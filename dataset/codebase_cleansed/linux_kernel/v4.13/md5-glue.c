static inline void ppc_md5_clear_context(struct md5_state *sctx)
{
int count = sizeof(struct md5_state) >> 2;
u32 *ptr = (u32 *)sctx;
BUILD_BUG_ON(sizeof(struct md5_state) % 4);
do { *ptr++ = 0; } while (--count);
}
static int ppc_md5_init(struct shash_desc *desc)
{
struct md5_state *sctx = shash_desc_ctx(desc);
sctx->hash[0] = MD5_H0;
sctx->hash[1] = MD5_H1;
sctx->hash[2] = MD5_H2;
sctx->hash[3] = MD5_H3;
sctx->byte_count = 0;
return 0;
}
static int ppc_md5_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct md5_state *sctx = shash_desc_ctx(desc);
const unsigned int offset = sctx->byte_count & 0x3f;
unsigned int avail = 64 - offset;
const u8 *src = data;
sctx->byte_count += len;
if (avail > len) {
memcpy((char *)sctx->block + offset, src, len);
return 0;
}
if (offset) {
memcpy((char *)sctx->block + offset, src, avail);
ppc_md5_transform(sctx->hash, (const u8 *)sctx->block, 1);
len -= avail;
src += avail;
}
if (len > 63) {
ppc_md5_transform(sctx->hash, src, len >> 6);
src += len & ~0x3f;
len &= 0x3f;
}
memcpy((char *)sctx->block, src, len);
return 0;
}
static int ppc_md5_final(struct shash_desc *desc, u8 *out)
{
struct md5_state *sctx = shash_desc_ctx(desc);
const unsigned int offset = sctx->byte_count & 0x3f;
const u8 *src = (const u8 *)sctx->block;
u8 *p = (u8 *)src + offset;
int padlen = 55 - offset;
__le64 *pbits = (__le64 *)((char *)sctx->block + 56);
__le32 *dst = (__le32 *)out;
*p++ = 0x80;
if (padlen < 0) {
memset(p, 0x00, padlen + sizeof (u64));
ppc_md5_transform(sctx->hash, src, 1);
p = (char *)sctx->block;
padlen = 56;
}
memset(p, 0, padlen);
*pbits = cpu_to_le64(sctx->byte_count << 3);
ppc_md5_transform(sctx->hash, src, 1);
dst[0] = cpu_to_le32(sctx->hash[0]);
dst[1] = cpu_to_le32(sctx->hash[1]);
dst[2] = cpu_to_le32(sctx->hash[2]);
dst[3] = cpu_to_le32(sctx->hash[3]);
ppc_md5_clear_context(sctx);
return 0;
}
static int ppc_md5_export(struct shash_desc *desc, void *out)
{
struct md5_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int ppc_md5_import(struct shash_desc *desc, const void *in)
{
struct md5_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int __init ppc_md5_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit ppc_md5_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
