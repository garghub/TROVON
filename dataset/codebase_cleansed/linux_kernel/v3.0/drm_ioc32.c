static int compat_drm_version(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_version32_t v32;
struct drm_version __user *version;
int err;
if (copy_from_user(&v32, (void __user *)arg, sizeof(v32)))
return -EFAULT;
version = compat_alloc_user_space(sizeof(*version));
if (!access_ok(VERIFY_WRITE, version, sizeof(*version)))
return -EFAULT;
if (__put_user(v32.name_len, &version->name_len)
|| __put_user((void __user *)(unsigned long)v32.name,
&version->name)
|| __put_user(v32.date_len, &version->date_len)
|| __put_user((void __user *)(unsigned long)v32.date,
&version->date)
|| __put_user(v32.desc_len, &version->desc_len)
|| __put_user((void __user *)(unsigned long)v32.desc,
&version->desc))
return -EFAULT;
err = drm_ioctl(file,
DRM_IOCTL_VERSION, (unsigned long)version);
if (err)
return err;
if (__get_user(v32.version_major, &version->version_major)
|| __get_user(v32.version_minor, &version->version_minor)
|| __get_user(v32.version_patchlevel, &version->version_patchlevel)
|| __get_user(v32.name_len, &version->name_len)
|| __get_user(v32.date_len, &version->date_len)
|| __get_user(v32.desc_len, &version->desc_len))
return -EFAULT;
if (copy_to_user((void __user *)arg, &v32, sizeof(v32)))
return -EFAULT;
return 0;
}
static int compat_drm_getunique(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_unique32_t uq32;
struct drm_unique __user *u;
int err;
if (copy_from_user(&uq32, (void __user *)arg, sizeof(uq32)))
return -EFAULT;
u = compat_alloc_user_space(sizeof(*u));
if (!access_ok(VERIFY_WRITE, u, sizeof(*u)))
return -EFAULT;
if (__put_user(uq32.unique_len, &u->unique_len)
|| __put_user((void __user *)(unsigned long)uq32.unique,
&u->unique))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_GET_UNIQUE, (unsigned long)u);
if (err)
return err;
if (__get_user(uq32.unique_len, &u->unique_len))
return -EFAULT;
if (copy_to_user((void __user *)arg, &uq32, sizeof(uq32)))
return -EFAULT;
return 0;
}
static int compat_drm_setunique(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_unique32_t uq32;
struct drm_unique __user *u;
if (copy_from_user(&uq32, (void __user *)arg, sizeof(uq32)))
return -EFAULT;
u = compat_alloc_user_space(sizeof(*u));
if (!access_ok(VERIFY_WRITE, u, sizeof(*u)))
return -EFAULT;
if (__put_user(uq32.unique_len, &u->unique_len)
|| __put_user((void __user *)(unsigned long)uq32.unique,
&u->unique))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_SET_UNIQUE, (unsigned long)u);
}
static int compat_drm_getmap(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_map32_t __user *argp = (void __user *)arg;
drm_map32_t m32;
struct drm_map __user *map;
int idx, err;
void *handle;
if (get_user(idx, &argp->offset))
return -EFAULT;
map = compat_alloc_user_space(sizeof(*map));
if (!access_ok(VERIFY_WRITE, map, sizeof(*map)))
return -EFAULT;
if (__put_user(idx, &map->offset))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_GET_MAP, (unsigned long)map);
if (err)
return err;
if (__get_user(m32.offset, &map->offset)
|| __get_user(m32.size, &map->size)
|| __get_user(m32.type, &map->type)
|| __get_user(m32.flags, &map->flags)
|| __get_user(handle, &map->handle)
|| __get_user(m32.mtrr, &map->mtrr))
return -EFAULT;
m32.handle = (unsigned long)handle;
if (copy_to_user(argp, &m32, sizeof(m32)))
return -EFAULT;
return 0;
}
static int compat_drm_addmap(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_map32_t __user *argp = (void __user *)arg;
drm_map32_t m32;
struct drm_map __user *map;
int err;
void *handle;
if (copy_from_user(&m32, argp, sizeof(m32)))
return -EFAULT;
map = compat_alloc_user_space(sizeof(*map));
if (!access_ok(VERIFY_WRITE, map, sizeof(*map)))
return -EFAULT;
if (__put_user(m32.offset, &map->offset)
|| __put_user(m32.size, &map->size)
|| __put_user(m32.type, &map->type)
|| __put_user(m32.flags, &map->flags))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_ADD_MAP, (unsigned long)map);
if (err)
return err;
if (__get_user(m32.offset, &map->offset)
|| __get_user(m32.mtrr, &map->mtrr)
|| __get_user(handle, &map->handle))
return -EFAULT;
m32.handle = (unsigned long)handle;
if (m32.handle != (unsigned long)handle)
printk_ratelimited(KERN_ERR "compat_drm_addmap truncated handle"
" %p for type %d offset %x\n",
handle, m32.type, m32.offset);
if (copy_to_user(argp, &m32, sizeof(m32)))
return -EFAULT;
return 0;
}
static int compat_drm_rmmap(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_map32_t __user *argp = (void __user *)arg;
struct drm_map __user *map;
u32 handle;
if (get_user(handle, &argp->handle))
return -EFAULT;
map = compat_alloc_user_space(sizeof(*map));
if (!access_ok(VERIFY_WRITE, map, sizeof(*map)))
return -EFAULT;
if (__put_user((void *)(unsigned long)handle, &map->handle))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RM_MAP, (unsigned long)map);
}
static int compat_drm_getclient(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_client32_t c32;
drm_client32_t __user *argp = (void __user *)arg;
struct drm_client __user *client;
int idx, err;
if (get_user(idx, &argp->idx))
return -EFAULT;
client = compat_alloc_user_space(sizeof(*client));
if (!access_ok(VERIFY_WRITE, client, sizeof(*client)))
return -EFAULT;
if (__put_user(idx, &client->idx))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_GET_CLIENT, (unsigned long)client);
if (err)
return err;
if (__get_user(c32.auth, &client->auth)
|| __get_user(c32.pid, &client->pid)
|| __get_user(c32.uid, &client->uid)
|| __get_user(c32.magic, &client->magic)
|| __get_user(c32.iocs, &client->iocs))
return -EFAULT;
if (copy_to_user(argp, &c32, sizeof(c32)))
return -EFAULT;
return 0;
}
static int compat_drm_getstats(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_stats32_t s32;
drm_stats32_t __user *argp = (void __user *)arg;
struct drm_stats __user *stats;
int i, err;
stats = compat_alloc_user_space(sizeof(*stats));
if (!access_ok(VERIFY_WRITE, stats, sizeof(*stats)))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_GET_STATS, (unsigned long)stats);
if (err)
return err;
if (__get_user(s32.count, &stats->count))
return -EFAULT;
for (i = 0; i < 15; ++i)
if (__get_user(s32.data[i].value, &stats->data[i].value)
|| __get_user(s32.data[i].type, &stats->data[i].type))
return -EFAULT;
if (copy_to_user(argp, &s32, sizeof(s32)))
return -EFAULT;
return 0;
}
static int compat_drm_addbufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_desc32_t __user *argp = (void __user *)arg;
struct drm_buf_desc __user *buf;
int err;
unsigned long agp_start;
buf = compat_alloc_user_space(sizeof(*buf));
if (!access_ok(VERIFY_WRITE, buf, sizeof(*buf))
|| !access_ok(VERIFY_WRITE, argp, sizeof(*argp)))
return -EFAULT;
if (__copy_in_user(buf, argp, offsetof(drm_buf_desc32_t, agp_start))
|| __get_user(agp_start, &argp->agp_start)
|| __put_user(agp_start, &buf->agp_start))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_ADD_BUFS, (unsigned long)buf);
if (err)
return err;
if (__copy_in_user(argp, buf, offsetof(drm_buf_desc32_t, agp_start))
|| __get_user(agp_start, &buf->agp_start)
|| __put_user(agp_start, &argp->agp_start))
return -EFAULT;
return 0;
}
static int compat_drm_markbufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_desc32_t b32;
drm_buf_desc32_t __user *argp = (void __user *)arg;
struct drm_buf_desc __user *buf;
if (copy_from_user(&b32, argp, sizeof(b32)))
return -EFAULT;
buf = compat_alloc_user_space(sizeof(*buf));
if (!access_ok(VERIFY_WRITE, buf, sizeof(*buf)))
return -EFAULT;
if (__put_user(b32.size, &buf->size)
|| __put_user(b32.low_mark, &buf->low_mark)
|| __put_user(b32.high_mark, &buf->high_mark))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_MARK_BUFS, (unsigned long)buf);
}
static int compat_drm_infobufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_info32_t req32;
drm_buf_info32_t __user *argp = (void __user *)arg;
drm_buf_desc32_t __user *to;
struct drm_buf_info __user *request;
struct drm_buf_desc __user *list;
size_t nbytes;
int i, err;
int count, actual;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
count = req32.count;
to = (drm_buf_desc32_t __user *) (unsigned long)req32.list;
if (count < 0)
count = 0;
if (count > 0
&& !access_ok(VERIFY_WRITE, to, count * sizeof(drm_buf_desc32_t)))
return -EFAULT;
nbytes = sizeof(*request) + count * sizeof(struct drm_buf_desc);
request = compat_alloc_user_space(nbytes);
if (!access_ok(VERIFY_WRITE, request, nbytes))
return -EFAULT;
list = (struct drm_buf_desc *) (request + 1);
if (__put_user(count, &request->count)
|| __put_user(list, &request->list))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_INFO_BUFS, (unsigned long)request);
if (err)
return err;
if (__get_user(actual, &request->count))
return -EFAULT;
if (count >= actual)
for (i = 0; i < actual; ++i)
if (__copy_in_user(&to[i], &list[i],
offsetof(struct drm_buf_desc, flags)))
return -EFAULT;
if (__put_user(actual, &argp->count))
return -EFAULT;
return 0;
}
static int compat_drm_mapbufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_map32_t __user *argp = (void __user *)arg;
drm_buf_map32_t req32;
drm_buf_pub32_t __user *list32;
struct drm_buf_map __user *request;
struct drm_buf_pub __user *list;
int i, err;
int count, actual;
size_t nbytes;
void __user *addr;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
count = req32.count;
list32 = (void __user *)(unsigned long)req32.list;
if (count < 0)
return -EINVAL;
nbytes = sizeof(*request) + count * sizeof(struct drm_buf_pub);
request = compat_alloc_user_space(nbytes);
if (!access_ok(VERIFY_WRITE, request, nbytes))
return -EFAULT;
list = (struct drm_buf_pub *) (request + 1);
if (__put_user(count, &request->count)
|| __put_user(list, &request->list))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_MAP_BUFS, (unsigned long)request);
if (err)
return err;
if (__get_user(actual, &request->count))
return -EFAULT;
if (count >= actual)
for (i = 0; i < actual; ++i)
if (__copy_in_user(&list32[i], &list[i],
offsetof(struct drm_buf_pub, address))
|| __get_user(addr, &list[i].address)
|| __put_user((unsigned long)addr,
&list32[i].address))
return -EFAULT;
if (__put_user(actual, &argp->count)
|| __get_user(addr, &request->virtual)
|| __put_user((unsigned long)addr, &argp->virtual))
return -EFAULT;
return 0;
}
static int compat_drm_freebufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_free32_t req32;
struct drm_buf_free __user *request;
drm_buf_free32_t __user *argp = (void __user *)arg;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request)))
return -EFAULT;
if (__put_user(req32.count, &request->count)
|| __put_user((int __user *)(unsigned long)req32.list,
&request->list))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_FREE_BUFS, (unsigned long)request);
}
static int compat_drm_setsareactx(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_ctx_priv_map32_t req32;
struct drm_ctx_priv_map __user *request;
drm_ctx_priv_map32_t __user *argp = (void __user *)arg;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request)))
return -EFAULT;
if (__put_user(req32.ctx_id, &request->ctx_id)
|| __put_user((void *)(unsigned long)req32.handle,
&request->handle))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_SET_SAREA_CTX, (unsigned long)request);
}
static int compat_drm_getsareactx(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct drm_ctx_priv_map __user *request;
drm_ctx_priv_map32_t __user *argp = (void __user *)arg;
int err;
unsigned int ctx_id;
void *handle;
if (!access_ok(VERIFY_WRITE, argp, sizeof(*argp))
|| __get_user(ctx_id, &argp->ctx_id))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request)))
return -EFAULT;
if (__put_user(ctx_id, &request->ctx_id))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_GET_SAREA_CTX, (unsigned long)request);
if (err)
return err;
if (__get_user(handle, &request->handle)
|| __put_user((unsigned long)handle, &argp->handle))
return -EFAULT;
return 0;
}
static int compat_drm_resctx(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_ctx_res32_t __user *argp = (void __user *)arg;
drm_ctx_res32_t res32;
struct drm_ctx_res __user *res;
int err;
if (copy_from_user(&res32, argp, sizeof(res32)))
return -EFAULT;
res = compat_alloc_user_space(sizeof(*res));
if (!access_ok(VERIFY_WRITE, res, sizeof(*res)))
return -EFAULT;
if (__put_user(res32.count, &res->count)
|| __put_user((struct drm_ctx __user *) (unsigned long)res32.contexts,
&res->contexts))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_RES_CTX, (unsigned long)res);
if (err)
return err;
if (__get_user(res32.count, &res->count)
|| __put_user(res32.count, &argp->count))
return -EFAULT;
return 0;
}
static int compat_drm_dma(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_dma32_t d32;
drm_dma32_t __user *argp = (void __user *)arg;
struct drm_dma __user *d;
int err;
if (copy_from_user(&d32, argp, sizeof(d32)))
return -EFAULT;
d = compat_alloc_user_space(sizeof(*d));
if (!access_ok(VERIFY_WRITE, d, sizeof(*d)))
return -EFAULT;
if (__put_user(d32.context, &d->context)
|| __put_user(d32.send_count, &d->send_count)
|| __put_user((int __user *)(unsigned long)d32.send_indices,
&d->send_indices)
|| __put_user((int __user *)(unsigned long)d32.send_sizes,
&d->send_sizes)
|| __put_user(d32.flags, &d->flags)
|| __put_user(d32.request_count, &d->request_count)
|| __put_user((int __user *)(unsigned long)d32.request_indices,
&d->request_indices)
|| __put_user((int __user *)(unsigned long)d32.request_sizes,
&d->request_sizes))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_DMA, (unsigned long)d);
if (err)
return err;
if (__get_user(d32.request_size, &d->request_size)
|| __get_user(d32.granted_count, &d->granted_count)
|| __put_user(d32.request_size, &argp->request_size)
|| __put_user(d32.granted_count, &argp->granted_count))
return -EFAULT;
return 0;
}
static int compat_drm_agp_enable(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_mode32_t __user *argp = (void __user *)arg;
drm_agp_mode32_t m32;
struct drm_agp_mode __user *mode;
if (get_user(m32.mode, &argp->mode))
return -EFAULT;
mode = compat_alloc_user_space(sizeof(*mode));
if (put_user(m32.mode, &mode->mode))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_AGP_ENABLE, (unsigned long)mode);
}
static int compat_drm_agp_info(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_info32_t __user *argp = (void __user *)arg;
drm_agp_info32_t i32;
struct drm_agp_info __user *info;
int err;
info = compat_alloc_user_space(sizeof(*info));
if (!access_ok(VERIFY_WRITE, info, sizeof(*info)))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_AGP_INFO, (unsigned long)info);
if (err)
return err;
if (__get_user(i32.agp_version_major, &info->agp_version_major)
|| __get_user(i32.agp_version_minor, &info->agp_version_minor)
|| __get_user(i32.mode, &info->mode)
|| __get_user(i32.aperture_base, &info->aperture_base)
|| __get_user(i32.aperture_size, &info->aperture_size)
|| __get_user(i32.memory_allowed, &info->memory_allowed)
|| __get_user(i32.memory_used, &info->memory_used)
|| __get_user(i32.id_vendor, &info->id_vendor)
|| __get_user(i32.id_device, &info->id_device))
return -EFAULT;
if (copy_to_user(argp, &i32, sizeof(i32)))
return -EFAULT;
return 0;
}
static int compat_drm_agp_alloc(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_buffer32_t __user *argp = (void __user *)arg;
drm_agp_buffer32_t req32;
struct drm_agp_buffer __user *request;
int err;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.size, &request->size)
|| __put_user(req32.type, &request->type))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_AGP_ALLOC, (unsigned long)request);
if (err)
return err;
if (__get_user(req32.handle, &request->handle)
|| __get_user(req32.physical, &request->physical)
|| copy_to_user(argp, &req32, sizeof(req32))) {
drm_ioctl(file, DRM_IOCTL_AGP_FREE, (unsigned long)request);
return -EFAULT;
}
return 0;
}
static int compat_drm_agp_free(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_buffer32_t __user *argp = (void __user *)arg;
struct drm_agp_buffer __user *request;
u32 handle;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| get_user(handle, &argp->handle)
|| __put_user(handle, &request->handle))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_AGP_FREE, (unsigned long)request);
}
static int compat_drm_agp_bind(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_binding32_t __user *argp = (void __user *)arg;
drm_agp_binding32_t req32;
struct drm_agp_binding __user *request;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.handle, &request->handle)
|| __put_user(req32.offset, &request->offset))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_AGP_BIND, (unsigned long)request);
}
static int compat_drm_agp_unbind(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_binding32_t __user *argp = (void __user *)arg;
struct drm_agp_binding __user *request;
u32 handle;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| get_user(handle, &argp->handle)
|| __put_user(handle, &request->handle))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_AGP_UNBIND, (unsigned long)request);
}
static int compat_drm_sg_alloc(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_scatter_gather32_t __user *argp = (void __user *)arg;
struct drm_scatter_gather __user *request;
int err;
unsigned long x;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| !access_ok(VERIFY_WRITE, argp, sizeof(*argp))
|| __get_user(x, &argp->size)
|| __put_user(x, &request->size))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_SG_ALLOC, (unsigned long)request);
if (err)
return err;
if (__get_user(x, &request->handle)
|| __put_user(x >> PAGE_SHIFT, &argp->handle))
return -EFAULT;
return 0;
}
static int compat_drm_sg_free(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_scatter_gather32_t __user *argp = (void __user *)arg;
struct drm_scatter_gather __user *request;
unsigned long x;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| !access_ok(VERIFY_WRITE, argp, sizeof(*argp))
|| __get_user(x, &argp->handle)
|| __put_user(x << PAGE_SHIFT, &request->handle))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_SG_FREE, (unsigned long)request);
}
static int compat_drm_update_draw(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_update_draw32_t update32;
struct drm_update_draw __user *request;
int err;
if (copy_from_user(&update32, (void __user *)arg, sizeof(update32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request)) ||
__put_user(update32.handle, &request->handle) ||
__put_user(update32.type, &request->type) ||
__put_user(update32.num, &request->num) ||
__put_user(update32.data, &request->data))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_UPDATE_DRAW, (unsigned long)request);
return err;
}
static int compat_drm_wait_vblank(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_wait_vblank32_t __user *argp = (void __user *)arg;
drm_wait_vblank32_t req32;
union drm_wait_vblank __user *request;
int err;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.request.type, &request->request.type)
|| __put_user(req32.request.sequence, &request->request.sequence)
|| __put_user(req32.request.signal, &request->request.signal))
return -EFAULT;
err = drm_ioctl(file, DRM_IOCTL_WAIT_VBLANK, (unsigned long)request);
if (err)
return err;
if (__get_user(req32.reply.type, &request->reply.type)
|| __get_user(req32.reply.sequence, &request->reply.sequence)
|| __get_user(req32.reply.tval_sec, &request->reply.tval_sec)
|| __get_user(req32.reply.tval_usec, &request->reply.tval_usec))
return -EFAULT;
if (copy_to_user(argp, &req32, sizeof(req32)))
return -EFAULT;
return 0;
}
long drm_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned int nr = DRM_IOCTL_NR(cmd);
drm_ioctl_compat_t *fn;
int ret;
if (nr >= ARRAY_SIZE(drm_compat_ioctls))
return drm_ioctl(filp, cmd, arg);
fn = drm_compat_ioctls[nr];
if (fn != NULL)
ret = (*fn) (filp, cmd, arg);
else
ret = drm_ioctl(filp, cmd, arg);
return ret;
}
