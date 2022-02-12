static int rn5t618_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int t)
{
struct rn5t618_wdt *wdt = watchdog_get_drvdata(wdt_dev);
int ret, i;
for (i = 0; i < ARRAY_SIZE(rn5t618_wdt_map); i++) {
if (rn5t618_wdt_map[i].time + 1 >= t)
break;
}
if (i == ARRAY_SIZE(rn5t618_wdt_map))
return -EINVAL;
ret = regmap_update_bits(wdt->rn5t618->regmap, RN5T618_WATCHDOG,
RN5T618_WATCHDOG_WDOGTIM_M,
rn5t618_wdt_map[i].reg_val);
if (!ret)
wdt_dev->timeout = rn5t618_wdt_map[i].time;
return ret;
}
static int rn5t618_wdt_start(struct watchdog_device *wdt_dev)
{
struct rn5t618_wdt *wdt = watchdog_get_drvdata(wdt_dev);
int ret;
ret = rn5t618_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
if (ret)
return ret;
ret = regmap_update_bits(wdt->rn5t618->regmap, RN5T618_REPCNT,
RN5T618_REPCNT_REPWRON,
RN5T618_REPCNT_REPWRON);
if (ret)
return ret;
ret = regmap_update_bits(wdt->rn5t618->regmap, RN5T618_WATCHDOG,
RN5T618_WATCHDOG_WDOGEN,
RN5T618_WATCHDOG_WDOGEN);
if (ret)
return ret;
return regmap_update_bits(wdt->rn5t618->regmap, RN5T618_PWRIREN,
RN5T618_PWRIRQ_IR_WDOG,
RN5T618_PWRIRQ_IR_WDOG);
}
static int rn5t618_wdt_stop(struct watchdog_device *wdt_dev)
{
struct rn5t618_wdt *wdt = watchdog_get_drvdata(wdt_dev);
return regmap_update_bits(wdt->rn5t618->regmap, RN5T618_WATCHDOG,
RN5T618_WATCHDOG_WDOGEN, 0);
}
static int rn5t618_wdt_ping(struct watchdog_device *wdt_dev)
{
struct rn5t618_wdt *wdt = watchdog_get_drvdata(wdt_dev);
unsigned int val;
int ret;
ret = regmap_read(wdt->rn5t618->regmap, RN5T618_WATCHDOG, &val);
if (ret)
return ret;
ret = regmap_write(wdt->rn5t618->regmap, RN5T618_WATCHDOG, val);
if (ret)
return ret;
return regmap_update_bits(wdt->rn5t618->regmap, RN5T618_PWRIRQ,
RN5T618_PWRIRQ_IR_WDOG, 0);
}
static int rn5t618_wdt_probe(struct platform_device *pdev)
{
struct rn5t618 *rn5t618 = dev_get_drvdata(pdev->dev.parent);
struct rn5t618_wdt *wdt;
int min_timeout, max_timeout;
wdt = devm_kzalloc(&pdev->dev, sizeof(struct rn5t618_wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
min_timeout = rn5t618_wdt_map[0].time;
max_timeout = rn5t618_wdt_map[ARRAY_SIZE(rn5t618_wdt_map) - 1].time;
wdt->rn5t618 = rn5t618;
wdt->wdt_dev.info = &rn5t618_wdt_info;
wdt->wdt_dev.ops = &rn5t618_wdt_ops;
wdt->wdt_dev.min_timeout = min_timeout;
wdt->wdt_dev.max_timeout = max_timeout;
wdt->wdt_dev.timeout = max_timeout;
wdt->wdt_dev.parent = &pdev->dev;
watchdog_set_drvdata(&wdt->wdt_dev, wdt);
watchdog_init_timeout(&wdt->wdt_dev, timeout, &pdev->dev);
watchdog_set_nowayout(&wdt->wdt_dev, nowayout);
platform_set_drvdata(pdev, wdt);
return watchdog_register_device(&wdt->wdt_dev);
}
static int rn5t618_wdt_remove(struct platform_device *pdev)
{
struct rn5t618_wdt *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&wdt->wdt_dev);
return 0;
}
