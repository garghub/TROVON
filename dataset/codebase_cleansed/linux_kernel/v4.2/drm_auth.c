int drm_getmagic(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
struct drm_auth *auth = data;
int ret = 0;
mutex_lock(&dev->struct_mutex);
if (!file_priv->magic) {
ret = idr_alloc(&file_priv->master->magic_map, file_priv,
1, 0, GFP_KERNEL);
if (ret >= 0)
file_priv->magic = ret;
}
auth->magic = file_priv->magic;
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG("%u\n", auth->magic);
return ret < 0 ? ret : 0;
}
int drm_authmagic(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_auth *auth = data;
struct drm_file *file;
DRM_DEBUG("%u\n", auth->magic);
mutex_lock(&dev->struct_mutex);
file = idr_find(&file_priv->master->magic_map, auth->magic);
if (file) {
file->authenticated = 1;
idr_replace(&file_priv->master->magic_map, NULL, auth->magic);
}
mutex_unlock(&dev->struct_mutex);
return file ? 0 : -EINVAL;
}
