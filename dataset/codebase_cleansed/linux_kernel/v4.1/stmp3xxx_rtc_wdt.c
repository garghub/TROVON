static int wdt_start(struct watchdog_device *wdd)
{
struct device *dev = watchdog_get_drvdata(wdd);
struct stmp3xxx_wdt_pdata *pdata = dev_get_platdata(dev);
pdata->wdt_set_timeout(dev->parent, wdd->timeout * WDOG_TICK_RATE);
return 0;
}
static int wdt_stop(struct watchdog_device *wdd)
{
struct device *dev = watchdog_get_drvdata(wdd);
struct stmp3xxx_wdt_pdata *pdata = dev_get_platdata(dev);
pdata->wdt_set_timeout(dev->parent, 0);
return 0;
}
static int wdt_set_timeout(struct watchdog_device *wdd, unsigned new_timeout)
{
wdd->timeout = new_timeout;
return wdt_start(wdd);
}
static int stmp3xxx_wdt_probe(struct platform_device *pdev)
{
int ret;
watchdog_set_drvdata(&stmp3xxx_wdd, &pdev->dev);
stmp3xxx_wdd.timeout = clamp_t(unsigned, heartbeat, 1, STMP3XXX_MAX_TIMEOUT);
ret = watchdog_register_device(&stmp3xxx_wdd);
if (ret < 0) {
dev_err(&pdev->dev, "cannot register watchdog device\n");
return ret;
}
dev_info(&pdev->dev, "initialized watchdog with heartbeat %ds\n",
stmp3xxx_wdd.timeout);
return 0;
}
static int stmp3xxx_wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&stmp3xxx_wdd);
return 0;
}
static int __maybe_unused stmp3xxx_wdt_suspend(struct device *dev)
{
struct watchdog_device *wdd = &stmp3xxx_wdd;
if (watchdog_active(wdd))
return wdt_stop(wdd);
return 0;
}
static int __maybe_unused stmp3xxx_wdt_resume(struct device *dev)
{
struct watchdog_device *wdd = &stmp3xxx_wdd;
if (watchdog_active(wdd))
return wdt_start(wdd);
return 0;
}
