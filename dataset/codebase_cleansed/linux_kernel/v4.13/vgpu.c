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
unsigned int i, low_avail, high_avail;
unsigned int min_low;
low_avail = gvt_aperture_sz(gvt) - HOST_LOW_GM_SIZE;
high_avail = gvt_hidden_sz(gvt) - HOST_HIGH_GM_SIZE;
num_types = sizeof(vgpu_types) / sizeof(vgpu_types[0]);
gvt->types = kzalloc(num_types * sizeof(struct intel_vgpu_type),
GFP_KERNEL);
if (!gvt->types)
return -ENOMEM;
min_low = MB_TO_BYTES(32);
for (i = 0; i < num_types; ++i) {
if (low_avail / vgpu_types[i].low_mm == 0)
break;
gvt->types[i].low_gm_size = vgpu_types[i].low_mm;
gvt->types[i].high_gm_size = vgpu_types[i].high_mm;
gvt->types[i].fence = vgpu_types[i].fence;
if (vgpu_types[i].weight < 1 ||
vgpu_types[i].weight > VGPU_MAX_WEIGHT)
return -EINVAL;
gvt->types[i].weight = vgpu_types[i].weight;
gvt->types[i].resolution = vgpu_types[i].edid;
gvt->types[i].avail_instance = min(low_avail / vgpu_types[i].low_mm,
high_avail / vgpu_types[i].high_mm);
if (IS_GEN8(gvt->dev_priv))
sprintf(gvt->types[i].name, "GVTg_V4_%s",
vgpu_types[i].name);
else if (IS_GEN9(gvt->dev_priv))
sprintf(gvt->types[i].name, "GVTg_V5_%s",
vgpu_types[i].name);
gvt_dbg_core("type[%d]: %s avail %u low %u high %u fence %u weight %u res %s\n",
i, gvt->types[i].name,
gvt->types[i].avail_instance,
gvt->types[i].low_gm_size,
gvt->types[i].high_gm_size, gvt->types[i].fence,
gvt->types[i].weight,
vgpu_edid_str(gvt->types[i].resolution));
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
unsigned int low_gm_min, high_gm_min, fence_min;
low_gm_avail = gvt_aperture_sz(gvt) - HOST_LOW_GM_SIZE -
gvt->gm.vgpu_allocated_low_gm_size;
high_gm_avail = gvt_hidden_sz(gvt) - HOST_HIGH_GM_SIZE -
gvt->gm.vgpu_allocated_high_gm_size;
fence_avail = gvt_fence_sz(gvt) - HOST_FENCE -
gvt->fence.vgpu_allocated_fence_num;
for (i = 0; i < gvt->num_types; i++) {
low_gm_min = low_gm_avail / gvt->types[i].low_gm_size;
high_gm_min = high_gm_avail / gvt->types[i].high_gm_size;
fence_min = fence_avail / gvt->types[i].fence;
gvt->types[i].avail_instance = min(min(low_gm_min, high_gm_min),
fence_min);
gvt_dbg_core("update type[%d]: %s avail %u low %u high %u fence %u\n",
i, gvt->types[i].name,
gvt->types[i].avail_instance, gvt->types[i].low_gm_size,
gvt->types[i].high_gm_size, gvt->types[i].fence);
}
}
void intel_gvt_activate_vgpu(struct intel_vgpu *vgpu)
{
mutex_lock(&vgpu->gvt->lock);
vgpu->active = true;
mutex_unlock(&vgpu->gvt->lock);
}
void intel_gvt_deactivate_vgpu(struct intel_vgpu *vgpu)
{
struct intel_gvt *gvt = vgpu->gvt;
mutex_lock(&gvt->lock);
vgpu->active = false;
if (atomic_read(&vgpu->running_workload_num)) {
mutex_unlock(&gvt->lock);
intel_gvt_wait_vgpu_idle(vgpu);
mutex_lock(&gvt->lock);
}
intel_vgpu_stop_schedule(vgpu);
mutex_unlock(&gvt->lock);
}
void intel_gvt_destroy_vgpu(struct intel_vgpu *vgpu)
{
struct intel_gvt *gvt = vgpu->gvt;
mutex_lock(&gvt->lock);
WARN(vgpu->active, "vGPU is still active!\n");
idr_remove(&gvt->vgpu_idr, vgpu->id);
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
struct intel_vgpu *intel_gvt_create_idle_vgpu(struct intel_gvt *gvt)
{
struct intel_vgpu *vgpu;
enum intel_engine_id i;
int ret;
vgpu = vzalloc(sizeof(*vgpu));
if (!vgpu)
return ERR_PTR(-ENOMEM);
vgpu->id = IDLE_VGPU_IDR;
vgpu->gvt = gvt;
for (i = 0; i < I915_NUM_ENGINES; i++)
INIT_LIST_HEAD(&vgpu->workload_q_head[i]);
ret = intel_vgpu_init_sched_policy(vgpu);
if (ret)
goto out_free_vgpu;
vgpu->active = false;
return vgpu;
out_free_vgpu:
vfree(vgpu);
return ERR_PTR(ret);
}
void intel_gvt_destroy_idle_vgpu(struct intel_vgpu *vgpu)
{
intel_vgpu_clean_sched_policy(vgpu);
vfree(vgpu);
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
ret = idr_alloc(&gvt->vgpu_idr, vgpu, IDLE_VGPU_IDR + 1, GVT_MAX_VGPU,
GFP_KERNEL);
if (ret < 0)
goto out_free_vgpu;
vgpu->id = ret;
vgpu->handle = param->handle;
vgpu->gvt = gvt;
vgpu->sched_ctl.weight = param->weight;
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
ret = intel_vgpu_init_display(vgpu, param->resolution);
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
param.weight = type->weight;
param.resolution = type->resolution;
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
unsigned int resetting_eng = dmlr ? ALL_ENGINES : engine_mask;
gvt_dbg_core("------------------------------------------\n");
gvt_dbg_core("resseting vgpu%d, dmlr %d, engine_mask %08x\n",
vgpu->id, dmlr, engine_mask);
vgpu->resetting_eng = resetting_eng;
intel_vgpu_stop_schedule(vgpu);
if (scheduler->current_vgpu == NULL) {
mutex_unlock(&gvt->lock);
intel_gvt_wait_vgpu_idle(vgpu);
mutex_lock(&gvt->lock);
}
intel_vgpu_reset_execlist(vgpu, resetting_eng);
if (engine_mask == ALL_ENGINES || dmlr) {
intel_vgpu_reset_gtt(vgpu, dmlr);
if (dmlr)
intel_vgpu_reset_resource(vgpu);
intel_vgpu_reset_mmio(vgpu, dmlr);
populate_pvinfo_page(vgpu);
intel_vgpu_reset_display(vgpu);
if (dmlr) {
intel_vgpu_reset_cfg_space(vgpu);
vgpu->failsafe = false;
vgpu->pv_notified = false;
}
}
vgpu->resetting_eng = 0;
gvt_dbg_core("reset vgpu%d done\n", vgpu->id);
gvt_dbg_core("------------------------------------------\n");
}
void intel_gvt_reset_vgpu(struct intel_vgpu *vgpu)
{
mutex_lock(&vgpu->gvt->lock);
intel_gvt_reset_vgpu_locked(vgpu, true, 0);
mutex_unlock(&vgpu->gvt->lock);
}
