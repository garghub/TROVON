static void superhyway_device_release(struct device *dev)
{
struct superhyway_device *sdev = to_superhyway_device(dev);
kfree(sdev->resource);
kfree(sdev);
}
int superhyway_add_device(unsigned long base, struct superhyway_device *sdev,
struct superhyway_bus *bus)
{
struct superhyway_device *dev = sdev;
if (!dev) {
dev = kzalloc(sizeof(struct superhyway_device), GFP_KERNEL);
if (!dev)
return -ENOMEM;
}
dev->bus = bus;
superhyway_read_vcr(dev, base, &dev->vcr);
if (!dev->resource) {
dev->resource = kzalloc(sizeof(struct resource), GFP_KERNEL);
if (!dev->resource) {
kfree(dev);
return -ENOMEM;
}
dev->resource->name = dev->name;
dev->resource->start = base;
dev->resource->end = dev->resource->start + 0x01000000;
}
dev->dev.parent = &superhyway_bus_device;
dev->dev.bus = &superhyway_bus_type;
dev->dev.release = superhyway_device_release;
dev->id.id = dev->vcr.mod_id;
sprintf(dev->name, "SuperHyway device %04x", dev->id.id);
dev_set_name(&dev->dev, "%02x", superhyway_devices);
superhyway_devices++;
return device_register(&dev->dev);
}
int superhyway_add_devices(struct superhyway_bus *bus,
struct superhyway_device **devices,
int nr_devices)
{
int i, ret = 0;
for (i = 0; i < nr_devices; i++) {
struct superhyway_device *dev = devices[i];
ret |= superhyway_add_device(dev->resource[0].start, dev, bus);
}
return ret;
}
static int __init superhyway_init(void)
{
struct superhyway_bus *bus;
int ret;
ret = device_register(&superhyway_bus_device);
if (unlikely(ret))
return ret;
for (bus = superhyway_channels; bus->ops; bus++)
ret |= superhyway_scan_bus(bus);
return ret;
}
static const struct superhyway_device_id *
superhyway_match_id(const struct superhyway_device_id *ids,
struct superhyway_device *dev)
{
while (ids->id) {
if (ids->id == dev->id.id)
return ids;
ids++;
}
return NULL;
}
static int superhyway_device_probe(struct device *dev)
{
struct superhyway_device *shyway_dev = to_superhyway_device(dev);
struct superhyway_driver *shyway_drv = to_superhyway_driver(dev->driver);
if (shyway_drv && shyway_drv->probe) {
const struct superhyway_device_id *id;
id = superhyway_match_id(shyway_drv->id_table, shyway_dev);
if (id)
return shyway_drv->probe(shyway_dev, id);
}
return -ENODEV;
}
static int superhyway_device_remove(struct device *dev)
{
struct superhyway_device *shyway_dev = to_superhyway_device(dev);
struct superhyway_driver *shyway_drv = to_superhyway_driver(dev->driver);
if (shyway_drv && shyway_drv->remove) {
shyway_drv->remove(shyway_dev);
return 0;
}
return -ENODEV;
}
int superhyway_register_driver(struct superhyway_driver *drv)
{
drv->drv.name = drv->name;
drv->drv.bus = &superhyway_bus_type;
return driver_register(&drv->drv);
}
void superhyway_unregister_driver(struct superhyway_driver *drv)
{
driver_unregister(&drv->drv);
}
static int superhyway_bus_match(struct device *dev, struct device_driver *drv)
{
struct superhyway_device *shyway_dev = to_superhyway_device(dev);
struct superhyway_driver *shyway_drv = to_superhyway_driver(drv);
const struct superhyway_device_id *ids = shyway_drv->id_table;
if (!ids)
return -EINVAL;
if (superhyway_match_id(ids, shyway_dev))
return 1;
return -ENODEV;
}
static int __init superhyway_bus_init(void)
{
return bus_register(&superhyway_bus_type);
}
static void __exit superhyway_bus_exit(void)
{
device_unregister(&superhyway_bus_device);
bus_unregister(&superhyway_bus_type);
}
