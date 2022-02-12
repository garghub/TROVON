void poly_atan(FPU_REG *st0_ptr, u_char st0_tag,
FPU_REG *st1_ptr, u_char st1_tag)
{
u_char transformed, inverted, sign1, sign2;
int exponent;
long int dummy_exp;
Xsig accumulator, Numer, Denom, accumulatore, argSignif, argSq, argSqSq;
u_char tag;
sign1 = getsign(st0_ptr);
sign2 = getsign(st1_ptr);
if (st0_tag == TAG_Valid) {
exponent = exponent(st0_ptr);
} else {
FPU_to_exp16(st0_ptr, st0_ptr);
exponent = exponent16(st0_ptr);
}
if (st1_tag == TAG_Valid) {
exponent -= exponent(st1_ptr);
} else {
FPU_to_exp16(st1_ptr, st1_ptr);
exponent -= exponent16(st1_ptr);
}
if ((exponent < 0) || ((exponent == 0) &&
((st0_ptr->sigh < st1_ptr->sigh) ||
((st0_ptr->sigh == st1_ptr->sigh) &&
(st0_ptr->sigl < st1_ptr->sigl))))) {
inverted = 1;
Numer.lsw = Denom.lsw = 0;
XSIG_LL(Numer) = significand(st0_ptr);
XSIG_LL(Denom) = significand(st1_ptr);
} else {
inverted = 0;
exponent = -exponent;
Numer.lsw = Denom.lsw = 0;
XSIG_LL(Numer) = significand(st1_ptr);
XSIG_LL(Denom) = significand(st0_ptr);
}
div_Xsig(&Numer, &Denom, &argSignif);
exponent += norm_Xsig(&argSignif);
if ((exponent >= -1)
|| ((exponent == -2) && (argSignif.msw > 0xd413ccd0))) {
transformed = 1;
if (exponent >= 0) {
#ifdef PARANOID
if (!((exponent == 0) &&
(argSignif.lsw == 0) && (argSignif.midw == 0) &&
(argSignif.msw == 0x80000000))) {
EXCEPTION(EX_INTERNAL | 0x104);
return;
}
#endif
argSignif.msw = 0;
} else {
Numer.lsw = Denom.lsw = argSignif.lsw;
XSIG_LL(Numer) = XSIG_LL(Denom) = XSIG_LL(argSignif);
if (exponent < -1)
shr_Xsig(&Numer, -1 - exponent);
negate_Xsig(&Numer);
shr_Xsig(&Denom, -exponent);
Denom.msw |= 0x80000000;
div_Xsig(&Numer, &Denom, &argSignif);
exponent = -1 + norm_Xsig(&argSignif);
}
} else {
transformed = 0;
}
argSq.lsw = argSignif.lsw;
argSq.midw = argSignif.midw;
argSq.msw = argSignif.msw;
mul_Xsig_Xsig(&argSq, &argSq);
argSqSq.lsw = argSq.lsw;
argSqSq.midw = argSq.midw;
argSqSq.msw = argSq.msw;
mul_Xsig_Xsig(&argSqSq, &argSqSq);
accumulatore.lsw = argSq.lsw;
XSIG_LL(accumulatore) = XSIG_LL(argSq);
shr_Xsig(&argSq, 2 * (-1 - exponent - 1));
shr_Xsig(&argSqSq, 4 * (-1 - exponent - 1));
accumulator.msw = accumulator.midw = accumulator.lsw = 0;
polynomial_Xsig(&accumulator, &XSIG_LL(argSqSq),
oddplterms, HIPOWERop - 1);
mul64_Xsig(&accumulator, &XSIG_LL(argSq));
negate_Xsig(&accumulator);
polynomial_Xsig(&accumulator, &XSIG_LL(argSqSq), oddnegterms,
HIPOWERon - 1);
negate_Xsig(&accumulator);
add_two_Xsig(&accumulator, &fixedpterm, &dummy_exp);
mul64_Xsig(&accumulatore, &denomterm);
shr_Xsig(&accumulatore, 1 + 2 * (-1 - exponent));
accumulatore.msw |= 0x80000000;
div_Xsig(&accumulator, &accumulatore, &accumulator);
mul_Xsig_Xsig(&accumulator, &argSignif);
mul_Xsig_Xsig(&accumulator, &argSq);
shr_Xsig(&accumulator, 3);
negate_Xsig(&accumulator);
add_Xsig_Xsig(&accumulator, &argSignif);
if (transformed) {
shr_Xsig(&accumulator, -1 - exponent);
negate_Xsig(&accumulator);
add_Xsig_Xsig(&accumulator, &pi_signif);
exponent = -1;
}
if (inverted) {
shr_Xsig(&accumulator, -exponent);
negate_Xsig(&accumulator);
add_Xsig_Xsig(&accumulator, &pi_signif);
exponent = 0;
}
if (sign1) {
shr_Xsig(&accumulator, 1 - exponent);
negate_Xsig(&accumulator);
add_Xsig_Xsig(&accumulator, &pi_signif);
exponent = 1;
}
exponent += round_Xsig(&accumulator);
significand(st1_ptr) = XSIG_LL(accumulator);
setexponent16(st1_ptr, exponent);
tag = FPU_round(st1_ptr, 1, 0, FULL_PRECISION, sign2);
FPU_settagi(1, tag);
set_precision_flag_up();
}
