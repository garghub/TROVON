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
struct drm_pending_vblank_event *event = crtc->state->event;
DRM_DEBUG_DRIVER("Committing plane changes\n");
sunxi_engine_commit(scrtc->engine);
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
static void sun4i_crtc_atomic_disable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct sun4i_crtc *scrtc = drm_crtc_to_sun4i_crtc(crtc);
DRM_DEBUG_DRIVER("Disabling the CRTC\n");
sun4i_tcon_disable(scrtc->tcon);
if (crtc->state->event && !crtc->state->active) {
spin_lock_irq(&crtc->dev->event_lock);
drm_crtc_send_vblank_event(crtc, crtc->state->event);
spin_unlock_irq(&crtc->dev->event_lock);
crtc->state->event = NULL;
}
}
static void sun4i_crtc_atomic_enable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct sun4i_crtc *scrtc = drm_crtc_to_sun4i_crtc(crtc);
DRM_DEBUG_DRIVER("Enabling the CRTC\n");
sun4i_tcon_enable(scrtc->tcon);
}
static int sun4i_crtc_enable_vblank(struct drm_crtc *crtc)
{
struct sun4i_crtc *scrtc = drm_crtc_to_sun4i_crtc(crtc);
DRM_DEBUG_DRIVER("Enabling VBLANK on crtc %p\n", crtc);
sun4i_tcon_enable_vblank(scrtc->tcon, true);
return 0;
}
static void sun4i_crtc_disable_vblank(struct drm_crtc *crtc)
{
struct sun4i_crtc *scrtc = drm_crtc_to_sun4i_crtc(crtc);
DRM_DEBUG_DRIVER("Disabling VBLANK on crtc %p\n", crtc);
sun4i_tcon_enable_vblank(scrtc->tcon, false);
}
struct sun4i_crtc *sun4i_crtc_init(struct drm_device *drm,
struct sunxi_engine *engine,
struct sun4i_tcon *tcon)
{
struct sun4i_crtc *scrtc;
struct drm_plane **planes;
struct drm_plane *primary = NULL, *cursor = NULL;
int ret, i;
scrtc = devm_kzalloc(drm->dev, sizeof(*scrtc), GFP_KERNEL);
if (!scrtc)
return ERR_PTR(-ENOMEM);
scrtc->engine = engine;
scrtc->tcon = tcon;
planes = sunxi_engine_layers_init(drm, engine);
if (IS_ERR(planes)) {
dev_err(drm->dev, "Couldn't create the planes\n");
return NULL;
}
for (i = 0; planes[i]; i++) {
struct drm_plane *plane = planes[i];
switch (plane->type) {
case DRM_PLANE_TYPE_PRIMARY:
primary = plane;
break;
case DRM_PLANE_TYPE_CURSOR:
cursor = plane;
break;
default:
break;
}
}
ret = drm_crtc_init_with_planes(drm, &scrtc->crtc,
primary,
cursor,
&sun4i_crtc_funcs,
NULL);
if (ret) {
dev_err(drm->dev, "Couldn't init DRM CRTC\n");
return ERR_PTR(ret);
}
drm_crtc_helper_add(&scrtc->crtc, &sun4i_crtc_helper_funcs);
scrtc->crtc.port = of_graph_get_port_by_id(scrtc->tcon->dev->of_node,
1);
for (i = 0; planes[i]; i++) {
uint32_t possible_crtcs = BIT(drm_crtc_index(&scrtc->crtc));
struct drm_plane *plane = planes[i];
if (plane->type == DRM_PLANE_TYPE_OVERLAY)
plane->possible_crtcs = possible_crtcs;
}
return scrtc;
}
