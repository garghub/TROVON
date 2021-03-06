static void adx_wdt_start_locked(struct adx_wdt *wdt)
{
u32 ctrl;
ctrl = readl(wdt->base + ADX_WDT_CONTROL);
ctrl |= ADX_WDT_CONTROL_ENABLE;
writel(ctrl, wdt->base + ADX_WDT_CONTROL);
wdt->state = WDT_STATE_START;
}
static void adx_wdt_start(struct adx_wdt *wdt)
{
unsigned long flags;
spin_lock_irqsave(&wdt->lock, flags);
adx_wdt_start_locked(wdt);
spin_unlock_irqrestore(&wdt->lock, flags);
}
static void adx_wdt_stop_locked(struct adx_wdt *wdt)
{
u32 ctrl;
ctrl = readl(wdt->base + ADX_WDT_CONTROL);
ctrl &= ~ADX_WDT_CONTROL_ENABLE;
writel(ctrl, wdt->base + ADX_WDT_CONTROL);
wdt->state = WDT_STATE_STOP;
}
static void adx_wdt_stop(struct adx_wdt *wdt)
{
unsigned long flags;
spin_lock_irqsave(&wdt->lock, flags);
adx_wdt_stop_locked(wdt);
spin_unlock_irqrestore(&wdt->lock, flags);
}
static void adx_wdt_set_timeout(struct adx_wdt *wdt, unsigned long seconds)
{
unsigned long timeout = seconds * 1000;
unsigned long flags;
unsigned int state;
spin_lock_irqsave(&wdt->lock, flags);
state = wdt->state;
adx_wdt_stop_locked(wdt);
writel(timeout, wdt->base + ADX_WDT_TIMEOUT);
if (state == WDT_STATE_START)
adx_wdt_start_locked(wdt);
wdt->timeout = timeout;
spin_unlock_irqrestore(&wdt->lock, flags);
}
static void adx_wdt_get_timeout(struct adx_wdt *wdt, unsigned long *seconds)
{
*seconds = wdt->timeout / 1000;
}
static void adx_wdt_keepalive(struct adx_wdt *wdt)
{
unsigned long flags;
spin_lock_irqsave(&wdt->lock, flags);
writel(wdt->timeout, wdt->base + ADX_WDT_TIMEOUT);
spin_unlock_irqrestore(&wdt->lock, flags);
}
static int adx_wdt_open(struct inode *inode, struct file *file)
{
struct adx_wdt *wdt = platform_get_drvdata(adx_wdt_dev);
if (test_and_set_bit(0, &driver_open))
return -EBUSY;
file->private_data = wdt;
adx_wdt_set_timeout(wdt, 30);
adx_wdt_start(wdt);
return nonseekable_open(inode, file);
}
static int adx_wdt_release(struct inode *inode, struct file *file)
{
struct adx_wdt *wdt = file->private_data;
adx_wdt_stop(wdt);
clear_bit(0, &driver_open);
return 0;
}
static long adx_wdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct adx_wdt *wdt = file->private_data;
void __user *argp = (void __user *)arg;
unsigned long __user *p = argp;
unsigned long seconds = 0;
unsigned int options;
long ret = -EINVAL;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &adx_wdt_info, sizeof(adx_wdt_info)))
return -EFAULT;
else
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
adx_wdt_keepalive(wdt);
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(seconds, p))
return -EFAULT;
adx_wdt_set_timeout(wdt, seconds);
case WDIOC_GETTIMEOUT:
adx_wdt_get_timeout(wdt, &seconds);
return put_user(seconds, p);
case WDIOC_SETOPTIONS:
if (copy_from_user(&options, argp, sizeof(options)))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
adx_wdt_stop(wdt);
ret = 0;
}
if (options & WDIOS_ENABLECARD) {
adx_wdt_start(wdt);
ret = 0;
}
return ret;
default:
break;
}
return -ENOTTY;
}
static ssize_t adx_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
struct adx_wdt *wdt = file->private_data;
if (len)
adx_wdt_keepalive(wdt);
return len;
}
static int __devinit adx_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
struct adx_wdt *wdt;
int ret = 0;
u32 ctrl;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt) {
dev_err(&pdev->dev, "cannot allocate WDT structure\n");
return -ENOMEM;
}
spin_lock_init(&wdt->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "cannot obtain I/O memory region\n");
return -ENXIO;
}
res = devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), res->name);
if (!res) {
dev_err(&pdev->dev, "cannot request I/O memory region\n");
return -ENXIO;
}
wdt->base = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (!wdt->base) {
dev_err(&pdev->dev, "cannot remap I/O memory region\n");
return -ENXIO;
}
ctrl = readl(wdt->base + ADX_WDT_CONTROL);
ctrl &= ~ADX_WDT_CONTROL_ENABLE;
ctrl &= ~ADX_WDT_CONTROL_nRESET;
writel(ctrl, wdt->base + ADX_WDT_CONTROL);
platform_set_drvdata(pdev, wdt);
adx_wdt_dev = pdev;
ret = misc_register(&adx_wdt_miscdev);
if (ret) {
dev_err(&pdev->dev, "cannot register miscdev on minor %d "
"(err=%d)\n", WATCHDOG_MINOR, ret);
return ret;
}
return 0;
}
static int __devexit adx_wdt_remove(struct platform_device *pdev)
{
struct adx_wdt *wdt = platform_get_drvdata(pdev);
misc_deregister(&adx_wdt_miscdev);
adx_wdt_stop(wdt);
platform_set_drvdata(pdev, NULL);
return 0;
}
static void adx_wdt_shutdown(struct platform_device *pdev)
{
struct adx_wdt *wdt = platform_get_drvdata(pdev);
adx_wdt_stop(wdt);
}
static int adx_wdt_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct adx_wdt *wdt = platform_get_drvdata(pdev);
wdt->wake = (wdt->state == WDT_STATE_START) ? 1 : 0;
adx_wdt_stop(wdt);
return 0;
}
static int adx_wdt_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct adx_wdt *wdt = platform_get_drvdata(pdev);
if (wdt->wake)
adx_wdt_start(wdt);
return 0;
}
static int __init adx_wdt_init(void)
{
return platform_driver_register(&adx_wdt_driver);
}
static void __exit adx_wdt_exit(void)
{
platform_driver_unregister(&adx_wdt_driver);
}
