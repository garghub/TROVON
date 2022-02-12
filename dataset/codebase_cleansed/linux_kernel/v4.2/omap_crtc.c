uint32_t pipe2vbl(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
return dispc_mgr_get_vsync_irq(omap_crtc->channel);
}
struct omap_video_timings *omap_crtc_timings(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
return &omap_crtc->timings;
}
enum omap_channel omap_crtc_channel(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
return omap_crtc->channel;
}
int omap_crtc_wait_pending(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
return wait_event_timeout(omap_crtc->pending_wait,
!omap_crtc->pending,
msecs_to_jiffies(50));
}
static int omap_crtc_dss_connect(struct omap_overlay_manager *mgr,
struct omap_dss_device *dst)
{
if (mgr->output)
return -EINVAL;
if ((mgr->supported_outputs & dst->id) == 0)
return -EINVAL;
dst->manager = mgr;
mgr->output = dst;
return 0;
}
static void omap_crtc_dss_disconnect(struct omap_overlay_manager *mgr,
struct omap_dss_device *dst)
{
mgr->output->manager = NULL;
mgr->output = NULL;
}
static void omap_crtc_dss_start_update(struct omap_overlay_manager *mgr)
{
}
static void omap_crtc_set_enabled(struct drm_crtc *crtc, bool enable)
{
struct drm_device *dev = crtc->dev;
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
enum omap_channel channel = omap_crtc->channel;
struct omap_irq_wait *wait;
u32 framedone_irq, vsync_irq;
int ret;
if (dispc_mgr_is_enabled(channel) == enable)
return;
if (omap_crtc->channel == OMAP_DSS_CHANNEL_DIGIT) {
omap_crtc->ignore_digit_sync_lost = true;
}
framedone_irq = dispc_mgr_get_framedone_irq(channel);
vsync_irq = dispc_mgr_get_vsync_irq(channel);
if (enable) {
wait = omap_irq_wait_init(dev, vsync_irq, 1);
} else {
if (framedone_irq)
wait = omap_irq_wait_init(dev, framedone_irq, 1);
else
wait = omap_irq_wait_init(dev, vsync_irq, 2);
}
dispc_mgr_enable(channel, enable);
ret = omap_irq_wait(dev, wait, msecs_to_jiffies(100));
if (ret) {
dev_err(dev->dev, "%s: timeout waiting for %s\n",
omap_crtc->name, enable ? "enable" : "disable");
}
if (omap_crtc->channel == OMAP_DSS_CHANNEL_DIGIT) {
omap_crtc->ignore_digit_sync_lost = false;
mb();
}
}
static int omap_crtc_dss_enable(struct omap_overlay_manager *mgr)
{
struct omap_crtc *omap_crtc = omap_crtcs[mgr->id];
struct omap_overlay_manager_info info;
memset(&info, 0, sizeof(info));
info.default_color = 0x00000000;
info.trans_key = 0x00000000;
info.trans_key_type = OMAP_DSS_COLOR_KEY_GFX_DST;
info.trans_enabled = false;
dispc_mgr_setup(omap_crtc->channel, &info);
dispc_mgr_set_timings(omap_crtc->channel,
&omap_crtc->timings);
omap_crtc_set_enabled(&omap_crtc->base, true);
return 0;
}
static void omap_crtc_dss_disable(struct omap_overlay_manager *mgr)
{
struct omap_crtc *omap_crtc = omap_crtcs[mgr->id];
omap_crtc_set_enabled(&omap_crtc->base, false);
}
static void omap_crtc_dss_set_timings(struct omap_overlay_manager *mgr,
const struct omap_video_timings *timings)
{
struct omap_crtc *omap_crtc = omap_crtcs[mgr->id];
DBG("%s", omap_crtc->name);
omap_crtc->timings = *timings;
}
static void omap_crtc_dss_set_lcd_config(struct omap_overlay_manager *mgr,
const struct dss_lcd_mgr_config *config)
{
struct omap_crtc *omap_crtc = omap_crtcs[mgr->id];
DBG("%s", omap_crtc->name);
dispc_mgr_set_lcd_config(omap_crtc->channel, config);
}
static int omap_crtc_dss_register_framedone(
struct omap_overlay_manager *mgr,
void (*handler)(void *), void *data)
{
return 0;
}
static void omap_crtc_dss_unregister_framedone(
struct omap_overlay_manager *mgr,
void (*handler)(void *), void *data)
{
}
static void omap_crtc_complete_page_flip(struct drm_crtc *crtc)
{
struct drm_pending_vblank_event *event;
struct drm_device *dev = crtc->dev;
unsigned long flags;
event = crtc->state->event;
if (!event)
return;
spin_lock_irqsave(&dev->event_lock, flags);
list_del(&event->base.link);
if (event->base.file_priv)
drm_crtc_send_vblank_event(crtc, event);
else
event->base.destroy(&event->base);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static void omap_crtc_error_irq(struct omap_drm_irq *irq, uint32_t irqstatus)
{
struct omap_crtc *omap_crtc =
container_of(irq, struct omap_crtc, error_irq);
if (omap_crtc->ignore_digit_sync_lost) {
irqstatus &= ~DISPC_IRQ_SYNC_LOST_DIGIT;
if (!irqstatus)
return;
}
DRM_ERROR_RATELIMITED("%s: errors: %08x\n", omap_crtc->name, irqstatus);
}
static void omap_crtc_vblank_irq(struct omap_drm_irq *irq, uint32_t irqstatus)
{
struct omap_crtc *omap_crtc =
container_of(irq, struct omap_crtc, vblank_irq);
struct drm_device *dev = omap_crtc->base.dev;
if (dispc_mgr_go_busy(omap_crtc->channel))
return;
DBG("%s: apply done", omap_crtc->name);
__omap_irq_unregister(dev, &omap_crtc->vblank_irq);
rmb();
WARN_ON(!omap_crtc->pending);
omap_crtc->pending = false;
wmb();
omap_crtc_complete_page_flip(&omap_crtc->base);
wake_up(&omap_crtc->pending_wait);
}
static void omap_crtc_destroy(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
DBG("%s", omap_crtc->name);
WARN_ON(omap_crtc->vblank_irq.registered);
omap_irq_unregister(crtc->dev, &omap_crtc->error_irq);
drm_crtc_cleanup(crtc);
kfree(omap_crtc);
}
static bool omap_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void omap_crtc_enable(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
DBG("%s", omap_crtc->name);
rmb();
WARN_ON(omap_crtc->pending);
omap_crtc->pending = true;
wmb();
omap_irq_register(crtc->dev, &omap_crtc->vblank_irq);
drm_crtc_vblank_on(crtc);
}
static void omap_crtc_disable(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
DBG("%s", omap_crtc->name);
drm_crtc_vblank_off(crtc);
}
static void omap_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
struct drm_display_mode *mode = &crtc->state->adjusted_mode;
DBG("%s: set mode: %d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x",
omap_crtc->name, mode->base.id, mode->name,
mode->vrefresh, mode->clock,
mode->hdisplay, mode->hsync_start, mode->hsync_end, mode->htotal,
mode->vdisplay, mode->vsync_start, mode->vsync_end, mode->vtotal,
mode->type, mode->flags);
copy_timings_drm_to_omap(&omap_crtc->timings, mode);
}
static void omap_crtc_atomic_begin(struct drm_crtc *crtc)
{
}
static void omap_crtc_atomic_flush(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
WARN_ON(omap_crtc->vblank_irq.registered);
if (dispc_mgr_is_enabled(omap_crtc->channel)) {
DBG("%s: GO", omap_crtc->name);
rmb();
WARN_ON(omap_crtc->pending);
omap_crtc->pending = true;
wmb();
dispc_mgr_go(omap_crtc->channel);
omap_irq_register(crtc->dev, &omap_crtc->vblank_irq);
}
crtc->invert_dimensions = !!(crtc->primary->state->rotation &
(BIT(DRM_ROTATE_90) | BIT(DRM_ROTATE_270)));
}
static int omap_crtc_atomic_set_property(struct drm_crtc *crtc,
struct drm_crtc_state *state,
struct drm_property *property,
uint64_t val)
{
struct drm_plane_state *plane_state;
struct drm_plane *plane = crtc->primary;
plane_state = drm_atomic_get_plane_state(state->state, plane);
if (!plane_state)
return -EINVAL;
return drm_atomic_plane_set_property(plane, plane_state, property, val);
}
static int omap_crtc_atomic_get_property(struct drm_crtc *crtc,
const struct drm_crtc_state *state,
struct drm_property *property,
uint64_t *val)
{
return drm_object_property_get_value(&crtc->primary->base, property,
val);
}
void omap_crtc_pre_init(void)
{
dss_install_mgr_ops(&mgr_ops);
}
void omap_crtc_pre_uninit(void)
{
dss_uninstall_mgr_ops();
}
struct drm_crtc *omap_crtc_init(struct drm_device *dev,
struct drm_plane *plane, enum omap_channel channel, int id)
{
struct drm_crtc *crtc = NULL;
struct omap_crtc *omap_crtc;
int ret;
DBG("%s", channel_names[channel]);
omap_crtc = kzalloc(sizeof(*omap_crtc), GFP_KERNEL);
if (!omap_crtc)
return NULL;
crtc = &omap_crtc->base;
init_waitqueue_head(&omap_crtc->pending_wait);
omap_crtc->channel = channel;
omap_crtc->name = channel_names[channel];
omap_crtc->vblank_irq.irqmask = pipe2vbl(crtc);
omap_crtc->vblank_irq.irq = omap_crtc_vblank_irq;
omap_crtc->error_irq.irqmask =
dispc_mgr_get_sync_lost_irq(channel);
omap_crtc->error_irq.irq = omap_crtc_error_irq;
omap_irq_register(dev, &omap_crtc->error_irq);
omap_crtc->mgr = omap_dss_get_overlay_manager(channel);
ret = drm_crtc_init_with_planes(dev, crtc, plane, NULL,
&omap_crtc_funcs);
if (ret < 0) {
kfree(omap_crtc);
return NULL;
}
drm_crtc_helper_add(crtc, &omap_crtc_helper_funcs);
omap_plane_install_properties(crtc->primary, &crtc->base);
omap_crtcs[channel] = omap_crtc;
return crtc;
}
