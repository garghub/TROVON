ieee754sp ieee754sp_modf(ieee754sp x, ieee754sp *ip)
{
COMPXSP;
CLEARCX;
EXPLODEXSP;
switch (xc) {
case IEEE754_CLASS_SNAN:
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
case IEEE754_CLASS_ZERO:
*ip = x;
return x;
case IEEE754_CLASS_DNORM:
*ip = ieee754sp_zero(xs);
return x;
case IEEE754_CLASS_NORM:
break;
}
if (xe < 0) {
*ip = ieee754sp_zero(xs);
return x;
}
if (xe >= SP_MBITS) {
*ip = x;
return ieee754sp_zero(xs);
}
*ip = buildsp(xs, xe + SP_EBIAS,
((xm >> (SP_MBITS - xe)) << (SP_MBITS - xe)) &
~SP_HIDDEN_BIT);
xm = (xm << (32 - (SP_MBITS - xe))) >> (32 - (SP_MBITS - xe));
if (xm == 0)
return ieee754sp_zero(xs);
while ((xm >> SP_MBITS) == 0) {
xm <<= 1;
xe--;
}
return buildsp(xs, xe + SP_EBIAS, xm & ~SP_HIDDEN_BIT);
}
