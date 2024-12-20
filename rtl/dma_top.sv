// dma_top.sv
// 4-channel descriptor-based DMA engine.
//
//   APB slave (config) ---> dma_apb_regs ---> start / desc_ptr per channel
//   4 x dma_channel --+--> read  arbiter (RR) ---> memory read port
//                     +--> write arbiter (RR) ---> memory write port
//
// Read and write ports are independent, so one channel can read while
// another (or the same one) writes. Each port serves one burst at a time:
//   IDLE : arbiter picks a requester, owner is latched
//   REQ  : owner's address/length presented until memory accepts
//   DATA : beats routed to/from the owner until the last beat

module dma_top
  import dma_pkg::*;
(
  input  logic                clk,
  input  logic                rst_n,

  // APB config slave
  input  logic                psel,
  input  logic                penable,
  input  logic                pwrite,
  input  logic [7:0]          paddr,
  input  logic [31:0]         pwdata,
  output logic [31:0]         prdata,
  output logic                pready,
  output logic                pslverr,

  // memory read port (master)
  output logic                m_rd_req_valid,
  input  logic                m_rd_req_ready,
  output logic [ADDR_W-1:0]   m_rd_req_addr,
  output logic [BEATS_W-1:0]  m_rd_req_len,
  input  logic                m_rd_valid,      // DMA always accepts read data
  input  logic [DATA_W-1:0]   m_rd_data,
  input  logic                m_rd_last,

  // memory write port (master)
  output logic                m_wr_req_valid,
  input  logic                m_wr_req_ready,
  output logic [ADDR_W-1:0]   m_wr_req_addr,
  output logic [BEATS_W-1:0]  m_wr_req_len,
  output logic                m_wr_data_valid,
  input  logic                m_wr_data_ready,
  output logic [DATA_W-1:0]   m_wr_data,
  output logic                m_wr_last,

  output logic                irq
);

  // ---------------- Per-channel wiring ----------------
  logic [NUM_CH-1:0]              start, busy, done_evt, err_evt;
  logic [NUM_CH-1:0][ADDR_W-1:0]  desc_ptr;

  logic [NUM_CH-1:0]              c_rd_req, c_rd_ack, c_rd_valid;
  logic [NUM_CH-1:0][ADDR_W-1:0]  c_rd_addr;
  logic [NUM_CH-1:0][BEATS_W-1:0] c_rd_len;

  logic [NUM_CH-1:0]              c_wr_req, c_wr_ack, c_wr_dvalid, c_wr_dlast, c_wr_beat;
  logic [NUM_CH-1:0][ADDR_W-1:0]  c_wr_addr;
  logic [NUM_CH-1:0][BEATS_W-1:0] c_wr_len;
  logic [NUM_CH-1:0][DATA_W-1:0]  c_wr_data;

  dma_apb_regs u_regs (
    .clk, .rst_n,
    .psel, .penable, .pwrite, .paddr, .pwdata, .prdata, .pready, .pslverr,
    .desc_ptr, .start, .busy, .done_evt, .err_evt, .irq
  );

  for (genvar c = 0; c < NUM_CH; c++) begin : g_ch
    dma_channel u_ch (
      .clk, .rst_n,
      .start        (start[c]),
      .desc_ptr_in  (desc_ptr[c]),
      .busy         (busy[c]),
      .done_evt     (done_evt[c]),
      .err_evt      (err_evt[c]),
      .rd_req       (c_rd_req[c]),
      .rd_addr      (c_rd_addr[c]),
      .rd_len       (c_rd_len[c]),
      .rd_ack       (c_rd_ack[c]),
      .rd_valid     (c_rd_valid[c]),
      .rd_data      (m_rd_data),       // broadcast; rd_valid selects the owner
      .rd_last      (m_rd_last),
      .wr_req       (c_wr_req[c]),
      .wr_addr      (c_wr_addr[c]),
      .wr_len       (c_wr_len[c]),
      .wr_ack       (c_wr_ack[c]),
      .wr_data_valid(c_wr_dvalid[c]),
      .wr_data      (c_wr_data[c]),
      .wr_data_last (c_wr_dlast[c]),
      .wr_beat      (c_wr_beat[c])
    );
  end

  typedef enum logic [1:0] { P_IDLE, P_REQ, P_DATA } port_e;

  // ================= Read port =================
  port_e            rstate;
  logic [CH_W-1:0]  r_own;
  logic [NUM_CH-1:0] r_gnt;
  logic [CH_W-1:0]  r_gnt_idx;
  logic             r_gnt_vld;

  dma_rr_arbiter #(.N(NUM_CH)) u_rd_arb (
    .clk, .rst_n,
    .req       (c_rd_req),
    .accept    (rstate == P_IDLE),
    .grant     (r_gnt),
    .grant_idx (r_gnt_idx),
    .grant_vld (r_gnt_vld)
  );

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      rstate <= P_IDLE;
      r_own  <= '0;
    end else begin
      case (rstate)
        P_IDLE: if (r_gnt_vld) begin
          r_own  <= r_gnt_idx;
          rstate <= P_REQ;
        end
        P_REQ:  if (m_rd_req_ready)          rstate <= P_DATA;
        P_DATA: if (m_rd_valid && m_rd_last) rstate <= P_IDLE;
        default:                             rstate <= P_IDLE;
      endcase
    end
  end

  assign m_rd_req_valid = (rstate == P_REQ);
  assign m_rd_req_addr  = c_rd_addr[r_own];
  assign m_rd_req_len   = c_rd_len[r_own];

  always_comb begin
    c_rd_ack   = '0;
    c_rd_valid = '0;
    c_rd_ack[r_own]   = (rstate == P_REQ)  && m_rd_req_ready;
    c_rd_valid[r_own] = (rstate == P_DATA) && m_rd_valid;
  end

  // ================= Write port =================
  port_e            wstate;
  logic [CH_W-1:0]  w_own;
  logic [NUM_CH-1:0] w_gnt;
  logic [CH_W-1:0]  w_gnt_idx;
  logic             w_gnt_vld;

  dma_rr_arbiter #(.N(NUM_CH)) u_wr_arb (
    .clk, .rst_n,
    .req       (c_wr_req),
    .accept    (wstate == P_IDLE),
    .grant     (w_gnt),
    .grant_idx (w_gnt_idx),
    .grant_vld (w_gnt_vld)
  );

  logic w_beat;
  assign w_beat = (wstate == P_DATA) && m_wr_data_valid && m_wr_data_ready;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      wstate <= P_IDLE;
      w_own  <= '0;
    end else begin
      case (wstate)
        P_IDLE: if (w_gnt_vld) begin
          w_own  <= w_gnt_idx;
          wstate <= P_REQ;
        end
        P_REQ:  if (m_wr_req_ready)      wstate <= P_DATA;
        P_DATA: if (w_beat && m_wr_last) wstate <= P_IDLE;
        default:                         wstate <= P_IDLE;
      endcase
    end
  end

  assign m_wr_req_valid  = (wstate == P_REQ);
  assign m_wr_req_addr   = c_wr_addr[w_own];
  assign m_wr_req_len    = c_wr_len[w_own];
  assign m_wr_data_valid = (wstate == P_DATA) && c_wr_dvalid[w_own];
  assign m_wr_data       = c_wr_data[w_own];
  assign m_wr_last       = c_wr_dlast[w_own];

  always_comb begin
    c_wr_ack  = '0;
    c_wr_beat = '0;
    c_wr_ack[w_own]  = (wstate == P_REQ) && m_wr_req_ready;
    c_wr_beat[w_own] = w_beat;
  end

  // one-hot grants are informational; owner index is what is used
  logic unused;
  assign unused = ^{r_gnt, w_gnt};

endmodule
