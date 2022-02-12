static void iommu_release_device(struct device *dev)
{
kfree(dev);
}
static int __init iommu_dev_init(void)
{
return class_register(&iommu_class);
}
struct device *iommu_device_create(struct device *parent, void *drvdata,
const struct attribute_group **groups,
const char *fmt, ...)
{
struct device *dev;
va_list vargs;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return ERR_PTR(-ENOMEM);
device_initialize(dev);
dev->class = &iommu_class;
dev->parent = parent;
dev->groups = groups;
dev_set_drvdata(dev, drvdata);
va_start(vargs, fmt);
ret = kobject_set_name_vargs(&dev->kobj, fmt, vargs);
va_end(vargs);
if (ret)
goto error;
ret = device_add(dev);
if (ret)
goto error;
return dev;
error:
put_device(dev);
return ERR_PTR(ret);
}
void iommu_device_destroy(struct device *dev)
{
if (!dev || IS_ERR(dev))
return;
device_unregister(dev);
}
int iommu_device_link(struct device *dev, struct device *link)
{
int ret;
if (!dev || IS_ERR(dev))
return -ENODEV;
ret = sysfs_add_link_to_group(&dev->kobj, "devices",
&link->kobj, dev_name(link));
if (ret)
return ret;
ret = sysfs_create_link_nowarn(&link->kobj, &dev->kobj, "iommu");
if (ret)
sysfs_remove_link_from_group(&dev->kobj, "devices",
dev_name(link));
return ret;
}
void iommu_device_unlink(struct device *dev, struct device *link)
{
if (!dev || IS_ERR(dev))
return;
sysfs_remove_link(&link->kobj, "iommu");
sysfs_remove_link_from_group(&dev->kobj, "devices", dev_name(link));
}
