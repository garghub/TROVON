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
void twofish_dec_blk_cbc_3way(void *ctx, u128 *dst, const u128 *src)
{
u128 ivs[2];
ivs[0] = src[0];
ivs[1] = src[1];
twofish_dec_blk_3way(ctx, (u8 *)dst, (u8 *)src);
u128_xor(&dst[1], &dst[1], &ivs[0]);
u128_xor(&dst[2], &dst[2], &ivs[1]);
}
void twofish_enc_blk_ctr(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
be128 ctrblk;
if (dst != src)
*dst = *src;
le128_to_be128(&ctrblk, iv);
le128_inc(iv);
twofish_enc_blk(ctx, (u8 *)&ctrblk, (u8 *)&ctrblk);
u128_xor(dst, dst, (u128 *)&ctrblk);
}
void twofish_enc_blk_ctr_3way(void *ctx, u128 *dst, const u128 *src,
le128 *iv)
{
be128 ctrblks[3];
if (dst != src) {
dst[0] = src[0];
dst[1] = src[1];
dst[2] = src[2];
}
le128_to_be128(&ctrblks[0], iv);
le128_inc(iv);
le128_to_be128(&ctrblks[1], iv);
le128_inc(iv);
le128_to_be128(&ctrblks[2], iv);
le128_inc(iv);
twofish_enc_blk_xor_3way(ctx, (u8 *)dst, (u8 *)ctrblks);
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
int lrw_twofish_setkey(struct crypto_tfm *tfm, const u8 *key,
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
void lrw_twofish_exit_tfm(struct crypto_tfm *tfm)
{
struct twofish_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
lrw_free_table(&ctx->lrw_table);
}
int xts_twofish_setkey(struct crypto_tfm *tfm, const u8 *key,
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
