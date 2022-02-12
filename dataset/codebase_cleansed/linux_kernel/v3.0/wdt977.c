static int wdt977_start(void)
{
unsigned long flags;
spin_lock_irqsave(&spinlock, flags);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(0xF2, IO_INDEX_PORT);
outb_p(timeoutM, IO_DATA_PORT);
outb_p(0xF3, IO_INDEX_PORT);
outb_p(0x00, IO_DATA_PORT);
outb_p(0xF4, IO_INDEX_PORT);
outb_p(0x00, IO_DATA_PORT);
if (!testmode) {
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x07, IO_DATA_PORT);
outb_p(0xE6, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
}
outb_p(LOCK_DATA, IO_INDEX_PORT);
spin_unlock_irqrestore(&spinlock, flags);
printk(KERN_INFO PFX "activated.\n");
return 0;
}
static int wdt977_stop(void)
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
outb_p(0xE6, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(LOCK_DATA, IO_INDEX_PORT);
spin_unlock_irqrestore(&spinlock, flags);
printk(KERN_INFO PFX "shutdown.\n");
return 0;
}
static int wdt977_keepalive(void)
{
unsigned long flags;
spin_lock_irqsave(&spinlock, flags);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(UNLOCK_DATA, IO_INDEX_PORT);
outb_p(DEVICE_REGISTER, IO_INDEX_PORT);
outb_p(0x08, IO_DATA_PORT);
outb_p(0xF2, IO_INDEX_PORT);
outb_p(timeoutM, IO_DATA_PORT);
outb_p(LOCK_DATA, IO_INDEX_PORT);
spin_unlock_irqrestore(&spinlock, flags);
return 0;
}
static int wdt977_set_timeout(int t)
{
int tmrval;
tmrval = (t + 59) / 60;
if (machine_is_netwinder()) {
tmrval += tmrval;
}
if (tmrval < 1 || tmrval > 255)
return -EINVAL;
timeout = t;
timeoutM = tmrval;
return 0;
}
static int wdt977_get_status(int *status)
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
static int wdt977_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &timer_alive))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
wdt977_start();
return nonseekable_open(inode, file);
}
static int wdt977_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
wdt977_stop();
clear_bit(0, &timer_alive);
} else {
wdt977_keepalive();
printk(KERN_CRIT PFX
"Unexpected close, not stopping watchdog!\n");
}
expect_close = 0;
return 0;
}
static ssize_t wdt977_write(struct file *file, const char __user *buf,
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
wdt977_keepalive();
}
return count;
}
static long wdt977_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
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
wdt977_get_status(&status);
return put_user(status, uarg.i);
case WDIOC_GETBOOTSTATUS:
return put_user(0, uarg.i);
case WDIOC_SETOPTIONS:
if (get_user(new_options, uarg.i))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD) {
wdt977_stop();
retval = 0;
}
if (new_options & WDIOS_ENABLECARD) {
wdt977_start();
retval = 0;
}
return retval;
case WDIOC_KEEPALIVE:
wdt977_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, uarg.i))
return -EFAULT;
if (wdt977_set_timeout(new_timeout))
return -EINVAL;
wdt977_keepalive();
case WDIOC_GETTIMEOUT:
return put_user(timeout, uarg.i);
default:
return -ENOTTY;
}
}
static int wdt977_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt977_stop();
return NOTIFY_DONE;
}
static int __init wd977_init(void)
{
int rc;
printk(KERN_INFO PFX DRIVER_VERSION);
if (wdt977_set_timeout(timeout)) {
wdt977_set_timeout(DEFAULT_TIMEOUT);
printk(KERN_INFO PFX
"timeout value must be 60 < timeout < 15300, using %d\n",
DEFAULT_TIMEOUT);
}
if (!machine_is_netwinder()) {
if (!request_region(IO_INDEX_PORT, 2, WATCHDOG_NAME)) {
printk(KERN_ERR PFX
"I/O address 0x%04x already in use\n",
IO_INDEX_PORT);
rc = -EIO;
goto err_out;
}
}
rc = register_reboot_notifier(&wdt977_notifier);
if (rc) {
printk(KERN_ERR PFX
"cannot register reboot notifier (err=%d)\n", rc);
goto err_out_region;
}
rc = misc_register(&wdt977_miscdev);
if (rc) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
wdt977_miscdev.minor, rc);
goto err_out_reboot;
}
printk(KERN_INFO PFX
"initialized. timeout=%d sec (nowayout=%d, testmode=%i)\n",
timeout, nowayout, testmode);
return 0;
err_out_reboot:
unregister_reboot_notifier(&wdt977_notifier);
err_out_region:
if (!machine_is_netwinder())
release_region(IO_INDEX_PORT, 2);
err_out:
return rc;
}
static void __exit wd977_exit(void)
{
wdt977_stop();
misc_deregister(&wdt977_miscdev);
unregister_reboot_notifier(&wdt977_notifier);
release_region(IO_INDEX_PORT, 2);
}
