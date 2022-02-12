static int compat_drm_version(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_version32_t v32;
struct drm_version v;
int err;
if (copy_from_user(&v32, (void __user *)arg, sizeof(v32)))
return -EFAULT;
v = (struct drm_version) {
.name_len = v32.name_len,
.name = compat_ptr(v32.name),
.date_len = v32.date_len,
.date = compat_ptr(v32.date),
.desc_len = v32.desc_len,
.desc = compat_ptr(v32.desc),
};
err = drm_ioctl_kernel(file, drm_version, &v,
DRM_UNLOCKED|DRM_RENDER_ALLOW|DRM_CONTROL_ALLOW);
if (err)
return err;
v32.version_major = v.version_major;
v32.version_minor = v.version_minor;
v32.version_patchlevel = v.version_patchlevel;
v32.name_len = v.name_len;
v32.date_len = v.date_len;
v32.desc_len = v.desc_len;
if (copy_to_user((void __user *)arg, &v32, sizeof(v32)))
return -EFAULT;
return 0;
}
static int compat_drm_getunique(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_unique32_t uq32;
struct drm_unique uq;
int err;
if (copy_from_user(&uq32, (void __user *)arg, sizeof(uq32)))
return -EFAULT;
uq = (struct drm_unique){
.unique_len = uq32.unique_len,
.unique = compat_ptr(uq32.unique),
};
err = drm_ioctl_kernel(file, drm_getunique, &uq, DRM_UNLOCKED);
if (err)
return err;
uq32.unique_len = uq.unique_len;
if (copy_to_user((void __user *)arg, &uq32, sizeof(uq32)))
return -EFAULT;
return 0;
}
static int compat_drm_setunique(struct file *file, unsigned int cmd,
unsigned long arg)
{
return -EINVAL;
}
static int compat_drm_getmap(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_map32_t __user *argp = (void __user *)arg;
drm_map32_t m32;
struct drm_map map;
int err;
if (copy_from_user(&m32, argp, sizeof(m32)))
return -EFAULT;
map.offset = m32.offset;
err = drm_ioctl_kernel(file, drm_legacy_getmap_ioctl, &map, DRM_UNLOCKED);
if (err)
return err;
m32.offset = map.offset;
m32.size = map.size;
m32.type = map.type;
m32.flags = map.flags;
m32.handle = ptr_to_compat(map.handle);
m32.mtrr = map.mtrr;
if (copy_to_user(argp, &m32, sizeof(m32)))
return -EFAULT;
return 0;
}
static int compat_drm_addmap(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_map32_t __user *argp = (void __user *)arg;
drm_map32_t m32;
struct drm_map map;
int err;
if (copy_from_user(&m32, argp, sizeof(m32)))
return -EFAULT;
map.offset = m32.offset;
map.size = m32.size;
map.type = m32.type;
map.flags = m32.flags;
err = drm_ioctl_kernel(file, drm_legacy_addmap_ioctl, &map,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
if (err)
return err;
m32.offset = map.offset;
m32.mtrr = map.mtrr;
m32.handle = ptr_to_compat(map.handle);
if (map.handle != compat_ptr(m32.handle))
pr_err_ratelimited("compat_drm_addmap truncated handle %p for type %d offset %x\n",
map.handle, m32.type, m32.offset);
if (copy_to_user(argp, &m32, sizeof(m32)))
return -EFAULT;
return 0;
}
static int compat_drm_rmmap(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_map32_t __user *argp = (void __user *)arg;
struct drm_map map;
u32 handle;
if (get_user(handle, &argp->handle))
return -EFAULT;
map.handle = compat_ptr(handle);
return drm_ioctl_kernel(file, drm_legacy_rmmap_ioctl, &map, DRM_AUTH);
}
static int compat_drm_getclient(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_client32_t c32;
drm_client32_t __user *argp = (void __user *)arg;
struct drm_client client;
int err;
if (copy_from_user(&c32, argp, sizeof(c32)))
return -EFAULT;
client.idx = c32.idx;
err = drm_ioctl_kernel(file, drm_getclient, &client, DRM_UNLOCKED);
if (err)
return err;
c32.idx = client.idx;
c32.auth = client.auth;
c32.pid = client.pid;
c32.uid = client.uid;
c32.magic = client.magic;
c32.iocs = client.iocs;
if (copy_to_user(argp, &c32, sizeof(c32)))
return -EFAULT;
return 0;
}
static int compat_drm_getstats(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_stats32_t __user *argp = (void __user *)arg;
int err;
err = drm_ioctl_kernel(file, drm_noop, NULL, DRM_UNLOCKED);
if (err)
return err;
if (clear_user(argp, sizeof(drm_stats32_t)))
return -EFAULT;
return 0;
}
static int compat_drm_addbufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_desc32_t __user *argp = (void __user *)arg;
drm_buf_desc32_t desc32;
struct drm_buf_desc desc;
int err;
if (copy_from_user(&desc32, argp, sizeof(drm_buf_desc32_t)))
return -EFAULT;
desc = (struct drm_buf_desc){
desc32.count, desc32.size, desc32.low_mark, desc32.high_mark,
desc32.flags, desc32.agp_start
};
err = drm_ioctl_kernel(file, drm_legacy_addbufs, &desc,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
if (err)
return err;
desc32 = (drm_buf_desc32_t){
desc.count, desc.size, desc.low_mark, desc.high_mark,
desc.flags, desc.agp_start
};
if (copy_to_user(argp, &desc32, sizeof(drm_buf_desc32_t)))
return -EFAULT;
return 0;
}
static int compat_drm_markbufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_desc32_t b32;
drm_buf_desc32_t __user *argp = (void __user *)arg;
struct drm_buf_desc buf;
if (copy_from_user(&b32, argp, sizeof(b32)))
return -EFAULT;
buf.size = b32.size;
buf.low_mark = b32.low_mark;
buf.high_mark = b32.high_mark;
return drm_ioctl_kernel(file, drm_legacy_markbufs, &buf,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int copy_one_buf32(void *data, int count, struct drm_buf_entry *from)
{
drm_buf_info32_t *request = data;
drm_buf_desc32_t __user *to = compat_ptr(request->list);
drm_buf_desc32_t v = {.count = from->buf_count,
.size = from->buf_size,
.low_mark = from->low_mark,
.high_mark = from->high_mark};
return copy_to_user(to + count, &v, offsetof(drm_buf_desc32_t, flags));
}
static int drm_legacy_infobufs32(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_buf_info32_t *request = data;
return __drm_legacy_infobufs(dev, data, &request->count, copy_one_buf32);
}
static int compat_drm_infobufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_info32_t req32;
drm_buf_info32_t __user *argp = (void __user *)arg;
int err;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
if (req32.count < 0)
req32.count = 0;
err = drm_ioctl_kernel(file, drm_legacy_infobufs32, &req32, DRM_AUTH);
if (err)
return err;
if (put_user(req32.count, &argp->count))
return -EFAULT;
return 0;
}
static int map_one_buf32(void *data, int idx, unsigned long virtual,
struct drm_buf *buf)
{
drm_buf_map32_t *request = data;
drm_buf_pub32_t __user *to = compat_ptr(request->list) + idx;
drm_buf_pub32_t v;
v.idx = buf->idx;
v.total = buf->total;
v.used = 0;
v.address = virtual + buf->offset;
if (copy_to_user(to, &v, sizeof(v)))
return -EFAULT;
return 0;
}
static int drm_legacy_mapbufs32(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_buf_map32_t *request = data;
void __user *v;
int err = __drm_legacy_mapbufs(dev, data, &request->count,
&v, map_one_buf32,
file_priv);
request->virtual = ptr_to_compat(v);
return err;
}
static int compat_drm_mapbufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_map32_t __user *argp = (void __user *)arg;
drm_buf_map32_t req32;
int err;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
if (req32.count < 0)
return -EINVAL;
err = drm_ioctl_kernel(file, drm_legacy_mapbufs32, &req32, DRM_AUTH);
if (err)
return err;
if (put_user(req32.count, &argp->count)
|| put_user(req32.virtual, &argp->virtual))
return -EFAULT;
return 0;
}
static int compat_drm_freebufs(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_buf_free32_t req32;
struct drm_buf_free request;
drm_buf_free32_t __user *argp = (void __user *)arg;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request.count = req32.count;
request.list = compat_ptr(req32.list);
return drm_ioctl_kernel(file, drm_legacy_freebufs, &request, DRM_AUTH);
}
static int compat_drm_setsareactx(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_ctx_priv_map32_t req32;
struct drm_ctx_priv_map request;
drm_ctx_priv_map32_t __user *argp = (void __user *)arg;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request.ctx_id = req32.ctx_id;
request.handle = compat_ptr(req32.handle);
return drm_ioctl_kernel(file, drm_legacy_setsareactx, &request,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int compat_drm_getsareactx(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct drm_ctx_priv_map req;
drm_ctx_priv_map32_t req32;
drm_ctx_priv_map32_t __user *argp = (void __user *)arg;
int err;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
req.ctx_id = req32.ctx_id;
err = drm_ioctl_kernel(file, drm_legacy_getsareactx, &req, DRM_AUTH);
if (err)
return err;
req32.handle = ptr_to_compat(req.handle);
if (copy_to_user(argp, &req32, sizeof(req32)))
return -EFAULT;
return 0;
}
static int compat_drm_resctx(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_ctx_res32_t __user *argp = (void __user *)arg;
drm_ctx_res32_t res32;
struct drm_ctx_res res;
int err;
if (copy_from_user(&res32, argp, sizeof(res32)))
return -EFAULT;
res.count = res32.count;
res.contexts = compat_ptr(res32.contexts);
err = drm_ioctl_kernel(file, drm_legacy_resctx, &res, DRM_AUTH);
if (err)
return err;
res32.count = res.count;
if (copy_to_user(argp, &res32, sizeof(res32)))
return -EFAULT;
return 0;
}
static int compat_drm_dma(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_dma32_t d32;
drm_dma32_t __user *argp = (void __user *)arg;
struct drm_dma d;
int err;
if (copy_from_user(&d32, argp, sizeof(d32)))
return -EFAULT;
d.context = d32.context;
d.send_count = d32.send_count;
d.send_indices = compat_ptr(d32.send_indices);
d.send_sizes = compat_ptr(d32.send_sizes);
d.flags = d32.flags;
d.request_count = d32.request_count;
d.request_indices = compat_ptr(d32.request_indices);
d.request_sizes = compat_ptr(d32.request_sizes);
err = drm_ioctl_kernel(file, drm_legacy_dma_ioctl, &d, DRM_AUTH);
if (err)
return err;
if (put_user(d.request_size, &argp->request_size)
|| put_user(d.granted_count, &argp->granted_count))
return -EFAULT;
return 0;
}
static int compat_drm_agp_enable(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_mode32_t __user *argp = (void __user *)arg;
struct drm_agp_mode mode;
if (get_user(mode.mode, &argp->mode))
return -EFAULT;
return drm_ioctl_kernel(file, drm_agp_enable_ioctl, &mode,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int compat_drm_agp_info(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_info32_t __user *argp = (void __user *)arg;
drm_agp_info32_t i32;
struct drm_agp_info info;
int err;
err = drm_ioctl_kernel(file, drm_agp_info_ioctl, &info, DRM_AUTH);
if (err)
return err;
i32.agp_version_major = info.agp_version_major;
i32.agp_version_minor = info.agp_version_minor;
i32.mode = info.mode;
i32.aperture_base = info.aperture_base;
i32.aperture_size = info.aperture_size;
i32.memory_allowed = info.memory_allowed;
i32.memory_used = info.memory_used;
i32.id_vendor = info.id_vendor;
i32.id_device = info.id_device;
if (copy_to_user(argp, &i32, sizeof(i32)))
return -EFAULT;
return 0;
}
static int compat_drm_agp_alloc(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_buffer32_t __user *argp = (void __user *)arg;
drm_agp_buffer32_t req32;
struct drm_agp_buffer request;
int err;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request.size = req32.size;
request.type = req32.type;
err = drm_ioctl_kernel(file, drm_agp_alloc_ioctl, &request,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
if (err)
return err;
req32.handle = request.handle;
req32.physical = request.physical;
if (copy_to_user(argp, &req32, sizeof(req32))) {
drm_ioctl_kernel(file, drm_agp_free_ioctl, &request,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
return -EFAULT;
}
return 0;
}
static int compat_drm_agp_free(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_buffer32_t __user *argp = (void __user *)arg;
struct drm_agp_buffer request;
if (get_user(request.handle, &argp->handle))
return -EFAULT;
return drm_ioctl_kernel(file, drm_agp_free_ioctl, &request,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int compat_drm_agp_bind(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_binding32_t __user *argp = (void __user *)arg;
drm_agp_binding32_t req32;
struct drm_agp_binding request;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
request.handle = req32.handle;
request.offset = req32.offset;
return drm_ioctl_kernel(file, drm_agp_bind_ioctl, &request,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int compat_drm_agp_unbind(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_agp_binding32_t __user *argp = (void __user *)arg;
struct drm_agp_binding request;
if (get_user(request.handle, &argp->handle))
return -EFAULT;
return drm_ioctl_kernel(file, drm_agp_unbind_ioctl, &request,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int compat_drm_sg_alloc(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_scatter_gather32_t __user *argp = (void __user *)arg;
struct drm_scatter_gather request;
int err;
if (get_user(request.size, &argp->size))
return -EFAULT;
err = drm_ioctl_kernel(file, drm_legacy_sg_alloc, &request,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
if (err)
return err;
if (put_user(request.handle >> PAGE_SHIFT, &argp->handle))
return -EFAULT;
return 0;
}
static int compat_drm_sg_free(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_scatter_gather32_t __user *argp = (void __user *)arg;
struct drm_scatter_gather request;
unsigned long x;
if (get_user(x, &argp->handle))
return -EFAULT;
request.handle = x << PAGE_SHIFT;
return drm_ioctl_kernel(file, drm_legacy_sg_free, &request,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int compat_drm_update_draw(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_update_draw32_t update32;
if (copy_from_user(&update32, (void __user *)arg, sizeof(update32)))
return -EFAULT;
return drm_ioctl_kernel(file, drm_noop, NULL,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int compat_drm_wait_vblank(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_wait_vblank32_t __user *argp = (void __user *)arg;
drm_wait_vblank32_t req32;
union drm_wait_vblank req;
int err;
if (copy_from_user(&req32, argp, sizeof(req32)))
return -EFAULT;
req.request.type = req32.request.type;
req.request.sequence = req32.request.sequence;
req.request.signal = req32.request.signal;
err = drm_ioctl_kernel(file, drm_wait_vblank, &req, DRM_UNLOCKED);
if (err)
return err;
req32.reply.type = req.reply.type;
req32.reply.sequence = req.reply.sequence;
req32.reply.tval_sec = req.reply.tval_sec;
req32.reply.tval_usec = req.reply.tval_usec;
if (copy_to_user(argp, &req32, sizeof(req32)))
return -EFAULT;
return 0;
}
static int compat_drm_mode_addfb2(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct drm_mode_fb_cmd232 __user *argp = (void __user *)arg;
struct drm_mode_fb_cmd2 req64;
int err;
if (copy_from_user(&req64, argp,
offsetof(drm_mode_fb_cmd232_t, modifier)))
return -EFAULT;
if (copy_from_user(&req64.modifier, &argp->modifier,
sizeof(req64.modifier)))
return -EFAULT;
err = drm_ioctl_kernel(file, drm_mode_addfb2, &req64,
DRM_CONTROL_ALLOW|DRM_UNLOCKED);
if (err)
return err;
if (put_user(req64.fb_id, &argp->fb_id))
return -EFAULT;
return 0;
}
long drm_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned int nr = DRM_IOCTL_NR(cmd);
struct drm_file *file_priv = filp->private_data;
drm_ioctl_compat_t *fn;
int ret;
if (nr >= ARRAY_SIZE(drm_compat_ioctls))
return drm_ioctl(filp, cmd, arg);
fn = drm_compat_ioctls[nr].fn;
if (!fn)
return drm_ioctl(filp, cmd, arg);
DRM_DEBUG("pid=%d, dev=0x%lx, auth=%d, %s\n",
task_pid_nr(current),
(long)old_encode_dev(file_priv->minor->kdev->devt),
file_priv->authenticated,
drm_compat_ioctls[nr].name);
ret = (*fn)(filp, cmd, arg);
if (ret)
DRM_DEBUG("ret = %d\n", ret);
return ret;
}
