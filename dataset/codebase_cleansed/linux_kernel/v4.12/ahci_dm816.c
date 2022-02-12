static int ahci_dm816_get_mpy_bits(unsigned long refclk_rate)
{
unsigned long pll_multiplier;
int i;
pll_multiplier = AHCI_DM816_PLL_OUT / (refclk_rate / 100);
for (i = 0; i < ARRAY_SIZE(pll_mpy_table); i++) {
if (pll_mpy_table[i] == pll_multiplier)
return i;
}
return -1;
}
static int ahci_dm816_phy_init(struct ahci_host_priv *hpriv, struct device *dev)
{
unsigned long refclk_rate;
int mpy;
u32 val;
if (!hpriv->clks[1]) {
dev_err(dev, "reference clock not supplied\n");
return -EINVAL;
}
refclk_rate = clk_get_rate(hpriv->clks[1]);
if ((refclk_rate % 100) != 0) {
dev_err(dev, "reference clock rate must be divisible by 100\n");
return -EINVAL;
}
mpy = ahci_dm816_get_mpy_bits(refclk_rate);
if (mpy < 0) {
dev_err(dev, "can't calculate the MPY bits value\n");
return -EINVAL;
}
val = AHCI_DM816_PHY_MPY(mpy) | AHCI_DM816_PHY_LOS(1) |
AHCI_DM816_PHY_RXCDR(4) | AHCI_DM816_PHY_RXEQ(1) |
AHCI_DM816_PHY_TXSWING(3) | AHCI_DM816_PHY_ENPLL(1);
writel(val, hpriv->mmio + AHCI_DM816_P0PHYCR_REG);
val = AHCI_DM816_PHY_LOS(1) | AHCI_DM816_PHY_RXCDR(4) |
AHCI_DM816_PHY_RXEQ(1) | AHCI_DM816_PHY_TXSWING(3);
writel(val, hpriv->mmio + AHCI_DM816_P1PHYCR_REG);
return 0;
}
static int ahci_dm816_softreset(struct ata_link *link,
unsigned int *class, unsigned long deadline)
{
int pmp, ret;
pmp = sata_srst_pmp(link);
ret = ahci_do_softreset(link, class, pmp, deadline, ahci_check_ready);
if (pmp && ret == -EBUSY)
return ahci_do_softreset(link, class, 0,
deadline, ahci_check_ready);
return ret;
}
static int ahci_dm816_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
int rc;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
rc = ahci_dm816_phy_init(hpriv, dev);
if (rc)
goto disable_resources;
rc = ahci_platform_init_host(pdev, hpriv,
&ahci_dm816_port_info,
&ahci_dm816_platform_sht);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
