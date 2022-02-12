int ieee754dp_tint(union ieee754dp x)
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
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754si_indef();
case IEEE754_CLASS_INF:
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754si_overflow(xs);
case IEEE754_CLASS_ZERO:
return 0;
case IEEE754_CLASS_DNORM:
case IEEE754_CLASS_NORM:
break;
}
if (xe > 31) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754si_overflow(xs);
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
residue = xm << (64 - DP_FBITS + xe);
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
if ((xm >> 31) != 0 && (xs == 0 || xm != 0x80000000)) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754si_overflow(xs);
}
if (round || sticky)
ieee754_setcx(IEEE754_INEXACT);
}
if (xs)
return -xm;
else
return xm;
}
