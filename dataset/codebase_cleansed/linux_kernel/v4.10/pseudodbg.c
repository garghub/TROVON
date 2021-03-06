static const char *get_allreg_name(int grp, int reg)
{
return greg_names[(grp << 3) | reg];
}
static bool fix_up_reg(struct pt_regs *fp, long *value, int grp, int reg)
{
long *val = &fp->r0;
unsigned long tmp;
if (grp == 5 ||
(grp == 4 && (reg == 4 || reg == 5)) ||
(grp == 7))
return false;
if (grp == 0 || (grp == 1 && reg < 6))
val -= (reg + 8 * grp);
else if (grp == 1 && reg == 6)
val = &fp->usp;
else if (grp == 1 && reg == 7)
val = &fp->fp;
else if (grp == 2) {
val = &fp->i0;
val -= reg;
} else if (grp == 3 && reg >= 4) {
val = &fp->l0;
val -= (reg - 4);
} else if (grp == 3 && reg < 4) {
val = &fp->b0;
val -= reg;
} else if (grp == 4 && reg < 4) {
val = &fp->a0x;
val -= reg;
} else if (grp == 4 && reg == 6)
val = &fp->astat;
else if (grp == 4 && reg == 7)
val = &fp->rets;
else if (grp == 6 && reg < 6) {
val = &fp->lc0;
val -= reg;
} else if (grp == 6 && reg == 6) {
__asm__ __volatile__("%0 = cycles;\n" : "=d"(tmp));
val = &tmp;
} else if (grp == 6 && reg == 7) {
__asm__ __volatile__("%0 = cycles2;\n" : "=d"(tmp));
val = &tmp;
}
*value = *val;
return true;
}
bool execute_pseudodbg_assert(struct pt_regs *fp, unsigned int opcode)
{
int expected = ((opcode >> PseudoDbg_Assert_expected_bits) & PseudoDbg_Assert_expected_mask);
int dbgop = ((opcode >> (PseudoDbg_Assert_dbgop_bits)) & PseudoDbg_Assert_dbgop_mask);
int grp = ((opcode >> (PseudoDbg_Assert_grp_bits)) & PseudoDbg_Assert_grp_mask);
int regtest = ((opcode >> (PseudoDbg_Assert_regtest_bits)) & PseudoDbg_Assert_regtest_mask);
long value;
if ((opcode & 0xFF000000) != PseudoDbg_Assert_opcode)
return false;
if (!fix_up_reg(fp, &value, grp, regtest))
return false;
if (dbgop == 0 || dbgop == 2) {
if (expected != (value & 0xFFFF)) {
pr_notice("DBGA (%s.L,0x%x) failure, got 0x%x\n",
get_allreg_name(grp, regtest),
expected, (unsigned int)(value & 0xFFFF));
return false;
}
} else if (dbgop == 1 || dbgop == 3) {
if (expected != ((value >> 16) & 0xFFFF)) {
pr_notice("DBGA (%s.H,0x%x) failure, got 0x%x\n",
get_allreg_name(grp, regtest),
expected, (unsigned int)((value >> 16) & 0xFFFF));
return false;
}
}
fp->pc += 4;
return true;
}
bool execute_pseudodbg(struct pt_regs *fp, unsigned int opcode)
{
int grp, fn, reg;
long value, value1;
if ((opcode & 0xFF000000) != PseudoDbg_opcode)
return false;
opcode >>= 16;
grp = ((opcode >> PseudoDbg_grp_bits) & PseudoDbg_reg_mask);
fn = ((opcode >> PseudoDbg_fn_bits) & PseudoDbg_fn_mask);
reg = ((opcode >> PseudoDbg_reg_bits) & PseudoDbg_reg_mask);
if (fn == 3 && (reg == 0 || reg == 1)) {
if (!fix_up_reg(fp, &value, 4, 2 * reg))
return false;
if (!fix_up_reg(fp, &value1, 4, 2 * reg + 1))
return false;
pr_notice("DBG A%i = %02lx%08lx\n", reg, value & 0xFF, value1);
fp->pc += 2;
return true;
} else if (fn == 0) {
if (!fix_up_reg(fp, &value, grp, reg))
return false;
pr_notice("DBG %s = %08lx\n", get_allreg_name(grp, reg), value);
fp->pc += 2;
return true;
}
return false;
}
