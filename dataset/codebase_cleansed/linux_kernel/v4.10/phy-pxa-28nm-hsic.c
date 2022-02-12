static bool wait_for_reg(void __iomem *reg, u32 mask, unsigned long timeout)
{
timeout += jiffies;
while (time_is_after_eq_jiffies(timeout)) {
if ((readl(reg) & mask) == mask)
return true;
msleep(1);
}
return false;
}
static int mv_hsic_phy_init(struct phy *phy)
{
struct mv_hsic_phy *mv_phy = phy_get_drvdata(phy);
struct platform_device *pdev = mv_phy->pdev;
void __iomem *base = mv_phy->base;
clk_prepare_enable(mv_phy->clk);
writel(0x1 << PHY_28NM_HSIC_PLL_SELLPFR_SHIFT |
0xf0 << PHY_28NM_HSIC_PLL_FBDIV_SHIFT |
0xd << PHY_28NM_HSIC_PLL_REFDIV_SHIFT,
base + PHY_28NM_HSIC_PLL_CTRL01);
writel(readl(base + PHY_28NM_HSIC_PLL_CTRL2) |
PHY_28NM_HSIC_S2H_PU_PLL,
base + PHY_28NM_HSIC_PLL_CTRL2);
if (!wait_for_reg(base + PHY_28NM_HSIC_PLL_CTRL2,
PHY_28NM_HSIC_H2S_PLL_LOCK, HZ / 10)) {
dev_err(&pdev->dev, "HSIC PHY PLL not locked after 100mS.");
clk_disable_unprepare(mv_phy->clk);
return -ETIMEDOUT;
}
return 0;
}
static int mv_hsic_phy_power_on(struct phy *phy)
{
struct mv_hsic_phy *mv_phy = phy_get_drvdata(phy);
struct platform_device *pdev = mv_phy->pdev;
void __iomem *base = mv_phy->base;
u32 reg;
reg = readl(base + PHY_28NM_HSIC_CTRL);
reg &= ~S2H_DRV_SE0_4RESUME;
reg |= PHY_28NM_HSIC_S2H_HSIC_EN;
writel(reg, base + PHY_28NM_HSIC_CTRL);
if (!wait_for_reg(base + PHY_28NM_HSIC_IMPCAL_CAL,
PHY_28NM_HSIC_H2S_IMPCAL_DONE, HZ / 10)) {
dev_warn(&pdev->dev, "HSIC PHY READY not set after 100mS.");
return -ETIMEDOUT;
}
if (!wait_for_reg(base + PHY_28NM_HSIC_INT,
PHY_28NM_HSIC_CONNECT_INT, HZ / 5)) {
dev_warn(&pdev->dev, "HSIC wait for connect interrupt timeout.");
return -ETIMEDOUT;
}
return 0;
}
static int mv_hsic_phy_power_off(struct phy *phy)
{
struct mv_hsic_phy *mv_phy = phy_get_drvdata(phy);
void __iomem *base = mv_phy->base;
writel(readl(base + PHY_28NM_HSIC_CTRL) & ~PHY_28NM_HSIC_S2H_HSIC_EN,
base + PHY_28NM_HSIC_CTRL);
return 0;
}
static int mv_hsic_phy_exit(struct phy *phy)
{
struct mv_hsic_phy *mv_phy = phy_get_drvdata(phy);
void __iomem *base = mv_phy->base;
writel(readl(base + PHY_28NM_HSIC_PLL_CTRL2) &
~PHY_28NM_HSIC_S2H_PU_PLL,
base + PHY_28NM_HSIC_PLL_CTRL2);
clk_disable_unprepare(mv_phy->clk);
return 0;
}
static int mv_hsic_phy_probe(struct platform_device *pdev)
{
struct phy_provider *phy_provider;
struct mv_hsic_phy *mv_phy;
struct resource *r;
mv_phy = devm_kzalloc(&pdev->dev, sizeof(*mv_phy), GFP_KERNEL);
if (!mv_phy)
return -ENOMEM;
mv_phy->pdev = pdev;
mv_phy->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(mv_phy->clk)) {
dev_err(&pdev->dev, "failed to get clock.\n");
return PTR_ERR(mv_phy->clk);
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mv_phy->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(mv_phy->base))
return PTR_ERR(mv_phy->base);
mv_phy->phy = devm_phy_create(&pdev->dev, pdev->dev.of_node, &hsic_ops);
if (IS_ERR(mv_phy->phy))
return PTR_ERR(mv_phy->phy);
phy_set_drvdata(mv_phy->phy, mv_phy);
phy_provider = devm_of_phy_provider_register(&pdev->dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
