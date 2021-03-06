static bool radeon_dig_encoder(struct drm_encoder *encoder)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
switch (radeon_encoder->encoder_id) {
case ENCODER_OBJECT_ID_INTERNAL_LVDS:
case ENCODER_OBJECT_ID_INTERNAL_TMDS1:
case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1:
case ENCODER_OBJECT_ID_INTERNAL_LVTM1:
case ENCODER_OBJECT_ID_INTERNAL_DVO1:
case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DVO1:
case ENCODER_OBJECT_ID_INTERNAL_DDI:
case ENCODER_OBJECT_ID_INTERNAL_UNIPHY:
case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA:
case ENCODER_OBJECT_ID_INTERNAL_UNIPHY1:
case ENCODER_OBJECT_ID_INTERNAL_UNIPHY2:
return true;
}
return false;
}
static int r600_audio_chipset_supported(struct radeon_device *rdev)
{
return ASIC_IS_DCE2(rdev) && !ASIC_IS_NODCE(rdev);
}
struct r600_audio_pin r600_audio_status(struct radeon_device *rdev)
{
struct r600_audio_pin status;
uint32_t value;
value = RREG32(R600_AUDIO_RATE_BPS_CHANNEL);
status.channels = (value & 0x7) + 1;
switch ((value & 0xF0) >> 4) {
case 0x0:
status.bits_per_sample = 8;
break;
case 0x1:
status.bits_per_sample = 16;
break;
case 0x2:
status.bits_per_sample = 20;
break;
case 0x3:
status.bits_per_sample = 24;
break;
case 0x4:
status.bits_per_sample = 32;
break;
default:
dev_err(rdev->dev, "Unknown bits per sample 0x%x, using 16\n",
(int)value);
status.bits_per_sample = 16;
}
if (value & 0x4000)
status.rate = 44100;
else
status.rate = 48000;
status.rate *= ((value >> 11) & 0x7) + 1;
status.rate /= ((value >> 8) & 0x7) + 1;
value = RREG32(R600_AUDIO_STATUS_BITS);
status.status_bits = value & 0xff;
status.category_code = (value >> 8) & 0xff;
return status;
}
void r600_audio_update_hdmi(struct work_struct *work)
{
struct radeon_device *rdev = container_of(work, struct radeon_device,
audio_work);
struct drm_device *dev = rdev->ddev;
struct r600_audio_pin audio_status = r600_audio_status(rdev);
struct drm_encoder *encoder;
bool changed = false;
if (rdev->audio.pin[0].channels != audio_status.channels ||
rdev->audio.pin[0].rate != audio_status.rate ||
rdev->audio.pin[0].bits_per_sample != audio_status.bits_per_sample ||
rdev->audio.pin[0].status_bits != audio_status.status_bits ||
rdev->audio.pin[0].category_code != audio_status.category_code) {
rdev->audio.pin[0] = audio_status;
changed = true;
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
if (!radeon_dig_encoder(encoder))
continue;
if (changed || r600_hdmi_buffer_status_changed(encoder))
r600_hdmi_update_audio_settings(encoder);
}
}
static void r600_audio_enable(struct radeon_device *rdev,
struct r600_audio_pin *pin,
bool enable)
{
u32 value = 0;
if (ASIC_IS_DCE4(rdev)) {
if (enable) {
value |= 0x81000000;
value |= 0x0e1000f0;
}
WREG32(EVERGREEN_AUDIO_ENABLE, value);
} else {
WREG32_P(R600_AUDIO_ENABLE,
enable ? 0x81000000 : 0x0, ~0x81000000);
}
DRM_INFO("%s audio %d support\n", enable ? "Enabling" : "Disabling", pin->id);
}
int r600_audio_init(struct radeon_device *rdev)
{
if (!radeon_audio || !r600_audio_chipset_supported(rdev))
return 0;
rdev->audio.enabled = true;
rdev->audio.num_pins = 1;
rdev->audio.pin[0].channels = -1;
rdev->audio.pin[0].rate = -1;
rdev->audio.pin[0].bits_per_sample = -1;
rdev->audio.pin[0].status_bits = 0;
rdev->audio.pin[0].category_code = 0;
rdev->audio.pin[0].id = 0;
r600_audio_enable(rdev, &rdev->audio.pin[0], true);
return 0;
}
void r600_audio_fini(struct radeon_device *rdev)
{
if (!rdev->audio.enabled)
return;
r600_audio_enable(rdev, &rdev->audio.pin[0], false);
rdev->audio.enabled = false;
}
struct r600_audio_pin *r600_audio_get_pin(struct radeon_device *rdev)
{
return &rdev->audio.pin[0];
}
