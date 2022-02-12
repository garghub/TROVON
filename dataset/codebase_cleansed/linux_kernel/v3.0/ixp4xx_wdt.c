static void wdt_enable(void)
{
spin_lock(&wdt_lock);
*IXP4XX_OSWK = IXP4XX_WDT_KEY;
*IXP4XX_OSWE = 0;
*IXP4XX_OSWT = WDT_TICK_RATE * heartbeat;
*IXP4XX_OSWE = IXP4XX_WDT_COUNT_ENABLE | IXP4XX_WDT_RESET_ENABLE;
*IXP4XX_OSWK = 0;
spin_unlock(&wdt_lock);
}
static void wdt_disable(void)
{
spin_lock(&wdt_lock);
*IXP4XX_OSWK = IXP4XX_WDT_KEY;
*IXP4XX_OSWE = 0;
*IXP4XX_OSWK = 0;
spin_unlock(&wdt_lock);
}
static int ixp4xx_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
wdt_enable();
return nonseekable_open(inode, file);
}
static ssize_t
ixp4xx_wdt_write(struct file *file, const char *data, size_t len, loff_t *ppos)
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
static long ixp4xx_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
int time;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user((struct watchdog_info *)arg, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, (int *)arg);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(boot_status, (int *)arg);
break;
case WDIOC_KEEPALIVE:
wdt_enable();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, (int *)arg);
if (ret)
break;
if (time <= 0 || time > 60) {
ret = -EINVAL;
break;
}
heartbeat = time;
wdt_enable();
case WDIOC_GETTIMEOUT:
ret = put_user(heartbeat, (int *)arg);
break;
}
return ret;
}
static int ixp4xx_wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDT_OK_TO_CLOSE, &wdt_status))
wdt_disable();
else
printk(KERN_CRIT "WATCHDOG: Device closed unexpectedly - "
"timer will not stop\n");
clear_bit(WDT_IN_USE, &wdt_status);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return 0;
}
static int __init ixp4xx_wdt_init(void)
{
int ret;
if (!(read_cpuid_id() & 0xf) && !cpu_is_ixp46x()) {
printk(KERN_ERR "IXP4XXX Watchdog: Rev. A0 IXP42x CPU detected"
" - watchdog disabled\n");
return -ENODEV;
}
spin_lock_init(&wdt_lock);
boot_status = (*IXP4XX_OSST & IXP4XX_OSST_TIMER_WARM_RESET) ?
WDIOF_CARDRESET : 0;
ret = misc_register(&ixp4xx_wdt_miscdev);
if (ret == 0)
printk(KERN_INFO "IXP4xx Watchdog Timer: heartbeat %d sec\n",
heartbeat);
return ret;
}
static void __exit ixp4xx_wdt_exit(void)
{
misc_deregister(&ixp4xx_wdt_miscdev);
}
