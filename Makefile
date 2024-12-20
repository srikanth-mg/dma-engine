# Verilator flow for the DMA engine
#   make lint   : -Wall lint of the RTL only
#   make sim    : build and run the self-checking testbench
#   make seeds  : run the testbench with 10 random seeds
#   make clean

RTL = rtl/dma_pkg.sv rtl/dma_fifo.sv rtl/dma_rr_arbiter.sv \
      rtl/dma_apb_regs.sv rtl/dma_channel.sv rtl/dma_top.sv
TB  = tb/mem_model.sv tb/tb_dma_top.sv

VFLAGS = --binary --timing --timescale 1ns/1ps -Wno-fatal \
         -Wno-INITIALDLY -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-UNUSEDPARAM

.PHONY: lint sim seeds clean

lint:
	verilator --lint-only -Wall $(RTL) --top-module dma_top && echo "LINT CLEAN"

build/sim: $(RTL) $(TB)
	verilator $(VFLAGS) --top-module tb_dma_top -Mdir build -o sim $(RTL) $(TB)

sim: build/sim
	./build/sim

seeds: build/sim
	@for s in 1 2 3 4 5 6 7 8 9 10; do \
	  printf "seed %-3s " $$s; \
	  ./build/sim +verilator+seed+$$s | grep -E "RESULT|TIMEOUT"; \
	done

clean:
	rm -rf build
