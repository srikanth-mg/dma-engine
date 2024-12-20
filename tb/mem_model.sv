// mem_model.sv
// Behavioral 64 KB memory with independent read and write ports.
// - Random back-pressure on request and write-data handshakes
// - Fixed read latency plus random gaps between read beats
// - Protocol checks: request must stay stable while valid && !ready,
//   write 'last' must match the requested burst length

module mem_model
  import dma_pkg::*;
#(
  parameter int RD_LAT  = 4,     // cycles from request accept to first beat
  parameter int BP_PCT  = 30     // % of cycles a ready is held low
) (
  input  logic                clk,
  input  logic                rst_n,

  input  logic                rd_req_valid,
  output logic                rd_req_ready,
  input  logic [ADDR_W-1:0]   rd_req_addr,
  input  logic [BEATS_W-1:0]  rd_req_len,
  output logic                rd_valid,
  output logic [DATA_W-1:0]   rd_data,
  output logic                rd_last,

  input  logic                wr_req_valid,
  output logic                wr_req_ready,
  input  logic [ADDR_W-1:0]   wr_req_addr,
  input  logic [BEATS_W-1:0]  wr_req_len,
  input  logic                wr_data_valid,
  output logic                wr_data_ready,
  input  logic [DATA_W-1:0]   wr_data,
  input  logic                wr_last
);

  localparam int WORDS = 8192;                 // 64 KB / 8 bytes
  logic [DATA_W-1:0] mem [WORDS];              // TB pokes/peeks this directly

  int errors = 0;

  function automatic bit stall();
    return ($urandom_range(99) < BP_PCT);
  endfunction

  // ---------------- Read port ----------------
  typedef enum { R_IDLE, R_WAIT, R_BURST } r_e;
  r_e                 rst_q;
  logic [ADDR_W-1:0]  r_addr;
  int                 r_left, r_lat;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      rst_q        <= R_IDLE;
      rd_req_ready <= 1'b0;
      rd_valid     <= 1'b0;
      rd_last      <= 1'b0;
      rd_data      <= '0;
    end else begin
      rd_valid <= 1'b0;
      rd_last  <= 1'b0;
      case (rst_q)
        R_IDLE: begin
          rd_req_ready <= !stall();
          if (rd_req_valid && rd_req_ready) begin
            if (rd_req_len == 0 || rd_req_len > 8) begin
              $error("[MEM] bad read length %0d", rd_req_len); errors++;
            end
            r_addr       <= rd_req_addr;
            r_left       <= int'(rd_req_len);
            r_lat        <= RD_LAT;
            rd_req_ready <= 1'b0;
            rst_q        <= R_WAIT;
          end
        end
        R_WAIT: begin
          if (r_lat <= 1) rst_q <= R_BURST;
          else            r_lat <= r_lat - 1;
        end
        R_BURST: if (!stall()) begin        // random gaps between beats
          rd_valid <= 1'b1;
          rd_data  <= mem[r_addr[15:3]];
          rd_last  <= (r_left == 1);
          r_addr   <= r_addr + 8;
          r_left   <= r_left - 1;
          if (r_left == 1) rst_q <= R_IDLE;
        end
      endcase
    end
  end

  // ---------------- Write port ----------------
  typedef enum { W_IDLE, W_DATA } w_e;
  w_e                 wst_q;
  logic [ADDR_W-1:0]  w_addr;
  int                 w_left;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      wst_q         <= W_IDLE;
      wr_req_ready  <= 1'b0;
      wr_data_ready <= 1'b0;
    end else begin
      case (wst_q)
        W_IDLE: begin
          wr_data_ready <= 1'b0;
          wr_req_ready  <= !stall();
          if (wr_req_valid && wr_req_ready) begin
            w_addr        <= wr_req_addr;
            w_left        <= int'(wr_req_len);
            wr_req_ready  <= 1'b0;
            wr_data_ready <= !stall();
            wst_q         <= W_DATA;
          end
        end
        W_DATA: begin
          wr_data_ready <= !stall();
          if (wr_data_valid && wr_data_ready) begin
            mem[w_addr[15:3]] <= wr_data;
            if (wr_last != (w_left == 1)) begin
              $error("[MEM] wr_last=%0b with %0d beats left", wr_last, w_left); errors++;
            end
            w_addr <= w_addr + 8;
            w_left <= w_left - 1;
            if (w_left == 1) begin
              wr_data_ready <= 1'b0;
              wst_q         <= W_IDLE;
            end
          end
        end
      endcase
    end
  end

  // ---------------- Request stability checks ----------------
  logic [ADDR_W-1:0]  p_raddr, p_waddr;
  logic [BEATS_W-1:0] p_rlen,  p_wlen;
  logic               p_rhold, p_whold;

  always_ff @(posedge clk) begin
    if (p_rhold && (!rd_req_valid || rd_req_addr != p_raddr || rd_req_len != p_rlen)) begin
      $error("[MEM] read request changed while waiting for ready"); errors++;
    end
    if (p_whold && (!wr_req_valid || wr_req_addr != p_waddr || wr_req_len != p_wlen)) begin
      $error("[MEM] write request changed while waiting for ready"); errors++;
    end
    p_rhold <= rst_n && rd_req_valid && !rd_req_ready;
    p_whold <= rst_n && wr_req_valid && !wr_req_ready;
    p_raddr <= rd_req_addr;  p_rlen <= rd_req_len;
    p_waddr <= wr_req_addr;  p_wlen <= wr_req_len;
  end

endmodule
