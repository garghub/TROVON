static int zx2967_thermal_get_temp(void *data, int *temp)
{
void __iomem *regs;
struct zx2967_thermal_priv *priv = data;
u32 val;
int ret;
if (!priv->tzd)
return -EAGAIN;
regs = priv->regs;
mutex_lock(&priv->lock);
writel_relaxed(ZX2967_POWER_MODE_LOW,
regs + ZX2967_THERMAL_POWER_MODE);
writel_relaxed(ZX2967_DCF_EN, regs + ZX2967_THERMAL_DCF);
val = readl_relaxed(regs + ZX2967_THERMAL_SEL);
val &= ~ZX2967_THERMAL_ID_MASK;
val |= ZX2967_THERMAL_ID;
writel_relaxed(val, regs + ZX2967_THERMAL_SEL);
usleep_range(100, 300);
ret = readx_poll_timeout(readl, regs + ZX2967_THERMAL_CTRL,
val, val & ZX2967_THERMAL_READY, 300,
ZX2967_GET_TEMP_TIMEOUT_US);
if (ret) {
dev_err(priv->dev, "Thermal sensor data timeout\n");
goto unlock;
}
writel_relaxed(ZX2967_DCF_FREEZE | ZX2967_DCF_EN,
regs + ZX2967_THERMAL_DCF);
val = readl_relaxed(regs + ZX2967_THERMAL_CTRL)
& ZX2967_THERMAL_TEMP_MASK;
writel_relaxed(ZX2967_POWER_MODE_HIGH,
regs + ZX2967_THERMAL_POWER_MODE);
*temp = DIV_ROUND_CLOSEST(((s32)val + priv->tzd->tzp->offset) * 1000,
priv->tzd->tzp->slope);
unlock:
mutex_unlock(&priv->lock);
return ret;
}
static int zx2967_thermal_probe(struct platform_device *pdev)
{
struct zx2967_thermal_priv *priv;
struct resource *res;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->regs))
return PTR_ERR(priv->regs);
priv->clk_topcrm = devm_clk_get(&pdev->dev, "topcrm");
if (IS_ERR(priv->clk_topcrm)) {
ret = PTR_ERR(priv->clk_topcrm);
dev_err(&pdev->dev, "failed to get topcrm clock: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(priv->clk_topcrm);
if (ret) {
dev_err(&pdev->dev, "failed to enable topcrm clock: %d\n",
ret);
return ret;
}
priv->clk_apb = devm_clk_get(&pdev->dev, "apb");
if (IS_ERR(priv->clk_apb)) {
ret = PTR_ERR(priv->clk_apb);
dev_err(&pdev->dev, "failed to get apb clock: %d\n", ret);
goto disable_clk_topcrm;
}
ret = clk_prepare_enable(priv->clk_apb);
if (ret) {
dev_err(&pdev->dev, "failed to enable apb clock: %d\n",
ret);
goto disable_clk_topcrm;
}
mutex_init(&priv->lock);
priv->tzd = thermal_zone_of_sensor_register(&pdev->dev,
0, priv, &zx2967_of_thermal_ops);
if (IS_ERR(priv->tzd)) {
ret = PTR_ERR(priv->tzd);
dev_err(&pdev->dev, "failed to register sensor: %d\n", ret);
goto disable_clk_all;
}
if (priv->tzd->tzp->slope == 0) {
thermal_zone_of_sensor_unregister(&pdev->dev, priv->tzd);
dev_err(&pdev->dev, "coefficients of sensor is invalid\n");
ret = -EINVAL;
goto disable_clk_all;
}
priv->dev = &pdev->dev;
platform_set_drvdata(pdev, priv);
return 0;
disable_clk_all:
clk_disable_unprepare(priv->clk_apb);
disable_clk_topcrm:
clk_disable_unprepare(priv->clk_topcrm);
return ret;
}
static int zx2967_thermal_exit(struct platform_device *pdev)
{
struct zx2967_thermal_priv *priv = platform_get_drvdata(pdev);
thermal_zone_of_sensor_unregister(&pdev->dev, priv->tzd);
clk_disable_unprepare(priv->clk_topcrm);
clk_disable_unprepare(priv->clk_apb);
return 0;
}
static int zx2967_thermal_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct zx2967_thermal_priv *priv = platform_get_drvdata(pdev);
if (priv && priv->clk_topcrm)
clk_disable_unprepare(priv->clk_topcrm);
if (priv && priv->clk_apb)
clk_disable_unprepare(priv->clk_apb);
return 0;
}
static int zx2967_thermal_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct zx2967_thermal_priv *priv = platform_get_drvdata(pdev);
int error;
error = clk_prepare_enable(priv->clk_topcrm);
if (error)
return error;
error = clk_prepare_enable(priv->clk_apb);
if (error) {
clk_disable_unprepare(priv->clk_topcrm);
return error;
}
return 0;
}
