static int ssi_ivgen_generate_pool(
struct ssi_ivgen_ctx *ivgen_ctx,
HwDesc_s iv_seq[],
unsigned int *iv_seq_len)
{
unsigned int idx = *iv_seq_len;
if ( (*iv_seq_len + SSI_IVPOOL_GEN_SEQ_LEN) > SSI_IVPOOL_SEQ_LEN) {
return -EINVAL;
}
HW_DESC_INIT(&iv_seq[idx]);
HW_DESC_SET_DIN_SRAM(&iv_seq[idx], ivgen_ctx->ctr_key, AES_KEYSIZE_128);
HW_DESC_SET_SETUP_MODE(&iv_seq[idx], SETUP_LOAD_KEY0);
HW_DESC_SET_CIPHER_CONFIG0(&iv_seq[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
HW_DESC_SET_FLOW_MODE(&iv_seq[idx], S_DIN_to_AES);
HW_DESC_SET_KEY_SIZE_AES(&iv_seq[idx], CC_AES_128_BIT_KEY_SIZE);
HW_DESC_SET_CIPHER_MODE(&iv_seq[idx], DRV_CIPHER_CTR);
idx++;
HW_DESC_INIT(&iv_seq[idx]);
HW_DESC_SET_DIN_SRAM(&iv_seq[idx], ivgen_ctx->ctr_iv, CC_AES_IV_SIZE);
HW_DESC_SET_CIPHER_CONFIG0(&iv_seq[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
HW_DESC_SET_FLOW_MODE(&iv_seq[idx], S_DIN_to_AES);
HW_DESC_SET_SETUP_MODE(&iv_seq[idx], SETUP_LOAD_STATE1);
HW_DESC_SET_KEY_SIZE_AES(&iv_seq[idx], CC_AES_128_BIT_KEY_SIZE);
HW_DESC_SET_CIPHER_MODE(&iv_seq[idx], DRV_CIPHER_CTR);
idx++;
HW_DESC_INIT(&iv_seq[idx]);
HW_DESC_SET_DIN_CONST(&iv_seq[idx], 0, CC_AES_IV_SIZE);
HW_DESC_SET_DOUT_SRAM(&iv_seq[idx], ivgen_ctx->pool, CC_AES_IV_SIZE);
HW_DESC_SET_FLOW_MODE(&iv_seq[idx], DIN_AES_DOUT);
idx++;
HW_DESC_INIT(&iv_seq[idx]);
HW_DESC_SET_DIN_CONST(&iv_seq[idx], 0, SSI_IVPOOL_SIZE);
HW_DESC_SET_DOUT_SRAM(&iv_seq[idx], ivgen_ctx->pool, SSI_IVPOOL_SIZE);
HW_DESC_SET_FLOW_MODE(&iv_seq[idx], DIN_AES_DOUT);
idx++;
*iv_seq_len = idx;
ivgen_ctx->next_iv_ofs = SSI_IVPOOL_META_SIZE;
return 0;
}
int ssi_ivgen_init_sram_pool(struct ssi_drvdata *drvdata)
{
struct ssi_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
HwDesc_s iv_seq[SSI_IVPOOL_SEQ_LEN];
unsigned int iv_seq_len = 0;
int rc;
get_random_bytes(ivgen_ctx->pool_meta, SSI_IVPOOL_META_SIZE);
ivgen_ctx->ctr_key = ivgen_ctx->pool;
ivgen_ctx->ctr_iv = ivgen_ctx->pool + AES_KEYSIZE_128;
HW_DESC_INIT(&iv_seq[iv_seq_len]);
HW_DESC_SET_DIN_TYPE(&iv_seq[iv_seq_len], DMA_DLLI,
ivgen_ctx->pool_meta_dma, SSI_IVPOOL_META_SIZE,
NS_BIT);
HW_DESC_SET_DOUT_SRAM(&iv_seq[iv_seq_len], ivgen_ctx->pool,
SSI_IVPOOL_META_SIZE);
HW_DESC_SET_FLOW_MODE(&iv_seq[iv_seq_len], BYPASS);
iv_seq_len++;
rc = ssi_ivgen_generate_pool(ivgen_ctx, iv_seq, &iv_seq_len);
if (unlikely(rc != 0)) {
return rc;
}
return send_request_init(drvdata, iv_seq, iv_seq_len);
}
void ssi_ivgen_fini(struct ssi_drvdata *drvdata)
{
struct ssi_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
struct device *device = &(drvdata->plat_dev->dev);
if (ivgen_ctx == NULL)
return;
if (ivgen_ctx->pool_meta != NULL) {
memset(ivgen_ctx->pool_meta, 0, SSI_IVPOOL_META_SIZE);
SSI_RESTORE_DMA_ADDR_TO_48BIT(ivgen_ctx->pool_meta_dma);
dma_free_coherent(device, SSI_IVPOOL_META_SIZE,
ivgen_ctx->pool_meta, ivgen_ctx->pool_meta_dma);
}
ivgen_ctx->pool = NULL_SRAM_ADDR;
kfree(ivgen_ctx);
}
int ssi_ivgen_init(struct ssi_drvdata *drvdata)
{
struct ssi_ivgen_ctx *ivgen_ctx;
struct device *device = &drvdata->plat_dev->dev;
int rc;
drvdata->ivgen_handle = kzalloc(sizeof(struct ssi_ivgen_ctx), GFP_KERNEL);
if (!drvdata->ivgen_handle) {
SSI_LOG_ERR("Not enough memory to allocate IVGEN context "
"(%zu B)\n", sizeof(struct ssi_ivgen_ctx));
rc = -ENOMEM;
goto out;
}
ivgen_ctx = drvdata->ivgen_handle;
ivgen_ctx->pool_meta = dma_alloc_coherent(device, SSI_IVPOOL_META_SIZE,
&ivgen_ctx->pool_meta_dma, GFP_KERNEL);
if (!ivgen_ctx->pool_meta) {
SSI_LOG_ERR("Not enough memory to allocate DMA of pool_meta "
"(%u B)\n", SSI_IVPOOL_META_SIZE);
rc = -ENOMEM;
goto out;
}
SSI_UPDATE_DMA_ADDR_TO_48BIT(ivgen_ctx->pool_meta_dma,
SSI_IVPOOL_META_SIZE);
ivgen_ctx->pool = ssi_sram_mgr_alloc(drvdata, SSI_IVPOOL_SIZE);
if (ivgen_ctx->pool == NULL_SRAM_ADDR) {
SSI_LOG_ERR("SRAM pool exhausted\n");
rc = -ENOMEM;
goto out;
}
return ssi_ivgen_init_sram_pool(drvdata);
out:
ssi_ivgen_fini(drvdata);
return rc;
}
int ssi_ivgen_getiv(
struct ssi_drvdata *drvdata,
dma_addr_t iv_out_dma[],
unsigned int iv_out_dma_len,
unsigned int iv_out_size,
HwDesc_s iv_seq[],
unsigned int *iv_seq_len)
{
struct ssi_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
unsigned int idx = *iv_seq_len;
unsigned int t;
if ((iv_out_size != CC_AES_IV_SIZE) &&
(iv_out_size != CTR_RFC3686_IV_SIZE)) {
return -EINVAL;
}
if ( (iv_out_dma_len + 1) > SSI_IVPOOL_SEQ_LEN) {
return -EINVAL;
}
if ( iv_out_dma_len > SSI_MAX_IVGEN_DMA_ADDRESSES) {
return -EINVAL;
}
for (t = 0; t < iv_out_dma_len; t++) {
HW_DESC_INIT(&iv_seq[idx]);
HW_DESC_SET_DIN_SRAM(&iv_seq[idx],
ivgen_ctx->pool + ivgen_ctx->next_iv_ofs,
iv_out_size);
HW_DESC_SET_DOUT_DLLI(&iv_seq[idx], iv_out_dma[t],
iv_out_size, NS_BIT, 0);
HW_DESC_SET_FLOW_MODE(&iv_seq[idx], BYPASS);
idx++;
}
HW_DESC_INIT(&iv_seq[idx]);
HW_DESC_SET_DIN_NO_DMA(&iv_seq[idx], 0, 0xfffff0);
HW_DESC_SET_DOUT_NO_DMA(&iv_seq[idx], 0, 0, 1);
idx++;
*iv_seq_len = idx;
ivgen_ctx->next_iv_ofs += iv_out_size;
if ((SSI_IVPOOL_SIZE - ivgen_ctx->next_iv_ofs) < CC_AES_IV_SIZE) {
SSI_LOG_DEBUG("Pool exhausted, regenerating iv-pool\n");
return ssi_ivgen_generate_pool(ivgen_ctx, iv_seq, iv_seq_len);
}
return 0;
}
