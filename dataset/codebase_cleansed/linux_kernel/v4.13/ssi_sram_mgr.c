void ssi_sram_mgr_fini(struct ssi_drvdata *drvdata)
{
struct ssi_sram_mgr_ctx *smgr_ctx = drvdata->sram_mgr_handle;
if (smgr_ctx) {
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
ssi_sram_addr_t ssi_sram_mgr_alloc(struct ssi_drvdata *drvdata, u32 size)
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
const u32 *src, ssi_sram_addr_t dst,
unsigned int nelement,
struct cc_hw_desc *seq, unsigned int *seq_len)
{
u32 i;
unsigned int idx = *seq_len;
for (i = 0; i < nelement; i++, idx++) {
hw_desc_init(&seq[idx]);
set_din_const(&seq[idx], src[i], sizeof(u32));
set_dout_sram(&seq[idx], dst + (i * sizeof(u32)), sizeof(u32));
set_flow_mode(&seq[idx], BYPASS);
}
*seq_len = idx;
}
