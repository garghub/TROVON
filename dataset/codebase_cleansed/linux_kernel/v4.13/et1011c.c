static int et1011c_config_aneg(struct phy_device *phydev)
{
int ctl = 0;
ctl = phy_read(phydev, MII_BMCR);
if (ctl < 0)
return ctl;
ctl &= ~(BMCR_FULLDPLX | BMCR_SPEED100 | BMCR_SPEED1000 |
BMCR_ANENABLE);
phy_write(phydev, MII_BMCR, ctl | BMCR_RESET);
return genphy_config_aneg(phydev);
}
static int et1011c_read_status(struct phy_device *phydev)
{
int ret;
u32 val;
static int speed;
ret = genphy_read_status(phydev);
if (speed != phydev->speed) {
speed = phydev->speed;
val = phy_read(phydev, ET1011C_STATUS_REG);
if ((val & ET1011C_SPEED_MASK) ==
ET1011C_GIGABIT_SPEED) {
val = phy_read(phydev, ET1011C_CONFIG_REG);
val &= ~ET1011C_TX_FIFO_MASK;
phy_write(phydev, ET1011C_CONFIG_REG, val\
| ET1011C_GMII_INTERFACE\
| ET1011C_SYS_CLK_EN\
| ET1011C_TX_FIFO_DEPTH_16);
}
}
return ret;
}
