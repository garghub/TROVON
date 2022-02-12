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
int drm_platform_set_busid(struct drm_device *dev, struct drm_master *master)
{
int id;
id = dev->platformdev->id;
if (id < 0)
id = 0;
master->unique = kasprintf(GFP_KERNEL, "platform:%s:%02d",
dev->platformdev->name, id);
if (!master->unique)
return -ENOMEM;
master->unique_len = strlen(master->unique);
return 0;
}
int drm_platform_init(struct drm_driver *driver, struct platform_device *platform_device)
{
DRM_DEBUG("\n");
return drm_get_platform_dev(platform_device, driver);
}
