ieee754sp ieee754sp_fdp(ieee754dp x)
{
COMPXDP;
ieee754sp nan;
EXPLODEXDP;
CLEARCX;
FLUSHXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
SETCX(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(ieee754sp_indef(), "fdp");
case IEEE754_CLASS_QNAN:
nan = buildsp(xs, SP_EMAX + 1 + SP_EBIAS, (u32)
(xm >> (DP_MBITS - SP_MBITS)));
if (!ieee754sp_isnan(nan))
nan = ieee754sp_indef();
return ieee754sp_nanxcpt(nan, "fdp", x);
case IEEE754_CLASS_INF:
return ieee754sp_inf(xs);
case IEEE754_CLASS_ZERO:
return ieee754sp_zero(xs);
case IEEE754_CLASS_DNORM:
SETCX(IEEE754_UNDERFLOW);
SETCX(IEEE754_INEXACT);
if ((ieee754_csr.rm == IEEE754_RU && !xs) ||
(ieee754_csr.rm == IEEE754_RD && xs))
return ieee754sp_xcpt(ieee754sp_mind(xs), "fdp", x);
return ieee754sp_xcpt(ieee754sp_zero(xs), "fdp", x);
case IEEE754_CLASS_NORM:
break;
}
{
u32 rm;
rm = (xm >> (DP_MBITS - (SP_MBITS + 3))) |
((xm << (64 - (DP_MBITS - (SP_MBITS + 3)))) != 0);
SPNORMRET1(xs, xe, rm, "fdp", x);
}
}
