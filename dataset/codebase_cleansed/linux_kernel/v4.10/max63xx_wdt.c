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
struct max63xx_wdt *wdt = watchdog_get_drvdata(wdd);
wdt->ping(wdt);
return 0;
}
static int max63xx_wdt_start(struct watchdog_device *wdd)
{
struct max63xx_wdt *wdt = watchdog_get_drvdata(wdd);
wdt->set(wdt, wdt->timeout->wdset);
if (wdt->timeout->tdelay == 0)
wdt->ping(wdt);
return 0;
}
static int max63xx_wdt_stop(struct watchdog_device *wdd)
{
struct max63xx_wdt *wdt = watchdog_get_drvdata(wdd);
wdt->set(wdt, MAX6369_WDSET_DISABLED);
return 0;
}
static void max63xx_mmap_ping(struct max63xx_wdt *wdt)
{
u8 val;
spin_lock(&wdt->lock);
val = __raw_readb(wdt->base);
__raw_writeb(val | MAX6369_WDI, wdt->base);
__raw_writeb(val & ~MAX6369_WDI, wdt->base);
spin_unlock(&wdt->lock);
}
static void max63xx_mmap_set(struct max63xx_wdt *wdt, u8 set)
{
u8 val;
spin_lock(&wdt->lock);
val = __raw_readb(wdt->base);
val &= ~MAX6369_WDSET;
val |= set & MAX6369_WDSET;
__raw_writeb(val, wdt->base);
spin_unlock(&wdt->lock);
}
static int max63xx_mmap_init(struct platform_device *p, struct max63xx_wdt *wdt)
{
struct resource *mem = platform_get_resource(p, IORESOURCE_MEM, 0);
wdt->base = devm_ioremap_resource(&p->dev, mem);
if (IS_ERR(wdt->base))
return PTR_ERR(wdt->base);
spin_lock_init(&wdt->lock);
wdt->ping = max63xx_mmap_ping;
wdt->set = max63xx_mmap_set;
return 0;
}
static int max63xx_wdt_probe(struct platform_device *pdev)
{
struct max63xx_wdt *wdt;
struct max63xx_timeout *table;
int err;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
table = (struct max63xx_timeout *)pdev->id_entry->driver_data;
if (heartbeat < 1 || heartbeat > MAX_HEARTBEAT)
heartbeat = DEFAULT_HEARTBEAT;
wdt->timeout = max63xx_select_timeout(table, heartbeat);
if (!wdt->timeout) {
dev_err(&pdev->dev, "unable to satisfy %ds heartbeat request\n",
heartbeat);
return -EINVAL;
}
err = max63xx_mmap_init(pdev, wdt);
if (err)
return err;
platform_set_drvdata(pdev, &wdt->wdd);
watchdog_set_drvdata(&wdt->wdd, wdt);
wdt->wdd.parent = &pdev->dev;
wdt->wdd.timeout = wdt->timeout->twd;
wdt->wdd.info = &max63xx_wdt_info;
wdt->wdd.ops = &max63xx_wdt_ops;
watchdog_set_nowayout(&wdt->wdd, nowayout);
err = watchdog_register_device(&wdt->wdd);
if (err)
return err;
dev_info(&pdev->dev, "using %ds heartbeat with %ds initial delay\n",
wdt->timeout->twd, wdt->timeout->tdelay);
return 0;
}
static int max63xx_wdt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdd = platform_get_drvdata(pdev);
watchdog_unregister_device(wdd);
return 0;
}
