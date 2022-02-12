static void cast6_crypt_ctr(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
be128 ctrblk;
le128_to_be128(&ctrblk, iv);
le128_inc(iv);
__cast6_encrypt(ctx, (u8 *)&ctrblk, (u8 *)&ctrblk);
u128_xor(dst, src, (u128 *)&ctrblk);
}
static int ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ecb_crypt_128bit(&cast6_enc, desc, dst, src, nbytes);
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ecb_crypt_128bit(&cast6_dec, desc, dst, src, nbytes);
}
static int cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_cbc_encrypt_128bit(GLUE_FUNC_CAST(__cast6_encrypt), desc,
dst, src, nbytes);
}
static int cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_cbc_decrypt_128bit(&cast6_dec_cbc, desc, dst, src,
nbytes);
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ctr_crypt_128bit(&cast6_ctr, desc, dst, src, nbytes);
}
static inline bool cast6_fpu_begin(bool fpu_enabled, unsigned int nbytes)
{
return glue_fpu_begin(CAST6_BLOCK_SIZE, CAST6_PARALLEL_BLOCKS,
NULL, fpu_enabled, nbytes);
}
static inline void cast6_fpu_end(bool fpu_enabled)
{
glue_fpu_end(fpu_enabled);
}
static void encrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = CAST6_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = cast6_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes == bsize * CAST6_PARALLEL_BLOCKS) {
cast6_ecb_enc_8way(ctx->ctx, srcdst, srcdst);
return;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
__cast6_encrypt(ctx->ctx, srcdst, srcdst);
}
static void decrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = CAST6_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = cast6_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes == bsize * CAST6_PARALLEL_BLOCKS) {
cast6_ecb_dec_8way(ctx->ctx, srcdst, srcdst);
return;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
__cast6_decrypt(ctx->ctx, srcdst, srcdst);
}
static int lrw_cast6_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct cast6_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
int err;
err = __cast6_setkey(&ctx->cast6_ctx, key, keylen - CAST6_BLOCK_SIZE,
&tfm->crt_flags);
if (err)
return err;
return lrw_init_table(&ctx->lrw_table, key + keylen - CAST6_BLOCK_SIZE);
}
static int lrw_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct cast6_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[CAST6_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->cast6_ctx,
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
cast6_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int lrw_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct cast6_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[CAST6_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->cast6_ctx,
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
cast6_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static void lrw_exit_tfm(struct crypto_tfm *tfm)
{
struct cast6_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
lrw_free_table(&ctx->lrw_table);
}
static int xts_cast6_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct cast6_xts_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
int err;
if (keylen % 2) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
err = __cast6_setkey(&ctx->crypt_ctx, key, keylen / 2, flags);
if (err)
return err;
return __cast6_setkey(&ctx->tweak_ctx, key + keylen / 2, keylen / 2,
flags);
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct cast6_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[CAST6_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->crypt_ctx,
.fpu_enabled = false,
};
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(__cast6_encrypt),
.crypt_ctx = &crypt_ctx,
.crypt_fn = encrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ret = xts_crypt(desc, dst, src, nbytes, &req);
cast6_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct cast6_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[CAST6_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->crypt_ctx,
.fpu_enabled = false,
};
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(__cast6_encrypt),
.crypt_ctx = &crypt_ctx,
.crypt_fn = decrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ret = xts_crypt(desc, dst, src, nbytes, &req);
cast6_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int __init cast6_init(void)
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
return crypto_register_algs(cast6_algs, ARRAY_SIZE(cast6_algs));
}
static void __exit cast6_exit(void)
{
crypto_unregister_algs(cast6_algs, ARRAY_SIZE(cast6_algs));
}
