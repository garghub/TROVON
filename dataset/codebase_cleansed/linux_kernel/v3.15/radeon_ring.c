int radeon_ib_get(struct radeon_device *rdev, int ring,
struct radeon_ib *ib, struct radeon_vm *vm,
unsigned size)
{
int r;
r = radeon_sa_bo_new(rdev, &rdev->ring_tmp_bo, &ib->sa_bo, size, 256);
if (r) {
dev_err(rdev->dev, "failed to get a new IB (%d)\n", r);
return r;
}
r = radeon_semaphore_create(rdev, &ib->semaphore);
if (r) {
return r;
}
ib->ring = ring;
ib->fence = NULL;
ib->ptr = radeon_sa_bo_cpu_addr(ib->sa_bo);
ib->vm = vm;
if (vm) {
ib->gpu_addr = ib->sa_bo->soffset + RADEON_VA_IB_OFFSET;
} else {
ib->gpu_addr = radeon_sa_bo_gpu_addr(ib->sa_bo);
}
ib->is_const_ib = false;
return 0;
}
void radeon_ib_free(struct radeon_device *rdev, struct radeon_ib *ib)
{
radeon_semaphore_free(rdev, &ib->semaphore, ib->fence);
radeon_sa_bo_free(rdev, &ib->sa_bo, ib->fence);
radeon_fence_unref(&ib->fence);
}
int radeon_ib_schedule(struct radeon_device *rdev, struct radeon_ib *ib,
struct radeon_ib *const_ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
int r = 0;
if (!ib->length_dw || !ring->ready) {
dev_err(rdev->dev, "couldn't schedule ib\n");
return -EINVAL;
}
r = radeon_ring_lock(rdev, ring, 64 + RADEON_NUM_SYNCS * 8);
if (r) {
dev_err(rdev->dev, "scheduling IB failed (%d).\n", r);
return r;
}
if (ib->vm) {
struct radeon_fence *vm_id_fence;
vm_id_fence = radeon_vm_grab_id(rdev, ib->vm, ib->ring);
radeon_semaphore_sync_to(ib->semaphore, vm_id_fence);
}
r = radeon_semaphore_sync_rings(rdev, ib->semaphore, ib->ring);
if (r) {
dev_err(rdev->dev, "failed to sync rings (%d)\n", r);
radeon_ring_unlock_undo(rdev, ring);
return r;
}
if (ib->vm)
radeon_vm_flush(rdev, ib->vm, ib->ring);
if (const_ib) {
radeon_ring_ib_execute(rdev, const_ib->ring, const_ib);
radeon_semaphore_free(rdev, &const_ib->semaphore, NULL);
}
radeon_ring_ib_execute(rdev, ib->ring, ib);
r = radeon_fence_emit(rdev, &ib->fence, ib->ring);
if (r) {
dev_err(rdev->dev, "failed to emit fence for new IB (%d)\n", r);
radeon_ring_unlock_undo(rdev, ring);
return r;
}
if (const_ib) {
const_ib->fence = radeon_fence_ref(ib->fence);
}
if (ib->vm)
radeon_vm_fence(rdev, ib->vm, ib->fence);
radeon_ring_unlock_commit(rdev, ring);
return 0;
}
int radeon_ib_pool_init(struct radeon_device *rdev)
{
int r;
if (rdev->ib_pool_ready) {
return 0;
}
r = radeon_sa_bo_manager_init(rdev, &rdev->ring_tmp_bo,
RADEON_IB_POOL_SIZE*64*1024,
RADEON_GPU_PAGE_SIZE,
RADEON_GEM_DOMAIN_GTT);
if (r) {
return r;
}
r = radeon_sa_bo_manager_start(rdev, &rdev->ring_tmp_bo);
if (r) {
return r;
}
rdev->ib_pool_ready = true;
if (radeon_debugfs_sa_init(rdev)) {
dev_err(rdev->dev, "failed to register debugfs file for SA\n");
}
return 0;
}
void radeon_ib_pool_fini(struct radeon_device *rdev)
{
if (rdev->ib_pool_ready) {
radeon_sa_bo_manager_suspend(rdev, &rdev->ring_tmp_bo);
radeon_sa_bo_manager_fini(rdev, &rdev->ring_tmp_bo);
rdev->ib_pool_ready = false;
}
}
int radeon_ib_ring_tests(struct radeon_device *rdev)
{
unsigned i;
int r;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
struct radeon_ring *ring = &rdev->ring[i];
if (!ring->ready)
continue;
r = radeon_ib_test(rdev, i, ring);
if (r) {
ring->ready = false;
rdev->needs_reset = false;
if (i == RADEON_RING_TYPE_GFX_INDEX) {
DRM_ERROR("radeon: failed testing IB on GFX ring (%d).\n", r);
rdev->accel_working = false;
return r;
} else {
DRM_ERROR("radeon: failed testing IB on ring %d (%d).\n", i, r);
}
}
}
return 0;
}
void radeon_ring_write(struct radeon_ring *ring, uint32_t v)
{
#if DRM_DEBUG_CODE
if (ring->count_dw <= 0) {
DRM_ERROR("radeon: writing more dwords to the ring than expected!\n");
}
#endif
ring->ring[ring->wptr++] = v;
ring->wptr &= ring->ptr_mask;
ring->count_dw--;
ring->ring_free_dw--;
}
bool radeon_ring_supports_scratch_reg(struct radeon_device *rdev,
struct radeon_ring *ring)
{
switch (ring->idx) {
case RADEON_RING_TYPE_GFX_INDEX:
case CAYMAN_RING_TYPE_CP1_INDEX:
case CAYMAN_RING_TYPE_CP2_INDEX:
return true;
default:
return false;
}
}
void radeon_ring_free_size(struct radeon_device *rdev, struct radeon_ring *ring)
{
uint32_t rptr = radeon_ring_get_rptr(rdev, ring);
ring->ring_free_dw = rptr + (ring->ring_size / 4);
ring->ring_free_dw -= ring->wptr;
ring->ring_free_dw &= ring->ptr_mask;
if (!ring->ring_free_dw) {
ring->ring_free_dw = ring->ring_size / 4;
radeon_ring_lockup_update(rdev, ring);
}
}
int radeon_ring_alloc(struct radeon_device *rdev, struct radeon_ring *ring, unsigned ndw)
{
int r;
if (ndw > (ring->ring_size / 4))
return -ENOMEM;
radeon_ring_free_size(rdev, ring);
ndw = (ndw + ring->align_mask) & ~ring->align_mask;
while (ndw > (ring->ring_free_dw - 1)) {
radeon_ring_free_size(rdev, ring);
if (ndw < ring->ring_free_dw) {
break;
}
r = radeon_fence_wait_next(rdev, ring->idx);
if (r)
return r;
}
ring->count_dw = ndw;
ring->wptr_old = ring->wptr;
return 0;
}
int radeon_ring_lock(struct radeon_device *rdev, struct radeon_ring *ring, unsigned ndw)
{
int r;
mutex_lock(&rdev->ring_lock);
r = radeon_ring_alloc(rdev, ring, ndw);
if (r) {
mutex_unlock(&rdev->ring_lock);
return r;
}
return 0;
}
void radeon_ring_commit(struct radeon_device *rdev, struct radeon_ring *ring)
{
while (ring->wptr & ring->align_mask) {
radeon_ring_write(ring, ring->nop);
}
mb();
radeon_ring_set_wptr(rdev, ring);
}
void radeon_ring_unlock_commit(struct radeon_device *rdev, struct radeon_ring *ring)
{
radeon_ring_commit(rdev, ring);
mutex_unlock(&rdev->ring_lock);
}
void radeon_ring_undo(struct radeon_ring *ring)
{
ring->wptr = ring->wptr_old;
}
void radeon_ring_unlock_undo(struct radeon_device *rdev, struct radeon_ring *ring)
{
radeon_ring_undo(ring);
mutex_unlock(&rdev->ring_lock);
}
void radeon_ring_lockup_update(struct radeon_device *rdev,
struct radeon_ring *ring)
{
atomic_set(&ring->last_rptr, radeon_ring_get_rptr(rdev, ring));
atomic64_set(&ring->last_activity, jiffies_64);
}
bool radeon_ring_test_lockup(struct radeon_device *rdev, struct radeon_ring *ring)
{
uint32_t rptr = radeon_ring_get_rptr(rdev, ring);
uint64_t last = atomic64_read(&ring->last_activity);
uint64_t elapsed;
if (rptr != atomic_read(&ring->last_rptr)) {
radeon_ring_lockup_update(rdev, ring);
return false;
}
elapsed = jiffies_to_msecs(jiffies_64 - last);
if (radeon_lockup_timeout && elapsed >= radeon_lockup_timeout) {
dev_err(rdev->dev, "ring %d stalled for more than %llumsec\n",
ring->idx, elapsed);
return true;
}
return false;
}
unsigned radeon_ring_backup(struct radeon_device *rdev, struct radeon_ring *ring,
uint32_t **data)
{
unsigned size, ptr, i;
mutex_lock(&rdev->ring_lock);
*data = NULL;
if (ring->ring_obj == NULL) {
mutex_unlock(&rdev->ring_lock);
return 0;
}
if (!radeon_fence_count_emitted(rdev, ring->idx)) {
mutex_unlock(&rdev->ring_lock);
return 0;
}
if (ring->rptr_save_reg)
ptr = RREG32(ring->rptr_save_reg);
else if (rdev->wb.enabled)
ptr = le32_to_cpu(*ring->next_rptr_cpu_addr);
else {
mutex_unlock(&rdev->ring_lock);
return 0;
}
size = ring->wptr + (ring->ring_size / 4);
size -= ptr;
size &= ring->ptr_mask;
if (size == 0) {
mutex_unlock(&rdev->ring_lock);
return 0;
}
*data = kmalloc_array(size, sizeof(uint32_t), GFP_KERNEL);
if (!*data) {
mutex_unlock(&rdev->ring_lock);
return 0;
}
for (i = 0; i < size; ++i) {
(*data)[i] = ring->ring[ptr++];
ptr &= ring->ptr_mask;
}
mutex_unlock(&rdev->ring_lock);
return size;
}
int radeon_ring_restore(struct radeon_device *rdev, struct radeon_ring *ring,
unsigned size, uint32_t *data)
{
int i, r;
if (!size || !data)
return 0;
r = radeon_ring_lock(rdev, ring, size);
if (r)
return r;
for (i = 0; i < size; ++i) {
radeon_ring_write(ring, data[i]);
}
radeon_ring_unlock_commit(rdev, ring);
kfree(data);
return 0;
}
int radeon_ring_init(struct radeon_device *rdev, struct radeon_ring *ring, unsigned ring_size,
unsigned rptr_offs, u32 nop)
{
int r;
ring->ring_size = ring_size;
ring->rptr_offs = rptr_offs;
ring->nop = nop;
if (ring->ring_obj == NULL) {
r = radeon_bo_create(rdev, ring->ring_size, PAGE_SIZE, true,
RADEON_GEM_DOMAIN_GTT,
NULL, &ring->ring_obj);
if (r) {
dev_err(rdev->dev, "(%d) ring create failed\n", r);
return r;
}
r = radeon_bo_reserve(ring->ring_obj, false);
if (unlikely(r != 0))
return r;
r = radeon_bo_pin(ring->ring_obj, RADEON_GEM_DOMAIN_GTT,
&ring->gpu_addr);
if (r) {
radeon_bo_unreserve(ring->ring_obj);
dev_err(rdev->dev, "(%d) ring pin failed\n", r);
return r;
}
r = radeon_bo_kmap(ring->ring_obj,
(void **)&ring->ring);
radeon_bo_unreserve(ring->ring_obj);
if (r) {
dev_err(rdev->dev, "(%d) ring map failed\n", r);
return r;
}
}
ring->ptr_mask = (ring->ring_size / 4) - 1;
ring->ring_free_dw = ring->ring_size / 4;
if (rdev->wb.enabled) {
u32 index = RADEON_WB_RING0_NEXT_RPTR + (ring->idx * 4);
ring->next_rptr_gpu_addr = rdev->wb.gpu_addr + index;
ring->next_rptr_cpu_addr = &rdev->wb.wb[index/4];
}
if (radeon_debugfs_ring_init(rdev, ring)) {
DRM_ERROR("Failed to register debugfs file for rings !\n");
}
radeon_ring_lockup_update(rdev, ring);
return 0;
}
void radeon_ring_fini(struct radeon_device *rdev, struct radeon_ring *ring)
{
int r;
struct radeon_bo *ring_obj;
mutex_lock(&rdev->ring_lock);
ring_obj = ring->ring_obj;
ring->ready = false;
ring->ring = NULL;
ring->ring_obj = NULL;
mutex_unlock(&rdev->ring_lock);
if (ring_obj) {
r = radeon_bo_reserve(ring_obj, false);
if (likely(r == 0)) {
radeon_bo_kunmap(ring_obj);
radeon_bo_unpin(ring_obj);
radeon_bo_unreserve(ring_obj);
}
radeon_bo_unref(&ring_obj);
}
}
static int radeon_debugfs_ring_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct radeon_device *rdev = dev->dev_private;
int ridx = *(int*)node->info_ent->data;
struct radeon_ring *ring = &rdev->ring[ridx];
uint32_t rptr, wptr, rptr_next;
unsigned count, i, j;
radeon_ring_free_size(rdev, ring);
count = (ring->ring_size / 4) - ring->ring_free_dw;
wptr = radeon_ring_get_wptr(rdev, ring);
seq_printf(m, "wptr: 0x%08x [%5d]\n",
wptr, wptr);
rptr = radeon_ring_get_rptr(rdev, ring);
seq_printf(m, "rptr: 0x%08x [%5d]\n",
rptr, rptr);
if (ring->rptr_save_reg) {
rptr_next = RREG32(ring->rptr_save_reg);
seq_printf(m, "rptr next(0x%04x): 0x%08x [%5d]\n",
ring->rptr_save_reg, rptr_next, rptr_next);
} else
rptr_next = ~0;
seq_printf(m, "driver's copy of the wptr: 0x%08x [%5d]\n",
ring->wptr, ring->wptr);
seq_printf(m, "last semaphore signal addr : 0x%016llx\n",
ring->last_semaphore_signal_addr);
seq_printf(m, "last semaphore wait addr : 0x%016llx\n",
ring->last_semaphore_wait_addr);
seq_printf(m, "%u free dwords in ring\n", ring->ring_free_dw);
seq_printf(m, "%u dwords in ring\n", count);
if (!ring->ready)
return 0;
i = (rptr + ring->ptr_mask + 1 - 32) & ring->ptr_mask;
for (j = 0; j <= (count + 32); j++) {
seq_printf(m, "r[%5d]=0x%08x", i, ring->ring[i]);
if (rptr == i)
seq_puts(m, " *");
if (rptr_next == i)
seq_puts(m, " #");
seq_puts(m, "\n");
i = (i + 1) & ring->ptr_mask;
}
return 0;
}
static int radeon_debugfs_sa_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct radeon_device *rdev = dev->dev_private;
radeon_sa_bo_dump_debug_info(&rdev->ring_tmp_bo, m);
return 0;
}
static int radeon_debugfs_ring_init(struct radeon_device *rdev, struct radeon_ring *ring)
{
#if defined(CONFIG_DEBUG_FS)
unsigned i;
for (i = 0; i < ARRAY_SIZE(radeon_debugfs_ring_info_list); ++i) {
struct drm_info_list *info = &radeon_debugfs_ring_info_list[i];
int ridx = *(int*)radeon_debugfs_ring_info_list[i].data;
unsigned r;
if (&rdev->ring[ridx] != ring)
continue;
r = radeon_debugfs_add_files(rdev, info, 1);
if (r)
return r;
}
#endif
return 0;
}
static int radeon_debugfs_sa_init(struct radeon_device *rdev)
{
#if defined(CONFIG_DEBUG_FS)
return radeon_debugfs_add_files(rdev, radeon_debugfs_sa_list, 1);
#else
return 0;
#endif
}
