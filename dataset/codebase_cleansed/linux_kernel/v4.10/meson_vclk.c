static void meson_venci_cvbs_clock_config(struct meson_drm *priv)
{
unsigned int val;
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu")) {
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x5800023d);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x00404e00);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x0d5c5091);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x801da72c);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x71486980);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x00000e55);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x4800023d);
} else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu")) {
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x4000027b);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x800cb300);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0xa6212844);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x0c4d000c);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x001fa729);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x01a31500);
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
HDMI_PLL_RESET, HDMI_PLL_RESET);
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
HDMI_PLL_RESET, 0);
}
regmap_read_poll_timeout(priv->hhi, HHI_HDMI_PLL_CNTL, val,
(val & HDMI_PLL_LOCK), 10, 0);
regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL, VCLK2_EN, 0);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV, VID_PLL_EN, 0);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV, VID_PLL_PRESET, 0);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
VID_PLL_BYPASS, VID_PLL_BYPASS);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
VID_PLL_EN, VID_PLL_EN);
regmap_update_bits(priv->hhi, HHI_VIID_CLK_DIV,
VCLK2_DIV_MASK, (55 - 1));
regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL,
VCLK2_SEL_MASK, (4 << VCLK2_SEL_SHIFT));
regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL, VCLK2_EN, VCLK2_EN);
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCI_SEL_MASK, (8 << CTS_ENCI_SEL_SHIFT));
regmap_update_bits(priv->hhi, HHI_VIID_CLK_DIV,
CTS_VDAC_SEL_MASK, (8 << CTS_VDAC_SEL_SHIFT));
regmap_update_bits(priv->hhi, HHI_VIID_CLK_DIV,
VCLK2_DIV_EN | VCLK2_DIV_RESET, VCLK2_DIV_EN);
regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL,
VCLK2_DIV1_EN, VCLK2_DIV1_EN);
regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL,
VCLK2_SOFT_RESET, VCLK2_SOFT_RESET);
regmap_update_bits(priv->hhi, HHI_VIID_CLK_CNTL,
VCLK2_SOFT_RESET, 0);
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
CTS_ENCI_EN, CTS_ENCI_EN);
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
CTS_VDAC_EN, CTS_VDAC_EN);
}
void meson_vclk_setup(struct meson_drm *priv, unsigned int target,
unsigned int freq)
{
if (target == MESON_VCLK_TARGET_CVBS && freq == MESON_VCLK_CVBS)
meson_venci_cvbs_clock_config(priv);
}
