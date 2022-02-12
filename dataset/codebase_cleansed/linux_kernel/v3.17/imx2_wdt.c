static inline void imx2_wdt_setup(struct watchdog_device *wdog)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
u32 val;
regmap_read(wdev->regmap, IMX2_WDT_WCR, &val);
val |= IMX2_WDT_WCR_WDZST;
val &= ~IMX2_WDT_WCR_WT;
val &= ~IMX2_WDT_WCR_WRE;
val &= ~IMX2_WDT_WCR_WDE;
val |= WDOG_SEC_TO_COUNT(wdog->timeout);
regmap_write(wdev->regmap, IMX2_WDT_WCR, val);
val |= IMX2_WDT_WCR_WDE;
regmap_write(wdev->regmap, IMX2_WDT_WCR, val);
}
static inline bool imx2_wdt_is_running(struct imx2_wdt_device *wdev)
{
u32 val;
regmap_read(wdev->regmap, IMX2_WDT_WCR, &val);
return val & IMX2_WDT_WCR_WDE;
}
static int imx2_wdt_ping(struct watchdog_device *wdog)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
regmap_write(wdev->regmap, IMX2_WDT_WSR, IMX2_WDT_SEQ1);
regmap_write(wdev->regmap, IMX2_WDT_WSR, IMX2_WDT_SEQ2);
return 0;
}
static void imx2_wdt_timer_ping(unsigned long arg)
{
struct watchdog_device *wdog = (struct watchdog_device *)arg;
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
imx2_wdt_ping(wdog);
mod_timer(&wdev->timer, jiffies + wdog->timeout * HZ / 2);
}
static int imx2_wdt_set_timeout(struct watchdog_device *wdog,
unsigned int new_timeout)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
regmap_update_bits(wdev->regmap, IMX2_WDT_WCR, IMX2_WDT_WCR_WT,
WDOG_SEC_TO_COUNT(new_timeout));
return 0;
}
static int imx2_wdt_start(struct watchdog_device *wdog)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
if (imx2_wdt_is_running(wdev)) {
del_timer_sync(&wdev->timer);
imx2_wdt_set_timeout(wdog, wdog->timeout);
} else
imx2_wdt_setup(wdog);
return imx2_wdt_ping(wdog);
}
static int imx2_wdt_stop(struct watchdog_device *wdog)
{
imx2_wdt_timer_ping((unsigned long)wdog);
return 0;
}
static inline void imx2_wdt_ping_if_active(struct watchdog_device *wdog)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
if (imx2_wdt_is_running(wdev)) {
imx2_wdt_set_timeout(wdog, wdog->timeout);
imx2_wdt_timer_ping((unsigned long)wdog);
}
}
static int __init imx2_wdt_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct imx2_wdt_device *wdev;
struct watchdog_device *wdog;
struct resource *res;
void __iomem *base;
bool big_endian;
int ret;
u32 val;
wdev = devm_kzalloc(&pdev->dev, sizeof(*wdev), GFP_KERNEL);
if (!wdev)
return -ENOMEM;
big_endian = of_property_read_bool(np, "big-endian");
if (big_endian)
imx2_wdt_regmap_config.val_format_endian = REGMAP_ENDIAN_BIG;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
wdev->regmap = devm_regmap_init_mmio_clk(&pdev->dev, NULL, base,
&imx2_wdt_regmap_config);
if (IS_ERR(wdev->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
return PTR_ERR(wdev->regmap);
}
wdev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(wdev->clk)) {
dev_err(&pdev->dev, "can't get Watchdog clock\n");
return PTR_ERR(wdev->clk);
}
wdog = &wdev->wdog;
wdog->info = &imx2_wdt_info;
wdog->ops = &imx2_wdt_ops;
wdog->min_timeout = 1;
wdog->max_timeout = IMX2_WDT_MAX_TIME;
clk_prepare_enable(wdev->clk);
regmap_read(wdev->regmap, IMX2_WDT_WRSR, &val);
wdog->bootstatus = val & IMX2_WDT_WRSR_TOUT ? WDIOF_CARDRESET : 0;
wdog->timeout = clamp_t(unsigned, timeout, 1, IMX2_WDT_MAX_TIME);
if (wdog->timeout != timeout)
dev_warn(&pdev->dev, "Initial timeout out of range! Clamped from %u to %u\n",
timeout, wdog->timeout);
platform_set_drvdata(pdev, wdog);
watchdog_set_drvdata(wdog, wdev);
watchdog_set_nowayout(wdog, nowayout);
watchdog_init_timeout(wdog, timeout, &pdev->dev);
setup_timer(&wdev->timer, imx2_wdt_timer_ping, (unsigned long)wdog);
imx2_wdt_ping_if_active(wdog);
ret = watchdog_register_device(wdog);
if (ret) {
dev_err(&pdev->dev, "cannot register watchdog device\n");
return ret;
}
dev_info(&pdev->dev, "timeout %d sec (nowayout=%d)\n",
wdog->timeout, nowayout);
return 0;
}
static int __exit imx2_wdt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdog = platform_get_drvdata(pdev);
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
watchdog_unregister_device(wdog);
if (imx2_wdt_is_running(wdev)) {
del_timer_sync(&wdev->timer);
imx2_wdt_ping(wdog);
dev_crit(&pdev->dev, "Device removed: Expect reboot!\n");
}
return 0;
}
static void imx2_wdt_shutdown(struct platform_device *pdev)
{
struct watchdog_device *wdog = platform_get_drvdata(pdev);
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
if (imx2_wdt_is_running(wdev)) {
del_timer_sync(&wdev->timer);
imx2_wdt_set_timeout(wdog, IMX2_WDT_MAX_TIME);
imx2_wdt_ping(wdog);
dev_crit(&pdev->dev, "Device shutdown: Expect reboot!\n");
}
}
