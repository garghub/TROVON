int intel_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
int nplanes = dev->mode_config.num_total_plane;
int ncrtcs = dev->mode_config.num_crtc;
int nconnectors = dev->mode_config.num_connector;
enum pipe nuclear_pipe = INVALID_PIPE;
struct intel_crtc *nuclear_crtc = NULL;
struct intel_crtc_state *crtc_state = NULL;
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
if (crtc)
memset(&crtc->atomic, 0, sizeof(crtc->atomic));
if (crtc && crtc->pipe != nuclear_pipe)
not_nuclear = true;
if (crtc && crtc->pipe == nuclear_pipe) {
nuclear_crtc = crtc;
crtc_state = to_intel_crtc_state(state->crtc_states[i]);
}
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
ret = intel_atomic_setup_scalers(dev, nuclear_crtc, crtc_state);
if (ret)
return ret;
return ret;
}
int intel_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state,
bool async)
{
struct drm_crtc_state *crtc_state;
struct drm_crtc *crtc;
int ret, i;
if (async) {
DRM_DEBUG_KMS("i915 does not yet support async commit\n");
return -EINVAL;
}
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
drm_atomic_helper_swap_state(dev, state);
for_each_crtc_in_state(state, crtc, crtc_state, i) {
to_intel_crtc(crtc)->config = to_intel_crtc_state(crtc->state);
if (INTEL_INFO(dev)->gen >= 9)
skl_detach_scalers(to_intel_crtc(crtc));
drm_atomic_helper_commit_planes_on_crtc(crtc_state);
}
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
if (!crtc_state)
return NULL;
__drm_atomic_helper_crtc_duplicate_state(crtc, &crtc_state->base);
crtc_state->base.crtc = crtc;
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
struct intel_crtc_scaler_state *scaler_state;
struct drm_atomic_state *drm_state;
int num_scalers_need;
int i, j;
if (INTEL_INFO(dev)->gen < 9 || !intel_crtc || !crtc_state)
return 0;
scaler_state = &crtc_state->scaler_state;
drm_state = crtc_state->base.state;
num_scalers_need = hweight32(scaler_state->scaler_users);
DRM_DEBUG_KMS("crtc_state = %p need = %d avail = %d scaler_users = 0x%x\n",
crtc_state, num_scalers_need, intel_crtc->num_scalers,
scaler_state->scaler_users);
if (num_scalers_need > intel_crtc->num_scalers){
DRM_DEBUG_KMS("Too many scaling requests %d > %d\n",
num_scalers_need, intel_crtc->num_scalers);
return -EINVAL;
}
for (i = 0; i < sizeof(scaler_state->scaler_users) * 8; i++) {
int *scaler_id;
if (!(scaler_state->scaler_users & (1 << i)))
continue;
if (i == SKL_CRTC_INDEX) {
scaler_id = &scaler_state->scaler_id;
} else {
if (!drm_state)
continue;
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
}
intel_plane = to_intel_plane(plane);
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
*scaler_id = scaler_state->scalers[j].id;
DRM_DEBUG_KMS("Attached scaler id %u.%u to %s:%d\n",
intel_crtc->pipe,
i == SKL_CRTC_INDEX ? scaler_state->scaler_id :
plane_state->scaler_id,
i == SKL_CRTC_INDEX ? "CRTC" : "PLANE",
i == SKL_CRTC_INDEX ? intel_crtc->base.base.id :
plane->base.id);
break;
}
}
}
if (WARN_ON(*scaler_id < 0)) {
DRM_DEBUG_KMS("Cannot find scaler for %s:%d\n",
i == SKL_CRTC_INDEX ? "CRTC" : "PLANE",
i == SKL_CRTC_INDEX ? intel_crtc->base.base.id:plane->base.id);
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
