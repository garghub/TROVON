void i915_check_vgpu(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
uint64_t magic;
uint32_t version;
BUILD_BUG_ON(sizeof(struct vgt_if) != VGT_PVINFO_SIZE);
if (!IS_HASWELL(dev))
return;
magic = readq(dev_priv->regs + vgtif_reg(magic));
if (magic != VGT_MAGIC)
return;
version = INTEL_VGT_IF_VERSION_ENCODE(
readw(dev_priv->regs + vgtif_reg(version_major)),
readw(dev_priv->regs + vgtif_reg(version_minor)));
if (version != INTEL_VGT_IF_VERSION) {
DRM_INFO("VGT interface version mismatch!\n");
return;
}
dev_priv->vgpu.active = true;
DRM_INFO("Virtual GPU for Intel GVT-g detected.\n");
}
void intel_vgt_deballoon(void)
{
int i;
DRM_DEBUG("VGT deballoon.\n");
for (i = 0; i < 4; i++) {
if (bl_info.space[i].allocated)
drm_mm_remove_node(&bl_info.space[i]);
}
memset(&bl_info, 0, sizeof(bl_info));
}
static int vgt_balloon_space(struct drm_mm *mm,
struct drm_mm_node *node,
unsigned long start, unsigned long end)
{
unsigned long size = end - start;
if (start == end)
return -EINVAL;
DRM_INFO("balloon space: range [ 0x%lx - 0x%lx ] %lu KiB.\n",
start, end, size / 1024);
node->start = start;
node->size = size;
return drm_mm_reserve_node(mm, node);
}
int intel_vgt_balloon(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_address_space *ggtt_vm = &dev_priv->gtt.base;
unsigned long ggtt_vm_end = ggtt_vm->start + ggtt_vm->total;
unsigned long mappable_base, mappable_size, mappable_end;
unsigned long unmappable_base, unmappable_size, unmappable_end;
int ret;
mappable_base = I915_READ(vgtif_reg(avail_rs.mappable_gmadr.base));
mappable_size = I915_READ(vgtif_reg(avail_rs.mappable_gmadr.size));
unmappable_base = I915_READ(vgtif_reg(avail_rs.nonmappable_gmadr.base));
unmappable_size = I915_READ(vgtif_reg(avail_rs.nonmappable_gmadr.size));
mappable_end = mappable_base + mappable_size;
unmappable_end = unmappable_base + unmappable_size;
DRM_INFO("VGT ballooning configuration:\n");
DRM_INFO("Mappable graphic memory: base 0x%lx size %ldKiB\n",
mappable_base, mappable_size / 1024);
DRM_INFO("Unmappable graphic memory: base 0x%lx size %ldKiB\n",
unmappable_base, unmappable_size / 1024);
if (mappable_base < ggtt_vm->start ||
mappable_end > dev_priv->gtt.mappable_end ||
unmappable_base < dev_priv->gtt.mappable_end ||
unmappable_end > ggtt_vm_end) {
DRM_ERROR("Invalid ballooning configuration!\n");
return -EINVAL;
}
if (unmappable_base > dev_priv->gtt.mappable_end) {
ret = vgt_balloon_space(&ggtt_vm->mm,
&bl_info.space[2],
dev_priv->gtt.mappable_end,
unmappable_base);
if (ret)
goto err;
}
if (unmappable_end < ggtt_vm_end - PAGE_SIZE) {
ret = vgt_balloon_space(&ggtt_vm->mm,
&bl_info.space[3],
unmappable_end,
ggtt_vm_end - PAGE_SIZE);
if (ret)
goto err;
}
if (mappable_base > ggtt_vm->start) {
ret = vgt_balloon_space(&ggtt_vm->mm,
&bl_info.space[0],
ggtt_vm->start, mappable_base);
if (ret)
goto err;
}
if (mappable_end < dev_priv->gtt.mappable_end) {
ret = vgt_balloon_space(&ggtt_vm->mm,
&bl_info.space[1],
mappable_end,
dev_priv->gtt.mappable_end);
if (ret)
goto err;
}
DRM_INFO("VGT balloon successfully\n");
return 0;
err:
DRM_ERROR("VGT balloon fail\n");
intel_vgt_deballoon();
return ret;
}
