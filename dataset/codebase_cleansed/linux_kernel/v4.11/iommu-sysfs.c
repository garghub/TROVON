static void iommu_release_device(struct device *dev)
{
kfree(dev);
}
static int __init iommu_dev_init(void)
{
return class_register(&iommu_class);
}
int iommu_device_sysfs_add(struct iommu_device *iommu,
struct device *parent,
const struct attribute_group **groups,
const char *fmt, ...)
{
va_list vargs;
int ret;
device_initialize(&iommu->dev);
iommu->dev.class = &iommu_class;
iommu->dev.parent = parent;
iommu->dev.groups = groups;
va_start(vargs, fmt);
ret = kobject_set_name_vargs(&iommu->dev.kobj, fmt, vargs);
va_end(vargs);
if (ret)
goto error;
ret = device_add(&iommu->dev);
if (ret)
goto error;
return 0;
error:
put_device(&iommu->dev);
return ret;
}
void iommu_device_sysfs_remove(struct iommu_device *iommu)
{
device_unregister(&iommu->dev);
}
int iommu_device_link(struct iommu_device *iommu, struct device *link)
{
int ret;
if (!iommu || IS_ERR(iommu))
return -ENODEV;
ret = sysfs_add_link_to_group(&iommu->dev.kobj, "devices",
&link->kobj, dev_name(link));
if (ret)
return ret;
ret = sysfs_create_link_nowarn(&link->kobj, &iommu->dev.kobj, "iommu");
if (ret)
sysfs_remove_link_from_group(&iommu->dev.kobj, "devices",
dev_name(link));
return ret;
}
void iommu_device_unlink(struct iommu_device *iommu, struct device *link)
{
if (!iommu || IS_ERR(iommu))
return;
sysfs_remove_link(&link->kobj, "iommu");
sysfs_remove_link_from_group(&iommu->dev.kobj, "devices", dev_name(link));
}
