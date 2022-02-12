static int drm_get_platform_dev(struct platform_device *platdev,
struct drm_driver *driver)
{
struct drm_device *dev;
int ret;
DRM_DEBUG("\n");
dev = drm_dev_alloc(driver, &platdev->dev);
if (!dev)
return -ENOMEM;
dev->platformdev = platdev;
ret = drm_dev_register(dev, 0);
if (ret)
goto err_free;
DRM_INFO("Initialized %s %d.%d.%d %s on minor %d\n",
driver->name, driver->major, driver->minor, driver->patchlevel,
driver->date, dev->primary->index);
return 0;
err_free:
drm_dev_unref(dev);
return ret;
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
return 0;
err:
return ret;
}
int drm_platform_init(struct drm_driver *driver, struct platform_device *platform_device)
{
DRM_DEBUG("\n");
driver->bus = &drm_platform_bus;
return drm_get_platform_dev(platform_device, driver);
}
