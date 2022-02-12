void radeon_sync_create(struct radeon_sync *sync)
{
unsigned i;
for (i = 0; i < RADEON_NUM_SYNCS; ++i)
sync->semaphores[i] = NULL;
for (i = 0; i < RADEON_NUM_RINGS; ++i)
sync->sync_to[i] = NULL;
sync->last_vm_update = NULL;
}
void radeon_sync_fence(struct radeon_sync *sync,
struct radeon_fence *fence)
{
struct radeon_fence *other;
if (!fence)
return;
other = sync->sync_to[fence->ring];
sync->sync_to[fence->ring] = radeon_fence_later(fence, other);
if (fence->is_vm_update) {
other = sync->last_vm_update;
sync->last_vm_update = radeon_fence_later(fence, other);
}
}
int radeon_sync_resv(struct radeon_device *rdev,
struct radeon_sync *sync,
struct reservation_object *resv,
bool shared)
{
struct reservation_object_list *flist;
struct dma_fence *f;
struct radeon_fence *fence;
unsigned i;
int r = 0;
f = reservation_object_get_excl(resv);
fence = f ? to_radeon_fence(f) : NULL;
if (fence && fence->rdev == rdev)
radeon_sync_fence(sync, fence);
else if (f)
r = dma_fence_wait(f, true);
flist = reservation_object_get_list(resv);
if (shared || !flist || r)
return r;
for (i = 0; i < flist->shared_count; ++i) {
f = rcu_dereference_protected(flist->shared[i],
reservation_object_held(resv));
fence = to_radeon_fence(f);
if (fence && fence->rdev == rdev)
radeon_sync_fence(sync, fence);
else
r = dma_fence_wait(f, true);
if (r)
break;
}
return r;
}
int radeon_sync_rings(struct radeon_device *rdev,
struct radeon_sync *sync,
int ring)
{
unsigned count = 0;
int i, r;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
struct radeon_fence *fence = sync->sync_to[i];
struct radeon_semaphore *semaphore;
if (!radeon_fence_need_sync(fence, ring))
continue;
if (!rdev->ring[i].ready) {
dev_err(rdev->dev, "Syncing to a disabled ring!");
return -EINVAL;
}
if (count >= RADEON_NUM_SYNCS) {
r = radeon_fence_wait(fence, false);
if (r)
return r;
continue;
}
r = radeon_semaphore_create(rdev, &semaphore);
if (r)
return r;
sync->semaphores[count++] = semaphore;
r = radeon_ring_alloc(rdev, &rdev->ring[i], 16);
if (r)
return r;
if (!radeon_semaphore_emit_signal(rdev, i, semaphore)) {
radeon_ring_undo(&rdev->ring[i]);
r = radeon_fence_wait(fence, false);
if (r)
return r;
continue;
}
if (!radeon_semaphore_emit_wait(rdev, ring, semaphore)) {
radeon_ring_undo(&rdev->ring[i]);
r = radeon_fence_wait(fence, false);
if (r)
return r;
continue;
}
radeon_ring_commit(rdev, &rdev->ring[i], false);
radeon_fence_note_sync(fence, ring);
}
return 0;
}
void radeon_sync_free(struct radeon_device *rdev,
struct radeon_sync *sync,
struct radeon_fence *fence)
{
unsigned i;
for (i = 0; i < RADEON_NUM_SYNCS; ++i)
radeon_semaphore_free(rdev, &sync->semaphores[i], fence);
}
