static int sbsa_gwdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct sbsa_gwdt *gwdt = watchdog_get_drvdata(wdd);
wdd->timeout = timeout;
if (action)
writel(gwdt->clk * timeout,
gwdt->control_base + SBSA_GWDT_WOR);
else
writel(gwdt->clk / 2 * timeout,
gwdt->control_base + SBSA_GWDT_WOR);
return 0;
}
static unsigned int sbsa_gwdt_get_timeleft(struct watchdog_device *wdd)
{
struct sbsa_gwdt *gwdt = watchdog_get_drvdata(wdd);
u64 timeleft = 0;
if (!action &&
!(readl(gwdt->control_base + SBSA_GWDT_WCS) & SBSA_GWDT_WCS_WS0))
timeleft += readl(gwdt->control_base + SBSA_GWDT_WOR);
timeleft += readq(gwdt->control_base + SBSA_GWDT_WCV) -
arch_counter_get_cntvct();
do_div(timeleft, gwdt->clk);
return timeleft;
}
static int sbsa_gwdt_keepalive(struct watchdog_device *wdd)
{
struct sbsa_gwdt *gwdt = watchdog_get_drvdata(wdd);
writel(0, gwdt->refresh_base + SBSA_GWDT_WRR);
return 0;
}
static int sbsa_gwdt_start(struct watchdog_device *wdd)
{
struct sbsa_gwdt *gwdt = watchdog_get_drvdata(wdd);
writel(SBSA_GWDT_WCS_EN, gwdt->control_base + SBSA_GWDT_WCS);
return 0;
}
static int sbsa_gwdt_stop(struct watchdog_device *wdd)
{
struct sbsa_gwdt *gwdt = watchdog_get_drvdata(wdd);
writel(0, gwdt->control_base + SBSA_GWDT_WCS);
return 0;
}
static irqreturn_t sbsa_gwdt_interrupt(int irq, void *dev_id)
{
panic(WATCHDOG_NAME " timeout");
return IRQ_HANDLED;
}
static int sbsa_gwdt_probe(struct platform_device *pdev)
{
void __iomem *rf_base, *cf_base;
struct device *dev = &pdev->dev;
struct watchdog_device *wdd;
struct sbsa_gwdt *gwdt;
struct resource *res;
int ret, irq;
u32 status;
gwdt = devm_kzalloc(dev, sizeof(*gwdt), GFP_KERNEL);
if (!gwdt)
return -ENOMEM;
platform_set_drvdata(pdev, gwdt);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
cf_base = devm_ioremap_resource(dev, res);
if (IS_ERR(cf_base))
return PTR_ERR(cf_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
rf_base = devm_ioremap_resource(dev, res);
if (IS_ERR(rf_base))
return PTR_ERR(rf_base);
gwdt->clk = arch_timer_get_cntfrq();
gwdt->refresh_base = rf_base;
gwdt->control_base = cf_base;
wdd = &gwdt->wdd;
wdd->parent = dev;
wdd->info = &sbsa_gwdt_info;
wdd->ops = &sbsa_gwdt_ops;
wdd->min_timeout = 1;
wdd->max_hw_heartbeat_ms = U32_MAX / gwdt->clk * 1000;
wdd->timeout = DEFAULT_TIMEOUT;
watchdog_set_drvdata(wdd, gwdt);
watchdog_set_nowayout(wdd, nowayout);
status = readl(cf_base + SBSA_GWDT_WCS);
if (status & SBSA_GWDT_WCS_WS1) {
dev_warn(dev, "System reset by WDT.\n");
wdd->bootstatus |= WDIOF_CARDRESET;
}
if (status & SBSA_GWDT_WCS_EN)
set_bit(WDOG_HW_RUNNING, &wdd->status);
if (action) {
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
action = 0;
dev_warn(dev, "unable to get ws0 interrupt.\n");
} else {
writel(0, rf_base + SBSA_GWDT_WRR);
if (devm_request_irq(dev, irq, sbsa_gwdt_interrupt, 0,
pdev->name, gwdt)) {
action = 0;
dev_warn(dev, "unable to request IRQ %d.\n",
irq);
}
}
if (!action)
dev_warn(dev, "falling back to single stage mode.\n");
}
if (!action)
wdd->max_hw_heartbeat_ms *= 2;
watchdog_init_timeout(wdd, timeout, dev);
sbsa_gwdt_set_timeout(wdd, wdd->timeout);
ret = watchdog_register_device(wdd);
if (ret)
return ret;
dev_info(dev, "Initialized with %ds timeout @ %u Hz, action=%d.%s\n",
wdd->timeout, gwdt->clk, action,
status & SBSA_GWDT_WCS_EN ? " [enabled]" : "");
return 0;
}
static void sbsa_gwdt_shutdown(struct platform_device *pdev)
{
struct sbsa_gwdt *gwdt = platform_get_drvdata(pdev);
sbsa_gwdt_stop(&gwdt->wdd);
}
static int sbsa_gwdt_remove(struct platform_device *pdev)
{
struct sbsa_gwdt *gwdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&gwdt->wdd);
return 0;
}
static int __maybe_unused sbsa_gwdt_suspend(struct device *dev)
{
struct sbsa_gwdt *gwdt = dev_get_drvdata(dev);
if (watchdog_active(&gwdt->wdd))
sbsa_gwdt_stop(&gwdt->wdd);
return 0;
}
static int __maybe_unused sbsa_gwdt_resume(struct device *dev)
{
struct sbsa_gwdt *gwdt = dev_get_drvdata(dev);
if (watchdog_active(&gwdt->wdd))
sbsa_gwdt_start(&gwdt->wdd);
return 0;
}
