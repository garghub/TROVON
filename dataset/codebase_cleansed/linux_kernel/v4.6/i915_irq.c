static void gen5_assert_iir_is_zero(struct drm_i915_private *dev_priv,
i915_reg_t reg)
{
u32 val = I915_READ(reg);
if (val == 0)
return;
WARN(1, "Interrupt register 0x%x is not zero: 0x%08x\n",
i915_mmio_reg_offset(reg), val);
I915_WRITE(reg, 0xffffffff);
POSTING_READ(reg);
I915_WRITE(reg, 0xffffffff);
POSTING_READ(reg);
}
static inline void
i915_hotplug_interrupt_update_locked(struct drm_i915_private *dev_priv,
uint32_t mask,
uint32_t bits)
{
uint32_t val;
assert_spin_locked(&dev_priv->irq_lock);
WARN_ON(bits & ~mask);
val = I915_READ(PORT_HOTPLUG_EN);
val &= ~mask;
val |= bits;
I915_WRITE(PORT_HOTPLUG_EN, val);
}
void i915_hotplug_interrupt_update(struct drm_i915_private *dev_priv,
uint32_t mask,
uint32_t bits)
{
spin_lock_irq(&dev_priv->irq_lock);
i915_hotplug_interrupt_update_locked(dev_priv, mask, bits);
spin_unlock_irq(&dev_priv->irq_lock);
}
void ilk_update_display_irq(struct drm_i915_private *dev_priv,
uint32_t interrupt_mask,
uint32_t enabled_irq_mask)
{
uint32_t new_val;
assert_spin_locked(&dev_priv->irq_lock);
WARN_ON(enabled_irq_mask & ~interrupt_mask);
if (WARN_ON(!intel_irqs_enabled(dev_priv)))
return;
new_val = dev_priv->irq_mask;
new_val &= ~interrupt_mask;
new_val |= (~enabled_irq_mask & interrupt_mask);
if (new_val != dev_priv->irq_mask) {
dev_priv->irq_mask = new_val;
I915_WRITE(DEIMR, dev_priv->irq_mask);
POSTING_READ(DEIMR);
}
}
static void ilk_update_gt_irq(struct drm_i915_private *dev_priv,
uint32_t interrupt_mask,
uint32_t enabled_irq_mask)
{
assert_spin_locked(&dev_priv->irq_lock);
WARN_ON(enabled_irq_mask & ~interrupt_mask);
if (WARN_ON(!intel_irqs_enabled(dev_priv)))
return;
dev_priv->gt_irq_mask &= ~interrupt_mask;
dev_priv->gt_irq_mask |= (~enabled_irq_mask & interrupt_mask);
I915_WRITE(GTIMR, dev_priv->gt_irq_mask);
POSTING_READ(GTIMR);
}
void gen5_enable_gt_irq(struct drm_i915_private *dev_priv, uint32_t mask)
{
ilk_update_gt_irq(dev_priv, mask, mask);
}
void gen5_disable_gt_irq(struct drm_i915_private *dev_priv, uint32_t mask)
{
ilk_update_gt_irq(dev_priv, mask, 0);
}
static i915_reg_t gen6_pm_iir(struct drm_i915_private *dev_priv)
{
return INTEL_INFO(dev_priv)->gen >= 8 ? GEN8_GT_IIR(2) : GEN6_PMIIR;
}
static i915_reg_t gen6_pm_imr(struct drm_i915_private *dev_priv)
{
return INTEL_INFO(dev_priv)->gen >= 8 ? GEN8_GT_IMR(2) : GEN6_PMIMR;
}
static i915_reg_t gen6_pm_ier(struct drm_i915_private *dev_priv)
{
return INTEL_INFO(dev_priv)->gen >= 8 ? GEN8_GT_IER(2) : GEN6_PMIER;
}
static void snb_update_pm_irq(struct drm_i915_private *dev_priv,
uint32_t interrupt_mask,
uint32_t enabled_irq_mask)
{
uint32_t new_val;
WARN_ON(enabled_irq_mask & ~interrupt_mask);
assert_spin_locked(&dev_priv->irq_lock);
new_val = dev_priv->pm_irq_mask;
new_val &= ~interrupt_mask;
new_val |= (~enabled_irq_mask & interrupt_mask);
if (new_val != dev_priv->pm_irq_mask) {
dev_priv->pm_irq_mask = new_val;
I915_WRITE(gen6_pm_imr(dev_priv), dev_priv->pm_irq_mask);
POSTING_READ(gen6_pm_imr(dev_priv));
}
}
void gen6_enable_pm_irq(struct drm_i915_private *dev_priv, uint32_t mask)
{
if (WARN_ON(!intel_irqs_enabled(dev_priv)))
return;
snb_update_pm_irq(dev_priv, mask, mask);
}
static void __gen6_disable_pm_irq(struct drm_i915_private *dev_priv,
uint32_t mask)
{
snb_update_pm_irq(dev_priv, mask, 0);
}
void gen6_disable_pm_irq(struct drm_i915_private *dev_priv, uint32_t mask)
{
if (WARN_ON(!intel_irqs_enabled(dev_priv)))
return;
__gen6_disable_pm_irq(dev_priv, mask);
}
void gen6_reset_rps_interrupts(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
i915_reg_t reg = gen6_pm_iir(dev_priv);
spin_lock_irq(&dev_priv->irq_lock);
I915_WRITE(reg, dev_priv->pm_rps_events);
I915_WRITE(reg, dev_priv->pm_rps_events);
POSTING_READ(reg);
dev_priv->rps.pm_iir = 0;
spin_unlock_irq(&dev_priv->irq_lock);
}
void gen6_enable_rps_interrupts(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
spin_lock_irq(&dev_priv->irq_lock);
WARN_ON(dev_priv->rps.pm_iir);
WARN_ON(I915_READ(gen6_pm_iir(dev_priv)) & dev_priv->pm_rps_events);
dev_priv->rps.interrupts_enabled = true;
I915_WRITE(gen6_pm_ier(dev_priv), I915_READ(gen6_pm_ier(dev_priv)) |
dev_priv->pm_rps_events);
gen6_enable_pm_irq(dev_priv, dev_priv->pm_rps_events);
spin_unlock_irq(&dev_priv->irq_lock);
}
u32 gen6_sanitize_rps_pm_mask(struct drm_i915_private *dev_priv, u32 mask)
{
if (INTEL_INFO(dev_priv)->gen <= 7 && !IS_HASWELL(dev_priv))
mask &= ~GEN6_PM_RP_UP_EI_EXPIRED;
if (INTEL_INFO(dev_priv)->gen >= 8)
mask &= ~GEN8_PMINTR_REDIRECT_TO_NON_DISP;
return mask;
}
void gen6_disable_rps_interrupts(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
spin_lock_irq(&dev_priv->irq_lock);
dev_priv->rps.interrupts_enabled = false;
spin_unlock_irq(&dev_priv->irq_lock);
cancel_work_sync(&dev_priv->rps.work);
spin_lock_irq(&dev_priv->irq_lock);
I915_WRITE(GEN6_PMINTRMSK, gen6_sanitize_rps_pm_mask(dev_priv, ~0));
__gen6_disable_pm_irq(dev_priv, dev_priv->pm_rps_events);
I915_WRITE(gen6_pm_ier(dev_priv), I915_READ(gen6_pm_ier(dev_priv)) &
~dev_priv->pm_rps_events);
spin_unlock_irq(&dev_priv->irq_lock);
synchronize_irq(dev->irq);
}
static void bdw_update_port_irq(struct drm_i915_private *dev_priv,
uint32_t interrupt_mask,
uint32_t enabled_irq_mask)
{
uint32_t new_val;
uint32_t old_val;
assert_spin_locked(&dev_priv->irq_lock);
WARN_ON(enabled_irq_mask & ~interrupt_mask);
if (WARN_ON(!intel_irqs_enabled(dev_priv)))
return;
old_val = I915_READ(GEN8_DE_PORT_IMR);
new_val = old_val;
new_val &= ~interrupt_mask;
new_val |= (~enabled_irq_mask & interrupt_mask);
if (new_val != old_val) {
I915_WRITE(GEN8_DE_PORT_IMR, new_val);
POSTING_READ(GEN8_DE_PORT_IMR);
}
}
void bdw_update_pipe_irq(struct drm_i915_private *dev_priv,
enum pipe pipe,
uint32_t interrupt_mask,
uint32_t enabled_irq_mask)
{
uint32_t new_val;
assert_spin_locked(&dev_priv->irq_lock);
WARN_ON(enabled_irq_mask & ~interrupt_mask);
if (WARN_ON(!intel_irqs_enabled(dev_priv)))
return;
new_val = dev_priv->de_irq_mask[pipe];
new_val &= ~interrupt_mask;
new_val |= (~enabled_irq_mask & interrupt_mask);
if (new_val != dev_priv->de_irq_mask[pipe]) {
dev_priv->de_irq_mask[pipe] = new_val;
I915_WRITE(GEN8_DE_PIPE_IMR(pipe), dev_priv->de_irq_mask[pipe]);
POSTING_READ(GEN8_DE_PIPE_IMR(pipe));
}
}
void ibx_display_interrupt_update(struct drm_i915_private *dev_priv,
uint32_t interrupt_mask,
uint32_t enabled_irq_mask)
{
uint32_t sdeimr = I915_READ(SDEIMR);
sdeimr &= ~interrupt_mask;
sdeimr |= (~enabled_irq_mask & interrupt_mask);
WARN_ON(enabled_irq_mask & ~interrupt_mask);
assert_spin_locked(&dev_priv->irq_lock);
if (WARN_ON(!intel_irqs_enabled(dev_priv)))
return;
I915_WRITE(SDEIMR, sdeimr);
POSTING_READ(SDEIMR);
}
static void
__i915_enable_pipestat(struct drm_i915_private *dev_priv, enum pipe pipe,
u32 enable_mask, u32 status_mask)
{
i915_reg_t reg = PIPESTAT(pipe);
u32 pipestat = I915_READ(reg) & PIPESTAT_INT_ENABLE_MASK;
assert_spin_locked(&dev_priv->irq_lock);
WARN_ON(!intel_irqs_enabled(dev_priv));
if (WARN_ONCE(enable_mask & ~PIPESTAT_INT_ENABLE_MASK ||
status_mask & ~PIPESTAT_INT_STATUS_MASK,
"pipe %c: enable_mask=0x%x, status_mask=0x%x\n",
pipe_name(pipe), enable_mask, status_mask))
return;
if ((pipestat & enable_mask) == enable_mask)
return;
dev_priv->pipestat_irq_mask[pipe] |= status_mask;
pipestat |= enable_mask | status_mask;
I915_WRITE(reg, pipestat);
POSTING_READ(reg);
}
static void
__i915_disable_pipestat(struct drm_i915_private *dev_priv, enum pipe pipe,
u32 enable_mask, u32 status_mask)
{
i915_reg_t reg = PIPESTAT(pipe);
u32 pipestat = I915_READ(reg) & PIPESTAT_INT_ENABLE_MASK;
assert_spin_locked(&dev_priv->irq_lock);
WARN_ON(!intel_irqs_enabled(dev_priv));
if (WARN_ONCE(enable_mask & ~PIPESTAT_INT_ENABLE_MASK ||
status_mask & ~PIPESTAT_INT_STATUS_MASK,
"pipe %c: enable_mask=0x%x, status_mask=0x%x\n",
pipe_name(pipe), enable_mask, status_mask))
return;
if ((pipestat & enable_mask) == 0)
return;
dev_priv->pipestat_irq_mask[pipe] &= ~status_mask;
pipestat &= ~enable_mask;
I915_WRITE(reg, pipestat);
POSTING_READ(reg);
}
static u32 vlv_get_pipestat_enable_mask(struct drm_device *dev, u32 status_mask)
{
u32 enable_mask = status_mask << 16;
if (WARN_ON_ONCE(status_mask & PIPE_A_PSR_STATUS_VLV))
return 0;
if (WARN_ON_ONCE(status_mask & PIPE_B_PSR_STATUS_VLV))
return 0;
enable_mask &= ~(PIPE_FIFO_UNDERRUN_STATUS |
SPRITE0_FLIP_DONE_INT_EN_VLV |
SPRITE1_FLIP_DONE_INT_EN_VLV);
if (status_mask & SPRITE0_FLIP_DONE_INT_STATUS_VLV)
enable_mask |= SPRITE0_FLIP_DONE_INT_EN_VLV;
if (status_mask & SPRITE1_FLIP_DONE_INT_STATUS_VLV)
enable_mask |= SPRITE1_FLIP_DONE_INT_EN_VLV;
return enable_mask;
}
void
i915_enable_pipestat(struct drm_i915_private *dev_priv, enum pipe pipe,
u32 status_mask)
{
u32 enable_mask;
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
enable_mask = vlv_get_pipestat_enable_mask(dev_priv->dev,
status_mask);
else
enable_mask = status_mask << 16;
__i915_enable_pipestat(dev_priv, pipe, enable_mask, status_mask);
}
void
i915_disable_pipestat(struct drm_i915_private *dev_priv, enum pipe pipe,
u32 status_mask)
{
u32 enable_mask;
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
enable_mask = vlv_get_pipestat_enable_mask(dev_priv->dev,
status_mask);
else
enable_mask = status_mask << 16;
__i915_disable_pipestat(dev_priv, pipe, enable_mask, status_mask);
}
static void i915_enable_asle_pipestat(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv->opregion.asle || !IS_MOBILE(dev))
return;
spin_lock_irq(&dev_priv->irq_lock);
i915_enable_pipestat(dev_priv, PIPE_B, PIPE_LEGACY_BLC_EVENT_STATUS);
if (INTEL_INFO(dev)->gen >= 4)
i915_enable_pipestat(dev_priv, PIPE_A,
PIPE_LEGACY_BLC_EVENT_STATUS);
spin_unlock_irq(&dev_priv->irq_lock);
}
static u32 i8xx_get_vblank_counter(struct drm_device *dev, unsigned int pipe)
{
return 0;
}
static u32 i915_get_vblank_counter(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
i915_reg_t high_frame, low_frame;
u32 high1, high2, low, pixel, vbl_start, hsync_start, htotal;
struct intel_crtc *intel_crtc =
to_intel_crtc(dev_priv->pipe_to_crtc_mapping[pipe]);
const struct drm_display_mode *mode = &intel_crtc->base.hwmode;
htotal = mode->crtc_htotal;
hsync_start = mode->crtc_hsync_start;
vbl_start = mode->crtc_vblank_start;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
vbl_start = DIV_ROUND_UP(vbl_start, 2);
vbl_start *= htotal;
vbl_start -= htotal - hsync_start;
high_frame = PIPEFRAME(pipe);
low_frame = PIPEFRAMEPIXEL(pipe);
do {
high1 = I915_READ(high_frame) & PIPE_FRAME_HIGH_MASK;
low = I915_READ(low_frame);
high2 = I915_READ(high_frame) & PIPE_FRAME_HIGH_MASK;
} while (high1 != high2);
high1 >>= PIPE_FRAME_HIGH_SHIFT;
pixel = low & PIPE_PIXEL_MASK;
low >>= PIPE_FRAME_LOW_SHIFT;
return (((high1 << 8) | low) + (pixel >= vbl_start)) & 0xffffff;
}
static u32 g4x_get_vblank_counter(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(PIPE_FRMCOUNT_G4X(pipe));
}
static int __intel_get_crtc_scanline(struct intel_crtc *crtc)
{
struct drm_device *dev = crtc->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
const struct drm_display_mode *mode = &crtc->base.hwmode;
enum pipe pipe = crtc->pipe;
int position, vtotal;
vtotal = mode->crtc_vtotal;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
vtotal /= 2;
if (IS_GEN2(dev))
position = I915_READ_FW(PIPEDSL(pipe)) & DSL_LINEMASK_GEN2;
else
position = I915_READ_FW(PIPEDSL(pipe)) & DSL_LINEMASK_GEN3;
if (HAS_DDI(dev) && !position) {
int i, temp;
for (i = 0; i < 100; i++) {
udelay(1);
temp = __raw_i915_read32(dev_priv, PIPEDSL(pipe)) &
DSL_LINEMASK_GEN3;
if (temp != position) {
position = temp;
break;
}
}
}
return (position + crtc->scanline_offset) % vtotal;
}
static int i915_get_crtc_scanoutpos(struct drm_device *dev, unsigned int pipe,
unsigned int flags, int *vpos, int *hpos,
ktime_t *stime, ktime_t *etime,
const struct drm_display_mode *mode)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = dev_priv->pipe_to_crtc_mapping[pipe];
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int position;
int vbl_start, vbl_end, hsync_start, htotal, vtotal;
bool in_vbl = true;
int ret = 0;
unsigned long irqflags;
if (WARN_ON(!mode->crtc_clock)) {
DRM_DEBUG_DRIVER("trying to get scanoutpos for disabled "
"pipe %c\n", pipe_name(pipe));
return 0;
}
htotal = mode->crtc_htotal;
hsync_start = mode->crtc_hsync_start;
vtotal = mode->crtc_vtotal;
vbl_start = mode->crtc_vblank_start;
vbl_end = mode->crtc_vblank_end;
if (mode->flags & DRM_MODE_FLAG_INTERLACE) {
vbl_start = DIV_ROUND_UP(vbl_start, 2);
vbl_end /= 2;
vtotal /= 2;
}
ret |= DRM_SCANOUTPOS_VALID | DRM_SCANOUTPOS_ACCURATE;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
if (stime)
*stime = ktime_get();
if (IS_GEN2(dev) || IS_G4X(dev) || INTEL_INFO(dev)->gen >= 5) {
position = __intel_get_crtc_scanline(intel_crtc);
} else {
position = (I915_READ_FW(PIPEFRAMEPIXEL(pipe)) & PIPE_PIXEL_MASK) >> PIPE_PIXEL_SHIFT;
vbl_start *= htotal;
vbl_end *= htotal;
vtotal *= htotal;
if (position >= vtotal)
position = vtotal - 1;
position = (position + htotal - hsync_start) % vtotal;
}
if (etime)
*etime = ktime_get();
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
in_vbl = position >= vbl_start && position < vbl_end;
if (position >= vbl_start)
position -= vbl_end;
else
position += vtotal - vbl_end;
if (IS_GEN2(dev) || IS_G4X(dev) || INTEL_INFO(dev)->gen >= 5) {
*vpos = position;
*hpos = 0;
} else {
*vpos = position / htotal;
*hpos = position - (*vpos * htotal);
}
if (in_vbl)
ret |= DRM_SCANOUTPOS_IN_VBLANK;
return ret;
}
int intel_get_crtc_scanline(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
unsigned long irqflags;
int position;
spin_lock_irqsave(&dev_priv->uncore.lock, irqflags);
position = __intel_get_crtc_scanline(crtc);
spin_unlock_irqrestore(&dev_priv->uncore.lock, irqflags);
return position;
}
static int i915_get_vblank_timestamp(struct drm_device *dev, unsigned int pipe,
int *max_error,
struct timeval *vblank_time,
unsigned flags)
{
struct drm_crtc *crtc;
if (pipe >= INTEL_INFO(dev)->num_pipes) {
DRM_ERROR("Invalid crtc %u\n", pipe);
return -EINVAL;
}
crtc = intel_get_crtc_for_pipe(dev, pipe);
if (crtc == NULL) {
DRM_ERROR("Invalid crtc %u\n", pipe);
return -EINVAL;
}
if (!crtc->hwmode.crtc_clock) {
DRM_DEBUG_KMS("crtc %u is disabled\n", pipe);
return -EBUSY;
}
return drm_calc_vbltimestamp_from_scanoutpos(dev, pipe, max_error,
vblank_time, flags,
&crtc->hwmode);
}
static void ironlake_rps_change_irq_handler(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 busy_up, busy_down, max_avg, min_avg;
u8 new_delay;
spin_lock(&mchdev_lock);
I915_WRITE16(MEMINTRSTS, I915_READ(MEMINTRSTS));
new_delay = dev_priv->ips.cur_delay;
I915_WRITE16(MEMINTRSTS, MEMINT_EVAL_CHG);
busy_up = I915_READ(RCPREVBSYTUPAVG);
busy_down = I915_READ(RCPREVBSYTDNAVG);
max_avg = I915_READ(RCBMAXAVG);
min_avg = I915_READ(RCBMINAVG);
if (busy_up > max_avg) {
if (dev_priv->ips.cur_delay != dev_priv->ips.max_delay)
new_delay = dev_priv->ips.cur_delay - 1;
if (new_delay < dev_priv->ips.max_delay)
new_delay = dev_priv->ips.max_delay;
} else if (busy_down < min_avg) {
if (dev_priv->ips.cur_delay != dev_priv->ips.min_delay)
new_delay = dev_priv->ips.cur_delay + 1;
if (new_delay > dev_priv->ips.min_delay)
new_delay = dev_priv->ips.min_delay;
}
if (ironlake_set_drps(dev, new_delay))
dev_priv->ips.cur_delay = new_delay;
spin_unlock(&mchdev_lock);
return;
}
static void notify_ring(struct intel_engine_cs *ring)
{
if (!intel_ring_initialized(ring))
return;
trace_i915_gem_request_notify(ring);
wake_up_all(&ring->irq_queue);
}
static void vlv_c0_read(struct drm_i915_private *dev_priv,
struct intel_rps_ei *ei)
{
ei->cz_clock = vlv_punit_read(dev_priv, PUNIT_REG_CZ_TIMESTAMP);
ei->render_c0 = I915_READ(VLV_RENDER_C0_COUNT);
ei->media_c0 = I915_READ(VLV_MEDIA_C0_COUNT);
}
static bool vlv_c0_above(struct drm_i915_private *dev_priv,
const struct intel_rps_ei *old,
const struct intel_rps_ei *now,
int threshold)
{
u64 time, c0;
unsigned int mul = 100;
if (old->cz_clock == 0)
return false;
if (I915_READ(VLV_COUNTER_CONTROL) & VLV_COUNT_RANGE_HIGH)
mul <<= 8;
time = now->cz_clock - old->cz_clock;
time *= threshold * dev_priv->czclk_freq;
c0 = now->render_c0 - old->render_c0;
c0 += now->media_c0 - old->media_c0;
c0 *= mul * VLV_CZ_CLOCK_TO_MILLI_SEC;
return c0 >= time;
}
void gen6_rps_reset_ei(struct drm_i915_private *dev_priv)
{
vlv_c0_read(dev_priv, &dev_priv->rps.down_ei);
dev_priv->rps.up_ei = dev_priv->rps.down_ei;
}
static u32 vlv_wa_c0_ei(struct drm_i915_private *dev_priv, u32 pm_iir)
{
struct intel_rps_ei now;
u32 events = 0;
if ((pm_iir & (GEN6_PM_RP_DOWN_EI_EXPIRED | GEN6_PM_RP_UP_EI_EXPIRED)) == 0)
return 0;
vlv_c0_read(dev_priv, &now);
if (now.cz_clock == 0)
return 0;
if (pm_iir & GEN6_PM_RP_DOWN_EI_EXPIRED) {
if (!vlv_c0_above(dev_priv,
&dev_priv->rps.down_ei, &now,
dev_priv->rps.down_threshold))
events |= GEN6_PM_RP_DOWN_THRESHOLD;
dev_priv->rps.down_ei = now;
}
if (pm_iir & GEN6_PM_RP_UP_EI_EXPIRED) {
if (vlv_c0_above(dev_priv,
&dev_priv->rps.up_ei, &now,
dev_priv->rps.up_threshold))
events |= GEN6_PM_RP_UP_THRESHOLD;
dev_priv->rps.up_ei = now;
}
return events;
}
static bool any_waiters(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *ring;
int i;
for_each_ring(ring, dev_priv, i)
if (ring->irq_refcount)
return true;
return false;
}
static void gen6_pm_rps_work(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, struct drm_i915_private, rps.work);
bool client_boost;
int new_delay, adj, min, max;
u32 pm_iir;
spin_lock_irq(&dev_priv->irq_lock);
if (!dev_priv->rps.interrupts_enabled) {
spin_unlock_irq(&dev_priv->irq_lock);
return;
}
DISABLE_RPM_WAKEREF_ASSERTS(dev_priv);
pm_iir = dev_priv->rps.pm_iir;
dev_priv->rps.pm_iir = 0;
gen6_enable_pm_irq(dev_priv, dev_priv->pm_rps_events);
client_boost = dev_priv->rps.client_boost;
dev_priv->rps.client_boost = false;
spin_unlock_irq(&dev_priv->irq_lock);
WARN_ON(pm_iir & ~dev_priv->pm_rps_events);
if ((pm_iir & dev_priv->pm_rps_events) == 0 && !client_boost)
goto out;
mutex_lock(&dev_priv->rps.hw_lock);
pm_iir |= vlv_wa_c0_ei(dev_priv, pm_iir);
adj = dev_priv->rps.last_adj;
new_delay = dev_priv->rps.cur_freq;
min = dev_priv->rps.min_freq_softlimit;
max = dev_priv->rps.max_freq_softlimit;
if (client_boost) {
new_delay = dev_priv->rps.max_freq_softlimit;
adj = 0;
} else if (pm_iir & GEN6_PM_RP_UP_THRESHOLD) {
if (adj > 0)
adj *= 2;
else
adj = IS_CHERRYVIEW(dev_priv) ? 2 : 1;
if (new_delay < dev_priv->rps.efficient_freq - adj) {
new_delay = dev_priv->rps.efficient_freq;
adj = 0;
}
} else if (any_waiters(dev_priv)) {
adj = 0;
} else if (pm_iir & GEN6_PM_RP_DOWN_TIMEOUT) {
if (dev_priv->rps.cur_freq > dev_priv->rps.efficient_freq)
new_delay = dev_priv->rps.efficient_freq;
else
new_delay = dev_priv->rps.min_freq_softlimit;
adj = 0;
} else if (pm_iir & GEN6_PM_RP_DOWN_THRESHOLD) {
if (adj < 0)
adj *= 2;
else
adj = IS_CHERRYVIEW(dev_priv) ? -2 : -1;
} else {
adj = 0;
}
dev_priv->rps.last_adj = adj;
new_delay += adj;
new_delay = clamp_t(int, new_delay, min, max);
intel_set_rps(dev_priv->dev, new_delay);
mutex_unlock(&dev_priv->rps.hw_lock);
out:
ENABLE_RPM_WAKEREF_ASSERTS(dev_priv);
}
static void ivybridge_parity_work(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, struct drm_i915_private, l3_parity.error_work);
u32 error_status, row, bank, subbank;
char *parity_event[6];
uint32_t misccpctl;
uint8_t slice = 0;
mutex_lock(&dev_priv->dev->struct_mutex);
if (WARN_ON(!dev_priv->l3_parity.which_slice))
goto out;
misccpctl = I915_READ(GEN7_MISCCPCTL);
I915_WRITE(GEN7_MISCCPCTL, misccpctl & ~GEN7_DOP_CLOCK_GATE_ENABLE);
POSTING_READ(GEN7_MISCCPCTL);
while ((slice = ffs(dev_priv->l3_parity.which_slice)) != 0) {
i915_reg_t reg;
slice--;
if (WARN_ON_ONCE(slice >= NUM_L3_SLICES(dev_priv->dev)))
break;
dev_priv->l3_parity.which_slice &= ~(1<<slice);
reg = GEN7_L3CDERRST1(slice);
error_status = I915_READ(reg);
row = GEN7_PARITY_ERROR_ROW(error_status);
bank = GEN7_PARITY_ERROR_BANK(error_status);
subbank = GEN7_PARITY_ERROR_SUBBANK(error_status);
I915_WRITE(reg, GEN7_PARITY_ERROR_VALID | GEN7_L3CDERRST1_ENABLE);
POSTING_READ(reg);
parity_event[0] = I915_L3_PARITY_UEVENT "=1";
parity_event[1] = kasprintf(GFP_KERNEL, "ROW=%d", row);
parity_event[2] = kasprintf(GFP_KERNEL, "BANK=%d", bank);
parity_event[3] = kasprintf(GFP_KERNEL, "SUBBANK=%d", subbank);
parity_event[4] = kasprintf(GFP_KERNEL, "SLICE=%d", slice);
parity_event[5] = NULL;
kobject_uevent_env(&dev_priv->dev->primary->kdev->kobj,
KOBJ_CHANGE, parity_event);
DRM_DEBUG("Parity error: Slice = %d, Row = %d, Bank = %d, Sub bank = %d.\n",
slice, row, bank, subbank);
kfree(parity_event[4]);
kfree(parity_event[3]);
kfree(parity_event[2]);
kfree(parity_event[1]);
}
I915_WRITE(GEN7_MISCCPCTL, misccpctl);
out:
WARN_ON(dev_priv->l3_parity.which_slice);
spin_lock_irq(&dev_priv->irq_lock);
gen5_enable_gt_irq(dev_priv, GT_PARITY_ERROR(dev_priv->dev));
spin_unlock_irq(&dev_priv->irq_lock);
mutex_unlock(&dev_priv->dev->struct_mutex);
}
static void ivybridge_parity_error_irq_handler(struct drm_device *dev, u32 iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!HAS_L3_DPF(dev))
return;
spin_lock(&dev_priv->irq_lock);
gen5_disable_gt_irq(dev_priv, GT_PARITY_ERROR(dev));
spin_unlock(&dev_priv->irq_lock);
iir &= GT_PARITY_ERROR(dev);
if (iir & GT_RENDER_L3_PARITY_ERROR_INTERRUPT_S1)
dev_priv->l3_parity.which_slice |= 1 << 1;
if (iir & GT_RENDER_L3_PARITY_ERROR_INTERRUPT)
dev_priv->l3_parity.which_slice |= 1 << 0;
queue_work(dev_priv->wq, &dev_priv->l3_parity.error_work);
}
static void ilk_gt_irq_handler(struct drm_device *dev,
struct drm_i915_private *dev_priv,
u32 gt_iir)
{
if (gt_iir &
(GT_RENDER_USER_INTERRUPT | GT_RENDER_PIPECTL_NOTIFY_INTERRUPT))
notify_ring(&dev_priv->ring[RCS]);
if (gt_iir & ILK_BSD_USER_INTERRUPT)
notify_ring(&dev_priv->ring[VCS]);
}
static void snb_gt_irq_handler(struct drm_device *dev,
struct drm_i915_private *dev_priv,
u32 gt_iir)
{
if (gt_iir &
(GT_RENDER_USER_INTERRUPT | GT_RENDER_PIPECTL_NOTIFY_INTERRUPT))
notify_ring(&dev_priv->ring[RCS]);
if (gt_iir & GT_BSD_USER_INTERRUPT)
notify_ring(&dev_priv->ring[VCS]);
if (gt_iir & GT_BLT_USER_INTERRUPT)
notify_ring(&dev_priv->ring[BCS]);
if (gt_iir & (GT_BLT_CS_ERROR_INTERRUPT |
GT_BSD_CS_ERROR_INTERRUPT |
GT_RENDER_CS_MASTER_ERROR_INTERRUPT))
DRM_DEBUG("Command parser error, gt_iir 0x%08x\n", gt_iir);
if (gt_iir & GT_PARITY_ERROR(dev))
ivybridge_parity_error_irq_handler(dev, gt_iir);
}
static __always_inline void
gen8_cs_irq_handler(struct intel_engine_cs *ring, u32 iir, int test_shift)
{
if (iir & (GT_RENDER_USER_INTERRUPT << test_shift))
notify_ring(ring);
if (iir & (GT_CONTEXT_SWITCH_INTERRUPT << test_shift))
intel_lrc_irq_handler(ring);
}
static irqreturn_t gen8_gt_irq_handler(struct drm_i915_private *dev_priv,
u32 master_ctl)
{
irqreturn_t ret = IRQ_NONE;
if (master_ctl & (GEN8_GT_RCS_IRQ | GEN8_GT_BCS_IRQ)) {
u32 iir = I915_READ_FW(GEN8_GT_IIR(0));
if (iir) {
I915_WRITE_FW(GEN8_GT_IIR(0), iir);
ret = IRQ_HANDLED;
gen8_cs_irq_handler(&dev_priv->ring[RCS],
iir, GEN8_RCS_IRQ_SHIFT);
gen8_cs_irq_handler(&dev_priv->ring[BCS],
iir, GEN8_BCS_IRQ_SHIFT);
} else
DRM_ERROR("The master control interrupt lied (GT0)!\n");
}
if (master_ctl & (GEN8_GT_VCS1_IRQ | GEN8_GT_VCS2_IRQ)) {
u32 iir = I915_READ_FW(GEN8_GT_IIR(1));
if (iir) {
I915_WRITE_FW(GEN8_GT_IIR(1), iir);
ret = IRQ_HANDLED;
gen8_cs_irq_handler(&dev_priv->ring[VCS],
iir, GEN8_VCS1_IRQ_SHIFT);
gen8_cs_irq_handler(&dev_priv->ring[VCS2],
iir, GEN8_VCS2_IRQ_SHIFT);
} else
DRM_ERROR("The master control interrupt lied (GT1)!\n");
}
if (master_ctl & GEN8_GT_VECS_IRQ) {
u32 iir = I915_READ_FW(GEN8_GT_IIR(3));
if (iir) {
I915_WRITE_FW(GEN8_GT_IIR(3), iir);
ret = IRQ_HANDLED;
gen8_cs_irq_handler(&dev_priv->ring[VECS],
iir, GEN8_VECS_IRQ_SHIFT);
} else
DRM_ERROR("The master control interrupt lied (GT3)!\n");
}
if (master_ctl & GEN8_GT_PM_IRQ) {
u32 iir = I915_READ_FW(GEN8_GT_IIR(2));
if (iir & dev_priv->pm_rps_events) {
I915_WRITE_FW(GEN8_GT_IIR(2),
iir & dev_priv->pm_rps_events);
ret = IRQ_HANDLED;
gen6_rps_irq_handler(dev_priv, iir);
} else
DRM_ERROR("The master control interrupt lied (PM)!\n");
}
return ret;
}
static bool bxt_port_hotplug_long_detect(enum port port, u32 val)
{
switch (port) {
case PORT_A:
return val & PORTA_HOTPLUG_LONG_DETECT;
case PORT_B:
return val & PORTB_HOTPLUG_LONG_DETECT;
case PORT_C:
return val & PORTC_HOTPLUG_LONG_DETECT;
default:
return false;
}
}
static bool spt_port_hotplug2_long_detect(enum port port, u32 val)
{
switch (port) {
case PORT_E:
return val & PORTE_HOTPLUG_LONG_DETECT;
default:
return false;
}
}
static bool spt_port_hotplug_long_detect(enum port port, u32 val)
{
switch (port) {
case PORT_A:
return val & PORTA_HOTPLUG_LONG_DETECT;
case PORT_B:
return val & PORTB_HOTPLUG_LONG_DETECT;
case PORT_C:
return val & PORTC_HOTPLUG_LONG_DETECT;
case PORT_D:
return val & PORTD_HOTPLUG_LONG_DETECT;
default:
return false;
}
}
static bool ilk_port_hotplug_long_detect(enum port port, u32 val)
{
switch (port) {
case PORT_A:
return val & DIGITAL_PORTA_HOTPLUG_LONG_DETECT;
default:
return false;
}
}
static bool pch_port_hotplug_long_detect(enum port port, u32 val)
{
switch (port) {
case PORT_B:
return val & PORTB_HOTPLUG_LONG_DETECT;
case PORT_C:
return val & PORTC_HOTPLUG_LONG_DETECT;
case PORT_D:
return val & PORTD_HOTPLUG_LONG_DETECT;
default:
return false;
}
}
static bool i9xx_port_hotplug_long_detect(enum port port, u32 val)
{
switch (port) {
case PORT_B:
return val & PORTB_HOTPLUG_INT_LONG_PULSE;
case PORT_C:
return val & PORTC_HOTPLUG_INT_LONG_PULSE;
case PORT_D:
return val & PORTD_HOTPLUG_INT_LONG_PULSE;
default:
return false;
}
}
static void intel_get_hpd_pins(u32 *pin_mask, u32 *long_mask,
u32 hotplug_trigger, u32 dig_hotplug_reg,
const u32 hpd[HPD_NUM_PINS],
bool long_pulse_detect(enum port port, u32 val))
{
enum port port;
int i;
for_each_hpd_pin(i) {
if ((hpd[i] & hotplug_trigger) == 0)
continue;
*pin_mask |= BIT(i);
if (!intel_hpd_pin_to_port(i, &port))
continue;
if (long_pulse_detect(port, dig_hotplug_reg))
*long_mask |= BIT(i);
}
DRM_DEBUG_DRIVER("hotplug event received, stat 0x%08x, dig 0x%08x, pins 0x%08x\n",
hotplug_trigger, dig_hotplug_reg, *pin_mask);
}
static void gmbus_irq_handler(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
wake_up_all(&dev_priv->gmbus_wait_queue);
}
static void dp_aux_irq_handler(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
wake_up_all(&dev_priv->gmbus_wait_queue);
}
static void display_pipe_crc_irq_handler(struct drm_device *dev, enum pipe pipe,
uint32_t crc0, uint32_t crc1,
uint32_t crc2, uint32_t crc3,
uint32_t crc4)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_pipe_crc *pipe_crc = &dev_priv->pipe_crc[pipe];
struct intel_pipe_crc_entry *entry;
int head, tail;
spin_lock(&pipe_crc->lock);
if (!pipe_crc->entries) {
spin_unlock(&pipe_crc->lock);
DRM_DEBUG_KMS("spurious interrupt\n");
return;
}
head = pipe_crc->head;
tail = pipe_crc->tail;
if (CIRC_SPACE(head, tail, INTEL_PIPE_CRC_ENTRIES_NR) < 1) {
spin_unlock(&pipe_crc->lock);
DRM_ERROR("CRC buffer overflowing\n");
return;
}
entry = &pipe_crc->entries[head];
entry->frame = dev->driver->get_vblank_counter(dev, pipe);
entry->crc[0] = crc0;
entry->crc[1] = crc1;
entry->crc[2] = crc2;
entry->crc[3] = crc3;
entry->crc[4] = crc4;
head = (head + 1) & (INTEL_PIPE_CRC_ENTRIES_NR - 1);
pipe_crc->head = head;
spin_unlock(&pipe_crc->lock);
wake_up_interruptible(&pipe_crc->wq);
}
static inline void
display_pipe_crc_irq_handler(struct drm_device *dev, enum pipe pipe,
uint32_t crc0, uint32_t crc1,
uint32_t crc2, uint32_t crc3,
uint32_t crc4) {}
static void hsw_pipe_crc_irq_handler(struct drm_device *dev, enum pipe pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
display_pipe_crc_irq_handler(dev, pipe,
I915_READ(PIPE_CRC_RES_1_IVB(pipe)),
0, 0, 0, 0);
}
static void ivb_pipe_crc_irq_handler(struct drm_device *dev, enum pipe pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
display_pipe_crc_irq_handler(dev, pipe,
I915_READ(PIPE_CRC_RES_1_IVB(pipe)),
I915_READ(PIPE_CRC_RES_2_IVB(pipe)),
I915_READ(PIPE_CRC_RES_3_IVB(pipe)),
I915_READ(PIPE_CRC_RES_4_IVB(pipe)),
I915_READ(PIPE_CRC_RES_5_IVB(pipe)));
}
static void i9xx_pipe_crc_irq_handler(struct drm_device *dev, enum pipe pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t res1, res2;
if (INTEL_INFO(dev)->gen >= 3)
res1 = I915_READ(PIPE_CRC_RES_RES1_I915(pipe));
else
res1 = 0;
if (INTEL_INFO(dev)->gen >= 5 || IS_G4X(dev))
res2 = I915_READ(PIPE_CRC_RES_RES2_G4X(pipe));
else
res2 = 0;
display_pipe_crc_irq_handler(dev, pipe,
I915_READ(PIPE_CRC_RES_RED(pipe)),
I915_READ(PIPE_CRC_RES_GREEN(pipe)),
I915_READ(PIPE_CRC_RES_BLUE(pipe)),
res1, res2);
}
static void gen6_rps_irq_handler(struct drm_i915_private *dev_priv, u32 pm_iir)
{
if (pm_iir & dev_priv->pm_rps_events) {
spin_lock(&dev_priv->irq_lock);
gen6_disable_pm_irq(dev_priv, pm_iir & dev_priv->pm_rps_events);
if (dev_priv->rps.interrupts_enabled) {
dev_priv->rps.pm_iir |= pm_iir & dev_priv->pm_rps_events;
queue_work(dev_priv->wq, &dev_priv->rps.work);
}
spin_unlock(&dev_priv->irq_lock);
}
if (INTEL_INFO(dev_priv)->gen >= 8)
return;
if (HAS_VEBOX(dev_priv->dev)) {
if (pm_iir & PM_VEBOX_USER_INTERRUPT)
notify_ring(&dev_priv->ring[VECS]);
if (pm_iir & PM_VEBOX_CS_ERROR_INTERRUPT)
DRM_DEBUG("Command parser error, pm_iir 0x%08x\n", pm_iir);
}
}
static bool intel_pipe_handle_vblank(struct drm_device *dev, enum pipe pipe)
{
if (!drm_handle_vblank(dev, pipe))
return false;
return true;
}
static void valleyview_pipestat_irq_handler(struct drm_device *dev, u32 iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 pipe_stats[I915_MAX_PIPES] = { };
int pipe;
spin_lock(&dev_priv->irq_lock);
if (!dev_priv->display_irqs_enabled) {
spin_unlock(&dev_priv->irq_lock);
return;
}
for_each_pipe(dev_priv, pipe) {
i915_reg_t reg;
u32 mask, iir_bit = 0;
mask = PIPE_FIFO_UNDERRUN_STATUS;
switch (pipe) {
case PIPE_A:
iir_bit = I915_DISPLAY_PIPE_A_EVENT_INTERRUPT;
break;
case PIPE_B:
iir_bit = I915_DISPLAY_PIPE_B_EVENT_INTERRUPT;
break;
case PIPE_C:
iir_bit = I915_DISPLAY_PIPE_C_EVENT_INTERRUPT;
break;
}
if (iir & iir_bit)
mask |= dev_priv->pipestat_irq_mask[pipe];
if (!mask)
continue;
reg = PIPESTAT(pipe);
mask |= PIPESTAT_INT_ENABLE_MASK;
pipe_stats[pipe] = I915_READ(reg) & mask;
if (pipe_stats[pipe] & (PIPE_FIFO_UNDERRUN_STATUS |
PIPESTAT_INT_STATUS_MASK))
I915_WRITE(reg, pipe_stats[pipe]);
}
spin_unlock(&dev_priv->irq_lock);
for_each_pipe(dev_priv, pipe) {
if (pipe_stats[pipe] & PIPE_START_VBLANK_INTERRUPT_STATUS &&
intel_pipe_handle_vblank(dev, pipe))
intel_check_page_flip(dev, pipe);
if (pipe_stats[pipe] & PLANE_FLIP_DONE_INT_STATUS_VLV) {
intel_prepare_page_flip(dev, pipe);
intel_finish_page_flip(dev, pipe);
}
if (pipe_stats[pipe] & PIPE_CRC_DONE_INTERRUPT_STATUS)
i9xx_pipe_crc_irq_handler(dev, pipe);
if (pipe_stats[pipe] & PIPE_FIFO_UNDERRUN_STATUS)
intel_cpu_fifo_underrun_irq_handler(dev_priv, pipe);
}
if (pipe_stats[0] & PIPE_GMBUS_INTERRUPT_STATUS)
gmbus_irq_handler(dev);
}
static void i9xx_hpd_irq_handler(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hotplug_status = I915_READ(PORT_HOTPLUG_STAT);
u32 pin_mask = 0, long_mask = 0;
if (!hotplug_status)
return;
I915_WRITE(PORT_HOTPLUG_STAT, hotplug_status);
POSTING_READ(PORT_HOTPLUG_STAT);
if (IS_G4X(dev) || IS_VALLEYVIEW(dev) || IS_CHERRYVIEW(dev)) {
u32 hotplug_trigger = hotplug_status & HOTPLUG_INT_STATUS_G4X;
if (hotplug_trigger) {
intel_get_hpd_pins(&pin_mask, &long_mask, hotplug_trigger,
hotplug_trigger, hpd_status_g4x,
i9xx_port_hotplug_long_detect);
intel_hpd_irq_handler(dev, pin_mask, long_mask);
}
if (hotplug_status & DP_AUX_CHANNEL_MASK_INT_STATUS_G4X)
dp_aux_irq_handler(dev);
} else {
u32 hotplug_trigger = hotplug_status & HOTPLUG_INT_STATUS_I915;
if (hotplug_trigger) {
intel_get_hpd_pins(&pin_mask, &long_mask, hotplug_trigger,
hotplug_trigger, hpd_status_i915,
i9xx_port_hotplug_long_detect);
intel_hpd_irq_handler(dev, pin_mask, long_mask);
}
}
}
static irqreturn_t valleyview_irq_handler(int irq, void *arg)
{
struct drm_device *dev = arg;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 iir, gt_iir, pm_iir;
irqreturn_t ret = IRQ_NONE;
if (!intel_irqs_enabled(dev_priv))
return IRQ_NONE;
disable_rpm_wakeref_asserts(dev_priv);
while (true) {
gt_iir = I915_READ(GTIIR);
if (gt_iir)
I915_WRITE(GTIIR, gt_iir);
pm_iir = I915_READ(GEN6_PMIIR);
if (pm_iir)
I915_WRITE(GEN6_PMIIR, pm_iir);
iir = I915_READ(VLV_IIR);
if (iir) {
if (iir & I915_DISPLAY_PORT_INTERRUPT)
i9xx_hpd_irq_handler(dev);
I915_WRITE(VLV_IIR, iir);
}
if (gt_iir == 0 && pm_iir == 0 && iir == 0)
goto out;
ret = IRQ_HANDLED;
if (gt_iir)
snb_gt_irq_handler(dev, dev_priv, gt_iir);
if (pm_iir)
gen6_rps_irq_handler(dev_priv, pm_iir);
valleyview_pipestat_irq_handler(dev, iir);
}
out:
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
static irqreturn_t cherryview_irq_handler(int irq, void *arg)
{
struct drm_device *dev = arg;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 master_ctl, iir;
irqreturn_t ret = IRQ_NONE;
if (!intel_irqs_enabled(dev_priv))
return IRQ_NONE;
disable_rpm_wakeref_asserts(dev_priv);
do {
master_ctl = I915_READ(GEN8_MASTER_IRQ) & ~GEN8_MASTER_IRQ_CONTROL;
iir = I915_READ(VLV_IIR);
if (master_ctl == 0 && iir == 0)
break;
ret = IRQ_HANDLED;
I915_WRITE(GEN8_MASTER_IRQ, 0);
if (iir) {
if (iir & I915_DISPLAY_PORT_INTERRUPT)
i9xx_hpd_irq_handler(dev);
I915_WRITE(VLV_IIR, iir);
}
gen8_gt_irq_handler(dev_priv, master_ctl);
valleyview_pipestat_irq_handler(dev, iir);
I915_WRITE(GEN8_MASTER_IRQ, DE_MASTER_IRQ_CONTROL);
POSTING_READ(GEN8_MASTER_IRQ);
} while (0);
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
static void ibx_hpd_irq_handler(struct drm_device *dev, u32 hotplug_trigger,
const u32 hpd[HPD_NUM_PINS])
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 dig_hotplug_reg, pin_mask = 0, long_mask = 0;
dig_hotplug_reg = I915_READ(PCH_PORT_HOTPLUG);
if (!hotplug_trigger) {
u32 mask = PORTA_HOTPLUG_STATUS_MASK |
PORTD_HOTPLUG_STATUS_MASK |
PORTC_HOTPLUG_STATUS_MASK |
PORTB_HOTPLUG_STATUS_MASK;
dig_hotplug_reg &= ~mask;
}
I915_WRITE(PCH_PORT_HOTPLUG, dig_hotplug_reg);
if (!hotplug_trigger)
return;
intel_get_hpd_pins(&pin_mask, &long_mask, hotplug_trigger,
dig_hotplug_reg, hpd,
pch_port_hotplug_long_detect);
intel_hpd_irq_handler(dev, pin_mask, long_mask);
}
static void ibx_irq_handler(struct drm_device *dev, u32 pch_iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
u32 hotplug_trigger = pch_iir & SDE_HOTPLUG_MASK;
ibx_hpd_irq_handler(dev, hotplug_trigger, hpd_ibx);
if (pch_iir & SDE_AUDIO_POWER_MASK) {
int port = ffs((pch_iir & SDE_AUDIO_POWER_MASK) >>
SDE_AUDIO_POWER_SHIFT);
DRM_DEBUG_DRIVER("PCH audio power change on port %d\n",
port_name(port));
}
if (pch_iir & SDE_AUX_MASK)
dp_aux_irq_handler(dev);
if (pch_iir & SDE_GMBUS)
gmbus_irq_handler(dev);
if (pch_iir & SDE_AUDIO_HDCP_MASK)
DRM_DEBUG_DRIVER("PCH HDCP audio interrupt\n");
if (pch_iir & SDE_AUDIO_TRANS_MASK)
DRM_DEBUG_DRIVER("PCH transcoder audio interrupt\n");
if (pch_iir & SDE_POISON)
DRM_ERROR("PCH poison interrupt\n");
if (pch_iir & SDE_FDI_MASK)
for_each_pipe(dev_priv, pipe)
DRM_DEBUG_DRIVER(" pipe %c FDI IIR: 0x%08x\n",
pipe_name(pipe),
I915_READ(FDI_RX_IIR(pipe)));
if (pch_iir & (SDE_TRANSB_CRC_DONE | SDE_TRANSA_CRC_DONE))
DRM_DEBUG_DRIVER("PCH transcoder CRC done interrupt\n");
if (pch_iir & (SDE_TRANSB_CRC_ERR | SDE_TRANSA_CRC_ERR))
DRM_DEBUG_DRIVER("PCH transcoder CRC error interrupt\n");
if (pch_iir & SDE_TRANSA_FIFO_UNDER)
intel_pch_fifo_underrun_irq_handler(dev_priv, TRANSCODER_A);
if (pch_iir & SDE_TRANSB_FIFO_UNDER)
intel_pch_fifo_underrun_irq_handler(dev_priv, TRANSCODER_B);
}
static void ivb_err_int_handler(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 err_int = I915_READ(GEN7_ERR_INT);
enum pipe pipe;
if (err_int & ERR_INT_POISON)
DRM_ERROR("Poison interrupt\n");
for_each_pipe(dev_priv, pipe) {
if (err_int & ERR_INT_FIFO_UNDERRUN(pipe))
intel_cpu_fifo_underrun_irq_handler(dev_priv, pipe);
if (err_int & ERR_INT_PIPE_CRC_DONE(pipe)) {
if (IS_IVYBRIDGE(dev))
ivb_pipe_crc_irq_handler(dev, pipe);
else
hsw_pipe_crc_irq_handler(dev, pipe);
}
}
I915_WRITE(GEN7_ERR_INT, err_int);
}
static void cpt_serr_int_handler(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 serr_int = I915_READ(SERR_INT);
if (serr_int & SERR_INT_POISON)
DRM_ERROR("PCH poison interrupt\n");
if (serr_int & SERR_INT_TRANS_A_FIFO_UNDERRUN)
intel_pch_fifo_underrun_irq_handler(dev_priv, TRANSCODER_A);
if (serr_int & SERR_INT_TRANS_B_FIFO_UNDERRUN)
intel_pch_fifo_underrun_irq_handler(dev_priv, TRANSCODER_B);
if (serr_int & SERR_INT_TRANS_C_FIFO_UNDERRUN)
intel_pch_fifo_underrun_irq_handler(dev_priv, TRANSCODER_C);
I915_WRITE(SERR_INT, serr_int);
}
static void cpt_irq_handler(struct drm_device *dev, u32 pch_iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
u32 hotplug_trigger = pch_iir & SDE_HOTPLUG_MASK_CPT;
ibx_hpd_irq_handler(dev, hotplug_trigger, hpd_cpt);
if (pch_iir & SDE_AUDIO_POWER_MASK_CPT) {
int port = ffs((pch_iir & SDE_AUDIO_POWER_MASK_CPT) >>
SDE_AUDIO_POWER_SHIFT_CPT);
DRM_DEBUG_DRIVER("PCH audio power change on port %c\n",
port_name(port));
}
if (pch_iir & SDE_AUX_MASK_CPT)
dp_aux_irq_handler(dev);
if (pch_iir & SDE_GMBUS_CPT)
gmbus_irq_handler(dev);
if (pch_iir & SDE_AUDIO_CP_REQ_CPT)
DRM_DEBUG_DRIVER("Audio CP request interrupt\n");
if (pch_iir & SDE_AUDIO_CP_CHG_CPT)
DRM_DEBUG_DRIVER("Audio CP change interrupt\n");
if (pch_iir & SDE_FDI_MASK_CPT)
for_each_pipe(dev_priv, pipe)
DRM_DEBUG_DRIVER(" pipe %c FDI IIR: 0x%08x\n",
pipe_name(pipe),
I915_READ(FDI_RX_IIR(pipe)));
if (pch_iir & SDE_ERROR_CPT)
cpt_serr_int_handler(dev);
}
static void spt_irq_handler(struct drm_device *dev, u32 pch_iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hotplug_trigger = pch_iir & SDE_HOTPLUG_MASK_SPT &
~SDE_PORTE_HOTPLUG_SPT;
u32 hotplug2_trigger = pch_iir & SDE_PORTE_HOTPLUG_SPT;
u32 pin_mask = 0, long_mask = 0;
if (hotplug_trigger) {
u32 dig_hotplug_reg;
dig_hotplug_reg = I915_READ(PCH_PORT_HOTPLUG);
I915_WRITE(PCH_PORT_HOTPLUG, dig_hotplug_reg);
intel_get_hpd_pins(&pin_mask, &long_mask, hotplug_trigger,
dig_hotplug_reg, hpd_spt,
spt_port_hotplug_long_detect);
}
if (hotplug2_trigger) {
u32 dig_hotplug_reg;
dig_hotplug_reg = I915_READ(PCH_PORT_HOTPLUG2);
I915_WRITE(PCH_PORT_HOTPLUG2, dig_hotplug_reg);
intel_get_hpd_pins(&pin_mask, &long_mask, hotplug2_trigger,
dig_hotplug_reg, hpd_spt,
spt_port_hotplug2_long_detect);
}
if (pin_mask)
intel_hpd_irq_handler(dev, pin_mask, long_mask);
if (pch_iir & SDE_GMBUS_CPT)
gmbus_irq_handler(dev);
}
static void ilk_hpd_irq_handler(struct drm_device *dev, u32 hotplug_trigger,
const u32 hpd[HPD_NUM_PINS])
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 dig_hotplug_reg, pin_mask = 0, long_mask = 0;
dig_hotplug_reg = I915_READ(DIGITAL_PORT_HOTPLUG_CNTRL);
I915_WRITE(DIGITAL_PORT_HOTPLUG_CNTRL, dig_hotplug_reg);
intel_get_hpd_pins(&pin_mask, &long_mask, hotplug_trigger,
dig_hotplug_reg, hpd,
ilk_port_hotplug_long_detect);
intel_hpd_irq_handler(dev, pin_mask, long_mask);
}
static void ilk_display_irq_handler(struct drm_device *dev, u32 de_iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe;
u32 hotplug_trigger = de_iir & DE_DP_A_HOTPLUG;
if (hotplug_trigger)
ilk_hpd_irq_handler(dev, hotplug_trigger, hpd_ilk);
if (de_iir & DE_AUX_CHANNEL_A)
dp_aux_irq_handler(dev);
if (de_iir & DE_GSE)
intel_opregion_asle_intr(dev);
if (de_iir & DE_POISON)
DRM_ERROR("Poison interrupt\n");
for_each_pipe(dev_priv, pipe) {
if (de_iir & DE_PIPE_VBLANK(pipe) &&
intel_pipe_handle_vblank(dev, pipe))
intel_check_page_flip(dev, pipe);
if (de_iir & DE_PIPE_FIFO_UNDERRUN(pipe))
intel_cpu_fifo_underrun_irq_handler(dev_priv, pipe);
if (de_iir & DE_PIPE_CRC_DONE(pipe))
i9xx_pipe_crc_irq_handler(dev, pipe);
if (de_iir & DE_PLANE_FLIP_DONE(pipe)) {
intel_prepare_page_flip(dev, pipe);
intel_finish_page_flip_plane(dev, pipe);
}
}
if (de_iir & DE_PCH_EVENT) {
u32 pch_iir = I915_READ(SDEIIR);
if (HAS_PCH_CPT(dev))
cpt_irq_handler(dev, pch_iir);
else
ibx_irq_handler(dev, pch_iir);
I915_WRITE(SDEIIR, pch_iir);
}
if (IS_GEN5(dev) && de_iir & DE_PCU_EVENT)
ironlake_rps_change_irq_handler(dev);
}
static void ivb_display_irq_handler(struct drm_device *dev, u32 de_iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe;
u32 hotplug_trigger = de_iir & DE_DP_A_HOTPLUG_IVB;
if (hotplug_trigger)
ilk_hpd_irq_handler(dev, hotplug_trigger, hpd_ivb);
if (de_iir & DE_ERR_INT_IVB)
ivb_err_int_handler(dev);
if (de_iir & DE_AUX_CHANNEL_A_IVB)
dp_aux_irq_handler(dev);
if (de_iir & DE_GSE_IVB)
intel_opregion_asle_intr(dev);
for_each_pipe(dev_priv, pipe) {
if (de_iir & (DE_PIPE_VBLANK_IVB(pipe)) &&
intel_pipe_handle_vblank(dev, pipe))
intel_check_page_flip(dev, pipe);
if (de_iir & DE_PLANE_FLIP_DONE_IVB(pipe)) {
intel_prepare_page_flip(dev, pipe);
intel_finish_page_flip_plane(dev, pipe);
}
}
if (!HAS_PCH_NOP(dev) && (de_iir & DE_PCH_EVENT_IVB)) {
u32 pch_iir = I915_READ(SDEIIR);
cpt_irq_handler(dev, pch_iir);
I915_WRITE(SDEIIR, pch_iir);
}
}
static irqreturn_t ironlake_irq_handler(int irq, void *arg)
{
struct drm_device *dev = arg;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 de_iir, gt_iir, de_ier, sde_ier = 0;
irqreturn_t ret = IRQ_NONE;
if (!intel_irqs_enabled(dev_priv))
return IRQ_NONE;
disable_rpm_wakeref_asserts(dev_priv);
de_ier = I915_READ(DEIER);
I915_WRITE(DEIER, de_ier & ~DE_MASTER_IRQ_CONTROL);
POSTING_READ(DEIER);
if (!HAS_PCH_NOP(dev)) {
sde_ier = I915_READ(SDEIER);
I915_WRITE(SDEIER, 0);
POSTING_READ(SDEIER);
}
gt_iir = I915_READ(GTIIR);
if (gt_iir) {
I915_WRITE(GTIIR, gt_iir);
ret = IRQ_HANDLED;
if (INTEL_INFO(dev)->gen >= 6)
snb_gt_irq_handler(dev, dev_priv, gt_iir);
else
ilk_gt_irq_handler(dev, dev_priv, gt_iir);
}
de_iir = I915_READ(DEIIR);
if (de_iir) {
I915_WRITE(DEIIR, de_iir);
ret = IRQ_HANDLED;
if (INTEL_INFO(dev)->gen >= 7)
ivb_display_irq_handler(dev, de_iir);
else
ilk_display_irq_handler(dev, de_iir);
}
if (INTEL_INFO(dev)->gen >= 6) {
u32 pm_iir = I915_READ(GEN6_PMIIR);
if (pm_iir) {
I915_WRITE(GEN6_PMIIR, pm_iir);
ret = IRQ_HANDLED;
gen6_rps_irq_handler(dev_priv, pm_iir);
}
}
I915_WRITE(DEIER, de_ier);
POSTING_READ(DEIER);
if (!HAS_PCH_NOP(dev)) {
I915_WRITE(SDEIER, sde_ier);
POSTING_READ(SDEIER);
}
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
static void bxt_hpd_irq_handler(struct drm_device *dev, u32 hotplug_trigger,
const u32 hpd[HPD_NUM_PINS])
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 dig_hotplug_reg, pin_mask = 0, long_mask = 0;
dig_hotplug_reg = I915_READ(PCH_PORT_HOTPLUG);
I915_WRITE(PCH_PORT_HOTPLUG, dig_hotplug_reg);
intel_get_hpd_pins(&pin_mask, &long_mask, hotplug_trigger,
dig_hotplug_reg, hpd,
bxt_port_hotplug_long_detect);
intel_hpd_irq_handler(dev, pin_mask, long_mask);
}
static irqreturn_t
gen8_de_irq_handler(struct drm_i915_private *dev_priv, u32 master_ctl)
{
struct drm_device *dev = dev_priv->dev;
irqreturn_t ret = IRQ_NONE;
u32 iir;
enum pipe pipe;
if (master_ctl & GEN8_DE_MISC_IRQ) {
iir = I915_READ(GEN8_DE_MISC_IIR);
if (iir) {
I915_WRITE(GEN8_DE_MISC_IIR, iir);
ret = IRQ_HANDLED;
if (iir & GEN8_DE_MISC_GSE)
intel_opregion_asle_intr(dev);
else
DRM_ERROR("Unexpected DE Misc interrupt\n");
}
else
DRM_ERROR("The master control interrupt lied (DE MISC)!\n");
}
if (master_ctl & GEN8_DE_PORT_IRQ) {
iir = I915_READ(GEN8_DE_PORT_IIR);
if (iir) {
u32 tmp_mask;
bool found = false;
I915_WRITE(GEN8_DE_PORT_IIR, iir);
ret = IRQ_HANDLED;
tmp_mask = GEN8_AUX_CHANNEL_A;
if (INTEL_INFO(dev_priv)->gen >= 9)
tmp_mask |= GEN9_AUX_CHANNEL_B |
GEN9_AUX_CHANNEL_C |
GEN9_AUX_CHANNEL_D;
if (iir & tmp_mask) {
dp_aux_irq_handler(dev);
found = true;
}
if (IS_BROXTON(dev_priv)) {
tmp_mask = iir & BXT_DE_PORT_HOTPLUG_MASK;
if (tmp_mask) {
bxt_hpd_irq_handler(dev, tmp_mask, hpd_bxt);
found = true;
}
} else if (IS_BROADWELL(dev_priv)) {
tmp_mask = iir & GEN8_PORT_DP_A_HOTPLUG;
if (tmp_mask) {
ilk_hpd_irq_handler(dev, tmp_mask, hpd_bdw);
found = true;
}
}
if (IS_BROXTON(dev) && (iir & BXT_DE_PORT_GMBUS)) {
gmbus_irq_handler(dev);
found = true;
}
if (!found)
DRM_ERROR("Unexpected DE Port interrupt\n");
}
else
DRM_ERROR("The master control interrupt lied (DE PORT)!\n");
}
for_each_pipe(dev_priv, pipe) {
u32 flip_done, fault_errors;
if (!(master_ctl & GEN8_DE_PIPE_IRQ(pipe)))
continue;
iir = I915_READ(GEN8_DE_PIPE_IIR(pipe));
if (!iir) {
DRM_ERROR("The master control interrupt lied (DE PIPE)!\n");
continue;
}
ret = IRQ_HANDLED;
I915_WRITE(GEN8_DE_PIPE_IIR(pipe), iir);
if (iir & GEN8_PIPE_VBLANK &&
intel_pipe_handle_vblank(dev, pipe))
intel_check_page_flip(dev, pipe);
flip_done = iir;
if (INTEL_INFO(dev_priv)->gen >= 9)
flip_done &= GEN9_PIPE_PLANE1_FLIP_DONE;
else
flip_done &= GEN8_PIPE_PRIMARY_FLIP_DONE;
if (flip_done) {
intel_prepare_page_flip(dev, pipe);
intel_finish_page_flip_plane(dev, pipe);
}
if (iir & GEN8_PIPE_CDCLK_CRC_DONE)
hsw_pipe_crc_irq_handler(dev, pipe);
if (iir & GEN8_PIPE_FIFO_UNDERRUN)
intel_cpu_fifo_underrun_irq_handler(dev_priv, pipe);
fault_errors = iir;
if (INTEL_INFO(dev_priv)->gen >= 9)
fault_errors &= GEN9_DE_PIPE_IRQ_FAULT_ERRORS;
else
fault_errors &= GEN8_DE_PIPE_IRQ_FAULT_ERRORS;
if (fault_errors)
DRM_ERROR("Fault errors on pipe %c\n: 0x%08x",
pipe_name(pipe),
fault_errors);
}
if (HAS_PCH_SPLIT(dev) && !HAS_PCH_NOP(dev) &&
master_ctl & GEN8_DE_PCH_IRQ) {
iir = I915_READ(SDEIIR);
if (iir) {
I915_WRITE(SDEIIR, iir);
ret = IRQ_HANDLED;
if (HAS_PCH_SPT(dev_priv))
spt_irq_handler(dev, iir);
else
cpt_irq_handler(dev, iir);
} else {
DRM_DEBUG_DRIVER("The master control interrupt lied (SDE)!\n");
}
}
return ret;
}
static irqreturn_t gen8_irq_handler(int irq, void *arg)
{
struct drm_device *dev = arg;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 master_ctl;
irqreturn_t ret;
if (!intel_irqs_enabled(dev_priv))
return IRQ_NONE;
master_ctl = I915_READ_FW(GEN8_MASTER_IRQ);
master_ctl &= ~GEN8_MASTER_IRQ_CONTROL;
if (!master_ctl)
return IRQ_NONE;
I915_WRITE_FW(GEN8_MASTER_IRQ, 0);
disable_rpm_wakeref_asserts(dev_priv);
ret = gen8_gt_irq_handler(dev_priv, master_ctl);
ret |= gen8_de_irq_handler(dev_priv, master_ctl);
I915_WRITE_FW(GEN8_MASTER_IRQ, GEN8_MASTER_IRQ_CONTROL);
POSTING_READ_FW(GEN8_MASTER_IRQ);
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
static void i915_error_wake_up(struct drm_i915_private *dev_priv,
bool reset_completed)
{
struct intel_engine_cs *ring;
int i;
for_each_ring(ring, dev_priv, i)
wake_up_all(&ring->irq_queue);
wake_up_all(&dev_priv->pending_flip_queue);
if (reset_completed)
wake_up_all(&dev_priv->gpu_error.reset_queue);
}
static void i915_reset_and_wakeup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_gpu_error *error = &dev_priv->gpu_error;
char *error_event[] = { I915_ERROR_UEVENT "=1", NULL };
char *reset_event[] = { I915_RESET_UEVENT "=1", NULL };
char *reset_done_event[] = { I915_ERROR_UEVENT "=0", NULL };
int ret;
kobject_uevent_env(&dev->primary->kdev->kobj, KOBJ_CHANGE, error_event);
if (i915_reset_in_progress(error) && !i915_terminally_wedged(error)) {
DRM_DEBUG_DRIVER("resetting chip\n");
kobject_uevent_env(&dev->primary->kdev->kobj, KOBJ_CHANGE,
reset_event);
intel_runtime_pm_get(dev_priv);
intel_prepare_reset(dev);
ret = i915_reset(dev);
intel_finish_reset(dev);
intel_runtime_pm_put(dev_priv);
if (ret == 0) {
smp_mb__before_atomic();
atomic_inc(&dev_priv->gpu_error.reset_counter);
kobject_uevent_env(&dev->primary->kdev->kobj,
KOBJ_CHANGE, reset_done_event);
} else {
atomic_or(I915_WEDGED, &error->reset_counter);
}
i915_error_wake_up(dev_priv, true);
}
}
static void i915_report_and_clear_eir(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t instdone[I915_NUM_INSTDONE_REG];
u32 eir = I915_READ(EIR);
int pipe, i;
if (!eir)
return;
pr_err("render error detected, EIR: 0x%08x\n", eir);
i915_get_extra_instdone(dev, instdone);
if (IS_G4X(dev)) {
if (eir & (GM45_ERROR_MEM_PRIV | GM45_ERROR_CP_PRIV)) {
u32 ipeir = I915_READ(IPEIR_I965);
pr_err(" IPEIR: 0x%08x\n", I915_READ(IPEIR_I965));
pr_err(" IPEHR: 0x%08x\n", I915_READ(IPEHR_I965));
for (i = 0; i < ARRAY_SIZE(instdone); i++)
pr_err(" INSTDONE_%d: 0x%08x\n", i, instdone[i]);
pr_err(" INSTPS: 0x%08x\n", I915_READ(INSTPS));
pr_err(" ACTHD: 0x%08x\n", I915_READ(ACTHD_I965));
I915_WRITE(IPEIR_I965, ipeir);
POSTING_READ(IPEIR_I965);
}
if (eir & GM45_ERROR_PAGE_TABLE) {
u32 pgtbl_err = I915_READ(PGTBL_ER);
pr_err("page table error\n");
pr_err(" PGTBL_ER: 0x%08x\n", pgtbl_err);
I915_WRITE(PGTBL_ER, pgtbl_err);
POSTING_READ(PGTBL_ER);
}
}
if (!IS_GEN2(dev)) {
if (eir & I915_ERROR_PAGE_TABLE) {
u32 pgtbl_err = I915_READ(PGTBL_ER);
pr_err("page table error\n");
pr_err(" PGTBL_ER: 0x%08x\n", pgtbl_err);
I915_WRITE(PGTBL_ER, pgtbl_err);
POSTING_READ(PGTBL_ER);
}
}
if (eir & I915_ERROR_MEMORY_REFRESH) {
pr_err("memory refresh error:\n");
for_each_pipe(dev_priv, pipe)
pr_err("pipe %c stat: 0x%08x\n",
pipe_name(pipe), I915_READ(PIPESTAT(pipe)));
}
if (eir & I915_ERROR_INSTRUCTION) {
pr_err("instruction error\n");
pr_err(" INSTPM: 0x%08x\n", I915_READ(INSTPM));
for (i = 0; i < ARRAY_SIZE(instdone); i++)
pr_err(" INSTDONE_%d: 0x%08x\n", i, instdone[i]);
if (INTEL_INFO(dev)->gen < 4) {
u32 ipeir = I915_READ(IPEIR);
pr_err(" IPEIR: 0x%08x\n", I915_READ(IPEIR));
pr_err(" IPEHR: 0x%08x\n", I915_READ(IPEHR));
pr_err(" ACTHD: 0x%08x\n", I915_READ(ACTHD));
I915_WRITE(IPEIR, ipeir);
POSTING_READ(IPEIR);
} else {
u32 ipeir = I915_READ(IPEIR_I965);
pr_err(" IPEIR: 0x%08x\n", I915_READ(IPEIR_I965));
pr_err(" IPEHR: 0x%08x\n", I915_READ(IPEHR_I965));
pr_err(" INSTPS: 0x%08x\n", I915_READ(INSTPS));
pr_err(" ACTHD: 0x%08x\n", I915_READ(ACTHD_I965));
I915_WRITE(IPEIR_I965, ipeir);
POSTING_READ(IPEIR_I965);
}
}
I915_WRITE(EIR, eir);
POSTING_READ(EIR);
eir = I915_READ(EIR);
if (eir) {
DRM_ERROR("EIR stuck: 0x%08x, masking\n", eir);
I915_WRITE(EMR, I915_READ(EMR) | eir);
I915_WRITE(IIR, I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT);
}
}
void i915_handle_error(struct drm_device *dev, bool wedged,
const char *fmt, ...)
{
struct drm_i915_private *dev_priv = dev->dev_private;
va_list args;
char error_msg[80];
va_start(args, fmt);
vscnprintf(error_msg, sizeof(error_msg), fmt, args);
va_end(args);
i915_capture_error_state(dev, wedged, error_msg);
i915_report_and_clear_eir(dev);
if (wedged) {
atomic_or(I915_RESET_IN_PROGRESS_FLAG,
&dev_priv->gpu_error.reset_counter);
i915_error_wake_up(dev_priv, false);
}
i915_reset_and_wakeup(dev);
}
static int i915_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
if (INTEL_INFO(dev)->gen >= 4)
i915_enable_pipestat(dev_priv, pipe,
PIPE_START_VBLANK_INTERRUPT_STATUS);
else
i915_enable_pipestat(dev_priv, pipe,
PIPE_VBLANK_INTERRUPT_STATUS);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
return 0;
}
static int ironlake_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
uint32_t bit = (INTEL_INFO(dev)->gen >= 7) ? DE_PIPE_VBLANK_IVB(pipe) :
DE_PIPE_VBLANK(pipe);
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
ilk_enable_display_irq(dev_priv, bit);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
return 0;
}
static int valleyview_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
i915_enable_pipestat(dev_priv, pipe,
PIPE_START_VBLANK_INTERRUPT_STATUS);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
return 0;
}
static int gen8_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
bdw_enable_pipe_irq(dev_priv, pipe, GEN8_PIPE_VBLANK);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
return 0;
}
static void i915_disable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
i915_disable_pipestat(dev_priv, pipe,
PIPE_VBLANK_INTERRUPT_STATUS |
PIPE_START_VBLANK_INTERRUPT_STATUS);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
static void ironlake_disable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
uint32_t bit = (INTEL_INFO(dev)->gen >= 7) ? DE_PIPE_VBLANK_IVB(pipe) :
DE_PIPE_VBLANK(pipe);
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
ilk_disable_display_irq(dev_priv, bit);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
static void valleyview_disable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
i915_disable_pipestat(dev_priv, pipe,
PIPE_START_VBLANK_INTERRUPT_STATUS);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
static void gen8_disable_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->irq_lock, irqflags);
bdw_disable_pipe_irq(dev_priv, pipe, GEN8_PIPE_VBLANK);
spin_unlock_irqrestore(&dev_priv->irq_lock, irqflags);
}
static bool
ring_idle(struct intel_engine_cs *ring, u32 seqno)
{
return (list_empty(&ring->request_list) ||
i915_seqno_passed(seqno, ring->last_submitted_seqno));
}
static bool
ipehr_is_semaphore_wait(struct drm_device *dev, u32 ipehr)
{
if (INTEL_INFO(dev)->gen >= 8) {
return (ipehr >> 23) == 0x1c;
} else {
ipehr &= ~MI_SEMAPHORE_SYNC_MASK;
return ipehr == (MI_SEMAPHORE_MBOX | MI_SEMAPHORE_COMPARE |
MI_SEMAPHORE_REGISTER);
}
}
static struct intel_engine_cs *
semaphore_wait_to_signaller_ring(struct intel_engine_cs *ring, u32 ipehr, u64 offset)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
struct intel_engine_cs *signaller;
int i;
if (INTEL_INFO(dev_priv->dev)->gen >= 8) {
for_each_ring(signaller, dev_priv, i) {
if (ring == signaller)
continue;
if (offset == signaller->semaphore.signal_ggtt[ring->id])
return signaller;
}
} else {
u32 sync_bits = ipehr & MI_SEMAPHORE_SYNC_MASK;
for_each_ring(signaller, dev_priv, i) {
if(ring == signaller)
continue;
if (sync_bits == signaller->semaphore.mbox.wait[ring->id])
return signaller;
}
}
DRM_ERROR("No signaller ring found for ring %i, ipehr 0x%08x, offset 0x%016llx\n",
ring->id, ipehr, offset);
return NULL;
}
static struct intel_engine_cs *
semaphore_waits_for(struct intel_engine_cs *ring, u32 *seqno)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
u32 cmd, ipehr, head;
u64 offset = 0;
int i, backwards;
if (ring->buffer == NULL)
return NULL;
ipehr = I915_READ(RING_IPEHR(ring->mmio_base));
if (!ipehr_is_semaphore_wait(ring->dev, ipehr))
return NULL;
head = I915_READ_HEAD(ring) & HEAD_ADDR;
backwards = (INTEL_INFO(ring->dev)->gen >= 8) ? 5 : 4;
for (i = backwards; i; --i) {
head &= ring->buffer->size - 1;
cmd = ioread32(ring->buffer->virtual_start + head);
if (cmd == ipehr)
break;
head -= 4;
}
if (!i)
return NULL;
*seqno = ioread32(ring->buffer->virtual_start + head + 4) + 1;
if (INTEL_INFO(ring->dev)->gen >= 8) {
offset = ioread32(ring->buffer->virtual_start + head + 12);
offset <<= 32;
offset = ioread32(ring->buffer->virtual_start + head + 8);
}
return semaphore_wait_to_signaller_ring(ring, ipehr, offset);
}
static int semaphore_passed(struct intel_engine_cs *ring)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
struct intel_engine_cs *signaller;
u32 seqno;
ring->hangcheck.deadlock++;
signaller = semaphore_waits_for(ring, &seqno);
if (signaller == NULL)
return -1;
if (signaller->hangcheck.deadlock >= I915_NUM_RINGS)
return -1;
if (i915_seqno_passed(signaller->get_seqno(signaller, false), seqno))
return 1;
if (I915_READ_CTL(signaller) & RING_WAIT_SEMAPHORE &&
semaphore_passed(signaller) < 0)
return -1;
return 0;
}
static void semaphore_clear_deadlocks(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *ring;
int i;
for_each_ring(ring, dev_priv, i)
ring->hangcheck.deadlock = 0;
}
static bool subunits_stuck(struct intel_engine_cs *ring)
{
u32 instdone[I915_NUM_INSTDONE_REG];
bool stuck;
int i;
if (ring->id != RCS)
return true;
i915_get_extra_instdone(ring->dev, instdone);
stuck = true;
for (i = 0; i < I915_NUM_INSTDONE_REG; i++) {
const u32 tmp = instdone[i] | ring->hangcheck.instdone[i];
if (tmp != ring->hangcheck.instdone[i])
stuck = false;
ring->hangcheck.instdone[i] |= tmp;
}
return stuck;
}
static enum intel_ring_hangcheck_action
head_stuck(struct intel_engine_cs *ring, u64 acthd)
{
if (acthd != ring->hangcheck.acthd) {
memset(ring->hangcheck.instdone, 0,
sizeof(ring->hangcheck.instdone));
if (acthd > ring->hangcheck.max_acthd) {
ring->hangcheck.max_acthd = acthd;
return HANGCHECK_ACTIVE;
}
return HANGCHECK_ACTIVE_LOOP;
}
if (!subunits_stuck(ring))
return HANGCHECK_ACTIVE;
return HANGCHECK_HUNG;
}
static enum intel_ring_hangcheck_action
ring_stuck(struct intel_engine_cs *ring, u64 acthd)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
enum intel_ring_hangcheck_action ha;
u32 tmp;
ha = head_stuck(ring, acthd);
if (ha != HANGCHECK_HUNG)
return ha;
if (IS_GEN2(dev))
return HANGCHECK_HUNG;
tmp = I915_READ_CTL(ring);
if (tmp & RING_WAIT) {
i915_handle_error(dev, false,
"Kicking stuck wait on %s",
ring->name);
I915_WRITE_CTL(ring, tmp);
return HANGCHECK_KICK;
}
if (INTEL_INFO(dev)->gen >= 6 && tmp & RING_WAIT_SEMAPHORE) {
switch (semaphore_passed(ring)) {
default:
return HANGCHECK_HUNG;
case 1:
i915_handle_error(dev, false,
"Kicking stuck semaphore on %s",
ring->name);
I915_WRITE_CTL(ring, tmp);
return HANGCHECK_KICK;
case 0:
return HANGCHECK_WAIT;
}
}
return HANGCHECK_HUNG;
}
static void i915_hangcheck_elapsed(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv),
gpu_error.hangcheck_work.work);
struct drm_device *dev = dev_priv->dev;
struct intel_engine_cs *ring;
int i;
int busy_count = 0, rings_hung = 0;
bool stuck[I915_NUM_RINGS] = { 0 };
#define BUSY 1
#define KICK 5
#define HUNG 20
if (!i915.enable_hangcheck)
return;
DISABLE_RPM_WAKEREF_ASSERTS(dev_priv);
intel_uncore_arm_unclaimed_mmio_detection(dev_priv);
for_each_ring(ring, dev_priv, i) {
u64 acthd;
u32 seqno;
bool busy = true;
semaphore_clear_deadlocks(dev_priv);
seqno = ring->get_seqno(ring, false);
acthd = intel_ring_get_active_head(ring);
if (ring->hangcheck.seqno == seqno) {
if (ring_idle(ring, seqno)) {
ring->hangcheck.action = HANGCHECK_IDLE;
if (waitqueue_active(&ring->irq_queue)) {
if (!test_and_set_bit(ring->id, &dev_priv->gpu_error.missed_irq_rings)) {
if (!(dev_priv->gpu_error.test_irq_rings & intel_ring_flag(ring)))
DRM_ERROR("Hangcheck timer elapsed... %s idle\n",
ring->name);
else
DRM_INFO("Fake missed irq on %s\n",
ring->name);
wake_up_all(&ring->irq_queue);
}
ring->hangcheck.score += BUSY;
} else
busy = false;
} else {
ring->hangcheck.action = ring_stuck(ring,
acthd);
switch (ring->hangcheck.action) {
case HANGCHECK_IDLE:
case HANGCHECK_WAIT:
case HANGCHECK_ACTIVE:
break;
case HANGCHECK_ACTIVE_LOOP:
ring->hangcheck.score += BUSY;
break;
case HANGCHECK_KICK:
ring->hangcheck.score += KICK;
break;
case HANGCHECK_HUNG:
ring->hangcheck.score += HUNG;
stuck[i] = true;
break;
}
}
} else {
ring->hangcheck.action = HANGCHECK_ACTIVE;
if (ring->hangcheck.score > 0)
ring->hangcheck.score--;
ring->hangcheck.acthd = ring->hangcheck.max_acthd = 0;
memset(ring->hangcheck.instdone, 0,
sizeof(ring->hangcheck.instdone));
}
ring->hangcheck.seqno = seqno;
ring->hangcheck.acthd = acthd;
busy_count += busy;
}
for_each_ring(ring, dev_priv, i) {
if (ring->hangcheck.score >= HANGCHECK_SCORE_RING_HUNG) {
DRM_INFO("%s on %s\n",
stuck[i] ? "stuck" : "no progress",
ring->name);
rings_hung++;
}
}
if (rings_hung) {
i915_handle_error(dev, true, "Ring hung");
goto out;
}
if (busy_count)
i915_queue_hangcheck(dev);
out:
ENABLE_RPM_WAKEREF_ASSERTS(dev_priv);
}
void i915_queue_hangcheck(struct drm_device *dev)
{
struct i915_gpu_error *e = &to_i915(dev)->gpu_error;
if (!i915.enable_hangcheck)
return;
queue_delayed_work(e->hangcheck_wq, &e->hangcheck_work,
round_jiffies_up_relative(DRM_I915_HANGCHECK_JIFFIES));
}
static void ibx_irq_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_PCH_NOP(dev))
return;
GEN5_IRQ_RESET(SDE);
if (HAS_PCH_CPT(dev) || HAS_PCH_LPT(dev))
I915_WRITE(SERR_INT, 0xffffffff);
}
static void ibx_irq_pre_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_PCH_NOP(dev))
return;
WARN_ON(I915_READ(SDEIER) != 0);
I915_WRITE(SDEIER, 0xffffffff);
POSTING_READ(SDEIER);
}
static void gen5_gt_irq_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
GEN5_IRQ_RESET(GT);
if (INTEL_INFO(dev)->gen >= 6)
GEN5_IRQ_RESET(GEN6_PM);
}
static void ironlake_irq_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(HWSTAM, 0xffffffff);
GEN5_IRQ_RESET(DE);
if (IS_GEN7(dev))
I915_WRITE(GEN7_ERR_INT, 0xffffffff);
gen5_gt_irq_reset(dev);
ibx_irq_reset(dev);
}
static void vlv_display_irq_reset(struct drm_i915_private *dev_priv)
{
enum pipe pipe;
i915_hotplug_interrupt_update(dev_priv, 0xFFFFFFFF, 0);
I915_WRITE(PORT_HOTPLUG_STAT, I915_READ(PORT_HOTPLUG_STAT));
for_each_pipe(dev_priv, pipe)
I915_WRITE(PIPESTAT(pipe), 0xffff);
GEN5_IRQ_RESET(VLV_);
}
static void valleyview_irq_preinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(VLV_IMR, 0);
I915_WRITE(RING_IMR(RENDER_RING_BASE), 0);
I915_WRITE(RING_IMR(GEN6_BSD_RING_BASE), 0);
I915_WRITE(RING_IMR(BLT_RING_BASE), 0);
gen5_gt_irq_reset(dev);
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
vlv_display_irq_reset(dev_priv);
}
static void gen8_gt_irq_reset(struct drm_i915_private *dev_priv)
{
GEN8_IRQ_RESET_NDX(GT, 0);
GEN8_IRQ_RESET_NDX(GT, 1);
GEN8_IRQ_RESET_NDX(GT, 2);
GEN8_IRQ_RESET_NDX(GT, 3);
}
static void gen8_irq_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
I915_WRITE(GEN8_MASTER_IRQ, 0);
POSTING_READ(GEN8_MASTER_IRQ);
gen8_gt_irq_reset(dev_priv);
for_each_pipe(dev_priv, pipe)
if (intel_display_power_is_enabled(dev_priv,
POWER_DOMAIN_PIPE(pipe)))
GEN8_IRQ_RESET_NDX(DE_PIPE, pipe);
GEN5_IRQ_RESET(GEN8_DE_PORT_);
GEN5_IRQ_RESET(GEN8_DE_MISC_);
GEN5_IRQ_RESET(GEN8_PCU_);
if (HAS_PCH_SPLIT(dev))
ibx_irq_reset(dev);
}
void gen8_irq_power_well_post_enable(struct drm_i915_private *dev_priv,
unsigned int pipe_mask)
{
uint32_t extra_ier = GEN8_PIPE_VBLANK | GEN8_PIPE_FIFO_UNDERRUN;
enum pipe pipe;
spin_lock_irq(&dev_priv->irq_lock);
for_each_pipe_masked(dev_priv, pipe, pipe_mask)
GEN8_IRQ_INIT_NDX(DE_PIPE, pipe,
dev_priv->de_irq_mask[pipe],
~dev_priv->de_irq_mask[pipe] | extra_ier);
spin_unlock_irq(&dev_priv->irq_lock);
}
void gen8_irq_power_well_pre_disable(struct drm_i915_private *dev_priv,
unsigned int pipe_mask)
{
enum pipe pipe;
spin_lock_irq(&dev_priv->irq_lock);
for_each_pipe_masked(dev_priv, pipe, pipe_mask)
GEN8_IRQ_RESET_NDX(DE_PIPE, pipe);
spin_unlock_irq(&dev_priv->irq_lock);
synchronize_irq(dev_priv->dev->irq);
}
static void cherryview_irq_preinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(GEN8_MASTER_IRQ, 0);
POSTING_READ(GEN8_MASTER_IRQ);
gen8_gt_irq_reset(dev_priv);
GEN5_IRQ_RESET(GEN8_PCU_);
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK_CHV);
vlv_display_irq_reset(dev_priv);
}
static u32 intel_hpd_enabled_irqs(struct drm_device *dev,
const u32 hpd[HPD_NUM_PINS])
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_encoder *encoder;
u32 enabled_irqs = 0;
for_each_intel_encoder(dev, encoder)
if (dev_priv->hotplug.stats[encoder->hpd_pin].state == HPD_ENABLED)
enabled_irqs |= hpd[encoder->hpd_pin];
return enabled_irqs;
}
static void ibx_hpd_irq_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hotplug_irqs, hotplug, enabled_irqs;
if (HAS_PCH_IBX(dev)) {
hotplug_irqs = SDE_HOTPLUG_MASK;
enabled_irqs = intel_hpd_enabled_irqs(dev, hpd_ibx);
} else {
hotplug_irqs = SDE_HOTPLUG_MASK_CPT;
enabled_irqs = intel_hpd_enabled_irqs(dev, hpd_cpt);
}
ibx_display_interrupt_update(dev_priv, hotplug_irqs, enabled_irqs);
hotplug = I915_READ(PCH_PORT_HOTPLUG);
hotplug &= ~(PORTD_PULSE_DURATION_MASK|PORTC_PULSE_DURATION_MASK|PORTB_PULSE_DURATION_MASK);
hotplug |= PORTD_HOTPLUG_ENABLE | PORTD_PULSE_DURATION_2ms;
hotplug |= PORTC_HOTPLUG_ENABLE | PORTC_PULSE_DURATION_2ms;
hotplug |= PORTB_HOTPLUG_ENABLE | PORTB_PULSE_DURATION_2ms;
if (HAS_PCH_LPT_LP(dev))
hotplug |= PORTA_HOTPLUG_ENABLE;
I915_WRITE(PCH_PORT_HOTPLUG, hotplug);
}
static void spt_hpd_irq_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hotplug_irqs, hotplug, enabled_irqs;
hotplug_irqs = SDE_HOTPLUG_MASK_SPT;
enabled_irqs = intel_hpd_enabled_irqs(dev, hpd_spt);
ibx_display_interrupt_update(dev_priv, hotplug_irqs, enabled_irqs);
hotplug = I915_READ(PCH_PORT_HOTPLUG);
hotplug |= PORTD_HOTPLUG_ENABLE | PORTC_HOTPLUG_ENABLE |
PORTB_HOTPLUG_ENABLE | PORTA_HOTPLUG_ENABLE;
I915_WRITE(PCH_PORT_HOTPLUG, hotplug);
hotplug = I915_READ(PCH_PORT_HOTPLUG2);
hotplug |= PORTE_HOTPLUG_ENABLE;
I915_WRITE(PCH_PORT_HOTPLUG2, hotplug);
}
static void ilk_hpd_irq_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hotplug_irqs, hotplug, enabled_irqs;
if (INTEL_INFO(dev)->gen >= 8) {
hotplug_irqs = GEN8_PORT_DP_A_HOTPLUG;
enabled_irqs = intel_hpd_enabled_irqs(dev, hpd_bdw);
bdw_update_port_irq(dev_priv, hotplug_irqs, enabled_irqs);
} else if (INTEL_INFO(dev)->gen >= 7) {
hotplug_irqs = DE_DP_A_HOTPLUG_IVB;
enabled_irqs = intel_hpd_enabled_irqs(dev, hpd_ivb);
ilk_update_display_irq(dev_priv, hotplug_irqs, enabled_irqs);
} else {
hotplug_irqs = DE_DP_A_HOTPLUG;
enabled_irqs = intel_hpd_enabled_irqs(dev, hpd_ilk);
ilk_update_display_irq(dev_priv, hotplug_irqs, enabled_irqs);
}
hotplug = I915_READ(DIGITAL_PORT_HOTPLUG_CNTRL);
hotplug &= ~DIGITAL_PORTA_PULSE_DURATION_MASK;
hotplug |= DIGITAL_PORTA_HOTPLUG_ENABLE | DIGITAL_PORTA_PULSE_DURATION_2ms;
I915_WRITE(DIGITAL_PORT_HOTPLUG_CNTRL, hotplug);
ibx_hpd_irq_setup(dev);
}
static void bxt_hpd_irq_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hotplug_irqs, hotplug, enabled_irqs;
enabled_irqs = intel_hpd_enabled_irqs(dev, hpd_bxt);
hotplug_irqs = BXT_DE_PORT_HOTPLUG_MASK;
bdw_update_port_irq(dev_priv, hotplug_irqs, enabled_irqs);
hotplug = I915_READ(PCH_PORT_HOTPLUG);
hotplug |= PORTC_HOTPLUG_ENABLE | PORTB_HOTPLUG_ENABLE |
PORTA_HOTPLUG_ENABLE;
I915_WRITE(PCH_PORT_HOTPLUG, hotplug);
}
static void ibx_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 mask;
if (HAS_PCH_NOP(dev))
return;
if (HAS_PCH_IBX(dev))
mask = SDE_GMBUS | SDE_AUX_MASK | SDE_POISON;
else
mask = SDE_GMBUS_CPT | SDE_AUX_MASK_CPT;
gen5_assert_iir_is_zero(dev_priv, SDEIIR);
I915_WRITE(SDEIMR, ~mask);
}
static void gen5_gt_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 pm_irqs, gt_irqs;
pm_irqs = gt_irqs = 0;
dev_priv->gt_irq_mask = ~0;
if (HAS_L3_DPF(dev)) {
dev_priv->gt_irq_mask = ~GT_PARITY_ERROR(dev);
gt_irqs |= GT_PARITY_ERROR(dev);
}
gt_irqs |= GT_RENDER_USER_INTERRUPT;
if (IS_GEN5(dev)) {
gt_irqs |= GT_RENDER_PIPECTL_NOTIFY_INTERRUPT |
ILK_BSD_USER_INTERRUPT;
} else {
gt_irqs |= GT_BLT_USER_INTERRUPT | GT_BSD_USER_INTERRUPT;
}
GEN5_IRQ_INIT(GT, dev_priv->gt_irq_mask, gt_irqs);
if (INTEL_INFO(dev)->gen >= 6) {
if (HAS_VEBOX(dev))
pm_irqs |= PM_VEBOX_USER_INTERRUPT;
dev_priv->pm_irq_mask = 0xffffffff;
GEN5_IRQ_INIT(GEN6_PM, dev_priv->pm_irq_mask, pm_irqs);
}
}
static int ironlake_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 display_mask, extra_mask;
if (INTEL_INFO(dev)->gen >= 7) {
display_mask = (DE_MASTER_IRQ_CONTROL | DE_GSE_IVB |
DE_PCH_EVENT_IVB | DE_PLANEC_FLIP_DONE_IVB |
DE_PLANEB_FLIP_DONE_IVB |
DE_PLANEA_FLIP_DONE_IVB | DE_AUX_CHANNEL_A_IVB);
extra_mask = (DE_PIPEC_VBLANK_IVB | DE_PIPEB_VBLANK_IVB |
DE_PIPEA_VBLANK_IVB | DE_ERR_INT_IVB |
DE_DP_A_HOTPLUG_IVB);
} else {
display_mask = (DE_MASTER_IRQ_CONTROL | DE_GSE | DE_PCH_EVENT |
DE_PLANEA_FLIP_DONE | DE_PLANEB_FLIP_DONE |
DE_AUX_CHANNEL_A |
DE_PIPEB_CRC_DONE | DE_PIPEA_CRC_DONE |
DE_POISON);
extra_mask = (DE_PIPEA_VBLANK | DE_PIPEB_VBLANK | DE_PCU_EVENT |
DE_PIPEB_FIFO_UNDERRUN | DE_PIPEA_FIFO_UNDERRUN |
DE_DP_A_HOTPLUG);
}
dev_priv->irq_mask = ~display_mask;
I915_WRITE(HWSTAM, 0xeffe);
ibx_irq_pre_postinstall(dev);
GEN5_IRQ_INIT(DE, dev_priv->irq_mask, display_mask | extra_mask);
gen5_gt_irq_postinstall(dev);
ibx_irq_postinstall(dev);
if (IS_IRONLAKE_M(dev)) {
spin_lock_irq(&dev_priv->irq_lock);
ilk_enable_display_irq(dev_priv, DE_PCU_EVENT);
spin_unlock_irq(&dev_priv->irq_lock);
}
return 0;
}
static void valleyview_display_irqs_install(struct drm_i915_private *dev_priv)
{
u32 pipestat_mask;
u32 iir_mask;
enum pipe pipe;
pipestat_mask = PIPESTAT_INT_STATUS_MASK |
PIPE_FIFO_UNDERRUN_STATUS;
for_each_pipe(dev_priv, pipe)
I915_WRITE(PIPESTAT(pipe), pipestat_mask);
POSTING_READ(PIPESTAT(PIPE_A));
pipestat_mask = PLANE_FLIP_DONE_INT_STATUS_VLV |
PIPE_CRC_DONE_INTERRUPT_STATUS;
i915_enable_pipestat(dev_priv, PIPE_A, PIPE_GMBUS_INTERRUPT_STATUS);
for_each_pipe(dev_priv, pipe)
i915_enable_pipestat(dev_priv, pipe, pipestat_mask);
iir_mask = I915_DISPLAY_PORT_INTERRUPT |
I915_DISPLAY_PIPE_A_EVENT_INTERRUPT |
I915_DISPLAY_PIPE_B_EVENT_INTERRUPT;
if (IS_CHERRYVIEW(dev_priv))
iir_mask |= I915_DISPLAY_PIPE_C_EVENT_INTERRUPT;
dev_priv->irq_mask &= ~iir_mask;
I915_WRITE(VLV_IIR, iir_mask);
I915_WRITE(VLV_IIR, iir_mask);
I915_WRITE(VLV_IER, ~dev_priv->irq_mask);
I915_WRITE(VLV_IMR, dev_priv->irq_mask);
POSTING_READ(VLV_IMR);
}
static void valleyview_display_irqs_uninstall(struct drm_i915_private *dev_priv)
{
u32 pipestat_mask;
u32 iir_mask;
enum pipe pipe;
iir_mask = I915_DISPLAY_PORT_INTERRUPT |
I915_DISPLAY_PIPE_A_EVENT_INTERRUPT |
I915_DISPLAY_PIPE_B_EVENT_INTERRUPT;
if (IS_CHERRYVIEW(dev_priv))
iir_mask |= I915_DISPLAY_PIPE_C_EVENT_INTERRUPT;
dev_priv->irq_mask |= iir_mask;
I915_WRITE(VLV_IMR, dev_priv->irq_mask);
I915_WRITE(VLV_IER, ~dev_priv->irq_mask);
I915_WRITE(VLV_IIR, iir_mask);
I915_WRITE(VLV_IIR, iir_mask);
POSTING_READ(VLV_IIR);
pipestat_mask = PLANE_FLIP_DONE_INT_STATUS_VLV |
PIPE_CRC_DONE_INTERRUPT_STATUS;
i915_disable_pipestat(dev_priv, PIPE_A, PIPE_GMBUS_INTERRUPT_STATUS);
for_each_pipe(dev_priv, pipe)
i915_disable_pipestat(dev_priv, pipe, pipestat_mask);
pipestat_mask = PIPESTAT_INT_STATUS_MASK |
PIPE_FIFO_UNDERRUN_STATUS;
for_each_pipe(dev_priv, pipe)
I915_WRITE(PIPESTAT(pipe), pipestat_mask);
POSTING_READ(PIPESTAT(PIPE_A));
}
void valleyview_enable_display_irqs(struct drm_i915_private *dev_priv)
{
assert_spin_locked(&dev_priv->irq_lock);
if (dev_priv->display_irqs_enabled)
return;
dev_priv->display_irqs_enabled = true;
if (intel_irqs_enabled(dev_priv))
valleyview_display_irqs_install(dev_priv);
}
void valleyview_disable_display_irqs(struct drm_i915_private *dev_priv)
{
assert_spin_locked(&dev_priv->irq_lock);
if (!dev_priv->display_irqs_enabled)
return;
dev_priv->display_irqs_enabled = false;
if (intel_irqs_enabled(dev_priv))
valleyview_display_irqs_uninstall(dev_priv);
}
static void vlv_display_irq_postinstall(struct drm_i915_private *dev_priv)
{
dev_priv->irq_mask = ~0;
i915_hotplug_interrupt_update(dev_priv, 0xffffffff, 0);
POSTING_READ(PORT_HOTPLUG_EN);
I915_WRITE(VLV_IIR, 0xffffffff);
I915_WRITE(VLV_IIR, 0xffffffff);
I915_WRITE(VLV_IER, ~dev_priv->irq_mask);
I915_WRITE(VLV_IMR, dev_priv->irq_mask);
POSTING_READ(VLV_IMR);
spin_lock_irq(&dev_priv->irq_lock);
if (dev_priv->display_irqs_enabled)
valleyview_display_irqs_install(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
}
static int valleyview_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
vlv_display_irq_postinstall(dev_priv);
gen5_gt_irq_postinstall(dev);
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
I915_WRITE(VLV_MASTER_IER, MASTER_INTERRUPT_ENABLE);
return 0;
}
static void gen8_gt_irq_postinstall(struct drm_i915_private *dev_priv)
{
uint32_t gt_interrupts[] = {
GT_RENDER_USER_INTERRUPT << GEN8_RCS_IRQ_SHIFT |
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_RCS_IRQ_SHIFT |
GT_RENDER_L3_PARITY_ERROR_INTERRUPT |
GT_RENDER_USER_INTERRUPT << GEN8_BCS_IRQ_SHIFT |
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_BCS_IRQ_SHIFT,
GT_RENDER_USER_INTERRUPT << GEN8_VCS1_IRQ_SHIFT |
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_VCS1_IRQ_SHIFT |
GT_RENDER_USER_INTERRUPT << GEN8_VCS2_IRQ_SHIFT |
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_VCS2_IRQ_SHIFT,
0,
GT_RENDER_USER_INTERRUPT << GEN8_VECS_IRQ_SHIFT |
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_VECS_IRQ_SHIFT
};
dev_priv->pm_irq_mask = 0xffffffff;
GEN8_IRQ_INIT_NDX(GT, 0, ~gt_interrupts[0], gt_interrupts[0]);
GEN8_IRQ_INIT_NDX(GT, 1, ~gt_interrupts[1], gt_interrupts[1]);
GEN8_IRQ_INIT_NDX(GT, 2, dev_priv->pm_irq_mask, 0);
GEN8_IRQ_INIT_NDX(GT, 3, ~gt_interrupts[3], gt_interrupts[3]);
}
static void gen8_de_irq_postinstall(struct drm_i915_private *dev_priv)
{
uint32_t de_pipe_masked = GEN8_PIPE_CDCLK_CRC_DONE;
uint32_t de_pipe_enables;
u32 de_port_masked = GEN8_AUX_CHANNEL_A;
u32 de_port_enables;
enum pipe pipe;
if (INTEL_INFO(dev_priv)->gen >= 9) {
de_pipe_masked |= GEN9_PIPE_PLANE1_FLIP_DONE |
GEN9_DE_PIPE_IRQ_FAULT_ERRORS;
de_port_masked |= GEN9_AUX_CHANNEL_B | GEN9_AUX_CHANNEL_C |
GEN9_AUX_CHANNEL_D;
if (IS_BROXTON(dev_priv))
de_port_masked |= BXT_DE_PORT_GMBUS;
} else {
de_pipe_masked |= GEN8_PIPE_PRIMARY_FLIP_DONE |
GEN8_DE_PIPE_IRQ_FAULT_ERRORS;
}
de_pipe_enables = de_pipe_masked | GEN8_PIPE_VBLANK |
GEN8_PIPE_FIFO_UNDERRUN;
de_port_enables = de_port_masked;
if (IS_BROXTON(dev_priv))
de_port_enables |= BXT_DE_PORT_HOTPLUG_MASK;
else if (IS_BROADWELL(dev_priv))
de_port_enables |= GEN8_PORT_DP_A_HOTPLUG;
dev_priv->de_irq_mask[PIPE_A] = ~de_pipe_masked;
dev_priv->de_irq_mask[PIPE_B] = ~de_pipe_masked;
dev_priv->de_irq_mask[PIPE_C] = ~de_pipe_masked;
for_each_pipe(dev_priv, pipe)
if (intel_display_power_is_enabled(dev_priv,
POWER_DOMAIN_PIPE(pipe)))
GEN8_IRQ_INIT_NDX(DE_PIPE, pipe,
dev_priv->de_irq_mask[pipe],
de_pipe_enables);
GEN5_IRQ_INIT(GEN8_DE_PORT_, ~de_port_masked, de_port_enables);
}
static int gen8_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_PCH_SPLIT(dev))
ibx_irq_pre_postinstall(dev);
gen8_gt_irq_postinstall(dev_priv);
gen8_de_irq_postinstall(dev_priv);
if (HAS_PCH_SPLIT(dev))
ibx_irq_postinstall(dev);
I915_WRITE(GEN8_MASTER_IRQ, DE_MASTER_IRQ_CONTROL);
POSTING_READ(GEN8_MASTER_IRQ);
return 0;
}
static int cherryview_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
vlv_display_irq_postinstall(dev_priv);
gen8_gt_irq_postinstall(dev_priv);
I915_WRITE(GEN8_MASTER_IRQ, MASTER_INTERRUPT_ENABLE);
POSTING_READ(GEN8_MASTER_IRQ);
return 0;
}
static void gen8_irq_uninstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv)
return;
gen8_irq_reset(dev);
}
static void vlv_display_irq_uninstall(struct drm_i915_private *dev_priv)
{
spin_lock_irq(&dev_priv->irq_lock);
if (dev_priv->display_irqs_enabled)
valleyview_display_irqs_uninstall(dev_priv);
spin_unlock_irq(&dev_priv->irq_lock);
vlv_display_irq_reset(dev_priv);
dev_priv->irq_mask = ~0;
}
static void valleyview_irq_uninstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv)
return;
I915_WRITE(VLV_MASTER_IER, 0);
gen5_gt_irq_reset(dev);
I915_WRITE(HWSTAM, 0xffffffff);
vlv_display_irq_uninstall(dev_priv);
}
static void cherryview_irq_uninstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv)
return;
I915_WRITE(GEN8_MASTER_IRQ, 0);
POSTING_READ(GEN8_MASTER_IRQ);
gen8_gt_irq_reset(dev_priv);
GEN5_IRQ_RESET(GEN8_PCU_);
vlv_display_irq_uninstall(dev_priv);
}
static void ironlake_irq_uninstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv)
return;
ironlake_irq_reset(dev);
}
static void i8xx_irq_preinstall(struct drm_device * dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
for_each_pipe(dev_priv, pipe)
I915_WRITE(PIPESTAT(pipe), 0);
I915_WRITE16(IMR, 0xffff);
I915_WRITE16(IER, 0x0);
POSTING_READ16(IER);
}
static int i8xx_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE16(EMR,
~(I915_ERROR_PAGE_TABLE | I915_ERROR_MEMORY_REFRESH));
dev_priv->irq_mask =
~(I915_DISPLAY_PIPE_A_EVENT_INTERRUPT |
I915_DISPLAY_PIPE_B_EVENT_INTERRUPT |
I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT |
I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT);
I915_WRITE16(IMR, dev_priv->irq_mask);
I915_WRITE16(IER,
I915_DISPLAY_PIPE_A_EVENT_INTERRUPT |
I915_DISPLAY_PIPE_B_EVENT_INTERRUPT |
I915_USER_INTERRUPT);
POSTING_READ16(IER);
spin_lock_irq(&dev_priv->irq_lock);
i915_enable_pipestat(dev_priv, PIPE_A, PIPE_CRC_DONE_INTERRUPT_STATUS);
i915_enable_pipestat(dev_priv, PIPE_B, PIPE_CRC_DONE_INTERRUPT_STATUS);
spin_unlock_irq(&dev_priv->irq_lock);
return 0;
}
static bool i8xx_handle_vblank(struct drm_device *dev,
int plane, int pipe, u32 iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u16 flip_pending = DISPLAY_PLANE_FLIP_PENDING(plane);
if (!intel_pipe_handle_vblank(dev, pipe))
return false;
if ((iir & flip_pending) == 0)
goto check_page_flip;
if (I915_READ16(ISR) & flip_pending)
goto check_page_flip;
intel_prepare_page_flip(dev, plane);
intel_finish_page_flip(dev, pipe);
return true;
check_page_flip:
intel_check_page_flip(dev, pipe);
return false;
}
static irqreturn_t i8xx_irq_handler(int irq, void *arg)
{
struct drm_device *dev = arg;
struct drm_i915_private *dev_priv = dev->dev_private;
u16 iir, new_iir;
u32 pipe_stats[2];
int pipe;
u16 flip_mask =
I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT |
I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT;
irqreturn_t ret;
if (!intel_irqs_enabled(dev_priv))
return IRQ_NONE;
disable_rpm_wakeref_asserts(dev_priv);
ret = IRQ_NONE;
iir = I915_READ16(IIR);
if (iir == 0)
goto out;
while (iir & ~flip_mask) {
spin_lock(&dev_priv->irq_lock);
if (iir & I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT)
DRM_DEBUG("Command parser error, iir 0x%08x\n", iir);
for_each_pipe(dev_priv, pipe) {
i915_reg_t reg = PIPESTAT(pipe);
pipe_stats[pipe] = I915_READ(reg);
if (pipe_stats[pipe] & 0x8000ffff)
I915_WRITE(reg, pipe_stats[pipe]);
}
spin_unlock(&dev_priv->irq_lock);
I915_WRITE16(IIR, iir & ~flip_mask);
new_iir = I915_READ16(IIR);
if (iir & I915_USER_INTERRUPT)
notify_ring(&dev_priv->ring[RCS]);
for_each_pipe(dev_priv, pipe) {
int plane = pipe;
if (HAS_FBC(dev))
plane = !plane;
if (pipe_stats[pipe] & PIPE_VBLANK_INTERRUPT_STATUS &&
i8xx_handle_vblank(dev, plane, pipe, iir))
flip_mask &= ~DISPLAY_PLANE_FLIP_PENDING(plane);
if (pipe_stats[pipe] & PIPE_CRC_DONE_INTERRUPT_STATUS)
i9xx_pipe_crc_irq_handler(dev, pipe);
if (pipe_stats[pipe] & PIPE_FIFO_UNDERRUN_STATUS)
intel_cpu_fifo_underrun_irq_handler(dev_priv,
pipe);
}
iir = new_iir;
}
ret = IRQ_HANDLED;
out:
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
static void i8xx_irq_uninstall(struct drm_device * dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
for_each_pipe(dev_priv, pipe) {
I915_WRITE(PIPESTAT(pipe), 0);
I915_WRITE(PIPESTAT(pipe), I915_READ(PIPESTAT(pipe)));
}
I915_WRITE16(IMR, 0xffff);
I915_WRITE16(IER, 0x0);
I915_WRITE16(IIR, I915_READ16(IIR));
}
static void i915_irq_preinstall(struct drm_device * dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
if (I915_HAS_HOTPLUG(dev)) {
i915_hotplug_interrupt_update(dev_priv, 0xffffffff, 0);
I915_WRITE(PORT_HOTPLUG_STAT, I915_READ(PORT_HOTPLUG_STAT));
}
I915_WRITE16(HWSTAM, 0xeffe);
for_each_pipe(dev_priv, pipe)
I915_WRITE(PIPESTAT(pipe), 0);
I915_WRITE(IMR, 0xffffffff);
I915_WRITE(IER, 0x0);
POSTING_READ(IER);
}
static int i915_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 enable_mask;
I915_WRITE(EMR, ~(I915_ERROR_PAGE_TABLE | I915_ERROR_MEMORY_REFRESH));
dev_priv->irq_mask =
~(I915_ASLE_INTERRUPT |
I915_DISPLAY_PIPE_A_EVENT_INTERRUPT |
I915_DISPLAY_PIPE_B_EVENT_INTERRUPT |
I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT |
I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT);
enable_mask =
I915_ASLE_INTERRUPT |
I915_DISPLAY_PIPE_A_EVENT_INTERRUPT |
I915_DISPLAY_PIPE_B_EVENT_INTERRUPT |
I915_USER_INTERRUPT;
if (I915_HAS_HOTPLUG(dev)) {
i915_hotplug_interrupt_update(dev_priv, 0xffffffff, 0);
POSTING_READ(PORT_HOTPLUG_EN);
enable_mask |= I915_DISPLAY_PORT_INTERRUPT;
dev_priv->irq_mask &= ~I915_DISPLAY_PORT_INTERRUPT;
}
I915_WRITE(IMR, dev_priv->irq_mask);
I915_WRITE(IER, enable_mask);
POSTING_READ(IER);
i915_enable_asle_pipestat(dev);
spin_lock_irq(&dev_priv->irq_lock);
i915_enable_pipestat(dev_priv, PIPE_A, PIPE_CRC_DONE_INTERRUPT_STATUS);
i915_enable_pipestat(dev_priv, PIPE_B, PIPE_CRC_DONE_INTERRUPT_STATUS);
spin_unlock_irq(&dev_priv->irq_lock);
return 0;
}
static bool i915_handle_vblank(struct drm_device *dev,
int plane, int pipe, u32 iir)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 flip_pending = DISPLAY_PLANE_FLIP_PENDING(plane);
if (!intel_pipe_handle_vblank(dev, pipe))
return false;
if ((iir & flip_pending) == 0)
goto check_page_flip;
if (I915_READ(ISR) & flip_pending)
goto check_page_flip;
intel_prepare_page_flip(dev, plane);
intel_finish_page_flip(dev, pipe);
return true;
check_page_flip:
intel_check_page_flip(dev, pipe);
return false;
}
static irqreturn_t i915_irq_handler(int irq, void *arg)
{
struct drm_device *dev = arg;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 iir, new_iir, pipe_stats[I915_MAX_PIPES];
u32 flip_mask =
I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT |
I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT;
int pipe, ret = IRQ_NONE;
if (!intel_irqs_enabled(dev_priv))
return IRQ_NONE;
disable_rpm_wakeref_asserts(dev_priv);
iir = I915_READ(IIR);
do {
bool irq_received = (iir & ~flip_mask) != 0;
bool blc_event = false;
spin_lock(&dev_priv->irq_lock);
if (iir & I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT)
DRM_DEBUG("Command parser error, iir 0x%08x\n", iir);
for_each_pipe(dev_priv, pipe) {
i915_reg_t reg = PIPESTAT(pipe);
pipe_stats[pipe] = I915_READ(reg);
if (pipe_stats[pipe] & 0x8000ffff) {
I915_WRITE(reg, pipe_stats[pipe]);
irq_received = true;
}
}
spin_unlock(&dev_priv->irq_lock);
if (!irq_received)
break;
if (I915_HAS_HOTPLUG(dev) &&
iir & I915_DISPLAY_PORT_INTERRUPT)
i9xx_hpd_irq_handler(dev);
I915_WRITE(IIR, iir & ~flip_mask);
new_iir = I915_READ(IIR);
if (iir & I915_USER_INTERRUPT)
notify_ring(&dev_priv->ring[RCS]);
for_each_pipe(dev_priv, pipe) {
int plane = pipe;
if (HAS_FBC(dev))
plane = !plane;
if (pipe_stats[pipe] & PIPE_VBLANK_INTERRUPT_STATUS &&
i915_handle_vblank(dev, plane, pipe, iir))
flip_mask &= ~DISPLAY_PLANE_FLIP_PENDING(plane);
if (pipe_stats[pipe] & PIPE_LEGACY_BLC_EVENT_STATUS)
blc_event = true;
if (pipe_stats[pipe] & PIPE_CRC_DONE_INTERRUPT_STATUS)
i9xx_pipe_crc_irq_handler(dev, pipe);
if (pipe_stats[pipe] & PIPE_FIFO_UNDERRUN_STATUS)
intel_cpu_fifo_underrun_irq_handler(dev_priv,
pipe);
}
if (blc_event || (iir & I915_ASLE_INTERRUPT))
intel_opregion_asle_intr(dev);
ret = IRQ_HANDLED;
iir = new_iir;
} while (iir & ~flip_mask);
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
static void i915_irq_uninstall(struct drm_device * dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
if (I915_HAS_HOTPLUG(dev)) {
i915_hotplug_interrupt_update(dev_priv, 0xffffffff, 0);
I915_WRITE(PORT_HOTPLUG_STAT, I915_READ(PORT_HOTPLUG_STAT));
}
I915_WRITE16(HWSTAM, 0xffff);
for_each_pipe(dev_priv, pipe) {
I915_WRITE(PIPESTAT(pipe), 0);
I915_WRITE(PIPESTAT(pipe), I915_READ(PIPESTAT(pipe)));
}
I915_WRITE(IMR, 0xffffffff);
I915_WRITE(IER, 0x0);
I915_WRITE(IIR, I915_READ(IIR));
}
static void i965_irq_preinstall(struct drm_device * dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
i915_hotplug_interrupt_update(dev_priv, 0xffffffff, 0);
I915_WRITE(PORT_HOTPLUG_STAT, I915_READ(PORT_HOTPLUG_STAT));
I915_WRITE(HWSTAM, 0xeffe);
for_each_pipe(dev_priv, pipe)
I915_WRITE(PIPESTAT(pipe), 0);
I915_WRITE(IMR, 0xffffffff);
I915_WRITE(IER, 0x0);
POSTING_READ(IER);
}
static int i965_irq_postinstall(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 enable_mask;
u32 error_mask;
dev_priv->irq_mask = ~(I915_ASLE_INTERRUPT |
I915_DISPLAY_PORT_INTERRUPT |
I915_DISPLAY_PIPE_A_EVENT_INTERRUPT |
I915_DISPLAY_PIPE_B_EVENT_INTERRUPT |
I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT |
I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT |
I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT);
enable_mask = ~dev_priv->irq_mask;
enable_mask &= ~(I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT |
I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT);
enable_mask |= I915_USER_INTERRUPT;
if (IS_G4X(dev))
enable_mask |= I915_BSD_USER_INTERRUPT;
spin_lock_irq(&dev_priv->irq_lock);
i915_enable_pipestat(dev_priv, PIPE_A, PIPE_GMBUS_INTERRUPT_STATUS);
i915_enable_pipestat(dev_priv, PIPE_A, PIPE_CRC_DONE_INTERRUPT_STATUS);
i915_enable_pipestat(dev_priv, PIPE_B, PIPE_CRC_DONE_INTERRUPT_STATUS);
spin_unlock_irq(&dev_priv->irq_lock);
if (IS_G4X(dev)) {
error_mask = ~(GM45_ERROR_PAGE_TABLE |
GM45_ERROR_MEM_PRIV |
GM45_ERROR_CP_PRIV |
I915_ERROR_MEMORY_REFRESH);
} else {
error_mask = ~(I915_ERROR_PAGE_TABLE |
I915_ERROR_MEMORY_REFRESH);
}
I915_WRITE(EMR, error_mask);
I915_WRITE(IMR, dev_priv->irq_mask);
I915_WRITE(IER, enable_mask);
POSTING_READ(IER);
i915_hotplug_interrupt_update(dev_priv, 0xffffffff, 0);
POSTING_READ(PORT_HOTPLUG_EN);
i915_enable_asle_pipestat(dev);
return 0;
}
static void i915_hpd_irq_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 hotplug_en;
assert_spin_locked(&dev_priv->irq_lock);
hotplug_en = intel_hpd_enabled_irqs(dev, hpd_mask_i915);
if (IS_G4X(dev))
hotplug_en |= CRT_HOTPLUG_ACTIVATION_PERIOD_64;
hotplug_en |= CRT_HOTPLUG_VOLTAGE_COMPARE_50;
i915_hotplug_interrupt_update_locked(dev_priv,
HOTPLUG_INT_EN_MASK |
CRT_HOTPLUG_VOLTAGE_COMPARE_MASK |
CRT_HOTPLUG_ACTIVATION_PERIOD_64,
hotplug_en);
}
static irqreturn_t i965_irq_handler(int irq, void *arg)
{
struct drm_device *dev = arg;
struct drm_i915_private *dev_priv = dev->dev_private;
u32 iir, new_iir;
u32 pipe_stats[I915_MAX_PIPES];
int ret = IRQ_NONE, pipe;
u32 flip_mask =
I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT |
I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT;
if (!intel_irqs_enabled(dev_priv))
return IRQ_NONE;
disable_rpm_wakeref_asserts(dev_priv);
iir = I915_READ(IIR);
for (;;) {
bool irq_received = (iir & ~flip_mask) != 0;
bool blc_event = false;
spin_lock(&dev_priv->irq_lock);
if (iir & I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT)
DRM_DEBUG("Command parser error, iir 0x%08x\n", iir);
for_each_pipe(dev_priv, pipe) {
i915_reg_t reg = PIPESTAT(pipe);
pipe_stats[pipe] = I915_READ(reg);
if (pipe_stats[pipe] & 0x8000ffff) {
I915_WRITE(reg, pipe_stats[pipe]);
irq_received = true;
}
}
spin_unlock(&dev_priv->irq_lock);
if (!irq_received)
break;
ret = IRQ_HANDLED;
if (iir & I915_DISPLAY_PORT_INTERRUPT)
i9xx_hpd_irq_handler(dev);
I915_WRITE(IIR, iir & ~flip_mask);
new_iir = I915_READ(IIR);
if (iir & I915_USER_INTERRUPT)
notify_ring(&dev_priv->ring[RCS]);
if (iir & I915_BSD_USER_INTERRUPT)
notify_ring(&dev_priv->ring[VCS]);
for_each_pipe(dev_priv, pipe) {
if (pipe_stats[pipe] & PIPE_START_VBLANK_INTERRUPT_STATUS &&
i915_handle_vblank(dev, pipe, pipe, iir))
flip_mask &= ~DISPLAY_PLANE_FLIP_PENDING(pipe);
if (pipe_stats[pipe] & PIPE_LEGACY_BLC_EVENT_STATUS)
blc_event = true;
if (pipe_stats[pipe] & PIPE_CRC_DONE_INTERRUPT_STATUS)
i9xx_pipe_crc_irq_handler(dev, pipe);
if (pipe_stats[pipe] & PIPE_FIFO_UNDERRUN_STATUS)
intel_cpu_fifo_underrun_irq_handler(dev_priv, pipe);
}
if (blc_event || (iir & I915_ASLE_INTERRUPT))
intel_opregion_asle_intr(dev);
if (pipe_stats[0] & PIPE_GMBUS_INTERRUPT_STATUS)
gmbus_irq_handler(dev);
iir = new_iir;
}
enable_rpm_wakeref_asserts(dev_priv);
return ret;
}
static void i965_irq_uninstall(struct drm_device * dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
if (!dev_priv)
return;
i915_hotplug_interrupt_update(dev_priv, 0xffffffff, 0);
I915_WRITE(PORT_HOTPLUG_STAT, I915_READ(PORT_HOTPLUG_STAT));
I915_WRITE(HWSTAM, 0xffffffff);
for_each_pipe(dev_priv, pipe)
I915_WRITE(PIPESTAT(pipe), 0);
I915_WRITE(IMR, 0xffffffff);
I915_WRITE(IER, 0x0);
for_each_pipe(dev_priv, pipe)
I915_WRITE(PIPESTAT(pipe),
I915_READ(PIPESTAT(pipe)) & 0x8000ffff);
I915_WRITE(IIR, I915_READ(IIR));
}
void intel_irq_init(struct drm_i915_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
intel_hpd_init_work(dev_priv);
INIT_WORK(&dev_priv->rps.work, gen6_pm_rps_work);
INIT_WORK(&dev_priv->l3_parity.error_work, ivybridge_parity_work);
if (IS_VALLEYVIEW(dev_priv))
dev_priv->pm_rps_events = GEN6_PM_RP_DOWN_EI_EXPIRED | GEN6_PM_RP_UP_EI_EXPIRED;
else
dev_priv->pm_rps_events = GEN6_PM_RPS_EVENTS;
INIT_DELAYED_WORK(&dev_priv->gpu_error.hangcheck_work,
i915_hangcheck_elapsed);
pm_qos_add_request(&dev_priv->pm_qos, PM_QOS_CPU_DMA_LATENCY, PM_QOS_DEFAULT_VALUE);
if (IS_GEN2(dev_priv)) {
dev->max_vblank_count = 0;
dev->driver->get_vblank_counter = i8xx_get_vblank_counter;
} else if (IS_G4X(dev_priv) || INTEL_INFO(dev_priv)->gen >= 5) {
dev->max_vblank_count = 0xffffffff;
dev->driver->get_vblank_counter = g4x_get_vblank_counter;
} else {
dev->driver->get_vblank_counter = i915_get_vblank_counter;
dev->max_vblank_count = 0xffffff;
}
if (!IS_GEN2(dev_priv))
dev->vblank_disable_immediate = true;
dev->driver->get_vblank_timestamp = i915_get_vblank_timestamp;
dev->driver->get_scanout_position = i915_get_crtc_scanoutpos;
if (IS_CHERRYVIEW(dev_priv)) {
dev->driver->irq_handler = cherryview_irq_handler;
dev->driver->irq_preinstall = cherryview_irq_preinstall;
dev->driver->irq_postinstall = cherryview_irq_postinstall;
dev->driver->irq_uninstall = cherryview_irq_uninstall;
dev->driver->enable_vblank = valleyview_enable_vblank;
dev->driver->disable_vblank = valleyview_disable_vblank;
dev_priv->display.hpd_irq_setup = i915_hpd_irq_setup;
} else if (IS_VALLEYVIEW(dev_priv)) {
dev->driver->irq_handler = valleyview_irq_handler;
dev->driver->irq_preinstall = valleyview_irq_preinstall;
dev->driver->irq_postinstall = valleyview_irq_postinstall;
dev->driver->irq_uninstall = valleyview_irq_uninstall;
dev->driver->enable_vblank = valleyview_enable_vblank;
dev->driver->disable_vblank = valleyview_disable_vblank;
dev_priv->display.hpd_irq_setup = i915_hpd_irq_setup;
} else if (INTEL_INFO(dev_priv)->gen >= 8) {
dev->driver->irq_handler = gen8_irq_handler;
dev->driver->irq_preinstall = gen8_irq_reset;
dev->driver->irq_postinstall = gen8_irq_postinstall;
dev->driver->irq_uninstall = gen8_irq_uninstall;
dev->driver->enable_vblank = gen8_enable_vblank;
dev->driver->disable_vblank = gen8_disable_vblank;
if (IS_BROXTON(dev))
dev_priv->display.hpd_irq_setup = bxt_hpd_irq_setup;
else if (HAS_PCH_SPT(dev))
dev_priv->display.hpd_irq_setup = spt_hpd_irq_setup;
else
dev_priv->display.hpd_irq_setup = ilk_hpd_irq_setup;
} else if (HAS_PCH_SPLIT(dev)) {
dev->driver->irq_handler = ironlake_irq_handler;
dev->driver->irq_preinstall = ironlake_irq_reset;
dev->driver->irq_postinstall = ironlake_irq_postinstall;
dev->driver->irq_uninstall = ironlake_irq_uninstall;
dev->driver->enable_vblank = ironlake_enable_vblank;
dev->driver->disable_vblank = ironlake_disable_vblank;
dev_priv->display.hpd_irq_setup = ilk_hpd_irq_setup;
} else {
if (INTEL_INFO(dev_priv)->gen == 2) {
dev->driver->irq_preinstall = i8xx_irq_preinstall;
dev->driver->irq_postinstall = i8xx_irq_postinstall;
dev->driver->irq_handler = i8xx_irq_handler;
dev->driver->irq_uninstall = i8xx_irq_uninstall;
} else if (INTEL_INFO(dev_priv)->gen == 3) {
dev->driver->irq_preinstall = i915_irq_preinstall;
dev->driver->irq_postinstall = i915_irq_postinstall;
dev->driver->irq_uninstall = i915_irq_uninstall;
dev->driver->irq_handler = i915_irq_handler;
} else {
dev->driver->irq_preinstall = i965_irq_preinstall;
dev->driver->irq_postinstall = i965_irq_postinstall;
dev->driver->irq_uninstall = i965_irq_uninstall;
dev->driver->irq_handler = i965_irq_handler;
}
if (I915_HAS_HOTPLUG(dev_priv))
dev_priv->display.hpd_irq_setup = i915_hpd_irq_setup;
dev->driver->enable_vblank = i915_enable_vblank;
dev->driver->disable_vblank = i915_disable_vblank;
}
}
int intel_irq_install(struct drm_i915_private *dev_priv)
{
dev_priv->pm.irqs_enabled = true;
return drm_irq_install(dev_priv->dev, dev_priv->dev->pdev->irq);
}
void intel_irq_uninstall(struct drm_i915_private *dev_priv)
{
drm_irq_uninstall(dev_priv->dev);
intel_hpd_cancel_work(dev_priv);
dev_priv->pm.irqs_enabled = false;
}
void intel_runtime_pm_disable_interrupts(struct drm_i915_private *dev_priv)
{
dev_priv->dev->driver->irq_uninstall(dev_priv->dev);
dev_priv->pm.irqs_enabled = false;
synchronize_irq(dev_priv->dev->irq);
}
void intel_runtime_pm_enable_interrupts(struct drm_i915_private *dev_priv)
{
dev_priv->pm.irqs_enabled = true;
dev_priv->dev->driver->irq_preinstall(dev_priv->dev);
dev_priv->dev->driver->irq_postinstall(dev_priv->dev);
}
