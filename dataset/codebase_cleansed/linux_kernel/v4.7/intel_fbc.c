static inline bool fbc_supported(struct drm_i915_private *dev_priv)
{
return HAS_FBC(dev_priv);
}
static inline bool fbc_on_pipe_a_only(struct drm_i915_private *dev_priv)
{
return IS_HASWELL(dev_priv) || INTEL_INFO(dev_priv)->gen >= 8;
}
static inline bool fbc_on_plane_a_only(struct drm_i915_private *dev_priv)
{
return INTEL_INFO(dev_priv)->gen < 4;
}
static inline bool no_fbc_on_multiple_pipes(struct drm_i915_private *dev_priv)
{
return INTEL_INFO(dev_priv)->gen <= 3;
}
static unsigned int get_crtc_fence_y_offset(struct intel_crtc *crtc)
{
return crtc->base.y - crtc->adjusted_y;
}
static void intel_fbc_get_plane_source_size(struct intel_fbc_state_cache *cache,
int *width, int *height)
{
int w, h;
if (intel_rotation_90_or_270(cache->plane.rotation)) {
w = cache->plane.src_h;
h = cache->plane.src_w;
} else {
w = cache->plane.src_w;
h = cache->plane.src_h;
}
if (width)
*width = w;
if (height)
*height = h;
}
static int intel_fbc_calculate_cfb_size(struct drm_i915_private *dev_priv,
struct intel_fbc_state_cache *cache)
{
int lines;
intel_fbc_get_plane_source_size(cache, NULL, &lines);
if (INTEL_INFO(dev_priv)->gen >= 7)
lines = min(lines, 2048);
return lines * cache->fb.stride;
}
static void i8xx_fbc_deactivate(struct drm_i915_private *dev_priv)
{
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
}
static void i8xx_fbc_activate(struct drm_i915_private *dev_priv)
{
struct intel_fbc_reg_params *params = &dev_priv->fbc.params;
int cfb_pitch;
int i;
u32 fbc_ctl;
cfb_pitch = params->cfb_size / FBC_LL_SIZE;
if (params->fb.stride < cfb_pitch)
cfb_pitch = params->fb.stride;
if (IS_GEN2(dev_priv))
cfb_pitch = (cfb_pitch / 32) - 1;
else
cfb_pitch = (cfb_pitch / 64) - 1;
for (i = 0; i < (FBC_LL_SIZE / 32) + 1; i++)
I915_WRITE(FBC_TAG(i), 0);
if (IS_GEN4(dev_priv)) {
u32 fbc_ctl2;
fbc_ctl2 = FBC_CTL_FENCE_DBL | FBC_CTL_IDLE_IMM | FBC_CTL_CPU_FENCE;
fbc_ctl2 |= FBC_CTL_PLANE(params->crtc.plane);
I915_WRITE(FBC_CONTROL2, fbc_ctl2);
I915_WRITE(FBC_FENCE_OFF, params->crtc.fence_y_offset);
}
fbc_ctl = I915_READ(FBC_CONTROL);
fbc_ctl &= 0x3fff << FBC_CTL_INTERVAL_SHIFT;
fbc_ctl |= FBC_CTL_EN | FBC_CTL_PERIODIC;
if (IS_I945GM(dev_priv))
fbc_ctl |= FBC_CTL_C3_IDLE;
fbc_ctl |= (cfb_pitch & 0xff) << FBC_CTL_STRIDE_SHIFT;
fbc_ctl |= params->fb.fence_reg;
I915_WRITE(FBC_CONTROL, fbc_ctl);
}
static bool i8xx_fbc_is_active(struct drm_i915_private *dev_priv)
{
return I915_READ(FBC_CONTROL) & FBC_CTL_EN;
}
static void g4x_fbc_activate(struct drm_i915_private *dev_priv)
{
struct intel_fbc_reg_params *params = &dev_priv->fbc.params;
u32 dpfc_ctl;
dpfc_ctl = DPFC_CTL_PLANE(params->crtc.plane) | DPFC_SR_EN;
if (drm_format_plane_cpp(params->fb.pixel_format, 0) == 2)
dpfc_ctl |= DPFC_CTL_LIMIT_2X;
else
dpfc_ctl |= DPFC_CTL_LIMIT_1X;
dpfc_ctl |= DPFC_CTL_FENCE_EN | params->fb.fence_reg;
I915_WRITE(DPFC_FENCE_YOFF, params->crtc.fence_y_offset);
I915_WRITE(DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
}
static void g4x_fbc_deactivate(struct drm_i915_private *dev_priv)
{
u32 dpfc_ctl;
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
static void ilk_fbc_activate(struct drm_i915_private *dev_priv)
{
struct intel_fbc_reg_params *params = &dev_priv->fbc.params;
u32 dpfc_ctl;
int threshold = dev_priv->fbc.threshold;
dpfc_ctl = DPFC_CTL_PLANE(params->crtc.plane);
if (drm_format_plane_cpp(params->fb.pixel_format, 0) == 2)
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
dpfc_ctl |= params->fb.fence_reg;
I915_WRITE(ILK_DPFC_FENCE_YOFF, params->crtc.fence_y_offset);
I915_WRITE(ILK_FBC_RT_BASE, params->fb.ggtt_offset | ILK_FBC_RT_VALID);
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
if (IS_GEN6(dev_priv)) {
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | params->fb.fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, params->crtc.fence_y_offset);
}
intel_fbc_recompress(dev_priv);
}
static void ilk_fbc_deactivate(struct drm_i915_private *dev_priv)
{
u32 dpfc_ctl;
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
static void gen7_fbc_activate(struct drm_i915_private *dev_priv)
{
struct intel_fbc_reg_params *params = &dev_priv->fbc.params;
u32 dpfc_ctl;
int threshold = dev_priv->fbc.threshold;
dpfc_ctl = 0;
if (IS_IVYBRIDGE(dev_priv))
dpfc_ctl |= IVB_DPFC_CTL_PLANE(params->crtc.plane);
if (drm_format_plane_cpp(params->fb.pixel_format, 0) == 2)
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
I915_WRITE(CHICKEN_PIPESL_1(params->crtc.pipe),
I915_READ(CHICKEN_PIPESL_1(params->crtc.pipe)) |
HSW_FBCQ_DIS);
}
I915_WRITE(ILK_DPFC_CONTROL, dpfc_ctl | DPFC_CTL_EN);
I915_WRITE(SNB_DPFC_CTL_SA,
SNB_CPU_FENCE_ENABLE | params->fb.fence_reg);
I915_WRITE(DPFC_CPU_FENCE_OFFSET, params->crtc.fence_y_offset);
intel_fbc_recompress(dev_priv);
}
static bool intel_fbc_hw_is_active(struct drm_i915_private *dev_priv)
{
if (INTEL_INFO(dev_priv)->gen >= 5)
return ilk_fbc_is_active(dev_priv);
else if (IS_GM45(dev_priv))
return g4x_fbc_is_active(dev_priv);
else
return i8xx_fbc_is_active(dev_priv);
}
static void intel_fbc_hw_activate(struct drm_i915_private *dev_priv)
{
struct intel_fbc *fbc = &dev_priv->fbc;
fbc->active = true;
if (INTEL_INFO(dev_priv)->gen >= 7)
gen7_fbc_activate(dev_priv);
else if (INTEL_INFO(dev_priv)->gen >= 5)
ilk_fbc_activate(dev_priv);
else if (IS_GM45(dev_priv))
g4x_fbc_activate(dev_priv);
else
i8xx_fbc_activate(dev_priv);
}
static void intel_fbc_hw_deactivate(struct drm_i915_private *dev_priv)
{
struct intel_fbc *fbc = &dev_priv->fbc;
fbc->active = false;
if (INTEL_INFO(dev_priv)->gen >= 5)
ilk_fbc_deactivate(dev_priv);
else if (IS_GM45(dev_priv))
g4x_fbc_deactivate(dev_priv);
else
i8xx_fbc_deactivate(dev_priv);
}
bool intel_fbc_is_active(struct drm_i915_private *dev_priv)
{
return dev_priv->fbc.active;
}
static void intel_fbc_work_fn(struct work_struct *__work)
{
struct drm_i915_private *dev_priv =
container_of(__work, struct drm_i915_private, fbc.work.work);
struct intel_fbc *fbc = &dev_priv->fbc;
struct intel_fbc_work *work = &fbc->work;
struct intel_crtc *crtc = fbc->crtc;
struct drm_vblank_crtc *vblank = &dev_priv->dev->vblank[crtc->pipe];
if (drm_crtc_vblank_get(&crtc->base)) {
DRM_ERROR("vblank not available for FBC on pipe %c\n",
pipe_name(crtc->pipe));
mutex_lock(&fbc->lock);
work->scheduled = false;
mutex_unlock(&fbc->lock);
return;
}
retry:
wait_event_timeout(vblank->queue,
drm_crtc_vblank_count(&crtc->base) != work->scheduled_vblank,
msecs_to_jiffies(50));
mutex_lock(&fbc->lock);
if (!work->scheduled)
goto out;
if (drm_crtc_vblank_count(&crtc->base) == work->scheduled_vblank) {
mutex_unlock(&fbc->lock);
goto retry;
}
intel_fbc_hw_activate(dev_priv);
work->scheduled = false;
out:
mutex_unlock(&fbc->lock);
drm_crtc_vblank_put(&crtc->base);
}
static void intel_fbc_schedule_activation(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
struct intel_fbc_work *work = &fbc->work;
WARN_ON(!mutex_is_locked(&fbc->lock));
if (drm_crtc_vblank_get(&crtc->base)) {
DRM_ERROR("vblank not available for FBC on pipe %c\n",
pipe_name(crtc->pipe));
return;
}
work->scheduled = true;
work->scheduled_vblank = drm_crtc_vblank_count(&crtc->base);
drm_crtc_vblank_put(&crtc->base);
schedule_work(&work->work);
}
static void intel_fbc_deactivate(struct drm_i915_private *dev_priv)
{
struct intel_fbc *fbc = &dev_priv->fbc;
WARN_ON(!mutex_is_locked(&fbc->lock));
fbc->work.scheduled = false;
if (fbc->active)
intel_fbc_hw_deactivate(dev_priv);
}
static bool multiple_pipes_ok(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct drm_plane *primary = crtc->base.primary;
struct intel_fbc *fbc = &dev_priv->fbc;
enum pipe pipe = crtc->pipe;
if (!no_fbc_on_multiple_pipes(dev_priv))
return true;
WARN_ON(!drm_modeset_is_locked(&primary->mutex));
if (to_intel_plane_state(primary->state)->visible)
fbc->visible_pipes_mask |= (1 << pipe);
else
fbc->visible_pipes_mask &= ~(1 << pipe);
return (fbc->visible_pipes_mask & ~(1 << pipe)) != 0;
}
static int find_compression_threshold(struct drm_i915_private *dev_priv,
struct drm_mm_node *node,
int size,
int fb_cpp)
{
struct i915_ggtt *ggtt = &dev_priv->ggtt;
int compression_threshold = 1;
int ret;
u64 end;
if (IS_BROADWELL(dev_priv) ||
IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv))
end = ggtt->stolen_size - 8 * 1024 * 1024;
else
end = ggtt->stolen_usable_size;
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
struct intel_fbc *fbc = &dev_priv->fbc;
struct drm_mm_node *uninitialized_var(compressed_llb);
int size, fb_cpp, ret;
WARN_ON(drm_mm_node_allocated(&fbc->compressed_fb));
size = intel_fbc_calculate_cfb_size(dev_priv, &fbc->state_cache);
fb_cpp = drm_format_plane_cpp(fbc->state_cache.fb.pixel_format, 0);
ret = find_compression_threshold(dev_priv, &fbc->compressed_fb,
size, fb_cpp);
if (!ret)
goto err_llb;
else if (ret > 1) {
DRM_INFO("Reducing the compressed framebuffer size. This may lead to less power savings than a non-reduced-size. Try to increase stolen memory size if available in BIOS.\n");
}
fbc->threshold = ret;
if (INTEL_INFO(dev_priv)->gen >= 5)
I915_WRITE(ILK_DPFC_CB_BASE, fbc->compressed_fb.start);
else if (IS_GM45(dev_priv)) {
I915_WRITE(DPFC_CB_BASE, fbc->compressed_fb.start);
} else {
compressed_llb = kzalloc(sizeof(*compressed_llb), GFP_KERNEL);
if (!compressed_llb)
goto err_fb;
ret = i915_gem_stolen_insert_node(dev_priv, compressed_llb,
4096, 4096);
if (ret)
goto err_fb;
fbc->compressed_llb = compressed_llb;
I915_WRITE(FBC_CFB_BASE,
dev_priv->mm.stolen_base + fbc->compressed_fb.start);
I915_WRITE(FBC_LL_BASE,
dev_priv->mm.stolen_base + compressed_llb->start);
}
DRM_DEBUG_KMS("reserved %llu bytes of contiguous stolen space for FBC, threshold: %d\n",
fbc->compressed_fb.size, fbc->threshold);
return 0;
err_fb:
kfree(compressed_llb);
i915_gem_stolen_remove_node(dev_priv, &fbc->compressed_fb);
err_llb:
pr_info_once("drm: not enough stolen space for compressed buffer (need %d more bytes), disabling. Hint: you may be able to increase stolen memory size in the BIOS to avoid this.\n", size);
return -ENOSPC;
}
static void __intel_fbc_cleanup_cfb(struct drm_i915_private *dev_priv)
{
struct intel_fbc *fbc = &dev_priv->fbc;
if (drm_mm_node_allocated(&fbc->compressed_fb))
i915_gem_stolen_remove_node(dev_priv, &fbc->compressed_fb);
if (fbc->compressed_llb) {
i915_gem_stolen_remove_node(dev_priv, fbc->compressed_llb);
kfree(fbc->compressed_llb);
}
}
void intel_fbc_cleanup_cfb(struct drm_i915_private *dev_priv)
{
struct intel_fbc *fbc = &dev_priv->fbc;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&fbc->lock);
__intel_fbc_cleanup_cfb(dev_priv);
mutex_unlock(&fbc->lock);
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
static bool pixel_format_is_valid(struct drm_i915_private *dev_priv,
uint32_t pixel_format)
{
switch (pixel_format) {
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_XBGR8888:
return true;
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_RGB565:
if (IS_GEN2(dev_priv))
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
struct intel_fbc *fbc = &dev_priv->fbc;
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
intel_fbc_get_plane_source_size(&fbc->state_cache, &effective_w,
&effective_h);
effective_w += crtc->adjusted_x;
effective_h += crtc->adjusted_y;
return effective_w <= max_w && effective_h <= max_h;
}
static void intel_fbc_update_state_cache(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
struct intel_fbc_state_cache *cache = &fbc->state_cache;
struct intel_crtc_state *crtc_state =
to_intel_crtc_state(crtc->base.state);
struct intel_plane_state *plane_state =
to_intel_plane_state(crtc->base.primary->state);
struct drm_framebuffer *fb = plane_state->base.fb;
struct drm_i915_gem_object *obj;
WARN_ON(!drm_modeset_is_locked(&crtc->base.mutex));
WARN_ON(!drm_modeset_is_locked(&crtc->base.primary->mutex));
cache->crtc.mode_flags = crtc_state->base.adjusted_mode.flags;
if (IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv))
cache->crtc.hsw_bdw_pixel_rate =
ilk_pipe_pixel_rate(crtc_state);
cache->plane.rotation = plane_state->base.rotation;
cache->plane.src_w = drm_rect_width(&plane_state->src) >> 16;
cache->plane.src_h = drm_rect_height(&plane_state->src) >> 16;
cache->plane.visible = plane_state->visible;
if (!cache->plane.visible)
return;
obj = intel_fb_obj(fb);
if (INTEL_INFO(dev_priv)->gen >= 5 && INTEL_INFO(dev_priv)->gen < 7)
cache->fb.ilk_ggtt_offset = i915_gem_obj_ggtt_offset(obj);
cache->fb.pixel_format = fb->pixel_format;
cache->fb.stride = fb->pitches[0];
cache->fb.fence_reg = obj->fence_reg;
cache->fb.tiling_mode = obj->tiling_mode;
}
static bool intel_fbc_can_activate(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
struct intel_fbc_state_cache *cache = &fbc->state_cache;
if (!cache->plane.visible) {
fbc->no_fbc_reason = "primary plane not visible";
return false;
}
if ((cache->crtc.mode_flags & DRM_MODE_FLAG_INTERLACE) ||
(cache->crtc.mode_flags & DRM_MODE_FLAG_DBLSCAN)) {
fbc->no_fbc_reason = "incompatible mode";
return false;
}
if (!intel_fbc_hw_tracking_covers_screen(crtc)) {
fbc->no_fbc_reason = "mode too large for compression";
return false;
}
if (cache->fb.tiling_mode != I915_TILING_X ||
cache->fb.fence_reg == I915_FENCE_REG_NONE) {
fbc->no_fbc_reason = "framebuffer not tiled or fenced";
return false;
}
if (INTEL_INFO(dev_priv)->gen <= 4 && !IS_G4X(dev_priv) &&
cache->plane.rotation != BIT(DRM_ROTATE_0)) {
fbc->no_fbc_reason = "rotation unsupported";
return false;
}
if (!stride_is_valid(dev_priv, cache->fb.stride)) {
fbc->no_fbc_reason = "framebuffer stride not supported";
return false;
}
if (!pixel_format_is_valid(dev_priv, cache->fb.pixel_format)) {
fbc->no_fbc_reason = "pixel format is invalid";
return false;
}
if ((IS_HASWELL(dev_priv) || IS_BROADWELL(dev_priv)) &&
cache->crtc.hsw_bdw_pixel_rate >= dev_priv->cdclk_freq * 95 / 100) {
fbc->no_fbc_reason = "pixel rate is too big";
return false;
}
if (intel_fbc_calculate_cfb_size(dev_priv, &fbc->state_cache) >
fbc->compressed_fb.size * fbc->threshold) {
fbc->no_fbc_reason = "CFB requirements changed";
return false;
}
return true;
}
static bool intel_fbc_can_choose(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
bool enable_by_default = IS_BROADWELL(dev_priv);
if (intel_vgpu_active(dev_priv->dev)) {
fbc->no_fbc_reason = "VGPU is active";
return false;
}
if (i915.enable_fbc < 0 && !enable_by_default) {
fbc->no_fbc_reason = "disabled per chip default";
return false;
}
if (!i915.enable_fbc) {
fbc->no_fbc_reason = "disabled per module param";
return false;
}
if (fbc_on_pipe_a_only(dev_priv) && crtc->pipe != PIPE_A) {
fbc->no_fbc_reason = "no enabled pipes can have FBC";
return false;
}
if (fbc_on_plane_a_only(dev_priv) && crtc->plane != PLANE_A) {
fbc->no_fbc_reason = "no enabled planes can have FBC";
return false;
}
return true;
}
static void intel_fbc_get_reg_params(struct intel_crtc *crtc,
struct intel_fbc_reg_params *params)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
struct intel_fbc_state_cache *cache = &fbc->state_cache;
memset(params, 0, sizeof(*params));
params->crtc.pipe = crtc->pipe;
params->crtc.plane = crtc->plane;
params->crtc.fence_y_offset = get_crtc_fence_y_offset(crtc);
params->fb.pixel_format = cache->fb.pixel_format;
params->fb.stride = cache->fb.stride;
params->fb.fence_reg = cache->fb.fence_reg;
params->cfb_size = intel_fbc_calculate_cfb_size(dev_priv, cache);
params->fb.ggtt_offset = cache->fb.ilk_ggtt_offset;
}
static bool intel_fbc_reg_params_equal(struct intel_fbc_reg_params *params1,
struct intel_fbc_reg_params *params2)
{
return memcmp(params1, params2, sizeof(*params1)) == 0;
}
void intel_fbc_pre_update(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&fbc->lock);
if (!multiple_pipes_ok(crtc)) {
fbc->no_fbc_reason = "more than one pipe active";
goto deactivate;
}
if (!fbc->enabled || fbc->crtc != crtc)
goto unlock;
intel_fbc_update_state_cache(crtc);
deactivate:
intel_fbc_deactivate(dev_priv);
unlock:
mutex_unlock(&fbc->lock);
}
static void __intel_fbc_post_update(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
struct intel_fbc_reg_params old_params;
WARN_ON(!mutex_is_locked(&fbc->lock));
if (!fbc->enabled || fbc->crtc != crtc)
return;
if (!intel_fbc_can_activate(crtc)) {
WARN_ON(fbc->active);
return;
}
old_params = fbc->params;
intel_fbc_get_reg_params(crtc, &fbc->params);
if (fbc->active &&
intel_fbc_reg_params_equal(&old_params, &fbc->params))
return;
intel_fbc_deactivate(dev_priv);
intel_fbc_schedule_activation(crtc);
fbc->no_fbc_reason = "FBC enabled (active or scheduled)";
}
void intel_fbc_post_update(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&fbc->lock);
__intel_fbc_post_update(crtc);
mutex_unlock(&fbc->lock);
}
static unsigned int intel_fbc_get_frontbuffer_bit(struct intel_fbc *fbc)
{
if (fbc->enabled)
return to_intel_plane(fbc->crtc->base.primary)->frontbuffer_bit;
else
return fbc->possible_framebuffer_bits;
}
void intel_fbc_invalidate(struct drm_i915_private *dev_priv,
unsigned int frontbuffer_bits,
enum fb_op_origin origin)
{
struct intel_fbc *fbc = &dev_priv->fbc;
if (!fbc_supported(dev_priv))
return;
if (origin == ORIGIN_GTT || origin == ORIGIN_FLIP)
return;
mutex_lock(&fbc->lock);
fbc->busy_bits |= intel_fbc_get_frontbuffer_bit(fbc) & frontbuffer_bits;
if (fbc->enabled && fbc->busy_bits)
intel_fbc_deactivate(dev_priv);
mutex_unlock(&fbc->lock);
}
void intel_fbc_flush(struct drm_i915_private *dev_priv,
unsigned int frontbuffer_bits, enum fb_op_origin origin)
{
struct intel_fbc *fbc = &dev_priv->fbc;
if (!fbc_supported(dev_priv))
return;
if (origin == ORIGIN_GTT || origin == ORIGIN_FLIP)
return;
mutex_lock(&fbc->lock);
fbc->busy_bits &= ~frontbuffer_bits;
if (!fbc->busy_bits && fbc->enabled &&
(frontbuffer_bits & intel_fbc_get_frontbuffer_bit(fbc))) {
if (fbc->active)
intel_fbc_recompress(dev_priv);
else
__intel_fbc_post_update(fbc->crtc);
}
mutex_unlock(&fbc->lock);
}
void intel_fbc_choose_crtc(struct drm_i915_private *dev_priv,
struct drm_atomic_state *state)
{
struct intel_fbc *fbc = &dev_priv->fbc;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_plane *plane;
struct drm_plane_state *plane_state;
bool fbc_crtc_present = false;
int i, j;
mutex_lock(&fbc->lock);
for_each_crtc_in_state(state, crtc, crtc_state, i) {
if (fbc->crtc == to_intel_crtc(crtc)) {
fbc_crtc_present = true;
break;
}
}
if (!fbc_crtc_present && fbc->crtc != NULL)
goto out;
for_each_plane_in_state(state, plane, plane_state, i) {
struct intel_plane_state *intel_plane_state =
to_intel_plane_state(plane_state);
if (!intel_plane_state->visible)
continue;
for_each_crtc_in_state(state, crtc, crtc_state, j) {
struct intel_crtc_state *intel_crtc_state =
to_intel_crtc_state(crtc_state);
if (plane_state->crtc != crtc)
continue;
if (!intel_fbc_can_choose(to_intel_crtc(crtc)))
break;
intel_crtc_state->enable_fbc = true;
goto out;
}
}
out:
mutex_unlock(&fbc->lock);
}
void intel_fbc_enable(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&fbc->lock);
if (fbc->enabled) {
WARN_ON(fbc->crtc == NULL);
if (fbc->crtc == crtc) {
WARN_ON(!crtc->config->enable_fbc);
WARN_ON(fbc->active);
}
goto out;
}
if (!crtc->config->enable_fbc)
goto out;
WARN_ON(fbc->active);
WARN_ON(fbc->crtc != NULL);
intel_fbc_update_state_cache(crtc);
if (intel_fbc_alloc_cfb(crtc)) {
fbc->no_fbc_reason = "not enough stolen memory";
goto out;
}
DRM_DEBUG_KMS("Enabling FBC on pipe %c\n", pipe_name(crtc->pipe));
fbc->no_fbc_reason = "FBC enabled but not active yet\n";
fbc->enabled = true;
fbc->crtc = crtc;
out:
mutex_unlock(&fbc->lock);
}
static void __intel_fbc_disable(struct drm_i915_private *dev_priv)
{
struct intel_fbc *fbc = &dev_priv->fbc;
struct intel_crtc *crtc = fbc->crtc;
WARN_ON(!mutex_is_locked(&fbc->lock));
WARN_ON(!fbc->enabled);
WARN_ON(fbc->active);
WARN_ON(crtc->active);
DRM_DEBUG_KMS("Disabling FBC on pipe %c\n", pipe_name(crtc->pipe));
__intel_fbc_cleanup_cfb(dev_priv);
fbc->enabled = false;
fbc->crtc = NULL;
}
void intel_fbc_disable(struct intel_crtc *crtc)
{
struct drm_i915_private *dev_priv = crtc->base.dev->dev_private;
struct intel_fbc *fbc = &dev_priv->fbc;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&fbc->lock);
if (fbc->crtc == crtc) {
WARN_ON(!fbc->enabled);
WARN_ON(fbc->active);
__intel_fbc_disable(dev_priv);
}
mutex_unlock(&fbc->lock);
cancel_work_sync(&fbc->work.work);
}
void intel_fbc_global_disable(struct drm_i915_private *dev_priv)
{
struct intel_fbc *fbc = &dev_priv->fbc;
if (!fbc_supported(dev_priv))
return;
mutex_lock(&fbc->lock);
if (fbc->enabled)
__intel_fbc_disable(dev_priv);
mutex_unlock(&fbc->lock);
cancel_work_sync(&fbc->work.work);
}
void intel_fbc_init_pipe_state(struct drm_i915_private *dev_priv)
{
struct intel_crtc *crtc;
if (!no_fbc_on_multiple_pipes(dev_priv))
return;
for_each_intel_crtc(dev_priv->dev, crtc)
if (intel_crtc_active(&crtc->base) &&
to_intel_plane_state(crtc->base.primary->state)->visible)
dev_priv->fbc.visible_pipes_mask |= (1 << crtc->pipe);
}
void intel_fbc_init(struct drm_i915_private *dev_priv)
{
struct intel_fbc *fbc = &dev_priv->fbc;
enum pipe pipe;
INIT_WORK(&fbc->work.work, intel_fbc_work_fn);
mutex_init(&fbc->lock);
fbc->enabled = false;
fbc->active = false;
fbc->work.scheduled = false;
if (!HAS_FBC(dev_priv)) {
fbc->no_fbc_reason = "unsupported by this chipset";
return;
}
for_each_pipe(dev_priv, pipe) {
fbc->possible_framebuffer_bits |=
INTEL_FRONTBUFFER_PRIMARY(pipe);
if (fbc_on_pipe_a_only(dev_priv))
break;
}
if (INTEL_INFO(dev_priv)->gen <= 4 && !IS_GM45(dev_priv))
I915_WRITE(FBC_CONTROL, 500 << FBC_CTL_INTERVAL_SHIFT);
if (intel_fbc_hw_is_active(dev_priv))
intel_fbc_hw_deactivate(dev_priv);
}
