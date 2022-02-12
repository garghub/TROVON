static void sun4i_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct sun4i_crtc *scrtc = drm_crtc_to_sun4i_crtc(crtc);
struct drm_device *dev = crtc->dev;
unsigned long flags;
if (crtc->state->event) {
WARN_ON(drm_crtc_vblank_get(crtc) != 0);
spin_lock_irqsave(&dev->event_lock, flags);
scrtc->event = crtc->state->event;
spin_unlock_irqrestore(&dev->event_lock, flags);
crtc->state->event = NULL;
}
}
static void sun4i_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct sun4i_crtc *scrtc = drm_crtc_to_sun4i_crtc(crtc);
struct sun4i_drv *drv = scrtc->drv;
struct drm_pending_vblank_event *event = crtc->state->event;
DRM_DEBUG_DRIVER("Committing plane changes\n");
sun4i_backend_commit(drv->backend);
if (event) {
crtc->state->event = NULL;
spin_lock_irq(&crtc->dev->event_lock);
if (drm_crtc_vblank_get(crtc) == 0)
drm_crtc_arm_vblank_event(crtc, event);
else
drm_crtc_send_vblank_event(crtc, event);
spin_unlock_irq(&crtc->dev->event_lock);
}
}
static void sun4i_crtc_disable(struct drm_crtc *crtc)
{
struct sun4i_crtc *scrtc = drm_crtc_to_sun4i_crtc(crtc);
struct sun4i_drv *drv = scrtc->drv;
DRM_DEBUG_DRIVER("Disabling the CRTC\n");
sun4i_tcon_disable(drv->tcon);
if (crtc->state->event && !crtc->state->active) {
spin_lock_irq(&crtc->dev->event_lock);
drm_crtc_send_vblank_event(crtc, crtc->state->event);
spin_unlock_irq(&crtc->dev->event_lock);
crtc->state->event = NULL;
}
}
static void sun4i_crtc_enable(struct drm_crtc *crtc)
{
struct sun4i_crtc *scrtc = drm_crtc_to_sun4i_crtc(crtc);
struct sun4i_drv *drv = scrtc->drv;
DRM_DEBUG_DRIVER("Enabling the CRTC\n");
sun4i_tcon_enable(drv->tcon);
}
struct sun4i_crtc *sun4i_crtc_init(struct drm_device *drm)
{
struct sun4i_drv *drv = drm->dev_private;
struct sun4i_crtc *scrtc;
int ret;
scrtc = devm_kzalloc(drm->dev, sizeof(*scrtc), GFP_KERNEL);
if (!scrtc)
return NULL;
scrtc->drv = drv;
ret = drm_crtc_init_with_planes(drm, &scrtc->crtc,
drv->primary,
NULL,
&sun4i_crtc_funcs,
NULL);
if (ret) {
dev_err(drm->dev, "Couldn't init DRM CRTC\n");
return NULL;
}
drm_crtc_helper_add(&scrtc->crtc, &sun4i_crtc_helper_funcs);
return scrtc;
}
