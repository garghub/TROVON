static void intel_increase_pllclock(struct drm_device *dev,
enum pipe pipe)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int dpll_reg = DPLL(pipe);
int dpll;
if (!HAS_GMCH_DISPLAY(dev))
return;
if (!dev_priv->lvds_downclock_avail)
return;
dpll = I915_READ(dpll_reg);
if (!HAS_PIPE_CXSR(dev) && (dpll & DISPLAY_RATE_SELECT_FPA1)) {
DRM_DEBUG_DRIVER("upclocking LVDS\n");
assert_panel_unlocked(dev_priv, pipe);
dpll &= ~DISPLAY_RATE_SELECT_FPA1;
I915_WRITE(dpll_reg, dpll);
intel_wait_for_vblank(dev, pipe);
dpll = I915_READ(dpll_reg);
if (dpll & DISPLAY_RATE_SELECT_FPA1)
DRM_DEBUG_DRIVER("failed to upclock LVDS!\n");
}
}
static void intel_mark_fb_busy(struct drm_device *dev,
unsigned frontbuffer_bits,
struct intel_engine_cs *ring)
{
struct drm_i915_private *dev_priv = dev->dev_private;
enum pipe pipe;
for_each_pipe(dev_priv, pipe) {
if (!(frontbuffer_bits & INTEL_FRONTBUFFER_ALL_MASK(pipe)))
continue;
intel_increase_pllclock(dev, pipe);
}
}
void intel_fb_obj_invalidate(struct drm_i915_gem_object *obj,
struct intel_engine_cs *ring,
enum fb_op_origin origin)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
if (!obj->frontbuffer_bits)
return;
if (ring) {
mutex_lock(&dev_priv->fb_tracking.lock);
dev_priv->fb_tracking.busy_bits
|= obj->frontbuffer_bits;
dev_priv->fb_tracking.flip_bits
&= ~obj->frontbuffer_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
}
intel_mark_fb_busy(dev, obj->frontbuffer_bits, ring);
intel_psr_invalidate(dev, obj->frontbuffer_bits);
intel_edp_drrs_invalidate(dev, obj->frontbuffer_bits);
intel_fbc_invalidate(dev_priv, obj->frontbuffer_bits, origin);
}
void intel_frontbuffer_flush(struct drm_device *dev,
unsigned frontbuffer_bits)
{
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev_priv->fb_tracking.lock);
frontbuffer_bits &= ~dev_priv->fb_tracking.busy_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
intel_mark_fb_busy(dev, frontbuffer_bits, NULL);
intel_edp_drrs_flush(dev, frontbuffer_bits);
intel_psr_flush(dev, frontbuffer_bits);
intel_fbc_flush(dev_priv, frontbuffer_bits);
}
void intel_fb_obj_flush(struct drm_i915_gem_object *obj,
bool retire)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned frontbuffer_bits;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
if (!obj->frontbuffer_bits)
return;
frontbuffer_bits = obj->frontbuffer_bits;
if (retire) {
mutex_lock(&dev_priv->fb_tracking.lock);
frontbuffer_bits &= dev_priv->fb_tracking.busy_bits;
dev_priv->fb_tracking.busy_bits &= ~frontbuffer_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
}
intel_frontbuffer_flush(dev, frontbuffer_bits);
}
void intel_frontbuffer_flip_prepare(struct drm_device *dev,
unsigned frontbuffer_bits)
{
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev_priv->fb_tracking.lock);
dev_priv->fb_tracking.flip_bits |= frontbuffer_bits;
dev_priv->fb_tracking.busy_bits &= ~frontbuffer_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
intel_psr_single_frame_update(dev);
}
void intel_frontbuffer_flip_complete(struct drm_device *dev,
unsigned frontbuffer_bits)
{
struct drm_i915_private *dev_priv = dev->dev_private;
mutex_lock(&dev_priv->fb_tracking.lock);
frontbuffer_bits &= dev_priv->fb_tracking.flip_bits;
dev_priv->fb_tracking.flip_bits &= ~frontbuffer_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
intel_frontbuffer_flush(dev, frontbuffer_bits);
}
