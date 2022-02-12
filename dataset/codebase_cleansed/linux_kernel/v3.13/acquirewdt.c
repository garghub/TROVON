static void acq_keepalive(void)
{
inb_p(wdt_start);
}
static void acq_stop(void)
{
inb_p(wdt_stop);
}
static ssize_t acq_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t i;
expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
acq_keepalive();
}
return count;
}
static long acq_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int options, retval = -EINVAL;
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = WATCHDOG_NAME,
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
if (get_user(options, p))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
acq_stop();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
acq_keepalive();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
acq_keepalive();
return 0;
case WDIOC_GETTIMEOUT:
return put_user(WATCHDOG_HEARTBEAT, p);
default:
return -ENOTTY;
}
}
static int acq_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &acq_is_open))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
acq_keepalive();
return nonseekable_open(inode, file);
}
static int acq_close(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
acq_stop();
} else {
pr_crit("Unexpected close, not stopping watchdog!\n");
acq_keepalive();
}
clear_bit(0, &acq_is_open);
expect_close = 0;
return 0;
}
static int acq_probe(struct platform_device *dev)
{
int ret;
if (wdt_stop != wdt_start) {
if (!request_region(wdt_stop, 1, WATCHDOG_NAME)) {
pr_err("I/O address 0x%04x already in use\n", wdt_stop);
ret = -EIO;
goto out;
}
}
if (!request_region(wdt_start, 1, WATCHDOG_NAME)) {
pr_err("I/O address 0x%04x already in use\n", wdt_start);
ret = -EIO;
goto unreg_stop;
}
ret = misc_register(&acq_miscdev);
if (ret != 0) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto unreg_regions;
}
pr_info("initialized. (nowayout=%d)\n", nowayout);
return 0;
unreg_regions:
release_region(wdt_start, 1);
unreg_stop:
if (wdt_stop != wdt_start)
release_region(wdt_stop, 1);
out:
return ret;
}
static int acq_remove(struct platform_device *dev)
{
misc_deregister(&acq_miscdev);
release_region(wdt_start, 1);
if (wdt_stop != wdt_start)
release_region(wdt_stop, 1);
return 0;
}
static void acq_shutdown(struct platform_device *dev)
{
acq_stop();
}
static int __init acq_init(void)
{
int err;
pr_info("WDT driver for Acquire single board computer initialising\n");
err = platform_driver_register(&acquirewdt_driver);
if (err)
return err;
acq_platform_device = platform_device_register_simple(DRV_NAME,
-1, NULL, 0);
if (IS_ERR(acq_platform_device)) {
err = PTR_ERR(acq_platform_device);
goto unreg_platform_driver;
}
return 0;
unreg_platform_driver:
platform_driver_unregister(&acquirewdt_driver);
return err;
}
static void __exit acq_exit(void)
{
platform_device_unregister(acq_platform_device);
platform_driver_unregister(&acquirewdt_driver);
pr_info("Watchdog Module Unloaded\n");
}
