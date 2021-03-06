int ieee754sp_tint(ieee754sp x)
{
COMPXSP;
CLEARCX;
EXPLODEXSP;
FLUSHXSP;
switch (xc) {
case IEEE754_CLASS_SNAN:
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
SETCX(IEEE754_INVALID_OPERATION);
return ieee754si_xcpt(ieee754si_indef(), "sp_tint", x);
case IEEE754_CLASS_ZERO:
return 0;
case IEEE754_CLASS_DNORM:
case IEEE754_CLASS_NORM:
break;
}
if (xe >= 31) {
if (xe == 31 && xs && xm == SP_HIDDEN_BIT)
return -0x80000000;
SETCX(IEEE754_INVALID_OPERATION);
return ieee754si_xcpt(ieee754si_indef(), "sp_tint", x);
}
if (xe > SP_MBITS) {
xm <<= xe - SP_MBITS;
} else {
u32 residue;
int round;
int sticky;
int odd;
if (xe < -1) {
residue = xm;
round = 0;
sticky = residue != 0;
xm = 0;
} else {
residue = xm << (xe + 1);
residue <<= 31 - SP_MBITS;
round = (residue >> 31) != 0;
sticky = (residue << 1) != 0;
xm >>= SP_MBITS - xe;
}
odd = (xm & 0x1) != 0x0;
switch (ieee754_csr.rm) {
case IEEE754_RN:
if (round && (sticky || odd))
xm++;
break;
case IEEE754_RZ:
break;
case IEEE754_RU:
if ((round || sticky) && !xs)
xm++;
break;
case IEEE754_RD:
if ((round || sticky) && xs)
xm++;
break;
}
if ((xm >> 31) != 0) {
SETCX(IEEE754_INVALID_OPERATION);
return ieee754si_xcpt(ieee754si_indef(), "sp_tint", x);
}
if (round || sticky)
SETCX(IEEE754_INEXACT);
}
if (xs)
return -xm;
else
return xm;
}
unsigned int ieee754sp_tuns(ieee754sp x)
{
ieee754sp hb = ieee754sp_1e31();
if (ieee754sp_lt(x, hb))
return (unsigned) ieee754sp_tint(x);
return (unsigned) ieee754sp_tint(ieee754sp_sub(x, hb)) |
((unsigned) 1 << 31);
}
