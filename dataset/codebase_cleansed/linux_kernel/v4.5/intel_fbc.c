static inline bool fbc_supported(struct drm_i915_private *dev_priv)
{
return dev_priv->fbc.activate != NULL;
}
static inline bool fbc_on_pipe_a_only(struct drm_i915_private *dev_priv)
{
return IS_HASWELL(dev_priv) || INTEL_INFO(dev_priv)->gen >= 8;
}
static inline bool fbc_on_plane_a_only(struct drm_i915_private *dev_priv)
{
return INTEL_INFO(dev_priv)->gen < 4;
}
static unsigned int get_crtc_fence_y_offset(struct intel_crtc *crtc)
{
return crtc->base.y - crtc->adjusted_y;
}
static void intel_fbc_get_plane_source_size(struct intel_crtc *crtc,
int *width, int *height)
{
struct intel_plane_state *plane_state =
to_intel_plane_state(crtc->base.primary->state);
int w, h;
if (intel_rotation_90_or_270(plane_state->base.rotation)) {
w = drm_rect_height(&plane_state->src) >> 16;
h = drm_rect_width(&plane_state->src) >> 16;
} else {
w = drm_rect_width(&plane_state->src) >> 16;
h = drm_rect_height(&plane_state->src) >> 16;
}
if (width)
*width = w;
if (height)
*height = h;
}
static int intel_fbc_calculate_cfb_size(struct intel_crtc *crtc,
struct drm_framebuffer *fb)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
int lines;
intel_fbc_get_plane_source_size(crtc, NULL, &lines);
if (INTEL_INFO(dev_priv)->gen >= 7)
lines = min(lines, 2048);
return lines * fb->pitches[0];
}
static void i8xx_fbc_deactivate(struct drm_i915_private *dev_priv)
{
u32 fbc_ctl;
dev_priv->fbc.active = false;
fbc_ctl = I915_READ(FBC_CONTROL);
if ((fbc_ctl & FBC_CTL_EN) == 0)
return;
fbc_ctl &= ~FBC_CTL_EN;
I915_WRITE(FBC_CONTROL, fbc_ctl);
if (wait_for((I915_READ(FBC_STATUS) & FBC_STAT_COMPRESSING) == 0, 10)) {
DRM_DEBUG_KMS("FBC idle timed out\n");
return;
}
}
static void i8xx_fbc_activate(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
int cfb_pitch;
int i;
u32 fbc_ctl;
dev_priv->fbc.active = true;
cfb_pitch = intel_fbc_calculate_cfb_size(crtc, fb) / FBC_LL_SIZE;
if (fb->pitches[0] < cfb_pitch)
cfb_pitch = fb->pitches[0];
if (IS_GEN2(dev_priv))
cfb_pitch = (cfb_pitch / 32) - 1;
else
cfb_pitch = (cfb_pitch / 64) - 1;
for (i = 0; i < (FBC_LL_SIZE / 32) + 1; i++)
I915_WRITE(FBC_TAG(i), 0);
if (IS_GEN4(dev_priv)) {
u32 fbc_ctl2;
fbc_ctl2 = FBC_CTL_FENCE_DBL | FBC_CTL_IDLE_IMM | FBC_CTL_CPU_FENCE;
fbc_ctl2 |= FBC_CTL_PLANE(crtc->plane);
I915_WRITE(FBC_CONTROL2, fbc_ctl2);
I915_WRITE(FBC_FENCE_OFF, get_crtc_fence_y_offset(crtc));
}
fbc_ctl = I915_READ(FBC_CONTROL);
fbc_ctl &= 0x3fff << FBC_CTL_INTERVAL_SHIFT;
fbc_ctl |= FBC_CTL_EN | FBC_CTL_PERIODIC;
if (IS_I945GM(dev_priv))
fbc_ctl |= FBC_CTL_C3_IDLE;
fbc_ctl |= (cfb_pitch & 0xff) << FBC_CTL_STRIDE_SHIFT;
fbc_ctl |= obj->fence_reg;
I915_WRITE(FBC_CONTROL, fbc_ctl);
}
static bool i8xx_fbc_is_active(struct drm_i915_private *dev_priv)
{
return I915_READ(FBC_CONTROL) & FBC_CTL_EN;
}
static void g4x_fbc_activate(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
u32 dpfc_ctl;
dev_priv->fbc.active = true;
dpfc_ctl = DPFC_CTL_PLANE(crtc->plane) | DPFC_SR_EN;
if (drm_format_plane_cpp(fb->pixel_format, 0) == 2)
dpfc_ctl |= DPFC_CTL_LIMIT_2X;
else
dpfc_ctl |= DPFC_CTL_LIMIT_1X;
dpfc_ctl |= DPFC_CTL_FENCE_EN | obj->fence_reg;
I915_WRITE(DPFC_FENCE_YOFF, get_crtc_fence_y_offset(crtc));
I915_WRITE(DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
}
static void g4x_fbc_deactivate(struct drm_i915_private *dev_priv)
{
u32 dpfc_ctl;
dev_priv->fbc.active = false;
dpfc_ctl = I915_READ(DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(DPFC_CONTROL, dpfc_ctl);
}
}
static bool g4x_fbc_is_active(struct drm_i915_private *dev_priv)
{
return I915_READ(DPFC_CONTROL) & DPFC_CTL_EN;
}
static void intel_fbc_recompress(struct drm_i915_private *dev_priv)
{
I915_WRITE(MSG_FBC_REND_STATE, FBC_REND_NUKE);
POSTING_READ(MSG_FBC_REND_STATE);
}
static void ilk_fbc_activate(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
u32 dpfc_ctl;
int threshold = dev_priv->fbc.threshold;
unsigned int y_offset;
dev_priv->fbc.active = true;
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
y_offset = get_crtc_fence_y_offset(crtc);
I915_WRITE(ILK_DPFC_FENCE_YOFF, y_offset);
I915_WRITE(ILK_FBC_RT_BASE, i915_gem_obj_ggtt_offset(obj) | ILK_FBC_RT_VALID);
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
if (IS_GEN6(dev_priv)) {
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | obj->fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, y_offset);
}
intel_fbc_recompress(dev_priv);
}
static void ilk_fbc_deactivate(struct drm_i915_private *dev_priv)
{
u32 dpfc_ctl;
dev_priv->fbc.active = false;
dpfc_ctl = I915_READ(ILK_DPFC_CONTROL);
if (dpfc_ctl & DPFC_CTL_EN) {
dpfc_ctl &= ~DPFC_CTL_EN;
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl);
}
}
static bool ilk_fbc_is_active(struct drm_i915_private *dev_priv)
{
return I915_READ(ILK_DPFC_CONTROL) & DPFC_CTL_EN;
}
static void gen7_fbc_activate(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->fb;
struct drm_i915_gem_object *obj = intel_fb_obj(fb);
u32 dpfc_ctl;
int threshold = dev_priv->fbc.threshold;
dev_priv->fbc.active = true;
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
if (IS_IVYBRIDGE(dev_priv)) {
I915_WRITE(ILK_DISPLAY_CHICKEN1,
I915_READ(ILK_DISPLAY_CHICKEN1) |
ILK_FBCQ_DIS);
} else if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) {
I915_WRITE(CHICKEN_PIPESL_1(crtc->pipe),
I915_READ(CHICKEN_PIPESL_1(crtc->pipe)) |
HSW_FBCQ_DIS);
}
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | obj->fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, get_crtc_fence_y_offset(crtc));
intel_fbc_recompress(dev_priv);
}
bool intel_fbc_is_active(struct drm_i915_private *dev_priv)
{
return dev_priv->fbc.active;
}
static void intel_fbc_activate(const struct drm_framebuffer *fb)
{
struct drm_i915_private *dev_priv = fb->dev->dev_private;
struct intel_crtc *crtc = dev_priv->fbc.crtc;
dev_priv->fbc.activate(crtc);
dev_priv->fbc.fb_id = fb->base.id;
dev_priv->fbc.y = crtc->base.y;
}
static void intel_fbc_work_fn(struct work_struct *__work)
{
struct drm_i915_private *dev_priv =
container_of(__work, struct drm_i915_private, fbc.work.work);
struct intel_fbc_work *work = &dev_priv->fbc.work;
struct intel_crtc *crtc = dev_priv->fbc.crtc;
int delay_ms = 50;
retry:
wait_remaining_ms_from_jiffies(work->enable_jiffies, delay_ms);
mutex_lock(&dev_priv->fbc.lock);
if (!work->scheduled)
goto out;
if (time_after(work->enable_jiffies + msecs_to_jiffies(delay_ms),
jiffies)) {
mutex_unlock(&dev_priv->fbc.lock);
goto retry;
}
if (crtc->base.primary->fb == work->fb)
intel_fbc_activate(work->fb);
work->scheduled = false;
out:
mutex_unlock(&dev_priv->fbc.lock);
}
static void intel_fbc_cancel_work(struct drm_i915_private *dev_priv)
{
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
dev_priv->fbc.work.scheduled = false;
}
static void intel_fbc_schedule_activation(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc_work *work = &dev_priv->fbc.work;
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
work->fb = crtc->base.primary->fb;
work->scheduled = true;
work->enable_jiffies = jiffies;
schedule_work(&work->work);
}
static void __intel_fbc_deactivate(struct drm_i915_private *dev_priv)
{
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
intel_fbc_cancel_work(dev_priv);
if (dev_priv->fbc.active)
dev_priv->fbc.deactivate(dev_priv);
}
void intel_fbc_deactivate(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&dev_priv->fbc.lock);
if (dev_priv->fbc.crtc == crtc)
__intel_fbc_deactivate(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
static void set_no_fbc_reason(struct drm_i915_private *dev_priv,
const char *reason)
{
if (dev_priv->fbc.no_fbc_reason == reason)
return;
dev_priv->fbc.no_fbc_reason = reason;
DRM_DEBUG_KMS("Disabling FBC: %s\n", reason);
}
static bool crtc_can_fbc(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
if (fbc_on_pipe_a_only(dev_priv) && crtc->pipe != PIPE_A)
return false;
if (fbc_on_plane_a_only(dev_priv) && crtc->plane != PLANE_A)
return false;
return true;
}
static bool crtc_is_valid(struct intel_crtc *crtc)
{
if (!intel_crtc_active(&crtc->base))
return false;
if (!to_intel_plane_state(crtc->base.primary->state)->visible)
return false;
return true;
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
u64 end;
if (IS_BROADWELL(dev_priv) ||
IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv))
end = dev_priv->gtt.stolen_size - 8 * 1024 * 1024;
else
end = dev_priv->gtt.stolen_usable_size;
ret = i915_gem_stolen_insert_node_in_range(dev_priv, node, size <<= 1,
4096, 0, end);
if (ret == 0)
return compression_threshold;
again:
if (compression_threshold > 4 ||
(fb_cpp == 2 && compression_threshold == 2))
return 0;
ret = i915_gem_stolen_insert_node_in_range(dev_priv, node, size >>= 1,
4096, 0, end);
if (ret && INTEL_INFO(dev_priv)->gen <= 4) {
return 0;
} else if (ret) {
compression_threshold <<= 1;
goto again;
} else {
return compression_threshold;
}
}
static int intel_fbc_alloc_cfb(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb = crtc->base.primary->state->fb;
struct drm_mm_node *uninitialized_var(compressed_llb);
int size, fb_cpp, ret;
WARN_ON(drm_mm_node_allocated(&dev_priv->fbc.compressed_fb));
size = intel_fbc_calculate_cfb_size(crtc, fb);
fb_cpp = drm_format_plane_cpp(fb->pixel_format, 0);
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
DRM_DEBUG_KMS("reserved %llu bytes of contiguous stolen space for FBC, threshold: %d\n",
dev_priv->fbc.compressed_fb.size,
dev_priv->fbc.threshold);
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
if (drm_mm_node_allocated(&dev_priv->fbc.compressed_fb))
i915_gem_stolen_remove_node(dev_priv,
&dev_priv->fbc.compressed_fb);
if (dev_priv->fbc.compressed_llb) {
i915_gem_stolen_remove_node(dev_priv,
dev_priv->fbc.compressed_llb);
kfree(dev_priv->fbc.compressed_llb);
}
}
void intel_fbc_cleanup_cfb(struct drm_i915_private *dev_priv)
{
if (!fbc_supported(dev_priv))
return;
mutex_lock(&dev_priv->fbc.lock);
__intel_fbc_cleanup_cfb(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
static bool stride_is_valid(struct drm_i915_private *dev_priv,
unsigned int stride)
{
WARN_ON(stride < 512);
WARN_ON((stride & (64 - 1)) != 0);
if (IS_GEN2(dev_priv) || IS_GEN3(dev_priv))
return stride == 4096 || stride == 8192;
if (IS_GEN4(dev_priv) && !IS_G4X(dev_priv) && stride < 2048)
return false;
if (stride > 16384)
return false;
return true;
}
static bool pixel_format_is_valid(struct drm_framebuffer *fb)
{
struct drm_device *dev = fb->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
switch (fb->pixel_format) {
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_XBGR8888:
return true;
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_RGB565:
if (IS_GEN2(dev))
return false;
if (IS_G4X(dev_priv))
return false;
return true;
default:
return false;
}
}
static bool intel_fbc_hw_tracking_covers_screen(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
unsigned int effective_w, effective_h, max_w, max_h;
if (INTEL_INFO(dev_priv)->gen >= 8 || IS_HASWELL(dev_priv)) {
max_w = 4096;
max_h = 4096;
} else if (IS_G4X(dev_priv) || INTEL_INFO(dev_priv)->gen >= 5) {
max_w = 4096;
max_h = 2048;
} else {
max_w = 2048;
max_h = 1536;
}
intel_fbc_get_plane_source_size(crtc, &effective_w, &effective_h);
effective_w += crtc->adjusted_x;
effective_h += crtc->adjusted_y;
return effective_w <= max_w && effective_h <= max_h;
}
static void __intel_fbc_update(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_framebuffer *fb;
struct drm_i915_gem_object *obj;
const struct drm_display_mode *adjusted_mode;
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
if (!multiple_pipes_ok(dev_priv)) {
set_no_fbc_reason(dev_priv, "more than one pipe active");
goto out_disable;
}
if (!dev_priv->fbc.enabled || dev_priv->fbc.crtc != crtc)
return;
if (!crtc_is_valid(crtc)) {
set_no_fbc_reason(dev_priv, "no output");
goto out_disable;
}
fb = crtc->base.primary->fb;
obj = intel_fb_obj(fb);
adjusted_mode = &crtc->config->base.adjusted_mode;
if ((adjusted_mode->flags & DRM_MODE_FLAG_INTERLACE) ||
(adjusted_mode->flags & DRM_MODE_FLAG_DBLSCAN)) {
set_no_fbc_reason(dev_priv, "incompatible mode");
goto out_disable;
}
if (!intel_fbc_hw_tracking_covers_screen(crtc)) {
set_no_fbc_reason(dev_priv, "mode too large for compression");
goto out_disable;
}
if (obj->tiling_mode != I915_TILING_X ||
obj->fence_reg == I915_FENCE_REG_NONE) {
set_no_fbc_reason(dev_priv, "framebuffer not tiled or fenced");
goto out_disable;
}
if (INTEL_INFO(dev_priv)->gen <= 4 && !IS_G4X(dev_priv) &&
crtc->base.primary->state->rotation != BIT(DRM_ROTATE_0)) {
set_no_fbc_reason(dev_priv, "rotation unsupported");
goto out_disable;
}
if (!stride_is_valid(dev_priv, fb->pitches[0])) {
set_no_fbc_reason(dev_priv, "framebuffer stride not supported");
goto out_disable;
}
if (!pixel_format_is_valid(fb)) {
set_no_fbc_reason(dev_priv, "pixel format is invalid");
goto out_disable;
}
if ((IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) &&
ilk_pipe_pixel_rate(crtc->config) >=
dev_priv->cdclk_freq * 95 / 100) {
set_no_fbc_reason(dev_priv, "pixel rate is too big");
goto out_disable;
}
if (intel_fbc_calculate_cfb_size(crtc, fb) >
dev_priv->fbc.compressed_fb.size * dev_priv->fbc.threshold) {
set_no_fbc_reason(dev_priv, "CFB requirements changed");
goto out_disable;
}
if (dev_priv->fbc.crtc == crtc &&
dev_priv->fbc.fb_id == fb->base.id &&
dev_priv->fbc.y == crtc->base.y &&
dev_priv->fbc.active)
return;
if (intel_fbc_is_active(dev_priv)) {
DRM_DEBUG_KMS("deactivating FBC for update\n");
__intel_fbc_deactivate(dev_priv);
}
intel_fbc_schedule_activation(crtc);
dev_priv->fbc.no_fbc_reason = "FBC enabled (not necessarily active)";
return;
out_disable:
if (intel_fbc_is_active(dev_priv)) {
DRM_DEBUG_KMS("unsupported config, deactivating FBC\n");
__intel_fbc_deactivate(dev_priv);
}
}
void intel_fbc_update(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&dev_priv->fbc.lock);
__intel_fbc_update(crtc);
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_invalidate(struct drm_i915_private *dev_priv,
unsigned int frontbuffer_bits,
enum fb_op_origin origin)
{
unsigned int fbc_bits;
if (!fbc_supported(dev_priv))
return;
if (origin == ORIGIN_GTT)
return;
mutex_lock(&dev_priv->fbc.lock);
if (dev_priv->fbc.enabled)
fbc_bits = INTEL_FRONTBUFFER_PRIMARY(dev_priv->fbc.crtc->pipe);
else
fbc_bits = dev_priv->fbc.possible_framebuffer_bits;
dev_priv->fbc.busy_bits |= (fbc_bits & frontbuffer_bits);
if (dev_priv->fbc.busy_bits)
__intel_fbc_deactivate(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_flush(struct drm_i915_private *dev_priv,
unsigned int frontbuffer_bits, enum fb_op_origin origin)
{
if (!fbc_supported(dev_priv))
return;
if (origin == ORIGIN_GTT)
return;
mutex_lock(&dev_priv->fbc.lock);
dev_priv->fbc.busy_bits &= ~frontbuffer_bits;
if (!dev_priv->fbc.busy_bits && dev_priv->fbc.enabled) {
if (origin != ORIGIN_FLIP && dev_priv->fbc.active) {
intel_fbc_recompress(dev_priv);
} else {
__intel_fbc_deactivate(dev_priv);
__intel_fbc_update(dev_priv->fbc.crtc);
}
}
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_enable(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&dev_priv->fbc.lock);
if (dev_priv->fbc.enabled) {
WARN_ON(dev_priv->fbc.crtc == crtc);
goto out;
}
WARN_ON(dev_priv->fbc.active);
WARN_ON(dev_priv->fbc.crtc != NULL);
if (intel_vgpu_active(dev_priv->dev)) {
set_no_fbc_reason(dev_priv, "VGPU is active");
goto out;
}
if (i915.enable_fbc < 0) {
set_no_fbc_reason(dev_priv, "disabled per chip default");
goto out;
}
if (!i915.enable_fbc) {
set_no_fbc_reason(dev_priv, "disabled per module param");
goto out;
}
if (!crtc_can_fbc(crtc)) {
set_no_fbc_reason(dev_priv, "no enabled pipes can have FBC");
goto out;
}
if (intel_fbc_alloc_cfb(crtc)) {
set_no_fbc_reason(dev_priv, "not enough stolen memory");
goto out;
}
DRM_DEBUG_KMS("Enabling FBC on pipe %c\n", pipe_name(crtc->pipe));
dev_priv->fbc.no_fbc_reason = "FBC enabled but not active yet\n";
dev_priv->fbc.enabled = true;
dev_priv->fbc.crtc = crtc;
out:
mutex_unlock(&dev_priv->fbc.lock);
}
static void __intel_fbc_disable(struct drm_i915_private *dev_priv)
{
struct intel_crtc *crtc = dev_priv->fbc.crtc;
WARN_ON(!mutex_is_locked(&dev_priv->fbc.lock));
WARN_ON(!dev_priv->fbc.enabled);
WARN_ON(dev_priv->fbc.active);
assert_pipe_disabled(dev_priv, crtc->pipe);
DRM_DEBUG_KMS("Disabling FBC on pipe %c\n", pipe_name(crtc->pipe));
__intel_fbc_cleanup_cfb(dev_priv);
dev_priv->fbc.enabled = false;
dev_priv->fbc.crtc = NULL;
}
void intel_fbc_disable_crtc(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&dev_priv->fbc.lock);
if (dev_priv->fbc.crtc == crtc) {
WARN_ON(!dev_priv->fbc.enabled);
WARN_ON(dev_priv->fbc.active);
__intel_fbc_disable(dev_priv);
}
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_disable(struct drm_i915_private *dev_priv)
{
if (!fbc_supported(dev_priv))
return;
mutex_lock(&dev_priv->fbc.lock);
if (dev_priv->fbc.enabled)
__intel_fbc_disable(dev_priv);
mutex_unlock(&dev_priv->fbc.lock);
}
void intel_fbc_init(struct drm_i915_private *dev_priv)
{
enum pipe pipe;
INIT_WORK(&dev_priv->fbc.work.work, intel_fbc_work_fn);
mutex_init(&dev_priv->fbc.lock);
dev_priv->fbc.enabled = false;
dev_priv->fbc.active = false;
dev_priv->fbc.work.scheduled = false;
if (!HAS_FBC(dev_priv)) {
dev_priv->fbc.no_fbc_reason = "unsupported by this chipset";
return;
}
for_each_pipe(dev_priv, pipe) {
dev_priv->fbc.possible_framebuffer_bits |=
INTEL_FRONTBUFFER_PRIMARY(pipe);
if (fbc_on_pipe_a_only(dev_priv))
break;
}
if (INTEL_INFO(dev_priv)->gen >= 7) {
dev_priv->fbc.is_active = ilk_fbc_is_active;
dev_priv->fbc.activate = gen7_fbc_activate;
dev_priv->fbc.deactivate = ilk_fbc_deactivate;
} else if (INTEL_INFO(dev_priv)->gen >= 5) {
dev_priv->fbc.is_active = ilk_fbc_is_active;
dev_priv->fbc.activate = ilk_fbc_activate;
dev_priv->fbc.deactivate = ilk_fbc_deactivate;
} else if (IS_GM45(dev_priv)) {
dev_priv->fbc.is_active = g4x_fbc_is_active;
dev_priv->fbc.activate = g4x_fbc_activate;
dev_priv->fbc.deactivate = g4x_fbc_deactivate;
} else {
dev_priv->fbc.is_active = i8xx_fbc_is_active;
dev_priv->fbc.activate = i8xx_fbc_activate;
dev_priv->fbc.deactivate = i8xx_fbc_deactivate;
I915_WRITE(FBC_CONTROL, 500 << FBC_CTL_INTERVAL_SHIFT);
}
if (dev_priv->fbc.is_active(dev_priv))
dev_priv->fbc.deactivate(dev_priv);
}
