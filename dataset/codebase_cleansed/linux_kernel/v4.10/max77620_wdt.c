static int max77620_wdt_start(struct watchdog_device *wdt_dev)
{
struct max77620_wdt *wdt = watchdog_get_drvdata(wdt_dev);
return regmap_update_bits(wdt->rmap, MAX77620_REG_CNFGGLBL2,
MAX77620_WDTEN, MAX77620_WDTEN);
}
static int max77620_wdt_stop(struct watchdog_device *wdt_dev)
{
struct max77620_wdt *wdt = watchdog_get_drvdata(wdt_dev);
return regmap_update_bits(wdt->rmap, MAX77620_REG_CNFGGLBL2,
MAX77620_WDTEN, 0);
}
static int max77620_wdt_ping(struct watchdog_device *wdt_dev)
{
struct max77620_wdt *wdt = watchdog_get_drvdata(wdt_dev);
return regmap_update_bits(wdt->rmap, MAX77620_REG_CNFGGLBL3,
MAX77620_WDTC_MASK, 0x1);
}
static int max77620_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct max77620_wdt *wdt = watchdog_get_drvdata(wdt_dev);
unsigned int wdt_timeout;
u8 regval;
int ret;
switch (timeout) {
case 0 ... 2:
regval = MAX77620_TWD_2s;
wdt_timeout = 2;
break;
case 3 ... 16:
regval = MAX77620_TWD_16s;
wdt_timeout = 16;
break;
case 17 ... 64:
regval = MAX77620_TWD_64s;
wdt_timeout = 64;
break;
default:
regval = MAX77620_TWD_128s;
wdt_timeout = 128;
break;
}
ret = regmap_update_bits(wdt->rmap, MAX77620_REG_CNFGGLBL3,
MAX77620_WDTC_MASK, 0x1);
if (ret < 0)
return ret;
ret = regmap_update_bits(wdt->rmap, MAX77620_REG_CNFGGLBL2,
MAX77620_TWD_MASK, regval);
if (ret < 0)
return ret;
wdt_dev->timeout = wdt_timeout;
return 0;
}
static int max77620_wdt_probe(struct platform_device *pdev)
{
struct max77620_wdt *wdt;
struct watchdog_device *wdt_dev;
unsigned int regval;
int ret;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->dev = &pdev->dev;
wdt->rmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!wdt->rmap) {
dev_err(wdt->dev, "Failed to get parent regmap\n");
return -ENODEV;
}
wdt_dev = &wdt->wdt_dev;
wdt_dev->info = &max77620_wdt_info;
wdt_dev->ops = &max77620_wdt_ops;
wdt_dev->min_timeout = 2;
wdt_dev->max_timeout = 128;
wdt_dev->max_hw_heartbeat_ms = 128 * 1000;
platform_set_drvdata(pdev, wdt);
ret = regmap_update_bits(wdt->rmap, MAX77620_REG_ONOFFCNFG2,
MAX77620_ONOFFCNFG2_WD_RST_WK,
MAX77620_ONOFFCNFG2_WD_RST_WK);
if (ret < 0) {
dev_err(wdt->dev, "Failed to set WD_RST_WK: %d\n", ret);
return ret;
}
ret = regmap_update_bits(wdt->rmap, MAX77620_REG_CNFGGLBL2,
MAX77620_WDTOFFC | MAX77620_WDTSLPC,
MAX77620_WDTOFFC | MAX77620_WDTSLPC);
if (ret < 0) {
dev_err(wdt->dev, "Failed to set WDT OFF mode: %d\n", ret);
return ret;
}
ret = regmap_read(wdt->rmap, MAX77620_REG_CNFGGLBL2, &regval);
if (ret < 0) {
dev_err(wdt->dev, "Failed to read WDT CFG register: %d\n", ret);
return ret;
}
switch (regval & MAX77620_TWD_MASK) {
case MAX77620_TWD_2s:
wdt_dev->timeout = 2;
break;
case MAX77620_TWD_16s:
wdt_dev->timeout = 16;
break;
case MAX77620_TWD_64s:
wdt_dev->timeout = 64;
break;
default:
wdt_dev->timeout = 128;
break;
}
if (regval & MAX77620_WDTEN)
set_bit(WDOG_HW_RUNNING, &wdt_dev->status);
watchdog_set_nowayout(wdt_dev, nowayout);
watchdog_set_drvdata(wdt_dev, wdt);
ret = watchdog_register_device(wdt_dev);
if (ret < 0) {
dev_err(&pdev->dev, "watchdog registration failed: %d\n", ret);
return ret;
}
return 0;
}
static int max77620_wdt_remove(struct platform_device *pdev)
{
struct max77620_wdt *wdt = platform_get_drvdata(pdev);
max77620_wdt_stop(&wdt->wdt_dev);
watchdog_unregister_device(&wdt->wdt_dev);
return 0;
}
