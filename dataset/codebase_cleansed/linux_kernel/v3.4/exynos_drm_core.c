static int exynos_drm_subdrv_probe(struct drm_device *dev,
struct exynos_drm_subdrv *subdrv)
{
struct drm_encoder *encoder;
struct drm_connector *connector;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (subdrv->probe) {
int ret;
ret = subdrv->probe(dev, subdrv->dev);
if (ret)
return ret;
}
if (!subdrv->manager)
return 0;
subdrv->manager->dev = subdrv->dev;
encoder = exynos_drm_encoder_create(dev, subdrv->manager,
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
drm_dev = dev;
list_for_each_entry_safe(subdrv, n, &exynos_drm_subdrv_list, list) {
subdrv->drm_dev = dev;
err = exynos_drm_subdrv_probe(dev, subdrv);
if (err) {
DRM_DEBUG("exynos drm subdrv probe failed.\n");
list_del(&subdrv->list);
}
}
return 0;
}
int exynos_drm_device_unregister(struct drm_device *dev)
{
struct exynos_drm_subdrv *subdrv;
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (!dev) {
WARN(1, "Unexpected drm device unregister!\n");
return -EINVAL;
}
list_for_each_entry(subdrv, &exynos_drm_subdrv_list, list)
exynos_drm_subdrv_remove(dev, subdrv);
drm_dev = NULL;
return 0;
}
int exynos_drm_subdrv_register(struct exynos_drm_subdrv *subdrv)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (!subdrv)
return -EINVAL;
list_add_tail(&subdrv->list, &exynos_drm_subdrv_list);
return 0;
}
int exynos_drm_subdrv_unregister(struct exynos_drm_subdrv *subdrv)
{
DRM_DEBUG_DRIVER("%s\n", __FILE__);
if (!subdrv)
return -EINVAL;
list_del(&subdrv->list);
return 0;
}
int exynos_drm_subdrv_open(struct drm_device *dev, struct drm_file *file)
{
struct exynos_drm_subdrv *subdrv;
int ret;
list_for_each_entry(subdrv, &exynos_drm_subdrv_list, list) {
if (subdrv->open) {
ret = subdrv->open(dev, subdrv->dev, file);
if (ret)
goto err;
}
}
return 0;
err:
list_for_each_entry_reverse(subdrv, &subdrv->list, list) {
if (subdrv->close)
subdrv->close(dev, subdrv->dev, file);
}
return ret;
}
void exynos_drm_subdrv_close(struct drm_device *dev, struct drm_file *file)
{
struct exynos_drm_subdrv *subdrv;
list_for_each_entry(subdrv, &exynos_drm_subdrv_list, list) {
if (subdrv->close)
subdrv->close(dev, subdrv->dev, file);
}
}
