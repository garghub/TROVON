static void wdt_enable(void)
{
spin_lock(&wdt_lock);
ixp2000_reg_write(IXP2000_RESET0, *(IXP2000_RESET0) | WDT_RESET_ENABLE);
ixp2000_reg_write(IXP2000_TWDE, WDT_ENABLE);
ixp2000_reg_write(IXP2000_T4_CLD, heartbeat * wdt_tick_rate);
ixp2000_reg_write(IXP2000_T4_CTL, TIMER_DIVIDER_256 | TIMER_ENABLE);
spin_unlock(&wdt_lock);
}
static void wdt_disable(void)
{
spin_lock(&wdt_lock);
ixp2000_reg_write(IXP2000_T4_CTL, 0);
spin_unlock(&wdt_lock);
}
static void wdt_keepalive(void)
{
spin_lock(&wdt_lock);
ixp2000_reg_write(IXP2000_T4_CLD, heartbeat * wdt_tick_rate);
spin_unlock(&wdt_lock);
}
static int ixp2000_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
wdt_enable();
return nonseekable_open(inode, file);
}
static ssize_t ixp2000_wdt_write(struct file *file, const char *data,
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
static long ixp2000_wdt_ioctl(struct file *file, unsigned int cmd,
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
wdt_keepalive();
case WDIOC_GETTIMEOUT:
ret = put_user(heartbeat, (int *)arg);
break;
}
return ret;
}
static int ixp2000_wdt_release(struct inode *inode, struct file *file)
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
static int __init ixp2000_wdt_init(void)
{
if ((*IXP2000_PRODUCT_ID & 0x001ffef0) == 0x00000000) {
printk(KERN_INFO "Unable to use IXP2000 watchdog due to IXP2800 erratum #25.\n");
return -EIO;
}
wdt_tick_rate = (*IXP2000_T1_CLD * HZ) / 256;
return misc_register(&ixp2000_wdt_miscdev);
}
static void __exit ixp2000_wdt_exit(void)
{
misc_deregister(&ixp2000_wdt_miscdev);
}
