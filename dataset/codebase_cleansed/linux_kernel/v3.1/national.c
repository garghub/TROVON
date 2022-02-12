static u8 ns_exp_read(struct phy_device *phydev, u16 reg)
{
phy_write(phydev, NS_EXP_MEM_ADD, reg);
return phy_read(phydev, NS_EXP_MEM_DATA);
}
static void ns_exp_write(struct phy_device *phydev, u16 reg, u8 data)
{
phy_write(phydev, NS_EXP_MEM_ADD, reg);
phy_write(phydev, NS_EXP_MEM_DATA, data);
}
static int ns_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, DP83865_INT_MASK,
DP83865_INT_MASK_DEFAULT);
else
err = phy_write(phydev, DP83865_INT_MASK, 0);
return err;
}
static int ns_ack_interrupt(struct phy_device *phydev)
{
int ret = phy_read(phydev, DP83865_INT_STATUS);
if (ret < 0)
return ret;
ret = phy_write(phydev, DP83865_INT_CLEAR, ret & ~0x7);
return ret;
}
static void ns_giga_speed_fallback(struct phy_device *phydev, int mode)
{
int bmcr = phy_read(phydev, MII_BMCR);
phy_write(phydev, MII_BMCR, (bmcr | BMCR_PDOWN));
phy_write(phydev, NS_EXP_MEM_CTL, 0);
phy_write(phydev, NS_EXP_MEM_ADD, 0x1C0);
phy_write(phydev, NS_EXP_MEM_DATA, 0x0008);
phy_write(phydev, MII_BMCR, (bmcr & ~BMCR_PDOWN));
phy_write(phydev, LED_CTRL_REG, mode);
}
static void ns_10_base_t_hdx_loopack(struct phy_device *phydev, int disable)
{
if (disable)
ns_exp_write(phydev, 0x1c0, ns_exp_read(phydev, 0x1c0) | 1);
else
ns_exp_write(phydev, 0x1c0,
ns_exp_read(phydev, 0x1c0) & 0xfffe);
printk(KERN_DEBUG "DP83865 PHY: 10BASE-T HDX loopback %s\n",
(ns_exp_read(phydev, 0x1c0) & 0x0001) ? "off" : "on");
}
static int ns_config_init(struct phy_device *phydev)
{
ns_giga_speed_fallback(phydev, ALL_FALLBACK_ON);
ns_10_base_t_hdx_loopack(phydev, hdx_loopback_off);
return ns_ack_interrupt(phydev);
}
static int __init ns_init(void)
{
return phy_driver_register(&dp83865_driver);
}
static void __exit ns_exit(void)
{
phy_driver_unregister(&dp83865_driver);
}
