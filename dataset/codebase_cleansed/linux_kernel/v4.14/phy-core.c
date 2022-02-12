const char *phy_speed_to_str(int speed)
{
switch (speed) {
case SPEED_10:
return "10Mbps";
case SPEED_100:
return "100Mbps";
case SPEED_1000:
return "1Gbps";
case SPEED_2500:
return "2.5Gbps";
case SPEED_5000:
return "5Gbps";
case SPEED_10000:
return "10Gbps";
case SPEED_14000:
return "14Gbps";
case SPEED_20000:
return "20Gbps";
case SPEED_25000:
return "25Gbps";
case SPEED_40000:
return "40Gbps";
case SPEED_50000:
return "50Gbps";
case SPEED_56000:
return "56Gbps";
case SPEED_100000:
return "100Gbps";
case SPEED_UNKNOWN:
return "Unknown";
default:
return "Unsupported (update phy-core.c)";
}
}
const char *phy_duplex_to_str(unsigned int duplex)
{
if (duplex == DUPLEX_HALF)
return "Half";
if (duplex == DUPLEX_FULL)
return "Full";
if (duplex == DUPLEX_UNKNOWN)
return "Unknown";
return "Unsupported (update phy-core.c)";
}
const struct phy_setting *
phy_lookup_setting(int speed, int duplex, const unsigned long *mask,
size_t maxbit, bool exact)
{
const struct phy_setting *p, *match = NULL, *last = NULL;
int i;
for (i = 0, p = settings; i < ARRAY_SIZE(settings); i++, p++) {
if (p->bit < maxbit && test_bit(p->bit, mask)) {
last = p;
if (p->speed == speed && p->duplex == duplex) {
match = p;
break;
} else if (!exact) {
if (!match && p->speed <= speed)
match = p;
if (p->speed < speed)
break;
}
}
}
if (!match && !exact)
match = last;
return match;
}
size_t phy_speeds(unsigned int *speeds, size_t size,
unsigned long *mask, size_t maxbit)
{
size_t count;
int i;
for (i = 0, count = 0; i < ARRAY_SIZE(settings) && count < size; i++)
if (settings[i].bit < maxbit &&
test_bit(settings[i].bit, mask) &&
(count == 0 || speeds[count - 1] != settings[i].speed))
speeds[count++] = settings[i].speed;
return count;
}
static void mmd_phy_indirect(struct mii_bus *bus, int phy_addr, int devad,
u16 regnum)
{
bus->write(bus, phy_addr, MII_MMD_CTRL, devad);
bus->write(bus, phy_addr, MII_MMD_DATA, regnum);
bus->write(bus, phy_addr, MII_MMD_CTRL, devad | MII_MMD_CTRL_NOINCR);
}
int phy_read_mmd(struct phy_device *phydev, int devad, u32 regnum)
{
int val;
if (regnum > (u16)~0 || devad > 32)
return -EINVAL;
if (phydev->drv->read_mmd) {
val = phydev->drv->read_mmd(phydev, devad, regnum);
} else if (phydev->is_c45) {
u32 addr = MII_ADDR_C45 | (devad << 16) | (regnum & 0xffff);
val = mdiobus_read(phydev->mdio.bus, phydev->mdio.addr, addr);
} else {
struct mii_bus *bus = phydev->mdio.bus;
int phy_addr = phydev->mdio.addr;
mutex_lock(&bus->mdio_lock);
mmd_phy_indirect(bus, phy_addr, devad, regnum);
val = bus->read(bus, phy_addr, MII_MMD_DATA);
mutex_unlock(&bus->mdio_lock);
}
return val;
}
int phy_write_mmd(struct phy_device *phydev, int devad, u32 regnum, u16 val)
{
int ret;
if (regnum > (u16)~0 || devad > 32)
return -EINVAL;
if (phydev->drv->write_mmd) {
ret = phydev->drv->write_mmd(phydev, devad, regnum, val);
} else if (phydev->is_c45) {
u32 addr = MII_ADDR_C45 | (devad << 16) | (regnum & 0xffff);
ret = mdiobus_write(phydev->mdio.bus, phydev->mdio.addr,
addr, val);
} else {
struct mii_bus *bus = phydev->mdio.bus;
int phy_addr = phydev->mdio.addr;
mutex_lock(&bus->mdio_lock);
mmd_phy_indirect(bus, phy_addr, devad, regnum);
bus->write(bus, phy_addr, MII_MMD_DATA, val);
mutex_unlock(&bus->mdio_lock);
ret = 0;
}
return ret;
}
