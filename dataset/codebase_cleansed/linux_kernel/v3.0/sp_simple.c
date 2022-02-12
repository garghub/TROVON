int ieee754sp_finite(ieee754sp x)
{
return SPBEXP(x) != SP_EMAX + 1 + SP_EBIAS;
}
ieee754sp ieee754sp_copysign(ieee754sp x, ieee754sp y)
{
CLEARCX;
SPSIGN(x) = SPSIGN(y);
return x;
}
ieee754sp ieee754sp_neg(ieee754sp x)
{
COMPXSP;
EXPLODEXSP;
CLEARCX;
FLUSHXSP;
SPSIGN(x) ^= 1;
if (xc == IEEE754_CLASS_SNAN) {
ieee754sp y = ieee754sp_indef();
SETCX(IEEE754_INVALID_OPERATION);
SPSIGN(y) = SPSIGN(x);
return ieee754sp_nanxcpt(y, "neg");
}
return x;
}
ieee754sp ieee754sp_abs(ieee754sp x)
{
COMPXSP;
EXPLODEXSP;
CLEARCX;
FLUSHXSP;
SPSIGN(x) = 0;
if (xc == IEEE754_CLASS_SNAN) {
SETCX(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(ieee754sp_indef(), "abs");
}
return x;
}
