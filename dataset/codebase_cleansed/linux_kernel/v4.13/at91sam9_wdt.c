static irqreturn_t wdt_interrupt(int irq, void *dev_id)
{
struct at91wdt *wdt = (struct at91wdt *)dev_id;
if (wdt_read(wdt, AT91_WDT_SR)) {
pr_crit("at91sam9 WDT software reset\n");
emergency_restart();
pr_crit("Reboot didn't ?????\n");
}
return IRQ_HANDLED;
}
static inline void at91_wdt_reset(struct at91wdt *wdt)
{
wdt_write(wdt, AT91_WDT_CR, AT91_WDT_KEY | AT91_WDT_WDRSTT);
}
static void at91_ping(unsigned long data)
{
struct at91wdt *wdt = (struct at91wdt *)data;
if (time_before(jiffies, wdt->next_heartbeat) ||
!watchdog_active(&wdt->wdd)) {
at91_wdt_reset(wdt);
mod_timer(&wdt->timer, jiffies + wdt->heartbeat);
} else {
pr_crit("I will reset your machine !\n");
}
}
static int at91_wdt_start(struct watchdog_device *wdd)
{
struct at91wdt *wdt = to_wdt(wdd);
wdt->next_heartbeat = jiffies + wdd->timeout * HZ;
return 0;
}
static int at91_wdt_stop(struct watchdog_device *wdd)
{
return 0;
}
static int at91_wdt_set_timeout(struct watchdog_device *wdd, unsigned int new_timeout)
{
wdd->timeout = new_timeout;
return at91_wdt_start(wdd);
}
static int at91_wdt_init(struct platform_device *pdev, struct at91wdt *wdt)
{
u32 tmp;
u32 delta;
u32 value;
int err;
u32 mask = wdt->mr_mask;
unsigned long min_heartbeat = 1;
unsigned long max_heartbeat;
struct device *dev = &pdev->dev;
tmp = wdt_read(wdt, AT91_WDT_MR);
if ((tmp & mask) != (wdt->mr & mask)) {
if (tmp == WDT_MR_RESET) {
wdt_write(wdt, AT91_WDT_MR, wdt->mr);
tmp = wdt_read(wdt, AT91_WDT_MR);
}
}
if (tmp & AT91_WDT_WDDIS) {
if (wdt->mr & AT91_WDT_WDDIS)
return 0;
dev_err(dev, "watchdog is disabled\n");
return -EINVAL;
}
value = tmp & AT91_WDT_WDV;
delta = (tmp & AT91_WDT_WDD) >> 16;
if (delta < value)
min_heartbeat = ticks_to_hz_roundup(value - delta);
max_heartbeat = ticks_to_hz_rounddown(value);
if (!max_heartbeat) {
dev_err(dev,
"heartbeat is too small for the system to handle it correctly\n");
return -EINVAL;
}
if ((max_heartbeat / 4) >= min_heartbeat)
wdt->heartbeat = max_heartbeat / 4;
else if ((max_heartbeat / 2) >= min_heartbeat)
wdt->heartbeat = max_heartbeat / 2;
else
wdt->heartbeat = min_heartbeat;
if (max_heartbeat < min_heartbeat + 4)
dev_warn(dev,
"min heartbeat and max heartbeat might be too close for the system to handle it correctly\n");
if ((tmp & AT91_WDT_WDFIEN) && wdt->irq) {
err = request_irq(wdt->irq, wdt_interrupt,
IRQF_SHARED | IRQF_IRQPOLL |
IRQF_NO_SUSPEND,
pdev->name, wdt);
if (err)
return err;
}
if ((tmp & wdt->mr_mask) != (wdt->mr & wdt->mr_mask))
dev_warn(dev,
"watchdog already configured differently (mr = %x expecting %x)\n",
tmp & wdt->mr_mask, wdt->mr & wdt->mr_mask);
setup_timer(&wdt->timer, at91_ping, (unsigned long)wdt);
mod_timer(&wdt->timer, jiffies + min_heartbeat);
if (watchdog_init_timeout(&wdt->wdd, 0, dev))
watchdog_init_timeout(&wdt->wdd, heartbeat, dev);
watchdog_set_nowayout(&wdt->wdd, wdt->nowayout);
err = watchdog_register_device(&wdt->wdd);
if (err)
goto out_stop_timer;
wdt->next_heartbeat = jiffies + wdt->wdd.timeout * HZ;
return 0;
out_stop_timer:
del_timer(&wdt->timer);
return err;
}
static int of_at91wdt_init(struct device_node *np, struct at91wdt *wdt)
{
u32 min = 0;
u32 max = WDT_COUNTER_MAX_SECS;
const char *tmp;
wdt->irq = irq_of_parse_and_map(np, 0);
if (!wdt->irq)
dev_warn(wdt->wdd.parent, "failed to get IRQ from DT\n");
if (!of_property_read_u32_index(np, "atmel,max-heartbeat-sec", 0,
&max)) {
if (!max || max > WDT_COUNTER_MAX_SECS)
max = WDT_COUNTER_MAX_SECS;
if (!of_property_read_u32_index(np, "atmel,min-heartbeat-sec",
0, &min)) {
if (min >= max)
min = max - 1;
}
}
min = secs_to_ticks(min);
max = secs_to_ticks(max);
wdt->mr_mask = 0x3FFFFFFF;
wdt->mr = 0;
if (!of_property_read_string(np, "atmel,watchdog-type", &tmp) &&
!strcmp(tmp, "software")) {
wdt->mr |= AT91_WDT_WDFIEN;
wdt->mr_mask &= ~AT91_WDT_WDRPROC;
} else {
wdt->mr |= AT91_WDT_WDRSTEN;
}
if (!of_property_read_string(np, "atmel,reset-type", &tmp) &&
!strcmp(tmp, "proc"))
wdt->mr |= AT91_WDT_WDRPROC;
if (of_property_read_bool(np, "atmel,disable")) {
wdt->mr |= AT91_WDT_WDDIS;
wdt->mr_mask &= AT91_WDT_WDDIS;
}
if (of_property_read_bool(np, "atmel,idle-halt"))
wdt->mr |= AT91_WDT_WDIDLEHLT;
if (of_property_read_bool(np, "atmel,dbg-halt"))
wdt->mr |= AT91_WDT_WDDBGHLT;
wdt->mr |= max | ((max - min) << 16);
return 0;
}
static inline int of_at91wdt_init(struct device_node *np, struct at91wdt *wdt)
{
return 0;
}
static int __init at91wdt_probe(struct platform_device *pdev)
{
struct resource *r;
int err;
struct at91wdt *wdt;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdt->mr = (WDT_HW_TIMEOUT * 256) | AT91_WDT_WDRSTEN | AT91_WDT_WDD |
AT91_WDT_WDDBGHLT | AT91_WDT_WDIDLEHLT;
wdt->mr_mask = 0x3FFFFFFF;
wdt->nowayout = nowayout;
wdt->wdd.parent = &pdev->dev;
wdt->wdd.info = &at91_wdt_info;
wdt->wdd.ops = &at91_wdt_ops;
wdt->wdd.timeout = WDT_HEARTBEAT;
wdt->wdd.min_timeout = 1;
wdt->wdd.max_timeout = 0xFFFF;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(wdt->base))
return PTR_ERR(wdt->base);
wdt->sclk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(wdt->sclk))
return PTR_ERR(wdt->sclk);
err = clk_prepare_enable(wdt->sclk);
if (err) {
dev_err(&pdev->dev, "Could not enable slow clock\n");
return err;
}
if (pdev->dev.of_node) {
err = of_at91wdt_init(pdev->dev.of_node, wdt);
if (err)
goto err_clk;
}
err = at91_wdt_init(pdev, wdt);
if (err)
goto err_clk;
platform_set_drvdata(pdev, wdt);
pr_info("enabled (heartbeat=%d sec, nowayout=%d)\n",
wdt->wdd.timeout, wdt->nowayout);
return 0;
err_clk:
clk_disable_unprepare(wdt->sclk);
return err;
}
static int __exit at91wdt_remove(struct platform_device *pdev)
{
struct at91wdt *wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&wdt->wdd);
pr_warn("I quit now, hardware will probably reboot!\n");
del_timer(&wdt->timer);
clk_disable_unprepare(wdt->sclk);
return 0;
}
