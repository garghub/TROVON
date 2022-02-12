static int tegra_ahci_power_on(struct ahci_host_priv *hpriv)
{
struct tegra_ahci_priv *tegra = hpriv->plat_data;
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(tegra->supplies),
tegra->supplies);
if (ret)
return ret;
ret = tegra_powergate_sequence_power_up(TEGRA_POWERGATE_SATA,
tegra->sata_clk,
tegra->sata_rst);
if (ret)
goto disable_regulators;
reset_control_assert(tegra->sata_oob_rst);
reset_control_assert(tegra->sata_cold_rst);
ret = ahci_platform_enable_resources(hpriv);
if (ret)
goto disable_power;
reset_control_deassert(tegra->sata_cold_rst);
reset_control_deassert(tegra->sata_oob_rst);
return 0;
disable_power:
clk_disable_unprepare(tegra->sata_clk);
tegra_powergate_power_off(TEGRA_POWERGATE_SATA);
disable_regulators:
regulator_bulk_disable(ARRAY_SIZE(tegra->supplies), tegra->supplies);
return ret;
}
static void tegra_ahci_power_off(struct ahci_host_priv *hpriv)
{
struct tegra_ahci_priv *tegra = hpriv->plat_data;
ahci_platform_disable_resources(hpriv);
reset_control_assert(tegra->sata_rst);
reset_control_assert(tegra->sata_oob_rst);
reset_control_assert(tegra->sata_cold_rst);
clk_disable_unprepare(tegra->sata_clk);
tegra_powergate_power_off(TEGRA_POWERGATE_SATA);
regulator_bulk_disable(ARRAY_SIZE(tegra->supplies), tegra->supplies);
}
static int tegra_ahci_controller_init(struct ahci_host_priv *hpriv)
{
struct tegra_ahci_priv *tegra = hpriv->plat_data;
int ret;
unsigned int val;
struct sata_pad_calibration calib;
ret = tegra_ahci_power_on(hpriv);
if (ret) {
dev_err(&tegra->pdev->dev,
"failed to power on AHCI controller: %d\n", ret);
return ret;
}
val = readl(tegra->sata_regs + SATA_CONFIGURATION_0);
val |= SATA_CONFIGURATION_EN_FPCI;
writel(val, tegra->sata_regs + SATA_CONFIGURATION_0);
ret = tegra_fuse_readl(FUSE_SATA_CALIB, &val);
if (ret) {
dev_err(&tegra->pdev->dev,
"failed to read calibration fuse: %d\n", ret);
return ret;
}
calib = tegra124_pad_calibration[val & FUSE_SATA_CALIB_MASK];
writel(BIT(0), tegra->sata_regs + SCFG_OFFSET + T_SATA0_INDEX);
val = readl(tegra->sata_regs +
SCFG_OFFSET + T_SATA0_CHX_PHY_CTRL1_GEN1);
val &= ~T_SATA0_CHX_PHY_CTRL1_GEN1_TX_AMP_MASK;
val &= ~T_SATA0_CHX_PHY_CTRL1_GEN1_TX_PEAK_MASK;
val |= calib.gen1_tx_amp <<
T_SATA0_CHX_PHY_CTRL1_GEN1_TX_AMP_SHIFT;
val |= calib.gen1_tx_peak <<
T_SATA0_CHX_PHY_CTRL1_GEN1_TX_PEAK_SHIFT;
writel(val, tegra->sata_regs + SCFG_OFFSET +
T_SATA0_CHX_PHY_CTRL1_GEN1);
val = readl(tegra->sata_regs +
SCFG_OFFSET + T_SATA0_CHX_PHY_CTRL1_GEN2);
val &= ~T_SATA0_CHX_PHY_CTRL1_GEN2_TX_AMP_MASK;
val &= ~T_SATA0_CHX_PHY_CTRL1_GEN2_TX_PEAK_MASK;
val |= calib.gen2_tx_amp <<
T_SATA0_CHX_PHY_CTRL1_GEN1_TX_AMP_SHIFT;
val |= calib.gen2_tx_peak <<
T_SATA0_CHX_PHY_CTRL1_GEN1_TX_PEAK_SHIFT;
writel(val, tegra->sata_regs + SCFG_OFFSET +
T_SATA0_CHX_PHY_CTRL1_GEN2);
writel(T_SATA0_CHX_PHY_CTRL11_GEN2_RX_EQ,
tegra->sata_regs + SCFG_OFFSET + T_SATA0_CHX_PHY_CTRL11);
writel(T_SATA0_CHX_PHY_CTRL2_CDR_CNTL_GEN1,
tegra->sata_regs + SCFG_OFFSET + T_SATA0_CHX_PHY_CTRL2);
writel(0, tegra->sata_regs + SCFG_OFFSET + T_SATA0_INDEX);
val = readl(tegra->sata_regs + SCFG_OFFSET + T_SATA0_CFG_SATA);
val |= T_SATA0_CFG_SATA_BACKDOOR_PROG_IF_EN;
writel(val, tegra->sata_regs + SCFG_OFFSET + T_SATA0_CFG_SATA);
writel(0x01060100, tegra->sata_regs + SCFG_OFFSET + T_SATA0_BKDOOR_CC);
val = readl(tegra->sata_regs + SCFG_OFFSET + T_SATA0_CFG_SATA);
val &= ~T_SATA0_CFG_SATA_BACKDOOR_PROG_IF_EN;
writel(val, tegra->sata_regs + SCFG_OFFSET + T_SATA0_CFG_SATA);
val = readl(tegra->sata_regs + SCFG_OFFSET + T_SATA0_CFG_1);
val |= T_SATA0_CFG_1_IO_SPACE | T_SATA0_CFG_1_MEMORY_SPACE |
T_SATA0_CFG_1_BUS_MASTER | T_SATA0_CFG_1_SERR;
writel(val, tegra->sata_regs + SCFG_OFFSET + T_SATA0_CFG_1);
writel(0x10000 << SATA_FPCI_BAR5_START_SHIFT,
tegra->sata_regs + SATA_FPCI_BAR5);
writel(0x08000 << T_SATA0_CFG_9_BASE_ADDRESS_SHIFT,
tegra->sata_regs + SCFG_OFFSET + T_SATA0_CFG_9);
val = readl(tegra->sata_regs + SATA_INTR_MASK);
val |= SATA_INTR_MASK_IP_INT_MASK;
writel(val, tegra->sata_regs + SATA_INTR_MASK);
return 0;
}
static void tegra_ahci_controller_deinit(struct ahci_host_priv *hpriv)
{
tegra_ahci_power_off(hpriv);
}
static void tegra_ahci_host_stop(struct ata_host *host)
{
struct ahci_host_priv *hpriv = host->private_data;
tegra_ahci_controller_deinit(hpriv);
}
static int tegra_ahci_probe(struct platform_device *pdev)
{
struct ahci_host_priv *hpriv;
struct tegra_ahci_priv *tegra;
struct resource *res;
int ret;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
tegra = devm_kzalloc(&pdev->dev, sizeof(*tegra), GFP_KERNEL);
if (!tegra)
return -ENOMEM;
hpriv->plat_data = tegra;
tegra->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
tegra->sata_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(tegra->sata_regs))
return PTR_ERR(tegra->sata_regs);
tegra->sata_rst = devm_reset_control_get(&pdev->dev, "sata");
if (IS_ERR(tegra->sata_rst)) {
dev_err(&pdev->dev, "Failed to get sata reset\n");
return PTR_ERR(tegra->sata_rst);
}
tegra->sata_oob_rst = devm_reset_control_get(&pdev->dev, "sata-oob");
if (IS_ERR(tegra->sata_oob_rst)) {
dev_err(&pdev->dev, "Failed to get sata-oob reset\n");
return PTR_ERR(tegra->sata_oob_rst);
}
tegra->sata_cold_rst = devm_reset_control_get(&pdev->dev, "sata-cold");
if (IS_ERR(tegra->sata_cold_rst)) {
dev_err(&pdev->dev, "Failed to get sata-cold reset\n");
return PTR_ERR(tegra->sata_cold_rst);
}
tegra->sata_clk = devm_clk_get(&pdev->dev, "sata");
if (IS_ERR(tegra->sata_clk)) {
dev_err(&pdev->dev, "Failed to get sata clock\n");
return PTR_ERR(tegra->sata_clk);
}
tegra->supplies[0].supply = "avdd";
tegra->supplies[1].supply = "hvdd";
tegra->supplies[2].supply = "vddio";
tegra->supplies[3].supply = "target-5v";
tegra->supplies[4].supply = "target-12v";
ret = devm_regulator_bulk_get(&pdev->dev, ARRAY_SIZE(tegra->supplies),
tegra->supplies);
if (ret) {
dev_err(&pdev->dev, "Failed to get regulators\n");
return ret;
}
ret = tegra_ahci_controller_init(hpriv);
if (ret)
return ret;
ret = ahci_platform_init_host(pdev, hpriv, &ahci_tegra_port_info,
&ahci_platform_sht);
if (ret)
goto deinit_controller;
return 0;
deinit_controller:
tegra_ahci_controller_deinit(hpriv);
return ret;
}
