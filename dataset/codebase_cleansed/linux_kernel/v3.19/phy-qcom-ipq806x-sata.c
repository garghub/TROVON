static int qcom_ipq806x_sata_phy_init(struct phy *generic_phy)
{
struct qcom_ipq806x_sata_phy *phy = phy_get_drvdata(generic_phy);
u32 reg;
reg = readl_relaxed(phy->mmio + SATA_PHY_P0_PARAM3);
reg = reg | SATA_PHY_SSC_EN;
writel_relaxed(reg, phy->mmio + SATA_PHY_P0_PARAM3);
reg = readl_relaxed(phy->mmio + SATA_PHY_P0_PARAM0) &
~(SATA_PHY_P0_PARAM0_P0_TX_PREEMPH_GEN3_MASK |
SATA_PHY_P0_PARAM0_P0_TX_PREEMPH_GEN2_MASK |
SATA_PHY_P0_PARAM0_P0_TX_PREEMPH_GEN1_MASK);
reg |= SATA_PHY_P0_PARAM0_P0_TX_PREEMPH_GEN3(0xf);
writel_relaxed(reg, phy->mmio + SATA_PHY_P0_PARAM0);
reg = readl_relaxed(phy->mmio + SATA_PHY_P0_PARAM1) &
~(SATA_PHY_P0_PARAM1_P0_TX_AMPLITUDE_GEN3_MASK |
SATA_PHY_P0_PARAM1_P0_TX_AMPLITUDE_GEN2_MASK |
SATA_PHY_P0_PARAM1_P0_TX_AMPLITUDE_GEN1_MASK);
reg |= SATA_PHY_P0_PARAM1_P0_TX_AMPLITUDE_GEN3(0x55) |
SATA_PHY_P0_PARAM1_P0_TX_AMPLITUDE_GEN2(0x55) |
SATA_PHY_P0_PARAM1_P0_TX_AMPLITUDE_GEN1(0x55);
writel_relaxed(reg, phy->mmio + SATA_PHY_P0_PARAM1);
reg = readl_relaxed(phy->mmio + SATA_PHY_P0_PARAM2) &
~SATA_PHY_P0_PARAM2_RX_EQ_MASK;
reg |= SATA_PHY_P0_PARAM2_RX_EQ(0x3);
writel_relaxed(reg, phy->mmio + SATA_PHY_P0_PARAM2);
reg = readl_relaxed(phy->mmio + SATA_PHY_P0_PARAM4);
reg = reg | SATA_PHY_RESET;
writel_relaxed(reg, phy->mmio + SATA_PHY_P0_PARAM4);
reg = readl_relaxed(phy->mmio + SATA_PHY_P0_PARAM4);
reg = reg | SATA_PHY_REF_SSP_EN | SATA_PHY_RESET;
writel_relaxed(reg, phy->mmio + SATA_PHY_P0_PARAM4);
mb();
usleep_range(20, 20 + 50);
reg = readl_relaxed(phy->mmio + SATA_PHY_P0_PARAM4);
reg = reg & ~SATA_PHY_RESET;
writel_relaxed(reg, phy->mmio + SATA_PHY_P0_PARAM4);
return 0;
}
static int qcom_ipq806x_sata_phy_exit(struct phy *generic_phy)
{
struct qcom_ipq806x_sata_phy *phy = phy_get_drvdata(generic_phy);
u32 reg;
reg = readl_relaxed(phy->mmio + SATA_PHY_P0_PARAM4);
reg = reg | SATA_PHY_RESET;
writel_relaxed(reg, phy->mmio + SATA_PHY_P0_PARAM4);
return 0;
}
static int qcom_ipq806x_sata_phy_probe(struct platform_device *pdev)
{
struct qcom_ipq806x_sata_phy *phy;
struct device *dev = &pdev->dev;
struct resource *res;
struct phy_provider *phy_provider;
struct phy *generic_phy;
int ret;
phy = devm_kzalloc(dev, sizeof(*phy), GFP_KERNEL);
if (!phy)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
phy->mmio = devm_ioremap_resource(dev, res);
if (IS_ERR(phy->mmio))
return PTR_ERR(phy->mmio);
generic_phy = devm_phy_create(dev, NULL, &qcom_ipq806x_sata_phy_ops);
if (IS_ERR(generic_phy)) {
dev_err(dev, "%s: failed to create phy\n", __func__);
return PTR_ERR(generic_phy);
}
phy->dev = dev;
phy_set_drvdata(generic_phy, phy);
platform_set_drvdata(pdev, phy);
phy->cfg_clk = devm_clk_get(dev, "cfg");
if (IS_ERR(phy->cfg_clk)) {
dev_err(dev, "Failed to get sata cfg clock\n");
return PTR_ERR(phy->cfg_clk);
}
ret = clk_prepare_enable(phy->cfg_clk);
if (ret)
return ret;
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(phy_provider)) {
clk_disable_unprepare(phy->cfg_clk);
dev_err(dev, "%s: failed to register phy\n", __func__);
return PTR_ERR(phy_provider);
}
return 0;
}
static int qcom_ipq806x_sata_phy_remove(struct platform_device *pdev)
{
struct qcom_ipq806x_sata_phy *phy = platform_get_drvdata(pdev);
clk_disable_unprepare(phy->cfg_clk);
return 0;
}
