ieee754sp ieee754sp_frexp(ieee754sp x, int *eptr)
{
COMPXSP;
CLEARCX;
EXPLODEXSP;
switch (xc) {
case IEEE754_CLASS_SNAN:
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
case IEEE754_CLASS_ZERO:
*eptr = 0;
return x;
case IEEE754_CLASS_DNORM:
SPDNORMX;
break;
case IEEE754_CLASS_NORM:
break;
}
*eptr = xe + 1;
return buildsp(xs, -1 + SP_EBIAS, xm & ~SP_HIDDEN_BIT);
}
