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
struct intel_crtc_state *crtc_state;
crtc_state = kmemdup(crtc->state, sizeof(*crtc_state), GFP_KERNEL);
if (!crtc_state)
return NULL;
__drm_atomic_helper_crtc_duplicate_state(crtc, &crtc_state->base);
crtc_state->update_pipe = false;
crtc_state->disable_lp_wm = false;
crtc_state->disable_cxsr = false;
crtc_state->wm_changed = false;
return &crtc_state->base;
}
void
intel_crtc_destroy_state(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
drm_atomic_helper_crtc_destroy_state(crtc, state);
}
int intel_atomic_setup_scalers(struct drm_device *dev,
struct intel_crtc *intel_crtc,
struct intel_crtc_state *crtc_state)
{
struct drm_plane *plane = NULL;
struct intel_plane *intel_plane;
struct intel_plane_state *plane_state = NULL;
struct intel_crtc_scaler_state *scaler_state =
&crtc_state->scaler_state;
struct drm_atomic_state *drm_state = crtc_state->base.state;
int num_scalers_need;
int i, j;
num_scalers_need = hweight32(scaler_state->scaler_users);
if (num_scalers_need > intel_crtc->num_scalers){
DRM_DEBUG_KMS("Too many scaling requests %d > %d\n",
num_scalers_need, intel_crtc->num_scalers);
return -EINVAL;
}
for (i = 0; i < sizeof(scaler_state->scaler_users) * 8; i++) {
int *scaler_id;
const char *name;
int idx;
if (!(scaler_state->scaler_users & (1 << i)))
continue;
if (i == SKL_CRTC_INDEX) {
name = "CRTC";
idx = intel_crtc->base.base.id;
scaler_id = &scaler_state->scaler_id;
} else {
name = "PLANE";
plane = drm_state->planes[i];
if (!plane) {
struct drm_plane_state *state;
plane = drm_plane_from_index(dev, i);
state = drm_atomic_get_plane_state(drm_state, plane);
if (IS_ERR(state)) {
DRM_DEBUG_KMS("Failed to add [PLANE:%d] to drm_state\n",
plane->base.id);
return PTR_ERR(state);
}
crtc_state->base.planes_changed = true;
}
intel_plane = to_intel_plane(plane);
idx = plane->base.id;
if (WARN_ON(intel_plane->pipe != intel_crtc->pipe)) {
continue;
}
plane_state = to_intel_plane_state(drm_state->plane_states[i]);
scaler_id = &plane_state->scaler_id;
}
if (*scaler_id < 0) {
for (j = 0; j < intel_crtc->num_scalers; j++) {
if (!scaler_state->scalers[j].in_use) {
scaler_state->scalers[j].in_use = 1;
*scaler_id = j;
DRM_DEBUG_KMS("Attached scaler id %u.%u to %s:%d\n",
intel_crtc->pipe, *scaler_id, name, idx);
break;
}
}
}
if (WARN_ON(*scaler_id < 0)) {
DRM_DEBUG_KMS("Cannot find scaler for %s:%d\n", name, idx);
continue;
}
if (num_scalers_need == 1 && intel_crtc->pipe != PIPE_C) {
*scaler_id = 0;
scaler_state->scalers[0].in_use = 1;
scaler_state->scalers[0].mode = PS_SCALER_MODE_HQ;
scaler_state->scalers[1].in_use = 0;
} else {
scaler_state->scalers[*scaler_id].mode = PS_SCALER_MODE_DYN;
}
}
return 0;
}
static void
intel_atomic_duplicate_dpll_state(struct drm_i915_private *dev_priv,
struct intel_shared_dpll_config *shared_dpll)
{
enum intel_dpll_id i;
for (i = 0; i < dev_priv->num_shared_dpll; i++) {
struct intel_shared_dpll *pll = &dev_priv->shared_dplls[i];
shared_dpll[i] = pll->config;
}
}
struct intel_shared_dpll_config *
intel_atomic_get_shared_dpll_state(struct drm_atomic_state *s)
{
struct intel_atomic_state *state = to_intel_atomic_state(s);
WARN_ON(!drm_modeset_is_locked(&s->dev->mode_config.connection_mutex));
if (!state->dpll_set) {
state->dpll_set = true;
intel_atomic_duplicate_dpll_state(to_i915(s->dev),
state->shared_dpll);
}
return state->shared_dpll;
}
struct drm_atomic_state *
intel_atomic_state_alloc(struct drm_device *dev)
{
struct intel_atomic_state *state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state || drm_atomic_state_init(dev, &state->base) < 0) {
kfree(state);
return NULL;
}
return &state->base;
}
void intel_atomic_state_clear(struct drm_atomic_state *s)
{
struct intel_atomic_state *state = to_intel_atomic_state(s);
drm_atomic_state_default_clear(&state->base);
state->dpll_set = false;
}
