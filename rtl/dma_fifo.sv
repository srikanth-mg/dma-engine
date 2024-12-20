// dma_fifo.sv
// Parameterized synchronous FIFO. One per DMA channel.
// - Simultaneous push and pop in the same cycle are supported.
// - Pointers carry one extra bit so full and empty are distinguishable
//   without a separate counter.
// - 'used' tells the channel how much space is left, so it only issues
//   a read burst when the whole burst is guaranteed to fit.

module dma_fifo #(
  parameter int WIDTH = 64,
  parameter int DEPTH = 8,                 // must be a power of 2
  localparam int AW   = $clog2(DEPTH)      // address bits into storage
) (
  input  logic             clk,
  input  logic             rst_n,

  // write side
  input  logic             push,
  input  logic [WIDTH-1:0] wdata,
  output logic             full,

  // read side
  input  logic             pop,
  output logic [WIDTH-1:0] rdata,
  output logic             empty,

  // occupancy, 0..DEPTH
  output logic [AW:0]      used
);

  logic [WIDTH-1:0] mem [DEPTH];
  logic [AW:0]      wr_ptr, rd_ptr;        // MSB is the wrap bit

  // A push or pop only takes effect when it is legal
  logic do_push, do_pop;
  assign do_push = push && !full;
  assign do_pop  = pop  && !empty;

  // Storage write: no reset on the data array (saves area, data is
  // never read before it is written because empty gates the read side)
  always_ff @(posedge clk) begin
    if (do_push) mem[wr_ptr[AW-1:0]] <= wdata;
  end

  // Pointer update
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      wr_ptr <= '0;
      rd_ptr <= '0;
    end else begin
      if (do_push) wr_ptr <= wr_ptr + 1'b1;
      if (do_pop)  rd_ptr <= rd_ptr + 1'b1;
    end
  end

  // Status
  //   empty: pointers identical
  //   full : same index, opposite wrap bit
  assign empty = (wr_ptr == rd_ptr);
  assign full  = (wr_ptr[AW] != rd_ptr[AW]) &&
                 (wr_ptr[AW-1:0] == rd_ptr[AW-1:0]);
  assign used  = wr_ptr - rd_ptr;          // modular subtraction handles wrap

  // First-word-fall-through: head entry is always visible on rdata
  assign rdata = mem[rd_ptr[AW-1:0]];

endmodule
