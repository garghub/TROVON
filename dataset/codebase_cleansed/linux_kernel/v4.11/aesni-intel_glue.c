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
static int aesni_skcipher_setkey(struct crypto_skcipher *tfm, const u8 *key,
unsigned int len)
{
return aes_set_key_common(crypto_skcipher_tfm(tfm),
crypto_skcipher_ctx(tfm), key, len);
}
static int ecb_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = aes_ctx(crypto_skcipher_ctx(tfm));
struct skcipher_walk walk;
unsigned int nbytes;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_fpu_begin();
while ((nbytes = walk.nbytes)) {
aesni_ecb_enc(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK);
nbytes &= AES_BLOCK_SIZE - 1;
err = skcipher_walk_done(&walk, nbytes);
}
kernel_fpu_end();
return err;
}
static int ecb_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = aes_ctx(crypto_skcipher_ctx(tfm));
struct skcipher_walk walk;
unsigned int nbytes;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_fpu_begin();
while ((nbytes = walk.nbytes)) {
aesni_ecb_dec(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK);
nbytes &= AES_BLOCK_SIZE - 1;
err = skcipher_walk_done(&walk, nbytes);
}
kernel_fpu_end();
return err;
}
static int cbc_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = aes_ctx(crypto_skcipher_ctx(tfm));
struct skcipher_walk walk;
unsigned int nbytes;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_fpu_begin();
while ((nbytes = walk.nbytes)) {
aesni_cbc_enc(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK, walk.iv);
nbytes &= AES_BLOCK_SIZE - 1;
err = skcipher_walk_done(&walk, nbytes);
}
kernel_fpu_end();
return err;
}
static int cbc_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = aes_ctx(crypto_skcipher_ctx(tfm));
struct skcipher_walk walk;
unsigned int nbytes;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_fpu_begin();
while ((nbytes = walk.nbytes)) {
aesni_cbc_dec(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK, walk.iv);
nbytes &= AES_BLOCK_SIZE - 1;
err = skcipher_walk_done(&walk, nbytes);
}
kernel_fpu_end();
return err;
}
static void ctr_crypt_final(struct crypto_aes_ctx *ctx,
struct skcipher_walk *walk)
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
static int ctr_crypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = aes_ctx(crypto_skcipher_ctx(tfm));
struct skcipher_walk walk;
unsigned int nbytes;
int err;
err = skcipher_walk_virt(&walk, req, true);
kernel_fpu_begin();
while ((nbytes = walk.nbytes) >= AES_BLOCK_SIZE) {
aesni_ctr_enc_tfm(ctx, walk.dst.virt.addr, walk.src.virt.addr,
nbytes & AES_BLOCK_MASK, walk.iv);
nbytes &= AES_BLOCK_SIZE - 1;
err = skcipher_walk_done(&walk, nbytes);
}
if (walk.nbytes) {
ctr_crypt_final(ctx, &walk);
err = skcipher_walk_done(&walk, 0);
}
kernel_fpu_end();
return err;
}
static int xts_aesni_setkey(struct crypto_skcipher *tfm, const u8 *key,
unsigned int keylen)
{
struct aesni_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int err;
err = xts_verify_key(tfm, key, keylen);
if (err)
return err;
keylen /= 2;
err = aes_set_key_common(crypto_skcipher_tfm(tfm), ctx->raw_crypt_ctx,
key, keylen);
if (err)
return err;
return aes_set_key_common(crypto_skcipher_tfm(tfm), ctx->raw_tweak_ctx,
key + keylen, keylen);
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
static int xts_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesni_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
return glue_xts_req_128bit(&aesni_enc_xts, req,
XTS_TWEAK_CAST(aesni_xts_tweak),
aes_ctx(ctx->raw_tweak_ctx),
aes_ctx(ctx->raw_crypt_ctx));
}
static int xts_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct aesni_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
return glue_xts_req_128bit(&aesni_dec_xts, req,
XTS_TWEAK_CAST(aesni_xts_tweak),
aes_ctx(ctx->raw_tweak_ctx),
aes_ctx(ctx->raw_crypt_ctx));
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
static int
rfc4106_set_hash_subkey(u8 *hash_subkey, const u8 *key, unsigned int key_len)
{
struct crypto_cipher *tfm;
int ret;
tfm = crypto_alloc_cipher("aes", 0, 0);
if (IS_ERR(tfm))
return PTR_ERR(tfm);
ret = crypto_cipher_setkey(tfm, key, key_len);
if (ret)
goto out_free_cipher;
memset(hash_subkey, 0, RFC4106_HASH_SUBKEY_SIZE);
crypto_cipher_encrypt_one(tfm, hash_subkey, hash_subkey);
out_free_cipher:
crypto_free_cipher(tfm);
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
struct scatter_walk dst_sg_walk = {};
unsigned int i;
if (unlikely(req->assoclen != 16 && req->assoclen != 20))
return -EINVAL;
for (i = 0; i < 4; i++)
*(iv+i) = ctx->nonce[i];
for (i = 0; i < 8; i++)
*(iv+4+i) = req->iv[i];
*((__be32 *)(iv+12)) = counter;
if (sg_is_last(req->src) &&
(!PageHighMem(sg_page(req->src)) ||
req->src->offset + req->src->length <= PAGE_SIZE) &&
sg_is_last(req->dst) &&
(!PageHighMem(sg_page(req->dst)) ||
req->dst->offset + req->dst->length <= PAGE_SIZE)) {
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
struct scatter_walk dst_sg_walk = {};
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
(!PageHighMem(sg_page(req->src)) ||
req->src->offset + req->src->length <= PAGE_SIZE) &&
sg_is_last(req->dst) &&
(!PageHighMem(sg_page(req->dst)) ||
req->dst->offset + req->dst->length <= PAGE_SIZE)) {
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
tfm = &cryptd_tfm->base;
if (irq_fpu_usable() && (!in_atomic() ||
!cryptd_aead_queued(cryptd_tfm)))
tfm = cryptd_aead_child(cryptd_tfm);
aead_request_set_tfm(req, tfm);
return crypto_aead_encrypt(req);
}
static int rfc4106_decrypt(struct aead_request *req)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct cryptd_aead **ctx = crypto_aead_ctx(tfm);
struct cryptd_aead *cryptd_tfm = *ctx;
tfm = &cryptd_tfm->base;
if (irq_fpu_usable() && (!in_atomic() ||
!cryptd_aead_queued(cryptd_tfm)))
tfm = cryptd_aead_child(cryptd_tfm);
aead_request_set_tfm(req, tfm);
return crypto_aead_decrypt(req);
}
static void aesni_free_simds(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(aesni_simd_skciphers) &&
aesni_simd_skciphers[i]; i++)
simd_skcipher_free(aesni_simd_skciphers[i]);
for (i = 0; i < ARRAY_SIZE(aesni_simd_skciphers2); i++)
if (aesni_simd_skciphers2[i].simd)
simd_skcipher_free(aesni_simd_skciphers2[i].simd);
}
static int __init aesni_init(void)
{
struct simd_skcipher_alg *simd;
const char *basename;
const char *algname;
const char *drvname;
int err;
int i;
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
if (boot_cpu_has(X86_FEATURE_AVX)) {
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
err = crypto_register_skciphers(aesni_skciphers,
ARRAY_SIZE(aesni_skciphers));
if (err)
goto unregister_algs;
err = crypto_register_aeads(aesni_aead_algs,
ARRAY_SIZE(aesni_aead_algs));
if (err)
goto unregister_skciphers;
for (i = 0; i < ARRAY_SIZE(aesni_skciphers); i++) {
algname = aesni_skciphers[i].base.cra_name + 2;
drvname = aesni_skciphers[i].base.cra_driver_name + 2;
basename = aesni_skciphers[i].base.cra_driver_name;
simd = simd_skcipher_create_compat(algname, drvname, basename);
err = PTR_ERR(simd);
if (IS_ERR(simd))
goto unregister_simds;
aesni_simd_skciphers[i] = simd;
}
for (i = 0; i < ARRAY_SIZE(aesni_simd_skciphers2); i++) {
algname = aesni_simd_skciphers2[i].algname;
drvname = aesni_simd_skciphers2[i].drvname;
basename = aesni_simd_skciphers2[i].basename;
simd = simd_skcipher_create_compat(algname, drvname, basename);
err = PTR_ERR(simd);
if (IS_ERR(simd))
continue;
aesni_simd_skciphers2[i].simd = simd;
}
return 0;
unregister_simds:
aesni_free_simds();
crypto_unregister_aeads(aesni_aead_algs, ARRAY_SIZE(aesni_aead_algs));
unregister_skciphers:
crypto_unregister_skciphers(aesni_skciphers,
ARRAY_SIZE(aesni_skciphers));
unregister_algs:
crypto_unregister_algs(aesni_algs, ARRAY_SIZE(aesni_algs));
fpu_exit:
crypto_fpu_exit();
return err;
}
static void __exit aesni_exit(void)
{
aesni_free_simds();
crypto_unregister_aeads(aesni_aead_algs, ARRAY_SIZE(aesni_aead_algs));
crypto_unregister_skciphers(aesni_skciphers,
ARRAY_SIZE(aesni_skciphers));
crypto_unregister_algs(aesni_algs, ARRAY_SIZE(aesni_algs));
crypto_fpu_exit();
}
