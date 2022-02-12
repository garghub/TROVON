ieee754dp ieee754dp_scalb(ieee754dp x, int n)
{
COMPXDP;
CLEARCX;
EXPLODEXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
return ieee754dp_nanxcpt(x, "scalb", x, n);
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
case IEEE754_CLASS_ZERO:
return x;
case IEEE754_CLASS_DNORM:
DPDNORMX;
break;
case IEEE754_CLASS_NORM:
break;
}
DPNORMRET2(xs, xe + n, xm << 3, "scalb", x, n);
}
ieee754dp ieee754dp_ldexp(ieee754dp x, int n)
{
return ieee754dp_scalb(x, n);
}
