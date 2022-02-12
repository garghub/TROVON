static int get_connectors_for_crtc(struct drm_crtc *crtc,
struct drm_connector **connector_list,
int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_connector *connector;
int count = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
if (connector->encoder && connector->encoder->crtc == crtc) {
if (connector_list != NULL && count < num_connectors)
*(connector_list++) = connector;
count++;
}
return count;
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
struct drm_rect dest = {
.x1 = crtc_x,
.y1 = crtc_y,
.x2 = crtc_x + crtc_w,
.y2 = crtc_y + crtc_h,
};
struct drm_rect clip = {
.x2 = crtc->mode.hdisplay,
.y2 = crtc->mode.vdisplay,
};
struct drm_connector **connector_list;
struct drm_framebuffer *tmpfb;
int num_connectors, ret;
if (!crtc->enabled) {
DRM_DEBUG_KMS("Cannot update primary plane of a disabled CRTC.\n");
return -EINVAL;
}
if ((src_x | src_y | src_w | src_h) & SUBPIXEL_MASK) {
DRM_DEBUG_KMS("Primary plane does not support subpixel positioning\n");
return -EINVAL;
}
if (plane->possible_crtcs != drm_crtc_mask(crtc)) {
DRM_DEBUG_KMS("Cannot change primary plane CRTC\n");
return -EINVAL;
}
if (crtc_w != src_w || crtc_h != src_h) {
DRM_DEBUG_KMS("Can't scale primary plane\n");
return -EINVAL;
}
drm_rect_intersect(&dest, &clip);
if (dest.x1 != 0 || dest.y1 != 0 ||
dest.x2 != crtc->mode.hdisplay || dest.y2 != crtc->mode.vdisplay) {
DRM_DEBUG_KMS("Primary plane must cover entire CRTC\n");
return -EINVAL;
}
ret = drm_crtc_check_viewport(crtc, crtc_x, crtc_y, &crtc->mode, fb);
if (ret)
return ret;
num_connectors = get_connectors_for_crtc(crtc, NULL, 0);
BUG_ON(num_connectors == 0);
connector_list = kzalloc(num_connectors * sizeof(*connector_list),
GFP_KERNEL);
if (!connector_list)
return -ENOMEM;
get_connectors_for_crtc(crtc, connector_list, num_connectors);
set.connectors = connector_list;
set.num_connectors = num_connectors;
tmpfb = plane->fb;
ret = crtc->funcs->set_config(&set);
plane->fb = tmpfb;
kfree(connector_list);
return ret;
}
int drm_primary_helper_disable(struct drm_plane *plane)
{
return -EINVAL;
}
void drm_primary_helper_destroy(struct drm_plane *plane)
{
plane->funcs->disable_plane(plane);
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
