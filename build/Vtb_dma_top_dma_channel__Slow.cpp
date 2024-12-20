// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dma_top.h for the primary calling header

#include "Vtb_dma_top__pch.h"

void Vtb_dma_top_dma_channel___ctor_var_reset(Vtb_dma_top_dma_channel* vlSelf);

Vtb_dma_top_dma_channel::Vtb_dma_top_dma_channel() = default;
Vtb_dma_top_dma_channel::~Vtb_dma_top_dma_channel() = default;

void Vtb_dma_top_dma_channel::ctor(Vtb_dma_top__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtb_dma_top_dma_channel___ctor_var_reset(this);
}

void Vtb_dma_top_dma_channel::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
