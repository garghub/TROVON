void drm_modeset_lock_all(struct drm_device *dev)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_modeset_acquire_ctx *ctx;
int ret;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (WARN_ON(!ctx))
return;
mutex_lock(&config->mutex);
drm_modeset_acquire_init(ctx, 0);
retry:
ret = drm_modeset_lock(&config->connection_mutex, ctx);
if (ret)
goto fail;
ret = drm_modeset_lock_all_crtcs(dev, ctx);
if (ret)
goto fail;
WARN_ON(config->acquire_ctx);
config->acquire_ctx = ctx;
drm_warn_on_modeset_not_all_locked(dev);
return;
fail:
if (ret == -EDEADLK) {
drm_modeset_backoff(ctx);
goto retry;
}
}
void drm_modeset_unlock_all(struct drm_device *dev)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_modeset_acquire_ctx *ctx = config->acquire_ctx;
if (WARN_ON(!ctx))
return;
config->acquire_ctx = NULL;
drm_modeset_drop_locks(ctx);
drm_modeset_acquire_fini(ctx);
kfree(ctx);
mutex_unlock(&dev->mode_config.mutex);
}
void drm_warn_on_modeset_not_all_locked(struct drm_device *dev)
{
struct drm_crtc *crtc;
if (oops_in_progress)
return;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
WARN_ON(!drm_modeset_is_locked(&crtc->mutex));
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
WARN_ON(!mutex_is_locked(&dev->mode_config.mutex));
}
void drm_connector_ida_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(drm_connector_enum_list); i++)
ida_init(&drm_connector_enum_list[i].ida);
}
void drm_connector_ida_destroy(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(drm_connector_enum_list); i++)
ida_destroy(&drm_connector_enum_list[i].ida);
}
const char *drm_get_connector_status_name(enum drm_connector_status status)
{
if (status == connector_status_connected)
return "connected";
else if (status == connector_status_disconnected)
return "disconnected";
else
return "unknown";
}
const char *drm_get_subpixel_order_name(enum subpixel_order order)
{
return drm_subpixel_enum_list[order].name;
}
static char printable_char(int c)
{
return isascii(c) && isprint(c) ? c : '?';
}
const char *drm_get_format_name(uint32_t format)
{
static char buf[32];
snprintf(buf, sizeof(buf),
"%c%c%c%c %s-endian (0x%08x)",
printable_char(format & 0xff),
printable_char((format >> 8) & 0xff),
printable_char((format >> 16) & 0xff),
printable_char((format >> 24) & 0x7f),
format & DRM_FORMAT_BIG_ENDIAN ? "big" : "little",
format);
return buf;
}
static int drm_mode_object_get_reg(struct drm_device *dev,
struct drm_mode_object *obj,
uint32_t obj_type,
bool register_obj)
{
int ret;
mutex_lock(&dev->mode_config.idr_mutex);
ret = idr_alloc(&dev->mode_config.crtc_idr, register_obj ? obj : NULL, 1, 0, GFP_KERNEL);
if (ret >= 0) {
obj->id = ret;
obj->type = obj_type;
}
mutex_unlock(&dev->mode_config.idr_mutex);
return ret < 0 ? ret : 0;
}
int drm_mode_object_get(struct drm_device *dev,
struct drm_mode_object *obj, uint32_t obj_type)
{
return drm_mode_object_get_reg(dev, obj, obj_type, true);
}
static void drm_mode_object_register(struct drm_device *dev,
struct drm_mode_object *obj)
{
mutex_lock(&dev->mode_config.idr_mutex);
idr_replace(&dev->mode_config.crtc_idr, obj, obj->id);
mutex_unlock(&dev->mode_config.idr_mutex);
}
void drm_mode_object_put(struct drm_device *dev,
struct drm_mode_object *object)
{
mutex_lock(&dev->mode_config.idr_mutex);
idr_remove(&dev->mode_config.crtc_idr, object->id);
mutex_unlock(&dev->mode_config.idr_mutex);
}
static struct drm_mode_object *_object_find(struct drm_device *dev,
uint32_t id, uint32_t type)
{
struct drm_mode_object *obj = NULL;
mutex_lock(&dev->mode_config.idr_mutex);
obj = idr_find(&dev->mode_config.crtc_idr, id);
if (obj && type != DRM_MODE_OBJECT_ANY && obj->type != type)
obj = NULL;
if (obj && obj->id != id)
obj = NULL;
if (obj && (obj->type == DRM_MODE_OBJECT_FB))
obj = NULL;
mutex_unlock(&dev->mode_config.idr_mutex);
return obj;
}
struct drm_mode_object *drm_mode_object_find(struct drm_device *dev,
uint32_t id, uint32_t type)
{
struct drm_mode_object *obj = NULL;
WARN_ON(type == DRM_MODE_OBJECT_FB);
obj = _object_find(dev, id, type);
return obj;
}
int drm_framebuffer_init(struct drm_device *dev, struct drm_framebuffer *fb,
const struct drm_framebuffer_funcs *funcs)
{
int ret;
mutex_lock(&dev->mode_config.fb_lock);
kref_init(&fb->refcount);
INIT_LIST_HEAD(&fb->filp_head);
fb->dev = dev;
fb->funcs = funcs;
ret = drm_mode_object_get(dev, &fb->base, DRM_MODE_OBJECT_FB);
if (ret)
goto out;
drm_framebuffer_reference(fb);
dev->mode_config.num_fb++;
list_add(&fb->head, &dev->mode_config.fb_list);
out:
mutex_unlock(&dev->mode_config.fb_lock);
return 0;
}
static void drm_framebuffer_free(struct kref *kref)
{
struct drm_framebuffer *fb =
container_of(kref, struct drm_framebuffer, refcount);
fb->funcs->destroy(fb);
}
static struct drm_framebuffer *__drm_framebuffer_lookup(struct drm_device *dev,
uint32_t id)
{
struct drm_mode_object *obj = NULL;
struct drm_framebuffer *fb;
mutex_lock(&dev->mode_config.idr_mutex);
obj = idr_find(&dev->mode_config.crtc_idr, id);
if (!obj || (obj->type != DRM_MODE_OBJECT_FB) || (obj->id != id))
fb = NULL;
else
fb = obj_to_fb(obj);
mutex_unlock(&dev->mode_config.idr_mutex);
return fb;
}
struct drm_framebuffer *drm_framebuffer_lookup(struct drm_device *dev,
uint32_t id)
{
struct drm_framebuffer *fb;
mutex_lock(&dev->mode_config.fb_lock);
fb = __drm_framebuffer_lookup(dev, id);
if (fb)
drm_framebuffer_reference(fb);
mutex_unlock(&dev->mode_config.fb_lock);
return fb;
}
void drm_framebuffer_unreference(struct drm_framebuffer *fb)
{
DRM_DEBUG("%p: FB ID: %d (%d)\n", fb, fb->base.id, atomic_read(&fb->refcount.refcount));
kref_put(&fb->refcount, drm_framebuffer_free);
}
void drm_framebuffer_reference(struct drm_framebuffer *fb)
{
DRM_DEBUG("%p: FB ID: %d (%d)\n", fb, fb->base.id, atomic_read(&fb->refcount.refcount));
kref_get(&fb->refcount);
}
static void drm_framebuffer_free_bug(struct kref *kref)
{
BUG();
}
static void __drm_framebuffer_unreference(struct drm_framebuffer *fb)
{
DRM_DEBUG("%p: FB ID: %d (%d)\n", fb, fb->base.id, atomic_read(&fb->refcount.refcount));
kref_put(&fb->refcount, drm_framebuffer_free_bug);
}
static void __drm_framebuffer_unregister(struct drm_device *dev,
struct drm_framebuffer *fb)
{
mutex_lock(&dev->mode_config.idr_mutex);
idr_remove(&dev->mode_config.crtc_idr, fb->base.id);
mutex_unlock(&dev->mode_config.idr_mutex);
fb->base.id = 0;
__drm_framebuffer_unreference(fb);
}
void drm_framebuffer_unregister_private(struct drm_framebuffer *fb)
{
struct drm_device *dev = fb->dev;
mutex_lock(&dev->mode_config.fb_lock);
__drm_framebuffer_unregister(dev, fb);
mutex_unlock(&dev->mode_config.fb_lock);
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
struct drm_device *dev = fb->dev;
struct drm_crtc *crtc;
struct drm_plane *plane;
struct drm_mode_set set;
int ret;
WARN_ON(!list_empty(&fb->filp_head));
if (atomic_read(&fb->refcount.refcount) > 1) {
drm_modeset_lock_all(dev);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (crtc->primary->fb == fb) {
memset(&set, 0, sizeof(struct drm_mode_set));
set.crtc = crtc;
set.fb = NULL;
ret = drm_mode_set_config_internal(&set);
if (ret)
DRM_ERROR("failed to reset crtc %p when fb was deleted\n", crtc);
}
}
list_for_each_entry(plane, &dev->mode_config.plane_list, head) {
if (plane->fb == fb)
drm_plane_force_disable(plane);
}
drm_modeset_unlock_all(dev);
}
drm_framebuffer_unreference(fb);
}
int drm_crtc_init_with_planes(struct drm_device *dev, struct drm_crtc *crtc,
struct drm_plane *primary,
struct drm_plane *cursor,
const struct drm_crtc_funcs *funcs)
{
struct drm_mode_config *config = &dev->mode_config;
int ret;
crtc->dev = dev;
crtc->funcs = funcs;
crtc->invert_dimensions = false;
drm_modeset_lock_all(dev);
drm_modeset_lock_init(&crtc->mutex);
drm_modeset_lock(&crtc->mutex, config->acquire_ctx);
ret = drm_mode_object_get(dev, &crtc->base, DRM_MODE_OBJECT_CRTC);
if (ret)
goto out;
crtc->base.properties = &crtc->properties;
list_add_tail(&crtc->head, &config->crtc_list);
config->num_crtc++;
crtc->primary = primary;
crtc->cursor = cursor;
if (primary)
primary->possible_crtcs = 1 << drm_crtc_index(crtc);
if (cursor)
cursor->possible_crtcs = 1 << drm_crtc_index(crtc);
out:
drm_modeset_unlock_all(dev);
return ret;
}
void drm_crtc_cleanup(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
kfree(crtc->gamma_store);
crtc->gamma_store = NULL;
drm_modeset_lock_fini(&crtc->mutex);
drm_mode_object_put(dev, &crtc->base);
list_del(&crtc->head);
dev->mode_config.num_crtc--;
}
unsigned int drm_crtc_index(struct drm_crtc *crtc)
{
unsigned int index = 0;
struct drm_crtc *tmp;
list_for_each_entry(tmp, &crtc->dev->mode_config.crtc_list, head) {
if (tmp == crtc)
return index;
index++;
}
BUG();
}
static void drm_mode_remove(struct drm_connector *connector,
struct drm_display_mode *mode)
{
list_del(&mode->head);
drm_mode_destroy(connector->dev, mode);
}
int drm_connector_init(struct drm_device *dev,
struct drm_connector *connector,
const struct drm_connector_funcs *funcs,
int connector_type)
{
int ret;
struct ida *connector_ida =
&drm_connector_enum_list[connector_type].ida;
drm_modeset_lock_all(dev);
ret = drm_mode_object_get_reg(dev, &connector->base, DRM_MODE_OBJECT_CONNECTOR, false);
if (ret)
goto out_unlock;
connector->base.properties = &connector->properties;
connector->dev = dev;
connector->funcs = funcs;
connector->connector_type = connector_type;
connector->connector_type_id =
ida_simple_get(connector_ida, 1, 0, GFP_KERNEL);
if (connector->connector_type_id < 0) {
ret = connector->connector_type_id;
goto out_put;
}
connector->name =
kasprintf(GFP_KERNEL, "%s-%d",
drm_connector_enum_list[connector_type].name,
connector->connector_type_id);
if (!connector->name) {
ret = -ENOMEM;
goto out_put;
}
INIT_LIST_HEAD(&connector->probed_modes);
INIT_LIST_HEAD(&connector->modes);
connector->edid_blob_ptr = NULL;
connector->status = connector_status_unknown;
list_add_tail(&connector->head, &dev->mode_config.connector_list);
dev->mode_config.num_connector++;
if (connector_type != DRM_MODE_CONNECTOR_VIRTUAL)
drm_object_attach_property(&connector->base,
dev->mode_config.edid_property,
0);
drm_object_attach_property(&connector->base,
dev->mode_config.dpms_property, 0);
connector->debugfs_entry = NULL;
out_put:
if (ret)
drm_mode_object_put(dev, &connector->base);
out_unlock:
drm_modeset_unlock_all(dev);
return ret;
}
void drm_connector_cleanup(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode, *t;
list_for_each_entry_safe(mode, t, &connector->probed_modes, head)
drm_mode_remove(connector, mode);
list_for_each_entry_safe(mode, t, &connector->modes, head)
drm_mode_remove(connector, mode);
ida_remove(&drm_connector_enum_list[connector->connector_type].ida,
connector->connector_type_id);
drm_mode_object_put(dev, &connector->base);
kfree(connector->name);
connector->name = NULL;
list_del(&connector->head);
dev->mode_config.num_connector--;
}
int drm_connector_register(struct drm_connector *connector)
{
int ret;
drm_mode_object_register(connector->dev, &connector->base);
ret = drm_sysfs_connector_add(connector);
if (ret)
return ret;
ret = drm_debugfs_connector_add(connector);
if (ret) {
drm_sysfs_connector_remove(connector);
return ret;
}
return 0;
}
void drm_connector_unregister(struct drm_connector *connector)
{
drm_sysfs_connector_remove(connector);
drm_debugfs_connector_remove(connector);
}
void drm_connector_unplug_all(struct drm_device *dev)
{
struct drm_connector *connector;
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
drm_connector_unregister(connector);
}
int drm_bridge_init(struct drm_device *dev, struct drm_bridge *bridge,
const struct drm_bridge_funcs *funcs)
{
int ret;
drm_modeset_lock_all(dev);
ret = drm_mode_object_get(dev, &bridge->base, DRM_MODE_OBJECT_BRIDGE);
if (ret)
goto out;
bridge->dev = dev;
bridge->funcs = funcs;
list_add_tail(&bridge->head, &dev->mode_config.bridge_list);
dev->mode_config.num_bridge++;
out:
drm_modeset_unlock_all(dev);
return ret;
}
void drm_bridge_cleanup(struct drm_bridge *bridge)
{
struct drm_device *dev = bridge->dev;
drm_modeset_lock_all(dev);
drm_mode_object_put(dev, &bridge->base);
list_del(&bridge->head);
dev->mode_config.num_bridge--;
drm_modeset_unlock_all(dev);
}
int drm_encoder_init(struct drm_device *dev,
struct drm_encoder *encoder,
const struct drm_encoder_funcs *funcs,
int encoder_type)
{
int ret;
drm_modeset_lock_all(dev);
ret = drm_mode_object_get(dev, &encoder->base, DRM_MODE_OBJECT_ENCODER);
if (ret)
goto out_unlock;
encoder->dev = dev;
encoder->encoder_type = encoder_type;
encoder->funcs = funcs;
encoder->name = kasprintf(GFP_KERNEL, "%s-%d",
drm_encoder_enum_list[encoder_type].name,
encoder->base.id);
if (!encoder->name) {
ret = -ENOMEM;
goto out_put;
}
list_add_tail(&encoder->head, &dev->mode_config.encoder_list);
dev->mode_config.num_encoder++;
out_put:
if (ret)
drm_mode_object_put(dev, &encoder->base);
out_unlock:
drm_modeset_unlock_all(dev);
return ret;
}
void drm_encoder_cleanup(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
drm_modeset_lock_all(dev);
drm_mode_object_put(dev, &encoder->base);
kfree(encoder->name);
encoder->name = NULL;
list_del(&encoder->head);
dev->mode_config.num_encoder--;
drm_modeset_unlock_all(dev);
}
int drm_universal_plane_init(struct drm_device *dev, struct drm_plane *plane,
unsigned long possible_crtcs,
const struct drm_plane_funcs *funcs,
const uint32_t *formats, uint32_t format_count,
enum drm_plane_type type)
{
int ret;
drm_modeset_lock_all(dev);
ret = drm_mode_object_get(dev, &plane->base, DRM_MODE_OBJECT_PLANE);
if (ret)
goto out;
plane->base.properties = &plane->properties;
plane->dev = dev;
plane->funcs = funcs;
plane->format_types = kmalloc(sizeof(uint32_t) * format_count,
GFP_KERNEL);
if (!plane->format_types) {
DRM_DEBUG_KMS("out of memory when allocating plane\n");
drm_mode_object_put(dev, &plane->base);
ret = -ENOMEM;
goto out;
}
memcpy(plane->format_types, formats, format_count * sizeof(uint32_t));
plane->format_count = format_count;
plane->possible_crtcs = possible_crtcs;
plane->type = type;
list_add_tail(&plane->head, &dev->mode_config.plane_list);
dev->mode_config.num_total_plane++;
if (plane->type == DRM_PLANE_TYPE_OVERLAY)
dev->mode_config.num_overlay_plane++;
drm_object_attach_property(&plane->base,
dev->mode_config.plane_type_property,
plane->type);
out:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_plane_init(struct drm_device *dev, struct drm_plane *plane,
unsigned long possible_crtcs,
const struct drm_plane_funcs *funcs,
const uint32_t *formats, uint32_t format_count,
bool is_primary)
{
enum drm_plane_type type;
type = is_primary ? DRM_PLANE_TYPE_PRIMARY : DRM_PLANE_TYPE_OVERLAY;
return drm_universal_plane_init(dev, plane, possible_crtcs, funcs,
formats, format_count, type);
}
void drm_plane_cleanup(struct drm_plane *plane)
{
struct drm_device *dev = plane->dev;
drm_modeset_lock_all(dev);
kfree(plane->format_types);
drm_mode_object_put(dev, &plane->base);
BUG_ON(list_empty(&plane->head));
list_del(&plane->head);
dev->mode_config.num_total_plane--;
if (plane->type == DRM_PLANE_TYPE_OVERLAY)
dev->mode_config.num_overlay_plane--;
drm_modeset_unlock_all(dev);
}
void drm_plane_force_disable(struct drm_plane *plane)
{
struct drm_framebuffer *old_fb = plane->fb;
int ret;
if (!old_fb)
return;
ret = plane->funcs->disable_plane(plane);
if (ret) {
DRM_ERROR("failed to disable plane with busy fb\n");
return;
}
__drm_framebuffer_unreference(old_fb);
plane->fb = NULL;
plane->crtc = NULL;
}
static int drm_mode_create_standard_connector_properties(struct drm_device *dev)
{
struct drm_property *edid;
struct drm_property *dpms;
struct drm_property *dev_path;
edid = drm_property_create(dev, DRM_MODE_PROP_BLOB |
DRM_MODE_PROP_IMMUTABLE,
"EDID", 0);
dev->mode_config.edid_property = edid;
dpms = drm_property_create_enum(dev, 0,
"DPMS", drm_dpms_enum_list,
ARRAY_SIZE(drm_dpms_enum_list));
dev->mode_config.dpms_property = dpms;
dev_path = drm_property_create(dev,
DRM_MODE_PROP_BLOB |
DRM_MODE_PROP_IMMUTABLE,
"PATH", 0);
dev->mode_config.path_property = dev_path;
return 0;
}
static int drm_mode_create_standard_plane_properties(struct drm_device *dev)
{
struct drm_property *type;
type = drm_property_create_enum(dev, DRM_MODE_PROP_IMMUTABLE,
"type", drm_plane_type_enum_list,
ARRAY_SIZE(drm_plane_type_enum_list));
dev->mode_config.plane_type_property = type;
return 0;
}
int drm_mode_create_dvi_i_properties(struct drm_device *dev)
{
struct drm_property *dvi_i_selector;
struct drm_property *dvi_i_subconnector;
if (dev->mode_config.dvi_i_select_subconnector_property)
return 0;
dvi_i_selector =
drm_property_create_enum(dev, 0,
"select subconnector",
drm_dvi_i_select_enum_list,
ARRAY_SIZE(drm_dvi_i_select_enum_list));
dev->mode_config.dvi_i_select_subconnector_property = dvi_i_selector;
dvi_i_subconnector = drm_property_create_enum(dev, DRM_MODE_PROP_IMMUTABLE,
"subconnector",
drm_dvi_i_subconnector_enum_list,
ARRAY_SIZE(drm_dvi_i_subconnector_enum_list));
dev->mode_config.dvi_i_subconnector_property = dvi_i_subconnector;
return 0;
}
int drm_mode_create_tv_properties(struct drm_device *dev, int num_modes,
char *modes[])
{
struct drm_property *tv_selector;
struct drm_property *tv_subconnector;
int i;
if (dev->mode_config.tv_select_subconnector_property)
return 0;
tv_selector = drm_property_create_enum(dev, 0,
"select subconnector",
drm_tv_select_enum_list,
ARRAY_SIZE(drm_tv_select_enum_list));
dev->mode_config.tv_select_subconnector_property = tv_selector;
tv_subconnector =
drm_property_create_enum(dev, DRM_MODE_PROP_IMMUTABLE,
"subconnector",
drm_tv_subconnector_enum_list,
ARRAY_SIZE(drm_tv_subconnector_enum_list));
dev->mode_config.tv_subconnector_property = tv_subconnector;
dev->mode_config.tv_left_margin_property =
drm_property_create_range(dev, 0, "left margin", 0, 100);
dev->mode_config.tv_right_margin_property =
drm_property_create_range(dev, 0, "right margin", 0, 100);
dev->mode_config.tv_top_margin_property =
drm_property_create_range(dev, 0, "top margin", 0, 100);
dev->mode_config.tv_bottom_margin_property =
drm_property_create_range(dev, 0, "bottom margin", 0, 100);
dev->mode_config.tv_mode_property =
drm_property_create(dev, DRM_MODE_PROP_ENUM,
"mode", num_modes);
for (i = 0; i < num_modes; i++)
drm_property_add_enum(dev->mode_config.tv_mode_property, i,
i, modes[i]);
dev->mode_config.tv_brightness_property =
drm_property_create_range(dev, 0, "brightness", 0, 100);
dev->mode_config.tv_contrast_property =
drm_property_create_range(dev, 0, "contrast", 0, 100);
dev->mode_config.tv_flicker_reduction_property =
drm_property_create_range(dev, 0, "flicker reduction", 0, 100);
dev->mode_config.tv_overscan_property =
drm_property_create_range(dev, 0, "overscan", 0, 100);
dev->mode_config.tv_saturation_property =
drm_property_create_range(dev, 0, "saturation", 0, 100);
dev->mode_config.tv_hue_property =
drm_property_create_range(dev, 0, "hue", 0, 100);
return 0;
}
int drm_mode_create_scaling_mode_property(struct drm_device *dev)
{
struct drm_property *scaling_mode;
if (dev->mode_config.scaling_mode_property)
return 0;
scaling_mode =
drm_property_create_enum(dev, 0, "scaling mode",
drm_scaling_mode_enum_list,
ARRAY_SIZE(drm_scaling_mode_enum_list));
dev->mode_config.scaling_mode_property = scaling_mode;
return 0;
}
int drm_mode_create_aspect_ratio_property(struct drm_device *dev)
{
if (dev->mode_config.aspect_ratio_property)
return 0;
dev->mode_config.aspect_ratio_property =
drm_property_create_enum(dev, 0, "aspect ratio",
drm_aspect_ratio_enum_list,
ARRAY_SIZE(drm_aspect_ratio_enum_list));
if (dev->mode_config.aspect_ratio_property == NULL)
return -ENOMEM;
return 0;
}
int drm_mode_create_dirty_info_property(struct drm_device *dev)
{
struct drm_property *dirty_info;
if (dev->mode_config.dirty_info_property)
return 0;
dirty_info =
drm_property_create_enum(dev, DRM_MODE_PROP_IMMUTABLE,
"dirty",
drm_dirty_info_enum_list,
ARRAY_SIZE(drm_dirty_info_enum_list));
dev->mode_config.dirty_info_property = dirty_info;
return 0;
}
static int drm_mode_group_init(struct drm_device *dev, struct drm_mode_group *group)
{
uint32_t total_objects = 0;
total_objects += dev->mode_config.num_crtc;
total_objects += dev->mode_config.num_connector;
total_objects += dev->mode_config.num_encoder;
total_objects += dev->mode_config.num_bridge;
group->id_list = kzalloc(total_objects * sizeof(uint32_t), GFP_KERNEL);
if (!group->id_list)
return -ENOMEM;
group->num_crtcs = 0;
group->num_connectors = 0;
group->num_encoders = 0;
group->num_bridges = 0;
return 0;
}
void drm_mode_group_destroy(struct drm_mode_group *group)
{
kfree(group->id_list);
group->id_list = NULL;
}
int drm_mode_group_init_legacy_group(struct drm_device *dev,
struct drm_mode_group *group)
{
struct drm_crtc *crtc;
struct drm_encoder *encoder;
struct drm_connector *connector;
struct drm_bridge *bridge;
int ret;
if ((ret = drm_mode_group_init(dev, group)))
return ret;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
group->id_list[group->num_crtcs++] = crtc->base.id;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head)
group->id_list[group->num_crtcs + group->num_encoders++] =
encoder->base.id;
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
group->id_list[group->num_crtcs + group->num_encoders +
group->num_connectors++] = connector->base.id;
list_for_each_entry(bridge, &dev->mode_config.bridge_list, head)
group->id_list[group->num_crtcs + group->num_encoders +
group->num_connectors + group->num_bridges++] =
bridge->base.id;
return 0;
}
void drm_reinit_primary_mode_group(struct drm_device *dev)
{
drm_modeset_lock_all(dev);
drm_mode_group_destroy(&dev->primary->mode_group);
drm_mode_group_init_legacy_group(dev, &dev->primary->mode_group);
drm_modeset_unlock_all(dev);
}
static void drm_crtc_convert_to_umode(struct drm_mode_modeinfo *out,
const struct drm_display_mode *in)
{
WARN(in->hdisplay > USHRT_MAX || in->hsync_start > USHRT_MAX ||
in->hsync_end > USHRT_MAX || in->htotal > USHRT_MAX ||
in->hskew > USHRT_MAX || in->vdisplay > USHRT_MAX ||
in->vsync_start > USHRT_MAX || in->vsync_end > USHRT_MAX ||
in->vtotal > USHRT_MAX || in->vscan > USHRT_MAX,
"timing values too large for mode info\n");
out->clock = in->clock;
out->hdisplay = in->hdisplay;
out->hsync_start = in->hsync_start;
out->hsync_end = in->hsync_end;
out->htotal = in->htotal;
out->hskew = in->hskew;
out->vdisplay = in->vdisplay;
out->vsync_start = in->vsync_start;
out->vsync_end = in->vsync_end;
out->vtotal = in->vtotal;
out->vscan = in->vscan;
out->vrefresh = in->vrefresh;
out->flags = in->flags;
out->type = in->type;
strncpy(out->name, in->name, DRM_DISPLAY_MODE_LEN);
out->name[DRM_DISPLAY_MODE_LEN-1] = 0;
}
static int drm_crtc_convert_umode(struct drm_display_mode *out,
const struct drm_mode_modeinfo *in)
{
if (in->clock > INT_MAX || in->vrefresh > INT_MAX)
return -ERANGE;
if ((in->flags & DRM_MODE_FLAG_3D_MASK) > DRM_MODE_FLAG_3D_MAX)
return -EINVAL;
out->clock = in->clock;
out->hdisplay = in->hdisplay;
out->hsync_start = in->hsync_start;
out->hsync_end = in->hsync_end;
out->htotal = in->htotal;
out->hskew = in->hskew;
out->vdisplay = in->vdisplay;
out->vsync_start = in->vsync_start;
out->vsync_end = in->vsync_end;
out->vtotal = in->vtotal;
out->vscan = in->vscan;
out->vrefresh = in->vrefresh;
out->flags = in->flags;
out->type = in->type;
strncpy(out->name, in->name, DRM_DISPLAY_MODE_LEN);
out->name[DRM_DISPLAY_MODE_LEN-1] = 0;
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
int copied = 0, i;
uint32_t __user *fb_id;
uint32_t __user *crtc_id;
uint32_t __user *connector_id;
uint32_t __user *encoder_id;
struct drm_mode_group *mode_group;
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
drm_modeset_lock_all(dev);
if (!drm_is_primary_client(file_priv)) {
mode_group = NULL;
list_for_each(lh, &dev->mode_config.crtc_list)
crtc_count++;
list_for_each(lh, &dev->mode_config.connector_list)
connector_count++;
list_for_each(lh, &dev->mode_config.encoder_list)
encoder_count++;
} else {
mode_group = &file_priv->master->minor->mode_group;
crtc_count = mode_group->num_crtcs;
connector_count = mode_group->num_connectors;
encoder_count = mode_group->num_encoders;
}
card_res->max_height = dev->mode_config.max_height;
card_res->min_height = dev->mode_config.min_height;
card_res->max_width = dev->mode_config.max_width;
card_res->min_width = dev->mode_config.min_width;
if (card_res->count_crtcs >= crtc_count) {
copied = 0;
crtc_id = (uint32_t __user *)(unsigned long)card_res->crtc_id_ptr;
if (!mode_group) {
list_for_each_entry(crtc, &dev->mode_config.crtc_list,
head) {
DRM_DEBUG_KMS("[CRTC:%d]\n", crtc->base.id);
if (put_user(crtc->base.id, crtc_id + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
} else {
for (i = 0; i < mode_group->num_crtcs; i++) {
if (put_user(mode_group->id_list[i],
crtc_id + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
}
card_res->count_crtcs = crtc_count;
if (card_res->count_encoders >= encoder_count) {
copied = 0;
encoder_id = (uint32_t __user *)(unsigned long)card_res->encoder_id_ptr;
if (!mode_group) {
list_for_each_entry(encoder,
&dev->mode_config.encoder_list,
head) {
DRM_DEBUG_KMS("[ENCODER:%d:%s]\n", encoder->base.id,
encoder->name);
if (put_user(encoder->base.id, encoder_id +
copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
} else {
for (i = mode_group->num_crtcs; i < mode_group->num_crtcs + mode_group->num_encoders; i++) {
if (put_user(mode_group->id_list[i],
encoder_id + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
}
card_res->count_encoders = encoder_count;
if (card_res->count_connectors >= connector_count) {
copied = 0;
connector_id = (uint32_t __user *)(unsigned long)card_res->connector_id_ptr;
if (!mode_group) {
list_for_each_entry(connector,
&dev->mode_config.connector_list,
head) {
DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n",
connector->base.id,
connector->name);
if (put_user(connector->base.id,
connector_id + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
} else {
int start = mode_group->num_crtcs +
mode_group->num_encoders;
for (i = start; i < start + mode_group->num_connectors; i++) {
if (put_user(mode_group->id_list[i],
connector_id + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
}
card_res->count_connectors = connector_count;
DRM_DEBUG_KMS("CRTC[%d] CONNECTORS[%d] ENCODERS[%d]\n", card_res->count_crtcs,
card_res->count_connectors, card_res->count_encoders);
out:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_mode_getcrtc(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_crtc *crtc_resp = data;
struct drm_crtc *crtc;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
crtc = drm_crtc_find(dev, crtc_resp->crtc_id);
if (!crtc) {
ret = -ENOENT;
goto out;
}
crtc_resp->x = crtc->x;
crtc_resp->y = crtc->y;
crtc_resp->gamma_size = crtc->gamma_size;
if (crtc->primary->fb)
crtc_resp->fb_id = crtc->primary->fb->base.id;
else
crtc_resp->fb_id = 0;
if (crtc->enabled) {
drm_crtc_convert_to_umode(&crtc_resp->mode, &crtc->mode);
crtc_resp->mode_valid = 1;
} else {
crtc_resp->mode_valid = 0;
}
out:
drm_modeset_unlock_all(dev);
return ret;
}
static bool drm_mode_expose_to_userspace(const struct drm_display_mode *mode,
const struct drm_file *file_priv)
{
if (!file_priv->stereo_allowed && drm_mode_is_stereo(mode))
return false;
return true;
}
int drm_mode_getconnector(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_get_connector *out_resp = data;
struct drm_connector *connector;
struct drm_display_mode *mode;
int mode_count = 0;
int props_count = 0;
int encoders_count = 0;
int ret = 0;
int copied = 0;
int i;
struct drm_mode_modeinfo u_mode;
struct drm_mode_modeinfo __user *mode_ptr;
uint32_t __user *prop_ptr;
uint64_t __user *prop_values;
uint32_t __user *encoder_ptr;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
memset(&u_mode, 0, sizeof(struct drm_mode_modeinfo));
DRM_DEBUG_KMS("[CONNECTOR:%d:?]\n", out_resp->connector_id);
mutex_lock(&dev->mode_config.mutex);
connector = drm_connector_find(dev, out_resp->connector_id);
if (!connector) {
ret = -ENOENT;
goto out;
}
props_count = connector->properties.count;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] != 0) {
encoders_count++;
}
}
if (out_resp->count_modes == 0) {
connector->funcs->fill_modes(connector,
dev->mode_config.max_width,
dev->mode_config.max_height);
}
list_for_each_entry(mode, &connector->modes, head)
if (drm_mode_expose_to_userspace(mode, file_priv))
mode_count++;
out_resp->connector_id = connector->base.id;
out_resp->connector_type = connector->connector_type;
out_resp->connector_type_id = connector->connector_type_id;
out_resp->mm_width = connector->display_info.width_mm;
out_resp->mm_height = connector->display_info.height_mm;
out_resp->subpixel = connector->display_info.subpixel_order;
out_resp->connection = connector->status;
drm_modeset_lock(&dev->mode_config.connection_mutex, NULL);
if (connector->encoder)
out_resp->encoder_id = connector->encoder->base.id;
else
out_resp->encoder_id = 0;
drm_modeset_unlock(&dev->mode_config.connection_mutex);
if ((out_resp->count_modes >= mode_count) && mode_count) {
copied = 0;
mode_ptr = (struct drm_mode_modeinfo __user *)(unsigned long)out_resp->modes_ptr;
list_for_each_entry(mode, &connector->modes, head) {
if (!drm_mode_expose_to_userspace(mode, file_priv))
continue;
drm_crtc_convert_to_umode(&u_mode, mode);
if (copy_to_user(mode_ptr + copied,
&u_mode, sizeof(u_mode))) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
out_resp->count_modes = mode_count;
if ((out_resp->count_props >= props_count) && props_count) {
copied = 0;
prop_ptr = (uint32_t __user *)(unsigned long)(out_resp->props_ptr);
prop_values = (uint64_t __user *)(unsigned long)(out_resp->prop_values_ptr);
for (i = 0; i < connector->properties.count; i++) {
if (put_user(connector->properties.ids[i],
prop_ptr + copied)) {
ret = -EFAULT;
goto out;
}
if (put_user(connector->properties.values[i],
prop_values + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
out_resp->count_props = props_count;
if ((out_resp->count_encoders >= encoders_count) && encoders_count) {
copied = 0;
encoder_ptr = (uint32_t __user *)(unsigned long)(out_resp->encoders_ptr);
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] != 0) {
if (put_user(connector->encoder_ids[i],
encoder_ptr + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
}
out_resp->count_encoders = encoders_count;
out:
mutex_unlock(&dev->mode_config.mutex);
return ret;
}
int drm_mode_getencoder(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_get_encoder *enc_resp = data;
struct drm_encoder *encoder;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
encoder = drm_encoder_find(dev, enc_resp->encoder_id);
if (!encoder) {
ret = -ENOENT;
goto out;
}
if (encoder->crtc)
enc_resp->crtc_id = encoder->crtc->base.id;
else
enc_resp->crtc_id = 0;
enc_resp->encoder_type = encoder->encoder_type;
enc_resp->encoder_id = encoder->base.id;
enc_resp->possible_crtcs = encoder->possible_crtcs;
enc_resp->possible_clones = encoder->possible_clones;
out:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_mode_getplane_res(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_get_plane_res *plane_resp = data;
struct drm_mode_config *config;
struct drm_plane *plane;
uint32_t __user *plane_ptr;
int copied = 0, ret = 0;
unsigned num_planes;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
config = &dev->mode_config;
if (file_priv->universal_planes)
num_planes = config->num_total_plane;
else
num_planes = config->num_overlay_plane;
if (num_planes &&
(plane_resp->count_planes >= num_planes)) {
plane_ptr = (uint32_t __user *)(unsigned long)plane_resp->plane_id_ptr;
list_for_each_entry(plane, &config->plane_list, head) {
if (plane->type != DRM_PLANE_TYPE_OVERLAY &&
!file_priv->universal_planes)
continue;
if (put_user(plane->base.id, plane_ptr + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
plane_resp->count_planes = num_planes;
out:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_mode_getplane(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_get_plane *plane_resp = data;
struct drm_plane *plane;
uint32_t __user *format_ptr;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
plane = drm_plane_find(dev, plane_resp->plane_id);
if (!plane) {
ret = -ENOENT;
goto out;
}
if (plane->crtc)
plane_resp->crtc_id = plane->crtc->base.id;
else
plane_resp->crtc_id = 0;
if (plane->fb)
plane_resp->fb_id = plane->fb->base.id;
else
plane_resp->fb_id = 0;
plane_resp->plane_id = plane->base.id;
plane_resp->possible_crtcs = plane->possible_crtcs;
plane_resp->gamma_size = 0;
if (plane->format_count &&
(plane_resp->count_format_types >= plane->format_count)) {
format_ptr = (uint32_t __user *)(unsigned long)plane_resp->format_type_ptr;
if (copy_to_user(format_ptr,
plane->format_types,
sizeof(uint32_t) * plane->format_count)) {
ret = -EFAULT;
goto out;
}
}
plane_resp->count_format_types = plane->format_count;
out:
drm_modeset_unlock_all(dev);
return ret;
}
static int setplane_internal(struct drm_plane *plane,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int32_t crtc_x, int32_t crtc_y,
uint32_t crtc_w, uint32_t crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct drm_device *dev = plane->dev;
struct drm_framebuffer *old_fb = NULL;
int ret = 0;
unsigned int fb_width, fb_height;
int i;
if (!fb) {
drm_modeset_lock_all(dev);
old_fb = plane->fb;
ret = plane->funcs->disable_plane(plane);
if (!ret) {
plane->crtc = NULL;
plane->fb = NULL;
} else {
old_fb = NULL;
}
drm_modeset_unlock_all(dev);
goto out;
}
if (!(plane->possible_crtcs & drm_crtc_mask(crtc))) {
DRM_DEBUG_KMS("Invalid crtc for plane\n");
ret = -EINVAL;
goto out;
}
for (i = 0; i < plane->format_count; i++)
if (fb->pixel_format == plane->format_types[i])
break;
if (i == plane->format_count) {
DRM_DEBUG_KMS("Invalid pixel format %s\n",
drm_get_format_name(fb->pixel_format));
ret = -EINVAL;
goto out;
}
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
ret = -ENOSPC;
goto out;
}
drm_modeset_lock_all(dev);
old_fb = plane->fb;
ret = plane->funcs->update_plane(plane, crtc, fb,
crtc_x, crtc_y, crtc_w, crtc_h,
src_x, src_y, src_w, src_h);
if (!ret) {
plane->crtc = crtc;
plane->fb = fb;
fb = NULL;
} else {
old_fb = NULL;
}
drm_modeset_unlock_all(dev);
out:
if (fb)
drm_framebuffer_unreference(fb);
if (old_fb)
drm_framebuffer_unreference(old_fb);
return ret;
}
int drm_mode_setplane(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_set_plane *plane_req = data;
struct drm_mode_object *obj;
struct drm_plane *plane;
struct drm_crtc *crtc = NULL;
struct drm_framebuffer *fb = NULL;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (plane_req->crtc_w > INT_MAX ||
plane_req->crtc_x > INT_MAX - (int32_t) plane_req->crtc_w ||
plane_req->crtc_h > INT_MAX ||
plane_req->crtc_y > INT_MAX - (int32_t) plane_req->crtc_h) {
DRM_DEBUG_KMS("Invalid CRTC coordinates %ux%u+%d+%d\n",
plane_req->crtc_w, plane_req->crtc_h,
plane_req->crtc_x, plane_req->crtc_y);
return -ERANGE;
}
obj = drm_mode_object_find(dev, plane_req->plane_id,
DRM_MODE_OBJECT_PLANE);
if (!obj) {
DRM_DEBUG_KMS("Unknown plane ID %d\n",
plane_req->plane_id);
return -ENOENT;
}
plane = obj_to_plane(obj);
if (plane_req->fb_id) {
fb = drm_framebuffer_lookup(dev, plane_req->fb_id);
if (!fb) {
DRM_DEBUG_KMS("Unknown framebuffer ID %d\n",
plane_req->fb_id);
return -ENOENT;
}
obj = drm_mode_object_find(dev, plane_req->crtc_id,
DRM_MODE_OBJECT_CRTC);
if (!obj) {
DRM_DEBUG_KMS("Unknown crtc ID %d\n",
plane_req->crtc_id);
return -ENOENT;
}
crtc = obj_to_crtc(obj);
}
return setplane_internal(plane, crtc, fb,
plane_req->crtc_x, plane_req->crtc_y,
plane_req->crtc_w, plane_req->crtc_h,
plane_req->src_x, plane_req->src_y,
plane_req->src_w, plane_req->src_h);
}
int drm_mode_set_config_internal(struct drm_mode_set *set)
{
struct drm_crtc *crtc = set->crtc;
struct drm_framebuffer *fb;
struct drm_crtc *tmp;
int ret;
list_for_each_entry(tmp, &crtc->dev->mode_config.crtc_list, head)
tmp->old_fb = tmp->primary->fb;
fb = set->fb;
ret = crtc->funcs->set_config(set);
if (ret == 0) {
crtc->primary->crtc = crtc;
crtc->primary->fb = fb;
}
list_for_each_entry(tmp, &crtc->dev->mode_config.crtc_list, head) {
if (tmp->primary->fb)
drm_framebuffer_reference(tmp->primary->fb);
if (tmp->old_fb)
drm_framebuffer_unreference(tmp->old_fb);
}
return ret;
}
int drm_crtc_check_viewport(const struct drm_crtc *crtc,
int x, int y,
const struct drm_display_mode *mode,
const struct drm_framebuffer *fb)
{
int hdisplay, vdisplay;
hdisplay = mode->hdisplay;
vdisplay = mode->vdisplay;
if (drm_mode_is_stereo(mode)) {
struct drm_display_mode adjusted = *mode;
drm_mode_set_crtcinfo(&adjusted, CRTC_STEREO_DOUBLE);
hdisplay = adjusted.crtc_hdisplay;
vdisplay = adjusted.crtc_vdisplay;
}
if (crtc->invert_dimensions)
swap(hdisplay, vdisplay);
if (hdisplay > fb->width ||
vdisplay > fb->height ||
x > fb->width - hdisplay ||
y > fb->height - vdisplay) {
DRM_DEBUG_KMS("Invalid fb size %ux%u for CRTC viewport %ux%u+%d+%d%s.\n",
fb->width, fb->height, hdisplay, vdisplay, x, y,
crtc->invert_dimensions ? " (inverted)" : "");
return -ENOSPC;
}
return 0;
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
if (crtc_req->x > INT_MAX || crtc_req->y > INT_MAX)
return -ERANGE;
drm_modeset_lock_all(dev);
crtc = drm_crtc_find(dev, crtc_req->crtc_id);
if (!crtc) {
DRM_DEBUG_KMS("Unknown CRTC ID %d\n", crtc_req->crtc_id);
ret = -ENOENT;
goto out;
}
DRM_DEBUG_KMS("[CRTC:%d]\n", crtc->base.id);
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
ret = drm_crtc_convert_umode(mode, &crtc_req->mode);
if (ret) {
DRM_DEBUG_KMS("Invalid mode\n");
goto out;
}
drm_mode_set_crtcinfo(mode, CRTC_INTERLACE_HALVE_V);
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
connector_set = kmalloc(crtc_req->count_connectors *
sizeof(struct drm_connector *),
GFP_KERNEL);
if (!connector_set) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < crtc_req->count_connectors; i++) {
set_connectors_ptr = (uint32_t __user *)(unsigned long)crtc_req->set_connectors_ptr;
if (get_user(out_id, &set_connectors_ptr[i])) {
ret = -EFAULT;
goto out;
}
connector = drm_connector_find(dev, out_id);
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
kfree(connector_set);
drm_mode_destroy(dev, mode);
drm_modeset_unlock_all(dev);
return ret;
}
static int drm_mode_cursor_universal(struct drm_crtc *crtc,
struct drm_mode_cursor2 *req,
struct drm_file *file_priv)
{
struct drm_device *dev = crtc->dev;
struct drm_framebuffer *fb = NULL;
struct drm_mode_fb_cmd2 fbreq = {
.width = req->width,
.height = req->height,
.pixel_format = DRM_FORMAT_ARGB8888,
.pitches = { req->width * 4 },
.handles = { req->handle },
};
int32_t crtc_x, crtc_y;
uint32_t crtc_w = 0, crtc_h = 0;
uint32_t src_w = 0, src_h = 0;
int ret = 0;
BUG_ON(!crtc->cursor);
if (req->flags & DRM_MODE_CURSOR_BO) {
if (req->handle) {
fb = add_framebuffer_internal(dev, &fbreq, file_priv);
if (IS_ERR(fb)) {
DRM_DEBUG_KMS("failed to wrap cursor buffer in drm framebuffer\n");
return PTR_ERR(fb);
}
drm_framebuffer_reference(fb);
} else {
fb = NULL;
}
} else {
mutex_lock(&dev->mode_config.mutex);
fb = crtc->cursor->fb;
if (fb)
drm_framebuffer_reference(fb);
mutex_unlock(&dev->mode_config.mutex);
}
if (req->flags & DRM_MODE_CURSOR_MOVE) {
crtc_x = req->x;
crtc_y = req->y;
} else {
crtc_x = crtc->cursor_x;
crtc_y = crtc->cursor_y;
}
if (fb) {
crtc_w = fb->width;
crtc_h = fb->height;
src_w = fb->width << 16;
src_h = fb->height << 16;
}
ret = setplane_internal(crtc->cursor, crtc, fb,
crtc_x, crtc_y, crtc_w, crtc_h,
0, 0, src_w, src_h);
if (ret == 0 && req->flags & DRM_MODE_CURSOR_MOVE) {
crtc->cursor_x = req->x;
crtc->cursor_y = req->y;
}
return ret;
}
static int drm_mode_cursor_common(struct drm_device *dev,
struct drm_mode_cursor2 *req,
struct drm_file *file_priv)
{
struct drm_crtc *crtc;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (!req->flags || (~DRM_MODE_CURSOR_FLAGS & req->flags))
return -EINVAL;
crtc = drm_crtc_find(dev, req->crtc_id);
if (!crtc) {
DRM_DEBUG_KMS("Unknown CRTC ID %d\n", req->crtc_id);
return -ENOENT;
}
if (crtc->cursor)
return drm_mode_cursor_universal(crtc, req, file_priv);
drm_modeset_lock(&crtc->mutex, NULL);
if (req->flags & DRM_MODE_CURSOR_BO) {
if (!crtc->funcs->cursor_set && !crtc->funcs->cursor_set2) {
ret = -ENXIO;
goto out;
}
if (crtc->funcs->cursor_set2)
ret = crtc->funcs->cursor_set2(crtc, file_priv, req->handle,
req->width, req->height, req->hot_x, req->hot_y);
else
ret = crtc->funcs->cursor_set(crtc, file_priv, req->handle,
req->width, req->height);
}
if (req->flags & DRM_MODE_CURSOR_MOVE) {
if (crtc->funcs->cursor_move) {
ret = crtc->funcs->cursor_move(crtc, req->x, req->y);
} else {
ret = -EFAULT;
goto out;
}
}
out:
drm_modeset_unlock(&crtc->mutex);
return ret;
}
int drm_mode_cursor_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_cursor *req = data;
struct drm_mode_cursor2 new_req;
memcpy(&new_req, req, sizeof(struct drm_mode_cursor));
new_req.hot_x = new_req.hot_y = 0;
return drm_mode_cursor_common(dev, &new_req, file_priv);
}
int drm_mode_cursor2_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_cursor2 *req = data;
return drm_mode_cursor_common(dev, req, file_priv);
}
uint32_t drm_mode_legacy_fb_format(uint32_t bpp, uint32_t depth)
{
uint32_t fmt;
switch (bpp) {
case 8:
fmt = DRM_FORMAT_C8;
break;
case 16:
if (depth == 15)
fmt = DRM_FORMAT_XRGB1555;
else
fmt = DRM_FORMAT_RGB565;
break;
case 24:
fmt = DRM_FORMAT_RGB888;
break;
case 32:
if (depth == 24)
fmt = DRM_FORMAT_XRGB8888;
else if (depth == 30)
fmt = DRM_FORMAT_XRGB2101010;
else
fmt = DRM_FORMAT_ARGB8888;
break;
default:
DRM_ERROR("bad bpp, assuming x8r8g8b8 pixel format\n");
fmt = DRM_FORMAT_XRGB8888;
break;
}
return fmt;
}
int drm_mode_addfb(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_fb_cmd *or = data;
struct drm_mode_fb_cmd2 r = {};
struct drm_mode_config *config = &dev->mode_config;
struct drm_framebuffer *fb;
int ret = 0;
r.fb_id = or->fb_id;
r.width = or->width;
r.height = or->height;
r.pitches[0] = or->pitch;
r.pixel_format = drm_mode_legacy_fb_format(or->bpp, or->depth);
r.handles[0] = or->handle;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if ((config->min_width > r.width) || (r.width > config->max_width))
return -EINVAL;
if ((config->min_height > r.height) || (r.height > config->max_height))
return -EINVAL;
fb = dev->mode_config.funcs->fb_create(dev, file_priv, &r);
if (IS_ERR(fb)) {
DRM_DEBUG_KMS("could not create framebuffer\n");
return PTR_ERR(fb);
}
mutex_lock(&file_priv->fbs_lock);
or->fb_id = fb->base.id;
list_add(&fb->filp_head, &file_priv->fbs);
DRM_DEBUG_KMS("[FB:%d]\n", fb->base.id);
mutex_unlock(&file_priv->fbs_lock);
return ret;
}
static int format_check(const struct drm_mode_fb_cmd2 *r)
{
uint32_t format = r->pixel_format & ~DRM_FORMAT_BIG_ENDIAN;
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
DRM_DEBUG_KMS("invalid pixel format %s\n",
drm_get_format_name(r->pixel_format));
return -EINVAL;
}
}
static int framebuffer_check(const struct drm_mode_fb_cmd2 *r)
{
int ret, hsub, vsub, num_planes, i;
ret = format_check(r);
if (ret) {
DRM_DEBUG_KMS("bad framebuffer format %s\n",
drm_get_format_name(r->pixel_format));
return ret;
}
hsub = drm_format_horz_chroma_subsampling(r->pixel_format);
vsub = drm_format_vert_chroma_subsampling(r->pixel_format);
num_planes = drm_format_num_planes(r->pixel_format);
if (r->width == 0 || r->width % hsub) {
DRM_DEBUG_KMS("bad framebuffer width %u\n", r->height);
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
}
return 0;
}
static struct drm_framebuffer *add_framebuffer_internal(struct drm_device *dev,
struct drm_mode_fb_cmd2 *r,
struct drm_file *file_priv)
{
struct drm_mode_config *config = &dev->mode_config;
struct drm_framebuffer *fb;
int ret;
if (r->flags & ~DRM_MODE_FB_INTERLACED) {
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
ret = framebuffer_check(r);
if (ret)
return ERR_PTR(ret);
fb = dev->mode_config.funcs->fb_create(dev, file_priv, r);
if (IS_ERR(fb)) {
DRM_DEBUG_KMS("could not create framebuffer\n");
return fb;
}
mutex_lock(&file_priv->fbs_lock);
r->fb_id = fb->base.id;
list_add(&fb->filp_head, &file_priv->fbs);
DRM_DEBUG_KMS("[FB:%d]\n", fb->base.id);
mutex_unlock(&file_priv->fbs_lock);
return fb;
}
int drm_mode_addfb2(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_framebuffer *fb;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
fb = add_framebuffer_internal(dev, data, file_priv);
if (IS_ERR(fb))
return PTR_ERR(fb);
return 0;
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
mutex_lock(&file_priv->fbs_lock);
mutex_lock(&dev->mode_config.fb_lock);
fb = __drm_framebuffer_lookup(dev, *id);
if (!fb)
goto fail_lookup;
list_for_each_entry(fbl, &file_priv->fbs, filp_head)
if (fb == fbl)
found = 1;
if (!found)
goto fail_lookup;
__drm_framebuffer_unregister(dev, fb);
list_del_init(&fb->filp_head);
mutex_unlock(&dev->mode_config.fb_lock);
mutex_unlock(&file_priv->fbs_lock);
drm_framebuffer_remove(fb);
return 0;
fail_lookup:
mutex_unlock(&dev->mode_config.fb_lock);
mutex_unlock(&file_priv->fbs_lock);
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
if (file_priv->is_master || capable(CAP_SYS_ADMIN) ||
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
clips = kzalloc(num_clips * sizeof(*clips), GFP_KERNEL);
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
struct drm_device *dev = priv->minor->dev;
struct drm_framebuffer *fb, *tfb;
mutex_lock(&priv->fbs_lock);
list_for_each_entry_safe(fb, tfb, &priv->fbs, filp_head) {
mutex_lock(&dev->mode_config.fb_lock);
__drm_framebuffer_unregister(dev, fb);
mutex_unlock(&dev->mode_config.fb_lock);
list_del_init(&fb->filp_head);
drm_framebuffer_remove(fb);
}
mutex_unlock(&priv->fbs_lock);
}
struct drm_property *drm_property_create(struct drm_device *dev, int flags,
const char *name, int num_values)
{
struct drm_property *property = NULL;
int ret;
property = kzalloc(sizeof(struct drm_property), GFP_KERNEL);
if (!property)
return NULL;
property->dev = dev;
if (num_values) {
property->values = kzalloc(sizeof(uint64_t)*num_values, GFP_KERNEL);
if (!property->values)
goto fail;
}
ret = drm_mode_object_get(dev, &property->base, DRM_MODE_OBJECT_PROPERTY);
if (ret)
goto fail;
property->flags = flags;
property->num_values = num_values;
INIT_LIST_HEAD(&property->enum_blob_list);
if (name) {
strncpy(property->name, name, DRM_PROP_NAME_LEN);
property->name[DRM_PROP_NAME_LEN-1] = '\0';
}
list_add_tail(&property->head, &dev->mode_config.property_list);
WARN_ON(!drm_property_type_valid(property));
return property;
fail:
kfree(property->values);
kfree(property);
return NULL;
}
struct drm_property *drm_property_create_enum(struct drm_device *dev, int flags,
const char *name,
const struct drm_prop_enum_list *props,
int num_values)
{
struct drm_property *property;
int i, ret;
flags |= DRM_MODE_PROP_ENUM;
property = drm_property_create(dev, flags, name, num_values);
if (!property)
return NULL;
for (i = 0; i < num_values; i++) {
ret = drm_property_add_enum(property, i,
props[i].type,
props[i].name);
if (ret) {
drm_property_destroy(dev, property);
return NULL;
}
}
return property;
}
struct drm_property *drm_property_create_bitmask(struct drm_device *dev,
int flags, const char *name,
const struct drm_prop_enum_list *props,
int num_props,
uint64_t supported_bits)
{
struct drm_property *property;
int i, ret, index = 0;
int num_values = hweight64(supported_bits);
flags |= DRM_MODE_PROP_BITMASK;
property = drm_property_create(dev, flags, name, num_values);
if (!property)
return NULL;
for (i = 0; i < num_props; i++) {
if (!(supported_bits & (1ULL << props[i].type)))
continue;
if (WARN_ON(index >= num_values)) {
drm_property_destroy(dev, property);
return NULL;
}
ret = drm_property_add_enum(property, index++,
props[i].type,
props[i].name);
if (ret) {
drm_property_destroy(dev, property);
return NULL;
}
}
return property;
}
static struct drm_property *property_create_range(struct drm_device *dev,
int flags, const char *name,
uint64_t min, uint64_t max)
{
struct drm_property *property;
property = drm_property_create(dev, flags, name, 2);
if (!property)
return NULL;
property->values[0] = min;
property->values[1] = max;
return property;
}
struct drm_property *drm_property_create_range(struct drm_device *dev, int flags,
const char *name,
uint64_t min, uint64_t max)
{
return property_create_range(dev, DRM_MODE_PROP_RANGE | flags,
name, min, max);
}
struct drm_property *drm_property_create_signed_range(struct drm_device *dev,
int flags, const char *name,
int64_t min, int64_t max)
{
return property_create_range(dev, DRM_MODE_PROP_SIGNED_RANGE | flags,
name, I642U64(min), I642U64(max));
}
struct drm_property *drm_property_create_object(struct drm_device *dev,
int flags, const char *name, uint32_t type)
{
struct drm_property *property;
flags |= DRM_MODE_PROP_OBJECT;
property = drm_property_create(dev, flags, name, 1);
if (!property)
return NULL;
property->values[0] = type;
return property;
}
int drm_property_add_enum(struct drm_property *property, int index,
uint64_t value, const char *name)
{
struct drm_property_enum *prop_enum;
if (!(drm_property_type_is(property, DRM_MODE_PROP_ENUM) ||
drm_property_type_is(property, DRM_MODE_PROP_BITMASK)))
return -EINVAL;
if (drm_property_type_is(property, DRM_MODE_PROP_BITMASK) &&
(value > 63))
return -EINVAL;
if (!list_empty(&property->enum_blob_list)) {
list_for_each_entry(prop_enum, &property->enum_blob_list, head) {
if (prop_enum->value == value) {
strncpy(prop_enum->name, name, DRM_PROP_NAME_LEN);
prop_enum->name[DRM_PROP_NAME_LEN-1] = '\0';
return 0;
}
}
}
prop_enum = kzalloc(sizeof(struct drm_property_enum), GFP_KERNEL);
if (!prop_enum)
return -ENOMEM;
strncpy(prop_enum->name, name, DRM_PROP_NAME_LEN);
prop_enum->name[DRM_PROP_NAME_LEN-1] = '\0';
prop_enum->value = value;
property->values[index] = value;
list_add_tail(&prop_enum->head, &property->enum_blob_list);
return 0;
}
void drm_property_destroy(struct drm_device *dev, struct drm_property *property)
{
struct drm_property_enum *prop_enum, *pt;
list_for_each_entry_safe(prop_enum, pt, &property->enum_blob_list, head) {
list_del(&prop_enum->head);
kfree(prop_enum);
}
if (property->num_values)
kfree(property->values);
drm_mode_object_put(dev, &property->base);
list_del(&property->head);
kfree(property);
}
void drm_object_attach_property(struct drm_mode_object *obj,
struct drm_property *property,
uint64_t init_val)
{
int count = obj->properties->count;
if (count == DRM_OBJECT_MAX_PROPERTY) {
WARN(1, "Failed to attach object property (type: 0x%x). Please "
"increase DRM_OBJECT_MAX_PROPERTY by 1 for each time "
"you see this message on the same object type.\n",
obj->type);
return;
}
obj->properties->ids[count] = property->base.id;
obj->properties->values[count] = init_val;
obj->properties->count++;
}
int drm_object_property_set_value(struct drm_mode_object *obj,
struct drm_property *property, uint64_t val)
{
int i;
for (i = 0; i < obj->properties->count; i++) {
if (obj->properties->ids[i] == property->base.id) {
obj->properties->values[i] = val;
return 0;
}
}
return -EINVAL;
}
int drm_object_property_get_value(struct drm_mode_object *obj,
struct drm_property *property, uint64_t *val)
{
int i;
for (i = 0; i < obj->properties->count; i++) {
if (obj->properties->ids[i] == property->base.id) {
*val = obj->properties->values[i];
return 0;
}
}
return -EINVAL;
}
int drm_mode_getproperty_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_get_property *out_resp = data;
struct drm_property *property;
int enum_count = 0;
int blob_count = 0;
int value_count = 0;
int ret = 0, i;
int copied;
struct drm_property_enum *prop_enum;
struct drm_mode_property_enum __user *enum_ptr;
struct drm_property_blob *prop_blob;
uint32_t __user *blob_id_ptr;
uint64_t __user *values_ptr;
uint32_t __user *blob_length_ptr;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
property = drm_property_find(dev, out_resp->prop_id);
if (!property) {
ret = -ENOENT;
goto done;
}
if (drm_property_type_is(property, DRM_MODE_PROP_ENUM) ||
drm_property_type_is(property, DRM_MODE_PROP_BITMASK)) {
list_for_each_entry(prop_enum, &property->enum_blob_list, head)
enum_count++;
} else if (drm_property_type_is(property, DRM_MODE_PROP_BLOB)) {
list_for_each_entry(prop_blob, &property->enum_blob_list, head)
blob_count++;
}
value_count = property->num_values;
strncpy(out_resp->name, property->name, DRM_PROP_NAME_LEN);
out_resp->name[DRM_PROP_NAME_LEN-1] = 0;
out_resp->flags = property->flags;
if ((out_resp->count_values >= value_count) && value_count) {
values_ptr = (uint64_t __user *)(unsigned long)out_resp->values_ptr;
for (i = 0; i < value_count; i++) {
if (copy_to_user(values_ptr + i, &property->values[i], sizeof(uint64_t))) {
ret = -EFAULT;
goto done;
}
}
}
out_resp->count_values = value_count;
if (drm_property_type_is(property, DRM_MODE_PROP_ENUM) ||
drm_property_type_is(property, DRM_MODE_PROP_BITMASK)) {
if ((out_resp->count_enum_blobs >= enum_count) && enum_count) {
copied = 0;
enum_ptr = (struct drm_mode_property_enum __user *)(unsigned long)out_resp->enum_blob_ptr;
list_for_each_entry(prop_enum, &property->enum_blob_list, head) {
if (copy_to_user(&enum_ptr[copied].value, &prop_enum->value, sizeof(uint64_t))) {
ret = -EFAULT;
goto done;
}
if (copy_to_user(&enum_ptr[copied].name,
&prop_enum->name, DRM_PROP_NAME_LEN)) {
ret = -EFAULT;
goto done;
}
copied++;
}
}
out_resp->count_enum_blobs = enum_count;
}
if (drm_property_type_is(property, DRM_MODE_PROP_BLOB)) {
if ((out_resp->count_enum_blobs >= blob_count) && blob_count) {
copied = 0;
blob_id_ptr = (uint32_t __user *)(unsigned long)out_resp->enum_blob_ptr;
blob_length_ptr = (uint32_t __user *)(unsigned long)out_resp->values_ptr;
list_for_each_entry(prop_blob, &property->enum_blob_list, head) {
if (put_user(prop_blob->base.id, blob_id_ptr + copied)) {
ret = -EFAULT;
goto done;
}
if (put_user(prop_blob->length, blob_length_ptr + copied)) {
ret = -EFAULT;
goto done;
}
copied++;
}
}
out_resp->count_enum_blobs = blob_count;
}
done:
drm_modeset_unlock_all(dev);
return ret;
}
static struct drm_property_blob *drm_property_create_blob(struct drm_device *dev, int length,
void *data)
{
struct drm_property_blob *blob;
int ret;
if (!length || !data)
return NULL;
blob = kzalloc(sizeof(struct drm_property_blob)+length, GFP_KERNEL);
if (!blob)
return NULL;
ret = drm_mode_object_get(dev, &blob->base, DRM_MODE_OBJECT_BLOB);
if (ret) {
kfree(blob);
return NULL;
}
blob->length = length;
memcpy(blob->data, data, length);
list_add_tail(&blob->head, &dev->mode_config.property_blob_list);
return blob;
}
static void drm_property_destroy_blob(struct drm_device *dev,
struct drm_property_blob *blob)
{
drm_mode_object_put(dev, &blob->base);
list_del(&blob->head);
kfree(blob);
}
int drm_mode_getblob_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_get_blob *out_resp = data;
struct drm_property_blob *blob;
int ret = 0;
void __user *blob_ptr;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
blob = drm_property_blob_find(dev, out_resp->blob_id);
if (!blob) {
ret = -ENOENT;
goto done;
}
if (out_resp->length == blob->length) {
blob_ptr = (void __user *)(unsigned long)out_resp->data;
if (copy_to_user(blob_ptr, blob->data, blob->length)){
ret = -EFAULT;
goto done;
}
}
out_resp->length = blob->length;
done:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_mode_connector_set_path_property(struct drm_connector *connector,
char *path)
{
struct drm_device *dev = connector->dev;
int ret, size;
size = strlen(path) + 1;
connector->path_blob_ptr = drm_property_create_blob(connector->dev,
size, path);
if (!connector->path_blob_ptr)
return -EINVAL;
ret = drm_object_property_set_value(&connector->base,
dev->mode_config.path_property,
connector->path_blob_ptr->base.id);
return ret;
}
int drm_mode_connector_update_edid_property(struct drm_connector *connector,
struct edid *edid)
{
struct drm_device *dev = connector->dev;
int ret, size;
if (connector->override_edid)
return 0;
if (connector->edid_blob_ptr)
drm_property_destroy_blob(dev, connector->edid_blob_ptr);
if (!edid) {
connector->edid_blob_ptr = NULL;
ret = drm_object_property_set_value(&connector->base, dev->mode_config.edid_property, 0);
return ret;
}
size = EDID_LENGTH * (1 + edid->extensions);
connector->edid_blob_ptr = drm_property_create_blob(connector->dev,
size, edid);
if (!connector->edid_blob_ptr)
return -EINVAL;
ret = drm_object_property_set_value(&connector->base,
dev->mode_config.edid_property,
connector->edid_blob_ptr->base.id);
return ret;
}
static bool drm_property_change_is_valid(struct drm_property *property,
uint64_t value)
{
if (property->flags & DRM_MODE_PROP_IMMUTABLE)
return false;
if (drm_property_type_is(property, DRM_MODE_PROP_RANGE)) {
if (value < property->values[0] || value > property->values[1])
return false;
return true;
} else if (drm_property_type_is(property, DRM_MODE_PROP_SIGNED_RANGE)) {
int64_t svalue = U642I64(value);
if (svalue < U642I64(property->values[0]) ||
svalue > U642I64(property->values[1]))
return false;
return true;
} else if (drm_property_type_is(property, DRM_MODE_PROP_BITMASK)) {
int i;
uint64_t valid_mask = 0;
for (i = 0; i < property->num_values; i++)
valid_mask |= (1ULL << property->values[i]);
return !(value & ~valid_mask);
} else if (drm_property_type_is(property, DRM_MODE_PROP_BLOB)) {
return true;
} else if (drm_property_type_is(property, DRM_MODE_PROP_OBJECT)) {
struct drm_mode_object *obj;
if (value == 0)
return true;
obj = _object_find(property->dev, value, property->values[0]);
return obj != NULL;
} else {
int i;
for (i = 0; i < property->num_values; i++)
if (property->values[i] == value)
return true;
return false;
}
}
int drm_mode_connector_property_set_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_connector_set_property *conn_set_prop = data;
struct drm_mode_obj_set_property obj_set_prop = {
.value = conn_set_prop->value,
.prop_id = conn_set_prop->prop_id,
.obj_id = conn_set_prop->connector_id,
.obj_type = DRM_MODE_OBJECT_CONNECTOR
};
return drm_mode_obj_set_property_ioctl(dev, &obj_set_prop, file_priv);
}
static int drm_mode_connector_set_obj_prop(struct drm_mode_object *obj,
struct drm_property *property,
uint64_t value)
{
int ret = -EINVAL;
struct drm_connector *connector = obj_to_connector(obj);
if (property == connector->dev->mode_config.dpms_property) {
if (connector->funcs->dpms)
(*connector->funcs->dpms)(connector, (int)value);
ret = 0;
} else if (connector->funcs->set_property)
ret = connector->funcs->set_property(connector, property, value);
if (!ret)
drm_object_property_set_value(&connector->base, property, value);
return ret;
}
static int drm_mode_crtc_set_obj_prop(struct drm_mode_object *obj,
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
static int drm_mode_plane_set_obj_prop(struct drm_mode_object *obj,
struct drm_property *property,
uint64_t value)
{
int ret = -EINVAL;
struct drm_plane *plane = obj_to_plane(obj);
if (plane->funcs->set_property)
ret = plane->funcs->set_property(plane, property, value);
if (!ret)
drm_object_property_set_value(obj, property, value);
return ret;
}
int drm_mode_obj_get_properties_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_obj_get_properties *arg = data;
struct drm_mode_object *obj;
int ret = 0;
int i;
int copied = 0;
int props_count = 0;
uint32_t __user *props_ptr;
uint64_t __user *prop_values_ptr;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
obj = drm_mode_object_find(dev, arg->obj_id, arg->obj_type);
if (!obj) {
ret = -ENOENT;
goto out;
}
if (!obj->properties) {
ret = -EINVAL;
goto out;
}
props_count = obj->properties->count;
if ((arg->count_props >= props_count) && props_count) {
copied = 0;
props_ptr = (uint32_t __user *)(unsigned long)(arg->props_ptr);
prop_values_ptr = (uint64_t __user *)(unsigned long)
(arg->prop_values_ptr);
for (i = 0; i < props_count; i++) {
if (put_user(obj->properties->ids[i],
props_ptr + copied)) {
ret = -EFAULT;
goto out;
}
if (put_user(obj->properties->values[i],
prop_values_ptr + copied)) {
ret = -EFAULT;
goto out;
}
copied++;
}
}
arg->count_props = props_count;
out:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_mode_obj_set_property_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_obj_set_property *arg = data;
struct drm_mode_object *arg_obj;
struct drm_mode_object *prop_obj;
struct drm_property *property;
int ret = -EINVAL;
int i;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
arg_obj = drm_mode_object_find(dev, arg->obj_id, arg->obj_type);
if (!arg_obj) {
ret = -ENOENT;
goto out;
}
if (!arg_obj->properties)
goto out;
for (i = 0; i < arg_obj->properties->count; i++)
if (arg_obj->properties->ids[i] == arg->prop_id)
break;
if (i == arg_obj->properties->count)
goto out;
prop_obj = drm_mode_object_find(dev, arg->prop_id,
DRM_MODE_OBJECT_PROPERTY);
if (!prop_obj) {
ret = -ENOENT;
goto out;
}
property = obj_to_property(prop_obj);
if (!drm_property_change_is_valid(property, arg->value))
goto out;
switch (arg_obj->type) {
case DRM_MODE_OBJECT_CONNECTOR:
ret = drm_mode_connector_set_obj_prop(arg_obj, property,
arg->value);
break;
case DRM_MODE_OBJECT_CRTC:
ret = drm_mode_crtc_set_obj_prop(arg_obj, property, arg->value);
break;
case DRM_MODE_OBJECT_PLANE:
ret = drm_mode_plane_set_obj_prop(arg_obj, property, arg->value);
break;
}
out:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_mode_connector_attach_encoder(struct drm_connector *connector,
struct drm_encoder *encoder)
{
int i;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0) {
connector->encoder_ids[i] = encoder->base.id;
return 0;
}
}
return -ENOMEM;
}
int drm_mode_crtc_set_gamma_size(struct drm_crtc *crtc,
int gamma_size)
{
crtc->gamma_size = gamma_size;
crtc->gamma_store = kzalloc(gamma_size * sizeof(uint16_t) * 3, GFP_KERNEL);
if (!crtc->gamma_store) {
crtc->gamma_size = 0;
return -ENOMEM;
}
return 0;
}
int drm_mode_gamma_set_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_crtc_lut *crtc_lut = data;
struct drm_crtc *crtc;
void *r_base, *g_base, *b_base;
int size;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
crtc = drm_crtc_find(dev, crtc_lut->crtc_id);
if (!crtc) {
ret = -ENOENT;
goto out;
}
if (crtc->funcs->gamma_set == NULL) {
ret = -ENOSYS;
goto out;
}
if (crtc_lut->gamma_size != crtc->gamma_size) {
ret = -EINVAL;
goto out;
}
size = crtc_lut->gamma_size * (sizeof(uint16_t));
r_base = crtc->gamma_store;
if (copy_from_user(r_base, (void __user *)(unsigned long)crtc_lut->red, size)) {
ret = -EFAULT;
goto out;
}
g_base = r_base + size;
if (copy_from_user(g_base, (void __user *)(unsigned long)crtc_lut->green, size)) {
ret = -EFAULT;
goto out;
}
b_base = g_base + size;
if (copy_from_user(b_base, (void __user *)(unsigned long)crtc_lut->blue, size)) {
ret = -EFAULT;
goto out;
}
crtc->funcs->gamma_set(crtc, r_base, g_base, b_base, 0, crtc->gamma_size);
out:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_mode_gamma_get_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_crtc_lut *crtc_lut = data;
struct drm_crtc *crtc;
void *r_base, *g_base, *b_base;
int size;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
drm_modeset_lock_all(dev);
crtc = drm_crtc_find(dev, crtc_lut->crtc_id);
if (!crtc) {
ret = -ENOENT;
goto out;
}
if (crtc_lut->gamma_size != crtc->gamma_size) {
ret = -EINVAL;
goto out;
}
size = crtc_lut->gamma_size * (sizeof(uint16_t));
r_base = crtc->gamma_store;
if (copy_to_user((void __user *)(unsigned long)crtc_lut->red, r_base, size)) {
ret = -EFAULT;
goto out;
}
g_base = r_base + size;
if (copy_to_user((void __user *)(unsigned long)crtc_lut->green, g_base, size)) {
ret = -EFAULT;
goto out;
}
b_base = g_base + size;
if (copy_to_user((void __user *)(unsigned long)crtc_lut->blue, b_base, size)) {
ret = -EFAULT;
goto out;
}
out:
drm_modeset_unlock_all(dev);
return ret;
}
int drm_mode_page_flip_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_crtc_page_flip *page_flip = data;
struct drm_crtc *crtc;
struct drm_framebuffer *fb = NULL, *old_fb = NULL;
struct drm_pending_vblank_event *e = NULL;
unsigned long flags;
int ret = -EINVAL;
if (page_flip->flags & ~DRM_MODE_PAGE_FLIP_FLAGS ||
page_flip->reserved != 0)
return -EINVAL;
if ((page_flip->flags & DRM_MODE_PAGE_FLIP_ASYNC) && !dev->mode_config.async_page_flip)
return -EINVAL;
crtc = drm_crtc_find(dev, page_flip->crtc_id);
if (!crtc)
return -ENOENT;
drm_modeset_lock(&crtc->mutex, NULL);
if (crtc->primary->fb == NULL) {
ret = -EBUSY;
goto out;
}
if (crtc->funcs->page_flip == NULL)
goto out;
fb = drm_framebuffer_lookup(dev, page_flip->fb_id);
if (!fb) {
ret = -ENOENT;
goto out;
}
ret = drm_crtc_check_viewport(crtc, crtc->x, crtc->y, &crtc->mode, fb);
if (ret)
goto out;
if (crtc->primary->fb->pixel_format != fb->pixel_format) {
DRM_DEBUG_KMS("Page flip is not allowed to change frame buffer format.\n");
ret = -EINVAL;
goto out;
}
if (page_flip->flags & DRM_MODE_PAGE_FLIP_EVENT) {
ret = -ENOMEM;
spin_lock_irqsave(&dev->event_lock, flags);
if (file_priv->event_space < sizeof e->event) {
spin_unlock_irqrestore(&dev->event_lock, flags);
goto out;
}
file_priv->event_space -= sizeof e->event;
spin_unlock_irqrestore(&dev->event_lock, flags);
e = kzalloc(sizeof *e, GFP_KERNEL);
if (e == NULL) {
spin_lock_irqsave(&dev->event_lock, flags);
file_priv->event_space += sizeof e->event;
spin_unlock_irqrestore(&dev->event_lock, flags);
goto out;
}
e->event.base.type = DRM_EVENT_FLIP_COMPLETE;
e->event.base.length = sizeof e->event;
e->event.user_data = page_flip->user_data;
e->base.event = &e->event.base;
e->base.file_priv = file_priv;
e->base.destroy =
(void (*) (struct drm_pending_event *)) kfree;
}
old_fb = crtc->primary->fb;
ret = crtc->funcs->page_flip(crtc, fb, e, page_flip->flags);
if (ret) {
if (page_flip->flags & DRM_MODE_PAGE_FLIP_EVENT) {
spin_lock_irqsave(&dev->event_lock, flags);
file_priv->event_space += sizeof e->event;
spin_unlock_irqrestore(&dev->event_lock, flags);
kfree(e);
}
old_fb = NULL;
} else {
WARN_ON(crtc->primary->fb != fb);
fb = NULL;
}
out:
if (fb)
drm_framebuffer_unreference(fb);
if (old_fb)
drm_framebuffer_unreference(old_fb);
drm_modeset_unlock(&crtc->mutex);
return ret;
}
void drm_mode_config_reset(struct drm_device *dev)
{
struct drm_crtc *crtc;
struct drm_encoder *encoder;
struct drm_connector *connector;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
if (crtc->funcs->reset)
crtc->funcs->reset(crtc);
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head)
if (encoder->funcs->reset)
encoder->funcs->reset(encoder);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
connector->status = connector_status_unknown;
if (connector->funcs->reset)
connector->funcs->reset(connector);
}
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
void drm_fb_get_bpp_depth(uint32_t format, unsigned int *depth,
int *bpp)
{
switch (format) {
case DRM_FORMAT_C8:
case DRM_FORMAT_RGB332:
case DRM_FORMAT_BGR233:
*depth = 8;
*bpp = 8;
break;
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_XBGR1555:
case DRM_FORMAT_RGBX5551:
case DRM_FORMAT_BGRX5551:
case DRM_FORMAT_ARGB1555:
case DRM_FORMAT_ABGR1555:
case DRM_FORMAT_RGBA5551:
case DRM_FORMAT_BGRA5551:
*depth = 15;
*bpp = 16;
break;
case DRM_FORMAT_RGB565:
case DRM_FORMAT_BGR565:
*depth = 16;
*bpp = 16;
break;
case DRM_FORMAT_RGB888:
case DRM_FORMAT_BGR888:
*depth = 24;
*bpp = 24;
break;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_RGBX8888:
case DRM_FORMAT_BGRX8888:
*depth = 24;
*bpp = 32;
break;
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_XBGR2101010:
case DRM_FORMAT_RGBX1010102:
case DRM_FORMAT_BGRX1010102:
case DRM_FORMAT_ARGB2101010:
case DRM_FORMAT_ABGR2101010:
case DRM_FORMAT_RGBA1010102:
case DRM_FORMAT_BGRA1010102:
*depth = 30;
*bpp = 32;
break;
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_RGBA8888:
case DRM_FORMAT_BGRA8888:
*depth = 32;
*bpp = 32;
break;
default:
DRM_DEBUG_KMS("unsupported pixel format %s\n",
drm_get_format_name(format));
*depth = 0;
*bpp = 0;
break;
}
}
int drm_format_num_planes(uint32_t format)
{
switch (format) {
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
return 3;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_NV24:
case DRM_FORMAT_NV42:
return 2;
default:
return 1;
}
}
int drm_format_plane_cpp(uint32_t format, int plane)
{
unsigned int depth;
int bpp;
if (plane >= drm_format_num_planes(format))
return 0;
switch (format) {
case DRM_FORMAT_YUYV:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
return 2;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_NV24:
case DRM_FORMAT_NV42:
return plane ? 2 : 1;
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
return 1;
default:
drm_fb_get_bpp_depth(format, &depth, &bpp);
return bpp >> 3;
}
}
int drm_format_horz_chroma_subsampling(uint32_t format)
{
switch (format) {
case DRM_FORMAT_YUV411:
case DRM_FORMAT_YVU411:
case DRM_FORMAT_YUV410:
case DRM_FORMAT_YVU410:
return 4;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YVU422:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
return 2;
default:
return 1;
}
}
int drm_format_vert_chroma_subsampling(uint32_t format)
{
switch (format) {
case DRM_FORMAT_YUV410:
case DRM_FORMAT_YVU410:
return 4;
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
return 2;
default:
return 1;
}
}
unsigned int drm_rotation_simplify(unsigned int rotation,
unsigned int supported_rotations)
{
if (rotation & ~supported_rotations) {
rotation ^= BIT(DRM_REFLECT_X) | BIT(DRM_REFLECT_Y);
rotation = (rotation & ~0xf) | BIT((ffs(rotation & 0xf) + 1) % 4);
}
return rotation;
}
void drm_mode_config_init(struct drm_device *dev)
{
mutex_init(&dev->mode_config.mutex);
drm_modeset_lock_init(&dev->mode_config.connection_mutex);
mutex_init(&dev->mode_config.idr_mutex);
mutex_init(&dev->mode_config.fb_lock);
INIT_LIST_HEAD(&dev->mode_config.fb_list);
INIT_LIST_HEAD(&dev->mode_config.crtc_list);
INIT_LIST_HEAD(&dev->mode_config.connector_list);
INIT_LIST_HEAD(&dev->mode_config.bridge_list);
INIT_LIST_HEAD(&dev->mode_config.encoder_list);
INIT_LIST_HEAD(&dev->mode_config.property_list);
INIT_LIST_HEAD(&dev->mode_config.property_blob_list);
INIT_LIST_HEAD(&dev->mode_config.plane_list);
idr_init(&dev->mode_config.crtc_idr);
drm_modeset_lock_all(dev);
drm_mode_create_standard_connector_properties(dev);
drm_mode_create_standard_plane_properties(dev);
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
struct drm_bridge *bridge, *brt;
struct drm_framebuffer *fb, *fbt;
struct drm_property *property, *pt;
struct drm_property_blob *blob, *bt;
struct drm_plane *plane, *plt;
list_for_each_entry_safe(encoder, enct, &dev->mode_config.encoder_list,
head) {
encoder->funcs->destroy(encoder);
}
list_for_each_entry_safe(bridge, brt,
&dev->mode_config.bridge_list, head) {
bridge->funcs->destroy(bridge);
}
list_for_each_entry_safe(connector, ot,
&dev->mode_config.connector_list, head) {
connector->funcs->destroy(connector);
}
list_for_each_entry_safe(property, pt, &dev->mode_config.property_list,
head) {
drm_property_destroy(dev, property);
}
list_for_each_entry_safe(blob, bt, &dev->mode_config.property_blob_list,
head) {
drm_property_destroy_blob(dev, blob);
}
WARN_ON(!list_empty(&dev->mode_config.fb_list));
list_for_each_entry_safe(fb, fbt, &dev->mode_config.fb_list, head) {
drm_framebuffer_remove(fb);
}
list_for_each_entry_safe(plane, plt, &dev->mode_config.plane_list,
head) {
plane->funcs->destroy(plane);
}
list_for_each_entry_safe(crtc, ct, &dev->mode_config.crtc_list, head) {
crtc->funcs->destroy(crtc);
}
idr_destroy(&dev->mode_config.crtc_idr);
drm_modeset_lock_fini(&dev->mode_config.connection_mutex);
}
struct drm_property *drm_mode_create_rotation_property(struct drm_device *dev,
unsigned int supported_rotations)
{
static const struct drm_prop_enum_list props[] = {
{ DRM_ROTATE_0, "rotate-0" },
{ DRM_ROTATE_90, "rotate-90" },
{ DRM_ROTATE_180, "rotate-180" },
{ DRM_ROTATE_270, "rotate-270" },
{ DRM_REFLECT_X, "reflect-x" },
{ DRM_REFLECT_Y, "reflect-y" },
};
return drm_property_create_bitmask(dev, 0, "rotation",
props, ARRAY_SIZE(props),
supported_rotations);
}
