void amdgpu_sync_create(struct amdgpu_sync *sync)
{
hash_init(sync->fences);
sync->last_vm_update = NULL;
}
static bool amdgpu_sync_same_dev(struct amdgpu_device *adev,
struct dma_fence *f)
{
struct amd_sched_fence *s_fence = to_amd_sched_fence(f);
if (s_fence) {
struct amdgpu_ring *ring;
ring = container_of(s_fence->sched, struct amdgpu_ring, sched);
return ring->adev == adev;
}
return false;
}
static void *amdgpu_sync_get_owner(struct dma_fence *f)
{
struct amd_sched_fence *s_fence = to_amd_sched_fence(f);
if (s_fence)
return s_fence->owner;
return AMDGPU_FENCE_OWNER_UNDEFINED;
}
static void amdgpu_sync_keep_later(struct dma_fence **keep,
struct dma_fence *fence)
{
if (*keep && dma_fence_is_later(*keep, fence))
return;
dma_fence_put(*keep);
*keep = dma_fence_get(fence);
}
static bool amdgpu_sync_add_later(struct amdgpu_sync *sync, struct dma_fence *f)
{
struct amdgpu_sync_entry *e;
hash_for_each_possible(sync->fences, e, node, f->context) {
if (unlikely(e->fence->context != f->context))
continue;
amdgpu_sync_keep_later(&e->fence, f);
return true;
}
return false;
}
int amdgpu_sync_fence(struct amdgpu_device *adev, struct amdgpu_sync *sync,
struct dma_fence *f)
{
struct amdgpu_sync_entry *e;
if (!f)
return 0;
if (amdgpu_sync_same_dev(adev, f) &&
amdgpu_sync_get_owner(f) == AMDGPU_FENCE_OWNER_VM)
amdgpu_sync_keep_later(&sync->last_vm_update, f);
if (amdgpu_sync_add_later(sync, f))
return 0;
e = kmem_cache_alloc(amdgpu_sync_slab, GFP_KERNEL);
if (!e)
return -ENOMEM;
hash_add(sync->fences, &e->node, f->context);
e->fence = dma_fence_get(f);
return 0;
}
int amdgpu_sync_resv(struct amdgpu_device *adev,
struct amdgpu_sync *sync,
struct reservation_object *resv,
void *owner)
{
struct reservation_object_list *flist;
struct dma_fence *f;
void *fence_owner;
unsigned i;
int r = 0;
if (resv == NULL)
return -EINVAL;
f = reservation_object_get_excl(resv);
r = amdgpu_sync_fence(adev, sync, f);
flist = reservation_object_get_list(resv);
if (!flist || r)
return r;
for (i = 0; i < flist->shared_count; ++i) {
f = rcu_dereference_protected(flist->shared[i],
reservation_object_held(resv));
if (amdgpu_sync_same_dev(adev, f)) {
fence_owner = amdgpu_sync_get_owner(f);
if ((owner != AMDGPU_FENCE_OWNER_UNDEFINED) &&
(fence_owner != AMDGPU_FENCE_OWNER_UNDEFINED) &&
((owner == AMDGPU_FENCE_OWNER_VM) !=
(fence_owner == AMDGPU_FENCE_OWNER_VM)))
continue;
if (owner != AMDGPU_FENCE_OWNER_UNDEFINED &&
fence_owner == owner)
continue;
}
r = amdgpu_sync_fence(adev, sync, f);
if (r)
break;
}
return r;
}
struct dma_fence *amdgpu_sync_peek_fence(struct amdgpu_sync *sync,
struct amdgpu_ring *ring)
{
struct amdgpu_sync_entry *e;
struct hlist_node *tmp;
int i;
hash_for_each_safe(sync->fences, i, tmp, e, node) {
struct dma_fence *f = e->fence;
struct amd_sched_fence *s_fence = to_amd_sched_fence(f);
if (ring && s_fence) {
if (s_fence->sched == &ring->sched) {
if (dma_fence_is_signaled(&s_fence->scheduled))
continue;
return &s_fence->scheduled;
}
}
if (dma_fence_is_signaled(f)) {
hash_del(&e->node);
dma_fence_put(f);
kmem_cache_free(amdgpu_sync_slab, e);
continue;
}
return f;
}
return NULL;
}
struct dma_fence *amdgpu_sync_get_fence(struct amdgpu_sync *sync)
{
struct amdgpu_sync_entry *e;
struct hlist_node *tmp;
struct dma_fence *f;
int i;
hash_for_each_safe(sync->fences, i, tmp, e, node) {
f = e->fence;
hash_del(&e->node);
kmem_cache_free(amdgpu_sync_slab, e);
if (!dma_fence_is_signaled(f))
return f;
dma_fence_put(f);
}
return NULL;
}
void amdgpu_sync_free(struct amdgpu_sync *sync)
{
struct amdgpu_sync_entry *e;
struct hlist_node *tmp;
unsigned i;
hash_for_each_safe(sync->fences, i, tmp, e, node) {
hash_del(&e->node);
dma_fence_put(e->fence);
kmem_cache_free(amdgpu_sync_slab, e);
}
dma_fence_put(sync->last_vm_update);
}
int amdgpu_sync_init(void)
{
amdgpu_sync_slab = kmem_cache_create(
"amdgpu_sync", sizeof(struct amdgpu_sync_entry), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!amdgpu_sync_slab)
return -ENOMEM;
return 0;
}
void amdgpu_sync_fini(void)
{
kmem_cache_destroy(amdgpu_sync_slab);
}
