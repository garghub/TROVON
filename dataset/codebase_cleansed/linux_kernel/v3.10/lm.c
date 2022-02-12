static int lm_match(struct device *dev, struct device_driver *drv)
{
return 1;
}
static int lm_bus_probe(struct device *dev)
{
struct lm_device *lmdev = to_lm_device(dev);
struct lm_driver *lmdrv = to_lm_driver(dev->driver);
return lmdrv->probe(lmdev);
}
static int lm_bus_remove(struct device *dev)
{
struct lm_device *lmdev = to_lm_device(dev);
struct lm_driver *lmdrv = to_lm_driver(dev->driver);
if (lmdrv->remove)
lmdrv->remove(lmdev);
return 0;
}
static int __init lm_init(void)
{
return bus_register(&lm_bustype);
}
int lm_driver_register(struct lm_driver *drv)
{
drv->drv.bus = &lm_bustype;
return driver_register(&drv->drv);
}
void lm_driver_unregister(struct lm_driver *drv)
{
driver_unregister(&drv->drv);
}
static void lm_device_release(struct device *dev)
{
struct lm_device *d = to_lm_device(dev);
kfree(d);
}
int lm_device_register(struct lm_device *dev)
{
int ret;
dev->dev.release = lm_device_release;
dev->dev.bus = &lm_bustype;
ret = dev_set_name(&dev->dev, "lm%d", dev->id);
if (ret)
return ret;
dev->resource.name = dev_name(&dev->dev);
ret = request_resource(&iomem_resource, &dev->resource);
if (ret == 0) {
ret = device_register(&dev->dev);
if (ret)
release_resource(&dev->resource);
}
return ret;
}
