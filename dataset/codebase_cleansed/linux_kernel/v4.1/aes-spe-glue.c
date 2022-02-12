static void spe_begin(void)
{
preempt_disable();
enable_kernel_spe();
}
static void spe_end(void)
{
preempt_enable();
}
static int ppc_aes_setkey(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct ppc_aes_ctx *ctx = crypto_tfm_ctx(tfm);
if (key_len != AES_KEYSIZE_128 &&
key_len != AES_KEYSIZE_192 &&
key_len != AES_KEYSIZE_256) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
switch (key_len) {
case AES_KEYSIZE_128:
ctx->rounds = 4;
ppc_expand_key_128(ctx->key_enc, in_key);
break;
case AES_KEYSIZE_192:
ctx->rounds = 5;
ppc_expand_key_192(ctx->key_enc, in_key);
break;
case AES_KEYSIZE_256:
ctx->rounds = 6;
ppc_expand_key_256(ctx->key_enc, in_key);
break;
}
ppc_generate_decrypt_key(ctx->key_dec, ctx->key_enc, key_len);
return 0;
}
static int ppc_xts_setkey(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct ppc_xts_ctx *ctx = crypto_tfm_ctx(tfm);
key_len >>= 1;
if (key_len != AES_KEYSIZE_128 &&
key_len != AES_KEYSIZE_192 &&
key_len != AES_KEYSIZE_256) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
switch (key_len) {
case AES_KEYSIZE_128:
ctx->rounds = 4;
ppc_expand_key_128(ctx->key_enc, in_key);
ppc_expand_key_128(ctx->key_twk, in_key + AES_KEYSIZE_128);
break;
case AES_KEYSIZE_192:
ctx->rounds = 5;
ppc_expand_key_192(ctx->key_enc, in_key);
ppc_expand_key_192(ctx->key_twk, in_key + AES_KEYSIZE_192);
break;
case AES_KEYSIZE_256:
ctx->rounds = 6;
ppc_expand_key_256(ctx->key_enc, in_key);
ppc_expand_key_256(ctx->key_twk, in_key + AES_KEYSIZE_256);
break;
}
ppc_generate_decrypt_key(ctx->key_dec, ctx->key_enc, key_len);
return 0;
}
static void ppc_aes_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct ppc_aes_ctx *ctx = crypto_tfm_ctx(tfm);
spe_begin();
ppc_encrypt_aes(out, in, ctx->key_enc, ctx->rounds);
spe_end();
}
static void ppc_aes_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct ppc_aes_ctx *ctx = crypto_tfm_ctx(tfm);
spe_begin();
ppc_decrypt_aes(out, in, ctx->key_dec, ctx->rounds);
spe_end();
}
static int ppc_ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int ubytes;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
ubytes = nbytes > MAX_BYTES ?
nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
nbytes -= ubytes;
spe_begin();
ppc_encrypt_ecb(walk.dst.virt.addr, walk.src.virt.addr,
ctx->key_enc, ctx->rounds, nbytes);
spe_end();
err = blkcipher_walk_done(desc, &walk, ubytes);
}
return err;
}
static int ppc_ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int ubytes;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
ubytes = nbytes > MAX_BYTES ?
nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
nbytes -= ubytes;
spe_begin();
ppc_decrypt_ecb(walk.dst.virt.addr, walk.src.virt.addr,
ctx->key_dec, ctx->rounds, nbytes);
spe_end();
err = blkcipher_walk_done(desc, &walk, ubytes);
}
return err;
}
static int ppc_cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int ubytes;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
ubytes = nbytes > MAX_BYTES ?
nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
nbytes -= ubytes;
spe_begin();
ppc_encrypt_cbc(walk.dst.virt.addr, walk.src.virt.addr,
ctx->key_enc, ctx->rounds, nbytes, walk.iv);
spe_end();
err = blkcipher_walk_done(desc, &walk, ubytes);
}
return err;
}
static int ppc_cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int ubytes;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
ubytes = nbytes > MAX_BYTES ?
nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
nbytes -= ubytes;
spe_begin();
ppc_decrypt_cbc(walk.dst.virt.addr, walk.src.virt.addr,
ctx->key_dec, ctx->rounds, nbytes, walk.iv);
spe_end();
err = blkcipher_walk_done(desc, &walk, ubytes);
}
return err;
}
static int ppc_ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct ppc_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int pbytes, ubytes;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, AES_BLOCK_SIZE);
while ((pbytes = walk.nbytes)) {
pbytes = pbytes > MAX_BYTES ? MAX_BYTES : pbytes;
pbytes = pbytes == nbytes ?
nbytes : pbytes & ~(AES_BLOCK_SIZE - 1);
ubytes = walk.nbytes - pbytes;
spe_begin();
ppc_crypt_ctr(walk.dst.virt.addr, walk.src.virt.addr,
ctx->key_enc, ctx->rounds, pbytes , walk.iv);
spe_end();
nbytes -= pbytes;
err = blkcipher_walk_done(desc, &walk, ubytes);
}
return err;
}
static int ppc_xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct ppc_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int ubytes;
int err;
u32 *twk;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
twk = ctx->key_twk;
while ((nbytes = walk.nbytes)) {
ubytes = nbytes > MAX_BYTES ?
nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
nbytes -= ubytes;
spe_begin();
ppc_encrypt_xts(walk.dst.virt.addr, walk.src.virt.addr,
ctx->key_enc, ctx->rounds, nbytes, walk.iv, twk);
spe_end();
twk = NULL;
err = blkcipher_walk_done(desc, &walk, ubytes);
}
return err;
}
static int ppc_xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct ppc_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int ubytes;
int err;
u32 *twk;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
twk = ctx->key_twk;
while ((nbytes = walk.nbytes)) {
ubytes = nbytes > MAX_BYTES ?
nbytes - MAX_BYTES : nbytes & (AES_BLOCK_SIZE - 1);
nbytes -= ubytes;
spe_begin();
ppc_decrypt_xts(walk.dst.virt.addr, walk.src.virt.addr,
ctx->key_dec, ctx->rounds, nbytes, walk.iv, twk);
spe_end();
twk = NULL;
err = blkcipher_walk_done(desc, &walk, ubytes);
}
return err;
}
static int __init ppc_aes_mod_init(void)
{
return crypto_register_algs(aes_algs, ARRAY_SIZE(aes_algs));
}
static void __exit ppc_aes_mod_fini(void)
{
crypto_unregister_algs(aes_algs, ARRAY_SIZE(aes_algs));
}
