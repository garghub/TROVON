static inline bool serpent_fpu_begin(bool fpu_enabled, unsigned int nbytes)
{
if (fpu_enabled)
return true;
if (nbytes < SERPENT_BLOCK_SIZE * SERPENT_PARALLEL_BLOCKS)
return false;
kernel_fpu_begin();
return true;
}
static inline void serpent_fpu_end(bool fpu_enabled)
{
if (fpu_enabled)
kernel_fpu_end();
}
static int ecb_crypt(struct blkcipher_desc *desc, struct blkcipher_walk *walk,
bool enc)
{
bool fpu_enabled = false;
struct serpent_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = SERPENT_BLOCK_SIZE;
unsigned int nbytes;
int err;
err = blkcipher_walk_virt(desc, walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
while ((nbytes = walk->nbytes)) {
u8 *wsrc = walk->src.virt.addr;
u8 *wdst = walk->dst.virt.addr;
fpu_enabled = serpent_fpu_begin(fpu_enabled, nbytes);
if (nbytes >= bsize * SERPENT_PARALLEL_BLOCKS) {
do {
if (enc)
serpent_enc_blk_xway(ctx, wdst, wsrc);
else
serpent_dec_blk_xway(ctx, wdst, wsrc);
wsrc += bsize * SERPENT_PARALLEL_BLOCKS;
wdst += bsize * SERPENT_PARALLEL_BLOCKS;
nbytes -= bsize * SERPENT_PARALLEL_BLOCKS;
} while (nbytes >= bsize * SERPENT_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
do {
if (enc)
__serpent_encrypt(ctx, wdst, wsrc);
else
__serpent_decrypt(ctx, wdst, wsrc);
wsrc += bsize;
wdst += bsize;
nbytes -= bsize;
} while (nbytes >= bsize);
done:
err = blkcipher_walk_done(desc, walk, nbytes);
}
serpent_fpu_end(fpu_enabled);
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
struct serpent_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = SERPENT_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 *iv = (u128 *)walk->iv;
do {
u128_xor(dst, src, iv);
__serpent_encrypt(ctx, (u8 *)dst, (u8 *)dst);
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
struct serpent_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = SERPENT_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 ivs[SERPENT_PARALLEL_BLOCKS - 1];
u128 last_iv;
int i;
src += nbytes / bsize - 1;
dst += nbytes / bsize - 1;
last_iv = *src;
if (nbytes >= bsize * SERPENT_PARALLEL_BLOCKS) {
do {
nbytes -= bsize * (SERPENT_PARALLEL_BLOCKS - 1);
src -= SERPENT_PARALLEL_BLOCKS - 1;
dst -= SERPENT_PARALLEL_BLOCKS - 1;
for (i = 0; i < SERPENT_PARALLEL_BLOCKS - 1; i++)
ivs[i] = src[i];
serpent_dec_blk_xway(ctx, (u8 *)dst, (u8 *)src);
for (i = 0; i < SERPENT_PARALLEL_BLOCKS - 1; i++)
u128_xor(dst + (i + 1), dst + (i + 1), ivs + i);
nbytes -= bsize;
if (nbytes < bsize)
goto done;
u128_xor(dst, dst, src - 1);
src -= 1;
dst -= 1;
} while (nbytes >= bsize * SERPENT_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
for (;;) {
__serpent_decrypt(ctx, (u8 *)dst, (u8 *)src);
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
bool fpu_enabled = false;
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
while ((nbytes = walk.nbytes)) {
fpu_enabled = serpent_fpu_begin(fpu_enabled, nbytes);
nbytes = __cbc_decrypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
serpent_fpu_end(fpu_enabled);
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
struct serpent_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
u8 *ctrblk = walk->iv;
u8 keystream[SERPENT_BLOCK_SIZE];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
__serpent_encrypt(ctx, keystream, ctrblk);
crypto_xor(keystream, src, nbytes);
memcpy(dst, keystream, nbytes);
crypto_inc(ctrblk, SERPENT_BLOCK_SIZE);
}
static unsigned int __ctr_crypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct serpent_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = SERPENT_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 ctrblk;
be128 ctrblocks[SERPENT_PARALLEL_BLOCKS];
int i;
be128_to_u128(&ctrblk, (be128 *)walk->iv);
if (nbytes >= bsize * SERPENT_PARALLEL_BLOCKS) {
do {
for (i = 0; i < SERPENT_PARALLEL_BLOCKS; i++) {
if (dst != src)
dst[i] = src[i];
u128_to_be128(&ctrblocks[i], &ctrblk);
u128_inc(&ctrblk);
}
serpent_enc_blk_xway_xor(ctx, (u8 *)dst,
(u8 *)ctrblocks);
src += SERPENT_PARALLEL_BLOCKS;
dst += SERPENT_PARALLEL_BLOCKS;
nbytes -= bsize * SERPENT_PARALLEL_BLOCKS;
} while (nbytes >= bsize * SERPENT_PARALLEL_BLOCKS);
if (nbytes < bsize)
goto done;
}
do {
if (dst != src)
*dst = *src;
u128_to_be128(&ctrblocks[0], &ctrblk);
u128_inc(&ctrblk);
__serpent_encrypt(ctx, (u8 *)ctrblocks, (u8 *)ctrblocks);
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
bool fpu_enabled = false;
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, SERPENT_BLOCK_SIZE);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
while ((nbytes = walk.nbytes) >= SERPENT_BLOCK_SIZE) {
fpu_enabled = serpent_fpu_begin(fpu_enabled, nbytes);
nbytes = __ctr_crypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
serpent_fpu_end(fpu_enabled);
if (walk.nbytes) {
ctr_crypt_final(desc, &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static void encrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = SERPENT_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = serpent_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes == bsize * SERPENT_PARALLEL_BLOCKS) {
serpent_enc_blk_xway(ctx->ctx, srcdst, srcdst);
return;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
__serpent_encrypt(ctx->ctx, srcdst, srcdst);
}
static void decrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = SERPENT_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = serpent_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes == bsize * SERPENT_PARALLEL_BLOCKS) {
serpent_dec_blk_xway(ctx->ctx, srcdst, srcdst);
return;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
__serpent_decrypt(ctx->ctx, srcdst, srcdst);
}
static int lrw_serpent_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct serpent_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
int err;
err = __serpent_setkey(&ctx->serpent_ctx, key, keylen -
SERPENT_BLOCK_SIZE);
if (err)
return err;
return lrw_init_table(&ctx->lrw_table, key + keylen -
SERPENT_BLOCK_SIZE);
}
static int lrw_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct serpent_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[SERPENT_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->serpent_ctx,
.fpu_enabled = false,
};
struct lrw_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.table_ctx = &ctx->lrw_table,
.crypt_ctx = &crypt_ctx,
.crypt_fn = encrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ret = lrw_crypt(desc, dst, src, nbytes, &req);
serpent_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int lrw_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct serpent_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[SERPENT_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->serpent_ctx,
.fpu_enabled = false,
};
struct lrw_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.table_ctx = &ctx->lrw_table,
.crypt_ctx = &crypt_ctx,
.crypt_fn = decrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ret = lrw_crypt(desc, dst, src, nbytes, &req);
serpent_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static void lrw_exit_tfm(struct crypto_tfm *tfm)
{
struct serpent_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
lrw_free_table(&ctx->lrw_table);
}
static int xts_serpent_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct serpent_xts_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
int err;
if (keylen % 2) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
err = __serpent_setkey(&ctx->crypt_ctx, key, keylen / 2);
if (err)
return err;
return __serpent_setkey(&ctx->tweak_ctx, key + keylen / 2, keylen / 2);
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct serpent_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[SERPENT_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->crypt_ctx,
.fpu_enabled = false,
};
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(__serpent_encrypt),
.crypt_ctx = &crypt_ctx,
.crypt_fn = encrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ret = xts_crypt(desc, dst, src, nbytes, &req);
serpent_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct serpent_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[SERPENT_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->crypt_ctx,
.fpu_enabled = false,
};
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(__serpent_encrypt),
.crypt_ctx = &crypt_ctx,
.crypt_fn = decrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ret = xts_crypt(desc, dst, src, nbytes, &req);
serpent_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int ablk_set_key(struct crypto_ablkcipher *tfm, const u8 *key,
unsigned int key_len)
{
struct async_serpent_ctx *ctx = crypto_ablkcipher_ctx(tfm);
struct crypto_ablkcipher *child = &ctx->cryptd_tfm->base;
int err;
crypto_ablkcipher_clear_flags(child, CRYPTO_TFM_REQ_MASK);
crypto_ablkcipher_set_flags(child, crypto_ablkcipher_get_flags(tfm)
& CRYPTO_TFM_REQ_MASK);
err = crypto_ablkcipher_setkey(child, key, key_len);
crypto_ablkcipher_set_flags(tfm, crypto_ablkcipher_get_flags(child)
& CRYPTO_TFM_RES_MASK);
return err;
}
static int __ablk_encrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
struct async_serpent_ctx *ctx = crypto_ablkcipher_ctx(tfm);
struct blkcipher_desc desc;
desc.tfm = cryptd_ablkcipher_child(ctx->cryptd_tfm);
desc.info = req->info;
desc.flags = 0;
return crypto_blkcipher_crt(desc.tfm)->encrypt(
&desc, req->dst, req->src, req->nbytes);
}
static int ablk_encrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
struct async_serpent_ctx *ctx = crypto_ablkcipher_ctx(tfm);
if (!irq_fpu_usable()) {
struct ablkcipher_request *cryptd_req =
ablkcipher_request_ctx(req);
memcpy(cryptd_req, req, sizeof(*req));
ablkcipher_request_set_tfm(cryptd_req, &ctx->cryptd_tfm->base);
return crypto_ablkcipher_encrypt(cryptd_req);
} else {
return __ablk_encrypt(req);
}
}
static int ablk_decrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);
struct async_serpent_ctx *ctx = crypto_ablkcipher_ctx(tfm);
if (!irq_fpu_usable()) {
struct ablkcipher_request *cryptd_req =
ablkcipher_request_ctx(req);
memcpy(cryptd_req, req, sizeof(*req));
ablkcipher_request_set_tfm(cryptd_req, &ctx->cryptd_tfm->base);
return crypto_ablkcipher_decrypt(cryptd_req);
} else {
struct blkcipher_desc desc;
desc.tfm = cryptd_ablkcipher_child(ctx->cryptd_tfm);
desc.info = req->info;
desc.flags = 0;
return crypto_blkcipher_crt(desc.tfm)->decrypt(
&desc, req->dst, req->src, req->nbytes);
}
}
static void ablk_exit(struct crypto_tfm *tfm)
{
struct async_serpent_ctx *ctx = crypto_tfm_ctx(tfm);
cryptd_free_ablkcipher(ctx->cryptd_tfm);
}
static int ablk_init(struct crypto_tfm *tfm)
{
struct async_serpent_ctx *ctx = crypto_tfm_ctx(tfm);
struct cryptd_ablkcipher *cryptd_tfm;
char drv_name[CRYPTO_MAX_ALG_NAME];
snprintf(drv_name, sizeof(drv_name), "__driver-%s",
crypto_tfm_alg_driver_name(tfm));
cryptd_tfm = cryptd_alloc_ablkcipher(drv_name, 0, 0);
if (IS_ERR(cryptd_tfm))
return PTR_ERR(cryptd_tfm);
ctx->cryptd_tfm = cryptd_tfm;
tfm->crt_ablkcipher.reqsize = sizeof(struct ablkcipher_request) +
crypto_ablkcipher_reqsize(&cryptd_tfm->base);
return 0;
}
static int __init serpent_sse2_init(void)
{
if (!cpu_has_xmm2) {
printk(KERN_INFO "SSE2 instructions are not detected.\n");
return -ENODEV;
}
return crypto_register_algs(serpent_algs, ARRAY_SIZE(serpent_algs));
}
static void __exit serpent_sse2_exit(void)
{
crypto_unregister_algs(serpent_algs, ARRAY_SIZE(serpent_algs));
}
