void __intel_fb_obj_invalidate(struct drm_i915_gem_object *obj,
enum fb_op_origin origin,
unsigned int frontbuffer_bits)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
if (origin == ORIGIN_CS) {
spin_lock(&dev_priv->fb_tracking.lock);
dev_priv->fb_tracking.busy_bits |= frontbuffer_bits;
dev_priv->fb_tracking.flip_bits &= ~frontbuffer_bits;
spin_unlock(&dev_priv->fb_tracking.lock);
}
intel_psr_invalidate(dev_priv, frontbuffer_bits);
intel_edp_drrs_invalidate(dev_priv, frontbuffer_bits);
intel_fbc_invalidate(dev_priv, frontbuffer_bits, origin);
}
static void intel_frontbuffer_flush(struct drm_i915_private *dev_priv,
unsigned frontbuffer_bits,
enum fb_op_origin origin)
{
spin_lock(&dev_priv->fb_tracking.lock);
frontbuffer_bits &= ~dev_priv->fb_tracking.busy_bits;
spin_unlock(&dev_priv->fb_tracking.lock);
if (!frontbuffer_bits)
return;
intel_edp_drrs_flush(dev_priv, frontbuffer_bits);
intel_psr_flush(dev_priv, frontbuffer_bits, origin);
intel_fbc_flush(dev_priv, frontbuffer_bits, origin);
}
void __intel_fb_obj_flush(struct drm_i915_gem_object *obj,
enum fb_op_origin origin,
unsigned int frontbuffer_bits)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
if (origin == ORIGIN_CS) {
spin_lock(&dev_priv->fb_tracking.lock);
frontbuffer_bits &= dev_priv->fb_tracking.busy_bits;
dev_priv->fb_tracking.busy_bits &= ~frontbuffer_bits;
spin_unlock(&dev_priv->fb_tracking.lock);
}
if (frontbuffer_bits)
intel_frontbuffer_flush(dev_priv, frontbuffer_bits, origin);
}
void intel_frontbuffer_flip_prepare(struct drm_i915_private *dev_priv,
unsigned frontbuffer_bits)
{
spin_lock(&dev_priv->fb_tracking.lock);
dev_priv->fb_tracking.flip_bits |= frontbuffer_bits;
dev_priv->fb_tracking.busy_bits &= ~frontbuffer_bits;
spin_unlock(&dev_priv->fb_tracking.lock);
intel_psr_single_frame_update(dev_priv, frontbuffer_bits);
}
void intel_frontbuffer_flip_complete(struct drm_i915_private *dev_priv,
unsigned frontbuffer_bits)
{
spin_lock(&dev_priv->fb_tracking.lock);
frontbuffer_bits &= dev_priv->fb_tracking.flip_bits;
dev_priv->fb_tracking.flip_bits &= ~frontbuffer_bits;
spin_unlock(&dev_priv->fb_tracking.lock);
if (frontbuffer_bits)
intel_frontbuffer_flush(dev_priv,
frontbuffer_bits, ORIGIN_FLIP);
}
void intel_frontbuffer_flip(struct drm_i915_private *dev_priv,
unsigned frontbuffer_bits)
{
spin_lock(&dev_priv->fb_tracking.lock);
dev_priv->fb_tracking.busy_bits &= ~frontbuffer_bits;
spin_unlock(&dev_priv->fb_tracking.lock);
intel_frontbuffer_flush(dev_priv, frontbuffer_bits, ORIGIN_FLIP);
}
