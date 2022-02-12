static void i8xx_fbc_disable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 fbc_ctl;
dev_priv->fbc.enabled = false;
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
static void i8xx_fbc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
int cfb_pitch;
int i;
u32 fbc_ctl;
dev_priv->fbc.enabled = true;
cfb_pitch = dev_priv->fbc.size / FBC_LL_SIZE;
if (fb->pitches[0] < cfb_pitch)
cfb_pitch = fb->pitches[0];
if (IS_GEN2(dev))
cfb_pitch = (cfb_pitch / 32) - 1;
else
cfb_pitch = (cfb_pitch / 64) - 1;
for (i = 0; i < (FBC_LL_SIZE / 32) + 1; i++)
I915_WRITE(FBC_TAG + (i * 4), 0);
if (IS_GEN4(dev)) {
u32 fbc_ctl2;
fbc_ctl2 = FBC_CTL_FENCE_DBL | FBC_CTL_IDLE_IMM | FBC_CTL_CPU_FENCE;
fbc_ctl2 |= FBC_CTL_PLANE(intel_crtc->plane);
I915_WRITE(FBC_CONTROL2, fbc_ctl2);
I915_WRITE(FBC_FENCE_OFF, crtc->y);
}
fbc_ctl = I915_READ(FBC_CONTROL);
fbc_ctl &= 0x3fff << FBC_CTL_INTERVAL_SHIFT;
fbc_ctl |= FBC_CTL_EN | FBC_CTL_PERIODIC;
if (IS_I945GM(dev))
fbc_ctl |= FBC_CTL_C3_IDLE;
fbc_ctl |= (cfb_pitch & 0xff) << FBC_CTL_STRIDE_SHIFT;
fbc_ctl |= obj->fence_reg;
I915_WRITE(FBC_CONTROL, fbc_ctl);
DRM_DEBUG_KMS("enabled FBC, pitch %d, yoff %d, plane %c\n",
cfb_pitch, crtc->y, plane_name(intel_crtc->plane));
}
static bool i8xx_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(FBC_CONTROL) & FBC_CTL_EN;
}
static void g4x_fbc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
u32 dpfc_ctl;
dev_priv->fbc.enabled = true;
dpfc_ctl = DPFC_CTL_PLANE(intel_crtc->plane) | DPFC_SR_EN;
if (drm_format_plane_cpp(fb->pixel_format, 0) == 2)
dpfc_ctl |= DPFC_CTL_LIMIT_2X;
else
dpfc_ctl |= DPFC_CTL_LIMIT_1X;
dpfc_ctl |= DPFC_CTL_FENCE_EN | obj->fence_reg;
I915_WRITE(DPFC_FENCE_YOFF, crtc->y);
I915_WRITE(DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
DRM_DEBUG_KMS("enabled fbc on plane %c\n", plane_name(intel_crtc->plane));
}
static void g4x_fbc_disable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpfc_ctl;
dev_priv->fbc.enabled = false;
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
static void snb_fbc_blit_update(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 blt_ecoskpd;
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_MEDIA);
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
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_MEDIA);
}
static void ilk_fbc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
u32 dpfc_ctl;
dev_priv->fbc.enabled = true;
dpfc_ctl = DPFC_CTL_PLANE(intel_crtc->plane);
if (drm_format_plane_cpp(fb->pixel_format, 0) == 2)
dev_priv->fbc.threshold++;
switch (dev_priv->fbc.threshold) {
case 4:
case 3:
dpfc_ctl |= DPFC_CTL_LIMIT_4X;
break;
case 2:
dpfc_ctl |= DPFC_CTL_LIMIT_2X;
break;
case 1:
dpfc_ctl |= DPFC_CTL_LIMIT_1X;
break;
}
dpfc_ctl |= DPFC_CTL_FENCE_EN;
if (IS_GEN5(dev))
dpfc_ctl |= obj->fence_reg;
I915_WRITE(ILK_DPFC_FENCE_YOFF, crtc->y);
I915_WRITE(ILK_FBC_RT_BASE, i915_gem_obj_ggtt_offset(obj) | ILK_FBC_RT_VALID);
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
if (IS_GEN6(dev)) {
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | obj->fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, crtc->y);
snb_fbc_blit_update(dev);
}
DRM_DEBUG_KMS("enabled fbc on plane %c\n", plane_name(intel_crtc->plane));
}
static void ilk_fbc_disable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 dpfc_ctl;
dev_priv->fbc.enabled = false;
dpfc_ctl = I915_READ(ILK_DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl);
DRM_DEBUG_KMS("disabled FBC\n");
}
}
static bool ilk_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return I915_READ(ILK_DPFC_CONTROL) & DPFC_CTL_EN;
}
static void gen7_fbc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_framebuffer *fb = crtc->primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
u32 dpfc_ctl;
dev_priv->fbc.enabled = true;
dpfc_ctl = IVB_DPFC_CTL_PLANE(intel_crtc->plane);
if (drm_format_plane_cpp(fb->pixel_format, 0) == 2)
dev_priv->fbc.threshold++;
switch (dev_priv->fbc.threshold) {
case 4:
case 3:
dpfc_ctl |= DPFC_CTL_LIMIT_4X;
break;
case 2:
dpfc_ctl |= DPFC_CTL_LIMIT_2X;
break;
case 1:
dpfc_ctl |= DPFC_CTL_LIMIT_1X;
break;
}
dpfc_ctl |= IVB_DPFC_CTL_FENCE_EN;
if (dev_priv->fbc.false_color)
dpfc_ctl |= FBC_CTL_FALSE_COLOR;
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
if (IS_IVYBRIDGE(dev)) {
I915_WRITE(ILK_DISPLAY_CHICKEN1,
I915_READ(ILK_DISPLAY_CHICKEN1) |
ILK_FBCQ_DIS);
} else {
I915_WRITE(CHICKEN_PIPESL_1(intel_crtc->pipe),
I915_READ(CHICKEN_PIPESL_1(intel_crtc->pipe)) |
HSW_FBCQ_DIS);
}
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | obj->fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, crtc->y);
snb_fbc_blit_update(dev);
DRM_DEBUG_KMS("enabled fbc on plane %c\n", plane_name(intel_crtc->plane));
}
bool intel_fbc_enabled(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
return dev_priv->fbc.enabled;
}
void bdw_fbc_sw_flush(struct drm_device *dev, u32 value)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!IS_GEN8(dev))
return;
if (!intel_fbc_enabled(dev))
return;
I915_WRITE(MSG_FBC_REND_STATE, value);
}
static void intel_fbc_work_fn(struct work_struct *__work)
{
struct intel_fbc_work *work =
container_of(to_delayed_work(__work),
struct intel_fbc_work, work);
struct drm_device *dev = work->crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev->struct_mutex);
if (work == dev_priv->fbc.fbc_work) {
if (work->crtc->primary->fb == work->fb) {
dev_priv->display.enable_fbc(work->crtc);
dev_priv->fbc.plane = to_intel_crtc(work->crtc)->plane;
dev_priv->fbc.fb_id = work->crtc->primary->fb->base.id;
dev_priv->fbc.y = work->crtc->y;
}
dev_priv->fbc.fbc_work = NULL;
}
mutex_unlock(&dev->struct_mutex);
kfree(work);
}
static void intel_fbc_cancel_work(struct drm_i915_private *dev_priv)
{
if (dev_priv->fbc.fbc_work == NULL)
return;
DRM_DEBUG_KMS("cancelling pending FBC enable\n");
if (cancel_delayed_work(&dev_priv->fbc.fbc_work->work))
kfree(dev_priv->fbc.fbc_work);
dev_priv->fbc.fbc_work = NULL;
}
static void intel_fbc_enable(struct drm_crtc *crtc)
{
struct intel_fbc_work *work;
struct drm_device *dev = crtc->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv->display.enable_fbc)
return;
intel_fbc_cancel_work(dev_priv);
work = kzalloc(sizeof(*work), GFP_KERNEL);
if (work == NULL) {
DRM_ERROR("Failed to allocate FBC work structure\n");
dev_priv->display.enable_fbc(crtc);
return;
}
work->crtc = crtc;
work->fb = crtc->primary->fb;
INIT_DELAYED_WORK(&work->work, intel_fbc_work_fn);
dev_priv->fbc.fbc_work = work;
schedule_delayed_work(&work->work, msecs_to_jiffies(50));
}
void intel_fbc_disable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
intel_fbc_cancel_work(dev_priv);
if (!dev_priv->display.disable_fbc)
return;
dev_priv->display.disable_fbc(dev);
dev_priv->fbc.plane = -1;
}
static bool set_no_fbc_reason(struct drm_i915_private *dev_priv,
enum no_fbc_reason reason)
{
if (dev_priv->fbc.no_fbc_reason == reason)
return false;
dev_priv->fbc.no_fbc_reason = reason;
return true;
}
void intel_fbc_update(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc = NULL, *tmp_crtc;
struct intel_crtc *intel_crtc;
struct drm_framebuffer *fb;
struct drm_i915_gem_object *obj;
const struct drm_display_mode *adjusted_mode;
unsigned int max_width, max_height;
if (!HAS_FBC(dev)) {
set_no_fbc_reason(dev_priv, FBC_UNSUPPORTED);
return;
}
if (!i915.powersave) {
if (set_no_fbc_reason(dev_priv, FBC_MODULE_PARAM))
DRM_DEBUG_KMS("fbc disabled per module param\n");
return;
}
for_each_crtc(dev, tmp_crtc) {
if (intel_crtc_active(tmp_crtc) &&
to_intel_crtc(tmp_crtc)->primary_enabled) {
if (crtc) {
if (set_no_fbc_reason(dev_priv, FBC_MULTIPLE_PIPES))
DRM_DEBUG_KMS("more than one pipe active, disabling compression\n");
goto out_disable;
}
crtc = tmp_crtc;
}
}
if (!crtc || crtc->primary->fb == NULL) {
if (set_no_fbc_reason(dev_priv, FBC_NO_OUTPUT))
DRM_DEBUG_KMS("no output, disabling\n");
goto out_disable;
}
intel_crtc = to_intel_crtc(crtc);
fb = crtc->primary->fb;
obj = intel_fb_obj(fb);
adjusted_mode = &intel_crtc->config->base.adjusted_mode;
if (i915.enable_fbc < 0) {
if (set_no_fbc_reason(dev_priv, FBC_CHIP_DEFAULT))
DRM_DEBUG_KMS("disabled per chip default\n");
goto out_disable;
}
if (!i915.enable_fbc) {
if (set_no_fbc_reason(dev_priv, FBC_MODULE_PARAM))
DRM_DEBUG_KMS("fbc disabled per module param\n");
goto out_disable;
}
if ((adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE) ||
(adjusted_mode->flags & DRM_MODE_FLAG_DBLSCAN)) {
if (set_no_fbc_reason(dev_priv, FBC_UNSUPPORTED_MODE))
DRM_DEBUG_KMS("mode incompatible with compression, "
"disabling\n");
goto out_disable;
}
if (INTEL_INFO(dev)->gen >= 8 || IS_HASWELL(dev)) {
max_width = 4096;
max_height = 4096;
} else if (IS_G4X(dev) || INTEL_INFO(dev)->gen >= 5) {
max_width = 4096;
max_height = 2048;
} else {
max_width = 2048;
max_height = 1536;
}
if (intel_crtc->config->pipe_src_w > max_width ||
intel_crtc->config->pipe_src_h > max_height) {
if (set_no_fbc_reason(dev_priv, FBC_MODE_TOO_LARGE))
DRM_DEBUG_KMS("mode too large for compression, disabling\n");
goto out_disable;
}
if ((INTEL_INFO(dev)->gen < 4 || HAS_DDI(dev)) &&
intel_crtc->plane != PLANE_A) {
if (set_no_fbc_reason(dev_priv, FBC_BAD_PLANE))
DRM_DEBUG_KMS("plane not A, disabling compression\n");
goto out_disable;
}
if (obj->tiling_mode != I915_TILING_X ||
obj->fence_reg == I915_FENCE_REG_NONE) {
if (set_no_fbc_reason(dev_priv, FBC_NOT_TILED))
DRM_DEBUG_KMS("framebuffer not tiled or fenced, disabling compression\n");
goto out_disable;
}
if (INTEL_INFO(dev)->gen <= 4 && !IS_G4X(dev) &&
crtc->primary->state->rotation != BIT(DRM_ROTATE_0)) {
if (set_no_fbc_reason(dev_priv, FBC_UNSUPPORTED_MODE))
DRM_DEBUG_KMS("Rotation unsupported, disabling\n");
goto out_disable;
}
if (in_dbg_master())
goto out_disable;
if (i915_gem_stolen_setup_compression(dev, obj->base.size,
drm_format_plane_cpp(fb->pixel_format, 0))) {
if (set_no_fbc_reason(dev_priv, FBC_STOLEN_TOO_SMALL))
DRM_DEBUG_KMS("framebuffer too large, disabling compression\n");
goto out_disable;
}
if (dev_priv->fbc.plane == intel_crtc->plane &&
dev_priv->fbc.fb_id == fb->base.id &&
dev_priv->fbc.y == crtc->y)
return;
if (intel_fbc_enabled(dev)) {
DRM_DEBUG_KMS("disabling active FBC for update\n");
intel_fbc_disable(dev);
}
intel_fbc_enable(crtc);
dev_priv->fbc.no_fbc_reason = FBC_OK;
return;
out_disable:
if (intel_fbc_enabled(dev)) {
DRM_DEBUG_KMS("unsupported config, disabling FBC\n");
intel_fbc_disable(dev);
}
i915_gem_stolen_cleanup_compression(dev);
}
void intel_fbc_init(struct drm_i915_private *dev_priv)
{
if (!HAS_FBC(dev_priv)) {
dev_priv->fbc.enabled = false;
return;
}
if (INTEL_INFO(dev_priv)->gen >= 7) {
dev_priv->display.fbc_enabled = ilk_fbc_enabled;
dev_priv->display.enable_fbc = gen7_fbc_enable;
dev_priv->display.disable_fbc = ilk_fbc_disable;
} else if (INTEL_INFO(dev_priv)->gen >= 5) {
dev_priv->display.fbc_enabled = ilk_fbc_enabled;
dev_priv->display.enable_fbc = ilk_fbc_enable;
dev_priv->display.disable_fbc = ilk_fbc_disable;
} else if (IS_GM45(dev_priv)) {
dev_priv->display.fbc_enabled = g4x_fbc_enabled;
dev_priv->display.enable_fbc = g4x_fbc_enable;
dev_priv->display.disable_fbc = g4x_fbc_disable;
} else {
dev_priv->display.fbc_enabled = i8xx_fbc_enabled;
dev_priv->display.enable_fbc = i8xx_fbc_enable;
dev_priv->display.disable_fbc = i8xx_fbc_disable;
I915_WRITE(FBC_CONTROL, 500 << FBC_CTL_INTERVAL_SHIFT);
}
dev_priv->fbc.enabled = dev_priv->display.fbc_enabled(dev_priv->dev);
}
