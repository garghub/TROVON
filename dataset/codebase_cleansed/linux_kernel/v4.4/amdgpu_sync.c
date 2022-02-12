void amdgpu_sync_create(struct amdgpu_sync *sync)
{
unsigned i;
for (i = 0; i < AMDGPU_NUM_SYNCS; ++i)
sync->semaphores[i] = NULL;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i)
sync->sync_to[i] = NULL;
hash_init(sync->fences);
sync->last_vm_update = NULL;
}
static bool amdgpu_sync_same_dev(struct amdgpu_device *adev, struct fence *f)
{
struct amdgpu_fence *a_fence = to_amdgpu_fence(f);
struct amd_sched_fence *s_fence = to_amd_sched_fence(f);
if (a_fence)
return a_fence->ring->adev == adev;
if (s_fence) {
struct amdgpu_ring *ring;
ring = container_of(s_fence->sched, struct amdgpu_ring, sched);
return ring->adev == adev;
}
return false;
}
static bool amdgpu_sync_test_owner(struct fence *f, void *owner)
{
struct amdgpu_fence *a_fence = to_amdgpu_fence(f);
struct amd_sched_fence *s_fence = to_amd_sched_fence(f);
if (s_fence)
return s_fence->owner == owner;
if (a_fence)
return a_fence->owner == owner;
return false;
}
static void amdgpu_sync_keep_later(struct fence **keep, struct fence *fence)
{
if (*keep && fence_is_later(*keep, fence))
return;
fence_put(*keep);
*keep = fence_get(fence);
}
int amdgpu_sync_fence(struct amdgpu_device *adev, struct amdgpu_sync *sync,
struct fence *f)
{
struct amdgpu_sync_entry *e;
struct amdgpu_fence *fence;
if (!f)
return 0;
if (amdgpu_sync_same_dev(adev, f) &&
amdgpu_sync_test_owner(f, AMDGPU_FENCE_OWNER_VM))
amdgpu_sync_keep_later(&sync->last_vm_update, f);
fence = to_amdgpu_fence(f);
if (!fence || fence->ring->adev != adev) {
hash_for_each_possible(sync->fences, e, node, f->context) {
if (unlikely(e->fence->context != f->context))
continue;
amdgpu_sync_keep_later(&e->fence, f);
return 0;
}
e = kmalloc(sizeof(struct amdgpu_sync_entry), GFP_KERNEL);
if (!e)
return -ENOMEM;
hash_add(sync->fences, &e->node, f->context);
e->fence = fence_get(f);
return 0;
}
amdgpu_sync_keep_later(&sync->sync_to[fence->ring->idx], f);
return 0;
}
static void *amdgpu_sync_get_owner(struct fence *f)
{
struct amdgpu_fence *a_fence = to_amdgpu_fence(f);
struct amd_sched_fence *s_fence = to_amd_sched_fence(f);
if (s_fence)
return s_fence->owner;
else if (a_fence)
return a_fence->owner;
return AMDGPU_FENCE_OWNER_UNDEFINED;
}
int amdgpu_sync_resv(struct amdgpu_device *adev,
struct amdgpu_sync *sync,
struct reservation_object *resv,
void *owner)
{
struct reservation_object_list *flist;
struct fence *f;
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
struct fence *amdgpu_sync_get_fence(struct amdgpu_sync *sync)
{
struct amdgpu_sync_entry *e;
struct hlist_node *tmp;
struct fence *f;
int i;
hash_for_each_safe(sync->fences, i, tmp, e, node) {
f = e->fence;
hash_del(&e->node);
kfree(e);
if (!fence_is_signaled(f))
return f;
fence_put(f);
}
return NULL;
}
int amdgpu_sync_wait(struct amdgpu_sync *sync)
{
struct amdgpu_sync_entry *e;
struct hlist_node *tmp;
int i, r;
hash_for_each_safe(sync->fences, i, tmp, e, node) {
r = fence_wait(e->fence, false);
if (r)
return r;
hash_del(&e->node);
fence_put(e->fence);
kfree(e);
}
if (amdgpu_enable_semaphores)
return 0;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct fence *fence = sync->sync_to[i];
if (!fence)
continue;
r = fence_wait(fence, false);
if (r)
return r;
}
return 0;
}
int amdgpu_sync_rings(struct amdgpu_sync *sync,
struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
unsigned count = 0;
int i, r;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *other = adev->rings[i];
struct amdgpu_semaphore *semaphore;
struct amdgpu_fence *fence;
if (!sync->sync_to[i])
continue;
fence = to_amdgpu_fence(sync->sync_to[i]);
if (!amdgpu_fence_need_sync(fence, ring))
continue;
if (!other->ready) {
dev_err(adev->dev, "Syncing to a disabled ring!");
return -EINVAL;
}
if (amdgpu_enable_scheduler || !amdgpu_enable_semaphores) {
r = fence_wait(&fence->base, true);
if (r)
return r;
continue;
}
if (count >= AMDGPU_NUM_SYNCS) {
r = fence_wait(&fence->base, false);
if (r)
return r;
continue;
}
r = amdgpu_semaphore_create(adev, &semaphore);
if (r)
return r;
sync->semaphores[count++] = semaphore;
r = amdgpu_ring_alloc(other, 16);
if (r)
return r;
if (!amdgpu_semaphore_emit_signal(other, semaphore)) {
amdgpu_ring_undo(other);
r = fence_wait(&fence->base, false);
if (r)
return r;
continue;
}
if (!amdgpu_semaphore_emit_wait(ring, semaphore)) {
amdgpu_ring_undo(other);
r = fence_wait(&fence->base, false);
if (r)
return r;
continue;
}
amdgpu_ring_commit(other);
amdgpu_fence_note_sync(fence, ring);
}
return 0;
}
void amdgpu_sync_free(struct amdgpu_device *adev,
struct amdgpu_sync *sync,
struct fence *fence)
{
struct amdgpu_sync_entry *e;
struct hlist_node *tmp;
unsigned i;
hash_for_each_safe(sync->fences, i, tmp, e, node) {
hash_del(&e->node);
fence_put(e->fence);
kfree(e);
}
for (i = 0; i < AMDGPU_NUM_SYNCS; ++i)
amdgpu_semaphore_free(adev, &sync->semaphores[i], fence);
for (i = 0; i < AMDGPU_MAX_RINGS; ++i)
fence_put(sync->sync_to[i]);
fence_put(sync->last_vm_update);
}
