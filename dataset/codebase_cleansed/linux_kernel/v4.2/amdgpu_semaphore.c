int amdgpu_semaphore_create(struct amdgpu_device *adev,
struct amdgpu_semaphore **semaphore)
{
int r;
*semaphore = kmalloc(sizeof(struct amdgpu_semaphore), GFP_KERNEL);
if (*semaphore == NULL) {
return -ENOMEM;
}
r = amdgpu_sa_bo_new(adev, &adev->ring_tmp_bo,
&(*semaphore)->sa_bo, 8, 8);
if (r) {
kfree(*semaphore);
*semaphore = NULL;
return r;
}
(*semaphore)->waiters = 0;
(*semaphore)->gpu_addr = amdgpu_sa_bo_gpu_addr((*semaphore)->sa_bo);
*((uint64_t *)amdgpu_sa_bo_cpu_addr((*semaphore)->sa_bo)) = 0;
return 0;
}
bool amdgpu_semaphore_emit_signal(struct amdgpu_ring *ring,
struct amdgpu_semaphore *semaphore)
{
trace_amdgpu_semaphore_signale(ring->idx, semaphore);
if (amdgpu_ring_emit_semaphore(ring, semaphore, false)) {
--semaphore->waiters;
ring->last_semaphore_signal_addr = semaphore->gpu_addr;
return true;
}
return false;
}
bool amdgpu_semaphore_emit_wait(struct amdgpu_ring *ring,
struct amdgpu_semaphore *semaphore)
{
trace_amdgpu_semaphore_wait(ring->idx, semaphore);
if (amdgpu_ring_emit_semaphore(ring, semaphore, true)) {
++semaphore->waiters;
ring->last_semaphore_wait_addr = semaphore->gpu_addr;
return true;
}
return false;
}
void amdgpu_semaphore_free(struct amdgpu_device *adev,
struct amdgpu_semaphore **semaphore,
struct amdgpu_fence *fence)
{
if (semaphore == NULL || *semaphore == NULL) {
return;
}
if ((*semaphore)->waiters > 0) {
dev_err(adev->dev, "semaphore %p has more waiters than signalers,"
" hardware lockup imminent!\n", *semaphore);
}
amdgpu_sa_bo_free(adev, &(*semaphore)->sa_bo, fence);
kfree(*semaphore);
*semaphore = NULL;
}
