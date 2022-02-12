static int drm_get_platform_dev(struct platform_device *platdev,
struct drm_driver *driver)
{
struct drm_device *dev;
int ret;
DRM_DEBUG("\n");
dev = drm_dev_alloc(driver, &platdev->dev);
if (IS_ERR(dev))
return PTR_ERR(dev);
dev->platformdev = platdev;
ret = drm_dev_register(dev, 0);
if (ret)
goto err_free;
return 0;
err_free:
drm_dev_unref(dev);
return ret;
}
int drm_platform_init(struct drm_driver *driver, struct platform_device *platform_device)
{
DRM_DEBUG("\n");
return drm_get_platform_dev(platform_device, driver);
}
