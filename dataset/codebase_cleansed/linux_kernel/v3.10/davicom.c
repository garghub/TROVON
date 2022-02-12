static int dm9161_config_intr(struct phy_device *phydev)
{
int temp;
temp = phy_read(phydev, MII_DM9161_INTR);
if (temp < 0)
return temp;
if(PHY_INTERRUPT_ENABLED == phydev->interrupts )
temp &= ~(MII_DM9161_INTR_STOP);
else
temp |= MII_DM9161_INTR_STOP;
temp = phy_write(phydev, MII_DM9161_INTR, temp);
return temp;
}
static int dm9161_config_aneg(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_BMCR, BMCR_ISOLATE);
if (err < 0)
return err;
err = genphy_config_aneg(phydev);
if (err < 0)
return err;
return 0;
}
static int dm9161_config_init(struct phy_device *phydev)
{
int err, temp;
err = phy_write(phydev, MII_BMCR, BMCR_ISOLATE);
if (err < 0)
return err;
switch (phydev->interface) {
case PHY_INTERFACE_MODE_MII:
temp = MII_DM9161_SCR_INIT;
break;
case PHY_INTERFACE_MODE_RMII:
temp = MII_DM9161_SCR_INIT | MII_DM9161_SCR_RMII;
break;
default:
return -EINVAL;
}
err = phy_write(phydev, MII_DM9161_SCR, temp);
if (err < 0)
return err;
err = phy_write(phydev, MII_DM9161_10BTCSR, MII_DM9161_10BTCSR_INIT);
if (err < 0)
return err;
return phy_write(phydev, MII_BMCR, BMCR_ANENABLE);
}
static int dm9161_ack_interrupt(struct phy_device *phydev)
{
int err = phy_read(phydev, MII_DM9161_INTR);
return (err < 0) ? err : 0;
}
static int __init davicom_init(void)
{
return phy_drivers_register(dm91xx_driver,
ARRAY_SIZE(dm91xx_driver));
}
static void __exit davicom_exit(void)
{
phy_drivers_unregister(dm91xx_driver,
ARRAY_SIZE(dm91xx_driver));
}
