int poly_2xm1(u_char sign, FPU_REG *arg, FPU_REG *result)
{
long int exponent, shift;
unsigned long long Xll;
Xsig accumulator, Denom, argSignif;
u_char tag;
exponent = exponent16(arg);
#ifdef PARANOID
if (exponent >= 0) {
EXCEPTION(EX_INTERNAL | 0x127);
return 1;
}
#endif
argSignif.lsw = 0;
XSIG_LL(argSignif) = Xll = significand(arg);
if (exponent == -1) {
shift = (argSignif.msw & 0x40000000) ? 3 : 2;
exponent -= 2;
XSIG_LL(argSignif) <<= 2;
Xll <<= 2;
} else if (exponent == -2) {
shift = 1;
exponent--;
XSIG_LL(argSignif) <<= 1;
Xll <<= 1;
} else
shift = 0;
if (exponent < -2) {
if (FPU_shrx(&Xll, -2 - exponent) >= 0x80000000U)
Xll++;
}
accumulator.lsw = accumulator.midw = accumulator.msw = 0;
polynomial_Xsig(&accumulator, &Xll, lterms, HIPOWER - 1);
mul_Xsig_Xsig(&accumulator, &argSignif);
shr_Xsig(&accumulator, 3);
mul_Xsig_Xsig(&argSignif, &hiterm);
add_two_Xsig(&accumulator, &argSignif, &exponent);
if (shift) {
shr_Xsig(&accumulator, -exponent);
accumulator.msw |= 0x80000000;
mul_Xsig_Xsig(&accumulator, shiftterm[shift]);
accumulator.msw &= 0x3fffffff;
exponent = 1;
}
if (sign != SIGN_POS) {
Denom.lsw = accumulator.lsw;
XSIG_LL(Denom) = XSIG_LL(accumulator);
if (exponent < 0)
shr_Xsig(&Denom, -exponent);
else if (exponent > 0) {
XSIG_LL(Denom) <<= 1;
if (Denom.lsw & 0x80000000)
XSIG_LL(Denom) |= 1;
(Denom.lsw) <<= 1;
}
Denom.msw |= 0x80000000;
div_Xsig(&accumulator, &Denom, &accumulator);
}
exponent += round_Xsig(&accumulator);
result = &st(0);
significand(result) = XSIG_LL(accumulator);
setexponent16(result, exponent);
tag = FPU_round(result, 1, 0, FULL_PRECISION, sign);
setsign(result, sign);
FPU_settag0(tag);
return 0;
}
