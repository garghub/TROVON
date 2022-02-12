static inline __kernel_time_t set_timeout(void)
{
wdt.timeout = timeout;
return ktime_to_timespec(ktime_get()).tv_sec + timeout;
}
static int xen_wdt_start(void)
{
__kernel_time_t expires;
int err;
spin_lock(&wdt_lock);
expires = set_timeout();
if (!wdt.id)
err = HYPERVISOR_sched_op(SCHEDOP_watchdog, &wdt);
else
err = -EBUSY;
if (err > 0) {
wdt.id = err;
wdt_expires = expires;
err = 0;
} else
BUG_ON(!err);
spin_unlock(&wdt_lock);
return err;
}
static int xen_wdt_stop(void)
{
int err = 0;
spin_lock(&wdt_lock);
wdt.timeout = 0;
if (wdt.id)
err = HYPERVISOR_sched_op(SCHEDOP_watchdog, &wdt);
if (!err)
wdt.id = 0;
spin_unlock(&wdt_lock);
return err;
}
static int xen_wdt_kick(void)
{
__kernel_time_t expires;
int err;
spin_lock(&wdt_lock);
expires = set_timeout();
if (wdt.id)
err = HYPERVISOR_sched_op(SCHEDOP_watchdog, &wdt);
else
err = -ENXIO;
if (!err)
wdt_expires = expires;
spin_unlock(&wdt_lock);
return err;
}
static int xen_wdt_open(struct inode *inode, struct file *file)
{
int err;
if (xchg(&is_active, true))
return -EBUSY;
err = xen_wdt_start();
if (err == -EBUSY)
err = xen_wdt_kick();
return err ?: nonseekable_open(inode, file);
}
static int xen_wdt_release(struct inode *inode, struct file *file)
{
int err = 0;
if (expect_release)
err = xen_wdt_stop();
else {
pr_crit("unexpected close, not stopping watchdog!\n");
xen_wdt_kick();
}
is_active = err;
expect_release = false;
return err;
}
static ssize_t xen_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
expect_release = false;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_release = true;
}
}
xen_wdt_kick();
}
return len;
}
static long xen_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int new_options, retval = -EINVAL;
int new_timeout;
int __user *argp = (void __user *)arg;
static const struct watchdog_info ident = {
.options = WDIOF_SETTIMEOUT | WDIOF_MAGICCLOSE,
.firmware_version = 0,
.identity = DRV_NAME,
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, argp);
case WDIOC_SETOPTIONS:
if (get_user(new_options, argp))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD)
retval = xen_wdt_stop();
if (new_options & WDIOS_ENABLECARD) {
retval = xen_wdt_start();
if (retval == -EBUSY)
retval = xen_wdt_kick();
}
return retval;
case WDIOC_KEEPALIVE:
xen_wdt_kick();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, argp))
return -EFAULT;
if (!new_timeout)
return -EINVAL;
timeout = new_timeout;
xen_wdt_kick();
case WDIOC_GETTIMEOUT:
return put_user(timeout, argp);
case WDIOC_GETTIMELEFT:
retval = wdt_expires - ktime_to_timespec(ktime_get()).tv_sec;
return put_user(retval, argp);
}
return -ENOTTY;
}
static int __devinit xen_wdt_probe(struct platform_device *dev)
{
struct sched_watchdog wd = { .id = ~0 };
int ret = HYPERVISOR_sched_op(SCHEDOP_watchdog, &wd);
switch (ret) {
case -EINVAL:
if (!timeout) {
timeout = WATCHDOG_TIMEOUT;
pr_info("timeout value invalid, using %d\n", timeout);
}
ret = misc_register(&xen_wdt_miscdev);
if (ret) {
pr_err("cannot register miscdev on minor=%d (%d)\n",
WATCHDOG_MINOR, ret);
break;
}
pr_info("initialized (timeout=%ds, nowayout=%d)\n",
timeout, nowayout);
break;
case -ENOSYS:
pr_info("not supported\n");
ret = -ENODEV;
break;
default:
pr_info("bogus return value %d\n", ret);
break;
}
return ret;
}
static int __devexit xen_wdt_remove(struct platform_device *dev)
{
if (!nowayout)
xen_wdt_stop();
misc_deregister(&xen_wdt_miscdev);
return 0;
}
static void xen_wdt_shutdown(struct platform_device *dev)
{
xen_wdt_stop();
}
static int xen_wdt_suspend(struct platform_device *dev, pm_message_t state)
{
typeof(wdt.id) id = wdt.id;
int rc = xen_wdt_stop();
wdt.id = id;
return rc;
}
static int xen_wdt_resume(struct platform_device *dev)
{
if (!wdt.id)
return 0;
wdt.id = 0;
return xen_wdt_start();
}
static int __init xen_wdt_init_module(void)
{
int err;
if (!xen_domain())
return -ENODEV;
pr_info("Xen WatchDog Timer Driver v%s\n", DRV_VERSION);
err = platform_driver_register(&xen_wdt_driver);
if (err)
return err;
platform_device = platform_device_register_simple(DRV_NAME,
-1, NULL, 0);
if (IS_ERR(platform_device)) {
err = PTR_ERR(platform_device);
platform_driver_unregister(&xen_wdt_driver);
}
return err;
}
static void __exit xen_wdt_cleanup_module(void)
{
platform_device_unregister(platform_device);
platform_driver_unregister(&xen_wdt_driver);
pr_info("module unloaded\n");
}
