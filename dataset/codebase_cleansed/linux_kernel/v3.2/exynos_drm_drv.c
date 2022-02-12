static int exynos_drm_load(struct drm_device *dev, unsigned long flags)
{
struct exynos_drm_private *private;
int ret;
int nr;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
private = kzalloc(sizeof(struct exynos_drm_private), GFP_KERNEL);
if (!private) {
DRM_ERROR("failed to allocate private\n");
return -ENOMEM;
}
INIT_LIST_HEAD(&private->pageflip_event_list);
dev->dev_private = (void *)private;
drm_mode_config_init(dev);
drm_kms_helper_poll_init(dev);
exynos_drm_mode_config_init(dev);
for (nr = 0; nr < MAX_CRTC; nr++) {
ret = exynos_drm_crtc_create(dev, nr);
if (ret)
goto err_crtc;
}
ret = drm_vblank_init(dev, MAX_CRTC);
if (ret)
goto err_crtc;
ret = exynos_drm_device_register(dev);
if (ret)
goto err_vblank;
ret = exynos_drm_fbdev_init(dev);
if (ret) {
DRM_ERROR("failed to initialize drm fbdev\n");
goto err_drm_device;
}
return 0;
err_drm_device:
exynos_drm_device_unregister(dev);
err_vblank:
drm_vblank_cleanup(dev);
err_crtc:
drm_mode_config_cleanup(dev);
kfree(private);
return ret;
}
static int exynos_drm_unload(struct drm_device *dev)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
exynos_drm_fbdev_fini(dev);
exynos_drm_device_unregister(dev);
drm_vblank_cleanup(dev);
drm_kms_helper_poll_fini(dev);
drm_mode_config_cleanup(dev);
kfree(dev->dev_private);
dev->dev_private = NULL;
return 0;
}
static void exynos_drm_preclose(struct drm_device *dev,
struct drm_file *file_priv)
{
struct exynos_drm_private *dev_priv = dev->dev_private;
if (!list_empty(&dev_priv->pageflip_event_list))
INIT_LIST_HEAD(&dev_priv->pageflip_event_list);
}
static void exynos_drm_lastclose(struct drm_device *dev)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
exynos_drm_fbdev_restore_mode(dev);
}
static int exynos_drm_platform_probe(struct platform_device *pdev)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
exynos_drm_driver.num_ioctls = DRM_ARRAY_SIZE(exynos_ioctls);
return drm_platform_init(&exynos_drm_driver, pdev);
}
static int exynos_drm_platform_remove(struct platform_device *pdev)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
drm_platform_exit(&exynos_drm_driver, pdev);
return 0;
}
static int __init exynos_drm_init(void)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
return platform_driver_register(&exynos_drm_platform_driver);
}
static void __exit exynos_drm_exit(void)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
platform_driver_unregister(&exynos_drm_platform_driver);
}
