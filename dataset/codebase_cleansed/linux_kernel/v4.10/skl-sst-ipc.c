static void skl_ipc_tx_data_copy(struct ipc_message *msg, char *tx_data,
size_t tx_size)
{
if (tx_size)
memcpy(msg->tx_data, tx_data, tx_size);
}
static bool skl_ipc_is_dsp_busy(struct sst_dsp *dsp)
{
u32 hipci;
hipci = sst_dsp_shim_read_unlocked(dsp, SKL_ADSP_REG_HIPCI);
return (hipci & SKL_ADSP_REG_HIPCI_BUSY);
}
static void skl_ipc_tx_msg(struct sst_generic_ipc *ipc, struct ipc_message *msg)
{
struct skl_ipc_header *header = (struct skl_ipc_header *)(&msg->header);
if (msg->tx_size)
sst_dsp_outbox_write(ipc->dsp, msg->tx_data, msg->tx_size);
sst_dsp_shim_write_unlocked(ipc->dsp, SKL_ADSP_REG_HIPCIE,
header->extension);
sst_dsp_shim_write_unlocked(ipc->dsp, SKL_ADSP_REG_HIPCI,
header->primary | SKL_ADSP_REG_HIPCI_BUSY);
}
int skl_ipc_check_D0i0(struct sst_dsp *dsp, bool state)
{
int ret;
if (!dsp->fw_ops.set_state_D0i0)
return 0;
if (state)
ret = dsp->fw_ops.set_state_D0i0(dsp);
else
ret = dsp->fw_ops.set_state_D0i3(dsp);
return ret;
}
static struct ipc_message *skl_ipc_reply_get_msg(struct sst_generic_ipc *ipc,
u64 ipc_header)
{
struct ipc_message *msg = NULL;
struct skl_ipc_header *header = (struct skl_ipc_header *)(&ipc_header);
if (list_empty(&ipc->rx_list)) {
dev_err(ipc->dev, "ipc: rx list is empty but received 0x%x\n",
header->primary);
goto out;
}
msg = list_first_entry(&ipc->rx_list, struct ipc_message, list);
out:
return msg;
}
static int skl_ipc_process_notification(struct sst_generic_ipc *ipc,
struct skl_ipc_header header)
{
struct skl_sst *skl = container_of(ipc, struct skl_sst, ipc);
if (IPC_GLB_NOTIFY_MSG_TYPE(header.primary)) {
switch (IPC_GLB_NOTIFY_TYPE(header.primary)) {
case IPC_GLB_NOTIFY_UNDERRUN:
dev_err(ipc->dev, "FW Underrun %x\n", header.primary);
break;
case IPC_GLB_NOTIFY_RESOURCE_EVENT:
dev_err(ipc->dev, "MCPS Budget Violation: %x\n",
header.primary);
break;
case IPC_GLB_NOTIFY_FW_READY:
skl->boot_complete = true;
wake_up(&skl->boot_wait);
break;
case IPC_GLB_NOTIFY_PHRASE_DETECTED:
dev_dbg(ipc->dev, "***** Phrase Detected **********\n");
skl->enable_miscbdcge(ipc->dev, false);
skl->miscbdcg_disabled = true;
break;
default:
dev_err(ipc->dev, "ipc: Unhandled error msg=%x\n",
header.primary);
break;
}
}
return 0;
}
static void skl_ipc_process_reply(struct sst_generic_ipc *ipc,
struct skl_ipc_header header)
{
struct ipc_message *msg;
u32 reply = header.primary & IPC_GLB_REPLY_STATUS_MASK;
u64 *ipc_header = (u64 *)(&header);
msg = skl_ipc_reply_get_msg(ipc, *ipc_header);
if (msg == NULL) {
dev_dbg(ipc->dev, "ipc: rx list is empty\n");
return;
}
switch (reply) {
case IPC_GLB_REPLY_SUCCESS:
dev_dbg(ipc->dev, "ipc FW reply %x: success\n", header.primary);
sst_dsp_inbox_read(ipc->dsp, msg->rx_data, msg->rx_size);
break;
case IPC_GLB_REPLY_OUT_OF_MEMORY:
dev_err(ipc->dev, "ipc fw reply: %x: no memory\n", header.primary);
msg->errno = -ENOMEM;
break;
case IPC_GLB_REPLY_BUSY:
dev_err(ipc->dev, "ipc fw reply: %x: Busy\n", header.primary);
msg->errno = -EBUSY;
break;
default:
dev_err(ipc->dev, "Unknown ipc reply: 0x%x\n", reply);
msg->errno = -EINVAL;
break;
}
if (reply != IPC_GLB_REPLY_SUCCESS) {
dev_err(ipc->dev, "ipc FW reply: reply=%d\n", reply);
dev_err(ipc->dev, "FW Error Code: %u\n",
ipc->dsp->fw_ops.get_fw_errcode(ipc->dsp));
}
list_del(&msg->list);
sst_ipc_tx_msg_reply_complete(ipc, msg);
}
irqreturn_t skl_dsp_irq_thread_handler(int irq, void *context)
{
struct sst_dsp *dsp = context;
struct skl_sst *skl = sst_dsp_get_thread_context(dsp);
struct sst_generic_ipc *ipc = &skl->ipc;
struct skl_ipc_header header = {0};
u32 hipcie, hipct, hipcte;
int ipc_irq = 0;
if (dsp->intr_status & SKL_ADSPIS_CL_DMA)
skl_cldma_process_intr(dsp);
if (!(dsp->intr_status & SKL_ADSPIS_IPC))
return IRQ_NONE;
hipcie = sst_dsp_shim_read_unlocked(dsp, SKL_ADSP_REG_HIPCIE);
hipct = sst_dsp_shim_read_unlocked(dsp, SKL_ADSP_REG_HIPCT);
if (hipcie & SKL_ADSP_REG_HIPCIE_DONE) {
sst_dsp_shim_update_bits(dsp, SKL_ADSP_REG_HIPCCTL,
SKL_ADSP_REG_HIPCCTL_DONE, 0);
sst_dsp_shim_update_bits_forced(dsp, SKL_ADSP_REG_HIPCIE,
SKL_ADSP_REG_HIPCIE_DONE, SKL_ADSP_REG_HIPCIE_DONE);
ipc_irq = 1;
sst_dsp_shim_update_bits(dsp, SKL_ADSP_REG_HIPCCTL,
SKL_ADSP_REG_HIPCCTL_DONE, SKL_ADSP_REG_HIPCCTL_DONE);
}
if (hipct & SKL_ADSP_REG_HIPCT_BUSY) {
hipcte = sst_dsp_shim_read_unlocked(dsp, SKL_ADSP_REG_HIPCTE);
header.primary = hipct;
header.extension = hipcte;
dev_dbg(dsp->dev, "IPC irq: Firmware respond primary:%x\n",
header.primary);
dev_dbg(dsp->dev, "IPC irq: Firmware respond extension:%x\n",
header.extension);
if (IPC_GLB_NOTIFY_RSP_TYPE(header.primary)) {
skl_ipc_process_reply(ipc, header);
} else {
dev_dbg(dsp->dev, "IPC irq: Notification from firmware\n");
skl_ipc_process_notification(ipc, header);
}
sst_dsp_shim_update_bits_forced(dsp, SKL_ADSP_REG_HIPCT,
SKL_ADSP_REG_HIPCT_BUSY, SKL_ADSP_REG_HIPCT_BUSY);
ipc_irq = 1;
}
if (ipc_irq == 0)
return IRQ_NONE;
skl_ipc_int_enable(dsp);
schedule_work(&ipc->kwork);
return IRQ_HANDLED;
}
void skl_ipc_int_enable(struct sst_dsp *ctx)
{
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_ADSPIC,
SKL_ADSPIC_IPC, SKL_ADSPIC_IPC);
}
void skl_ipc_int_disable(struct sst_dsp *ctx)
{
sst_dsp_shim_update_bits_unlocked(ctx, SKL_ADSP_REG_ADSPIC,
SKL_ADSPIC_IPC, 0);
}
void skl_ipc_op_int_enable(struct sst_dsp *ctx)
{
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_HIPCCTL,
SKL_ADSP_REG_HIPCCTL_DONE, SKL_ADSP_REG_HIPCCTL_DONE);
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_HIPCCTL,
SKL_ADSP_REG_HIPCCTL_BUSY, SKL_ADSP_REG_HIPCCTL_BUSY);
}
void skl_ipc_op_int_disable(struct sst_dsp *ctx)
{
sst_dsp_shim_update_bits_unlocked(ctx, SKL_ADSP_REG_HIPCCTL,
SKL_ADSP_REG_HIPCCTL_DONE, 0);
sst_dsp_shim_update_bits_unlocked(ctx, SKL_ADSP_REG_HIPCCTL,
SKL_ADSP_REG_HIPCCTL_BUSY, 0);
}
bool skl_ipc_int_status(struct sst_dsp *ctx)
{
return sst_dsp_shim_read_unlocked(ctx,
SKL_ADSP_REG_ADSPIS) & SKL_ADSPIS_IPC;
}
int skl_ipc_init(struct device *dev, struct skl_sst *skl)
{
struct sst_generic_ipc *ipc;
int err;
ipc = &skl->ipc;
ipc->dsp = skl->dsp;
ipc->dev = dev;
ipc->tx_data_max_size = SKL_ADSP_W1_SZ;
ipc->rx_data_max_size = SKL_ADSP_W0_UP_SZ;
err = sst_ipc_init(ipc);
if (err)
return err;
ipc->ops.tx_msg = skl_ipc_tx_msg;
ipc->ops.tx_data_copy = skl_ipc_tx_data_copy;
ipc->ops.is_dsp_busy = skl_ipc_is_dsp_busy;
return 0;
}
void skl_ipc_free(struct sst_generic_ipc *ipc)
{
sst_dsp_shim_update_bits(ipc->dsp, SKL_ADSP_REG_HIPCCTL,
SKL_ADSP_REG_HIPCCTL_DONE, 0);
sst_dsp_shim_update_bits(ipc->dsp, SKL_ADSP_REG_HIPCCTL,
SKL_ADSP_REG_HIPCCTL_BUSY, 0);
sst_ipc_fini(ipc);
}
int skl_ipc_create_pipeline(struct sst_generic_ipc *ipc,
u16 ppl_mem_size, u8 ppl_type, u8 instance_id, u8 lp_mode)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_FW_GEN_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_GLB_CREATE_PPL);
header.primary |= IPC_INSTANCE_ID(instance_id);
header.primary |= IPC_PPL_TYPE(ppl_type);
header.primary |= IPC_PPL_MEM_SIZE(ppl_mem_size);
header.extension = IPC_PPL_LP_MODE(lp_mode);
dev_dbg(ipc->dev, "In %s header=%d\n", __func__, header.primary);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, NULL, 0, NULL, 0);
if (ret < 0) {
dev_err(ipc->dev, "ipc: create pipeline fail, err: %d\n", ret);
return ret;
}
return ret;
}
int skl_ipc_delete_pipeline(struct sst_generic_ipc *ipc, u8 instance_id)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_FW_GEN_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_GLB_DELETE_PPL);
header.primary |= IPC_INSTANCE_ID(instance_id);
dev_dbg(ipc->dev, "In %s header=%d\n", __func__, header.primary);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, NULL, 0, NULL, 0);
if (ret < 0) {
dev_err(ipc->dev, "ipc: delete pipeline failed, err %d\n", ret);
return ret;
}
return 0;
}
int skl_ipc_set_pipeline_state(struct sst_generic_ipc *ipc,
u8 instance_id, enum skl_ipc_pipeline_state state)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_FW_GEN_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_GLB_SET_PPL_STATE);
header.primary |= IPC_INSTANCE_ID(instance_id);
header.primary |= IPC_PPL_STATE(state);
dev_dbg(ipc->dev, "In %s header=%d\n", __func__, header.primary);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, NULL, 0, NULL, 0);
if (ret < 0) {
dev_err(ipc->dev, "ipc: set pipeline state failed, err: %d\n", ret);
return ret;
}
return ret;
}
int
skl_ipc_save_pipeline(struct sst_generic_ipc *ipc, u8 instance_id, int dma_id)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_FW_GEN_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_GLB_SAVE_PPL);
header.primary |= IPC_INSTANCE_ID(instance_id);
header.extension = IPC_DMA_ID(dma_id);
dev_dbg(ipc->dev, "In %s header=%d\n", __func__, header.primary);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, NULL, 0, NULL, 0);
if (ret < 0) {
dev_err(ipc->dev, "ipc: save pipeline failed, err: %d\n", ret);
return ret;
}
return ret;
}
int skl_ipc_restore_pipeline(struct sst_generic_ipc *ipc, u8 instance_id)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_FW_GEN_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_GLB_RESTORE_PPL);
header.primary |= IPC_INSTANCE_ID(instance_id);
dev_dbg(ipc->dev, "In %s header=%d\n", __func__, header.primary);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, NULL, 0, NULL, 0);
if (ret < 0) {
dev_err(ipc->dev, "ipc: restore pipeline failed, err: %d\n", ret);
return ret;
}
return ret;
}
int skl_ipc_set_dx(struct sst_generic_ipc *ipc, u8 instance_id,
u16 module_id, struct skl_ipc_dxstate_info *dx)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_MOD_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_MOD_SET_DX);
header.primary |= IPC_MOD_INSTANCE_ID(instance_id);
header.primary |= IPC_MOD_ID(module_id);
dev_dbg(ipc->dev, "In %s primary =%x ext=%x\n", __func__,
header.primary, header.extension);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header,
dx, sizeof(*dx), NULL, 0);
if (ret < 0) {
dev_err(ipc->dev, "ipc: set dx failed, err %d\n", ret);
return ret;
}
return ret;
}
int skl_ipc_init_instance(struct sst_generic_ipc *ipc,
struct skl_ipc_init_instance_msg *msg, void *param_data)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
u32 *buffer = (u32 *)param_data;
u16 param_block_size = msg->param_data_size / sizeof(u32);
print_hex_dump_debug("Param data:", DUMP_PREFIX_NONE,
16, 4, buffer, param_block_size, false);
header.primary = IPC_MSG_TARGET(IPC_MOD_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_MOD_INIT_INSTANCE);
header.primary |= IPC_MOD_INSTANCE_ID(msg->instance_id);
header.primary |= IPC_MOD_ID(msg->module_id);
header.extension = IPC_CORE_ID(msg->core_id);
header.extension |= IPC_PPL_INSTANCE_ID(msg->ppl_instance_id);
header.extension |= IPC_PARAM_BLOCK_SIZE(param_block_size);
header.extension |= IPC_DOMAIN(msg->domain);
dev_dbg(ipc->dev, "In %s primary =%x ext=%x\n", __func__,
header.primary, header.extension);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, param_data,
msg->param_data_size, NULL, 0);
if (ret < 0) {
dev_err(ipc->dev, "ipc: init instance failed\n");
return ret;
}
return ret;
}
int skl_ipc_bind_unbind(struct sst_generic_ipc *ipc,
struct skl_ipc_bind_unbind_msg *msg)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
u8 bind_unbind = msg->bind ? IPC_MOD_BIND : IPC_MOD_UNBIND;
int ret;
header.primary = IPC_MSG_TARGET(IPC_MOD_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(bind_unbind);
header.primary |= IPC_MOD_INSTANCE_ID(msg->instance_id);
header.primary |= IPC_MOD_ID(msg->module_id);
header.extension = IPC_DST_MOD_ID(msg->dst_module_id);
header.extension |= IPC_DST_MOD_INSTANCE_ID(msg->dst_instance_id);
header.extension |= IPC_DST_QUEUE(msg->dst_queue);
header.extension |= IPC_SRC_QUEUE(msg->src_queue);
dev_dbg(ipc->dev, "In %s hdr=%x ext=%x\n", __func__, header.primary,
header.extension);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, NULL, 0, NULL, 0);
if (ret < 0) {
dev_err(ipc->dev, "ipc: bind/unbind failed\n");
return ret;
}
return ret;
}
int skl_ipc_load_modules(struct sst_generic_ipc *ipc,
u8 module_cnt, void *data)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_FW_GEN_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_GLB_LOAD_MULTIPLE_MODS);
header.primary |= IPC_LOAD_MODULE_CNT(module_cnt);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, data,
(sizeof(u16) * module_cnt), NULL, 0);
if (ret < 0)
dev_err(ipc->dev, "ipc: load modules failed :%d\n", ret);
return ret;
}
int skl_ipc_unload_modules(struct sst_generic_ipc *ipc, u8 module_cnt,
void *data)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_FW_GEN_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_GLB_UNLOAD_MULTIPLE_MODS);
header.primary |= IPC_LOAD_MODULE_CNT(module_cnt);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, data,
(sizeof(u16) * module_cnt), NULL, 0);
if (ret < 0)
dev_err(ipc->dev, "ipc: unload modules failed :%d\n", ret);
return ret;
}
int skl_ipc_set_large_config(struct sst_generic_ipc *ipc,
struct skl_ipc_large_config_msg *msg, u32 *param)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret = 0;
size_t sz_remaining, tx_size, data_offset;
header.primary = IPC_MSG_TARGET(IPC_MOD_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_MOD_LARGE_CONFIG_SET);
header.primary |= IPC_MOD_INSTANCE_ID(msg->instance_id);
header.primary |= IPC_MOD_ID(msg->module_id);
header.extension = IPC_DATA_OFFSET_SZ(msg->param_data_size);
header.extension |= IPC_LARGE_PARAM_ID(msg->large_param_id);
header.extension |= IPC_FINAL_BLOCK(0);
header.extension |= IPC_INITIAL_BLOCK(1);
sz_remaining = msg->param_data_size;
data_offset = 0;
while (sz_remaining != 0) {
tx_size = sz_remaining > SKL_ADSP_W1_SZ
? SKL_ADSP_W1_SZ : sz_remaining;
if (tx_size == sz_remaining)
header.extension |= IPC_FINAL_BLOCK(1);
dev_dbg(ipc->dev, "In %s primary=%#x ext=%#x\n", __func__,
header.primary, header.extension);
dev_dbg(ipc->dev, "transmitting offset: %#x, size: %#x\n",
(unsigned)data_offset, (unsigned)tx_size);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header,
((char *)param) + data_offset,
tx_size, NULL, 0);
if (ret < 0) {
dev_err(ipc->dev,
"ipc: set large config fail, err: %d\n", ret);
return ret;
}
sz_remaining -= tx_size;
data_offset = msg->param_data_size - sz_remaining;
header.extension &= IPC_INITIAL_BLOCK_CLEAR;
header.extension &= IPC_DATA_OFFSET_SZ_CLEAR;
header.extension |= IPC_INITIAL_BLOCK(0);
header.extension |= IPC_DATA_OFFSET_SZ(data_offset);
}
return ret;
}
int skl_ipc_get_large_config(struct sst_generic_ipc *ipc,
struct skl_ipc_large_config_msg *msg, u32 *param)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret = 0;
size_t sz_remaining, rx_size, data_offset;
header.primary = IPC_MSG_TARGET(IPC_MOD_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_MOD_LARGE_CONFIG_GET);
header.primary |= IPC_MOD_INSTANCE_ID(msg->instance_id);
header.primary |= IPC_MOD_ID(msg->module_id);
header.extension = IPC_DATA_OFFSET_SZ(msg->param_data_size);
header.extension |= IPC_LARGE_PARAM_ID(msg->large_param_id);
header.extension |= IPC_FINAL_BLOCK(1);
header.extension |= IPC_INITIAL_BLOCK(1);
sz_remaining = msg->param_data_size;
data_offset = 0;
while (sz_remaining != 0) {
rx_size = sz_remaining > SKL_ADSP_W1_SZ
? SKL_ADSP_W1_SZ : sz_remaining;
if (rx_size == sz_remaining)
header.extension |= IPC_FINAL_BLOCK(1);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, NULL, 0,
((char *)param) + data_offset,
msg->param_data_size);
if (ret < 0) {
dev_err(ipc->dev,
"ipc: get large config fail, err: %d\n", ret);
return ret;
}
sz_remaining -= rx_size;
data_offset = msg->param_data_size - sz_remaining;
header.extension &= IPC_INITIAL_BLOCK_CLEAR;
header.extension &= IPC_DATA_OFFSET_SZ_CLEAR;
header.extension |= IPC_INITIAL_BLOCK(1);
header.extension |= IPC_DATA_OFFSET_SZ(data_offset);
}
return ret;
}
int skl_sst_ipc_load_library(struct sst_generic_ipc *ipc,
u8 dma_id, u8 table_id)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret = 0;
header.primary = IPC_MSG_TARGET(IPC_FW_GEN_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_GLB_LOAD_LIBRARY);
header.primary |= IPC_MOD_INSTANCE_ID(table_id);
header.primary |= IPC_MOD_ID(dma_id);
ret = sst_ipc_tx_message_wait(ipc, *ipc_header, NULL, 0, NULL, 0);
if (ret < 0)
dev_err(ipc->dev, "ipc: load lib failed\n");
return ret;
}
int skl_ipc_set_d0ix(struct sst_generic_ipc *ipc, struct skl_ipc_d0ix_msg *msg)
{
struct skl_ipc_header header = {0};
u64 *ipc_header = (u64 *)(&header);
int ret;
header.primary = IPC_MSG_TARGET(IPC_MOD_MSG);
header.primary |= IPC_MSG_DIR(IPC_MSG_REQUEST);
header.primary |= IPC_GLB_TYPE(IPC_MOD_SET_D0IX);
header.primary |= IPC_MOD_INSTANCE_ID(msg->instance_id);
header.primary |= IPC_MOD_ID(msg->module_id);
header.extension = IPC_D0IX_WAKE(msg->wake);
header.extension |= IPC_D0IX_STREAMING(msg->streaming);
dev_dbg(ipc->dev, "In %s primary=%x ext=%x\n", __func__,
header.primary, header.extension);
ret = sst_ipc_tx_message_nopm(ipc, *ipc_header, NULL, 0, NULL, 0);
if (ret < 0)
dev_err(ipc->dev, "ipc: set d0ix failed, err %d\n", ret);
return ret;
}
