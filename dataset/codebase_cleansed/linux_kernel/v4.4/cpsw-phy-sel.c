static void cpsw_gmii_sel_am3352(struct cpsw_phy_sel_priv *priv,
phy_interface_t phy_mode, int slave)
{
u32 reg;
u32 mask;
u32 mode = 0;
reg = readl(priv->gmii_sel);
switch (phy_mode) {
case PHY_INTERFACE_MODE_RMII:
mode = AM33XX_GMII_SEL_MODE_RMII;
break;
case PHY_INTERFACE_MODE_RGMII:
case PHY_INTERFACE_MODE_RGMII_ID:
case PHY_INTERFACE_MODE_RGMII_RXID:
case PHY_INTERFACE_MODE_RGMII_TXID:
mode = AM33XX_GMII_SEL_MODE_RGMII;
break;
case PHY_INTERFACE_MODE_MII:
default:
mode = AM33XX_GMII_SEL_MODE_MII;
break;
};
mask = GMII_SEL_MODE_MASK << (slave * 2) | BIT(slave + 6);
mode <<= slave * 2;
if (priv->rmii_clock_external) {
if (slave == 0)
mode |= AM33XX_GMII_SEL_RMII1_IO_CLK_EN;
else
mode |= AM33XX_GMII_SEL_RMII2_IO_CLK_EN;
}
reg &= ~mask;
reg |= mode;
writel(reg, priv->gmii_sel);
}
static void cpsw_gmii_sel_dra7xx(struct cpsw_phy_sel_priv *priv,
phy_interface_t phy_mode, int slave)
{
u32 reg;
u32 mask;
u32 mode = 0;
reg = readl(priv->gmii_sel);
switch (phy_mode) {
case PHY_INTERFACE_MODE_RMII:
mode = AM33XX_GMII_SEL_MODE_RMII;
break;
case PHY_INTERFACE_MODE_RGMII:
case PHY_INTERFACE_MODE_RGMII_ID:
case PHY_INTERFACE_MODE_RGMII_RXID:
case PHY_INTERFACE_MODE_RGMII_TXID:
mode = AM33XX_GMII_SEL_MODE_RGMII;
break;
case PHY_INTERFACE_MODE_MII:
default:
mode = AM33XX_GMII_SEL_MODE_MII;
break;
};
switch (slave) {
case 0:
mask = GMII_SEL_MODE_MASK;
break;
case 1:
mask = GMII_SEL_MODE_MASK << 4;
mode <<= 4;
break;
default:
dev_err(priv->dev, "invalid slave number...\n");
return;
}
if (priv->rmii_clock_external)
dev_err(priv->dev, "RMII External clock is not supported\n");
reg &= ~mask;
reg |= mode;
writel(reg, priv->gmii_sel);
}
static int match(struct device *dev, void *data)
{
struct device_node *node = (struct device_node *)data;
return dev->of_node == node &&
dev->driver == &cpsw_phy_sel_driver.driver;
}
void cpsw_phy_sel(struct device *dev, phy_interface_t phy_mode, int slave)
{
struct device_node *node;
struct cpsw_phy_sel_priv *priv;
node = of_get_child_by_name(dev->of_node, "cpsw-phy-sel");
if (!node) {
dev_err(dev, "Phy mode driver DT not found\n");
return;
}
dev = bus_find_device(&platform_bus_type, NULL, node, match);
priv = dev_get_drvdata(dev);
priv->cpsw_phy_sel(priv, phy_mode, slave);
}
static int cpsw_phy_sel_probe(struct platform_device *pdev)
{
struct resource *res;
const struct of_device_id *of_id;
struct cpsw_phy_sel_priv *priv;
of_id = of_match_node(cpsw_phy_sel_id_table, pdev->dev.of_node);
if (!of_id)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "unable to alloc memory for cpsw phy sel\n");
return -ENOMEM;
}
priv->dev = &pdev->dev;
priv->cpsw_phy_sel = of_id->data;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "gmii-sel");
priv->gmii_sel = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->gmii_sel))
return PTR_ERR(priv->gmii_sel);
if (of_find_property(pdev->dev.of_node, "rmii-clock-ext", NULL))
priv->rmii_clock_external = true;
dev_set_drvdata(&pdev->dev, priv);
return 0;
}
