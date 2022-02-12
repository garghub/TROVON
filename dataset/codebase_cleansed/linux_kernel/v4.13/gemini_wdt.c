static inline
struct gemini_wdt *to_gemini_wdt(struct watchdog_device *wdd)
{
return container_of(wdd, struct gemini_wdt, wdd);
}
static int gemini_wdt_start(struct watchdog_device *wdd)
{
struct gemini_wdt *gwdt = to_gemini_wdt(wdd);
writel(wdd->timeout * WDT_CLOCK, gwdt->base + GEMINI_WDLOAD);
writel(WDRESTART_MAGIC, gwdt->base + GEMINI_WDRESTART);
writel(WDCR_CLOCK_5MHZ | WDCR_SYS_RST,
gwdt->base + GEMINI_WDCR);
writel(WDCR_CLOCK_5MHZ | WDCR_SYS_RST | WDCR_ENABLE,
gwdt->base + GEMINI_WDCR);
return 0;
}
static int gemini_wdt_stop(struct watchdog_device *wdd)
{
struct gemini_wdt *gwdt = to_gemini_wdt(wdd);
writel(0, gwdt->base + GEMINI_WDCR);
return 0;
}
static int gemini_wdt_ping(struct watchdog_device *wdd)
{
struct gemini_wdt *gwdt = to_gemini_wdt(wdd);
writel(WDRESTART_MAGIC, gwdt->base + GEMINI_WDRESTART);
return 0;
}
static int gemini_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
wdd->timeout = timeout;
if (watchdog_active(wdd))
gemini_wdt_start(wdd);
return 0;
}
static irqreturn_t gemini_wdt_interrupt(int irq, void *data)
{
struct gemini_wdt *gwdt = data;
watchdog_notify_pretimeout(&gwdt->wdd);
return IRQ_HANDLED;
}
static int gemini_wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct gemini_wdt *gwdt;
unsigned int reg;
int irq;
int ret;
gwdt = devm_kzalloc(dev, sizeof(*gwdt), GFP_KERNEL);
if (!gwdt)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gwdt->base = devm_ioremap_resource(dev, res);
if (IS_ERR(gwdt->base))
return PTR_ERR(gwdt->base);
irq = platform_get_irq(pdev, 0);
if (!irq)
return -EINVAL;
gwdt->dev = dev;
gwdt->wdd.info = &gemini_wdt_info;
gwdt->wdd.ops = &gemini_wdt_ops;
gwdt->wdd.min_timeout = 1;
gwdt->wdd.max_timeout = 0xFFFFFFFF / WDT_CLOCK;
gwdt->wdd.parent = dev;
gwdt->wdd.timeout = 13U;
watchdog_init_timeout(&gwdt->wdd, 0, dev);
reg = readw(gwdt->base + GEMINI_WDCR);
if (reg & WDCR_ENABLE) {
reg &= ~WDCR_ENABLE;
writel(reg, gwdt->base + GEMINI_WDCR);
}
ret = devm_request_irq(dev, irq, gemini_wdt_interrupt, 0,
"watchdog bark", gwdt);
if (ret)
return ret;
ret = devm_watchdog_register_device(dev, &gwdt->wdd);
if (ret) {
dev_err(&pdev->dev, "failed to register watchdog\n");
return ret;
}
platform_set_drvdata(pdev, gwdt);
dev_info(dev, "Gemini watchdog driver enabled\n");
return 0;
}
static int __maybe_unused gemini_wdt_suspend(struct device *dev)
{
struct gemini_wdt *gwdt = dev_get_drvdata(dev);
unsigned int reg;
reg = readw(gwdt->base + GEMINI_WDCR);
reg &= ~WDCR_ENABLE;
writel(reg, gwdt->base + GEMINI_WDCR);
return 0;
}
static int __maybe_unused gemini_wdt_resume(struct device *dev)
{
struct gemini_wdt *gwdt = dev_get_drvdata(dev);
unsigned int reg;
if (watchdog_active(&gwdt->wdd)) {
reg = readw(gwdt->base + GEMINI_WDCR);
reg |= WDCR_ENABLE;
writel(reg, gwdt->base + GEMINI_WDCR);
}
return 0;
}
