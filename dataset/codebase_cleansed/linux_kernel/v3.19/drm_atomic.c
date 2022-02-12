static void kfree_state(struct drm_atomic_state *state)
{
kfree(state->connectors);
kfree(state->connector_states);
kfree(state->crtcs);
kfree(state->crtc_states);
kfree(state->planes);
kfree(state->plane_states);
kfree(state);
}
struct drm_atomic_state *
drm_atomic_state_alloc(struct drm_device *dev)
{
struct drm_atomic_state *state;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
state->num_connector = ACCESS_ONCE(dev->mode_config.num_connector);
state->crtcs = kcalloc(dev->mode_config.num_crtc,
sizeof(*state->crtcs), GFP_KERNEL);
if (!state->crtcs)
goto fail;
state->crtc_states = kcalloc(dev->mode_config.num_crtc,
sizeof(*state->crtc_states), GFP_KERNEL);
if (!state->crtc_states)
goto fail;
state->planes = kcalloc(dev->mode_config.num_total_plane,
sizeof(*state->planes), GFP_KERNEL);
if (!state->planes)
goto fail;
state->plane_states = kcalloc(dev->mode_config.num_total_plane,
sizeof(*state->plane_states), GFP_KERNEL);
if (!state->plane_states)
goto fail;
state->connectors = kcalloc(state->num_connector,
sizeof(*state->connectors),
GFP_KERNEL);
if (!state->connectors)
goto fail;
state->connector_states = kcalloc(state->num_connector,
sizeof(*state->connector_states),
GFP_KERNEL);
if (!state->connector_states)
goto fail;
state->dev = dev;
DRM_DEBUG_KMS("Allocate atomic state %p\n", state);
return state;
fail:
kfree_state(state);
return NULL;
}
void drm_atomic_state_clear(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_mode_config *config = &dev->mode_config;
int i;
DRM_DEBUG_KMS("Clearing atomic state %p\n", state);
for (i = 0; i < state->num_connector; i++) {
struct drm_connector *connector = state->connectors[i];
if (!connector)
continue;
WARN_ON(!drm_modeset_is_locked(&config->connection_mutex));
connector->funcs->atomic_destroy_state(connector,
state->connector_states[i]);
}
for (i = 0; i < config->num_crtc; i++) {
struct drm_crtc *crtc = state->crtcs[i];
if (!crtc)
continue;
crtc->funcs->atomic_destroy_state(crtc,
state->crtc_states[i]);
}
for (i = 0; i < config->num_total_plane; i++) {
struct drm_plane *plane = state->planes[i];
if (!plane)
continue;
plane->funcs->atomic_destroy_state(plane,
state->plane_states[i]);
}
}
void drm_atomic_state_free(struct drm_atomic_state *state)
{
drm_atomic_state_clear(state);
DRM_DEBUG_KMS("Freeing atomic state %p\n", state);
kfree_state(state);
}
struct drm_crtc_state *
drm_atomic_get_crtc_state(struct drm_atomic_state *state,
struct drm_crtc *crtc)
{
int ret, index;
struct drm_crtc_state *crtc_state;
index = drm_crtc_index(crtc);
if (state->crtc_states[index])
return state->crtc_states[index];
ret = drm_modeset_lock(&crtc->mutex, state->acquire_ctx);
if (ret)
return ERR_PTR(ret);
crtc_state = crtc->funcs->atomic_duplicate_state(crtc);
if (!crtc_state)
return ERR_PTR(-ENOMEM);
state->crtc_states[index] = crtc_state;
state->crtcs[index] = crtc;
crtc_state->state = state;
DRM_DEBUG_KMS("Added [CRTC:%d] %p state to %p\n",
crtc->base.id, crtc_state, state);
return crtc_state;
}
struct drm_plane_state *
drm_atomic_get_plane_state(struct drm_atomic_state *state,
struct drm_plane *plane)
{
int ret, index;
struct drm_plane_state *plane_state;
index = drm_plane_index(plane);
if (state->plane_states[index])
return state->plane_states[index];
ret = drm_modeset_lock(&plane->mutex, state->acquire_ctx);
if (ret)
return ERR_PTR(ret);
plane_state = plane->funcs->atomic_duplicate_state(plane);
if (!plane_state)
return ERR_PTR(-ENOMEM);
state->plane_states[index] = plane_state;
state->planes[index] = plane;
plane_state->state = state;
DRM_DEBUG_KMS("Added [PLANE:%d] %p state to %p\n",
plane->base.id, plane_state, state);
if (plane_state->crtc) {
struct drm_crtc_state *crtc_state;
crtc_state = drm_atomic_get_crtc_state(state,
plane_state->crtc);
if (IS_ERR(crtc_state))
return ERR_CAST(crtc_state);
}
return plane_state;
}
struct drm_connector_state *
drm_atomic_get_connector_state(struct drm_atomic_state *state,
struct drm_connector *connector)
{
int ret, index;
struct drm_mode_config *config = &connector->dev->mode_config;
struct drm_connector_state *connector_state;
ret = drm_modeset_lock(&config->connection_mutex, state->acquire_ctx);
if (ret)
return ERR_PTR(ret);
index = drm_connector_index(connector);
if (index >= state->num_connector) {
DRM_DEBUG_KMS("Hot-added connector would overflow state array, restarting\n");
return ERR_PTR(-EAGAIN);
}
if (state->connector_states[index])
return state->connector_states[index];
connector_state = connector->funcs->atomic_duplicate_state(connector);
if (!connector_state)
return ERR_PTR(-ENOMEM);
state->connector_states[index] = connector_state;
state->connectors[index] = connector;
connector_state->state = state;
DRM_DEBUG_KMS("Added [CONNECTOR:%d] %p state to %p\n",
connector->base.id, connector_state, state);
if (connector_state->crtc) {
struct drm_crtc_state *crtc_state;
crtc_state = drm_atomic_get_crtc_state(state,
connector_state->crtc);
if (IS_ERR(crtc_state))
return ERR_CAST(crtc_state);
}
return connector_state;
}
int
drm_atomic_set_crtc_for_plane(struct drm_atomic_state *state,
struct drm_plane *plane, struct drm_crtc *crtc)
{
struct drm_plane_state *plane_state =
drm_atomic_get_plane_state(state, plane);
struct drm_crtc_state *crtc_state;
if (WARN_ON(IS_ERR(plane_state)))
return PTR_ERR(plane_state);
if (plane_state->crtc) {
crtc_state = drm_atomic_get_crtc_state(plane_state->state,
plane_state->crtc);
if (WARN_ON(IS_ERR(crtc_state)))
return PTR_ERR(crtc_state);
crtc_state->plane_mask &= ~(1 << drm_plane_index(plane));
}
plane_state->crtc = crtc;
if (crtc) {
crtc_state = drm_atomic_get_crtc_state(plane_state->state,
crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
crtc_state->plane_mask |= (1 << drm_plane_index(plane));
}
if (crtc)
DRM_DEBUG_KMS("Link plane state %p to [CRTC:%d]\n",
plane_state, crtc->base.id);
else
DRM_DEBUG_KMS("Link plane state %p to [NOCRTC]\n", plane_state);
return 0;
}
void
drm_atomic_set_fb_for_plane(struct drm_plane_state *plane_state,
struct drm_framebuffer *fb)
{
if (plane_state->fb)
drm_framebuffer_unreference(plane_state->fb);
if (fb)
drm_framebuffer_reference(fb);
plane_state->fb = fb;
if (fb)
DRM_DEBUG_KMS("Set [FB:%d] for plane state %p\n",
fb->base.id, plane_state);
else
DRM_DEBUG_KMS("Set [NOFB] for plane state %p\n", plane_state);
}
int
drm_atomic_set_crtc_for_connector(struct drm_connector_state *conn_state,
struct drm_crtc *crtc)
{
struct drm_crtc_state *crtc_state;
if (crtc) {
crtc_state = drm_atomic_get_crtc_state(conn_state->state, crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
}
conn_state->crtc = crtc;
if (crtc)
DRM_DEBUG_KMS("Link connector state %p to [CRTC:%d]\n",
conn_state, crtc->base.id);
else
DRM_DEBUG_KMS("Link connector state %p to [NOCRTC]\n",
conn_state);
return 0;
}
int
drm_atomic_add_affected_connectors(struct drm_atomic_state *state,
struct drm_crtc *crtc)
{
struct drm_mode_config *config = &state->dev->mode_config;
struct drm_connector *connector;
struct drm_connector_state *conn_state;
int ret;
ret = drm_modeset_lock(&config->connection_mutex, state->acquire_ctx);
if (ret)
return ret;
DRM_DEBUG_KMS("Adding all current connectors for [CRTC:%d] to %p\n",
crtc->base.id, state);
list_for_each_entry(connector, &config->connector_list, head) {
if (connector->state->crtc != crtc)
continue;
conn_state = drm_atomic_get_connector_state(state, connector);
if (IS_ERR(conn_state))
return PTR_ERR(conn_state);
}
return 0;
}
int
drm_atomic_connectors_for_crtc(struct drm_atomic_state *state,
struct drm_crtc *crtc)
{
int i, num_connected_connectors = 0;
for (i = 0; i < state->num_connector; i++) {
struct drm_connector_state *conn_state;
conn_state = state->connector_states[i];
if (conn_state && conn_state->crtc == crtc)
num_connected_connectors++;
}
DRM_DEBUG_KMS("State %p has %i connectors for [CRTC:%d]\n",
state, num_connected_connectors, crtc->base.id);
return num_connected_connectors;
}
void drm_atomic_legacy_backoff(struct drm_atomic_state *state)
{
int ret;
retry:
drm_modeset_backoff(state->acquire_ctx);
ret = drm_modeset_lock(&state->dev->mode_config.connection_mutex,
state->acquire_ctx);
if (ret)
goto retry;
ret = drm_modeset_lock_all_crtcs(state->dev,
state->acquire_ctx);
if (ret)
goto retry;
}
int drm_atomic_check_only(struct drm_atomic_state *state)
{
struct drm_mode_config *config = &state->dev->mode_config;
DRM_DEBUG_KMS("checking %p\n", state);
if (config->funcs->atomic_check)
return config->funcs->atomic_check(state->dev, state);
else
return 0;
}
int drm_atomic_commit(struct drm_atomic_state *state)
{
struct drm_mode_config *config = &state->dev->mode_config;
int ret;
ret = drm_atomic_check_only(state);
if (ret)
return ret;
DRM_DEBUG_KMS("commiting %p\n", state);
return config->funcs->atomic_commit(state->dev, state, false);
}
int drm_atomic_async_commit(struct drm_atomic_state *state)
{
struct drm_mode_config *config = &state->dev->mode_config;
int ret;
ret = drm_atomic_check_only(state);
if (ret)
return ret;
DRM_DEBUG_KMS("commiting %p asynchronously\n", state);
return config->funcs->atomic_commit(state->dev, state, true);
}
