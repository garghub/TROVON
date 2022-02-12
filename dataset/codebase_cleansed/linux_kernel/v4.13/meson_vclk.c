void meson_vid_pll_set(struct meson_drm *priv, unsigned int div)
{
unsigned int shift_val = 0;
unsigned int shift_sel = 0;
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV, VID_PLL_EN, 0);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV, VID_PLL_PRESET, 0);
switch (div) {
case VID_PLL_DIV_2:
shift_val = 0x0aaa;
shift_sel = 0;
break;
case VID_PLL_DIV_2p5:
shift_val = 0x5294;
shift_sel = 2;
break;
case VID_PLL_DIV_3:
shift_val = 0x0db6;
shift_sel = 0;
break;
case VID_PLL_DIV_3p5:
shift_val = 0x36cc;
shift_sel = 1;
break;
case VID_PLL_DIV_3p75:
shift_val = 0x6666;
shift_sel = 2;
break;
case VID_PLL_DIV_4:
shift_val = 0x0ccc;
shift_sel = 0;
break;
case VID_PLL_DIV_5:
shift_val = 0x739c;
shift_sel = 2;
break;
case VID_PLL_DIV_6:
shift_val = 0x0e38;
shift_sel = 0;
break;
case VID_PLL_DIV_6p25:
shift_val = 0x0000;
shift_sel = 3;
break;
case VID_PLL_DIV_7:
shift_val = 0x3c78;
shift_sel = 1;
break;
case VID_PLL_DIV_7p5:
shift_val = 0x78f0;
shift_sel = 2;
break;
case VID_PLL_DIV_12:
shift_val = 0x0fc0;
shift_sel = 0;
break;
case VID_PLL_DIV_14:
shift_val = 0x3f80;
shift_sel = 1;
break;
case VID_PLL_DIV_15:
shift_val = 0x7f80;
shift_sel = 2;
break;
}
if (div == VID_PLL_DIV_1)
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
VID_PLL_BYPASS, VID_PLL_BYPASS);
else {
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
VID_PLL_BYPASS, 0);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
3 << 16, 0);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
VID_PLL_PRESET, 0);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
0x7fff, 0);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
3 << 16, shift_sel << 16);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
VID_PLL_PRESET, VID_PLL_PRESET);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
0x7fff, shift_val);
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
VID_PLL_PRESET, 0);
}
regmap_update_bits(priv->hhi, HHI_VID_PLL_CLK_DIV,
VID_PLL_EN, VID_PLL_EN);
}
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
meson_vid_pll_set(priv, VID_PLL_DIV_1);
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
static inline unsigned int pll_od_to_reg(unsigned int od)
{
switch (od) {
case 1:
return 0;
case 2:
return 1;
case 4:
return 2;
case 8:
return 3;
}
return 0;
}
void meson_hdmi_pll_set(struct meson_drm *priv,
unsigned int base,
unsigned int od1,
unsigned int od2,
unsigned int od3)
{
unsigned int val;
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu")) {
switch (base) {
case 2970000:
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x5800023d);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x00000000);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x0d5c5091);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x801da72c);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x71486980);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x00000e55);
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
0x7 << 28, 0x4 << 28);
regmap_read_poll_timeout(priv->hhi, HHI_HDMI_PLL_CNTL,
val, (val & HDMI_PLL_LOCK), 10, 0);
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL2,
0xFFFF, 0x4e00);
break;
case 4320000:
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x5800025a);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x00000000);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x0d5c5091);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x801da72c);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x71486980);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x00000e55);
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
BIT(28), 0);
regmap_read_poll_timeout(priv->hhi, HHI_HDMI_PLL_CNTL,
val, (val & HDMI_PLL_LOCK), 10, 0);
break;
case 5940000:
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x5800027b);
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL2,
0xFFFF, 0x4c00);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x135c5091);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x801da72c);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x71486980);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x00000e55);
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
BIT(28), 0);
regmap_read_poll_timeout(priv->hhi, HHI_HDMI_PLL_CNTL,
val, (val & HDMI_PLL_LOCK), 10, 0);
break;
};
} else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu")) {
switch (base) {
case 2970000:
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x4000027b);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x800cb300);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x860f30c4);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x0c8e0000);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x001fa729);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x01a31500);
break;
case 4320000:
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x400002b4);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x800cb000);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x860f30c4);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x0c8e0000);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x001fa729);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x01a31500);
break;
case 5940000:
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL, 0x400002f7);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL2, 0x800cb200);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL3, 0x860f30c4);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL4, 0x0c8e0000);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL5, 0x001fa729);
regmap_write(priv->hhi, HHI_HDMI_PLL_CNTL6, 0x01a31500);
break;
};
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
HDMI_PLL_RESET, HDMI_PLL_RESET);
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL,
HDMI_PLL_RESET, 0);
regmap_read_poll_timeout(priv->hhi, HHI_HDMI_PLL_CNTL, val,
(val & HDMI_PLL_LOCK), 10, 0);
};
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL2,
3 << 16, pll_od_to_reg(od1) << 16);
else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL3,
3 << 21, pll_od_to_reg(od1) << 21);
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL2,
3 << 22, pll_od_to_reg(od2) << 22);
else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL3,
3 << 23, pll_od_to_reg(od2) << 23);
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL2,
3 << 18, pll_od_to_reg(od3) << 18);
else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
regmap_update_bits(priv->hhi, HHI_HDMI_PLL_CNTL3,
3 << 19, pll_od_to_reg(od3) << 19);
}
void meson_vclk_setup(struct meson_drm *priv, unsigned int target,
unsigned int vclk_freq, unsigned int venc_freq,
unsigned int dac_freq, bool hdmi_use_enci)
{
unsigned int freq;
unsigned int hdmi_tx_div;
unsigned int venc_div;
if (target == MESON_VCLK_TARGET_CVBS) {
meson_venci_cvbs_clock_config(priv);
return;
}
hdmi_tx_div = vclk_freq / dac_freq;
if (hdmi_tx_div == 0) {
pr_err("Fatal Error, invalid HDMI-TX freq %d\n",
dac_freq);
return;
}
venc_div = vclk_freq / venc_freq;
if (venc_div == 0) {
pr_err("Fatal Error, invalid HDMI venc freq %d\n",
venc_freq);
return;
}
switch (vclk_freq) {
case 54000:
if (hdmi_use_enci)
freq = MESON_VCLK_HDMI_ENCI_54000;
else
freq = MESON_VCLK_HDMI_DDR_54000;
break;
case 74250:
freq = MESON_VCLK_HDMI_74250;
break;
case 148500:
if (dac_freq != 148500)
freq = MESON_VCLK_HDMI_DDR_148500;
else
freq = MESON_VCLK_HDMI_148500;
break;
case 297000:
freq = MESON_VCLK_HDMI_297000;
break;
case 594000:
freq = MESON_VCLK_HDMI_594000;
break;
default:
pr_err("Fatal Error, invalid HDMI vclk freq %d\n",
vclk_freq);
return;
}
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
CTS_HDMI_SYS_SEL_MASK, 0);
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
CTS_HDMI_SYS_DIV_MASK, 0);
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
CTS_HDMI_SYS_EN, CTS_HDMI_SYS_EN);
meson_hdmi_pll_set(priv, params[freq].pll_base_freq,
params[freq].pll_od1,
params[freq].pll_od2,
params[freq].pll_od3);
meson_vid_pll_set(priv, params[freq].vid_pll_div);
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_SEL_MASK, 0);
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
VCLK_DIV_MASK, params[freq].vclk_div - 1);
switch (hdmi_tx_div) {
case 1:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV1_EN, VCLK_DIV1_EN);
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
HDMI_TX_PIXEL_SEL_MASK, 0);
break;
case 2:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV2_EN, VCLK_DIV2_EN);
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
HDMI_TX_PIXEL_SEL_MASK, 1 << HDMI_TX_PIXEL_SEL_SHIFT);
break;
case 4:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV4_EN, VCLK_DIV4_EN);
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
HDMI_TX_PIXEL_SEL_MASK, 2 << HDMI_TX_PIXEL_SEL_SHIFT);
break;
case 6:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV6_EN, VCLK_DIV6_EN);
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
HDMI_TX_PIXEL_SEL_MASK, 3 << HDMI_TX_PIXEL_SEL_SHIFT);
break;
case 12:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV12_EN, VCLK_DIV12_EN);
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL,
HDMI_TX_PIXEL_SEL_MASK, 4 << HDMI_TX_PIXEL_SEL_SHIFT);
break;
}
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
HDMI_TX_PIXEL_EN, HDMI_TX_PIXEL_EN);
switch (venc_div) {
case 1:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV1_EN, VCLK_DIV1_EN);
if (hdmi_use_enci)
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCI_SEL_MASK, 0);
else
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCP_SEL_MASK, 0);
break;
case 2:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV2_EN, VCLK_DIV2_EN);
if (hdmi_use_enci)
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCI_SEL_MASK, 1 << CTS_ENCI_SEL_SHIFT);
else
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCP_SEL_MASK, 1 << CTS_ENCP_SEL_SHIFT);
break;
case 4:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV4_EN, VCLK_DIV4_EN);
if (hdmi_use_enci)
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCI_SEL_MASK, 2 << CTS_ENCI_SEL_SHIFT);
else
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCP_SEL_MASK, 2 << CTS_ENCP_SEL_SHIFT);
break;
case 6:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV6_EN, VCLK_DIV6_EN);
if (hdmi_use_enci)
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCI_SEL_MASK, 3 << CTS_ENCI_SEL_SHIFT);
else
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCP_SEL_MASK, 3 << CTS_ENCP_SEL_SHIFT);
break;
case 12:
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL,
VCLK_DIV12_EN, VCLK_DIV12_EN);
if (hdmi_use_enci)
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCI_SEL_MASK, 4 << CTS_ENCI_SEL_SHIFT);
else
regmap_update_bits(priv->hhi, HHI_VID_CLK_DIV,
CTS_ENCP_SEL_MASK, 4 << CTS_ENCP_SEL_SHIFT);
break;
}
if (hdmi_use_enci)
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
CTS_ENCI_EN, CTS_ENCI_EN);
else
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL2,
CTS_ENCP_EN, CTS_ENCP_EN);
regmap_update_bits(priv->hhi, HHI_VID_CLK_CNTL, VCLK_EN, VCLK_EN);
}
