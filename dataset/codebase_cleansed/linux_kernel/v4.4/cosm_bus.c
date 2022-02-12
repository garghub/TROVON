static int cosm_dev_probe(struct device *d)
{
struct cosm_device *dev = dev_to_cosm(d);
struct cosm_driver *drv = drv_to_cosm(dev->dev.driver);
return drv->probe(dev);
}
static int cosm_dev_remove(struct device *d)
{
struct cosm_device *dev = dev_to_cosm(d);
struct cosm_driver *drv = drv_to_cosm(dev->dev.driver);
drv->remove(dev);
return 0;
}
int cosm_register_driver(struct cosm_driver *driver)
{
driver->driver.bus = &cosm_bus;
return driver_register(&driver->driver);
}
void cosm_unregister_driver(struct cosm_driver *driver)
{
driver_unregister(&driver->driver);
}
static inline void cosm_release_dev(struct device *d)
{
struct cosm_device *cdev = dev_to_cosm(d);
kfree(cdev);
}
struct cosm_device *
cosm_register_device(struct device *pdev, struct cosm_hw_ops *hw_ops)
{
struct cosm_device *cdev;
int ret;
cdev = kzalloc(sizeof(*cdev), GFP_KERNEL);
if (!cdev)
return ERR_PTR(-ENOMEM);
cdev->dev.parent = pdev;
cdev->dev.release = cosm_release_dev;
cdev->hw_ops = hw_ops;
dev_set_drvdata(&cdev->dev, cdev);
cdev->dev.bus = &cosm_bus;
ret = ida_simple_get(&cosm_index_ida, 0, 0, GFP_KERNEL);
if (ret < 0)
goto free_cdev;
cdev->index = ret;
cdev->dev.id = ret;
dev_set_name(&cdev->dev, "cosm-dev%u", cdev->index);
ret = device_register(&cdev->dev);
if (ret)
goto ida_remove;
return cdev;
ida_remove:
ida_simple_remove(&cosm_index_ida, cdev->index);
free_cdev:
put_device(&cdev->dev);
return ERR_PTR(ret);
}
void cosm_unregister_device(struct cosm_device *dev)
{
int index = dev->index;
device_unregister(&dev->dev);
ida_simple_remove(&cosm_index_ida, index);
}
struct cosm_device *cosm_find_cdev_by_id(int id)
{
struct device *dev = subsys_find_device_by_id(&cosm_bus, id, NULL);
return dev ? container_of(dev, struct cosm_device, dev) : NULL;
}
static int __init cosm_init(void)
{
return bus_register(&cosm_bus);
}
static void __exit cosm_exit(void)
{
bus_unregister(&cosm_bus);
ida_destroy(&cosm_index_ida);
}
