static void fld_const(FPU_REG const * c, int adj, u_char tag)
{
FPU_REG *st_new_ptr;
if (STACK_OVERFLOW) {
FPU_stack_overflow();
return;
}
push();
reg_copy(c, st_new_ptr);
st_new_ptr->sigl += adj;
FPU_settag0(tag);
clear_C1();
}
static void fld1(int rc)
{
fld_const(&CONST_1, 0, TAG_Valid);
}
static void fldl2t(int rc)
{
fld_const(&CONST_L2T, (rc == RC_UP) ? 1 : 0, TAG_Valid);
}
static void fldl2e(int rc)
{
fld_const(&CONST_L2E, DOWN_OR_CHOP(rc) ? -1 : 0, TAG_Valid);
}
static void fldpi(int rc)
{
fld_const(&CONST_PI, DOWN_OR_CHOP(rc) ? -1 : 0, TAG_Valid);
}
static void fldlg2(int rc)
{
fld_const(&CONST_LG2, DOWN_OR_CHOP(rc) ? -1 : 0, TAG_Valid);
}
static void fldln2(int rc)
{
fld_const(&CONST_LN2, DOWN_OR_CHOP(rc) ? -1 : 0, TAG_Valid);
}
static void fldz(int rc)
{
fld_const(&CONST_Z, 0, TAG_Zero);
}
void fconst(void)
{
(constants_table[FPU_rm]) (control_word & CW_RC);
}
