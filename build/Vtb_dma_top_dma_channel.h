// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_dma_top.h for the primary calling header

#ifndef VERILATED_VTB_DMA_TOP_DMA_CHANNEL_H_
#define VERILATED_VTB_DMA_TOP_DMA_CHANNEL_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_dma_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_dma_top_dma_channel final {
  public:

    // DESIGN-SPECIFIC STATE
    CData/*0:0*/ clk;
    CData/*0:0*/ rst_n;
    CData/*0:0*/ start;
    CData/*0:0*/ busy;
    CData/*0:0*/ done_evt;
    CData/*0:0*/ err_evt;
    CData/*0:0*/ rd_req;
    CData/*3:0*/ rd_len;
    CData/*0:0*/ rd_ack;
    CData/*0:0*/ rd_valid;
    CData/*0:0*/ rd_last;
    CData/*0:0*/ wr_req;
    CData/*3:0*/ wr_len;
    CData/*0:0*/ wr_ack;
    CData/*0:0*/ wr_data_valid;
    CData/*0:0*/ wr_data_last;
    CData/*0:0*/ wr_beat;
    CData/*2:0*/ __PVT__state;
    CData/*1:0*/ __PVT__wstate;
    CData/*0:0*/ __PVT__desc_active;
    CData/*3:0*/ __PVT__wcnt;
    CData/*3:0*/ __PVT__f_used;
    CData/*3:0*/ __PVT__rd_burst;
    CData/*0:0*/ __PVT__desc_ok;
    CData/*3:0*/ __PVT__u_fifo__DOT__wr_ptr;
    CData/*3:0*/ __PVT__u_fifo__DOT__rd_ptr;
    CData/*0:0*/ __PVT__u_fifo__DOT__do_push;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    CData/*2:0*/ __Vdly__state;
    CData/*1:0*/ __Vdly__wstate;
    CData/*3:0*/ __Vdly__u_fifo__DOT__wr_ptr;
    CData/*3:0*/ __Vdly__u_fifo__DOT__rd_ptr;
    SData/*12:0*/ __PVT__rd_rem;
    SData/*12:0*/ __PVT__wr_rem;
    SData/*12:0*/ __Vdly__wr_rem;
    IData/*31:0*/ desc_ptr_in;
    IData/*31:0*/ rd_addr;
    IData/*31:0*/ wr_addr;
    IData/*31:0*/ __PVT__desc_addr;
    IData/*31:0*/ __PVT__rd_ptr;
    IData/*31:0*/ __PVT__wr_ptr;
    QData/*63:0*/ rd_data;
    QData/*63:0*/ wr_data;
    QData/*63:0*/ __PVT__desc_lo;
    VlWide<4>/*127:0*/ __PVT__desc;
    VlWide<4>/*127:0*/ __Vdly__desc;
    VlUnpacked<QData/*63:0*/, 8> __PVT__u_fifo__DOT__mem;

    // INTERNAL VARIABLES
    Vtb_dma_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_dma_top_dma_channel();
    ~Vtb_dma_top_dma_channel();
    void ctor(Vtb_dma_top__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtb_dma_top_dma_channel);

    // INTERNAL METHODS
};


#endif  // guard
