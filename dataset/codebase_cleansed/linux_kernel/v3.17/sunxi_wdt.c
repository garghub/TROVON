static void sun4i_wdt_restart(enum reboot_mode mode, const char *cmd)
{
writel(WDT_MODE_EN | WDT_MODE_RST_EN, reboot_wdt_base + WDT_MODE);
writel(WDT_CTRL_RELOAD, reboot_wdt_base + WDT_CTRL);
while (1) {
mdelay(5);
writel(WDT_MODE_EN | WDT_MODE_RST_EN,
reboot_wdt_base + WDT_MODE);
}
}
static int sunxi_wdt_ping(struct watchdog_device *wdt_dev)
{
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
iowrite32(WDT_CTRL_RELOAD, wdt_base + WDT_CTRL);
return 0;
}
static int sunxi_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
u32 reg;
if (wdt_timeout_map[timeout] == 0)
timeout++;
sunxi_wdt->wdt_dev.timeout = timeout;
reg = ioread32(wdt_base + WDT_MODE);
reg &= ~WDT_TIMEOUT_MASK;
reg |= WDT_MODE_TIMEOUT(wdt_timeout_map[timeout]);
iowrite32(reg, wdt_base + WDT_MODE);
sunxi_wdt_ping(wdt_dev);
return 0;
}
static int sunxi_wdt_stop(struct watchdog_device *wdt_dev)
{
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
iowrite32(0, wdt_base + WDT_MODE);
return 0;
}
static int sunxi_wdt_start(struct watchdog_device *wdt_dev)
{
u32 reg;
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
int ret;
ret = sunxi_wdt_set_timeout(&sunxi_wdt->wdt_dev,
sunxi_wdt->wdt_dev.timeout);
if (ret < 0)
return ret;
reg = ioread32(wdt_base + WDT_MODE);
reg |= (WDT_MODE_RST_EN | WDT_MODE_EN);
iowrite32(reg, wdt_base + WDT_MODE);
return 0;
}
static int sunxi_wdt_probe(struct platform_device *pdev)
{
struct sunxi_wdt_dev *sunxi_wdt;
struct resource *res;
int err;
sunxi_wdt = devm_kzalloc(&pdev->dev, sizeof(*sunxi_wdt), GFP_KERNEL);
if (!sunxi_wdt)
return -EINVAL;
platform_set_drvdata(pdev, sunxi_wdt);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sunxi_wdt->wdt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(sunxi_wdt->wdt_base))
return PTR_ERR(sunxi_wdt->wdt_base);
sunxi_wdt->wdt_dev.info = &sunxi_wdt_info;
sunxi_wdt->wdt_dev.ops = &sunxi_wdt_ops;
sunxi_wdt->wdt_dev.timeout = WDT_MAX_TIMEOUT;
sunxi_wdt->wdt_dev.max_timeout = WDT_MAX_TIMEOUT;
sunxi_wdt->wdt_dev.min_timeout = WDT_MIN_TIMEOUT;
sunxi_wdt->wdt_dev.parent = &pdev->dev;
watchdog_init_timeout(&sunxi_wdt->wdt_dev, timeout, &pdev->dev);
watchdog_set_nowayout(&sunxi_wdt->wdt_dev, nowayout);
watchdog_set_drvdata(&sunxi_wdt->wdt_dev, sunxi_wdt);
sunxi_wdt_stop(&sunxi_wdt->wdt_dev);
err = watchdog_register_device(&sunxi_wdt->wdt_dev);
if (unlikely(err))
return err;
reboot_wdt_base = sunxi_wdt->wdt_base;
arm_pm_restart = sun4i_wdt_restart;
dev_info(&pdev->dev, "Watchdog enabled (timeout=%d sec, nowayout=%d)",
sunxi_wdt->wdt_dev.timeout, nowayout);
return 0;
}
static int sunxi_wdt_remove(struct platform_device *pdev)
{
struct sunxi_wdt_dev *sunxi_wdt = platform_get_drvdata(pdev);
arm_pm_restart = NULL;
watchdog_unregister_device(&sunxi_wdt->wdt_dev);
watchdog_set_drvdata(&sunxi_wdt->wdt_dev, NULL);
return 0;
}
static void sunxi_wdt_shutdown(struct platform_device *pdev)
{
struct sunxi_wdt_dev *sunxi_wdt = platform_get_drvdata(pdev);
sunxi_wdt_stop(&sunxi_wdt->wdt_dev);
}
