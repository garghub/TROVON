static u32 audio_config_hdmi_pixel_clock(const struct drm_display_mode *adjusted_mode)
{
int i;
for (i = 0; i < ARRAY_SIZE(hdmi_audio_clock); i++) {
if (adjusted_mode->crtc_clock == hdmi_audio_clock[i].clock)
break;
}
if (i == ARRAY_SIZE(hdmi_audio_clock)) {
DRM_DEBUG_KMS("HDMI audio pixel clock setting for %d not found, falling back to defaults\n",
adjusted_mode->crtc_clock);
i = 1;
}
DRM_DEBUG_KMS("Configuring HDMI audio for pixel clock %d (0x%08x)\n",
hdmi_audio_clock[i].clock,
hdmi_audio_clock[i].config);
return hdmi_audio_clock[i].config;
}
static int audio_config_get_n(const struct drm_display_mode *mode, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(aud_ncts); i++) {
if ((rate == aud_ncts[i].sample_rate) &&
(mode->clock == aud_ncts[i].clock)) {
return aud_ncts[i].n;
}
}
return 0;
}
static uint32_t audio_config_setup_n_reg(int n, uint32_t val)
{
int n_low, n_up;
uint32_t tmp = val;
n_low = n & 0xfff;
n_up = (n >> 12) & 0xff;
tmp &= ~(AUD_CONFIG_UPPER_N_MASK | AUD_CONFIG_LOWER_N_MASK);
tmp |= ((n_up << AUD_CONFIG_UPPER_N_SHIFT) |
(n_low << AUD_CONFIG_LOWER_N_SHIFT) |
AUD_CONFIG_N_PROG_ENABLE);
return tmp;
}
static bool audio_rate_need_prog(struct intel_crtc *crtc,
const struct drm_display_mode *mode)
{
if (((mode->clock == TMDS_297M) ||
(mode->clock == TMDS_296M)) &&
intel_pipe_has_type(crtc, INTEL_OUTPUT_HDMI))
return true;
else
return false;
}
static bool intel_eld_uptodate(struct drm_connector *connector,
i915_reg_t reg_eldv, uint32_t bits_eldv,
i915_reg_t reg_elda, uint32_t bits_elda,
i915_reg_t reg_edid)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
uint8_t *eld = connector->eld;
uint32_t tmp;
int i;
tmp = I915_READ(reg_eldv);
tmp &= bits_eldv;
if (!tmp)
return false;
tmp = I915_READ(reg_elda);
tmp &= ~bits_elda;
I915_WRITE(reg_elda, tmp);
for (i = 0; i < drm_eld_size(eld) / 4; i++)
if (I915_READ(reg_edid) != *((uint32_t *)eld + i))
return false;
return true;
}
static void g4x_audio_codec_disable(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
uint32_t eldv, tmp;
DRM_DEBUG_KMS("Disable audio codec\n");
tmp = I915_READ(G4X_AUD_VID_DID);
if (tmp == INTEL_AUDIO_DEVBLC || tmp == INTEL_AUDIO_DEVCL)
eldv = G4X_ELDV_DEVCL_DEVBLC;
else
eldv = G4X_ELDV_DEVCTG;
tmp = I915_READ(G4X_AUD_CNTL_ST);
tmp &= ~eldv;
I915_WRITE(G4X_AUD_CNTL_ST, tmp);
}
static void g4x_audio_codec_enable(struct drm_connector *connector,
struct intel_encoder *encoder,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
uint8_t *eld = connector->eld;
uint32_t eldv;
uint32_t tmp;
int len, i;
DRM_DEBUG_KMS("Enable audio codec, %u bytes ELD\n", eld[2]);
tmp = I915_READ(G4X_AUD_VID_DID);
if (tmp == INTEL_AUDIO_DEVBLC || tmp == INTEL_AUDIO_DEVCL)
eldv = G4X_ELDV_DEVCL_DEVBLC;
else
eldv = G4X_ELDV_DEVCTG;
if (intel_eld_uptodate(connector,
G4X_AUD_CNTL_ST, eldv,
G4X_AUD_CNTL_ST, G4X_ELD_ADDR_MASK,
G4X_HDMIW_HDMIEDID))
return;
tmp = I915_READ(G4X_AUD_CNTL_ST);
tmp &= ~(eldv | G4X_ELD_ADDR_MASK);
len = (tmp >> 9) & 0x1f;
I915_WRITE(G4X_AUD_CNTL_ST, tmp);
len = min(drm_eld_size(eld) / 4, len);
DRM_DEBUG_DRIVER("ELD size %d\n", len);
for (i = 0; i < len; i++)
I915_WRITE(G4X_HDMIW_HDMIEDID, *((uint32_t *)eld + i));
tmp = I915_READ(G4X_AUD_CNTL_ST);
tmp |= eldv;
I915_WRITE(G4X_AUD_CNTL_ST, tmp);
}
static void hsw_audio_codec_disable(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
enum pipe pipe = intel_crtc->pipe;
uint32_t tmp;
DRM_DEBUG_KMS("Disable audio codec on pipe %c\n", pipe_name(pipe));
mutex_lock(&dev_priv->av_mutex);
tmp = I915_READ(HSW_AUD_CFG(pipe));
tmp &= ~AUD_CONFIG_N_VALUE_INDEX;
tmp |= AUD_CONFIG_N_PROG_ENABLE;
tmp &= ~AUD_CONFIG_UPPER_N_MASK;
tmp &= ~AUD_CONFIG_LOWER_N_MASK;
if (intel_pipe_has_type(intel_crtc, INTEL_OUTPUT_DISPLAYPORT))
tmp |= AUD_CONFIG_N_VALUE_INDEX;
I915_WRITE(HSW_AUD_CFG(pipe), tmp);
tmp = I915_READ(HSW_AUD_PIN_ELD_CP_VLD);
tmp &= ~AUDIO_ELD_VALID(pipe);
tmp &= ~AUDIO_OUTPUT_ENABLE(pipe);
I915_WRITE(HSW_AUD_PIN_ELD_CP_VLD, tmp);
mutex_unlock(&dev_priv->av_mutex);
}
static void hsw_audio_codec_enable(struct drm_connector *connector,
struct intel_encoder *encoder,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
enum pipe pipe = intel_crtc->pipe;
struct i915_audio_component *acomp = dev_priv->audio_component;
const uint8_t *eld = connector->eld;
struct intel_digital_port *intel_dig_port =
enc_to_dig_port(&encoder->base);
enum port port = intel_dig_port->port;
uint32_t tmp;
int len, i;
int n, rate;
DRM_DEBUG_KMS("Enable audio codec on pipe %c, %u bytes ELD\n",
pipe_name(pipe), drm_eld_size(eld));
mutex_lock(&dev_priv->av_mutex);
tmp = I915_READ(HSW_AUD_PIN_ELD_CP_VLD);
tmp |= AUDIO_OUTPUT_ENABLE(pipe);
tmp &= ~AUDIO_ELD_VALID(pipe);
I915_WRITE(HSW_AUD_PIN_ELD_CP_VLD, tmp);
tmp = I915_READ(HSW_AUD_DIP_ELD_CTRL(pipe));
tmp &= ~IBX_ELD_ADDRESS_MASK;
I915_WRITE(HSW_AUD_DIP_ELD_CTRL(pipe), tmp);
len = min(drm_eld_size(eld), 84);
for (i = 0; i < len / 4; i++)
I915_WRITE(HSW_AUD_EDID_DATA(pipe), *((uint32_t *)eld + i));
tmp = I915_READ(HSW_AUD_PIN_ELD_CP_VLD);
tmp |= AUDIO_ELD_VALID(pipe);
I915_WRITE(HSW_AUD_PIN_ELD_CP_VLD, tmp);
tmp = I915_READ(HSW_AUD_CFG(pipe));
tmp &= ~AUD_CONFIG_N_VALUE_INDEX;
tmp &= ~AUD_CONFIG_PIXEL_CLOCK_HDMI_MASK;
if (intel_pipe_has_type(intel_crtc, INTEL_OUTPUT_DISPLAYPORT))
tmp |= AUD_CONFIG_N_VALUE_INDEX;
else
tmp |= audio_config_hdmi_pixel_clock(adjusted_mode);
tmp &= ~AUD_CONFIG_N_PROG_ENABLE;
if (audio_rate_need_prog(intel_crtc, adjusted_mode)) {
if (!acomp)
rate = 0;
else if (port >= PORT_A && port <= PORT_E)
rate = acomp->aud_sample_rate[port];
else {
DRM_ERROR("invalid port: %d\n", port);
rate = 0;
}
n = audio_config_get_n(adjusted_mode, rate);
if (n != 0)
tmp = audio_config_setup_n_reg(n, tmp);
else
DRM_DEBUG_KMS("no suitable N value is found\n");
}
I915_WRITE(HSW_AUD_CFG(pipe), tmp);
mutex_unlock(&dev_priv->av_mutex);
}
static void ilk_audio_codec_disable(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
struct intel_digital_port *intel_dig_port =
enc_to_dig_port(&encoder->base);
enum port port = intel_dig_port->port;
enum pipe pipe = intel_crtc->pipe;
uint32_t tmp, eldv;
i915_reg_t aud_config, aud_cntrl_st2;
DRM_DEBUG_KMS("Disable audio codec on port %c, pipe %c\n",
port_name(port), pipe_name(pipe));
if (WARN_ON(port == PORT_A))
return;
if (HAS_PCH_IBX(dev_priv->dev)) {
aud_config = IBX_AUD_CFG(pipe);
aud_cntrl_st2 = IBX_AUD_CNTL_ST2;
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
aud_config = VLV_AUD_CFG(pipe);
aud_cntrl_st2 = VLV_AUD_CNTL_ST2;
} else {
aud_config = CPT_AUD_CFG(pipe);
aud_cntrl_st2 = CPT_AUD_CNTRL_ST2;
}
tmp = I915_READ(aud_config);
tmp &= ~AUD_CONFIG_N_VALUE_INDEX;
tmp |= AUD_CONFIG_N_PROG_ENABLE;
tmp &= ~AUD_CONFIG_UPPER_N_MASK;
tmp &= ~AUD_CONFIG_LOWER_N_MASK;
if (intel_pipe_has_type(intel_crtc, INTEL_OUTPUT_DISPLAYPORT))
tmp |= AUD_CONFIG_N_VALUE_INDEX;
I915_WRITE(aud_config, tmp);
eldv = IBX_ELD_VALID(port);
tmp = I915_READ(aud_cntrl_st2);
tmp &= ~eldv;
I915_WRITE(aud_cntrl_st2, tmp);
}
static void ilk_audio_codec_enable(struct drm_connector *connector,
struct intel_encoder *encoder,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = connector->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
struct intel_digital_port *intel_dig_port =
enc_to_dig_port(&encoder->base);
enum port port = intel_dig_port->port;
enum pipe pipe = intel_crtc->pipe;
uint8_t *eld = connector->eld;
uint32_t eldv;
uint32_t tmp;
int len, i;
i915_reg_t hdmiw_hdmiedid, aud_config, aud_cntl_st, aud_cntrl_st2;
DRM_DEBUG_KMS("Enable audio codec on port %c, pipe %c, %u bytes ELD\n",
port_name(port), pipe_name(pipe), drm_eld_size(eld));
if (WARN_ON(port == PORT_A))
return;
if (HAS_PCH_IBX(connector->dev)) {
hdmiw_hdmiedid = IBX_HDMIW_HDMIEDID(pipe);
aud_config = IBX_AUD_CFG(pipe);
aud_cntl_st = IBX_AUD_CNTL_ST(pipe);
aud_cntrl_st2 = IBX_AUD_CNTL_ST2;
} else if (IS_VALLEYVIEW(connector->dev) ||
IS_CHERRYVIEW(connector->dev)) {
hdmiw_hdmiedid = VLV_HDMIW_HDMIEDID(pipe);
aud_config = VLV_AUD_CFG(pipe);
aud_cntl_st = VLV_AUD_CNTL_ST(pipe);
aud_cntrl_st2 = VLV_AUD_CNTL_ST2;
} else {
hdmiw_hdmiedid = CPT_HDMIW_HDMIEDID(pipe);
aud_config = CPT_AUD_CFG(pipe);
aud_cntl_st = CPT_AUD_CNTL_ST(pipe);
aud_cntrl_st2 = CPT_AUD_CNTRL_ST2;
}
eldv = IBX_ELD_VALID(port);
tmp = I915_READ(aud_cntrl_st2);
tmp &= ~eldv;
I915_WRITE(aud_cntrl_st2, tmp);
tmp = I915_READ(aud_cntl_st);
tmp &= ~IBX_ELD_ADDRESS_MASK;
I915_WRITE(aud_cntl_st, tmp);
len = min(drm_eld_size(eld), 84);
for (i = 0; i < len / 4; i++)
I915_WRITE(hdmiw_hdmiedid, *((uint32_t *)eld + i));
tmp = I915_READ(aud_cntrl_st2);
tmp |= eldv;
I915_WRITE(aud_cntrl_st2, tmp);
tmp = I915_READ(aud_config);
tmp &= ~AUD_CONFIG_N_VALUE_INDEX;
tmp &= ~AUD_CONFIG_N_PROG_ENABLE;
tmp &= ~AUD_CONFIG_PIXEL_CLOCK_HDMI_MASK;
if (intel_pipe_has_type(intel_crtc, INTEL_OUTPUT_DISPLAYPORT))
tmp |= AUD_CONFIG_N_VALUE_INDEX;
else
tmp |= audio_config_hdmi_pixel_clock(adjusted_mode);
I915_WRITE(aud_config, tmp);
}
void intel_audio_codec_enable(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct intel_crtc *crtc = to_intel_crtc(encoder->crtc);
const struct drm_display_mode *adjusted_mode = &crtc->config->base.adjusted_mode;
struct drm_connector *connector;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_audio_component *acomp = dev_priv->audio_component;
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
enum port port = intel_dig_port->port;
connector = drm_select_eld(encoder);
if (!connector)
return;
DRM_DEBUG_DRIVER("ELD on [CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id,
connector->name,
connector->encoder->base.id,
connector->encoder->name);
connector->eld[5] &= ~(3 << 2);
if (intel_pipe_has_type(crtc, INTEL_OUTPUT_DISPLAYPORT))
connector->eld[5] |= (1 << 2);
connector->eld[6] = drm_av_sync_delay(connector, adjusted_mode) / 2;
if (dev_priv->display.audio_codec_enable)
dev_priv->display.audio_codec_enable(connector, intel_encoder,
adjusted_mode);
mutex_lock(&dev_priv->av_mutex);
intel_dig_port->audio_connector = connector;
dev_priv->dig_port_map[port] = intel_encoder;
mutex_unlock(&dev_priv->av_mutex);
if (acomp && acomp->audio_ops && acomp->audio_ops->pin_eld_notify)
acomp->audio_ops->pin_eld_notify(acomp->audio_ops->audio_ptr, (int) port);
}
void intel_audio_codec_disable(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_audio_component *acomp = dev_priv->audio_component;
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
enum port port = intel_dig_port->port;
if (dev_priv->display.audio_codec_disable)
dev_priv->display.audio_codec_disable(intel_encoder);
mutex_lock(&dev_priv->av_mutex);
intel_dig_port->audio_connector = NULL;
dev_priv->dig_port_map[port] = NULL;
mutex_unlock(&dev_priv->av_mutex);
if (acomp && acomp->audio_ops && acomp->audio_ops->pin_eld_notify)
acomp->audio_ops->pin_eld_notify(acomp->audio_ops->audio_ptr, (int) port);
}
void intel_init_audio(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_G4X(dev)) {
dev_priv->display.audio_codec_enable = g4x_audio_codec_enable;
dev_priv->display.audio_codec_disable = g4x_audio_codec_disable;
} else if (IS_VALLEYVIEW(dev) || IS_CHERRYVIEW(dev)) {
dev_priv->display.audio_codec_enable = ilk_audio_codec_enable;
dev_priv->display.audio_codec_disable = ilk_audio_codec_disable;
} else if (IS_HASWELL(dev) || INTEL_INFO(dev)->gen >= 8) {
dev_priv->display.audio_codec_enable = hsw_audio_codec_enable;
dev_priv->display.audio_codec_disable = hsw_audio_codec_disable;
} else if (HAS_PCH_SPLIT(dev)) {
dev_priv->display.audio_codec_enable = ilk_audio_codec_enable;
dev_priv->display.audio_codec_disable = ilk_audio_codec_disable;
}
}
static void i915_audio_component_get_power(struct device *dev)
{
intel_display_power_get(dev_to_i915(dev), POWER_DOMAIN_AUDIO);
}
static void i915_audio_component_put_power(struct device *dev)
{
intel_display_power_put(dev_to_i915(dev), POWER_DOMAIN_AUDIO);
}
static void i915_audio_component_codec_wake_override(struct device *dev,
bool enable)
{
struct drm_i915_private *dev_priv = dev_to_i915(dev);
u32 tmp;
if (!IS_SKYLAKE(dev_priv) && !IS_KABYLAKE(dev_priv))
return;
tmp = I915_READ(HSW_AUD_CHICKENBIT);
tmp &= ~SKL_AUD_CODEC_WAKE_SIGNAL;
I915_WRITE(HSW_AUD_CHICKENBIT, tmp);
usleep_range(1000, 1500);
if (enable) {
tmp = I915_READ(HSW_AUD_CHICKENBIT);
tmp |= SKL_AUD_CODEC_WAKE_SIGNAL;
I915_WRITE(HSW_AUD_CHICKENBIT, tmp);
usleep_range(1000, 1500);
}
}
static int i915_audio_component_get_cdclk_freq(struct device *dev)
{
struct drm_i915_private *dev_priv = dev_to_i915(dev);
int ret;
if (WARN_ON_ONCE(!HAS_DDI(dev_priv)))
return -ENODEV;
intel_display_power_get(dev_priv, POWER_DOMAIN_AUDIO);
ret = dev_priv->display.get_display_clock_speed(dev_priv->dev);
intel_display_power_put(dev_priv, POWER_DOMAIN_AUDIO);
return ret;
}
static int i915_audio_component_sync_audio_rate(struct device *dev,
int port, int rate)
{
struct drm_i915_private *dev_priv = dev_to_i915(dev);
struct intel_encoder *intel_encoder;
struct intel_crtc *crtc;
struct drm_display_mode *mode;
struct i915_audio_component *acomp = dev_priv->audio_component;
enum pipe pipe = INVALID_PIPE;
u32 tmp;
int n;
int err = 0;
if (!IS_SKYLAKE(dev_priv) &&
!IS_KABYLAKE(dev_priv) &&
!IS_BROADWELL(dev_priv) &&
!IS_HASWELL(dev_priv))
return 0;
mutex_lock(&dev_priv->av_mutex);
intel_encoder = dev_priv->dig_port_map[port];
if (!intel_encoder || !intel_encoder->base.crtc ||
intel_encoder->type != INTEL_OUTPUT_HDMI) {
DRM_DEBUG_KMS("no valid port %c\n", port_name(port));
err = -ENODEV;
goto unlock;
}
crtc = to_intel_crtc(intel_encoder->base.crtc);
pipe = crtc->pipe;
if (pipe == INVALID_PIPE) {
DRM_DEBUG_KMS("no pipe for the port %c\n", port_name(port));
err = -ENODEV;
goto unlock;
}
DRM_DEBUG_KMS("pipe %c connects port %c\n",
pipe_name(pipe), port_name(port));
mode = &crtc->config->base.adjusted_mode;
acomp->aud_sample_rate[port] = rate;
if (!audio_rate_need_prog(crtc, mode)) {
tmp = I915_READ(HSW_AUD_CFG(pipe));
tmp &= ~AUD_CONFIG_N_PROG_ENABLE;
I915_WRITE(HSW_AUD_CFG(pipe), tmp);
goto unlock;
}
n = audio_config_get_n(mode, rate);
if (n == 0) {
DRM_DEBUG_KMS("Using automatic mode for N value on port %c\n",
port_name(port));
tmp = I915_READ(HSW_AUD_CFG(pipe));
tmp &= ~AUD_CONFIG_N_PROG_ENABLE;
I915_WRITE(HSW_AUD_CFG(pipe), tmp);
goto unlock;
}
tmp = I915_READ(HSW_AUD_CFG(pipe));
tmp = audio_config_setup_n_reg(n, tmp);
I915_WRITE(HSW_AUD_CFG(pipe), tmp);
unlock:
mutex_unlock(&dev_priv->av_mutex);
return err;
}
static int i915_audio_component_get_eld(struct device *dev, int port,
bool *enabled,
unsigned char *buf, int max_bytes)
{
struct drm_i915_private *dev_priv = dev_to_i915(dev);
struct intel_encoder *intel_encoder;
struct intel_digital_port *intel_dig_port;
const u8 *eld;
int ret = -EINVAL;
mutex_lock(&dev_priv->av_mutex);
intel_encoder = dev_priv->dig_port_map[port];
if (intel_encoder) {
ret = 0;
intel_dig_port = enc_to_dig_port(&intel_encoder->base);
*enabled = intel_dig_port->audio_connector != NULL;
if (*enabled) {
eld = intel_dig_port->audio_connector->eld;
ret = drm_eld_size(eld);
memcpy(buf, eld, min(max_bytes, ret));
}
}
mutex_unlock(&dev_priv->av_mutex);
return ret;
}
static int i915_audio_component_bind(struct device *i915_dev,
struct device *hda_dev, void *data)
{
struct i915_audio_component *acomp = data;
struct drm_i915_private *dev_priv = dev_to_i915(i915_dev);
int i;
if (WARN_ON(acomp->ops || acomp->dev))
return -EEXIST;
drm_modeset_lock_all(dev_priv->dev);
acomp->ops = &i915_audio_component_ops;
acomp->dev = i915_dev;
BUILD_BUG_ON(MAX_PORTS != I915_MAX_PORTS);
for (i = 0; i < ARRAY_SIZE(acomp->aud_sample_rate); i++)
acomp->aud_sample_rate[i] = 0;
dev_priv->audio_component = acomp;
drm_modeset_unlock_all(dev_priv->dev);
return 0;
}
static void i915_audio_component_unbind(struct device *i915_dev,
struct device *hda_dev, void *data)
{
struct i915_audio_component *acomp = data;
struct drm_i915_private *dev_priv = dev_to_i915(i915_dev);
drm_modeset_lock_all(dev_priv->dev);
acomp->ops = NULL;
acomp->dev = NULL;
dev_priv->audio_component = NULL;
drm_modeset_unlock_all(dev_priv->dev);
}
void i915_audio_component_init(struct drm_i915_private *dev_priv)
{
int ret;
ret = component_add(dev_priv->dev->dev, &i915_audio_component_bind_ops);
if (ret < 0) {
DRM_ERROR("failed to add audio component (%d)\n", ret);
return;
}
dev_priv->audio_component_registered = true;
}
void i915_audio_component_cleanup(struct drm_i915_private *dev_priv)
{
if (!dev_priv->audio_component_registered)
return;
component_del(dev_priv->dev->dev, &i915_audio_component_bind_ops);
dev_priv->audio_component_registered = false;
}
