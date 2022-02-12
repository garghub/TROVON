static void omap_wdt_reload(struct omap_wdt_dev *wdev)
{
void __iomem *base = wdev->base;
while ((readl_relaxed(base + OMAP_WATCHDOG_WPS)) & 0x08)
cpu_relax();
wdev->wdt_trgr_pattern = ~wdev->wdt_trgr_pattern;
writel_relaxed(wdev->wdt_trgr_pattern, (base + OMAP_WATCHDOG_TGR));
while ((readl_relaxed(base + OMAP_WATCHDOG_WPS)) & 0x08)
cpu_relax();
}
static void omap_wdt_enable(struct omap_wdt_dev *wdev)
{
void __iomem *base = wdev->base;
writel_relaxed(0xBBBB, base + OMAP_WATCHDOG_SPR);
while ((readl_relaxed(base + OMAP_WATCHDOG_WPS)) & 0x10)
cpu_relax();
writel_relaxed(0x4444, base + OMAP_WATCHDOG_SPR);
while ((readl_relaxed(base + OMAP_WATCHDOG_WPS)) & 0x10)
cpu_relax();
}
static void omap_wdt_disable(struct omap_wdt_dev *wdev)
{
void __iomem *base = wdev->base;
writel_relaxed(0xAAAA, base + OMAP_WATCHDOG_SPR);
while (readl_relaxed(base + OMAP_WATCHDOG_WPS) & 0x10)
cpu_relax();
writel_relaxed(0x5555, base + OMAP_WATCHDOG_SPR);
while (readl_relaxed(base + OMAP_WATCHDOG_WPS) & 0x10)
cpu_relax();
}
static void omap_wdt_set_timer(struct omap_wdt_dev *wdev,
unsigned int timeout)
{
u32 pre_margin = GET_WLDR_VAL(timeout);
void __iomem *base = wdev->base;
while (readl_relaxed(base + OMAP_WATCHDOG_WPS) & 0x04)
cpu_relax();
writel_relaxed(pre_margin, base + OMAP_WATCHDOG_LDR);
while (readl_relaxed(base + OMAP_WATCHDOG_WPS) & 0x04)
cpu_relax();
}
static int omap_wdt_start(struct watchdog_device *wdog)
{
struct omap_wdt_dev *wdev = to_omap_wdt_dev(wdog);
void __iomem *base = wdev->base;
mutex_lock(&wdev->lock);
wdev->omap_wdt_users = true;
pm_runtime_get_sync(wdev->dev);
omap_wdt_disable(wdev);
while (readl_relaxed(base + OMAP_WATCHDOG_WPS) & 0x01)
cpu_relax();
writel_relaxed((1 << 5) | (PTV << 2), base + OMAP_WATCHDOG_CNTRL);
while (readl_relaxed(base + OMAP_WATCHDOG_WPS) & 0x01)
cpu_relax();
omap_wdt_set_timer(wdev, wdog->timeout);
omap_wdt_reload(wdev);
omap_wdt_enable(wdev);
mutex_unlock(&wdev->lock);
return 0;
}
static int omap_wdt_stop(struct watchdog_device *wdog)
{
struct omap_wdt_dev *wdev = to_omap_wdt_dev(wdog);
mutex_lock(&wdev->lock);
omap_wdt_disable(wdev);
pm_runtime_put_sync(wdev->dev);
wdev->omap_wdt_users = false;
mutex_unlock(&wdev->lock);
return 0;
}
static int omap_wdt_ping(struct watchdog_device *wdog)
{
struct omap_wdt_dev *wdev = to_omap_wdt_dev(wdog);
mutex_lock(&wdev->lock);
omap_wdt_reload(wdev);
mutex_unlock(&wdev->lock);
return 0;
}
static int omap_wdt_set_timeout(struct watchdog_device *wdog,
unsigned int timeout)
{
struct omap_wdt_dev *wdev = to_omap_wdt_dev(wdog);
mutex_lock(&wdev->lock);
omap_wdt_disable(wdev);
omap_wdt_set_timer(wdev, timeout);
omap_wdt_enable(wdev);
omap_wdt_reload(wdev);
wdog->timeout = timeout;
mutex_unlock(&wdev->lock);
return 0;
}
static unsigned int omap_wdt_get_timeleft(struct watchdog_device *wdog)
{
struct omap_wdt_dev *wdev = to_omap_wdt_dev(wdog);
void __iomem *base = wdev->base;
u32 value;
value = readl_relaxed(base + OMAP_WATCHDOG_CRR);
return GET_WCCR_SECS(value);
}
static int omap_wdt_probe(struct platform_device *pdev)
{
struct omap_wd_timer_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct resource *res;
struct omap_wdt_dev *wdev;
int ret;
wdev = devm_kzalloc(&pdev->dev, sizeof(*wdev), GFP_KERNEL);
if (!wdev)
return -ENOMEM;
wdev->omap_wdt_users = false;
wdev->dev = &pdev->dev;
wdev->wdt_trgr_pattern = 0x1234;
mutex_init(&wdev->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdev->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(wdev->base))
return PTR_ERR(wdev->base);
wdev->wdog.info = &omap_wdt_info;
wdev->wdog.ops = &omap_wdt_ops;
wdev->wdog.min_timeout = TIMER_MARGIN_MIN;
wdev->wdog.max_timeout = TIMER_MARGIN_MAX;
wdev->wdog.parent = &pdev->dev;
if (watchdog_init_timeout(&wdev->wdog, timer_margin, &pdev->dev) < 0)
wdev->wdog.timeout = TIMER_MARGIN_DEFAULT;
watchdog_set_nowayout(&wdev->wdog, nowayout);
platform_set_drvdata(pdev, wdev);
pm_runtime_enable(wdev->dev);
pm_runtime_get_sync(wdev->dev);
if (pdata && pdata->read_reset_sources) {
u32 rs = pdata->read_reset_sources();
if (rs & (1 << OMAP_MPU_WD_RST_SRC_ID_SHIFT))
wdev->wdog.bootstatus = WDIOF_CARDRESET;
}
omap_wdt_disable(wdev);
ret = watchdog_register_device(&wdev->wdog);
if (ret) {
pm_runtime_disable(wdev->dev);
return ret;
}
pr_info("OMAP Watchdog Timer Rev 0x%02x: initial timeout %d sec\n",
readl_relaxed(wdev->base + OMAP_WATCHDOG_REV) & 0xFF,
wdev->wdog.timeout);
pm_runtime_put_sync(wdev->dev);
if (early_enable)
omap_wdt_start(&wdev->wdog);
return 0;
}
static void omap_wdt_shutdown(struct platform_device *pdev)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(pdev);
mutex_lock(&wdev->lock);
if (wdev->omap_wdt_users) {
omap_wdt_disable(wdev);
pm_runtime_put_sync(wdev->dev);
}
mutex_unlock(&wdev->lock);
}
static int omap_wdt_remove(struct platform_device *pdev)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(pdev);
pm_runtime_disable(wdev->dev);
watchdog_unregister_device(&wdev->wdog);
return 0;
}
static int omap_wdt_suspend(struct platform_device *pdev, pm_message_t state)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(pdev);
mutex_lock(&wdev->lock);
if (wdev->omap_wdt_users) {
omap_wdt_disable(wdev);
pm_runtime_put_sync(wdev->dev);
}
mutex_unlock(&wdev->lock);
return 0;
}
static int omap_wdt_resume(struct platform_device *pdev)
{
struct omap_wdt_dev *wdev = platform_get_drvdata(pdev);
mutex_lock(&wdev->lock);
if (wdev->omap_wdt_users) {
pm_runtime_get_sync(wdev->dev);
omap_wdt_enable(wdev);
omap_wdt_reload(wdev);
}
mutex_unlock(&wdev->lock);
return 0;
}
