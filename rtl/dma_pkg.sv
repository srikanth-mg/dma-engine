// dma_pkg.sv
// Shared parameters, descriptor format and helpers for the 4-channel DMA engine.

package dma_pkg;

  // ---------------- Global parameters ----------------
  localparam int NUM_CH     = 4;              // independent channels
  localparam int CH_W       = $clog2(NUM_CH); // channel ID width (2)
  localparam int ADDR_W     = 32;             // byte address
  localparam int DATA_W     = 64;             // memory data bus
  localparam int FIFO_DEPTH = 8;              // per-channel data FIFO (beats)
  localparam int LEN_W      = 16;             // transfer length in bytes (max 64 KB - 8)
  localparam int BEATS_W    = 4;              // holds a beat count of 1..8

  // ---------------- Burst length encoding ----------------
  // 2-bit code in the descriptor -> 1/2/4/8 beats per memory burst
  typedef enum logic [1:0] {
    BURST_1 = 2'd0,
    BURST_2 = 2'd1,
    BURST_4 = 2'd2,
    BURST_8 = 2'd3
  } burst_e;

  // ---------------- Descriptor (128 bits = two 64-bit beats) ----------------
  // Lives in memory, 16-byte aligned, fetched with one 2-beat read burst.
  //   beat 0 (bits  63:0)  : {dst_addr, src_addr}
  //   beat 1 (bits 127:64) : {next_ptr, ctrl[15:0], length}
  // Chaining descriptors through next_ptr is what gives scatter-gather.
  typedef struct packed {
    logic [ADDR_W-1:0] next_ptr;   // address of next descriptor (ignored if last)
    logic [11:0]       rsvd;       // reserved, write 0
    logic              irq_en;     // raise interrupt when this descriptor completes
    logic              last;       // 1 = end of chain
    burst_e            burst;      // burst size for this descriptor's data moves
    logic [LEN_W-1:0]  length;     // bytes to move, multiple of 8
    logic [ADDR_W-1:0] dst_addr;   // destination, 8-byte aligned
    logic [ADDR_W-1:0] src_addr;   // source, 8-byte aligned
  } desc_t;

  // Convert burst code to number of beats: 1 << code
  function automatic logic [BEATS_W-1:0] burst_beats(input burst_e b);
    return BEATS_W'(1) << b;
  endfunction

endpackage
