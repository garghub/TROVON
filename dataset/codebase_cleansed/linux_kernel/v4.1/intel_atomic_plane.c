struct intel_plane_state *
intel_create_plane_state(struct drm_plane *plane)
{
struct intel_plane_state *state;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
state->base.plane = plane;
state->base.rotation = BIT(DRM_ROTATE_0);
return state;
}
struct drm_plane_state *
intel_plane_duplicate_state(struct drm_plane *plane)
{
struct drm_plane_state *state;
struct intel_plane_state *intel_state;
if (WARN_ON(!plane->state))
intel_state = intel_create_plane_state(plane);
else
intel_state = kmemdup(plane->state, sizeof(*intel_state),
GFP_KERNEL);
if (!intel_state)
return NULL;
state = &intel_state->base;
if (state->fb)
drm_framebuffer_reference(state->fb);
return state;
}
void
intel_plane_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
drm_atomic_helper_plane_destroy_state(plane, state);
}
static int intel_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_crtc *crtc = state->crtc;
struct intel_crtc *intel_crtc;
struct intel_plane *intel_plane = to_intel_plane(plane);
struct intel_plane_state *intel_state = to_intel_plane_state(state);
crtc = crtc ? crtc : plane->crtc;
intel_crtc = to_intel_crtc(crtc);
if (!crtc)
return 0;
intel_state->src.x1 = state->src_x;
intel_state->src.y1 = state->src_y;
intel_state->src.x2 = state->src_x + state->src_w;
intel_state->src.y2 = state->src_y + state->src_h;
intel_state->dst.x1 = state->crtc_x;
intel_state->dst.y1 = state->crtc_y;
intel_state->dst.x2 = state->crtc_x + state->crtc_w;
intel_state->dst.y2 = state->crtc_y + state->crtc_h;
intel_state->clip.x1 = 0;
intel_state->clip.y1 = 0;
intel_state->clip.x2 =
intel_crtc->active ? intel_crtc->config->pipe_src_w : 0;
intel_state->clip.y2 =
intel_crtc->active ? intel_crtc->config->pipe_src_h : 0;
if (state->fb == NULL && plane->state->fb != NULL) {
intel_crtc->atomic.disabled_planes |=
(1 << drm_plane_index(plane));
}
return intel_plane->check_plane(plane, intel_state);
}
static void intel_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct intel_plane *intel_plane = to_intel_plane(plane);
struct intel_plane_state *intel_state =
to_intel_plane_state(plane->state);
if (!plane->state->fb && !old_state->fb)
return;
intel_plane->commit_plane(plane, intel_state);
}
int
intel_plane_atomic_get_property(struct drm_plane *plane,
const struct drm_plane_state *state,
struct drm_property *property,
uint64_t *val)
{
DRM_DEBUG_KMS("Unknown plane property '%s'\n", property->name);
return -EINVAL;
}
int
intel_plane_atomic_set_property(struct drm_plane *plane,
struct drm_plane_state *state,
struct drm_property *property,
uint64_t val)
{
DRM_DEBUG_KMS("Unknown plane property '%s'\n", property->name);
return -EINVAL;
}
