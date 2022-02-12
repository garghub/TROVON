static struct max63xx_timeout *
max63xx_select_timeout(struct max63xx_timeout *table, int value)
{
while (table->twd) {
if (value <= table->twd) {
if (nodelay && table->tdelay == 0)
return table;
if (!nodelay)
return table;
}
table++;
}
return NULL;
}
static int max63xx_wdt_ping(struct watchdog_device *wdd)
{
u8 val;
spin_lock(&io_lock);
val = __raw_readb(wdt_base);
__raw_writeb(val | MAX6369_WDI, wdt_base);
__raw_writeb(val & ~MAX6369_WDI, wdt_base);
spin_unlock(&io_lock);
return 0;
}
static int max63xx_wdt_start(struct watchdog_device *wdd)
{
struct max63xx_timeout *entry = watchdog_get_drvdata(wdd);
u8 val;
spin_lock(&io_lock);
val = __raw_readb(wdt_base);
val &= ~MAX6369_WDSET;
val |= entry->wdset;
__raw_writeb(val, wdt_base);
spin_unlock(&io_lock);
if (entry->tdelay == 0)
max63xx_wdt_ping(wdd);
return 0;
}
static int max63xx_wdt_stop(struct watchdog_device *wdd)
{
u8 val;
spin_lock(&io_lock);
val = __raw_readb(wdt_base);
val &= ~MAX6369_WDSET;
val |= 3;
__raw_writeb(val, wdt_base);
spin_unlock(&io_lock);
return 0;
}
static int max63xx_wdt_probe(struct platform_device *pdev)
{
struct resource *wdt_mem;
struct max63xx_timeout *table;
table = (struct max63xx_timeout *)pdev->id_entry->driver_data;
if (heartbeat < 1 || heartbeat > MAX_HEARTBEAT)
heartbeat = DEFAULT_HEARTBEAT;
dev_info(&pdev->dev, "requesting %ds heartbeat\n", heartbeat);
current_timeout = max63xx_select_timeout(table, heartbeat);
if (!current_timeout) {
dev_err(&pdev->dev, "unable to satisfy heartbeat request\n");
return -EINVAL;
}
dev_info(&pdev->dev, "using %ds heartbeat with %ds initial delay\n",
current_timeout->twd, current_timeout->tdelay);
heartbeat = current_timeout->twd;
wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt_base = devm_ioremap_resource(&pdev->dev, wdt_mem);
if (IS_ERR(wdt_base))
return PTR_ERR(wdt_base);
max63xx_wdt_dev.timeout = heartbeat;
watchdog_set_nowayout(&max63xx_wdt_dev, nowayout);
watchdog_set_drvdata(&max63xx_wdt_dev, current_timeout);
return watchdog_register_device(&max63xx_wdt_dev);
}
static int max63xx_wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&max63xx_wdt_dev);
return 0;
}
