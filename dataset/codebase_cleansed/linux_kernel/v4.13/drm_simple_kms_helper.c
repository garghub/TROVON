static int drm_simple_kms_crtc_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
return drm_atomic_add_affected_planes(state->state, crtc);
}
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
struct drm_rect clip = { 0 };
struct drm_simple_display_pipe *pipe;
struct drm_crtc_state *crtc_state;
int ret;
pipe = container_of(plane, struct drm_simple_display_pipe, plane);
crtc_state = drm_atomic_get_new_crtc_state(plane_state->state,
&pipe->crtc);
if (crtc_state->enable != !!plane_state->crtc)
return -EINVAL;
if (!crtc_state->enable)
return 0;
clip.x2 = crtc_state->adjusted_mode.hdisplay;
clip.y2 = crtc_state->adjusted_mode.vdisplay;
ret = drm_plane_helper_check_state(plane_state, &clip,
DRM_PLANE_HELPER_NO_SCALING,
DRM_PLANE_HELPER_NO_SCALING,
false, true);
if (ret)
return ret;
if (!plane_state->visible)
return -EINVAL;
if (!pipe->funcs || !pipe->funcs->check)
return 0;
return pipe->funcs->check(pipe, plane_state, crtc_state);
}
static void drm_simple_kms_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_pstate)
{
struct drm_simple_display_pipe *pipe;
pipe = container_of(plane, struct drm_simple_display_pipe, plane);
if (!pipe->funcs || !pipe->funcs->update)
return;
pipe->funcs->update(pipe, old_pstate);
}
static int drm_simple_kms_plane_prepare_fb(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_simple_display_pipe *pipe;
pipe = container_of(plane, struct drm_simple_display_pipe, plane);
if (!pipe->funcs || !pipe->funcs->prepare_fb)
return 0;
return pipe->funcs->prepare_fb(pipe, state);
}
static void drm_simple_kms_plane_cleanup_fb(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_simple_display_pipe *pipe;
pipe = container_of(plane, struct drm_simple_display_pipe, plane);
if (!pipe->funcs || !pipe->funcs->cleanup_fb)
return;
pipe->funcs->cleanup_fb(pipe, state);
}
int drm_simple_display_pipe_attach_bridge(struct drm_simple_display_pipe *pipe,
struct drm_bridge *bridge)
{
return drm_bridge_attach(&pipe->encoder, bridge, NULL);
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
if (ret || !connector)
return ret;
return drm_mode_connector_attach_encoder(connector, encoder);
}
