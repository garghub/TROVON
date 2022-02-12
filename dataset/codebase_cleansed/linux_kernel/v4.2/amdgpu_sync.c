void amdgpu_sync_create(struct amdgpu_sync *sync)
{
unsigned i;
for (i = 0; i < AMDGPU_NUM_SYNCS; ++i)
sync->semaphores[i] = NULL;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i)
sync->sync_to[i] = NULL;
sync->last_vm_update = NULL;
}
void amdgpu_sync_fence(struct amdgpu_sync *sync,
struct amdgpu_fence *fence)
{
struct amdgpu_fence *other;
if (!fence)
return;
other = sync->sync_to[fence->ring->idx];
sync->sync_to[fence->ring->idx] = amdgpu_fence_ref(
amdgpu_fence_later(fence, other));
amdgpu_fence_unref(&other);
if (fence->owner == AMDGPU_FENCE_OWNER_VM) {
other = sync->last_vm_update;
sync->last_vm_update = amdgpu_fence_ref(
amdgpu_fence_later(fence, other));
amdgpu_fence_unref(&other);
}
}
int amdgpu_sync_resv(struct amdgpu_device *adev,
struct amdgpu_sync *sync,
struct reservation_object *resv,
void *owner)
{
struct reservation_object_list *flist;
struct fence *f;
struct amdgpu_fence *fence;
unsigned i;
int r = 0;
if (resv == NULL)
return -EINVAL;
f = reservation_object_get_excl(resv);
fence = f ? to_amdgpu_fence(f) : NULL;
if (fence && fence->ring->adev == adev)
amdgpu_sync_fence(sync, fence);
else if (f)
r = fence_wait(f, true);
flist = reservation_object_get_list(resv);
if (!flist || r)
return r;
for (i = 0; i < flist->shared_count; ++i) {
f = rcu_dereference_protected(flist->shared[i],
reservation_object_held(resv));
fence = f ? to_amdgpu_fence(f) : NULL;
if (fence && fence->ring->adev == adev) {
if (fence->owner != owner ||
fence->owner == AMDGPU_FENCE_OWNER_UNDEFINED)
amdgpu_sync_fence(sync, fence);
} else if (f) {
r = fence_wait(f, true);
if (r)
break;
}
}
return r;
}
int amdgpu_sync_rings(struct amdgpu_sync *sync,
struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
unsigned count = 0;
int i, r;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_fence *fence = sync->sync_to[i];
struct amdgpu_semaphore *semaphore;
struct amdgpu_ring *other = adev->rings[i];
if (!amdgpu_fence_need_sync(fence, ring))
continue;
if (!other->ready) {
dev_err(adev->dev, "Syncing to a disabled ring!");
return -EINVAL;
}
if (count >= AMDGPU_NUM_SYNCS) {
r = amdgpu_fence_wait(fence, false);
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
r = amdgpu_fence_wait(fence, false);
if (r)
return r;
continue;
}
if (!amdgpu_semaphore_emit_wait(ring, semaphore)) {
amdgpu_ring_undo(other);
r = amdgpu_fence_wait(fence, false);
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
struct amdgpu_fence *fence)
{
unsigned i;
for (i = 0; i < AMDGPU_NUM_SYNCS; ++i)
amdgpu_semaphore_free(adev, &sync->semaphores[i], fence);
for (i = 0; i < AMDGPU_MAX_RINGS; ++i)
amdgpu_fence_unref(&sync->sync_to[i]);
amdgpu_fence_unref(&sync->last_vm_update);
}
