ieee754dp ieee754dp_logb(ieee754dp x)
{
COMPXDP;
CLEARCX;
EXPLODEXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
return ieee754dp_nanxcpt(x, "logb", x);
case IEEE754_CLASS_QNAN:
return x;
case IEEE754_CLASS_INF:
return ieee754dp_inf(0);
case IEEE754_CLASS_ZERO:
return ieee754dp_inf(1);
case IEEE754_CLASS_DNORM:
DPDNORMX;
break;
case IEEE754_CLASS_NORM:
break;
}
return ieee754dp_fint(xe);
}
