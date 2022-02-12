static int rtl821x_ack_interrupt(struct phy_device *phydev)
{
int err;
err = phy_read(phydev, RTL821x_INSR);
return (err < 0) ? err : 0;
}
static int rtl8211b_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, RTL821x_INER,
RTL821x_INER_INIT);
else
err = phy_write(phydev, RTL821x_INER, 0);
return err;
}
static int rtl8211e_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, RTL821x_INER,
RTL8211E_INER_LINK_STATUS);
else
err = phy_write(phydev, RTL821x_INER, 0);
return err;
}
static int __init realtek_init(void)
{
return phy_drivers_register(realtek_drvs, ARRAY_SIZE(realtek_drvs));
}
static void __exit realtek_exit(void)
{
phy_drivers_unregister(realtek_drvs, ARRAY_SIZE(realtek_drvs));
}
