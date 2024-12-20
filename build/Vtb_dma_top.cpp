// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_dma_top__pch.h"

//============================================================
// Constructors

Vtb_dma_top::Vtb_dma_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_dma_top__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , __PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch{vlSymsp->TOP.__PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__0__KET____DOT__u_ch}
    , __PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch{vlSymsp->TOP.__PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__1__KET____DOT__u_ch}
    , __PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch{vlSymsp->TOP.__PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__2__KET____DOT__u_ch}
    , __PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch{vlSymsp->TOP.__PVT__tb_dma_top__DOT__dut__DOT__g_ch__BRA__3__KET____DOT__u_ch}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_dma_top::Vtb_dma_top(const char* _vcname__)
    : Vtb_dma_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_dma_top::~Vtb_dma_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_dma_top___024root___eval_debug_assertions(Vtb_dma_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtb_dma_top___024root___eval_static(Vtb_dma_top___024root* vlSelf);
void Vtb_dma_top___024root___eval_initial(Vtb_dma_top___024root* vlSelf);
VL_ATTR_COLD bool Vtb_dma_top___024root___eval_stl(Vtb_dma_top___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vtb_dma_top___024root___eval_sample(Vtb_dma_top___024root* vlSelf);
bool Vtb_dma_top___024root___eval_ico(Vtb_dma_top___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vtb_dma_top___024root___eval_act(Vtb_dma_top___024root* vlSelf);
bool Vtb_dma_top___024root___eval_inact(Vtb_dma_top___024root* vlSelf);
bool Vtb_dma_top___024root___eval_nba(Vtb_dma_top___024root* vlSelf);
bool Vtb_dma_top___024root___eval_obs(Vtb_dma_top___024root* vlSelf);
bool Vtb_dma_top___024root___eval_react(Vtb_dma_top___024root* vlSelf);
void Vtb_dma_top___024root___eval_postponed(Vtb_dma_top___024root* vlSelf);
VL_ATTR_COLD void Vtb_dma_top___024root___eval_final(Vtb_dma_top___024root* vlSelf);
VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__stl(Vtb_dma_top___024root* vlSelf);
VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__ico(Vtb_dma_top___024root* vlSelf);
VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__act(Vtb_dma_top___024root* vlSelf);
VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__nba(Vtb_dma_top___024root* vlSelf);
VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__obs(Vtb_dma_top___024root* vlSelf);
VL_ATTR_COLD void Vtb_dma_top___024root___eval_dump_triggers__react(Vtb_dma_top___024root* vlSelf);

void Vtb_dma_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_dma_top::eval_step\n"); );
    m_evalLoop.eval();
}

void Vtb_dma_top::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_dma_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vtb_dma_top::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vtb_dma_top::evalStatic() {
    Vtb_dma_top___024root___eval_static(&(vlSymsp->TOP));
}

void Vtb_dma_top::evalInitial() {
    Vtb_dma_top___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vtb_dma_top::evalStl(bool firstIteration) {
    return Vtb_dma_top___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vtb_dma_top::evalSample() {
    Vtb_dma_top___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vtb_dma_top::evalIco(bool firstIteration) {
    return Vtb_dma_top___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vtb_dma_top::evalAct() {
    return Vtb_dma_top___024root___eval_act(&(vlSymsp->TOP));
}

bool Vtb_dma_top::evalInact() {
    return Vtb_dma_top___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vtb_dma_top::evalNba() {
    return Vtb_dma_top___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vtb_dma_top::evalObs() {
    return Vtb_dma_top___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vtb_dma_top::evalReact() {
    return Vtb_dma_top___024root___eval_react(&(vlSymsp->TOP));
}

void Vtb_dma_top::evalPostponed() {
    Vtb_dma_top___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vtb_dma_top::evalFinal() {
    Vtb_dma_top___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_dma_top::dumpTriggersStl() {
    Vtb_dma_top___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_dma_top::dumpTriggersIco() {
    Vtb_dma_top___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_dma_top::dumpTriggersAct() {
    Vtb_dma_top___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_dma_top::dumpTriggersNba() {
    Vtb_dma_top___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_dma_top::dumpTriggersObs() {
    Vtb_dma_top___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vtb_dma_top::dumpTriggersReact() {
    Vtb_dma_top___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vtb_dma_top::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_dma_top::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_dma_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vtb_dma_top::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_dma_top::hierName() const { return vlSymsp->name(); }
const char* Vtb_dma_top::modelName() const { return "Vtb_dma_top"; }
unsigned Vtb_dma_top::threads() const { return 1; }
void Vtb_dma_top::prepareClone() const { contextp()->prepareClone(); }
void Vtb_dma_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
