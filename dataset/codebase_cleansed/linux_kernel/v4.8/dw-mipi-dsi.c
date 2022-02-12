static int max_mbps_to_testdin(unsigned int max_mbps)
{
int i;
for (i = 0; i < ARRAY_SIZE(dptdin_map); i++)
if (dptdin_map[i].max_mbps > max_mbps)
return dptdin_map[i].testdin;
return -EINVAL;
}
static void dw_mipi_dsi_wait_for_two_frames(struct dw_mipi_dsi *dsi)
{
int refresh, two_frames;
refresh = drm_mode_vrefresh(dsi->mode);
two_frames = DIV_ROUND_UP(MSEC_PER_SEC, refresh) * 2;
msleep(two_frames);
}
static inline struct dw_mipi_dsi *host_to_dsi(struct mipi_dsi_host *host)
{
return container_of(host, struct dw_mipi_dsi, dsi_host);
}
static inline struct dw_mipi_dsi *con_to_dsi(struct drm_connector *con)
{
return container_of(con, struct dw_mipi_dsi, connector);
}
static inline struct dw_mipi_dsi *encoder_to_dsi(struct drm_encoder *encoder)
{
return container_of(encoder, struct dw_mipi_dsi, encoder);
}
static inline void dsi_write(struct dw_mipi_dsi *dsi, u32 reg, u32 val)
{
writel(val, dsi->base + reg);
}
static inline u32 dsi_read(struct dw_mipi_dsi *dsi, u32 reg)
{
return readl(dsi->base + reg);
}
static void dw_mipi_dsi_phy_write(struct dw_mipi_dsi *dsi, u8 test_code,
u8 test_data)
{
dsi_write(dsi, DSI_PHY_TST_CTRL0, PHY_TESTCLK | PHY_UNTESTCLR);
dsi_write(dsi, DSI_PHY_TST_CTRL1, PHY_TESTEN | PHY_TESTDOUT(0) |
PHY_TESTDIN(test_code));
dsi_write(dsi, DSI_PHY_TST_CTRL0, PHY_UNTESTCLK | PHY_UNTESTCLR);
dsi_write(dsi, DSI_PHY_TST_CTRL1, PHY_UNTESTEN | PHY_TESTDOUT(0) |
PHY_TESTDIN(test_data));
dsi_write(dsi, DSI_PHY_TST_CTRL0, PHY_TESTCLK | PHY_UNTESTCLR);
}
static int dw_mipi_dsi_phy_init(struct dw_mipi_dsi *dsi)
{
int ret, testdin, vco, val;
vco = (dsi->lane_mbps < 200) ? 0 : (dsi->lane_mbps + 100) / 200;
testdin = max_mbps_to_testdin(dsi->lane_mbps);
if (testdin < 0) {
dev_err(dsi->dev,
"failed to get testdin for %dmbps lane clock\n",
dsi->lane_mbps);
return testdin;
}
dsi_write(dsi, DSI_PWR_UP, POWERUP);
dw_mipi_dsi_phy_write(dsi, 0x10, BYPASS_VCO_RANGE |
VCO_RANGE_CON_SEL(vco) |
VCO_IN_CAP_CON_LOW |
REF_BIAS_CUR_SEL);
dw_mipi_dsi_phy_write(dsi, 0x11, CP_CURRENT_3MA);
dw_mipi_dsi_phy_write(dsi, 0x12, CP_PROGRAM_EN | LPF_PROGRAM_EN |
LPF_RESISTORS_20_KOHM);
dw_mipi_dsi_phy_write(dsi, 0x44, HSFREQRANGE_SEL(testdin));
dw_mipi_dsi_phy_write(dsi, 0x19, PLL_LOOP_DIV_EN | PLL_INPUT_DIV_EN);
dw_mipi_dsi_phy_write(dsi, 0x17, INPUT_DIVIDER(dsi->input_div));
dw_mipi_dsi_phy_write(dsi, 0x18, LOOP_DIV_LOW_SEL(dsi->feedback_div) |
LOW_PROGRAM_EN);
dw_mipi_dsi_phy_write(dsi, 0x18, LOOP_DIV_HIGH_SEL(dsi->feedback_div) |
HIGH_PROGRAM_EN);
dw_mipi_dsi_phy_write(dsi, 0x20, POWER_CONTROL | INTERNAL_REG_CURRENT |
BIAS_BLOCK_ON | BANDGAP_ON);
dw_mipi_dsi_phy_write(dsi, 0x21, TER_RESISTOR_LOW | TER_CAL_DONE |
SETRD_MAX | TER_RESISTORS_ON);
dw_mipi_dsi_phy_write(dsi, 0x21, TER_RESISTOR_HIGH | LEVEL_SHIFTERS_ON |
SETRD_MAX | POWER_MANAGE |
TER_RESISTORS_ON);
dw_mipi_dsi_phy_write(dsi, 0x22, LOW_PROGRAM_EN |
BIASEXTR_SEL(BIASEXTR_127_7));
dw_mipi_dsi_phy_write(dsi, 0x22, HIGH_PROGRAM_EN |
BANDGAP_SEL(BANDGAP_96_10));
dw_mipi_dsi_phy_write(dsi, 0x70, TLP_PROGRAM_EN | 0xf);
dw_mipi_dsi_phy_write(dsi, 0x71, THS_PRE_PROGRAM_EN | 0x55);
dw_mipi_dsi_phy_write(dsi, 0x72, THS_ZERO_PROGRAM_EN | 0xa);
dsi_write(dsi, DSI_PHY_RSTZ, PHY_ENFORCEPLL | PHY_ENABLECLK |
PHY_UNRSTZ | PHY_UNSHUTDOWNZ);
ret = readx_poll_timeout(readl, dsi->base + DSI_PHY_STATUS,
val, val & LOCK, 1000, PHY_STATUS_TIMEOUT_US);
if (ret < 0) {
dev_err(dsi->dev, "failed to wait for phy lock state\n");
return ret;
}
ret = readx_poll_timeout(readl, dsi->base + DSI_PHY_STATUS,
val, val & STOP_STATE_CLK_LANE, 1000,
PHY_STATUS_TIMEOUT_US);
if (ret < 0) {
dev_err(dsi->dev,
"failed to wait for phy clk lane stop state\n");
return ret;
}
return ret;
}
static int dw_mipi_dsi_get_lane_bps(struct dw_mipi_dsi *dsi)
{
unsigned int i, pre;
unsigned long mpclk, pllref, tmp;
unsigned int m = 1, n = 1, target_mbps = 1000;
unsigned int max_mbps = dptdin_map[ARRAY_SIZE(dptdin_map) - 1].max_mbps;
int bpp;
bpp = mipi_dsi_pixel_format_to_bpp(dsi->format);
if (bpp < 0) {
dev_err(dsi->dev, "failed to get bpp for pixel format %d\n",
dsi->format);
return bpp;
}
mpclk = DIV_ROUND_UP(dsi->mode->clock, MSEC_PER_SEC);
if (mpclk) {
tmp = mpclk * (bpp / dsi->lanes) * 10 / 9;
if (tmp < max_mbps)
target_mbps = tmp;
else
dev_err(dsi->dev, "DPHY clock frequency is out of range\n");
}
pllref = DIV_ROUND_UP(clk_get_rate(dsi->pllref_clk), USEC_PER_SEC);
tmp = pllref;
for (i = 1; i < 6; i++) {
pre = pllref / i;
if ((tmp > (target_mbps % pre)) && (target_mbps / pre < 512)) {
tmp = target_mbps % pre;
n = i;
m = target_mbps / pre;
}
if (tmp == 0)
break;
}
dsi->lane_mbps = pllref / n * m;
dsi->input_div = n;
dsi->feedback_div = m;
return 0;
}
static int dw_mipi_dsi_host_attach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct dw_mipi_dsi *dsi = host_to_dsi(host);
if (device->lanes > dsi->pdata->max_data_lanes) {
dev_err(dsi->dev, "the number of data lanes(%u) is too many\n",
device->lanes);
return -EINVAL;
}
if (!(device->mode_flags & MIPI_DSI_MODE_VIDEO_BURST) ||
!(device->mode_flags & MIPI_DSI_MODE_VIDEO_SYNC_PULSE)) {
dev_err(dsi->dev, "device mode is unsupported\n");
return -EINVAL;
}
dsi->lanes = device->lanes;
dsi->channel = device->channel;
dsi->format = device->format;
dsi->panel = of_drm_find_panel(device->dev.of_node);
if (dsi->panel)
return drm_panel_attach(dsi->panel, &dsi->connector);
return -EINVAL;
}
static int dw_mipi_dsi_host_detach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct dw_mipi_dsi *dsi = host_to_dsi(host);
drm_panel_detach(dsi->panel);
return 0;
}
static int dw_mipi_dsi_gen_pkt_hdr_write(struct dw_mipi_dsi *dsi, u32 val)
{
int ret;
ret = readx_poll_timeout(readl, dsi->base + DSI_CMD_PKT_STATUS,
val, !(val & GEN_CMD_FULL), 1000,
CMD_PKT_STATUS_TIMEOUT_US);
if (ret < 0) {
dev_err(dsi->dev, "failed to get available command FIFO\n");
return ret;
}
dsi_write(dsi, DSI_GEN_HDR, val);
ret = readx_poll_timeout(readl, dsi->base + DSI_CMD_PKT_STATUS,
val, val & (GEN_CMD_EMPTY | GEN_PLD_W_EMPTY),
1000, CMD_PKT_STATUS_TIMEOUT_US);
if (ret < 0) {
dev_err(dsi->dev, "failed to write command FIFO\n");
return ret;
}
return 0;
}
static int dw_mipi_dsi_dcs_short_write(struct dw_mipi_dsi *dsi,
const struct mipi_dsi_msg *msg)
{
const u16 *tx_buf = msg->tx_buf;
u32 val = GEN_HDATA(*tx_buf) | GEN_HTYPE(msg->type);
if (msg->tx_len > 2) {
dev_err(dsi->dev, "too long tx buf length %zu for short write\n",
msg->tx_len);
return -EINVAL;
}
return dw_mipi_dsi_gen_pkt_hdr_write(dsi, val);
}
static int dw_mipi_dsi_dcs_long_write(struct dw_mipi_dsi *dsi,
const struct mipi_dsi_msg *msg)
{
const u32 *tx_buf = msg->tx_buf;
int len = msg->tx_len, pld_data_bytes = sizeof(*tx_buf), ret;
u32 val = GEN_HDATA(msg->tx_len) | GEN_HTYPE(msg->type);
u32 remainder = 0;
if (msg->tx_len < 3) {
dev_err(dsi->dev, "wrong tx buf length %zu for long write\n",
msg->tx_len);
return -EINVAL;
}
while (DIV_ROUND_UP(len, pld_data_bytes)) {
if (len < pld_data_bytes) {
memcpy(&remainder, tx_buf, len);
dsi_write(dsi, DSI_GEN_PLD_DATA, remainder);
len = 0;
} else {
dsi_write(dsi, DSI_GEN_PLD_DATA, *tx_buf);
tx_buf++;
len -= pld_data_bytes;
}
ret = readx_poll_timeout(readl, dsi->base + DSI_CMD_PKT_STATUS,
val, !(val & GEN_PLD_W_FULL), 1000,
CMD_PKT_STATUS_TIMEOUT_US);
if (ret < 0) {
dev_err(dsi->dev,
"failed to get available write payload FIFO\n");
return ret;
}
}
return dw_mipi_dsi_gen_pkt_hdr_write(dsi, val);
}
static ssize_t dw_mipi_dsi_host_transfer(struct mipi_dsi_host *host,
const struct mipi_dsi_msg *msg)
{
struct dw_mipi_dsi *dsi = host_to_dsi(host);
int ret;
switch (msg->type) {
case MIPI_DSI_DCS_SHORT_WRITE:
case MIPI_DSI_DCS_SHORT_WRITE_PARAM:
case MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE:
ret = dw_mipi_dsi_dcs_short_write(dsi, msg);
break;
case MIPI_DSI_DCS_LONG_WRITE:
ret = dw_mipi_dsi_dcs_long_write(dsi, msg);
break;
default:
dev_err(dsi->dev, "unsupported message type\n");
ret = -EINVAL;
}
return ret;
}
static void dw_mipi_dsi_video_mode_config(struct dw_mipi_dsi *dsi)
{
u32 val;
val = VID_MODE_TYPE_BURST_SYNC_PULSES | ENABLE_LOW_POWER;
dsi_write(dsi, DSI_VID_MODE_CFG, val);
}
static void dw_mipi_dsi_set_mode(struct dw_mipi_dsi *dsi,
enum dw_mipi_dsi_mode mode)
{
if (mode == DW_MIPI_DSI_CMD_MODE) {
dsi_write(dsi, DSI_PWR_UP, RESET);
dsi_write(dsi, DSI_MODE_CFG, ENABLE_CMD_MODE);
dsi_write(dsi, DSI_PWR_UP, POWERUP);
} else {
dsi_write(dsi, DSI_PWR_UP, RESET);
dsi_write(dsi, DSI_MODE_CFG, ENABLE_VIDEO_MODE);
dw_mipi_dsi_video_mode_config(dsi);
dsi_write(dsi, DSI_PWR_UP, POWERUP);
}
}
static void dw_mipi_dsi_disable(struct dw_mipi_dsi *dsi)
{
dsi_write(dsi, DSI_PWR_UP, RESET);
dsi_write(dsi, DSI_PHY_RSTZ, PHY_RSTZ);
}
static void dw_mipi_dsi_init(struct dw_mipi_dsi *dsi)
{
dsi_write(dsi, DSI_PWR_UP, RESET);
dsi_write(dsi, DSI_PHY_RSTZ, PHY_DISFORCEPLL | PHY_DISABLECLK
| PHY_RSTZ | PHY_SHUTDOWNZ);
dsi_write(dsi, DSI_CLKMGR_CFG, TO_CLK_DIVIDSION(10) |
TX_ESC_CLK_DIVIDSION(7));
dsi_write(dsi, DSI_LPCLK_CTRL, PHY_TXREQUESTCLKHS);
}
static void dw_mipi_dsi_dpi_config(struct dw_mipi_dsi *dsi,
struct drm_display_mode *mode)
{
u32 val = 0, color = 0;
switch (dsi->format) {
case MIPI_DSI_FMT_RGB888:
color = DPI_COLOR_CODING_24BIT;
break;
case MIPI_DSI_FMT_RGB666:
color = DPI_COLOR_CODING_18BIT_2 | EN18_LOOSELY;
break;
case MIPI_DSI_FMT_RGB666_PACKED:
color = DPI_COLOR_CODING_18BIT_1;
break;
case MIPI_DSI_FMT_RGB565:
color = DPI_COLOR_CODING_16BIT_1;
break;
}
if (!(mode->flags & DRM_MODE_FLAG_PVSYNC))
val |= VSYNC_ACTIVE_LOW;
if (!(mode->flags & DRM_MODE_FLAG_PHSYNC))
val |= HSYNC_ACTIVE_LOW;
dsi_write(dsi, DSI_DPI_VCID, DPI_VID(dsi->channel));
dsi_write(dsi, DSI_DPI_COLOR_CODING, color);
dsi_write(dsi, DSI_DPI_CFG_POL, val);
dsi_write(dsi, DSI_DPI_LP_CMD_TIM, OUTVACT_LPCMD_TIME(4)
| INVACT_LPCMD_TIME(4));
}
static void dw_mipi_dsi_packet_handler_config(struct dw_mipi_dsi *dsi)
{
dsi_write(dsi, DSI_PCKHDL_CFG, EN_CRC_RX | EN_ECC_RX | EN_BTA);
}
static void dw_mipi_dsi_video_packet_config(struct dw_mipi_dsi *dsi,
struct drm_display_mode *mode)
{
dsi_write(dsi, DSI_VID_PKT_SIZE, VID_PKT_SIZE(mode->hdisplay));
}
static void dw_mipi_dsi_command_mode_config(struct dw_mipi_dsi *dsi)
{
dsi_write(dsi, DSI_TO_CNT_CFG, HSTX_TO_CNT(1000) | LPRX_TO_CNT(1000));
dsi_write(dsi, DSI_BTA_TO_CNT, 0xd00);
dsi_write(dsi, DSI_CMD_MODE_CFG, CMD_MODE_ALL_LP);
dsi_write(dsi, DSI_MODE_CFG, ENABLE_CMD_MODE);
}
static u32 dw_mipi_dsi_get_hcomponent_lbcc(struct dw_mipi_dsi *dsi,
u32 hcomponent)
{
u32 frac, lbcc;
lbcc = hcomponent * dsi->lane_mbps * MSEC_PER_SEC / 8;
frac = lbcc % dsi->mode->clock;
lbcc = lbcc / dsi->mode->clock;
if (frac)
lbcc++;
return lbcc;
}
static void dw_mipi_dsi_line_timer_config(struct dw_mipi_dsi *dsi)
{
u32 htotal, hsa, hbp, lbcc;
struct drm_display_mode *mode = dsi->mode;
htotal = mode->htotal;
hsa = mode->hsync_end - mode->hsync_start;
hbp = mode->htotal - mode->hsync_end;
lbcc = dw_mipi_dsi_get_hcomponent_lbcc(dsi, htotal);
dsi_write(dsi, DSI_VID_HLINE_TIME, lbcc);
lbcc = dw_mipi_dsi_get_hcomponent_lbcc(dsi, hsa);
dsi_write(dsi, DSI_VID_HSA_TIME, lbcc);
lbcc = dw_mipi_dsi_get_hcomponent_lbcc(dsi, hbp);
dsi_write(dsi, DSI_VID_HBP_TIME, lbcc);
}
static void dw_mipi_dsi_vertical_timing_config(struct dw_mipi_dsi *dsi)
{
u32 vactive, vsa, vfp, vbp;
struct drm_display_mode *mode = dsi->mode;
vactive = mode->vdisplay;
vsa = mode->vsync_end - mode->vsync_start;
vfp = mode->vsync_start - mode->vdisplay;
vbp = mode->vtotal - mode->vsync_end;
dsi_write(dsi, DSI_VID_VACTIVE_LINES, vactive);
dsi_write(dsi, DSI_VID_VSA_LINES, vsa);
dsi_write(dsi, DSI_VID_VFP_LINES, vfp);
dsi_write(dsi, DSI_VID_VBP_LINES, vbp);
}
static void dw_mipi_dsi_dphy_timing_config(struct dw_mipi_dsi *dsi)
{
dsi_write(dsi, DSI_PHY_TMR_CFG, PHY_HS2LP_TIME(0x40)
| PHY_LP2HS_TIME(0x40) | MAX_RD_TIME(10000));
dsi_write(dsi, DSI_PHY_TMR_LPCLK_CFG, PHY_CLKHS2LP_TIME(0x40)
| PHY_CLKLP2HS_TIME(0x40));
}
static void dw_mipi_dsi_dphy_interface_config(struct dw_mipi_dsi *dsi)
{
dsi_write(dsi, DSI_PHY_IF_CFG, PHY_STOP_WAIT_TIME(0x20) |
N_LANES(dsi->lanes));
}
static void dw_mipi_dsi_clear_err(struct dw_mipi_dsi *dsi)
{
dsi_read(dsi, DSI_INT_ST0);
dsi_read(dsi, DSI_INT_ST1);
dsi_write(dsi, DSI_INT_MSK0, 0);
dsi_write(dsi, DSI_INT_MSK1, 0);
}
static void dw_mipi_dsi_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct dw_mipi_dsi *dsi = encoder_to_dsi(encoder);
int ret;
dsi->mode = adjusted_mode;
ret = dw_mipi_dsi_get_lane_bps(dsi);
if (ret < 0)
return;
if (clk_prepare_enable(dsi->pclk)) {
dev_err(dsi->dev, "%s: Failed to enable pclk\n", __func__);
return;
}
dw_mipi_dsi_init(dsi);
dw_mipi_dsi_dpi_config(dsi, mode);
dw_mipi_dsi_packet_handler_config(dsi);
dw_mipi_dsi_video_mode_config(dsi);
dw_mipi_dsi_video_packet_config(dsi, mode);
dw_mipi_dsi_command_mode_config(dsi);
dw_mipi_dsi_line_timer_config(dsi);
dw_mipi_dsi_vertical_timing_config(dsi);
dw_mipi_dsi_dphy_timing_config(dsi);
dw_mipi_dsi_dphy_interface_config(dsi);
dw_mipi_dsi_clear_err(dsi);
if (drm_panel_prepare(dsi->panel))
dev_err(dsi->dev, "failed to prepare panel\n");
clk_disable_unprepare(dsi->pclk);
}
static void dw_mipi_dsi_encoder_disable(struct drm_encoder *encoder)
{
struct dw_mipi_dsi *dsi = encoder_to_dsi(encoder);
drm_panel_disable(dsi->panel);
if (clk_prepare_enable(dsi->pclk)) {
dev_err(dsi->dev, "%s: Failed to enable pclk\n", __func__);
return;
}
dw_mipi_dsi_set_mode(dsi, DW_MIPI_DSI_CMD_MODE);
drm_panel_unprepare(dsi->panel);
dw_mipi_dsi_set_mode(dsi, DW_MIPI_DSI_VID_MODE);
msleep(120);
dw_mipi_dsi_set_mode(dsi, DW_MIPI_DSI_CMD_MODE);
dw_mipi_dsi_disable(dsi);
clk_disable_unprepare(dsi->pclk);
}
static void dw_mipi_dsi_encoder_commit(struct drm_encoder *encoder)
{
struct dw_mipi_dsi *dsi = encoder_to_dsi(encoder);
int mux = drm_of_encoder_active_endpoint_id(dsi->dev->of_node, encoder);
u32 val;
if (clk_prepare_enable(dsi->pclk)) {
dev_err(dsi->dev, "%s: Failed to enable pclk\n", __func__);
return;
}
dw_mipi_dsi_phy_init(dsi);
dw_mipi_dsi_wait_for_two_frames(dsi);
dw_mipi_dsi_set_mode(dsi, DW_MIPI_DSI_VID_MODE);
drm_panel_enable(dsi->panel);
clk_disable_unprepare(dsi->pclk);
if (mux)
val = DSI0_SEL_VOP_LIT | (DSI0_SEL_VOP_LIT << 16);
else
val = DSI0_SEL_VOP_LIT << 16;
regmap_write(dsi->grf_regmap, GRF_SOC_CON6, val);
dev_dbg(dsi->dev, "vop %s output to dsi0\n", (mux) ? "LIT" : "BIG");
}
static int
dw_mipi_dsi_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
struct rockchip_crtc_state *s = to_rockchip_crtc_state(crtc_state);
struct dw_mipi_dsi *dsi = encoder_to_dsi(encoder);
switch (dsi->format) {
case MIPI_DSI_FMT_RGB888:
s->output_mode = ROCKCHIP_OUT_MODE_P888;
break;
case MIPI_DSI_FMT_RGB666:
s->output_mode = ROCKCHIP_OUT_MODE_P666;
break;
case MIPI_DSI_FMT_RGB565:
s->output_mode = ROCKCHIP_OUT_MODE_P565;
break;
default:
WARN_ON(1);
return -EINVAL;
}
s->output_type = DRM_MODE_CONNECTOR_DSI;
return 0;
}
static int dw_mipi_dsi_connector_get_modes(struct drm_connector *connector)
{
struct dw_mipi_dsi *dsi = con_to_dsi(connector);
return drm_panel_get_modes(dsi->panel);
}
static enum drm_mode_status dw_mipi_dsi_mode_valid(
struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct dw_mipi_dsi *dsi = con_to_dsi(connector);
enum drm_mode_status mode_status = MODE_OK;
if (dsi->pdata->mode_valid)
mode_status = dsi->pdata->mode_valid(connector, mode);
return mode_status;
}
static enum drm_connector_status
dw_mipi_dsi_detect(struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
static void dw_mipi_dsi_drm_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static int dw_mipi_dsi_register(struct drm_device *drm,
struct dw_mipi_dsi *dsi)
{
struct drm_encoder *encoder = &dsi->encoder;
struct drm_connector *connector = &dsi->connector;
struct device *dev = dsi->dev;
int ret;
encoder->possible_crtcs = drm_of_find_possible_crtcs(drm,
dev->of_node);
if (encoder->possible_crtcs == 0)
return -EPROBE_DEFER;
drm_encoder_helper_add(&dsi->encoder,
&dw_mipi_dsi_encoder_helper_funcs);
ret = drm_encoder_init(drm, &dsi->encoder, &dw_mipi_dsi_encoder_funcs,
DRM_MODE_ENCODER_DSI, NULL);
if (ret) {
dev_err(dev, "Failed to initialize encoder with drm\n");
return ret;
}
drm_connector_helper_add(connector,
&dw_mipi_dsi_connector_helper_funcs);
drm_connector_init(drm, &dsi->connector,
&dw_mipi_dsi_atomic_connector_funcs,
DRM_MODE_CONNECTOR_DSI);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
static int rockchip_mipi_parse_dt(struct dw_mipi_dsi *dsi)
{
struct device_node *np = dsi->dev->of_node;
dsi->grf_regmap = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
if (IS_ERR(dsi->grf_regmap)) {
dev_err(dsi->dev, "Unable to get rockchip,grf\n");
return PTR_ERR(dsi->grf_regmap);
}
return 0;
}
static enum drm_mode_status rk3288_mipi_dsi_mode_valid(
struct drm_connector *connector,
struct drm_display_mode *mode)
{
if (mode->hdisplay > 0x7ff)
return MODE_BAD_HVALUE;
if (mode->vdisplay > 0x7ff)
return MODE_BAD_VVALUE;
return MODE_OK;
}
static int dw_mipi_dsi_bind(struct device *dev, struct device *master,
void *data)
{
const struct of_device_id *of_id =
of_match_device(dw_mipi_dsi_dt_ids, dev);
const struct dw_mipi_dsi_plat_data *pdata = of_id->data;
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = data;
struct dw_mipi_dsi *dsi;
struct resource *res;
int ret;
dsi = devm_kzalloc(dev, sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return -ENOMEM;
dsi->dev = dev;
dsi->pdata = pdata;
ret = rockchip_mipi_parse_dt(dsi);
if (ret)
return ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
dsi->base = devm_ioremap_resource(dev, res);
if (IS_ERR(dsi->base))
return PTR_ERR(dsi->base);
dsi->pllref_clk = devm_clk_get(dev, "ref");
if (IS_ERR(dsi->pllref_clk)) {
ret = PTR_ERR(dsi->pllref_clk);
dev_err(dev, "Unable to get pll reference clock: %d\n", ret);
return ret;
}
dsi->pclk = devm_clk_get(dev, "pclk");
if (IS_ERR(dsi->pclk)) {
ret = PTR_ERR(dsi->pclk);
dev_err(dev, "Unable to get pclk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(dsi->pllref_clk);
if (ret) {
dev_err(dev, "%s: Failed to enable pllref_clk\n", __func__);
return ret;
}
ret = dw_mipi_dsi_register(drm, dsi);
if (ret) {
dev_err(dev, "Failed to register mipi_dsi: %d\n", ret);
goto err_pllref;
}
dev_set_drvdata(dev, dsi);
dsi->dsi_host.ops = &dw_mipi_dsi_host_ops;
dsi->dsi_host.dev = dev;
return mipi_dsi_host_register(&dsi->dsi_host);
err_pllref:
clk_disable_unprepare(dsi->pllref_clk);
return ret;
}
static void dw_mipi_dsi_unbind(struct device *dev, struct device *master,
void *data)
{
struct dw_mipi_dsi *dsi = dev_get_drvdata(dev);
mipi_dsi_host_unregister(&dsi->dsi_host);
clk_disable_unprepare(dsi->pllref_clk);
}
static int dw_mipi_dsi_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &dw_mipi_dsi_ops);
}
static int dw_mipi_dsi_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &dw_mipi_dsi_ops);
return 0;
}
