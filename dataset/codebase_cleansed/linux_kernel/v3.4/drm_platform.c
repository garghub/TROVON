int drm_get_platform_dev(struct platform_device *platdev,
struct drm_driver *driver)
{
struct drm_device *dev;
int ret;
DRM_DEBUG("\n");
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->platformdev = platdev;
dev->dev = &platdev->dev;
mutex_lock(&drm_global_mutex);
ret = drm_fill_in_dev(dev, NULL, driver);
if (ret) {
printk(KERN_ERR "DRM: Fill_in_dev failed.\n");
goto err_g1;
}
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
dev_set_drvdata(&platdev->dev, dev);
ret = drm_get_minor(dev, &dev->control, DRM_MINOR_CONTROL);
if (ret)
goto err_g1;
}
ret = drm_get_minor(dev, &dev->primary, DRM_MINOR_LEGACY);
if (ret)
goto err_g2;
if (dev->driver->load) {
ret = dev->driver->load(dev, 0);
if (ret)
goto err_g3;
}
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = drm_mode_group_init_legacy_group(dev,
&dev->primary->mode_group);
if (ret)
goto err_g3;
}
list_add_tail(&dev->driver_item, &driver->device_list);
mutex_unlock(&drm_global_mutex);
DRM_INFO("Initialized %s %d.%d.%d %s on minor %d\n",
driver->name, driver->major, driver->minor, driver->patchlevel,
driver->date, dev->primary->index);
return 0;
err_g3:
drm_put_minor(&dev->primary);
err_g2:
if (drm_core_check_feature(dev, DRIVER_MODESET))
drm_put_minor(&dev->control);
err_g1:
kfree(dev);
mutex_unlock(&drm_global_mutex);
return ret;
}
static int drm_platform_get_irq(struct drm_device *dev)
{
return platform_get_irq(dev->platformdev, 0);
}
static const char *drm_platform_get_name(struct drm_device *dev)
{
return dev->platformdev->name;
}
static int drm_platform_set_busid(struct drm_device *dev, struct drm_master *master)
{
int len, ret, id;
master->unique_len = 13 + strlen(dev->platformdev->name);
master->unique_size = master->unique_len;
master->unique = kmalloc(master->unique_len + 1, GFP_KERNEL);
if (master->unique == NULL)
return -ENOMEM;
id = dev->platformdev->id;
if (id == -1)
id = 0;
len = snprintf(master->unique, master->unique_len,
"platform:%s:%02d", dev->platformdev->name, id);
if (len > master->unique_len) {
DRM_ERROR("Unique buffer overflowed\n");
ret = -EINVAL;
goto err;
}
dev->devname =
kmalloc(strlen(dev->platformdev->name) +
master->unique_len + 2, GFP_KERNEL);
if (dev->devname == NULL) {
ret = -ENOMEM;
goto err;
}
sprintf(dev->devname, "%s@%s", dev->platformdev->name,
master->unique);
return 0;
err:
return ret;
}
int drm_platform_init(struct drm_driver *driver, struct platform_device *platform_device)
{
DRM_DEBUG("\n");
driver->kdriver.platform_device = platform_device;
driver->bus = &drm_platform_bus;
INIT_LIST_HEAD(&driver->device_list);
return drm_get_platform_dev(platform_device, driver);
}
void drm_platform_exit(struct drm_driver *driver, struct platform_device *platform_device)
{
struct drm_device *dev, *tmp;
DRM_DEBUG("\n");
list_for_each_entry_safe(dev, tmp, &driver->device_list, driver_item)
drm_put_dev(dev);
DRM_INFO("Module unloaded\n");
}
