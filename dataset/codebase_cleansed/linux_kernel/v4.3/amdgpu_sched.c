static struct fence *amdgpu_sched_dependency(struct amd_sched_job *sched_job)
{
struct amdgpu_job *job = to_amdgpu_job(sched_job);
return amdgpu_sync_get_fence(&job->ibs->sync);
}
static struct fence *amdgpu_sched_run_job(struct amd_sched_job *sched_job)
{
struct amdgpu_fence *fence = NULL;
struct amdgpu_job *job;
int r;
if (!sched_job) {
DRM_ERROR("job is null\n");
return NULL;
}
job = to_amdgpu_job(sched_job);
mutex_lock(&job->job_lock);
r = amdgpu_ib_schedule(job->adev,
job->num_ibs,
job->ibs,
job->base.owner);
if (r) {
DRM_ERROR("Error scheduling IBs (%d)\n", r);
goto err;
}
fence = amdgpu_fence_ref(job->ibs[job->num_ibs - 1].fence);
err:
if (job->free_job)
job->free_job(job);
mutex_unlock(&job->job_lock);
fence_put(&job->base.s_fence->base);
kfree(job);
return fence ? &fence->base : NULL;
}
int amdgpu_sched_ib_submit_kernel_helper(struct amdgpu_device *adev,
struct amdgpu_ring *ring,
struct amdgpu_ib *ibs,
unsigned num_ibs,
int (*free_job)(struct amdgpu_job *),
void *owner,
struct fence **f)
{
int r = 0;
if (amdgpu_enable_scheduler) {
struct amdgpu_job *job =
kzalloc(sizeof(struct amdgpu_job), GFP_KERNEL);
if (!job)
return -ENOMEM;
job->base.sched = &ring->sched;
job->base.s_entity = &adev->kernel_ctx.rings[ring->idx].entity;
job->adev = adev;
job->ibs = ibs;
job->num_ibs = num_ibs;
job->base.owner = owner;
mutex_init(&job->job_lock);
job->free_job = free_job;
mutex_lock(&job->job_lock);
r = amd_sched_entity_push_job(&job->base);
if (r) {
mutex_unlock(&job->job_lock);
kfree(job);
return r;
}
*f = fence_get(&job->base.s_fence->base);
mutex_unlock(&job->job_lock);
} else {
r = amdgpu_ib_schedule(adev, num_ibs, ibs, owner);
if (r)
return r;
*f = fence_get(&ibs[num_ibs - 1].fence->base);
}
return 0;
}
