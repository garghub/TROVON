static int p8_aes_cbc_init(struct crypto_tfm *tfm)
{
const char *alg = crypto_tfm_alg_name(tfm);
struct crypto_skcipher *fallback;
struct p8_aes_cbc_ctx *ctx = crypto_tfm_ctx(tfm);
fallback = crypto_alloc_skcipher(alg, 0,
CRYPTO_ALG_ASYNC | CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(fallback)) {
printk(KERN_ERR
"Failed to allocate transformation for '%s': %ld\n",
alg, PTR_ERR(fallback));
return PTR_ERR(fallback);
}
printk(KERN_INFO "Using '%s' as fallback implementation.\n",
crypto_skcipher_driver_name(fallback));
crypto_skcipher_set_flags(
fallback,
crypto_skcipher_get_flags((struct crypto_skcipher *)tfm));
ctx->fallback = fallback;
return 0;
}
static void p8_aes_cbc_exit(struct crypto_tfm *tfm)
{
struct p8_aes_cbc_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->fallback) {
crypto_free_skcipher(ctx->fallback);
ctx->fallback = NULL;
}
}
static int p8_aes_cbc_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
int ret;
struct p8_aes_cbc_ctx *ctx = crypto_tfm_ctx(tfm);
preempt_disable();
pagefault_disable();
enable_kernel_vsx();
ret = aes_p8_set_encrypt_key(key, keylen * 8, &ctx->enc_key);
ret += aes_p8_set_decrypt_key(key, keylen * 8, &ctx->dec_key);
disable_kernel_vsx();
pagefault_enable();
preempt_enable();
ret += crypto_skcipher_setkey(ctx->fallback, key, keylen);
return ret;
}
static int p8_aes_cbc_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
int ret;
struct blkcipher_walk walk;
struct p8_aes_cbc_ctx *ctx =
crypto_tfm_ctx(crypto_blkcipher_tfm(desc->tfm));
if (in_interrupt()) {
SKCIPHER_REQUEST_ON_STACK(req, ctx->fallback);
skcipher_request_set_tfm(req, ctx->fallback);
skcipher_request_set_callback(req, desc->flags, NULL, NULL);
skcipher_request_set_crypt(req, src, dst, nbytes, desc->info);
ret = crypto_skcipher_encrypt(req);
skcipher_request_zero(req);
} else {
preempt_disable();
pagefault_disable();
enable_kernel_vsx();
blkcipher_walk_init(&walk, dst, src, nbytes);
ret = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
aes_p8_cbc_encrypt(walk.src.virt.addr,
walk.dst.virt.addr,
nbytes & AES_BLOCK_MASK,
&ctx->enc_key, walk.iv, 1);
nbytes &= AES_BLOCK_SIZE - 1;
ret = blkcipher_walk_done(desc, &walk, nbytes);
}
disable_kernel_vsx();
pagefault_enable();
preempt_enable();
}
return ret;
}
static int p8_aes_cbc_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
int ret;
struct blkcipher_walk walk;
struct p8_aes_cbc_ctx *ctx =
crypto_tfm_ctx(crypto_blkcipher_tfm(desc->tfm));
if (in_interrupt()) {
SKCIPHER_REQUEST_ON_STACK(req, ctx->fallback);
skcipher_request_set_tfm(req, ctx->fallback);
skcipher_request_set_callback(req, desc->flags, NULL, NULL);
skcipher_request_set_crypt(req, src, dst, nbytes, desc->info);
ret = crypto_skcipher_decrypt(req);
skcipher_request_zero(req);
} else {
preempt_disable();
pagefault_disable();
enable_kernel_vsx();
blkcipher_walk_init(&walk, dst, src, nbytes);
ret = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
aes_p8_cbc_encrypt(walk.src.virt.addr,
walk.dst.virt.addr,
nbytes & AES_BLOCK_MASK,
&ctx->dec_key, walk.iv, 0);
nbytes &= AES_BLOCK_SIZE - 1;
ret = blkcipher_walk_done(desc, &walk, nbytes);
}
disable_kernel_vsx();
pagefault_enable();
preempt_enable();
}
return ret;
}
