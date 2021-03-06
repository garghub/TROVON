static void i8xx_fbc_disable(struct drm_i915_private *dev_priv)
{
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
static void i8xx_fbc_enable(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
int cfb_pitch;
int i;
u32 fbc_ctl;
dev_priv->fbc.enabled = true;
cfb_pitch = dev_priv->fbc.uncompressed_size / FBC_LL_SIZE;
if (fb->pitches[0] < cfb_pitch)
cfb_pitch = fb->pitches[0];
if (IS_GEN2(dev_priv))
cfb_pitch = (cfb_pitch / 32) - 1;
else
cfb_pitch = (cfb_pitch / 64) - 1;
for (i = 0; i < (FBC_LL_SIZE / 32) + 1; i++)
I915_WRITE(FBC_TAG + (i * 4), 0);
if (IS_GEN4(dev_priv)) {
u32 fbc_ctl2;
fbc_ctl2 = FBC_CTL_FENCE_DBL | FBC_CTL_IDLE_IMM | FBC_CTL_CPU_FENCE;
fbc_ctl2 |= FBC_CTL_PLANE(crtc->plane);
I915_WRITE(FBC_CONTROL2, fbc_ctl2);
I915_WRITE(FBC_FENCE_OFF, crtc->base.y);
}
fbc_ctl = I915_READ(FBC_CONTROL);
fbc_ctl &= 0x3fff << FBC_CTL_INTERVAL_SHIFT;
fbc_ctl |= FBC_CTL_EN | FBC_CTL_PERIODIC;
if (IS_I945GM(dev_priv))
fbc_ctl |= FBC_CTL_C3_IDLE;
fbc_ctl |= (cfb_pitch & 0xff) << FBC_CTL_STRIDE_SHIFT;
fbc_ctl |= obj->fence_reg;
I915_WRITE(FBC_CONTROL, fbc_ctl);
DRM_DEBUG_KMS("enabled FBC, pitch %d, yoff %d, plane %c\n",
cfb_pitch, crtc->base.y, plane_name(crtc->plane));
}
static bool i8xx_fbc_enabled(struct drm_i915_private *dev_priv)
{
return I915_READ(FBC_CONTROL) & FBC_CTL_EN;
}
static void g4x_fbc_enable(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
u32 dpfc_ctl;
dev_priv->fbc.enabled = true;
dpfc_ctl = DPFC_CTL_PLANE(crtc->plane) | DPFC_SR_EN;
if (drm_format_plane_cpp(fb->pixel_format, 0) == 2)
dpfc_ctl |= DPFC_CTL_LIMIT_2X;
else
dpfc_ctl |= DPFC_CTL_LIMIT_1X;
dpfc_ctl |= DPFC_CTL_FENCE_EN | obj->fence_reg;
I915_WRITE(DPFC_FENCE_YOFF, crtc->base.y);
I915_WRITE(DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
DRM_DEBUG_KMS("enabled fbc on plane %c\n", plane_name(crtc->plane));
}
static void g4x_fbc_disable(struct drm_i915_private *dev_priv)
{
u32 dpfc_ctl;
dev_priv->fbc.enabled = false;
dpfc_ctl = I915_READ(DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(DPFC_CONTROL, dpfc_ctl);
DRM_DEBUG_KMS("disabled FBC\n");
}
}
static bool g4x_fbc_enabled(struct drm_i915_private *dev_priv)
{
return I915_READ(DPFC_CONTROL) & DPFC_CTL_EN;
}
static void intel_fbc_nuke(struct drm_i915_private *dev_priv)
{
I915_WRITE(MSG_FBC_REND_STATE, FBC_REND_NUKE);
POSTING_READ(MSG_FBC_REND_STATE);
}
static void ilk_fbc_enable(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
u32 dpfc_ctl;
int threshold = dev_priv->fbc.threshold;
dev_priv->fbc.enabled = true;
dpfc_ctl = DPFC_CTL_PLANE(crtc->plane);
if (drm_format_plane_cpp(fb->pixel_format, 0) == 2)
threshold++;
switch (threshold) {
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
if (IS_GEN5(dev_priv))
dpfc_ctl |= obj->fence_reg;
I915_WRITE(ILK_DPFC_FENCE_YOFF, crtc->base.y);
I915_WRITE(ILK_FBC_RT_BASE, i915_gem_obj_ggtt_offset(obj) | ILK_FBC_RT_VALID);
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
if (IS_GEN6(dev_priv)) {
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | obj->fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, crtc->base.y);
}
intel_fbc_nuke(dev_priv);
DRM_DEBUG_KMS("enabled fbc on plane %c\n", plane_name(crtc->plane));
}
static void ilk_fbc_disable(struct drm_i915_private *dev_priv)
{
u32 dpfc_ctl;
dev_priv->fbc.enabled = false;
dpfc_ctl = I915_READ(ILK_DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl);
DRM_DEBUG_KMS("disabled FBC\n");
}
}
static bool ilk_fbc_enabled(struct drm_i915_private *dev_priv)
{
return I915_READ(ILK_DPFC_CONTROL) & DPFC_CTL_EN;
}
static void gen7_fbc_enable(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
u32 dpfc_ctl;
int threshold = dev_priv->fbc.threshold;
dev_priv->fbc.enabled = true;
dpfc_ctl = 0;
if (IS_IVYBRIDGE(dev_priv))
dpfc_ctl |= IVB_DPFC_CTL_PLANE(crtc->plane);
if (drm_format_plane_cpp(fb->pixel_format, 0) == 2)
threshold++;
switch (threshold) {
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
if (IS_IVYBRIDGE(dev_priv)) {
I915_WRITE(ILK_DISPLAY_CHICKEN1,
I915_READ(ILK_DISPLAY_CHICKEN1) |
ILK_FBCQ_DIS);
} else {
I915_WRITE(CHICKEN_PIPESL_1(crtc->pipe),
I915_READ(CHICKEN_PIPESL_1(crtc->pipe)) |
HSW_FBCQ_DIS);
}
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | obj->fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, crtc->base.y);
intel_fbc_nuke(dev_priv);
DRM_DEBUG_KMS("enabled fbc on plane %c\n", plane_name(crtc->plane));
}
bool intel_fbc_enabled(struct drm_i915_private *dev_priv)
{
return dev_priv->fbc.enabled;
}
static void intel_fbc_work_fn(struct work_struct *__work)
{
struct intel_fbc_work *work =
container_of(to_delayed_work(__work),
struct intel_fbc_work, work);
struct drm_i915_private *dev_priv = work->crtc->base.dev->dev_private;
struct drm_framebuffer *crtc_fb = work->crtc->base.primary->fb;
mutex_lock(&dev_priv->fbc.lock);
if (work == dev_priv->fbc.fbc_work) {
if (crtc_fb == work->fb) {
dev_priv->fbc.enable_fbc(work->crtc);
dev_priv->fbc.crtc = work->crtc;
dev_priv->fbc.fb_id = crtc_fb->base.id;
dev_priv->fbc.y = work->crtc->base.y;
}
dev_priv->fbc.fbc_work = NULL;
}
mutex_unlock(&dev_priv->fbc.lock);
kfree(work);
}
static void intel_fbc_cancel_work(struct drm_i915_private *dev_priv)
{
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
if (dev_priv->fbc.fbc_work == NULL)
return;
DRM_DEBUG_KMS("cancelling pending FBC enable\n");
if (cancel_delayed_work(&dev_priv->fbc.fbc_work->work))
kfree(dev_priv->fbc.fbc_work);
dev_priv->fbc.fbc_work = NULL;
}
static void intel_fbc_enable(struct intel_crtc *crtc)
{
struct intel_fbc_work *work;
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
intel_fbc_cancel_work(dev_priv);
work = kzalloc(sizeof(*work), GFP_KERNEL);
if (work == NULL) {
DRM_ERROR("Failed to allocate FBC work structure\n");
dev_priv->fbc.enable_fbc(crtc);
return;
}
work->crtc = crtc;
work->fb = crtc->base.primary->fb;
INIT_DELAYED_WORK(&work->work, intel_fbc_work_fn);
dev_priv->fbc.fbc_work = work;
schedule_delayed_work(&work->work, msecs_to_jiffies(50));
}
static void __intel_fbc_disable(struct drm_i915_private *dev_priv)
{
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
intel_fbc_cancel_work(dev_priv);
dev_priv->fbc.disable_fbc(dev_priv);
dev_priv->fbc.crtc = NULL;
}
void intel_fbc_disable(struct drm_i915_private *dev_priv)
{
if (!dev_priv->fbc.enable_fbc)
return;
mutex_lock(&dev_priv->fbc.lock);
__intel_fbc_disable(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_disable_crtc(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
if (!dev_priv->fbc.enable_fbc)
return;
mutex_lock(&dev_priv->fbc.lock);
if (dev_priv->fbc.crtc == crtc)
__intel_fbc_disable(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
const char *intel_no_fbc_reason_str(enum no_fbc_reason reason)
{
switch (reason) {
case FBC_OK:
return "FBC enabled but currently disabled in hardware";
case FBC_UNSUPPORTED:
return "unsupported by this chipset";
case FBC_NO_OUTPUT:
return "no output";
case FBC_STOLEN_TOO_SMALL:
return "not enough stolen memory";
case FBC_UNSUPPORTED_MODE:
return "mode incompatible with compression";
case FBC_MODE_TOO_LARGE:
return "mode too large for compression";
case FBC_BAD_PLANE:
return "FBC unsupported on plane";
case FBC_NOT_TILED:
return "framebuffer not tiled or fenced";
case FBC_MULTIPLE_PIPES:
return "more than one pipe active";
case FBC_MODULE_PARAM:
return "disabled per module param";
case FBC_CHIP_DEFAULT:
return "disabled per chip default";
case FBC_ROTATION:
return "rotation unsupported";
case FBC_IN_DBG_MASTER:
return "Kernel debugger is active";
default:
MISSING_CASE(reason);
return "unknown reason";
}
}
static void set_no_fbc_reason(struct drm_i915_private *dev_priv,
enum no_fbc_reason reason)
{
if (dev_priv->fbc.no_fbc_reason == reason)
return;
dev_priv->fbc.no_fbc_reason = reason;
DRM_DEBUG_KMS("Disabling FBC: %s\n", intel_no_fbc_reason_str(reason));
}
static struct drm_crtc *intel_fbc_find_crtc(struct drm_i915_private *dev_priv)
{
struct drm_crtc *crtc = NULL, *tmp_crtc;
enum pipe pipe;
bool pipe_a_only = false;
if (IS_HASWELL(dev_priv) || INTEL_INFO(dev_priv)->gen >= 8)
pipe_a_only = true;
for_each_pipe(dev_priv, pipe) {
tmp_crtc = dev_priv->pipe_to_crtc_mapping[pipe];
if (intel_crtc_active(tmp_crtc) &&
to_intel_plane_state(tmp_crtc->primary->state)->visible)
crtc = tmp_crtc;
if (pipe_a_only)
break;
}
if (!crtc || crtc->primary->fb == NULL)
return NULL;
return crtc;
}
static bool multiple_pipes_ok(struct drm_i915_private *dev_priv)
{
enum pipe pipe;
int n_pipes = 0;
struct drm_crtc *crtc;
if (INTEL_INFO(dev_priv)->gen > 4)
return true;
for_each_pipe(dev_priv, pipe) {
crtc = dev_priv->pipe_to_crtc_mapping[pipe];
if (intel_crtc_active(crtc) &&
to_intel_plane_state(crtc->primary->state)->visible)
n_pipes++;
}
return (n_pipes < 2);
}
static int find_compression_threshold(struct drm_i915_private *dev_priv,
struct drm_mm_node *node,
int size,
int fb_cpp)
{
int compression_threshold = 1;
int ret;
ret = i915_gem_stolen_insert_node(dev_priv, node, size <<= 1, 4096);
if (ret == 0)
return compression_threshold;
again:
if (compression_threshold > 4 ||
(fb_cpp == 2 && compression_threshold == 2))
return 0;
ret = i915_gem_stolen_insert_node(dev_priv, node, size >>= 1, 4096);
if (ret && INTEL_INFO(dev_priv)->gen <= 4) {
return 0;
} else if (ret) {
compression_threshold <<= 1;
goto again;
} else {
return compression_threshold;
}
}
static int intel_fbc_alloc_cfb(struct drm_i915_private *dev_priv, int size,
int fb_cpp)
{
struct drm_mm_node *uninitialized_var(compressed_llb);
int ret;
ret = find_compression_threshold(dev_priv, &dev_priv->fbc.compressed_fb,
size, fb_cpp);
if (!ret)
goto err_llb;
else if (ret > 1) {
DRM_INFO("Reducing the compressed framebuffer size. This may lead to less power savings than a non-reduced-size. Try to increase stolen memory size if available in BIOS.\n");
}
dev_priv->fbc.threshold = ret;
if (INTEL_INFO(dev_priv)->gen >= 5)
I915_WRITE(ILK_DPFC_CB_BASE, dev_priv->fbc.compressed_fb.start);
else if (IS_GM45(dev_priv)) {
I915_WRITE(DPFC_CB_BASE, dev_priv->fbc.compressed_fb.start);
} else {
compressed_llb = kzalloc(sizeof(*compressed_llb), GFP_KERNEL);
if (!compressed_llb)
goto err_fb;
ret = i915_gem_stolen_insert_node(dev_priv, compressed_llb,
4096, 4096);
if (ret)
goto err_fb;
dev_priv->fbc.compressed_llb = compressed_llb;
I915_WRITE(FBC_CFB_BASE,
dev_priv->mm.stolen_base + dev_priv->fbc.compressed_fb.start);
I915_WRITE(FBC_LL_BASE,
dev_priv->mm.stolen_base + compressed_llb->start);
}
dev_priv->fbc.uncompressed_size = size;
DRM_DEBUG_KMS("reserved %d bytes of contiguous stolen space for FBC\n",
size);
return 0;
err_fb:
kfree(compressed_llb);
i915_gem_stolen_remove_node(dev_priv, &dev_priv->fbc.compressed_fb);
err_llb:
pr_info_once("drm: not enough stolen space for compressed buffer (need %d more bytes), disabling. Hint: you may be able to increase stolen memory size in the BIOS to avoid this.\n", size);
return -ENOSPC;
}
static void __intel_fbc_cleanup_cfb(struct drm_i915_private *dev_priv)
{
if (dev_priv->fbc.uncompressed_size == 0)
return;
i915_gem_stolen_remove_node(dev_priv, &dev_priv->fbc.compressed_fb);
if (dev_priv->fbc.compressed_llb) {
i915_gem_stolen_remove_node(dev_priv,
dev_priv->fbc.compressed_llb);
kfree(dev_priv->fbc.compressed_llb);
}
dev_priv->fbc.uncompressed_size = 0;
}
void intel_fbc_cleanup_cfb(struct drm_i915_private *dev_priv)
{
if (!dev_priv->fbc.enable_fbc)
return;
mutex_lock(&dev_priv->fbc.lock);
__intel_fbc_cleanup_cfb(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
static int intel_fbc_setup_cfb(struct drm_i915_private *dev_priv, int size,
int fb_cpp)
{
if (size <= dev_priv->fbc.uncompressed_size)
return 0;
__intel_fbc_cleanup_cfb(dev_priv);
return intel_fbc_alloc_cfb(dev_priv, size, fb_cpp);
}
static void __intel_fbc_update(struct drm_i915_private *dev_priv)
{
struct drm_crtc *crtc = NULL;
struct intel_crtc *intel_crtc;
struct drm_framebuffer *fb;
struct drm_i915_gem_object *obj;
const struct drm_display_mode *adjusted_mode;
unsigned int max_width, max_height;
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
if (intel_vgpu_active(dev_priv->dev))
i915.enable_fbc = 0;
if (i915.enable_fbc < 0) {
set_no_fbc_reason(dev_priv, FBC_CHIP_DEFAULT);
goto out_disable;
}
if (!i915.enable_fbc) {
set_no_fbc_reason(dev_priv, FBC_MODULE_PARAM);
goto out_disable;
}
crtc = intel_fbc_find_crtc(dev_priv);
if (!crtc) {
set_no_fbc_reason(dev_priv, FBC_NO_OUTPUT);
goto out_disable;
}
if (!multiple_pipes_ok(dev_priv)) {
set_no_fbc_reason(dev_priv, FBC_MULTIPLE_PIPES);
goto out_disable;
}
intel_crtc = to_intel_crtc(crtc);
fb = crtc->primary->fb;
obj = intel_fb_obj(fb);
adjusted_mode = &intel_crtc->config->base.adjusted_mode;
if ((adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE) ||
(adjusted_mode->flags & DRM_MODE_FLAG_DBLSCAN)) {
set_no_fbc_reason(dev_priv, FBC_UNSUPPORTED_MODE);
goto out_disable;
}
if (INTEL_INFO(dev_priv)->gen >= 8 || IS_HASWELL(dev_priv)) {
max_width = 4096;
max_height = 4096;
} else if (IS_G4X(dev_priv) || INTEL_INFO(dev_priv)->gen >= 5) {
max_width = 4096;
max_height = 2048;
} else {
max_width = 2048;
max_height = 1536;
}
if (intel_crtc->config->pipe_src_w > max_width ||
intel_crtc->config->pipe_src_h > max_height) {
set_no_fbc_reason(dev_priv, FBC_MODE_TOO_LARGE);
goto out_disable;
}
if ((INTEL_INFO(dev_priv)->gen < 4 || HAS_DDI(dev_priv)) &&
intel_crtc->plane != PLANE_A) {
set_no_fbc_reason(dev_priv, FBC_BAD_PLANE);
goto out_disable;
}
if (obj->tiling_mode != I915_TILING_X ||
obj->fence_reg == I915_FENCE_REG_NONE) {
set_no_fbc_reason(dev_priv, FBC_NOT_TILED);
goto out_disable;
}
if (INTEL_INFO(dev_priv)->gen <= 4 && !IS_G4X(dev_priv) &&
crtc->primary->state->rotation != BIT(DRM_ROTATE_0)) {
set_no_fbc_reason(dev_priv, FBC_ROTATION);
goto out_disable;
}
if (in_dbg_master()) {
set_no_fbc_reason(dev_priv, FBC_IN_DBG_MASTER);
goto out_disable;
}
if (intel_fbc_setup_cfb(dev_priv, obj->base.size,
drm_format_plane_cpp(fb->pixel_format, 0))) {
set_no_fbc_reason(dev_priv, FBC_STOLEN_TOO_SMALL);
goto out_disable;
}
if (dev_priv->fbc.crtc == intel_crtc &&
dev_priv->fbc.fb_id == fb->base.id &&
dev_priv->fbc.y == crtc->y)
return;
if (intel_fbc_enabled(dev_priv)) {
DRM_DEBUG_KMS("disabling active FBC for update\n");
__intel_fbc_disable(dev_priv);
}
intel_fbc_enable(intel_crtc);
dev_priv->fbc.no_fbc_reason = FBC_OK;
return;
out_disable:
if (intel_fbc_enabled(dev_priv)) {
DRM_DEBUG_KMS("unsupported config, disabling FBC\n");
__intel_fbc_disable(dev_priv);
}
__intel_fbc_cleanup_cfb(dev_priv);
}
void intel_fbc_update(struct drm_i915_private *dev_priv)
{
if (!dev_priv->fbc.enable_fbc)
return;
mutex_lock(&dev_priv->fbc.lock);
__intel_fbc_update(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_invalidate(struct drm_i915_private *dev_priv,
unsigned int frontbuffer_bits,
enum fb_op_origin origin)
{
unsigned int fbc_bits;
if (!dev_priv->fbc.enable_fbc)
return;
if (origin == ORIGIN_GTT)
return;
mutex_lock(&dev_priv->fbc.lock);
if (dev_priv->fbc.enabled)
fbc_bits = INTEL_FRONTBUFFER_PRIMARY(dev_priv->fbc.crtc->pipe);
else if (dev_priv->fbc.fbc_work)
fbc_bits = INTEL_FRONTBUFFER_PRIMARY(
dev_priv->fbc.fbc_work->crtc->pipe);
else
fbc_bits = dev_priv->fbc.possible_framebuffer_bits;
dev_priv->fbc.busy_bits |= (fbc_bits & frontbuffer_bits);
if (dev_priv->fbc.busy_bits)
__intel_fbc_disable(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_flush(struct drm_i915_private *dev_priv,
unsigned int frontbuffer_bits, enum fb_op_origin origin)
{
if (!dev_priv->fbc.enable_fbc)
return;
if (origin == ORIGIN_GTT)
return;
mutex_lock(&dev_priv->fbc.lock);
dev_priv->fbc.busy_bits &= ~frontbuffer_bits;
if (!dev_priv->fbc.busy_bits) {
__intel_fbc_disable(dev_priv);
__intel_fbc_update(dev_priv);
}
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_init(struct drm_i915_private *dev_priv)
{
enum pipe pipe;
mutex_init(&dev_priv->fbc.lock);
if (!HAS_FBC(dev_priv)) {
dev_priv->fbc.enabled = false;
dev_priv->fbc.no_fbc_reason = FBC_UNSUPPORTED;
return;
}
for_each_pipe(dev_priv, pipe) {
dev_priv->fbc.possible_framebuffer_bits |=
INTEL_FRONTBUFFER_PRIMARY(pipe);
if (IS_HASWELL(dev_priv) || INTEL_INFO(dev_priv)->gen >= 8)
break;
}
if (INTEL_INFO(dev_priv)->gen >= 7) {
dev_priv->fbc.fbc_enabled = ilk_fbc_enabled;
dev_priv->fbc.enable_fbc = gen7_fbc_enable;
dev_priv->fbc.disable_fbc = ilk_fbc_disable;
} else if (INTEL_INFO(dev_priv)->gen >= 5) {
dev_priv->fbc.fbc_enabled = ilk_fbc_enabled;
dev_priv->fbc.enable_fbc = ilk_fbc_enable;
dev_priv->fbc.disable_fbc = ilk_fbc_disable;
} else if (IS_GM45(dev_priv)) {
dev_priv->fbc.fbc_enabled = g4x_fbc_enabled;
dev_priv->fbc.enable_fbc = g4x_fbc_enable;
dev_priv->fbc.disable_fbc = g4x_fbc_disable;
} else {
dev_priv->fbc.fbc_enabled = i8xx_fbc_enabled;
dev_priv->fbc.enable_fbc = i8xx_fbc_enable;
dev_priv->fbc.disable_fbc = i8xx_fbc_disable;
I915_WRITE(FBC_CONTROL, 500 << FBC_CTL_INTERVAL_SHIFT);
}
dev_priv->fbc.enabled = dev_priv->fbc.fbc_enabled(dev_priv);
}
