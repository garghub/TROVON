static void wafwdt_ping(void)
{
spin_lock(&wafwdt_lock);
inb_p(wdt_stop);
inb_p(wdt_start);
spin_unlock(&wafwdt_lock);
}
static void wafwdt_start(void)
{
outb_p(timeout, wdt_start);
inb_p(wdt_start);
}
static void wafwdt_stop(void)
{
inb_p(wdt_stop);
}
static ssize_t wafwdt_write(struct file *file, const char __user *buf,
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
wafwdt_ping();
}
return count;
}
static long wafwdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int new_timeout;
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT |
WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "Wafer 5823 WDT",
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
wafwdt_start();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
wafwdt_stop();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
wafwdt_ping();
break;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, p))
return -EFAULT;
if ((new_timeout < 1) || (new_timeout > 255))
return -EINVAL;
timeout = new_timeout;
wafwdt_stop();
wafwdt_start();
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
return 0;
}
static int wafwdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wafwdt_is_open))
return -EBUSY;
wafwdt_start();
return nonseekable_open(inode, file);
}
static int wafwdt_close(struct inode *inode, struct file *file)
{
if (expect_close == 42)
wafwdt_stop();
else {
printk(KERN_CRIT PFX
"WDT device closed unexpectedly. WDT will not stop!\n");
wafwdt_ping();
}
clear_bit(0, &wafwdt_is_open);
expect_close = 0;
return 0;
}
static int wafwdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wafwdt_stop();
return NOTIFY_DONE;
}
static int __init wafwdt_init(void)
{
int ret;
printk(KERN_INFO
"WDT driver for Wafer 5823 single board computer initialising.\n");
if (timeout < 1 || timeout > 255) {
timeout = WD_TIMO;
printk(KERN_INFO PFX
"timeout value must be 1 <= x <= 255, using %d\n",
timeout);
}
if (wdt_stop != wdt_start) {
if (!request_region(wdt_stop, 1, "Wafer 5823 WDT")) {
printk(KERN_ERR PFX
"I/O address 0x%04x already in use\n",
wdt_stop);
ret = -EIO;
goto error;
}
}
if (!request_region(wdt_start, 1, "Wafer 5823 WDT")) {
printk(KERN_ERR PFX "I/O address 0x%04x already in use\n",
wdt_start);
ret = -EIO;
goto error2;
}
ret = register_reboot_notifier(&wafwdt_notifier);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register reboot notifier (err=%d)\n", ret);
goto error3;
}
ret = misc_register(&wafwdt_miscdev);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto error4;
}
printk(KERN_INFO PFX "initialized. timeout=%d sec (nowayout=%d)\n",
timeout, nowayout);
return ret;
error4:
unregister_reboot_notifier(&wafwdt_notifier);
error3:
release_region(wdt_start, 1);
error2:
if (wdt_stop != wdt_start)
release_region(wdt_stop, 1);
error:
return ret;
}
static void __exit wafwdt_exit(void)
{
misc_deregister(&wafwdt_miscdev);
unregister_reboot_notifier(&wafwdt_notifier);
if (wdt_stop != wdt_start)
release_region(wdt_stop, 1);
release_region(wdt_start, 1);
}
