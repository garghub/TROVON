static void i965_write_fence_reg(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(dev);
i915_reg_t fence_reg_lo, fence_reg_hi;
int fence_pitch_shift;
if (INTEL_INFO(dev)->gen >= 6) {
fence_reg_lo = FENCE_REG_GEN6_LO(reg);
fence_reg_hi = FENCE_REG_GEN6_HI(reg);
fence_pitch_shift = GEN6_FENCE_PITCH_SHIFT;
} else {
fence_reg_lo = FENCE_REG_965_LO(reg);
fence_reg_hi = FENCE_REG_965_HI(reg);
fence_pitch_shift = I965_FENCE_PITCH_SHIFT;
}
I915_WRITE(fence_reg_lo, 0);
POSTING_READ(fence_reg_lo);
if (obj) {
u32 size = i915_gem_obj_ggtt_size(obj);
uint64_t val;
if (obj->tiling_mode != I915_TILING_NONE) {
uint32_t row_size = obj->stride *
(obj->tiling_mode == I915_TILING_Y ? 32 : 8);
size = (size / row_size) * row_size;
}
val = (uint64_t)((i915_gem_obj_ggtt_offset(obj) + size - 4096) &
0xfffff000) << 32;
val |= i915_gem_obj_ggtt_offset(obj) & 0xfffff000;
val |= (uint64_t)((obj->stride / 128) - 1) << fence_pitch_shift;
if (obj->tiling_mode == I915_TILING_Y)
val |= 1 << I965_FENCE_TILING_Y_SHIFT;
val |= I965_FENCE_REG_VALID;
I915_WRITE(fence_reg_hi, val >> 32);
POSTING_READ(fence_reg_hi);
I915_WRITE(fence_reg_lo, val);
POSTING_READ(fence_reg_lo);
} else {
I915_WRITE(fence_reg_hi, 0);
POSTING_READ(fence_reg_hi);
}
}
static void i915_write_fence_reg(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(dev);
u32 val;
if (obj) {
u32 size = i915_gem_obj_ggtt_size(obj);
int pitch_val;
int tile_width;
WARN((i915_gem_obj_ggtt_offset(obj) & ~I915_FENCE_START_MASK) ||
(size & -size) != size ||
(i915_gem_obj_ggtt_offset(obj) & (size - 1)),
"object 0x%08llx [fenceable? %d] not 1M or pot-size (0x%08x) aligned\n",
i915_gem_obj_ggtt_offset(obj), obj->map_and_fenceable, size);
if (obj->tiling_mode == I915_TILING_Y && HAS_128_BYTE_Y_TILING(dev))
tile_width = 128;
else
tile_width = 512;
pitch_val = obj->stride / tile_width;
pitch_val = ffs(pitch_val) - 1;
val = i915_gem_obj_ggtt_offset(obj);
if (obj->tiling_mode == I915_TILING_Y)
val |= 1 << I830_FENCE_TILING_Y_SHIFT;
val |= I915_FENCE_SIZE_BITS(size);
val |= pitch_val << I830_FENCE_PITCH_SHIFT;
val |= I830_FENCE_REG_VALID;
} else
val = 0;
I915_WRITE(FENCE_REG(reg), val);
POSTING_READ(FENCE_REG(reg));
}
static void i830_write_fence_reg(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(dev);
uint32_t val;
if (obj) {
u32 size = i915_gem_obj_ggtt_size(obj);
uint32_t pitch_val;
WARN((i915_gem_obj_ggtt_offset(obj) & ~I830_FENCE_START_MASK) ||
(size & -size) != size ||
(i915_gem_obj_ggtt_offset(obj) & (size - 1)),
"object 0x%08llx not 512K or pot-size 0x%08x aligned\n",
i915_gem_obj_ggtt_offset(obj), size);
pitch_val = obj->stride / 128;
pitch_val = ffs(pitch_val) - 1;
val = i915_gem_obj_ggtt_offset(obj);
if (obj->tiling_mode == I915_TILING_Y)
val |= 1 << I830_FENCE_TILING_Y_SHIFT;
val |= I830_FENCE_SIZE_BITS(size);
val |= pitch_val << I830_FENCE_PITCH_SHIFT;
val |= I830_FENCE_REG_VALID;
} else
val = 0;
I915_WRITE(FENCE_REG(reg), val);
POSTING_READ(FENCE_REG(reg));
}
inline static bool i915_gem_object_needs_mb(struct drm_i915_gem_object *obj)
{
return obj && obj->base.read_domains & I915_GEM_DOMAIN_GTT;
}
static void i915_gem_write_fence(struct drm_device *dev, int reg,
struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(dev);
if (i915_gem_object_needs_mb(dev_priv->fence_regs[reg].obj))
mb();
WARN(obj && (!obj->stride || !obj->tiling_mode),
"bogus fence setup with stride: 0x%x, tiling mode: %i\n",
obj->stride, obj->tiling_mode);
if (IS_GEN2(dev))
i830_write_fence_reg(dev, reg, obj);
else if (IS_GEN3(dev))
i915_write_fence_reg(dev, reg, obj);
else if (INTEL_INFO(dev)->gen >= 4)
i965_write_fence_reg(dev, reg, obj);
if (i915_gem_object_needs_mb(obj))
mb();
}
static inline int fence_number(struct drm_i915_private *dev_priv,
struct drm_i915_fence_reg *fence)
{
return fence - dev_priv->fence_regs;
}
static void i915_gem_object_update_fence(struct drm_i915_gem_object *obj,
struct drm_i915_fence_reg *fence,
bool enable)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
int reg = fence_number(dev_priv, fence);
i915_gem_write_fence(obj->base.dev, reg, enable ? obj : NULL);
if (enable) {
obj->fence_reg = reg;
fence->obj = obj;
list_move_tail(&fence->lru_list, &dev_priv->mm.fence_list);
} else {
obj->fence_reg = I915_FENCE_REG_NONE;
fence->obj = NULL;
list_del_init(&fence->lru_list);
}
obj->fence_dirty = false;
}
static inline void i915_gem_object_fence_lost(struct drm_i915_gem_object *obj)
{
if (obj->tiling_mode)
i915_gem_release_mmap(obj);
obj->fence_dirty = false;
obj->fence_reg = I915_FENCE_REG_NONE;
}
static int
i915_gem_object_wait_fence(struct drm_i915_gem_object *obj)
{
if (obj->last_fenced_req) {
int ret = i915_wait_request(obj->last_fenced_req);
if (ret)
return ret;
i915_gem_request_assign(&obj->last_fenced_req, NULL);
}
return 0;
}
int
i915_gem_object_put_fence(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
struct drm_i915_fence_reg *fence;
int ret;
ret = i915_gem_object_wait_fence(obj);
if (ret)
return ret;
if (obj->fence_reg == I915_FENCE_REG_NONE)
return 0;
fence = &dev_priv->fence_regs[obj->fence_reg];
if (WARN_ON(fence->pin_count))
return -EBUSY;
i915_gem_object_fence_lost(obj);
i915_gem_object_update_fence(obj, fence, false);
return 0;
}
static struct drm_i915_fence_reg *
i915_find_fence_reg(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_fence_reg *reg, *avail;
int i;
avail = NULL;
for (i = 0; i < dev_priv->num_fence_regs; i++) {
reg = &dev_priv->fence_regs[i];
if (!reg->obj)
return reg;
if (!reg->pin_count)
avail = reg;
}
if (avail == NULL)
goto deadlock;
list_for_each_entry(reg, &dev_priv->mm.fence_list, lru_list) {
if (reg->pin_count)
continue;
return reg;
}
deadlock:
if (intel_has_pending_fb_unpin(dev))
return ERR_PTR(-EAGAIN);
return ERR_PTR(-EDEADLK);
}
int
i915_gem_object_get_fence(struct drm_i915_gem_object *obj)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = to_i915(dev);
bool enable = obj->tiling_mode != I915_TILING_NONE;
struct drm_i915_fence_reg *reg;
int ret;
if (obj->fence_dirty) {
ret = i915_gem_object_wait_fence(obj);
if (ret)
return ret;
}
if (obj->fence_reg != I915_FENCE_REG_NONE) {
reg = &dev_priv->fence_regs[obj->fence_reg];
if (!obj->fence_dirty) {
list_move_tail(&reg->lru_list,
&dev_priv->mm.fence_list);
return 0;
}
} else if (enable) {
if (WARN_ON(!obj->map_and_fenceable))
return -EINVAL;
reg = i915_find_fence_reg(dev);
if (IS_ERR(reg))
return PTR_ERR(reg);
if (reg->obj) {
struct drm_i915_gem_object *old = reg->obj;
ret = i915_gem_object_wait_fence(old);
if (ret)
return ret;
i915_gem_object_fence_lost(old);
}
} else
return 0;
i915_gem_object_update_fence(obj, reg, enable);
return 0;
}
bool
i915_gem_object_pin_fence(struct drm_i915_gem_object *obj)
{
if (obj->fence_reg != I915_FENCE_REG_NONE) {
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
struct i915_vma *ggtt_vma = i915_gem_obj_to_ggtt(obj);
WARN_ON(!ggtt_vma ||
dev_priv->fence_regs[obj->fence_reg].pin_count >
ggtt_vma->pin_count);
dev_priv->fence_regs[obj->fence_reg].pin_count++;
return true;
} else
return false;
}
void
i915_gem_object_unpin_fence(struct drm_i915_gem_object *obj)
{
if (obj->fence_reg != I915_FENCE_REG_NONE) {
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
WARN_ON(dev_priv->fence_regs[obj->fence_reg].pin_count <= 0);
dev_priv->fence_regs[obj->fence_reg].pin_count--;
}
}
void i915_gem_restore_fences(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
int i;
for (i = 0; i < dev_priv->num_fence_regs; i++) {
struct drm_i915_fence_reg *reg = &dev_priv->fence_regs[i];
if (reg->obj) {
i915_gem_object_update_fence(reg->obj, reg,
reg->obj->tiling_mode);
} else {
i915_gem_write_fence(dev, i, NULL);
}
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
