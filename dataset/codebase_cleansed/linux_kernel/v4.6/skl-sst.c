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
struct skl_sst *skl = ctx->thread_context;
u32 reg;
skl->boot_complete = false;
init_waitqueue_head(&skl->boot_wait);
if (ctx->fw == NULL) {
ret = request_firmware(&ctx->fw, ctx->fw_name, ctx->dev);
if (ret < 0) {
dev_err(ctx->dev, "Request firmware failed %d\n", ret);
skl_dsp_disable_core(ctx);
return -EIO;
}
}
ret = skl_dsp_boot(ctx);
if (ret < 0) {
dev_err(ctx->dev, "Boot dsp core failed ret: %d", ret);
goto skl_load_base_firmware_failed;
}
ret = skl_cldma_prepare(ctx);
if (ret < 0) {
dev_err(ctx->dev, "CL dma prepare failed : %d", ret);
goto skl_load_base_firmware_failed;
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
goto transfer_firmware_failed;
}
ret = skl_transfer_firmware(ctx, ctx->fw->data, ctx->fw->size);
if (ret < 0) {
dev_err(ctx->dev, "Transfer firmware failed%d\n", ret);
goto transfer_firmware_failed;
} else {
ret = wait_event_timeout(skl->boot_wait, skl->boot_complete,
msecs_to_jiffies(SKL_IPC_BOOT_MSECS));
if (ret == 0) {
dev_err(ctx->dev, "DSP boot failed, FW Ready timed-out\n");
ret = -EIO;
goto transfer_firmware_failed;
}
dev_dbg(ctx->dev, "Download firmware successful%d\n", ret);
skl_dsp_set_state_locked(ctx, SKL_DSP_RUNNING);
}
return 0;
transfer_firmware_failed:
ctx->cl_dev.ops.cl_cleanup_controller(ctx);
skl_load_base_firmware_failed:
skl_dsp_disable_core(ctx);
release_firmware(ctx->fw);
ctx->fw = NULL;
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
if (ret < 0)
dev_err(ctx->dev,
"D3 request to FW failed, continuing reset: %d", ret);
ctx->cl_dev.ops.cl_cleanup_controller(ctx);
skl_cldma_int_disable(ctx);
skl_ipc_op_int_disable(ctx);
skl_ipc_int_disable(ctx);
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
static int skl_get_module(struct sst_dsp *ctx, u16 mod_id)
{
struct skl_module_table *module;
list_for_each_entry(module, &ctx->module_list, list) {
if (module->mod_info->mod_id == mod_id)
return ++module->usage_cnt;
}
return -EINVAL;
}
static int skl_put_module(struct sst_dsp *ctx, u16 mod_id)
{
struct skl_module_table *module;
list_for_each_entry(module, &ctx->module_list, list) {
if (module->mod_info->mod_id == mod_id)
return --module->usage_cnt;
}
return -EINVAL;
}
static struct skl_module_table *skl_fill_module_table(struct sst_dsp *ctx,
char *mod_name, int mod_id)
{
const struct firmware *fw;
struct skl_module_table *skl_module;
unsigned int size;
int ret;
ret = request_firmware(&fw, mod_name, ctx->dev);
if (ret < 0) {
dev_err(ctx->dev, "Request Module %s failed :%d\n",
mod_name, ret);
return NULL;
}
skl_module = devm_kzalloc(ctx->dev, sizeof(*skl_module), GFP_KERNEL);
if (skl_module == NULL) {
release_firmware(fw);
return NULL;
}
size = sizeof(*skl_module->mod_info);
skl_module->mod_info = devm_kzalloc(ctx->dev, size, GFP_KERNEL);
if (skl_module->mod_info == NULL) {
release_firmware(fw);
return NULL;
}
skl_module->mod_info->mod_id = mod_id;
skl_module->mod_info->fw = fw;
list_add(&skl_module->list, &ctx->module_list);
return skl_module;
}
static struct skl_module_table *skl_module_get_from_id(
struct sst_dsp *ctx, u16 mod_id)
{
struct skl_module_table *module;
if (list_empty(&ctx->module_list)) {
dev_err(ctx->dev, "Module list is empty\n");
return NULL;
}
list_for_each_entry(module, &ctx->module_list, list) {
if (module->mod_info->mod_id == mod_id)
return module;
}
return NULL;
}
static int skl_transfer_module(struct sst_dsp *ctx,
struct skl_load_module_info *module)
{
int ret;
struct skl_sst *skl = ctx->thread_context;
ret = ctx->cl_dev.ops.cl_copy_to_dmabuf(ctx, module->fw->data,
module->fw->size);
if (ret < 0)
return ret;
ret = skl_ipc_load_modules(&skl->ipc, SKL_NUM_MODULES,
(void *)&module->mod_id);
if (ret < 0)
dev_err(ctx->dev, "Failed to Load module: %d\n", ret);
ctx->cl_dev.ops.cl_stop_dma(ctx);
return ret;
}
static int skl_load_module(struct sst_dsp *ctx, u16 mod_id, char *guid)
{
struct skl_module_table *module_entry = NULL;
int ret = 0;
char mod_name[64];
snprintf(mod_name, sizeof(mod_name), "%s%s%s",
"intel/dsp_fw_", guid, ".bin");
module_entry = skl_module_get_from_id(ctx, mod_id);
if (module_entry == NULL) {
module_entry = skl_fill_module_table(ctx, mod_name, mod_id);
if (module_entry == NULL) {
dev_err(ctx->dev, "Failed to Load module\n");
return -EINVAL;
}
}
if (!module_entry->usage_cnt) {
ret = skl_transfer_module(ctx, module_entry->mod_info);
if (ret < 0) {
dev_err(ctx->dev, "Failed to Load module\n");
return ret;
}
}
ret = skl_get_module(ctx, mod_id);
return ret;
}
static int skl_unload_module(struct sst_dsp *ctx, u16 mod_id)
{
int usage_cnt;
struct skl_sst *skl = ctx->thread_context;
int ret = 0;
usage_cnt = skl_put_module(ctx, mod_id);
if (usage_cnt < 0) {
dev_err(ctx->dev, "Module bad usage cnt!:%d\n", usage_cnt);
return -EIO;
}
ret = skl_ipc_unload_modules(&skl->ipc,
SKL_NUM_MODULES, &mod_id);
if (ret < 0) {
dev_err(ctx->dev, "Failed to UnLoad module\n");
skl_get_module(ctx, mod_id);
return ret;
}
return ret;
}
static void skl_clear_module_table(struct sst_dsp *ctx)
{
struct skl_module_table *module, *tmp;
if (list_empty(&ctx->module_list))
return;
list_for_each_entry_safe(module, tmp, &ctx->module_list, list) {
list_del(&module->list);
release_firmware(module->mod_info->fw);
}
}
int skl_sst_dsp_init(struct device *dev, void __iomem *mmio_base, int irq,
const char *fw_name, struct skl_dsp_loader_ops dsp_ops, struct skl_sst **dsp)
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
sst->fw_name = fw_name;
sst->addr.lpe = mmio_base;
sst->addr.shim = mmio_base;
sst_dsp_mailbox_init(sst, (SKL_ADSP_SRAM0_BASE + SKL_ADSP_W0_STAT_SZ),
SKL_ADSP_W0_UP_SZ, SKL_ADSP_SRAM1_BASE, SKL_ADSP_W1_SZ);
INIT_LIST_HEAD(&sst->module_list);
sst->dsp_ops = dsp_ops;
sst->fw_ops = skl_fw_ops;
ret = skl_ipc_init(dev, skl);
if (ret)
return ret;
ret = sst->fw_ops.load_fw(sst);
if (ret < 0) {
dev_err(dev, "Load base fw failed : %d", ret);
goto cleanup;
}
if (dsp)
*dsp = skl;
return ret;
cleanup:
skl_sst_dsp_cleanup(dev, skl);
return ret;
}
void skl_sst_dsp_cleanup(struct device *dev, struct skl_sst *ctx)
{
skl_clear_module_table(ctx->dsp);
skl_ipc_free(&ctx->ipc);
ctx->dsp->ops->free(ctx->dsp);
}
