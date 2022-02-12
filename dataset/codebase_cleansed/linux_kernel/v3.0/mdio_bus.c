struct mii_bus *mdiobus_alloc(void)
{
struct mii_bus *bus;
bus = kzalloc(sizeof(*bus), GFP_KERNEL);
if (bus != NULL)
bus->state = MDIOBUS_ALLOCATED;
return bus;
}
static void mdiobus_release(struct device *d)
{
struct mii_bus *bus = to_mii_bus(d);
BUG_ON(bus->state != MDIOBUS_RELEASED &&
bus->state != MDIOBUS_ALLOCATED);
kfree(bus);
}
int mdiobus_register(struct mii_bus *bus)
{
int i, err;
if (NULL == bus || NULL == bus->name ||
NULL == bus->read ||
NULL == bus->write)
return -EINVAL;
BUG_ON(bus->state != MDIOBUS_ALLOCATED &&
bus->state != MDIOBUS_UNREGISTERED);
bus->dev.parent = bus->parent;
bus->dev.class = &mdio_bus_class;
bus->dev.groups = NULL;
dev_set_name(&bus->dev, "%s", bus->id);
err = device_register(&bus->dev);
if (err) {
printk(KERN_ERR "mii_bus %s failed to register\n", bus->id);
return -EINVAL;
}
mutex_init(&bus->mdio_lock);
if (bus->reset)
bus->reset(bus);
for (i = 0; i < PHY_MAX_ADDR; i++) {
if ((bus->phy_mask & (1 << i)) == 0) {
struct phy_device *phydev;
phydev = mdiobus_scan(bus, i);
if (IS_ERR(phydev)) {
err = PTR_ERR(phydev);
goto error;
}
}
}
bus->state = MDIOBUS_REGISTERED;
pr_info("%s: probed\n", bus->name);
return 0;
error:
while (--i >= 0) {
if (bus->phy_map[i])
device_unregister(&bus->phy_map[i]->dev);
}
device_del(&bus->dev);
return err;
}
void mdiobus_unregister(struct mii_bus *bus)
{
int i;
BUG_ON(bus->state != MDIOBUS_REGISTERED);
bus->state = MDIOBUS_UNREGISTERED;
device_del(&bus->dev);
for (i = 0; i < PHY_MAX_ADDR; i++) {
if (bus->phy_map[i])
device_unregister(&bus->phy_map[i]->dev);
bus->phy_map[i] = NULL;
}
}
void mdiobus_free(struct mii_bus *bus)
{
if (bus->state == MDIOBUS_ALLOCATED) {
kfree(bus);
return;
}
BUG_ON(bus->state != MDIOBUS_UNREGISTERED);
bus->state = MDIOBUS_RELEASED;
put_device(&bus->dev);
}
struct phy_device *mdiobus_scan(struct mii_bus *bus, int addr)
{
struct phy_device *phydev;
int err;
phydev = get_phy_device(bus, addr);
if (IS_ERR(phydev) || phydev == NULL)
return phydev;
err = phy_device_register(phydev);
if (err) {
phy_device_free(phydev);
return NULL;
}
return phydev;
}
int mdiobus_read(struct mii_bus *bus, int addr, u32 regnum)
{
int retval;
BUG_ON(in_interrupt());
mutex_lock(&bus->mdio_lock);
retval = bus->read(bus, addr, regnum);
mutex_unlock(&bus->mdio_lock);
return retval;
}
int mdiobus_write(struct mii_bus *bus, int addr, u32 regnum, u16 val)
{
int err;
BUG_ON(in_interrupt());
mutex_lock(&bus->mdio_lock);
err = bus->write(bus, addr, regnum, val);
mutex_unlock(&bus->mdio_lock);
return err;
}
static int mdio_bus_match(struct device *dev, struct device_driver *drv)
{
struct phy_device *phydev = to_phy_device(dev);
struct phy_driver *phydrv = to_phy_driver(drv);
return ((phydrv->phy_id & phydrv->phy_id_mask) ==
(phydev->phy_id & phydrv->phy_id_mask));
}
static bool mdio_bus_phy_may_suspend(struct phy_device *phydev)
{
struct device_driver *drv = phydev->dev.driver;
struct phy_driver *phydrv = to_phy_driver(drv);
struct net_device *netdev = phydev->attached_dev;
if (!drv || !phydrv->suspend)
return false;
if (!netdev)
return true;
if (netdev->dev.parent && device_may_wakeup(netdev->dev.parent))
return false;
if (device_may_wakeup(&netdev->dev))
return false;
return true;
}
static int mdio_bus_suspend(struct device *dev)
{
struct phy_driver *phydrv = to_phy_driver(dev->driver);
struct phy_device *phydev = to_phy_device(dev);
if (phydev->attached_dev && phydev->adjust_link)
phy_stop_machine(phydev);
if (!mdio_bus_phy_may_suspend(phydev))
return 0;
return phydrv->suspend(phydev);
}
static int mdio_bus_resume(struct device *dev)
{
struct phy_driver *phydrv = to_phy_driver(dev->driver);
struct phy_device *phydev = to_phy_device(dev);
int ret;
if (!mdio_bus_phy_may_suspend(phydev))
goto no_resume;
ret = phydrv->resume(phydev);
if (ret < 0)
return ret;
no_resume:
if (phydev->attached_dev && phydev->adjust_link)
phy_start_machine(phydev, NULL);
return 0;
}
static int mdio_bus_restore(struct device *dev)
{
struct phy_device *phydev = to_phy_device(dev);
struct net_device *netdev = phydev->attached_dev;
int ret;
if (!netdev)
return 0;
ret = phy_init_hw(phydev);
if (ret < 0)
return ret;
phydev->link = 0;
phydev->state = PHY_UP;
phy_start_machine(phydev, NULL);
return 0;
}
int __init mdio_bus_init(void)
{
int ret;
ret = class_register(&mdio_bus_class);
if (!ret) {
ret = bus_register(&mdio_bus_type);
if (ret)
class_unregister(&mdio_bus_class);
}
return ret;
}
void mdio_bus_exit(void)
{
class_unregister(&mdio_bus_class);
bus_unregister(&mdio_bus_type);
}
