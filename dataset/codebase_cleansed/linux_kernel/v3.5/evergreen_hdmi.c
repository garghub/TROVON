static void evergreen_hdmi_update_ACR(struct drm_encoder *encoder, uint32_t clock)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_hdmi_acr acr = r600_hdmi_acr(clock);
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
WREG32(HDMI_ACR_32_0 + offset, HDMI_ACR_CTS_32(acr.cts_32khz));
WREG32(HDMI_ACR_32_1 + offset, acr.n_32khz);
WREG32(HDMI_ACR_44_0 + offset, HDMI_ACR_CTS_44(acr.cts_44_1khz));
WREG32(HDMI_ACR_44_1 + offset, acr.n_44_1khz);
WREG32(HDMI_ACR_48_0 + offset, HDMI_ACR_CTS_48(acr.cts_48khz));
WREG32(HDMI_ACR_48_1 + offset, acr.n_48khz);
}
static void evergreen_hdmi_infoframe_checksum(uint8_t packetType,
uint8_t versionNumber,
uint8_t length,
uint8_t *frame)
{
int i;
frame[0] = packetType + versionNumber + length;
for (i = 1; i <= length; i++)
frame[0] += frame[i];
frame[0] = 0x100 - frame[0];
}
static void evergreen_hdmi_videoinfoframe(
struct drm_encoder *encoder,
uint8_t color_format,
int active_information_present,
uint8_t active_format_aspect_ratio,
uint8_t scan_information,
uint8_t colorimetry,
uint8_t ex_colorimetry,
uint8_t quantization,
int ITC,
uint8_t picture_aspect_ratio,
uint8_t video_format_identification,
uint8_t pixel_repetition,
uint8_t non_uniform_picture_scaling,
uint8_t bar_info_data_valid,
uint16_t top_bar,
uint16_t bottom_bar,
uint16_t left_bar,
uint16_t right_bar
)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset = dig->afmt->offset;
uint8_t frame[14];
frame[0x0] = 0;
frame[0x1] =
(scan_information & 0x3) |
((bar_info_data_valid & 0x3) << 2) |
((active_information_present & 0x1) << 4) |
((color_format & 0x3) << 5);
frame[0x2] =
(active_format_aspect_ratio & 0xF) |
((picture_aspect_ratio & 0x3) << 4) |
((colorimetry & 0x3) << 6);
frame[0x3] =
(non_uniform_picture_scaling & 0x3) |
((quantization & 0x3) << 2) |
((ex_colorimetry & 0x7) << 4) |
((ITC & 0x1) << 7);
frame[0x4] = (video_format_identification & 0x7F);
frame[0x5] = (pixel_repetition & 0xF);
frame[0x6] = (top_bar & 0xFF);
frame[0x7] = (top_bar >> 8);
frame[0x8] = (bottom_bar & 0xFF);
frame[0x9] = (bottom_bar >> 8);
frame[0xA] = (left_bar & 0xFF);
frame[0xB] = (left_bar >> 8);
frame[0xC] = (right_bar & 0xFF);
frame[0xD] = (right_bar >> 8);
evergreen_hdmi_infoframe_checksum(0x82, 0x02, 0x0D, frame);
frame[0x0] += 2;
WREG32(AFMT_AVI_INFO0 + offset,
frame[0x0] | (frame[0x1] << 8) | (frame[0x2] << 16) | (frame[0x3] << 24));
WREG32(AFMT_AVI_INFO1 + offset,
frame[0x4] | (frame[0x5] << 8) | (frame[0x6] << 16) | (frame[0x7] << 24));
WREG32(AFMT_AVI_INFO2 + offset,
frame[0x8] | (frame[0x9] << 8) | (frame[0xA] << 16) | (frame[0xB] << 24));
WREG32(AFMT_AVI_INFO3 + offset,
frame[0xC] | (frame[0xD] << 8));
}
void evergreen_hdmi_setmode(struct drm_encoder *encoder, struct drm_display_mode *mode)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
uint32_t offset;
if (!dig->afmt->enabled)
return;
offset = dig->afmt->offset;
r600_audio_set_clock(encoder, mode->clock);
WREG32(HDMI_VBI_PACKET_CONTROL + offset,
HDMI_NULL_SEND);
WREG32(AFMT_AUDIO_CRC_CONTROL + offset, 0x1000);
WREG32(HDMI_AUDIO_PACKET_CONTROL + offset,
HDMI_AUDIO_DELAY_EN(1) |
HDMI_AUDIO_PACKETS_PER_LINE(3));
WREG32(AFMT_AUDIO_PACKET_CONTROL + offset,
AFMT_AUDIO_SAMPLE_SEND |
AFMT_60958_CS_UPDATE);
WREG32(HDMI_ACR_PACKET_CONTROL + offset,
HDMI_ACR_AUTO_SEND |
HDMI_ACR_SOURCE);
WREG32(HDMI_VBI_PACKET_CONTROL + offset,
HDMI_NULL_SEND |
HDMI_GC_SEND |
HDMI_GC_CONT);
WREG32(HDMI_INFOFRAME_CONTROL0 + offset,
HDMI_AVI_INFO_SEND |
HDMI_AVI_INFO_CONT |
HDMI_AUDIO_INFO_SEND |
HDMI_AUDIO_INFO_CONT);
WREG32(AFMT_INFOFRAME_CONTROL0 + offset,
AFMT_AUDIO_INFO_UPDATE);
WREG32(HDMI_INFOFRAME_CONTROL1 + offset,
HDMI_AVI_INFO_LINE(2) |
HDMI_AUDIO_INFO_LINE(2));
WREG32(HDMI_GC + offset, 0);
evergreen_hdmi_videoinfoframe(encoder, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0);
evergreen_hdmi_update_ACR(encoder, mode->clock);
WREG32(AFMT_RAMP_CONTROL0 + offset, 0x00FFFFFF);
WREG32(AFMT_RAMP_CONTROL1 + offset, 0x007FFFFF);
WREG32(AFMT_RAMP_CONTROL2 + offset, 0x00000001);
WREG32(AFMT_RAMP_CONTROL3 + offset, 0x00000001);
}
