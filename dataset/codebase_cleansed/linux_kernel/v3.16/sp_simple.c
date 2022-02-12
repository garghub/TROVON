union ieee754sp ieee754sp_neg(union ieee754sp x)
{
COMPXSP;
EXPLODEXSP;
ieee754_clearcx();
FLUSHXSP;
SPSIGN(x) ^= 1;
if (xc == IEEE754_CLASS_SNAN) {
union ieee754sp y = ieee754sp_indef();
ieee754_setcx(IEEE754_INVALID_OPERATION);
SPSIGN(y) = SPSIGN(x);
return ieee754sp_nanxcpt(y);
}
return x;
}
union ieee754sp ieee754sp_abs(union ieee754sp x)
{
COMPXSP;
EXPLODEXSP;
ieee754_clearcx();
FLUSHXSP;
SPSIGN(x) = 0;
if (xc == IEEE754_CLASS_SNAN) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(ieee754sp_indef());
}
return x;
}
