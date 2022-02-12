static int tangox_wdt_set_timeout(struct watchdog_device *wdt,
unsigned int new_timeout)
{
wdt->timeout = new_timeout;
return 0;
}
static int tangox_wdt_start(struct watchdog_device *wdt)
{
struct tangox_wdt_device *dev = watchdog_get_drvdata(wdt);
u32 ticks;
ticks = 1 + wdt->timeout * dev->clk_rate;
writel(ticks, dev->base + WD_COUNTER);
return 0;
}
static int tangox_wdt_stop(struct watchdog_device *wdt)
{
struct tangox_wdt_device *dev = watchdog_get_drvdata(wdt);
writel(0, dev->base + WD_COUNTER);
return 0;
}
static unsigned int tangox_wdt_get_timeleft(struct watchdog_device *wdt)
{
struct tangox_wdt_device *dev = watchdog_get_drvdata(wdt);
u32 count;
count = readl(dev->base + WD_COUNTER);
if (!count)
return 0;
return (count - 1) / dev->clk_rate;
}
static int tangox_wdt_restart(struct notifier_block *nb, unsigned long action,
void *data)
{
struct tangox_wdt_device *dev =
container_of(nb, struct tangox_wdt_device, restart);
writel(1, dev->base + WD_COUNTER);
return NOTIFY_DONE;
}
static int tangox_wdt_probe(struct platform_device *pdev)
{
struct tangox_wdt_device *dev;
struct resource *res;
u32 config;
int err;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dev->base))
return PTR_ERR(dev->base);
dev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk))
return PTR_ERR(dev->clk);
err = clk_prepare_enable(dev->clk);
if (err)
return err;
dev->clk_rate = clk_get_rate(dev->clk);
if (!dev->clk_rate) {
err = -EINVAL;
goto err;
}
dev->wdt.parent = &pdev->dev;
dev->wdt.info = &tangox_wdt_info;
dev->wdt.ops = &tangox_wdt_ops;
dev->wdt.timeout = DEFAULT_TIMEOUT;
dev->wdt.min_timeout = 1;
dev->wdt.max_timeout = (U32_MAX - 1) / dev->clk_rate;
watchdog_init_timeout(&dev->wdt, timeout, &pdev->dev);
watchdog_set_nowayout(&dev->wdt, nowayout);
watchdog_set_drvdata(&dev->wdt, dev);
config = readl(dev->base + WD_CONFIG);
if (config & WD_CONFIG_DISABLE)
writel(0, dev->base + WD_COUNTER);
writel(WD_CONFIG_XTAL_IN, dev->base + WD_CONFIG);
if (readl(dev->base + WD_COUNTER)) {
set_bit(WDOG_ACTIVE, &dev->wdt.status);
tangox_wdt_start(&dev->wdt);
}
err = watchdog_register_device(&dev->wdt);
if (err)
goto err;
platform_set_drvdata(pdev, dev);
dev->restart.notifier_call = tangox_wdt_restart;
dev->restart.priority = 128;
err = register_restart_handler(&dev->restart);
if (err)
dev_warn(&pdev->dev, "failed to register restart handler\n");
dev_info(&pdev->dev, "SMP86xx/SMP87xx watchdog registered\n");
return 0;
err:
clk_disable_unprepare(dev->clk);
return err;
}
static int tangox_wdt_remove(struct platform_device *pdev)
{
struct tangox_wdt_device *dev = platform_get_drvdata(pdev);
tangox_wdt_stop(&dev->wdt);
clk_disable_unprepare(dev->clk);
unregister_restart_handler(&dev->restart);
watchdog_unregister_device(&dev->wdt);
return 0;
}
