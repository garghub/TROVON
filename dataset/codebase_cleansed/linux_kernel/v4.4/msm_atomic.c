static int start_atomic(struct msm_drm_private *priv, uint32_t crtc_mask)
{
int ret;
spin_lock(&priv->pending_crtcs_event.lock);
ret = wait_event_interruptible_locked(priv->pending_crtcs_event,
!(priv->pending_crtcs & crtc_mask));
if (ret == 0) {
DBG("start: %08x", crtc_mask);
priv->pending_crtcs |= crtc_mask;
}
spin_unlock(&priv->pending_crtcs_event.lock);
return ret;
}
static void end_atomic(struct msm_drm_private *priv, uint32_t crtc_mask)
{
spin_lock(&priv->pending_crtcs_event.lock);
DBG("end: %08x", crtc_mask);
priv->pending_crtcs &= ~crtc_mask;
wake_up_all_locked(&priv->pending_crtcs_event);
spin_unlock(&priv->pending_crtcs_event.lock);
}
static struct msm_commit *commit_init(struct drm_atomic_state *state)
{
struct msm_commit *c = kzalloc(sizeof(*c), GFP_KERNEL);
if (!c)
return NULL;
c->dev = state->dev;
c->state = state;
INIT_FENCE_CB(&c->fence_cb, fence_cb);
return c;
}
static void commit_destroy(struct msm_commit *c)
{
end_atomic(c->dev->dev_private, c->crtc_mask);
kfree(c);
}
static void msm_atomic_wait_for_commit_done(struct drm_device *dev,
struct drm_atomic_state *old_state)
{
struct drm_crtc *crtc;
struct msm_drm_private *priv = old_state->dev->dev_private;
struct msm_kms *kms = priv->kms;
int ncrtcs = old_state->dev->mode_config.num_crtc;
int i;
for (i = 0; i < ncrtcs; i++) {
crtc = old_state->crtcs[i];
if (!crtc)
continue;
if (!crtc->state->enable)
continue;
if (old_state->legacy_cursor_update)
continue;
kms->funcs->wait_for_crtc_commit_done(kms, crtc);
}
}
static void complete_commit(struct msm_commit *c)
{
struct drm_atomic_state *state = c->state;
struct drm_device *dev = state->dev;
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
kms->funcs->prepare_commit(kms, state);
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_planes(dev, state, false);
drm_atomic_helper_commit_modeset_enables(dev, state);
msm_atomic_wait_for_commit_done(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
kms->funcs->complete_commit(kms, state);
drm_atomic_state_free(state);
commit_destroy(c);
}
static void fence_cb(struct msm_fence_cb *cb)
{
struct msm_commit *c =
container_of(cb, struct msm_commit, fence_cb);
complete_commit(c);
}
static void add_fb(struct msm_commit *c, struct drm_framebuffer *fb)
{
struct drm_gem_object *obj = msm_framebuffer_bo(fb, 0);
c->fence = max(c->fence, msm_gem_fence(to_msm_bo(obj), MSM_PREP_READ));
}
int msm_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
int ret;
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
return ret;
}
int msm_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state, bool async)
{
int nplanes = dev->mode_config.num_total_plane;
int ncrtcs = dev->mode_config.num_crtc;
ktime_t timeout;
struct msm_commit *c;
int i, ret;
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
c = commit_init(state);
if (!c) {
ret = -ENOMEM;
goto error;
}
for (i = 0; i < ncrtcs; i++) {
struct drm_crtc *crtc = state->crtcs[i];
if (!crtc)
continue;
c->crtc_mask |= (1 << drm_crtc_index(crtc));
}
for (i = 0; i < nplanes; i++) {
struct drm_plane *plane = state->planes[i];
struct drm_plane_state *new_state = state->plane_states[i];
if (!plane)
continue;
if ((plane->state->fb != new_state->fb) && new_state->fb)
add_fb(c, new_state->fb);
}
ret = start_atomic(dev->dev_private, c->crtc_mask);
if (ret) {
kfree(c);
goto error;
}
drm_atomic_helper_swap_state(dev, state);
if (async) {
msm_queue_fence_cb(dev, &c->fence_cb, c->fence);
return 0;
}
timeout = ktime_add_ms(ktime_get(), 1000);
msm_wait_fence(dev, c->fence, &timeout, false);
complete_commit(c);
return 0;
error:
drm_atomic_helper_cleanup_planes(dev, state);
return ret;
}
