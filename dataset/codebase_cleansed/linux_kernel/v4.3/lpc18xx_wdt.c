static int lpc18xx_wdt_feed(struct watchdog_device *wdt_dev)
{
struct lpc18xx_wdt_dev *lpc18xx_wdt = watchdog_get_drvdata(wdt_dev);
unsigned long flags;
spin_lock_irqsave(&lpc18xx_wdt->lock, flags);
writel(LPC18XX_WDT_FEED_MAGIC1, lpc18xx_wdt->base + LPC18XX_WDT_FEED);
writel(LPC18XX_WDT_FEED_MAGIC2, lpc18xx_wdt->base + LPC18XX_WDT_FEED);
spin_unlock_irqrestore(&lpc18xx_wdt->lock, flags);
return 0;
}
static void lpc18xx_wdt_timer_feed(unsigned long data)
{
struct watchdog_device *wdt_dev = (struct watchdog_device *)data;
struct lpc18xx_wdt_dev *lpc18xx_wdt = watchdog_get_drvdata(wdt_dev);
lpc18xx_wdt_feed(wdt_dev);
mod_timer(&lpc18xx_wdt->timer, jiffies +
msecs_to_jiffies((wdt_dev->timeout * MSEC_PER_SEC) / 2));
}
static int lpc18xx_wdt_stop(struct watchdog_device *wdt_dev)
{
lpc18xx_wdt_timer_feed((unsigned long)wdt_dev);
return 0;
}
static void __lpc18xx_wdt_set_timeout(struct lpc18xx_wdt_dev *lpc18xx_wdt)
{
unsigned int val;
val = DIV_ROUND_UP(lpc18xx_wdt->wdt_dev.timeout * lpc18xx_wdt->clk_rate,
LPC18XX_WDT_CLK_DIV);
writel(val, lpc18xx_wdt->base + LPC18XX_WDT_TC);
}
static int lpc18xx_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int new_timeout)
{
struct lpc18xx_wdt_dev *lpc18xx_wdt = watchdog_get_drvdata(wdt_dev);
lpc18xx_wdt->wdt_dev.timeout = new_timeout;
__lpc18xx_wdt_set_timeout(lpc18xx_wdt);
return 0;
}
static unsigned int lpc18xx_wdt_get_timeleft(struct watchdog_device *wdt_dev)
{
struct lpc18xx_wdt_dev *lpc18xx_wdt = watchdog_get_drvdata(wdt_dev);
unsigned int val;
val = readl(lpc18xx_wdt->base + LPC18XX_WDT_TV);
return (val * LPC18XX_WDT_CLK_DIV) / lpc18xx_wdt->clk_rate;
}
static int lpc18xx_wdt_start(struct watchdog_device *wdt_dev)
{
struct lpc18xx_wdt_dev *lpc18xx_wdt = watchdog_get_drvdata(wdt_dev);
unsigned int val;
if (timer_pending(&lpc18xx_wdt->timer))
del_timer(&lpc18xx_wdt->timer);
val = readl(lpc18xx_wdt->base + LPC18XX_WDT_MOD);
val |= LPC18XX_WDT_MOD_WDEN;
val |= LPC18XX_WDT_MOD_WDRESET;
writel(val, lpc18xx_wdt->base + LPC18XX_WDT_MOD);
lpc18xx_wdt_feed(wdt_dev);
return 0;
}
static int lpc18xx_wdt_restart(struct notifier_block *this, unsigned long mode,
void *cmd)
{
struct lpc18xx_wdt_dev *lpc18xx_wdt = container_of(this,
struct lpc18xx_wdt_dev, restart_handler);
unsigned long flags;
int val;
spin_lock_irqsave(&lpc18xx_wdt->lock, flags);
val = readl(lpc18xx_wdt->base + LPC18XX_WDT_MOD);
val |= LPC18XX_WDT_MOD_WDEN;
val |= LPC18XX_WDT_MOD_WDRESET;
writel(val, lpc18xx_wdt->base + LPC18XX_WDT_MOD);
writel(LPC18XX_WDT_FEED_MAGIC1, lpc18xx_wdt->base + LPC18XX_WDT_FEED);
writel(LPC18XX_WDT_FEED_MAGIC2, lpc18xx_wdt->base + LPC18XX_WDT_FEED);
writel(LPC18XX_WDT_FEED_MAGIC1, lpc18xx_wdt->base + LPC18XX_WDT_FEED);
writel(LPC18XX_WDT_FEED_MAGIC1, lpc18xx_wdt->base + LPC18XX_WDT_FEED);
spin_unlock_irqrestore(&lpc18xx_wdt->lock, flags);
return NOTIFY_OK;
}
static int lpc18xx_wdt_probe(struct platform_device *pdev)
{
struct lpc18xx_wdt_dev *lpc18xx_wdt;
struct device *dev = &pdev->dev;
struct resource *res;
int ret;
lpc18xx_wdt = devm_kzalloc(dev, sizeof(*lpc18xx_wdt), GFP_KERNEL);
if (!lpc18xx_wdt)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
lpc18xx_wdt->base = devm_ioremap_resource(dev, res);
if (IS_ERR(lpc18xx_wdt->base))
return PTR_ERR(lpc18xx_wdt->base);
lpc18xx_wdt->reg_clk = devm_clk_get(dev, "reg");
if (IS_ERR(lpc18xx_wdt->reg_clk)) {
dev_err(dev, "failed to get the reg clock\n");
return PTR_ERR(lpc18xx_wdt->reg_clk);
}
lpc18xx_wdt->wdt_clk = devm_clk_get(dev, "wdtclk");
if (IS_ERR(lpc18xx_wdt->wdt_clk)) {
dev_err(dev, "failed to get the wdt clock\n");
return PTR_ERR(lpc18xx_wdt->wdt_clk);
}
ret = clk_prepare_enable(lpc18xx_wdt->reg_clk);
if (ret) {
dev_err(dev, "could not prepare or enable sys clock\n");
return ret;
}
ret = clk_prepare_enable(lpc18xx_wdt->wdt_clk);
if (ret) {
dev_err(dev, "could not prepare or enable wdt clock\n");
goto disable_reg_clk;
}
lpc18xx_wdt->clk_rate = clk_get_rate(lpc18xx_wdt->wdt_clk);
if (lpc18xx_wdt->clk_rate == 0) {
dev_err(dev, "failed to get clock rate\n");
ret = -EINVAL;
goto disable_wdt_clk;
}
lpc18xx_wdt->wdt_dev.info = &lpc18xx_wdt_info;
lpc18xx_wdt->wdt_dev.ops = &lpc18xx_wdt_ops;
lpc18xx_wdt->wdt_dev.min_timeout = DIV_ROUND_UP(LPC18XX_WDT_TC_MIN *
LPC18XX_WDT_CLK_DIV, lpc18xx_wdt->clk_rate);
lpc18xx_wdt->wdt_dev.max_timeout = (LPC18XX_WDT_TC_MAX *
LPC18XX_WDT_CLK_DIV) / lpc18xx_wdt->clk_rate;
lpc18xx_wdt->wdt_dev.timeout = min(lpc18xx_wdt->wdt_dev.max_timeout,
LPC18XX_WDT_DEF_TIMEOUT);
spin_lock_init(&lpc18xx_wdt->lock);
lpc18xx_wdt->wdt_dev.parent = dev;
watchdog_set_drvdata(&lpc18xx_wdt->wdt_dev, lpc18xx_wdt);
ret = watchdog_init_timeout(&lpc18xx_wdt->wdt_dev, heartbeat, dev);
__lpc18xx_wdt_set_timeout(lpc18xx_wdt);
setup_timer(&lpc18xx_wdt->timer, lpc18xx_wdt_timer_feed,
(unsigned long)&lpc18xx_wdt->wdt_dev);
watchdog_set_nowayout(&lpc18xx_wdt->wdt_dev, nowayout);
platform_set_drvdata(pdev, lpc18xx_wdt);
ret = watchdog_register_device(&lpc18xx_wdt->wdt_dev);
if (ret)
goto disable_wdt_clk;
lpc18xx_wdt->restart_handler.notifier_call = lpc18xx_wdt_restart;
lpc18xx_wdt->restart_handler.priority = 128;
ret = register_restart_handler(&lpc18xx_wdt->restart_handler);
if (ret)
dev_warn(dev, "failed to register restart handler: %d\n", ret);
return 0;
disable_wdt_clk:
clk_disable_unprepare(lpc18xx_wdt->wdt_clk);
disable_reg_clk:
clk_disable_unprepare(lpc18xx_wdt->reg_clk);
return ret;
}
static void lpc18xx_wdt_shutdown(struct platform_device *pdev)
{
struct lpc18xx_wdt_dev *lpc18xx_wdt = platform_get_drvdata(pdev);
lpc18xx_wdt_stop(&lpc18xx_wdt->wdt_dev);
}
static int lpc18xx_wdt_remove(struct platform_device *pdev)
{
struct lpc18xx_wdt_dev *lpc18xx_wdt = platform_get_drvdata(pdev);
unregister_restart_handler(&lpc18xx_wdt->restart_handler);
dev_warn(&pdev->dev, "I quit now, hardware will probably reboot!\n");
del_timer(&lpc18xx_wdt->timer);
watchdog_unregister_device(&lpc18xx_wdt->wdt_dev);
clk_disable_unprepare(lpc18xx_wdt->wdt_clk);
clk_disable_unprepare(lpc18xx_wdt->reg_clk);
return 0;
}
