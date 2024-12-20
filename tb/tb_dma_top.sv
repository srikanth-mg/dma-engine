// tb_dma_top.sv
// Self-checking testbench for the 4-channel DMA engine.
//   T1 single descriptor, single channel
//   T2 scatter-gather chain of 3 descriptors (bursts 1/2/8, partial last burst)
//   T3 all 4 channels running at once (arbitration + read/write overlap)
//   T4 error handling: misaligned descriptor pointer, zero-length descriptor
//   T5 interrupt mask and W1C clear
//   T6 START to a busy channel is ignored
// Memory map: descriptors 0x0000-0x0FFF, source 0x1000-0x7FFF, dest 0x8000-0xFFFF

`timescale 1ns/1ps

module tb_dma_top;
  import dma_pkg::*;

  logic clk = 0, rst_n = 0;
  always #5 clk = ~clk;                       // 100 MHz

  // APB
  logic        psel = 0, penable = 0, pwrite = 0;
  logic [7:0]  paddr = 0;
  logic [31:0] pwdata = 0, prdata;
  logic        pready, pslverr;

  // memory ports
  logic                rd_req_valid, rd_req_ready, rd_valid, rd_last;
  logic [ADDR_W-1:0]   rd_req_addr;
  logic [BEATS_W-1:0]  rd_req_len;
  logic [DATA_W-1:0]   rd_data;
  logic                wr_req_valid, wr_req_ready, wr_data_valid, wr_data_ready, wr_last;
  logic [ADDR_W-1:0]   wr_req_addr;
  logic [BEATS_W-1:0]  wr_req_len;
  logic [DATA_W-1:0]   wr_data;
  logic                irq;

  dma_top dut (
    .clk, .rst_n,
    .psel, .penable, .pwrite, .paddr, .pwdata, .prdata, .pready, .pslverr,
    .m_rd_req_valid (rd_req_valid), .m_rd_req_ready (rd_req_ready),
    .m_rd_req_addr  (rd_req_addr),  .m_rd_req_len   (rd_req_len),
    .m_rd_valid     (rd_valid),     .m_rd_data      (rd_data),  .m_rd_last (rd_last),
    .m_wr_req_valid (wr_req_valid), .m_wr_req_ready (wr_req_ready),
    .m_wr_req_addr  (wr_req_addr),  .m_wr_req_len   (wr_req_len),
    .m_wr_data_valid(wr_data_valid),.m_wr_data_ready(wr_data_ready),
    .m_wr_data      (wr_data),      .m_wr_last      (wr_last),
    .irq
  );

  mem_model #(.RD_LAT(4), .BP_PCT(30)) u_mem (
    .clk, .rst_n,
    .rd_req_valid, .rd_req_ready, .rd_req_addr, .rd_req_len,
    .rd_valid, .rd_data, .rd_last,
    .wr_req_valid, .wr_req_ready, .wr_req_addr, .wr_req_len,
    .wr_data_valid, .wr_data_ready, .wr_data, .wr_last
  );

  // ---------------- Scoreboard ----------------
  int pass_cnt = 0, fail_cnt = 0;

  task automatic check(input bit cond, input string msg);
    if (cond) begin pass_cnt++; $display("  PASS  %s", msg); end
    else      begin fail_cnt++; $display("  FAIL  %s", msg); end
  endtask

  // ---------------- APB tasks ----------------
  task automatic apb_write(input logic [7:0] a, input logic [31:0] d);
    @(posedge clk); psel <= 1; penable <= 0; pwrite <= 1; paddr <= a; pwdata <= d;
    @(posedge clk); penable <= 1;
    @(posedge clk); psel <= 0; penable <= 0; pwrite <= 0;
  endtask

  task automatic apb_read(input logic [7:0] a, output logic [31:0] d);
    @(posedge clk); psel <= 1; penable <= 0; pwrite <= 0; paddr <= a;
    @(posedge clk); penable <= 1;
    #1 d = prdata;                             // sample during access phase
    @(posedge clk); psel <= 0; penable <= 0;
  endtask

  // ---------------- Memory helpers ----------------
  function automatic void put_desc(input logic [31:0] at,
                                   input logic [31:0] src, dst,
                                   input logic [15:0] len,
                                   input burst_e burst,
                                   input bit last, irq_en,
                                   input logic [31:0] nxt);
    desc_t d;
    d          = '0;
    d.src_addr = src;  d.dst_addr = dst;  d.length = len;
    d.burst    = burst; d.last = last;    d.irq_en = irq_en;
    d.next_ptr = nxt;
    u_mem.mem[at[15:3]]     = d[63:0];
    u_mem.mem[at[15:3] + 1] = d[127:64];
  endfunction

  function automatic void fill_src(input logic [31:0] base, input int bytes, input int seed);
    for (int i = 0; i < bytes/8; i++)
      u_mem.mem[base[15:3] + i] = {32'(seed), 32'(i)} ^ 64'hA5A5_0000_5A5A_0000;
  endfunction

  function automatic void clear(input logic [31:0] base, input int bytes);
    for (int i = 0; i < bytes/8; i++) u_mem.mem[base[15:3] + i] = '0;
  endfunction

  function automatic bit same(input logic [31:0] src, dst, input int bytes);
    for (int i = 0; i < bytes/8; i++)
      if (u_mem.mem[src[15:3] + i] !== u_mem.mem[dst[15:3] + i]) begin
        $display("    mismatch word %0d: src=%h dst=%h", i,
                 u_mem.mem[src[15:3] + i], u_mem.mem[dst[15:3] + i]);
        return 0;
      end
    return 1;
  endfunction

  // ---------------- Channel helpers ----------------
  function automatic logic [7:0] ch_base(input int ch);
    return 8'(ch * 16);
  endfunction

  task automatic start_ch(input int ch, input logic [31:0] dptr);
    apb_write(ch_base(ch) + 8'h0, dptr);
    apb_write(ch_base(ch) + 8'h4, 32'h1);
  endtask

  task automatic wait_idle(input int ch, output bit ok);
    logic [31:0] s;
    ok = 0;
    for (int t = 0; t < 20000; t++) begin
      apb_read(ch_base(ch) + 8'h8, s);
      if (!s[0]) begin ok = 1; return; end
    end
  endtask

  task automatic clear_irqs();
    apb_write(8'h40, 32'hFF);
  endtask

  // ---------------- Tests ----------------
  logic [31:0] rd;
  bit ok;

  initial begin
    $display("=== DMA engine testbench ===");
    repeat (5) @(posedge clk);
    rst_n = 1;
    repeat (2) @(posedge clk);
    apb_write(8'h44, 32'hFF);                  // enable all interrupts

    // ---------- T1: single descriptor ----------
    $display("[T1] single descriptor, ch0, 64 B, burst 4");
    fill_src(32'h1000, 64, 1); clear(32'h8000, 64);
    put_desc(32'h0000, 32'h1000, 32'h8000, 16'd64, BURST_4, 1, 1, 32'h0);
    start_ch(0, 32'h0000);
    wait_idle(0, ok);
    check(ok,                          "T1 channel finished");
    check(same(32'h1000, 32'h8000, 64),"T1 data copied");
    apb_read(8'h40, rd);
    check(rd[0] == 1'b1,               "T1 DONE interrupt set");
    check(irq == 1'b1,                 "T1 irq line asserted");
    clear_irqs();

    // ---------- T2: scatter-gather chain ----------
    $display("[T2] scatter-gather, ch1, 3 descriptors, bursts 1/2/8");
    fill_src(32'h1100, 24, 2);  clear(32'h8100, 24);
    fill_src(32'h2000, 40, 3);  clear(32'h9000, 40);
    fill_src(32'h3000, 136, 4); clear(32'hA000, 136);       // 17 beats: 8+8+1
    put_desc(32'h0100, 32'h1100, 32'h8100, 16'd24,  BURST_1, 0, 0, 32'h0200);
    put_desc(32'h0200, 32'h2000, 32'h9000, 16'd40,  BURST_2, 0, 0, 32'h0300);
    put_desc(32'h0300, 32'h3000, 32'hA000, 16'd136, BURST_8, 1, 1, 32'h0);
    start_ch(1, 32'h0100);
    wait_idle(1, ok);
    check(ok,                                  "T2 chain finished");
    check(same(32'h1100, 32'h8100, 24),        "T2 descriptor 0 data");
    check(same(32'h2000, 32'h9000, 40),        "T2 descriptor 1 data");
    check(same(32'h3000, 32'hA000, 136),       "T2 descriptor 2 data (partial last burst)");
    apb_read(8'h40, rd);
    check(rd[7:0] == 8'h02,                    "T2 only ch1 DONE set (irq_en on last only)");
    clear_irqs();

    // ---------- T3: 4 channels concurrently ----------
    $display("[T3] 4 channels at once, mixed bursts");
    for (int c = 0; c < 4; c++) begin
      fill_src(32'h4000 + c*32'h400, 512, 10 + c);
      clear  (32'hB000 + c*32'h400, 512);
      put_desc(32'h0400 + c*32'h10, 32'h4000 + c*32'h400, 32'hB000 + c*32'h400,
               16'd512, burst_e'(c), 1, 1, 32'h0);
    end
    for (int c = 0; c < 4; c++) start_ch(c, 32'h0400 + c*32'h10);
    for (int c = 0; c < 4; c++) begin
      wait_idle(c, ok);
      check(ok, $sformatf("T3 ch%0d finished", c));
    end
    for (int c = 0; c < 4; c++)
      check(same(32'h4000 + c*32'h400, 32'hB000 + c*32'h400, 512),
            $sformatf("T3 ch%0d data (burst %0d)", c, 1 << c));
    apb_read(8'h40, rd);
    check(rd[3:0] == 4'hF,                     "T3 DONE set on all 4 channels");
    clear_irqs();

    // ---------- T4: error handling ----------
    $display("[T4] error handling");
    start_ch(2, 32'h0504);                     // not 16-byte aligned
    wait_idle(2, ok);
    apb_read(8'h40, rd);
    check(ok && rd[6] == 1'b1,                 "T4 misaligned descriptor ptr -> ERROR ch2");
    clear_irqs();
    put_desc(32'h0600, 32'h1000, 32'h8000, 16'd0, BURST_4, 1, 1, 32'h0);
    start_ch(3, 32'h0600);
    wait_idle(3, ok);
    apb_read(8'h40, rd);
    check(ok && rd[7] == 1'b1 && rd[3] == 1'b0,"T4 zero-length descriptor -> ERROR ch3, no DONE");
    clear_irqs();

    // ---------- T5: interrupt mask and W1C ----------
    $display("[T5] interrupt mask and W1C");
    apb_write(8'h44, 32'h00);                  // mask everything
    fill_src(32'h1000, 32, 20); clear(32'h8000, 32);
    put_desc(32'h0700, 32'h1000, 32'h8000, 16'd32, BURST_2, 1, 1, 32'h0);
    start_ch(0, 32'h0700);
    wait_idle(0, ok);
    apb_read(8'h40, rd);
    check(rd[0] == 1'b1 && irq == 1'b0,        "T5 status set but irq masked");
    apb_write(8'h44, 32'h01);
    @(posedge clk); #1;
    check(irq == 1'b1,                         "T5 irq asserts after unmask");
    apb_write(8'h40, 32'h01);                  // W1C
    apb_read(8'h40, rd);
    check(rd[0] == 1'b0 && irq == 1'b0,        "T5 W1C clears status and irq");
    apb_write(8'h44, 32'hFF);

    // ---------- T6: START while busy is ignored ----------
    $display("[T6] START to busy channel ignored");
    fill_src(32'h5000, 1024, 30); clear(32'hC000, 1024);
    put_desc(32'h0800, 32'h5000, 32'hC000, 16'd1024, BURST_1, 1, 1, 32'h0);
    put_desc(32'h0810, 32'h1000, 32'h8000, 16'd8,    BURST_1, 1, 1, 32'h0);
    start_ch(1, 32'h0800);
    apb_write(8'h10, 32'h0810);                // change DESC_PTR mid-transfer
    apb_write(8'h14, 32'h1);                   // second START while busy
    wait_idle(1, ok);
    check(ok && same(32'h5000, 32'hC000, 1024),"T6 original transfer completed intact");
    clear_irqs();

    // ---------- summary ----------
    check(u_mem.errors == 0, "memory-side protocol checks clean");
    $display("=== RESULT: %0d passed, %0d failed ===", pass_cnt, fail_cnt);
    if (fail_cnt == 0) $display("ALL TESTS PASSED");
    $finish;
  end

  // ---------------- Coverage counters ----------------
  // overlap: a read beat and a write beat move in the same cycle
  int rd_beats = 0, wr_beats = 0, overlap_cycles = 0;
  always @(posedge clk) if (rst_n) begin
    if (rd_valid) rd_beats++;
    if (wr_data_valid && wr_data_ready) wr_beats++;
    if (rd_valid && wr_data_valid && wr_data_ready) overlap_cycles++;
  end

  final $display("Coverage: %0d read beats, %0d write beats, %0d cycles with read+write overlap",
                 rd_beats, wr_beats, overlap_cycles);

  // watchdog
  initial begin
    #5_000_000;
    $display("TIMEOUT");
    $finish;
  end

endmodule
