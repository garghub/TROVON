static void dc_wdt_set(struct dc_wdt *wdt, u32 ticks)
{
unsigned long flags;
spin_lock_irqsave(&wdt->lock, flags);
writel_relaxed(0, wdt->base + TIMER_A_CONTROL);
writel_relaxed(ticks, wdt->base + TIMER_A_COUNT);
writel_relaxed(TIMER_A_ENABLE_COUNT | TIMER_A_ENABLE_WATCHDOG,
wdt->base + TIMER_A_CONTROL);
spin_unlock_irqrestore(&wdt->lock, flags);
}
static int dc_wdt_restart(struct watchdog_device *wdog, unsigned long action,
void *data)
{
struct dc_wdt *wdt = watchdog_get_drvdata(wdog);
dc_wdt_set(wdt, 1);
mdelay(500);
return 0;
}
static int dc_wdt_start(struct watchdog_device *wdog)
{
struct dc_wdt *wdt = watchdog_get_drvdata(wdog);
dc_wdt_set(wdt, wdog->timeout * clk_get_rate(wdt->clk));
return 0;
}
static int dc_wdt_stop(struct watchdog_device *wdog)
{
struct dc_wdt *wdt = watchdog_get_drvdata(wdog);
writel_relaxed(0, wdt->base + TIMER_A_CONTROL);
return 0;
}
static int dc_wdt_set_timeout(struct watchdog_device *wdog, unsigned int t)
{
struct dc_wdt *wdt = watchdog_get_drvdata(wdog);
dc_wdt_set(wdt, t * clk_get_rate(wdt->clk));
wdog->timeout = t;
return 0;
}
static unsigned int dc_wdt_get_timeleft(struct watchdog_device *wdog)
{
struct dc_wdt *wdt = watchdog_get_drvdata(wdog);
uint32_t count = readl_relaxed(wdt->base + TIMER_A_COUNT);
return count / clk_get_rate(wdt->clk);
}
static int dc_wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct dc_wdt *wdt;
int ret;
wdt = devm_kzalloc(dev, sizeof(struct dc_wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
platform_set_drvdata(pdev, wdt);
wdt->base = of_iomap(np, 0);
if (!wdt->base) {
dev_err(dev, "Failed to remap watchdog regs");
return -ENODEV;
}
wdt->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(wdt->clk)) {
ret = PTR_ERR(wdt->clk);
goto err_iounmap;
}
dc_wdt_wdd.max_timeout = U32_MAX / clk_get_rate(wdt->clk);
dc_wdt_wdd.timeout = dc_wdt_wdd.max_timeout;
dc_wdt_wdd.parent = &pdev->dev;
spin_lock_init(&wdt->lock);
watchdog_set_drvdata(&dc_wdt_wdd, wdt);
watchdog_set_restart_priority(&dc_wdt_wdd, 128);
watchdog_init_timeout(&dc_wdt_wdd, timeout, dev);
ret = watchdog_register_device(&dc_wdt_wdd);
if (ret) {
dev_err(dev, "Failed to register watchdog device");
goto err_iounmap;
}
return 0;
err_iounmap:
iounmap(wdt->base);
return ret;
}
static int dc_wdt_remove(struct platform_device *pdev)
{
struct dc_wdt *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&dc_wdt_wdd);
iounmap(wdt->base);
return 0;
}
static void dc_wdt_shutdown(struct platform_device *pdev)
{
dc_wdt_stop(&dc_wdt_wdd);
}
