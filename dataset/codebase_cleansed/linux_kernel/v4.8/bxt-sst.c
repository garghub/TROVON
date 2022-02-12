static unsigned int bxt_get_errorcode(struct sst_dsp *ctx)
{
return sst_dsp_shim_read(ctx, BXT_ADSP_ERROR_CODE);
}
static int sst_bxt_prepare_fw(struct sst_dsp *ctx,
const void *fwdata, u32 fwsize)
{
int stream_tag, ret, i;
u32 reg;
stream_tag = ctx->dsp_ops.prepare(ctx->dev, 0x40, fwsize, &ctx->dmab);
if (stream_tag <= 0) {
dev_err(ctx->dev, "Failed to prepare DMA FW loading err: %x\n",
stream_tag);
return stream_tag;
}
ctx->dsp_ops.stream_tag = stream_tag;
memcpy(ctx->dmab.area, fwdata, fwsize);
ret = skl_dsp_core_power_up(ctx, SKL_DSP_CORE0_MASK |
SKL_DSP_CORE_MASK(1));
if (ret < 0) {
dev_err(ctx->dev, "dsp core0/1 power up failed\n");
goto base_fw_load_failed;
}
sst_dsp_shim_write(ctx, SKL_ADSP_REG_HIPCI, SKL_ADSP_REG_HIPCI_BUSY |
(BXT_IPC_PURGE_FW | ((stream_tag - 1) << 9)));
ret = skl_dsp_start_core(ctx, SKL_DSP_CORE0_MASK);
if (ret < 0) {
dev_err(ctx->dev, "Start dsp core failed ret: %d\n", ret);
ret = -EIO;
goto base_fw_load_failed;
}
for (i = BXT_INIT_TIMEOUT; i > 0; --i) {
reg = sst_dsp_shim_read(ctx, SKL_ADSP_REG_HIPCIE);
if (reg & SKL_ADSP_REG_HIPCIE_DONE) {
sst_dsp_shim_update_bits_forced(ctx,
SKL_ADSP_REG_HIPCIE,
SKL_ADSP_REG_HIPCIE_DONE,
SKL_ADSP_REG_HIPCIE_DONE);
break;
}
mdelay(1);
}
if (!i) {
dev_info(ctx->dev, "Waiting for HIPCIE done, reg: 0x%x\n", reg);
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_HIPCIE,
SKL_ADSP_REG_HIPCIE_DONE,
SKL_ADSP_REG_HIPCIE_DONE);
}
ret = skl_dsp_core_power_down(ctx, SKL_DSP_CORE_MASK(1));
if (ret < 0) {
dev_err(ctx->dev, "dsp core1 power down failed\n");
goto base_fw_load_failed;
}
skl_ipc_int_enable(ctx);
skl_ipc_op_int_enable(ctx);
for (i = BXT_INIT_TIMEOUT; i > 0; --i) {
if (SKL_FW_INIT ==
(sst_dsp_shim_read(ctx, BXT_ADSP_FW_STATUS) &
SKL_FW_STS_MASK)) {
dev_info(ctx->dev, "ROM loaded, continue FW loading\n");
break;
}
mdelay(1);
}
if (!i) {
dev_err(ctx->dev, "Timeout for ROM init, HIPCIE: 0x%x\n", reg);
ret = -EIO;
goto base_fw_load_failed;
}
return ret;
base_fw_load_failed:
ctx->dsp_ops.cleanup(ctx->dev, &ctx->dmab, stream_tag);
skl_dsp_core_power_down(ctx, SKL_DSP_CORE_MASK(1));
skl_dsp_disable_core(ctx, SKL_DSP_CORE0_MASK);
return ret;
}
static int sst_transfer_fw_host_dma(struct sst_dsp *ctx)
{
int ret;
ctx->dsp_ops.trigger(ctx->dev, true, ctx->dsp_ops.stream_tag);
ret = sst_dsp_register_poll(ctx, BXT_ADSP_FW_STATUS, SKL_FW_STS_MASK,
BXT_ROM_INIT, BXT_BASEFW_TIMEOUT, "Firmware boot");
ctx->dsp_ops.trigger(ctx->dev, false, ctx->dsp_ops.stream_tag);
ctx->dsp_ops.cleanup(ctx->dev, &ctx->dmab, ctx->dsp_ops.stream_tag);
return ret;
}
static int bxt_load_base_firmware(struct sst_dsp *ctx)
{
struct firmware stripped_fw;
struct skl_sst *skl = ctx->thread_context;
int ret;
ret = request_firmware(&ctx->fw, ctx->fw_name, ctx->dev);
if (ret < 0) {
dev_err(ctx->dev, "Request firmware failed %d\n", ret);
goto sst_load_base_firmware_failed;
}
if (ctx->fw == NULL)
goto sst_load_base_firmware_failed;
ret = snd_skl_parse_uuids(ctx, BXT_ADSP_FW_BIN_HDR_OFFSET);
if (ret < 0)
goto sst_load_base_firmware_failed;
stripped_fw.data = ctx->fw->data;
stripped_fw.size = ctx->fw->size;
skl_dsp_strip_extended_manifest(&stripped_fw);
ret = sst_bxt_prepare_fw(ctx, stripped_fw.data, stripped_fw.size);
if (ret < 0) {
ret = sst_bxt_prepare_fw(ctx, stripped_fw.data, stripped_fw.size);
if (ret < 0) {
dev_err(ctx->dev, "Error code=0x%x: FW status=0x%x\n",
sst_dsp_shim_read(ctx, BXT_ADSP_ERROR_CODE),
sst_dsp_shim_read(ctx, BXT_ADSP_FW_STATUS));
dev_err(ctx->dev, "Core En/ROM load fail:%d\n", ret);
goto sst_load_base_firmware_failed;
}
}
ret = sst_transfer_fw_host_dma(ctx);
if (ret < 0) {
dev_err(ctx->dev, "Transfer firmware failed %d\n", ret);
dev_info(ctx->dev, "Error code=0x%x: FW status=0x%x\n",
sst_dsp_shim_read(ctx, BXT_ADSP_ERROR_CODE),
sst_dsp_shim_read(ctx, BXT_ADSP_FW_STATUS));
skl_dsp_disable_core(ctx, SKL_DSP_CORE0_MASK);
} else {
dev_dbg(ctx->dev, "Firmware download successful\n");
ret = wait_event_timeout(skl->boot_wait, skl->boot_complete,
msecs_to_jiffies(SKL_IPC_BOOT_MSECS));
if (ret == 0) {
dev_err(ctx->dev, "DSP boot fail, FW Ready timeout\n");
skl_dsp_disable_core(ctx, SKL_DSP_CORE0_MASK);
ret = -EIO;
} else {
ret = 0;
skl->fw_loaded = true;
}
}
sst_load_base_firmware_failed:
release_firmware(ctx->fw);
return ret;
}
static int bxt_set_dsp_D0(struct sst_dsp *ctx, unsigned int core_id)
{
struct skl_sst *skl = ctx->thread_context;
int ret;
struct skl_ipc_dxstate_info dx;
unsigned int core_mask = SKL_DSP_CORE_MASK(core_id);
if (skl->fw_loaded == false) {
skl->boot_complete = false;
ret = bxt_load_base_firmware(ctx);
if (ret < 0)
dev_err(ctx->dev, "reload fw failed: %d\n", ret);
return ret;
}
if (core_id == SKL_DSP_CORE0_ID)
ret = skl_dsp_core_power_up(ctx, core_mask |
SKL_DSP_CORE_MASK(1));
else
ret = skl_dsp_core_power_up(ctx, core_mask);
if (ret < 0)
goto err;
if (core_id == SKL_DSP_CORE0_ID) {
skl_ipc_int_enable(ctx);
skl_ipc_op_int_enable(ctx);
skl->boot_complete = false;
}
ret = skl_dsp_start_core(ctx, core_mask);
if (ret < 0)
goto err;
if (core_id == SKL_DSP_CORE0_ID) {
ret = wait_event_timeout(skl->boot_wait,
skl->boot_complete,
msecs_to_jiffies(SKL_IPC_BOOT_MSECS));
skl_dsp_core_power_down(ctx, SKL_DSP_CORE_MASK(1));
if (ret == 0) {
dev_err(ctx->dev, "%s: DSP boot timeout\n", __func__);
dev_err(ctx->dev, "Error code=0x%x: FW status=0x%x\n",
sst_dsp_shim_read(ctx, BXT_ADSP_ERROR_CODE),
sst_dsp_shim_read(ctx, BXT_ADSP_FW_STATUS));
dev_err(ctx->dev, "Failed to set core0 to D0 state\n");
ret = -EIO;
goto err;
}
}
if (core_id != SKL_DSP_CORE0_ID) {
dx.core_mask = core_mask;
dx.dx_mask = core_mask;
ret = skl_ipc_set_dx(&skl->ipc, BXT_INSTANCE_ID,
BXT_BASE_FW_MODULE_ID, &dx);
if (ret < 0) {
dev_err(ctx->dev, "IPC set_dx for core %d fail: %d\n",
core_id, ret);
goto err;
}
}
skl->cores.state[core_id] = SKL_DSP_RUNNING;
return 0;
err:
if (core_id == SKL_DSP_CORE0_ID)
core_mask |= SKL_DSP_CORE_MASK(1);
skl_dsp_disable_core(ctx, core_mask);
return ret;
}
static int bxt_set_dsp_D3(struct sst_dsp *ctx, unsigned int core_id)
{
int ret;
struct skl_ipc_dxstate_info dx;
struct skl_sst *skl = ctx->thread_context;
unsigned int core_mask = SKL_DSP_CORE_MASK(core_id);
dx.core_mask = core_mask;
dx.dx_mask = SKL_IPC_D3_MASK;
dev_dbg(ctx->dev, "core mask=%x dx_mask=%x\n",
dx.core_mask, dx.dx_mask);
ret = skl_ipc_set_dx(&skl->ipc, BXT_INSTANCE_ID,
BXT_BASE_FW_MODULE_ID, &dx);
if (ret < 0)
dev_err(ctx->dev,
"Failed to set DSP to D3:core id = %d;Continue reset\n",
core_id);
ret = skl_dsp_disable_core(ctx, core_mask);
if (ret < 0) {
dev_err(ctx->dev, "Failed to disable core %d", ret);
return ret;
}
skl->cores.state[core_id] = SKL_DSP_RESET;
return 0;
}
int bxt_sst_dsp_init(struct device *dev, void __iomem *mmio_base, int irq,
const char *fw_name, struct skl_dsp_loader_ops dsp_ops,
struct skl_sst **dsp)
{
struct skl_sst *skl;
struct sst_dsp *sst;
int ret;
skl = devm_kzalloc(dev, sizeof(*skl), GFP_KERNEL);
if (skl == NULL)
return -ENOMEM;
skl->dev = dev;
skl_dev.thread_context = skl;
INIT_LIST_HEAD(&skl->uuid_list);
skl->dsp = skl_dsp_ctx_init(dev, &skl_dev, irq);
if (!skl->dsp) {
dev_err(skl->dev, "skl_dsp_ctx_init failed\n");
return -ENODEV;
}
sst = skl->dsp;
sst->fw_name = fw_name;
sst->dsp_ops = dsp_ops;
sst->fw_ops = bxt_fw_ops;
sst->addr.lpe = mmio_base;
sst->addr.shim = mmio_base;
sst_dsp_mailbox_init(sst, (BXT_ADSP_SRAM0_BASE + SKL_ADSP_W0_STAT_SZ),
SKL_ADSP_W0_UP_SZ, BXT_ADSP_SRAM1_BASE, SKL_ADSP_W1_SZ);
INIT_LIST_HEAD(&sst->module_list);
ret = skl_ipc_init(dev, skl);
if (ret)
return ret;
skl->cores.count = 2;
skl->boot_complete = false;
init_waitqueue_head(&skl->boot_wait);
ret = sst->fw_ops.load_fw(sst);
if (ret < 0) {
dev_err(dev, "Load base fw failed: %x", ret);
return ret;
}
skl_dsp_init_core_state(sst);
if (dsp)
*dsp = skl;
return 0;
}
void bxt_sst_dsp_cleanup(struct device *dev, struct skl_sst *ctx)
{
skl_freeup_uuid_list(ctx);
skl_ipc_free(&ctx->ipc);
ctx->dsp->cl_dev.ops.cl_cleanup_controller(ctx->dsp);
if (ctx->dsp->addr.lpe)
iounmap(ctx->dsp->addr.lpe);
ctx->dsp->ops->free(ctx->dsp);
}
