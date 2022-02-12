static int ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ecb_crypt_128bit(&camellia_enc, desc, dst, src, nbytes);
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ecb_crypt_128bit(&camellia_dec, desc, dst, src, nbytes);
}
static int cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_cbc_encrypt_128bit(GLUE_FUNC_CAST(camellia_enc_blk), desc,
dst, src, nbytes);
}
static int cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_cbc_decrypt_128bit(&camellia_dec_cbc, desc, dst, src,
nbytes);
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
return glue_ctr_crypt_128bit(&camellia_ctr, desc, dst, src, nbytes);
}
static inline bool camellia_fpu_begin(bool fpu_enabled, unsigned int nbytes)
{
return glue_fpu_begin(CAMELLIA_BLOCK_SIZE,
CAMELLIA_AESNI_PARALLEL_BLOCKS, NULL, fpu_enabled,
nbytes);
}
static inline void camellia_fpu_end(bool fpu_enabled)
{
glue_fpu_end(fpu_enabled);
}
static int camellia_setkey(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
return __camellia_setkey(crypto_tfm_ctx(tfm), in_key, key_len,
&tfm->crt_flags);
}
static void encrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = CAMELLIA_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = camellia_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes >= CAMELLIA_AESNI_AVX2_PARALLEL_BLOCKS * bsize) {
camellia_ecb_enc_32way(ctx->ctx, srcdst, srcdst);
srcdst += bsize * CAMELLIA_AESNI_AVX2_PARALLEL_BLOCKS;
nbytes -= bsize * CAMELLIA_AESNI_AVX2_PARALLEL_BLOCKS;
}
if (nbytes >= CAMELLIA_AESNI_PARALLEL_BLOCKS * bsize) {
camellia_ecb_enc_16way(ctx->ctx, srcdst, srcdst);
srcdst += bsize * CAMELLIA_AESNI_PARALLEL_BLOCKS;
nbytes -= bsize * CAMELLIA_AESNI_PARALLEL_BLOCKS;
}
while (nbytes >= CAMELLIA_PARALLEL_BLOCKS * bsize) {
camellia_enc_blk_2way(ctx->ctx, srcdst, srcdst);
srcdst += bsize * CAMELLIA_PARALLEL_BLOCKS;
nbytes -= bsize * CAMELLIA_PARALLEL_BLOCKS;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
camellia_enc_blk(ctx->ctx, srcdst, srcdst);
}
static void decrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = CAMELLIA_BLOCK_SIZE;
struct crypt_priv *ctx = priv;
int i;
ctx->fpu_enabled = camellia_fpu_begin(ctx->fpu_enabled, nbytes);
if (nbytes >= CAMELLIA_AESNI_AVX2_PARALLEL_BLOCKS * bsize) {
camellia_ecb_dec_32way(ctx->ctx, srcdst, srcdst);
srcdst += bsize * CAMELLIA_AESNI_AVX2_PARALLEL_BLOCKS;
nbytes -= bsize * CAMELLIA_AESNI_AVX2_PARALLEL_BLOCKS;
}
if (nbytes >= CAMELLIA_AESNI_PARALLEL_BLOCKS * bsize) {
camellia_ecb_dec_16way(ctx->ctx, srcdst, srcdst);
srcdst += bsize * CAMELLIA_AESNI_PARALLEL_BLOCKS;
nbytes -= bsize * CAMELLIA_AESNI_PARALLEL_BLOCKS;
}
while (nbytes >= CAMELLIA_PARALLEL_BLOCKS * bsize) {
camellia_dec_blk_2way(ctx->ctx, srcdst, srcdst);
srcdst += bsize * CAMELLIA_PARALLEL_BLOCKS;
nbytes -= bsize * CAMELLIA_PARALLEL_BLOCKS;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
camellia_dec_blk(ctx->ctx, srcdst, srcdst);
}
static int lrw_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct camellia_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[CAMELLIA_AESNI_AVX2_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->camellia_ctx,
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
camellia_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int lrw_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct camellia_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[CAMELLIA_AESNI_AVX2_PARALLEL_BLOCKS];
struct crypt_priv crypt_ctx = {
.ctx = &ctx->camellia_ctx,
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
camellia_fpu_end(crypt_ctx.fpu_enabled);
return ret;
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct camellia_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
return glue_xts_crypt_128bit(&camellia_enc_xts, desc, dst, src, nbytes,
XTS_TWEAK_CAST(camellia_enc_blk),
&ctx->tweak_ctx, &ctx->crypt_ctx);
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct camellia_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
return glue_xts_crypt_128bit(&camellia_dec_xts, desc, dst, src, nbytes,
XTS_TWEAK_CAST(camellia_enc_blk),
&ctx->tweak_ctx, &ctx->crypt_ctx);
}
static int __init camellia_aesni_init(void)
{
const char *feature_name;
if (!boot_cpu_has(X86_FEATURE_AVX) ||
!boot_cpu_has(X86_FEATURE_AVX2) ||
!boot_cpu_has(X86_FEATURE_AES) ||
!boot_cpu_has(X86_FEATURE_OSXSAVE)) {
pr_info("AVX2 or AES-NI instructions are not detected.\n");
return -ENODEV;
}
if (!cpu_has_xfeatures(XFEATURE_MASK_SSE | XFEATURE_MASK_YMM,
&feature_name)) {
pr_info("CPU feature '%s' is not supported.\n", feature_name);
return -ENODEV;
}
return crypto_register_algs(cmll_algs, ARRAY_SIZE(cmll_algs));
}
static void __exit camellia_aesni_fini(void)
{
crypto_unregister_algs(cmll_algs, ARRAY_SIZE(cmll_algs));
}
