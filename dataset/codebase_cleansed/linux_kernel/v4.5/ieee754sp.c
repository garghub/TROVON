int ieee754sp_class(union ieee754sp x)
{
COMPXSP;
EXPLODEXSP;
return xc;
}
static inline int ieee754sp_isnan(union ieee754sp x)
{
return ieee754_class_nan(ieee754sp_class(x));
}
static inline int ieee754sp_issnan(union ieee754sp x)
{
int qbit;
assert(ieee754sp_isnan(x));
qbit = (SPMANT(x) & SP_MBIT(SP_FBITS - 1)) == SP_MBIT(SP_FBITS - 1);
return ieee754_csr.nan2008 ^ qbit;
}
union ieee754sp __cold ieee754sp_nanxcpt(union ieee754sp r)
{
assert(ieee754sp_issnan(r));
ieee754_setcx(IEEE754_INVALID_OPERATION);
if (ieee754_csr.nan2008)
SPMANT(r) |= SP_MBIT(SP_FBITS - 1);
else
r = ieee754sp_indef();
return r;
}
static unsigned ieee754sp_get_rounding(int sn, unsigned xm)
{
if (xm & (SP_MBIT(3) - 1)) {
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
union ieee754sp ieee754sp_format(int sn, int xe, unsigned xm)
{
assert(xm);
assert((xm >> (SP_FBITS + 1 + 3)) == 0);
assert(xm & (SP_HIDDEN_BIT << 3));
if (xe < SP_EMIN) {
int es = SP_EMIN - xe;
if (ieee754_csr.nod) {
ieee754_setcx(IEEE754_UNDERFLOW);
ieee754_setcx(IEEE754_INEXACT);
switch(ieee754_csr.rm) {
case FPU_CSR_RN:
case FPU_CSR_RZ:
return ieee754sp_zero(sn);
case FPU_CSR_RU:
if (sn == 0)
return ieee754sp_min(0);
else
return ieee754sp_zero(1);
case FPU_CSR_RD:
if (sn == 0)
return ieee754sp_zero(0);
else
return ieee754sp_min(1);
}
}
if (xe == SP_EMIN - 1 &&
ieee754sp_get_rounding(sn, xm) >> (SP_FBITS + 1 + 3))
{
ieee754_setcx(IEEE754_INEXACT);
xm = ieee754sp_get_rounding(sn, xm);
xm >>= 1;
xm &= ~(SP_MBIT(3) - 1);
xe++;
} else {
SPXSRSXn(es);
assert((xm & (SP_HIDDEN_BIT << 3)) == 0);
assert(xe == SP_EMIN);
}
}
if (xm & (SP_MBIT(3) - 1)) {
ieee754_setcx(IEEE754_INEXACT);
if ((xm & (SP_HIDDEN_BIT << 3)) == 0) {
ieee754_setcx(IEEE754_UNDERFLOW);
}
xm = ieee754sp_get_rounding(sn, xm);
if (xm >> (SP_FBITS + 1 + 3)) {
xm >>= 1;
xe++;
}
}
xm >>= 3;
assert((xm >> (SP_FBITS + 1)) == 0);
assert(xe >= SP_EMIN);
if (xe > SP_EMAX) {
ieee754_setcx(IEEE754_OVERFLOW);
ieee754_setcx(IEEE754_INEXACT);
switch (ieee754_csr.rm) {
case FPU_CSR_RN:
return ieee754sp_inf(sn);
case FPU_CSR_RZ:
return ieee754sp_max(sn);
case FPU_CSR_RU:
if (sn == 0)
return ieee754sp_inf(0);
else
return ieee754sp_max(1);
case FPU_CSR_RD:
if (sn == 0)
return ieee754sp_max(0);
else
return ieee754sp_inf(1);
}
}
if ((xm & SP_HIDDEN_BIT) == 0) {
assert(xe == SP_EMIN);
if (ieee754_csr.mx & IEEE754_UNDERFLOW)
ieee754_setcx(IEEE754_UNDERFLOW);
return buildsp(sn, SP_EMIN - 1 + SP_EBIAS, xm);
} else {
assert((xm >> (SP_FBITS + 1)) == 0);
assert(xm & SP_HIDDEN_BIT);
return buildsp(sn, xe + SP_EBIAS, xm & ~SP_HIDDEN_BIT);
}
}
