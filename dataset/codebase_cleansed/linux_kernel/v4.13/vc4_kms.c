static void vc4_output_poll_changed(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
drm_fbdev_cma_hotplug_event(vc4->fbdev);
}
static void
vc4_atomic_complete_commit(struct vc4_commit *c)
{
struct drm_atomic_state *state = c->state;
struct drm_device *dev = state->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
drm_atomic_helper_wait_for_fences(dev, state, false);
drm_atomic_helper_wait_for_dependencies(state);
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_planes(dev, state, 0);
drm_atomic_helper_commit_modeset_enables(dev, state);
state->legacy_cursor_update = false;
drm_atomic_helper_commit_hw_done(state);
drm_atomic_helper_wait_for_vblanks(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
drm_atomic_helper_commit_cleanup_done(state);
drm_atomic_state_put(state);
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
bool nonblock)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
int ret;
int i;
uint64_t wait_seqno = 0;
struct vc4_commit *c;
struct drm_plane *plane;
struct drm_plane_state *new_state;
c = commit_init(state);
if (!c)
return -ENOMEM;
ret = drm_atomic_helper_setup_commit(state, nonblock);
if (ret)
return ret;
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
for_each_plane_in_state(state, plane, new_state, i) {
if ((plane->state->fb != new_state->fb) && new_state->fb) {
struct drm_gem_cma_object *cma_bo =
drm_fb_cma_get_gem_obj(new_state->fb, 0);
struct vc4_bo *bo = to_vc4_bo(&cma_bo->base);
wait_seqno = max(bo->seqno, wait_seqno);
}
}
drm_atomic_helper_swap_state(state, true);
drm_atomic_state_get(state);
if (nonblock) {
vc4_queue_seqno_cb(dev, &c->cb, wait_seqno,
vc4_atomic_complete_commit_seqno_cb);
} else {
vc4_wait_for_seqno(dev, wait_seqno, ~0ull, false);
vc4_atomic_complete_commit(c);
}
return 0;
}
static struct drm_framebuffer *vc4_fb_create(struct drm_device *dev,
struct drm_file *file_priv,
const struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_mode_fb_cmd2 mode_cmd_local;
if (!(mode_cmd->flags & DRM_MODE_FB_MODIFIERS)) {
struct drm_gem_object *gem_obj;
struct vc4_bo *bo;
gem_obj = drm_gem_object_lookup(file_priv,
mode_cmd->handles[0]);
if (!gem_obj) {
DRM_ERROR("Failed to look up GEM BO %d\n",
mode_cmd->handles[0]);
return ERR_PTR(-ENOENT);
}
bo = to_vc4_bo(gem_obj);
mode_cmd_local = *mode_cmd;
if (bo->t_format) {
mode_cmd_local.modifier[0] =
DRM_FORMAT_MOD_BROADCOM_VC4_T_TILED;
} else {
mode_cmd_local.modifier[0] = DRM_FORMAT_MOD_NONE;
}
drm_gem_object_unreference_unlocked(gem_obj);
mode_cmd = &mode_cmd_local;
}
return drm_fb_cma_create(dev, file_priv, mode_cmd);
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
drm_mode_config_reset(dev);
if (dev->mode_config.num_connector) {
vc4->fbdev = drm_fbdev_cma_init(dev, 32,
dev->mode_config.num_connector);
if (IS_ERR(vc4->fbdev))
vc4->fbdev = NULL;
}
drm_kms_helper_poll_init(dev);
return 0;
}
