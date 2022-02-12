void i915_check_vgpu(struct drm_i915_private *dev_priv)
{
u64 magic;
u16 version_major;
BUILD_BUG_ON(sizeof(struct vgt_if) != VGT_PVINFO_SIZE);
magic = __raw_i915_read64(dev_priv, vgtif_reg(magic));
if (magic != VGT_MAGIC)
return;
version_major = __raw_i915_read16(dev_priv, vgtif_reg(version_major));
if (version_major < VGT_VERSION_MAJOR) {
DRM_INFO("VGT interface version mismatch!\n");
return;
}
dev_priv->vgpu.active = true;
DRM_INFO("Virtual GPU for Intel GVT-g detected.\n");
}
static void vgt_deballoon_space(struct i915_ggtt *ggtt,
struct drm_mm_node *node)
{
DRM_DEBUG_DRIVER("deballoon space: range [0x%llx - 0x%llx] %llu KiB.\n",
node->start,
node->start + node->size,
node->size / 1024);
ggtt->base.reserved -= node->size;
drm_mm_remove_node(node);
}
void intel_vgt_deballoon(struct drm_i915_private *dev_priv)
{
int i;
if (!intel_vgpu_active(dev_priv))
return;
DRM_DEBUG("VGT deballoon.\n");
for (i = 0; i < 4; i++)
vgt_deballoon_space(&dev_priv->ggtt, &bl_info.space[i]);
}
static int vgt_balloon_space(struct i915_ggtt *ggtt,
struct drm_mm_node *node,
unsigned long start, unsigned long end)
{
unsigned long size = end - start;
int ret;
if (start >= end)
return -EINVAL;
DRM_INFO("balloon space: range [ 0x%lx - 0x%lx ] %lu KiB.\n",
start, end, size / 1024);
ret = i915_gem_gtt_reserve(&ggtt->base, node,
size, start, I915_COLOR_UNEVICTABLE,
0);
if (!ret)
ggtt->base.reserved += size;
return ret;
}
int intel_vgt_balloon(struct drm_i915_private *dev_priv)
{
struct i915_ggtt *ggtt = &dev_priv->ggtt;
unsigned long ggtt_end = ggtt->base.total;
unsigned long mappable_base, mappable_size, mappable_end;
unsigned long unmappable_base, unmappable_size, unmappable_end;
int ret;
if (!intel_vgpu_active(dev_priv))
return 0;
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
if (mappable_end > ggtt->mappable_end ||
unmappable_base < ggtt->mappable_end ||
unmappable_end > ggtt_end) {
DRM_ERROR("Invalid ballooning configuration!\n");
return -EINVAL;
}
if (unmappable_base > ggtt->mappable_end) {
ret = vgt_balloon_space(ggtt, &bl_info.space[2],
ggtt->mappable_end, unmappable_base);
if (ret)
goto err;
}
if (unmappable_end < ggtt_end) {
ret = vgt_balloon_space(ggtt, &bl_info.space[3],
unmappable_end, ggtt_end);
if (ret)
goto err_upon_mappable;
}
if (mappable_base) {
ret = vgt_balloon_space(ggtt, &bl_info.space[0],
0, mappable_base);
if (ret)
goto err_upon_unmappable;
}
if (mappable_end < ggtt->mappable_end) {
ret = vgt_balloon_space(ggtt, &bl_info.space[1],
mappable_end, ggtt->mappable_end);
if (ret)
goto err_below_mappable;
}
DRM_INFO("VGT balloon successfully\n");
return 0;
err_below_mappable:
vgt_deballoon_space(ggtt, &bl_info.space[0]);
err_upon_unmappable:
vgt_deballoon_space(ggtt, &bl_info.space[3]);
err_upon_mappable:
vgt_deballoon_space(ggtt, &bl_info.space[2]);
err:
DRM_ERROR("VGT balloon fail\n");
return ret;
}
