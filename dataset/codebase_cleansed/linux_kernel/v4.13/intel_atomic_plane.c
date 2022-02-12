struct intel_plane_state *
intel_create_plane_state(struct drm_plane *plane)
{
struct intel_plane_state *state;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
state->base.plane = plane;
state->base.rotation = DRM_MODE_ROTATE_0;
state->ckey.flags = I915_SET_COLORKEY_NONE;
return state;
}
struct drm_plane_state *
intel_plane_duplicate_state(struct drm_plane *plane)
{
struct drm_plane_state *state;
struct intel_plane_state *intel_state;
intel_state = kmemdup(plane->state, sizeof(*intel_state), GFP_KERNEL);
if (!intel_state)
return NULL;
state = &intel_state->base;
__drm_atomic_helper_plane_duplicate_state(plane, state);
intel_state->vma = NULL;
return state;
}
void
intel_plane_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
WARN_ON(to_intel_plane_state(state)->vma);
drm_atomic_helper_plane_destroy_state(plane, state);
}
int intel_plane_atomic_check_with_state(struct intel_crtc_state *crtc_state,
struct intel_plane_state *intel_state)
{
struct drm_plane *plane = intel_state->base.plane;
struct drm_i915_private *dev_priv = to_i915(plane->dev);
struct drm_plane_state *state = &intel_state->base;
struct intel_plane *intel_plane = to_intel_plane(plane);
int ret;
if (!intel_state->base.crtc && !plane->state->crtc)
return 0;
intel_state->clip.x1 = 0;
intel_state->clip.y1 = 0;
intel_state->clip.x2 =
crtc_state->base.enable ? crtc_state->pipe_src_w : 0;
intel_state->clip.y2 =
crtc_state->base.enable ? crtc_state->pipe_src_h : 0;
if (state->fb && drm_rotation_90_or_270(state->rotation)) {
struct drm_format_name_buf format_name;
if (state->fb->modifier != I915_FORMAT_MOD_Y_TILED &&
state->fb->modifier != I915_FORMAT_MOD_Yf_TILED) {
DRM_DEBUG_KMS("Y/Yf tiling required for 90/270!\n");
return -EINVAL;
}
switch (state->fb->format->format) {
case DRM_FORMAT_C8:
case DRM_FORMAT_RGB565:
DRM_DEBUG_KMS("Unsupported pixel format %s for 90/270!\n",
drm_get_format_name(state->fb->format->format,
&format_name));
return -EINVAL;
default:
break;
}
}
if (IS_CHERRYVIEW(dev_priv) &&
state->rotation & DRM_MODE_ROTATE_180 &&
state->rotation & DRM_MODE_REFLECT_X) {
DRM_DEBUG_KMS("Cannot rotate and reflect at the same time\n");
return -EINVAL;
}
intel_state->base.visible = false;
ret = intel_plane->check_plane(intel_plane, crtc_state, intel_state);
if (ret)
return ret;
if (intel_state->base.visible)
crtc_state->active_planes |= BIT(intel_plane->id);
else
crtc_state->active_planes &= ~BIT(intel_plane->id);
return intel_plane_atomic_calc_changes(&crtc_state->base, state);
}
static int intel_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_crtc *crtc = state->crtc;
struct drm_crtc_state *drm_crtc_state;
crtc = crtc ? crtc : plane->state->crtc;
if (!crtc)
return 0;
drm_crtc_state = drm_atomic_get_existing_crtc_state(state->state, crtc);
if (WARN_ON(!drm_crtc_state))
return -EINVAL;
return intel_plane_atomic_check_with_state(to_intel_crtc_state(drm_crtc_state),
to_intel_plane_state(state));
}
static void intel_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct intel_plane *intel_plane = to_intel_plane(plane);
struct intel_plane_state *intel_state =
to_intel_plane_state(plane->state);
struct drm_crtc *crtc = plane->state->crtc ?: old_state->crtc;
if (intel_state->base.visible) {
trace_intel_update_plane(plane,
to_intel_crtc(crtc));
intel_plane->update_plane(intel_plane,
to_intel_crtc_state(crtc->state),
intel_state);
} else {
trace_intel_disable_plane(plane,
to_intel_crtc(crtc));
intel_plane->disable_plane(intel_plane, to_intel_crtc(crtc));
}
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
