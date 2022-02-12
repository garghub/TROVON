static int teranetics_config_init(struct phy_device *phydev)
{
phydev->supported = SUPPORTED_10000baseT_Full;
phydev->advertising = SUPPORTED_10000baseT_Full;
return 0;
}
static int teranetics_soft_reset(struct phy_device *phydev)
{
return 0;
}
static int teranetics_aneg_done(struct phy_device *phydev)
{
int reg;
if (!phy_read_mmd(phydev, MDIO_MMD_VEND1, 93)) {
reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
return (reg < 0) ? reg : (reg & BMSR_ANEGCOMPLETE);
}
return 1;
}
static int teranetics_config_aneg(struct phy_device *phydev)
{
return 0;
}
static int teranetics_read_status(struct phy_device *phydev)
{
int reg;
phydev->link = 1;
phydev->speed = SPEED_10000;
phydev->duplex = DUPLEX_FULL;
if (!phy_read_mmd(phydev, MDIO_MMD_VEND1, 93)) {
reg = phy_read_mmd(phydev, MDIO_MMD_PHYXS, MDIO_PHYXS_LNSTAT);
if (reg < 0 ||
!((reg & MDIO_PHYXS_LANE_READY) == MDIO_PHYXS_LANE_READY)) {
phydev->link = 0;
return 0;
}
reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
if (reg < 0 || !(reg & MDIO_STAT1_LSTATUS))
phydev->link = 0;
}
return 0;
}
static int teranetics_match_phy_device(struct phy_device *phydev)
{
return phydev->c45_ids.device_ids[3] == PHY_ID_TN2020;
}
