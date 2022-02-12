static void w83627hf_select_wd_register(void)
{
unsigned char c;
outb_p(0x87, WDT_EFER);
outb_p(0x87, WDT_EFER);
outb(0x20, WDT_EFER);
c = inb(WDT_EFDR);
if (c == 0x82) {
outb_p(0x2b, WDT_EFER);
c = ((inb_p(WDT_EFDR) & 0xf7) | 0x04);
outb_p(0x2b, WDT_EFER);
outb_p(c, WDT_EFDR);
} else if (c == 0x88 || c == 0xa0) {
outb_p(0x2d, WDT_EFER);
c = inb_p(WDT_EFDR) & ~0x01;
outb_p(0x2d, WDT_EFER);
outb_p(c, WDT_EFDR);
}
outb_p(0x07, WDT_EFER);
outb_p(0x08, WDT_EFDR);
outb_p(0x30, WDT_EFER);
outb_p(0x01, WDT_EFDR);
}
static void w83627hf_unselect_wd_register(void)
{
outb_p(0xAA, WDT_EFER);
}
static void w83627hf_init(void)
{
unsigned char t;
w83627hf_select_wd_register();
outb_p(0xF6, WDT_EFER);
t = inb_p(WDT_EFDR);
if (t != 0) {
printk(KERN_INFO PFX
"Watchdog already running. Resetting timeout to %d sec\n",
timeout);
outb_p(timeout, WDT_EFDR);
}
outb_p(0xF5, WDT_EFER);
t = inb_p(WDT_EFDR);
t &= ~0x0C;
t |= 0x02;
outb_p(t, WDT_EFDR);
outb_p(0xF7, WDT_EFER);
t = inb_p(WDT_EFDR);
t &= ~0xC0;
outb_p(t, WDT_EFDR);
w83627hf_unselect_wd_register();
}
static void wdt_set_time(int timeout)
{
spin_lock(&io_lock);
w83627hf_select_wd_register();
outb_p(0xF6, WDT_EFER);
outb_p(timeout, WDT_EFDR);
w83627hf_unselect_wd_register();
spin_unlock(&io_lock);
}
static int wdt_ping(void)
{
wdt_set_time(timeout);
return 0;
}
static int wdt_disable(void)
{
wdt_set_time(0);
return 0;
}
static int wdt_set_heartbeat(int t)
{
if (t < 1 || t > 255)
return -EINVAL;
timeout = t;
return 0;
}
static int wdt_get_time(void)
{
int timeleft;
spin_lock(&io_lock);
w83627hf_select_wd_register();
outb_p(0xF6, WDT_EFER);
timeleft = inb_p(WDT_EFDR);
w83627hf_unselect_wd_register();
spin_unlock(&io_lock);
return timeleft;
}
static ssize_t wdt_write(struct file *file, const char __user *buf,
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
wdt_ping();
}
return count;
}
static long wdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int timeval;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT |
WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "W83627HF WDT",
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
wdt_disable();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
wdt_ping();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
wdt_ping();
break;
case WDIOC_SETTIMEOUT:
if (get_user(timeval, p))
return -EFAULT;
if (wdt_set_heartbeat(timeval))
return -EINVAL;
wdt_ping();
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
case WDIOC_GETTIMELEFT:
timeval = wdt_get_time();
return put_user(timeval, p);
default:
return -ENOTTY;
}
return 0;
}
static int wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wdt_is_open))
return -EBUSY;
wdt_ping();
return nonseekable_open(inode, file);
}
static int wdt_close(struct inode *inode, struct file *file)
{
if (expect_close == 42)
wdt_disable();
else {
printk(KERN_CRIT PFX
"Unexpected close, not stopping watchdog!\n");
wdt_ping();
}
expect_close = 0;
clear_bit(0, &wdt_is_open);
return 0;
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_disable();
return NOTIFY_DONE;
}
static int __init wdt_init(void)
{
int ret;
printk(KERN_INFO "WDT driver for the Winbond(TM) W83627HF/THF/HG/DHG Super I/O chip initialising.\n");
if (wdt_set_heartbeat(timeout)) {
wdt_set_heartbeat(WATCHDOG_TIMEOUT);
printk(KERN_INFO PFX
"timeout value must be 1 <= timeout <= 255, using %d\n",
WATCHDOG_TIMEOUT);
}
if (!request_region(wdt_io, 1, WATCHDOG_NAME)) {
printk(KERN_ERR PFX "I/O address 0x%04x already in use\n",
wdt_io);
ret = -EIO;
goto out;
}
w83627hf_init();
ret = register_reboot_notifier(&wdt_notifier);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register reboot notifier (err=%d)\n", ret);
goto unreg_regions;
}
ret = misc_register(&wdt_miscdev);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto unreg_reboot;
}
printk(KERN_INFO PFX
"initialized. timeout=%d sec (nowayout=%d)\n",
timeout, nowayout);
out:
return ret;
unreg_reboot:
unregister_reboot_notifier(&wdt_notifier);
unreg_regions:
release_region(wdt_io, 1);
goto out;
}
static void __exit wdt_exit(void)
{
misc_deregister(&wdt_miscdev);
unregister_reboot_notifier(&wdt_notifier);
release_region(wdt_io, 1);
}
