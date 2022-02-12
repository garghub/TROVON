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
static int wdt_notify_sys(struct notifier_block *nb, unsigned long code,
void *unused)
{
switch (code) {
case SYS_DOWN:
break;
case SYS_HALT:
case SYS_POWER_OFF:
wdt_stop(&stmp3xxx_wdd);
break;
}
return NOTIFY_DONE;
}
static int stmp3xxx_wdt_probe(struct platform_device *pdev)
{
int ret;
watchdog_set_drvdata(&stmp3xxx_wdd, &pdev->dev);
stmp3xxx_wdd.timeout = clamp_t(unsigned, heartbeat, 1, STMP3XXX_MAX_TIMEOUT);
stmp3xxx_wdd.parent = &pdev->dev;
ret = watchdog_register_device(&stmp3xxx_wdd);
if (ret < 0) {
dev_err(&pdev->dev, "cannot register watchdog device\n");
return ret;
}
if (register_reboot_notifier(&wdt_notifier))
dev_warn(&pdev->dev, "cannot register reboot notifier\n");
dev_info(&pdev->dev, "initialized watchdog with heartbeat %ds\n",
stmp3xxx_wdd.timeout);
return 0;
}
static int stmp3xxx_wdt_remove(struct platform_device *pdev)
{
unregister_reboot_notifier(&wdt_notifier);
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
