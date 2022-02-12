static int aesbs_cbc_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_cbc_ctx *ctx = crypto_tfm_ctx(tfm);
int bits = key_len * 8;
if (private_AES_set_encrypt_key(in_key, bits, &ctx->enc)) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
ctx->dec.rk = ctx->enc;
private_AES_set_decrypt_key(in_key, bits, &ctx->dec.rk);
ctx->dec.converted = 0;
return 0;
}
static int aesbs_ctr_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_ctr_ctx *ctx = crypto_tfm_ctx(tfm);
int bits = key_len * 8;
if (private_AES_set_encrypt_key(in_key, bits, &ctx->enc.rk)) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
ctx->enc.converted = 0;
return 0;
}
static int aesbs_xts_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct aesbs_xts_ctx *ctx = crypto_tfm_ctx(tfm);
int bits = key_len * 4;
if (private_AES_set_encrypt_key(in_key, bits, &ctx->enc.rk)) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
ctx->dec.rk = ctx->enc.rk;
private_AES_set_decrypt_key(in_key, bits, &ctx->dec.rk);
private_AES_set_encrypt_key(in_key + key_len / 2, bits, &ctx->twkey);
ctx->enc.converted = ctx->dec.converted = 0;
return 0;
}
static int aesbs_cbc_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesbs_cbc_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while (walk.nbytes) {
u32 blocks = walk.nbytes / AES_BLOCK_SIZE;
u8 *src = walk.src.virt.addr;
if (walk.dst.virt.addr == walk.src.virt.addr) {
u8 *iv = walk.iv;
do {
crypto_xor(src, iv, AES_BLOCK_SIZE);
AES_encrypt(src, src, &ctx->enc);
iv = src;
src += AES_BLOCK_SIZE;
} while (--blocks);
memcpy(walk.iv, iv, AES_BLOCK_SIZE);
} else {
u8 *dst = walk.dst.virt.addr;
do {
crypto_xor(walk.iv, src, AES_BLOCK_SIZE);
AES_encrypt(walk.iv, dst, &ctx->enc);
memcpy(walk.iv, dst, AES_BLOCK_SIZE);
src += AES_BLOCK_SIZE;
dst += AES_BLOCK_SIZE;
} while (--blocks);
}
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
return err;
}
static int aesbs_cbc_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesbs_cbc_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, 8 * AES_BLOCK_SIZE);
while ((walk.nbytes / AES_BLOCK_SIZE) >= 8) {
kernel_neon_begin();
bsaes_cbc_encrypt(walk.src.virt.addr, walk.dst.virt.addr,
walk.nbytes, &ctx->dec, walk.iv);
kernel_neon_end();
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
while (walk.nbytes) {
u32 blocks = walk.nbytes / AES_BLOCK_SIZE;
u8 *dst = walk.dst.virt.addr;
u8 *src = walk.src.virt.addr;
u8 bk[2][AES_BLOCK_SIZE];
u8 *iv = walk.iv;
do {
if (walk.dst.virt.addr == walk.src.virt.addr)
memcpy(bk[blocks & 1], src, AES_BLOCK_SIZE);
AES_decrypt(src, dst, &ctx->dec.rk);
crypto_xor(dst, iv, AES_BLOCK_SIZE);
if (walk.dst.virt.addr == walk.src.virt.addr)
iv = bk[blocks & 1];
else
iv = src;
dst += AES_BLOCK_SIZE;
src += AES_BLOCK_SIZE;
} while (--blocks);
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
return err;
}
static void inc_be128_ctr(__be32 ctr[], u32 addend)
{
int i;
for (i = 3; i >= 0; i--, addend = 1) {
u32 n = be32_to_cpu(ctr[i]) + addend;
ctr[i] = cpu_to_be32(n);
if (n >= addend)
break;
}
}
static int aesbs_ctr_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct aesbs_ctr_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
u32 blocks;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, 8 * AES_BLOCK_SIZE);
while ((blocks = walk.nbytes / AES_BLOCK_SIZE)) {
u32 tail = walk.nbytes % AES_BLOCK_SIZE;
__be32 *ctr = (__be32 *)walk.iv;
u32 headroom = UINT_MAX - be32_to_cpu(ctr[3]);
if (unlikely(headroom < blocks)) {
blocks = headroom + 1;
tail = walk.nbytes - blocks * AES_BLOCK_SIZE;
}
kernel_neon_begin();
bsaes_ctr32_encrypt_blocks(walk.src.virt.addr,
walk.dst.virt.addr, blocks,
&ctx->enc, walk.iv);
kernel_neon_end();
inc_be128_ctr(ctr, blocks);
nbytes -= blocks * AES_BLOCK_SIZE;
if (nbytes && nbytes == tail && nbytes <= AES_BLOCK_SIZE)
break;
err = blkcipher_walk_done(desc, &walk, tail);
}
if (walk.nbytes) {
u8 *tdst = walk.dst.virt.addr + blocks * AES_BLOCK_SIZE;
u8 *tsrc = walk.src.virt.addr + blocks * AES_BLOCK_SIZE;
u8 ks[AES_BLOCK_SIZE];
AES_encrypt(walk.iv, ks, &ctx->enc.rk);
if (tdst != tsrc)
memcpy(tdst, tsrc, nbytes);
crypto_xor(tdst, ks, nbytes);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static int aesbs_xts_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesbs_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, 8 * AES_BLOCK_SIZE);
AES_encrypt(walk.iv, walk.iv, &ctx->twkey);
while (walk.nbytes) {
kernel_neon_begin();
bsaes_xts_encrypt(walk.src.virt.addr, walk.dst.virt.addr,
walk.nbytes, &ctx->enc, walk.iv);
kernel_neon_end();
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
return err;
}
static int aesbs_xts_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesbs_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, 8 * AES_BLOCK_SIZE);
AES_encrypt(walk.iv, walk.iv, &ctx->twkey);
while (walk.nbytes) {
kernel_neon_begin();
bsaes_xts_decrypt(walk.src.virt.addr, walk.dst.virt.addr,
walk.nbytes, &ctx->dec, walk.iv);
kernel_neon_end();
err = blkcipher_walk_done(desc, &walk, walk.nbytes % AES_BLOCK_SIZE);
}
return err;
}
static int __init aesbs_mod_init(void)
{
if (!cpu_has_neon())
return -ENODEV;
return crypto_register_algs(aesbs_algs, ARRAY_SIZE(aesbs_algs));
}
static void __exit aesbs_mod_exit(void)
{
crypto_unregister_algs(aesbs_algs, ARRAY_SIZE(aesbs_algs));
}
