static int wait_for_phy_ready(void __iomem *reg, unsigned long bit)
{
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(3000);
while (!(__raw_readl(reg) & bit)) {
if (time_after(jiffies, timeout))
return -1;
cpu_relax();
}
return 0;
}
static int ahci_phy_init(void __iomem *mmio)
{
int i, ctrl0;
for (i = 0; i < ARRAY_SIZE(exynos4_sataphy_cmu); i++)
__raw_writeb(exynos4_sataphy_cmu[i].val,
phy_base + (exynos4_sataphy_cmu[i].reg * 4));
for (i = 0; i < ARRAY_SIZE(exynos4_sataphy_lane); i++)
__raw_writeb(exynos4_sataphy_lane[i].val,
phy_base + (LANE0 + exynos4_sataphy_lane[i].reg) * 4);
for (i = 0; i < ARRAY_SIZE(exynos4_sataphy_comlane); i++)
__raw_writeb(exynos4_sataphy_comlane[i].val,
phy_base + (COM_LANE + exynos4_sataphy_comlane[i].reg) * 4);
__raw_writeb(0x07, phy_base);
ctrl0 = __raw_readl(phy_ctrl + SATA_CTRL0);
ctrl0 |= SATA_CTRL0_PHY_CMU_RST_N;
__raw_writel(ctrl0, phy_ctrl + SATA_CTRL0);
if (wait_for_phy_ready(phy_ctrl + SATA_PHY_STATUS,
SATA_PHY_STATUS_CMU_OK) < 0) {
printk(KERN_ERR "PHY CMU not ready\n");
return -EBUSY;
}
__raw_writeb(0x03, phy_base + (COM_LANE * 4));
ctrl0 = __raw_readl(phy_ctrl + SATA_CTRL0);
ctrl0 |= SATA_CTRL0_M_PHY_LN_RST_N;
__raw_writel(ctrl0, phy_ctrl + SATA_CTRL0);
if (wait_for_phy_ready(phy_ctrl + SATA_PHY_STATUS,
SATA_PHY_STATUS_LANE_OK) < 0) {
printk(KERN_ERR "PHY LANE not ready\n");
return -EBUSY;
}
ctrl0 = __raw_readl(phy_ctrl + SATA_CTRL0);
ctrl0 |= SATA_CTRL0_M_PHY_CAL;
__raw_writel(ctrl0, phy_ctrl + SATA_CTRL0);
return 0;
}
static int exynos4_ahci_init(struct device *dev, void __iomem *mmio)
{
struct clk *clk_sata, *clk_sataphy, *clk_sclk_sata;
int val, ret;
phy_base = ioremap(EXYNOS4_PA_SATAPHY, SZ_64K);
if (!phy_base) {
dev_err(dev, "failed to allocate memory for SATA PHY\n");
return -ENOMEM;
}
phy_ctrl = ioremap(EXYNOS4_PA_SATAPHY_CTRL, SZ_16);
if (!phy_ctrl) {
dev_err(dev, "failed to allocate memory for SATA PHY CTRL\n");
ret = -ENOMEM;
goto err1;
}
clk_sata = clk_get(dev, "sata");
if (IS_ERR(clk_sata)) {
dev_err(dev, "failed to get sata clock\n");
ret = PTR_ERR(clk_sata);
clk_sata = NULL;
goto err2;
}
clk_enable(clk_sata);
clk_sataphy = clk_get(dev, "sataphy");
if (IS_ERR(clk_sataphy)) {
dev_err(dev, "failed to get sataphy clock\n");
ret = PTR_ERR(clk_sataphy);
clk_sataphy = NULL;
goto err3;
}
clk_enable(clk_sataphy);
clk_sclk_sata = clk_get(dev, "sclk_sata");
if (IS_ERR(clk_sclk_sata)) {
dev_err(dev, "failed to get sclk_sata\n");
ret = PTR_ERR(clk_sclk_sata);
clk_sclk_sata = NULL;
goto err4;
}
clk_enable(clk_sclk_sata);
clk_set_rate(clk_sclk_sata, SCLK_SATA_FREQ);
__raw_writel(S5P_PMU_SATA_PHY_CONTROL_EN, S5P_PMU_SATA_PHY_CONTROL);
val = SATA_CTRL1_RST_PMALIVE_N | SATA_CTRL1_RST_RXOOB_N |
SATA_CTRL1_RST_RX_N | SATA_CTRL1_RST_TX_N;
__raw_writel(val, phy_ctrl + SATA_CTRL1);
val = SATA_CTRL0_RX_DATA_VALID(3) | SATA_CTRL0_SPEED_MODE |
SATA_CTRL0_PHY_POR_N;
__raw_writel(val, phy_ctrl + SATA_CTRL0);
__raw_writel(0x1, mmio + HOST_PORTS_IMPL);
return ahci_phy_init(mmio);
err4:
clk_disable(clk_sataphy);
clk_put(clk_sataphy);
err3:
clk_disable(clk_sata);
clk_put(clk_sata);
err2:
iounmap(phy_ctrl);
err1:
iounmap(phy_base);
return ret;
}
