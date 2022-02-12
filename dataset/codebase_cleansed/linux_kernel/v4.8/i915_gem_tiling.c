static bool
i915_tiling_ok(struct drm_device *dev, int stride, int size, int tiling_mode)
{
int tile_width;
if (tiling_mode == I915_TILING_NONE)
return true;
if (IS_GEN2(dev) ||
(tiling_mode == I915_TILING_Y && HAS_128_BYTE_Y_TILING(dev)))
tile_width = 128;
else
tile_width = 512;
if (INTEL_INFO(dev)->gen >= 7) {
if (stride / 128 > GEN7_FENCE_MAX_PITCH_VAL)
return false;
} else if (INTEL_INFO(dev)->gen >= 4) {
if (stride / 128 > I965_FENCE_MAX_PITCH_VAL)
return false;
} else {
if (stride > 8192)
return false;
if (IS_GEN3(dev)) {
if (size > I830_FENCE_MAX_SIZE_VAL << 20)
return false;
} else {
if (size > I830_FENCE_MAX_SIZE_VAL << 19)
return false;
}
}
if (stride < tile_width)
return false;
if (INTEL_INFO(dev)->gen >= 4) {
if (stride & (tile_width - 1))
return false;
return true;
}
if (stride & (stride - 1))
return false;
return true;
}
static bool
i915_gem_object_fence_ok(struct drm_i915_gem_object *obj, int tiling_mode)
{
u32 size;
if (tiling_mode == I915_TILING_NONE)
return true;
if (INTEL_INFO(obj->base.dev)->gen >= 4)
return true;
if (IS_GEN3(obj->base.dev)) {
if (i915_gem_obj_ggtt_offset(obj) & ~I915_FENCE_START_MASK)
return false;
} else {
if (i915_gem_obj_ggtt_offset(obj) & ~I830_FENCE_START_MASK)
return false;
}
size = i915_gem_get_gtt_size(obj->base.dev, obj->base.size, tiling_mode);
if (i915_gem_obj_ggtt_size(obj) != size)
return false;
if (i915_gem_obj_ggtt_offset(obj) & (size - 1))
return false;
return true;
}
int
i915_gem_set_tiling(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_set_tiling *args = data;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_object *obj;
int ret = 0;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL)
return -ENOENT;
if (!i915_tiling_ok(dev,
args->stride, obj->base.size, args->tiling_mode)) {
drm_gem_object_unreference_unlocked(&obj->base);
return -EINVAL;
}
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev->struct_mutex);
if (obj->pin_display || obj->framebuffer_references) {
ret = -EBUSY;
goto err;
}
if (args->tiling_mode == I915_TILING_NONE) {
args->swizzle_mode = I915_BIT_6_SWIZZLE_NONE;
args->stride = 0;
} else {
if (args->tiling_mode == I915_TILING_X)
args->swizzle_mode = dev_priv->mm.bit_6_swizzle_x;
else
args->swizzle_mode = dev_priv->mm.bit_6_swizzle_y;
if (args->swizzle_mode == I915_BIT_6_SWIZZLE_9_17)
args->swizzle_mode = I915_BIT_6_SWIZZLE_9;
if (args->swizzle_mode == I915_BIT_6_SWIZZLE_9_10_17)
args->swizzle_mode = I915_BIT_6_SWIZZLE_9_10;
if (args->swizzle_mode == I915_BIT_6_SWIZZLE_UNKNOWN) {
args->tiling_mode = I915_TILING_NONE;
args->swizzle_mode = I915_BIT_6_SWIZZLE_NONE;
args->stride = 0;
}
}
if (args->tiling_mode != obj->tiling_mode ||
args->stride != obj->stride) {
if (obj->map_and_fenceable &&
!i915_gem_object_fence_ok(obj, args->tiling_mode))
ret = i915_vma_unbind(i915_gem_obj_to_ggtt(obj));
if (ret == 0) {
if (obj->pages &&
obj->madv == I915_MADV_WILLNEED &&
dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES) {
if (args->tiling_mode == I915_TILING_NONE)
i915_gem_object_unpin_pages(obj);
if (obj->tiling_mode == I915_TILING_NONE)
i915_gem_object_pin_pages(obj);
}
obj->fence_dirty =
obj->last_fenced_req ||
obj->fence_reg != I915_FENCE_REG_NONE;
obj->tiling_mode = args->tiling_mode;
obj->stride = args->stride;
i915_gem_release_mmap(obj);
}
}
args->stride = obj->stride;
args->tiling_mode = obj->tiling_mode;
if (i915_gem_object_needs_bit17_swizzle(obj)) {
if (obj->bit_17 == NULL) {
obj->bit_17 = kcalloc(BITS_TO_LONGS(obj->base.size >> PAGE_SHIFT),
sizeof(long), GFP_KERNEL);
}
} else {
kfree(obj->bit_17);
obj->bit_17 = NULL;
}
err:
drm_gem_object_unreference(&obj->base);
mutex_unlock(&dev->struct_mutex);
intel_runtime_pm_put(dev_priv);
return ret;
}
int
i915_gem_get_tiling(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_get_tiling *args = data;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_object *obj;
obj = to_intel_bo(drm_gem_object_lookup(file, args->handle));
if (&obj->base == NULL)
return -ENOENT;
mutex_lock(&dev->struct_mutex);
args->tiling_mode = obj->tiling_mode;
switch (obj->tiling_mode) {
case I915_TILING_X:
args->swizzle_mode = dev_priv->mm.bit_6_swizzle_x;
break;
case I915_TILING_Y:
args->swizzle_mode = dev_priv->mm.bit_6_swizzle_y;
break;
case I915_TILING_NONE:
args->swizzle_mode = I915_BIT_6_SWIZZLE_NONE;
break;
default:
DRM_ERROR("unknown tiling mode\n");
}
if (dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES)
args->phys_swizzle_mode = I915_BIT_6_SWIZZLE_UNKNOWN;
else
args->phys_swizzle_mode = args->swizzle_mode;
if (args->swizzle_mode == I915_BIT_6_SWIZZLE_9_17)
args->swizzle_mode = I915_BIT_6_SWIZZLE_9;
if (args->swizzle_mode == I915_BIT_6_SWIZZLE_9_10_17)
args->swizzle_mode = I915_BIT_6_SWIZZLE_9_10;
drm_gem_object_unreference(&obj->base);
mutex_unlock(&dev->struct_mutex);
return 0;
}
