// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_dma_top.h for the primary calling header

#include "Vtb_dma_top__pch.h"

VL_ATTR_COLD void Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                != (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr));
    vlSelfRef.__PVT__f_used = (0x0000000fU & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                              - (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
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

VL_ATTR_COLD void Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                != (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr));
    vlSelfRef.__PVT__f_used = (0x0000000fU & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                              - (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
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

VL_ATTR_COLD void Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                != (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr));
    vlSelfRef.__PVT__f_used = (0x0000000fU & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                              - (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
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

VL_ATTR_COLD void Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__0(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___stl_sequent__TOP__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch__0\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4 = ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                                != (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr));
    vlSelfRef.__PVT__f_used = (0x0000000fU & ((IData)(vlSelfRef.__PVT__u_fifo__DOT__wr_ptr) 
                                              - (IData)(vlSelfRef.__PVT__u_fifo__DOT__rd_ptr)));
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

VL_ATTR_COLD void Vtb_dma_top_dma_channel___ctor_var_reset(Vtb_dma_top_dma_channel* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_dma_top_dma_channel___ctor_var_reset\n"); );
    Vtb_dma_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->desc_ptr_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4110309435942311655ull);
    vlSelf->busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6386567572483775230ull);
    vlSelf->done_evt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15212261262841999586ull);
    vlSelf->err_evt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8672234052930424789ull);
    vlSelf->rd_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8855675061116762241ull);
    vlSelf->rd_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7950012703377089919ull);
    vlSelf->rd_len = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11017455776226519632ull);
    vlSelf->rd_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12140461203557527735ull);
    vlSelf->rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1884875144532392565ull);
    vlSelf->rd_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17824471296722538975ull);
    vlSelf->rd_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16704583667377528919ull);
    vlSelf->wr_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2480232592294068587ull);
    vlSelf->wr_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10458723662394441575ull);
    vlSelf->wr_len = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7590815035100596504ull);
    vlSelf->wr_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8966074053183106177ull);
    vlSelf->wr_data_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1205664041844020279ull);
    vlSelf->wr_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12812822527505751231ull);
    vlSelf->wr_data_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13338934679801278356ull);
    vlSelf->wr_beat = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10507216635217163794ull);
    vlSelf->__PVT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9404372463396948974ull);
    vlSelf->__PVT__wstate = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14116570300487947195ull);
    vlSelf->__PVT__desc_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11694056886397644814ull);
    vlSelf->__PVT__desc_lo = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16930064644559792403ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__PVT__desc, __VscopeHash, 3518590697625020873ull);
    vlSelf->__PVT__desc_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13861407501522166462ull);
    vlSelf->__PVT__rd_ptr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8582113012353463185ull);
    vlSelf->__PVT__wr_ptr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12436053222651956031ull);
    vlSelf->__PVT__rd_rem = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 8736661208398809808ull);
    vlSelf->__PVT__wr_rem = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 10973004752166322747ull);
    vlSelf->__PVT__wcnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3123973083424779920ull);
    vlSelf->__PVT__f_used = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9934954943248401198ull);
    vlSelf->__PVT__rd_burst = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12968466181349637911ull);
    vlSelf->__PVT__desc_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3222671465251331426ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__u_fifo__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5616501622472368203ull);
    }
    vlSelf->__PVT__u_fifo__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1340694319711768522ull);
    vlSelf->__PVT__u_fifo__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5918169777023352860ull);
    vlSelf->__PVT__u_fifo__DOT__do_push = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9842226943729752555ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_1 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_2 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_3 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_4 = 0;
    vlSelf->__Vdly__state = 0;
    VL_ZERO_RESET_W(128, vlSelf->__Vdly__desc);
    vlSelf->__Vdly__wr_rem = 0;
    vlSelf->__Vdly__wstate = 0;
    vlSelf->__Vdly__u_fifo__DOT__wr_ptr = 0;
    vlSelf->__Vdly__u_fifo__DOT__rd_ptr = 0;
}
