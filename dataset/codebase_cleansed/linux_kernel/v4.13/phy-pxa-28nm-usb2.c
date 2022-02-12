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
static int mv_usb2_phy_28nm_init(struct phy *phy)
{
struct mv_usb2_phy *mv_phy = phy_get_drvdata(phy);
struct platform_device *pdev = mv_phy->pdev;
void __iomem *base = mv_phy->base;
u32 reg;
int ret;
clk_prepare_enable(mv_phy->clk);
reg = readl(base + PHY_28NM_PLL_REG0) &
~(PHY_28NM_PLL_SELLPFR_MASK | PHY_28NM_PLL_FBDIV_MASK
| PHY_28NM_PLL_ICP_MASK | PHY_28NM_PLL_REFDIV_MASK);
writel(reg | (0x1 << PHY_28NM_PLL_SELLPFR_SHIFT
| 0xf0 << PHY_28NM_PLL_FBDIV_SHIFT
| 0x3 << PHY_28NM_PLL_ICP_SHIFT
| 0xd << PHY_28NM_PLL_REFDIV_SHIFT),
base + PHY_28NM_PLL_REG0);
reg = readl(base + PHY_28NM_PLL_REG1);
writel(reg | PHY_28NM_PLL_PU_PLL | PHY_28NM_PLL_PU_BY_REG,
base + PHY_28NM_PLL_REG1);
reg = readl(base + PHY_28NM_TX_REG0) & ~PHY_28NM_TX_AMP_MASK;
writel(reg | PHY_28NM_TX_PU_BY_REG | 0x3 << PHY_28NM_TX_AMP_SHIFT |
PHY_28NM_TX_PU_ANA,
base + PHY_28NM_TX_REG0);
reg = readl(base + PHY_28NM_RX_REG0) & ~PHY_28NM_RX_SQ_THRESH_MASK;
writel(reg | 0xa << PHY_28NM_RX_SQ_THRESH_SHIFT,
base + PHY_28NM_RX_REG0);
reg = readl(base + PHY_28NM_DIG_REG0) &
~(PHY_28NM_DIG_BITSTAFFING_ERR | PHY_28NM_DIG_SYNC_ERR |
PHY_28NM_DIG_SQ_FILT_MASK | PHY_28NM_DIG_SQ_BLK_MASK |
PHY_28NM_DIG_SYNC_NUM_MASK);
writel(reg | (0x1 << PHY_28NM_DIG_SYNC_NUM_SHIFT |
PHY_28NM_PLL_LOCK_BYPASS),
base + PHY_28NM_DIG_REG0);
reg = readl(base + PHY_28NM_OTG_REG) | PHY_28NM_OTG_PU_OTG;
writel(reg & ~PHY_28NM_OTG_CONTROL_BY_PIN, base + PHY_28NM_OTG_REG);
if (!wait_for_reg(base + PHY_28NM_CAL_REG,
PHY_28NM_PLL_PLLCAL_DONE | PHY_28NM_PLL_IMPCAL_DONE,
HZ / 10)) {
dev_warn(&pdev->dev, "USB PHY PLL calibrate not done after 100mS.");
ret = -ETIMEDOUT;
goto err_clk;
}
if (!wait_for_reg(base + PHY_28NM_RX_REG1,
PHY_28NM_RX_SQCAL_DONE, HZ / 10)) {
dev_warn(&pdev->dev, "USB PHY RX SQ calibrate not done after 100mS.");
ret = -ETIMEDOUT;
goto err_clk;
}
if (!wait_for_reg(base + PHY_28NM_PLL_REG0,
PHY_28NM_PLL_READY, HZ / 10)) {
dev_warn(&pdev->dev, "PLL_READY not set after 100mS.");
ret = -ETIMEDOUT;
goto err_clk;
}
return 0;
err_clk:
clk_disable_unprepare(mv_phy->clk);
return ret;
}
static int mv_usb2_phy_28nm_power_on(struct phy *phy)
{
struct mv_usb2_phy *mv_phy = phy_get_drvdata(phy);
void __iomem *base = mv_phy->base;
writel(readl(base + PHY_28NM_CTRL_REG3) |
(PHY_28NM_CTRL3_OVERWRITE | PHY_28NM_CTRL3_VBUS_VALID |
PHY_28NM_CTRL3_AVALID | PHY_28NM_CTRL3_BVALID),
base + PHY_28NM_CTRL_REG3);
return 0;
}
static int mv_usb2_phy_28nm_power_off(struct phy *phy)
{
struct mv_usb2_phy *mv_phy = phy_get_drvdata(phy);
void __iomem *base = mv_phy->base;
writel(readl(base + PHY_28NM_CTRL_REG3) |
~(PHY_28NM_CTRL3_OVERWRITE | PHY_28NM_CTRL3_VBUS_VALID
| PHY_28NM_CTRL3_AVALID | PHY_28NM_CTRL3_BVALID),
base + PHY_28NM_CTRL_REG3);
return 0;
}
static int mv_usb2_phy_28nm_exit(struct phy *phy)
{
struct mv_usb2_phy *mv_phy = phy_get_drvdata(phy);
void __iomem *base = mv_phy->base;
unsigned int val;
val = readw(base + PHY_28NM_PLL_REG1);
val &= ~PHY_28NM_PLL_PU_PLL;
writew(val, base + PHY_28NM_PLL_REG1);
val = readw(base + PHY_28NM_TX_REG0);
val &= ~PHY_28NM_TX_PU_ANA;
writew(val, base + PHY_28NM_TX_REG0);
val = readw(base + PHY_28NM_OTG_REG);
val &= ~PHY_28NM_OTG_PU_OTG;
writew(val, base + PHY_28NM_OTG_REG);
clk_disable_unprepare(mv_phy->clk);
return 0;
}
static int mv_usb2_phy_probe(struct platform_device *pdev)
{
struct phy_provider *phy_provider;
struct mv_usb2_phy *mv_phy;
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
mv_phy->phy = devm_phy_create(&pdev->dev, pdev->dev.of_node, &usb_ops);
if (IS_ERR(mv_phy->phy))
return PTR_ERR(mv_phy->phy);
phy_set_drvdata(mv_phy->phy, mv_phy);
phy_provider = devm_of_phy_provider_register(&pdev->dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
