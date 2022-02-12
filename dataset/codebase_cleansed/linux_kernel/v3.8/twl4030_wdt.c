static int twl4030_wdt_write(unsigned char val)
{
return twl_i2c_write_u8(TWL_MODULE_PM_RECEIVER, val,
TWL4030_WATCHDOG_CFG_REG_OFFS);
}
static int twl4030_wdt_start(struct watchdog_device *wdt)
{
return twl4030_wdt_write(wdt->timeout + 1);
}
static int twl4030_wdt_stop(struct watchdog_device *wdt)
{
return twl4030_wdt_write(0);
}
static int twl4030_wdt_set_timeout(struct watchdog_device *wdt,
unsigned int timeout)
{
wdt->timeout = timeout;
return 0;
}
static int twl4030_wdt_probe(struct platform_device *pdev)
{
int ret = 0;
struct watchdog_device *wdt;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->info = &twl4030_wdt_info;
wdt->ops = &twl4030_wdt_ops;
wdt->status = 0;
wdt->timeout = 30;
wdt->min_timeout = 1;
wdt->max_timeout = 30;
watchdog_set_nowayout(wdt, nowayout);
platform_set_drvdata(pdev, wdt);
twl4030_wdt_stop(wdt);
ret = watchdog_register_device(wdt);
if (ret) {
platform_set_drvdata(pdev, NULL);
return ret;
}
return 0;
}
static int twl4030_wdt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(wdt);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int twl4030_wdt_suspend(struct platform_device *pdev, pm_message_t state)
{
struct watchdog_device *wdt = platform_get_drvdata(pdev);
if (watchdog_active(wdt))
return twl4030_wdt_stop(wdt);
return 0;
}
static int twl4030_wdt_resume(struct platform_device *pdev)
{
struct watchdog_device *wdt = platform_get_drvdata(pdev);
if (watchdog_active(wdt))
return twl4030_wdt_start(wdt);
return 0;
}
