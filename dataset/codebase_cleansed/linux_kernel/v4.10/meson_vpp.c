void meson_vpp_setup_mux(struct meson_drm *priv, unsigned int mux)
{
writel(mux, priv->io_base + _REG(VPU_VIU_VENC_MUX_CTRL));
}
void meson_vpp_setup_interlace_vscaler_osd1(struct meson_drm *priv,
struct drm_rect *input)
{
writel_relaxed(BIT(3) |
BIT(2),
priv->io_base + _REG(VPP_OSD_SC_CTRL0));
writel_relaxed(((drm_rect_width(input) - 1) << 16) |
(drm_rect_height(input) - 1),
priv->io_base + _REG(VPP_OSD_SCI_WH_M1));
writel_relaxed(((input->x1) << 16) | (input->x2),
priv->io_base + _REG(VPP_OSD_SCO_H_START_END));
writel_relaxed(((input->y1 >> 1) << 16) | (input->y2 >> 1),
priv->io_base + _REG(VPP_OSD_SCO_V_START_END));
writel_relaxed(BIT(16), priv->io_base + _REG(VPP_OSD_VSC_INI_PHASE));
writel_relaxed(BIT(25), priv->io_base + _REG(VPP_OSD_VSC_PHASE_STEP));
writel_relaxed(0, priv->io_base + _REG(VPP_OSD_HSC_CTRL0));
writel_relaxed((4 << 0) |
(4 << 3) |
(1 << 8) |
(6 << 11) |
(2 << 16) |
BIT(23) |
BIT(24),
priv->io_base + _REG(VPP_OSD_VSC_CTRL0));
}
void meson_vpp_disable_interlace_vscaler_osd1(struct meson_drm *priv)
{
writel_relaxed(0, priv->io_base + _REG(VPP_OSD_SC_CTRL0));
writel_relaxed(0, priv->io_base + _REG(VPP_OSD_VSC_CTRL0));
writel_relaxed(0, priv->io_base + _REG(VPP_OSD_HSC_CTRL0));
}
static void meson_vpp_write_scaling_filter_coefs(struct meson_drm *priv,
const unsigned int *coefs,
bool is_horizontal)
{
int i;
writel_relaxed(is_horizontal ? BIT(8) : 0,
priv->io_base + _REG(VPP_OSD_SCALE_COEF_IDX));
for (i = 0; i < 33; i++)
writel_relaxed(coefs[i],
priv->io_base + _REG(VPP_OSD_SCALE_COEF));
}
void meson_vpp_init(struct meson_drm *priv)
{
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
writel_relaxed(0x108080, priv->io_base + _REG(VPP_DUMMY_DATA1));
else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu")) {
writel_bits_relaxed(0xff << 16, 0xff << 16,
priv->io_base + _REG(VIU_MISC_CTRL1));
writel_relaxed(0x20000, priv->io_base + _REG(VPP_DOLBY_CTRL));
writel_relaxed(0x1020080,
priv->io_base + _REG(VPP_DUMMY_DATA1));
}
writel_relaxed(readl_relaxed(priv->io_base + _REG(VPP_OFIFO_SIZE)) |
0x77f, priv->io_base + _REG(VPP_OFIFO_SIZE));
writel_relaxed(0x08080808, priv->io_base + _REG(VPP_HOLD_LINES));
writel_bits_relaxed(VPP_PREBLEND_ENABLE, 0,
priv->io_base + _REG(VPP_MISC));
writel_bits_relaxed(VPP_POSTBLEND_ENABLE, 0,
priv->io_base + _REG(VPP_MISC));
writel_bits_relaxed(VPP_OSD1_POSTBLEND | VPP_OSD2_POSTBLEND |
VPP_VD1_POSTBLEND | VPP_VD2_POSTBLEND, 0,
priv->io_base + _REG(VPP_MISC));
writel_relaxed(0, priv->io_base + _REG(VPP_OSD_SC_CTRL0));
writel_relaxed(0, priv->io_base + _REG(VPP_OSD_VSC_CTRL0));
writel_relaxed(0, priv->io_base + _REG(VPP_OSD_HSC_CTRL0));
meson_vpp_write_scaling_filter_coefs(priv,
vpp_filter_coefs_4point_bspline, false);
meson_vpp_write_scaling_filter_coefs(priv,
vpp_filter_coefs_4point_bspline, true);
}
