void intel_fb_obj_invalidate(struct drm_i915_gem_object *obj,
enum fb_op_origin origin)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
if (!obj->frontbuffer_bits)
return;
if (origin == ORIGIN_CS) {
mutex_lock(&dev_priv->fb_tracking.lock);
dev_priv->fb_tracking.busy_bits
|= obj->frontbuffer_bits;
dev_priv->fb_tracking.flip_bits
&= ~obj->frontbuffer_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
}
intel_psr_invalidate(dev, obj->frontbuffer_bits);
intel_edp_drrs_invalidate(dev, obj->frontbuffer_bits);
intel_fbc_invalidate(dev_priv, obj->frontbuffer_bits, origin);
}
static void intel_frontbuffer_flush(struct drm_device *dev,
unsigned frontbuffer_bits,
enum fb_op_origin origin)
{
struct drm_i915_private *dev_priv = to_i915(dev);
mutex_lock(&dev_priv->fb_tracking.lock);
frontbuffer_bits &= ~dev_priv->fb_tracking.busy_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
if (!frontbuffer_bits)
return;
intel_edp_drrs_flush(dev, frontbuffer_bits);
intel_psr_flush(dev, frontbuffer_bits, origin);
intel_fbc_flush(dev_priv, frontbuffer_bits, origin);
}
void intel_fb_obj_flush(struct drm_i915_gem_object *obj,
bool retire, enum fb_op_origin origin)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
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
intel_frontbuffer_flush(dev, frontbuffer_bits, origin);
}
void intel_frontbuffer_flip_prepare(struct drm_device *dev,
unsigned frontbuffer_bits)
{
struct drm_i915_private *dev_priv = to_i915(dev);
mutex_lock(&dev_priv->fb_tracking.lock);
dev_priv->fb_tracking.flip_bits |= frontbuffer_bits;
dev_priv->fb_tracking.busy_bits &= ~frontbuffer_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
intel_psr_single_frame_update(dev, frontbuffer_bits);
}
void intel_frontbuffer_flip_complete(struct drm_device *dev,
unsigned frontbuffer_bits)
{
struct drm_i915_private *dev_priv = to_i915(dev);
mutex_lock(&dev_priv->fb_tracking.lock);
frontbuffer_bits &= dev_priv->fb_tracking.flip_bits;
dev_priv->fb_tracking.flip_bits &= ~frontbuffer_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
intel_frontbuffer_flush(dev, frontbuffer_bits, ORIGIN_FLIP);
}
void intel_frontbuffer_flip(struct drm_device *dev,
unsigned frontbuffer_bits)
{
struct drm_i915_private *dev_priv = to_i915(dev);
mutex_lock(&dev_priv->fb_tracking.lock);
dev_priv->fb_tracking.busy_bits &= ~frontbuffer_bits;
mutex_unlock(&dev_priv->fb_tracking.lock);
intel_frontbuffer_flush(dev, frontbuffer_bits, ORIGIN_FLIP);
}
