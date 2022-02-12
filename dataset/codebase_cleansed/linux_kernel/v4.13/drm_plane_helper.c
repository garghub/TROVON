static int get_connectors_for_crtc(struct drm_crtc *crtc,
struct drm_connector **connector_list,
int num_connectors)
{
struct drm_device *dev = crtc->dev;
struct drm_connector *connector;
struct drm_connector_list_iter conn_iter;
int count = 0;
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
if (connector->encoder && connector->encoder->crtc == crtc) {
if (connector_list != NULL && count < num_connectors)
*(connector_list++) = connector;
count++;
}
}
drm_connector_list_iter_end(&conn_iter);
return count;
}
int drm_plane_helper_check_state(struct drm_plane_state *state,
const struct drm_rect *clip,
int min_scale,
int max_scale,
bool can_position,
bool can_update_disabled)
{
struct drm_crtc *crtc = state->crtc;
struct drm_framebuffer *fb = state->fb;
struct drm_rect *src = &state->src;
struct drm_rect *dst = &state->dst;
unsigned int rotation = state->rotation;
int hscale, vscale;
*src = drm_plane_state_src(state);
*dst = drm_plane_state_dest(state);
if (!fb) {
state->visible = false;
return 0;
}
if (WARN_ON(!crtc)) {
state->visible = false;
return 0;
}
if (!crtc->enabled && !can_update_disabled) {
DRM_DEBUG_KMS("Cannot update plane of a disabled CRTC.\n");
return -EINVAL;
}
drm_rect_rotate(src, fb->width << 16, fb->height << 16, rotation);
hscale = drm_rect_calc_hscale(src, dst, min_scale, max_scale);
vscale = drm_rect_calc_vscale(src, dst, min_scale, max_scale);
if (hscale < 0 || vscale < 0) {
DRM_DEBUG_KMS("Invalid scaling of plane\n");
drm_rect_debug_print("src: ", &state->src, true);
drm_rect_debug_print("dst: ", &state->dst, false);
return -ERANGE;
}
state->visible = drm_rect_clip_scaled(src, dst, clip, hscale, vscale);
drm_rect_rotate_inv(src, fb->width << 16, fb->height << 16, rotation);
if (!state->visible)
return 0;
if (!can_position && !drm_rect_equals(dst, clip)) {
DRM_DEBUG_KMS("Plane must cover entire CRTC\n");
drm_rect_debug_print("dst: ", dst, false);
drm_rect_debug_print("clip: ", clip, false);
return -EINVAL;
}
return 0;
}
int drm_plane_helper_check_update(struct drm_plane *plane,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_rect *src,
struct drm_rect *dst,
const struct drm_rect *clip,
unsigned int rotation,
int min_scale,
int max_scale,
bool can_position,
bool can_update_disabled,
bool *visible)
{
struct drm_plane_state state = {
.plane = plane,
.crtc = crtc,
.fb = fb,
.src_x = src->x1,
.src_y = src->y1,
.src_w = drm_rect_width(src),
.src_h = drm_rect_height(src),
.crtc_x = dst->x1,
.crtc_y = dst->y1,
.crtc_w = drm_rect_width(dst),
.crtc_h = drm_rect_height(dst),
.rotation = rotation,
.visible = *visible,
};
int ret;
ret = drm_plane_helper_check_state(&state, clip,
min_scale, max_scale,
can_position,
can_update_disabled);
if (ret)
return ret;
*src = state.src;
*dst = state.dst;
*visible = state.visible;
return 0;
}
int drm_primary_helper_update(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h,
struct drm_modeset_acquire_ctx *ctx)
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
DRM_MODE_ROTATE_0,
DRM_PLANE_HELPER_NO_SCALING,
DRM_PLANE_HELPER_NO_SCALING,
false, false, &visible);
if (ret)
return ret;
if (!visible)
return plane->funcs->disable_plane(plane, ctx);
num_connectors = get_connectors_for_crtc(crtc, NULL, 0);
BUG_ON(num_connectors == 0);
connector_list = kzalloc(num_connectors * sizeof(*connector_list),
GFP_KERNEL);
if (!connector_list)
return -ENOMEM;
get_connectors_for_crtc(crtc, connector_list, num_connectors);
set.connectors = connector_list;
set.num_connectors = num_connectors;
ret = crtc->funcs->set_config(&set, ctx);
kfree(connector_list);
return ret;
}
int drm_primary_helper_disable(struct drm_plane *plane,
struct drm_modeset_acquire_ctx *ctx)
{
return -EINVAL;
}
void drm_primary_helper_destroy(struct drm_plane *plane)
{
drm_plane_cleanup(plane);
kfree(plane);
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
if (plane_funcs->prepare_fb && plane_state->fb != old_fb) {
ret = plane_funcs->prepare_fb(plane,
plane_state);
if (ret)
goto out;
}
swap(plane->state, plane_state);
for (i = 0; i < 2; i++) {
if (crtc_funcs[i] && crtc_funcs[i]->atomic_begin)
crtc_funcs[i]->atomic_begin(crtc[i], crtc[i]->state);
}
if (drm_atomic_plane_disabling(plane_state, plane->state) &&
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
if (plane_funcs->cleanup_fb)
plane_funcs->cleanup_fb(plane, plane_state);
out:
if (plane->funcs->atomic_destroy_state)
plane->funcs->atomic_destroy_state(plane, plane_state);
else
drm_atomic_helper_plane_destroy_state(plane, plane_state);
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
