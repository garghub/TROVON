int ieee754dp_class(union ieee754dp x)
{
COMPXDP;
EXPLODEXDP;
return xc;
}
int ieee754dp_isnan(union ieee754dp x)
{
return ieee754dp_class(x) >= IEEE754_CLASS_SNAN;
}
static inline int ieee754dp_issnan(union ieee754dp x)
{
assert(ieee754dp_isnan(x));
return (DPMANT(x) & DP_MBIT(DP_FBITS - 1)) == DP_MBIT(DP_FBITS - 1);
}
union ieee754dp __cold ieee754dp_nanxcpt(union ieee754dp r)
{
assert(ieee754dp_isnan(r));
if (!ieee754dp_issnan(r))
return r;
if (!ieee754_setandtestcx(IEEE754_INVALID_OPERATION)) {
DPMANT(r) &= (~DP_MBIT(DP_FBITS-1));
if (ieee754dp_isnan(r))
return r;
else
return ieee754dp_indef();
}
return r;
}
static u64 ieee754dp_get_rounding(int sn, u64 xm)
{
if (xm & (DP_MBIT(3) - 1)) {
switch (ieee754_csr.rm) {
case FPU_CSR_RZ:
break;
case FPU_CSR_RN:
xm += 0x3 + ((xm >> 3) & 1);
break;
case FPU_CSR_RU:
if (!sn)
xm += 0x8;
break;
case FPU_CSR_RD:
if (sn)
xm += 0x8;
break;
}
}
return xm;
}
union ieee754dp ieee754dp_format(int sn, int xe, u64 xm)
{
assert(xm);
assert((xm >> (DP_FBITS + 1 + 3)) == 0);
assert(xm & (DP_HIDDEN_BIT << 3));
if (xe < DP_EMIN) {
int es = DP_EMIN - xe;
if (ieee754_csr.nod) {
ieee754_setcx(IEEE754_UNDERFLOW);
ieee754_setcx(IEEE754_INEXACT);
switch(ieee754_csr.rm) {
case FPU_CSR_RN:
case FPU_CSR_RZ:
return ieee754dp_zero(sn);
case FPU_CSR_RU:
if (sn == 0)
return ieee754dp_min(0);
else
return ieee754dp_zero(1);
case FPU_CSR_RD:
if (sn == 0)
return ieee754dp_zero(0);
else
return ieee754dp_min(1);
}
}
if (xe == DP_EMIN - 1 &&
ieee754dp_get_rounding(sn, xm) >> (DP_FBITS + 1 + 3))
{
ieee754_setcx(IEEE754_INEXACT);
xm = ieee754dp_get_rounding(sn, xm);
xm >>= 1;
xm &= ~(DP_MBIT(3) - 1);
xe++;
}
else {
xm = XDPSRS(xm, es);
xe += es;
assert((xm & (DP_HIDDEN_BIT << 3)) == 0);
assert(xe == DP_EMIN);
}
}
if (xm & (DP_MBIT(3) - 1)) {
ieee754_setcx(IEEE754_INEXACT);
if ((xm & (DP_HIDDEN_BIT << 3)) == 0) {
ieee754_setcx(IEEE754_UNDERFLOW);
}
xm = ieee754dp_get_rounding(sn, xm);
if (xm >> (DP_FBITS + 3 + 1)) {
xm >>= 1;
xe++;
}
}
xm >>= 3;
assert((xm >> (DP_FBITS + 1)) == 0);
assert(xe >= DP_EMIN);
if (xe > DP_EMAX) {
ieee754_setcx(IEEE754_OVERFLOW);
ieee754_setcx(IEEE754_INEXACT);
switch (ieee754_csr.rm) {
case FPU_CSR_RN:
return ieee754dp_inf(sn);
case FPU_CSR_RZ:
return ieee754dp_max(sn);
case FPU_CSR_RU:
if (sn == 0)
return ieee754dp_inf(0);
else
return ieee754dp_max(1);
case FPU_CSR_RD:
if (sn == 0)
return ieee754dp_max(0);
else
return ieee754dp_inf(1);
}
}
if ((xm & DP_HIDDEN_BIT) == 0) {
assert(xe == DP_EMIN);
if (ieee754_csr.mx & IEEE754_UNDERFLOW)
ieee754_setcx(IEEE754_UNDERFLOW);
return builddp(sn, DP_EMIN - 1 + DP_EBIAS, xm);
} else {
assert((xm >> (DP_FBITS + 1)) == 0);
assert(xm & DP_HIDDEN_BIT);
return builddp(sn, xe + DP_EBIAS, xm & ~DP_HIDDEN_BIT);
}
}
