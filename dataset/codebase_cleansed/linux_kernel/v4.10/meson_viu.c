void meson_viu_set_osd_matrix(struct meson_drm *priv,
enum viu_matrix_sel_e m_select,
int *m, bool csc_on)
{
if (m_select == VIU_MATRIX_OSD) {
writel(((m[0] & 0xfff) << 16) | (m[1] & 0xfff),
priv->io_base + _REG(VIU_OSD1_MATRIX_PRE_OFFSET0_1));
writel(m[2] & 0xfff,
priv->io_base + _REG(VIU_OSD1_MATRIX_PRE_OFFSET2));
writel(((m[3] & 0x1fff) << 16) | (m[4] & 0x1fff),
priv->io_base + _REG(VIU_OSD1_MATRIX_COEF00_01));
writel(((m[5] & 0x1fff) << 16) | (m[6] & 0x1fff),
priv->io_base + _REG(VIU_OSD1_MATRIX_COEF02_10));
writel(((m[7] & 0x1fff) << 16) | (m[8] & 0x1fff),
priv->io_base + _REG(VIU_OSD1_MATRIX_COEF11_12));
writel(((m[9] & 0x1fff) << 16) | (m[10] & 0x1fff),
priv->io_base + _REG(VIU_OSD1_MATRIX_COEF20_21));
if (m[21]) {
writel(((m[11] & 0x1fff) << 16) | (m[12] & 0x1fff),
priv->io_base +
_REG(VIU_OSD1_MATRIX_COEF22_30));
writel(((m[13] & 0x1fff) << 16) | (m[14] & 0x1fff),
priv->io_base +
_REG(VIU_OSD1_MATRIX_COEF31_32));
writel(((m[15] & 0x1fff) << 16) | (m[16] & 0x1fff),
priv->io_base +
_REG(VIU_OSD1_MATRIX_COEF40_41));
writel(m[17] & 0x1fff, priv->io_base +
_REG(VIU_OSD1_MATRIX_COLMOD_COEF42));
} else
writel((m[11] & 0x1fff) << 16, priv->io_base +
_REG(VIU_OSD1_MATRIX_COEF22_30));
writel(((m[18] & 0xfff) << 16) | (m[19] & 0xfff),
priv->io_base + _REG(VIU_OSD1_MATRIX_OFFSET0_1));
writel(m[20] & 0xfff,
priv->io_base + _REG(VIU_OSD1_MATRIX_OFFSET2));
writel_bits_relaxed(3 << 30, m[21] << 30,
priv->io_base + _REG(VIU_OSD1_MATRIX_COLMOD_COEF42));
writel_bits_relaxed(7 << 16, m[22] << 16,
priv->io_base + _REG(VIU_OSD1_MATRIX_COLMOD_COEF42));
writel_bits_relaxed(BIT(0), csc_on ? BIT(0) : 0,
priv->io_base + _REG(VIU_OSD1_MATRIX_CTRL));
writel_bits_relaxed(BIT(1), 0,
priv->io_base + _REG(VIU_OSD1_MATRIX_CTRL));
} else if (m_select == VIU_MATRIX_OSD_EOTF) {
int i;
for (i = 0; i < 5; i++)
writel(((m[i * 2] & 0x1fff) << 16) |
(m[i * 2 + 1] & 0x1fff), priv->io_base +
_REG(VIU_OSD1_EOTF_CTL + i + 1));
writel_bits_relaxed(BIT(30), csc_on ? BIT(30) : 0,
priv->io_base + _REG(VIU_OSD1_EOTF_CTL));
writel_bits_relaxed(BIT(31), csc_on ? BIT(31) : 0,
priv->io_base + _REG(VIU_OSD1_EOTF_CTL));
}
}
void meson_viu_set_osd_lut(struct meson_drm *priv, enum viu_lut_sel_e lut_sel,
unsigned int *r_map, unsigned int *g_map,
unsigned int *b_map,
bool csc_on)
{
unsigned int addr_port;
unsigned int data_port;
unsigned int ctrl_port;
int i;
if (lut_sel == VIU_LUT_OSD_EOTF) {
addr_port = VIU_OSD1_EOTF_LUT_ADDR_PORT;
data_port = VIU_OSD1_EOTF_LUT_DATA_PORT;
ctrl_port = VIU_OSD1_EOTF_CTL;
} else if (lut_sel == VIU_LUT_OSD_OETF) {
addr_port = VIU_OSD1_OETF_LUT_ADDR_PORT;
data_port = VIU_OSD1_OETF_LUT_DATA_PORT;
ctrl_port = VIU_OSD1_OETF_CTL;
} else
return;
if (lut_sel == VIU_LUT_OSD_OETF) {
writel(0, priv->io_base + _REG(addr_port));
for (i = 0; i < 20; i++)
writel(r_map[i * 2] | (r_map[i * 2 + 1] << 16),
priv->io_base + _REG(data_port));
writel(r_map[OSD_OETF_LUT_SIZE - 1] | (g_map[0] << 16),
priv->io_base + _REG(data_port));
for (i = 0; i < 20; i++)
writel(g_map[i * 2 + 1] | (g_map[i * 2 + 2] << 16),
priv->io_base + _REG(data_port));
for (i = 0; i < 20; i++)
writel(b_map[i * 2] | (b_map[i * 2 + 1] << 16),
priv->io_base + _REG(data_port));
writel(b_map[OSD_OETF_LUT_SIZE - 1],
priv->io_base + _REG(data_port));
if (csc_on)
writel_bits_relaxed(0x7 << 29, 7 << 29,
priv->io_base + _REG(ctrl_port));
else
writel_bits_relaxed(0x7 << 29, 0,
priv->io_base + _REG(ctrl_port));
} else if (lut_sel == VIU_LUT_OSD_EOTF) {
writel(0, priv->io_base + _REG(addr_port));
for (i = 0; i < 20; i++)
writel(r_map[i * 2] | (r_map[i * 2 + 1] << 16),
priv->io_base + _REG(data_port));
writel(r_map[OSD_EOTF_LUT_SIZE - 1] | (g_map[0] << 16),
priv->io_base + _REG(data_port));
for (i = 0; i < 20; i++)
writel(g_map[i * 2 + 1] | (g_map[i * 2 + 2] << 16),
priv->io_base + _REG(data_port));
for (i = 0; i < 20; i++)
writel(b_map[i * 2] | (b_map[i * 2 + 1] << 16),
priv->io_base + _REG(data_port));
writel(b_map[OSD_EOTF_LUT_SIZE - 1],
priv->io_base + _REG(data_port));
if (csc_on)
writel_bits_relaxed(7 << 27, 7 << 27,
priv->io_base + _REG(ctrl_port));
else
writel_bits_relaxed(7 << 27, 0,
priv->io_base + _REG(ctrl_port));
writel_bits_relaxed(BIT(31), BIT(31),
priv->io_base + _REG(ctrl_port));
}
}
static void meson_viu_load_matrix(struct meson_drm *priv)
{
meson_viu_set_osd_lut(priv, VIU_LUT_OSD_EOTF,
eotf_33_linear_mapping,
eotf_33_linear_mapping,
eotf_33_linear_mapping,
false);
meson_viu_set_osd_matrix(priv, VIU_MATRIX_OSD_EOTF,
eotf_bypass_coeff,
false);
meson_viu_set_osd_lut(priv, VIU_LUT_OSD_OETF,
oetf_41_linear_mapping,
oetf_41_linear_mapping,
oetf_41_linear_mapping,
false);
meson_viu_set_osd_matrix(priv, VIU_MATRIX_OSD,
RGB709_to_YUV709l_coeff,
true);
}
void meson_viu_init(struct meson_drm *priv)
{
uint32_t reg;
writel_bits_relaxed(BIT(0) | BIT(21), 0,
priv->io_base + _REG(VIU_OSD1_CTRL_STAT));
writel_bits_relaxed(BIT(0) | BIT(21), 0,
priv->io_base + _REG(VIU_OSD2_CTRL_STAT));
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
meson_viu_load_matrix(priv);
reg = BIT(0) |
(4 << 5) |
(3 << 10) |
(32 << 12) |
(2 << 22) |
(2 << 24);
writel_relaxed(reg, priv->io_base + _REG(VIU_OSD1_FIFO_CTRL_STAT));
writel_relaxed(reg, priv->io_base + _REG(VIU_OSD2_FIFO_CTRL_STAT));
writel_bits_relaxed(0xff << OSD_REPLACE_SHIFT,
0xff << OSD_REPLACE_SHIFT,
priv->io_base + _REG(VIU_OSD1_CTRL_STAT2));
writel_bits_relaxed(0xff << OSD_REPLACE_SHIFT,
0xff << OSD_REPLACE_SHIFT,
priv->io_base + _REG(VIU_OSD2_CTRL_STAT2));
priv->viu.osd1_enabled = false;
priv->viu.osd1_commit = false;
priv->viu.osd1_interlace = false;
}
