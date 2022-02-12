static inline unsigned long ROL(unsigned long word, int i)
{
__asm__("roll %%cl,%0"
:"=r" (word)
:"0" (word),"c" (i));
return word;
}
static inline unsigned long ROR(unsigned long word, int i)
{
__asm__("rorl %%cl,%0"
:"=r" (word)
:"0" (word),"c" (i));
return word;
}
static ulong32 BYTE2WORD(const unsigned char *b)
{
ulong32 t;
LOAD32L(t, b);
return t;
}
static void XORWORD(ulong32 w, unsigned char *b)
{
ulong32 t;
LOAD32L(t, b);
t ^= w;
STORE32L(t, b);
}
static void cycle(ulong32 *R)
{
ulong32 t;
int i;
STEP(R,0);
t = R[0];
for (i = 1; i < N; ++i) {
R[i-1] = R[i];
}
R[N-1] = t;
}
static ulong32 nltap(sober128_prng *c)
{
ulong32 t;
NLFUNC(c, 0);
return t;
}
int sober128_start(sober128_prng *c)
{
int i;
c->R[0] = 1;
c->R[1] = 1;
for (i = 2; i < N; ++i) {
c->R[i] = c->R[i-1] + c->R[i-2];
}
c->konst = INITKONST;
c->flag = 1;
c->set = 0;
return 0;
}
static void s128_savestate(sober128_prng *c)
{
int i;
for (i = 0; i < N; ++i) {
c->initR[i] = c->R[i];
}
}
static void s128_reloadstate(sober128_prng *c)
{
int i;
for (i = 0; i < N; ++i) {
c->R[i] = c->initR[i];
}
}
static void s128_genkonst(sober128_prng *c)
{
ulong32 newkonst;
do {
cycle(c->R);
newkonst = nltap(c);
} while ((newkonst & 0xFF000000) == 0);
c->konst = newkonst;
}
static void s128_diffuse(sober128_prng *c)
{
ulong32 t;
DROUND(0);
DROUND(1);
DROUND(2);
DROUND(3);
DROUND(4);
DROUND(5);
DROUND(6);
DROUND(7);
DROUND(8);
DROUND(9);
DROUND(10);
DROUND(11);
DROUND(12);
DROUND(13);
DROUND(14);
DROUND(15);
DROUND(16);
}
int sober128_add_entropy(const unsigned char *buf, unsigned long len, sober128_prng *c)
{
ulong32 i, k;
if (c->flag == 1) {
for (i = 0; i < len/4; i++) {
k = BYTE2WORD(&buf[i*4]);
ADDKEY(k);
cycle(c->R);
XORNL(nltap(c));
}
ADDKEY(len);
s128_diffuse(c);
s128_genkonst(c);
s128_savestate(c);
c->nbuf = 0;
c->flag = 0;
c->set = 1;
} else {
s128_reloadstate(c);
for (i = 0; i < len/4; i++) {
k = BYTE2WORD(&buf[i*4]);
ADDKEY(k);
cycle(c->R);
XORNL(nltap(c));
}
ADDKEY(len);
s128_diffuse(c);
c->nbuf = 0;
}
return 0;
}
unsigned long sober128_read(unsigned char *buf, unsigned long nbytes, sober128_prng *c)
{
ulong32 t, tlen;
tlen = nbytes;
while (c->nbuf != 0 && nbytes != 0) {
*buf++ ^= c->sbuf & 0xFF;
c->sbuf >>= 8;
c->nbuf -= 8;
--nbytes;
}
#ifndef SMALL_CODE
while (nbytes >= N*4) {
SROUND(0);
SROUND(1);
SROUND(2);
SROUND(3);
SROUND(4);
SROUND(5);
SROUND(6);
SROUND(7);
SROUND(8);
SROUND(9);
SROUND(10);
SROUND(11);
SROUND(12);
SROUND(13);
SROUND(14);
SROUND(15);
SROUND(16);
buf += 4*N;
nbytes -= 4*N;
}
#endif
while (4 <= nbytes) {
cycle(c->R);
t = nltap(c);
XORWORD(t, buf);
buf += 4;
nbytes -= 4;
}
if (nbytes != 0) {
cycle(c->R);
c->sbuf = nltap(c);
c->nbuf = 32;
while (c->nbuf != 0 && nbytes != 0) {
*buf++ ^= c->sbuf & 0xFF;
c->sbuf >>= 8;
c->nbuf -= 8;
--nbytes;
}
}
return tlen;
}
