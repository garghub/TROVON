int FPU_to_exp16(FPU_REG const *a, FPU_REG *x)
{
int sign = getsign(a);
*(long long *)&(x->sigl) = *(const long long *)&(a->sigl);
setexponent16(x, exponent(a));
if (exponent16(x) == EXP_UNDER) {
if (x->sigh & 0x80000000) {
addexponent(x, 1);
} else {
addexponent(x, 1);
FPU_normalize_nuo(x);
}
}
if (!(x->sigh & 0x80000000)) {
EXCEPTION(EX_INTERNAL | 0x180);
}
return sign;
}
