static void exynos_pcie_phy_writel(void __iomem *base, u32 val, u32 offset)
{
writel(val, base + offset);
}
static u32 exynos_pcie_phy_readl(void __iomem *base, u32 offset)
{
return readl(base + offset);
}
static int exynos5440_pcie_phy_init(struct phy *phy)
{
struct exynos_pcie_phy *ep = phy_get_drvdata(phy);
exynos_pcie_phy_writel(ep->phy_base, 0x29, PCIE_PHY_DCC_FEEDBACK);
exynos_pcie_phy_writel(ep->phy_base, 0xd5, PCIE_PHY_IMPEDANCE);
exynos_pcie_phy_writel(ep->phy_base, 0x14, PCIE_PHY_PLL_DIV_0);
exynos_pcie_phy_writel(ep->phy_base, 0x12, PCIE_PHY_PLL_DIV_1);
exynos_pcie_phy_writel(ep->phy_base, 0x7f, PCIE_PHY_TRSV0_DRV_LVL);
exynos_pcie_phy_writel(ep->phy_base, 0x0, PCIE_PHY_TRSV0_EMP_LVL);
exynos_pcie_phy_writel(ep->phy_base, 0xe7, PCIE_PHY_PLL_BIAS);
exynos_pcie_phy_writel(ep->phy_base, 0x82, PCIE_PHY_TRSV0_RXCDR);
exynos_pcie_phy_writel(ep->phy_base, 0x82, PCIE_PHY_TRSV1_RXCDR);
exynos_pcie_phy_writel(ep->phy_base, 0x82, PCIE_PHY_TRSV2_RXCDR);
exynos_pcie_phy_writel(ep->phy_base, 0x82, PCIE_PHY_TRSV3_RXCDR);
exynos_pcie_phy_writel(ep->phy_base, 0x39, PCIE_PHY_TRSV0_EMP_LVL);
exynos_pcie_phy_writel(ep->phy_base, 0x39, PCIE_PHY_TRSV1_EMP_LVL);
exynos_pcie_phy_writel(ep->phy_base, 0x39, PCIE_PHY_TRSV2_EMP_LVL);
exynos_pcie_phy_writel(ep->phy_base, 0x39, PCIE_PHY_TRSV3_EMP_LVL);
exynos_pcie_phy_writel(ep->phy_base, 0x20, PCIE_PHY_TRSV0_LVCC);
exynos_pcie_phy_writel(ep->phy_base, 0xa0, PCIE_PHY_TRSV1_LVCC);
exynos_pcie_phy_writel(ep->phy_base, 0xa0, PCIE_PHY_TRSV2_LVCC);
exynos_pcie_phy_writel(ep->phy_base, 0xa0, PCIE_PHY_TRSV3_LVCC);
exynos_pcie_phy_writel(ep->blk_base, 1, PCIE_PHY_COMMON_RESET);
udelay(500);
exynos_pcie_phy_writel(ep->blk_base, 0, PCIE_PHY_COMMON_RESET);
return 0;
}
static int exynos5440_pcie_phy_power_on(struct phy *phy)
{
struct exynos_pcie_phy *ep = phy_get_drvdata(phy);
u32 val;
exynos_pcie_phy_writel(ep->blk_base, 0, PCIE_PHY_COMMON_RESET);
exynos_pcie_phy_writel(ep->blk_base, 0, PCIE_PHY_CMN_REG);
exynos_pcie_phy_writel(ep->blk_base, 0, PCIE_PHY_TRSVREG_RESET);
exynos_pcie_phy_writel(ep->blk_base, 0, PCIE_PHY_TRSV_RESET);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_COMMON_POWER);
val &= ~PCIE_PHY_COMMON_PD_CMN;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_COMMON_POWER);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_TRSV0_POWER);
val &= ~PCIE_PHY_TRSV0_PD_TSV;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_TRSV0_POWER);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_TRSV1_POWER);
val &= ~PCIE_PHY_TRSV1_PD_TSV;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_TRSV1_POWER);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_TRSV2_POWER);
val &= ~PCIE_PHY_TRSV2_PD_TSV;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_TRSV2_POWER);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_TRSV3_POWER);
val &= ~PCIE_PHY_TRSV3_PD_TSV;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_TRSV3_POWER);
return 0;
}
static int exynos5440_pcie_phy_power_off(struct phy *phy)
{
struct exynos_pcie_phy *ep = phy_get_drvdata(phy);
u32 val;
if (readl_poll_timeout(ep->phy_base + PCIE_PHY_PLL_LOCKED, val,
(val != 0), 1, 500)) {
dev_err(&phy->dev, "PLL Locked: 0x%x\n", val);
return -ETIMEDOUT;
}
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_COMMON_POWER);
val |= PCIE_PHY_COMMON_PD_CMN;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_COMMON_POWER);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_TRSV0_POWER);
val |= PCIE_PHY_TRSV0_PD_TSV;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_TRSV0_POWER);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_TRSV1_POWER);
val |= PCIE_PHY_TRSV1_PD_TSV;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_TRSV1_POWER);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_TRSV2_POWER);
val |= PCIE_PHY_TRSV2_PD_TSV;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_TRSV2_POWER);
val = exynos_pcie_phy_readl(ep->phy_base, PCIE_PHY_TRSV3_POWER);
val |= PCIE_PHY_TRSV3_PD_TSV;
exynos_pcie_phy_writel(ep->phy_base, val, PCIE_PHY_TRSV3_POWER);
return 0;
}
static int exynos5440_pcie_phy_reset(struct phy *phy)
{
struct exynos_pcie_phy *ep = phy_get_drvdata(phy);
exynos_pcie_phy_writel(ep->blk_base, 0, PCIE_PHY_MAC_RESET);
exynos_pcie_phy_writel(ep->blk_base, 1, PCIE_PHY_GLOBAL_RESET);
exynos_pcie_phy_writel(ep->blk_base, 0, PCIE_PHY_GLOBAL_RESET);
return 0;
}
static int exynos_pcie_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct exynos_pcie_phy *exynos_phy;
struct phy *generic_phy;
struct phy_provider *phy_provider;
struct resource *res;
const struct exynos_pcie_phy_data *drv_data;
drv_data = of_device_get_match_data(dev);
if (!drv_data)
return -ENODEV;
exynos_phy = devm_kzalloc(dev, sizeof(*exynos_phy), GFP_KERNEL);
if (!exynos_phy)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
exynos_phy->phy_base = devm_ioremap_resource(dev, res);
if (IS_ERR(exynos_phy->phy_base))
return PTR_ERR(exynos_phy->phy_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
exynos_phy->blk_base = devm_ioremap_resource(dev, res);
if (IS_ERR(exynos_phy->blk_base))
return PTR_ERR(exynos_phy->blk_base);
exynos_phy->drv_data = drv_data;
generic_phy = devm_phy_create(dev, dev->of_node, drv_data->ops);
if (IS_ERR(generic_phy)) {
dev_err(dev, "failed to create PHY\n");
return PTR_ERR(generic_phy);
}
phy_set_drvdata(generic_phy, exynos_phy);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
