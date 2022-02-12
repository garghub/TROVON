static int vsc824x_add_skew(struct phy_device *phydev)
{
int err;
int extcon;
extcon = phy_read(phydev, MII_VSC8244_EXT_CON1);
if (extcon < 0)
return extcon;
extcon &= ~(MII_VSC8244_EXTCON1_TX_SKEW_MASK |
MII_VSC8244_EXTCON1_RX_SKEW_MASK);
extcon |= (MII_VSC8244_EXTCON1_TX_SKEW |
MII_VSC8244_EXTCON1_RX_SKEW);
err = phy_write(phydev, MII_VSC8244_EXT_CON1, extcon);
return err;
}
static int vsc824x_config_init(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_VSC8244_AUX_CONSTAT,
MII_VSC8244_AUXCONSTAT_INIT);
if (err < 0)
return err;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID)
err = vsc824x_add_skew(phydev);
return err;
}
static int vsc824x_ack_interrupt(struct phy_device *phydev)
{
int err = 0;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_read(phydev, MII_VSC8244_ISTAT);
return (err < 0) ? err : 0;
}
static int vsc82xx_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, MII_VSC8244_IMASK,
phydev->drv->phy_id == PHY_ID_VSC8244 ?
MII_VSC8244_IMASK_MASK :
MII_VSC8221_IMASK_MASK);
else {
err = phy_read(phydev, MII_VSC8244_ISTAT);
if (err < 0)
return err;
err = phy_write(phydev, MII_VSC8244_IMASK, 0);
}
return err;
}
static int vsc8221_config_init(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_VSC8244_AUX_CONSTAT,
MII_VSC8221_AUXCONSTAT_INIT);
return err;
}
static int __init vsc82xx_init(void)
{
return phy_drivers_register(vsc82xx_driver,
ARRAY_SIZE(vsc82xx_driver));
}
static void __exit vsc82xx_exit(void)
{
return phy_drivers_unregister(vsc82xx_driver,
ARRAY_SIZE(vsc82xx_driver));
}
