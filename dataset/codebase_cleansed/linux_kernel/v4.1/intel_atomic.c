int intel_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
int nplanes = dev->mode_config.num_total_plane;
int ncrtcs = dev->mode_config.num_crtc;
int nconnectors = dev->mode_config.num_connector;
enum pipe nuclear_pipe = INVALID_PIPE;
int ret;
int i;
bool not_nuclear = false;
for (i = 0; i < nplanes; i++) {
struct intel_plane *plane = to_intel_plane(state->planes[i]);
if (!plane)
continue;
if (nuclear_pipe == INVALID_PIPE) {
nuclear_pipe = plane->pipe;
} else if (nuclear_pipe != plane->pipe) {
DRM_DEBUG_KMS("i915 only support atomic plane operations on a single CRTC at the moment\n");
return -EINVAL;
}
}
state->allow_modeset = false;
for (i = 0; i < ncrtcs; i++) {
struct intel_crtc *crtc = to_intel_crtc(state->crtcs[i]);
if (crtc && crtc->pipe != nuclear_pipe)
not_nuclear = true;
}
for (i = 0; i < nconnectors; i++)
if (state->connectors[i] != NULL)
not_nuclear = true;
if (not_nuclear) {
DRM_DEBUG_KMS("i915 only supports atomic plane operations at the moment\n");
return -EINVAL;
}
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
return ret;
}
int intel_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state,
bool async)
{
int ret;
int i;
if (async) {
DRM_DEBUG_KMS("i915 does not yet support async commit\n");
return -EINVAL;
}
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
for (i = 0; i < dev->mode_config.num_total_plane; i++) {
struct drm_plane *plane = state->planes[i];
if (!plane)
continue;
plane->state->state = state;
swap(state->plane_states[i], plane->state);
plane->state->state = NULL;
}
drm_atomic_helper_commit_planes(dev, state);
drm_atomic_helper_wait_for_vblanks(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
drm_atomic_state_free(state);
return 0;
}
int
intel_connector_atomic_get_property(struct drm_connector *connector,
const struct drm_connector_state *state,
struct drm_property *property,
uint64_t *val)
{
int i;
for (i = 0; i < connector->base.properties->count; i++) {
if (connector->base.properties->properties[i] == property) {
*val = connector->base.properties->values[i];
return 0;
}
}
return -EINVAL;
}
struct drm_crtc_state *
intel_crtc_duplicate_state(struct drm_crtc *crtc)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_crtc_state *crtc_state;
if (WARN_ON(!intel_crtc->config))
crtc_state = kzalloc(sizeof(*crtc_state), GFP_KERNEL);
else
crtc_state = kmemdup(intel_crtc->config,
sizeof(*intel_crtc->config), GFP_KERNEL);
if (crtc_state)
crtc_state->base.crtc = crtc;
return &crtc_state->base;
}
void
intel_crtc_destroy_state(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
drm_atomic_helper_crtc_destroy_state(crtc, state);
}
