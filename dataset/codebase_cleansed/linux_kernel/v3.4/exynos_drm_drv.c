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
for (nr = 0; nr < MAX_PLANE; nr++) {
ret = exynos_plane_init(dev, nr);
if (ret)
goto err_crtc;
}
ret = drm_vblank_init(dev, MAX_CRTC);
if (ret)
goto err_crtc;
ret = exynos_drm_device_register(dev);
if (ret)
goto err_vblank;
exynos_drm_encoder_setup(dev);
ret = exynos_drm_fbdev_init(dev);
if (ret) {
DRM_ERROR("failed to initialize drm fbdev\n");
goto err_drm_device;
}
drm_vblank_offdelay = VBLANK_OFF_DELAY;
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
static int exynos_drm_open(struct drm_device *dev, struct drm_file *file)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
return exynos_drm_subdrv_open(dev, file);
}
static void exynos_drm_preclose(struct drm_device *dev,
struct drm_file *file)
{
struct exynos_drm_private *private = dev->dev_private;
struct drm_pending_vblank_event *e, *t;
unsigned long flags;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
spin_lock_irqsave(&dev->event_lock, flags);
list_for_each_entry_safe(e, t, &private->pageflip_event_list,
base.link) {
if (e->base.file_priv == file) {
list_del(&e->base.link);
e->base.destroy(&e->base);
}
}
spin_unlock_irqrestore(&dev->event_lock, flags);
exynos_drm_subdrv_close(dev, file);
}
static void exynos_drm_postclose(struct drm_device *dev, struct drm_file *file)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (!file->driver_priv)
return;
kfree(file->driver_priv);
file->driver_priv = NULL;
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
int ret;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
#ifdef CONFIG_DRM_EXYNOS_FIMD
ret = platform_driver_register(&fimd_driver);
if (ret < 0)
goto out_fimd;
#endif
#ifdef CONFIG_DRM_EXYNOS_HDMI
ret = platform_driver_register(&hdmi_driver);
if (ret < 0)
goto out_hdmi;
ret = platform_driver_register(&mixer_driver);
if (ret < 0)
goto out_mixer;
ret = platform_driver_register(&exynos_drm_common_hdmi_driver);
if (ret < 0)
goto out_common_hdmi;
#endif
#ifdef CONFIG_DRM_EXYNOS_VIDI
ret = platform_driver_register(&vidi_driver);
if (ret < 0)
goto out_vidi;
#endif
ret = platform_driver_register(&exynos_drm_platform_driver);
if (ret < 0)
goto out;
return 0;
out:
#ifdef CONFIG_DRM_EXYNOS_VIDI
out_vidi:
platform_driver_unregister(&vidi_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_HDMI
platform_driver_unregister(&exynos_drm_common_hdmi_driver);
out_common_hdmi:
platform_driver_unregister(&mixer_driver);
out_mixer:
platform_driver_unregister(&hdmi_driver);
out_hdmi:
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMD
platform_driver_unregister(&fimd_driver);
out_fimd:
#endif
return ret;
}
static void __exit exynos_drm_exit(void)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
platform_driver_unregister(&exynos_drm_platform_driver);
#ifdef CONFIG_DRM_EXYNOS_HDMI
platform_driver_unregister(&exynos_drm_common_hdmi_driver);
platform_driver_unregister(&mixer_driver);
platform_driver_unregister(&hdmi_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_VIDI
platform_driver_unregister(&vidi_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMD
platform_driver_unregister(&fimd_driver);
#endif
}
