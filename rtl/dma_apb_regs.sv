// dma_apb_regs.sv
// APB3 slave register block. Zero wait states (pready = 1), no slave errors.
//
// Register map (byte offsets):
//   0x00 + 0x10*ch  CH_DESC_PTR  RW  address of the first descriptor (16-byte aligned)
//   0x04 + 0x10*ch  CH_CTRL      WO  bit0 = START (write 1 to launch, reads 0)
//   0x08 + 0x10*ch  CH_STATUS    RO  bit0 = BUSY
//   0x40            IRQ_STATUS   W1C bits[3:0] DONE per channel, bits[7:4] ERROR per channel
//   0x44            IRQ_MASK     RW  same layout as IRQ_STATUS, 1 = enabled
//
// irq = OR of (IRQ_STATUS & IRQ_MASK), one level-sensitive line.

module dma_apb_regs
  import dma_pkg::*;
(
  input  logic                     clk,
  input  logic                     rst_n,

  // APB slave
  input  logic                     psel,
  input  logic                     penable,
  input  logic                     pwrite,
  input  logic [7:0]               paddr,
  input  logic [31:0]              pwdata,
  output logic [31:0]              prdata,
  output logic                     pready,
  output logic                     pslverr,

  // to / from channels
  output logic [NUM_CH-1:0][ADDR_W-1:0] desc_ptr,
  output logic [NUM_CH-1:0]        start,      // 1-cycle pulse
  input  logic [NUM_CH-1:0]        busy,
  input  logic [NUM_CH-1:0]        done_evt,   // 1-cycle pulses from channels
  input  logic [NUM_CH-1:0]        err_evt,

  output logic                     irq
);

  logic [2*NUM_CH-1:0] irq_status, irq_mask;

  // APB access phase: psel & penable. Zero wait states, so it lasts one cycle.
  logic wr_en, rd_en;
  assign wr_en = psel && penable &&  pwrite;
  assign rd_en = psel && penable && !pwrite;

  assign pready  = 1'b1;
  assign pslverr = 1'b0;

  // Decode: channel registers live below 0x40
  logic          ch_space;
  logic [1:0]    ch_sel;
  logic [1:0]    ch_reg;               // 0 = DESC_PTR, 1 = CTRL, 2 = STATUS
  assign ch_space = (paddr[7:6] == 2'b00);
  assign ch_sel   = paddr[5:4];
  assign ch_reg   = paddr[3:2];

  // ---------------- Writes ----------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      desc_ptr <= '0;
      irq_mask <= '0;
    end else if (wr_en) begin
      if (ch_space && ch_reg == 2'd0) desc_ptr[ch_sel] <= pwdata;
      if (paddr == 8'h44)             irq_mask         <= pwdata[2*NUM_CH-1:0];
    end
  end

  // START is a pulse. A start to a busy channel is ignored.
  always_comb begin
    start = '0;
    if (wr_en && ch_space && ch_reg == 2'd1 && pwdata[0] && !busy[ch_sel])
      start[ch_sel] = 1'b1;
  end

  // IRQ status: hardware sets, software clears by writing 1 (W1C).
  // If set and clear hit the same bit in the same cycle, set wins,
  // so an event is never lost.
  logic [2*NUM_CH-1:0] w1c;
  assign w1c = (wr_en && paddr == 8'h40) ? pwdata[2*NUM_CH-1:0] : '0;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) irq_status <= '0;
    else        irq_status <= (irq_status & ~w1c) | {err_evt, done_evt};
  end

  assign irq = |(irq_status & irq_mask);

  // ---------------- Reads ----------------
  always_comb begin
    prdata = '0;
    if (rd_en) begin
      if (ch_space) begin
        case (ch_reg)
          2'd0:    prdata = desc_ptr[ch_sel];
          2'd2:    prdata = {31'b0, busy[ch_sel]};
          default: prdata = '0;
        endcase
      end else if (paddr == 8'h40) prdata = 32'(irq_status);
      else if   (paddr == 8'h44)   prdata = 32'(irq_mask);
    end
  end

  // paddr[1:0] are byte offsets within a word, unused for 32-bit registers
  logic unused;
  assign unused = ^paddr[1:0];

endmodule
