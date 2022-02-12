static const struct mcb_device_id *mcb_match_id(const struct mcb_device_id *ids,
struct mcb_device *dev)
{
if (ids) {
while (ids->device) {
if (ids->device == dev->id)
return ids;
ids++;
}
}
return NULL;
}
static int mcb_match(struct device *dev, struct device_driver *drv)
{
struct mcb_driver *mdrv = to_mcb_driver(drv);
struct mcb_device *mdev = to_mcb_device(dev);
const struct mcb_device_id *found_id;
found_id = mcb_match_id(mdrv->id_table, mdev);
if (found_id)
return 1;
return 0;
}
static int mcb_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct mcb_device *mdev = to_mcb_device(dev);
int ret;
ret = add_uevent_var(env, "MODALIAS=mcb:16z%03d", mdev->id);
if (ret)
return -ENOMEM;
return 0;
}
static int mcb_probe(struct device *dev)
{
struct mcb_driver *mdrv = to_mcb_driver(dev->driver);
struct mcb_device *mdev = to_mcb_device(dev);
const struct mcb_device_id *found_id;
found_id = mcb_match_id(mdrv->id_table, mdev);
if (!found_id)
return -ENODEV;
return mdrv->probe(mdev, found_id);
}
static int mcb_remove(struct device *dev)
{
struct mcb_driver *mdrv = to_mcb_driver(dev->driver);
struct mcb_device *mdev = to_mcb_device(dev);
mdrv->remove(mdev);
put_device(&mdev->dev);
return 0;
}
static void mcb_shutdown(struct device *dev)
{
struct mcb_device *mdev = to_mcb_device(dev);
struct mcb_driver *mdrv = mdev->driver;
if (mdrv && mdrv->shutdown)
mdrv->shutdown(mdev);
}
int __mcb_register_driver(struct mcb_driver *drv, struct module *owner,
const char *mod_name)
{
if (!drv->probe || !drv->remove)
return -EINVAL;
drv->driver.owner = owner;
drv->driver.bus = &mcb_bus_type;
drv->driver.mod_name = mod_name;
return driver_register(&drv->driver);
}
void mcb_unregister_driver(struct mcb_driver *drv)
{
driver_unregister(&drv->driver);
}
static void mcb_release_dev(struct device *dev)
{
struct mcb_device *mdev = to_mcb_device(dev);
mcb_bus_put(mdev->bus);
kfree(mdev);
}
int mcb_device_register(struct mcb_bus *bus, struct mcb_device *dev)
{
int ret;
int device_id;
device_initialize(&dev->dev);
dev->dev.bus = &mcb_bus_type;
dev->dev.parent = bus->dev.parent;
dev->dev.release = mcb_release_dev;
device_id = dev->id;
dev_set_name(&dev->dev, "mcb%d-16z%03d-%d:%d:%d",
bus->bus_nr, device_id, dev->inst, dev->group, dev->var);
ret = device_add(&dev->dev);
if (ret < 0) {
pr_err("Failed registering device 16z%03d on bus mcb%d (%d)\n",
device_id, bus->bus_nr, ret);
goto out;
}
return 0;
out:
return ret;
}
struct mcb_bus *mcb_alloc_bus(struct device *carrier)
{
struct mcb_bus *bus;
int bus_nr;
bus = kzalloc(sizeof(struct mcb_bus), GFP_KERNEL);
if (!bus)
return ERR_PTR(-ENOMEM);
bus_nr = ida_simple_get(&mcb_ida, 0, 0, GFP_KERNEL);
if (bus_nr < 0) {
kfree(bus);
return ERR_PTR(bus_nr);
}
INIT_LIST_HEAD(&bus->children);
bus->bus_nr = bus_nr;
bus->carrier = carrier;
return bus;
}
static int __mcb_devices_unregister(struct device *dev, void *data)
{
device_unregister(dev);
return 0;
}
static void mcb_devices_unregister(struct mcb_bus *bus)
{
bus_for_each_dev(&mcb_bus_type, NULL, NULL, __mcb_devices_unregister);
}
void mcb_release_bus(struct mcb_bus *bus)
{
mcb_devices_unregister(bus);
ida_simple_remove(&mcb_ida, bus->bus_nr);
kfree(bus);
}
struct mcb_bus *mcb_bus_get(struct mcb_bus *bus)
{
if (bus)
get_device(&bus->dev);
return bus;
}
void mcb_bus_put(struct mcb_bus *bus)
{
if (bus)
put_device(&bus->dev);
}
struct mcb_device *mcb_alloc_dev(struct mcb_bus *bus)
{
struct mcb_device *dev;
dev = kzalloc(sizeof(struct mcb_device), GFP_KERNEL);
if (!dev)
return NULL;
INIT_LIST_HEAD(&dev->bus_list);
dev->bus = bus;
return dev;
}
void mcb_free_dev(struct mcb_device *dev)
{
kfree(dev);
}
static int __mcb_bus_add_devices(struct device *dev, void *data)
{
struct mcb_device *mdev = to_mcb_device(dev);
int retval;
if (mdev->is_added)
return 0;
retval = device_attach(dev);
if (retval < 0)
dev_err(dev, "Error adding device (%d)\n", retval);
mdev->is_added = true;
return 0;
}
static int __mcb_bus_add_child(struct device *dev, void *data)
{
struct mcb_device *mdev = to_mcb_device(dev);
struct mcb_bus *child;
BUG_ON(!mdev->is_added);
child = mdev->subordinate;
if (child)
mcb_bus_add_devices(child);
return 0;
}
void mcb_bus_add_devices(const struct mcb_bus *bus)
{
bus_for_each_dev(&mcb_bus_type, NULL, NULL, __mcb_bus_add_devices);
bus_for_each_dev(&mcb_bus_type, NULL, NULL, __mcb_bus_add_child);
}
struct resource *mcb_request_mem(struct mcb_device *dev, const char *name)
{
struct resource *mem;
u32 size;
if (!name)
name = dev->dev.driver->name;
size = resource_size(&dev->mem);
mem = request_mem_region(dev->mem.start, size, name);
if (!mem)
return ERR_PTR(-EBUSY);
return mem;
}
void mcb_release_mem(struct resource *mem)
{
u32 size;
size = resource_size(mem);
release_mem_region(mem->start, size);
}
static int __mcb_get_irq(struct mcb_device *dev)
{
struct resource *irq = &dev->irq;
return irq->start;
}
int mcb_get_irq(struct mcb_device *dev)
{
struct mcb_bus *bus = dev->bus;
if (bus->get_irq)
return bus->get_irq(dev);
return __mcb_get_irq(dev);
}
static int mcb_init(void)
{
return bus_register(&mcb_bus_type);
}
static void mcb_exit(void)
{
ida_destroy(&mcb_ida);
bus_unregister(&mcb_bus_type);
}
