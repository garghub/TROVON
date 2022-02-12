static struct intel_hdmi *enc_to_intel_hdmi(struct drm_encoder *encoder)
{
return container_of(encoder, struct intel_hdmi, base.base);
}
static struct intel_hdmi *intel_attached_hdmi(struct drm_connector *connector)
{
return container_of(intel_attached_encoder(connector),
struct intel_hdmi, base);
}
void intel_dip_infoframe_csum(struct dip_infoframe *avi_if)
{
uint8_t *data = (uint8_t *)avi_if;
uint8_t sum = 0;
unsigned i;
avi_if->checksum = 0;
avi_if->ecc = 0;
for (i = 0; i < sizeof(*avi_if); i++)
sum += data[i];
avi_if->checksum = 0x100 - sum;
}
static void intel_hdmi_set_avi_infoframe(struct drm_encoder *encoder)
{
struct dip_infoframe avi_if = {
.type = DIP_TYPE_AVI,
.ver = DIP_VERSION_AVI,
.len = DIP_LEN_AVI,
};
uint32_t *data = (uint32_t *)&avi_if;
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
u32 port;
unsigned i;
if (!intel_hdmi->has_hdmi_sink)
return;
if (intel_hdmi->sdvox_reg == SDVOB)
port = VIDEO_DIP_PORT_B;
else if (intel_hdmi->sdvox_reg == SDVOC)
port = VIDEO_DIP_PORT_C;
else
return;
I915_WRITE(VIDEO_DIP_CTL, VIDEO_DIP_ENABLE | port |
VIDEO_DIP_SELECT_AVI | VIDEO_DIP_FREQ_VSYNC);
intel_dip_infoframe_csum(&avi_if);
for (i = 0; i < sizeof(avi_if); i += 4) {
I915_WRITE(VIDEO_DIP_DATA, *data);
data++;
}
I915_WRITE(VIDEO_DIP_CTL, VIDEO_DIP_ENABLE | port |
VIDEO_DIP_SELECT_AVI | VIDEO_DIP_FREQ_VSYNC |
VIDEO_DIP_ENABLE_AVI);
}
static void intel_hdmi_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = encoder->crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
u32 sdvox;
sdvox = SDVO_ENCODING_HDMI | SDVO_BORDER_ENABLE;
sdvox |= intel_hdmi->color_range;
if (adjusted_mode->flags & DRM_MODE_FLAG_PVSYNC)
sdvox |= SDVO_VSYNC_ACTIVE_HIGH;
if (adjusted_mode->flags & DRM_MODE_FLAG_PHSYNC)
sdvox |= SDVO_HSYNC_ACTIVE_HIGH;
if (intel_hdmi->has_hdmi_sink && HAS_PCH_CPT(dev))
sdvox |= HDMI_MODE_SELECT;
if (intel_hdmi->has_audio) {
sdvox |= SDVO_AUDIO_ENABLE;
sdvox |= SDVO_NULL_PACKETS_DURING_VSYNC;
}
if (intel_crtc->pipe == 1) {
if (HAS_PCH_CPT(dev))
sdvox |= PORT_TRANS_B_SEL_CPT;
else
sdvox |= SDVO_PIPE_B_SELECT;
}
I915_WRITE(intel_hdmi->sdvox_reg, sdvox);
POSTING_READ(intel_hdmi->sdvox_reg);
intel_hdmi_set_avi_infoframe(encoder);
}
static void intel_hdmi_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_hdmi *intel_hdmi = enc_to_intel_hdmi(encoder);
u32 temp;
temp = I915_READ(intel_hdmi->sdvox_reg);
if (HAS_PCH_SPLIT(dev)) {
I915_WRITE(intel_hdmi->sdvox_reg, temp & ~SDVO_ENABLE);
POSTING_READ(intel_hdmi->sdvox_reg);
}
if (mode != DRM_MODE_DPMS_ON) {
temp &= ~SDVO_ENABLE;
} else {
temp |= SDVO_ENABLE;
}
I915_WRITE(intel_hdmi->sdvox_reg, temp);
POSTING_READ(intel_hdmi->sdvox_reg);
if (HAS_PCH_SPLIT(dev)) {
I915_WRITE(intel_hdmi->sdvox_reg, temp);
POSTING_READ(intel_hdmi->sdvox_reg);
}
}
static int intel_hdmi_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
if (mode->clock > 165000)
return MODE_CLOCK_HIGH;
if (mode->clock < 20000)
return MODE_CLOCK_LOW;
if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
return MODE_NO_DBLESCAN;
return MODE_OK;
}
static bool intel_hdmi_mode_fixup(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static enum drm_connector_status
intel_hdmi_detect(struct drm_connector *connector, bool force)
{
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
struct drm_i915_private *dev_priv = connector->dev->dev_private;
struct edid *edid;
enum drm_connector_status status = connector_status_disconnected;
intel_hdmi->has_hdmi_sink = false;
intel_hdmi->has_audio = false;
edid = drm_get_edid(connector,
&dev_priv->gmbus[intel_hdmi->ddc_bus].adapter);
if (edid) {
if (edid->input & DRM_EDID_INPUT_DIGITAL) {
status = connector_status_connected;
intel_hdmi->has_hdmi_sink = drm_detect_hdmi_monitor(edid);
intel_hdmi->has_audio = drm_detect_monitor_audio(edid);
}
connector->display_info.raw_edid = NULL;
kfree(edid);
}
if (status == connector_status_connected) {
if (intel_hdmi->force_audio)
intel_hdmi->has_audio = intel_hdmi->force_audio > 0;
}
return status;
}
static int intel_hdmi_get_modes(struct drm_connector *connector)
{
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
struct drm_i915_private *dev_priv = connector->dev->dev_private;
return intel_ddc_get_modes(connector,
&dev_priv->gmbus[intel_hdmi->ddc_bus].adapter);
}
static bool
intel_hdmi_detect_audio(struct drm_connector *connector)
{
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
struct drm_i915_private *dev_priv = connector->dev->dev_private;
struct edid *edid;
bool has_audio = false;
edid = drm_get_edid(connector,
&dev_priv->gmbus[intel_hdmi->ddc_bus].adapter);
if (edid) {
if (edid->input & DRM_EDID_INPUT_DIGITAL)
has_audio = drm_detect_monitor_audio(edid);
connector->display_info.raw_edid = NULL;
kfree(edid);
}
return has_audio;
}
static int
intel_hdmi_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
struct intel_hdmi *intel_hdmi = intel_attached_hdmi(connector);
struct drm_i915_private *dev_priv = connector->dev->dev_private;
int ret;
ret = drm_connector_property_set_value(connector, property, val);
if (ret)
return ret;
if (property == dev_priv->force_audio_property) {
int i = val;
bool has_audio;
if (i == intel_hdmi->force_audio)
return 0;
intel_hdmi->force_audio = i;
if (i == 0)
has_audio = intel_hdmi_detect_audio(connector);
else
has_audio = i > 0;
if (has_audio == intel_hdmi->has_audio)
return 0;
intel_hdmi->has_audio = has_audio;
goto done;
}
if (property == dev_priv->broadcast_rgb_property) {
if (val == !!intel_hdmi->color_range)
return 0;
intel_hdmi->color_range = val ? SDVO_COLOR_RANGE_16_235 : 0;
goto done;
}
return -EINVAL;
done:
if (intel_hdmi->base.base.crtc) {
struct drm_crtc *crtc = intel_hdmi->base.base.crtc;
drm_crtc_helper_set_mode(crtc, &crtc->mode,
crtc->x, crtc->y,
crtc->fb);
}
return 0;
}
static void intel_hdmi_destroy(struct drm_connector *connector)
{
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
static void
intel_hdmi_add_properties(struct intel_hdmi *intel_hdmi, struct drm_connector *connector)
{
intel_attach_force_audio_property(connector);
intel_attach_broadcast_rgb_property(connector);
}
void intel_hdmi_init(struct drm_device *dev, int sdvox_reg)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_connector *connector;
struct intel_encoder *intel_encoder;
struct intel_connector *intel_connector;
struct intel_hdmi *intel_hdmi;
intel_hdmi = kzalloc(sizeof(struct intel_hdmi), GFP_KERNEL);
if (!intel_hdmi)
return;
intel_connector = kzalloc(sizeof(struct intel_connector), GFP_KERNEL);
if (!intel_connector) {
kfree(intel_hdmi);
return;
}
intel_encoder = &intel_hdmi->base;
drm_encoder_init(dev, &intel_encoder->base, &intel_hdmi_enc_funcs,
DRM_MODE_ENCODER_TMDS);
connector = &intel_connector->base;
drm_connector_init(dev, connector, &intel_hdmi_connector_funcs,
DRM_MODE_CONNECTOR_HDMIA);
drm_connector_helper_add(connector, &intel_hdmi_connector_helper_funcs);
intel_encoder->type = INTEL_OUTPUT_HDMI;
connector->polled = DRM_CONNECTOR_POLL_HPD;
connector->interlace_allowed = 0;
connector->doublescan_allowed = 0;
intel_encoder->crtc_mask = (1 << 0) | (1 << 1);
if (sdvox_reg == SDVOB) {
intel_encoder->clone_mask = (1 << INTEL_HDMIB_CLONE_BIT);
intel_hdmi->ddc_bus = GMBUS_PORT_DPB;
dev_priv->hotplug_supported_mask |= HDMIB_HOTPLUG_INT_STATUS;
} else if (sdvox_reg == SDVOC) {
intel_encoder->clone_mask = (1 << INTEL_HDMIC_CLONE_BIT);
intel_hdmi->ddc_bus = GMBUS_PORT_DPC;
dev_priv->hotplug_supported_mask |= HDMIC_HOTPLUG_INT_STATUS;
} else if (sdvox_reg == HDMIB) {
intel_encoder->clone_mask = (1 << INTEL_HDMID_CLONE_BIT);
intel_hdmi->ddc_bus = GMBUS_PORT_DPB;
dev_priv->hotplug_supported_mask |= HDMIB_HOTPLUG_INT_STATUS;
} else if (sdvox_reg == HDMIC) {
intel_encoder->clone_mask = (1 << INTEL_HDMIE_CLONE_BIT);
intel_hdmi->ddc_bus = GMBUS_PORT_DPC;
dev_priv->hotplug_supported_mask |= HDMIC_HOTPLUG_INT_STATUS;
} else if (sdvox_reg == HDMID) {
intel_encoder->clone_mask = (1 << INTEL_HDMIF_CLONE_BIT);
intel_hdmi->ddc_bus = GMBUS_PORT_DPD;
dev_priv->hotplug_supported_mask |= HDMID_HOTPLUG_INT_STATUS;
}
intel_hdmi->sdvox_reg = sdvox_reg;
drm_encoder_helper_add(&intel_encoder->base, &intel_hdmi_helper_funcs);
intel_hdmi_add_properties(intel_hdmi, connector);
intel_connector_attach_encoder(intel_connector, intel_encoder);
drm_sysfs_connector_add(connector);
if (IS_G4X(dev) && !IS_GM45(dev)) {
u32 temp = I915_READ(PEG_BAND_GAP_DATA);
I915_WRITE(PEG_BAND_GAP_DATA, (temp & ~0xf) | 0xd);
}
}
