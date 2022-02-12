static int meson_gxbb_wdt_start(struct watchdog_device *wdt_dev)
{
struct meson_gxbb_wdt *data = watchdog_get_drvdata(wdt_dev);
writel(readl(data->reg_base + GXBB_WDT_CTRL_REG) | GXBB_WDT_CTRL_EN,
data->reg_base + GXBB_WDT_CTRL_REG);
return 0;
}
static int meson_gxbb_wdt_stop(struct watchdog_device *wdt_dev)
{
struct meson_gxbb_wdt *data = watchdog_get_drvdata(wdt_dev);
writel(readl(data->reg_base + GXBB_WDT_CTRL_REG) & ~GXBB_WDT_CTRL_EN,
data->reg_base + GXBB_WDT_CTRL_REG);
return 0;
}
static int meson_gxbb_wdt_ping(struct watchdog_device *wdt_dev)
{
struct meson_gxbb_wdt *data = watchdog_get_drvdata(wdt_dev);
writel(0, data->reg_base + GXBB_WDT_RSET_REG);
return 0;
}
static int meson_gxbb_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct meson_gxbb_wdt *data = watchdog_get_drvdata(wdt_dev);
unsigned long tcnt = timeout * 1000;
if (tcnt > GXBB_WDT_TCNT_SETUP_MASK)
tcnt = GXBB_WDT_TCNT_SETUP_MASK;
wdt_dev->timeout = timeout;
meson_gxbb_wdt_ping(wdt_dev);
writel(tcnt, data->reg_base + GXBB_WDT_TCNT_REG);
return 0;
}
static unsigned int meson_gxbb_wdt_get_timeleft(struct watchdog_device *wdt_dev)
{
struct meson_gxbb_wdt *data = watchdog_get_drvdata(wdt_dev);
unsigned long reg;
reg = readl(data->reg_base + GXBB_WDT_TCNT_REG);
return ((reg >> GXBB_WDT_TCNT_CNT_SHIFT) -
(reg & GXBB_WDT_TCNT_SETUP_MASK)) / 1000;
}
static int __maybe_unused meson_gxbb_wdt_resume(struct device *dev)
{
struct meson_gxbb_wdt *data = dev_get_drvdata(dev);
if (watchdog_active(&data->wdt_dev))
meson_gxbb_wdt_start(&data->wdt_dev);
return 0;
}
static int __maybe_unused meson_gxbb_wdt_suspend(struct device *dev)
{
struct meson_gxbb_wdt *data = dev_get_drvdata(dev);
if (watchdog_active(&data->wdt_dev))
meson_gxbb_wdt_stop(&data->wdt_dev);
return 0;
}
static int meson_gxbb_wdt_probe(struct platform_device *pdev)
{
struct meson_gxbb_wdt *data;
struct resource *res;
int ret;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->reg_base))
return PTR_ERR(data->reg_base);
data->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(data->clk))
return PTR_ERR(data->clk);
clk_prepare_enable(data->clk);
platform_set_drvdata(pdev, data);
data->wdt_dev.parent = &pdev->dev;
data->wdt_dev.info = &meson_gxbb_wdt_info;
data->wdt_dev.ops = &meson_gxbb_wdt_ops;
data->wdt_dev.max_hw_heartbeat_ms = GXBB_WDT_TCNT_SETUP_MASK;
data->wdt_dev.min_timeout = 1;
data->wdt_dev.timeout = DEFAULT_TIMEOUT;
watchdog_set_drvdata(&data->wdt_dev, data);
writel(((clk_get_rate(data->clk) / 1000) & GXBB_WDT_CTRL_DIV_MASK) |
GXBB_WDT_CTRL_EE_RESET |
GXBB_WDT_CTRL_CLK_EN |
GXBB_WDT_CTRL_CLKDIV_EN,
data->reg_base + GXBB_WDT_CTRL_REG);
meson_gxbb_wdt_set_timeout(&data->wdt_dev, data->wdt_dev.timeout);
ret = watchdog_register_device(&data->wdt_dev);
if (ret) {
clk_disable_unprepare(data->clk);
return ret;
}
return 0;
}
static int meson_gxbb_wdt_remove(struct platform_device *pdev)
{
struct meson_gxbb_wdt *data = platform_get_drvdata(pdev);
watchdog_unregister_device(&data->wdt_dev);
clk_disable_unprepare(data->clk);
return 0;
}
static void meson_gxbb_wdt_shutdown(struct platform_device *pdev)
{
struct meson_gxbb_wdt *data = platform_get_drvdata(pdev);
meson_gxbb_wdt_stop(&data->wdt_dev);
}
