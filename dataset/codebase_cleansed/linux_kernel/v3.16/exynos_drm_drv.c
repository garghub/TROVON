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
for (nr = 0; nr < MAX_PLANE; nr++) {
struct drm_plane *plane;
unsigned long possible_crtcs = (1 << MAX_CRTC) - 1;
plane = exynos_plane_init(dev, possible_crtcs, false);
if (!plane)
goto err_mode_config_cleanup;
}
drm_kms_helper_poll_init(dev);
ret = drm_vblank_init(dev, MAX_CRTC);
if (ret)
goto err_mode_config_cleanup;
exynos_drm_encoder_setup(dev);
drm_vblank_offdelay = VBLANK_OFF_DELAY;
platform_set_drvdata(dev->platformdev, dev);
ret = component_bind_all(dev->dev, dev);
if (ret)
goto err_cleanup_vblank;
ret = exynos_drm_device_subdrv_probe(dev);
if (ret)
goto err_unbind_all;
drm_helper_hpd_irq_event(dev);
return 0;
err_unbind_all:
component_unbind_all(dev->dev, dev);
err_cleanup_vblank:
drm_vblank_cleanup(dev);
err_mode_config_cleanup:
drm_mode_config_cleanup(dev);
drm_release_iommu_mapping(dev);
err_free_private:
kfree(private);
return ret;
}
static int exynos_drm_unload(struct drm_device *dev)
{
exynos_drm_device_subdrv_remove(dev);
exynos_drm_fbdev_fini(dev);
drm_vblank_cleanup(dev);
drm_kms_helper_poll_fini(dev);
drm_mode_config_cleanup(dev);
drm_release_iommu_mapping(dev);
kfree(dev->dev_private);
component_unbind_all(dev->dev, dev);
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
drm_modeset_unlock_all(dev);
drm_helper_resume_force_mode(dev);
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
int exynos_drm_component_add(struct device *dev,
enum exynos_drm_device_type dev_type,
enum exynos_drm_output_type out_type)
{
struct component_dev *cdev;
if (dev_type != EXYNOS_DEVICE_TYPE_CRTC &&
dev_type != EXYNOS_DEVICE_TYPE_CONNECTOR) {
DRM_ERROR("invalid device type.\n");
return -EINVAL;
}
mutex_lock(&drm_component_lock);
list_for_each_entry(cdev, &drm_component_list, list) {
if (cdev->out_type == out_type) {
if (cdev->dev_type_flag == (EXYNOS_DEVICE_TYPE_CRTC |
EXYNOS_DEVICE_TYPE_CONNECTOR)) {
mutex_unlock(&drm_component_lock);
return 0;
}
if (dev_type == EXYNOS_DEVICE_TYPE_CRTC) {
cdev->crtc_dev = dev;
cdev->dev_type_flag |= dev_type;
}
if (dev_type == EXYNOS_DEVICE_TYPE_CONNECTOR) {
cdev->conn_dev = dev;
cdev->dev_type_flag |= dev_type;
}
mutex_unlock(&drm_component_lock);
return 0;
}
}
mutex_unlock(&drm_component_lock);
cdev = kzalloc(sizeof(*cdev), GFP_KERNEL);
if (!cdev)
return -ENOMEM;
if (dev_type == EXYNOS_DEVICE_TYPE_CRTC)
cdev->crtc_dev = dev;
if (dev_type == EXYNOS_DEVICE_TYPE_CONNECTOR)
cdev->conn_dev = dev;
cdev->out_type = out_type;
cdev->dev_type_flag = dev_type;
mutex_lock(&drm_component_lock);
list_add_tail(&cdev->list, &drm_component_list);
mutex_unlock(&drm_component_lock);
return 0;
}
void exynos_drm_component_del(struct device *dev,
enum exynos_drm_device_type dev_type)
{
struct component_dev *cdev, *next;
mutex_lock(&drm_component_lock);
list_for_each_entry_safe(cdev, next, &drm_component_list, list) {
if (dev_type == EXYNOS_DEVICE_TYPE_CRTC) {
if (cdev->crtc_dev == dev) {
cdev->crtc_dev = NULL;
cdev->dev_type_flag &= ~dev_type;
}
}
if (dev_type == EXYNOS_DEVICE_TYPE_CONNECTOR) {
if (cdev->conn_dev == dev) {
cdev->conn_dev = NULL;
cdev->dev_type_flag &= ~dev_type;
}
}
if (!cdev->crtc_dev && !cdev->conn_dev) {
list_del(&cdev->list);
kfree(cdev);
}
break;
}
mutex_unlock(&drm_component_lock);
}
static int compare_of(struct device *dev, void *data)
{
return dev == (struct device *)data;
}
static int exynos_drm_add_components(struct device *dev, struct master *m)
{
struct component_dev *cdev;
unsigned int attach_cnt = 0;
mutex_lock(&drm_component_lock);
list_for_each_entry(cdev, &drm_component_list, list) {
int ret;
if (!cdev->crtc_dev || !cdev->conn_dev)
continue;
attach_cnt++;
mutex_unlock(&drm_component_lock);
if (cdev->crtc_dev == cdev->conn_dev) {
ret = component_master_add_child(m, compare_of,
cdev->crtc_dev);
if (ret < 0)
return ret;
goto out_lock;
}
ret = component_master_add_child(m, compare_of, cdev->crtc_dev);
ret |= component_master_add_child(m, compare_of,
cdev->conn_dev);
if (ret < 0)
return ret;
out_lock:
mutex_lock(&drm_component_lock);
}
mutex_unlock(&drm_component_lock);
return attach_cnt ? 0 : -ENODEV;
}
static int exynos_drm_bind(struct device *dev)
{
return drm_platform_init(&exynos_drm_driver, to_platform_device(dev));
}
static void exynos_drm_unbind(struct device *dev)
{
drm_put_dev(dev_get_drvdata(dev));
}
static int exynos_drm_platform_probe(struct platform_device *pdev)
{
int ret;
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
exynos_drm_driver.num_ioctls = ARRAY_SIZE(exynos_ioctls);
#ifdef CONFIG_DRM_EXYNOS_FIMD
ret = platform_driver_register(&fimd_driver);
if (ret < 0)
return ret;
#endif
#ifdef CONFIG_DRM_EXYNOS_DP
ret = platform_driver_register(&dp_driver);
if (ret < 0)
goto err_unregister_fimd_drv;
#endif
#ifdef CONFIG_DRM_EXYNOS_DSI
ret = platform_driver_register(&dsi_driver);
if (ret < 0)
goto err_unregister_dp_drv;
#endif
#ifdef CONFIG_DRM_EXYNOS_HDMI
ret = platform_driver_register(&mixer_driver);
if (ret < 0)
goto err_unregister_dsi_drv;
ret = platform_driver_register(&hdmi_driver);
if (ret < 0)
goto err_unregister_mixer_drv;
#endif
#ifdef CONFIG_DRM_EXYNOS_G2D
ret = platform_driver_register(&g2d_driver);
if (ret < 0)
goto err_unregister_hdmi_drv;
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMC
ret = platform_driver_register(&fimc_driver);
if (ret < 0)
goto err_unregister_g2d_drv;
#endif
#ifdef CONFIG_DRM_EXYNOS_ROTATOR
ret = platform_driver_register(&rotator_driver);
if (ret < 0)
goto err_unregister_fimc_drv;
#endif
#ifdef CONFIG_DRM_EXYNOS_GSC
ret = platform_driver_register(&gsc_driver);
if (ret < 0)
goto err_unregister_rotator_drv;
#endif
#ifdef CONFIG_DRM_EXYNOS_IPP
ret = platform_driver_register(&ipp_driver);
if (ret < 0)
goto err_unregister_gsc_drv;
ret = exynos_platform_device_ipp_register();
if (ret < 0)
goto err_unregister_ipp_drv;
#endif
ret = component_master_add(&pdev->dev, &exynos_drm_ops);
if (ret < 0)
DRM_DEBUG_KMS("re-tried by last sub driver probed later.\n");
return 0;
#ifdef CONFIG_DRM_EXYNOS_IPP
err_unregister_ipp_drv:
platform_driver_unregister(&ipp_driver);
err_unregister_gsc_drv:
#endif
#ifdef CONFIG_DRM_EXYNOS_GSC
platform_driver_unregister(&gsc_driver);
err_unregister_rotator_drv:
#endif
#ifdef CONFIG_DRM_EXYNOS_ROTATOR
platform_driver_unregister(&rotator_driver);
err_unregister_fimc_drv:
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMC
platform_driver_unregister(&fimc_driver);
err_unregister_g2d_drv:
#endif
#ifdef CONFIG_DRM_EXYNOS_G2D
platform_driver_unregister(&g2d_driver);
err_unregister_hdmi_drv:
#endif
#ifdef CONFIG_DRM_EXYNOS_HDMI
platform_driver_unregister(&hdmi_driver);
err_unregister_mixer_drv:
platform_driver_unregister(&mixer_driver);
err_unregister_dsi_drv:
#endif
#ifdef CONFIG_DRM_EXYNOS_DSI
platform_driver_unregister(&dsi_driver);
err_unregister_dp_drv:
#endif
#ifdef CONFIG_DRM_EXYNOS_DP
platform_driver_unregister(&dp_driver);
err_unregister_fimd_drv:
#endif
#ifdef CONFIG_DRM_EXYNOS_FIMD
platform_driver_unregister(&fimd_driver);
#endif
return ret;
}
static int exynos_drm_platform_remove(struct platform_device *pdev)
{
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
#ifdef CONFIG_DRM_EXYNOS_FIMD
platform_driver_unregister(&fimd_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_DSI
platform_driver_unregister(&dsi_driver);
#endif
#ifdef CONFIG_DRM_EXYNOS_DP
platform_driver_unregister(&dp_driver);
#endif
component_master_del(&pdev->dev, &exynos_drm_ops);
return 0;
}
static int exynos_drm_init(void)
{
int ret;
exynos_drm_pdev = platform_device_register_simple("exynos-drm", -1,
NULL, 0);
if (IS_ERR(exynos_drm_pdev))
return PTR_ERR(exynos_drm_pdev);
#ifdef CONFIG_DRM_EXYNOS_VIDI
ret = exynos_drm_probe_vidi();
if (ret < 0)
goto err_unregister_pd;
#endif
ret = platform_driver_register(&exynos_drm_platform_driver);
if (ret)
goto err_remove_vidi;
return 0;
err_remove_vidi:
#ifdef CONFIG_DRM_EXYNOS_VIDI
exynos_drm_remove_vidi();
err_unregister_pd:
#endif
platform_device_unregister(exynos_drm_pdev);
return ret;
}
static void exynos_drm_exit(void)
{
platform_driver_unregister(&exynos_drm_platform_driver);
#ifdef CONFIG_DRM_EXYNOS_VIDI
exynos_drm_remove_vidi();
#endif
platform_device_unregister(exynos_drm_pdev);
}
