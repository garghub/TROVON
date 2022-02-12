static void ctr128_inc(unsigned char *counter)
{
u32 n = 16, c = 1;
do {
--n;
c += counter[n];
counter[n] = (u8)c;
c >>= 8;
} while (n);
}
static void ctr128_inc_aligned(unsigned char *counter)
{
size_t *data, c, d, n;
const union {
long one;
char little;
} is_endian = {
1
};
if (is_endian.little || ((size_t)counter % sizeof(size_t)) != 0) {
ctr128_inc(counter);
return;
}
data = (size_t *)counter;
c = 1;
n = 16 / sizeof(size_t);
do {
--n;
d = data[n] += c;
c = ((d - c) ^ d) >> (sizeof(size_t) * 8 - 1);
} while (n);
}
void CRYPTO_ctr128_encrypt(const unsigned char *in, unsigned char *out,
size_t len, const void *key,
unsigned char ivec[16],
unsigned char ecount_buf[16], unsigned int *num,
block128_f block)
{
unsigned int n;
size_t l = 0;
n = *num;
#if !defined(OPENSSL_SMALL_FOOTPRINT)
if (16 % sizeof(size_t) == 0) {
do {
while (n && len) {
*(out++) = *(in++) ^ ecount_buf[n];
--len;
n = (n + 1) % 16;
}
# if defined(STRICT_ALIGNMENT)
if (((size_t)in | (size_t)out | (size_t)ecount_buf)
% sizeof(size_t) != 0)
break;
# endif
while (len >= 16) {
(*block) (ivec, ecount_buf, key);
ctr128_inc_aligned(ivec);
for (n = 0; n < 16; n += sizeof(size_t))
*(size_t *)(out + n) =
*(size_t *)(in + n) ^ *(size_t *)(ecount_buf + n);
len -= 16;
out += 16;
in += 16;
n = 0;
}
if (len) {
(*block) (ivec, ecount_buf, key);
ctr128_inc_aligned(ivec);
while (len--) {
out[n] = in[n] ^ ecount_buf[n];
++n;
}
}
*num = n;
return;
} while (0);
}
#endif
while (l < len) {
if (n == 0) {
(*block) (ivec, ecount_buf, key);
ctr128_inc(ivec);
}
out[l] = in[l] ^ ecount_buf[n];
++l;
n = (n + 1) % 16;
}
*num = n;
}
static void ctr96_inc(unsigned char *counter)
{
u32 n = 12, c = 1;
do {
--n;
c += counter[n];
counter[n] = (u8)c;
c >>= 8;
} while (n);
}
void CRYPTO_ctr128_encrypt_ctr32(const unsigned char *in, unsigned char *out,
size_t len, const void *key,
unsigned char ivec[16],
unsigned char ecount_buf[16],
unsigned int *num, ctr128_f func)
{
unsigned int n, ctr32;
n = *num;
while (n && len) {
*(out++) = *(in++) ^ ecount_buf[n];
--len;
n = (n + 1) % 16;
}
ctr32 = GETU32(ivec + 12);
while (len >= 16) {
size_t blocks = len / 16;
if (sizeof(size_t) > sizeof(unsigned int) && blocks > (1U << 28))
blocks = (1U << 28);
ctr32 += (u32)blocks;
if (ctr32 < blocks) {
blocks -= ctr32;
ctr32 = 0;
}
(*func) (in, out, blocks, key, ivec);
PUTU32(ivec + 12, ctr32);
if (ctr32 == 0)
ctr96_inc(ivec);
blocks *= 16;
len -= blocks;
out += blocks;
in += blocks;
}
if (len) {
memset(ecount_buf, 0, 16);
(*func) (ecount_buf, ecount_buf, 1, key, ivec);
++ctr32;
PUTU32(ivec + 12, ctr32);
if (ctr32 == 0)
ctr96_inc(ivec);
while (len--) {
out[n] = in[n] ^ ecount_buf[n];
++n;
}
}
*num = n;
}
