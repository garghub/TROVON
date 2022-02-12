struct amd_sched_fence *amd_sched_fence_create(struct amd_sched_entity *s_entity, void *owner)
{
struct amd_sched_fence *fence = NULL;
unsigned seq;
fence = kzalloc(sizeof(struct amd_sched_fence), GFP_KERNEL);
if (fence == NULL)
return NULL;
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
