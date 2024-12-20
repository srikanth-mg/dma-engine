// dma_channel.sv
// One DMA channel. Walks a descriptor chain and moves data src -> dst.
//
// Two FSMs share one descriptor and one FIFO:
//   main/read FSM : fetch descriptor -> issue read bursts -> push into FIFO
//                   -> wait for writes to drain -> follow next_ptr or finish
//   write FSM     : whenever a full burst is sitting in the FIFO, issue a
//                   write burst and pop the FIFO beat by beat
// Because the two run independently on separate memory ports, reading
// burst N+1 overlaps with writing burst N.
//
// Flow-control rules (no back-pressure ever needed on read data):
//   - a read burst is issued only if the FIFO has room for the whole burst
//   - a write burst is issued only if the FIFO already holds the whole burst

module dma_channel
  import dma_pkg::*;
(
  input  logic                clk,
  input  logic                rst_n,

  // control / status
  input  logic                start,
  input  logic [ADDR_W-1:0]   desc_ptr_in,
  output logic                busy,
  output logic                done_evt,    // descriptor with irq_en finished
  output logic                err_evt,     // bad descriptor, channel stopped

  // read port (to top-level read arbiter)
  output logic                rd_req,
  output logic [ADDR_W-1:0]   rd_addr,
  output logic [BEATS_W-1:0]  rd_len,      // beats, 1..8
  input  logic                rd_ack,      // request accepted by memory
  input  logic                rd_valid,    // read data beat for this channel
  input  logic [DATA_W-1:0]   rd_data,
  input  logic                rd_last,

  // write port (to top-level write arbiter)
  output logic                wr_req,
  output logic [ADDR_W-1:0]   wr_addr,
  output logic [BEATS_W-1:0]  wr_len,
  input  logic                wr_ack,
  output logic                wr_data_valid,
  output logic [DATA_W-1:0]   wr_data,
  output logic                wr_data_last,
  input  logic                wr_beat      // memory accepted a write beat from us
);

  localparam int REM_W = LEN_W - 3;        // length in beats (bytes / 8)

  // ---------------- State ----------------
  typedef enum logic [2:0] {
    S_IDLE, S_FETCH_REQ, S_FETCH_DATA, S_CHECK,
    S_RD_ISSUE, S_RD_DATA, S_WAIT_WR, S_ERR
  } main_e;

  typedef enum logic [1:0] { W_IDLE, W_REQ, W_DATA } wr_e;

  main_e              state;
  wr_e                wstate;

  logic [ADDR_W-1:0]  desc_addr;           // where the current descriptor lives
  logic [DATA_W-1:0]  desc_lo;             // first descriptor beat
  desc_t              desc;
  logic               desc_active;         // descriptor loaded, data moving

  logic [ADDR_W-1:0]  rd_ptr, wr_ptr;      // running src / dst addresses
  logic [REM_W-1:0]   rd_rem, wr_rem;      // beats still to read / write
  logic [BEATS_W-1:0] wcnt;                // beats sent in current write burst

  // ---------------- FIFO ----------------
  localparam int FAW = $clog2(FIFO_DEPTH);
  logic             f_push, f_pop, f_full, f_empty;
  logic [FAW:0]     f_used;
  logic [DATA_W-1:0] f_rdata;

  dma_fifo #(.WIDTH(DATA_W), .DEPTH(FIFO_DEPTH)) u_fifo (
    .clk, .rst_n,
    .push (f_push), .wdata (rd_data), .full  (f_full),
    .pop  (f_pop),  .rdata (f_rdata), .empty (f_empty),
    .used (f_used)
  );

  // ---------------- Burst sizing ----------------
  // Each burst = min(configured burst, beats remaining)
  logic [BEATS_W-1:0] bb, rd_burst, wr_burst;
  logic [FAW:0]       f_free;

  assign bb       = burst_beats(desc.burst);
  assign rd_burst = (rd_rem < REM_W'(bb)) ? BEATS_W'(rd_rem) : bb;
  assign wr_burst = (wr_rem < REM_W'(bb)) ? BEATS_W'(wr_rem) : bb;
  assign f_free   = (FAW+1)'(FIFO_DEPTH) - f_used;

  // Descriptor sanity: non-zero length, everything 8-byte aligned
  logic desc_ok;
  assign desc_ok = (desc.length != '0) && (desc.length[2:0] == 3'b0) &&
                   (desc.src_addr[2:0] == 3'b0) && (desc.dst_addr[2:0] == 3'b0);

  // ---------------- Main / read FSM ----------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      state       <= S_IDLE;
      desc_addr   <= '0;
      desc_lo     <= '0;
      desc        <= '0;
      desc_active <= 1'b0;
      rd_ptr      <= '0;
      rd_rem      <= '0;
    end else begin
      case (state)
        S_IDLE: if (start) begin
          desc_addr <= desc_ptr_in;
          state     <= (desc_ptr_in[3:0] != 4'b0) ? S_ERR : S_FETCH_REQ;
        end

        // Descriptor = one 2-beat read on the shared read port
        S_FETCH_REQ:  if (rd_ack) state <= S_FETCH_DATA;

        S_FETCH_DATA: if (rd_valid) begin
          if (rd_last) begin
            desc  <= desc_t'({rd_data, desc_lo});
            state <= S_CHECK;
          end else begin
            desc_lo <= rd_data;
          end
        end

        S_CHECK: begin
          if (desc_ok) begin
            rd_ptr      <= desc.src_addr;
            rd_rem      <= REM_W'(desc.length >> 3);
            desc_active <= 1'b1;
            state       <= S_RD_ISSUE;
          end else begin
            state <= S_ERR;
          end
        end

        S_RD_ISSUE: begin
          if (rd_rem == '0)  state <= S_WAIT_WR;
          else if (rd_ack)   state <= S_RD_DATA;
        end

        S_RD_DATA: if (rd_valid && rd_last) begin
          rd_ptr <= rd_ptr + ADDR_W'({rd_burst, 3'b000});   // beats * 8 bytes
          rd_rem <= rd_rem - REM_W'(rd_burst);
          state  <= S_RD_ISSUE;
        end

        // All reads done; wait for the write side to drain this descriptor.
        // Descriptor registers are shared, so the next fetch must wait.
        S_WAIT_WR: if (wr_rem == '0 && wstate == W_IDLE) begin
          desc_active <= 1'b0;
          if (desc.last) begin
            state <= S_IDLE;
          end else begin
            desc_addr <= desc.next_ptr;
            state     <= (desc.next_ptr[3:0] != 4'b0) ? S_ERR : S_FETCH_REQ;
          end
        end

        S_ERR: begin
          desc_active <= 1'b0;
          state       <= S_IDLE;
        end

        default: state <= S_IDLE;
      endcase
    end
  end

  // Read port request: descriptor fetch, or a data burst that fits in the FIFO.
  // Once asserted it stays asserted until rd_ack (free space only grows
  // while waiting, because only the write side touches the FIFO then).
  always_comb begin
    rd_req  = 1'b0;
    rd_addr = rd_ptr;
    rd_len  = rd_burst;
    if (state == S_FETCH_REQ) begin
      rd_req  = 1'b1;
      rd_addr = desc_addr;
      rd_len  = BEATS_W'(2);
    end else if (state == S_RD_ISSUE && rd_rem != '0 &&
                 f_free >= (FAW+1)'(rd_burst)) begin
      rd_req  = 1'b1;
    end
  end

  assign f_push = (state == S_RD_DATA) && rd_valid;

  // ---------------- Write FSM ----------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      wstate <= W_IDLE;
      wr_ptr <= '0;
      wr_rem <= '0;
      wcnt   <= '0;
    end else begin
      // Load write-side counters when the descriptor is accepted
      if (state == S_CHECK && desc_ok) begin
        wr_ptr <= desc.dst_addr;
        wr_rem <= REM_W'(desc.length >> 3);
      end

      case (wstate)
        W_IDLE: if (desc_active && wr_rem != '0 &&
                    f_used >= (FAW+1)'(wr_burst)) wstate <= W_REQ;

        W_REQ:  if (wr_ack) begin
          wcnt   <= '0;
          wstate <= W_DATA;
        end

        W_DATA: if (wr_beat) begin
          if (wr_data_last) begin
            wr_ptr <= wr_ptr + ADDR_W'({wr_burst, 3'b000});
            wr_rem <= wr_rem - REM_W'(wr_burst);
            wstate <= W_IDLE;
          end else begin
            wcnt <= wcnt + 1'b1;
          end
        end

        default: wstate <= W_IDLE;
      endcase
    end
  end

  assign wr_req        = (wstate == W_REQ);
  assign wr_addr       = wr_ptr;
  assign wr_len        = wr_burst;
  assign wr_data_valid = (wstate == W_DATA) && !f_empty;
  assign wr_data       = f_rdata;
  assign wr_data_last  = (wcnt == wr_burst - 1'b1);
  assign f_pop         = wr_beat;

  // ---------------- Status / events ----------------
  assign busy     = (state != S_IDLE);
  assign err_evt  = (state == S_ERR);
  assign done_evt = (state == S_WAIT_WR) && (wr_rem == '0) &&
                    (wstate == W_IDLE) && desc.irq_en;

  // f_full is not needed: the free-space check guarantees no overflow
  logic unused;
  assign unused = f_full ^ ^desc.rsvd;

endmodule
