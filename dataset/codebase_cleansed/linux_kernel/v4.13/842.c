static void *crypto842_alloc_ctx(struct crypto_scomp *tfm)
{
void *ctx;
ctx = kmalloc(SW842_MEM_COMPRESS, GFP_KERNEL);
if (!ctx)
return ERR_PTR(-ENOMEM);
return ctx;
}
static int crypto842_init(struct crypto_tfm *tfm)
{
struct crypto842_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->wmem = crypto842_alloc_ctx(NULL);
if (IS_ERR(ctx->wmem))
return -ENOMEM;
return 0;
}
static void crypto842_free_ctx(struct crypto_scomp *tfm, void *ctx)
{
kfree(ctx);
}
static void crypto842_exit(struct crypto_tfm *tfm)
{
struct crypto842_ctx *ctx = crypto_tfm_ctx(tfm);
crypto842_free_ctx(NULL, ctx->wmem);
}
static int crypto842_compress(struct crypto_tfm *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
struct crypto842_ctx *ctx = crypto_tfm_ctx(tfm);
return sw842_compress(src, slen, dst, dlen, ctx->wmem);
}
static int crypto842_scompress(struct crypto_scomp *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen, void *ctx)
{
return sw842_compress(src, slen, dst, dlen, ctx);
}
static int crypto842_decompress(struct crypto_tfm *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
return sw842_decompress(src, slen, dst, dlen);
}
static int crypto842_sdecompress(struct crypto_scomp *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen, void *ctx)
{
return sw842_decompress(src, slen, dst, dlen);
}
static int __init crypto842_mod_init(void)
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
static void __exit crypto842_mod_exit(void)
{
crypto_unregister_alg(&alg);
crypto_unregister_scomp(&scomp);
}
