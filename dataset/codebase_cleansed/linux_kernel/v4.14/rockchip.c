static int rockchip_init_tstmode(struct phy_device *phydev)
{
int ret;
ret = phy_write(phydev, SMI_ADDR_TSTCNTL, TSTMODE_ENABLE);
if (ret)
return ret;
ret = phy_write(phydev, SMI_ADDR_TSTCNTL, TSTMODE_DISABLE);
if (ret)
return ret;
return phy_write(phydev, SMI_ADDR_TSTCNTL, TSTMODE_ENABLE);
}
static int rockchip_close_tstmode(struct phy_device *phydev)
{
return phy_write(phydev, SMI_ADDR_TSTCNTL, TSTMODE_DISABLE);
}
static int rockchip_integrated_phy_analog_init(struct phy_device *phydev)
{
int ret;
ret = rockchip_init_tstmode(phydev);
if (ret)
return ret;
ret = phy_write(phydev, SMI_ADDR_TSTWRITE, 0xB);
if (ret)
return ret;
ret = phy_write(phydev, SMI_ADDR_TSTCNTL, TSTCNTL_WR | WR_ADDR_A7CFG);
if (ret)
return ret;
return rockchip_close_tstmode(phydev);
}
static int rockchip_integrated_phy_config_init(struct phy_device *phydev)
{
int val, ret;
val = phy_read(phydev, MII_INTERNAL_CTRL_STATUS);
if (val < 0)
return val;
val &= ~MII_AUTO_MDIX_EN;
ret = phy_write(phydev, MII_INTERNAL_CTRL_STATUS, val);
if (ret)
return ret;
return rockchip_integrated_phy_analog_init(phydev);
}
static void rockchip_link_change_notify(struct phy_device *phydev)
{
int speed = SPEED_10;
if (phydev->autoneg == AUTONEG_ENABLE) {
int reg = phy_read(phydev, MII_SPECIAL_CONTROL_STATUS);
if (reg < 0) {
phydev_err(phydev, "phy_read err: %d.\n", reg);
return;
}
if (reg & MII_SPEED_100)
speed = SPEED_100;
else if (reg & MII_SPEED_10)
speed = SPEED_10;
} else {
int bmcr = phy_read(phydev, MII_BMCR);
if (bmcr < 0) {
phydev_err(phydev, "phy_read err: %d.\n", bmcr);
return;
}
if (bmcr & BMCR_SPEED100)
speed = SPEED_100;
else
speed = SPEED_10;
}
if ((phydev->speed == SPEED_10) && (speed == SPEED_100)) {
int ret = rockchip_integrated_phy_analog_init(phydev);
if (ret)
phydev_err(phydev, "rockchip_integrated_phy_analog_init err: %d.\n",
ret);
}
}
static int rockchip_set_polarity(struct phy_device *phydev, int polarity)
{
int reg, err, val;
reg = phy_read(phydev, MII_INTERNAL_CTRL_STATUS);
if (reg < 0)
return reg;
reg &= ~MII_AUTO_MDIX_EN;
val = reg;
switch (polarity) {
case ETH_TP_MDI:
val &= ~MII_MDIX_EN;
break;
case ETH_TP_MDI_X:
val |= MII_MDIX_EN;
break;
case ETH_TP_MDI_AUTO:
case ETH_TP_MDI_INVALID:
default:
return 0;
}
if (val != reg) {
err = phy_write(phydev, MII_INTERNAL_CTRL_STATUS, val);
if (err)
return err;
}
return 0;
}
static int rockchip_config_aneg(struct phy_device *phydev)
{
int err;
err = rockchip_set_polarity(phydev, phydev->mdix);
if (err < 0)
return err;
return genphy_config_aneg(phydev);
}
static int rockchip_phy_resume(struct phy_device *phydev)
{
genphy_resume(phydev);
return rockchip_integrated_phy_config_init(phydev);
}
