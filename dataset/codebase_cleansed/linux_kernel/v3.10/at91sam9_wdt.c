static inline void at91_wdt_reset(void)
{
wdt_write(AT91_WDT_CR, AT91_WDT_KEY | AT91_WDT_WDRSTT);
}
static void at91_ping(unsigned long data)
{
if (time_before(jiffies, at91wdt_private.next_heartbeat) ||
(!watchdog_active(&at91_wdt_dev))) {
at91_wdt_reset();
mod_timer(&at91wdt_private.timer, jiffies + WDT_TIMEOUT);
} else
pr_crit("I will reset your machine !\n");
}
static int at91_wdt_ping(struct watchdog_device *wdd)
{
at91wdt_private.next_heartbeat = jiffies + wdd->timeout * HZ;
return 0;
}
static int at91_wdt_start(struct watchdog_device *wdd)
{
at91_wdt_ping(wdd);
mod_timer(&at91wdt_private.timer, jiffies + WDT_TIMEOUT);
return 0;
}
static int at91_wdt_stop(struct watchdog_device *wdd)
{
return 0;
}
static int at91_wdt_set_timeout(struct watchdog_device *wdd, unsigned int new_timeout)
{
wdd->timeout = new_timeout;
return 0;
}
static int at91_wdt_settimeout(unsigned int timeout)
{
unsigned int reg;
unsigned int mr;
mr = wdt_read(AT91_WDT_MR);
if (mr & AT91_WDT_WDDIS) {
pr_err("sorry, watchdog is disabled\n");
return -EIO;
}
reg = AT91_WDT_WDRSTEN
| AT91_WDT_WDDBGHLT
| AT91_WDT_WDD
| (timeout & AT91_WDT_WDV);
wdt_write(AT91_WDT_MR, reg);
return 0;
}
static int __init at91wdt_probe(struct platform_device *pdev)
{
struct resource *r;
int res;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r)
return -ENODEV;
at91wdt_private.base = ioremap(r->start, resource_size(r));
if (!at91wdt_private.base) {
dev_err(&pdev->dev, "failed to map registers, aborting.\n");
return -ENOMEM;
}
at91_wdt_dev.parent = &pdev->dev;
watchdog_init_timeout(&at91_wdt_dev, heartbeat, &pdev->dev);
watchdog_set_nowayout(&at91_wdt_dev, nowayout);
res = at91_wdt_settimeout(ms_to_ticks(WDT_HW_TIMEOUT * 1000));
if (res)
return res;
res = watchdog_register_device(&at91_wdt_dev);
if (res)
return res;
at91wdt_private.next_heartbeat = jiffies + at91_wdt_dev.timeout * HZ;
setup_timer(&at91wdt_private.timer, at91_ping, 0);
mod_timer(&at91wdt_private.timer, jiffies + WDT_TIMEOUT);
pr_info("enabled (heartbeat=%d sec, nowayout=%d)\n",
at91_wdt_dev.timeout, nowayout);
return 0;
}
static int __exit at91wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&at91_wdt_dev);
pr_warn("I quit now, hardware will probably reboot!\n");
del_timer(&at91wdt_private.timer);
return 0;
}
