static int r600_audio_chipset_supported(struct radeon_device *rdev)
{
return (rdev->family >= CHIP_R600 && rdev->family < CHIP_CEDAR)
|| rdev->family == CHIP_RS600
|| rdev->family == CHIP_RS690
|| rdev->family == CHIP_RS740;
}
int r600_audio_channels(struct radeon_device *rdev)
{
return (RREG32(R600_AUDIO_RATE_BPS_CHANNEL) & 0x7) + 1;
}
int r600_audio_bits_per_sample(struct radeon_device *rdev)
{
uint32_t value = (RREG32(R600_AUDIO_RATE_BPS_CHANNEL) & 0xF0) >> 4;
switch (value) {
case 0x0: return 8;
case 0x1: return 16;
case 0x2: return 20;
case 0x3: return 24;
case 0x4: return 32;
}
dev_err(rdev->dev, "Unknown bits per sample 0x%x using 16 instead\n",
(int)value);
return 16;
}
int r600_audio_rate(struct radeon_device *rdev)
{
uint32_t value = RREG32(R600_AUDIO_RATE_BPS_CHANNEL);
uint32_t result;
if (value & 0x4000)
result = 44100;
else
result = 48000;
result *= ((value >> 11) & 0x7) + 1;
result /= ((value >> 8) & 0x7) + 1;
return result;
}
uint8_t r600_audio_status_bits(struct radeon_device *rdev)
{
return RREG32(R600_AUDIO_STATUS_BITS) & 0xff;
}
uint8_t r600_audio_category_code(struct radeon_device *rdev)
{
return (RREG32(R600_AUDIO_STATUS_BITS) >> 8) & 0xff;
}
void r600_audio_schedule_polling(struct radeon_device *rdev)
{
mod_timer(&rdev->audio_timer,
jiffies + msecs_to_jiffies(AUDIO_TIMER_INTERVALL));
}
static void r600_audio_update_hdmi(unsigned long param)
{
struct radeon_device *rdev = (struct radeon_device *)param;
struct drm_device *dev = rdev->ddev;
int channels = r600_audio_channels(rdev);
int rate = r600_audio_rate(rdev);
int bps = r600_audio_bits_per_sample(rdev);
uint8_t status_bits = r600_audio_status_bits(rdev);
uint8_t category_code = r600_audio_category_code(rdev);
struct drm_encoder *encoder;
int changes = 0, still_going = 0;
changes |= channels != rdev->audio_channels;
changes |= rate != rdev->audio_rate;
changes |= bps != rdev->audio_bits_per_sample;
changes |= status_bits != rdev->audio_status_bits;
changes |= category_code != rdev->audio_category_code;
if (changes) {
rdev->audio_channels = channels;
rdev->audio_rate = rate;
rdev->audio_bits_per_sample = bps;
rdev->audio_status_bits = status_bits;
rdev->audio_category_code = category_code;
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
still_going |= radeon_encoder->audio_polling_active;
if (changes || r600_hdmi_buffer_status_changed(encoder))
r600_hdmi_update_audio_settings(encoder);
}
if (still_going)
r600_audio_schedule_polling(rdev);
}
static void r600_audio_engine_enable(struct radeon_device *rdev, bool enable)
{
DRM_INFO("%s audio support\n", enable ? "Enabling" : "Disabling");
WREG32_P(R600_AUDIO_ENABLE, enable ? 0x81000000 : 0x0, ~0x81000000);
rdev->audio_enabled = enable;
}
int r600_audio_init(struct radeon_device *rdev)
{
if (!radeon_audio || !r600_audio_chipset_supported(rdev))
return 0;
r600_audio_engine_enable(rdev, true);
rdev->audio_channels = -1;
rdev->audio_rate = -1;
rdev->audio_bits_per_sample = -1;
rdev->audio_status_bits = 0;
rdev->audio_category_code = 0;
setup_timer(
&rdev->audio_timer,
r600_audio_update_hdmi,
(unsigned long)rdev);
return 0;
}
void r600_audio_enable_polling(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
DRM_DEBUG("r600_audio_enable_polling: %d\n",
radeon_encoder->audio_polling_active);
if (radeon_encoder->audio_polling_active)
return;
radeon_encoder->audio_polling_active = 1;
if (rdev->audio_enabled)
mod_timer(&rdev->audio_timer, jiffies + 1);
}
void r600_audio_disable_polling(struct drm_encoder *encoder)
{
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
DRM_DEBUG("r600_audio_disable_polling: %d\n",
radeon_encoder->audio_polling_active);
radeon_encoder->audio_polling_active = 0;
}
void r600_audio_set_clock(struct drm_encoder *encoder, int clock)
{
struct drm_device *dev = encoder->dev;
struct radeon_device *rdev = dev->dev_private;
struct radeon_encoder *radeon_encoder = to_radeon_encoder(encoder);
struct radeon_encoder_atom_dig *dig = radeon_encoder->enc_priv;
int base_rate = 48000;
switch (radeon_encoder->encoder_id) {
case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1:
case ENCODER_OBJECT_ID_INTERNAL_LVTM1:
WREG32_P(R600_AUDIO_TIMING, 0, ~0x301);
break;
case ENCODER_OBJECT_ID_INTERNAL_UNIPHY:
case ENCODER_OBJECT_ID_INTERNAL_UNIPHY1:
case ENCODER_OBJECT_ID_INTERNAL_UNIPHY2:
case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA:
WREG32_P(R600_AUDIO_TIMING, 0x100, ~0x301);
break;
default:
dev_err(rdev->dev, "Unsupported encoder type 0x%02X\n",
radeon_encoder->encoder_id);
return;
}
switch (dig->dig_encoder) {
case 0:
WREG32(R600_AUDIO_PLL1_MUL, base_rate * 50);
WREG32(R600_AUDIO_PLL1_DIV, clock * 100);
WREG32(R600_AUDIO_CLK_SRCSEL, 0);
break;
case 1:
WREG32(R600_AUDIO_PLL2_MUL, base_rate * 50);
WREG32(R600_AUDIO_PLL2_DIV, clock * 100);
WREG32(R600_AUDIO_CLK_SRCSEL, 1);
break;
default:
dev_err(rdev->dev, "Unsupported DIG on encoder 0x%02X\n",
radeon_encoder->encoder_id);
return;
}
}
void r600_audio_fini(struct radeon_device *rdev)
{
if (!rdev->audio_enabled)
return;
del_timer(&rdev->audio_timer);
r600_audio_engine_enable(rdev, false);
}
