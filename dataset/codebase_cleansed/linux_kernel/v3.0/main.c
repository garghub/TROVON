static inline int __iwmct_tx(struct iwmct_priv *priv, void *src, int count)
{
return sdio_memcpy_toio(priv->func, IWMC_SDIO_DATA_ADDR, src, count);
}
int iwmct_tx(struct iwmct_priv *priv, void *src, int count)
{
int ret;
sdio_claim_host(priv->func);
ret = __iwmct_tx(priv, src, count);
sdio_release_host(priv->func);
return ret;
}
static void iwmct_rescan_worker(struct work_struct *ws)
{
struct iwmct_priv *priv;
int ret;
priv = container_of(ws, struct iwmct_priv, bus_rescan_worker);
LOG_INFO(priv, FW_MSG, "Calling bus_rescan\n");
ret = bus_rescan_devices(priv->func->dev.bus);
if (ret < 0)
LOG_INFO(priv, INIT, "bus_rescan_devices FAILED!!!\n");
}
static void op_top_message(struct iwmct_priv *priv, struct top_msg *msg)
{
switch (msg->hdr.opcode) {
case OP_OPR_ALIVE:
LOG_INFO(priv, FW_MSG, "Got ALIVE from device, wake rescan\n");
schedule_work(&priv->bus_rescan_worker);
break;
default:
LOG_INFO(priv, FW_MSG, "Received msg opcode 0x%X\n",
msg->hdr.opcode);
break;
}
}
static void handle_top_message(struct iwmct_priv *priv, u8 *buf, int len)
{
struct top_msg *msg;
msg = (struct top_msg *)buf;
if (msg->hdr.type != COMM_TYPE_D2H) {
LOG_ERROR(priv, FW_MSG,
"Message from TOP with invalid message type 0x%X\n",
msg->hdr.type);
return;
}
if (len < sizeof(msg->hdr)) {
LOG_ERROR(priv, FW_MSG,
"Message from TOP is too short for message header "
"received %d bytes, expected at least %zd bytes\n",
len, sizeof(msg->hdr));
return;
}
if (len < le16_to_cpu(msg->hdr.length) + sizeof(msg->hdr)) {
LOG_ERROR(priv, FW_MSG,
"Message length (%d bytes) is shorter than "
"in header (%d bytes)\n",
len, le16_to_cpu(msg->hdr.length));
return;
}
switch (msg->hdr.category) {
case COMM_CATEGORY_OPERATIONAL:
op_top_message(priv, (struct top_msg *)buf);
break;
case COMM_CATEGORY_DEBUG:
case COMM_CATEGORY_TESTABILITY:
case COMM_CATEGORY_DIAGNOSTICS:
iwmct_log_top_message(priv, buf, len);
break;
default:
LOG_ERROR(priv, FW_MSG,
"Message from TOP with unknown category 0x%X\n",
msg->hdr.category);
break;
}
}
int iwmct_send_hcmd(struct iwmct_priv *priv, u8 *cmd, u16 len)
{
int ret;
u8 *buf;
LOG_TRACE(priv, FW_MSG, "Sending hcmd:\n");
((struct top_msg *)cmd)->hdr.flags |= CMD_FLAG_PADDING_256;
LOG_HEXDUMP(FW_MSG, cmd, len);
if (len > FW_HCMD_BLOCK_SIZE) {
LOG_ERROR(priv, FW_MSG, "size %d exceeded hcmd max size %d\n",
len, FW_HCMD_BLOCK_SIZE);
return -1;
}
buf = kzalloc(FW_HCMD_BLOCK_SIZE, GFP_KERNEL);
if (!buf) {
LOG_ERROR(priv, FW_MSG, "kzalloc error, buf size %d\n",
FW_HCMD_BLOCK_SIZE);
return -1;
}
memcpy(buf, cmd, len);
ret = iwmct_tx(priv, buf, FW_HCMD_BLOCK_SIZE);
kfree(buf);
return ret;
}
static void iwmct_irq_read_worker(struct work_struct *ws)
{
struct iwmct_priv *priv;
struct iwmct_work_struct *read_req;
__le32 *buf = NULL;
int ret;
int iosize;
u32 barker;
bool is_barker;
priv = container_of(ws, struct iwmct_priv, isr_worker);
LOG_TRACE(priv, IRQ, "enter iwmct_irq_read_worker %p\n", ws);
sdio_claim_host(priv->func);
if (list_empty(&priv->read_req_list)) {
LOG_ERROR(priv, IRQ, "read_req_list empty in read worker\n");
goto exit_release;
}
read_req = list_entry(priv->read_req_list.next,
struct iwmct_work_struct, list);
list_del(&read_req->list);
iosize = read_req->iosize;
kfree(read_req);
buf = kzalloc(iosize, GFP_KERNEL);
if (!buf) {
LOG_ERROR(priv, IRQ, "kzalloc error, buf size %d\n", iosize);
goto exit_release;
}
LOG_INFO(priv, IRQ, "iosize=%d, buf=%p, func=%d\n",
iosize, buf, priv->func->num);
ret = sdio_memcpy_fromio(priv->func, buf, IWMC_SDIO_DATA_ADDR, iosize);
if (ret) {
LOG_ERROR(priv, IRQ, "error %d reading buffer\n", ret);
goto exit_release;
}
LOG_HEXDUMP(IRQ, (u8 *)buf, iosize);
barker = le32_to_cpu(buf[0]);
if (barker == IWMC_BARKER_ACK ||
(barker & BARKER_DNLOAD_BARKER_MSK) == IWMC_BARKER_REBOOT) {
is_barker = (buf[1] == buf[0]) &&
(buf[2] == buf[0]) &&
(buf[3] == buf[0]);
if (!is_barker) {
LOG_WARNING(priv, IRQ,
"Potentially inconsistent barker "
"%08X_%08X_%08X_%08X\n",
le32_to_cpu(buf[0]), le32_to_cpu(buf[1]),
le32_to_cpu(buf[2]), le32_to_cpu(buf[3]));
}
} else {
is_barker = false;
}
if (!is_barker) {
sdio_release_host(priv->func);
handle_top_message(priv, (u8 *)buf, iosize);
goto exit;
} else if (barker == IWMC_BARKER_ACK) {
if (atomic_read(&priv->dev_sync) == 0) {
LOG_ERROR(priv, IRQ,
"ACK barker arrived out-of-sync\n");
goto exit_release;
}
atomic_set(&priv->dev_sync, 0);
LOG_INFO(priv, IRQ, "ACK barker arrived "
"- starting FW download\n");
} else {
LOG_INFO(priv, IRQ, "Received reboot barker: %x\n", barker);
priv->barker = barker;
if (barker & BARKER_DNLOAD_SYNC_MSK) {
ret = __iwmct_tx(priv, buf, iosize);
if (ret) {
LOG_ERROR(priv, IRQ,
"error %d echoing barker\n", ret);
goto exit_release;
}
LOG_INFO(priv, IRQ, "Echoing barker to device\n");
atomic_set(&priv->dev_sync, 1);
goto exit_release;
}
LOG_INFO(priv, IRQ, "No sync requested "
"- starting FW download\n");
}
sdio_release_host(priv->func);
if (priv->dbg.fw_download)
iwmct_fw_load(priv);
else
LOG_ERROR(priv, IRQ, "FW download not allowed\n");
goto exit;
exit_release:
sdio_release_host(priv->func);
exit:
kfree(buf);
LOG_TRACE(priv, IRQ, "exit iwmct_irq_read_worker\n");
}
static void iwmct_irq(struct sdio_func *func)
{
struct iwmct_priv *priv;
int val, ret;
int iosize;
int addr = IWMC_SDIO_INTR_GET_SIZE_ADDR;
struct iwmct_work_struct *read_req;
priv = sdio_get_drvdata(func);
LOG_TRACE(priv, IRQ, "enter iwmct_irq\n");
val = sdio_readb(func, IWMC_SDIO_INTR_STATUS_ADDR, &ret);
LOG_TRACE(priv, IRQ, "iir value = %d, ret=%d\n", val, ret);
if (!val) {
LOG_ERROR(priv, IRQ, "iir = 0, exiting ISR\n");
goto exit_clear_intr;
}
val = sdio_readb(priv->func, addr++, &ret);
iosize = val;
val = sdio_readb(priv->func, addr++, &ret);
iosize += val << 8;
LOG_INFO(priv, IRQ, "READ size %d\n", iosize);
if (iosize == 0) {
LOG_ERROR(priv, IRQ, "READ size %d, exiting ISR\n", iosize);
goto exit_clear_intr;
}
read_req = kzalloc(sizeof(struct iwmct_work_struct), GFP_KERNEL);
if (!read_req) {
LOG_ERROR(priv, IRQ, "failed to allocate read_req, exit ISR\n");
goto exit_clear_intr;
}
INIT_LIST_HEAD(&read_req->list);
read_req->iosize = iosize;
list_add_tail(&priv->read_req_list, &read_req->list);
sdio_writeb(func, 1, IWMC_SDIO_INTR_CLEAR_ADDR, &ret);
schedule_work(&priv->isr_worker);
LOG_TRACE(priv, IRQ, "exit iwmct_irq\n");
return;
exit_clear_intr:
sdio_writeb(func, 1, IWMC_SDIO_INTR_CLEAR_ADDR, &ret);
}
void iwmct_dbg_init_params(struct iwmct_priv *priv)
{
#ifdef CONFIG_IWMC3200TOP_DEBUG
int i;
for (i = 0; i < log_level_argc; i++) {
dev_notice(&priv->func->dev, "log_level[%d]=0x%X\n",
i, log_level[i]);
iwmct_log_set_filter((log_level[i] >> 8) & 0xFF,
log_level[i] & 0xFF);
}
for (i = 0; i < log_level_fw_argc; i++) {
dev_notice(&priv->func->dev, "log_level_fw[%d]=0x%X\n",
i, log_level_fw[i]);
iwmct_log_set_fw_filter((log_level_fw[i] >> 8) & 0xFF,
log_level_fw[i] & 0xFF);
}
#endif
priv->dbg.blocks = blocks;
LOG_INFO(priv, INIT, "blocks=%d\n", blocks);
priv->dbg.dump = (bool)dump;
LOG_INFO(priv, INIT, "dump=%d\n", dump);
priv->dbg.jump = (bool)jump;
LOG_INFO(priv, INIT, "jump=%d\n", jump);
priv->dbg.direct = (bool)direct;
LOG_INFO(priv, INIT, "direct=%d\n", direct);
priv->dbg.checksum = (bool)checksum;
LOG_INFO(priv, INIT, "checksum=%d\n", checksum);
priv->dbg.fw_download = (bool)fw_download;
LOG_INFO(priv, INIT, "fw_download=%d\n", fw_download);
priv->dbg.block_size = block_size;
LOG_INFO(priv, INIT, "block_size=%d\n", block_size);
priv->dbg.download_trans_blks = download_trans_blks;
LOG_INFO(priv, INIT, "download_trans_blks=%d\n", download_trans_blks);
}
static ssize_t show_iwmct_fw_version(struct device *d,
struct device_attribute *attr, char *buf)
{
struct iwmct_priv *priv = dev_get_drvdata(d);
return sprintf(buf, "%s\n", priv->dbg.label_fw);
}
static int iwmct_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
struct iwmct_priv *priv;
int ret;
int val = 1;
int addr = IWMC_SDIO_INTR_ENABLE_ADDR;
dev_dbg(&func->dev, "enter iwmct_probe\n");
dev_dbg(&func->dev, "IRQ polling period id %u msecs, HZ is %d\n",
jiffies_to_msecs(2147483647), HZ);
priv = kzalloc(sizeof(struct iwmct_priv), GFP_KERNEL);
if (!priv) {
dev_err(&func->dev, "kzalloc error\n");
return -ENOMEM;
}
priv->func = func;
sdio_set_drvdata(func, priv);
INIT_WORK(&priv->bus_rescan_worker, iwmct_rescan_worker);
INIT_WORK(&priv->isr_worker, iwmct_irq_read_worker);
init_waitqueue_head(&priv->wait_q);
sdio_claim_host(func);
func->enable_timeout = 10;
ret = sdio_set_block_size(func, priv->dbg.block_size);
if (ret) {
LOG_ERROR(priv, INIT,
"sdio_set_block_size() failure: %d\n", ret);
goto error_sdio_enable;
}
ret = sdio_enable_func(func);
if (ret) {
LOG_ERROR(priv, INIT, "sdio_enable_func() failure: %d\n", ret);
goto error_sdio_enable;
}
atomic_set(&priv->reset, 0);
atomic_set(&priv->dev_sync, 0);
INIT_LIST_HEAD(&priv->read_req_list);
iwmct_dbg_init_params(priv);
ret = sysfs_create_group(&func->dev.kobj, &iwmct_attribute_group);
if (ret) {
LOG_ERROR(priv, INIT, "Failed to register attributes and "
"initialize module_params\n");
goto error_dev_attrs;
}
iwmct_dbgfs_register(priv, DRV_NAME);
if (!priv->dbg.direct && priv->dbg.download_trans_blks > 8) {
LOG_INFO(priv, INIT,
"Reducing transaction to 8 blocks = 2K (from %d)\n",
priv->dbg.download_trans_blks);
priv->dbg.download_trans_blks = 8;
}
priv->trans_len = priv->dbg.download_trans_blks * priv->dbg.block_size;
LOG_INFO(priv, INIT, "Transaction length = %d\n", priv->trans_len);
ret = sdio_claim_irq(func, iwmct_irq);
if (ret) {
LOG_ERROR(priv, INIT, "sdio_claim_irq() failure: %d\n", ret);
goto error_claim_irq;
}
sdio_writeb(priv->func, val, addr, &ret);
if (ret) {
LOG_ERROR(priv, INIT, "Failure writing to "
"Interrupt Enable Register (%d): %d\n", addr, ret);
goto error_enable_int;
}
sdio_release_host(func);
LOG_INFO(priv, INIT, "exit iwmct_probe\n");
return ret;
error_enable_int:
sdio_release_irq(func);
error_claim_irq:
sdio_disable_func(func);
error_dev_attrs:
iwmct_dbgfs_unregister(priv->dbgfs);
sysfs_remove_group(&func->dev.kobj, &iwmct_attribute_group);
error_sdio_enable:
sdio_release_host(func);
return ret;
}
static void iwmct_remove(struct sdio_func *func)
{
struct iwmct_work_struct *read_req;
struct iwmct_priv *priv = sdio_get_drvdata(func);
LOG_INFO(priv, INIT, "enter\n");
sdio_claim_host(func);
sdio_release_irq(func);
sdio_release_host(func);
flush_work_sync(&priv->bus_rescan_worker);
flush_work_sync(&priv->isr_worker);
sdio_claim_host(func);
sdio_disable_func(func);
sysfs_remove_group(&func->dev.kobj, &iwmct_attribute_group);
iwmct_dbgfs_unregister(priv->dbgfs);
sdio_release_host(func);
while (!list_empty(&priv->read_req_list)) {
read_req = list_entry(priv->read_req_list.next,
struct iwmct_work_struct, list);
list_del(&read_req->list);
kfree(read_req);
}
kfree(priv);
}
static int __init iwmct_init(void)
{
int rc;
iwmct_log_set_filter(LOG_SRC_ALL, LOG_SEV_FILTER_RUNTIME);
iwmct_log_set_filter(LOG_SRC_FW_MSG, LOG_SEV_FW_FILTER_ALL);
iwmct_log_set_fw_filter(LOG_SRC_ALL, FW_LOG_SEV_FILTER_RUNTIME);
rc = sdio_register_driver(&iwmct_driver);
return rc;
}
static void __exit iwmct_exit(void)
{
sdio_unregister_driver(&iwmct_driver);
}
