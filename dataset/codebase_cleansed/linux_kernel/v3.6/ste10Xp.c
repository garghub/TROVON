static int ste10Xp_config_init(struct phy_device *phydev)
{
int value, err;
value = phy_read(phydev, MII_BMCR);
if (value < 0)
return value;
value |= BMCR_RESET;
err = phy_write(phydev, MII_BMCR, value);
if (err < 0)
return err;
do {
value = phy_read(phydev, MII_BMCR);
} while (value & BMCR_RESET);
return 0;
}
static int ste10Xp_config_intr(struct phy_device *phydev)
{
int err, value;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
err = phy_write(phydev, MII_XIE, MII_XIE_DEFAULT_MASK);
if (err == 0) {
value = phy_read(phydev, MII_XCIIS);
if (value < 0)
err = value;
}
} else
err = phy_write(phydev, MII_XIE, 0);
return err;
}
static int ste10Xp_ack_interrupt(struct phy_device *phydev)
{
int err = phy_read(phydev, MII_XCIIS);
if (err < 0)
return err;
return 0;
}
static int __init ste10Xp_init(void)
{
return phy_drivers_register(ste10xp_pdriver,
ARRAY_SIZE(ste10xp_pdriver));
}
static void __exit ste10Xp_exit(void)
{
phy_drivers_unregister(ste10xp_pdriver,
ARRAY_SIZE(ste10xp_pdriver));
}
