int radeon_ib_get(struct radeon_device *rdev, int ring,
struct radeon_ib *ib, struct radeon_vm *vm,
unsigned size)
{
int r;
r = radeon_sa_bo_new(rdev, &rdev->ring_tmp_bo, &ib->sa_bo, size, 256);
if (r) {
dev_err(rdev->dev, "failed to get a new IB (%d)\n", r);
return r;
}
r = radeon_semaphore_create(rdev, &ib->semaphore);
if (r) {
return r;
}
ib->ring = ring;
ib->fence = NULL;
ib->ptr = radeon_sa_bo_cpu_addr(ib->sa_bo);
ib->vm = vm;
if (vm) {
ib->gpu_addr = ib->sa_bo->soffset + RADEON_VA_IB_OFFSET;
} else {
ib->gpu_addr = radeon_sa_bo_gpu_addr(ib->sa_bo);
}
ib->is_const_ib = false;
return 0;
}
void radeon_ib_free(struct radeon_device *rdev, struct radeon_ib *ib)
{
radeon_semaphore_free(rdev, &ib->semaphore, ib->fence);
radeon_sa_bo_free(rdev, &ib->sa_bo, ib->fence);
radeon_fence_unref(&ib->fence);
}
int radeon_ib_schedule(struct radeon_device *rdev, struct radeon_ib *ib,
struct radeon_ib *const_ib, bool hdp_flush)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
int r = 0;
if (!ib->length_dw || !ring->ready) {
dev_err(rdev->dev, "couldn't schedule ib\n");
return -EINVAL;
}
r = radeon_ring_lock(rdev, ring, 64 + RADEON_NUM_SYNCS * 8);
if (r) {
dev_err(rdev->dev, "scheduling IB failed (%d).\n", r);
return r;
}
if (ib->vm) {
struct radeon_fence *vm_id_fence;
vm_id_fence = radeon_vm_grab_id(rdev, ib->vm, ib->ring);
radeon_semaphore_sync_fence(ib->semaphore, vm_id_fence);
}
r = radeon_semaphore_sync_rings(rdev, ib->semaphore, ib->ring);
if (r) {
dev_err(rdev->dev, "failed to sync rings (%d)\n", r);
radeon_ring_unlock_undo(rdev, ring);
return r;
}
if (ib->vm)
radeon_vm_flush(rdev, ib->vm, ib->ring);
if (const_ib) {
radeon_ring_ib_execute(rdev, const_ib->ring, const_ib);
radeon_semaphore_free(rdev, &const_ib->semaphore, NULL);
}
radeon_ring_ib_execute(rdev, ib->ring, ib);
r = radeon_fence_emit(rdev, &ib->fence, ib->ring);
if (r) {
dev_err(rdev->dev, "failed to emit fence for new IB (%d)\n", r);
radeon_ring_unlock_undo(rdev, ring);
return r;
}
if (const_ib) {
const_ib->fence = radeon_fence_ref(ib->fence);
}
if (ib->vm)
radeon_vm_fence(rdev, ib->vm, ib->fence);
radeon_ring_unlock_commit(rdev, ring, hdp_flush);
return 0;
}
int radeon_ib_pool_init(struct radeon_device *rdev)
{
int r;
if (rdev->ib_pool_ready) {
return 0;
}
if (rdev->family >= CHIP_BONAIRE) {
r = radeon_sa_bo_manager_init(rdev, &rdev->ring_tmp_bo,
RADEON_IB_POOL_SIZE*64*1024,
RADEON_GPU_PAGE_SIZE,
RADEON_GEM_DOMAIN_GTT,
RADEON_GEM_GTT_WC);
} else {
r = radeon_sa_bo_manager_init(rdev, &rdev->ring_tmp_bo,
RADEON_IB_POOL_SIZE*64*1024,
RADEON_GPU_PAGE_SIZE,
RADEON_GEM_DOMAIN_GTT, 0);
}
if (r) {
return r;
}
r = radeon_sa_bo_manager_start(rdev, &rdev->ring_tmp_bo);
if (r) {
return r;
}
rdev->ib_pool_ready = true;
if (radeon_debugfs_sa_init(rdev)) {
dev_err(rdev->dev, "failed to register debugfs file for SA\n");
}
return 0;
}
void radeon_ib_pool_fini(struct radeon_device *rdev)
{
if (rdev->ib_pool_ready) {
radeon_sa_bo_manager_suspend(rdev, &rdev->ring_tmp_bo);
radeon_sa_bo_manager_fini(rdev, &rdev->ring_tmp_bo);
rdev->ib_pool_ready = false;
}
}
int radeon_ib_ring_tests(struct radeon_device *rdev)
{
unsigned i;
int r;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
struct radeon_ring *ring = &rdev->ring[i];
if (!ring->ready)
continue;
r = radeon_ib_test(rdev, i, ring);
if (r) {
radeon_fence_driver_force_completion(rdev, i);
ring->ready = false;
rdev->needs_reset = false;
if (i == RADEON_RING_TYPE_GFX_INDEX) {
DRM_ERROR("radeon: failed testing IB on GFX ring (%d).\n", r);
rdev->accel_working = false;
return r;
} else {
DRM_ERROR("radeon: failed testing IB on ring %d (%d).\n", i, r);
}
}
}
return 0;
}
static int radeon_debugfs_sa_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct radeon_device *rdev = dev->dev_private;
radeon_sa_bo_dump_debug_info(&rdev->ring_tmp_bo, m);
return 0;
}
static int radeon_debugfs_sa_init(struct radeon_device *rdev)
{
#if defined(CONFIG_DEBUG_FS)
return radeon_debugfs_add_files(rdev, radeon_debugfs_sa_list, 1);
#else
return 0;
#endif
}
