// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_DMA_TOP__SYMS_H_
#define VERILATED_VTB_DMA_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_dma_top.h"

// INCLUDE MODULE CLASSES
#include "Vtb_dma_top___024root.h"
#include "Vtb_dma_top_dma_channel.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_dma_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_dma_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    Vtb_dma_top___024root          TOP;
    Vtb_dma_top_dma_channel        TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch;
    Vtb_dma_top_dma_channel        TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch;
    Vtb_dma_top_dma_channel        TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch;
    Vtb_dma_top_dma_channel        TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch;

    // CONSTRUCTORS
    Vtb_dma_top__Syms(VerilatedContext* contextp, const char* namep, Vtb_dma_top* modelp);
    ~Vtb_dma_top__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
