static struct mdp5_kms *get_kms(struct drm_encoder *encoder)
{
struct msm_drm_private *priv = encoder->dev->dev_private;
return to_mdp5_kms(to_mdp_kms(priv->kms));
}
static void bs_init(struct mdp5_encoder *mdp5_encoder)
{
mdp5_encoder->bsc = msm_bus_scale_register_client(
&mdp_bus_scale_table);
DBG("bus scale client: %08x", mdp5_encoder->bsc);
}
static void bs_fini(struct mdp5_encoder *mdp5_encoder)
{
if (mdp5_encoder->bsc) {
msm_bus_scale_unregister_client(mdp5_encoder->bsc);
mdp5_encoder->bsc = 0;
}
}
static void bs_set(struct mdp5_encoder *mdp5_encoder, int idx)
{
if (mdp5_encoder->bsc) {
DBG("set bus scaling: %d", idx);
idx = 1;
msm_bus_scale_client_update_request(mdp5_encoder->bsc, idx);
}
}
static void bs_init(struct mdp5_encoder *mdp5_encoder) {}
static void bs_fini(struct mdp5_encoder *mdp5_encoder) {}
static void bs_set(struct mdp5_encoder *mdp5_encoder, int idx) {}
static void mdp5_encoder_destroy(struct drm_encoder *encoder)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
bs_fini(mdp5_encoder);
drm_encoder_cleanup(encoder);
kfree(mdp5_encoder);
}
static void mdp5_vid_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_kms *mdp5_kms = get_kms(encoder);
struct drm_device *dev = encoder->dev;
struct drm_connector *connector;
int intf = mdp5_encoder->intf->num;
uint32_t dtv_hsync_skew, vsync_period, vsync_len, ctrl_pol;
uint32_t display_v_start, display_v_end;
uint32_t hsync_start_x, hsync_end_x;
uint32_t format = 0x2100;
unsigned long flags;
mode = adjusted_mode;
DBG("set mode: %d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x",
mode->base.id, mode->name,
mode->vrefresh, mode->clock,
mode->hdisplay, mode->hsync_start,
mode->hsync_end, mode->htotal,
mode->vdisplay, mode->vsync_start,
mode->vsync_end, mode->vtotal,
mode->type, mode->flags);
ctrl_pol = 0;
if (mdp5_encoder->intf->type != INTF_DSI) {
if (mode->flags & DRM_MODE_FLAG_NHSYNC)
ctrl_pol |= MDP5_INTF_POLARITY_CTL_HSYNC_LOW;
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
ctrl_pol |= MDP5_INTF_POLARITY_CTL_VSYNC_LOW;
}
dtv_hsync_skew = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->encoder == encoder) {
switch (connector->display_info.bpc) {
case 4:
format |= 0;
break;
case 5:
format |= 0x15;
break;
case 6:
format |= 0x2A;
break;
case 8:
default:
format |= 0x3F;
break;
}
break;
}
}
hsync_start_x = (mode->htotal - mode->hsync_start);
hsync_end_x = mode->htotal - (mode->hsync_start - mode->hdisplay) - 1;
vsync_period = mode->vtotal * mode->htotal;
vsync_len = (mode->vsync_end - mode->vsync_start) * mode->htotal;
display_v_start = (mode->vtotal - mode->vsync_start) * mode->htotal + dtv_hsync_skew;
display_v_end = vsync_period - ((mode->vsync_start - mode->vdisplay) * mode->htotal) + dtv_hsync_skew - 1;
if (mdp5_encoder->intf->type == INTF_eDP) {
display_v_start += mode->htotal - mode->hsync_start;
display_v_end -= mode->hsync_start - mode->hdisplay;
}
spin_lock_irqsave(&mdp5_encoder->intf_lock, flags);
mdp5_write(mdp5_kms, REG_MDP5_INTF_HSYNC_CTL(intf),
MDP5_INTF_HSYNC_CTL_PULSEW(mode->hsync_end - mode->hsync_start) |
MDP5_INTF_HSYNC_CTL_PERIOD(mode->htotal));
mdp5_write(mdp5_kms, REG_MDP5_INTF_VSYNC_PERIOD_F0(intf), vsync_period);
mdp5_write(mdp5_kms, REG_MDP5_INTF_VSYNC_LEN_F0(intf), vsync_len);
mdp5_write(mdp5_kms, REG_MDP5_INTF_DISPLAY_HCTL(intf),
MDP5_INTF_DISPLAY_HCTL_START(hsync_start_x) |
MDP5_INTF_DISPLAY_HCTL_END(hsync_end_x));
mdp5_write(mdp5_kms, REG_MDP5_INTF_DISPLAY_VSTART_F0(intf), display_v_start);
mdp5_write(mdp5_kms, REG_MDP5_INTF_DISPLAY_VEND_F0(intf), display_v_end);
mdp5_write(mdp5_kms, REG_MDP5_INTF_BORDER_COLOR(intf), 0);
mdp5_write(mdp5_kms, REG_MDP5_INTF_UNDERFLOW_COLOR(intf), 0xff);
mdp5_write(mdp5_kms, REG_MDP5_INTF_HSYNC_SKEW(intf), dtv_hsync_skew);
mdp5_write(mdp5_kms, REG_MDP5_INTF_POLARITY_CTL(intf), ctrl_pol);
mdp5_write(mdp5_kms, REG_MDP5_INTF_ACTIVE_HCTL(intf),
MDP5_INTF_ACTIVE_HCTL_START(0) |
MDP5_INTF_ACTIVE_HCTL_END(0));
mdp5_write(mdp5_kms, REG_MDP5_INTF_ACTIVE_VSTART_F0(intf), 0);
mdp5_write(mdp5_kms, REG_MDP5_INTF_ACTIVE_VEND_F0(intf), 0);
mdp5_write(mdp5_kms, REG_MDP5_INTF_PANEL_FORMAT(intf), format);
mdp5_write(mdp5_kms, REG_MDP5_INTF_FRAME_LINE_COUNT_EN(intf), 0x3);
spin_unlock_irqrestore(&mdp5_encoder->intf_lock, flags);
mdp5_crtc_set_pipeline(encoder->crtc);
}
static void mdp5_vid_encoder_disable(struct drm_encoder *encoder)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_kms *mdp5_kms = get_kms(encoder);
struct mdp5_ctl *ctl = mdp5_encoder->ctl;
struct mdp5_pipeline *pipeline = mdp5_crtc_get_pipeline(encoder->crtc);
struct mdp5_hw_mixer *mixer = mdp5_crtc_get_mixer(encoder->crtc);
struct mdp5_interface *intf = mdp5_encoder->intf;
int intfn = mdp5_encoder->intf->num;
unsigned long flags;
if (WARN_ON(!mdp5_encoder->enabled))
return;
mdp5_ctl_set_encoder_state(ctl, pipeline, false);
spin_lock_irqsave(&mdp5_encoder->intf_lock, flags);
mdp5_write(mdp5_kms, REG_MDP5_INTF_TIMING_ENGINE_EN(intfn), 0);
spin_unlock_irqrestore(&mdp5_encoder->intf_lock, flags);
mdp5_ctl_commit(ctl, pipeline, mdp_ctl_flush_mask_encoder(intf));
mdp_irq_wait(&mdp5_kms->base, intf2vblank(mixer, intf));
bs_set(mdp5_encoder, 0);
mdp5_encoder->enabled = false;
}
static void mdp5_vid_encoder_enable(struct drm_encoder *encoder)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_kms *mdp5_kms = get_kms(encoder);
struct mdp5_ctl *ctl = mdp5_encoder->ctl;
struct mdp5_interface *intf = mdp5_encoder->intf;
struct mdp5_pipeline *pipeline = mdp5_crtc_get_pipeline(encoder->crtc);
int intfn = intf->num;
unsigned long flags;
if (WARN_ON(mdp5_encoder->enabled))
return;
bs_set(mdp5_encoder, 1);
spin_lock_irqsave(&mdp5_encoder->intf_lock, flags);
mdp5_write(mdp5_kms, REG_MDP5_INTF_TIMING_ENGINE_EN(intfn), 1);
spin_unlock_irqrestore(&mdp5_encoder->intf_lock, flags);
mdp5_ctl_commit(ctl, pipeline, mdp_ctl_flush_mask_encoder(intf));
mdp5_ctl_set_encoder_state(ctl, pipeline, true);
mdp5_encoder->enabled = true;
}
static void mdp5_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_interface *intf = mdp5_encoder->intf;
if (intf->mode == MDP5_INTF_DSI_MODE_COMMAND)
mdp5_cmd_encoder_mode_set(encoder, mode, adjusted_mode);
else
mdp5_vid_encoder_mode_set(encoder, mode, adjusted_mode);
}
static void mdp5_encoder_disable(struct drm_encoder *encoder)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_interface *intf = mdp5_encoder->intf;
if (intf->mode == MDP5_INTF_DSI_MODE_COMMAND)
mdp5_cmd_encoder_disable(encoder);
else
mdp5_vid_encoder_disable(encoder);
}
static void mdp5_encoder_enable(struct drm_encoder *encoder)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_interface *intf = mdp5_encoder->intf;
struct drm_crtc_state *cstate = encoder->crtc->state;
mdp5_encoder_mode_set(encoder, &cstate->mode, &cstate->adjusted_mode);
if (intf->mode == MDP5_INTF_DSI_MODE_COMMAND)
mdp5_cmd_encoder_enable(encoder);
else
mdp5_vid_encoder_enable(encoder);
}
static int mdp5_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_crtc_state *mdp5_cstate = to_mdp5_crtc_state(crtc_state);
struct mdp5_interface *intf = mdp5_encoder->intf;
struct mdp5_ctl *ctl = mdp5_encoder->ctl;
mdp5_cstate->ctl = ctl;
mdp5_cstate->pipeline.intf = intf;
return 0;
}
int mdp5_encoder_get_linecount(struct drm_encoder *encoder)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_kms *mdp5_kms = get_kms(encoder);
int intf = mdp5_encoder->intf->num;
return mdp5_read(mdp5_kms, REG_MDP5_INTF_LINE_COUNT(intf));
}
u32 mdp5_encoder_get_framecount(struct drm_encoder *encoder)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_kms *mdp5_kms = get_kms(encoder);
int intf = mdp5_encoder->intf->num;
return mdp5_read(mdp5_kms, REG_MDP5_INTF_FRAME_COUNT(intf));
}
int mdp5_vid_encoder_set_split_display(struct drm_encoder *encoder,
struct drm_encoder *slave_encoder)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_encoder *mdp5_slave_enc = to_mdp5_encoder(slave_encoder);
struct mdp5_kms *mdp5_kms;
struct device *dev;
int intf_num;
u32 data = 0;
if (!encoder || !slave_encoder)
return -EINVAL;
mdp5_kms = get_kms(encoder);
intf_num = mdp5_encoder->intf->num;
if (intf_num == 1)
data |= MDP5_SPLIT_DPL_LOWER_INTF2_TG_SYNC;
else if (intf_num == 2)
data |= MDP5_SPLIT_DPL_LOWER_INTF1_TG_SYNC;
else
return -EINVAL;
dev = &mdp5_kms->pdev->dev;
pm_runtime_get_sync(dev);
mdp5_write(mdp5_kms, REG_MDP5_SPLIT_DPL_UPPER, 0);
mdp5_write(mdp5_kms, REG_MDP5_SPLIT_DPL_LOWER, data);
mdp5_write(mdp5_kms, REG_MDP5_SPLIT_DPL_EN, 1);
mdp5_ctl_pair(mdp5_encoder->ctl, mdp5_slave_enc->ctl, true);
pm_runtime_put_autosuspend(dev);
return 0;
}
void mdp5_encoder_set_intf_mode(struct drm_encoder *encoder, bool cmd_mode)
{
struct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);
struct mdp5_interface *intf = mdp5_encoder->intf;
if (cmd_mode) {
WARN_ON(intf->type != INTF_DSI);
intf->mode = MDP5_INTF_DSI_MODE_COMMAND;
} else {
if (intf->type == INTF_DSI)
intf->mode = MDP5_INTF_DSI_MODE_VIDEO;
else
intf->mode = MDP5_INTF_MODE_NONE;
}
}
struct drm_encoder *mdp5_encoder_init(struct drm_device *dev,
struct mdp5_interface *intf,
struct mdp5_ctl *ctl)
{
struct drm_encoder *encoder = NULL;
struct mdp5_encoder *mdp5_encoder;
int enc_type = (intf->type == INTF_DSI) ?
DRM_MODE_ENCODER_DSI : DRM_MODE_ENCODER_TMDS;
int ret;
mdp5_encoder = kzalloc(sizeof(*mdp5_encoder), GFP_KERNEL);
if (!mdp5_encoder) {
ret = -ENOMEM;
goto fail;
}
encoder = &mdp5_encoder->base;
mdp5_encoder->ctl = ctl;
mdp5_encoder->intf = intf;
spin_lock_init(&mdp5_encoder->intf_lock);
drm_encoder_init(dev, encoder, &mdp5_encoder_funcs, enc_type, NULL);
drm_encoder_helper_add(encoder, &mdp5_encoder_helper_funcs);
bs_init(mdp5_encoder);
return encoder;
fail:
if (encoder)
mdp5_encoder_destroy(encoder);
return ERR_PTR(ret);
}
