static int txx9wdt_ping(struct watchdog_device *wdt_dev)
{
spin_lock(&txx9_lock);
__raw_writel(TXx9_TMWTMR_TWIE | TXx9_TMWTMR_TWC, &txx9wdt_reg->wtmr);
spin_unlock(&txx9_lock);
return 0;
}
static int txx9wdt_start(struct watchdog_device *wdt_dev)
{
spin_lock(&txx9_lock);
__raw_writel(WD_TIMER_CLK * wdt_dev->timeout, &txx9wdt_reg->cpra);
__raw_writel(WD_TIMER_CCD, &txx9wdt_reg->ccdr);
__raw_writel(0, &txx9wdt_reg->tisr);
__raw_writel(TXx9_TMTCR_TCE | TXx9_TMTCR_CCDE | TXx9_TMTCR_TMODE_WDOG,
&txx9wdt_reg->tcr);
__raw_writel(TXx9_TMWTMR_TWIE | TXx9_TMWTMR_TWC, &txx9wdt_reg->wtmr);
spin_unlock(&txx9_lock);
return 0;
}
static int txx9wdt_stop(struct watchdog_device *wdt_dev)
{
spin_lock(&txx9_lock);
__raw_writel(TXx9_TMWTMR_WDIS, &txx9wdt_reg->wtmr);
__raw_writel(__raw_readl(&txx9wdt_reg->tcr) & ~TXx9_TMTCR_TCE,
&txx9wdt_reg->tcr);
spin_unlock(&txx9_lock);
return 0;
}
static int txx9wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int new_timeout)
{
wdt_dev->timeout = new_timeout;
txx9wdt_stop(wdt_dev);
txx9wdt_start(wdt_dev);
return 0;
}
static int __init txx9wdt_probe(struct platform_device *dev)
{
struct resource *res;
int ret;
txx9_imclk = clk_get(NULL, "imbus_clk");
if (IS_ERR(txx9_imclk)) {
ret = PTR_ERR(txx9_imclk);
txx9_imclk = NULL;
goto exit;
}
ret = clk_enable(txx9_imclk);
if (ret) {
clk_put(txx9_imclk);
txx9_imclk = NULL;
goto exit;
}
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
txx9wdt_reg = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(txx9wdt_reg)) {
ret = PTR_ERR(txx9wdt_reg);
goto exit;
}
if (timeout < 1 || timeout > WD_MAX_TIMEOUT)
timeout = TIMER_MARGIN;
txx9wdt.timeout = timeout;
txx9wdt.min_timeout = 1;
txx9wdt.max_timeout = WD_MAX_TIMEOUT;
watchdog_set_nowayout(&txx9wdt, nowayout);
ret = watchdog_register_device(&txx9wdt);
if (ret)
goto exit;
pr_info("Hardware Watchdog Timer: timeout=%d sec (max %ld) (nowayout= %d)\n",
timeout, WD_MAX_TIMEOUT, nowayout);
return 0;
exit:
if (txx9_imclk) {
clk_disable(txx9_imclk);
clk_put(txx9_imclk);
}
return ret;
}
static int __exit txx9wdt_remove(struct platform_device *dev)
{
watchdog_unregister_device(&txx9wdt);
clk_disable(txx9_imclk);
clk_put(txx9_imclk);
return 0;
}
static void txx9wdt_shutdown(struct platform_device *dev)
{
txx9wdt_stop(&txx9wdt);
}
