static int sha1_init(struct shash_desc *desc)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
*sctx = (struct sha1_state){
.state = { SHA1_H0, SHA1_H1, SHA1_H2, SHA1_H3, SHA1_H4 },
};
return 0;
}
static int sha1_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count % SHA1_BLOCK_SIZE;
sctx->count += len;
if ((partial + len) >= SHA1_BLOCK_SIZE) {
int blocks;
if (partial) {
int p = SHA1_BLOCK_SIZE - partial;
memcpy(sctx->buffer + partial, data, p);
data += p;
len -= p;
}
blocks = len / SHA1_BLOCK_SIZE;
len %= SHA1_BLOCK_SIZE;
kernel_neon_begin_partial(16);
sha1_ce_transform(blocks, data, sctx->state,
partial ? sctx->buffer : NULL, 0);
kernel_neon_end();
data += blocks * SHA1_BLOCK_SIZE;
partial = 0;
}
if (len)
memcpy(sctx->buffer + partial, data, len);
return 0;
}
static int sha1_final(struct shash_desc *desc, u8 *out)
{
static const u8 padding[SHA1_BLOCK_SIZE] = { 0x80, };
struct sha1_state *sctx = shash_desc_ctx(desc);
__be64 bits = cpu_to_be64(sctx->count << 3);
__be32 *dst = (__be32 *)out;
int i;
u32 padlen = SHA1_BLOCK_SIZE
- ((sctx->count + sizeof(bits)) % SHA1_BLOCK_SIZE);
sha1_update(desc, padding, padlen);
sha1_update(desc, (const u8 *)&bits, sizeof(bits));
for (i = 0; i < SHA1_DIGEST_SIZE / sizeof(__be32); i++)
put_unaligned_be32(sctx->state[i], dst++);
*sctx = (struct sha1_state){};
return 0;
}
static int sha1_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
__be32 *dst = (__be32 *)out;
int blocks;
int i;
if (sctx->count || !len || (len % SHA1_BLOCK_SIZE)) {
sha1_update(desc, data, len);
return sha1_final(desc, out);
}
blocks = len / SHA1_BLOCK_SIZE;
kernel_neon_begin_partial(16);
sha1_ce_transform(blocks, data, sctx->state, NULL, len);
kernel_neon_end();
for (i = 0; i < SHA1_DIGEST_SIZE / sizeof(__be32); i++)
put_unaligned_be32(sctx->state[i], dst++);
*sctx = (struct sha1_state){};
return 0;
}
static int sha1_export(struct shash_desc *desc, void *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
struct sha1_state *dst = out;
*dst = *sctx;
return 0;
}
static int sha1_import(struct shash_desc *desc, const void *in)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
struct sha1_state const *src = in;
*sctx = *src;
return 0;
}
static int __init sha1_ce_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit sha1_ce_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
