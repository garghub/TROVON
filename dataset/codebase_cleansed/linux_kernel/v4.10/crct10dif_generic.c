static int chksum_init(struct shash_desc *desc)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
ctx->crc = 0;
return 0;
}
static int chksum_update(struct shash_desc *desc, const u8 *data,
unsigned int length)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
ctx->crc = crc_t10dif_generic(ctx->crc, data, length);
return 0;
}
static int chksum_final(struct shash_desc *desc, u8 *out)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
*(__u16 *)out = ctx->crc;
return 0;
}
static int __chksum_finup(__u16 *crcp, const u8 *data, unsigned int len,
u8 *out)
{
*(__u16 *)out = crc_t10dif_generic(*crcp, data, len);
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
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
return __chksum_finup(&ctx->crc, data, length, out);
}
static int __init crct10dif_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit crct10dif_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
