ieee754dp ieee754dp_fsp(ieee754sp x)
{
COMPXSP;
EXPLODEXSP;
CLEARCX;
FLUSHXSP;
switch (xc) {
case IEEE754_CLASS_SNAN:
SETCX(IEEE754_INVALID_OPERATION);
return ieee754dp_nanxcpt(ieee754dp_indef(), "fsp");
case IEEE754_CLASS_QNAN:
return ieee754dp_nanxcpt(builddp(xs,
DP_EMAX + 1 + DP_EBIAS,
((u64) xm
<< (DP_MBITS -
SP_MBITS))), "fsp",
x);
case IEEE754_CLASS_INF:
return ieee754dp_inf(xs);
case IEEE754_CLASS_ZERO:
return ieee754dp_zero(xs);
case IEEE754_CLASS_DNORM:
while ((xm >> SP_MBITS) == 0) {
xm <<= 1;
xe--;
}
break;
case IEEE754_CLASS_NORM:
break;
}
xm &= ~SP_HIDDEN_BIT;
return builddp(xs, xe + DP_EBIAS,
(u64) xm << (DP_MBITS - SP_MBITS));
}
