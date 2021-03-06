static bool is_edp_psr(struct intel_dp *intel_dp)
{
return intel_dp->psr_dpcd[0] & DP_PSR_IS_SUPPORTED;
}
bool intel_psr_is_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!HAS_PSR(dev))
return false;
return I915_READ(EDP_PSR_CTL(dev)) & EDP_PSR_ENABLE;
}
static void intel_psr_write_vsc(struct intel_dp *intel_dp,
struct edp_vsc_psr *vsc_psr)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(dig_port->base.base.crtc);
u32 ctl_reg = HSW_TVIDEO_DIP_CTL(crtc->config.cpu_transcoder);
u32 data_reg = HSW_TVIDEO_DIP_VSC_DATA(crtc->config.cpu_transcoder);
uint32_t *data = (uint32_t *) vsc_psr;
unsigned int i;
I915_WRITE(ctl_reg, 0);
POSTING_READ(ctl_reg);
for (i = 0; i < VIDEO_DIP_VSC_DATA_SIZE; i += 4) {
if (i < sizeof(struct edp_vsc_psr))
I915_WRITE(data_reg + i, *data++);
else
I915_WRITE(data_reg + i, 0);
}
I915_WRITE(ctl_reg, VIDEO_DIP_ENABLE_VSC_HSW);
POSTING_READ(ctl_reg);
}
static void intel_psr_setup_vsc(struct intel_dp *intel_dp)
{
struct edp_vsc_psr psr_vsc;
memset(&psr_vsc, 0, sizeof(psr_vsc));
psr_vsc.sdp_header.HB0 = 0;
psr_vsc.sdp_header.HB1 = 0x7;
psr_vsc.sdp_header.HB2 = 0x2;
psr_vsc.sdp_header.HB3 = 0x8;
intel_psr_write_vsc(intel_dp, &psr_vsc);
}
static void intel_psr_enable_sink(struct intel_dp *intel_dp)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t aux_clock_divider;
int precharge = 0x3;
bool only_standby = false;
static const uint8_t aux_msg[] = {
[0] = DP_AUX_NATIVE_WRITE << 4,
[1] = DP_SET_POWER >> 8,
[2] = DP_SET_POWER & 0xff,
[3] = 1 - 1,
[4] = DP_SET_POWER_D0,
};
int i;
BUILD_BUG_ON(sizeof(aux_msg) > 20);
aux_clock_divider = intel_dp->get_aux_clock_divider(intel_dp, 0);
if (IS_BROADWELL(dev) && dig_port->port != PORT_A)
only_standby = true;
if (intel_dp->psr_dpcd[1] & DP_PSR_NO_TRAIN_ON_EXIT || only_standby)
drm_dp_dpcd_writeb(&intel_dp->aux, DP_PSR_EN_CFG,
DP_PSR_ENABLE & ~DP_PSR_MAIN_LINK_ACTIVE);
else
drm_dp_dpcd_writeb(&intel_dp->aux, DP_PSR_EN_CFG,
DP_PSR_ENABLE | DP_PSR_MAIN_LINK_ACTIVE);
for (i = 0; i < sizeof(aux_msg); i += 4)
I915_WRITE(EDP_PSR_AUX_DATA1(dev) + i,
intel_dp_pack_aux(&aux_msg[i], sizeof(aux_msg) - i));
I915_WRITE(EDP_PSR_AUX_CTL(dev),
DP_AUX_CH_CTL_TIME_OUT_400us |
(sizeof(aux_msg) << DP_AUX_CH_CTL_MESSAGE_SIZE_SHIFT) |
(precharge << DP_AUX_CH_CTL_PRECHARGE_2US_SHIFT) |
(aux_clock_divider << DP_AUX_CH_CTL_BIT_CLOCK_2X_SHIFT));
}
static void intel_psr_enable_source(struct intel_dp *intel_dp)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t max_sleep_time = 0x1f;
uint32_t idle_frames = 1;
uint32_t val = 0x0;
const uint32_t link_entry_time = EDP_PSR_MIN_LINK_ENTRY_TIME_8_LINES;
bool only_standby = false;
if (IS_BROADWELL(dev) && dig_port->port != PORT_A)
only_standby = true;
if (intel_dp->psr_dpcd[1] & DP_PSR_NO_TRAIN_ON_EXIT || only_standby) {
val |= EDP_PSR_LINK_STANDBY;
val |= EDP_PSR_TP2_TP3_TIME_0us;
val |= EDP_PSR_TP1_TIME_0us;
val |= EDP_PSR_SKIP_AUX_EXIT;
val |= IS_BROADWELL(dev) ? BDW_PSR_SINGLE_FRAME : 0;
} else
val |= EDP_PSR_LINK_DISABLE;
I915_WRITE(EDP_PSR_CTL(dev), val |
(IS_BROADWELL(dev) ? 0 : link_entry_time) |
max_sleep_time << EDP_PSR_MAX_SLEEP_TIME_SHIFT |
idle_frames << EDP_PSR_IDLE_FRAME_SHIFT |
EDP_PSR_ENABLE);
}
static bool intel_psr_match_conditions(struct intel_dp *intel_dp)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dig_port->base.base.crtc;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
lockdep_assert_held(&dev_priv->psr.lock);
WARN_ON(!drm_modeset_is_locked(&dev->mode_config.connection_mutex));
WARN_ON(!drm_modeset_is_locked(&crtc->mutex));
dev_priv->psr.source_ok = false;
if (IS_HASWELL(dev) && dig_port->port != PORT_A) {
DRM_DEBUG_KMS("HSW ties PSR to DDI A (eDP)\n");
return false;
}
if (!i915.enable_psr) {
DRM_DEBUG_KMS("PSR disable by flag\n");
return false;
}
if (IS_BROADWELL(dev))
goto out;
if (I915_READ(HSW_STEREO_3D_CTL(intel_crtc->config.cpu_transcoder)) &
S3D_ENABLE) {
DRM_DEBUG_KMS("PSR condition failed: Stereo 3D is Enabled\n");
return false;
}
if (intel_crtc->config.adjusted_mode.flags & DRM_MODE_FLAG_INTERLACE) {
DRM_DEBUG_KMS("PSR condition failed: Interlaced is Enabled\n");
return false;
}
out:
dev_priv->psr.source_ok = true;
return true;
}
static void intel_psr_do_enable(struct intel_dp *intel_dp)
{
struct intel_digital_port *intel_dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = intel_dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
WARN_ON(I915_READ(EDP_PSR_CTL(dev)) & EDP_PSR_ENABLE);
WARN_ON(dev_priv->psr.active);
lockdep_assert_held(&dev_priv->psr.lock);
intel_psr_enable_source(intel_dp);
dev_priv->psr.active = true;
}
void intel_psr_enable(struct intel_dp *intel_dp)
{
struct intel_digital_port *intel_dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = intel_dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (!HAS_PSR(dev)) {
DRM_DEBUG_KMS("PSR not supported on this platform\n");
return;
}
if (!is_edp_psr(intel_dp)) {
DRM_DEBUG_KMS("PSR not supported by this panel\n");
return;
}
mutex_lock(&dev_priv->psr.lock);
if (dev_priv->psr.enabled) {
DRM_DEBUG_KMS("PSR already in use\n");
goto unlock;
}
if (!intel_psr_match_conditions(intel_dp))
goto unlock;
dev_priv->psr.busy_frontbuffer_bits = 0;
intel_psr_setup_vsc(intel_dp);
I915_WRITE(EDP_PSR_DEBUG_CTL(dev), EDP_PSR_DEBUG_MASK_MEMUP |
EDP_PSR_DEBUG_MASK_HPD | EDP_PSR_DEBUG_MASK_LPSP);
intel_psr_enable_sink(intel_dp);
dev_priv->psr.enabled = intel_dp;
unlock:
mutex_unlock(&dev_priv->psr.lock);
}
void intel_psr_disable(struct intel_dp *intel_dp)
{
struct intel_digital_port *intel_dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = intel_dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev_priv->psr.lock);
if (!dev_priv->psr.enabled) {
mutex_unlock(&dev_priv->psr.lock);
return;
}
if (dev_priv->psr.active) {
I915_WRITE(EDP_PSR_CTL(dev),
I915_READ(EDP_PSR_CTL(dev)) & ~EDP_PSR_ENABLE);
if (_wait_for((I915_READ(EDP_PSR_STATUS_CTL(dev)) &
EDP_PSR_STATUS_STATE_MASK) == 0, 2000, 10))
DRM_ERROR("Timed out waiting for PSR Idle State\n");
dev_priv->psr.active = false;
} else {
WARN_ON(I915_READ(EDP_PSR_CTL(dev)) & EDP_PSR_ENABLE);
}
dev_priv->psr.enabled = NULL;
mutex_unlock(&dev_priv->psr.lock);
cancel_delayed_work_sync(&dev_priv->psr.work);
}
static void intel_psr_work(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv), psr.work.work);
struct intel_dp *intel_dp = dev_priv->psr.enabled;
if (wait_for((I915_READ(EDP_PSR_STATUS_CTL(dev_priv->dev)) &
EDP_PSR_STATUS_STATE_MASK) == 0, 50)) {
DRM_ERROR("Timed out waiting for PSR Idle for re-enable\n");
return;
}
mutex_lock(&dev_priv->psr.lock);
intel_dp = dev_priv->psr.enabled;
if (!intel_dp)
goto unlock;
if (dev_priv->psr.busy_frontbuffer_bits)
goto unlock;
intel_psr_do_enable(intel_dp);
unlock:
mutex_unlock(&dev_priv->psr.lock);
}
static void intel_psr_exit(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->psr.active) {
u32 val = I915_READ(EDP_PSR_CTL(dev));
WARN_ON(!(val & EDP_PSR_ENABLE));
I915_WRITE(EDP_PSR_CTL(dev), val & ~EDP_PSR_ENABLE);
dev_priv->psr.active = false;
}
}
void intel_psr_invalidate(struct drm_device *dev,
unsigned frontbuffer_bits)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
enum pipe pipe;
mutex_lock(&dev_priv->psr.lock);
if (!dev_priv->psr.enabled) {
mutex_unlock(&dev_priv->psr.lock);
return;
}
crtc = dp_to_dig_port(dev_priv->psr.enabled)->base.base.crtc;
pipe = to_intel_crtc(crtc)->pipe;
intel_psr_exit(dev);
frontbuffer_bits &= INTEL_FRONTBUFFER_ALL_MASK(pipe);
dev_priv->psr.busy_frontbuffer_bits |= frontbuffer_bits;
mutex_unlock(&dev_priv->psr.lock);
}
void intel_psr_flush(struct drm_device *dev,
unsigned frontbuffer_bits)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
enum pipe pipe;
mutex_lock(&dev_priv->psr.lock);
if (!dev_priv->psr.enabled) {
mutex_unlock(&dev_priv->psr.lock);
return;
}
crtc = dp_to_dig_port(dev_priv->psr.enabled)->base.base.crtc;
pipe = to_intel_crtc(crtc)->pipe;
dev_priv->psr.busy_frontbuffer_bits &= ~frontbuffer_bits;
if (IS_HASWELL(dev) &&
(frontbuffer_bits & INTEL_FRONTBUFFER_SPRITE(pipe)))
intel_psr_exit(dev);
if (!dev_priv->psr.active && !dev_priv->psr.busy_frontbuffer_bits)
schedule_delayed_work(&dev_priv->psr.work,
msecs_to_jiffies(100));
mutex_unlock(&dev_priv->psr.lock);
}
void intel_psr_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
INIT_DELAYED_WORK(&dev_priv->psr.work, intel_psr_work);
mutex_init(&dev_priv->psr.lock);
}
