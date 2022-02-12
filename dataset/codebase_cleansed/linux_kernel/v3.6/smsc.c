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
return smsc_phy_ack_interrupt (phydev);
}
static int lan87xx_config_init(struct phy_device *phydev)
{
int rc = phy_read(phydev, MII_LAN83C185_CTRL_STATUS);
if (rc < 0)
return rc;
rc &= ~MII_LAN83C185_EDPWRDOWN;
rc = phy_write(phydev, MII_LAN83C185_CTRL_STATUS, rc);
if (rc < 0)
return rc;
return smsc_phy_ack_interrupt(phydev);
}
static int lan911x_config_init(struct phy_device *phydev)
{
return smsc_phy_ack_interrupt(phydev);
}
static int __init smsc_init(void)
{
return phy_drivers_register(smsc_phy_driver,
ARRAY_SIZE(smsc_phy_driver));
}
static void __exit smsc_exit(void)
{
return phy_drivers_unregister(smsc_phy_driver,
ARRAY_SIZE(smsc_phy_driver));
}
