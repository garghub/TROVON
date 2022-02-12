static void spe_begin(void)
{
preempt_disable();
enable_kernel_spe();
}
static void spe_end(void)
{
preempt_enable();
}
static inline void ppc_sha256_clear_context(struct sha256_state *sctx)
{
int count = sizeof(struct sha256_state) >> 2;
u32 *ptr = (u32 *)sctx;
BUILD_BUG_ON(sizeof(struct sha256_state) % 4);
do { *ptr++ = 0; } while (--count);
}
static int ppc_spe_sha256_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA256_H0;
sctx->state[1] = SHA256_H1;
sctx->state[2] = SHA256_H2;
sctx->state[3] = SHA256_H3;
sctx->state[4] = SHA256_H4;
sctx->state[5] = SHA256_H5;
sctx->state[6] = SHA256_H6;
sctx->state[7] = SHA256_H7;
sctx->count = 0;
return 0;
}
static int ppc_spe_sha224_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA224_H0;
sctx->state[1] = SHA224_H1;
sctx->state[2] = SHA224_H2;
sctx->state[3] = SHA224_H3;
sctx->state[4] = SHA224_H4;
sctx->state[5] = SHA224_H5;
sctx->state[6] = SHA224_H6;
sctx->state[7] = SHA224_H7;
sctx->count = 0;
return 0;
}
static int ppc_spe_sha256_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
const unsigned int offset = sctx->count & 0x3f;
const unsigned int avail = 64 - offset;
unsigned int bytes;
const u8 *src = data;
if (avail > len) {
sctx->count += len;
memcpy((char *)sctx->buf + offset, src, len);
return 0;
}
sctx->count += len;
if (offset) {
memcpy((char *)sctx->buf + offset, src, avail);
spe_begin();
ppc_spe_sha256_transform(sctx->state, (const u8 *)sctx->buf, 1);
spe_end();
len -= avail;
src += avail;
}
while (len > 63) {
bytes = (len > MAX_BYTES) ? MAX_BYTES : len;
bytes = bytes & ~0x3f;
spe_begin();
ppc_spe_sha256_transform(sctx->state, src, bytes >> 6);
spe_end();
src += bytes;
len -= bytes;
};
memcpy((char *)sctx->buf, src, len);
return 0;
}
static int ppc_spe_sha256_final(struct shash_desc *desc, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
const unsigned int offset = sctx->count & 0x3f;
char *p = (char *)sctx->buf + offset;
int padlen;
__be64 *pbits = (__be64 *)(((char *)&sctx->buf) + 56);
__be32 *dst = (__be32 *)out;
padlen = 55 - offset;
*p++ = 0x80;
spe_begin();
if (padlen < 0) {
memset(p, 0x00, padlen + sizeof (u64));
ppc_spe_sha256_transform(sctx->state, sctx->buf, 1);
p = (char *)sctx->buf;
padlen = 56;
}
memset(p, 0, padlen);
*pbits = cpu_to_be64(sctx->count << 3);
ppc_spe_sha256_transform(sctx->state, sctx->buf, 1);
spe_end();
dst[0] = cpu_to_be32(sctx->state[0]);
dst[1] = cpu_to_be32(sctx->state[1]);
dst[2] = cpu_to_be32(sctx->state[2]);
dst[3] = cpu_to_be32(sctx->state[3]);
dst[4] = cpu_to_be32(sctx->state[4]);
dst[5] = cpu_to_be32(sctx->state[5]);
dst[6] = cpu_to_be32(sctx->state[6]);
dst[7] = cpu_to_be32(sctx->state[7]);
ppc_sha256_clear_context(sctx);
return 0;
}
static int ppc_spe_sha224_final(struct shash_desc *desc, u8 *out)
{
u32 D[SHA256_DIGEST_SIZE >> 2];
__be32 *dst = (__be32 *)out;
ppc_spe_sha256_final(desc, (u8 *)D);
dst[0] = D[0];
dst[1] = D[1];
dst[2] = D[2];
dst[3] = D[3];
dst[4] = D[4];
dst[5] = D[5];
dst[6] = D[6];
memzero_explicit(D, SHA256_DIGEST_SIZE);
return 0;
}
static int ppc_spe_sha256_export(struct shash_desc *desc, void *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int ppc_spe_sha256_import(struct shash_desc *desc, const void *in)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int __init ppc_spe_sha256_mod_init(void)
{
return crypto_register_shashes(algs, ARRAY_SIZE(algs));
}
static void __exit ppc_spe_sha256_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
