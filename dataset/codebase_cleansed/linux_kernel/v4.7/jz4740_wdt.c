static int jz4740_wdt_ping(struct watchdog_device *wdt_dev)
{
struct jz4740_wdt_drvdata *drvdata = watchdog_get_drvdata(wdt_dev);
writew(0x0, drvdata->base + JZ_REG_WDT_TIMER_COUNTER);
return 0;
}
static int jz4740_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int new_timeout)
{
struct jz4740_wdt_drvdata *drvdata = watchdog_get_drvdata(wdt_dev);
unsigned int rtc_clk_rate;
unsigned int timeout_value;
unsigned short clock_div = JZ_WDT_CLOCK_DIV_1;
rtc_clk_rate = clk_get_rate(drvdata->rtc_clk);
timeout_value = rtc_clk_rate * new_timeout;
while (timeout_value > 0xffff) {
if (clock_div == JZ_WDT_CLOCK_DIV_1024) {
timeout_value = 0xffff;
break;
}
timeout_value >>= 2;
clock_div += (1 << JZ_WDT_CLOCK_DIV_SHIFT);
}
writeb(0x0, drvdata->base + JZ_REG_WDT_COUNTER_ENABLE);
writew(clock_div, drvdata->base + JZ_REG_WDT_TIMER_CONTROL);
writew((u16)timeout_value, drvdata->base + JZ_REG_WDT_TIMER_DATA);
writew(0x0, drvdata->base + JZ_REG_WDT_TIMER_COUNTER);
writew(clock_div | JZ_WDT_CLOCK_RTC,
drvdata->base + JZ_REG_WDT_TIMER_CONTROL);
writeb(0x1, drvdata->base + JZ_REG_WDT_COUNTER_ENABLE);
wdt_dev->timeout = new_timeout;
return 0;
}
static int jz4740_wdt_start(struct watchdog_device *wdt_dev)
{
jz4740_timer_enable_watchdog();
jz4740_wdt_set_timeout(wdt_dev, wdt_dev->timeout);
return 0;
}
static int jz4740_wdt_stop(struct watchdog_device *wdt_dev)
{
struct jz4740_wdt_drvdata *drvdata = watchdog_get_drvdata(wdt_dev);
jz4740_timer_disable_watchdog();
writeb(0x0, drvdata->base + JZ_REG_WDT_COUNTER_ENABLE);
return 0;
}
static int jz4740_wdt_probe(struct platform_device *pdev)
{
struct jz4740_wdt_drvdata *drvdata;
struct watchdog_device *jz4740_wdt;
struct resource *res;
int ret;
drvdata = devm_kzalloc(&pdev->dev, sizeof(struct jz4740_wdt_drvdata),
GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
if (heartbeat < 1 || heartbeat > MAX_HEARTBEAT)
heartbeat = DEFAULT_HEARTBEAT;
jz4740_wdt = &drvdata->wdt;
jz4740_wdt->info = &jz4740_wdt_info;
jz4740_wdt->ops = &jz4740_wdt_ops;
jz4740_wdt->timeout = heartbeat;
jz4740_wdt->min_timeout = 1;
jz4740_wdt->max_timeout = MAX_HEARTBEAT;
jz4740_wdt->parent = &pdev->dev;
watchdog_set_nowayout(jz4740_wdt, nowayout);
watchdog_set_drvdata(jz4740_wdt, drvdata);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
drvdata->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(drvdata->base)) {
ret = PTR_ERR(drvdata->base);
goto err_out;
}
drvdata->rtc_clk = clk_get(&pdev->dev, "rtc");
if (IS_ERR(drvdata->rtc_clk)) {
dev_err(&pdev->dev, "cannot find RTC clock\n");
ret = PTR_ERR(drvdata->rtc_clk);
goto err_out;
}
ret = watchdog_register_device(&drvdata->wdt);
if (ret < 0)
goto err_disable_clk;
platform_set_drvdata(pdev, drvdata);
return 0;
err_disable_clk:
clk_put(drvdata->rtc_clk);
err_out:
return ret;
}
static int jz4740_wdt_remove(struct platform_device *pdev)
{
struct jz4740_wdt_drvdata *drvdata = platform_get_drvdata(pdev);
jz4740_wdt_stop(&drvdata->wdt);
watchdog_unregister_device(&drvdata->wdt);
clk_put(drvdata->rtc_clk);
return 0;
}
