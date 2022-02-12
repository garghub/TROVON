void populate_pvinfo_page(struct intel_vgpu *vgpu)
{
vgpu_vreg64(vgpu, vgtif_reg(magic)) = VGT_MAGIC;
vgpu_vreg(vgpu, vgtif_reg(version_major)) = 1;
vgpu_vreg(vgpu, vgtif_reg(version_minor)) = 0;
vgpu_vreg(vgpu, vgtif_reg(display_ready)) = 0;
vgpu_vreg(vgpu, vgtif_reg(vgt_id)) = vgpu->id;
vgpu_vreg(vgpu, vgtif_reg(avail_rs.mappable_gmadr.base)) =
vgpu_aperture_gmadr_base(vgpu);
vgpu_vreg(vgpu, vgtif_reg(avail_rs.mappable_gmadr.size)) =
vgpu_aperture_sz(vgpu);
vgpu_vreg(vgpu, vgtif_reg(avail_rs.nonmappable_gmadr.base)) =
vgpu_hidden_gmadr_base(vgpu);
vgpu_vreg(vgpu, vgtif_reg(avail_rs.nonmappable_gmadr.size)) =
vgpu_hidden_sz(vgpu);
vgpu_vreg(vgpu, vgtif_reg(avail_rs.fence_num)) = vgpu_fence_sz(vgpu);
gvt_dbg_core("Populate PVINFO PAGE for vGPU %d\n", vgpu->id);
gvt_dbg_core("aperture base [GMADR] 0x%llx size 0x%llx\n",
vgpu_aperture_gmadr_base(vgpu), vgpu_aperture_sz(vgpu));
gvt_dbg_core("hidden base [GMADR] 0x%llx size=0x%llx\n",
vgpu_hidden_gmadr_base(vgpu), vgpu_hidden_sz(vgpu));
gvt_dbg_core("fence size %d\n", vgpu_fence_sz(vgpu));
WARN_ON(sizeof(struct vgt_if) != VGT_PVINFO_SIZE);
}
int intel_gvt_init_vgpu_types(struct intel_gvt *gvt)
{
unsigned int num_types;
unsigned int i, low_avail;
unsigned int min_low;
low_avail = MB_TO_BYTES(256) - HOST_LOW_GM_SIZE;
num_types = 4;
gvt->types = kzalloc(num_types * sizeof(struct intel_vgpu_type),
GFP_KERNEL);
if (!gvt->types)
return -ENOMEM;
min_low = MB_TO_BYTES(32);
for (i = 0; i < num_types; ++i) {
if (low_avail / min_low == 0)
break;
gvt->types[i].low_gm_size = min_low;
gvt->types[i].high_gm_size = max((min_low<<3), MB_TO_BYTES(384U));
gvt->types[i].fence = 4;
gvt->types[i].max_instance = low_avail / min_low;
gvt->types[i].avail_instance = gvt->types[i].max_instance;
if (IS_GEN8(gvt->dev_priv))
sprintf(gvt->types[i].name, "GVTg_V4_%u",
gvt->types[i].max_instance);
else if (IS_GEN9(gvt->dev_priv))
sprintf(gvt->types[i].name, "GVTg_V5_%u",
gvt->types[i].max_instance);
min_low <<= 1;
gvt_dbg_core("type[%d]: %s max %u avail %u low %u high %u fence %u\n",
i, gvt->types[i].name, gvt->types[i].max_instance,
gvt->types[i].avail_instance,
gvt->types[i].low_gm_size,
gvt->types[i].high_gm_size, gvt->types[i].fence);
}
gvt->num_types = i;
return 0;
}
void intel_gvt_clean_vgpu_types(struct intel_gvt *gvt)
{
kfree(gvt->types);
}
static void intel_gvt_update_vgpu_types(struct intel_gvt *gvt)
{
int i;
unsigned int low_gm_avail, high_gm_avail, fence_avail;
unsigned int low_gm_min, high_gm_min, fence_min, total_min;
low_gm_avail = MB_TO_BYTES(256) - HOST_LOW_GM_SIZE -
gvt->gm.vgpu_allocated_low_gm_size;
high_gm_avail = MB_TO_BYTES(256) * 8UL - HOST_HIGH_GM_SIZE -
gvt->gm.vgpu_allocated_high_gm_size;
fence_avail = gvt_fence_sz(gvt) - HOST_FENCE -
gvt->fence.vgpu_allocated_fence_num;
for (i = 0; i < gvt->num_types; i++) {
low_gm_min = low_gm_avail / gvt->types[i].low_gm_size;
high_gm_min = high_gm_avail / gvt->types[i].high_gm_size;
fence_min = fence_avail / gvt->types[i].fence;
total_min = min(min(low_gm_min, high_gm_min), fence_min);
gvt->types[i].avail_instance = min(gvt->types[i].max_instance,
total_min);
gvt_dbg_core("update type[%d]: %s max %u avail %u low %u high %u fence %u\n",
i, gvt->types[i].name, gvt->types[i].max_instance,
gvt->types[i].avail_instance, gvt->types[i].low_gm_size,
gvt->types[i].high_gm_size, gvt->types[i].fence);
}
}
void intel_gvt_destroy_vgpu(struct intel_vgpu *vgpu)
{
struct intel_gvt *gvt = vgpu->gvt;
mutex_lock(&gvt->lock);
vgpu->active = false;
idr_remove(&gvt->vgpu_idr, vgpu->id);
if (atomic_read(&vgpu->running_workload_num)) {
mutex_unlock(&gvt->lock);
intel_gvt_wait_vgpu_idle(vgpu);
mutex_lock(&gvt->lock);
}
intel_vgpu_stop_schedule(vgpu);
intel_vgpu_clean_sched_policy(vgpu);
intel_vgpu_clean_gvt_context(vgpu);
intel_vgpu_clean_execlist(vgpu);
intel_vgpu_clean_display(vgpu);
intel_vgpu_clean_opregion(vgpu);
intel_vgpu_clean_gtt(vgpu);
intel_gvt_hypervisor_detach_vgpu(vgpu);
intel_vgpu_free_resource(vgpu);
intel_vgpu_clean_mmio(vgpu);
vfree(vgpu);
intel_gvt_update_vgpu_types(gvt);
mutex_unlock(&gvt->lock);
}
static struct intel_vgpu *__intel_gvt_create_vgpu(struct intel_gvt *gvt,
struct intel_vgpu_creation_params *param)
{
struct intel_vgpu *vgpu;
int ret;
gvt_dbg_core("handle %llu low %llu MB high %llu MB fence %llu\n",
param->handle, param->low_gm_sz, param->high_gm_sz,
param->fence_sz);
vgpu = vzalloc(sizeof(*vgpu));
if (!vgpu)
return ERR_PTR(-ENOMEM);
mutex_lock(&gvt->lock);
ret = idr_alloc(&gvt->vgpu_idr, vgpu, 1, GVT_MAX_VGPU, GFP_KERNEL);
if (ret < 0)
goto out_free_vgpu;
vgpu->id = ret;
vgpu->handle = param->handle;
vgpu->gvt = gvt;
bitmap_zero(vgpu->tlb_handle_pending, I915_NUM_ENGINES);
intel_vgpu_init_cfg_space(vgpu, param->primary);
ret = intel_vgpu_init_mmio(vgpu);
if (ret)
goto out_clean_idr;
ret = intel_vgpu_alloc_resource(vgpu, param);
if (ret)
goto out_clean_vgpu_mmio;
populate_pvinfo_page(vgpu);
ret = intel_gvt_hypervisor_attach_vgpu(vgpu);
if (ret)
goto out_clean_vgpu_resource;
ret = intel_vgpu_init_gtt(vgpu);
if (ret)
goto out_detach_hypervisor_vgpu;
ret = intel_vgpu_init_display(vgpu);
if (ret)
goto out_clean_gtt;
ret = intel_vgpu_init_execlist(vgpu);
if (ret)
goto out_clean_display;
ret = intel_vgpu_init_gvt_context(vgpu);
if (ret)
goto out_clean_execlist;
ret = intel_vgpu_init_sched_policy(vgpu);
if (ret)
goto out_clean_shadow_ctx;
vgpu->active = true;
mutex_unlock(&gvt->lock);
return vgpu;
out_clean_shadow_ctx:
intel_vgpu_clean_gvt_context(vgpu);
out_clean_execlist:
intel_vgpu_clean_execlist(vgpu);
out_clean_display:
intel_vgpu_clean_display(vgpu);
out_clean_gtt:
intel_vgpu_clean_gtt(vgpu);
out_detach_hypervisor_vgpu:
intel_gvt_hypervisor_detach_vgpu(vgpu);
out_clean_vgpu_resource:
intel_vgpu_free_resource(vgpu);
out_clean_vgpu_mmio:
intel_vgpu_clean_mmio(vgpu);
out_clean_idr:
idr_remove(&gvt->vgpu_idr, vgpu->id);
out_free_vgpu:
vfree(vgpu);
mutex_unlock(&gvt->lock);
return ERR_PTR(ret);
}
struct intel_vgpu *intel_gvt_create_vgpu(struct intel_gvt *gvt,
struct intel_vgpu_type *type)
{
struct intel_vgpu_creation_params param;
struct intel_vgpu *vgpu;
param.handle = 0;
param.primary = 1;
param.low_gm_sz = type->low_gm_size;
param.high_gm_sz = type->high_gm_size;
param.fence_sz = type->fence;
param.low_gm_sz = BYTES_TO_MB(param.low_gm_sz);
param.high_gm_sz = BYTES_TO_MB(param.high_gm_sz);
vgpu = __intel_gvt_create_vgpu(gvt, &param);
if (IS_ERR(vgpu))
return vgpu;
intel_gvt_update_vgpu_types(gvt);
return vgpu;
}
void intel_gvt_reset_vgpu_locked(struct intel_vgpu *vgpu, bool dmlr,
unsigned int engine_mask)
{
struct intel_gvt *gvt = vgpu->gvt;
struct intel_gvt_workload_scheduler *scheduler = &gvt->scheduler;
gvt_dbg_core("------------------------------------------\n");
gvt_dbg_core("resseting vgpu%d, dmlr %d, engine_mask %08x\n",
vgpu->id, dmlr, engine_mask);
vgpu->resetting = true;
intel_vgpu_stop_schedule(vgpu);
if (scheduler->current_vgpu == NULL) {
mutex_unlock(&gvt->lock);
intel_gvt_wait_vgpu_idle(vgpu);
mutex_lock(&gvt->lock);
}
intel_vgpu_reset_execlist(vgpu, dmlr ? ALL_ENGINES : engine_mask);
if (engine_mask == ALL_ENGINES || dmlr) {
intel_vgpu_reset_gtt(vgpu, dmlr);
intel_vgpu_reset_resource(vgpu);
intel_vgpu_reset_mmio(vgpu);
populate_pvinfo_page(vgpu);
if (dmlr)
intel_vgpu_reset_cfg_space(vgpu);
}
vgpu->resetting = false;
gvt_dbg_core("reset vgpu%d done\n", vgpu->id);
gvt_dbg_core("------------------------------------------\n");
}
void intel_gvt_reset_vgpu(struct intel_vgpu *vgpu)
{
mutex_lock(&vgpu->gvt->lock);
intel_gvt_reset_vgpu_locked(vgpu, true, 0);
mutex_unlock(&vgpu->gvt->lock);
}
