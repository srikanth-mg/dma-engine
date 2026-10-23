# Multi-Channel DMA Engine - Microarchitecture Spec

## 1. What it does

Moves data from a source buffer to a destination buffer in memory without the CPU.
Software writes a chain of descriptors into memory, points a channel at the first one,
writes START, and gets an interrupt when the chain completes. Four channels run
independently and share the memory through round-robin arbitration.

## 2. Block diagram

```
            APB (config)
                 │
         ┌───────▼────────┐  start[3:0], desc_ptr[3:0]
         │  dma_apb_regs  │──────────────────────────────┐
         │ regs + IRQ     │◄─ busy / done_evt / err_evt ─┤
         └───────┬────────┘                              │
                 │ irq                                   │
                                     ┌───────────────────▼──────────────┐
                                     │ dma_channel x4                   │
                                     │  main/read FSM ─► FIFO 8x64 ─► write FSM
                                     └─────┬───────────────────────┬────┘
                                      rd_req[3:0]             wr_req[3:0]
                                   ┌───────▼───────┐       ┌───────▼───────┐
                                   │ RR arbiter +  │       │ RR arbiter +  │
                                   │ read port FSM │       │ write port FSM│
                                   └───────┬───────┘       └───────┬───────┘
                                    memory read port        memory write port
```

## 3. Key parameters (`dma_pkg.sv`)

| Parameter | Value | Meaning |
|---|---|---|
| NUM_CH | 4 | channels |
| ADDR_W | 32 | byte address |
| DATA_W | 64 | 8 bytes per beat |
| FIFO_DEPTH | 8 | beats buffered per channel |
| LEN_W | 16 | descriptor length field (bytes) |
| Burst | 1 / 2 / 4 / 8 beats | per descriptor, 2-bit code |

## 4. Descriptor format (128 bits, 16-byte aligned, fetched as one 2-beat read)

| Word | Bits | Field |
|---|---|---|
| 0 | [31:0] | src_addr (8-byte aligned) |
| 0 | [63:32] | dst_addr (8-byte aligned) |
| 1 | [15:0] | length in bytes (non-zero, multiple of 8) |
| 1 | [17:16] | burst code: 0=1, 1=2, 2=4, 3=8 beats |
| 1 | [18] | last - end of chain |
| 1 | [19] | irq_en - set DONE when this descriptor completes |
| 1 | [31:20] | reserved |
| 1 | [63:32] | next_ptr - next descriptor (ignored if last) |

Scatter-gather = descriptors linked through `next_ptr`. Each descriptor is one
contiguous piece; the chain stitches non-contiguous pieces together with no CPU work
between pieces.

## 5. Register map (APB, zero wait states)

| Offset | Name | Access | Description |
|---|---|---|---|
| 0x00 + 0x10·ch | CH_DESC_PTR | RW | first descriptor address |
| 0x04 + 0x10·ch | CH_CTRL | WO | bit0 START (ignored if channel busy) |
| 0x08 + 0x10·ch | CH_STATUS | RO | bit0 BUSY |
| 0x40 | IRQ_STATUS | W1C | [3:0] DONE per channel, [7:4] ERROR per channel |
| 0x44 | IRQ_MASK | RW | same layout, 1 = enabled |

`irq = |(IRQ_STATUS & IRQ_MASK)`. If hardware sets and software clears the same bit
in the same cycle, set wins, so no event is lost.

## 6. Memory interface

Separate read and write ports, valid/ready handshakes, one burst in flight per port.

| Read port | Write port |
|---|---|
| req: valid/ready, addr, len (beats) | req: valid/ready, addr, len |
| data: valid, data, last (no ready - DMA always accepts) | data: valid/ready, data, last |

Writes are posted: a write burst is complete when its last beat is accepted. There is
no write-response channel.

## 7. Channel operation

**Main/read FSM:** `IDLE -> FETCH_REQ -> FETCH_DATA -> CHECK -> RD_ISSUE ⇄ RD_DATA -> WAIT_WR -> (FETCH_REQ | IDLE)`, with `ERR -> IDLE` on a bad descriptor.

**Write FSM:** `W_IDLE -> W_REQ -> W_DATA -> W_IDLE`.

Flow-control rules, which are the heart of the design:

1. A read burst is issued only if the FIFO has free space for the whole burst. So read
   data never has to be stalled, which is why the read data path has no ready signal.
2. A write burst is issued only if the FIFO already holds the whole burst. So once a
   write starts it never runs dry mid-burst.
3. Each burst is `min(configured burst, beats remaining)`, so a 17-beat transfer at
   burst 8 becomes 8 + 8 + 1.

Because the read and write ports are independent, the read side of a channel can fetch
burst N+1 while its write side is still writing burst N.

## 8. Port arbitration (`dma_top.sv`)

Each port runs `P_IDLE -> P_REQ -> P_DATA`. In P_IDLE the round-robin arbiter picks a
requester and the owner is **latched**. The owner keeps the port for the whole burst.
Latching matters: the arbiter's grant is combinational, so if a new request arrived
while waiting for `ready`, the presented address could change mid-handshake, which
breaks the valid/ready rule. The memory model checks for exactly this.

Round-robin: after channel i is served, priority starts at i+1. Every requester is
served within 4 grants, so no starvation.

## 9. Error handling

Errors set the channel's ERROR bit and return it to IDLE (no data is moved):
descriptor pointer not 16-byte aligned (at START or in `next_ptr`), length zero or not
a multiple of 8, src or dst not 8-byte aligned.

## 10. Design decisions and trade-offs

| Decision | Why | Cost / alternative |
|---|---|---|
| Split read/write ports | lets reads and writes overlap; FIFO alone can't give overlap if the bus is shared | two arbiters, more wiring |
| Whole-burst space check | read data never back-pressured, simpler memory side | with depth 8 and burst 8 a channel can't overlap with itself; depth 16 fixes it at 2× FIFO area |
| FIFO first-word-fall-through | zero latency from push to visible data | read mux sits in the write-data path; a registered output adds a cycle but improves timing |
| No reset on FIFO storage | saves area/power, array could map to SRAM | none: empty gates every read, so stale data is never used |
| Latched port owner | keeps request stable during valid/ready | 1 idle cycle per burst for arbitration |
| One burst in flight per port | simple routing of returning data to its owner | lower bandwidth vs. multiple outstanding with transaction IDs |
| 8-byte alignment required | no byte shifting or byte strobes in the datapath | real DMAs handle unaligned with a barrel shifter + strobes |
| Next descriptor fetched only after current one fully written | descriptor registers are shared | prefetching the next descriptor would hide fetch latency |

## 11. Known limitations / what I'd improve next

1. Multiple outstanding reads with IDs, to hide memory latency.
2. Deeper FIFO (16) so burst-8 transfers overlap within one channel.
3. Unaligned addresses and byte-granular lengths (barrel shifter + write strobes).
4. Descriptor prefetch and write-back of status into the descriptor.
5. Weighted or priority arbitration for latency-critical channels.
6. Write-response channel so completion means data is truly in memory.
7. Register the arbitration decision path and pipeline the FIFO output for higher Fmax.

## 12. Verification

Self-checking SystemVerilog testbench (`tb/tb_dma_top.sv`) with a behavioral memory
model that adds read latency, random back-pressure on every ready, random gaps between
read beats, and protocol checks (request stability, write `last` correctness).

| Test | What it proves |
|---|---|
| T1 | single descriptor, data + DONE + irq |
| T2 | 3-descriptor scatter-gather, bursts 1/2/8, partial last burst, irq_en only on last |
| T3 | all 4 channels at once, all 4 burst sizes, arbitration fairness |
| T4 | misaligned pointer and zero-length descriptor -> ERROR, no DONE |
| T5 | IRQ mask and W1C |
| T6 | START to a busy channel is ignored |

Result: 25/25 checks pass across 10 random seeds; Verilator `-Wall` lint clean.
Read/write overlap observed in simulation. A mutation (source address never advancing)
is caught by 8 checks.
