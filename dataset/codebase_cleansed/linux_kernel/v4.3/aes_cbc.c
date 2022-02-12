static int p8_aes_cbc_init(struct crypto_tfm *tfm)
{
const char *alg;
struct crypto_blkcipher *fallback;
struct p8_aes_cbc_ctx *ctx = crypto_tfm_ctx(tfm);
if (!(alg = crypto_tfm_alg_name(tfm))) {
printk(KERN_ERR "Failed to get algorithm name.\n");
return -ENOENT;
}
fallback =
crypto_alloc_blkcipher(alg, 0, CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(fallback)) {
printk(KERN_ERR
"Failed to allocate transformation for '%s': %ld\n",
alg, PTR_ERR(fallback));
return PTR_ERR(fallback);
}
printk(KERN_INFO "Using '%s' as fallback implementation.\n",
crypto_tfm_alg_driver_name((struct crypto_tfm *) fallback));
crypto_blkcipher_set_flags(
fallback,
crypto_blkcipher_get_flags((struct crypto_blkcipher *)tfm));
ctx->fallback = fallback;
return 0;
}
static void p8_aes_cbc_exit(struct crypto_tfm *tfm)
{
struct p8_aes_cbc_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->fallback) {
crypto_free_blkcipher(ctx->fallback);
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
enable_kernel_altivec();
enable_kernel_vsx();
ret = aes_p8_set_encrypt_key(key, keylen * 8, &ctx->enc_key);
ret += aes_p8_set_decrypt_key(key, keylen * 8, &ctx->dec_key);
pagefault_enable();
preempt_enable();
ret += crypto_blkcipher_setkey(ctx->fallback, key, keylen);
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
struct blkcipher_desc fallback_desc = {
.tfm = ctx->fallback,
.info = desc->info,
.flags = desc->flags
};
if (in_interrupt()) {
ret = crypto_blkcipher_encrypt(&fallback_desc, dst, src,
nbytes);
} else {
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
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
struct blkcipher_desc fallback_desc = {
.tfm = ctx->fallback,
.info = desc->info,
.flags = desc->flags
};
if (in_interrupt()) {
ret = crypto_blkcipher_decrypt(&fallback_desc, dst, src,
nbytes);
} else {
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
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
pagefault_enable();
preempt_enable();
}
return ret;
}
