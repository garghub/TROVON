static int orion_wdt_clock_init(struct platform_device *pdev,
struct orion_watchdog *dev)
{
int ret;
dev->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk))
return PTR_ERR(dev->clk);
ret = clk_prepare_enable(dev->clk);
if (ret) {
clk_put(dev->clk);
return ret;
}
dev->clk_rate = clk_get_rate(dev->clk);
return 0;
}
static int armada370_wdt_clock_init(struct platform_device *pdev,
struct orion_watchdog *dev)
{
int ret;
dev->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk))
return PTR_ERR(dev->clk);
ret = clk_prepare_enable(dev->clk);
if (ret) {
clk_put(dev->clk);
return ret;
}
atomic_io_modify(dev->reg + TIMER_CTRL,
WDT_A370_RATIO_MASK(WDT_A370_RATIO_SHIFT),
WDT_A370_RATIO_MASK(WDT_A370_RATIO_SHIFT));
dev->clk_rate = clk_get_rate(dev->clk) / WDT_A370_RATIO;
return 0;
}
static int armadaxp_wdt_clock_init(struct platform_device *pdev,
struct orion_watchdog *dev)
{
int ret;
dev->clk = of_clk_get_by_name(pdev->dev.of_node, "fixed");
if (IS_ERR(dev->clk))
return PTR_ERR(dev->clk);
ret = clk_prepare_enable(dev->clk);
if (ret) {
clk_put(dev->clk);
return ret;
}
atomic_io_modify(dev->reg + TIMER_CTRL,
WDT_AXP_FIXED_ENABLE_BIT,
WDT_AXP_FIXED_ENABLE_BIT);
dev->clk_rate = clk_get_rate(dev->clk);
return 0;
}
static int orion_wdt_ping(struct watchdog_device *wdt_dev)
{
struct orion_watchdog *dev = watchdog_get_drvdata(wdt_dev);
writel(dev->clk_rate * wdt_dev->timeout,
dev->reg + dev->data->wdt_counter_offset);
return 0;
}
static int armada370_start(struct watchdog_device *wdt_dev)
{
struct orion_watchdog *dev = watchdog_get_drvdata(wdt_dev);
writel(dev->clk_rate * wdt_dev->timeout,
dev->reg + dev->data->wdt_counter_offset);
atomic_io_modify(dev->reg + TIMER_A370_STATUS, WDT_A370_EXPIRED, 0);
atomic_io_modify(dev->reg + TIMER_CTRL, dev->data->wdt_enable_bit,
dev->data->wdt_enable_bit);
atomic_io_modify(dev->rstout, dev->data->rstout_enable_bit,
dev->data->rstout_enable_bit);
return 0;
}
static int orion_start(struct watchdog_device *wdt_dev)
{
struct orion_watchdog *dev = watchdog_get_drvdata(wdt_dev);
writel(dev->clk_rate * wdt_dev->timeout,
dev->reg + dev->data->wdt_counter_offset);
atomic_io_modify(dev->reg + TIMER_CTRL, dev->data->wdt_enable_bit,
dev->data->wdt_enable_bit);
atomic_io_modify(dev->rstout, dev->data->rstout_enable_bit,
dev->data->rstout_enable_bit);
return 0;
}
static int orion_wdt_start(struct watchdog_device *wdt_dev)
{
struct orion_watchdog *dev = watchdog_get_drvdata(wdt_dev);
return dev->data->start(wdt_dev);
}
static int orion_wdt_stop(struct watchdog_device *wdt_dev)
{
struct orion_watchdog *dev = watchdog_get_drvdata(wdt_dev);
atomic_io_modify(dev->rstout, dev->data->rstout_enable_bit, 0);
atomic_io_modify(dev->reg + TIMER_CTRL, dev->data->wdt_enable_bit, 0);
return 0;
}
static int orion_wdt_enabled(struct orion_watchdog *dev)
{
bool enabled, running;
enabled = readl(dev->rstout) & dev->data->rstout_enable_bit;
running = readl(dev->reg + TIMER_CTRL) & dev->data->wdt_enable_bit;
return enabled && running;
}
static unsigned int orion_wdt_get_timeleft(struct watchdog_device *wdt_dev)
{
struct orion_watchdog *dev = watchdog_get_drvdata(wdt_dev);
return readl(dev->reg + dev->data->wdt_counter_offset) / dev->clk_rate;
}
static int orion_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
wdt_dev->timeout = timeout;
return 0;
}
static irqreturn_t orion_wdt_irq(int irq, void *devid)
{
panic("Watchdog Timeout");
return IRQ_HANDLED;
}
static void __iomem *orion_wdt_ioremap_rstout(struct platform_device *pdev,
phys_addr_t internal_regs)
{
struct resource *res;
phys_addr_t rstout;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (res)
return devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!of_device_is_compatible(pdev->dev.of_node, "marvell,orion-wdt"))
return NULL;
rstout = internal_regs + ORION_RSTOUT_MASK_OFFSET;
WARN(1, FW_BUG "falling back to harcoded RSTOUT reg %pa\n", &rstout);
return devm_ioremap(&pdev->dev, rstout, 0x4);
}
static int orion_wdt_probe(struct platform_device *pdev)
{
struct orion_watchdog *dev;
const struct of_device_id *match;
unsigned int wdt_max_duration;
struct resource *res;
int ret, irq;
dev = devm_kzalloc(&pdev->dev, sizeof(struct orion_watchdog),
GFP_KERNEL);
if (!dev)
return -ENOMEM;
match = of_match_device(orion_wdt_of_match_table, &pdev->dev);
if (!match)
match = &orion_wdt_of_match_table[0];
dev->wdt.info = &orion_wdt_info;
dev->wdt.ops = &orion_wdt_ops;
dev->wdt.min_timeout = 1;
dev->data = match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
dev->reg = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!dev->reg)
return -ENOMEM;
dev->rstout = orion_wdt_ioremap_rstout(pdev, res->start &
INTERNAL_REGS_MASK);
if (!dev->rstout)
return -ENODEV;
ret = dev->data->clock_init(pdev, dev);
if (ret) {
dev_err(&pdev->dev, "cannot initialize clock\n");
return ret;
}
wdt_max_duration = WDT_MAX_CYCLE_COUNT / dev->clk_rate;
dev->wdt.timeout = wdt_max_duration;
dev->wdt.max_timeout = wdt_max_duration;
watchdog_init_timeout(&dev->wdt, heartbeat, &pdev->dev);
platform_set_drvdata(pdev, &dev->wdt);
watchdog_set_drvdata(&dev->wdt, dev);
if (!orion_wdt_enabled(dev))
orion_wdt_stop(&dev->wdt);
irq = platform_get_irq(pdev, 0);
if (irq > 0) {
ret = devm_request_irq(&pdev->dev, irq, orion_wdt_irq, 0,
pdev->name, dev);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request IRQ\n");
goto disable_clk;
}
}
watchdog_set_nowayout(&dev->wdt, nowayout);
ret = watchdog_register_device(&dev->wdt);
if (ret)
goto disable_clk;
pr_info("Initial timeout %d sec%s\n",
dev->wdt.timeout, nowayout ? ", nowayout" : "");
return 0;
disable_clk:
clk_disable_unprepare(dev->clk);
clk_put(dev->clk);
return ret;
}
static int orion_wdt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdt_dev = platform_get_drvdata(pdev);
struct orion_watchdog *dev = watchdog_get_drvdata(wdt_dev);
watchdog_unregister_device(wdt_dev);
clk_disable_unprepare(dev->clk);
clk_put(dev->clk);
return 0;
}
static void orion_wdt_shutdown(struct platform_device *pdev)
{
struct watchdog_device *wdt_dev = platform_get_drvdata(pdev);
orion_wdt_stop(wdt_dev);
}
