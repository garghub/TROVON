static int wm8350_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
int ret, i;
u16 reg;
for (i = 0; i < ARRAY_SIZE(wm8350_wdt_cfgs); i++)
if (wm8350_wdt_cfgs[i].time == timeout)
break;
if (i == ARRAY_SIZE(wm8350_wdt_cfgs))
return -EINVAL;
mutex_lock(&wdt_mutex);
wm8350_reg_unlock(wm8350);
reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
reg &= ~WM8350_WDOG_TO_MASK;
reg |= wm8350_wdt_cfgs[i].val;
ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);
wm8350_reg_lock(wm8350);
mutex_unlock(&wdt_mutex);
wdt_dev->timeout = timeout;
return ret;
}
static int wm8350_wdt_start(struct watchdog_device *wdt_dev)
{
struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
int ret;
u16 reg;
mutex_lock(&wdt_mutex);
wm8350_reg_unlock(wm8350);
reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
reg &= ~WM8350_WDOG_MODE_MASK;
reg |= 0x20;
ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);
wm8350_reg_lock(wm8350);
mutex_unlock(&wdt_mutex);
return ret;
}
static int wm8350_wdt_stop(struct watchdog_device *wdt_dev)
{
struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
int ret;
u16 reg;
mutex_lock(&wdt_mutex);
wm8350_reg_unlock(wm8350);
reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
reg &= ~WM8350_WDOG_MODE_MASK;
ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);
wm8350_reg_lock(wm8350);
mutex_unlock(&wdt_mutex);
return ret;
}
static int wm8350_wdt_ping(struct watchdog_device *wdt_dev)
{
struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
int ret;
u16 reg;
mutex_lock(&wdt_mutex);
reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);
mutex_unlock(&wdt_mutex);
return ret;
}
static int __devinit wm8350_wdt_probe(struct platform_device *pdev)
{
struct wm8350 *wm8350 = platform_get_drvdata(pdev);
if (!wm8350) {
pr_err("No driver data supplied\n");
return -ENODEV;
}
watchdog_set_nowayout(&wm8350_wdt, nowayout);
watchdog_set_drvdata(&wm8350_wdt, wm8350);
wm8350_wdt_set_timeout(&wm8350_wdt, 4);
return watchdog_register_device(&wm8350_wdt);
}
static int __devexit wm8350_wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&wm8350_wdt);
return 0;
}
