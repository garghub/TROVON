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
static int fb_plane_width(int width,
const struct drm_format_info *format, int plane)
{
if (plane == 0)
return width;
return DIV_ROUND_UP(width, format->hsub);
}
static int fb_plane_height(int height,
const struct drm_format_info *format, int plane)
{
if (plane == 0)
return height;
return DIV_ROUND_UP(height, format->vsub);
}
static int framebuffer_check(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *r)
{
const struct drm_format_info *info;
int i;
info = __drm_format_info(r->pixel_format & ~DRM_FORMAT_BIG_ENDIAN);
if (!info) {
struct drm_format_name_buf format_name;
DRM_DEBUG_KMS("bad framebuffer format %s\n",
drm_get_format_name(r->pixel_format,
&format_name));
return -EINVAL;
}
info = drm_get_format_info(dev, r);
if (r->width == 0) {
DRM_DEBUG_KMS("bad framebuffer width %u\n", r->width);
return -EINVAL;
}
if (r->height == 0) {
DRM_DEBUG_KMS("bad framebuffer height %u\n", r->height);
return -EINVAL;
}
for (i = 0; i < info->num_planes; i++) {
unsigned int width = fb_plane_width(r->width, info, i);
unsigned int height = fb_plane_height(r->height, info, i);
unsigned int cpp = info->cpp[i];
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
if (r->flags & DRM_MODE_FB_MODIFIERS &&
r->modifier[i] != r->modifier[0]) {
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
for (i = info->num_planes; i < 4; i++) {
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
ret = framebuffer_check(dev, r);
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
drm_framebuffer_put(fb);
if (drm_framebuffer_read_refcount(fb) > 1) {
struct drm_mode_rmfb_work arg;
INIT_WORK_ONSTACK(&arg.work, drm_mode_rmfb_work_fn);
INIT_LIST_HEAD(&arg.fbs);
list_add_tail(&fb->filp_head, &arg.fbs);
schedule_work(&arg.work);
flush_work(&arg.work);
destroy_work_on_stack(&arg.work);
} else
drm_framebuffer_put(fb);
return 0;
fail_unref:
drm_framebuffer_put(fb);
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
r->depth = fb->format->depth;
r->bpp = fb->format->cpp[0] * 8;
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
drm_framebuffer_put(fb);
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
drm_framebuffer_put(fb);
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
drm_framebuffer_put(fb);
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
if (WARN_ON_ONCE(fb->dev != dev || !fb->format))
return -EINVAL;
INIT_LIST_HEAD(&fb->filp_head);
fb->funcs = funcs;
ret = __drm_mode_object_add(dev, &fb->base, DRM_MODE_OBJECT_FB,
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
static int atomic_remove_fb(struct drm_framebuffer *fb)
{
struct drm_modeset_acquire_ctx ctx;
struct drm_device *dev = fb->dev;
struct drm_atomic_state *state;
struct drm_plane *plane;
struct drm_connector *conn;
struct drm_connector_state *conn_state;
int i, ret = 0;
unsigned plane_mask;
state = drm_atomic_state_alloc(dev);
if (!state)
return -ENOMEM;
drm_modeset_acquire_init(&ctx, 0);
state->acquire_ctx = &ctx;
retry:
plane_mask = 0;
ret = drm_modeset_lock_all_ctx(dev, &ctx);
if (ret)
goto unlock;
drm_for_each_plane(plane, dev) {
struct drm_plane_state *plane_state;
if (plane->state->fb != fb)
continue;
plane_state = drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
ret = PTR_ERR(plane_state);
goto unlock;
}
if (plane_state->crtc->primary == plane) {
struct drm_crtc_state *crtc_state;
crtc_state = drm_atomic_get_existing_crtc_state(state, plane_state->crtc);
ret = drm_atomic_add_affected_connectors(state, plane_state->crtc);
if (ret)
goto unlock;
crtc_state->active = false;
ret = drm_atomic_set_mode_for_crtc(crtc_state, NULL);
if (ret)
goto unlock;
}
drm_atomic_set_fb_for_plane(plane_state, NULL);
ret = drm_atomic_set_crtc_for_plane(plane_state, NULL);
if (ret)
goto unlock;
plane_mask |= BIT(drm_plane_index(plane));
plane->old_fb = plane->fb;
}
for_each_connector_in_state(state, conn, conn_state, i) {
ret = drm_atomic_set_crtc_for_connector(conn_state, NULL);
if (ret)
goto unlock;
}
if (plane_mask)
ret = drm_atomic_commit(state);
unlock:
if (plane_mask)
drm_atomic_clean_old_fb(dev, plane_mask, ret);
if (ret == -EDEADLK) {
drm_atomic_state_clear(state);
drm_modeset_backoff(&ctx);
goto retry;
}
drm_atomic_state_put(state);
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
return ret;
}
static void legacy_remove_fb(struct drm_framebuffer *fb)
{
struct drm_device *dev = fb->dev;
struct drm_crtc *crtc;
struct drm_plane *plane;
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
void drm_framebuffer_remove(struct drm_framebuffer *fb)
{
struct drm_device *dev;
if (!fb)
return;
dev = fb->dev;
WARN_ON(!list_empty(&fb->filp_head));
if (drm_framebuffer_read_refcount(fb) > 1) {
if (drm_drv_uses_atomic_modeset(dev)) {
int ret = atomic_remove_fb(fb);
WARN(ret, "atomic remove_fb failed with %i\n", ret);
} else
legacy_remove_fb(fb);
}
drm_framebuffer_put(fb);
}
int drm_framebuffer_plane_width(int width,
const struct drm_framebuffer *fb, int plane)
{
if (plane >= fb->format->num_planes)
return 0;
return fb_plane_width(width, fb->format, plane);
}
int drm_framebuffer_plane_height(int height,
const struct drm_framebuffer *fb, int plane)
{
if (plane >= fb->format->num_planes)
return 0;
return fb_plane_height(height, fb->format, plane);
}
