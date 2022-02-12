static bool
i915_tiling_ok(struct drm_i915_private *dev_priv,
int stride, int size, int tiling_mode)
{
int tile_width;
if (tiling_mode == I915_TILING_NONE)
return true;
if (tiling_mode > I915_TILING_LAST)
return false;
if (IS_GEN2(dev_priv) ||
(tiling_mode == I915_TILING_Y && HAS_128_BYTE_Y_TILING(dev_priv)))
tile_width = 128;
else
tile_width = 512;
if (INTEL_GEN(dev_priv) >= 7) {
if (stride / 128 > GEN7_FENCE_MAX_PITCH_VAL)
return false;
} else if (INTEL_GEN(dev_priv) >= 4) {
if (stride / 128 > I965_FENCE_MAX_PITCH_VAL)
return false;
} else {
if (stride > 8192)
return false;
if (IS_GEN3(dev_priv)) {
if (size > I830_FENCE_MAX_SIZE_VAL << 20)
return false;
} else {
if (size > I830_FENCE_MAX_SIZE_VAL << 19)
return false;
}
}
if (stride < tile_width)
return false;
if (INTEL_GEN(dev_priv) >= 4) {
if (stride & (tile_width - 1))
return false;
return true;
}
if (stride & (stride - 1))
return false;
return true;
}
static bool i915_vma_fence_prepare(struct i915_vma *vma, int tiling_mode)
{
struct drm_i915_private *dev_priv = to_i915(vma->vm->dev);
u32 size;
if (!i915_vma_is_map_and_fenceable(vma))
return true;
if (INTEL_GEN(dev_priv) == 3) {
if (vma->node.start & ~I915_FENCE_START_MASK)
return false;
} else {
if (vma->node.start & ~I830_FENCE_START_MASK)
return false;
}
size = i915_gem_get_ggtt_size(dev_priv, vma->size, tiling_mode);
if (vma->node.size < size)
return false;
if (vma->node.start & (size - 1))
return false;
return true;
}
static int
i915_gem_object_fence_prepare(struct drm_i915_gem_object *obj, int tiling_mode)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
struct i915_vma *vma;
int ret;
if (tiling_mode == I915_TILING_NONE)
return 0;
if (INTEL_GEN(dev_priv) >= 4)
return 0;
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (i915_vma_fence_prepare(vma, tiling_mode))
continue;
ret = i915_vma_unbind(vma);
if (ret)
return ret;
}
return 0;
}
int
i915_gem_set_tiling(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_set_tiling *args = data;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_object *obj;
int err = 0;
BUILD_BUG_ON(I915_TILING_LAST & STRIDE_MASK);
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
if (!i915_tiling_ok(dev_priv,
args->stride, obj->base.size, args->tiling_mode)) {
i915_gem_object_put(obj);
return -EINVAL;
}
mutex_lock(&dev->struct_mutex);
if (obj->pin_display || obj->framebuffer_references) {
err = -EBUSY;
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
if (args->tiling_mode != i915_gem_object_get_tiling(obj) ||
args->stride != i915_gem_object_get_stride(obj)) {
err = i915_gem_object_fence_prepare(obj, args->tiling_mode);
if (!err) {
struct i915_vma *vma;
mutex_lock(&obj->mm.lock);
if (obj->mm.pages &&
obj->mm.madv == I915_MADV_WILLNEED &&
dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES) {
if (args->tiling_mode == I915_TILING_NONE) {
GEM_BUG_ON(!obj->mm.quirked);
__i915_gem_object_unpin_pages(obj);
obj->mm.quirked = false;
}
if (!i915_gem_object_is_tiled(obj)) {
GEM_BUG_ON(!obj->mm.quirked);
__i915_gem_object_pin_pages(obj);
obj->mm.quirked = true;
}
}
mutex_unlock(&obj->mm.lock);
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (!vma->fence)
continue;
vma->fence->dirty = true;
}
obj->tiling_and_stride =
args->stride | args->tiling_mode;
i915_gem_release_mmap(obj);
}
}
args->stride = i915_gem_object_get_stride(obj);
args->tiling_mode = i915_gem_object_get_tiling(obj);
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
i915_gem_object_put(obj);
mutex_unlock(&dev->struct_mutex);
return err;
}
int
i915_gem_get_tiling(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_get_tiling *args = data;
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_object *obj;
int err = -ENOENT;
rcu_read_lock();
obj = i915_gem_object_lookup_rcu(file, args->handle);
if (obj) {
args->tiling_mode =
READ_ONCE(obj->tiling_and_stride) & TILING_MASK;
err = 0;
}
rcu_read_unlock();
if (unlikely(err))
return err;
switch (args->tiling_mode) {
case I915_TILING_X:
args->swizzle_mode = dev_priv->mm.bit_6_swizzle_x;
break;
case I915_TILING_Y:
args->swizzle_mode = dev_priv->mm.bit_6_swizzle_y;
break;
default:
case I915_TILING_NONE:
args->swizzle_mode = I915_BIT_6_SWIZZLE_NONE;
break;
}
if (dev_priv->quirks & QUIRK_PIN_SWIZZLED_PAGES)
args->phys_swizzle_mode = I915_BIT_6_SWIZZLE_UNKNOWN;
else
args->phys_swizzle_mode = args->swizzle_mode;
if (args->swizzle_mode == I915_BIT_6_SWIZZLE_9_17)
args->swizzle_mode = I915_BIT_6_SWIZZLE_9;
if (args->swizzle_mode == I915_BIT_6_SWIZZLE_9_10_17)
args->swizzle_mode = I915_BIT_6_SWIZZLE_9_10;
return 0;
}
