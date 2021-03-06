static void advwdt_ping(void)
{
outb_p(timeout, wdt_start);
}
static void advwdt_disable(void)
{
inb_p(wdt_stop);
}
static int advwdt_set_heartbeat(int t)
{
if (t < 1 || t > 63)
return -EINVAL;
timeout = t;
return 0;
}
static ssize_t advwdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t i;
adv_expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
adv_expect_close = 42;
}
}
advwdt_ping();
}
return count;
}
static long advwdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int new_timeout;
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING |
WDIOF_SETTIMEOUT |
WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = WATCHDOG_NAME,
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
int options, retval = -EINVAL;
if (get_user(options, p))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
advwdt_disable();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
advwdt_ping();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
advwdt_ping();
break;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, p))
return -EFAULT;
if (advwdt_set_heartbeat(new_timeout))
return -EINVAL;
advwdt_ping();
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
return 0;
}
static int advwdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &advwdt_is_open))
return -EBUSY;
advwdt_ping();
return nonseekable_open(inode, file);
}
static int advwdt_close(struct inode *inode, struct file *file)
{
if (adv_expect_close == 42) {
advwdt_disable();
} else {
pr_crit("Unexpected close, not stopping watchdog!\n");
advwdt_ping();
}
clear_bit(0, &advwdt_is_open);
adv_expect_close = 0;
return 0;
}
static int __devinit advwdt_probe(struct platform_device *dev)
{
int ret;
if (wdt_stop != wdt_start) {
if (!request_region(wdt_stop, 1, WATCHDOG_NAME)) {
pr_err("I/O address 0x%04x already in use\n",
wdt_stop);
ret = -EIO;
goto out;
}
}
if (!request_region(wdt_start, 1, WATCHDOG_NAME)) {
pr_err("I/O address 0x%04x already in use\n", wdt_start);
ret = -EIO;
goto unreg_stop;
}
if (advwdt_set_heartbeat(timeout)) {
advwdt_set_heartbeat(WATCHDOG_TIMEOUT);
pr_info("timeout value must be 1<=x<=63, using %d\n", timeout);
}
ret = misc_register(&advwdt_miscdev);
if (ret != 0) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto unreg_regions;
}
pr_info("initialized. timeout=%d sec (nowayout=%d)\n",
timeout, nowayout);
out:
return ret;
unreg_regions:
release_region(wdt_start, 1);
unreg_stop:
if (wdt_stop != wdt_start)
release_region(wdt_stop, 1);
goto out;
}
static int __devexit advwdt_remove(struct platform_device *dev)
{
misc_deregister(&advwdt_miscdev);
release_region(wdt_start, 1);
if (wdt_stop != wdt_start)
release_region(wdt_stop, 1);
return 0;
}
static void advwdt_shutdown(struct platform_device *dev)
{
advwdt_disable();
}
static int __init advwdt_init(void)
{
int err;
pr_info("WDT driver for Advantech single board computer initialising\n");
err = platform_driver_register(&advwdt_driver);
if (err)
return err;
advwdt_platform_device = platform_device_register_simple(DRV_NAME,
-1, NULL, 0);
if (IS_ERR(advwdt_platform_device)) {
err = PTR_ERR(advwdt_platform_device);
goto unreg_platform_driver;
}
return 0;
unreg_platform_driver:
platform_driver_unregister(&advwdt_driver);
return err;
}
static void __exit advwdt_exit(void)
{
platform_device_unregister(advwdt_platform_device);
platform_driver_unregister(&advwdt_driver);
pr_info("Watchdog Module Unloaded\n");
}
