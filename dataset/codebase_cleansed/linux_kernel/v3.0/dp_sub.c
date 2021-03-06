ieee754dp ieee754dp_sub(ieee754dp x, ieee754dp y)
{
COMPXDP;
COMPYDP;
EXPLODEXDP;
EXPLODEYDP;
CLEARCX;
FLUSHXDP;
FLUSHYDP;
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
SETCX(IEEE754_INVALID_OPERATION);
return ieee754dp_nanxcpt(ieee754dp_indef(), "sub", x, y);
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
SETCX(IEEE754_INVALID_OPERATION);
return ieee754dp_xcpt(ieee754dp_indef(), "sub", x, y);
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_INF):
return ieee754dp_inf(ys ^ 1);
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_DNORM):
return x;
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_ZERO):
if (xs != ys)
return x;
else
return ieee754dp_zero(ieee754_csr.rm ==
IEEE754_RD);
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_ZERO):
return x;
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_DNORM):
DPSIGN(y) ^= 1;
return y;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_DNORM):
DPDNORMX;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_DNORM):
DPDNORMY;
break;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_NORM):
DPDNORMX;
break;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_NORM):
break;
}
ys ^= 1;
assert(xm & DP_HIDDEN_BIT);
assert(ym & DP_HIDDEN_BIT);
xm <<= 3;
ym <<= 3;
if (xe > ye) {
int s = xe - ye;
ym = XDPSRS(ym, s);
ye += s;
} else if (ye > xe) {
int s = ye - xe;
xm = XDPSRS(xm, s);
xe += s;
}
assert(xe == ye);
assert(xe <= DP_EMAX);
if (xs == ys) {
xm = xm + ym;
xe = xe;
xs = xs;
if (xm >> (DP_MBITS + 1 + 3)) {
xm = XDPSRS1(xm);
xe++;
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
if (ieee754_csr.rm == IEEE754_RD)
return ieee754dp_zero(1);
else
return ieee754dp_zero(0);
}
while ((xm >> (DP_MBITS + 3)) == 0) {
xm <<= 1;
xe--;
}
}
DPNORMRET2(xs, xe, xm, "sub", x, y);
}
