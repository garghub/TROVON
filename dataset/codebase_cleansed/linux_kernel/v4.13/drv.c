static void drv_output_poll_changed(struct drm_device *ddev)
{
struct ltdc_device *ldev = ddev->dev_private;
drm_fbdev_cma_hotplug_event(ldev->fbdev);
}
static void drv_lastclose(struct drm_device *ddev)
{
struct ltdc_device *ldev = ddev->dev_private;
DRM_DEBUG("%s\n", __func__);
drm_fbdev_cma_restore_mode(ldev->fbdev);
}
static int drv_load(struct drm_device *ddev)
{
struct platform_device *pdev = to_platform_device(ddev->dev);
struct drm_fbdev_cma *fbdev;
struct ltdc_device *ldev;
int ret;
DRM_DEBUG("%s\n", __func__);
ldev = devm_kzalloc(ddev->dev, sizeof(*ldev), GFP_KERNEL);
if (!ldev)
return -ENOMEM;
ddev->dev_private = (void *)ldev;
drm_mode_config_init(ddev);
ddev->mode_config.min_width = 0;
ddev->mode_config.min_height = 0;
ddev->mode_config.max_width = STM_MAX_FB_WIDTH;
ddev->mode_config.max_height = STM_MAX_FB_HEIGHT;
ddev->mode_config.funcs = &drv_mode_config_funcs;
ret = ltdc_load(ddev);
if (ret)
goto err;
drm_mode_config_reset(ddev);
drm_kms_helper_poll_init(ddev);
if (ddev->mode_config.num_connector) {
ldev = ddev->dev_private;
fbdev = drm_fbdev_cma_init(ddev, 16,
ddev->mode_config.num_connector);
if (IS_ERR(fbdev)) {
DRM_DEBUG("Warning: fails to create fbdev\n");
fbdev = NULL;
}
ldev->fbdev = fbdev;
}
platform_set_drvdata(pdev, ddev);
return 0;
err:
drm_mode_config_cleanup(ddev);
return ret;
}
static void drv_unload(struct drm_device *ddev)
{
struct ltdc_device *ldev = ddev->dev_private;
DRM_DEBUG("%s\n", __func__);
if (ldev->fbdev) {
drm_fbdev_cma_fini(ldev->fbdev);
ldev->fbdev = NULL;
}
drm_kms_helper_poll_fini(ddev);
ltdc_unload(ddev);
drm_mode_config_cleanup(ddev);
}
static int stm_drm_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct drm_device *ddev;
int ret;
DRM_DEBUG("%s\n", __func__);
dma_set_coherent_mask(dev, DMA_BIT_MASK(32));
ddev = drm_dev_alloc(&drv_driver, dev);
if (IS_ERR(ddev))
return PTR_ERR(ddev);
ret = drv_load(ddev);
if (ret)
goto err_unref;
ret = drm_dev_register(ddev, 0);
if (ret)
goto err_unref;
return 0;
err_unref:
drm_dev_unref(ddev);
return ret;
}
static int stm_drm_platform_remove(struct platform_device *pdev)
{
struct drm_device *ddev = platform_get_drvdata(pdev);
DRM_DEBUG("%s\n", __func__);
drm_dev_unregister(ddev);
drv_unload(ddev);
drm_dev_unref(ddev);
return 0;
}
