static void geodewdt_ping(void)
{
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_SETUP, 0);
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_COUNTER, 0);
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_SETUP, MFGPT_SETUP_CNTEN);
}
static void geodewdt_disable(void)
{
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_SETUP, 0);
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_COUNTER, 0);
}
static int geodewdt_set_heartbeat(int val)
{
if (val < 1 || val > GEODEWDT_MAX_SECONDS)
return -EINVAL;
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_SETUP, 0);
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_CMP2, val * GEODEWDT_HZ);
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_COUNTER, 0);
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_SETUP, MFGPT_SETUP_CNTEN);
timeout = val;
return 0;
}
static int geodewdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_FLAGS_OPEN, &wdt_flags))
return -EBUSY;
if (!test_and_clear_bit(WDT_FLAGS_ORPHAN, &wdt_flags))
__module_get(THIS_MODULE);
geodewdt_ping();
return nonseekable_open(inode, file);
}
static int geodewdt_release(struct inode *inode, struct file *file)
{
if (safe_close) {
geodewdt_disable();
module_put(THIS_MODULE);
} else {
pr_crit("Unexpected close - watchdog is not stopping\n");
geodewdt_ping();
set_bit(WDT_FLAGS_ORPHAN, &wdt_flags);
}
clear_bit(WDT_FLAGS_OPEN, &wdt_flags);
safe_close = 0;
return 0;
}
static ssize_t geodewdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
safe_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
safe_close = 1;
}
}
geodewdt_ping();
}
return len;
}
static long geodewdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int interval;
static const struct watchdog_info ident = {
.options = WDIOF_SETTIMEOUT | WDIOF_KEEPALIVEPING
| WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = WATCHDOG_NAME,
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
int options, ret = -EINVAL;
if (get_user(options, p))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
geodewdt_disable();
ret = 0;
}
if (options & WDIOS_ENABLECARD) {
geodewdt_ping();
ret = 0;
}
return ret;
}
case WDIOC_KEEPALIVE:
geodewdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(interval, p))
return -EFAULT;
if (geodewdt_set_heartbeat(interval))
return -EINVAL;
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
return 0;
}
static int __init geodewdt_probe(struct platform_device *dev)
{
int ret;
wdt_timer = cs5535_mfgpt_alloc_timer(MFGPT_TIMER_ANY, MFGPT_DOMAIN_WORKING);
if (!wdt_timer) {
pr_err("No timers were available\n");
return -ENODEV;
}
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_SETUP,
GEODEWDT_SCALE | (3 << 8));
cs5535_mfgpt_toggle_event(wdt_timer, MFGPT_CMP2, MFGPT_EVENT_RESET, 1);
cs5535_mfgpt_write(wdt_timer, MFGPT_REG_CMP2,
timeout * GEODEWDT_HZ);
ret = misc_register(&geodewdt_miscdev);
return ret;
}
static int geodewdt_remove(struct platform_device *dev)
{
misc_deregister(&geodewdt_miscdev);
return 0;
}
static void geodewdt_shutdown(struct platform_device *dev)
{
geodewdt_disable();
}
static int __init geodewdt_init(void)
{
int ret;
geodewdt_platform_device = platform_device_register_simple(DRV_NAME,
-1, NULL, 0);
if (IS_ERR(geodewdt_platform_device))
return PTR_ERR(geodewdt_platform_device);
ret = platform_driver_probe(&geodewdt_driver, geodewdt_probe);
if (ret)
goto err;
return 0;
err:
platform_device_unregister(geodewdt_platform_device);
return ret;
}
static void __exit geodewdt_exit(void)
{
platform_device_unregister(geodewdt_platform_device);
platform_driver_unregister(&geodewdt_driver);
}
