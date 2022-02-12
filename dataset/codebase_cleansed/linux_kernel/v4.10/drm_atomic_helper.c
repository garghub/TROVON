static void
drm_atomic_helper_plane_changed(struct drm_atomic_state *state,
struct drm_plane_state *plane_state,
struct drm_plane *plane)
{
struct drm_crtc_state *crtc_state;
if (plane->state->crtc) {
crtc_state = drm_atomic_get_existing_crtc_state(state,
plane->state->crtc);
if (WARN_ON(!crtc_state))
return;
crtc_state->planes_changed = true;
}
if (plane_state->crtc) {
crtc_state = drm_atomic_get_existing_crtc_state(state,
plane_state->crtc);
if (WARN_ON(!crtc_state))
return;
crtc_state->planes_changed = true;
}
}
static int handle_conflicting_encoders(struct drm_atomic_state *state,
bool disable_conflicting_encoders)
{
struct drm_connector_state *conn_state;
struct drm_connector *connector;
struct drm_encoder *encoder;
unsigned encoder_mask = 0;
int i, ret;
for_each_connector_in_state(state, connector, conn_state, i) {
const struct drm_connector_helper_funcs *funcs = connector->helper_private;
struct drm_encoder *new_encoder;
if (!conn_state->crtc)
continue;
if (funcs->atomic_best_encoder)
new_encoder = funcs->atomic_best_encoder(connector, conn_state);
else if (funcs->best_encoder)
new_encoder = funcs->best_encoder(connector);
else
new_encoder = drm_atomic_helper_best_encoder(connector);
if (new_encoder) {
if (encoder_mask & (1 << drm_encoder_index(new_encoder))) {
DRM_DEBUG_ATOMIC("[ENCODER:%d:%s] on [CONNECTOR:%d:%s] already assigned\n",
new_encoder->base.id, new_encoder->name,
connector->base.id, connector->name);
return -EINVAL;
}
encoder_mask |= 1 << drm_encoder_index(new_encoder);
}
}
if (!encoder_mask)
return 0;
drm_for_each_connector(connector, state->dev) {
struct drm_crtc_state *crtc_state;
if (drm_atomic_get_existing_connector_state(state, connector))
continue;
encoder = connector->state->best_encoder;
if (!encoder || !(encoder_mask & (1 << drm_encoder_index(encoder))))
continue;
if (!disable_conflicting_encoders) {
DRM_DEBUG_ATOMIC("[ENCODER:%d:%s] in use on [CRTC:%d:%s] by [CONNECTOR:%d:%s]\n",
encoder->base.id, encoder->name,
connector->state->crtc->base.id,
connector->state->crtc->name,
connector->base.id, connector->name);
return -EINVAL;
}
conn_state = drm_atomic_get_connector_state(state, connector);
if (IS_ERR(conn_state))
return PTR_ERR(conn_state);
DRM_DEBUG_ATOMIC("[ENCODER:%d:%s] in use on [CRTC:%d:%s], disabling [CONNECTOR:%d:%s]\n",
encoder->base.id, encoder->name,
conn_state->crtc->base.id, conn_state->crtc->name,
connector->base.id, connector->name);
crtc_state = drm_atomic_get_existing_crtc_state(state, conn_state->crtc);
ret = drm_atomic_set_crtc_for_connector(conn_state, NULL);
if (ret)
return ret;
if (!crtc_state->connector_mask) {
ret = drm_atomic_set_mode_prop_for_crtc(crtc_state,
NULL);
if (ret < 0)
return ret;
crtc_state->active = false;
}
}
return 0;
}
static void
set_best_encoder(struct drm_atomic_state *state,
struct drm_connector_state *conn_state,
struct drm_encoder *encoder)
{
struct drm_crtc_state *crtc_state;
struct drm_crtc *crtc;
if (conn_state->best_encoder) {
crtc = conn_state->connector->state->crtc;
WARN_ON(!crtc && encoder != conn_state->best_encoder);
if (crtc) {
crtc_state = drm_atomic_get_existing_crtc_state(state, crtc);
crtc_state->encoder_mask &=
~(1 << drm_encoder_index(conn_state->best_encoder));
}
}
if (encoder) {
crtc = conn_state->crtc;
WARN_ON(!crtc);
if (crtc) {
crtc_state = drm_atomic_get_existing_crtc_state(state, crtc);
crtc_state->encoder_mask |=
1 << drm_encoder_index(encoder);
}
}
conn_state->best_encoder = encoder;
}
static void
steal_encoder(struct drm_atomic_state *state,
struct drm_encoder *encoder)
{
struct drm_crtc_state *crtc_state;
struct drm_connector *connector;
struct drm_connector_state *connector_state;
int i;
for_each_connector_in_state(state, connector, connector_state, i) {
struct drm_crtc *encoder_crtc;
if (connector_state->best_encoder != encoder)
continue;
encoder_crtc = connector->state->crtc;
DRM_DEBUG_ATOMIC("[ENCODER:%d:%s] in use on [CRTC:%d:%s], stealing it\n",
encoder->base.id, encoder->name,
encoder_crtc->base.id, encoder_crtc->name);
set_best_encoder(state, connector_state, NULL);
crtc_state = drm_atomic_get_existing_crtc_state(state, encoder_crtc);
crtc_state->connectors_changed = true;
return;
}
}
static int
update_connector_routing(struct drm_atomic_state *state,
struct drm_connector *connector,
struct drm_connector_state *connector_state)
{
const struct drm_connector_helper_funcs *funcs;
struct drm_encoder *new_encoder;
struct drm_crtc_state *crtc_state;
DRM_DEBUG_ATOMIC("Updating routing for [CONNECTOR:%d:%s]\n",
connector->base.id,
connector->name);
if (connector->state->crtc != connector_state->crtc) {
if (connector->state->crtc) {
crtc_state = drm_atomic_get_existing_crtc_state(state, connector->state->crtc);
crtc_state->connectors_changed = true;
}
if (connector_state->crtc) {
crtc_state = drm_atomic_get_existing_crtc_state(state, connector_state->crtc);
crtc_state->connectors_changed = true;
}
}
if (!connector_state->crtc) {
DRM_DEBUG_ATOMIC("Disabling [CONNECTOR:%d:%s]\n",
connector->base.id,
connector->name);
set_best_encoder(state, connector_state, NULL);
return 0;
}
funcs = connector->helper_private;
if (funcs->atomic_best_encoder)
new_encoder = funcs->atomic_best_encoder(connector,
connector_state);
else if (funcs->best_encoder)
new_encoder = funcs->best_encoder(connector);
else
new_encoder = drm_atomic_helper_best_encoder(connector);
if (!new_encoder) {
DRM_DEBUG_ATOMIC("No suitable encoder found for [CONNECTOR:%d:%s]\n",
connector->base.id,
connector->name);
return -EINVAL;
}
if (!drm_encoder_crtc_ok(new_encoder, connector_state->crtc)) {
DRM_DEBUG_ATOMIC("[ENCODER:%d:%s] incompatible with [CRTC:%d]\n",
new_encoder->base.id,
new_encoder->name,
connector_state->crtc->base.id);
return -EINVAL;
}
if (new_encoder == connector_state->best_encoder) {
set_best_encoder(state, connector_state, new_encoder);
DRM_DEBUG_ATOMIC("[CONNECTOR:%d:%s] keeps [ENCODER:%d:%s], now on [CRTC:%d:%s]\n",
connector->base.id,
connector->name,
new_encoder->base.id,
new_encoder->name,
connector_state->crtc->base.id,
connector_state->crtc->name);
return 0;
}
steal_encoder(state, new_encoder);
set_best_encoder(state, connector_state, new_encoder);
crtc_state = drm_atomic_get_existing_crtc_state(state, connector_state->crtc);
crtc_state->connectors_changed = true;
DRM_DEBUG_ATOMIC("[CONNECTOR:%d:%s] using [ENCODER:%d:%s] on [CRTC:%d:%s]\n",
connector->base.id,
connector->name,
new_encoder->base.id,
new_encoder->name,
connector_state->crtc->base.id,
connector_state->crtc->name);
return 0;
}
static int
mode_fixup(struct drm_atomic_state *state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_connector *connector;
struct drm_connector_state *conn_state;
int i;
bool ret;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
if (!crtc_state->mode_changed &&
!crtc_state->connectors_changed)
continue;
drm_mode_copy(&crtc_state->adjusted_mode, &crtc_state->mode);
}
for_each_connector_in_state(state, connector, conn_state, i) {
const struct drm_encoder_helper_funcs *funcs;
struct drm_encoder *encoder;
WARN_ON(!!conn_state->best_encoder != !!conn_state->crtc);
if (!conn_state->crtc || !conn_state->best_encoder)
continue;
crtc_state = drm_atomic_get_existing_crtc_state(state,
conn_state->crtc);
encoder = conn_state->best_encoder;
funcs = encoder->helper_private;
ret = drm_bridge_mode_fixup(encoder->bridge, &crtc_state->mode,
&crtc_state->adjusted_mode);
if (!ret) {
DRM_DEBUG_ATOMIC("Bridge fixup failed\n");
return -EINVAL;
}
if (funcs && funcs->atomic_check) {
ret = funcs->atomic_check(encoder, crtc_state,
conn_state);
if (ret) {
DRM_DEBUG_ATOMIC("[ENCODER:%d:%s] check failed\n",
encoder->base.id, encoder->name);
return ret;
}
} else if (funcs && funcs->mode_fixup) {
ret = funcs->mode_fixup(encoder, &crtc_state->mode,
&crtc_state->adjusted_mode);
if (!ret) {
DRM_DEBUG_ATOMIC("[ENCODER:%d:%s] fixup failed\n",
encoder->base.id, encoder->name);
return -EINVAL;
}
}
}
for_each_crtc_in_state(state, crtc, crtc_state, i) {
const struct drm_crtc_helper_funcs *funcs;
if (!crtc_state->enable)
continue;
if (!crtc_state->mode_changed &&
!crtc_state->connectors_changed)
continue;
funcs = crtc->helper_private;
if (!funcs->mode_fixup)
continue;
ret = funcs->mode_fixup(crtc, &crtc_state->mode,
&crtc_state->adjusted_mode);
if (!ret) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] fixup failed\n",
crtc->base.id, crtc->name);
return -EINVAL;
}
}
return 0;
}
int
drm_atomic_helper_check_modeset(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_connector *connector;
struct drm_connector_state *connector_state;
int i, ret;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
if (!drm_mode_equal(&crtc->state->mode, &crtc_state->mode)) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] mode changed\n",
crtc->base.id, crtc->name);
crtc_state->mode_changed = true;
}
if (crtc->state->enable != crtc_state->enable) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] enable changed\n",
crtc->base.id, crtc->name);
crtc_state->mode_changed = true;
crtc_state->connectors_changed = true;
}
}
ret = handle_conflicting_encoders(state, state->legacy_set_config);
if (ret)
return ret;
for_each_connector_in_state(state, connector, connector_state, i) {
ret = update_connector_routing(state, connector,
connector_state);
if (ret)
return ret;
}
for_each_crtc_in_state(state, crtc, crtc_state, i) {
bool has_connectors =
!!crtc_state->connector_mask;
if (crtc->state->active != crtc_state->active) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] active changed\n",
crtc->base.id, crtc->name);
crtc_state->active_changed = true;
}
if (!drm_atomic_crtc_needs_modeset(crtc_state))
continue;
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] needs all connectors, enable: %c, active: %c\n",
crtc->base.id, crtc->name,
crtc_state->enable ? 'y' : 'n',
crtc_state->active ? 'y' : 'n');
ret = drm_atomic_add_affected_connectors(state, crtc);
if (ret != 0)
return ret;
ret = drm_atomic_add_affected_planes(state, crtc);
if (ret != 0)
return ret;
if (crtc_state->enable != has_connectors) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] enabled/connectors mismatch\n",
crtc->base.id, crtc->name);
return -EINVAL;
}
}
return mode_fixup(state);
}
int
drm_atomic_helper_check_planes(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_plane *plane;
struct drm_plane_state *plane_state;
int i, ret = 0;
for_each_plane_in_state(state, plane, plane_state, i) {
const struct drm_plane_helper_funcs *funcs;
funcs = plane->helper_private;
drm_atomic_helper_plane_changed(state, plane_state, plane);
if (!funcs || !funcs->atomic_check)
continue;
ret = funcs->atomic_check(plane, plane_state);
if (ret) {
DRM_DEBUG_ATOMIC("[PLANE:%d:%s] atomic driver check failed\n",
plane->base.id, plane->name);
return ret;
}
}
for_each_crtc_in_state(state, crtc, crtc_state, i) {
const struct drm_crtc_helper_funcs *funcs;
funcs = crtc->helper_private;
if (!funcs || !funcs->atomic_check)
continue;
ret = funcs->atomic_check(crtc, crtc_state);
if (ret) {
DRM_DEBUG_ATOMIC("[CRTC:%d:%s] atomic driver check failed\n",
crtc->base.id, crtc->name);
return ret;
}
}
return ret;
}
int drm_atomic_helper_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
int ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
return ret;
}
static void
disable_outputs(struct drm_device *dev, struct drm_atomic_state *old_state)
{
struct drm_connector *connector;
struct drm_connector_state *old_conn_state;
struct drm_crtc *crtc;
struct drm_crtc_state *old_crtc_state;
int i;
for_each_connector_in_state(old_state, connector, old_conn_state, i) {
const struct drm_encoder_helper_funcs *funcs;
struct drm_encoder *encoder;
if (!old_conn_state->crtc)
continue;
old_crtc_state = drm_atomic_get_existing_crtc_state(old_state,
old_conn_state->crtc);
if (!old_crtc_state->active ||
!drm_atomic_crtc_needs_modeset(old_conn_state->crtc->state))
continue;
encoder = old_conn_state->best_encoder;
if (WARN_ON(!encoder))
continue;
funcs = encoder->helper_private;
DRM_DEBUG_ATOMIC("disabling [ENCODER:%d:%s]\n",
encoder->base.id, encoder->name);
drm_bridge_disable(encoder->bridge);
if (funcs) {
if (connector->state->crtc && funcs->prepare)
funcs->prepare(encoder);
else if (funcs->disable)
funcs->disable(encoder);
else if (funcs->dpms)
funcs->dpms(encoder, DRM_MODE_DPMS_OFF);
}
drm_bridge_post_disable(encoder->bridge);
}
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
const struct drm_crtc_helper_funcs *funcs;
if (!drm_atomic_crtc_needs_modeset(crtc->state))
continue;
if (!old_crtc_state->active)
continue;
funcs = crtc->helper_private;
DRM_DEBUG_ATOMIC("disabling [CRTC:%d:%s]\n",
crtc->base.id, crtc->name);
if (crtc->state->enable && funcs->prepare)
funcs->prepare(crtc);
else if (funcs->atomic_disable)
funcs->atomic_disable(crtc, old_crtc_state);
else if (funcs->disable)
funcs->disable(crtc);
else
funcs->dpms(crtc, DRM_MODE_DPMS_OFF);
}
}
void
drm_atomic_helper_update_legacy_modeset_state(struct drm_device *dev,
struct drm_atomic_state *old_state)
{
struct drm_connector *connector;
struct drm_connector_state *old_conn_state;
struct drm_crtc *crtc;
struct drm_crtc_state *old_crtc_state;
int i;
for_each_connector_in_state(old_state, connector, old_conn_state, i) {
if (connector->encoder) {
WARN_ON(!connector->encoder->crtc);
connector->encoder->crtc = NULL;
connector->encoder = NULL;
}
crtc = connector->state->crtc;
if ((!crtc && old_conn_state->crtc) ||
(crtc && drm_atomic_crtc_needs_modeset(crtc->state))) {
struct drm_property *dpms_prop =
dev->mode_config.dpms_property;
int mode = DRM_MODE_DPMS_OFF;
if (crtc && crtc->state->active)
mode = DRM_MODE_DPMS_ON;
connector->dpms = mode;
drm_object_property_set_value(&connector->base,
dpms_prop, mode);
}
}
for_each_connector_in_state(old_state, connector, old_conn_state, i) {
if (!connector->state->crtc)
continue;
if (WARN_ON(!connector->state->best_encoder))
continue;
connector->encoder = connector->state->best_encoder;
connector->encoder->crtc = connector->state->crtc;
}
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
struct drm_plane *primary = crtc->primary;
crtc->mode = crtc->state->mode;
crtc->enabled = crtc->state->enable;
if (drm_atomic_get_existing_plane_state(old_state, primary) &&
primary->state->crtc == crtc) {
crtc->x = primary->state->src_x >> 16;
crtc->y = primary->state->src_y >> 16;
}
if (crtc->state->enable)
drm_calc_timestamping_constants(crtc,
&crtc->state->adjusted_mode);
}
}
static void
crtc_set_mode(struct drm_device *dev, struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *old_crtc_state;
struct drm_connector *connector;
struct drm_connector_state *old_conn_state;
int i;
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
const struct drm_crtc_helper_funcs *funcs;
if (!crtc->state->mode_changed)
continue;
funcs = crtc->helper_private;
if (crtc->state->enable && funcs->mode_set_nofb) {
DRM_DEBUG_ATOMIC("modeset on [CRTC:%d:%s]\n",
crtc->base.id, crtc->name);
funcs->mode_set_nofb(crtc);
}
}
for_each_connector_in_state(old_state, connector, old_conn_state, i) {
const struct drm_encoder_helper_funcs *funcs;
struct drm_crtc_state *new_crtc_state;
struct drm_encoder *encoder;
struct drm_display_mode *mode, *adjusted_mode;
if (!connector->state->best_encoder)
continue;
encoder = connector->state->best_encoder;
funcs = encoder->helper_private;
new_crtc_state = connector->state->crtc->state;
mode = &new_crtc_state->mode;
adjusted_mode = &new_crtc_state->adjusted_mode;
if (!new_crtc_state->mode_changed)
continue;
DRM_DEBUG_ATOMIC("modeset on [ENCODER:%d:%s]\n",
encoder->base.id, encoder->name);
if (funcs && funcs->atomic_mode_set) {
funcs->atomic_mode_set(encoder, new_crtc_state,
connector->state);
} else if (funcs && funcs->mode_set) {
funcs->mode_set(encoder, mode, adjusted_mode);
}
drm_bridge_mode_set(encoder->bridge, mode, adjusted_mode);
}
}
void drm_atomic_helper_commit_modeset_disables(struct drm_device *dev,
struct drm_atomic_state *old_state)
{
disable_outputs(dev, old_state);
drm_atomic_helper_update_legacy_modeset_state(dev, old_state);
crtc_set_mode(dev, old_state);
}
void drm_atomic_helper_commit_modeset_enables(struct drm_device *dev,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *old_crtc_state;
struct drm_connector *connector;
struct drm_connector_state *old_conn_state;
int i;
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
const struct drm_crtc_helper_funcs *funcs;
if (!drm_atomic_crtc_needs_modeset(crtc->state))
continue;
if (!crtc->state->active)
continue;
funcs = crtc->helper_private;
if (crtc->state->enable) {
DRM_DEBUG_ATOMIC("enabling [CRTC:%d:%s]\n",
crtc->base.id, crtc->name);
if (funcs->enable)
funcs->enable(crtc);
else
funcs->commit(crtc);
}
}
for_each_connector_in_state(old_state, connector, old_conn_state, i) {
const struct drm_encoder_helper_funcs *funcs;
struct drm_encoder *encoder;
if (!connector->state->best_encoder)
continue;
if (!connector->state->crtc->state->active ||
!drm_atomic_crtc_needs_modeset(connector->state->crtc->state))
continue;
encoder = connector->state->best_encoder;
funcs = encoder->helper_private;
DRM_DEBUG_ATOMIC("enabling [ENCODER:%d:%s]\n",
encoder->base.id, encoder->name);
drm_bridge_pre_enable(encoder->bridge);
if (funcs) {
if (funcs->enable)
funcs->enable(encoder);
else if (funcs->commit)
funcs->commit(encoder);
}
drm_bridge_enable(encoder->bridge);
}
}
int drm_atomic_helper_wait_for_fences(struct drm_device *dev,
struct drm_atomic_state *state,
bool pre_swap)
{
struct drm_plane *plane;
struct drm_plane_state *plane_state;
int i, ret;
for_each_plane_in_state(state, plane, plane_state, i) {
if (!pre_swap)
plane_state = plane->state;
if (!plane_state->fence)
continue;
WARN_ON(!plane_state->fb);
ret = dma_fence_wait(plane_state->fence, pre_swap);
if (ret)
return ret;
dma_fence_put(plane_state->fence);
plane_state->fence = NULL;
}
return 0;
}
bool drm_atomic_helper_framebuffer_changed(struct drm_device *dev,
struct drm_atomic_state *old_state,
struct drm_crtc *crtc)
{
struct drm_plane *plane;
struct drm_plane_state *old_plane_state;
int i;
for_each_plane_in_state(old_state, plane, old_plane_state, i) {
if (plane->state->crtc != crtc &&
old_plane_state->crtc != crtc)
continue;
if (plane->state->fb != old_plane_state->fb)
return true;
}
return false;
}
void
drm_atomic_helper_wait_for_vblanks(struct drm_device *dev,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *old_crtc_state;
int i, ret;
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
old_crtc_state->enable = false;
if (!crtc->state->enable)
continue;
if (old_state->legacy_cursor_update)
continue;
if (!drm_atomic_helper_framebuffer_changed(dev,
old_state, crtc))
continue;
ret = drm_crtc_vblank_get(crtc);
if (ret != 0)
continue;
old_crtc_state->enable = true;
old_crtc_state->last_vblank_count = drm_crtc_vblank_count(crtc);
}
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
if (!old_crtc_state->enable)
continue;
ret = wait_event_timeout(dev->vblank[i].queue,
old_crtc_state->last_vblank_count !=
drm_crtc_vblank_count(crtc),
msecs_to_jiffies(50));
WARN(!ret, "[CRTC:%d] vblank wait timed out\n", crtc->base.id);
drm_crtc_vblank_put(crtc);
}
}
void drm_atomic_helper_commit_tail(struct drm_atomic_state *old_state)
{
struct drm_device *dev = old_state->dev;
drm_atomic_helper_commit_modeset_disables(dev, old_state);
drm_atomic_helper_commit_planes(dev, old_state, 0);
drm_atomic_helper_commit_modeset_enables(dev, old_state);
drm_atomic_helper_commit_hw_done(old_state);
drm_atomic_helper_wait_for_vblanks(dev, old_state);
drm_atomic_helper_cleanup_planes(dev, old_state);
}
static void commit_tail(struct drm_atomic_state *old_state)
{
struct drm_device *dev = old_state->dev;
struct drm_mode_config_helper_funcs *funcs;
funcs = dev->mode_config.helper_private;
drm_atomic_helper_wait_for_fences(dev, old_state, false);
drm_atomic_helper_wait_for_dependencies(old_state);
if (funcs && funcs->atomic_commit_tail)
funcs->atomic_commit_tail(old_state);
else
drm_atomic_helper_commit_tail(old_state);
drm_atomic_helper_commit_cleanup_done(old_state);
drm_atomic_state_put(old_state);
}
static void commit_work(struct work_struct *work)
{
struct drm_atomic_state *state = container_of(work,
struct drm_atomic_state,
commit_work);
commit_tail(state);
}
int drm_atomic_helper_commit(struct drm_device *dev,
struct drm_atomic_state *state,
bool nonblock)
{
int ret;
ret = drm_atomic_helper_setup_commit(state, nonblock);
if (ret)
return ret;
INIT_WORK(&state->commit_work, commit_work);
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
if (!nonblock) {
ret = drm_atomic_helper_wait_for_fences(dev, state, true);
if (ret) {
drm_atomic_helper_cleanup_planes(dev, state);
return ret;
}
}
drm_atomic_helper_swap_state(state, true);
drm_atomic_state_get(state);
if (nonblock)
queue_work(system_unbound_wq, &state->commit_work);
else
commit_tail(state);
return 0;
}
static int stall_checks(struct drm_crtc *crtc, bool nonblock)
{
struct drm_crtc_commit *commit, *stall_commit = NULL;
bool completed = true;
int i;
long ret = 0;
spin_lock(&crtc->commit_lock);
i = 0;
list_for_each_entry(commit, &crtc->commit_list, commit_entry) {
if (i == 0) {
completed = try_wait_for_completion(&commit->flip_done);
if (!completed && nonblock) {
spin_unlock(&crtc->commit_lock);
return -EBUSY;
}
} else if (i == 1) {
stall_commit = commit;
drm_crtc_commit_get(stall_commit);
break;
}
i++;
}
spin_unlock(&crtc->commit_lock);
if (!stall_commit)
return 0;
ret = wait_for_completion_interruptible_timeout(&stall_commit->cleanup_done,
10*HZ);
if (ret == 0)
DRM_ERROR("[CRTC:%d:%s] cleanup_done timed out\n",
crtc->base.id, crtc->name);
drm_crtc_commit_put(stall_commit);
return ret < 0 ? ret : 0;
}
int drm_atomic_helper_setup_commit(struct drm_atomic_state *state,
bool nonblock)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_crtc_commit *commit;
int i, ret;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
commit = kzalloc(sizeof(*commit), GFP_KERNEL);
if (!commit)
return -ENOMEM;
init_completion(&commit->flip_done);
init_completion(&commit->hw_done);
init_completion(&commit->cleanup_done);
INIT_LIST_HEAD(&commit->commit_entry);
kref_init(&commit->ref);
commit->crtc = crtc;
state->crtcs[i].commit = commit;
ret = stall_checks(crtc, nonblock);
if (ret)
return ret;
if (!crtc->state->active && !crtc_state->active) {
complete_all(&commit->flip_done);
continue;
}
if (state->legacy_cursor_update) {
complete_all(&commit->flip_done);
continue;
}
if (!crtc_state->event) {
commit->event = kzalloc(sizeof(*commit->event),
GFP_KERNEL);
if (!commit->event)
return -ENOMEM;
crtc_state->event = commit->event;
}
crtc_state->event->base.completion = &commit->flip_done;
}
return 0;
}
static struct drm_crtc_commit *preceeding_commit(struct drm_crtc *crtc)
{
struct drm_crtc_commit *commit;
int i = 0;
list_for_each_entry(commit, &crtc->commit_list, commit_entry) {
if (i == 1)
return commit;
i++;
}
return NULL;
}
void drm_atomic_helper_wait_for_dependencies(struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_crtc_commit *commit;
int i;
long ret;
for_each_crtc_in_state(old_state, crtc, crtc_state, i) {
spin_lock(&crtc->commit_lock);
commit = preceeding_commit(crtc);
if (commit)
drm_crtc_commit_get(commit);
spin_unlock(&crtc->commit_lock);
if (!commit)
continue;
ret = wait_for_completion_timeout(&commit->hw_done,
10*HZ);
if (ret == 0)
DRM_ERROR("[CRTC:%d:%s] hw_done timed out\n",
crtc->base.id, crtc->name);
ret = wait_for_completion_timeout(&commit->flip_done,
10*HZ);
if (ret == 0)
DRM_ERROR("[CRTC:%d:%s] flip_done timed out\n",
crtc->base.id, crtc->name);
drm_crtc_commit_put(commit);
}
}
void drm_atomic_helper_commit_hw_done(struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_crtc_commit *commit;
int i;
for_each_crtc_in_state(old_state, crtc, crtc_state, i) {
commit = old_state->crtcs[i].commit;
if (!commit)
continue;
WARN_ON(crtc->state->event);
spin_lock(&crtc->commit_lock);
complete_all(&commit->hw_done);
spin_unlock(&crtc->commit_lock);
}
}
void drm_atomic_helper_commit_cleanup_done(struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_crtc_commit *commit;
int i;
long ret;
for_each_crtc_in_state(old_state, crtc, crtc_state, i) {
commit = old_state->crtcs[i].commit;
if (WARN_ON(!commit))
continue;
spin_lock(&crtc->commit_lock);
complete_all(&commit->cleanup_done);
WARN_ON(!try_wait_for_completion(&commit->hw_done));
if (try_wait_for_completion(&commit->flip_done))
goto del_commit;
spin_unlock(&crtc->commit_lock);
ret = wait_for_completion_timeout(&commit->flip_done,
10*HZ);
if (ret == 0)
DRM_ERROR("[CRTC:%d:%s] flip_done timed out\n",
crtc->base.id, crtc->name);
spin_lock(&crtc->commit_lock);
del_commit:
list_del(&commit->commit_entry);
spin_unlock(&crtc->commit_lock);
}
}
int drm_atomic_helper_prepare_planes(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct drm_plane *plane;
struct drm_plane_state *plane_state;
int ret, i, j;
for_each_plane_in_state(state, plane, plane_state, i) {
const struct drm_plane_helper_funcs *funcs;
funcs = plane->helper_private;
if (funcs->prepare_fb) {
ret = funcs->prepare_fb(plane, plane_state);
if (ret)
goto fail;
}
}
return 0;
fail:
for_each_plane_in_state(state, plane, plane_state, j) {
const struct drm_plane_helper_funcs *funcs;
if (j >= i)
continue;
funcs = plane->helper_private;
if (funcs->cleanup_fb)
funcs->cleanup_fb(plane, plane_state);
}
return ret;
}
static bool plane_crtc_active(const struct drm_plane_state *state)
{
return state->crtc && state->crtc->state->active;
}
void drm_atomic_helper_commit_planes(struct drm_device *dev,
struct drm_atomic_state *old_state,
uint32_t flags)
{
struct drm_crtc *crtc;
struct drm_crtc_state *old_crtc_state;
struct drm_plane *plane;
struct drm_plane_state *old_plane_state;
int i;
bool active_only = flags & DRM_PLANE_COMMIT_ACTIVE_ONLY;
bool no_disable = flags & DRM_PLANE_COMMIT_NO_DISABLE_AFTER_MODESET;
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
const struct drm_crtc_helper_funcs *funcs;
funcs = crtc->helper_private;
if (!funcs || !funcs->atomic_begin)
continue;
if (active_only && !crtc->state->active)
continue;
funcs->atomic_begin(crtc, old_crtc_state);
}
for_each_plane_in_state(old_state, plane, old_plane_state, i) {
const struct drm_plane_helper_funcs *funcs;
bool disabling;
funcs = plane->helper_private;
if (!funcs)
continue;
disabling = drm_atomic_plane_disabling(plane, old_plane_state);
if (active_only) {
if (!disabling && !plane_crtc_active(plane->state))
continue;
if (disabling && !plane_crtc_active(old_plane_state))
continue;
}
if (disabling && funcs->atomic_disable) {
struct drm_crtc_state *crtc_state;
crtc_state = old_plane_state->crtc->state;
if (drm_atomic_crtc_needs_modeset(crtc_state) &&
no_disable)
continue;
funcs->atomic_disable(plane, old_plane_state);
} else if (plane->state->crtc || disabling) {
funcs->atomic_update(plane, old_plane_state);
}
}
for_each_crtc_in_state(old_state, crtc, old_crtc_state, i) {
const struct drm_crtc_helper_funcs *funcs;
funcs = crtc->helper_private;
if (!funcs || !funcs->atomic_flush)
continue;
if (active_only && !crtc->state->active)
continue;
funcs->atomic_flush(crtc, old_crtc_state);
}
}
void
drm_atomic_helper_commit_planes_on_crtc(struct drm_crtc_state *old_crtc_state)
{
const struct drm_crtc_helper_funcs *crtc_funcs;
struct drm_crtc *crtc = old_crtc_state->crtc;
struct drm_atomic_state *old_state = old_crtc_state->state;
struct drm_plane *plane;
unsigned plane_mask;
plane_mask = old_crtc_state->plane_mask;
plane_mask |= crtc->state->plane_mask;
crtc_funcs = crtc->helper_private;
if (crtc_funcs && crtc_funcs->atomic_begin)
crtc_funcs->atomic_begin(crtc, old_crtc_state);
drm_for_each_plane_mask(plane, crtc->dev, plane_mask) {
struct drm_plane_state *old_plane_state =
drm_atomic_get_existing_plane_state(old_state, plane);
const struct drm_plane_helper_funcs *plane_funcs;
plane_funcs = plane->helper_private;
if (!old_plane_state || !plane_funcs)
continue;
WARN_ON(plane->state->crtc && plane->state->crtc != crtc);
if (drm_atomic_plane_disabling(plane, old_plane_state) &&
plane_funcs->atomic_disable)
plane_funcs->atomic_disable(plane, old_plane_state);
else if (plane->state->crtc ||
drm_atomic_plane_disabling(plane, old_plane_state))
plane_funcs->atomic_update(plane, old_plane_state);
}
if (crtc_funcs && crtc_funcs->atomic_flush)
crtc_funcs->atomic_flush(crtc, old_crtc_state);
}
void
drm_atomic_helper_disable_planes_on_crtc(struct drm_crtc_state *old_crtc_state,
bool atomic)
{
struct drm_crtc *crtc = old_crtc_state->crtc;
const struct drm_crtc_helper_funcs *crtc_funcs =
crtc->helper_private;
struct drm_plane *plane;
if (atomic && crtc_funcs && crtc_funcs->atomic_begin)
crtc_funcs->atomic_begin(crtc, NULL);
drm_atomic_crtc_state_for_each_plane(plane, old_crtc_state) {
const struct drm_plane_helper_funcs *plane_funcs =
plane->helper_private;
if (!plane_funcs)
continue;
WARN_ON(!plane_funcs->atomic_disable);
if (plane_funcs->atomic_disable)
plane_funcs->atomic_disable(plane, NULL);
}
if (atomic && crtc_funcs && crtc_funcs->atomic_flush)
crtc_funcs->atomic_flush(crtc, NULL);
}
void drm_atomic_helper_cleanup_planes(struct drm_device *dev,
struct drm_atomic_state *old_state)
{
struct drm_plane *plane;
struct drm_plane_state *plane_state;
int i;
for_each_plane_in_state(old_state, plane, plane_state, i) {
const struct drm_plane_helper_funcs *funcs;
funcs = plane->helper_private;
if (funcs->cleanup_fb)
funcs->cleanup_fb(plane, plane_state);
}
}
void drm_atomic_helper_swap_state(struct drm_atomic_state *state,
bool stall)
{
int i;
long ret;
struct drm_connector *connector;
struct drm_connector_state *conn_state;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_plane *plane;
struct drm_plane_state *plane_state;
struct drm_crtc_commit *commit;
if (stall) {
for_each_crtc_in_state(state, crtc, crtc_state, i) {
spin_lock(&crtc->commit_lock);
commit = list_first_entry_or_null(&crtc->commit_list,
struct drm_crtc_commit, commit_entry);
if (commit)
drm_crtc_commit_get(commit);
spin_unlock(&crtc->commit_lock);
if (!commit)
continue;
ret = wait_for_completion_timeout(&commit->hw_done,
10*HZ);
if (ret == 0)
DRM_ERROR("[CRTC:%d:%s] hw_done timed out\n",
crtc->base.id, crtc->name);
drm_crtc_commit_put(commit);
}
}
for_each_connector_in_state(state, connector, conn_state, i) {
connector->state->state = state;
swap(state->connectors[i].state, connector->state);
connector->state->state = NULL;
}
for_each_crtc_in_state(state, crtc, crtc_state, i) {
crtc->state->state = state;
swap(state->crtcs[i].state, crtc->state);
crtc->state->state = NULL;
if (state->crtcs[i].commit) {
spin_lock(&crtc->commit_lock);
list_add(&state->crtcs[i].commit->commit_entry,
&crtc->commit_list);
spin_unlock(&crtc->commit_lock);
state->crtcs[i].commit->event = NULL;
}
}
for_each_plane_in_state(state, plane, plane_state, i) {
plane->state->state = state;
swap(state->planes[i].state, plane->state);
plane->state->state = NULL;
}
}
int drm_atomic_helper_update_plane(struct drm_plane *plane,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct drm_atomic_state *state;
struct drm_plane_state *plane_state;
int ret = 0;
state = drm_atomic_state_alloc(plane->dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = drm_modeset_legacy_acquire_ctx(crtc);
retry:
plane_state = drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
ret = PTR_ERR(plane_state);
goto fail;
}
ret = drm_atomic_set_crtc_for_plane(plane_state, crtc);
if (ret != 0)
goto fail;
drm_atomic_set_fb_for_plane(plane_state, fb);
plane_state->crtc_x = crtc_x;
plane_state->crtc_y = crtc_y;
plane_state->crtc_w = crtc_w;
plane_state->crtc_h = crtc_h;
plane_state->src_x = src_x;
plane_state->src_y = src_y;
plane_state->src_w = src_w;
plane_state->src_h = src_h;
if (plane == crtc->cursor)
state->legacy_cursor_update = true;
ret = drm_atomic_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
plane->old_fb = plane->fb;
goto retry;
}
int drm_atomic_helper_disable_plane(struct drm_plane *plane)
{
struct drm_atomic_state *state;
struct drm_plane_state *plane_state;
int ret = 0;
if (!plane->crtc)
return 0;
state = drm_atomic_state_alloc(plane->dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = drm_modeset_legacy_acquire_ctx(plane->crtc);
retry:
plane_state = drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
ret = PTR_ERR(plane_state);
goto fail;
}
if (plane_state->crtc && (plane == plane->crtc->cursor))
plane_state->state->legacy_cursor_update = true;
ret = __drm_atomic_helper_disable_plane(plane, plane_state);
if (ret != 0)
goto fail;
ret = drm_atomic_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
plane->old_fb = plane->fb;
goto retry;
}
int __drm_atomic_helper_disable_plane(struct drm_plane *plane,
struct drm_plane_state *plane_state)
{
int ret;
ret = drm_atomic_set_crtc_for_plane(plane_state, NULL);
if (ret != 0)
return ret;
drm_atomic_set_fb_for_plane(plane_state, NULL);
plane_state->crtc_x = 0;
plane_state->crtc_y = 0;
plane_state->crtc_w = 0;
plane_state->crtc_h = 0;
plane_state->src_x = 0;
plane_state->src_y = 0;
plane_state->src_w = 0;
plane_state->src_h = 0;
return 0;
}
static int update_output_state(struct drm_atomic_state *state,
struct drm_mode_set *set)
{
struct drm_device *dev = set->crtc->dev;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_connector *connector;
struct drm_connector_state *conn_state;
int ret, i;
ret = drm_modeset_lock(&dev->mode_config.connection_mutex,
state->acquire_ctx);
if (ret)
return ret;
ret = drm_atomic_add_affected_connectors(state, set->crtc);
if (ret)
return ret;
for_each_connector_in_state(state, connector, conn_state, i) {
if (conn_state->crtc == set->crtc) {
ret = drm_atomic_set_crtc_for_connector(conn_state,
NULL);
if (ret)
return ret;
}
}
for (i = 0; i < set->num_connectors; i++) {
conn_state = drm_atomic_get_connector_state(state,
set->connectors[i]);
if (IS_ERR(conn_state))
return PTR_ERR(conn_state);
ret = drm_atomic_set_crtc_for_connector(conn_state,
set->crtc);
if (ret)
return ret;
}
for_each_crtc_in_state(state, crtc, crtc_state, i) {
if (crtc == set->crtc)
continue;
if (!crtc_state->connector_mask) {
ret = drm_atomic_set_mode_prop_for_crtc(crtc_state,
NULL);
if (ret < 0)
return ret;
crtc_state->active = false;
}
}
return 0;
}
int drm_atomic_helper_set_config(struct drm_mode_set *set)
{
struct drm_atomic_state *state;
struct drm_crtc *crtc = set->crtc;
int ret = 0;
state = drm_atomic_state_alloc(crtc->dev);
if (!state)
return -ENOMEM;
state->legacy_set_config = true;
state->acquire_ctx = drm_modeset_legacy_acquire_ctx(crtc);
retry:
ret = __drm_atomic_helper_set_config(set, state);
if (ret != 0)
goto fail;
ret = drm_atomic_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
crtc->primary->old_fb = crtc->primary->fb;
goto retry;
}
int __drm_atomic_helper_set_config(struct drm_mode_set *set,
struct drm_atomic_state *state)
{
struct drm_crtc_state *crtc_state;
struct drm_plane_state *primary_state;
struct drm_crtc *crtc = set->crtc;
int hdisplay, vdisplay;
int ret;
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
primary_state = drm_atomic_get_plane_state(state, crtc->primary);
if (IS_ERR(primary_state))
return PTR_ERR(primary_state);
if (!set->mode) {
WARN_ON(set->fb);
WARN_ON(set->num_connectors);
ret = drm_atomic_set_mode_for_crtc(crtc_state, NULL);
if (ret != 0)
return ret;
crtc_state->active = false;
ret = drm_atomic_set_crtc_for_plane(primary_state, NULL);
if (ret != 0)
return ret;
drm_atomic_set_fb_for_plane(primary_state, NULL);
goto commit;
}
WARN_ON(!set->fb);
WARN_ON(!set->num_connectors);
ret = drm_atomic_set_mode_for_crtc(crtc_state, set->mode);
if (ret != 0)
return ret;
crtc_state->active = true;
ret = drm_atomic_set_crtc_for_plane(primary_state, crtc);
if (ret != 0)
return ret;
drm_crtc_get_hv_timing(set->mode, &hdisplay, &vdisplay);
drm_atomic_set_fb_for_plane(primary_state, set->fb);
primary_state->crtc_x = 0;
primary_state->crtc_y = 0;
primary_state->crtc_w = hdisplay;
primary_state->crtc_h = vdisplay;
primary_state->src_x = set->x << 16;
primary_state->src_y = set->y << 16;
if (drm_rotation_90_or_270(primary_state->rotation)) {
primary_state->src_w = vdisplay << 16;
primary_state->src_h = hdisplay << 16;
} else {
primary_state->src_w = hdisplay << 16;
primary_state->src_h = vdisplay << 16;
}
commit:
ret = update_output_state(state, set);
if (ret)
return ret;
return 0;
}
int drm_atomic_helper_disable_all(struct drm_device *dev,
struct drm_modeset_acquire_ctx *ctx)
{
struct drm_atomic_state *state;
struct drm_connector *conn;
int err;
state = drm_atomic_state_alloc(dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = ctx;
drm_for_each_connector(conn, dev) {
struct drm_crtc *crtc = conn->state->crtc;
struct drm_crtc_state *crtc_state;
if (!crtc || conn->dpms != DRM_MODE_DPMS_ON)
continue;
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state)) {
err = PTR_ERR(crtc_state);
goto free;
}
crtc_state->active = false;
}
err = drm_atomic_commit(state);
free:
drm_atomic_state_put(state);
return err;
}
struct drm_atomic_state *drm_atomic_helper_suspend(struct drm_device *dev)
{
struct drm_modeset_acquire_ctx ctx;
struct drm_atomic_state *state;
int err;
drm_modeset_acquire_init(&ctx, 0);
retry:
err = drm_modeset_lock_all_ctx(dev, &ctx);
if (err < 0) {
state = ERR_PTR(err);
goto unlock;
}
state = drm_atomic_helper_duplicate_state(dev, &ctx);
if (IS_ERR(state))
goto unlock;
err = drm_atomic_helper_disable_all(dev, &ctx);
if (err < 0) {
drm_atomic_state_put(state);
state = ERR_PTR(err);
goto unlock;
}
unlock:
if (PTR_ERR(state) == -EDEADLK) {
drm_modeset_backoff(&ctx);
goto retry;
}
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
return state;
}
int drm_atomic_helper_resume(struct drm_device *dev,
struct drm_atomic_state *state)
{
struct drm_mode_config *config = &dev->mode_config;
int err;
drm_mode_config_reset(dev);
drm_modeset_lock_all(dev);
state->acquire_ctx = config->acquire_ctx;
err = drm_atomic_commit(state);
drm_modeset_unlock_all(dev);
return err;
}
int
drm_atomic_helper_crtc_set_property(struct drm_crtc *crtc,
struct drm_property *property,
uint64_t val)
{
struct drm_atomic_state *state;
struct drm_crtc_state *crtc_state;
int ret = 0;
state = drm_atomic_state_alloc(crtc->dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = crtc->dev->mode_config.acquire_ctx;
retry:
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state)) {
ret = PTR_ERR(crtc_state);
goto fail;
}
ret = drm_atomic_crtc_set_property(crtc, crtc_state,
property, val);
if (ret)
goto fail;
ret = drm_atomic_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
goto retry;
}
int
drm_atomic_helper_plane_set_property(struct drm_plane *plane,
struct drm_property *property,
uint64_t val)
{
struct drm_atomic_state *state;
struct drm_plane_state *plane_state;
int ret = 0;
state = drm_atomic_state_alloc(plane->dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = plane->dev->mode_config.acquire_ctx;
retry:
plane_state = drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
ret = PTR_ERR(plane_state);
goto fail;
}
ret = drm_atomic_plane_set_property(plane, plane_state,
property, val);
if (ret)
goto fail;
ret = drm_atomic_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
goto retry;
}
int
drm_atomic_helper_connector_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
struct drm_atomic_state *state;
struct drm_connector_state *connector_state;
int ret = 0;
state = drm_atomic_state_alloc(connector->dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = connector->dev->mode_config.acquire_ctx;
retry:
connector_state = drm_atomic_get_connector_state(state, connector);
if (IS_ERR(connector_state)) {
ret = PTR_ERR(connector_state);
goto fail;
}
ret = drm_atomic_connector_set_property(connector, connector_state,
property, val);
if (ret)
goto fail;
ret = drm_atomic_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
goto retry;
}
int drm_atomic_helper_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t flags)
{
struct drm_plane *plane = crtc->primary;
struct drm_atomic_state *state;
struct drm_plane_state *plane_state;
struct drm_crtc_state *crtc_state;
int ret = 0;
if (flags & DRM_MODE_PAGE_FLIP_ASYNC)
return -EINVAL;
state = drm_atomic_state_alloc(plane->dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = drm_modeset_legacy_acquire_ctx(crtc);
retry:
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state)) {
ret = PTR_ERR(crtc_state);
goto fail;
}
crtc_state->event = event;
plane_state = drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
ret = PTR_ERR(plane_state);
goto fail;
}
ret = drm_atomic_set_crtc_for_plane(plane_state, crtc);
if (ret != 0)
goto fail;
drm_atomic_set_fb_for_plane(plane_state, fb);
state->allow_modeset = false;
if (!crtc_state->active) {
DRM_DEBUG_ATOMIC("[CRTC:%d] disabled, rejecting legacy flip\n",
crtc->base.id);
ret = -EINVAL;
goto fail;
}
ret = drm_atomic_nonblocking_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
plane->old_fb = plane->fb;
goto retry;
}
int drm_atomic_helper_connector_dpms(struct drm_connector *connector,
int mode)
{
struct drm_mode_config *config = &connector->dev->mode_config;
struct drm_atomic_state *state;
struct drm_crtc_state *crtc_state;
struct drm_crtc *crtc;
struct drm_connector *tmp_connector;
int ret;
bool active = false;
int old_mode = connector->dpms;
if (mode != DRM_MODE_DPMS_ON)
mode = DRM_MODE_DPMS_OFF;
connector->dpms = mode;
crtc = connector->state->crtc;
if (!crtc)
return 0;
state = drm_atomic_state_alloc(connector->dev);
if (!state)
return -ENOMEM;
state->acquire_ctx = drm_modeset_legacy_acquire_ctx(crtc);
retry:
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state)) {
ret = PTR_ERR(crtc_state);
goto fail;
}
WARN_ON(!drm_modeset_is_locked(&config->connection_mutex));
drm_for_each_connector(tmp_connector, connector->dev) {
if (tmp_connector->state->crtc != crtc)
continue;
if (tmp_connector->dpms == DRM_MODE_DPMS_ON) {
active = true;
break;
}
}
crtc_state->active = active;
ret = drm_atomic_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
if (ret != 0)
connector->dpms = old_mode;
drm_atomic_state_put(state);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
goto retry;
}
struct drm_encoder *
drm_atomic_helper_best_encoder(struct drm_connector *connector)
{
WARN_ON(connector->encoder_ids[1]);
return drm_encoder_find(connector->dev, connector->encoder_ids[0]);
}
void drm_atomic_helper_crtc_reset(struct drm_crtc *crtc)
{
if (crtc->state)
__drm_atomic_helper_crtc_destroy_state(crtc->state);
kfree(crtc->state);
crtc->state = kzalloc(sizeof(*crtc->state), GFP_KERNEL);
if (crtc->state)
crtc->state->crtc = crtc;
}
void __drm_atomic_helper_crtc_duplicate_state(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
memcpy(state, crtc->state, sizeof(*state));
if (state->mode_blob)
drm_property_reference_blob(state->mode_blob);
if (state->degamma_lut)
drm_property_reference_blob(state->degamma_lut);
if (state->ctm)
drm_property_reference_blob(state->ctm);
if (state->gamma_lut)
drm_property_reference_blob(state->gamma_lut);
state->mode_changed = false;
state->active_changed = false;
state->planes_changed = false;
state->connectors_changed = false;
state->color_mgmt_changed = false;
state->zpos_changed = false;
state->event = NULL;
}
struct drm_crtc_state *
drm_atomic_helper_crtc_duplicate_state(struct drm_crtc *crtc)
{
struct drm_crtc_state *state;
if (WARN_ON(!crtc->state))
return NULL;
state = kmalloc(sizeof(*state), GFP_KERNEL);
if (state)
__drm_atomic_helper_crtc_duplicate_state(crtc, state);
return state;
}
void __drm_atomic_helper_crtc_destroy_state(struct drm_crtc_state *state)
{
drm_property_unreference_blob(state->mode_blob);
drm_property_unreference_blob(state->degamma_lut);
drm_property_unreference_blob(state->ctm);
drm_property_unreference_blob(state->gamma_lut);
}
void drm_atomic_helper_crtc_destroy_state(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
__drm_atomic_helper_crtc_destroy_state(state);
kfree(state);
}
void drm_atomic_helper_plane_reset(struct drm_plane *plane)
{
if (plane->state)
__drm_atomic_helper_plane_destroy_state(plane->state);
kfree(plane->state);
plane->state = kzalloc(sizeof(*plane->state), GFP_KERNEL);
if (plane->state) {
plane->state->plane = plane;
plane->state->rotation = DRM_ROTATE_0;
}
}
void __drm_atomic_helper_plane_duplicate_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
memcpy(state, plane->state, sizeof(*state));
if (state->fb)
drm_framebuffer_reference(state->fb);
state->fence = NULL;
}
struct drm_plane_state *
drm_atomic_helper_plane_duplicate_state(struct drm_plane *plane)
{
struct drm_plane_state *state;
if (WARN_ON(!plane->state))
return NULL;
state = kmalloc(sizeof(*state), GFP_KERNEL);
if (state)
__drm_atomic_helper_plane_duplicate_state(plane, state);
return state;
}
void __drm_atomic_helper_plane_destroy_state(struct drm_plane_state *state)
{
if (state->fb)
drm_framebuffer_unreference(state->fb);
if (state->fence)
dma_fence_put(state->fence);
}
void drm_atomic_helper_plane_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
__drm_atomic_helper_plane_destroy_state(state);
kfree(state);
}
void
__drm_atomic_helper_connector_reset(struct drm_connector *connector,
struct drm_connector_state *conn_state)
{
if (conn_state)
conn_state->connector = connector;
connector->state = conn_state;
}
void drm_atomic_helper_connector_reset(struct drm_connector *connector)
{
struct drm_connector_state *conn_state =
kzalloc(sizeof(*conn_state), GFP_KERNEL);
if (connector->state)
__drm_atomic_helper_connector_destroy_state(connector->state);
kfree(connector->state);
__drm_atomic_helper_connector_reset(connector, conn_state);
}
void
__drm_atomic_helper_connector_duplicate_state(struct drm_connector *connector,
struct drm_connector_state *state)
{
memcpy(state, connector->state, sizeof(*state));
if (state->crtc)
drm_connector_reference(connector);
}
struct drm_connector_state *
drm_atomic_helper_connector_duplicate_state(struct drm_connector *connector)
{
struct drm_connector_state *state;
if (WARN_ON(!connector->state))
return NULL;
state = kmalloc(sizeof(*state), GFP_KERNEL);
if (state)
__drm_atomic_helper_connector_duplicate_state(connector, state);
return state;
}
struct drm_atomic_state *
drm_atomic_helper_duplicate_state(struct drm_device *dev,
struct drm_modeset_acquire_ctx *ctx)
{
struct drm_atomic_state *state;
struct drm_connector *conn;
struct drm_plane *plane;
struct drm_crtc *crtc;
int err = 0;
state = drm_atomic_state_alloc(dev);
if (!state)
return ERR_PTR(-ENOMEM);
state->acquire_ctx = ctx;
drm_for_each_crtc(crtc, dev) {
struct drm_crtc_state *crtc_state;
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state)) {
err = PTR_ERR(crtc_state);
goto free;
}
}
drm_for_each_plane(plane, dev) {
struct drm_plane_state *plane_state;
plane_state = drm_atomic_get_plane_state(state, plane);
if (IS_ERR(plane_state)) {
err = PTR_ERR(plane_state);
goto free;
}
}
drm_for_each_connector(conn, dev) {
struct drm_connector_state *conn_state;
conn_state = drm_atomic_get_connector_state(state, conn);
if (IS_ERR(conn_state)) {
err = PTR_ERR(conn_state);
goto free;
}
}
state->acquire_ctx = NULL;
free:
if (err < 0) {
drm_atomic_state_put(state);
state = ERR_PTR(err);
}
return state;
}
void
__drm_atomic_helper_connector_destroy_state(struct drm_connector_state *state)
{
if (state->crtc)
drm_connector_unreference(state->connector);
}
void drm_atomic_helper_connector_destroy_state(struct drm_connector *connector,
struct drm_connector_state *state)
{
__drm_atomic_helper_connector_destroy_state(state);
kfree(state);
}
int drm_atomic_helper_legacy_gamma_set(struct drm_crtc *crtc,
u16 *red, u16 *green, u16 *blue,
uint32_t size)
{
struct drm_device *dev = crtc->dev;
struct drm_mode_config *config = &dev->mode_config;
struct drm_atomic_state *state;
struct drm_crtc_state *crtc_state;
struct drm_property_blob *blob = NULL;
struct drm_color_lut *blob_data;
int i, ret = 0;
state = drm_atomic_state_alloc(crtc->dev);
if (!state)
return -ENOMEM;
blob = drm_property_create_blob(dev,
sizeof(struct drm_color_lut) * size,
NULL);
if (IS_ERR(blob)) {
ret = PTR_ERR(blob);
blob = NULL;
goto fail;
}
blob_data = (struct drm_color_lut *) blob->data;
for (i = 0; i < size; i++) {
blob_data[i].red = red[i];
blob_data[i].green = green[i];
blob_data[i].blue = blue[i];
}
state->acquire_ctx = crtc->dev->mode_config.acquire_ctx;
retry:
crtc_state = drm_atomic_get_crtc_state(state, crtc);
if (IS_ERR(crtc_state)) {
ret = PTR_ERR(crtc_state);
goto fail;
}
ret = drm_atomic_crtc_set_property(crtc, crtc_state,
config->degamma_lut_property, 0);
if (ret)
goto fail;
ret = drm_atomic_crtc_set_property(crtc, crtc_state,
config->ctm_property, 0);
if (ret)
goto fail;
ret = drm_atomic_crtc_set_property(crtc, crtc_state,
config->gamma_lut_property, blob->base.id);
if (ret)
goto fail;
ret = drm_atomic_commit(state);
fail:
if (ret == -EDEADLK)
goto backoff;
drm_atomic_state_put(state);
drm_property_unreference_blob(blob);
return ret;
backoff:
drm_atomic_state_clear(state);
drm_atomic_legacy_backoff(state);
goto retry;
}
