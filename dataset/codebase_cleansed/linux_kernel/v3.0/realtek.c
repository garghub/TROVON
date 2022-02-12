static int rtl821x_ack_interrupt(struct phy_device *phydev)
{
int err;
err = phy_read(phydev, RTL821x_INSR);
return (err < 0) ? err : 0;
}
static int rtl821x_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, RTL821x_INER,
RTL821x_INER_INIT);
else
err = phy_write(phydev, RTL821x_INER, 0);
return err;
}
static int __init realtek_init(void)
{
int ret;
ret = phy_driver_register(&rtl821x_driver);
return ret;
}
static void __exit realtek_exit(void)
{
phy_driver_unregister(&rtl821x_driver);
}
