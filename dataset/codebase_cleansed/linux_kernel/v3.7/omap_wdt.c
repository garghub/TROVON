static void omap_wdt_ping(struct omap_wdt_dev *wdev)
{
void __iomem *base = wdev->base;
while ((__raw_readl(base + OMAP_WATCHDOG_WPS)) & 0x08)
cpu_relax();
wdt_trgr_pattern = ~wdt_trgr_pattern;
__raw_writel(wdt_trgr_pattern, (base + OMAP_WATCHDOG_TGR));
while ((__raw_readl(base + OMAP_WATCHDOG_WPS)) & 0x08)
cpu_relax();
}
static void omap_wdt_enable(struct omap_wdt_dev *wdev)
{
void __iomem *base = wdev->base;
__raw_writel(0xBBBB, base + OMAP_WATCHDOG_SPR);
while ((__raw_readl(base + OMAP_WATCHDOG_WPS)) & 0x10)
cpu_relax();
__raw_writel(0x4444, base + OMAP_WATCHDOG_SPR);
while ((__raw_readl(base + OMAP_WATCHDOG_WPS)) & 0x10)
cpu_relax();
}
static void omap_wdt_disable(struct omap_wdt_dev *wdev)
{
void __iomem *base = wdev->base;
__raw_writel(0xAAAA, base + OMAP_WATCHDOG_SPR);
while (__raw_readl(base + OMAP_WATCHDOG_WPS) & 0x10)
cpu_relax();
__raw_writel(0x5555, base + OMAP_WATCHDOG_SPR);
while (__raw_readl(base + OMAP_WATCHDOG_WPS) & 0x10)
cpu_relax();
}
static void omap_wdt_adjust_timeout(unsigned new_timeout)
{
if (new_timeout < TIMER_MARGIN_MIN)
new_timeout = TIMER_MARGIN_DEFAULT;
if (new_timeout > TIMER_MARGIN_MAX)
new_timeout = TIMER_MARGIN_MAX;
timer_margin = new_timeout;
}
static void omap_wdt_set_timeout(struct omap_wdt_dev *wdev)
{
u32 pre_margin = GET_WLDR_VAL(timer_margin);
void __iomem *base = wdev->base;
while (__raw_readl(base + OMAP_WATCHDOG_WPS) & 0x04)
cpu_relax();
__raw_writel(pre_margin, base + OMAP_WATCHDOG_LDR);
while (__raw_readl(base + OMAP_WATCHDOG_WPS) & 0x04)
cpu_relax();
}
static int omap_wdt_open(struct inode *inode, struct file *file)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(omap_wdt_dev);
void __iomem *base = wdev->base;
if (test_and_set_bit(1, (unsigned long *)&(wdev->omap_wdt_users)))
return -EBUSY;
pm_runtime_get_sync(wdev->dev);
while (__raw_readl(base + OMAP_WATCHDOG_WPS) & 0x01)
cpu_relax();
__raw_writel((1 << 5) | (PTV << 2), base + OMAP_WATCHDOG_CNTRL);
while (__raw_readl(base + OMAP_WATCHDOG_WPS) & 0x01)
cpu_relax();
file->private_data = (void *) wdev;
omap_wdt_set_timeout(wdev);
omap_wdt_ping(wdev);
omap_wdt_enable(wdev);
return nonseekable_open(inode, file);
}
static int omap_wdt_release(struct inode *inode, struct file *file)
{
struct omap_wdt_dev *wdev = file->private_data;
#ifndef CONFIG_WATCHDOG_NOWAYOUT
omap_wdt_disable(wdev);
pm_runtime_put_sync(wdev->dev);
#else
pr_crit("Unexpected close, not stopping!\n");
#endif
wdev->omap_wdt_users = 0;
return 0;
}
static ssize_t omap_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
struct omap_wdt_dev *wdev = file->private_data;
if (len) {
spin_lock(&wdt_lock);
omap_wdt_ping(wdev);
spin_unlock(&wdt_lock);
}
return len;
}
static long omap_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct omap_wdt_dev *wdev;
int new_margin;
static const struct watchdog_info ident = {
.identity = "OMAP Watchdog",
.options = WDIOF_SETTIMEOUT,
.firmware_version = 0,
};
wdev = file->private_data;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user((struct watchdog_info __user *)arg, &ident,
sizeof(ident));
case WDIOC_GETSTATUS:
return put_user(0, (int __user *)arg);
case WDIOC_GETBOOTSTATUS:
#ifdef CONFIG_ARCH_OMAP1
if (cpu_is_omap16xx())
return put_user(__raw_readw(ARM_SYSST),
(int __user *)arg);
#endif
#ifdef CONFIG_ARCH_OMAP2PLUS
if (cpu_is_omap24xx())
return put_user(omap_prcm_get_reset_sources(),
(int __user *)arg);
#endif
return put_user(0, (int __user *)arg);
case WDIOC_KEEPALIVE:
spin_lock(&wdt_lock);
omap_wdt_ping(wdev);
spin_unlock(&wdt_lock);
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, (int __user *)arg))
return -EFAULT;
omap_wdt_adjust_timeout(new_margin);
spin_lock(&wdt_lock);
omap_wdt_disable(wdev);
omap_wdt_set_timeout(wdev);
omap_wdt_enable(wdev);
omap_wdt_ping(wdev);
spin_unlock(&wdt_lock);
case WDIOC_GETTIMEOUT:
return put_user(timer_margin, (int __user *)arg);
default:
return -ENOTTY;
}
}
static int __devinit omap_wdt_probe(struct platform_device *pdev)
{
struct resource *res, *mem;
struct omap_wdt_dev *wdev;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENOENT;
goto err_get_resource;
}
if (omap_wdt_dev) {
ret = -EBUSY;
goto err_busy;
}
mem = request_mem_region(res->start, resource_size(res), pdev->name);
if (!mem) {
ret = -EBUSY;
goto err_busy;
}
wdev = kzalloc(sizeof(struct omap_wdt_dev), GFP_KERNEL);
if (!wdev) {
ret = -ENOMEM;
goto err_kzalloc;
}
wdev->omap_wdt_users = 0;
wdev->mem = mem;
wdev->dev = &pdev->dev;
wdev->base = ioremap(res->start, resource_size(res));
if (!wdev->base) {
ret = -ENOMEM;
goto err_ioremap;
}
platform_set_drvdata(pdev, wdev);
pm_runtime_enable(wdev->dev);
pm_runtime_get_sync(wdev->dev);
omap_wdt_disable(wdev);
omap_wdt_adjust_timeout(timer_margin);
wdev->omap_wdt_miscdev.parent = &pdev->dev;
wdev->omap_wdt_miscdev.minor = WATCHDOG_MINOR;
wdev->omap_wdt_miscdev.name = "watchdog";
wdev->omap_wdt_miscdev.fops = &omap_wdt_fops;
ret = misc_register(&(wdev->omap_wdt_miscdev));
if (ret)
goto err_misc;
pr_info("OMAP Watchdog Timer Rev 0x%02x: initial timeout %d sec\n",
__raw_readl(wdev->base + OMAP_WATCHDOG_REV) & 0xFF,
timer_margin);
pm_runtime_put_sync(wdev->dev);
omap_wdt_dev = pdev;
return 0;
err_misc:
pm_runtime_disable(wdev->dev);
platform_set_drvdata(pdev, NULL);
iounmap(wdev->base);
err_ioremap:
wdev->base = NULL;
kfree(wdev);
err_kzalloc:
release_mem_region(res->start, resource_size(res));
err_busy:
err_get_resource:
return ret;
}
static void omap_wdt_shutdown(struct platform_device *pdev)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(pdev);
if (wdev->omap_wdt_users) {
omap_wdt_disable(wdev);
pm_runtime_put_sync(wdev->dev);
}
}
static int __devexit omap_wdt_remove(struct platform_device *pdev)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pm_runtime_disable(wdev->dev);
if (!res)
return -ENOENT;
misc_deregister(&(wdev->omap_wdt_miscdev));
release_mem_region(res->start, resource_size(res));
platform_set_drvdata(pdev, NULL);
iounmap(wdev->base);
kfree(wdev);
omap_wdt_dev = NULL;
return 0;
}
static int omap_wdt_suspend(struct platform_device *pdev, pm_message_t state)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(pdev);
if (wdev->omap_wdt_users) {
omap_wdt_disable(wdev);
pm_runtime_put_sync(wdev->dev);
}
return 0;
}
static int omap_wdt_resume(struct platform_device *pdev)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(pdev);
if (wdev->omap_wdt_users) {
pm_runtime_get_sync(wdev->dev);
omap_wdt_enable(wdev);
omap_wdt_ping(wdev);
}
return 0;
}
