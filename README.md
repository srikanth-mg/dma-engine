# Multi-Channel DMA Engine

A 4-channel, descriptor-based DMA engine written in SystemVerilog. It supports scatter-gather descriptor chains, round-robin arbitration, per-channel FIFOs, configurable burst lengths, and maskable interrupts, all configured over APB.

## Features

- 4 independent channels sharing memory through round-robin arbitration
- Scatter-gather via linked descriptors in memory
- Separate read and write memory ports, so reads and writes overlap
- 8-deep × 64-bit FIFO per channel
- 32-bit addressing, 64-bit data path
- Configurable bursts of 1, 2, 4, or 8 beats per descriptor
- Per-channel DONE and ERROR interrupts with mask and write-1-to-clear status
- Descriptor validation (alignment, zero length)

## Architecture

```
              APB (config)
                   │
           ┌───────▼────────┐
           │  dma_apb_regs  │──── irq
           └───────┬────────┘
                   │ start / desc_ptr / status
     ┌─────────────▼──────────────────────────┐
     │  dma_channel × 4                       │
     │  read FSM ──► FIFO (8×64) ──► write FSM│
     └──────┬──────────────────────────┬──────┘
            │ rd_req[3:0]              │ wr_req[3:0]
     ┌──────▼───────┐           ┌──────▼───────┐
     │ RR arbiter   │           │ RR arbiter   │
     │ + read port  │           │ + write port │
     └──────┬───────┘           └──────┬───────┘
      memory read port           memory write port
```

## Repository Structure

```
dma-engine/
├── rtl/
│   ├── dma_pkg.sv          Parameters, descriptor struct, burst encoding
│   ├── dma_fifo.sv         Parameterized synchronous FIFO
│   ├── dma_rr_arbiter.sv   N-way round-robin arbiter
│   ├── dma_apb_regs.sv     APB register block and interrupt logic
│   ├── dma_channel.sv      Per-channel descriptor walker and data mover
│   └── dma_top.sv          Top level: channels, arbiters, memory ports
├── tb/
│   ├── mem_model.sv        Memory model with latency, back-pressure, protocol checks
│   └── tb_dma_top.sv       Self-checking testbench
├── docs/
│   └── dma_spec.md         Detailed microarchitecture specification
└── Makefile
```

## Getting Started

**Requirements:** Verilator 5.x

```bash
make lint    # Verilator -Wall lint of the RTL
make sim     # Build and run the testbench
make seeds   # Run with 10 random seeds
make clean
```

## Descriptor Format

128 bits, 16-byte aligned, stored as two 64-bit words.

| Word | Bits    | Field      | Description                              |
|------|---------|------------|------------------------------------------|
| 0    | [31:0]  | `src_addr` | Source address (8-byte aligned)          |
| 0    | [63:32] | `dst_addr` | Destination address (8-byte aligned)     |
| 1    | [15:0]  | `length`   | Bytes to transfer (non-zero, multiple of 8) |
| 1    | [17:16] | `burst`    | 0 = 1, 1 = 2, 2 = 4, 3 = 8 beats         |
| 1    | [18]    | `last`     | End of chain                             |
| 1    | [19]    | `irq_en`   | Raise DONE when this descriptor completes |
| 1    | [63:32] | `next_ptr` | Address of the next descriptor           |

## Register Map

| Offset           | Name          | Access | Description                                   |
|------------------|---------------|--------|-----------------------------------------------|
| `0x00 + 0x10*ch` | `CH_DESC_PTR` | RW     | Address of the first descriptor               |
| `0x04 + 0x10*ch` | `CH_CTRL`     | WO     | Bit 0: START                                  |
| `0x08 + 0x10*ch` | `CH_STATUS`   | RO     | Bit 0: BUSY                                   |
| `0x40`           | `IRQ_STATUS`  | W1C    | [3:0] DONE, [7:4] ERROR (one bit per channel) |
| `0x44`           | `IRQ_MASK`    | RW     | Interrupt enable, same layout as IRQ_STATUS   |

## Usage

1. Write a descriptor chain into memory.
2. Write the first descriptor's address to `CH_DESC_PTR`.
3. Write `1` to `CH_CTRL` to start the channel.
4. Wait for the interrupt, or poll `CH_STATUS`.
5. Clear the interrupt by writing `1` to the corresponding bit in `IRQ_STATUS`.

## Verification

Self-checking testbench against a behavioral memory model with read latency, random back-pressure, and protocol checking.

| Test | Coverage                                                        |
|------|-----------------------------------------------------------------|
| T1   | Single descriptor transfer with interrupt                       |
| T2   | 3-descriptor scatter-gather chain, mixed bursts, partial burst  |
| T3   | All 4 channels concurrently with all burst sizes                |
| T4   | Error handling: misaligned pointer, zero-length descriptor      |
| T5   | Interrupt masking and write-1-to-clear                          |
| T6   | START ignored on a busy channel                                 |

**Status:** 25/25 checks passing across 10 random seeds. Lint clean.

## Design Notes

- A read burst is issued only when the FIFO has room for the whole burst, so read data never needs back-pressure.
- A write burst is issued only when the FIFO holds the whole burst, so writes never stall mid-burst.
- The port owner is latched for the full burst to keep requests stable during the valid/ready handshake.

See [`docs/dma_spec.md`](docs/dma_spec.md) for the full microarchitecture and design trade-offs.

## Future Work

- Multiple outstanding transactions with IDs
- Unaligned transfers with byte strobes
- Descriptor prefetch
- Weighted or priority arbitration
- Write-response handling

## 🛠️ Compilation and Simulation Quickstart

The project provides an automated `Makefile` configured for open-source verification using **Verilator 5.x**:

```bash
# Execute compilation and a strict linting sweep of all RTL structures
make lint

# Run the complete self-checking testbench suite
make sim

# Execute regression sweeps utilizing 10 randomized algorithmic seeds
make seeds
```

## Project Timeline & Maintenance
* **Core Development:** Completed in Fall 2024 as a comprehensive hardware design project.
* **Portfolio Publication:** Uploaded to GitHub for public portfolio showcase.
* **Active Maintenance:** The documentation, build scripts, and README are actively maintained and updated to ensure clean linting and easy verification for open-source users.
