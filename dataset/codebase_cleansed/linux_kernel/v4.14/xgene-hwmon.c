static u16 xgene_word_tst_and_clr(u16 *addr, u16 mask)
{
u16 ret, val;
val = le16_to_cpu(READ_ONCE(*addr));
ret = val & mask;
val &= ~mask;
WRITE_ONCE(*addr, cpu_to_le16(val));
return ret;
}
static int xgene_hwmon_pcc_rd(struct xgene_hwmon_dev *ctx, u32 *msg)
{
struct acpi_pcct_shared_memory *generic_comm_base = ctx->pcc_comm_addr;
u32 *ptr = (void *)(generic_comm_base + 1);
int rc, i;
u16 val;
mutex_lock(&ctx->rd_mutex);
init_completion(&ctx->rd_complete);
ctx->resp_pending = true;
WRITE_ONCE(generic_comm_base->signature,
cpu_to_le32(PCC_SIGNATURE_MASK | ctx->mbox_idx));
WRITE_ONCE(generic_comm_base->command,
cpu_to_le16(MSG_TYPE(msg[0]) | PCCC_GENERATE_DB_INT));
val = le16_to_cpu(READ_ONCE(generic_comm_base->status));
val &= ~PCCS_CMD_COMPLETE;
WRITE_ONCE(generic_comm_base->status, cpu_to_le16(val));
for (i = 0; i < sizeof(struct slimpro_resp_msg) / 4; i++)
WRITE_ONCE(ptr[i], cpu_to_le32(msg[i]));
rc = mbox_send_message(ctx->mbox_chan, msg);
if (rc < 0) {
dev_err(ctx->dev, "Mailbox send error %d\n", rc);
goto err;
}
if (!wait_for_completion_timeout(&ctx->rd_complete,
usecs_to_jiffies(ctx->usecs_lat))) {
dev_err(ctx->dev, "Mailbox operation timed out\n");
rc = -ETIMEDOUT;
goto err;
}
if (MSG_TYPE(ctx->sync_msg.msg) == MSG_TYPE_ERR) {
rc = -EINVAL;
goto err;
}
msg[0] = ctx->sync_msg.msg;
msg[1] = ctx->sync_msg.param1;
msg[2] = ctx->sync_msg.param2;
err:
mbox_chan_txdone(ctx->mbox_chan, 0);
ctx->resp_pending = false;
mutex_unlock(&ctx->rd_mutex);
return rc;
}
static int xgene_hwmon_rd(struct xgene_hwmon_dev *ctx, u32 *msg)
{
int rc;
mutex_lock(&ctx->rd_mutex);
init_completion(&ctx->rd_complete);
ctx->resp_pending = true;
rc = mbox_send_message(ctx->mbox_chan, msg);
if (rc < 0) {
dev_err(ctx->dev, "Mailbox send error %d\n", rc);
goto err;
}
if (!wait_for_completion_timeout(&ctx->rd_complete,
msecs_to_jiffies(MBOX_OP_TIMEOUTMS))) {
dev_err(ctx->dev, "Mailbox operation timed out\n");
rc = -ETIMEDOUT;
goto err;
}
if (MSG_TYPE(ctx->sync_msg.msg) == MSG_TYPE_ERR) {
rc = -EINVAL;
goto err;
}
msg[0] = ctx->sync_msg.msg;
msg[1] = ctx->sync_msg.param1;
msg[2] = ctx->sync_msg.param2;
err:
ctx->resp_pending = false;
mutex_unlock(&ctx->rd_mutex);
return rc;
}
static int xgene_hwmon_reg_map_rd(struct xgene_hwmon_dev *ctx, u32 addr,
u32 *data)
{
u32 msg[3];
int rc;
msg[0] = SENSOR_RD_MSG;
msg[1] = SENSOR_RD_EN_ADDR(addr);
msg[2] = 0;
if (acpi_disabled)
rc = xgene_hwmon_rd(ctx, msg);
else
rc = xgene_hwmon_pcc_rd(ctx, msg);
if (rc < 0)
return rc;
if (msg[1] & SENSOR_INVALID_DATA)
return -ENODATA;
*data = msg[1];
return rc;
}
static int xgene_hwmon_get_notification_msg(struct xgene_hwmon_dev *ctx,
u32 *amsg)
{
u32 msg[3];
int rc;
msg[0] = TPC_EN_MSG(PWRMGMT_SUBTYPE_TPC, TPC_GET_ALARM, 0);
msg[1] = 0;
msg[2] = 0;
rc = xgene_hwmon_pcc_rd(ctx, msg);
if (rc < 0)
return rc;
amsg[0] = msg[0];
amsg[1] = msg[1];
amsg[2] = msg[2];
return rc;
}
static int xgene_hwmon_get_cpu_pwr(struct xgene_hwmon_dev *ctx, u32 *val)
{
u32 watt, mwatt;
int rc;
rc = xgene_hwmon_reg_map_rd(ctx, PMD_PWR_REG, &watt);
if (rc < 0)
return rc;
rc = xgene_hwmon_reg_map_rd(ctx, PMD_PWR_MW_REG, &mwatt);
if (rc < 0)
return rc;
*val = WATT_TO_mWATT(watt) + mwatt;
return 0;
}
static int xgene_hwmon_get_io_pwr(struct xgene_hwmon_dev *ctx, u32 *val)
{
u32 watt, mwatt;
int rc;
rc = xgene_hwmon_reg_map_rd(ctx, SOC_PWR_REG, &watt);
if (rc < 0)
return rc;
rc = xgene_hwmon_reg_map_rd(ctx, SOC_PWR_MW_REG, &mwatt);
if (rc < 0)
return rc;
*val = WATT_TO_mWATT(watt) + mwatt;
return 0;
}
static int xgene_hwmon_get_temp(struct xgene_hwmon_dev *ctx, u32 *val)
{
return xgene_hwmon_reg_map_rd(ctx, SOC_TEMP_REG, val);
}
static ssize_t temp1_input_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct xgene_hwmon_dev *ctx = dev_get_drvdata(dev);
int rc, temp;
u32 val;
rc = xgene_hwmon_get_temp(ctx, &val);
if (rc < 0)
return rc;
temp = sign_extend32(val, TEMP_NEGATIVE_BIT);
return snprintf(buf, PAGE_SIZE, "%d\n", CELSIUS_TO_mCELSIUS(temp));
}
static ssize_t temp1_label_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "SoC Temperature\n");
}
static ssize_t temp1_critical_alarm_show(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct xgene_hwmon_dev *ctx = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ctx->temp_critical_alarm);
}
static ssize_t power1_label_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "CPU power\n");
}
static ssize_t power2_label_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "IO power\n");
}
static ssize_t power1_input_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct xgene_hwmon_dev *ctx = dev_get_drvdata(dev);
u32 val;
int rc;
rc = xgene_hwmon_get_cpu_pwr(ctx, &val);
if (rc < 0)
return rc;
return snprintf(buf, PAGE_SIZE, "%u\n", mWATT_TO_uWATT(val));
}
static ssize_t power2_input_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct xgene_hwmon_dev *ctx = dev_get_drvdata(dev);
u32 val;
int rc;
rc = xgene_hwmon_get_io_pwr(ctx, &val);
if (rc < 0)
return rc;
return snprintf(buf, PAGE_SIZE, "%u\n", mWATT_TO_uWATT(val));
}
static int xgene_hwmon_tpc_alarm(struct xgene_hwmon_dev *ctx,
struct slimpro_resp_msg *amsg)
{
ctx->temp_critical_alarm = !!amsg->param2;
sysfs_notify(&ctx->dev->kobj, NULL, "temp1_critical_alarm");
return 0;
}
static void xgene_hwmon_process_pwrmsg(struct xgene_hwmon_dev *ctx,
struct slimpro_resp_msg *amsg)
{
if ((MSG_SUBTYPE(amsg->msg) == PWRMGMT_SUBTYPE_TPC) &&
(TPC_CMD(amsg->msg) == TPC_ALARM))
xgene_hwmon_tpc_alarm(ctx, amsg);
}
static void xgene_hwmon_evt_work(struct work_struct *work)
{
struct slimpro_resp_msg amsg;
struct xgene_hwmon_dev *ctx;
int ret;
ctx = container_of(work, struct xgene_hwmon_dev, workq);
while (kfifo_out_spinlocked(&ctx->async_msg_fifo, &amsg,
sizeof(struct slimpro_resp_msg),
&ctx->kfifo_lock)) {
if (!acpi_disabled) {
ret = xgene_hwmon_get_notification_msg(ctx,
(u32 *)&amsg);
if (ret < 0)
continue;
}
if (MSG_TYPE(amsg.msg) == MSG_TYPE_PWRMGMT)
xgene_hwmon_process_pwrmsg(ctx, &amsg);
}
}
static int xgene_hwmon_rx_ready(struct xgene_hwmon_dev *ctx, void *msg)
{
if (IS_ERR_OR_NULL(ctx->hwmon_dev) && !ctx->resp_pending) {
kfifo_in_spinlocked(&ctx->async_msg_fifo, msg,
sizeof(struct slimpro_resp_msg),
&ctx->kfifo_lock);
return -ENODEV;
}
return 0;
}
static void xgene_hwmon_rx_cb(struct mbox_client *cl, void *msg)
{
struct xgene_hwmon_dev *ctx = to_xgene_hwmon_dev(cl);
if (xgene_hwmon_rx_ready(ctx, msg) < 0)
return;
if (ctx->resp_pending &&
((MSG_TYPE(((u32 *)msg)[0]) == MSG_TYPE_ERR) ||
(MSG_TYPE(((u32 *)msg)[0]) == MSG_TYPE_DBG &&
MSG_SUBTYPE(((u32 *)msg)[0]) == DBG_SUBTYPE_SENSOR_READ) ||
(MSG_TYPE(((u32 *)msg)[0]) == MSG_TYPE_PWRMGMT &&
MSG_SUBTYPE(((u32 *)msg)[0]) == PWRMGMT_SUBTYPE_TPC &&
TPC_CMD(((u32 *)msg)[0]) == TPC_ALARM))) {
ctx->sync_msg.msg = ((u32 *)msg)[0];
ctx->sync_msg.param1 = ((u32 *)msg)[1];
ctx->sync_msg.param2 = ((u32 *)msg)[2];
complete(&ctx->rd_complete);
return;
}
kfifo_in_spinlocked(&ctx->async_msg_fifo, msg,
sizeof(struct slimpro_resp_msg), &ctx->kfifo_lock);
schedule_work(&ctx->workq);
}
static void xgene_hwmon_pcc_rx_cb(struct mbox_client *cl, void *msg)
{
struct xgene_hwmon_dev *ctx = to_xgene_hwmon_dev(cl);
struct acpi_pcct_shared_memory *generic_comm_base = ctx->pcc_comm_addr;
struct slimpro_resp_msg amsg;
if (xgene_hwmon_rx_ready(ctx, &amsg) < 0)
return;
msg = generic_comm_base + 1;
if (!xgene_word_tst_and_clr(&generic_comm_base->status,
PCCS_SCI_DOORBEL))
return;
if (ctx->resp_pending &&
((MSG_TYPE(((u32 *)msg)[0]) == MSG_TYPE_ERR) ||
(MSG_TYPE(((u32 *)msg)[0]) == MSG_TYPE_DBG &&
MSG_SUBTYPE(((u32 *)msg)[0]) == DBG_SUBTYPE_SENSOR_READ) ||
(MSG_TYPE(((u32 *)msg)[0]) == MSG_TYPE_PWRMGMT &&
MSG_SUBTYPE(((u32 *)msg)[0]) == PWRMGMT_SUBTYPE_TPC &&
TPC_CMD(((u32 *)msg)[0]) == TPC_ALARM))) {
if (xgene_word_tst_and_clr(&generic_comm_base->status,
PCCS_CMD_COMPLETE)) {
ctx->sync_msg.msg = ((u32 *)msg)[0];
ctx->sync_msg.param1 = ((u32 *)msg)[1];
ctx->sync_msg.param2 = ((u32 *)msg)[2];
complete(&ctx->rd_complete);
return;
}
}
kfifo_in_spinlocked(&ctx->async_msg_fifo, &amsg,
sizeof(struct slimpro_resp_msg), &ctx->kfifo_lock);
schedule_work(&ctx->workq);
}
static void xgene_hwmon_tx_done(struct mbox_client *cl, void *msg, int ret)
{
if (ret) {
dev_dbg(cl->dev, "TX did not complete: CMD sent:%x, ret:%d\n",
*(u16 *)msg, ret);
} else {
dev_dbg(cl->dev, "TX completed. CMD sent:%x, ret:%d\n",
*(u16 *)msg, ret);
}
}
static int xgene_hwmon_probe(struct platform_device *pdev)
{
struct xgene_hwmon_dev *ctx;
struct mbox_client *cl;
int rc;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->dev = &pdev->dev;
platform_set_drvdata(pdev, ctx);
cl = &ctx->mbox_client;
spin_lock_init(&ctx->kfifo_lock);
mutex_init(&ctx->rd_mutex);
rc = kfifo_alloc(&ctx->async_msg_fifo,
sizeof(struct slimpro_resp_msg) * ASYNC_MSG_FIFO_SIZE,
GFP_KERNEL);
if (rc)
return -ENOMEM;
INIT_WORK(&ctx->workq, xgene_hwmon_evt_work);
cl->dev = &pdev->dev;
cl->tx_done = xgene_hwmon_tx_done;
cl->tx_block = false;
cl->tx_tout = MBOX_OP_TIMEOUTMS;
cl->knows_txdone = false;
if (acpi_disabled) {
cl->rx_callback = xgene_hwmon_rx_cb;
ctx->mbox_chan = mbox_request_channel(cl, 0);
if (IS_ERR(ctx->mbox_chan)) {
dev_err(&pdev->dev,
"SLIMpro mailbox channel request failed\n");
rc = -ENODEV;
goto out_mbox_free;
}
} else {
struct acpi_pcct_hw_reduced *cppc_ss;
if (device_property_read_u32(&pdev->dev, "pcc-channel",
&ctx->mbox_idx)) {
dev_err(&pdev->dev, "no pcc-channel property\n");
rc = -ENODEV;
goto out_mbox_free;
}
cl->rx_callback = xgene_hwmon_pcc_rx_cb;
ctx->mbox_chan = pcc_mbox_request_channel(cl, ctx->mbox_idx);
if (IS_ERR(ctx->mbox_chan)) {
dev_err(&pdev->dev,
"PPC channel request failed\n");
rc = -ENODEV;
goto out_mbox_free;
}
cppc_ss = ctx->mbox_chan->con_priv;
if (!cppc_ss) {
dev_err(&pdev->dev, "PPC subspace not found\n");
rc = -ENODEV;
goto out;
}
if (!ctx->mbox_chan->mbox->txdone_irq) {
dev_err(&pdev->dev, "PCC IRQ not supported\n");
rc = -ENODEV;
goto out;
}
ctx->comm_base_addr = cppc_ss->base_address;
if (ctx->comm_base_addr) {
ctx->pcc_comm_addr = memremap(ctx->comm_base_addr,
cppc_ss->length,
MEMREMAP_WB);
} else {
dev_err(&pdev->dev, "Failed to get PCC comm region\n");
rc = -ENODEV;
goto out;
}
if (!ctx->pcc_comm_addr) {
dev_err(&pdev->dev,
"Failed to ioremap PCC comm region\n");
rc = -ENOMEM;
goto out;
}
ctx->usecs_lat = PCC_NUM_RETRIES * cppc_ss->latency;
}
ctx->hwmon_dev = hwmon_device_register_with_groups(ctx->dev,
"apm_xgene",
ctx,
xgene_hwmon_groups);
if (IS_ERR(ctx->hwmon_dev)) {
dev_err(&pdev->dev, "Failed to register HW monitor device\n");
rc = PTR_ERR(ctx->hwmon_dev);
goto out;
}
schedule_work(&ctx->workq);
dev_info(&pdev->dev, "APM X-Gene SoC HW monitor driver registered\n");
return 0;
out:
if (acpi_disabled)
mbox_free_channel(ctx->mbox_chan);
else
pcc_mbox_free_channel(ctx->mbox_chan);
out_mbox_free:
kfifo_free(&ctx->async_msg_fifo);
return rc;
}
static int xgene_hwmon_remove(struct platform_device *pdev)
{
struct xgene_hwmon_dev *ctx = platform_get_drvdata(pdev);
hwmon_device_unregister(ctx->hwmon_dev);
kfifo_free(&ctx->async_msg_fifo);
if (acpi_disabled)
mbox_free_channel(ctx->mbox_chan);
else
pcc_mbox_free_channel(ctx->mbox_chan);
return 0;
}
