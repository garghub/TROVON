ieee754sp ieee754sp_scalb(ieee754sp x, int n)
{
COMPXSP;
CLEARCX;
EXPLODEXSP;
switch (xc) {
case IEEE754_CLASS_SNAN:
return ieee754sp_nanxcpt(x, "scalb", x, n);
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
case IEEE754_CLASS_ZERO:
return x;
case IEEE754_CLASS_DNORM:
SPDNORMX;
break;
case IEEE754_CLASS_NORM:
break;
}
SPNORMRET2(xs, xe + n, xm << 3, "scalb", x, n);
}
ieee754sp ieee754sp_ldexp(ieee754sp x, int n)
{
return ieee754sp_scalb(x, n);
}
