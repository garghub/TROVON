static void armadaxp_init_sensor(struct platform_device *pdev,
struct armada_thermal_priv *priv)
{
unsigned long reg;
reg = readl_relaxed(priv->control);
reg |= PMU_TDC0_OTF_CAL_MASK;
writel(reg, priv->control);
reg &= ~PMU_TDC0_REF_CAL_CNT_MASK;
reg |= (0xf1 << PMU_TDC0_REF_CAL_CNT_OFFS);
writel(reg, priv->control);
reg = readl_relaxed(priv->control);
writel((reg | PMU_TDC0_SW_RST_MASK), priv->control);
writel(reg, priv->control);
reg = readl_relaxed(priv->sensor);
reg &= ~PMU_TM_DISABLE_MASK;
writel(reg, priv->sensor);
}
static void armada370_init_sensor(struct platform_device *pdev,
struct armada_thermal_priv *priv)
{
unsigned long reg;
reg = readl_relaxed(priv->control);
reg |= PMU_TDC0_OTF_CAL_MASK;
writel(reg, priv->control);
reg &= ~PMU_TDC0_REF_CAL_CNT_MASK;
reg |= (0xf1 << PMU_TDC0_REF_CAL_CNT_OFFS);
writel(reg, priv->control);
reg &= ~PMU_TDC0_START_CAL_MASK;
writel(reg, priv->control);
mdelay(10);
}
static void armada375_init_sensor(struct platform_device *pdev,
struct armada_thermal_priv *priv)
{
unsigned long reg;
bool quirk_needed =
!!of_device_is_compatible(pdev->dev.of_node,
"marvell,armada375-z1-thermal");
if (quirk_needed) {
writel(A375_Z1_CAL_RESET_LSB, priv->control);
writel(A375_Z1_CAL_RESET_MSB, priv->control + 0x4);
}
reg = readl(priv->control + 4);
reg &= ~(A375_UNIT_CONTROL_MASK << A375_UNIT_CONTROL_SHIFT);
reg &= ~A375_READOUT_INVERT;
reg &= ~A375_HW_RESETn;
if (quirk_needed)
reg |= A375_Z1_WORKAROUND_BIT;
writel(reg, priv->control + 4);
mdelay(20);
reg |= A375_HW_RESETn;
writel(reg, priv->control + 4);
mdelay(50);
}
static void armada380_init_sensor(struct platform_device *pdev,
struct armada_thermal_priv *priv)
{
unsigned long reg = readl_relaxed(priv->control);
if (!(reg & A380_HW_RESET)) {
reg |= A380_HW_RESET;
writel(reg, priv->control);
mdelay(10);
}
}
static bool armada_is_valid(struct armada_thermal_priv *priv)
{
unsigned long reg = readl_relaxed(priv->sensor);
return (reg >> priv->data->is_valid_shift) & THERMAL_VALID_MASK;
}
static int armada_get_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
struct armada_thermal_priv *priv = thermal->devdata;
unsigned long reg;
unsigned long m, b, div;
if (priv->data->is_valid && !priv->data->is_valid(priv)) {
dev_err(&thermal->device,
"Temperature sensor reading not valid\n");
return -EIO;
}
reg = readl_relaxed(priv->sensor);
reg = (reg >> priv->data->temp_shift) & priv->data->temp_mask;
b = priv->data->coef_b;
m = priv->data->coef_m;
div = priv->data->coef_div;
if (priv->data->inverted)
*temp = ((m * reg) - b) / div;
else
*temp = (b - (m * reg)) / div;
return 0;
}
static int armada_thermal_probe(struct platform_device *pdev)
{
struct thermal_zone_device *thermal;
const struct of_device_id *match;
struct armada_thermal_priv *priv;
struct resource *res;
match = of_match_device(armada_thermal_id_table, &pdev->dev);
if (!match)
return -ENODEV;
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
priv->data = (struct armada_thermal_data *)match->data;
priv->data->init_sensor(pdev, priv);
thermal = thermal_zone_device_register("armada_thermal", 0, 0,
priv, &ops, NULL, 0, 0);
if (IS_ERR(thermal)) {
dev_err(&pdev->dev,
"Failed to register thermal zone device\n");
return PTR_ERR(thermal);
}
platform_set_drvdata(pdev, thermal);
return 0;
}
static int armada_thermal_exit(struct platform_device *pdev)
{
struct thermal_zone_device *armada_thermal =
platform_get_drvdata(pdev);
thermal_zone_device_unregister(armada_thermal);
return 0;
}
