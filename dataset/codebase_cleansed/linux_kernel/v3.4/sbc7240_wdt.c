static void wdt_disable(void)
{
if (test_and_clear_bit(SBC7240_ENABLED_STATUS_BIT, &wdt_status)) {
inb_p(SBC7240_DISABLE_PORT);
pr_info("Watchdog timer is now disabled\n");
}
}
static void wdt_enable(void)
{
if (!test_and_set_bit(SBC7240_ENABLED_STATUS_BIT, &wdt_status)) {
inb_p(SBC7240_ENABLE_PORT);
pr_info("Watchdog timer is now enabled\n");
}
}
static int wdt_set_timeout(int t)
{
if (t < 1 || t > SBC7240_MAX_TIMEOUT) {
pr_err("timeout value must be 1<=x<=%d\n", SBC7240_MAX_TIMEOUT);
return -1;
}
outb_p((unsigned)t, SBC7240_SET_TIMEOUT_PORT);
timeout = t;
pr_info("timeout set to %d seconds\n", t);
return 0;
}
static inline void wdt_keepalive(void)
{
if (test_bit(SBC7240_ENABLED_STATUS_BIT, &wdt_status))
inb_p(SBC7240_ENABLE_PORT);
}
static ssize_t fop_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
size_t i;
char c;
if (count) {
if (!nowayout) {
clear_bit(SBC7240_EXPECT_CLOSE_STATUS_BIT,
&wdt_status);
for (i = 0; i != count; i++) {
if (get_user(c, buf + i))
return -EFAULT;
if (c == SBC7240_MAGIC_CHAR) {
set_bit(SBC7240_EXPECT_CLOSE_STATUS_BIT,
&wdt_status);
break;
}
}
}
wdt_keepalive();
}
return count;
}
static int fop_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(SBC7240_OPEN_STATUS_BIT, &wdt_status))
return -EBUSY;
wdt_enable();
return nonseekable_open(inode, file);
}
static int fop_close(struct inode *inode, struct file *file)
{
if (test_and_clear_bit(SBC7240_EXPECT_CLOSE_STATUS_BIT, &wdt_status)
|| !nowayout) {
wdt_disable();
} else {
pr_crit("Unexpected close, not stopping watchdog!\n");
wdt_keepalive();
}
clear_bit(SBC7240_OPEN_STATUS_BIT, &wdt_status);
return 0;
}
static long fop_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user((void __user *)arg, &ident, sizeof(ident))
? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, (int __user *)arg);
case WDIOC_SETOPTIONS:
{
int options;
int retval = -EINVAL;
if (get_user(options, (int __user *)arg))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
wdt_disable();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
wdt_enable();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
wdt_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
{
int new_timeout;
if (get_user(new_timeout, (int __user *)arg))
return -EFAULT;
if (wdt_set_timeout(new_timeout))
return -EINVAL;
}
case WDIOC_GETTIMEOUT:
return put_user(timeout, (int __user *)arg);
default:
return -ENOTTY;
}
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_disable();
return NOTIFY_DONE;
}
static void __exit sbc7240_wdt_unload(void)
{
pr_info("Removing watchdog\n");
misc_deregister(&wdt_miscdev);
unregister_reboot_notifier(&wdt_notifier);
release_region(SBC7240_ENABLE_PORT, 1);
}
static int __init sbc7240_wdt_init(void)
{
int rc = -EBUSY;
if (!request_region(SBC7240_ENABLE_PORT, 1, "SBC7240 WDT")) {
pr_err("I/O address 0x%04x already in use\n",
SBC7240_ENABLE_PORT);
rc = -EIO;
goto err_out;
}
if (timeout < 1 || timeout > SBC7240_MAX_TIMEOUT) {
timeout = SBC7240_TIMEOUT;
pr_info("timeout value must be 1<=x<=%d, using %d\n",
SBC7240_MAX_TIMEOUT, timeout);
}
wdt_set_timeout(timeout);
wdt_disable();
rc = register_reboot_notifier(&wdt_notifier);
if (rc) {
pr_err("cannot register reboot notifier (err=%d)\n", rc);
goto err_out_region;
}
rc = misc_register(&wdt_miscdev);
if (rc) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
wdt_miscdev.minor, rc);
goto err_out_reboot_notifier;
}
pr_info("Watchdog driver for SBC7240 initialised (nowayout=%d)\n",
nowayout);
return 0;
err_out_reboot_notifier:
unregister_reboot_notifier(&wdt_notifier);
err_out_region:
release_region(SBC7240_ENABLE_PORT, 1);
err_out:
return rc;
}
