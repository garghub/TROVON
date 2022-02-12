union ieee754dp ieee754dp_neg(union ieee754dp x)
{
COMPXDP;
EXPLODEXDP;
ieee754_clearcx();
FLUSHXDP;
DPSIGN(x) ^= 1;
if (xc == IEEE754_CLASS_SNAN) {
union ieee754dp y = ieee754dp_indef();
ieee754_setcx(IEEE754_INVALID_OPERATION);
DPSIGN(y) = DPSIGN(x);
return ieee754dp_nanxcpt(y);
}
return x;
}
union ieee754dp ieee754dp_abs(union ieee754dp x)
{
COMPXDP;
EXPLODEXDP;
ieee754_clearcx();
FLUSHXDP;
DPSIGN(x) = 0;
if (xc == IEEE754_CLASS_SNAN) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754dp_nanxcpt(ieee754dp_indef());
}
return x;
}
