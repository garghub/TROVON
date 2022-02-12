static int davinci_wdt_start(struct watchdog_device *wdd)
{
u32 tgcr;
u32 timer_margin;
unsigned long wdt_freq;
struct davinci_wdt_device *davinci_wdt = watchdog_get_drvdata(wdd);
wdt_freq = clk_get_rate(davinci_wdt->clk);
iowrite32(0, davinci_wdt->base + TCR);
iowrite32(0, davinci_wdt->base + TGCR);
tgcr = TIMMODE_64BIT_WDOG | TIM12RS_UNRESET | TIM34RS_UNRESET;
iowrite32(tgcr, davinci_wdt->base + TGCR);
iowrite32(0, davinci_wdt->base + TIM12);
iowrite32(0, davinci_wdt->base + TIM34);
timer_margin = (((u64)wdd->timeout * wdt_freq) & 0xffffffff);
iowrite32(timer_margin, davinci_wdt->base + PRD12);
timer_margin = (((u64)wdd->timeout * wdt_freq) >> 32);
iowrite32(timer_margin, davinci_wdt->base + PRD34);
iowrite32(ENAMODE12_PERIODIC, davinci_wdt->base + TCR);
iowrite32(WDKEY_SEQ0 | WDEN, davinci_wdt->base + WDTCR);
iowrite32(WDKEY_SEQ1 | WDEN, davinci_wdt->base + WDTCR);
return 0;
}
static int davinci_wdt_ping(struct watchdog_device *wdd)
{
struct davinci_wdt_device *davinci_wdt = watchdog_get_drvdata(wdd);
iowrite32(WDKEY_SEQ0, davinci_wdt->base + WDTCR);
iowrite32(WDKEY_SEQ1, davinci_wdt->base + WDTCR);
return 0;
}
static unsigned int davinci_wdt_get_timeleft(struct watchdog_device *wdd)
{
u64 timer_counter;
unsigned long freq;
u32 val;
struct davinci_wdt_device *davinci_wdt = watchdog_get_drvdata(wdd);
val = ioread32(davinci_wdt->base + WDTCR);
if (val & WDFLAG)
return 0;
freq = clk_get_rate(davinci_wdt->clk);
if (!freq)
return 0;
timer_counter = ioread32(davinci_wdt->base + TIM12);
timer_counter |= ((u64)ioread32(davinci_wdt->base + TIM34) << 32);
do_div(timer_counter, freq);
return wdd->timeout - timer_counter;
}
static int davinci_wdt_probe(struct platform_device *pdev)
{
int ret = 0;
struct device *dev = &pdev->dev;
struct resource *wdt_mem;
struct watchdog_device *wdd;
struct davinci_wdt_device *davinci_wdt;
davinci_wdt = devm_kzalloc(dev, sizeof(*davinci_wdt), GFP_KERNEL);
if (!davinci_wdt)
return -ENOMEM;
davinci_wdt->clk = devm_clk_get(dev, NULL);
if (IS_ERR(davinci_wdt->clk)) {
if (PTR_ERR(davinci_wdt->clk) != -EPROBE_DEFER)
dev_err(&pdev->dev, "failed to get clock node\n");
return PTR_ERR(davinci_wdt->clk);
}
clk_prepare_enable(davinci_wdt->clk);
platform_set_drvdata(pdev, davinci_wdt);
wdd = &davinci_wdt->wdd;
wdd->info = &davinci_wdt_info;
wdd->ops = &davinci_wdt_ops;
wdd->min_timeout = 1;
wdd->max_timeout = MAX_HEARTBEAT;
wdd->timeout = DEFAULT_HEARTBEAT;
wdd->parent = &pdev->dev;
watchdog_init_timeout(wdd, heartbeat, dev);
dev_info(dev, "heartbeat %d sec\n", wdd->timeout);
watchdog_set_drvdata(wdd, davinci_wdt);
watchdog_set_nowayout(wdd, 1);
wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
davinci_wdt->base = devm_ioremap_resource(dev, wdt_mem);
if (IS_ERR(davinci_wdt->base))
return PTR_ERR(davinci_wdt->base);
ret = watchdog_register_device(wdd);
if (ret < 0)
dev_err(dev, "cannot register watchdog device\n");
return ret;
}
static int davinci_wdt_remove(struct platform_device *pdev)
{
struct davinci_wdt_device *davinci_wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&davinci_wdt->wdd);
clk_disable_unprepare(davinci_wdt->clk);
return 0;
}
