int ieee754sp_cmp(union ieee754sp x, union ieee754sp y, int cmp, int sig)
{
int vx;
int vy;
COMPXSP;
COMPYSP;
EXPLODEXSP;
EXPLODEYSP;
FLUSHXSP;
FLUSHYSP;
ieee754_clearcx();
if (ieee754_class_nan(xc) || ieee754_class_nan(yc)) {
if (sig ||
xc == IEEE754_CLASS_SNAN || yc == IEEE754_CLASS_SNAN)
ieee754_setcx(IEEE754_INVALID_OPERATION);
return (cmp & IEEE754_CUN) != 0;
} else {
vx = x.bits;
vy = y.bits;
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
