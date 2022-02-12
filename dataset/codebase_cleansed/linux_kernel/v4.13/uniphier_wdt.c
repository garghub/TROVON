static int uniphier_watchdog_ping(struct watchdog_device *w)
{
struct uniphier_wdt_dev *wdev = watchdog_get_drvdata(w);
unsigned int val;
int ret;
ret = regmap_write_bits(wdev->regmap, WDTCTRL,
WDTCTRL_CLEAR, WDTCTRL_CLEAR);
if (!ret)
ret = regmap_read_poll_timeout(wdev->regmap, WDTCTRL, val,
(val & WDTCTRL_STATUS),
0, WDTST_TIMEOUT);
return ret;
}
static int __uniphier_watchdog_start(struct regmap *regmap, unsigned int sec)
{
unsigned int val;
int ret;
ret = regmap_read_poll_timeout(regmap, WDTCTRL, val,
!(val & WDTCTRL_STATUS),
0, WDTST_TIMEOUT);
if (ret)
return ret;
ret = regmap_write(regmap, WDTTIMSET,
SEC_TO_WDTTIMSET_PRD(sec));
if (ret)
return ret;
ret = regmap_write(regmap, WDTCTRL, WDTCTRL_ENABLE | WDTCTRL_CLEAR);
if (!ret)
ret = regmap_read_poll_timeout(regmap, WDTCTRL, val,
(val & WDTCTRL_STATUS),
0, WDTST_TIMEOUT);
return ret;
}
static int __uniphier_watchdog_stop(struct regmap *regmap)
{
return regmap_write_bits(regmap, WDTCTRL, WDTCTRL_ENABLE, 0);
}
static int __uniphier_watchdog_restart(struct regmap *regmap, unsigned int sec)
{
int ret;
ret = __uniphier_watchdog_stop(regmap);
if (ret)
return ret;
return __uniphier_watchdog_start(regmap, sec);
}
static int uniphier_watchdog_start(struct watchdog_device *w)
{
struct uniphier_wdt_dev *wdev = watchdog_get_drvdata(w);
unsigned int tmp_timeout;
tmp_timeout = roundup_pow_of_two(w->timeout);
return __uniphier_watchdog_start(wdev->regmap, tmp_timeout);
}
static int uniphier_watchdog_stop(struct watchdog_device *w)
{
struct uniphier_wdt_dev *wdev = watchdog_get_drvdata(w);
return __uniphier_watchdog_stop(wdev->regmap);
}
static int uniphier_watchdog_set_timeout(struct watchdog_device *w,
unsigned int t)
{
struct uniphier_wdt_dev *wdev = watchdog_get_drvdata(w);
unsigned int tmp_timeout;
int ret;
tmp_timeout = roundup_pow_of_two(t);
if (tmp_timeout == w->timeout)
return 0;
if (watchdog_active(w)) {
ret = __uniphier_watchdog_restart(wdev->regmap, tmp_timeout);
if (ret)
return ret;
}
w->timeout = tmp_timeout;
return 0;
}
static int uniphier_wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct uniphier_wdt_dev *wdev;
struct regmap *regmap;
struct device_node *parent;
int ret;
wdev = devm_kzalloc(dev, sizeof(*wdev), GFP_KERNEL);
if (!wdev)
return -ENOMEM;
platform_set_drvdata(pdev, wdev);
parent = of_get_parent(dev->of_node);
regmap = syscon_node_to_regmap(parent);
of_node_put(parent);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
wdev->regmap = regmap;
wdev->wdt_dev.info = &uniphier_wdt_info;
wdev->wdt_dev.ops = &uniphier_wdt_ops;
wdev->wdt_dev.max_timeout = WDT_PERIOD_MAX;
wdev->wdt_dev.min_timeout = WDT_PERIOD_MIN;
wdev->wdt_dev.parent = dev;
if (watchdog_init_timeout(&wdev->wdt_dev, timeout, dev) < 0) {
wdev->wdt_dev.timeout = WDT_DEFAULT_TIMEOUT;
}
watchdog_set_nowayout(&wdev->wdt_dev, nowayout);
watchdog_stop_on_reboot(&wdev->wdt_dev);
watchdog_set_drvdata(&wdev->wdt_dev, wdev);
uniphier_watchdog_stop(&wdev->wdt_dev);
ret = regmap_write(wdev->regmap, WDTRSTSEL, WDTRSTSEL_RSTSEL_BOTH);
if (ret)
return ret;
ret = devm_watchdog_register_device(dev, &wdev->wdt_dev);
if (ret)
return ret;
dev_info(dev, "watchdog driver (timeout=%d sec, nowayout=%d)\n",
wdev->wdt_dev.timeout, nowayout);
return 0;
}
