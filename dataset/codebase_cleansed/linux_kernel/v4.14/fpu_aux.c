static void fnop(void)
{
}
static void fclex(void)
{
partial_status &=
~(SW_Backward | SW_Summary | SW_Stack_Fault | SW_Precision |
SW_Underflow | SW_Overflow | SW_Zero_Div | SW_Denorm_Op |
SW_Invalid);
no_ip_update = 1;
}
void fpstate_init_soft(struct swregs_state *soft)
{
struct address *oaddr, *iaddr;
memset(soft, 0, sizeof(*soft));
soft->cwd = 0x037f;
soft->swd = 0;
soft->ftop = 0;
soft->twd = 0xffff;
oaddr = (struct address *)&soft->foo;
oaddr->offset = 0;
oaddr->selector = 0;
iaddr = (struct address *)&soft->fip;
iaddr->offset = 0;
iaddr->selector = 0;
iaddr->opcode = 0;
soft->no_update = 1;
}
void finit(void)
{
fpstate_init_soft(&current->thread.fpu.state.soft);
}
void finit_(void)
{
(finit_table[FPU_rm]) ();
}
static void fstsw_ax(void)
{
*(short *)&FPU_EAX = status_word();
no_ip_update = 1;
}
void fstsw_(void)
{
(fstsw_table[FPU_rm]) ();
}
void fp_nop(void)
{
(fp_nop_table[FPU_rm]) ();
}
void fld_i_(void)
{
FPU_REG *st_new_ptr;
int i;
u_char tag;
if (STACK_OVERFLOW) {
FPU_stack_overflow();
return;
}
i = FPU_rm;
if (NOT_EMPTY(i)) {
reg_copy(&st(i), st_new_ptr);
tag = FPU_gettagi(i);
push();
FPU_settag0(tag);
} else {
if (control_word & CW_Invalid) {
FPU_stack_underflow();
} else
EXCEPTION(EX_StackUnder);
}
}
void fxch_i(void)
{
FPU_REG t;
int i = FPU_rm;
FPU_REG *st0_ptr = &st(0), *sti_ptr = &st(i);
long tag_word = fpu_tag_word;
int regnr = top & 7, regnri = ((regnr + i) & 7);
u_char st0_tag = (tag_word >> (regnr * 2)) & 3;
u_char sti_tag = (tag_word >> (regnri * 2)) & 3;
if (st0_tag == TAG_Empty) {
if (sti_tag == TAG_Empty) {
FPU_stack_underflow();
FPU_stack_underflow_i(i);
return;
}
if (control_word & CW_Invalid) {
FPU_copy_to_reg0(sti_ptr, sti_tag);
}
FPU_stack_underflow_i(i);
return;
}
if (sti_tag == TAG_Empty) {
if (control_word & CW_Invalid) {
FPU_copy_to_regi(st0_ptr, st0_tag, i);
}
FPU_stack_underflow();
return;
}
clear_C1();
reg_copy(st0_ptr, &t);
reg_copy(sti_ptr, st0_ptr);
reg_copy(&t, sti_ptr);
tag_word &= ~(3 << (regnr * 2)) & ~(3 << (regnri * 2));
tag_word |= (sti_tag << (regnr * 2)) | (st0_tag << (regnri * 2));
fpu_tag_word = tag_word;
}
static void fcmovCC(void)
{
int i = FPU_rm;
FPU_REG *st0_ptr = &st(0);
FPU_REG *sti_ptr = &st(i);
long tag_word = fpu_tag_word;
int regnr = top & 7;
int regnri = (top + i) & 7;
u_char sti_tag = (tag_word >> (regnri * 2)) & 3;
if (sti_tag == TAG_Empty) {
FPU_stack_underflow();
clear_C1();
return;
}
reg_copy(sti_ptr, st0_ptr);
tag_word &= ~(3 << (regnr * 2));
tag_word |= (sti_tag << (regnr * 2));
fpu_tag_word = tag_word;
}
void fcmovb(void)
{
if (FPU_EFLAGS & X86_EFLAGS_CF)
fcmovCC();
}
void fcmove(void)
{
if (FPU_EFLAGS & X86_EFLAGS_ZF)
fcmovCC();
}
void fcmovbe(void)
{
if (FPU_EFLAGS & (X86_EFLAGS_CF|X86_EFLAGS_ZF))
fcmovCC();
}
void fcmovu(void)
{
if (FPU_EFLAGS & X86_EFLAGS_PF)
fcmovCC();
}
void fcmovnb(void)
{
if (!(FPU_EFLAGS & X86_EFLAGS_CF))
fcmovCC();
}
void fcmovne(void)
{
if (!(FPU_EFLAGS & X86_EFLAGS_ZF))
fcmovCC();
}
void fcmovnbe(void)
{
if (!(FPU_EFLAGS & (X86_EFLAGS_CF|X86_EFLAGS_ZF)))
fcmovCC();
}
void fcmovnu(void)
{
if (!(FPU_EFLAGS & X86_EFLAGS_PF))
fcmovCC();
}
void ffree_(void)
{
FPU_settagi(FPU_rm, TAG_Empty);
}
void ffreep(void)
{
FPU_settagi(FPU_rm, TAG_Empty);
FPU_pop();
}
void fst_i_(void)
{
FPU_copy_to_regi(&st(0), FPU_gettag0(), FPU_rm);
}
void fstp_i(void)
{
FPU_copy_to_regi(&st(0), FPU_gettag0(), FPU_rm);
FPU_pop();
}
