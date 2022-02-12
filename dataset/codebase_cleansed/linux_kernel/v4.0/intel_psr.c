static bool is_edp_psr(struct intel_dp *intel_dp)
{
return intel_dp->psr_dpcd[0] & DP_PSR_IS_SUPPORTED;
}
static bool vlv_is_psr_active_on_pipe(struct drm_device *dev, int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t val;
val = I915_READ(VLV_PSRSTAT(pipe)) &
VLV_EDP_PSR_CURR_STATE_MASK;
return (val == VLV_EDP_PSR_ACTIVE_NORFB_UP) ||
(val == VLV_EDP_PSR_ACTIVE_SF_UPDATE);
}
static void intel_psr_write_vsc(struct intel_dp *intel_dp,
struct edp_vsc_psr *vsc_psr)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *crtc = to_intel_crtc(dig_port->base.base.crtc);
u32 ctl_reg = HSW_TVIDEO_DIP_CTL(crtc->config->cpu_transcoder);
u32 data_reg = HSW_TVIDEO_DIP_VSC_DATA(crtc->config->cpu_transcoder);
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
static void vlv_psr_setup_vsc(struct intel_dp *intel_dp)
{
struct intel_digital_port *intel_dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = intel_dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = intel_dig_port->base.base.crtc;
enum pipe pipe = to_intel_crtc(crtc)->pipe;
uint32_t val;
val = I915_READ(VLV_VSCSDP(pipe));
val &= ~VLV_EDP_PSR_SDP_FREQ_MASK;
val |= VLV_EDP_PSR_SDP_FREQ_EVFRAME;
I915_WRITE(VLV_VSCSDP(pipe), val);
}
static void hsw_psr_setup_vsc(struct intel_dp *intel_dp)
{
struct edp_vsc_psr psr_vsc;
memset(&psr_vsc, 0, sizeof(psr_vsc));
psr_vsc.sdp_header.HB0 = 0;
psr_vsc.sdp_header.HB1 = 0x7;
psr_vsc.sdp_header.HB2 = 0x2;
psr_vsc.sdp_header.HB3 = 0x8;
intel_psr_write_vsc(intel_dp, &psr_vsc);
}
static void vlv_psr_enable_sink(struct intel_dp *intel_dp)
{
drm_dp_dpcd_writeb(&intel_dp->aux, DP_PSR_EN_CFG,
DP_PSR_ENABLE);
}
static void hsw_psr_enable_sink(struct intel_dp *intel_dp)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t aux_clock_divider;
uint32_t aux_data_reg, aux_ctl_reg;
int precharge = 0x3;
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
if (dev_priv->psr.link_standby)
drm_dp_dpcd_writeb(&intel_dp->aux, DP_PSR_EN_CFG,
DP_PSR_ENABLE | DP_PSR_MAIN_LINK_ACTIVE);
else
drm_dp_dpcd_writeb(&intel_dp->aux, DP_PSR_EN_CFG,
DP_PSR_ENABLE & ~DP_PSR_MAIN_LINK_ACTIVE);
aux_data_reg = (INTEL_INFO(dev)->gen >= 9) ?
DPA_AUX_CH_DATA1 : EDP_PSR_AUX_DATA1(dev);
aux_ctl_reg = (INTEL_INFO(dev)->gen >= 9) ?
DPA_AUX_CH_CTL : EDP_PSR_AUX_CTL(dev);
for (i = 0; i < sizeof(aux_msg); i += 4)
I915_WRITE(aux_data_reg + i,
intel_dp_pack_aux(&aux_msg[i], sizeof(aux_msg) - i));
if (INTEL_INFO(dev)->gen >= 9) {
uint32_t val;
val = I915_READ(aux_ctl_reg);
val &= ~DP_AUX_CH_CTL_TIME_OUT_MASK;
val |= DP_AUX_CH_CTL_TIME_OUT_1600us;
val &= ~DP_AUX_CH_CTL_MESSAGE_SIZE_MASK;
val |= (sizeof(aux_msg) << DP_AUX_CH_CTL_MESSAGE_SIZE_SHIFT);
val &= ~DP_AUX_CH_CTL_PSR_DATA_AUX_REG_SKL;
I915_WRITE(aux_ctl_reg, val);
} else {
I915_WRITE(aux_ctl_reg,
DP_AUX_CH_CTL_TIME_OUT_400us |
(sizeof(aux_msg) << DP_AUX_CH_CTL_MESSAGE_SIZE_SHIFT) |
(precharge << DP_AUX_CH_CTL_PRECHARGE_2US_SHIFT) |
(aux_clock_divider << DP_AUX_CH_CTL_BIT_CLOCK_2X_SHIFT));
}
}
static void vlv_psr_enable_source(struct intel_dp *intel_dp)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dig_port->base.base.crtc;
enum pipe pipe = to_intel_crtc(crtc)->pipe;
I915_WRITE(VLV_PSRCTL(pipe),
VLV_EDP_PSR_MODE_SW_TIMER |
VLV_EDP_PSR_SRC_TRANSMITTER_STATE |
VLV_EDP_PSR_ENABLE);
}
static void vlv_psr_activate(struct intel_dp *intel_dp)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dig_port->base.base.crtc;
enum pipe pipe = to_intel_crtc(crtc)->pipe;
I915_WRITE(VLV_PSRCTL(pipe), I915_READ(VLV_PSRCTL(pipe)) |
VLV_EDP_PSR_ACTIVE_ENTRY);
}
static void hsw_psr_enable_source(struct intel_dp *intel_dp)
{
struct intel_digital_port *dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t max_sleep_time = 0x1f;
uint32_t idle_frames = dev_priv->vbt.psr.idle_frames ?
dev_priv->vbt.psr.idle_frames + 1 : 2;
uint32_t val = 0x0;
const uint32_t link_entry_time = EDP_PSR_MIN_LINK_ENTRY_TIME_8_LINES;
if (dev_priv->psr.link_standby) {
val |= EDP_PSR_LINK_STANDBY;
val |= EDP_PSR_TP2_TP3_TIME_0us;
val |= EDP_PSR_TP1_TIME_0us;
val |= EDP_PSR_SKIP_AUX_EXIT;
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
if (IS_HASWELL(dev) &&
I915_READ(HSW_STEREO_3D_CTL(intel_crtc->config->cpu_transcoder)) &
S3D_ENABLE) {
DRM_DEBUG_KMS("PSR condition failed: Stereo 3D is Enabled\n");
return false;
}
if (IS_HASWELL(dev) &&
intel_crtc->config->base.adjusted_mode.flags & DRM_MODE_FLAG_INTERLACE) {
DRM_DEBUG_KMS("PSR condition failed: Interlaced is Enabled\n");
return false;
}
dev_priv->psr.source_ok = true;
return true;
}
static void intel_psr_activate(struct intel_dp *intel_dp)
{
struct intel_digital_port *intel_dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = intel_dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
WARN_ON(I915_READ(EDP_PSR_CTL(dev)) & EDP_PSR_ENABLE);
WARN_ON(dev_priv->psr.active);
lockdep_assert_held(&dev_priv->psr.lock);
if (HAS_DDI(dev))
hsw_psr_enable_source(intel_dp);
else
vlv_psr_activate(intel_dp);
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
dev_priv->psr.link_standby = dev_priv->vbt.psr.full_link;
if ((intel_dp->psr_dpcd[1] & DP_PSR_NO_TRAIN_ON_EXIT) ||
(IS_BROADWELL(dev) && intel_dig_port->port != PORT_A))
dev_priv->psr.link_standby = true;
dev_priv->psr.busy_frontbuffer_bits = 0;
if (HAS_DDI(dev)) {
hsw_psr_setup_vsc(intel_dp);
I915_WRITE(EDP_PSR_DEBUG_CTL(dev), EDP_PSR_DEBUG_MASK_MEMUP |
EDP_PSR_DEBUG_MASK_HPD | EDP_PSR_DEBUG_MASK_LPSP);
hsw_psr_enable_sink(intel_dp);
if (INTEL_INFO(dev)->gen >= 9)
intel_psr_activate(intel_dp);
} else {
vlv_psr_setup_vsc(intel_dp);
vlv_psr_enable_sink(intel_dp);
vlv_psr_enable_source(intel_dp);
}
dev_priv->psr.enabled = intel_dp;
unlock:
mutex_unlock(&dev_priv->psr.lock);
}
static void vlv_psr_disable(struct intel_dp *intel_dp)
{
struct intel_digital_port *intel_dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = intel_dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_crtc *intel_crtc =
to_intel_crtc(intel_dig_port->base.base.crtc);
uint32_t val;
if (dev_priv->psr.active) {
if (wait_for((I915_READ(VLV_PSRSTAT(intel_crtc->pipe)) &
VLV_EDP_PSR_IN_TRANS) == 0, 1))
WARN(1, "PSR transition took longer than expected\n");
val = I915_READ(VLV_PSRCTL(intel_crtc->pipe));
val &= ~VLV_EDP_PSR_ACTIVE_ENTRY;
val &= ~VLV_EDP_PSR_ENABLE;
val &= ~VLV_EDP_PSR_MODE_MASK;
I915_WRITE(VLV_PSRCTL(intel_crtc->pipe), val);
dev_priv->psr.active = false;
} else {
WARN_ON(vlv_is_psr_active_on_pipe(dev, intel_crtc->pipe));
}
}
static void hsw_psr_disable(struct intel_dp *intel_dp)
{
struct intel_digital_port *intel_dig_port = dp_to_dig_port(intel_dp);
struct drm_device *dev = intel_dig_port->base.base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
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
if (HAS_DDI(dev))
hsw_psr_disable(intel_dp);
else
vlv_psr_disable(intel_dp);
dev_priv->psr.enabled = NULL;
mutex_unlock(&dev_priv->psr.lock);
cancel_delayed_work_sync(&dev_priv->psr.work);
}
static void intel_psr_work(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv), psr.work.work);
struct intel_dp *intel_dp = dev_priv->psr.enabled;
struct drm_crtc *crtc = dp_to_dig_port(intel_dp)->base.base.crtc;
enum pipe pipe = to_intel_crtc(crtc)->pipe;
if (HAS_DDI(dev_priv->dev)) {
if (wait_for((I915_READ(EDP_PSR_STATUS_CTL(dev_priv->dev)) &
EDP_PSR_STATUS_STATE_MASK) == 0, 50)) {
DRM_ERROR("Timed out waiting for PSR Idle for re-enable\n");
return;
}
} else {
if (wait_for((I915_READ(VLV_PSRSTAT(pipe)) &
VLV_EDP_PSR_IN_TRANS) == 0, 1)) {
DRM_ERROR("Timed out waiting for PSR Idle for re-enable\n");
return;
}
}
mutex_lock(&dev_priv->psr.lock);
intel_dp = dev_priv->psr.enabled;
if (!intel_dp)
goto unlock;
if (dev_priv->psr.busy_frontbuffer_bits)
goto unlock;
intel_psr_activate(intel_dp);
unlock:
mutex_unlock(&dev_priv->psr.lock);
}
static void intel_psr_exit(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_dp *intel_dp = dev_priv->psr.enabled;
struct drm_crtc *crtc = dp_to_dig_port(intel_dp)->base.base.crtc;
enum pipe pipe = to_intel_crtc(crtc)->pipe;
u32 val;
if (!dev_priv->psr.active)
return;
if (HAS_DDI(dev)) {
val = I915_READ(EDP_PSR_CTL(dev));
WARN_ON(!(val & EDP_PSR_ENABLE));
I915_WRITE(EDP_PSR_CTL(dev), val & ~EDP_PSR_ENABLE);
dev_priv->psr.active = false;
} else {
val = I915_READ(VLV_PSRCTL(pipe));
val &= ~VLV_EDP_PSR_ACTIVE_ENTRY;
I915_WRITE(VLV_PSRCTL(pipe), val);
drm_dp_dpcd_writeb(&intel_dp->aux, DP_SET_POWER,
DP_SET_POWER_D0);
}
dev_priv->psr.active = false;
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
if (!HAS_DDI(dev))
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
