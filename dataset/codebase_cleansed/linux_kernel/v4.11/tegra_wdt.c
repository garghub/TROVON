static int tegra_wdt_start(struct watchdog_device *wdd)
{
struct tegra_wdt *wdt = watchdog_get_drvdata(wdd);
u32 val;
val = 1000000ul / 4;
val |= (TIMER_EN | TIMER_PERIODIC);
writel(val, wdt->tmr_regs + TIMER_PTV);
val = WDT_TIMER_ID |
(wdd->timeout << WDT_CFG_PERIOD_SHIFT) |
WDT_CFG_PMC2CAR_RST_EN;
writel(val, wdt->wdt_regs + WDT_CFG);
writel(WDT_CMD_START_COUNTER, wdt->wdt_regs + WDT_CMD);
return 0;
}
static int tegra_wdt_stop(struct watchdog_device *wdd)
{
struct tegra_wdt *wdt = watchdog_get_drvdata(wdd);
writel(WDT_UNLOCK_PATTERN, wdt->wdt_regs + WDT_UNLOCK);
writel(WDT_CMD_DISABLE_COUNTER, wdt->wdt_regs + WDT_CMD);
writel(0, wdt->tmr_regs + TIMER_PTV);
return 0;
}
static int tegra_wdt_ping(struct watchdog_device *wdd)
{
struct tegra_wdt *wdt = watchdog_get_drvdata(wdd);
writel(WDT_CMD_START_COUNTER, wdt->wdt_regs + WDT_CMD);
return 0;
}
static int tegra_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
wdd->timeout = timeout;
if (watchdog_active(wdd)) {
tegra_wdt_stop(wdd);
return tegra_wdt_start(wdd);
}
return 0;
}
static unsigned int tegra_wdt_get_timeleft(struct watchdog_device *wdd)
{
struct tegra_wdt *wdt = watchdog_get_drvdata(wdd);
u32 val;
int count;
int exp;
val = readl(wdt->wdt_regs + WDT_STS);
count = (val >> WDT_STS_COUNT_SHIFT) & WDT_STS_COUNT_MASK;
exp = (val >> WDT_STS_EXP_SHIFT) & WDT_STS_EXP_MASK;
return (((3 - exp) * wdd->timeout) + count) / 4;
}
static int tegra_wdt_probe(struct platform_device *pdev)
{
struct watchdog_device *wdd;
struct tegra_wdt *wdt;
struct resource *res;
void __iomem *regs;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->wdt_regs = regs + WDT_BASE;
wdt->tmr_regs = regs + WDT_TIMER_BASE;
wdd = &wdt->wdd;
wdd->timeout = heartbeat;
wdd->info = &tegra_wdt_info;
wdd->ops = &tegra_wdt_ops;
wdd->min_timeout = MIN_WDT_TIMEOUT;
wdd->max_timeout = MAX_WDT_TIMEOUT;
wdd->parent = &pdev->dev;
watchdog_set_drvdata(wdd, wdt);
watchdog_set_nowayout(wdd, nowayout);
ret = devm_watchdog_register_device(&pdev->dev, wdd);
if (ret) {
dev_err(&pdev->dev,
"failed to register watchdog device\n");
return ret;
}
platform_set_drvdata(pdev, wdt);
dev_info(&pdev->dev,
"initialized (heartbeat = %d sec, nowayout = %d)\n",
heartbeat, nowayout);
return 0;
}
static int tegra_wdt_remove(struct platform_device *pdev)
{
struct tegra_wdt *wdt = platform_get_drvdata(pdev);
tegra_wdt_stop(&wdt->wdd);
dev_info(&pdev->dev, "removed wdt\n");
return 0;
}
static int tegra_wdt_runtime_suspend(struct device *dev)
{
struct tegra_wdt *wdt = dev_get_drvdata(dev);
if (watchdog_active(&wdt->wdd))
tegra_wdt_stop(&wdt->wdd);
return 0;
}
static int tegra_wdt_runtime_resume(struct device *dev)
{
struct tegra_wdt *wdt = dev_get_drvdata(dev);
if (watchdog_active(&wdt->wdd))
tegra_wdt_start(&wdt->wdd);
return 0;
}
