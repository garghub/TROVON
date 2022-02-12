static int ec_response_timed_out(void)
{
unsigned long one_second = jiffies + HZ;
u8 data;
usleep_range(200, 300);
do {
if (!(cros_ec_lpc_read_bytes(EC_LPC_ADDR_HOST_CMD, 1, &data) &
EC_LPC_STATUS_BUSY_MASK))
return 0;
usleep_range(100, 200);
} while (time_before(jiffies, one_second));
return 1;
}
static int cros_ec_pkt_xfer_lpc(struct cros_ec_device *ec,
struct cros_ec_command *msg)
{
struct ec_host_request *request;
struct ec_host_response response;
u8 sum;
int ret = 0;
u8 *dout;
ret = cros_ec_prepare_tx(ec, msg);
cros_ec_lpc_write_bytes(EC_LPC_ADDR_HOST_PACKET, ret, ec->dout);
request = (struct ec_host_request *)ec->dout;
sum = EC_COMMAND_PROTOCOL_3;
cros_ec_lpc_write_bytes(EC_LPC_ADDR_HOST_CMD, 1, &sum);
if (ec_response_timed_out()) {
dev_warn(ec->dev, "EC responsed timed out\n");
ret = -EIO;
goto done;
}
msg->result = cros_ec_lpc_read_bytes(EC_LPC_ADDR_HOST_DATA, 1, &sum);
ret = cros_ec_check_result(ec, msg);
if (ret)
goto done;
dout = (u8 *)&response;
sum = cros_ec_lpc_read_bytes(EC_LPC_ADDR_HOST_PACKET, sizeof(response),
dout);
msg->result = response.result;
if (response.data_len > msg->insize) {
dev_err(ec->dev,
"packet too long (%d bytes, expected %d)",
response.data_len, msg->insize);
ret = -EMSGSIZE;
goto done;
}
sum += cros_ec_lpc_read_bytes(EC_LPC_ADDR_HOST_PACKET +
sizeof(response), response.data_len,
msg->data);
if (sum) {
dev_err(ec->dev,
"bad packet checksum %02x\n",
response.checksum);
ret = -EBADMSG;
goto done;
}
ret = response.data_len;
done:
return ret;
}
static int cros_ec_cmd_xfer_lpc(struct cros_ec_device *ec,
struct cros_ec_command *msg)
{
struct ec_lpc_host_args args;
u8 sum;
int ret = 0;
if (msg->outsize > EC_PROTO2_MAX_PARAM_SIZE ||
msg->insize > EC_PROTO2_MAX_PARAM_SIZE) {
dev_err(ec->dev,
"invalid buffer sizes (out %d, in %d)\n",
msg->outsize, msg->insize);
return -EINVAL;
}
args.flags = EC_HOST_ARGS_FLAG_FROM_HOST;
args.command_version = msg->version;
args.data_size = msg->outsize;
sum = msg->command + args.flags + args.command_version + args.data_size;
sum += cros_ec_lpc_write_bytes(EC_LPC_ADDR_HOST_PARAM, msg->outsize,
msg->data);
args.checksum = sum;
cros_ec_lpc_write_bytes(EC_LPC_ADDR_HOST_ARGS, sizeof(args),
(u8 *)&args);
sum = msg->command;
cros_ec_lpc_write_bytes(EC_LPC_ADDR_HOST_CMD, 1, &sum);
if (ec_response_timed_out()) {
dev_warn(ec->dev, "EC responsed timed out\n");
ret = -EIO;
goto done;
}
msg->result = cros_ec_lpc_read_bytes(EC_LPC_ADDR_HOST_DATA, 1, &sum);
ret = cros_ec_check_result(ec, msg);
if (ret)
goto done;
cros_ec_lpc_read_bytes(EC_LPC_ADDR_HOST_ARGS, sizeof(args),
(u8 *)&args);
if (args.data_size > msg->insize) {
dev_err(ec->dev,
"packet too long (%d bytes, expected %d)",
args.data_size, msg->insize);
ret = -ENOSPC;
goto done;
}
sum = msg->command + args.flags + args.command_version + args.data_size;
sum += cros_ec_lpc_read_bytes(EC_LPC_ADDR_HOST_PARAM, args.data_size,
msg->data);
if (args.checksum != sum) {
dev_err(ec->dev,
"bad packet checksum, expected %02x, got %02x\n",
args.checksum, sum);
ret = -EBADMSG;
goto done;
}
ret = args.data_size;
done:
return ret;
}
static int cros_ec_lpc_readmem(struct cros_ec_device *ec, unsigned int offset,
unsigned int bytes, void *dest)
{
int i = offset;
char *s = dest;
int cnt = 0;
if (offset >= EC_MEMMAP_SIZE - bytes)
return -EINVAL;
if (bytes) {
cros_ec_lpc_read_bytes(EC_LPC_ADDR_MEMMAP + offset, bytes, s);
return bytes;
}
for (; i < EC_MEMMAP_SIZE; i++, s++) {
cros_ec_lpc_read_bytes(EC_LPC_ADDR_MEMMAP + i, 1, s);
cnt++;
if (!*s)
break;
}
return cnt;
}
static void cros_ec_lpc_acpi_notify(acpi_handle device, u32 value, void *data)
{
struct cros_ec_device *ec_dev = data;
if (ec_dev->mkbp_event_supported &&
cros_ec_get_next_event(ec_dev, NULL) > 0)
blocking_notifier_call_chain(&ec_dev->event_notifier, 0,
ec_dev);
}
static int cros_ec_lpc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct acpi_device *adev;
acpi_status status;
struct cros_ec_device *ec_dev;
u8 buf[2];
int ret;
if (!devm_request_region(dev, EC_LPC_ADDR_MEMMAP, EC_MEMMAP_SIZE,
dev_name(dev))) {
dev_err(dev, "couldn't reserve memmap region\n");
return -EBUSY;
}
cros_ec_lpc_read_bytes(EC_LPC_ADDR_MEMMAP + EC_MEMMAP_ID, 2, buf);
if (buf[0] != 'E' || buf[1] != 'C') {
dev_err(dev, "EC ID not detected\n");
return -ENODEV;
}
if (!devm_request_region(dev, EC_HOST_CMD_REGION0,
EC_HOST_CMD_REGION_SIZE, dev_name(dev))) {
dev_err(dev, "couldn't reserve region0\n");
return -EBUSY;
}
if (!devm_request_region(dev, EC_HOST_CMD_REGION1,
EC_HOST_CMD_REGION_SIZE, dev_name(dev))) {
dev_err(dev, "couldn't reserve region1\n");
return -EBUSY;
}
ec_dev = devm_kzalloc(dev, sizeof(*ec_dev), GFP_KERNEL);
if (!ec_dev)
return -ENOMEM;
platform_set_drvdata(pdev, ec_dev);
ec_dev->dev = dev;
ec_dev->phys_name = dev_name(dev);
ec_dev->cmd_xfer = cros_ec_cmd_xfer_lpc;
ec_dev->pkt_xfer = cros_ec_pkt_xfer_lpc;
ec_dev->cmd_readmem = cros_ec_lpc_readmem;
ec_dev->din_size = sizeof(struct ec_host_response) +
sizeof(struct ec_response_get_protocol_info);
ec_dev->dout_size = sizeof(struct ec_host_request);
ret = cros_ec_register(ec_dev);
if (ret) {
dev_err(dev, "couldn't register ec_dev (%d)\n", ret);
return ret;
}
adev = ACPI_COMPANION(dev);
if (adev) {
status = acpi_install_notify_handler(adev->handle,
ACPI_ALL_NOTIFY,
cros_ec_lpc_acpi_notify,
ec_dev);
if (ACPI_FAILURE(status))
dev_warn(dev, "Failed to register notifier %08x\n",
status);
}
return 0;
}
static int cros_ec_lpc_remove(struct platform_device *pdev)
{
struct cros_ec_device *ec_dev;
struct acpi_device *adev;
adev = ACPI_COMPANION(&pdev->dev);
if (adev)
acpi_remove_notify_handler(adev->handle, ACPI_ALL_NOTIFY,
cros_ec_lpc_acpi_notify);
ec_dev = platform_get_drvdata(pdev);
cros_ec_remove(ec_dev);
return 0;
}
static int cros_ec_lpc_suspend(struct device *dev)
{
struct cros_ec_device *ec_dev = dev_get_drvdata(dev);
return cros_ec_suspend(ec_dev);
}
static int cros_ec_lpc_resume(struct device *dev)
{
struct cros_ec_device *ec_dev = dev_get_drvdata(dev);
return cros_ec_resume(ec_dev);
}
static int __init cros_ec_lpc_init(void)
{
int ret;
if (!dmi_check_system(cros_ec_lpc_dmi_table)) {
pr_err(DRV_NAME ": unsupported system.\n");
return -ENODEV;
}
cros_ec_lpc_reg_init();
ret = platform_driver_register(&cros_ec_lpc_driver);
if (ret) {
pr_err(DRV_NAME ": can't register driver: %d\n", ret);
cros_ec_lpc_reg_destroy();
return ret;
}
return 0;
}
static void __exit cros_ec_lpc_exit(void)
{
platform_driver_unregister(&cros_ec_lpc_driver);
cros_ec_lpc_reg_destroy();
}
