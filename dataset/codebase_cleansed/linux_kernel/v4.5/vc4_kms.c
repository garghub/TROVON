static void vc4_output_poll_changed(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
if (vc4->fbdev)
drm_fbdev_cma_hotplug_event(vc4->fbdev);
}
static void
vc4_atomic_complete_commit(struct vc4_commit *c)
{
struct drm_atomic_state *state = c->state;
struct drm_device *dev = state->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_planes(dev, state, false);
drm_atomic_helper_commit_modeset_enables(dev, state);
drm_atomic_helper_wait_for_vblanks(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
drm_atomic_state_free(state);
up(&vc4->async_modeset);
kfree(c);
}
static void
vc4_atomic_complete_commit_seqno_cb(struct vc4_seqno_cb *cb)
{
struct vc4_commit *c = container_of(cb, struct vc4_commit, cb);
vc4_atomic_complete_commit(c);
}
static struct vc4_commit *commit_init(struct drm_atomic_state *state)
{
struct vc4_commit *c = kzalloc(sizeof(*c), GFP_KERNEL);
if (!c)
return NULL;
c->dev = state->dev;
c->state = state;
return c;
}
static int vc4_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state,
bool async)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
int ret;
int i;
uint64_t wait_seqno = 0;
struct vc4_commit *c;
c = commit_init(state);
if (!c)
return -ENOMEM;
ret = down_interruptible(&vc4->async_modeset);
if (ret) {
kfree(c);
return ret;
}
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret) {
kfree(c);
up(&vc4->async_modeset);
return ret;
}
for (i = 0; i < dev->mode_config.num_total_plane; i++) {
struct drm_plane *plane = state->planes[i];
struct drm_plane_state *new_state = state->plane_states[i];
if (!plane)
continue;
if ((plane->state->fb != new_state->fb) && new_state->fb) {
struct drm_gem_cma_object *cma_bo =
drm_fb_cma_get_gem_obj(new_state->fb, 0);
struct vc4_bo *bo = to_vc4_bo(&cma_bo->base);
wait_seqno = max(bo->seqno, wait_seqno);
}
}
drm_atomic_helper_swap_state(dev, state);
if (async) {
vc4_queue_seqno_cb(dev, &c->cb, wait_seqno,
vc4_atomic_complete_commit_seqno_cb);
} else {
vc4_wait_for_seqno(dev, wait_seqno, ~0ull, false);
vc4_atomic_complete_commit(c);
}
return 0;
}
int vc4_kms_load(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
int ret;
sema_init(&vc4->async_modeset, 1);
ret = drm_vblank_init(dev, dev->mode_config.num_crtc);
if (ret < 0) {
dev_err(dev->dev, "failed to initialize vblank\n");
return ret;
}
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
dev->mode_config.funcs = &vc4_mode_funcs;
dev->mode_config.preferred_depth = 24;
dev->mode_config.async_page_flip = true;
dev->vblank_disable_allowed = true;
drm_mode_config_reset(dev);
vc4->fbdev = drm_fbdev_cma_init(dev, 32,
dev->mode_config.num_crtc,
dev->mode_config.num_connector);
if (IS_ERR(vc4->fbdev))
vc4->fbdev = NULL;
drm_kms_helper_poll_init(dev);
return 0;
}
