int ieee754dp_cmp(ieee754dp x, ieee754dp y, int cmp, int sig)
{
COMPXDP;
COMPYDP;
EXPLODEXDP;
EXPLODEYDP;
FLUSHXDP;
FLUSHYDP;
CLEARCX;
if (ieee754dp_isnan(x) || ieee754dp_isnan(y)) {
if (sig || xc == IEEE754_CLASS_SNAN || yc == IEEE754_CLASS_SNAN)
SETCX(IEEE754_INVALID_OPERATION);
if (cmp & IEEE754_CUN)
return 1;
if (cmp & (IEEE754_CLT | IEEE754_CGT)) {
if (sig && SETANDTESTCX(IEEE754_INVALID_OPERATION))
return ieee754si_xcpt(0, "fcmpf", x);
}
return 0;
} else {
s64 vx = x.bits;
s64 vy = y.bits;
if (vx < 0)
vx = -vx ^ DP_SIGN_BIT;
if (vy < 0)
vy = -vy ^ DP_SIGN_BIT;
if (vx < vy)
return (cmp & IEEE754_CLT) != 0;
else if (vx == vy)
return (cmp & IEEE754_CEQ) != 0;
else
return (cmp & IEEE754_CGT) != 0;
}
}
