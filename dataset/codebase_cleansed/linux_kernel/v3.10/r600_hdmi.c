static void r600_hdmi_calc_cts(uint32_t clock, int *CTS, int N, int freq)
{
if (*CTS == 0)
*CTS = clock * N / (128 * freq) * 1000;
DRM_DEBUG("Using ACR timing N=%d CTS=%d for frequency %d\n",
N, *CTS, freq);
}
struct radeon_hdmi_acr r600_hdmi_acr(uint32_t clock)
{
struct radeon_hdmi_acr res;
u8 i;
for (i = 0; r600_hdmi_predefined_acr[i].clock != clock &&
r600_hdmi_predefined_acr[i].clock != 0; i++)
;
res = r600_hdmi_predefined_acr[i];
r600_hdmi_calc_cts(clock, &res.cts_32khz, res.n_32khz, 32000);
r600_hdmi_calc_cts(clock, &res.cts_44_1khz, res.n_44_1khz, 44100);
r600_hdmi_calc_cts(clock, &res.cts_48khz, res.n_48khz, 48000);
return res;
}
static void r600_hdmi_update_ACR(struct drm_encoder *encoder, uint32_t clock)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_hdmi_acr acr = r600_hdmi_acr(clock);
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
WREG32(HDMI0_ACR_32_0 + offset, HDMI0_ACR_CTS_32(acr.cts_32khz));
WREG32(HDMI0_ACR_32_1 + offset, acr.n_32khz);
WREG32(HDMI0_ACR_44_0 + offset, HDMI0_ACR_CTS_44(acr.cts_44_1khz));
WREG32(HDMI0_ACR_44_1 + offset, acr.n_44_1khz);
WREG32(HDMI0_ACR_48_0 + offset, HDMI0_ACR_CTS_48(acr.cts_48khz));
WREG32(HDMI0_ACR_48_1 + offset, acr.n_48khz);
}
static void r600_hdmi_update_avi_infoframe(struct drm_encoder *encoder,
void *buffer, size_t size)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
uint8_t *frame = buffer + 3;
frame[0x0] += 2;
WREG32(HDMI0_AVI_INFO0 + offset,
frame[0x0] | (frame[0x1] << 8) | (frame[0x2] << 16) | (frame[0x3] << 24));
WREG32(HDMI0_AVI_INFO1 + offset,
frame[0x4] | (frame[0x5] << 8) | (frame[0x6] << 16) | (frame[0x7] << 24));
WREG32(HDMI0_AVI_INFO2 + offset,
frame[0x8] | (frame[0x9] << 8) | (frame[0xA] << 16) | (frame[0xB] << 24));
WREG32(HDMI0_AVI_INFO3 + offset,
frame[0xC] | (frame[0xD] << 8));
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
static void r600_hdmi_audio_workaround(struct drm_encoder *encoder)
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
if (!dig || !dig->afmt)
return;
if (ASIC_IS_DCE3(rdev)) {
WREG32(DCCG_AUDIO_DTO0_PHASE, base_rate * 100);
WREG32(DCCG_AUDIO_DTO0_MODULE, clock * 100);
WREG32(DCCG_AUDIO_DTO_SELECT, 0);
} else {
WREG32(AUDIO_DTO, AUDIO_DTO_PHASE(base_rate / 10) |
AUDIO_DTO_MODULE(clock / 10));
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
ssize_t err;
if (!dig->afmt->enabled)
return;
offset = dig->afmt->offset;
r600_audio_set_dto(encoder, mode->clock);
WREG32(HDMI0_VBI_PACKET_CONTROL + offset,
HDMI0_NULL_SEND);
WREG32(HDMI0_AUDIO_CRC_CONTROL + offset, 0x1000);
if (ASIC_IS_DCE32(rdev)) {
WREG32(HDMI0_AUDIO_PACKET_CONTROL + offset,
HDMI0_AUDIO_DELAY_EN(1) |
HDMI0_AUDIO_PACKETS_PER_LINE(3));
WREG32(AFMT_AUDIO_PACKET_CONTROL + offset,
AFMT_AUDIO_SAMPLE_SEND |
AFMT_60958_CS_UPDATE);
} else {
WREG32(HDMI0_AUDIO_PACKET_CONTROL + offset,
HDMI0_AUDIO_SAMPLE_SEND |
HDMI0_AUDIO_DELAY_EN(1) |
HDMI0_AUDIO_PACKETS_PER_LINE(3) |
HDMI0_60958_CS_UPDATE);
}
WREG32(HDMI0_ACR_PACKET_CONTROL + offset,
HDMI0_ACR_AUTO_SEND |
HDMI0_ACR_SOURCE);
WREG32(HDMI0_VBI_PACKET_CONTROL + offset,
HDMI0_NULL_SEND |
HDMI0_GC_SEND |
HDMI0_GC_CONT);
WREG32(HDMI0_INFOFRAME_CONTROL0 + offset,
HDMI0_AVI_INFO_SEND |
HDMI0_AVI_INFO_CONT |
HDMI0_AUDIO_INFO_SEND |
HDMI0_AUDIO_INFO_CONT);
WREG32(HDMI0_INFOFRAME_CONTROL1 + offset,
HDMI0_AVI_INFO_LINE(2) |
HDMI0_AUDIO_INFO_LINE(2));
WREG32(HDMI0_GC + offset, 0);
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
r600_hdmi_update_ACR(encoder, mode->clock);
WREG32(HDMI0_RAMP_CONTROL0 + offset, 0x00FFFFFF);
WREG32(HDMI0_RAMP_CONTROL1 + offset, 0x007FFFFF);
WREG32(HDMI0_RAMP_CONTROL2 + offset, 0x00000001);
WREG32(HDMI0_RAMP_CONTROL3 + offset, 0x00000001);
r600_hdmi_audio_workaround(encoder);
}
void r600_hdmi_update_audio_settings(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
struct r600_audio audio = r600_audio_status(rdev);
uint8_t buffer[HDMI_INFOFRAME_HEADER_SIZE + HDMI_AUDIO_INFOFRAME_SIZE];
struct hdmi_audio_infoframe frame;
uint32_t offset;
uint32_t iec;
ssize_t err;
if (!dig->afmt || !dig->afmt->enabled)
return;
offset = dig->afmt->offset;
DRM_DEBUG("%s with %d channels, %d Hz sampling rate, %d bits per sample,\n",
r600_hdmi_is_audio_buffer_filled(encoder) ? "playing" : "stopped",
audio.channels, audio.rate, audio.bits_per_sample);
DRM_DEBUG("0x%02X IEC60958 status bits and 0x%02X category code\n",
(int)audio.status_bits, (int)audio.category_code);
iec = 0;
if (audio.status_bits & AUDIO_STATUS_PROFESSIONAL)
iec |= 1 << 0;
if (audio.status_bits & AUDIO_STATUS_NONAUDIO)
iec |= 1 << 1;
if (audio.status_bits & AUDIO_STATUS_COPYRIGHT)
iec |= 1 << 2;
if (audio.status_bits & AUDIO_STATUS_EMPHASIS)
iec |= 1 << 3;
iec |= HDMI0_60958_CS_CATEGORY_CODE(audio.category_code);
switch (audio.rate) {
case 32000:
iec |= HDMI0_60958_CS_SAMPLING_FREQUENCY(0x3);
break;
case 44100:
iec |= HDMI0_60958_CS_SAMPLING_FREQUENCY(0x0);
break;
case 48000:
iec |= HDMI0_60958_CS_SAMPLING_FREQUENCY(0x2);
break;
case 88200:
iec |= HDMI0_60958_CS_SAMPLING_FREQUENCY(0x8);
break;
case 96000:
iec |= HDMI0_60958_CS_SAMPLING_FREQUENCY(0xa);
break;
case 176400:
iec |= HDMI0_60958_CS_SAMPLING_FREQUENCY(0xc);
break;
case 192000:
iec |= HDMI0_60958_CS_SAMPLING_FREQUENCY(0xe);
break;
}
WREG32(HDMI0_60958_0 + offset, iec);
iec = 0;
switch (audio.bits_per_sample) {
case 16:
iec |= HDMI0_60958_CS_WORD_LENGTH(0x2);
break;
case 20:
iec |= HDMI0_60958_CS_WORD_LENGTH(0x3);
break;
case 24:
iec |= HDMI0_60958_CS_WORD_LENGTH(0xb);
break;
}
if (audio.status_bits & AUDIO_STATUS_V)
iec |= 0x5 << 16;
WREG32_P(HDMI0_60958_1 + offset, iec, ~0x5000f);
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
r600_hdmi_update_audio_infoframe(encoder, buffer, sizeof(buffer));
r600_hdmi_audio_workaround(encoder);
}
void r600_hdmi_enable(struct drm_encoder *encoder, bool enable)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
u32 hdmi = HDMI0_ERROR_ACK;
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
