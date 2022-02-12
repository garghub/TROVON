static void coh901327_enable(u16 timeout)
{
u16 val;
unsigned long freq;
unsigned long delay_ns;
val = readw(virtbase + U300_WDOG_D2R);
if (val == U300_WDOG_D2R_DISABLE_STATUS_DISABLED)
writew(U300_WDOG_RR_RESTART_VALUE_RESUME,
virtbase + U300_WDOG_RR);
writew(U300_WDOG_IER_WILL_BARK_IRQ_ACK_ENABLE,
virtbase + U300_WDOG_IER);
freq = clk_get_rate(clk);
delay_ns = DIV_ROUND_UP(1000000000, freq);
delay_ns = 3 * delay_ns;
ndelay(delay_ns);
writew(U300_WDOG_IMR_WILL_BARK_IRQ_ENABLE, virtbase + U300_WDOG_IMR);
writew(timeout, virtbase + U300_WDOG_TR);
writew(U300_WDOG_FR_FEED_RESTART_TIMER, virtbase + U300_WDOG_FR);
(void) readw(virtbase + U300_WDOG_CR);
val = readw(virtbase + U300_WDOG_D2R);
if (val != U300_WDOG_D2R_DISABLE_STATUS_ENABLED)
dev_err(parent,
"%s(): watchdog not enabled! D2R value %04x\n",
__func__, val);
}
static void coh901327_disable(void)
{
u16 val;
writew(0x0000U, virtbase + U300_WDOG_IMR);
val = readw(virtbase + U300_WDOG_D2R);
if (val != U300_WDOG_D2R_DISABLE_STATUS_DISABLED) {
writew(U300_WDOG_D1R_DISABLE1_DISABLE_TIMER,
virtbase + U300_WDOG_D1R);
writew(U300_WDOG_D2R_DISABLE2_DISABLE_TIMER,
virtbase + U300_WDOG_D2R);
writew(U300_WDOG_D2R_DISABLE2_DISABLE_TIMER,
virtbase + U300_WDOG_D2R);
}
val = readw(virtbase + U300_WDOG_D2R);
if (val != U300_WDOG_D2R_DISABLE_STATUS_DISABLED)
dev_err(parent,
"%s(): watchdog not disabled! D2R value %04x\n",
__func__, val);
}
static int coh901327_start(struct watchdog_device *wdt_dev)
{
coh901327_enable(wdt_dev->timeout * 100);
return 0;
}
static int coh901327_stop(struct watchdog_device *wdt_dev)
{
coh901327_disable();
return 0;
}
static int coh901327_ping(struct watchdog_device *wdd)
{
writew(U300_WDOG_FR_FEED_RESTART_TIMER,
virtbase + U300_WDOG_FR);
return 0;
}
static int coh901327_settimeout(struct watchdog_device *wdt_dev,
unsigned int time)
{
wdt_dev->timeout = time;
writew(time * 100, virtbase + U300_WDOG_TR);
writew(U300_WDOG_FR_FEED_RESTART_TIMER,
virtbase + U300_WDOG_FR);
return 0;
}
static unsigned int coh901327_gettimeleft(struct watchdog_device *wdt_dev)
{
u16 val;
val = readw(virtbase + U300_WDOG_CR);
while (val & U300_WDOG_CR_VALID_IND)
val = readw(virtbase + U300_WDOG_CR);
val &= U300_WDOG_CR_COUNT_VALUE_MASK;
if (val != 0)
val /= 100;
return val;
}
static irqreturn_t coh901327_interrupt(int irq, void *data)
{
u16 val;
val = readw(virtbase + U300_WDOG_IER);
if (val == U300_WDOG_IER_WILL_BARK_IRQ_EVENT_IND)
writew(U300_WDOG_IER_WILL_BARK_IRQ_ACK_ENABLE,
virtbase + U300_WDOG_IER);
writew(0x0000U, virtbase + U300_WDOG_IMR);
dev_crit(parent, "watchdog is barking!\n");
return IRQ_HANDLED;
}
static int __exit coh901327_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&coh901327_wdt);
coh901327_disable();
free_irq(irq, pdev);
clk_disable_unprepare(clk);
clk_put(clk);
return 0;
}
static int __init coh901327_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int ret;
u16 val;
struct resource *res;
parent = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
virtbase = devm_ioremap_resource(dev, res);
if (IS_ERR(virtbase))
return PTR_ERR(virtbase);
clk = clk_get(dev, NULL);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
dev_err(dev, "could not get clock\n");
return ret;
}
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(dev, "could not prepare and enable clock\n");
goto out_no_clk_enable;
}
val = readw(virtbase + U300_WDOG_SR);
switch (val) {
case U300_WDOG_SR_STATUS_TIMED_OUT:
dev_info(dev, "watchdog timed out since last chip reset!\n");
coh901327_wdt.bootstatus |= WDIOF_CARDRESET;
break;
case U300_WDOG_SR_STATUS_NORMAL:
dev_info(dev, "in normal status, no timeouts have occurred.\n");
break;
default:
dev_info(dev, "contains an illegal status code (%08x)\n", val);
break;
}
val = readw(virtbase + U300_WDOG_D2R);
switch (val) {
case U300_WDOG_D2R_DISABLE_STATUS_DISABLED:
dev_info(dev, "currently disabled.\n");
break;
case U300_WDOG_D2R_DISABLE_STATUS_ENABLED:
dev_info(dev, "currently enabled! (disabling it now)\n");
coh901327_disable();
break;
default:
dev_err(dev, "contains an illegal enable/disable code (%08x)\n",
val);
break;
}
writew(U300_WDOG_SR_RESET_STATUS_RESET, virtbase + U300_WDOG_SR);
irq = platform_get_irq(pdev, 0);
if (request_irq(irq, coh901327_interrupt, 0,
DRV_NAME " Bark", pdev)) {
ret = -EIO;
goto out_no_irq;
}
ret = watchdog_init_timeout(&coh901327_wdt, margin, dev);
if (ret < 0)
coh901327_wdt.timeout = 60;
coh901327_wdt.parent = dev;
ret = watchdog_register_device(&coh901327_wdt);
if (ret)
goto out_no_wdog;
dev_info(dev, "initialized. timer margin=%d sec\n", margin);
return 0;
out_no_wdog:
free_irq(irq, pdev);
out_no_irq:
clk_disable_unprepare(clk);
out_no_clk_enable:
clk_put(clk);
return ret;
}
static int coh901327_suspend(struct platform_device *pdev, pm_message_t state)
{
irqmaskstore = readw(virtbase + U300_WDOG_IMR) & 0x0001U;
wdogenablestore = readw(virtbase + U300_WDOG_D2R);
if (wdogenablestore == U300_WDOG_D2R_DISABLE_STATUS_ENABLED)
coh901327_disable();
return 0;
}
static int coh901327_resume(struct platform_device *pdev)
{
writew(irqmaskstore, virtbase + U300_WDOG_IMR);
if (wdogenablestore == U300_WDOG_D2R_DISABLE_STATUS_ENABLED) {
writew(U300_WDOG_RR_RESTART_VALUE_RESUME,
virtbase + U300_WDOG_RR);
writew(U300_WDOG_FR_FEED_RESTART_TIMER,
virtbase + U300_WDOG_FR);
}
return 0;
}
void coh901327_watchdog_reset(void)
{
writew(U300_WDOG_JOR_JTAG_WATCHDOG_ENABLE,
virtbase + U300_WDOG_JOR);
coh901327_enable(500);
}
