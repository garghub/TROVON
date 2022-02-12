static int ec_get_version(struct cros_ec_device *ec, char *str, int maxlen)
{
struct ec_response_get_version *resp;
static const char * const current_image_name[] = {
"unknown", "read-only", "read-write", "invalid",
};
struct cros_ec_command msg = {
.version = 0,
.command = EC_CMD_GET_VERSION,
.outdata = { 0 },
.outsize = 0,
.indata = { 0 },
.insize = sizeof(*resp),
};
int ret;
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return ret;
if (msg.result != EC_RES_SUCCESS) {
snprintf(str, maxlen,
"%s\nUnknown EC version: EC returned %d\n",
CROS_EC_DEV_VERSION, msg.result);
return 0;
}
resp = (struct ec_response_get_version *)msg.indata;
if (resp->current_image >= ARRAY_SIZE(current_image_name))
resp->current_image = 3;
snprintf(str, maxlen, "%s\n%s\n%s\n%s\n", CROS_EC_DEV_VERSION,
resp->version_string_ro, resp->version_string_rw,
current_image_name[resp->current_image]);
return 0;
}
static int ec_device_open(struct inode *inode, struct file *filp)
{
filp->private_data = container_of(inode->i_cdev,
struct cros_ec_device, cdev);
return 0;
}
static int ec_device_release(struct inode *inode, struct file *filp)
{
return 0;
}
static ssize_t ec_device_read(struct file *filp, char __user *buffer,
size_t length, loff_t *offset)
{
struct cros_ec_device *ec = filp->private_data;
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
static long ec_device_ioctl_xcmd(struct cros_ec_device *ec, void __user *arg)
{
long ret;
struct cros_ec_command s_cmd = { };
if (copy_from_user(&s_cmd, arg, sizeof(s_cmd)))
return -EFAULT;
ret = cros_ec_cmd_xfer(ec, &s_cmd);
if (ret < 0)
return ret;
if (copy_to_user(arg, &s_cmd, sizeof(s_cmd)))
return -EFAULT;
return 0;
}
static long ec_device_ioctl_readmem(struct cros_ec_device *ec, void __user *arg)
{
struct cros_ec_readmem s_mem = { };
long num;
if (!ec->cmd_readmem)
return -ENOTTY;
if (copy_from_user(&s_mem, arg, sizeof(s_mem)))
return -EFAULT;
num = ec->cmd_readmem(ec, s_mem.offset, s_mem.bytes, s_mem.buffer);
if (num <= 0)
return num;
if (copy_to_user((void __user *)arg, &s_mem, sizeof(s_mem)))
return -EFAULT;
return 0;
}
static long ec_device_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct cros_ec_device *ec = filp->private_data;
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
static int ec_device_probe(struct platform_device *pdev)
{
struct cros_ec_device *ec = dev_get_drvdata(pdev->dev.parent);
int retval = -ENOTTY;
dev_t devno = MKDEV(ec_major, 0);
cdev_init(&ec->cdev, &fops);
retval = cdev_add(&ec->cdev, devno, 1);
if (retval) {
dev_err(&pdev->dev, ": failed to add character device\n");
return retval;
}
ec->vdev = device_create(cros_class, NULL, devno, ec,
CROS_EC_DEV_NAME);
if (IS_ERR(ec->vdev)) {
retval = PTR_ERR(ec->vdev);
dev_err(&pdev->dev, ": failed to create device\n");
cdev_del(&ec->cdev);
return retval;
}
ec_dev_sysfs_init(ec);
ec_dev_lightbar_init(ec);
return 0;
}
static int ec_device_remove(struct platform_device *pdev)
{
struct cros_ec_device *ec = dev_get_drvdata(pdev->dev.parent);
ec_dev_lightbar_remove(ec);
ec_dev_sysfs_remove(ec);
device_destroy(cros_class, MKDEV(ec_major, 0));
cdev_del(&ec->cdev);
return 0;
}
static int __init cros_ec_dev_init(void)
{
int ret;
dev_t dev = 0;
cros_class = class_create(THIS_MODULE, "chromeos");
if (IS_ERR(cros_class)) {
pr_err(CROS_EC_DEV_NAME ": failed to register device class\n");
return PTR_ERR(cros_class);
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
class_destroy(cros_class);
return ret;
}
static void __exit cros_ec_dev_exit(void)
{
platform_driver_unregister(&cros_ec_dev_driver);
unregister_chrdev(ec_major, CROS_EC_DEV_NAME);
class_destroy(cros_class);
}
