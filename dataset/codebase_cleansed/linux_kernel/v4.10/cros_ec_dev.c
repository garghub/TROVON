static int ec_get_version(struct cros_ec_dev *ec, char *str, int maxlen)
{
struct ec_response_get_version *resp;
static const char * const current_image_name[] = {
"unknown", "read-only", "read-write", "invalid",
};
struct cros_ec_command *msg;
int ret;
msg = kmalloc(sizeof(*msg) + sizeof(*resp), GFP_KERNEL);
if (!msg)
return -ENOMEM;
msg->version = 0;
msg->command = EC_CMD_GET_VERSION + ec->cmd_offset;
msg->insize = sizeof(*resp);
msg->outsize = 0;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0)
goto exit;
if (msg->result != EC_RES_SUCCESS) {
snprintf(str, maxlen,
"%s\nUnknown EC version: EC returned %d\n",
CROS_EC_DEV_VERSION, msg->result);
ret = -EINVAL;
goto exit;
}
resp = (struct ec_response_get_version *)msg->data;
if (resp->current_image >= ARRAY_SIZE(current_image_name))
resp->current_image = 3;
snprintf(str, maxlen, "%s\n%s\n%s\n%s\n", CROS_EC_DEV_VERSION,
resp->version_string_ro, resp->version_string_rw,
current_image_name[resp->current_image]);
ret = 0;
exit:
kfree(msg);
return ret;
}
static int cros_ec_check_features(struct cros_ec_dev *ec, int feature)
{
struct cros_ec_command *msg;
int ret;
if (ec->features[0] == -1U && ec->features[1] == -1U) {
msg = kmalloc(sizeof(*msg) + sizeof(ec->features), GFP_KERNEL);
if (!msg)
return -ENOMEM;
msg->version = 0;
msg->command = EC_CMD_GET_FEATURES + ec->cmd_offset;
msg->insize = sizeof(ec->features);
msg->outsize = 0;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0 || msg->result != EC_RES_SUCCESS) {
dev_warn(ec->dev, "cannot get EC features: %d/%d\n",
ret, msg->result);
memset(ec->features, 0, sizeof(ec->features));
}
memcpy(ec->features, msg->data, sizeof(ec->features));
dev_dbg(ec->dev, "EC features %08x %08x\n",
ec->features[0], ec->features[1]);
kfree(msg);
}
return ec->features[feature / 32] & EC_FEATURE_MASK_0(feature);
}
static int ec_device_open(struct inode *inode, struct file *filp)
{
struct cros_ec_dev *ec = container_of(inode->i_cdev,
struct cros_ec_dev, cdev);
filp->private_data = ec;
nonseekable_open(inode, filp);
return 0;
}
static int ec_device_release(struct inode *inode, struct file *filp)
{
return 0;
}
static ssize_t ec_device_read(struct file *filp, char __user *buffer,
size_t length, loff_t *offset)
{
struct cros_ec_dev *ec = filp->private_data;
char msg[sizeof(struct ec_response_get_version) +
sizeof(CROS_EC_DEV_VERSION)];
size_t count;
int ret;
if (*offset != 0)
return 0;
ret = ec_get_version(ec, msg, sizeof(msg));
if (ret)
return ret;
count = min(length, strlen(msg));
if (copy_to_user(buffer, msg, count))
return -EFAULT;
*offset = count;
return count;
}
static long ec_device_ioctl_xcmd(struct cros_ec_dev *ec, void __user *arg)
{
long ret;
struct cros_ec_command u_cmd;
struct cros_ec_command *s_cmd;
if (copy_from_user(&u_cmd, arg, sizeof(u_cmd)))
return -EFAULT;
if ((u_cmd.outsize > EC_MAX_MSG_BYTES) ||
(u_cmd.insize > EC_MAX_MSG_BYTES))
return -EINVAL;
s_cmd = kmalloc(sizeof(*s_cmd) + max(u_cmd.outsize, u_cmd.insize),
GFP_KERNEL);
if (!s_cmd)
return -ENOMEM;
if (copy_from_user(s_cmd, arg, sizeof(*s_cmd) + u_cmd.outsize)) {
ret = -EFAULT;
goto exit;
}
if (u_cmd.outsize != s_cmd->outsize ||
u_cmd.insize != s_cmd->insize) {
ret = -EINVAL;
goto exit;
}
s_cmd->command += ec->cmd_offset;
ret = cros_ec_cmd_xfer(ec->ec_dev, s_cmd);
if (ret < 0)
goto exit;
if (copy_to_user(arg, s_cmd, sizeof(*s_cmd) + s_cmd->insize))
ret = -EFAULT;
exit:
kfree(s_cmd);
return ret;
}
static long ec_device_ioctl_readmem(struct cros_ec_dev *ec, void __user *arg)
{
struct cros_ec_device *ec_dev = ec->ec_dev;
struct cros_ec_readmem s_mem = { };
long num;
if (!ec_dev->cmd_readmem)
return -ENOTTY;
if (copy_from_user(&s_mem, arg, sizeof(s_mem)))
return -EFAULT;
num = ec_dev->cmd_readmem(ec_dev, s_mem.offset, s_mem.bytes,
s_mem.buffer);
if (num <= 0)
return num;
if (copy_to_user((void __user *)arg, &s_mem, sizeof(s_mem)))
return -EFAULT;
return 0;
}
static long ec_device_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct cros_ec_dev *ec = filp->private_data;
if (_IOC_TYPE(cmd) != CROS_EC_DEV_IOC)
return -ENOTTY;
switch (cmd) {
case CROS_EC_DEV_IOCXCMD:
return ec_device_ioctl_xcmd(ec, (void __user *)arg);
case CROS_EC_DEV_IOCRDMEM:
return ec_device_ioctl_readmem(ec, (void __user *)arg);
}
return -ENOTTY;
}
static void __remove(struct device *dev)
{
struct cros_ec_dev *ec = container_of(dev, struct cros_ec_dev,
class_dev);
kfree(ec);
}
static void cros_ec_sensors_register(struct cros_ec_dev *ec)
{
int ret, i, id, sensor_num;
struct mfd_cell *sensor_cells;
struct cros_ec_sensor_platform *sensor_platforms;
int sensor_type[MOTIONSENSE_TYPE_MAX];
struct ec_params_motion_sense *params;
struct ec_response_motion_sense *resp;
struct cros_ec_command *msg;
msg = kzalloc(sizeof(struct cros_ec_command) +
max(sizeof(*params), sizeof(*resp)), GFP_KERNEL);
if (msg == NULL)
return;
msg->version = 2;
msg->command = EC_CMD_MOTION_SENSE_CMD + ec->cmd_offset;
msg->outsize = sizeof(*params);
msg->insize = sizeof(*resp);
params = (struct ec_params_motion_sense *)msg->data;
params->cmd = MOTIONSENSE_CMD_DUMP;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0 || msg->result != EC_RES_SUCCESS) {
dev_warn(ec->dev, "cannot get EC sensor information: %d/%d\n",
ret, msg->result);
goto error;
}
resp = (struct ec_response_motion_sense *)msg->data;
sensor_num = resp->dump.sensor_count;
sensor_cells = kzalloc(sizeof(struct mfd_cell) * (sensor_num + 2),
GFP_KERNEL);
if (sensor_cells == NULL)
goto error;
sensor_platforms = kzalloc(sizeof(struct cros_ec_sensor_platform) *
(sensor_num + 1), GFP_KERNEL);
if (sensor_platforms == NULL)
goto error_platforms;
memset(sensor_type, 0, sizeof(sensor_type));
id = 0;
for (i = 0; i < sensor_num; i++) {
params->cmd = MOTIONSENSE_CMD_INFO;
params->info.sensor_num = i;
ret = cros_ec_cmd_xfer(ec->ec_dev, msg);
if (ret < 0 || msg->result != EC_RES_SUCCESS) {
dev_warn(ec->dev, "no info for EC sensor %d : %d/%d\n",
i, ret, msg->result);
continue;
}
switch (resp->info.type) {
case MOTIONSENSE_TYPE_ACCEL:
sensor_cells[id].name = "cros-ec-accel";
break;
case MOTIONSENSE_TYPE_GYRO:
sensor_cells[id].name = "cros-ec-gyro";
break;
case MOTIONSENSE_TYPE_MAG:
sensor_cells[id].name = "cros-ec-mag";
break;
case MOTIONSENSE_TYPE_PROX:
sensor_cells[id].name = "cros-ec-prox";
break;
case MOTIONSENSE_TYPE_LIGHT:
sensor_cells[id].name = "cros-ec-light";
break;
case MOTIONSENSE_TYPE_ACTIVITY:
sensor_cells[id].name = "cros-ec-activity";
break;
default:
dev_warn(ec->dev, "unknown type %d\n", resp->info.type);
continue;
}
sensor_platforms[id].sensor_num = i;
sensor_cells[id].id = sensor_type[resp->info.type];
sensor_cells[id].platform_data = &sensor_platforms[id];
sensor_cells[id].pdata_size =
sizeof(struct cros_ec_sensor_platform);
sensor_type[resp->info.type]++;
id++;
}
if (sensor_type[MOTIONSENSE_TYPE_ACCEL] >= 2) {
sensor_platforms[id].sensor_num = sensor_num;
sensor_cells[id].name = "cros-ec-angle";
sensor_cells[id].id = 0;
sensor_cells[id].platform_data = &sensor_platforms[id];
sensor_cells[id].pdata_size =
sizeof(struct cros_ec_sensor_platform);
id++;
}
if (cros_ec_check_features(ec, EC_FEATURE_MOTION_SENSE_FIFO)) {
sensor_cells[id].name = "cros-ec-ring";
id++;
}
ret = mfd_add_devices(ec->dev, 0, sensor_cells, id,
NULL, 0, NULL);
if (ret)
dev_err(ec->dev, "failed to add EC sensors\n");
kfree(sensor_platforms);
error_platforms:
kfree(sensor_cells);
error:
kfree(msg);
}
static int ec_device_probe(struct platform_device *pdev)
{
int retval = -ENOMEM;
struct device *dev = &pdev->dev;
struct cros_ec_platform *ec_platform = dev_get_platdata(dev);
dev_t devno = MKDEV(ec_major, pdev->id);
struct cros_ec_dev *ec = kzalloc(sizeof(*ec), GFP_KERNEL);
if (!ec)
return retval;
dev_set_drvdata(dev, ec);
ec->ec_dev = dev_get_drvdata(dev->parent);
ec->dev = dev;
ec->cmd_offset = ec_platform->cmd_offset;
ec->features[0] = -1U;
ec->features[1] = -1U;
device_initialize(&ec->class_dev);
cdev_init(&ec->cdev, &fops);
ec->cdev.kobj.parent = &ec->class_dev.kobj;
retval = cdev_add(&ec->cdev, devno, 1);
if (retval) {
dev_err(dev, ": failed to add character device\n");
goto cdev_add_failed;
}
ec->class_dev.devt = ec->cdev.dev;
ec->class_dev.class = &cros_class;
ec->class_dev.parent = dev;
ec->class_dev.release = __remove;
retval = dev_set_name(&ec->class_dev, "%s", ec_platform->ec_name);
if (retval) {
dev_err(dev, "dev_set_name failed => %d\n", retval);
goto set_named_failed;
}
retval = device_add(&ec->class_dev);
if (retval) {
dev_err(dev, "device_register failed => %d\n", retval);
goto dev_reg_failed;
}
if (cros_ec_check_features(ec, EC_FEATURE_MOTION_SENSE))
cros_ec_sensors_register(ec);
return 0;
dev_reg_failed:
set_named_failed:
dev_set_drvdata(dev, NULL);
cdev_del(&ec->cdev);
cdev_add_failed:
kfree(ec);
return retval;
}
static int ec_device_remove(struct platform_device *pdev)
{
struct cros_ec_dev *ec = dev_get_drvdata(&pdev->dev);
cdev_del(&ec->cdev);
device_unregister(&ec->class_dev);
return 0;
}
static int __init cros_ec_dev_init(void)
{
int ret;
dev_t dev = 0;
ret = class_register(&cros_class);
if (ret) {
pr_err(CROS_EC_DEV_NAME ": failed to register device class\n");
return ret;
}
ret = alloc_chrdev_region(&dev, 0, CROS_MAX_DEV, CROS_EC_DEV_NAME);
if (ret < 0) {
pr_err(CROS_EC_DEV_NAME ": alloc_chrdev_region() failed\n");
goto failed_chrdevreg;
}
ec_major = MAJOR(dev);
ret = platform_driver_register(&cros_ec_dev_driver);
if (ret < 0) {
pr_warn(CROS_EC_DEV_NAME ": can't register driver: %d\n", ret);
goto failed_devreg;
}
return 0;
failed_devreg:
unregister_chrdev_region(MKDEV(ec_major, 0), CROS_MAX_DEV);
failed_chrdevreg:
class_unregister(&cros_class);
return ret;
}
static void __exit cros_ec_dev_exit(void)
{
platform_driver_unregister(&cros_ec_dev_driver);
unregister_chrdev(ec_major, CROS_EC_DEV_NAME);
class_unregister(&cros_class);
}
