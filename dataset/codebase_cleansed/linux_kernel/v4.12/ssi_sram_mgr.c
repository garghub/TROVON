void ssi_sram_mgr_fini(struct ssi_drvdata *drvdata)
{
struct ssi_sram_mgr_ctx *smgr_ctx = drvdata->sram_mgr_handle;
if (smgr_ctx != NULL) {
memset(smgr_ctx, 0, sizeof(struct ssi_sram_mgr_ctx));
kfree(smgr_ctx);
}
}
int ssi_sram_mgr_init(struct ssi_drvdata *drvdata)
{
struct ssi_sram_mgr_ctx *smgr_ctx;
int rc;
drvdata->sram_mgr_handle = kzalloc(
sizeof(struct ssi_sram_mgr_ctx), GFP_KERNEL);
if (!drvdata->sram_mgr_handle) {
SSI_LOG_ERR("Not enough memory to allocate SRAM_MGR ctx (%zu)\n",
sizeof(struct ssi_sram_mgr_ctx));
rc = -ENOMEM;
goto out;
}
smgr_ctx = drvdata->sram_mgr_handle;
smgr_ctx->sram_free_offset = 0;
return 0;
out:
ssi_sram_mgr_fini(drvdata);
return rc;
}
ssi_sram_addr_t ssi_sram_mgr_alloc(struct ssi_drvdata *drvdata, uint32_t size)
{
struct ssi_sram_mgr_ctx *smgr_ctx = drvdata->sram_mgr_handle;
ssi_sram_addr_t p;
if (unlikely((size & 0x3) != 0)) {
SSI_LOG_ERR("Requested buffer size (%u) is not multiple of 4",
size);
return NULL_SRAM_ADDR;
}
if (unlikely(size > (SSI_CC_SRAM_SIZE - smgr_ctx->sram_free_offset))) {
SSI_LOG_ERR("Not enough space to allocate %u B (at offset %llu)\n",
size, smgr_ctx->sram_free_offset);
return NULL_SRAM_ADDR;
}
p = smgr_ctx->sram_free_offset;
smgr_ctx->sram_free_offset += size;
SSI_LOG_DEBUG("Allocated %u B @ %u\n", size, (unsigned int)p);
return p;
}
void ssi_sram_mgr_const2sram_desc(
const uint32_t *src, ssi_sram_addr_t dst,
unsigned int nelement,
HwDesc_s *seq, unsigned int *seq_len)
{
uint32_t i;
unsigned int idx = *seq_len;
for (i = 0; i < nelement; i++, idx++) {
HW_DESC_INIT(&seq[idx]);
HW_DESC_SET_DIN_CONST(&seq[idx], src[i], sizeof(uint32_t));
HW_DESC_SET_DOUT_SRAM(&seq[idx], dst + (i * sizeof(uint32_t)), sizeof(uint32_t));
HW_DESC_SET_FLOW_MODE(&seq[idx], BYPASS);
}
*seq_len = idx;
}
