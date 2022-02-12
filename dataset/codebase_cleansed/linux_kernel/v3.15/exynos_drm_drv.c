static int exynos_drm_load(struct drm_device *dev, unsigned long flags)
{
struct exynos_drm_private *private;
int ret;
int nr;
private = kzalloc(sizeof(struct exynos_drm_private), GFP_KERNEL);
if (!private)
return -ENOMEM;
INIT_LIST_HEAD(&private->pageflip_event_list);
dev_set_drvdata(dev->dev, dev);
dev->dev_private = (void *)private;
ret = drm_create_iommu_mapping(dev);
if (ret < 0) {
DRM_ERROR("failed to create iommu mapping.\n");
goto err_free_private;
}
drm_mode_config_init(dev);
exynos_drm_mode_config_init(dev);
ret = exynos_drm_initialize_managers(dev);
if (ret)
goto err_mode_config_cleanup;
for (nr = 0; nr < MAX_PLANE; nr++) {
struct drm_plane *plane;
unsigned long possible_crtcs = (1 << MAX_CRTC) - 1;
plane = exynos_plane_init(dev, possible_crtcs, false);
if (!plane)
goto err_manager_cleanup;
}
ret = exynos_drm_initialize_displays(dev);
if (ret)
goto err_manager_cleanup;
drm_kms_helper_poll_init(dev);
ret = drm_vblank_init(dev, MAX_CRTC);
if (ret)
goto err_display_cleanup;
ret = exynos_drm_device_register(dev);
if (ret)
goto err_vblank;
exynos_drm_encoder_setup(dev);
drm_vblank_offdelay = VBLANK_OFF_DELAY;
platform_set_drvdata(dev->platformdev, dev);
drm_helper_hpd_irq_event(dev);
return 0;
err_vblank:
drm_vblank_cleanup(dev);
err_display_cleanup:
exynos_drm_remove_displays(dev);
err_manager_cleanup:
exynos_drm_remove_managers(dev);
err_mode_config_cleanup:
drm_mode_config_cleanup(dev);
drm_release_iommu_mapping(dev);
err_free_private:
kfree(private);
return ret;
}
static int exynos_drm_unload(struct drm_device *dev)
{
exynos_drm_fbdev_fini(dev);
exynos_drm_device_unregister(dev);
drm_vblank_cleanup(dev);
drm_kms_helper_poll_fini(dev);
exynos_drm_remove_displays(dev);
exynos_drm_remove_managers(dev);
drm_mode_config_cleanup(dev);
drm_release_iommu_mapping(dev);
kfree(dev->dev_private);
dev->dev_private = NULL;
return 0;
}
static int exynos_drm_suspend(struct drm_device *dev, pm_message_t state)
{
struct drm_connector *connector;
drm_modeset_lock_all(dev);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
int old_dpms = connector->dpms;
if (connector->funcs->dpms)
connector->funcs->dpms(connector, DRM_MODE_DPMS_OFF);
connector->dpms = old_dpms;
}
drm_modeset_unlock_all(dev);
return 0;
}
static int exynos_drm_resume(struct drm_device *dev)
{
struct drm_connector *connector;
drm_modeset_lock_all(dev);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->funcs->dpms)
connector->funcs->dpms(connector, connector->dpms);
}
drm_helper_resume_force_mode(dev);
drm_modeset_unlock_all(dev);
return 0;
}
static int exynos_drm_open(struct drm_device *dev, struct drm_file *file)
{
struct drm_exynos_file_private *file_priv;
struct file *anon_filp;
int ret;
file_priv = kzalloc(sizeof(*file_priv), GFP_KERNEL);
if (!file_priv)
return -ENOMEM;
file->driver_priv = file_priv;
ret = exynos_drm_subdrv_open(dev, file);
if (ret)
goto err_file_priv_free;
anon_filp = anon_inode_getfile("exynos_gem", &exynos_drm_gem_fops,
NULL, 0);
if (IS_ERR(anon_filp)) {
ret = PTR_ERR(anon_filp);
goto err_subdrv_close;
}
anon_filp->f_mode = FMODE_READ | FMODE_WRITE;
file_priv->anon_filp = anon_filp;
return ret;
err_subdrv_close:
exynos_drm_subdrv_close(dev, file);
err_file_priv_free:
kfree(file_priv);
file->driver_priv = NULL;
return ret;
}
static void exynos_drm_preclose(struct drm_device *dev,
struct drm_file *file)
{
exynos_drm_subdrv_close(dev, file);
}
static void exynos_drm_postclose(struct drm_device *dev, struct drm_file *file)
{
struct exynos_drm_private *private = dev->dev_private;
struct drm_exynos_file_private *file_priv;
struct drm_pending_vblank_event *v, *vt;
struct drm_pending_event *e, *et;
unsigned long flags;
if (!file->driver_priv)
return;
spin_lock_irqsave(&dev->event_lock, flags);
list_for_each_entry_safe(v, vt, &private->pageflip_event_list,
base.link) {
if (v->base.file_priv == file) {
list_del(&v->base.link);
drm_vblank_put(dev, v->pipe);
v->base.destroy(&v->base);
}
}
list_for_each_entry_safe(e, et, &file->event_list, link) {
list_del(&e->link);
e->destroy(e);
}
spin_unlock_irqrestore(&dev->event_lock, flags);
file_priv = file->driver_priv;
if (file_priv->anon_filp)
fput(file_priv->anon_filp);
kfree(file->driver_priv);
file->driver_priv = NULL;
}
static void exynos_drm_lastclose(struct drm_device *dev)
{
exynos_drm_fbdev_restore_mode(dev);
}
static int exynos_drm_platform_probe(struct platform_device *pdev)
{
int ret;
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
return drm_platform_init(&exynos_drm_driver, pdev);
}
static int exynos_drm_platform_remove(struct platform_device *pdev)
{
drm_put_dev(platform_get_drvdata(pdev));
return 0;
}
static int exynos_drm_sys_suspend(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
pm_message_t message;
if (pm_runtime_suspended(dev))
return 0;
message.event = PM_EVENT_SUSPEND;
return exynos_drm_suspend(drm_dev, message);
}
static int exynos_drm_sys_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
if (pm_runtime_suspended(dev))
return 0;
return exynos_drm_resume(drm_dev);
}
static int exynos_drm_runtime_suspend(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
pm_message_t message;
if (pm_runtime_suspended(dev))
return 0;
message.event = PM_EVENT_SUSPEND;
return exynos_drm_suspend(drm_dev, message);
}
static int exynos_drm_runtime_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
if (!pm_runtime_suspended(dev))
return 0;
return exynos_drm_resume(drm_dev);
}
static int __init exynos_drm_init(void)
{
int ret;
#ifdef CONFIG_DRM_EXYNOS_DP
ret = platform_driver_register(&dp_driver);
if (ret < 0)
goto out_dp;
#endif
#ifdef CONFIG_DRM_EXYNOS_DSI
ret = platform_driver_register(&dsi_driver);
if (ret < 0)
goto out_dsi;
#endif
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
#endif
#ifdef CONFIG_DRM_EXYNOS_VIDI
ret = platform_driver_register(&vidi_driver);
if (ret < 0)
goto out_vidi;
#endif
#ifdef CONFIG_DRM_EXYNOS_G2D
ret = platform_driver_register(&g2d_driver);
if (ret < 0)
goto out_g2d;
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMC
ret = platform_driver_register(&fimc_driver);
if (ret < 0)
goto out_fimc;
#endif
#ifdef CONFIG_DRM_EXYNOS_ROTATOR
ret = platform_driver_register(&rotator_driver);
if (ret < 0)
goto out_rotator;
#endif
#ifdef CONFIG_DRM_EXYNOS_GSC
ret = platform_driver_register(&gsc_driver);
if (ret < 0)
goto out_gsc;
#endif
#ifdef CONFIG_DRM_EXYNOS_IPP
ret = platform_driver_register(&ipp_driver);
if (ret < 0)
goto out_ipp;
ret = exynos_platform_device_ipp_register();
if (ret < 0)
goto out_ipp_dev;
#endif
ret = platform_driver_register(&exynos_drm_platform_driver);
if (ret < 0)
goto out_drm;
exynos_drm_pdev = platform_device_register_simple("exynos-drm", -1,
NULL, 0);
if (IS_ERR(exynos_drm_pdev)) {
ret = PTR_ERR(exynos_drm_pdev);
goto out;
}
return 0;
out:
platform_driver_unregister(&exynos_drm_platform_driver);
out_drm:
#ifdef CONFIG_DRM_EXYNOS_IPP
exynos_platform_device_ipp_unregister();
out_ipp_dev:
platform_driver_unregister(&ipp_driver);
out_ipp:
#endif
#ifdef CONFIG_DRM_EXYNOS_GSC
platform_driver_unregister(&gsc_driver);
out_gsc:
#endif
#ifdef CONFIG_DRM_EXYNOS_ROTATOR
platform_driver_unregister(&rotator_driver);
out_rotator:
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMC
platform_driver_unregister(&fimc_driver);
out_fimc:
#endif
#ifdef CONFIG_DRM_EXYNOS_G2D
platform_driver_unregister(&g2d_driver);
out_g2d:
#endif
#ifdef CONFIG_DRM_EXYNOS_VIDI
platform_driver_unregister(&vidi_driver);
out_vidi:
#endif
#ifdef CONFIG_DRM_EXYNOS_HDMI
platform_driver_unregister(&mixer_driver);
out_mixer:
platform_driver_unregister(&hdmi_driver);
out_hdmi:
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMD
platform_driver_unregister(&fimd_driver);
out_fimd:
#endif
#ifdef CONFIG_DRM_EXYNOS_DSI
platform_driver_unregister(&dsi_driver);
out_dsi:
#endif
#ifdef CONFIG_DRM_EXYNOS_DP
platform_driver_unregister(&dp_driver);
out_dp:
#endif
return ret;
}
static void __exit exynos_drm_exit(void)
{
platform_device_unregister(exynos_drm_pdev);
platform_driver_unregister(&exynos_drm_platform_driver);
#ifdef CONFIG_DRM_EXYNOS_IPP
exynos_platform_device_ipp_unregister();
platform_driver_unregister(&ipp_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_GSC
platform_driver_unregister(&gsc_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_ROTATOR
platform_driver_unregister(&rotator_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMC
platform_driver_unregister(&fimc_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_G2D
platform_driver_unregister(&g2d_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_HDMI
platform_driver_unregister(&mixer_driver);
platform_driver_unregister(&hdmi_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_VIDI
platform_driver_unregister(&vidi_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMD
platform_driver_unregister(&fimd_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_DSI
platform_driver_unregister(&dsi_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_DP
platform_driver_unregister(&dp_driver);
#endif
}
