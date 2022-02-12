int genphy_c45_pma_setup_forced(struct phy_device *phydev)
{
int ctrl1, ctrl2, ret;
if (phydev->duplex != DUPLEX_FULL)
return -EINVAL;
ctrl1 = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_CTRL1);
if (ctrl1 < 0)
return ctrl1;
ctrl2 = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_CTRL2);
if (ctrl2 < 0)
return ctrl2;
ctrl1 &= ~MDIO_CTRL1_SPEEDSEL;
ctrl2 &= ~(MDIO_PMA_CTRL2_TYPE | 0x30);
switch (phydev->speed) {
case SPEED_10:
ctrl2 |= MDIO_PMA_CTRL2_10BT;
break;
case SPEED_100:
ctrl1 |= MDIO_PMA_CTRL1_SPEED100;
ctrl2 |= MDIO_PMA_CTRL2_100BTX;
break;
case SPEED_1000:
ctrl1 |= MDIO_PMA_CTRL1_SPEED1000;
ctrl2 |= MDIO_PMA_CTRL2_1000BT;
break;
case SPEED_10000:
ctrl1 |= MDIO_CTRL1_SPEED10G;
ctrl2 |= MDIO_PMA_CTRL2_10GBT;
break;
default:
return -EINVAL;
}
ret = phy_write_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_CTRL1, ctrl1);
if (ret < 0)
return ret;
return phy_write_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_CTRL2, ctrl2);
}
int genphy_c45_an_disable_aneg(struct phy_device *phydev)
{
int val;
val = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_CTRL1);
if (val < 0)
return val;
val &= ~(MDIO_AN_CTRL1_ENABLE | MDIO_AN_CTRL1_RESTART);
return phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_CTRL1, val);
}
int genphy_c45_restart_aneg(struct phy_device *phydev)
{
int val;
val = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_CTRL1);
if (val < 0)
return val;
val |= MDIO_AN_CTRL1_ENABLE | MDIO_AN_CTRL1_RESTART;
return phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_CTRL1, val);
}
int genphy_c45_aneg_done(struct phy_device *phydev)
{
int val = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
return val < 0 ? val : val & MDIO_AN_STAT1_COMPLETE ? 1 : 0;
}
int genphy_c45_read_link(struct phy_device *phydev, u32 mmd_mask)
{
int val, devad;
bool link = true;
while (mmd_mask) {
devad = __ffs(mmd_mask);
mmd_mask &= ~BIT(devad);
val = phy_read_mmd(phydev, devad, MDIO_STAT1);
if (val < 0)
return val;
if (!(val & MDIO_STAT1_LSTATUS))
link = false;
}
return link;
}
int genphy_c45_read_lpa(struct phy_device *phydev)
{
int val;
val = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_LPA);
if (val < 0)
return val;
phydev->lp_advertising = mii_lpa_to_ethtool_lpa_t(val);
phydev->pause = val & LPA_PAUSE_CAP ? 1 : 0;
phydev->asym_pause = val & LPA_PAUSE_ASYM ? 1 : 0;
val = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_10GBT_STAT);
if (val < 0)
return val;
if (val & MDIO_AN_10GBT_STAT_LP10G)
phydev->lp_advertising |= ADVERTISED_10000baseT_Full;
return 0;
}
int genphy_c45_read_pma(struct phy_device *phydev)
{
int val;
val = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_CTRL1);
if (val < 0)
return val;
switch (val & MDIO_CTRL1_SPEEDSEL) {
case 0:
phydev->speed = SPEED_10;
break;
case MDIO_PMA_CTRL1_SPEED100:
phydev->speed = SPEED_100;
break;
case MDIO_PMA_CTRL1_SPEED1000:
phydev->speed = SPEED_1000;
break;
case MDIO_CTRL1_SPEED10G:
phydev->speed = SPEED_10000;
break;
default:
phydev->speed = SPEED_UNKNOWN;
break;
}
phydev->duplex = DUPLEX_FULL;
return 0;
}
static int gen10g_config_aneg(struct phy_device *phydev)
{
return 0;
}
static int gen10g_read_status(struct phy_device *phydev)
{
u32 mmd_mask = phydev->c45_ids.devices_in_package;
int ret;
phydev->speed = SPEED_10000;
phydev->duplex = DUPLEX_FULL;
mmd_mask &= ~(BIT(MDIO_MMD_VEND1) | BIT(MDIO_MMD_VEND2));
ret = genphy_c45_read_link(phydev, mmd_mask);
phydev->link = ret > 0 ? 1 : 0;
return 0;
}
static int gen10g_soft_reset(struct phy_device *phydev)
{
return 0;
}
static int gen10g_config_init(struct phy_device *phydev)
{
phydev->supported = SUPPORTED_10000baseT_Full;
phydev->advertising = SUPPORTED_10000baseT_Full;
return 0;
}
static int gen10g_suspend(struct phy_device *phydev)
{
return 0;
}
static int gen10g_resume(struct phy_device *phydev)
{
return 0;
}
