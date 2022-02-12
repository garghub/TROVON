static int ghash_init(struct shash_desc *desc)
{
struct ghash_desc_ctx *dctx = shash_desc_ctx(desc);
memset(dctx, 0, sizeof(*dctx));
return 0;
}
static int ghash_setkey(struct crypto_shash *tfm,
const u8 *key, unsigned int keylen)
{
struct ghash_ctx *ctx = crypto_shash_ctx(tfm);
if (keylen != GHASH_BLOCK_SIZE) {
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
if (ctx->gf128)
gf128mul_free_4k(ctx->gf128);
ctx->gf128 = gf128mul_init_4k_lle((be128 *)key);
if (!ctx->gf128)
return -ENOMEM;
return 0;
}
static int ghash_update(struct shash_desc *desc,
const u8 *src, unsigned int srclen)
{
struct ghash_desc_ctx *dctx = shash_desc_ctx(desc);
struct ghash_ctx *ctx = crypto_shash_ctx(desc->tfm);
u8 *dst = dctx->buffer;
if (dctx->bytes) {
int n = min(srclen, dctx->bytes);
u8 *pos = dst + (GHASH_BLOCK_SIZE - dctx->bytes);
dctx->bytes -= n;
srclen -= n;
while (n--)
*pos++ ^= *src++;
if (!dctx->bytes)
gf128mul_4k_lle((be128 *)dst, ctx->gf128);
}
while (srclen >= GHASH_BLOCK_SIZE) {
crypto_xor(dst, src, GHASH_BLOCK_SIZE);
gf128mul_4k_lle((be128 *)dst, ctx->gf128);
src += GHASH_BLOCK_SIZE;
srclen -= GHASH_BLOCK_SIZE;
}
if (srclen) {
dctx->bytes = GHASH_BLOCK_SIZE - srclen;
while (srclen--)
*dst++ ^= *src++;
}
return 0;
}
static void ghash_flush(struct ghash_ctx *ctx, struct ghash_desc_ctx *dctx)
{
u8 *dst = dctx->buffer;
if (dctx->bytes) {
u8 *tmp = dst + (GHASH_BLOCK_SIZE - dctx->bytes);
while (dctx->bytes--)
*tmp++ ^= 0;
gf128mul_4k_lle((be128 *)dst, ctx->gf128);
}
dctx->bytes = 0;
}
static int ghash_final(struct shash_desc *desc, u8 *dst)
{
struct ghash_desc_ctx *dctx = shash_desc_ctx(desc);
struct ghash_ctx *ctx = crypto_shash_ctx(desc->tfm);
u8 *buf = dctx->buffer;
ghash_flush(ctx, dctx);
memcpy(dst, buf, GHASH_BLOCK_SIZE);
return 0;
}
static void ghash_exit_tfm(struct crypto_tfm *tfm)
{
struct ghash_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->gf128)
gf128mul_free_4k(ctx->gf128);
}
static int __init ghash_mod_init(void)
{
return crypto_register_shash(&ghash_alg);
}
static void __exit ghash_mod_exit(void)
{
crypto_unregister_shash(&ghash_alg);
}
