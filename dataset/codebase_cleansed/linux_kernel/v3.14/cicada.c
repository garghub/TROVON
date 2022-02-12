static int cis820x_config_init(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_CIS8201_AUX_CONSTAT,
MII_CIS8201_AUXCONSTAT_INIT);
if (err < 0)
return err;
err = phy_write(phydev, MII_CIS8201_EXT_CON1,
MII_CIS8201_EXTCON1_INIT);
return err;
}
static int cis820x_ack_interrupt(struct phy_device *phydev)
{
int err = phy_read(phydev, MII_CIS8201_ISTAT);
return (err < 0) ? err : 0;
}
static int cis820x_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, MII_CIS8201_IMASK,
MII_CIS8201_IMASK_MASK);
else
err = phy_write(phydev, MII_CIS8201_IMASK, 0);
return err;
}
static int __init cicada_init(void)
{
return phy_drivers_register(cis820x_driver,
ARRAY_SIZE(cis820x_driver));
}
static void __exit cicada_exit(void)
{
phy_drivers_unregister(cis820x_driver,
ARRAY_SIZE(cis820x_driver));
}
