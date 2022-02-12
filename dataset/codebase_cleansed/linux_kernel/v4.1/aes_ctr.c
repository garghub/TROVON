static int p8_aes_ctr_init(struct crypto_tfm *tfm)
{
const char *alg;
struct crypto_blkcipher *fallback;
struct p8_aes_ctr_ctx *ctx = crypto_tfm_ctx(tfm);
if (!(alg = crypto_tfm_alg_name(tfm))) {
printk(KERN_ERR "Failed to get algorithm name.\n");
return -ENOENT;
}
fallback = crypto_alloc_blkcipher(alg, 0 ,CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(fallback)) {
printk(KERN_ERR "Failed to allocate transformation for '%s': %ld\n",
alg, PTR_ERR(fallback));
return PTR_ERR(fallback);
}
printk(KERN_INFO "Using '%s' as fallback implementation.\n",
crypto_tfm_alg_driver_name((struct crypto_tfm *) fallback));
crypto_blkcipher_set_flags(fallback,
crypto_blkcipher_get_flags((struct crypto_blkcipher *) tfm));
ctx->fallback = fallback;
return 0;
}
static void p8_aes_ctr_exit(struct crypto_tfm *tfm)
{
struct p8_aes_ctr_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->fallback) {
crypto_free_blkcipher(ctx->fallback);
ctx->fallback = NULL;
}
}
static int p8_aes_ctr_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
int ret;
struct p8_aes_ctr_ctx *ctx = crypto_tfm_ctx(tfm);
pagefault_disable();
enable_kernel_altivec();
ret = aes_p8_set_encrypt_key(key, keylen * 8, &ctx->enc_key);
pagefault_enable();
ret += crypto_blkcipher_setkey(ctx->fallback, key, keylen);
return ret;
}
static void p8_aes_ctr_final(struct p8_aes_ctr_ctx *ctx,
struct blkcipher_walk *walk)
{
u8 *ctrblk = walk->iv;
u8 keystream[AES_BLOCK_SIZE];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
pagefault_disable();
enable_kernel_altivec();
aes_p8_encrypt(ctrblk, keystream, &ctx->enc_key);
pagefault_enable();
crypto_xor(keystream, src, nbytes);
memcpy(dst, keystream, nbytes);
crypto_inc(ctrblk, AES_BLOCK_SIZE);
}
static int p8_aes_ctr_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
int ret;
struct blkcipher_walk walk;
struct p8_aes_ctr_ctx *ctx = crypto_tfm_ctx(
crypto_blkcipher_tfm(desc->tfm));
struct blkcipher_desc fallback_desc = {
.tfm = ctx->fallback,
.info = desc->info,
.flags = desc->flags
};
if (in_interrupt()) {
ret = crypto_blkcipher_encrypt(&fallback_desc, dst, src, nbytes);
} else {
blkcipher_walk_init(&walk, dst, src, nbytes);
ret = blkcipher_walk_virt_block(desc, &walk, AES_BLOCK_SIZE);
while ((nbytes = walk.nbytes) >= AES_BLOCK_SIZE) {
pagefault_disable();
enable_kernel_altivec();
aes_p8_ctr32_encrypt_blocks(walk.src.virt.addr, walk.dst.virt.addr,
(nbytes & AES_BLOCK_MASK)/AES_BLOCK_SIZE, &ctx->enc_key, walk.iv);
pagefault_enable();
crypto_inc(walk.iv, AES_BLOCK_SIZE);
nbytes &= AES_BLOCK_SIZE - 1;
ret = blkcipher_walk_done(desc, &walk, nbytes);
}
if (walk.nbytes) {
p8_aes_ctr_final(ctx, &walk);
ret = blkcipher_walk_done(desc, &walk, 0);
}
}
return ret;
}
