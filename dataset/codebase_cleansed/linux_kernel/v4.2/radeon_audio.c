static u32 radeon_audio_rreg(struct radeon_device *rdev, u32 offset, u32 reg)
{
return RREG32(reg);
}
static void radeon_audio_wreg(struct radeon_device *rdev, u32 offset,
u32 reg, u32 v)
{
WREG32(reg, v);
}
static void radeon_audio_enable(struct radeon_device *rdev,
struct r600_audio_pin *pin, u8 enable_mask)
{
struct drm_encoder *encoder;
struct radeon_encoder *radeon_encoder;
struct radeon_encoder_atom_dig *dig;
int pin_count = 0;
if (!pin)
return;
if (rdev->mode_info.mode_config_initialized) {
list_for_each_entry(encoder, &rdev->ddev->mode_config.encoder_list, head) {
if (radeon_encoder_is_digital(encoder)) {
radeon_encoder = to_radeon_encoder(encoder);
dig = radeon_encoder->enc_priv;
if (dig->pin == pin)
pin_count++;
}
}
if ((pin_count > 1) && (enable_mask == 0))
return;
}
if (rdev->audio.funcs->enable)
rdev->audio.funcs->enable(rdev, pin, enable_mask);
}
static void radeon_audio_interface_init(struct radeon_device *rdev)
{
if (ASIC_IS_DCE6(rdev)) {
rdev->audio.funcs = &dce6_funcs;
rdev->audio.hdmi_funcs = &dce6_hdmi_funcs;
rdev->audio.dp_funcs = &dce6_dp_funcs;
} else if (ASIC_IS_DCE4(rdev)) {
rdev->audio.funcs = &dce4_funcs;
rdev->audio.hdmi_funcs = &dce4_hdmi_funcs;
rdev->audio.dp_funcs = &dce4_dp_funcs;
} else if (ASIC_IS_DCE32(rdev)) {
rdev->audio.funcs = &dce32_funcs;
rdev->audio.hdmi_funcs = &dce32_hdmi_funcs;
rdev->audio.dp_funcs = &dce32_dp_funcs;
} else {
rdev->audio.funcs = &r600_funcs;
rdev->audio.hdmi_funcs = &r600_hdmi_funcs;
rdev->audio.dp_funcs = 0;
}
}
static int radeon_audio_chipset_supported(struct radeon_device *rdev)
{
return ASIC_IS_DCE2(rdev) && !ASIC_IS_NODCE(rdev);
}
int radeon_audio_init(struct radeon_device *rdev)
{
int i;
if (!radeon_audio || !radeon_audio_chipset_supported(rdev))
return 0;
rdev->audio.enabled = true;
if (ASIC_IS_DCE83(rdev))
rdev->audio.num_pins = 3;
else if (ASIC_IS_DCE81(rdev))
rdev->audio.num_pins = 7;
else if (ASIC_IS_DCE8(rdev))
rdev->audio.num_pins = 7;
else if (ASIC_IS_DCE64(rdev))
rdev->audio.num_pins = 2;
else if (ASIC_IS_DCE61(rdev))
rdev->audio.num_pins = 6;
else if (ASIC_IS_DCE6(rdev))
rdev->audio.num_pins = 6;
else
rdev->audio.num_pins = 1;
for (i = 0; i < rdev->audio.num_pins; i++) {
rdev->audio.pin[i].channels = -1;
rdev->audio.pin[i].rate = -1;
rdev->audio.pin[i].bits_per_sample = -1;
rdev->audio.pin[i].status_bits = 0;
rdev->audio.pin[i].category_code = 0;
rdev->audio.pin[i].connected = false;
rdev->audio.pin[i].offset = pin_offsets[i];
rdev->audio.pin[i].id = i;
}
radeon_audio_interface_init(rdev);
for (i = 0; i < rdev->audio.num_pins; i++)
radeon_audio_enable(rdev, &rdev->audio.pin[i], 0);
return 0;
}
u32 radeon_audio_endpoint_rreg(struct radeon_device *rdev, u32 offset, u32 reg)
{
if (rdev->audio.funcs->endpoint_rreg)
return rdev->audio.funcs->endpoint_rreg(rdev, offset, reg);
return 0;
}
void radeon_audio_endpoint_wreg(struct radeon_device *rdev, u32 offset,
u32 reg, u32 v)
{
if (rdev->audio.funcs->endpoint_wreg)
rdev->audio.funcs->endpoint_wreg(rdev, offset, reg, v);
}
static void radeon_audio_write_sad_regs(struct drm_encoder *encoder)
{
struct drm_connector *connector = radeon_get_connector_for_encoder(encoder);
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct cea_sad *sads;
int sad_count;
if (!connector)
return;
sad_count = drm_edid_to_sad(radeon_connector_edid(connector), &sads);
if (sad_count <= 0) {
DRM_ERROR("Couldn't read SADs: %d\n", sad_count);
return;
}
BUG_ON(!sads);
if (radeon_encoder->audio && radeon_encoder->audio->write_sad_regs)
radeon_encoder->audio->write_sad_regs(encoder, sads, sad_count);
kfree(sads);
}
static void radeon_audio_write_speaker_allocation(struct drm_encoder *encoder)
{
struct drm_connector *connector = radeon_get_connector_for_encoder(encoder);
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
u8 *sadb = NULL;
int sad_count;
if (!connector)
return;
sad_count = drm_edid_to_speaker_allocation(radeon_connector_edid(connector),
&sadb);
if (sad_count < 0) {
DRM_DEBUG("Couldn't read Speaker Allocation Data Block: %d\n",
sad_count);
sad_count = 0;
}
if (radeon_encoder->audio && radeon_encoder->audio->write_speaker_allocation)
radeon_encoder->audio->write_speaker_allocation(encoder, sadb, sad_count);
kfree(sadb);
}
static void radeon_audio_write_latency_fields(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
struct drm_connector *connector = radeon_get_connector_for_encoder(encoder);
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
if (!connector)
return;
if (radeon_encoder->audio && radeon_encoder->audio->write_latency_fields)
radeon_encoder->audio->write_latency_fields(encoder, connector, mode);
}
struct r600_audio_pin* radeon_audio_get_pin(struct drm_encoder *encoder)
{
struct radeon_device *rdev = encoder->dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->audio && radeon_encoder->audio->get_pin)
return radeon_encoder->audio->get_pin(rdev);
return NULL;
}
static void radeon_audio_select_pin(struct drm_encoder *encoder)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->audio && radeon_encoder->audio->select_pin)
radeon_encoder->audio->select_pin(encoder);
}
void radeon_audio_detect(struct drm_connector *connector,
struct drm_encoder *encoder,
enum drm_connector_status status)
{
struct drm_device *dev = connector->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig;
if (!radeon_audio_chipset_supported(rdev))
return;
if (!radeon_encoder_is_digital(encoder))
return;
dig = radeon_encoder->enc_priv;
if (status == connector_status_connected) {
if (connector->connector_type == DRM_MODE_CONNECTOR_DisplayPort) {
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
if (radeon_dp_getsinktype(radeon_connector) ==
CONNECTOR_OBJECT_ID_DISPLAYPORT)
radeon_encoder->audio = rdev->audio.dp_funcs;
else
radeon_encoder->audio = rdev->audio.hdmi_funcs;
} else {
radeon_encoder->audio = rdev->audio.hdmi_funcs;
}
if (drm_detect_monitor_audio(radeon_connector_edid(connector))) {
if (!dig->pin)
dig->pin = radeon_audio_get_pin(encoder);
radeon_audio_enable(rdev, dig->pin, 0xf);
} else {
radeon_audio_enable(rdev, dig->pin, 0);
dig->pin = NULL;
}
} else {
radeon_audio_enable(rdev, dig->pin, 0);
dig->pin = NULL;
}
}
void radeon_audio_fini(struct radeon_device *rdev)
{
int i;
if (!rdev->audio.enabled)
return;
for (i = 0; i < rdev->audio.num_pins; i++)
radeon_audio_enable(rdev, &rdev->audio.pin[i], 0);
rdev->audio.enabled = false;
}
static void radeon_audio_set_dto(struct drm_encoder *encoder, unsigned int clock)
{
struct radeon_device *rdev = encoder->dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_crtc *crtc = to_radeon_crtc(encoder->crtc);
if (radeon_encoder->audio && radeon_encoder->audio->set_dto)
radeon_encoder->audio->set_dto(rdev, crtc, clock);
}
static int radeon_audio_set_avi_packet(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
struct radeon_device *rdev = encoder->dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
struct drm_connector *connector = radeon_get_connector_for_encoder(encoder);
u8 buffer[HDMI_INFOFRAME_HEADER_SIZE + HDMI_AVI_INFOFRAME_SIZE];
struct hdmi_avi_infoframe frame;
int err;
if (!connector)
return -EINVAL;
err = drm_hdmi_avi_infoframe_from_display_mode(&frame, mode);
if (err < 0) {
DRM_ERROR("failed to setup AVI infoframe: %d\n", err);
return err;
}
if (drm_rgb_quant_range_selectable(radeon_connector_edid(connector))) {
if (radeon_encoder->output_csc == RADEON_OUTPUT_CSC_TVRGB)
frame.quantization_range = HDMI_QUANTIZATION_RANGE_LIMITED;
else
frame.quantization_range = HDMI_QUANTIZATION_RANGE_FULL;
} else {
frame.quantization_range = HDMI_QUANTIZATION_RANGE_DEFAULT;
}
err = hdmi_avi_infoframe_pack(&frame, buffer, sizeof(buffer));
if (err < 0) {
DRM_ERROR("failed to pack AVI infoframe: %d\n", err);
return err;
}
if (dig && dig->afmt && radeon_encoder->audio &&
radeon_encoder->audio->set_avi_packet)
radeon_encoder->audio->set_avi_packet(rdev, dig->afmt->offset,
buffer, sizeof(buffer));
return 0;
}
static void radeon_audio_calc_cts(unsigned int clock, int *CTS, int *N, int freq)
{
int n, cts;
unsigned long div, mul;
n = 128 * freq;
cts = clock * 1000;
div = gcd(n, cts);
n /= div;
cts /= div;
mul = ((128*freq/1000) + (n-1))/n;
n *= mul;
cts *= mul;
if (n < (128*freq/1500))
printk(KERN_WARNING "Calculated ACR N value is too small. You may experience audio problems.\n");
if (n > (128*freq/300))
printk(KERN_WARNING "Calculated ACR N value is too large. You may experience audio problems.\n");
*N = n;
*CTS = cts;
DRM_DEBUG("Calculated ACR timing N=%d CTS=%d for frequency %d\n",
*N, *CTS, freq);
}
static const struct radeon_hdmi_acr* radeon_audio_acr(unsigned int clock)
{
static struct radeon_hdmi_acr res;
u8 i;
static const struct radeon_hdmi_acr hdmi_predefined_acr[] = {
{ 25175, 4096, 25175, 28224, 125875, 6144, 25175 },
{ 25200, 4096, 25200, 6272, 28000, 6144, 25200 },
{ 27000, 4096, 27000, 6272, 30000, 6144, 27000 },
{ 27027, 4096, 27027, 6272, 30030, 6144, 27027 },
{ 54000, 4096, 54000, 6272, 60000, 6144, 54000 },
{ 54054, 4096, 54054, 6272, 60060, 6144, 54054 },
{ 74176, 4096, 74176, 5733, 75335, 6144, 74176 },
{ 74250, 4096, 74250, 6272, 82500, 6144, 74250 },
{ 148352, 4096, 148352, 5733, 150670, 6144, 148352 },
{ 148500, 4096, 148500, 6272, 165000, 6144, 148500 },
};
for (i = 0; i < ARRAY_SIZE(hdmi_predefined_acr); i++)
if (hdmi_predefined_acr[i].clock == clock)
return &hdmi_predefined_acr[i];
radeon_audio_calc_cts(clock, &res.cts_32khz, &res.n_32khz, 32000);
radeon_audio_calc_cts(clock, &res.cts_44_1khz, &res.n_44_1khz, 44100);
radeon_audio_calc_cts(clock, &res.cts_48khz, &res.n_48khz, 48000);
return &res;
}
static void radeon_audio_update_acr(struct drm_encoder *encoder, unsigned int clock)
{
const struct radeon_hdmi_acr *acr = radeon_audio_acr(clock);
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
if (!dig || !dig->afmt)
return;
if (radeon_encoder->audio && radeon_encoder->audio->update_acr)
radeon_encoder->audio->update_acr(encoder, dig->afmt->offset, acr);
}
static void radeon_audio_set_vbi_packet(struct drm_encoder *encoder)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
if (!dig || !dig->afmt)
return;
if (radeon_encoder->audio && radeon_encoder->audio->set_vbi_packet)
radeon_encoder->audio->set_vbi_packet(encoder, dig->afmt->offset);
}
static void radeon_hdmi_set_color_depth(struct drm_encoder *encoder)
{
int bpc = 8;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
if (!dig || !dig->afmt)
return;
if (encoder->crtc) {
struct radeon_crtc *radeon_crtc = to_radeon_crtc(encoder->crtc);
bpc = radeon_crtc->bpc;
}
if (radeon_encoder->audio && radeon_encoder->audio->set_color_depth)
radeon_encoder->audio->set_color_depth(encoder, dig->afmt->offset, bpc);
}
static void radeon_audio_set_audio_packet(struct drm_encoder *encoder)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
if (!dig || !dig->afmt)
return;
if (radeon_encoder->audio && radeon_encoder->audio->set_audio_packet)
radeon_encoder->audio->set_audio_packet(encoder, dig->afmt->offset);
}
static void radeon_audio_set_mute(struct drm_encoder *encoder, bool mute)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
if (!dig || !dig->afmt)
return;
if (radeon_encoder->audio && radeon_encoder->audio->set_mute)
radeon_encoder->audio->set_mute(encoder, dig->afmt->offset, mute);
}
static void radeon_audio_hdmi_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
struct drm_connector *connector = radeon_get_connector_for_encoder(encoder);
if (!dig || !dig->afmt)
return;
if (!connector)
return;
if (drm_detect_monitor_audio(radeon_connector_edid(connector))) {
radeon_audio_set_mute(encoder, true);
radeon_audio_write_speaker_allocation(encoder);
radeon_audio_write_sad_regs(encoder);
radeon_audio_write_latency_fields(encoder, mode);
radeon_audio_set_dto(encoder, mode->clock);
radeon_audio_set_vbi_packet(encoder);
radeon_hdmi_set_color_depth(encoder);
radeon_audio_update_acr(encoder, mode->clock);
radeon_audio_set_audio_packet(encoder);
radeon_audio_select_pin(encoder);
if (radeon_audio_set_avi_packet(encoder, mode) < 0)
return;
radeon_audio_set_mute(encoder, false);
} else {
radeon_hdmi_set_color_depth(encoder);
if (radeon_audio_set_avi_packet(encoder, mode) < 0)
return;
}
}
static void radeon_audio_dp_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
struct drm_connector *connector = radeon_get_connector_for_encoder(encoder);
struct radeon_connector *radeon_connector = to_radeon_connector(connector);
struct radeon_connector_atom_dig *dig_connector =
radeon_connector->con_priv;
if (!dig || !dig->afmt)
return;
if (!connector)
return;
if (drm_detect_monitor_audio(radeon_connector_edid(connector))) {
radeon_audio_write_speaker_allocation(encoder);
radeon_audio_write_sad_regs(encoder);
radeon_audio_write_latency_fields(encoder, mode);
if (rdev->clock.dp_extclk || ASIC_IS_DCE5(rdev))
radeon_audio_set_dto(encoder, rdev->clock.default_dispclk * 10);
else
radeon_audio_set_dto(encoder, dig_connector->dp_clock);
radeon_audio_set_audio_packet(encoder);
radeon_audio_select_pin(encoder);
if (radeon_audio_set_avi_packet(encoder, mode) < 0)
return;
}
}
void radeon_audio_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->audio && radeon_encoder->audio->mode_set)
radeon_encoder->audio->mode_set(encoder, mode);
}
void radeon_audio_dpms(struct drm_encoder *encoder, int mode)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
if (radeon_encoder->audio && radeon_encoder->audio->dpms)
radeon_encoder->audio->dpms(encoder, mode == DRM_MODE_DPMS_ON);
}
