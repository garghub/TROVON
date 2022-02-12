static int ep93xx_wdt_start(struct watchdog_device *wdd)
{
struct ep93xx_wdt_priv *priv = watchdog_get_drvdata(wdd);
writel(0xaaaa, priv->mmio + EP93XX_WATCHDOG);
return 0;
}
static int ep93xx_wdt_stop(struct watchdog_device *wdd)
{
struct ep93xx_wdt_priv *priv = watchdog_get_drvdata(wdd);
writel(0xaa55, priv->mmio + EP93XX_WATCHDOG);
return 0;
}
static int ep93xx_wdt_ping(struct watchdog_device *wdd)
{
struct ep93xx_wdt_priv *priv = watchdog_get_drvdata(wdd);
writel(0x5555, priv->mmio + EP93XX_WATCHDOG);
return 0;
}
static int ep93xx_wdt_probe(struct platform_device *pdev)
{
struct ep93xx_wdt_priv *priv;
struct watchdog_device *wdd;
struct resource *res;
unsigned long val;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->mmio = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->mmio))
return PTR_ERR(priv->mmio);
val = readl(priv->mmio + EP93XX_WATCHDOG);
wdd = &priv->wdd;
wdd->bootstatus = (val & 0x01) ? WDIOF_CARDRESET : 0;
wdd->info = &ep93xx_wdt_ident;
wdd->ops = &ep93xx_wdt_ops;
wdd->min_timeout = 1;
wdd->max_hw_heartbeat_ms = 200;
wdd->parent = &pdev->dev;
watchdog_set_nowayout(wdd, nowayout);
wdd->timeout = WDT_TIMEOUT;
watchdog_init_timeout(wdd, timeout, &pdev->dev);
watchdog_set_drvdata(wdd, priv);
ret = devm_watchdog_register_device(&pdev->dev, wdd);
if (ret)
return ret;
dev_info(&pdev->dev, "EP93XX watchdog driver %s\n",
(val & 0x08) ? " (nCS1 disable detected)" : "");
return 0;
}
