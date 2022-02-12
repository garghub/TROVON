static inline bool pic32_wdt_is_win_enabled(struct pic32_wdt *wdt)
{
return !!(readl(wdt->regs + WDTCON_REG) & WDTCON_WIN_EN);
}
static inline u32 pic32_wdt_get_post_scaler(struct pic32_wdt *wdt)
{
u32 v = readl(wdt->regs + WDTCON_REG);
return (v >> WDTCON_RMPS_SHIFT) & WDTCON_RMPS_MASK;
}
static inline u32 pic32_wdt_get_clk_id(struct pic32_wdt *wdt)
{
u32 v = readl(wdt->regs + WDTCON_REG);
return (v >> WDTCON_RMCS_SHIFT) & WDTCON_RMCS_MASK;
}
static int pic32_wdt_bootstatus(struct pic32_wdt *wdt)
{
u32 v = readl(wdt->rst_base);
writel(RESETCON_WDT_TIMEOUT, PIC32_CLR(wdt->rst_base));
return v & RESETCON_WDT_TIMEOUT;
}
static u32 pic32_wdt_get_timeout_secs(struct pic32_wdt *wdt, struct device *dev)
{
unsigned long rate;
u32 period, ps, terminal;
rate = clk_get_rate(wdt->clk);
dev_dbg(dev, "wdt: clk_id %d, clk_rate %lu (prescale)\n",
pic32_wdt_get_clk_id(wdt), rate);
rate >>= 5;
if (!rate)
return 0;
ps = pic32_wdt_get_post_scaler(wdt);
terminal = BIT(ps);
period = terminal / rate;
dev_dbg(dev,
"wdt: clk_rate %lu (postscale) / terminal %d, timeout %dsec\n",
rate, terminal, period);
return period;
}
static void pic32_wdt_keepalive(struct pic32_wdt *wdt)
{
writew(WDTCON_CLR_KEY, wdt->regs + WDTCON_REG + 2);
}
static int pic32_wdt_start(struct watchdog_device *wdd)
{
struct pic32_wdt *wdt = watchdog_get_drvdata(wdd);
writel(WDTCON_ON, PIC32_SET(wdt->regs + WDTCON_REG));
pic32_wdt_keepalive(wdt);
return 0;
}
static int pic32_wdt_stop(struct watchdog_device *wdd)
{
struct pic32_wdt *wdt = watchdog_get_drvdata(wdd);
writel(WDTCON_ON, PIC32_CLR(wdt->regs + WDTCON_REG));
nop();
return 0;
}
static int pic32_wdt_ping(struct watchdog_device *wdd)
{
struct pic32_wdt *wdt = watchdog_get_drvdata(wdd);
pic32_wdt_keepalive(wdt);
return 0;
}
static int pic32_wdt_drv_probe(struct platform_device *pdev)
{
int ret;
struct watchdog_device *wdd = &pic32_wdd;
struct pic32_wdt *wdt;
struct resource *mem;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (IS_ERR(wdt))
return PTR_ERR(wdt);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(wdt->regs))
return PTR_ERR(wdt->regs);
wdt->rst_base = devm_ioremap(&pdev->dev, PIC32_BASE_RESET, 0x10);
if (IS_ERR(wdt->rst_base))
return PTR_ERR(wdt->rst_base);
wdt->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(wdt->clk)) {
dev_err(&pdev->dev, "clk not found\n");
return PTR_ERR(wdt->clk);
}
ret = clk_prepare_enable(wdt->clk);
if (ret) {
dev_err(&pdev->dev, "clk enable failed\n");
return ret;
}
if (pic32_wdt_is_win_enabled(wdt)) {
dev_err(&pdev->dev, "windowed-clear mode is not supported.\n");
ret = -ENODEV;
goto out_disable_clk;
}
wdd->timeout = pic32_wdt_get_timeout_secs(wdt, &pdev->dev);
if (!wdd->timeout) {
dev_err(&pdev->dev,
"failed to read watchdog register timeout\n");
ret = -EINVAL;
goto out_disable_clk;
}
dev_info(&pdev->dev, "timeout %d\n", wdd->timeout);
wdd->bootstatus = pic32_wdt_bootstatus(wdt) ? WDIOF_CARDRESET : 0;
watchdog_set_nowayout(wdd, WATCHDOG_NOWAYOUT);
watchdog_set_drvdata(wdd, wdt);
ret = watchdog_register_device(wdd);
if (ret) {
dev_err(&pdev->dev, "watchdog register failed, err %d\n", ret);
goto out_disable_clk;
}
platform_set_drvdata(pdev, wdd);
return 0;
out_disable_clk:
clk_disable_unprepare(wdt->clk);
return ret;
}
static int pic32_wdt_drv_remove(struct platform_device *pdev)
{
struct watchdog_device *wdd = platform_get_drvdata(pdev);
struct pic32_wdt *wdt = watchdog_get_drvdata(wdd);
watchdog_unregister_device(wdd);
clk_disable_unprepare(wdt->clk);
return 0;
}
