static int sha224_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
*sctx = (struct sha256_state){
.state = {
SHA224_H0, SHA224_H1, SHA224_H2, SHA224_H3,
SHA224_H4, SHA224_H5, SHA224_H6, SHA224_H7,
}
};
return 0;
}
static int sha256_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
*sctx = (struct sha256_state){
.state = {
SHA256_H0, SHA256_H1, SHA256_H2, SHA256_H3,
SHA256_H4, SHA256_H5, SHA256_H6, SHA256_H7,
}
};
return 0;
}
static int sha2_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count % SHA256_BLOCK_SIZE;
sctx->count += len;
if ((partial + len) >= SHA256_BLOCK_SIZE) {
int blocks;
if (partial) {
int p = SHA256_BLOCK_SIZE - partial;
memcpy(sctx->buf + partial, data, p);
data += p;
len -= p;
}
blocks = len / SHA256_BLOCK_SIZE;
len %= SHA256_BLOCK_SIZE;
kernel_neon_begin_partial(28);
sha2_ce_transform(blocks, data, sctx->state,
partial ? sctx->buf : NULL, 0);
kernel_neon_end();
data += blocks * SHA256_BLOCK_SIZE;
partial = 0;
}
if (len)
memcpy(sctx->buf + partial, data, len);
return 0;
}
static void sha2_final(struct shash_desc *desc)
{
static const u8 padding[SHA256_BLOCK_SIZE] = { 0x80, };
struct sha256_state *sctx = shash_desc_ctx(desc);
__be64 bits = cpu_to_be64(sctx->count << 3);
u32 padlen = SHA256_BLOCK_SIZE
- ((sctx->count + sizeof(bits)) % SHA256_BLOCK_SIZE);
sha2_update(desc, padding, padlen);
sha2_update(desc, (const u8 *)&bits, sizeof(bits));
}
static int sha224_final(struct shash_desc *desc, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
__be32 *dst = (__be32 *)out;
int i;
sha2_final(desc);
for (i = 0; i < SHA224_DIGEST_SIZE / sizeof(__be32); i++)
put_unaligned_be32(sctx->state[i], dst++);
*sctx = (struct sha256_state){};
return 0;
}
static int sha256_final(struct shash_desc *desc, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
__be32 *dst = (__be32 *)out;
int i;
sha2_final(desc);
for (i = 0; i < SHA256_DIGEST_SIZE / sizeof(__be32); i++)
put_unaligned_be32(sctx->state[i], dst++);
*sctx = (struct sha256_state){};
return 0;
}
static void sha2_finup(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
int blocks;
if (sctx->count || !len || (len % SHA256_BLOCK_SIZE)) {
sha2_update(desc, data, len);
sha2_final(desc);
return;
}
blocks = len / SHA256_BLOCK_SIZE;
kernel_neon_begin_partial(28);
sha2_ce_transform(blocks, data, sctx->state, NULL, len);
kernel_neon_end();
}
static int sha224_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
__be32 *dst = (__be32 *)out;
int i;
sha2_finup(desc, data, len);
for (i = 0; i < SHA224_DIGEST_SIZE / sizeof(__be32); i++)
put_unaligned_be32(sctx->state[i], dst++);
*sctx = (struct sha256_state){};
return 0;
}
static int sha256_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
__be32 *dst = (__be32 *)out;
int i;
sha2_finup(desc, data, len);
for (i = 0; i < SHA256_DIGEST_SIZE / sizeof(__be32); i++)
put_unaligned_be32(sctx->state[i], dst++);
*sctx = (struct sha256_state){};
return 0;
}
static int sha2_export(struct shash_desc *desc, void *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct sha256_state *dst = out;
*dst = *sctx;
return 0;
}
static int sha2_import(struct shash_desc *desc, const void *in)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
struct sha256_state const *src = in;
*sctx = *src;
return 0;
}
static int __init sha2_ce_mod_init(void)
{
return crypto_register_shashes(algs, ARRAY_SIZE(algs));
}
static void __exit sha2_ce_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
