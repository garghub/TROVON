static inline void twofish_enc_blk_3way(struct twofish_ctx *ctx, u8 *dst,
const u8 *src)
{
__twofish_enc_blk_3way(ctx, dst, src, false);
}
static int ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ecb_crypt_128bit(&twofish_enc, desc, dst, src, nbytes);
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ecb_crypt_128bit(&twofish_dec, desc, dst, src, nbytes);
}
static int cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_cbc_encrypt_128bit(GLUE_FUNC_CAST(twofish_enc_blk), desc,
dst, src, nbytes);
}
static int cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_cbc_decrypt_128bit(&twofish_dec_cbc, desc, dst, src,
nbytes);
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ctr_crypt_128bit(&twofish_ctr, desc, dst, src, nbytes);
}
static inline bool twofish_fpu_begin(bool fpu_enabled, unsigned int nbytes)
{
return glue_fpu_begin(TF_BLOCK_SIZE, TWOFISH_PARALLEL_BLOCKS, NULL,
fpu_enabled, nbytes);
}
static inline void twofish_fpu_end(bool fpu_enabled)
{
glue_fpu_end(fpu_enabled);
}
static void encrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = TF_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = twofish_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes == bsize * TWOFISH_PARALLEL_BLOCKS) {
twofish_ecb_enc_8way(ctx->ctx, srcdst, srcdst);
return;
}
for (i = 0; i < nbytes / (bsize * 3); i++, srcdst += bsize * 3)
twofish_enc_blk_3way(ctx->ctx, srcdst, srcdst);
nbytes %= bsize * 3;
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
twofish_enc_blk(ctx->ctx, srcdst, srcdst);
}
static void decrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = TF_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = twofish_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes == bsize * TWOFISH_PARALLEL_BLOCKS) {
twofish_ecb_dec_8way(ctx->ctx, srcdst, srcdst);
return;
}
for (i = 0; i < nbytes / (bsize * 3); i++, srcdst += bsize * 3)
twofish_dec_blk_3way(ctx->ctx, srcdst, srcdst);
nbytes %= bsize * 3;
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
twofish_dec_blk(ctx->ctx, srcdst, srcdst);
}
static int lrw_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct twofish_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[TWOFISH_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->twofish_ctx,
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
twofish_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int lrw_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct twofish_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[TWOFISH_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->twofish_ctx,
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
twofish_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct twofish_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[TWOFISH_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->crypt_ctx,
.fpu_enabled = false,
};
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(twofish_enc_blk),
.crypt_ctx = &crypt_ctx,
.crypt_fn = encrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ret = xts_crypt(desc, dst, src, nbytes, &req);
twofish_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct twofish_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[TWOFISH_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->crypt_ctx,
.fpu_enabled = false,
};
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(twofish_enc_blk),
.crypt_ctx = &crypt_ctx,
.crypt_fn = decrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
ret = xts_crypt(desc, dst, src, nbytes, &req);
twofish_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int __init twofish_init(void)
{
u64 xcr0;
if (!cpu_has_avx || !cpu_has_osxsave) {
printk(KERN_INFO "AVX instructions are not detected.\n");
return -ENODEV;
}
xcr0 = xgetbv(XCR_XFEATURE_ENABLED_MASK);
if ((xcr0 & (XSTATE_SSE | XSTATE_YMM)) != (XSTATE_SSE | XSTATE_YMM)) {
printk(KERN_INFO "AVX detected but unusable.\n");
return -ENODEV;
}
return crypto_register_algs(twofish_algs, ARRAY_SIZE(twofish_algs));
}
static void __exit twofish_exit(void)
{
crypto_unregister_algs(twofish_algs, ARRAY_SIZE(twofish_algs));
}
