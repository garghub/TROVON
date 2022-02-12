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
static void drm_connector_get_cmdline_mode(struct drm_connector *connector)
{
struct drm_cmdline_mode *mode = &connector->cmdline_mode;
char *option = NULL;
if (fb_get_options(connector->name, &option))
return;
if (!drm_mode_parse_command_line_for_connector(option,
connector,
mode))
return;
if (mode->force) {
DRM_INFO("forcing %s connector %s\n", connector->name,
drm_get_connector_force_name(mode->force));
connector->force = mode->force;
}
DRM_DEBUG_KMS("cmdline mode for connector %s %dx%d@%dHz%s%s%s\n",
connector->name,
mode->xres, mode->yres,
mode->refresh_specified ? mode->refresh : 60,
mode->rb ? " reduced blanking" : "",
mode->margins ? " with margins" : "",
mode->interlace ? " interlaced" : "");
}
static void drm_connector_free(struct kref *kref)
{
struct drm_connector *connector =
container_of(kref, struct drm_connector, base.refcount);
struct drm_device *dev = connector->dev;
drm_mode_object_unregister(dev, &connector->base);
connector->funcs->destroy(connector);
}
int drm_connector_init(struct drm_device *dev,
struct drm_connector *connector,
const struct drm_connector_funcs *funcs,
int connector_type)
{
struct drm_mode_config *config = &dev->mode_config;
int ret;
struct ida *connector_ida =
&drm_connector_enum_list[connector_type].ida;
ret = __drm_mode_object_add(dev, &connector->base,
DRM_MODE_OBJECT_CONNECTOR,
false, drm_connector_free);
if (ret)
return ret;
connector->base.properties = &connector->properties;
connector->dev = dev;
connector->funcs = funcs;
ret = ida_simple_get(&config->connector_ida, 0, 0, GFP_KERNEL);
if (ret < 0)
goto out_put;
connector->index = ret;
ret = 0;
connector->connector_type = connector_type;
connector->connector_type_id =
ida_simple_get(connector_ida, 1, 0, GFP_KERNEL);
if (connector->connector_type_id < 0) {
ret = connector->connector_type_id;
goto out_put_id;
}
connector->name =
kasprintf(GFP_KERNEL, "%s-%d",
drm_connector_enum_list[connector_type].name,
connector->connector_type_id);
if (!connector->name) {
ret = -ENOMEM;
goto out_put_type_id;
}
INIT_LIST_HEAD(&connector->probed_modes);
INIT_LIST_HEAD(&connector->modes);
mutex_init(&connector->mutex);
connector->edid_blob_ptr = NULL;
connector->status = connector_status_unknown;
drm_connector_get_cmdline_mode(connector);
spin_lock_irq(&config->connector_list_lock);
list_add_tail(&connector->head, &config->connector_list);
config->num_connector++;
spin_unlock_irq(&config->connector_list_lock);
if (connector_type != DRM_MODE_CONNECTOR_VIRTUAL)
drm_object_attach_property(&connector->base,
config->edid_property,
0);
drm_object_attach_property(&connector->base,
config->dpms_property, 0);
drm_object_attach_property(&connector->base,
config->link_status_property,
0);
if (drm_core_check_feature(dev, DRIVER_ATOMIC)) {
drm_object_attach_property(&connector->base, config->prop_crtc_id, 0);
}
connector->debugfs_entry = NULL;
out_put_type_id:
if (ret)
ida_simple_remove(connector_ida, connector->connector_type_id);
out_put_id:
if (ret)
ida_simple_remove(&config->connector_ida, connector->index);
out_put:
if (ret)
drm_mode_object_unregister(dev, &connector->base);
return ret;
}
int drm_mode_connector_attach_encoder(struct drm_connector *connector,
struct drm_encoder *encoder)
{
int i;
if (WARN_ON(connector->encoder))
return -EINVAL;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++) {
if (connector->encoder_ids[i] == 0) {
connector->encoder_ids[i] = encoder->base.id;
return 0;
}
}
return -ENOMEM;
}
static void drm_mode_remove(struct drm_connector *connector,
struct drm_display_mode *mode)
{
list_del(&mode->head);
drm_mode_destroy(connector->dev, mode);
}
void drm_connector_cleanup(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode, *t;
if (WARN_ON(connector->registered))
drm_connector_unregister(connector);
if (connector->tile_group) {
drm_mode_put_tile_group(dev, connector->tile_group);
connector->tile_group = NULL;
}
list_for_each_entry_safe(mode, t, &connector->probed_modes, head)
drm_mode_remove(connector, mode);
list_for_each_entry_safe(mode, t, &connector->modes, head)
drm_mode_remove(connector, mode);
ida_simple_remove(&drm_connector_enum_list[connector->connector_type].ida,
connector->connector_type_id);
ida_simple_remove(&dev->mode_config.connector_ida,
connector->index);
kfree(connector->display_info.bus_formats);
drm_mode_object_unregister(dev, &connector->base);
kfree(connector->name);
connector->name = NULL;
spin_lock_irq(&dev->mode_config.connector_list_lock);
list_del(&connector->head);
dev->mode_config.num_connector--;
spin_unlock_irq(&dev->mode_config.connector_list_lock);
WARN_ON(connector->state && !connector->funcs->atomic_destroy_state);
if (connector->state && connector->funcs->atomic_destroy_state)
connector->funcs->atomic_destroy_state(connector,
connector->state);
mutex_destroy(&connector->mutex);
memset(connector, 0, sizeof(*connector));
}
int drm_connector_register(struct drm_connector *connector)
{
int ret = 0;
if (!connector->dev->registered)
return 0;
mutex_lock(&connector->mutex);
if (connector->registered)
goto unlock;
ret = drm_sysfs_connector_add(connector);
if (ret)
goto unlock;
ret = drm_debugfs_connector_add(connector);
if (ret) {
goto err_sysfs;
}
if (connector->funcs->late_register) {
ret = connector->funcs->late_register(connector);
if (ret)
goto err_debugfs;
}
drm_mode_object_register(connector->dev, &connector->base);
connector->registered = true;
goto unlock;
err_debugfs:
drm_debugfs_connector_remove(connector);
err_sysfs:
drm_sysfs_connector_remove(connector);
unlock:
mutex_unlock(&connector->mutex);
return ret;
}
void drm_connector_unregister(struct drm_connector *connector)
{
mutex_lock(&connector->mutex);
if (!connector->registered) {
mutex_unlock(&connector->mutex);
return;
}
if (connector->funcs->early_unregister)
connector->funcs->early_unregister(connector);
drm_sysfs_connector_remove(connector);
drm_debugfs_connector_remove(connector);
connector->registered = false;
mutex_unlock(&connector->mutex);
}
void drm_connector_unregister_all(struct drm_device *dev)
{
struct drm_connector *connector;
struct drm_connector_list_iter conn_iter;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter)
drm_connector_unregister(connector);
drm_connector_list_iter_end(&conn_iter);
}
int drm_connector_register_all(struct drm_device *dev)
{
struct drm_connector *connector;
struct drm_connector_list_iter conn_iter;
int ret = 0;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
ret = drm_connector_register(connector);
if (ret)
break;
}
drm_connector_list_iter_end(&conn_iter);
if (ret)
drm_connector_unregister_all(dev);
return ret;
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
const char *drm_get_connector_force_name(enum drm_connector_force force)
{
switch (force) {
case DRM_FORCE_UNSPECIFIED:
return "unspecified";
case DRM_FORCE_OFF:
return "off";
case DRM_FORCE_ON:
return "on";
case DRM_FORCE_ON_DIGITAL:
return "digital";
default:
return "unknown";
}
}
void drm_connector_list_iter_begin(struct drm_device *dev,
struct drm_connector_list_iter *iter)
{
iter->dev = dev;
iter->conn = NULL;
lock_acquire_shared_recursive(&connector_list_iter_dep_map, 0, 1, NULL, _RET_IP_);
}
struct drm_connector *
drm_connector_list_iter_next(struct drm_connector_list_iter *iter)
{
struct drm_connector *old_conn = iter->conn;
struct drm_mode_config *config = &iter->dev->mode_config;
struct list_head *lhead;
unsigned long flags;
spin_lock_irqsave(&config->connector_list_lock, flags);
lhead = old_conn ? &old_conn->head : &config->connector_list;
do {
if (lhead->next == &config->connector_list) {
iter->conn = NULL;
break;
}
lhead = lhead->next;
iter->conn = list_entry(lhead, struct drm_connector, head);
} while (!kref_get_unless_zero(&iter->conn->base.refcount));
spin_unlock_irqrestore(&config->connector_list_lock, flags);
if (old_conn)
drm_connector_put(old_conn);
return iter->conn;
}
void drm_connector_list_iter_end(struct drm_connector_list_iter *iter)
{
iter->dev = NULL;
if (iter->conn)
drm_connector_put(iter->conn);
lock_release(&connector_list_iter_dep_map, 0, _RET_IP_);
}
const char *drm_get_subpixel_order_name(enum subpixel_order order)
{
return drm_subpixel_enum_list[order].name;
}
int drm_display_info_set_bus_formats(struct drm_display_info *info,
const u32 *formats,
unsigned int num_formats)
{
u32 *fmts = NULL;
if (!formats && num_formats)
return -EINVAL;
if (formats && num_formats) {
fmts = kmemdup(formats, sizeof(*formats) * num_formats,
GFP_KERNEL);
if (!fmts)
return -ENOMEM;
}
kfree(info->bus_formats);
info->bus_formats = fmts;
info->num_bus_formats = num_formats;
return 0;
}
int drm_connector_create_standard_properties(struct drm_device *dev)
{
struct drm_property *prop;
prop = drm_property_create(dev, DRM_MODE_PROP_BLOB |
DRM_MODE_PROP_IMMUTABLE,
"EDID", 0);
if (!prop)
return -ENOMEM;
dev->mode_config.edid_property = prop;
prop = drm_property_create_enum(dev, 0,
"DPMS", drm_dpms_enum_list,
ARRAY_SIZE(drm_dpms_enum_list));
if (!prop)
return -ENOMEM;
dev->mode_config.dpms_property = prop;
prop = drm_property_create(dev,
DRM_MODE_PROP_BLOB |
DRM_MODE_PROP_IMMUTABLE,
"PATH", 0);
if (!prop)
return -ENOMEM;
dev->mode_config.path_property = prop;
prop = drm_property_create(dev,
DRM_MODE_PROP_BLOB |
DRM_MODE_PROP_IMMUTABLE,
"TILE", 0);
if (!prop)
return -ENOMEM;
dev->mode_config.tile_property = prop;
prop = drm_property_create_enum(dev, 0, "link-status",
drm_link_status_enum_list,
ARRAY_SIZE(drm_link_status_enum_list));
if (!prop)
return -ENOMEM;
dev->mode_config.link_status_property = prop;
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
int drm_mode_create_tv_properties(struct drm_device *dev,
unsigned int num_modes,
const char * const modes[])
{
struct drm_property *tv_selector;
struct drm_property *tv_subconnector;
unsigned int i;
if (dev->mode_config.tv_select_subconnector_property)
return 0;
tv_selector = drm_property_create_enum(dev, 0,
"select subconnector",
drm_tv_select_enum_list,
ARRAY_SIZE(drm_tv_select_enum_list));
if (!tv_selector)
goto nomem;
dev->mode_config.tv_select_subconnector_property = tv_selector;
tv_subconnector =
drm_property_create_enum(dev, DRM_MODE_PROP_IMMUTABLE,
"subconnector",
drm_tv_subconnector_enum_list,
ARRAY_SIZE(drm_tv_subconnector_enum_list));
if (!tv_subconnector)
goto nomem;
dev->mode_config.tv_subconnector_property = tv_subconnector;
dev->mode_config.tv_left_margin_property =
drm_property_create_range(dev, 0, "left margin", 0, 100);
if (!dev->mode_config.tv_left_margin_property)
goto nomem;
dev->mode_config.tv_right_margin_property =
drm_property_create_range(dev, 0, "right margin", 0, 100);
if (!dev->mode_config.tv_right_margin_property)
goto nomem;
dev->mode_config.tv_top_margin_property =
drm_property_create_range(dev, 0, "top margin", 0, 100);
if (!dev->mode_config.tv_top_margin_property)
goto nomem;
dev->mode_config.tv_bottom_margin_property =
drm_property_create_range(dev, 0, "bottom margin", 0, 100);
if (!dev->mode_config.tv_bottom_margin_property)
goto nomem;
dev->mode_config.tv_mode_property =
drm_property_create(dev, DRM_MODE_PROP_ENUM,
"mode", num_modes);
if (!dev->mode_config.tv_mode_property)
goto nomem;
for (i = 0; i < num_modes; i++)
drm_property_add_enum(dev->mode_config.tv_mode_property, i,
i, modes[i]);
dev->mode_config.tv_brightness_property =
drm_property_create_range(dev, 0, "brightness", 0, 100);
if (!dev->mode_config.tv_brightness_property)
goto nomem;
dev->mode_config.tv_contrast_property =
drm_property_create_range(dev, 0, "contrast", 0, 100);
if (!dev->mode_config.tv_contrast_property)
goto nomem;
dev->mode_config.tv_flicker_reduction_property =
drm_property_create_range(dev, 0, "flicker reduction", 0, 100);
if (!dev->mode_config.tv_flicker_reduction_property)
goto nomem;
dev->mode_config.tv_overscan_property =
drm_property_create_range(dev, 0, "overscan", 0, 100);
if (!dev->mode_config.tv_overscan_property)
goto nomem;
dev->mode_config.tv_saturation_property =
drm_property_create_range(dev, 0, "saturation", 0, 100);
if (!dev->mode_config.tv_saturation_property)
goto nomem;
dev->mode_config.tv_hue_property =
drm_property_create_range(dev, 0, "hue", 0, 100);
if (!dev->mode_config.tv_hue_property)
goto nomem;
return 0;
nomem:
return -ENOMEM;
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
int drm_connector_attach_scaling_mode_property(struct drm_connector *connector,
u32 scaling_mode_mask)
{
struct drm_device *dev = connector->dev;
struct drm_property *scaling_mode_property;
int i, j = 0;
const unsigned valid_scaling_mode_mask =
(1U << ARRAY_SIZE(drm_scaling_mode_enum_list)) - 1;
if (WARN_ON(hweight32(scaling_mode_mask) < 2 ||
scaling_mode_mask & ~valid_scaling_mode_mask))
return -EINVAL;
scaling_mode_property =
drm_property_create(dev, DRM_MODE_PROP_ENUM, "scaling mode",
hweight32(scaling_mode_mask));
if (!scaling_mode_property)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(drm_scaling_mode_enum_list); i++) {
int ret;
if (!(BIT(i) & scaling_mode_mask))
continue;
ret = drm_property_add_enum(scaling_mode_property, j++,
drm_scaling_mode_enum_list[i].type,
drm_scaling_mode_enum_list[i].name);
if (ret) {
drm_property_destroy(dev, scaling_mode_property);
return ret;
}
}
drm_object_attach_property(&connector->base,
scaling_mode_property, 0);
connector->scaling_mode_property = scaling_mode_property;
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
int drm_mode_create_suggested_offset_properties(struct drm_device *dev)
{
if (dev->mode_config.suggested_x_property && dev->mode_config.suggested_y_property)
return 0;
dev->mode_config.suggested_x_property =
drm_property_create_range(dev, DRM_MODE_PROP_IMMUTABLE, "suggested X", 0, 0xffffffff);
dev->mode_config.suggested_y_property =
drm_property_create_range(dev, DRM_MODE_PROP_IMMUTABLE, "suggested Y", 0, 0xffffffff);
if (dev->mode_config.suggested_x_property == NULL ||
dev->mode_config.suggested_y_property == NULL)
return -ENOMEM;
return 0;
}
int drm_mode_connector_set_path_property(struct drm_connector *connector,
const char *path)
{
struct drm_device *dev = connector->dev;
int ret;
ret = drm_property_replace_global_blob(dev,
&connector->path_blob_ptr,
strlen(path) + 1,
path,
&connector->base,
dev->mode_config.path_property);
return ret;
}
int drm_mode_connector_set_tile_property(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
char tile[256];
int ret;
if (!connector->has_tile) {
ret = drm_property_replace_global_blob(dev,
&connector->tile_blob_ptr,
0,
NULL,
&connector->base,
dev->mode_config.tile_property);
return ret;
}
snprintf(tile, 256, "%d:%d:%d:%d:%d:%d:%d:%d",
connector->tile_group->id, connector->tile_is_single_monitor,
connector->num_h_tile, connector->num_v_tile,
connector->tile_h_loc, connector->tile_v_loc,
connector->tile_h_size, connector->tile_v_size);
ret = drm_property_replace_global_blob(dev,
&connector->tile_blob_ptr,
strlen(tile) + 1,
tile,
&connector->base,
dev->mode_config.tile_property);
return ret;
}
int drm_mode_connector_update_edid_property(struct drm_connector *connector,
const struct edid *edid)
{
struct drm_device *dev = connector->dev;
size_t size = 0;
int ret;
if (connector->override_edid)
return 0;
if (edid)
size = EDID_LENGTH * (1 + edid->extensions);
ret = drm_property_replace_global_blob(dev,
&connector->edid_blob_ptr,
size,
edid,
&connector->base,
dev->mode_config.edid_property);
return ret;
}
void drm_mode_connector_set_link_status_property(struct drm_connector *connector,
uint64_t link_status)
{
struct drm_device *dev = connector->dev;
drm_modeset_lock(&dev->mode_config.connection_mutex, NULL);
connector->state->link_status = link_status;
drm_modeset_unlock(&dev->mode_config.connection_mutex);
}
int drm_mode_connector_set_obj_prop(struct drm_mode_object *obj,
struct drm_property *property,
uint64_t value)
{
int ret = -EINVAL;
struct drm_connector *connector = obj_to_connector(obj);
if (property == connector->dev->mode_config.dpms_property) {
ret = (*connector->funcs->dpms)(connector, (int)value);
} else if (connector->funcs->set_property)
ret = connector->funcs->set_property(connector, property, value);
if (!ret)
drm_object_property_set_value(&connector->base, property, value);
return ret;
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
static struct drm_encoder *drm_connector_get_encoder(struct drm_connector *connector)
{
if (connector->state)
return connector->state->best_encoder;
return connector->encoder;
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
struct drm_encoder *encoder;
struct drm_display_mode *mode;
int mode_count = 0;
int encoders_count = 0;
int ret = 0;
int copied = 0;
int i;
struct drm_mode_modeinfo u_mode;
struct drm_mode_modeinfo __user *mode_ptr;
uint32_t __user *encoder_ptr;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
memset(&u_mode, 0, sizeof(struct drm_mode_modeinfo));
connector = drm_connector_lookup(dev, out_resp->connector_id);
if (!connector)
return -ENOENT;
for (i = 0; i < DRM_CONNECTOR_MAX_ENCODER; i++)
if (connector->encoder_ids[i] != 0)
encoders_count++;
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
out_resp->connector_id = connector->base.id;
out_resp->connector_type = connector->connector_type;
out_resp->connector_type_id = connector->connector_type_id;
mutex_lock(&dev->mode_config.mutex);
if (out_resp->count_modes == 0) {
connector->funcs->fill_modes(connector,
dev->mode_config.max_width,
dev->mode_config.max_height);
}
out_resp->mm_width = connector->display_info.width_mm;
out_resp->mm_height = connector->display_info.height_mm;
out_resp->subpixel = connector->display_info.subpixel_order;
out_resp->connection = connector->status;
list_for_each_entry(mode, &connector->modes, head)
if (drm_mode_expose_to_userspace(mode, file_priv))
mode_count++;
if ((out_resp->count_modes >= mode_count) && mode_count) {
copied = 0;
mode_ptr = (struct drm_mode_modeinfo __user *)(unsigned long)out_resp->modes_ptr;
list_for_each_entry(mode, &connector->modes, head) {
if (!drm_mode_expose_to_userspace(mode, file_priv))
continue;
drm_mode_convert_to_umode(&u_mode, mode);
if (copy_to_user(mode_ptr + copied,
&u_mode, sizeof(u_mode))) {
ret = -EFAULT;
mutex_unlock(&dev->mode_config.mutex);
goto out;
}
copied++;
}
}
out_resp->count_modes = mode_count;
mutex_unlock(&dev->mode_config.mutex);
drm_modeset_lock(&dev->mode_config.connection_mutex, NULL);
encoder = drm_connector_get_encoder(connector);
if (encoder)
out_resp->encoder_id = encoder->base.id;
else
out_resp->encoder_id = 0;
ret = drm_mode_object_get_properties(&connector->base, file_priv->atomic,
(uint32_t __user *)(unsigned long)(out_resp->props_ptr),
(uint64_t __user *)(unsigned long)(out_resp->prop_values_ptr),
&out_resp->count_props);
drm_modeset_unlock(&dev->mode_config.connection_mutex);
out:
drm_connector_put(connector);
return ret;
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
