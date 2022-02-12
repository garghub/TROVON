static inline void cast5_enc_blk_xway(struct cast5_ctx *ctx, u8 *dst,
const u8 *src)
{
__cast5_enc_blk_16way(ctx, dst, src, false);
}
static inline void cast5_enc_blk_xway_xor(struct cast5_ctx *ctx, u8 *dst,
const u8 *src)
{
__cast5_enc_blk_16way(ctx, dst, src, true);
}
static inline void cast5_dec_blk_xway(struct cast5_ctx *ctx, u8 *dst,
const u8 *src)
{
cast5_dec_blk_16way(ctx, dst, src);
}
static inline bool cast5_fpu_begin(bool fpu_enabled, unsigned int nbytes)
{
return glue_fpu_begin(CAST5_BLOCK_SIZE, CAST5_PARALLEL_BLOCKS,
NULL, fpu_enabled, nbytes);
}
static inline void cast5_fpu_end(bool fpu_enabled)
{
return glue_fpu_end(fpu_enabled);
}
static int ecb_crypt(struct blkcipher_desc *desc, struct blkcipher_walk *walk,
bool enc)
{
bool fpu_enabled = false;
struct cast5_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = CAST5_BLOCK_SIZE;
unsigned int nbytes;
int err;
err = blkcipher_walk_virt(desc, walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
while ((nbytes = walk->nbytes)) {
u8 *wsrc = walk->src.virt.addr;
u8 *wdst = walk->dst.virt.addr;
fpu_enabled = cast5_fpu_begin(fpu_enabled, nbytes);
if (nbytes >= bsize * CAST5_PARALLEL_BLOCKS) {
do {
if (enc)
cast5_enc_blk_xway(ctx, wdst, wsrc);
else
cast5_dec_blk_xway(ctx, wdst, wsrc);
wsrc += bsize * CAST5_PARALLEL_BLOCKS;
wdst += bsize * CAST5_PARALLEL_BLOCKS;
nbytes -= bsize * CAST5_PARALLEL_BLOCKS;
} while (nbytes >= bsize * CAST5_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
do {
if (enc)
__cast5_encrypt(ctx, wdst, wsrc);
else
__cast5_decrypt(ctx, wdst, wsrc);
wsrc += bsize;
wdst += bsize;
nbytes -= bsize;
} while (nbytes >= bsize);
done:
err = blkcipher_walk_done(desc, walk, nbytes);
}
cast5_fpu_end(fpu_enabled);
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
struct cast5_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = CAST5_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u64 *src = (u64 *)walk->src.virt.addr;
u64 *dst = (u64 *)walk->dst.virt.addr;
u64 *iv = (u64 *)walk->iv;
do {
*dst = *src ^ *iv;
__cast5_encrypt(ctx, (u8 *)dst, (u8 *)dst);
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
struct cast5_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = CAST5_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u64 *src = (u64 *)walk->src.virt.addr;
u64 *dst = (u64 *)walk->dst.virt.addr;
u64 ivs[CAST5_PARALLEL_BLOCKS - 1];
u64 last_iv;
int i;
src += nbytes / bsize - 1;
dst += nbytes / bsize - 1;
last_iv = *src;
if (nbytes >= bsize * CAST5_PARALLEL_BLOCKS) {
do {
nbytes -= bsize * (CAST5_PARALLEL_BLOCKS - 1);
src -= CAST5_PARALLEL_BLOCKS - 1;
dst -= CAST5_PARALLEL_BLOCKS - 1;
for (i = 0; i < CAST5_PARALLEL_BLOCKS - 1; i++)
ivs[i] = src[i];
cast5_dec_blk_xway(ctx, (u8 *)dst, (u8 *)src);
for (i = 0; i < CAST5_PARALLEL_BLOCKS - 1; i++)
*(dst + (i + 1)) ^= *(ivs + i);
nbytes -= bsize;
if (nbytes < bsize)
goto done;
*dst ^= *(src - 1);
src -= 1;
dst -= 1;
} while (nbytes >= bsize * CAST5_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
for (;;) {
__cast5_decrypt(ctx, (u8 *)dst, (u8 *)src);
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
fpu_enabled = cast5_fpu_begin(fpu_enabled, nbytes);
nbytes = __cbc_decrypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
cast5_fpu_end(fpu_enabled);
return err;
}
static void ctr_crypt_final(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct cast5_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
u8 *ctrblk = walk->iv;
u8 keystream[CAST5_BLOCK_SIZE];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
__cast5_encrypt(ctx, keystream, ctrblk);
crypto_xor(keystream, src, nbytes);
memcpy(dst, keystream, nbytes);
crypto_inc(ctrblk, CAST5_BLOCK_SIZE);
}
static unsigned int __ctr_crypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct cast5_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = CAST5_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u64 *src = (u64 *)walk->src.virt.addr;
u64 *dst = (u64 *)walk->dst.virt.addr;
u64 ctrblk = be64_to_cpu(*(__be64 *)walk->iv);
__be64 ctrblocks[CAST5_PARALLEL_BLOCKS];
int i;
if (nbytes >= bsize * CAST5_PARALLEL_BLOCKS) {
do {
for (i = 0; i < CAST5_PARALLEL_BLOCKS; i++) {
if (dst != src)
dst[i] = src[i];
ctrblocks[i] = cpu_to_be64(ctrblk++);
}
cast5_enc_blk_xway_xor(ctx, (u8 *)dst,
(u8 *)ctrblocks);
src += CAST5_PARALLEL_BLOCKS;
dst += CAST5_PARALLEL_BLOCKS;
nbytes -= bsize * CAST5_PARALLEL_BLOCKS;
} while (nbytes >= bsize * CAST5_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
do {
if (dst != src)
*dst = *src;
ctrblocks[0] = cpu_to_be64(ctrblk++);
__cast5_encrypt(ctx, (u8 *)ctrblocks, (u8 *)ctrblocks);
*dst ^= ctrblocks[0];
src += 1;
dst += 1;
nbytes -= bsize;
} while (nbytes >= bsize);
done:
*(__be64 *)walk->iv = cpu_to_be64(ctrblk);
return nbytes;
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
bool fpu_enabled = false;
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, CAST5_BLOCK_SIZE);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
while ((nbytes = walk.nbytes) >= CAST5_BLOCK_SIZE) {
fpu_enabled = cast5_fpu_begin(fpu_enabled, nbytes);
nbytes = __ctr_crypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
cast5_fpu_end(fpu_enabled);
if (walk.nbytes) {
ctr_crypt_final(desc, &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static int __init cast5_init(void)
{
u64 xcr0;
if (!cpu_has_avx || !cpu_has_osxsave) {
pr_info("AVX instructions are not detected.\n");
return -ENODEV;
}
xcr0 = xgetbv(XCR_XFEATURE_ENABLED_MASK);
if ((xcr0 & (XSTATE_SSE | XSTATE_YMM)) != (XSTATE_SSE | XSTATE_YMM)) {
pr_info("AVX detected but unusable.\n");
return -ENODEV;
}
return crypto_register_algs(cast5_algs, ARRAY_SIZE(cast5_algs));
}
static void __exit cast5_exit(void)
{
crypto_unregister_algs(cast5_algs, ARRAY_SIZE(cast5_algs));
}
