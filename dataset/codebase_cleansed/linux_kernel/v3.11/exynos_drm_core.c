static int exynos_drm_create_enc_conn(struct drm_device *dev,
struct exynos_drm_subdrv *subdrv)
{
struct drm_encoder *encoder;
struct drm_connector *connector;
int ret;
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
ret = -EFAULT;
goto err_destroy_encoder;
}
subdrv->encoder = encoder;
subdrv->connector = connector;
return 0;
err_destroy_encoder:
encoder->funcs->destroy(encoder);
return ret;
}
static void exynos_drm_destroy_enc_conn(struct exynos_drm_subdrv *subdrv)
{
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
static int exynos_drm_subdrv_probe(struct drm_device *dev,
struct exynos_drm_subdrv *subdrv)
{
if (subdrv->probe) {
int ret;
subdrv->drm_dev = dev;
ret = subdrv->probe(dev, subdrv->dev);
if (ret)
return ret;
}
return 0;
}
static void exynos_drm_subdrv_remove(struct drm_device *dev,
struct exynos_drm_subdrv *subdrv)
{
if (subdrv->remove)
subdrv->remove(dev, subdrv->dev);
}
int exynos_drm_device_register(struct drm_device *dev)
{
struct exynos_drm_subdrv *subdrv, *n;
unsigned int fine_cnt = 0;
int err;
if (!dev)
return -EINVAL;
list_for_each_entry_safe(subdrv, n, &exynos_drm_subdrv_list, list) {
err = exynos_drm_subdrv_probe(dev, subdrv);
if (err) {
DRM_DEBUG("exynos drm subdrv probe failed.\n");
list_del(&subdrv->list);
continue;
}
if (!subdrv->manager) {
fine_cnt++;
continue;
}
err = exynos_drm_create_enc_conn(dev, subdrv);
if (err) {
DRM_DEBUG("failed to create encoder and connector.\n");
exynos_drm_subdrv_remove(dev, subdrv);
list_del(&subdrv->list);
continue;
}
fine_cnt++;
}
if (!fine_cnt)
return -EINVAL;
return 0;
}
int exynos_drm_device_unregister(struct drm_device *dev)
{
struct exynos_drm_subdrv *subdrv;
if (!dev) {
WARN(1, "Unexpected drm device unregister!\n");
return -EINVAL;
}
list_for_each_entry(subdrv, &exynos_drm_subdrv_list, list) {
exynos_drm_subdrv_remove(dev, subdrv);
exynos_drm_destroy_enc_conn(subdrv);
}
return 0;
}
int exynos_drm_subdrv_register(struct exynos_drm_subdrv *subdrv)
{
if (!subdrv)
return -EINVAL;
list_add_tail(&subdrv->list, &exynos_drm_subdrv_list);
return 0;
}
int exynos_drm_subdrv_unregister(struct exynos_drm_subdrv *subdrv)
{
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
