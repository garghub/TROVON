static void wdt_enable(void)
{
__raw_writew(0xaaaa, EP93XX_WDT_WATCHDOG);
}
static void wdt_disable(void)
{
__raw_writew(0xaa55, EP93XX_WDT_WATCHDOG);
}
static inline void wdt_ping(void)
{
__raw_writew(0x5555, EP93XX_WDT_WATCHDOG);
}
static void wdt_startup(void)
{
next_heartbeat = jiffies + (timeout * HZ);
wdt_enable();
mod_timer(&timer, jiffies + WDT_INTERVAL);
}
static void wdt_shutdown(void)
{
del_timer_sync(&timer);
wdt_disable();
}
static void wdt_keepalive(void)
{
next_heartbeat = jiffies + (timeout * HZ);
}
static int ep93xx_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
wdt_startup();
return nonseekable_open(inode, file);
}
static ssize_t
ep93xx_wdt_write(struct file *file, const char __user *data, size_t len,
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
else
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
}
}
wdt_keepalive();
}
return len;
}
static long ep93xx_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int ret = -ENOTTY;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user((struct watchdog_info __user *)arg, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, (int __user *)arg);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(boot_status, (int __user *)arg);
break;
case WDIOC_KEEPALIVE:
wdt_keepalive();
ret = 0;
break;
case WDIOC_GETTIMEOUT:
ret = put_user(1, (int __user *)arg);
break;
}
return ret;
}
static int ep93xx_wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDT_OK_TO_CLOSE, &wdt_status))
wdt_shutdown();
else
printk(KERN_CRIT PFX
"Device closed unexpectedly - timer will not stop\n");
clear_bit(WDT_IN_USE, &wdt_status);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return 0;
}
static void ep93xx_timer_ping(unsigned long data)
{
if (time_before(jiffies, next_heartbeat))
wdt_ping();
mod_timer(&timer, jiffies + WDT_INTERVAL);
}
static int __init ep93xx_wdt_init(void)
{
int err;
err = misc_register(&ep93xx_wdt_miscdev);
boot_status = __raw_readl(EP93XX_WDT_WATCHDOG) & 0x01 ? 1 : 0;
printk(KERN_INFO PFX "EP93XX watchdog, driver version "
WDT_VERSION "%s\n",
(__raw_readl(EP93XX_WDT_WATCHDOG) & 0x08)
? " (nCS1 disable detected)" : "");
if (timeout < 1 || timeout > 3600) {
timeout = WDT_TIMEOUT;
printk(KERN_INFO PFX
"timeout value must be 1<=x<=3600, using %d\n",
timeout);
}
setup_timer(&timer, ep93xx_timer_ping, 1);
return err;
}
static void __exit ep93xx_wdt_exit(void)
{
wdt_shutdown();
misc_deregister(&ep93xx_wdt_miscdev);
}
