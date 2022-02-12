static void spe_begin(void)
{
preempt_disable();
enable_kernel_spe();
}
static void spe_end(void)
{
disable_kernel_spe();
preempt_enable();
}
static inline void ppc_sha1_clear_context(struct sha1_state *sctx)
{
int count = sizeof(struct sha1_state) >> 2;
u32 *ptr = (u32 *)sctx;
BUILD_BUG_ON(sizeof(struct sha1_state) % 4);
do { *ptr++ = 0; } while (--count);
}
static int ppc_spe_sha1_init(struct shash_desc *desc)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA1_H0;
sctx->state[1] = SHA1_H1;
sctx->state[2] = SHA1_H2;
sctx->state[3] = SHA1_H3;
sctx->state[4] = SHA1_H4;
sctx->count = 0;
return 0;
}
static int ppc_spe_sha1_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
const unsigned int offset = sctx->count & 0x3f;
const unsigned int avail = 64 - offset;
unsigned int bytes;
const u8 *src = data;
if (avail > len) {
sctx->count += len;
memcpy((char *)sctx->buffer + offset, src, len);
return 0;
}
sctx->count += len;
if (offset) {
memcpy((char *)sctx->buffer + offset, src, avail);
spe_begin();
ppc_spe_sha1_transform(sctx->state, (const u8 *)sctx->buffer, 1);
spe_end();
len -= avail;
src += avail;
}
while (len > 63) {
bytes = (len > MAX_BYTES) ? MAX_BYTES : len;
bytes = bytes & ~0x3f;
spe_begin();
ppc_spe_sha1_transform(sctx->state, src, bytes >> 6);
spe_end();
src += bytes;
len -= bytes;
};
memcpy((char *)sctx->buffer, src, len);
return 0;
}
static int ppc_spe_sha1_final(struct shash_desc *desc, u8 *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
const unsigned int offset = sctx->count & 0x3f;
char *p = (char *)sctx->buffer + offset;
int padlen;
__be64 *pbits = (__be64 *)(((char *)&sctx->buffer) + 56);
__be32 *dst = (__be32 *)out;
padlen = 55 - offset;
*p++ = 0x80;
spe_begin();
if (padlen < 0) {
memset(p, 0x00, padlen + sizeof (u64));
ppc_spe_sha1_transform(sctx->state, sctx->buffer, 1);
p = (char *)sctx->buffer;
padlen = 56;
}
memset(p, 0, padlen);
*pbits = cpu_to_be64(sctx->count << 3);
ppc_spe_sha1_transform(sctx->state, sctx->buffer, 1);
spe_end();
dst[0] = cpu_to_be32(sctx->state[0]);
dst[1] = cpu_to_be32(sctx->state[1]);
dst[2] = cpu_to_be32(sctx->state[2]);
dst[3] = cpu_to_be32(sctx->state[3]);
dst[4] = cpu_to_be32(sctx->state[4]);
ppc_sha1_clear_context(sctx);
return 0;
}
static int ppc_spe_sha1_export(struct shash_desc *desc, void *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int ppc_spe_sha1_import(struct shash_desc *desc, const void *in)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int __init ppc_spe_sha1_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit ppc_spe_sha1_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
