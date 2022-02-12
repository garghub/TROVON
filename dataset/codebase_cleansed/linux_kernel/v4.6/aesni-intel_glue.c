static void aesni_gcm_enc_avx(void *ctx, u8 *out,
const u8 *in, unsigned long plaintext_len, u8 *iv,
u8 *hash_subkey, const u8 *aad, unsigned long aad_len,
u8 *auth_tag, unsigned long auth_tag_len)
{
struct crypto_aes_ctx *aes_ctx = (struct crypto_aes_ctx*)ctx;
if ((plaintext_len < AVX_GEN2_OPTSIZE) || (aes_ctx-> key_length != AES_KEYSIZE_128)){
aesni_gcm_enc(ctx, out, in, plaintext_len, iv, hash_subkey, aad,
aad_len, auth_tag, auth_tag_len);
} else {
aesni_gcm_precomp_avx_gen2(ctx, hash_subkey);
aesni_gcm_enc_avx_gen2(ctx, out, in, plaintext_len, iv, aad,
aad_len, auth_tag, auth_tag_len);
}
}
static void aesni_gcm_dec_avx(void *ctx, u8 *out,
const u8 *in, unsigned long ciphertext_len, u8 *iv,
u8 *hash_subkey, const u8 *aad, unsigned long aad_len,
u8 *auth_tag, unsigned long auth_tag_len)
{
struct crypto_aes_ctx *aes_ctx = (struct crypto_aes_ctx*)ctx;
if ((ciphertext_len < AVX_GEN2_OPTSIZE) || (aes_ctx-> key_length != AES_KEYSIZE_128)) {
aesni_gcm_dec(ctx, out, in, ciphertext_len, iv, hash_subkey, aad,
aad_len, auth_tag, auth_tag_len);
} else {
aesni_gcm_precomp_avx_gen2(ctx, hash_subkey);
aesni_gcm_dec_avx_gen2(ctx, out, in, ciphertext_len, iv, aad,
aad_len, auth_tag, auth_tag_len);
}
}
static void aesni_gcm_enc_avx2(void *ctx, u8 *out,
const u8 *in, unsigned long plaintext_len, u8 *iv,
u8 *hash_subkey, const u8 *aad, unsigned long aad_len,
u8 *auth_tag, unsigned long auth_tag_len)
{
struct crypto_aes_ctx *aes_ctx = (struct crypto_aes_ctx*)ctx;
if ((plaintext_len < AVX_GEN2_OPTSIZE) || (aes_ctx-> key_length != AES_KEYSIZE_128)) {
aesni_gcm_enc(ctx, out, in, plaintext_len, iv, hash_subkey, aad,
aad_len, auth_tag, auth_tag_len);
} else if (plaintext_len < AVX_GEN4_OPTSIZE) {
aesni_gcm_precomp_avx_gen2(ctx, hash_subkey);
aesni_gcm_enc_avx_gen2(ctx, out, in, plaintext_len, iv, aad,
aad_len, auth_tag, auth_tag_len);
} else {
aesni_gcm_precomp_avx_gen4(ctx, hash_subkey);
aesni_gcm_enc_avx_gen4(ctx, out, in, plaintext_len, iv, aad,
aad_len, auth_tag, auth_tag_len);
}
}
static void aesni_gcm_dec_avx2(void *ctx, u8 *out,
const u8 *in, unsigned long ciphertext_len, u8 *iv,
u8 *hash_subkey, const u8 *aad, unsigned long aad_len,
u8 *auth_tag, unsigned long auth_tag_len)
{
struct crypto_aes_ctx *aes_ctx = (struct crypto_aes_ctx*)ctx;
if ((ciphertext_len < AVX_GEN2_OPTSIZE) || (aes_ctx-> key_length != AES_KEYSIZE_128)) {
aesni_gcm_dec(ctx, out, in, ciphertext_len, iv, hash_subkey,
aad, aad_len, auth_tag, auth_tag_len);
} else if (ciphertext_len < AVX_GEN4_OPTSIZE) {
aesni_gcm_precomp_avx_gen2(ctx, hash_subkey);
aesni_gcm_dec_avx_gen2(ctx, out, in, ciphertext_len, iv, aad,
aad_len, auth_tag, auth_tag_len);
} else {
aesni_gcm_precomp_avx_gen4(ctx, hash_subkey);
aesni_gcm_dec_avx_gen4(ctx, out, in, ciphertext_len, iv, aad,
aad_len, auth_tag, auth_tag_len);
}
}
static inline struct
aesni_rfc4106_gcm_ctx *aesni_rfc4106_gcm_ctx_get(struct crypto_aead *tfm)
{
unsigned long align = AESNI_ALIGN;
if (align <= crypto_tfm_ctx_alignment())
align = 1;
return PTR_ALIGN(crypto_aead_ctx(tfm), align);
}
static inline struct crypto_aes_ctx *aes_ctx(void *raw_ctx)
{
unsigned long addr = (unsigned long)raw_ctx;
unsigned long align = AESNI_ALIGN;
if (align <= crypto_tfm_ctx_alignment())
align = 1;
return (struct crypto_aes_ctx *)ALIGN(addr, align);
}
static int aes_set_key_common(struct crypto_tfm *tfm, void *raw_ctx,
const u8 *in_key, unsigned int key_len)
{
struct crypto_aes_ctx *ctx = aes_ctx(raw_ctx);
u32 *flags = &tfm->crt_flags;
int err;
if (key_len != AES_KEYSIZE_128 && key_len != AES_KEYSIZE_192 &&
key_len != AES_KEYSIZE_256) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
if (!irq_fpu_usable())
err = crypto_aes_expand_key(ctx, in_key, key_len);
else {
kernel_fpu_begin();
err = aesni_set_key(ctx, in_key, key_len);
kernel_fpu_end();
}
return err;
}
static int aes_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
return aes_set_key_common(tfm, crypto_tfm_ctx(tfm), in_key, key_len);
}
static void aes_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_tfm_ctx(tfm));
if (!irq_fpu_usable())
crypto_aes_encrypt_x86(ctx, dst, src);
else {
kernel_fpu_begin();
aesni_enc(ctx, dst, src);
kernel_fpu_end();
}
}
static void aes_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_tfm_ctx(tfm));
if (!irq_fpu_usable())
crypto_aes_decrypt_x86(ctx, dst, src);
else {
kernel_fpu_begin();
aesni_dec(ctx, dst, src);
kernel_fpu_end();
}
}
static void __aes_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_tfm_ctx(tfm));
aesni_enc(ctx, dst, src);
}
static void __aes_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_tfm_ctx(tfm));
aesni_dec(ctx, dst, src);
}
static int ecb_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_blkcipher_ctx(desc->tfm));
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
while ((nbytes = walk.nbytes)) {
aesni_ecb_enc(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
kernel_fpu_end();
return err;
}
static int ecb_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_blkcipher_ctx(desc->tfm));
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
while ((nbytes = walk.nbytes)) {
aesni_ecb_dec(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
kernel_fpu_end();
return err;
}
static int cbc_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_blkcipher_ctx(desc->tfm));
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
while ((nbytes = walk.nbytes)) {
aesni_cbc_enc(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK, walk.iv);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
kernel_fpu_end();
return err;
}
static int cbc_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_blkcipher_ctx(desc->tfm));
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
while ((nbytes = walk.nbytes)) {
aesni_cbc_dec(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK, walk.iv);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
kernel_fpu_end();
return err;
}
static void ctr_crypt_final(struct crypto_aes_ctx *ctx,
struct blkcipher_walk *walk)
{
u8 *ctrblk = walk->iv;
u8 keystream[AES_BLOCK_SIZE];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
aesni_enc(ctx, keystream, ctrblk);
crypto_xor(keystream, src, nbytes);
memcpy(dst, keystream, nbytes);
crypto_inc(ctrblk, AES_BLOCK_SIZE);
}
static void aesni_ctr_enc_avx_tfm(struct crypto_aes_ctx *ctx, u8 *out,
const u8 *in, unsigned int len, u8 *iv)
{
if (ctx->key_length == AES_KEYSIZE_128)
aes_ctr_enc_128_avx_by8(in, iv, (void *)ctx, out, len);
else if (ctx->key_length == AES_KEYSIZE_192)
aes_ctr_enc_192_avx_by8(in, iv, (void *)ctx, out, len);
else
aes_ctr_enc_256_avx_by8(in, iv, (void *)ctx, out, len);
}
static int ctr_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_aes_ctx *ctx = aes_ctx(crypto_blkcipher_ctx(desc->tfm));
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, AES_BLOCK_SIZE);
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
while ((nbytes = walk.nbytes) >= AES_BLOCK_SIZE) {
aesni_ctr_enc_tfm(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK, walk.iv);
nbytes &= AES_BLOCK_SIZE - 1;
err = blkcipher_walk_done(desc, &walk, nbytes);
}
if (walk.nbytes) {
ctr_crypt_final(ctx, &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
kernel_fpu_end();
return err;
}
static int ablk_ecb_init(struct crypto_tfm *tfm)
{
return ablk_init_common(tfm, "__driver-ecb-aes-aesni");
}
static int ablk_cbc_init(struct crypto_tfm *tfm)
{
return ablk_init_common(tfm, "__driver-cbc-aes-aesni");
}
static int ablk_ctr_init(struct crypto_tfm *tfm)
{
return ablk_init_common(tfm, "__driver-ctr-aes-aesni");
}
static int ablk_pcbc_init(struct crypto_tfm *tfm)
{
return ablk_init_common(tfm, "fpu(pcbc(__driver-aes-aesni))");
}
static void lrw_xts_encrypt_callback(void *ctx, u8 *blks, unsigned int nbytes)
{
aesni_ecb_enc(ctx, blks, blks, nbytes);
}
static void lrw_xts_decrypt_callback(void *ctx, u8 *blks, unsigned int nbytes)
{
aesni_ecb_dec(ctx, blks, blks, nbytes);
}
static int lrw_aesni_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct aesni_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
int err;
err = aes_set_key_common(tfm, ctx->raw_aes_ctx, key,
keylen - AES_BLOCK_SIZE);
if (err)
return err;
return lrw_init_table(&ctx->lrw_table, key + keylen - AES_BLOCK_SIZE);
}
static void lrw_aesni_exit_tfm(struct crypto_tfm *tfm)
{
struct aesni_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
lrw_free_table(&ctx->lrw_table);
}
static int lrw_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesni_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[8];
struct lrw_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.table_ctx = &ctx->lrw_table,
.crypt_ctx = aes_ctx(ctx->raw_aes_ctx),
.crypt_fn = lrw_xts_encrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
ret = lrw_crypt(desc, dst, src, nbytes, &req);
kernel_fpu_end();
return ret;
}
static int lrw_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesni_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[8];
struct lrw_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.table_ctx = &ctx->lrw_table,
.crypt_ctx = aes_ctx(ctx->raw_aes_ctx),
.crypt_fn = lrw_xts_decrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
ret = lrw_crypt(desc, dst, src, nbytes, &req);
kernel_fpu_end();
return ret;
}
static int xts_aesni_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct aesni_xts_ctx *ctx = crypto_tfm_ctx(tfm);
int err;
err = xts_check_key(tfm, key, keylen);
if (err)
return err;
err = aes_set_key_common(tfm, ctx->raw_crypt_ctx, key, keylen / 2);
if (err)
return err;
return aes_set_key_common(tfm, ctx->raw_tweak_ctx, key + keylen / 2,
keylen / 2);
}
static void aesni_xts_tweak(void *ctx, u8 *out, const u8 *in)
{
aesni_enc(ctx, out, in);
}
static void aesni_xts_enc(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
glue_xts_crypt_128bit_one(ctx, dst, src, iv, GLUE_FUNC_CAST(aesni_enc));
}
static void aesni_xts_dec(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
glue_xts_crypt_128bit_one(ctx, dst, src, iv, GLUE_FUNC_CAST(aesni_dec));
}
static void aesni_xts_enc8(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
aesni_xts_crypt8(ctx, (u8 *)dst, (const u8 *)src, true, (u8 *)iv);
}
static void aesni_xts_dec8(void *ctx, u128 *dst, const u128 *src, le128 *iv)
{
aesni_xts_crypt8(ctx, (u8 *)dst, (const u8 *)src, false, (u8 *)iv);
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesni_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
return glue_xts_crypt_128bit(&aesni_enc_xts, desc, dst, src, nbytes,
XTS_TWEAK_CAST(aesni_xts_tweak),
aes_ctx(ctx->raw_tweak_ctx),
aes_ctx(ctx->raw_crypt_ctx));
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesni_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
return glue_xts_crypt_128bit(&aesni_dec_xts, desc, dst, src, nbytes,
XTS_TWEAK_CAST(aesni_xts_tweak),
aes_ctx(ctx->raw_tweak_ctx),
aes_ctx(ctx->raw_crypt_ctx));
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesni_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[8];
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = aes_ctx(ctx->raw_tweak_ctx),
.tweak_fn = aesni_xts_tweak,
.crypt_ctx = aes_ctx(ctx->raw_crypt_ctx),
.crypt_fn = lrw_xts_encrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
ret = xts_crypt(desc, dst, src, nbytes, &req);
kernel_fpu_end();
return ret;
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct aesni_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[8];
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = aes_ctx(ctx->raw_tweak_ctx),
.tweak_fn = aesni_xts_tweak,
.crypt_ctx = aes_ctx(ctx->raw_crypt_ctx),
.crypt_fn = lrw_xts_decrypt_callback,
};
int ret;
desc->flags &= ~CRYPTO_TFM_REQ_MAY_SLEEP;
kernel_fpu_begin();
ret = xts_crypt(desc, dst, src, nbytes, &req);
kernel_fpu_end();
return ret;
}
static int rfc4106_init(struct crypto_aead *aead)
{
struct cryptd_aead *cryptd_tfm;
struct cryptd_aead **ctx = crypto_aead_ctx(aead);
cryptd_tfm = cryptd_alloc_aead("__driver-gcm-aes-aesni",
CRYPTO_ALG_INTERNAL,
CRYPTO_ALG_INTERNAL);
if (IS_ERR(cryptd_tfm))
return PTR_ERR(cryptd_tfm);
*ctx = cryptd_tfm;
crypto_aead_set_reqsize(aead, crypto_aead_reqsize(&cryptd_tfm->base));
return 0;
}
static void rfc4106_exit(struct crypto_aead *aead)
{
struct cryptd_aead **ctx = crypto_aead_ctx(aead);
cryptd_free_aead(*ctx);
}
static void
rfc4106_set_hash_subkey_done(struct crypto_async_request *req, int err)
{
struct aesni_gcm_set_hash_subkey_result *result = req->data;
if (err == -EINPROGRESS)
return;
result->err = err;
complete(&result->completion);
}
static int
rfc4106_set_hash_subkey(u8 *hash_subkey, const u8 *key, unsigned int key_len)
{
struct crypto_ablkcipher *ctr_tfm;
struct ablkcipher_request *req;
int ret = -EINVAL;
struct aesni_hash_subkey_req_data *req_data;
ctr_tfm = crypto_alloc_ablkcipher("ctr(aes)", 0, 0);
if (IS_ERR(ctr_tfm))
return PTR_ERR(ctr_tfm);
ret = crypto_ablkcipher_setkey(ctr_tfm, key, key_len);
if (ret)
goto out_free_ablkcipher;
ret = -ENOMEM;
req = ablkcipher_request_alloc(ctr_tfm, GFP_KERNEL);
if (!req)
goto out_free_ablkcipher;
req_data = kmalloc(sizeof(*req_data), GFP_KERNEL);
if (!req_data)
goto out_free_request;
memset(req_data->iv, 0, sizeof(req_data->iv));
memset(hash_subkey, 0, RFC4106_HASH_SUBKEY_SIZE);
init_completion(&req_data->result.completion);
sg_init_one(&req_data->sg, hash_subkey, RFC4106_HASH_SUBKEY_SIZE);
ablkcipher_request_set_tfm(req, ctr_tfm);
ablkcipher_request_set_callback(req, CRYPTO_TFM_REQ_MAY_SLEEP |
CRYPTO_TFM_REQ_MAY_BACKLOG,
rfc4106_set_hash_subkey_done,
&req_data->result);
ablkcipher_request_set_crypt(req, &req_data->sg,
&req_data->sg, RFC4106_HASH_SUBKEY_SIZE, req_data->iv);
ret = crypto_ablkcipher_encrypt(req);
if (ret == -EINPROGRESS || ret == -EBUSY) {
ret = wait_for_completion_interruptible
(&req_data->result.completion);
if (!ret)
ret = req_data->result.err;
}
kfree(req_data);
out_free_request:
ablkcipher_request_free(req);
out_free_ablkcipher:
crypto_free_ablkcipher(ctr_tfm);
return ret;
}
static int common_rfc4106_set_key(struct crypto_aead *aead, const u8 *key,
unsigned int key_len)
{
struct aesni_rfc4106_gcm_ctx *ctx = aesni_rfc4106_gcm_ctx_get(aead);
if (key_len < 4) {
crypto_aead_set_flags(aead, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
key_len -= 4;
memcpy(ctx->nonce, key + key_len, sizeof(ctx->nonce));
return aes_set_key_common(crypto_aead_tfm(aead),
&ctx->aes_key_expanded, key, key_len) ?:
rfc4106_set_hash_subkey(ctx->hash_subkey, key, key_len);
}
static int rfc4106_set_key(struct crypto_aead *parent, const u8 *key,
unsigned int key_len)
{
struct cryptd_aead **ctx = crypto_aead_ctx(parent);
struct cryptd_aead *cryptd_tfm = *ctx;
return crypto_aead_setkey(&cryptd_tfm->base, key, key_len);
}
static int common_rfc4106_set_authsize(struct crypto_aead *aead,
unsigned int authsize)
{
switch (authsize) {
case 8:
case 12:
case 16:
break;
default:
return -EINVAL;
}
return 0;
}
static int rfc4106_set_authsize(struct crypto_aead *parent,
unsigned int authsize)
{
struct cryptd_aead **ctx = crypto_aead_ctx(parent);
struct cryptd_aead *cryptd_tfm = *ctx;
return crypto_aead_setauthsize(&cryptd_tfm->base, authsize);
}
static int helper_rfc4106_encrypt(struct aead_request *req)
{
u8 one_entry_in_sg = 0;
u8 *src, *dst, *assoc;
__be32 counter = cpu_to_be32(1);
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct aesni_rfc4106_gcm_ctx *ctx = aesni_rfc4106_gcm_ctx_get(tfm);
void *aes_ctx = &(ctx->aes_key_expanded);
unsigned long auth_tag_len = crypto_aead_authsize(tfm);
u8 iv[16] __attribute__ ((__aligned__(AESNI_ALIGN)));
struct scatter_walk src_sg_walk;
struct scatter_walk dst_sg_walk;
unsigned int i;
if (unlikely(req->assoclen != 16 && req->assoclen != 20))
return -EINVAL;
for (i = 0; i < 4; i++)
*(iv+i) = ctx->nonce[i];
for (i = 0; i < 8; i++)
*(iv+4+i) = req->iv[i];
*((__be32 *)(iv+12)) = counter;
if (sg_is_last(req->src) &&
req->src->offset + req->src->length <= PAGE_SIZE &&
sg_is_last(req->dst) &&
req->dst->offset + req->dst->length <= PAGE_SIZE) {
one_entry_in_sg = 1;
scatterwalk_start(&src_sg_walk, req->src);
assoc = scatterwalk_map(&src_sg_walk);
src = assoc + req->assoclen;
dst = src;
if (unlikely(req->src != req->dst)) {
scatterwalk_start(&dst_sg_walk, req->dst);
dst = scatterwalk_map(&dst_sg_walk) + req->assoclen;
}
} else {
assoc = kmalloc(req->cryptlen + auth_tag_len + req->assoclen,
GFP_ATOMIC);
if (unlikely(!assoc))
return -ENOMEM;
scatterwalk_map_and_copy(assoc, req->src, 0,
req->assoclen + req->cryptlen, 0);
src = assoc + req->assoclen;
dst = src;
}
kernel_fpu_begin();
aesni_gcm_enc_tfm(aes_ctx, dst, src, req->cryptlen, iv,
ctx->hash_subkey, assoc, req->assoclen - 8,
dst + req->cryptlen, auth_tag_len);
kernel_fpu_end();
if (one_entry_in_sg) {
if (unlikely(req->src != req->dst)) {
scatterwalk_unmap(dst - req->assoclen);
scatterwalk_advance(&dst_sg_walk, req->dst->length);
scatterwalk_done(&dst_sg_walk, 1, 0);
}
scatterwalk_unmap(assoc);
scatterwalk_advance(&src_sg_walk, req->src->length);
scatterwalk_done(&src_sg_walk, req->src == req->dst, 0);
} else {
scatterwalk_map_and_copy(dst, req->dst, req->assoclen,
req->cryptlen + auth_tag_len, 1);
kfree(assoc);
}
return 0;
}
static int helper_rfc4106_decrypt(struct aead_request *req)
{
u8 one_entry_in_sg = 0;
u8 *src, *dst, *assoc;
unsigned long tempCipherLen = 0;
__be32 counter = cpu_to_be32(1);
int retval = 0;
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct aesni_rfc4106_gcm_ctx *ctx = aesni_rfc4106_gcm_ctx_get(tfm);
void *aes_ctx = &(ctx->aes_key_expanded);
unsigned long auth_tag_len = crypto_aead_authsize(tfm);
u8 iv[16] __attribute__ ((__aligned__(AESNI_ALIGN)));
u8 authTag[16];
struct scatter_walk src_sg_walk;
struct scatter_walk dst_sg_walk;
unsigned int i;
if (unlikely(req->assoclen != 16 && req->assoclen != 20))
return -EINVAL;
tempCipherLen = (unsigned long)(req->cryptlen - auth_tag_len);
for (i = 0; i < 4; i++)
*(iv+i) = ctx->nonce[i];
for (i = 0; i < 8; i++)
*(iv+4+i) = req->iv[i];
*((__be32 *)(iv+12)) = counter;
if (sg_is_last(req->src) &&
req->src->offset + req->src->length <= PAGE_SIZE &&
sg_is_last(req->dst) &&
req->dst->offset + req->dst->length <= PAGE_SIZE) {
one_entry_in_sg = 1;
scatterwalk_start(&src_sg_walk, req->src);
assoc = scatterwalk_map(&src_sg_walk);
src = assoc + req->assoclen;
dst = src;
if (unlikely(req->src != req->dst)) {
scatterwalk_start(&dst_sg_walk, req->dst);
dst = scatterwalk_map(&dst_sg_walk) + req->assoclen;
}
} else {
assoc = kmalloc(req->cryptlen + req->assoclen, GFP_ATOMIC);
if (!assoc)
return -ENOMEM;
scatterwalk_map_and_copy(assoc, req->src, 0,
req->assoclen + req->cryptlen, 0);
src = assoc + req->assoclen;
dst = src;
}
kernel_fpu_begin();
aesni_gcm_dec_tfm(aes_ctx, dst, src, tempCipherLen, iv,
ctx->hash_subkey, assoc, req->assoclen - 8,
authTag, auth_tag_len);
kernel_fpu_end();
retval = crypto_memneq(src + tempCipherLen, authTag, auth_tag_len) ?
-EBADMSG : 0;
if (one_entry_in_sg) {
if (unlikely(req->src != req->dst)) {
scatterwalk_unmap(dst - req->assoclen);
scatterwalk_advance(&dst_sg_walk, req->dst->length);
scatterwalk_done(&dst_sg_walk, 1, 0);
}
scatterwalk_unmap(assoc);
scatterwalk_advance(&src_sg_walk, req->src->length);
scatterwalk_done(&src_sg_walk, req->src == req->dst, 0);
} else {
scatterwalk_map_and_copy(dst, req->dst, req->assoclen,
tempCipherLen, 1);
kfree(assoc);
}
return retval;
}
static int rfc4106_encrypt(struct aead_request *req)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct cryptd_aead **ctx = crypto_aead_ctx(tfm);
struct cryptd_aead *cryptd_tfm = *ctx;
aead_request_set_tfm(req, irq_fpu_usable() ?
cryptd_aead_child(cryptd_tfm) :
&cryptd_tfm->base);
return crypto_aead_encrypt(req);
}
static int rfc4106_decrypt(struct aead_request *req)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct cryptd_aead **ctx = crypto_aead_ctx(tfm);
struct cryptd_aead *cryptd_tfm = *ctx;
aead_request_set_tfm(req, irq_fpu_usable() ?
cryptd_aead_child(cryptd_tfm) :
&cryptd_tfm->base);
return crypto_aead_decrypt(req);
}
static int __init aesni_init(void)
{
int err;
if (!x86_match_cpu(aesni_cpu_id))
return -ENODEV;
#ifdef CONFIG_X86_64
#ifdef CONFIG_AS_AVX2
if (boot_cpu_has(X86_FEATURE_AVX2)) {
pr_info("AVX2 version of gcm_enc/dec engaged.\n");
aesni_gcm_enc_tfm = aesni_gcm_enc_avx2;
aesni_gcm_dec_tfm = aesni_gcm_dec_avx2;
} else
#endif
#ifdef CONFIG_AS_AVX
if (boot_cpu_has(X86_FEATURE_AVX)) {
pr_info("AVX version of gcm_enc/dec engaged.\n");
aesni_gcm_enc_tfm = aesni_gcm_enc_avx;
aesni_gcm_dec_tfm = aesni_gcm_dec_avx;
} else
#endif
{
pr_info("SSE version of gcm_enc/dec engaged.\n");
aesni_gcm_enc_tfm = aesni_gcm_enc;
aesni_gcm_dec_tfm = aesni_gcm_dec;
}
aesni_ctr_enc_tfm = aesni_ctr_enc;
#ifdef CONFIG_AS_AVX
if (cpu_has_avx) {
aesni_ctr_enc_tfm = aesni_ctr_enc_avx_tfm;
pr_info("AES CTR mode by8 optimization enabled\n");
}
#endif
#endif
err = crypto_fpu_init();
if (err)
return err;
err = crypto_register_algs(aesni_algs, ARRAY_SIZE(aesni_algs));
if (err)
goto fpu_exit;
err = crypto_register_aeads(aesni_aead_algs,
ARRAY_SIZE(aesni_aead_algs));
if (err)
goto unregister_algs;
return err;
unregister_algs:
crypto_unregister_algs(aesni_algs, ARRAY_SIZE(aesni_algs));
fpu_exit:
crypto_fpu_exit();
return err;
}
static void __exit aesni_exit(void)
{
crypto_unregister_aeads(aesni_aead_algs, ARRAY_SIZE(aesni_aead_algs));
crypto_unregister_algs(aesni_algs, ARRAY_SIZE(aesni_algs));
crypto_fpu_exit();
}
