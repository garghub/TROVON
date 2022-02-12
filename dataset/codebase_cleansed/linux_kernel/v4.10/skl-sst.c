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
struct firmware stripped_fw;
u32 reg;
skl->boot_complete = false;
init_waitqueue_head(&skl->boot_wait);
if (ctx->fw == NULL) {
ret = request_firmware(&ctx->fw, ctx->fw_name, ctx->dev);
if (ret < 0) {
dev_err(ctx->dev, "Request firmware failed %d\n", ret);
return -EIO;
}
}
if (skl->is_first_boot) {
ret = snd_skl_parse_uuids(ctx, ctx->fw, SKL_ADSP_FW_BIN_HDR_OFFSET, 0);
if (ret < 0) {
dev_err(ctx->dev, "UUID parsing err: %d\n", ret);
release_firmware(ctx->fw);
skl_dsp_disable_core(ctx, SKL_DSP_CORE0_MASK);
return ret;
}
}
stripped_fw.data = ctx->fw->data;
stripped_fw.size = ctx->fw->size;
skl_dsp_strip_extended_manifest(&stripped_fw);
ret = skl_dsp_boot(ctx);
if (ret < 0) {
dev_err(ctx->dev, "Boot dsp core failed ret: %d\n", ret);
goto skl_load_base_firmware_failed;
}
ret = skl_cldma_prepare(ctx);
if (ret < 0) {
dev_err(ctx->dev, "CL dma prepare failed : %d\n", ret);
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
ret = skl_transfer_firmware(ctx, stripped_fw.data, stripped_fw.size);
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
skl->fw_loaded = true;
}
return 0;
transfer_firmware_failed:
ctx->cl_dev.ops.cl_cleanup_controller(ctx);
skl_load_base_firmware_failed:
skl_dsp_disable_core(ctx, SKL_DSP_CORE0_MASK);
release_firmware(ctx->fw);
ctx->fw = NULL;
return ret;
}
static int skl_set_dsp_D0(struct sst_dsp *ctx, unsigned int core_id)
{
int ret;
struct skl_ipc_dxstate_info dx;
struct skl_sst *skl = ctx->thread_context;
unsigned int core_mask = SKL_DSP_CORE_MASK(core_id);
if (core_id == SKL_DSP_CORE0_ID) {
ret = skl_load_base_firmware(ctx);
if (ret < 0) {
dev_err(ctx->dev, "unable to load firmware\n");
return ret;
}
}
if (core_id != SKL_DSP_CORE0_ID) {
ret = skl_dsp_enable_core(ctx, core_mask);
if (ret < 0)
return ret;
dx.core_mask = core_mask;
dx.dx_mask = core_mask;
ret = skl_ipc_set_dx(&skl->ipc, SKL_INSTANCE_ID,
SKL_BASE_FW_MODULE_ID, &dx);
if (ret < 0) {
dev_err(ctx->dev, "Failed to set dsp to D0:core id= %d\n",
core_id);
skl_dsp_disable_core(ctx, core_mask);
}
}
skl->cores.state[core_id] = SKL_DSP_RUNNING;
return ret;
}
static int skl_set_dsp_D3(struct sst_dsp *ctx, unsigned int core_id)
{
int ret;
struct skl_ipc_dxstate_info dx;
struct skl_sst *skl = ctx->thread_context;
unsigned int core_mask = SKL_DSP_CORE_MASK(core_id);
dx.core_mask = core_mask;
dx.dx_mask = SKL_IPC_D3_MASK;
ret = skl_ipc_set_dx(&skl->ipc, SKL_INSTANCE_ID, SKL_BASE_FW_MODULE_ID, &dx);
if (ret < 0)
dev_err(ctx->dev, "set Dx core %d fail: %d\n", core_id, ret);
if (core_id == SKL_DSP_CORE0_ID) {
ctx->cl_dev.ops.cl_cleanup_controller(ctx);
skl_cldma_int_disable(ctx);
skl_ipc_op_int_disable(ctx);
skl_ipc_int_disable(ctx);
}
ret = skl_dsp_disable_core(ctx, core_mask);
if (ret < 0)
return ret;
skl->cores.state[core_id] = SKL_DSP_RESET;
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
static int skl_load_module(struct sst_dsp *ctx, u16 mod_id, u8 *guid)
{
struct skl_module_table *module_entry = NULL;
int ret = 0;
char mod_name[64];
uuid_le *uuid_mod;
uuid_mod = (uuid_le *)guid;
snprintf(mod_name, sizeof(mod_name), "%s%pUL%s",
"intel/dsp_fw_", uuid_mod, ".bin");
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
void skl_clear_module_cnt(struct sst_dsp *ctx)
{
struct skl_module_table *module;
if (list_empty(&ctx->module_list))
return;
list_for_each_entry(module, &ctx->module_list, list) {
module->usage_cnt = 0;
}
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
INIT_LIST_HEAD(&skl->uuid_list);
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
skl->cores.count = 2;
skl->is_first_boot = true;
if (dsp)
*dsp = skl;
return ret;
}
int skl_sst_init_fw(struct device *dev, struct skl_sst *ctx)
{
int ret;
struct sst_dsp *sst = ctx->dsp;
ret = sst->fw_ops.load_fw(sst);
if (ret < 0) {
dev_err(dev, "Load base fw failed : %d\n", ret);
return ret;
}
skl_dsp_init_core_state(sst);
ctx->is_first_boot = false;
return 0;
}
void skl_sst_dsp_cleanup(struct device *dev, struct skl_sst *ctx)
{
if (ctx->dsp->fw)
release_firmware(ctx->dsp->fw);
skl_clear_module_table(ctx->dsp);
skl_freeup_uuid_list(ctx);
skl_ipc_free(&ctx->ipc);
ctx->dsp->ops->free(ctx->dsp);
if (ctx->boot_complete) {
ctx->dsp->cl_dev.ops.cl_cleanup_controller(ctx->dsp);
skl_cldma_int_disable(ctx->dsp);
}
}
