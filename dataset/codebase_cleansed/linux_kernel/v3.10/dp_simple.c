int ieee754dp_finite(ieee754dp x)
{
return DPBEXP(x) != DP_EMAX + 1 + DP_EBIAS;
}
ieee754dp ieee754dp_copysign(ieee754dp x, ieee754dp y)
{
CLEARCX;
DPSIGN(x) = DPSIGN(y);
return x;
}
ieee754dp ieee754dp_neg(ieee754dp x)
{
COMPXDP;
EXPLODEXDP;
CLEARCX;
FLUSHXDP;
DPSIGN(x) ^= 1;
if (xc == IEEE754_CLASS_SNAN) {
ieee754dp y = ieee754dp_indef();
SETCX(IEEE754_INVALID_OPERATION);
DPSIGN(y) = DPSIGN(x);
return ieee754dp_nanxcpt(y, "neg");
}
return x;
}
ieee754dp ieee754dp_abs(ieee754dp x)
{
COMPXDP;
EXPLODEXDP;
CLEARCX;
FLUSHXDP;
DPSIGN(x) = 0;
if (xc == IEEE754_CLASS_SNAN) {
SETCX(IEEE754_INVALID_OPERATION);
return ieee754dp_nanxcpt(ieee754dp_indef(), "abs");
}
return x;
}
