static irqreturn_t mpcore_wdt_fire(int irq, void *arg)
{
struct mpcore_wdt *wdt = arg;
if (readl(wdt->base + TWD_WDOG_INTSTAT)) {
dev_printk(KERN_CRIT, wdt->dev,
"Triggered - Reboot ignored.\n");
writel(1, wdt->base + TWD_WDOG_INTSTAT);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void mpcore_wdt_keepalive(struct mpcore_wdt *wdt)
{
unsigned long count;
spin_lock(&wdt_lock);
count = __raw_readl(wdt->base + TWD_WDOG_COUNTER);
count = (0xFFFFFFFFU - count) * (HZ / 5);
count = (count / 256) * mpcore_margin;
writel(count + wdt->perturb, wdt->base + TWD_WDOG_LOAD);
wdt->perturb = wdt->perturb ? 0 : 1;
spin_unlock(&wdt_lock);
}
static void mpcore_wdt_stop(struct mpcore_wdt *wdt)
{
spin_lock(&wdt_lock);
writel(0x12345678, wdt->base + TWD_WDOG_DISABLE);
writel(0x87654321, wdt->base + TWD_WDOG_DISABLE);
writel(0x0, wdt->base + TWD_WDOG_CONTROL);
spin_unlock(&wdt_lock);
}
static void mpcore_wdt_start(struct mpcore_wdt *wdt)
{
dev_printk(KERN_INFO, wdt->dev, "enabling watchdog.\n");
mpcore_wdt_keepalive(wdt);
if (mpcore_noboot) {
writel(0x0000FF01, wdt->base + TWD_WDOG_CONTROL);
} else {
writel(0x0000FF09, wdt->base + TWD_WDOG_CONTROL);
}
}
static int mpcore_wdt_set_heartbeat(int t)
{
if (t < 0x0001 || t > 0xFFFF)
return -EINVAL;
mpcore_margin = t;
return 0;
}
static int mpcore_wdt_open(struct inode *inode, struct file *file)
{
struct mpcore_wdt *wdt = platform_get_drvdata(mpcore_wdt_pdev);
if (test_and_set_bit(0, &wdt->timer_alive))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
file->private_data = wdt;
mpcore_wdt_start(wdt);
return nonseekable_open(inode, file);
}
static int mpcore_wdt_release(struct inode *inode, struct file *file)
{
struct mpcore_wdt *wdt = file->private_data;
if (wdt->expect_close == 42)
mpcore_wdt_stop(wdt);
else {
dev_printk(KERN_CRIT, wdt->dev,
"unexpected close, not stopping watchdog!\n");
mpcore_wdt_keepalive(wdt);
}
clear_bit(0, &wdt->timer_alive);
wdt->expect_close = 0;
return 0;
}
static ssize_t mpcore_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
struct mpcore_wdt *wdt = file->private_data;
if (len) {
if (!nowayout) {
size_t i;
wdt->expect_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
wdt->expect_close = 42;
}
}
mpcore_wdt_keepalive(wdt);
}
return len;
}
static long mpcore_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct mpcore_wdt *wdt = file->private_data;
int ret;
union {
struct watchdog_info ident;
int i;
} uarg;
if (_IOC_DIR(cmd) && _IOC_SIZE(cmd) > sizeof(uarg))
return -ENOTTY;
if (_IOC_DIR(cmd) & _IOC_WRITE) {
ret = copy_from_user(&uarg, (void __user *)arg, _IOC_SIZE(cmd));
if (ret)
return -EFAULT;
}
switch (cmd) {
case WDIOC_GETSUPPORT:
uarg.ident = ident;
ret = 0;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
uarg.i = 0;
ret = 0;
break;
case WDIOC_SETOPTIONS:
ret = -EINVAL;
if (uarg.i & WDIOS_DISABLECARD) {
mpcore_wdt_stop(wdt);
ret = 0;
}
if (uarg.i & WDIOS_ENABLECARD) {
mpcore_wdt_start(wdt);
ret = 0;
}
break;
case WDIOC_KEEPALIVE:
mpcore_wdt_keepalive(wdt);
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = mpcore_wdt_set_heartbeat(uarg.i);
if (ret)
break;
mpcore_wdt_keepalive(wdt);
case WDIOC_GETTIMEOUT:
uarg.i = mpcore_margin;
ret = 0;
break;
default:
return -ENOTTY;
}
if (ret == 0 && _IOC_DIR(cmd) & _IOC_READ) {
ret = copy_to_user((void __user *)arg, &uarg, _IOC_SIZE(cmd));
if (ret)
ret = -EFAULT;
}
return ret;
}
static void mpcore_wdt_shutdown(struct platform_device *pdev)
{
struct mpcore_wdt *wdt = platform_get_drvdata(pdev);
if (system_state == SYSTEM_RESTART || system_state == SYSTEM_HALT)
mpcore_wdt_stop(wdt);
}
static int __devinit mpcore_wdt_probe(struct platform_device *pdev)
{
struct mpcore_wdt *wdt;
struct resource *res;
int ret;
if (pdev->id != -1)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
wdt = devm_kzalloc(&pdev->dev, sizeof(struct mpcore_wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->dev = &pdev->dev;
wdt->irq = platform_get_irq(pdev, 0);
if (wdt->irq >= 0) {
ret = devm_request_irq(wdt->dev, wdt->irq, mpcore_wdt_fire, 0,
"mpcore_wdt", wdt);
if (ret) {
dev_printk(KERN_ERR, wdt->dev,
"cannot register IRQ%d for watchdog\n",
wdt->irq);
return ret;
}
}
wdt->base = devm_ioremap(wdt->dev, res->start, resource_size(res));
if (!wdt->base)
return -ENOMEM;
mpcore_wdt_miscdev.parent = &pdev->dev;
ret = misc_register(&mpcore_wdt_miscdev);
if (ret) {
dev_printk(KERN_ERR, wdt->dev,
"cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
return ret;
}
mpcore_wdt_stop(wdt);
platform_set_drvdata(pdev, wdt);
mpcore_wdt_pdev = pdev;
return 0;
}
static int __devexit mpcore_wdt_remove(struct platform_device *pdev)
{
platform_set_drvdata(pdev, NULL);
misc_deregister(&mpcore_wdt_miscdev);
mpcore_wdt_pdev = NULL;
return 0;
}
static int mpcore_wdt_suspend(struct platform_device *pdev, pm_message_t msg)
{
struct mpcore_wdt *wdt = platform_get_drvdata(pdev);
mpcore_wdt_stop(wdt);
return 0;
}
static int mpcore_wdt_resume(struct platform_device *pdev)
{
struct mpcore_wdt *wdt = platform_get_drvdata(pdev);
if (test_bit(0, &wdt->timer_alive))
mpcore_wdt_start(wdt);
return 0;
}
static int __init mpcore_wdt_init(void)
{
if (mpcore_wdt_set_heartbeat(mpcore_margin)) {
mpcore_wdt_set_heartbeat(TIMER_MARGIN);
pr_info("mpcore_margin value must be 0 < mpcore_margin < 65536, using %d\n",
TIMER_MARGIN);
}
pr_info("MPcore Watchdog Timer: 0.1. mpcore_noboot=%d mpcore_margin=%d sec (nowayout= %d)\n",
mpcore_noboot, mpcore_margin, nowayout);
return platform_driver_register(&mpcore_wdt_driver);
}
static void __exit mpcore_wdt_exit(void)
{
platform_driver_unregister(&mpcore_wdt_driver);
}
