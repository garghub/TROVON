void drm_helper_move_panel_connectors_to_head(struct drm_device *dev)
{
struct drm_connector *connector, *tmp;
struct list_head panel_list;
INIT_LIST_HEAD(&panel_list);
list_for_each_entry_safe(connector, tmp,
&dev->mode_config.connector_list, head) {
if (connector->connector_type == DRM_MODE_CONNECTOR_LVDS ||
connector->connector_type == DRM_MODE_CONNECTOR_eDP ||
connector->connector_type == DRM_MODE_CONNECTOR_DSI)
list_move_tail(&connector->head, &panel_list);
}
list_splice(&panel_list, &dev->mode_config.connector_list);
}
void drm_helper_mode_fill_fb_struct(struct drm_framebuffer *fb,
const struct drm_mode_fb_cmd2 *mode_cmd)
{
const struct drm_format_info *info;
int i;
info = drm_format_info(mode_cmd->pixel_format);
if (!info || !info->depth) {
struct drm_format_name_buf format_name;
DRM_DEBUG_KMS("non-RGB pixel format %s\n",
drm_get_format_name(mode_cmd->pixel_format,
&format_name));
fb->depth = 0;
fb->bits_per_pixel = 0;
} else {
fb->depth = info->depth;
fb->bits_per_pixel = info->cpp[0] * 8;
}
fb->width = mode_cmd->width;
fb->height = mode_cmd->height;
for (i = 0; i < 4; i++) {
fb->pitches[i] = mode_cmd->pitches[i];
fb->offsets[i] = mode_cmd->offsets[i];
}
fb->modifier = mode_cmd->modifier[0];
fb->pixel_format = mode_cmd->pixel_format;
fb->flags = mode_cmd->flags;
}
static struct drm_plane *create_primary_plane(struct drm_device *dev)
{
struct drm_plane *primary;
int ret;
primary = kzalloc(sizeof(*primary), GFP_KERNEL);
if (primary == NULL) {
DRM_DEBUG_KMS("Failed to allocate primary plane\n");
return NULL;
}
primary->format_default = true;
ret = drm_universal_plane_init(dev, primary, 0,
&drm_primary_helper_funcs,
safe_modeset_formats,
ARRAY_SIZE(safe_modeset_formats),
DRM_PLANE_TYPE_PRIMARY, NULL);
if (ret) {
kfree(primary);
primary = NULL;
}
return primary;
}
int drm_crtc_init(struct drm_device *dev, struct drm_crtc *crtc,
const struct drm_crtc_funcs *funcs)
{
struct drm_plane *primary;
primary = create_primary_plane(dev);
return drm_crtc_init_with_planes(dev, crtc, primary, NULL, funcs,
NULL);
}
