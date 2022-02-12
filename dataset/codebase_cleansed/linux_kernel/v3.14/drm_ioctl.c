int drm_getunique(struct drm_device *dev, void *data,
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
kfree(dev->devname);
dev->devname = NULL;
kfree(master->unique);
master->unique = NULL;
master->unique_len = 0;
master->unique_size = 0;
}
int drm_setunique(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_unique *u = data;
struct drm_master *master = file_priv->master;
int ret;
if (master->unique_len || master->unique)
return -EBUSY;
if (!u->unique_len || u->unique_len > 1024)
return -EINVAL;
if (!dev->driver->bus->set_unique)
return -EINVAL;
ret = dev->driver->bus->set_unique(dev, master, u);
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
ret = dev->driver->bus->set_busid(dev, master);
if (ret)
goto err;
return 0;
err:
drm_unset_busid(dev, master);
return ret;
}
int drm_getmap(struct drm_device *dev, void *data,
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
int drm_getclient(struct drm_device *dev, void *data,
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
int drm_getstats(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_stats *stats = data;
memset(stats, 0, sizeof(*stats));
return 0;
}
int drm_getcap(struct drm_device *dev, void *data, struct drm_file *file_priv)
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
int
drm_setclientcap(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
struct drm_set_client_cap *req = data;
switch (req->capability) {
case DRM_CLIENT_CAP_STEREO_3D:
if (req->value > 1)
return -EINVAL;
file_priv->stereo_allowed = req->value;
break;
default:
return -EINVAL;
}
return 0;
}
int drm_setversion(struct drm_device *dev, void *data, struct drm_file *file_priv)
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
