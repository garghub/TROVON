static void exynos_drm_crtc_enable(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->enabled)
return;
if (exynos_crtc->ops->enable)
exynos_crtc->ops->enable(exynos_crtc);
exynos_crtc->enabled = true;
drm_crtc_vblank_on(crtc);
}
static void exynos_drm_crtc_disable(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (!exynos_crtc->enabled)
return;
if (!wait_event_timeout(exynos_crtc->pending_flip_queue,
(exynos_crtc->event == NULL), HZ/20))
exynos_crtc->event = NULL;
drm_crtc_vblank_off(crtc);
if (exynos_crtc->ops->disable)
exynos_crtc->ops->disable(exynos_crtc);
exynos_crtc->enabled = false;
}
static bool
exynos_drm_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->mode_fixup)
return exynos_crtc->ops->mode_fixup(exynos_crtc, mode,
adjusted_mode);
return true;
}
static void
exynos_drm_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->commit)
exynos_crtc->ops->commit(exynos_crtc);
}
static void exynos_crtc_atomic_begin(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (crtc->state->event) {
WARN_ON(drm_crtc_vblank_get(crtc) != 0);
exynos_crtc->event = crtc->state->event;
}
}
static void exynos_crtc_atomic_flush(struct drm_crtc *crtc)
{
}
static void exynos_drm_crtc_destroy(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_private *private = crtc->dev->dev_private;
private->crtc[exynos_crtc->pipe] = NULL;
drm_crtc_cleanup(crtc);
kfree(exynos_crtc);
}
struct exynos_drm_crtc *exynos_drm_crtc_create(struct drm_device *drm_dev,
struct drm_plane *plane,
int pipe,
enum exynos_drm_output_type type,
const struct exynos_drm_crtc_ops *ops,
void *ctx)
{
struct exynos_drm_crtc *exynos_crtc;
struct exynos_drm_private *private = drm_dev->dev_private;
struct drm_crtc *crtc;
int ret;
exynos_crtc = kzalloc(sizeof(*exynos_crtc), GFP_KERNEL);
if (!exynos_crtc)
return ERR_PTR(-ENOMEM);
init_waitqueue_head(&exynos_crtc->pending_flip_queue);
exynos_crtc->pipe = pipe;
exynos_crtc->type = type;
exynos_crtc->ops = ops;
exynos_crtc->ctx = ctx;
crtc = &exynos_crtc->base;
private->crtc[pipe] = crtc;
ret = drm_crtc_init_with_planes(drm_dev, crtc, plane, NULL,
&exynos_crtc_funcs);
if (ret < 0)
goto err_crtc;
drm_crtc_helper_add(crtc, &exynos_crtc_helper_funcs);
return exynos_crtc;
err_crtc:
plane->funcs->destroy(plane);
kfree(exynos_crtc);
return ERR_PTR(ret);
}
int exynos_drm_crtc_enable_vblank(struct drm_device *dev, int pipe)
{
struct exynos_drm_private *private = dev->dev_private;
struct exynos_drm_crtc *exynos_crtc =
to_exynos_crtc(private->crtc[pipe]);
if (!exynos_crtc->enabled)
return -EPERM;
if (exynos_crtc->ops->enable_vblank)
exynos_crtc->ops->enable_vblank(exynos_crtc);
return 0;
}
void exynos_drm_crtc_disable_vblank(struct drm_device *dev, int pipe)
{
struct exynos_drm_private *private = dev->dev_private;
struct exynos_drm_crtc *exynos_crtc =
to_exynos_crtc(private->crtc[pipe]);
if (!exynos_crtc->enabled)
return;
if (exynos_crtc->ops->disable_vblank)
exynos_crtc->ops->disable_vblank(exynos_crtc);
}
void exynos_drm_crtc_finish_pageflip(struct drm_device *dev, int pipe)
{
struct exynos_drm_private *dev_priv = dev->dev_private;
struct drm_crtc *drm_crtc = dev_priv->crtc[pipe];
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(drm_crtc);
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
if (exynos_crtc->event) {
drm_send_vblank_event(dev, -1, exynos_crtc->event);
drm_vblank_put(dev, pipe);
wake_up(&exynos_crtc->pending_flip_queue);
}
exynos_crtc->event = NULL;
spin_unlock_irqrestore(&dev->event_lock, flags);
}
void exynos_drm_crtc_complete_scanout(struct drm_framebuffer *fb)
{
struct exynos_drm_crtc *exynos_crtc;
struct drm_device *dev = fb->dev;
struct drm_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->ops->wait_for_vblank)
exynos_crtc->ops->wait_for_vblank(exynos_crtc);
}
}
int exynos_drm_crtc_get_pipe_from_type(struct drm_device *drm_dev,
unsigned int out_type)
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
