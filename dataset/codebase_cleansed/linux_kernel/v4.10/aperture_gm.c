static int alloc_gm(struct intel_vgpu *vgpu, bool high_gm)
{
struct intel_gvt *gvt = vgpu->gvt;
struct drm_i915_private *dev_priv = gvt->dev_priv;
u32 alloc_flag, search_flag;
u64 start, end, size;
struct drm_mm_node *node;
int retried = 0;
int ret;
if (high_gm) {
search_flag = DRM_MM_SEARCH_BELOW;
alloc_flag = DRM_MM_CREATE_TOP;
node = &vgpu->gm.high_gm_node;
size = vgpu_hidden_sz(vgpu);
start = gvt_hidden_gmadr_base(gvt);
end = gvt_hidden_gmadr_end(gvt);
} else {
search_flag = DRM_MM_SEARCH_DEFAULT;
alloc_flag = DRM_MM_CREATE_DEFAULT;
node = &vgpu->gm.low_gm_node;
size = vgpu_aperture_sz(vgpu);
start = gvt_aperture_gmadr_base(gvt);
end = gvt_aperture_gmadr_end(gvt);
}
mutex_lock(&dev_priv->drm.struct_mutex);
search_again:
ret = drm_mm_insert_node_in_range_generic(&dev_priv->ggtt.base.mm,
node, size, 4096, 0,
start, end, search_flag,
alloc_flag);
if (ret) {
ret = i915_gem_evict_something(&dev_priv->ggtt.base,
size, 4096, 0, start, end, 0);
if (ret == 0 && ++retried < 3)
goto search_again;
gvt_err("fail to alloc %s gm space from host, retried %d\n",
high_gm ? "high" : "low", retried);
}
mutex_unlock(&dev_priv->drm.struct_mutex);
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
gvt_err("Invalid vGPU creation params\n");
return -EINVAL;
}
item = "low GM space";
max = gvt_aperture_sz(gvt) - HOST_LOW_GM_SIZE;
taken = gvt->gm.vgpu_allocated_low_gm_size;
avail = max - taken;
request = MB_TO_BYTES(param->low_gm_sz);
if (request > avail)
goto no_enough_resource;
vgpu_aperture_sz(vgpu) = request;
item = "high GM space";
max = gvt_hidden_sz(gvt) - HOST_HIGH_GM_SIZE;
taken = gvt->gm.vgpu_allocated_high_gm_size;
avail = max - taken;
request = MB_TO_BYTES(param->high_gm_sz);
if (request > avail)
goto no_enough_resource;
vgpu_hidden_sz(vgpu) = request;
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
gvt_err("vgpu%d: fail to allocate resource %s\n", vgpu->id, item);
gvt_err("vgpu%d: request %luMB avail %luMB max %luMB taken %luMB\n",
vgpu->id, BYTES_TO_MB(request), BYTES_TO_MB(avail),
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
