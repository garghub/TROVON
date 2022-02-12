s64 ieee754dp_tlong(union ieee754dp x)
{
u64 residue;
int round;
int sticky;
int odd;
COMPXDP;
ieee754_clearcx();
EXPLODEXDP;
FLUSHXDP;
switch (xc) {
case IEEE754_CLASS_SNAN:
case IEEE754_CLASS_QNAN:
case IEEE754_CLASS_INF:
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754di_indef();
case IEEE754_CLASS_ZERO:
return 0;
case IEEE754_CLASS_DNORM:
case IEEE754_CLASS_NORM:
break;
}
if (xe >= 63) {
if (xe == 63 && xs && xm == DP_HIDDEN_BIT)
return -0x8000000000000000LL;
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754di_indef();
}
if (xe > DP_FBITS) {
xm <<= xe - DP_FBITS;
} else if (xe < DP_FBITS) {
if (xe < -1) {
residue = xm;
round = 0;
sticky = residue != 0;
xm = 0;
} else {
residue = xm << (xe + 1);
residue <<= 63 - DP_FBITS;
round = (residue >> 63) != 0;
sticky = (residue << 1) != 0;
xm >>= DP_FBITS - xe;
}
odd = (xm & 0x1) != 0x0;
switch (ieee754_csr.rm) {
case FPU_CSR_RN:
if (round && (sticky || odd))
xm++;
break;
case FPU_CSR_RZ:
break;
case FPU_CSR_RU:
if ((round || sticky) && !xs)
xm++;
break;
case FPU_CSR_RD:
if ((round || sticky) && xs)
xm++;
break;
}
if ((xm >> 63) != 0) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754di_indef();
}
if (round || sticky)
ieee754_setcx(IEEE754_INEXACT);
}
if (xs)
return -xm;
else
return xm;
}
