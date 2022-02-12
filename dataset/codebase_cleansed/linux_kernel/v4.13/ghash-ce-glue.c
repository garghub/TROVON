static int ghash_init(struct shash_desc *desc)
{
struct ghash_desc_ctx *ctx = shash_desc_ctx(desc);
*ctx = (struct ghash_desc_ctx){};
return 0;
}
static int ghash_update(struct shash_desc *desc, const u8 *src,
unsigned int len)
{
struct ghash_desc_ctx *ctx = shash_desc_ctx(desc);
unsigned int partial = ctx->count % GHASH_BLOCK_SIZE;
ctx->count += len;
if ((partial + len) >= GHASH_BLOCK_SIZE) {
struct ghash_key *key = crypto_shash_ctx(desc->tfm);
int blocks;
if (partial) {
int p = GHASH_BLOCK_SIZE - partial;
memcpy(ctx->buf + partial, src, p);
src += p;
len -= p;
}
blocks = len / GHASH_BLOCK_SIZE;
len %= GHASH_BLOCK_SIZE;
kernel_neon_begin_partial(8);
pmull_ghash_update(blocks, ctx->digest, src, key,
partial ? ctx->buf : NULL);
kernel_neon_end();
src += blocks * GHASH_BLOCK_SIZE;
partial = 0;
}
if (len)
memcpy(ctx->buf + partial, src, len);
return 0;
}
static int ghash_final(struct shash_desc *desc, u8 *dst)
{
struct ghash_desc_ctx *ctx = shash_desc_ctx(desc);
unsigned int partial = ctx->count % GHASH_BLOCK_SIZE;
if (partial) {
struct ghash_key *key = crypto_shash_ctx(desc->tfm);
memset(ctx->buf + partial, 0, GHASH_BLOCK_SIZE - partial);
kernel_neon_begin_partial(8);
pmull_ghash_update(1, ctx->digest, ctx->buf, key, NULL);
kernel_neon_end();
}
put_unaligned_be64(ctx->digest[1], dst);
put_unaligned_be64(ctx->digest[0], dst + 8);
*ctx = (struct ghash_desc_ctx){};
return 0;
}
static int ghash_setkey(struct crypto_shash *tfm,
const u8 *inkey, unsigned int keylen)
{
struct ghash_key *key = crypto_shash_ctx(tfm);
u64 a, b;
if (keylen != GHASH_BLOCK_SIZE) {
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
b = get_unaligned_be64(inkey);
a = get_unaligned_be64(inkey + 8);
key->a = (a << 1) | (b >> 63);
key->b = (b << 1) | (a >> 63);
if (b >> 63)
key->b ^= 0xc200000000000000UL;
return 0;
}
static int __init ghash_ce_mod_init(void)
{
return crypto_register_shash(&ghash_alg);
}
static void __exit ghash_ce_mod_exit(void)
{
crypto_unregister_shash(&ghash_alg);
}
