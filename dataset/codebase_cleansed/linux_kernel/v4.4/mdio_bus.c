struct mii_bus *mdiobus_alloc_size(size_t size)
{
struct mii_bus *bus;
size_t aligned_size = ALIGN(sizeof(*bus), NETDEV_ALIGN);
size_t alloc_size;
if (size)
alloc_size = aligned_size + size;
else
alloc_size = sizeof(*bus);
bus = kzalloc(alloc_size, GFP_KERNEL);
if (bus) {
bus->state = MDIOBUS_ALLOCATED;
if (size)
bus->priv = (void *)bus + aligned_size;
}
return bus;
}
static void _devm_mdiobus_free(struct device *dev, void *res)
{
mdiobus_free(*(struct mii_bus **)res);
}
static int devm_mdiobus_match(struct device *dev, void *res, void *data)
{
struct mii_bus **r = res;
if (WARN_ON(!r || !*r))
return 0;
return *r == data;
}
struct mii_bus *devm_mdiobus_alloc_size(struct device *dev, int sizeof_priv)
{
struct mii_bus **ptr, *bus;
ptr = devres_alloc(_devm_mdiobus_free, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return NULL;
bus = mdiobus_alloc_size(sizeof_priv);
if (bus) {
*ptr = bus;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return bus;
}
void devm_mdiobus_free(struct device *dev, struct mii_bus *bus)
{
int rc;
rc = devres_release(dev, _devm_mdiobus_free,
devm_mdiobus_match, bus);
WARN_ON(rc);
}
static void mdiobus_release(struct device *d)
{
struct mii_bus *bus = to_mii_bus(d);
BUG_ON(bus->state != MDIOBUS_RELEASED &&
bus->state != MDIOBUS_ALLOCATED);
kfree(bus);
}
static int of_mdio_bus_match(struct device *dev, const void *mdio_bus_np)
{
return dev->of_node == mdio_bus_np;
}
struct mii_bus *of_mdio_find_bus(struct device_node *mdio_bus_np)
{
struct device *d;
if (!mdio_bus_np)
return NULL;
d = class_find_device(&mdio_bus_class, NULL, mdio_bus_np,
of_mdio_bus_match);
return d ? to_mii_bus(d) : NULL;
}
static void of_mdiobus_link_phydev(struct mii_bus *mdio,
struct phy_device *phydev)
{
struct device *dev = &phydev->dev;
struct device_node *child;
if (dev->of_node || !mdio->dev.of_node)
return;
for_each_available_child_of_node(mdio->dev.of_node, child) {
int addr;
int ret;
ret = of_property_read_u32(child, "reg", &addr);
if (ret < 0) {
dev_err(dev, "%s has invalid PHY address\n",
child->full_name);
continue;
}
if (addr >= PHY_MAX_ADDR) {
dev_err(dev, "%s PHY address %i is too large\n",
child->full_name, addr);
continue;
}
if (addr == phydev->addr) {
dev->of_node = child;
return;
}
}
}
static inline void of_mdiobus_link_phydev(struct mii_bus *mdio,
struct phy_device *phydev)
{
}
int __mdiobus_register(struct mii_bus *bus, struct module *owner)
{
int i, err;
if (NULL == bus || NULL == bus->name ||
NULL == bus->read || NULL == bus->write)
return -EINVAL;
BUG_ON(bus->state != MDIOBUS_ALLOCATED &&
bus->state != MDIOBUS_UNREGISTERED);
bus->owner = owner;
bus->dev.parent = bus->parent;
bus->dev.class = &mdio_bus_class;
bus->dev.groups = NULL;
dev_set_name(&bus->dev, "%s", bus->id);
err = device_register(&bus->dev);
if (err) {
pr_err("mii_bus %s failed to register\n", bus->id);
put_device(&bus->dev);
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
struct phy_device *phydev = bus->phy_map[i];
if (phydev) {
phy_device_remove(phydev);
phy_device_free(phydev);
}
}
device_del(&bus->dev);
return err;
}
void mdiobus_unregister(struct mii_bus *bus)
{
int i;
BUG_ON(bus->state != MDIOBUS_REGISTERED);
bus->state = MDIOBUS_UNREGISTERED;
for (i = 0; i < PHY_MAX_ADDR; i++) {
struct phy_device *phydev = bus->phy_map[i];
if (phydev) {
phy_device_remove(phydev);
phy_device_free(phydev);
}
}
device_del(&bus->dev);
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
phydev = get_phy_device(bus, addr, false);
if (IS_ERR(phydev) || phydev == NULL)
return phydev;
of_mdiobus_link_phydev(bus, phydev);
err = phy_device_register(phydev);
if (err) {
phy_device_free(phydev);
return NULL;
}
return phydev;
}
int mdiobus_read_nested(struct mii_bus *bus, int addr, u32 regnum)
{
int retval;
BUG_ON(in_interrupt());
mutex_lock_nested(&bus->mdio_lock, SINGLE_DEPTH_NESTING);
retval = bus->read(bus, addr, regnum);
mutex_unlock(&bus->mdio_lock);
return retval;
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
int mdiobus_write_nested(struct mii_bus *bus, int addr, u32 regnum, u16 val)
{
int err;
BUG_ON(in_interrupt());
mutex_lock_nested(&bus->mdio_lock, SINGLE_DEPTH_NESTING);
err = bus->write(bus, addr, regnum, val);
mutex_unlock(&bus->mdio_lock);
return err;
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
const int num_ids = ARRAY_SIZE(phydev->c45_ids.device_ids);
int i;
if (of_driver_match_device(dev, drv))
return 1;
if (phydrv->match_phy_device)
return phydrv->match_phy_device(phydev);
if (phydev->is_c45) {
for (i = 1; i < num_ids; i++) {
if (!(phydev->c45_ids.devices_in_package & (1 << i)))
continue;
if ((phydrv->phy_id & phydrv->phy_id_mask) ==
(phydev->c45_ids.device_ids[i] &
phydrv->phy_id_mask))
return 1;
}
return 0;
} else {
return (phydrv->phy_id & phydrv->phy_id_mask) ==
(phydev->phy_id & phydrv->phy_id_mask);
}
}
static bool mdio_bus_phy_may_suspend(struct phy_device *phydev)
{
struct device_driver *drv = phydev->dev.driver;
struct phy_driver *phydrv = to_phy_driver(drv);
struct net_device *netdev = phydev->attached_dev;
if (!drv || !phydrv->suspend)
return false;
if (!netdev)
return !phydev->suspended;
if (netdev->dev.parent && device_may_wakeup(netdev->dev.parent))
return false;
if (device_may_wakeup(&netdev->dev))
return false;
return true;
}
static int mdio_bus_suspend(struct device *dev)
{
struct phy_device *phydev = to_phy_device(dev);
if (phydev->attached_dev && phydev->adjust_link)
phy_stop_machine(phydev);
if (!mdio_bus_phy_may_suspend(phydev))
return 0;
return phy_suspend(phydev);
}
static int mdio_bus_resume(struct device *dev)
{
struct phy_device *phydev = to_phy_device(dev);
int ret;
if (!mdio_bus_phy_may_suspend(phydev))
goto no_resume;
ret = phy_resume(phydev);
if (ret < 0)
return ret;
no_resume:
if (phydev->attached_dev && phydev->adjust_link)
phy_start_machine(phydev);
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
phy_start_machine(phydev);
return 0;
}
static ssize_t
phy_id_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct phy_device *phydev = to_phy_device(dev);
return sprintf(buf, "0x%.8lx\n", (unsigned long)phydev->phy_id);
}
static ssize_t
phy_interface_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct phy_device *phydev = to_phy_device(dev);
const char *mode = NULL;
if (phy_is_internal(phydev))
mode = "internal";
else
mode = phy_modes(phydev->interface);
return sprintf(buf, "%s\n", mode);
}
static ssize_t
phy_has_fixups_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct phy_device *phydev = to_phy_device(dev);
return sprintf(buf, "%d\n", phydev->has_fixups);
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
