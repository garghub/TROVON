static int orion_wdt_ping(struct watchdog_device *wdt_dev)
{
spin_lock(&wdt_lock);
writel(wdt_tclk * wdt_dev->timeout, wdt_reg + WDT_VAL);
spin_unlock(&wdt_lock);
return 0;
}
static int orion_wdt_start(struct watchdog_device *wdt_dev)
{
u32 reg;
spin_lock(&wdt_lock);
writel(wdt_tclk * wdt_dev->timeout, wdt_reg + WDT_VAL);
reg = readl(BRIDGE_CAUSE);
reg &= ~WDT_INT_REQ;
writel(reg, BRIDGE_CAUSE);
reg = readl(wdt_reg + TIMER_CTRL);
reg |= WDT_EN;
writel(reg, wdt_reg + TIMER_CTRL);
reg = readl(RSTOUTn_MASK);
reg |= WDT_RESET_OUT_EN;
writel(reg, RSTOUTn_MASK);
spin_unlock(&wdt_lock);
return 0;
}
static int orion_wdt_stop(struct watchdog_device *wdt_dev)
{
u32 reg;
spin_lock(&wdt_lock);
reg = readl(RSTOUTn_MASK);
reg &= ~WDT_RESET_OUT_EN;
writel(reg, RSTOUTn_MASK);
reg = readl(wdt_reg + TIMER_CTRL);
reg &= ~WDT_EN;
writel(reg, wdt_reg + TIMER_CTRL);
spin_unlock(&wdt_lock);
return 0;
}
static unsigned int orion_wdt_get_timeleft(struct watchdog_device *wdt_dev)
{
unsigned int time_left;
spin_lock(&wdt_lock);
time_left = readl(wdt_reg + WDT_VAL) / wdt_tclk;
spin_unlock(&wdt_lock);
return time_left;
}
static int orion_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
wdt_dev->timeout = timeout;
return 0;
}
static int orion_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
int ret;
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Orion Watchdog missing clock\n");
return -ENODEV;
}
clk_prepare_enable(clk);
wdt_tclk = clk_get_rate(clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
wdt_reg = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!wdt_reg)
return -ENOMEM;
wdt_max_duration = WDT_MAX_CYCLE_COUNT / wdt_tclk;
orion_wdt.timeout = wdt_max_duration;
orion_wdt.max_timeout = wdt_max_duration;
watchdog_init_timeout(&orion_wdt, heartbeat, &pdev->dev);
watchdog_set_nowayout(&orion_wdt, nowayout);
ret = watchdog_register_device(&orion_wdt);
if (ret) {
clk_disable_unprepare(clk);
return ret;
}
pr_info("Initial timeout %d sec%s\n",
orion_wdt.timeout, nowayout ? ", nowayout" : "");
return 0;
}
static int orion_wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&orion_wdt);
clk_disable_unprepare(clk);
return 0;
}
static void orion_wdt_shutdown(struct platform_device *pdev)
{
orion_wdt_stop(&orion_wdt);
}
