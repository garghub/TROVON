static int ucsi_acpi_cmd(struct ucsi *ucsi, struct ucsi_control *ctrl)
{
uuid_le uuid = UUID_LE(0x6f8398c2, 0x7ca4, 0x11e4,
0xad, 0x36, 0x63, 0x10, 0x42, 0xb5, 0x00, 0x8f);
union acpi_object *obj;
ucsi->data->ctrl.raw_cmd = ctrl->raw_cmd;
obj = acpi_evaluate_dsm(ACPI_HANDLE(ucsi->dev), uuid.b, 1, 1, NULL);
if (!obj) {
dev_err(ucsi->dev, "%s: failed to evaluate _DSM\n", __func__);
return -EIO;
}
ACPI_FREE(obj);
return 0;
}
static void ucsi_acpi_notify(acpi_handle handle, u32 event, void *data)
{
struct ucsi *ucsi = data;
struct ucsi_cci *cci;
spin_lock(&ucsi->dev_lock);
ucsi->status = UCSI_IDLE;
cci = &ucsi->data->cci;
if (!ucsi->data->raw_cci) {
if (test_bit(EVENT_PENDING, &ucsi->flags))
complete(&ucsi->complete);
else
dev_WARN(ucsi->dev, "spurious notification\n");
goto out_unlock;
}
if (test_bit(COMMAND_PENDING, &ucsi->flags)) {
if (cci->busy) {
ucsi->status = UCSI_BUSY;
complete(&ucsi->complete);
goto out_unlock;
} else if (cci->ack_complete || cci->cmd_complete) {
if (cci->error && cci->cmd_complete)
ucsi->status = UCSI_ERROR;
ucsi->data->ctrl.raw_cmd = 0;
complete(&ucsi->complete);
}
}
if (cci->connector_change) {
struct ucsi_connector *con;
if (!ucsi->connector)
goto out_unlock;
con = ucsi->connector + (cci->connector_change - 1);
if (!test_and_set_bit(EVENT_PENDING, &ucsi->flags))
schedule_work(&con->work);
}
out_unlock:
spin_unlock(&ucsi->dev_lock);
}
static int ucsi_ack(struct ucsi *ucsi, u8 cmd)
{
struct ucsi_control ctrl;
int ret;
ctrl.cmd.cmd = UCSI_ACK_CC_CI;
ctrl.cmd.length = 0;
ctrl.cmd.data = cmd;
ret = ucsi_acpi_cmd(ucsi, &ctrl);
if (ret)
return ret;
ret = wait_for_completion_timeout(&ucsi->complete,
msecs_to_jiffies(UCSI_TIMEOUT_MS));
if (!ret)
return -ETIMEDOUT;
return 0;
}
static int ucsi_run_cmd(struct ucsi *ucsi, struct ucsi_control *ctrl,
void *data, size_t size)
{
u16 err_value = 0;
int ret;
set_bit(COMMAND_PENDING, &ucsi->flags);
ret = ucsi_acpi_cmd(ucsi, ctrl);
if (ret)
goto err_clear_flag;
ret = wait_for_completion_timeout(&ucsi->complete,
msecs_to_jiffies(UCSI_TIMEOUT_MS));
if (!ret) {
ret = -ETIMEDOUT;
goto err_clear_flag;
}
switch (ucsi->status) {
case UCSI_IDLE:
if (data)
memcpy(data, ucsi->data->message_in, size);
ret = ucsi_ack(ucsi, UCSI_ACK_CMD);
break;
case UCSI_BUSY:
ret = -EBUSY;
goto err_clear_flag;
case UCSI_ERROR:
ret = ucsi_ack(ucsi, UCSI_ACK_CMD);
if (ret)
goto err_clear_flag;
ctrl->cmd.cmd = UCSI_GET_ERROR_STATUS;
ctrl->cmd.length = 0;
ctrl->cmd.data = 0;
ret = ucsi_acpi_cmd(ucsi, ctrl);
if (ret)
goto err_clear_flag;
ret = wait_for_completion_timeout(&ucsi->complete,
msecs_to_jiffies(UCSI_TIMEOUT_MS));
if (!ret) {
ret = -ETIMEDOUT;
goto err_clear_flag;
}
memcpy(&err_value, ucsi->data->message_in, sizeof(err_value));
if (WARN_ON(ucsi->status == UCSI_ERROR)) {
ret = -ENODEV;
goto err_clear_flag;
}
ret = ucsi_ack(ucsi, UCSI_ACK_CMD);
if (ret)
goto err_clear_flag;
switch (err_value) {
case UCSI_ERROR_INCOMPATIBLE_PARTNER:
ret = -EOPNOTSUPP;
break;
case UCSI_ERROR_CC_COMMUNICATION_ERR:
ret = -ECOMM;
break;
case UCSI_ERROR_CONTRACT_NEGOTIATION_FAIL:
ret = -EIO;
break;
case UCSI_ERROR_DEAD_BATTERY:
dev_warn(ucsi->dev, "Dead battery condition!\n");
ret = -EPERM;
break;
case UCSI_ERROR_INVALID_CON_NUM:
case UCSI_ERROR_UNREGONIZED_CMD:
case UCSI_ERROR_INVALID_CMD_ARGUMENT:
default:
dev_warn(ucsi->dev,
"%s: possible UCSI driver bug - error %hu\n",
__func__, err_value);
ret = -EINVAL;
break;
}
break;
}
ctrl->raw_cmd = 0;
err_clear_flag:
clear_bit(COMMAND_PENDING, &ucsi->flags);
return ret;
}
static void ucsi_connector_change(struct work_struct *work)
{
struct ucsi_connector *con = container_of(work, struct ucsi_connector,
work);
struct ucsi_connector_status constat;
struct ucsi *ucsi = con->ucsi;
struct ucsi_control ctrl;
int ret;
mutex_lock(&ucsi->ppm_lock);
ctrl.cmd.cmd = UCSI_GET_CONNECTOR_STATUS;
ctrl.cmd.length = 0;
ctrl.cmd.data = con->num;
ret = ucsi_run_cmd(con->ucsi, &ctrl, &constat, sizeof(constat));
if (ret) {
dev_err(ucsi->dev, "%s: failed to read connector status (%d)\n",
__func__, ret);
goto out_ack_event;
}
if (!constat.connected || !(constat.change &
(UCSI_CONSTAT_PARTNER_CHANGE | UCSI_CONSTAT_CONNECT_CHANGE)) ||
constat.partner_flags & UCSI_CONSTAT_PARTNER_FLAG_ALT_MODE)
goto out_ack_event;
if (constat.partner_type & UCSI_CONSTAT_PARTNER_TYPE_DFP) {
ctrl.uor.cmd = UCSI_SET_UOR;
ctrl.uor.con_num = con->num;
ctrl.uor.role = UCSI_UOR_ROLE_DFP;
ret = ucsi_run_cmd(con->ucsi, &ctrl, NULL, 0);
if (ret)
dev_err(ucsi->dev, "%s: failed to swap role (%d)\n",
__func__, ret);
}
out_ack_event:
ucsi_ack(ucsi, UCSI_ACK_EVENT);
clear_bit(EVENT_PENDING, &ucsi->flags);
mutex_unlock(&ucsi->ppm_lock);
}
static int ucsi_reset_ppm(struct ucsi *ucsi)
{
int timeout = UCSI_TIMEOUT_MS;
struct ucsi_control ctrl;
int ret;
memset(&ctrl, 0, sizeof(ctrl));
ctrl.cmd.cmd = UCSI_PPM_RESET;
ret = ucsi_acpi_cmd(ucsi, &ctrl);
if (ret)
return ret;
while (!ucsi->data->cci.reset_complete && timeout--)
usleep_range(1000, 2000);
return 0;
}
static int ucsi_init(struct ucsi *ucsi)
{
struct ucsi_connector *con;
struct ucsi_control ctrl;
int ret;
int i;
init_completion(&ucsi->complete);
spin_lock_init(&ucsi->dev_lock);
mutex_init(&ucsi->ppm_lock);
ret = ucsi_reset_ppm(ucsi);
if (ret)
return ret;
ret = ucsi_reset_ppm(ucsi);
if (ret)
return ret;
mutex_lock(&ucsi->ppm_lock);
ctrl.cmd.cmd = UCSI_SET_NOTIFICATION_ENABLE;
ctrl.cmd.length = 0;
ctrl.cmd.data = UCSI_ENABLE_NTFY_CMD_COMPLETE | UCSI_ENABLE_NTFY_ERROR;
ret = ucsi_run_cmd(ucsi, &ctrl, NULL, 0);
if (ret)
goto err_reset;
ctrl.cmd.cmd = UCSI_GET_CAPABILITY;
ret = ucsi_run_cmd(ucsi, &ctrl, &ucsi->cap, sizeof(ucsi->cap));
if (ret)
goto err_reset;
if (!ucsi->cap.num_connectors) {
ret = -ENODEV;
goto err_reset;
}
ucsi->connector = devm_kcalloc(ucsi->dev, ucsi->cap.num_connectors,
sizeof(*ucsi->connector), GFP_KERNEL);
if (!ucsi->connector) {
ret = -ENOMEM;
goto err_reset;
}
for (i = 1, con = ucsi->connector; i < ucsi->cap.num_connectors + 1;
i++, con++) {
ctrl.cmd.cmd = UCSI_GET_CONNECTOR_CAPABILITY;
ctrl.cmd.data = i;
ret = ucsi_run_cmd(ucsi, &ctrl, &con->cap, sizeof(con->cap));
if (ret)
goto err_reset;
con->num = i;
con->ucsi = ucsi;
INIT_WORK(&con->work, ucsi_connector_change);
}
ctrl.cmd.cmd = UCSI_SET_NOTIFICATION_ENABLE;
ctrl.cmd.data = UCSI_ENABLE_NTFY_ALL;
ret = ucsi_run_cmd(ucsi, &ctrl, NULL, 0);
if (ret < 0)
goto err_reset;
mutex_unlock(&ucsi->ppm_lock);
return 0;
err_reset:
ucsi_reset_ppm(ucsi);
mutex_unlock(&ucsi->ppm_lock);
return ret;
}
static int ucsi_acpi_probe(struct platform_device *pdev)
{
struct resource *res;
acpi_status status;
struct ucsi *ucsi;
int ret;
ucsi = devm_kzalloc(&pdev->dev, sizeof(*ucsi), GFP_KERNEL);
if (!ucsi)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "missing memory resource\n");
return -ENODEV;
}
ucsi->data = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!ucsi->data)
return -ENOMEM;
ucsi->dev = &pdev->dev;
status = acpi_install_notify_handler(ACPI_HANDLE(&pdev->dev),
ACPI_ALL_NOTIFY,
ucsi_acpi_notify, ucsi);
if (ACPI_FAILURE(status))
return -ENODEV;
ret = ucsi_init(ucsi);
if (ret) {
acpi_remove_notify_handler(ACPI_HANDLE(&pdev->dev),
ACPI_ALL_NOTIFY,
ucsi_acpi_notify);
return ret;
}
platform_set_drvdata(pdev, ucsi);
return 0;
}
static int ucsi_acpi_remove(struct platform_device *pdev)
{
struct ucsi *ucsi = platform_get_drvdata(pdev);
acpi_remove_notify_handler(ACPI_HANDLE(&pdev->dev),
ACPI_ALL_NOTIFY, ucsi_acpi_notify);
if (wait_on_bit_timeout(&ucsi->flags, EVENT_PENDING,
TASK_UNINTERRUPTIBLE,
msecs_to_jiffies(UCSI_TIMEOUT_MS)))
dev_WARN(ucsi->dev, "%s: Events still pending\n", __func__);
ucsi_reset_ppm(ucsi);
return 0;
}
