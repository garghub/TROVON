s64 ieee754dp_tlong(ieee754dp x)
{
COMPXDP;
CLEARCX;
EXPLODEXDP;
FLUSHXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
SETCX(IEEE754_INVALID_OPERATION);
return ieee754di_xcpt(ieee754di_indef(), "dp_tlong", x);
case IEEE754_CLASS_ZERO:
return 0;
case IEEE754_CLASS_DNORM:
case IEEE754_CLASS_NORM:
break;
}
if (xe >= 63) {
if (xe == 63 && xs && xm == DP_HIDDEN_BIT)
return -0x8000000000000000LL;
SETCX(IEEE754_INVALID_OPERATION);
return ieee754di_xcpt(ieee754di_indef(), "dp_tlong", x);
}
if (xe > DP_MBITS) {
xm <<= xe - DP_MBITS;
} else if (xe < DP_MBITS) {
u64 residue;
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
residue <<= 63 - DP_MBITS;
round = (residue >> 63) != 0;
sticky = (residue << 1) != 0;
xm >>= DP_MBITS - xe;
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
return ieee754di_xcpt(ieee754di_indef(), "dp_tlong", x);
}
if (round || sticky)
SETCX(IEEE754_INEXACT);
}
if (xs)
return -xm;
else
return xm;
}
u64 ieee754dp_tulong(ieee754dp x)
{
ieee754dp hb = ieee754dp_1e63();
if (ieee754dp_lt(x, hb))
return (u64) ieee754dp_tlong(x);
return (u64) ieee754dp_tlong(ieee754dp_sub(x, hb)) |
(1ULL << 63);
}
