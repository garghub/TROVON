static int dove_init_sensor(const struct dove_thermal_priv *priv)
{
u32 reg;
u32 i;
reg = readl_relaxed(priv->control);
reg &= ~PMU_TDC0_AVG_NUM_MASK;
reg |= (0x1 << PMU_TDC0_AVG_NUM_OFFS);
reg &= ~PMU_TDC0_REF_CAL_CNT_MASK;
reg |= (0x0F1 << PMU_TDC0_REF_CAL_CNT_OFFS);
reg &= ~PMU_TDC0_SEL_VCAL_MASK;
reg |= (0x2 << PMU_TDC0_SEL_VCAL_OFFS);
writel(reg, priv->control);
reg = readl_relaxed(priv->control);
writel((reg | PMU_TDC0_SW_RST_MASK), priv->control);
writel(reg, priv->control);
reg = readl_relaxed(priv->sensor);
reg &= ~PMU_TM_DISABLE_MASK;
writel(reg, priv->sensor);
for (i = 0; i < 1000000; i++) {
reg = readl_relaxed(priv->sensor);
if (reg & DOVE_THERMAL_TEMP_MASK)
break;
}
if (i == 1000000)
return -EIO;
return 0;
}
static int dove_get_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
unsigned long reg;
struct dove_thermal_priv *priv = thermal->devdata;
reg = readl_relaxed(priv->control + PMU_TEMP_DIOD_CTRL1_REG);
if ((reg & PMU_TDC1_TEMP_VALID_MASK) == 0x0) {
dev_err(&thermal->device,
"Temperature sensor reading not valid\n");
return -EIO;
}
reg = readl_relaxed(priv->sensor);
reg = (reg >> DOVE_THERMAL_TEMP_OFFSET) & DOVE_THERMAL_TEMP_MASK;
*temp = ((3220000000UL - (10000000UL * reg)) / 13625);
return 0;
}
static int dove_thermal_probe(struct platform_device *pdev)
{
struct thermal_zone_device *thermal = NULL;
struct dove_thermal_priv *priv;
struct resource *res;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->sensor = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->sensor))
return PTR_ERR(priv->sensor);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
priv->control = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->control))
return PTR_ERR(priv->control);
ret = dove_init_sensor(priv);
if (ret) {
dev_err(&pdev->dev, "Failed to initialize sensor\n");
return ret;
}
thermal = thermal_zone_device_register("dove_thermal", 0, 0,
priv, &ops, NULL, 0, 0);
if (IS_ERR(thermal)) {
dev_err(&pdev->dev,
"Failed to register thermal zone device\n");
return PTR_ERR(thermal);
}
platform_set_drvdata(pdev, thermal);
return 0;
}
static int dove_thermal_exit(struct platform_device *pdev)
{
struct thermal_zone_device *dove_thermal =
platform_get_drvdata(pdev);
thermal_zone_device_unregister(dove_thermal);
return 0;
}
