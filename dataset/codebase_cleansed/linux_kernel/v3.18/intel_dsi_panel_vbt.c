static u8 *mipi_exec_send_packet(struct intel_dsi *intel_dsi, u8 *data)
{
u8 type, byte, mode, vc, port;
u16 len;
byte = *data++;
mode = (byte >> MIPI_TRANSFER_MODE_SHIFT) & 0x1;
vc = (byte >> MIPI_VIRTUAL_CHANNEL_SHIFT) & 0x3;
port = (byte >> MIPI_PORT_SHIFT) & 0x3;
intel_dsi->hs = mode;
type = *data++;
len = *((u16 *) data);
data += 2;
switch (type) {
case MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM:
dsi_vc_generic_write_0(intel_dsi, vc);
break;
case MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM:
dsi_vc_generic_write_1(intel_dsi, vc, *data);
break;
case MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM:
dsi_vc_generic_write_2(intel_dsi, vc, *data, *(data + 1));
break;
case MIPI_DSI_GENERIC_READ_REQUEST_0_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_2_PARAM:
DRM_DEBUG_DRIVER("Generic Read not yet implemented or used\n");
break;
case MIPI_DSI_GENERIC_LONG_WRITE:
dsi_vc_generic_write(intel_dsi, vc, data, len);
break;
case MIPI_DSI_DCS_SHORT_WRITE:
dsi_vc_dcs_write_0(intel_dsi, vc, *data);
break;
case MIPI_DSI_DCS_SHORT_WRITE_PARAM:
dsi_vc_dcs_write_1(intel_dsi, vc, *data, *(data + 1));
break;
case MIPI_DSI_DCS_READ:
DRM_DEBUG_DRIVER("DCS Read not yet implemented or used\n");
break;
case MIPI_DSI_DCS_LONG_WRITE:
dsi_vc_dcs_write(intel_dsi, vc, data, len);
break;
}
data += len;
return data;
}
static u8 *mipi_exec_delay(struct intel_dsi *intel_dsi, u8 *data)
{
u32 delay = *((u32 *) data);
usleep_range(delay, delay + 10);
data += 4;
return data;
}
static u8 *mipi_exec_gpio(struct intel_dsi *intel_dsi, u8 *data)
{
u8 gpio, action;
u16 function, pad;
u32 val;
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
gpio = *data++;
action = *data++;
function = gtable[gpio].function_reg;
pad = gtable[gpio].pad_reg;
mutex_lock(&dev_priv->dpio_lock);
if (!gtable[gpio].init) {
vlv_gpio_nc_write(dev_priv, function, 0x2000CC00);
gtable[gpio].init = 1;
}
val = 0x4 | action;
vlv_gpio_nc_write(dev_priv, pad, val);
mutex_unlock(&dev_priv->dpio_lock);
return data;
}
static void generic_exec_sequence(struct intel_dsi *intel_dsi, char *sequence)
{
u8 *data = sequence;
fn_mipi_elem_exec mipi_elem_exec;
int index;
if (!sequence)
return;
DRM_DEBUG_DRIVER("Starting MIPI sequence - %s\n", seq_name[*data]);
data++;
while (1) {
index = *data;
mipi_elem_exec = exec_elem[index];
if (!mipi_elem_exec) {
DRM_ERROR("Unsupported MIPI element, skipping sequence execution\n");
return;
}
data++;
data = mipi_elem_exec(intel_dsi, data);
if (*data == 0x00)
break;
}
}
static bool generic_init(struct intel_dsi_device *dsi)
{
struct intel_dsi *intel_dsi = container_of(dsi, struct intel_dsi, dev);
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct mipi_config *mipi_config = dev_priv->vbt.dsi.config;
struct mipi_pps_data *pps = dev_priv->vbt.dsi.pps;
struct drm_display_mode *mode = dev_priv->vbt.lfp_lvds_vbt_mode;
u32 bits_per_pixel = 24;
u32 tlpx_ns, extra_byte_count, bitrate, tlpx_ui;
u32 ui_num, ui_den;
u32 prepare_cnt, exit_zero_cnt, clk_zero_cnt, trail_cnt;
u32 ths_prepare_ns, tclk_trail_ns;
u32 tclk_prepare_clkzero, ths_prepare_hszero;
u32 lp_to_hs_switch, hs_to_lp_switch;
u32 pclk, computed_ddr;
u16 burst_mode_ratio;
DRM_DEBUG_KMS("\n");
intel_dsi->eotp_pkt = mipi_config->eot_pkt_disabled ? 0 : 1;
intel_dsi->clock_stop = mipi_config->enable_clk_stop ? 1 : 0;
intel_dsi->lane_count = mipi_config->lane_cnt + 1;
intel_dsi->pixel_format = mipi_config->videomode_color_format << 7;
if (intel_dsi->pixel_format == VID_MODE_FORMAT_RGB666)
bits_per_pixel = 18;
else if (intel_dsi->pixel_format == VID_MODE_FORMAT_RGB565)
bits_per_pixel = 16;
intel_dsi->operation_mode = mipi_config->is_cmd_mode;
intel_dsi->video_mode_format = mipi_config->video_transfer_mode;
intel_dsi->escape_clk_div = mipi_config->byte_clk_sel;
intel_dsi->lp_rx_timeout = mipi_config->lp_rx_timeout;
intel_dsi->turn_arnd_val = mipi_config->turn_around_timeout;
intel_dsi->rst_timer_val = mipi_config->device_reset_timer;
intel_dsi->init_count = mipi_config->master_init_timer;
intel_dsi->bw_timer = mipi_config->dbi_bw_timer;
intel_dsi->video_frmt_cfg_bits =
mipi_config->bta_enabled ? DISABLE_VIDEO_BTA : 0;
pclk = mode->clock;
if (intel_dsi->video_mode_format == VIDEO_MODE_BURST) {
if (mipi_config->target_burst_mode_freq) {
computed_ddr =
(pclk * bits_per_pixel) / intel_dsi->lane_count;
if (mipi_config->target_burst_mode_freq <
computed_ddr) {
DRM_ERROR("Burst mode freq is less than computed\n");
return false;
}
burst_mode_ratio = DIV_ROUND_UP(
mipi_config->target_burst_mode_freq * 100,
computed_ddr);
pclk = DIV_ROUND_UP(pclk * burst_mode_ratio, 100);
} else {
DRM_ERROR("Burst mode target is not set\n");
return false;
}
} else
burst_mode_ratio = 100;
intel_dsi->burst_mode_ratio = burst_mode_ratio;
intel_dsi->pclk = pclk;
bitrate = (pclk * bits_per_pixel) / intel_dsi->lane_count;
switch (intel_dsi->escape_clk_div) {
case 0:
tlpx_ns = 50;
break;
case 1:
tlpx_ns = 100;
break;
case 2:
tlpx_ns = 200;
break;
default:
tlpx_ns = 50;
break;
}
switch (intel_dsi->lane_count) {
case 1:
case 2:
extra_byte_count = 2;
break;
case 3:
extra_byte_count = 4;
break;
case 4:
default:
extra_byte_count = 3;
break;
}
ui_num = NS_KHZ_RATIO;
ui_den = bitrate;
tclk_prepare_clkzero = mipi_config->tclk_prepare_clkzero;
ths_prepare_hszero = mipi_config->ths_prepare_hszero;
intel_dsi->lp_byte_clk = DIV_ROUND_UP(tlpx_ns * ui_den, 8 * ui_num);
ths_prepare_ns = max(mipi_config->ths_prepare,
mipi_config->tclk_prepare);
prepare_cnt = DIV_ROUND_UP(ths_prepare_ns * ui_den, ui_num * 2);
exit_zero_cnt = DIV_ROUND_UP(
(ths_prepare_hszero - ths_prepare_ns) * ui_den,
ui_num * 2
);
if (exit_zero_cnt < (55 * ui_den / ui_num))
if ((55 * ui_den) % ui_num)
exit_zero_cnt += 1;
clk_zero_cnt = DIV_ROUND_UP(
(tclk_prepare_clkzero - ths_prepare_ns)
* ui_den, 2 * ui_num);
tclk_trail_ns = max(mipi_config->tclk_trail, mipi_config->ths_trail);
trail_cnt = DIV_ROUND_UP(tclk_trail_ns * ui_den, 2 * ui_num);
if (prepare_cnt > PREPARE_CNT_MAX ||
exit_zero_cnt > EXIT_ZERO_CNT_MAX ||
clk_zero_cnt > CLK_ZERO_CNT_MAX ||
trail_cnt > TRAIL_CNT_MAX)
DRM_DEBUG_DRIVER("Values crossing maximum limits, restricting to max values\n");
if (prepare_cnt > PREPARE_CNT_MAX)
prepare_cnt = PREPARE_CNT_MAX;
if (exit_zero_cnt > EXIT_ZERO_CNT_MAX)
exit_zero_cnt = EXIT_ZERO_CNT_MAX;
if (clk_zero_cnt > CLK_ZERO_CNT_MAX)
clk_zero_cnt = CLK_ZERO_CNT_MAX;
if (trail_cnt > TRAIL_CNT_MAX)
trail_cnt = TRAIL_CNT_MAX;
intel_dsi->dphy_reg = exit_zero_cnt << 24 | trail_cnt << 16 |
clk_zero_cnt << 8 | prepare_cnt;
tlpx_ui = DIV_ROUND_UP(tlpx_ns * ui_den, ui_num);
lp_to_hs_switch = DIV_ROUND_UP(4 * tlpx_ui + prepare_cnt * 2 +
exit_zero_cnt * 2 + 10, 8);
hs_to_lp_switch = DIV_ROUND_UP(mipi_config->ths_trail + 2 * tlpx_ui, 8);
intel_dsi->hs_to_lp_count = max(lp_to_hs_switch, hs_to_lp_switch);
intel_dsi->hs_to_lp_count += extra_byte_count;
intel_dsi->clk_lp_to_hs_count =
DIV_ROUND_UP(
4 * tlpx_ui + prepare_cnt * 2 +
clk_zero_cnt * 2,
8);
intel_dsi->clk_lp_to_hs_count += extra_byte_count;
intel_dsi->clk_hs_to_lp_count =
DIV_ROUND_UP(2 * tlpx_ui + trail_cnt * 2 + 8,
8);
intel_dsi->clk_hs_to_lp_count += extra_byte_count;
DRM_DEBUG_KMS("Eot %s\n", intel_dsi->eotp_pkt ? "enabled" : "disabled");
DRM_DEBUG_KMS("Clockstop %s\n", intel_dsi->clock_stop ?
"disabled" : "enabled");
DRM_DEBUG_KMS("Mode %s\n", intel_dsi->operation_mode ? "command" : "video");
DRM_DEBUG_KMS("Pixel Format %d\n", intel_dsi->pixel_format);
DRM_DEBUG_KMS("TLPX %d\n", intel_dsi->escape_clk_div);
DRM_DEBUG_KMS("LP RX Timeout 0x%x\n", intel_dsi->lp_rx_timeout);
DRM_DEBUG_KMS("Turnaround Timeout 0x%x\n", intel_dsi->turn_arnd_val);
DRM_DEBUG_KMS("Init Count 0x%x\n", intel_dsi->init_count);
DRM_DEBUG_KMS("HS to LP Count 0x%x\n", intel_dsi->hs_to_lp_count);
DRM_DEBUG_KMS("LP Byte Clock %d\n", intel_dsi->lp_byte_clk);
DRM_DEBUG_KMS("DBI BW Timer 0x%x\n", intel_dsi->bw_timer);
DRM_DEBUG_KMS("LP to HS Clock Count 0x%x\n", intel_dsi->clk_lp_to_hs_count);
DRM_DEBUG_KMS("HS to LP Clock Count 0x%x\n", intel_dsi->clk_hs_to_lp_count);
DRM_DEBUG_KMS("BTA %s\n",
intel_dsi->video_frmt_cfg_bits & DISABLE_VIDEO_BTA ?
"disabled" : "enabled");
intel_dsi->backlight_off_delay = pps->bl_disable_delay / 10;
intel_dsi->backlight_on_delay = pps->bl_enable_delay / 10;
intel_dsi->panel_on_delay = pps->panel_on_delay / 10;
intel_dsi->panel_off_delay = pps->panel_off_delay / 10;
intel_dsi->panel_pwr_cycle_delay = pps->panel_power_cycle_delay / 10;
return true;
}
static int generic_mode_valid(struct intel_dsi_device *dsi,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static bool generic_mode_fixup(struct intel_dsi_device *dsi,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode) {
return true;
}
static void generic_panel_reset(struct intel_dsi_device *dsi)
{
struct intel_dsi *intel_dsi = container_of(dsi, struct intel_dsi, dev);
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
char *sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_ASSERT_RESET];
generic_exec_sequence(intel_dsi, sequence);
}
static void generic_disable_panel_power(struct intel_dsi_device *dsi)
{
struct intel_dsi *intel_dsi = container_of(dsi, struct intel_dsi, dev);
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
char *sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_DEASSERT_RESET];
generic_exec_sequence(intel_dsi, sequence);
}
static void generic_send_otp_cmds(struct intel_dsi_device *dsi)
{
struct intel_dsi *intel_dsi = container_of(dsi, struct intel_dsi, dev);
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
char *sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_INIT_OTP];
generic_exec_sequence(intel_dsi, sequence);
}
static void generic_enable(struct intel_dsi_device *dsi)
{
struct intel_dsi *intel_dsi = container_of(dsi, struct intel_dsi, dev);
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
char *sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_DISPLAY_ON];
generic_exec_sequence(intel_dsi, sequence);
}
static void generic_disable(struct intel_dsi_device *dsi)
{
struct intel_dsi *intel_dsi = container_of(dsi, struct intel_dsi, dev);
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
char *sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_DISPLAY_OFF];
generic_exec_sequence(intel_dsi, sequence);
}
static enum drm_connector_status generic_detect(struct intel_dsi_device *dsi)
{
return connector_status_connected;
}
static bool generic_get_hw_state(struct intel_dsi_device *dev)
{
return true;
}
static struct drm_display_mode *generic_get_modes(struct intel_dsi_device *dsi)
{
struct intel_dsi *intel_dsi = container_of(dsi, struct intel_dsi, dev);
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->vbt.lfp_lvds_vbt_mode->type |= DRM_MODE_TYPE_PREFERRED;
return dev_priv->vbt.lfp_lvds_vbt_mode;
}
static void generic_destroy(struct intel_dsi_device *dsi) { }
