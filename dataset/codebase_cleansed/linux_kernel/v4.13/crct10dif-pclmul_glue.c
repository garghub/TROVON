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
if (irq_fpu_usable()) {
kernel_fpu_begin();
ctx->crc = crc_t10dif_pcl(ctx->crc, data, length);
kernel_fpu_end();
} else
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
if (irq_fpu_usable()) {
kernel_fpu_begin();
*(__u16 *)out = crc_t10dif_pcl(*crcp, data, len);
kernel_fpu_end();
} else
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
static int __init crct10dif_intel_mod_init(void)
{
if (!x86_match_cpu(crct10dif_cpu_id))
return -ENODEV;
return crypto_register_shash(&alg);
}
static void __exit crct10dif_intel_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
