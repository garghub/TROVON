static u16 txbyteclkhs(u16 pixels, int bpp, int lane_count,
u16 burst_mode_ratio)
{
return DIV_ROUND_UP(DIV_ROUND_UP(pixels * bpp * burst_mode_ratio,
8 * 100), lane_count);
}
static u16 pixels_from_txbyteclkhs(u16 clk_hs, int bpp, int lane_count,
u16 burst_mode_ratio)
{
return DIV_ROUND_UP((clk_hs * lane_count * 8 * 100),
(bpp * burst_mode_ratio));
}
enum mipi_dsi_pixel_format pixel_format_from_register_bits(u32 fmt)
{
switch (fmt) {
case VID_MODE_FORMAT_RGB888:
return MIPI_DSI_FMT_RGB888;
case VID_MODE_FORMAT_RGB666:
return MIPI_DSI_FMT_RGB666;
case VID_MODE_FORMAT_RGB666_PACKED:
return MIPI_DSI_FMT_RGB666_PACKED;
case VID_MODE_FORMAT_RGB565:
return MIPI_DSI_FMT_RGB565;
default:
MISSING_CASE(fmt);
return MIPI_DSI_FMT_RGB666;
}
}
void wait_for_dsi_fifo_empty(struct intel_dsi *intel_dsi, enum port port)
{
struct drm_encoder *encoder = &intel_dsi->base.base;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
u32 mask;
mask = LP_CTRL_FIFO_EMPTY | HS_CTRL_FIFO_EMPTY |
LP_DATA_FIFO_EMPTY | HS_DATA_FIFO_EMPTY;
if (intel_wait_for_register(dev_priv,
MIPI_GEN_FIFO_STAT(port), mask, mask,
100))
DRM_ERROR("DPI FIFOs are not empty\n");
}
static void write_data(struct drm_i915_private *dev_priv,
i915_reg_t reg,
const u8 *data, u32 len)
{
u32 i, j;
for (i = 0; i < len; i += 4) {
u32 val = 0;
for (j = 0; j < min_t(u32, len - i, 4); j++)
val |= *data++ << 8 * j;
I915_WRITE(reg, val);
}
}
static void read_data(struct drm_i915_private *dev_priv,
i915_reg_t reg,
u8 *data, u32 len)
{
u32 i, j;
for (i = 0; i < len; i += 4) {
u32 val = I915_READ(reg);
for (j = 0; j < min_t(u32, len - i, 4); j++)
*data++ = val >> 8 * j;
}
}
static ssize_t intel_dsi_host_transfer(struct mipi_dsi_host *host,
const struct mipi_dsi_msg *msg)
{
struct intel_dsi_host *intel_dsi_host = to_intel_dsi_host(host);
struct drm_device *dev = intel_dsi_host->intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
enum port port = intel_dsi_host->port;
struct mipi_dsi_packet packet;
ssize_t ret;
const u8 *header, *data;
i915_reg_t data_reg, ctrl_reg;
u32 data_mask, ctrl_mask;
ret = mipi_dsi_create_packet(&packet, msg);
if (ret < 0)
return ret;
header = packet.header;
data = packet.payload;
if (msg->flags & MIPI_DSI_MSG_USE_LPM) {
data_reg = MIPI_LP_GEN_DATA(port);
data_mask = LP_DATA_FIFO_FULL;
ctrl_reg = MIPI_LP_GEN_CTRL(port);
ctrl_mask = LP_CTRL_FIFO_FULL;
} else {
data_reg = MIPI_HS_GEN_DATA(port);
data_mask = HS_DATA_FIFO_FULL;
ctrl_reg = MIPI_HS_GEN_CTRL(port);
ctrl_mask = HS_CTRL_FIFO_FULL;
}
if (packet.payload_length) {
if (intel_wait_for_register(dev_priv,
MIPI_GEN_FIFO_STAT(port),
data_mask, 0,
50))
DRM_ERROR("Timeout waiting for HS/LP DATA FIFO !full\n");
write_data(dev_priv, data_reg, packet.payload,
packet.payload_length);
}
if (msg->rx_len) {
I915_WRITE(MIPI_INTR_STAT(port), GEN_READ_DATA_AVAIL);
}
if (intel_wait_for_register(dev_priv,
MIPI_GEN_FIFO_STAT(port),
ctrl_mask, 0,
50)) {
DRM_ERROR("Timeout waiting for HS/LP CTRL FIFO !full\n");
}
I915_WRITE(ctrl_reg, header[2] << 16 | header[1] << 8 | header[0]);
if (msg->rx_len) {
data_mask = GEN_READ_DATA_AVAIL;
if (intel_wait_for_register(dev_priv,
MIPI_INTR_STAT(port),
data_mask, data_mask,
50))
DRM_ERROR("Timeout waiting for read data.\n");
read_data(dev_priv, data_reg, msg->rx_buf, msg->rx_len);
}
return 4 + packet.payload_length;
}
static int intel_dsi_host_attach(struct mipi_dsi_host *host,
struct mipi_dsi_device *dsi)
{
return 0;
}
static int intel_dsi_host_detach(struct mipi_dsi_host *host,
struct mipi_dsi_device *dsi)
{
return 0;
}
static struct intel_dsi_host *intel_dsi_host_init(struct intel_dsi *intel_dsi,
enum port port)
{
struct intel_dsi_host *host;
struct mipi_dsi_device *device;
host = kzalloc(sizeof(*host), GFP_KERNEL);
if (!host)
return NULL;
host->base.ops = &intel_dsi_host_ops;
host->intel_dsi = intel_dsi;
host->port = port;
device = kzalloc(sizeof(*device), GFP_KERNEL);
if (!device) {
kfree(host);
return NULL;
}
device->host = &host->base;
host->device = device;
return host;
}
static int dpi_send_cmd(struct intel_dsi *intel_dsi, u32 cmd, bool hs,
enum port port)
{
struct drm_encoder *encoder = &intel_dsi->base.base;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
u32 mask;
if (hs)
cmd &= ~DPI_LP_MODE;
else
cmd |= DPI_LP_MODE;
I915_WRITE(MIPI_INTR_STAT(port), SPL_PKT_SENT_INTERRUPT);
if (cmd == I915_READ(MIPI_DPI_CONTROL(port)))
DRM_ERROR("Same special packet %02x twice in a row.\n", cmd);
I915_WRITE(MIPI_DPI_CONTROL(port), cmd);
mask = SPL_PKT_SENT_INTERRUPT;
if (intel_wait_for_register(dev_priv,
MIPI_INTR_STAT(port), mask, mask,
100))
DRM_ERROR("Video mode command 0x%08x send failed.\n", cmd);
return 0;
}
static void band_gap_reset(struct drm_i915_private *dev_priv)
{
mutex_lock(&dev_priv->sb_lock);
vlv_flisdsi_write(dev_priv, 0x08, 0x0001);
vlv_flisdsi_write(dev_priv, 0x0F, 0x0005);
vlv_flisdsi_write(dev_priv, 0x0F, 0x0025);
udelay(150);
vlv_flisdsi_write(dev_priv, 0x0F, 0x0000);
vlv_flisdsi_write(dev_priv, 0x08, 0x0000);
mutex_unlock(&dev_priv->sb_lock);
}
static inline bool is_vid_mode(struct intel_dsi *intel_dsi)
{
return intel_dsi->operation_mode == INTEL_DSI_VIDEO_MODE;
}
static inline bool is_cmd_mode(struct intel_dsi *intel_dsi)
{
return intel_dsi->operation_mode == INTEL_DSI_COMMAND_MODE;
}
static bool intel_dsi_compute_config(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config,
struct drm_connector_state *conn_state)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = container_of(encoder, struct intel_dsi,
base);
struct intel_connector *intel_connector = intel_dsi->attached_connector;
struct intel_crtc *crtc = to_intel_crtc(pipe_config->base.crtc);
const struct drm_display_mode *fixed_mode = intel_connector->panel.fixed_mode;
struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
int ret;
DRM_DEBUG_KMS("\n");
if (fixed_mode) {
intel_fixed_panel_mode(fixed_mode, adjusted_mode);
if (HAS_GMCH_DISPLAY(dev_priv))
intel_gmch_panel_fitting(crtc, pipe_config,
conn_state->scaling_mode);
else
intel_pch_panel_fitting(crtc, pipe_config,
conn_state->scaling_mode);
}
adjusted_mode->flags = 0;
if (IS_GEN9_LP(dev_priv)) {
if (intel_dsi->ports == BIT(PORT_C))
pipe_config->cpu_transcoder = TRANSCODER_DSI_C;
else
pipe_config->cpu_transcoder = TRANSCODER_DSI_A;
}
ret = intel_compute_dsi_pll(encoder, pipe_config);
if (ret)
return false;
pipe_config->clock_set = true;
return true;
}
static bool glk_dsi_enable_io(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 tmp;
bool cold_boot = false;
for_each_dsi_port(port, intel_dsi->ports) {
tmp = I915_READ(MIPI_CTRL(port));
I915_WRITE(MIPI_CTRL(port), tmp | GLK_MIPIIO_ENABLE);
}
tmp = I915_READ(MIPI_CTRL(PORT_A));
tmp &= ~GLK_MIPIIO_RESET_RELEASED;
I915_WRITE(MIPI_CTRL(PORT_A), tmp);
for_each_dsi_port(port, intel_dsi->ports) {
tmp = I915_READ(MIPI_CTRL(port));
if (!(I915_READ(MIPI_DEVICE_READY(port)) & DEVICE_READY))
tmp &= ~GLK_LP_WAKE;
else
tmp |= GLK_LP_WAKE;
I915_WRITE(MIPI_CTRL(port), tmp);
}
for_each_dsi_port(port, intel_dsi->ports) {
if (intel_wait_for_register(dev_priv,
MIPI_CTRL(port), GLK_MIPIIO_PORT_POWERED,
GLK_MIPIIO_PORT_POWERED, 20))
DRM_ERROR("MIPIO port is powergated\n");
}
for_each_dsi_port(port, intel_dsi->ports) {
cold_boot |= !(I915_READ(MIPI_DEVICE_READY(port)) &
DEVICE_READY);
}
return cold_boot;
}
static void glk_dsi_device_ready(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 val;
for_each_dsi_port(port, intel_dsi->ports) {
if (intel_wait_for_register(dev_priv,
MIPI_CTRL(port), GLK_PHY_STATUS_PORT_READY,
GLK_PHY_STATUS_PORT_READY, 20))
DRM_ERROR("PHY is not ON\n");
}
val = I915_READ(MIPI_CTRL(PORT_A));
I915_WRITE(MIPI_CTRL(PORT_A), val | GLK_MIPIIO_RESET_RELEASED);
for_each_dsi_port(port, intel_dsi->ports) {
if (!(I915_READ(MIPI_DEVICE_READY(port)) & DEVICE_READY)) {
val = I915_READ(MIPI_DEVICE_READY(port));
val &= ~ULPS_STATE_MASK;
val |= DEVICE_READY;
I915_WRITE(MIPI_DEVICE_READY(port), val);
usleep_range(10, 15);
} else {
val = I915_READ(MIPI_DEVICE_READY(port));
val &= ~ULPS_STATE_MASK;
val |= (ULPS_STATE_ENTER | DEVICE_READY);
I915_WRITE(MIPI_DEVICE_READY(port), val);
if (intel_wait_for_register(dev_priv,
MIPI_CTRL(port), GLK_ULPS_NOT_ACTIVE, 0, 20))
DRM_ERROR("ULPS not active\n");
val = I915_READ(MIPI_DEVICE_READY(port));
val &= ~ULPS_STATE_MASK;
val |= (ULPS_STATE_EXIT | DEVICE_READY);
I915_WRITE(MIPI_DEVICE_READY(port), val);
val = I915_READ(MIPI_DEVICE_READY(port));
val &= ~ULPS_STATE_MASK;
val |= (ULPS_STATE_NORMAL_OPERATION | DEVICE_READY);
I915_WRITE(MIPI_DEVICE_READY(port), val);
val = I915_READ(MIPI_CTRL(port));
val &= ~GLK_LP_WAKE;
I915_WRITE(MIPI_CTRL(port), val);
}
}
for_each_dsi_port(port, intel_dsi->ports) {
if (intel_wait_for_register(dev_priv,
MIPI_CTRL(port), GLK_DATA_LANE_STOP_STATE,
GLK_DATA_LANE_STOP_STATE, 20))
DRM_ERROR("Date lane not in STOP state\n");
}
for_each_dsi_port(port, intel_dsi->ports) {
if (intel_wait_for_register(dev_priv,
BXT_MIPI_PORT_CTRL(port), AFE_LATCHOUT,
AFE_LATCHOUT, 20))
DRM_ERROR("D-PHY not entering LP-11 state\n");
}
}
static void bxt_dsi_device_ready(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 val;
DRM_DEBUG_KMS("\n");
for_each_dsi_port(port, intel_dsi->ports) {
val = I915_READ(BXT_MIPI_PORT_CTRL(port));
I915_WRITE(BXT_MIPI_PORT_CTRL(port), val | LP_OUTPUT_HOLD);
usleep_range(2000, 2500);
}
for_each_dsi_port(port, intel_dsi->ports) {
val = I915_READ(MIPI_DEVICE_READY(port));
val &= ~ULPS_STATE_MASK;
I915_WRITE(MIPI_DEVICE_READY(port), val);
usleep_range(2000, 2500);
val |= DEVICE_READY;
I915_WRITE(MIPI_DEVICE_READY(port), val);
}
}
static void vlv_dsi_device_ready(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 val;
DRM_DEBUG_KMS("\n");
mutex_lock(&dev_priv->sb_lock);
vlv_flisdsi_write(dev_priv, 0x04, 0x0004);
mutex_unlock(&dev_priv->sb_lock);
band_gap_reset(dev_priv);
for_each_dsi_port(port, intel_dsi->ports) {
I915_WRITE(MIPI_DEVICE_READY(port), ULPS_STATE_ENTER);
usleep_range(2500, 3000);
val = I915_READ(MIPI_PORT_CTRL(PORT_A));
I915_WRITE(MIPI_PORT_CTRL(PORT_A), val | LP_OUTPUT_HOLD);
usleep_range(1000, 1500);
I915_WRITE(MIPI_DEVICE_READY(port), ULPS_STATE_EXIT);
usleep_range(2500, 3000);
I915_WRITE(MIPI_DEVICE_READY(port), DEVICE_READY);
usleep_range(2500, 3000);
}
}
static void intel_dsi_device_ready(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
vlv_dsi_device_ready(encoder);
else if (IS_BROXTON(dev_priv))
bxt_dsi_device_ready(encoder);
else if (IS_GEMINILAKE(dev_priv))
glk_dsi_device_ready(encoder);
}
static void glk_dsi_enter_low_power_mode(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 val;
for_each_dsi_port(port, intel_dsi->ports) {
val = I915_READ(MIPI_DEVICE_READY(port));
val &= ~ULPS_STATE_MASK;
val |= (ULPS_STATE_ENTER | DEVICE_READY);
I915_WRITE(MIPI_DEVICE_READY(port), val);
}
for_each_dsi_port(port, intel_dsi->ports) {
if (intel_wait_for_register(dev_priv,
MIPI_CTRL(port),
GLK_PHY_STATUS_PORT_READY, 0, 20))
DRM_ERROR("PHY is not turning OFF\n");
}
for_each_dsi_port(port, intel_dsi->ports) {
if (intel_wait_for_register(dev_priv,
MIPI_CTRL(port),
GLK_MIPIIO_PORT_POWERED, 0, 20))
DRM_ERROR("MIPI IO Port is not powergated\n");
}
}
static void glk_dsi_disable_mipi_io(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 tmp;
tmp = I915_READ(MIPI_CTRL(PORT_A));
tmp &= ~GLK_MIPIIO_RESET_RELEASED;
I915_WRITE(MIPI_CTRL(PORT_A), tmp);
for_each_dsi_port(port, intel_dsi->ports) {
if (intel_wait_for_register(dev_priv,
MIPI_CTRL(port),
GLK_PHY_STATUS_PORT_READY, 0, 20))
DRM_ERROR("PHY is not turning OFF\n");
}
for_each_dsi_port(port, intel_dsi->ports) {
tmp = I915_READ(MIPI_CTRL(port));
tmp &= ~GLK_MIPIIO_ENABLE;
I915_WRITE(MIPI_CTRL(port), tmp);
}
}
static void glk_dsi_clear_device_ready(struct intel_encoder *encoder)
{
glk_dsi_enter_low_power_mode(encoder);
glk_dsi_disable_mipi_io(encoder);
}
static void vlv_dsi_clear_device_ready(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
DRM_DEBUG_KMS("\n");
for_each_dsi_port(port, intel_dsi->ports) {
i915_reg_t port_ctrl = IS_GEN9_LP(dev_priv) ?
BXT_MIPI_PORT_CTRL(port) : MIPI_PORT_CTRL(PORT_A);
u32 val;
I915_WRITE(MIPI_DEVICE_READY(port), DEVICE_READY |
ULPS_STATE_ENTER);
usleep_range(2000, 2500);
I915_WRITE(MIPI_DEVICE_READY(port), DEVICE_READY |
ULPS_STATE_EXIT);
usleep_range(2000, 2500);
I915_WRITE(MIPI_DEVICE_READY(port), DEVICE_READY |
ULPS_STATE_ENTER);
usleep_range(2000, 2500);
if ((IS_GEN9_LP(dev_priv) || port == PORT_A) &&
intel_wait_for_register(dev_priv,
port_ctrl, AFE_LATCHOUT, 0,
30))
DRM_ERROR("DSI LP not going Low\n");
val = I915_READ(port_ctrl);
I915_WRITE(port_ctrl, val & ~LP_OUTPUT_HOLD);
usleep_range(1000, 1500);
I915_WRITE(MIPI_DEVICE_READY(port), 0x00);
usleep_range(2000, 2500);
}
}
static void intel_dsi_port_enable(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
if (intel_dsi->dual_link == DSI_DUAL_LINK_FRONT_BACK) {
u32 temp;
if (IS_GEN9_LP(dev_priv)) {
for_each_dsi_port(port, intel_dsi->ports) {
temp = I915_READ(MIPI_CTRL(port));
temp &= ~BXT_PIXEL_OVERLAP_CNT_MASK |
intel_dsi->pixel_overlap <<
BXT_PIXEL_OVERLAP_CNT_SHIFT;
I915_WRITE(MIPI_CTRL(port), temp);
}
} else {
temp = I915_READ(VLV_CHICKEN_3);
temp &= ~PIXEL_OVERLAP_CNT_MASK |
intel_dsi->pixel_overlap <<
PIXEL_OVERLAP_CNT_SHIFT;
I915_WRITE(VLV_CHICKEN_3, temp);
}
}
for_each_dsi_port(port, intel_dsi->ports) {
i915_reg_t port_ctrl = IS_GEN9_LP(dev_priv) ?
BXT_MIPI_PORT_CTRL(port) : MIPI_PORT_CTRL(port);
u32 temp;
temp = I915_READ(port_ctrl);
temp &= ~LANE_CONFIGURATION_MASK;
temp &= ~DUAL_LINK_MODE_MASK;
if (intel_dsi->ports == (BIT(PORT_A) | BIT(PORT_C))) {
temp |= (intel_dsi->dual_link - 1)
<< DUAL_LINK_MODE_SHIFT;
if (IS_BROXTON(dev_priv))
temp |= LANE_CONFIGURATION_DUAL_LINK_A;
else
temp |= intel_crtc->pipe ?
LANE_CONFIGURATION_DUAL_LINK_B :
LANE_CONFIGURATION_DUAL_LINK_A;
}
I915_WRITE(port_ctrl, temp | DPI_ENABLE);
POSTING_READ(port_ctrl);
}
}
static void intel_dsi_port_disable(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
for_each_dsi_port(port, intel_dsi->ports) {
i915_reg_t port_ctrl = IS_GEN9_LP(dev_priv) ?
BXT_MIPI_PORT_CTRL(port) : MIPI_PORT_CTRL(port);
u32 temp;
temp = I915_READ(port_ctrl);
I915_WRITE(port_ctrl, temp & ~DPI_ENABLE);
POSTING_READ(port_ctrl);
}
}
static void intel_dsi_msleep(struct intel_dsi *intel_dsi, int msec)
{
struct drm_i915_private *dev_priv = to_i915(intel_dsi->base.base.dev);
if (is_vid_mode(intel_dsi) && dev_priv->vbt.dsi.seq_version >= 3)
return;
msleep(msec);
}
static void intel_dsi_pre_enable(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config,
struct drm_connector_state *conn_state)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 val;
bool glk_cold_boot = false;
DRM_DEBUG_KMS("\n");
intel_disable_dsi_pll(encoder);
intel_enable_dsi_pll(encoder, pipe_config);
if (IS_BROXTON(dev_priv)) {
val = I915_READ(BXT_P_CR_GT_DISP_PWRON);
I915_WRITE(BXT_P_CR_GT_DISP_PWRON,
val | MIPIO_RST_CTRL);
I915_WRITE(BXT_P_DSI_REGULATOR_CFG, STAP_SELECT);
I915_WRITE(BXT_P_DSI_REGULATOR_TX_CTRL, 0);
}
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
u32 val;
val = I915_READ(DSPCLK_GATE_D);
val |= DPOUNIT_CLOCK_GATE_DISABLE;
I915_WRITE(DSPCLK_GATE_D, val);
}
if (!IS_GEMINILAKE(dev_priv))
intel_dsi_prepare(encoder, pipe_config);
if (intel_dsi->gpio_panel)
gpiod_set_value_cansleep(intel_dsi->gpio_panel, 1);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_POWER_ON);
intel_dsi_msleep(intel_dsi, intel_dsi->panel_on_delay);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_DEASSERT_RESET);
if (IS_GEMINILAKE(dev_priv)) {
glk_cold_boot = glk_dsi_enable_io(encoder);
if (glk_cold_boot)
intel_dsi_prepare(encoder, pipe_config);
}
intel_dsi_device_ready(encoder);
if (IS_GEMINILAKE(dev_priv) && !glk_cold_boot)
intel_dsi_prepare(encoder, pipe_config);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_INIT_OTP);
if (is_cmd_mode(intel_dsi)) {
for_each_dsi_port(port, intel_dsi->ports)
I915_WRITE(MIPI_MAX_RETURN_PKT_SIZE(port), 8 * 4);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_TEAR_ON);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_DISPLAY_ON);
} else {
msleep(20);
for_each_dsi_port(port, intel_dsi->ports)
dpi_send_cmd(intel_dsi, TURN_ON, false, port);
intel_dsi_msleep(intel_dsi, 100);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_DISPLAY_ON);
intel_dsi_port_enable(encoder);
}
intel_panel_enable_backlight(pipe_config, conn_state);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_BACKLIGHT_ON);
}
static void intel_dsi_enable_nop(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config,
struct drm_connector_state *conn_state)
{
DRM_DEBUG_KMS("\n");
}
static void intel_dsi_disable(struct intel_encoder *encoder,
struct intel_crtc_state *old_crtc_state,
struct drm_connector_state *old_conn_state)
{
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
DRM_DEBUG_KMS("\n");
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_BACKLIGHT_OFF);
intel_panel_disable_backlight(old_conn_state);
if (is_vid_mode(intel_dsi)) {
for_each_dsi_port(port, intel_dsi->ports)
dpi_send_cmd(intel_dsi, SHUTDOWN, false, port);
msleep(10);
}
}
static void intel_dsi_clear_device_ready(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv) ||
IS_BROXTON(dev_priv))
vlv_dsi_clear_device_ready(encoder);
else if (IS_GEMINILAKE(dev_priv))
glk_dsi_clear_device_ready(encoder);
}
static void intel_dsi_post_disable(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config,
struct drm_connector_state *conn_state)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 val;
DRM_DEBUG_KMS("\n");
if (is_vid_mode(intel_dsi)) {
for_each_dsi_port(port, intel_dsi->ports)
wait_for_dsi_fifo_empty(intel_dsi, port);
intel_dsi_port_disable(encoder);
usleep_range(2000, 5000);
}
intel_dsi_unprepare(encoder);
if (is_cmd_mode(intel_dsi))
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_TEAR_OFF);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_DISPLAY_OFF);
intel_dsi_clear_device_ready(encoder);
if (IS_BROXTON(dev_priv)) {
I915_WRITE(BXT_P_DSI_REGULATOR_CFG, STAP_SELECT);
I915_WRITE(BXT_P_DSI_REGULATOR_TX_CTRL, HS_IO_CTRL_SELECT);
val = I915_READ(BXT_P_CR_GT_DISP_PWRON);
I915_WRITE(BXT_P_CR_GT_DISP_PWRON,
val & ~MIPIO_RST_CTRL);
}
intel_disable_dsi_pll(encoder);
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
u32 val;
val = I915_READ(DSPCLK_GATE_D);
val &= ~DPOUNIT_CLOCK_GATE_DISABLE;
I915_WRITE(DSPCLK_GATE_D, val);
}
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_ASSERT_RESET);
intel_dsi_msleep(intel_dsi, intel_dsi->panel_off_delay);
intel_dsi_vbt_exec_sequence(intel_dsi, MIPI_SEQ_POWER_OFF);
if (intel_dsi->gpio_panel)
gpiod_set_value_cansleep(intel_dsi->gpio_panel, 0);
intel_dsi_msleep(intel_dsi, intel_dsi->panel_pwr_cycle_delay);
}
static bool intel_dsi_get_hw_state(struct intel_encoder *encoder,
enum pipe *pipe)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
bool active = false;
DRM_DEBUG_KMS("\n");
if (!intel_display_power_get_if_enabled(dev_priv,
encoder->power_domain))
return false;
if (IS_GEN9_LP(dev_priv) && !intel_dsi_pll_is_enabled(dev_priv))
goto out_put_power;
for_each_dsi_port(port, intel_dsi->ports) {
i915_reg_t ctrl_reg = IS_GEN9_LP(dev_priv) ?
BXT_MIPI_PORT_CTRL(port) : MIPI_PORT_CTRL(port);
bool enabled = I915_READ(ctrl_reg) & DPI_ENABLE;
if ((IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) &&
port == PORT_C)
enabled = I915_READ(PIPECONF(PIPE_B)) & PIPECONF_ENABLE;
if (!enabled) {
u32 tmp = I915_READ(MIPI_DSI_FUNC_PRG(port));
enabled = tmp & CMD_MODE_DATA_WIDTH_MASK;
}
if (!enabled)
continue;
if (!(I915_READ(MIPI_DEVICE_READY(port)) & DEVICE_READY))
continue;
if (IS_GEN9_LP(dev_priv)) {
u32 tmp = I915_READ(MIPI_CTRL(port));
tmp &= BXT_PIPE_SELECT_MASK;
tmp >>= BXT_PIPE_SELECT_SHIFT;
if (WARN_ON(tmp > PIPE_C))
continue;
*pipe = tmp;
} else {
*pipe = port == PORT_A ? PIPE_A : PIPE_B;
}
active = true;
break;
}
out_put_power:
intel_display_power_put(dev_priv, encoder->power_domain);
return active;
}
static void bxt_dsi_get_pipe_config(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_display_mode *adjusted_mode =
&pipe_config->base.adjusted_mode;
struct drm_display_mode *adjusted_mode_sw;
struct intel_crtc *intel_crtc;
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
unsigned int lane_count = intel_dsi->lane_count;
unsigned int bpp, fmt;
enum port port;
u16 hactive, hfp, hsync, hbp, vfp, vsync, vbp;
u16 hfp_sw, hsync_sw, hbp_sw;
u16 crtc_htotal_sw, crtc_hsync_start_sw, crtc_hsync_end_sw,
crtc_hblank_start_sw, crtc_hblank_end_sw;
intel_crtc = to_intel_crtc(encoder->base.crtc);
adjusted_mode_sw = &intel_crtc->config->base.adjusted_mode;
for_each_dsi_port(port, intel_dsi->ports) {
if (I915_READ(BXT_MIPI_PORT_CTRL(port)) & DPI_ENABLE)
break;
}
fmt = I915_READ(MIPI_DSI_FUNC_PRG(port)) & VID_MODE_FORMAT_MASK;
pipe_config->pipe_bpp =
mipi_dsi_pixel_format_to_bpp(
pixel_format_from_register_bits(fmt));
bpp = pipe_config->pipe_bpp;
adjusted_mode->crtc_hdisplay =
I915_READ(BXT_MIPI_TRANS_HACTIVE(port));
adjusted_mode->crtc_vdisplay =
I915_READ(BXT_MIPI_TRANS_VACTIVE(port));
adjusted_mode->crtc_vtotal =
I915_READ(BXT_MIPI_TRANS_VTOTAL(port));
hactive = adjusted_mode->crtc_hdisplay;
hfp = I915_READ(MIPI_HFP_COUNT(port));
hsync = I915_READ(MIPI_HSYNC_PADDING_COUNT(port));
hbp = I915_READ(MIPI_HBP_COUNT(port));
hfp = pixels_from_txbyteclkhs(hfp, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hsync = pixels_from_txbyteclkhs(hsync, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hbp = pixels_from_txbyteclkhs(hbp, bpp, lane_count,
intel_dsi->burst_mode_ratio);
if (intel_dsi->dual_link) {
hfp *= 2;
hsync *= 2;
hbp *= 2;
}
vfp = I915_READ(MIPI_VFP_COUNT(port));
vsync = I915_READ(MIPI_VSYNC_PADDING_COUNT(port));
vbp = I915_READ(MIPI_VBP_COUNT(port));
adjusted_mode->crtc_htotal = hactive + hfp + hsync + hbp;
adjusted_mode->crtc_hsync_start = hfp + adjusted_mode->crtc_hdisplay;
adjusted_mode->crtc_hsync_end = hsync + adjusted_mode->crtc_hsync_start;
adjusted_mode->crtc_hblank_start = adjusted_mode->crtc_hdisplay;
adjusted_mode->crtc_hblank_end = adjusted_mode->crtc_htotal;
adjusted_mode->crtc_vsync_start = vfp + adjusted_mode->crtc_vdisplay;
adjusted_mode->crtc_vsync_end = vsync + adjusted_mode->crtc_vsync_start;
adjusted_mode->crtc_vblank_start = adjusted_mode->crtc_vdisplay;
adjusted_mode->crtc_vblank_end = adjusted_mode->crtc_vtotal;
hfp_sw = adjusted_mode_sw->crtc_hsync_start -
adjusted_mode_sw->crtc_hdisplay;
hsync_sw = adjusted_mode_sw->crtc_hsync_end -
adjusted_mode_sw->crtc_hsync_start;
hbp_sw = adjusted_mode_sw->crtc_htotal -
adjusted_mode_sw->crtc_hsync_end;
if (intel_dsi->dual_link) {
hfp_sw /= 2;
hsync_sw /= 2;
hbp_sw /= 2;
}
hfp_sw = txbyteclkhs(hfp_sw, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hsync_sw = txbyteclkhs(hsync_sw, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hbp_sw = txbyteclkhs(hbp_sw, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hfp_sw = pixels_from_txbyteclkhs(hfp_sw, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hsync_sw = pixels_from_txbyteclkhs(hsync_sw, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hbp_sw = pixels_from_txbyteclkhs(hbp_sw, bpp, lane_count,
intel_dsi->burst_mode_ratio);
if (intel_dsi->dual_link) {
hfp_sw *= 2;
hsync_sw *= 2;
hbp_sw *= 2;
}
crtc_htotal_sw = adjusted_mode_sw->crtc_hdisplay + hfp_sw +
hsync_sw + hbp_sw;
crtc_hsync_start_sw = hfp_sw + adjusted_mode_sw->crtc_hdisplay;
crtc_hsync_end_sw = hsync_sw + crtc_hsync_start_sw;
crtc_hblank_start_sw = adjusted_mode_sw->crtc_hdisplay;
crtc_hblank_end_sw = crtc_htotal_sw;
if (adjusted_mode->crtc_htotal == crtc_htotal_sw)
adjusted_mode->crtc_htotal = adjusted_mode_sw->crtc_htotal;
if (adjusted_mode->crtc_hsync_start == crtc_hsync_start_sw)
adjusted_mode->crtc_hsync_start =
adjusted_mode_sw->crtc_hsync_start;
if (adjusted_mode->crtc_hsync_end == crtc_hsync_end_sw)
adjusted_mode->crtc_hsync_end =
adjusted_mode_sw->crtc_hsync_end;
if (adjusted_mode->crtc_hblank_start == crtc_hblank_start_sw)
adjusted_mode->crtc_hblank_start =
adjusted_mode_sw->crtc_hblank_start;
if (adjusted_mode->crtc_hblank_end == crtc_hblank_end_sw)
adjusted_mode->crtc_hblank_end =
adjusted_mode_sw->crtc_hblank_end;
}
static void intel_dsi_get_config(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
u32 pclk;
DRM_DEBUG_KMS("\n");
if (IS_GEN9_LP(dev_priv))
bxt_dsi_get_pipe_config(encoder, pipe_config);
pclk = intel_dsi_get_pclk(encoder, pipe_config->pipe_bpp,
pipe_config);
if (!pclk)
return;
pipe_config->base.adjusted_mode.crtc_clock = pclk;
pipe_config->port_clock = pclk;
}
static enum drm_mode_status
intel_dsi_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct intel_connector *intel_connector = to_intel_connector(connector);
const struct drm_display_mode *fixed_mode = intel_connector->panel.fixed_mode;
int max_dotclk = to_i915(connector->dev)->max_dotclk_freq;
DRM_DEBUG_KMS("\n");
if (mode->flags & DRM_MODE_FLAG_DBLSCAN) {
DRM_DEBUG_KMS("MODE_NO_DBLESCAN\n");
return MODE_NO_DBLESCAN;
}
if (fixed_mode) {
if (mode->hdisplay > fixed_mode->hdisplay)
return MODE_PANEL;
if (mode->vdisplay > fixed_mode->vdisplay)
return MODE_PANEL;
if (fixed_mode->clock > max_dotclk)
return MODE_CLOCK_HIGH;
}
return MODE_OK;
}
static u16 txclkesc(u32 divider, unsigned int us)
{
switch (divider) {
case ESCAPE_CLOCK_DIVIDER_1:
default:
return 20 * us;
case ESCAPE_CLOCK_DIVIDER_2:
return 10 * us;
case ESCAPE_CLOCK_DIVIDER_4:
return 5 * us;
}
}
static void set_dsi_timings(struct drm_encoder *encoder,
const struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(encoder);
enum port port;
unsigned int bpp = mipi_dsi_pixel_format_to_bpp(intel_dsi->pixel_format);
unsigned int lane_count = intel_dsi->lane_count;
u16 hactive, hfp, hsync, hbp, vfp, vsync, vbp;
hactive = adjusted_mode->crtc_hdisplay;
hfp = adjusted_mode->crtc_hsync_start - adjusted_mode->crtc_hdisplay;
hsync = adjusted_mode->crtc_hsync_end - adjusted_mode->crtc_hsync_start;
hbp = adjusted_mode->crtc_htotal - adjusted_mode->crtc_hsync_end;
if (intel_dsi->dual_link) {
hactive /= 2;
if (intel_dsi->dual_link == DSI_DUAL_LINK_FRONT_BACK)
hactive += intel_dsi->pixel_overlap;
hfp /= 2;
hsync /= 2;
hbp /= 2;
}
vfp = adjusted_mode->crtc_vsync_start - adjusted_mode->crtc_vdisplay;
vsync = adjusted_mode->crtc_vsync_end - adjusted_mode->crtc_vsync_start;
vbp = adjusted_mode->crtc_vtotal - adjusted_mode->crtc_vsync_end;
hactive = txbyteclkhs(hactive, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hfp = txbyteclkhs(hfp, bpp, lane_count, intel_dsi->burst_mode_ratio);
hsync = txbyteclkhs(hsync, bpp, lane_count,
intel_dsi->burst_mode_ratio);
hbp = txbyteclkhs(hbp, bpp, lane_count, intel_dsi->burst_mode_ratio);
for_each_dsi_port(port, intel_dsi->ports) {
if (IS_GEN9_LP(dev_priv)) {
I915_WRITE(BXT_MIPI_TRANS_HACTIVE(port),
adjusted_mode->crtc_hdisplay);
I915_WRITE(BXT_MIPI_TRANS_VACTIVE(port),
adjusted_mode->crtc_vdisplay);
I915_WRITE(BXT_MIPI_TRANS_VTOTAL(port),
adjusted_mode->crtc_vtotal);
}
I915_WRITE(MIPI_HACTIVE_AREA_COUNT(port), hactive);
I915_WRITE(MIPI_HFP_COUNT(port), hfp);
I915_WRITE(MIPI_HSYNC_PADDING_COUNT(port), hsync);
I915_WRITE(MIPI_HBP_COUNT(port), hbp);
I915_WRITE(MIPI_VFP_COUNT(port), vfp);
I915_WRITE(MIPI_VSYNC_PADDING_COUNT(port), vsync);
I915_WRITE(MIPI_VBP_COUNT(port), vbp);
}
}
static u32 pixel_format_to_reg(enum mipi_dsi_pixel_format fmt)
{
switch (fmt) {
case MIPI_DSI_FMT_RGB888:
return VID_MODE_FORMAT_RGB888;
case MIPI_DSI_FMT_RGB666:
return VID_MODE_FORMAT_RGB666;
case MIPI_DSI_FMT_RGB666_PACKED:
return VID_MODE_FORMAT_RGB666_PACKED;
case MIPI_DSI_FMT_RGB565:
return VID_MODE_FORMAT_RGB565;
default:
MISSING_CASE(fmt);
return VID_MODE_FORMAT_RGB666;
}
}
static void intel_dsi_prepare(struct intel_encoder *intel_encoder,
struct intel_crtc_state *pipe_config)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_crtc *intel_crtc = to_intel_crtc(pipe_config->base.crtc);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(encoder);
const struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
enum port port;
unsigned int bpp = mipi_dsi_pixel_format_to_bpp(intel_dsi->pixel_format);
u32 val, tmp;
u16 mode_hdisplay;
DRM_DEBUG_KMS("pipe %c\n", pipe_name(intel_crtc->pipe));
mode_hdisplay = adjusted_mode->crtc_hdisplay;
if (intel_dsi->dual_link) {
mode_hdisplay /= 2;
if (intel_dsi->dual_link == DSI_DUAL_LINK_FRONT_BACK)
mode_hdisplay += intel_dsi->pixel_overlap;
}
for_each_dsi_port(port, intel_dsi->ports) {
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
tmp = I915_READ(MIPI_CTRL(PORT_A));
tmp &= ~ESCAPE_CLOCK_DIVIDER_MASK;
I915_WRITE(MIPI_CTRL(PORT_A), tmp |
ESCAPE_CLOCK_DIVIDER_1);
tmp = I915_READ(MIPI_CTRL(port));
tmp &= ~READ_REQUEST_PRIORITY_MASK;
I915_WRITE(MIPI_CTRL(port), tmp |
READ_REQUEST_PRIORITY_HIGH);
} else if (IS_GEN9_LP(dev_priv)) {
enum pipe pipe = intel_crtc->pipe;
tmp = I915_READ(MIPI_CTRL(port));
tmp &= ~BXT_PIPE_SELECT_MASK;
tmp |= BXT_PIPE_SELECT(pipe);
I915_WRITE(MIPI_CTRL(port), tmp);
}
I915_WRITE(MIPI_INTR_STAT(port), 0xffffffff);
I915_WRITE(MIPI_INTR_EN(port), 0xffffffff);
I915_WRITE(MIPI_DPHY_PARAM(port), intel_dsi->dphy_reg);
I915_WRITE(MIPI_DPI_RESOLUTION(port),
adjusted_mode->crtc_vdisplay << VERTICAL_ADDRESS_SHIFT |
mode_hdisplay << HORIZONTAL_ADDRESS_SHIFT);
}
set_dsi_timings(encoder, adjusted_mode);
val = intel_dsi->lane_count << DATA_LANES_PRG_REG_SHIFT;
if (is_cmd_mode(intel_dsi)) {
val |= intel_dsi->channel << CMD_MODE_CHANNEL_NUMBER_SHIFT;
val |= CMD_MODE_DATA_WIDTH_8_BIT;
} else {
val |= intel_dsi->channel << VID_MODE_CHANNEL_NUMBER_SHIFT;
val |= pixel_format_to_reg(intel_dsi->pixel_format);
}
tmp = 0;
if (intel_dsi->eotp_pkt == 0)
tmp |= EOT_DISABLE;
if (intel_dsi->clock_stop)
tmp |= CLOCKSTOP;
if (IS_GEN9_LP(dev_priv)) {
tmp |= BXT_DPHY_DEFEATURE_EN;
if (!is_cmd_mode(intel_dsi))
tmp |= BXT_DEFEATURE_DPI_FIFO_CTR;
}
for_each_dsi_port(port, intel_dsi->ports) {
I915_WRITE(MIPI_DSI_FUNC_PRG(port), val);
if (is_vid_mode(intel_dsi) &&
intel_dsi->video_mode_format == VIDEO_MODE_BURST) {
I915_WRITE(MIPI_HS_TX_TIMEOUT(port),
txbyteclkhs(adjusted_mode->crtc_htotal, bpp,
intel_dsi->lane_count,
intel_dsi->burst_mode_ratio) + 1);
} else {
I915_WRITE(MIPI_HS_TX_TIMEOUT(port),
txbyteclkhs(adjusted_mode->crtc_vtotal *
adjusted_mode->crtc_htotal,
bpp, intel_dsi->lane_count,
intel_dsi->burst_mode_ratio) + 1);
}
I915_WRITE(MIPI_LP_RX_TIMEOUT(port), intel_dsi->lp_rx_timeout);
I915_WRITE(MIPI_TURN_AROUND_TIMEOUT(port),
intel_dsi->turn_arnd_val);
I915_WRITE(MIPI_DEVICE_RESET_TIMER(port),
intel_dsi->rst_timer_val);
I915_WRITE(MIPI_INIT_COUNT(port),
txclkesc(intel_dsi->escape_clk_div, 100));
if (IS_GEN9_LP(dev_priv) && (!intel_dsi->dual_link)) {
I915_WRITE(MIPI_INIT_COUNT(port ==
PORT_A ? PORT_C : PORT_A),
intel_dsi->init_count);
}
I915_WRITE(MIPI_EOT_DISABLE(port), tmp);
I915_WRITE(MIPI_INIT_COUNT(port), intel_dsi->init_count);
I915_WRITE(MIPI_HIGH_LOW_SWITCH_COUNT(port),
intel_dsi->hs_to_lp_count);
I915_WRITE(MIPI_LP_BYTECLK(port), intel_dsi->lp_byte_clk);
if (IS_GEMINILAKE(dev_priv)) {
I915_WRITE(MIPI_TLPX_TIME_COUNT(port),
intel_dsi->lp_byte_clk);
I915_WRITE(MIPI_CLK_LANE_TIMING(port),
intel_dsi->dphy_reg);
}
I915_WRITE(MIPI_DBI_BW_CTRL(port), intel_dsi->bw_timer);
I915_WRITE(MIPI_CLK_LANE_SWITCH_TIME_CNT(port),
intel_dsi->clk_lp_to_hs_count << LP_HS_SSW_CNT_SHIFT |
intel_dsi->clk_hs_to_lp_count << HS_LP_PWR_SW_CNT_SHIFT);
if (is_vid_mode(intel_dsi))
I915_WRITE(MIPI_VIDEO_MODE_FORMAT(port),
intel_dsi->video_frmt_cfg_bits |
intel_dsi->video_mode_format |
IP_TG_CONFIG |
RANDOM_DPI_DISPLAY_RESOLUTION);
}
}
static void intel_dsi_unprepare(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
enum port port;
u32 val;
if (!IS_GEMINILAKE(dev_priv)) {
for_each_dsi_port(port, intel_dsi->ports) {
I915_WRITE(MIPI_DEVICE_READY(port), 0x0);
intel_dsi_reset_clocks(encoder, port);
I915_WRITE(MIPI_EOT_DISABLE(port), CLOCKSTOP);
val = I915_READ(MIPI_DSI_FUNC_PRG(port));
val &= ~VID_MODE_FORMAT_MASK;
I915_WRITE(MIPI_DSI_FUNC_PRG(port), val);
I915_WRITE(MIPI_DEVICE_READY(port), 0x1);
}
}
}
static int intel_dsi_get_modes(struct drm_connector *connector)
{
struct intel_connector *intel_connector = to_intel_connector(connector);
struct drm_display_mode *mode;
DRM_DEBUG_KMS("\n");
if (!intel_connector->panel.fixed_mode) {
DRM_DEBUG_KMS("no fixed mode\n");
return 0;
}
mode = drm_mode_duplicate(connector->dev,
intel_connector->panel.fixed_mode);
if (!mode) {
DRM_DEBUG_KMS("drm_mode_duplicate failed\n");
return 0;
}
drm_mode_probed_add(connector, mode);
return 1;
}
static void intel_dsi_connector_destroy(struct drm_connector *connector)
{
struct intel_connector *intel_connector = to_intel_connector(connector);
DRM_DEBUG_KMS("\n");
intel_panel_fini(&intel_connector->panel);
drm_connector_cleanup(connector);
kfree(connector);
}
static void intel_dsi_encoder_destroy(struct drm_encoder *encoder)
{
struct intel_dsi *intel_dsi = enc_to_intel_dsi(encoder);
if (intel_dsi->gpio_panel)
gpiod_put(intel_dsi->gpio_panel);
intel_encoder_destroy(encoder);
}
static void intel_dsi_add_properties(struct intel_connector *connector)
{
struct drm_i915_private *dev_priv = to_i915(connector->base.dev);
if (connector->panel.fixed_mode) {
u32 allowed_scalers;
allowed_scalers = BIT(DRM_MODE_SCALE_ASPECT) | BIT(DRM_MODE_SCALE_FULLSCREEN);
if (!HAS_GMCH_DISPLAY(dev_priv))
allowed_scalers |= BIT(DRM_MODE_SCALE_CENTER);
drm_connector_attach_scaling_mode_property(&connector->base,
allowed_scalers);
connector->base.state->scaling_mode = DRM_MODE_SCALE_ASPECT;
}
}
void intel_dsi_init(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = &dev_priv->drm;
struct intel_dsi *intel_dsi;
struct intel_encoder *intel_encoder;
struct drm_encoder *encoder;
struct intel_connector *intel_connector;
struct drm_connector *connector;
struct drm_display_mode *scan, *fixed_mode = NULL;
enum port port;
DRM_DEBUG_KMS("\n");
if (!intel_bios_is_dsi_present(dev_priv, &port))
return;
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
dev_priv->mipi_mmio_base = VLV_MIPI_BASE;
} else if (IS_GEN9_LP(dev_priv)) {
dev_priv->mipi_mmio_base = BXT_MIPI_BASE;
} else {
DRM_ERROR("Unsupported Mipi device to reg base");
return;
}
intel_dsi = kzalloc(sizeof(*intel_dsi), GFP_KERNEL);
if (!intel_dsi)
return;
intel_connector = intel_connector_alloc();
if (!intel_connector) {
kfree(intel_dsi);
return;
}
intel_encoder = &intel_dsi->base;
encoder = &intel_encoder->base;
intel_dsi->attached_connector = intel_connector;
connector = &intel_connector->base;
drm_encoder_init(dev, encoder, &intel_dsi_funcs, DRM_MODE_ENCODER_DSI,
"DSI %c", port_name(port));
intel_encoder->compute_config = intel_dsi_compute_config;
intel_encoder->pre_enable = intel_dsi_pre_enable;
intel_encoder->enable = intel_dsi_enable_nop;
intel_encoder->disable = intel_dsi_disable;
intel_encoder->post_disable = intel_dsi_post_disable;
intel_encoder->get_hw_state = intel_dsi_get_hw_state;
intel_encoder->get_config = intel_dsi_get_config;
intel_connector->get_hw_state = intel_connector_get_hw_state;
intel_encoder->port = port;
if (IS_GEN9_LP(dev_priv))
intel_encoder->crtc_mask = BIT(PIPE_A) | BIT(PIPE_B) | BIT(PIPE_C);
else if (port == PORT_A)
intel_encoder->crtc_mask = BIT(PIPE_A);
else
intel_encoder->crtc_mask = BIT(PIPE_B);
if (dev_priv->vbt.dsi.config->dual_link) {
intel_dsi->ports = BIT(PORT_A) | BIT(PORT_C);
switch (dev_priv->vbt.dsi.config->dl_dcs_backlight_ports) {
case DL_DCS_PORT_A:
intel_dsi->dcs_backlight_ports = BIT(PORT_A);
break;
case DL_DCS_PORT_C:
intel_dsi->dcs_backlight_ports = BIT(PORT_C);
break;
default:
case DL_DCS_PORT_A_AND_C:
intel_dsi->dcs_backlight_ports = BIT(PORT_A) | BIT(PORT_C);
break;
}
switch (dev_priv->vbt.dsi.config->dl_dcs_cabc_ports) {
case DL_DCS_PORT_A:
intel_dsi->dcs_cabc_ports = BIT(PORT_A);
break;
case DL_DCS_PORT_C:
intel_dsi->dcs_cabc_ports = BIT(PORT_C);
break;
default:
case DL_DCS_PORT_A_AND_C:
intel_dsi->dcs_cabc_ports = BIT(PORT_A) | BIT(PORT_C);
break;
}
} else {
intel_dsi->ports = BIT(port);
intel_dsi->dcs_backlight_ports = BIT(port);
intel_dsi->dcs_cabc_ports = BIT(port);
}
if (!dev_priv->vbt.dsi.config->cabc_supported)
intel_dsi->dcs_cabc_ports = 0;
for_each_dsi_port(port, intel_dsi->ports) {
struct intel_dsi_host *host;
host = intel_dsi_host_init(intel_dsi, port);
if (!host)
goto err;
intel_dsi->dsi_hosts[port] = host;
}
if (!intel_dsi_vbt_init(intel_dsi, MIPI_DSI_GENERIC_PANEL_ID)) {
DRM_DEBUG_KMS("no device found\n");
goto err;
}
if ((IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) &&
(dev_priv->vbt.dsi.config->pwm_blc == PPS_BLC_PMIC)) {
intel_dsi->gpio_panel =
gpiod_get(dev->dev, "panel", GPIOD_OUT_HIGH);
if (IS_ERR(intel_dsi->gpio_panel)) {
DRM_ERROR("Failed to own gpio for panel control\n");
intel_dsi->gpio_panel = NULL;
}
}
intel_encoder->type = INTEL_OUTPUT_DSI;
intel_encoder->power_domain = POWER_DOMAIN_PORT_DSI;
intel_encoder->cloneable = 0;
drm_connector_init(dev, connector, &intel_dsi_connector_funcs,
DRM_MODE_CONNECTOR_DSI);
drm_connector_helper_add(connector, &intel_dsi_connector_helper_funcs);
connector->display_info.subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
intel_connector_attach_encoder(intel_connector, intel_encoder);
mutex_lock(&dev->mode_config.mutex);
intel_dsi_vbt_get_modes(intel_dsi);
list_for_each_entry(scan, &connector->probed_modes, head) {
if ((scan->type & DRM_MODE_TYPE_PREFERRED)) {
fixed_mode = drm_mode_duplicate(dev, scan);
break;
}
}
mutex_unlock(&dev->mode_config.mutex);
if (!fixed_mode) {
DRM_DEBUG_KMS("no fixed mode\n");
goto err;
}
connector->display_info.width_mm = fixed_mode->width_mm;
connector->display_info.height_mm = fixed_mode->height_mm;
intel_panel_init(&intel_connector->panel, fixed_mode, NULL, NULL);
intel_panel_setup_backlight(connector, INVALID_PIPE);
intel_dsi_add_properties(intel_connector);
return;
err:
drm_encoder_cleanup(&intel_encoder->base);
kfree(intel_dsi);
kfree(intel_connector);
}
