static void set_aux_backlight_enable(struct intel_dp *intel_dp, bool enable)
{
uint8_t reg_val = 0;
if (!(intel_dp->edp_dpcd[1] & DP_EDP_BACKLIGHT_AUX_ENABLE_CAP))
return;
if (drm_dp_dpcd_readb(&intel_dp->aux, DP_EDP_DISPLAY_CONTROL_REGISTER,
&reg_val) < 0) {
DRM_DEBUG_KMS("Failed to read DPCD register 0x%x\n",
DP_EDP_DISPLAY_CONTROL_REGISTER);
return;
}
if (enable)
reg_val |= DP_EDP_BACKLIGHT_ENABLE;
else
reg_val &= ~(DP_EDP_BACKLIGHT_ENABLE);
if (drm_dp_dpcd_writeb(&intel_dp->aux, DP_EDP_DISPLAY_CONTROL_REGISTER,
reg_val) != 1) {
DRM_DEBUG_KMS("Failed to %s aux backlight\n",
enable ? "enable" : "disable");
}
}
static uint32_t intel_dp_aux_get_backlight(struct intel_connector *connector)
{
struct intel_dp *intel_dp = enc_to_intel_dp(&connector->encoder->base);
uint8_t read_val[2] = { 0x0 };
uint16_t level = 0;
if (drm_dp_dpcd_read(&intel_dp->aux, DP_EDP_BACKLIGHT_BRIGHTNESS_MSB,
&read_val, sizeof(read_val)) < 0) {
DRM_DEBUG_KMS("Failed to read DPCD register 0x%x\n",
DP_EDP_BACKLIGHT_BRIGHTNESS_MSB);
return 0;
}
level = read_val[0];
if (intel_dp->edp_dpcd[2] & DP_EDP_BACKLIGHT_BRIGHTNESS_BYTE_COUNT)
level = (read_val[0] << 8 | read_val[1]);
return level;
}
static void
intel_dp_aux_set_backlight(const struct drm_connector_state *conn_state, u32 level)
{
struct intel_connector *connector = to_intel_connector(conn_state->connector);
struct intel_dp *intel_dp = enc_to_intel_dp(&connector->encoder->base);
uint8_t vals[2] = { 0x0 };
vals[0] = level;
if (intel_dp->edp_dpcd[2] & DP_EDP_BACKLIGHT_BRIGHTNESS_BYTE_COUNT) {
vals[0] = (level & 0xFF00) >> 8;
vals[1] = (level & 0xFF);
}
if (drm_dp_dpcd_write(&intel_dp->aux, DP_EDP_BACKLIGHT_BRIGHTNESS_MSB,
vals, sizeof(vals)) < 0) {
DRM_DEBUG_KMS("Failed to write aux backlight level\n");
return;
}
}
static void intel_dp_aux_enable_backlight(const struct intel_crtc_state *crtc_state,
const struct drm_connector_state *conn_state)
{
struct intel_connector *connector = to_intel_connector(conn_state->connector);
struct intel_dp *intel_dp = enc_to_intel_dp(&connector->encoder->base);
uint8_t dpcd_buf = 0;
uint8_t edp_backlight_mode = 0;
if (drm_dp_dpcd_readb(&intel_dp->aux,
DP_EDP_BACKLIGHT_MODE_SET_REGISTER, &dpcd_buf) != 1) {
DRM_DEBUG_KMS("Failed to read DPCD register 0x%x\n",
DP_EDP_BACKLIGHT_MODE_SET_REGISTER);
return;
}
edp_backlight_mode = dpcd_buf & DP_EDP_BACKLIGHT_CONTROL_MODE_MASK;
switch (edp_backlight_mode) {
case DP_EDP_BACKLIGHT_CONTROL_MODE_PWM:
case DP_EDP_BACKLIGHT_CONTROL_MODE_PRESET:
case DP_EDP_BACKLIGHT_CONTROL_MODE_PRODUCT:
dpcd_buf &= ~DP_EDP_BACKLIGHT_CONTROL_MODE_MASK;
dpcd_buf |= DP_EDP_BACKLIGHT_CONTROL_MODE_DPCD;
if (drm_dp_dpcd_writeb(&intel_dp->aux,
DP_EDP_BACKLIGHT_MODE_SET_REGISTER, dpcd_buf) < 0) {
DRM_DEBUG_KMS("Failed to write aux backlight mode\n");
}
break;
case DP_EDP_BACKLIGHT_CONTROL_MODE_DPCD:
default:
break;
}
set_aux_backlight_enable(intel_dp, true);
intel_dp_aux_set_backlight(conn_state, connector->panel.backlight.level);
}
static void intel_dp_aux_disable_backlight(const struct drm_connector_state *old_conn_state)
{
set_aux_backlight_enable(enc_to_intel_dp(old_conn_state->best_encoder), false);
}
static int intel_dp_aux_setup_backlight(struct intel_connector *connector,
enum pipe pipe)
{
struct intel_dp *intel_dp = enc_to_intel_dp(&connector->encoder->base);
struct intel_panel *panel = &connector->panel;
if (intel_dp->edp_dpcd[2] & DP_EDP_BACKLIGHT_BRIGHTNESS_BYTE_COUNT)
panel->backlight.max = 0xFFFF;
else
panel->backlight.max = 0xFF;
panel->backlight.min = 0;
panel->backlight.level = intel_dp_aux_get_backlight(connector);
panel->backlight.enabled = panel->backlight.level != 0;
return 0;
}
static bool
intel_dp_aux_display_control_capable(struct intel_connector *connector)
{
struct intel_dp *intel_dp = enc_to_intel_dp(&connector->encoder->base);
if (intel_dp->edp_dpcd[1] & DP_EDP_TCON_BACKLIGHT_ADJUSTMENT_CAP &&
(intel_dp->edp_dpcd[2] & DP_EDP_BACKLIGHT_BRIGHTNESS_AUX_SET_CAP) &&
!(intel_dp->edp_dpcd[2] & DP_EDP_BACKLIGHT_BRIGHTNESS_PWM_PIN_CAP)) {
DRM_DEBUG_KMS("AUX Backlight Control Supported!\n");
return true;
}
return false;
}
int intel_dp_aux_init_backlight_funcs(struct intel_connector *intel_connector)
{
struct intel_panel *panel = &intel_connector->panel;
if (!i915.enable_dpcd_backlight)
return -ENODEV;
if (!intel_dp_aux_display_control_capable(intel_connector))
return -ENODEV;
panel->backlight.setup = intel_dp_aux_setup_backlight;
panel->backlight.enable = intel_dp_aux_enable_backlight;
panel->backlight.disable = intel_dp_aux_disable_backlight;
panel->backlight.set = intel_dp_aux_set_backlight;
panel->backlight.get = intel_dp_aux_get_backlight;
return 0;
}
