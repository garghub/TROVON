union ieee754dp ieee754dp_sqrt(union ieee754dp x)
{
struct _ieee754_csr oldcsr;
union ieee754dp y, z, t;
unsigned scalx, yh;
COMPXDP;
EXPLODEXDP;
ieee754_clearcx();
FLUSHXDP;
switch (xc) {
case IEEE754_CLASS_QNAN:
return ieee754dp_nanxcpt(x);
case IEEE754_CLASS_SNAN:
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754dp_nanxcpt(ieee754dp_indef());
case IEEE754_CLASS_ZERO:
return x;
case IEEE754_CLASS_INF:
if (xs) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754dp_nanxcpt(ieee754dp_indef());
}
return x;
case IEEE754_CLASS_DNORM:
DPDNORMX;
case IEEE754_CLASS_NORM:
if (xs) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754dp_nanxcpt(ieee754dp_indef());
}
break;
}
oldcsr = ieee754_csr;
ieee754_csr.mx &= ~IEEE754_INEXACT;
ieee754_csr.sx &= ~IEEE754_INEXACT;
ieee754_csr.rm = FPU_CSR_RN;
scalx = 0;
if (xe > 512) {
xe -= 512;
scalx += 256;
} else if (xe < -512) {
xe += 512;
scalx -= 256;
}
y = x = builddp(0, xe + DP_EBIAS, xm & ~DP_HIDDEN_BIT);
yh = y.bits >> 32;
yh = (yh >> 1) + 0x1ff80000;
yh = yh - table[(yh >> 15) & 31];
y.bits = ((u64) yh << 32) | (y.bits & 0xffffffff);
t = ieee754dp_div(x, y);
y = ieee754dp_add(y, t);
y.bits -= 0x0010000600000000LL;
y.bits &= 0xffffffff00000000LL;
z = t = ieee754dp_mul(y, y);
t.bexp += 0x001;
t = ieee754dp_add(t, z);
z = ieee754dp_mul(ieee754dp_sub(x, z), y);
t = ieee754dp_div(z, ieee754dp_add(t, x));
t.bexp += 0x001;
y = ieee754dp_add(y, t);
ieee754_csr.rm = FPU_CSR_RZ;
ieee754_csr.sx &= ~IEEE754_INEXACT;
t = ieee754dp_div(x, y);
if (ieee754_csr.sx & IEEE754_INEXACT || t.bits != y.bits) {
if (!(ieee754_csr.sx & IEEE754_INEXACT))
t.bits -= 1;
oldcsr.cx |= IEEE754_INEXACT;
oldcsr.sx |= IEEE754_INEXACT;
switch (oldcsr.rm) {
case FPU_CSR_RU:
y.bits += 1;
case FPU_CSR_RN:
t.bits += 1;
break;
}
y = ieee754dp_add(y, t);
scalx -= 1;
}
y.bexp += scalx;
ieee754_csr = oldcsr;
return y;
}
