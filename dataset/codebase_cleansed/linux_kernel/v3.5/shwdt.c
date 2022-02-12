static int sh_wdt_start(struct watchdog_device *wdt_dev)
{
struct sh_wdt *wdt = watchdog_get_drvdata(wdt_dev);
unsigned long flags;
u8 csr;
pm_runtime_get_sync(wdt->dev);
clk_enable(wdt->clk);
spin_lock_irqsave(&wdt->lock, flags);
next_heartbeat = jiffies + (heartbeat * HZ);
mod_timer(&wdt->timer, next_ping_period(clock_division_ratio));
csr = sh_wdt_read_csr();
csr |= WTCSR_WT | clock_division_ratio;
sh_wdt_write_csr(csr);
sh_wdt_write_cnt(0);
csr = sh_wdt_read_csr();
csr |= WTCSR_TME;
csr &= ~WTCSR_RSTS;
sh_wdt_write_csr(csr);
#ifdef CONFIG_CPU_SH2
csr = sh_wdt_read_rstcsr();
csr &= ~RSTCSR_RSTS;
sh_wdt_write_rstcsr(csr);
#endif
spin_unlock_irqrestore(&wdt->lock, flags);
return 0;
}
static int sh_wdt_stop(struct watchdog_device *wdt_dev)
{
struct sh_wdt *wdt = watchdog_get_drvdata(wdt_dev);
unsigned long flags;
u8 csr;
spin_lock_irqsave(&wdt->lock, flags);
del_timer(&wdt->timer);
csr = sh_wdt_read_csr();
csr &= ~WTCSR_TME;
sh_wdt_write_csr(csr);
spin_unlock_irqrestore(&wdt->lock, flags);
clk_disable(wdt->clk);
pm_runtime_put_sync(wdt->dev);
return 0;
}
static int sh_wdt_keepalive(struct watchdog_device *wdt_dev)
{
struct sh_wdt *wdt = watchdog_get_drvdata(wdt_dev);
unsigned long flags;
spin_lock_irqsave(&wdt->lock, flags);
next_heartbeat = jiffies + (heartbeat * HZ);
spin_unlock_irqrestore(&wdt->lock, flags);
return 0;
}
static int sh_wdt_set_heartbeat(struct watchdog_device *wdt_dev, unsigned t)
{
struct sh_wdt *wdt = watchdog_get_drvdata(wdt_dev);
unsigned long flags;
if (unlikely(t < 1 || t > 3600))
return -EINVAL;
spin_lock_irqsave(&wdt->lock, flags);
heartbeat = t;
wdt_dev->timeout = t;
spin_unlock_irqrestore(&wdt->lock, flags);
return 0;
}
static void sh_wdt_ping(unsigned long data)
{
struct sh_wdt *wdt = (struct sh_wdt *)data;
unsigned long flags;
spin_lock_irqsave(&wdt->lock, flags);
if (time_before(jiffies, next_heartbeat)) {
u8 csr;
csr = sh_wdt_read_csr();
csr &= ~WTCSR_IOVF;
sh_wdt_write_csr(csr);
sh_wdt_write_cnt(0);
mod_timer(&wdt->timer, next_ping_period(clock_division_ratio));
} else
dev_warn(wdt->dev, "Heartbeat lost! Will not ping "
"the watchdog\n");
spin_unlock_irqrestore(&wdt->lock, flags);
}
static int __devinit sh_wdt_probe(struct platform_device *pdev)
{
struct sh_wdt *wdt;
struct resource *res;
int rc;
if (pdev->id != -1)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!res))
return -EINVAL;
wdt = devm_kzalloc(&pdev->dev, sizeof(struct sh_wdt), GFP_KERNEL);
if (unlikely(!wdt))
return -ENOMEM;
wdt->dev = &pdev->dev;
wdt->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(wdt->clk)) {
wdt->clk = NULL;
}
wdt->base = devm_request_and_ioremap(wdt->dev, res);
if (unlikely(!wdt->base)) {
rc = -EADDRNOTAVAIL;
goto err;
}
watchdog_set_nowayout(&sh_wdt_dev, nowayout);
watchdog_set_drvdata(&sh_wdt_dev, wdt);
spin_lock_init(&wdt->lock);
rc = sh_wdt_set_heartbeat(&sh_wdt_dev, heartbeat);
if (unlikely(rc)) {
sh_wdt_set_heartbeat(&sh_wdt_dev, WATCHDOG_HEARTBEAT);
dev_warn(&pdev->dev,
"heartbeat value must be 1<=x<=3600, using %d\n",
sh_wdt_dev.timeout);
}
dev_info(&pdev->dev, "configured with heartbeat=%d sec (nowayout=%d)\n",
sh_wdt_dev.timeout, nowayout);
rc = watchdog_register_device(&sh_wdt_dev);
if (unlikely(rc)) {
dev_err(&pdev->dev, "Can't register watchdog (err=%d)\n", rc);
goto err;
}
init_timer(&wdt->timer);
wdt->timer.function = sh_wdt_ping;
wdt->timer.data = (unsigned long)wdt;
wdt->timer.expires = next_ping_period(clock_division_ratio);
platform_set_drvdata(pdev, wdt);
dev_info(&pdev->dev, "initialized.\n");
pm_runtime_enable(&pdev->dev);
return 0;
err:
clk_put(wdt->clk);
return rc;
}
static int __devexit sh_wdt_remove(struct platform_device *pdev)
{
struct sh_wdt *wdt = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
watchdog_unregister_device(&sh_wdt_dev);
pm_runtime_disable(&pdev->dev);
clk_put(wdt->clk);
return 0;
}
static void sh_wdt_shutdown(struct platform_device *pdev)
{
sh_wdt_stop(&sh_wdt_dev);
}
static int __init sh_wdt_init(void)
{
if (unlikely(clock_division_ratio < 0x5 ||
clock_division_ratio > 0x7)) {
clock_division_ratio = WTCSR_CKS_4096;
pr_info("divisor must be 0x5<=x<=0x7, using %d\n",
clock_division_ratio);
}
return platform_driver_register(&sh_wdt_driver);
}
static void __exit sh_wdt_exit(void)
{
platform_driver_unregister(&sh_wdt_driver);
}
