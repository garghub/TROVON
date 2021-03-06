union ieee754sp ieee754sp_sub(union ieee754sp x, union ieee754sp y)
{
int s;
COMPXSP;
COMPYSP;
EXPLODEXSP;
EXPLODEYSP;
ieee754_clearcx();
FLUSHXSP;
FLUSHYSP;
switch (CLPAIR(xc, yc)) {
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_QNAN):
case CLPAIR(IEEE754_CLASS_QNAN, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_INF):
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(ieee754sp_indef());
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_QNAN):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_QNAN):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_QNAN):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_QNAN):
return y;
case CLPAIR(IEEE754_CLASS_QNAN, IEEE754_CLASS_QNAN):
case CLPAIR(IEEE754_CLASS_QNAN, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_QNAN, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_QNAN, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_QNAN, IEEE754_CLASS_INF):
return x;
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_INF):
if (xs != ys)
return x;
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_indef();
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_INF):
return ieee754sp_inf(ys ^ 1);
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_DNORM):
return x;
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_ZERO):
if (xs != ys)
return x;
else
return ieee754sp_zero(ieee754_csr.rm == FPU_CSR_RD);
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_ZERO):
return x;
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_DNORM):
SPSIGN(y) ^= 1;
return y;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_DNORM):
SPDNORMX;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_DNORM):
SPDNORMY;
break;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_NORM):
SPDNORMX;
break;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_NORM):
break;
}
ys ^= 1;
assert(xm & SP_HIDDEN_BIT);
assert(ym & SP_HIDDEN_BIT);
xm <<= 3;
ym <<= 3;
if (xe > ye) {
s = xe - ye;
SPXSRSYn(s);
} else if (ye > xe) {
s = ye - xe;
SPXSRSXn(s);
}
assert(xe == ye);
assert(xe <= SP_EMAX);
if (xs == ys) {
xm = xm + ym;
xe = xe;
xs = xs;
if (xm >> (SP_FBITS + 1 + 3)) {
SPXSRSX1();
}
} else {
if (xm >= ym) {
xm = xm - ym;
xe = xe;
xs = xs;
} else {
xm = ym - xm;
xe = xe;
xs = ys;
}
if (xm == 0) {
if (ieee754_csr.rm == FPU_CSR_RD)
return ieee754sp_zero(1);
else
return ieee754sp_zero(0);
}
while ((xm >> (SP_FBITS + 3)) == 0) {
xm <<= 1;
xe--;
}
}
return ieee754sp_format(xs, xe, xm);
}
