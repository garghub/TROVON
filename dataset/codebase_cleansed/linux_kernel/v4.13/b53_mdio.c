static int b53_mdio_op(struct b53_device *dev, u8 page, u8 reg, u16 op)
{
int i;
u16 v;
int ret;
struct mii_bus *bus = dev->priv;
if (dev->current_page != page) {
v = (page << 8) | REG_MII_PAGE_ENABLE;
ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_PAGE, v);
if (ret)
return ret;
dev->current_page = page;
}
v = (reg << 8) | op;
ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR, REG_MII_ADDR, v);
if (ret)
return ret;
for (i = 0; i < 5; ++i) {
v = mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_ADDR);
if (!(v & (REG_MII_ADDR_WRITE | REG_MII_ADDR_READ)))
break;
usleep_range(10, 100);
}
if (WARN_ON(i == 5))
return -EIO;
return 0;
}
static int b53_mdio_read8(struct b53_device *dev, u8 page, u8 reg, u8 *val)
{
struct mii_bus *bus = dev->priv;
int ret;
ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
if (ret)
return ret;
*val = mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA0) & 0xff;
return 0;
}
static int b53_mdio_read16(struct b53_device *dev, u8 page, u8 reg, u16 *val)
{
struct mii_bus *bus = dev->priv;
int ret;
ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
if (ret)
return ret;
*val = mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR, REG_MII_DATA0);
return 0;
}
static int b53_mdio_read32(struct b53_device *dev, u8 page, u8 reg, u32 *val)
{
struct mii_bus *bus = dev->priv;
int ret;
ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
if (ret)
return ret;
*val = mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR, REG_MII_DATA0);
*val |= mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA1) << 16;
return 0;
}
static int b53_mdio_read48(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
struct mii_bus *bus = dev->priv;
u64 temp = 0;
int i;
int ret;
ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
if (ret)
return ret;
for (i = 2; i >= 0; i--) {
temp <<= 16;
temp |= mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA0 + i);
}
*val = temp;
return 0;
}
static int b53_mdio_read64(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
struct mii_bus *bus = dev->priv;
u64 temp = 0;
int i;
int ret;
ret = b53_mdio_op(dev, page, reg, REG_MII_ADDR_READ);
if (ret)
return ret;
for (i = 3; i >= 0; i--) {
temp <<= 16;
temp |= mdiobus_read_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA0 + i);
}
*val = temp;
return 0;
}
static int b53_mdio_write8(struct b53_device *dev, u8 page, u8 reg, u8 value)
{
struct mii_bus *bus = dev->priv;
int ret;
ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA0, value);
if (ret)
return ret;
return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}
static int b53_mdio_write16(struct b53_device *dev, u8 page, u8 reg,
u16 value)
{
struct mii_bus *bus = dev->priv;
int ret;
ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA0, value);
if (ret)
return ret;
return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}
static int b53_mdio_write32(struct b53_device *dev, u8 page, u8 reg,
u32 value)
{
struct mii_bus *bus = dev->priv;
unsigned int i;
u32 temp = value;
for (i = 0; i < 2; i++) {
int ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA0 + i,
temp & 0xffff);
if (ret)
return ret;
temp >>= 16;
}
return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}
static int b53_mdio_write48(struct b53_device *dev, u8 page, u8 reg,
u64 value)
{
struct mii_bus *bus = dev->priv;
unsigned int i;
u64 temp = value;
for (i = 0; i < 3; i++) {
int ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA0 + i,
temp & 0xffff);
if (ret)
return ret;
temp >>= 16;
}
return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}
static int b53_mdio_write64(struct b53_device *dev, u8 page, u8 reg,
u64 value)
{
struct mii_bus *bus = dev->priv;
unsigned int i;
u64 temp = value;
for (i = 0; i < 4; i++) {
int ret = mdiobus_write_nested(bus, BRCM_PSEUDO_PHY_ADDR,
REG_MII_DATA0 + i,
temp & 0xffff);
if (ret)
return ret;
temp >>= 16;
}
return b53_mdio_op(dev, page, reg, REG_MII_ADDR_WRITE);
}
static int b53_mdio_phy_read16(struct b53_device *dev, int addr, int reg,
u16 *value)
{
struct mii_bus *bus = dev->priv;
*value = mdiobus_read_nested(bus, addr, reg);
return 0;
}
static int b53_mdio_phy_write16(struct b53_device *dev, int addr, int reg,
u16 value)
{
struct mii_bus *bus = dev->bus;
return mdiobus_write_nested(bus, addr, reg, value);
}
static int b53_mdio_probe(struct mdio_device *mdiodev)
{
struct b53_device *dev;
u32 phy_id;
int ret;
if (mdiodev->addr != BRCM_PSEUDO_PHY_ADDR && mdiodev->addr != 0) {
dev_err(&mdiodev->dev, "leaving address %d to PHY\n",
mdiodev->addr);
return -ENODEV;
}
phy_id = mdiobus_read(mdiodev->bus, 0, 2) << 16;
phy_id |= mdiobus_read(mdiodev->bus, 0, 3);
if ((phy_id & 0xfffffc00) != B53_BRCM_OUI_1 &&
(phy_id & 0xfffffc00) != B53_BRCM_OUI_2 &&
(phy_id & 0xfffffc00) != B53_BRCM_OUI_3) {
dev_err(&mdiodev->dev, "Unsupported device: 0x%08x\n", phy_id);
return -ENODEV;
}
if (of_machine_is_compatible("brcm,bcm7445d0") &&
strcmp(mdiodev->bus->name, "sf2 slave mii"))
return -EPROBE_DEFER;
dev = b53_switch_alloc(&mdiodev->dev, &b53_mdio_ops, mdiodev->bus);
if (!dev)
return -ENOMEM;
dev->current_page = 0xff;
dev->bus = mdiodev->bus;
dev_set_drvdata(&mdiodev->dev, dev);
ret = b53_switch_register(dev);
if (ret) {
dev_err(&mdiodev->dev, "failed to register switch: %i\n", ret);
return ret;
}
return ret;
}
static void b53_mdio_remove(struct mdio_device *mdiodev)
{
struct b53_device *dev = dev_get_drvdata(&mdiodev->dev);
struct dsa_switch *ds = dev->ds;
dsa_unregister_switch(ds);
}
