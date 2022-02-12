unsigned long __init
paravirt_get_gate_patchlist(enum pv_gate_patchlist type)
{
#define CASE(NAME, name) \
case PV_GATE_START_##NAME: \
return pv_patchdata.start_##name##_patchlist; \
case PV_GATE_END_##NAME: \
return pv_patchdata.end_##name##_patchlist; \
switch (type) {
CASE(FSYSCALL, fsyscall);
CASE(BRL_FSYS_BUBBLE_DOWN, brl_fsys_bubble_down);
CASE(VTOP, vtop);
CASE(MCKINLEY_E9, mckinley_e9);
default:
BUG();
break;
}
