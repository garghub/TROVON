static int get_connectors_for_crtc(struct drm_crtc *crtc,
struct drm_connector **connector_list,
int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_connector *connector;
int count = 0;
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
drm_for_each_connector(connector, dev) {
if (connector->encoder && connector->encoder->crtc == crtc) {
if (connector_list != NULL && count < num_connectors)
*(connector_list++) = connector;
count++;
}
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
if (!fb) {
*visible = false;
return 0;
}
if (WARN_ON(!crtc)) {
*visible = false;
return 0;
}
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
primary = create_primary_plane(dev);
return drm_crtc_init_with_planes(dev, crtc, primary, NULL, funcs);
}
int drm_plane_helper_commit(struct drm_plane *plane,
struct drm_plane_state *plane_state,
struct drm_framebuffer *old_fb)
{
const struct drm_plane_helper_funcs *plane_funcs;
struct drm_crtc *crtc[2];
const struct drm_crtc_helper_funcs *crtc_funcs[2];
int i, ret = 0;
plane_funcs = plane->helper_private;
crtc[0] = plane->crtc;
crtc[1] = crtc[0] != plane_state->crtc ? plane_state->crtc : NULL;
for (i = 0; i < 2; i++)
crtc_funcs[i] = crtc[i] ? crtc[i]->helper_private : NULL;
if (plane_funcs->atomic_check) {
ret = plane_funcs->atomic_check(plane, plane_state);
if (ret)
goto out;
}
if (plane_funcs->prepare_fb && plane_state->fb &&
plane_state->fb != old_fb) {
ret = plane_funcs->prepare_fb(plane, plane_state->fb,
plane_state);
if (ret)
goto out;
}
swap(plane->state, plane_state);
for (i = 0; i < 2; i++) {
if (crtc_funcs[i] && crtc_funcs[i]->atomic_begin)
crtc_funcs[i]->atomic_begin(crtc[i], crtc[i]->state);
}
if (drm_atomic_plane_disabling(plane, plane_state) &&
plane_funcs->atomic_disable)
plane_funcs->atomic_disable(plane, plane_state);
else
plane_funcs->atomic_update(plane, plane_state);
for (i = 0; i < 2; i++) {
if (crtc_funcs[i] && crtc_funcs[i]->atomic_flush)
crtc_funcs[i]->atomic_flush(crtc[i], crtc[i]->state);
}
if (plane->state->fb == old_fb)
goto out;
for (i = 0; i < 2; i++) {
if (!crtc[i])
continue;
if (crtc[i]->cursor == plane)
continue;
ret = drm_crtc_vblank_get(crtc[i]);
if (ret == 0) {
drm_crtc_wait_one_vblank(crtc[i]);
drm_crtc_vblank_put(crtc[i]);
}
ret = 0;
}
if (plane_funcs->cleanup_fb && old_fb)
plane_funcs->cleanup_fb(plane, old_fb, plane_state);
out:
if (plane_state) {
if (plane->funcs->atomic_destroy_state)
plane->funcs->atomic_destroy_state(plane, plane_state);
else
drm_atomic_helper_plane_destroy_state(plane, plane_state);
}
return ret;
}
int drm_plane_helper_update(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct drm_plane_state *plane_state;
if (plane->funcs->atomic_duplicate_state)
plane_state = plane->funcs->atomic_duplicate_state(plane);
else {
if (!plane->state)
drm_atomic_helper_plane_reset(plane);
plane_state = drm_atomic_helper_plane_duplicate_state(plane);
}
if (!plane_state)
return -ENOMEM;
plane_state->plane = plane;
plane_state->crtc = crtc;
drm_atomic_set_fb_for_plane(plane_state, fb);
plane_state->crtc_x = crtc_x;
plane_state->crtc_y = crtc_y;
plane_state->crtc_h = crtc_h;
plane_state->crtc_w = crtc_w;
plane_state->src_x = src_x;
plane_state->src_y = src_y;
plane_state->src_h = src_h;
plane_state->src_w = src_w;
return drm_plane_helper_commit(plane, plane_state, plane->fb);
}
int drm_plane_helper_disable(struct drm_plane *plane)
{
struct drm_plane_state *plane_state;
if (!plane->crtc)
return 0;
if (plane->funcs->atomic_duplicate_state)
plane_state = plane->funcs->atomic_duplicate_state(plane);
else {
if (!plane->state)
drm_atomic_helper_plane_reset(plane);
plane_state = drm_atomic_helper_plane_duplicate_state(plane);
}
if (!plane_state)
return -ENOMEM;
plane_state->plane = plane;
plane_state->crtc = NULL;
drm_atomic_set_fb_for_plane(plane_state, NULL);
return drm_plane_helper_commit(plane, plane_state, plane->fb);
}
