int amd_sched_fence_slab_init(void)
{
sched_fence_slab = kmem_cache_create(
"amd_sched_fence", sizeof(struct amd_sched_fence), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!sched_fence_slab)
return -ENOMEM;
return 0;
}
void amd_sched_fence_slab_fini(void)
{
rcu_barrier();
kmem_cache_destroy(sched_fence_slab);
}
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
dma_fence_init(&fence->scheduled, &amd_sched_fence_ops_scheduled,
&fence->lock, entity->fence_context, seq);
dma_fence_init(&fence->finished, &amd_sched_fence_ops_finished,
&fence->lock, entity->fence_context + 1, seq);
return fence;
}
void amd_sched_fence_scheduled(struct amd_sched_fence *fence)
{
int ret = dma_fence_signal(&fence->scheduled);
if (!ret)
DMA_FENCE_TRACE(&fence->scheduled,
"signaled from irq context\n");
else
DMA_FENCE_TRACE(&fence->scheduled,
"was already signaled\n");
}
void amd_sched_fence_finished(struct amd_sched_fence *fence)
{
int ret = dma_fence_signal(&fence->finished);
if (!ret)
DMA_FENCE_TRACE(&fence->finished,
"signaled from irq context\n");
else
DMA_FENCE_TRACE(&fence->finished,
"was already signaled\n");
}
static const char *amd_sched_fence_get_driver_name(struct dma_fence *fence)
{
return "amd_sched";
}
static const char *amd_sched_fence_get_timeline_name(struct dma_fence *f)
{
struct amd_sched_fence *fence = to_amd_sched_fence(f);
return (const char *)fence->sched->name;
}
static bool amd_sched_fence_enable_signaling(struct dma_fence *f)
{
return true;
}
static void amd_sched_fence_free(struct rcu_head *rcu)
{
struct dma_fence *f = container_of(rcu, struct dma_fence, rcu);
struct amd_sched_fence *fence = to_amd_sched_fence(f);
dma_fence_put(fence->parent);
kmem_cache_free(sched_fence_slab, fence);
}
static void amd_sched_fence_release_scheduled(struct dma_fence *f)
{
struct amd_sched_fence *fence = to_amd_sched_fence(f);
call_rcu(&fence->finished.rcu, amd_sched_fence_free);
}
static void amd_sched_fence_release_finished(struct dma_fence *f)
{
struct amd_sched_fence *fence = to_amd_sched_fence(f);
dma_fence_put(&fence->scheduled);
}
