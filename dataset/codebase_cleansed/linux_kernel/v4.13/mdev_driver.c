static int mdev_attach_iommu(struct mdev_device *mdev)
{
int ret;
struct iommu_group *group;
group = iommu_group_alloc();
if (IS_ERR(group))
return PTR_ERR(group);
ret = iommu_group_add_device(group, &mdev->dev);
if (!ret)
dev_info(&mdev->dev, "MDEV: group_id = %d\n",
iommu_group_id(group));
iommu_group_put(group);
return ret;
}
static void mdev_detach_iommu(struct mdev_device *mdev)
{
iommu_group_remove_device(&mdev->dev);
dev_info(&mdev->dev, "MDEV: detaching iommu\n");
}
static int mdev_probe(struct device *dev)
{
struct mdev_driver *drv = to_mdev_driver(dev->driver);
struct mdev_device *mdev = to_mdev_device(dev);
int ret;
ret = mdev_attach_iommu(mdev);
if (ret)
return ret;
if (drv && drv->probe) {
ret = drv->probe(dev);
if (ret)
mdev_detach_iommu(mdev);
}
return ret;
}
static int mdev_remove(struct device *dev)
{
struct mdev_driver *drv = to_mdev_driver(dev->driver);
struct mdev_device *mdev = to_mdev_device(dev);
if (drv && drv->remove)
drv->remove(dev);
mdev_detach_iommu(mdev);
return 0;
}
int mdev_register_driver(struct mdev_driver *drv, struct module *owner)
{
drv->driver.name = drv->name;
drv->driver.bus = &mdev_bus_type;
drv->driver.owner = owner;
return driver_register(&drv->driver);
}
void mdev_unregister_driver(struct mdev_driver *drv)
{
driver_unregister(&drv->driver);
}
int mdev_bus_register(void)
{
return bus_register(&mdev_bus_type);
}
void mdev_bus_unregister(void)
{
bus_unregister(&mdev_bus_type);
}
