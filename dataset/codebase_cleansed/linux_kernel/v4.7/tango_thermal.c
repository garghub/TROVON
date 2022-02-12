static bool temp_above_thresh(void __iomem *base, int thresh_idx)
{
writel(CMD_READ | thresh_idx << 8, base + TEMPSI_CMD);
usleep_range(10, 20);
writel(CMD_READ | thresh_idx << 8, base + TEMPSI_CMD);
return readl(base + TEMPSI_RES);
}
static int tango_get_temp(void *arg, int *res)
{
struct tango_thermal_priv *priv = arg;
int idx = priv->thresh_idx;
if (temp_above_thresh(priv->base, idx)) {
while (idx < IDX_MAX && temp_above_thresh(priv->base, ++idx))
cpu_relax();
idx = idx - 1;
} else {
while (idx > IDX_MIN && !temp_above_thresh(priv->base, --idx))
cpu_relax();
}
*res = (idx * 9 / 2 - 38) * 1000;
priv->thresh_idx = idx;
return 0;
}
static int tango_thermal_probe(struct platform_device *pdev)
{
struct resource *res;
struct tango_thermal_priv *priv;
struct thermal_zone_device *tzdev;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
priv->thresh_idx = IDX_MIN;
writel(0, priv->base + TEMPSI_CFG);
writel(CMD_ON, priv->base + TEMPSI_CMD);
tzdev = devm_thermal_zone_of_sensor_register(&pdev->dev, 0, priv, &ops);
return PTR_ERR_OR_ZERO(tzdev);
}
