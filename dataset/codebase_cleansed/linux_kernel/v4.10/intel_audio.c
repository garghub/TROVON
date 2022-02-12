static const struct dp_aud_n_m *
audio_config_dp_get_n_m(struct intel_crtc *intel_crtc, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(dp_aud_n_m); i++) {
if (rate == dp_aud_n_m[i].sample_rate &&
intel_crtc->config->port_clock == dp_aud_n_m[i].clock)
return &dp_aud_n_m[i];
}
return NULL;
}
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
static int audio_config_hdmi_get_n(const struct drm_display_mode *adjusted_mode,
int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(hdmi_aud_ncts); i++) {
if (rate == hdmi_aud_ncts[i].sample_rate &&
adjusted_mode->crtc_clock == hdmi_aud_ncts[i].clock) {
return hdmi_aud_ncts[i].n;
}
}
return 0;
}
static bool intel_eld_uptodate(struct drm_connector *connector,
i915_reg_t reg_eldv, uint32_t bits_eldv,
i915_reg_t reg_elda, uint32_t bits_elda,
i915_reg_t reg_edid)
{
struct drm_i915_private *dev_priv = to_i915(connector->dev);
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
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
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
struct drm_i915_private *dev_priv = to_i915(connector->dev);
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
static void
hsw_dp_audio_config_update(struct intel_crtc *intel_crtc, enum port port,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = to_i915(intel_crtc->base.dev);
struct i915_audio_component *acomp = dev_priv->audio_component;
int rate = acomp ? acomp->aud_sample_rate[port] : 0;
const struct dp_aud_n_m *nm = audio_config_dp_get_n_m(intel_crtc, rate);
enum pipe pipe = intel_crtc->pipe;
u32 tmp;
if (nm)
DRM_DEBUG_KMS("using Maud %u, Naud %u\n", nm->m, nm->n);
else
DRM_DEBUG_KMS("using automatic Maud, Naud\n");
tmp = I915_READ(HSW_AUD_CFG(pipe));
tmp &= ~AUD_CONFIG_N_VALUE_INDEX;
tmp &= ~AUD_CONFIG_PIXEL_CLOCK_HDMI_MASK;
tmp &= ~AUD_CONFIG_N_PROG_ENABLE;
tmp |= AUD_CONFIG_N_VALUE_INDEX;
if (nm) {
tmp &= ~AUD_CONFIG_N_MASK;
tmp |= AUD_CONFIG_N(nm->n);
tmp |= AUD_CONFIG_N_PROG_ENABLE;
}
I915_WRITE(HSW_AUD_CFG(pipe), tmp);
tmp = I915_READ(HSW_AUD_M_CTS_ENABLE(pipe));
tmp &= ~AUD_CONFIG_M_MASK;
tmp &= ~AUD_M_CTS_M_VALUE_INDEX;
tmp &= ~AUD_M_CTS_M_PROG_ENABLE;
if (nm) {
tmp |= nm->m;
tmp |= AUD_M_CTS_M_VALUE_INDEX;
tmp |= AUD_M_CTS_M_PROG_ENABLE;
}
I915_WRITE(HSW_AUD_M_CTS_ENABLE(pipe), tmp);
}
static void
hsw_hdmi_audio_config_update(struct intel_crtc *intel_crtc, enum port port,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = to_i915(intel_crtc->base.dev);
struct i915_audio_component *acomp = dev_priv->audio_component;
int rate = acomp ? acomp->aud_sample_rate[port] : 0;
enum pipe pipe = intel_crtc->pipe;
int n;
u32 tmp;
tmp = I915_READ(HSW_AUD_CFG(pipe));
tmp &= ~AUD_CONFIG_N_VALUE_INDEX;
tmp &= ~AUD_CONFIG_PIXEL_CLOCK_HDMI_MASK;
tmp &= ~AUD_CONFIG_N_PROG_ENABLE;
tmp |= audio_config_hdmi_pixel_clock(adjusted_mode);
n = audio_config_hdmi_get_n(adjusted_mode, rate);
if (n != 0) {
DRM_DEBUG_KMS("using N %d\n", n);
tmp &= ~AUD_CONFIG_N_MASK;
tmp |= AUD_CONFIG_N(n);
tmp |= AUD_CONFIG_N_PROG_ENABLE;
} else {
DRM_DEBUG_KMS("using automatic N\n");
}
I915_WRITE(HSW_AUD_CFG(pipe), tmp);
tmp = I915_READ(HSW_AUD_M_CTS_ENABLE(pipe));
tmp &= ~AUD_M_CTS_M_PROG_ENABLE;
tmp &= ~AUD_M_CTS_M_VALUE_INDEX;
I915_WRITE(HSW_AUD_M_CTS_ENABLE(pipe), tmp);
}
static void
hsw_audio_config_update(struct intel_crtc *intel_crtc, enum port port,
const struct drm_display_mode *adjusted_mode)
{
if (intel_crtc_has_dp_encoder(intel_crtc->config))
hsw_dp_audio_config_update(intel_crtc, port, adjusted_mode);
else
hsw_hdmi_audio_config_update(intel_crtc, port, adjusted_mode);
}
static void hsw_audio_codec_disable(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
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
if (intel_crtc_has_dp_encoder(intel_crtc->config))
tmp |= AUD_CONFIG_N_VALUE_INDEX;
I915_WRITE(HSW_AUD_CFG(pipe), tmp);
tmp = I915_READ(HSW_AUD_PIN_ELD_CP_VLD);
tmp &= ~AUDIO_ELD_VALID(pipe);
tmp &= ~AUDIO_OUTPUT_ENABLE(pipe);
I915_WRITE(HSW_AUD_PIN_ELD_CP_VLD, tmp);
mutex_unlock(&dev_priv->av_mutex);
}
static void hsw_audio_codec_enable(struct drm_connector *connector,
struct intel_encoder *intel_encoder,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = to_i915(connector->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(intel_encoder->base.crtc);
enum pipe pipe = intel_crtc->pipe;
enum port port = intel_encoder->port;
const uint8_t *eld = connector->eld;
uint32_t tmp;
int len, i;
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
hsw_audio_config_update(intel_crtc, port, adjusted_mode);
mutex_unlock(&dev_priv->av_mutex);
}
static void ilk_audio_codec_disable(struct intel_encoder *intel_encoder)
{
struct drm_i915_private *dev_priv = to_i915(intel_encoder->base.dev);
struct intel_crtc *intel_crtc = to_intel_crtc(intel_encoder->base.crtc);
enum pipe pipe = intel_crtc->pipe;
enum port port = intel_encoder->port;
uint32_t tmp, eldv;
i915_reg_t aud_config, aud_cntrl_st2;
DRM_DEBUG_KMS("Disable audio codec on port %c, pipe %c\n",
port_name(port), pipe_name(pipe));
if (WARN_ON(port == PORT_A))
return;
if (HAS_PCH_IBX(dev_priv)) {
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
if (intel_crtc_has_dp_encoder(intel_crtc->config))
tmp |= AUD_CONFIG_N_VALUE_INDEX;
I915_WRITE(aud_config, tmp);
eldv = IBX_ELD_VALID(port);
tmp = I915_READ(aud_cntrl_st2);
tmp &= ~eldv;
I915_WRITE(aud_cntrl_st2, tmp);
}
static void ilk_audio_codec_enable(struct drm_connector *connector,
struct intel_encoder *intel_encoder,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = to_i915(connector->dev);
struct intel_crtc *intel_crtc = to_intel_crtc(intel_encoder->base.crtc);
enum pipe pipe = intel_crtc->pipe;
enum port port = intel_encoder->port;
uint8_t *eld = connector->eld;
uint32_t tmp, eldv;
int len, i;
i915_reg_t hdmiw_hdmiedid, aud_config, aud_cntl_st, aud_cntrl_st2;
DRM_DEBUG_KMS("Enable audio codec on port %c, pipe %c, %u bytes ELD\n",
port_name(port), pipe_name(pipe), drm_eld_size(eld));
if (WARN_ON(port == PORT_A))
return;
if (HAS_PCH_IBX(dev_priv)) {
hdmiw_hdmiedid = IBX_HDMIW_HDMIEDID(pipe);
aud_config = IBX_AUD_CFG(pipe);
aud_cntl_st = IBX_AUD_CNTL_ST(pipe);
aud_cntrl_st2 = IBX_AUD_CNTL_ST2;
} else if (IS_VALLEYVIEW(dev_priv) ||
IS_CHERRYVIEW(dev_priv)) {
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
if (intel_crtc_has_dp_encoder(intel_crtc->config))
tmp |= AUD_CONFIG_N_VALUE_INDEX;
else
tmp |= audio_config_hdmi_pixel_clock(adjusted_mode);
I915_WRITE(aud_config, tmp);
}
void intel_audio_codec_enable(struct intel_encoder *intel_encoder,
const struct intel_crtc_state *crtc_state,
const struct drm_connector_state *conn_state)
{
struct drm_encoder *encoder = &intel_encoder->base;
const struct drm_display_mode *adjusted_mode = &crtc_state->base.adjusted_mode;
struct drm_connector *connector;
struct drm_i915_private *dev_priv = to_i915(encoder->dev);
struct i915_audio_component *acomp = dev_priv->audio_component;
enum port port = intel_encoder->port;
enum pipe pipe = to_intel_crtc(crtc_state->base.crtc)->pipe;
connector = conn_state->connector;
if (!connector || !connector->eld[0])
return;
DRM_DEBUG_DRIVER("ELD on [CONNECTOR:%d:%s], [ENCODER:%d:%s]\n",
connector->base.id,
connector->name,
connector->encoder->base.id,
connector->encoder->name);
connector->eld[5] &= ~(3 << 2);
if (intel_crtc_has_dp_encoder(crtc_state))
connector->eld[5] |= (1 << 2);
connector->eld[6] = drm_av_sync_delay(connector, adjusted_mode) / 2;
if (dev_priv->display.audio_codec_enable)
dev_priv->display.audio_codec_enable(connector, intel_encoder,
adjusted_mode);
mutex_lock(&dev_priv->av_mutex);
intel_encoder->audio_connector = connector;
dev_priv->av_enc_map[pipe] = intel_encoder;
mutex_unlock(&dev_priv->av_mutex);
if (intel_encoder->type != INTEL_OUTPUT_DP_MST)
pipe = -1;
if (acomp && acomp->audio_ops && acomp->audio_ops->pin_eld_notify)
acomp->audio_ops->pin_eld_notify(acomp->audio_ops->audio_ptr,
(int) port, (int) pipe);
}
void intel_audio_codec_disable(struct intel_encoder *intel_encoder)
{
struct drm_encoder *encoder = &intel_encoder->base;
struct drm_i915_private *dev_priv = to_i915(encoder->dev);
struct i915_audio_component *acomp = dev_priv->audio_component;
enum port port = intel_encoder->port;
struct intel_crtc *crtc = to_intel_crtc(encoder->crtc);
enum pipe pipe = crtc->pipe;
if (dev_priv->display.audio_codec_disable)
dev_priv->display.audio_codec_disable(intel_encoder);
mutex_lock(&dev_priv->av_mutex);
intel_encoder->audio_connector = NULL;
dev_priv->av_enc_map[pipe] = NULL;
mutex_unlock(&dev_priv->av_mutex);
if (intel_encoder->type != INTEL_OUTPUT_DP_MST)
pipe = -1;
if (acomp && acomp->audio_ops && acomp->audio_ops->pin_eld_notify)
acomp->audio_ops->pin_eld_notify(acomp->audio_ops->audio_ptr,
(int) port, (int) pipe);
}
void intel_init_audio_hooks(struct drm_i915_private *dev_priv)
{
if (IS_G4X(dev_priv)) {
dev_priv->display.audio_codec_enable = g4x_audio_codec_enable;
dev_priv->display.audio_codec_disable = g4x_audio_codec_disable;
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
dev_priv->display.audio_codec_enable = ilk_audio_codec_enable;
dev_priv->display.audio_codec_disable = ilk_audio_codec_disable;
} else if (IS_HASWELL(dev_priv) || INTEL_INFO(dev_priv)->gen >= 8) {
dev_priv->display.audio_codec_enable = hsw_audio_codec_enable;
dev_priv->display.audio_codec_disable = hsw_audio_codec_disable;
} else if (HAS_PCH_SPLIT(dev_priv)) {
dev_priv->display.audio_codec_enable = ilk_audio_codec_enable;
dev_priv->display.audio_codec_disable = ilk_audio_codec_disable;
}
}
static void i915_audio_component_get_power(struct device *kdev)
{
intel_display_power_get(kdev_to_i915(kdev), POWER_DOMAIN_AUDIO);
}
static void i915_audio_component_put_power(struct device *kdev)
{
intel_display_power_put(kdev_to_i915(kdev), POWER_DOMAIN_AUDIO);
}
static void i915_audio_component_codec_wake_override(struct device *kdev,
bool enable)
{
struct drm_i915_private *dev_priv = kdev_to_i915(kdev);
u32 tmp;
if (!IS_SKYLAKE(dev_priv) && !IS_KABYLAKE(dev_priv))
return;
i915_audio_component_get_power(kdev);
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
i915_audio_component_put_power(kdev);
}
static int i915_audio_component_get_cdclk_freq(struct device *kdev)
{
struct drm_i915_private *dev_priv = kdev_to_i915(kdev);
if (WARN_ON_ONCE(!HAS_DDI(dev_priv)))
return -ENODEV;
return dev_priv->cdclk_freq;
}
static struct intel_encoder *get_saved_enc(struct drm_i915_private *dev_priv,
int port, int pipe)
{
if (WARN_ON(pipe >= I915_MAX_PIPES))
return NULL;
if (pipe >= 0)
return dev_priv->av_enc_map[pipe];
for_each_pipe(dev_priv, pipe) {
struct intel_encoder *encoder;
encoder = dev_priv->av_enc_map[pipe];
if (encoder == NULL)
continue;
if (port == encoder->port)
return encoder;
}
return NULL;
}
static int i915_audio_component_sync_audio_rate(struct device *kdev, int port,
int pipe, int rate)
{
struct drm_i915_private *dev_priv = kdev_to_i915(kdev);
struct intel_encoder *intel_encoder;
struct intel_crtc *crtc;
struct drm_display_mode *adjusted_mode;
struct i915_audio_component *acomp = dev_priv->audio_component;
int err = 0;
if (!HAS_DDI(dev_priv))
return 0;
i915_audio_component_get_power(kdev);
mutex_lock(&dev_priv->av_mutex);
intel_encoder = get_saved_enc(dev_priv, port, pipe);
if (!intel_encoder || !intel_encoder->base.crtc ||
(intel_encoder->type != INTEL_OUTPUT_HDMI &&
intel_encoder->type != INTEL_OUTPUT_DP)) {
DRM_DEBUG_KMS("Not valid for port %c\n", port_name(port));
err = -ENODEV;
goto unlock;
}
crtc = to_intel_crtc(intel_encoder->base.crtc);
pipe = crtc->pipe;
adjusted_mode = &crtc->config->base.adjusted_mode;
acomp->aud_sample_rate[port] = rate;
hsw_audio_config_update(crtc, port, adjusted_mode);
unlock:
mutex_unlock(&dev_priv->av_mutex);
i915_audio_component_put_power(kdev);
return err;
}
static int i915_audio_component_get_eld(struct device *kdev, int port,
int pipe, bool *enabled,
unsigned char *buf, int max_bytes)
{
struct drm_i915_private *dev_priv = kdev_to_i915(kdev);
struct intel_encoder *intel_encoder;
const u8 *eld;
int ret = -EINVAL;
mutex_lock(&dev_priv->av_mutex);
intel_encoder = get_saved_enc(dev_priv, port, pipe);
if (!intel_encoder) {
DRM_DEBUG_KMS("Not valid for port %c\n", port_name(port));
mutex_unlock(&dev_priv->av_mutex);
return ret;
}
ret = 0;
*enabled = intel_encoder->audio_connector != NULL;
if (*enabled) {
eld = intel_encoder->audio_connector->eld;
ret = drm_eld_size(eld);
memcpy(buf, eld, min(max_bytes, ret));
}
mutex_unlock(&dev_priv->av_mutex);
return ret;
}
static int i915_audio_component_bind(struct device *i915_kdev,
struct device *hda_kdev, void *data)
{
struct i915_audio_component *acomp = data;
struct drm_i915_private *dev_priv = kdev_to_i915(i915_kdev);
int i;
if (WARN_ON(acomp->ops || acomp->dev))
return -EEXIST;
drm_modeset_lock_all(&dev_priv->drm);
acomp->ops = &i915_audio_component_ops;
acomp->dev = i915_kdev;
BUILD_BUG_ON(MAX_PORTS != I915_MAX_PORTS);
for (i = 0; i < ARRAY_SIZE(acomp->aud_sample_rate); i++)
acomp->aud_sample_rate[i] = 0;
dev_priv->audio_component = acomp;
drm_modeset_unlock_all(&dev_priv->drm);
return 0;
}
static void i915_audio_component_unbind(struct device *i915_kdev,
struct device *hda_kdev, void *data)
{
struct i915_audio_component *acomp = data;
struct drm_i915_private *dev_priv = kdev_to_i915(i915_kdev);
drm_modeset_lock_all(&dev_priv->drm);
acomp->ops = NULL;
acomp->dev = NULL;
dev_priv->audio_component = NULL;
drm_modeset_unlock_all(&dev_priv->drm);
}
void i915_audio_component_init(struct drm_i915_private *dev_priv)
{
int ret;
ret = component_add(dev_priv->drm.dev, &i915_audio_component_bind_ops);
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
component_del(dev_priv->drm.dev, &i915_audio_component_bind_ops);
dev_priv->audio_component_registered = false;
}
