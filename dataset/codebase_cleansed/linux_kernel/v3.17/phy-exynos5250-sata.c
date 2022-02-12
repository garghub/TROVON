static int wait_for_reg_status(void __iomem *base, u32 reg, u32 checkbit,
u32 status)
{
unsigned long timeout = jiffies + PHY_PLL_TIMEOUT;
while (time_before(jiffies, timeout)) {
if ((readl(base + reg) & checkbit) == status)
return 0;
}
return -EFAULT;
}
static int exynos_sata_phy_power_on(struct phy *phy)
{
struct exynos_sata_phy *sata_phy = phy_get_drvdata(phy);
return regmap_update_bits(sata_phy->pmureg, SATAPHY_CONTROL_OFFSET,
EXYNOS5_SATAPHY_PMU_ENABLE, true);
}
static int exynos_sata_phy_power_off(struct phy *phy)
{
struct exynos_sata_phy *sata_phy = phy_get_drvdata(phy);
return regmap_update_bits(sata_phy->pmureg, SATAPHY_CONTROL_OFFSET,
EXYNOS5_SATAPHY_PMU_ENABLE, false);
}
static int exynos_sata_phy_init(struct phy *phy)
{
u32 val = 0;
int ret = 0;
u8 buf[] = { 0x3a, 0x0b };
struct exynos_sata_phy *sata_phy = phy_get_drvdata(phy);
ret = regmap_update_bits(sata_phy->pmureg, SATAPHY_CONTROL_OFFSET,
EXYNOS5_SATAPHY_PMU_ENABLE, true);
if (ret != 0)
dev_err(&sata_phy->phy->dev, "phy init failed\n");
writel(val, sata_phy->regs + EXYNOS5_SATA_RESET);
val = readl(sata_phy->regs + EXYNOS5_SATA_RESET);
val |= RESET_GLOBAL_RST_N | RESET_CMN_RST_N | RESET_CMN_BLOCK_RST_N
| RESET_CMN_I2C_RST_N | RESET_TX_RX_PIPE_RST_N
| RESET_TX_RX_BLOCK_RST_N | RESET_TX_RX_I2C_RST_N;
writel(val, sata_phy->regs + EXYNOS5_SATA_RESET);
val = readl(sata_phy->regs + EXYNOS5_SATA_RESET);
val |= LINK_RESET;
writel(val, sata_phy->regs + EXYNOS5_SATA_RESET);
val = readl(sata_phy->regs + EXYNOS5_SATA_RESET);
val |= RESET_CMN_RST_N;
writel(val, sata_phy->regs + EXYNOS5_SATA_RESET);
val = readl(sata_phy->regs + EXYNOS5_SATA_PHSATA_CTRLM);
val &= ~PHCTRLM_REF_RATE;
writel(val, sata_phy->regs + EXYNOS5_SATA_PHSATA_CTRLM);
val = readl(sata_phy->regs + EXYNOS5_SATA_PHSATA_CTRLM);
val |= PHCTRLM_HIGH_SPEED;
writel(val, sata_phy->regs + EXYNOS5_SATA_PHSATA_CTRLM);
val = readl(sata_phy->regs + EXYNOS5_SATA_CTRL0);
val |= CTRL0_P0_PHY_CALIBRATED_SEL | CTRL0_P0_PHY_CALIBRATED;
writel(val, sata_phy->regs + EXYNOS5_SATA_CTRL0);
val = readl(sata_phy->regs + EXYNOS5_SATA_MODE0);
val |= SATA_SPD_GEN3;
writel(val, sata_phy->regs + EXYNOS5_SATA_MODE0);
ret = i2c_master_send(sata_phy->client, buf, sizeof(buf));
if (ret < 0)
return ret;
val = readl(sata_phy->regs + EXYNOS5_SATA_RESET);
val &= ~RESET_CMN_RST_N;
writel(val, sata_phy->regs + EXYNOS5_SATA_RESET);
val = readl(sata_phy->regs + EXYNOS5_SATA_RESET);
val |= RESET_CMN_RST_N;
writel(val, sata_phy->regs + EXYNOS5_SATA_RESET);
ret = wait_for_reg_status(sata_phy->regs,
EXYNOS5_SATA_PHSATA_STATM,
PHSTATM_PLL_LOCKED, 1);
if (ret < 0)
dev_err(&sata_phy->phy->dev,
"PHY PLL locking failed\n");
return ret;
}
static int exynos_sata_phy_probe(struct platform_device *pdev)
{
struct exynos_sata_phy *sata_phy;
struct device *dev = &pdev->dev;
struct resource *res;
struct phy_provider *phy_provider;
struct device_node *node;
int ret = 0;
sata_phy = devm_kzalloc(dev, sizeof(*sata_phy), GFP_KERNEL);
if (!sata_phy)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sata_phy->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(sata_phy->regs))
return PTR_ERR(sata_phy->regs);
sata_phy->pmureg = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,syscon-phandle");
if (IS_ERR(sata_phy->pmureg)) {
dev_err(dev, "syscon regmap lookup failed.\n");
return PTR_ERR(sata_phy->pmureg);
}
node = of_parse_phandle(dev->of_node,
"samsung,exynos-sataphy-i2c-phandle", 0);
if (!node)
return -EINVAL;
sata_phy->client = of_find_i2c_device_by_node(node);
if (!sata_phy->client)
return -EPROBE_DEFER;
dev_set_drvdata(dev, sata_phy);
sata_phy->phyclk = devm_clk_get(dev, "sata_phyctrl");
if (IS_ERR(sata_phy->phyclk)) {
dev_err(dev, "failed to get clk for PHY\n");
return PTR_ERR(sata_phy->phyclk);
}
ret = clk_prepare_enable(sata_phy->phyclk);
if (ret < 0) {
dev_err(dev, "failed to enable source clk\n");
return ret;
}
sata_phy->phy = devm_phy_create(dev, NULL, &exynos_sata_phy_ops, NULL);
if (IS_ERR(sata_phy->phy)) {
clk_disable_unprepare(sata_phy->phyclk);
dev_err(dev, "failed to create PHY\n");
return PTR_ERR(sata_phy->phy);
}
phy_set_drvdata(sata_phy->phy, sata_phy);
phy_provider = devm_of_phy_provider_register(dev,
of_phy_simple_xlate);
if (IS_ERR(phy_provider)) {
clk_disable_unprepare(sata_phy->phyclk);
return PTR_ERR(phy_provider);
}
return 0;
}
