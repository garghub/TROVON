static enum flexi_cipher flexi_cipher_type(const char *name)
{
const struct nitrox_cipher *cipher = flexi_cipher_table;
while (cipher->name) {
if (!strcmp(cipher->name, name))
break;
cipher++;
}
return cipher->value;
}
static int flexi_aes_keylen(int keylen)
{
int aes_keylen;
switch (keylen) {
case AES_KEYSIZE_128:
aes_keylen = 1;
break;
case AES_KEYSIZE_192:
aes_keylen = 2;
break;
case AES_KEYSIZE_256:
aes_keylen = 3;
break;
default:
aes_keylen = -EINVAL;
break;
}
return aes_keylen;
}
static int nitrox_skcipher_init(struct crypto_skcipher *tfm)
{
struct nitrox_crypto_ctx *nctx = crypto_skcipher_ctx(tfm);
void *fctx;
nctx->ndev = nitrox_get_first_device();
if (!nctx->ndev)
return -ENODEV;
fctx = crypto_alloc_context(nctx->ndev);
if (!fctx) {
nitrox_put_device(nctx->ndev);
return -ENOMEM;
}
nctx->u.ctx_handle = (uintptr_t)fctx;
crypto_skcipher_set_reqsize(tfm, crypto_skcipher_reqsize(tfm) +
sizeof(struct nitrox_kcrypt_request));
return 0;
}
static void nitrox_skcipher_exit(struct crypto_skcipher *tfm)
{
struct nitrox_crypto_ctx *nctx = crypto_skcipher_ctx(tfm);
if (nctx->u.ctx_handle) {
struct flexi_crypto_context *fctx = nctx->u.fctx;
memset(&fctx->crypto, 0, sizeof(struct crypto_keys));
memset(&fctx->auth, 0, sizeof(struct auth_keys));
crypto_free_context((void *)fctx);
}
nitrox_put_device(nctx->ndev);
nctx->u.ctx_handle = 0;
nctx->ndev = NULL;
}
static inline int nitrox_skcipher_setkey(struct crypto_skcipher *cipher,
int aes_keylen, const u8 *key,
unsigned int keylen)
{
struct crypto_tfm *tfm = crypto_skcipher_tfm(cipher);
struct nitrox_crypto_ctx *nctx = crypto_tfm_ctx(tfm);
struct flexi_crypto_context *fctx;
enum flexi_cipher cipher_type;
const char *name;
name = crypto_tfm_alg_name(tfm);
cipher_type = flexi_cipher_type(name);
if (unlikely(cipher_type == CIPHER_INVALID)) {
pr_err("unsupported cipher: %s\n", name);
return -EINVAL;
}
fctx = nctx->u.fctx;
fctx->flags = 0;
fctx->w0.cipher_type = cipher_type;
fctx->w0.aes_keylen = aes_keylen;
fctx->w0.iv_source = IV_FROM_DPTR;
fctx->flags = cpu_to_be64(*(u64 *)&fctx->w0);
memcpy(fctx->crypto.u.key, key, keylen);
return 0;
}
static int nitrox_aes_setkey(struct crypto_skcipher *cipher, const u8 *key,
unsigned int keylen)
{
int aes_keylen;
aes_keylen = flexi_aes_keylen(keylen);
if (aes_keylen < 0) {
crypto_skcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
return nitrox_skcipher_setkey(cipher, aes_keylen, key, keylen);
}
static void nitrox_skcipher_callback(struct skcipher_request *skreq,
int err)
{
if (err) {
pr_err_ratelimited("request failed status 0x%0x\n", err);
err = -EINVAL;
}
skcipher_request_complete(skreq, err);
}
static int nitrox_skcipher_crypt(struct skcipher_request *skreq, bool enc)
{
struct crypto_skcipher *cipher = crypto_skcipher_reqtfm(skreq);
struct nitrox_crypto_ctx *nctx = crypto_skcipher_ctx(cipher);
struct nitrox_kcrypt_request *nkreq = skcipher_request_ctx(skreq);
int ivsize = crypto_skcipher_ivsize(cipher);
struct se_crypto_request *creq;
creq = &nkreq->creq;
creq->flags = skreq->base.flags;
creq->gfp = (skreq->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP) ?
GFP_KERNEL : GFP_ATOMIC;
creq->ctrl.value = 0;
creq->opcode = FLEXI_CRYPTO_ENCRYPT_HMAC;
creq->ctrl.s.arg = (enc ? ENCRYPT : DECRYPT);
creq->gph.param0 = cpu_to_be16(skreq->cryptlen);
creq->gph.param1 = 0;
creq->gph.param2 = cpu_to_be16(ivsize);
creq->gph.param3 = 0;
creq->ctx_handle = nctx->u.ctx_handle;
creq->ctrl.s.ctxl = sizeof(struct flexi_crypto_context);
memcpy(creq->iv, skreq->iv, ivsize);
creq->ivsize = ivsize;
creq->src = skreq->src;
creq->dst = skreq->dst;
nkreq->nctx = nctx;
nkreq->skreq = skreq;
return nitrox_process_se_request(nctx->ndev, creq,
nitrox_skcipher_callback, skreq);
}
static int nitrox_aes_encrypt(struct skcipher_request *skreq)
{
return nitrox_skcipher_crypt(skreq, true);
}
static int nitrox_aes_decrypt(struct skcipher_request *skreq)
{
return nitrox_skcipher_crypt(skreq, false);
}
static int nitrox_3des_setkey(struct crypto_skcipher *cipher,
const u8 *key, unsigned int keylen)
{
if (keylen != DES3_EDE_KEY_SIZE) {
crypto_skcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
return nitrox_skcipher_setkey(cipher, 0, key, keylen);
}
static int nitrox_3des_encrypt(struct skcipher_request *skreq)
{
return nitrox_skcipher_crypt(skreq, true);
}
static int nitrox_3des_decrypt(struct skcipher_request *skreq)
{
return nitrox_skcipher_crypt(skreq, false);
}
static int nitrox_aes_xts_setkey(struct crypto_skcipher *cipher,
const u8 *key, unsigned int keylen)
{
struct crypto_tfm *tfm = crypto_skcipher_tfm(cipher);
struct nitrox_crypto_ctx *nctx = crypto_tfm_ctx(tfm);
struct flexi_crypto_context *fctx;
int aes_keylen, ret;
ret = xts_check_key(tfm, key, keylen);
if (ret)
return ret;
keylen /= 2;
aes_keylen = flexi_aes_keylen(keylen);
if (aes_keylen < 0) {
crypto_skcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
fctx = nctx->u.fctx;
memcpy(fctx->auth.u.key2, (key + keylen), keylen);
return nitrox_skcipher_setkey(cipher, aes_keylen, key, keylen);
}
static int nitrox_aes_ctr_rfc3686_setkey(struct crypto_skcipher *cipher,
const u8 *key, unsigned int keylen)
{
struct crypto_tfm *tfm = crypto_skcipher_tfm(cipher);
struct nitrox_crypto_ctx *nctx = crypto_tfm_ctx(tfm);
struct flexi_crypto_context *fctx;
int aes_keylen;
if (keylen < CTR_RFC3686_NONCE_SIZE)
return -EINVAL;
fctx = nctx->u.fctx;
memcpy(fctx->crypto.iv, key + (keylen - CTR_RFC3686_NONCE_SIZE),
CTR_RFC3686_NONCE_SIZE);
keylen -= CTR_RFC3686_NONCE_SIZE;
aes_keylen = flexi_aes_keylen(keylen);
if (aes_keylen < 0) {
crypto_skcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
return nitrox_skcipher_setkey(cipher, aes_keylen, key, keylen);
}
int nitrox_crypto_register(void)
{
return crypto_register_skciphers(nitrox_skciphers,
ARRAY_SIZE(nitrox_skciphers));
}
void nitrox_crypto_unregister(void)
{
crypto_unregister_skciphers(nitrox_skciphers,
ARRAY_SIZE(nitrox_skciphers));
}
