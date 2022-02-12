u32 i915_gem_fence_size(struct drm_i915_private *i915,
u32 size, unsigned int tiling, unsigned int stride)
{
u32 ggtt_size;
GEM_BUG_ON(!size);
if (tiling == I915_TILING_NONE)
return size;
GEM_BUG_ON(!stride);
if (INTEL_GEN(i915) >= 4) {
stride *= i915_gem_tile_height(tiling);
GEM_BUG_ON(!IS_ALIGNED(stride, I965_FENCE_PAGE));
return roundup(size, stride);
}
if (IS_GEN3(i915))
ggtt_size = 1024*1024;
else
ggtt_size = 512*1024;
while (ggtt_size < size)
ggtt_size <<= 1;
return ggtt_size;
}
u32 i915_gem_fence_alignment(struct drm_i915_private *i915, u32 size,
unsigned int tiling, unsigned int stride)
{
GEM_BUG_ON(!size);
if (tiling == I915_TILING_NONE)
return I915_GTT_MIN_ALIGNMENT;
if (INTEL_GEN(i915) >= 4)
return I965_FENCE_PAGE;
return i915_gem_fence_size(i915, size, tiling, stride);
}
static bool
i915_tiling_ok(struct drm_i915_gem_object *obj,
unsigned int tiling, unsigned int stride)
{
struct drm_i915_private *i915 = to_i915(obj->base.dev);
unsigned int tile_width;
if (tiling == I915_TILING_NONE)
return true;
if (tiling > I915_TILING_LAST)
return false;
if (INTEL_GEN(i915) >= 7) {
if (stride / 128 > GEN7_FENCE_MAX_PITCH_VAL)
return false;
} else if (INTEL_GEN(i915) >= 4) {
if (stride / 128 > I965_FENCE_MAX_PITCH_VAL)
return false;
} else {
if (stride > 8192)
return false;
if (!is_power_of_2(stride))
return false;
}
if (IS_GEN2(i915) ||
(tiling == I915_TILING_Y && HAS_128_BYTE_Y_TILING(i915)))
tile_width = 128;
else
tile_width = 512;
if (!stride || !IS_ALIGNED(stride, tile_width))
return false;
return true;
}
static bool i915_vma_fence_prepare(struct i915_vma *vma,
int tiling_mode, unsigned int stride)
{
struct drm_i915_private *i915 = vma->vm->i915;
u32 size, alignment;
if (!i915_vma_is_map_and_fenceable(vma))
return true;
size = i915_gem_fence_size(i915, vma->size, tiling_mode, stride);
if (vma->node.size < size)
return false;
alignment = i915_gem_fence_alignment(i915, vma->size, tiling_mode, stride);
if (!IS_ALIGNED(vma->node.start, alignment))
return false;
return true;
}
static int
i915_gem_object_fence_prepare(struct drm_i915_gem_object *obj,
int tiling_mode, unsigned int stride)
{
struct i915_vma *vma;
int ret;
if (tiling_mode == I915_TILING_NONE)
return 0;
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (!i915_vma_is_ggtt(vma))
break;
if (i915_vma_fence_prepare(vma, tiling_mode, stride))
continue;
ret = i915_vma_unbind(vma);
if (ret)
return ret;
}
return 0;
}
int
i915_gem_object_set_tiling(struct drm_i915_gem_object *obj,
unsigned int tiling, unsigned int stride)
{
struct drm_i915_private *i915 = to_i915(obj->base.dev);
struct i915_vma *vma;
int err;
BUILD_BUG_ON(I915_TILING_LAST & STRIDE_MASK);
GEM_BUG_ON(!i915_tiling_ok(obj, tiling, stride));
GEM_BUG_ON(!stride ^ (tiling == I915_TILING_NONE));
lockdep_assert_held(&i915->drm.struct_mutex);
if ((tiling | stride) == obj->tiling_and_stride)
return 0;
if (i915_gem_object_is_framebuffer(obj))
return -EBUSY;
err = i915_gem_object_fence_prepare(obj, tiling, stride);
if (err)
return err;
i915_gem_object_lock(obj);
if (i915_gem_object_is_framebuffer(obj)) {
i915_gem_object_unlock(obj);
return -EBUSY;
}
mutex_lock(&obj->mm.lock);
if (obj->mm.pages &&
obj->mm.madv == I915_MADV_WILLNEED &&
i915->quirks & QUIRK_PIN_SWIZZLED_PAGES) {
if (tiling == I915_TILING_NONE) {
GEM_BUG_ON(!obj->mm.quirked);
__i915_gem_object_unpin_pages(obj);
obj->mm.quirked = false;
}
if (!i915_gem_object_is_tiled(obj)) {
GEM_BUG_ON(obj->mm.quirked);
__i915_gem_object_pin_pages(obj);
obj->mm.quirked = true;
}
}
mutex_unlock(&obj->mm.lock);
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (!i915_vma_is_ggtt(vma))
break;
vma->fence_size =
i915_gem_fence_size(i915, vma->size, tiling, stride);
vma->fence_alignment =
i915_gem_fence_alignment(i915,
vma->size, tiling, stride);
if (vma->fence)
vma->fence->dirty = true;
}
obj->tiling_and_stride = tiling | stride;
i915_gem_object_unlock(obj);
i915_gem_release_mmap(obj);
if (i915_gem_object_needs_bit17_swizzle(obj)) {
if (!obj->bit_17) {
obj->bit_17 = kcalloc(BITS_TO_LONGS(obj->base.size >> PAGE_SHIFT),
sizeof(long), GFP_KERNEL);
}
} else {
kfree(obj->bit_17);
obj->bit_17 = NULL;
}
return 0;
}
int
i915_gem_set_tiling_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_set_tiling *args = data;
struct drm_i915_gem_object *obj;
int err;
obj = i915_gem_object_lookup(file, args->handle);
if (!obj)
return -ENOENT;
if (!i915_tiling_ok(obj, args->tiling_mode, args->stride)) {
err = -EINVAL;
goto err;
}
if (args->tiling_mode == I915_TILING_NONE) {
args->swizzle_mode = I915_BIT_6_SWIZZLE_NONE;
args->stride = 0;
} else {
if (args->tiling_mode == I915_TILING_X)
args->swizzle_mode = to_i915(dev)->mm.bit_6_swizzle_x;
else
args->swizzle_mode = to_i915(dev)->mm.bit_6_swizzle_y;
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
err = mutex_lock_interruptible(&dev->struct_mutex);
if (err)
goto err;
err = i915_gem_object_set_tiling(obj, args->tiling_mode, args->stride);
mutex_unlock(&dev->struct_mutex);
args->stride = i915_gem_object_get_stride(obj);
args->tiling_mode = i915_gem_object_get_tiling(obj);
err:
i915_gem_object_put(obj);
return err;
}
int
i915_gem_get_tiling_ioctl(struct drm_device *dev, void *data,
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
