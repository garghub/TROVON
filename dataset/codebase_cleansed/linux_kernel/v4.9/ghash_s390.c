static int ghash_init(struct shash_desc *desc)
{
struct ghash_desc_ctx *dctx = shash_desc_ctx(desc);
struct ghash_ctx *ctx = crypto_shash_ctx(desc->tfm);
memset(dctx, 0, sizeof(*dctx));
memcpy(dctx->key, ctx->key, GHASH_BLOCK_SIZE);
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
memcpy(ctx->key, key, GHASH_BLOCK_SIZE);
return 0;
}
static int ghash_update(struct shash_desc *desc,
const u8 *src, unsigned int srclen)
{
struct ghash_desc_ctx *dctx = shash_desc_ctx(desc);
unsigned int n;
u8 *buf = dctx->buffer;
if (dctx->bytes) {
u8 *pos = buf + (GHASH_BLOCK_SIZE - dctx->bytes);
n = min(srclen, dctx->bytes);
dctx->bytes -= n;
srclen -= n;
memcpy(pos, src, n);
src += n;
if (!dctx->bytes) {
cpacf_kimd(CPACF_KIMD_GHASH, dctx, buf,
GHASH_BLOCK_SIZE);
}
}
n = srclen & ~(GHASH_BLOCK_SIZE - 1);
if (n) {
cpacf_kimd(CPACF_KIMD_GHASH, dctx, src, n);
src += n;
srclen -= n;
}
if (srclen) {
dctx->bytes = GHASH_BLOCK_SIZE - srclen;
memcpy(buf, src, srclen);
}
return 0;
}
static int ghash_flush(struct ghash_desc_ctx *dctx)
{
u8 *buf = dctx->buffer;
if (dctx->bytes) {
u8 *pos = buf + (GHASH_BLOCK_SIZE - dctx->bytes);
memset(pos, 0, dctx->bytes);
cpacf_kimd(CPACF_KIMD_GHASH, dctx, buf, GHASH_BLOCK_SIZE);
dctx->bytes = 0;
}
return 0;
}
static int ghash_final(struct shash_desc *desc, u8 *dst)
{
struct ghash_desc_ctx *dctx = shash_desc_ctx(desc);
int ret;
ret = ghash_flush(dctx);
if (!ret)
memcpy(dst, dctx->icv, GHASH_BLOCK_SIZE);
return ret;
}
static int __init ghash_mod_init(void)
{
if (!cpacf_query_func(CPACF_KIMD, CPACF_KIMD_GHASH))
return -EOPNOTSUPP;
return crypto_register_shash(&ghash_alg);
}
static void __exit ghash_mod_exit(void)
{
crypto_unregister_shash(&ghash_alg);
}
