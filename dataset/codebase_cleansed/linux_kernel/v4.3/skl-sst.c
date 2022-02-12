static bool skl_check_fw_status(struct sst_dsp *ctx, u32 status)
{
u32 cur_sts;
cur_sts = sst_dsp_shim_read(ctx, SKL_ADSP_FW_STATUS) & SKL_FW_STS_MASK;
return (cur_sts == status);
}
static int skl_transfer_firmware(struct sst_dsp *ctx,
const void *basefw, u32 base_fw_size)
{
int ret = 0;
ret = ctx->cl_dev.ops.cl_copy_to_dmabuf(ctx, basefw, base_fw_size);
if (ret < 0)
return ret;
ret = sst_dsp_register_poll(ctx,
SKL_ADSP_FW_STATUS,
SKL_FW_STS_MASK,
SKL_FW_RFW_START,
SKL_BASEFW_TIMEOUT,
"Firmware boot");
ctx->cl_dev.ops.cl_stop_dma(ctx);
return ret;
}
static int skl_load_base_firmware(struct sst_dsp *ctx)
{
int ret = 0, i;
const struct firmware *fw = NULL;
struct skl_sst *skl = ctx->thread_context;
u32 reg;
ret = request_firmware(&fw, "dsp_fw_release.bin", ctx->dev);
if (ret < 0) {
dev_err(ctx->dev, "Request firmware failed %d\n", ret);
skl_dsp_disable_core(ctx);
return -EIO;
}
skl_ipc_int_enable(ctx);
skl_ipc_op_int_enable(ctx);
for (i = SKL_INIT_TIMEOUT; i > 0; --i) {
if (skl_check_fw_status(ctx, SKL_FW_INIT)) {
dev_dbg(ctx->dev,
"ROM loaded, we can continue with FW loading\n");
break;
}
mdelay(1);
}
if (!i) {
reg = sst_dsp_shim_read(ctx, SKL_ADSP_FW_STATUS);
dev_err(ctx->dev,
"Timeout waiting for ROM init done, reg:0x%x\n", reg);
ret = -EIO;
goto skl_load_base_firmware_failed;
}
ret = skl_transfer_firmware(ctx, fw->data, fw->size);
if (ret < 0) {
dev_err(ctx->dev, "Transfer firmware failed%d\n", ret);
goto skl_load_base_firmware_failed;
} else {
ret = wait_event_timeout(skl->boot_wait, skl->boot_complete,
msecs_to_jiffies(SKL_IPC_BOOT_MSECS));
if (ret == 0) {
dev_err(ctx->dev, "DSP boot failed, FW Ready timed-out\n");
ret = -EIO;
goto skl_load_base_firmware_failed;
}
dev_dbg(ctx->dev, "Download firmware successful%d\n", ret);
skl_dsp_set_state_locked(ctx, SKL_DSP_RUNNING);
}
release_firmware(fw);
return 0;
skl_load_base_firmware_failed:
skl_dsp_disable_core(ctx);
release_firmware(fw);
return ret;
}
static int skl_set_dsp_D0(struct sst_dsp *ctx)
{
int ret;
ret = skl_load_base_firmware(ctx);
if (ret < 0) {
dev_err(ctx->dev, "unable to load firmware\n");
return ret;
}
skl_dsp_set_state_locked(ctx, SKL_DSP_RUNNING);
return ret;
}
static int skl_set_dsp_D3(struct sst_dsp *ctx)
{
int ret;
struct skl_ipc_dxstate_info dx;
struct skl_sst *skl = ctx->thread_context;
dev_dbg(ctx->dev, "In %s:\n", __func__);
mutex_lock(&ctx->mutex);
if (!is_skl_dsp_running(ctx)) {
mutex_unlock(&ctx->mutex);
return 0;
}
mutex_unlock(&ctx->mutex);
dx.core_mask = SKL_DSP_CORE0_MASK;
dx.dx_mask = SKL_IPC_D3_MASK;
ret = skl_ipc_set_dx(&skl->ipc, SKL_INSTANCE_ID, SKL_BASE_FW_MODULE_ID, &dx);
if (ret < 0) {
dev_err(ctx->dev, "Failed to set DSP to D3 state\n");
return ret;
}
ret = skl_dsp_disable_core(ctx);
if (ret < 0) {
dev_err(ctx->dev, "disable dsp core failed ret: %d\n", ret);
ret = -EIO;
}
skl_dsp_set_state_locked(ctx, SKL_DSP_RESET);
return ret;
}
static unsigned int skl_get_errorcode(struct sst_dsp *ctx)
{
return sst_dsp_shim_read(ctx, SKL_ADSP_ERROR_CODE);
}
int skl_sst_dsp_init(struct device *dev, void __iomem *mmio_base, int irq,
struct skl_dsp_loader_ops dsp_ops, struct skl_sst **dsp)
{
struct skl_sst *skl;
struct sst_dsp *sst;
int ret;
skl = devm_kzalloc(dev, sizeof(*skl), GFP_KERNEL);
if (skl == NULL)
return -ENOMEM;
skl->dev = dev;
skl_dev.thread_context = skl;
skl->dsp = skl_dsp_ctx_init(dev, &skl_dev, irq);
if (!skl->dsp) {
dev_err(skl->dev, "%s: no device\n", __func__);
return -ENODEV;
}
sst = skl->dsp;
sst->addr.lpe = mmio_base;
sst->addr.shim = mmio_base;
sst_dsp_mailbox_init(sst, (SKL_ADSP_SRAM0_BASE + SKL_ADSP_W0_STAT_SZ),
SKL_ADSP_W0_UP_SZ, SKL_ADSP_SRAM1_BASE, SKL_ADSP_W1_SZ);
sst->dsp_ops = dsp_ops;
sst->fw_ops = skl_fw_ops;
ret = skl_ipc_init(dev, skl);
if (ret)
return ret;
skl->boot_complete = false;
init_waitqueue_head(&skl->boot_wait);
ret = skl_dsp_boot(sst);
if (ret < 0) {
dev_err(skl->dev, "Boot dsp core failed ret: %d", ret);
goto free_ipc;
}
ret = skl_cldma_prepare(sst);
if (ret < 0) {
dev_err(dev, "CL dma prepare failed : %d", ret);
goto free_ipc;
}
ret = sst->fw_ops.load_fw(sst);
if (ret < 0) {
dev_err(dev, "Load base fw failed : %d", ret);
return ret;
}
if (dsp)
*dsp = skl;
return 0;
free_ipc:
skl_ipc_free(&skl->ipc);
return ret;
}
void skl_sst_dsp_cleanup(struct device *dev, struct skl_sst *ctx)
{
skl_ipc_free(&ctx->ipc);
ctx->dsp->cl_dev.ops.cl_cleanup_controller(ctx->dsp);
ctx->dsp->ops->free(ctx->dsp);
}
