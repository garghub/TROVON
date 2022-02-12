static inline void cdns_wdt_writereg(struct cdns_wdt *wdt, u32 offset, u32 val)
{
writel_relaxed(val, wdt->regs + offset);
}
static int cdns_wdt_stop(struct watchdog_device *wdd)
{
struct cdns_wdt *wdt = watchdog_get_drvdata(wdd);
spin_lock(&wdt->io_lock);
cdns_wdt_writereg(wdt, CDNS_WDT_ZMR_OFFSET,
CDNS_WDT_ZMR_ZKEY_VAL & (~CDNS_WDT_ZMR_WDEN_MASK));
spin_unlock(&wdt->io_lock);
return 0;
}
static int cdns_wdt_reload(struct watchdog_device *wdd)
{
struct cdns_wdt *wdt = watchdog_get_drvdata(wdd);
spin_lock(&wdt->io_lock);
cdns_wdt_writereg(wdt, CDNS_WDT_RESTART_OFFSET,
CDNS_WDT_RESTART_KEY);
spin_unlock(&wdt->io_lock);
return 0;
}
static int cdns_wdt_start(struct watchdog_device *wdd)
{
struct cdns_wdt *wdt = watchdog_get_drvdata(wdd);
unsigned int data = 0;
unsigned short count;
unsigned long clock_f = clk_get_rate(wdt->clk);
count = (wdd->timeout * (clock_f / wdt->prescaler)) /
CDNS_WDT_COUNTER_VALUE_DIVISOR + 1;
if (count > CDNS_WDT_COUNTER_MAX)
count = CDNS_WDT_COUNTER_MAX;
spin_lock(&wdt->io_lock);
cdns_wdt_writereg(wdt, CDNS_WDT_ZMR_OFFSET,
CDNS_WDT_ZMR_ZKEY_VAL);
count = (count << 2) & CDNS_WDT_CCR_CRV_MASK;
data = count | CDNS_WDT_REGISTER_ACCESS_KEY | wdt->ctrl_clksel;
cdns_wdt_writereg(wdt, CDNS_WDT_CCR_OFFSET, data);
data = CDNS_WDT_ZMR_WDEN_MASK | CDNS_WDT_ZMR_RSTLEN_16 |
CDNS_WDT_ZMR_ZKEY_VAL;
if (wdt->rst) {
data |= CDNS_WDT_ZMR_RSTEN_MASK;
data &= ~CDNS_WDT_ZMR_IRQEN_MASK;
} else {
data &= ~CDNS_WDT_ZMR_RSTEN_MASK;
data |= CDNS_WDT_ZMR_IRQEN_MASK;
}
cdns_wdt_writereg(wdt, CDNS_WDT_ZMR_OFFSET, data);
cdns_wdt_writereg(wdt, CDNS_WDT_RESTART_OFFSET,
CDNS_WDT_RESTART_KEY);
spin_unlock(&wdt->io_lock);
return 0;
}
static int cdns_wdt_settimeout(struct watchdog_device *wdd,
unsigned int new_time)
{
wdd->timeout = new_time;
return cdns_wdt_start(wdd);
}
static irqreturn_t cdns_wdt_irq_handler(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
dev_info(&pdev->dev,
"Watchdog timed out. Internal reset not enabled\n");
return IRQ_HANDLED;
}
static int cdns_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
int ret, irq;
unsigned long clock_f;
struct cdns_wdt *wdt;
struct watchdog_device *cdns_wdt_device;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
cdns_wdt_device = &wdt->cdns_wdt_device;
cdns_wdt_device->info = &cdns_wdt_info;
cdns_wdt_device->ops = &cdns_wdt_ops;
cdns_wdt_device->timeout = CDNS_WDT_DEFAULT_TIMEOUT;
cdns_wdt_device->min_timeout = CDNS_WDT_MIN_TIMEOUT;
cdns_wdt_device->max_timeout = CDNS_WDT_MAX_TIMEOUT;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(wdt->regs))
return PTR_ERR(wdt->regs);
wdt->rst = of_property_read_bool(pdev->dev.of_node, "reset-on-timeout");
irq = platform_get_irq(pdev, 0);
if (!wdt->rst && irq >= 0) {
ret = devm_request_irq(&pdev->dev, irq, cdns_wdt_irq_handler, 0,
pdev->name, pdev);
if (ret) {
dev_err(&pdev->dev,
"cannot register interrupt handler err=%d\n",
ret);
return ret;
}
}
cdns_wdt_device->parent = &pdev->dev;
ret = watchdog_init_timeout(cdns_wdt_device, wdt_timeout, &pdev->dev);
if (ret) {
dev_err(&pdev->dev, "unable to set timeout value\n");
return ret;
}
watchdog_set_nowayout(cdns_wdt_device, nowayout);
watchdog_stop_on_reboot(cdns_wdt_device);
watchdog_set_drvdata(cdns_wdt_device, wdt);
wdt->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(wdt->clk)) {
dev_err(&pdev->dev, "input clock not found\n");
ret = PTR_ERR(wdt->clk);
return ret;
}
ret = clk_prepare_enable(wdt->clk);
if (ret) {
dev_err(&pdev->dev, "unable to enable clock\n");
return ret;
}
clock_f = clk_get_rate(wdt->clk);
if (clock_f <= CDNS_WDT_CLK_75MHZ) {
wdt->prescaler = CDNS_WDT_PRESCALE_512;
wdt->ctrl_clksel = CDNS_WDT_PRESCALE_SELECT_512;
} else {
wdt->prescaler = CDNS_WDT_PRESCALE_4096;
wdt->ctrl_clksel = CDNS_WDT_PRESCALE_SELECT_4096;
}
spin_lock_init(&wdt->io_lock);
ret = watchdog_register_device(cdns_wdt_device);
if (ret) {
dev_err(&pdev->dev, "Failed to register wdt device\n");
goto err_clk_disable;
}
platform_set_drvdata(pdev, wdt);
dev_dbg(&pdev->dev, "Xilinx Watchdog Timer at %p with timeout %ds%s\n",
wdt->regs, cdns_wdt_device->timeout,
nowayout ? ", nowayout" : "");
return 0;
err_clk_disable:
clk_disable_unprepare(wdt->clk);
return ret;
}
static int cdns_wdt_remove(struct platform_device *pdev)
{
struct cdns_wdt *wdt = platform_get_drvdata(pdev);
cdns_wdt_stop(&wdt->cdns_wdt_device);
watchdog_unregister_device(&wdt->cdns_wdt_device);
clk_disable_unprepare(wdt->clk);
return 0;
}
static void cdns_wdt_shutdown(struct platform_device *pdev)
{
struct cdns_wdt *wdt = platform_get_drvdata(pdev);
cdns_wdt_stop(&wdt->cdns_wdt_device);
clk_disable_unprepare(wdt->clk);
}
static int __maybe_unused cdns_wdt_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct cdns_wdt *wdt = platform_get_drvdata(pdev);
if (watchdog_active(&wdt->cdns_wdt_device)) {
cdns_wdt_stop(&wdt->cdns_wdt_device);
clk_disable_unprepare(wdt->clk);
}
return 0;
}
static int __maybe_unused cdns_wdt_resume(struct device *dev)
{
int ret;
struct platform_device *pdev = to_platform_device(dev);
struct cdns_wdt *wdt = platform_get_drvdata(pdev);
if (watchdog_active(&wdt->cdns_wdt_device)) {
ret = clk_prepare_enable(wdt->clk);
if (ret) {
dev_err(dev, "unable to enable clock\n");
return ret;
}
cdns_wdt_start(&wdt->cdns_wdt_device);
}
return 0;
}
