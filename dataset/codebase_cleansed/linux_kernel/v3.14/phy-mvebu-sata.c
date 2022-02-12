static int phy_mvebu_sata_power_on(struct phy *phy)
{
struct priv *priv = phy_get_drvdata(phy);
u32 reg;
clk_prepare_enable(priv->clk);
reg = readl(priv->base + SATA_PHY_MODE_2);
reg |= (MODE_2_FORCE_PU_TX | MODE_2_FORCE_PU_RX |
MODE_2_PU_PLL | MODE_2_PU_IVREF);
writel(reg , priv->base + SATA_PHY_MODE_2);
reg = readl(priv->base + SATA_IF_CTRL);
reg &= ~CTRL_PHY_SHUTDOWN;
writel(reg, priv->base + SATA_IF_CTRL);
clk_disable_unprepare(priv->clk);
return 0;
}
static int phy_mvebu_sata_power_off(struct phy *phy)
{
struct priv *priv = phy_get_drvdata(phy);
u32 reg;
clk_prepare_enable(priv->clk);
reg = readl(priv->base + SATA_PHY_MODE_2);
reg &= ~(MODE_2_FORCE_PU_TX | MODE_2_FORCE_PU_RX |
MODE_2_PU_PLL | MODE_2_PU_IVREF);
writel(reg, priv->base + SATA_PHY_MODE_2);
reg = readl(priv->base + SATA_IF_CTRL);
reg |= CTRL_PHY_SHUTDOWN;
writel(reg, priv->base + SATA_IF_CTRL);
clk_disable_unprepare(priv->clk);
return 0;
}
static int phy_mvebu_sata_probe(struct platform_device *pdev)
{
struct phy_provider *phy_provider;
struct resource *res;
struct priv *priv;
struct phy *phy;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
priv->clk = devm_clk_get(&pdev->dev, "sata");
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
phy = devm_phy_create(&pdev->dev, &phy_mvebu_sata_ops, NULL);
if (IS_ERR(phy))
return PTR_ERR(phy);
phy_set_drvdata(phy, priv);
phy_provider = devm_of_phy_provider_register(&pdev->dev,
of_phy_simple_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
phy_mvebu_sata_power_off(phy);
return 0;
}
