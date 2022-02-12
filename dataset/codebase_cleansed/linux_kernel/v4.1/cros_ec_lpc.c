static int ec_response_timed_out(void)
{
unsigned long one_second = jiffies + HZ;
usleep_range(200, 300);
do {
if (!(inb(EC_LPC_ADDR_HOST_CMD) & EC_LPC_STATUS_BUSY_MASK))
return 0;
usleep_range(100, 200);
} while (time_before(jiffies, one_second));
return 1;
}
static int cros_ec_cmd_xfer_lpc(struct cros_ec_device *ec,
struct cros_ec_command *msg)
{
struct ec_lpc_host_args args;
int csum;
int i;
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
csum = msg->command + args.flags +
args.command_version + args.data_size;
for (i = 0; i < msg->outsize; i++) {
outb(msg->outdata[i], EC_LPC_ADDR_HOST_PARAM + i);
csum += msg->outdata[i];
}
args.checksum = csum & 0xFF;
outb(args.flags, EC_LPC_ADDR_HOST_ARGS);
outb(args.command_version, EC_LPC_ADDR_HOST_ARGS + 1);
outb(args.data_size, EC_LPC_ADDR_HOST_ARGS + 2);
outb(args.checksum, EC_LPC_ADDR_HOST_ARGS + 3);
outb(msg->command, EC_LPC_ADDR_HOST_CMD);
if (ec_response_timed_out()) {
dev_warn(ec->dev, "EC responsed timed out\n");
ret = -EIO;
goto done;
}
msg->result = inb(EC_LPC_ADDR_HOST_DATA);
switch (msg->result) {
case EC_RES_SUCCESS:
break;
case EC_RES_IN_PROGRESS:
ret = -EAGAIN;
dev_dbg(ec->dev, "command 0x%02x in progress\n",
msg->command);
goto done;
default:
dev_dbg(ec->dev, "command 0x%02x returned %d\n",
msg->command, msg->result);
}
args.flags = inb(EC_LPC_ADDR_HOST_ARGS);
args.command_version = inb(EC_LPC_ADDR_HOST_ARGS + 1);
args.data_size = inb(EC_LPC_ADDR_HOST_ARGS + 2);
args.checksum = inb(EC_LPC_ADDR_HOST_ARGS + 3);
if (args.data_size > msg->insize) {
dev_err(ec->dev,
"packet too long (%d bytes, expected %d)",
args.data_size, msg->insize);
ret = -ENOSPC;
goto done;
}
csum = msg->command + args.flags +
args.command_version + args.data_size;
for (i = 0; i < args.data_size; i++) {
msg->indata[i] = inb(EC_LPC_ADDR_HOST_PARAM + i);
csum += msg->indata[i];
}
if (args.checksum != (csum & 0xFF)) {
dev_err(ec->dev,
"bad packet checksum, expected %02x, got %02x\n",
args.checksum, csum & 0xFF);
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
for (; cnt < bytes; i++, s++, cnt++)
*s = inb(EC_LPC_ADDR_MEMMAP + i);
return cnt;
}
for (; i < EC_MEMMAP_SIZE; i++, s++) {
*s = inb(EC_LPC_ADDR_MEMMAP + i);
cnt++;
if (!*s)
break;
}
return cnt;
}
static int cros_ec_lpc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct cros_ec_device *ec_dev;
int ret;
if (!devm_request_region(dev, EC_LPC_ADDR_MEMMAP, EC_MEMMAP_SIZE,
dev_name(dev))) {
dev_err(dev, "couldn't reserve memmap region\n");
return -EBUSY;
}
if ((inb(EC_LPC_ADDR_MEMMAP + EC_MEMMAP_ID) != 'E') ||
(inb(EC_LPC_ADDR_MEMMAP + EC_MEMMAP_ID + 1) != 'C')) {
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
ec_dev->ec_name = pdev->name;
ec_dev->phys_name = dev_name(dev);
ec_dev->parent = dev;
ec_dev->cmd_xfer = cros_ec_cmd_xfer_lpc;
ec_dev->cmd_readmem = cros_ec_lpc_readmem;
ret = cros_ec_register(ec_dev);
if (ret) {
dev_err(dev, "couldn't register ec_dev (%d)\n", ret);
return ret;
}
return 0;
}
static int cros_ec_lpc_remove(struct platform_device *pdev)
{
struct cros_ec_device *ec_dev;
ec_dev = platform_get_drvdata(pdev);
cros_ec_remove(ec_dev);
return 0;
}
static int __init cros_ec_lpc_init(void)
{
int ret;
if (!dmi_check_system(cros_ec_lpc_dmi_table)) {
pr_err(DRV_NAME ": unsupported system.\n");
return -ENODEV;
}
ret = platform_driver_register(&cros_ec_lpc_driver);
if (ret) {
pr_err(DRV_NAME ": can't register driver: %d\n", ret);
return ret;
}
ret = platform_device_register(&cros_ec_lpc_device);
if (ret) {
pr_err(DRV_NAME ": can't register device: %d\n", ret);
platform_driver_unregister(&cros_ec_lpc_driver);
return ret;
}
return 0;
}
static void __exit cros_ec_lpc_exit(void)
{
platform_device_unregister(&cros_ec_lpc_device);
platform_driver_unregister(&cros_ec_lpc_driver);
}
