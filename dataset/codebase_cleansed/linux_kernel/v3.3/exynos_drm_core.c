static int exynos_drm_subdrv_probe(struct drm_device *dev,
struct exynos_drm_subdrv *subdrv)
{
struct drm_encoder *encoder;
struct drm_connector *connector;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (subdrv->probe) {
int ret;
ret = subdrv->probe(dev, subdrv->manager.dev);
if (ret)
return ret;
}
encoder = exynos_drm_encoder_create(dev, &subdrv->manager,
(1 << MAX_CRTC) - 1);
if (!encoder) {
DRM_ERROR("failed to create encoder\n");
return -EFAULT;
}
connector = exynos_drm_connector_create(dev, encoder);
if (!connector) {
DRM_ERROR("failed to create connector\n");
encoder->funcs->destroy(encoder);
return -EFAULT;
}
subdrv->encoder = encoder;
subdrv->connector = connector;
return 0;
}
static void exynos_drm_subdrv_remove(struct drm_device *dev,
struct exynos_drm_subdrv *subdrv)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (subdrv->remove)
subdrv->remove(dev);
if (subdrv->encoder) {
struct drm_encoder *encoder = subdrv->encoder;
encoder->funcs->destroy(encoder);
subdrv->encoder = NULL;
}
if (subdrv->connector) {
struct drm_connector *connector = subdrv->connector;
connector->funcs->destroy(connector);
subdrv->connector = NULL;
}
}
int exynos_drm_device_register(struct drm_device *dev)
{
struct exynos_drm_subdrv *subdrv, *n;
int err;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (!dev)
return -EINVAL;
if (drm_dev) {
DRM_ERROR("Already drm device were registered\n");
return -EBUSY;
}
mutex_lock(&exynos_drm_mutex);
list_for_each_entry_safe(subdrv, n, &exynos_drm_subdrv_list, list) {
err = exynos_drm_subdrv_probe(dev, subdrv);
if (err) {
DRM_DEBUG("exynos drm subdrv probe failed.\n");
list_del(&subdrv->list);
}
}
drm_dev = dev;
mutex_unlock(&exynos_drm_mutex);
return 0;
}
int exynos_drm_device_unregister(struct drm_device *dev)
{
struct exynos_drm_subdrv *subdrv;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (!dev || dev != drm_dev) {
WARN(1, "Unexpected drm device unregister!\n");
return -EINVAL;
}
mutex_lock(&exynos_drm_mutex);
list_for_each_entry(subdrv, &exynos_drm_subdrv_list, list)
exynos_drm_subdrv_remove(dev, subdrv);
drm_dev = NULL;
mutex_unlock(&exynos_drm_mutex);
return 0;
}
static int exynos_drm_mode_group_reinit(struct drm_device *dev)
{
struct drm_mode_group *group = &dev->primary->mode_group;
uint32_t *id_list = group->id_list;
int ret;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
ret = drm_mode_group_init_legacy_group(dev, group);
if (ret < 0)
return ret;
kfree(id_list);
return 0;
}
int exynos_drm_subdrv_register(struct exynos_drm_subdrv *subdrv)
{
int err;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (!subdrv)
return -EINVAL;
mutex_lock(&exynos_drm_mutex);
if (drm_dev) {
err = exynos_drm_subdrv_probe(drm_dev, subdrv);
if (err) {
DRM_ERROR("failed to probe exynos drm subdrv\n");
mutex_unlock(&exynos_drm_mutex);
return err;
}
exynos_drm_encoder_setup(drm_dev);
err = exynos_drm_fbdev_reinit(drm_dev);
if (err) {
DRM_ERROR("failed to reinitialize exynos drm fbdev\n");
exynos_drm_subdrv_remove(drm_dev, subdrv);
mutex_unlock(&exynos_drm_mutex);
return err;
}
err = exynos_drm_mode_group_reinit(drm_dev);
if (err) {
DRM_ERROR("failed to reinitialize mode group\n");
exynos_drm_fbdev_fini(drm_dev);
exynos_drm_subdrv_remove(drm_dev, subdrv);
mutex_unlock(&exynos_drm_mutex);
return err;
}
}
subdrv->drm_dev = drm_dev;
list_add_tail(&subdrv->list, &exynos_drm_subdrv_list);
mutex_unlock(&exynos_drm_mutex);
return 0;
}
int exynos_drm_subdrv_unregister(struct exynos_drm_subdrv *subdrv)
{
int ret = -EFAULT;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (!subdrv) {
DRM_DEBUG("Unexpected exynos drm subdrv unregister!\n");
return ret;
}
mutex_lock(&exynos_drm_mutex);
if (drm_dev) {
exynos_drm_subdrv_remove(drm_dev, subdrv);
list_del(&subdrv->list);
ret = exynos_drm_fbdev_reinit(drm_dev);
if (ret < 0) {
DRM_ERROR("failed fb helper reinit.\n");
goto fail;
}
ret = exynos_drm_mode_group_reinit(drm_dev);
if (ret < 0) {
DRM_ERROR("failed drm mode group reinit.\n");
goto fail;
}
}
fail:
mutex_unlock(&exynos_drm_mutex);
return ret;
}
