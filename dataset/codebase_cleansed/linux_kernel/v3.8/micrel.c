static int kszphy_ack_interrupt(struct phy_device *phydev)
{
int rc;
rc = phy_read(phydev, MII_KSZPHY_INTCS);
return (rc < 0) ? rc : 0;
}
static int kszphy_set_interrupt(struct phy_device *phydev)
{
int temp;
temp = (PHY_INTERRUPT_ENABLED == phydev->interrupts) ?
KSZPHY_INTCS_ALL : 0;
return phy_write(phydev, MII_KSZPHY_INTCS, temp);
}
static int kszphy_config_intr(struct phy_device *phydev)
{
int temp, rc;
temp = phy_read(phydev, MII_KSZPHY_CTRL);
temp &= ~KSZPHY_CTRL_INT_ACTIVE_HIGH;
phy_write(phydev, MII_KSZPHY_CTRL, temp);
rc = kszphy_set_interrupt(phydev);
return rc < 0 ? rc : 0;
}
static int ksz9021_config_intr(struct phy_device *phydev)
{
int temp, rc;
temp = phy_read(phydev, MII_KSZPHY_CTRL);
temp &= ~KSZ9021_CTRL_INT_ACTIVE_HIGH;
phy_write(phydev, MII_KSZPHY_CTRL, temp);
rc = kszphy_set_interrupt(phydev);
return rc < 0 ? rc : 0;
}
static int ks8737_config_intr(struct phy_device *phydev)
{
int temp, rc;
temp = phy_read(phydev, MII_KSZPHY_CTRL);
temp &= ~KS8737_CTRL_INT_ACTIVE_HIGH;
phy_write(phydev, MII_KSZPHY_CTRL, temp);
rc = kszphy_set_interrupt(phydev);
return rc < 0 ? rc : 0;
}
static int kszphy_config_init(struct phy_device *phydev)
{
return 0;
}
static int ksz8021_config_init(struct phy_device *phydev)
{
const u16 val = KSZPHY_OMSO_B_CAST_OFF | KSZPHY_OMSO_RMII_OVERRIDE;
phy_write(phydev, MII_KSZPHY_OMSO, val);
return 0;
}
static int ks8051_config_init(struct phy_device *phydev)
{
int regval;
if (phydev->dev_flags & MICREL_PHY_50MHZ_CLK) {
regval = phy_read(phydev, MII_KSZPHY_CTRL);
regval |= KSZ8051_RMII_50MHZ_CLK;
phy_write(phydev, MII_KSZPHY_CTRL, regval);
}
return 0;
}
int ksz8873mll_read_status(struct phy_device *phydev)
{
int regval;
regval = phy_read(phydev, KSZ8873MLL_GLOBAL_CONTROL_4);
regval = phy_read(phydev, KSZ8873MLL_GLOBAL_CONTROL_4);
if (regval & KSZ8873MLL_GLOBAL_CONTROL_4_DUPLEX)
phydev->duplex = DUPLEX_HALF;
else
phydev->duplex = DUPLEX_FULL;
if (regval & KSZ8873MLL_GLOBAL_CONTROL_4_SPEED)
phydev->speed = SPEED_10;
else
phydev->speed = SPEED_100;
phydev->link = 1;
phydev->pause = phydev->asym_pause = 0;
return 0;
}
static int ksz8873mll_config_aneg(struct phy_device *phydev)
{
return 0;
}
static int __init ksphy_init(void)
{
return phy_drivers_register(ksphy_driver,
ARRAY_SIZE(ksphy_driver));
}
static void __exit ksphy_exit(void)
{
phy_drivers_unregister(ksphy_driver,
ARRAY_SIZE(ksphy_driver));
}
