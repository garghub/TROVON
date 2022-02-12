static int wdt_start(void)
{
unsigned long flags;
spin_lock_irqsave(&spinlock, flags);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(0xF2, IO_INDEX_PORT);
outb_p(timeoutW, IO_DATA_PORT);
outb_p(0xF3, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(0xF4, IO_INDEX_PORT);
outb_p(0x00, IO_DATA_PORT);
outb_p(0x30, IO_INDEX_PORT);
outb_p(0x01, IO_DATA_PORT);
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x07, IO_DATA_PORT);
if (!testmode) {
unsigned pin_map;
outb_p(0xE6, IO_INDEX_PORT);
outb_p(0x0A, IO_DATA_PORT);
outb_p(0x2C, IO_INDEX_PORT);
pin_map = inb_p(IO_DATA_PORT);
pin_map |= 0x10;
pin_map &= ~(0x20);
outb_p(0x2C, IO_INDEX_PORT);
outb_p(pin_map, IO_DATA_PORT);
}
outb_p(0xE3, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(0x30, IO_INDEX_PORT);
outb_p(0x01, IO_DATA_PORT);
outb_p(LOCK_DATA, IO_INDEX_PORT);
spin_unlock_irqrestore(&spinlock, flags);
printk(KERN_INFO PFX "activated.\n");
return 0;
}
static int wdt_stop(void)
{
unsigned long flags;
spin_lock_irqsave(&spinlock, flags);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(0xF2, IO_INDEX_PORT);
outb_p(0xFF, IO_DATA_PORT);
outb_p(0xF3, IO_INDEX_PORT);
outb_p(0x00, IO_DATA_PORT);
outb_p(0xF4, IO_INDEX_PORT);
outb_p(0x00, IO_DATA_PORT);
outb_p(0xF2, IO_INDEX_PORT);
outb_p(0x00, IO_DATA_PORT);
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x07, IO_DATA_PORT);
if (!testmode) {
outb_p(0xE6, IO_INDEX_PORT);
outb_p(0x01, IO_DATA_PORT);
}
outb_p(0xE3, IO_INDEX_PORT);
outb_p(0x01, IO_DATA_PORT);
outb_p(LOCK_DATA, IO_INDEX_PORT);
spin_unlock_irqrestore(&spinlock, flags);
printk(KERN_INFO PFX "shutdown.\n");
return 0;
}
static int wdt_keepalive(void)
{
unsigned long flags;
spin_lock_irqsave(&spinlock, flags);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(0xF2, IO_INDEX_PORT);
outb_p(timeoutW, IO_DATA_PORT);
outb_p(LOCK_DATA, IO_INDEX_PORT);
spin_unlock_irqrestore(&spinlock, flags);
return 0;
}
static int wdt_set_timeout(int t)
{
int tmrval;
if (t < 15)
return -EINVAL;
tmrval = ((t + 15) + 29) / 30;
if (tmrval > 255)
return -EINVAL;
timeoutW = tmrval;
timeout = (timeoutW * 30) - 15;
return 0;
}
static int wdt_get_status(int *status)
{
int new_status;
unsigned long flags;
spin_lock_irqsave(&spinlock, flags);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(0xF4, IO_INDEX_PORT);
new_status = inb_p(IO_DATA_PORT);
outb_p(LOCK_DATA, IO_INDEX_PORT);
spin_unlock_irqrestore(&spinlock, flags);
*status = 0;
if (new_status & 1)
*status |= WDIOF_CARDRESET;
return 0;
}
static int wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &timer_alive))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
wdt_start();
return nonseekable_open(inode, file);
}
static int wdt_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
wdt_stop();
clear_bit(0, &timer_alive);
} else {
wdt_keepalive();
printk(KERN_CRIT PFX
"unexpected close, not stopping watchdog!\n");
}
expect_close = 0;
return 0;
}
static ssize_t wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t ofs;
expect_close = 0;
for (ofs = 0; ofs != count; ofs++) {
char c;
if (get_user(c, buf + ofs))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
wdt_keepalive();
}
return count;
}
static long wdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int status;
int new_options, retval = -EINVAL;
int new_timeout;
union {
struct watchdog_info __user *ident;
int __user *i;
} uarg;
uarg.i = (int __user *)arg;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(uarg.ident, &ident,
sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
wdt_get_status(&status);
return put_user(status, uarg.i);
case WDIOC_GETBOOTSTATUS:
return put_user(0, uarg.i);
case WDIOC_SETOPTIONS:
if (get_user(new_options, uarg.i))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD) {
wdt_stop();
retval = 0;
}
if (new_options & WDIOS_ENABLECARD) {
wdt_start();
retval = 0;
}
return retval;
case WDIOC_KEEPALIVE:
wdt_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, uarg.i))
return -EFAULT;
if (wdt_set_timeout(new_timeout))
return -EINVAL;
wdt_keepalive();
case WDIOC_GETTIMEOUT:
return put_user(timeout, uarg.i);
default:
return -ENOTTY;
}
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_stop();
return NOTIFY_DONE;
}
static int __init w83977f_wdt_init(void)
{
int rc;
printk(KERN_INFO PFX DRIVER_VERSION);
if (wdt_set_timeout(timeout)) {
wdt_set_timeout(DEFAULT_TIMEOUT);
printk(KERN_INFO PFX
"timeout value must be 15 <= timeout <= 7635, using %d\n",
DEFAULT_TIMEOUT);
}
if (!request_region(IO_INDEX_PORT, 2, WATCHDOG_NAME)) {
printk(KERN_ERR PFX "I/O address 0x%04x already in use\n",
IO_INDEX_PORT);
rc = -EIO;
goto err_out;
}
rc = register_reboot_notifier(&wdt_notifier);
if (rc) {
printk(KERN_ERR PFX
"cannot register reboot notifier (err=%d)\n", rc);
goto err_out_region;
}
rc = misc_register(&wdt_miscdev);
if (rc) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
wdt_miscdev.minor, rc);
goto err_out_reboot;
}
printk(KERN_INFO PFX
"initialized. timeout=%d sec (nowayout=%d testmode=%d)\n",
timeout, nowayout, testmode);
return 0;
err_out_reboot:
unregister_reboot_notifier(&wdt_notifier);
err_out_region:
release_region(IO_INDEX_PORT, 2);
err_out:
return rc;
}
static void __exit w83977f_wdt_exit(void)
{
wdt_stop();
misc_deregister(&wdt_miscdev);
unregister_reboot_notifier(&wdt_notifier);
release_region(IO_INDEX_PORT, 2);
}
