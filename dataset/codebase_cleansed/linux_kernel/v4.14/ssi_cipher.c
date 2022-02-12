static int validate_keys_sizes(struct ssi_ablkcipher_ctx *ctx_p, u32 size)
{
switch (ctx_p->flow_mode) {
case S_DIN_to_AES:
switch (size) {
case CC_AES_128_BIT_KEY_SIZE:
case CC_AES_192_BIT_KEY_SIZE:
if (likely((ctx_p->cipher_mode != DRV_CIPHER_XTS) &&
(ctx_p->cipher_mode != DRV_CIPHER_ESSIV) &&
(ctx_p->cipher_mode != DRV_CIPHER_BITLOCKER)))
return 0;
break;
case CC_AES_256_BIT_KEY_SIZE:
return 0;
case (CC_AES_192_BIT_KEY_SIZE * 2):
case (CC_AES_256_BIT_KEY_SIZE * 2):
if (likely((ctx_p->cipher_mode == DRV_CIPHER_XTS) ||
(ctx_p->cipher_mode == DRV_CIPHER_ESSIV) ||
(ctx_p->cipher_mode == DRV_CIPHER_BITLOCKER)))
return 0;
break;
default:
break;
}
case S_DIN_to_DES:
if (likely(size == DES3_EDE_KEY_SIZE || size == DES_KEY_SIZE))
return 0;
break;
#if SSI_CC_HAS_MULTI2
case S_DIN_to_MULTI2:
if (likely(size == CC_MULTI2_SYSTEM_N_DATA_KEY_SIZE))
return 0;
break;
#endif
default:
break;
}
return -EINVAL;
}
static int validate_data_size(struct ssi_ablkcipher_ctx *ctx_p, unsigned int size)
{
switch (ctx_p->flow_mode) {
case S_DIN_to_AES:
switch (ctx_p->cipher_mode) {
case DRV_CIPHER_XTS:
if ((size >= SSI_MIN_AES_XTS_SIZE) &&
(size <= SSI_MAX_AES_XTS_SIZE) &&
IS_ALIGNED(size, AES_BLOCK_SIZE))
return 0;
break;
case DRV_CIPHER_CBC_CTS:
if (likely(size >= AES_BLOCK_SIZE))
return 0;
break;
case DRV_CIPHER_OFB:
case DRV_CIPHER_CTR:
return 0;
case DRV_CIPHER_ECB:
case DRV_CIPHER_CBC:
case DRV_CIPHER_ESSIV:
case DRV_CIPHER_BITLOCKER:
if (likely(IS_ALIGNED(size, AES_BLOCK_SIZE)))
return 0;
break;
default:
break;
}
break;
case S_DIN_to_DES:
if (likely(IS_ALIGNED(size, DES_BLOCK_SIZE)))
return 0;
break;
#if SSI_CC_HAS_MULTI2
case S_DIN_to_MULTI2:
switch (ctx_p->cipher_mode) {
case DRV_MULTI2_CBC:
if (likely(IS_ALIGNED(size, CC_MULTI2_BLOCK_SIZE)))
return 0;
break;
case DRV_MULTI2_OFB:
return 0;
default:
break;
}
break;
#endif
default:
break;
}
return -EINVAL;
}
static unsigned int get_max_keysize(struct crypto_tfm *tfm)
{
struct ssi_crypto_alg *ssi_alg = container_of(tfm->__crt_alg, struct ssi_crypto_alg, crypto_alg);
if ((ssi_alg->crypto_alg.cra_flags & CRYPTO_ALG_TYPE_MASK) == CRYPTO_ALG_TYPE_ABLKCIPHER)
return ssi_alg->crypto_alg.cra_ablkcipher.max_keysize;
if ((ssi_alg->crypto_alg.cra_flags & CRYPTO_ALG_TYPE_MASK) == CRYPTO_ALG_TYPE_BLKCIPHER)
return ssi_alg->crypto_alg.cra_blkcipher.max_keysize;
return 0;
}
static int ssi_blkcipher_init(struct crypto_tfm *tfm)
{
struct ssi_ablkcipher_ctx *ctx_p = crypto_tfm_ctx(tfm);
struct crypto_alg *alg = tfm->__crt_alg;
struct ssi_crypto_alg *ssi_alg =
container_of(alg, struct ssi_crypto_alg, crypto_alg);
struct device *dev;
int rc = 0;
unsigned int max_key_buf_size = get_max_keysize(tfm);
SSI_LOG_DEBUG("Initializing context @%p for %s\n",
ctx_p, crypto_tfm_alg_name(tfm));
ctx_p->cipher_mode = ssi_alg->cipher_mode;
ctx_p->flow_mode = ssi_alg->flow_mode;
ctx_p->drvdata = ssi_alg->drvdata;
dev = &ctx_p->drvdata->plat_dev->dev;
ctx_p->user.key = kmalloc(max_key_buf_size, GFP_KERNEL | GFP_DMA);
if (!ctx_p->user.key) {
SSI_LOG_ERR("Allocating key buffer in context failed\n");
rc = -ENOMEM;
}
SSI_LOG_DEBUG("Allocated key buffer in context. key=@%p\n",
ctx_p->user.key);
ctx_p->user.key_dma_addr = dma_map_single(dev, (void *)ctx_p->user.key,
max_key_buf_size,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, ctx_p->user.key_dma_addr)) {
SSI_LOG_ERR("Mapping Key %u B at va=%pK for DMA failed\n",
max_key_buf_size, ctx_p->user.key);
return -ENOMEM;
}
SSI_LOG_DEBUG("Mapped key %u B at va=%pK to dma=%pad\n",
max_key_buf_size, ctx_p->user.key,
ctx_p->user.key_dma_addr);
if (ctx_p->cipher_mode == DRV_CIPHER_ESSIV) {
ctx_p->shash_tfm = crypto_alloc_shash("sha256-generic", 0, 0);
if (IS_ERR(ctx_p->shash_tfm)) {
SSI_LOG_ERR("Error allocating hash tfm for ESSIV.\n");
return PTR_ERR(ctx_p->shash_tfm);
}
}
return rc;
}
static void ssi_blkcipher_exit(struct crypto_tfm *tfm)
{
struct ssi_ablkcipher_ctx *ctx_p = crypto_tfm_ctx(tfm);
struct device *dev = &ctx_p->drvdata->plat_dev->dev;
unsigned int max_key_buf_size = get_max_keysize(tfm);
SSI_LOG_DEBUG("Clearing context @%p for %s\n",
crypto_tfm_ctx(tfm), crypto_tfm_alg_name(tfm));
if (ctx_p->cipher_mode == DRV_CIPHER_ESSIV) {
crypto_free_shash(ctx_p->shash_tfm);
ctx_p->shash_tfm = NULL;
}
dma_unmap_single(dev, ctx_p->user.key_dma_addr, max_key_buf_size,
DMA_TO_DEVICE);
SSI_LOG_DEBUG("Unmapped key buffer key_dma_addr=%pad\n",
ctx_p->user.key_dma_addr);
kfree(ctx_p->user.key);
SSI_LOG_DEBUG("Free key buffer in context. key=@%p\n", ctx_p->user.key);
}
static int ssi_verify_3des_keys(const u8 *key, unsigned int keylen)
{
struct tdes_keys *tdes_key = (struct tdes_keys *)key;
if (unlikely((memcmp((u8 *)tdes_key->key1, (u8 *)tdes_key->key2, sizeof(tdes_key->key1)) == 0) ||
(memcmp((u8 *)tdes_key->key3, (u8 *)tdes_key->key2, sizeof(tdes_key->key3)) == 0))) {
return -ENOEXEC;
}
return 0;
}
static enum cc_hw_crypto_key hw_key_to_cc_hw_key(int slot_num)
{
switch (slot_num) {
case 0:
return KFDE0_KEY;
case 1:
return KFDE1_KEY;
case 2:
return KFDE2_KEY;
case 3:
return KFDE3_KEY;
}
return END_OF_KEYS;
}
static inline void
ssi_blkcipher_create_setup_desc(
struct crypto_tfm *tfm,
struct blkcipher_req_ctx *req_ctx,
unsigned int ivsize,
unsigned int nbytes,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct ssi_ablkcipher_ctx *ctx_p = crypto_tfm_ctx(tfm);
int cipher_mode = ctx_p->cipher_mode;
int flow_mode = ctx_p->flow_mode;
int direction = req_ctx->gen_ctx.op_type;
dma_addr_t key_dma_addr = ctx_p->user.key_dma_addr;
unsigned int key_len = ctx_p->keylen;
dma_addr_t iv_dma_addr = req_ctx->gen_ctx.iv_dma_addr;
unsigned int du_size = nbytes;
struct ssi_crypto_alg *ssi_alg = container_of(tfm->__crt_alg, struct ssi_crypto_alg, crypto_alg);
if ((ssi_alg->crypto_alg.cra_flags & CRYPTO_ALG_BULK_MASK) == CRYPTO_ALG_BULK_DU_512)
du_size = 512;
if ((ssi_alg->crypto_alg.cra_flags & CRYPTO_ALG_BULK_MASK) == CRYPTO_ALG_BULK_DU_4096)
du_size = 4096;
switch (cipher_mode) {
case DRV_CIPHER_CBC:
case DRV_CIPHER_CBC_CTS:
case DRV_CIPHER_CTR:
case DRV_CIPHER_OFB:
hw_desc_init(&desc[*seq_size]);
set_din_type(&desc[*seq_size], DMA_DLLI, iv_dma_addr, ivsize,
NS_BIT);
set_cipher_config0(&desc[*seq_size], direction);
set_flow_mode(&desc[*seq_size], flow_mode);
set_cipher_mode(&desc[*seq_size], cipher_mode);
if ((cipher_mode == DRV_CIPHER_CTR) ||
(cipher_mode == DRV_CIPHER_OFB)) {
set_setup_mode(&desc[*seq_size], SETUP_LOAD_STATE1);
} else {
set_setup_mode(&desc[*seq_size], SETUP_LOAD_STATE0);
}
(*seq_size)++;
case DRV_CIPHER_ECB:
hw_desc_init(&desc[*seq_size]);
set_cipher_mode(&desc[*seq_size], cipher_mode);
set_cipher_config0(&desc[*seq_size], direction);
if (flow_mode == S_DIN_to_AES) {
if (ssi_is_hw_key(tfm)) {
set_hw_crypto_key(&desc[*seq_size],
ctx_p->hw.key1_slot);
} else {
set_din_type(&desc[*seq_size], DMA_DLLI,
key_dma_addr, ((key_len == 24) ?
AES_MAX_KEY_SIZE :
key_len), NS_BIT);
}
set_key_size_aes(&desc[*seq_size], key_len);
} else {
set_din_type(&desc[*seq_size], DMA_DLLI, key_dma_addr,
key_len, NS_BIT);
set_key_size_des(&desc[*seq_size], key_len);
}
set_flow_mode(&desc[*seq_size], flow_mode);
set_setup_mode(&desc[*seq_size], SETUP_LOAD_KEY0);
(*seq_size)++;
break;
case DRV_CIPHER_XTS:
case DRV_CIPHER_ESSIV:
case DRV_CIPHER_BITLOCKER:
hw_desc_init(&desc[*seq_size]);
set_cipher_mode(&desc[*seq_size], cipher_mode);
set_cipher_config0(&desc[*seq_size], direction);
if (ssi_is_hw_key(tfm)) {
set_hw_crypto_key(&desc[*seq_size],
ctx_p->hw.key1_slot);
} else {
set_din_type(&desc[*seq_size], DMA_DLLI, key_dma_addr,
(key_len / 2), NS_BIT);
}
set_key_size_aes(&desc[*seq_size], (key_len / 2));
set_flow_mode(&desc[*seq_size], flow_mode);
set_setup_mode(&desc[*seq_size], SETUP_LOAD_KEY0);
(*seq_size)++;
hw_desc_init(&desc[*seq_size]);
set_cipher_mode(&desc[*seq_size], cipher_mode);
set_cipher_config0(&desc[*seq_size], direction);
if (ssi_is_hw_key(tfm)) {
set_hw_crypto_key(&desc[*seq_size],
ctx_p->hw.key2_slot);
} else {
set_din_type(&desc[*seq_size], DMA_DLLI,
(key_dma_addr + (key_len / 2)),
(key_len / 2), NS_BIT);
}
set_xex_data_unit_size(&desc[*seq_size], du_size);
set_flow_mode(&desc[*seq_size], S_DIN_to_AES2);
set_key_size_aes(&desc[*seq_size], (key_len / 2));
set_setup_mode(&desc[*seq_size], SETUP_LOAD_XEX_KEY);
(*seq_size)++;
hw_desc_init(&desc[*seq_size]);
set_setup_mode(&desc[*seq_size], SETUP_LOAD_STATE1);
set_cipher_mode(&desc[*seq_size], cipher_mode);
set_cipher_config0(&desc[*seq_size], direction);
set_key_size_aes(&desc[*seq_size], (key_len / 2));
set_flow_mode(&desc[*seq_size], flow_mode);
set_din_type(&desc[*seq_size], DMA_DLLI, iv_dma_addr,
CC_AES_BLOCK_SIZE, NS_BIT);
(*seq_size)++;
break;
default:
SSI_LOG_ERR("Unsupported cipher mode (%d)\n", cipher_mode);
BUG();
}
}
static inline void ssi_blkcipher_create_multi2_setup_desc(
struct crypto_tfm *tfm,
struct blkcipher_req_ctx *req_ctx,
unsigned int ivsize,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct ssi_ablkcipher_ctx *ctx_p = crypto_tfm_ctx(tfm);
int direction = req_ctx->gen_ctx.op_type;
hw_desc_init(&desc[*seq_size]);
set_cipher_mode(&desc[*seq_size], ctx_p->cipher_mode);
set_cipher_config0(&desc[*seq_size], direction);
set_din_type(&desc[*seq_size], DMA_DLLI, ctx_p->user.key_dma_addr,
CC_MULTI2_SYSTEM_KEY_SIZE, NS_BIT);
set_flow_mode(&desc[*seq_size], ctx_p->flow_mode);
set_setup_mode(&desc[*seq_size], SETUP_LOAD_KEY0);
(*seq_size)++;
hw_desc_init(&desc[*seq_size]);
set_din_type(&desc[*seq_size], DMA_DLLI,
(ctx_p->user.key_dma_addr + CC_MULTI2_SYSTEM_KEY_SIZE),
CC_MULTI2_DATA_KEY_SIZE, NS_BIT);
set_multi2_num_rounds(&desc[*seq_size], ctx_p->key_round_number);
set_flow_mode(&desc[*seq_size], ctx_p->flow_mode);
set_cipher_mode(&desc[*seq_size], ctx_p->cipher_mode);
set_cipher_config0(&desc[*seq_size], direction);
set_setup_mode(&desc[*seq_size], SETUP_LOAD_STATE0);
(*seq_size)++;
hw_desc_init(&desc[*seq_size]);
set_din_type(&desc[*seq_size], DMA_DLLI, req_ctx->gen_ctx.iv_dma_addr,
ivsize, NS_BIT);
set_cipher_config0(&desc[*seq_size], direction);
set_flow_mode(&desc[*seq_size], ctx_p->flow_mode);
set_cipher_mode(&desc[*seq_size], ctx_p->cipher_mode);
set_setup_mode(&desc[*seq_size], SETUP_LOAD_STATE1);
(*seq_size)++;
}
static inline void
ssi_blkcipher_create_data_desc(
struct crypto_tfm *tfm,
struct blkcipher_req_ctx *req_ctx,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes,
void *areq,
struct cc_hw_desc desc[],
unsigned int *seq_size)
{
struct ssi_ablkcipher_ctx *ctx_p = crypto_tfm_ctx(tfm);
unsigned int flow_mode = ctx_p->flow_mode;
switch (ctx_p->flow_mode) {
case S_DIN_to_AES:
flow_mode = DIN_AES_DOUT;
break;
case S_DIN_to_DES:
flow_mode = DIN_DES_DOUT;
break;
#if SSI_CC_HAS_MULTI2
case S_DIN_to_MULTI2:
flow_mode = DIN_MULTI2_DOUT;
break;
#endif
default:
SSI_LOG_ERR("invalid flow mode, flow_mode = %d\n", flow_mode);
return;
}
if (likely(req_ctx->dma_buf_type == SSI_DMA_BUF_DLLI)) {
SSI_LOG_DEBUG(" data params addr %pad length 0x%X\n",
sg_dma_address(src), nbytes);
SSI_LOG_DEBUG(" data params addr %pad length 0x%X\n",
sg_dma_address(dst), nbytes);
hw_desc_init(&desc[*seq_size]);
set_din_type(&desc[*seq_size], DMA_DLLI, sg_dma_address(src),
nbytes, NS_BIT);
set_dout_dlli(&desc[*seq_size], sg_dma_address(dst),
nbytes, NS_BIT, (!areq ? 0 : 1));
if (areq)
set_queue_last_ind(&desc[*seq_size]);
set_flow_mode(&desc[*seq_size], flow_mode);
(*seq_size)++;
} else {
SSI_LOG_DEBUG(" bypass params addr %pad "
"length 0x%X addr 0x%08X\n",
req_ctx->mlli_params.mlli_dma_addr,
req_ctx->mlli_params.mlli_len,
(unsigned int)ctx_p->drvdata->mlli_sram_addr);
hw_desc_init(&desc[*seq_size]);
set_din_type(&desc[*seq_size], DMA_DLLI,
req_ctx->mlli_params.mlli_dma_addr,
req_ctx->mlli_params.mlli_len, NS_BIT);
set_dout_sram(&desc[*seq_size],
ctx_p->drvdata->mlli_sram_addr,
req_ctx->mlli_params.mlli_len);
set_flow_mode(&desc[*seq_size], BYPASS);
(*seq_size)++;
hw_desc_init(&desc[*seq_size]);
set_din_type(&desc[*seq_size], DMA_MLLI,
ctx_p->drvdata->mlli_sram_addr,
req_ctx->in_mlli_nents, NS_BIT);
if (req_ctx->out_nents == 0) {
SSI_LOG_DEBUG(" din/dout params addr 0x%08X "
"addr 0x%08X\n",
(unsigned int)ctx_p->drvdata->mlli_sram_addr,
(unsigned int)ctx_p->drvdata->mlli_sram_addr);
set_dout_mlli(&desc[*seq_size],
ctx_p->drvdata->mlli_sram_addr,
req_ctx->in_mlli_nents, NS_BIT,
(!areq ? 0 : 1));
} else {
SSI_LOG_DEBUG(" din/dout params "
"addr 0x%08X addr 0x%08X\n",
(unsigned int)ctx_p->drvdata->mlli_sram_addr,
(unsigned int)ctx_p->drvdata->mlli_sram_addr +
(u32)LLI_ENTRY_BYTE_SIZE *
req_ctx->in_nents);
set_dout_mlli(&desc[*seq_size],
(ctx_p->drvdata->mlli_sram_addr +
(LLI_ENTRY_BYTE_SIZE *
req_ctx->in_mlli_nents)),
req_ctx->out_mlli_nents, NS_BIT,
(!areq ? 0 : 1));
}
if (areq)
set_queue_last_ind(&desc[*seq_size]);
set_flow_mode(&desc[*seq_size], flow_mode);
(*seq_size)++;
}
}
static int ssi_blkcipher_complete(struct device *dev,
struct ssi_ablkcipher_ctx *ctx_p,
struct blkcipher_req_ctx *req_ctx,
struct scatterlist *dst,
struct scatterlist *src,
unsigned int ivsize,
void *areq,
void __iomem *cc_base)
{
int completion_error = 0;
u32 inflight_counter;
struct ablkcipher_request *req = (struct ablkcipher_request *)areq;
ssi_buffer_mgr_unmap_blkcipher_request(dev, req_ctx, ivsize, src, dst);
inflight_counter = ctx_p->drvdata->inflight_counter;
if (ctx_p->flow_mode == BYPASS && ctx_p->drvdata->inflight_counter > 0)
ctx_p->drvdata->inflight_counter--;
if (areq) {
if (req_ctx->gen_ctx.op_type == DRV_CRYPTO_DIRECTION_DECRYPT) {
memcpy(req->info, req_ctx->backup_info, ivsize);
kfree(req_ctx->backup_info);
} else {
scatterwalk_map_and_copy(req->info, req->dst,
(req->nbytes - ivsize),
ivsize, 0);
}
ablkcipher_request_complete(areq, completion_error);
return 0;
}
return completion_error;
}
static int ssi_blkcipher_process(
struct crypto_tfm *tfm,
struct blkcipher_req_ctx *req_ctx,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes,
void *info,
unsigned int ivsize,
void *areq,
enum drv_crypto_direction direction)
{
struct ssi_ablkcipher_ctx *ctx_p = crypto_tfm_ctx(tfm);
struct device *dev = &ctx_p->drvdata->plat_dev->dev;
struct cc_hw_desc desc[MAX_ABLKCIPHER_SEQ_LEN];
struct ssi_crypto_req ssi_req = {};
int rc, seq_len = 0, cts_restore_flag = 0;
SSI_LOG_DEBUG("%s areq=%p info=%p nbytes=%d\n",
((direction == DRV_CRYPTO_DIRECTION_ENCRYPT) ? "Encrypt" : "Decrypt"),
areq, info, nbytes);
if (unlikely(validate_data_size(ctx_p, nbytes))) {
SSI_LOG_ERR("Unsupported data size %d.\n", nbytes);
crypto_tfm_set_flags(tfm, CRYPTO_TFM_RES_BAD_BLOCK_LEN);
rc = -EINVAL;
goto exit_process;
}
if (nbytes == 0) {
rc = 0;
goto exit_process;
}
if (((nbytes % AES_BLOCK_SIZE) == 0) && (ctx_p->cipher_mode == DRV_CIPHER_CBC_CTS)) {
ctx_p->cipher_mode = DRV_CIPHER_CBC;
cts_restore_flag = 1;
}
ssi_req.user_cb = (void *)ssi_ablkcipher_complete;
ssi_req.user_arg = (void *)areq;
#ifdef ENABLE_CYCLE_COUNT
ssi_req.op_type = (direction == DRV_CRYPTO_DIRECTION_DECRYPT) ?
STAT_OP_TYPE_DECODE : STAT_OP_TYPE_ENCODE;
#endif
req_ctx->gen_ctx.op_type = direction;
rc = ssi_buffer_mgr_map_blkcipher_request(ctx_p->drvdata, req_ctx, ivsize, nbytes, info, src, dst);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("map_request() failed\n");
goto exit_process;
}
#if SSI_CC_HAS_MULTI2
if (ctx_p->flow_mode == S_DIN_to_MULTI2)
ssi_blkcipher_create_multi2_setup_desc(tfm, req_ctx, ivsize,
desc, &seq_len);
else
#endif
ssi_blkcipher_create_setup_desc(tfm, req_ctx, ivsize, nbytes,
desc, &seq_len);
ssi_blkcipher_create_data_desc(tfm, req_ctx, dst, src, nbytes, areq,
desc, &seq_len);
if (req_ctx->is_giv) {
ssi_req.ivgen_dma_addr[0] = req_ctx->gen_ctx.iv_dma_addr;
ssi_req.ivgen_dma_addr_len = 1;
ssi_req.ivgen_size = ivsize;
}
rc = send_request(ctx_p->drvdata, &ssi_req, desc, seq_len, (!areq) ? 0 : 1);
if (areq) {
if (unlikely(rc != -EINPROGRESS)) {
ssi_buffer_mgr_unmap_blkcipher_request(dev, req_ctx, ivsize, src, dst);
}
} else {
if (rc != 0) {
ssi_buffer_mgr_unmap_blkcipher_request(dev, req_ctx, ivsize, src, dst);
} else {
rc = ssi_blkcipher_complete(dev, ctx_p, req_ctx, dst,
src, ivsize, NULL,
ctx_p->drvdata->cc_base);
}
}
exit_process:
if (cts_restore_flag != 0)
ctx_p->cipher_mode = DRV_CIPHER_CBC_CTS;
if (rc != -EINPROGRESS)
kfree(req_ctx->backup_info);
return rc;
}
static void ssi_ablkcipher_complete(struct device *dev, void *ssi_req, void __iomem *cc_base)
{
struct ablkcipher_request *areq = (struct ablkcipher_request *)ssi_req;
struct blkcipher_req_ctx *req_ctx = ablkcipher_request_ctx(areq);
struct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(areq);
struct ssi_ablkcipher_ctx *ctx_p = crypto_ablkcipher_ctx(tfm);
unsigned int ivsize = crypto_ablkcipher_ivsize(tfm);
ssi_blkcipher_complete(dev, ctx_p, req_ctx, areq->dst, areq->src,
ivsize, areq, cc_base);
}
static int ssi_ablkcipher_init(struct crypto_tfm *tfm)
{
struct ablkcipher_tfm *ablktfm = &tfm->crt_ablkcipher;
ablktfm->reqsize = sizeof(struct blkcipher_req_ctx);
return ssi_blkcipher_init(tfm);
}
static int ssi_ablkcipher_setkey(struct crypto_ablkcipher *tfm,
const u8 *key,
unsigned int keylen)
{
return ssi_blkcipher_setkey(crypto_ablkcipher_tfm(tfm), key, keylen);
}
static int ssi_ablkcipher_encrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *ablk_tfm = crypto_ablkcipher_reqtfm(req);
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(ablk_tfm);
struct blkcipher_req_ctx *req_ctx = ablkcipher_request_ctx(req);
unsigned int ivsize = crypto_ablkcipher_ivsize(ablk_tfm);
req_ctx->is_giv = false;
return ssi_blkcipher_process(tfm, req_ctx, req->dst, req->src, req->nbytes, req->info, ivsize, (void *)req, DRV_CRYPTO_DIRECTION_ENCRYPT);
}
static int ssi_ablkcipher_decrypt(struct ablkcipher_request *req)
{
struct crypto_ablkcipher *ablk_tfm = crypto_ablkcipher_reqtfm(req);
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(ablk_tfm);
struct blkcipher_req_ctx *req_ctx = ablkcipher_request_ctx(req);
unsigned int ivsize = crypto_ablkcipher_ivsize(ablk_tfm);
req_ctx->backup_info = kmalloc(ivsize, GFP_KERNEL);
if (!req_ctx->backup_info)
return -ENOMEM;
scatterwalk_map_and_copy(req_ctx->backup_info, req->src,
(req->nbytes - ivsize), ivsize, 0);
req_ctx->is_giv = false;
return ssi_blkcipher_process(tfm, req_ctx, req->dst, req->src, req->nbytes, req->info, ivsize, (void *)req, DRV_CRYPTO_DIRECTION_DECRYPT);
}
static
struct ssi_crypto_alg *ssi_ablkcipher_create_alg(struct ssi_alg_template *template)
{
struct ssi_crypto_alg *t_alg;
struct crypto_alg *alg;
t_alg = kzalloc(sizeof(*t_alg), GFP_KERNEL);
if (!t_alg) {
SSI_LOG_ERR("failed to allocate t_alg\n");
return ERR_PTR(-ENOMEM);
}
alg = &t_alg->crypto_alg;
snprintf(alg->cra_name, CRYPTO_MAX_ALG_NAME, "%s", template->name);
snprintf(alg->cra_driver_name, CRYPTO_MAX_ALG_NAME, "%s",
template->driver_name);
alg->cra_module = THIS_MODULE;
alg->cra_priority = SSI_CRA_PRIO;
alg->cra_blocksize = template->blocksize;
alg->cra_alignmask = 0;
alg->cra_ctxsize = sizeof(struct ssi_ablkcipher_ctx);
alg->cra_init = ssi_ablkcipher_init;
alg->cra_exit = ssi_blkcipher_exit;
alg->cra_type = &crypto_ablkcipher_type;
alg->cra_ablkcipher = template->template_ablkcipher;
alg->cra_flags = CRYPTO_ALG_ASYNC | CRYPTO_ALG_KERN_DRIVER_ONLY |
template->type;
t_alg->cipher_mode = template->cipher_mode;
t_alg->flow_mode = template->flow_mode;
return t_alg;
}
int ssi_ablkcipher_free(struct ssi_drvdata *drvdata)
{
struct ssi_crypto_alg *t_alg, *n;
struct ssi_blkcipher_handle *blkcipher_handle =
drvdata->blkcipher_handle;
struct device *dev;
dev = &drvdata->plat_dev->dev;
if (blkcipher_handle) {
list_for_each_entry_safe(t_alg, n,
&blkcipher_handle->blkcipher_alg_list,
entry) {
crypto_unregister_alg(&t_alg->crypto_alg);
list_del(&t_alg->entry);
kfree(t_alg);
}
kfree(blkcipher_handle);
drvdata->blkcipher_handle = NULL;
}
return 0;
}
int ssi_ablkcipher_alloc(struct ssi_drvdata *drvdata)
{
struct ssi_blkcipher_handle *ablkcipher_handle;
struct ssi_crypto_alg *t_alg;
int rc = -ENOMEM;
int alg;
ablkcipher_handle = kmalloc(sizeof(*ablkcipher_handle), GFP_KERNEL);
if (!ablkcipher_handle)
return -ENOMEM;
drvdata->blkcipher_handle = ablkcipher_handle;
INIT_LIST_HEAD(&ablkcipher_handle->blkcipher_alg_list);
SSI_LOG_DEBUG("Number of algorithms = %zu\n", ARRAY_SIZE(blkcipher_algs));
for (alg = 0; alg < ARRAY_SIZE(blkcipher_algs); alg++) {
SSI_LOG_DEBUG("creating %s\n", blkcipher_algs[alg].driver_name);
t_alg = ssi_ablkcipher_create_alg(&blkcipher_algs[alg]);
if (IS_ERR(t_alg)) {
rc = PTR_ERR(t_alg);
SSI_LOG_ERR("%s alg allocation failed\n",
blkcipher_algs[alg].driver_name);
goto fail0;
}
t_alg->drvdata = drvdata;
SSI_LOG_DEBUG("registering %s\n", blkcipher_algs[alg].driver_name);
rc = crypto_register_alg(&t_alg->crypto_alg);
SSI_LOG_DEBUG("%s alg registration rc = %x\n",
t_alg->crypto_alg.cra_driver_name, rc);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("%s alg registration failed\n",
t_alg->crypto_alg.cra_driver_name);
kfree(t_alg);
goto fail0;
} else {
list_add_tail(&t_alg->entry,
&ablkcipher_handle->blkcipher_alg_list);
SSI_LOG_DEBUG("Registered %s\n",
t_alg->crypto_alg.cra_driver_name);
}
}
return 0;
fail0:
ssi_ablkcipher_free(drvdata);
return rc;
}
