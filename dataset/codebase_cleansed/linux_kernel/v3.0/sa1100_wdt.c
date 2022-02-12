static int sa1100dog_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(1, &sa1100wdt_users))
return -EBUSY;
OSMR3 = OSCR + pre_margin;
OSSR = OSSR_M3;
OWER = OWER_WME;
OIER |= OIER_E3;
return nonseekable_open(inode, file);
}
static int sa1100dog_release(struct inode *inode, struct file *file)
{
printk(KERN_CRIT "WATCHDOG: Device closed - timer will not stop\n");
clear_bit(1, &sa1100wdt_users);
return 0;
}
static ssize_t sa1100dog_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len)
OSMR3 = OSCR + pre_margin;
return len;
}
static long sa1100dog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
int time;
void __user *argp = (void __user *)arg;
int __user *p = argp;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user(argp, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, p);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(boot_status, p);
break;
case WDIOC_KEEPALIVE:
OSMR3 = OSCR + pre_margin;
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, p);
if (ret)
break;
if (time <= 0 || (oscr_freq * (long long)time >= 0xffffffff)) {
ret = -EINVAL;
break;
}
pre_margin = oscr_freq * time;
OSMR3 = OSCR + pre_margin;
case WDIOC_GETTIMEOUT:
ret = put_user(pre_margin / oscr_freq, p);
break;
}
return ret;
}
static int __init sa1100dog_init(void)
{
int ret;
oscr_freq = get_clock_tick_rate();
boot_status = (reset_status & RESET_STATUS_WATCHDOG) ?
WDIOF_CARDRESET : 0;
pre_margin = oscr_freq * margin;
ret = misc_register(&sa1100dog_miscdev);
if (ret == 0)
printk(KERN_INFO
"SA1100/PXA2xx Watchdog Timer: timer margin %d sec\n",
margin);
return ret;
}
static void __exit sa1100dog_exit(void)
{
misc_deregister(&sa1100dog_miscdev);
}
