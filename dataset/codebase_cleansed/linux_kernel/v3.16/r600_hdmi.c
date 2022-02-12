static void r600_hdmi_calc_cts(uint32_t clock, int *CTS, int *N, int freq)
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
struct radeon_hdmi_acr r600_hdmi_acr(uint32_t clock)
{
struct radeon_hdmi_acr res;
u8 i;
for (i = 0; i < ARRAY_SIZE(r600_hdmi_predefined_acr); i++) {
if (r600_hdmi_predefined_acr[i].clock == clock)
return r600_hdmi_predefined_acr[i];
}
r600_hdmi_calc_cts(clock, &res.cts_32khz, &res.n_32khz, 32000);
r600_hdmi_calc_cts(clock, &res.cts_44_1khz, &res.n_44_1khz, 44100);
r600_hdmi_calc_cts(clock, &res.cts_48khz, &res.n_48khz, 48000);
return res;
}
void r600_hdmi_update_ACR(struct drm_encoder *encoder, uint32_t clock)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_hdmi_acr acr = r600_hdmi_acr(clock);
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
WREG32_P(HDMI0_ACR_32_0 + offset,
HDMI0_ACR_CTS_32(acr.cts_32khz),
~HDMI0_ACR_CTS_32_MASK);
WREG32_P(HDMI0_ACR_32_1 + offset,
HDMI0_ACR_N_32(acr.n_32khz),
~HDMI0_ACR_N_32_MASK);
WREG32_P(HDMI0_ACR_44_0 + offset,
HDMI0_ACR_CTS_44(acr.cts_44_1khz),
~HDMI0_ACR_CTS_44_MASK);
WREG32_P(HDMI0_ACR_44_1 + offset,
HDMI0_ACR_N_44(acr.n_44_1khz),
~HDMI0_ACR_N_44_MASK);
WREG32_P(HDMI0_ACR_48_0 + offset,
HDMI0_ACR_CTS_48(acr.cts_48khz),
~HDMI0_ACR_CTS_48_MASK);
WREG32_P(HDMI0_ACR_48_1 + offset,
HDMI0_ACR_N_48(acr.n_48khz),
~HDMI0_ACR_N_48_MASK);
}
void r600_hdmi_update_avi_infoframe(struct drm_encoder *encoder, void *buffer,
size_t size)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
uint8_t *frame = buffer + 3;
uint8_t *header = buffer;
WREG32(HDMI0_AVI_INFO0 + offset,
frame[0x0] | (frame[0x1] << 8) | (frame[0x2] << 16) | (frame[0x3] << 24));
WREG32(HDMI0_AVI_INFO1 + offset,
frame[0x4] | (frame[0x5] << 8) | (frame[0x6] << 16) | (frame[0x7] << 24));
WREG32(HDMI0_AVI_INFO2 + offset,
frame[0x8] | (frame[0x9] << 8) | (frame[0xA] << 16) | (frame[0xB] << 24));
WREG32(HDMI0_AVI_INFO3 + offset,
frame[0xC] | (frame[0xD] << 8) | (header[1] << 24));
}
static void r600_hdmi_update_audio_infoframe(struct drm_encoder *encoder,
const void *buffer, size_t size)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
const u8 *frame = buffer + 3;
WREG32(HDMI0_AUDIO_INFO0 + offset,
frame[0x0] | (frame[0x1] << 8) | (frame[0x2] << 16) | (frame[0x3] << 24));
WREG32(HDMI0_AUDIO_INFO1 + offset,
frame[0x4] | (frame[0x5] << 8) | (frame[0x6] << 16) | (frame[0x8] << 24));
}
static bool r600_hdmi_is_audio_buffer_filled(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
return (RREG32(HDMI0_STATUS + offset) & 0x10) != 0;
}
int r600_hdmi_buffer_status_changed(struct drm_encoder *encoder)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
int status, result;
if (!dig->afmt || !dig->afmt->enabled)
return 0;
status = r600_hdmi_is_audio_buffer_filled(encoder);
result = dig->afmt->last_buffer_filled_status != status;
dig->afmt->last_buffer_filled_status = status;
return result;
}
void r600_hdmi_audio_workaround(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
bool hdmi_audio_workaround = false;
u32 value;
if (!hdmi_audio_workaround ||
r600_hdmi_is_audio_buffer_filled(encoder))
value = 0;
else
value = HDMI0_AUDIO_TEST_EN;
WREG32_P(HDMI0_AUDIO_PACKET_CONTROL + offset,
value, ~HDMI0_AUDIO_TEST_EN);
}
void r600_audio_set_dto(struct drm_encoder *encoder, u32 clock)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
u32 base_rate = 24000;
u32 max_ratio = clock / base_rate;
u32 dto_phase;
u32 dto_modulo = clock;
u32 wallclock_ratio;
u32 dto_cntl;
if (!dig || !dig->afmt)
return;
if (max_ratio >= 8) {
dto_phase = 192 * 1000;
wallclock_ratio = 3;
} else if (max_ratio >= 4) {
dto_phase = 96 * 1000;
wallclock_ratio = 2;
} else if (max_ratio >= 2) {
dto_phase = 48 * 1000;
wallclock_ratio = 1;
} else {
dto_phase = 24 * 1000;
wallclock_ratio = 0;
}
if (ASIC_IS_DCE32(rdev)) {
if (dig->dig_encoder == 0) {
dto_cntl = RREG32(DCCG_AUDIO_DTO0_CNTL) & ~DCCG_AUDIO_DTO_WALLCLOCK_RATIO_MASK;
dto_cntl |= DCCG_AUDIO_DTO_WALLCLOCK_RATIO(wallclock_ratio);
WREG32(DCCG_AUDIO_DTO0_CNTL, dto_cntl);
WREG32(DCCG_AUDIO_DTO0_PHASE, dto_phase);
WREG32(DCCG_AUDIO_DTO0_MODULE, dto_modulo);
WREG32(DCCG_AUDIO_DTO_SELECT, 0);
} else {
dto_cntl = RREG32(DCCG_AUDIO_DTO1_CNTL) & ~DCCG_AUDIO_DTO_WALLCLOCK_RATIO_MASK;
dto_cntl |= DCCG_AUDIO_DTO_WALLCLOCK_RATIO(wallclock_ratio);
WREG32(DCCG_AUDIO_DTO1_CNTL, dto_cntl);
WREG32(DCCG_AUDIO_DTO1_PHASE, dto_phase);
WREG32(DCCG_AUDIO_DTO1_MODULE, dto_modulo);
WREG32(DCCG_AUDIO_DTO_SELECT, 1);
}
} else {
if (dig->dig_encoder == 0) {
WREG32(DCCG_AUDIO_DTO0_PHASE, base_rate * 100);
WREG32(DCCG_AUDIO_DTO0_MODULE, clock * 100);
WREG32(DCCG_AUDIO_DTO_SELECT, 0);
} else {
WREG32(DCCG_AUDIO_DTO1_PHASE, base_rate * 100);
WREG32(DCCG_AUDIO_DTO1_MODULE, clock * 100);
WREG32(DCCG_AUDIO_DTO_SELECT, 1);
}
}
}
void r600_hdmi_setmode(struct drm_encoder *encoder, struct drm_display_mode *mode)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
u8 buffer[HDMI_INFOFRAME_HEADER_SIZE + HDMI_AVI_INFOFRAME_SIZE];
struct hdmi_avi_infoframe frame;
uint32_t offset;
uint32_t acr_ctl;
ssize_t err;
if (!dig || !dig->afmt)
return;
if (!dig->afmt->enabled)
return;
offset = dig->afmt->offset;
dig->afmt->pin = r600_audio_get_pin(rdev);
r600_audio_enable(rdev, dig->afmt->pin, false);
r600_audio_set_dto(encoder, mode->clock);
WREG32_P(HDMI0_AUDIO_PACKET_CONTROL + offset,
HDMI0_AUDIO_SAMPLE_SEND |
HDMI0_AUDIO_DELAY_EN(1) |
HDMI0_AUDIO_PACKETS_PER_LINE(3) |
HDMI0_60958_CS_UPDATE,
~(HDMI0_AUDIO_SAMPLE_SEND |
HDMI0_AUDIO_DELAY_EN_MASK |
HDMI0_AUDIO_PACKETS_PER_LINE_MASK |
HDMI0_60958_CS_UPDATE));
acr_ctl = ASIC_IS_DCE3(rdev) ? DCE3_HDMI0_ACR_PACKET_CONTROL :
HDMI0_ACR_PACKET_CONTROL;
WREG32_P(acr_ctl + offset,
HDMI0_ACR_SOURCE |
HDMI0_ACR_AUTO_SEND,
~(HDMI0_ACR_SOURCE |
HDMI0_ACR_AUTO_SEND));
WREG32_OR(HDMI0_VBI_PACKET_CONTROL + offset,
HDMI0_NULL_SEND |
HDMI0_GC_SEND |
HDMI0_GC_CONT);
WREG32_OR(HDMI0_INFOFRAME_CONTROL0 + offset,
HDMI0_AVI_INFO_SEND |
HDMI0_AVI_INFO_CONT |
HDMI0_AUDIO_INFO_SEND |
HDMI0_AUDIO_INFO_UPDATE);
WREG32_P(HDMI0_INFOFRAME_CONTROL1 + offset,
HDMI0_AVI_INFO_LINE(2) |
HDMI0_AUDIO_INFO_LINE(2),
~(HDMI0_AVI_INFO_LINE_MASK |
HDMI0_AUDIO_INFO_LINE_MASK));
WREG32_AND(HDMI0_GC + offset,
~HDMI0_GC_AVMUTE);
err = drm_hdmi_avi_infoframe_from_display_mode(&frame, mode);
if (err < 0) {
DRM_ERROR("failed to setup AVI infoframe: %zd\n", err);
return;
}
err = hdmi_avi_infoframe_pack(&frame, buffer, sizeof(buffer));
if (err < 0) {
DRM_ERROR("failed to pack AVI infoframe: %zd\n", err);
return;
}
r600_hdmi_update_avi_infoframe(encoder, buffer, sizeof(buffer));
WREG32_AND(HDMI0_GENERIC_PACKET_CONTROL + offset,
~(HDMI0_GENERIC0_SEND |
HDMI0_GENERIC0_CONT |
HDMI0_GENERIC0_UPDATE |
HDMI0_GENERIC1_SEND |
HDMI0_GENERIC1_CONT |
HDMI0_GENERIC0_LINE_MASK |
HDMI0_GENERIC1_LINE_MASK));
r600_hdmi_update_ACR(encoder, mode->clock);
WREG32_P(HDMI0_60958_0 + offset,
HDMI0_60958_CS_CHANNEL_NUMBER_L(1),
~(HDMI0_60958_CS_CHANNEL_NUMBER_L_MASK |
HDMI0_60958_CS_CLOCK_ACCURACY_MASK));
WREG32_P(HDMI0_60958_1 + offset,
HDMI0_60958_CS_CHANNEL_NUMBER_R(2),
~HDMI0_60958_CS_CHANNEL_NUMBER_R_MASK);
WREG32(HDMI0_RAMP_CONTROL0 + offset, 0x00FFFFFF);
WREG32(HDMI0_RAMP_CONTROL1 + offset, 0x007FFFFF);
WREG32(HDMI0_RAMP_CONTROL2 + offset, 0x00000001);
WREG32(HDMI0_RAMP_CONTROL3 + offset, 0x00000001);
r600_audio_enable(rdev, dig->afmt->pin, true);
}
void r600_hdmi_update_audio_settings(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
struct r600_audio_pin audio = r600_audio_status(rdev);
uint8_t buffer[HDMI_INFOFRAME_HEADER_SIZE + HDMI_AUDIO_INFOFRAME_SIZE];
struct hdmi_audio_infoframe frame;
uint32_t offset;
uint32_t value;
ssize_t err;
if (!dig->afmt || !dig->afmt->enabled)
return;
offset = dig->afmt->offset;
DRM_DEBUG("%s with %d channels, %d Hz sampling rate, %d bits per sample,\n",
r600_hdmi_is_audio_buffer_filled(encoder) ? "playing" : "stopped",
audio.channels, audio.rate, audio.bits_per_sample);
DRM_DEBUG("0x%02X IEC60958 status bits and 0x%02X category code\n",
(int)audio.status_bits, (int)audio.category_code);
err = hdmi_audio_infoframe_init(&frame);
if (err < 0) {
DRM_ERROR("failed to setup audio infoframe\n");
return;
}
frame.channels = audio.channels;
err = hdmi_audio_infoframe_pack(&frame, buffer, sizeof(buffer));
if (err < 0) {
DRM_ERROR("failed to pack audio infoframe\n");
return;
}
value = RREG32(HDMI0_AUDIO_PACKET_CONTROL + offset);
if (value & HDMI0_AUDIO_TEST_EN)
WREG32(HDMI0_AUDIO_PACKET_CONTROL + offset,
value & ~HDMI0_AUDIO_TEST_EN);
WREG32_OR(HDMI0_CONTROL + offset,
HDMI0_ERROR_ACK);
WREG32_AND(HDMI0_INFOFRAME_CONTROL0 + offset,
~HDMI0_AUDIO_INFO_SOURCE);
r600_hdmi_update_audio_infoframe(encoder, buffer, sizeof(buffer));
WREG32_OR(HDMI0_INFOFRAME_CONTROL0 + offset,
HDMI0_AUDIO_INFO_CONT |
HDMI0_AUDIO_INFO_UPDATE);
}
void r600_hdmi_enable(struct drm_encoder *encoder, bool enable)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
u32 hdmi = HDMI0_ERROR_ACK;
if (!dig || !dig->afmt)
return;
if (enable && dig->afmt->enabled)
return;
if (!enable && !dig->afmt->enabled)
return;
if (!ASIC_IS_DCE3(rdev)) {
if (enable)
hdmi |= HDMI0_ENABLE;
switch (radeon_encoder->encoder_id) {
case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1:
if (enable) {
WREG32_OR(AVIVO_TMDSA_CNTL, AVIVO_TMDSA_CNTL_HDMI_EN);
hdmi |= HDMI0_STREAM(HDMI0_STREAM_TMDSA);
} else {
WREG32_AND(AVIVO_TMDSA_CNTL, ~AVIVO_TMDSA_CNTL_HDMI_EN);
}
break;
case ENCODER_OBJECT_ID_INTERNAL_LVTM1:
if (enable) {
WREG32_OR(AVIVO_LVTMA_CNTL, AVIVO_LVTMA_CNTL_HDMI_EN);
hdmi |= HDMI0_STREAM(HDMI0_STREAM_LVTMA);
} else {
WREG32_AND(AVIVO_LVTMA_CNTL, ~AVIVO_LVTMA_CNTL_HDMI_EN);
}
break;
case ENCODER_OBJECT_ID_INTERNAL_DDI:
if (enable) {
WREG32_OR(DDIA_CNTL, DDIA_HDMI_EN);
hdmi |= HDMI0_STREAM(HDMI0_STREAM_DDIA);
} else {
WREG32_AND(DDIA_CNTL, ~DDIA_HDMI_EN);
}
break;
case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DVO1:
if (enable)
hdmi |= HDMI0_STREAM(HDMI0_STREAM_DVOA);
break;
default:
dev_err(rdev->dev, "Invalid encoder for HDMI: 0x%X\n",
radeon_encoder->encoder_id);
break;
}
WREG32(HDMI0_CONTROL + dig->afmt->offset, hdmi);
}
if (rdev->irq.installed) {
if (enable)
radeon_irq_kms_enable_afmt(rdev, dig->afmt->id);
else
radeon_irq_kms_disable_afmt(rdev, dig->afmt->id);
}
dig->afmt->enabled = enable;
DRM_DEBUG("%sabling HDMI interface @ 0x%04X for encoder 0x%x\n",
enable ? "En" : "Dis", dig->afmt->offset, radeon_encoder->encoder_id);
}
