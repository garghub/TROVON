int exynos_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
int ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
ret = drm_atomic_normalize_zpos(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
return ret;
}
static int exynos_drm_open(struct drm_device *dev, struct drm_file *file)
{
struct drm_exynos_file_private *file_priv;
int ret;
file_priv = kzalloc(sizeof(*file_priv), GFP_KERNEL);
if (!file_priv)
return -ENOMEM;
file->driver_priv = file_priv;
ret = exynos_drm_subdrv_open(dev, file);
if (ret)
goto err_file_priv_free;
return ret;
err_file_priv_free:
kfree(file_priv);
file->driver_priv = NULL;
return ret;
}
static void exynos_drm_postclose(struct drm_device *dev, struct drm_file *file)
{
exynos_drm_subdrv_close(dev, file);
kfree(file->driver_priv);
file->driver_priv = NULL;
}
static void exynos_drm_lastclose(struct drm_device *dev)
{
exynos_drm_fbdev_restore_mode(dev);
}
static int exynos_drm_suspend(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
struct drm_connector *connector;
if (pm_runtime_suspended(dev) || !drm_dev)
return 0;
drm_modeset_lock_all(drm_dev);
drm_for_each_connector(connector, drm_dev) {
int old_dpms = connector->dpms;
if (connector->funcs->dpms)
connector->funcs->dpms(connector, DRM_MODE_DPMS_OFF);
connector->dpms = old_dpms;
}
drm_modeset_unlock_all(drm_dev);
return 0;
}
static int exynos_drm_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
struct drm_connector *connector;
if (pm_runtime_suspended(dev) || !drm_dev)
return 0;
drm_modeset_lock_all(drm_dev);
drm_for_each_connector(connector, drm_dev) {
if (connector->funcs->dpms) {
int dpms = connector->dpms;
connector->dpms = DRM_MODE_DPMS_OFF;
connector->funcs->dpms(connector, dpms);
}
}
drm_modeset_unlock_all(drm_dev);
return 0;
}
static int compare_dev(struct device *dev, void *data)
{
return dev == (struct device *)data;
}
static struct component_match *exynos_drm_match_add(struct device *dev)
{
struct component_match *match = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(exynos_drm_drivers); ++i) {
struct exynos_drm_driver_info *info = &exynos_drm_drivers[i];
struct device *p = NULL, *d;
if (!info->driver || !(info->flags & DRM_COMPONENT_DRIVER))
continue;
while ((d = bus_find_device(&platform_bus_type, p,
&info->driver->driver,
(void *)platform_bus_type.match))) {
put_device(p);
component_match_add(dev, &match, compare_dev, d);
p = d;
}
put_device(p);
}
return match ?: ERR_PTR(-ENODEV);
}
static int exynos_drm_bind(struct device *dev)
{
struct exynos_drm_private *private;
struct drm_encoder *encoder;
struct drm_device *drm;
unsigned int clone_mask;
int cnt, ret;
drm = drm_dev_alloc(&exynos_drm_driver, dev);
if (IS_ERR(drm))
return PTR_ERR(drm);
private = kzalloc(sizeof(struct exynos_drm_private), GFP_KERNEL);
if (!private) {
ret = -ENOMEM;
goto err_free_drm;
}
init_waitqueue_head(&private->wait);
spin_lock_init(&private->lock);
dev_set_drvdata(dev, drm);
drm->dev_private = (void *)private;
private->dma_dev = exynos_drm_get_dma_device();
if (!private->dma_dev) {
DRM_ERROR("no device found for DMA mapping operations.\n");
ret = -ENODEV;
goto err_free_private;
}
DRM_INFO("Exynos DRM: using %s device for DMA mapping operations\n",
dev_name(private->dma_dev));
ret = drm_create_iommu_mapping(drm);
if (ret < 0) {
DRM_ERROR("failed to create iommu mapping.\n");
goto err_free_private;
}
drm_mode_config_init(drm);
exynos_drm_mode_config_init(drm);
cnt = 0;
clone_mask = 0;
list_for_each_entry(encoder, &drm->mode_config.encoder_list, head)
clone_mask |= (1 << (cnt++));
list_for_each_entry(encoder, &drm->mode_config.encoder_list, head)
encoder->possible_clones = clone_mask;
ret = component_bind_all(drm->dev, drm);
if (ret)
goto err_mode_config_cleanup;
ret = drm_vblank_init(drm, drm->mode_config.num_crtc);
if (ret)
goto err_unbind_all;
ret = exynos_drm_device_subdrv_probe(drm);
if (ret)
goto err_cleanup_vblank;
drm_mode_config_reset(drm);
drm->irq_enabled = true;
drm_kms_helper_poll_init(drm);
drm_helper_hpd_irq_event(drm);
ret = drm_dev_register(drm, 0);
if (ret < 0)
goto err_cleanup_fbdev;
return 0;
err_cleanup_fbdev:
exynos_drm_fbdev_fini(drm);
drm_kms_helper_poll_fini(drm);
exynos_drm_device_subdrv_remove(drm);
err_cleanup_vblank:
drm_vblank_cleanup(drm);
err_unbind_all:
component_unbind_all(drm->dev, drm);
err_mode_config_cleanup:
drm_mode_config_cleanup(drm);
drm_release_iommu_mapping(drm);
err_free_private:
kfree(private);
err_free_drm:
drm_dev_unref(drm);
return ret;
}
static void exynos_drm_unbind(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
drm_dev_unregister(drm);
exynos_drm_device_subdrv_remove(drm);
exynos_drm_fbdev_fini(drm);
drm_kms_helper_poll_fini(drm);
component_unbind_all(drm->dev, drm);
drm_mode_config_cleanup(drm);
drm_release_iommu_mapping(drm);
kfree(drm->dev_private);
drm->dev_private = NULL;
drm_dev_unref(drm);
}
static int exynos_drm_platform_probe(struct platform_device *pdev)
{
struct component_match *match;
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
exynos_drm_driver.num_ioctls = ARRAY_SIZE(exynos_ioctls);
match = exynos_drm_match_add(&pdev->dev);
if (IS_ERR(match))
return PTR_ERR(match);
return component_master_add_with_match(&pdev->dev, &exynos_drm_ops,
match);
}
static int exynos_drm_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &exynos_drm_ops);
return 0;
}
static struct device *exynos_drm_get_dma_device(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(exynos_drm_drivers); ++i) {
struct exynos_drm_driver_info *info = &exynos_drm_drivers[i];
struct device *dev;
if (!info->driver || !(info->flags & DRM_DMA_DEVICE))
continue;
while ((dev = bus_find_device(&platform_bus_type, NULL,
&info->driver->driver,
(void *)platform_bus_type.match))) {
put_device(dev);
return dev;
}
}
return NULL;
}
static void exynos_drm_unregister_devices(void)
{
int i;
for (i = ARRAY_SIZE(exynos_drm_drivers) - 1; i >= 0; --i) {
struct exynos_drm_driver_info *info = &exynos_drm_drivers[i];
struct device *dev;
if (!info->driver || !(info->flags & DRM_VIRTUAL_DEVICE))
continue;
while ((dev = bus_find_device(&platform_bus_type, NULL,
&info->driver->driver,
(void *)platform_bus_type.match))) {
put_device(dev);
platform_device_unregister(to_platform_device(dev));
}
}
}
static int exynos_drm_register_devices(void)
{
struct platform_device *pdev;
int i;
for (i = 0; i < ARRAY_SIZE(exynos_drm_drivers); ++i) {
struct exynos_drm_driver_info *info = &exynos_drm_drivers[i];
if (!info->driver || !(info->flags & DRM_VIRTUAL_DEVICE))
continue;
pdev = platform_device_register_simple(
info->driver->driver.name, -1, NULL, 0);
if (IS_ERR(pdev))
goto fail;
}
return 0;
fail:
exynos_drm_unregister_devices();
return PTR_ERR(pdev);
}
static void exynos_drm_unregister_drivers(void)
{
int i;
for (i = ARRAY_SIZE(exynos_drm_drivers) - 1; i >= 0; --i) {
struct exynos_drm_driver_info *info = &exynos_drm_drivers[i];
if (!info->driver)
continue;
platform_driver_unregister(info->driver);
}
}
static int exynos_drm_register_drivers(void)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(exynos_drm_drivers); ++i) {
struct exynos_drm_driver_info *info = &exynos_drm_drivers[i];
if (!info->driver)
continue;
ret = platform_driver_register(info->driver);
if (ret)
goto fail;
}
return 0;
fail:
exynos_drm_unregister_drivers();
return ret;
}
static int exynos_drm_init(void)
{
int ret;
ret = exynos_drm_register_devices();
if (ret)
return ret;
ret = exynos_drm_register_drivers();
if (ret)
goto err_unregister_pdevs;
return 0;
err_unregister_pdevs:
exynos_drm_unregister_devices();
return ret;
}
static void exynos_drm_exit(void)
{
exynos_drm_unregister_drivers();
exynos_drm_unregister_devices();
}
