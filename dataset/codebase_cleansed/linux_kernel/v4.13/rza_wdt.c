static int rza_wdt_start(struct watchdog_device *wdev)
{
struct rza_wdt *priv = watchdog_get_drvdata(wdev);
writew(WTCSR_MAGIC | 0, priv->base + WTCSR);
readb(priv->base + WRCSR);
writew(WRCSR_CLEAR_WOVF, priv->base + WRCSR);
writew(WRCSR_MAGIC | WRCSR_RSTE, priv->base + WRCSR);
writew(WTCNT_MAGIC | 0, priv->base + WTCNT);
writew(WTCSR_MAGIC | WTSCR_WT | WTSCR_TME | WTSCR_CKS(7),
priv->base + WTCSR);
return 0;
}
static int rza_wdt_stop(struct watchdog_device *wdev)
{
struct rza_wdt *priv = watchdog_get_drvdata(wdev);
writew(WTCSR_MAGIC | 0, priv->base + WTCSR);
return 0;
}
static int rza_wdt_ping(struct watchdog_device *wdev)
{
struct rza_wdt *priv = watchdog_get_drvdata(wdev);
writew(WTCNT_MAGIC | 0, priv->base + WTCNT);
return 0;
}
static int rza_wdt_restart(struct watchdog_device *wdev, unsigned long action,
void *data)
{
struct rza_wdt *priv = watchdog_get_drvdata(wdev);
writew(WTCSR_MAGIC | 0, priv->base + WTCSR);
readb(priv->base + WRCSR);
writew(WRCSR_CLEAR_WOVF, priv->base + WRCSR);
writew(WRCSR_MAGIC | WRCSR_RSTE, priv->base + WRCSR);
writew(WTCNT_MAGIC | 255, priv->base + WTCNT);
writew(WTCSR_MAGIC | WTSCR_WT | WTSCR_TME, priv->base + WTCSR);
wmb();
udelay(20);
return 0;
}
static int rza_wdt_probe(struct platform_device *pdev)
{
struct rza_wdt *priv;
struct resource *res;
unsigned long rate;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
rate = clk_get_rate(priv->clk);
if (rate < 16384) {
dev_err(&pdev->dev, "invalid clock rate (%ld)\n", rate);
return -ENOENT;
}
rate /= 16384;
priv->wdev.info = &rza_wdt_ident,
priv->wdev.ops = &rza_wdt_ops,
priv->wdev.parent = &pdev->dev;
priv->wdev.max_hw_heartbeat_ms = (1000 * U8_MAX) / rate;
dev_dbg(&pdev->dev, "max hw timeout of %dms\n",
priv->wdev.max_hw_heartbeat_ms);
priv->wdev.min_timeout = 1;
priv->wdev.timeout = DEFAULT_TIMEOUT;
watchdog_init_timeout(&priv->wdev, 0, &pdev->dev);
watchdog_set_drvdata(&priv->wdev, priv);
ret = devm_watchdog_register_device(&pdev->dev, &priv->wdev);
if (ret)
dev_err(&pdev->dev, "Cannot register watchdog device\n");
return ret;
}
