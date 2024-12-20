// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dma_top.h for the primary calling header

#include "Vtb_dma_top__pch.h"

void Vtb_dma_top___024root___ctor_var_reset(Vtb_dma_top___024root* vlSelf);

Vtb_dma_top___024root::Vtb_dma_top___024root(Vtb_dma_top__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_dma_top___024root___ctor_var_reset(this);
}

Vtb_dma_top___024root::~Vtb_dma_top___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
