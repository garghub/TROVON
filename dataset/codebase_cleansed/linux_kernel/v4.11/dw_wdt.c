static inline int dw_wdt_is_enabled(struct dw_wdt *dw_wdt)
{
return readl(dw_wdt->regs + WDOG_CONTROL_REG_OFFSET) &
WDOG_CONTROL_REG_WDT_EN_MASK;
}
static inline int dw_wdt_top_in_seconds(struct dw_wdt *dw_wdt, unsigned top)
{
return (1U << (16 + top)) / dw_wdt->rate;
}
static int dw_wdt_get_top(struct dw_wdt *dw_wdt)
{
int top = readl(dw_wdt->regs + WDOG_TIMEOUT_RANGE_REG_OFFSET) & 0xF;
return dw_wdt_top_in_seconds(dw_wdt, top);
}
static int dw_wdt_ping(struct watchdog_device *wdd)
{
struct dw_wdt *dw_wdt = to_dw_wdt(wdd);
writel(WDOG_COUNTER_RESTART_KICK_VALUE, dw_wdt->regs +
WDOG_COUNTER_RESTART_REG_OFFSET);
return 0;
}
static int dw_wdt_set_timeout(struct watchdog_device *wdd, unsigned int top_s)
{
struct dw_wdt *dw_wdt = to_dw_wdt(wdd);
int i, top_val = DW_WDT_MAX_TOP;
for (i = 0; i <= DW_WDT_MAX_TOP; ++i)
if (dw_wdt_top_in_seconds(dw_wdt, i) >= top_s) {
top_val = i;
break;
}
writel(top_val | top_val << WDOG_TIMEOUT_RANGE_TOPINIT_SHIFT,
dw_wdt->regs + WDOG_TIMEOUT_RANGE_REG_OFFSET);
wdd->timeout = dw_wdt_top_in_seconds(dw_wdt, top_val);
return 0;
}
static int dw_wdt_start(struct watchdog_device *wdd)
{
struct dw_wdt *dw_wdt = to_dw_wdt(wdd);
dw_wdt_set_timeout(wdd, wdd->timeout);
set_bit(WDOG_HW_RUNNING, &wdd->status);
writel(WDOG_CONTROL_REG_WDT_EN_MASK,
dw_wdt->regs + WDOG_CONTROL_REG_OFFSET);
return 0;
}
static int dw_wdt_restart(struct watchdog_device *wdd,
unsigned long action, void *data)
{
struct dw_wdt *dw_wdt = to_dw_wdt(wdd);
u32 val;
writel(0, dw_wdt->regs + WDOG_TIMEOUT_RANGE_REG_OFFSET);
val = readl(dw_wdt->regs + WDOG_CONTROL_REG_OFFSET);
if (val & WDOG_CONTROL_REG_WDT_EN_MASK)
writel(WDOG_COUNTER_RESTART_KICK_VALUE,
dw_wdt->regs + WDOG_COUNTER_RESTART_REG_OFFSET);
else
writel(WDOG_CONTROL_REG_WDT_EN_MASK,
dw_wdt->regs + WDOG_CONTROL_REG_OFFSET);
mdelay(500);
return 0;
}
static unsigned int dw_wdt_get_timeleft(struct watchdog_device *wdd)
{
struct dw_wdt *dw_wdt = to_dw_wdt(wdd);
return readl(dw_wdt->regs + WDOG_CURRENT_COUNT_REG_OFFSET) /
dw_wdt->rate;
}
static int dw_wdt_suspend(struct device *dev)
{
struct dw_wdt *dw_wdt = dev_get_drvdata(dev);
clk_disable_unprepare(dw_wdt->clk);
return 0;
}
static int dw_wdt_resume(struct device *dev)
{
struct dw_wdt *dw_wdt = dev_get_drvdata(dev);
int err = clk_prepare_enable(dw_wdt->clk);
if (err)
return err;
dw_wdt_ping(&dw_wdt->wdd);
return 0;
}
static int dw_wdt_drv_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct watchdog_device *wdd;
struct dw_wdt *dw_wdt;
struct resource *mem;
int ret;
dw_wdt = devm_kzalloc(dev, sizeof(*dw_wdt), GFP_KERNEL);
if (!dw_wdt)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dw_wdt->regs = devm_ioremap_resource(dev, mem);
if (IS_ERR(dw_wdt->regs))
return PTR_ERR(dw_wdt->regs);
dw_wdt->clk = devm_clk_get(dev, NULL);
if (IS_ERR(dw_wdt->clk))
return PTR_ERR(dw_wdt->clk);
ret = clk_prepare_enable(dw_wdt->clk);
if (ret)
return ret;
dw_wdt->rate = clk_get_rate(dw_wdt->clk);
if (dw_wdt->rate == 0) {
ret = -EINVAL;
goto out_disable_clk;
}
wdd = &dw_wdt->wdd;
wdd->info = &dw_wdt_ident;
wdd->ops = &dw_wdt_ops;
wdd->min_timeout = 1;
wdd->max_hw_heartbeat_ms =
dw_wdt_top_in_seconds(dw_wdt, DW_WDT_MAX_TOP) * 1000;
wdd->parent = dev;
watchdog_set_drvdata(wdd, dw_wdt);
watchdog_set_nowayout(wdd, nowayout);
watchdog_init_timeout(wdd, 0, dev);
if (dw_wdt_is_enabled(dw_wdt)) {
wdd->timeout = dw_wdt_get_top(dw_wdt);
set_bit(WDOG_HW_RUNNING, &wdd->status);
} else {
wdd->timeout = DW_WDT_DEFAULT_SECONDS;
watchdog_init_timeout(wdd, 0, dev);
}
platform_set_drvdata(pdev, dw_wdt);
watchdog_set_restart_priority(wdd, 128);
ret = watchdog_register_device(wdd);
if (ret)
goto out_disable_clk;
return 0;
out_disable_clk:
clk_disable_unprepare(dw_wdt->clk);
return ret;
}
static int dw_wdt_drv_remove(struct platform_device *pdev)
{
struct dw_wdt *dw_wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&dw_wdt->wdd);
clk_disable_unprepare(dw_wdt->clk);
return 0;
}
