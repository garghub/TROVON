static int hix5hd2_sata_phy_init(struct phy *phy)
{
struct hix5hd2_priv *priv = phy_get_drvdata(phy);
u32 val, data[2];
int ret;
if (priv->peri_ctrl) {
ret = of_property_read_u32_array(phy->dev.of_node,
"hisilicon,power-reg",
&data[0], 2);
if (ret) {
dev_err(&phy->dev, "Fail read hisilicon,power-reg\n");
return ret;
}
regmap_update_bits(priv->peri_ctrl, data[0],
BIT(data[1]), BIT(data[1]));
}
val = readl_relaxed(priv->base + SATA_PHY0_CTLL);
val &= ~(MPLL_MULTIPLIER_MASK | REF_USE_PAD);
val |= MPLL_MULTIPLIER_50M << MPLL_MULTIPLIER_SHIFT |
REF_SSP_EN | PHY_RESET;
writel_relaxed(val, priv->base + SATA_PHY0_CTLL);
msleep(20);
val &= ~PHY_RESET;
writel_relaxed(val, priv->base + SATA_PHY0_CTLL);
val = readl_relaxed(priv->base + SATA_PORT_PHYCTL1);
val &= ~AMPLITUDE_MASK;
val |= AMPLITUDE_GEN3 << AMPLITUDE_GEN3_SHIFT |
AMPLITUDE_GEN2 << AMPLITUDE_GEN2_SHIFT |
AMPLITUDE_GEN1 << AMPLITUDE_GEN1_SHIFT;
writel_relaxed(val, priv->base + SATA_PORT_PHYCTL1);
val = readl_relaxed(priv->base + SATA_PORT_PHYCTL2);
val &= ~PREEMPH_MASK;
val |= PREEMPH_GEN3 << PREEMPH_GEN3_SHIFT |
PREEMPH_GEN2 << PREEMPH_GEN2_SHIFT |
PREEMPH_GEN1 << PREEMPH_GEN1_SHIFT;
writel_relaxed(val, priv->base + SATA_PORT_PHYCTL2);
val = readl_relaxed(priv->base + SATA_PORT_PHYCTL);
val &= ~SPEED_MODE_MASK;
val |= SPEED_MODE_GEN1 << HALF_RATE_SHIFT |
SPEED_MODE_GEN1 << PHY_CONFIG_SHIFT |
SPEED_MODE_GEN1 << GEN2_EN_SHIFT | SPEED_CTRL;
writel_relaxed(val, priv->base + SATA_PORT_PHYCTL);
msleep(20);
val &= ~SPEED_MODE_MASK;
val |= SPEED_MODE_GEN3 << HALF_RATE_SHIFT |
SPEED_MODE_GEN3 << PHY_CONFIG_SHIFT |
SPEED_MODE_GEN3 << GEN2_EN_SHIFT | SPEED_CTRL;
writel_relaxed(val, priv->base + SATA_PORT_PHYCTL);
val &= ~(SPEED_MODE_MASK | SPEED_CTRL);
val |= SPEED_MODE_GEN2 << HALF_RATE_SHIFT |
SPEED_MODE_GEN2 << PHY_CONFIG_SHIFT |
SPEED_MODE_GEN2 << GEN2_EN_SHIFT;
writel_relaxed(val, priv->base + SATA_PORT_PHYCTL);
return 0;
}
static int hix5hd2_sata_phy_probe(struct platform_device *pdev)
{
struct phy_provider *phy_provider;
struct device *dev = &pdev->dev;
struct resource *res;
struct phy *phy;
struct hix5hd2_priv *priv;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap(dev, res->start, resource_size(res));
if (!priv->base)
return -ENOMEM;
priv->peri_ctrl = syscon_regmap_lookup_by_phandle(dev->of_node,
"hisilicon,peripheral-syscon");
if (IS_ERR(priv->peri_ctrl))
priv->peri_ctrl = NULL;
phy = devm_phy_create(dev, NULL, &hix5hd2_sata_phy_ops, NULL);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create PHY\n");
return PTR_ERR(phy);
}
phy_set_drvdata(phy, priv);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
return 0;
}
