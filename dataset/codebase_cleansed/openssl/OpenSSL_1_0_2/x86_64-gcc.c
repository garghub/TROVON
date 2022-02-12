BN_ULONG bn_mul_add_words(BN_ULONG *rp, const BN_ULONG *ap, int num,
BN_ULONG w)
{
BN_ULONG c1 = 0;
if (num <= 0)
return (c1);
while (num & ~3) {
mul_add(rp[0], ap[0], w, c1);
mul_add(rp[1], ap[1], w, c1);
mul_add(rp[2], ap[2], w, c1);
mul_add(rp[3], ap[3], w, c1);
ap += 4;
rp += 4;
num -= 4;
}
if (num) {
mul_add(rp[0], ap[0], w, c1);
if (--num == 0)
return c1;
mul_add(rp[1], ap[1], w, c1);
if (--num == 0)
return c1;
mul_add(rp[2], ap[2], w, c1);
return c1;
}
return (c1);
}
BN_ULONG bn_mul_words(BN_ULONG *rp, const BN_ULONG *ap, int num, BN_ULONG w)
{
BN_ULONG c1 = 0;
if (num <= 0)
return (c1);
while (num & ~3) {
mul(rp[0], ap[0], w, c1);
mul(rp[1], ap[1], w, c1);
mul(rp[2], ap[2], w, c1);
mul(rp[3], ap[3], w, c1);
ap += 4;
rp += 4;
num -= 4;
}
if (num) {
mul(rp[0], ap[0], w, c1);
if (--num == 0)
return c1;
mul(rp[1], ap[1], w, c1);
if (--num == 0)
return c1;
mul(rp[2], ap[2], w, c1);
}
return (c1);
}
void bn_sqr_words(BN_ULONG *r, const BN_ULONG *a, int n)
{
if (n <= 0)
return;
while (n & ~3) {
sqr(r[0], r[1], a[0]);
sqr(r[2], r[3], a[1]);
sqr(r[4], r[5], a[2]);
sqr(r[6], r[7], a[3]);
a += 4;
r += 8;
n -= 4;
}
if (n) {
sqr(r[0], r[1], a[0]);
if (--n == 0)
return;
sqr(r[2], r[3], a[1]);
if (--n == 0)
return;
sqr(r[4], r[5], a[2]);
}
}
BN_ULONG bn_div_words(BN_ULONG h, BN_ULONG l, BN_ULONG d)
{
BN_ULONG ret, waste;
asm("divq %4":"=a"(ret), "=d"(waste)
: "a"(l), "d"(h), "g"(d)
: "cc");
return ret;
}
BN_ULONG bn_add_words(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp,
int n)
{
BN_ULONG ret;
size_t i = 0;
if (n <= 0)
return 0;
asm volatile (" subq %0,%0 \n"
" jmp 1f \n"
".p2align 4 \n"
"1: movq (%4,%2,8),%0 \n"
" adcq (%5,%2,8),%0 \n"
" movq %0,(%3,%2,8) \n"
" lea 1(%2),%2 \n"
" loop 1b \n"
" sbbq %0,%0 \n":"=&r" (ret), "+c"(n),
"+r"(i)
:"r"(rp), "r"(ap), "r"(bp)
:"cc", "memory");
return ret & 1;
}
BN_ULONG bn_sub_words(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp,
int n)
{
BN_ULONG ret;
size_t i = 0;
if (n <= 0)
return 0;
asm volatile (" subq %0,%0 \n"
" jmp 1f \n"
".p2align 4 \n"
"1: movq (%4,%2,8),%0 \n"
" sbbq (%5,%2,8),%0 \n"
" movq %0,(%3,%2,8) \n"
" lea 1(%2),%2 \n"
" loop 1b \n"
" sbbq %0,%0 \n":"=&r" (ret), "+c"(n),
"+r"(i)
:"r"(rp), "r"(ap), "r"(bp)
:"cc", "memory");
return ret & 1;
}
BN_ULONG bn_sub_words(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b, int n)
{
BN_ULONG t1, t2;
int c = 0;
if (n <= 0)
return ((BN_ULONG)0);
for (;;) {
t1 = a[0];
t2 = b[0];
r[0] = (t1 - t2 - c) & BN_MASK2;
if (t1 != t2)
c = (t1 < t2);
if (--n <= 0)
break;
t1 = a[1];
t2 = b[1];
r[1] = (t1 - t2 - c) & BN_MASK2;
if (t1 != t2)
c = (t1 < t2);
if (--n <= 0)
break;
t1 = a[2];
t2 = b[2];
r[2] = (t1 - t2 - c) & BN_MASK2;
if (t1 != t2)
c = (t1 < t2);
if (--n <= 0)
break;
t1 = a[3];
t2 = b[3];
r[3] = (t1 - t2 - c) & BN_MASK2;
if (t1 != t2)
c = (t1 < t2);
if (--n <= 0)
break;
a += 4;
b += 4;
r += 4;
}
return (c);
}
void bn_mul_comba8(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b)
{
BN_ULONG c1, c2, c3;
c1 = 0;
c2 = 0;
c3 = 0;
mul_add_c(a[0], b[0], c1, c2, c3);
r[0] = c1;
c1 = 0;
mul_add_c(a[0], b[1], c2, c3, c1);
mul_add_c(a[1], b[0], c2, c3, c1);
r[1] = c2;
c2 = 0;
mul_add_c(a[2], b[0], c3, c1, c2);
mul_add_c(a[1], b[1], c3, c1, c2);
mul_add_c(a[0], b[2], c3, c1, c2);
r[2] = c3;
c3 = 0;
mul_add_c(a[0], b[3], c1, c2, c3);
mul_add_c(a[1], b[2], c1, c2, c3);
mul_add_c(a[2], b[1], c1, c2, c3);
mul_add_c(a[3], b[0], c1, c2, c3);
r[3] = c1;
c1 = 0;
mul_add_c(a[4], b[0], c2, c3, c1);
mul_add_c(a[3], b[1], c2, c3, c1);
mul_add_c(a[2], b[2], c2, c3, c1);
mul_add_c(a[1], b[3], c2, c3, c1);
mul_add_c(a[0], b[4], c2, c3, c1);
r[4] = c2;
c2 = 0;
mul_add_c(a[0], b[5], c3, c1, c2);
mul_add_c(a[1], b[4], c3, c1, c2);
mul_add_c(a[2], b[3], c3, c1, c2);
mul_add_c(a[3], b[2], c3, c1, c2);
mul_add_c(a[4], b[1], c3, c1, c2);
mul_add_c(a[5], b[0], c3, c1, c2);
r[5] = c3;
c3 = 0;
mul_add_c(a[6], b[0], c1, c2, c3);
mul_add_c(a[5], b[1], c1, c2, c3);
mul_add_c(a[4], b[2], c1, c2, c3);
mul_add_c(a[3], b[3], c1, c2, c3);
mul_add_c(a[2], b[4], c1, c2, c3);
mul_add_c(a[1], b[5], c1, c2, c3);
mul_add_c(a[0], b[6], c1, c2, c3);
r[6] = c1;
c1 = 0;
mul_add_c(a[0], b[7], c2, c3, c1);
mul_add_c(a[1], b[6], c2, c3, c1);
mul_add_c(a[2], b[5], c2, c3, c1);
mul_add_c(a[3], b[4], c2, c3, c1);
mul_add_c(a[4], b[3], c2, c3, c1);
mul_add_c(a[5], b[2], c2, c3, c1);
mul_add_c(a[6], b[1], c2, c3, c1);
mul_add_c(a[7], b[0], c2, c3, c1);
r[7] = c2;
c2 = 0;
mul_add_c(a[7], b[1], c3, c1, c2);
mul_add_c(a[6], b[2], c3, c1, c2);
mul_add_c(a[5], b[3], c3, c1, c2);
mul_add_c(a[4], b[4], c3, c1, c2);
mul_add_c(a[3], b[5], c3, c1, c2);
mul_add_c(a[2], b[6], c3, c1, c2);
mul_add_c(a[1], b[7], c3, c1, c2);
r[8] = c3;
c3 = 0;
mul_add_c(a[2], b[7], c1, c2, c3);
mul_add_c(a[3], b[6], c1, c2, c3);
mul_add_c(a[4], b[5], c1, c2, c3);
mul_add_c(a[5], b[4], c1, c2, c3);
mul_add_c(a[6], b[3], c1, c2, c3);
mul_add_c(a[7], b[2], c1, c2, c3);
r[9] = c1;
c1 = 0;
mul_add_c(a[7], b[3], c2, c3, c1);
mul_add_c(a[6], b[4], c2, c3, c1);
mul_add_c(a[5], b[5], c2, c3, c1);
mul_add_c(a[4], b[6], c2, c3, c1);
mul_add_c(a[3], b[7], c2, c3, c1);
r[10] = c2;
c2 = 0;
mul_add_c(a[4], b[7], c3, c1, c2);
mul_add_c(a[5], b[6], c3, c1, c2);
mul_add_c(a[6], b[5], c3, c1, c2);
mul_add_c(a[7], b[4], c3, c1, c2);
r[11] = c3;
c3 = 0;
mul_add_c(a[7], b[5], c1, c2, c3);
mul_add_c(a[6], b[6], c1, c2, c3);
mul_add_c(a[5], b[7], c1, c2, c3);
r[12] = c1;
c1 = 0;
mul_add_c(a[6], b[7], c2, c3, c1);
mul_add_c(a[7], b[6], c2, c3, c1);
r[13] = c2;
c2 = 0;
mul_add_c(a[7], b[7], c3, c1, c2);
r[14] = c3;
r[15] = c1;
}
void bn_mul_comba4(BN_ULONG *r, BN_ULONG *a, BN_ULONG *b)
{
BN_ULONG c1, c2, c3;
c1 = 0;
c2 = 0;
c3 = 0;
mul_add_c(a[0], b[0], c1, c2, c3);
r[0] = c1;
c1 = 0;
mul_add_c(a[0], b[1], c2, c3, c1);
mul_add_c(a[1], b[0], c2, c3, c1);
r[1] = c2;
c2 = 0;
mul_add_c(a[2], b[0], c3, c1, c2);
mul_add_c(a[1], b[1], c3, c1, c2);
mul_add_c(a[0], b[2], c3, c1, c2);
r[2] = c3;
c3 = 0;
mul_add_c(a[0], b[3], c1, c2, c3);
mul_add_c(a[1], b[2], c1, c2, c3);
mul_add_c(a[2], b[1], c1, c2, c3);
mul_add_c(a[3], b[0], c1, c2, c3);
r[3] = c1;
c1 = 0;
mul_add_c(a[3], b[1], c2, c3, c1);
mul_add_c(a[2], b[2], c2, c3, c1);
mul_add_c(a[1], b[3], c2, c3, c1);
r[4] = c2;
c2 = 0;
mul_add_c(a[2], b[3], c3, c1, c2);
mul_add_c(a[3], b[2], c3, c1, c2);
r[5] = c3;
c3 = 0;
mul_add_c(a[3], b[3], c1, c2, c3);
r[6] = c1;
r[7] = c2;
}
void bn_sqr_comba8(BN_ULONG *r, const BN_ULONG *a)
{
BN_ULONG c1, c2, c3;
c1 = 0;
c2 = 0;
c3 = 0;
sqr_add_c(a, 0, c1, c2, c3);
r[0] = c1;
c1 = 0;
sqr_add_c2(a, 1, 0, c2, c3, c1);
r[1] = c2;
c2 = 0;
sqr_add_c(a, 1, c3, c1, c2);
sqr_add_c2(a, 2, 0, c3, c1, c2);
r[2] = c3;
c3 = 0;
sqr_add_c2(a, 3, 0, c1, c2, c3);
sqr_add_c2(a, 2, 1, c1, c2, c3);
r[3] = c1;
c1 = 0;
sqr_add_c(a, 2, c2, c3, c1);
sqr_add_c2(a, 3, 1, c2, c3, c1);
sqr_add_c2(a, 4, 0, c2, c3, c1);
r[4] = c2;
c2 = 0;
sqr_add_c2(a, 5, 0, c3, c1, c2);
sqr_add_c2(a, 4, 1, c3, c1, c2);
sqr_add_c2(a, 3, 2, c3, c1, c2);
r[5] = c3;
c3 = 0;
sqr_add_c(a, 3, c1, c2, c3);
sqr_add_c2(a, 4, 2, c1, c2, c3);
sqr_add_c2(a, 5, 1, c1, c2, c3);
sqr_add_c2(a, 6, 0, c1, c2, c3);
r[6] = c1;
c1 = 0;
sqr_add_c2(a, 7, 0, c2, c3, c1);
sqr_add_c2(a, 6, 1, c2, c3, c1);
sqr_add_c2(a, 5, 2, c2, c3, c1);
sqr_add_c2(a, 4, 3, c2, c3, c1);
r[7] = c2;
c2 = 0;
sqr_add_c(a, 4, c3, c1, c2);
sqr_add_c2(a, 5, 3, c3, c1, c2);
sqr_add_c2(a, 6, 2, c3, c1, c2);
sqr_add_c2(a, 7, 1, c3, c1, c2);
r[8] = c3;
c3 = 0;
sqr_add_c2(a, 7, 2, c1, c2, c3);
sqr_add_c2(a, 6, 3, c1, c2, c3);
sqr_add_c2(a, 5, 4, c1, c2, c3);
r[9] = c1;
c1 = 0;
sqr_add_c(a, 5, c2, c3, c1);
sqr_add_c2(a, 6, 4, c2, c3, c1);
sqr_add_c2(a, 7, 3, c2, c3, c1);
r[10] = c2;
c2 = 0;
sqr_add_c2(a, 7, 4, c3, c1, c2);
sqr_add_c2(a, 6, 5, c3, c1, c2);
r[11] = c3;
c3 = 0;
sqr_add_c(a, 6, c1, c2, c3);
sqr_add_c2(a, 7, 5, c1, c2, c3);
r[12] = c1;
c1 = 0;
sqr_add_c2(a, 7, 6, c2, c3, c1);
r[13] = c2;
c2 = 0;
sqr_add_c(a, 7, c3, c1, c2);
r[14] = c3;
r[15] = c1;
}
void bn_sqr_comba4(BN_ULONG *r, const BN_ULONG *a)
{
BN_ULONG c1, c2, c3;
c1 = 0;
c2 = 0;
c3 = 0;
sqr_add_c(a, 0, c1, c2, c3);
r[0] = c1;
c1 = 0;
sqr_add_c2(a, 1, 0, c2, c3, c1);
r[1] = c2;
c2 = 0;
sqr_add_c(a, 1, c3, c1, c2);
sqr_add_c2(a, 2, 0, c3, c1, c2);
r[2] = c3;
c3 = 0;
sqr_add_c2(a, 3, 0, c1, c2, c3);
sqr_add_c2(a, 2, 1, c1, c2, c3);
r[3] = c1;
c1 = 0;
sqr_add_c(a, 2, c2, c3, c1);
sqr_add_c2(a, 3, 1, c2, c3, c1);
r[4] = c2;
c2 = 0;
sqr_add_c2(a, 3, 2, c3, c1, c2);
r[5] = c3;
c3 = 0;
sqr_add_c(a, 3, c1, c2, c3);
r[6] = c1;
r[7] = c2;
}
