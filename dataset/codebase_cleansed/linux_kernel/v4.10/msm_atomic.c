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
INIT_WORK(&c->work, commit_worker);
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
struct drm_crtc_state *crtc_state;
struct msm_drm_private *priv = old_state->dev->dev_private;
struct msm_kms *kms = priv->kms;
int i;
for_each_crtc_in_state(old_state, crtc, crtc_state, i) {
if (!crtc->state->enable)
continue;
if (old_state->legacy_cursor_update)
continue;
kms->funcs->wait_for_crtc_commit_done(kms, crtc);
}
}
static void complete_commit(struct msm_commit *c, bool async)
{
struct drm_atomic_state *state = c->state;
struct drm_device *dev = state->dev;
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
drm_atomic_helper_wait_for_fences(dev, state, false);
kms->funcs->prepare_commit(kms, state);
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_planes(dev, state, 0);
drm_atomic_helper_commit_modeset_enables(dev, state);
msm_atomic_wait_for_commit_done(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
kms->funcs->complete_commit(kms, state);
drm_atomic_state_put(state);
commit_destroy(c);
}
static void commit_worker(struct work_struct *work)
{
complete_commit(container_of(work, struct msm_commit, work), true);
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
struct drm_atomic_state *state, bool nonblock)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_commit *c;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_plane *plane;
struct drm_plane_state *plane_state;
int i, ret;
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
c = commit_init(state);
if (!c) {
ret = -ENOMEM;
goto error;
}
for_each_crtc_in_state(state, crtc, crtc_state, i)
c->crtc_mask |= drm_crtc_mask(crtc);
for_each_plane_in_state(state, plane, plane_state, i) {
if ((plane->state->fb != plane_state->fb) && plane_state->fb) {
struct drm_gem_object *obj = msm_framebuffer_bo(plane_state->fb, 0);
struct msm_gem_object *msm_obj = to_msm_bo(obj);
struct dma_fence *fence = reservation_object_get_excl_rcu(msm_obj->resv);
drm_atomic_set_fence_for_plane(plane_state, fence);
}
}
ret = start_atomic(dev->dev_private, c->crtc_mask);
if (ret) {
kfree(c);
goto error;
}
drm_atomic_helper_swap_state(state, true);
if (to_kms_state(state)->state)
priv->kms->funcs->swap_state(priv->kms, state);
drm_atomic_state_get(state);
if (nonblock) {
queue_work(priv->atomic_wq, &c->work);
return 0;
}
complete_commit(c, false);
return 0;
error:
drm_atomic_helper_cleanup_planes(dev, state);
return ret;
}
struct drm_atomic_state *msm_atomic_state_alloc(struct drm_device *dev)
{
struct msm_kms_state *state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state || drm_atomic_state_init(dev, &state->base) < 0) {
kfree(state);
return NULL;
}
return &state->base;
}
void msm_atomic_state_clear(struct drm_atomic_state *s)
{
struct msm_kms_state *state = to_kms_state(s);
drm_atomic_state_default_clear(&state->base);
kfree(state->state);
state->state = NULL;
}
void msm_atomic_state_free(struct drm_atomic_state *state)
{
kfree(to_kms_state(state)->state);
drm_atomic_state_default_release(state);
kfree(state);
}
