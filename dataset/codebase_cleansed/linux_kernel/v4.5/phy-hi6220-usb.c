static void hi6220_phy_init(struct hi6220_priv *priv)
{
struct regmap *reg = priv->reg;
u32 val, mask;
val = RST0_USBOTG_BUS | RST0_POR_PICOPHY |
RST0_USBOTG | RST0_USBOTG_32K;
mask = val;
regmap_update_bits(reg, SC_PERIPH_RSTEN0, mask, val);
regmap_update_bits(reg, SC_PERIPH_RSTDIS0, mask, val);
}
static int hi6220_phy_setup(struct hi6220_priv *priv, bool on)
{
struct regmap *reg = priv->reg;
u32 val, mask;
int ret;
if (on) {
val = CTRL5_USBOTG_RES_SEL | CTRL5_PICOPHY_ACAENB;
mask = val | CTRL5_PICOPHY_BC_MODE;
ret = regmap_update_bits(reg, SC_PERIPH_CTRL5, mask, val);
if (ret)
goto out;
val = CTRL4_PICO_VBUSVLDEXT | CTRL4_PICO_VBUSVLDEXTSEL |
CTRL4_OTG_PHY_SEL;
mask = val | CTRL4_PICO_SIDDQ | CTRL4_PICO_OGDISABLE;
ret = regmap_update_bits(reg, SC_PERIPH_CTRL4, mask, val);
if (ret)
goto out;
ret = regmap_write(reg, SC_PERIPH_CTRL8, EYE_PATTERN_PARA);
if (ret)
goto out;
} else {
val = CTRL4_PICO_SIDDQ;
mask = val;
ret = regmap_update_bits(reg, SC_PERIPH_CTRL4, mask, val);
if (ret)
goto out;
}
return 0;
out:
dev_err(priv->dev, "failed to setup phy ret: %d\n", ret);
return ret;
}
static int hi6220_phy_start(struct phy *phy)
{
struct hi6220_priv *priv = phy_get_drvdata(phy);
return hi6220_phy_setup(priv, true);
}
static int hi6220_phy_exit(struct phy *phy)
{
struct hi6220_priv *priv = phy_get_drvdata(phy);
return hi6220_phy_setup(priv, false);
}
static int hi6220_phy_probe(struct platform_device *pdev)
{
struct phy_provider *phy_provider;
struct device *dev = &pdev->dev;
struct phy *phy;
struct hi6220_priv *priv;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
priv->reg = syscon_regmap_lookup_by_phandle(dev->of_node,
"hisilicon,peripheral-syscon");
if (IS_ERR(priv->reg)) {
dev_err(dev, "no hisilicon,peripheral-syscon\n");
return PTR_ERR(priv->reg);
}
hi6220_phy_init(priv);
phy = devm_phy_create(dev, NULL, &hi6220_phy_ops);
if (IS_ERR(phy))
return PTR_ERR(phy);
phy_set_drvdata(phy, priv);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
