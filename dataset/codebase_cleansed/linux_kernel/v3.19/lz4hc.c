static int lz4hc_init(struct crypto_tfm *tfm)
{
struct lz4hc_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->lz4hc_comp_mem = vmalloc(LZ4HC_MEM_COMPRESS);
if (!ctx->lz4hc_comp_mem)
return -ENOMEM;
return 0;
}
static void lz4hc_exit(struct crypto_tfm *tfm)
{
struct lz4hc_ctx *ctx = crypto_tfm_ctx(tfm);
vfree(ctx->lz4hc_comp_mem);
}
static int lz4hc_compress_crypto(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
struct lz4hc_ctx *ctx = crypto_tfm_ctx(tfm);
size_t tmp_len = *dlen;
int err;
err = lz4hc_compress(src, slen, dst, &tmp_len, ctx->lz4hc_comp_mem);
if (err < 0)
return -EINVAL;
*dlen = tmp_len;
return 0;
}
static int lz4hc_decompress_crypto(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
int err;
size_t tmp_len = *dlen;
size_t __slen = slen;
err = lz4_decompress_unknownoutputsize(src, __slen, dst, &tmp_len);
if (err < 0)
return -EINVAL;
*dlen = tmp_len;
return err;
}
static int __init lz4hc_mod_init(void)
{
return crypto_register_alg(&alg_lz4hc);
}
static void __exit lz4hc_mod_fini(void)
{
crypto_unregister_alg(&alg_lz4hc);
}
