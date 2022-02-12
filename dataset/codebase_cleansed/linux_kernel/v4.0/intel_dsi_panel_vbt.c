static inline struct vbt_panel *to_vbt_panel(struct drm_panel *panel)
{
return container_of(panel, struct vbt_panel, panel);
}
static inline enum port intel_dsi_seq_port_to_port(u8 port)
{
return port ? PORT_C : PORT_A;
}
static const u8 *mipi_exec_send_packet(struct intel_dsi *intel_dsi,
const u8 *data)
{
struct mipi_dsi_device *dsi_device;
u8 type, flags, seq_port;
u16 len;
enum port port;
flags = *data++;
type = *data++;
len = *((u16 *) data);
data += 2;
seq_port = (flags >> MIPI_PORT_SHIFT) & 3;
if (intel_dsi->ports == (1 << PORT_C))
port = PORT_C;
else
port = intel_dsi_seq_port_to_port(seq_port);
dsi_device = intel_dsi->dsi_hosts[port]->device;
if (!dsi_device) {
DRM_DEBUG_KMS("no dsi device for port %c\n", port_name(port));
goto out;
}
if ((flags >> MIPI_TRANSFER_MODE_SHIFT) & 1)
dsi_device->mode_flags &= ~MIPI_DSI_MODE_LPM;
else
dsi_device->mode_flags |= MIPI_DSI_MODE_LPM;
dsi_device->channel = (flags >> MIPI_VIRTUAL_CHANNEL_SHIFT) & 3;
switch (type) {
case MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM:
mipi_dsi_generic_write(dsi_device, NULL, 0);
break;
case MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM:
mipi_dsi_generic_write(dsi_device, data, 1);
break;
case MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM:
mipi_dsi_generic_write(dsi_device, data, 2);
break;
case MIPI_DSI_GENERIC_READ_REQUEST_0_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM:
case MIPI_DSI_GENERIC_READ_REQUEST_2_PARAM:
DRM_DEBUG_DRIVER("Generic Read not yet implemented or used\n");
break;
case MIPI_DSI_GENERIC_LONG_WRITE:
mipi_dsi_generic_write(dsi_device, data, len);
break;
case MIPI_DSI_DCS_SHORT_WRITE:
mipi_dsi_dcs_write_buffer(dsi_device, data, 1);
break;
case MIPI_DSI_DCS_SHORT_WRITE_PARAM:
mipi_dsi_dcs_write_buffer(dsi_device, data, 2);
break;
case MIPI_DSI_DCS_READ:
DRM_DEBUG_DRIVER("DCS Read not yet implemented or used\n");
break;
case MIPI_DSI_DCS_LONG_WRITE:
mipi_dsi_dcs_write_buffer(dsi_device, data, len);
break;
}
out:
data += len;
return data;
}
static const u8 *mipi_exec_delay(struct intel_dsi *intel_dsi, const u8 *data)
{
u32 delay = *((const u32 *) data);
usleep_range(delay, delay + 10);
data += 4;
return data;
}
static const u8 *mipi_exec_gpio(struct intel_dsi *intel_dsi, const u8 *data)
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
static void generic_exec_sequence(struct intel_dsi *intel_dsi, const u8 *data)
{
fn_mipi_elem_exec mipi_elem_exec;
int index;
if (!data)
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
static int vbt_panel_prepare(struct drm_panel *panel)
{
struct vbt_panel *vbt_panel = to_vbt_panel(panel);
struct intel_dsi *intel_dsi = vbt_panel->intel_dsi;
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
const u8 *sequence;
sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_ASSERT_RESET];
generic_exec_sequence(intel_dsi, sequence);
sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_INIT_OTP];
generic_exec_sequence(intel_dsi, sequence);
return 0;
}
static int vbt_panel_unprepare(struct drm_panel *panel)
{
struct vbt_panel *vbt_panel = to_vbt_panel(panel);
struct intel_dsi *intel_dsi = vbt_panel->intel_dsi;
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
const u8 *sequence;
sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_DEASSERT_RESET];
generic_exec_sequence(intel_dsi, sequence);
return 0;
}
static int vbt_panel_enable(struct drm_panel *panel)
{
struct vbt_panel *vbt_panel = to_vbt_panel(panel);
struct intel_dsi *intel_dsi = vbt_panel->intel_dsi;
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
const u8 *sequence;
sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_DISPLAY_ON];
generic_exec_sequence(intel_dsi, sequence);
return 0;
}
static int vbt_panel_disable(struct drm_panel *panel)
{
struct vbt_panel *vbt_panel = to_vbt_panel(panel);
struct intel_dsi *intel_dsi = vbt_panel->intel_dsi;
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
const u8 *sequence;
sequence = dev_priv->vbt.dsi.sequence[MIPI_SEQ_DISPLAY_OFF];
generic_exec_sequence(intel_dsi, sequence);
return 0;
}
static int vbt_panel_get_modes(struct drm_panel *panel)
{
struct vbt_panel *vbt_panel = to_vbt_panel(panel);
struct intel_dsi *intel_dsi = vbt_panel->intel_dsi;
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_display_mode *mode;
if (!panel->connector)
return 0;
mode = drm_mode_duplicate(dev, dev_priv->vbt.lfp_lvds_vbt_mode);
if (!mode)
return 0;
mode->type |= DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(panel->connector, mode);
return 1;
}
struct drm_panel *vbt_panel_init(struct intel_dsi *intel_dsi, u16 panel_id)
{
struct drm_device *dev = intel_dsi->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct mipi_config *mipi_config = dev_priv->vbt.dsi.config;
struct mipi_pps_data *pps = dev_priv->vbt.dsi.pps;
struct drm_display_mode *mode = dev_priv->vbt.lfp_lvds_vbt_mode;
struct vbt_panel *vbt_panel;
u32 bits_per_pixel = 24;
u32 tlpx_ns, extra_byte_count, bitrate, tlpx_ui;
u32 ui_num, ui_den;
u32 prepare_cnt, exit_zero_cnt, clk_zero_cnt, trail_cnt;
u32 ths_prepare_ns, tclk_trail_ns;
u32 tclk_prepare_clkzero, ths_prepare_hszero;
u32 lp_to_hs_switch, hs_to_lp_switch;
u32 pclk, computed_ddr;
u16 burst_mode_ratio;
enum port port;
DRM_DEBUG_KMS("\n");
intel_dsi->eotp_pkt = mipi_config->eot_pkt_disabled ? 0 : 1;
intel_dsi->clock_stop = mipi_config->enable_clk_stop ? 1 : 0;
intel_dsi->lane_count = mipi_config->lane_cnt + 1;
intel_dsi->pixel_format = mipi_config->videomode_color_format << 7;
intel_dsi->dual_link = mipi_config->dual_link;
intel_dsi->pixel_overlap = mipi_config->pixel_overlap;
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
if (intel_dsi->dual_link) {
pclk = pclk / 2;
if (intel_dsi->dual_link == DSI_DUAL_LINK_FRONT_BACK) {
pclk += DIV_ROUND_UP(mode->vtotal *
intel_dsi->pixel_overlap *
60, 1000);
}
}
if (intel_dsi->video_mode_format == VIDEO_MODE_BURST) {
if (mipi_config->target_burst_mode_freq) {
computed_ddr =
(pclk * bits_per_pixel) / intel_dsi->lane_count;
if (mipi_config->target_burst_mode_freq <
computed_ddr) {
DRM_ERROR("Burst mode freq is less than computed\n");
return NULL;
}
burst_mode_ratio = DIV_ROUND_UP(
mipi_config->target_burst_mode_freq * 100,
computed_ddr);
pclk = DIV_ROUND_UP(pclk * burst_mode_ratio, 100);
} else {
DRM_ERROR("Burst mode target is not set\n");
return NULL;
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
if (intel_dsi->dual_link == DSI_DUAL_LINK_FRONT_BACK)
DRM_DEBUG_KMS("Dual link: DSI_DUAL_LINK_FRONT_BACK\n");
else if (intel_dsi->dual_link == DSI_DUAL_LINK_PIXEL_ALT)
DRM_DEBUG_KMS("Dual link: DSI_DUAL_LINK_PIXEL_ALT\n");
else
DRM_DEBUG_KMS("Dual link: NONE\n");
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
vbt_panel = devm_kzalloc(dev->dev, sizeof(*vbt_panel), GFP_KERNEL);
vbt_panel->intel_dsi = intel_dsi;
drm_panel_init(&vbt_panel->panel);
vbt_panel->panel.funcs = &vbt_panel_funcs;
drm_panel_add(&vbt_panel->panel);
for_each_dsi_port(port, intel_dsi->ports) {
mipi_dsi_attach(intel_dsi->dsi_hosts[port]->device);
}
return &vbt_panel->panel;
}
