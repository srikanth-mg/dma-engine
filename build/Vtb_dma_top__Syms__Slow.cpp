// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_dma_top__pch.h"

Vtb_dma_top__Syms::Vtb_dma_top__Syms(VerilatedContext* contextp, const char* namep, Vtb_dma_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_didInit{modelp->m_didInit}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(2441);
    // Setup sub module instances
    TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.ctor(this, "tb_dma_top.dut.g_ch[0].u_ch");
    TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.ctor(this, "tb_dma_top.dut.g_ch[1].u_ch");
    TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.ctor(this, "tb_dma_top.dut.g_ch[2].u_ch");
    TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.ctor(this, "tb_dma_top.dut.g_ch[3].u_ch");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch = &TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch;
    TOP.__PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch = &TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch;
    TOP.__PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch = &TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch;
    TOP.__PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch = &TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch;
}

Vtb_dma_top__Syms::~Vtb_dma_top__Syms() {
    // Tear down scopes
    // Tear down sub module instances
    TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.dtor();
    TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.dtor();
    TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.dtor();
    TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.dtor();
}
