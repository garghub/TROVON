static void exynos_drm_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
DRM_DEBUG_KMS("crtc[%d] mode[%d]\n", crtc->base.id, mode);
if (exynos_crtc->dpms == mode) {
DRM_DEBUG_KMS("desired dpms mode is same as previous one.\n");
return;
}
if (mode > DRM_MODE_DPMS_ON) {
if (!wait_event_timeout(exynos_crtc->pending_flip_queue,
!atomic_read(&exynos_crtc->pending_flip),
HZ/20))
atomic_set(&exynos_crtc->pending_flip, 0);
drm_crtc_vblank_off(crtc);
}
if (exynos_crtc->ops->dpms)
exynos_crtc->ops->dpms(exynos_crtc, mode);
exynos_crtc->dpms = mode;
if (mode == DRM_MODE_DPMS_ON)
drm_crtc_vblank_on(crtc);
}
static void exynos_drm_crtc_prepare(struct drm_crtc *crtc)
{
}
static void exynos_drm_crtc_commit(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_plane *exynos_plane = to_exynos_plane(crtc->primary);
exynos_drm_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
if (exynos_crtc->ops->win_commit)
exynos_crtc->ops->win_commit(exynos_crtc, exynos_plane->zpos);
if (exynos_crtc->ops->commit)
exynos_crtc->ops->commit(exynos_crtc);
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
static int
exynos_drm_crtc_mode_set(struct drm_crtc *crtc, struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode, int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_framebuffer *fb = crtc->primary->fb;
unsigned int crtc_w;
unsigned int crtc_h;
int ret;
memcpy(&crtc->mode, adjusted_mode, sizeof(*adjusted_mode));
ret = exynos_check_plane(crtc->primary, fb);
if (ret < 0)
return ret;
crtc_w = fb->width - x;
crtc_h = fb->height - y;
exynos_plane_mode_set(crtc->primary, crtc, fb, 0, 0,
crtc_w, crtc_h, x, y, crtc_w, crtc_h);
return 0;
}
static int exynos_drm_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct drm_framebuffer *fb = crtc->primary->fb;
unsigned int crtc_w;
unsigned int crtc_h;
if (exynos_crtc->dpms > DRM_MODE_DPMS_ON) {
DRM_ERROR("failed framebuffer changing request.\n");
return -EPERM;
}
crtc_w = fb->width - x;
crtc_h = fb->height - y;
return exynos_update_plane(crtc->primary, crtc, fb, 0, 0,
crtc_w, crtc_h, x, y, crtc_w, crtc_h);
}
static void exynos_drm_crtc_disable(struct drm_crtc *crtc)
{
struct drm_plane *plane;
int ret;
exynos_drm_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
drm_for_each_legacy_plane(plane, &crtc->dev->mode_config.plane_list) {
if (plane->crtc != crtc)
continue;
ret = plane->funcs->disable_plane(plane);
if (ret)
DRM_ERROR("Failed to disable plane %d\n", ret);
}
}
static int exynos_drm_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags)
{
struct drm_device *dev = crtc->dev;
struct exynos_drm_private *dev_priv = dev->dev_private;
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct drm_framebuffer *old_fb = crtc->primary->fb;
unsigned int crtc_w, crtc_h;
int ret = -EINVAL;
if (exynos_crtc->dpms > DRM_MODE_DPMS_ON) {
DRM_ERROR("failed page flip request.\n");
return -EINVAL;
}
mutex_lock(&dev->struct_mutex);
if (event) {
event->pipe = exynos_crtc->pipe;
ret = drm_vblank_get(dev, exynos_crtc->pipe);
if (ret) {
DRM_DEBUG("failed to acquire vblank counter\n");
goto out;
}
spin_lock_irq(&dev->event_lock);
list_add_tail(&event->base.link,
&dev_priv->pageflip_event_list);
atomic_set(&exynos_crtc->pending_flip, 1);
spin_unlock_irq(&dev->event_lock);
crtc->primary->fb = fb;
crtc_w = fb->width - crtc->x;
crtc_h = fb->height - crtc->y;
ret = exynos_update_plane(crtc->primary, crtc, fb, 0, 0,
crtc_w, crtc_h, crtc->x, crtc->y,
crtc_w, crtc_h);
if (ret) {
crtc->primary->fb = old_fb;
spin_lock_irq(&dev->event_lock);
drm_vblank_put(dev, exynos_crtc->pipe);
list_del(&event->base.link);
atomic_set(&exynos_crtc->pending_flip, 0);
spin_unlock_irq(&dev->event_lock);
goto out;
}
}
out:
mutex_unlock(&dev->struct_mutex);
return ret;
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
int pipe,
enum exynos_drm_output_type type,
struct exynos_drm_crtc_ops *ops,
void *ctx)
{
struct exynos_drm_crtc *exynos_crtc;
struct drm_plane *plane;
struct exynos_drm_private *private = drm_dev->dev_private;
struct drm_crtc *crtc;
int ret;
exynos_crtc = kzalloc(sizeof(*exynos_crtc), GFP_KERNEL);
if (!exynos_crtc)
return ERR_PTR(-ENOMEM);
init_waitqueue_head(&exynos_crtc->pending_flip_queue);
atomic_set(&exynos_crtc->pending_flip, 0);
exynos_crtc->dpms = DRM_MODE_DPMS_OFF;
exynos_crtc->pipe = pipe;
exynos_crtc->type = type;
exynos_crtc->ops = ops;
exynos_crtc->ctx = ctx;
plane = exynos_plane_init(drm_dev, 1 << pipe,
DRM_PLANE_TYPE_PRIMARY);
if (IS_ERR(plane)) {
ret = PTR_ERR(plane);
goto err_plane;
}
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
err_plane:
kfree(exynos_crtc);
return ERR_PTR(ret);
}
int exynos_drm_crtc_enable_vblank(struct drm_device *dev, int pipe)
{
struct exynos_drm_private *private = dev->dev_private;
struct exynos_drm_crtc *exynos_crtc =
to_exynos_crtc(private->crtc[pipe]);
if (exynos_crtc->dpms != DRM_MODE_DPMS_ON)
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
if (exynos_crtc->dpms != DRM_MODE_DPMS_ON)
return;
if (exynos_crtc->ops->disable_vblank)
exynos_crtc->ops->disable_vblank(exynos_crtc);
}
void exynos_drm_crtc_finish_pageflip(struct drm_device *dev, int pipe)
{
struct exynos_drm_private *dev_priv = dev->dev_private;
struct drm_pending_vblank_event *e, *t;
struct drm_crtc *drm_crtc = dev_priv->crtc[pipe];
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(drm_crtc);
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
list_for_each_entry_safe(e, t, &dev_priv->pageflip_event_list,
base.link) {
if (pipe != e->pipe)
continue;
list_del(&e->base.link);
drm_send_vblank_event(dev, -1, e);
drm_vblank_put(dev, pipe);
atomic_set(&exynos_crtc->pending_flip, 0);
wake_up(&exynos_crtc->pending_flip_queue);
}
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
