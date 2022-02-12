int ieee754sp_cmp(ieee754sp x, ieee754sp y, int cmp, int sig)
{
COMPXSP;
COMPYSP;
EXPLODEXSP;
EXPLODEYSP;
FLUSHXSP;
FLUSHYSP;
CLEARCX;
if (ieee754sp_isnan(x) || ieee754sp_isnan(y)) {
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
int vx = x.bits;
int vy = y.bits;
if (vx < 0)
vx = -vx ^ SP_SIGN_BIT;
if (vy < 0)
vy = -vy ^ SP_SIGN_BIT;
if (vx < vy)
return (cmp & IEEE754_CLT) != 0;
else if (vx == vy)
return (cmp & IEEE754_CEQ) != 0;
else
return (cmp & IEEE754_CGT) != 0;
}
}
