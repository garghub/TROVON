static int meson_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_crtc_state *crtc_state;
struct drm_rect clip = { 0, };
if (!state->crtc)
return 0;
crtc_state = drm_atomic_get_crtc_state(state->state, state->crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
clip.x2 = crtc_state->mode.hdisplay;
clip.y2 = crtc_state->mode.vdisplay;
return drm_plane_helper_check_state(state, &clip,
DRM_PLANE_HELPER_NO_SCALING,
DRM_PLANE_HELPER_NO_SCALING,
true, true);
}
static inline int64_t fixed16_to_int(int64_t value)
{
return value >> 16;
}
static void meson_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct meson_plane *meson_plane = to_meson_plane(plane);
struct drm_plane_state *state = plane->state;
struct drm_framebuffer *fb = state->fb;
struct meson_drm *priv = meson_plane->priv;
struct drm_gem_cma_object *gem;
struct drm_rect src = {
.x1 = (state->src_x),
.y1 = (state->src_y),
.x2 = (state->src_x + state->src_w),
.y2 = (state->src_y + state->src_h),
};
struct drm_rect dest = {
.x1 = state->crtc_x,
.y1 = state->crtc_y,
.x2 = state->crtc_x + state->crtc_w,
.y2 = state->crtc_y + state->crtc_h,
};
unsigned long flags;
spin_lock_irqsave(&priv->drm->event_lock, flags);
priv->viu.osd1_ctrl_stat = OSD_ENABLE |
(0xFF << OSD_GLOBAL_ALPHA_SHIFT) |
OSD_BLK0_ENABLE;
priv->viu.osd1_blk0_cfg[0] = ((MESON_CANVAS_ID_OSD1 << OSD_CANVAS_SEL) |
OSD_ENDIANNESS_LE);
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
priv->viu.osd1_blk0_cfg[0] |= OSD_OUTPUT_COLOR_RGB;
switch (fb->format->format) {
case DRM_FORMAT_XRGB8888:
writel_bits_relaxed(OSD_REPLACE_EN, OSD_REPLACE_EN,
priv->io_base + _REG(VIU_OSD1_CTRL_STAT2));
priv->viu.osd1_blk0_cfg[0] |= OSD_BLK_MODE_32 |
OSD_COLOR_MATRIX_32_ARGB;
break;
case DRM_FORMAT_ARGB8888:
writel_bits_relaxed(OSD_REPLACE_EN, 0,
priv->io_base + _REG(VIU_OSD1_CTRL_STAT2));
priv->viu.osd1_blk0_cfg[0] |= OSD_BLK_MODE_32 |
OSD_COLOR_MATRIX_32_ARGB;
break;
case DRM_FORMAT_RGB888:
priv->viu.osd1_blk0_cfg[0] |= OSD_BLK_MODE_24 |
OSD_COLOR_MATRIX_24_RGB;
break;
case DRM_FORMAT_RGB565:
priv->viu.osd1_blk0_cfg[0] |= OSD_BLK_MODE_16 |
OSD_COLOR_MATRIX_16_RGB565;
break;
};
if (state->crtc->mode.flags & DRM_MODE_FLAG_INTERLACE) {
priv->viu.osd1_interlace = true;
dest.y1 /= 2;
dest.y2 /= 2;
} else
priv->viu.osd1_interlace = false;
priv->viu.osd1_blk0_cfg[1] = ((fixed16_to_int(src.x2) - 1) << 16) |
fixed16_to_int(src.x1);
priv->viu.osd1_blk0_cfg[2] = ((fixed16_to_int(src.y2) - 1) << 16) |
fixed16_to_int(src.y1);
priv->viu.osd1_blk0_cfg[3] = ((dest.x2 - 1) << 16) | dest.x1;
priv->viu.osd1_blk0_cfg[4] = ((dest.y2 - 1) << 16) | dest.y1;
gem = drm_fb_cma_get_gem_obj(fb, 0);
meson_canvas_setup(priv, MESON_CANVAS_ID_OSD1,
gem->paddr, fb->pitches[0],
fb->height, MESON_CANVAS_WRAP_NONE,
MESON_CANVAS_BLKMODE_LINEAR);
spin_unlock_irqrestore(&priv->drm->event_lock, flags);
}
static void meson_plane_atomic_disable(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct meson_plane *meson_plane = to_meson_plane(plane);
struct meson_drm *priv = meson_plane->priv;
writel_bits_relaxed(VPP_OSD1_POSTBLEND, 0,
priv->io_base + _REG(VPP_MISC));
}
int meson_plane_create(struct meson_drm *priv)
{
struct meson_plane *meson_plane;
struct drm_plane *plane;
meson_plane = devm_kzalloc(priv->drm->dev, sizeof(*meson_plane),
GFP_KERNEL);
if (!meson_plane)
return -ENOMEM;
meson_plane->priv = priv;
plane = &meson_plane->base;
drm_universal_plane_init(priv->drm, plane, 0xFF,
&meson_plane_funcs,
supported_drm_formats,
ARRAY_SIZE(supported_drm_formats),
DRM_PLANE_TYPE_PRIMARY, "meson_primary_plane");
drm_plane_helper_add(plane, &meson_plane_helper_funcs);
priv->primary_plane = plane;
return 0;
}
