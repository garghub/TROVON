static int sha512_neon_init(struct shash_desc *desc)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA512_H0;
sctx->state[1] = SHA512_H1;
sctx->state[2] = SHA512_H2;
sctx->state[3] = SHA512_H3;
sctx->state[4] = SHA512_H4;
sctx->state[5] = SHA512_H5;
sctx->state[6] = SHA512_H6;
sctx->state[7] = SHA512_H7;
sctx->count[0] = sctx->count[1] = 0;
return 0;
}
static int __sha512_neon_update(struct shash_desc *desc, const u8 *data,
unsigned int len, unsigned int partial)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
unsigned int done = 0;
sctx->count[0] += len;
if (sctx->count[0] < len)
sctx->count[1]++;
if (partial) {
done = SHA512_BLOCK_SIZE - partial;
memcpy(sctx->buf + partial, data, done);
sha512_transform_neon(sctx->state, sctx->buf, sha512_k, 1);
}
if (len - done >= SHA512_BLOCK_SIZE) {
const unsigned int rounds = (len - done) / SHA512_BLOCK_SIZE;
sha512_transform_neon(sctx->state, data + done, sha512_k,
rounds);
done += rounds * SHA512_BLOCK_SIZE;
}
memcpy(sctx->buf, data + done, len - done);
return 0;
}
static int sha512_neon_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count[0] % SHA512_BLOCK_SIZE;
int res;
if (partial + len < SHA512_BLOCK_SIZE) {
sctx->count[0] += len;
if (sctx->count[0] < len)
sctx->count[1]++;
memcpy(sctx->buf + partial, data, len);
return 0;
}
if (!may_use_simd()) {
res = crypto_sha512_update(desc, data, len);
} else {
kernel_neon_begin();
res = __sha512_neon_update(desc, data, len, partial);
kernel_neon_end();
}
return res;
}
static int sha512_neon_final(struct shash_desc *desc, u8 *out)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, padlen;
__be64 *dst = (__be64 *)out;
__be64 bits[2];
static const u8 padding[SHA512_BLOCK_SIZE] = { 0x80, };
bits[1] = cpu_to_be64(sctx->count[0] << 3);
bits[0] = cpu_to_be64(sctx->count[1] << 3 | sctx->count[0] >> 61);
index = sctx->count[0] & 0x7f;
padlen = (index < 112) ? (112 - index) : ((128+112) - index);
if (!may_use_simd()) {
crypto_sha512_update(desc, padding, padlen);
crypto_sha512_update(desc, (const u8 *)&bits, sizeof(bits));
} else {
kernel_neon_begin();
if (padlen <= 112) {
sctx->count[0] += padlen;
if (sctx->count[0] < padlen)
sctx->count[1]++;
memcpy(sctx->buf + index, padding, padlen);
} else {
__sha512_neon_update(desc, padding, padlen, index);
}
__sha512_neon_update(desc, (const u8 *)&bits,
sizeof(bits), 112);
kernel_neon_end();
}
for (i = 0; i < 8; i++)
dst[i] = cpu_to_be64(sctx->state[i]);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int sha512_neon_export(struct shash_desc *desc, void *out)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha512_neon_import(struct shash_desc *desc, const void *in)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int sha384_neon_init(struct shash_desc *desc)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA384_H0;
sctx->state[1] = SHA384_H1;
sctx->state[2] = SHA384_H2;
sctx->state[3] = SHA384_H3;
sctx->state[4] = SHA384_H4;
sctx->state[5] = SHA384_H5;
sctx->state[6] = SHA384_H6;
sctx->state[7] = SHA384_H7;
sctx->count[0] = sctx->count[1] = 0;
return 0;
}
static int sha384_neon_final(struct shash_desc *desc, u8 *hash)
{
u8 D[SHA512_DIGEST_SIZE];
sha512_neon_final(desc, D);
memcpy(hash, D, SHA384_DIGEST_SIZE);
memset(D, 0, SHA512_DIGEST_SIZE);
return 0;
}
static int __init sha512_neon_mod_init(void)
{
if (!cpu_has_neon())
return -ENODEV;
return crypto_register_shashes(algs, ARRAY_SIZE(algs));
}
static void __exit sha512_neon_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
