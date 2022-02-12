static int meson_restart_handle(struct notifier_block *this, unsigned long mode,
void *cmd)
{
u32 tc_reboot = MESON_WDT_DC_RESET | MESON_WDT_TC_EN;
struct meson_wdt_dev *meson_wdt = container_of(this,
struct meson_wdt_dev,
restart_handler);
while (1) {
writel(tc_reboot, meson_wdt->wdt_base + MESON_WDT_TC);
mdelay(5);
}
return NOTIFY_DONE;
}
static int meson_wdt_ping(struct watchdog_device *wdt_dev)
{
struct meson_wdt_dev *meson_wdt = watchdog_get_drvdata(wdt_dev);
writel(0, meson_wdt->wdt_base + MESON_WDT_RESET);
return 0;
}
static void meson_wdt_change_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct meson_wdt_dev *meson_wdt = watchdog_get_drvdata(wdt_dev);
u32 reg;
reg = readl(meson_wdt->wdt_base + MESON_WDT_TC);
reg &= ~MESON_WDT_TC_TM_MASK;
reg |= MESON_SEC_TO_TC(timeout);
writel(reg, meson_wdt->wdt_base + MESON_WDT_TC);
}
static int meson_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
wdt_dev->timeout = timeout;
meson_wdt_change_timeout(wdt_dev, timeout);
meson_wdt_ping(wdt_dev);
return 0;
}
static int meson_wdt_stop(struct watchdog_device *wdt_dev)
{
struct meson_wdt_dev *meson_wdt = watchdog_get_drvdata(wdt_dev);
u32 reg;
reg = readl(meson_wdt->wdt_base + MESON_WDT_TC);
reg &= ~MESON_WDT_TC_EN;
writel(reg, meson_wdt->wdt_base + MESON_WDT_TC);
return 0;
}
static int meson_wdt_start(struct watchdog_device *wdt_dev)
{
struct meson_wdt_dev *meson_wdt = watchdog_get_drvdata(wdt_dev);
u32 reg;
meson_wdt_change_timeout(wdt_dev, meson_wdt->wdt_dev.timeout);
meson_wdt_ping(wdt_dev);
reg = readl(meson_wdt->wdt_base + MESON_WDT_TC);
reg |= MESON_WDT_TC_EN;
writel(reg, meson_wdt->wdt_base + MESON_WDT_TC);
return 0;
}
static int meson_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
struct meson_wdt_dev *meson_wdt;
int err;
meson_wdt = devm_kzalloc(&pdev->dev, sizeof(*meson_wdt), GFP_KERNEL);
if (!meson_wdt)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
meson_wdt->wdt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(meson_wdt->wdt_base))
return PTR_ERR(meson_wdt->wdt_base);
meson_wdt->wdt_dev.parent = &pdev->dev;
meson_wdt->wdt_dev.info = &meson_wdt_info;
meson_wdt->wdt_dev.ops = &meson_wdt_ops;
meson_wdt->wdt_dev.timeout = MESON_WDT_TIMEOUT;
meson_wdt->wdt_dev.max_timeout = MESON_WDT_MAX_TIMEOUT;
meson_wdt->wdt_dev.min_timeout = MESON_WDT_MIN_TIMEOUT;
watchdog_set_drvdata(&meson_wdt->wdt_dev, meson_wdt);
watchdog_init_timeout(&meson_wdt->wdt_dev, timeout, &pdev->dev);
watchdog_set_nowayout(&meson_wdt->wdt_dev, nowayout);
meson_wdt_stop(&meson_wdt->wdt_dev);
err = watchdog_register_device(&meson_wdt->wdt_dev);
if (err)
return err;
platform_set_drvdata(pdev, meson_wdt);
meson_wdt->restart_handler.notifier_call = meson_restart_handle;
meson_wdt->restart_handler.priority = 128;
err = register_restart_handler(&meson_wdt->restart_handler);
if (err)
dev_err(&pdev->dev,
"cannot register restart handler (err=%d)\n", err);
dev_info(&pdev->dev, "Watchdog enabled (timeout=%d sec, nowayout=%d)",
meson_wdt->wdt_dev.timeout, nowayout);
return 0;
}
static int meson_wdt_remove(struct platform_device *pdev)
{
struct meson_wdt_dev *meson_wdt = platform_get_drvdata(pdev);
unregister_restart_handler(&meson_wdt->restart_handler);
watchdog_unregister_device(&meson_wdt->wdt_dev);
return 0;
}
static void meson_wdt_shutdown(struct platform_device *pdev)
{
struct meson_wdt_dev *meson_wdt = platform_get_drvdata(pdev);
meson_wdt_stop(&meson_wdt->wdt_dev);
}
