static struct drm_device *intel_hdmi_to_dev(struct intel_hdmi *intel_hdmi)
{
return hdmi_to_dig_port(intel_hdmi)->base.base.dev;
}
static void
assert_hdmi_port_disabled(struct intel_hdmi *intel_hdmi)
{
struct drm_device *dev = intel_hdmi_to_dev(intel_hdmi);
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t enabled_bits;
enabled_bits = HAS_DDI(dev) ? DDI_BUF_CTL_ENABLE : SDVO_ENABLE;
WARN(I915_READ(intel_hdmi->hdmi_reg) & enabled_bits,
"HDMI port enabled, expecting disabled\n");
}
struct intel_hdmi *enc_to_intel_hdmi(struct drm_encoder *encoder)
{
struct intel_digital_port *intel_dig_port =
container_of(encoder, struct intel_digital_port, base.base);
return &intel_dig_port->hdmi;
}
static struct intel_hdmi *intel_attached_hdmi(struct drm_connector *connector)
{
return enc_to_intel_hdmi(&intel_attached_encoder(connector)->base);
}
static u32 g4x_infoframe_index(enum hdmi_infoframe_type type)
{
switch (type) {
case HDMI_INFOFRAME_TYPE_AVI:
return VIDEO_DIP_SELECT_AVI;
case HDMI_INFOFRAME_TYPE_SPD:
return VIDEO_DIP_SELECT_SPD;
case HDMI_INFOFRAME_TYPE_VENDOR:
return VIDEO_DIP_SELECT_VENDOR;
default:
MISSING_CASE(type);
return 0;
}
}
static u32 g4x_infoframe_enable(enum hdmi_infoframe_type type)
{
switch (type) {
case HDMI_INFOFRAME_TYPE_AVI:
return VIDEO_DIP_ENABLE_AVI;
case HDMI_INFOFRAME_TYPE_SPD:
return VIDEO_DIP_ENABLE_SPD;
case HDMI_INFOFRAME_TYPE_VENDOR:
return VIDEO_DIP_ENABLE_VENDOR;
default:
MISSING_CASE(type);
return 0;
}
}
static u32 hsw_infoframe_enable(enum hdmi_infoframe_type type)
{
switch (type) {
case HDMI_INFOFRAME_TYPE_AVI:
return VIDEO_DIP_ENABLE_AVI_HSW;
case HDMI_INFOFRAME_TYPE_SPD:
return VIDEO_DIP_ENABLE_SPD_HSW;
case HDMI_INFOFRAME_TYPE_VENDOR:
return VIDEO_DIP_ENABLE_VS_HSW;
default:
MISSING_CASE(type);
return 0;
}
}
static i915_reg_t
hsw_dip_data_reg(struct drm_i915_private *dev_priv,
enum transcoder cpu_transcoder,
enum hdmi_infoframe_type type,
int i)
{
switch (type) {
case HDMI_INFOFRAME_TYPE_AVI:
return HSW_TVIDEO_DIP_AVI_DATA(cpu_transcoder, i);
case HDMI_INFOFRAME_TYPE_SPD:
return HSW_TVIDEO_DIP_SPD_DATA(cpu_transcoder, i);
case HDMI_INFOFRAME_TYPE_VENDOR:
return HSW_TVIDEO_DIP_VS_DATA(cpu_transcoder, i);
default:
MISSING_CASE(type);
return INVALID_MMIO_REG;
}
}
static void g4x_write_infoframe(struct drm_encoder *encoder,
enum hdmi_infoframe_type type,
const void *frame, ssize_t len)
{
const uint32_t *data = frame;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 val = I915_READ(VIDEO_DIP_CTL);
int i;
WARN(!(val & VIDEO_DIP_ENABLE), "Writing DIP with CTL reg disabled\n");
val &= ~(VIDEO_DIP_SELECT_MASK | 0xf);
val |= g4x_infoframe_index(type);
val &= ~g4x_infoframe_enable(type);
I915_WRITE(VIDEO_DIP_CTL, val);
mmiowb();
for (i = 0; i < len; i += 4) {
I915_WRITE(VIDEO_DIP_DATA, *data);
data++;
}
for (; i < VIDEO_DIP_DATA_SIZE; i += 4)
I915_WRITE(VIDEO_DIP_DATA, 0);
mmiowb();
val |= g4x_infoframe_enable(type);
val &= ~VIDEO_DIP_FREQ_MASK;
val |= VIDEO_DIP_FREQ_VSYNC;
I915_WRITE(VIDEO_DIP_CTL, val);
POSTING_READ(VIDEO_DIP_CTL);
}
static bool g4x_infoframe_enabled(struct drm_encoder *encoder,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->dev);
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
u32 val = I915_READ(VIDEO_DIP_CTL);
if ((val & VIDEO_DIP_ENABLE) == 0)
return false;
if ((val & VIDEO_DIP_PORT_MASK) != VIDEO_DIP_PORT(intel_dig_port->port))
return false;
return val & (VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_SPD);
}
static void ibx_write_infoframe(struct drm_encoder *encoder,
enum hdmi_infoframe_type type,
const void *frame, ssize_t len)
{
const uint32_t *data = frame;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
i915_reg_t reg = TVIDEO_DIP_CTL(intel_crtc->pipe);
u32 val = I915_READ(reg);
int i;
WARN(!(val & VIDEO_DIP_ENABLE), "Writing DIP with CTL reg disabled\n");
val &= ~(VIDEO_DIP_SELECT_MASK | 0xf);
val |= g4x_infoframe_index(type);
val &= ~g4x_infoframe_enable(type);
I915_WRITE(reg, val);
mmiowb();
for (i = 0; i < len; i += 4) {
I915_WRITE(TVIDEO_DIP_DATA(intel_crtc->pipe), *data);
data++;
}
for (; i < VIDEO_DIP_DATA_SIZE; i += 4)
I915_WRITE(TVIDEO_DIP_DATA(intel_crtc->pipe), 0);
mmiowb();
val |= g4x_infoframe_enable(type);
val &= ~VIDEO_DIP_FREQ_MASK;
val |= VIDEO_DIP_FREQ_VSYNC;
I915_WRITE(reg, val);
POSTING_READ(reg);
}
static bool ibx_infoframe_enabled(struct drm_encoder *encoder,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->dev);
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
enum pipe pipe = to_intel_crtc(pipe_config->base.crtc)->pipe;
i915_reg_t reg = TVIDEO_DIP_CTL(pipe);
u32 val = I915_READ(reg);
if ((val & VIDEO_DIP_ENABLE) == 0)
return false;
if ((val & VIDEO_DIP_PORT_MASK) != VIDEO_DIP_PORT(intel_dig_port->port))
return false;
return val & (VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
}
static void cpt_write_infoframe(struct drm_encoder *encoder,
enum hdmi_infoframe_type type,
const void *frame, ssize_t len)
{
const uint32_t *data = frame;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
i915_reg_t reg = TVIDEO_DIP_CTL(intel_crtc->pipe);
u32 val = I915_READ(reg);
int i;
WARN(!(val & VIDEO_DIP_ENABLE), "Writing DIP with CTL reg disabled\n");
val &= ~(VIDEO_DIP_SELECT_MASK | 0xf);
val |= g4x_infoframe_index(type);
if (type != HDMI_INFOFRAME_TYPE_AVI)
val &= ~g4x_infoframe_enable(type);
I915_WRITE(reg, val);
mmiowb();
for (i = 0; i < len; i += 4) {
I915_WRITE(TVIDEO_DIP_DATA(intel_crtc->pipe), *data);
data++;
}
for (; i < VIDEO_DIP_DATA_SIZE; i += 4)
I915_WRITE(TVIDEO_DIP_DATA(intel_crtc->pipe), 0);
mmiowb();
val |= g4x_infoframe_enable(type);
val &= ~VIDEO_DIP_FREQ_MASK;
val |= VIDEO_DIP_FREQ_VSYNC;
I915_WRITE(reg, val);
POSTING_READ(reg);
}
static bool cpt_infoframe_enabled(struct drm_encoder *encoder,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->dev);
enum pipe pipe = to_intel_crtc(pipe_config->base.crtc)->pipe;
u32 val = I915_READ(TVIDEO_DIP_CTL(pipe));
if ((val & VIDEO_DIP_ENABLE) == 0)
return false;
return val & (VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
}
static void vlv_write_infoframe(struct drm_encoder *encoder,
enum hdmi_infoframe_type type,
const void *frame, ssize_t len)
{
const uint32_t *data = frame;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
i915_reg_t reg = VLV_TVIDEO_DIP_CTL(intel_crtc->pipe);
u32 val = I915_READ(reg);
int i;
WARN(!(val & VIDEO_DIP_ENABLE), "Writing DIP with CTL reg disabled\n");
val &= ~(VIDEO_DIP_SELECT_MASK | 0xf);
val |= g4x_infoframe_index(type);
val &= ~g4x_infoframe_enable(type);
I915_WRITE(reg, val);
mmiowb();
for (i = 0; i < len; i += 4) {
I915_WRITE(VLV_TVIDEO_DIP_DATA(intel_crtc->pipe), *data);
data++;
}
for (; i < VIDEO_DIP_DATA_SIZE; i += 4)
I915_WRITE(VLV_TVIDEO_DIP_DATA(intel_crtc->pipe), 0);
mmiowb();
val |= g4x_infoframe_enable(type);
val &= ~VIDEO_DIP_FREQ_MASK;
val |= VIDEO_DIP_FREQ_VSYNC;
I915_WRITE(reg, val);
POSTING_READ(reg);
}
static bool vlv_infoframe_enabled(struct drm_encoder *encoder,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->dev);
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
enum pipe pipe = to_intel_crtc(pipe_config->base.crtc)->pipe;
u32 val = I915_READ(VLV_TVIDEO_DIP_CTL(pipe));
if ((val & VIDEO_DIP_ENABLE) == 0)
return false;
if ((val & VIDEO_DIP_PORT_MASK) != VIDEO_DIP_PORT(intel_dig_port->port))
return false;
return val & (VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
}
static void hsw_write_infoframe(struct drm_encoder *encoder,
enum hdmi_infoframe_type type,
const void *frame, ssize_t len)
{
const uint32_t *data = frame;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
enum transcoder cpu_transcoder = intel_crtc->config->cpu_transcoder;
i915_reg_t ctl_reg = HSW_TVIDEO_DIP_CTL(cpu_transcoder);
i915_reg_t data_reg;
int i;
u32 val = I915_READ(ctl_reg);
data_reg = hsw_dip_data_reg(dev_priv, cpu_transcoder, type, 0);
val &= ~hsw_infoframe_enable(type);
I915_WRITE(ctl_reg, val);
mmiowb();
for (i = 0; i < len; i += 4) {
I915_WRITE(hsw_dip_data_reg(dev_priv, cpu_transcoder,
type, i >> 2), *data);
data++;
}
for (; i < VIDEO_DIP_DATA_SIZE; i += 4)
I915_WRITE(hsw_dip_data_reg(dev_priv, cpu_transcoder,
type, i >> 2), 0);
mmiowb();
val |= hsw_infoframe_enable(type);
I915_WRITE(ctl_reg, val);
POSTING_READ(ctl_reg);
}
static bool hsw_infoframe_enabled(struct drm_encoder *encoder,
const struct intel_crtc_state *pipe_config)
{
struct drm_i915_private *dev_priv = to_i915(encoder->dev);
u32 val = I915_READ(HSW_TVIDEO_DIP_CTL(pipe_config->cpu_transcoder));
return val & (VIDEO_DIP_ENABLE_VSC_HSW | VIDEO_DIP_ENABLE_AVI_HSW |
VIDEO_DIP_ENABLE_GCP_HSW | VIDEO_DIP_ENABLE_VS_HSW |
VIDEO_DIP_ENABLE_GMP_HSW | VIDEO_DIP_ENABLE_SPD_HSW);
}
static void intel_write_infoframe(struct drm_encoder *encoder,
union hdmi_infoframe *frame)
{
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
uint8_t buffer[VIDEO_DIP_DATA_SIZE];
ssize_t len;
len = hdmi_infoframe_pack(frame, buffer + 1, sizeof(buffer) - 1);
if (len < 0)
return;
buffer[0] = buffer[1];
buffer[1] = buffer[2];
buffer[2] = buffer[3];
buffer[3] = 0;
len++;
intel_hdmi->write_infoframe(encoder, frame->any.type, buffer, len);
}
static void intel_hdmi_set_avi_infoframe(struct drm_encoder *encoder,
const struct drm_display_mode *adjusted_mode)
{
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
union hdmi_infoframe frame;
int ret;
ret = drm_hdmi_avi_infoframe_from_display_mode(&frame.avi,
adjusted_mode);
if (ret < 0) {
DRM_ERROR("couldn't fill AVI infoframe\n");
return;
}
if (intel_hdmi->rgb_quant_range_selectable) {
if (intel_crtc->config->limited_color_range)
frame.avi.quantization_range =
HDMI_QUANTIZATION_RANGE_LIMITED;
else
frame.avi.quantization_range =
HDMI_QUANTIZATION_RANGE_FULL;
}
intel_write_infoframe(encoder, &frame);
}
static void intel_hdmi_set_spd_infoframe(struct drm_encoder *encoder)
{
union hdmi_infoframe frame;
int ret;
ret = hdmi_spd_infoframe_init(&frame.spd, "Intel", "Integrated gfx");
if (ret < 0) {
DRM_ERROR("couldn't fill SPD infoframe\n");
return;
}
frame.spd.sdi = HDMI_SPD_SDI_PC;
intel_write_infoframe(encoder, &frame);
}
static void
intel_hdmi_set_hdmi_infoframe(struct drm_encoder *encoder,
const struct drm_display_mode *adjusted_mode)
{
union hdmi_infoframe frame;
int ret;
ret = drm_hdmi_vendor_infoframe_from_display_mode(&frame.vendor.hdmi,
adjusted_mode);
if (ret < 0)
return;
intel_write_infoframe(encoder, &frame);
}
static void g4x_set_infoframes(struct drm_encoder *encoder,
bool enable,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
struct intel_hdmi *intel_hdmi = &intel_dig_port->hdmi;
i915_reg_t reg = VIDEO_DIP_CTL;
u32 val = I915_READ(reg);
u32 port = VIDEO_DIP_PORT(intel_dig_port->port);
assert_hdmi_port_disabled(intel_hdmi);
val |= VIDEO_DIP_SELECT_AVI | VIDEO_DIP_FREQ_VSYNC;
if (!enable) {
if (!(val & VIDEO_DIP_ENABLE))
return;
if (port != (val & VIDEO_DIP_PORT_MASK)) {
DRM_DEBUG_KMS("video DIP still enabled on port %c\n",
(val & VIDEO_DIP_PORT_MASK) >> 29);
return;
}
val &= ~(VIDEO_DIP_ENABLE | VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_SPD);
I915_WRITE(reg, val);
POSTING_READ(reg);
return;
}
if (port != (val & VIDEO_DIP_PORT_MASK)) {
if (val & VIDEO_DIP_ENABLE) {
DRM_DEBUG_KMS("video DIP already enabled on port %c\n",
(val & VIDEO_DIP_PORT_MASK) >> 29);
return;
}
val &= ~VIDEO_DIP_PORT_MASK;
val |= port;
}
val |= VIDEO_DIP_ENABLE;
val &= ~(VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_SPD);
I915_WRITE(reg, val);
POSTING_READ(reg);
intel_hdmi_set_avi_infoframe(encoder, adjusted_mode);
intel_hdmi_set_spd_infoframe(encoder);
intel_hdmi_set_hdmi_infoframe(encoder, adjusted_mode);
}
static bool hdmi_sink_is_deep_color(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct drm_connector *connector;
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
if (connector->encoder == encoder)
return connector->display_info.bpc > 8;
return false;
}
static bool gcp_default_phase_possible(int pipe_bpp,
const struct drm_display_mode *mode)
{
unsigned int pixels_per_group;
switch (pipe_bpp) {
case 30:
pixels_per_group = 4;
break;
case 36:
pixels_per_group = 2;
break;
case 48:
pixels_per_group = 1;
break;
default:
return false;
}
return mode->crtc_hdisplay % pixels_per_group == 0 &&
mode->crtc_htotal % pixels_per_group == 0 &&
mode->crtc_hblank_start % pixels_per_group == 0 &&
mode->crtc_hblank_end % pixels_per_group == 0 &&
mode->crtc_hsync_start % pixels_per_group == 0 &&
mode->crtc_hsync_end % pixels_per_group == 0 &&
((mode->flags & DRM_MODE_FLAG_INTERLACE) == 0 ||
mode->crtc_htotal/2 % pixels_per_group == 0);
}
static bool intel_hdmi_set_gcp_infoframe(struct drm_encoder *encoder)
{
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(encoder->crtc);
i915_reg_t reg;
u32 val = 0;
if (HAS_DDI(dev_priv))
reg = HSW_TVIDEO_DIP_GCP(crtc->config->cpu_transcoder);
else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
reg = VLV_TVIDEO_DIP_GCP(crtc->pipe);
else if (HAS_PCH_SPLIT(dev_priv))
reg = TVIDEO_DIP_GCP(crtc->pipe);
else
return false;
if (hdmi_sink_is_deep_color(encoder))
val |= GCP_COLOR_INDICATION;
if (gcp_default_phase_possible(crtc->config->pipe_bpp,
&crtc->config->base.adjusted_mode))
val |= GCP_DEFAULT_PHASE_ENABLE;
I915_WRITE(reg, val);
return val != 0;
}
static void ibx_set_infoframes(struct drm_encoder *encoder,
bool enable,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
struct intel_hdmi *intel_hdmi = &intel_dig_port->hdmi;
i915_reg_t reg = TVIDEO_DIP_CTL(intel_crtc->pipe);
u32 val = I915_READ(reg);
u32 port = VIDEO_DIP_PORT(intel_dig_port->port);
assert_hdmi_port_disabled(intel_hdmi);
val |= VIDEO_DIP_SELECT_AVI | VIDEO_DIP_FREQ_VSYNC;
if (!enable) {
if (!(val & VIDEO_DIP_ENABLE))
return;
val &= ~(VIDEO_DIP_ENABLE | VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
I915_WRITE(reg, val);
POSTING_READ(reg);
return;
}
if (port != (val & VIDEO_DIP_PORT_MASK)) {
WARN(val & VIDEO_DIP_ENABLE,
"DIP already enabled on port %c\n",
(val & VIDEO_DIP_PORT_MASK) >> 29);
val &= ~VIDEO_DIP_PORT_MASK;
val |= port;
}
val |= VIDEO_DIP_ENABLE;
val &= ~(VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
if (intel_hdmi_set_gcp_infoframe(encoder))
val |= VIDEO_DIP_ENABLE_GCP;
I915_WRITE(reg, val);
POSTING_READ(reg);
intel_hdmi_set_avi_infoframe(encoder, adjusted_mode);
intel_hdmi_set_spd_infoframe(encoder);
intel_hdmi_set_hdmi_infoframe(encoder, adjusted_mode);
}
static void cpt_set_infoframes(struct drm_encoder *encoder,
bool enable,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
i915_reg_t reg = TVIDEO_DIP_CTL(intel_crtc->pipe);
u32 val = I915_READ(reg);
assert_hdmi_port_disabled(intel_hdmi);
val |= VIDEO_DIP_SELECT_AVI | VIDEO_DIP_FREQ_VSYNC;
if (!enable) {
if (!(val & VIDEO_DIP_ENABLE))
return;
val &= ~(VIDEO_DIP_ENABLE | VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
I915_WRITE(reg, val);
POSTING_READ(reg);
return;
}
val |= VIDEO_DIP_ENABLE | VIDEO_DIP_ENABLE_AVI;
val &= ~(VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
if (intel_hdmi_set_gcp_infoframe(encoder))
val |= VIDEO_DIP_ENABLE_GCP;
I915_WRITE(reg, val);
POSTING_READ(reg);
intel_hdmi_set_avi_infoframe(encoder, adjusted_mode);
intel_hdmi_set_spd_infoframe(encoder);
intel_hdmi_set_hdmi_infoframe(encoder, adjusted_mode);
}
static void vlv_set_infoframes(struct drm_encoder *encoder,
bool enable,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
struct intel_digital_port *intel_dig_port = enc_to_dig_port(encoder);
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
i915_reg_t reg = VLV_TVIDEO_DIP_CTL(intel_crtc->pipe);
u32 val = I915_READ(reg);
u32 port = VIDEO_DIP_PORT(intel_dig_port->port);
assert_hdmi_port_disabled(intel_hdmi);
val |= VIDEO_DIP_SELECT_AVI | VIDEO_DIP_FREQ_VSYNC;
if (!enable) {
if (!(val & VIDEO_DIP_ENABLE))
return;
val &= ~(VIDEO_DIP_ENABLE | VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
I915_WRITE(reg, val);
POSTING_READ(reg);
return;
}
if (port != (val & VIDEO_DIP_PORT_MASK)) {
WARN(val & VIDEO_DIP_ENABLE,
"DIP already enabled on port %c\n",
(val & VIDEO_DIP_PORT_MASK) >> 29);
val &= ~VIDEO_DIP_PORT_MASK;
val |= port;
}
val |= VIDEO_DIP_ENABLE;
val &= ~(VIDEO_DIP_ENABLE_AVI |
VIDEO_DIP_ENABLE_VENDOR | VIDEO_DIP_ENABLE_GAMUT |
VIDEO_DIP_ENABLE_SPD | VIDEO_DIP_ENABLE_GCP);
if (intel_hdmi_set_gcp_infoframe(encoder))
val |= VIDEO_DIP_ENABLE_GCP;
I915_WRITE(reg, val);
POSTING_READ(reg);
intel_hdmi_set_avi_infoframe(encoder, adjusted_mode);
intel_hdmi_set_spd_infoframe(encoder);
intel_hdmi_set_hdmi_infoframe(encoder, adjusted_mode);
}
static void hsw_set_infoframes(struct drm_encoder *encoder,
bool enable,
const struct drm_display_mode *adjusted_mode)
{
struct drm_i915_private *dev_priv = encoder->dev->dev_private;
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
i915_reg_t reg = HSW_TVIDEO_DIP_CTL(intel_crtc->config->cpu_transcoder);
u32 val = I915_READ(reg);
assert_hdmi_port_disabled(intel_hdmi);
val &= ~(VIDEO_DIP_ENABLE_VSC_HSW | VIDEO_DIP_ENABLE_AVI_HSW |
VIDEO_DIP_ENABLE_GCP_HSW | VIDEO_DIP_ENABLE_VS_HSW |
VIDEO_DIP_ENABLE_GMP_HSW | VIDEO_DIP_ENABLE_SPD_HSW);
if (!enable) {
I915_WRITE(reg, val);
POSTING_READ(reg);
return;
}
if (intel_hdmi_set_gcp_infoframe(encoder))
val |= VIDEO_DIP_ENABLE_GCP_HSW;
I915_WRITE(reg, val);
POSTING_READ(reg);
intel_hdmi_set_avi_infoframe(encoder, adjusted_mode);
intel_hdmi_set_spd_infoframe(encoder);
intel_hdmi_set_hdmi_infoframe(encoder, adjusted_mode);
}
void intel_dp_dual_mode_set_tmds_output(struct intel_hdmi *hdmi, bool enable)
{
struct drm_i915_private *dev_priv = to_i915(intel_hdmi_to_dev(hdmi));
struct i2c_adapter *adapter =
intel_gmbus_get_adapter(dev_priv, hdmi->ddc_bus);
if (hdmi->dp_dual_mode.type < DRM_DP_DUAL_MODE_TYPE2_DVI)
return;
DRM_DEBUG_KMS("%s DP dual mode adaptor TMDS output\n",
enable ? "Enabling" : "Disabling");
drm_dp_dual_mode_set_tmds_output(hdmi->dp_dual_mode.type,
adapter, enable);
}
static void intel_hdmi_prepare(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
const struct drm_display_mode *adjusted_mode = &crtc->config->base.adjusted_mode;
u32 hdmi_val;
intel_dp_dual_mode_set_tmds_output(intel_hdmi, true);
hdmi_val = SDVO_ENCODING_HDMI;
if (!HAS_PCH_SPLIT(dev) && crtc->config->limited_color_range)
hdmi_val |= HDMI_COLOR_RANGE_16_235;
if (adjusted_mode->flags & DRM_MODE_FLAG_PVSYNC)
hdmi_val |= SDVO_VSYNC_ACTIVE_HIGH;
if (adjusted_mode->flags & DRM_MODE_FLAG_PHSYNC)
hdmi_val |= SDVO_HSYNC_ACTIVE_HIGH;
if (crtc->config->pipe_bpp > 24)
hdmi_val |= HDMI_COLOR_FORMAT_12bpc;
else
hdmi_val |= SDVO_COLOR_FORMAT_8bpc;
if (crtc->config->has_hdmi_sink)
hdmi_val |= HDMI_MODE_SELECT_HDMI;
if (HAS_PCH_CPT(dev))
hdmi_val |= SDVO_PIPE_SEL_CPT(crtc->pipe);
else if (IS_CHERRYVIEW(dev))
hdmi_val |= SDVO_PIPE_SEL_CHV(crtc->pipe);
else
hdmi_val |= SDVO_PIPE_SEL(crtc->pipe);
I915_WRITE(intel_hdmi->hdmi_reg, hdmi_val);
POSTING_READ(intel_hdmi->hdmi_reg);
}
static bool intel_hdmi_get_hw_state(struct intel_encoder *encoder,
enum pipe *pipe)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
enum intel_display_power_domain power_domain;
u32 tmp;
bool ret;
power_domain = intel_display_port_power_domain(encoder);
if (!intel_display_power_get_if_enabled(dev_priv, power_domain))
return false;
ret = false;
tmp = I915_READ(intel_hdmi->hdmi_reg);
if (!(tmp & SDVO_ENABLE))
goto out;
if (HAS_PCH_CPT(dev))
*pipe = PORT_TO_PIPE_CPT(tmp);
else if (IS_CHERRYVIEW(dev))
*pipe = SDVO_PORT_TO_PIPE_CHV(tmp);
else
*pipe = PORT_TO_PIPE(tmp);
ret = true;
out:
intel_display_power_put(dev_priv, power_domain);
return ret;
}
static void intel_hdmi_get_config(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config)
{
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 tmp, flags = 0;
int dotclock;
tmp = I915_READ(intel_hdmi->hdmi_reg);
if (tmp & SDVO_HSYNC_ACTIVE_HIGH)
flags |= DRM_MODE_FLAG_PHSYNC;
else
flags |= DRM_MODE_FLAG_NHSYNC;
if (tmp & SDVO_VSYNC_ACTIVE_HIGH)
flags |= DRM_MODE_FLAG_PVSYNC;
else
flags |= DRM_MODE_FLAG_NVSYNC;
if (tmp & HDMI_MODE_SELECT_HDMI)
pipe_config->has_hdmi_sink = true;
if (intel_hdmi->infoframe_enabled(&encoder->base, pipe_config))
pipe_config->has_infoframe = true;
if (tmp & SDVO_AUDIO_ENABLE)
pipe_config->has_audio = true;
if (!HAS_PCH_SPLIT(dev) &&
tmp & HDMI_COLOR_RANGE_16_235)
pipe_config->limited_color_range = true;
pipe_config->base.adjusted_mode.flags |= flags;
if ((tmp & SDVO_COLOR_FORMAT_MASK) == HDMI_COLOR_FORMAT_12bpc)
dotclock = pipe_config->port_clock * 2 / 3;
else
dotclock = pipe_config->port_clock;
if (pipe_config->pixel_multiplier)
dotclock /= pipe_config->pixel_multiplier;
pipe_config->base.adjusted_mode.crtc_clock = dotclock;
pipe_config->lane_count = 4;
}
static void intel_enable_hdmi_audio(struct intel_encoder *encoder)
{
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
WARN_ON(!crtc->config->has_hdmi_sink);
DRM_DEBUG_DRIVER("Enabling HDMI audio on pipe %c\n",
pipe_name(crtc->pipe));
intel_audio_codec_enable(encoder);
}
static void g4x_enable_hdmi(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
u32 temp;
temp = I915_READ(intel_hdmi->hdmi_reg);
temp |= SDVO_ENABLE;
if (crtc->config->has_audio)
temp |= SDVO_AUDIO_ENABLE;
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
if (crtc->config->has_audio)
intel_enable_hdmi_audio(encoder);
}
static void ibx_enable_hdmi(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
u32 temp;
temp = I915_READ(intel_hdmi->hdmi_reg);
temp |= SDVO_ENABLE;
if (crtc->config->has_audio)
temp |= SDVO_AUDIO_ENABLE;
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
if (crtc->config->pipe_bpp > 24 &&
crtc->config->pixel_multiplier > 1) {
I915_WRITE(intel_hdmi->hdmi_reg, temp & ~SDVO_ENABLE);
POSTING_READ(intel_hdmi->hdmi_reg);
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
}
if (crtc->config->has_audio)
intel_enable_hdmi_audio(encoder);
}
static void cpt_enable_hdmi(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
enum pipe pipe = crtc->pipe;
u32 temp;
temp = I915_READ(intel_hdmi->hdmi_reg);
temp |= SDVO_ENABLE;
if (crtc->config->has_audio)
temp |= SDVO_AUDIO_ENABLE;
if (crtc->config->pipe_bpp > 24) {
I915_WRITE(TRANS_CHICKEN1(pipe),
I915_READ(TRANS_CHICKEN1(pipe)) |
TRANS_CHICKEN1_HDMIUNIT_GC_DISABLE);
temp &= ~SDVO_COLOR_FORMAT_MASK;
temp |= SDVO_COLOR_FORMAT_8bpc;
}
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
if (crtc->config->pipe_bpp > 24) {
temp &= ~SDVO_COLOR_FORMAT_MASK;
temp |= HDMI_COLOR_FORMAT_12bpc;
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
I915_WRITE(TRANS_CHICKEN1(pipe),
I915_READ(TRANS_CHICKEN1(pipe)) &
~TRANS_CHICKEN1_HDMIUNIT_GC_DISABLE);
}
if (crtc->config->has_audio)
intel_enable_hdmi_audio(encoder);
}
static void vlv_enable_hdmi(struct intel_encoder *encoder)
{
}
static void intel_disable_hdmi(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
u32 temp;
temp = I915_READ(intel_hdmi->hdmi_reg);
temp &= ~(SDVO_ENABLE | SDVO_AUDIO_ENABLE);
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
if (HAS_PCH_IBX(dev) && crtc->pipe == PIPE_B) {
intel_set_cpu_fifo_underrun_reporting(dev_priv, PIPE_A, false);
intel_set_pch_fifo_underrun_reporting(dev_priv, PIPE_A, false);
temp &= ~SDVO_PIPE_B_SELECT;
temp |= SDVO_ENABLE;
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
temp &= ~SDVO_ENABLE;
I915_WRITE(intel_hdmi->hdmi_reg, temp);
POSTING_READ(intel_hdmi->hdmi_reg);
intel_wait_for_vblank_if_active(dev_priv->dev, PIPE_A);
intel_set_cpu_fifo_underrun_reporting(dev_priv, PIPE_A, true);
intel_set_pch_fifo_underrun_reporting(dev_priv, PIPE_A, true);
}
intel_hdmi->set_infoframes(&encoder->base, false, NULL);
intel_dp_dual_mode_set_tmds_output(intel_hdmi, false);
}
static void g4x_disable_hdmi(struct intel_encoder *encoder)
{
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
if (crtc->config->has_audio)
intel_audio_codec_disable(encoder);
intel_disable_hdmi(encoder);
}
static void pch_disable_hdmi(struct intel_encoder *encoder)
{
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
if (crtc->config->has_audio)
intel_audio_codec_disable(encoder);
}
static void pch_post_disable_hdmi(struct intel_encoder *encoder)
{
intel_disable_hdmi(encoder);
}
static int intel_hdmi_source_max_tmds_clock(struct drm_i915_private *dev_priv)
{
if (IS_G4X(dev_priv))
return 165000;
else if (IS_HASWELL(dev_priv) || INTEL_INFO(dev_priv)->gen >= 8)
return 300000;
else
return 225000;
}
static int hdmi_port_clock_limit(struct intel_hdmi *hdmi,
bool respect_downstream_limits)
{
struct drm_device *dev = intel_hdmi_to_dev(hdmi);
int max_tmds_clock = intel_hdmi_source_max_tmds_clock(to_i915(dev));
if (respect_downstream_limits) {
if (hdmi->dp_dual_mode.max_tmds_clock)
max_tmds_clock = min(max_tmds_clock,
hdmi->dp_dual_mode.max_tmds_clock);
if (!hdmi->has_hdmi_sink)
max_tmds_clock = min(max_tmds_clock, 165000);
}
return max_tmds_clock;
}
static enum drm_mode_status
hdmi_port_clock_valid(struct intel_hdmi *hdmi,
int clock, bool respect_downstream_limits)
{
struct drm_device *dev = intel_hdmi_to_dev(hdmi);
if (clock < 25000)
return MODE_CLOCK_LOW;
if (clock > hdmi_port_clock_limit(hdmi, respect_downstream_limits))
return MODE_CLOCK_HIGH;
if (IS_BROXTON(dev) && clock > 223333 && clock < 240000)
return MODE_CLOCK_RANGE;
if (IS_CHERRYVIEW(dev) && clock > 216000 && clock < 240000)
return MODE_CLOCK_RANGE;
return MODE_OK;
}
static enum drm_mode_status
intel_hdmi_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct intel_hdmi *hdmi = intel_attached_hdmi(connector);
struct drm_device *dev = intel_hdmi_to_dev(hdmi);
enum drm_mode_status status;
int clock;
int max_dotclk = to_i915(connector->dev)->max_dotclk_freq;
if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
return MODE_NO_DBLESCAN;
clock = mode->clock;
if ((mode->flags & DRM_MODE_FLAG_3D_MASK) == DRM_MODE_FLAG_3D_FRAME_PACKING)
clock *= 2;
if (clock > max_dotclk)
return MODE_CLOCK_HIGH;
if (mode->flags & DRM_MODE_FLAG_DBLCLK)
clock *= 2;
status = hdmi_port_clock_valid(hdmi, clock, true);
if (!HAS_GMCH_DISPLAY(dev) && status != MODE_OK)
status = hdmi_port_clock_valid(hdmi, clock * 3 / 2, true);
return status;
}
static bool hdmi_12bpc_possible(struct intel_crtc_state *crtc_state)
{
struct drm_device *dev = crtc_state->base.crtc->dev;
struct drm_atomic_state *state;
struct intel_encoder *encoder;
struct drm_connector *connector;
struct drm_connector_state *connector_state;
int count = 0, count_hdmi = 0;
int i;
if (HAS_GMCH_DISPLAY(dev))
return false;
state = crtc_state->base.state;
for_each_connector_in_state(state, connector, connector_state, i) {
if (connector_state->crtc != crtc_state->base.crtc)
continue;
encoder = to_intel_encoder(connector_state->best_encoder);
count_hdmi += encoder->type == INTEL_OUTPUT_HDMI;
count++;
}
return count_hdmi > 0 && count_hdmi == count;
}
bool intel_hdmi_compute_config(struct intel_encoder *encoder,
struct intel_crtc_state *pipe_config)
{
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
struct drm_device *dev = encoder->base.dev;
struct drm_display_mode *adjusted_mode = &pipe_config->base.adjusted_mode;
int clock_8bpc = pipe_config->base.adjusted_mode.crtc_clock;
int clock_12bpc = clock_8bpc * 3 / 2;
int desired_bpp;
pipe_config->has_hdmi_sink = intel_hdmi->has_hdmi_sink;
if (pipe_config->has_hdmi_sink)
pipe_config->has_infoframe = true;
if (intel_hdmi->color_range_auto) {
pipe_config->limited_color_range =
pipe_config->has_hdmi_sink &&
drm_match_cea_mode(adjusted_mode) > 1;
} else {
pipe_config->limited_color_range =
intel_hdmi->limited_color_range;
}
if (adjusted_mode->flags & DRM_MODE_FLAG_DBLCLK) {
pipe_config->pixel_multiplier = 2;
clock_8bpc *= 2;
clock_12bpc *= 2;
}
if (HAS_PCH_SPLIT(dev) && !HAS_DDI(dev))
pipe_config->has_pch_encoder = true;
if (pipe_config->has_hdmi_sink && intel_hdmi->has_audio)
pipe_config->has_audio = true;
if (pipe_config->pipe_bpp > 8*3 && pipe_config->has_hdmi_sink &&
hdmi_port_clock_valid(intel_hdmi, clock_12bpc, true) == MODE_OK &&
hdmi_12bpc_possible(pipe_config)) {
DRM_DEBUG_KMS("picking bpc to 12 for HDMI output\n");
desired_bpp = 12*3;
pipe_config->port_clock = clock_12bpc;
} else {
DRM_DEBUG_KMS("picking bpc to 8 for HDMI output\n");
desired_bpp = 8*3;
pipe_config->port_clock = clock_8bpc;
}
if (!pipe_config->bw_constrained) {
DRM_DEBUG_KMS("forcing pipe bpc to %i for HDMI\n", desired_bpp);
pipe_config->pipe_bpp = desired_bpp;
}
if (hdmi_port_clock_valid(intel_hdmi, pipe_config->port_clock,
false) != MODE_OK) {
DRM_DEBUG_KMS("unsupported HDMI clock, rejecting mode\n");
return false;
}
adjusted_mode->picture_aspect_ratio = intel_hdmi->aspect_ratio;
pipe_config->lane_count = 4;
return true;
}
static void
intel_hdmi_unset_edid(struct drm_connector *connector)
{
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
intel_hdmi->has_hdmi_sink = false;
intel_hdmi->has_audio = false;
intel_hdmi->rgb_quant_range_selectable = false;
intel_hdmi->dp_dual_mode.type = DRM_DP_DUAL_MODE_NONE;
intel_hdmi->dp_dual_mode.max_tmds_clock = 0;
kfree(to_intel_connector(connector)->detect_edid);
to_intel_connector(connector)->detect_edid = NULL;
}
static void
intel_hdmi_dp_dual_mode_detect(struct drm_connector *connector, bool has_edid)
{
struct drm_i915_private *dev_priv = to_i915(connector->dev);
struct intel_hdmi *hdmi = intel_attached_hdmi(connector);
enum port port = hdmi_to_dig_port(hdmi)->port;
struct i2c_adapter *adapter =
intel_gmbus_get_adapter(dev_priv, hdmi->ddc_bus);
enum drm_dp_dual_mode_type type = drm_dp_dual_mode_detect(adapter);
if (type == DRM_DP_DUAL_MODE_UNKNOWN) {
if (has_edid &&
intel_bios_is_port_dp_dual_mode(dev_priv, port)) {
DRM_DEBUG_KMS("Assuming DP dual mode adaptor presence based on VBT\n");
type = DRM_DP_DUAL_MODE_TYPE1_DVI;
} else {
type = DRM_DP_DUAL_MODE_NONE;
}
}
if (type == DRM_DP_DUAL_MODE_NONE)
return;
hdmi->dp_dual_mode.type = type;
hdmi->dp_dual_mode.max_tmds_clock =
drm_dp_dual_mode_max_tmds_clock(type, adapter);
DRM_DEBUG_KMS("DP dual mode adaptor (%s) detected (max TMDS clock: %d kHz)\n",
drm_dp_get_dual_mode_type_name(type),
hdmi->dp_dual_mode.max_tmds_clock);
}
static bool
intel_hdmi_set_edid(struct drm_connector *connector, bool force)
{
struct drm_i915_private *dev_priv = to_i915(connector->dev);
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
struct edid *edid = NULL;
bool connected = false;
if (force) {
intel_display_power_get(dev_priv, POWER_DOMAIN_GMBUS);
edid = drm_get_edid(connector,
intel_gmbus_get_adapter(dev_priv,
intel_hdmi->ddc_bus));
intel_hdmi_dp_dual_mode_detect(connector, edid != NULL);
intel_display_power_put(dev_priv, POWER_DOMAIN_GMBUS);
}
to_intel_connector(connector)->detect_edid = edid;
if (edid && edid->input & DRM_EDID_INPUT_DIGITAL) {
intel_hdmi->rgb_quant_range_selectable =
drm_rgb_quant_range_selectable(edid);
intel_hdmi->has_audio = drm_detect_monitor_audio(edid);
if (intel_hdmi->force_audio != HDMI_AUDIO_AUTO)
intel_hdmi->has_audio =
intel_hdmi->force_audio == HDMI_AUDIO_ON;
if (intel_hdmi->force_audio != HDMI_AUDIO_OFF_DVI)
intel_hdmi->has_hdmi_sink =
drm_detect_hdmi_monitor(edid);
connected = true;
}
return connected;
}
static enum drm_connector_status
intel_hdmi_detect(struct drm_connector *connector, bool force)
{
enum drm_connector_status status;
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
struct drm_i915_private *dev_priv = to_i915(connector->dev);
bool live_status = false;
unsigned int try;
DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n",
connector->base.id, connector->name);
intel_display_power_get(dev_priv, POWER_DOMAIN_GMBUS);
for (try = 0; !live_status && try < 9; try++) {
if (try)
msleep(10);
live_status = intel_digital_port_connected(dev_priv,
hdmi_to_dig_port(intel_hdmi));
}
if (!live_status) {
DRM_DEBUG_KMS("HDMI live status down\n");
if (INTEL_INFO(dev_priv)->gen < 7 || IS_IVYBRIDGE(dev_priv))
live_status = true;
}
intel_hdmi_unset_edid(connector);
if (intel_hdmi_set_edid(connector, live_status)) {
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
hdmi_to_dig_port(intel_hdmi)->base.type = INTEL_OUTPUT_HDMI;
status = connector_status_connected;
} else
status = connector_status_disconnected;
intel_display_power_put(dev_priv, POWER_DOMAIN_GMBUS);
return status;
}
static void
intel_hdmi_force(struct drm_connector *connector)
{
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
DRM_DEBUG_KMS("[CONNECTOR:%d:%s]\n",
connector->base.id, connector->name);
intel_hdmi_unset_edid(connector);
if (connector->status != connector_status_connected)
return;
intel_hdmi_set_edid(connector, true);
hdmi_to_dig_port(intel_hdmi)->base.type = INTEL_OUTPUT_HDMI;
}
static int intel_hdmi_get_modes(struct drm_connector *connector)
{
struct edid *edid;
edid = to_intel_connector(connector)->detect_edid;
if (edid == NULL)
return 0;
return intel_connector_update_modes(connector, edid);
}
static bool
intel_hdmi_detect_audio(struct drm_connector *connector)
{
bool has_audio = false;
struct edid *edid;
edid = to_intel_connector(connector)->detect_edid;
if (edid && edid->input & DRM_EDID_INPUT_DIGITAL)
has_audio = drm_detect_monitor_audio(edid);
return has_audio;
}
static int
intel_hdmi_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
struct intel_digital_port *intel_dig_port =
hdmi_to_dig_port(intel_hdmi);
struct drm_i915_private *dev_priv = connector->dev->dev_private;
int ret;
ret = drm_object_property_set_value(&connector->base, property, val);
if (ret)
return ret;
if (property == dev_priv->force_audio_property) {
enum hdmi_force_audio i = val;
bool has_audio;
if (i == intel_hdmi->force_audio)
return 0;
intel_hdmi->force_audio = i;
if (i == HDMI_AUDIO_AUTO)
has_audio = intel_hdmi_detect_audio(connector);
else
has_audio = (i == HDMI_AUDIO_ON);
if (i == HDMI_AUDIO_OFF_DVI)
intel_hdmi->has_hdmi_sink = 0;
intel_hdmi->has_audio = has_audio;
goto done;
}
if (property == dev_priv->broadcast_rgb_property) {
bool old_auto = intel_hdmi->color_range_auto;
bool old_range = intel_hdmi->limited_color_range;
switch (val) {
case INTEL_BROADCAST_RGB_AUTO:
intel_hdmi->color_range_auto = true;
break;
case INTEL_BROADCAST_RGB_FULL:
intel_hdmi->color_range_auto = false;
intel_hdmi->limited_color_range = false;
break;
case INTEL_BROADCAST_RGB_LIMITED:
intel_hdmi->color_range_auto = false;
intel_hdmi->limited_color_range = true;
break;
default:
return -EINVAL;
}
if (old_auto == intel_hdmi->color_range_auto &&
old_range == intel_hdmi->limited_color_range)
return 0;
goto done;
}
if (property == connector->dev->mode_config.aspect_ratio_property) {
switch (val) {
case DRM_MODE_PICTURE_ASPECT_NONE:
intel_hdmi->aspect_ratio = HDMI_PICTURE_ASPECT_NONE;
break;
case DRM_MODE_PICTURE_ASPECT_4_3:
intel_hdmi->aspect_ratio = HDMI_PICTURE_ASPECT_4_3;
break;
case DRM_MODE_PICTURE_ASPECT_16_9:
intel_hdmi->aspect_ratio = HDMI_PICTURE_ASPECT_16_9;
break;
default:
return -EINVAL;
}
goto done;
}
return -EINVAL;
done:
if (intel_dig_port->base.base.crtc)
intel_crtc_restore_mode(intel_dig_port->base.base.crtc);
return 0;
}
static void intel_hdmi_pre_enable(struct intel_encoder *encoder)
{
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(&encoder->base);
struct intel_crtc *intel_crtc = to_intel_crtc(encoder->base.crtc);
const struct drm_display_mode *adjusted_mode = &intel_crtc->config->base.adjusted_mode;
intel_hdmi_prepare(encoder);
intel_hdmi->set_infoframes(&encoder->base,
intel_crtc->config->has_hdmi_sink,
adjusted_mode);
}
static void vlv_hdmi_pre_enable(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct intel_hdmi *intel_hdmi = &dport->hdmi;
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
const struct drm_display_mode *adjusted_mode = &intel_crtc->config->base.adjusted_mode;
enum dpio_channel port = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
u32 val;
mutex_lock(&dev_priv->sb_lock);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW8(port));
val = 0;
if (pipe)
val |= (1<<21);
else
val &= ~(1<<21);
val |= 0x001000c4;
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW8(port), val);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW5(port), 0);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW4(port), 0x2b245f5f);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW2(port), 0x5578b83a);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW3(port), 0x0c782040);
vlv_dpio_write(dev_priv, pipe, VLV_TX3_DW4(port), 0x2b247878);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW11(port), 0x00030000);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW9(port), 0x00002000);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW5(port), DPIO_TX_OCALINIT_EN);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW14(port), 0x00760018);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW23(port), 0x00400888);
mutex_unlock(&dev_priv->sb_lock);
intel_hdmi->set_infoframes(&encoder->base,
intel_crtc->config->has_hdmi_sink,
adjusted_mode);
g4x_enable_hdmi(encoder);
vlv_wait_port_ready(dev_priv, dport, 0x0);
}
static void vlv_hdmi_pre_pll_enable(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
enum dpio_channel port = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
intel_hdmi_prepare(encoder);
mutex_lock(&dev_priv->sb_lock);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW0(port),
DPIO_PCS_TX_LANE2_RESET |
DPIO_PCS_TX_LANE1_RESET);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW1(port),
DPIO_PCS_CLK_CRI_RXEB_EIOS_EN |
DPIO_PCS_CLK_CRI_RXDIGFILTSG_EN |
(1<<DPIO_PCS_CLK_DATAWIDTH_SHIFT) |
DPIO_PCS_CLK_SOFT_RESET);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW12(port), 0x00750f00);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW11(port), 0x00001500);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW14(port), 0x40400000);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW9(port), 0x00002000);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW5(port), DPIO_TX_OCALINIT_EN);
mutex_unlock(&dev_priv->sb_lock);
}
static void chv_data_lane_soft_reset(struct intel_encoder *encoder,
bool reset)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
enum dpio_channel ch = vlv_dport_to_channel(enc_to_dig_port(&encoder->base));
struct intel_crtc *crtc = to_intel_crtc(encoder->base.crtc);
enum pipe pipe = crtc->pipe;
uint32_t val;
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW0(ch));
if (reset)
val &= ~(DPIO_PCS_TX_LANE2_RESET | DPIO_PCS_TX_LANE1_RESET);
else
val |= DPIO_PCS_TX_LANE2_RESET | DPIO_PCS_TX_LANE1_RESET;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW0(ch), val);
if (crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW0(ch));
if (reset)
val &= ~(DPIO_PCS_TX_LANE2_RESET | DPIO_PCS_TX_LANE1_RESET);
else
val |= DPIO_PCS_TX_LANE2_RESET | DPIO_PCS_TX_LANE1_RESET;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW0(ch), val);
}
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW1(ch));
val |= CHV_PCS_REQ_SOFTRESET_EN;
if (reset)
val &= ~DPIO_PCS_CLK_SOFT_RESET;
else
val |= DPIO_PCS_CLK_SOFT_RESET;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW1(ch), val);
if (crtc->config->lane_count > 2) {
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW1(ch));
val |= CHV_PCS_REQ_SOFTRESET_EN;
if (reset)
val &= ~DPIO_PCS_CLK_SOFT_RESET;
else
val |= DPIO_PCS_CLK_SOFT_RESET;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW1(ch), val);
}
}
static void chv_hdmi_pre_pll_enable(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
enum dpio_channel ch = vlv_dport_to_channel(dport);
enum pipe pipe = intel_crtc->pipe;
u32 val;
intel_hdmi_prepare(encoder);
if (ch == DPIO_CH0 && pipe == PIPE_B)
dport->release_cl2_override =
!chv_phy_powergate_ch(dev_priv, DPIO_PHY0, DPIO_CH1, true);
chv_phy_powergate_lanes(encoder, true, 0x0);
mutex_lock(&dev_priv->sb_lock);
chv_data_lane_soft_reset(encoder, true);
if (pipe != PIPE_B) {
val = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW5_CH0);
val &= ~(CHV_BUFLEFTENA1_MASK | CHV_BUFRIGHTENA1_MASK);
if (ch == DPIO_CH0)
val |= CHV_BUFLEFTENA1_FORCE;
if (ch == DPIO_CH1)
val |= CHV_BUFRIGHTENA1_FORCE;
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW5_CH0, val);
} else {
val = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW1_CH1);
val &= ~(CHV_BUFLEFTENA2_MASK | CHV_BUFRIGHTENA2_MASK);
if (ch == DPIO_CH0)
val |= CHV_BUFLEFTENA2_FORCE;
if (ch == DPIO_CH1)
val |= CHV_BUFRIGHTENA2_FORCE;
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW1_CH1, val);
}
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW8(ch));
val |= CHV_PCS_USEDCLKCHANNEL_OVRRIDE;
if (pipe != PIPE_B)
val &= ~CHV_PCS_USEDCLKCHANNEL;
else
val |= CHV_PCS_USEDCLKCHANNEL;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW8(ch), val);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW8(ch));
val |= CHV_PCS_USEDCLKCHANNEL_OVRRIDE;
if (pipe != PIPE_B)
val &= ~CHV_PCS_USEDCLKCHANNEL;
else
val |= CHV_PCS_USEDCLKCHANNEL;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW8(ch), val);
val = vlv_dpio_read(dev_priv, pipe, CHV_CMN_DW19(ch));
if (pipe != PIPE_B)
val &= ~CHV_CMN_USEDCLKCHANNEL;
else
val |= CHV_CMN_USEDCLKCHANNEL;
vlv_dpio_write(dev_priv, pipe, CHV_CMN_DW19(ch), val);
mutex_unlock(&dev_priv->sb_lock);
}
static void chv_hdmi_post_pll_disable(struct intel_encoder *encoder)
{
struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);
enum pipe pipe = to_intel_crtc(encoder->base.crtc)->pipe;
u32 val;
mutex_lock(&dev_priv->sb_lock);
if (pipe != PIPE_B) {
val = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW5_CH0);
val &= ~(CHV_BUFLEFTENA1_MASK | CHV_BUFRIGHTENA1_MASK);
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW5_CH0, val);
} else {
val = vlv_dpio_read(dev_priv, pipe, _CHV_CMN_DW1_CH1);
val &= ~(CHV_BUFLEFTENA2_MASK | CHV_BUFRIGHTENA2_MASK);
vlv_dpio_write(dev_priv, pipe, _CHV_CMN_DW1_CH1, val);
}
mutex_unlock(&dev_priv->sb_lock);
chv_phy_powergate_lanes(encoder, false, 0x0);
}
static void vlv_hdmi_post_disable(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct drm_i915_private *dev_priv = encoder->base.dev->dev_private;
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
enum dpio_channel port = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
mutex_lock(&dev_priv->sb_lock);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW0(port), 0x00000000);
vlv_dpio_write(dev_priv, pipe, VLV_PCS_DW1(port), 0x00e00060);
mutex_unlock(&dev_priv->sb_lock);
}
static void chv_hdmi_post_disable(struct intel_encoder *encoder)
{
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev_priv->sb_lock);
chv_data_lane_soft_reset(encoder, true);
mutex_unlock(&dev_priv->sb_lock);
}
static void chv_hdmi_pre_enable(struct intel_encoder *encoder)
{
struct intel_digital_port *dport = enc_to_dig_port(&encoder->base);
struct intel_hdmi *intel_hdmi = &dport->hdmi;
struct drm_device *dev = encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc =
to_intel_crtc(encoder->base.crtc);
const struct drm_display_mode *adjusted_mode = &intel_crtc->config->base.adjusted_mode;
enum dpio_channel ch = vlv_dport_to_channel(dport);
int pipe = intel_crtc->pipe;
int data, i, stagger;
u32 val;
mutex_lock(&dev_priv->sb_lock);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW11(ch));
val &= ~DPIO_LANEDESKEW_STRAP_OVRD;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW11(ch), val);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW11(ch));
val &= ~DPIO_LANEDESKEW_STRAP_OVRD;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW11(ch), val);
for (i = 0; i < 4; i++) {
data = (i == 1) ? 0x0 : 0x1;
vlv_dpio_write(dev_priv, pipe, CHV_TX_DW14(ch, i),
data << DPIO_UPAR_SHIFT);
}
if (intel_crtc->config->port_clock > 270000)
stagger = 0x18;
else if (intel_crtc->config->port_clock > 135000)
stagger = 0xd;
else if (intel_crtc->config->port_clock > 67500)
stagger = 0x7;
else if (intel_crtc->config->port_clock > 33750)
stagger = 0x4;
else
stagger = 0x2;
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW11(ch));
val |= DPIO_TX2_STAGGER_MASK(0x1f);
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW11(ch), val);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW11(ch));
val |= DPIO_TX2_STAGGER_MASK(0x1f);
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW11(ch), val);
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW12(ch),
DPIO_LANESTAGGER_STRAP(stagger) |
DPIO_LANESTAGGER_STRAP_OVRD |
DPIO_TX1_STAGGER_MASK(0x1f) |
DPIO_TX1_STAGGER_MULT(6) |
DPIO_TX2_STAGGER_MULT(0));
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW12(ch),
DPIO_LANESTAGGER_STRAP(stagger) |
DPIO_LANESTAGGER_STRAP_OVRD |
DPIO_TX1_STAGGER_MASK(0x1f) |
DPIO_TX1_STAGGER_MULT(7) |
DPIO_TX2_STAGGER_MULT(5));
chv_data_lane_soft_reset(encoder, false);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW10(ch));
val &= ~(DPIO_PCS_SWING_CALC_TX0_TX2 | DPIO_PCS_SWING_CALC_TX1_TX3);
val &= ~(DPIO_PCS_TX1DEEMP_MASK | DPIO_PCS_TX2DEEMP_MASK);
val |= DPIO_PCS_TX1DEEMP_9P5 | DPIO_PCS_TX2DEEMP_9P5;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW10(ch), val);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW10(ch));
val &= ~(DPIO_PCS_SWING_CALC_TX0_TX2 | DPIO_PCS_SWING_CALC_TX1_TX3);
val &= ~(DPIO_PCS_TX1DEEMP_MASK | DPIO_PCS_TX2DEEMP_MASK);
val |= DPIO_PCS_TX1DEEMP_9P5 | DPIO_PCS_TX2DEEMP_9P5;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW10(ch), val);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW9(ch));
val &= ~(DPIO_PCS_TX1MARGIN_MASK | DPIO_PCS_TX2MARGIN_MASK);
val |= DPIO_PCS_TX1MARGIN_000 | DPIO_PCS_TX2MARGIN_000;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW9(ch), val);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW9(ch));
val &= ~(DPIO_PCS_TX1MARGIN_MASK | DPIO_PCS_TX2MARGIN_MASK);
val |= DPIO_PCS_TX1MARGIN_000 | DPIO_PCS_TX2MARGIN_000;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW9(ch), val);
for (i = 0; i < 4; i++) {
val = vlv_dpio_read(dev_priv, pipe, CHV_TX_DW4(ch, i));
val &= ~DPIO_SWING_DEEMPH9P5_MASK;
val |= 128 << DPIO_SWING_DEEMPH9P5_SHIFT;
vlv_dpio_write(dev_priv, pipe, CHV_TX_DW4(ch, i), val);
}
for (i = 0; i < 4; i++) {
val = vlv_dpio_read(dev_priv, pipe, CHV_TX_DW2(ch, i));
val &= ~DPIO_SWING_MARGIN000_MASK;
val |= 102 << DPIO_SWING_MARGIN000_SHIFT;
val &= ~(0xff << DPIO_UNIQ_TRANS_SCALE_SHIFT);
val |= 0x9a << DPIO_UNIQ_TRANS_SCALE_SHIFT;
vlv_dpio_write(dev_priv, pipe, CHV_TX_DW2(ch, i), val);
}
for (i = 0; i < 4; i++) {
val = vlv_dpio_read(dev_priv, pipe, CHV_TX_DW3(ch, i));
val &= ~DPIO_TX_UNIQ_TRANS_SCALE_EN;
vlv_dpio_write(dev_priv, pipe, CHV_TX_DW3(ch, i), val);
}
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS01_DW10(ch));
val |= DPIO_PCS_SWING_CALC_TX0_TX2 | DPIO_PCS_SWING_CALC_TX1_TX3;
vlv_dpio_write(dev_priv, pipe, VLV_PCS01_DW10(ch), val);
val = vlv_dpio_read(dev_priv, pipe, VLV_PCS23_DW10(ch));
val |= DPIO_PCS_SWING_CALC_TX0_TX2 | DPIO_PCS_SWING_CALC_TX1_TX3;
vlv_dpio_write(dev_priv, pipe, VLV_PCS23_DW10(ch), val);
mutex_unlock(&dev_priv->sb_lock);
intel_hdmi->set_infoframes(&encoder->base,
intel_crtc->config->has_hdmi_sink,
adjusted_mode);
g4x_enable_hdmi(encoder);
vlv_wait_port_ready(dev_priv, dport, 0x0);
if (dport->release_cl2_override) {
chv_phy_powergate_ch(dev_priv, DPIO_PHY0, DPIO_CH1, false);
dport->release_cl2_override = false;
}
}
static void intel_hdmi_destroy(struct drm_connector *connector)
{
kfree(to_intel_connector(connector)->detect_edid);
drm_connector_cleanup(connector);
kfree(connector);
}
static void
intel_hdmi_add_properties(struct intel_hdmi *intel_hdmi, struct drm_connector *connector)
{
intel_attach_force_audio_property(connector);
intel_attach_broadcast_rgb_property(connector);
intel_hdmi->color_range_auto = true;
intel_attach_aspect_ratio_property(connector);
intel_hdmi->aspect_ratio = HDMI_PICTURE_ASPECT_NONE;
}
void intel_hdmi_init_connector(struct intel_digital_port *intel_dig_port,
struct intel_connector *intel_connector)
{
struct drm_connector *connector = &intel_connector->base;
struct intel_hdmi *intel_hdmi = &intel_dig_port->hdmi;
struct intel_encoder *intel_encoder = &intel_dig_port->base;
struct drm_device *dev = intel_encoder->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum port port = intel_dig_port->port;
uint8_t alternate_ddc_pin;
DRM_DEBUG_KMS("Adding HDMI connector on port %c\n",
port_name(port));
if (WARN(intel_dig_port->max_lanes < 4,
"Not enough lanes (%d) for HDMI on port %c\n",
intel_dig_port->max_lanes, port_name(port)))
return;
drm_connector_init(dev, connector, &intel_hdmi_connector_funcs,
DRM_MODE_CONNECTOR_HDMIA);
drm_connector_helper_add(connector, &intel_hdmi_connector_helper_funcs);
connector->interlace_allowed = 1;
connector->doublescan_allowed = 0;
connector->stereo_allowed = 1;
switch (port) {
case PORT_B:
if (IS_BROXTON(dev_priv))
intel_hdmi->ddc_bus = GMBUS_PIN_1_BXT;
else
intel_hdmi->ddc_bus = GMBUS_PIN_DPB;
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
intel_encoder->hpd_pin = HPD_PORT_A;
else
intel_encoder->hpd_pin = HPD_PORT_B;
break;
case PORT_C:
if (IS_BROXTON(dev_priv))
intel_hdmi->ddc_bus = GMBUS_PIN_2_BXT;
else
intel_hdmi->ddc_bus = GMBUS_PIN_DPC;
intel_encoder->hpd_pin = HPD_PORT_C;
break;
case PORT_D:
if (WARN_ON(IS_BROXTON(dev_priv)))
intel_hdmi->ddc_bus = GMBUS_PIN_DISABLED;
else if (IS_CHERRYVIEW(dev_priv))
intel_hdmi->ddc_bus = GMBUS_PIN_DPD_CHV;
else
intel_hdmi->ddc_bus = GMBUS_PIN_DPD;
intel_encoder->hpd_pin = HPD_PORT_D;
break;
case PORT_E:
alternate_ddc_pin =
dev_priv->vbt.ddi_port_info[PORT_E].alternate_ddc_pin;
switch (alternate_ddc_pin) {
case DDC_PIN_B:
intel_hdmi->ddc_bus = GMBUS_PIN_DPB;
break;
case DDC_PIN_C:
intel_hdmi->ddc_bus = GMBUS_PIN_DPC;
break;
case DDC_PIN_D:
intel_hdmi->ddc_bus = GMBUS_PIN_DPD;
break;
default:
MISSING_CASE(alternate_ddc_pin);
}
intel_encoder->hpd_pin = HPD_PORT_E;
break;
case PORT_A:
intel_encoder->hpd_pin = HPD_PORT_A;
default:
BUG();
}
if (IS_VALLEYVIEW(dev) || IS_CHERRYVIEW(dev)) {
intel_hdmi->write_infoframe = vlv_write_infoframe;
intel_hdmi->set_infoframes = vlv_set_infoframes;
intel_hdmi->infoframe_enabled = vlv_infoframe_enabled;
} else if (IS_G4X(dev)) {
intel_hdmi->write_infoframe = g4x_write_infoframe;
intel_hdmi->set_infoframes = g4x_set_infoframes;
intel_hdmi->infoframe_enabled = g4x_infoframe_enabled;
} else if (HAS_DDI(dev)) {
intel_hdmi->write_infoframe = hsw_write_infoframe;
intel_hdmi->set_infoframes = hsw_set_infoframes;
intel_hdmi->infoframe_enabled = hsw_infoframe_enabled;
} else if (HAS_PCH_IBX(dev)) {
intel_hdmi->write_infoframe = ibx_write_infoframe;
intel_hdmi->set_infoframes = ibx_set_infoframes;
intel_hdmi->infoframe_enabled = ibx_infoframe_enabled;
} else {
intel_hdmi->write_infoframe = cpt_write_infoframe;
intel_hdmi->set_infoframes = cpt_set_infoframes;
intel_hdmi->infoframe_enabled = cpt_infoframe_enabled;
}
if (HAS_DDI(dev))
intel_connector->get_hw_state = intel_ddi_connector_get_hw_state;
else
intel_connector->get_hw_state = intel_connector_get_hw_state;
intel_connector->unregister = intel_connector_unregister;
intel_hdmi_add_properties(intel_hdmi, connector);
intel_connector_attach_encoder(intel_connector, intel_encoder);
drm_connector_register(connector);
intel_hdmi->attached_connector = intel_connector;
if (IS_G4X(dev) && !IS_GM45(dev)) {
u32 temp = I915_READ(PEG_BAND_GAP_DATA);
I915_WRITE(PEG_BAND_GAP_DATA, (temp & ~0xf) | 0xd);
}
}
void intel_hdmi_init(struct drm_device *dev,
i915_reg_t hdmi_reg, enum port port)
{
struct intel_digital_port *intel_dig_port;
struct intel_encoder *intel_encoder;
struct intel_connector *intel_connector;
intel_dig_port = kzalloc(sizeof(*intel_dig_port), GFP_KERNEL);
if (!intel_dig_port)
return;
intel_connector = intel_connector_alloc();
if (!intel_connector) {
kfree(intel_dig_port);
return;
}
intel_encoder = &intel_dig_port->base;
drm_encoder_init(dev, &intel_encoder->base, &intel_hdmi_enc_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
intel_encoder->compute_config = intel_hdmi_compute_config;
if (HAS_PCH_SPLIT(dev)) {
intel_encoder->disable = pch_disable_hdmi;
intel_encoder->post_disable = pch_post_disable_hdmi;
} else {
intel_encoder->disable = g4x_disable_hdmi;
}
intel_encoder->get_hw_state = intel_hdmi_get_hw_state;
intel_encoder->get_config = intel_hdmi_get_config;
if (IS_CHERRYVIEW(dev)) {
intel_encoder->pre_pll_enable = chv_hdmi_pre_pll_enable;
intel_encoder->pre_enable = chv_hdmi_pre_enable;
intel_encoder->enable = vlv_enable_hdmi;
intel_encoder->post_disable = chv_hdmi_post_disable;
intel_encoder->post_pll_disable = chv_hdmi_post_pll_disable;
} else if (IS_VALLEYVIEW(dev)) {
intel_encoder->pre_pll_enable = vlv_hdmi_pre_pll_enable;
intel_encoder->pre_enable = vlv_hdmi_pre_enable;
intel_encoder->enable = vlv_enable_hdmi;
intel_encoder->post_disable = vlv_hdmi_post_disable;
} else {
intel_encoder->pre_enable = intel_hdmi_pre_enable;
if (HAS_PCH_CPT(dev))
intel_encoder->enable = cpt_enable_hdmi;
else if (HAS_PCH_IBX(dev))
intel_encoder->enable = ibx_enable_hdmi;
else
intel_encoder->enable = g4x_enable_hdmi;
}
intel_encoder->type = INTEL_OUTPUT_HDMI;
if (IS_CHERRYVIEW(dev)) {
if (port == PORT_D)
intel_encoder->crtc_mask = 1 << 2;
else
intel_encoder->crtc_mask = (1 << 0) | (1 << 1);
} else {
intel_encoder->crtc_mask = (1 << 0) | (1 << 1) | (1 << 2);
}
intel_encoder->cloneable = 1 << INTEL_OUTPUT_ANALOG;
if (IS_G4X(dev))
intel_encoder->cloneable |= 1 << INTEL_OUTPUT_HDMI;
intel_dig_port->port = port;
intel_dig_port->hdmi.hdmi_reg = hdmi_reg;
intel_dig_port->dp.output_reg = INVALID_MMIO_REG;
intel_dig_port->max_lanes = 4;
intel_hdmi_init_connector(intel_dig_port, intel_connector);
}
