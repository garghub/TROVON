struct amd_sched_fence *amd_sched_fence_create(struct amd_sched_entity *entity,
void *owner)
{
struct amd_sched_fence *fence = NULL;
unsigned seq;
fence = kmem_cache_zalloc(sched_fence_slab, GFP_KERNEL);
if (fence == NULL)
return NULL;
fence->owner = owner;
fence->sched = entity->sched;
spin_lock_init(&fence->lock);
seq = atomic_inc_return(&entity->fence_seq);
fence_init(&fence->scheduled, &amd_sched_fence_ops_scheduled,
&fence->lock, entity->fence_context, seq);
fence_init(&fence->finished, &amd_sched_fence_ops_finished,
&fence->lock, entity->fence_context + 1, seq);
return fence;
}
void amd_sched_fence_scheduled(struct amd_sched_fence *fence)
{
int ret = fence_signal(&fence->scheduled);
if (!ret)
FENCE_TRACE(&fence->scheduled, "signaled from irq context\n");
else
FENCE_TRACE(&fence->scheduled, "was already signaled\n");
}
void amd_sched_fence_finished(struct amd_sched_fence *fence)
{
int ret = fence_signal(&fence->finished);
if (!ret)
FENCE_TRACE(&fence->finished, "signaled from irq context\n");
else
FENCE_TRACE(&fence->finished, "was already signaled\n");
}
static const char *amd_sched_fence_get_driver_name(struct fence *fence)
{
return "amd_sched";
}
static const char *amd_sched_fence_get_timeline_name(struct fence *f)
{
struct amd_sched_fence *fence = to_amd_sched_fence(f);
return (const char *)fence->sched->name;
}
static bool amd_sched_fence_enable_signaling(struct fence *f)
{
return true;
}
static void amd_sched_fence_free(struct rcu_head *rcu)
{
struct fence *f = container_of(rcu, struct fence, rcu);
struct amd_sched_fence *fence = to_amd_sched_fence(f);
fence_put(fence->parent);
kmem_cache_free(sched_fence_slab, fence);
}
static void amd_sched_fence_release_scheduled(struct fence *f)
{
struct amd_sched_fence *fence = to_amd_sched_fence(f);
call_rcu(&fence->finished.rcu, amd_sched_fence_free);
}
static void amd_sched_fence_release_finished(struct fence *f)
{
struct amd_sched_fence *fence = to_amd_sched_fence(f);
fence_put(&fence->scheduled);
}
