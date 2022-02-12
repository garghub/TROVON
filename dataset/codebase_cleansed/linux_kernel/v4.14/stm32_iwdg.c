static inline u32 reg_read(void __iomem *base, u32 reg)
{
return readl_relaxed(base + reg);
}
static inline void reg_write(void __iomem *base, u32 reg, u32 val)
{
writel_relaxed(val, base + reg);
}
static int stm32_iwdg_start(struct watchdog_device *wdd)
{
struct stm32_iwdg *wdt = watchdog_get_drvdata(wdd);
u32 val = FLAG_PVU | FLAG_RVU;
u32 reload;
int ret;
dev_dbg(wdd->parent, "%s\n", __func__);
reload = clamp_t(unsigned int, ((wdd->timeout * wdt->rate) / 256) - 1,
RLR_MIN, RLR_MAX);
reg_write(wdt->regs, IWDG_KR, KR_KEY_EWA);
reg_write(wdt->regs, IWDG_PR, PR_256);
reg_write(wdt->regs, IWDG_RLR, reload);
reg_write(wdt->regs, IWDG_KR, KR_KEY_ENABLE);
ret = readl_relaxed_poll_timeout(wdt->regs + IWDG_SR, val,
!(val & (FLAG_PVU | FLAG_RVU)),
SLEEP_US, TIMEOUT_US);
if (ret) {
dev_err(wdd->parent,
"Fail to set prescaler or reload registers\n");
return ret;
}
reg_write(wdt->regs, IWDG_KR, KR_KEY_RELOAD);
return 0;
}
static int stm32_iwdg_ping(struct watchdog_device *wdd)
{
struct stm32_iwdg *wdt = watchdog_get_drvdata(wdd);
dev_dbg(wdd->parent, "%s\n", __func__);
reg_write(wdt->regs, IWDG_KR, KR_KEY_RELOAD);
return 0;
}
static int stm32_iwdg_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
dev_dbg(wdd->parent, "%s timeout: %d sec\n", __func__, timeout);
wdd->timeout = timeout;
if (watchdog_active(wdd))
return stm32_iwdg_start(wdd);
return 0;
}
static int stm32_iwdg_probe(struct platform_device *pdev)
{
struct watchdog_device *wdd;
struct stm32_iwdg *wdt;
struct resource *res;
void __iomem *regs;
struct clk *clk;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs)) {
dev_err(&pdev->dev, "Could not get resource\n");
return PTR_ERR(regs);
}
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Unable to get clock\n");
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(&pdev->dev, "Unable to prepare clock %p\n", clk);
return ret;
}
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt) {
ret = -ENOMEM;
goto err;
}
wdt->regs = regs;
wdt->clk = clk;
wdt->rate = clk_get_rate(clk);
wdd = &wdt->wdd;
wdd->info = &stm32_iwdg_info;
wdd->ops = &stm32_iwdg_ops;
wdd->min_timeout = ((RLR_MIN + 1) * 256) / wdt->rate;
wdd->max_hw_heartbeat_ms = ((RLR_MAX + 1) * 256 * 1000) / wdt->rate;
wdd->parent = &pdev->dev;
watchdog_set_drvdata(wdd, wdt);
watchdog_set_nowayout(wdd, WATCHDOG_NOWAYOUT);
ret = watchdog_init_timeout(wdd, 0, &pdev->dev);
if (ret)
dev_warn(&pdev->dev,
"unable to set timeout value, using default\n");
ret = watchdog_register_device(wdd);
if (ret) {
dev_err(&pdev->dev, "failed to register watchdog device\n");
goto err;
}
platform_set_drvdata(pdev, wdt);
return 0;
err:
clk_disable_unprepare(clk);
return ret;
}
static int stm32_iwdg_remove(struct platform_device *pdev)
{
struct stm32_iwdg *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&wdt->wdd);
clk_disable_unprepare(wdt->clk);
return 0;
}
