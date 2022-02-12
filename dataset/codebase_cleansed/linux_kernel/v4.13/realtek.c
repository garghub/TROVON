static int rtl821x_ack_interrupt(struct phy_device *phydev)
{
int err;
err = phy_read(phydev, RTL821x_INSR);
return (err < 0) ? err : 0;
}
static int rtl8211f_ack_interrupt(struct phy_device *phydev)
{
int err;
phy_write(phydev, RTL8211F_PAGE_SELECT, 0xa43);
err = phy_read(phydev, RTL8211F_INSR);
phy_write(phydev, RTL8211F_PAGE_SELECT, 0x0);
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
static int rtl8211f_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, RTL821x_INER,
RTL8211F_INER_LINK_STATUS);
else
err = phy_write(phydev, RTL821x_INER, 0);
return err;
}
static int rtl8211f_config_init(struct phy_device *phydev)
{
int ret;
u16 reg;
ret = genphy_config_init(phydev);
if (ret < 0)
return ret;
phy_write(phydev, RTL8211F_PAGE_SELECT, 0xd08);
reg = phy_read(phydev, 0x11);
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID ||
phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)
reg |= RTL8211F_TX_DELAY;
else
reg &= ~RTL8211F_TX_DELAY;
phy_write(phydev, 0x11, reg);
phy_write(phydev, RTL8211F_PAGE_SELECT, 0x0);
return 0;
}
