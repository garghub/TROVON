static inline void ks8695_wdt_stop(void)
{
unsigned long tmcon;
spin_lock(&ks8695_lock);
tmcon = __raw_readl(KS8695_TMR_VA + KS8695_TMCON);
__raw_writel(tmcon & ~TMCON_T0EN, KS8695_TMR_VA + KS8695_TMCON);
spin_unlock(&ks8695_lock);
}
static inline void ks8695_wdt_start(void)
{
unsigned long tmcon;
unsigned long tval = wdt_time * KS8695_CLOCK_RATE;
spin_lock(&ks8695_lock);
tmcon = __raw_readl(KS8695_TMR_VA + KS8695_TMCON);
__raw_writel(tmcon & ~TMCON_T0EN, KS8695_TMR_VA + KS8695_TMCON);
__raw_writel(tval | T0TC_WATCHDOG, KS8695_TMR_VA + KS8695_T0TC);
tmcon = __raw_readl(KS8695_TMR_VA + KS8695_TMCON);
__raw_writel(tmcon | TMCON_T0EN, KS8695_TMR_VA + KS8695_TMCON);
spin_unlock(&ks8695_lock);
}
static inline void ks8695_wdt_reload(void)
{
unsigned long tmcon;
spin_lock(&ks8695_lock);
tmcon = __raw_readl(KS8695_TMR_VA + KS8695_TMCON);
__raw_writel(tmcon & ~TMCON_T0EN, KS8695_TMR_VA + KS8695_TMCON);
__raw_writel(tmcon | TMCON_T0EN, KS8695_TMR_VA + KS8695_TMCON);
spin_unlock(&ks8695_lock);
}
static int ks8695_wdt_settimeout(int new_time)
{
if ((new_time <= 0) || (new_time > WDT_MAX_TIME))
return -EINVAL;
wdt_time = new_time;
return 0;
}
static int ks8695_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &ks8695wdt_busy))
return -EBUSY;
ks8695_wdt_start();
return nonseekable_open(inode, file);
}
static int ks8695_wdt_close(struct inode *inode, struct file *file)
{
if (!nowayout)
ks8695_wdt_stop();
clear_bit(0, &ks8695wdt_busy);
return 0;
}
static long ks8695_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_value;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ks8695_wdt_info,
sizeof(ks8695_wdt_info)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
if (get_user(new_value, p))
return -EFAULT;
if (new_value & WDIOS_DISABLECARD)
ks8695_wdt_stop();
if (new_value & WDIOS_ENABLECARD)
ks8695_wdt_start();
return 0;
case WDIOC_KEEPALIVE:
ks8695_wdt_reload();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_value, p))
return -EFAULT;
if (ks8695_wdt_settimeout(new_value))
return -EINVAL;
ks8695_wdt_start();
return put_user(wdt_time, p);
case WDIOC_GETTIMEOUT:
return put_user(wdt_time, p);
default:
return -ENOTTY;
}
}
static ssize_t ks8695_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
ks8695_wdt_reload();
return len;
}
static int __devinit ks8695wdt_probe(struct platform_device *pdev)
{
int res;
if (ks8695wdt_miscdev.parent)
return -EBUSY;
ks8695wdt_miscdev.parent = &pdev->dev;
res = misc_register(&ks8695wdt_miscdev);
if (res)
return res;
printk(KERN_INFO "KS8695 Watchdog Timer enabled (%d seconds%s)\n",
wdt_time, nowayout ? ", nowayout" : "");
return 0;
}
static int __devexit ks8695wdt_remove(struct platform_device *pdev)
{
int res;
res = misc_deregister(&ks8695wdt_miscdev);
if (!res)
ks8695wdt_miscdev.parent = NULL;
return res;
}
static void ks8695wdt_shutdown(struct platform_device *pdev)
{
ks8695_wdt_stop();
}
static int ks8695wdt_suspend(struct platform_device *pdev, pm_message_t message)
{
ks8695_wdt_stop();
return 0;
}
static int ks8695wdt_resume(struct platform_device *pdev)
{
if (ks8695wdt_busy)
ks8695_wdt_start();
return 0;
}
static int __init ks8695_wdt_init(void)
{
spin_lock_init(&ks8695_lock);
if (ks8695_wdt_settimeout(wdt_time)) {
ks8695_wdt_settimeout(WDT_DEFAULT_TIME);
pr_info("ks8695_wdt: wdt_time value must be 1 <= wdt_time <= %i"
", using %d\n", wdt_time, WDT_MAX_TIME);
}
return platform_driver_register(&ks8695wdt_driver);
}
static void __exit ks8695_wdt_exit(void)
{
platform_driver_unregister(&ks8695wdt_driver);
}
