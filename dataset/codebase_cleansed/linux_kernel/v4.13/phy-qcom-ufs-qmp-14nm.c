static
int ufs_qcom_phy_qmp_14nm_phy_calibrate(struct ufs_qcom_phy *ufs_qcom_phy,
bool is_rate_B)
{
int tbl_size_A = ARRAY_SIZE(phy_cal_table_rate_A);
int tbl_size_B = ARRAY_SIZE(phy_cal_table_rate_B);
int err;
err = ufs_qcom_phy_calibrate(ufs_qcom_phy, phy_cal_table_rate_A,
tbl_size_A, phy_cal_table_rate_B, tbl_size_B, is_rate_B);
if (err)
dev_err(ufs_qcom_phy->dev,
"%s: ufs_qcom_phy_calibrate() failed %d\n",
__func__, err);
return err;
}
static
void ufs_qcom_phy_qmp_14nm_advertise_quirks(struct ufs_qcom_phy *phy_common)
{
phy_common->quirks =
UFS_QCOM_PHY_QUIRK_HIBERN8_EXIT_AFTER_PHY_PWR_COLLAPSE;
}
static int ufs_qcom_phy_qmp_14nm_init(struct phy *generic_phy)
{
return 0;
}
static int ufs_qcom_phy_qmp_14nm_exit(struct phy *generic_phy)
{
return 0;
}
static
void ufs_qcom_phy_qmp_14nm_power_control(struct ufs_qcom_phy *phy, bool val)
{
writel_relaxed(val ? 0x1 : 0x0, phy->mmio + UFS_PHY_POWER_DOWN_CONTROL);
mb();
}
static inline
void ufs_qcom_phy_qmp_14nm_set_tx_lane_enable(struct ufs_qcom_phy *phy, u32 val)
{
}
static inline void ufs_qcom_phy_qmp_14nm_start_serdes(struct ufs_qcom_phy *phy)
{
u32 tmp;
tmp = readl_relaxed(phy->mmio + UFS_PHY_PHY_START);
tmp &= ~MASK_SERDES_START;
tmp |= (1 << OFFSET_SERDES_START);
writel_relaxed(tmp, phy->mmio + UFS_PHY_PHY_START);
mb();
}
static int ufs_qcom_phy_qmp_14nm_is_pcs_ready(struct ufs_qcom_phy *phy_common)
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
static int ufs_qcom_phy_qmp_14nm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct phy *generic_phy;
struct ufs_qcom_phy_qmp_14nm *phy;
struct ufs_qcom_phy *phy_common;
int err = 0;
phy = devm_kzalloc(dev, sizeof(*phy), GFP_KERNEL);
if (!phy) {
err = -ENOMEM;
goto out;
}
phy_common = &phy->common_cfg;
generic_phy = ufs_qcom_phy_generic_probe(pdev, phy_common,
&ufs_qcom_phy_qmp_14nm_phy_ops, &phy_14nm_ops);
if (!generic_phy) {
err = -EIO;
goto out;
}
err = ufs_qcom_phy_init_clks(phy_common);
if (err)
goto out;
err = ufs_qcom_phy_init_vregulators(phy_common);
if (err)
goto out;
phy_common->vdda_phy.max_uV = UFS_PHY_VDDA_PHY_UV;
phy_common->vdda_phy.min_uV = UFS_PHY_VDDA_PHY_UV;
ufs_qcom_phy_qmp_14nm_advertise_quirks(phy_common);
phy_set_drvdata(generic_phy, phy);
strlcpy(phy_common->name, UFS_PHY_NAME, sizeof(phy_common->name));
out:
return err;
}
