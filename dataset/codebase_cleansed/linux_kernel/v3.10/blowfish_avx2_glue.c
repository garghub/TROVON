static inline bool bf_fpu_begin(bool fpu_enabled, unsigned int nbytes)
{
if (fpu_enabled)
return true;
if (nbytes < BF_BLOCK_SIZE * BF_AVX2_PARALLEL_BLOCKS)
return false;
kernel_fpu_begin();
return true;
}
static inline void bf_fpu_end(bool fpu_enabled)
{
if (fpu_enabled)
kernel_fpu_end();
}
static int ecb_crypt(struct blkcipher_desc *desc, struct blkcipher_walk *walk,
bool enc)
{
bool fpu_enabled = false;
struct bf_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = BF_BLOCK_SIZE;
unsigned int nbytes;
int err;
err = blkcipher_walk_virt(desc, walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
while ((nbytes = walk->nbytes)) {
u8 *wsrc = walk->src.virt.addr;
u8 *wdst = walk->dst.virt.addr;
fpu_enabled = bf_fpu_begin(fpu_enabled, nbytes);
if (nbytes >= bsize * BF_AVX2_PARALLEL_BLOCKS) {
do {
if (enc)
blowfish_ecb_enc_32way(ctx, wdst, wsrc);
else
blowfish_ecb_dec_32way(ctx, wdst, wsrc);
wsrc += bsize * BF_AVX2_PARALLEL_BLOCKS;
wdst += bsize * BF_AVX2_PARALLEL_BLOCKS;
nbytes -= bsize * BF_AVX2_PARALLEL_BLOCKS;
} while (nbytes >= bsize * BF_AVX2_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
if (nbytes >= bsize * BF_PARALLEL_BLOCKS) {
do {
if (enc)
blowfish_enc_blk_4way(ctx, wdst, wsrc);
else
blowfish_dec_blk_4way(ctx, wdst, wsrc);
wsrc += bsize * BF_PARALLEL_BLOCKS;
wdst += bsize * BF_PARALLEL_BLOCKS;
nbytes -= bsize * BF_PARALLEL_BLOCKS;
} while (nbytes >= bsize * BF_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
do {
if (enc)
blowfish_enc_blk(ctx, wdst, wsrc);
else
blowfish_dec_blk(ctx, wdst, wsrc);
wsrc += bsize;
wdst += bsize;
nbytes -= bsize;
} while (nbytes >= bsize);
done:
err = blkcipher_walk_done(desc, walk, nbytes);
}
bf_fpu_end(fpu_enabled);
return err;
}
static int ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_crypt(desc, &walk, true);
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_crypt(desc, &walk, false);
}
static unsigned int __cbc_encrypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct bf_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = BF_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u64 *src = (u64 *)walk->src.virt.addr;
u64 *dst = (u64 *)walk->dst.virt.addr;
u64 *iv = (u64 *)walk->iv;
do {
*dst = *src ^ *iv;
blowfish_enc_blk(ctx, (u8 *)dst, (u8 *)dst);
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
struct bf_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = BF_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u64 *src = (u64 *)walk->src.virt.addr;
u64 *dst = (u64 *)walk->dst.virt.addr;
u64 last_iv;
int i;
src += nbytes / bsize - 1;
dst += nbytes / bsize - 1;
last_iv = *src;
if (nbytes >= bsize * BF_AVX2_PARALLEL_BLOCKS) {
do {
nbytes -= bsize * (BF_AVX2_PARALLEL_BLOCKS - 1);
src -= BF_AVX2_PARALLEL_BLOCKS - 1;
dst -= BF_AVX2_PARALLEL_BLOCKS - 1;
blowfish_cbc_dec_32way(ctx, (u8 *)dst, (u8 *)src);
nbytes -= bsize;
if (nbytes < bsize)
goto done;
*dst ^= *(src - 1);
src -= 1;
dst -= 1;
} while (nbytes >= bsize * BF_AVX2_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
if (nbytes >= bsize * BF_PARALLEL_BLOCKS) {
u64 ivs[BF_PARALLEL_BLOCKS - 1];
do {
nbytes -= bsize * (BF_PARALLEL_BLOCKS - 1);
src -= BF_PARALLEL_BLOCKS - 1;
dst -= BF_PARALLEL_BLOCKS - 1;
for (i = 0; i < BF_PARALLEL_BLOCKS - 1; i++)
ivs[i] = src[i];
blowfish_dec_blk_4way(ctx, (u8 *)dst, (u8 *)src);
for (i = 0; i < BF_PARALLEL_BLOCKS - 1; i++)
dst[i + 1] ^= ivs[i];
nbytes -= bsize;
if (nbytes < bsize)
goto done;
*dst ^= *(src - 1);
src -= 1;
dst -= 1;
} while (nbytes >= bsize * BF_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
for (;;) {
blowfish_dec_blk(ctx, (u8 *)dst, (u8 *)src);
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
bool fpu_enabled = false;
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
while ((nbytes = walk.nbytes)) {
fpu_enabled = bf_fpu_begin(fpu_enabled, nbytes);
nbytes = __cbc_decrypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
bf_fpu_end(fpu_enabled);
return err;
}
static void ctr_crypt_final(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct bf_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
u8 *ctrblk = walk->iv;
u8 keystream[BF_BLOCK_SIZE];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
blowfish_enc_blk(ctx, keystream, ctrblk);
crypto_xor(keystream, src, nbytes);
memcpy(dst, keystream, nbytes);
crypto_inc(ctrblk, BF_BLOCK_SIZE);
}
static unsigned int __ctr_crypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct bf_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = BF_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u64 *src = (u64 *)walk->src.virt.addr;
u64 *dst = (u64 *)walk->dst.virt.addr;
int i;
if (nbytes >= bsize * BF_AVX2_PARALLEL_BLOCKS) {
do {
blowfish_ctr_32way(ctx, (u8 *)dst, (u8 *)src,
(__be64 *)walk->iv);
src += BF_AVX2_PARALLEL_BLOCKS;
dst += BF_AVX2_PARALLEL_BLOCKS;
nbytes -= bsize * BF_AVX2_PARALLEL_BLOCKS;
} while (nbytes >= bsize * BF_AVX2_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
if (nbytes >= bsize * BF_PARALLEL_BLOCKS) {
__be64 ctrblocks[BF_PARALLEL_BLOCKS];
u64 ctrblk = be64_to_cpu(*(__be64 *)walk->iv);
do {
for (i = 0; i < BF_PARALLEL_BLOCKS; i++) {
if (dst != src)
dst[i] = src[i];
ctrblocks[i] = cpu_to_be64(ctrblk++);
}
blowfish_enc_blk_xor_4way(ctx, (u8 *)dst,
(u8 *)ctrblocks);
src += BF_PARALLEL_BLOCKS;
dst += BF_PARALLEL_BLOCKS;
nbytes -= bsize * BF_PARALLEL_BLOCKS;
} while (nbytes >= bsize * BF_PARALLEL_BLOCKS);
*(__be64 *)walk->iv = cpu_to_be64(ctrblk);
if (nbytes < bsize)
goto done;
}
do {
u64 ctrblk;
if (dst != src)
*dst = *src;
ctrblk = *(u64 *)walk->iv;
be64_add_cpu((__be64 *)walk->iv, 1);
blowfish_enc_blk_xor(ctx, (u8 *)dst, (u8 *)&ctrblk);
src += 1;
dst += 1;
} while ((nbytes -= bsize) >= bsize);
done:
return nbytes;
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
bool fpu_enabled = false;
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, BF_BLOCK_SIZE);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
while ((nbytes = walk.nbytes) >= BF_BLOCK_SIZE) {
fpu_enabled = bf_fpu_begin(fpu_enabled, nbytes);
nbytes = __ctr_crypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
bf_fpu_end(fpu_enabled);
if (walk.nbytes) {
ctr_crypt_final(desc, &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static int __init init(void)
{
u64 xcr0;
if (!cpu_has_avx2 || !cpu_has_osxsave) {
pr_info("AVX2 instructions are not detected.\n");
return -ENODEV;
}
xcr0 = xgetbv(XCR_XFEATURE_ENABLED_MASK);
if ((xcr0 & (XSTATE_SSE | XSTATE_YMM)) != (XSTATE_SSE | XSTATE_YMM)) {
pr_info("AVX detected but unusable.\n");
return -ENODEV;
}
return crypto_register_algs(bf_algs, ARRAY_SIZE(bf_algs));
}
static void __exit fini(void)
{
crypto_unregister_algs(bf_algs, ARRAY_SIZE(bf_algs));
}
