static struct aspeed_wdt *to_aspeed_wdt(struct watchdog_device *wdd)
{
return container_of(wdd, struct aspeed_wdt, wdd);
}
static void aspeed_wdt_enable(struct aspeed_wdt *wdt, int count)
{
wdt->ctrl |= WDT_CTRL_ENABLE;
writel(0, wdt->base + WDT_CTRL);
writel(count, wdt->base + WDT_RELOAD_VALUE);
writel(WDT_RESTART_MAGIC, wdt->base + WDT_RESTART);
writel(wdt->ctrl, wdt->base + WDT_CTRL);
}
static int aspeed_wdt_start(struct watchdog_device *wdd)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
aspeed_wdt_enable(wdt, wdd->timeout * WDT_RATE_1MHZ);
return 0;
}
static int aspeed_wdt_stop(struct watchdog_device *wdd)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
wdt->ctrl &= ~WDT_CTRL_ENABLE;
writel(wdt->ctrl, wdt->base + WDT_CTRL);
return 0;
}
static int aspeed_wdt_ping(struct watchdog_device *wdd)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
writel(WDT_RESTART_MAGIC, wdt->base + WDT_RESTART);
return 0;
}
static int aspeed_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
u32 actual;
wdd->timeout = timeout;
actual = min(timeout, wdd->max_hw_heartbeat_ms * 1000);
writel(actual * WDT_RATE_1MHZ, wdt->base + WDT_RELOAD_VALUE);
writel(WDT_RESTART_MAGIC, wdt->base + WDT_RESTART);
return 0;
}
static int aspeed_wdt_restart(struct watchdog_device *wdd,
unsigned long action, void *data)
{
struct aspeed_wdt *wdt = to_aspeed_wdt(wdd);
aspeed_wdt_enable(wdt, 128 * WDT_RATE_1MHZ / 1000);
mdelay(1000);
return 0;
}
static int aspeed_wdt_remove(struct platform_device *pdev)
{
struct aspeed_wdt *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&wdt->wdd);
return 0;
}
static int aspeed_wdt_probe(struct platform_device *pdev)
{
struct aspeed_wdt *wdt;
struct resource *res;
int ret;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(wdt->base))
return PTR_ERR(wdt->base);
wdt->wdd.info = &aspeed_wdt_info;
wdt->wdd.ops = &aspeed_wdt_ops;
wdt->wdd.max_hw_heartbeat_ms = WDT_MAX_TIMEOUT_MS;
wdt->wdd.parent = &pdev->dev;
wdt->wdd.timeout = WDT_DEFAULT_TIMEOUT;
watchdog_init_timeout(&wdt->wdd, 0, &pdev->dev);
wdt->ctrl = WDT_CTRL_RESET_MODE_SOC |
WDT_CTRL_1MHZ_CLK |
WDT_CTRL_RESET_SYSTEM;
if (readl(wdt->base + WDT_CTRL) & WDT_CTRL_ENABLE) {
aspeed_wdt_start(&wdt->wdd);
set_bit(WDOG_HW_RUNNING, &wdt->wdd.status);
}
ret = watchdog_register_device(&wdt->wdd);
if (ret) {
dev_err(&pdev->dev, "failed to register\n");
return ret;
}
platform_set_drvdata(pdev, wdt);
return 0;
}
