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
(phydev->drv->phy_id == PHY_ID_VSC8234 ||
phydev->drv->phy_id == PHY_ID_VSC8244 ||
phydev->drv->phy_id == PHY_ID_VSC8514 ||
phydev->drv->phy_id == PHY_ID_VSC8574) ?
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
static int vsc82x4_config_autocross_enable(struct phy_device *phydev)
{
int ret;
if (phydev->autoneg == AUTONEG_ENABLE || phydev->speed > SPEED_100)
return 0;
ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_ACCESS, 0x52b5);
if (ret >= 0)
ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_18E, 0x0012);
if (ret >= 0)
ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_17E, 0x2803);
if (ret >= 0)
ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_16E, 0x87fa);
if (ret >= 0)
ret = phy_write(phydev, MII_VSC82X4_EXT_PAGE_ACCESS, 0x0000);
else
phy_write(phydev, MII_VSC82X4_EXT_PAGE_ACCESS, 0x0000);
return ret;
}
static int vsc82x4_config_aneg(struct phy_device *phydev)
{
int ret;
if (phydev->autoneg != AUTONEG_ENABLE && phydev->speed <= SPEED_100) {
ret = genphy_setup_forced(phydev);
if (ret < 0)
return ret;
return vsc82x4_config_autocross_enable(phydev);
}
return genphy_config_aneg(phydev);
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
