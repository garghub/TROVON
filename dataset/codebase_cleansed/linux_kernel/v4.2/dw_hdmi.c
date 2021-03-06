static void dw_hdmi_writel(struct dw_hdmi *hdmi, u8 val, int offset)
{
writel(val, hdmi->regs + (offset << 2));
}
static u8 dw_hdmi_readl(struct dw_hdmi *hdmi, int offset)
{
return readl(hdmi->regs + (offset << 2));
}
static void dw_hdmi_writeb(struct dw_hdmi *hdmi, u8 val, int offset)
{
writeb(val, hdmi->regs + offset);
}
static u8 dw_hdmi_readb(struct dw_hdmi *hdmi, int offset)
{
return readb(hdmi->regs + offset);
}
static inline void hdmi_writeb(struct dw_hdmi *hdmi, u8 val, int offset)
{
hdmi->write(hdmi, val, offset);
}
static inline u8 hdmi_readb(struct dw_hdmi *hdmi, int offset)
{
return hdmi->read(hdmi, offset);
}
static void hdmi_modb(struct dw_hdmi *hdmi, u8 data, u8 mask, unsigned reg)
{
u8 val = hdmi_readb(hdmi, reg) & ~mask;
val |= data & mask;
hdmi_writeb(hdmi, val, reg);
}
static void hdmi_mask_writeb(struct dw_hdmi *hdmi, u8 data, unsigned int reg,
u8 shift, u8 mask)
{
hdmi_modb(hdmi, data << shift, mask, reg);
}
static void hdmi_set_cts_n(struct dw_hdmi *hdmi, unsigned int cts,
unsigned int n)
{
hdmi_modb(hdmi, 0, HDMI_AUD_CTS3_CTS_MANUAL, HDMI_AUD_CTS3);
hdmi_modb(hdmi, 0, HDMI_AUD_CTS3_N_SHIFT_MASK, HDMI_AUD_CTS3);
hdmi_writeb(hdmi, ((cts >> 16) & HDMI_AUD_CTS3_AUDCTS19_16_MASK) |
HDMI_AUD_CTS3_CTS_MANUAL, HDMI_AUD_CTS3);
hdmi_writeb(hdmi, (cts >> 8) & 0xff, HDMI_AUD_CTS2);
hdmi_writeb(hdmi, cts & 0xff, HDMI_AUD_CTS1);
hdmi_writeb(hdmi, (n >> 16) & 0x0f, HDMI_AUD_N3);
hdmi_writeb(hdmi, (n >> 8) & 0xff, HDMI_AUD_N2);
hdmi_writeb(hdmi, n & 0xff, HDMI_AUD_N1);
}
static unsigned int hdmi_compute_n(unsigned int freq, unsigned long pixel_clk,
unsigned int ratio)
{
unsigned int n = (128 * freq) / 1000;
switch (freq) {
case 32000:
if (pixel_clk == 25170000)
n = (ratio == 150) ? 9152 : 4576;
else if (pixel_clk == 27020000)
n = (ratio == 150) ? 8192 : 4096;
else if (pixel_clk == 74170000 || pixel_clk == 148350000)
n = 11648;
else
n = 4096;
break;
case 44100:
if (pixel_clk == 25170000)
n = 7007;
else if (pixel_clk == 74170000)
n = 17836;
else if (pixel_clk == 148350000)
n = (ratio == 150) ? 17836 : 8918;
else
n = 6272;
break;
case 48000:
if (pixel_clk == 25170000)
n = (ratio == 150) ? 9152 : 6864;
else if (pixel_clk == 27020000)
n = (ratio == 150) ? 8192 : 6144;
else if (pixel_clk == 74170000)
n = 11648;
else if (pixel_clk == 148350000)
n = (ratio == 150) ? 11648 : 5824;
else
n = 6144;
break;
case 88200:
n = hdmi_compute_n(44100, pixel_clk, ratio) * 2;
break;
case 96000:
n = hdmi_compute_n(48000, pixel_clk, ratio) * 2;
break;
case 176400:
n = hdmi_compute_n(44100, pixel_clk, ratio) * 4;
break;
case 192000:
n = hdmi_compute_n(48000, pixel_clk, ratio) * 4;
break;
default:
break;
}
return n;
}
static unsigned int hdmi_compute_cts(unsigned int freq, unsigned long pixel_clk,
unsigned int ratio)
{
unsigned int cts = 0;
pr_debug("%s: freq: %d pixel_clk: %ld ratio: %d\n", __func__, freq,
pixel_clk, ratio);
switch (freq) {
case 32000:
if (pixel_clk == 297000000) {
cts = 222750;
break;
}
case 48000:
case 96000:
case 192000:
switch (pixel_clk) {
case 25200000:
case 27000000:
case 54000000:
case 74250000:
case 148500000:
cts = pixel_clk / 1000;
break;
case 297000000:
cts = 247500;
break;
default:
break;
}
break;
case 44100:
case 88200:
case 176400:
switch (pixel_clk) {
case 25200000:
cts = 28000;
break;
case 27000000:
cts = 30000;
break;
case 54000000:
cts = 60000;
break;
case 74250000:
cts = 82500;
break;
case 148500000:
cts = 165000;
break;
case 297000000:
cts = 247500;
break;
default:
break;
}
break;
default:
break;
}
if (ratio == 100)
return cts;
return (cts * ratio) / 100;
}
static void hdmi_set_clk_regenerator(struct dw_hdmi *hdmi,
unsigned long pixel_clk)
{
unsigned int clk_n, clk_cts;
clk_n = hdmi_compute_n(hdmi->sample_rate, pixel_clk,
hdmi->ratio);
clk_cts = hdmi_compute_cts(hdmi->sample_rate, pixel_clk,
hdmi->ratio);
if (!clk_cts) {
dev_dbg(hdmi->dev, "%s: pixel clock not supported: %lu\n",
__func__, pixel_clk);
return;
}
dev_dbg(hdmi->dev, "%s: samplerate=%d ratio=%d pixelclk=%lu N=%d cts=%d\n",
__func__, hdmi->sample_rate, hdmi->ratio,
pixel_clk, clk_n, clk_cts);
hdmi_set_cts_n(hdmi, clk_cts, clk_n);
}
static void hdmi_init_clk_regenerator(struct dw_hdmi *hdmi)
{
mutex_lock(&hdmi->audio_mutex);
hdmi_set_clk_regenerator(hdmi, 74250000);
mutex_unlock(&hdmi->audio_mutex);
}
static void hdmi_clk_regenerator_update_pixel_clock(struct dw_hdmi *hdmi)
{
mutex_lock(&hdmi->audio_mutex);
hdmi_set_clk_regenerator(hdmi, hdmi->hdmi_data.video_mode.mpixelclock);
mutex_unlock(&hdmi->audio_mutex);
}
static void hdmi_video_sample(struct dw_hdmi *hdmi)
{
int color_format = 0;
u8 val;
if (hdmi->hdmi_data.enc_in_format == RGB) {
if (hdmi->hdmi_data.enc_color_depth == 8)
color_format = 0x01;
else if (hdmi->hdmi_data.enc_color_depth == 10)
color_format = 0x03;
else if (hdmi->hdmi_data.enc_color_depth == 12)
color_format = 0x05;
else if (hdmi->hdmi_data.enc_color_depth == 16)
color_format = 0x07;
else
return;
} else if (hdmi->hdmi_data.enc_in_format == YCBCR444) {
if (hdmi->hdmi_data.enc_color_depth == 8)
color_format = 0x09;
else if (hdmi->hdmi_data.enc_color_depth == 10)
color_format = 0x0B;
else if (hdmi->hdmi_data.enc_color_depth == 12)
color_format = 0x0D;
else if (hdmi->hdmi_data.enc_color_depth == 16)
color_format = 0x0F;
else
return;
} else if (hdmi->hdmi_data.enc_in_format == YCBCR422_8BITS) {
if (hdmi->hdmi_data.enc_color_depth == 8)
color_format = 0x16;
else if (hdmi->hdmi_data.enc_color_depth == 10)
color_format = 0x14;
else if (hdmi->hdmi_data.enc_color_depth == 12)
color_format = 0x12;
else
return;
}
val = HDMI_TX_INVID0_INTERNAL_DE_GENERATOR_DISABLE |
((color_format << HDMI_TX_INVID0_VIDEO_MAPPING_OFFSET) &
HDMI_TX_INVID0_VIDEO_MAPPING_MASK);
hdmi_writeb(hdmi, val, HDMI_TX_INVID0);
val = HDMI_TX_INSTUFFING_BDBDATA_STUFFING_ENABLE |
HDMI_TX_INSTUFFING_RCRDATA_STUFFING_ENABLE |
HDMI_TX_INSTUFFING_GYDATA_STUFFING_ENABLE;
hdmi_writeb(hdmi, val, HDMI_TX_INSTUFFING);
hdmi_writeb(hdmi, 0x0, HDMI_TX_GYDATA0);
hdmi_writeb(hdmi, 0x0, HDMI_TX_GYDATA1);
hdmi_writeb(hdmi, 0x0, HDMI_TX_RCRDATA0);
hdmi_writeb(hdmi, 0x0, HDMI_TX_RCRDATA1);
hdmi_writeb(hdmi, 0x0, HDMI_TX_BCBDATA0);
hdmi_writeb(hdmi, 0x0, HDMI_TX_BCBDATA1);
}
static int is_color_space_conversion(struct dw_hdmi *hdmi)
{
return hdmi->hdmi_data.enc_in_format != hdmi->hdmi_data.enc_out_format;
}
static int is_color_space_decimation(struct dw_hdmi *hdmi)
{
if (hdmi->hdmi_data.enc_out_format != YCBCR422_8BITS)
return 0;
if (hdmi->hdmi_data.enc_in_format == RGB ||
hdmi->hdmi_data.enc_in_format == YCBCR444)
return 1;
return 0;
}
static int is_color_space_interpolation(struct dw_hdmi *hdmi)
{
if (hdmi->hdmi_data.enc_in_format != YCBCR422_8BITS)
return 0;
if (hdmi->hdmi_data.enc_out_format == RGB ||
hdmi->hdmi_data.enc_out_format == YCBCR444)
return 1;
return 0;
}
static void dw_hdmi_update_csc_coeffs(struct dw_hdmi *hdmi)
{
const u16 (*csc_coeff)[3][4] = &csc_coeff_default;
unsigned i;
u32 csc_scale = 1;
if (is_color_space_conversion(hdmi)) {
if (hdmi->hdmi_data.enc_out_format == RGB) {
if (hdmi->hdmi_data.colorimetry ==
HDMI_COLORIMETRY_ITU_601)
csc_coeff = &csc_coeff_rgb_out_eitu601;
else
csc_coeff = &csc_coeff_rgb_out_eitu709;
} else if (hdmi->hdmi_data.enc_in_format == RGB) {
if (hdmi->hdmi_data.colorimetry ==
HDMI_COLORIMETRY_ITU_601)
csc_coeff = &csc_coeff_rgb_in_eitu601;
else
csc_coeff = &csc_coeff_rgb_in_eitu709;
csc_scale = 0;
}
}
for (i = 0; i < ARRAY_SIZE(csc_coeff_default[0]); i++) {
u16 coeff_a = (*csc_coeff)[0][i];
u16 coeff_b = (*csc_coeff)[1][i];
u16 coeff_c = (*csc_coeff)[2][i];
hdmi_writeb(hdmi, coeff_a & 0xff, HDMI_CSC_COEF_A1_LSB + i * 2);
hdmi_writeb(hdmi, coeff_a >> 8, HDMI_CSC_COEF_A1_MSB + i * 2);
hdmi_writeb(hdmi, coeff_b & 0xff, HDMI_CSC_COEF_B1_LSB + i * 2);
hdmi_writeb(hdmi, coeff_b >> 8, HDMI_CSC_COEF_B1_MSB + i * 2);
hdmi_writeb(hdmi, coeff_c & 0xff, HDMI_CSC_COEF_C1_LSB + i * 2);
hdmi_writeb(hdmi, coeff_c >> 8, HDMI_CSC_COEF_C1_MSB + i * 2);
}
hdmi_modb(hdmi, csc_scale, HDMI_CSC_SCALE_CSCSCALE_MASK,
HDMI_CSC_SCALE);
}
static void hdmi_video_csc(struct dw_hdmi *hdmi)
{
int color_depth = 0;
int interpolation = HDMI_CSC_CFG_INTMODE_DISABLE;
int decimation = 0;
if (is_color_space_interpolation(hdmi))
interpolation = HDMI_CSC_CFG_INTMODE_CHROMA_INT_FORMULA1;
else if (is_color_space_decimation(hdmi))
decimation = HDMI_CSC_CFG_DECMODE_CHROMA_INT_FORMULA3;
if (hdmi->hdmi_data.enc_color_depth == 8)
color_depth = HDMI_CSC_SCALE_CSC_COLORDE_PTH_24BPP;
else if (hdmi->hdmi_data.enc_color_depth == 10)
color_depth = HDMI_CSC_SCALE_CSC_COLORDE_PTH_30BPP;
else if (hdmi->hdmi_data.enc_color_depth == 12)
color_depth = HDMI_CSC_SCALE_CSC_COLORDE_PTH_36BPP;
else if (hdmi->hdmi_data.enc_color_depth == 16)
color_depth = HDMI_CSC_SCALE_CSC_COLORDE_PTH_48BPP;
else
return;
hdmi_writeb(hdmi, interpolation | decimation, HDMI_CSC_CFG);
hdmi_modb(hdmi, color_depth, HDMI_CSC_SCALE_CSC_COLORDE_PTH_MASK,
HDMI_CSC_SCALE);
dw_hdmi_update_csc_coeffs(hdmi);
}
static void hdmi_video_packetize(struct dw_hdmi *hdmi)
{
unsigned int color_depth = 0;
unsigned int remap_size = HDMI_VP_REMAP_YCC422_16bit;
unsigned int output_select = HDMI_VP_CONF_OUTPUT_SELECTOR_PP;
struct hdmi_data_info *hdmi_data = &hdmi->hdmi_data;
u8 val, vp_conf;
if (hdmi_data->enc_out_format == RGB ||
hdmi_data->enc_out_format == YCBCR444) {
if (!hdmi_data->enc_color_depth) {
output_select = HDMI_VP_CONF_OUTPUT_SELECTOR_BYPASS;
} else if (hdmi_data->enc_color_depth == 8) {
color_depth = 4;
output_select = HDMI_VP_CONF_OUTPUT_SELECTOR_BYPASS;
} else if (hdmi_data->enc_color_depth == 10) {
color_depth = 5;
} else if (hdmi_data->enc_color_depth == 12) {
color_depth = 6;
} else if (hdmi_data->enc_color_depth == 16) {
color_depth = 7;
} else {
return;
}
} else if (hdmi_data->enc_out_format == YCBCR422_8BITS) {
if (!hdmi_data->enc_color_depth ||
hdmi_data->enc_color_depth == 8)
remap_size = HDMI_VP_REMAP_YCC422_16bit;
else if (hdmi_data->enc_color_depth == 10)
remap_size = HDMI_VP_REMAP_YCC422_20bit;
else if (hdmi_data->enc_color_depth == 12)
remap_size = HDMI_VP_REMAP_YCC422_24bit;
else
return;
output_select = HDMI_VP_CONF_OUTPUT_SELECTOR_YCC422;
} else {
return;
}
val = ((color_depth << HDMI_VP_PR_CD_COLOR_DEPTH_OFFSET) &
HDMI_VP_PR_CD_COLOR_DEPTH_MASK) |
((hdmi_data->pix_repet_factor <<
HDMI_VP_PR_CD_DESIRED_PR_FACTOR_OFFSET) &
HDMI_VP_PR_CD_DESIRED_PR_FACTOR_MASK);
hdmi_writeb(hdmi, val, HDMI_VP_PR_CD);
hdmi_modb(hdmi, HDMI_VP_STUFF_PR_STUFFING_STUFFING_MODE,
HDMI_VP_STUFF_PR_STUFFING_MASK, HDMI_VP_STUFF);
if (hdmi_data->pix_repet_factor > 1) {
vp_conf = HDMI_VP_CONF_PR_EN_ENABLE |
HDMI_VP_CONF_BYPASS_SELECT_PIX_REPEATER;
} else {
vp_conf = HDMI_VP_CONF_PR_EN_DISABLE |
HDMI_VP_CONF_BYPASS_SELECT_VID_PACKETIZER;
}
hdmi_modb(hdmi, vp_conf,
HDMI_VP_CONF_PR_EN_MASK |
HDMI_VP_CONF_BYPASS_SELECT_MASK, HDMI_VP_CONF);
hdmi_modb(hdmi, 1 << HDMI_VP_STUFF_IDEFAULT_PHASE_OFFSET,
HDMI_VP_STUFF_IDEFAULT_PHASE_MASK, HDMI_VP_STUFF);
hdmi_writeb(hdmi, remap_size, HDMI_VP_REMAP);
if (output_select == HDMI_VP_CONF_OUTPUT_SELECTOR_PP) {
vp_conf = HDMI_VP_CONF_BYPASS_EN_DISABLE |
HDMI_VP_CONF_PP_EN_ENABLE |
HDMI_VP_CONF_YCC422_EN_DISABLE;
} else if (output_select == HDMI_VP_CONF_OUTPUT_SELECTOR_YCC422) {
vp_conf = HDMI_VP_CONF_BYPASS_EN_DISABLE |
HDMI_VP_CONF_PP_EN_DISABLE |
HDMI_VP_CONF_YCC422_EN_ENABLE;
} else if (output_select == HDMI_VP_CONF_OUTPUT_SELECTOR_BYPASS) {
vp_conf = HDMI_VP_CONF_BYPASS_EN_ENABLE |
HDMI_VP_CONF_PP_EN_DISABLE |
HDMI_VP_CONF_YCC422_EN_DISABLE;
} else {
return;
}
hdmi_modb(hdmi, vp_conf,
HDMI_VP_CONF_BYPASS_EN_MASK | HDMI_VP_CONF_PP_EN_ENMASK |
HDMI_VP_CONF_YCC422_EN_MASK, HDMI_VP_CONF);
hdmi_modb(hdmi, HDMI_VP_STUFF_PP_STUFFING_STUFFING_MODE |
HDMI_VP_STUFF_YCC422_STUFFING_STUFFING_MODE,
HDMI_VP_STUFF_PP_STUFFING_MASK |
HDMI_VP_STUFF_YCC422_STUFFING_MASK, HDMI_VP_STUFF);
hdmi_modb(hdmi, output_select, HDMI_VP_CONF_OUTPUT_SELECTOR_MASK,
HDMI_VP_CONF);
}
static inline void hdmi_phy_test_clear(struct dw_hdmi *hdmi,
unsigned char bit)
{
hdmi_modb(hdmi, bit << HDMI_PHY_TST0_TSTCLR_OFFSET,
HDMI_PHY_TST0_TSTCLR_MASK, HDMI_PHY_TST0);
}
static inline void hdmi_phy_test_enable(struct dw_hdmi *hdmi,
unsigned char bit)
{
hdmi_modb(hdmi, bit << HDMI_PHY_TST0_TSTEN_OFFSET,
HDMI_PHY_TST0_TSTEN_MASK, HDMI_PHY_TST0);
}
static inline void hdmi_phy_test_clock(struct dw_hdmi *hdmi,
unsigned char bit)
{
hdmi_modb(hdmi, bit << HDMI_PHY_TST0_TSTCLK_OFFSET,
HDMI_PHY_TST0_TSTCLK_MASK, HDMI_PHY_TST0);
}
static inline void hdmi_phy_test_din(struct dw_hdmi *hdmi,
unsigned char bit)
{
hdmi_writeb(hdmi, bit, HDMI_PHY_TST1);
}
static inline void hdmi_phy_test_dout(struct dw_hdmi *hdmi,
unsigned char bit)
{
hdmi_writeb(hdmi, bit, HDMI_PHY_TST2);
}
static bool hdmi_phy_wait_i2c_done(struct dw_hdmi *hdmi, int msec)
{
u32 val;
while ((val = hdmi_readb(hdmi, HDMI_IH_I2CMPHY_STAT0) & 0x3) == 0) {
if (msec-- == 0)
return false;
udelay(1000);
}
hdmi_writeb(hdmi, val, HDMI_IH_I2CMPHY_STAT0);
return true;
}
static void __hdmi_phy_i2c_write(struct dw_hdmi *hdmi, unsigned short data,
unsigned char addr)
{
hdmi_writeb(hdmi, 0xFF, HDMI_IH_I2CMPHY_STAT0);
hdmi_writeb(hdmi, addr, HDMI_PHY_I2CM_ADDRESS_ADDR);
hdmi_writeb(hdmi, (unsigned char)(data >> 8),
HDMI_PHY_I2CM_DATAO_1_ADDR);
hdmi_writeb(hdmi, (unsigned char)(data >> 0),
HDMI_PHY_I2CM_DATAO_0_ADDR);
hdmi_writeb(hdmi, HDMI_PHY_I2CM_OPERATION_ADDR_WRITE,
HDMI_PHY_I2CM_OPERATION_ADDR);
hdmi_phy_wait_i2c_done(hdmi, 1000);
}
static int hdmi_phy_i2c_write(struct dw_hdmi *hdmi, unsigned short data,
unsigned char addr)
{
__hdmi_phy_i2c_write(hdmi, data, addr);
return 0;
}
static void dw_hdmi_phy_enable_power(struct dw_hdmi *hdmi, u8 enable)
{
hdmi_mask_writeb(hdmi, enable, HDMI_PHY_CONF0,
HDMI_PHY_CONF0_PDZ_OFFSET,
HDMI_PHY_CONF0_PDZ_MASK);
}
static void dw_hdmi_phy_enable_tmds(struct dw_hdmi *hdmi, u8 enable)
{
hdmi_mask_writeb(hdmi, enable, HDMI_PHY_CONF0,
HDMI_PHY_CONF0_ENTMDS_OFFSET,
HDMI_PHY_CONF0_ENTMDS_MASK);
}
static void dw_hdmi_phy_enable_spare(struct dw_hdmi *hdmi, u8 enable)
{
hdmi_mask_writeb(hdmi, enable, HDMI_PHY_CONF0,
HDMI_PHY_CONF0_SPARECTRL_OFFSET,
HDMI_PHY_CONF0_SPARECTRL_MASK);
}
static void dw_hdmi_phy_gen2_pddq(struct dw_hdmi *hdmi, u8 enable)
{
hdmi_mask_writeb(hdmi, enable, HDMI_PHY_CONF0,
HDMI_PHY_CONF0_GEN2_PDDQ_OFFSET,
HDMI_PHY_CONF0_GEN2_PDDQ_MASK);
}
static void dw_hdmi_phy_gen2_txpwron(struct dw_hdmi *hdmi, u8 enable)
{
hdmi_mask_writeb(hdmi, enable, HDMI_PHY_CONF0,
HDMI_PHY_CONF0_GEN2_TXPWRON_OFFSET,
HDMI_PHY_CONF0_GEN2_TXPWRON_MASK);
}
static void dw_hdmi_phy_sel_data_en_pol(struct dw_hdmi *hdmi, u8 enable)
{
hdmi_mask_writeb(hdmi, enable, HDMI_PHY_CONF0,
HDMI_PHY_CONF0_SELDATAENPOL_OFFSET,
HDMI_PHY_CONF0_SELDATAENPOL_MASK);
}
static void dw_hdmi_phy_sel_interface_control(struct dw_hdmi *hdmi, u8 enable)
{
hdmi_mask_writeb(hdmi, enable, HDMI_PHY_CONF0,
HDMI_PHY_CONF0_SELDIPIF_OFFSET,
HDMI_PHY_CONF0_SELDIPIF_MASK);
}
static int hdmi_phy_configure(struct dw_hdmi *hdmi, unsigned char prep,
unsigned char res, int cscon)
{
unsigned res_idx, i;
u8 val, msec;
const struct dw_hdmi_plat_data *plat_data = hdmi->plat_data;
const struct dw_hdmi_mpll_config *mpll_config = plat_data->mpll_cfg;
const struct dw_hdmi_curr_ctrl *curr_ctrl = plat_data->cur_ctr;
const struct dw_hdmi_phy_config *phy_config = plat_data->phy_config;
if (prep)
return -EINVAL;
switch (res) {
case 0:
case 8:
res_idx = DW_HDMI_RES_8;
break;
case 10:
res_idx = DW_HDMI_RES_10;
break;
case 12:
res_idx = DW_HDMI_RES_12;
break;
default:
return -EINVAL;
}
if (cscon)
val = HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_CSC_IN_PATH;
else
val = HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_CSC_BYPASS;
hdmi_writeb(hdmi, val, HDMI_MC_FLOWCTRL);
dw_hdmi_phy_gen2_txpwron(hdmi, 0);
dw_hdmi_phy_gen2_pddq(hdmi, 1);
hdmi_writeb(hdmi, HDMI_MC_PHYRSTZ_DEASSERT, HDMI_MC_PHYRSTZ);
hdmi_writeb(hdmi, HDMI_MC_PHYRSTZ_ASSERT, HDMI_MC_PHYRSTZ);
hdmi_writeb(hdmi, HDMI_MC_HEACPHY_RST_ASSERT, HDMI_MC_HEACPHY_RST);
hdmi_phy_test_clear(hdmi, 1);
hdmi_writeb(hdmi, HDMI_PHY_I2CM_SLAVE_ADDR_PHY_GEN2,
HDMI_PHY_I2CM_SLAVE_ADDR);
hdmi_phy_test_clear(hdmi, 0);
for (i = 0; mpll_config[i].mpixelclock != (~0UL); i++)
if (hdmi->hdmi_data.video_mode.mpixelclock <=
mpll_config[i].mpixelclock)
break;
hdmi_phy_i2c_write(hdmi, mpll_config[i].res[res_idx].cpce, 0x06);
hdmi_phy_i2c_write(hdmi, mpll_config[i].res[res_idx].gmp, 0x15);
for (i = 0; curr_ctrl[i].mpixelclock != (~0UL); i++)
if (hdmi->hdmi_data.video_mode.mpixelclock <=
curr_ctrl[i].mpixelclock)
break;
if (curr_ctrl[i].mpixelclock == (~0UL)) {
dev_err(hdmi->dev, "Pixel clock %d - unsupported by HDMI\n",
hdmi->hdmi_data.video_mode.mpixelclock);
return -EINVAL;
}
hdmi_phy_i2c_write(hdmi, curr_ctrl[i].curr[res_idx], 0x10);
hdmi_phy_i2c_write(hdmi, 0x0000, 0x13);
hdmi_phy_i2c_write(hdmi, 0x0006, 0x17);
for (i = 0; phy_config[i].mpixelclock != (~0UL); i++)
if (hdmi->hdmi_data.video_mode.mpixelclock <=
phy_config[i].mpixelclock)
break;
hdmi_phy_i2c_write(hdmi, phy_config[i].term, 0x19);
hdmi_phy_i2c_write(hdmi, phy_config[i].sym_ctr, 0x09);
hdmi_phy_i2c_write(hdmi, phy_config[i].vlev_ctr, 0x0E);
hdmi_phy_i2c_write(hdmi, 0x8000, 0x05);
dw_hdmi_phy_enable_power(hdmi, 1);
dw_hdmi_phy_enable_tmds(hdmi, 0);
dw_hdmi_phy_enable_tmds(hdmi, 1);
dw_hdmi_phy_gen2_txpwron(hdmi, 1);
dw_hdmi_phy_gen2_pddq(hdmi, 0);
if (hdmi->dev_type == RK3288_HDMI)
dw_hdmi_phy_enable_spare(hdmi, 1);
msec = 5;
do {
val = hdmi_readb(hdmi, HDMI_PHY_STAT0) & HDMI_PHY_TX_PHY_LOCK;
if (!val)
break;
if (msec == 0) {
dev_err(hdmi->dev, "PHY PLL not locked\n");
return -ETIMEDOUT;
}
udelay(1000);
msec--;
} while (1);
return 0;
}
static int dw_hdmi_phy_init(struct dw_hdmi *hdmi)
{
int i, ret;
bool cscon = false;
cscon = (is_color_space_conversion(hdmi) &&
!hdmi->hdmi_data.video_mode.mdvi);
for (i = 0; i < 2; i++) {
dw_hdmi_phy_sel_data_en_pol(hdmi, 1);
dw_hdmi_phy_sel_interface_control(hdmi, 0);
dw_hdmi_phy_enable_tmds(hdmi, 0);
dw_hdmi_phy_enable_power(hdmi, 0);
ret = hdmi_phy_configure(hdmi, 0, 8, cscon);
if (ret)
return ret;
}
hdmi->phy_enabled = true;
return 0;
}
static void hdmi_tx_hdcp_config(struct dw_hdmi *hdmi)
{
u8 de;
if (hdmi->hdmi_data.video_mode.mdataenablepolarity)
de = HDMI_A_VIDPOLCFG_DATAENPOL_ACTIVE_HIGH;
else
de = HDMI_A_VIDPOLCFG_DATAENPOL_ACTIVE_LOW;
hdmi_modb(hdmi, HDMI_A_HDCPCFG0_RXDETECT_DISABLE,
HDMI_A_HDCPCFG0_RXDETECT_MASK, HDMI_A_HDCPCFG0);
hdmi_modb(hdmi, de, HDMI_A_VIDPOLCFG_DATAENPOL_MASK, HDMI_A_VIDPOLCFG);
hdmi_modb(hdmi, HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_DISABLE,
HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_MASK, HDMI_A_HDCPCFG1);
}
static void hdmi_config_AVI(struct dw_hdmi *hdmi)
{
u8 val, pix_fmt, under_scan;
u8 act_ratio, coded_ratio, colorimetry, ext_colorimetry;
bool aspect_16_9;
aspect_16_9 = false;
if (hdmi->hdmi_data.enc_out_format == YCBCR444)
pix_fmt = HDMI_FC_AVICONF0_PIX_FMT_YCBCR444;
else if (hdmi->hdmi_data.enc_out_format == YCBCR422_8BITS)
pix_fmt = HDMI_FC_AVICONF0_PIX_FMT_YCBCR422;
else
pix_fmt = HDMI_FC_AVICONF0_PIX_FMT_RGB;
under_scan = HDMI_FC_AVICONF0_SCAN_INFO_NODATA;
val = pix_fmt | under_scan |
HDMI_FC_AVICONF0_ACTIVE_FMT_INFO_PRESENT |
HDMI_FC_AVICONF0_BAR_DATA_NO_DATA;
hdmi_writeb(hdmi, val, HDMI_FC_AVICONF0);
if (aspect_16_9) {
act_ratio = HDMI_FC_AVICONF1_ACTIVE_ASPECT_RATIO_16_9;
coded_ratio = HDMI_FC_AVICONF1_CODED_ASPECT_RATIO_16_9;
} else {
act_ratio = HDMI_FC_AVICONF1_ACTIVE_ASPECT_RATIO_4_3;
coded_ratio = HDMI_FC_AVICONF1_CODED_ASPECT_RATIO_4_3;
}
if (hdmi->hdmi_data.enc_out_format == XVYCC444) {
colorimetry = HDMI_FC_AVICONF1_COLORIMETRY_EXTENDED_INFO;
if (hdmi->hdmi_data.colorimetry == HDMI_COLORIMETRY_ITU_601)
ext_colorimetry =
HDMI_FC_AVICONF2_EXT_COLORIMETRY_XVYCC601;
else
ext_colorimetry =
HDMI_FC_AVICONF2_EXT_COLORIMETRY_XVYCC709;
} else if (hdmi->hdmi_data.enc_out_format != RGB) {
if (hdmi->hdmi_data.colorimetry == HDMI_COLORIMETRY_ITU_601)
colorimetry = HDMI_FC_AVICONF1_COLORIMETRY_SMPTE;
else
colorimetry = HDMI_FC_AVICONF1_COLORIMETRY_ITUR;
ext_colorimetry = HDMI_FC_AVICONF2_EXT_COLORIMETRY_XVYCC601;
} else {
colorimetry = HDMI_FC_AVICONF1_COLORIMETRY_NO_DATA;
ext_colorimetry = HDMI_FC_AVICONF2_EXT_COLORIMETRY_XVYCC601;
}
val = colorimetry | coded_ratio | act_ratio;
hdmi_writeb(hdmi, val, HDMI_FC_AVICONF1);
val = HDMI_FC_AVICONF2_IT_CONTENT_NO_DATA | ext_colorimetry |
HDMI_FC_AVICONF2_RGB_QUANT_DEFAULT |
HDMI_FC_AVICONF2_SCALING_NONE;
hdmi_writeb(hdmi, val, HDMI_FC_AVICONF2);
hdmi_writeb(hdmi, hdmi->vic, HDMI_FC_AVIVID);
val = (((hdmi->hdmi_data.video_mode.mpixelrepetitioninput + 1) <<
HDMI_FC_PRCONF_INCOMING_PR_FACTOR_OFFSET) &
HDMI_FC_PRCONF_INCOMING_PR_FACTOR_MASK) |
((hdmi->hdmi_data.video_mode.mpixelrepetitionoutput <<
HDMI_FC_PRCONF_OUTPUT_PR_FACTOR_OFFSET) &
HDMI_FC_PRCONF_OUTPUT_PR_FACTOR_MASK);
hdmi_writeb(hdmi, val, HDMI_FC_PRCONF);
val = HDMI_FC_AVICONF3_IT_CONTENT_TYPE_GRAPHICS |
HDMI_FC_AVICONF3_QUANT_RANGE_LIMITED;
hdmi_writeb(hdmi, val, HDMI_FC_AVICONF3);
hdmi_writeb(hdmi, 0, HDMI_FC_AVIETB0);
hdmi_writeb(hdmi, 0, HDMI_FC_AVIETB1);
hdmi_writeb(hdmi, 0, HDMI_FC_AVISBB0);
hdmi_writeb(hdmi, 0, HDMI_FC_AVISBB1);
hdmi_writeb(hdmi, 0, HDMI_FC_AVIELB0);
hdmi_writeb(hdmi, 0, HDMI_FC_AVIELB1);
hdmi_writeb(hdmi, 0, HDMI_FC_AVISRB0);
hdmi_writeb(hdmi, 0, HDMI_FC_AVISRB1);
}
static void hdmi_av_composer(struct dw_hdmi *hdmi,
const struct drm_display_mode *mode)
{
u8 inv_val;
struct hdmi_vmode *vmode = &hdmi->hdmi_data.video_mode;
int hblank, vblank, h_de_hs, v_de_vs, hsync_len, vsync_len;
vmode->mhsyncpolarity = !!(mode->flags & DRM_MODE_FLAG_PHSYNC);
vmode->mvsyncpolarity = !!(mode->flags & DRM_MODE_FLAG_PVSYNC);
vmode->minterlaced = !!(mode->flags & DRM_MODE_FLAG_INTERLACE);
vmode->mpixelclock = mode->clock * 1000;
dev_dbg(hdmi->dev, "final pixclk = %d\n", vmode->mpixelclock);
inv_val = (hdmi->hdmi_data.hdcp_enable ?
HDMI_FC_INVIDCONF_HDCP_KEEPOUT_ACTIVE :
HDMI_FC_INVIDCONF_HDCP_KEEPOUT_INACTIVE);
inv_val |= (vmode->mvsyncpolarity ?
HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_ACTIVE_HIGH :
HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_ACTIVE_LOW);
inv_val |= (vmode->mhsyncpolarity ?
HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_ACTIVE_HIGH :
HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_ACTIVE_LOW);
inv_val |= (vmode->mdataenablepolarity ?
HDMI_FC_INVIDCONF_DE_IN_POLARITY_ACTIVE_HIGH :
HDMI_FC_INVIDCONF_DE_IN_POLARITY_ACTIVE_LOW);
if (hdmi->vic == 39)
inv_val |= HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_HIGH;
else
inv_val |= (vmode->minterlaced ?
HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_HIGH :
HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_LOW);
inv_val |= (vmode->minterlaced ?
HDMI_FC_INVIDCONF_IN_I_P_INTERLACED :
HDMI_FC_INVIDCONF_IN_I_P_PROGRESSIVE);
inv_val |= (vmode->mdvi ?
HDMI_FC_INVIDCONF_DVI_MODEZ_DVI_MODE :
HDMI_FC_INVIDCONF_DVI_MODEZ_HDMI_MODE);
hdmi_writeb(hdmi, inv_val, HDMI_FC_INVIDCONF);
hdmi_writeb(hdmi, mode->hdisplay >> 8, HDMI_FC_INHACTV1);
hdmi_writeb(hdmi, mode->hdisplay, HDMI_FC_INHACTV0);
hdmi_writeb(hdmi, mode->vdisplay >> 8, HDMI_FC_INVACTV1);
hdmi_writeb(hdmi, mode->vdisplay, HDMI_FC_INVACTV0);
hblank = mode->htotal - mode->hdisplay;
hdmi_writeb(hdmi, hblank >> 8, HDMI_FC_INHBLANK1);
hdmi_writeb(hdmi, hblank, HDMI_FC_INHBLANK0);
vblank = mode->vtotal - mode->vdisplay;
hdmi_writeb(hdmi, vblank, HDMI_FC_INVBLANK);
h_de_hs = mode->hsync_start - mode->hdisplay;
hdmi_writeb(hdmi, h_de_hs >> 8, HDMI_FC_HSYNCINDELAY1);
hdmi_writeb(hdmi, h_de_hs, HDMI_FC_HSYNCINDELAY0);
v_de_vs = mode->vsync_start - mode->vdisplay;
hdmi_writeb(hdmi, v_de_vs, HDMI_FC_VSYNCINDELAY);
hsync_len = mode->hsync_end - mode->hsync_start;
hdmi_writeb(hdmi, hsync_len >> 8, HDMI_FC_HSYNCINWIDTH1);
hdmi_writeb(hdmi, hsync_len, HDMI_FC_HSYNCINWIDTH0);
vsync_len = mode->vsync_end - mode->vsync_start;
hdmi_writeb(hdmi, vsync_len, HDMI_FC_VSYNCINWIDTH);
}
static void dw_hdmi_phy_disable(struct dw_hdmi *hdmi)
{
if (!hdmi->phy_enabled)
return;
dw_hdmi_phy_enable_tmds(hdmi, 0);
dw_hdmi_phy_enable_power(hdmi, 0);
hdmi->phy_enabled = false;
}
static void dw_hdmi_enable_video_path(struct dw_hdmi *hdmi)
{
u8 clkdis;
hdmi_writeb(hdmi, 12, HDMI_FC_CTRLDUR);
hdmi_writeb(hdmi, 32, HDMI_FC_EXCTRLDUR);
hdmi_writeb(hdmi, 1, HDMI_FC_EXCTRLSPAC);
hdmi_writeb(hdmi, 0x0B, HDMI_FC_CH0PREAM);
hdmi_writeb(hdmi, 0x16, HDMI_FC_CH1PREAM);
hdmi_writeb(hdmi, 0x21, HDMI_FC_CH2PREAM);
clkdis = 0x7F;
clkdis &= ~HDMI_MC_CLKDIS_PIXELCLK_DISABLE;
hdmi_writeb(hdmi, clkdis, HDMI_MC_CLKDIS);
clkdis &= ~HDMI_MC_CLKDIS_TMDSCLK_DISABLE;
hdmi_writeb(hdmi, clkdis, HDMI_MC_CLKDIS);
if (is_color_space_conversion(hdmi)) {
clkdis &= ~HDMI_MC_CLKDIS_CSCCLK_DISABLE;
hdmi_writeb(hdmi, clkdis, HDMI_MC_CLKDIS);
}
}
static void hdmi_enable_audio_clk(struct dw_hdmi *hdmi)
{
hdmi_modb(hdmi, 0, HDMI_MC_CLKDIS_AUDCLK_DISABLE, HDMI_MC_CLKDIS);
}
static void dw_hdmi_clear_overflow(struct dw_hdmi *hdmi)
{
int count;
u8 val;
hdmi_writeb(hdmi, (u8)~HDMI_MC_SWRSTZ_TMDSSWRST_REQ, HDMI_MC_SWRSTZ);
val = hdmi_readb(hdmi, HDMI_FC_INVIDCONF);
if (hdmi->dev_type == IMX6DL_HDMI) {
hdmi_writeb(hdmi, val, HDMI_FC_INVIDCONF);
return;
}
for (count = 0; count < 4; count++)
hdmi_writeb(hdmi, val, HDMI_FC_INVIDCONF);
}
static void hdmi_enable_overflow_interrupts(struct dw_hdmi *hdmi)
{
hdmi_writeb(hdmi, 0, HDMI_FC_MASK2);
hdmi_writeb(hdmi, 0, HDMI_IH_MUTE_FC_STAT2);
}
static void hdmi_disable_overflow_interrupts(struct dw_hdmi *hdmi)
{
hdmi_writeb(hdmi, HDMI_IH_MUTE_FC_STAT2_OVERFLOW_MASK,
HDMI_IH_MUTE_FC_STAT2);
}
static int dw_hdmi_setup(struct dw_hdmi *hdmi, struct drm_display_mode *mode)
{
int ret;
hdmi_disable_overflow_interrupts(hdmi);
hdmi->vic = drm_match_cea_mode(mode);
if (!hdmi->vic) {
dev_dbg(hdmi->dev, "Non-CEA mode used in HDMI\n");
hdmi->hdmi_data.video_mode.mdvi = true;
} else {
dev_dbg(hdmi->dev, "CEA mode used vic=%d\n", hdmi->vic);
hdmi->hdmi_data.video_mode.mdvi = false;
}
if ((hdmi->vic == 6) || (hdmi->vic == 7) ||
(hdmi->vic == 21) || (hdmi->vic == 22) ||
(hdmi->vic == 2) || (hdmi->vic == 3) ||
(hdmi->vic == 17) || (hdmi->vic == 18))
hdmi->hdmi_data.colorimetry = HDMI_COLORIMETRY_ITU_601;
else
hdmi->hdmi_data.colorimetry = HDMI_COLORIMETRY_ITU_709;
if ((hdmi->vic == 10) || (hdmi->vic == 11) ||
(hdmi->vic == 12) || (hdmi->vic == 13) ||
(hdmi->vic == 14) || (hdmi->vic == 15) ||
(hdmi->vic == 25) || (hdmi->vic == 26) ||
(hdmi->vic == 27) || (hdmi->vic == 28) ||
(hdmi->vic == 29) || (hdmi->vic == 30) ||
(hdmi->vic == 35) || (hdmi->vic == 36) ||
(hdmi->vic == 37) || (hdmi->vic == 38))
hdmi->hdmi_data.video_mode.mpixelrepetitionoutput = 1;
else
hdmi->hdmi_data.video_mode.mpixelrepetitionoutput = 0;
hdmi->hdmi_data.video_mode.mpixelrepetitioninput = 0;
hdmi->hdmi_data.enc_in_format = RGB;
hdmi->hdmi_data.enc_out_format = RGB;
hdmi->hdmi_data.enc_color_depth = 8;
hdmi->hdmi_data.pix_repet_factor = 0;
hdmi->hdmi_data.hdcp_enable = 0;
hdmi->hdmi_data.video_mode.mdataenablepolarity = true;
hdmi_av_composer(hdmi, mode);
ret = dw_hdmi_phy_init(hdmi);
if (ret)
return ret;
dw_hdmi_enable_video_path(hdmi);
if (hdmi->hdmi_data.video_mode.mdvi) {
dev_dbg(hdmi->dev, "%s DVI mode\n", __func__);
} else {
dev_dbg(hdmi->dev, "%s CEA mode\n", __func__);
hdmi_clk_regenerator_update_pixel_clock(hdmi);
hdmi_enable_audio_clk(hdmi);
hdmi_config_AVI(hdmi);
}
hdmi_video_packetize(hdmi);
hdmi_video_csc(hdmi);
hdmi_video_sample(hdmi);
hdmi_tx_hdcp_config(hdmi);
dw_hdmi_clear_overflow(hdmi);
if (hdmi->cable_plugin && !hdmi->hdmi_data.video_mode.mdvi)
hdmi_enable_overflow_interrupts(hdmi);
return 0;
}
static int dw_hdmi_fb_registered(struct dw_hdmi *hdmi)
{
hdmi_writeb(hdmi, HDMI_PHY_I2CM_INT_ADDR_DONE_POL,
HDMI_PHY_I2CM_INT_ADDR);
hdmi_writeb(hdmi, HDMI_PHY_I2CM_CTLINT_ADDR_NAC_POL |
HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL,
HDMI_PHY_I2CM_CTLINT_ADDR);
hdmi_writeb(hdmi, (u8)~HDMI_PHY_HPD, HDMI_PHY_MASK0);
hdmi_writeb(hdmi, HDMI_IH_PHY_STAT0_HPD, HDMI_IH_PHY_STAT0);
return 0;
}
static void initialize_hdmi_ih_mutes(struct dw_hdmi *hdmi)
{
u8 ih_mute;
ih_mute = hdmi_readb(hdmi, HDMI_IH_MUTE) |
HDMI_IH_MUTE_MUTE_WAKEUP_INTERRUPT |
HDMI_IH_MUTE_MUTE_ALL_INTERRUPT;
hdmi_writeb(hdmi, ih_mute, HDMI_IH_MUTE);
hdmi_writeb(hdmi, 0xff, HDMI_VP_MASK);
hdmi_writeb(hdmi, 0xff, HDMI_FC_MASK0);
hdmi_writeb(hdmi, 0xff, HDMI_FC_MASK1);
hdmi_writeb(hdmi, 0xff, HDMI_FC_MASK2);
hdmi_writeb(hdmi, 0xff, HDMI_PHY_MASK0);
hdmi_writeb(hdmi, 0xff, HDMI_PHY_I2CM_INT_ADDR);
hdmi_writeb(hdmi, 0xff, HDMI_PHY_I2CM_CTLINT_ADDR);
hdmi_writeb(hdmi, 0xff, HDMI_AUD_INT);
hdmi_writeb(hdmi, 0xff, HDMI_AUD_SPDIFINT);
hdmi_writeb(hdmi, 0xff, HDMI_AUD_HBR_MASK);
hdmi_writeb(hdmi, 0xff, HDMI_GP_MASK);
hdmi_writeb(hdmi, 0xff, HDMI_A_APIINTMSK);
hdmi_writeb(hdmi, 0xff, HDMI_CEC_MASK);
hdmi_writeb(hdmi, 0xff, HDMI_I2CM_INT);
hdmi_writeb(hdmi, 0xff, HDMI_I2CM_CTLINT);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_FC_STAT0);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_FC_STAT1);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_FC_STAT2);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_AS_STAT0);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_PHY_STAT0);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_I2CM_STAT0);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_CEC_STAT0);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_VP_STAT0);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_I2CMPHY_STAT0);
hdmi_writeb(hdmi, 0xff, HDMI_IH_MUTE_AHBDMAAUD_STAT0);
ih_mute &= ~(HDMI_IH_MUTE_MUTE_WAKEUP_INTERRUPT |
HDMI_IH_MUTE_MUTE_ALL_INTERRUPT);
hdmi_writeb(hdmi, ih_mute, HDMI_IH_MUTE);
}
static void dw_hdmi_poweron(struct dw_hdmi *hdmi)
{
dw_hdmi_setup(hdmi, &hdmi->previous_mode);
}
static void dw_hdmi_poweroff(struct dw_hdmi *hdmi)
{
dw_hdmi_phy_disable(hdmi);
}
static void dw_hdmi_bridge_mode_set(struct drm_bridge *bridge,
struct drm_display_mode *orig_mode,
struct drm_display_mode *mode)
{
struct dw_hdmi *hdmi = bridge->driver_private;
dw_hdmi_setup(hdmi, mode);
memcpy(&hdmi->previous_mode, mode, sizeof(hdmi->previous_mode));
}
static bool dw_hdmi_bridge_mode_fixup(struct drm_bridge *bridge,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void dw_hdmi_bridge_disable(struct drm_bridge *bridge)
{
struct dw_hdmi *hdmi = bridge->driver_private;
dw_hdmi_poweroff(hdmi);
}
static void dw_hdmi_bridge_enable(struct drm_bridge *bridge)
{
struct dw_hdmi *hdmi = bridge->driver_private;
dw_hdmi_poweron(hdmi);
}
static void dw_hdmi_bridge_nop(struct drm_bridge *bridge)
{
}
static enum drm_connector_status
dw_hdmi_connector_detect(struct drm_connector *connector, bool force)
{
struct dw_hdmi *hdmi = container_of(connector, struct dw_hdmi,
connector);
return hdmi_readb(hdmi, HDMI_PHY_STAT0) & HDMI_PHY_HPD ?
connector_status_connected : connector_status_disconnected;
}
static int dw_hdmi_connector_get_modes(struct drm_connector *connector)
{
struct dw_hdmi *hdmi = container_of(connector, struct dw_hdmi,
connector);
struct edid *edid;
int ret = 0;
if (!hdmi->ddc)
return 0;
edid = drm_get_edid(connector, hdmi->ddc);
if (edid) {
dev_dbg(hdmi->dev, "got edid: width[%d] x height[%d]\n",
edid->width_cm, edid->height_cm);
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
kfree(edid);
} else {
dev_dbg(hdmi->dev, "failed to get edid\n");
}
return ret;
}
static enum drm_mode_status
dw_hdmi_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct dw_hdmi *hdmi = container_of(connector,
struct dw_hdmi, connector);
enum drm_mode_status mode_status = MODE_OK;
if (hdmi->plat_data->mode_valid)
mode_status = hdmi->plat_data->mode_valid(connector, mode);
return mode_status;
}
static struct drm_encoder *dw_hdmi_connector_best_encoder(struct drm_connector
*connector)
{
struct dw_hdmi *hdmi = container_of(connector, struct dw_hdmi,
connector);
return hdmi->encoder;
}
static void dw_hdmi_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static irqreturn_t dw_hdmi_hardirq(int irq, void *dev_id)
{
struct dw_hdmi *hdmi = dev_id;
u8 intr_stat;
intr_stat = hdmi_readb(hdmi, HDMI_IH_PHY_STAT0);
if (intr_stat)
hdmi_writeb(hdmi, ~0, HDMI_IH_MUTE_PHY_STAT0);
return intr_stat ? IRQ_WAKE_THREAD : IRQ_NONE;
}
static irqreturn_t dw_hdmi_irq(int irq, void *dev_id)
{
struct dw_hdmi *hdmi = dev_id;
u8 intr_stat;
u8 phy_int_pol;
intr_stat = hdmi_readb(hdmi, HDMI_IH_PHY_STAT0);
phy_int_pol = hdmi_readb(hdmi, HDMI_PHY_POL0);
if (intr_stat & HDMI_IH_PHY_STAT0_HPD) {
if (phy_int_pol & HDMI_PHY_HPD) {
dev_dbg(hdmi->dev, "EVENT=plugin\n");
hdmi_modb(hdmi, 0, HDMI_PHY_HPD, HDMI_PHY_POL0);
dw_hdmi_poweron(hdmi);
} else {
dev_dbg(hdmi->dev, "EVENT=plugout\n");
hdmi_modb(hdmi, HDMI_PHY_HPD, HDMI_PHY_HPD,
HDMI_PHY_POL0);
dw_hdmi_poweroff(hdmi);
}
drm_helper_hpd_irq_event(hdmi->connector.dev);
}
hdmi_writeb(hdmi, intr_stat, HDMI_IH_PHY_STAT0);
hdmi_writeb(hdmi, ~HDMI_IH_PHY_STAT0_HPD, HDMI_IH_MUTE_PHY_STAT0);
return IRQ_HANDLED;
}
static int dw_hdmi_register(struct drm_device *drm, struct dw_hdmi *hdmi)
{
struct drm_encoder *encoder = hdmi->encoder;
struct drm_bridge *bridge;
int ret;
bridge = devm_kzalloc(drm->dev, sizeof(*bridge), GFP_KERNEL);
if (!bridge) {
DRM_ERROR("Failed to allocate drm bridge\n");
return -ENOMEM;
}
hdmi->bridge = bridge;
bridge->driver_private = hdmi;
bridge->funcs = &dw_hdmi_bridge_funcs;
ret = drm_bridge_attach(drm, bridge);
if (ret) {
DRM_ERROR("Failed to initialize bridge with drm\n");
return -EINVAL;
}
encoder->bridge = bridge;
hdmi->connector.polled = DRM_CONNECTOR_POLL_HPD;
drm_connector_helper_add(&hdmi->connector,
&dw_hdmi_connector_helper_funcs);
drm_connector_init(drm, &hdmi->connector, &dw_hdmi_connector_funcs,
DRM_MODE_CONNECTOR_HDMIA);
hdmi->connector.encoder = encoder;
drm_mode_connector_attach_encoder(&hdmi->connector, encoder);
return 0;
}
int dw_hdmi_bind(struct device *dev, struct device *master,
void *data, struct drm_encoder *encoder,
struct resource *iores, int irq,
const struct dw_hdmi_plat_data *plat_data)
{
struct drm_device *drm = data;
struct device_node *np = dev->of_node;
struct device_node *ddc_node;
struct dw_hdmi *hdmi;
int ret;
u32 val = 1;
hdmi = devm_kzalloc(dev, sizeof(*hdmi), GFP_KERNEL);
if (!hdmi)
return -ENOMEM;
hdmi->plat_data = plat_data;
hdmi->dev = dev;
hdmi->dev_type = plat_data->dev_type;
hdmi->sample_rate = 48000;
hdmi->ratio = 100;
hdmi->encoder = encoder;
mutex_init(&hdmi->audio_mutex);
of_property_read_u32(np, "reg-io-width", &val);
switch (val) {
case 4:
hdmi->write = dw_hdmi_writel;
hdmi->read = dw_hdmi_readl;
break;
case 1:
hdmi->write = dw_hdmi_writeb;
hdmi->read = dw_hdmi_readb;
break;
default:
dev_err(dev, "reg-io-width must be 1 or 4\n");
return -EINVAL;
}
ddc_node = of_parse_phandle(np, "ddc-i2c-bus", 0);
if (ddc_node) {
hdmi->ddc = of_find_i2c_adapter_by_node(ddc_node);
of_node_put(ddc_node);
if (!hdmi->ddc) {
dev_dbg(hdmi->dev, "failed to read ddc node\n");
return -EPROBE_DEFER;
}
} else {
dev_dbg(hdmi->dev, "no ddc property found\n");
}
hdmi->regs = devm_ioremap_resource(dev, iores);
if (IS_ERR(hdmi->regs))
return PTR_ERR(hdmi->regs);
hdmi->isfr_clk = devm_clk_get(hdmi->dev, "isfr");
if (IS_ERR(hdmi->isfr_clk)) {
ret = PTR_ERR(hdmi->isfr_clk);
dev_err(hdmi->dev, "Unable to get HDMI isfr clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(hdmi->isfr_clk);
if (ret) {
dev_err(hdmi->dev, "Cannot enable HDMI isfr clock: %d\n", ret);
return ret;
}
hdmi->iahb_clk = devm_clk_get(hdmi->dev, "iahb");
if (IS_ERR(hdmi->iahb_clk)) {
ret = PTR_ERR(hdmi->iahb_clk);
dev_err(hdmi->dev, "Unable to get HDMI iahb clk: %d\n", ret);
goto err_isfr;
}
ret = clk_prepare_enable(hdmi->iahb_clk);
if (ret) {
dev_err(hdmi->dev, "Cannot enable HDMI iahb clock: %d\n", ret);
goto err_isfr;
}
dev_info(dev,
"Detected HDMI controller 0x%x:0x%x:0x%x:0x%x\n",
hdmi_readb(hdmi, HDMI_DESIGN_ID),
hdmi_readb(hdmi, HDMI_REVISION_ID),
hdmi_readb(hdmi, HDMI_PRODUCT_ID0),
hdmi_readb(hdmi, HDMI_PRODUCT_ID1));
initialize_hdmi_ih_mutes(hdmi);
ret = devm_request_threaded_irq(dev, irq, dw_hdmi_hardirq,
dw_hdmi_irq, IRQF_SHARED,
dev_name(dev), hdmi);
if (ret)
goto err_iahb;
hdmi_init_clk_regenerator(hdmi);
hdmi_writeb(hdmi, HDMI_PHY_HPD, HDMI_PHY_POL0);
hdmi_writeb(hdmi, HDMI_IH_PHY_STAT0_HPD, HDMI_IH_PHY_STAT0);
ret = dw_hdmi_fb_registered(hdmi);
if (ret)
goto err_iahb;
ret = dw_hdmi_register(drm, hdmi);
if (ret)
goto err_iahb;
hdmi_writeb(hdmi, ~HDMI_IH_PHY_STAT0_HPD, HDMI_IH_MUTE_PHY_STAT0);
dev_set_drvdata(dev, hdmi);
return 0;
err_iahb:
clk_disable_unprepare(hdmi->iahb_clk);
err_isfr:
clk_disable_unprepare(hdmi->isfr_clk);
return ret;
}
void dw_hdmi_unbind(struct device *dev, struct device *master, void *data)
{
struct dw_hdmi *hdmi = dev_get_drvdata(dev);
hdmi_writeb(hdmi, ~0, HDMI_IH_MUTE_PHY_STAT0);
hdmi->connector.funcs->destroy(&hdmi->connector);
hdmi->encoder->funcs->destroy(hdmi->encoder);
clk_disable_unprepare(hdmi->iahb_clk);
clk_disable_unprepare(hdmi->isfr_clk);
i2c_put_adapter(hdmi->ddc);
}
