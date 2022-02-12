ieee754dp ieee754dp_frexp(ieee754dp x, int *eptr)
{
COMPXDP;
CLEARCX;
EXPLODEXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
case IEEE754_CLASS_ZERO:
*eptr = 0;
return x;
case IEEE754_CLASS_DNORM:
DPDNORMX;
break;
case IEEE754_CLASS_NORM:
break;
}
*eptr = xe + 1;
return builddp(xs, -1 + DP_EBIAS, xm & ~DP_HIDDEN_BIT);
}
