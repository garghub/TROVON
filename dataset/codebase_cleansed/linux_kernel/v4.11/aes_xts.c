static int p8_aes_xts_init(struct crypto_tfm *tfm)
{
const char *alg;
struct crypto_skcipher *fallback;
struct p8_aes_xts_ctx *ctx = crypto_tfm_ctx(tfm);
if (!(alg = crypto_tfm_alg_name(tfm))) {
printk(KERN_ERR "Failed to get algorithm name.\n");
return -ENOENT;
}
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
static void p8_aes_xts_exit(struct crypto_tfm *tfm)
{
struct p8_aes_xts_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->fallback) {
crypto_free_skcipher(ctx->fallback);
ctx->fallback = NULL;
}
}
static int p8_aes_xts_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
int ret;
struct p8_aes_xts_ctx *ctx = crypto_tfm_ctx(tfm);
ret = xts_check_key(tfm, key, keylen);
if (ret)
return ret;
preempt_disable();
pagefault_disable();
enable_kernel_vsx();
ret = aes_p8_set_encrypt_key(key + keylen/2, (keylen/2) * 8, &ctx->tweak_key);
ret += aes_p8_set_encrypt_key(key, (keylen/2) * 8, &ctx->enc_key);
ret += aes_p8_set_decrypt_key(key, (keylen/2) * 8, &ctx->dec_key);
disable_kernel_vsx();
pagefault_enable();
preempt_enable();
ret += crypto_skcipher_setkey(ctx->fallback, key, keylen);
return ret;
}
static int p8_aes_xts_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src,
unsigned int nbytes, int enc)
{
int ret;
u8 tweak[AES_BLOCK_SIZE];
u8 *iv;
struct blkcipher_walk walk;
struct p8_aes_xts_ctx *ctx =
crypto_tfm_ctx(crypto_blkcipher_tfm(desc->tfm));
if (in_interrupt()) {
SKCIPHER_REQUEST_ON_STACK(req, ctx->fallback);
skcipher_request_set_tfm(req, ctx->fallback);
skcipher_request_set_callback(req, desc->flags, NULL, NULL);
skcipher_request_set_crypt(req, src, dst, nbytes, desc->info);
ret = enc? crypto_skcipher_encrypt(req) : crypto_skcipher_decrypt(req);
skcipher_request_zero(req);
} else {
preempt_disable();
pagefault_disable();
enable_kernel_vsx();
blkcipher_walk_init(&walk, dst, src, nbytes);
ret = blkcipher_walk_virt(desc, &walk);
iv = walk.iv;
memset(tweak, 0, AES_BLOCK_SIZE);
aes_p8_encrypt(iv, tweak, &ctx->tweak_key);
while ((nbytes = walk.nbytes)) {
if (enc)
aes_p8_xts_encrypt(walk.src.virt.addr, walk.dst.virt.addr,
nbytes & AES_BLOCK_MASK, &ctx->enc_key, NULL, tweak);
else
aes_p8_xts_decrypt(walk.src.virt.addr, walk.dst.virt.addr,
nbytes & AES_BLOCK_MASK, &ctx->dec_key, NULL, tweak);
nbytes &= AES_BLOCK_SIZE - 1;
ret = blkcipher_walk_done(desc, &walk, nbytes);
}
disable_kernel_vsx();
pagefault_enable();
preempt_enable();
}
return ret;
}
static int p8_aes_xts_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return p8_aes_xts_crypt(desc, dst, src, nbytes, 1);
}
static int p8_aes_xts_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return p8_aes_xts_crypt(desc, dst, src, nbytes, 0);
}
