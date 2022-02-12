int poly1305_init(void *ctx, const unsigned char key[16])
{
poly1305_internal *st = (poly1305_internal *) ctx;
elem64 r0, r1, r2, r3;
#if 0
st->h[0].d = TWO(52)*TWO0;
st->h[1].d = TWO(52)*TWO32;
st->h[2].d = TWO(52)*TWO64;
st->h[3].d = TWO(52)*TWO96;
#else
st->h[0].u = EXP(52+0);
st->h[1].u = EXP(52+32);
st->h[2].u = EXP(52+64);
st->h[3].u = EXP(52+96);
#endif
if (key) {
#if defined(__x86_64__)
u32 mxcsr_orig;
asm volatile ("stmxcsr %0":"=m"(mxcsr_orig));
asm volatile ("ldmxcsr %0"::"m"(mxcsr));
#elif defined(__PPC__)
double fpscr_orig, fpscr = *(double *)&one;
asm volatile ("mffs %0":"=f"(fpscr_orig));
asm volatile ("mtfsf 255,%0"::"f"(fpscr));
#elif defined(__s390x__)
u32 fpc_orig;
asm volatile ("stfpc %0":"=m"(fpc_orig));
asm volatile ("lfpc %0"::"m"(fpc));
#elif defined(__sparc__)
u64 fsr_orig;
asm volatile ("stx %%fsr,%0":"=m"(fsr_orig));
asm volatile ("ldx %0,%%fsr"::"m"(fsr));
#endif
r0.u = EXP(52+0) | (U8TOU32(&key[0]) & 0x0fffffff);
r1.u = EXP(52+32) | (U8TOU32(&key[4]) & 0x0ffffffc);
r2.u = EXP(52+64) | (U8TOU32(&key[8]) & 0x0ffffffc);
r3.u = EXP(52+96) | (U8TOU32(&key[12]) & 0x0ffffffc);
st->r[0] = r0.d - TWO(52)*TWO0;
st->r[2] = r1.d - TWO(52)*TWO32;
st->r[4] = r2.d - TWO(52)*TWO64;
st->r[6] = r3.d - TWO(52)*TWO96;
st->s[0] = st->r[2] * (5.0/TWO130);
st->s[2] = st->r[4] * (5.0/TWO130);
st->s[4] = st->r[6] * (5.0/TWO130);
st->r[1] = (st->r[0] + TWO(52)*TWO(16)*TWO0) -
TWO(52)*TWO(16)*TWO0;
st->r[0] -= st->r[1];
st->r[3] = (st->r[2] + TWO(52)*TWO(16)*TWO32) -
TWO(52)*TWO(16)*TWO32;
st->r[2] -= st->r[3];
st->r[5] = (st->r[4] + TWO(52)*TWO(16)*TWO64) -
TWO(52)*TWO(16)*TWO64;
st->r[4] -= st->r[5];
st->r[7] = (st->r[6] + TWO(52)*TWO(16)*TWO96) -
TWO(52)*TWO(16)*TWO96;
st->r[6] -= st->r[7];
st->s[1] = (st->s[0] + TWO(52)*TWO(16)*TWO0/TWO96) -
TWO(52)*TWO(16)*TWO0/TWO96;
st->s[0] -= st->s[1];
st->s[3] = (st->s[2] + TWO(52)*TWO(16)*TWO32/TWO96) -
TWO(52)*TWO(16)*TWO32/TWO96;
st->s[2] -= st->s[3];
st->s[5] = (st->s[4] + TWO(52)*TWO(16)*TWO64/TWO96) -
TWO(52)*TWO(16)*TWO64/TWO96;
st->s[4] -= st->s[5];
#if defined(__x86_64__)
asm volatile ("ldmxcsr %0"::"m"(mxcsr_orig));
#elif defined(__PPC__)
asm volatile ("mtfsf 255,%0"::"f"(fpscr_orig));
#elif defined(__s390x__)
asm volatile ("lfpc %0"::"m"(fpc_orig));
#elif defined(__sparc__)
asm volatile ("ldx %0,%%fsr"::"m"(fsr_orig));
#endif
}
return 0;
}
void poly1305_blocks(void *ctx, const unsigned char *inp, size_t len,
int padbit)
{
poly1305_internal *st = (poly1305_internal *)ctx;
elem64 in0, in1, in2, in3;
u64 pad = (u64)padbit<<32;
double x0, x1, x2, x3;
double h0lo, h0hi, h1lo, h1hi, h2lo, h2hi, h3lo, h3hi;
double c0lo, c0hi, c1lo, c1hi, c2lo, c2hi, c3lo, c3hi;
const double r0lo = st->r[0];
const double r0hi = st->r[1];
const double r1lo = st->r[2];
const double r1hi = st->r[3];
const double r2lo = st->r[4];
const double r2hi = st->r[5];
const double r3lo = st->r[6];
const double r3hi = st->r[7];
const double s1lo = st->s[0];
const double s1hi = st->s[1];
const double s2lo = st->s[2];
const double s2hi = st->s[3];
const double s3lo = st->s[4];
const double s3hi = st->s[5];
#if defined(__x86_64__)
u32 mxcsr_orig;
asm volatile ("stmxcsr %0":"=m"(mxcsr_orig));
asm volatile ("ldmxcsr %0"::"m"(mxcsr));
#elif defined(__PPC__)
double fpscr_orig, fpscr = *(double *)&one;
asm volatile ("mffs %0":"=f"(fpscr_orig));
asm volatile ("mtfsf 255,%0"::"f"(fpscr));
#elif defined(__s390x__)
u32 fpc_orig;
asm volatile ("stfpc %0":"=m"(fpc_orig));
asm volatile ("lfpc %0"::"m"(fpc));
#elif defined(__sparc__)
u64 fsr_orig;
asm volatile ("stx %%fsr,%0":"=m"(fsr_orig));
asm volatile ("ldx %0,%%fsr"::"m"(fsr));
#endif
h0lo = st->h[0].d - TWO(52)*TWO0;
h1lo = st->h[1].d - TWO(52)*TWO32;
h2lo = st->h[2].d - TWO(52)*TWO64;
h3lo = st->h[3].d - TWO(52)*TWO96;
#ifdef __clang__
h0hi = 0;
h1hi = 0;
h2hi = 0;
h3hi = 0;
#else
in0.u = EXP(52+0) | U8TOU32(&inp[0]);
in1.u = EXP(52+32) | U8TOU32(&inp[4]);
in2.u = EXP(52+64) | U8TOU32(&inp[8]);
in3.u = EXP(52+96) | U8TOU32(&inp[12]) | pad;
x0 = in0.d - TWO(52)*TWO0;
x1 = in1.d - TWO(52)*TWO32;
x2 = in2.d - TWO(52)*TWO64;
x3 = in3.d - TWO(52)*TWO96;
x0 += h0lo;
x1 += h1lo;
x2 += h2lo;
x3 += h3lo;
goto fast_entry;
#endif
do {
in0.u = EXP(52+0) | U8TOU32(&inp[0]);
in1.u = EXP(52+32) | U8TOU32(&inp[4]);
in2.u = EXP(52+64) | U8TOU32(&inp[8]);
in3.u = EXP(52+96) | U8TOU32(&inp[12]) | pad;
x0 = in0.d - TWO(52)*TWO0;
x1 = in1.d - TWO(52)*TWO32;
x2 = in2.d - TWO(52)*TWO64;
x3 = in3.d - TWO(52)*TWO96;
h0lo += x0;
h0hi += x1;
h2lo += x2;
h2hi += x3;
c0lo = (h0lo + TWO(52)*TWO32) - TWO(52)*TWO32;
c1lo = (h1lo + TWO(52)*TWO64) - TWO(52)*TWO64;
c2lo = (h2lo + TWO(52)*TWO96) - TWO(52)*TWO96;
c3lo = (h3lo + TWO(52)*TWO130) - TWO(52)*TWO130;
c0hi = (h0hi + TWO(52)*TWO32) - TWO(52)*TWO32;
c1hi = (h1hi + TWO(52)*TWO64) - TWO(52)*TWO64;
c2hi = (h2hi + TWO(52)*TWO96) - TWO(52)*TWO96;
c3hi = (h3hi + TWO(52)*TWO130) - TWO(52)*TWO130;
x1 = (h1lo - c1lo) + c0lo;
x2 = (h2lo - c2lo) + c1lo;
x3 = (h3lo - c3lo) + c2lo;
x0 = (h0lo - c0lo) + c3lo * (5.0/TWO130);
x1 += (h1hi - c1hi) + c0hi;
x2 += (h2hi - c2hi) + c1hi;
x3 += (h3hi - c3hi) + c2hi;
x0 += (h0hi - c0hi) + c3hi * (5.0/TWO130);
#ifndef __clang__
fast_entry:
#endif
h0lo = s3lo * x1 + s2lo * x2 + s1lo * x3 + r0lo * x0;
h1lo = r0lo * x1 + s3lo * x2 + s2lo * x3 + r1lo * x0;
h2lo = r1lo * x1 + r0lo * x2 + s3lo * x3 + r2lo * x0;
h3lo = r2lo * x1 + r1lo * x2 + r0lo * x3 + r3lo * x0;
h0hi = s3hi * x1 + s2hi * x2 + s1hi * x3 + r0hi * x0;
h1hi = r0hi * x1 + s3hi * x2 + s2hi * x3 + r1hi * x0;
h2hi = r1hi * x1 + r0hi * x2 + s3hi * x3 + r2hi * x0;
h3hi = r2hi * x1 + r1hi * x2 + r0hi * x3 + r3hi * x0;
inp += 16;
len -= 16;
} while (len >= 16);
c0lo = (h0lo + TWO(52)*TWO32) - TWO(52)*TWO32;
c1lo = (h1lo + TWO(52)*TWO64) - TWO(52)*TWO64;
c2lo = (h2lo + TWO(52)*TWO96) - TWO(52)*TWO96;
c3lo = (h3lo + TWO(52)*TWO130) - TWO(52)*TWO130;
c0hi = (h0hi + TWO(52)*TWO32) - TWO(52)*TWO32;
c1hi = (h1hi + TWO(52)*TWO64) - TWO(52)*TWO64;
c2hi = (h2hi + TWO(52)*TWO96) - TWO(52)*TWO96;
c3hi = (h3hi + TWO(52)*TWO130) - TWO(52)*TWO130;
x1 = (h1lo - c1lo) + c0lo;
x2 = (h2lo - c2lo) + c1lo;
x3 = (h3lo - c3lo) + c2lo;
x0 = (h0lo - c0lo) + c3lo * (5.0/TWO130);
x1 += (h1hi - c1hi) + c0hi;
x2 += (h2hi - c2hi) + c1hi;
x3 += (h3hi - c3hi) + c2hi;
x0 += (h0hi - c0hi) + c3hi * (5.0/TWO130);
st->h[1].d = x1 + TWO(52)*TWO32;
st->h[2].d = x2 + TWO(52)*TWO64;
st->h[3].d = x3 + TWO(52)*TWO96;
st->h[0].d = x0 + TWO(52)*TWO0;
#if defined(__x86_64__)
asm volatile ("ldmxcsr %0"::"m"(mxcsr_orig));
#elif defined(__PPC__)
asm volatile ("mtfsf 255,%0"::"f"(fpscr_orig));
#elif defined(__s390x__)
asm volatile ("lfpc %0"::"m"(fpc_orig));
#elif defined(__sparc__)
asm volatile ("ldx %0,%%fsr"::"m"(fsr_orig));
#endif
}
void poly1305_emit(void *ctx, unsigned char mac[16], const u32 nonce[4])
{
poly1305_internal *st = (poly1305_internal *) ctx;
u64 h0, h1, h2, h3, h4;
u32 g0, g1, g2, g3, g4;
u64 t;
u32 mask;
h0 = st->h[0].u & 0x000fffffffffffffULL;
h1 = st->h[1].u & 0x000fffffffffffffULL;
h2 = st->h[2].u & 0x000fffffffffffffULL;
h3 = st->h[3].u & 0x000fffffffffffffULL;
h4 = h3>>32; h3 &= 0xffffffffU;
g4 = h4&-4;
h4 &= 3;
g4 += g4>>2;
h0 += g4;
h1 += h0>>32; h0 &= 0xffffffffU;
h2 += h1>>32; h1 &= 0xffffffffU;
h3 += h2>>32; h2 &= 0xffffffffU;
g0 = (u32)(t = h0 + 5);
g1 = (u32)(t = h1 + (t >> 32));
g2 = (u32)(t = h2 + (t >> 32));
g3 = (u32)(t = h3 + (t >> 32));
g4 = h4 + (u32)(t >> 32);
mask = 0 - (g4 >> 2);
g0 &= mask;
g1 &= mask;
g2 &= mask;
g3 &= mask;
mask = ~mask;
g0 |= (h0 & mask);
g1 |= (h1 & mask);
g2 |= (h2 & mask);
g3 |= (h3 & mask);
g0 = (u32)(t = (u64)g0 + nonce[0]);
g1 = (u32)(t = (u64)g1 + (t >> 32) + nonce[1]);
g2 = (u32)(t = (u64)g2 + (t >> 32) + nonce[2]);
g3 = (u32)(t = (u64)g3 + (t >> 32) + nonce[3]);
U32TO8(mac + 0, g0);
U32TO8(mac + 4, g1);
U32TO8(mac + 8, g2);
U32TO8(mac + 12, g3);
}
