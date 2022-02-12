static int drm_getunique(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_unique *u = data;
struct drm_master *master = file_priv->master;
if (u->unique_len >= master->unique_len) {
if (copy_to_user(u->unique, master->unique, master->unique_len))
return -EFAULT;
}
u->unique_len = master->unique_len;
return 0;
}
static void
drm_unset_busid(struct drm_device *dev,
struct drm_master *master)
{
kfree(master->unique);
master->unique = NULL;
master->unique_len = 0;
}
static int drm_setunique(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_unique *u = data;
struct drm_master *master = file_priv->master;
int ret;
if (master->unique_len || master->unique)
return -EBUSY;
if (!u->unique_len || u->unique_len > 1024)
return -EINVAL;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return 0;
if (WARN_ON(!dev->pdev))
return -EINVAL;
ret = drm_pci_set_unique(dev, master, u);
if (ret)
goto err;
return 0;
err:
drm_unset_busid(dev, master);
return ret;
}
static int drm_set_busid(struct drm_device *dev, struct drm_file *file_priv)
{
struct drm_master *master = file_priv->master;
int ret;
if (master->unique != NULL)
drm_unset_busid(dev, master);
if (dev->driver->set_busid) {
ret = dev->driver->set_busid(dev, master);
if (ret) {
drm_unset_busid(dev, master);
return ret;
}
} else {
if (WARN(dev->unique == NULL,
"No drm_driver.set_busid() implementation provided by "
"%ps. Use drm_dev_set_unique() to set the unique "
"name explicitly.", dev->driver))
return -EINVAL;
master->unique = kstrdup(dev->unique, GFP_KERNEL);
if (master->unique)
master->unique_len = strlen(dev->unique);
}
return 0;
}
static int drm_getmap(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_map *map = data;
struct drm_map_list *r_list = NULL;
struct list_head *list;
int idx;
int i;
idx = map->offset;
if (idx < 0)
return -EINVAL;
i = 0;
mutex_lock(&dev->struct_mutex);
list_for_each(list, &dev->maplist) {
if (i == idx) {
r_list = list_entry(list, struct drm_map_list, head);
break;
}
i++;
}
if (!r_list || !r_list->map) {
mutex_unlock(&dev->struct_mutex);
return -EINVAL;
}
map->offset = r_list->map->offset;
map->size = r_list->map->size;
map->type = r_list->map->type;
map->flags = r_list->map->flags;
map->handle = (void *)(unsigned long) r_list->user_token;
#ifdef CONFIG_X86
map->mtrr = phys_wc_to_mtrr_index(r_list->map->mtrr);
#else
map->mtrr = -1;
#endif
mutex_unlock(&dev->struct_mutex);
return 0;
}
static int drm_getclient(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_client *client = data;
if (client->idx == 0) {
client->auth = file_priv->authenticated;
client->pid = pid_vnr(file_priv->pid);
client->uid = from_kuid_munged(current_user_ns(),
file_priv->uid);
client->magic = 0;
client->iocs = 0;
return 0;
} else {
return -EINVAL;
}
}
static int drm_getstats(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_stats *stats = data;
memset(stats, 0, sizeof(*stats));
return 0;
}
static int drm_getcap(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
struct drm_get_cap *req = data;
req->value = 0;
switch (req->capability) {
case DRM_CAP_DUMB_BUFFER:
if (dev->driver->dumb_create)
req->value = 1;
break;
case DRM_CAP_VBLANK_HIGH_CRTC:
req->value = 1;
break;
case DRM_CAP_DUMB_PREFERRED_DEPTH:
req->value = dev->mode_config.preferred_depth;
break;
case DRM_CAP_DUMB_PREFER_SHADOW:
req->value = dev->mode_config.prefer_shadow;
break;
case DRM_CAP_PRIME:
req->value |= dev->driver->prime_fd_to_handle ? DRM_PRIME_CAP_IMPORT : 0;
req->value |= dev->driver->prime_handle_to_fd ? DRM_PRIME_CAP_EXPORT : 0;
break;
case DRM_CAP_TIMESTAMP_MONOTONIC:
req->value = drm_timestamp_monotonic;
break;
case DRM_CAP_ASYNC_PAGE_FLIP:
req->value = dev->mode_config.async_page_flip;
break;
case DRM_CAP_CURSOR_WIDTH:
if (dev->mode_config.cursor_width)
req->value = dev->mode_config.cursor_width;
else
req->value = 64;
break;
case DRM_CAP_CURSOR_HEIGHT:
if (dev->mode_config.cursor_height)
req->value = dev->mode_config.cursor_height;
else
req->value = 64;
break;
default:
return -EINVAL;
}
return 0;
}
static int
drm_setclientcap(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
struct drm_set_client_cap *req = data;
switch (req->capability) {
case DRM_CLIENT_CAP_STEREO_3D:
if (req->value > 1)
return -EINVAL;
file_priv->stereo_allowed = req->value;
break;
case DRM_CLIENT_CAP_UNIVERSAL_PLANES:
if (req->value > 1)
return -EINVAL;
file_priv->universal_planes = req->value;
break;
case DRM_CLIENT_CAP_ATOMIC:
if (!drm_atomic)
return -EINVAL;
if (!drm_core_check_feature(dev, DRIVER_ATOMIC))
return -EINVAL;
if (req->value > 1)
return -EINVAL;
file_priv->atomic = req->value;
file_priv->universal_planes = req->value;
break;
default:
return -EINVAL;
}
return 0;
}
static int drm_setversion(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
struct drm_set_version *sv = data;
int if_version, retcode = 0;
if (sv->drm_di_major != -1) {
if (sv->drm_di_major != DRM_IF_MAJOR ||
sv->drm_di_minor < 0 || sv->drm_di_minor > DRM_IF_MINOR) {
retcode = -EINVAL;
goto done;
}
if_version = DRM_IF_VERSION(sv->drm_di_major,
sv->drm_di_minor);
dev->if_version = max(if_version, dev->if_version);
if (sv->drm_di_minor >= 1) {
retcode = drm_set_busid(dev, file_priv);
if (retcode)
goto done;
}
}
if (sv->drm_dd_major != -1) {
if (sv->drm_dd_major != dev->driver->major ||
sv->drm_dd_minor < 0 || sv->drm_dd_minor >
dev->driver->minor) {
retcode = -EINVAL;
goto done;
}
}
done:
sv->drm_di_major = DRM_IF_MAJOR;
sv->drm_di_minor = DRM_IF_MINOR;
sv->drm_dd_major = dev->driver->major;
sv->drm_dd_minor = dev->driver->minor;
return retcode;
}
int drm_noop(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
DRM_DEBUG("\n");
return 0;
}
static int drm_copy_field(char __user *buf, size_t *buf_len, const char *value)
{
int len;
len = strlen(value);
if (len > *buf_len)
len = *buf_len;
*buf_len = strlen(value);
if (len && buf)
if (copy_to_user(buf, value, len))
return -EFAULT;
return 0;
}
static int drm_version(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_version *version = data;
int err;
version->version_major = dev->driver->major;
version->version_minor = dev->driver->minor;
version->version_patchlevel = dev->driver->patchlevel;
err = drm_copy_field(version->name, &version->name_len,
dev->driver->name);
if (!err)
err = drm_copy_field(version->date, &version->date_len,
dev->driver->date);
if (!err)
err = drm_copy_field(version->desc, &version->desc_len,
dev->driver->desc);
return err;
}
static int drm_ioctl_permit(u32 flags, struct drm_file *file_priv)
{
if (unlikely((flags & DRM_ROOT_ONLY) && !capable(CAP_SYS_ADMIN)))
return -EACCES;
if (unlikely((flags & DRM_AUTH) && !drm_is_render_client(file_priv) &&
!file_priv->authenticated))
return -EACCES;
if (unlikely((flags & DRM_MASTER) && !file_priv->is_master &&
!drm_is_control_client(file_priv)))
return -EACCES;
if (unlikely(!(flags & DRM_CONTROL_ALLOW) &&
drm_is_control_client(file_priv)))
return -EACCES;
if (unlikely(!(flags & DRM_RENDER_ALLOW) &&
drm_is_render_client(file_priv)))
return -EACCES;
return 0;
}
long drm_ioctl(struct file *filp,
unsigned int cmd, unsigned long arg)
{
struct drm_file *file_priv = filp->private_data;
struct drm_device *dev;
const struct drm_ioctl_desc *ioctl = NULL;
drm_ioctl_t *func;
unsigned int nr = DRM_IOCTL_NR(cmd);
int retcode = -EINVAL;
char stack_kdata[128];
char *kdata = NULL;
unsigned int usize, asize;
dev = file_priv->minor->dev;
if (drm_device_is_unplugged(dev))
return -ENODEV;
if ((nr >= DRM_CORE_IOCTL_COUNT) &&
((nr < DRM_COMMAND_BASE) || (nr >= DRM_COMMAND_END)))
goto err_i1;
if ((nr >= DRM_COMMAND_BASE) && (nr < DRM_COMMAND_END) &&
(nr < DRM_COMMAND_BASE + dev->driver->num_ioctls)) {
u32 drv_size;
ioctl = &dev->driver->ioctls[nr - DRM_COMMAND_BASE];
drv_size = _IOC_SIZE(ioctl->cmd_drv);
usize = asize = _IOC_SIZE(cmd);
if (drv_size > asize)
asize = drv_size;
cmd = ioctl->cmd_drv;
}
else if ((nr >= DRM_COMMAND_END) || (nr < DRM_COMMAND_BASE)) {
u32 drv_size;
ioctl = &drm_ioctls[nr];
drv_size = _IOC_SIZE(ioctl->cmd);
usize = asize = _IOC_SIZE(cmd);
if (drv_size > asize)
asize = drv_size;
cmd = ioctl->cmd;
} else
goto err_i1;
DRM_DEBUG("pid=%d, dev=0x%lx, auth=%d, %s\n",
task_pid_nr(current),
(long)old_encode_dev(file_priv->minor->kdev->devt),
file_priv->authenticated, ioctl->name);
func = ioctl->func;
if (unlikely(!func)) {
DRM_DEBUG("no function\n");
retcode = -EINVAL;
goto err_i1;
}
retcode = drm_ioctl_permit(ioctl->flags, file_priv);
if (unlikely(retcode))
goto err_i1;
if (cmd & (IOC_IN | IOC_OUT)) {
if (asize <= sizeof(stack_kdata)) {
kdata = stack_kdata;
} else {
kdata = kmalloc(asize, GFP_KERNEL);
if (!kdata) {
retcode = -ENOMEM;
goto err_i1;
}
}
if (asize > usize)
memset(kdata + usize, 0, asize - usize);
}
if (cmd & IOC_IN) {
if (copy_from_user(kdata, (void __user *)arg,
usize) != 0) {
retcode = -EFAULT;
goto err_i1;
}
} else if (cmd & IOC_OUT) {
memset(kdata, 0, usize);
}
if (ioctl->flags & DRM_UNLOCKED)
retcode = func(dev, kdata, file_priv);
else {
mutex_lock(&drm_global_mutex);
retcode = func(dev, kdata, file_priv);
mutex_unlock(&drm_global_mutex);
}
if (cmd & IOC_OUT) {
if (copy_to_user((void __user *)arg, kdata,
usize) != 0)
retcode = -EFAULT;
}
err_i1:
if (!ioctl)
DRM_DEBUG("invalid ioctl: pid=%d, dev=0x%lx, auth=%d, cmd=0x%02x, nr=0x%02x\n",
task_pid_nr(current),
(long)old_encode_dev(file_priv->minor->kdev->devt),
file_priv->authenticated, cmd, nr);
if (kdata != stack_kdata)
kfree(kdata);
if (retcode)
DRM_DEBUG("ret = %d\n", retcode);
return retcode;
}
bool drm_ioctl_flags(unsigned int nr, unsigned int *flags)
{
if ((nr >= DRM_COMMAND_END && nr < DRM_CORE_IOCTL_COUNT) ||
(nr < DRM_COMMAND_BASE)) {
*flags = drm_ioctls[nr].flags;
return true;
}
return false;
}
