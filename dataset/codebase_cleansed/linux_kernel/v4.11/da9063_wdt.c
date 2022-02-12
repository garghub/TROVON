static unsigned int da9063_wdt_timeout_to_sel(unsigned int secs)
{
unsigned int i;
for (i = DA9063_TWDSCALE_MIN; i <= DA9063_TWDSCALE_MAX; i++) {
if (wdt_timeout[i] >= secs)
return i;
}
return DA9063_TWDSCALE_MAX;
}
static int _da9063_wdt_set_timeout(struct da9063 *da9063, unsigned int regval)
{
return regmap_update_bits(da9063->regmap, DA9063_REG_CONTROL_D,
DA9063_TWDSCALE_MASK, regval);
}
static int da9063_wdt_start(struct watchdog_device *wdd)
{
struct da9063_watchdog *wdt = watchdog_get_drvdata(wdd);
unsigned int selector;
int ret;
selector = da9063_wdt_timeout_to_sel(wdt->wdtdev.timeout);
ret = _da9063_wdt_set_timeout(wdt->da9063, selector);
if (ret)
dev_err(wdt->da9063->dev, "Watchdog failed to start (err = %d)\n",
ret);
return ret;
}
static int da9063_wdt_stop(struct watchdog_device *wdd)
{
struct da9063_watchdog *wdt = watchdog_get_drvdata(wdd);
int ret;
ret = regmap_update_bits(wdt->da9063->regmap, DA9063_REG_CONTROL_D,
DA9063_TWDSCALE_MASK, DA9063_TWDSCALE_DISABLE);
if (ret)
dev_alert(wdt->da9063->dev, "Watchdog failed to stop (err = %d)\n",
ret);
return ret;
}
static int da9063_wdt_ping(struct watchdog_device *wdd)
{
struct da9063_watchdog *wdt = watchdog_get_drvdata(wdd);
int ret;
ret = regmap_write(wdt->da9063->regmap, DA9063_REG_CONTROL_F,
DA9063_WATCHDOG);
if (ret)
dev_alert(wdt->da9063->dev, "Failed to ping the watchdog (err = %d)\n",
ret);
return ret;
}
static int da9063_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct da9063_watchdog *wdt = watchdog_get_drvdata(wdd);
unsigned int selector;
int ret;
selector = da9063_wdt_timeout_to_sel(timeout);
ret = _da9063_wdt_set_timeout(wdt->da9063, selector);
if (ret)
dev_err(wdt->da9063->dev, "Failed to set watchdog timeout (err = %d)\n",
ret);
else
wdd->timeout = wdt_timeout[selector];
return ret;
}
static int da9063_wdt_restart(struct watchdog_device *wdd, unsigned long action,
void *data)
{
struct da9063_watchdog *wdt = watchdog_get_drvdata(wdd);
int ret;
ret = regmap_write(wdt->da9063->regmap, DA9063_REG_CONTROL_F,
DA9063_SHUTDOWN);
if (ret)
dev_alert(wdt->da9063->dev, "Failed to shutdown (err = %d)\n",
ret);
return ret;
}
static int da9063_wdt_probe(struct platform_device *pdev)
{
struct da9063 *da9063;
struct da9063_watchdog *wdt;
if (!pdev->dev.parent)
return -EINVAL;
da9063 = dev_get_drvdata(pdev->dev.parent);
if (!da9063)
return -EINVAL;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->da9063 = da9063;
wdt->wdtdev.info = &da9063_watchdog_info;
wdt->wdtdev.ops = &da9063_watchdog_ops;
wdt->wdtdev.min_timeout = DA9063_WDT_MIN_TIMEOUT;
wdt->wdtdev.max_timeout = DA9063_WDT_MAX_TIMEOUT;
wdt->wdtdev.min_hw_heartbeat_ms = DA9063_RESET_PROTECTION_MS;
wdt->wdtdev.timeout = DA9063_WDG_TIMEOUT;
wdt->wdtdev.parent = &pdev->dev;
wdt->wdtdev.status = WATCHDOG_NOWAYOUT_INIT_STATUS;
watchdog_set_restart_priority(&wdt->wdtdev, 128);
watchdog_set_drvdata(&wdt->wdtdev, wdt);
return devm_watchdog_register_device(&pdev->dev, &wdt->wdtdev);
}
