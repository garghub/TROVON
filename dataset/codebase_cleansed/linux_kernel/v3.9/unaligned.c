static void fixup_load(struct disasm_state *state, struct pt_regs *regs,
struct callee_regs *cregs)
{
int val;
if ((state->aa == 1) || (state->aa == 2)) {
set_reg(state->wb_reg, state->src1 + state->src2, regs, cregs);
if (state->aa == 2)
state->src2 = 0;
}
if (state->zz == 0) {
get32_unaligned_check(val, state->src1 + state->src2);
} else {
get16_unaligned_check(val, state->src1 + state->src2);
if (state->x)
val = (val << 16) >> 16;
}
if (state->pref == 0)
set_reg(state->dest, val, regs, cregs);
return;
fault: state->fault = 1;
}
static void fixup_store(struct disasm_state *state, struct pt_regs *regs,
struct callee_regs *cregs)
{
if ((state->aa == 1) || (state->aa == 2)) {
set_reg(state->wb_reg, state->src2 + state->src3, regs, cregs);
if (state->aa == 3)
state->src3 = 0;
} else if (state->aa == 3) {
if (state->zz == 2) {
set_reg(state->wb_reg, state->src2 + (state->src3 << 1),
regs, cregs);
} else if (!state->zz) {
set_reg(state->wb_reg, state->src2 + (state->src3 << 2),
regs, cregs);
} else {
goto fault;
}
}
if (!state->zz)
put32_unaligned_check(state->src1, state->src2 + state->src3);
else
put16_unaligned_check(state->src1, state->src2 + state->src3);
return;
fault: state->fault = 1;
}
int misaligned_fixup(unsigned long address, struct pt_regs *regs,
unsigned long cause, struct callee_regs *cregs)
{
struct disasm_state state;
char buf[TASK_COMM_LEN];
if (!user_mode(regs) || !unaligned_enabled)
return 1;
if (no_unaligned_warning) {
pr_warn_once("%s(%d) made unaligned access which was emulated"
" by kernel assist\n. This can degrade application"
" performance significantly\n. To enable further"
" logging of such instances, please \n"
" echo 0 > /proc/sys/kernel/ignore-unaligned-usertrap\n",
get_task_comm(buf, current), task_pid_nr(current));
} else {
pr_warn("%s(%d): unaligned access to/from 0x%lx by PC: 0x%lx\n",
get_task_comm(buf, current), task_pid_nr(current),
address, regs->ret);
}
disasm_instr(regs->ret, &state, 1, regs, cregs);
if (state.fault)
goto fault;
if ((state.zz == 1) || (state.di))
goto fault;
if (!state.write)
fixup_load(&state, regs, cregs);
else
fixup_store(&state, regs, cregs);
if (state.fault)
goto fault;
if (delay_mode(regs)) {
regs->ret = regs->bta;
regs->status32 &= ~STATUS_DE_MASK;
} else {
regs->ret += state.instr_len;
}
return 0;
fault:
pr_err("Alignment trap: fault in fix-up %08lx at [<%08lx>]\n",
state.words[0], address);
return 1;
}
