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
static struct msm_commit *new_commit(struct drm_atomic_state *state)
{
struct msm_commit *c = kzalloc(sizeof(*c), GFP_KERNEL);
if (!c)
return NULL;
c->state = state;
INIT_FENCE_CB(&c->fence_cb, fence_cb);
return c;
}
static void complete_commit(struct msm_commit *c)
{
struct drm_atomic_state *state = c->state;
struct drm_device *dev = state->dev;
drm_atomic_helper_commit_pre_planes(dev, state);
drm_atomic_helper_commit_planes(dev, state);
drm_atomic_helper_commit_post_planes(dev, state);
drm_atomic_helper_wait_for_vblanks(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
drm_atomic_state_free(state);
end_atomic(dev->dev_private, c->crtc_mask);
kfree(c);
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
int msm_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state, bool async)
{
int nplanes = dev->mode_config.num_total_plane;
int ncrtcs = dev->mode_config.num_crtc;
struct msm_commit *c;
int i, ret;
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
c = new_commit(state);
if (!c)
return -ENOMEM;
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
if (ret)
return ret;
drm_atomic_helper_swap_state(dev, state);
if (async) {
msm_queue_fence_cb(dev, &c->fence_cb, c->fence);
return 0;
}
ret = msm_wait_fence_interruptable(dev, c->fence, NULL);
if (ret) {
WARN_ON(ret);
kfree(c);
return ret;
}
complete_commit(c);
return 0;
}
