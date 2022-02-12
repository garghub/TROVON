static void ep93xx_wdt_timer_ping(unsigned long data)
{
if (time_before(jiffies, next_heartbeat))
writel(0x5555, mmio_base + EP93XX_WATCHDOG);
mod_timer(&timer, jiffies + WDT_INTERVAL);
}
static int ep93xx_wdt_start(struct watchdog_device *wdd)
{
next_heartbeat = jiffies + (timeout * HZ);
writel(0xaaaa, mmio_base + EP93XX_WATCHDOG);
mod_timer(&timer, jiffies + WDT_INTERVAL);
return 0;
}
static int ep93xx_wdt_stop(struct watchdog_device *wdd)
{
del_timer_sync(&timer);
writel(0xaa55, mmio_base + EP93XX_WATCHDOG);
return 0;
}
static int ep93xx_wdt_keepalive(struct watchdog_device *wdd)
{
next_heartbeat = jiffies + (timeout * HZ);
return 0;
}
static int ep93xx_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
unsigned long val;
int err;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), pdev->name))
return -EBUSY;
mmio_base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!mmio_base)
return -ENXIO;
if (timeout < 1 || timeout > 3600) {
timeout = WDT_TIMEOUT;
dev_warn(&pdev->dev,
"timeout value must be 1<=x<=3600, using %d\n",
timeout);
}
val = readl(mmio_base + EP93XX_WATCHDOG);
ep93xx_wdt_wdd.bootstatus = (val & 0x01) ? WDIOF_CARDRESET : 0;
ep93xx_wdt_wdd.timeout = timeout;
watchdog_set_nowayout(&ep93xx_wdt_wdd, nowayout);
setup_timer(&timer, ep93xx_wdt_timer_ping, 1);
err = watchdog_register_device(&ep93xx_wdt_wdd);
if (err)
return err;
dev_info(&pdev->dev,
"EP93XX watchdog, driver version " WDT_VERSION "%s\n",
(val & 0x08) ? " (nCS1 disable detected)" : "");
return 0;
}
static int ep93xx_wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&ep93xx_wdt_wdd);
return 0;
}
