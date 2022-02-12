static void amdgpu_job_timedout(struct amd_sched_job *s_job)
{
struct amdgpu_job *job = container_of(s_job, struct amdgpu_job, base);
DRM_ERROR("ring %s timeout, last signaled seq=%u, last emitted seq=%u\n",
job->base.sched->name,
atomic_read(&job->ring->fence_drv.last_seq),
job->ring->fence_drv.sync_seq);
amdgpu_gpu_reset(job->adev);
}
int amdgpu_job_alloc(struct amdgpu_device *adev, unsigned num_ibs,
struct amdgpu_job **job, struct amdgpu_vm *vm)
{
size_t size = sizeof(struct amdgpu_job);
if (num_ibs == 0)
return -EINVAL;
size += sizeof(struct amdgpu_ib) * num_ibs;
*job = kzalloc(size, GFP_KERNEL);
if (!*job)
return -ENOMEM;
(*job)->adev = adev;
(*job)->vm = vm;
(*job)->ibs = (void *)&(*job)[1];
(*job)->num_ibs = num_ibs;
amdgpu_sync_create(&(*job)->sync);
return 0;
}
int amdgpu_job_alloc_with_ib(struct amdgpu_device *adev, unsigned size,
struct amdgpu_job **job)
{
int r;
r = amdgpu_job_alloc(adev, 1, job, NULL);
if (r)
return r;
r = amdgpu_ib_get(adev, NULL, size, &(*job)->ibs[0]);
if (r)
kfree(*job);
return r;
}
void amdgpu_job_free_resources(struct amdgpu_job *job)
{
struct fence *f;
unsigned i;
f = job->base.s_fence ? &job->base.s_fence->finished : job->fence;
for (i = 0; i < job->num_ibs; ++i)
amdgpu_ib_free(job->adev, &job->ibs[i], f);
}
static void amdgpu_job_free_cb(struct amd_sched_job *s_job)
{
struct amdgpu_job *job = container_of(s_job, struct amdgpu_job, base);
fence_put(job->fence);
amdgpu_sync_free(&job->sync);
kfree(job);
}
void amdgpu_job_free(struct amdgpu_job *job)
{
amdgpu_job_free_resources(job);
fence_put(job->fence);
amdgpu_sync_free(&job->sync);
kfree(job);
}
int amdgpu_job_submit(struct amdgpu_job *job, struct amdgpu_ring *ring,
struct amd_sched_entity *entity, void *owner,
struct fence **f)
{
int r;
job->ring = ring;
if (!f)
return -EINVAL;
r = amd_sched_job_init(&job->base, &ring->sched, entity, owner);
if (r)
return r;
job->owner = owner;
job->fence_ctx = entity->fence_context;
*f = fence_get(&job->base.s_fence->finished);
amdgpu_job_free_resources(job);
amd_sched_entity_push_job(&job->base);
return 0;
}
static struct fence *amdgpu_job_dependency(struct amd_sched_job *sched_job)
{
struct amdgpu_job *job = to_amdgpu_job(sched_job);
struct amdgpu_vm *vm = job->vm;
struct fence *fence = amdgpu_sync_get_fence(&job->sync);
if (fence == NULL && vm && !job->vm_id) {
struct amdgpu_ring *ring = job->ring;
int r;
r = amdgpu_vm_grab_id(vm, ring, &job->sync,
&job->base.s_fence->finished,
job);
if (r)
DRM_ERROR("Error getting VM ID (%d)\n", r);
fence = amdgpu_sync_get_fence(&job->sync);
}
return fence;
}
static struct fence *amdgpu_job_run(struct amd_sched_job *sched_job)
{
struct fence *fence = NULL;
struct amdgpu_job *job;
int r;
if (!sched_job) {
DRM_ERROR("job is null\n");
return NULL;
}
job = to_amdgpu_job(sched_job);
BUG_ON(amdgpu_sync_peek_fence(&job->sync, NULL));
trace_amdgpu_sched_run_job(job);
r = amdgpu_ib_schedule(job->ring, job->num_ibs, job->ibs,
job->sync.last_vm_update, job, &fence);
if (r)
DRM_ERROR("Error scheduling IBs (%d)\n", r);
fence_put(job->fence);
job->fence = fence_get(fence);
amdgpu_job_free_resources(job);
return fence;
}
