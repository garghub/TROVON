static inline enum cc_fips_error
FIPS_CipherToFipsError(enum drv_cipher_mode mode, bool is_aes)
{
switch (mode)
{
case DRV_CIPHER_ECB:
return is_aes ? CC_REE_FIPS_ERROR_AES_ECB_PUT : CC_REE_FIPS_ERROR_DES_ECB_PUT;
case DRV_CIPHER_CBC:
return is_aes ? CC_REE_FIPS_ERROR_AES_CBC_PUT : CC_REE_FIPS_ERROR_DES_CBC_PUT;
case DRV_CIPHER_OFB:
return CC_REE_FIPS_ERROR_AES_OFB_PUT;
case DRV_CIPHER_CTR:
return CC_REE_FIPS_ERROR_AES_CTR_PUT;
case DRV_CIPHER_CBC_CTS:
return CC_REE_FIPS_ERROR_AES_CBC_CTS_PUT;
case DRV_CIPHER_XTS:
return CC_REE_FIPS_ERROR_AES_XTS_PUT;
default:
return CC_REE_FIPS_ERROR_GENERAL;
}
return CC_REE_FIPS_ERROR_GENERAL;
}
static inline int
ssi_cipher_fips_run_test(struct ssi_drvdata *drvdata,
bool is_aes,
int cipher_mode,
int direction,
dma_addr_t key_dma_addr,
size_t key_len,
dma_addr_t iv_dma_addr,
size_t iv_len,
dma_addr_t din_dma_addr,
dma_addr_t dout_dma_addr,
size_t data_size)
{
#define FIPS_CIPHER_MAX_SEQ_LEN 6
int rc;
struct ssi_crypto_req ssi_req = {0};
struct cc_hw_desc desc[FIPS_CIPHER_MAX_SEQ_LEN];
int idx = 0;
int s_flow_mode = is_aes ? S_DIN_to_AES : S_DIN_to_DES;
switch (cipher_mode) {
case DRV_CIPHER_CBC:
case DRV_CIPHER_CBC_CTS:
case DRV_CIPHER_CTR:
case DRV_CIPHER_OFB:
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI,
iv_dma_addr, iv_len, NS_BIT);
set_cipher_config0(&desc[idx], direction);
set_flow_mode(&desc[idx], s_flow_mode);
set_cipher_mode(&desc[idx], cipher_mode);
if ((cipher_mode == DRV_CIPHER_CTR) ||
(cipher_mode == DRV_CIPHER_OFB)) {
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
} else {
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
}
idx++;
case DRV_CIPHER_ECB:
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], cipher_mode);
set_cipher_config0(&desc[idx], direction);
if (is_aes) {
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr,
((key_len == 24) ? AES_MAX_KEY_SIZE :
key_len), NS_BIT);
set_key_size_aes(&desc[idx], key_len);
} else {
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr,
key_len, NS_BIT);
set_key_size_des(&desc[idx], key_len);
}
set_flow_mode(&desc[idx], s_flow_mode);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
break;
case DRV_CIPHER_XTS:
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], cipher_mode);
set_cipher_config0(&desc[idx], direction);
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr, (key_len / 2),
NS_BIT);
set_key_size_aes(&desc[idx], (key_len / 2));
set_flow_mode(&desc[idx], s_flow_mode);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], cipher_mode);
set_cipher_config0(&desc[idx], direction);
set_din_type(&desc[idx], DMA_DLLI,
(key_dma_addr + (key_len / 2)),
(key_len / 2), NS_BIT);
set_xex_data_unit_size(&desc[idx], data_size);
set_flow_mode(&desc[idx], s_flow_mode);
set_key_size_aes(&desc[idx], (key_len / 2));
set_setup_mode(&desc[idx], SETUP_LOAD_XEX_KEY);
idx++;
hw_desc_init(&desc[idx]);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_cipher_mode(&desc[idx], cipher_mode);
set_cipher_config0(&desc[idx], direction);
set_key_size_aes(&desc[idx], (key_len / 2));
set_flow_mode(&desc[idx], s_flow_mode);
set_din_type(&desc[idx], DMA_DLLI, iv_dma_addr,
CC_AES_BLOCK_SIZE, NS_BIT);
idx++;
break;
default:
FIPS_LOG("Unsupported cipher mode (%d)\n", cipher_mode);
BUG();
}
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, din_dma_addr, data_size, NS_BIT);
set_dout_dlli(&desc[idx], dout_dma_addr, data_size, NS_BIT, 0);
set_flow_mode(&desc[idx], is_aes ? DIN_AES_DOUT : DIN_DES_DOUT);
idx++;
BUG_ON(idx > FIPS_CIPHER_MAX_SEQ_LEN);
rc = send_request(drvdata, &ssi_req, desc, idx, false);
return rc;
}
enum cc_fips_error
ssi_cipher_fips_power_up_tests(struct ssi_drvdata *drvdata, void *cpu_addr_buffer, dma_addr_t dma_coherent_buffer)
{
enum cc_fips_error error = CC_REE_FIPS_ERROR_OK;
size_t i;
struct fips_cipher_ctx *virt_ctx = (struct fips_cipher_ctx *)cpu_addr_buffer;
dma_addr_t iv_dma_addr = dma_coherent_buffer + offsetof(struct fips_cipher_ctx, iv);
dma_addr_t key_dma_addr = dma_coherent_buffer + offsetof(struct fips_cipher_ctx, key);
dma_addr_t din_dma_addr = dma_coherent_buffer + offsetof(struct fips_cipher_ctx, din);
dma_addr_t dout_dma_addr = dma_coherent_buffer + offsetof(struct fips_cipher_ctx, dout);
for (i = 0; i < FIPS_CIPHER_NUM_OF_TESTS; ++i)
{
FipsCipherData *cipherData = (FipsCipherData *)&FipsCipherDataTable[i];
int rc = 0;
size_t iv_size = cipherData->isAes ? NIST_AES_IV_SIZE : NIST_TDES_IV_SIZE;
memset(cpu_addr_buffer, 0, sizeof(struct fips_cipher_ctx));
memcpy(virt_ctx->iv, cipherData->iv, iv_size);
memcpy(virt_ctx->key, cipherData->key, cipherData->keySize);
memcpy(virt_ctx->din, cipherData->dataIn, cipherData->dataInSize);
FIPS_DBG("ssi_cipher_fips_run_test - (i = %d) \n", i);
rc = ssi_cipher_fips_run_test(drvdata,
cipherData->isAes,
cipherData->oprMode,
cipherData->direction,
key_dma_addr,
cipherData->keySize,
iv_dma_addr,
iv_size,
din_dma_addr,
dout_dma_addr,
cipherData->dataInSize);
if (rc != 0)
{
FIPS_LOG("ssi_cipher_fips_run_test %d returned error - rc = %d \n", i, rc);
error = FIPS_CipherToFipsError(cipherData->oprMode, cipherData->isAes);
break;
}
if (memcmp(virt_ctx->dout, cipherData->dataOut, cipherData->dataInSize) != 0)
{
FIPS_LOG("dout comparison error %d - oprMode=%d, isAes=%d\n", i, cipherData->oprMode, cipherData->isAes);
FIPS_LOG(" i expected received \n");
FIPS_LOG(" i 0x%08x 0x%08x (size=%d) \n", (size_t)cipherData->dataOut, (size_t)virt_ctx->dout, cipherData->dataInSize);
for (i = 0; i < cipherData->dataInSize; ++i)
{
FIPS_LOG(" %d 0x%02x 0x%02x \n", i, cipherData->dataOut[i], virt_ctx->dout[i]);
}
error = FIPS_CipherToFipsError(cipherData->oprMode, cipherData->isAes);
break;
}
}
return error;
}
static inline int
ssi_cmac_fips_run_test(struct ssi_drvdata *drvdata,
dma_addr_t key_dma_addr,
size_t key_len,
dma_addr_t din_dma_addr,
size_t din_len,
dma_addr_t digest_dma_addr,
size_t digest_len)
{
#define FIPS_CMAC_MAX_SEQ_LEN 4
int rc;
struct ssi_crypto_req ssi_req = {0};
struct cc_hw_desc desc[FIPS_CMAC_MAX_SEQ_LEN];
int idx = 0;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr,
((key_len == 24) ? AES_MAX_KEY_SIZE : key_len), NS_BIT);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_cipher_mode(&desc[idx], DRV_CIPHER_CMAC);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_key_size_aes(&desc[idx], key_len);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, digest_dma_addr, CC_AES_BLOCK_SIZE,
NS_BIT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
set_cipher_mode(&desc[idx], DRV_CIPHER_CMAC);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_key_size_aes(&desc[idx], key_len);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, din_dma_addr, din_len, NS_BIT);
set_flow_mode(&desc[idx], DIN_AES_DOUT);
idx++;
hw_desc_init(&desc[idx]);
set_dout_dlli(&desc[idx], digest_dma_addr, CC_AES_BLOCK_SIZE, NS_BIT,
0);
set_flow_mode(&desc[idx], S_AES_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_cipher_mode(&desc[idx], DRV_CIPHER_CMAC);
idx++;
BUG_ON(idx > FIPS_CMAC_MAX_SEQ_LEN);
rc = send_request(drvdata, &ssi_req, desc, idx, false);
return rc;
}
enum cc_fips_error
ssi_cmac_fips_power_up_tests(struct ssi_drvdata *drvdata, void *cpu_addr_buffer, dma_addr_t dma_coherent_buffer)
{
enum cc_fips_error error = CC_REE_FIPS_ERROR_OK;
size_t i;
struct fips_cmac_ctx *virt_ctx = (struct fips_cmac_ctx *)cpu_addr_buffer;
dma_addr_t key_dma_addr = dma_coherent_buffer + offsetof(struct fips_cmac_ctx, key);
dma_addr_t din_dma_addr = dma_coherent_buffer + offsetof(struct fips_cmac_ctx, din);
dma_addr_t mac_res_dma_addr = dma_coherent_buffer + offsetof(struct fips_cmac_ctx, mac_res);
for (i = 0; i < FIPS_CMAC_NUM_OF_TESTS; ++i)
{
FipsCmacData *cmac_data = (FipsCmacData *)&FipsCmacDataTable[i];
int rc = 0;
memset(cpu_addr_buffer, 0, sizeof(struct fips_cmac_ctx));
memcpy(virt_ctx->key, cmac_data->key, cmac_data->key_size);
memcpy(virt_ctx->din, cmac_data->data_in, cmac_data->data_in_size);
BUG_ON(cmac_data->direction != DRV_CRYPTO_DIRECTION_ENCRYPT);
FIPS_DBG("ssi_cmac_fips_run_test - (i = %d) \n", i);
rc = ssi_cmac_fips_run_test(drvdata,
key_dma_addr,
cmac_data->key_size,
din_dma_addr,
cmac_data->data_in_size,
mac_res_dma_addr,
cmac_data->mac_res_size);
if (rc != 0)
{
FIPS_LOG("ssi_cmac_fips_run_test %d returned error - rc = %d \n", i, rc);
error = CC_REE_FIPS_ERROR_AES_CMAC_PUT;
break;
}
if (memcmp(virt_ctx->mac_res, cmac_data->mac_res, cmac_data->mac_res_size) != 0)
{
FIPS_LOG("comparison error %d - digest_size=%d \n", i, cmac_data->mac_res_size);
FIPS_LOG(" i expected received \n");
FIPS_LOG(" i 0x%08x 0x%08x \n", (size_t)cmac_data->mac_res, (size_t)virt_ctx->mac_res);
for (i = 0; i < cmac_data->mac_res_size; ++i)
{
FIPS_LOG(" %d 0x%02x 0x%02x \n", i, cmac_data->mac_res[i], virt_ctx->mac_res[i]);
}
error = CC_REE_FIPS_ERROR_AES_CMAC_PUT;
break;
}
}
return error;
}
static inline enum cc_fips_error
FIPS_HashToFipsError(enum drv_hash_mode hash_mode)
{
switch (hash_mode) {
case DRV_HASH_SHA1:
return CC_REE_FIPS_ERROR_SHA1_PUT;
case DRV_HASH_SHA256:
return CC_REE_FIPS_ERROR_SHA256_PUT;
#if (CC_SUPPORT_SHA > 256)
case DRV_HASH_SHA512:
return CC_REE_FIPS_ERROR_SHA512_PUT;
#endif
default:
return CC_REE_FIPS_ERROR_GENERAL;
}
return CC_REE_FIPS_ERROR_GENERAL;
}
static inline int
ssi_hash_fips_run_test(struct ssi_drvdata *drvdata,
dma_addr_t initial_digest_dma_addr,
dma_addr_t din_dma_addr,
size_t data_in_size,
dma_addr_t mac_res_dma_addr,
enum drv_hash_mode hash_mode,
enum drv_hash_hw_mode hw_mode,
int digest_size,
int inter_digestsize)
{
#define FIPS_HASH_MAX_SEQ_LEN 4
int rc;
struct ssi_crypto_req ssi_req = {0};
struct cc_hw_desc desc[FIPS_HASH_MAX_SEQ_LEN];
int idx = 0;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_din_type(&desc[idx], DMA_DLLI, initial_digest_dma_addr,
inter_digestsize, NS_BIT);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_din_const(&desc[idx], 0, HASH_LEN_SIZE);
set_cipher_config1(&desc[idx], HASH_PADDING_ENABLED);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, din_dma_addr, data_in_size, NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_dout_dlli(&desc[idx], mac_res_dma_addr, digest_size, NS_BIT, 0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_cipher_config1(&desc[idx], HASH_PADDING_DISABLED);
if (unlikely((hash_mode == DRV_HASH_MD5) ||
(hash_mode == DRV_HASH_SHA384) ||
(hash_mode == DRV_HASH_SHA512))) {
set_bytes_swap(&desc[idx], 1);
} else {
set_cipher_config0(&desc[idx],
HASH_DIGEST_RESULT_LITTLE_ENDIAN);
}
idx++;
BUG_ON(idx > FIPS_HASH_MAX_SEQ_LEN);
rc = send_request(drvdata, &ssi_req, desc, idx, false);
return rc;
}
enum cc_fips_error
ssi_hash_fips_power_up_tests(struct ssi_drvdata *drvdata, void *cpu_addr_buffer, dma_addr_t dma_coherent_buffer)
{
enum cc_fips_error error = CC_REE_FIPS_ERROR_OK;
size_t i;
struct fips_hash_ctx *virt_ctx = (struct fips_hash_ctx *)cpu_addr_buffer;
dma_addr_t initial_digest_dma_addr = dma_coherent_buffer + offsetof(struct fips_hash_ctx, initial_digest);
dma_addr_t din_dma_addr = dma_coherent_buffer + offsetof(struct fips_hash_ctx, din);
dma_addr_t mac_res_dma_addr = dma_coherent_buffer + offsetof(struct fips_hash_ctx, mac_res);
for (i = 0; i < FIPS_HASH_NUM_OF_TESTS; ++i)
{
FipsHashData *hash_data = (FipsHashData *)&FipsHashDataTable[i];
int rc = 0;
enum drv_hash_hw_mode hw_mode = 0;
int digest_size = 0;
int inter_digestsize = 0;
memset(cpu_addr_buffer, 0, sizeof(struct fips_hash_ctx));
switch (hash_data->hash_mode) {
case DRV_HASH_SHA1:
hw_mode = DRV_HASH_HW_SHA1;
digest_size = CC_SHA1_DIGEST_SIZE;
inter_digestsize = CC_SHA1_DIGEST_SIZE;
memcpy(virt_ctx->initial_digest, (void *)sha1_init, CC_SHA1_DIGEST_SIZE);
break;
case DRV_HASH_SHA256:
hw_mode = DRV_HASH_HW_SHA256;
digest_size = CC_SHA256_DIGEST_SIZE;
inter_digestsize = CC_SHA256_DIGEST_SIZE;
memcpy(virt_ctx->initial_digest, (void *)sha256_init, CC_SHA256_DIGEST_SIZE);
break;
#if (CC_SUPPORT_SHA > 256)
case DRV_HASH_SHA512:
hw_mode = DRV_HASH_HW_SHA512;
digest_size = CC_SHA512_DIGEST_SIZE;
inter_digestsize = CC_SHA512_DIGEST_SIZE;
memcpy(virt_ctx->initial_digest, (void *)sha512_init, CC_SHA512_DIGEST_SIZE);
break;
#endif
default:
error = FIPS_HashToFipsError(hash_data->hash_mode);
break;
}
memcpy(virt_ctx->din, hash_data->data_in, hash_data->data_in_size);
FIPS_DBG("ssi_hash_fips_run_test - (i = %d) \n", i);
rc = ssi_hash_fips_run_test(drvdata,
initial_digest_dma_addr,
din_dma_addr,
hash_data->data_in_size,
mac_res_dma_addr,
hash_data->hash_mode,
hw_mode,
digest_size,
inter_digestsize);
if (rc != 0)
{
FIPS_LOG("ssi_hash_fips_run_test %d returned error - rc = %d \n", i, rc);
error = FIPS_HashToFipsError(hash_data->hash_mode);
break;
}
if (memcmp(virt_ctx->mac_res, hash_data->mac_res, digest_size) != 0)
{
FIPS_LOG("comparison error %d - hash_mode=%d digest_size=%d \n", i, hash_data->hash_mode, digest_size);
FIPS_LOG(" i expected received \n");
FIPS_LOG(" i 0x%08x 0x%08x \n", (size_t)hash_data->mac_res, (size_t)virt_ctx->mac_res);
for (i = 0; i < digest_size; ++i)
{
FIPS_LOG(" %d 0x%02x 0x%02x \n", i, hash_data->mac_res[i], virt_ctx->mac_res[i]);
}
error = FIPS_HashToFipsError(hash_data->hash_mode);
break;
}
}
return error;
}
static inline enum cc_fips_error
FIPS_HmacToFipsError(enum drv_hash_mode hash_mode)
{
switch (hash_mode) {
case DRV_HASH_SHA1:
return CC_REE_FIPS_ERROR_HMAC_SHA1_PUT;
case DRV_HASH_SHA256:
return CC_REE_FIPS_ERROR_HMAC_SHA256_PUT;
#if (CC_SUPPORT_SHA > 256)
case DRV_HASH_SHA512:
return CC_REE_FIPS_ERROR_HMAC_SHA512_PUT;
#endif
default:
return CC_REE_FIPS_ERROR_GENERAL;
}
return CC_REE_FIPS_ERROR_GENERAL;
}
static inline int
ssi_hmac_fips_run_test(struct ssi_drvdata *drvdata,
dma_addr_t initial_digest_dma_addr,
dma_addr_t key_dma_addr,
size_t key_size,
dma_addr_t din_dma_addr,
size_t data_in_size,
dma_addr_t mac_res_dma_addr,
enum drv_hash_mode hash_mode,
enum drv_hash_hw_mode hw_mode,
size_t digest_size,
size_t inter_digestsize,
size_t block_size,
dma_addr_t k0_dma_addr,
dma_addr_t tmp_digest_dma_addr,
dma_addr_t digest_bytes_len_dma_addr)
{
#define FIPS_HMAC_MAX_SEQ_LEN 12
int rc;
struct ssi_crypto_req ssi_req = {0};
struct cc_hw_desc desc[FIPS_HMAC_MAX_SEQ_LEN];
int idx = 0;
int i;
unsigned int hmacPadConst[2] = { HMAC_OPAD_CONST, HMAC_IPAD_CONST };
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr, key_size, NS_BIT);
set_flow_mode(&desc[idx], BYPASS);
set_dout_dlli(&desc[idx], k0_dma_addr, key_size, NS_BIT, 0);
idx++;
if ((block_size - key_size) != 0) {
hw_desc_init(&desc[idx]);
set_din_const(&desc[idx], 0, (block_size - key_size));
set_flow_mode(&desc[idx], BYPASS);
set_dout_dlli(&desc[idx], (k0_dma_addr + key_size),
(block_size - key_size), NS_BIT, 0);
idx++;
}
BUG_ON(idx > FIPS_HMAC_MAX_SEQ_LEN);
rc = send_request(drvdata, &ssi_req, desc, idx, 0);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("send_request() failed (rc=%d)\n", rc);
return rc;
}
idx = 0;
for (i = 0; i < 2; i++) {
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_din_type(&desc[idx], DMA_DLLI, initial_digest_dma_addr,
inter_digestsize, NS_BIT);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_din_const(&desc[idx], 0, HASH_LEN_SIZE);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_xor_val(&desc[idx], hmacPadConst[i]);
set_cipher_mode(&desc[idx], hw_mode);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, k0_dma_addr, block_size,
NS_BIT);
set_cipher_mode(&desc[idx], hw_mode);
set_xor_active(&desc[idx]);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
if (i == 0) {
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_dout_dlli(&desc[idx], tmp_digest_dma_addr,
inter_digestsize, NS_BIT, 0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
idx++;
BUG_ON(idx > FIPS_HMAC_MAX_SEQ_LEN);
rc = send_request(drvdata, &ssi_req, desc, idx, 0);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("send_request() failed (rc=%d)\n", rc);
return rc;
}
idx = 0;
}
}
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, din_dma_addr, data_in_size, NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_dout_dlli(&desc[idx], k0_dma_addr, HASH_LEN_SIZE, NS_BIT, 0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE1);
set_cipher_do(&desc[idx], DO_PAD);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_dout_dlli(&desc[idx], k0_dma_addr, digest_size, NS_BIT, 0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
if (unlikely((hash_mode == DRV_HASH_MD5) ||
(hash_mode == DRV_HASH_SHA384) ||
(hash_mode == DRV_HASH_SHA512))) {
set_bytes_swap(&desc[idx], 1);
} else {
set_cipher_config0(&desc[idx],
HASH_DIGEST_RESULT_LITTLE_ENDIAN);
}
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_din_type(&desc[idx], DMA_DLLI, tmp_digest_dma_addr,
inter_digestsize, NS_BIT);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_din_type(&desc[idx], DMA_DLLI, digest_bytes_len_dma_addr,
HASH_LEN_SIZE, NS_BIT);
set_cipher_config1(&desc[idx], HASH_PADDING_ENABLED);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
idx++;
hw_desc_init(&desc[idx]);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_no_dma(&desc[idx], 0, 0, 1);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, k0_dma_addr, digest_size, NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], hw_mode);
set_dout_dlli(&desc[idx], mac_res_dma_addr, digest_size, NS_BIT, 0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_cipher_config1(&desc[idx], HASH_PADDING_DISABLED);
if (unlikely((hash_mode == DRV_HASH_MD5) ||
(hash_mode == DRV_HASH_SHA384) ||
(hash_mode == DRV_HASH_SHA512))) {
set_bytes_swap(&desc[idx], 1);
} else {
set_cipher_config0(&desc[idx],
HASH_DIGEST_RESULT_LITTLE_ENDIAN);
}
idx++;
BUG_ON(idx > FIPS_HMAC_MAX_SEQ_LEN);
rc = send_request(drvdata, &ssi_req, desc, idx, false);
return rc;
}
enum cc_fips_error
ssi_hmac_fips_power_up_tests(struct ssi_drvdata *drvdata, void *cpu_addr_buffer, dma_addr_t dma_coherent_buffer)
{
enum cc_fips_error error = CC_REE_FIPS_ERROR_OK;
size_t i;
struct fips_hmac_ctx *virt_ctx = (struct fips_hmac_ctx *)cpu_addr_buffer;
dma_addr_t initial_digest_dma_addr = dma_coherent_buffer + offsetof(struct fips_hmac_ctx, initial_digest);
dma_addr_t key_dma_addr = dma_coherent_buffer + offsetof(struct fips_hmac_ctx, key);
dma_addr_t k0_dma_addr = dma_coherent_buffer + offsetof(struct fips_hmac_ctx, k0);
dma_addr_t tmp_digest_dma_addr = dma_coherent_buffer + offsetof(struct fips_hmac_ctx, tmp_digest);
dma_addr_t digest_bytes_len_dma_addr = dma_coherent_buffer + offsetof(struct fips_hmac_ctx, digest_bytes_len);
dma_addr_t din_dma_addr = dma_coherent_buffer + offsetof(struct fips_hmac_ctx, din);
dma_addr_t mac_res_dma_addr = dma_coherent_buffer + offsetof(struct fips_hmac_ctx, mac_res);
for (i = 0; i < FIPS_HMAC_NUM_OF_TESTS; ++i)
{
FipsHmacData *hmac_data = (FipsHmacData *)&FipsHmacDataTable[i];
int rc = 0;
enum drv_hash_hw_mode hw_mode = 0;
int digest_size = 0;
int block_size = 0;
int inter_digestsize = 0;
memset(cpu_addr_buffer, 0, sizeof(struct fips_hmac_ctx));
switch (hmac_data->hash_mode) {
case DRV_HASH_SHA1:
hw_mode = DRV_HASH_HW_SHA1;
digest_size = CC_SHA1_DIGEST_SIZE;
block_size = CC_SHA1_BLOCK_SIZE;
inter_digestsize = CC_SHA1_DIGEST_SIZE;
memcpy(virt_ctx->initial_digest, (void *)sha1_init, CC_SHA1_DIGEST_SIZE);
memcpy(virt_ctx->digest_bytes_len, digest_len_init, HASH_LEN_SIZE);
break;
case DRV_HASH_SHA256:
hw_mode = DRV_HASH_HW_SHA256;
digest_size = CC_SHA256_DIGEST_SIZE;
block_size = CC_SHA256_BLOCK_SIZE;
inter_digestsize = CC_SHA256_DIGEST_SIZE;
memcpy(virt_ctx->initial_digest, (void *)sha256_init, CC_SHA256_DIGEST_SIZE);
memcpy(virt_ctx->digest_bytes_len, digest_len_init, HASH_LEN_SIZE);
break;
#if (CC_SUPPORT_SHA > 256)
case DRV_HASH_SHA512:
hw_mode = DRV_HASH_HW_SHA512;
digest_size = CC_SHA512_DIGEST_SIZE;
block_size = CC_SHA512_BLOCK_SIZE;
inter_digestsize = CC_SHA512_DIGEST_SIZE;
memcpy(virt_ctx->initial_digest, (void *)sha512_init, CC_SHA512_DIGEST_SIZE);
memcpy(virt_ctx->digest_bytes_len, digest_len_sha512_init, HASH_LEN_SIZE);
break;
#endif
default:
error = FIPS_HmacToFipsError(hmac_data->hash_mode);
break;
}
memcpy(virt_ctx->key, hmac_data->key, hmac_data->key_size);
memcpy(virt_ctx->din, hmac_data->data_in, hmac_data->data_in_size);
FIPS_DBG("ssi_hmac_fips_run_test - (i = %d) \n", i);
rc = ssi_hmac_fips_run_test(drvdata,
initial_digest_dma_addr,
key_dma_addr,
hmac_data->key_size,
din_dma_addr,
hmac_data->data_in_size,
mac_res_dma_addr,
hmac_data->hash_mode,
hw_mode,
digest_size,
inter_digestsize,
block_size,
k0_dma_addr,
tmp_digest_dma_addr,
digest_bytes_len_dma_addr);
if (rc != 0)
{
FIPS_LOG("ssi_hmac_fips_run_test %d returned error - rc = %d \n", i, rc);
error = FIPS_HmacToFipsError(hmac_data->hash_mode);
break;
}
if (memcmp(virt_ctx->mac_res, hmac_data->mac_res, digest_size) != 0)
{
FIPS_LOG("comparison error %d - hash_mode=%d digest_size=%d \n", i, hmac_data->hash_mode, digest_size);
FIPS_LOG(" i expected received \n");
FIPS_LOG(" i 0x%08x 0x%08x \n", (size_t)hmac_data->mac_res, (size_t)virt_ctx->mac_res);
for (i = 0; i < digest_size; ++i)
{
FIPS_LOG(" %d 0x%02x 0x%02x \n", i, hmac_data->mac_res[i], virt_ctx->mac_res[i]);
}
error = FIPS_HmacToFipsError(hmac_data->hash_mode);
break;
}
}
return error;
}
static inline int
ssi_ccm_fips_run_test(struct ssi_drvdata *drvdata,
enum drv_crypto_direction direction,
dma_addr_t key_dma_addr,
size_t key_size,
dma_addr_t iv_dma_addr,
dma_addr_t ctr_cnt_0_dma_addr,
dma_addr_t b0_a0_adata_dma_addr,
size_t b0_a0_adata_size,
dma_addr_t din_dma_addr,
size_t din_size,
dma_addr_t dout_dma_addr,
dma_addr_t mac_res_dma_addr)
{
#define FIPS_CCM_MAX_SEQ_LEN 10
int rc;
struct ssi_crypto_req ssi_req = {0};
struct cc_hw_desc desc[FIPS_CCM_MAX_SEQ_LEN];
unsigned int idx = 0;
unsigned int cipher_flow_mode;
if (direction == DRV_CRYPTO_DIRECTION_DECRYPT) {
cipher_flow_mode = AES_to_HASH_and_DOUT;
} else {
cipher_flow_mode = AES_and_HASH;
}
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CTR);
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr,
((key_size == NIST_AESCCM_192_BIT_KEY_SIZE) ?
CC_AES_KEY_SIZE_MAX : key_size), NS_BIT)
set_key_size_aes(&desc[idx], key_size);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CTR);
set_key_size_aes(&desc[idx], key_size);
set_din_type(&desc[idx], DMA_DLLI, iv_dma_addr, AES_BLOCK_SIZE,
NS_BIT);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CBC_MAC);
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr,
((key_size == NIST_AESCCM_192_BIT_KEY_SIZE) ?
CC_AES_KEY_SIZE_MAX : key_size), NS_BIT);
set_key_size_aes(&desc[idx], key_size);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CBC_MAC);
set_key_size_aes(&desc[idx], key_size);
set_din_type(&desc[idx], DMA_DLLI, mac_res_dma_addr,
NIST_AESCCM_TAG_SIZE, NS_BIT);
set_cipher_config0(&desc[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE0);
set_flow_mode(&desc[idx], S_DIN_to_HASH);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, b0_a0_adata_dma_addr,
b0_a0_adata_size, NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, din_dma_addr, din_size, NS_BIT);
set_dout_dlli(&desc[idx], dout_dma_addr, din_size, NS_BIT, 0);
set_flow_mode(&desc[idx], cipher_flow_mode);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CBC_MAC);
set_dout_dlli(&desc[idx], mac_res_dma_addr, NIST_AESCCM_TAG_SIZE,
NS_BIT, 0);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_cipher_config0(&desc[idx], HASH_DIGEST_RESULT_LITTLE_ENDIAN);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_CTR);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_din_type(&desc[idx], DMA_DLLI, ctr_cnt_0_dma_addr, AES_BLOCK_SIZE,
NS_BIT);
set_key_size_aes(&desc[idx], key_size);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_no_dma(&desc[idx], 0, 0, 1);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, mac_res_dma_addr,
NIST_AESCCM_TAG_SIZE, NS_BIT);
set_dout_dlli(&desc[idx], mac_res_dma_addr, NIST_AESCCM_TAG_SIZE,
NS_BIT, 0);
set_flow_mode(&desc[idx], DIN_AES_DOUT);
idx++;
BUG_ON(idx > FIPS_CCM_MAX_SEQ_LEN);
rc = send_request(drvdata, &ssi_req, desc, idx, false);
return rc;
}
enum cc_fips_error
ssi_ccm_fips_power_up_tests(struct ssi_drvdata *drvdata, void *cpu_addr_buffer, dma_addr_t dma_coherent_buffer)
{
enum cc_fips_error error = CC_REE_FIPS_ERROR_OK;
size_t i;
struct fips_ccm_ctx *virt_ctx = (struct fips_ccm_ctx *)cpu_addr_buffer;
dma_addr_t b0_a0_adata_dma_addr = dma_coherent_buffer + offsetof(struct fips_ccm_ctx, b0_a0_adata);
dma_addr_t iv_dma_addr = dma_coherent_buffer + offsetof(struct fips_ccm_ctx, iv);
dma_addr_t ctr_cnt_0_dma_addr = dma_coherent_buffer + offsetof(struct fips_ccm_ctx, ctr_cnt_0);
dma_addr_t key_dma_addr = dma_coherent_buffer + offsetof(struct fips_ccm_ctx, key);
dma_addr_t din_dma_addr = dma_coherent_buffer + offsetof(struct fips_ccm_ctx, din);
dma_addr_t dout_dma_addr = dma_coherent_buffer + offsetof(struct fips_ccm_ctx, dout);
dma_addr_t mac_res_dma_addr = dma_coherent_buffer + offsetof(struct fips_ccm_ctx, mac_res);
for (i = 0; i < FIPS_CCM_NUM_OF_TESTS; ++i)
{
FipsCcmData *ccmData = (FipsCcmData *)&FipsCcmDataTable[i];
int rc = 0;
memset(cpu_addr_buffer, 0, sizeof(struct fips_ccm_ctx));
memcpy(virt_ctx->key, ccmData->key, ccmData->keySize);
memcpy(virt_ctx->din, ccmData->dataIn, ccmData->dataInSize);
{
__be16 data = cpu_to_be16(NIST_AESCCM_TEXT_SIZE);
virt_ctx->b0_a0_adata[0] = NIST_AESCCM_B0_VAL;
memcpy(virt_ctx->b0_a0_adata + 1, ccmData->nonce, NIST_AESCCM_NONCE_SIZE);
memcpy(virt_ctx->b0_a0_adata + 14, (u8 *)&data, sizeof(__be16));
virt_ctx->b0_a0_adata[NIST_AESCCM_IV_SIZE + 0] = (ccmData->adataSize >> 8) & 0xFF;
virt_ctx->b0_a0_adata[NIST_AESCCM_IV_SIZE + 1] = ccmData->adataSize & 0xFF;
memcpy(virt_ctx->b0_a0_adata + NIST_AESCCM_IV_SIZE + 2, ccmData->adata, ccmData->adataSize);
virt_ctx->iv[0] = 1;
memcpy(virt_ctx->iv + 1, ccmData->nonce, NIST_AESCCM_NONCE_SIZE);
virt_ctx->iv[15] = 1;
memcpy(virt_ctx->ctr_cnt_0, virt_ctx->iv, NIST_AESCCM_IV_SIZE);
virt_ctx->ctr_cnt_0[15] = 0;
}
FIPS_DBG("ssi_ccm_fips_run_test - (i = %d) \n", i);
rc = ssi_ccm_fips_run_test(drvdata,
ccmData->direction,
key_dma_addr,
ccmData->keySize,
iv_dma_addr,
ctr_cnt_0_dma_addr,
b0_a0_adata_dma_addr,
FIPS_CCM_B0_A0_ADATA_SIZE,
din_dma_addr,
ccmData->dataInSize,
dout_dma_addr,
mac_res_dma_addr);
if (rc != 0)
{
FIPS_LOG("ssi_ccm_fips_run_test %d returned error - rc = %d \n", i, rc);
error = CC_REE_FIPS_ERROR_AESCCM_PUT;
break;
}
if (memcmp(virt_ctx->dout, ccmData->dataOut, ccmData->dataInSize) != 0)
{
FIPS_LOG("dout comparison error %d - size=%d \n", i, ccmData->dataInSize);
error = CC_REE_FIPS_ERROR_AESCCM_PUT;
break;
}
if (memcmp(virt_ctx->mac_res, ccmData->macResOut, ccmData->tagSize) != 0)
{
FIPS_LOG("mac_res comparison error %d - mac_size=%d \n", i, ccmData->tagSize);
FIPS_LOG(" i expected received \n");
FIPS_LOG(" i 0x%08x 0x%08x \n", (size_t)ccmData->macResOut, (size_t)virt_ctx->mac_res);
for (i = 0; i < ccmData->tagSize; ++i)
{
FIPS_LOG(" %d 0x%02x 0x%02x \n", i, ccmData->macResOut[i], virt_ctx->mac_res[i]);
}
error = CC_REE_FIPS_ERROR_AESCCM_PUT;
break;
}
}
return error;
}
static inline int
ssi_gcm_fips_run_test(struct ssi_drvdata *drvdata,
enum drv_crypto_direction direction,
dma_addr_t key_dma_addr,
size_t key_size,
dma_addr_t hkey_dma_addr,
dma_addr_t block_len_dma_addr,
dma_addr_t iv_inc1_dma_addr,
dma_addr_t iv_inc2_dma_addr,
dma_addr_t adata_dma_addr,
size_t adata_size,
dma_addr_t din_dma_addr,
size_t din_size,
dma_addr_t dout_dma_addr,
dma_addr_t mac_res_dma_addr)
{
#define FIPS_GCM_MAX_SEQ_LEN 15
int rc;
struct ssi_crypto_req ssi_req = {0};
struct cc_hw_desc desc[FIPS_GCM_MAX_SEQ_LEN];
unsigned int idx = 0;
unsigned int cipher_flow_mode;
if (direction == DRV_CRYPTO_DIRECTION_DECRYPT) {
cipher_flow_mode = AES_and_HASH;
} else {
cipher_flow_mode = AES_to_HASH_and_DOUT;
}
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_ECB);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr, key_size, NS_BIT);
set_key_size_aes(&desc[idx], key_size);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_din_const(&desc[idx], 0x0, AES_BLOCK_SIZE);
set_dout_dlli(&desc[idx], hkey_dma_addr, AES_BLOCK_SIZE, NS_BIT, 0);
set_flow_mode(&desc[idx], DIN_AES_DOUT);
idx++;
hw_desc_init(&desc[idx]);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_no_dma(&desc[idx], 0, 0, 1);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, hkey_dma_addr, AES_BLOCK_SIZE,
NS_BIT);
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
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, adata_dma_addr, adata_size, NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_GCTR);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_din_type(&desc[idx], DMA_DLLI, key_dma_addr, key_size, NS_BIT);
set_key_size_aes(&desc[idx], key_size);
set_setup_mode(&desc[idx], SETUP_LOAD_KEY0);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_GCTR);
set_key_size_aes(&desc[idx], key_size);
set_din_type(&desc[idx], DMA_DLLI, iv_inc2_dma_addr, AES_BLOCK_SIZE,
NS_BIT);
set_cipher_config0(&desc[idx], DRV_CRYPTO_DIRECTION_ENCRYPT);
set_setup_mode(&desc[idx], SETUP_LOAD_STATE1);
set_flow_mode(&desc[idx], S_DIN_to_AES);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, din_dma_addr, din_size, NS_BIT);
set_dout_dlli(&desc[idx], dout_dma_addr, din_size, NS_BIT, 0);
set_flow_mode(&desc[idx], cipher_flow_mode);
idx++;
hw_desc_init(&desc[idx]);
set_din_type(&desc[idx], DMA_DLLI, block_len_dma_addr, AES_BLOCK_SIZE,
NS_BIT);
set_flow_mode(&desc[idx], DIN_HASH);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_HASH_HW_GHASH);
set_din_no_dma(&desc[idx], 0, 0xfffff0);
set_dout_dlli(&desc[idx], mac_res_dma_addr, AES_BLOCK_SIZE, NS_BIT, 0);
set_setup_mode(&desc[idx], SETUP_WRITE_STATE0);
set_flow_mode(&desc[idx], S_HASH_to_DOUT);
set_aes_not_hash_mode(&desc[idx]);
idx++;
hw_desc_init(&desc[idx]);
set_cipher_mode(&desc[idx], DRV_CIPHER_GCTR);
set_key_size_aes(&desc[idx], key_size);
set_din_type(&desc[idx], DMA_DLLI, iv_inc1_dma_addr, AES_BLOCK_SIZE,
NS_BIT);
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
set_din_type(&desc[idx], DMA_DLLI, mac_res_dma_addr, AES_BLOCK_SIZE,
NS_BIT);
set_dout_dlli(&desc[idx], mac_res_dma_addr, AES_BLOCK_SIZE, NS_BIT, 0);
set_flow_mode(&desc[idx], DIN_AES_DOUT);
idx++;
BUG_ON(idx > FIPS_GCM_MAX_SEQ_LEN);
rc = send_request(drvdata, &ssi_req, desc, idx, false);
return rc;
}
enum cc_fips_error
ssi_gcm_fips_power_up_tests(struct ssi_drvdata *drvdata, void *cpu_addr_buffer, dma_addr_t dma_coherent_buffer)
{
enum cc_fips_error error = CC_REE_FIPS_ERROR_OK;
size_t i;
struct fips_gcm_ctx *virt_ctx = (struct fips_gcm_ctx *)cpu_addr_buffer;
dma_addr_t adata_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, adata);
dma_addr_t key_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, key);
dma_addr_t hkey_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, hkey);
dma_addr_t din_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, din);
dma_addr_t dout_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, dout);
dma_addr_t mac_res_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, mac_res);
dma_addr_t len_block_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, len_block);
dma_addr_t iv_inc1_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, iv_inc1);
dma_addr_t iv_inc2_dma_addr = dma_coherent_buffer + offsetof(struct fips_gcm_ctx, iv_inc2);
for (i = 0; i < FIPS_GCM_NUM_OF_TESTS; ++i)
{
FipsGcmData *gcmData = (FipsGcmData *)&FipsGcmDataTable[i];
int rc = 0;
memset(cpu_addr_buffer, 0, sizeof(struct fips_gcm_ctx));
memcpy(virt_ctx->key, gcmData->key, gcmData->keySize);
memcpy(virt_ctx->adata, gcmData->adata, gcmData->adataSize);
memcpy(virt_ctx->din, gcmData->dataIn, gcmData->dataInSize);
{
__be64 len_bits;
len_bits = cpu_to_be64(gcmData->adataSize * 8);
memcpy(virt_ctx->len_block, &len_bits, sizeof(len_bits));
len_bits = cpu_to_be64(gcmData->dataInSize * 8);
memcpy(virt_ctx->len_block + 8, &len_bits, sizeof(len_bits));
}
{
__be32 counter = cpu_to_be32(1);
memcpy(virt_ctx->iv_inc1, gcmData->iv, NIST_AESGCM_IV_SIZE);
memcpy(virt_ctx->iv_inc1 + NIST_AESGCM_IV_SIZE, &counter, sizeof(counter));
counter = cpu_to_be32(2);
memcpy(virt_ctx->iv_inc2, gcmData->iv, NIST_AESGCM_IV_SIZE);
memcpy(virt_ctx->iv_inc2 + NIST_AESGCM_IV_SIZE, &counter, sizeof(counter));
}
FIPS_DBG("ssi_gcm_fips_run_test - (i = %d) \n", i);
rc = ssi_gcm_fips_run_test(drvdata,
gcmData->direction,
key_dma_addr,
gcmData->keySize,
hkey_dma_addr,
len_block_dma_addr,
iv_inc1_dma_addr,
iv_inc2_dma_addr,
adata_dma_addr,
gcmData->adataSize,
din_dma_addr,
gcmData->dataInSize,
dout_dma_addr,
mac_res_dma_addr);
if (rc != 0)
{
FIPS_LOG("ssi_gcm_fips_run_test %d returned error - rc = %d \n", i, rc);
error = CC_REE_FIPS_ERROR_AESGCM_PUT;
break;
}
if (gcmData->direction == DRV_CRYPTO_DIRECTION_ENCRYPT) {
if (memcmp(virt_ctx->dout, gcmData->dataOut, gcmData->dataInSize) != 0)
{
FIPS_LOG("dout comparison error %d - size=%d \n", i, gcmData->dataInSize);
FIPS_LOG(" i expected received \n");
FIPS_LOG(" i 0x%08x 0x%08x \n", (size_t)gcmData->dataOut, (size_t)virt_ctx->dout);
for (i = 0; i < gcmData->dataInSize; ++i)
{
FIPS_LOG(" %d 0x%02x 0x%02x \n", i, gcmData->dataOut[i], virt_ctx->dout[i]);
}
error = CC_REE_FIPS_ERROR_AESGCM_PUT;
break;
}
}
if (memcmp(virt_ctx->mac_res, gcmData->macResOut, gcmData->tagSize) != 0)
{
FIPS_LOG("mac_res comparison error %d - mac_size=%d \n", i, gcmData->tagSize);
FIPS_LOG(" i expected received \n");
FIPS_LOG(" i 0x%08x 0x%08x \n", (size_t)gcmData->macResOut, (size_t)virt_ctx->mac_res);
for (i = 0; i < gcmData->tagSize; ++i)
{
FIPS_LOG(" %d 0x%02x 0x%02x \n", i, gcmData->macResOut[i], virt_ctx->mac_res[i]);
}
error = CC_REE_FIPS_ERROR_AESGCM_PUT;
break;
}
}
return error;
}
size_t ssi_fips_max_mem_alloc_size(void)
{
FIPS_DBG("sizeof(struct fips_cipher_ctx) %d \n", sizeof(struct fips_cipher_ctx));
FIPS_DBG("sizeof(struct fips_cmac_ctx) %d \n", sizeof(struct fips_cmac_ctx));
FIPS_DBG("sizeof(struct fips_hash_ctx) %d \n", sizeof(struct fips_hash_ctx));
FIPS_DBG("sizeof(struct fips_hmac_ctx) %d \n", sizeof(struct fips_hmac_ctx));
FIPS_DBG("sizeof(struct fips_ccm_ctx) %d \n", sizeof(struct fips_ccm_ctx));
FIPS_DBG("sizeof(struct fips_gcm_ctx) %d \n", sizeof(struct fips_gcm_ctx));
return sizeof(fips_ctx);
}
