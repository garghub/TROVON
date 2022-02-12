static int wm831x_wdt_start(struct watchdog_device *wdt_dev)
{
struct wm831x_wdt_drvdata *driver_data = watchdog_get_drvdata(wdt_dev);
struct wm831x *wm831x = driver_data->wm831x;
int ret;
mutex_lock(&driver_data->lock);
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_set_bits(wm831x, WM831X_WATCHDOG,
WM831X_WDOG_ENA, WM831X_WDOG_ENA);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev, "Failed to unlock security key: %d\n",
ret);
}
mutex_unlock(&driver_data->lock);
return ret;
}
static int wm831x_wdt_stop(struct watchdog_device *wdt_dev)
{
struct wm831x_wdt_drvdata *driver_data = watchdog_get_drvdata(wdt_dev);
struct wm831x *wm831x = driver_data->wm831x;
int ret;
mutex_lock(&driver_data->lock);
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_set_bits(wm831x, WM831X_WATCHDOG,
WM831X_WDOG_ENA, 0);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev, "Failed to unlock security key: %d\n",
ret);
}
mutex_unlock(&driver_data->lock);
return ret;
}
static int wm831x_wdt_ping(struct watchdog_device *wdt_dev)
{
struct wm831x_wdt_drvdata *driver_data = watchdog_get_drvdata(wdt_dev);
struct wm831x *wm831x = driver_data->wm831x;
int ret;
u16 reg;
mutex_lock(&driver_data->lock);
if (driver_data->update_gpio) {
gpio_set_value_cansleep(driver_data->update_gpio,
driver_data->update_state);
driver_data->update_state = !driver_data->update_state;
ret = 0;
goto out;
}
reg = wm831x_reg_read(wm831x, WM831X_WATCHDOG);
if (!(reg & WM831X_WDOG_RST_SRC)) {
dev_err(wm831x->dev, "Hardware watchdog update unsupported\n");
ret = -EINVAL;
goto out;
}
reg |= WM831X_WDOG_RESET;
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_reg_write(wm831x, WM831X_WATCHDOG, reg);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev, "Failed to unlock security key: %d\n",
ret);
}
out:
mutex_unlock(&driver_data->lock);
return ret;
}
static int wm831x_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct wm831x_wdt_drvdata *driver_data = watchdog_get_drvdata(wdt_dev);
struct wm831x *wm831x = driver_data->wm831x;
int ret, i;
for (i = 0; i < ARRAY_SIZE(wm831x_wdt_cfgs); i++)
if (wm831x_wdt_cfgs[i].time == timeout)
break;
if (i == ARRAY_SIZE(wm831x_wdt_cfgs))
return -EINVAL;
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_set_bits(wm831x, WM831X_WATCHDOG,
WM831X_WDOG_TO_MASK,
wm831x_wdt_cfgs[i].val);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev, "Failed to unlock security key: %d\n",
ret);
}
return ret;
}
static int __devinit wm831x_wdt_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct wm831x_pdata *chip_pdata;
struct wm831x_watchdog_pdata *pdata;
struct wm831x_wdt_drvdata *driver_data;
struct watchdog_device *wm831x_wdt;
int reg, ret, i;
ret = wm831x_reg_read(wm831x, WM831X_WATCHDOG);
if (ret < 0) {
dev_err(wm831x->dev, "Failed to read watchdog status: %d\n",
ret);
goto err;
}
reg = ret;
if (reg & WM831X_WDOG_DEBUG)
dev_warn(wm831x->dev, "Watchdog is paused\n");
driver_data = kzalloc(sizeof(*driver_data), GFP_KERNEL);
if (!driver_data) {
dev_err(wm831x->dev, "Unable to alloacate watchdog device\n");
ret = -ENOMEM;
goto err;
}
mutex_init(&driver_data->lock);
driver_data->wm831x = wm831x;
wm831x_wdt = &driver_data->wdt;
wm831x_wdt->info = &wm831x_wdt_info;
wm831x_wdt->ops = &wm831x_wdt_ops;
watchdog_set_drvdata(wm831x_wdt, driver_data);
if (nowayout)
wm831x_wdt->status |= WDOG_NO_WAY_OUT;
reg = wm831x_reg_read(wm831x, WM831X_WATCHDOG);
reg &= WM831X_WDOG_TO_MASK;
for (i = 0; i < ARRAY_SIZE(wm831x_wdt_cfgs); i++)
if (wm831x_wdt_cfgs[i].val == reg)
break;
if (i == ARRAY_SIZE(wm831x_wdt_cfgs))
dev_warn(wm831x->dev,
"Unknown watchdog timeout: %x\n", reg);
else
wm831x_wdt->timeout = wm831x_wdt_cfgs[i].time;
if (pdev->dev.parent->platform_data) {
chip_pdata = pdev->dev.parent->platform_data;
pdata = chip_pdata->watchdog;
} else {
pdata = NULL;
}
if (pdata) {
reg &= ~(WM831X_WDOG_SECACT_MASK | WM831X_WDOG_PRIMACT_MASK |
WM831X_WDOG_RST_SRC);
reg |= pdata->primary << WM831X_WDOG_PRIMACT_SHIFT;
reg |= pdata->secondary << WM831X_WDOG_SECACT_SHIFT;
reg |= pdata->software << WM831X_WDOG_RST_SRC_SHIFT;
if (pdata->update_gpio) {
ret = gpio_request(pdata->update_gpio,
"Watchdog update");
if (ret < 0) {
dev_err(wm831x->dev,
"Failed to request update GPIO: %d\n",
ret);
goto err_alloc;
}
ret = gpio_direction_output(pdata->update_gpio, 0);
if (ret != 0) {
dev_err(wm831x->dev,
"gpio_direction_output returned: %d\n",
ret);
goto err_gpio;
}
driver_data->update_gpio = pdata->update_gpio;
reg |= WM831X_WDOG_RST_SRC;
}
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_reg_write(wm831x, WM831X_WATCHDOG, reg);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev,
"Failed to unlock security key: %d\n", ret);
goto err_gpio;
}
}
ret = watchdog_register_device(&driver_data->wdt);
if (ret != 0) {
dev_err(wm831x->dev, "watchdog_register_device() failed: %d\n",
ret);
goto err_gpio;
}
dev_set_drvdata(&pdev->dev, driver_data);
return 0;
err_gpio:
if (driver_data->update_gpio)
gpio_free(driver_data->update_gpio);
err_alloc:
kfree(driver_data);
err:
return ret;
}
static int __devexit wm831x_wdt_remove(struct platform_device *pdev)
{
struct wm831x_wdt_drvdata *driver_data = dev_get_drvdata(&pdev->dev);
watchdog_unregister_device(&driver_data->wdt);
if (driver_data->update_gpio)
gpio_free(driver_data->update_gpio);
return 0;
}
static int __init wm831x_wdt_init(void)
{
return platform_driver_register(&wm831x_wdt_driver);
}
static void __exit wm831x_wdt_exit(void)
{
platform_driver_unregister(&wm831x_wdt_driver);
}
