static int p8_ghash_init_tfm(struct crypto_tfm *tfm)
{
const char *alg;
struct crypto_shash *fallback;
struct crypto_shash *shash_tfm = __crypto_shash_cast(tfm);
struct p8_ghash_ctx *ctx = crypto_tfm_ctx(tfm);
if (!(alg = crypto_tfm_alg_name(tfm))) {
printk(KERN_ERR "Failed to get algorithm name.\n");
return -ENOENT;
}
fallback = crypto_alloc_shash(alg, 0, CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(fallback)) {
printk(KERN_ERR
"Failed to allocate transformation for '%s': %ld\n",
alg, PTR_ERR(fallback));
return PTR_ERR(fallback);
}
printk(KERN_INFO "Using '%s' as fallback implementation.\n",
crypto_tfm_alg_driver_name(crypto_shash_tfm(fallback)));
crypto_shash_set_flags(fallback,
crypto_shash_get_flags((struct crypto_shash
*) tfm));
ctx->fallback = fallback;
shash_tfm->descsize = sizeof(struct p8_ghash_desc_ctx)
+ crypto_shash_descsize(fallback);
return 0;
}
static void p8_ghash_exit_tfm(struct crypto_tfm *tfm)
{
struct p8_ghash_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->fallback) {
crypto_free_shash(ctx->fallback);
ctx->fallback = NULL;
}
}
static int p8_ghash_init(struct shash_desc *desc)
{
struct p8_ghash_ctx *ctx = crypto_tfm_ctx(crypto_shash_tfm(desc->tfm));
struct p8_ghash_desc_ctx *dctx = shash_desc_ctx(desc);
dctx->bytes = 0;
memset(dctx->shash, 0, GHASH_DIGEST_SIZE);
dctx->fallback_desc.tfm = ctx->fallback;
dctx->fallback_desc.flags = desc->flags;
return crypto_shash_init(&dctx->fallback_desc);
}
static int p8_ghash_setkey(struct crypto_shash *tfm, const u8 *key,
unsigned int keylen)
{
struct p8_ghash_ctx *ctx = crypto_tfm_ctx(crypto_shash_tfm(tfm));
if (keylen != GHASH_KEY_LEN)
return -EINVAL;
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
enable_kernel_fp();
gcm_init_p8(ctx->htable, (const u64 *) key);
pagefault_enable();
preempt_enable();
return crypto_shash_setkey(ctx->fallback, key, keylen);
}
static int p8_ghash_update(struct shash_desc *desc,
const u8 *src, unsigned int srclen)
{
unsigned int len;
struct p8_ghash_ctx *ctx = crypto_tfm_ctx(crypto_shash_tfm(desc->tfm));
struct p8_ghash_desc_ctx *dctx = shash_desc_ctx(desc);
if (IN_INTERRUPT) {
return crypto_shash_update(&dctx->fallback_desc, src,
srclen);
} else {
if (dctx->bytes) {
if (dctx->bytes + srclen < GHASH_DIGEST_SIZE) {
memcpy(dctx->buffer + dctx->bytes, src,
srclen);
dctx->bytes += srclen;
return 0;
}
memcpy(dctx->buffer + dctx->bytes, src,
GHASH_DIGEST_SIZE - dctx->bytes);
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
enable_kernel_fp();
gcm_ghash_p8(dctx->shash, ctx->htable,
dctx->buffer, GHASH_DIGEST_SIZE);
pagefault_enable();
preempt_enable();
src += GHASH_DIGEST_SIZE - dctx->bytes;
srclen -= GHASH_DIGEST_SIZE - dctx->bytes;
dctx->bytes = 0;
}
len = srclen & ~(GHASH_DIGEST_SIZE - 1);
if (len) {
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
enable_kernel_fp();
gcm_ghash_p8(dctx->shash, ctx->htable, src, len);
pagefault_enable();
preempt_enable();
src += len;
srclen -= len;
}
if (srclen) {
memcpy(dctx->buffer, src, srclen);
dctx->bytes = srclen;
}
return 0;
}
}
static int p8_ghash_final(struct shash_desc *desc, u8 *out)
{
int i;
struct p8_ghash_ctx *ctx = crypto_tfm_ctx(crypto_shash_tfm(desc->tfm));
struct p8_ghash_desc_ctx *dctx = shash_desc_ctx(desc);
if (IN_INTERRUPT) {
return crypto_shash_final(&dctx->fallback_desc, out);
} else {
if (dctx->bytes) {
for (i = dctx->bytes; i < GHASH_DIGEST_SIZE; i++)
dctx->buffer[i] = 0;
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
enable_kernel_fp();
gcm_ghash_p8(dctx->shash, ctx->htable,
dctx->buffer, GHASH_DIGEST_SIZE);
pagefault_enable();
preempt_enable();
dctx->bytes = 0;
}
memcpy(out, dctx->shash, GHASH_DIGEST_SIZE);
return 0;
}
}
