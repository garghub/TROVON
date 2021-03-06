static int p8_aes_init(struct crypto_tfm *tfm)
{
const char *alg;
struct crypto_cipher *fallback;
struct p8_aes_ctx *ctx = crypto_tfm_ctx(tfm);
if (!(alg = crypto_tfm_alg_name(tfm))) {
printk(KERN_ERR "Failed to get algorithm name.\n");
return -ENOENT;
}
fallback = crypto_alloc_cipher(alg, 0, CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(fallback)) {
printk(KERN_ERR
"Failed to allocate transformation for '%s': %ld\n",
alg, PTR_ERR(fallback));
return PTR_ERR(fallback);
}
printk(KERN_INFO "Using '%s' as fallback implementation.\n",
crypto_tfm_alg_driver_name((struct crypto_tfm *) fallback));
crypto_cipher_set_flags(fallback,
crypto_cipher_get_flags((struct
crypto_cipher *)
tfm));
ctx->fallback = fallback;
return 0;
}
static void p8_aes_exit(struct crypto_tfm *tfm)
{
struct p8_aes_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->fallback) {
crypto_free_cipher(ctx->fallback);
ctx->fallback = NULL;
}
}
static int p8_aes_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
int ret;
struct p8_aes_ctx *ctx = crypto_tfm_ctx(tfm);
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
ret = aes_p8_set_encrypt_key(key, keylen * 8, &ctx->enc_key);
ret += aes_p8_set_decrypt_key(key, keylen * 8, &ctx->dec_key);
pagefault_enable();
preempt_enable();
ret += crypto_cipher_setkey(ctx->fallback, key, keylen);
return ret;
}
static void p8_aes_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct p8_aes_ctx *ctx = crypto_tfm_ctx(tfm);
if (in_interrupt()) {
crypto_cipher_encrypt_one(ctx->fallback, dst, src);
} else {
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
aes_p8_encrypt(src, dst, &ctx->enc_key);
pagefault_enable();
preempt_enable();
}
}
static void p8_aes_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct p8_aes_ctx *ctx = crypto_tfm_ctx(tfm);
if (in_interrupt()) {
crypto_cipher_decrypt_one(ctx->fallback, dst, src);
} else {
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
aes_p8_decrypt(src, dst, &ctx->dec_key);
pagefault_enable();
preempt_enable();
}
}
