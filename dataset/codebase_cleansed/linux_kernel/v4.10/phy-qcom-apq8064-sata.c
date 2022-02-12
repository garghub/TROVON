static int read_poll_timeout(void __iomem *addr, u32 mask)
{
unsigned long timeout = jiffies + msecs_to_jiffies(TIMEOUT_MS);
do {
if (readl_relaxed(addr) & mask)
return 0;
usleep_range(DELAY_INTERVAL_US, DELAY_INTERVAL_US + 50);
} while (!time_after(jiffies, timeout));
return (readl_relaxed(addr) & mask) ? 0 : -ETIMEDOUT;
}
static int qcom_apq8064_sata_phy_init(struct phy *generic_phy)
{
struct qcom_apq8064_sata_phy *phy = phy_get_drvdata(generic_phy);
void __iomem *base = phy->mmio;
int ret = 0;
writel_relaxed(0x01, base + SATA_PHY_SER_CTRL);
writel_relaxed(0xB1, base + SATA_PHY_POW_DWN_CTRL0);
mb();
usleep_range(10, 60);
writel_relaxed(0x01, base + SATA_PHY_POW_DWN_CTRL0);
writel_relaxed(0x3E, base + SATA_PHY_POW_DWN_CTRL1);
writel_relaxed(0x01, base + SATA_PHY_RX_IMCAL0);
writel_relaxed(0x01, base + SATA_PHY_TX_IMCAL0);
writel_relaxed(0x02, base + SATA_PHY_TX_IMCAL2);
writel_relaxed(0x04, base + UNIPHY_PLL_REFCLK_CFG);
writel_relaxed(0x00, base + UNIPHY_PLL_PWRGEN_CFG);
writel_relaxed(0x0A, base + UNIPHY_PLL_CAL_CFG0);
writel_relaxed(0xF3, base + UNIPHY_PLL_CAL_CFG8);
writel_relaxed(0x01, base + UNIPHY_PLL_CAL_CFG9);
writel_relaxed(0xED, base + UNIPHY_PLL_CAL_CFG10);
writel_relaxed(0x02, base + UNIPHY_PLL_CAL_CFG11);
writel_relaxed(0x36, base + UNIPHY_PLL_SDM_CFG0);
writel_relaxed(0x0D, base + UNIPHY_PLL_SDM_CFG1);
writel_relaxed(0xA3, base + UNIPHY_PLL_SDM_CFG2);
writel_relaxed(0xF0, base + UNIPHY_PLL_SDM_CFG3);
writel_relaxed(0x00, base + UNIPHY_PLL_SDM_CFG4);
writel_relaxed(0x19, base + UNIPHY_PLL_SSC_CFG0);
writel_relaxed(0xE1, base + UNIPHY_PLL_SSC_CFG1);
writel_relaxed(0x00, base + UNIPHY_PLL_SSC_CFG2);
writel_relaxed(0x11, base + UNIPHY_PLL_SSC_CFG3);
writel_relaxed(0x04, base + UNIPHY_PLL_LKDET_CFG0);
writel_relaxed(0xFF, base + UNIPHY_PLL_LKDET_CFG1);
writel_relaxed(0x02, base + UNIPHY_PLL_GLB_CFG);
mb();
writel_relaxed(0x03, base + UNIPHY_PLL_GLB_CFG);
writel_relaxed(0x05, base + UNIPHY_PLL_LKDET_CFG2);
ret = read_poll_timeout(base + UNIPHY_PLL_STATUS, UNIPHY_PLL_LOCK);
if (ret) {
dev_err(phy->dev, "poll timeout UNIPHY_PLL_STATUS\n");
return ret;
}
ret = read_poll_timeout(base + SATA_PHY_TX_IMCAL_STAT, SATA_PHY_TX_CAL);
if (ret) {
dev_err(phy->dev, "poll timeout SATA_PHY_TX_IMCAL_STAT\n");
return ret;
}
ret = read_poll_timeout(base + SATA_PHY_RX_IMCAL_STAT, SATA_PHY_RX_CAL);
if (ret) {
dev_err(phy->dev, "poll timeout SATA_PHY_RX_IMCAL_STAT\n");
return ret;
}
writel_relaxed(0x3E, base + SATA_PHY_POW_DWN_CTRL1);
writel_relaxed(0x01, base + SATA_PHY_RX_IMCAL0);
writel_relaxed(0x01, base + SATA_PHY_TX_IMCAL0);
writel_relaxed(0x00, base + SATA_PHY_POW_DWN_CTRL1);
writel_relaxed(0x59, base + SATA_PHY_CDR_CTRL0);
writel_relaxed(0x04, base + SATA_PHY_CDR_CTRL1);
writel_relaxed(0x00, base + SATA_PHY_CDR_CTRL2);
writel_relaxed(0x00, base + SATA_PHY_PI_CTRL0);
writel_relaxed(0x00, base + SATA_PHY_CDR_CTRL3);
writel_relaxed(0x01, base + SATA_PHY_POW_DWN_CTRL0);
writel_relaxed(0x11, base + SATA_PHY_TX_DATA_CTRL);
writel_relaxed(0x43, base + SATA_PHY_ALIGNP);
writel_relaxed(0x04, base + SATA_PHY_OOB_TERM);
writel_relaxed(0x01, base + SATA_PHY_EQUAL);
writel_relaxed(0x09, base + SATA_PHY_TX_DRIV_CTRL0);
writel_relaxed(0x09, base + SATA_PHY_TX_DRIV_CTRL1);
return 0;
}
static int qcom_apq8064_sata_phy_exit(struct phy *generic_phy)
{
struct qcom_apq8064_sata_phy *phy = phy_get_drvdata(generic_phy);
void __iomem *base = phy->mmio;
writel_relaxed(0xF8, base + SATA_PHY_POW_DWN_CTRL0);
writel_relaxed(0xFE, base + SATA_PHY_POW_DWN_CTRL1);
writel_relaxed(0x00, base + UNIPHY_PLL_GLB_CFG);
return 0;
}
static int qcom_apq8064_sata_phy_probe(struct platform_device *pdev)
{
struct qcom_apq8064_sata_phy *phy;
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
generic_phy = devm_phy_create(dev, NULL, &qcom_apq8064_sata_phy_ops);
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
static int qcom_apq8064_sata_phy_remove(struct platform_device *pdev)
{
struct qcom_apq8064_sata_phy *phy = platform_get_drvdata(pdev);
clk_disable_unprepare(phy->cfg_clk);
return 0;
}
