static unsigned int atlas7_wdt_gettimeleft(struct watchdog_device *wdd)
{
struct atlas7_wdog *wdt = watchdog_get_drvdata(wdd);
u32 counter, match, delta;
counter = readl(wdt->base + ATLAS7_WDT_CNT);
match = readl(wdt->base + ATLAS7_WDT_CNT_MATCH);
delta = match - counter;
return delta / wdt->tick_rate;
}
static int atlas7_wdt_ping(struct watchdog_device *wdd)
{
struct atlas7_wdog *wdt = watchdog_get_drvdata(wdd);
u32 counter, match, delta;
counter = readl(wdt->base + ATLAS7_WDT_CNT);
delta = wdd->timeout * wdt->tick_rate;
match = counter + delta;
writel(match, wdt->base + ATLAS7_WDT_CNT_MATCH);
return 0;
}
static int atlas7_wdt_enable(struct watchdog_device *wdd)
{
struct atlas7_wdog *wdt = watchdog_get_drvdata(wdd);
atlas7_wdt_ping(wdd);
writel(readl(wdt->base + ATLAS7_WDT_CNT_CTRL) | ATLAS7_WDT_CNT_EN,
wdt->base + ATLAS7_WDT_CNT_CTRL);
writel(1, wdt->base + ATLAS7_WDT_EN);
return 0;
}
static int atlas7_wdt_disable(struct watchdog_device *wdd)
{
struct atlas7_wdog *wdt = watchdog_get_drvdata(wdd);
writel(0, wdt->base + ATLAS7_WDT_EN);
writel(readl(wdt->base + ATLAS7_WDT_CNT_CTRL) & ~ATLAS7_WDT_CNT_EN,
wdt->base + ATLAS7_WDT_CNT_CTRL);
return 0;
}
static int atlas7_wdt_settimeout(struct watchdog_device *wdd, unsigned int to)
{
wdd->timeout = to;
return 0;
}
static int atlas7_wdt_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct atlas7_wdog *wdt;
struct resource *res;
struct clk *clk;
int ret;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(wdt->base))
return PTR_ERR(wdt->base);
clk = of_clk_get(np, 0);
if (IS_ERR(clk))
return PTR_ERR(clk);
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(&pdev->dev, "clk enable failed\n");
goto err;
}
writel(0, wdt->base + ATLAS7_WDT_CNT_CTRL);
wdt->tick_rate = clk_get_rate(clk);
wdt->clk = clk;
atlas7_wdd.min_timeout = 1;
atlas7_wdd.max_timeout = UINT_MAX / wdt->tick_rate;
watchdog_init_timeout(&atlas7_wdd, 0, &pdev->dev);
watchdog_set_nowayout(&atlas7_wdd, nowayout);
watchdog_set_drvdata(&atlas7_wdd, wdt);
platform_set_drvdata(pdev, &atlas7_wdd);
ret = watchdog_register_device(&atlas7_wdd);
if (ret)
goto err1;
return 0;
err1:
clk_disable_unprepare(clk);
err:
clk_put(clk);
return ret;
}
static void atlas7_wdt_shutdown(struct platform_device *pdev)
{
struct watchdog_device *wdd = platform_get_drvdata(pdev);
struct atlas7_wdog *wdt = watchdog_get_drvdata(wdd);
atlas7_wdt_disable(wdd);
clk_disable_unprepare(wdt->clk);
}
static int atlas7_wdt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdd = platform_get_drvdata(pdev);
struct atlas7_wdog *wdt = watchdog_get_drvdata(wdd);
atlas7_wdt_shutdown(pdev);
clk_put(wdt->clk);
return 0;
}
static int __maybe_unused atlas7_wdt_suspend(struct device *dev)
{
return 0;
}
static int __maybe_unused atlas7_wdt_resume(struct device *dev)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
atlas7_wdt_ping(wdd);
return 0;
}
