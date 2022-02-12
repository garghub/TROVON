static void da9052_wdt_release_resources(struct kref *r)
{
}
static int da9052_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct da9052_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
struct da9052 *da9052 = driver_data->da9052;
int ret, i;
ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
DA9052_CONTROLD_TWDSCALE, 0);
if (ret < 0) {
dev_err(da9052->dev, "Failed to disable watchdog bit, %d\n",
ret);
return ret;
}
if (timeout) {
udelay(150);
for (i = 0; i < ARRAY_SIZE(da9052_wdt_maps); i++)
if (da9052_wdt_maps[i].time == timeout)
break;
if (i == ARRAY_SIZE(da9052_wdt_maps))
ret = -EINVAL;
else
ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
DA9052_CONTROLD_TWDSCALE,
da9052_wdt_maps[i].reg_val);
if (ret < 0) {
dev_err(da9052->dev,
"Failed to update timescale bit, %d\n", ret);
return ret;
}
wdt_dev->timeout = timeout;
driver_data->jpast = jiffies;
}
return 0;
}
static void da9052_wdt_ref(struct watchdog_device *wdt_dev)
{
struct da9052_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
kref_get(&driver_data->kref);
}
static void da9052_wdt_unref(struct watchdog_device *wdt_dev)
{
struct da9052_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
kref_put(&driver_data->kref, da9052_wdt_release_resources);
}
static int da9052_wdt_start(struct watchdog_device *wdt_dev)
{
return da9052_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
}
static int da9052_wdt_stop(struct watchdog_device *wdt_dev)
{
return da9052_wdt_set_timeout(wdt_dev, 0);
}
static int da9052_wdt_ping(struct watchdog_device *wdt_dev)
{
struct da9052_wdt_data *driver_data = watchdog_get_drvdata(wdt_dev);
struct da9052 *da9052 = driver_data->da9052;
unsigned long msec, jnow = jiffies;
int ret;
msec = (jnow - driver_data->jpast) * 1000/HZ;
if (msec < DA9052_TWDMIN)
mdelay(msec);
ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
DA9052_CONTROLD_WATCHDOG, 1 << 7);
if (ret < 0)
goto err_strobe;
ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
DA9052_CONTROLD_WATCHDOG, 0 << 7);
err_strobe:
return ret;
}
static int da9052_wdt_probe(struct platform_device *pdev)
{
struct da9052 *da9052 = dev_get_drvdata(pdev->dev.parent);
struct da9052_wdt_data *driver_data;
struct watchdog_device *da9052_wdt;
int ret;
driver_data = devm_kzalloc(&pdev->dev, sizeof(*driver_data),
GFP_KERNEL);
if (!driver_data) {
dev_err(da9052->dev, "Unable to alloacate watchdog device\n");
ret = -ENOMEM;
goto err;
}
driver_data->da9052 = da9052;
da9052_wdt = &driver_data->wdt;
da9052_wdt->timeout = DA9052_DEF_TIMEOUT;
da9052_wdt->info = &da9052_wdt_info;
da9052_wdt->ops = &da9052_wdt_ops;
watchdog_set_drvdata(da9052_wdt, driver_data);
kref_init(&driver_data->kref);
ret = da9052_reg_update(da9052, DA9052_CONTROL_D_REG,
DA9052_CONTROLD_TWDSCALE, 0);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to disable watchdog bits, %d\n",
ret);
goto err;
}
ret = watchdog_register_device(&driver_data->wdt);
if (ret != 0) {
dev_err(da9052->dev, "watchdog_register_device() failed: %d\n",
ret);
goto err;
}
platform_set_drvdata(pdev, driver_data);
err:
return ret;
}
static int da9052_wdt_remove(struct platform_device *pdev)
{
struct da9052_wdt_data *driver_data = platform_get_drvdata(pdev);
watchdog_unregister_device(&driver_data->wdt);
kref_put(&driver_data->kref, da9052_wdt_release_resources);
return 0;
}
