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
