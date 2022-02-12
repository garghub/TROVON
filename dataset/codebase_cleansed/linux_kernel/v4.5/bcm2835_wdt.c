static int bcm2835_wdt_start(struct watchdog_device *wdog)
{
struct bcm2835_wdt *wdt = watchdog_get_drvdata(wdog);
uint32_t cur;
unsigned long flags;
spin_lock_irqsave(&wdt->lock, flags);
writel_relaxed(PM_PASSWORD | (SECS_TO_WDOG_TICKS(wdog->timeout) &
PM_WDOG_TIME_SET), wdt->base + PM_WDOG);
cur = readl_relaxed(wdt->base + PM_RSTC);
writel_relaxed(PM_PASSWORD | (cur & PM_RSTC_WRCFG_CLR) |
PM_RSTC_WRCFG_FULL_RESET, wdt->base + PM_RSTC);
spin_unlock_irqrestore(&wdt->lock, flags);
return 0;
}
static int bcm2835_wdt_stop(struct watchdog_device *wdog)
{
struct bcm2835_wdt *wdt = watchdog_get_drvdata(wdog);
writel_relaxed(PM_PASSWORD | PM_RSTC_RESET, wdt->base + PM_RSTC);
return 0;
}
static int bcm2835_wdt_set_timeout(struct watchdog_device *wdog, unsigned int t)
{
wdog->timeout = t;
return 0;
}
static unsigned int bcm2835_wdt_get_timeleft(struct watchdog_device *wdog)
{
struct bcm2835_wdt *wdt = watchdog_get_drvdata(wdog);
uint32_t ret = readl_relaxed(wdt->base + PM_WDOG);
return WDOG_TICKS_TO_SECS(ret & PM_WDOG_TIME_SET);
}
static int
bcm2835_restart(struct notifier_block *this, unsigned long mode, void *cmd)
{
struct bcm2835_wdt *wdt = container_of(this, struct bcm2835_wdt,
restart_handler);
u32 val;
writel_relaxed(10 | PM_PASSWORD, wdt->base + PM_WDOG);
val = readl_relaxed(wdt->base + PM_RSTC);
val &= PM_RSTC_WRCFG_CLR;
val |= PM_PASSWORD | PM_RSTC_WRCFG_FULL_RESET;
writel_relaxed(val, wdt->base + PM_RSTC);
mdelay(1);
return 0;
}
static void bcm2835_power_off(void)
{
struct device_node *np =
of_find_compatible_node(NULL, NULL, "brcm,bcm2835-pm-wdt");
struct platform_device *pdev = of_find_device_by_node(np);
struct bcm2835_wdt *wdt = platform_get_drvdata(pdev);
u32 val;
val = readl_relaxed(wdt->base + PM_RSTS);
val |= PM_PASSWORD | PM_RSTS_RASPBERRYPI_HALT;
writel_relaxed(val, wdt->base + PM_RSTS);
bcm2835_restart(&wdt->restart_handler, REBOOT_HARD, NULL);
}
static int bcm2835_wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct bcm2835_wdt *wdt;
int err;
wdt = devm_kzalloc(dev, sizeof(struct bcm2835_wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
platform_set_drvdata(pdev, wdt);
spin_lock_init(&wdt->lock);
wdt->base = of_iomap(np, 0);
if (!wdt->base) {
dev_err(dev, "Failed to remap watchdog regs");
return -ENODEV;
}
watchdog_set_drvdata(&bcm2835_wdt_wdd, wdt);
watchdog_init_timeout(&bcm2835_wdt_wdd, heartbeat, dev);
watchdog_set_nowayout(&bcm2835_wdt_wdd, nowayout);
bcm2835_wdt_wdd.parent = &pdev->dev;
err = watchdog_register_device(&bcm2835_wdt_wdd);
if (err) {
dev_err(dev, "Failed to register watchdog device");
iounmap(wdt->base);
return err;
}
wdt->restart_handler.notifier_call = bcm2835_restart;
wdt->restart_handler.priority = 128;
register_restart_handler(&wdt->restart_handler);
if (pm_power_off == NULL)
pm_power_off = bcm2835_power_off;
dev_info(dev, "Broadcom BCM2835 watchdog timer");
return 0;
}
static int bcm2835_wdt_remove(struct platform_device *pdev)
{
struct bcm2835_wdt *wdt = platform_get_drvdata(pdev);
unregister_restart_handler(&wdt->restart_handler);
if (pm_power_off == bcm2835_power_off)
pm_power_off = NULL;
watchdog_unregister_device(&bcm2835_wdt_wdd);
iounmap(wdt->base);
return 0;
}
static void bcm2835_wdt_shutdown(struct platform_device *pdev)
{
bcm2835_wdt_stop(&bcm2835_wdt_wdd);
}
