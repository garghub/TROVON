static int ux500_wdt_start(struct watchdog_device *wdd)
{
return prcmu_enable_a9wdog(PRCMU_WDOG_ALL);
}
static int ux500_wdt_stop(struct watchdog_device *wdd)
{
return prcmu_disable_a9wdog(PRCMU_WDOG_ALL);
}
static int ux500_wdt_keepalive(struct watchdog_device *wdd)
{
return prcmu_kick_a9wdog(PRCMU_WDOG_ALL);
}
static int ux500_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
ux500_wdt_stop(wdd);
prcmu_load_a9wdog(PRCMU_WDOG_ALL, timeout * 1000);
ux500_wdt_start(wdd);
return 0;
}
static int ux500_wdt_probe(struct platform_device *pdev)
{
int ret;
struct ux500_wdt_data *pdata = dev_get_platdata(&pdev->dev);
if (pdata) {
if (pdata->timeout > 0)
timeout = pdata->timeout;
if (pdata->has_28_bits_resolution)
ux500_wdt.max_timeout = WATCHDOG_MAX28;
}
ux500_wdt.parent = &pdev->dev;
watchdog_set_nowayout(&ux500_wdt, nowayout);
prcmu_config_a9wdog(PRCMU_WDOG_CPU1, false);
prcmu_load_a9wdog(PRCMU_WDOG_ALL, timeout * 1000);
ret = watchdog_register_device(&ux500_wdt);
if (ret)
return ret;
dev_info(&pdev->dev, "initialized\n");
return 0;
}
static int ux500_wdt_remove(struct platform_device *dev)
{
watchdog_unregister_device(&ux500_wdt);
return 0;
}
static int ux500_wdt_suspend(struct platform_device *pdev,
pm_message_t state)
{
if (watchdog_active(&ux500_wdt)) {
ux500_wdt_stop(&ux500_wdt);
prcmu_config_a9wdog(PRCMU_WDOG_CPU1, true);
prcmu_load_a9wdog(PRCMU_WDOG_ALL, timeout * 1000);
ux500_wdt_start(&ux500_wdt);
}
return 0;
}
static int ux500_wdt_resume(struct platform_device *pdev)
{
if (watchdog_active(&ux500_wdt)) {
ux500_wdt_stop(&ux500_wdt);
prcmu_config_a9wdog(PRCMU_WDOG_CPU1, false);
prcmu_load_a9wdog(PRCMU_WDOG_ALL, timeout * 1000);
ux500_wdt_start(&ux500_wdt);
}
return 0;
}
