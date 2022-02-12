static unsigned int sirfsoc_wdt_gettimeleft(struct watchdog_device *wdd)
{
u32 counter, match;
void __iomem *wdt_base;
int time_left;
wdt_base = watchdog_get_drvdata(wdd);
counter = readl(wdt_base + SIRFSOC_TIMER_COUNTER_LO);
match = readl(wdt_base +
SIRFSOC_TIMER_MATCH_0 + (SIRFSOC_TIMER_WDT_INDEX << 2));
time_left = match - counter;
return time_left / CLOCK_FREQ;
}
static int sirfsoc_wdt_updatetimeout(struct watchdog_device *wdd)
{
u32 counter, timeout_ticks;
void __iomem *wdt_base;
timeout_ticks = wdd->timeout * CLOCK_FREQ;
wdt_base = watchdog_get_drvdata(wdd);
writel(1, wdt_base + SIRFSOC_TIMER_LATCH);
counter = readl(wdt_base + SIRFSOC_TIMER_LATCHED_LO);
counter += timeout_ticks;
writel(counter, wdt_base +
SIRFSOC_TIMER_MATCH_0 + (SIRFSOC_TIMER_WDT_INDEX << 2));
return 0;
}
static int sirfsoc_wdt_enable(struct watchdog_device *wdd)
{
void __iomem *wdt_base = watchdog_get_drvdata(wdd);
sirfsoc_wdt_updatetimeout(wdd);
writel(readl(wdt_base + SIRFSOC_TIMER_INT_EN)
| (1 << SIRFSOC_TIMER_WDT_INDEX),
wdt_base + SIRFSOC_TIMER_INT_EN);
writel(1, wdt_base + SIRFSOC_TIMER_WATCHDOG_EN);
return 0;
}
static int sirfsoc_wdt_disable(struct watchdog_device *wdd)
{
void __iomem *wdt_base = watchdog_get_drvdata(wdd);
writel(0, wdt_base + SIRFSOC_TIMER_WATCHDOG_EN);
writel(readl(wdt_base + SIRFSOC_TIMER_INT_EN)
& (~(1 << SIRFSOC_TIMER_WDT_INDEX)),
wdt_base + SIRFSOC_TIMER_INT_EN);
return 0;
}
static int sirfsoc_wdt_settimeout(struct watchdog_device *wdd, unsigned int to)
{
wdd->timeout = to;
sirfsoc_wdt_updatetimeout(wdd);
return 0;
}
static int sirfsoc_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
int ret;
void __iomem *base;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
watchdog_set_drvdata(&sirfsoc_wdd, base);
watchdog_init_timeout(&sirfsoc_wdd, timeout, &pdev->dev);
watchdog_set_nowayout(&sirfsoc_wdd, nowayout);
ret = watchdog_register_device(&sirfsoc_wdd);
if (ret)
return ret;
platform_set_drvdata(pdev, &sirfsoc_wdd);
return 0;
}
static void sirfsoc_wdt_shutdown(struct platform_device *pdev)
{
struct watchdog_device *wdd = platform_get_drvdata(pdev);
sirfsoc_wdt_disable(wdd);
}
static int sirfsoc_wdt_remove(struct platform_device *pdev)
{
sirfsoc_wdt_shutdown(pdev);
return 0;
}
static int sirfsoc_wdt_suspend(struct device *dev)
{
return 0;
}
static int sirfsoc_wdt_resume(struct device *dev)
{
struct watchdog_device *wdd = dev_get_drvdata(dev);
sirfsoc_wdt_updatetimeout(wdd);
return 0;
}
