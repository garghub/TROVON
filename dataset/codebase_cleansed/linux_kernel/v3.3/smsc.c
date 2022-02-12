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
static int lan911x_config_init(struct phy_device *phydev)
{
return smsc_phy_ack_interrupt(phydev);
}
static int __init smsc_init(void)
{
int ret;
ret = phy_driver_register (&lan83c185_driver);
if (ret)
goto err1;
ret = phy_driver_register (&lan8187_driver);
if (ret)
goto err2;
ret = phy_driver_register (&lan8700_driver);
if (ret)
goto err3;
ret = phy_driver_register (&lan911x_int_driver);
if (ret)
goto err4;
ret = phy_driver_register (&lan8710_driver);
if (ret)
goto err5;
return 0;
err5:
phy_driver_unregister (&lan911x_int_driver);
err4:
phy_driver_unregister (&lan8700_driver);
err3:
phy_driver_unregister (&lan8187_driver);
err2:
phy_driver_unregister (&lan83c185_driver);
err1:
return ret;
}
static void __exit smsc_exit(void)
{
phy_driver_unregister (&lan8710_driver);
phy_driver_unregister (&lan911x_int_driver);
phy_driver_unregister (&lan8700_driver);
phy_driver_unregister (&lan8187_driver);
phy_driver_unregister (&lan83c185_driver);
}
