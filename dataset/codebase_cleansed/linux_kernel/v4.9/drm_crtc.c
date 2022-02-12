int drm_crtc_force_disable(struct drm_crtc *crtc)
{
struct drm_mode_set set = {
.crtc = crtc,
};
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
static int drm_crtc_register_all(struct drm_device *dev)
{
struct drm_crtc *crtc;
int ret = 0;
drm_for_each_crtc(crtc, dev) {
if (crtc->funcs->late_register)
ret = crtc->funcs->late_register(crtc);
if (ret)
return ret;
}
return 0;
}
static void drm_crtc_unregister_all(struct drm_device *dev)
{
struct drm_crtc *crtc;
drm_for_each_crtc(crtc, dev) {
if (crtc->funcs->early_unregister)
crtc->funcs->early_unregister(crtc);
}
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
ret = drm_mode_object_get(dev, &crtc->base, DRM_MODE_OBJECT_CRTC);
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
crtc->base.properties = &crtc->properties;
list_add_tail(&crtc->head, &config->crtc_list);
crtc->index = config->num_crtc++;
crtc->primary = primary;
crtc->cursor = cursor;
if (primary)
primary->possible_crtcs = 1 << drm_crtc_index(crtc);
if (cursor)
cursor->possible_crtcs = 1 << drm_crtc_index(crtc);
if (drm_core_check_feature(dev, DRIVER_ATOMIC)) {
drm_object_attach_property(&crtc->base, config->prop_active, 0);
drm_object_attach_property(&crtc->base, config->prop_mode_id, 0);
}
return 0;
}
void drm_crtc_cleanup(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
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
int drm_modeset_register_all(struct drm_device *dev)
{
int ret;
ret = drm_plane_register_all(dev);
if (ret)
goto err_plane;
ret = drm_crtc_register_all(dev);
if (ret)
goto err_crtc;
ret = drm_encoder_register_all(dev);
if (ret)
goto err_encoder;
ret = drm_connector_register_all(dev);
if (ret)
goto err_connector;
return 0;
err_connector:
drm_encoder_unregister_all(dev);
err_encoder:
drm_crtc_unregister_all(dev);
err_crtc:
drm_plane_unregister_all(dev);
err_plane:
return ret;
}
void drm_modeset_unregister_all(struct drm_device *dev)
{
drm_connector_unregister_all(dev);
drm_encoder_unregister_all(dev);
drm_crtc_unregister_all(dev);
drm_plane_unregister_all(dev);
}
static int drm_mode_create_standard_properties(struct drm_device *dev)
{
struct drm_property *prop;
int ret;
ret = drm_connector_create_standard_properties(dev);
if (ret)
return ret;
prop = drm_property_create_enum(dev, DRM_MODE_PROP_IMMUTABLE,
"type", drm_plane_type_enum_list,
ARRAY_SIZE(drm_plane_type_enum_list));
if (!prop)
return -ENOMEM;
dev->mode_config.plane_type_property = prop;
prop = drm_property_create_range(dev, DRM_MODE_PROP_ATOMIC,
"SRC_X", 0, UINT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_src_x = prop;
prop = drm_property_create_range(dev, DRM_MODE_PROP_ATOMIC,
"SRC_Y", 0, UINT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_src_y = prop;
prop = drm_property_create_range(dev, DRM_MODE_PROP_ATOMIC,
"SRC_W", 0, UINT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_src_w = prop;
prop = drm_property_create_range(dev, DRM_MODE_PROP_ATOMIC,
"SRC_H", 0, UINT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_src_h = prop;
prop = drm_property_create_signed_range(dev, DRM_MODE_PROP_ATOMIC,
"CRTC_X", INT_MIN, INT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_crtc_x = prop;
prop = drm_property_create_signed_range(dev, DRM_MODE_PROP_ATOMIC,
"CRTC_Y", INT_MIN, INT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_crtc_y = prop;
prop = drm_property_create_range(dev, DRM_MODE_PROP_ATOMIC,
"CRTC_W", 0, INT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_crtc_w = prop;
prop = drm_property_create_range(dev, DRM_MODE_PROP_ATOMIC,
"CRTC_H", 0, INT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_crtc_h = prop;
prop = drm_property_create_object(dev, DRM_MODE_PROP_ATOMIC,
"FB_ID", DRM_MODE_OBJECT_FB);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_fb_id = prop;
prop = drm_property_create_object(dev, DRM_MODE_PROP_ATOMIC,
"CRTC_ID", DRM_MODE_OBJECT_CRTC);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_crtc_id = prop;
prop = drm_property_create_bool(dev, DRM_MODE_PROP_ATOMIC,
"ACTIVE");
if (!prop)
return -ENOMEM;
dev->mode_config.prop_active = prop;
prop = drm_property_create(dev,
DRM_MODE_PROP_ATOMIC | DRM_MODE_PROP_BLOB,
"MODE_ID", 0);
if (!prop)
return -ENOMEM;
dev->mode_config.prop_mode_id = prop;
prop = drm_property_create(dev,
DRM_MODE_PROP_BLOB,
"DEGAMMA_LUT", 0);
if (!prop)
return -ENOMEM;
dev->mode_config.degamma_lut_property = prop;
prop = drm_property_create_range(dev,
DRM_MODE_PROP_IMMUTABLE,
"DEGAMMA_LUT_SIZE", 0, UINT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.degamma_lut_size_property = prop;
prop = drm_property_create(dev,
DRM_MODE_PROP_BLOB,
"CTM", 0);
if (!prop)
return -ENOMEM;
dev->mode_config.ctm_property = prop;
prop = drm_property_create(dev,
DRM_MODE_PROP_BLOB,
"GAMMA_LUT", 0);
if (!prop)
return -ENOMEM;
dev->mode_config.gamma_lut_property = prop;
prop = drm_property_create_range(dev,
DRM_MODE_PROP_IMMUTABLE,
"GAMMA_LUT_SIZE", 0, UINT_MAX);
if (!prop)
return -ENOMEM;
dev->mode_config.gamma_lut_size_property = prop;
return 0;
}
int drm_mode_getresources(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_card_res *card_res = data;
struct list_head *lh;
struct drm_framebuffer *fb;
struct drm_connector *connector;
struct drm_crtc *crtc;
struct drm_encoder *encoder;
int ret = 0;
int connector_count = 0;
int crtc_count = 0;
int fb_count = 0;
int encoder_count = 0;
int copied = 0;
uint32_t __user *fb_id;
uint32_t __user *crtc_id;
uint32_t __user *connector_id;
uint32_t __user *encoder_id;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
mutex_lock(&file_priv->fbs_lock);
list_for_each(lh, &file_priv->fbs)
fb_count++;
if (card_res->count_fbs >= fb_count) {
copied = 0;
fb_id = (uint32_t __user *)(unsigned long)card_res->fb_id_ptr;
list_for_each_entry(fb, &file_priv->fbs, filp_head) {
if (put_user(fb->base.id, fb_id + copied)) {
mutex_unlock(&file_priv->fbs_lock);
return -EFAULT;
}
copied++;
}
}
card_res->count_fbs = fb_count;
mutex_unlock(&file_priv->fbs_lock);
mutex_lock(&dev->mode_config.mutex);
drm_for_each_crtc(crtc, dev)
crtc_count++;
drm_for_each_connector(connector, dev)
connector_count++;
drm_for_each_encoder(encoder, dev)
encoder_count++;
card_res->max_height = dev->mode_config.max_height;
card_res->min_height = dev->mode_config.min_height;
card_res->max_width = dev->mode_config.max_width;
card_res->min_width = dev->mode_config.min_width;
if (card_res->count_crtcs >= crtc_count) {
copied = 0;
crtc_id = (uint32_t __user *)(unsigned long)card_res->crtc_id_ptr;
drm_for_each_crtc(crtc, dev) {
if (put_user(crtc->base.id, crtc_id + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
card_res->count_crtcs = crtc_count;
if (card_res->count_encoders >= encoder_count) {
copied = 0;
encoder_id = (uint32_t __user *)(unsigned long)card_res->encoder_id_ptr;
drm_for_each_encoder(encoder, dev) {
if (put_user(encoder->base.id, encoder_id +
copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
card_res->count_encoders = encoder_count;
if (card_res->count_connectors >= connector_count) {
copied = 0;
connector_id = (uint32_t __user *)(unsigned long)card_res->connector_id_ptr;
drm_for_each_connector(connector, dev) {
if (put_user(connector->base.id,
connector_id + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
card_res->count_connectors = connector_count;
out:
mutex_unlock(&dev->mode_config.mutex);
return ret;
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
drm_modeset_lock_crtc(crtc, crtc->primary);
crtc_resp->gamma_size = crtc->gamma_size;
if (crtc->primary->fb)
crtc_resp->fb_id = crtc->primary->fb->base.id;
else
crtc_resp->fb_id = 0;
if (crtc->state) {
crtc_resp->x = crtc->primary->state->src_x >> 16;
crtc_resp->y = crtc->primary->state->src_y >> 16;
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
drm_modeset_unlock_crtc(crtc);
return 0;
}
int drm_mode_set_config_internal(struct drm_mode_set *set)
{
struct drm_crtc *crtc = set->crtc;
struct drm_framebuffer *fb;
struct drm_crtc *tmp;
int ret;
drm_for_each_crtc(tmp, crtc->dev)
tmp->primary->old_fb = tmp->primary->fb;
fb = set->fb;
ret = crtc->funcs->set_config(set);
if (ret == 0) {
crtc->primary->crtc = crtc;
crtc->primary->fb = fb;
}
drm_for_each_crtc(tmp, crtc->dev) {
if (tmp->primary->fb)
drm_framebuffer_reference(tmp->primary->fb);
if (tmp->primary->old_fb)
drm_framebuffer_unreference(tmp->primary->old_fb);
tmp->primary->old_fb = NULL;
}
return ret;
}
void drm_crtc_get_hv_timing(const struct drm_display_mode *mode,
int *hdisplay, int *vdisplay)
{
struct drm_display_mode adjusted;
drm_mode_copy(&adjusted, mode);
drm_mode_set_crtcinfo(&adjusted, CRTC_STEREO_DOUBLE_ONLY);
*hdisplay = adjusted.crtc_hdisplay;
*vdisplay = adjusted.crtc_vdisplay;
}
int drm_crtc_check_viewport(const struct drm_crtc *crtc,
int x, int y,
const struct drm_display_mode *mode,
const struct drm_framebuffer *fb)
{
int hdisplay, vdisplay;
drm_crtc_get_hv_timing(mode, &hdisplay, &vdisplay);
if (crtc->state &&
crtc->primary->state->rotation & (DRM_ROTATE_90 |
DRM_ROTATE_270))
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
int ret;
int i;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (crtc_req->x & 0xffff0000 || crtc_req->y & 0xffff0000)
return -ERANGE;
drm_modeset_lock_all(dev);
crtc = drm_crtc_find(dev, crtc_req->crtc_id);
if (!crtc) {
DRM_DEBUG_KMS("Unknown CRTC ID %d\n", crtc_req->crtc_id);
ret = -ENOENT;
goto out;
}
DRM_DEBUG_KMS("[CRTC:%d:%s]\n", crtc->base.id, crtc->name);
if (crtc_req->mode_valid) {
if (crtc_req->fb_id == -1) {
if (!crtc->primary->fb) {
DRM_DEBUG_KMS("CRTC doesn't have current FB\n");
ret = -EINVAL;
goto out;
}
fb = crtc->primary->fb;
drm_framebuffer_reference(fb);
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
fb->pixel_format);
if (ret) {
char *format_name = drm_get_format_name(fb->pixel_format);
DRM_DEBUG_KMS("Invalid pixel format %s\n", format_name);
kfree(format_name);
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
ret = drm_mode_set_config_internal(&set);
out:
if (fb)
drm_framebuffer_unreference(fb);
if (connector_set) {
for (i = 0; i < crtc_req->count_connectors; i++) {
if (connector_set[i])
drm_connector_unreference(connector_set[i]);
}
}
kfree(connector_set);
drm_mode_destroy(dev, mode);
drm_modeset_unlock_all(dev);
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
void drm_mode_config_reset(struct drm_device *dev)
{
struct drm_crtc *crtc;
struct drm_plane *plane;
struct drm_encoder *encoder;
struct drm_connector *connector;
drm_for_each_plane(plane, dev)
if (plane->funcs->reset)
plane->funcs->reset(plane);
drm_for_each_crtc(crtc, dev)
if (crtc->funcs->reset)
crtc->funcs->reset(crtc);
drm_for_each_encoder(encoder, dev)
if (encoder->funcs->reset)
encoder->funcs->reset(encoder);
mutex_lock(&dev->mode_config.mutex);
drm_for_each_connector(connector, dev)
if (connector->funcs->reset)
connector->funcs->reset(connector);
mutex_unlock(&dev->mode_config.mutex);
}
int drm_mode_create_dumb_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_create_dumb *args = data;
u32 cpp, stride, size;
if (!dev->driver->dumb_create)
return -ENOSYS;
if (!args->width || !args->height || !args->bpp)
return -EINVAL;
cpp = DIV_ROUND_UP(args->bpp, 8);
if (!cpp || cpp > 0xffffffffU / args->width)
return -EINVAL;
stride = cpp * args->width;
if (args->height > 0xffffffffU / stride)
return -EINVAL;
size = args->height * stride;
if (PAGE_ALIGN(size) == 0)
return -EINVAL;
args->handle = 0;
args->pitch = 0;
args->size = 0;
return dev->driver->dumb_create(file_priv, dev, args);
}
int drm_mode_mmap_dumb_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_map_dumb *args = data;
if (!dev->driver->dumb_map_offset)
return -ENOSYS;
return dev->driver->dumb_map_offset(file_priv, dev, args->handle, &args->offset);
}
int drm_mode_destroy_dumb_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_destroy_dumb *args = data;
if (!dev->driver->dumb_destroy)
return -ENOSYS;
return dev->driver->dumb_destroy(file_priv, dev, args->handle);
}
void drm_mode_config_init(struct drm_device *dev)
{
mutex_init(&dev->mode_config.mutex);
drm_modeset_lock_init(&dev->mode_config.connection_mutex);
mutex_init(&dev->mode_config.idr_mutex);
mutex_init(&dev->mode_config.fb_lock);
mutex_init(&dev->mode_config.blob_lock);
INIT_LIST_HEAD(&dev->mode_config.fb_list);
INIT_LIST_HEAD(&dev->mode_config.crtc_list);
INIT_LIST_HEAD(&dev->mode_config.connector_list);
INIT_LIST_HEAD(&dev->mode_config.encoder_list);
INIT_LIST_HEAD(&dev->mode_config.property_list);
INIT_LIST_HEAD(&dev->mode_config.property_blob_list);
INIT_LIST_HEAD(&dev->mode_config.plane_list);
idr_init(&dev->mode_config.crtc_idr);
idr_init(&dev->mode_config.tile_idr);
ida_init(&dev->mode_config.connector_ida);
drm_modeset_lock_all(dev);
drm_mode_create_standard_properties(dev);
drm_modeset_unlock_all(dev);
dev->mode_config.num_fb = 0;
dev->mode_config.num_connector = 0;
dev->mode_config.num_crtc = 0;
dev->mode_config.num_encoder = 0;
dev->mode_config.num_overlay_plane = 0;
dev->mode_config.num_total_plane = 0;
}
void drm_mode_config_cleanup(struct drm_device *dev)
{
struct drm_connector *connector, *ot;
struct drm_crtc *crtc, *ct;
struct drm_encoder *encoder, *enct;
struct drm_framebuffer *fb, *fbt;
struct drm_property *property, *pt;
struct drm_property_blob *blob, *bt;
struct drm_plane *plane, *plt;
list_for_each_entry_safe(encoder, enct, &dev->mode_config.encoder_list,
head) {
encoder->funcs->destroy(encoder);
}
list_for_each_entry_safe(connector, ot,
&dev->mode_config.connector_list, head) {
connector->funcs->destroy(connector);
}
list_for_each_entry_safe(property, pt, &dev->mode_config.property_list,
head) {
drm_property_destroy(dev, property);
}
list_for_each_entry_safe(plane, plt, &dev->mode_config.plane_list,
head) {
plane->funcs->destroy(plane);
}
list_for_each_entry_safe(crtc, ct, &dev->mode_config.crtc_list, head) {
crtc->funcs->destroy(crtc);
}
list_for_each_entry_safe(blob, bt, &dev->mode_config.property_blob_list,
head_global) {
drm_property_unreference_blob(blob);
}
WARN_ON(!list_empty(&dev->mode_config.fb_list));
list_for_each_entry_safe(fb, fbt, &dev->mode_config.fb_list, head) {
drm_framebuffer_free(&fb->base.refcount);
}
ida_destroy(&dev->mode_config.connector_ida);
idr_destroy(&dev->mode_config.tile_idr);
idr_destroy(&dev->mode_config.crtc_idr);
drm_modeset_lock_fini(&dev->mode_config.connection_mutex);
}
static void drm_tile_group_free(struct kref *kref)
{
struct drm_tile_group *tg = container_of(kref, struct drm_tile_group, refcount);
struct drm_device *dev = tg->dev;
mutex_lock(&dev->mode_config.idr_mutex);
idr_remove(&dev->mode_config.tile_idr, tg->id);
mutex_unlock(&dev->mode_config.idr_mutex);
kfree(tg);
}
void drm_mode_put_tile_group(struct drm_device *dev,
struct drm_tile_group *tg)
{
kref_put(&tg->refcount, drm_tile_group_free);
}
struct drm_tile_group *drm_mode_get_tile_group(struct drm_device *dev,
char topology[8])
{
struct drm_tile_group *tg;
int id;
mutex_lock(&dev->mode_config.idr_mutex);
idr_for_each_entry(&dev->mode_config.tile_idr, tg, id) {
if (!memcmp(tg->group_data, topology, 8)) {
if (!kref_get_unless_zero(&tg->refcount))
tg = NULL;
mutex_unlock(&dev->mode_config.idr_mutex);
return tg;
}
}
mutex_unlock(&dev->mode_config.idr_mutex);
return NULL;
}
struct drm_tile_group *drm_mode_create_tile_group(struct drm_device *dev,
char topology[8])
{
struct drm_tile_group *tg;
int ret;
tg = kzalloc(sizeof(*tg), GFP_KERNEL);
if (!tg)
return ERR_PTR(-ENOMEM);
kref_init(&tg->refcount);
memcpy(tg->group_data, topology, 8);
tg->dev = dev;
mutex_lock(&dev->mode_config.idr_mutex);
ret = idr_alloc(&dev->mode_config.tile_idr, tg, 1, 0, GFP_KERNEL);
if (ret >= 0) {
tg->id = ret;
} else {
kfree(tg);
tg = ERR_PTR(ret);
}
mutex_unlock(&dev->mode_config.idr_mutex);
return tg;
}
