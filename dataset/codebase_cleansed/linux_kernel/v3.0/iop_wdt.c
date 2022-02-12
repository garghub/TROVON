static unsigned long iop_watchdog_timeout(void)
{
return (0xffffffffUL / get_iop_tick_rate());
}
static int wdt_supports_disable(void)
{
int can_disable;
if (IOP_WDTCR_EN_ARM != IOP_WDTCR_DIS_ARM)
can_disable = 1;
else
can_disable = 0;
return can_disable;
}
static void wdt_enable(void)
{
spin_lock(&wdt_lock);
write_wdtcr(IOP_WDTCR_EN_ARM);
write_wdtcr(IOP_WDTCR_EN);
spin_unlock(&wdt_lock);
}
static int wdt_disable(void)
{
if (wdt_supports_disable()) {
spin_lock(&wdt_lock);
write_wdtcr(IOP_WDTCR_DIS_ARM);
write_wdtcr(IOP_WDTCR_DIS);
clear_bit(WDT_ENABLED, &wdt_status);
spin_unlock(&wdt_lock);
printk(KERN_INFO "WATCHDOG: Disabled\n");
return 0;
} else
return 1;
}
static int iop_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
wdt_enable();
set_bit(WDT_ENABLED, &wdt_status);
return nonseekable_open(inode, file);
}
static ssize_t iop_wdt_write(struct file *file, const char *data, size_t len,
loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(WDT_OK_TO_CLOSE, &wdt_status);
}
}
wdt_enable();
}
return len;
}
static long iop_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int options;
int ret = -ENOTTY;
int __user *argp = (int __user *)arg;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
ret = -EFAULT;
else
ret = 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, argp);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(boot_status, argp);
break;
case WDIOC_SETOPTIONS:
if (get_user(options, (int *)arg))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
if (!nowayout) {
if (wdt_disable() == 0) {
set_bit(WDT_OK_TO_CLOSE, &wdt_status);
ret = 0;
} else
ret = -ENXIO;
} else
ret = 0;
}
if (options & WDIOS_ENABLECARD) {
wdt_enable();
ret = 0;
}
break;
case WDIOC_KEEPALIVE:
wdt_enable();
ret = 0;
break;
case WDIOC_GETTIMEOUT:
ret = put_user(iop_watchdog_timeout(), argp);
break;
}
return ret;
}
static int iop_wdt_release(struct inode *inode, struct file *file)
{
int state = 1;
if (test_bit(WDT_OK_TO_CLOSE, &wdt_status))
if (test_bit(WDT_ENABLED, &wdt_status))
state = wdt_disable();
if (state != 0) {
wdt_enable();
printk(KERN_CRIT "WATCHDOG: Device closed unexpectedly - "
"reset in %lu seconds\n", iop_watchdog_timeout());
}
clear_bit(WDT_IN_USE, &wdt_status);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return 0;
}
static int __init iop_wdt_init(void)
{
int ret;
spin_lock_init(&wdt_lock);
boot_status = (read_rcsr() & IOP_RCSR_WDT) ? WDIOF_CARDRESET : 0;
write_wdtsr(IOP13XX_WDTCR_IB_RESET);
ret = misc_register(&iop_wdt_miscdev);
if (ret == 0)
printk(KERN_INFO "iop watchdog timer: timeout %lu sec\n",
iop_watchdog_timeout());
return ret;
}
static void __exit iop_wdt_exit(void)
{
misc_deregister(&iop_wdt_miscdev);
}
