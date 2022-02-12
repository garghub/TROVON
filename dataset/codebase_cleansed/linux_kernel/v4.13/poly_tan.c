void poly_tan(FPU_REG *st0_ptr)
{
long int exponent;
int invert;
Xsig argSq, argSqSq, accumulatoro, accumulatore, accum,
argSignif, fix_up;
unsigned long adj;
exponent = exponent(st0_ptr);
#ifdef PARANOID
if (signnegative(st0_ptr)) {
arith_invalid(0);
return;
}
#endif
if ((exponent == 0)
|| ((exponent == -1) && (st0_ptr->sigh > 0xc90fdaa2))) {
invert = 1;
accum.lsw = 0;
XSIG_LL(accum) = significand(st0_ptr);
if (exponent == 0) {
XSIG_LL(accum) <<= 1;
}
XSIG_LL(accum) = 0x921fb54442d18469LL - XSIG_LL(accum);
if (XSIG_LL(accum) == 0xffffffffffffffffLL) {
FPU_settag0(TAG_Valid);
significand(st0_ptr) = 0x8a51e04daabda360LL;
setexponent16(st0_ptr,
(0x41 + EXTENDED_Ebias) | SIGN_Negative);
return;
}
argSignif.lsw = accum.lsw;
XSIG_LL(argSignif) = XSIG_LL(accum);
exponent = -1 + norm_Xsig(&argSignif);
} else {
invert = 0;
argSignif.lsw = 0;
XSIG_LL(accum) = XSIG_LL(argSignif) = significand(st0_ptr);
if (exponent < -1) {
if (FPU_shrx(&XSIG_LL(accum), -1 - exponent) >=
0x80000000U)
XSIG_LL(accum)++;
}
}
XSIG_LL(argSq) = XSIG_LL(accum);
argSq.lsw = accum.lsw;
mul_Xsig_Xsig(&argSq, &argSq);
XSIG_LL(argSqSq) = XSIG_LL(argSq);
argSqSq.lsw = argSq.lsw;
mul_Xsig_Xsig(&argSqSq, &argSqSq);
accumulatoro.msw = accumulatoro.midw = accumulatoro.lsw = 0;
polynomial_Xsig(&accumulatoro, &XSIG_LL(argSqSq), oddnegterm,
HiPOWERon - 1);
mul_Xsig_Xsig(&accumulatoro, &argSq);
negate_Xsig(&accumulatoro);
polynomial_Xsig(&accumulatoro, &XSIG_LL(argSqSq), oddplterm,
HiPOWERop - 1);
accumulatore.msw = accumulatore.midw = accumulatore.lsw = 0;
polynomial_Xsig(&accumulatore, &XSIG_LL(argSqSq), evenplterm,
HiPOWERep - 1);
mul_Xsig_Xsig(&accumulatore, &argSq);
negate_Xsig(&accumulatore);
polynomial_Xsig(&accumulatore, &XSIG_LL(argSqSq), evennegterm,
HiPOWERen - 1);
mul64_Xsig(&accumulatore, &XSIG_LL(argSignif));
mul64_Xsig(&accumulatore, &XSIG_LL(argSignif));
shr_Xsig(&accumulatore, -2 * (1 + exponent) + 1);
negate_Xsig(&accumulatore);
if (accumulatore.msw == 0) {
XSIG_LL(accum) = 0x8000000000000000LL;
accum.lsw = 0;
} else {
div_Xsig(&accumulatoro, &accumulatore, &accum);
}
mul64_Xsig(&accum, &XSIG_LL(argSignif));
mul64_Xsig(&accum, &XSIG_LL(argSignif));
mul64_Xsig(&accum, &XSIG_LL(argSignif));
mul64_Xsig(&accum, &twothirds);
shr_Xsig(&accum, -2 * (exponent + 1));
add_two_Xsig(&accum, &argSignif, &exponent);
if (invert) {
XSIG_LL(fix_up) = 0x898cc51701b839a2LL;
fix_up.lsw = 0;
if (exponent == 0)
adj = 0xffffffff;
else if (exponent > -30) {
adj = accum.msw >> -(exponent + 1);
adj = mul_32_32(adj, adj);
} else
adj = 0;
adj = mul_32_32(0x898cc517, adj);
fix_up.msw += adj;
if (!(fix_up.msw & 0x80000000)) {
shr_Xsig(&fix_up, 1);
fix_up.msw |= 0x80000000;
shr_Xsig(&fix_up, 64 + exponent);
} else
shr_Xsig(&fix_up, 65 + exponent);
add_two_Xsig(&accum, &fix_up, &exponent);
accumulatoro.lsw = accumulatoro.midw = 0;
accumulatoro.msw = 0x80000000;
div_Xsig(&accumulatoro, &accum, &accum);
exponent = -exponent - 1;
}
round_Xsig(&accum);
FPU_settag0(TAG_Valid);
significand(st0_ptr) = XSIG_LL(accum);
setexponent16(st0_ptr, exponent + EXTENDED_Ebias);
}
