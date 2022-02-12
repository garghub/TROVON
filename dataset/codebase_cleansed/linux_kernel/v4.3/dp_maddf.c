union ieee754dp ieee754dp_maddf(union ieee754dp z, union ieee754dp x,
union ieee754dp y)
{
int re;
int rs;
u64 rm;
unsigned lxm;
unsigned hxm;
unsigned lym;
unsigned hym;
u64 lrm;
u64 hrm;
u64 t;
u64 at;
int s;
COMPXDP;
COMPYDP;
u64 zm; int ze; int zs __maybe_unused; int zc;
EXPLODEXDP;
EXPLODEYDP;
EXPLODEDP(z, zc, zs, ze, zm)
FLUSHXDP;
FLUSHYDP;
FLUSHDP(z, zc, zs, ze, zm);
ieee754_clearcx();
switch (zc) {
case IEEE754_CLASS_SNAN:
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754dp_nanxcpt(z);
case IEEE754_CLASS_DNORM:
DPDNORMx(zm, ze);
}
switch (CLPAIR(xc, yc)) {
case CLPAIR(IEEE754_CLASS_QNAN, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_SNAN):
return ieee754dp_nanxcpt(y);
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_QNAN):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_INF):
return ieee754dp_nanxcpt(x);
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
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_INF):
if (zc == IEEE754_CLASS_QNAN)
return z;
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754dp_indef();
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_INF):
if (zc == IEEE754_CLASS_QNAN)
return z;
return ieee754dp_inf(xs ^ ys);
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_ZERO):
if (zc == IEEE754_CLASS_INF)
return ieee754dp_inf(zs);
return z;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_DNORM):
DPDNORMX;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_DNORM):
if (zc == IEEE754_CLASS_QNAN)
return z;
else if (zc == IEEE754_CLASS_INF)
return ieee754dp_inf(zs);
DPDNORMY;
break;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_NORM):
if (zc == IEEE754_CLASS_QNAN)
return z;
else if (zc == IEEE754_CLASS_INF)
return ieee754dp_inf(zs);
DPDNORMX;
break;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_NORM):
if (zc == IEEE754_CLASS_QNAN)
return z;
else if (zc == IEEE754_CLASS_INF)
return ieee754dp_inf(zs);
}
assert(xm & DP_HIDDEN_BIT);
assert(ym & DP_HIDDEN_BIT);
re = xe + ye;
rs = xs ^ ys;
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
rm = hrm | (lrm != 0);
if ((s64) rm < 0) {
rm = (rm >> (64 - (DP_FBITS + 1 + 3))) |
((rm << (DP_FBITS + 1 + 3)) != 0);
re++;
} else {
rm = (rm >> (64 - (DP_FBITS + 1 + 3 + 1))) |
((rm << (DP_FBITS + 1 + 3 + 1)) != 0);
}
assert(rm & (DP_HIDDEN_BIT << 3));
assert(zm & DP_HIDDEN_BIT);
zm <<= 3;
if (ze > re) {
s = ze - re;
rm = XDPSRS(rm, s);
re += s;
} else if (re > ze) {
s = re - ze;
zm = XDPSRS(zm, s);
ze += s;
}
assert(ze == re);
assert(ze <= DP_EMAX);
if (zs == rs) {
zm = zm + rm;
if (zm >> (DP_FBITS + 1 + 3)) {
zm = XDPSRS1(zm);
ze++;
}
} else {
if (zm >= rm) {
zm = zm - rm;
} else {
zm = rm - zm;
zs = rs;
}
if (zm == 0)
return ieee754dp_zero(ieee754_csr.rm == FPU_CSR_RD);
while ((zm >> (DP_FBITS + 3)) == 0) {
zm <<= 1;
ze--;
}
}
return ieee754dp_format(zs, ze, zm);
}
