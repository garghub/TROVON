struct drm_crtc *drm_crtc_from_index(struct drm_device *dev, int idx)
{
struct drm_crtc *crtc;
drm_for_each_crtc(crtc, dev)
if (idx == crtc->index)
return crtc;
return NULL;
}
int drm_crtc_force_disable(struct drm_crtc *crtc)
{
struct drm_mode_set set = {
.crtc = crtc,
};
WARN_ON(drm_drv_uses_atomic_modeset(crtc->dev));
return drm_mode_set_config_internal(&set);
}
int drm_crtc_force_disable_all(struct drm_device *dev)
{
struct drm_crtc *crtc;
int ret = 0;
drm_modeset_lock_all(dev);
drm_for_each_crtc(crtc, dev)
if (crtc->enabled) {
ret = drm_crtc_force_disable(crtc);
if (ret)
goto out;
}
out:
drm_modeset_unlock_all(dev);
return ret;
}
static unsigned int drm_num_crtcs(struct drm_device *dev)
{
unsigned int num = 0;
struct drm_crtc *tmp;
drm_for_each_crtc(tmp, dev) {
num++;
}
return num;
}
int drm_crtc_register_all(struct drm_device *dev)
{
struct drm_crtc *crtc;
int ret = 0;
drm_for_each_crtc(crtc, dev) {
if (drm_debugfs_crtc_add(crtc))
DRM_ERROR("Failed to initialize debugfs entry for CRTC '%s'.\n",
crtc->name);
if (crtc->funcs->late_register)
ret = crtc->funcs->late_register(crtc);
if (ret)
return ret;
}
return 0;
}
void drm_crtc_unregister_all(struct drm_device *dev)
{
struct drm_crtc *crtc;
drm_for_each_crtc(crtc, dev) {
if (crtc->funcs->early_unregister)
crtc->funcs->early_unregister(crtc);
drm_debugfs_crtc_remove(crtc);
}
}
static int drm_crtc_crc_init(struct drm_crtc *crtc)
{
#ifdef CONFIG_DEBUG_FS
spin_lock_init(&crtc->crc.lock);
init_waitqueue_head(&crtc->crc.wq);
crtc->crc.source = kstrdup("auto", GFP_KERNEL);
if (!crtc->crc.source)
return -ENOMEM;
#endif
return 0;
}
static void drm_crtc_crc_fini(struct drm_crtc *crtc)
{
#ifdef CONFIG_DEBUG_FS
kfree(crtc->crc.source);
#endif
}
static struct drm_crtc *fence_to_crtc(struct dma_fence *fence)
{
BUG_ON(fence->ops != &drm_crtc_fence_ops);
return container_of(fence->lock, struct drm_crtc, fence_lock);
}
static const char *drm_crtc_fence_get_driver_name(struct dma_fence *fence)
{
struct drm_crtc *crtc = fence_to_crtc(fence);
return crtc->dev->driver->name;
}
static const char *drm_crtc_fence_get_timeline_name(struct dma_fence *fence)
{
struct drm_crtc *crtc = fence_to_crtc(fence);
return crtc->timeline_name;
}
static bool drm_crtc_fence_enable_signaling(struct dma_fence *fence)
{
return true;
}
struct dma_fence *drm_crtc_create_fence(struct drm_crtc *crtc)
{
struct dma_fence *fence;
fence = kzalloc(sizeof(*fence), GFP_KERNEL);
if (!fence)
return NULL;
dma_fence_init(fence, &drm_crtc_fence_ops, &crtc->fence_lock,
crtc->fence_context, ++crtc->fence_seqno);
return fence;
}
int drm_crtc_init_with_planes(struct drm_device *dev, struct drm_crtc *crtc,
struct drm_plane *primary,
struct drm_plane *cursor,
const struct drm_crtc_funcs *funcs,
const char *name, ...)
{
struct drm_mode_config *config = &dev->mode_config;
int ret;
WARN_ON(primary && primary->type != DRM_PLANE_TYPE_PRIMARY);
WARN_ON(cursor && cursor->type != DRM_PLANE_TYPE_CURSOR);
crtc->dev = dev;
crtc->funcs = funcs;
INIT_LIST_HEAD(&crtc->commit_list);
spin_lock_init(&crtc->commit_lock);
drm_modeset_lock_init(&crtc->mutex);
ret = drm_mode_object_add(dev, &crtc->base, DRM_MODE_OBJECT_CRTC);
if (ret)
return ret;
if (name) {
va_list ap;
va_start(ap, name);
crtc->name = kvasprintf(GFP_KERNEL, name, ap);
va_end(ap);
} else {
crtc->name = kasprintf(GFP_KERNEL, "crtc-%d",
drm_num_crtcs(dev));
}
if (!crtc->name) {
drm_mode_object_unregister(dev, &crtc->base);
return -ENOMEM;
}
crtc->fence_context = dma_fence_context_alloc(1);
spin_lock_init(&crtc->fence_lock);
snprintf(crtc->timeline_name, sizeof(crtc->timeline_name),
"CRTC:%d-%s", crtc->base.id, crtc->name);
crtc->base.properties = &crtc->properties;
list_add_tail(&crtc->head, &config->crtc_list);
crtc->index = config->num_crtc++;
crtc->primary = primary;
crtc->cursor = cursor;
if (primary && !primary->possible_crtcs)
primary->possible_crtcs = 1 << drm_crtc_index(crtc);
if (cursor && !cursor->possible_crtcs)
cursor->possible_crtcs = 1 << drm_crtc_index(crtc);
ret = drm_crtc_crc_init(crtc);
if (ret) {
drm_mode_object_unregister(dev, &crtc->base);
return ret;
}
if (drm_core_check_feature(dev, DRIVER_ATOMIC)) {
drm_object_attach_property(&crtc->base, config->prop_active, 0);
drm_object_attach_property(&crtc->base, config->prop_mode_id, 0);
drm_object_attach_property(&crtc->base,
config->prop_out_fence_ptr, 0);
}
return 0;
}
void drm_crtc_cleanup(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
drm_crtc_crc_fini(crtc);
kfree(crtc->gamma_store);
crtc->gamma_store = NULL;
drm_modeset_lock_fini(&crtc->mutex);
drm_mode_object_unregister(dev, &crtc->base);
list_del(&crtc->head);
dev->mode_config.num_crtc--;
WARN_ON(crtc->state && !crtc->funcs->atomic_destroy_state);
if (crtc->state && crtc->funcs->atomic_destroy_state)
crtc->funcs->atomic_destroy_state(crtc, crtc->state);
kfree(crtc->name);
memset(crtc, 0, sizeof(*crtc));
}
int drm_mode_getcrtc(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_crtc *crtc_resp = data;
struct drm_crtc *crtc;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
crtc = drm_crtc_find(dev, crtc_resp->crtc_id);
if (!crtc)
return -ENOENT;
crtc_resp->gamma_size = crtc->gamma_size;
drm_modeset_lock(&crtc->primary->mutex, NULL);
if (crtc->primary->state && crtc->primary->state->fb)
crtc_resp->fb_id = crtc->primary->state->fb->base.id;
else if (!crtc->primary->state && crtc->primary->fb)
crtc_resp->fb_id = crtc->primary->fb->base.id;
else
crtc_resp->fb_id = 0;
if (crtc->primary->state) {
crtc_resp->x = crtc->primary->state->src_x >> 16;
crtc_resp->y = crtc->primary->state->src_y >> 16;
}
drm_modeset_unlock(&crtc->primary->mutex);
drm_modeset_lock(&crtc->mutex, NULL);
if (crtc->state) {
if (crtc->state->enable) {
drm_mode_convert_to_umode(&crtc_resp->mode, &crtc->state->mode);
crtc_resp->mode_valid = 1;
} else {
crtc_resp->mode_valid = 0;
}
} else {
crtc_resp->x = crtc->x;
crtc_resp->y = crtc->y;
if (crtc->enabled) {
drm_mode_convert_to_umode(&crtc_resp->mode, &crtc->mode);
crtc_resp->mode_valid = 1;
} else {
crtc_resp->mode_valid = 0;
}
}
drm_modeset_unlock(&crtc->mutex);
return 0;
}
static int __drm_mode_set_config_internal(struct drm_mode_set *set,
struct drm_modeset_acquire_ctx *ctx)
{
struct drm_crtc *crtc = set->crtc;
struct drm_framebuffer *fb;
struct drm_crtc *tmp;
int ret;
drm_for_each_crtc(tmp, crtc->dev)
tmp->primary->old_fb = tmp->primary->fb;
fb = set->fb;
ret = crtc->funcs->set_config(set, ctx);
if (ret == 0) {
crtc->primary->crtc = crtc;
crtc->primary->fb = fb;
}
drm_for_each_crtc(tmp, crtc->dev) {
if (tmp->primary->fb)
drm_framebuffer_get(tmp->primary->fb);
if (tmp->primary->old_fb)
drm_framebuffer_put(tmp->primary->old_fb);
tmp->primary->old_fb = NULL;
}
return ret;
}
int drm_mode_set_config_internal(struct drm_mode_set *set)
{
WARN_ON(drm_drv_uses_atomic_modeset(set->crtc->dev));
return __drm_mode_set_config_internal(set, NULL);
}
int drm_crtc_check_viewport(const struct drm_crtc *crtc,
int x, int y,
const struct drm_display_mode *mode,
const struct drm_framebuffer *fb)
{
int hdisplay, vdisplay;
drm_mode_get_hv_timing(mode, &hdisplay, &vdisplay);
if (crtc->state &&
drm_rotation_90_or_270(crtc->primary->state->rotation))
swap(hdisplay, vdisplay);
return drm_framebuffer_check_src_coords(x << 16, y << 16,
hdisplay << 16, vdisplay << 16,
fb);
}
int drm_mode_setcrtc(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_mode_crtc *crtc_req = data;
struct drm_crtc *crtc;
struct drm_connector **connector_set = NULL, *connector;
struct drm_framebuffer *fb = NULL;
struct drm_display_mode *mode = NULL;
struct drm_mode_set set;
uint32_t __user *set_connectors_ptr;
struct drm_modeset_acquire_ctx ctx;
int ret;
int i;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (crtc_req->x & 0xffff0000 || crtc_req->y & 0xffff0000)
return -ERANGE;
crtc = drm_crtc_find(dev, crtc_req->crtc_id);
if (!crtc) {
DRM_DEBUG_KMS("Unknown CRTC ID %d\n", crtc_req->crtc_id);
return -ENOENT;
}
DRM_DEBUG_KMS("[CRTC:%d:%s]\n", crtc->base.id, crtc->name);
mutex_lock(&crtc->dev->mode_config.mutex);
drm_modeset_acquire_init(&ctx, 0);
retry:
ret = drm_modeset_lock_all_ctx(crtc->dev, &ctx);
if (ret)
goto out;
if (crtc_req->mode_valid) {
if (crtc_req->fb_id == -1) {
if (!crtc->primary->fb) {
DRM_DEBUG_KMS("CRTC doesn't have current FB\n");
ret = -EINVAL;
goto out;
}
fb = crtc->primary->fb;
drm_framebuffer_get(fb);
} else {
fb = drm_framebuffer_lookup(dev, crtc_req->fb_id);
if (!fb) {
DRM_DEBUG_KMS("Unknown FB ID%d\n",
crtc_req->fb_id);
ret = -ENOENT;
goto out;
}
}
mode = drm_mode_create(dev);
if (!mode) {
ret = -ENOMEM;
goto out;
}
ret = drm_mode_convert_umode(mode, &crtc_req->mode);
if (ret) {
DRM_DEBUG_KMS("Invalid mode\n");
goto out;
}
if (!crtc->primary->format_default) {
ret = drm_plane_check_pixel_format(crtc->primary,
fb->format->format);
if (ret) {
struct drm_format_name_buf format_name;
DRM_DEBUG_KMS("Invalid pixel format %s\n",
drm_get_format_name(fb->format->format,
&format_name));
goto out;
}
}
ret = drm_crtc_check_viewport(crtc, crtc_req->x, crtc_req->y,
mode, fb);
if (ret)
goto out;
}
if (crtc_req->count_connectors == 0 && mode) {
DRM_DEBUG_KMS("Count connectors is 0 but mode set\n");
ret = -EINVAL;
goto out;
}
if (crtc_req->count_connectors > 0 && (!mode || !fb)) {
DRM_DEBUG_KMS("Count connectors is %d but no mode or fb set\n",
crtc_req->count_connectors);
ret = -EINVAL;
goto out;
}
if (crtc_req->count_connectors > 0) {
u32 out_id;
if (crtc_req->count_connectors > config->num_connector) {
ret = -EINVAL;
goto out;
}
connector_set = kmalloc_array(crtc_req->count_connectors,
sizeof(struct drm_connector *),
GFP_KERNEL);
if (!connector_set) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < crtc_req->count_connectors; i++) {
connector_set[i] = NULL;
set_connectors_ptr = (uint32_t __user *)(unsigned long)crtc_req->set_connectors_ptr;
if (get_user(out_id, &set_connectors_ptr[i])) {
ret = -EFAULT;
goto out;
}
connector = drm_connector_lookup(dev, out_id);
if (!connector) {
DRM_DEBUG_KMS("Connector id %d unknown\n",
out_id);
ret = -ENOENT;
goto out;
}
DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n",
connector->base.id,
connector->name);
connector_set[i] = connector;
}
}
set.crtc = crtc;
set.x = crtc_req->x;
set.y = crtc_req->y;
set.mode = mode;
set.connectors = connector_set;
set.num_connectors = crtc_req->count_connectors;
set.fb = fb;
ret = __drm_mode_set_config_internal(&set, &ctx);
out:
if (fb)
drm_framebuffer_put(fb);
if (connector_set) {
for (i = 0; i < crtc_req->count_connectors; i++) {
if (connector_set[i])
drm_connector_put(connector_set[i]);
}
}
kfree(connector_set);
drm_mode_destroy(dev, mode);
if (ret == -EDEADLK) {
drm_modeset_backoff(&ctx);
goto retry;
}
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
mutex_unlock(&crtc->dev->mode_config.mutex);
return ret;
}
int drm_mode_crtc_set_obj_prop(struct drm_mode_object *obj,
struct drm_property *property,
uint64_t value)
{
int ret = -EINVAL;
struct drm_crtc *crtc = obj_to_crtc(obj);
if (crtc->funcs->set_property)
ret = crtc->funcs->set_property(crtc, property, value);
if (!ret)
drm_object_property_set_value(obj, property, value);
return ret;
}
