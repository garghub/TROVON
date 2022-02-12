static inline u32 nic7018_timeout(u32 period, u8 counter)
{
return period * counter - period / 2;
}
static const struct nic7018_config *nic7018_get_config(u32 timeout,
u8 *counter)
{
const struct nic7018_config *config;
u8 count;
if (timeout < 30 && timeout != 16) {
config = &nic7018_configs[0];
count = timeout / 2 + 1;
} else {
config = &nic7018_configs[1];
count = DIV_ROUND_UP(timeout + 16, 32);
if (count > WDT_MAX_COUNTER)
count = WDT_MAX_COUNTER;
}
*counter = count;
return config;
}
static int nic7018_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct nic7018_wdt *wdt = watchdog_get_drvdata(wdd);
const struct nic7018_config *config;
u8 counter;
config = nic7018_get_config(timeout, &counter);
outb(counter << 4 | config->divider,
wdt->io_base + WDT_PRESET_PRESCALE);
wdd->timeout = nic7018_timeout(config->period, counter);
wdt->period = config->period;
return 0;
}
static int nic7018_start(struct watchdog_device *wdd)
{
struct nic7018_wdt *wdt = watchdog_get_drvdata(wdd);
u8 control;
nic7018_set_timeout(wdd, wdd->timeout);
control = inb(wdt->io_base + WDT_RELOAD_CTRL);
outb(control | WDT_RELOAD_PORT_EN, wdt->io_base + WDT_RELOAD_CTRL);
outb(1, wdt->io_base + WDT_RELOAD_PORT);
control = inb(wdt->io_base + WDT_CTRL);
outb(control | WDT_CTRL_RESET_EN, wdt->io_base + WDT_CTRL);
return 0;
}
static int nic7018_stop(struct watchdog_device *wdd)
{
struct nic7018_wdt *wdt = watchdog_get_drvdata(wdd);
outb(0, wdt->io_base + WDT_CTRL);
outb(0, wdt->io_base + WDT_RELOAD_CTRL);
outb(0xF0, wdt->io_base + WDT_PRESET_PRESCALE);
return 0;
}
static int nic7018_ping(struct watchdog_device *wdd)
{
struct nic7018_wdt *wdt = watchdog_get_drvdata(wdd);
outb(1, wdt->io_base + WDT_RELOAD_PORT);
return 0;
}
static unsigned int nic7018_get_timeleft(struct watchdog_device *wdd)
{
struct nic7018_wdt *wdt = watchdog_get_drvdata(wdd);
u8 count;
count = inb(wdt->io_base + WDT_COUNT) & 0xF;
if (!count)
return 0;
return nic7018_timeout(wdt->period, count);
}
static int nic7018_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct watchdog_device *wdd;
struct nic7018_wdt *wdt;
struct resource *io_rc;
int ret;
wdt = devm_kzalloc(dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
platform_set_drvdata(pdev, wdt);
io_rc = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!io_rc) {
dev_err(dev, "missing IO resources\n");
return -EINVAL;
}
if (!devm_request_region(dev, io_rc->start, resource_size(io_rc),
KBUILD_MODNAME)) {
dev_err(dev, "failed to get IO region\n");
return -EBUSY;
}
wdt->io_base = io_rc->start;
wdd = &wdt->wdd;
wdd->info = &nic7018_wdd_info;
wdd->ops = &nic7018_wdd_ops;
wdd->min_timeout = WDT_MIN_TIMEOUT;
wdd->max_timeout = WDT_MAX_TIMEOUT;
wdd->timeout = WDT_DEFAULT_TIMEOUT;
wdd->parent = dev;
watchdog_set_drvdata(wdd, wdt);
watchdog_set_nowayout(wdd, nowayout);
ret = watchdog_init_timeout(wdd, timeout, dev);
if (ret)
dev_warn(dev, "unable to set timeout value, using default\n");
outb(UNLOCK, wdt->io_base + WDT_REG_LOCK);
ret = watchdog_register_device(wdd);
if (ret) {
outb(LOCK, wdt->io_base + WDT_REG_LOCK);
dev_err(dev, "failed to register watchdog\n");
return ret;
}
dev_dbg(dev, "io_base=0x%04X, timeout=%d, nowayout=%d\n",
wdt->io_base, timeout, nowayout);
return 0;
}
static int nic7018_remove(struct platform_device *pdev)
{
struct nic7018_wdt *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&wdt->wdd);
outb(LOCK, wdt->io_base + WDT_REG_LOCK);
return 0;
}
