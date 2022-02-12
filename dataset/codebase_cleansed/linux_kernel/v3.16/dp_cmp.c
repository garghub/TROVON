int ieee754dp_cmp(union ieee754dp x, union ieee754dp y, int cmp, int sig)
{
s64 vx;
s64 vy;
COMPXDP;
COMPYDP;
EXPLODEXDP;
EXPLODEYDP;
FLUSHXDP;
FLUSHYDP;
ieee754_clearcx();
if (ieee754dp_isnan(x) || ieee754dp_isnan(y)) {
if (sig || xc == IEEE754_CLASS_SNAN || yc == IEEE754_CLASS_SNAN)
ieee754_setcx(IEEE754_INVALID_OPERATION);
if (cmp & IEEE754_CUN)
return 1;
if (cmp & (IEEE754_CLT | IEEE754_CGT)) {
if (sig && ieee754_setandtestcx(IEEE754_INVALID_OPERATION))
return 0;
}
return 0;
} else {
vx = x.bits;
vy = y.bits;
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
