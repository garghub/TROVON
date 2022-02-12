static int aquantia_config_aneg(struct phy_device *phydev)
{
phydev->supported = PHY_AQUANTIA_FEATURES;
phydev->advertising = phydev->supported;
return 0;
}
static int aquantia_aneg_done(struct phy_device *phydev)
{
int reg;
reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
return (reg < 0) ? reg : (reg & BMSR_ANEGCOMPLETE);
}
static int aquantia_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
err = phy_write_mmd(phydev, MDIO_MMD_AN, 0xd401, 1);
if (err < 0)
return err;
err = phy_write_mmd(phydev, MDIO_MMD_VEND1, 0xff00, 1);
if (err < 0)
return err;
err = phy_write_mmd(phydev, MDIO_MMD_VEND1, 0xff01, 0x1001);
} else {
err = phy_write_mmd(phydev, MDIO_MMD_AN, 0xd401, 0);
if (err < 0)
return err;
err = phy_write_mmd(phydev, MDIO_MMD_VEND1, 0xff00, 0);
if (err < 0)
return err;
err = phy_write_mmd(phydev, MDIO_MMD_VEND1, 0xff01, 0);
}
return err;
}
static int aquantia_ack_interrupt(struct phy_device *phydev)
{
int reg;
reg = phy_read_mmd(phydev, MDIO_MMD_AN, 0xcc01);
return (reg < 0) ? reg : 0;
}
static int aquantia_read_status(struct phy_device *phydev)
{
int reg;
reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
reg = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_STAT1);
if (reg & MDIO_STAT1_LSTATUS)
phydev->link = 1;
else
phydev->link = 0;
reg = phy_read_mmd(phydev, MDIO_MMD_AN, 0xc800);
mdelay(10);
reg = phy_read_mmd(phydev, MDIO_MMD_AN, 0xc800);
switch (reg) {
case 0x9:
phydev->speed = SPEED_2500;
break;
case 0x5:
phydev->speed = SPEED_1000;
break;
case 0x3:
phydev->speed = SPEED_100;
break;
case 0x7:
default:
phydev->speed = SPEED_10000;
break;
}
phydev->duplex = DUPLEX_FULL;
return 0;
}
