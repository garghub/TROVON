static int aes_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_sparc64_aes_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
switch (key_len) {
case AES_KEYSIZE_128:
ctx->expanded_key_length = 0xb0;
ctx->ops = &aes128_ops;
break;
case AES_KEYSIZE_192:
ctx->expanded_key_length = 0xd0;
ctx->ops = &aes192_ops;
break;
case AES_KEYSIZE_256:
ctx->expanded_key_length = 0xf0;
ctx->ops = &aes256_ops;
break;
default:
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
aes_sparc64_key_expand((const u32 *)in_key, &ctx->key[0], key_len);
ctx->key_length = key_len;
return 0;
}
static void aes_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct crypto_sparc64_aes_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->ops->encrypt(&ctx->key[0], (const u32 *) src, (u32 *) dst);
}
static void aes_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct crypto_sparc64_aes_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->ops->decrypt(&ctx->key[0], (const u32 *) src, (u32 *) dst);
}
static int ecb_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_sparc64_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ctx->ops->load_encrypt_keys(&ctx->key[0]);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & AES_BLOCK_MASK;
if (likely(block_len)) {
ctx->ops->ecb_encrypt(&ctx->key[0],
(const u64 *)walk.src.virt.addr,
(u64 *) walk.dst.virt.addr,
block_len);
}
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int ecb_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_sparc64_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
u64 *key_end;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ctx->ops->load_decrypt_keys(&ctx->key[0]);
key_end = &ctx->key[ctx->expanded_key_length / sizeof(u64)];
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & AES_BLOCK_MASK;
if (likely(block_len)) {
ctx->ops->ecb_decrypt(key_end,
(const u64 *) walk.src.virt.addr,
(u64 *) walk.dst.virt.addr, block_len);
}
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int cbc_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_sparc64_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ctx->ops->load_encrypt_keys(&ctx->key[0]);
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & AES_BLOCK_MASK;
if (likely(block_len)) {
ctx->ops->cbc_encrypt(&ctx->key[0],
(const u64 *)walk.src.virt.addr,
(u64 *) walk.dst.virt.addr,
block_len, (u64 *) walk.iv);
}
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static int cbc_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_sparc64_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
u64 *key_end;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ctx->ops->load_decrypt_keys(&ctx->key[0]);
key_end = &ctx->key[ctx->expanded_key_length / sizeof(u64)];
while ((nbytes = walk.nbytes)) {
unsigned int block_len = nbytes & AES_BLOCK_MASK;
if (likely(block_len)) {
ctx->ops->cbc_decrypt(key_end,
(const u64 *) walk.src.virt.addr,
(u64 *) walk.dst.virt.addr,
block_len, (u64 *) walk.iv);
}
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
fprs_write(0);
return err;
}
static void ctr_crypt_final(struct crypto_sparc64_aes_ctx *ctx,
struct blkcipher_walk *walk)
{
u8 *ctrblk = walk->iv;
u64 keystream[AES_BLOCK_SIZE / sizeof(u64)];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
ctx->ops->ecb_encrypt(&ctx->key[0], (const u64 *)ctrblk,
keystream, AES_BLOCK_SIZE);
crypto_xor((u8 *) keystream, src, nbytes);
memcpy(dst, keystream, nbytes);
crypto_inc(ctrblk, AES_BLOCK_SIZE);
}
static int ctr_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_sparc64_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, AES_BLOCK_SIZE);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ctx->ops->load_encrypt_keys(&ctx->key[0]);
while ((nbytes = walk.nbytes) >= AES_BLOCK_SIZE) {
unsigned int block_len = nbytes & AES_BLOCK_MASK;
if (likely(block_len)) {
ctx->ops->ctr_crypt(&ctx->key[0],
(const u64 *)walk.src.virt.addr,
(u64 *) walk.dst.virt.addr,
block_len, (u64 *) walk.iv);
}
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
if (walk.nbytes) {
ctr_crypt_final(ctx, &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
fprs_write(0);
return err;
}
static bool __init sparc64_has_aes_opcode(void)
{
unsigned long cfr;
if (!(sparc64_elf_hwcap & HWCAP_SPARC_CRYPTO))
return false;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if (!(cfr & CFR_AES))
return false;
return true;
}
static int __init aes_sparc64_mod_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(algs); i++)
INIT_LIST_HEAD(&algs[i].cra_list);
if (sparc64_has_aes_opcode()) {
pr_info("Using sparc64 aes opcodes optimized AES implementation\n");
return crypto_register_algs(algs, ARRAY_SIZE(algs));
}
pr_info("sparc64 aes opcodes not available.\n");
return -ENODEV;
}
static void __exit aes_sparc64_mod_fini(void)
{
crypto_unregister_algs(algs, ARRAY_SIZE(algs));
}
