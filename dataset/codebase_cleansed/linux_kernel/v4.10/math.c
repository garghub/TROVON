int init_module(void)
{
save_emul_imprecise = alpha_fp_emul_imprecise;
save_emul = alpha_fp_emul;
alpha_fp_emul_imprecise = do_alpha_fp_emul_imprecise;
alpha_fp_emul = do_alpha_fp_emul;
return 0;
}
void cleanup_module(void)
{
alpha_fp_emul_imprecise = save_emul_imprecise;
alpha_fp_emul = save_emul;
}
long
alpha_fp_emul (unsigned long pc)
{
FP_DECL_EX;
FP_DECL_S(SA); FP_DECL_S(SB); FP_DECL_S(SR);
FP_DECL_D(DA); FP_DECL_D(DB); FP_DECL_D(DR);
unsigned long fa, fb, fc, func, mode, src;
unsigned long res, va, vb, vc, swcr, fpcr;
__u32 insn;
long si_code;
get_user(insn, (__u32 __user *)pc);
fc = (insn >> 0) & 0x1f;
fb = (insn >> 16) & 0x1f;
fa = (insn >> 21) & 0x1f;
func = (insn >> 5) & 0xf;
src = (insn >> 9) & 0x3;
mode = (insn >> 11) & 0x3;
fpcr = rdfpcr();
swcr = swcr_update_status(current_thread_info()->ieee_state, fpcr);
if (mode == 3) {
mode = (fpcr >> FPCR_DYN_SHIFT) & 3;
}
switch (src) {
case FOP_SRC_S:
va = alpha_read_fp_reg_s(fa);
vb = alpha_read_fp_reg_s(fb);
FP_UNPACK_SP(SA, &va);
FP_UNPACK_SP(SB, &vb);
switch (func) {
case FOP_FNC_SUBx:
FP_SUB_S(SR, SA, SB);
goto pack_s;
case FOP_FNC_ADDx:
FP_ADD_S(SR, SA, SB);
goto pack_s;
case FOP_FNC_MULx:
FP_MUL_S(SR, SA, SB);
goto pack_s;
case FOP_FNC_DIVx:
FP_DIV_S(SR, SA, SB);
goto pack_s;
case FOP_FNC_SQRTx:
FP_SQRT_S(SR, SB);
goto pack_s;
}
goto bad_insn;
case FOP_SRC_T:
va = alpha_read_fp_reg(fa);
vb = alpha_read_fp_reg(fb);
if ((func & ~3) == FOP_FNC_CMPxUN) {
FP_UNPACK_RAW_DP(DA, &va);
FP_UNPACK_RAW_DP(DB, &vb);
if (!DA_e && !_FP_FRAC_ZEROP_1(DA)) {
FP_SET_EXCEPTION(FP_EX_DENORM);
if (FP_DENORM_ZERO)
_FP_FRAC_SET_1(DA, _FP_ZEROFRAC_1);
}
if (!DB_e && !_FP_FRAC_ZEROP_1(DB)) {
FP_SET_EXCEPTION(FP_EX_DENORM);
if (FP_DENORM_ZERO)
_FP_FRAC_SET_1(DB, _FP_ZEROFRAC_1);
}
FP_CMP_D(res, DA, DB, 3);
vc = 0x4000000000000000UL;
if (res == 3
&& ((func & 3) >= 2
|| FP_ISSIGNAN_D(DA)
|| FP_ISSIGNAN_D(DB))) {
FP_SET_EXCEPTION(FP_EX_INVALID);
}
switch (func) {
case FOP_FNC_CMPxUN: if (res != 3) vc = 0; break;
case FOP_FNC_CMPxEQ: if (res) vc = 0; break;
case FOP_FNC_CMPxLT: if (res != -1) vc = 0; break;
case FOP_FNC_CMPxLE: if ((long)res > 0) vc = 0; break;
}
goto done_d;
}
FP_UNPACK_DP(DA, &va);
FP_UNPACK_DP(DB, &vb);
switch (func) {
case FOP_FNC_SUBx:
FP_SUB_D(DR, DA, DB);
goto pack_d;
case FOP_FNC_ADDx:
FP_ADD_D(DR, DA, DB);
goto pack_d;
case FOP_FNC_MULx:
FP_MUL_D(DR, DA, DB);
goto pack_d;
case FOP_FNC_DIVx:
FP_DIV_D(DR, DA, DB);
goto pack_d;
case FOP_FNC_SQRTx:
FP_SQRT_D(DR, DB);
goto pack_d;
case FOP_FNC_CVTxS:
if (insn & 0x2000) {
FP_CONV(S,D,1,1,SR,DB);
goto pack_s;
} else {
vb = alpha_read_fp_reg_s(fb);
FP_UNPACK_SP(SB, &vb);
DR_c = DB_c;
DR_s = DB_s;
DR_e = DB_e + (1024 - 128);
DR_f = SB_f << (52 - 23);
goto pack_d;
}
case FOP_FNC_CVTxQ:
if (DB_c == FP_CLS_NAN
&& (_FP_FRAC_HIGH_RAW_D(DB) & _FP_QNANBIT_D)) {
vc = 0;
} else
FP_TO_INT_ROUND_D(vc, DB, 64, 2);
goto done_d;
}
goto bad_insn;
case FOP_SRC_Q:
vb = alpha_read_fp_reg(fb);
switch (func) {
case FOP_FNC_CVTQL:
vc = ((vb & 0xc0000000) << 32 |
(vb & 0x3fffffff) << 29);
FP_SET_EXCEPTION (FP_EX_INVALID);
goto done_d;
case FOP_FNC_CVTxS:
FP_FROM_INT_S(SR, ((long)vb), 64, long);
goto pack_s;
case FOP_FNC_CVTxT:
FP_FROM_INT_D(DR, ((long)vb), 64, long);
goto pack_d;
}
goto bad_insn;
}
goto bad_insn;
pack_s:
FP_PACK_SP(&vc, SR);
if ((_fex & FP_EX_UNDERFLOW) && (swcr & IEEE_MAP_UMZ))
vc = 0;
alpha_write_fp_reg_s(fc, vc);
goto done;
pack_d:
FP_PACK_DP(&vc, DR);
if ((_fex & FP_EX_UNDERFLOW) && (swcr & IEEE_MAP_UMZ))
vc = 0;
done_d:
alpha_write_fp_reg(fc, vc);
goto done;
done:
if (_fex) {
swcr |= (_fex << IEEE_STATUS_TO_EXCSUM_SHIFT);
current_thread_info()->ieee_state
|= (_fex << IEEE_STATUS_TO_EXCSUM_SHIFT);
fpcr &= (~FPCR_MASK | FPCR_DYN_MASK);
fpcr |= ieee_swcr_to_fpcr(swcr);
wrfpcr(fpcr);
_fex = _fex & swcr & IEEE_TRAP_ENABLE_MASK;
si_code = 0;
if (_fex) {
if (_fex & IEEE_TRAP_ENABLE_DNO) si_code = FPE_FLTUND;
if (_fex & IEEE_TRAP_ENABLE_INE) si_code = FPE_FLTRES;
if (_fex & IEEE_TRAP_ENABLE_UNF) si_code = FPE_FLTUND;
if (_fex & IEEE_TRAP_ENABLE_OVF) si_code = FPE_FLTOVF;
if (_fex & IEEE_TRAP_ENABLE_DZE) si_code = FPE_FLTDIV;
if (_fex & IEEE_TRAP_ENABLE_INV) si_code = FPE_FLTINV;
}
return si_code;
}
return 0;
bad_insn:
printk(KERN_ERR "alpha_fp_emul: Invalid FP insn %#x at %#lx\n",
insn, pc);
return -1;
}
long
alpha_fp_emul_imprecise (struct pt_regs *regs, unsigned long write_mask)
{
unsigned long trigger_pc = regs->pc - 4;
unsigned long insn, opcode, rc, si_code = 0;
while (write_mask) {
get_user(insn, (__u32 __user *)(trigger_pc));
opcode = insn >> 26;
rc = insn & 0x1f;
switch (opcode) {
case OPC_PAL:
case OPC_JSR:
case 0x30 ... 0x3f:
goto egress;
case OPC_MISC:
switch (insn & 0xffff) {
case MISC_TRAPB:
case MISC_EXCB:
goto egress;
default:
break;
}
break;
case OPC_INTA:
case OPC_INTL:
case OPC_INTS:
case OPC_INTM:
write_mask &= ~(1UL << rc);
break;
case OPC_FLTC:
case OPC_FLTV:
case OPC_FLTI:
case OPC_FLTL:
write_mask &= ~(1UL << (rc + 32));
break;
}
if (!write_mask) {
regs->pc = trigger_pc + 4;
si_code = alpha_fp_emul(trigger_pc);
goto egress;
}
trigger_pc -= 4;
}
egress:
return si_code;
}
