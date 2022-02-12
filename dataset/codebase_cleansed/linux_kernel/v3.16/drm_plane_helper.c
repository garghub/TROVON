static int get_connectors_for_crtc(struct drm_crtc *crtc,
struct drm_connector **connector_list,
int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_connector *connector;
int count = 0;
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
if (connector->encoder && connector->encoder->crtc == crtc) {
if (connector_list != NULL && count < num_connectors)
*(connector_list++) = connector;
count++;
}
return count;
}
int drm_plane_helper_check_update(struct drm_plane *plane,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_rect *src,
struct drm_rect *dest,
const struct drm_rect *clip,
int min_scale,
int max_scale,
bool can_position,
bool can_update_disabled,
bool *visible)
{
int hscale, vscale;
if (!crtc->enabled && !can_update_disabled) {
DRM_DEBUG_KMS("Cannot update plane of a disabled CRTC.\n");
return -EINVAL;
}
hscale = drm_rect_calc_hscale(src, dest, min_scale, max_scale);
vscale = drm_rect_calc_vscale(src, dest, min_scale, max_scale);
if (hscale < 0 || vscale < 0) {
DRM_DEBUG_KMS("Invalid scaling of plane\n");
return -ERANGE;
}
*visible = drm_rect_clip_scaled(src, dest, clip, hscale, vscale);
if (!*visible)
return 0;
if (!can_position && !drm_rect_equals(dest, clip)) {
DRM_DEBUG_KMS("Plane must cover entire CRTC\n");
return -EINVAL;
}
return 0;
}
int drm_primary_helper_update(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct drm_mode_set set = {
.crtc = crtc,
.fb = fb,
.mode = &crtc->mode,
.x = src_x >> 16,
.y = src_y >> 16,
};
struct drm_rect src = {
.x1 = src_x,
.y1 = src_y,
.x2 = src_x + src_w,
.y2 = src_y + src_h,
};
struct drm_rect dest = {
.x1 = crtc_x,
.y1 = crtc_y,
.x2 = crtc_x + crtc_w,
.y2 = crtc_y + crtc_h,
};
const struct drm_rect clip = {
.x2 = crtc->mode.hdisplay,
.y2 = crtc->mode.vdisplay,
};
struct drm_connector **connector_list;
int num_connectors, ret;
bool visible;
ret = drm_plane_helper_check_update(plane, crtc, fb,
&src, &dest, &clip,
DRM_PLANE_HELPER_NO_SCALING,
DRM_PLANE_HELPER_NO_SCALING,
false, false, &visible);
if (ret)
return ret;
if (!visible)
return plane->funcs->disable_plane(plane);
num_connectors = get_connectors_for_crtc(crtc, NULL, 0);
BUG_ON(num_connectors == 0);
connector_list = kzalloc(num_connectors * sizeof(*connector_list),
GFP_KERNEL);
if (!connector_list)
return -ENOMEM;
get_connectors_for_crtc(crtc, connector_list, num_connectors);
set.connectors = connector_list;
set.num_connectors = num_connectors;
ret = crtc->funcs->set_config(&set);
kfree(connector_list);
return ret;
}
int drm_primary_helper_disable(struct drm_plane *plane)
{
return -EINVAL;
}
void drm_primary_helper_destroy(struct drm_plane *plane)
{
drm_plane_cleanup(plane);
kfree(plane);
}
struct drm_plane *drm_primary_helper_create_plane(struct drm_device *dev,
const uint32_t *formats,
int num_formats)
{
struct drm_plane *primary;
int ret;
primary = kzalloc(sizeof(*primary), GFP_KERNEL);
if (primary == NULL) {
DRM_DEBUG_KMS("Failed to allocate primary plane\n");
return NULL;
}
if (formats == NULL) {
formats = safe_modeset_formats;
num_formats = ARRAY_SIZE(safe_modeset_formats);
}
ret = drm_plane_init(dev, primary, 0, &drm_primary_helper_funcs,
formats, num_formats,
DRM_PLANE_TYPE_PRIMARY);
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
primary = drm_primary_helper_create_plane(dev, NULL, 0);
return drm_crtc_init_with_planes(dev, crtc, primary, NULL, funcs);
}
