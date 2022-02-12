static inline union ieee754dp ieee754dp_nan_fsp(int xs, u64 xm)
{
return builddp(xs, DP_EMAX + 1 + DP_EBIAS,
xm << (DP_FBITS - SP_FBITS));
}
union ieee754dp ieee754dp_fsp(union ieee754sp x)
{
COMPXSP;
EXPLODEXSP;
ieee754_clearcx();
FLUSHXSP;
switch (xc) {
case IEEE754_CLASS_SNAN:
return ieee754dp_nanxcpt(ieee754dp_nan_fsp(xs, xm));
case IEEE754_CLASS_QNAN:
return ieee754dp_nan_fsp(xs, xm);
case IEEE754_CLASS_INF:
return ieee754dp_inf(xs);
case IEEE754_CLASS_ZERO:
return ieee754dp_zero(xs);
case IEEE754_CLASS_DNORM:
while ((xm >> SP_FBITS) == 0) {
xm <<= 1;
xe--;
}
break;
case IEEE754_CLASS_NORM:
break;
}
xm &= ~SP_HIDDEN_BIT;
return builddp(xs, xe + DP_EBIAS,
(u64) xm << (DP_FBITS - SP_FBITS));
}
