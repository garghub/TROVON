ieee754sp ieee754sp_logb(ieee754sp x)
{
COMPXSP;
CLEARCX;
EXPLODEXSP;
switch (xc) {
case IEEE754_CLASS_SNAN:
return ieee754sp_nanxcpt(x, "logb", x);
case IEEE754_CLASS_QNAN:
return x;
case IEEE754_CLASS_INF:
return ieee754sp_inf(0);
case IEEE754_CLASS_ZERO:
return ieee754sp_inf(1);
case IEEE754_CLASS_DNORM:
SPDNORMX;
break;
case IEEE754_CLASS_NORM:
break;
}
return ieee754sp_fint(xe);
}
