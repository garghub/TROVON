static int mtk_wdt_restart(struct watchdog_device *wdt_dev,
unsigned long action, void *data)
{
struct mtk_wdt_dev *mtk_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base;
wdt_base = mtk_wdt->wdt_base;
while (1) {
writel(WDT_SWRST_KEY, wdt_base + WDT_SWRST);
mdelay(5);
}
return 0;
}
static int mtk_wdt_ping(struct watchdog_device *wdt_dev)
{
struct mtk_wdt_dev *mtk_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = mtk_wdt->wdt_base;
iowrite32(WDT_RST_RELOAD, wdt_base + WDT_RST);
return 0;
}
static int mtk_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct mtk_wdt_dev *mtk_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = mtk_wdt->wdt_base;
u32 reg;
wdt_dev->timeout = timeout;
reg = WDT_LENGTH_TIMEOUT(timeout << 6) | WDT_LENGTH_KEY;
iowrite32(reg, wdt_base + WDT_LENGTH);
mtk_wdt_ping(wdt_dev);
return 0;
}
static int mtk_wdt_stop(struct watchdog_device *wdt_dev)
{
struct mtk_wdt_dev *mtk_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = mtk_wdt->wdt_base;
u32 reg;
reg = readl(wdt_base + WDT_MODE);
reg &= ~WDT_MODE_EN;
reg |= WDT_MODE_KEY;
iowrite32(reg, wdt_base + WDT_MODE);
return 0;
}
static int mtk_wdt_start(struct watchdog_device *wdt_dev)
{
u32 reg;
struct mtk_wdt_dev *mtk_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = mtk_wdt->wdt_base;
int ret;
ret = mtk_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
if (ret < 0)
return ret;
reg = ioread32(wdt_base + WDT_MODE);
reg &= ~(WDT_MODE_IRQ_EN | WDT_MODE_DUAL_EN);
reg |= (WDT_MODE_EN | WDT_MODE_KEY);
iowrite32(reg, wdt_base + WDT_MODE);
return 0;
}
static int mtk_wdt_probe(struct platform_device *pdev)
{
struct mtk_wdt_dev *mtk_wdt;
struct resource *res;
int err;
mtk_wdt = devm_kzalloc(&pdev->dev, sizeof(*mtk_wdt), GFP_KERNEL);
if (!mtk_wdt)
return -ENOMEM;
platform_set_drvdata(pdev, mtk_wdt);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mtk_wdt->wdt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mtk_wdt->wdt_base))
return PTR_ERR(mtk_wdt->wdt_base);
mtk_wdt->wdt_dev.info = &mtk_wdt_info;
mtk_wdt->wdt_dev.ops = &mtk_wdt_ops;
mtk_wdt->wdt_dev.timeout = WDT_MAX_TIMEOUT;
mtk_wdt->wdt_dev.max_timeout = WDT_MAX_TIMEOUT;
mtk_wdt->wdt_dev.min_timeout = WDT_MIN_TIMEOUT;
mtk_wdt->wdt_dev.parent = &pdev->dev;
watchdog_init_timeout(&mtk_wdt->wdt_dev, timeout, &pdev->dev);
watchdog_set_nowayout(&mtk_wdt->wdt_dev, nowayout);
watchdog_set_restart_priority(&mtk_wdt->wdt_dev, 128);
watchdog_set_drvdata(&mtk_wdt->wdt_dev, mtk_wdt);
mtk_wdt_stop(&mtk_wdt->wdt_dev);
err = watchdog_register_device(&mtk_wdt->wdt_dev);
if (unlikely(err))
return err;
dev_info(&pdev->dev, "Watchdog enabled (timeout=%d sec, nowayout=%d)\n",
mtk_wdt->wdt_dev.timeout, nowayout);
return 0;
}
static void mtk_wdt_shutdown(struct platform_device *pdev)
{
struct mtk_wdt_dev *mtk_wdt = platform_get_drvdata(pdev);
if (watchdog_active(&mtk_wdt->wdt_dev))
mtk_wdt_stop(&mtk_wdt->wdt_dev);
}
static int mtk_wdt_remove(struct platform_device *pdev)
{
struct mtk_wdt_dev *mtk_wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&mtk_wdt->wdt_dev);
return 0;
}
static int mtk_wdt_suspend(struct device *dev)
{
struct mtk_wdt_dev *mtk_wdt = dev_get_drvdata(dev);
if (watchdog_active(&mtk_wdt->wdt_dev))
mtk_wdt_stop(&mtk_wdt->wdt_dev);
return 0;
}
static int mtk_wdt_resume(struct device *dev)
{
struct mtk_wdt_dev *mtk_wdt = dev_get_drvdata(dev);
if (watchdog_active(&mtk_wdt->wdt_dev)) {
mtk_wdt_start(&mtk_wdt->wdt_dev);
mtk_wdt_ping(&mtk_wdt->wdt_dev);
}
return 0;
}
