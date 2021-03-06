static u32 dcs_get_backlight(struct intel_connector *connector)
{
struct intel_encoder *encoder = connector->encoder;
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
struct mipi_dsi_device *dsi_device;
u8 data;
enum port port;
for_each_dsi_port(port, intel_dsi->dcs_backlight_ports) {
dsi_device = intel_dsi->dsi_hosts[port]->device;
mipi_dsi_dcs_read(dsi_device, MIPI_DCS_GET_DISPLAY_BRIGHTNESS,
&data, sizeof(data));
break;
}
return data;
}
static void dcs_set_backlight(struct intel_connector *connector, u32 level)
{
struct intel_encoder *encoder = connector->encoder;
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
struct mipi_dsi_device *dsi_device;
u8 data = level;
enum port port;
for_each_dsi_port(port, intel_dsi->dcs_backlight_ports) {
dsi_device = intel_dsi->dsi_hosts[port]->device;
mipi_dsi_dcs_write(dsi_device, MIPI_DCS_SET_DISPLAY_BRIGHTNESS,
&data, sizeof(data));
}
}
static void dcs_disable_backlight(struct intel_connector *connector)
{
struct intel_encoder *encoder = connector->encoder;
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
struct mipi_dsi_device *dsi_device;
enum port port;
dcs_set_backlight(connector, 0);
for_each_dsi_port(port, intel_dsi->dcs_cabc_ports) {
u8 cabc = POWER_SAVE_OFF;
dsi_device = intel_dsi->dsi_hosts[port]->device;
mipi_dsi_dcs_write(dsi_device, MIPI_DCS_WRITE_POWER_SAVE,
&cabc, sizeof(cabc));
}
for_each_dsi_port(port, intel_dsi->dcs_backlight_ports) {
u8 ctrl = 0;
dsi_device = intel_dsi->dsi_hosts[port]->device;
mipi_dsi_dcs_read(dsi_device, MIPI_DCS_GET_CONTROL_DISPLAY,
&ctrl, sizeof(ctrl));
ctrl &= ~CONTROL_DISPLAY_BL;
ctrl &= ~CONTROL_DISPLAY_DD;
ctrl &= ~CONTROL_DISPLAY_BCTRL;
mipi_dsi_dcs_write(dsi_device, MIPI_DCS_WRITE_CONTROL_DISPLAY,
&ctrl, sizeof(ctrl));
}
}
static void dcs_enable_backlight(struct intel_connector *connector)
{
struct intel_encoder *encoder = connector->encoder;
struct intel_dsi *intel_dsi = enc_to_intel_dsi(&encoder->base);
struct intel_panel *panel = &connector->panel;
struct mipi_dsi_device *dsi_device;
enum port port;
for_each_dsi_port(port, intel_dsi->dcs_backlight_ports) {
u8 ctrl = 0;
dsi_device = intel_dsi->dsi_hosts[port]->device;
mipi_dsi_dcs_read(dsi_device, MIPI_DCS_GET_CONTROL_DISPLAY,
&ctrl, sizeof(ctrl));
ctrl |= CONTROL_DISPLAY_BL;
ctrl |= CONTROL_DISPLAY_DD;
ctrl |= CONTROL_DISPLAY_BCTRL;
mipi_dsi_dcs_write(dsi_device, MIPI_DCS_WRITE_CONTROL_DISPLAY,
&ctrl, sizeof(ctrl));
}
for_each_dsi_port(port, intel_dsi->dcs_cabc_ports) {
u8 cabc = POWER_SAVE_MEDIUM;
dsi_device = intel_dsi->dsi_hosts[port]->device;
mipi_dsi_dcs_write(dsi_device, MIPI_DCS_WRITE_POWER_SAVE,
&cabc, sizeof(cabc));
}
dcs_set_backlight(connector, panel->backlight.level);
}
static int dcs_setup_backlight(struct intel_connector *connector,
enum pipe unused)
{
struct intel_panel *panel = &connector->panel;
panel->backlight.max = PANEL_PWM_MAX_VALUE;
panel->backlight.level = PANEL_PWM_MAX_VALUE;
return 0;
}
int intel_dsi_dcs_init_backlight_funcs(struct intel_connector *intel_connector)
{
struct drm_device *dev = intel_connector->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_encoder *encoder = intel_connector->encoder;
struct intel_panel *panel = &intel_connector->panel;
if (dev_priv->vbt.backlight.type != INTEL_BACKLIGHT_DSI_DCS)
return -ENODEV;
if (WARN_ON(encoder->type != INTEL_OUTPUT_DSI))
return -EINVAL;
panel->backlight.setup = dcs_setup_backlight;
panel->backlight.enable = dcs_enable_backlight;
panel->backlight.disable = dcs_disable_backlight;
panel->backlight.set = dcs_set_backlight;
panel->backlight.get = dcs_get_backlight;
return 0;
}
