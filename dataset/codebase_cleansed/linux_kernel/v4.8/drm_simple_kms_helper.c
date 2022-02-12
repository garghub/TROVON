static void drm_simple_kms_crtc_enable(struct drm_crtc *crtc)
{
struct drm_simple_display_pipe *pipe;
pipe = container_of(crtc, struct drm_simple_display_pipe, crtc);
if (!pipe->funcs || !pipe->funcs->enable)
return;
pipe->funcs->enable(pipe, crtc->state);
}
static void drm_simple_kms_crtc_disable(struct drm_crtc *crtc)
{
struct drm_simple_display_pipe *pipe;
pipe = container_of(crtc, struct drm_simple_display_pipe, crtc);
if (!pipe->funcs || !pipe->funcs->disable)
return;
pipe->funcs->disable(pipe);
}
static int drm_simple_kms_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *plane_state)
{
struct drm_rect src = {
.x1 = plane_state->src_x,
.y1 = plane_state->src_y,
.x2 = plane_state->src_x + plane_state->src_w,
.y2 = plane_state->src_y + plane_state->src_h,
};
struct drm_rect dest = {
.x1 = plane_state->crtc_x,
.y1 = plane_state->crtc_y,
.x2 = plane_state->crtc_x + plane_state->crtc_w,
.y2 = plane_state->crtc_y + plane_state->crtc_h,
};
struct drm_rect clip = { 0 };
struct drm_simple_display_pipe *pipe;
struct drm_crtc_state *crtc_state;
bool visible;
int ret;
pipe = container_of(plane, struct drm_simple_display_pipe, plane);
crtc_state = drm_atomic_get_existing_crtc_state(plane_state->state,
&pipe->crtc);
if (crtc_state->enable != !!plane_state->crtc)
return -EINVAL;
if (!crtc_state->enable)
return 0;
clip.x2 = crtc_state->adjusted_mode.hdisplay;
clip.y2 = crtc_state->adjusted_mode.vdisplay;
ret = drm_plane_helper_check_update(plane, &pipe->crtc,
plane_state->fb,
&src, &dest, &clip,
plane_state->rotation,
DRM_PLANE_HELPER_NO_SCALING,
DRM_PLANE_HELPER_NO_SCALING,
false, true, &visible);
if (ret)
return ret;
if (!visible)
return -EINVAL;
if (!pipe->funcs || !pipe->funcs->check)
return 0;
return pipe->funcs->check(pipe, plane_state, crtc_state);
}
static void drm_simple_kms_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *pstate)
{
struct drm_simple_display_pipe *pipe;
pipe = container_of(plane, struct drm_simple_display_pipe, plane);
if (!pipe->funcs || !pipe->funcs->update)
return;
pipe->funcs->update(pipe, pstate);
}
int drm_simple_display_pipe_init(struct drm_device *dev,
struct drm_simple_display_pipe *pipe,
const struct drm_simple_display_pipe_funcs *funcs,
const uint32_t *formats, unsigned int format_count,
struct drm_connector *connector)
{
struct drm_encoder *encoder = &pipe->encoder;
struct drm_plane *plane = &pipe->plane;
struct drm_crtc *crtc = &pipe->crtc;
int ret;
pipe->connector = connector;
pipe->funcs = funcs;
drm_plane_helper_add(plane, &drm_simple_kms_plane_helper_funcs);
ret = drm_universal_plane_init(dev, plane, 0,
&drm_simple_kms_plane_funcs,
formats, format_count,
DRM_PLANE_TYPE_PRIMARY, NULL);
if (ret)
return ret;
drm_crtc_helper_add(crtc, &drm_simple_kms_crtc_helper_funcs);
ret = drm_crtc_init_with_planes(dev, crtc, plane, NULL,
&drm_simple_kms_crtc_funcs, NULL);
if (ret)
return ret;
encoder->possible_crtcs = 1 << drm_crtc_index(crtc);
ret = drm_encoder_init(dev, encoder, &drm_simple_kms_encoder_funcs,
DRM_MODE_ENCODER_NONE, NULL);
if (ret)
return ret;
return drm_mode_connector_attach_encoder(connector, encoder);
}
