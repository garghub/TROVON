ieee754dp ieee754dp_modf(ieee754dp x, ieee754dp *ip)
{
COMPXDP;
CLEARCX;
EXPLODEXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
case IEEE754_CLASS_ZERO:
*ip = x;
return x;
case IEEE754_CLASS_DNORM:
*ip = ieee754dp_zero(xs);
return x;
case IEEE754_CLASS_NORM:
break;
}
if (xe < 0) {
*ip = ieee754dp_zero(xs);
return x;
}
if (xe >= DP_MBITS) {
*ip = x;
return ieee754dp_zero(xs);
}
*ip = builddp(xs, xe + DP_EBIAS,
((xm >> (DP_MBITS - xe)) << (DP_MBITS - xe)) &
~DP_HIDDEN_BIT);
xm = (xm << (64 - (DP_MBITS - xe))) >> (64 - (DP_MBITS - xe));
if (xm == 0)
return ieee754dp_zero(xs);
while ((xm >> DP_MBITS) == 0) {
xm <<= 1;
xe--;
}
return builddp(xs, xe + DP_EBIAS, xm & ~DP_HIDDEN_BIT);
}
