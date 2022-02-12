int radeon_semaphore_create(struct radeon_device *rdev,
struct radeon_semaphore **semaphore)
{
int r;
*semaphore = kmalloc(sizeof(struct radeon_semaphore), GFP_KERNEL);
if (*semaphore == NULL) {
return -ENOMEM;
}
r = radeon_sa_bo_new(rdev, &rdev->ring_tmp_bo,
&(*semaphore)->sa_bo, 8, 8);
if (r) {
kfree(*semaphore);
*semaphore = NULL;
return r;
}
(*semaphore)->waiters = 0;
(*semaphore)->gpu_addr = radeon_sa_bo_gpu_addr((*semaphore)->sa_bo);
*((uint64_t *)radeon_sa_bo_cpu_addr((*semaphore)->sa_bo)) = 0;
return 0;
}
bool radeon_semaphore_emit_signal(struct radeon_device *rdev, int ridx,
struct radeon_semaphore *semaphore)
{
struct radeon_ring *ring = &rdev->ring[ridx];
trace_radeon_semaphore_signale(ridx, semaphore);
if (radeon_semaphore_ring_emit(rdev, ridx, ring, semaphore, false)) {
--semaphore->waiters;
ring->last_semaphore_signal_addr = semaphore->gpu_addr;
return true;
}
return false;
}
bool radeon_semaphore_emit_wait(struct radeon_device *rdev, int ridx,
struct radeon_semaphore *semaphore)
{
struct radeon_ring *ring = &rdev->ring[ridx];
trace_radeon_semaphore_wait(ridx, semaphore);
if (radeon_semaphore_ring_emit(rdev, ridx, ring, semaphore, true)) {
++semaphore->waiters;
ring->last_semaphore_wait_addr = semaphore->gpu_addr;
return true;
}
return false;
}
void radeon_semaphore_free(struct radeon_device *rdev,
struct radeon_semaphore **semaphore,
struct radeon_fence *fence)
{
if (semaphore == NULL || *semaphore == NULL) {
return;
}
if ((*semaphore)->waiters > 0) {
dev_err(rdev->dev, "semaphore %p has more waiters than signalers,"
" hardware lockup imminent!\n", *semaphore);
}
radeon_sa_bo_free(rdev, &(*semaphore)->sa_bo, fence);
kfree(*semaphore);
*semaphore = NULL;
}
