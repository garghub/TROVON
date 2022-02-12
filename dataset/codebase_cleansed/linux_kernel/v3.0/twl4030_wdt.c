static int twl4030_wdt_write(unsigned char val)
{
return twl_i2c_write_u8(TWL4030_MODULE_PM_RECEIVER, val,
TWL4030_WATCHDOG_CFG_REG_OFFS);
}
static int twl4030_wdt_enable(struct twl4030_wdt *wdt)
{
return twl4030_wdt_write(wdt->timer_margin + 1);
}
static int twl4030_wdt_disable(struct twl4030_wdt *wdt)
{
return twl4030_wdt_write(0);
}
static int twl4030_wdt_set_timeout(struct twl4030_wdt *wdt, int timeout)
{
if (timeout < 0 || timeout > 30) {
dev_warn(wdt->miscdev.parent,
"Timeout can only be in the range [0-30] seconds");
return -EINVAL;
}
wdt->timer_margin = timeout;
return twl4030_wdt_enable(wdt);
}
static ssize_t twl4030_wdt_write_fop(struct file *file,
const char __user *data, size_t len, loff_t *ppos)
{
struct twl4030_wdt *wdt = file->private_data;
if (len)
twl4030_wdt_enable(wdt);
return len;
}
static long twl4030_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_margin;
struct twl4030_wdt *wdt = file->private_data;
static const struct watchdog_info twl4030_wd_ident = {
.identity = "TWL4030 Watchdog",
.options = WDIOF_SETTIMEOUT,
.firmware_version = 0,
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &twl4030_wd_ident,
sizeof(twl4030_wd_ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
twl4030_wdt_enable(wdt);
break;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, p))
return -EFAULT;
if (twl4030_wdt_set_timeout(wdt, new_margin))
return -EINVAL;
return put_user(wdt->timer_margin, p);
case WDIOC_GETTIMEOUT:
return put_user(wdt->timer_margin, p);
default:
return -ENOTTY;
}
return 0;
}
static int twl4030_wdt_open(struct inode *inode, struct file *file)
{
struct twl4030_wdt *wdt = platform_get_drvdata(twl4030_wdt_dev);
if (test_and_set_bit(0, &wdt->state))
return -EBUSY;
wdt->state |= TWL4030_WDT_STATE_ACTIVE;
file->private_data = (void *) wdt;
twl4030_wdt_enable(wdt);
return nonseekable_open(inode, file);
}
static int twl4030_wdt_release(struct inode *inode, struct file *file)
{
struct twl4030_wdt *wdt = file->private_data;
if (nowayout) {
dev_alert(wdt->miscdev.parent,
"Unexpected close, watchdog still running!\n");
twl4030_wdt_enable(wdt);
} else {
if (twl4030_wdt_disable(wdt))
return -EFAULT;
wdt->state &= ~TWL4030_WDT_STATE_ACTIVE;
}
clear_bit(0, &wdt->state);
return 0;
}
static int __devinit twl4030_wdt_probe(struct platform_device *pdev)
{
int ret = 0;
struct twl4030_wdt *wdt;
wdt = kzalloc(sizeof(struct twl4030_wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->state = 0;
wdt->timer_margin = 30;
wdt->miscdev.parent = &pdev->dev;
wdt->miscdev.fops = &twl4030_wdt_fops;
wdt->miscdev.minor = WATCHDOG_MINOR;
wdt->miscdev.name = "watchdog";
platform_set_drvdata(pdev, wdt);
twl4030_wdt_dev = pdev;
twl4030_wdt_disable(wdt);
ret = misc_register(&wdt->miscdev);
if (ret) {
dev_err(wdt->miscdev.parent,
"Failed to register misc device\n");
platform_set_drvdata(pdev, NULL);
kfree(wdt);
twl4030_wdt_dev = NULL;
return ret;
}
return 0;
}
static int __devexit twl4030_wdt_remove(struct platform_device *pdev)
{
struct twl4030_wdt *wdt = platform_get_drvdata(pdev);
if (wdt->state & TWL4030_WDT_STATE_ACTIVE)
if (twl4030_wdt_disable(wdt))
return -EFAULT;
wdt->state &= ~TWL4030_WDT_STATE_ACTIVE;
misc_deregister(&wdt->miscdev);
platform_set_drvdata(pdev, NULL);
kfree(wdt);
twl4030_wdt_dev = NULL;
return 0;
}
static int twl4030_wdt_suspend(struct platform_device *pdev, pm_message_t state)
{
struct twl4030_wdt *wdt = platform_get_drvdata(pdev);
if (wdt->state & TWL4030_WDT_STATE_ACTIVE)
return twl4030_wdt_disable(wdt);
return 0;
}
static int twl4030_wdt_resume(struct platform_device *pdev)
{
struct twl4030_wdt *wdt = platform_get_drvdata(pdev);
if (wdt->state & TWL4030_WDT_STATE_ACTIVE)
return twl4030_wdt_enable(wdt);
return 0;
}
static int __devinit twl4030_wdt_init(void)
{
return platform_driver_register(&twl4030_wdt_driver);
}
static void __devexit twl4030_wdt_exit(void)
{
platform_driver_unregister(&twl4030_wdt_driver);
}
