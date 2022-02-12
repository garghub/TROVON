static int ksz_config_flags(struct phy_device *phydev)
{
int regval;
if (phydev->dev_flags & MICREL_PHY_50MHZ_CLK) {
regval = phy_read(phydev, MII_KSZPHY_CTRL);
regval |= KSZ8051_RMII_50MHZ_CLK;
return phy_write(phydev, MII_KSZPHY_CTRL, regval);
}
return 0;
}
static int kszphy_extended_write(struct phy_device *phydev,
u32 regnum, u16 val)
{
phy_write(phydev, MII_KSZPHY_EXTREG, KSZPHY_EXTREG_WRITE | regnum);
return phy_write(phydev, MII_KSZPHY_EXTREG_WRITE, val);
}
static int kszphy_extended_read(struct phy_device *phydev,
u32 regnum)
{
phy_write(phydev, MII_KSZPHY_EXTREG, regnum);
return phy_read(phydev, MII_KSZPHY_EXTREG_READ);
}
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
static int kszphy_setup_led(struct phy_device *phydev,
unsigned int reg, unsigned int shift)
{
struct device *dev = &phydev->dev;
struct device_node *of_node = dev->of_node;
int rc, temp;
u32 val;
if (!of_node && dev->parent->of_node)
of_node = dev->parent->of_node;
if (of_property_read_u32(of_node, "micrel,led-mode", &val))
return 0;
temp = phy_read(phydev, reg);
if (temp < 0)
return temp;
temp &= ~(3 << shift);
temp |= val << shift;
rc = phy_write(phydev, reg, temp);
return rc < 0 ? rc : 0;
}
static int kszphy_config_init(struct phy_device *phydev)
{
return 0;
}
static int kszphy_config_init_led8041(struct phy_device *phydev)
{
return kszphy_setup_led(phydev, 0x1e, 14);
}
static int ksz8021_config_init(struct phy_device *phydev)
{
const u16 val = KSZPHY_OMSO_B_CAST_OFF | KSZPHY_OMSO_RMII_OVERRIDE;
int rc;
rc = kszphy_setup_led(phydev, 0x1f, 4);
if (rc)
dev_err(&phydev->dev, "failed to set led mode\n");
phy_write(phydev, MII_KSZPHY_OMSO, val);
rc = ksz_config_flags(phydev);
return rc < 0 ? rc : 0;
}
static int ks8051_config_init(struct phy_device *phydev)
{
int rc;
rc = kszphy_setup_led(phydev, 0x1f, 4);
if (rc)
dev_err(&phydev->dev, "failed to set led mode\n");
rc = ksz_config_flags(phydev);
return rc < 0 ? rc : 0;
}
static int ksz9021_load_values_from_of(struct phy_device *phydev,
struct device_node *of_node, u16 reg,
char *field1, char *field2,
char *field3, char *field4)
{
int val1 = -1;
int val2 = -2;
int val3 = -3;
int val4 = -4;
int newval;
int matches = 0;
if (!of_property_read_u32(of_node, field1, &val1))
matches++;
if (!of_property_read_u32(of_node, field2, &val2))
matches++;
if (!of_property_read_u32(of_node, field3, &val3))
matches++;
if (!of_property_read_u32(of_node, field4, &val4))
matches++;
if (!matches)
return 0;
if (matches < 4)
newval = kszphy_extended_read(phydev, reg);
else
newval = 0;
if (val1 != -1)
newval = ((newval & 0xfff0) | ((val1 / PS_TO_REG) & 0xf) << 0);
if (val2 != -2)
newval = ((newval & 0xff0f) | ((val2 / PS_TO_REG) & 0xf) << 4);
if (val3 != -3)
newval = ((newval & 0xf0ff) | ((val3 / PS_TO_REG) & 0xf) << 8);
if (val4 != -4)
newval = ((newval & 0x0fff) | ((val4 / PS_TO_REG) & 0xf) << 12);
return kszphy_extended_write(phydev, reg, newval);
}
static int ksz9021_config_init(struct phy_device *phydev)
{
struct device *dev = &phydev->dev;
struct device_node *of_node = dev->of_node;
if (!of_node && dev->parent->of_node)
of_node = dev->parent->of_node;
if (of_node) {
ksz9021_load_values_from_of(phydev, of_node,
MII_KSZPHY_CLK_CONTROL_PAD_SKEW,
"txen-skew-ps", "txc-skew-ps",
"rxdv-skew-ps", "rxc-skew-ps");
ksz9021_load_values_from_of(phydev, of_node,
MII_KSZPHY_RX_DATA_PAD_SKEW,
"rxd0-skew-ps", "rxd1-skew-ps",
"rxd2-skew-ps", "rxd3-skew-ps");
ksz9021_load_values_from_of(phydev, of_node,
MII_KSZPHY_TX_DATA_PAD_SKEW,
"txd0-skew-ps", "txd1-skew-ps",
"txd2-skew-ps", "txd3-skew-ps");
}
return 0;
}
static int ksz8873mll_read_status(struct phy_device *phydev)
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
