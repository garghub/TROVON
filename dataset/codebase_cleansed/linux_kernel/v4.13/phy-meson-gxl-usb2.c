static int phy_meson_gxl_usb2_reset(struct phy *phy)
{
struct phy_meson_gxl_usb2_priv *priv = phy_get_drvdata(phy);
if (priv->is_enabled) {
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_POWER_ON_RESET,
U2P_R0_POWER_ON_RESET);
udelay(RESET_COMPLETE_TIME);
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_POWER_ON_RESET,
0);
udelay(RESET_COMPLETE_TIME);
}
return 0;
}
static int phy_meson_gxl_usb2_set_mode(struct phy *phy, enum phy_mode mode)
{
struct phy_meson_gxl_usb2_priv *priv = phy_get_drvdata(phy);
switch (mode) {
case PHY_MODE_USB_HOST:
case PHY_MODE_USB_OTG:
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_DM_PULLDOWN,
U2P_R0_DM_PULLDOWN);
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_DP_PULLDOWN,
U2P_R0_DP_PULLDOWN);
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_ID_PULLUP, 0);
break;
case PHY_MODE_USB_DEVICE:
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_DM_PULLDOWN,
0);
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_DP_PULLDOWN,
0);
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_ID_PULLUP,
U2P_R0_ID_PULLUP);
break;
default:
return -EINVAL;
}
phy_meson_gxl_usb2_reset(phy);
priv->mode = mode;
return 0;
}
static int phy_meson_gxl_usb2_power_off(struct phy *phy)
{
struct phy_meson_gxl_usb2_priv *priv = phy_get_drvdata(phy);
priv->is_enabled = 0;
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_POWER_ON_RESET,
U2P_R0_POWER_ON_RESET);
return 0;
}
static int phy_meson_gxl_usb2_power_on(struct phy *phy)
{
struct phy_meson_gxl_usb2_priv *priv = phy_get_drvdata(phy);
int ret;
priv->is_enabled = 1;
regmap_update_bits(priv->regmap, U2P_R0, U2P_R0_POWER_ON_RESET, 0);
ret = phy_meson_gxl_usb2_set_mode(phy, priv->mode);
if (ret) {
phy_meson_gxl_usb2_power_off(phy);
dev_err(&phy->dev, "Failed to initialize PHY with mode %d\n",
priv->mode);
return ret;
}
return 0;
}
static int phy_meson_gxl_usb2_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct phy_provider *phy_provider;
struct resource *res;
struct phy_meson_gxl_usb2_priv *priv;
struct phy *phy;
void __iomem *base;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, priv);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
switch (of_usb_get_dr_mode_by_phy(dev->of_node, -1)) {
case USB_DR_MODE_PERIPHERAL:
priv->mode = PHY_MODE_USB_DEVICE;
break;
case USB_DR_MODE_OTG:
priv->mode = PHY_MODE_USB_OTG;
break;
case USB_DR_MODE_HOST:
default:
priv->mode = PHY_MODE_USB_HOST;
break;
}
priv->regmap = devm_regmap_init_mmio(dev, base,
&phy_meson_gxl_usb2_regmap_conf);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
phy = devm_phy_create(dev, NULL, &phy_meson_gxl_usb2_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create PHY\n");
return PTR_ERR(phy);
}
phy_set_drvdata(phy, priv);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
