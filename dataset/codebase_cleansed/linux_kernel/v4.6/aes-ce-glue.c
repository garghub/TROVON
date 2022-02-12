static int num_rounds(struct crypto_aes_ctx *ctx)
{
return 6 + ctx->key_length / 4;
}
static int ce_aes_expandkey(struct crypto_aes_ctx *ctx, const u8 *in_key,
unsigned int key_len)
{
static u8 const rcon[] = {
0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36,
};
u32 kwords = key_len / sizeof(u32);
struct aes_block *key_enc, *key_dec;
int i, j;
if (key_len != AES_KEYSIZE_128 &&
key_len != AES_KEYSIZE_192 &&
key_len != AES_KEYSIZE_256)
return -EINVAL;
memcpy(ctx->key_enc, in_key, key_len);
ctx->key_length = key_len;
kernel_neon_begin();
for (i = 0; i < sizeof(rcon); i++) {
u32 *rki = ctx->key_enc + (i * kwords);
u32 *rko = rki + kwords;
rko[0] = ror32(ce_aes_sub(rki[kwords - 1]), 8);
rko[0] = rko[0] ^ rki[0] ^ rcon[i];
rko[1] = rko[0] ^ rki[1];
rko[2] = rko[1] ^ rki[2];
rko[3] = rko[2] ^ rki[3];
if (key_len == AES_KEYSIZE_192) {
if (i >= 7)
break;
rko[4] = rko[3] ^ rki[4];
rko[5] = rko[4] ^ rki[5];
} else if (key_len == AES_KEYSIZE_256) {
if (i >= 6)
break;
rko[4] = ce_aes_sub(rko[3]) ^ rki[4];
rko[5] = rko[4] ^ rki[5];
rko[6] = rko[5] ^ rki[6];
rko[7] = rko[6] ^ rki[7];
}
}
key_enc = (struct aes_block *)ctx->key_enc;
key_dec = (struct aes_block *)ctx->key_dec;
j = num_rounds(ctx);
key_dec[0] = key_enc[j];
for (i = 1, j--; j > 0; i++, j--)
ce_aes_invert(key_dec + i, key_enc + j);
key_dec[i] = key_enc[0];
kernel_neon_end();
return 0;
}
static int ce_aes_setkey(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_ctx *ctx = crypto_tfm_ctx(tfm);
int ret;
ret = ce_aes_expandkey(ctx, in_key, key_len);
if (!ret)
return 0;
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
static int xts_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_xts_ctx *ctx = crypto_tfm_ctx(tfm);
int ret;
ret = xts_check_key(tfm, in_key, key_len);
if (ret)
return ret;
ret = ce_aes_expandkey(&ctx->key1, in_key, key_len / 2);
if (!ret)
ret = ce_aes_expandkey(&ctx->key2, &in_key[key_len / 2],
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
struct blkcipher_walk walk;
unsigned int blocks;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_ecb_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, num_rounds(ctx), blocks);
err = blkcipher_walk_done(desc, &walk,
walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int blocks;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_ecb_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_dec, num_rounds(ctx), blocks);
err = blkcipher_walk_done(desc, &walk,
walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int blocks;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_cbc_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, num_rounds(ctx), blocks,
walk.iv);
err = blkcipher_walk_done(desc, &walk,
walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
unsigned int blocks;
int err;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_cbc_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_dec, num_rounds(ctx), blocks,
walk.iv);
err = blkcipher_walk_done(desc, &walk,
walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ctr_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err, blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, AES_BLOCK_SIZE);
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
ce_aes_ctr_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, num_rounds(ctx), blocks,
walk.iv);
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
ce_aes_ctr_encrypt(tail, tsrc, (u8 *)ctx->key_enc,
num_rounds(ctx), blocks, walk.iv);
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
int err, first, rounds = num_rounds(&ctx->key1);
struct blkcipher_walk walk;
unsigned int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
ce_aes_xts_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key1.key_enc, rounds, blocks,
walk.iv, (u8 *)ctx->key2.key_enc, first);
err = blkcipher_walk_done(desc, &walk,
walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct crypto_aes_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int err, first, rounds = num_rounds(&ctx->key1);
struct blkcipher_walk walk;
unsigned int blocks;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
ce_aes_xts_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key1.key_dec, rounds, blocks,
walk.iv, (u8 *)ctx->key2.key_enc, first);
err = blkcipher_walk_done(desc, &walk,
walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int __init aes_init(void)
{
if (!(elf_hwcap2 & HWCAP2_AES))
return -ENODEV;
return crypto_register_algs(aes_algs, ARRAY_SIZE(aes_algs));
}
static void __exit aes_exit(void)
{
crypto_unregister_algs(aes_algs, ARRAY_SIZE(aes_algs));
}
