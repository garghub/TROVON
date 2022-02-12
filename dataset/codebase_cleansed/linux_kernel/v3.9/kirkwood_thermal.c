static int kirkwood_get_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
unsigned long reg;
struct kirkwood_thermal_priv *priv = thermal->devdata;
reg = readl_relaxed(priv->sensor);
if (!(reg >> KIRKWOOD_THERMAL_VALID_OFFSET) &
KIRKWOOD_THERMAL_VALID_MASK) {
dev_err(&thermal->device,
"Temperature sensor reading not valid\n");
return -EIO;
}
reg = (reg >> KIRKWOOD_THERMAL_TEMP_OFFSET) &
KIRKWOOD_THERMAL_TEMP_MASK;
*temp = ((2281638UL - (7298*reg)) / 10);
return 0;
}
static int kirkwood_thermal_probe(struct platform_device *pdev)
{
struct thermal_zone_device *thermal = NULL;
struct kirkwood_thermal_priv *priv;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get platform resource\n");
return -ENODEV;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->sensor = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->sensor))
return PTR_ERR(priv->sensor);
thermal = thermal_zone_device_register("kirkwood_thermal", 0, 0,
priv, &ops, NULL, 0, 0);
if (IS_ERR(thermal)) {
dev_err(&pdev->dev,
"Failed to register thermal zone device\n");
return PTR_ERR(thermal);
}
platform_set_drvdata(pdev, thermal);
return 0;
}
static int kirkwood_thermal_exit(struct platform_device *pdev)
{
struct thermal_zone_device *kirkwood_thermal =
platform_get_drvdata(pdev);
thermal_zone_device_unregister(kirkwood_thermal);
platform_set_drvdata(pdev, NULL);
return 0;
}
