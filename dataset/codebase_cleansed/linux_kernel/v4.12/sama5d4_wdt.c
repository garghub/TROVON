static void wdt_write(struct sama5d4_wdt *wdt, u32 field, u32 val)
{
while (time_before(jiffies, wdt->last_ping + WDT_DELAY))
usleep_range(30, 125);
writel_relaxed(val, wdt->reg_base + field);
wdt->last_ping = jiffies;
}
static void wdt_write_nosleep(struct sama5d4_wdt *wdt, u32 field, u32 val)
{
if (time_before(jiffies, wdt->last_ping + WDT_DELAY))
udelay(123);
writel_relaxed(val, wdt->reg_base + field);
wdt->last_ping = jiffies;
}
static int sama5d4_wdt_start(struct watchdog_device *wdd)
{
struct sama5d4_wdt *wdt = watchdog_get_drvdata(wdd);
wdt->mr &= ~AT91_WDT_WDDIS;
wdt_write(wdt, AT91_WDT_MR, wdt->mr);
return 0;
}
static int sama5d4_wdt_stop(struct watchdog_device *wdd)
{
struct sama5d4_wdt *wdt = watchdog_get_drvdata(wdd);
wdt->mr |= AT91_WDT_WDDIS;
wdt_write(wdt, AT91_WDT_MR, wdt->mr);
return 0;
}
static int sama5d4_wdt_ping(struct watchdog_device *wdd)
{
struct sama5d4_wdt *wdt = watchdog_get_drvdata(wdd);
wdt_write(wdt, AT91_WDT_CR, AT91_WDT_KEY | AT91_WDT_WDRSTT);
return 0;
}
static int sama5d4_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct sama5d4_wdt *wdt = watchdog_get_drvdata(wdd);
u32 value = WDT_SEC2TICKS(timeout);
wdt->mr &= ~AT91_WDT_WDV;
wdt->mr &= ~AT91_WDT_WDD;
wdt->mr |= AT91_WDT_SET_WDV(value);
wdt->mr |= AT91_WDT_SET_WDD(value);
if (wdt_enabled)
wdt_write(wdt, AT91_WDT_MR, wdt->mr & ~AT91_WDT_WDDIS);
wdd->timeout = timeout;
return 0;
}
static irqreturn_t sama5d4_wdt_irq_handler(int irq, void *dev_id)
{
struct sama5d4_wdt *wdt = platform_get_drvdata(dev_id);
if (wdt_read(wdt, AT91_WDT_SR)) {
pr_crit("Atmel Watchdog Software Reset\n");
emergency_restart();
pr_crit("Reboot didn't succeed\n");
}
return IRQ_HANDLED;
}
static int of_sama5d4_wdt_init(struct device_node *np, struct sama5d4_wdt *wdt)
{
const char *tmp;
wdt->mr = AT91_WDT_WDDIS;
if (!of_property_read_string(np, "atmel,watchdog-type", &tmp) &&
!strcmp(tmp, "software"))
wdt->mr |= AT91_WDT_WDFIEN;
else
wdt->mr |= AT91_WDT_WDRSTEN;
if (of_property_read_bool(np, "atmel,idle-halt"))
wdt->mr |= AT91_WDT_WDIDLEHLT;
if (of_property_read_bool(np, "atmel,dbg-halt"))
wdt->mr |= AT91_WDT_WDDBGHLT;
return 0;
}
static int sama5d4_wdt_init(struct sama5d4_wdt *wdt)
{
u32 reg;
if (wdt_enabled) {
wdt_write_nosleep(wdt, AT91_WDT_MR, wdt->mr);
} else {
reg = wdt_read(wdt, AT91_WDT_MR);
if (!(reg & AT91_WDT_WDDIS))
wdt_write_nosleep(wdt, AT91_WDT_MR,
reg | AT91_WDT_WDDIS);
}
return 0;
}
static int sama5d4_wdt_probe(struct platform_device *pdev)
{
struct watchdog_device *wdd;
struct sama5d4_wdt *wdt;
struct resource *res;
void __iomem *regs;
u32 irq = 0;
u32 timeout;
int ret;
wdt = devm_kzalloc(&pdev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
wdd = &wdt->wdd;
wdd->timeout = wdt_timeout;
wdd->info = &sama5d4_wdt_info;
wdd->ops = &sama5d4_wdt_ops;
wdd->min_timeout = MIN_WDT_TIMEOUT;
wdd->max_timeout = MAX_WDT_TIMEOUT;
wdt->last_ping = jiffies;
watchdog_set_drvdata(wdd, wdt);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
wdt->reg_base = regs;
if (pdev->dev.of_node) {
irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
if (!irq)
dev_warn(&pdev->dev, "failed to get IRQ from DT\n");
ret = of_sama5d4_wdt_init(pdev->dev.of_node, wdt);
if (ret)
return ret;
}
if ((wdt->mr & AT91_WDT_WDFIEN) && irq) {
ret = devm_request_irq(&pdev->dev, irq, sama5d4_wdt_irq_handler,
IRQF_SHARED | IRQF_IRQPOLL |
IRQF_NO_SUSPEND, pdev->name, pdev);
if (ret) {
dev_err(&pdev->dev,
"cannot register interrupt handler\n");
return ret;
}
}
ret = watchdog_init_timeout(wdd, wdt_timeout, &pdev->dev);
if (ret) {
dev_err(&pdev->dev, "unable to set timeout value\n");
return ret;
}
timeout = WDT_SEC2TICKS(wdd->timeout);
wdt->mr |= AT91_WDT_SET_WDD(timeout);
wdt->mr |= AT91_WDT_SET_WDV(timeout);
ret = sama5d4_wdt_init(wdt);
if (ret)
return ret;
watchdog_set_nowayout(wdd, nowayout);
ret = watchdog_register_device(wdd);
if (ret) {
dev_err(&pdev->dev, "failed to register watchdog device\n");
return ret;
}
platform_set_drvdata(pdev, wdt);
dev_info(&pdev->dev, "initialized (timeout = %d sec, nowayout = %d)\n",
wdt_timeout, nowayout);
return 0;
}
static int sama5d4_wdt_remove(struct platform_device *pdev)
{
struct sama5d4_wdt *wdt = platform_get_drvdata(pdev);
sama5d4_wdt_stop(&wdt->wdd);
watchdog_unregister_device(&wdt->wdd);
return 0;
}
static int sama5d4_wdt_resume(struct device *dev)
{
struct sama5d4_wdt *wdt = dev_get_drvdata(dev);
sama5d4_wdt_init(wdt);
return 0;
}
