static int ts72xx_wdt_start(struct watchdog_device *wdd)
{
struct ts72xx_wdt_priv *priv = watchdog_get_drvdata(wdd);
writeb(TS72XX_WDT_FEED_VAL, priv->feed_reg);
writeb(priv->regval, priv->control_reg);
return 0;
}
static int ts72xx_wdt_stop(struct watchdog_device *wdd)
{
struct ts72xx_wdt_priv *priv = watchdog_get_drvdata(wdd);
writeb(TS72XX_WDT_FEED_VAL, priv->feed_reg);
writeb(TS72XX_WDT_CTRL_DISABLE, priv->control_reg);
return 0;
}
static int ts72xx_wdt_ping(struct watchdog_device *wdd)
{
struct ts72xx_wdt_priv *priv = watchdog_get_drvdata(wdd);
writeb(TS72XX_WDT_FEED_VAL, priv->feed_reg);
return 0;
}
static int ts72xx_wdt_settimeout(struct watchdog_device *wdd, unsigned int to)
{
struct ts72xx_wdt_priv *priv = watchdog_get_drvdata(wdd);
if (to == 1) {
priv->regval = TS72XX_WDT_CTRL_1SEC;
} else if (to == 2) {
priv->regval = TS72XX_WDT_CTRL_2SEC;
} else if (to <= 4) {
priv->regval = TS72XX_WDT_CTRL_4SEC;
to = 4;
} else {
priv->regval = TS72XX_WDT_CTRL_8SEC;
if (to <= 8)
to = 8;
}
wdd->timeout = to;
if (watchdog_active(wdd)) {
ts72xx_wdt_stop(wdd);
ts72xx_wdt_start(wdd);
}
return 0;
}
static int ts72xx_wdt_probe(struct platform_device *pdev)
{
struct ts72xx_wdt_priv *priv;
struct watchdog_device *wdd;
struct resource *res;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->control_reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->control_reg))
return PTR_ERR(priv->control_reg);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
priv->feed_reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->feed_reg))
return PTR_ERR(priv->feed_reg);
wdd = &priv->wdd;
wdd->info = &ts72xx_wdt_ident;
wdd->ops = &ts72xx_wdt_ops;
wdd->min_timeout = 1;
wdd->max_hw_heartbeat_ms = 8000;
wdd->parent = &pdev->dev;
watchdog_set_nowayout(wdd, nowayout);
wdd->timeout = TS72XX_WDT_DEFAULT_TIMEOUT;
watchdog_init_timeout(wdd, timeout, &pdev->dev);
watchdog_set_drvdata(wdd, priv);
ret = devm_watchdog_register_device(&pdev->dev, wdd);
if (ret)
return ret;
dev_info(&pdev->dev, "TS-72xx Watchdog driver\n");
return 0;
}
