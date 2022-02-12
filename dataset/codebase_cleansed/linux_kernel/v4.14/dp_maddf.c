void srl128(u64 *hptr, u64 *lptr, int count)
{
u64 low;
if (count >= 128) {
*lptr = *hptr != 0 || *lptr != 0;
*hptr = 0;
} else if (count >= 64) {
if (count == 64) {
*lptr = *hptr | (*lptr != 0);
} else {
low = *lptr;
*lptr = *hptr >> (count - 64);
*lptr |= (*hptr << (128 - count)) != 0 || low != 0;
}
*hptr = 0;
} else {
low = *lptr;
*lptr = low >> count | *hptr << (64 - count);
*lptr |= (low << (64 - count)) != 0;
*hptr = *hptr >> count;
}
}
static union ieee754dp _dp_maddf(union ieee754dp z, union ieee754dp x,
union ieee754dp y, enum maddf_flags flags)
{
int re;
int rs;
unsigned lxm;
unsigned hxm;
unsigned lym;
unsigned hym;
u64 lrm;
u64 hrm;
u64 lzm;
u64 hzm;
u64 t;
u64 at;
int s;
COMPXDP;
COMPYDP;
COMPZDP;
EXPLODEXDP;
EXPLODEYDP;
EXPLODEZDP;
FLUSHXDP;
FLUSHYDP;
FLUSHZDP;
ieee754_clearcx();
if (zc == IEEE754_CLASS_SNAN)
return ieee754dp_nanxcpt(z);
if (xc == IEEE754_CLASS_SNAN)
return ieee754dp_nanxcpt(x);
if (yc == IEEE754_CLASS_SNAN)
return ieee754dp_nanxcpt(y);
if (zc == IEEE754_CLASS_QNAN)
return z;
if (xc == IEEE754_CLASS_QNAN)
return x;
if (yc == IEEE754_CLASS_QNAN)
return y;
if (zc == IEEE754_CLASS_DNORM)
DPDNORMZ;
switch (CLPAIR(xc, yc)) {
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_INF):
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754dp_indef();
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_INF):
if ((zc == IEEE754_CLASS_INF) &&
((!(flags & MADDF_NEGATE_PRODUCT) && (zs != (xs ^ ys))) ||
((flags & MADDF_NEGATE_PRODUCT) && (zs == (xs ^ ys))))) {
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754dp_indef();
}
if (flags & MADDF_NEGATE_PRODUCT)
return ieee754dp_inf(1 ^ (xs ^ ys));
else
return ieee754dp_inf(xs ^ ys);
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_ZERO):
if (zc == IEEE754_CLASS_INF)
return ieee754dp_inf(zs);
if (zc == IEEE754_CLASS_ZERO) {
if ((!(flags & MADDF_NEGATE_PRODUCT)
&& (zs == (xs ^ ys))) ||
((flags & MADDF_NEGATE_PRODUCT)
&& (zs != (xs ^ ys))))
return z;
return ieee754dp_zero(ieee754_csr.rm == FPU_CSR_RD);
}
return z;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_DNORM):
DPDNORMX;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_DNORM):
if (zc == IEEE754_CLASS_INF)
return ieee754dp_inf(zs);
DPDNORMY;
break;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_NORM):
if (zc == IEEE754_CLASS_INF)
return ieee754dp_inf(zs);
DPDNORMX;
break;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_NORM):
if (zc == IEEE754_CLASS_INF)
return ieee754dp_inf(zs);
}
assert(xm & DP_HIDDEN_BIT);
assert(ym & DP_HIDDEN_BIT);
re = xe + ye;
rs = xs ^ ys;
if (flags & MADDF_NEGATE_PRODUCT)
rs ^= 1;
xm <<= 64 - (DP_FBITS + 1);
ym <<= 64 - (DP_FBITS + 1);
#define DPXMULT(x, y) ((u64)(x) * (u64)y)
lxm = xm;
hxm = xm >> 32;
lym = ym;
hym = ym >> 32;
lrm = DPXMULT(lxm, lym);
hrm = DPXMULT(hxm, hym);
t = DPXMULT(lxm, hym);
at = lrm + (t << 32);
hrm += at < lrm;
lrm = at;
hrm = hrm + (t >> 32);
t = DPXMULT(hxm, lym);
at = lrm + (t << 32);
hrm += at < lrm;
lrm = at;
hrm = hrm + (t >> 32);
if ((int64_t)hrm < 0) {
lrm = (hrm << 63) | (lrm >> 1);
hrm = hrm >> 1;
re++;
}
assert(hrm & (1 << 62));
if (zc == IEEE754_CLASS_ZERO) {
srl128(&hrm, &lrm, (126 - 55));
return ieee754dp_format(rs, re, lrm);
}
lzm = 0;
hzm = zm << 10;
assert(hzm & (1 << 62));
if (ze > re) {
s = ze - re;
srl128(&hrm, &lrm, s);
re += s;
} else if (re > ze) {
s = re - ze;
srl128(&hzm, &lzm, s);
ze += s;
}
assert(ze == re);
assert(ze <= DP_EMAX);
if (zs == rs) {
hzm = hzm + hrm + (lzm > (lzm + lrm));
lzm = lzm + lrm;
if ((int64_t)hzm < 0) {
srl128(&hzm, &lzm, 1);
ze++;
}
} else {
if (hzm > hrm || (hzm == hrm && lzm >= lrm)) {
hzm = hzm - hrm - (lzm < lrm);
lzm = lzm - lrm;
} else {
hzm = hrm - hzm - (lrm < lzm);
lzm = lrm - lzm;
zs = rs;
}
if (lzm == 0 && hzm == 0)
return ieee754dp_zero(ieee754_csr.rm == FPU_CSR_RD);
if (hzm == 0) {
if ((int64_t)lzm < 0) {
hzm = lzm >> 1;
lzm = lzm << 63;
ze -= 63;
} else {
hzm = lzm;
lzm = 0;
ze -= 64;
}
}
t = 0;
while ((hzm >> (62 - t)) == 0)
t++;
assert(t <= 62);
if (t) {
hzm = hzm << t | lzm >> (64 - t);
lzm = lzm << t;
ze -= t;
}
}
srl128(&hzm, &lzm, (126 - 55));
return ieee754dp_format(zs, ze, lzm);
}
union ieee754dp ieee754dp_maddf(union ieee754dp z, union ieee754dp x,
union ieee754dp y)
{
return _dp_maddf(z, x, y, 0);
}
union ieee754dp ieee754dp_msubf(union ieee754dp z, union ieee754dp x,
union ieee754dp y)
{
return _dp_maddf(z, x, y, MADDF_NEGATE_PRODUCT);
}
