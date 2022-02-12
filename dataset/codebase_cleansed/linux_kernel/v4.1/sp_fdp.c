static inline union ieee754sp ieee754sp_nan_fdp(int xs, u64 xm)
{
return buildsp(xs, SP_EMAX + 1 + SP_EBIAS,
xm >> (DP_FBITS - SP_FBITS));
}
union ieee754sp ieee754sp_fdp(union ieee754dp x)
{
union ieee754sp y;
u32 rm;
COMPXDP;
COMPYSP;
EXPLODEXDP;
ieee754_clearcx();
FLUSHXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
return ieee754sp_nanxcpt(ieee754sp_nan_fdp(xs, xm));
case IEEE754_CLASS_QNAN:
y = ieee754sp_nan_fdp(xs, xm);
EXPLODEYSP;
if (!ieee754_class_nan(yc))
y = ieee754sp_indef();
return y;
case IEEE754_CLASS_INF:
return ieee754sp_inf(xs);
case IEEE754_CLASS_ZERO:
return ieee754sp_zero(xs);
case IEEE754_CLASS_DNORM:
ieee754_setcx(IEEE754_UNDERFLOW);
ieee754_setcx(IEEE754_INEXACT);
if ((ieee754_csr.rm == FPU_CSR_RU && !xs) ||
(ieee754_csr.rm == FPU_CSR_RD && xs))
return ieee754sp_mind(xs);
return ieee754sp_zero(xs);
case IEEE754_CLASS_NORM:
break;
}
rm = (xm >> (DP_FBITS - (SP_FBITS + 3))) |
((xm << (64 - (DP_FBITS - (SP_FBITS + 3)))) != 0);
return ieee754sp_format(xs, xe, rm);
}
