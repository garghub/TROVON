void meson_venci_cvbs_mode_set(struct meson_drm *priv,
struct meson_cvbs_enci_mode *mode)
{
if (mode->mode_tag == priv->venc.current_mode)
return;
writel_relaxed(0x12, priv->io_base + _REG(ENCI_CFILT_CTRL));
writel_relaxed(0x12, priv->io_base + _REG(ENCI_CFILT_CTRL2));
writel_relaxed(0, priv->io_base + _REG(VENC_DVI_SETTING));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_MODE));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_MODE_ADV));
writel_relaxed(mode->hso_begin,
priv->io_base + _REG(ENCI_SYNC_HSO_BEGIN));
writel_relaxed(mode->hso_end,
priv->io_base + _REG(ENCI_SYNC_HSO_END));
writel_relaxed(mode->vso_even,
priv->io_base + _REG(ENCI_SYNC_VSO_EVNLN));
writel_relaxed(mode->vso_odd,
priv->io_base + _REG(ENCI_SYNC_VSO_ODDLN));
writel_relaxed(0x8100 + mode->macv_max_amp,
priv->io_base + _REG(ENCI_MACV_MAX_AMP));
writel_relaxed(mode->video_prog_mode,
priv->io_base + _REG(VENC_VIDEO_PROG_MODE));
writel_relaxed(mode->video_mode,
priv->io_base + _REG(ENCI_VIDEO_MODE));
writel_relaxed(0x26, priv->io_base + _REG(ENCI_VIDEO_MODE_ADV));
writel(mode->sch_adjust, priv->io_base + _REG(ENCI_VIDEO_SCH));
writel_relaxed(0x07, priv->io_base + _REG(ENCI_SYNC_MODE));
writel_relaxed(mode->yc_delay, priv->io_base + _REG(ENCI_YC_DELAY));
writel_relaxed(mode->pixel_start,
priv->io_base + _REG(ENCI_VFIFO2VD_PIXEL_START));
writel_relaxed(mode->pixel_end,
priv->io_base + _REG(ENCI_VFIFO2VD_PIXEL_END));
writel_relaxed(mode->top_field_line_start,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_TOP_START));
writel_relaxed(mode->top_field_line_end,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_TOP_END));
writel_relaxed(mode->bottom_field_line_start,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_BOT_START));
writel_relaxed(mode->bottom_field_line_end,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_BOT_END));
writel_relaxed(0, priv->io_base + _REG(VENC_SYNC_ROUTE));
writel_relaxed(0, priv->io_base + _REG(ENCI_DBG_PX_RST));
writel_relaxed(0x4e01, priv->io_base + _REG(ENCI_VFIFO2VD_CTL));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_SETTING));
writel_relaxed(0x0061, priv->io_base + _REG(VENC_UPSAMPLE_CTRL0));
writel_relaxed(0x4061, priv->io_base + _REG(VENC_UPSAMPLE_CTRL1));
writel_relaxed(0x5061, priv->io_base + _REG(VENC_UPSAMPLE_CTRL2));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL0));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL1));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL2));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL3));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL4));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL5));
meson_vpp_setup_mux(priv, MESON_VIU_VPP_MUX_ENCI);
writel_relaxed(0x2000, priv->io_base + _REG(VENC_VDAC_FIFO_CTRL));
writel_relaxed(0x11, priv->io_base + _REG(ENCI_DACSEL_0));
writel_relaxed(0x11, priv->io_base + _REG(ENCI_DACSEL_1));
writel_relaxed(1, priv->io_base + _REG(ENCI_VIDEO_EN));
writel_relaxed(mode->video_saturation,
priv->io_base + _REG(ENCI_VIDEO_SAT));
writel_relaxed(mode->video_contrast,
priv->io_base + _REG(ENCI_VIDEO_CONT));
writel_relaxed(mode->video_brightness,
priv->io_base + _REG(ENCI_VIDEO_BRIGHT));
writel_relaxed(mode->video_hue,
priv->io_base + _REG(ENCI_VIDEO_HUE));
writel_relaxed(0x1, priv->io_base + _REG(VENC_VDAC_DAC0_FILT_CTRL0));
writel_relaxed(0xfc48, priv->io_base + _REG(VENC_VDAC_DAC0_FILT_CTRL1));
writel_relaxed(0, priv->io_base + _REG(ENCI_MACV_N0));
writel_relaxed(mode->analog_sync_adj,
priv->io_base + _REG(ENCI_SYNC_ADJ));
meson_vclk_setup(priv, MESON_VCLK_TARGET_CVBS, MESON_VCLK_CVBS);
priv->venc.current_mode = mode->mode_tag;
}
unsigned int meson_venci_get_field(struct meson_drm *priv)
{
return readl_relaxed(priv->io_base + _REG(ENCI_INFO_READ)) & BIT(29);
}
void meson_venc_enable_vsync(struct meson_drm *priv)
{
writel_relaxed(2, priv->io_base + _REG(VENC_INTCTRL));
}
void meson_venc_disable_vsync(struct meson_drm *priv)
{
writel_relaxed(0, priv->io_base + _REG(VENC_INTCTRL));
}
void meson_venc_init(struct meson_drm *priv)
{
regmap_write(priv->hhi, HHI_VDAC_CNTL0, 0);
regmap_write(priv->hhi, HHI_VDAC_CNTL1, 8);
writel_relaxed(0xff, priv->io_base + _REG(VENC_VDAC_SETTING));
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0);
writel_bits_relaxed(0x3, 0,
priv->io_base + _REG(VPU_HDMI_SETTING));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_EN));
writel_relaxed(0, priv->io_base + _REG(ENCP_VIDEO_EN));
writel_relaxed(0, priv->io_base + _REG(ENCL_VIDEO_EN));
meson_venc_disable_vsync(priv);
priv->venc.current_mode = MESON_VENC_MODE_NONE;
}
