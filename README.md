# Multi-Channel DMA Engine

4-channel, descriptor-based DMA engine in SystemVerilog with scatter-gather
descriptor chains, round-robin arbitration, 8-deep per-channel FIFOs,
32-bit addressing, 64-bit data, configurable burst lengths (1/2/4/8 beats),
and maskable interrupts. Configured over APB.

Read and write memory ports are independent, so reads and writes overlap.

## Layout

```
rtl/   dma_pkg, dma_fifo, dma_rr_arbiter, dma_apb_regs, dma_channel, dma_top
tb/    mem_model (latency, random back-pressure, protocol checks), tb_dma_top
docs/  dma_spec.md  (microarchitecture, register map, design decisions)
```

## Run (Verilator 5.x)

```
make lint    # -Wall lint of the RTL
make sim     # self-checking testbench
make seeds   # 10 random seeds
```

## Status

25/25 checks pass across 10 seeds, lint clean. See `docs/dma_spec.md`.
