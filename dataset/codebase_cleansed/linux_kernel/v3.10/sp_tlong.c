s64 ieee754sp_tlong(ieee754sp x)
{
COMPXDP;
CLEARCX;
EXPLODEXSP;
FLUSHXSP;
switch (xc) {
case IEEE754_CLASS_SNAN:
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
SETCX(IEEE754_INVALID_OPERATION);
return ieee754di_xcpt(ieee754di_indef(), "sp_tlong", x);
case IEEE754_CLASS_ZERO:
return 0;
case IEEE754_CLASS_DNORM:
case IEEE754_CLASS_NORM:
break;
}
if (xe >= 63) {
if (xe == 63 && xs && xm == SP_HIDDEN_BIT)
return -0x8000000000000000LL;
SETCX(IEEE754_INVALID_OPERATION);
return ieee754di_xcpt(ieee754di_indef(), "sp_tlong", x);
}
if (xe > SP_MBITS) {
xm <<= xe - SP_MBITS;
} else if (xe < SP_MBITS) {
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
residue = xm << (32 - SP_MBITS + xe);
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
if ((xm >> 63) != 0) {
SETCX(IEEE754_INVALID_OPERATION);
return ieee754di_xcpt(ieee754di_indef(), "sp_tlong", x);
}
if (round || sticky)
SETCX(IEEE754_INEXACT);
}
if (xs)
return -xm;
else
return xm;
}
u64 ieee754sp_tulong(ieee754sp x)
{
ieee754sp hb = ieee754sp_1e63();
if (ieee754sp_lt(x, hb))
return (u64) ieee754sp_tlong(x);
return (u64) ieee754sp_tlong(ieee754sp_sub(x, hb)) |
(1ULL << 63);
}
