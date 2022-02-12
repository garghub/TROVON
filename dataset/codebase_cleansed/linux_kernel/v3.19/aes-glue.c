static int xts_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_xts_ctx *ctx = crypto_tfm_ctx(tfm);
int ret;
ret = aes_expandkey(&ctx->key1, in_key, key_len / 2);
if (!ret)
ret = aes_expandkey(&ctx->key2, &in_key[key_len / 2],
key_len / 2);
if (!ret)
return 0;
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
static int ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct blkcipher_walk walk;
unsigned int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_ecb_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, rounds, blocks, first);
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct blkcipher_walk walk;
unsigned int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_ecb_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_dec, rounds, blocks, first);
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct blkcipher_walk walk;
unsigned int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_cbc_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, rounds, blocks, walk.iv,
first);
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct blkcipher_walk walk;
unsigned int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_cbc_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_dec, rounds, blocks, walk.iv,
first);
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ctr_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct blkcipher_walk walk;
int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, AES_BLOCK_SIZE);
first = 1;
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
aes_ctr_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, rounds, blocks, walk.iv,
first);
first = 0;
nbytes -= blocks * AES_BLOCK_SIZE;
if (nbytes && nbytes == walk.nbytes % AES_BLOCK_SIZE)
break;
err = blkcipher_walk_done(desc, &walk,
walk.nbytes % AES_BLOCK_SIZE);
}
if (nbytes) {
u8 *tdst = walk.dst.virt.addr + blocks * AES_BLOCK_SIZE;
u8 *tsrc = walk.src.virt.addr + blocks * AES_BLOCK_SIZE;
u8 __aligned(8) tail[AES_BLOCK_SIZE];
blocks = (nbytes <= 8) ? -1 : 1;
aes_ctr_encrypt(tail, tsrc, (u8 *)ctx->key_enc, rounds,
blocks, walk.iv, first);
memcpy(tdst, tail, nbytes);
err = blkcipher_walk_done(desc, &walk, 0);
}
kernel_neon_end();
return err;
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int err, first, rounds = 6 + ctx->key1.key_length / 4;
struct blkcipher_walk walk;
unsigned int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_xts_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key1.key_enc, rounds, blocks,
(u8 *)ctx->key2.key_enc, walk.iv, first);
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int err, first, rounds = 6 + ctx->key1.key_length / 4;
struct blkcipher_walk walk;
unsigned int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_xts_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key1.key_dec, rounds, blocks,
(u8 *)ctx->key2.key_enc, walk.iv, first);
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int __init aes_init(void)
{
return crypto_register_algs(aes_algs, ARRAY_SIZE(aes_algs));
}
static void __exit aes_exit(void)
{
crypto_unregister_algs(aes_algs, ARRAY_SIZE(aes_algs));
}
