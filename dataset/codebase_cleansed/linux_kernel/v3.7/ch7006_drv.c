static void ch7006_encoder_set_config(struct drm_encoder *encoder,
void *params)
{
struct ch7006_priv *priv = to_ch7006_priv(encoder);
priv->params = *(struct ch7006_encoder_params *)params;
}
static void ch7006_encoder_destroy(struct drm_encoder *encoder)
{
struct ch7006_priv *priv = to_ch7006_priv(encoder);
drm_property_destroy(encoder->dev, priv->scale_property);
kfree(priv);
to_encoder_slave(encoder)->slave_priv = NULL;
drm_i2c_encoder_destroy(encoder);
}
static void ch7006_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct ch7006_state *state = &priv->state;
ch7006_dbg(client, "\n");
if (mode == priv->last_dpms)
return;
priv->last_dpms = mode;
ch7006_setup_power_state(encoder);
ch7006_load_reg(client, state, CH7006_POWER);
}
static void ch7006_encoder_save(struct drm_encoder *encoder)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
ch7006_dbg(client, "\n");
ch7006_state_save(client, &priv->saved_state);
}
static void ch7006_encoder_restore(struct drm_encoder *encoder)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
ch7006_dbg(client, "\n");
ch7006_state_load(client, &priv->saved_state);
}
static bool ch7006_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct ch7006_priv *priv = to_ch7006_priv(encoder);
priv->mode = ch7006_lookup_mode(encoder, mode);
return !!priv->mode;
}
static int ch7006_encoder_mode_valid(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
if (ch7006_lookup_mode(encoder, mode))
return MODE_OK;
else
return MODE_BAD;
}
static void ch7006_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *drm_mode,
struct drm_display_mode *adjusted_mode)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct ch7006_encoder_params *params = &priv->params;
struct ch7006_state *state = &priv->state;
uint8_t *regs = state->regs;
struct ch7006_mode *mode = priv->mode;
struct ch7006_tv_norm_info *norm = &ch7006_tv_norms[priv->norm];
int start_active;
ch7006_dbg(client, "\n");
regs[CH7006_DISPMODE] = norm->dispmode | mode->dispmode;
regs[CH7006_BWIDTH] = 0;
regs[CH7006_INPUT_FORMAT] = bitf(CH7006_INPUT_FORMAT_FORMAT,
params->input_format);
regs[CH7006_CLKMODE] = CH7006_CLKMODE_SUBC_LOCK
| bitf(CH7006_CLKMODE_XCM, params->xcm)
| bitf(CH7006_CLKMODE_PCM, params->pcm);
if (params->clock_mode)
regs[CH7006_CLKMODE] |= CH7006_CLKMODE_MASTER;
if (params->clock_edge)
regs[CH7006_CLKMODE] |= CH7006_CLKMODE_POS_EDGE;
start_active = (drm_mode->htotal & ~0x7) - (drm_mode->hsync_start & ~0x7);
regs[CH7006_POV] = bitf(CH7006_POV_START_ACTIVE_8, start_active);
regs[CH7006_START_ACTIVE] = bitf(CH7006_START_ACTIVE_0, start_active);
regs[CH7006_INPUT_SYNC] = 0;
if (params->sync_direction)
regs[CH7006_INPUT_SYNC] |= CH7006_INPUT_SYNC_OUTPUT;
if (params->sync_encoding)
regs[CH7006_INPUT_SYNC] |= CH7006_INPUT_SYNC_EMBEDDED;
if (drm_mode->flags & DRM_MODE_FLAG_PVSYNC)
regs[CH7006_INPUT_SYNC] |= CH7006_INPUT_SYNC_PVSYNC;
if (drm_mode->flags & DRM_MODE_FLAG_PHSYNC)
regs[CH7006_INPUT_SYNC] |= CH7006_INPUT_SYNC_PHSYNC;
regs[CH7006_DETECT] = 0;
regs[CH7006_BCLKOUT] = 0;
regs[CH7006_SUBC_INC3] = 0;
if (params->pout_level)
regs[CH7006_SUBC_INC3] |= CH7006_SUBC_INC3_POUT_3_3V;
regs[CH7006_SUBC_INC4] = 0;
if (params->active_detect)
regs[CH7006_SUBC_INC4] |= CH7006_SUBC_INC4_DS_INPUT;
regs[CH7006_PLL_CONTROL] = priv->saved_state.regs[CH7006_PLL_CONTROL];
ch7006_setup_levels(encoder);
ch7006_setup_subcarrier(encoder);
ch7006_setup_pll(encoder);
ch7006_setup_power_state(encoder);
ch7006_setup_properties(encoder);
ch7006_state_load(client, state);
}
static enum drm_connector_status ch7006_encoder_detect(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct ch7006_state *state = &priv->state;
int det;
ch7006_dbg(client, "\n");
ch7006_save_reg(client, state, CH7006_DETECT);
ch7006_save_reg(client, state, CH7006_POWER);
ch7006_save_reg(client, state, CH7006_CLKMODE);
ch7006_write(client, CH7006_POWER, CH7006_POWER_RESET |
bitfs(CH7006_POWER_LEVEL, NORMAL));
ch7006_write(client, CH7006_CLKMODE, CH7006_CLKMODE_MASTER);
ch7006_write(client, CH7006_DETECT, CH7006_DETECT_SENSE);
ch7006_write(client, CH7006_DETECT, 0);
det = ch7006_read(client, CH7006_DETECT);
ch7006_load_reg(client, state, CH7006_CLKMODE);
ch7006_load_reg(client, state, CH7006_POWER);
ch7006_load_reg(client, state, CH7006_DETECT);
if ((det & (CH7006_DETECT_SVIDEO_Y_TEST|
CH7006_DETECT_SVIDEO_C_TEST|
CH7006_DETECT_CVBS_TEST)) == 0)
priv->subconnector = DRM_MODE_SUBCONNECTOR_SCART;
else if ((det & (CH7006_DETECT_SVIDEO_Y_TEST|
CH7006_DETECT_SVIDEO_C_TEST)) == 0)
priv->subconnector = DRM_MODE_SUBCONNECTOR_SVIDEO;
else if ((det & CH7006_DETECT_CVBS_TEST) == 0)
priv->subconnector = DRM_MODE_SUBCONNECTOR_Composite;
else
priv->subconnector = DRM_MODE_SUBCONNECTOR_Unknown;
drm_connector_property_set_value(connector,
encoder->dev->mode_config.tv_subconnector_property,
priv->subconnector);
return priv->subconnector ? connector_status_connected :
connector_status_disconnected;
}
static int ch7006_encoder_get_modes(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct ch7006_mode *mode;
int n = 0;
for (mode = ch7006_modes; mode->mode.clock; mode++) {
if (~mode->valid_scales & 1<<priv->scale ||
~mode->valid_norms & 1<<priv->norm)
continue;
drm_mode_probed_add(connector,
drm_mode_duplicate(encoder->dev, &mode->mode));
n++;
}
return n;
}
static int ch7006_encoder_create_resources(struct drm_encoder *encoder,
struct drm_connector *connector)
{
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct drm_device *dev = encoder->dev;
struct drm_mode_config *conf = &dev->mode_config;
drm_mode_create_tv_properties(dev, NUM_TV_NORMS, ch7006_tv_norm_names);
priv->scale_property = drm_property_create_range(dev, 0, "scale", 0, 2);
drm_connector_attach_property(connector, conf->tv_select_subconnector_property,
priv->select_subconnector);
drm_connector_attach_property(connector, conf->tv_subconnector_property,
priv->subconnector);
drm_connector_attach_property(connector, conf->tv_left_margin_property,
priv->hmargin);
drm_connector_attach_property(connector, conf->tv_bottom_margin_property,
priv->vmargin);
drm_connector_attach_property(connector, conf->tv_mode_property,
priv->norm);
drm_connector_attach_property(connector, conf->tv_brightness_property,
priv->brightness);
drm_connector_attach_property(connector, conf->tv_contrast_property,
priv->contrast);
drm_connector_attach_property(connector, conf->tv_flicker_reduction_property,
priv->flicker);
drm_connector_attach_property(connector, priv->scale_property,
priv->scale);
return 0;
}
static int ch7006_encoder_set_property(struct drm_encoder *encoder,
struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct ch7006_state *state = &priv->state;
struct drm_mode_config *conf = &encoder->dev->mode_config;
struct drm_crtc *crtc = encoder->crtc;
bool modes_changed = false;
ch7006_dbg(client, "\n");
if (property == conf->tv_select_subconnector_property) {
priv->select_subconnector = val;
ch7006_setup_power_state(encoder);
ch7006_load_reg(client, state, CH7006_POWER);
} else if (property == conf->tv_left_margin_property) {
priv->hmargin = val;
ch7006_setup_properties(encoder);
ch7006_load_reg(client, state, CH7006_POV);
ch7006_load_reg(client, state, CH7006_HPOS);
} else if (property == conf->tv_bottom_margin_property) {
priv->vmargin = val;
ch7006_setup_properties(encoder);
ch7006_load_reg(client, state, CH7006_POV);
ch7006_load_reg(client, state, CH7006_VPOS);
} else if (property == conf->tv_mode_property) {
if (connector->dpms != DRM_MODE_DPMS_OFF)
return -EINVAL;
priv->norm = val;
modes_changed = true;
} else if (property == conf->tv_brightness_property) {
priv->brightness = val;
ch7006_setup_levels(encoder);
ch7006_load_reg(client, state, CH7006_BLACK_LEVEL);
} else if (property == conf->tv_contrast_property) {
priv->contrast = val;
ch7006_setup_properties(encoder);
ch7006_load_reg(client, state, CH7006_CONTRAST);
} else if (property == conf->tv_flicker_reduction_property) {
priv->flicker = val;
ch7006_setup_properties(encoder);
ch7006_load_reg(client, state, CH7006_FFILTER);
} else if (property == priv->scale_property) {
if (connector->dpms != DRM_MODE_DPMS_OFF)
return -EINVAL;
priv->scale = val;
modes_changed = true;
} else {
return -EINVAL;
}
if (modes_changed) {
drm_helper_probe_single_connector_modes(connector, 0, 0);
if (crtc) {
struct drm_mode_set modeset = {
.crtc = crtc,
};
crtc->funcs->set_config(&modeset);
}
}
return 0;
}
static int ch7006_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
uint8_t addr = CH7006_VERSION_ID;
uint8_t val;
int ret;
ch7006_dbg(client, "\n");
ret = i2c_master_send(client, &addr, sizeof(addr));
if (ret < 0)
goto fail;
ret = i2c_master_recv(client, &val, sizeof(val));
if (ret < 0)
goto fail;
ch7006_info(client, "Detected version ID: %x\n", val);
ch7006_write(client, 0x3d, 0x0);
return 0;
fail:
ch7006_err(client, "Error %d reading version ID\n", ret);
return -ENODEV;
}
static int ch7006_remove(struct i2c_client *client)
{
ch7006_dbg(client, "\n");
return 0;
}
static int ch7006_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
ch7006_dbg(client, "\n");
ch7006_write(client, 0x3d, 0x0);
return 0;
}
static int ch7006_encoder_init(struct i2c_client *client,
struct drm_device *dev,
struct drm_encoder_slave *encoder)
{
struct ch7006_priv *priv;
int i;
ch7006_dbg(client, "\n");
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
encoder->slave_priv = priv;
encoder->slave_funcs = &ch7006_encoder_funcs;
priv->norm = TV_NORM_PAL;
priv->select_subconnector = DRM_MODE_SUBCONNECTOR_Automatic;
priv->subconnector = DRM_MODE_SUBCONNECTOR_Unknown;
priv->scale = 1;
priv->contrast = 50;
priv->brightness = 50;
priv->flicker = 50;
priv->hmargin = 50;
priv->vmargin = 50;
priv->last_dpms = -1;
priv->chip_version = ch7006_read(client, CH7006_VERSION_ID);
if (ch7006_tv_norm) {
for (i = 0; i < NUM_TV_NORMS; i++) {
if (!strcmp(ch7006_tv_norm_names[i], ch7006_tv_norm)) {
priv->norm = i;
break;
}
}
if (i == NUM_TV_NORMS)
ch7006_err(client, "Invalid TV norm setting \"%s\".\n",
ch7006_tv_norm);
}
if (ch7006_scale >= 0 && ch7006_scale <= 2)
priv->scale = ch7006_scale;
else
ch7006_err(client, "Invalid scale setting \"%d\".\n",
ch7006_scale);
return 0;
}
static int __init ch7006_init(void)
{
return drm_i2c_encoder_register(THIS_MODULE, &ch7006_driver);
}
static void __exit ch7006_exit(void)
{
drm_i2c_encoder_unregister(&ch7006_driver);
}
