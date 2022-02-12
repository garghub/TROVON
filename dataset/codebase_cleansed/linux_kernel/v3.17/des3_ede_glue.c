static inline void des3_ede_enc_blk(struct des3_ede_x86_ctx *ctx, u8 *dst,
const u8 *src)
{
u32 *enc_ctx = ctx->enc_expkey;
des3_ede_x86_64_crypt_blk(enc_ctx, dst, src);
}
static inline void des3_ede_dec_blk(struct des3_ede_x86_ctx *ctx, u8 *dst,
const u8 *src)
{
u32 *dec_ctx = ctx->dec_expkey;
des3_ede_x86_64_crypt_blk(dec_ctx, dst, src);
}
static inline void des3_ede_enc_blk_3way(struct des3_ede_x86_ctx *ctx, u8 *dst,
const u8 *src)
{
u32 *enc_ctx = ctx->enc_expkey;
des3_ede_x86_64_crypt_blk_3way(enc_ctx, dst, src);
}
static inline void des3_ede_dec_blk_3way(struct des3_ede_x86_ctx *ctx, u8 *dst,
const u8 *src)
{
u32 *dec_ctx = ctx->dec_expkey;
des3_ede_x86_64_crypt_blk_3way(dec_ctx, dst, src);
}
static void des3_ede_x86_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
des3_ede_enc_blk(crypto_tfm_ctx(tfm), dst, src);
}
static void des3_ede_x86_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
des3_ede_dec_blk(crypto_tfm_ctx(tfm), dst, src);
}
static int ecb_crypt(struct blkcipher_desc *desc, struct blkcipher_walk *walk,
const u32 *expkey)
{
unsigned int bsize = DES3_EDE_BLOCK_SIZE;
unsigned int nbytes;
int err;
err = blkcipher_walk_virt(desc, walk);
while ((nbytes = walk->nbytes)) {
u8 *wsrc = walk->src.virt.addr;
u8 *wdst = walk->dst.virt.addr;
if (nbytes >= bsize * 3) {
do {
des3_ede_x86_64_crypt_blk_3way(expkey, wdst,
wsrc);
wsrc += bsize * 3;
wdst += bsize * 3;
nbytes -= bsize * 3;
} while (nbytes >= bsize * 3);
if (nbytes < bsize)
goto done;
}
do {
des3_ede_x86_64_crypt_blk(expkey, wdst, wsrc);
wsrc += bsize;
wdst += bsize;
nbytes -= bsize;
} while (nbytes >= bsize);
done:
err = blkcipher_walk_done(desc, walk, nbytes);
}
return err;
}
static int ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct des3_ede_x86_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_crypt(desc, &walk, ctx->enc_expkey);
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct des3_ede_x86_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_crypt(desc, &walk, ctx->dec_expkey);
}
static unsigned int __cbc_encrypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct des3_ede_x86_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = DES3_EDE_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u64 *src = (u64 *)walk->src.virt.addr;
u64 *dst = (u64 *)walk->dst.virt.addr;
u64 *iv = (u64 *)walk->iv;
do {
*dst = *src ^ *iv;
des3_ede_enc_blk(ctx, (u8 *)dst, (u8 *)dst);
iv = dst;
src += 1;
dst += 1;
nbytes -= bsize;
} while (nbytes >= bsize);
*(u64 *)walk->iv = *iv;
return nbytes;
}
static int cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
nbytes = __cbc_encrypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
return err;
}
static unsigned int __cbc_decrypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct des3_ede_x86_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = DES3_EDE_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u64 *src = (u64 *)walk->src.virt.addr;
u64 *dst = (u64 *)walk->dst.virt.addr;
u64 ivs[3 - 1];
u64 last_iv;
src += nbytes / bsize - 1;
dst += nbytes / bsize - 1;
last_iv = *src;
if (nbytes >= bsize * 3) {
do {
nbytes -= bsize * 3 - bsize;
src -= 3 - 1;
dst -= 3 - 1;
ivs[0] = src[0];
ivs[1] = src[1];
des3_ede_dec_blk_3way(ctx, (u8 *)dst, (u8 *)src);
dst[1] ^= ivs[0];
dst[2] ^= ivs[1];
nbytes -= bsize;
if (nbytes < bsize)
goto done;
*dst ^= *(src - 1);
src -= 1;
dst -= 1;
} while (nbytes >= bsize * 3);
}
for (;;) {
des3_ede_dec_blk(ctx, (u8 *)dst, (u8 *)src);
nbytes -= bsize;
if (nbytes < bsize)
break;
*dst ^= *(src - 1);
src -= 1;
dst -= 1;
}
done:
*dst ^= *(u64 *)walk->iv;
*(u64 *)walk->iv = last_iv;
return nbytes;
}
static int cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
nbytes = __cbc_decrypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
return err;
}
static void ctr_crypt_final(struct des3_ede_x86_ctx *ctx,
struct blkcipher_walk *walk)
{
u8 *ctrblk = walk->iv;
u8 keystream[DES3_EDE_BLOCK_SIZE];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
des3_ede_enc_blk(ctx, keystream, ctrblk);
crypto_xor(keystream, src, nbytes);
memcpy(dst, keystream, nbytes);
crypto_inc(ctrblk, DES3_EDE_BLOCK_SIZE);
}
static unsigned int __ctr_crypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct des3_ede_x86_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = DES3_EDE_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
__be64 *src = (__be64 *)walk->src.virt.addr;
__be64 *dst = (__be64 *)walk->dst.virt.addr;
u64 ctrblk = be64_to_cpu(*(__be64 *)walk->iv);
__be64 ctrblocks[3];
if (nbytes >= bsize * 3) {
do {
ctrblocks[0] = cpu_to_be64(ctrblk++);
ctrblocks[1] = cpu_to_be64(ctrblk++);
ctrblocks[2] = cpu_to_be64(ctrblk++);
des3_ede_enc_blk_3way(ctx, (u8 *)ctrblocks,
(u8 *)ctrblocks);
dst[0] = src[0] ^ ctrblocks[0];
dst[1] = src[1] ^ ctrblocks[1];
dst[2] = src[2] ^ ctrblocks[2];
src += 3;
dst += 3;
} while ((nbytes -= bsize * 3) >= bsize * 3);
if (nbytes < bsize)
goto done;
}
do {
ctrblocks[0] = cpu_to_be64(ctrblk++);
des3_ede_enc_blk(ctx, (u8 *)ctrblocks, (u8 *)ctrblocks);
dst[0] = src[0] ^ ctrblocks[0];
src += 1;
dst += 1;
} while ((nbytes -= bsize) >= bsize);
done:
*(__be64 *)walk->iv = cpu_to_be64(ctrblk);
return nbytes;
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, DES3_EDE_BLOCK_SIZE);
while ((nbytes = walk.nbytes) >= DES3_EDE_BLOCK_SIZE) {
nbytes = __ctr_crypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
if (walk.nbytes) {
ctr_crypt_final(crypto_blkcipher_ctx(desc->tfm), &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static int des3_ede_x86_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct des3_ede_x86_ctx *ctx = crypto_tfm_ctx(tfm);
u32 i, j, tmp;
int err;
err = __des3_ede_setkey(ctx->enc_expkey, &tfm->crt_flags, key, keylen);
if (err < 0)
return err;
j = DES3_EDE_EXPKEY_WORDS - 2;
for (i = 0; i < DES3_EDE_EXPKEY_WORDS; i += 2, j -= 2) {
tmp = ror32(ctx->enc_expkey[i + 1], 4);
ctx->enc_expkey[i + 1] = tmp;
ctx->dec_expkey[j + 0] = ctx->enc_expkey[i + 0];
ctx->dec_expkey[j + 1] = tmp;
}
return 0;
}
static bool is_blacklisted_cpu(void)
{
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return false;
if (boot_cpu_data.x86 == 0x0f) {
return true;
}
return false;
}
static int __init des3_ede_x86_init(void)
{
if (!force && is_blacklisted_cpu()) {
pr_info("des3_ede-x86_64: performance on this CPU would be suboptimal: disabling des3_ede-x86_64.\n");
return -ENODEV;
}
return crypto_register_algs(des3_ede_algs, ARRAY_SIZE(des3_ede_algs));
}
static void __exit des3_ede_x86_fini(void)
{
crypto_unregister_algs(des3_ede_algs, ARRAY_SIZE(des3_ede_algs));
}
