static int alloc_gm(struct intel_vgpu *vgpu, bool high_gm)
{
struct intel_gvt *gvt = vgpu->gvt;
struct drm_i915_private *dev_priv = gvt->dev_priv;
unsigned int flags;
u64 start, end, size;
struct drm_mm_node *node;
int ret;
if (high_gm) {
node = &vgpu->gm.high_gm_node;
size = vgpu_hidden_sz(vgpu);
start = ALIGN(gvt_hidden_gmadr_base(gvt), I915_GTT_PAGE_SIZE);
end = ALIGN(gvt_hidden_gmadr_end(gvt), I915_GTT_PAGE_SIZE);
flags = PIN_HIGH;
} else {
node = &vgpu->gm.low_gm_node;
size = vgpu_aperture_sz(vgpu);
start = ALIGN(gvt_aperture_gmadr_base(gvt), I915_GTT_PAGE_SIZE);
end = ALIGN(gvt_aperture_gmadr_end(gvt), I915_GTT_PAGE_SIZE);
flags = PIN_MAPPABLE;
}
mutex_lock(&dev_priv->drm.struct_mutex);
ret = i915_gem_gtt_insert(&dev_priv->ggtt.base, node,
size, I915_GTT_PAGE_SIZE,
I915_COLOR_UNEVICTABLE,
start, end, flags);
mutex_unlock(&dev_priv->drm.struct_mutex);
if (ret)
gvt_err("fail to alloc %s gm space from host\n",
high_gm ? "high" : "low");
return ret;
}
static int alloc_vgpu_gm(struct intel_vgpu *vgpu)
{
struct intel_gvt *gvt = vgpu->gvt;
struct drm_i915_private *dev_priv = gvt->dev_priv;
int ret;
ret = alloc_gm(vgpu, false);
if (ret)
return ret;
ret = alloc_gm(vgpu, true);
if (ret)
goto out_free_aperture;
gvt_dbg_core("vgpu%d: alloc low GM start %llx size %llx\n", vgpu->id,
vgpu_aperture_offset(vgpu), vgpu_aperture_sz(vgpu));
gvt_dbg_core("vgpu%d: alloc high GM start %llx size %llx\n", vgpu->id,
vgpu_hidden_offset(vgpu), vgpu_hidden_sz(vgpu));
return 0;
out_free_aperture:
mutex_lock(&dev_priv->drm.struct_mutex);
drm_mm_remove_node(&vgpu->gm.low_gm_node);
mutex_unlock(&dev_priv->drm.struct_mutex);
return ret;
}
static void free_vgpu_gm(struct intel_vgpu *vgpu)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
mutex_lock(&dev_priv->drm.struct_mutex);
drm_mm_remove_node(&vgpu->gm.low_gm_node);
drm_mm_remove_node(&vgpu->gm.high_gm_node);
mutex_unlock(&dev_priv->drm.struct_mutex);
}
void intel_vgpu_write_fence(struct intel_vgpu *vgpu,
u32 fence, u64 value)
{
struct intel_gvt *gvt = vgpu->gvt;
struct drm_i915_private *dev_priv = gvt->dev_priv;
struct drm_i915_fence_reg *reg;
i915_reg_t fence_reg_lo, fence_reg_hi;
assert_rpm_wakelock_held(dev_priv);
if (WARN_ON(fence > vgpu_fence_sz(vgpu)))
return;
reg = vgpu->fence.regs[fence];
if (WARN_ON(!reg))
return;
fence_reg_lo = FENCE_REG_GEN6_LO(reg->id);
fence_reg_hi = FENCE_REG_GEN6_HI(reg->id);
I915_WRITE(fence_reg_lo, 0);
POSTING_READ(fence_reg_lo);
I915_WRITE(fence_reg_hi, upper_32_bits(value));
I915_WRITE(fence_reg_lo, lower_32_bits(value));
POSTING_READ(fence_reg_lo);
}
static void _clear_vgpu_fence(struct intel_vgpu *vgpu)
{
int i;
for (i = 0; i < vgpu_fence_sz(vgpu); i++)
intel_vgpu_write_fence(vgpu, i, 0);
}
static void free_vgpu_fence(struct intel_vgpu *vgpu)
{
struct intel_gvt *gvt = vgpu->gvt;
struct drm_i915_private *dev_priv = gvt->dev_priv;
struct drm_i915_fence_reg *reg;
u32 i;
if (WARN_ON(!vgpu_fence_sz(vgpu)))
return;
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->drm.struct_mutex);
_clear_vgpu_fence(vgpu);
for (i = 0; i < vgpu_fence_sz(vgpu); i++) {
reg = vgpu->fence.regs[i];
list_add_tail(&reg->link,
&dev_priv->mm.fence_list);
}
mutex_unlock(&dev_priv->drm.struct_mutex);
intel_runtime_pm_put(dev_priv);
}
static int alloc_vgpu_fence(struct intel_vgpu *vgpu)
{
struct intel_gvt *gvt = vgpu->gvt;
struct drm_i915_private *dev_priv = gvt->dev_priv;
struct drm_i915_fence_reg *reg;
int i;
struct list_head *pos, *q;
intel_runtime_pm_get(dev_priv);
mutex_lock(&dev_priv->drm.struct_mutex);
i = 0;
list_for_each_safe(pos, q, &dev_priv->mm.fence_list) {
reg = list_entry(pos, struct drm_i915_fence_reg, link);
if (reg->pin_count || reg->vma)
continue;
list_del(pos);
vgpu->fence.regs[i] = reg;
if (++i == vgpu_fence_sz(vgpu))
break;
}
if (i != vgpu_fence_sz(vgpu))
goto out_free_fence;
_clear_vgpu_fence(vgpu);
mutex_unlock(&dev_priv->drm.struct_mutex);
intel_runtime_pm_put(dev_priv);
return 0;
out_free_fence:
for (i = 0; i < vgpu_fence_sz(vgpu); i++) {
reg = vgpu->fence.regs[i];
if (!reg)
continue;
list_add_tail(&reg->link,
&dev_priv->mm.fence_list);
}
mutex_unlock(&dev_priv->drm.struct_mutex);
intel_runtime_pm_put(dev_priv);
return -ENOSPC;
}
static void free_resource(struct intel_vgpu *vgpu)
{
struct intel_gvt *gvt = vgpu->gvt;
gvt->gm.vgpu_allocated_low_gm_size -= vgpu_aperture_sz(vgpu);
gvt->gm.vgpu_allocated_high_gm_size -= vgpu_hidden_sz(vgpu);
gvt->fence.vgpu_allocated_fence_num -= vgpu_fence_sz(vgpu);
}
static int alloc_resource(struct intel_vgpu *vgpu,
struct intel_vgpu_creation_params *param)
{
struct intel_gvt *gvt = vgpu->gvt;
unsigned long request, avail, max, taken;
const char *item;
if (!param->low_gm_sz || !param->high_gm_sz || !param->fence_sz) {
gvt_vgpu_err("Invalid vGPU creation params\n");
return -EINVAL;
}
item = "low GM space";
max = gvt_aperture_sz(gvt) - HOST_LOW_GM_SIZE;
taken = gvt->gm.vgpu_allocated_low_gm_size;
avail = max - taken;
request = MB_TO_BYTES(param->low_gm_sz);
if (request > avail)
goto no_enough_resource;
vgpu_aperture_sz(vgpu) = ALIGN(request, I915_GTT_PAGE_SIZE);
item = "high GM space";
max = gvt_hidden_sz(gvt) - HOST_HIGH_GM_SIZE;
taken = gvt->gm.vgpu_allocated_high_gm_size;
avail = max - taken;
request = MB_TO_BYTES(param->high_gm_sz);
if (request > avail)
goto no_enough_resource;
vgpu_hidden_sz(vgpu) = ALIGN(request, I915_GTT_PAGE_SIZE);
item = "fence";
max = gvt_fence_sz(gvt) - HOST_FENCE;
taken = gvt->fence.vgpu_allocated_fence_num;
avail = max - taken;
request = param->fence_sz;
if (request > avail)
goto no_enough_resource;
vgpu_fence_sz(vgpu) = request;
gvt->gm.vgpu_allocated_low_gm_size += MB_TO_BYTES(param->low_gm_sz);
gvt->gm.vgpu_allocated_high_gm_size += MB_TO_BYTES(param->high_gm_sz);
gvt->fence.vgpu_allocated_fence_num += param->fence_sz;
return 0;
no_enough_resource:
gvt_vgpu_err("fail to allocate resource %s\n", item);
gvt_vgpu_err("request %luMB avail %luMB max %luMB taken %luMB\n",
BYTES_TO_MB(request), BYTES_TO_MB(avail),
BYTES_TO_MB(max), BYTES_TO_MB(taken));
return -ENOSPC;
}
void intel_vgpu_free_resource(struct intel_vgpu *vgpu)
{
free_vgpu_gm(vgpu);
free_vgpu_fence(vgpu);
free_resource(vgpu);
}
void intel_vgpu_reset_resource(struct intel_vgpu *vgpu)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
intel_runtime_pm_get(dev_priv);
_clear_vgpu_fence(vgpu);
intel_runtime_pm_put(dev_priv);
}
int intel_vgpu_alloc_resource(struct intel_vgpu *vgpu,
struct intel_vgpu_creation_params *param)
{
int ret;
ret = alloc_resource(vgpu, param);
if (ret)
return ret;
ret = alloc_vgpu_gm(vgpu);
if (ret)
goto out_free_resource;
ret = alloc_vgpu_fence(vgpu);
if (ret)
goto out_free_vgpu_gm;
return 0;
out_free_vgpu_gm:
free_vgpu_gm(vgpu);
out_free_resource:
free_resource(vgpu);
return ret;
}
