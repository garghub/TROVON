static int moxart_wdt_restart(struct watchdog_device *wdt_dev,
unsigned long action, void *data)
{
struct moxart_wdt_dev *moxart_wdt = watchdog_get_drvdata(wdt_dev);
writel(1, moxart_wdt->base + REG_COUNT);
writel(0x5ab9, moxart_wdt->base + REG_MODE);
writel(0x03, moxart_wdt->base + REG_ENABLE);
return 0;
}
static int moxart_wdt_stop(struct watchdog_device *wdt_dev)
{
struct moxart_wdt_dev *moxart_wdt = watchdog_get_drvdata(wdt_dev);
writel(0, moxart_wdt->base + REG_ENABLE);
return 0;
}
static int moxart_wdt_start(struct watchdog_device *wdt_dev)
{
struct moxart_wdt_dev *moxart_wdt = watchdog_get_drvdata(wdt_dev);
writel(moxart_wdt->clock_frequency * wdt_dev->timeout,
moxart_wdt->base + REG_COUNT);
writel(0x5ab9, moxart_wdt->base + REG_MODE);
writel(0x03, moxart_wdt->base + REG_ENABLE);
return 0;
}
static int moxart_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
wdt_dev->timeout = timeout;
return 0;
}
static int moxart_wdt_probe(struct platform_device *pdev)
{
struct moxart_wdt_dev *moxart_wdt;
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct resource *res;
struct clk *clk;
int err;
unsigned int max_timeout;
bool nowayout = WATCHDOG_NOWAYOUT;
moxart_wdt = devm_kzalloc(dev, sizeof(*moxart_wdt), GFP_KERNEL);
if (!moxart_wdt)
return -ENOMEM;
platform_set_drvdata(pdev, moxart_wdt);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
moxart_wdt->base = devm_ioremap_resource(dev, res);
if (IS_ERR(moxart_wdt->base))
return PTR_ERR(moxart_wdt->base);
clk = of_clk_get(node, 0);
if (IS_ERR(clk)) {
pr_err("%s: of_clk_get failed\n", __func__);
return PTR_ERR(clk);
}
moxart_wdt->clock_frequency = clk_get_rate(clk);
if (moxart_wdt->clock_frequency == 0) {
pr_err("%s: incorrect clock frequency\n", __func__);
return -EINVAL;
}
max_timeout = UINT_MAX / moxart_wdt->clock_frequency;
moxart_wdt->dev.info = &moxart_wdt_info;
moxart_wdt->dev.ops = &moxart_wdt_ops;
moxart_wdt->dev.timeout = max_timeout;
moxart_wdt->dev.min_timeout = 1;
moxart_wdt->dev.max_timeout = max_timeout;
moxart_wdt->dev.parent = dev;
watchdog_init_timeout(&moxart_wdt->dev, heartbeat, dev);
watchdog_set_nowayout(&moxart_wdt->dev, nowayout);
watchdog_set_restart_priority(&moxart_wdt->dev, 128);
watchdog_set_drvdata(&moxart_wdt->dev, moxart_wdt);
err = watchdog_register_device(&moxart_wdt->dev);
if (err)
return err;
dev_dbg(dev, "Watchdog enabled (heartbeat=%d sec, nowayout=%d)\n",
moxart_wdt->dev.timeout, nowayout);
return 0;
}
static int moxart_wdt_remove(struct platform_device *pdev)
{
struct moxart_wdt_dev *moxart_wdt = platform_get_drvdata(pdev);
moxart_wdt_stop(&moxart_wdt->dev);
return 0;
}
