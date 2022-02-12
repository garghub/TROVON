static int at91rm9200_restart(struct notifier_block *this,
unsigned long mode, void *cmd)
{
regmap_write(regmap_st, AT91_ST_WDMR,
AT91_ST_RSTEN | AT91_ST_EXTEN | 1);
regmap_write(regmap_st, AT91_ST_CR, AT91_ST_WDRST);
mdelay(2000);
pr_emerg("Unable to restart system\n");
return NOTIFY_DONE;
}
static inline void at91_wdt_stop(void)
{
regmap_write(regmap_st, AT91_ST_WDMR, AT91_ST_EXTEN);
}
static inline void at91_wdt_start(void)
{
regmap_write(regmap_st, AT91_ST_WDMR, AT91_ST_EXTEN | AT91_ST_RSTEN |
(((65536 * wdt_time) >> 8) & AT91_ST_WDV));
regmap_write(regmap_st, AT91_ST_CR, AT91_ST_WDRST);
}
static inline void at91_wdt_reload(void)
{
regmap_write(regmap_st, AT91_ST_CR, AT91_ST_WDRST);
}
static int at91_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &at91wdt_busy))
return -EBUSY;
at91_wdt_start();
return nonseekable_open(inode, file);
}
static int at91_wdt_close(struct inode *inode, struct file *file)
{
if (!nowayout)
at91_wdt_stop();
clear_bit(0, &at91wdt_busy);
return 0;
}
static int at91_wdt_settimeout(int new_time)
{
if ((new_time <= 0) || (new_time > WDT_MAX_TIME))
return -EINVAL;
wdt_time = new_time;
return 0;
}
static long at91_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_value;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &at91_wdt_info,
sizeof(at91_wdt_info)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
if (get_user(new_value, p))
return -EFAULT;
if (new_value & WDIOS_DISABLECARD)
at91_wdt_stop();
if (new_value & WDIOS_ENABLECARD)
at91_wdt_start();
return 0;
case WDIOC_KEEPALIVE:
at91_wdt_reload();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_value, p))
return -EFAULT;
if (at91_wdt_settimeout(new_value))
return -EINVAL;
at91_wdt_start();
return put_user(wdt_time, p);
case WDIOC_GETTIMEOUT:
return put_user(wdt_time, p);
default:
return -ENOTTY;
}
}
static ssize_t at91_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
at91_wdt_reload();
return len;
}
static int at91wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device *parent;
int res;
if (at91wdt_miscdev.parent)
return -EBUSY;
at91wdt_miscdev.parent = &pdev->dev;
parent = dev->parent;
if (!parent) {
dev_err(dev, "no parent\n");
return -ENODEV;
}
regmap_st = syscon_node_to_regmap(parent->of_node);
if (IS_ERR(regmap_st))
return -ENODEV;
res = misc_register(&at91wdt_miscdev);
if (res)
return res;
res = register_restart_handler(&at91rm9200_restart_nb);
if (res)
dev_warn(dev, "failed to register restart handler\n");
pr_info("AT91 Watchdog Timer enabled (%d seconds%s)\n",
wdt_time, nowayout ? ", nowayout" : "");
return 0;
}
static int at91wdt_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int res;
res = unregister_restart_handler(&at91rm9200_restart_nb);
if (res)
dev_warn(dev, "failed to unregister restart handler\n");
misc_deregister(&at91wdt_miscdev);
at91wdt_miscdev.parent = NULL;
return res;
}
static void at91wdt_shutdown(struct platform_device *pdev)
{
at91_wdt_stop();
}
static int at91wdt_suspend(struct platform_device *pdev, pm_message_t message)
{
at91_wdt_stop();
return 0;
}
static int at91wdt_resume(struct platform_device *pdev)
{
if (at91wdt_busy)
at91_wdt_start();
return 0;
}
static int __init at91_wdt_init(void)
{
if (at91_wdt_settimeout(wdt_time)) {
at91_wdt_settimeout(WDT_DEFAULT_TIME);
pr_info("wdt_time value must be 1 <= wdt_time <= 256, using %d\n",
wdt_time);
}
return platform_driver_register(&at91wdt_driver);
}
static void __exit at91_wdt_exit(void)
{
platform_driver_unregister(&at91wdt_driver);
}
