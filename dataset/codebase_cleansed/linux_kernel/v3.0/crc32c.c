static u32 crc32c(u32 crc, const u8 *data, unsigned int length)
{
while (length--)
crc = crc32c_table[(crc ^ *data++) & 0xFFL] ^ (crc >> 8);
return crc;
}
static int chksum_init(struct shash_desc *desc)
{
struct chksum_ctx *mctx = crypto_shash_ctx(desc->tfm);
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
ctx->crc = mctx->key;
return 0;
}
static int chksum_setkey(struct crypto_shash *tfm, const u8 *key,
unsigned int keylen)
{
struct chksum_ctx *mctx = crypto_shash_ctx(tfm);
if (keylen != sizeof(mctx->key)) {
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
mctx->key = le32_to_cpu(*(__le32 *)key);
return 0;
}
static int chksum_update(struct shash_desc *desc, const u8 *data,
unsigned int length)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
ctx->crc = crc32c(ctx->crc, data, length);
return 0;
}
static int chksum_final(struct shash_desc *desc, u8 *out)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
*(__le32 *)out = ~cpu_to_le32p(&ctx->crc);
return 0;
}
static int __chksum_finup(u32 *crcp, const u8 *data, unsigned int len, u8 *out)
{
*(__le32 *)out = ~cpu_to_le32(crc32c(*crcp, data, len));
return 0;
}
static int chksum_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
return __chksum_finup(&ctx->crc, data, len, out);
}
static int chksum_digest(struct shash_desc *desc, const u8 *data,
unsigned int length, u8 *out)
{
struct chksum_ctx *mctx = crypto_shash_ctx(desc->tfm);
return __chksum_finup(&mctx->key, data, length, out);
}
static int crc32c_cra_init(struct crypto_tfm *tfm)
{
struct chksum_ctx *mctx = crypto_tfm_ctx(tfm);
mctx->key = ~0;
return 0;
}
static int __init crc32c_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit crc32c_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
