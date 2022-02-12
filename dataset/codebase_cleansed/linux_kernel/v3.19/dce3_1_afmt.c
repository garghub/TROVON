static void dce3_2_afmt_write_speaker_allocation(struct drm_encoder *encoder)
{
struct radeon_device *rdev = encoder->dev->dev_private;
struct drm_connector *connector;
struct radeon_connector *radeon_connector = NULL;
u32 tmp;
u8 *sadb = NULL;
int sad_count;
list_for_each_entry(connector, &encoder->dev->mode_config.connector_list, head) {
if (connector->encoder == encoder) {
radeon_connector = to_radeon_connector(connector);
break;
}
}
if (!radeon_connector) {
DRM_ERROR("Couldn't find encoder's connector\n");
return;
}
sad_count = drm_edid_to_speaker_allocation(radeon_connector->edid, &sadb);
if (sad_count < 0) {
DRM_DEBUG("Couldn't read Speaker Allocation Data Block: %d\n", sad_count);
sad_count = 0;
}
tmp = RREG32(AZ_F0_CODEC_PIN0_CONTROL_CHANNEL_SPEAKER);
tmp &= ~(DP_CONNECTION | SPEAKER_ALLOCATION_MASK);
tmp |= HDMI_CONNECTION;
if (sad_count)
tmp |= SPEAKER_ALLOCATION(sadb[0]);
else
tmp |= SPEAKER_ALLOCATION(5);
WREG32(AZ_F0_CODEC_PIN0_CONTROL_CHANNEL_SPEAKER, tmp);
kfree(sadb);
}
static void dce3_2_afmt_write_sad_regs(struct drm_encoder *encoder)
{
struct radeon_device *rdev = encoder->dev->dev_private;
struct drm_connector *connector;
struct radeon_connector *radeon_connector = NULL;
struct cea_sad *sads;
int i, sad_count;
static const u16 eld_reg_to_type[][2] = {
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR0, HDMI_AUDIO_CODING_TYPE_PCM },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR1, HDMI_AUDIO_CODING_TYPE_AC3 },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR2, HDMI_AUDIO_CODING_TYPE_MPEG1 },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR3, HDMI_AUDIO_CODING_TYPE_MP3 },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR4, HDMI_AUDIO_CODING_TYPE_MPEG2 },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR5, HDMI_AUDIO_CODING_TYPE_AAC_LC },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR6, HDMI_AUDIO_CODING_TYPE_DTS },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR7, HDMI_AUDIO_CODING_TYPE_ATRAC },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR9, HDMI_AUDIO_CODING_TYPE_EAC3 },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR10, HDMI_AUDIO_CODING_TYPE_DTS_HD },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR11, HDMI_AUDIO_CODING_TYPE_MLP },
{ AZ_F0_CODEC_PIN0_CONTROL_AUDIO_DESCRIPTOR13, HDMI_AUDIO_CODING_TYPE_WMA_PRO },
};
list_for_each_entry(connector, &encoder->dev->mode_config.connector_list, head) {
if (connector->encoder == encoder) {
radeon_connector = to_radeon_connector(connector);
break;
}
}
if (!radeon_connector) {
DRM_ERROR("Couldn't find encoder's connector\n");
return;
}
sad_count = drm_edid_to_sad(radeon_connector->edid, &sads);
if (sad_count <= 0) {
DRM_ERROR("Couldn't read SADs: %d\n", sad_count);
return;
}
BUG_ON(!sads);
for (i = 0; i < ARRAY_SIZE(eld_reg_to_type); i++) {
u32 value = 0;
u8 stereo_freqs = 0;
int max_channels = -1;
int j;
for (j = 0; j < sad_count; j++) {
struct cea_sad *sad = &sads[j];
if (sad->format == eld_reg_to_type[i][1]) {
if (sad->channels > max_channels) {
value = MAX_CHANNELS(sad->channels) |
DESCRIPTOR_BYTE_2(sad->byte2) |
SUPPORTED_FREQUENCIES(sad->freq);
max_channels = sad->channels;
}
if (sad->format == HDMI_AUDIO_CODING_TYPE_PCM)
stereo_freqs |= sad->freq;
else
break;
}
}
value |= SUPPORTED_FREQUENCIES_STEREO(stereo_freqs);
WREG32(eld_reg_to_type[i][0], value);
}
kfree(sads);
}
void dce3_1_hdmi_setmode(struct drm_encoder *encoder, struct drm_display_mode *mode)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
u8 buffer[HDMI_INFOFRAME_HEADER_SIZE + HDMI_AVI_INFOFRAME_SIZE];
struct hdmi_avi_infoframe frame;
uint32_t offset;
ssize_t err;
if (!dig || !dig->afmt)
return;
if (!dig->afmt->enabled)
return;
offset = dig->afmt->offset;
dig->afmt->pin = r600_audio_get_pin(rdev);
r600_audio_enable(rdev, dig->afmt->pin, 0);
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
if (ASIC_IS_DCE32(rdev)) {
dce3_2_afmt_write_speaker_allocation(encoder);
dce3_2_afmt_write_sad_regs(encoder);
}
WREG32(HDMI0_ACR_PACKET_CONTROL + offset,
HDMI0_ACR_SOURCE |
HDMI0_ACR_AUTO_SEND);
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
r600_audio_enable(rdev, dig->afmt->pin, 0xf);
}
