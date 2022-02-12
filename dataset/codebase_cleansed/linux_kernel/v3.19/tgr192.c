static void tgr192_round(u64 * ra, u64 * rb, u64 * rc, u64 x, int mul)
{
u64 a = *ra;
u64 b = *rb;
u64 c = *rc;
c ^= x;
a -= sbox1[c & 0xff] ^ sbox2[(c >> 16) & 0xff]
^ sbox3[(c >> 32) & 0xff] ^ sbox4[(c >> 48) & 0xff];
b += sbox4[(c >> 8) & 0xff] ^ sbox3[(c >> 24) & 0xff]
^ sbox2[(c >> 40) & 0xff] ^ sbox1[(c >> 56) & 0xff];
b *= mul;
*ra = a;
*rb = b;
*rc = c;
}
static void tgr192_pass(u64 * ra, u64 * rb, u64 * rc, u64 * x, int mul)
{
u64 a = *ra;
u64 b = *rb;
u64 c = *rc;
tgr192_round(&a, &b, &c, x[0], mul);
tgr192_round(&b, &c, &a, x[1], mul);
tgr192_round(&c, &a, &b, x[2], mul);
tgr192_round(&a, &b, &c, x[3], mul);
tgr192_round(&b, &c, &a, x[4], mul);
tgr192_round(&c, &a, &b, x[5], mul);
tgr192_round(&a, &b, &c, x[6], mul);
tgr192_round(&b, &c, &a, x[7], mul);
*ra = a;
*rb = b;
*rc = c;
}
static void tgr192_key_schedule(u64 * x)
{
x[0] -= x[7] ^ 0xa5a5a5a5a5a5a5a5ULL;
x[1] ^= x[0];
x[2] += x[1];
x[3] -= x[2] ^ ((~x[1]) << 19);
x[4] ^= x[3];
x[5] += x[4];
x[6] -= x[5] ^ ((~x[4]) >> 23);
x[7] ^= x[6];
x[0] += x[7];
x[1] -= x[0] ^ ((~x[7]) << 19);
x[2] ^= x[1];
x[3] += x[2];
x[4] -= x[3] ^ ((~x[2]) >> 23);
x[5] ^= x[4];
x[6] += x[5];
x[7] -= x[6] ^ 0x0123456789abcdefULL;
}
static void tgr192_transform(struct tgr192_ctx *tctx, const u8 * data)
{
u64 a, b, c, aa, bb, cc;
u64 x[8];
int i;
const __le64 *ptr = (const __le64 *)data;
for (i = 0; i < 8; i++)
x[i] = le64_to_cpu(ptr[i]);
a = aa = tctx->a;
b = bb = tctx->b;
c = cc = tctx->c;
tgr192_pass(&a, &b, &c, x, 5);
tgr192_key_schedule(x);
tgr192_pass(&c, &a, &b, x, 7);
tgr192_key_schedule(x);
tgr192_pass(&b, &c, &a, x, 9);
a ^= aa;
b -= bb;
c += cc;
tctx->a = a;
tctx->b = b;
tctx->c = c;
}
static int tgr192_init(struct shash_desc *desc)
{
struct tgr192_ctx *tctx = shash_desc_ctx(desc);
tctx->a = 0x0123456789abcdefULL;
tctx->b = 0xfedcba9876543210ULL;
tctx->c = 0xf096a5b4c3b2e187ULL;
tctx->nblocks = 0;
tctx->count = 0;
return 0;
}
static int tgr192_update(struct shash_desc *desc, const u8 *inbuf,
unsigned int len)
{
struct tgr192_ctx *tctx = shash_desc_ctx(desc);
if (tctx->count == 64) {
tgr192_transform(tctx, tctx->hash);
tctx->count = 0;
tctx->nblocks++;
}
if (!inbuf) {
return 0;
}
if (tctx->count) {
for (; len && tctx->count < 64; len--) {
tctx->hash[tctx->count++] = *inbuf++;
}
tgr192_update(desc, NULL, 0);
if (!len) {
return 0;
}
}
while (len >= 64) {
tgr192_transform(tctx, inbuf);
tctx->count = 0;
tctx->nblocks++;
len -= 64;
inbuf += 64;
}
for (; len && tctx->count < 64; len--) {
tctx->hash[tctx->count++] = *inbuf++;
}
return 0;
}
static int tgr192_final(struct shash_desc *desc, u8 * out)
{
struct tgr192_ctx *tctx = shash_desc_ctx(desc);
__be64 *dst = (__be64 *)out;
__be64 *be64p;
__le32 *le32p;
u32 t, msb, lsb;
tgr192_update(desc, NULL, 0); ;
msb = 0;
t = tctx->nblocks;
if ((lsb = t << 6) < t) {
msb++;
}
msb += t >> 26;
t = lsb;
if ((lsb = t + tctx->count) < t) {
msb++;
}
t = lsb;
if ((lsb = t << 3) < t) {
msb++;
}
msb += t >> 29;
if (tctx->count < 56) {
tctx->hash[tctx->count++] = 0x01;
while (tctx->count < 56) {
tctx->hash[tctx->count++] = 0;
}
} else {
tctx->hash[tctx->count++] = 0x01;
while (tctx->count < 64) {
tctx->hash[tctx->count++] = 0;
}
tgr192_update(desc, NULL, 0); ;
memset(tctx->hash, 0, 56);
}
le32p = (__le32 *)&tctx->hash[56];
le32p[0] = cpu_to_le32(lsb);
le32p[1] = cpu_to_le32(msb);
tgr192_transform(tctx, tctx->hash);
be64p = (__be64 *)tctx->hash;
dst[0] = be64p[0] = cpu_to_be64(tctx->a);
dst[1] = be64p[1] = cpu_to_be64(tctx->b);
dst[2] = be64p[2] = cpu_to_be64(tctx->c);
return 0;
}
static int tgr160_final(struct shash_desc *desc, u8 * out)
{
u8 D[64];
tgr192_final(desc, D);
memcpy(out, D, TGR160_DIGEST_SIZE);
memzero_explicit(D, TGR192_DIGEST_SIZE);
return 0;
}
static int tgr128_final(struct shash_desc *desc, u8 * out)
{
u8 D[64];
tgr192_final(desc, D);
memcpy(out, D, TGR128_DIGEST_SIZE);
memzero_explicit(D, TGR192_DIGEST_SIZE);
return 0;
}
static int __init tgr192_mod_init(void)
{
return crypto_register_shashes(tgr_algs, ARRAY_SIZE(tgr_algs));
}
static void __exit tgr192_mod_fini(void)
{
crypto_unregister_shashes(tgr_algs, ARRAY_SIZE(tgr_algs));
}
