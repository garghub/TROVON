static int s3c2410wdt_keepalive(struct watchdog_device *wdd)
{
spin_lock(&wdt_lock);
writel(wdt_count, wdt_base + S3C2410_WTCNT);
spin_unlock(&wdt_lock);
return 0;
}
static void __s3c2410wdt_stop(void)
{
unsigned long wtcon;
wtcon = readl(wdt_base + S3C2410_WTCON);
wtcon &= ~(S3C2410_WTCON_ENABLE | S3C2410_WTCON_RSTEN);
writel(wtcon, wdt_base + S3C2410_WTCON);
}
static int s3c2410wdt_stop(struct watchdog_device *wdd)
{
spin_lock(&wdt_lock);
__s3c2410wdt_stop();
spin_unlock(&wdt_lock);
return 0;
}
static int s3c2410wdt_start(struct watchdog_device *wdd)
{
unsigned long wtcon;
spin_lock(&wdt_lock);
__s3c2410wdt_stop();
wtcon = readl(wdt_base + S3C2410_WTCON);
wtcon |= S3C2410_WTCON_ENABLE | S3C2410_WTCON_DIV128;
if (soft_noboot) {
wtcon |= S3C2410_WTCON_INTEN;
wtcon &= ~S3C2410_WTCON_RSTEN;
} else {
wtcon &= ~S3C2410_WTCON_INTEN;
wtcon |= S3C2410_WTCON_RSTEN;
}
DBG("%s: wdt_count=0x%08x, wtcon=%08lx\n",
__func__, wdt_count, wtcon);
writel(wdt_count, wdt_base + S3C2410_WTDAT);
writel(wdt_count, wdt_base + S3C2410_WTCNT);
writel(wtcon, wdt_base + S3C2410_WTCON);
spin_unlock(&wdt_lock);
return 0;
}
static inline int s3c2410wdt_is_running(void)
{
return readl(wdt_base + S3C2410_WTCON) & S3C2410_WTCON_ENABLE;
}
static int s3c2410wdt_set_heartbeat(struct watchdog_device *wdd, unsigned timeout)
{
unsigned long freq = clk_get_rate(wdt_clock);
unsigned int count;
unsigned int divisor = 1;
unsigned long wtcon;
if (timeout < 1)
return -EINVAL;
freq /= 128;
count = timeout * freq;
DBG("%s: count=%d, timeout=%d, freq=%lu\n",
__func__, count, timeout, freq);
if (count >= 0x10000) {
for (divisor = 1; divisor <= 0x100; divisor++) {
if ((count / divisor) < 0x10000)
break;
}
if ((count / divisor) >= 0x10000) {
dev_err(wdt_dev, "timeout %d too big\n", timeout);
return -EINVAL;
}
}
DBG("%s: timeout=%d, divisor=%d, count=%d (%08x)\n",
__func__, timeout, divisor, count, count/divisor);
count /= divisor;
wdt_count = count;
wtcon = readl(wdt_base + S3C2410_WTCON);
wtcon &= ~S3C2410_WTCON_PRESCALE_MASK;
wtcon |= S3C2410_WTCON_PRESCALE(divisor-1);
writel(count, wdt_base + S3C2410_WTDAT);
writel(wtcon, wdt_base + S3C2410_WTCON);
return 0;
}
static irqreturn_t s3c2410wdt_irq(int irqno, void *param)
{
dev_info(wdt_dev, "watchdog timer expired (irq)\n");
s3c2410wdt_keepalive(&s3c2410_wdd);
return IRQ_HANDLED;
}
static int s3c2410wdt_cpufreq_transition(struct notifier_block *nb,
unsigned long val, void *data)
{
int ret;
if (!s3c2410wdt_is_running())
goto done;
if (val == CPUFREQ_PRECHANGE) {
s3c2410wdt_keepalive(&s3c2410_wdd);
} else if (val == CPUFREQ_POSTCHANGE) {
s3c2410wdt_stop(&s3c2410_wdd);
ret = s3c2410wdt_set_heartbeat(&s3c2410_wdd, s3c2410_wdd.timeout);
if (ret >= 0)
s3c2410wdt_start(&s3c2410_wdd);
else
goto err;
}
done:
return 0;
err:
dev_err(wdt_dev, "cannot set new value for timeout %d\n",
s3c2410_wdd.timeout);
return ret;
}
static inline int s3c2410wdt_cpufreq_register(void)
{
return cpufreq_register_notifier(&s3c2410wdt_cpufreq_transition_nb,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline void s3c2410wdt_cpufreq_deregister(void)
{
cpufreq_unregister_notifier(&s3c2410wdt_cpufreq_transition_nb,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline int s3c2410wdt_cpufreq_register(void)
{
return 0;
}
static inline void s3c2410wdt_cpufreq_deregister(void)
{
}
static int __devinit s3c2410wdt_probe(struct platform_device *pdev)
{
struct device *dev;
unsigned int wtcon;
int started = 0;
int ret;
int size;
DBG("%s: probe=%p\n", __func__, pdev);
dev = &pdev->dev;
wdt_dev = &pdev->dev;
wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (wdt_mem == NULL) {
dev_err(dev, "no memory resource specified\n");
return -ENOENT;
}
size = resource_size(wdt_mem);
if (!request_mem_region(wdt_mem->start, size, pdev->name)) {
dev_err(dev, "failed to get memory region\n");
return -EBUSY;
}
wdt_base = ioremap(wdt_mem->start, size);
if (wdt_base == NULL) {
dev_err(dev, "failed to ioremap() region\n");
ret = -EINVAL;
goto err_req;
}
DBG("probe: mapped wdt_base=%p\n", wdt_base);
wdt_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (wdt_irq == NULL) {
dev_err(dev, "no irq resource specified\n");
ret = -ENOENT;
goto err_map;
}
ret = request_irq(wdt_irq->start, s3c2410wdt_irq, 0, pdev->name, pdev);
if (ret != 0) {
dev_err(dev, "failed to install irq (%d)\n", ret);
goto err_map;
}
wdt_clock = clk_get(&pdev->dev, "watchdog");
if (IS_ERR(wdt_clock)) {
dev_err(dev, "failed to find watchdog clock source\n");
ret = PTR_ERR(wdt_clock);
goto err_irq;
}
clk_enable(wdt_clock);
if (s3c2410wdt_cpufreq_register() < 0) {
printk(KERN_ERR PFX "failed to register cpufreq\n");
goto err_clk;
}
if (s3c2410wdt_set_heartbeat(&s3c2410_wdd, tmr_margin)) {
started = s3c2410wdt_set_heartbeat(&s3c2410_wdd,
CONFIG_S3C2410_WATCHDOG_DEFAULT_TIME);
if (started == 0)
dev_info(dev,
"tmr_margin value out of range, default %d used\n",
CONFIG_S3C2410_WATCHDOG_DEFAULT_TIME);
else
dev_info(dev, "default timer value is out of range, "
"cannot start\n");
}
ret = watchdog_register_device(&s3c2410_wdd);
if (ret) {
dev_err(dev, "cannot register watchdog (%d)\n", ret);
goto err_cpufreq;
}
if (tmr_atboot && started == 0) {
dev_info(dev, "starting watchdog timer\n");
s3c2410wdt_start(&s3c2410_wdd);
} else if (!tmr_atboot) {
s3c2410wdt_stop(&s3c2410_wdd);
}
wtcon = readl(wdt_base + S3C2410_WTCON);
dev_info(dev, "watchdog %sactive, reset %sabled, irq %sabled\n",
(wtcon & S3C2410_WTCON_ENABLE) ? "" : "in",
(wtcon & S3C2410_WTCON_RSTEN) ? "en" : "dis",
(wtcon & S3C2410_WTCON_INTEN) ? "en" : "dis");
return 0;
err_cpufreq:
s3c2410wdt_cpufreq_deregister();
err_clk:
clk_disable(wdt_clock);
clk_put(wdt_clock);
err_irq:
free_irq(wdt_irq->start, pdev);
err_map:
iounmap(wdt_base);
err_req:
release_mem_region(wdt_mem->start, size);
wdt_mem = NULL;
return ret;
}
static int __devexit s3c2410wdt_remove(struct platform_device *dev)
{
watchdog_unregister_device(&s3c2410_wdd);
s3c2410wdt_cpufreq_deregister();
clk_disable(wdt_clock);
clk_put(wdt_clock);
wdt_clock = NULL;
free_irq(wdt_irq->start, dev);
wdt_irq = NULL;
iounmap(wdt_base);
release_mem_region(wdt_mem->start, resource_size(wdt_mem));
wdt_mem = NULL;
return 0;
}
static void s3c2410wdt_shutdown(struct platform_device *dev)
{
s3c2410wdt_stop(&s3c2410_wdd);
}
static int s3c2410wdt_suspend(struct platform_device *dev, pm_message_t state)
{
wtcon_save = readl(wdt_base + S3C2410_WTCON);
wtdat_save = readl(wdt_base + S3C2410_WTDAT);
s3c2410wdt_stop(&s3c2410_wdd);
return 0;
}
static int s3c2410wdt_resume(struct platform_device *dev)
{
writel(wtdat_save, wdt_base + S3C2410_WTDAT);
writel(wtdat_save, wdt_base + S3C2410_WTCNT);
writel(wtcon_save, wdt_base + S3C2410_WTCON);
printk(KERN_INFO PFX "watchdog %sabled\n",
(wtcon_save & S3C2410_WTCON_ENABLE) ? "en" : "dis");
return 0;
}
static int __init watchdog_init(void)
{
printk(banner);
return platform_driver_register(&s3c2410wdt_driver);
}
static void __exit watchdog_exit(void)
{
platform_driver_unregister(&s3c2410wdt_driver);
}
