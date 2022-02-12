int amdgpu_ib_get(struct amdgpu_ring *ring, struct amdgpu_vm *vm,
unsigned size, struct amdgpu_ib *ib)
{
struct amdgpu_device *adev = ring->adev;
int r;
if (size) {
r = amdgpu_sa_bo_new(adev, &adev->ring_tmp_bo,
&ib->sa_bo, size, 256);
if (r) {
dev_err(adev->dev, "failed to get a new IB (%d)\n", r);
return r;
}
ib->ptr = amdgpu_sa_bo_cpu_addr(ib->sa_bo);
if (!vm)
ib->gpu_addr = amdgpu_sa_bo_gpu_addr(ib->sa_bo);
}
amdgpu_sync_create(&ib->sync);
ib->ring = ring;
ib->vm = vm;
return 0;
}
void amdgpu_ib_free(struct amdgpu_device *adev, struct amdgpu_ib *ib)
{
amdgpu_sync_free(adev, &ib->sync, &ib->fence->base);
amdgpu_sa_bo_free(adev, &ib->sa_bo, &ib->fence->base);
amdgpu_fence_unref(&ib->fence);
}
int amdgpu_ib_schedule(struct amdgpu_device *adev, unsigned num_ibs,
struct amdgpu_ib *ibs, void *owner)
{
struct amdgpu_ib *ib = &ibs[0];
struct amdgpu_ring *ring;
struct amdgpu_ctx *ctx, *old_ctx;
struct amdgpu_vm *vm;
unsigned i;
int r = 0;
if (num_ibs == 0)
return -EINVAL;
ring = ibs->ring;
ctx = ibs->ctx;
vm = ibs->vm;
if (!ring->ready) {
dev_err(adev->dev, "couldn't schedule ib\n");
return -EINVAL;
}
r = amdgpu_sync_wait(&ibs->sync);
if (r) {
dev_err(adev->dev, "IB sync failed (%d).\n", r);
return r;
}
r = amdgpu_ring_lock(ring, (256 + AMDGPU_NUM_SYNCS * 8) * num_ibs);
if (r) {
dev_err(adev->dev, "scheduling IB failed (%d).\n", r);
return r;
}
if (vm) {
r = amdgpu_vm_grab_id(ibs->vm, ibs->ring, &ibs->sync);
if (r) {
amdgpu_ring_unlock_undo(ring);
return r;
}
}
r = amdgpu_sync_rings(&ibs->sync, ring);
if (r) {
amdgpu_ring_unlock_undo(ring);
dev_err(adev->dev, "failed to sync rings (%d)\n", r);
return r;
}
if (vm) {
amdgpu_vm_flush(ring, vm, ib->sync.last_vm_update);
if (ring->funcs->emit_gds_switch)
amdgpu_ring_emit_gds_switch(ring, ib->vm->ids[ring->idx].id,
ib->gds_base, ib->gds_size,
ib->gws_base, ib->gws_size,
ib->oa_base, ib->oa_size);
if (ring->funcs->emit_hdp_flush)
amdgpu_ring_emit_hdp_flush(ring);
}
old_ctx = ring->current_ctx;
for (i = 0; i < num_ibs; ++i) {
ib = &ibs[i];
if (ib->ring != ring || ib->ctx != ctx || ib->vm != vm) {
ring->current_ctx = old_ctx;
amdgpu_ring_unlock_undo(ring);
return -EINVAL;
}
amdgpu_ring_emit_ib(ring, ib);
ring->current_ctx = ctx;
}
r = amdgpu_fence_emit(ring, owner, &ib->fence);
if (r) {
dev_err(adev->dev, "failed to emit fence (%d)\n", r);
ring->current_ctx = old_ctx;
amdgpu_ring_unlock_undo(ring);
return r;
}
if (!amdgpu_enable_scheduler && ib->ctx)
ib->sequence = amdgpu_ctx_add_fence(ib->ctx, ring,
&ib->fence->base);
if (ib->user) {
uint64_t addr = amdgpu_bo_gpu_offset(ib->user->bo);
addr += ib->user->offset;
amdgpu_ring_emit_fence(ring, addr, ib->sequence,
AMDGPU_FENCE_FLAG_64BIT);
}
if (ib->vm)
amdgpu_vm_fence(adev, ib->vm, ib->fence);
amdgpu_ring_unlock_commit(ring);
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
adev->needs_reset = false;
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
