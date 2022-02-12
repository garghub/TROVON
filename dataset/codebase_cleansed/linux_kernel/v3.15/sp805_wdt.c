static int wdt_setload(struct watchdog_device *wdd, unsigned int timeout)
{
struct sp805_wdt *wdt = watchdog_get_drvdata(wdd);
u64 load, rate;
rate = clk_get_rate(wdt->clk);
load = div_u64(rate, 2) * timeout - 1;
load = (load > LOAD_MAX) ? LOAD_MAX : load;
load = (load < LOAD_MIN) ? LOAD_MIN : load;
spin_lock(&wdt->lock);
wdt->load_val = load;
wdt->timeout = div_u64((load + 1) * 2 + (rate / 2), rate);
spin_unlock(&wdt->lock);
return 0;
}
static unsigned int wdt_timeleft(struct watchdog_device *wdd)
{
struct sp805_wdt *wdt = watchdog_get_drvdata(wdd);
u64 load, rate;
rate = clk_get_rate(wdt->clk);
spin_lock(&wdt->lock);
load = readl_relaxed(wdt->base + WDTVALUE);
if (!(readl_relaxed(wdt->base + WDTRIS) & INT_MASK))
load += wdt->load_val + 1;
spin_unlock(&wdt->lock);
return div_u64(load, rate);
}
static int wdt_config(struct watchdog_device *wdd, bool ping)
{
struct sp805_wdt *wdt = watchdog_get_drvdata(wdd);
int ret;
if (!ping) {
ret = clk_prepare_enable(wdt->clk);
if (ret) {
dev_err(&wdt->adev->dev, "clock enable fail");
return ret;
}
}
spin_lock(&wdt->lock);
writel_relaxed(UNLOCK, wdt->base + WDTLOCK);
writel_relaxed(wdt->load_val, wdt->base + WDTLOAD);
if (!ping) {
writel_relaxed(INT_MASK, wdt->base + WDTINTCLR);
writel_relaxed(INT_ENABLE | RESET_ENABLE, wdt->base +
WDTCONTROL);
}
writel_relaxed(LOCK, wdt->base + WDTLOCK);
readl_relaxed(wdt->base + WDTLOCK);
spin_unlock(&wdt->lock);
return 0;
}
static int wdt_ping(struct watchdog_device *wdd)
{
return wdt_config(wdd, true);
}
static int wdt_enable(struct watchdog_device *wdd)
{
return wdt_config(wdd, false);
}
static int wdt_disable(struct watchdog_device *wdd)
{
struct sp805_wdt *wdt = watchdog_get_drvdata(wdd);
spin_lock(&wdt->lock);
writel_relaxed(UNLOCK, wdt->base + WDTLOCK);
writel_relaxed(0, wdt->base + WDTCONTROL);
writel_relaxed(LOCK, wdt->base + WDTLOCK);
readl_relaxed(wdt->base + WDTLOCK);
spin_unlock(&wdt->lock);
clk_disable_unprepare(wdt->clk);
return 0;
}
static int
sp805_wdt_probe(struct amba_device *adev, const struct amba_id *id)
{
struct sp805_wdt *wdt;
int ret = 0;
wdt = devm_kzalloc(&adev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt) {
ret = -ENOMEM;
goto err;
}
wdt->base = devm_ioremap_resource(&adev->dev, &adev->res);
if (IS_ERR(wdt->base))
return PTR_ERR(wdt->base);
wdt->clk = devm_clk_get(&adev->dev, NULL);
if (IS_ERR(wdt->clk)) {
dev_warn(&adev->dev, "Clock not found\n");
ret = PTR_ERR(wdt->clk);
goto err;
}
wdt->adev = adev;
wdt->wdd.info = &wdt_info;
wdt->wdd.ops = &wdt_ops;
spin_lock_init(&wdt->lock);
watchdog_set_nowayout(&wdt->wdd, nowayout);
watchdog_set_drvdata(&wdt->wdd, wdt);
wdt_setload(&wdt->wdd, DEFAULT_TIMEOUT);
ret = watchdog_register_device(&wdt->wdd);
if (ret) {
dev_err(&adev->dev, "watchdog_register_device() failed: %d\n",
ret);
goto err;
}
amba_set_drvdata(adev, wdt);
dev_info(&adev->dev, "registration successful\n");
return 0;
err:
dev_err(&adev->dev, "Probe Failed!!!\n");
return ret;
}
static int sp805_wdt_remove(struct amba_device *adev)
{
struct sp805_wdt *wdt = amba_get_drvdata(adev);
watchdog_unregister_device(&wdt->wdd);
watchdog_set_drvdata(&wdt->wdd, NULL);
return 0;
}
static int __maybe_unused sp805_wdt_suspend(struct device *dev)
{
struct sp805_wdt *wdt = dev_get_drvdata(dev);
if (watchdog_active(&wdt->wdd))
return wdt_disable(&wdt->wdd);
return 0;
}
static int __maybe_unused sp805_wdt_resume(struct device *dev)
{
struct sp805_wdt *wdt = dev_get_drvdata(dev);
if (watchdog_active(&wdt->wdd))
return wdt_enable(&wdt->wdd);
return 0;
}
