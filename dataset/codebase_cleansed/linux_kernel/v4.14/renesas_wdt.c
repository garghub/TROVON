static void rwdt_write(struct rwdt_priv *priv, u32 val, unsigned int reg)
{
if (reg == RWTCNT)
val |= 0x5a5a0000;
else
val |= 0xa5a5a500;
writel_relaxed(val, priv->base + reg);
}
static int rwdt_init_timeout(struct watchdog_device *wdev)
{
struct rwdt_priv *priv = watchdog_get_drvdata(wdev);
rwdt_write(priv, 65536 - MUL_BY_CLKS_PER_SEC(priv, wdev->timeout), RWTCNT);
return 0;
}
static int rwdt_start(struct watchdog_device *wdev)
{
struct rwdt_priv *priv = watchdog_get_drvdata(wdev);
pm_runtime_get_sync(wdev->parent);
rwdt_write(priv, 0, RWTCSRB);
rwdt_write(priv, priv->cks, RWTCSRA);
rwdt_init_timeout(wdev);
while (readb_relaxed(priv->base + RWTCSRA) & RWTCSRA_WRFLG)
cpu_relax();
rwdt_write(priv, priv->cks | RWTCSRA_TME, RWTCSRA);
return 0;
}
static int rwdt_stop(struct watchdog_device *wdev)
{
struct rwdt_priv *priv = watchdog_get_drvdata(wdev);
rwdt_write(priv, priv->cks, RWTCSRA);
pm_runtime_put(wdev->parent);
return 0;
}
static unsigned int rwdt_get_timeleft(struct watchdog_device *wdev)
{
struct rwdt_priv *priv = watchdog_get_drvdata(wdev);
u16 val = readw_relaxed(priv->base + RWTCNT);
return DIV_BY_CLKS_PER_SEC(priv, 65536 - val);
}
static int rwdt_probe(struct platform_device *pdev)
{
struct rwdt_priv *priv;
struct resource *res;
struct clk *clk;
unsigned long clks_per_sec;
int ret, i;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
priv->clk_rate = clk_get_rate(clk);
pm_runtime_put(&pdev->dev);
if (!priv->clk_rate) {
ret = -ENOENT;
goto out_pm_disable;
}
for (i = ARRAY_SIZE(clk_divs) - 1; i >= 0; i--) {
clks_per_sec = priv->clk_rate / clk_divs[i];
if (clks_per_sec && clks_per_sec < 65536) {
priv->cks = i;
break;
}
}
if (i < 0) {
dev_err(&pdev->dev, "Can't find suitable clock divider\n");
ret = -ERANGE;
goto out_pm_disable;
}
priv->wdev.info = &rwdt_ident,
priv->wdev.ops = &rwdt_ops,
priv->wdev.parent = &pdev->dev;
priv->wdev.min_timeout = 1;
priv->wdev.max_timeout = DIV_BY_CLKS_PER_SEC(priv, 65536);
priv->wdev.timeout = min(priv->wdev.max_timeout, RWDT_DEFAULT_TIMEOUT);
platform_set_drvdata(pdev, priv);
watchdog_set_drvdata(&priv->wdev, priv);
watchdog_set_nowayout(&priv->wdev, nowayout);
ret = watchdog_init_timeout(&priv->wdev, 0, &pdev->dev);
if (ret)
dev_warn(&pdev->dev, "Specified timeout value invalid, using default\n");
ret = watchdog_register_device(&priv->wdev);
if (ret < 0)
goto out_pm_disable;
return 0;
out_pm_disable:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int rwdt_remove(struct platform_device *pdev)
{
struct rwdt_priv *priv = platform_get_drvdata(pdev);
watchdog_unregister_device(&priv->wdev);
pm_runtime_disable(&pdev->dev);
return 0;
}
