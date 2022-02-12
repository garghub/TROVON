static int crc32_vx_cra_init_zero(struct crypto_tfm *tfm)
{
struct crc_ctx *mctx = crypto_tfm_ctx(tfm);
mctx->key = 0;
return 0;
}
static int crc32_vx_cra_init_invert(struct crypto_tfm *tfm)
{
struct crc_ctx *mctx = crypto_tfm_ctx(tfm);
mctx->key = ~0;
return 0;
}
static int crc32_vx_init(struct shash_desc *desc)
{
struct crc_ctx *mctx = crypto_shash_ctx(desc->tfm);
struct crc_desc_ctx *ctx = shash_desc_ctx(desc);
ctx->crc = mctx->key;
return 0;
}
static int crc32_vx_setkey(struct crypto_shash *tfm, const u8 *newkey,
unsigned int newkeylen)
{
struct crc_ctx *mctx = crypto_shash_ctx(tfm);
if (newkeylen != sizeof(mctx->key)) {
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
mctx->key = le32_to_cpu(*(__le32 *)newkey);
return 0;
}
static int crc32be_vx_setkey(struct crypto_shash *tfm, const u8 *newkey,
unsigned int newkeylen)
{
struct crc_ctx *mctx = crypto_shash_ctx(tfm);
if (newkeylen != sizeof(mctx->key)) {
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
mctx->key = be32_to_cpu(*(__be32 *)newkey);
return 0;
}
static int crc32le_vx_final(struct shash_desc *desc, u8 *out)
{
struct crc_desc_ctx *ctx = shash_desc_ctx(desc);
*(__le32 *)out = cpu_to_le32p(&ctx->crc);
return 0;
}
static int crc32be_vx_final(struct shash_desc *desc, u8 *out)
{
struct crc_desc_ctx *ctx = shash_desc_ctx(desc);
*(__be32 *)out = cpu_to_be32p(&ctx->crc);
return 0;
}
static int crc32c_vx_final(struct shash_desc *desc, u8 *out)
{
struct crc_desc_ctx *ctx = shash_desc_ctx(desc);
*(__le32 *)out = ~cpu_to_le32p(&ctx->crc);
return 0;
}
static int __crc32le_vx_finup(u32 *crc, const u8 *data, unsigned int len,
u8 *out)
{
*(__le32 *)out = cpu_to_le32(crc32_le_vx(*crc, data, len));
return 0;
}
static int __crc32be_vx_finup(u32 *crc, const u8 *data, unsigned int len,
u8 *out)
{
*(__be32 *)out = cpu_to_be32(crc32_be_vx(*crc, data, len));
return 0;
}
static int __crc32c_vx_finup(u32 *crc, const u8 *data, unsigned int len,
u8 *out)
{
*(__le32 *)out = ~cpu_to_le32(crc32c_le_vx(*crc, data, len));
return 0;
}
static int __init crc_vx_mod_init(void)
{
return crypto_register_shashes(crc32_vx_algs,
ARRAY_SIZE(crc32_vx_algs));
}
static void __exit crc_vx_mod_exit(void)
{
crypto_unregister_shashes(crc32_vx_algs, ARRAY_SIZE(crc32_vx_algs));
}
