static inline void twofish_enc_blk_3way(struct twofish_ctx *ctx, u8 *dst,
const u8 *src)
{
__twofish_enc_blk_3way(ctx, dst, src, false);
}
static inline void twofish_enc_blk_xor_3way(struct twofish_ctx *ctx, u8 *dst,
const u8 *src)
{
__twofish_enc_blk_3way(ctx, dst, src, true);
}
static int ecb_crypt(struct blkcipher_desc *desc, struct blkcipher_walk *walk,
void (*fn)(struct twofish_ctx *, u8 *, const u8 *),
void (*fn_3way)(struct twofish_ctx *, u8 *, const u8 *))
{
struct twofish_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = TF_BLOCK_SIZE;
unsigned int nbytes;
int err;
err = blkcipher_walk_virt(desc, walk);
while ((nbytes = walk->nbytes)) {
u8 *wsrc = walk->src.virt.addr;
u8 *wdst = walk->dst.virt.addr;
if (nbytes >= bsize * 3) {
do {
fn_3way(ctx, wdst, wsrc);
wsrc += bsize * 3;
wdst += bsize * 3;
nbytes -= bsize * 3;
} while (nbytes >= bsize * 3);
if (nbytes < bsize)
goto done;
}
do {
fn(ctx, wdst, wsrc);
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
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_crypt(desc, &walk, twofish_enc_blk, twofish_enc_blk_3way);
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_crypt(desc, &walk, twofish_dec_blk, twofish_dec_blk_3way);
}
static unsigned int __cbc_encrypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct twofish_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = TF_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 *iv = (u128 *)walk->iv;
do {
u128_xor(dst, src, iv);
twofish_enc_blk(ctx, (u8 *)dst, (u8 *)dst);
iv = dst;
src += 1;
dst += 1;
nbytes -= bsize;
} while (nbytes >= bsize);
u128_xor((u128 *)walk->iv, (u128 *)walk->iv, iv);
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
struct twofish_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = TF_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 ivs[3 - 1];
u128 last_iv;
src += nbytes / bsize - 1;
dst += nbytes / bsize - 1;
last_iv = *src;
if (nbytes >= bsize * 3) {
do {
nbytes -= bsize * (3 - 1);
src -= 3 - 1;
dst -= 3 - 1;
ivs[0] = src[0];
ivs[1] = src[1];
twofish_dec_blk_3way(ctx, (u8 *)dst, (u8 *)src);
u128_xor(dst + 1, dst + 1, ivs + 0);
u128_xor(dst + 2, dst + 2, ivs + 1);
nbytes -= bsize;
if (nbytes < bsize)
goto done;
u128_xor(dst, dst, src - 1);
src -= 1;
dst -= 1;
} while (nbytes >= bsize * 3);
if (nbytes < bsize)
goto done;
}
for (;;) {
twofish_dec_blk(ctx, (u8 *)dst, (u8 *)src);
nbytes -= bsize;
if (nbytes < bsize)
break;
u128_xor(dst, dst, src - 1);
src -= 1;
dst -= 1;
}
done:
u128_xor(dst, dst, (u128 *)walk->iv);
*(u128 *)walk->iv = last_iv;
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
static inline void u128_to_be128(be128 *dst, const u128 *src)
{
dst->a = cpu_to_be64(src->a);
dst->b = cpu_to_be64(src->b);
}
static inline void be128_to_u128(u128 *dst, const be128 *src)
{
dst->a = be64_to_cpu(src->a);
dst->b = be64_to_cpu(src->b);
}
static inline void u128_inc(u128 *i)
{
i->b++;
if (!i->b)
i->a++;
}
static void ctr_crypt_final(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct twofish_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
u8 *ctrblk = walk->iv;
u8 keystream[TF_BLOCK_SIZE];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
twofish_enc_blk(ctx, keystream, ctrblk);
crypto_xor(keystream, src, nbytes);
memcpy(dst, keystream, nbytes);
crypto_inc(ctrblk, TF_BLOCK_SIZE);
}
static unsigned int __ctr_crypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct twofish_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = TF_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 ctrblk;
be128 ctrblocks[3];
be128_to_u128(&ctrblk, (be128 *)walk->iv);
if (nbytes >= bsize * 3) {
do {
if (dst != src) {
dst[0] = src[0];
dst[1] = src[1];
dst[2] = src[2];
}
u128_to_be128(&ctrblocks[0], &ctrblk);
u128_inc(&ctrblk);
u128_to_be128(&ctrblocks[1], &ctrblk);
u128_inc(&ctrblk);
u128_to_be128(&ctrblocks[2], &ctrblk);
u128_inc(&ctrblk);
twofish_enc_blk_xor_3way(ctx, (u8 *)dst,
(u8 *)ctrblocks);
src += 3;
dst += 3;
nbytes -= bsize * 3;
} while (nbytes >= bsize * 3);
if (nbytes < bsize)
goto done;
}
do {
if (dst != src)
*dst = *src;
u128_to_be128(&ctrblocks[0], &ctrblk);
u128_inc(&ctrblk);
twofish_enc_blk(ctx, (u8 *)ctrblocks, (u8 *)ctrblocks);
u128_xor(dst, dst, (u128 *)ctrblocks);
src += 1;
dst += 1;
nbytes -= bsize;
} while (nbytes >= bsize);
done:
u128_to_be128((be128 *)walk->iv, &ctrblk);
return nbytes;
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, TF_BLOCK_SIZE);
while ((nbytes = walk.nbytes) >= TF_BLOCK_SIZE) {
nbytes = __ctr_crypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
if (walk.nbytes) {
ctr_crypt_final(desc, &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static void encrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = TF_BLOCK_SIZE;
struct twofish_ctx *ctx = priv;
int i;
if (nbytes == 3 * bsize) {
twofish_enc_blk_3way(ctx, srcdst, srcdst);
return;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
twofish_enc_blk(ctx, srcdst, srcdst);
}
static void decrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = TF_BLOCK_SIZE;
struct twofish_ctx *ctx = priv;
int i;
if (nbytes == 3 * bsize) {
twofish_dec_blk_3way(ctx, srcdst, srcdst);
return;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
twofish_dec_blk(ctx, srcdst, srcdst);
}
static int lrw_twofish_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct twofish_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
int err;
err = __twofish_setkey(&ctx->twofish_ctx, key, keylen - TF_BLOCK_SIZE,
&tfm->crt_flags);
if (err)
return err;
return lrw_init_table(&ctx->lrw_table, key + keylen - TF_BLOCK_SIZE);
}
static int lrw_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct twofish_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[3];
struct lrw_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.table_ctx = &ctx->lrw_table,
.crypt_ctx = &ctx->twofish_ctx,
.crypt_fn = encrypt_callback,
};
return lrw_crypt(desc, dst, src, nbytes, &req);
}
static int lrw_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct twofish_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[3];
struct lrw_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.table_ctx = &ctx->lrw_table,
.crypt_ctx = &ctx->twofish_ctx,
.crypt_fn = decrypt_callback,
};
return lrw_crypt(desc, dst, src, nbytes, &req);
}
static void lrw_exit_tfm(struct crypto_tfm *tfm)
{
struct twofish_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
lrw_free_table(&ctx->lrw_table);
}
static int xts_twofish_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct twofish_xts_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
int err;
if (keylen % 2) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
err = __twofish_setkey(&ctx->crypt_ctx, key, keylen / 2, flags);
if (err)
return err;
return __twofish_setkey(&ctx->tweak_ctx, key + keylen / 2, keylen / 2,
flags);
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct twofish_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[3];
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(twofish_enc_blk),
.crypt_ctx = &ctx->crypt_ctx,
.crypt_fn = encrypt_callback,
};
return xts_crypt(desc, dst, src, nbytes, &req);
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct twofish_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[3];
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(twofish_enc_blk),
.crypt_ctx = &ctx->crypt_ctx,
.crypt_fn = decrypt_callback,
};
return xts_crypt(desc, dst, src, nbytes, &req);
}
static bool is_blacklisted_cpu(void)
{
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return false;
if (boot_cpu_data.x86 == 0x06 &&
(boot_cpu_data.x86_model == 0x1c ||
boot_cpu_data.x86_model == 0x26 ||
boot_cpu_data.x86_model == 0x36)) {
return true;
}
if (boot_cpu_data.x86 == 0x0f) {
return true;
}
return false;
}
static int __init init(void)
{
if (!force && is_blacklisted_cpu()) {
printk(KERN_INFO
"twofish-x86_64-3way: performance on this CPU "
"would be suboptimal: disabling "
"twofish-x86_64-3way.\n");
return -ENODEV;
}
return crypto_register_algs(tf_algs, ARRAY_SIZE(tf_algs));
}
static void __exit fini(void)
{
crypto_unregister_algs(tf_algs, ARRAY_SIZE(tf_algs));
}
