int amdgpu_ib_get(struct amdgpu_device *adev, struct amdgpu_vm *vm,
unsigned size, struct amdgpu_ib *ib)
{
int r;
if (size) {
r = amdgpu_sa_bo_new(&adev->ring_tmp_bo,
&ib->sa_bo, size, 256);
if (r) {
dev_err(adev->dev, "failed to get a new IB (%d)\n", r);
return r;
}
ib->ptr = amdgpu_sa_bo_cpu_addr(ib->sa_bo);
if (!vm)
ib->gpu_addr = amdgpu_sa_bo_gpu_addr(ib->sa_bo);
}
ib->vm = vm;
ib->vm_id = 0;
return 0;
}
void amdgpu_ib_free(struct amdgpu_device *adev, struct amdgpu_ib *ib, struct fence *f)
{
amdgpu_sa_bo_free(adev, &ib->sa_bo, f);
}
int amdgpu_ib_schedule(struct amdgpu_ring *ring, unsigned num_ibs,
struct amdgpu_ib *ibs, struct fence *last_vm_update,
struct fence **f)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_ib *ib = &ibs[0];
struct amdgpu_ctx *ctx, *old_ctx;
struct amdgpu_vm *vm;
struct fence *hwf;
unsigned i;
int r = 0;
if (num_ibs == 0)
return -EINVAL;
ctx = ibs->ctx;
vm = ibs->vm;
if (!ring->ready) {
dev_err(adev->dev, "couldn't schedule ib\n");
return -EINVAL;
}
if (vm && !ibs->vm_id) {
dev_err(adev->dev, "VM IB without ID\n");
return -EINVAL;
}
r = amdgpu_ring_alloc(ring, 256 * num_ibs);
if (r) {
dev_err(adev->dev, "scheduling IB failed (%d).\n", r);
return r;
}
if (vm) {
amdgpu_vm_flush(ring, ib->vm_id, ib->vm_pd_addr,
ib->gds_base, ib->gds_size,
ib->gws_base, ib->gws_size,
ib->oa_base, ib->oa_size);
if (ring->funcs->emit_hdp_flush)
amdgpu_ring_emit_hdp_flush(ring);
}
old_ctx = ring->current_ctx;
for (i = 0; i < num_ibs; ++i) {
ib = &ibs[i];
if (ib->ctx != ctx || ib->vm != vm) {
ring->current_ctx = old_ctx;
if (ib->vm_id)
amdgpu_vm_reset_id(adev, ib->vm_id);
amdgpu_ring_undo(ring);
return -EINVAL;
}
amdgpu_ring_emit_ib(ring, ib);
ring->current_ctx = ctx;
}
if (vm) {
if (ring->funcs->emit_hdp_invalidate)
amdgpu_ring_emit_hdp_invalidate(ring);
}
r = amdgpu_fence_emit(ring, &hwf);
if (r) {
dev_err(adev->dev, "failed to emit fence (%d)\n", r);
ring->current_ctx = old_ctx;
if (ib->vm_id)
amdgpu_vm_reset_id(adev, ib->vm_id);
amdgpu_ring_undo(ring);
return r;
}
if (ib->user) {
uint64_t addr = amdgpu_bo_gpu_offset(ib->user->bo);
addr += ib->user->offset;
amdgpu_ring_emit_fence(ring, addr, ib->sequence,
AMDGPU_FENCE_FLAG_64BIT);
}
if (f)
*f = fence_get(hwf);
amdgpu_ring_commit(ring);
return 0;
}
int amdgpu_ib_pool_init(struct amdgpu_device *adev)
{
int r;
if (adev->ib_pool_ready) {
return 0;
}
r = amdgpu_sa_bo_manager_init(adev, &adev->ring_tmp_bo,
AMDGPU_IB_POOL_SIZE*64*1024,
AMDGPU_GPU_PAGE_SIZE,
AMDGPU_GEM_DOMAIN_GTT);
if (r) {
return r;
}
r = amdgpu_sa_bo_manager_start(adev, &adev->ring_tmp_bo);
if (r) {
return r;
}
adev->ib_pool_ready = true;
if (amdgpu_debugfs_sa_init(adev)) {
dev_err(adev->dev, "failed to register debugfs file for SA\n");
}
return 0;
}
void amdgpu_ib_pool_fini(struct amdgpu_device *adev)
{
if (adev->ib_pool_ready) {
amdgpu_sa_bo_manager_suspend(adev, &adev->ring_tmp_bo);
amdgpu_sa_bo_manager_fini(adev, &adev->ring_tmp_bo);
adev->ib_pool_ready = false;
}
}
int amdgpu_ib_ring_tests(struct amdgpu_device *adev)
{
unsigned i;
int r;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->ready)
continue;
r = amdgpu_ring_test_ib(ring);
if (r) {
ring->ready = false;
if (ring == &adev->gfx.gfx_ring[0]) {
DRM_ERROR("amdgpu: failed testing IB on GFX ring (%d).\n", r);
adev->accel_working = false;
return r;
} else {
DRM_ERROR("amdgpu: failed testing IB on ring %d (%d).\n", i, r);
}
}
}
return 0;
}
static int amdgpu_debugfs_sa_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct amdgpu_device *adev = dev->dev_private;
amdgpu_sa_bo_dump_debug_info(&adev->ring_tmp_bo, m);
return 0;
}
static int amdgpu_debugfs_sa_init(struct amdgpu_device *adev)
{
#if defined(CONFIG_DEBUG_FS)
return amdgpu_debugfs_add_files(adev, amdgpu_debugfs_sa_list, 1);
#else
return 0;
#endif
}
