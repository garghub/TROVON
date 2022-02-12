static int da9055_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct da9055_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
struct da9055 *da9055 = driver_data->da9055;
int ret, i;
for (i = 0; i < ARRAY_SIZE(da9055_wdt_maps); i++)
if (da9055_wdt_maps[i].user_time == timeout)
break;
if (i == ARRAY_SIZE(da9055_wdt_maps))
ret = -EINVAL;
else
ret = da9055_reg_update(da9055, DA9055_REG_CONTROL_B,
DA9055_TWDSCALE_MASK,
da9055_wdt_maps[i].reg_val <<
DA9055_TWDSCALE_SHIFT);
if (ret < 0) {
dev_err(da9055->dev,
"Failed to update timescale bit, %d\n", ret);
return ret;
}
wdt_dev->timeout = timeout;
return 0;
}
static int da9055_wdt_ping(struct watchdog_device *wdt_dev)
{
struct da9055_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
struct da9055 *da9055 = driver_data->da9055;
mdelay(DA9055_TWDMIN);
return da9055_reg_update(da9055, DA9055_REG_CONTROL_E,
DA9055_WATCHDOG_MASK, 1);
}
static int da9055_wdt_start(struct watchdog_device *wdt_dev)
{
return da9055_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
}
static int da9055_wdt_stop(struct watchdog_device *wdt_dev)
{
return da9055_wdt_set_timeout(wdt_dev, 0);
}
static int da9055_wdt_probe(struct platform_device *pdev)
{
struct da9055 *da9055 = dev_get_drvdata(pdev->dev.parent);
struct da9055_wdt_data *driver_data;
struct watchdog_device *da9055_wdt;
int ret;
driver_data = devm_kzalloc(&pdev->dev, sizeof(*driver_data),
GFP_KERNEL);
if (!driver_data)
return -ENOMEM;
driver_data->da9055 = da9055;
da9055_wdt = &driver_data->wdt;
da9055_wdt->timeout = DA9055_DEF_TIMEOUT;
da9055_wdt->info = &da9055_wdt_info;
da9055_wdt->ops = &da9055_wdt_ops;
da9055_wdt->parent = &pdev->dev;
watchdog_set_nowayout(da9055_wdt, nowayout);
watchdog_set_drvdata(da9055_wdt, driver_data);
ret = da9055_wdt_stop(da9055_wdt);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to stop watchdog, %d\n", ret);
goto err;
}
platform_set_drvdata(pdev, driver_data);
ret = watchdog_register_device(&driver_data->wdt);
if (ret != 0)
dev_err(da9055->dev, "watchdog_register_device() failed: %d\n",
ret);
err:
return ret;
}
static int da9055_wdt_remove(struct platform_device *pdev)
{
struct da9055_wdt_data *driver_data = platform_get_drvdata(pdev);
watchdog_unregister_device(&driver_data->wdt);
return 0;
}
