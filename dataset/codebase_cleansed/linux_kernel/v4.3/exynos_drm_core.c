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
int exynos_drm_device_subdrv_probe(struct drm_device *dev)
{
struct exynos_drm_subdrv *subdrv, *n;
int err;
if (!dev)
return -EINVAL;
list_for_each_entry_safe(subdrv, n, &exynos_drm_subdrv_list, list) {
if (subdrv->probe) {
subdrv->drm_dev = dev;
err = subdrv->probe(dev, subdrv->dev);
if (err) {
DRM_DEBUG("exynos drm subdrv probe failed.\n");
list_del(&subdrv->list);
continue;
}
}
}
return 0;
}
int exynos_drm_device_subdrv_remove(struct drm_device *dev)
{
struct exynos_drm_subdrv *subdrv;
if (!dev) {
WARN(1, "Unexpected drm device unregister!\n");
return -EINVAL;
}
list_for_each_entry(subdrv, &exynos_drm_subdrv_list, list) {
if (subdrv->remove)
subdrv->remove(dev, subdrv->dev);
}
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
