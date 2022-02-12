void drm_err(const char *format, ...)
{
struct va_format vaf;
va_list args;
va_start(args, format);
vaf.fmt = format;
vaf.va = &args;
printk(KERN_ERR "[" DRM_NAME ":%ps] *ERROR* %pV",
__builtin_return_address(0), &vaf);
va_end(args);
}
void drm_ut_debug_printk(const char *function_name, const char *format, ...)
{
struct va_format vaf;
va_list args;
va_start(args, format);
vaf.fmt = format;
vaf.va = &args;
printk(KERN_DEBUG "[" DRM_NAME ":%s] %pV", function_name, &vaf);
va_end(args);
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
idr_init(&master->magic_map);
master->minor = minor;
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
struct drm_device *dev = master->minor->dev;
struct drm_map_list *r_list, *list_temp;
mutex_lock(&dev->struct_mutex);
if (dev->driver->master_destroy)
dev->driver->master_destroy(dev, master);
list_for_each_entry_safe(r_list, list_temp, &dev->maplist, head) {
if (r_list->master == master) {
drm_legacy_rmmap_locked(dev, r_list->map);
r_list = NULL;
}
}
mutex_unlock(&dev->struct_mutex);
idr_destroy(&master->magic_map);
kfree(master->unique);
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
mutex_lock(&dev->master_mutex);
if (file_priv->is_master)
goto out_unlock;
if (file_priv->minor->master) {
ret = -EINVAL;
goto out_unlock;
}
if (!file_priv->master) {
ret = -EINVAL;
goto out_unlock;
}
file_priv->minor->master = drm_master_get(file_priv->master);
file_priv->is_master = 1;
if (dev->driver->master_set) {
ret = dev->driver->master_set(dev, file_priv, false);
if (unlikely(ret != 0)) {
file_priv->is_master = 0;
drm_master_put(&file_priv->minor->master);
}
}
out_unlock:
mutex_unlock(&dev->master_mutex);
return ret;
}
int drm_dropmaster_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret = -EINVAL;
mutex_lock(&dev->master_mutex);
if (!file_priv->is_master)
goto out_unlock;
if (!file_priv->minor->master)
goto out_unlock;
ret = 0;
if (dev->driver->master_drop)
dev->driver->master_drop(dev, file_priv, false);
drm_master_put(&file_priv->minor->master);
file_priv->is_master = 0;
out_unlock:
mutex_unlock(&dev->master_mutex);
return ret;
}
static struct drm_minor **drm_minor_get_slot(struct drm_device *dev,
unsigned int type)
{
switch (type) {
case DRM_MINOR_LEGACY:
return &dev->primary;
case DRM_MINOR_RENDER:
return &dev->render;
case DRM_MINOR_CONTROL:
return &dev->control;
default:
return NULL;
}
}
static int drm_minor_alloc(struct drm_device *dev, unsigned int type)
{
struct drm_minor *minor;
unsigned long flags;
int r;
minor = kzalloc(sizeof(*minor), GFP_KERNEL);
if (!minor)
return -ENOMEM;
minor->type = type;
minor->dev = dev;
idr_preload(GFP_KERNEL);
spin_lock_irqsave(&drm_minor_lock, flags);
r = idr_alloc(&drm_minors_idr,
NULL,
64 * type,
64 * (type + 1),
GFP_NOWAIT);
spin_unlock_irqrestore(&drm_minor_lock, flags);
idr_preload_end();
if (r < 0)
goto err_free;
minor->index = r;
minor->kdev = drm_sysfs_minor_alloc(minor);
if (IS_ERR(minor->kdev)) {
r = PTR_ERR(minor->kdev);
goto err_index;
}
*drm_minor_get_slot(dev, type) = minor;
return 0;
err_index:
spin_lock_irqsave(&drm_minor_lock, flags);
idr_remove(&drm_minors_idr, minor->index);
spin_unlock_irqrestore(&drm_minor_lock, flags);
err_free:
kfree(minor);
return r;
}
static void drm_minor_free(struct drm_device *dev, unsigned int type)
{
struct drm_minor **slot, *minor;
unsigned long flags;
slot = drm_minor_get_slot(dev, type);
minor = *slot;
if (!minor)
return;
drm_mode_group_destroy(&minor->mode_group);
put_device(minor->kdev);
spin_lock_irqsave(&drm_minor_lock, flags);
idr_remove(&drm_minors_idr, minor->index);
spin_unlock_irqrestore(&drm_minor_lock, flags);
kfree(minor);
*slot = NULL;
}
static int drm_minor_register(struct drm_device *dev, unsigned int type)
{
struct drm_minor *minor;
unsigned long flags;
int ret;
DRM_DEBUG("\n");
minor = *drm_minor_get_slot(dev, type);
if (!minor)
return 0;
ret = drm_debugfs_init(minor, minor->index, drm_debugfs_root);
if (ret) {
DRM_ERROR("DRM: Failed to initialize /sys/kernel/debug/dri.\n");
return ret;
}
ret = device_add(minor->kdev);
if (ret)
goto err_debugfs;
spin_lock_irqsave(&drm_minor_lock, flags);
idr_replace(&drm_minors_idr, minor, minor->index);
spin_unlock_irqrestore(&drm_minor_lock, flags);
DRM_DEBUG("new minor registered %d\n", minor->index);
return 0;
err_debugfs:
drm_debugfs_cleanup(minor);
return ret;
}
static void drm_minor_unregister(struct drm_device *dev, unsigned int type)
{
struct drm_minor *minor;
unsigned long flags;
minor = *drm_minor_get_slot(dev, type);
if (!minor || !device_is_registered(minor->kdev))
return;
spin_lock_irqsave(&drm_minor_lock, flags);
idr_replace(&drm_minors_idr, NULL, minor->index);
spin_unlock_irqrestore(&drm_minor_lock, flags);
device_del(minor->kdev);
dev_set_drvdata(minor->kdev, NULL);
drm_debugfs_cleanup(minor);
}
struct drm_minor *drm_minor_acquire(unsigned int minor_id)
{
struct drm_minor *minor;
unsigned long flags;
spin_lock_irqsave(&drm_minor_lock, flags);
minor = idr_find(&drm_minors_idr, minor_id);
if (minor)
drm_dev_ref(minor->dev);
spin_unlock_irqrestore(&drm_minor_lock, flags);
if (!minor) {
return ERR_PTR(-ENODEV);
} else if (drm_device_is_unplugged(minor->dev)) {
drm_dev_unref(minor->dev);
return ERR_PTR(-ENODEV);
}
return minor;
}
void drm_minor_release(struct drm_minor *minor)
{
drm_dev_unref(minor->dev);
}
void drm_put_dev(struct drm_device *dev)
{
DRM_DEBUG("\n");
if (!dev) {
DRM_ERROR("cleanup called no dev\n");
return;
}
drm_dev_unregister(dev);
drm_dev_unref(dev);
}
void drm_unplug_dev(struct drm_device *dev)
{
drm_minor_unregister(dev, DRM_MINOR_LEGACY);
drm_minor_unregister(dev, DRM_MINOR_RENDER);
drm_minor_unregister(dev, DRM_MINOR_CONTROL);
mutex_lock(&drm_global_mutex);
drm_device_set_unplugged(dev);
if (dev->open_count == 0) {
drm_put_dev(dev);
}
mutex_unlock(&drm_global_mutex);
}
static struct dentry *drm_fs_mount(struct file_system_type *fs_type, int flags,
const char *dev_name, void *data)
{
return mount_pseudo(fs_type,
"drm:",
&drm_fs_sops,
&drm_fs_dops,
0x010203ff);
}
static struct inode *drm_fs_inode_new(void)
{
struct inode *inode;
int r;
r = simple_pin_fs(&drm_fs_type, &drm_fs_mnt, &drm_fs_cnt);
if (r < 0) {
DRM_ERROR("Cannot mount pseudo fs: %d\n", r);
return ERR_PTR(r);
}
inode = alloc_anon_inode(drm_fs_mnt->mnt_sb);
if (IS_ERR(inode))
simple_release_fs(&drm_fs_mnt, &drm_fs_cnt);
return inode;
}
static void drm_fs_inode_free(struct inode *inode)
{
if (inode) {
iput(inode);
simple_release_fs(&drm_fs_mnt, &drm_fs_cnt);
}
}
struct drm_device *drm_dev_alloc(struct drm_driver *driver,
struct device *parent)
{
struct drm_device *dev;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return NULL;
kref_init(&dev->ref);
dev->dev = parent;
dev->driver = driver;
INIT_LIST_HEAD(&dev->filelist);
INIT_LIST_HEAD(&dev->ctxlist);
INIT_LIST_HEAD(&dev->vmalist);
INIT_LIST_HEAD(&dev->maplist);
INIT_LIST_HEAD(&dev->vblank_event_list);
spin_lock_init(&dev->buf_lock);
spin_lock_init(&dev->event_lock);
mutex_init(&dev->struct_mutex);
mutex_init(&dev->ctxlist_mutex);
mutex_init(&dev->master_mutex);
dev->anon_inode = drm_fs_inode_new();
if (IS_ERR(dev->anon_inode)) {
ret = PTR_ERR(dev->anon_inode);
DRM_ERROR("Cannot allocate anonymous inode: %d\n", ret);
goto err_free;
}
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = drm_minor_alloc(dev, DRM_MINOR_CONTROL);
if (ret)
goto err_minors;
}
if (drm_core_check_feature(dev, DRIVER_RENDER)) {
ret = drm_minor_alloc(dev, DRM_MINOR_RENDER);
if (ret)
goto err_minors;
}
ret = drm_minor_alloc(dev, DRM_MINOR_LEGACY);
if (ret)
goto err_minors;
if (drm_ht_create(&dev->map_hash, 12))
goto err_minors;
ret = drm_legacy_ctxbitmap_init(dev);
if (ret) {
DRM_ERROR("Cannot allocate memory for context bitmap.\n");
goto err_ht;
}
if (drm_core_check_feature(dev, DRIVER_GEM)) {
ret = drm_gem_init(dev);
if (ret) {
DRM_ERROR("Cannot initialize graphics execution manager (GEM)\n");
goto err_ctxbitmap;
}
}
return dev;
err_ctxbitmap:
drm_legacy_ctxbitmap_cleanup(dev);
err_ht:
drm_ht_remove(&dev->map_hash);
err_minors:
drm_minor_free(dev, DRM_MINOR_LEGACY);
drm_minor_free(dev, DRM_MINOR_RENDER);
drm_minor_free(dev, DRM_MINOR_CONTROL);
drm_fs_inode_free(dev->anon_inode);
err_free:
mutex_destroy(&dev->master_mutex);
kfree(dev);
return NULL;
}
static void drm_dev_release(struct kref *ref)
{
struct drm_device *dev = container_of(ref, struct drm_device, ref);
if (drm_core_check_feature(dev, DRIVER_GEM))
drm_gem_destroy(dev);
drm_legacy_ctxbitmap_cleanup(dev);
drm_ht_remove(&dev->map_hash);
drm_fs_inode_free(dev->anon_inode);
drm_minor_free(dev, DRM_MINOR_LEGACY);
drm_minor_free(dev, DRM_MINOR_RENDER);
drm_minor_free(dev, DRM_MINOR_CONTROL);
mutex_destroy(&dev->master_mutex);
kfree(dev->unique);
kfree(dev);
}
void drm_dev_ref(struct drm_device *dev)
{
if (dev)
kref_get(&dev->ref);
}
void drm_dev_unref(struct drm_device *dev)
{
if (dev)
kref_put(&dev->ref, drm_dev_release);
}
int drm_dev_register(struct drm_device *dev, unsigned long flags)
{
int ret;
mutex_lock(&drm_global_mutex);
ret = drm_minor_register(dev, DRM_MINOR_CONTROL);
if (ret)
goto err_minors;
ret = drm_minor_register(dev, DRM_MINOR_RENDER);
if (ret)
goto err_minors;
ret = drm_minor_register(dev, DRM_MINOR_LEGACY);
if (ret)
goto err_minors;
if (dev->driver->load) {
ret = dev->driver->load(dev, flags);
if (ret)
goto err_minors;
}
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = drm_mode_group_init_legacy_group(dev,
&dev->primary->mode_group);
if (ret)
goto err_unload;
}
ret = 0;
goto out_unlock;
err_unload:
if (dev->driver->unload)
dev->driver->unload(dev);
err_minors:
drm_minor_unregister(dev, DRM_MINOR_LEGACY);
drm_minor_unregister(dev, DRM_MINOR_RENDER);
drm_minor_unregister(dev, DRM_MINOR_CONTROL);
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
if (dev->agp)
drm_pci_agp_destroy(dev);
drm_vblank_cleanup(dev);
list_for_each_entry_safe(r_list, list_temp, &dev->maplist, head)
drm_legacy_rmmap(dev, r_list->map);
drm_minor_unregister(dev, DRM_MINOR_LEGACY);
drm_minor_unregister(dev, DRM_MINOR_RENDER);
drm_minor_unregister(dev, DRM_MINOR_CONTROL);
}
int drm_dev_set_unique(struct drm_device *dev, const char *fmt, ...)
{
va_list ap;
kfree(dev->unique);
va_start(ap, fmt);
dev->unique = kvasprintf(GFP_KERNEL, fmt, ap);
va_end(ap);
return dev->unique ? 0 : -ENOMEM;
}
static int drm_stub_open(struct inode *inode, struct file *filp)
{
const struct file_operations *new_fops;
struct drm_minor *minor;
int err;
DRM_DEBUG("\n");
mutex_lock(&drm_global_mutex);
minor = drm_minor_acquire(iminor(inode));
if (IS_ERR(minor)) {
err = PTR_ERR(minor);
goto out_unlock;
}
new_fops = fops_get(minor->dev->driver->fops);
if (!new_fops) {
err = -ENODEV;
goto out_release;
}
replace_fops(filp, new_fops);
if (filp->f_op->open)
err = filp->f_op->open(inode, filp);
else
err = 0;
out_release:
drm_minor_release(minor);
out_unlock:
mutex_unlock(&drm_global_mutex);
return err;
}
static int __init drm_core_init(void)
{
int ret = -ENOMEM;
drm_global_init();
drm_connector_ida_init();
idr_init(&drm_minors_idr);
if (register_chrdev(DRM_MAJOR, "drm", &drm_stub_fops))
goto err_p1;
drm_class = drm_sysfs_create(THIS_MODULE, "drm");
if (IS_ERR(drm_class)) {
printk(KERN_ERR "DRM: Error creating drm class.\n");
ret = PTR_ERR(drm_class);
goto err_p2;
}
drm_debugfs_root = debugfs_create_dir("dri", NULL);
if (!drm_debugfs_root) {
DRM_ERROR("Cannot create /sys/kernel/debug/dri\n");
ret = -1;
goto err_p3;
}
DRM_INFO("Initialized %s %d.%d.%d %s\n",
CORE_NAME, CORE_MAJOR, CORE_MINOR, CORE_PATCHLEVEL, CORE_DATE);
return 0;
err_p3:
drm_sysfs_destroy();
err_p2:
unregister_chrdev(DRM_MAJOR, "drm");
idr_destroy(&drm_minors_idr);
err_p1:
return ret;
}
static void __exit drm_core_exit(void)
{
debugfs_remove(drm_debugfs_root);
drm_sysfs_destroy();
unregister_chrdev(DRM_MAJOR, "drm");
drm_connector_ida_destroy();
idr_destroy(&drm_minors_idr);
}
