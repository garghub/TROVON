static inline
struct qcom_wdt *to_qcom_wdt(struct watchdog_device *wdd)
{
return container_of(wdd, struct qcom_wdt, wdd);
}
static int qcom_wdt_start(struct watchdog_device *wdd)
{
struct qcom_wdt *wdt = to_qcom_wdt(wdd);
writel(0, wdt->base + WDT_EN);
writel(1, wdt->base + WDT_RST);
writel(wdd->timeout * wdt->rate, wdt->base + WDT_BITE_TIME);
writel(1, wdt->base + WDT_EN);
return 0;
}
static int qcom_wdt_stop(struct watchdog_device *wdd)
{
struct qcom_wdt *wdt = to_qcom_wdt(wdd);
writel(0, wdt->base + WDT_EN);
return 0;
}
static int qcom_wdt_ping(struct watchdog_device *wdd)
{
struct qcom_wdt *wdt = to_qcom_wdt(wdd);
writel(1, wdt->base + WDT_RST);
return 0;
}
static int qcom_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
wdd->timeout = timeout;
return qcom_wdt_start(wdd);
}
static int qcom_wdt_restart(struct watchdog_device *wdd)
{
struct qcom_wdt *wdt = to_qcom_wdt(wdd);
u32 timeout;
timeout = 128 * wdt->rate / 1000;
writel(0, wdt->base + WDT_EN);
writel(1, wdt->base + WDT_RST);
writel(timeout, wdt->base + WDT_BITE_TIME);
writel(1, wdt->base + WDT_EN);
wmb();
msleep(150);
return 0;
}
static int qcom_wdt_probe(struct platform_device *pdev)
{
struct qcom_wdt *wdt;
struct resource *res;
struct device_node *np = pdev->dev.of_node;
u32 percpu_offset;
int ret;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (of_property_read_u32(np, "cpu-offset", &percpu_offset))
percpu_offset = 0;
res->start += percpu_offset;
res->end += percpu_offset;
wdt->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(wdt->base))
return PTR_ERR(wdt->base);
wdt->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(wdt->clk)) {
dev_err(&pdev->dev, "failed to get input clock\n");
return PTR_ERR(wdt->clk);
}
ret = clk_prepare_enable(wdt->clk);
if (ret) {
dev_err(&pdev->dev, "failed to setup clock\n");
return ret;
}
wdt->rate = clk_get_rate(wdt->clk);
if (wdt->rate == 0 ||
wdt->rate > 0x10000000U) {
dev_err(&pdev->dev, "invalid clock rate\n");
ret = -EINVAL;
goto err_clk_unprepare;
}
wdt->wdd.info = &qcom_wdt_info;
wdt->wdd.ops = &qcom_wdt_ops;
wdt->wdd.min_timeout = 1;
wdt->wdd.max_timeout = 0x10000000U / wdt->rate;
wdt->wdd.parent = &pdev->dev;
wdt->wdd.timeout = min(wdt->wdd.max_timeout, 30U);
watchdog_init_timeout(&wdt->wdd, 0, &pdev->dev);
ret = watchdog_register_device(&wdt->wdd);
if (ret) {
dev_err(&pdev->dev, "failed to register watchdog\n");
goto err_clk_unprepare;
}
platform_set_drvdata(pdev, wdt);
return 0;
err_clk_unprepare:
clk_disable_unprepare(wdt->clk);
return ret;
}
static int qcom_wdt_remove(struct platform_device *pdev)
{
struct qcom_wdt *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&wdt->wdd);
clk_disable_unprepare(wdt->clk);
return 0;
}
