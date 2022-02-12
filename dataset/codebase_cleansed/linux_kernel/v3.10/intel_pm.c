static bool intel_crtc_active(struct drm_crtc *crtc)
{
return to_intel_crtc(crtc)->active && crtc->fb && crtc->mode.clock;
}
static void i8xx_disable_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 fbc_ctl;
fbc_ctl = I915_READ(FBC_CONTROL);
if ((fbc_ctl & FBC_CTL_EN) == 0)
return;
fbc_ctl &= ~FBC_CTL_EN;
I915_WRITE(FBC_CONTROL, fbc_ctl);
if (wait_for((I915_READ(FBC_STATUS) & FBC_STAT_COMPRESSING) == 0, 10)) {
DRM_DEBUG_KMS("FBC idle timed out\n");
return;
}
DRM_DEBUG_KMS("disabled FBC\n");
}
static void i8xx_enable_fbc(struct drm_crtc *crtc, unsigned long interval)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->fb;
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int cfb_pitch;
int plane, i;
u32 fbc_ctl, fbc_ctl2;
cfb_pitch = dev_priv->cfb_size / FBC_LL_SIZE;
if (fb->pitches[0] < cfb_pitch)
cfb_pitch = fb->pitches[0];
cfb_pitch = (cfb_pitch / 64) - 1;
plane = intel_crtc->plane == 0 ? FBC_CTL_PLANEA : FBC_CTL_PLANEB;
for (i = 0; i < (FBC_LL_SIZE / 32) + 1; i++)
I915_WRITE(FBC_TAG + (i * 4), 0);
fbc_ctl2 = FBC_CTL_FENCE_DBL | FBC_CTL_IDLE_IMM | FBC_CTL_CPU_FENCE;
fbc_ctl2 |= plane;
I915_WRITE(FBC_CONTROL2, fbc_ctl2);
I915_WRITE(FBC_FENCE_OFF, crtc->y);
fbc_ctl = FBC_CTL_EN | FBC_CTL_PERIODIC;
if (IS_I945GM(dev))
fbc_ctl |= FBC_CTL_C3_IDLE;
fbc_ctl |= (cfb_pitch & 0xff) << FBC_CTL_STRIDE_SHIFT;
fbc_ctl |= (interval & 0x2fff) << FBC_CTL_INTERVAL_SHIFT;
fbc_ctl |= obj->fence_reg;
I915_WRITE(FBC_CONTROL, fbc_ctl);
DRM_DEBUG_KMS("enabled FBC, pitch %d, yoff %d, plane %d, ",
cfb_pitch, crtc->y, intel_crtc->plane);
}
static bool i8xx_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(FBC_CONTROL) & FBC_CTL_EN;
}
static void g4x_enable_fbc(struct drm_crtc *crtc, unsigned long interval)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->fb;
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int plane = intel_crtc->plane == 0 ? DPFC_CTL_PLANEA : DPFC_CTL_PLANEB;
unsigned long stall_watermark = 200;
u32 dpfc_ctl;
dpfc_ctl = plane | DPFC_SR_EN | DPFC_CTL_LIMIT_1X;
dpfc_ctl |= DPFC_CTL_FENCE_EN | obj->fence_reg;
I915_WRITE(DPFC_CHICKEN, DPFC_HT_MODIFY);
I915_WRITE(DPFC_RECOMP_CTL, DPFC_RECOMP_STALL_EN |
(stall_watermark << DPFC_RECOMP_STALL_WM_SHIFT) |
(interval << DPFC_RECOMP_TIMER_COUNT_SHIFT));
I915_WRITE(DPFC_FENCE_YOFF, crtc->y);
I915_WRITE(DPFC_CONTROL, I915_READ(DPFC_CONTROL) | DPFC_CTL_EN);
DRM_DEBUG_KMS("enabled fbc on plane %d\n", intel_crtc->plane);
}
static void g4x_disable_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpfc_ctl;
dpfc_ctl = I915_READ(DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(DPFC_CONTROL, dpfc_ctl);
DRM_DEBUG_KMS("disabled FBC\n");
}
}
static bool g4x_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(DPFC_CONTROL) & DPFC_CTL_EN;
}
static void sandybridge_blit_fbc_update(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 blt_ecoskpd;
gen6_gt_force_wake_get(dev_priv);
blt_ecoskpd = I915_READ(GEN6_BLITTER_ECOSKPD);
blt_ecoskpd |= GEN6_BLITTER_FBC_NOTIFY <<
GEN6_BLITTER_LOCK_SHIFT;
I915_WRITE(GEN6_BLITTER_ECOSKPD, blt_ecoskpd);
blt_ecoskpd |= GEN6_BLITTER_FBC_NOTIFY;
I915_WRITE(GEN6_BLITTER_ECOSKPD, blt_ecoskpd);
blt_ecoskpd &= ~(GEN6_BLITTER_FBC_NOTIFY <<
GEN6_BLITTER_LOCK_SHIFT);
I915_WRITE(GEN6_BLITTER_ECOSKPD, blt_ecoskpd);
POSTING_READ(GEN6_BLITTER_ECOSKPD);
gen6_gt_force_wake_put(dev_priv);
}
static void ironlake_enable_fbc(struct drm_crtc *crtc, unsigned long interval)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->fb;
struct intel_framebuffer *intel_fb = to_intel_framebuffer(fb);
struct drm_i915_gem_object *obj = intel_fb->obj;
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int plane = intel_crtc->plane == 0 ? DPFC_CTL_PLANEA : DPFC_CTL_PLANEB;
unsigned long stall_watermark = 200;
u32 dpfc_ctl;
dpfc_ctl = I915_READ(ILK_DPFC_CONTROL);
dpfc_ctl &= DPFC_RESERVED;
dpfc_ctl |= (plane | DPFC_CTL_LIMIT_1X);
dpfc_ctl |= DPFC_CTL_PERSISTENT_MODE;
dpfc_ctl |= (DPFC_CTL_FENCE_EN | obj->fence_reg);
I915_WRITE(ILK_DPFC_CHICKEN, DPFC_HT_MODIFY);
I915_WRITE(ILK_DPFC_RECOMP_CTL, DPFC_RECOMP_STALL_EN |
(stall_watermark << DPFC_RECOMP_STALL_WM_SHIFT) |
(interval << DPFC_RECOMP_TIMER_COUNT_SHIFT));
I915_WRITE(ILK_DPFC_FENCE_YOFF, crtc->y);
I915_WRITE(ILK_FBC_RT_BASE, obj->gtt_offset | ILK_FBC_RT_VALID);
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
if (IS_GEN6(dev)) {
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | obj->fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, crtc->y);
sandybridge_blit_fbc_update(dev);
}
DRM_DEBUG_KMS("enabled fbc on plane %d\n", intel_crtc->plane);
}
static void ironlake_disable_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpfc_ctl;
dpfc_ctl = I915_READ(ILK_DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl);
DRM_DEBUG_KMS("disabled FBC\n");
}
}
static bool ironlake_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(ILK_DPFC_CONTROL) & DPFC_CTL_EN;
}
bool intel_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv->display.fbc_enabled)
return false;
return dev_priv->display.fbc_enabled(dev);
}
static void intel_fbc_work_fn(struct work_struct *__work)
{
struct intel_fbc_work *work =
container_of(to_delayed_work(__work),
struct intel_fbc_work, work);
struct drm_device *dev = work->crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev->struct_mutex);
if (work == dev_priv->fbc_work) {
if (work->crtc->fb == work->fb) {
dev_priv->display.enable_fbc(work->crtc,
work->interval);
dev_priv->cfb_plane = to_intel_crtc(work->crtc)->plane;
dev_priv->cfb_fb = work->crtc->fb->base.id;
dev_priv->cfb_y = work->crtc->y;
}
dev_priv->fbc_work = NULL;
}
mutex_unlock(&dev->struct_mutex);
kfree(work);
}
static void intel_cancel_fbc_work(struct drm_i915_private *dev_priv)
{
if (dev_priv->fbc_work == NULL)
return;
DRM_DEBUG_KMS("cancelling pending FBC enable\n");
if (cancel_delayed_work(&dev_priv->fbc_work->work))
kfree(dev_priv->fbc_work);
dev_priv->fbc_work = NULL;
}
void intel_enable_fbc(struct drm_crtc *crtc, unsigned long interval)
{
struct intel_fbc_work *work;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv->display.enable_fbc)
return;
intel_cancel_fbc_work(dev_priv);
work = kzalloc(sizeof *work, GFP_KERNEL);
if (work == NULL) {
dev_priv->display.enable_fbc(crtc, interval);
return;
}
work->crtc = crtc;
work->fb = crtc->fb;
work->interval = interval;
INIT_DELAYED_WORK(&work->work, intel_fbc_work_fn);
dev_priv->fbc_work = work;
DRM_DEBUG_KMS("scheduling delayed FBC enable\n");
schedule_delayed_work(&work->work, msecs_to_jiffies(50));
}
void intel_disable_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
intel_cancel_fbc_work(dev_priv);
if (!dev_priv->display.disable_fbc)
return;
dev_priv->display.disable_fbc(dev);
dev_priv->cfb_plane = -1;
}
void intel_update_fbc(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = NULL, *tmp_crtc;
struct intel_crtc *intel_crtc;
struct drm_framebuffer *fb;
struct intel_framebuffer *intel_fb;
struct drm_i915_gem_object *obj;
int enable_fbc;
if (!i915_powersave)
return;
if (!I915_HAS_FBC(dev))
return;
list_for_each_entry(tmp_crtc, &dev->mode_config.crtc_list, head) {
if (intel_crtc_active(tmp_crtc) &&
!to_intel_crtc(tmp_crtc)->primary_disabled) {
if (crtc) {
DRM_DEBUG_KMS("more than one pipe active, disabling compression\n");
dev_priv->no_fbc_reason = FBC_MULTIPLE_PIPES;
goto out_disable;
}
crtc = tmp_crtc;
}
}
if (!crtc || crtc->fb == NULL) {
DRM_DEBUG_KMS("no output, disabling\n");
dev_priv->no_fbc_reason = FBC_NO_OUTPUT;
goto out_disable;
}
intel_crtc = to_intel_crtc(crtc);
fb = crtc->fb;
intel_fb = to_intel_framebuffer(fb);
obj = intel_fb->obj;
enable_fbc = i915_enable_fbc;
if (enable_fbc < 0) {
DRM_DEBUG_KMS("fbc set to per-chip default\n");
enable_fbc = 1;
if (INTEL_INFO(dev)->gen <= 6)
enable_fbc = 0;
}
if (!enable_fbc) {
DRM_DEBUG_KMS("fbc disabled per module param\n");
dev_priv->no_fbc_reason = FBC_MODULE_PARAM;
goto out_disable;
}
if ((crtc->mode.flags & DRM_MODE_FLAG_INTERLACE) ||
(crtc->mode.flags & DRM_MODE_FLAG_DBLSCAN)) {
DRM_DEBUG_KMS("mode incompatible with compression, "
"disabling\n");
dev_priv->no_fbc_reason = FBC_UNSUPPORTED_MODE;
goto out_disable;
}
if ((crtc->mode.hdisplay > 2048) ||
(crtc->mode.vdisplay > 1536)) {
DRM_DEBUG_KMS("mode too large for compression, disabling\n");
dev_priv->no_fbc_reason = FBC_MODE_TOO_LARGE;
goto out_disable;
}
if ((IS_I915GM(dev) || IS_I945GM(dev)) && intel_crtc->plane != 0) {
DRM_DEBUG_KMS("plane not 0, disabling compression\n");
dev_priv->no_fbc_reason = FBC_BAD_PLANE;
goto out_disable;
}
if (obj->tiling_mode != I915_TILING_X ||
obj->fence_reg == I915_FENCE_REG_NONE) {
DRM_DEBUG_KMS("framebuffer not tiled or fenced, disabling compression\n");
dev_priv->no_fbc_reason = FBC_NOT_TILED;
goto out_disable;
}
if (in_dbg_master())
goto out_disable;
if (i915_gem_stolen_setup_compression(dev, intel_fb->obj->base.size)) {
DRM_INFO("not enough stolen space for compressed buffer (need %zd bytes), disabling\n", intel_fb->obj->base.size);
DRM_INFO("hint: you may be able to increase stolen memory size in the BIOS to avoid this\n");
DRM_DEBUG_KMS("framebuffer too large, disabling compression\n");
dev_priv->no_fbc_reason = FBC_STOLEN_TOO_SMALL;
goto out_disable;
}
if (dev_priv->cfb_plane == intel_crtc->plane &&
dev_priv->cfb_fb == fb->base.id &&
dev_priv->cfb_y == crtc->y)
return;
if (intel_fbc_enabled(dev)) {
DRM_DEBUG_KMS("disabling active FBC for update\n");
intel_disable_fbc(dev);
}
intel_enable_fbc(crtc, 500);
return;
out_disable:
if (intel_fbc_enabled(dev)) {
DRM_DEBUG_KMS("unsupported config, disabling FBC\n");
intel_disable_fbc(dev);
}
i915_gem_stolen_cleanup_compression(dev);
}
static void i915_pineview_get_mem_freq(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u32 tmp;
tmp = I915_READ(CLKCFG);
switch (tmp & CLKCFG_FSB_MASK) {
case CLKCFG_FSB_533:
dev_priv->fsb_freq = 533;
break;
case CLKCFG_FSB_800:
dev_priv->fsb_freq = 800;
break;
case CLKCFG_FSB_667:
dev_priv->fsb_freq = 667;
break;
case CLKCFG_FSB_400:
dev_priv->fsb_freq = 400;
break;
}
switch (tmp & CLKCFG_MEM_MASK) {
case CLKCFG_MEM_533:
dev_priv->mem_freq = 533;
break;
case CLKCFG_MEM_667:
dev_priv->mem_freq = 667;
break;
case CLKCFG_MEM_800:
dev_priv->mem_freq = 800;
break;
}
tmp = I915_READ(CSHRDDR3CTL);
dev_priv->is_ddr3 = (tmp & CSHRDDR3CTL_DDR3) ? 1 : 0;
}
static void i915_ironlake_get_mem_freq(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u16 ddrpll, csipll;
ddrpll = I915_READ16(DDRMPLL1);
csipll = I915_READ16(CSIPLL0);
switch (ddrpll & 0xff) {
case 0xc:
dev_priv->mem_freq = 800;
break;
case 0x10:
dev_priv->mem_freq = 1066;
break;
case 0x14:
dev_priv->mem_freq = 1333;
break;
case 0x18:
dev_priv->mem_freq = 1600;
break;
default:
DRM_DEBUG_DRIVER("unknown memory frequency 0x%02x\n",
ddrpll & 0xff);
dev_priv->mem_freq = 0;
break;
}
dev_priv->ips.r_t = dev_priv->mem_freq;
switch (csipll & 0x3ff) {
case 0x00c:
dev_priv->fsb_freq = 3200;
break;
case 0x00e:
dev_priv->fsb_freq = 3733;
break;
case 0x010:
dev_priv->fsb_freq = 4266;
break;
case 0x012:
dev_priv->fsb_freq = 4800;
break;
case 0x014:
dev_priv->fsb_freq = 5333;
break;
case 0x016:
dev_priv->fsb_freq = 5866;
break;
case 0x018:
dev_priv->fsb_freq = 6400;
break;
default:
DRM_DEBUG_DRIVER("unknown fsb frequency 0x%04x\n",
csipll & 0x3ff);
dev_priv->fsb_freq = 0;
break;
}
if (dev_priv->fsb_freq == 3200) {
dev_priv->ips.c_m = 0;
} else if (dev_priv->fsb_freq > 3200 && dev_priv->fsb_freq <= 4800) {
dev_priv->ips.c_m = 1;
} else {
dev_priv->ips.c_m = 2;
}
}
static const struct cxsr_latency *intel_get_cxsr_latency(int is_desktop,
int is_ddr3,
int fsb,
int mem)
{
const struct cxsr_latency *latency;
int i;
if (fsb == 0 || mem == 0)
return NULL;
for (i = 0; i < ARRAY_SIZE(cxsr_latency_table); i++) {
latency = &cxsr_latency_table[i];
if (is_desktop == latency->is_desktop &&
is_ddr3 == latency->is_ddr3 &&
fsb == latency->fsb_freq && mem == latency->mem_freq)
return latency;
}
DRM_DEBUG_KMS("Unknown FSB/MEM found, disable CxSR\n");
return NULL;
}
static void pineview_disable_cxsr(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(DSPFW3, I915_READ(DSPFW3) & ~PINEVIEW_SELF_REFRESH_EN);
}
static int i9xx_get_fifo_size(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dsparb = I915_READ(DSPARB);
int size;
size = dsparb & 0x7f;
if (plane)
size = ((dsparb >> DSPARB_CSTART_SHIFT) & 0x7f) - size;
DRM_DEBUG_KMS("FIFO size - (0x%08x) %s: %d\n", dsparb,
plane ? "B" : "A", size);
return size;
}
static int i85x_get_fifo_size(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dsparb = I915_READ(DSPARB);
int size;
size = dsparb & 0x1ff;
if (plane)
size = ((dsparb >> DSPARB_BEND_SHIFT) & 0x1ff) - size;
size >>= 1;
DRM_DEBUG_KMS("FIFO size - (0x%08x) %s: %d\n", dsparb,
plane ? "B" : "A", size);
return size;
}
static int i845_get_fifo_size(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dsparb = I915_READ(DSPARB);
int size;
size = dsparb & 0x7f;
size >>= 2;
DRM_DEBUG_KMS("FIFO size - (0x%08x) %s: %d\n", dsparb,
plane ? "B" : "A",
size);
return size;
}
static int i830_get_fifo_size(struct drm_device *dev, int plane)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dsparb = I915_READ(DSPARB);
int size;
size = dsparb & 0x7f;
size >>= 1;
DRM_DEBUG_KMS("FIFO size - (0x%08x) %s: %d\n", dsparb,
plane ? "B" : "A", size);
return size;
}
static unsigned long intel_calculate_wm(unsigned long clock_in_khz,
const struct intel_watermark_params *wm,
int fifo_size,
int pixel_size,
unsigned long latency_ns)
{
long entries_required, wm_size;
entries_required = ((clock_in_khz / 1000) * pixel_size * latency_ns) /
1000;
entries_required = DIV_ROUND_UP(entries_required, wm->cacheline_size);
DRM_DEBUG_KMS("FIFO entries required for mode: %ld\n", entries_required);
wm_size = fifo_size - (entries_required + wm->guard_size);
DRM_DEBUG_KMS("FIFO watermark level: %ld\n", wm_size);
if (wm_size > (long)wm->max_wm)
wm_size = wm->max_wm;
if (wm_size <= 0)
wm_size = wm->default_wm;
return wm_size;
}
static struct drm_crtc *single_enabled_crtc(struct drm_device *dev)
{
struct drm_crtc *crtc, *enabled = NULL;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (intel_crtc_active(crtc)) {
if (enabled)
return NULL;
enabled = crtc;
}
}
return enabled;
}
static void pineview_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
const struct cxsr_latency *latency;
u32 reg;
unsigned long wm;
latency = intel_get_cxsr_latency(IS_PINEVIEW_G(dev), dev_priv->is_ddr3,
dev_priv->fsb_freq, dev_priv->mem_freq);
if (!latency) {
DRM_DEBUG_KMS("Unknown FSB/MEM found, disable CxSR\n");
pineview_disable_cxsr(dev);
return;
}
crtc = single_enabled_crtc(dev);
if (crtc) {
int clock = crtc->mode.clock;
int pixel_size = crtc->fb->bits_per_pixel / 8;
wm = intel_calculate_wm(clock, &pineview_display_wm,
pineview_display_wm.fifo_size,
pixel_size, latency->display_sr);
reg = I915_READ(DSPFW1);
reg &= ~DSPFW_SR_MASK;
reg |= wm << DSPFW_SR_SHIFT;
I915_WRITE(DSPFW1, reg);
DRM_DEBUG_KMS("DSPFW1 register is %x\n", reg);
wm = intel_calculate_wm(clock, &pineview_cursor_wm,
pineview_display_wm.fifo_size,
pixel_size, latency->cursor_sr);
reg = I915_READ(DSPFW3);
reg &= ~DSPFW_CURSOR_SR_MASK;
reg |= (wm & 0x3f) << DSPFW_CURSOR_SR_SHIFT;
I915_WRITE(DSPFW3, reg);
wm = intel_calculate_wm(clock, &pineview_display_hplloff_wm,
pineview_display_hplloff_wm.fifo_size,
pixel_size, latency->display_hpll_disable);
reg = I915_READ(DSPFW3);
reg &= ~DSPFW_HPLL_SR_MASK;
reg |= wm & DSPFW_HPLL_SR_MASK;
I915_WRITE(DSPFW3, reg);
wm = intel_calculate_wm(clock, &pineview_cursor_hplloff_wm,
pineview_display_hplloff_wm.fifo_size,
pixel_size, latency->cursor_hpll_disable);
reg = I915_READ(DSPFW3);
reg &= ~DSPFW_HPLL_CURSOR_MASK;
reg |= (wm & 0x3f) << DSPFW_HPLL_CURSOR_SHIFT;
I915_WRITE(DSPFW3, reg);
DRM_DEBUG_KMS("DSPFW3 register is %x\n", reg);
I915_WRITE(DSPFW3,
I915_READ(DSPFW3) | PINEVIEW_SELF_REFRESH_EN);
DRM_DEBUG_KMS("Self-refresh is enabled\n");
} else {
pineview_disable_cxsr(dev);
DRM_DEBUG_KMS("Self-refresh is disabled\n");
}
}
static bool g4x_compute_wm0(struct drm_device *dev,
int plane,
const struct intel_watermark_params *display,
int display_latency_ns,
const struct intel_watermark_params *cursor,
int cursor_latency_ns,
int *plane_wm,
int *cursor_wm)
{
struct drm_crtc *crtc;
int htotal, hdisplay, clock, pixel_size;
int line_time_us, line_count;
int entries, tlb_miss;
crtc = intel_get_crtc_for_plane(dev, plane);
if (!intel_crtc_active(crtc)) {
*cursor_wm = cursor->guard_size;
*plane_wm = display->guard_size;
return false;
}
htotal = crtc->mode.htotal;
hdisplay = crtc->mode.hdisplay;
clock = crtc->mode.clock;
pixel_size = crtc->fb->bits_per_pixel / 8;
entries = ((clock * pixel_size / 1000) * display_latency_ns) / 1000;
tlb_miss = display->fifo_size*display->cacheline_size - hdisplay * 8;
if (tlb_miss > 0)
entries += tlb_miss;
entries = DIV_ROUND_UP(entries, display->cacheline_size);
*plane_wm = entries + display->guard_size;
if (*plane_wm > (int)display->max_wm)
*plane_wm = display->max_wm;
line_time_us = ((htotal * 1000) / clock);
line_count = (cursor_latency_ns / line_time_us + 1000) / 1000;
entries = line_count * 64 * pixel_size;
tlb_miss = cursor->fifo_size*cursor->cacheline_size - hdisplay * 8;
if (tlb_miss > 0)
entries += tlb_miss;
entries = DIV_ROUND_UP(entries, cursor->cacheline_size);
*cursor_wm = entries + cursor->guard_size;
if (*cursor_wm > (int)cursor->max_wm)
*cursor_wm = (int)cursor->max_wm;
return true;
}
static bool g4x_check_srwm(struct drm_device *dev,
int display_wm, int cursor_wm,
const struct intel_watermark_params *display,
const struct intel_watermark_params *cursor)
{
DRM_DEBUG_KMS("SR watermark: display plane %d, cursor %d\n",
display_wm, cursor_wm);
if (display_wm > display->max_wm) {
DRM_DEBUG_KMS("display watermark is too large(%d/%ld), disabling\n",
display_wm, display->max_wm);
return false;
}
if (cursor_wm > cursor->max_wm) {
DRM_DEBUG_KMS("cursor watermark is too large(%d/%ld), disabling\n",
cursor_wm, cursor->max_wm);
return false;
}
if (!(display_wm || cursor_wm)) {
DRM_DEBUG_KMS("SR latency is 0, disabling\n");
return false;
}
return true;
}
static bool g4x_compute_srwm(struct drm_device *dev,
int plane,
int latency_ns,
const struct intel_watermark_params *display,
const struct intel_watermark_params *cursor,
int *display_wm, int *cursor_wm)
{
struct drm_crtc *crtc;
int hdisplay, htotal, pixel_size, clock;
unsigned long line_time_us;
int line_count, line_size;
int small, large;
int entries;
if (!latency_ns) {
*display_wm = *cursor_wm = 0;
return false;
}
crtc = intel_get_crtc_for_plane(dev, plane);
hdisplay = crtc->mode.hdisplay;
htotal = crtc->mode.htotal;
clock = crtc->mode.clock;
pixel_size = crtc->fb->bits_per_pixel / 8;
line_time_us = (htotal * 1000) / clock;
line_count = (latency_ns / line_time_us + 1000) / 1000;
line_size = hdisplay * pixel_size;
small = ((clock * pixel_size / 1000) * latency_ns) / 1000;
large = line_count * line_size;
entries = DIV_ROUND_UP(min(small, large), display->cacheline_size);
*display_wm = entries + display->guard_size;
entries = line_count * pixel_size * 64;
entries = DIV_ROUND_UP(entries, cursor->cacheline_size);
*cursor_wm = entries + cursor->guard_size;
return g4x_check_srwm(dev,
*display_wm, *cursor_wm,
display, cursor);
}
static bool vlv_compute_drain_latency(struct drm_device *dev,
int plane,
int *plane_prec_mult,
int *plane_dl,
int *cursor_prec_mult,
int *cursor_dl)
{
struct drm_crtc *crtc;
int clock, pixel_size;
int entries;
crtc = intel_get_crtc_for_plane(dev, plane);
if (!intel_crtc_active(crtc))
return false;
clock = crtc->mode.clock;
pixel_size = crtc->fb->bits_per_pixel / 8;
entries = (clock / 1000) * pixel_size;
*plane_prec_mult = (entries > 256) ?
DRAIN_LATENCY_PRECISION_32 : DRAIN_LATENCY_PRECISION_16;
*plane_dl = (64 * (*plane_prec_mult) * 4) / ((clock / 1000) *
pixel_size);
entries = (clock / 1000) * 4;
*cursor_prec_mult = (entries > 256) ?
DRAIN_LATENCY_PRECISION_32 : DRAIN_LATENCY_PRECISION_16;
*cursor_dl = (64 * (*cursor_prec_mult) * 4) / ((clock / 1000) * 4);
return true;
}
static void vlv_update_drain_latency(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int planea_prec, planea_dl, planeb_prec, planeb_dl;
int cursora_prec, cursora_dl, cursorb_prec, cursorb_dl;
int plane_prec_mult, cursor_prec_mult;
if (vlv_compute_drain_latency(dev, 0, &plane_prec_mult, &planea_dl,
&cursor_prec_mult, &cursora_dl)) {
cursora_prec = (cursor_prec_mult == DRAIN_LATENCY_PRECISION_32) ?
DDL_CURSORA_PRECISION_32 : DDL_CURSORA_PRECISION_16;
planea_prec = (plane_prec_mult == DRAIN_LATENCY_PRECISION_32) ?
DDL_PLANEA_PRECISION_32 : DDL_PLANEA_PRECISION_16;
I915_WRITE(VLV_DDL1, cursora_prec |
(cursora_dl << DDL_CURSORA_SHIFT) |
planea_prec | planea_dl);
}
if (vlv_compute_drain_latency(dev, 1, &plane_prec_mult, &planeb_dl,
&cursor_prec_mult, &cursorb_dl)) {
cursorb_prec = (cursor_prec_mult == DRAIN_LATENCY_PRECISION_32) ?
DDL_CURSORB_PRECISION_32 : DDL_CURSORB_PRECISION_16;
planeb_prec = (plane_prec_mult == DRAIN_LATENCY_PRECISION_32) ?
DDL_PLANEB_PRECISION_32 : DDL_PLANEB_PRECISION_16;
I915_WRITE(VLV_DDL2, cursorb_prec |
(cursorb_dl << DDL_CURSORB_SHIFT) |
planeb_prec | planeb_dl);
}
}
static void valleyview_update_wm(struct drm_device *dev)
{
static const int sr_latency_ns = 12000;
struct drm_i915_private *dev_priv = dev->dev_private;
int planea_wm, planeb_wm, cursora_wm, cursorb_wm;
int plane_sr, cursor_sr;
int ignore_plane_sr, ignore_cursor_sr;
unsigned int enabled = 0;
vlv_update_drain_latency(dev);
if (g4x_compute_wm0(dev, PIPE_A,
&valleyview_wm_info, latency_ns,
&valleyview_cursor_wm_info, latency_ns,
&planea_wm, &cursora_wm))
enabled |= 1 << PIPE_A;
if (g4x_compute_wm0(dev, PIPE_B,
&valleyview_wm_info, latency_ns,
&valleyview_cursor_wm_info, latency_ns,
&planeb_wm, &cursorb_wm))
enabled |= 1 << PIPE_B;
if (single_plane_enabled(enabled) &&
g4x_compute_srwm(dev, ffs(enabled) - 1,
sr_latency_ns,
&valleyview_wm_info,
&valleyview_cursor_wm_info,
&plane_sr, &ignore_cursor_sr) &&
g4x_compute_srwm(dev, ffs(enabled) - 1,
2*sr_latency_ns,
&valleyview_wm_info,
&valleyview_cursor_wm_info,
&ignore_plane_sr, &cursor_sr)) {
I915_WRITE(FW_BLC_SELF_VLV, FW_CSPWRDWNEN);
} else {
I915_WRITE(FW_BLC_SELF_VLV,
I915_READ(FW_BLC_SELF_VLV) & ~FW_CSPWRDWNEN);
plane_sr = cursor_sr = 0;
}
DRM_DEBUG_KMS("Setting FIFO watermarks - A: plane=%d, cursor=%d, B: plane=%d, cursor=%d, SR: plane=%d, cursor=%d\n",
planea_wm, cursora_wm,
planeb_wm, cursorb_wm,
plane_sr, cursor_sr);
I915_WRITE(DSPFW1,
(plane_sr << DSPFW_SR_SHIFT) |
(cursorb_wm << DSPFW_CURSORB_SHIFT) |
(planeb_wm << DSPFW_PLANEB_SHIFT) |
planea_wm);
I915_WRITE(DSPFW2,
(I915_READ(DSPFW2) & ~DSPFW_CURSORA_MASK) |
(cursora_wm << DSPFW_CURSORA_SHIFT));
I915_WRITE(DSPFW3,
(I915_READ(DSPFW3) & ~DSPFW_CURSOR_SR_MASK) |
(cursor_sr << DSPFW_CURSOR_SR_SHIFT));
}
static void g4x_update_wm(struct drm_device *dev)
{
static const int sr_latency_ns = 12000;
struct drm_i915_private *dev_priv = dev->dev_private;
int planea_wm, planeb_wm, cursora_wm, cursorb_wm;
int plane_sr, cursor_sr;
unsigned int enabled = 0;
if (g4x_compute_wm0(dev, PIPE_A,
&g4x_wm_info, latency_ns,
&g4x_cursor_wm_info, latency_ns,
&planea_wm, &cursora_wm))
enabled |= 1 << PIPE_A;
if (g4x_compute_wm0(dev, PIPE_B,
&g4x_wm_info, latency_ns,
&g4x_cursor_wm_info, latency_ns,
&planeb_wm, &cursorb_wm))
enabled |= 1 << PIPE_B;
if (single_plane_enabled(enabled) &&
g4x_compute_srwm(dev, ffs(enabled) - 1,
sr_latency_ns,
&g4x_wm_info,
&g4x_cursor_wm_info,
&plane_sr, &cursor_sr)) {
I915_WRITE(FW_BLC_SELF, FW_BLC_SELF_EN);
} else {
I915_WRITE(FW_BLC_SELF,
I915_READ(FW_BLC_SELF) & ~FW_BLC_SELF_EN);
plane_sr = cursor_sr = 0;
}
DRM_DEBUG_KMS("Setting FIFO watermarks - A: plane=%d, cursor=%d, B: plane=%d, cursor=%d, SR: plane=%d, cursor=%d\n",
planea_wm, cursora_wm,
planeb_wm, cursorb_wm,
plane_sr, cursor_sr);
I915_WRITE(DSPFW1,
(plane_sr << DSPFW_SR_SHIFT) |
(cursorb_wm << DSPFW_CURSORB_SHIFT) |
(planeb_wm << DSPFW_PLANEB_SHIFT) |
planea_wm);
I915_WRITE(DSPFW2,
(I915_READ(DSPFW2) & ~DSPFW_CURSORA_MASK) |
(cursora_wm << DSPFW_CURSORA_SHIFT));
I915_WRITE(DSPFW3,
(I915_READ(DSPFW3) & ~(DSPFW_HPLL_SR_EN | DSPFW_CURSOR_SR_MASK)) |
(cursor_sr << DSPFW_CURSOR_SR_SHIFT));
}
static void i965_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
int srwm = 1;
int cursor_sr = 16;
crtc = single_enabled_crtc(dev);
if (crtc) {
static const int sr_latency_ns = 12000;
int clock = crtc->mode.clock;
int htotal = crtc->mode.htotal;
int hdisplay = crtc->mode.hdisplay;
int pixel_size = crtc->fb->bits_per_pixel / 8;
unsigned long line_time_us;
int entries;
line_time_us = ((htotal * 1000) / clock);
entries = (((sr_latency_ns / line_time_us) + 1000) / 1000) *
pixel_size * hdisplay;
entries = DIV_ROUND_UP(entries, I915_FIFO_LINE_SIZE);
srwm = I965_FIFO_SIZE - entries;
if (srwm < 0)
srwm = 1;
srwm &= 0x1ff;
DRM_DEBUG_KMS("self-refresh entries: %d, wm: %d\n",
entries, srwm);
entries = (((sr_latency_ns / line_time_us) + 1000) / 1000) *
pixel_size * 64;
entries = DIV_ROUND_UP(entries,
i965_cursor_wm_info.cacheline_size);
cursor_sr = i965_cursor_wm_info.fifo_size -
(entries + i965_cursor_wm_info.guard_size);
if (cursor_sr > i965_cursor_wm_info.max_wm)
cursor_sr = i965_cursor_wm_info.max_wm;
DRM_DEBUG_KMS("self-refresh watermark: display plane %d "
"cursor %d\n", srwm, cursor_sr);
if (IS_CRESTLINE(dev))
I915_WRITE(FW_BLC_SELF, FW_BLC_SELF_EN);
} else {
if (IS_CRESTLINE(dev))
I915_WRITE(FW_BLC_SELF, I915_READ(FW_BLC_SELF)
& ~FW_BLC_SELF_EN);
}
DRM_DEBUG_KMS("Setting FIFO watermarks - A: 8, B: 8, C: 8, SR %d\n",
srwm);
I915_WRITE(DSPFW1, (srwm << DSPFW_SR_SHIFT) |
(8 << 16) | (8 << 8) | (8 << 0));
I915_WRITE(DSPFW2, (8 << 8) | (8 << 0));
I915_WRITE(DSPFW3, (cursor_sr << DSPFW_CURSOR_SR_SHIFT));
}
static void i9xx_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
const struct intel_watermark_params *wm_info;
uint32_t fwater_lo;
uint32_t fwater_hi;
int cwm, srwm = 1;
int fifo_size;
int planea_wm, planeb_wm;
struct drm_crtc *crtc, *enabled = NULL;
if (IS_I945GM(dev))
wm_info = &i945_wm_info;
else if (!IS_GEN2(dev))
wm_info = &i915_wm_info;
else
wm_info = &i855_wm_info;
fifo_size = dev_priv->display.get_fifo_size(dev, 0);
crtc = intel_get_crtc_for_plane(dev, 0);
if (intel_crtc_active(crtc)) {
int cpp = crtc->fb->bits_per_pixel / 8;
if (IS_GEN2(dev))
cpp = 4;
planea_wm = intel_calculate_wm(crtc->mode.clock,
wm_info, fifo_size, cpp,
latency_ns);
enabled = crtc;
} else
planea_wm = fifo_size - wm_info->guard_size;
fifo_size = dev_priv->display.get_fifo_size(dev, 1);
crtc = intel_get_crtc_for_plane(dev, 1);
if (intel_crtc_active(crtc)) {
int cpp = crtc->fb->bits_per_pixel / 8;
if (IS_GEN2(dev))
cpp = 4;
planeb_wm = intel_calculate_wm(crtc->mode.clock,
wm_info, fifo_size, cpp,
latency_ns);
if (enabled == NULL)
enabled = crtc;
else
enabled = NULL;
} else
planeb_wm = fifo_size - wm_info->guard_size;
DRM_DEBUG_KMS("FIFO watermarks - A: %d, B: %d\n", planea_wm, planeb_wm);
cwm = 2;
if (IS_I945G(dev) || IS_I945GM(dev))
I915_WRITE(FW_BLC_SELF, FW_BLC_SELF_EN_MASK | 0);
else if (IS_I915GM(dev))
I915_WRITE(INSTPM, I915_READ(INSTPM) & ~INSTPM_SELF_EN);
if (HAS_FW_BLC(dev) && enabled) {
static const int sr_latency_ns = 6000;
int clock = enabled->mode.clock;
int htotal = enabled->mode.htotal;
int hdisplay = enabled->mode.hdisplay;
int pixel_size = enabled->fb->bits_per_pixel / 8;
unsigned long line_time_us;
int entries;
line_time_us = (htotal * 1000) / clock;
entries = (((sr_latency_ns / line_time_us) + 1000) / 1000) *
pixel_size * hdisplay;
entries = DIV_ROUND_UP(entries, wm_info->cacheline_size);
DRM_DEBUG_KMS("self-refresh entries: %d\n", entries);
srwm = wm_info->fifo_size - entries;
if (srwm < 0)
srwm = 1;
if (IS_I945G(dev) || IS_I945GM(dev))
I915_WRITE(FW_BLC_SELF,
FW_BLC_SELF_FIFO_MASK | (srwm & 0xff));
else if (IS_I915GM(dev))
I915_WRITE(FW_BLC_SELF, srwm & 0x3f);
}
DRM_DEBUG_KMS("Setting FIFO watermarks - A: %d, B: %d, C: %d, SR %d\n",
planea_wm, planeb_wm, cwm, srwm);
fwater_lo = ((planeb_wm & 0x3f) << 16) | (planea_wm & 0x3f);
fwater_hi = (cwm & 0x1f);
fwater_lo = fwater_lo | (1 << 24) | (1 << 8);
fwater_hi = fwater_hi | (1 << 8);
I915_WRITE(FW_BLC, fwater_lo);
I915_WRITE(FW_BLC2, fwater_hi);
if (HAS_FW_BLC(dev)) {
if (enabled) {
if (IS_I945G(dev) || IS_I945GM(dev))
I915_WRITE(FW_BLC_SELF,
FW_BLC_SELF_EN_MASK | FW_BLC_SELF_EN);
else if (IS_I915GM(dev))
I915_WRITE(INSTPM, I915_READ(INSTPM) | INSTPM_SELF_EN);
DRM_DEBUG_KMS("memory self refresh enabled\n");
} else
DRM_DEBUG_KMS("memory self refresh disabled\n");
}
}
static void i830_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
uint32_t fwater_lo;
int planea_wm;
crtc = single_enabled_crtc(dev);
if (crtc == NULL)
return;
planea_wm = intel_calculate_wm(crtc->mode.clock, &i830_wm_info,
dev_priv->display.get_fifo_size(dev, 0),
4, latency_ns);
fwater_lo = I915_READ(FW_BLC) & ~0xfff;
fwater_lo |= (3<<8) | planea_wm;
DRM_DEBUG_KMS("Setting FIFO watermarks - A: %d\n", planea_wm);
I915_WRITE(FW_BLC, fwater_lo);
}
static bool ironlake_check_srwm(struct drm_device *dev, int level,
int fbc_wm, int display_wm, int cursor_wm,
const struct intel_watermark_params *display,
const struct intel_watermark_params *cursor)
{
struct drm_i915_private *dev_priv = dev->dev_private;
DRM_DEBUG_KMS("watermark %d: display plane %d, fbc lines %d,"
" cursor %d\n", level, display_wm, fbc_wm, cursor_wm);
if (fbc_wm > SNB_FBC_MAX_SRWM) {
DRM_DEBUG_KMS("fbc watermark(%d) is too large(%d), disabling wm%d+\n",
fbc_wm, SNB_FBC_MAX_SRWM, level);
I915_WRITE(DISP_ARB_CTL,
I915_READ(DISP_ARB_CTL) | DISP_FBC_WM_DIS);
return false;
}
if (display_wm > display->max_wm) {
DRM_DEBUG_KMS("display watermark(%d) is too large(%d), disabling wm%d+\n",
display_wm, SNB_DISPLAY_MAX_SRWM, level);
return false;
}
if (cursor_wm > cursor->max_wm) {
DRM_DEBUG_KMS("cursor watermark(%d) is too large(%d), disabling wm%d+\n",
cursor_wm, SNB_CURSOR_MAX_SRWM, level);
return false;
}
if (!(fbc_wm || display_wm || cursor_wm)) {
DRM_DEBUG_KMS("latency %d is 0, disabling wm%d+\n", level, level);
return false;
}
return true;
}
static bool ironlake_compute_srwm(struct drm_device *dev, int level, int plane,
int latency_ns,
const struct intel_watermark_params *display,
const struct intel_watermark_params *cursor,
int *fbc_wm, int *display_wm, int *cursor_wm)
{
struct drm_crtc *crtc;
unsigned long line_time_us;
int hdisplay, htotal, pixel_size, clock;
int line_count, line_size;
int small, large;
int entries;
if (!latency_ns) {
*fbc_wm = *display_wm = *cursor_wm = 0;
return false;
}
crtc = intel_get_crtc_for_plane(dev, plane);
hdisplay = crtc->mode.hdisplay;
htotal = crtc->mode.htotal;
clock = crtc->mode.clock;
pixel_size = crtc->fb->bits_per_pixel / 8;
line_time_us = (htotal * 1000) / clock;
line_count = (latency_ns / line_time_us + 1000) / 1000;
line_size = hdisplay * pixel_size;
small = ((clock * pixel_size / 1000) * latency_ns) / 1000;
large = line_count * line_size;
entries = DIV_ROUND_UP(min(small, large), display->cacheline_size);
*display_wm = entries + display->guard_size;
*fbc_wm = DIV_ROUND_UP(*display_wm * 64, line_size) + 2;
entries = line_count * pixel_size * 64;
entries = DIV_ROUND_UP(entries, cursor->cacheline_size);
*cursor_wm = entries + cursor->guard_size;
return ironlake_check_srwm(dev, level,
*fbc_wm, *display_wm, *cursor_wm,
display, cursor);
}
static void ironlake_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int fbc_wm, plane_wm, cursor_wm;
unsigned int enabled;
enabled = 0;
if (g4x_compute_wm0(dev, PIPE_A,
&ironlake_display_wm_info,
ILK_LP0_PLANE_LATENCY,
&ironlake_cursor_wm_info,
ILK_LP0_CURSOR_LATENCY,
&plane_wm, &cursor_wm)) {
I915_WRITE(WM0_PIPEA_ILK,
(plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm);
DRM_DEBUG_KMS("FIFO watermarks For pipe A -"
" plane %d, " "cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1 << PIPE_A;
}
if (g4x_compute_wm0(dev, PIPE_B,
&ironlake_display_wm_info,
ILK_LP0_PLANE_LATENCY,
&ironlake_cursor_wm_info,
ILK_LP0_CURSOR_LATENCY,
&plane_wm, &cursor_wm)) {
I915_WRITE(WM0_PIPEB_ILK,
(plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm);
DRM_DEBUG_KMS("FIFO watermarks For pipe B -"
" plane %d, cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1 << PIPE_B;
}
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
if (!single_plane_enabled(enabled))
return;
enabled = ffs(enabled) - 1;
if (!ironlake_compute_srwm(dev, 1, enabled,
ILK_READ_WM1_LATENCY() * 500,
&ironlake_display_srwm_info,
&ironlake_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM1_LP_ILK,
WM1_LP_SR_EN |
(ILK_READ_WM1_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
if (!ironlake_compute_srwm(dev, 2, enabled,
ILK_READ_WM2_LATENCY() * 500,
&ironlake_display_srwm_info,
&ironlake_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM2_LP_ILK,
WM2_LP_EN |
(ILK_READ_WM2_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
}
static void sandybridge_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int latency = SNB_READ_WM0_LATENCY() * 100;
u32 val;
int fbc_wm, plane_wm, cursor_wm;
unsigned int enabled;
enabled = 0;
if (g4x_compute_wm0(dev, PIPE_A,
&sandybridge_display_wm_info, latency,
&sandybridge_cursor_wm_info, latency,
&plane_wm, &cursor_wm)) {
val = I915_READ(WM0_PIPEA_ILK);
val &= ~(WM0_PIPE_PLANE_MASK | WM0_PIPE_CURSOR_MASK);
I915_WRITE(WM0_PIPEA_ILK, val |
((plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm));
DRM_DEBUG_KMS("FIFO watermarks For pipe A -"
" plane %d, " "cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1 << PIPE_A;
}
if (g4x_compute_wm0(dev, PIPE_B,
&sandybridge_display_wm_info, latency,
&sandybridge_cursor_wm_info, latency,
&plane_wm, &cursor_wm)) {
val = I915_READ(WM0_PIPEB_ILK);
val &= ~(WM0_PIPE_PLANE_MASK | WM0_PIPE_CURSOR_MASK);
I915_WRITE(WM0_PIPEB_ILK, val |
((plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm));
DRM_DEBUG_KMS("FIFO watermarks For pipe B -"
" plane %d, cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1 << PIPE_B;
}
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
if (!single_plane_enabled(enabled) ||
dev_priv->sprite_scaling_enabled)
return;
enabled = ffs(enabled) - 1;
if (!ironlake_compute_srwm(dev, 1, enabled,
SNB_READ_WM1_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM1_LP_ILK,
WM1_LP_SR_EN |
(SNB_READ_WM1_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
if (!ironlake_compute_srwm(dev, 2, enabled,
SNB_READ_WM2_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM2_LP_ILK,
WM2_LP_EN |
(SNB_READ_WM2_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
if (!ironlake_compute_srwm(dev, 3, enabled,
SNB_READ_WM3_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM3_LP_ILK,
WM3_LP_EN |
(SNB_READ_WM3_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
}
static void ivybridge_update_wm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int latency = SNB_READ_WM0_LATENCY() * 100;
u32 val;
int fbc_wm, plane_wm, cursor_wm;
int ignore_fbc_wm, ignore_plane_wm, ignore_cursor_wm;
unsigned int enabled;
enabled = 0;
if (g4x_compute_wm0(dev, PIPE_A,
&sandybridge_display_wm_info, latency,
&sandybridge_cursor_wm_info, latency,
&plane_wm, &cursor_wm)) {
val = I915_READ(WM0_PIPEA_ILK);
val &= ~(WM0_PIPE_PLANE_MASK | WM0_PIPE_CURSOR_MASK);
I915_WRITE(WM0_PIPEA_ILK, val |
((plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm));
DRM_DEBUG_KMS("FIFO watermarks For pipe A -"
" plane %d, " "cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1 << PIPE_A;
}
if (g4x_compute_wm0(dev, PIPE_B,
&sandybridge_display_wm_info, latency,
&sandybridge_cursor_wm_info, latency,
&plane_wm, &cursor_wm)) {
val = I915_READ(WM0_PIPEB_ILK);
val &= ~(WM0_PIPE_PLANE_MASK | WM0_PIPE_CURSOR_MASK);
I915_WRITE(WM0_PIPEB_ILK, val |
((plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm));
DRM_DEBUG_KMS("FIFO watermarks For pipe B -"
" plane %d, cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1 << PIPE_B;
}
if (g4x_compute_wm0(dev, PIPE_C,
&sandybridge_display_wm_info, latency,
&sandybridge_cursor_wm_info, latency,
&plane_wm, &cursor_wm)) {
val = I915_READ(WM0_PIPEC_IVB);
val &= ~(WM0_PIPE_PLANE_MASK | WM0_PIPE_CURSOR_MASK);
I915_WRITE(WM0_PIPEC_IVB, val |
((plane_wm << WM0_PIPE_PLANE_SHIFT) | cursor_wm));
DRM_DEBUG_KMS("FIFO watermarks For pipe C -"
" plane %d, cursor: %d\n",
plane_wm, cursor_wm);
enabled |= 1 << PIPE_C;
}
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
if (!single_plane_enabled(enabled) ||
dev_priv->sprite_scaling_enabled)
return;
enabled = ffs(enabled) - 1;
if (!ironlake_compute_srwm(dev, 1, enabled,
SNB_READ_WM1_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM1_LP_ILK,
WM1_LP_SR_EN |
(SNB_READ_WM1_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
if (!ironlake_compute_srwm(dev, 2, enabled,
SNB_READ_WM2_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &cursor_wm))
return;
I915_WRITE(WM2_LP_ILK,
WM2_LP_EN |
(SNB_READ_WM2_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
if (!ironlake_compute_srwm(dev, 3, enabled,
SNB_READ_WM3_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&fbc_wm, &plane_wm, &ignore_cursor_wm) ||
!ironlake_compute_srwm(dev, 3, enabled,
2 * SNB_READ_WM3_LATENCY() * 500,
&sandybridge_display_srwm_info,
&sandybridge_cursor_srwm_info,
&ignore_fbc_wm, &ignore_plane_wm, &cursor_wm))
return;
I915_WRITE(WM3_LP_ILK,
WM3_LP_EN |
(SNB_READ_WM3_LATENCY() << WM1_LP_LATENCY_SHIFT) |
(fbc_wm << WM1_LP_FBC_SHIFT) |
(plane_wm << WM1_LP_SR_SHIFT) |
cursor_wm);
}
static void
haswell_update_linetime_wm(struct drm_device *dev, int pipe,
struct drm_display_mode *mode)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 temp;
temp = I915_READ(PIPE_WM_LINETIME(pipe));
temp &= ~PIPE_WM_LINETIME_MASK;
temp |= PIPE_WM_LINETIME_TIME(
((mode->crtc_hdisplay * 1000) / mode->clock) * 8);
I915_WRITE(PIPE_WM_LINETIME(pipe), temp);
}
static bool
sandybridge_compute_sprite_wm(struct drm_device *dev, int plane,
uint32_t sprite_width, int pixel_size,
const struct intel_watermark_params *display,
int display_latency_ns, int *sprite_wm)
{
struct drm_crtc *crtc;
int clock;
int entries, tlb_miss;
crtc = intel_get_crtc_for_plane(dev, plane);
if (!intel_crtc_active(crtc)) {
*sprite_wm = display->guard_size;
return false;
}
clock = crtc->mode.clock;
entries = ((clock * pixel_size / 1000) * display_latency_ns) / 1000;
tlb_miss = display->fifo_size*display->cacheline_size -
sprite_width * 8;
if (tlb_miss > 0)
entries += tlb_miss;
entries = DIV_ROUND_UP(entries, display->cacheline_size);
*sprite_wm = entries + display->guard_size;
if (*sprite_wm > (int)display->max_wm)
*sprite_wm = display->max_wm;
return true;
}
static bool
sandybridge_compute_sprite_srwm(struct drm_device *dev, int plane,
uint32_t sprite_width, int pixel_size,
const struct intel_watermark_params *display,
int latency_ns, int *sprite_wm)
{
struct drm_crtc *crtc;
unsigned long line_time_us;
int clock;
int line_count, line_size;
int small, large;
int entries;
if (!latency_ns) {
*sprite_wm = 0;
return false;
}
crtc = intel_get_crtc_for_plane(dev, plane);
clock = crtc->mode.clock;
if (!clock) {
*sprite_wm = 0;
return false;
}
line_time_us = (sprite_width * 1000) / clock;
if (!line_time_us) {
*sprite_wm = 0;
return false;
}
line_count = (latency_ns / line_time_us + 1000) / 1000;
line_size = sprite_width * pixel_size;
small = ((clock * pixel_size / 1000) * latency_ns) / 1000;
large = line_count * line_size;
entries = DIV_ROUND_UP(min(small, large), display->cacheline_size);
*sprite_wm = entries + display->guard_size;
return *sprite_wm > 0x3ff ? false : true;
}
static void sandybridge_update_sprite_wm(struct drm_device *dev, int pipe,
uint32_t sprite_width, int pixel_size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int latency = SNB_READ_WM0_LATENCY() * 100;
u32 val;
int sprite_wm, reg;
int ret;
switch (pipe) {
case 0:
reg = WM0_PIPEA_ILK;
break;
case 1:
reg = WM0_PIPEB_ILK;
break;
case 2:
reg = WM0_PIPEC_IVB;
break;
default:
return;
}
ret = sandybridge_compute_sprite_wm(dev, pipe, sprite_width, pixel_size,
&sandybridge_display_wm_info,
latency, &sprite_wm);
if (!ret) {
DRM_DEBUG_KMS("failed to compute sprite wm for pipe %d\n",
pipe);
return;
}
val = I915_READ(reg);
val &= ~WM0_PIPE_SPRITE_MASK;
I915_WRITE(reg, val | (sprite_wm << WM0_PIPE_SPRITE_SHIFT));
DRM_DEBUG_KMS("sprite watermarks For pipe %d - %d\n", pipe, sprite_wm);
ret = sandybridge_compute_sprite_srwm(dev, pipe, sprite_width,
pixel_size,
&sandybridge_display_srwm_info,
SNB_READ_WM1_LATENCY() * 500,
&sprite_wm);
if (!ret) {
DRM_DEBUG_KMS("failed to compute sprite lp1 wm on pipe %d\n",
pipe);
return;
}
I915_WRITE(WM1S_LP_ILK, sprite_wm);
if (!IS_IVYBRIDGE(dev))
return;
ret = sandybridge_compute_sprite_srwm(dev, pipe, sprite_width,
pixel_size,
&sandybridge_display_srwm_info,
SNB_READ_WM2_LATENCY() * 500,
&sprite_wm);
if (!ret) {
DRM_DEBUG_KMS("failed to compute sprite lp2 wm on pipe %d\n",
pipe);
return;
}
I915_WRITE(WM2S_LP_IVB, sprite_wm);
ret = sandybridge_compute_sprite_srwm(dev, pipe, sprite_width,
pixel_size,
&sandybridge_display_srwm_info,
SNB_READ_WM3_LATENCY() * 500,
&sprite_wm);
if (!ret) {
DRM_DEBUG_KMS("failed to compute sprite lp3 wm on pipe %d\n",
pipe);
return;
}
I915_WRITE(WM3S_LP_IVB, sprite_wm);
}
void intel_update_watermarks(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->display.update_wm)
dev_priv->display.update_wm(dev);
}
void intel_update_linetime_watermarks(struct drm_device *dev,
int pipe, struct drm_display_mode *mode)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->display.update_linetime_wm)
dev_priv->display.update_linetime_wm(dev, pipe, mode);
}
void intel_update_sprite_watermarks(struct drm_device *dev, int pipe,
uint32_t sprite_width, int pixel_size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->display.update_sprite_wm)
dev_priv->display.update_sprite_wm(dev, pipe, sprite_width,
pixel_size);
}
static struct drm_i915_gem_object *
intel_alloc_context_page(struct drm_device *dev)
{
struct drm_i915_gem_object *ctx;
int ret;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
ctx = i915_gem_alloc_object(dev, 4096);
if (!ctx) {
DRM_DEBUG("failed to alloc power context, RC6 disabled\n");
return NULL;
}
ret = i915_gem_object_pin(ctx, 4096, true, false);
if (ret) {
DRM_ERROR("failed to pin power context: %d\n", ret);
goto err_unref;
}
ret = i915_gem_object_set_to_gtt_domain(ctx, 1);
if (ret) {
DRM_ERROR("failed to set-domain on power context: %d\n", ret);
goto err_unpin;
}
return ctx;
err_unpin:
i915_gem_object_unpin(ctx);
err_unref:
drm_gem_object_unreference(&ctx->base);
return NULL;
}
bool ironlake_set_drps(struct drm_device *dev, u8 val)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u16 rgvswctl;
assert_spin_locked(&mchdev_lock);
rgvswctl = I915_READ16(MEMSWCTL);
if (rgvswctl & MEMCTL_CMD_STS) {
DRM_DEBUG("gpu busy, RCS change rejected\n");
return false;
}
rgvswctl = (MEMCTL_CMD_CHFREQ << MEMCTL_CMD_SHIFT) |
(val << MEMCTL_FREQ_SHIFT) | MEMCTL_SFCAVM;
I915_WRITE16(MEMSWCTL, rgvswctl);
POSTING_READ16(MEMSWCTL);
rgvswctl |= MEMCTL_CMD_STS;
I915_WRITE16(MEMSWCTL, rgvswctl);
return true;
}
static void ironlake_enable_drps(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 rgvmodectl = I915_READ(MEMMODECTL);
u8 fmax, fmin, fstart, vstart;
spin_lock_irq(&mchdev_lock);
I915_WRITE16(PMMISC, I915_READ(PMMISC) | MCPPCE_EN);
I915_WRITE16(TSC1, I915_READ(TSC1) | TSE);
I915_WRITE(RCUPEI, 100000);
I915_WRITE(RCDNEI, 100000);
I915_WRITE(RCBMAXAVG, 90000);
I915_WRITE(RCBMINAVG, 80000);
I915_WRITE(MEMIHYST, 1);
fmax = (rgvmodectl & MEMMODE_FMAX_MASK) >> MEMMODE_FMAX_SHIFT;
fmin = (rgvmodectl & MEMMODE_FMIN_MASK);
fstart = (rgvmodectl & MEMMODE_FSTART_MASK) >>
MEMMODE_FSTART_SHIFT;
vstart = (I915_READ(PXVFREQ_BASE + (fstart * 4)) & PXVFREQ_PX_MASK) >>
PXVFREQ_PX_SHIFT;
dev_priv->ips.fmax = fmax;
dev_priv->ips.fstart = fstart;
dev_priv->ips.max_delay = fstart;
dev_priv->ips.min_delay = fmin;
dev_priv->ips.cur_delay = fstart;
DRM_DEBUG_DRIVER("fmax: %d, fmin: %d, fstart: %d\n",
fmax, fmin, fstart);
I915_WRITE(MEMINTREN, MEMINT_CX_SUPR_EN | MEMINT_EVAL_CHG_EN);
I915_WRITE(VIDSTART, vstart);
POSTING_READ(VIDSTART);
rgvmodectl |= MEMMODE_SWMODE_EN;
I915_WRITE(MEMMODECTL, rgvmodectl);
if (wait_for_atomic((I915_READ(MEMSWCTL) & MEMCTL_CMD_STS) == 0, 10))
DRM_ERROR("stuck trying to change perf mode\n");
mdelay(1);
ironlake_set_drps(dev, fstart);
dev_priv->ips.last_count1 = I915_READ(0x112e4) + I915_READ(0x112e8) +
I915_READ(0x112e0);
dev_priv->ips.last_time1 = jiffies_to_msecs(jiffies);
dev_priv->ips.last_count2 = I915_READ(0x112f4);
getrawmonotonic(&dev_priv->ips.last_time2);
spin_unlock_irq(&mchdev_lock);
}
static void ironlake_disable_drps(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u16 rgvswctl;
spin_lock_irq(&mchdev_lock);
rgvswctl = I915_READ16(MEMSWCTL);
I915_WRITE(MEMINTREN, I915_READ(MEMINTREN) & ~MEMINT_EVAL_CHG_EN);
I915_WRITE(MEMINTRSTS, MEMINT_EVAL_CHG);
I915_WRITE(DEIER, I915_READ(DEIER) & ~DE_PCU_EVENT);
I915_WRITE(DEIIR, DE_PCU_EVENT);
I915_WRITE(DEIMR, I915_READ(DEIMR) | DE_PCU_EVENT);
ironlake_set_drps(dev, dev_priv->ips.fstart);
mdelay(1);
rgvswctl |= MEMCTL_CMD_STS;
I915_WRITE(MEMSWCTL, rgvswctl);
mdelay(1);
spin_unlock_irq(&mchdev_lock);
}
static u32 gen6_rps_limits(struct drm_i915_private *dev_priv, u8 *val)
{
u32 limits;
limits = 0;
if (*val >= dev_priv->rps.max_delay)
*val = dev_priv->rps.max_delay;
limits |= dev_priv->rps.max_delay << 24;
if (*val <= dev_priv->rps.min_delay) {
*val = dev_priv->rps.min_delay;
limits |= dev_priv->rps.min_delay << 16;
}
return limits;
}
void gen6_set_rps(struct drm_device *dev, u8 val)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 limits = gen6_rps_limits(dev_priv, &val);
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
WARN_ON(val > dev_priv->rps.max_delay);
WARN_ON(val < dev_priv->rps.min_delay);
if (val == dev_priv->rps.cur_delay)
return;
if (IS_HASWELL(dev))
I915_WRITE(GEN6_RPNSWREQ,
HSW_FREQUENCY(val));
else
I915_WRITE(GEN6_RPNSWREQ,
GEN6_FREQUENCY(val) |
GEN6_OFFSET(0) |
GEN6_AGGRESSIVE_TURBO);
I915_WRITE(GEN6_RP_INTERRUPT_LIMITS, limits);
POSTING_READ(GEN6_RPNSWREQ);
dev_priv->rps.cur_delay = val;
trace_intel_gpu_freq_change(val * 50);
}
static void gen6_disable_rps(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(GEN6_RC_CONTROL, 0);
I915_WRITE(GEN6_RPNSWREQ, 1 << 31);
I915_WRITE(GEN6_PMINTRMSK, 0xffffffff);
I915_WRITE(GEN6_PMIER, 0);
spin_lock_irq(&dev_priv->rps.lock);
dev_priv->rps.pm_iir = 0;
spin_unlock_irq(&dev_priv->rps.lock);
I915_WRITE(GEN6_PMIIR, I915_READ(GEN6_PMIIR));
}
int intel_enable_rc6(const struct drm_device *dev)
{
if (i915_enable_rc6 >= 0)
return i915_enable_rc6;
if (INTEL_INFO(dev)->gen == 5)
return 0;
if (IS_HASWELL(dev)) {
DRM_DEBUG_DRIVER("Haswell: only RC6 available\n");
return INTEL_RC6_ENABLE;
}
if (INTEL_INFO(dev)->gen == 6) {
DRM_DEBUG_DRIVER("Sandybridge: deep RC6 disabled\n");
return INTEL_RC6_ENABLE;
}
DRM_DEBUG_DRIVER("RC6 and deep RC6 enabled\n");
return (INTEL_RC6_ENABLE | INTEL_RC6p_ENABLE);
}
static void gen6_enable_rps(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring;
u32 rp_state_cap;
u32 gt_perf_status;
u32 rc6vids, pcu_mbox, rc6_mask = 0;
u32 gtfifodbg;
int rc6_mode;
int i, ret;
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
I915_WRITE(GEN6_RC_STATE, 0);
if ((gtfifodbg = I915_READ(GTFIFODBG))) {
DRM_ERROR("GT fifo had a previous error %x\n", gtfifodbg);
I915_WRITE(GTFIFODBG, gtfifodbg);
}
gen6_gt_force_wake_get(dev_priv);
rp_state_cap = I915_READ(GEN6_RP_STATE_CAP);
gt_perf_status = I915_READ(GEN6_GT_PERF_STATUS);
dev_priv->rps.hw_max = dev_priv->rps.max_delay = rp_state_cap & 0xff;
dev_priv->rps.min_delay = (rp_state_cap & 0xff0000) >> 16;
dev_priv->rps.cur_delay = 0;
I915_WRITE(GEN6_RC_CONTROL, 0);
I915_WRITE(GEN6_RC1_WAKE_RATE_LIMIT, 1000 << 16);
I915_WRITE(GEN6_RC6_WAKE_RATE_LIMIT, 40 << 16 | 30);
I915_WRITE(GEN6_RC6pp_WAKE_RATE_LIMIT, 30);
I915_WRITE(GEN6_RC_EVALUATION_INTERVAL, 125000);
I915_WRITE(GEN6_RC_IDLE_HYSTERSIS, 25);
for_each_ring(ring, dev_priv, i)
I915_WRITE(RING_MAX_IDLE(ring->mmio_base), 10);
I915_WRITE(GEN6_RC_SLEEP, 0);
I915_WRITE(GEN6_RC1e_THRESHOLD, 1000);
I915_WRITE(GEN6_RC6_THRESHOLD, 50000);
I915_WRITE(GEN6_RC6p_THRESHOLD, 150000);
I915_WRITE(GEN6_RC6pp_THRESHOLD, 64000);
rc6_mode = intel_enable_rc6(dev_priv->dev);
if (rc6_mode & INTEL_RC6_ENABLE)
rc6_mask |= GEN6_RC_CTL_RC6_ENABLE;
if (!IS_HASWELL(dev)) {
if (rc6_mode & INTEL_RC6p_ENABLE)
rc6_mask |= GEN6_RC_CTL_RC6p_ENABLE;
if (rc6_mode & INTEL_RC6pp_ENABLE)
rc6_mask |= GEN6_RC_CTL_RC6pp_ENABLE;
}
DRM_INFO("Enabling RC6 states: RC6 %s, RC6p %s, RC6pp %s\n",
(rc6_mask & GEN6_RC_CTL_RC6_ENABLE) ? "on" : "off",
(rc6_mask & GEN6_RC_CTL_RC6p_ENABLE) ? "on" : "off",
(rc6_mask & GEN6_RC_CTL_RC6pp_ENABLE) ? "on" : "off");
I915_WRITE(GEN6_RC_CONTROL,
rc6_mask |
GEN6_RC_CTL_EI_MODE(1) |
GEN6_RC_CTL_HW_ENABLE);
if (IS_HASWELL(dev)) {
I915_WRITE(GEN6_RPNSWREQ,
HSW_FREQUENCY(10));
I915_WRITE(GEN6_RC_VIDEO_FREQ,
HSW_FREQUENCY(12));
} else {
I915_WRITE(GEN6_RPNSWREQ,
GEN6_FREQUENCY(10) |
GEN6_OFFSET(0) |
GEN6_AGGRESSIVE_TURBO);
I915_WRITE(GEN6_RC_VIDEO_FREQ,
GEN6_FREQUENCY(12));
}
I915_WRITE(GEN6_RP_DOWN_TIMEOUT, 1000000);
I915_WRITE(GEN6_RP_INTERRUPT_LIMITS,
dev_priv->rps.max_delay << 24 |
dev_priv->rps.min_delay << 16);
I915_WRITE(GEN6_RP_UP_THRESHOLD, 59400);
I915_WRITE(GEN6_RP_DOWN_THRESHOLD, 245000);
I915_WRITE(GEN6_RP_UP_EI, 66000);
I915_WRITE(GEN6_RP_DOWN_EI, 350000);
I915_WRITE(GEN6_RP_IDLE_HYSTERSIS, 10);
I915_WRITE(GEN6_RP_CONTROL,
GEN6_RP_MEDIA_TURBO |
GEN6_RP_MEDIA_HW_NORMAL_MODE |
GEN6_RP_MEDIA_IS_GFX |
GEN6_RP_ENABLE |
GEN6_RP_UP_BUSY_AVG |
(IS_HASWELL(dev) ? GEN7_RP_DOWN_IDLE_AVG : GEN6_RP_DOWN_IDLE_CONT));
ret = sandybridge_pcode_write(dev_priv, GEN6_PCODE_WRITE_MIN_FREQ_TABLE, 0);
if (!ret) {
pcu_mbox = 0;
ret = sandybridge_pcode_read(dev_priv, GEN6_READ_OC_PARAMS, &pcu_mbox);
if (!ret && (pcu_mbox & (1<<31))) {
DRM_DEBUG_DRIVER("Overclocking supported. Max: %dMHz, Overclock max: %dMHz\n",
(dev_priv->rps.max_delay & 0xff) * 50,
(pcu_mbox & 0xff) * 50);
dev_priv->rps.hw_max = pcu_mbox & 0xff;
}
} else {
DRM_DEBUG_DRIVER("Failed to set the min frequency\n");
}
gen6_set_rps(dev_priv->dev, (gt_perf_status & 0xff00) >> 8);
I915_WRITE(GEN6_PMIER, GEN6_PM_DEFERRED_EVENTS);
spin_lock_irq(&dev_priv->rps.lock);
WARN_ON(dev_priv->rps.pm_iir != 0);
I915_WRITE(GEN6_PMIMR, 0);
spin_unlock_irq(&dev_priv->rps.lock);
I915_WRITE(GEN6_PMINTRMSK, 0);
rc6vids = 0;
ret = sandybridge_pcode_read(dev_priv, GEN6_PCODE_READ_RC6VIDS, &rc6vids);
if (IS_GEN6(dev) && ret) {
DRM_DEBUG_DRIVER("Couldn't check for BIOS workaround\n");
} else if (IS_GEN6(dev) && (GEN6_DECODE_RC6_VID(rc6vids & 0xff) < 450)) {
DRM_DEBUG_DRIVER("You should update your BIOS. Correcting minimum rc6 voltage (%dmV->%dmV)\n",
GEN6_DECODE_RC6_VID(rc6vids & 0xff), 450);
rc6vids &= 0xffff00;
rc6vids |= GEN6_ENCODE_RC6_VID(450);
ret = sandybridge_pcode_write(dev_priv, GEN6_PCODE_WRITE_RC6VIDS, rc6vids);
if (ret)
DRM_ERROR("Couldn't fix incorrect rc6 voltage\n");
}
gen6_gt_force_wake_put(dev_priv);
}
static void gen6_update_ring_freq(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int min_freq = 15;
unsigned int gpu_freq;
unsigned int max_ia_freq, min_ring_freq;
int scaling_factor = 180;
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
max_ia_freq = cpufreq_quick_get_max(0);
if (!max_ia_freq)
max_ia_freq = tsc_khz;
max_ia_freq /= 1000;
min_ring_freq = I915_READ(MCHBAR_MIRROR_BASE_SNB + DCLK);
min_ring_freq = (2 * 4 * min_ring_freq + 2) / 3;
for (gpu_freq = dev_priv->rps.max_delay; gpu_freq >= dev_priv->rps.min_delay;
gpu_freq--) {
int diff = dev_priv->rps.max_delay - gpu_freq;
unsigned int ia_freq = 0, ring_freq = 0;
if (IS_HASWELL(dev)) {
ring_freq = (gpu_freq * 5 + 3) / 4;
ring_freq = max(min_ring_freq, ring_freq);
} else {
if (gpu_freq < min_freq)
ia_freq = 800;
else
ia_freq = max_ia_freq - ((diff * scaling_factor) / 2);
ia_freq = DIV_ROUND_CLOSEST(ia_freq, 100);
}
sandybridge_pcode_write(dev_priv,
GEN6_PCODE_WRITE_MIN_FREQ_TABLE,
ia_freq << GEN6_PCODE_FREQ_IA_RATIO_SHIFT |
ring_freq << GEN6_PCODE_FREQ_RING_RATIO_SHIFT |
gpu_freq);
}
}
void ironlake_teardown_rc6(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->ips.renderctx) {
i915_gem_object_unpin(dev_priv->ips.renderctx);
drm_gem_object_unreference(&dev_priv->ips.renderctx->base);
dev_priv->ips.renderctx = NULL;
}
if (dev_priv->ips.pwrctx) {
i915_gem_object_unpin(dev_priv->ips.pwrctx);
drm_gem_object_unreference(&dev_priv->ips.pwrctx->base);
dev_priv->ips.pwrctx = NULL;
}
}
static void ironlake_disable_rc6(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (I915_READ(PWRCTXA)) {
I915_WRITE(RSTDBYCTL, I915_READ(RSTDBYCTL) | RCX_SW_EXIT);
wait_for(((I915_READ(RSTDBYCTL) & RSX_STATUS_MASK) == RSX_STATUS_ON),
50);
I915_WRITE(PWRCTXA, 0);
POSTING_READ(PWRCTXA);
I915_WRITE(RSTDBYCTL, I915_READ(RSTDBYCTL) & ~RCX_SW_EXIT);
POSTING_READ(RSTDBYCTL);
}
}
static int ironlake_setup_rc6(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->ips.renderctx == NULL)
dev_priv->ips.renderctx = intel_alloc_context_page(dev);
if (!dev_priv->ips.renderctx)
return -ENOMEM;
if (dev_priv->ips.pwrctx == NULL)
dev_priv->ips.pwrctx = intel_alloc_context_page(dev);
if (!dev_priv->ips.pwrctx) {
ironlake_teardown_rc6(dev);
return -ENOMEM;
}
return 0;
}
static void ironlake_enable_rc6(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring = &dev_priv->ring[RCS];
bool was_interruptible;
int ret;
if (!intel_enable_rc6(dev))
return;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
ret = ironlake_setup_rc6(dev);
if (ret)
return;
was_interruptible = dev_priv->mm.interruptible;
dev_priv->mm.interruptible = false;
ret = intel_ring_begin(ring, 6);
if (ret) {
ironlake_teardown_rc6(dev);
dev_priv->mm.interruptible = was_interruptible;
return;
}
intel_ring_emit(ring, MI_SUSPEND_FLUSH | MI_SUSPEND_FLUSH_EN);
intel_ring_emit(ring, MI_SET_CONTEXT);
intel_ring_emit(ring, dev_priv->ips.renderctx->gtt_offset |
MI_MM_SPACE_GTT |
MI_SAVE_EXT_STATE_EN |
MI_RESTORE_EXT_STATE_EN |
MI_RESTORE_INHIBIT);
intel_ring_emit(ring, MI_SUSPEND_FLUSH);
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_FLUSH);
intel_ring_advance(ring);
ret = intel_ring_idle(ring);
dev_priv->mm.interruptible = was_interruptible;
if (ret) {
DRM_ERROR("failed to enable ironlake power savings\n");
ironlake_teardown_rc6(dev);
return;
}
I915_WRITE(PWRCTXA, dev_priv->ips.pwrctx->gtt_offset | PWRCTX_EN);
I915_WRITE(RSTDBYCTL, I915_READ(RSTDBYCTL) & ~RCX_SW_EXIT);
}
static unsigned long intel_pxfreq(u32 vidfreq)
{
unsigned long freq;
int div = (vidfreq & 0x3f0000) >> 16;
int post = (vidfreq & 0x3000) >> 12;
int pre = (vidfreq & 0x7);
if (!pre)
return 0;
freq = ((div * 133333) / ((1<<post) * pre));
return freq;
}
static unsigned long __i915_chipset_val(struct drm_i915_private *dev_priv)
{
u64 total_count, diff, ret;
u32 count1, count2, count3, m = 0, c = 0;
unsigned long now = jiffies_to_msecs(jiffies), diff1;
int i;
assert_spin_locked(&mchdev_lock);
diff1 = now - dev_priv->ips.last_time1;
if (diff1 <= 10)
return dev_priv->ips.chipset_power;
count1 = I915_READ(DMIEC);
count2 = I915_READ(DDREC);
count3 = I915_READ(CSIEC);
total_count = count1 + count2 + count3;
if (total_count < dev_priv->ips.last_count1) {
diff = ~0UL - dev_priv->ips.last_count1;
diff += total_count;
} else {
diff = total_count - dev_priv->ips.last_count1;
}
for (i = 0; i < ARRAY_SIZE(cparams); i++) {
if (cparams[i].i == dev_priv->ips.c_m &&
cparams[i].t == dev_priv->ips.r_t) {
m = cparams[i].m;
c = cparams[i].c;
break;
}
}
diff = div_u64(diff, diff1);
ret = ((m * diff) + c);
ret = div_u64(ret, 10);
dev_priv->ips.last_count1 = total_count;
dev_priv->ips.last_time1 = now;
dev_priv->ips.chipset_power = ret;
return ret;
}
unsigned long i915_chipset_val(struct drm_i915_private *dev_priv)
{
unsigned long val;
if (dev_priv->info->gen != 5)
return 0;
spin_lock_irq(&mchdev_lock);
val = __i915_chipset_val(dev_priv);
spin_unlock_irq(&mchdev_lock);
return val;
}
unsigned long i915_mch_val(struct drm_i915_private *dev_priv)
{
unsigned long m, x, b;
u32 tsfs;
tsfs = I915_READ(TSFS);
m = ((tsfs & TSFS_SLOPE_MASK) >> TSFS_SLOPE_SHIFT);
x = I915_READ8(TR1);
b = tsfs & TSFS_INTR_MASK;
return ((m * x) / 127) - b;
}
static u16 pvid_to_extvid(struct drm_i915_private *dev_priv, u8 pxvid)
{
static const struct v_table {
u16 vd;
u16 vm;
} v_table[] = {
{ 0, 0, },
{ 375, 0, },
{ 500, 0, },
{ 625, 0, },
{ 750, 0, },
{ 875, 0, },
{ 1000, 0, },
{ 1125, 0, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4250, 3125, },
{ 4375, 3250, },
{ 4500, 3375, },
{ 4625, 3500, },
{ 4750, 3625, },
{ 4875, 3750, },
{ 5000, 3875, },
{ 5125, 4000, },
{ 5250, 4125, },
{ 5375, 4250, },
{ 5500, 4375, },
{ 5625, 4500, },
{ 5750, 4625, },
{ 5875, 4750, },
{ 6000, 4875, },
{ 6125, 5000, },
{ 6250, 5125, },
{ 6375, 5250, },
{ 6500, 5375, },
{ 6625, 5500, },
{ 6750, 5625, },
{ 6875, 5750, },
{ 7000, 5875, },
{ 7125, 6000, },
{ 7250, 6125, },
{ 7375, 6250, },
{ 7500, 6375, },
{ 7625, 6500, },
{ 7750, 6625, },
{ 7875, 6750, },
{ 8000, 6875, },
{ 8125, 7000, },
{ 8250, 7125, },
{ 8375, 7250, },
{ 8500, 7375, },
{ 8625, 7500, },
{ 8750, 7625, },
{ 8875, 7750, },
{ 9000, 7875, },
{ 9125, 8000, },
{ 9250, 8125, },
{ 9375, 8250, },
{ 9500, 8375, },
{ 9625, 8500, },
{ 9750, 8625, },
{ 9875, 8750, },
{ 10000, 8875, },
{ 10125, 9000, },
{ 10250, 9125, },
{ 10375, 9250, },
{ 10500, 9375, },
{ 10625, 9500, },
{ 10750, 9625, },
{ 10875, 9750, },
{ 11000, 9875, },
{ 11125, 10000, },
{ 11250, 10125, },
{ 11375, 10250, },
{ 11500, 10375, },
{ 11625, 10500, },
{ 11750, 10625, },
{ 11875, 10750, },
{ 12000, 10875, },
{ 12125, 11000, },
{ 12250, 11125, },
{ 12375, 11250, },
{ 12500, 11375, },
{ 12625, 11500, },
{ 12750, 11625, },
{ 12875, 11750, },
{ 13000, 11875, },
{ 13125, 12000, },
{ 13250, 12125, },
{ 13375, 12250, },
{ 13500, 12375, },
{ 13625, 12500, },
{ 13750, 12625, },
{ 13875, 12750, },
{ 14000, 12875, },
{ 14125, 13000, },
{ 14250, 13125, },
{ 14375, 13250, },
{ 14500, 13375, },
{ 14625, 13500, },
{ 14750, 13625, },
{ 14875, 13750, },
{ 15000, 13875, },
{ 15125, 14000, },
{ 15250, 14125, },
{ 15375, 14250, },
{ 15500, 14375, },
{ 15625, 14500, },
{ 15750, 14625, },
{ 15875, 14750, },
{ 16000, 14875, },
{ 16125, 15000, },
};
if (dev_priv->info->is_mobile)
return v_table[pxvid].vm;
else
return v_table[pxvid].vd;
}
static void __i915_update_gfx_val(struct drm_i915_private *dev_priv)
{
struct timespec now, diff1;
u64 diff;
unsigned long diffms;
u32 count;
assert_spin_locked(&mchdev_lock);
getrawmonotonic(&now);
diff1 = timespec_sub(now, dev_priv->ips.last_time2);
diffms = diff1.tv_sec * 1000 + diff1.tv_nsec / 1000000;
if (!diffms)
return;
count = I915_READ(GFXEC);
if (count < dev_priv->ips.last_count2) {
diff = ~0UL - dev_priv->ips.last_count2;
diff += count;
} else {
diff = count - dev_priv->ips.last_count2;
}
dev_priv->ips.last_count2 = count;
dev_priv->ips.last_time2 = now;
diff = diff * 1181;
diff = div_u64(diff, diffms * 10);
dev_priv->ips.gfx_power = diff;
}
void i915_update_gfx_val(struct drm_i915_private *dev_priv)
{
if (dev_priv->info->gen != 5)
return;
spin_lock_irq(&mchdev_lock);
__i915_update_gfx_val(dev_priv);
spin_unlock_irq(&mchdev_lock);
}
static unsigned long __i915_gfx_val(struct drm_i915_private *dev_priv)
{
unsigned long t, corr, state1, corr2, state2;
u32 pxvid, ext_v;
assert_spin_locked(&mchdev_lock);
pxvid = I915_READ(PXVFREQ_BASE + (dev_priv->rps.cur_delay * 4));
pxvid = (pxvid >> 24) & 0x7f;
ext_v = pvid_to_extvid(dev_priv, pxvid);
state1 = ext_v;
t = i915_mch_val(dev_priv);
if (t > 80)
corr = ((t * 2349) + 135940);
else if (t >= 50)
corr = ((t * 964) + 29317);
else
corr = ((t * 301) + 1004);
corr = corr * ((150142 * state1) / 10000 - 78642);
corr /= 100000;
corr2 = (corr * dev_priv->ips.corr);
state2 = (corr2 * state1) / 10000;
state2 /= 100;
__i915_update_gfx_val(dev_priv);
return dev_priv->ips.gfx_power + state2;
}
unsigned long i915_gfx_val(struct drm_i915_private *dev_priv)
{
unsigned long val;
if (dev_priv->info->gen != 5)
return 0;
spin_lock_irq(&mchdev_lock);
val = __i915_gfx_val(dev_priv);
spin_unlock_irq(&mchdev_lock);
return val;
}
unsigned long i915_read_mch_val(void)
{
struct drm_i915_private *dev_priv;
unsigned long chipset_val, graphics_val, ret = 0;
spin_lock_irq(&mchdev_lock);
if (!i915_mch_dev)
goto out_unlock;
dev_priv = i915_mch_dev;
chipset_val = __i915_chipset_val(dev_priv);
graphics_val = __i915_gfx_val(dev_priv);
ret = chipset_val + graphics_val;
out_unlock:
spin_unlock_irq(&mchdev_lock);
return ret;
}
bool i915_gpu_raise(void)
{
struct drm_i915_private *dev_priv;
bool ret = true;
spin_lock_irq(&mchdev_lock);
if (!i915_mch_dev) {
ret = false;
goto out_unlock;
}
dev_priv = i915_mch_dev;
if (dev_priv->ips.max_delay > dev_priv->ips.fmax)
dev_priv->ips.max_delay--;
out_unlock:
spin_unlock_irq(&mchdev_lock);
return ret;
}
bool i915_gpu_lower(void)
{
struct drm_i915_private *dev_priv;
bool ret = true;
spin_lock_irq(&mchdev_lock);
if (!i915_mch_dev) {
ret = false;
goto out_unlock;
}
dev_priv = i915_mch_dev;
if (dev_priv->ips.max_delay < dev_priv->ips.min_delay)
dev_priv->ips.max_delay++;
out_unlock:
spin_unlock_irq(&mchdev_lock);
return ret;
}
bool i915_gpu_busy(void)
{
struct drm_i915_private *dev_priv;
struct intel_ring_buffer *ring;
bool ret = false;
int i;
spin_lock_irq(&mchdev_lock);
if (!i915_mch_dev)
goto out_unlock;
dev_priv = i915_mch_dev;
for_each_ring(ring, dev_priv, i)
ret |= !list_empty(&ring->request_list);
out_unlock:
spin_unlock_irq(&mchdev_lock);
return ret;
}
bool i915_gpu_turbo_disable(void)
{
struct drm_i915_private *dev_priv;
bool ret = true;
spin_lock_irq(&mchdev_lock);
if (!i915_mch_dev) {
ret = false;
goto out_unlock;
}
dev_priv = i915_mch_dev;
dev_priv->ips.max_delay = dev_priv->ips.fstart;
if (!ironlake_set_drps(dev_priv->dev, dev_priv->ips.fstart))
ret = false;
out_unlock:
spin_unlock_irq(&mchdev_lock);
return ret;
}
static void
ips_ping_for_i915_load(void)
{
void (*link)(void);
link = symbol_get(ips_link_to_i915_driver);
if (link) {
link();
symbol_put(ips_link_to_i915_driver);
}
}
void intel_gpu_ips_init(struct drm_i915_private *dev_priv)
{
spin_lock_irq(&mchdev_lock);
i915_mch_dev = dev_priv;
spin_unlock_irq(&mchdev_lock);
ips_ping_for_i915_load();
}
void intel_gpu_ips_teardown(void)
{
spin_lock_irq(&mchdev_lock);
i915_mch_dev = NULL;
spin_unlock_irq(&mchdev_lock);
}
static void intel_init_emon(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 lcfuse;
u8 pxw[16];
int i;
I915_WRITE(ECR, 0);
POSTING_READ(ECR);
I915_WRITE(SDEW, 0x15040d00);
I915_WRITE(CSIEW0, 0x007f0000);
I915_WRITE(CSIEW1, 0x1e220004);
I915_WRITE(CSIEW2, 0x04000004);
for (i = 0; i < 5; i++)
I915_WRITE(PEW + (i * 4), 0);
for (i = 0; i < 3; i++)
I915_WRITE(DEW + (i * 4), 0);
for (i = 0; i < 16; i++) {
u32 pxvidfreq = I915_READ(PXVFREQ_BASE + (i * 4));
unsigned long freq = intel_pxfreq(pxvidfreq);
unsigned long vid = (pxvidfreq & PXVFREQ_PX_MASK) >>
PXVFREQ_PX_SHIFT;
unsigned long val;
val = vid * vid;
val *= (freq / 1000);
val *= 255;
val /= (127*127*900);
if (val > 0xff)
DRM_ERROR("bad pxval: %ld\n", val);
pxw[i] = val;
}
pxw[14] = 0;
pxw[15] = 0;
for (i = 0; i < 4; i++) {
u32 val = (pxw[i*4] << 24) | (pxw[(i*4)+1] << 16) |
(pxw[(i*4)+2] << 8) | (pxw[(i*4)+3]);
I915_WRITE(PXW + (i * 4), val);
}
I915_WRITE(OGW0, 0);
I915_WRITE(OGW1, 0);
I915_WRITE(EG0, 0x00007f00);
I915_WRITE(EG1, 0x0000000e);
I915_WRITE(EG2, 0x000e0000);
I915_WRITE(EG3, 0x68000300);
I915_WRITE(EG4, 0x42000000);
I915_WRITE(EG5, 0x00140031);
I915_WRITE(EG6, 0);
I915_WRITE(EG7, 0);
for (i = 0; i < 8; i++)
I915_WRITE(PXWL + (i * 4), 0);
I915_WRITE(ECR, 0x80000019);
lcfuse = I915_READ(LCFUSE02);
dev_priv->ips.corr = (lcfuse & LCFUSE_HIV_MASK);
}
void intel_disable_gt_powersave(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_IRONLAKE_M(dev)) {
ironlake_disable_drps(dev);
ironlake_disable_rc6(dev);
} else if (INTEL_INFO(dev)->gen >= 6 && !IS_VALLEYVIEW(dev)) {
cancel_delayed_work_sync(&dev_priv->rps.delayed_resume_work);
mutex_lock(&dev_priv->rps.hw_lock);
gen6_disable_rps(dev);
mutex_unlock(&dev_priv->rps.hw_lock);
}
}
static void intel_gen6_powersave_work(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, struct drm_i915_private,
rps.delayed_resume_work.work);
struct drm_device *dev = dev_priv->dev;
mutex_lock(&dev_priv->rps.hw_lock);
gen6_enable_rps(dev);
gen6_update_ring_freq(dev);
mutex_unlock(&dev_priv->rps.hw_lock);
}
void intel_enable_gt_powersave(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_IRONLAKE_M(dev)) {
ironlake_enable_drps(dev);
ironlake_enable_rc6(dev);
intel_init_emon(dev);
} else if ((IS_GEN6(dev) || IS_GEN7(dev)) && !IS_VALLEYVIEW(dev)) {
schedule_delayed_work(&dev_priv->rps.delayed_resume_work,
round_jiffies_up_relative(HZ));
}
}
static void ibx_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(SOUTH_DSPCLK_GATE_D, PCH_DPLSUNIT_CLOCK_GATE_DISABLE);
}
static void ironlake_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dspclk_gate = ILK_VRHUNIT_CLOCK_GATE_DISABLE;
dspclk_gate |= ILK_DPFCRUNIT_CLOCK_GATE_DISABLE |
ILK_DPFCUNIT_CLOCK_GATE_DISABLE |
ILK_DPFDUNIT_CLOCK_GATE_ENABLE;
I915_WRITE(PCH_3DCGDIS0,
MARIUNIT_CLOCK_GATE_DISABLE |
SVSMUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(PCH_3DCGDIS1,
VFMUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
(I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_DPARB_GATE | ILK_VSDPFD_FULL));
dspclk_gate |= ILK_DPARBUNIT_CLOCK_GATE_ENABLE;
I915_WRITE(DISP_ARB_CTL,
(I915_READ(DISP_ARB_CTL) |
DISP_FBC_WM_DIS));
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
if (IS_IRONLAKE_M(dev)) {
I915_WRITE(ILK_DISPLAY_CHICKEN1,
I915_READ(ILK_DISPLAY_CHICKEN1) |
ILK_FBCQ_DIS);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_DPARB_GATE);
}
I915_WRITE(ILK_DSPCLK_GATE_D, dspclk_gate);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_ELPIN_409_SELECT);
I915_WRITE(_3D_CHICKEN2,
_3D_CHICKEN2_WM_READ_PIPELINED << 16 |
_3D_CHICKEN2_WM_READ_PIPELINED);
I915_WRITE(CACHE_MODE_0,
_MASKED_BIT_ENABLE(CM0_PIPELINED_RENDER_FLUSH_DISABLE));
ibx_init_clock_gating(dev);
}
static void cpt_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
uint32_t val;
I915_WRITE(SOUTH_DSPCLK_GATE_D, PCH_DPLSUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(SOUTH_CHICKEN2, I915_READ(SOUTH_CHICKEN2) |
DPLS_EDP_PPS_FIX_DIS);
for_each_pipe(pipe) {
val = I915_READ(TRANS_CHICKEN2(pipe));
val |= TRANS_CHICKEN2_TIMING_OVERRIDE;
val &= ~TRANS_CHICKEN2_FDI_POLARITY_REVERSED;
if (dev_priv->fdi_rx_polarity_inverted)
val |= TRANS_CHICKEN2_FDI_POLARITY_REVERSED;
val &= ~TRANS_CHICKEN2_FRAME_START_DELAY_MASK;
val &= ~TRANS_CHICKEN2_DISABLE_DEEP_COLOR_COUNTER;
val &= ~TRANS_CHICKEN2_DISABLE_DEEP_COLOR_MODESWITCH;
I915_WRITE(TRANS_CHICKEN2(pipe), val);
}
for_each_pipe(pipe) {
I915_WRITE(TRANS_CHICKEN1(pipe),
TRANS_CHICKEN1_DP0UNIT_GC_DISABLE);
}
}
static void gen6_check_mch_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t tmp;
tmp = I915_READ(MCH_SSKPD);
if ((tmp & MCH_SSKPD_WM0_MASK) != MCH_SSKPD_WM0_VAL) {
DRM_INFO("Wrong MCH_SSKPD value: 0x%08x\n", tmp);
DRM_INFO("This can cause pipe underruns and display issues.\n");
DRM_INFO("Please upgrade your BIOS to fix this.\n");
}
}
static void gen6_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
uint32_t dspclk_gate = ILK_VRHUNIT_CLOCK_GATE_DISABLE;
I915_WRITE(ILK_DSPCLK_GATE_D, dspclk_gate);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_ELPIN_409_SELECT);
I915_WRITE(_3D_CHICKEN,
_MASKED_BIT_ENABLE(_3D_CHICKEN_HIZ_PLANE_DISABLE_MSAA_4X_SNB));
if (IS_SNB_GT1(dev))
I915_WRITE(GEN6_GT_MODE,
_MASKED_BIT_ENABLE(GEN6_TD_FOUR_ROW_DISPATCH_DISABLE));
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
I915_WRITE(CACHE_MODE_0,
_MASKED_BIT_DISABLE(CM0_STC_EVICT_DISABLE_LRA_SNB));
I915_WRITE(GEN6_UCGCTL1,
I915_READ(GEN6_UCGCTL1) |
GEN6_BLBUNIT_CLOCK_GATE_DISABLE |
GEN6_CSUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(GEN6_UCGCTL2,
GEN7_VDSUNIT_CLOCK_GATE_DISABLE |
GEN6_RCPBUNIT_CLOCK_GATE_DISABLE |
GEN6_RCCUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(_3D_CHICKEN3, (0xFFFF << 16) |
_3D_CHICKEN3_SF_DISABLE_FASTCLIP_CULL);
I915_WRITE(ILK_DISPLAY_CHICKEN1,
I915_READ(ILK_DISPLAY_CHICKEN1) |
ILK_FBCQ_DIS | ILK_PABSTRETCH_DIS);
I915_WRITE(ILK_DISPLAY_CHICKEN2,
I915_READ(ILK_DISPLAY_CHICKEN2) |
ILK_DPARB_GATE | ILK_VSDPFD_FULL);
I915_WRITE(ILK_DSPCLK_GATE_D,
I915_READ(ILK_DSPCLK_GATE_D) |
ILK_DPARBUNIT_CLOCK_GATE_ENABLE |
ILK_DPFDUNIT_CLOCK_GATE_ENABLE);
I915_WRITE(GEN6_MBCTL, I915_READ(GEN6_MBCTL) |
GEN6_MBCTL_ENABLE_BOOT_FETCH);
for_each_pipe(pipe) {
I915_WRITE(DSPCNTR(pipe),
I915_READ(DSPCNTR(pipe)) |
DISPPLANE_TRICKLE_FEED_DISABLE);
intel_flush_display_plane(dev_priv, pipe);
}
I915_WRITE(GEN6_GT_MODE, _MASKED_BIT_DISABLE(0xffff));
I915_WRITE(GEN6_GT_MODE, _MASKED_BIT_ENABLE(GEN6_GT_MODE_HI));
cpt_init_clock_gating(dev);
gen6_check_mch_setup(dev);
}
static void gen7_setup_fixed_func_scheduler(struct drm_i915_private *dev_priv)
{
uint32_t reg = I915_READ(GEN7_FF_THREAD_MODE);
reg &= ~GEN7_FF_SCHED_MASK;
reg |= GEN7_FF_TS_SCHED_HW;
reg |= GEN7_FF_VS_SCHED_HW;
reg |= GEN7_FF_DS_SCHED_HW;
if (IS_HASWELL(dev_priv->dev))
reg &= ~GEN7_FF_VS_REF_CNT_FFME;
I915_WRITE(GEN7_FF_THREAD_MODE, reg);
}
static void lpt_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->pch_id == INTEL_PCH_LPT_LP_DEVICE_ID_TYPE)
I915_WRITE(SOUTH_DSPCLK_GATE_D,
I915_READ(SOUTH_DSPCLK_GATE_D) |
PCH_LP_PARTITION_LEVEL_DISABLE);
}
static void haswell_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
I915_WRITE(GEN6_UCGCTL2, GEN6_RCZUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(GEN7_COMMON_SLICE_CHICKEN1,
GEN7_CSC1_RHWO_OPT_DISABLE_IN_RCC);
I915_WRITE(GEN7_L3CNTLREG1,
GEN7_WA_FOR_GEN7_L3_CONTROL);
I915_WRITE(GEN7_L3_CHICKEN_MODE_REGISTER,
GEN7_WA_L3_CHICKEN_MODE);
I915_WRITE(GEN7_SQ_CHICKEN_MBCUNIT_CONFIG,
I915_READ(GEN7_SQ_CHICKEN_MBCUNIT_CONFIG) |
GEN7_SQ_CHICKEN_MBCUNIT_SQINTMOB);
for_each_pipe(pipe) {
I915_WRITE(DSPCNTR(pipe),
I915_READ(DSPCNTR(pipe)) |
DISPPLANE_TRICKLE_FEED_DISABLE);
intel_flush_display_plane(dev_priv, pipe);
}
gen7_setup_fixed_func_scheduler(dev_priv);
I915_WRITE(CACHE_MODE_1,
_MASKED_BIT_ENABLE(PIXEL_SUBSPAN_COLLECT_OPT_DISABLE));
I915_WRITE(GEN6_MBCTL, I915_READ(GEN6_MBCTL) |
GEN6_MBCTL_ENABLE_BOOT_FETCH);
I915_WRITE(GAM_ECOCHK, I915_READ(GAM_ECOCHK) | HSW_ECOCHK_ARB_PRIO_SOL);
I915_WRITE(WM_DBG,
I915_READ(WM_DBG) |
WM_DBG_DISALLOW_MULTIPLE_LP |
WM_DBG_DISALLOW_SPRITE |
WM_DBG_DISALLOW_MAXFIFO);
lpt_init_clock_gating(dev);
}
static void ivybridge_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
uint32_t snpcr;
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
I915_WRITE(ILK_DSPCLK_GATE_D, ILK_VRHUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(_3D_CHICKEN3,
_MASKED_BIT_ENABLE(_3D_CHICKEN_SF_DISABLE_OBJEND_CULL));
I915_WRITE(IVB_CHICKEN3,
CHICKEN3_DGMG_REQ_OUT_FIX_DISABLE |
CHICKEN3_DGMG_DONE_FIX_DISABLE);
if (IS_IVB_GT1(dev))
I915_WRITE(GEN7_HALF_SLICE_CHICKEN1,
_MASKED_BIT_ENABLE(GEN7_PSD_SINGLE_PORT_DISPATCH_ENABLE));
else
I915_WRITE(GEN7_HALF_SLICE_CHICKEN1_GT2,
_MASKED_BIT_ENABLE(GEN7_PSD_SINGLE_PORT_DISPATCH_ENABLE));
I915_WRITE(GEN7_COMMON_SLICE_CHICKEN1,
GEN7_CSC1_RHWO_OPT_DISABLE_IN_RCC);
I915_WRITE(GEN7_L3CNTLREG1,
GEN7_WA_FOR_GEN7_L3_CONTROL);
I915_WRITE(GEN7_L3_CHICKEN_MODE_REGISTER,
GEN7_WA_L3_CHICKEN_MODE);
if (IS_IVB_GT1(dev))
I915_WRITE(GEN7_ROW_CHICKEN2,
_MASKED_BIT_ENABLE(DOP_CLOCK_GATING_DISABLE));
else
I915_WRITE(GEN7_ROW_CHICKEN2_GT2,
_MASKED_BIT_ENABLE(DOP_CLOCK_GATING_DISABLE));
I915_WRITE(GEN7_L3SQCREG4, I915_READ(GEN7_L3SQCREG4) &
~L3SQ_URB_READ_CAM_MATCH_DISABLE);
I915_WRITE(GEN6_UCGCTL2,
GEN6_RCZUNIT_CLOCK_GATE_DISABLE |
GEN6_RCCUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(GEN7_SQ_CHICKEN_MBCUNIT_CONFIG,
I915_READ(GEN7_SQ_CHICKEN_MBCUNIT_CONFIG) |
GEN7_SQ_CHICKEN_MBCUNIT_SQINTMOB);
for_each_pipe(pipe) {
I915_WRITE(DSPCNTR(pipe),
I915_READ(DSPCNTR(pipe)) |
DISPPLANE_TRICKLE_FEED_DISABLE);
intel_flush_display_plane(dev_priv, pipe);
}
I915_WRITE(GEN6_MBCTL, I915_READ(GEN6_MBCTL) |
GEN6_MBCTL_ENABLE_BOOT_FETCH);
gen7_setup_fixed_func_scheduler(dev_priv);
I915_WRITE(CACHE_MODE_1,
_MASKED_BIT_ENABLE(PIXEL_SUBSPAN_COLLECT_OPT_DISABLE));
snpcr = I915_READ(GEN6_MBCUNIT_SNPCR);
snpcr &= ~GEN6_MBC_SNPCR_MASK;
snpcr |= GEN6_MBC_SNPCR_MED;
I915_WRITE(GEN6_MBCUNIT_SNPCR, snpcr);
if (!HAS_PCH_NOP(dev))
cpt_init_clock_gating(dev);
gen6_check_mch_setup(dev);
}
static void valleyview_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int pipe;
I915_WRITE(WM3_LP_ILK, 0);
I915_WRITE(WM2_LP_ILK, 0);
I915_WRITE(WM1_LP_ILK, 0);
I915_WRITE(ILK_DSPCLK_GATE_D, ILK_VRHUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(_3D_CHICKEN3,
_MASKED_BIT_ENABLE(_3D_CHICKEN_SF_DISABLE_OBJEND_CULL));
I915_WRITE(IVB_CHICKEN3,
CHICKEN3_DGMG_REQ_OUT_FIX_DISABLE |
CHICKEN3_DGMG_DONE_FIX_DISABLE);
I915_WRITE(GEN7_HALF_SLICE_CHICKEN1,
_MASKED_BIT_ENABLE(GEN7_MAX_PS_THREAD_DEP |
GEN7_PSD_SINGLE_PORT_DISPATCH_ENABLE));
I915_WRITE(GEN7_COMMON_SLICE_CHICKEN1,
GEN7_CSC1_RHWO_OPT_DISABLE_IN_RCC);
I915_WRITE(GEN7_L3CNTLREG1, I915_READ(GEN7_L3CNTLREG1) | GEN7_L3AGDIS);
I915_WRITE(GEN7_L3_CHICKEN_MODE_REGISTER, GEN7_WA_L3_CHICKEN_MODE);
I915_WRITE(GEN7_L3SQCREG4, I915_READ(GEN7_L3SQCREG4) &
~L3SQ_URB_READ_CAM_MATCH_DISABLE);
I915_WRITE(GEN7_ROW_CHICKEN2,
_MASKED_BIT_ENABLE(DOP_CLOCK_GATING_DISABLE));
I915_WRITE(GEN7_L3SQCREG4, I915_READ(GEN7_L3SQCREG4) &
~L3SQ_URB_READ_CAM_MATCH_DISABLE);
I915_WRITE(GEN7_SQ_CHICKEN_MBCUNIT_CONFIG,
I915_READ(GEN7_SQ_CHICKEN_MBCUNIT_CONFIG) |
GEN7_SQ_CHICKEN_MBCUNIT_SQINTMOB);
I915_WRITE(GEN6_MBCTL, I915_READ(GEN6_MBCTL) |
GEN6_MBCTL_ENABLE_BOOT_FETCH);
I915_WRITE(GEN6_UCGCTL2,
GEN7_VDSUNIT_CLOCK_GATE_DISABLE |
GEN7_TDLUNIT_CLOCK_GATE_DISABLE |
GEN6_RCZUNIT_CLOCK_GATE_DISABLE |
GEN6_RCPBUNIT_CLOCK_GATE_DISABLE |
GEN6_RCCUNIT_CLOCK_GATE_DISABLE);
I915_WRITE(GEN7_UCGCTL4, GEN7_L3BANK2X_CLOCK_GATE_DISABLE);
for_each_pipe(pipe) {
I915_WRITE(DSPCNTR(pipe),
I915_READ(DSPCNTR(pipe)) |
DISPPLANE_TRICKLE_FEED_DISABLE);
intel_flush_display_plane(dev_priv, pipe);
}
I915_WRITE(CACHE_MODE_1,
_MASKED_BIT_ENABLE(PIXEL_SUBSPAN_COLLECT_OPT_DISABLE));
I915_WRITE(VLV_GUNIT_CLOCK_GATE, 0xffffffff);
I915_WRITE(0x9400, 0xffffffff);
I915_WRITE(0x9404, 0xffffffff);
I915_WRITE(0x9408, 0xffffffff);
I915_WRITE(0x940c, 0xffffffff);
I915_WRITE(0x9410, 0xffffffff);
I915_WRITE(0x9414, 0xffffffff);
I915_WRITE(0x9418, 0xffffffff);
}
static void g4x_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t dspclk_gate;
I915_WRITE(RENCLK_GATE_D1, 0);
I915_WRITE(RENCLK_GATE_D2, VF_UNIT_CLOCK_GATE_DISABLE |
GS_UNIT_CLOCK_GATE_DISABLE |
CL_UNIT_CLOCK_GATE_DISABLE);
I915_WRITE(RAMCLK_GATE_D, 0);
dspclk_gate = VRHUNIT_CLOCK_GATE_DISABLE |
OVRUNIT_CLOCK_GATE_DISABLE |
OVCUNIT_CLOCK_GATE_DISABLE;
if (IS_GM45(dev))
dspclk_gate |= DSSUNIT_CLOCK_GATE_DISABLE;
I915_WRITE(DSPCLK_GATE_D, dspclk_gate);
I915_WRITE(CACHE_MODE_0,
_MASKED_BIT_ENABLE(CM0_PIPELINED_RENDER_FLUSH_DISABLE));
}
static void crestline_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(RENCLK_GATE_D1, I965_RCC_CLOCK_GATE_DISABLE);
I915_WRITE(RENCLK_GATE_D2, 0);
I915_WRITE(DSPCLK_GATE_D, 0);
I915_WRITE(RAMCLK_GATE_D, 0);
I915_WRITE16(DEUC, 0);
}
static void broadwater_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(RENCLK_GATE_D1, I965_RCZ_CLOCK_GATE_DISABLE |
I965_RCC_CLOCK_GATE_DISABLE |
I965_RCPB_CLOCK_GATE_DISABLE |
I965_ISC_CLOCK_GATE_DISABLE |
I965_FBC_CLOCK_GATE_DISABLE);
I915_WRITE(RENCLK_GATE_D2, 0);
}
static void gen3_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dstate = I915_READ(D_STATE);
dstate |= DSTATE_PLL_D3_OFF | DSTATE_GFX_CLOCK_GATING |
DSTATE_DOT_CLOCK_GATING;
I915_WRITE(D_STATE, dstate);
if (IS_PINEVIEW(dev))
I915_WRITE(ECOSKPD, _MASKED_BIT_ENABLE(ECO_GATING_CX_ONLY));
I915_WRITE(ECOSKPD, _MASKED_BIT_DISABLE(ECO_FLIP_DONE));
}
static void i85x_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(RENCLK_GATE_D1, SV_CLOCK_GATE_DISABLE);
}
static void i830_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE(DSPCLK_GATE_D, OVRUNIT_CLOCK_GATE_DISABLE);
}
void intel_init_clock_gating(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->display.init_clock_gating(dev);
}
bool intel_using_power_well(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_HASWELL(dev))
return I915_READ(HSW_PWR_WELL_DRIVER) ==
(HSW_PWR_WELL_ENABLE | HSW_PWR_WELL_STATE);
else
return true;
}
void intel_set_power_well(struct drm_device *dev, bool enable)
{
struct drm_i915_private *dev_priv = dev->dev_private;
bool is_enabled, enable_requested;
uint32_t tmp;
if (!HAS_POWER_WELL(dev))
return;
if (!i915_disable_power_well && !enable)
return;
tmp = I915_READ(HSW_PWR_WELL_DRIVER);
is_enabled = tmp & HSW_PWR_WELL_STATE;
enable_requested = tmp & HSW_PWR_WELL_ENABLE;
if (enable) {
if (!enable_requested)
I915_WRITE(HSW_PWR_WELL_DRIVER, HSW_PWR_WELL_ENABLE);
if (!is_enabled) {
DRM_DEBUG_KMS("Enabling power well\n");
if (wait_for((I915_READ(HSW_PWR_WELL_DRIVER) &
HSW_PWR_WELL_STATE), 20))
DRM_ERROR("Timeout enabling power well\n");
}
} else {
if (enable_requested) {
I915_WRITE(HSW_PWR_WELL_DRIVER, 0);
DRM_DEBUG_KMS("Requesting to disable the power well\n");
}
}
}
void intel_init_power_well(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!HAS_POWER_WELL(dev))
return;
intel_set_power_well(dev, true);
if (I915_READ(HSW_PWR_WELL_BIOS) & HSW_PWR_WELL_ENABLE)
I915_WRITE(HSW_PWR_WELL_BIOS, 0);
}
void intel_init_pm(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (I915_HAS_FBC(dev)) {
if (HAS_PCH_SPLIT(dev)) {
dev_priv->display.fbc_enabled = ironlake_fbc_enabled;
dev_priv->display.enable_fbc = ironlake_enable_fbc;
dev_priv->display.disable_fbc = ironlake_disable_fbc;
} else if (IS_GM45(dev)) {
dev_priv->display.fbc_enabled = g4x_fbc_enabled;
dev_priv->display.enable_fbc = g4x_enable_fbc;
dev_priv->display.disable_fbc = g4x_disable_fbc;
} else if (IS_CRESTLINE(dev)) {
dev_priv->display.fbc_enabled = i8xx_fbc_enabled;
dev_priv->display.enable_fbc = i8xx_enable_fbc;
dev_priv->display.disable_fbc = i8xx_disable_fbc;
}
}
if (IS_PINEVIEW(dev))
i915_pineview_get_mem_freq(dev);
else if (IS_GEN5(dev))
i915_ironlake_get_mem_freq(dev);
if (HAS_PCH_SPLIT(dev)) {
if (IS_GEN5(dev)) {
if (I915_READ(MLTR_ILK) & ILK_SRLT_MASK)
dev_priv->display.update_wm = ironlake_update_wm;
else {
DRM_DEBUG_KMS("Failed to get proper latency. "
"Disable CxSR\n");
dev_priv->display.update_wm = NULL;
}
dev_priv->display.init_clock_gating = ironlake_init_clock_gating;
} else if (IS_GEN6(dev)) {
if (SNB_READ_WM0_LATENCY()) {
dev_priv->display.update_wm = sandybridge_update_wm;
dev_priv->display.update_sprite_wm = sandybridge_update_sprite_wm;
} else {
DRM_DEBUG_KMS("Failed to read display plane latency. "
"Disable CxSR\n");
dev_priv->display.update_wm = NULL;
}
dev_priv->display.init_clock_gating = gen6_init_clock_gating;
} else if (IS_IVYBRIDGE(dev)) {
if (SNB_READ_WM0_LATENCY()) {
dev_priv->display.update_wm = ivybridge_update_wm;
dev_priv->display.update_sprite_wm = sandybridge_update_sprite_wm;
} else {
DRM_DEBUG_KMS("Failed to read display plane latency. "
"Disable CxSR\n");
dev_priv->display.update_wm = NULL;
}
dev_priv->display.init_clock_gating = ivybridge_init_clock_gating;
} else if (IS_HASWELL(dev)) {
if (SNB_READ_WM0_LATENCY()) {
dev_priv->display.update_wm = sandybridge_update_wm;
dev_priv->display.update_sprite_wm = sandybridge_update_sprite_wm;
dev_priv->display.update_linetime_wm = haswell_update_linetime_wm;
} else {
DRM_DEBUG_KMS("Failed to read display plane latency. "
"Disable CxSR\n");
dev_priv->display.update_wm = NULL;
}
dev_priv->display.init_clock_gating = haswell_init_clock_gating;
} else
dev_priv->display.update_wm = NULL;
} else if (IS_VALLEYVIEW(dev)) {
dev_priv->display.update_wm = valleyview_update_wm;
dev_priv->display.init_clock_gating =
valleyview_init_clock_gating;
} else if (IS_PINEVIEW(dev)) {
if (!intel_get_cxsr_latency(IS_PINEVIEW_G(dev),
dev_priv->is_ddr3,
dev_priv->fsb_freq,
dev_priv->mem_freq)) {
DRM_INFO("failed to find known CxSR latency "
"(found ddr%s fsb freq %d, mem freq %d), "
"disabling CxSR\n",
(dev_priv->is_ddr3 == 1) ? "3" : "2",
dev_priv->fsb_freq, dev_priv->mem_freq);
pineview_disable_cxsr(dev);
dev_priv->display.update_wm = NULL;
} else
dev_priv->display.update_wm = pineview_update_wm;
dev_priv->display.init_clock_gating = gen3_init_clock_gating;
} else if (IS_G4X(dev)) {
dev_priv->display.update_wm = g4x_update_wm;
dev_priv->display.init_clock_gating = g4x_init_clock_gating;
} else if (IS_GEN4(dev)) {
dev_priv->display.update_wm = i965_update_wm;
if (IS_CRESTLINE(dev))
dev_priv->display.init_clock_gating = crestline_init_clock_gating;
else if (IS_BROADWATER(dev))
dev_priv->display.init_clock_gating = broadwater_init_clock_gating;
} else if (IS_GEN3(dev)) {
dev_priv->display.update_wm = i9xx_update_wm;
dev_priv->display.get_fifo_size = i9xx_get_fifo_size;
dev_priv->display.init_clock_gating = gen3_init_clock_gating;
} else if (IS_I865G(dev)) {
dev_priv->display.update_wm = i830_update_wm;
dev_priv->display.init_clock_gating = i85x_init_clock_gating;
dev_priv->display.get_fifo_size = i830_get_fifo_size;
} else if (IS_I85X(dev)) {
dev_priv->display.update_wm = i9xx_update_wm;
dev_priv->display.get_fifo_size = i85x_get_fifo_size;
dev_priv->display.init_clock_gating = i85x_init_clock_gating;
} else {
dev_priv->display.update_wm = i830_update_wm;
dev_priv->display.init_clock_gating = i830_init_clock_gating;
if (IS_845G(dev))
dev_priv->display.get_fifo_size = i845_get_fifo_size;
else
dev_priv->display.get_fifo_size = i830_get_fifo_size;
}
}
static void __gen6_gt_wait_for_thread_c0(struct drm_i915_private *dev_priv)
{
u32 gt_thread_status_mask;
if (IS_HASWELL(dev_priv->dev))
gt_thread_status_mask = GEN6_GT_THREAD_STATUS_CORE_MASK_HSW;
else
gt_thread_status_mask = GEN6_GT_THREAD_STATUS_CORE_MASK;
if (wait_for_atomic_us((I915_READ_NOTRACE(GEN6_GT_THREAD_STATUS_REG) & gt_thread_status_mask) == 0, 500))
DRM_ERROR("GT thread status wait timed out\n");
}
static void __gen6_gt_force_wake_reset(struct drm_i915_private *dev_priv)
{
I915_WRITE_NOTRACE(FORCEWAKE, 0);
POSTING_READ(ECOBUS);
}
static void __gen6_gt_force_wake_get(struct drm_i915_private *dev_priv)
{
if (wait_for_atomic((I915_READ_NOTRACE(FORCEWAKE_ACK) & 1) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake old ack to clear.\n");
I915_WRITE_NOTRACE(FORCEWAKE, 1);
POSTING_READ(ECOBUS);
if (wait_for_atomic((I915_READ_NOTRACE(FORCEWAKE_ACK) & 1),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake to ack request.\n");
__gen6_gt_wait_for_thread_c0(dev_priv);
}
static void __gen6_gt_force_wake_mt_reset(struct drm_i915_private *dev_priv)
{
I915_WRITE_NOTRACE(FORCEWAKE_MT, _MASKED_BIT_DISABLE(0xffff));
POSTING_READ(ECOBUS);
}
static void __gen6_gt_force_wake_mt_get(struct drm_i915_private *dev_priv)
{
u32 forcewake_ack;
if (IS_HASWELL(dev_priv->dev))
forcewake_ack = FORCEWAKE_ACK_HSW;
else
forcewake_ack = FORCEWAKE_MT_ACK;
if (wait_for_atomic((I915_READ_NOTRACE(forcewake_ack) & FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake old ack to clear.\n");
I915_WRITE_NOTRACE(FORCEWAKE_MT, _MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
POSTING_READ(ECOBUS);
if (wait_for_atomic((I915_READ_NOTRACE(forcewake_ack) & FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake to ack request.\n");
__gen6_gt_wait_for_thread_c0(dev_priv);
}
void gen6_gt_force_wake_get(struct drm_i915_private *dev_priv)
{
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->gt_lock, irqflags);
if (dev_priv->forcewake_count++ == 0)
dev_priv->gt.force_wake_get(dev_priv);
spin_unlock_irqrestore(&dev_priv->gt_lock, irqflags);
}
void gen6_gt_check_fifodbg(struct drm_i915_private *dev_priv)
{
u32 gtfifodbg;
gtfifodbg = I915_READ_NOTRACE(GTFIFODBG);
if (WARN(gtfifodbg & GT_FIFO_CPU_ERROR_MASK,
"MMIO read or write has been dropped %x\n", gtfifodbg))
I915_WRITE_NOTRACE(GTFIFODBG, GT_FIFO_CPU_ERROR_MASK);
}
static void __gen6_gt_force_wake_put(struct drm_i915_private *dev_priv)
{
I915_WRITE_NOTRACE(FORCEWAKE, 0);
POSTING_READ(ECOBUS);
gen6_gt_check_fifodbg(dev_priv);
}
static void __gen6_gt_force_wake_mt_put(struct drm_i915_private *dev_priv)
{
I915_WRITE_NOTRACE(FORCEWAKE_MT, _MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
POSTING_READ(ECOBUS);
gen6_gt_check_fifodbg(dev_priv);
}
void gen6_gt_force_wake_put(struct drm_i915_private *dev_priv)
{
unsigned long irqflags;
spin_lock_irqsave(&dev_priv->gt_lock, irqflags);
if (--dev_priv->forcewake_count == 0)
dev_priv->gt.force_wake_put(dev_priv);
spin_unlock_irqrestore(&dev_priv->gt_lock, irqflags);
}
int __gen6_gt_wait_for_fifo(struct drm_i915_private *dev_priv)
{
int ret = 0;
if (dev_priv->gt_fifo_count < GT_FIFO_NUM_RESERVED_ENTRIES) {
int loop = 500;
u32 fifo = I915_READ_NOTRACE(GT_FIFO_FREE_ENTRIES);
while (fifo <= GT_FIFO_NUM_RESERVED_ENTRIES && loop--) {
udelay(10);
fifo = I915_READ_NOTRACE(GT_FIFO_FREE_ENTRIES);
}
if (WARN_ON(loop < 0 && fifo <= GT_FIFO_NUM_RESERVED_ENTRIES))
++ret;
dev_priv->gt_fifo_count = fifo;
}
dev_priv->gt_fifo_count--;
return ret;
}
static void vlv_force_wake_reset(struct drm_i915_private *dev_priv)
{
I915_WRITE_NOTRACE(FORCEWAKE_VLV, _MASKED_BIT_DISABLE(0xffff));
POSTING_READ(FORCEWAKE_ACK_VLV);
}
static void vlv_force_wake_get(struct drm_i915_private *dev_priv)
{
if (wait_for_atomic((I915_READ_NOTRACE(FORCEWAKE_ACK_VLV) & FORCEWAKE_KERNEL) == 0,
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for forcewake old ack to clear.\n");
I915_WRITE_NOTRACE(FORCEWAKE_VLV, _MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
I915_WRITE_NOTRACE(FORCEWAKE_MEDIA_VLV,
_MASKED_BIT_ENABLE(FORCEWAKE_KERNEL));
if (wait_for_atomic((I915_READ_NOTRACE(FORCEWAKE_ACK_VLV) & FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for GT to ack forcewake request.\n");
if (wait_for_atomic((I915_READ_NOTRACE(FORCEWAKE_ACK_MEDIA_VLV) &
FORCEWAKE_KERNEL),
FORCEWAKE_ACK_TIMEOUT_MS))
DRM_ERROR("Timed out waiting for media to ack forcewake request.\n");
__gen6_gt_wait_for_thread_c0(dev_priv);
}
static void vlv_force_wake_put(struct drm_i915_private *dev_priv)
{
I915_WRITE_NOTRACE(FORCEWAKE_VLV, _MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
I915_WRITE_NOTRACE(FORCEWAKE_MEDIA_VLV,
_MASKED_BIT_DISABLE(FORCEWAKE_KERNEL));
gen6_gt_check_fifodbg(dev_priv);
}
void intel_gt_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (IS_VALLEYVIEW(dev)) {
vlv_force_wake_reset(dev_priv);
} else if (INTEL_INFO(dev)->gen >= 6) {
__gen6_gt_force_wake_reset(dev_priv);
if (IS_IVYBRIDGE(dev) || IS_HASWELL(dev))
__gen6_gt_force_wake_mt_reset(dev_priv);
}
}
void intel_gt_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
spin_lock_init(&dev_priv->gt_lock);
intel_gt_reset(dev);
if (IS_VALLEYVIEW(dev)) {
dev_priv->gt.force_wake_get = vlv_force_wake_get;
dev_priv->gt.force_wake_put = vlv_force_wake_put;
} else if (IS_IVYBRIDGE(dev) || IS_HASWELL(dev)) {
dev_priv->gt.force_wake_get = __gen6_gt_force_wake_mt_get;
dev_priv->gt.force_wake_put = __gen6_gt_force_wake_mt_put;
} else if (IS_GEN6(dev)) {
dev_priv->gt.force_wake_get = __gen6_gt_force_wake_get;
dev_priv->gt.force_wake_put = __gen6_gt_force_wake_put;
}
INIT_DELAYED_WORK(&dev_priv->rps.delayed_resume_work,
intel_gen6_powersave_work);
}
int sandybridge_pcode_read(struct drm_i915_private *dev_priv, u8 mbox, u32 *val)
{
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
if (I915_READ(GEN6_PCODE_MAILBOX) & GEN6_PCODE_READY) {
DRM_DEBUG_DRIVER("warning: pcode (read) mailbox access failed\n");
return -EAGAIN;
}
I915_WRITE(GEN6_PCODE_DATA, *val);
I915_WRITE(GEN6_PCODE_MAILBOX, GEN6_PCODE_READY | mbox);
if (wait_for((I915_READ(GEN6_PCODE_MAILBOX) & GEN6_PCODE_READY) == 0,
500)) {
DRM_ERROR("timeout waiting for pcode read (%d) to finish\n", mbox);
return -ETIMEDOUT;
}
*val = I915_READ(GEN6_PCODE_DATA);
I915_WRITE(GEN6_PCODE_DATA, 0);
return 0;
}
int sandybridge_pcode_write(struct drm_i915_private *dev_priv, u8 mbox, u32 val)
{
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
if (I915_READ(GEN6_PCODE_MAILBOX) & GEN6_PCODE_READY) {
DRM_DEBUG_DRIVER("warning: pcode (write) mailbox access failed\n");
return -EAGAIN;
}
I915_WRITE(GEN6_PCODE_DATA, val);
I915_WRITE(GEN6_PCODE_MAILBOX, GEN6_PCODE_READY | mbox);
if (wait_for((I915_READ(GEN6_PCODE_MAILBOX) & GEN6_PCODE_READY) == 0,
500)) {
DRM_ERROR("timeout waiting for pcode write (%d) to finish\n", mbox);
return -ETIMEDOUT;
}
I915_WRITE(GEN6_PCODE_DATA, 0);
return 0;
}
static int vlv_punit_rw(struct drm_i915_private *dev_priv, u8 opcode,
u8 addr, u32 *val)
{
u32 cmd, devfn, port, be, bar;
bar = 0;
be = 0xf;
port = IOSF_PORT_PUNIT;
devfn = PCI_DEVFN(2, 0);
cmd = (devfn << IOSF_DEVFN_SHIFT) | (opcode << IOSF_OPCODE_SHIFT) |
(port << IOSF_PORT_SHIFT) | (be << IOSF_BYTE_ENABLES_SHIFT) |
(bar << IOSF_BAR_SHIFT);
WARN_ON(!mutex_is_locked(&dev_priv->rps.hw_lock));
if (I915_READ(VLV_IOSF_DOORBELL_REQ) & IOSF_SB_BUSY) {
DRM_DEBUG_DRIVER("warning: pcode (%s) mailbox access failed\n",
opcode == PUNIT_OPCODE_REG_READ ?
"read" : "write");
return -EAGAIN;
}
I915_WRITE(VLV_IOSF_ADDR, addr);
if (opcode == PUNIT_OPCODE_REG_WRITE)
I915_WRITE(VLV_IOSF_DATA, *val);
I915_WRITE(VLV_IOSF_DOORBELL_REQ, cmd);
if (wait_for((I915_READ(VLV_IOSF_DOORBELL_REQ) & IOSF_SB_BUSY) == 0,
500)) {
DRM_ERROR("timeout waiting for pcode %s (%d) to finish\n",
opcode == PUNIT_OPCODE_REG_READ ? "read" : "write",
addr);
return -ETIMEDOUT;
}
if (opcode == PUNIT_OPCODE_REG_READ)
*val = I915_READ(VLV_IOSF_DATA);
I915_WRITE(VLV_IOSF_DATA, 0);
return 0;
}
int valleyview_punit_read(struct drm_i915_private *dev_priv, u8 addr, u32 *val)
{
return vlv_punit_rw(dev_priv, PUNIT_OPCODE_REG_READ, addr, val);
}
int valleyview_punit_write(struct drm_i915_private *dev_priv, u8 addr, u32 val)
{
return vlv_punit_rw(dev_priv, PUNIT_OPCODE_REG_WRITE, addr, &val);
}
