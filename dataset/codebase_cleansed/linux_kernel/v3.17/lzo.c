static int lzo_init(struct crypto_tfm *tfm)
{
struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->lzo_comp_mem = kmalloc(LZO1X_MEM_COMPRESS,
GFP_KERNEL | __GFP_NOWARN | __GFP_REPEAT);
if (!ctx->lzo_comp_mem)
ctx->lzo_comp_mem = vmalloc(LZO1X_MEM_COMPRESS);
if (!ctx->lzo_comp_mem)
return -ENOMEM;
return 0;
}
static void lzo_exit(struct crypto_tfm *tfm)
{
struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);
kvfree(ctx->lzo_comp_mem);
}
static int lzo_compress(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);
size_t tmp_len = *dlen;
int err;
err = lzo1x_1_compress(src, slen, dst, &tmp_len, ctx->lzo_comp_mem);
if (err != LZO_E_OK)
return -EINVAL;
*dlen = tmp_len;
return 0;
}
static int lzo_decompress(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
int err;
size_t tmp_len = *dlen;
err = lzo1x_decompress_safe(src, slen, dst, &tmp_len);
if (err != LZO_E_OK)
return -EINVAL;
*dlen = tmp_len;
return 0;
}
static int __init lzo_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit lzo_mod_fini(void)
{
crypto_unregister_alg(&alg);
}
