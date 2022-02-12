static int crypto842_compress(struct crypto_tfm *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
struct crypto842_ctx *ctx = crypto_tfm_ctx(tfm);
return sw842_compress(src, slen, dst, dlen, ctx->wmem);
}
static int crypto842_decompress(struct crypto_tfm *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int *dlen)
{
return sw842_decompress(src, slen, dst, dlen);
}
static int __init crypto842_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit crypto842_mod_exit(void)
{
crypto_unregister_alg(&alg);
}
