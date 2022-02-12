union ieee754sp ieee754sp_maddf(union ieee754sp z, union ieee754sp x,
union ieee754sp y)
{
int re;
int rs;
unsigned rm;
unsigned short lxm;
unsigned short hxm;
unsigned short lym;
unsigned short hym;
unsigned lrm;
unsigned hrm;
unsigned t;
unsigned at;
int s;
COMPXSP;
COMPYSP;
u32 zm; int ze; int zs __maybe_unused; int zc;
EXPLODEXSP;
EXPLODEYSP;
EXPLODESP(z, zc, zs, ze, zm)
FLUSHXSP;
FLUSHYSP;
FLUSHSP(z, zc, zs, ze, zm);
ieee754_clearcx();
switch (zc) {
case IEEE754_CLASS_SNAN:
ieee754_setcx(IEEE754_INVALID_OPERATION);
return ieee754sp_nanxcpt(z);
case IEEE754_CLASS_DNORM:
SPDNORMx(zm, ze);
}
switch (CLPAIR(xc, yc)) {
case CLPAIR(IEEE754_CLASS_QNAN, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_SNAN):
return ieee754sp_nanxcpt(y);
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_SNAN):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_QNAN):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_SNAN, IEEE754_CLASS_INF):
return ieee754sp_nanxcpt(x);
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
return ieee754sp_indef();
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_INF):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_INF, IEEE754_CLASS_INF):
if (zc == IEEE754_CLASS_QNAN)
return z;
return ieee754sp_inf(xs ^ ys);
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_NORM):
case CLPAIR(IEEE754_CLASS_ZERO, IEEE754_CLASS_DNORM):
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_ZERO):
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_ZERO):
if (zc == IEEE754_CLASS_INF)
return ieee754sp_inf(zs);
return z;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_DNORM):
SPDNORMX;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_DNORM):
if (zc == IEEE754_CLASS_QNAN)
return z;
else if (zc == IEEE754_CLASS_INF)
return ieee754sp_inf(zs);
SPDNORMY;
break;
case CLPAIR(IEEE754_CLASS_DNORM, IEEE754_CLASS_NORM):
if (zc == IEEE754_CLASS_QNAN)
return z;
else if (zc == IEEE754_CLASS_INF)
return ieee754sp_inf(zs);
SPDNORMX;
break;
case CLPAIR(IEEE754_CLASS_NORM, IEEE754_CLASS_NORM):
if (zc == IEEE754_CLASS_QNAN)
return z;
else if (zc == IEEE754_CLASS_INF)
return ieee754sp_inf(zs);
}
assert(xm & SP_HIDDEN_BIT);
assert(ym & SP_HIDDEN_BIT);
re = xe + ye;
rs = xs ^ ys;
xm <<= 32 - (SP_FBITS + 1);
ym <<= 32 - (SP_FBITS + 1);
lxm = xm & 0xffff;
hxm = xm >> 16;
lym = ym & 0xffff;
hym = ym >> 16;
lrm = lxm * lym;
hrm = hxm * hym;
t = lxm * hym;
at = lrm + (t << 16);
hrm += at < lrm;
lrm = at;
hrm = hrm + (t >> 16);
t = hxm * lym;
at = lrm + (t << 16);
hrm += at < lrm;
lrm = at;
hrm = hrm + (t >> 16);
rm = hrm | (lrm != 0);
if ((int) rm < 0) {
rm = (rm >> (32 - (SP_FBITS + 1 + 3))) |
((rm << (SP_FBITS + 1 + 3)) != 0);
re++;
} else {
rm = (rm >> (32 - (SP_FBITS + 1 + 3 + 1))) |
((rm << (SP_FBITS + 1 + 3 + 1)) != 0);
}
assert(rm & (SP_HIDDEN_BIT << 3));
assert(zm & SP_HIDDEN_BIT);
zm <<= 3;
if (ze > re) {
s = ze - re;
SPXSRSYn(s);
} else if (re > ze) {
s = re - ze;
SPXSRSYn(s);
}
assert(ze == re);
assert(ze <= SP_EMAX);
if (zs == rs) {
zm = zm + rm;
if (zm >> (SP_FBITS + 1 + 3)) {
SPXSRSX1();
}
} else {
if (zm >= rm) {
zm = zm - rm;
} else {
zm = rm - zm;
zs = rs;
}
if (zm == 0)
return ieee754sp_zero(ieee754_csr.rm == FPU_CSR_RD);
while ((zm >> (SP_MBITS + 3)) == 0) {
zm <<= 1;
ze--;
}
}
return ieee754sp_format(zs, ze, zm);
}
