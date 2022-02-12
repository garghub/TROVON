int radeon_semaphore_create(struct radeon_device *rdev,
struct radeon_semaphore **semaphore)
{
int r;
*semaphore = kmalloc(sizeof(struct radeon_semaphore), GFP_KERNEL);
if (*semaphore == NULL) {
return -ENOMEM;
}
r = radeon_sa_bo_new(rdev, &rdev->ring_tmp_bo,
&(*semaphore)->sa_bo, 8, 8, true);
if (r) {
kfree(*semaphore);
*semaphore = NULL;
return r;
}
(*semaphore)->waiters = 0;
(*semaphore)->gpu_addr = radeon_sa_bo_gpu_addr((*semaphore)->sa_bo);
*((uint64_t*)radeon_sa_bo_cpu_addr((*semaphore)->sa_bo)) = 0;
return 0;
}
void radeon_semaphore_emit_signal(struct radeon_device *rdev, int ring,
struct radeon_semaphore *semaphore)
{
--semaphore->waiters;
radeon_semaphore_ring_emit(rdev, ring, &rdev->ring[ring], semaphore, false);
}
void radeon_semaphore_emit_wait(struct radeon_device *rdev, int ring,
struct radeon_semaphore *semaphore)
{
++semaphore->waiters;
radeon_semaphore_ring_emit(rdev, ring, &rdev->ring[ring], semaphore, true);
}
int radeon_semaphore_sync_rings(struct radeon_device *rdev,
struct radeon_semaphore *semaphore,
bool sync_to[RADEON_NUM_RINGS],
int dst_ring)
{
int i = 0, r;
mutex_lock(&rdev->ring_lock);
r = radeon_ring_alloc(rdev, &rdev->ring[dst_ring], RADEON_NUM_RINGS * 8);
if (r) {
goto error;
}
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (!sync_to[i] || i == dst_ring)
continue;
if (!rdev->ring[i].ready) {
dev_err(rdev->dev, "Trying to sync to a disabled ring!");
r = -EINVAL;
goto error;
}
r = radeon_ring_alloc(rdev, &rdev->ring[i], 8);
if (r) {
goto error;
}
radeon_semaphore_emit_signal(rdev, i, semaphore);
radeon_semaphore_emit_wait(rdev, dst_ring, semaphore);
radeon_ring_commit(rdev, &rdev->ring[i]);
}
radeon_ring_commit(rdev, &rdev->ring[dst_ring]);
mutex_unlock(&rdev->ring_lock);
return 0;
error:
for (--i; i >= 0; --i) {
if (sync_to[i] || i == dst_ring) {
radeon_ring_undo(&rdev->ring[i]);
}
}
radeon_ring_undo(&rdev->ring[dst_ring]);
mutex_unlock(&rdev->ring_lock);
return r;
}
void radeon_semaphore_free(struct radeon_device *rdev,
struct radeon_semaphore *semaphore,
struct radeon_fence *fence)
{
if (semaphore == NULL) {
return;
}
if (semaphore->waiters > 0) {
dev_err(rdev->dev, "semaphore %p has more waiters than signalers,"
" hardware lockup imminent!\n", semaphore);
}
radeon_sa_bo_free(rdev, &semaphore->sa_bo, fence);
kfree(semaphore);
}
