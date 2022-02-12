static void *lz4hc_alloc_ctx(struct crypto_scomp *tfm)
{
void *ctx;
ctx = vmalloc(LZ4HC_MEM_COMPRESS);
if (!ctx)
return ERR_PTR(-ENOMEM);
return ctx;
}
static int lz4hc_init(struct crypto_tfm *tfm)
{
struct lz4hc_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->lz4hc_comp_mem = lz4hc_alloc_ctx(NULL);
if (IS_ERR(ctx->lz4hc_comp_mem))
return -ENOMEM;
return 0;
}
static void lz4hc_free_ctx(struct crypto_scomp *tfm, void *ctx)
{
vfree(ctx);
}
static void lz4hc_exit(struct crypto_tfm *tfm)
{
struct lz4hc_ctx *ctx = crypto_tfm_ctx(tfm);
lz4hc_free_ctx(NULL, ctx->lz4hc_comp_mem);
}
static int __lz4hc_compress_crypto(const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen, void *ctx)
{
size_t tmp_len = *dlen;
int err;
err = lz4hc_compress(src, slen, dst, &tmp_len, ctx);
if (err < 0)
return -EINVAL;
*dlen = tmp_len;
return 0;
}
static int lz4hc_scompress(struct crypto_scomp *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen,
void *ctx)
{
return __lz4hc_compress_crypto(src, slen, dst, dlen, ctx);
}
static int lz4hc_compress_crypto(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst,
unsigned int *dlen)
{
struct lz4hc_ctx *ctx = crypto_tfm_ctx(tfm);
return __lz4hc_compress_crypto(src, slen, dst, dlen,
ctx->lz4hc_comp_mem);
}
static int __lz4hc_decompress_crypto(const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen, void *ctx)
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
static int lz4hc_sdecompress(struct crypto_scomp *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen,
void *ctx)
{
return __lz4hc_decompress_crypto(src, slen, dst, dlen, NULL);
}
static int lz4hc_decompress_crypto(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst,
unsigned int *dlen)
{
return __lz4hc_decompress_crypto(src, slen, dst, dlen, NULL);
}
static int __init lz4hc_mod_init(void)
{
int ret;
ret = crypto_register_alg(&alg_lz4hc);
if (ret)
return ret;
ret = crypto_register_scomp(&scomp);
if (ret) {
crypto_unregister_alg(&alg_lz4hc);
return ret;
}
return ret;
}
static void __exit lz4hc_mod_fini(void)
{
crypto_unregister_alg(&alg_lz4hc);
crypto_unregister_scomp(&scomp);
}
