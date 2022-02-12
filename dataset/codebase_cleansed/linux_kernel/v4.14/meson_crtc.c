static int meson_crtc_enable_vblank(struct drm_crtc *crtc)
{
struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
struct meson_drm *priv = meson_crtc->priv;
meson_venc_enable_vsync(priv);
return 0;
}
static void meson_crtc_disable_vblank(struct drm_crtc *crtc)
{
struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
struct meson_drm *priv = meson_crtc->priv;
meson_venc_disable_vsync(priv);
}
static void meson_crtc_atomic_enable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
struct drm_crtc_state *crtc_state = crtc->state;
struct meson_drm *priv = meson_crtc->priv;
DRM_DEBUG_DRIVER("\n");
if (!crtc_state) {
DRM_ERROR("Invalid crtc_state\n");
return;
}
writel(crtc_state->mode.hdisplay,
priv->io_base + _REG(VPP_POSTBLEND_H_SIZE));
writel_bits_relaxed(VPP_POSTBLEND_ENABLE, VPP_POSTBLEND_ENABLE,
priv->io_base + _REG(VPP_MISC));
priv->viu.osd1_enabled = true;
}
static void meson_crtc_atomic_disable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
struct meson_drm *priv = meson_crtc->priv;
priv->viu.osd1_enabled = false;
priv->viu.osd1_commit = false;
writel_bits_relaxed(VPP_POSTBLEND_ENABLE, 0,
priv->io_base + _REG(VPP_MISC));
if (crtc->state->event && !crtc->state->active) {
spin_lock_irq(&crtc->dev->event_lock);
drm_crtc_send_vblank_event(crtc, crtc->state->event);
spin_unlock_irq(&crtc->dev->event_lock);
crtc->state->event = NULL;
}
}
static void meson_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
unsigned long flags;
if (crtc->state->event) {
WARN_ON(drm_crtc_vblank_get(crtc) != 0);
spin_lock_irqsave(&crtc->dev->event_lock, flags);
meson_crtc->event = crtc->state->event;
spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
crtc->state->event = NULL;
}
}
static void meson_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
struct meson_crtc *meson_crtc = to_meson_crtc(crtc);
struct meson_drm *priv = meson_crtc->priv;
priv->viu.osd1_commit = true;
}
void meson_crtc_irq(struct meson_drm *priv)
{
struct meson_crtc *meson_crtc = to_meson_crtc(priv->crtc);
unsigned long flags;
if (priv->viu.osd1_enabled && priv->viu.osd1_commit) {
writel_relaxed(priv->viu.osd1_ctrl_stat,
priv->io_base + _REG(VIU_OSD1_CTRL_STAT));
writel_relaxed(priv->viu.osd1_blk0_cfg[0],
priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W0));
writel_relaxed(priv->viu.osd1_blk0_cfg[1],
priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W1));
writel_relaxed(priv->viu.osd1_blk0_cfg[2],
priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W2));
writel_relaxed(priv->viu.osd1_blk0_cfg[3],
priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W3));
writel_relaxed(priv->viu.osd1_blk0_cfg[4],
priv->io_base + _REG(VIU_OSD1_BLK0_CFG_W4));
if (priv->viu.osd1_interlace) {
struct drm_plane *plane = priv->primary_plane;
struct drm_plane_state *state = plane->state;
struct drm_rect dest = {
.x1 = state->crtc_x,
.y1 = state->crtc_y,
.x2 = state->crtc_x + state->crtc_w,
.y2 = state->crtc_y + state->crtc_h,
};
meson_vpp_setup_interlace_vscaler_osd1(priv, &dest);
} else
meson_vpp_disable_interlace_vscaler_osd1(priv);
writel_bits_relaxed(VPP_OSD1_POSTBLEND, VPP_OSD1_POSTBLEND,
priv->io_base + _REG(VPP_MISC));
priv->viu.osd1_commit = false;
}
drm_crtc_handle_vblank(priv->crtc);
spin_lock_irqsave(&priv->drm->event_lock, flags);
if (meson_crtc->event) {
drm_crtc_send_vblank_event(priv->crtc, meson_crtc->event);
drm_crtc_vblank_put(priv->crtc);
meson_crtc->event = NULL;
}
spin_unlock_irqrestore(&priv->drm->event_lock, flags);
}
int meson_crtc_create(struct meson_drm *priv)
{
struct meson_crtc *meson_crtc;
struct drm_crtc *crtc;
int ret;
meson_crtc = devm_kzalloc(priv->drm->dev, sizeof(*meson_crtc),
GFP_KERNEL);
if (!meson_crtc)
return -ENOMEM;
meson_crtc->priv = priv;
crtc = &meson_crtc->base;
ret = drm_crtc_init_with_planes(priv->drm, crtc,
priv->primary_plane, NULL,
&meson_crtc_funcs, "meson_crtc");
if (ret) {
dev_err(priv->drm->dev, "Failed to init CRTC\n");
return ret;
}
drm_crtc_helper_add(crtc, &meson_crtc_helper_funcs);
priv->crtc = crtc;
return 0;
}
