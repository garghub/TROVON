static int ssi_ivgen_generate_pool(
struct ssi_ivgen_ctx *ivgen_ctx,
struct cc_hw_desc iv_seq[],
unsigned int *iv_seq_len)
{
unsigned int idx = *iv_seq_len;
if ((*iv_seq_len + SSI_IVPOOL_GEN_SEQ_LEN) > SSI_IVPOOL_SEQ_LEN) {
return -EINVAL;
}
hw_desc_init(&iv_seq[idx]);
set_din_sram(&iv_seq[idx], ivgen_ctx->ctr_key, AES_KEYSIZE_128);
set_setup_mode(&iv_seq[idx], SETUP_LOAD_KEY0);
set_cipher_config0(&iv_seq[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_flow_mode(&iv_seq[idx], S_DIN_to_AES);
set_key_size_aes(&iv_seq[idx], CC_AES_128_BIT_KEY_SIZE);
set_cipher_mode(&iv_seq[idx], DRV_CIPHER_CTR);
idx++;
hw_desc_init(&iv_seq[idx]);
set_din_sram(&iv_seq[idx], ivgen_ctx->ctr_iv, CC_AES_IV_SIZE);
set_cipher_config0(&iv_seq[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
set_flow_mode(&iv_seq[idx], S_DIN_to_AES);
set_setup_mode(&iv_seq[idx], SETUP_LOAD_STATE1);
set_key_size_aes(&iv_seq[idx], CC_AES_128_BIT_KEY_SIZE);
set_cipher_mode(&iv_seq[idx], DRV_CIPHER_CTR);
idx++;
hw_desc_init(&iv_seq[idx]);
set_din_const(&iv_seq[idx], 0, CC_AES_IV_SIZE);
set_dout_sram(&iv_seq[idx], ivgen_ctx->pool, CC_AES_IV_SIZE);
set_flow_mode(&iv_seq[idx], DIN_AES_DOUT);
idx++;
hw_desc_init(&iv_seq[idx]);
set_din_const(&iv_seq[idx], 0, SSI_IVPOOL_SIZE);
set_dout_sram(&iv_seq[idx], ivgen_ctx->pool, SSI_IVPOOL_SIZE);
set_flow_mode(&iv_seq[idx], DIN_AES_DOUT);
idx++;
*iv_seq_len = idx;
ivgen_ctx->next_iv_ofs = SSI_IVPOOL_META_SIZE;
return 0;
}
int ssi_ivgen_init_sram_pool(struct ssi_drvdata *drvdata)
{
struct ssi_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
struct cc_hw_desc iv_seq[SSI_IVPOOL_SEQ_LEN];
unsigned int iv_seq_len = 0;
int rc;
get_random_bytes(ivgen_ctx->pool_meta, SSI_IVPOOL_META_SIZE);
ivgen_ctx->ctr_key = ivgen_ctx->pool;
ivgen_ctx->ctr_iv = ivgen_ctx->pool + AES_KEYSIZE_128;
hw_desc_init(&iv_seq[iv_seq_len]);
set_din_type(&iv_seq[iv_seq_len], DMA_DLLI, ivgen_ctx->pool_meta_dma,
SSI_IVPOOL_META_SIZE, NS_BIT);
set_dout_sram(&iv_seq[iv_seq_len], ivgen_ctx->pool,
SSI_IVPOOL_META_SIZE);
set_flow_mode(&iv_seq[iv_seq_len], BYPASS);
iv_seq_len++;
rc = ssi_ivgen_generate_pool(ivgen_ctx, iv_seq, &iv_seq_len);
if (unlikely(rc != 0))
return rc;
return send_request_init(drvdata, iv_seq, iv_seq_len);
}
void ssi_ivgen_fini(struct ssi_drvdata *drvdata)
{
struct ssi_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
struct device *device = &(drvdata->plat_dev->dev);
if (!ivgen_ctx)
return;
if (ivgen_ctx->pool_meta) {
memset(ivgen_ctx->pool_meta, 0, SSI_IVPOOL_META_SIZE);
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
struct cc_hw_desc iv_seq[],
unsigned int *iv_seq_len)
{
struct ssi_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
unsigned int idx = *iv_seq_len;
unsigned int t;
if ((iv_out_size != CC_AES_IV_SIZE) &&
(iv_out_size != CTR_RFC3686_IV_SIZE)) {
return -EINVAL;
}
if ((iv_out_dma_len + 1) > SSI_IVPOOL_SEQ_LEN) {
return -EINVAL;
}
if (iv_out_dma_len > SSI_MAX_IVGEN_DMA_ADDRESSES) {
return -EINVAL;
}
for (t = 0; t < iv_out_dma_len; t++) {
hw_desc_init(&iv_seq[idx]);
set_din_sram(&iv_seq[idx], (ivgen_ctx->pool +
ivgen_ctx->next_iv_ofs),
iv_out_size);
set_dout_dlli(&iv_seq[idx], iv_out_dma[t], iv_out_size,
NS_BIT, 0);
set_flow_mode(&iv_seq[idx], BYPASS);
idx++;
}
hw_desc_init(&iv_seq[idx]);
set_din_no_dma(&iv_seq[idx], 0, 0xfffff0);
set_dout_no_dma(&iv_seq[idx], 0, 0, 1);
idx++;
*iv_seq_len = idx;
ivgen_ctx->next_iv_ofs += iv_out_size;
if ((SSI_IVPOOL_SIZE - ivgen_ctx->next_iv_ofs) < CC_AES_IV_SIZE) {
SSI_LOG_DEBUG("Pool exhausted, regenerating iv-pool\n");
return ssi_ivgen_generate_pool(ivgen_ctx, iv_seq, iv_seq_len);
}
return 0;
}
