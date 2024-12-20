// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dma_top.h for the primary calling header

#include "Vtb_dma_top__pch.h"

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*12:0*/ __Vdly__rd_rem;
    __Vdly__rd_rem = 0;
    IData/*31:0*/ __Vdly__wr_ptr;
    __Vdly__wr_ptr = 0;
    CData/*3:0*/ __Vdly__wcnt;
    __Vdly__wcnt = 0;
    // Body
    vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = vlSelfRef.__PVT__u_fifo__DOT__wr_ptr;
    vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = vlSelfRef.__PVT__u_fifo__DOT__rd_ptr;
    vlSelfRef.__Vdly__desc[0U] = vlSelfRef.__PVT__desc[0U];
    vlSelfRef.__Vdly__desc[1U] = vlSelfRef.__PVT__desc[1U];
    vlSelfRef.__Vdly__desc[2U] = vlSelfRef.__PVT__desc[2U];
    vlSelfRef.__Vdly__desc[3U] = vlSelfRef.__PVT__desc[3U];
    __Vdly__rd_rem = vlSelfRef.__PVT__rd_rem;
    vlSelfRef.__Vdly__state = vlSelfRef.__PVT__state;
    __Vdly__wr_ptr = vlSelfRef.__PVT__wr_ptr;
    __Vdly__wcnt = vlSelfRef.__PVT__wcnt;
    vlSelfRef.__Vdly__wr_rem = vlSelfRef.__PVT__wr_rem;
    vlSelfRef.__Vdly__wstate = vlSelfRef.__PVT__wstate;
    if (vlSymsp->TOP.tb_dma_top__DOT__rst_n) {
        if (vlSelfRef.__PVT__u_fifo__DOT__do_push) {
            vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = 
                (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr)));
        }
        if (((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_beat) 
             & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))) {
            vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = 
                (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
        }
        if (((3U == (IData)(vlSelfRef.__PVT__state)) 
             & (IData)(vlSelfRef.__PVT__desc_ok))) {
            __Vdly__wr_ptr = vlSelfRef.__PVT__desc[1U];
            vlSelfRef.__Vdly__wr_rem = (0x00001fffU 
                                        & (vlSelfRef.__PVT__desc[2U] 
                                           >> 3U));
        }
        if ((0U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((((IData)(vlSelfRef.__PVT__desc_active) 
                  & (0U != (IData)(vlSelfRef.__PVT__wr_rem))) 
                 & ((IData)(vlSelfRef.__PVT__f_used) 
                    >= (IData)(vlSelfRef.wr_len)))) {
                vlSelfRef.__Vdly__wstate = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((1U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_ack))) {
                __Vdly__wcnt = 0U;
                vlSelfRef.__Vdly__wstate = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((1U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_beat))) {
                if (vlSelfRef.wr_data_last) {
                    __Vdly__wr_ptr = (vlSelfRef.__PVT__wr_ptr 
                                      + ((IData)(vlSelfRef.wr_len) 
                                         << 3U));
                    vlSelfRef.__Vdly__wr_rem = (0x00001fffU 
                                                & ((IData)(vlSelfRef.__PVT__wr_rem) 
                                                   - (IData)(vlSelfRef.wr_len)));
                    vlSelfRef.__Vdly__wstate = 0U;
                } else {
                    __Vdly__wcnt = (0x0000000fU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.__PVT__wcnt)));
                }
            }
        } else {
            vlSelfRef.__Vdly__wstate = 0U;
        }
        if ((4U & (IData)(vlSelfRef.__PVT__state))) {
            if ((2U & (IData)(vlSelfRef.__PVT__state))) {
                if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                    vlSelfRef.__PVT__desc_active = 0U;
                    vlSelfRef.__Vdly__state = 0U;
                } else if (((0U == (IData)(vlSelfRef.__PVT__wr_rem)) 
                            & (0U == (IData)(vlSelfRef.__PVT__wstate)))) {
                    vlSelfRef.__PVT__desc_active = 0U;
                    if ((0x00040000U & vlSelfRef.__PVT__desc[2U])) {
                        vlSelfRef.__Vdly__state = 0U;
                    } else {
                        vlSelfRef.__PVT__desc_addr 
                            = vlSelfRef.__PVT__desc[3U];
                        vlSelfRef.__Vdly__state = (
                                                   (0U 
                                                    != 
                                                    (0x0000000fU 
                                                     & vlSelfRef.__PVT__desc[3U]))
                                                    ? 7U
                                                    : 1U);
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                if (((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid) 
                     & (IData)(vlSymsp->TOP.tb_dma_top__DOT__rd_last))) {
                    vlSelfRef.__PVT__rd_ptr = (vlSelfRef.__PVT__rd_ptr 
                                               + ((IData)(vlSelfRef.__PVT__rd_burst) 
                                                  << 3U));
                    __Vdly__rd_rem = (0x00001fffU & 
                                      ((IData)(vlSelfRef.__PVT__rd_rem) 
                                       - (IData)(vlSelfRef.__PVT__rd_burst)));
                    vlSelfRef.__Vdly__state = 4U;
                }
            } else if ((0U == (IData)(vlSelfRef.__PVT__rd_rem))) {
                vlSelfRef.__Vdly__state = 6U;
            } else if ((1U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_ack))) {
                vlSelfRef.__Vdly__state = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.__PVT__state))) {
            if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                if (vlSelfRef.__PVT__desc_ok) {
                    vlSelfRef.__PVT__rd_ptr = vlSelfRef.__PVT__desc[0U];
                    __Vdly__rd_rem = (0x00001fffU & 
                                      (vlSelfRef.__PVT__desc[2U] 
                                       >> 3U));
                    vlSelfRef.__PVT__desc_active = 1U;
                    vlSelfRef.__Vdly__state = 4U;
                } else {
                    vlSelfRef.__Vdly__state = 7U;
                }
            } else if ((1U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid))) {
                if (vlSymsp->TOP.tb_dma_top__DOT__rd_last) {
                    vlSelfRef.__Vdly__desc[0U] = (IData)(vlSelfRef.__PVT__desc_lo);
                    vlSelfRef.__Vdly__desc[1U] = (IData)(
                                                         (vlSelfRef.__PVT__desc_lo 
                                                          >> 0x00000020U));
                    vlSelfRef.__Vdly__desc[2U] = (IData)(vlSymsp->TOP.tb_dma_top__DOT__rd_data);
                    vlSelfRef.__Vdly__desc[3U] = (IData)(
                                                         (vlSymsp->TOP.tb_dma_top__DOT__rd_data 
                                                          >> 0x00000020U));
                    vlSelfRef.__Vdly__state = 3U;
                } else {
                    vlSelfRef.__PVT__desc_lo = vlSymsp->TOP.tb_dma_top__DOT__rd_data;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__PVT__state))) {
            if ((1U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_ack))) {
                vlSelfRef.__Vdly__state = 2U;
            }
        } else if ((1U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__start))) {
            vlSelfRef.__PVT__desc_addr = vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__desc_ptr[0U];
            vlSelfRef.__Vdly__state = ((0U != (0x0000000fU 
                                               & vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__desc_ptr[0U]))
                                        ? 7U : 1U);
        }
    } else {
        vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = 0U;
        vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = 0U;
        __Vdly__wr_ptr = 0U;
        vlSelfRef.__Vdly__wr_rem = 0U;
        vlSelfRef.__Vdly__wstate = 0U;
        __Vdly__wcnt = 0U;
        vlSelfRef.__PVT__rd_ptr = 0U;
        __Vdly__rd_rem = 0U;
        vlSelfRef.__Vdly__state = 0U;
        vlSelfRef.__PVT__desc_addr = 0U;
        vlSelfRef.__PVT__desc_lo = 0ULL;
        vlSelfRef.__Vdly__desc[0U] = 0U;
        vlSelfRef.__Vdly__desc[1U] = 0U;
        vlSelfRef.__Vdly__desc[2U] = 0U;
        vlSelfRef.__Vdly__desc[3U] = 0U;
        vlSelfRef.__PVT__desc_active = 0U;
    }
    vlSelfRef.__PVT__wr_ptr = __Vdly__wr_ptr;
    vlSelfRef.__PVT__wcnt = __Vdly__wcnt;
    vlSelfRef.__PVT__rd_rem = __Vdly__rd_rem;
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__1(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__1\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__rd_ptr = vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr;
    vlSelfRef.__PVT__wr_rem = vlSelfRef.__Vdly__wr_rem;
    vlSelfRef.__PVT__wstate = vlSelfRef.__Vdly__wstate;
    vlSelfRef.__PVT__desc[0U] = vlSelfRef.__Vdly__desc[0U];
    vlSelfRef.__PVT__desc[1U] = vlSelfRef.__Vdly__desc[1U];
    vlSelfRef.__PVT__desc[2U] = vlSelfRef.__Vdly__desc[2U];
    vlSelfRef.__PVT__desc[3U] = vlSelfRef.__Vdly__desc[3U];
    vlSelfRef.__PVT__state = vlSelfRef.__Vdly__state;
    vlSelfRef.__PVT__desc_ok = ((0U != (0x0000ffffU 
                                        & vlSelfRef.__PVT__desc[2U])) 
                                & ((0U == (7U & vlSelfRef.__PVT__desc[2U])) 
                                   & ((0U == (7U & vlSelfRef.__PVT__desc[0U])) 
                                      & (0U == (7U 
                                                & vlSelfRef.__PVT__desc[1U])))));
    vlSelfRef.wr_len = (0x0000000fU & (((IData)(vlSelfRef.__PVT__wr_rem) 
                                        < (0x0000000fU 
                                           & ((IData)(1U) 
                                              << (3U 
                                                  & (vlSelfRef.__PVT__desc[2U] 
                                                     >> 0x00000010U)))))
                                        ? (IData)(vlSelfRef.__PVT__wr_rem)
                                        : ((IData)(1U) 
                                           << (3U & 
                                               (vlSelfRef.__PVT__desc[2U] 
                                                >> 0x00000010U)))));
    vlSelfRef.__PVT__rd_burst = (0x0000000fU & (((IData)(vlSelfRef.__PVT__rd_rem) 
                                                 < 
                                                 (0x0000000fU 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (3U 
                                                      & (vlSelfRef.__PVT__desc[2U] 
                                                         >> 0x00000010U)))))
                                                 ? (IData)(vlSelfRef.__PVT__rd_rem)
                                                 : 
                                                ((IData)(1U) 
                                                 << 
                                                 (3U 
                                                  & (vlSelfRef.__PVT__desc[2U] 
                                                     >> 0x00000010U)))));
    vlSelfRef.wr_data_last = ((IData)(vlSelfRef.__PVT__wcnt) 
                              == (0x0000000fU & ((IData)(vlSelfRef.wr_len) 
                                                 - (IData)(1U))));
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__2(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__2\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*63:0*/ __VdlyVal__u_fifo__DOT__mem__v0;
    __VdlyVal__u_fifo__DOT__mem__v0 = 0;
    CData/*2:0*/ __VdlyDim0__u_fifo__DOT__mem__v0;
    __VdlyDim0__u_fifo__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__u_fifo__DOT__mem__v0;
    __VdlySet__u_fifo__DOT__mem__v0 = 0;
    // Body
    __VdlySet__u_fifo__DOT__mem__v0 = 0U;
    if (vlSelfRef.__PVT__u_fifo__DOT__do_push) {
        __VdlyVal__u_fifo__DOT__mem__v0 = vlSymsp->TOP.tb_dma_top__DOT__rd_data;
        __VdlyDim0__u_fifo__DOT__mem__v0 = (7U & (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr));
        __VdlySet__u_fifo__DOT__mem__v0 = 1U;
    }
    if (__VdlySet__u_fifo__DOT__mem__v0) {
        vlSelfRef.__PVT__u_fifo__DOT__mem[__VdlyDim0__u_fifo__DOT__mem__v0] 
            = __VdlyVal__u_fifo__DOT__mem__v0;
    }
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__3(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__3\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__wr_ptr = vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                != (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr));
    vlSelfRef.__PVT__f_used = (0x0000000fU & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                              - (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__4(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__4\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__do_push = ((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid) 
                                             & ((~ 
                                                 (((1U 
                                                    & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                       >> 3U)) 
                                                   != 
                                                   (1U 
                                                    & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr) 
                                                       >> 3U))) 
                                                  & ((7U 
                                                      & (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr)) 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr))))) 
                                                & (5U 
                                                   == (IData)(vlSelfRef.__PVT__state))));
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*12:0*/ __Vdly__rd_rem;
    __Vdly__rd_rem = 0;
    IData/*31:0*/ __Vdly__wr_ptr;
    __Vdly__wr_ptr = 0;
    CData/*3:0*/ __Vdly__wcnt;
    __Vdly__wcnt = 0;
    // Body
    vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = vlSelfRef.__PVT__u_fifo__DOT__wr_ptr;
    vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = vlSelfRef.__PVT__u_fifo__DOT__rd_ptr;
    vlSelfRef.__Vdly__desc[0U] = vlSelfRef.__PVT__desc[0U];
    vlSelfRef.__Vdly__desc[1U] = vlSelfRef.__PVT__desc[1U];
    vlSelfRef.__Vdly__desc[2U] = vlSelfRef.__PVT__desc[2U];
    vlSelfRef.__Vdly__desc[3U] = vlSelfRef.__PVT__desc[3U];
    __Vdly__rd_rem = vlSelfRef.__PVT__rd_rem;
    vlSelfRef.__Vdly__state = vlSelfRef.__PVT__state;
    __Vdly__wr_ptr = vlSelfRef.__PVT__wr_ptr;
    __Vdly__wcnt = vlSelfRef.__PVT__wcnt;
    vlSelfRef.__Vdly__wr_rem = vlSelfRef.__PVT__wr_rem;
    vlSelfRef.__Vdly__wstate = vlSelfRef.__PVT__wstate;
    if (vlSymsp->TOP.tb_dma_top__DOT__rst_n) {
        if (vlSelfRef.__PVT__u_fifo__DOT__do_push) {
            vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = 
                (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr)));
        }
        if ((((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_beat) 
              >> 1U) & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))) {
            vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = 
                (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
        }
        if (((3U == (IData)(vlSelfRef.__PVT__state)) 
             & (IData)(vlSelfRef.__PVT__desc_ok))) {
            __Vdly__wr_ptr = vlSelfRef.__PVT__desc[1U];
            vlSelfRef.__Vdly__wr_rem = (0x00001fffU 
                                        & (vlSelfRef.__PVT__desc[2U] 
                                           >> 3U));
        }
        if ((0U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((((IData)(vlSelfRef.__PVT__desc_active) 
                  & (0U != (IData)(vlSelfRef.__PVT__wr_rem))) 
                 & ((IData)(vlSelfRef.__PVT__f_used) 
                    >= (IData)(vlSelfRef.wr_len)))) {
                vlSelfRef.__Vdly__wstate = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((2U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_ack))) {
                __Vdly__wcnt = 0U;
                vlSelfRef.__Vdly__wstate = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((2U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_beat))) {
                if (vlSelfRef.wr_data_last) {
                    __Vdly__wr_ptr = (vlSelfRef.__PVT__wr_ptr 
                                      + ((IData)(vlSelfRef.wr_len) 
                                         << 3U));
                    vlSelfRef.__Vdly__wr_rem = (0x00001fffU 
                                                & ((IData)(vlSelfRef.__PVT__wr_rem) 
                                                   - (IData)(vlSelfRef.wr_len)));
                    vlSelfRef.__Vdly__wstate = 0U;
                } else {
                    __Vdly__wcnt = (0x0000000fU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.__PVT__wcnt)));
                }
            }
        } else {
            vlSelfRef.__Vdly__wstate = 0U;
        }
        if ((4U & (IData)(vlSelfRef.__PVT__state))) {
            if ((2U & (IData)(vlSelfRef.__PVT__state))) {
                if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                    vlSelfRef.__PVT__desc_active = 0U;
                    vlSelfRef.__Vdly__state = 0U;
                } else if (((0U == (IData)(vlSelfRef.__PVT__wr_rem)) 
                            & (0U == (IData)(vlSelfRef.__PVT__wstate)))) {
                    vlSelfRef.__PVT__desc_active = 0U;
                    if ((0x00040000U & vlSelfRef.__PVT__desc[2U])) {
                        vlSelfRef.__Vdly__state = 0U;
                    } else {
                        vlSelfRef.__PVT__desc_addr 
                            = vlSelfRef.__PVT__desc[3U];
                        vlSelfRef.__Vdly__state = (
                                                   (0U 
                                                    != 
                                                    (0x0000000fU 
                                                     & vlSelfRef.__PVT__desc[3U]))
                                                    ? 7U
                                                    : 1U);
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                if ((((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid) 
                      >> 1U) & (IData)(vlSymsp->TOP.tb_dma_top__DOT__rd_last))) {
                    vlSelfRef.__PVT__rd_ptr = (vlSelfRef.__PVT__rd_ptr 
                                               + ((IData)(vlSelfRef.__PVT__rd_burst) 
                                                  << 3U));
                    __Vdly__rd_rem = (0x00001fffU & 
                                      ((IData)(vlSelfRef.__PVT__rd_rem) 
                                       - (IData)(vlSelfRef.__PVT__rd_burst)));
                    vlSelfRef.__Vdly__state = 4U;
                }
            } else if ((0U == (IData)(vlSelfRef.__PVT__rd_rem))) {
                vlSelfRef.__Vdly__state = 6U;
            } else if ((2U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_ack))) {
                vlSelfRef.__Vdly__state = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.__PVT__state))) {
            if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                if (vlSelfRef.__PVT__desc_ok) {
                    vlSelfRef.__PVT__rd_ptr = vlSelfRef.__PVT__desc[0U];
                    __Vdly__rd_rem = (0x00001fffU & 
                                      (vlSelfRef.__PVT__desc[2U] 
                                       >> 3U));
                    vlSelfRef.__PVT__desc_active = 1U;
                    vlSelfRef.__Vdly__state = 4U;
                } else {
                    vlSelfRef.__Vdly__state = 7U;
                }
            } else if ((2U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid))) {
                if (vlSymsp->TOP.tb_dma_top__DOT__rd_last) {
                    vlSelfRef.__Vdly__desc[0U] = (IData)(vlSelfRef.__PVT__desc_lo);
                    vlSelfRef.__Vdly__desc[1U] = (IData)(
                                                         (vlSelfRef.__PVT__desc_lo 
                                                          >> 0x00000020U));
                    vlSelfRef.__Vdly__desc[2U] = (IData)(vlSymsp->TOP.tb_dma_top__DOT__rd_data);
                    vlSelfRef.__Vdly__desc[3U] = (IData)(
                                                         (vlSymsp->TOP.tb_dma_top__DOT__rd_data 
                                                          >> 0x00000020U));
                    vlSelfRef.__Vdly__state = 3U;
                } else {
                    vlSelfRef.__PVT__desc_lo = vlSymsp->TOP.tb_dma_top__DOT__rd_data;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__PVT__state))) {
            if ((2U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_ack))) {
                vlSelfRef.__Vdly__state = 2U;
            }
        } else if ((2U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__start))) {
            vlSelfRef.__PVT__desc_addr = vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__desc_ptr[1U];
            vlSelfRef.__Vdly__state = ((0U != (0x0000000fU 
                                               & vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__desc_ptr[1U]))
                                        ? 7U : 1U);
        }
    } else {
        vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = 0U;
        vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = 0U;
        __Vdly__wr_ptr = 0U;
        vlSelfRef.__Vdly__wr_rem = 0U;
        vlSelfRef.__Vdly__wstate = 0U;
        __Vdly__wcnt = 0U;
        vlSelfRef.__PVT__rd_ptr = 0U;
        __Vdly__rd_rem = 0U;
        vlSelfRef.__Vdly__state = 0U;
        vlSelfRef.__PVT__desc_addr = 0U;
        vlSelfRef.__PVT__desc_lo = 0ULL;
        vlSelfRef.__Vdly__desc[0U] = 0U;
        vlSelfRef.__Vdly__desc[1U] = 0U;
        vlSelfRef.__Vdly__desc[2U] = 0U;
        vlSelfRef.__Vdly__desc[3U] = 0U;
        vlSelfRef.__PVT__desc_active = 0U;
    }
    vlSelfRef.__PVT__wr_ptr = __Vdly__wr_ptr;
    vlSelfRef.__PVT__wcnt = __Vdly__wcnt;
    vlSelfRef.__PVT__rd_rem = __Vdly__rd_rem;
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__3(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__3\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__wr_ptr = vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                != (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr));
    vlSelfRef.__PVT__f_used = (0x0000000fU & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                              - (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__4(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__4\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__do_push = (((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid) 
                                              >> 1U) 
                                             & ((~ 
                                                 (((1U 
                                                    & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                       >> 3U)) 
                                                   != 
                                                   (1U 
                                                    & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr) 
                                                       >> 3U))) 
                                                  & ((7U 
                                                      & (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr)) 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr))))) 
                                                & (5U 
                                                   == (IData)(vlSelfRef.__PVT__state))));
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*12:0*/ __Vdly__rd_rem;
    __Vdly__rd_rem = 0;
    IData/*31:0*/ __Vdly__wr_ptr;
    __Vdly__wr_ptr = 0;
    CData/*3:0*/ __Vdly__wcnt;
    __Vdly__wcnt = 0;
    // Body
    vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = vlSelfRef.__PVT__u_fifo__DOT__wr_ptr;
    vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = vlSelfRef.__PVT__u_fifo__DOT__rd_ptr;
    vlSelfRef.__Vdly__desc[0U] = vlSelfRef.__PVT__desc[0U];
    vlSelfRef.__Vdly__desc[1U] = vlSelfRef.__PVT__desc[1U];
    vlSelfRef.__Vdly__desc[2U] = vlSelfRef.__PVT__desc[2U];
    vlSelfRef.__Vdly__desc[3U] = vlSelfRef.__PVT__desc[3U];
    __Vdly__rd_rem = vlSelfRef.__PVT__rd_rem;
    vlSelfRef.__Vdly__state = vlSelfRef.__PVT__state;
    __Vdly__wr_ptr = vlSelfRef.__PVT__wr_ptr;
    __Vdly__wcnt = vlSelfRef.__PVT__wcnt;
    vlSelfRef.__Vdly__wr_rem = vlSelfRef.__PVT__wr_rem;
    vlSelfRef.__Vdly__wstate = vlSelfRef.__PVT__wstate;
    if (vlSymsp->TOP.tb_dma_top__DOT__rst_n) {
        if (vlSelfRef.__PVT__u_fifo__DOT__do_push) {
            vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = 
                (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr)));
        }
        if ((((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_beat) 
              >> 2U) & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))) {
            vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = 
                (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
        }
        if (((3U == (IData)(vlSelfRef.__PVT__state)) 
             & (IData)(vlSelfRef.__PVT__desc_ok))) {
            __Vdly__wr_ptr = vlSelfRef.__PVT__desc[1U];
            vlSelfRef.__Vdly__wr_rem = (0x00001fffU 
                                        & (vlSelfRef.__PVT__desc[2U] 
                                           >> 3U));
        }
        if ((0U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((((IData)(vlSelfRef.__PVT__desc_active) 
                  & (0U != (IData)(vlSelfRef.__PVT__wr_rem))) 
                 & ((IData)(vlSelfRef.__PVT__f_used) 
                    >= (IData)(vlSelfRef.wr_len)))) {
                vlSelfRef.__Vdly__wstate = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((4U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_ack))) {
                __Vdly__wcnt = 0U;
                vlSelfRef.__Vdly__wstate = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((4U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_beat))) {
                if (vlSelfRef.wr_data_last) {
                    __Vdly__wr_ptr = (vlSelfRef.__PVT__wr_ptr 
                                      + ((IData)(vlSelfRef.wr_len) 
                                         << 3U));
                    vlSelfRef.__Vdly__wr_rem = (0x00001fffU 
                                                & ((IData)(vlSelfRef.__PVT__wr_rem) 
                                                   - (IData)(vlSelfRef.wr_len)));
                    vlSelfRef.__Vdly__wstate = 0U;
                } else {
                    __Vdly__wcnt = (0x0000000fU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.__PVT__wcnt)));
                }
            }
        } else {
            vlSelfRef.__Vdly__wstate = 0U;
        }
        if ((4U & (IData)(vlSelfRef.__PVT__state))) {
            if ((2U & (IData)(vlSelfRef.__PVT__state))) {
                if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                    vlSelfRef.__PVT__desc_active = 0U;
                    vlSelfRef.__Vdly__state = 0U;
                } else if (((0U == (IData)(vlSelfRef.__PVT__wr_rem)) 
                            & (0U == (IData)(vlSelfRef.__PVT__wstate)))) {
                    vlSelfRef.__PVT__desc_active = 0U;
                    if ((0x00040000U & vlSelfRef.__PVT__desc[2U])) {
                        vlSelfRef.__Vdly__state = 0U;
                    } else {
                        vlSelfRef.__PVT__desc_addr 
                            = vlSelfRef.__PVT__desc[3U];
                        vlSelfRef.__Vdly__state = (
                                                   (0U 
                                                    != 
                                                    (0x0000000fU 
                                                     & vlSelfRef.__PVT__desc[3U]))
                                                    ? 7U
                                                    : 1U);
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                if ((((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid) 
                      >> 2U) & (IData)(vlSymsp->TOP.tb_dma_top__DOT__rd_last))) {
                    vlSelfRef.__PVT__rd_ptr = (vlSelfRef.__PVT__rd_ptr 
                                               + ((IData)(vlSelfRef.__PVT__rd_burst) 
                                                  << 3U));
                    __Vdly__rd_rem = (0x00001fffU & 
                                      ((IData)(vlSelfRef.__PVT__rd_rem) 
                                       - (IData)(vlSelfRef.__PVT__rd_burst)));
                    vlSelfRef.__Vdly__state = 4U;
                }
            } else if ((0U == (IData)(vlSelfRef.__PVT__rd_rem))) {
                vlSelfRef.__Vdly__state = 6U;
            } else if ((4U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_ack))) {
                vlSelfRef.__Vdly__state = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.__PVT__state))) {
            if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                if (vlSelfRef.__PVT__desc_ok) {
                    vlSelfRef.__PVT__rd_ptr = vlSelfRef.__PVT__desc[0U];
                    __Vdly__rd_rem = (0x00001fffU & 
                                      (vlSelfRef.__PVT__desc[2U] 
                                       >> 3U));
                    vlSelfRef.__PVT__desc_active = 1U;
                    vlSelfRef.__Vdly__state = 4U;
                } else {
                    vlSelfRef.__Vdly__state = 7U;
                }
            } else if ((4U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid))) {
                if (vlSymsp->TOP.tb_dma_top__DOT__rd_last) {
                    vlSelfRef.__Vdly__desc[0U] = (IData)(vlSelfRef.__PVT__desc_lo);
                    vlSelfRef.__Vdly__desc[1U] = (IData)(
                                                         (vlSelfRef.__PVT__desc_lo 
                                                          >> 0x00000020U));
                    vlSelfRef.__Vdly__desc[2U] = (IData)(vlSymsp->TOP.tb_dma_top__DOT__rd_data);
                    vlSelfRef.__Vdly__desc[3U] = (IData)(
                                                         (vlSymsp->TOP.tb_dma_top__DOT__rd_data 
                                                          >> 0x00000020U));
                    vlSelfRef.__Vdly__state = 3U;
                } else {
                    vlSelfRef.__PVT__desc_lo = vlSymsp->TOP.tb_dma_top__DOT__rd_data;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__PVT__state))) {
            if ((4U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_ack))) {
                vlSelfRef.__Vdly__state = 2U;
            }
        } else if ((4U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__start))) {
            vlSelfRef.__PVT__desc_addr = vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__desc_ptr[2U];
            vlSelfRef.__Vdly__state = ((0U != (0x0000000fU 
                                               & vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__desc_ptr[2U]))
                                        ? 7U : 1U);
        }
    } else {
        vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = 0U;
        vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = 0U;
        __Vdly__wr_ptr = 0U;
        vlSelfRef.__Vdly__wr_rem = 0U;
        vlSelfRef.__Vdly__wstate = 0U;
        __Vdly__wcnt = 0U;
        vlSelfRef.__PVT__rd_ptr = 0U;
        __Vdly__rd_rem = 0U;
        vlSelfRef.__Vdly__state = 0U;
        vlSelfRef.__PVT__desc_addr = 0U;
        vlSelfRef.__PVT__desc_lo = 0ULL;
        vlSelfRef.__Vdly__desc[0U] = 0U;
        vlSelfRef.__Vdly__desc[1U] = 0U;
        vlSelfRef.__Vdly__desc[2U] = 0U;
        vlSelfRef.__Vdly__desc[3U] = 0U;
        vlSelfRef.__PVT__desc_active = 0U;
    }
    vlSelfRef.__PVT__wr_ptr = __Vdly__wr_ptr;
    vlSelfRef.__PVT__wcnt = __Vdly__wcnt;
    vlSelfRef.__PVT__rd_rem = __Vdly__rd_rem;
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__3(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__3\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__wr_ptr = vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                != (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr));
    vlSelfRef.__PVT__f_used = (0x0000000fU & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                              - (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__4(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__4\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__do_push = (((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid) 
                                              >> 2U) 
                                             & ((~ 
                                                 (((1U 
                                                    & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                       >> 3U)) 
                                                   != 
                                                   (1U 
                                                    & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr) 
                                                       >> 3U))) 
                                                  & ((7U 
                                                      & (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr)) 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr))))) 
                                                & (5U 
                                                   == (IData)(vlSelfRef.__PVT__state))));
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*12:0*/ __Vdly__rd_rem;
    __Vdly__rd_rem = 0;
    IData/*31:0*/ __Vdly__wr_ptr;
    __Vdly__wr_ptr = 0;
    CData/*3:0*/ __Vdly__wcnt;
    __Vdly__wcnt = 0;
    // Body
    vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = vlSelfRef.__PVT__u_fifo__DOT__wr_ptr;
    vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = vlSelfRef.__PVT__u_fifo__DOT__rd_ptr;
    vlSelfRef.__Vdly__desc[0U] = vlSelfRef.__PVT__desc[0U];
    vlSelfRef.__Vdly__desc[1U] = vlSelfRef.__PVT__desc[1U];
    vlSelfRef.__Vdly__desc[2U] = vlSelfRef.__PVT__desc[2U];
    vlSelfRef.__Vdly__desc[3U] = vlSelfRef.__PVT__desc[3U];
    __Vdly__rd_rem = vlSelfRef.__PVT__rd_rem;
    vlSelfRef.__Vdly__state = vlSelfRef.__PVT__state;
    __Vdly__wr_ptr = vlSelfRef.__PVT__wr_ptr;
    __Vdly__wcnt = vlSelfRef.__PVT__wcnt;
    vlSelfRef.__Vdly__wr_rem = vlSelfRef.__PVT__wr_rem;
    vlSelfRef.__Vdly__wstate = vlSelfRef.__PVT__wstate;
    if (vlSymsp->TOP.tb_dma_top__DOT__rst_n) {
        if (vlSelfRef.__PVT__u_fifo__DOT__do_push) {
            vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = 
                (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr)));
        }
        if ((((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_beat) 
              >> 3U) & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))) {
            vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = 
                (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
        }
        if (((3U == (IData)(vlSelfRef.__PVT__state)) 
             & (IData)(vlSelfRef.__PVT__desc_ok))) {
            __Vdly__wr_ptr = vlSelfRef.__PVT__desc[1U];
            vlSelfRef.__Vdly__wr_rem = (0x00001fffU 
                                        & (vlSelfRef.__PVT__desc[2U] 
                                           >> 3U));
        }
        if ((0U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((((IData)(vlSelfRef.__PVT__desc_active) 
                  & (0U != (IData)(vlSelfRef.__PVT__wr_rem))) 
                 & ((IData)(vlSelfRef.__PVT__f_used) 
                    >= (IData)(vlSelfRef.wr_len)))) {
                vlSelfRef.__Vdly__wstate = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((8U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_ack))) {
                __Vdly__wcnt = 0U;
                vlSelfRef.__Vdly__wstate = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__wstate))) {
            if ((8U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_wr_beat))) {
                if (vlSelfRef.wr_data_last) {
                    __Vdly__wr_ptr = (vlSelfRef.__PVT__wr_ptr 
                                      + ((IData)(vlSelfRef.wr_len) 
                                         << 3U));
                    vlSelfRef.__Vdly__wr_rem = (0x00001fffU 
                                                & ((IData)(vlSelfRef.__PVT__wr_rem) 
                                                   - (IData)(vlSelfRef.wr_len)));
                    vlSelfRef.__Vdly__wstate = 0U;
                } else {
                    __Vdly__wcnt = (0x0000000fU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.__PVT__wcnt)));
                }
            }
        } else {
            vlSelfRef.__Vdly__wstate = 0U;
        }
        if ((4U & (IData)(vlSelfRef.__PVT__state))) {
            if ((2U & (IData)(vlSelfRef.__PVT__state))) {
                if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                    vlSelfRef.__PVT__desc_active = 0U;
                    vlSelfRef.__Vdly__state = 0U;
                } else if (((0U == (IData)(vlSelfRef.__PVT__wr_rem)) 
                            & (0U == (IData)(vlSelfRef.__PVT__wstate)))) {
                    vlSelfRef.__PVT__desc_active = 0U;
                    if ((0x00040000U & vlSelfRef.__PVT__desc[2U])) {
                        vlSelfRef.__Vdly__state = 0U;
                    } else {
                        vlSelfRef.__PVT__desc_addr 
                            = vlSelfRef.__PVT__desc[3U];
                        vlSelfRef.__Vdly__state = (
                                                   (0U 
                                                    != 
                                                    (0x0000000fU 
                                                     & vlSelfRef.__PVT__desc[3U]))
                                                    ? 7U
                                                    : 1U);
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                if ((((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid) 
                      >> 3U) & (IData)(vlSymsp->TOP.tb_dma_top__DOT__rd_last))) {
                    vlSelfRef.__PVT__rd_ptr = (vlSelfRef.__PVT__rd_ptr 
                                               + ((IData)(vlSelfRef.__PVT__rd_burst) 
                                                  << 3U));
                    __Vdly__rd_rem = (0x00001fffU & 
                                      ((IData)(vlSelfRef.__PVT__rd_rem) 
                                       - (IData)(vlSelfRef.__PVT__rd_burst)));
                    vlSelfRef.__Vdly__state = 4U;
                }
            } else if ((0U == (IData)(vlSelfRef.__PVT__rd_rem))) {
                vlSelfRef.__Vdly__state = 6U;
            } else if ((8U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_ack))) {
                vlSelfRef.__Vdly__state = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.__PVT__state))) {
            if ((1U & (IData)(vlSelfRef.__PVT__state))) {
                if (vlSelfRef.__PVT__desc_ok) {
                    vlSelfRef.__PVT__rd_ptr = vlSelfRef.__PVT__desc[0U];
                    __Vdly__rd_rem = (0x00001fffU & 
                                      (vlSelfRef.__PVT__desc[2U] 
                                       >> 3U));
                    vlSelfRef.__PVT__desc_active = 1U;
                    vlSelfRef.__Vdly__state = 4U;
                } else {
                    vlSelfRef.__Vdly__state = 7U;
                }
            } else if ((8U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid))) {
                if (vlSymsp->TOP.tb_dma_top__DOT__rd_last) {
                    vlSelfRef.__Vdly__desc[0U] = (IData)(vlSelfRef.__PVT__desc_lo);
                    vlSelfRef.__Vdly__desc[1U] = (IData)(
                                                         (vlSelfRef.__PVT__desc_lo 
                                                          >> 0x00000020U));
                    vlSelfRef.__Vdly__desc[2U] = (IData)(vlSymsp->TOP.tb_dma_top__DOT__rd_data);
                    vlSelfRef.__Vdly__desc[3U] = (IData)(
                                                         (vlSymsp->TOP.tb_dma_top__DOT__rd_data 
                                                          >> 0x00000020U));
                    vlSelfRef.__Vdly__state = 3U;
                } else {
                    vlSelfRef.__PVT__desc_lo = vlSymsp->TOP.tb_dma_top__DOT__rd_data;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__PVT__state))) {
            if ((8U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_ack))) {
                vlSelfRef.__Vdly__state = 2U;
            }
        } else if ((8U & (IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__start))) {
            vlSelfRef.__PVT__desc_addr = vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__desc_ptr[3U];
            vlSelfRef.__Vdly__state = ((0U != (0x0000000fU 
                                               & vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__desc_ptr[3U]))
                                        ? 7U : 1U);
        }
    } else {
        vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr = 0U;
        vlSelfRef.__Vdly__u_fifo__DOT__rd_ptr = 0U;
        __Vdly__wr_ptr = 0U;
        vlSelfRef.__Vdly__wr_rem = 0U;
        vlSelfRef.__Vdly__wstate = 0U;
        __Vdly__wcnt = 0U;
        vlSelfRef.__PVT__rd_ptr = 0U;
        __Vdly__rd_rem = 0U;
        vlSelfRef.__Vdly__state = 0U;
        vlSelfRef.__PVT__desc_addr = 0U;
        vlSelfRef.__PVT__desc_lo = 0ULL;
        vlSelfRef.__Vdly__desc[0U] = 0U;
        vlSelfRef.__Vdly__desc[1U] = 0U;
        vlSelfRef.__Vdly__desc[2U] = 0U;
        vlSelfRef.__Vdly__desc[3U] = 0U;
        vlSelfRef.__PVT__desc_active = 0U;
    }
    vlSelfRef.__PVT__wr_ptr = __Vdly__wr_ptr;
    vlSelfRef.__PVT__wcnt = __Vdly__wcnt;
    vlSelfRef.__PVT__rd_rem = __Vdly__rd_rem;
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__3(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__3\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__wr_ptr = vlSelfRef.__Vdly__u_fifo__DOT__wr_ptr;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4 = ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                != (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr));
    vlSelfRef.__PVT__f_used = (0x0000000fU & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                              - (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
}

void Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__4(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___nba_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__4\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_fifo__DOT__do_push = (((IData)(vlSymsp->TOP.tb_dma_top__DOT__dut__DOT__c_rd_valid) 
                                              >> 3U) 
                                             & ((~ 
                                                 (((1U 
                                                    & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                       >> 3U)) 
                                                   != 
                                                   (1U 
                                                    & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr) 
                                                       >> 3U))) 
                                                  & ((7U 
                                                      & (IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr)) 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr))))) 
                                                & (5U 
                                                   == (IData)(vlSelfRef.__PVT__state))));
}
