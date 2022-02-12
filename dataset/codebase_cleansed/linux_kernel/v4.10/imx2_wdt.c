static int imx2_wdt_restart(struct watchdog_device *wdog, unsigned long action,
void *data)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
unsigned int wcr_enable = IMX2_WDT_WCR_WDE;
if (wdev->ext_reset)
wcr_enable |= IMX2_WDT_WCR_SRS;
else
wcr_enable |= IMX2_WDT_WCR_WDA;
regmap_write(wdev->regmap, IMX2_WDT_WCR, wcr_enable);
regmap_write(wdev->regmap, IMX2_WDT_WCR, wcr_enable);
regmap_write(wdev->regmap, IMX2_WDT_WCR, wcr_enable);
mdelay(500);
return 0;
}
static inline void imx2_wdt_setup(struct watchdog_device *wdog)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
u32 val;
regmap_read(wdev->regmap, IMX2_WDT_WCR, &val);
val |= IMX2_WDT_WCR_WDZST;
val &= ~IMX2_WDT_WCR_WT;
if (!wdev->ext_reset)
val &= ~IMX2_WDT_WCR_WRE;
else
val |= IMX2_WDT_WCR_WRE;
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
static int imx2_wdt_set_timeout(struct watchdog_device *wdog,
unsigned int new_timeout)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
wdog->timeout = new_timeout;
regmap_update_bits(wdev->regmap, IMX2_WDT_WCR, IMX2_WDT_WCR_WT,
WDOG_SEC_TO_COUNT(new_timeout));
return 0;
}
static int imx2_wdt_set_pretimeout(struct watchdog_device *wdog,
unsigned int new_pretimeout)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
if (new_pretimeout >= IMX2_WDT_MAX_TIME)
return -EINVAL;
wdog->pretimeout = new_pretimeout;
regmap_update_bits(wdev->regmap, IMX2_WDT_WICR,
IMX2_WDT_WICR_WIE | IMX2_WDT_WICR_WICT,
IMX2_WDT_WICR_WIE | (new_pretimeout << 1));
return 0;
}
static irqreturn_t imx2_wdt_isr(int irq, void *wdog_arg)
{
struct watchdog_device *wdog = wdog_arg;
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
regmap_write_bits(wdev->regmap, IMX2_WDT_WICR,
IMX2_WDT_WICR_WTIS, IMX2_WDT_WICR_WTIS);
watchdog_notify_pretimeout(wdog);
return IRQ_HANDLED;
}
static int imx2_wdt_start(struct watchdog_device *wdog)
{
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
if (imx2_wdt_is_running(wdev))
imx2_wdt_set_timeout(wdog, wdog->timeout);
else
imx2_wdt_setup(wdog);
set_bit(WDOG_HW_RUNNING, &wdog->status);
return imx2_wdt_ping(wdog);
}
static int __init imx2_wdt_probe(struct platform_device *pdev)
{
struct imx2_wdt_device *wdev;
struct watchdog_device *wdog;
struct resource *res;
void __iomem *base;
int ret;
u32 val;
wdev = devm_kzalloc(&pdev->dev, sizeof(*wdev), GFP_KERNEL);
if (!wdev)
return -ENOMEM;
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
wdog->max_hw_heartbeat_ms = IMX2_WDT_MAX_TIME * 1000;
wdog->parent = &pdev->dev;
ret = platform_get_irq(pdev, 0);
if (ret > 0)
if (!devm_request_irq(&pdev->dev, ret, imx2_wdt_isr, 0,
dev_name(&pdev->dev), wdog))
wdog->info = &imx2_wdt_pretimeout_info;
ret = clk_prepare_enable(wdev->clk);
if (ret)
return ret;
regmap_read(wdev->regmap, IMX2_WDT_WRSR, &val);
wdog->bootstatus = val & IMX2_WDT_WRSR_TOUT ? WDIOF_CARDRESET : 0;
wdev->ext_reset = of_property_read_bool(pdev->dev.of_node,
"fsl,ext-reset-output");
wdog->timeout = clamp_t(unsigned, timeout, 1, IMX2_WDT_MAX_TIME);
if (wdog->timeout != timeout)
dev_warn(&pdev->dev, "Initial timeout out of range! Clamped from %u to %u\n",
timeout, wdog->timeout);
platform_set_drvdata(pdev, wdog);
watchdog_set_drvdata(wdog, wdev);
watchdog_set_nowayout(wdog, nowayout);
watchdog_set_restart_priority(wdog, 128);
watchdog_init_timeout(wdog, timeout, &pdev->dev);
if (imx2_wdt_is_running(wdev)) {
imx2_wdt_set_timeout(wdog, wdog->timeout);
set_bit(WDOG_HW_RUNNING, &wdog->status);
}
regmap_write(wdev->regmap, IMX2_WDT_WMCR, 0);
ret = watchdog_register_device(wdog);
if (ret) {
dev_err(&pdev->dev, "cannot register watchdog device\n");
goto disable_clk;
}
dev_info(&pdev->dev, "timeout %d sec (nowayout=%d)\n",
wdog->timeout, nowayout);
return 0;
disable_clk:
clk_disable_unprepare(wdev->clk);
return ret;
}
static int __exit imx2_wdt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdog = platform_get_drvdata(pdev);
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
watchdog_unregister_device(wdog);
if (imx2_wdt_is_running(wdev)) {
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
imx2_wdt_set_timeout(wdog, IMX2_WDT_MAX_TIME);
imx2_wdt_ping(wdog);
dev_crit(&pdev->dev, "Device shutdown: Expect reboot!\n");
}
}
static int imx2_wdt_suspend(struct device *dev)
{
struct watchdog_device *wdog = dev_get_drvdata(dev);
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
if (imx2_wdt_is_running(wdev)) {
imx2_wdt_set_timeout(wdog, IMX2_WDT_MAX_TIME);
imx2_wdt_ping(wdog);
}
clk_disable_unprepare(wdev->clk);
return 0;
}
static int imx2_wdt_resume(struct device *dev)
{
struct watchdog_device *wdog = dev_get_drvdata(dev);
struct imx2_wdt_device *wdev = watchdog_get_drvdata(wdog);
int ret;
ret = clk_prepare_enable(wdev->clk);
if (ret)
return ret;
if (watchdog_active(wdog) && !imx2_wdt_is_running(wdev)) {
imx2_wdt_setup(wdog);
}
if (imx2_wdt_is_running(wdev)) {
imx2_wdt_set_timeout(wdog, wdog->timeout);
imx2_wdt_ping(wdog);
}
return 0;
}
