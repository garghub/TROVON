int drm_err(const char *func, const char *format, ...)
{
struct va_format vaf;
va_list args;
int r;
va_start(args, format);
vaf.fmt = format;
vaf.va = &args;
r = printk(KERN_ERR "[" DRM_NAME ":%s] *ERROR* %pV", func, &vaf);
va_end(args);
return r;
}
void drm_ut_debug_printk(unsigned int request_level,
const char *prefix,
const char *function_name,
const char *format, ...)
{
va_list args;
if (drm_debug & request_level) {
if (function_name)
printk(KERN_DEBUG "[%s:%s], ", prefix, function_name);
va_start(args, format);
vprintk(format, args);
va_end(args);
}
}
static int drm_minor_get_id(struct drm_device *dev, int type)
{
int ret;
int base = 0, limit = 63;
if (type == DRM_MINOR_CONTROL) {
base += 64;
limit = base + 63;
} else if (type == DRM_MINOR_RENDER) {
base += 128;
limit = base + 63;
}
mutex_lock(&dev->struct_mutex);
ret = idr_alloc(&drm_minors_idr, NULL, base, limit, GFP_KERNEL);
mutex_unlock(&dev->struct_mutex);
return ret == -ENOSPC ? -EINVAL : ret;
}
struct drm_master *drm_master_create(struct drm_minor *minor)
{
struct drm_master *master;
master = kzalloc(sizeof(*master), GFP_KERNEL);
if (!master)
return NULL;
kref_init(&master->refcount);
spin_lock_init(&master->lock.spinlock);
init_waitqueue_head(&master->lock.lock_queue);
drm_ht_create(&master->magiclist, DRM_MAGIC_HASH_ORDER);
INIT_LIST_HEAD(&master->magicfree);
master->minor = minor;
list_add_tail(&master->head, &minor->master_list);
return master;
}
struct drm_master *drm_master_get(struct drm_master *master)
{
kref_get(&master->refcount);
return master;
}
static void drm_master_destroy(struct kref *kref)
{
struct drm_master *master = container_of(kref, struct drm_master, refcount);
struct drm_magic_entry *pt, *next;
struct drm_device *dev = master->minor->dev;
struct drm_map_list *r_list, *list_temp;
list_del(&master->head);
if (dev->driver->master_destroy)
dev->driver->master_destroy(dev, master);
list_for_each_entry_safe(r_list, list_temp, &dev->maplist, head) {
if (r_list->master == master) {
drm_rmmap_locked(dev, r_list->map);
r_list = NULL;
}
}
if (master->unique) {
kfree(master->unique);
master->unique = NULL;
master->unique_len = 0;
}
kfree(dev->devname);
dev->devname = NULL;
list_for_each_entry_safe(pt, next, &master->magicfree, head) {
list_del(&pt->head);
drm_ht_remove_item(&master->magiclist, &pt->hash_item);
kfree(pt);
}
drm_ht_remove(&master->magiclist);
kfree(master);
}
void drm_master_put(struct drm_master **master)
{
kref_put(&(*master)->refcount, drm_master_destroy);
*master = NULL;
}
int drm_setmaster_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret = 0;
if (file_priv->is_master)
return 0;
if (file_priv->minor->master && file_priv->minor->master != file_priv->master)
return -EINVAL;
if (!file_priv->master)
return -EINVAL;
if (file_priv->minor->master)
return -EINVAL;
mutex_lock(&dev->struct_mutex);
file_priv->minor->master = drm_master_get(file_priv->master);
file_priv->is_master = 1;
if (dev->driver->master_set) {
ret = dev->driver->master_set(dev, file_priv, false);
if (unlikely(ret != 0)) {
file_priv->is_master = 0;
drm_master_put(&file_priv->minor->master);
}
}
mutex_unlock(&dev->struct_mutex);
return ret;
}
int drm_dropmaster_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
if (!file_priv->is_master)
return -EINVAL;
if (!file_priv->minor->master)
return -EINVAL;
mutex_lock(&dev->struct_mutex);
if (dev->driver->master_drop)
dev->driver->master_drop(dev, file_priv, false);
drm_master_put(&file_priv->minor->master);
file_priv->is_master = 0;
mutex_unlock(&dev->struct_mutex);
return 0;
}
static int drm_get_minor(struct drm_device *dev, struct drm_minor **minor,
int type)
{
struct drm_minor *new_minor;
int ret;
int minor_id;
DRM_DEBUG("\n");
minor_id = drm_minor_get_id(dev, type);
if (minor_id < 0)
return minor_id;
new_minor = kzalloc(sizeof(struct drm_minor), GFP_KERNEL);
if (!new_minor) {
ret = -ENOMEM;
goto err_idr;
}
new_minor->type = type;
new_minor->device = MKDEV(DRM_MAJOR, minor_id);
new_minor->dev = dev;
new_minor->index = minor_id;
INIT_LIST_HEAD(&new_minor->master_list);
idr_replace(&drm_minors_idr, new_minor, minor_id);
#if defined(CONFIG_DEBUG_FS)
ret = drm_debugfs_init(new_minor, minor_id, drm_debugfs_root);
if (ret) {
DRM_ERROR("DRM: Failed to initialize /sys/kernel/debug/dri.\n");
goto err_mem;
}
#endif
ret = drm_sysfs_device_add(new_minor);
if (ret) {
printk(KERN_ERR
"DRM: Error sysfs_device_add.\n");
goto err_debugfs;
}
*minor = new_minor;
DRM_DEBUG("new minor assigned %d\n", minor_id);
return 0;
err_debugfs:
#if defined(CONFIG_DEBUG_FS)
drm_debugfs_cleanup(new_minor);
err_mem:
#endif
kfree(new_minor);
err_idr:
idr_remove(&drm_minors_idr, minor_id);
*minor = NULL;
return ret;
}
static void drm_unplug_minor(struct drm_minor *minor)
{
if (!minor || !minor->kdev)
return;
#if defined(CONFIG_DEBUG_FS)
drm_debugfs_cleanup(minor);
#endif
drm_sysfs_device_remove(minor);
idr_remove(&drm_minors_idr, minor->index);
}
static void drm_put_minor(struct drm_minor *minor)
{
if (!minor)
return;
DRM_DEBUG("release secondary minor %d\n", minor->index);
drm_unplug_minor(minor);
kfree(minor);
}
void drm_put_dev(struct drm_device *dev)
{
DRM_DEBUG("\n");
if (!dev) {
DRM_ERROR("cleanup called no dev\n");
return;
}
drm_dev_unregister(dev);
drm_dev_free(dev);
}
void drm_unplug_dev(struct drm_device *dev)
{
if (drm_core_check_feature(dev, DRIVER_MODESET))
drm_unplug_minor(dev->control);
if (dev->render)
drm_unplug_minor(dev->render);
drm_unplug_minor(dev->primary);
mutex_lock(&drm_global_mutex);
drm_device_set_unplugged(dev);
if (dev->open_count == 0) {
drm_put_dev(dev);
}
mutex_unlock(&drm_global_mutex);
}
struct drm_device *drm_dev_alloc(struct drm_driver *driver,
struct device *parent)
{
struct drm_device *dev;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return NULL;
dev->dev = parent;
dev->driver = driver;
INIT_LIST_HEAD(&dev->filelist);
INIT_LIST_HEAD(&dev->ctxlist);
INIT_LIST_HEAD(&dev->vmalist);
INIT_LIST_HEAD(&dev->maplist);
INIT_LIST_HEAD(&dev->vblank_event_list);
spin_lock_init(&dev->count_lock);
spin_lock_init(&dev->event_lock);
mutex_init(&dev->struct_mutex);
mutex_init(&dev->ctxlist_mutex);
if (drm_ht_create(&dev->map_hash, 12))
goto err_free;
ret = drm_ctxbitmap_init(dev);
if (ret) {
DRM_ERROR("Cannot allocate memory for context bitmap.\n");
goto err_ht;
}
if (driver->driver_features & DRIVER_GEM) {
ret = drm_gem_init(dev);
if (ret) {
DRM_ERROR("Cannot initialize graphics execution manager (GEM)\n");
goto err_ctxbitmap;
}
}
return dev;
err_ctxbitmap:
drm_ctxbitmap_cleanup(dev);
err_ht:
drm_ht_remove(&dev->map_hash);
err_free:
kfree(dev);
return NULL;
}
void drm_dev_free(struct drm_device *dev)
{
drm_put_minor(dev->control);
drm_put_minor(dev->render);
drm_put_minor(dev->primary);
if (dev->driver->driver_features & DRIVER_GEM)
drm_gem_destroy(dev);
drm_ctxbitmap_cleanup(dev);
drm_ht_remove(&dev->map_hash);
kfree(dev->devname);
kfree(dev);
}
int drm_dev_register(struct drm_device *dev, unsigned long flags)
{
int ret;
mutex_lock(&drm_global_mutex);
if (dev->driver->bus->agp_init) {
ret = dev->driver->bus->agp_init(dev);
if (ret)
goto out_unlock;
}
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = drm_get_minor(dev, &dev->control, DRM_MINOR_CONTROL);
if (ret)
goto err_agp;
}
if (drm_core_check_feature(dev, DRIVER_RENDER) && drm_rnodes) {
ret = drm_get_minor(dev, &dev->render, DRM_MINOR_RENDER);
if (ret)
goto err_control_node;
}
ret = drm_get_minor(dev, &dev->primary, DRM_MINOR_LEGACY);
if (ret)
goto err_render_node;
if (dev->driver->load) {
ret = dev->driver->load(dev, flags);
if (ret)
goto err_primary_node;
}
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = drm_mode_group_init_legacy_group(dev,
&dev->primary->mode_group);
if (ret)
goto err_unload;
}
list_add_tail(&dev->driver_item, &dev->driver->device_list);
ret = 0;
goto out_unlock;
err_unload:
if (dev->driver->unload)
dev->driver->unload(dev);
err_primary_node:
drm_unplug_minor(dev->primary);
err_render_node:
drm_unplug_minor(dev->render);
err_control_node:
drm_unplug_minor(dev->control);
err_agp:
if (dev->driver->bus->agp_destroy)
dev->driver->bus->agp_destroy(dev);
out_unlock:
mutex_unlock(&drm_global_mutex);
return ret;
}
void drm_dev_unregister(struct drm_device *dev)
{
struct drm_map_list *r_list, *list_temp;
drm_lastclose(dev);
if (dev->driver->unload)
dev->driver->unload(dev);
if (dev->driver->bus->agp_destroy)
dev->driver->bus->agp_destroy(dev);
drm_vblank_cleanup(dev);
list_for_each_entry_safe(r_list, list_temp, &dev->maplist, head)
drm_rmmap(dev, r_list->map);
drm_unplug_minor(dev->control);
drm_unplug_minor(dev->render);
drm_unplug_minor(dev->primary);
list_del(&dev->driver_item);
}
