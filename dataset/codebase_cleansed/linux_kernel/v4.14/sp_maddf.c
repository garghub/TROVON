static union ieee754sp _sp_maddf(union ieee754sp z, union ieee754sp x,
union ieee754sp y, enum maddf_flags flags)
{
int re;
int rs;
unsigned rm;
uint64_t rm64;
uint64_t zm64;
int s;
COMPXSP;
COMPYSP;
COMPZSP;
EXPLODEXSP;
EXPLODEYSP;
EXPLODEZSP;
FLUSHXSP;
FLUSHYSP;
FLUSHZSP;
ieee754_clearcx();
if (zc == IEEE754_CLASS_SNAN)
return ieee754sp_nanxcpt(z);
if (xc == IEEE754_CLASS_SNAN)
return ieee754sp_nanxcpt(x);
if (yc == IEEE754_CLASS_SNAN)
return ieee754sp_nanxcpt(y);
if (zc == IEEE754_CLASS_QNAN)
return z;
if (xc == IEEE754_CLASS_QNAN)
return x;
if (yc == IEEE754_CLASS_QNAN)
return y;
if (zc == IEEE754_CLASS_DNORM)
SPDNORMZ;
switch (CLPAIR(xc, yc)) {
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_INF):
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_indef();
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_INF):
if ((zc == IEEE754_CLASS_INF) &&
((!(flags & MADDF_NEGATE_PRODUCT) && (zs != (xs ^ ys))) ||
((flags & MADDF_NEGATE_PRODUCT) && (zs == (xs ^ ys))))) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_indef();
}
if (flags & MADDF_NEGATE_PRODUCT)
return ieee754sp_inf(1 ^ (xs ^ ys));
else
return ieee754sp_inf(xs ^ ys);
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_ZERO):
if (zc == IEEE754_CLASS_INF)
return ieee754sp_inf(zs);
if (zc == IEEE754_CLASS_ZERO) {
if ((!(flags & MADDF_NEGATE_PRODUCT)
&& (zs == (xs ^ ys))) ||
((flags & MADDF_NEGATE_PRODUCT)
&& (zs != (xs ^ ys))))
return z;
return ieee754sp_zero(ieee754_csr.rm == FPU_CSR_RD);
}
return z;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_DNORM):
SPDNORMX;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_DNORM):
if (zc == IEEE754_CLASS_INF)
return ieee754sp_inf(zs);
SPDNORMY;
break;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_NORM):
if (zc == IEEE754_CLASS_INF)
return ieee754sp_inf(zs);
SPDNORMX;
break;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_NORM):
if (zc == IEEE754_CLASS_INF)
return ieee754sp_inf(zs);
}
assert(xm & SP_HIDDEN_BIT);
assert(ym & SP_HIDDEN_BIT);
re = xe + ye;
rs = xs ^ ys;
if (flags & MADDF_NEGATE_PRODUCT)
rs ^= 1;
rm64 = (uint64_t)xm * ym;
rm64 = rm64 << 16;
if ((int64_t) rm64 < 0) {
rm64 = rm64 >> 1;
re++;
}
assert(rm64 & (1 << 62));
if (zc == IEEE754_CLASS_ZERO) {
rm = XSPSRS64(rm64, (62 - 26));
return ieee754sp_format(rs, re, rm);
}
zm64 = (uint64_t)zm << (62 - 23);
assert(zm64 & (1 << 62));
if (ze > re) {
s = ze - re;
rm64 = XSPSRS64(rm64, s);
re += s;
} else if (re > ze) {
s = re - ze;
zm64 = XSPSRS64(zm64, s);
ze += s;
}
assert(ze == re);
assert(ze <= SP_EMAX);
if (zs == rs) {
zm64 = zm64 + rm64;
if ((int64_t)zm64 < 0) {
zm64 = XSPSRS1(zm64);
ze++;
}
} else {
if (zm64 >= rm64) {
zm64 = zm64 - rm64;
} else {
zm64 = rm64 - zm64;
zs = rs;
}
if (zm64 == 0)
return ieee754sp_zero(ieee754_csr.rm == FPU_CSR_RD);
while ((zm64 >> 62) == 0) {
zm64 <<= 1;
ze--;
}
}
zm = XSPSRS64(zm64, (62 - 26));
return ieee754sp_format(zs, ze, zm);
}
union ieee754sp ieee754sp_maddf(union ieee754sp z, union ieee754sp x,
union ieee754sp y)
{
return _sp_maddf(z, x, y, 0);
}
union ieee754sp ieee754sp_msubf(union ieee754sp z, union ieee754sp x,
union ieee754sp y)
{
return _sp_maddf(z, x, y, MADDF_NEGATE_PRODUCT);
}
