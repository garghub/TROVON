union ieee754sp ieee754sp_fdp(union ieee754dp x)
{
u32 rm;
COMPXDP;
union ieee754sp nan;
EXPLODEXDP;
ieee754_clearcx();
FLUSHXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(ieee754sp_indef());
case IEEE754_CLASS_QNAN:
nan = buildsp(xs, SP_EMAX + 1 + SP_EBIAS, (u32)
(xm >> (DP_FBITS - SP_FBITS)));
if (!ieee754sp_isnan(nan))
nan = ieee754sp_indef();
return ieee754sp_nanxcpt(nan);
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
