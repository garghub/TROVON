int drm_getmagic(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
struct drm_auth *auth = data;
int ret = 0;
mutex_lock(&dev->master_mutex);
if (!file_priv->magic) {
ret = idr_alloc(&file_priv->master->magic_map, file_priv,
1, 0, GFP_KERNEL);
if (ret >= 0)
file_priv->magic = ret;
}
auth->magic = file_priv->magic;
mutex_unlock(&dev->master_mutex);
DRM_DEBUG("%u\n", auth->magic);
return ret < 0 ? ret : 0;
}
int drm_authmagic(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_auth *auth = data;
struct drm_file *file;
DRM_DEBUG("%u\n", auth->magic);
mutex_lock(&dev->master_mutex);
file = idr_find(&file_priv->master->magic_map, auth->magic);
if (file) {
file->authenticated = 1;
idr_replace(&file_priv->master->magic_map, NULL, auth->magic);
}
mutex_unlock(&dev->master_mutex);
return file ? 0 : -EINVAL;
}
static struct drm_master *drm_master_create(struct drm_device *dev)
{
struct drm_master *master;
master = kzalloc(sizeof(*master), GFP_KERNEL);
if (!master)
return NULL;
kref_init(&master->refcount);
spin_lock_init(&master->lock.spinlock);
init_waitqueue_head(&master->lock.lock_queue);
idr_init(&master->magic_map);
master->dev = dev;
return master;
}
static int drm_set_master(struct drm_device *dev, struct drm_file *fpriv,
bool new_master)
{
int ret = 0;
dev->master = drm_master_get(fpriv->master);
if (dev->driver->master_set) {
ret = dev->driver->master_set(dev, fpriv, new_master);
if (unlikely(ret != 0)) {
drm_master_put(&dev->master);
}
}
return ret;
}
static int drm_new_set_master(struct drm_device *dev, struct drm_file *fpriv)
{
struct drm_master *old_master;
int ret;
lockdep_assert_held_once(&dev->master_mutex);
old_master = fpriv->master;
fpriv->master = drm_master_create(dev);
if (!fpriv->master) {
fpriv->master = old_master;
return -ENOMEM;
}
if (dev->driver->master_create) {
ret = dev->driver->master_create(dev, fpriv->master);
if (ret)
goto out_err;
}
fpriv->is_master = 1;
fpriv->authenticated = 1;
ret = drm_set_master(dev, fpriv, true);
if (ret)
goto out_err;
if (old_master)
drm_master_put(&old_master);
return 0;
out_err:
drm_master_put(&fpriv->master);
fpriv->master = old_master;
return ret;
}
int drm_setmaster_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret = 0;
mutex_lock(&dev->master_mutex);
if (drm_is_current_master(file_priv))
goto out_unlock;
if (dev->master) {
ret = -EINVAL;
goto out_unlock;
}
if (!file_priv->master) {
ret = -EINVAL;
goto out_unlock;
}
if (!file_priv->is_master) {
ret = drm_new_set_master(dev, file_priv);
goto out_unlock;
}
ret = drm_set_master(dev, file_priv, false);
out_unlock:
mutex_unlock(&dev->master_mutex);
return ret;
}
static void drm_drop_master(struct drm_device *dev,
struct drm_file *fpriv)
{
if (dev->driver->master_drop)
dev->driver->master_drop(dev, fpriv);
drm_master_put(&dev->master);
}
int drm_dropmaster_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret = -EINVAL;
mutex_lock(&dev->master_mutex);
if (!drm_is_current_master(file_priv))
goto out_unlock;
if (!dev->master)
goto out_unlock;
ret = 0;
drm_drop_master(dev, file_priv);
out_unlock:
mutex_unlock(&dev->master_mutex);
return ret;
}
int drm_master_open(struct drm_file *file_priv)
{
struct drm_device *dev = file_priv->minor->dev;
int ret = 0;
mutex_lock(&dev->master_mutex);
if (!dev->master)
ret = drm_new_set_master(dev, file_priv);
else
file_priv->master = drm_master_get(dev->master);
mutex_unlock(&dev->master_mutex);
return ret;
}
void drm_master_release(struct drm_file *file_priv)
{
struct drm_device *dev = file_priv->minor->dev;
struct drm_master *master = file_priv->master;
mutex_lock(&dev->master_mutex);
if (file_priv->magic)
idr_remove(&file_priv->master->magic_map, file_priv->magic);
if (!drm_is_current_master(file_priv))
goto out;
if (!drm_core_check_feature(dev, DRIVER_MODESET)) {
mutex_lock(&dev->struct_mutex);
if (master->lock.hw_lock) {
if (dev->sigdata.lock == master->lock.hw_lock)
dev->sigdata.lock = NULL;
master->lock.hw_lock = NULL;
master->lock.file_priv = NULL;
wake_up_interruptible_all(&master->lock.lock_queue);
}
mutex_unlock(&dev->struct_mutex);
}
if (dev->master == file_priv->master)
drm_drop_master(dev, file_priv);
out:
if (file_priv->master)
drm_master_put(&file_priv->master);
mutex_unlock(&dev->master_mutex);
}
bool drm_is_current_master(struct drm_file *fpriv)
{
return fpriv->is_master && fpriv->master == fpriv->minor->dev->master;
}
struct drm_master *drm_master_get(struct drm_master *master)
{
kref_get(&master->refcount);
return master;
}
static void drm_master_destroy(struct kref *kref)
{
struct drm_master *master = container_of(kref, struct drm_master, refcount);
struct drm_device *dev = master->dev;
if (dev->driver->master_destroy)
dev->driver->master_destroy(dev, master);
drm_legacy_master_rmmaps(dev, master);
idr_destroy(&master->magic_map);
kfree(master->unique);
kfree(master);
}
void drm_master_put(struct drm_master **master)
{
kref_put(&(*master)->refcount, drm_master_destroy);
*master = NULL;
}
