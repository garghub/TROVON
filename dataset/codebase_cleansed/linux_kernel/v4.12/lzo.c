static void *lzo_alloc_ctx(struct crypto_scomp *tfm)
{
void *ctx;
ctx = kvmalloc(LZO1X_MEM_COMPRESS, GFP_KERNEL);
if (!ctx)
return ERR_PTR(-ENOMEM);
return ctx;
}
static int lzo_init(struct crypto_tfm *tfm)
{
struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->lzo_comp_mem = lzo_alloc_ctx(NULL);
if (IS_ERR(ctx->lzo_comp_mem))
return -ENOMEM;
return 0;
}
static void lzo_free_ctx(struct crypto_scomp *tfm, void *ctx)
{
kvfree(ctx);
}
static void lzo_exit(struct crypto_tfm *tfm)
{
struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);
lzo_free_ctx(NULL, ctx->lzo_comp_mem);
}
static int __lzo_compress(const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen, void *ctx)
{
size_t tmp_len = *dlen;
int err;
err = lzo1x_1_compress(src, slen, dst, &tmp_len, ctx);
if (err != LZO_E_OK)
return -EINVAL;
*dlen = tmp_len;
return 0;
}
static int lzo_compress(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);
return __lzo_compress(src, slen, dst, dlen, ctx->lzo_comp_mem);
}
static int lzo_scompress(struct crypto_scomp *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen,
void *ctx)
{
return __lzo_compress(src, slen, dst, dlen, ctx);
}
static int __lzo_decompress(const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
int err;
size_t tmp_len = *dlen;
err = lzo1x_decompress_safe(src, slen, dst, &tmp_len);
if (err != LZO_E_OK)
return -EINVAL;
*dlen = tmp_len;
return 0;
}
static int lzo_decompress(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
return __lzo_decompress(src, slen, dst, dlen);
}
static int lzo_sdecompress(struct crypto_scomp *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen,
void *ctx)
{
return __lzo_decompress(src, slen, dst, dlen);
}
static int __init lzo_mod_init(void)
{
int ret;
ret = crypto_register_alg(&alg);
if (ret)
return ret;
ret = crypto_register_scomp(&scomp);
if (ret) {
crypto_unregister_alg(&alg);
return ret;
}
return ret;
}
static void __exit lzo_mod_fini(void)
{
crypto_unregister_alg(&alg);
crypto_unregister_scomp(&scomp);
}
