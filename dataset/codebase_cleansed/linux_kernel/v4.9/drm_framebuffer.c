int drm_framebuffer_check_src_coords(uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h,
const struct drm_framebuffer *fb)
{
unsigned int fb_width, fb_height;
fb_width = fb->width << 16;
fb_height = fb->height << 16;
if (src_w > fb_width ||
src_x > fb_width - src_w ||
src_h > fb_height ||
src_y > fb_height - src_h) {
DRM_DEBUG_KMS("Invalid source coordinates "
"%u.%06ux%u.%06u+%u.%06u+%u.%06u\n",
src_w >> 16, ((src_w & 0xffff) * 15625) >> 10,
src_h >> 16, ((src_h & 0xffff) * 15625) >> 10,
src_x >> 16, ((src_x & 0xffff) * 15625) >> 10,
src_y >> 16, ((src_y & 0xffff) * 15625) >> 10);
return -ENOSPC;
}
return 0;
}
int drm_mode_addfb(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_fb_cmd *or = data;
struct drm_mode_fb_cmd2 r = {};
int ret;
r.fb_id = or->fb_id;
r.width = or->width;
r.height = or->height;
r.pitches[0] = or->pitch;
r.pixel_format = drm_mode_legacy_fb_format(or->bpp, or->depth);
r.handles[0] = or->handle;
ret = drm_mode_addfb2(dev, &r, file_priv);
if (ret)
return ret;
or->fb_id = r.fb_id;
return 0;
}
static int format_check(const struct drm_mode_fb_cmd2 *r)
{
uint32_t format = r->pixel_format & ~DRM_FORMAT_BIG_ENDIAN;
char *format_name;
switch (format) {
case DRM_FORMAT_C8:
case DRM_FORMAT_RGB332:
case DRM_FORMAT_BGR233:
case DRM_FORMAT_XRGB4444:
case DRM_FORMAT_XBGR4444:
case DRM_FORMAT_RGBX4444:
case DRM_FORMAT_BGRX4444:
case DRM_FORMAT_ARGB4444:
case DRM_FORMAT_ABGR4444:
case DRM_FORMAT_RGBA4444:
case DRM_FORMAT_BGRA4444:
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_XBGR1555:
case DRM_FORMAT_RGBX5551:
case DRM_FORMAT_BGRX5551:
case DRM_FORMAT_ARGB1555:
case DRM_FORMAT_ABGR1555:
case DRM_FORMAT_RGBA5551:
case DRM_FORMAT_BGRA5551:
case DRM_FORMAT_RGB565:
case DRM_FORMAT_BGR565:
case DRM_FORMAT_RGB888:
case DRM_FORMAT_BGR888:
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_RGBX8888:
case DRM_FORMAT_BGRX8888:
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_RGBA8888:
case DRM_FORMAT_BGRA8888:
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_XBGR2101010:
case DRM_FORMAT_RGBX1010102:
case DRM_FORMAT_BGRX1010102:
case DRM_FORMAT_ARGB2101010:
case DRM_FORMAT_ABGR2101010:
case DRM_FORMAT_RGBA1010102:
case DRM_FORMAT_BGRA1010102:
case DRM_FORMAT_YUYV:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
case DRM_FORMAT_AYUV:
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_NV24:
case DRM_FORMAT_NV42:
case DRM_FORMAT_YUV410:
case DRM_FORMAT_YVU410:
case DRM_FORMAT_YUV411:
case DRM_FORMAT_YVU411:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YVU422:
case DRM_FORMAT_YUV444:
case DRM_FORMAT_YVU444:
return 0;
default:
format_name = drm_get_format_name(r->pixel_format);
DRM_DEBUG_KMS("invalid pixel format %s\n", format_name);
kfree(format_name);
return -EINVAL;
}
}
static int framebuffer_check(const struct drm_mode_fb_cmd2 *r)
{
int ret, hsub, vsub, num_planes, i;
ret = format_check(r);
if (ret) {
char *format_name = drm_get_format_name(r->pixel_format);
DRM_DEBUG_KMS("bad framebuffer format %s\n", format_name);
kfree(format_name);
return ret;
}
hsub = drm_format_horz_chroma_subsampling(r->pixel_format);
vsub = drm_format_vert_chroma_subsampling(r->pixel_format);
num_planes = drm_format_num_planes(r->pixel_format);
if (r->width == 0 || r->width % hsub) {
DRM_DEBUG_KMS("bad framebuffer width %u\n", r->width);
return -EINVAL;
}
if (r->height == 0 || r->height % vsub) {
DRM_DEBUG_KMS("bad framebuffer height %u\n", r->height);
return -EINVAL;
}
for (i = 0; i < num_planes; i++) {
unsigned int width = r->width / (i != 0 ? hsub : 1);
unsigned int height = r->height / (i != 0 ? vsub : 1);
unsigned int cpp = drm_format_plane_cpp(r->pixel_format, i);
if (!r->handles[i]) {
DRM_DEBUG_KMS("no buffer object handle for plane %d\n", i);
return -EINVAL;
}
if ((uint64_t) width * cpp > UINT_MAX)
return -ERANGE;
if ((uint64_t) height * r->pitches[i] + r->offsets[i] > UINT_MAX)
return -ERANGE;
if (r->pitches[i] < width * cpp) {
DRM_DEBUG_KMS("bad pitch %u for plane %d\n", r->pitches[i], i);
return -EINVAL;
}
if (r->modifier[i] && !(r->flags & DRM_MODE_FB_MODIFIERS)) {
DRM_DEBUG_KMS("bad fb modifier %llu for plane %d\n",
r->modifier[i], i);
return -EINVAL;
}
switch (r->modifier[i]) {
case DRM_FORMAT_MOD_SAMSUNG_64_32_TILE:
if (r->pixel_format != DRM_FORMAT_NV12 ||
width % 128 || height % 32 ||
r->pitches[i] % 128) {
DRM_DEBUG_KMS("bad modifier data for plane %d\n", i);
return -EINVAL;
}
break;
default:
break;
}
}
for (i = num_planes; i < 4; i++) {
if (r->modifier[i]) {
DRM_DEBUG_KMS("non-zero modifier for unused plane %d\n", i);
return -EINVAL;
}
if (!(r->flags & DRM_MODE_FB_MODIFIERS))
continue;
if (r->handles[i]) {
DRM_DEBUG_KMS("buffer object handle for unused plane %d\n", i);
return -EINVAL;
}
if (r->pitches[i]) {
DRM_DEBUG_KMS("non-zero pitch for unused plane %d\n", i);
return -EINVAL;
}
if (r->offsets[i]) {
DRM_DEBUG_KMS("non-zero offset for unused plane %d\n", i);
return -EINVAL;
}
}
return 0;
}
struct drm_framebuffer *
drm_internal_framebuffer_create(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *r,
struct drm_file *file_priv)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_framebuffer *fb;
int ret;
if (r->flags & ~(DRM_MODE_FB_INTERLACED | DRM_MODE_FB_MODIFIERS)) {
DRM_DEBUG_KMS("bad framebuffer flags 0x%08x\n", r->flags);
return ERR_PTR(-EINVAL);
}
if ((config->min_width > r->width) || (r->width > config->max_width)) {
DRM_DEBUG_KMS("bad framebuffer width %d, should be >= %d && <= %d\n",
r->width, config->min_width, config->max_width);
return ERR_PTR(-EINVAL);
}
if ((config->min_height > r->height) || (r->height > config->max_height)) {
DRM_DEBUG_KMS("bad framebuffer height %d, should be >= %d && <= %d\n",
r->height, config->min_height, config->max_height);
return ERR_PTR(-EINVAL);
}
if (r->flags & DRM_MODE_FB_MODIFIERS &&
!dev->mode_config.allow_fb_modifiers) {
DRM_DEBUG_KMS("driver does not support fb modifiers\n");
return ERR_PTR(-EINVAL);
}
ret = framebuffer_check(r);
if (ret)
return ERR_PTR(ret);
fb = dev->mode_config.funcs->fb_create(dev, file_priv, r);
if (IS_ERR(fb)) {
DRM_DEBUG_KMS("could not create framebuffer\n");
return fb;
}
return fb;
}
int drm_mode_addfb2(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_fb_cmd2 *r = data;
struct drm_framebuffer *fb;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
fb = drm_internal_framebuffer_create(dev, r, file_priv);
if (IS_ERR(fb))
return PTR_ERR(fb);
DRM_DEBUG_KMS("[FB:%d]\n", fb->base.id);
r->fb_id = fb->base.id;
mutex_lock(&file_priv->fbs_lock);
list_add(&fb->filp_head, &file_priv->fbs);
mutex_unlock(&file_priv->fbs_lock);
return 0;
}
static void drm_mode_rmfb_work_fn(struct work_struct *w)
{
struct drm_mode_rmfb_work *arg = container_of(w, typeof(*arg), work);
while (!list_empty(&arg->fbs)) {
struct drm_framebuffer *fb =
list_first_entry(&arg->fbs, typeof(*fb), filp_head);
list_del_init(&fb->filp_head);
drm_framebuffer_remove(fb);
}
}
int drm_mode_rmfb(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_framebuffer *fb = NULL;
struct drm_framebuffer *fbl = NULL;
uint32_t *id = data;
int found = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
fb = drm_framebuffer_lookup(dev, *id);
if (!fb)
return -ENOENT;
mutex_lock(&file_priv->fbs_lock);
list_for_each_entry(fbl, &file_priv->fbs, filp_head)
if (fb == fbl)
found = 1;
if (!found) {
mutex_unlock(&file_priv->fbs_lock);
goto fail_unref;
}
list_del_init(&fb->filp_head);
mutex_unlock(&file_priv->fbs_lock);
drm_framebuffer_unreference(fb);
if (drm_framebuffer_read_refcount(fb) > 1) {
struct drm_mode_rmfb_work arg;
INIT_WORK_ONSTACK(&arg.work, drm_mode_rmfb_work_fn);
INIT_LIST_HEAD(&arg.fbs);
list_add_tail(&fb->filp_head, &arg.fbs);
schedule_work(&arg.work);
flush_work(&arg.work);
destroy_work_on_stack(&arg.work);
} else
drm_framebuffer_unreference(fb);
return 0;
fail_unref:
drm_framebuffer_unreference(fb);
return -ENOENT;
}
int drm_mode_getfb(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_fb_cmd *r = data;
struct drm_framebuffer *fb;
int ret;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
fb = drm_framebuffer_lookup(dev, r->fb_id);
if (!fb)
return -ENOENT;
r->height = fb->height;
r->width = fb->width;
r->depth = fb->depth;
r->bpp = fb->bits_per_pixel;
r->pitch = fb->pitches[0];
if (fb->funcs->create_handle) {
if (drm_is_current_master(file_priv) || capable(CAP_SYS_ADMIN) ||
drm_is_control_client(file_priv)) {
ret = fb->funcs->create_handle(fb, file_priv,
&r->handle);
} else {
r->handle = 0;
ret = 0;
}
} else {
ret = -ENODEV;
}
drm_framebuffer_unreference(fb);
return ret;
}
int drm_mode_dirtyfb_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_clip_rect __user *clips_ptr;
struct drm_clip_rect *clips = NULL;
struct drm_mode_fb_dirty_cmd *r = data;
struct drm_framebuffer *fb;
unsigned flags;
int num_clips;
int ret;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
fb = drm_framebuffer_lookup(dev, r->fb_id);
if (!fb)
return -ENOENT;
num_clips = r->num_clips;
clips_ptr = (struct drm_clip_rect __user *)(unsigned long)r->clips_ptr;
if (!num_clips != !clips_ptr) {
ret = -EINVAL;
goto out_err1;
}
flags = DRM_MODE_FB_DIRTY_FLAGS & r->flags;
if (flags & DRM_MODE_FB_DIRTY_ANNOTATE_COPY && (num_clips % 2)) {
ret = -EINVAL;
goto out_err1;
}
if (num_clips && clips_ptr) {
if (num_clips < 0 || num_clips > DRM_MODE_FB_DIRTY_MAX_CLIPS) {
ret = -EINVAL;
goto out_err1;
}
clips = kcalloc(num_clips, sizeof(*clips), GFP_KERNEL);
if (!clips) {
ret = -ENOMEM;
goto out_err1;
}
ret = copy_from_user(clips, clips_ptr,
num_clips * sizeof(*clips));
if (ret) {
ret = -EFAULT;
goto out_err2;
}
}
if (fb->funcs->dirty) {
ret = fb->funcs->dirty(fb, file_priv, flags, r->color,
clips, num_clips);
} else {
ret = -ENOSYS;
}
out_err2:
kfree(clips);
out_err1:
drm_framebuffer_unreference(fb);
return ret;
}
void drm_fb_release(struct drm_file *priv)
{
struct drm_framebuffer *fb, *tfb;
struct drm_mode_rmfb_work arg;
INIT_LIST_HEAD(&arg.fbs);
list_for_each_entry_safe(fb, tfb, &priv->fbs, filp_head) {
if (drm_framebuffer_read_refcount(fb) > 1) {
list_move_tail(&fb->filp_head, &arg.fbs);
} else {
list_del_init(&fb->filp_head);
drm_framebuffer_unreference(fb);
}
}
if (!list_empty(&arg.fbs)) {
INIT_WORK_ONSTACK(&arg.work, drm_mode_rmfb_work_fn);
schedule_work(&arg.work);
flush_work(&arg.work);
destroy_work_on_stack(&arg.work);
}
}
void drm_framebuffer_free(struct kref *kref)
{
struct drm_framebuffer *fb =
container_of(kref, struct drm_framebuffer, base.refcount);
struct drm_device *dev = fb->dev;
drm_mode_object_unregister(dev, &fb->base);
fb->funcs->destroy(fb);
}
int drm_framebuffer_init(struct drm_device *dev, struct drm_framebuffer *fb,
const struct drm_framebuffer_funcs *funcs)
{
int ret;
INIT_LIST_HEAD(&fb->filp_head);
fb->dev = dev;
fb->funcs = funcs;
ret = drm_mode_object_get_reg(dev, &fb->base, DRM_MODE_OBJECT_FB,
false, drm_framebuffer_free);
if (ret)
goto out;
mutex_lock(&dev->mode_config.fb_lock);
dev->mode_config.num_fb++;
list_add(&fb->head, &dev->mode_config.fb_list);
mutex_unlock(&dev->mode_config.fb_lock);
drm_mode_object_register(dev, &fb->base);
out:
return ret;
}
struct drm_framebuffer *drm_framebuffer_lookup(struct drm_device *dev,
uint32_t id)
{
struct drm_mode_object *obj;
struct drm_framebuffer *fb = NULL;
obj = __drm_mode_object_find(dev, id, DRM_MODE_OBJECT_FB);
if (obj)
fb = obj_to_fb(obj);
return fb;
}
void drm_framebuffer_unregister_private(struct drm_framebuffer *fb)
{
struct drm_device *dev;
if (!fb)
return;
dev = fb->dev;
drm_mode_object_unregister(dev, &fb->base);
}
void drm_framebuffer_cleanup(struct drm_framebuffer *fb)
{
struct drm_device *dev = fb->dev;
mutex_lock(&dev->mode_config.fb_lock);
list_del(&fb->head);
dev->mode_config.num_fb--;
mutex_unlock(&dev->mode_config.fb_lock);
}
void drm_framebuffer_remove(struct drm_framebuffer *fb)
{
struct drm_device *dev;
struct drm_crtc *crtc;
struct drm_plane *plane;
if (!fb)
return;
dev = fb->dev;
WARN_ON(!list_empty(&fb->filp_head));
if (drm_framebuffer_read_refcount(fb) > 1) {
drm_modeset_lock_all(dev);
drm_for_each_crtc(crtc, dev) {
if (crtc->primary->fb == fb) {
if (drm_crtc_force_disable(crtc))
DRM_ERROR("failed to reset crtc %p when fb was deleted\n", crtc);
}
}
drm_for_each_plane(plane, dev) {
if (plane->fb == fb)
drm_plane_force_disable(plane);
}
drm_modeset_unlock_all(dev);
}
drm_framebuffer_unreference(fb);
}
