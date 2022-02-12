static void fchs(FPU_REG *st0_ptr, u_char st0tag)
{
if (st0tag ^ TAG_Empty) {
signbyte(st0_ptr) ^= SIGN_NEG;
clear_C1();
} else
FPU_stack_underflow();
}
static void fabs(FPU_REG *st0_ptr, u_char st0tag)
{
if (st0tag ^ TAG_Empty) {
setpositive(st0_ptr);
clear_C1();
} else
FPU_stack_underflow();
}
static void ftst_(FPU_REG *st0_ptr, u_char st0tag)
{
switch (st0tag) {
case TAG_Zero:
setcc(SW_C3);
break;
case TAG_Valid:
if (getsign(st0_ptr) == SIGN_POS)
setcc(0);
else
setcc(SW_C0);
break;
case TAG_Special:
switch (FPU_Special(st0_ptr)) {
case TW_Denormal:
if (getsign(st0_ptr) == SIGN_POS)
setcc(0);
else
setcc(SW_C0);
if (denormal_operand() < 0) {
#ifdef PECULIAR_486
if (getsign(st0_ptr) == SIGN_POS)
setcc(SW_C3);
#endif
return;
}
break;
case TW_NaN:
setcc(SW_C0 | SW_C2 | SW_C3);
EXCEPTION(EX_Invalid);
break;
case TW_Infinity:
if (getsign(st0_ptr) == SIGN_POS)
setcc(0);
else
setcc(SW_C0);
break;
default:
setcc(SW_C0 | SW_C2 | SW_C3);
EXCEPTION(EX_INTERNAL | 0x14);
break;
}
break;
case TAG_Empty:
setcc(SW_C0 | SW_C2 | SW_C3);
EXCEPTION(EX_StackUnder);
break;
}
}
static void fxam(FPU_REG *st0_ptr, u_char st0tag)
{
int c = 0;
switch (st0tag) {
case TAG_Empty:
c = SW_C3 | SW_C0;
break;
case TAG_Zero:
c = SW_C3;
break;
case TAG_Valid:
c = SW_C2;
break;
case TAG_Special:
switch (FPU_Special(st0_ptr)) {
case TW_Denormal:
c = SW_C2 | SW_C3;
break;
case TW_NaN:
if ((st0_ptr->sigh & 0x80000000)
&& (exponent(st0_ptr) == EXP_OVER))
c = SW_C0;
break;
case TW_Infinity:
c = SW_C2 | SW_C0;
break;
}
}
if (getsign(st0_ptr) == SIGN_NEG)
c |= SW_C1;
setcc(c);
}
void FPU_etc(void)
{
(fp_etc_table[FPU_rm]) (&st(0), FPU_gettag0());
}
