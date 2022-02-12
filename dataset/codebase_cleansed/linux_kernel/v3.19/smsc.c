static int smsc_phy_config_intr(struct phy_device *phydev)
{
int rc = phy_write (phydev, MII_LAN83C185_IM,
((PHY_INTERRUPT_ENABLED == phydev->interrupts)
? MII_LAN83C185_ISF_INT_PHYLIB_EVENTS
: 0));
return rc < 0 ? rc : 0;
}
static int smsc_phy_ack_interrupt(struct phy_device *phydev)
{
int rc = phy_read (phydev, MII_LAN83C185_ISF);
return rc < 0 ? rc : 0;
}
static int smsc_phy_config_init(struct phy_device *phydev)
{
int rc = phy_read(phydev, MII_LAN83C185_CTRL_STATUS);
if (rc < 0)
return rc;
rc = phy_write(phydev, MII_LAN83C185_CTRL_STATUS,
rc | MII_LAN83C185_EDPWRDOWN);
if (rc < 0)
return rc;
return smsc_phy_ack_interrupt(phydev);
}
static int smsc_phy_reset(struct phy_device *phydev)
{
int rc = phy_read(phydev, MII_LAN83C185_SPECIAL_MODES);
if (rc < 0)
return rc;
if ((rc & MII_LAN83C185_MODE_MASK) == MII_LAN83C185_MODE_POWERDOWN) {
int timeout = 50000;
rc |= MII_LAN83C185_MODE_ALL;
phy_write(phydev, MII_LAN83C185_SPECIAL_MODES, rc);
phy_write(phydev, MII_BMCR, BMCR_RESET);
do {
udelay(10);
if (timeout-- == 0)
return -1;
rc = phy_read(phydev, MII_BMCR);
} while (rc & BMCR_RESET);
}
return 0;
}
static int lan911x_config_init(struct phy_device *phydev)
{
return smsc_phy_ack_interrupt(phydev);
}
static int lan87xx_read_status(struct phy_device *phydev)
{
int err = genphy_read_status(phydev);
if (!phydev->link) {
int rc = phy_read(phydev, MII_LAN83C185_CTRL_STATUS);
if (rc < 0)
return rc;
rc = phy_write(phydev, MII_LAN83C185_CTRL_STATUS,
rc & ~MII_LAN83C185_EDPWRDOWN);
if (rc < 0)
return rc;
msleep(64);
rc = phy_read(phydev, MII_LAN83C185_CTRL_STATUS);
if (rc < 0)
return rc;
rc = phy_write(phydev, MII_LAN83C185_CTRL_STATUS,
rc | MII_LAN83C185_EDPWRDOWN);
if (rc < 0)
return rc;
}
return err;
}
