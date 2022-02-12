static inline struct bcm47xx_wdt *bcm47xx_wdt_get(struct watchdog_device *wdd)
{
return container_of(wdd, struct bcm47xx_wdt, wdd);
}
static int bcm47xx_wdt_hard_keepalive(struct watchdog_device *wdd)
{
struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);
wdt->timer_set_ms(wdt, wdd->timeout * 1000);
return 0;
}
static int bcm47xx_wdt_hard_start(struct watchdog_device *wdd)
{
return 0;
}
static int bcm47xx_wdt_hard_stop(struct watchdog_device *wdd)
{
struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);
wdt->timer_set(wdt, 0);
return 0;
}
static int bcm47xx_wdt_hard_set_timeout(struct watchdog_device *wdd,
unsigned int new_time)
{
struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);
u32 max_timer = wdt->max_timer_ms;
if (new_time < 1 || new_time > max_timer / 1000) {
pr_warn("timeout value must be 1<=x<=%d, using %d\n",
max_timer / 1000, new_time);
return -EINVAL;
}
wdd->timeout = new_time;
return 0;
}
static int bcm47xx_wdt_restart(struct watchdog_device *wdd,
unsigned long action, void *data)
{
struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);
wdt->timer_set(wdt, 1);
return 0;
}
static void bcm47xx_wdt_soft_timer_tick(unsigned long data)
{
struct bcm47xx_wdt *wdt = (struct bcm47xx_wdt *)data;
u32 next_tick = min(wdt->wdd.timeout * 1000, wdt->max_timer_ms);
if (!atomic_dec_and_test(&wdt->soft_ticks)) {
wdt->timer_set_ms(wdt, next_tick);
mod_timer(&wdt->soft_timer, jiffies + HZ);
} else {
pr_crit("Watchdog will fire soon!!!\n");
}
}
static int bcm47xx_wdt_soft_keepalive(struct watchdog_device *wdd)
{
struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);
atomic_set(&wdt->soft_ticks, wdd->timeout);
return 0;
}
static int bcm47xx_wdt_soft_start(struct watchdog_device *wdd)
{
struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);
bcm47xx_wdt_soft_keepalive(wdd);
bcm47xx_wdt_soft_timer_tick((unsigned long)wdt);
return 0;
}
static int bcm47xx_wdt_soft_stop(struct watchdog_device *wdd)
{
struct bcm47xx_wdt *wdt = bcm47xx_wdt_get(wdd);
del_timer_sync(&wdt->soft_timer);
wdt->timer_set(wdt, 0);
return 0;
}
static int bcm47xx_wdt_soft_set_timeout(struct watchdog_device *wdd,
unsigned int new_time)
{
if (new_time < 1 || new_time > WDT_SOFTTIMER_MAX) {
pr_warn("timeout value must be 1<=x<=%d, using %d\n",
WDT_SOFTTIMER_MAX, new_time);
return -EINVAL;
}
wdd->timeout = new_time;
return 0;
}
static int bcm47xx_wdt_probe(struct platform_device *pdev)
{
int ret;
bool soft;
struct bcm47xx_wdt *wdt = dev_get_platdata(&pdev->dev);
if (!wdt)
return -ENXIO;
soft = wdt->max_timer_ms < WDT_SOFTTIMER_THRESHOLD * 1000;
if (soft) {
wdt->wdd.ops = &bcm47xx_wdt_soft_ops;
setup_timer(&wdt->soft_timer, bcm47xx_wdt_soft_timer_tick,
(long unsigned int)wdt);
} else {
wdt->wdd.ops = &bcm47xx_wdt_hard_ops;
}
wdt->wdd.info = &bcm47xx_wdt_info;
wdt->wdd.timeout = WDT_DEFAULT_TIME;
wdt->wdd.parent = &pdev->dev;
ret = wdt->wdd.ops->set_timeout(&wdt->wdd, timeout);
if (ret)
goto err_timer;
watchdog_set_nowayout(&wdt->wdd, nowayout);
watchdog_set_restart_priority(&wdt->wdd, 64);
watchdog_stop_on_reboot(&wdt->wdd);
ret = watchdog_register_device(&wdt->wdd);
if (ret)
goto err_timer;
dev_info(&pdev->dev, "BCM47xx Watchdog Timer enabled (%d seconds%s%s)\n",
timeout, nowayout ? ", nowayout" : "",
soft ? ", Software Timer" : "");
return 0;
err_timer:
if (soft)
del_timer_sync(&wdt->soft_timer);
return ret;
}
static int bcm47xx_wdt_remove(struct platform_device *pdev)
{
struct bcm47xx_wdt *wdt = dev_get_platdata(&pdev->dev);
watchdog_unregister_device(&wdt->wdd);
return 0;
}
