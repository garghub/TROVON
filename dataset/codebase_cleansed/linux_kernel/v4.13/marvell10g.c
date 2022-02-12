static int mv3310_modify(struct phy_device *phydev, int devad, u16 reg,
u16 mask, u16 bits)
{
int old, val, ret;
old = phy_read_mmd(phydev, devad, reg);
if (old < 0)
return old;
val = (old & ~mask) | (bits & mask);
if (val == old)
return 0;
ret = phy_write_mmd(phydev, devad, reg, val);
return ret < 0 ? ret : 1;
}
static int mv3310_probe(struct phy_device *phydev)
{
u32 mmd_mask = MDIO_DEVS_PMAPMD | MDIO_DEVS_AN;
if (!phydev->is_c45 ||
(phydev->c45_ids.devices_in_package & mmd_mask) != mmd_mask)
return -ENODEV;
return 0;
}
static int mv3310_soft_reset(struct phy_device *phydev)
{
return 0;
}
static int mv3310_config_init(struct phy_device *phydev)
{
__ETHTOOL_DECLARE_LINK_MODE_MASK(supported) = { 0, };
u32 mask;
int val;
if (phydev->interface != PHY_INTERFACE_MODE_SGMII &&
phydev->interface != PHY_INTERFACE_MODE_XGMII &&
phydev->interface != PHY_INTERFACE_MODE_XAUI &&
phydev->interface != PHY_INTERFACE_MODE_RXAUI &&
phydev->interface != PHY_INTERFACE_MODE_10GKR)
return -ENODEV;
__set_bit(ETHTOOL_LINK_MODE_Pause_BIT, supported);
__set_bit(ETHTOOL_LINK_MODE_Asym_Pause_BIT, supported);
if (phydev->c45_ids.devices_in_package & MDIO_DEVS_AN) {
val = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
if (val < 0)
return val;
if (val & MDIO_AN_STAT1_ABLE)
__set_bit(ETHTOOL_LINK_MODE_Autoneg_BIT, supported);
}
val = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_STAT2);
if (val < 0)
return val;
if (val & (MDIO_PMA_STAT2_10GBSR | MDIO_PMA_STAT2_10GBLR |
MDIO_PMA_STAT2_10GBER | MDIO_PMA_STAT2_10GBLX4 |
MDIO_PMA_STAT2_10GBSW | MDIO_PMA_STAT2_10GBLW |
MDIO_PMA_STAT2_10GBEW))
__set_bit(ETHTOOL_LINK_MODE_FIBRE_BIT, supported);
if (val & MDIO_PMA_STAT2_10GBSR)
__set_bit(ETHTOOL_LINK_MODE_10000baseSR_Full_BIT, supported);
if (val & MDIO_PMA_STAT2_10GBLR)
__set_bit(ETHTOOL_LINK_MODE_10000baseLR_Full_BIT, supported);
if (val & MDIO_PMA_STAT2_10GBER)
__set_bit(ETHTOOL_LINK_MODE_10000baseER_Full_BIT, supported);
if (val & MDIO_PMA_STAT2_EXTABLE) {
val = phy_read_mmd(phydev, MDIO_MMD_PMAPMD, MDIO_PMA_EXTABLE);
if (val < 0)
return val;
if (val & (MDIO_PMA_EXTABLE_10GBT | MDIO_PMA_EXTABLE_1000BT |
MDIO_PMA_EXTABLE_100BTX | MDIO_PMA_EXTABLE_10BT))
__set_bit(ETHTOOL_LINK_MODE_TP_BIT, supported);
if (val & MDIO_PMA_EXTABLE_10GBLRM)
__set_bit(ETHTOOL_LINK_MODE_FIBRE_BIT, supported);
if (val & (MDIO_PMA_EXTABLE_10GBKX4 | MDIO_PMA_EXTABLE_10GBKR |
MDIO_PMA_EXTABLE_1000BKX))
__set_bit(ETHTOOL_LINK_MODE_Backplane_BIT, supported);
if (val & MDIO_PMA_EXTABLE_10GBLRM)
__set_bit(ETHTOOL_LINK_MODE_10000baseLRM_Full_BIT,
supported);
if (val & MDIO_PMA_EXTABLE_10GBT)
__set_bit(ETHTOOL_LINK_MODE_10000baseT_Full_BIT,
supported);
if (val & MDIO_PMA_EXTABLE_10GBKX4)
__set_bit(ETHTOOL_LINK_MODE_10000baseKX4_Full_BIT,
supported);
if (val & MDIO_PMA_EXTABLE_10GBKR)
__set_bit(ETHTOOL_LINK_MODE_10000baseKR_Full_BIT,
supported);
if (val & MDIO_PMA_EXTABLE_1000BT)
__set_bit(ETHTOOL_LINK_MODE_1000baseT_Full_BIT,
supported);
if (val & MDIO_PMA_EXTABLE_1000BKX)
__set_bit(ETHTOOL_LINK_MODE_1000baseKX_Full_BIT,
supported);
if (val & MDIO_PMA_EXTABLE_100BTX)
__set_bit(ETHTOOL_LINK_MODE_100baseT_Full_BIT,
supported);
if (val & MDIO_PMA_EXTABLE_10BT)
__set_bit(ETHTOOL_LINK_MODE_10baseT_Full_BIT,
supported);
}
if (!ethtool_convert_link_mode_to_legacy_u32(&mask, supported))
dev_warn(&phydev->mdio.dev,
"PHY supports (%*pb) more modes than phylib supports, some modes not supported.\n",
__ETHTOOL_LINK_MODE_MASK_NBITS, supported);
phydev->supported &= mask;
phydev->advertising &= phydev->supported;
return 0;
}
static int mv3310_config_aneg(struct phy_device *phydev)
{
bool changed = false;
u32 advertising;
int ret;
if (phydev->autoneg == AUTONEG_DISABLE) {
ret = genphy_c45_pma_setup_forced(phydev);
if (ret < 0)
return ret;
return genphy_c45_an_disable_aneg(phydev);
}
phydev->advertising &= phydev->supported;
advertising = phydev->advertising;
ret = mv3310_modify(phydev, MDIO_MMD_AN, MDIO_AN_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_100BASE4 |
ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM,
ethtool_adv_to_mii_adv_t(advertising));
if (ret < 0)
return ret;
if (ret > 0)
changed = true;
ret = mv3310_modify(phydev, MDIO_MMD_AN, MV_AN_CTRL1000,
ADVERTISE_1000FULL | ADVERTISE_1000HALF,
ethtool_adv_to_mii_ctrl1000_t(advertising));
if (ret < 0)
return ret;
if (ret > 0)
changed = true;
ret = mv3310_modify(phydev, MDIO_MMD_AN, MDIO_AN_10GBT_CTRL,
MDIO_AN_10GBT_CTRL_ADV10G,
advertising & ADVERTISED_10000baseT_Full ?
MDIO_AN_10GBT_CTRL_ADV10G : 0);
if (ret < 0)
return ret;
if (ret > 0)
changed = true;
if (changed)
ret = genphy_c45_restart_aneg(phydev);
return ret;
}
static int mv3310_aneg_done(struct phy_device *phydev)
{
int val;
val = phy_read_mmd(phydev, MDIO_MMD_PCS, MV_PCS_BASE_R + MDIO_STAT1);
if (val < 0)
return val;
if (val & MDIO_STAT1_LSTATUS)
return 1;
return genphy_c45_aneg_done(phydev);
}
static int mv3310_read_10gbr_status(struct phy_device *phydev)
{
phydev->link = 1;
phydev->speed = SPEED_10000;
phydev->duplex = DUPLEX_FULL;
if (phydev->interface == PHY_INTERFACE_MODE_SGMII)
phydev->interface = PHY_INTERFACE_MODE_10GKR;
return 0;
}
static int mv3310_read_status(struct phy_device *phydev)
{
u32 mmd_mask = phydev->c45_ids.devices_in_package;
int val;
mmd_mask &= ~(BIT(MDIO_MMD_VEND1) | BIT(MDIO_MMD_VEND2) |
BIT(MDIO_MMD_PHYXS));
phydev->speed = SPEED_UNKNOWN;
phydev->duplex = DUPLEX_UNKNOWN;
phydev->lp_advertising = 0;
phydev->link = 0;
phydev->pause = 0;
phydev->asym_pause = 0;
val = phy_read_mmd(phydev, MDIO_MMD_PCS, MV_PCS_BASE_R + MDIO_STAT1);
if (val < 0)
return val;
if (val & MDIO_STAT1_LSTATUS)
return mv3310_read_10gbr_status(phydev);
val = genphy_c45_read_link(phydev, mmd_mask);
if (val < 0)
return val;
phydev->link = val > 0 ? 1 : 0;
val = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
if (val < 0)
return val;
if (val & MDIO_AN_STAT1_COMPLETE) {
val = genphy_c45_read_lpa(phydev);
if (val < 0)
return val;
val = phy_read_mmd(phydev, MDIO_MMD_AN, MV_AN_STAT1000);
if (val < 0)
return val;
phydev->lp_advertising |= mii_stat1000_to_ethtool_lpa_t(val);
if (phydev->autoneg == AUTONEG_ENABLE) {
val = phy_read_mmd(phydev, MDIO_MMD_AN, MV_AN_RESULT);
if (val < 0)
return val;
if (val & MV_AN_RESULT_SPD_10000)
phydev->speed = SPEED_10000;
else if (val & MV_AN_RESULT_SPD_1000)
phydev->speed = SPEED_1000;
else if (val & MV_AN_RESULT_SPD_100)
phydev->speed = SPEED_100;
else if (val & MV_AN_RESULT_SPD_10)
phydev->speed = SPEED_10;
phydev->duplex = DUPLEX_FULL;
}
}
if (phydev->autoneg != AUTONEG_ENABLE) {
val = genphy_c45_read_pma(phydev);
if (val < 0)
return val;
}
if ((phydev->interface == PHY_INTERFACE_MODE_SGMII ||
phydev->interface == PHY_INTERFACE_MODE_10GKR) && phydev->link) {
if (phydev->speed == SPEED_10000)
phydev->interface = PHY_INTERFACE_MODE_10GKR;
else if (phydev->speed >= SPEED_10 &&
phydev->speed < SPEED_10000)
phydev->interface = PHY_INTERFACE_MODE_SGMII;
}
return 0;
}
