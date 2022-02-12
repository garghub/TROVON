struct amd_sched_fence *amd_sched_fence_create(struct amd_sched_entity *s_entity, void *owner)
{
struct amd_sched_fence *fence = NULL;
unsigned seq;
fence = kmem_cache_zalloc(sched_fence_slab, GFP_KERNEL);
if (fence == NULL)
return NULL;
INIT_LIST_HEAD(&fence->scheduled_cb);
fence->owner = owner;
fence->sched = s_entity->sched;
spin_lock_init(&fence->lock);
seq = atomic_inc_return(&s_entity->fence_seq);
fence_init(&fence->base, &amd_sched_fence_ops, &fence->lock,
s_entity->fence_context, seq);
return fence;
}
void amd_sched_fence_signal(struct amd_sched_fence *fence)
{
int ret = fence_signal(&fence->base);
if (!ret)
FENCE_TRACE(&fence->base, "signaled from irq context\n");
else
FENCE_TRACE(&fence->base, "was already signaled\n");
}
void amd_sched_fence_scheduled(struct amd_sched_fence *s_fence)
{
struct fence_cb *cur, *tmp;
set_bit(AMD_SCHED_FENCE_SCHEDULED_BIT, &s_fence->base.flags);
list_for_each_entry_safe(cur, tmp, &s_fence->scheduled_cb, node) {
list_del_init(&cur->node);
cur->func(&s_fence->base, cur);
}
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
static void amd_sched_fence_release(struct fence *f)
{
struct amd_sched_fence *fence = to_amd_sched_fence(f);
kmem_cache_free(sched_fence_slab, fence);
}
