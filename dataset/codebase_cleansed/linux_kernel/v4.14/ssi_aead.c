static inline bool valid_assoclen(struct aead_request *req)
{
return ((req->assoclen == 16) || (req->assoclen == 20));
}
static void ssi_aead_exit(struct crypto_aead *tfm)
{
struct device *dev = NULL;
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
SSI_LOG_DEBUG("Clearing context @%p for %s\n",
crypto_aead_ctx(tfm), crypto_tfm_alg_name(&tfm->base));
dev = &ctx->drvdata->plat_dev->dev;
if (ctx->enckey) {
dma_free_coherent(dev, AES_MAX_KEY_SIZE, ctx->enckey, ctx->enckey_dma_addr);
SSI_LOG_DEBUG("Freed enckey DMA buffer enckey_dma_addr=%pad\n",
ctx->enckey_dma_addr);
ctx->enckey_dma_addr = 0;
ctx->enckey = NULL;
}
if (ctx->auth_mode == DRV_HASH_XCBC_MAC) {
struct cc_xcbc_s *xcbc = &ctx->auth_state.xcbc;
if (xcbc->xcbc_keys) {
dma_free_coherent(dev, CC_AES_128_BIT_KEY_SIZE * 3,
xcbc->xcbc_keys,
xcbc->xcbc_keys_dma_addr);
}
SSI_LOG_DEBUG("Freed xcbc_keys DMA buffer xcbc_keys_dma_addr=%pad\n",
xcbc->xcbc_keys_dma_addr);
xcbc->xcbc_keys_dma_addr = 0;
xcbc->xcbc_keys = NULL;
} else if (ctx->auth_mode != DRV_HASH_NULL) {
struct cc_hmac_s *hmac = &ctx->auth_state.hmac;
if (hmac->ipad_opad) {
dma_free_coherent(dev, 2 * MAX_HMAC_DIGEST_SIZE,
hmac->ipad_opad,
hmac->ipad_opad_dma_addr);
SSI_LOG_DEBUG("Freed ipad_opad DMA buffer ipad_opad_dma_addr=%pad\n",
hmac->ipad_opad_dma_addr);
hmac->ipad_opad_dma_addr = 0;
hmac->ipad_opad = NULL;
}
if (hmac->padded_authkey) {
dma_free_coherent(dev, MAX_HMAC_BLOCK_SIZE,
hmac->padded_authkey,
hmac->padded_authkey_dma_addr);
SSI_LOG_DEBUG("Freed padded_authkey DMA buffer padded_authkey_dma_addr=%pad\n",
hmac->padded_authkey_dma_addr);
hmac->padded_authkey_dma_addr = 0;
hmac->padded_authkey = NULL;
}
}
}
static int ssi_aead_init(struct crypto_aead *tfm)
{
struct device *dev;
struct aead_alg *alg = crypto_aead_alg(tfm);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct ssi_crypto_alg *ssi_alg =
container_of(alg, struct ssi_crypto_alg, aead_alg);
SSI_LOG_DEBUG("Initializing context @%p for %s\n", ctx, crypto_tfm_alg_name(&tfm->base));
ctx->cipher_mode = ssi_alg->cipher_mode;
ctx->flow_mode = ssi_alg->flow_mode;
ctx->auth_mode = ssi_alg->auth_mode;
ctx->drvdata = ssi_alg->drvdata;
dev = &ctx->drvdata->plat_dev->dev;
crypto_aead_set_reqsize(tfm, sizeof(struct aead_req_ctx));
ctx->enckey = dma_alloc_coherent(dev, AES_MAX_KEY_SIZE,
&ctx->enckey_dma_addr, GFP_KERNEL);
if (!ctx->enckey) {
SSI_LOG_ERR("Failed allocating key buffer\n");
goto init_failed;
}
SSI_LOG_DEBUG("Allocated enckey buffer in context ctx->enckey=@%p\n", ctx->enckey);
if (ctx->auth_mode == DRV_HASH_XCBC_MAC) {
struct cc_xcbc_s *xcbc = &ctx->auth_state.xcbc;
const unsigned int key_size = CC_AES_128_BIT_KEY_SIZE * 3;
xcbc->xcbc_keys = dma_alloc_coherent(dev, key_size,
&xcbc->xcbc_keys_dma_addr,
GFP_KERNEL);
if (!xcbc->xcbc_keys) {
SSI_LOG_ERR("Failed allocating buffer for XCBC keys\n");
goto init_failed;
}
} else if (ctx->auth_mode != DRV_HASH_NULL) {
struct cc_hmac_s *hmac = &ctx->auth_state.hmac;
const unsigned int digest_size = 2 * MAX_HMAC_DIGEST_SIZE;
dma_addr_t *pkey_dma = &hmac->padded_authkey_dma_addr;
hmac->ipad_opad = dma_alloc_coherent(dev, digest_size,
&hmac->ipad_opad_dma_addr,
GFP_KERNEL);
if (!hmac->ipad_opad) {
SSI_LOG_ERR("Failed allocating IPAD/OPAD buffer\n");
goto init_failed;
}
SSI_LOG_DEBUG("Allocated authkey buffer in context ctx->authkey=@%p\n",
hmac->ipad_opad);
hmac->padded_authkey = dma_alloc_coherent(dev,
MAX_HMAC_BLOCK_SIZE,
pkey_dma,
GFP_KERNEL);
if (!hmac->padded_authkey) {
SSI_LOG_ERR("failed to allocate padded_authkey\n");
goto init_failed;
}
} else {
ctx->auth_state.hmac.ipad_opad = NULL;
ctx->auth_state.hmac.padded_authkey = NULL;
}
return 0;
init_failed:
ssi_aead_exit(tfm);
return -ENOMEM;
}
static void ssi_aead_complete(struct device *dev, void *ssi_req, void __iomem *cc_base)
{
struct aead_request *areq = (struct aead_request *)ssi_req;
struct aead_req_ctx *areq_ctx = aead_request_ctx(areq);
struct crypto_aead *tfm = crypto_aead_reqtfm(ssi_req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
int err = 0;
ssi_buffer_mgr_unmap_aead_request(dev, areq);
areq->iv = areq_ctx->backup_iv;
if (areq_ctx->gen_ctx.op_type == DRV_CRYPTO_DIRECTION_DECRYPT) {
if (memcmp(areq_ctx->mac_buf, areq_ctx->icv_virt_addr,
ctx->authsize) != 0) {
SSI_LOG_DEBUG("Payload authentication failure, "
"(auth-size=%d, cipher=%d).\n",
ctx->authsize, ctx->cipher_mode);
ssi_buffer_mgr_zero_sgl(areq->dst, areq_ctx->cryptlen);
err = -EBADMSG;
}
} else {
if (unlikely(areq_ctx->is_icv_fragmented))
ssi_buffer_mgr_copy_scatterlist_portion(
areq_ctx->mac_buf, areq_ctx->dst_sgl, areq->cryptlen + areq_ctx->dst_offset,
areq->cryptlen + areq_ctx->dst_offset + ctx->authsize, SSI_SG_FROM_BUF);
if (areq_ctx->backup_giv) {
if (ctx->cipher_mode == DRV_CIPHER_CTR)
memcpy(areq_ctx->backup_giv, areq_ctx->ctr_iv + CTR_RFC3686_NONCE_SIZE, CTR_RFC3686_IV_SIZE);
else if (ctx->cipher_mode == DRV_CIPHER_CCM)
memcpy(areq_ctx->backup_giv, areq_ctx->ctr_iv + CCM_BLOCK_IV_OFFSET, CCM_BLOCK_IV_SIZE);
}
}
aead_request_complete(areq, err);
}
static int xcbc_setkey(struct cc_hw_desc *desc, struct ssi_aead_ctx *ctx)
{
hw_desc_init(&desc[0]);
set_din_type(&desc[0], DMA_DLLI,
ctx->auth_state.xcbc.xcbc_keys_dma_addr, ctx->auth_keylen,
NS_BIT);
set_cipher_mode(&desc[0], DRV_CIPHER_ECB);
set_cipher_config0(&desc[0], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_key_size_aes(&desc[0], ctx->auth_keylen);
set_flow_mode(&desc[0], S_DIN_to_AES);
set_setup_mode(&desc[0], SETUP_LOAD_KEY0);
hw_desc_init(&desc[1]);
set_din_const(&desc[1], 0x01010101, CC_AES_128_BIT_KEY_SIZE);
set_flow_mode(&desc[1], DIN_AES_DOUT);
set_dout_dlli(&desc[1], ctx->auth_state.xcbc.xcbc_keys_dma_addr,
AES_KEYSIZE_128, NS_BIT, 0);
hw_desc_init(&desc[2]);
set_din_const(&desc[2], 0x02020202, CC_AES_128_BIT_KEY_SIZE);
set_flow_mode(&desc[2], DIN_AES_DOUT);
set_dout_dlli(&desc[2], (ctx->auth_state.xcbc.xcbc_keys_dma_addr
+ AES_KEYSIZE_128),
AES_KEYSIZE_128, NS_BIT, 0);
hw_desc_init(&desc[3]);
set_din_const(&desc[3], 0x03030303, CC_AES_128_BIT_KEY_SIZE);
set_flow_mode(&desc[3], DIN_AES_DOUT);
set_dout_dlli(&desc[3], (ctx->auth_state.xcbc.xcbc_keys_dma_addr
+ 2 * AES_KEYSIZE_128),
AES_KEYSIZE_128, NS_BIT, 0);
return 4;
}
static int hmac_setkey(struct cc_hw_desc *desc, struct ssi_aead_ctx *ctx)
{
unsigned int hmac_pad_const[2] = { HMAC_IPAD_CONST, HMAC_OPAD_CONST };
unsigned int digest_ofs = 0;
unsigned int hash_mode = (ctx->auth_mode == DRV_HASH_SHA1) ?
DRV_HASH_HW_SHA1 : DRV_HASH_HW_SHA256;
unsigned int digest_size = (ctx->auth_mode == DRV_HASH_SHA1) ?
CC_SHA1_DIGEST_SIZE : CC_SHA256_DIGEST_SIZE;
struct cc_hmac_s *hmac = &ctx->auth_state.hmac;
int idx = 0;
int i;
for (i = 0; i < 2; i++) {
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hash_mode);
set_din_sram(&desc[idx],
ssi_ahash_get_larval_digest_sram_addr(
ctx->drvdata, ctx->auth_mode),
digest_size);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hash_mode);
set_din_const(&desc[idx], 0, HASH_LEN_SIZE);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_xor_val(&desc[idx], hmac_pad_const[i]);
set_cipher_mode(&desc[idx], hash_mode);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
hmac->padded_authkey_dma_addr,
SHA256_BLOCK_SIZE, NS_BIT);
set_cipher_mode(&desc[idx], hash_mode);
set_xor_active(&desc[idx]);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hash_mode);
set_dout_dlli(&desc[idx],
(hmac->ipad_opad_dma_addr + digest_ofs),
digest_size, NS_BIT, 0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_cipher_config1(&desc[idx], HASH_PADDING_DISABLED);
idx++;
digest_ofs += digest_size;
}
return idx;
}
static int validate_keys_sizes(struct ssi_aead_ctx *ctx)
{
SSI_LOG_DEBUG("enc_keylen=%u authkeylen=%u\n",
ctx->enc_keylen, ctx->auth_keylen);
switch (ctx->auth_mode) {
case DRV_HASH_SHA1:
case DRV_HASH_SHA256:
break;
case DRV_HASH_XCBC_MAC:
if ((ctx->auth_keylen != AES_KEYSIZE_128) &&
(ctx->auth_keylen != AES_KEYSIZE_192) &&
(ctx->auth_keylen != AES_KEYSIZE_256))
return -ENOTSUPP;
break;
case DRV_HASH_NULL:
if (ctx->auth_keylen > 0)
return -EINVAL;
break;
default:
SSI_LOG_ERR("Invalid auth_mode=%d\n", ctx->auth_mode);
return -EINVAL;
}
if (unlikely(ctx->flow_mode == S_DIN_to_DES)) {
if (ctx->enc_keylen != DES3_EDE_KEY_SIZE) {
SSI_LOG_ERR("Invalid cipher(3DES) key size: %u\n",
ctx->enc_keylen);
return -EINVAL;
}
} else {
if ((ctx->enc_keylen != AES_KEYSIZE_128) &&
(ctx->enc_keylen != AES_KEYSIZE_192) &&
(ctx->enc_keylen != AES_KEYSIZE_256)) {
SSI_LOG_ERR("Invalid cipher(AES) key size: %u\n",
ctx->enc_keylen);
return -EINVAL;
}
}
return 0;
}
static int
ssi_get_plain_hmac_key(struct crypto_aead *tfm, const u8 *key, unsigned int keylen)
{
dma_addr_t key_dma_addr = 0;
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct device *dev = &ctx->drvdata->plat_dev->dev;
u32 larval_addr = ssi_ahash_get_larval_digest_sram_addr(
ctx->drvdata, ctx->auth_mode);
struct ssi_crypto_req ssi_req = {};
unsigned int blocksize;
unsigned int digestsize;
unsigned int hashmode;
unsigned int idx = 0;
int rc = 0;
struct cc_hw_desc desc[MAX_AEAD_SETKEY_SEQ];
dma_addr_t padded_authkey_dma_addr =
ctx->auth_state.hmac.padded_authkey_dma_addr;
switch (ctx->auth_mode) {
case DRV_HASH_SHA1:
blocksize = SHA1_BLOCK_SIZE;
digestsize = SHA1_DIGEST_SIZE;
hashmode = DRV_HASH_HW_SHA1;
break;
case DRV_HASH_SHA256:
default:
blocksize = SHA256_BLOCK_SIZE;
digestsize = SHA256_DIGEST_SIZE;
hashmode = DRV_HASH_HW_SHA256;
}
if (likely(keylen != 0)) {
key_dma_addr = dma_map_single(dev, (void *)key, keylen, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(dev, key_dma_addr))) {
SSI_LOG_ERR("Mapping key va=0x%p len=%u for"
" DMA failed\n", key, keylen);
return -ENOMEM;
}
if (keylen > blocksize) {
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hashmode);
set_din_sram(&desc[idx], larval_addr, digestsize);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hashmode);
set_din_const(&desc[idx], 0, HASH_LEN_SIZE);
set_cipher_config1(&desc[idx], HASH_PADDING_ENABLED);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
key_dma_addr, keylen, NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hashmode);
set_dout_dlli(&desc[idx], padded_authkey_dma_addr,
digestsize, NS_BIT, 0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_cipher_config1(&desc[idx], HASH_PADDING_DISABLED);
set_cipher_config0(&desc[idx],
HASH_DIGEST_RESULT_LITTLE_ENDIAN);
idx++;
hw_desc_init(&desc[idx]);
set_din_const(&desc[idx], 0, (blocksize - digestsize));
set_flow_mode(&desc[idx], BYPASS);
set_dout_dlli(&desc[idx], (padded_authkey_dma_addr +
digestsize), (blocksize - digestsize),
NS_BIT, 0);
idx++;
} else {
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr,
keylen, NS_BIT);
set_flow_mode(&desc[idx], BYPASS);
set_dout_dlli(&desc[idx], padded_authkey_dma_addr,
keylen, NS_BIT, 0);
idx++;
if ((blocksize - keylen) != 0) {
hw_desc_init(&desc[idx]);
set_din_const(&desc[idx], 0,
(blocksize - keylen));
set_flow_mode(&desc[idx], BYPASS);
set_dout_dlli(&desc[idx],
(padded_authkey_dma_addr +
keylen),
(blocksize - keylen), NS_BIT, 0);
idx++;
}
}
} else {
hw_desc_init(&desc[idx]);
set_din_const(&desc[idx], 0, (blocksize - keylen));
set_flow_mode(&desc[idx], BYPASS);
set_dout_dlli(&desc[idx], padded_authkey_dma_addr,
blocksize, NS_BIT, 0);
idx++;
}
rc = send_request(ctx->drvdata, &ssi_req, desc, idx, 0);
if (unlikely(rc != 0))
SSI_LOG_ERR("send_request() failed (rc=%d)\n", rc);
if (likely(key_dma_addr != 0))
dma_unmap_single(dev, key_dma_addr, keylen, DMA_TO_DEVICE);
return rc;
}
static int
ssi_aead_setkey(struct crypto_aead *tfm, const u8 *key, unsigned int keylen)
{
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct rtattr *rta = (struct rtattr *)key;
struct ssi_crypto_req ssi_req = {};
struct crypto_authenc_key_param *param;
struct cc_hw_desc desc[MAX_AEAD_SETKEY_SEQ];
int seq_len = 0, rc = -EINVAL;
SSI_LOG_DEBUG("Setting key in context @%p for %s. key=%p keylen=%u\n",
ctx, crypto_tfm_alg_name(crypto_aead_tfm(tfm)),
key, keylen);
if (ctx->auth_mode != DRV_HASH_NULL) {
if (!RTA_OK(rta, keylen))
goto badkey;
if (rta->rta_type != CRYPTO_AUTHENC_KEYA_PARAM)
goto badkey;
if (RTA_PAYLOAD(rta) < sizeof(*param))
goto badkey;
param = RTA_DATA(rta);
ctx->enc_keylen = be32_to_cpu(param->enckeylen);
key += RTA_ALIGN(rta->rta_len);
keylen -= RTA_ALIGN(rta->rta_len);
if (keylen < ctx->enc_keylen)
goto badkey;
ctx->auth_keylen = keylen - ctx->enc_keylen;
if (ctx->cipher_mode == DRV_CIPHER_CTR) {
if (ctx->enc_keylen <
(AES_MIN_KEY_SIZE + CTR_RFC3686_NONCE_SIZE))
goto badkey;
memcpy(ctx->ctr_nonce, key + ctx->auth_keylen + ctx->enc_keylen -
CTR_RFC3686_NONCE_SIZE, CTR_RFC3686_NONCE_SIZE);
ctx->enc_keylen -= CTR_RFC3686_NONCE_SIZE;
}
} else {
ctx->enc_keylen = keylen;
ctx->auth_keylen = 0;
}
rc = validate_keys_sizes(ctx);
if (unlikely(rc != 0))
goto badkey;
memcpy(ctx->enckey, key + ctx->auth_keylen, ctx->enc_keylen);
if (ctx->enc_keylen == 24)
memset(ctx->enckey + 24, 0, CC_AES_KEY_SIZE_MAX - 24);
if (ctx->auth_mode == DRV_HASH_XCBC_MAC) {
memcpy(ctx->auth_state.xcbc.xcbc_keys, key, ctx->auth_keylen);
} else if (ctx->auth_mode != DRV_HASH_NULL) {
rc = ssi_get_plain_hmac_key(tfm, key, ctx->auth_keylen);
if (rc != 0)
goto badkey;
}
switch (ctx->auth_mode) {
case DRV_HASH_SHA1:
case DRV_HASH_SHA256:
seq_len = hmac_setkey(desc, ctx);
break;
case DRV_HASH_XCBC_MAC:
seq_len = xcbc_setkey(desc, ctx);
break;
case DRV_HASH_NULL:
break;
default:
SSI_LOG_ERR("Unsupported authenc (%d)\n", ctx->auth_mode);
rc = -ENOTSUPP;
goto badkey;
}
if (seq_len > 0) {
rc = send_request(ctx->drvdata, &ssi_req, desc, seq_len, 0);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("send_request() failed (rc=%d)\n", rc);
goto setkey_error;
}
}
return rc;
badkey:
crypto_aead_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
setkey_error:
return rc;
}
static int ssi_rfc4309_ccm_setkey(struct crypto_aead *tfm, const u8 *key, unsigned int keylen)
{
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
int rc = 0;
if (keylen < 3)
return -EINVAL;
keylen -= 3;
memcpy(ctx->ctr_nonce, key + keylen, 3);
rc = ssi_aead_setkey(tfm, key, keylen);
return rc;
}
static int ssi_aead_setauthsize(
struct crypto_aead *authenc,
unsigned int authsize)
{
struct ssi_aead_ctx *ctx = crypto_aead_ctx(authenc);
if ((authsize == 0) ||
(authsize > crypto_aead_maxauthsize(authenc))) {
return -ENOTSUPP;
}
ctx->authsize = authsize;
SSI_LOG_DEBUG("authlen=%d\n", ctx->authsize);
return 0;
}
static int ssi_rfc4309_ccm_setauthsize(struct crypto_aead *authenc,
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
return ssi_aead_setauthsize(authenc, authsize);
}
static int ssi_ccm_setauthsize(struct crypto_aead *authenc,
unsigned int authsize)
{
switch (authsize) {
case 4:
case 6:
case 8:
case 10:
case 12:
case 14:
case 16:
break;
default:
return -EINVAL;
}
return ssi_aead_setauthsize(authenc, authsize);
}
static inline void
ssi_aead_create_assoc_desc(
struct aead_request *areq,
unsigned int flow_mode,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(areq);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *areq_ctx = aead_request_ctx(areq);
enum ssi_req_dma_buf_type assoc_dma_type = areq_ctx->assoc_buff_type;
unsigned int idx = *seq_size;
switch (assoc_dma_type) {
case SSI_DMA_BUF_DLLI:
SSI_LOG_DEBUG("ASSOC buffer type DLLI\n");
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, sg_dma_address(areq->src),
areq->assoclen, NS_BIT); set_flow_mode(&desc[idx],
flow_mode);
if ((ctx->auth_mode == DRV_HASH_XCBC_MAC) &&
(areq_ctx->cryptlen > 0))
set_din_not_last_indication(&desc[idx]);
break;
case SSI_DMA_BUF_MLLI:
SSI_LOG_DEBUG("ASSOC buffer type MLLI\n");
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_MLLI, areq_ctx->assoc.sram_addr,
areq_ctx->assoc.mlli_nents, NS_BIT);
set_flow_mode(&desc[idx], flow_mode);
if ((ctx->auth_mode == DRV_HASH_XCBC_MAC) &&
(areq_ctx->cryptlen > 0))
set_din_not_last_indication(&desc[idx]);
break;
case SSI_DMA_BUF_NULL:
default:
SSI_LOG_ERR("Invalid ASSOC buffer type\n");
}
*seq_size = (++idx);
}
static inline void
ssi_aead_process_authenc_data_desc(
struct aead_request *areq,
unsigned int flow_mode,
struct cc_hw_desc desc[],
unsigned int *seq_size,
int direct)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(areq);
enum ssi_req_dma_buf_type data_dma_type = areq_ctx->data_buff_type;
unsigned int idx = *seq_size;
switch (data_dma_type) {
case SSI_DMA_BUF_DLLI:
{
struct scatterlist *cipher =
(direct == DRV_CRYPTO_DIRECTION_ENCRYPT) ?
areq_ctx->dst_sgl : areq_ctx->src_sgl;
unsigned int offset =
(direct == DRV_CRYPTO_DIRECTION_ENCRYPT) ?
areq_ctx->dst_offset : areq_ctx->src_offset;
SSI_LOG_DEBUG("AUTHENC: SRC/DST buffer type DLLI\n");
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
(sg_dma_address(cipher) + offset),
areq_ctx->cryptlen, NS_BIT);
set_flow_mode(&desc[idx], flow_mode);
break;
}
case SSI_DMA_BUF_MLLI:
{
ssi_sram_addr_t mlli_addr = areq_ctx->assoc.sram_addr;
u32 mlli_nents = areq_ctx->assoc.mlli_nents;
if (likely(areq_ctx->is_single_pass)) {
if (direct == DRV_CRYPTO_DIRECTION_ENCRYPT) {
mlli_addr = areq_ctx->dst.sram_addr;
mlli_nents = areq_ctx->dst.mlli_nents;
} else {
mlli_addr = areq_ctx->src.sram_addr;
mlli_nents = areq_ctx->src.mlli_nents;
}
}
SSI_LOG_DEBUG("AUTHENC: SRC/DST buffer type MLLI\n");
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_MLLI, mlli_addr, mlli_nents,
NS_BIT);
set_flow_mode(&desc[idx], flow_mode);
break;
}
case SSI_DMA_BUF_NULL:
default:
SSI_LOG_ERR("AUTHENC: Invalid SRC/DST buffer type\n");
}
*seq_size = (++idx);
}
static inline void
ssi_aead_process_cipher_data_desc(
struct aead_request *areq,
unsigned int flow_mode,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
unsigned int idx = *seq_size;
struct aead_req_ctx *areq_ctx = aead_request_ctx(areq);
enum ssi_req_dma_buf_type data_dma_type = areq_ctx->data_buff_type;
if (areq_ctx->cryptlen == 0)
return;
switch (data_dma_type) {
case SSI_DMA_BUF_DLLI:
SSI_LOG_DEBUG("CIPHER: SRC/DST buffer type DLLI\n");
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
(sg_dma_address(areq_ctx->src_sgl) +
areq_ctx->src_offset), areq_ctx->cryptlen, NS_BIT);
set_dout_dlli(&desc[idx],
(sg_dma_address(areq_ctx->dst_sgl) +
areq_ctx->dst_offset),
areq_ctx->cryptlen, NS_BIT, 0);
set_flow_mode(&desc[idx], flow_mode);
break;
case SSI_DMA_BUF_MLLI:
SSI_LOG_DEBUG("CIPHER: SRC/DST buffer type MLLI\n");
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_MLLI, areq_ctx->src.sram_addr,
areq_ctx->src.mlli_nents, NS_BIT);
set_dout_mlli(&desc[idx], areq_ctx->dst.sram_addr,
areq_ctx->dst.mlli_nents, NS_BIT, 0);
set_flow_mode(&desc[idx], flow_mode);
break;
case SSI_DMA_BUF_NULL:
default:
SSI_LOG_ERR("CIPHER: Invalid SRC/DST buffer type\n");
}
*seq_size = (++idx);
}
static inline void ssi_aead_process_digest_result_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
unsigned int idx = *seq_size;
unsigned int hash_mode = (ctx->auth_mode == DRV_HASH_SHA1) ?
DRV_HASH_HW_SHA1 : DRV_HASH_HW_SHA256;
int direct = req_ctx->gen_ctx.op_type;
if (direct == DRV_CRYPTO_DIRECTION_ENCRYPT) {
hw_desc_init(&desc[idx]);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_dout_dlli(&desc[idx], req_ctx->icv_dma_addr, ctx->authsize,
NS_BIT, 1);
set_queue_last_ind(&desc[idx]);
if (ctx->auth_mode == DRV_HASH_XCBC_MAC) {
set_aes_not_hash_mode(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_XCBC_MAC);
} else {
set_cipher_config0(&desc[idx],
HASH_DIGEST_RESULT_LITTLE_ENDIAN);
set_cipher_mode(&desc[idx], hash_mode);
}
} else {
hw_desc_init(&desc[idx]);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_dout_dlli(&desc[idx], req_ctx->mac_buf_dma_addr,
ctx->authsize, NS_BIT, 1);
set_queue_last_ind(&desc[idx]);
set_cipher_config0(&desc[idx],
HASH_DIGEST_RESULT_LITTLE_ENDIAN);
set_cipher_config1(&desc[idx], HASH_PADDING_DISABLED);
if (ctx->auth_mode == DRV_HASH_XCBC_MAC) {
set_cipher_mode(&desc[idx], DRV_CIPHER_XCBC_MAC);
set_aes_not_hash_mode(&desc[idx]);
} else {
set_cipher_mode(&desc[idx], hash_mode);
}
}
*seq_size = (++idx);
}
static inline void ssi_aead_setup_cipher_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
unsigned int hw_iv_size = req_ctx->hw_iv_size;
unsigned int idx = *seq_size;
int direct = req_ctx->gen_ctx.op_type;
hw_desc_init(&desc[idx]);
set_cipher_config0(&desc[idx], direct);
set_flow_mode(&desc[idx], ctx->flow_mode);
set_din_type(&desc[idx], DMA_DLLI, req_ctx->gen_ctx.iv_dma_addr,
hw_iv_size, NS_BIT);
if (ctx->cipher_mode == DRV_CIPHER_CTR)
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
else
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
set_cipher_mode(&desc[idx], ctx->cipher_mode);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_config0(&desc[idx], direct);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_flow_mode(&desc[idx], ctx->flow_mode);
if (ctx->flow_mode == S_DIN_to_AES) {
set_din_type(&desc[idx], DMA_DLLI, ctx->enckey_dma_addr,
((ctx->enc_keylen == 24) ? CC_AES_KEY_SIZE_MAX :
ctx->enc_keylen), NS_BIT);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
} else {
set_din_type(&desc[idx], DMA_DLLI, ctx->enckey_dma_addr,
ctx->enc_keylen, NS_BIT);
set_key_size_des(&desc[idx], ctx->enc_keylen);
}
set_cipher_mode(&desc[idx], ctx->cipher_mode);
idx++;
*seq_size = idx;
}
static inline void ssi_aead_process_cipher(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size,
unsigned int data_flow_mode)
{
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
int direct = req_ctx->gen_ctx.op_type;
unsigned int idx = *seq_size;
if (req_ctx->cryptlen == 0)
return;
ssi_aead_setup_cipher_desc(req, desc, &idx);
ssi_aead_process_cipher_data_desc(req, data_flow_mode, desc, &idx);
if (direct == DRV_CRYPTO_DIRECTION_ENCRYPT) {
hw_desc_init(&desc[idx]);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_no_dma(&desc[idx], 0, 0, 1);
idx++;
}
*seq_size = idx;
}
static inline void ssi_aead_hmac_setup_digest_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
unsigned int hash_mode = (ctx->auth_mode == DRV_HASH_SHA1) ?
DRV_HASH_HW_SHA1 : DRV_HASH_HW_SHA256;
unsigned int digest_size = (ctx->auth_mode == DRV_HASH_SHA1) ?
CC_SHA1_DIGEST_SIZE : CC_SHA256_DIGEST_SIZE;
unsigned int idx = *seq_size;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hash_mode);
set_din_type(&desc[idx], DMA_DLLI,
ctx->auth_state.hmac.ipad_opad_dma_addr, digest_size,
NS_BIT);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hash_mode);
set_din_sram(&desc[idx],
ssi_ahash_get_initial_digest_len_sram_addr(ctx->drvdata,
hash_mode),
HASH_LEN_SIZE);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
*seq_size = idx;
}
static inline void ssi_aead_xcbc_setup_digest_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
unsigned int idx = *seq_size;
hw_desc_init(&desc[idx]);
set_din_const(&desc[idx], 0, CC_AES_BLOCK_SIZE);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
set_cipher_mode(&desc[idx], DRV_CIPHER_XCBC_MAC);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_key_size_aes(&desc[idx], CC_AES_128_BIT_KEY_SIZE);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
ctx->auth_state.xcbc.xcbc_keys_dma_addr,
AES_KEYSIZE_128, NS_BIT);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_cipher_mode(&desc[idx], DRV_CIPHER_XCBC_MAC);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_key_size_aes(&desc[idx], CC_AES_128_BIT_KEY_SIZE);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
(ctx->auth_state.xcbc.xcbc_keys_dma_addr +
AES_KEYSIZE_128), AES_KEYSIZE_128, NS_BIT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_cipher_mode(&desc[idx], DRV_CIPHER_XCBC_MAC);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_key_size_aes(&desc[idx], CC_AES_128_BIT_KEY_SIZE);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
(ctx->auth_state.xcbc.xcbc_keys_dma_addr +
2 * AES_KEYSIZE_128), AES_KEYSIZE_128, NS_BIT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE2);
set_cipher_mode(&desc[idx], DRV_CIPHER_XCBC_MAC);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_key_size_aes(&desc[idx], CC_AES_128_BIT_KEY_SIZE);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
idx++;
*seq_size = idx;
}
static inline void ssi_aead_process_digest_header_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
unsigned int idx = *seq_size;
if (req->assoclen > 0)
ssi_aead_create_assoc_desc(req, DIN_HASH, desc, &idx);
*seq_size = idx;
}
static inline void ssi_aead_process_digest_scheme_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct ssi_aead_handle *aead_handle = ctx->drvdata->aead_handle;
unsigned int hash_mode = (ctx->auth_mode == DRV_HASH_SHA1) ?
DRV_HASH_HW_SHA1 : DRV_HASH_HW_SHA256;
unsigned int digest_size = (ctx->auth_mode == DRV_HASH_SHA1) ?
CC_SHA1_DIGEST_SIZE : CC_SHA256_DIGEST_SIZE;
unsigned int idx = *seq_size;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hash_mode);
set_dout_sram(&desc[idx], aead_handle->sram_workspace_addr,
HASH_LEN_SIZE);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE1);
set_cipher_do(&desc[idx], DO_PAD);
idx++;
hw_desc_init(&desc[idx]);
set_dout_sram(&desc[idx], aead_handle->sram_workspace_addr,
digest_size);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_cipher_config0(&desc[idx], HASH_DIGEST_RESULT_LITTLE_ENDIAN);
set_cipher_mode(&desc[idx], hash_mode);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hash_mode);
set_din_type(&desc[idx], DMA_DLLI,
(ctx->auth_state.hmac.ipad_opad_dma_addr + digest_size),
digest_size, NS_BIT);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hash_mode);
set_din_sram(&desc[idx],
ssi_ahash_get_initial_digest_len_sram_addr(ctx->drvdata,
hash_mode),
HASH_LEN_SIZE);
set_cipher_config1(&desc[idx], HASH_PADDING_ENABLED);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_din_sram(&desc[idx], aead_handle->sram_workspace_addr,
digest_size);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
*seq_size = idx;
}
static inline void ssi_aead_load_mlli_to_sram(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
if (unlikely(
(req_ctx->assoc_buff_type == SSI_DMA_BUF_MLLI) ||
(req_ctx->data_buff_type == SSI_DMA_BUF_MLLI) ||
!req_ctx->is_single_pass)) {
SSI_LOG_DEBUG("Copy-to-sram: mlli_dma=%08x, mlli_size=%u\n",
(unsigned int)ctx->drvdata->mlli_sram_addr,
req_ctx->mlli_params.mlli_len);
hw_desc_init(&desc[*seq_size]);
set_din_type(&desc[*seq_size], DMA_DLLI,
req_ctx->mlli_params.mlli_dma_addr,
req_ctx->mlli_params.mlli_len, NS_BIT);
set_dout_sram(&desc[*seq_size],
ctx->drvdata->mlli_sram_addr,
req_ctx->mlli_params.mlli_len);
set_flow_mode(&desc[*seq_size], BYPASS);
(*seq_size)++;
}
}
static inline enum cc_flow_mode ssi_aead_get_data_flow_mode(
enum drv_crypto_direction direct,
enum cc_flow_mode setup_flow_mode,
bool is_single_pass)
{
enum cc_flow_mode data_flow_mode;
if (direct == DRV_CRYPTO_DIRECTION_ENCRYPT) {
if (setup_flow_mode == S_DIN_to_AES)
data_flow_mode = likely(is_single_pass) ?
AES_to_HASH_and_DOUT : DIN_AES_DOUT;
else
data_flow_mode = likely(is_single_pass) ?
DES_to_HASH_and_DOUT : DIN_DES_DOUT;
} else {
if (setup_flow_mode == S_DIN_to_AES)
data_flow_mode = likely(is_single_pass) ?
AES_and_HASH : DIN_AES_DOUT;
else
data_flow_mode = likely(is_single_pass) ?
DES_and_HASH : DIN_DES_DOUT;
}
return data_flow_mode;
}
static inline void ssi_aead_hmac_authenc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
int direct = req_ctx->gen_ctx.op_type;
unsigned int data_flow_mode = ssi_aead_get_data_flow_mode(
direct, ctx->flow_mode, req_ctx->is_single_pass);
if (req_ctx->is_single_pass) {
ssi_aead_hmac_setup_digest_desc(req, desc, seq_size);
ssi_aead_setup_cipher_desc(req, desc, seq_size);
ssi_aead_process_digest_header_desc(req, desc, seq_size);
ssi_aead_process_cipher_data_desc(req, data_flow_mode, desc, seq_size);
ssi_aead_process_digest_scheme_desc(req, desc, seq_size);
ssi_aead_process_digest_result_desc(req, desc, seq_size);
return;
}
if (direct == DRV_CRYPTO_DIRECTION_ENCRYPT) {
ssi_aead_process_cipher(req, desc, seq_size, data_flow_mode);
ssi_aead_hmac_setup_digest_desc(req, desc, seq_size);
ssi_aead_process_authenc_data_desc(req, DIN_HASH, desc, seq_size, direct);
ssi_aead_process_digest_scheme_desc(req, desc, seq_size);
ssi_aead_process_digest_result_desc(req, desc, seq_size);
} else {
ssi_aead_hmac_setup_digest_desc(req, desc, seq_size);
ssi_aead_process_authenc_data_desc(req, DIN_HASH, desc, seq_size, direct);
ssi_aead_process_digest_scheme_desc(req, desc, seq_size);
ssi_aead_process_cipher(req, desc, seq_size, data_flow_mode);
ssi_aead_process_digest_result_desc(req, desc, seq_size);
}
}
static inline void
ssi_aead_xcbc_authenc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
int direct = req_ctx->gen_ctx.op_type;
unsigned int data_flow_mode = ssi_aead_get_data_flow_mode(
direct, ctx->flow_mode, req_ctx->is_single_pass);
if (req_ctx->is_single_pass) {
ssi_aead_xcbc_setup_digest_desc(req, desc, seq_size);
ssi_aead_setup_cipher_desc(req, desc, seq_size);
ssi_aead_process_digest_header_desc(req, desc, seq_size);
ssi_aead_process_cipher_data_desc(req, data_flow_mode, desc, seq_size);
ssi_aead_process_digest_result_desc(req, desc, seq_size);
return;
}
if (direct == DRV_CRYPTO_DIRECTION_ENCRYPT) {
ssi_aead_process_cipher(req, desc, seq_size, data_flow_mode);
ssi_aead_xcbc_setup_digest_desc(req, desc, seq_size);
ssi_aead_process_authenc_data_desc(req, DIN_HASH, desc, seq_size, direct);
ssi_aead_process_digest_result_desc(req, desc, seq_size);
} else {
ssi_aead_xcbc_setup_digest_desc(req, desc, seq_size);
ssi_aead_process_authenc_data_desc(req, DIN_HASH, desc, seq_size, direct);
ssi_aead_process_cipher(req, desc, seq_size, data_flow_mode);
ssi_aead_process_digest_result_desc(req, desc, seq_size);
}
}
static int validate_data_size(struct ssi_aead_ctx *ctx,
enum drv_crypto_direction direct,
struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
unsigned int assoclen = req->assoclen;
unsigned int cipherlen = (direct == DRV_CRYPTO_DIRECTION_DECRYPT) ?
(req->cryptlen - ctx->authsize) : req->cryptlen;
if (unlikely((direct == DRV_CRYPTO_DIRECTION_DECRYPT) &&
(req->cryptlen < ctx->authsize)))
goto data_size_err;
areq_ctx->is_single_pass = true;
switch (ctx->flow_mode) {
case S_DIN_to_AES:
if (unlikely((ctx->cipher_mode == DRV_CIPHER_CBC) &&
!IS_ALIGNED(cipherlen, AES_BLOCK_SIZE)))
goto data_size_err;
if (ctx->cipher_mode == DRV_CIPHER_CCM)
break;
if (ctx->cipher_mode == DRV_CIPHER_GCTR) {
if (areq_ctx->plaintext_authenticate_only)
areq_ctx->is_single_pass = false;
break;
}
if (!IS_ALIGNED(assoclen, sizeof(u32)))
areq_ctx->is_single_pass = false;
if ((ctx->cipher_mode == DRV_CIPHER_CTR) &&
!IS_ALIGNED(cipherlen, sizeof(u32)))
areq_ctx->is_single_pass = false;
break;
case S_DIN_to_DES:
if (unlikely(!IS_ALIGNED(cipherlen, DES_BLOCK_SIZE)))
goto data_size_err;
if (unlikely(!IS_ALIGNED(assoclen, DES_BLOCK_SIZE)))
areq_ctx->is_single_pass = false;
break;
default:
SSI_LOG_ERR("Unexpected flow mode (%d)\n", ctx->flow_mode);
goto data_size_err;
}
return 0;
data_size_err:
return -EINVAL;
}
static unsigned int format_ccm_a0(u8 *pa0_buff, u32 header_size)
{
unsigned int len = 0;
if (header_size == 0)
return 0;
if (header_size < ((1UL << 16) - (1UL << 8))) {
len = 2;
pa0_buff[0] = (header_size >> 8) & 0xFF;
pa0_buff[1] = header_size & 0xFF;
} else {
len = 6;
pa0_buff[0] = 0xFF;
pa0_buff[1] = 0xFE;
pa0_buff[2] = (header_size >> 24) & 0xFF;
pa0_buff[3] = (header_size >> 16) & 0xFF;
pa0_buff[4] = (header_size >> 8) & 0xFF;
pa0_buff[5] = header_size & 0xFF;
}
return len;
}
static int set_msg_len(u8 *block, unsigned int msglen, unsigned int csize)
{
__be32 data;
memset(block, 0, csize);
block += csize;
if (csize >= 4)
csize = 4;
else if (msglen > (1 << (8 * csize)))
return -EOVERFLOW;
data = cpu_to_be32(msglen);
memcpy(block - csize, (u8 *)&data + 4 - csize, csize);
return 0;
}
static inline int ssi_aead_ccm(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
unsigned int idx = *seq_size;
unsigned int cipher_flow_mode;
dma_addr_t mac_result;
if (req_ctx->gen_ctx.op_type == DRV_CRYPTO_DIRECTION_DECRYPT) {
cipher_flow_mode = AES_to_HASH_and_DOUT;
mac_result = req_ctx->mac_buf_dma_addr;
} else {
cipher_flow_mode = AES_and_HASH;
mac_result = req_ctx->icv_dma_addr;
}
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CTR);
set_din_type(&desc[idx], DMA_DLLI, ctx->enckey_dma_addr,
((ctx->enc_keylen == 24) ? CC_AES_KEY_SIZE_MAX :
ctx->enc_keylen), NS_BIT);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CTR);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_din_type(&desc[idx], DMA_DLLI,
req_ctx->gen_ctx.iv_dma_addr, AES_BLOCK_SIZE, NS_BIT);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CBC_MAC);
set_din_type(&desc[idx], DMA_DLLI, ctx->enckey_dma_addr,
((ctx->enc_keylen == 24) ? CC_AES_KEY_SIZE_MAX :
ctx->enc_keylen), NS_BIT);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CBC_MAC);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_din_type(&desc[idx], DMA_DLLI, req_ctx->mac_buf_dma_addr,
AES_BLOCK_SIZE, NS_BIT);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
idx++;
if (req->assoclen > 0) {
ssi_aead_create_assoc_desc(req, DIN_HASH, desc, &idx);
} else {
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
sg_dma_address(&req_ctx->ccm_adata_sg),
AES_BLOCK_SIZE + req_ctx->ccm_hdr_size, NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
}
if (req_ctx->cryptlen != 0)
ssi_aead_process_cipher_data_desc(req, cipher_flow_mode, desc, &idx);
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CBC_MAC);
set_dout_dlli(&desc[idx], req_ctx->mac_buf_dma_addr, ctx->authsize,
NS_BIT, 0);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_cipher_config0(&desc[idx], HASH_DIGEST_RESULT_LITTLE_ENDIAN);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CTR);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_din_type(&desc[idx], DMA_DLLI, req_ctx->ccm_iv0_dma_addr,
AES_BLOCK_SIZE, NS_BIT);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_no_dma(&desc[idx], 0, 0, 1);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, req_ctx->mac_buf_dma_addr,
ctx->authsize, NS_BIT);
set_dout_dlli(&desc[idx], mac_result, ctx->authsize, NS_BIT, 1);
set_queue_last_ind(&desc[idx]);
set_flow_mode(&desc[idx], DIN_AES_DOUT);
idx++;
*seq_size = idx;
return 0;
}
static int config_ccm_adata(struct aead_request *req)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
unsigned int lp = req->iv[0];
unsigned int l = lp + 1;
unsigned int m = ctx->authsize;
u8 *b0 = req_ctx->ccm_config + CCM_B0_OFFSET;
u8 *a0 = req_ctx->ccm_config + CCM_A0_OFFSET;
u8 *ctr_count_0 = req_ctx->ccm_config + CCM_CTR_COUNT_0_OFFSET;
unsigned int cryptlen = (req_ctx->gen_ctx.op_type ==
DRV_CRYPTO_DIRECTION_ENCRYPT) ?
req->cryptlen :
(req->cryptlen - ctx->authsize);
int rc;
memset(req_ctx->mac_buf, 0, AES_BLOCK_SIZE);
memset(req_ctx->ccm_config, 0, AES_BLOCK_SIZE * 3);
if (l < 2 || l > 8) {
SSI_LOG_ERR("illegal iv value %X\n", req->iv[0]);
return -EINVAL;
}
memcpy(b0, req->iv, AES_BLOCK_SIZE);
*b0 |= (8 * ((m - 2) / 2));
if (req->assoclen > 0)
*b0 |= 64;
rc = set_msg_len(b0 + 16 - l, cryptlen, l);
if (rc != 0)
return rc;
req_ctx->ccm_hdr_size = format_ccm_a0(a0, req->assoclen);
memset(req->iv + 15 - req->iv[0], 0, req->iv[0] + 1);
req->iv[15] = 1;
memcpy(ctr_count_0, req->iv, AES_BLOCK_SIZE);
ctr_count_0[15] = 0;
return 0;
}
static void ssi_rfc4309_ccm_process(struct aead_request *req)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
memset(areq_ctx->ctr_iv, 0, AES_BLOCK_SIZE);
areq_ctx->ctr_iv[0] = 3;
memcpy(areq_ctx->ctr_iv + CCM_BLOCK_NONCE_OFFSET, ctx->ctr_nonce, CCM_BLOCK_NONCE_SIZE);
memcpy(areq_ctx->ctr_iv + CCM_BLOCK_IV_OFFSET, req->iv, CCM_BLOCK_IV_SIZE);
req->iv = areq_ctx->ctr_iv;
req->assoclen -= CCM_BLOCK_IV_SIZE;
}
static inline void ssi_aead_gcm_setup_ghash_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
unsigned int idx = *seq_size;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_ECB);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_din_type(&desc[idx], DMA_DLLI, ctx->enckey_dma_addr,
ctx->enc_keylen, NS_BIT);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_din_const(&desc[idx], 0x0, AES_BLOCK_SIZE);
set_dout_dlli(&desc[idx], req_ctx->hkey_dma_addr, AES_BLOCK_SIZE,
NS_BIT, 0);
set_flow_mode(&desc[idx], DIN_AES_DOUT);
idx++;
hw_desc_init(&desc[idx]);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_no_dma(&desc[idx], 0, 0, 1);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, req_ctx->hkey_dma_addr,
AES_BLOCK_SIZE, NS_BIT);
set_dout_no_dma(&desc[idx], 0, 0, 1);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_HASH_HW_GHASH);
set_cipher_config1(&desc[idx], HASH_PADDING_ENABLED);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_no_dma(&desc[idx], 0, 0, 1);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_HASH_HW_GHASH);
set_cipher_do(&desc[idx], 1);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_cipher_config1(&desc[idx], HASH_PADDING_ENABLED);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_din_const(&desc[idx], 0x0, AES_BLOCK_SIZE);
set_dout_no_dma(&desc[idx], 0, 0, 1);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_HASH_HW_GHASH);
set_cipher_config1(&desc[idx], HASH_PADDING_ENABLED);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
idx++;
*seq_size = idx;
}
static inline void ssi_aead_gcm_setup_gctr_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
unsigned int idx = *seq_size;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_GCTR);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_din_type(&desc[idx], DMA_DLLI, ctx->enckey_dma_addr,
ctx->enc_keylen, NS_BIT);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
if ((req_ctx->cryptlen != 0) && (!req_ctx->plaintext_authenticate_only)) {
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_GCTR);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_din_type(&desc[idx], DMA_DLLI,
req_ctx->gcm_iv_inc2_dma_addr, AES_BLOCK_SIZE,
NS_BIT);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
}
*seq_size = idx;
}
static inline void ssi_aead_process_gcm_result_desc(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
dma_addr_t mac_result;
unsigned int idx = *seq_size;
if (req_ctx->gen_ctx.op_type == DRV_CRYPTO_DIRECTION_DECRYPT) {
mac_result = req_ctx->mac_buf_dma_addr;
} else {
mac_result = req_ctx->icv_dma_addr;
}
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, req_ctx->gcm_block_len_dma_addr,
AES_BLOCK_SIZE, NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_HASH_HW_GHASH);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_dlli(&desc[idx], req_ctx->mac_buf_dma_addr, AES_BLOCK_SIZE,
NS_BIT, 0);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_GCTR);
set_key_size_aes(&desc[idx], ctx->enc_keylen);
set_din_type(&desc[idx], DMA_DLLI, req_ctx->gcm_iv_inc1_dma_addr,
AES_BLOCK_SIZE, NS_BIT);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_no_dma(&desc[idx], 0, 0, 1);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_GCTR);
set_din_type(&desc[idx], DMA_DLLI, req_ctx->mac_buf_dma_addr,
AES_BLOCK_SIZE, NS_BIT);
set_dout_dlli(&desc[idx], mac_result, ctx->authsize, NS_BIT, 1);
set_queue_last_ind(&desc[idx]);
set_flow_mode(&desc[idx], DIN_AES_DOUT);
idx++;
*seq_size = idx;
}
static inline int ssi_aead_gcm(
struct aead_request *req,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
unsigned int idx = *seq_size;
unsigned int cipher_flow_mode;
if (req_ctx->gen_ctx.op_type == DRV_CRYPTO_DIRECTION_DECRYPT) {
cipher_flow_mode = AES_and_HASH;
} else {
cipher_flow_mode = AES_to_HASH_and_DOUT;
}
if (req_ctx->plaintext_authenticate_only) {
ssi_aead_process_cipher_data_desc(req, BYPASS, desc, seq_size);
ssi_aead_gcm_setup_ghash_desc(req, desc, seq_size);
ssi_aead_create_assoc_desc(req, DIN_HASH, desc, seq_size);
ssi_aead_gcm_setup_gctr_desc(req, desc, seq_size);
ssi_aead_process_gcm_result_desc(req, desc, seq_size);
idx = *seq_size;
return 0;
}
ssi_aead_gcm_setup_ghash_desc(req, desc, seq_size);
if (req->assoclen > 0)
ssi_aead_create_assoc_desc(req, DIN_HASH, desc, seq_size);
ssi_aead_gcm_setup_gctr_desc(req, desc, seq_size);
if (req_ctx->cryptlen != 0)
ssi_aead_process_cipher_data_desc(req, cipher_flow_mode, desc, seq_size);
ssi_aead_process_gcm_result_desc(req, desc, seq_size);
idx = *seq_size;
return 0;
}
static inline void ssi_aead_dump_gcm(
const char *title,
struct aead_request *req)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
if (ctx->cipher_mode != DRV_CIPHER_GCTR)
return;
if (title) {
SSI_LOG_DEBUG("----------------------------------------------------------------------------------");
SSI_LOG_DEBUG("%s\n", title);
}
SSI_LOG_DEBUG("cipher_mode %d, authsize %d, enc_keylen %d, assoclen %d, cryptlen %d\n",
ctx->cipher_mode, ctx->authsize, ctx->enc_keylen,
req->assoclen, req_ctx->cryptlen);
if (ctx->enckey)
dump_byte_array("mac key", ctx->enckey, 16);
dump_byte_array("req->iv", req->iv, AES_BLOCK_SIZE);
dump_byte_array("gcm_iv_inc1", req_ctx->gcm_iv_inc1, AES_BLOCK_SIZE);
dump_byte_array("gcm_iv_inc2", req_ctx->gcm_iv_inc2, AES_BLOCK_SIZE);
dump_byte_array("hkey", req_ctx->hkey, AES_BLOCK_SIZE);
dump_byte_array("mac_buf", req_ctx->mac_buf, AES_BLOCK_SIZE);
dump_byte_array("gcm_len_block", req_ctx->gcm_len_block.len_a, AES_BLOCK_SIZE);
if (req->src && req->cryptlen)
dump_byte_array("req->src", sg_virt(req->src), req->cryptlen + req->assoclen);
if (req->dst)
dump_byte_array("req->dst", sg_virt(req->dst), req->cryptlen + ctx->authsize + req->assoclen);
}
static int config_gcm_context(struct aead_request *req)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *req_ctx = aead_request_ctx(req);
unsigned int cryptlen = (req_ctx->gen_ctx.op_type ==
DRV_CRYPTO_DIRECTION_ENCRYPT) ?
req->cryptlen :
(req->cryptlen - ctx->authsize);
__be32 counter = cpu_to_be32(2);
SSI_LOG_DEBUG("%s() cryptlen = %d, req->assoclen = %d ctx->authsize = %d\n", __func__, cryptlen, req->assoclen, ctx->authsize);
memset(req_ctx->hkey, 0, AES_BLOCK_SIZE);
memset(req_ctx->mac_buf, 0, AES_BLOCK_SIZE);
memcpy(req->iv + 12, &counter, 4);
memcpy(req_ctx->gcm_iv_inc2, req->iv, 16);
counter = cpu_to_be32(1);
memcpy(req->iv + 12, &counter, 4);
memcpy(req_ctx->gcm_iv_inc1, req->iv, 16);
if (!req_ctx->plaintext_authenticate_only) {
__be64 temp64;
temp64 = cpu_to_be64(req->assoclen * 8);
memcpy(&req_ctx->gcm_len_block.len_a, &temp64, sizeof(temp64));
temp64 = cpu_to_be64(cryptlen * 8);
memcpy(&req_ctx->gcm_len_block.len_c, &temp64, 8);
} else {
__be64 temp64;
temp64 = cpu_to_be64((req->assoclen + GCM_BLOCK_RFC4_IV_SIZE + cryptlen) * 8);
memcpy(&req_ctx->gcm_len_block.len_a, &temp64, sizeof(temp64));
temp64 = 0;
memcpy(&req_ctx->gcm_len_block.len_c, &temp64, 8);
}
return 0;
}
static void ssi_rfc4_gcm_process(struct aead_request *req)
{
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
memcpy(areq_ctx->ctr_iv + GCM_BLOCK_RFC4_NONCE_OFFSET, ctx->ctr_nonce, GCM_BLOCK_RFC4_NONCE_SIZE);
memcpy(areq_ctx->ctr_iv + GCM_BLOCK_RFC4_IV_OFFSET, req->iv, GCM_BLOCK_RFC4_IV_SIZE);
req->iv = areq_ctx->ctr_iv;
req->assoclen -= GCM_BLOCK_RFC4_IV_SIZE;
}
static int ssi_aead_process(struct aead_request *req, enum drv_crypto_direction direct)
{
int rc = 0;
int seq_len = 0;
struct cc_hw_desc desc[MAX_AEAD_PROCESS_SEQ];
struct crypto_aead *tfm = crypto_aead_reqtfm(req);
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
struct device *dev = &ctx->drvdata->plat_dev->dev;
struct ssi_crypto_req ssi_req = {};
SSI_LOG_DEBUG("%s context=%p req=%p iv=%p src=%p src_ofs=%d dst=%p dst_ofs=%d cryptolen=%d\n",
((direct == DRV_CRYPTO_DIRECTION_ENCRYPT) ? "Encrypt" : "Decrypt"),
ctx, req, req->iv, sg_virt(req->src), req->src->offset,
sg_virt(req->dst), req->dst->offset, req->cryptlen);
if (unlikely(validate_data_size(ctx, direct, req) != 0)) {
SSI_LOG_ERR("Unsupported crypt/assoc len %d/%d.\n",
req->cryptlen, req->assoclen);
crypto_aead_set_flags(tfm, CRYPTO_TFM_RES_BAD_BLOCK_LEN);
return -EINVAL;
}
ssi_req.user_cb = (void *)ssi_aead_complete;
ssi_req.user_arg = (void *)req;
areq_ctx->gen_ctx.op_type = direct;
areq_ctx->req_authsize = ctx->authsize;
areq_ctx->cipher_mode = ctx->cipher_mode;
if (ctx->cipher_mode == DRV_CIPHER_CTR) {
memcpy(areq_ctx->ctr_iv, ctx->ctr_nonce, CTR_RFC3686_NONCE_SIZE);
if (!areq_ctx->backup_giv)
memcpy(areq_ctx->ctr_iv + CTR_RFC3686_NONCE_SIZE,
req->iv, CTR_RFC3686_IV_SIZE);
*(__be32 *)(areq_ctx->ctr_iv + CTR_RFC3686_NONCE_SIZE +
CTR_RFC3686_IV_SIZE) = cpu_to_be32(1);
req->iv = areq_ctx->ctr_iv;
areq_ctx->hw_iv_size = CTR_RFC3686_BLOCK_SIZE;
} else if ((ctx->cipher_mode == DRV_CIPHER_CCM) ||
(ctx->cipher_mode == DRV_CIPHER_GCTR)) {
areq_ctx->hw_iv_size = AES_BLOCK_SIZE;
if (areq_ctx->ctr_iv != req->iv) {
memcpy(areq_ctx->ctr_iv, req->iv, crypto_aead_ivsize(tfm));
req->iv = areq_ctx->ctr_iv;
}
} else {
areq_ctx->hw_iv_size = crypto_aead_ivsize(tfm);
}
#if SSI_CC_HAS_AES_CCM
if (ctx->cipher_mode == DRV_CIPHER_CCM) {
rc = config_ccm_adata(req);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("config_ccm_adata() returned with a failure %d!", rc);
goto exit;
}
} else {
areq_ctx->ccm_hdr_size = ccm_header_size_null;
}
#else
areq_ctx->ccm_hdr_size = ccm_header_size_null;
#endif
#if SSI_CC_HAS_AES_GCM
if (ctx->cipher_mode == DRV_CIPHER_GCTR) {
rc = config_gcm_context(req);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("config_gcm_context() returned with a failure %d!", rc);
goto exit;
}
}
#endif
rc = ssi_buffer_mgr_map_aead_request(ctx->drvdata, req);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("map_request() failed\n");
goto exit;
}
if (areq_ctx->backup_giv) {
if (ctx->cipher_mode == DRV_CIPHER_CTR) {
ssi_req.ivgen_dma_addr[0] = areq_ctx->gen_ctx.iv_dma_addr + CTR_RFC3686_NONCE_SIZE;
ssi_req.ivgen_dma_addr_len = 1;
} else if (ctx->cipher_mode == DRV_CIPHER_CCM) {
ssi_req.ivgen_dma_addr[0] = areq_ctx->gen_ctx.iv_dma_addr + CCM_BLOCK_IV_OFFSET;
ssi_req.ivgen_dma_addr[1] = sg_dma_address(&areq_ctx->ccm_adata_sg) + CCM_B0_OFFSET + CCM_BLOCK_IV_OFFSET;
ssi_req.ivgen_dma_addr[2] = sg_dma_address(&areq_ctx->ccm_adata_sg) + CCM_CTR_COUNT_0_OFFSET + CCM_BLOCK_IV_OFFSET;
ssi_req.ivgen_dma_addr_len = 3;
} else {
ssi_req.ivgen_dma_addr[0] = areq_ctx->gen_ctx.iv_dma_addr;
ssi_req.ivgen_dma_addr_len = 1;
}
ssi_req.ivgen_size = crypto_aead_ivsize(tfm);
}
ssi_aead_load_mlli_to_sram(req, desc, &seq_len);
switch (ctx->auth_mode) {
case DRV_HASH_SHA1:
case DRV_HASH_SHA256:
ssi_aead_hmac_authenc(req, desc, &seq_len);
break;
case DRV_HASH_XCBC_MAC:
ssi_aead_xcbc_authenc(req, desc, &seq_len);
break;
#if (SSI_CC_HAS_AES_CCM || SSI_CC_HAS_AES_GCM)
case DRV_HASH_NULL:
#if SSI_CC_HAS_AES_CCM
if (ctx->cipher_mode == DRV_CIPHER_CCM)
ssi_aead_ccm(req, desc, &seq_len);
#endif
#if SSI_CC_HAS_AES_GCM
if (ctx->cipher_mode == DRV_CIPHER_GCTR)
ssi_aead_gcm(req, desc, &seq_len);
#endif
break;
#endif
default:
SSI_LOG_ERR("Unsupported authenc (%d)\n", ctx->auth_mode);
ssi_buffer_mgr_unmap_aead_request(dev, req);
rc = -ENOTSUPP;
goto exit;
}
rc = send_request(ctx->drvdata, &ssi_req, desc, seq_len, 1);
if (unlikely(rc != -EINPROGRESS)) {
SSI_LOG_ERR("send_request() failed (rc=%d)\n", rc);
ssi_buffer_mgr_unmap_aead_request(dev, req);
}
exit:
return rc;
}
static int ssi_aead_encrypt(struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
int rc;
areq_ctx->backup_iv = req->iv;
areq_ctx->backup_giv = NULL;
areq_ctx->is_gcm4543 = false;
areq_ctx->plaintext_authenticate_only = false;
rc = ssi_aead_process(req, DRV_CRYPTO_DIRECTION_ENCRYPT);
if (rc != -EINPROGRESS)
req->iv = areq_ctx->backup_iv;
return rc;
}
static int ssi_rfc4309_ccm_encrypt(struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
int rc = -EINVAL;
if (!valid_assoclen(req)) {
SSI_LOG_ERR("invalid Assoclen:%u\n", req->assoclen);
goto out;
}
areq_ctx->backup_iv = req->iv;
areq_ctx->backup_giv = NULL;
areq_ctx->is_gcm4543 = true;
ssi_rfc4309_ccm_process(req);
rc = ssi_aead_process(req, DRV_CRYPTO_DIRECTION_ENCRYPT);
if (rc != -EINPROGRESS)
req->iv = areq_ctx->backup_iv;
out:
return rc;
}
static int ssi_aead_decrypt(struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
int rc;
areq_ctx->backup_iv = req->iv;
areq_ctx->backup_giv = NULL;
areq_ctx->is_gcm4543 = false;
areq_ctx->plaintext_authenticate_only = false;
rc = ssi_aead_process(req, DRV_CRYPTO_DIRECTION_DECRYPT);
if (rc != -EINPROGRESS)
req->iv = areq_ctx->backup_iv;
return rc;
}
static int ssi_rfc4309_ccm_decrypt(struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
int rc = -EINVAL;
if (!valid_assoclen(req)) {
SSI_LOG_ERR("invalid Assoclen:%u\n", req->assoclen);
goto out;
}
areq_ctx->backup_iv = req->iv;
areq_ctx->backup_giv = NULL;
areq_ctx->is_gcm4543 = true;
ssi_rfc4309_ccm_process(req);
rc = ssi_aead_process(req, DRV_CRYPTO_DIRECTION_DECRYPT);
if (rc != -EINPROGRESS)
req->iv = areq_ctx->backup_iv;
out:
return rc;
}
static int ssi_rfc4106_gcm_setkey(struct crypto_aead *tfm, const u8 *key, unsigned int keylen)
{
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
int rc = 0;
SSI_LOG_DEBUG("%s() keylen %d, key %p\n", __func__, keylen, key);
if (keylen < 4)
return -EINVAL;
keylen -= 4;
memcpy(ctx->ctr_nonce, key + keylen, 4);
rc = ssi_aead_setkey(tfm, key, keylen);
return rc;
}
static int ssi_rfc4543_gcm_setkey(struct crypto_aead *tfm, const u8 *key, unsigned int keylen)
{
struct ssi_aead_ctx *ctx = crypto_aead_ctx(tfm);
int rc = 0;
SSI_LOG_DEBUG("%s() keylen %d, key %p\n", __func__, keylen, key);
if (keylen < 4)
return -EINVAL;
keylen -= 4;
memcpy(ctx->ctr_nonce, key + keylen, 4);
rc = ssi_aead_setkey(tfm, key, keylen);
return rc;
}
static int ssi_gcm_setauthsize(struct crypto_aead *authenc,
unsigned int authsize)
{
switch (authsize) {
case 4:
case 8:
case 12:
case 13:
case 14:
case 15:
case 16:
break;
default:
return -EINVAL;
}
return ssi_aead_setauthsize(authenc, authsize);
}
static int ssi_rfc4106_gcm_setauthsize(struct crypto_aead *authenc,
unsigned int authsize)
{
SSI_LOG_DEBUG("authsize %d\n", authsize);
switch (authsize) {
case 8:
case 12:
case 16:
break;
default:
return -EINVAL;
}
return ssi_aead_setauthsize(authenc, authsize);
}
static int ssi_rfc4543_gcm_setauthsize(struct crypto_aead *authenc,
unsigned int authsize)
{
SSI_LOG_DEBUG("authsize %d\n", authsize);
if (authsize != 16)
return -EINVAL;
return ssi_aead_setauthsize(authenc, authsize);
}
static int ssi_rfc4106_gcm_encrypt(struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
int rc = -EINVAL;
if (!valid_assoclen(req)) {
SSI_LOG_ERR("invalid Assoclen:%u\n", req->assoclen);
goto out;
}
areq_ctx->backup_iv = req->iv;
areq_ctx->backup_giv = NULL;
areq_ctx->plaintext_authenticate_only = false;
ssi_rfc4_gcm_process(req);
areq_ctx->is_gcm4543 = true;
rc = ssi_aead_process(req, DRV_CRYPTO_DIRECTION_ENCRYPT);
if (rc != -EINPROGRESS)
req->iv = areq_ctx->backup_iv;
out:
return rc;
}
static int ssi_rfc4543_gcm_encrypt(struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
int rc;
areq_ctx->plaintext_authenticate_only = true;
areq_ctx->backup_iv = req->iv;
areq_ctx->backup_giv = NULL;
ssi_rfc4_gcm_process(req);
areq_ctx->is_gcm4543 = true;
rc = ssi_aead_process(req, DRV_CRYPTO_DIRECTION_ENCRYPT);
if (rc != -EINPROGRESS)
req->iv = areq_ctx->backup_iv;
return rc;
}
static int ssi_rfc4106_gcm_decrypt(struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
int rc = -EINVAL;
if (!valid_assoclen(req)) {
SSI_LOG_ERR("invalid Assoclen:%u\n", req->assoclen);
goto out;
}
areq_ctx->backup_iv = req->iv;
areq_ctx->backup_giv = NULL;
areq_ctx->plaintext_authenticate_only = false;
ssi_rfc4_gcm_process(req);
areq_ctx->is_gcm4543 = true;
rc = ssi_aead_process(req, DRV_CRYPTO_DIRECTION_DECRYPT);
if (rc != -EINPROGRESS)
req->iv = areq_ctx->backup_iv;
out:
return rc;
}
static int ssi_rfc4543_gcm_decrypt(struct aead_request *req)
{
struct aead_req_ctx *areq_ctx = aead_request_ctx(req);
int rc;
areq_ctx->plaintext_authenticate_only = true;
areq_ctx->backup_iv = req->iv;
areq_ctx->backup_giv = NULL;
ssi_rfc4_gcm_process(req);
areq_ctx->is_gcm4543 = true;
rc = ssi_aead_process(req, DRV_CRYPTO_DIRECTION_DECRYPT);
if (rc != -EINPROGRESS)
req->iv = areq_ctx->backup_iv;
return rc;
}
static struct ssi_crypto_alg *ssi_aead_create_alg(struct ssi_alg_template *template)
{
struct ssi_crypto_alg *t_alg;
struct aead_alg *alg;
t_alg = kzalloc(sizeof(*t_alg), GFP_KERNEL);
if (!t_alg) {
SSI_LOG_ERR("failed to allocate t_alg\n");
return ERR_PTR(-ENOMEM);
}
alg = &template->template_aead;
snprintf(alg->base.cra_name, CRYPTO_MAX_ALG_NAME, "%s", template->name);
snprintf(alg->base.cra_driver_name, CRYPTO_MAX_ALG_NAME, "%s",
template->driver_name);
alg->base.cra_module = THIS_MODULE;
alg->base.cra_priority = SSI_CRA_PRIO;
alg->base.cra_ctxsize = sizeof(struct ssi_aead_ctx);
alg->base.cra_flags = CRYPTO_ALG_ASYNC | CRYPTO_ALG_KERN_DRIVER_ONLY |
template->type;
alg->init = ssi_aead_init;
alg->exit = ssi_aead_exit;
t_alg->aead_alg = *alg;
t_alg->cipher_mode = template->cipher_mode;
t_alg->flow_mode = template->flow_mode;
t_alg->auth_mode = template->auth_mode;
return t_alg;
}
int ssi_aead_free(struct ssi_drvdata *drvdata)
{
struct ssi_crypto_alg *t_alg, *n;
struct ssi_aead_handle *aead_handle =
(struct ssi_aead_handle *)drvdata->aead_handle;
if (aead_handle) {
list_for_each_entry_safe(t_alg, n, &aead_handle->aead_list, entry) {
crypto_unregister_aead(&t_alg->aead_alg);
list_del(&t_alg->entry);
kfree(t_alg);
}
kfree(aead_handle);
drvdata->aead_handle = NULL;
}
return 0;
}
int ssi_aead_alloc(struct ssi_drvdata *drvdata)
{
struct ssi_aead_handle *aead_handle;
struct ssi_crypto_alg *t_alg;
int rc = -ENOMEM;
int alg;
aead_handle = kmalloc(sizeof(*aead_handle), GFP_KERNEL);
if (!aead_handle) {
rc = -ENOMEM;
goto fail0;
}
drvdata->aead_handle = aead_handle;
aead_handle->sram_workspace_addr = ssi_sram_mgr_alloc(
drvdata, MAX_HMAC_DIGEST_SIZE);
if (aead_handle->sram_workspace_addr == NULL_SRAM_ADDR) {
SSI_LOG_ERR("SRAM pool exhausted\n");
rc = -ENOMEM;
goto fail1;
}
INIT_LIST_HEAD(&aead_handle->aead_list);
for (alg = 0; alg < ARRAY_SIZE(aead_algs); alg++) {
t_alg = ssi_aead_create_alg(&aead_algs[alg]);
if (IS_ERR(t_alg)) {
rc = PTR_ERR(t_alg);
SSI_LOG_ERR("%s alg allocation failed\n",
aead_algs[alg].driver_name);
goto fail1;
}
t_alg->drvdata = drvdata;
rc = crypto_register_aead(&t_alg->aead_alg);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("%s alg registration failed\n",
t_alg->aead_alg.base.cra_driver_name);
goto fail2;
} else {
list_add_tail(&t_alg->entry, &aead_handle->aead_list);
SSI_LOG_DEBUG("Registered %s\n", t_alg->aead_alg.base.cra_driver_name);
}
}
return 0;
fail2:
kfree(t_alg);
fail1:
ssi_aead_free(drvdata);
fail0:
return rc;
}
