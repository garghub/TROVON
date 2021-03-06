static void ipack_device_release(struct device *dev)
{
struct ipack_device *device = to_ipack_dev(dev);
kfree(device);
}
static int ipack_bus_match(struct device *device, struct device_driver *driver)
{
int ret;
struct ipack_device *dev = to_ipack_dev(device);
struct ipack_driver *drv = to_ipack_driver(driver);
if ((!drv->ops) || (!drv->ops->match))
return -EINVAL;
ret = drv->ops->match(dev);
if (ret)
dev->driver = drv;
return ret;
}
static int ipack_bus_probe(struct device *device)
{
struct ipack_device *dev = to_ipack_dev(device);
if (!dev->driver->ops->probe)
return -EINVAL;
return dev->driver->ops->probe(dev);
}
static int ipack_bus_remove(struct device *device)
{
struct ipack_device *dev = to_ipack_dev(device);
if (!dev->driver->ops->remove)
return -EINVAL;
dev->driver->ops->remove(dev);
return 0;
}
struct ipack_bus_device *ipack_bus_register(struct device *parent, int slots,
struct ipack_bus_ops *ops)
{
int bus_nr;
struct ipack_bus_device *bus;
bus = kzalloc(sizeof(struct ipack_bus_device), GFP_KERNEL);
if (!bus)
return NULL;
bus_nr = ida_simple_get(&ipack_ida, 0, 0, GFP_KERNEL);
if (bus_nr < 0) {
kfree(bus);
return NULL;
}
bus->bus_nr = bus_nr;
bus->parent = parent;
bus->slots = slots;
bus->ops = ops;
return bus;
}
int ipack_bus_unregister(struct ipack_bus_device *bus)
{
ida_simple_remove(&ipack_ida, bus->bus_nr);
kfree(bus);
return 0;
}
int ipack_driver_register(struct ipack_driver *edrv, struct module *owner,
char *name)
{
edrv->driver.owner = owner;
edrv->driver.name = name;
edrv->driver.bus = &ipack_bus_type;
return driver_register(&edrv->driver);
}
void ipack_driver_unregister(struct ipack_driver *edrv)
{
driver_unregister(&edrv->driver);
}
struct ipack_device *ipack_device_register(struct ipack_bus_device *bus,
int slot, int irqv)
{
int ret;
struct ipack_device *dev;
dev = kzalloc(sizeof(struct ipack_device), GFP_KERNEL);
if (!dev)
return NULL;
dev->dev.bus = &ipack_bus_type;
dev->dev.release = ipack_device_release;
dev->dev.parent = bus->parent;
dev->slot = slot;
dev->bus_nr = bus->bus_nr;
dev->irq = irqv;
dev->bus = bus;
dev_set_name(&dev->dev,
"ipack-dev.%u.%u", dev->bus_nr, dev->slot);
ret = device_register(&dev->dev);
if (ret < 0) {
kfree(dev);
return NULL;
}
return dev;
}
void ipack_device_unregister(struct ipack_device *dev)
{
device_unregister(&dev->dev);
}
static int __init ipack_init(void)
{
ida_init(&ipack_ida);
return bus_register(&ipack_bus_type);
}
static void __exit ipack_exit(void)
{
bus_unregister(&ipack_bus_type);
ida_destroy(&ipack_ida);
}
