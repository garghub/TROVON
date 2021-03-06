static void exynos_drm_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_manager *manager = exynos_crtc->manager;
DRM_DEBUG_KMS("crtc[%d] mode[%d]\n", crtc->base.id, mode);
if (exynos_crtc->dpms == mode) {
DRM_DEBUG_KMS("desired dpms mode is same as previous one.\n");
return;
}
if (mode > DRM_MODE_DPMS_ON) {
wait_event(exynos_crtc->pending_flip_queue,
atomic_read(&exynos_crtc->pending_flip) == 0);
drm_vblank_off(crtc->dev, exynos_crtc->pipe);
}
if (manager->ops->dpms)
manager->ops->dpms(manager, mode);
exynos_crtc->dpms = mode;
}
static void exynos_drm_crtc_prepare(struct drm_crtc *crtc)
{
}
static void exynos_drm_crtc_commit(struct drm_crtc *crtc)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_manager *manager = exynos_crtc->manager;
exynos_drm_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
exynos_plane_commit(exynos_crtc->plane);
if (manager->ops->commit)
manager->ops->commit(manager);
exynos_plane_dpms(exynos_crtc->plane, DRM_MODE_DPMS_ON);
}
static bool
exynos_drm_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_manager *manager = exynos_crtc->manager;
if (manager->ops->mode_fixup)
return manager->ops->mode_fixup(manager, mode, adjusted_mode);
return true;
}
static int
exynos_drm_crtc_mode_set(struct drm_crtc *crtc, struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode, int x, int y,
struct drm_framebuffer *old_fb)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct exynos_drm_manager *manager = exynos_crtc->manager;
struct drm_plane *plane = exynos_crtc->plane;
unsigned int crtc_w;
unsigned int crtc_h;
int ret;
memcpy(&crtc->mode, adjusted_mode, sizeof(*adjusted_mode));
crtc_w = crtc->primary->fb->width - x;
crtc_h = crtc->primary->fb->height - y;
if (manager->ops->mode_set)
manager->ops->mode_set(manager, &crtc->mode);
ret = exynos_plane_mode_set(plane, crtc, crtc->primary->fb, 0, 0, crtc_w, crtc_h,
x, y, crtc_w, crtc_h);
if (ret)
return ret;
plane->crtc = crtc;
plane->fb = crtc->primary->fb;
drm_framebuffer_reference(plane->fb);
return 0;
}
static int exynos_drm_crtc_mode_set_commit(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
struct drm_plane *plane = exynos_crtc->plane;
unsigned int crtc_w;
unsigned int crtc_h;
int ret;
if (exynos_crtc->dpms > DRM_MODE_DPMS_ON) {
DRM_ERROR("failed framebuffer changing request.\n");
return -EPERM;
}
crtc_w = crtc->primary->fb->width - x;
crtc_h = crtc->primary->fb->height - y;
ret = exynos_plane_mode_set(plane, crtc, crtc->primary->fb, 0, 0, crtc_w, crtc_h,
x, y, crtc_w, crtc_h);
if (ret)
return ret;
exynos_drm_crtc_commit(crtc);
return 0;
}
static int exynos_drm_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
return exynos_drm_crtc_mode_set_commit(crtc, x, y, old_fb);
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
ret = exynos_drm_crtc_mode_set_commit(crtc, crtc->x, crtc->y,
NULL);
if (ret) {
crtc->primary->fb = old_fb;
spin_lock_irq(&dev->event_lock);
drm_vblank_put(dev, exynos_crtc->pipe);
list_del(&event->base.link);
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
static int exynos_drm_crtc_set_property(struct drm_crtc *crtc,
struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = crtc->dev;
struct exynos_drm_private *dev_priv = dev->dev_private;
struct exynos_drm_crtc *exynos_crtc = to_exynos_crtc(crtc);
if (property == dev_priv->crtc_mode_property) {
enum exynos_crtc_mode mode = val;
if (mode == exynos_crtc->mode)
return 0;
exynos_crtc->mode = mode;
switch (mode) {
case CRTC_MODE_NORMAL:
exynos_drm_crtc_commit(crtc);
break;
case CRTC_MODE_BLANK:
exynos_plane_dpms(exynos_crtc->plane,
DRM_MODE_DPMS_OFF);
break;
default:
break;
}
return 0;
}
return -EINVAL;
}
static void exynos_drm_crtc_attach_mode_property(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct exynos_drm_private *dev_priv = dev->dev_private;
struct drm_property *prop;
prop = dev_priv->crtc_mode_property;
if (!prop) {
prop = drm_property_create_enum(dev, 0, "mode", mode_names,
ARRAY_SIZE(mode_names));
if (!prop)
return;
dev_priv->crtc_mode_property = prop;
}
drm_object_attach_property(&crtc->base, prop, 0);
}
int exynos_drm_crtc_create(struct exynos_drm_manager *manager)
{
struct exynos_drm_crtc *exynos_crtc;
struct exynos_drm_private *private = manager->drm_dev->dev_private;
struct drm_crtc *crtc;
exynos_crtc = kzalloc(sizeof(*exynos_crtc), GFP_KERNEL);
if (!exynos_crtc)
return -ENOMEM;
init_waitqueue_head(&exynos_crtc->pending_flip_queue);
atomic_set(&exynos_crtc->pending_flip, 0);
exynos_crtc->dpms = DRM_MODE_DPMS_OFF;
exynos_crtc->manager = manager;
exynos_crtc->pipe = manager->pipe;
exynos_crtc->plane = exynos_plane_init(manager->drm_dev,
1 << manager->pipe, true);
if (!exynos_crtc->plane) {
kfree(exynos_crtc);
return -ENOMEM;
}
manager->crtc = &exynos_crtc->drm_crtc;
crtc = &exynos_crtc->drm_crtc;
private->crtc[manager->pipe] = crtc;
drm_crtc_init(manager->drm_dev, crtc, &exynos_crtc_funcs);
drm_crtc_helper_add(crtc, &exynos_crtc_helper_funcs);
exynos_drm_crtc_attach_mode_property(crtc);
return 0;
}
int exynos_drm_crtc_enable_vblank(struct drm_device *dev, int pipe)
{
struct exynos_drm_private *private = dev->dev_private;
struct exynos_drm_crtc *exynos_crtc =
to_exynos_crtc(private->crtc[pipe]);
struct exynos_drm_manager *manager = exynos_crtc->manager;
if (exynos_crtc->dpms != DRM_MODE_DPMS_ON)
return -EPERM;
if (manager->ops->enable_vblank)
manager->ops->enable_vblank(manager);
return 0;
}
void exynos_drm_crtc_disable_vblank(struct drm_device *dev, int pipe)
{
struct exynos_drm_private *private = dev->dev_private;
struct exynos_drm_crtc *exynos_crtc =
to_exynos_crtc(private->crtc[pipe]);
struct exynos_drm_manager *manager = exynos_crtc->manager;
if (exynos_crtc->dpms != DRM_MODE_DPMS_ON)
return;
if (manager->ops->disable_vblank)
manager->ops->disable_vblank(manager);
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
void exynos_drm_crtc_plane_mode_set(struct drm_crtc *crtc,
struct exynos_drm_overlay *overlay)
{
struct exynos_drm_manager *manager = to_exynos_crtc(crtc)->manager;
if (manager->ops->win_mode_set)
manager->ops->win_mode_set(manager, overlay);
}
void exynos_drm_crtc_plane_commit(struct drm_crtc *crtc, int zpos)
{
struct exynos_drm_manager *manager = to_exynos_crtc(crtc)->manager;
if (manager->ops->win_commit)
manager->ops->win_commit(manager, zpos);
}
void exynos_drm_crtc_plane_enable(struct drm_crtc *crtc, int zpos)
{
struct exynos_drm_manager *manager = to_exynos_crtc(crtc)->manager;
if (manager->ops->win_enable)
manager->ops->win_enable(manager, zpos);
}
void exynos_drm_crtc_plane_disable(struct drm_crtc *crtc, int zpos)
{
struct exynos_drm_manager *manager = to_exynos_crtc(crtc)->manager;
if (manager->ops->win_disable)
manager->ops->win_disable(manager, zpos);
}
void exynos_drm_crtc_complete_scanout(struct drm_framebuffer *fb)
{
struct exynos_drm_manager *manager;
struct drm_device *dev = fb->dev;
struct drm_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
manager = to_exynos_crtc(crtc)->manager;
if (manager->ops->wait_for_vblank)
manager->ops->wait_for_vblank(manager);
}
}
int exynos_drm_crtc_get_pipe_from_type(struct drm_device *drm_dev,
unsigned int out_type)
{
struct drm_crtc *crtc;
list_for_each_entry(crtc, &drm_dev->mode_config.crtc_list, head) {
struct exynos_drm_crtc *exynos_crtc;
exynos_crtc = to_exynos_crtc(crtc);
if (exynos_crtc->manager->type == out_type)
return exynos_crtc->manager->pipe;
}
return -EPERM;
}
