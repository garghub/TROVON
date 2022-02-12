static void i965_write_fence_reg(struct drm_i915_fence_reg *fence,
struct i915_vma *vma)
{
i915_reg_t fence_reg_lo, fence_reg_hi;
int fence_pitch_shift;
u64 val;
if (INTEL_INFO(fence->i915)->gen >= 6) {
fence_reg_lo = FENCE_REG_GEN6_LO(fence->id);
fence_reg_hi = FENCE_REG_GEN6_HI(fence->id);
fence_pitch_shift = GEN6_FENCE_PITCH_SHIFT;
} else {
fence_reg_lo = FENCE_REG_965_LO(fence->id);
fence_reg_hi = FENCE_REG_965_HI(fence->id);
fence_pitch_shift = I965_FENCE_PITCH_SHIFT;
}
val = 0;
if (vma) {
unsigned int tiling = i915_gem_object_get_tiling(vma->obj);
bool is_y_tiled = tiling == I915_TILING_Y;
unsigned int stride = i915_gem_object_get_stride(vma->obj);
u32 row_size = stride * (is_y_tiled ? 32 : 8);
u32 size = rounddown((u32)vma->node.size, row_size);
val = ((vma->node.start + size - 4096) & 0xfffff000) << 32;
val |= vma->node.start & 0xfffff000;
val |= (u64)((stride / 128) - 1) << fence_pitch_shift;
if (is_y_tiled)
val |= BIT(I965_FENCE_TILING_Y_SHIFT);
val |= I965_FENCE_REG_VALID;
}
if (!pipelined) {
struct drm_i915_private *dev_priv = fence->i915;
I915_WRITE(fence_reg_lo, 0);
POSTING_READ(fence_reg_lo);
I915_WRITE(fence_reg_hi, upper_32_bits(val));
I915_WRITE(fence_reg_lo, lower_32_bits(val));
POSTING_READ(fence_reg_lo);
}
}
static void i915_write_fence_reg(struct drm_i915_fence_reg *fence,
struct i915_vma *vma)
{
u32 val;
val = 0;
if (vma) {
unsigned int tiling = i915_gem_object_get_tiling(vma->obj);
bool is_y_tiled = tiling == I915_TILING_Y;
unsigned int stride = i915_gem_object_get_stride(vma->obj);
int pitch_val;
int tile_width;
WARN((vma->node.start & ~I915_FENCE_START_MASK) ||
!is_power_of_2(vma->node.size) ||
(vma->node.start & (vma->node.size - 1)),
"object 0x%08llx [fenceable? %d] not 1M or pot-size (0x%08llx) aligned\n",
vma->node.start,
i915_vma_is_map_and_fenceable(vma),
vma->node.size);
if (is_y_tiled && HAS_128_BYTE_Y_TILING(fence->i915))
tile_width = 128;
else
tile_width = 512;
pitch_val = stride / tile_width;
pitch_val = ffs(pitch_val) - 1;
val = vma->node.start;
if (is_y_tiled)
val |= BIT(I830_FENCE_TILING_Y_SHIFT);
val |= I915_FENCE_SIZE_BITS(vma->node.size);
val |= pitch_val << I830_FENCE_PITCH_SHIFT;
val |= I830_FENCE_REG_VALID;
}
if (!pipelined) {
struct drm_i915_private *dev_priv = fence->i915;
i915_reg_t reg = FENCE_REG(fence->id);
I915_WRITE(reg, val);
POSTING_READ(reg);
}
}
static void i830_write_fence_reg(struct drm_i915_fence_reg *fence,
struct i915_vma *vma)
{
u32 val;
val = 0;
if (vma) {
unsigned int tiling = i915_gem_object_get_tiling(vma->obj);
bool is_y_tiled = tiling == I915_TILING_Y;
unsigned int stride = i915_gem_object_get_stride(vma->obj);
u32 pitch_val;
WARN((vma->node.start & ~I830_FENCE_START_MASK) ||
!is_power_of_2(vma->node.size) ||
(vma->node.start & (vma->node.size - 1)),
"object 0x%08llx not 512K or pot-size 0x%08llx aligned\n",
vma->node.start, vma->node.size);
pitch_val = stride / 128;
pitch_val = ffs(pitch_val) - 1;
val = vma->node.start;
if (is_y_tiled)
val |= BIT(I830_FENCE_TILING_Y_SHIFT);
val |= I830_FENCE_SIZE_BITS(vma->node.size);
val |= pitch_val << I830_FENCE_PITCH_SHIFT;
val |= I830_FENCE_REG_VALID;
}
if (!pipelined) {
struct drm_i915_private *dev_priv = fence->i915;
i915_reg_t reg = FENCE_REG(fence->id);
I915_WRITE(reg, val);
POSTING_READ(reg);
}
}
static void fence_write(struct drm_i915_fence_reg *fence,
struct i915_vma *vma)
{
if (IS_GEN2(fence->i915))
i830_write_fence_reg(fence, vma);
else if (IS_GEN3(fence->i915))
i915_write_fence_reg(fence, vma);
else
i965_write_fence_reg(fence, vma);
fence->dirty = false;
}
static int fence_update(struct drm_i915_fence_reg *fence,
struct i915_vma *vma)
{
int ret;
if (vma) {
if (!i915_vma_is_map_and_fenceable(vma))
return -EINVAL;
if (WARN(!i915_gem_object_get_stride(vma->obj) ||
!i915_gem_object_get_tiling(vma->obj),
"bogus fence setup with stride: 0x%x, tiling mode: %i\n",
i915_gem_object_get_stride(vma->obj),
i915_gem_object_get_tiling(vma->obj)))
return -EINVAL;
ret = i915_gem_active_retire(&vma->last_fence,
&vma->obj->base.dev->struct_mutex);
if (ret)
return ret;
}
if (fence->vma) {
ret = i915_gem_active_retire(&fence->vma->last_fence,
&fence->vma->obj->base.dev->struct_mutex);
if (ret)
return ret;
}
if (fence->vma && fence->vma != vma) {
i915_gem_release_mmap(fence->vma->obj);
fence->vma->fence = NULL;
fence->vma = NULL;
list_move(&fence->link, &fence->i915->mm.fence_list);
}
fence_write(fence, vma);
if (vma) {
if (fence->vma != vma) {
vma->fence = fence;
fence->vma = vma;
}
list_move_tail(&fence->link, &fence->i915->mm.fence_list);
}
return 0;
}
int
i915_vma_put_fence(struct i915_vma *vma)
{
struct drm_i915_fence_reg *fence = vma->fence;
assert_rpm_wakelock_held(to_i915(vma->vm->dev));
if (!fence)
return 0;
if (fence->pin_count)
return -EBUSY;
return fence_update(fence, NULL);
}
static struct drm_i915_fence_reg *fence_find(struct drm_i915_private *dev_priv)
{
struct drm_i915_fence_reg *fence;
list_for_each_entry(fence, &dev_priv->mm.fence_list, link) {
if (fence->pin_count)
continue;
return fence;
}
if (intel_has_pending_fb_unpin(&dev_priv->drm))
return ERR_PTR(-EAGAIN);
return ERR_PTR(-EDEADLK);
}
int
i915_vma_get_fence(struct i915_vma *vma)
{
struct drm_i915_fence_reg *fence;
struct i915_vma *set = i915_gem_object_is_tiled(vma->obj) ? vma : NULL;
assert_rpm_wakelock_held(to_i915(vma->vm->dev));
if (vma->fence) {
fence = vma->fence;
if (!fence->dirty) {
list_move_tail(&fence->link,
&fence->i915->mm.fence_list);
return 0;
}
} else if (set) {
fence = fence_find(to_i915(vma->vm->dev));
if (IS_ERR(fence))
return PTR_ERR(fence);
} else
return 0;
return fence_update(fence, set);
}
void i915_gem_restore_fences(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int i;
for (i = 0; i < dev_priv->num_fence_regs; i++) {
struct drm_i915_fence_reg *reg = &dev_priv->fence_regs[i];
struct i915_vma *vma = reg->vma;
if (vma && !i915_gem_object_is_tiled(vma->obj)) {
GEM_BUG_ON(!reg->dirty);
GEM_BUG_ON(vma->obj->fault_mappable);
list_move(&reg->link, &dev_priv->mm.fence_list);
vma->fence = NULL;
vma = NULL;
}
fence_write(reg, vma);
reg->vma = vma;
}
}
void
i915_gem_detect_bit_6_swizzle(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t swizzle_x = I915_BIT_6_SWIZZLE_UNKNOWN;
uint32_t swizzle_y = I915_BIT_6_SWIZZLE_UNKNOWN;
if (INTEL_INFO(dev)->gen >= 8 || IS_VALLEYVIEW(dev)) {
swizzle_x = I915_BIT_6_SWIZZLE_NONE;
swizzle_y = I915_BIT_6_SWIZZLE_NONE;
} else if (INTEL_INFO(dev)->gen >= 6) {
if (dev_priv->preserve_bios_swizzle) {
if (I915_READ(DISP_ARB_CTL) &
DISP_TILE_SURFACE_SWIZZLING) {
swizzle_x = I915_BIT_6_SWIZZLE_9_10;
swizzle_y = I915_BIT_6_SWIZZLE_9;
} else {
swizzle_x = I915_BIT_6_SWIZZLE_NONE;
swizzle_y = I915_BIT_6_SWIZZLE_NONE;
}
} else {
uint32_t dimm_c0, dimm_c1;
dimm_c0 = I915_READ(MAD_DIMM_C0);
dimm_c1 = I915_READ(MAD_DIMM_C1);
dimm_c0 &= MAD_DIMM_A_SIZE_MASK | MAD_DIMM_B_SIZE_MASK;
dimm_c1 &= MAD_DIMM_A_SIZE_MASK | MAD_DIMM_B_SIZE_MASK;
if (dimm_c0 == dimm_c1) {
swizzle_x = I915_BIT_6_SWIZZLE_9_10;
swizzle_y = I915_BIT_6_SWIZZLE_9;
} else {
swizzle_x = I915_BIT_6_SWIZZLE_NONE;
swizzle_y = I915_BIT_6_SWIZZLE_NONE;
}
}
} else if (IS_GEN5(dev)) {
swizzle_x = I915_BIT_6_SWIZZLE_9_10;
swizzle_y = I915_BIT_6_SWIZZLE_9;
} else if (IS_GEN2(dev)) {
swizzle_x = I915_BIT_6_SWIZZLE_NONE;
swizzle_y = I915_BIT_6_SWIZZLE_NONE;
} else if (IS_MOBILE(dev) || (IS_GEN3(dev) && !IS_G33(dev))) {
uint32_t dcc;
dcc = I915_READ(DCC);
switch (dcc & DCC_ADDRESSING_MODE_MASK) {
case DCC_ADDRESSING_MODE_SINGLE_CHANNEL:
case DCC_ADDRESSING_MODE_DUAL_CHANNEL_ASYMMETRIC:
swizzle_x = I915_BIT_6_SWIZZLE_NONE;
swizzle_y = I915_BIT_6_SWIZZLE_NONE;
break;
case DCC_ADDRESSING_MODE_DUAL_CHANNEL_INTERLEAVED:
if (dcc & DCC_CHANNEL_XOR_DISABLE) {
swizzle_x = I915_BIT_6_SWIZZLE_9_10;
swizzle_y = I915_BIT_6_SWIZZLE_9;
} else if ((dcc & DCC_CHANNEL_XOR_BIT_17) == 0) {
swizzle_x = I915_BIT_6_SWIZZLE_9_10_11;
swizzle_y = I915_BIT_6_SWIZZLE_9_11;
} else {
swizzle_x = I915_BIT_6_SWIZZLE_9_10_17;
swizzle_y = I915_BIT_6_SWIZZLE_9_17;
}
break;
}
if (IS_GEN4(dev) &&
!(I915_READ(DCC2) & DCC2_MODIFIED_ENHANCED_DISABLE)) {
swizzle_x = I915_BIT_6_SWIZZLE_UNKNOWN;
swizzle_y = I915_BIT_6_SWIZZLE_UNKNOWN;
}
if (dcc == 0xffffffff) {
DRM_ERROR("Couldn't read from MCHBAR. "
"Disabling tiling.\n");
swizzle_x = I915_BIT_6_SWIZZLE_UNKNOWN;
swizzle_y = I915_BIT_6_SWIZZLE_UNKNOWN;
}
} else {
if (I915_READ16(C0DRB3) == I915_READ16(C1DRB3)) {
swizzle_x = I915_BIT_6_SWIZZLE_9_10;
swizzle_y = I915_BIT_6_SWIZZLE_9;
}
}
if (swizzle_x == I915_BIT_6_SWIZZLE_UNKNOWN ||
swizzle_y == I915_BIT_6_SWIZZLE_UNKNOWN) {
dev_priv->quirks |= QUIRK_PIN_SWIZZLED_PAGES;
swizzle_x = I915_BIT_6_SWIZZLE_NONE;
swizzle_y = I915_BIT_6_SWIZZLE_NONE;
}
dev_priv->mm.bit_6_swizzle_x = swizzle_x;
dev_priv->mm.bit_6_swizzle_y = swizzle_y;
}
static void
i915_gem_swizzle_page(struct page *page)
{
char temp[64];
char *vaddr;
int i;
vaddr = kmap(page);
for (i = 0; i < PAGE_SIZE; i += 128) {
memcpy(temp, &vaddr[i], 64);
memcpy(&vaddr[i], &vaddr[i + 64], 64);
memcpy(&vaddr[i + 64], temp, 64);
}
kunmap(page);
}
void
i915_gem_object_do_bit_17_swizzle(struct drm_i915_gem_object *obj)
{
struct sgt_iter sgt_iter;
struct page *page;
int i;
if (obj->bit_17 == NULL)
return;
i = 0;
for_each_sgt_page(page, sgt_iter, obj->pages) {
char new_bit_17 = page_to_phys(page) >> 17;
if ((new_bit_17 & 0x1) !=
(test_bit(i, obj->bit_17) != 0)) {
i915_gem_swizzle_page(page);
set_page_dirty(page);
}
i++;
}
}
void
i915_gem_object_save_bit_17_swizzle(struct drm_i915_gem_object *obj)
{
struct sgt_iter sgt_iter;
struct page *page;
int page_count = obj->base.size >> PAGE_SHIFT;
int i;
if (obj->bit_17 == NULL) {
obj->bit_17 = kcalloc(BITS_TO_LONGS(page_count),
sizeof(long), GFP_KERNEL);
if (obj->bit_17 == NULL) {
DRM_ERROR("Failed to allocate memory for bit 17 "
"record\n");
return;
}
}
i = 0;
for_each_sgt_page(page, sgt_iter, obj->pages) {
if (page_to_phys(page) & (1 << 17))
__set_bit(i, obj->bit_17);
else
__clear_bit(i, obj->bit_17);
i++;
}
}
