static void wdt_enable(void)
{
unsigned int gms0;
gms0 = __raw_readl(MCF_MBAR + MCF_GPT_GMS0);
if (gms0 & MCF_GPT_GMS_TMS_GPIO)
gms0 &= (MCF_GPT_GMS_TMS_GPIO | MCF_GPT_GMS_GPIO_MASK
| MCF_GPT_GMS_OD);
else
gms0 = MCF_GPT_GMS_TMS_GPIO | MCF_GPT_GMS_OD;
__raw_writel(gms0, MCF_MBAR + MCF_GPT_GMS0);
__raw_writel(MCF_GPT_GCIR_PRE(heartbeat*(MCF_BUSCLK/0xffff)) |
MCF_GPT_GCIR_CNT(0xffff), MCF_MBAR + MCF_GPT_GCIR0);
gms0 |= MCF_GPT_GMS_OCPW(0xA5) | MCF_GPT_GMS_WDEN | MCF_GPT_GMS_CE;
__raw_writel(gms0, MCF_MBAR + MCF_GPT_GMS0);
}
static void wdt_disable(void)
{
unsigned int gms0;
gms0 = __raw_readl(MCF_MBAR + MCF_GPT_GMS0);
gms0 &= ~(MCF_GPT_GMS_WDEN | MCF_GPT_GMS_CE);
__raw_writel(gms0, MCF_MBAR + MCF_GPT_GMS0);
}
static void wdt_keepalive(void)
{
unsigned int gms0;
gms0 = __raw_readl(MCF_MBAR + MCF_GPT_GMS0);
gms0 |= MCF_GPT_GMS_OCPW(0xA5);
__raw_writel(gms0, MCF_MBAR + MCF_GPT_GMS0);
}
static int m54xx_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
wdt_enable();
return nonseekable_open(inode, file);
}
static ssize_t m54xx_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
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
wdt_keepalive();
}
return len;
}
static long m54xx_wdt_ioctl(struct file *file, unsigned int cmd,
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
ret = put_user(0, (int *)arg);
break;
case WDIOC_KEEPALIVE:
wdt_keepalive();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, (int *)arg);
if (ret)
break;
if (time <= 0 || time > 30) {
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
static int m54xx_wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDT_OK_TO_CLOSE, &wdt_status))
wdt_disable();
else {
printk(KERN_CRIT "WATCHDOG: Device closed unexpectedly - "
"timer will not stop\n");
wdt_keepalive();
}
clear_bit(WDT_IN_USE, &wdt_status);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return 0;
}
static int __init m54xx_wdt_init(void)
{
if (!request_mem_region(MCF_MBAR + MCF_GPT_GCIR0, 4,
"Coldfire M54xx Watchdog")) {
printk(KERN_WARNING
"Coldfire M54xx Watchdog : I/O region busy\n");
return -EBUSY;
}
printk(KERN_INFO "ColdFire watchdog driver is loaded.\n");
return misc_register(&m54xx_wdt_miscdev);
}
static void __exit m54xx_wdt_exit(void)
{
misc_deregister(&m54xx_wdt_miscdev);
release_mem_region(MCF_MBAR + MCF_GPT_GCIR0, 4);
}
