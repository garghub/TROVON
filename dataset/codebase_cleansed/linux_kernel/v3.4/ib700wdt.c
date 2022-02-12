static void ibwdt_ping(void)
{
int wd_margin = 15 - ((timeout + 1) / 2);
spin_lock(&ibwdt_lock);
outb_p(wd_margin, WDT_START);
spin_unlock(&ibwdt_lock);
}
static void ibwdt_disable(void)
{
spin_lock(&ibwdt_lock);
outb_p(0, WDT_STOP);
spin_unlock(&ibwdt_lock);
}
static int ibwdt_set_heartbeat(int t)
{
if (t < 0 || t > 30)
return -EINVAL;
timeout = t;
return 0;
}
static ssize_t ibwdt_write(struct file *file, const char __user *buf,
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
ibwdt_ping();
}
return count;
}
static long ibwdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int new_margin;
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT
| WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "IB700 WDT",
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
ibwdt_disable();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
ibwdt_ping();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
ibwdt_ping();
break;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, p))
return -EFAULT;
if (ibwdt_set_heartbeat(new_margin))
return -EINVAL;
ibwdt_ping();
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
return 0;
}
static int ibwdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &ibwdt_is_open))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
ibwdt_ping();
return nonseekable_open(inode, file);
}
static int ibwdt_close(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
ibwdt_disable();
} else {
pr_crit("WDT device closed unexpectedly. WDT will not stop!\n");
ibwdt_ping();
}
clear_bit(0, &ibwdt_is_open);
expect_close = 0;
return 0;
}
static int __devinit ibwdt_probe(struct platform_device *dev)
{
int res;
#if WDT_START != WDT_STOP
if (!request_region(WDT_STOP, 1, "IB700 WDT")) {
pr_err("STOP method I/O %X is not available\n", WDT_STOP);
res = -EIO;
goto out_nostopreg;
}
#endif
if (!request_region(WDT_START, 1, "IB700 WDT")) {
pr_err("START method I/O %X is not available\n", WDT_START);
res = -EIO;
goto out_nostartreg;
}
if (ibwdt_set_heartbeat(timeout)) {
ibwdt_set_heartbeat(WATCHDOG_TIMEOUT);
pr_info("timeout value must be 0<=x<=30, using %d\n", timeout);
}
res = misc_register(&ibwdt_miscdev);
if (res) {
pr_err("failed to register misc device\n");
goto out_nomisc;
}
return 0;
out_nomisc:
release_region(WDT_START, 1);
out_nostartreg:
#if WDT_START != WDT_STOP
release_region(WDT_STOP, 1);
#endif
out_nostopreg:
return res;
}
static int __devexit ibwdt_remove(struct platform_device *dev)
{
misc_deregister(&ibwdt_miscdev);
release_region(WDT_START, 1);
#if WDT_START != WDT_STOP
release_region(WDT_STOP, 1);
#endif
return 0;
}
static void ibwdt_shutdown(struct platform_device *dev)
{
ibwdt_disable();
}
static int __init ibwdt_init(void)
{
int err;
pr_info("WDT driver for IB700 single board computer initialising\n");
err = platform_driver_register(&ibwdt_driver);
if (err)
return err;
ibwdt_platform_device = platform_device_register_simple(DRV_NAME,
-1, NULL, 0);
if (IS_ERR(ibwdt_platform_device)) {
err = PTR_ERR(ibwdt_platform_device);
goto unreg_platform_driver;
}
return 0;
unreg_platform_driver:
platform_driver_unregister(&ibwdt_driver);
return err;
}
static void __exit ibwdt_exit(void)
{
platform_device_unregister(ibwdt_platform_device);
platform_driver_unregister(&ibwdt_driver);
pr_info("Watchdog Module Unloaded\n");
}
