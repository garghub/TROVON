static void bcm7038_wdt_set_timeout_reg(struct watchdog_device *wdog)
{
struct bcm7038_watchdog *wdt = watchdog_get_drvdata(wdog);
u32 timeout;
timeout = wdt->rate * wdog->timeout;
writel(timeout, wdt->base + WDT_TIMEOUT_REG);
}
static int bcm7038_wdt_ping(struct watchdog_device *wdog)
{
struct bcm7038_watchdog *wdt = watchdog_get_drvdata(wdog);
writel(WDT_START_1, wdt->base + WDT_CMD_REG);
writel(WDT_START_2, wdt->base + WDT_CMD_REG);
return 0;
}
static int bcm7038_wdt_start(struct watchdog_device *wdog)
{
bcm7038_wdt_set_timeout_reg(wdog);
bcm7038_wdt_ping(wdog);
return 0;
}
static int bcm7038_wdt_stop(struct watchdog_device *wdog)
{
struct bcm7038_watchdog *wdt = watchdog_get_drvdata(wdog);
writel(WDT_STOP_1, wdt->base + WDT_CMD_REG);
writel(WDT_STOP_2, wdt->base + WDT_CMD_REG);
return 0;
}
static int bcm7038_wdt_set_timeout(struct watchdog_device *wdog,
unsigned int t)
{
bcm7038_wdt_stop(wdog);
wdog->timeout = t;
bcm7038_wdt_start(wdog);
return 0;
}
static unsigned int bcm7038_wdt_get_timeleft(struct watchdog_device *wdog)
{
struct bcm7038_watchdog *wdt = watchdog_get_drvdata(wdog);
u32 time_left;
time_left = readl(wdt->base + WDT_CMD_REG);
return time_left / wdt->rate;
}
static int bcm7038_wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct bcm7038_watchdog *wdt;
struct resource *res;
int err;
wdt = devm_kzalloc(dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
platform_set_drvdata(pdev, wdt);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->base = devm_ioremap_resource(dev, res);
if (IS_ERR(wdt->base))
return PTR_ERR(wdt->base);
wdt->clk = devm_clk_get(dev, NULL);
if (!IS_ERR(wdt->clk)) {
err = clk_prepare_enable(wdt->clk);
if (err)
return err;
wdt->rate = clk_get_rate(wdt->clk);
if (!wdt->rate)
wdt->rate = WDT_DEFAULT_RATE;
} else {
wdt->rate = WDT_DEFAULT_RATE;
wdt->clk = NULL;
}
wdt->wdd.info = &bcm7038_wdt_info;
wdt->wdd.ops = &bcm7038_wdt_ops;
wdt->wdd.min_timeout = WDT_MIN_TIMEOUT;
wdt->wdd.timeout = WDT_DEFAULT_TIMEOUT;
wdt->wdd.max_timeout = 0xffffffff / wdt->rate;
wdt->wdd.parent = dev;
watchdog_set_drvdata(&wdt->wdd, wdt);
err = watchdog_register_device(&wdt->wdd);
if (err) {
dev_err(dev, "Failed to register watchdog device\n");
clk_disable_unprepare(wdt->clk);
return err;
}
dev_info(dev, "Registered BCM7038 Watchdog\n");
return 0;
}
static int bcm7038_wdt_remove(struct platform_device *pdev)
{
struct bcm7038_watchdog *wdt = platform_get_drvdata(pdev);
if (!nowayout)
bcm7038_wdt_stop(&wdt->wdd);
watchdog_unregister_device(&wdt->wdd);
clk_disable_unprepare(wdt->clk);
return 0;
}
static int bcm7038_wdt_suspend(struct device *dev)
{
struct bcm7038_watchdog *wdt = dev_get_drvdata(dev);
if (watchdog_active(&wdt->wdd))
return bcm7038_wdt_stop(&wdt->wdd);
return 0;
}
static int bcm7038_wdt_resume(struct device *dev)
{
struct bcm7038_watchdog *wdt = dev_get_drvdata(dev);
if (watchdog_active(&wdt->wdd))
return bcm7038_wdt_start(&wdt->wdd);
return 0;
}
static void bcm7038_wdt_shutdown(struct platform_device *pdev)
{
struct bcm7038_watchdog *wdt = platform_get_drvdata(pdev);
if (watchdog_active(&wdt->wdd))
bcm7038_wdt_stop(&wdt->wdd);
}
