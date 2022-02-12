static void wdt_timer_ping(unsigned long data)
{
if (time_before(jiffies, next_heartbeat)) {
inb_p(wdt_start);
mod_timer(&timer, jiffies + WDT_INTERVAL);
} else
printk(KERN_WARNING PFX
"Heartbeat lost! Will not ping the watchdog\n");
}
static void wdt_startup(void)
{
next_heartbeat = jiffies + (timeout * HZ);
mod_timer(&timer, jiffies + WDT_INTERVAL);
printk(KERN_INFO PFX "Watchdog timer is now enabled.\n");
}
static void wdt_turnoff(void)
{
del_timer(&timer);
inb_p(wdt_stop);
printk(KERN_INFO PFX "Watchdog timer is now disabled...\n");
}
static void wdt_keepalive(void)
{
next_heartbeat = jiffies + (timeout * HZ);
}
static ssize_t fop_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t ofs;
wdt_expect_close = 0;
for (ofs = 0; ofs != count; ofs++) {
char c;
if (get_user(c, buf + ofs))
return -EFAULT;
if (c == 'V')
wdt_expect_close = 42;
}
}
wdt_keepalive();
}
return count;
}
static int fop_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wdt_is_open))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
wdt_startup();
return nonseekable_open(inode, file);
}
static int fop_close(struct inode *inode, struct file *file)
{
if (wdt_expect_close == 42)
wdt_turnoff();
else {
del_timer(&timer);
printk(KERN_CRIT PFX
"device file closed unexpectedly. Will not stop the WDT!\n");
}
clear_bit(0, &wdt_is_open);
wdt_expect_close = 0;
return 0;
}
static long fop_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT |
WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "SBC60xx",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
int new_options, retval = -EINVAL;
if (get_user(new_options, p))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD) {
wdt_turnoff();
retval = 0;
}
if (new_options & WDIOS_ENABLECARD) {
wdt_startup();
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
if (get_user(new_timeout, p))
return -EFAULT;
if (new_timeout < 1 || new_timeout > 3600)
return -EINVAL;
timeout = new_timeout;
wdt_keepalive();
}
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_turnoff();
return NOTIFY_DONE;
}
static void __exit sbc60xxwdt_unload(void)
{
wdt_turnoff();
misc_deregister(&wdt_miscdev);
unregister_reboot_notifier(&wdt_notifier);
if ((wdt_stop != 0x45) && (wdt_stop != wdt_start))
release_region(wdt_stop, 1);
release_region(wdt_start, 1);
}
static int __init sbc60xxwdt_init(void)
{
int rc = -EBUSY;
if (timeout < 1 || timeout > 3600) {
timeout = WATCHDOG_TIMEOUT;
printk(KERN_INFO PFX
"timeout value must be 1 <= x <= 3600, using %d\n",
timeout);
}
if (!request_region(wdt_start, 1, "SBC 60XX WDT")) {
printk(KERN_ERR PFX "I/O address 0x%04x already in use\n",
wdt_start);
rc = -EIO;
goto err_out;
}
if (wdt_stop != 0x45 && wdt_stop != wdt_start) {
if (!request_region(wdt_stop, 1, "SBC 60XX WDT")) {
printk(KERN_ERR PFX
"I/O address 0x%04x already in use\n",
wdt_stop);
rc = -EIO;
goto err_out_region1;
}
}
rc = register_reboot_notifier(&wdt_notifier);
if (rc) {
printk(KERN_ERR PFX
"cannot register reboot notifier (err=%d)\n", rc);
goto err_out_region2;
}
rc = misc_register(&wdt_miscdev);
if (rc) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
wdt_miscdev.minor, rc);
goto err_out_reboot;
}
printk(KERN_INFO PFX
"WDT driver for 60XX single board computer initialised. "
"timeout=%d sec (nowayout=%d)\n", timeout, nowayout);
return 0;
err_out_reboot:
unregister_reboot_notifier(&wdt_notifier);
err_out_region2:
if (wdt_stop != 0x45 && wdt_stop != wdt_start)
release_region(wdt_stop, 1);
err_out_region1:
release_region(wdt_start, 1);
err_out:
return rc;
}
