int mdiobus_register_device(struct mdio_device *mdiodev)
{
if (mdiodev->bus->mdio_map[mdiodev->addr])
return -EBUSY;
mdiodev->bus->mdio_map[mdiodev->addr] = mdiodev;
return 0;
}
int mdiobus_unregister_device(struct mdio_device *mdiodev)
{
if (mdiodev->bus->mdio_map[mdiodev->addr] != mdiodev)
return -EINVAL;
mdiodev->bus->mdio_map[mdiodev->addr] = NULL;
return 0;
}
struct phy_device *mdiobus_get_phy(struct mii_bus *bus, int addr)
{
struct mdio_device *mdiodev = bus->mdio_map[addr];
if (!mdiodev)
return NULL;
if (!(mdiodev->flags & MDIO_DEVICE_FLAG_PHY))
return NULL;
return container_of(mdiodev, struct phy_device, mdio);
}
bool mdiobus_is_registered_device(struct mii_bus *bus, int addr)
{
return bus->mdio_map[addr];
}
struct mii_bus *mdiobus_alloc_size(size_t size)
{
struct mii_bus *bus;
size_t aligned_size = ALIGN(sizeof(*bus), NETDEV_ALIGN);
size_t alloc_size;
int i;
if (size)
alloc_size = aligned_size + size;
else
alloc_size = sizeof(*bus);
bus = kzalloc(alloc_size, GFP_KERNEL);
if (!bus)
return NULL;
bus->state = MDIOBUS_ALLOCATED;
if (size)
bus->priv = (void *)bus + aligned_size;
for (i = 0; i < PHY_MAX_ADDR; i++)
bus->irq[i] = PHY_POLL;
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
static void of_mdiobus_link_mdiodev(struct mii_bus *bus,
struct mdio_device *mdiodev)
{
struct device *dev = &mdiodev->dev;
struct device_node *child;
if (dev->of_node || !bus->dev.of_node)
return;
for_each_available_child_of_node(bus->dev.of_node, child) {
int addr;
int ret;
ret = of_property_read_u32(child, "reg", &addr);
if (ret < 0) {
dev_err(dev, "%s has invalid MDIO address\n",
child->full_name);
continue;
}
if (addr >= PHY_MAX_ADDR) {
dev_err(dev, "%s MDIO address %i is too large\n",
child->full_name, addr);
continue;
}
if (addr == mdiodev->addr) {
dev->of_node = child;
return;
}
}
}
static inline void of_mdiobus_link_mdiodev(struct mii_bus *mdio,
struct mdio_device *mdiodev)
{
}
int __mdiobus_register(struct mii_bus *bus, struct module *owner)
{
struct mdio_device *mdiodev;
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
mdiodev = bus->mdio_map[i];
if (!mdiodev)
continue;
mdiodev->device_remove(mdiodev);
mdiodev->device_free(mdiodev);
}
device_del(&bus->dev);
return err;
}
void mdiobus_unregister(struct mii_bus *bus)
{
struct mdio_device *mdiodev;
int i;
BUG_ON(bus->state != MDIOBUS_REGISTERED);
bus->state = MDIOBUS_UNREGISTERED;
for (i = 0; i < PHY_MAX_ADDR; i++) {
mdiodev = bus->mdio_map[i];
if (!mdiodev)
continue;
mdiodev->device_remove(mdiodev);
mdiodev->device_free(mdiodev);
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
of_mdiobus_link_mdiodev(bus, &phydev->mdio);
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
struct mdio_device *mdio = to_mdio_device(dev);
if (of_driver_match_device(dev, drv))
return 1;
if (mdio->bus_match)
return mdio->bus_match(dev, drv);
return 0;
}
static int mdio_bus_suspend(struct device *dev)
{
struct mdio_device *mdio = to_mdio_device(dev);
if (mdio->pm_ops && mdio->pm_ops->suspend)
return mdio->pm_ops->suspend(dev);
return 0;
}
static int mdio_bus_resume(struct device *dev)
{
struct mdio_device *mdio = to_mdio_device(dev);
if (mdio->pm_ops && mdio->pm_ops->resume)
return mdio->pm_ops->resume(dev);
return 0;
}
static int mdio_bus_restore(struct device *dev)
{
struct mdio_device *mdio = to_mdio_device(dev);
if (mdio->pm_ops && mdio->pm_ops->restore)
return mdio->pm_ops->restore(dev);
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
