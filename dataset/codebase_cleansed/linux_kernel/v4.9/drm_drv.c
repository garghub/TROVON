void drm_dev_printk(const struct device *dev, const char *level,
unsigned int category, const char *function_name,
const char *prefix, const char *format, ...)
{
struct va_format vaf;
va_list args;
if (category != DRM_UT_NONE && !(drm_debug & category))
return;
va_start(args, format);
vaf.fmt = format;
vaf.va = &args;
if (dev)
dev_printk(level, dev, DRM_PRINTK_FMT, function_name, prefix,
&vaf);
else
printk("%s" DRM_PRINTK_FMT, level, function_name, prefix, &vaf);
va_end(args);
}
void drm_printk(const char *level, unsigned int category,
const char *format, ...)
{
struct va_format vaf;
va_list args;
if (category != DRM_UT_NONE && !(drm_debug & category))
return;
va_start(args, format);
vaf.fmt = format;
vaf.va = &args;
printk("%s" "[" DRM_NAME ":%ps]%s %pV",
level, __builtin_return_address(0),
strcmp(level, KERN_ERR) == 0 ? " *ERROR*" : "", &vaf);
va_end(args);
}
static struct drm_minor **drm_minor_get_slot(struct drm_device *dev,
unsigned int type)
{
switch (type) {
case DRM_MINOR_PRIMARY:
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
static int drm_dev_set_unique(struct drm_device *dev, const char *name)
{
if (!name)
return -EINVAL;
kfree(dev->unique);
dev->unique = kstrdup(name, GFP_KERNEL);
return dev->unique ? 0 : -ENOMEM;
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
drm_dev_unregister(dev);
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
int drm_dev_init(struct drm_device *dev,
struct drm_driver *driver,
struct device *parent)
{
int ret;
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
mutex_init(&dev->filelist_mutex);
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
ret = drm_minor_alloc(dev, DRM_MINOR_PRIMARY);
if (ret)
goto err_minors;
ret = drm_ht_create(&dev->map_hash, 12);
if (ret)
goto err_minors;
drm_legacy_ctxbitmap_init(dev);
if (drm_core_check_feature(dev, DRIVER_GEM)) {
ret = drm_gem_init(dev);
if (ret) {
DRM_ERROR("Cannot initialize graphics execution manager (GEM)\n");
goto err_ctxbitmap;
}
}
ret = drm_dev_set_unique(dev, parent ? dev_name(parent) : driver->name);
if (ret)
goto err_setunique;
return 0;
err_setunique:
if (drm_core_check_feature(dev, DRIVER_GEM))
drm_gem_destroy(dev);
err_ctxbitmap:
drm_legacy_ctxbitmap_cleanup(dev);
drm_ht_remove(&dev->map_hash);
err_minors:
drm_minor_free(dev, DRM_MINOR_PRIMARY);
drm_minor_free(dev, DRM_MINOR_RENDER);
drm_minor_free(dev, DRM_MINOR_CONTROL);
drm_fs_inode_free(dev->anon_inode);
err_free:
mutex_destroy(&dev->master_mutex);
return ret;
}
struct drm_device *drm_dev_alloc(struct drm_driver *driver,
struct device *parent)
{
struct drm_device *dev;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return ERR_PTR(-ENOMEM);
ret = drm_dev_init(dev, driver, parent);
if (ret) {
kfree(dev);
return ERR_PTR(ret);
}
return dev;
}
static void drm_dev_release(struct kref *ref)
{
struct drm_device *dev = container_of(ref, struct drm_device, ref);
if (drm_core_check_feature(dev, DRIVER_GEM))
drm_gem_destroy(dev);
drm_legacy_ctxbitmap_cleanup(dev);
drm_ht_remove(&dev->map_hash);
drm_fs_inode_free(dev->anon_inode);
drm_minor_free(dev, DRM_MINOR_PRIMARY);
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
ret = drm_minor_register(dev, DRM_MINOR_PRIMARY);
if (ret)
goto err_minors;
if (dev->driver->load) {
ret = dev->driver->load(dev, flags);
if (ret)
goto err_minors;
}
if (drm_core_check_feature(dev, DRIVER_MODESET))
drm_modeset_register_all(dev);
ret = 0;
goto out_unlock;
err_minors:
drm_minor_unregister(dev, DRM_MINOR_PRIMARY);
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
if (drm_core_check_feature(dev, DRIVER_MODESET))
drm_modeset_unregister_all(dev);
if (dev->driver->unload)
dev->driver->unload(dev);
if (dev->agp)
drm_pci_agp_destroy(dev);
drm_vblank_cleanup(dev);
list_for_each_entry_safe(r_list, list_temp, &dev->maplist, head)
drm_legacy_rmmap(dev, r_list->map);
drm_minor_unregister(dev, DRM_MINOR_PRIMARY);
drm_minor_unregister(dev, DRM_MINOR_RENDER);
drm_minor_unregister(dev, DRM_MINOR_CONTROL);
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
static void drm_core_exit(void)
{
unregister_chrdev(DRM_MAJOR, "drm");
debugfs_remove(drm_debugfs_root);
drm_sysfs_destroy();
idr_destroy(&drm_minors_idr);
drm_connector_ida_destroy();
drm_global_release();
}
static int __init drm_core_init(void)
{
int ret;
drm_global_init();
drm_connector_ida_init();
idr_init(&drm_minors_idr);
ret = drm_sysfs_init();
if (ret < 0) {
DRM_ERROR("Cannot create DRM class: %d\n", ret);
goto error;
}
drm_debugfs_root = debugfs_create_dir("dri", NULL);
if (!drm_debugfs_root) {
ret = -ENOMEM;
DRM_ERROR("Cannot create debugfs-root: %d\n", ret);
goto error;
}
ret = register_chrdev(DRM_MAJOR, "drm", &drm_stub_fops);
if (ret < 0)
goto error;
DRM_INFO("Initialized\n");
return 0;
error:
drm_core_exit();
return ret;
}
