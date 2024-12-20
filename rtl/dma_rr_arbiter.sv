// dma_rr_arbiter.sv
// N-way round-robin arbiter.
// - grant is combinational from req and the rotating priority pointer.
// - The pointer only moves when the grant is actually used (accept=1),
//   so a requester that is granted but not yet accepted keeps priority.
// - After channel i is served, priority starts at i+1: no channel can be
//   starved, every requester is served within N grants.

module dma_rr_arbiter #(
  parameter int  N  = 4,
  localparam int IW = $clog2(N)
) (
  input  logic          clk,
  input  logic          rst_n,
  input  logic [N-1:0]  req,
  input  logic          accept,     // grant consumed this cycle
  output logic [N-1:0]  grant,      // one-hot
  output logic [IW-1:0] grant_idx,
  output logic          grant_vld   // at least one request
);

  logic [IW-1:0] ptr;               // highest-priority index this round

  // Scan from ptr upward (with wrap); first requester wins
  always_comb begin
    grant     = '0;
    grant_idx = '0;
    grant_vld = 1'b0;
    for (int i = 0; i < N; i++) begin
      logic [IW-1:0] idx;
      idx = IW'((32'(ptr) + i) % N);
      if (!grant_vld && req[idx]) begin
        grant[idx] = 1'b1;
        grant_idx  = idx;
        grant_vld  = 1'b1;
      end
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n)                   ptr <= '0;
    else if (accept && grant_vld) ptr <= IW'((32'(grant_idx) + 1) % N);
  end

endmodule
