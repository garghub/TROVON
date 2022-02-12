static inline struct hdmi_context *encoder_to_hdmi(struct drm_encoder *e)
{
return container_of(e, struct hdmi_context, encoder);
}
static inline struct hdmi_context *connector_to_hdmi(struct drm_connector *c)
{
return container_of(c, struct hdmi_context, connector);
}
static inline u32 hdmi_map_reg(struct hdmi_context *hdata, u32 reg_id)
{
if ((reg_id & 0xffff0000) == HDMI_MAPPED_BASE)
return hdmi_reg_map[reg_id & 0xffff][hdata->drv_data->type];
return reg_id;
}
static inline u32 hdmi_reg_read(struct hdmi_context *hdata, u32 reg_id)
{
return readl(hdata->regs + hdmi_map_reg(hdata, reg_id));
}
static inline void hdmi_reg_writeb(struct hdmi_context *hdata,
u32 reg_id, u8 value)
{
writel(value, hdata->regs + hdmi_map_reg(hdata, reg_id));
}
static inline void hdmi_reg_writev(struct hdmi_context *hdata, u32 reg_id,
int bytes, u32 val)
{
reg_id = hdmi_map_reg(hdata, reg_id);
while (--bytes >= 0) {
writel(val & 0xff, hdata->regs + reg_id);
val >>= 8;
reg_id += 4;
}
}
static inline void hdmi_reg_write_buf(struct hdmi_context *hdata, u32 reg_id,
u8 *buf, int size)
{
for (reg_id = hdmi_map_reg(hdata, reg_id); size; --size, reg_id += 4)
writel(*buf++, hdata->regs + reg_id);
}
static inline void hdmi_reg_writemask(struct hdmi_context *hdata,
u32 reg_id, u32 value, u32 mask)
{
u32 old;
reg_id = hdmi_map_reg(hdata, reg_id);
old = readl(hdata->regs + reg_id);
value = (value & mask) | (old & ~mask);
writel(value, hdata->regs + reg_id);
}
static int hdmiphy_reg_write_buf(struct hdmi_context *hdata,
u32 reg_offset, const u8 *buf, u32 len)
{
if ((reg_offset + len) > 32)
return -EINVAL;
if (hdata->hdmiphy_port) {
int ret;
ret = i2c_master_send(hdata->hdmiphy_port, buf, len);
if (ret == len)
return 0;
return ret;
} else {
int i;
for (i = 0; i < len; i++)
writel(buf[i], hdata->regs_hdmiphy +
((reg_offset + i)<<2));
return 0;
}
}
static int hdmi_clk_enable_gates(struct hdmi_context *hdata)
{
int i, ret;
for (i = 0; i < hdata->drv_data->clk_gates.count; ++i) {
ret = clk_prepare_enable(hdata->clk_gates[i]);
if (!ret)
continue;
dev_err(hdata->dev, "Cannot enable clock '%s', %d\n",
hdata->drv_data->clk_gates.data[i], ret);
while (i--)
clk_disable_unprepare(hdata->clk_gates[i]);
return ret;
}
return 0;
}
static void hdmi_clk_disable_gates(struct hdmi_context *hdata)
{
int i = hdata->drv_data->clk_gates.count;
while (i--)
clk_disable_unprepare(hdata->clk_gates[i]);
}
static int hdmi_clk_set_parents(struct hdmi_context *hdata, bool to_phy)
{
struct device *dev = hdata->dev;
int ret = 0;
int i;
for (i = 0; i < hdata->drv_data->clk_muxes.count; i += 3) {
struct clk **c = &hdata->clk_muxes[i];
ret = clk_set_parent(c[2], c[to_phy]);
if (!ret)
continue;
dev_err(dev, "Cannot set clock parent of '%s' to '%s', %d\n",
hdata->drv_data->clk_muxes.data[i + 2],
hdata->drv_data->clk_muxes.data[i + to_phy], ret);
}
return ret;
}
static void hdmi_reg_infoframes(struct hdmi_context *hdata)
{
union hdmi_infoframe frm;
u8 buf[25];
int ret;
if (hdata->dvi_mode) {
hdmi_reg_writeb(hdata, HDMI_AVI_CON,
HDMI_AVI_CON_DO_NOT_TRANSMIT);
hdmi_reg_writeb(hdata, HDMI_VSI_CON,
HDMI_VSI_CON_DO_NOT_TRANSMIT);
hdmi_reg_writeb(hdata, HDMI_AUI_CON, HDMI_AUI_CON_NO_TRAN);
return;
}
ret = drm_hdmi_avi_infoframe_from_display_mode(&frm.avi,
&hdata->current_mode, false);
if (!ret)
ret = hdmi_avi_infoframe_pack(&frm.avi, buf, sizeof(buf));
if (ret > 0) {
hdmi_reg_writeb(hdata, HDMI_AVI_CON, HDMI_AVI_CON_EVERY_VSYNC);
hdmi_reg_write_buf(hdata, HDMI_AVI_HEADER0, buf, ret);
} else {
DRM_INFO("%s: invalid AVI infoframe (%d)\n", __func__, ret);
}
ret = drm_hdmi_vendor_infoframe_from_display_mode(&frm.vendor.hdmi,
&hdata->current_mode);
if (!ret)
ret = hdmi_vendor_infoframe_pack(&frm.vendor.hdmi, buf,
sizeof(buf));
if (ret > 0) {
hdmi_reg_writeb(hdata, HDMI_VSI_CON, HDMI_VSI_CON_EVERY_VSYNC);
hdmi_reg_write_buf(hdata, HDMI_VSI_HEADER0, buf, 3);
hdmi_reg_write_buf(hdata, HDMI_VSI_DATA(0), buf + 3, ret - 3);
}
ret = hdmi_audio_infoframe_init(&frm.audio);
if (!ret) {
frm.audio.channels = 2;
ret = hdmi_audio_infoframe_pack(&frm.audio, buf, sizeof(buf));
}
if (ret > 0) {
hdmi_reg_writeb(hdata, HDMI_AUI_CON, HDMI_AUI_CON_EVERY_VSYNC);
hdmi_reg_write_buf(hdata, HDMI_AUI_HEADER0, buf, ret);
}
}
static enum drm_connector_status hdmi_detect(struct drm_connector *connector,
bool force)
{
struct hdmi_context *hdata = connector_to_hdmi(connector);
if (gpiod_get_value(hdata->hpd_gpio))
return connector_status_connected;
cec_notifier_set_phys_addr(hdata->notifier, CEC_PHYS_ADDR_INVALID);
return connector_status_disconnected;
}
static void hdmi_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static int hdmi_get_modes(struct drm_connector *connector)
{
struct hdmi_context *hdata = connector_to_hdmi(connector);
struct edid *edid;
int ret;
if (!hdata->ddc_adpt)
return -ENODEV;
edid = drm_get_edid(connector, hdata->ddc_adpt);
if (!edid)
return -ENODEV;
hdata->dvi_mode = !drm_detect_hdmi_monitor(edid);
DRM_DEBUG_KMS("%s : width[%d] x height[%d]\n",
(hdata->dvi_mode ? "dvi monitor" : "hdmi monitor"),
edid->width_cm, edid->height_cm);
drm_mode_connector_update_edid_property(connector, edid);
cec_notifier_set_phys_addr_from_edid(hdata->notifier, edid);
ret = drm_add_edid_modes(connector, edid);
kfree(edid);
return ret;
}
static int hdmi_find_phy_conf(struct hdmi_context *hdata, u32 pixel_clock)
{
const struct hdmiphy_configs *confs = &hdata->drv_data->phy_confs;
int i;
for (i = 0; i < confs->count; i++)
if (confs->data[i].pixel_clock == pixel_clock)
return i;
DRM_DEBUG_KMS("Could not find phy config for %d\n", pixel_clock);
return -EINVAL;
}
static int hdmi_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct hdmi_context *hdata = connector_to_hdmi(connector);
int ret;
DRM_DEBUG_KMS("xres=%d, yres=%d, refresh=%d, intl=%d clock=%d\n",
mode->hdisplay, mode->vdisplay, mode->vrefresh,
(mode->flags & DRM_MODE_FLAG_INTERLACE) ? true :
false, mode->clock * 1000);
ret = hdmi_find_phy_conf(hdata, mode->clock * 1000);
if (ret < 0)
return MODE_BAD;
return MODE_OK;
}
static int hdmi_create_connector(struct drm_encoder *encoder)
{
struct hdmi_context *hdata = encoder_to_hdmi(encoder);
struct drm_connector *connector = &hdata->connector;
int ret;
connector->interlace_allowed = true;
connector->polled = DRM_CONNECTOR_POLL_HPD;
ret = drm_connector_init(hdata->drm_dev, connector,
&hdmi_connector_funcs, DRM_MODE_CONNECTOR_HDMIA);
if (ret) {
DRM_ERROR("Failed to initialize connector with drm\n");
return ret;
}
drm_connector_helper_add(connector, &hdmi_connector_helper_funcs);
drm_mode_connector_attach_encoder(connector, encoder);
if (hdata->bridge) {
encoder->bridge = hdata->bridge;
hdata->bridge->encoder = encoder;
ret = drm_bridge_attach(encoder, hdata->bridge, NULL);
if (ret)
DRM_ERROR("Failed to attach bridge\n");
}
return ret;
}
static bool hdmi_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct drm_connector *connector;
struct drm_display_mode *m;
struct drm_connector_list_iter conn_iter;
int mode_ok;
drm_mode_set_crtcinfo(adjusted_mode, 0);
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
if (connector->encoder == encoder)
break;
}
if (connector)
drm_connector_get(connector);
drm_connector_list_iter_end(&conn_iter);
if (!connector)
return true;
mode_ok = hdmi_mode_valid(connector, adjusted_mode);
if (mode_ok == MODE_OK)
goto cleanup;
list_for_each_entry(m, &connector->modes, head) {
mode_ok = hdmi_mode_valid(connector, m);
if (mode_ok == MODE_OK) {
DRM_INFO("desired mode doesn't exist so\n");
DRM_INFO("use the most suitable mode among modes.\n");
DRM_DEBUG_KMS("Adjusted Mode: [%d]x[%d] [%d]Hz\n",
m->hdisplay, m->vdisplay, m->vrefresh);
drm_mode_copy(adjusted_mode, m);
break;
}
}
cleanup:
drm_connector_put(connector);
return true;
}
static void hdmi_reg_acr(struct hdmi_context *hdata, u32 freq)
{
u32 n, cts;
cts = (freq % 9) ? 27000 : 30000;
n = 128 * freq / (27000000 / cts);
hdmi_reg_writev(hdata, HDMI_ACR_N0, 3, n);
hdmi_reg_writev(hdata, HDMI_ACR_MCTS0, 3, cts);
hdmi_reg_writev(hdata, HDMI_ACR_CTS0, 3, cts);
hdmi_reg_writeb(hdata, HDMI_ACR_CON, 4);
}
static void hdmi_audio_init(struct hdmi_context *hdata)
{
u32 sample_rate, bits_per_sample;
u32 data_num, bit_ch, sample_frq;
u32 val;
sample_rate = 44100;
bits_per_sample = 16;
switch (bits_per_sample) {
case 20:
data_num = 2;
bit_ch = 1;
break;
case 24:
data_num = 3;
bit_ch = 1;
break;
default:
data_num = 1;
bit_ch = 0;
break;
}
hdmi_reg_acr(hdata, sample_rate);
hdmi_reg_writeb(hdata, HDMI_I2S_MUX_CON, HDMI_I2S_IN_DISABLE
| HDMI_I2S_AUD_I2S | HDMI_I2S_CUV_I2S_ENABLE
| HDMI_I2S_MUX_ENABLE);
hdmi_reg_writeb(hdata, HDMI_I2S_MUX_CH, HDMI_I2S_CH0_EN
| HDMI_I2S_CH1_EN | HDMI_I2S_CH2_EN);
hdmi_reg_writeb(hdata, HDMI_I2S_MUX_CUV, HDMI_I2S_CUV_RL_EN);
sample_frq = (sample_rate == 44100) ? 0 :
(sample_rate == 48000) ? 2 :
(sample_rate == 32000) ? 3 :
(sample_rate == 96000) ? 0xa : 0x0;
hdmi_reg_writeb(hdata, HDMI_I2S_CLK_CON, HDMI_I2S_CLK_DIS);
hdmi_reg_writeb(hdata, HDMI_I2S_CLK_CON, HDMI_I2S_CLK_EN);
val = hdmi_reg_read(hdata, HDMI_I2S_DSD_CON) | 0x01;
hdmi_reg_writeb(hdata, HDMI_I2S_DSD_CON, val);
hdmi_reg_writeb(hdata, HDMI_I2S_PIN_SEL_0, HDMI_I2S_SEL_SCLK(5)
| HDMI_I2S_SEL_LRCK(6));
hdmi_reg_writeb(hdata, HDMI_I2S_PIN_SEL_1, HDMI_I2S_SEL_SDATA1(1)
| HDMI_I2S_SEL_SDATA2(4));
hdmi_reg_writeb(hdata, HDMI_I2S_PIN_SEL_2, HDMI_I2S_SEL_SDATA3(1)
| HDMI_I2S_SEL_SDATA2(2));
hdmi_reg_writeb(hdata, HDMI_I2S_PIN_SEL_3, HDMI_I2S_SEL_DSD(0));
hdmi_reg_writeb(hdata, HDMI_I2S_CON_1, HDMI_I2S_SCLK_FALLING_EDGE
| HDMI_I2S_L_CH_LOW_POL);
hdmi_reg_writeb(hdata, HDMI_I2S_CON_2, HDMI_I2S_MSB_FIRST_MODE
| HDMI_I2S_SET_BIT_CH(bit_ch)
| HDMI_I2S_SET_SDATA_BIT(data_num)
| HDMI_I2S_BASIC_FORMAT);
hdmi_reg_writeb(hdata, HDMI_I2S_CH_ST_0, HDMI_I2S_CH_STATUS_MODE_0
| HDMI_I2S_2AUD_CH_WITHOUT_PREEMPH
| HDMI_I2S_COPYRIGHT
| HDMI_I2S_LINEAR_PCM
| HDMI_I2S_CONSUMER_FORMAT);
hdmi_reg_writeb(hdata, HDMI_I2S_CH_ST_1, HDMI_I2S_CD_PLAYER);
hdmi_reg_writeb(hdata, HDMI_I2S_CH_ST_2, HDMI_I2S_SET_SOURCE_NUM(0));
hdmi_reg_writeb(hdata, HDMI_I2S_CH_ST_3, HDMI_I2S_CLK_ACCUR_LEVEL_2
| HDMI_I2S_SET_SMP_FREQ(sample_frq));
hdmi_reg_writeb(hdata, HDMI_I2S_CH_ST_4,
HDMI_I2S_ORG_SMP_FREQ_44_1
| HDMI_I2S_WORD_LEN_MAX24_24BITS
| HDMI_I2S_WORD_LEN_MAX_24BITS);
hdmi_reg_writeb(hdata, HDMI_I2S_CH_ST_CON, HDMI_I2S_CH_STATUS_RELOAD);
}
static void hdmi_audio_control(struct hdmi_context *hdata, bool onoff)
{
if (hdata->dvi_mode)
return;
hdmi_reg_writeb(hdata, HDMI_AUI_CON, onoff ? 2 : 0);
hdmi_reg_writemask(hdata, HDMI_CON_0, onoff ?
HDMI_ASP_EN : HDMI_ASP_DIS, HDMI_ASP_MASK);
}
static void hdmi_start(struct hdmi_context *hdata, bool start)
{
u32 val = start ? HDMI_TG_EN : 0;
if (hdata->current_mode.flags & DRM_MODE_FLAG_INTERLACE)
val |= HDMI_FIELD_EN;
hdmi_reg_writemask(hdata, HDMI_CON_0, val, HDMI_EN);
hdmi_reg_writemask(hdata, HDMI_TG_CMD, val, HDMI_TG_EN | HDMI_FIELD_EN);
}
static void hdmi_conf_init(struct hdmi_context *hdata)
{
hdmi_reg_writemask(hdata, HDMI_INTC_CON, 0, HDMI_INTC_EN_GLOBAL |
HDMI_INTC_EN_HPD_PLUG | HDMI_INTC_EN_HPD_UNPLUG);
hdmi_reg_writemask(hdata, HDMI_MODE_SEL,
HDMI_MODE_HDMI_EN, HDMI_MODE_MASK);
hdmi_reg_writeb(hdata, HDMI_CON_2, 0);
hdmi_reg_writemask(hdata, HDMI_CON_0, 0, HDMI_BLUE_SCR_EN);
if (hdata->dvi_mode) {
hdmi_reg_writemask(hdata, HDMI_MODE_SEL,
HDMI_MODE_DVI_EN, HDMI_MODE_MASK);
hdmi_reg_writeb(hdata, HDMI_CON_2,
HDMI_VID_PREAMBLE_DIS | HDMI_GUARD_BAND_DIS);
}
if (hdata->drv_data->type == HDMI_TYPE13) {
hdmi_reg_writeb(hdata, HDMI_V13_BLUE_SCREEN_0, 0x12);
hdmi_reg_writeb(hdata, HDMI_V13_BLUE_SCREEN_1, 0x34);
hdmi_reg_writeb(hdata, HDMI_V13_BLUE_SCREEN_2, 0x56);
hdmi_reg_writeb(hdata, HDMI_V13_AVI_CON, 0x02);
hdmi_reg_writeb(hdata, HDMI_V13_AVI_BYTE(0), 0 << 5);
hdmi_reg_writemask(hdata, HDMI_CON_1, 0x10 << 5, 0x11 << 5);
hdmi_reg_writeb(hdata, HDMI_V13_SPD_CON, 0x02);
hdmi_reg_writeb(hdata, HDMI_V13_AUI_CON, 0x02);
hdmi_reg_writeb(hdata, HDMI_V13_ACR_CON, 0x04);
} else {
hdmi_reg_infoframes(hdata);
hdmi_reg_writemask(hdata, HDMI_CON_1, 2, 3 << 5);
}
}
static void hdmiphy_wait_for_pll(struct hdmi_context *hdata)
{
int tries;
for (tries = 0; tries < 10; ++tries) {
u32 val = hdmi_reg_read(hdata, HDMI_PHY_STATUS);
if (val & HDMI_PHY_STATUS_READY) {
DRM_DEBUG_KMS("PLL stabilized after %d tries\n", tries);
return;
}
usleep_range(10, 20);
}
DRM_ERROR("PLL could not reach steady state\n");
}
static void hdmi_v13_mode_apply(struct hdmi_context *hdata)
{
struct drm_display_mode *m = &hdata->current_mode;
unsigned int val;
hdmi_reg_writev(hdata, HDMI_H_BLANK_0, 2, m->htotal - m->hdisplay);
hdmi_reg_writev(hdata, HDMI_V13_H_V_LINE_0, 3,
(m->htotal << 12) | m->vtotal);
val = (m->flags & DRM_MODE_FLAG_NVSYNC) ? 1 : 0;
hdmi_reg_writev(hdata, HDMI_VSYNC_POL, 1, val);
val = (m->flags & DRM_MODE_FLAG_INTERLACE) ? 1 : 0;
hdmi_reg_writev(hdata, HDMI_INT_PRO_MODE, 1, val);
val = (m->hsync_start - m->hdisplay - 2);
val |= ((m->hsync_end - m->hdisplay - 2) << 10);
val |= ((m->flags & DRM_MODE_FLAG_NHSYNC) ? 1 : 0)<<20;
hdmi_reg_writev(hdata, HDMI_V13_H_SYNC_GEN_0, 3, val);
if (m->flags & DRM_MODE_FLAG_INTERLACE) {
val = ((m->vsync_end - m->vdisplay) / 2);
val |= ((m->vsync_start - m->vdisplay) / 2) << 12;
hdmi_reg_writev(hdata, HDMI_V13_V_SYNC_GEN_1_0, 3, val);
val = m->vtotal / 2;
val |= ((m->vtotal - m->vdisplay) / 2) << 11;
hdmi_reg_writev(hdata, HDMI_V13_V_BLANK_0, 3, val);
val = (m->vtotal +
((m->vsync_end - m->vsync_start) * 4) + 5) / 2;
val |= m->vtotal << 11;
hdmi_reg_writev(hdata, HDMI_V13_V_BLANK_F_0, 3, val);
val = ((m->vtotal / 2) + 7);
val |= ((m->vtotal / 2) + 2) << 12;
hdmi_reg_writev(hdata, HDMI_V13_V_SYNC_GEN_2_0, 3, val);
val = ((m->htotal / 2) + (m->hsync_start - m->hdisplay));
val |= ((m->htotal / 2) +
(m->hsync_start - m->hdisplay)) << 12;
hdmi_reg_writev(hdata, HDMI_V13_V_SYNC_GEN_3_0, 3, val);
hdmi_reg_writev(hdata, HDMI_TG_VACT_ST_L, 2,
(m->vtotal - m->vdisplay) / 2);
hdmi_reg_writev(hdata, HDMI_TG_VACT_SZ_L, 2, m->vdisplay / 2);
hdmi_reg_writev(hdata, HDMI_TG_VACT_ST2_L, 2, 0x249);
} else {
val = m->vtotal;
val |= (m->vtotal - m->vdisplay) << 11;
hdmi_reg_writev(hdata, HDMI_V13_V_BLANK_0, 3, val);
hdmi_reg_writev(hdata, HDMI_V13_V_BLANK_F_0, 3, 0);
val = (m->vsync_end - m->vdisplay);
val |= ((m->vsync_start - m->vdisplay) << 12);
hdmi_reg_writev(hdata, HDMI_V13_V_SYNC_GEN_1_0, 3, val);
hdmi_reg_writev(hdata, HDMI_V13_V_SYNC_GEN_2_0, 3, 0x1001);
hdmi_reg_writev(hdata, HDMI_V13_V_SYNC_GEN_3_0, 3, 0x1001);
hdmi_reg_writev(hdata, HDMI_TG_VACT_ST_L, 2,
m->vtotal - m->vdisplay);
hdmi_reg_writev(hdata, HDMI_TG_VACT_SZ_L, 2, m->vdisplay);
}
hdmi_reg_writev(hdata, HDMI_TG_H_FSZ_L, 2, m->htotal);
hdmi_reg_writev(hdata, HDMI_TG_HACT_ST_L, 2, m->htotal - m->hdisplay);
hdmi_reg_writev(hdata, HDMI_TG_HACT_SZ_L, 2, m->hdisplay);
hdmi_reg_writev(hdata, HDMI_TG_V_FSZ_L, 2, m->vtotal);
}
static void hdmi_v14_mode_apply(struct hdmi_context *hdata)
{
struct drm_display_mode *m = &hdata->current_mode;
hdmi_reg_writev(hdata, HDMI_H_BLANK_0, 2, m->htotal - m->hdisplay);
hdmi_reg_writev(hdata, HDMI_V_LINE_0, 2, m->vtotal);
hdmi_reg_writev(hdata, HDMI_H_LINE_0, 2, m->htotal);
hdmi_reg_writev(hdata, HDMI_HSYNC_POL, 1,
(m->flags & DRM_MODE_FLAG_NHSYNC) ? 1 : 0);
hdmi_reg_writev(hdata, HDMI_VSYNC_POL, 1,
(m->flags & DRM_MODE_FLAG_NVSYNC) ? 1 : 0);
hdmi_reg_writev(hdata, HDMI_INT_PRO_MODE, 1,
(m->flags & DRM_MODE_FLAG_INTERLACE) ? 1 : 0);
if (m->flags & DRM_MODE_FLAG_INTERLACE) {
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_BEF_2_0, 2,
(m->vsync_end - m->vdisplay) / 2);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_BEF_1_0, 2,
(m->vsync_start - m->vdisplay) / 2);
hdmi_reg_writev(hdata, HDMI_V2_BLANK_0, 2, m->vtotal / 2);
hdmi_reg_writev(hdata, HDMI_V1_BLANK_0, 2,
(m->vtotal - m->vdisplay) / 2);
hdmi_reg_writev(hdata, HDMI_V_BLANK_F0_0, 2,
m->vtotal - m->vdisplay / 2);
hdmi_reg_writev(hdata, HDMI_V_BLANK_F1_0, 2, m->vtotal);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_2_0, 2,
(m->vtotal / 2) + 7);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_1_0, 2,
(m->vtotal / 2) + 2);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_PXL_2_0, 2,
(m->htotal / 2) + (m->hsync_start - m->hdisplay));
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_PXL_1_0, 2,
(m->htotal / 2) + (m->hsync_start - m->hdisplay));
hdmi_reg_writev(hdata, HDMI_TG_VACT_ST_L, 2,
(m->vtotal - m->vdisplay) / 2);
hdmi_reg_writev(hdata, HDMI_TG_VACT_SZ_L, 2, m->vdisplay / 2);
hdmi_reg_writev(hdata, HDMI_TG_VACT_ST2_L, 2,
m->vtotal - m->vdisplay / 2);
hdmi_reg_writev(hdata, HDMI_TG_VSYNC2_L, 2,
(m->vtotal / 2) + 1);
hdmi_reg_writev(hdata, HDMI_TG_VSYNC_BOT_HDMI_L, 2,
(m->vtotal / 2) + 1);
hdmi_reg_writev(hdata, HDMI_TG_FIELD_BOT_HDMI_L, 2,
(m->vtotal / 2) + 1);
hdmi_reg_writev(hdata, HDMI_TG_VACT_ST3_L, 2, 0x0);
hdmi_reg_writev(hdata, HDMI_TG_VACT_ST4_L, 2, 0x0);
} else {
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_BEF_2_0, 2,
m->vsync_end - m->vdisplay);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_BEF_1_0, 2,
m->vsync_start - m->vdisplay);
hdmi_reg_writev(hdata, HDMI_V2_BLANK_0, 2, m->vtotal);
hdmi_reg_writev(hdata, HDMI_V1_BLANK_0, 2,
m->vtotal - m->vdisplay);
hdmi_reg_writev(hdata, HDMI_V_BLANK_F0_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_BLANK_F1_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_2_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_1_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_PXL_2_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_PXL_1_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_TG_VACT_ST_L, 2,
m->vtotal - m->vdisplay);
hdmi_reg_writev(hdata, HDMI_TG_VACT_SZ_L, 2, m->vdisplay);
}
hdmi_reg_writev(hdata, HDMI_H_SYNC_START_0, 2,
m->hsync_start - m->hdisplay - 2);
hdmi_reg_writev(hdata, HDMI_H_SYNC_END_0, 2,
m->hsync_end - m->hdisplay - 2);
hdmi_reg_writev(hdata, HDMI_VACT_SPACE_1_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_VACT_SPACE_2_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_VACT_SPACE_3_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_VACT_SPACE_4_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_VACT_SPACE_5_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_VACT_SPACE_6_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_BLANK_F2_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_BLANK_F3_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_BLANK_F4_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_BLANK_F5_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_3_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_4_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_5_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_6_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_PXL_3_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_PXL_4_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_PXL_5_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_V_SYNC_LINE_AFT_PXL_6_0, 2, 0xffff);
hdmi_reg_writev(hdata, HDMI_TG_H_FSZ_L, 2, m->htotal);
hdmi_reg_writev(hdata, HDMI_TG_HACT_ST_L, 2, m->htotal - m->hdisplay);
hdmi_reg_writev(hdata, HDMI_TG_HACT_SZ_L, 2, m->hdisplay);
hdmi_reg_writev(hdata, HDMI_TG_V_FSZ_L, 2, m->vtotal);
if (hdata->drv_data == &exynos5433_hdmi_driver_data)
hdmi_reg_writeb(hdata, HDMI_TG_DECON_EN, 1);
}
static void hdmi_mode_apply(struct hdmi_context *hdata)
{
if (hdata->drv_data->type == HDMI_TYPE13)
hdmi_v13_mode_apply(hdata);
else
hdmi_v14_mode_apply(hdata);
hdmi_start(hdata, true);
}
static void hdmiphy_conf_reset(struct hdmi_context *hdata)
{
hdmi_reg_writemask(hdata, HDMI_CORE_RSTOUT, 0, 1);
usleep_range(10000, 12000);
hdmi_reg_writemask(hdata, HDMI_CORE_RSTOUT, ~0, 1);
usleep_range(10000, 12000);
hdmi_reg_writemask(hdata, HDMI_PHY_RSTOUT, ~0, HDMI_PHY_SW_RSTOUT);
usleep_range(10000, 12000);
hdmi_reg_writemask(hdata, HDMI_PHY_RSTOUT, 0, HDMI_PHY_SW_RSTOUT);
usleep_range(10000, 12000);
}
static void hdmiphy_enable_mode_set(struct hdmi_context *hdata, bool enable)
{
u8 v = enable ? HDMI_PHY_ENABLE_MODE_SET : HDMI_PHY_DISABLE_MODE_SET;
if (hdata->drv_data == &exynos5433_hdmi_driver_data)
writel(v, hdata->regs_hdmiphy + HDMIPHY5433_MODE_SET_DONE);
}
static void hdmiphy_conf_apply(struct hdmi_context *hdata)
{
int ret;
const u8 *phy_conf;
ret = hdmi_find_phy_conf(hdata, hdata->current_mode.clock * 1000);
if (ret < 0) {
DRM_ERROR("failed to find hdmiphy conf\n");
return;
}
phy_conf = hdata->drv_data->phy_confs.data[ret].conf;
hdmi_clk_set_parents(hdata, false);
hdmiphy_conf_reset(hdata);
hdmiphy_enable_mode_set(hdata, true);
ret = hdmiphy_reg_write_buf(hdata, 0, phy_conf, 32);
if (ret) {
DRM_ERROR("failed to configure hdmiphy\n");
return;
}
hdmiphy_enable_mode_set(hdata, false);
hdmi_clk_set_parents(hdata, true);
usleep_range(10000, 12000);
hdmiphy_wait_for_pll(hdata);
}
static void hdmi_conf_apply(struct hdmi_context *hdata)
{
hdmi_start(hdata, false);
hdmi_conf_init(hdata);
hdmi_audio_init(hdata);
hdmi_mode_apply(hdata);
hdmi_audio_control(hdata, true);
}
static void hdmi_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct hdmi_context *hdata = encoder_to_hdmi(encoder);
struct drm_display_mode *m = adjusted_mode;
DRM_DEBUG_KMS("xres=%d, yres=%d, refresh=%d, intl=%s\n",
m->hdisplay, m->vdisplay,
m->vrefresh, (m->flags & DRM_MODE_FLAG_INTERLACE) ?
"INTERLACED" : "PROGRESSIVE");
drm_mode_copy(&hdata->current_mode, m);
}
static void hdmi_set_refclk(struct hdmi_context *hdata, bool on)
{
if (!hdata->sysreg)
return;
regmap_update_bits(hdata->sysreg, EXYNOS5433_SYSREG_DISP_HDMI_PHY,
SYSREG_HDMI_REFCLK_INT_CLK, on ? ~0 : 0);
}
static void hdmiphy_enable(struct hdmi_context *hdata)
{
if (hdata->powered)
return;
pm_runtime_get_sync(hdata->dev);
if (regulator_bulk_enable(ARRAY_SIZE(supply), hdata->regul_bulk))
DRM_DEBUG_KMS("failed to enable regulator bulk\n");
regmap_update_bits(hdata->pmureg, PMU_HDMI_PHY_CONTROL,
PMU_HDMI_PHY_ENABLE_BIT, 1);
hdmi_set_refclk(hdata, true);
hdmi_reg_writemask(hdata, HDMI_PHY_CON_0, 0, HDMI_PHY_POWER_OFF_EN);
hdmiphy_conf_apply(hdata);
hdata->powered = true;
}
static void hdmiphy_disable(struct hdmi_context *hdata)
{
if (!hdata->powered)
return;
hdmi_reg_writemask(hdata, HDMI_CON_0, 0, HDMI_EN);
hdmi_reg_writemask(hdata, HDMI_PHY_CON_0, ~0, HDMI_PHY_POWER_OFF_EN);
hdmi_set_refclk(hdata, false);
regmap_update_bits(hdata->pmureg, PMU_HDMI_PHY_CONTROL,
PMU_HDMI_PHY_ENABLE_BIT, 0);
regulator_bulk_disable(ARRAY_SIZE(supply), hdata->regul_bulk);
pm_runtime_put_sync(hdata->dev);
hdata->powered = false;
}
static void hdmi_enable(struct drm_encoder *encoder)
{
struct hdmi_context *hdata = encoder_to_hdmi(encoder);
hdmiphy_enable(hdata);
hdmi_conf_apply(hdata);
}
static void hdmi_disable(struct drm_encoder *encoder)
{
struct hdmi_context *hdata = encoder_to_hdmi(encoder);
if (!hdata->powered)
return;
cancel_delayed_work(&hdata->hotplug_work);
cec_notifier_set_phys_addr(hdata->notifier, CEC_PHYS_ADDR_INVALID);
}
static void hdmi_hotplug_work_func(struct work_struct *work)
{
struct hdmi_context *hdata;
hdata = container_of(work, struct hdmi_context, hotplug_work.work);
if (hdata->drm_dev)
drm_helper_hpd_irq_event(hdata->drm_dev);
}
static irqreturn_t hdmi_irq_thread(int irq, void *arg)
{
struct hdmi_context *hdata = arg;
mod_delayed_work(system_wq, &hdata->hotplug_work,
msecs_to_jiffies(HOTPLUG_DEBOUNCE_MS));
return IRQ_HANDLED;
}
static int hdmi_clks_get(struct hdmi_context *hdata,
const struct string_array_spec *names,
struct clk **clks)
{
struct device *dev = hdata->dev;
int i;
for (i = 0; i < names->count; ++i) {
struct clk *clk = devm_clk_get(dev, names->data[i]);
if (IS_ERR(clk)) {
int ret = PTR_ERR(clk);
dev_err(dev, "Cannot get clock %s, %d\n",
names->data[i], ret);
return ret;
}
clks[i] = clk;
}
return 0;
}
static int hdmi_clk_init(struct hdmi_context *hdata)
{
const struct hdmi_driver_data *drv_data = hdata->drv_data;
int count = drv_data->clk_gates.count + drv_data->clk_muxes.count;
struct device *dev = hdata->dev;
struct clk **clks;
int ret;
if (!count)
return 0;
clks = devm_kzalloc(dev, sizeof(*clks) * count, GFP_KERNEL);
if (!clks)
return -ENOMEM;
hdata->clk_gates = clks;
hdata->clk_muxes = clks + drv_data->clk_gates.count;
ret = hdmi_clks_get(hdata, &drv_data->clk_gates, hdata->clk_gates);
if (ret)
return ret;
return hdmi_clks_get(hdata, &drv_data->clk_muxes, hdata->clk_muxes);
}
static void hdmiphy_clk_enable(struct exynos_drm_clk *clk, bool enable)
{
struct hdmi_context *hdata = container_of(clk, struct hdmi_context,
phy_clk);
if (enable)
hdmiphy_enable(hdata);
else
hdmiphy_disable(hdata);
}
static int hdmi_bridge_init(struct hdmi_context *hdata)
{
struct device *dev = hdata->dev;
struct device_node *ep, *np;
ep = of_graph_get_endpoint_by_regs(dev->of_node, 1, -1);
if (!ep)
return 0;
np = of_graph_get_remote_port_parent(ep);
of_node_put(ep);
if (!np) {
DRM_ERROR("failed to get remote port parent");
return -EINVAL;
}
hdata->bridge = of_drm_find_bridge(np);
of_node_put(np);
if (!hdata->bridge)
return -EPROBE_DEFER;
return 0;
}
static int hdmi_resources_init(struct hdmi_context *hdata)
{
struct device *dev = hdata->dev;
int i, ret;
DRM_DEBUG_KMS("HDMI resource init\n");
hdata->hpd_gpio = devm_gpiod_get(dev, "hpd", GPIOD_IN);
if (IS_ERR(hdata->hpd_gpio)) {
DRM_ERROR("cannot get hpd gpio property\n");
return PTR_ERR(hdata->hpd_gpio);
}
hdata->irq = gpiod_to_irq(hdata->hpd_gpio);
if (hdata->irq < 0) {
DRM_ERROR("failed to get GPIO irq\n");
return hdata->irq;
}
ret = hdmi_clk_init(hdata);
if (ret)
return ret;
ret = hdmi_clk_set_parents(hdata, false);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(supply); ++i)
hdata->regul_bulk[i].supply = supply[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(supply), hdata->regul_bulk);
if (ret) {
if (ret != -EPROBE_DEFER)
DRM_ERROR("failed to get regulators\n");
return ret;
}
hdata->reg_hdmi_en = devm_regulator_get_optional(dev, "hdmi-en");
if (PTR_ERR(hdata->reg_hdmi_en) != -ENODEV) {
if (IS_ERR(hdata->reg_hdmi_en))
return PTR_ERR(hdata->reg_hdmi_en);
ret = regulator_enable(hdata->reg_hdmi_en);
if (ret) {
DRM_ERROR("failed to enable hdmi-en regulator\n");
return ret;
}
}
return hdmi_bridge_init(hdata);
}
static int hdmi_bind(struct device *dev, struct device *master, void *data)
{
struct drm_device *drm_dev = data;
struct hdmi_context *hdata = dev_get_drvdata(dev);
struct drm_encoder *encoder = &hdata->encoder;
struct exynos_drm_crtc *crtc;
int ret;
hdata->drm_dev = drm_dev;
hdata->phy_clk.enable = hdmiphy_clk_enable;
drm_encoder_init(drm_dev, encoder, &exynos_hdmi_encoder_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
drm_encoder_helper_add(encoder, &exynos_hdmi_encoder_helper_funcs);
ret = exynos_drm_set_possible_crtcs(encoder, EXYNOS_DISPLAY_TYPE_HDMI);
if (ret < 0)
return ret;
crtc = exynos_drm_crtc_get_by_type(drm_dev, EXYNOS_DISPLAY_TYPE_HDMI);
crtc->pipe_clk = &hdata->phy_clk;
ret = hdmi_create_connector(encoder);
if (ret) {
DRM_ERROR("failed to create connector ret = %d\n", ret);
drm_encoder_cleanup(encoder);
return ret;
}
return 0;
}
static void hdmi_unbind(struct device *dev, struct device *master, void *data)
{
}
static int hdmi_get_ddc_adapter(struct hdmi_context *hdata)
{
const char *compatible_str = "samsung,exynos4210-hdmiddc";
struct device_node *np;
struct i2c_adapter *adpt;
np = of_find_compatible_node(NULL, NULL, compatible_str);
if (np)
np = of_get_next_parent(np);
else
np = of_parse_phandle(hdata->dev->of_node, "ddc", 0);
if (!np) {
DRM_ERROR("Failed to find ddc node in device tree\n");
return -ENODEV;
}
adpt = of_find_i2c_adapter_by_node(np);
of_node_put(np);
if (!adpt) {
DRM_INFO("Failed to get ddc i2c adapter by node\n");
return -EPROBE_DEFER;
}
hdata->ddc_adpt = adpt;
return 0;
}
static int hdmi_get_phy_io(struct hdmi_context *hdata)
{
const char *compatible_str = "samsung,exynos4212-hdmiphy";
struct device_node *np;
int ret = 0;
np = of_find_compatible_node(NULL, NULL, compatible_str);
if (!np) {
np = of_parse_phandle(hdata->dev->of_node, "phy", 0);
if (!np) {
DRM_ERROR("Failed to find hdmiphy node in device tree\n");
return -ENODEV;
}
}
if (hdata->drv_data->is_apb_phy) {
hdata->regs_hdmiphy = of_iomap(np, 0);
if (!hdata->regs_hdmiphy) {
DRM_ERROR("failed to ioremap hdmi phy\n");
ret = -ENOMEM;
goto out;
}
} else {
hdata->hdmiphy_port = of_find_i2c_device_by_node(np);
if (!hdata->hdmiphy_port) {
DRM_INFO("Failed to get hdmi phy i2c client\n");
ret = -EPROBE_DEFER;
goto out;
}
}
out:
of_node_put(np);
return ret;
}
static int hdmi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct hdmi_context *hdata;
struct resource *res;
int ret;
hdata = devm_kzalloc(dev, sizeof(struct hdmi_context), GFP_KERNEL);
if (!hdata)
return -ENOMEM;
hdata->drv_data = of_device_get_match_data(dev);
platform_set_drvdata(pdev, hdata);
hdata->dev = dev;
ret = hdmi_resources_init(hdata);
if (ret) {
if (ret != -EPROBE_DEFER)
DRM_ERROR("hdmi_resources_init failed\n");
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hdata->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(hdata->regs)) {
ret = PTR_ERR(hdata->regs);
return ret;
}
ret = hdmi_get_ddc_adapter(hdata);
if (ret)
return ret;
ret = hdmi_get_phy_io(hdata);
if (ret)
goto err_ddc;
INIT_DELAYED_WORK(&hdata->hotplug_work, hdmi_hotplug_work_func);
ret = devm_request_threaded_irq(dev, hdata->irq, NULL,
hdmi_irq_thread, IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"hdmi", hdata);
if (ret) {
DRM_ERROR("failed to register hdmi interrupt\n");
goto err_hdmiphy;
}
hdata->pmureg = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,syscon-phandle");
if (IS_ERR(hdata->pmureg)) {
DRM_ERROR("syscon regmap lookup failed.\n");
ret = -EPROBE_DEFER;
goto err_hdmiphy;
}
if (hdata->drv_data->has_sysreg) {
hdata->sysreg = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,sysreg-phandle");
if (IS_ERR(hdata->sysreg)) {
DRM_ERROR("sysreg regmap lookup failed.\n");
ret = -EPROBE_DEFER;
goto err_hdmiphy;
}
}
hdata->notifier = cec_notifier_get(&pdev->dev);
if (hdata->notifier == NULL) {
ret = -ENOMEM;
goto err_hdmiphy;
}
pm_runtime_enable(dev);
ret = component_add(&pdev->dev, &hdmi_component_ops);
if (ret)
goto err_notifier_put;
return ret;
err_notifier_put:
cec_notifier_put(hdata->notifier);
pm_runtime_disable(dev);
err_hdmiphy:
if (hdata->hdmiphy_port)
put_device(&hdata->hdmiphy_port->dev);
if (hdata->regs_hdmiphy)
iounmap(hdata->regs_hdmiphy);
err_ddc:
put_device(&hdata->ddc_adpt->dev);
return ret;
}
static int hdmi_remove(struct platform_device *pdev)
{
struct hdmi_context *hdata = platform_get_drvdata(pdev);
cancel_delayed_work_sync(&hdata->hotplug_work);
cec_notifier_set_phys_addr(hdata->notifier, CEC_PHYS_ADDR_INVALID);
component_del(&pdev->dev, &hdmi_component_ops);
cec_notifier_put(hdata->notifier);
pm_runtime_disable(&pdev->dev);
if (!IS_ERR(hdata->reg_hdmi_en))
regulator_disable(hdata->reg_hdmi_en);
if (hdata->hdmiphy_port)
put_device(&hdata->hdmiphy_port->dev);
if (hdata->regs_hdmiphy)
iounmap(hdata->regs_hdmiphy);
put_device(&hdata->ddc_adpt->dev);
return 0;
}
static int __maybe_unused exynos_hdmi_suspend(struct device *dev)
{
struct hdmi_context *hdata = dev_get_drvdata(dev);
hdmi_clk_disable_gates(hdata);
return 0;
}
static int __maybe_unused exynos_hdmi_resume(struct device *dev)
{
struct hdmi_context *hdata = dev_get_drvdata(dev);
int ret;
ret = hdmi_clk_enable_gates(hdata);
if (ret < 0)
return ret;
return 0;
}
