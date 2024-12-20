// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dma_top.h for the primary calling header

#include "Vtb_dma_top__pch.h"

void Vtb_dma_top___024root___timing_ready(Vtb_dma_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_dma_top___024root___eval_static(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_static\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        CData/*1:0*/ __Vinline_0__eval_static__TOP_tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
        __Vinline_0__eval_static__TOP_tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
        CData/*1:0*/ __Vinline_0__eval_static__TOP_tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
        __Vinline_0__eval_static__TOP_tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
        vlSelfRef.tb_dma_top__DOT__clk = 0U;
        vlSelfRef.tb_dma_top__DOT__rst_n = 0U;
        vlSelfRef.tb_dma_top__DOT__psel = 0U;
        vlSelfRef.tb_dma_top__DOT__penable = 0U;
        vlSelfRef.tb_dma_top__DOT__pwrite = 0U;
        vlSelfRef.tb_dma_top__DOT__paddr = 0U;
        vlSelfRef.tb_dma_top__DOT__pwdata = 0U;
        vlSelfRef.tb_dma_top__DOT__pass_cnt = 0U;
        vlSelfRef.tb_dma_top__DOT__fail_cnt = 0U;
        vlSelfRef.tb_dma_top__DOT__rd_beats = 0U;
        vlSelfRef.tb_dma_top__DOT__wr_beats = 0U;
        vlSelfRef.tb_dma_top__DOT__overlap_cycles = 0U;
        __Vinline_0__eval_static__TOP_tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
        __Vinline_0__eval_static__TOP_tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
        vlSelfRef.tb_dma_top__DOT__u_mem__DOT__errors = 0U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__tb_dma_top__DOT__clk__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_dma_top__DOT__rst_n__0 = 0U;
    Vtb_dma_top___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dma_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_dma_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf);
VL_ATTR_COLD void Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf);
VL_ATTR_COLD void Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf);
VL_ATTR_COLD void Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf);
VL_ATTR_COLD void Vtb_dma_top___024root___stl_sequent__TOP__0(Vtb_dma_top___024root* vlSelf);
void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__4(Vtb_dma_top_dma_channel* vlSelf);
void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__4(Vtb_dma_top_dma_channel* vlSelf);
void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__4(Vtb_dma_top_dma_channel* vlSelf);
void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__4(Vtb_dma_top_dma_channel* vlSelf);

VL_ATTR_COLD bool Vtb_dma_top___024root___eval_stl(Vtb_dma_top___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_stl\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_dma_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_dma_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__0((&vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch));
                Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__0((&vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch));
                Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__0((&vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch));
                Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__0((&vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch));
                Vtb_dma_top___024root___stl_sequent__TOP__0(vlSelf);
                Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__4((&vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch));
                Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__4((&vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch));
                Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__4((&vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch));
                Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__4((&vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch));
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__stl(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_dump_triggers__stl\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_dma_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dma_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__ico(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_dump_triggers__ico\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_dma_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dma_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__act(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_dump_triggers__act\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_dma_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__nba(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_dump_triggers__nba\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_dma_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__obs(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_dump_triggers__obs\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__react(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_dump_triggers__react\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_dma_top___024root___eval_final(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___eval_final\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_final__TOP
        VL_WRITEF_NX("Coverage: %0d read beats, %0d write beats, %0d cycles with read+write overlap\n",3
                     , '~',32,vlSelfRef.tb_dma_top__DOT__rd_beats
                     , '~',32,vlSelfRef.tb_dma_top__DOT__wr_beats
                     , '~',32,vlSelfRef.tb_dma_top__DOT__overlap_cycles);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dma_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_dma_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_dma_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vtb_dma_top___024root___stl_sequent__TOP__0(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___stl_sequent__TOP__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ tb_dma_top__DOT__dut__DOT__c_rd_req;
    tb_dma_top__DOT__dut__DOT__c_rd_req = 0;
    CData/*3:0*/ tb_dma_top__DOT__dut__DOT__c_wr_req;
    tb_dma_top__DOT__dut__DOT__c_wr_req = 0;
    CData/*3:0*/ tb_dma_top__DOT__dut__DOT__r_gnt;
    tb_dma_top__DOT__dut__DOT__r_gnt = 0;
    CData/*3:0*/ tb_dma_top__DOT__dut__DOT__w_gnt;
    tb_dma_top__DOT__dut__DOT__w_gnt = 0;
    CData/*1:0*/ tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
    CData/*1:0*/ tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_4;
    // Body
    vlSelfRef.tb_dma_top__DOT__dut__DOT__c_rd_ack = 0U;
    vlSelfRef.tb_dma_top__DOT__dut__DOT__c_rd_ack = 
        (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_own))) 
          & (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__c_rd_ack)) 
         | (0x0fU & (((1U == (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__rstate)) 
                      & (IData)(vlSelfRef.tb_dma_top__DOT__rd_req_ready)) 
                     << (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_own))));
    vlSelfRef.tb_dma_top__DOT__dut__DOT__c_wr_ack = 0U;
    vlSelfRef.tb_dma_top__DOT__dut__DOT__c_wr_ack = 
        (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_own))) 
          & (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__c_wr_ack)) 
         | (0x0fU & (((1U == (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__wstate)) 
                      & (IData)(vlSelfRef.tb_dma_top__DOT__wr_req_ready)) 
                     << (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_own))));
    __Vtemp_2[0U] = vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__wr_ptr;
    __Vtemp_2[1U] = vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__wr_ptr;
    __Vtemp_2[2U] = (IData)((((QData)((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__wr_ptr)) 
                              << 0x00000020U) | (QData)((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__wr_ptr))));
    __Vtemp_2[3U] = (IData)(((((QData)((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__wr_ptr)) 
                               << 0x00000020U) | (QData)((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__wr_ptr))) 
                             >> 0x00000020U));
    vlSelfRef.tb_dma_top__DOT__wr_req_addr = __Vtemp_2
        [(0x07ffffffU & (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_own))];
    __Vtemp_4[0U] = ((1U == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__state))
                      ? vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__desc_addr
                      : vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__rd_ptr);
    __Vtemp_4[1U] = ((1U == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__state))
                      ? vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__desc_addr
                      : vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__rd_ptr);
    __Vtemp_4[2U] = (IData)((((QData)((IData)(((1U 
                                                == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__state))
                                                ? vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__desc_addr
                                                : vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__rd_ptr))) 
                              << 0x00000020U) | (QData)((IData)(
                                                                ((1U 
                                                                  == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__state))
                                                                  ? vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__desc_addr
                                                                  : vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__rd_ptr)))));
    __Vtemp_4[3U] = (IData)(((((QData)((IData)(((1U 
                                                 == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__state))
                                                 ? vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__desc_addr
                                                 : vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__rd_ptr))) 
                               << 0x00000020U) | (QData)((IData)(
                                                                 ((1U 
                                                                   == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__state))
                                                                   ? vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__desc_addr
                                                                   : vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__rd_ptr)))) 
                             >> 0x00000020U));
    vlSelfRef.tb_dma_top__DOT__rd_req_addr = __Vtemp_4
        [(0x07ffffffU & (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_own))];
    tb_dma_top__DOT__dut__DOT__c_wr_req = ((((1U == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__wstate)) 
                                             << 3U) 
                                            | ((1U 
                                                == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__wstate)) 
                                               << 2U)) 
                                           | (((1U 
                                                == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__wstate)) 
                                               << 1U) 
                                              | (1U 
                                                 == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__wstate))));
    vlSelfRef.tb_dma_top__DOT__dut__DOT__busy = (((
                                                   (0U 
                                                    != (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__state)) 
                                                   << 3U) 
                                                  | ((0U 
                                                      != (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__state)) 
                                                     << 2U)) 
                                                 | (((0U 
                                                      != (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__state)) 
                                                     << 1U) 
                                                    | (0U 
                                                       != (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__state))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.tb_dma_top__DOT__psel) 
                                                & (IData)(vlSelfRef.tb_dma_top__DOT__penable));
    vlSelfRef.tb_dma_top__DOT__dut__DOT__c_rd_valid = 0U;
    vlSelfRef.tb_dma_top__DOT__dut__DOT__c_rd_valid 
        = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_own))) 
            & (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__c_rd_valid)) 
           | (0x0fU & (((2U == (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__rstate)) 
                        & (IData)(vlSelfRef.tb_dma_top__DOT__rd_valid)) 
                       << (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_own))));
    vlSelfRef.tb_dma_top__DOT__wr_req_len = (0x0000000fU 
                                             & (((((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.wr_len) 
                                                   << 0x0000000cU) 
                                                  | ((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.wr_len) 
                                                     << 8U)) 
                                                 | (((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.wr_len) 
                                                     << 4U) 
                                                    | (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.wr_len))) 
                                                >> 
                                                ((IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_own) 
                                                 << 2U)));
    vlSelfRef.tb_dma_top__DOT__wr_data_valid = ((2U 
                                                 == (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__wstate)) 
                                                & ((((((2U 
                                                        == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__wstate)) 
                                                       & (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__VdfgRegularize_h6e95ff9d_0_4)) 
                                                      << 3U) 
                                                     | (((2U 
                                                          == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__wstate)) 
                                                         & (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__VdfgRegularize_h6e95ff9d_0_3)) 
                                                        << 2U)) 
                                                    | ((((2U 
                                                          == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__wstate)) 
                                                         & (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__VdfgRegularize_h6e95ff9d_0_2)) 
                                                        << 1U) 
                                                       | ((2U 
                                                           == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__wstate)) 
                                                          & (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__VdfgRegularize_h6e95ff9d_0_1)))) 
                                                   >> (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_own)));
    vlSelfRef.tb_dma_top__DOT__rd_req_len = (0x0000000fU 
                                             & ((((((1U 
                                                     == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__state))
                                                     ? 2U
                                                     : (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__rd_burst)) 
                                                   << 0x0000000cU) 
                                                  | (((1U 
                                                       == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__state))
                                                       ? 2U
                                                       : (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__rd_burst)) 
                                                     << 8U)) 
                                                 | ((((1U 
                                                       == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__state))
                                                       ? 2U
                                                       : (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__rd_burst)) 
                                                     << 4U) 
                                                    | ((1U 
                                                        == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__state))
                                                        ? 2U
                                                        : (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__rd_burst)))) 
                                                >> 
                                                ((IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_own) 
                                                 << 2U)));
    tb_dma_top__DOT__dut__DOT__c_rd_req = (((((1U == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__state)) 
                                              | ((4U 
                                                  == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__state)) 
                                                 & ((0U 
                                                     != (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__rd_rem)) 
                                                    & ((0x0000000fU 
                                                        & ((IData)(8U) 
                                                           - (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__f_used))) 
                                                       >= (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.__PVT__rd_burst))))) 
                                             << 3U) 
                                            | (((1U 
                                                 == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__state)) 
                                                | ((4U 
                                                    == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__state)) 
                                                   & ((0U 
                                                       != (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__rd_rem)) 
                                                      & ((0x0000000fU 
                                                          & ((IData)(8U) 
                                                             - (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__f_used))) 
                                                         >= (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.__PVT__rd_burst))))) 
                                               << 2U)) 
                                           | ((((1U 
                                                 == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__state)) 
                                                | ((4U 
                                                    == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__state)) 
                                                   & ((0U 
                                                       != (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__rd_rem)) 
                                                      & ((0x0000000fU 
                                                          & ((IData)(8U) 
                                                             - (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__f_used))) 
                                                         >= (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.__PVT__rd_burst))))) 
                                               << 1U) 
                                              | ((1U 
                                                  == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__state)) 
                                                 | ((4U 
                                                     == (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__state)) 
                                                    & ((0U 
                                                        != (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__rd_rem)) 
                                                       & ((0x0000000fU 
                                                           & ((IData)(8U) 
                                                              - (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__f_used))) 
                                                          >= (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.__PVT__rd_burst)))))));
    vlSelfRef.tb_dma_top__DOT__wr_last = (1U & (((((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch.wr_data_last) 
                                                   << 3U) 
                                                  | ((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch.wr_data_last) 
                                                     << 2U)) 
                                                 | (((IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch.wr_data_last) 
                                                     << 1U) 
                                                    | (IData)(vlSymsp->TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch.wr_data_last))) 
                                                >> (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_own)));
    tb_dma_top__DOT__dut__DOT__w_gnt = 0U;
    vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_idx = 0U;
    vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_vld = 0U;
    tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = vlSelfRef.tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__ptr;
    if ((1U & ((IData)(tb_dma_top__DOT__dut__DOT__c_wr_req) 
               >> (IData)(tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx)))) {
        tb_dma_top__DOT__dut__DOT__w_gnt = ((IData)(tb_dma_top__DOT__dut__DOT__w_gnt) 
                                            | (0x0fU 
                                               & ((IData)(1U) 
                                                  << (IData)(tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))));
        vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_vld = 1U;
        vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_idx 
            = tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__ptr)));
    if ((1U & ((~ (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_vld)) 
               & ((IData)(tb_dma_top__DOT__dut__DOT__c_wr_req) 
                  >> (IData)(tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))))) {
        tb_dma_top__DOT__dut__DOT__w_gnt = ((IData)(tb_dma_top__DOT__dut__DOT__w_gnt) 
                                            | (0x0fU 
                                               & ((IData)(1U) 
                                                  << (IData)(tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))));
        vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_vld = 1U;
        vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_idx 
            = tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (3U & ((IData)(2U) + (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__ptr)));
    if ((1U & ((~ (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_vld)) 
               & ((IData)(tb_dma_top__DOT__dut__DOT__c_wr_req) 
                  >> (IData)(tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))))) {
        tb_dma_top__DOT__dut__DOT__w_gnt = ((IData)(tb_dma_top__DOT__dut__DOT__w_gnt) 
                                            | (0x0fU 
                                               & ((IData)(1U) 
                                                  << (IData)(tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))));
        vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_vld = 1U;
        vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_idx 
            = tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (3U & ((IData)(3U) + (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__ptr)));
    if ((1U & ((~ (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_vld)) 
               & ((IData)(tb_dma_top__DOT__dut__DOT__c_wr_req) 
                  >> (IData)(tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))))) {
        tb_dma_top__DOT__dut__DOT__w_gnt = ((IData)(tb_dma_top__DOT__dut__DOT__w_gnt) 
                                            | (0x0fU 
                                               & ((IData)(1U) 
                                                  << (IData)(tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))));
        vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_vld = 1U;
        vlSelfRef.tb_dma_top__DOT__dut__DOT__w_gnt_idx 
            = tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    vlSelfRef.tb_dma_top__DOT__prdata = (((0U == (3U 
                                                  & ((IData)(vlSelfRef.tb_dma_top__DOT__paddr) 
                                                     >> 6U)))
                                           ? ((0U == 
                                               (3U 
                                                & ((IData)(vlSelfRef.tb_dma_top__DOT__paddr) 
                                                   >> 2U)))
                                               ? vlSelfRef.tb_dma_top__DOT__dut__DOT__desc_ptr
                                              [(3U 
                                                & ((IData)(vlSelfRef.tb_dma_top__DOT__paddr) 
                                                   >> 4U))]
                                               : (1U 
                                                  & ((- (IData)(
                                                                (2U 
                                                                 == 
                                                                 (3U 
                                                                  & ((IData)(vlSelfRef.tb_dma_top__DOT__paddr) 
                                                                     >> 2U))))) 
                                                     & ((IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__busy) 
                                                        >> 
                                                        (3U 
                                                         & ((IData)(vlSelfRef.tb_dma_top__DOT__paddr) 
                                                            >> 4U))))))
                                           : ((0x40U 
                                               == (IData)(vlSelfRef.tb_dma_top__DOT__paddr))
                                               ? (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_regs__DOT__irq_status)
                                               : ((- (IData)(
                                                             (0x44U 
                                                              == (IData)(vlSelfRef.tb_dma_top__DOT__paddr)))) 
                                                  & (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_regs__DOT__irq_mask)))) 
                                         & (- (IData)(
                                                      ((~ (IData)(vlSelfRef.tb_dma_top__DOT__pwrite)) 
                                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)))));
    vlSelfRef.tb_dma_top__DOT__dut__DOT__u_regs__DOT__wr_en 
        = ((IData)(vlSelfRef.tb_dma_top__DOT__pwrite) 
           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.tb_dma_top__DOT__dut__DOT__w_beat = (
                                                   (2U 
                                                    == (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__wstate)) 
                                                   & ((IData)(vlSelfRef.tb_dma_top__DOT__wr_data_ready) 
                                                      & (IData)(vlSelfRef.tb_dma_top__DOT__wr_data_valid)));
    tb_dma_top__DOT__dut__DOT__r_gnt = 0U;
    vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_idx = 0U;
    vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_vld = 0U;
    tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = vlSelfRef.tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__ptr;
    if ((1U & ((IData)(tb_dma_top__DOT__dut__DOT__c_rd_req) 
               >> (IData)(tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx)))) {
        tb_dma_top__DOT__dut__DOT__r_gnt = ((IData)(tb_dma_top__DOT__dut__DOT__r_gnt) 
                                            | (0x0fU 
                                               & ((IData)(1U) 
                                                  << (IData)(tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))));
        vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_vld = 1U;
        vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_idx 
            = tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__ptr)));
    if ((1U & ((~ (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_vld)) 
               & ((IData)(tb_dma_top__DOT__dut__DOT__c_rd_req) 
                  >> (IData)(tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))))) {
        tb_dma_top__DOT__dut__DOT__r_gnt = ((IData)(tb_dma_top__DOT__dut__DOT__r_gnt) 
                                            | (0x0fU 
                                               & ((IData)(1U) 
                                                  << (IData)(tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))));
        vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_vld = 1U;
        vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_idx 
            = tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (3U & ((IData)(2U) + (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__ptr)));
    if ((1U & ((~ (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_vld)) 
               & ((IData)(tb_dma_top__DOT__dut__DOT__c_rd_req) 
                  >> (IData)(tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))))) {
        tb_dma_top__DOT__dut__DOT__r_gnt = ((IData)(tb_dma_top__DOT__dut__DOT__r_gnt) 
                                            | (0x0fU 
                                               & ((IData)(1U) 
                                                  << (IData)(tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))));
        vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_vld = 1U;
        vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_idx 
            = tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (3U & ((IData)(3U) + (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__ptr)));
    if ((1U & ((~ (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_vld)) 
               & ((IData)(tb_dma_top__DOT__dut__DOT__c_rd_req) 
                  >> (IData)(tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))))) {
        tb_dma_top__DOT__dut__DOT__r_gnt = ((IData)(tb_dma_top__DOT__dut__DOT__r_gnt) 
                                            | (0x0fU 
                                               & ((IData)(1U) 
                                                  << (IData)(tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx))));
        vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_vld = 1U;
        vlSelfRef.tb_dma_top__DOT__dut__DOT__r_gnt_idx 
            = tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    vlSelfRef.tb_dma_top__DOT__dut__DOT__start = 0U;
    if (((((IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__u_regs__DOT__wr_en) 
           & (4U == (0xccU & (IData)(vlSelfRef.tb_dma_top__DOT__paddr)))) 
          & vlSelfRef.tb_dma_top__DOT__pwdata) & (~ 
                                                  ((IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__busy) 
                                                   >> 
                                                   (3U 
                                                    & ((IData)(vlSelfRef.tb_dma_top__DOT__paddr) 
                                                       >> 4U)))))) {
        vlSelfRef.tb_dma_top__DOT__dut__DOT__start 
            = ((IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__start) 
               | (0x0fU & ((IData)(1U) << (3U & ((IData)(vlSelfRef.tb_dma_top__DOT__paddr) 
                                                 >> 4U)))));
    }
    vlSelfRef.tb_dma_top__DOT__dut__DOT__c_wr_beat = 0U;
    vlSelfRef.tb_dma_top__DOT__dut__DOT__c_wr_beat 
        = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_own))) 
            & (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__c_wr_beat)) 
           | (0x0fU & ((IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_beat) 
                       << (IData)(vlSelfRef.tb_dma_top__DOT__dut__DOT__w_own))));
}

bool Vtb_dma_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dma_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_dma_top___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtb_dma_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_dma_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_dma_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_dma_top.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_dma_top.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_dma_top___024root___ctor_var_reset(Vtb_dma_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_dma_top___024root___ctor_var_reset\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_dma_top__DOT__prdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10477783191803241083ull);
    vlSelf->tb_dma_top__DOT__rd_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4261326596020023899ull);
    vlSelf->tb_dma_top__DOT__rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2430195541556260394ull);
    vlSelf->tb_dma_top__DOT__rd_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10984152764005702993ull);
    vlSelf->tb_dma_top__DOT__rd_req_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13712523274469972588ull);
    vlSelf->tb_dma_top__DOT__rd_req_len = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2844257552167941383ull);
    vlSelf->tb_dma_top__DOT__rd_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13891394774284383509ull);
    vlSelf->tb_dma_top__DOT__wr_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3995277295816116725ull);
    vlSelf->tb_dma_top__DOT__wr_data_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10436087743052114901ull);
    vlSelf->tb_dma_top__DOT__wr_data_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2168979149379011929ull);
    vlSelf->tb_dma_top__DOT__wr_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6973295789154871793ull);
    vlSelf->tb_dma_top__DOT__wr_req_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5561431974258109025ull);
    vlSelf->tb_dma_top__DOT__wr_req_len = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18358794842697601205ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__start = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17578052977280998958ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__busy = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13133110466518441349ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_dma_top__DOT__dut__DOT__desc_ptr, __VscopeHash, 2760224863332732578ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__c_rd_ack = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3197644894619618629ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__c_rd_valid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11468835989038584428ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__c_wr_ack = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3569232125814282485ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__c_wr_beat = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14017423656915650613ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__rstate = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1599177745979783980ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__r_own = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11119542859952629485ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__r_gnt_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17644564781002229938ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__r_gnt_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7356967162799991316ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__wstate = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1224492744694636503ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__w_own = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9470739387473691732ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__w_gnt_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9418399732308070848ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__w_gnt_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17865142421152963298ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__w_beat = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4574896712731372990ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__u_wr_arb__DOT__ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4180783540697400297ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__u_rd_arb__DOT__ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7333986315133220401ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__u_regs__DOT__irq_status = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17871639921864120516ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__u_regs__DOT__irq_mask = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4910303965446839150ull);
    vlSelf->tb_dma_top__DOT__dut__DOT__u_regs__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4791628551054350054ull);
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->tb_dma_top__DOT__u_mem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14780852991601873666ull);
    }
    vlSelf->tb_dma_top__DOT__u_mem__DOT__rst_q = 0;
    vlSelf->tb_dma_top__DOT__u_mem__DOT__r_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6889602619017784904ull);
    vlSelf->tb_dma_top__DOT__u_mem__DOT__r_left = 0;
    vlSelf->tb_dma_top__DOT__u_mem__DOT__r_lat = 0;
    vlSelf->tb_dma_top__DOT__u_mem__DOT__wst_q = 0;
    vlSelf->tb_dma_top__DOT__u_mem__DOT__w_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13622423865338333481ull);
    vlSelf->tb_dma_top__DOT__u_mem__DOT__w_left = 0;
    vlSelf->tb_dma_top__DOT__u_mem__DOT__p_raddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2270822104875790119ull);
    vlSelf->tb_dma_top__DOT__u_mem__DOT__p_waddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12712192766983101704ull);
    vlSelf->tb_dma_top__DOT__u_mem__DOT__p_rlen = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1122456270516045315ull);
    vlSelf->tb_dma_top__DOT__u_mem__DOT__p_wlen = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10690549144295420281ull);
    vlSelf->tb_dma_top__DOT__u_mem__DOT__p_rhold = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13655445964121543524ull);
    vlSelf->tb_dma_top__DOT__u_mem__DOT__p_whold = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6734940513271562169ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__dut__DOT__rstate = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__dut__DOT__wstate = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__rd_req_ready = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__u_mem__DOT__r_addr = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__u_mem__DOT__r_left = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__u_mem__DOT__r_lat = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__u_mem__DOT__rst_q = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__wr_data_ready = 0;
    vlSelf->__Vdly__tb_dma_top__DOT__wr_req_ready = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v0 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v0 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v0 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v0 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v0 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v0 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v0 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v1 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v1 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v2 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v1 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v2 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v3 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v2 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v1 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v1 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v1 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v1 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v4 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v3 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v5 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v3 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v4 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v6 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v4 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v2 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v2 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v2 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v2 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v7 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v5 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v8 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v5 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v6 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v9 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v6 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v3 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v3 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v10 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v7 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v11 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v8 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v12 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v7 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v4 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v4 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v13 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v9 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v14 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v10 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v15 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v8 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v5 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v5 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v3 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v3 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v16 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v11 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v17 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v9 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v12 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v18 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v10 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v6 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v6 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v4 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v4 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v19 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v13 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v20 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v11 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v14 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v21 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v12 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v7 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v7 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v5 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v5 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v22 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v15 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v23 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v13 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v16 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v24 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v14 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v8 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v8 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v25 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v17 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v26 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v18 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v27 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v15 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v9 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v9 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v28 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v19 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v29 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v20 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v30 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v16 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v10 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v10 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v6 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v6 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v31 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v21 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v32 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v17 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v22 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v33 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v18 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v11 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v11 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v7 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v7 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v34 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v23 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v35 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v19 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v24 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v36 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v20 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v12 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v12 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v8 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v8 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v37 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v25 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v38 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v21 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v26 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v39 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v22 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v13 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v13 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v40 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v27 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v41 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v28 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v42 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v23 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v14 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v14 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v43 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v29 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v44 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v30 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v45 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v24 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v15 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v15 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v9 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v9 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v46 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v31 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v47 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v25 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v32 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v48 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v26 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v16 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v16 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v10 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v10 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v49 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v33 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v50 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v27 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v34 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v51 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v28 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v17 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v17 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v11 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v11 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v52 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v35 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v53 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v29 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v36 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v54 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v30 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v18 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v18 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v55 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v37 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v56 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v38 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v57 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v31 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v19 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v19 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v58 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v39 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v59 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v40 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v60 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v32 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v20 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v20 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v12 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v12 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v61 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v41 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v62 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v33 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v42 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v63 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v34 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v21 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v21 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v13 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v13 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v64 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v43 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v65 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v35 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v44 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v66 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v36 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v22 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v22 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v14 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v14 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v67 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v45 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v68 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v37 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v46 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v69 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v38 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v23 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v23 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v70 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v47 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v71 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v48 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v72 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v39 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v24 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v24 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v73 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v49 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v74 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v50 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v75 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v40 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v25 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v25 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v15 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v15 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v76 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v51 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v77 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v41 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v52 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v78 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v42 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v26 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v26 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v16 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v16 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v79 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v53 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v80 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v43 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v54 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v81 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v44 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v27 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v27 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v17 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v17 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v82 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v55 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v83 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v45 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v56 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v84 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v46 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v28 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v28 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v18 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v18 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v85 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v57 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v86 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v47 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v58 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v87 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v48 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v29 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v29 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v88 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v59 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v89 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v60 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v90 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v49 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v30 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v30 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v91 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v61 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v92 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v62 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v93 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v50 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v31 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v31 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v19 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v19 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v94 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v63 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v95 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v51 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v64 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v96 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v52 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v32 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v32 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v20 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v20 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v97 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v65 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v98 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v53 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v66 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v99 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v54 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v33 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v33 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v100 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v67 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v101 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v68 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v102 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v55 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v34 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v34 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v21 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v21 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v103 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v69 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v104 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v56 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v70 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v105 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v57 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v35 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v35 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v22 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v22 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v106 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v71 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v107 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v58 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v72 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v108 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v59 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v36 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v36 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v23 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v23 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v109 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v73 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v110 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v60 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v74 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v111 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v61 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v37 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v37 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v24 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v24 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v112 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v75 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v113 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v62 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v76 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v114 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v63 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v38 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v38 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v25 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v25 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v115 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v77 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v116 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v64 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v78 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v117 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v65 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v39 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v39 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v118 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v79 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v119 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v80 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v120 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v66 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__paddr__v40 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__paddr__v40 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__pwdata__v26 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwdata__v26 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v121 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__psel__v81 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__penable__v122 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__pwrite__v67 = 0;
    vlSelf->__VdlyVal__tb_dma_top__DOT__u_mem__DOT__mem__v0 = 0;
    vlSelf->__VdlyDim0__tb_dma_top__DOT__u_mem__DOT__mem__v0 = 0;
    vlSelf->__VdlySet__tb_dma_top__DOT__u_mem__DOT__mem__v0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_dma_top__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_dma_top__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
