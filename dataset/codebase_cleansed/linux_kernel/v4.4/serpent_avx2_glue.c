static int ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ecb_crypt_128bit(&serpent_enc, desc, dst, src, nbytes);
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ecb_crypt_128bit(&serpent_dec, desc, dst, src, nbytes);
}
static int cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_cbc_encrypt_128bit(GLUE_FUNC_CAST(__serpent_encrypt), desc,
dst, src, nbytes);
}
static int cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_cbc_decrypt_128bit(&serpent_dec_cbc, desc, dst, src,
nbytes);
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ctr_crypt_128bit(&serpent_ctr, desc, dst, src, nbytes);
}
static inline bool serpent_fpu_begin(bool fpu_enabled, unsigned int nbytes)
{
return glue_fpu_begin(SERPENT_BLOCK_SIZE, 8, NULL, fpu_enabled, nbytes);
}
static inline void serpent_fpu_end(bool fpu_enabled)
{
glue_fpu_end(fpu_enabled);
}
static void encrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = SERPENT_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = serpent_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes >= SERPENT_AVX2_PARALLEL_BLOCKS * bsize) {
serpent_ecb_enc_16way(ctx->ctx, srcdst, srcdst);
srcdst += bsize * SERPENT_AVX2_PARALLEL_BLOCKS;
nbytes -= bsize * SERPENT_AVX2_PARALLEL_BLOCKS;
}
while (nbytes >= SERPENT_PARALLEL_BLOCKS * bsize) {
serpent_ecb_enc_8way_avx(ctx->ctx, srcdst, srcdst);
srcdst += bsize * SERPENT_PARALLEL_BLOCKS;
nbytes -= bsize * SERPENT_PARALLEL_BLOCKS;
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
if (nbytes >= SERPENT_AVX2_PARALLEL_BLOCKS * bsize) {
serpent_ecb_dec_16way(ctx->ctx, srcdst, srcdst);
srcdst += bsize * SERPENT_AVX2_PARALLEL_BLOCKS;
nbytes -= bsize * SERPENT_AVX2_PARALLEL_BLOCKS;
}
while (nbytes >= SERPENT_PARALLEL_BLOCKS * bsize) {
serpent_ecb_dec_8way_avx(ctx->ctx, srcdst, srcdst);
srcdst += bsize * SERPENT_PARALLEL_BLOCKS;
nbytes -= bsize * SERPENT_PARALLEL_BLOCKS;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
__serpent_decrypt(ctx->ctx, srcdst, srcdst);
}
static int lrw_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct serpent_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[SERPENT_AVX2_PARALLEL_BLOCKS];
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
be128 buf[SERPENT_AVX2_PARALLEL_BLOCKS];
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
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct serpent_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
return glue_xts_crypt_128bit(&serpent_enc_xts, desc, dst, src, nbytes,
XTS_TWEAK_CAST(__serpent_encrypt),
&ctx->tweak_ctx, &ctx->crypt_ctx);
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct serpent_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
return glue_xts_crypt_128bit(&serpent_dec_xts, desc, dst, src, nbytes,
XTS_TWEAK_CAST(__serpent_encrypt),
&ctx->tweak_ctx, &ctx->crypt_ctx);
}
static int __init init(void)
{
const char *feature_name;
if (!cpu_has_avx2 || !cpu_has_osxsave) {
pr_info("AVX2 instructions are not detected.\n");
return -ENODEV;
}
if (!cpu_has_xfeatures(XFEATURE_MASK_SSE | XFEATURE_MASK_YMM,
&feature_name)) {
pr_info("CPU feature '%s' is not supported.\n", feature_name);
return -ENODEV;
}
return crypto_register_algs(srp_algs, ARRAY_SIZE(srp_algs));
}
static void __exit fini(void)
{
crypto_unregister_algs(srp_algs, ARRAY_SIZE(srp_algs));
}
