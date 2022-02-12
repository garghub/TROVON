static inline void
dsi_dma_workaround_write(struct vc4_dsi *dsi, u32 offset, u32 val)
{
struct dma_chan *chan = dsi->reg_dma_chan;
struct dma_async_tx_descriptor *tx;
dma_cookie_t cookie;
int ret;
if (!chan) {
writel(val, dsi->regs + offset);
return;
}
*dsi->reg_dma_mem = val;
tx = chan->device->device_prep_dma_memcpy(chan,
dsi->reg_paddr + offset,
dsi->reg_dma_paddr,
4, 0);
if (!tx) {
DRM_ERROR("Failed to set up DMA register write\n");
return;
}
cookie = tx->tx_submit(tx);
ret = dma_submit_error(cookie);
if (ret) {
DRM_ERROR("Failed to submit DMA: %d\n", ret);
return;
}
ret = dma_sync_wait(chan, cookie);
if (ret)
DRM_ERROR("Failed to wait for DMA: %d\n", ret);
}
static inline struct vc4_dsi_encoder *
to_vc4_dsi_encoder(struct drm_encoder *encoder)
{
return container_of(encoder, struct vc4_dsi_encoder, base.base);
}
static inline struct vc4_dsi_connector *
to_vc4_dsi_connector(struct drm_connector *connector)
{
return container_of(connector, struct vc4_dsi_connector, base);
}
static void vc4_dsi_dump_regs(struct vc4_dsi *dsi)
{
int i;
if (dsi->port == 0) {
for (i = 0; i < ARRAY_SIZE(dsi0_regs); i++) {
DRM_INFO("0x%04x (%s): 0x%08x\n",
dsi0_regs[i].reg, dsi0_regs[i].name,
DSI_READ(dsi0_regs[i].reg));
}
} else {
for (i = 0; i < ARRAY_SIZE(dsi1_regs); i++) {
DRM_INFO("0x%04x (%s): 0x%08x\n",
dsi1_regs[i].reg, dsi1_regs[i].name,
DSI_READ(dsi1_regs[i].reg));
}
}
}
int vc4_dsi_debugfs_regs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *drm = node->minor->dev;
struct vc4_dev *vc4 = to_vc4_dev(drm);
int dsi_index = (uintptr_t)node->info_ent->data;
struct vc4_dsi *dsi = (dsi_index == 1 ? vc4->dsi1 : NULL);
int i;
if (!dsi)
return 0;
if (dsi->port == 0) {
for (i = 0; i < ARRAY_SIZE(dsi0_regs); i++) {
seq_printf(m, "0x%04x (%s): 0x%08x\n",
dsi0_regs[i].reg, dsi0_regs[i].name,
DSI_READ(dsi0_regs[i].reg));
}
} else {
for (i = 0; i < ARRAY_SIZE(dsi1_regs); i++) {
seq_printf(m, "0x%04x (%s): 0x%08x\n",
dsi1_regs[i].reg, dsi1_regs[i].name,
DSI_READ(dsi1_regs[i].reg));
}
}
return 0;
}
static enum drm_connector_status
vc4_dsi_connector_detect(struct drm_connector *connector, bool force)
{
struct vc4_dsi_connector *vc4_connector =
to_vc4_dsi_connector(connector);
struct vc4_dsi *dsi = vc4_connector->dsi;
if (dsi->panel)
return connector_status_connected;
else
return connector_status_disconnected;
}
static void vc4_dsi_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static int vc4_dsi_connector_get_modes(struct drm_connector *connector)
{
struct vc4_dsi_connector *vc4_connector =
to_vc4_dsi_connector(connector);
struct vc4_dsi *dsi = vc4_connector->dsi;
if (dsi->panel)
return drm_panel_get_modes(dsi->panel);
return 0;
}
static struct drm_connector *vc4_dsi_connector_init(struct drm_device *dev,
struct vc4_dsi *dsi)
{
struct drm_connector *connector;
struct vc4_dsi_connector *dsi_connector;
dsi_connector = devm_kzalloc(dev->dev, sizeof(*dsi_connector),
GFP_KERNEL);
if (!dsi_connector)
return ERR_PTR(-ENOMEM);
connector = &dsi_connector->base;
dsi_connector->dsi = dsi;
drm_connector_init(dev, connector, &vc4_dsi_connector_funcs,
DRM_MODE_CONNECTOR_DSI);
drm_connector_helper_add(connector, &vc4_dsi_connector_helper_funcs);
connector->polled = 0;
connector->interlace_allowed = 0;
connector->doublescan_allowed = 0;
drm_mode_connector_attach_encoder(connector, dsi->encoder);
return connector;
}
static void vc4_dsi_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static void vc4_dsi_latch_ulps(struct vc4_dsi *dsi, bool latch)
{
u32 afec0 = DSI_PORT_READ(PHY_AFEC0);
if (latch)
afec0 |= DSI_PORT_BIT(PHY_AFEC0_LATCH_ULPS);
else
afec0 &= ~DSI_PORT_BIT(PHY_AFEC0_LATCH_ULPS);
DSI_PORT_WRITE(PHY_AFEC0, afec0);
}
static void vc4_dsi_ulps(struct vc4_dsi *dsi, bool ulps)
{
bool continuous = dsi->mode_flags & MIPI_DSI_CLOCK_NON_CONTINUOUS;
u32 phyc_ulps = ((continuous ? DSI_PORT_BIT(PHYC_CLANE_ULPS) : 0) |
DSI_PHYC_DLANE0_ULPS |
(dsi->lanes > 1 ? DSI_PHYC_DLANE1_ULPS : 0) |
(dsi->lanes > 2 ? DSI_PHYC_DLANE2_ULPS : 0) |
(dsi->lanes > 3 ? DSI_PHYC_DLANE3_ULPS : 0));
u32 stat_ulps = ((continuous ? DSI1_STAT_PHY_CLOCK_ULPS : 0) |
DSI1_STAT_PHY_D0_ULPS |
(dsi->lanes > 1 ? DSI1_STAT_PHY_D1_ULPS : 0) |
(dsi->lanes > 2 ? DSI1_STAT_PHY_D2_ULPS : 0) |
(dsi->lanes > 3 ? DSI1_STAT_PHY_D3_ULPS : 0));
u32 stat_stop = ((continuous ? DSI1_STAT_PHY_CLOCK_STOP : 0) |
DSI1_STAT_PHY_D0_STOP |
(dsi->lanes > 1 ? DSI1_STAT_PHY_D1_STOP : 0) |
(dsi->lanes > 2 ? DSI1_STAT_PHY_D2_STOP : 0) |
(dsi->lanes > 3 ? DSI1_STAT_PHY_D3_STOP : 0));
int ret;
DSI_PORT_WRITE(STAT, stat_ulps);
DSI_PORT_WRITE(PHYC, DSI_PORT_READ(PHYC) | phyc_ulps);
ret = wait_for((DSI_PORT_READ(STAT) & stat_ulps) == stat_ulps, 200);
if (ret) {
dev_warn(&dsi->pdev->dev,
"Timeout waiting for DSI ULPS entry: STAT 0x%08x",
DSI_PORT_READ(STAT));
DSI_PORT_WRITE(PHYC, DSI_PORT_READ(PHYC) & ~phyc_ulps);
vc4_dsi_latch_ulps(dsi, false);
return;
}
vc4_dsi_latch_ulps(dsi, ulps);
DSI_PORT_WRITE(STAT, stat_stop);
DSI_PORT_WRITE(PHYC, DSI_PORT_READ(PHYC) & ~phyc_ulps);
ret = wait_for((DSI_PORT_READ(STAT) & stat_stop) == stat_stop, 200);
if (ret) {
dev_warn(&dsi->pdev->dev,
"Timeout waiting for DSI STOP entry: STAT 0x%08x",
DSI_PORT_READ(STAT));
DSI_PORT_WRITE(PHYC, DSI_PORT_READ(PHYC) & ~phyc_ulps);
return;
}
}
static u32
dsi_hs_timing(u32 ui_ns, u32 ns, u32 ui)
{
return roundup(ui + DIV_ROUND_UP(ns, ui_ns), 8);
}
static u32
dsi_esc_timing(u32 ns)
{
return DIV_ROUND_UP(ns, ESC_TIME_NS);
}
static void vc4_dsi_encoder_disable(struct drm_encoder *encoder)
{
struct vc4_dsi_encoder *vc4_encoder = to_vc4_dsi_encoder(encoder);
struct vc4_dsi *dsi = vc4_encoder->dsi;
struct device *dev = &dsi->pdev->dev;
drm_panel_disable(dsi->panel);
vc4_dsi_ulps(dsi, true);
drm_panel_unprepare(dsi->panel);
clk_disable_unprepare(dsi->pll_phy_clock);
clk_disable_unprepare(dsi->escape_clock);
clk_disable_unprepare(dsi->pixel_clock);
pm_runtime_put(dev);
}
static void vc4_dsi_encoder_enable(struct drm_encoder *encoder)
{
struct drm_display_mode *mode = &encoder->crtc->mode;
struct vc4_dsi_encoder *vc4_encoder = to_vc4_dsi_encoder(encoder);
struct vc4_dsi *dsi = vc4_encoder->dsi;
struct device *dev = &dsi->pdev->dev;
u32 format = 0, divider = 0;
bool debug_dump_regs = false;
unsigned long hs_clock;
u32 ui_ns;
u32 lpx = dsi_esc_timing(60);
unsigned long pixel_clock_hz = mode->clock * 1000;
unsigned long dsip_clock;
unsigned long phy_clock;
int ret;
ret = pm_runtime_get_sync(dev);
if (ret) {
DRM_ERROR("Failed to runtime PM enable on DSI%d\n", dsi->port);
return;
}
ret = drm_panel_prepare(dsi->panel);
if (ret) {
DRM_ERROR("Panel failed to prepare\n");
return;
}
if (debug_dump_regs) {
DRM_INFO("DSI regs before:\n");
vc4_dsi_dump_regs(dsi);
}
switch (dsi->format) {
case MIPI_DSI_FMT_RGB888:
format = DSI_PFORMAT_RGB888;
divider = 24 / dsi->lanes;
break;
case MIPI_DSI_FMT_RGB666:
format = DSI_PFORMAT_RGB666;
divider = 24 / dsi->lanes;
break;
case MIPI_DSI_FMT_RGB666_PACKED:
format = DSI_PFORMAT_RGB666_PACKED;
divider = 18 / dsi->lanes;
break;
case MIPI_DSI_FMT_RGB565:
format = DSI_PFORMAT_RGB565;
divider = 16 / dsi->lanes;
break;
}
phy_clock = pixel_clock_hz * divider;
ret = clk_set_rate(dsi->pll_phy_clock, phy_clock);
if (ret) {
dev_err(&dsi->pdev->dev,
"Failed to set phy clock to %ld: %d\n", phy_clock, ret);
}
DSI_PORT_WRITE(CTRL,
DSI_CTRL_SOFT_RESET_CFG |
DSI_PORT_BIT(CTRL_RESET_FIFOS));
DSI_PORT_WRITE(CTRL,
DSI_CTRL_HSDT_EOT_DISABLE |
DSI_CTRL_RX_LPDT_EOT_DISABLE);
DSI_PORT_WRITE(STAT, DSI_PORT_READ(STAT));
if (dsi->port == 0) {
u32 afec0 = (VC4_SET_FIELD(7, DSI_PHY_AFEC0_PTATADJ) |
VC4_SET_FIELD(7, DSI_PHY_AFEC0_CTATADJ));
if (dsi->lanes < 2)
afec0 |= DSI0_PHY_AFEC0_PD_DLANE1;
if (!(dsi->mode_flags & MIPI_DSI_MODE_VIDEO))
afec0 |= DSI0_PHY_AFEC0_RESET;
DSI_PORT_WRITE(PHY_AFEC0, afec0);
DSI_PORT_WRITE(PHY_AFEC1,
VC4_SET_FIELD(6, DSI0_PHY_AFEC1_IDR_DLANE1) |
VC4_SET_FIELD(6, DSI0_PHY_AFEC1_IDR_DLANE0) |
VC4_SET_FIELD(6, DSI0_PHY_AFEC1_IDR_CLANE));
} else {
u32 afec0 = (VC4_SET_FIELD(7, DSI_PHY_AFEC0_PTATADJ) |
VC4_SET_FIELD(7, DSI_PHY_AFEC0_CTATADJ) |
VC4_SET_FIELD(6, DSI1_PHY_AFEC0_IDR_CLANE) |
VC4_SET_FIELD(6, DSI1_PHY_AFEC0_IDR_DLANE0) |
VC4_SET_FIELD(6, DSI1_PHY_AFEC0_IDR_DLANE1) |
VC4_SET_FIELD(6, DSI1_PHY_AFEC0_IDR_DLANE2) |
VC4_SET_FIELD(6, DSI1_PHY_AFEC0_IDR_DLANE3));
if (dsi->lanes < 4)
afec0 |= DSI1_PHY_AFEC0_PD_DLANE3;
if (dsi->lanes < 3)
afec0 |= DSI1_PHY_AFEC0_PD_DLANE2;
if (dsi->lanes < 2)
afec0 |= DSI1_PHY_AFEC0_PD_DLANE1;
afec0 |= DSI1_PHY_AFEC0_RESET;
DSI_PORT_WRITE(PHY_AFEC0, afec0);
DSI_PORT_WRITE(PHY_AFEC1, 0);
mdelay(1);
}
ret = clk_prepare_enable(dsi->escape_clock);
if (ret) {
DRM_ERROR("Failed to turn on DSI escape clock: %d\n", ret);
return;
}
ret = clk_prepare_enable(dsi->pll_phy_clock);
if (ret) {
DRM_ERROR("Failed to turn on DSI PLL: %d\n", ret);
return;
}
hs_clock = clk_get_rate(dsi->pll_phy_clock);
dsip_clock = phy_clock / 8;
ret = clk_set_rate(dsi->pixel_clock, dsip_clock);
if (ret) {
dev_err(dev, "Failed to set pixel clock to %ldHz: %d\n",
dsip_clock, ret);
}
ret = clk_prepare_enable(dsi->pixel_clock);
if (ret) {
DRM_ERROR("Failed to turn on DSI pixel clock: %d\n", ret);
return;
}
ui_ns = DIV_ROUND_UP(500000000, hs_clock);
DSI_PORT_WRITE(HS_CLT0,
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 262, 0),
DSI_HS_CLT0_CZERO) |
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 0, 8),
DSI_HS_CLT0_CPRE) |
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 38, 0),
DSI_HS_CLT0_CPREP));
DSI_PORT_WRITE(HS_CLT1,
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 60, 0),
DSI_HS_CLT1_CTRAIL) |
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 60, 52),
DSI_HS_CLT1_CPOST));
DSI_PORT_WRITE(HS_CLT2,
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 1000000, 0),
DSI_HS_CLT2_WUP));
DSI_PORT_WRITE(HS_DLT3,
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 100, 0),
DSI_HS_DLT3_EXIT) |
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 105, 6),
DSI_HS_DLT3_ZERO) |
VC4_SET_FIELD(dsi_hs_timing(ui_ns, 40, 4),
DSI_HS_DLT3_PRE));
DSI_PORT_WRITE(HS_DLT4,
VC4_SET_FIELD(dsi_hs_timing(ui_ns, lpx * ESC_TIME_NS, 0),
DSI_HS_DLT4_LPX) |
VC4_SET_FIELD(max(dsi_hs_timing(ui_ns, 0, 8),
dsi_hs_timing(ui_ns, 60, 4)),
DSI_HS_DLT4_TRAIL) |
VC4_SET_FIELD(0, DSI_HS_DLT4_ANLAT));
DSI_PORT_WRITE(HS_DLT5, VC4_SET_FIELD(dsi_hs_timing(ui_ns, 1000, 5000),
DSI_HS_DLT5_INIT));
DSI_PORT_WRITE(HS_DLT6,
VC4_SET_FIELD(lpx * 5, DSI_HS_DLT6_TA_GET) |
VC4_SET_FIELD(lpx, DSI_HS_DLT6_TA_SURE) |
VC4_SET_FIELD(lpx * 4, DSI_HS_DLT6_TA_GO) |
VC4_SET_FIELD(lpx, DSI_HS_DLT6_LP_LPX));
DSI_PORT_WRITE(HS_DLT7,
VC4_SET_FIELD(dsi_esc_timing(1000000),
DSI_HS_DLT7_LP_WUP));
DSI_PORT_WRITE(PHYC,
DSI_PHYC_DLANE0_ENABLE |
(dsi->lanes >= 2 ? DSI_PHYC_DLANE1_ENABLE : 0) |
(dsi->lanes >= 3 ? DSI_PHYC_DLANE2_ENABLE : 0) |
(dsi->lanes >= 4 ? DSI_PHYC_DLANE3_ENABLE : 0) |
DSI_PORT_BIT(PHYC_CLANE_ENABLE) |
((dsi->mode_flags & MIPI_DSI_CLOCK_NON_CONTINUOUS) ?
0 : DSI_PORT_BIT(PHYC_HS_CLK_CONTINUOUS)) |
(dsi->port == 0 ?
VC4_SET_FIELD(lpx - 1, DSI0_PHYC_ESC_CLK_LPDT) :
VC4_SET_FIELD(lpx - 1, DSI1_PHYC_ESC_CLK_LPDT)));
DSI_PORT_WRITE(CTRL,
DSI_PORT_READ(CTRL) |
DSI_CTRL_CAL_BYTE);
DSI_PORT_WRITE(HSTX_TO_CNT, 0);
DSI_PORT_WRITE(LPRX_TO_CNT, 0xffffff);
DSI_PORT_WRITE(TA_TO_CNT, 100000);
DSI_PORT_WRITE(PR_TO_CNT, 100000);
if (dsi->mode_flags & MIPI_DSI_MODE_VIDEO) {
DSI_PORT_WRITE(DISP0_CTRL,
VC4_SET_FIELD(divider, DSI_DISP0_PIX_CLK_DIV) |
VC4_SET_FIELD(format, DSI_DISP0_PFORMAT) |
VC4_SET_FIELD(DSI_DISP0_LP_STOP_PERFRAME,
DSI_DISP0_LP_STOP_CTRL) |
DSI_DISP0_ST_END |
DSI_DISP0_ENABLE);
} else {
DSI_PORT_WRITE(DISP0_CTRL,
DSI_DISP0_COMMAND_MODE |
DSI_DISP0_ENABLE);
}
DSI_PORT_WRITE(DISP1_CTRL,
VC4_SET_FIELD(DSI_DISP1_PFORMAT_32BIT_LE,
DSI_DISP1_PFORMAT) |
DSI_DISP1_ENABLE);
if (dsi->port == 0)
DSI_PORT_WRITE(CTRL, DSI_PORT_READ(CTRL) | DSI0_CTRL_CTRL0);
else
DSI_PORT_WRITE(CTRL, DSI_PORT_READ(CTRL) | DSI1_CTRL_EN);
if (dsi->port == 0) {
} else {
DSI_PORT_WRITE(PHY_AFEC0,
DSI_PORT_READ(PHY_AFEC0) &
~DSI1_PHY_AFEC0_RESET);
}
vc4_dsi_ulps(dsi, false);
if (debug_dump_regs) {
DRM_INFO("DSI regs after:\n");
vc4_dsi_dump_regs(dsi);
}
ret = drm_panel_enable(dsi->panel);
if (ret) {
DRM_ERROR("Panel failed to enable\n");
drm_panel_unprepare(dsi->panel);
return;
}
}
static ssize_t vc4_dsi_host_transfer(struct mipi_dsi_host *host,
const struct mipi_dsi_msg *msg)
{
struct vc4_dsi *dsi = host_to_dsi(host);
struct mipi_dsi_packet packet;
u32 pkth = 0, pktc = 0;
int i, ret;
bool is_long = mipi_dsi_packet_format_is_long(msg->type);
u32 cmd_fifo_len = 0, pix_fifo_len = 0;
mipi_dsi_create_packet(&packet, msg);
pkth |= VC4_SET_FIELD(packet.header[0], DSI_TXPKT1H_BC_DT);
pkth |= VC4_SET_FIELD(packet.header[1] |
(packet.header[2] << 8),
DSI_TXPKT1H_BC_PARAM);
if (is_long) {
if (packet.payload_length <= 16) {
cmd_fifo_len = packet.payload_length;
pix_fifo_len = 0;
} else {
cmd_fifo_len = (packet.payload_length %
DSI_PIX_FIFO_WIDTH);
pix_fifo_len = ((packet.payload_length - cmd_fifo_len) /
DSI_PIX_FIFO_WIDTH);
}
WARN_ON_ONCE(pix_fifo_len >= DSI_PIX_FIFO_DEPTH);
pkth |= VC4_SET_FIELD(cmd_fifo_len, DSI_TXPKT1H_BC_CMDFIFO);
}
if (msg->rx_len) {
pktc |= VC4_SET_FIELD(DSI_TXPKT1C_CMD_CTRL_RX,
DSI_TXPKT1C_CMD_CTRL);
} else {
pktc |= VC4_SET_FIELD(DSI_TXPKT1C_CMD_CTRL_TX,
DSI_TXPKT1C_CMD_CTRL);
}
for (i = 0; i < cmd_fifo_len; i++)
DSI_PORT_WRITE(TXPKT_CMD_FIFO, packet.payload[i]);
for (i = 0; i < pix_fifo_len; i++) {
const u8 *pix = packet.payload + cmd_fifo_len + i * 4;
DSI_PORT_WRITE(TXPKT_PIX_FIFO,
pix[0] |
pix[1] << 8 |
pix[2] << 16 |
pix[3] << 24);
}
if (msg->flags & MIPI_DSI_MSG_USE_LPM)
pktc |= DSI_TXPKT1C_CMD_MODE_LP;
if (is_long)
pktc |= DSI_TXPKT1C_CMD_TYPE_LONG;
pktc |= VC4_SET_FIELD(1, DSI_TXPKT1C_CMD_REPEAT);
pktc |= DSI_TXPKT1C_CMD_EN;
if (pix_fifo_len) {
pktc |= VC4_SET_FIELD(DSI_TXPKT1C_DISPLAY_NO_SECONDARY,
DSI_TXPKT1C_DISPLAY_NO);
} else {
pktc |= VC4_SET_FIELD(DSI_TXPKT1C_DISPLAY_NO_SHORT,
DSI_TXPKT1C_DISPLAY_NO);
}
dsi->xfer_result = 0;
reinit_completion(&dsi->xfer_completion);
DSI_PORT_WRITE(INT_STAT, DSI1_INT_TXPKT1_DONE | DSI1_INT_PHY_DIR_RTF);
if (msg->rx_len) {
DSI_PORT_WRITE(INT_EN, (DSI1_INTERRUPTS_ALWAYS_ENABLED |
DSI1_INT_PHY_DIR_RTF));
} else {
DSI_PORT_WRITE(INT_EN, (DSI1_INTERRUPTS_ALWAYS_ENABLED |
DSI1_INT_TXPKT1_DONE));
}
DSI_PORT_WRITE(TXPKT1H, pkth);
DSI_PORT_WRITE(TXPKT1C, pktc);
if (!wait_for_completion_timeout(&dsi->xfer_completion,
msecs_to_jiffies(1000))) {
dev_err(&dsi->pdev->dev, "transfer interrupt wait timeout");
dev_err(&dsi->pdev->dev, "instat: 0x%08x\n",
DSI_PORT_READ(INT_STAT));
ret = -ETIMEDOUT;
} else {
ret = dsi->xfer_result;
}
DSI_PORT_WRITE(INT_EN, DSI1_INTERRUPTS_ALWAYS_ENABLED);
if (ret)
goto reset_fifo_and_return;
if (ret == 0 && msg->rx_len) {
u32 rxpkt1h = DSI_PORT_READ(RXPKT1H);
u8 *msg_rx = msg->rx_buf;
if (rxpkt1h & DSI_RXPKT1H_PKT_TYPE_LONG) {
u32 rxlen = VC4_GET_FIELD(rxpkt1h,
DSI_RXPKT1H_BC_PARAM);
if (rxlen != msg->rx_len) {
DRM_ERROR("DSI returned %db, expecting %db\n",
rxlen, (int)msg->rx_len);
ret = -ENXIO;
goto reset_fifo_and_return;
}
for (i = 0; i < msg->rx_len; i++)
msg_rx[i] = DSI_READ(DSI1_RXPKT_FIFO);
} else {
msg_rx[0] = VC4_GET_FIELD(rxpkt1h,
DSI_RXPKT1H_SHORT_0);
if (msg->rx_len > 1) {
msg_rx[1] = VC4_GET_FIELD(rxpkt1h,
DSI_RXPKT1H_SHORT_1);
}
}
}
return ret;
reset_fifo_and_return:
DRM_ERROR("DSI transfer failed, resetting: %d\n", ret);
DSI_PORT_WRITE(TXPKT1C, DSI_PORT_READ(TXPKT1C) & ~DSI_TXPKT1C_CMD_EN);
udelay(1);
DSI_PORT_WRITE(CTRL,
DSI_PORT_READ(CTRL) |
DSI_PORT_BIT(CTRL_RESET_FIFOS));
DSI_PORT_WRITE(TXPKT1C, 0);
DSI_PORT_WRITE(INT_EN, DSI1_INTERRUPTS_ALWAYS_ENABLED);
return ret;
}
static int vc4_dsi_host_attach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct vc4_dsi *dsi = host_to_dsi(host);
int ret = 0;
dsi->lanes = device->lanes;
dsi->channel = device->channel;
dsi->format = device->format;
dsi->mode_flags = device->mode_flags;
if (!(dsi->mode_flags & MIPI_DSI_MODE_VIDEO)) {
dev_err(&dsi->pdev->dev,
"Only VIDEO mode panels supported currently.\n");
return 0;
}
dsi->panel = of_drm_find_panel(device->dev.of_node);
if (!dsi->panel)
return 0;
ret = drm_panel_attach(dsi->panel, dsi->connector);
if (ret != 0)
return ret;
drm_helper_hpd_irq_event(dsi->connector->dev);
return 0;
}
static int vc4_dsi_host_detach(struct mipi_dsi_host *host,
struct mipi_dsi_device *device)
{
struct vc4_dsi *dsi = host_to_dsi(host);
if (dsi->panel) {
int ret = drm_panel_detach(dsi->panel);
if (ret)
return ret;
dsi->panel = NULL;
drm_helper_hpd_irq_event(dsi->connector->dev);
}
return 0;
}
static void dsi_handle_error(struct vc4_dsi *dsi,
irqreturn_t *ret, u32 stat, u32 bit,
const char *type)
{
if (!(stat & bit))
return;
DRM_ERROR("DSI%d: %s error\n", dsi->port, type);
*ret = IRQ_HANDLED;
}
static irqreturn_t vc4_dsi_irq_handler(int irq, void *data)
{
struct vc4_dsi *dsi = data;
u32 stat = DSI_PORT_READ(INT_STAT);
irqreturn_t ret = IRQ_NONE;
DSI_PORT_WRITE(INT_STAT, stat);
dsi_handle_error(dsi, &ret, stat,
DSI1_INT_ERR_SYNC_ESC, "LPDT sync");
dsi_handle_error(dsi, &ret, stat,
DSI1_INT_ERR_CONTROL, "data lane 0 sequence");
dsi_handle_error(dsi, &ret, stat,
DSI1_INT_ERR_CONT_LP0, "LP0 contention");
dsi_handle_error(dsi, &ret, stat,
DSI1_INT_ERR_CONT_LP1, "LP1 contention");
dsi_handle_error(dsi, &ret, stat,
DSI1_INT_HSTX_TO, "HSTX timeout");
dsi_handle_error(dsi, &ret, stat,
DSI1_INT_LPRX_TO, "LPRX timeout");
dsi_handle_error(dsi, &ret, stat,
DSI1_INT_TA_TO, "turnaround timeout");
dsi_handle_error(dsi, &ret, stat,
DSI1_INT_PR_TO, "peripheral reset timeout");
if (stat & (DSI1_INT_TXPKT1_DONE | DSI1_INT_PHY_DIR_RTF)) {
complete(&dsi->xfer_completion);
ret = IRQ_HANDLED;
} else if (stat & DSI1_INT_HSTX_TO) {
complete(&dsi->xfer_completion);
dsi->xfer_result = -ETIMEDOUT;
ret = IRQ_HANDLED;
}
return ret;
}
static int
vc4_dsi_init_phy_clocks(struct vc4_dsi *dsi)
{
struct device *dev = &dsi->pdev->dev;
const char *parent_name = __clk_get_name(dsi->pll_phy_clock);
static const struct {
const char *dsi0_name, *dsi1_name;
int div;
} phy_clocks[] = {
{ "dsi0_byte", "dsi1_byte", 8 },
{ "dsi0_ddr2", "dsi1_ddr2", 4 },
{ "dsi0_ddr", "dsi1_ddr", 2 },
};
int i;
dsi->clk_onecell = devm_kzalloc(dev,
sizeof(*dsi->clk_onecell) +
ARRAY_SIZE(phy_clocks) *
sizeof(struct clk_hw *),
GFP_KERNEL);
if (!dsi->clk_onecell)
return -ENOMEM;
dsi->clk_onecell->num = ARRAY_SIZE(phy_clocks);
for (i = 0; i < ARRAY_SIZE(phy_clocks); i++) {
struct clk_fixed_factor *fix = &dsi->phy_clocks[i];
struct clk_init_data init;
int ret;
fix->mult = 1;
fix->div = phy_clocks[i].div;
fix->hw.init = &init;
memset(&init, 0, sizeof(init));
init.parent_names = &parent_name;
init.num_parents = 1;
if (dsi->port == 1)
init.name = phy_clocks[i].dsi1_name;
else
init.name = phy_clocks[i].dsi0_name;
init.ops = &clk_fixed_factor_ops;
ret = devm_clk_hw_register(dev, &fix->hw);
if (ret)
return ret;
dsi->clk_onecell->hws[i] = &fix->hw;
}
return of_clk_add_hw_provider(dev->of_node,
of_clk_hw_onecell_get,
dsi->clk_onecell);
}
static int vc4_dsi_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_dsi *dsi;
struct vc4_dsi_encoder *vc4_dsi_encoder;
const struct of_device_id *match;
dma_cap_mask_t dma_mask;
int ret;
dsi = devm_kzalloc(dev, sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return -ENOMEM;
match = of_match_device(vc4_dsi_dt_match, dev);
if (!match)
return -ENODEV;
dsi->port = (uintptr_t)match->data;
vc4_dsi_encoder = devm_kzalloc(dev, sizeof(*vc4_dsi_encoder),
GFP_KERNEL);
if (!vc4_dsi_encoder)
return -ENOMEM;
vc4_dsi_encoder->base.type = VC4_ENCODER_TYPE_DSI1;
vc4_dsi_encoder->dsi = dsi;
dsi->encoder = &vc4_dsi_encoder->base.base;
dsi->pdev = pdev;
dsi->regs = vc4_ioremap_regs(pdev, 0);
if (IS_ERR(dsi->regs))
return PTR_ERR(dsi->regs);
if (DSI_PORT_READ(ID) != DSI_ID_VALUE) {
dev_err(dev, "Port returned 0x%08x for ID instead of 0x%08x\n",
DSI_PORT_READ(ID), DSI_ID_VALUE);
return -ENODEV;
}
if (dsi->port == 1) {
dsi->reg_dma_mem = dma_alloc_coherent(dev, 4,
&dsi->reg_dma_paddr,
GFP_KERNEL);
if (!dsi->reg_dma_mem) {
DRM_ERROR("Failed to get DMA memory\n");
return -ENOMEM;
}
dma_cap_zero(dma_mask);
dma_cap_set(DMA_MEMCPY, dma_mask);
dsi->reg_dma_chan = dma_request_chan_by_mask(&dma_mask);
if (IS_ERR(dsi->reg_dma_chan)) {
ret = PTR_ERR(dsi->reg_dma_chan);
if (ret != -EPROBE_DEFER)
DRM_ERROR("Failed to get DMA channel: %d\n",
ret);
return ret;
}
dsi->reg_paddr = be32_to_cpup(of_get_address(dev->of_node,
0, NULL, NULL));
}
init_completion(&dsi->xfer_completion);
DSI_PORT_WRITE(INT_EN, DSI1_INTERRUPTS_ALWAYS_ENABLED);
DSI_PORT_WRITE(INT_STAT, DSI_PORT_READ(INT_STAT));
ret = devm_request_irq(dev, platform_get_irq(pdev, 0),
vc4_dsi_irq_handler, 0, "vc4 dsi", dsi);
if (ret) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get interrupt: %d\n", ret);
return ret;
}
dsi->escape_clock = devm_clk_get(dev, "escape");
if (IS_ERR(dsi->escape_clock)) {
ret = PTR_ERR(dsi->escape_clock);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get escape clock: %d\n", ret);
return ret;
}
dsi->pll_phy_clock = devm_clk_get(dev, "phy");
if (IS_ERR(dsi->pll_phy_clock)) {
ret = PTR_ERR(dsi->pll_phy_clock);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get phy clock: %d\n", ret);
return ret;
}
dsi->pixel_clock = devm_clk_get(dev, "pixel");
if (IS_ERR(dsi->pixel_clock)) {
ret = PTR_ERR(dsi->pixel_clock);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get pixel clock: %d\n", ret);
return ret;
}
ret = clk_set_rate(dsi->escape_clock, 100 * 1000000);
if (ret) {
dev_err(dev, "Failed to set esc clock: %d\n", ret);
return ret;
}
ret = vc4_dsi_init_phy_clocks(dsi);
if (ret)
return ret;
if (dsi->port == 1)
vc4->dsi1 = dsi;
drm_encoder_init(drm, dsi->encoder, &vc4_dsi_encoder_funcs,
DRM_MODE_ENCODER_DSI, NULL);
drm_encoder_helper_add(dsi->encoder, &vc4_dsi_encoder_helper_funcs);
dsi->connector = vc4_dsi_connector_init(drm, dsi);
if (IS_ERR(dsi->connector)) {
ret = PTR_ERR(dsi->connector);
goto err_destroy_encoder;
}
dsi->dsi_host.ops = &vc4_dsi_host_ops;
dsi->dsi_host.dev = dev;
mipi_dsi_host_register(&dsi->dsi_host);
dev_set_drvdata(dev, dsi);
pm_runtime_enable(dev);
return 0;
err_destroy_encoder:
vc4_dsi_encoder_destroy(dsi->encoder);
return ret;
}
static void vc4_dsi_unbind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_dsi *dsi = dev_get_drvdata(dev);
pm_runtime_disable(dev);
vc4_dsi_connector_destroy(dsi->connector);
vc4_dsi_encoder_destroy(dsi->encoder);
mipi_dsi_host_unregister(&dsi->dsi_host);
clk_disable_unprepare(dsi->pll_phy_clock);
clk_disable_unprepare(dsi->escape_clock);
if (dsi->port == 1)
vc4->dsi1 = NULL;
}
static int vc4_dsi_dev_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vc4_dsi_ops);
}
static int vc4_dsi_dev_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vc4_dsi_ops);
return 0;
}
