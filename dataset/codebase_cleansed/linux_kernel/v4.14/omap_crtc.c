struct videomode *omap_crtc_timings(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
return &omap_crtc->vm;
}
enum omap_channel omap_crtc_channel(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
return omap_crtc->channel;
}
static bool omap_crtc_is_pending(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
unsigned long flags;
bool pending;
spin_lock_irqsave(&crtc->dev->event_lock, flags);
pending = omap_crtc->pending;
spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
return pending;
}
int omap_crtc_wait_pending(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
return wait_event_timeout(omap_crtc->pending_wait,
!omap_crtc_is_pending(crtc),
msecs_to_jiffies(250));
}
static int omap_crtc_dss_connect(enum omap_channel channel,
struct omap_dss_device *dst)
{
const struct dispc_ops *dispc_ops = dispc_get_ops();
if (omap_crtc_output[channel])
return -EINVAL;
if ((dispc_ops->mgr_get_supported_outputs(channel) & dst->id) == 0)
return -EINVAL;
omap_crtc_output[channel] = dst;
dst->dispc_channel_connected = true;
return 0;
}
static void omap_crtc_dss_disconnect(enum omap_channel channel,
struct omap_dss_device *dst)
{
omap_crtc_output[channel] = NULL;
dst->dispc_channel_connected = false;
}
static void omap_crtc_dss_start_update(enum omap_channel channel)
{
}
static void omap_crtc_set_enabled(struct drm_crtc *crtc, bool enable)
{
struct drm_device *dev = crtc->dev;
struct omap_drm_private *priv = dev->dev_private;
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
enum omap_channel channel = omap_crtc->channel;
struct omap_irq_wait *wait;
u32 framedone_irq, vsync_irq;
int ret;
if (WARN_ON(omap_crtc->enabled == enable))
return;
if (omap_crtc_output[channel]->output_type == OMAP_DISPLAY_TYPE_HDMI) {
priv->dispc_ops->mgr_enable(channel, enable);
omap_crtc->enabled = enable;
return;
}
if (omap_crtc->channel == OMAP_DSS_CHANNEL_DIGIT) {
omap_crtc->ignore_digit_sync_lost = true;
}
framedone_irq = priv->dispc_ops->mgr_get_framedone_irq(channel);
vsync_irq = priv->dispc_ops->mgr_get_vsync_irq(channel);
if (enable) {
wait = omap_irq_wait_init(dev, vsync_irq, 1);
} else {
if (framedone_irq)
wait = omap_irq_wait_init(dev, framedone_irq, 1);
else
wait = omap_irq_wait_init(dev, vsync_irq, 2);
}
priv->dispc_ops->mgr_enable(channel, enable);
omap_crtc->enabled = enable;
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
static int omap_crtc_dss_enable(enum omap_channel channel)
{
struct omap_crtc *omap_crtc = omap_crtcs[channel];
struct omap_drm_private *priv = omap_crtc->base.dev->dev_private;
priv->dispc_ops->mgr_set_timings(omap_crtc->channel, &omap_crtc->vm);
omap_crtc_set_enabled(&omap_crtc->base, true);
return 0;
}
static void omap_crtc_dss_disable(enum omap_channel channel)
{
struct omap_crtc *omap_crtc = omap_crtcs[channel];
omap_crtc_set_enabled(&omap_crtc->base, false);
}
static void omap_crtc_dss_set_timings(enum omap_channel channel,
const struct videomode *vm)
{
struct omap_crtc *omap_crtc = omap_crtcs[channel];
DBG("%s", omap_crtc->name);
omap_crtc->vm = *vm;
}
static void omap_crtc_dss_set_lcd_config(enum omap_channel channel,
const struct dss_lcd_mgr_config *config)
{
struct omap_crtc *omap_crtc = omap_crtcs[channel];
struct omap_drm_private *priv = omap_crtc->base.dev->dev_private;
DBG("%s", omap_crtc->name);
priv->dispc_ops->mgr_set_lcd_config(omap_crtc->channel, config);
}
static int omap_crtc_dss_register_framedone(
enum omap_channel channel,
void (*handler)(void *), void *data)
{
return 0;
}
static void omap_crtc_dss_unregister_framedone(
enum omap_channel channel,
void (*handler)(void *), void *data)
{
}
void omap_crtc_error_irq(struct drm_crtc *crtc, uint32_t irqstatus)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
if (omap_crtc->ignore_digit_sync_lost) {
irqstatus &= ~DISPC_IRQ_SYNC_LOST_DIGIT;
if (!irqstatus)
return;
}
DRM_ERROR_RATELIMITED("%s: errors: %08x\n", omap_crtc->name, irqstatus);
}
void omap_crtc_vblank_irq(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
struct drm_device *dev = omap_crtc->base.dev;
struct omap_drm_private *priv = dev->dev_private;
bool pending;
spin_lock(&crtc->dev->event_lock);
if (priv->dispc_ops->mgr_go_busy(omap_crtc->channel)) {
spin_unlock(&crtc->dev->event_lock);
return;
}
if (omap_crtc->event) {
drm_crtc_send_vblank_event(crtc, omap_crtc->event);
omap_crtc->event = NULL;
}
pending = omap_crtc->pending;
omap_crtc->pending = false;
spin_unlock(&crtc->dev->event_lock);
if (pending)
drm_crtc_vblank_put(crtc);
wake_up(&omap_crtc->pending_wait);
DBG("%s: apply done", omap_crtc->name);
}
static void omap_crtc_write_crtc_properties(struct drm_crtc *crtc)
{
struct omap_drm_private *priv = crtc->dev->dev_private;
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
struct omap_overlay_manager_info info;
memset(&info, 0, sizeof(info));
info.default_color = 0x000000;
info.trans_enabled = false;
info.partial_alpha_enabled = false;
info.cpr_enable = false;
priv->dispc_ops->mgr_setup(omap_crtc->channel, &info);
}
static void omap_crtc_destroy(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
DBG("%s", omap_crtc->name);
drm_crtc_cleanup(crtc);
kfree(omap_crtc);
}
static void omap_crtc_arm_event(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
WARN_ON(omap_crtc->pending);
omap_crtc->pending = true;
if (crtc->state->event) {
omap_crtc->event = crtc->state->event;
crtc->state->event = NULL;
}
}
static void omap_crtc_atomic_enable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
int ret;
DBG("%s", omap_crtc->name);
spin_lock_irq(&crtc->dev->event_lock);
drm_crtc_vblank_on(crtc);
ret = drm_crtc_vblank_get(crtc);
WARN_ON(ret != 0);
omap_crtc_arm_event(crtc);
spin_unlock_irq(&crtc->dev->event_lock);
}
static void omap_crtc_atomic_disable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
DBG("%s", omap_crtc->name);
spin_lock_irq(&crtc->dev->event_lock);
if (crtc->state->event) {
drm_crtc_send_vblank_event(crtc, crtc->state->event);
crtc->state->event = NULL;
}
spin_unlock_irq(&crtc->dev->event_lock);
drm_crtc_vblank_off(crtc);
}
static void omap_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
struct drm_display_mode *mode = &crtc->state->adjusted_mode;
struct omap_drm_private *priv = crtc->dev->dev_private;
const u32 flags_mask = DISPLAY_FLAGS_DE_HIGH | DISPLAY_FLAGS_DE_LOW |
DISPLAY_FLAGS_PIXDATA_POSEDGE | DISPLAY_FLAGS_PIXDATA_NEGEDGE |
DISPLAY_FLAGS_SYNC_POSEDGE | DISPLAY_FLAGS_SYNC_NEGEDGE;
unsigned int i;
DBG("%s: set mode: %d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x",
omap_crtc->name, mode->base.id, mode->name,
mode->vrefresh, mode->clock,
mode->hdisplay, mode->hsync_start, mode->hsync_end, mode->htotal,
mode->vdisplay, mode->vsync_start, mode->vsync_end, mode->vtotal,
mode->type, mode->flags);
drm_display_mode_to_videomode(mode, &omap_crtc->vm);
for (i = 0; i < priv->num_encoders; ++i) {
struct drm_encoder *encoder = priv->encoders[i];
if (encoder->crtc == crtc) {
struct omap_dss_device *dssdev;
dssdev = omap_encoder_get_dssdev(encoder);
if (dssdev) {
struct videomode vm = {0};
dssdev->driver->get_timings(dssdev, &vm);
omap_crtc->vm.flags |= vm.flags & flags_mask;
}
break;
}
}
}
static int omap_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct drm_plane_state *pri_state;
if (state->color_mgmt_changed && state->gamma_lut) {
uint length = state->gamma_lut->length /
sizeof(struct drm_color_lut);
if (length < 2)
return -EINVAL;
}
pri_state = drm_atomic_get_new_plane_state(state->state, crtc->primary);
if (pri_state) {
struct omap_crtc_state *omap_crtc_state =
to_omap_crtc_state(state);
omap_crtc_state->zpos = pri_state->zpos;
omap_crtc_state->rotation = pri_state->rotation;
}
return 0;
}
static void omap_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
}
static void omap_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct omap_drm_private *priv = crtc->dev->dev_private;
struct omap_crtc *omap_crtc = to_omap_crtc(crtc);
int ret;
if (crtc->state->color_mgmt_changed) {
struct drm_color_lut *lut = NULL;
uint length = 0;
if (crtc->state->gamma_lut) {
lut = (struct drm_color_lut *)
crtc->state->gamma_lut->data;
length = crtc->state->gamma_lut->length /
sizeof(*lut);
}
priv->dispc_ops->mgr_set_gamma(omap_crtc->channel, lut, length);
}
omap_crtc_write_crtc_properties(crtc);
if (!omap_crtc->enabled)
return;
DBG("%s: GO", omap_crtc->name);
ret = drm_crtc_vblank_get(crtc);
WARN_ON(ret != 0);
spin_lock_irq(&crtc->dev->event_lock);
priv->dispc_ops->mgr_go(omap_crtc->channel);
omap_crtc_arm_event(crtc);
spin_unlock_irq(&crtc->dev->event_lock);
}
static int omap_crtc_atomic_set_property(struct drm_crtc *crtc,
struct drm_crtc_state *state,
struct drm_property *property,
uint64_t val)
{
struct omap_drm_private *priv = crtc->dev->dev_private;
struct drm_plane_state *plane_state;
plane_state = drm_atomic_get_plane_state(state->state, crtc->primary);
if (IS_ERR(plane_state))
return PTR_ERR(plane_state);
if (property == crtc->primary->rotation_property)
plane_state->rotation = val;
else if (property == priv->zorder_prop)
plane_state->zpos = val;
else
return -EINVAL;
return 0;
}
static int omap_crtc_atomic_get_property(struct drm_crtc *crtc,
const struct drm_crtc_state *state,
struct drm_property *property,
uint64_t *val)
{
struct omap_drm_private *priv = crtc->dev->dev_private;
struct omap_crtc_state *omap_state = to_omap_crtc_state(state);
if (property == crtc->primary->rotation_property)
*val = omap_state->rotation;
else if (property == priv->zorder_prop)
*val = omap_state->zpos;
else
return -EINVAL;
return 0;
}
static void omap_crtc_reset(struct drm_crtc *crtc)
{
if (crtc->state)
__drm_atomic_helper_crtc_destroy_state(crtc->state);
kfree(crtc->state);
crtc->state = kzalloc(sizeof(struct omap_crtc_state), GFP_KERNEL);
if (crtc->state)
crtc->state->crtc = crtc;
}
static struct drm_crtc_state *
omap_crtc_duplicate_state(struct drm_crtc *crtc)
{
struct omap_crtc_state *state, *current_state;
if (WARN_ON(!crtc->state))
return NULL;
current_state = to_omap_crtc_state(crtc->state);
state = kmalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
__drm_atomic_helper_crtc_duplicate_state(crtc, &state->base);
state->zpos = current_state->zpos;
state->rotation = current_state->rotation;
return &state->base;
}
void omap_crtc_pre_init(void)
{
memset(omap_crtcs, 0, sizeof(omap_crtcs));
dss_install_mgr_ops(&mgr_ops);
}
void omap_crtc_pre_uninit(void)
{
dss_uninstall_mgr_ops();
}
struct drm_crtc *omap_crtc_init(struct drm_device *dev,
struct drm_plane *plane, struct omap_dss_device *dssdev)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_crtc *crtc = NULL;
struct omap_crtc *omap_crtc;
enum omap_channel channel;
struct omap_dss_device *out;
int ret;
out = omapdss_find_output_from_display(dssdev);
channel = out->dispc_channel;
omap_dss_put_device(out);
DBG("%s", channel_names[channel]);
if (WARN_ON(omap_crtcs[channel] != NULL))
return ERR_PTR(-EINVAL);
omap_crtc = kzalloc(sizeof(*omap_crtc), GFP_KERNEL);
if (!omap_crtc)
return ERR_PTR(-ENOMEM);
crtc = &omap_crtc->base;
init_waitqueue_head(&omap_crtc->pending_wait);
omap_crtc->channel = channel;
omap_crtc->name = channel_names[channel];
ret = drm_crtc_init_with_planes(dev, crtc, plane, NULL,
&omap_crtc_funcs, NULL);
if (ret < 0) {
dev_err(dev->dev, "%s(): could not init crtc for: %s\n",
__func__, dssdev->name);
kfree(omap_crtc);
return ERR_PTR(ret);
}
drm_crtc_helper_add(crtc, &omap_crtc_helper_funcs);
if (priv->dispc_ops->mgr_gamma_size(channel)) {
uint gamma_lut_size = 256;
drm_crtc_enable_color_mgmt(crtc, 0, false, gamma_lut_size);
drm_mode_crtc_set_gamma_size(crtc, gamma_lut_size);
}
omap_plane_install_properties(crtc->primary, &crtc->base);
omap_crtcs[channel] = omap_crtc;
return crtc;
}
