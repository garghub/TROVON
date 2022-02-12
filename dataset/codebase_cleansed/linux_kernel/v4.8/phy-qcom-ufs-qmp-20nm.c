static
int ufs_qcom_phy_qmp_20nm_phy_calibrate(struct ufs_qcom_phy *ufs_qcom_phy,
bool is_rate_B)
{
struct ufs_qcom_phy_calibration *tbl_A, *tbl_B;
int tbl_size_A, tbl_size_B;
u8 major = ufs_qcom_phy->host_ctrl_rev_major;
u16 minor = ufs_qcom_phy->host_ctrl_rev_minor;
u16 step = ufs_qcom_phy->host_ctrl_rev_step;
int err;
if ((major == 0x1) && (minor == 0x002) && (step == 0x0000)) {
tbl_size_A = ARRAY_SIZE(phy_cal_table_rate_A_1_2_0);
tbl_A = phy_cal_table_rate_A_1_2_0;
} else if ((major == 0x1) && (minor == 0x003) && (step == 0x0000)) {
tbl_size_A = ARRAY_SIZE(phy_cal_table_rate_A_1_3_0);
tbl_A = phy_cal_table_rate_A_1_3_0;
} else {
dev_err(ufs_qcom_phy->dev, "%s: Unknown UFS-PHY version, no calibration values\n",
__func__);
err = -ENODEV;
goto out;
}
tbl_size_B = ARRAY_SIZE(phy_cal_table_rate_B);
tbl_B = phy_cal_table_rate_B;
err = ufs_qcom_phy_calibrate(ufs_qcom_phy, tbl_A, tbl_size_A,
tbl_B, tbl_size_B, is_rate_B);
if (err)
dev_err(ufs_qcom_phy->dev, "%s: ufs_qcom_phy_calibrate() failed %d\n",
__func__, err);
out:
return err;
}
static
void ufs_qcom_phy_qmp_20nm_advertise_quirks(struct ufs_qcom_phy *phy_common)
{
phy_common->quirks =
UFS_QCOM_PHY_QUIRK_HIBERN8_EXIT_AFTER_PHY_PWR_COLLAPSE;
}
static int ufs_qcom_phy_qmp_20nm_init(struct phy *generic_phy)
{
struct ufs_qcom_phy_qmp_20nm *phy = phy_get_drvdata(generic_phy);
struct ufs_qcom_phy *phy_common = &phy->common_cfg;
int err = 0;
err = ufs_qcom_phy_init_clks(generic_phy, phy_common);
if (err) {
dev_err(phy_common->dev, "%s: ufs_qcom_phy_init_clks() failed %d\n",
__func__, err);
goto out;
}
err = ufs_qcom_phy_init_vregulators(generic_phy, phy_common);
if (err) {
dev_err(phy_common->dev, "%s: ufs_qcom_phy_init_vregulators() failed %d\n",
__func__, err);
goto out;
}
ufs_qcom_phy_qmp_20nm_advertise_quirks(phy_common);
out:
return err;
}
static
void ufs_qcom_phy_qmp_20nm_power_control(struct ufs_qcom_phy *phy, bool val)
{
bool hibern8_exit_after_pwr_collapse = phy->quirks &
UFS_QCOM_PHY_QUIRK_HIBERN8_EXIT_AFTER_PHY_PWR_COLLAPSE;
if (val) {
writel_relaxed(0x1, phy->mmio + UFS_PHY_POWER_DOWN_CONTROL);
mb();
if (hibern8_exit_after_pwr_collapse) {
usleep_range(1, 2);
writel_relaxed(0x0A, phy->mmio +
QSERDES_COM_SYSCLK_EN_SEL_TXBAND);
writel_relaxed(0x08, phy->mmio +
QSERDES_COM_SYSCLK_EN_SEL_TXBAND);
mb();
}
} else {
if (hibern8_exit_after_pwr_collapse) {
writel_relaxed(0x0A, phy->mmio +
QSERDES_COM_SYSCLK_EN_SEL_TXBAND);
writel_relaxed(0x02, phy->mmio +
QSERDES_COM_SYSCLK_EN_SEL_TXBAND);
mb();
}
writel_relaxed(0x0, phy->mmio + UFS_PHY_POWER_DOWN_CONTROL);
mb();
}
}
static
void ufs_qcom_phy_qmp_20nm_set_tx_lane_enable(struct ufs_qcom_phy *phy, u32 val)
{
writel_relaxed(val & UFS_PHY_TX_LANE_ENABLE_MASK,
phy->mmio + UFS_PHY_TX_LANE_ENABLE);
mb();
}
static inline void ufs_qcom_phy_qmp_20nm_start_serdes(struct ufs_qcom_phy *phy)
{
u32 tmp;
tmp = readl_relaxed(phy->mmio + UFS_PHY_PHY_START);
tmp &= ~MASK_SERDES_START;
tmp |= (1 << OFFSET_SERDES_START);
writel_relaxed(tmp, phy->mmio + UFS_PHY_PHY_START);
mb();
}
static int ufs_qcom_phy_qmp_20nm_is_pcs_ready(struct ufs_qcom_phy *phy_common)
{
int err = 0;
u32 val;
err = readl_poll_timeout(phy_common->mmio + UFS_PHY_PCS_READY_STATUS,
val, (val & MASK_PCS_READY), 10, 1000000);
if (err)
dev_err(phy_common->dev, "%s: poll for pcs failed err = %d\n",
__func__, err);
return err;
}
static int ufs_qcom_phy_qmp_20nm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct phy *generic_phy;
struct ufs_qcom_phy_qmp_20nm *phy;
int err = 0;
phy = devm_kzalloc(dev, sizeof(*phy), GFP_KERNEL);
if (!phy) {
err = -ENOMEM;
goto out;
}
generic_phy = ufs_qcom_phy_generic_probe(pdev, &phy->common_cfg,
&ufs_qcom_phy_qmp_20nm_phy_ops, &phy_20nm_ops);
if (!generic_phy) {
dev_err(dev, "%s: ufs_qcom_phy_generic_probe() failed\n",
__func__);
err = -EIO;
goto out;
}
phy_set_drvdata(generic_phy, phy);
strlcpy(phy->common_cfg.name, UFS_PHY_NAME,
sizeof(phy->common_cfg.name));
out:
return err;
}
static int ufs_qcom_phy_qmp_20nm_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct phy *generic_phy = to_phy(dev);
struct ufs_qcom_phy *ufs_qcom_phy = get_ufs_qcom_phy(generic_phy);
int err = 0;
err = ufs_qcom_phy_remove(generic_phy, ufs_qcom_phy);
if (err)
dev_err(dev, "%s: ufs_qcom_phy_remove failed = %d\n",
__func__, err);
return err;
}
