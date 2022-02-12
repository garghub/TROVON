static void exynos_drm_crtc_enable(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->enable)
exynos_crtc->ops->enable(exynos_crtc);
drm_crtc_vblank_on(crtc);
}
static void exynos_drm_crtc_disable(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
drm_crtc_vblank_off(crtc);
if (exynos_crtc->ops->disable)
exynos_crtc->ops->disable(exynos_crtc);
if (crtc->state->event && !crtc->state->active) {
spin_lock_irq(&crtc->dev->event_lock);
drm_crtc_send_vblank_event(crtc, crtc->state->event);
spin_unlock_irq(&crtc->dev->event_lock);
crtc->state->event = NULL;
}
}
static void
exynos_drm_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->commit)
exynos_crtc->ops->commit(exynos_crtc);
}
static int exynos_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (!state->enable)
return 0;
if (exynos_crtc->ops->atomic_check)
return exynos_crtc->ops->atomic_check(exynos_crtc, state);
return 0;
}
static void exynos_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->atomic_begin)
exynos_crtc->ops->atomic_begin(exynos_crtc);
}
static void exynos_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->atomic_flush)
exynos_crtc->ops->atomic_flush(exynos_crtc);
}
void exynos_crtc_handle_event(struct exynos_drm_crtc *exynos_crtc)
{
struct drm_crtc *crtc = &exynos_crtc->base;
struct drm_pending_vblank_event *event = crtc->state->event;
unsigned long flags;
if (event) {
crtc->state->event = NULL;
spin_lock_irqsave(&crtc->dev->event_lock, flags);
if (drm_crtc_vblank_get(crtc) == 0)
drm_crtc_arm_vblank_event(crtc, event);
else
drm_crtc_send_vblank_event(crtc, event);
spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
}
}
static void exynos_drm_crtc_destroy(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
drm_crtc_cleanup(crtc);
kfree(exynos_crtc);
}
static int exynos_drm_crtc_enable_vblank(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->enable_vblank)
return exynos_crtc->ops->enable_vblank(exynos_crtc);
return 0;
}
static void exynos_drm_crtc_disable_vblank(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->disable_vblank)
exynos_crtc->ops->disable_vblank(exynos_crtc);
}
struct exynos_drm_crtc *exynos_drm_crtc_create(struct drm_device *drm_dev,
struct drm_plane *plane,
int pipe,
enum exynos_drm_output_type type,
const struct exynos_drm_crtc_ops *ops,
void *ctx)
{
struct exynos_drm_crtc *exynos_crtc;
struct drm_crtc *crtc;
int ret;
exynos_crtc = kzalloc(sizeof(*exynos_crtc), GFP_KERNEL);
if (!exynos_crtc)
return ERR_PTR(-ENOMEM);
exynos_crtc->pipe = pipe;
exynos_crtc->type = type;
exynos_crtc->ops = ops;
exynos_crtc->ctx = ctx;
crtc = &exynos_crtc->base;
ret = drm_crtc_init_with_planes(drm_dev, crtc, plane, NULL,
&exynos_crtc_funcs, NULL);
if (ret < 0)
goto err_crtc;
drm_crtc_helper_add(crtc, &exynos_crtc_helper_funcs);
return exynos_crtc;
err_crtc:
plane->funcs->destroy(plane);
kfree(exynos_crtc);
return ERR_PTR(ret);
}
int exynos_drm_crtc_get_pipe_from_type(struct drm_device *drm_dev,
enum exynos_drm_output_type out_type)
{
struct drm_crtc *crtc;
list_for_each_entry(crtc, &drm_dev->mode_config.crtc_list, head) {
struct exynos_drm_crtc *exynos_crtc;
exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->type == out_type)
return exynos_crtc->pipe;
}
return -EPERM;
}
void exynos_drm_crtc_te_handler(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->te_handler)
exynos_crtc->ops->te_handler(exynos_crtc);
}
