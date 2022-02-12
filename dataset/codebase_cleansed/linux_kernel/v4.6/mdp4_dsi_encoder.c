static struct mdp4_kms *get_kms(struct drm_encoder *encoder)
{
struct msm_drm_private *priv = encoder->dev->dev_private;
return to_mdp4_kms(to_mdp_kms(priv->kms));
}
static void mdp4_dsi_encoder_destroy(struct drm_encoder *encoder)
{
struct mdp4_dsi_encoder *mdp4_dsi_encoder = to_mdp4_dsi_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(mdp4_dsi_encoder);
}
static void mdp4_dsi_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct mdp4_kms *mdp4_kms = get_kms(encoder);
uint32_t dsi_hsync_skew, vsync_period, vsync_len, ctrl_pol;
uint32_t display_v_start, display_v_end;
uint32_t hsync_start_x, hsync_end_x;
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
if (mode->flags & DRM_MODE_FLAG_NHSYNC)
ctrl_pol |= MDP4_DSI_CTRL_POLARITY_HSYNC_LOW;
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
ctrl_pol |= MDP4_DSI_CTRL_POLARITY_VSYNC_LOW;
dsi_hsync_skew = 0;
hsync_start_x = (mode->htotal - mode->hsync_start);
hsync_end_x = mode->htotal - (mode->hsync_start - mode->hdisplay) - 1;
vsync_period = mode->vtotal * mode->htotal;
vsync_len = (mode->vsync_end - mode->vsync_start) * mode->htotal;
display_v_start = (mode->vtotal - mode->vsync_start) * mode->htotal + dsi_hsync_skew;
display_v_end = vsync_period - ((mode->vsync_start - mode->vdisplay) * mode->htotal) + dsi_hsync_skew - 1;
mdp4_write(mdp4_kms, REG_MDP4_DSI_HSYNC_CTRL,
MDP4_DSI_HSYNC_CTRL_PULSEW(mode->hsync_end - mode->hsync_start) |
MDP4_DSI_HSYNC_CTRL_PERIOD(mode->htotal));
mdp4_write(mdp4_kms, REG_MDP4_DSI_VSYNC_PERIOD, vsync_period);
mdp4_write(mdp4_kms, REG_MDP4_DSI_VSYNC_LEN, vsync_len);
mdp4_write(mdp4_kms, REG_MDP4_DSI_DISPLAY_HCTRL,
MDP4_DSI_DISPLAY_HCTRL_START(hsync_start_x) |
MDP4_DSI_DISPLAY_HCTRL_END(hsync_end_x));
mdp4_write(mdp4_kms, REG_MDP4_DSI_DISPLAY_VSTART, display_v_start);
mdp4_write(mdp4_kms, REG_MDP4_DSI_DISPLAY_VEND, display_v_end);
mdp4_write(mdp4_kms, REG_MDP4_DSI_CTRL_POLARITY, ctrl_pol);
mdp4_write(mdp4_kms, REG_MDP4_DSI_UNDERFLOW_CLR,
MDP4_DSI_UNDERFLOW_CLR_ENABLE_RECOVERY |
MDP4_DSI_UNDERFLOW_CLR_COLOR(0xff));
mdp4_write(mdp4_kms, REG_MDP4_DSI_ACTIVE_HCTL,
MDP4_DSI_ACTIVE_HCTL_START(0) |
MDP4_DSI_ACTIVE_HCTL_END(0));
mdp4_write(mdp4_kms, REG_MDP4_DSI_HSYNC_SKEW, dsi_hsync_skew);
mdp4_write(mdp4_kms, REG_MDP4_DSI_BORDER_CLR, 0);
mdp4_write(mdp4_kms, REG_MDP4_DSI_ACTIVE_VSTART, 0);
mdp4_write(mdp4_kms, REG_MDP4_DSI_ACTIVE_VEND, 0);
}
static void mdp4_dsi_encoder_disable(struct drm_encoder *encoder)
{
struct mdp4_dsi_encoder *mdp4_dsi_encoder = to_mdp4_dsi_encoder(encoder);
struct mdp4_kms *mdp4_kms = get_kms(encoder);
if (!mdp4_dsi_encoder->enabled)
return;
mdp4_write(mdp4_kms, REG_MDP4_DSI_ENABLE, 0);
mdp_irq_wait(&mdp4_kms->base, MDP4_IRQ_PRIMARY_VSYNC);
mdp4_dsi_encoder->enabled = false;
}
static void mdp4_dsi_encoder_enable(struct drm_encoder *encoder)
{
struct mdp4_dsi_encoder *mdp4_dsi_encoder = to_mdp4_dsi_encoder(encoder);
struct mdp4_kms *mdp4_kms = get_kms(encoder);
if (mdp4_dsi_encoder->enabled)
return;
mdp4_crtc_set_config(encoder->crtc,
MDP4_DMA_CONFIG_PACK_ALIGN_MSB |
MDP4_DMA_CONFIG_DEFLKR_EN |
MDP4_DMA_CONFIG_DITHER_EN |
MDP4_DMA_CONFIG_R_BPC(BPC8) |
MDP4_DMA_CONFIG_G_BPC(BPC8) |
MDP4_DMA_CONFIG_B_BPC(BPC8) |
MDP4_DMA_CONFIG_PACK(0x21));
mdp4_crtc_set_intf(encoder->crtc, INTF_DSI_VIDEO, 0);
mdp4_write(mdp4_kms, REG_MDP4_DSI_ENABLE, 1);
mdp4_dsi_encoder->enabled = true;
}
struct drm_encoder *mdp4_dsi_encoder_init(struct drm_device *dev)
{
struct drm_encoder *encoder = NULL;
struct mdp4_dsi_encoder *mdp4_dsi_encoder;
int ret;
mdp4_dsi_encoder = kzalloc(sizeof(*mdp4_dsi_encoder), GFP_KERNEL);
if (!mdp4_dsi_encoder) {
ret = -ENOMEM;
goto fail;
}
encoder = &mdp4_dsi_encoder->base;
drm_encoder_init(dev, encoder, &mdp4_dsi_encoder_funcs,
DRM_MODE_ENCODER_DSI, NULL);
drm_encoder_helper_add(encoder, &mdp4_dsi_encoder_helper_funcs);
return encoder;
fail:
if (encoder)
mdp4_dsi_encoder_destroy(encoder);
return ERR_PTR(ret);
}
