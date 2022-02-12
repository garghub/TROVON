union ieee754sp ieee754sp_sqrt(union ieee754sp x)
{
int ix, s, q, m, t, i;
unsigned int r;
COMPXSP;
EXPLODEXSP;
ieee754_clearcx();
FLUSHXSP;
switch (xc) {
case IEEE754_CLASS_QNAN:
return ieee754sp_nanxcpt(x);
case IEEE754_CLASS_SNAN:
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(ieee754sp_indef());
case IEEE754_CLASS_ZERO:
return x;
case IEEE754_CLASS_INF:
if (xs) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(ieee754sp_indef());
}
return x;
case IEEE754_CLASS_DNORM:
case IEEE754_CLASS_NORM:
if (xs) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(ieee754sp_indef());
}
break;
}
ix = x.bits;
m = (ix >> 23);
if (m == 0) {
for (i = 0; (ix & 0x00800000) == 0; i++)
ix <<= 1;
m -= i - 1;
}
m -= 127;
ix = (ix & 0x007fffff) | 0x00800000;
if (m & 1)
ix += ix;
m >>= 1;
ix += ix;
q = s = 0;
r = 0x01000000;
while (r != 0) {
t = s + r;
if (t <= ix) {
s = t + r;
ix -= t;
q += r;
}
ix += ix;
r >>= 1;
}
if (ix != 0) {
ieee754_setcx(IEEE754_INEXACT);
switch (ieee754_csr.rm) {
case FPU_CSR_RU:
q += 2;
break;
case FPU_CSR_RN:
q += (q & 1);
break;
}
}
ix = (q >> 1) + 0x3f000000;
ix += (m << 23);
x.bits = ix;
return x;
}
