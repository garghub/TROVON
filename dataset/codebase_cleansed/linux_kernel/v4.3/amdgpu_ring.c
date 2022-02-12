void amdgpu_ring_free_size(struct amdgpu_ring *ring)
{
uint32_t rptr = amdgpu_ring_get_rptr(ring);
ring->ring_free_dw = rptr + (ring->ring_size / 4);
ring->ring_free_dw -= ring->wptr;
ring->ring_free_dw &= ring->ptr_mask;
if (!ring->ring_free_dw) {
ring->ring_free_dw = ring->ring_size / 4;
amdgpu_ring_lockup_update(ring);
}
}
int amdgpu_ring_alloc(struct amdgpu_ring *ring, unsigned ndw)
{
int r;
if (ndw > (ring->ring_size / 4))
return -ENOMEM;
amdgpu_ring_free_size(ring);
ndw = (ndw + ring->align_mask) & ~ring->align_mask;
while (ndw > (ring->ring_free_dw - 1)) {
amdgpu_ring_free_size(ring);
if (ndw < ring->ring_free_dw) {
break;
}
r = amdgpu_fence_wait_next(ring);
if (r)
return r;
}
ring->count_dw = ndw;
ring->wptr_old = ring->wptr;
return 0;
}
int amdgpu_ring_lock(struct amdgpu_ring *ring, unsigned ndw)
{
int r;
mutex_lock(ring->ring_lock);
r = amdgpu_ring_alloc(ring, ndw);
if (r) {
mutex_unlock(ring->ring_lock);
return r;
}
return 0;
}
void amdgpu_ring_insert_nop(struct amdgpu_ring *ring, uint32_t count)
{
int i;
for (i = 0; i < count; i++)
amdgpu_ring_write(ring, ring->nop);
}
void amdgpu_ring_commit(struct amdgpu_ring *ring)
{
uint32_t count;
count = ring->align_mask + 1 - (ring->wptr & ring->align_mask);
count %= ring->align_mask + 1;
ring->funcs->insert_nop(ring, count);
mb();
amdgpu_ring_set_wptr(ring);
}
void amdgpu_ring_unlock_commit(struct amdgpu_ring *ring)
{
amdgpu_ring_commit(ring);
mutex_unlock(ring->ring_lock);
}
void amdgpu_ring_undo(struct amdgpu_ring *ring)
{
ring->wptr = ring->wptr_old;
}
void amdgpu_ring_unlock_undo(struct amdgpu_ring *ring)
{
amdgpu_ring_undo(ring);
mutex_unlock(ring->ring_lock);
}
void amdgpu_ring_lockup_update(struct amdgpu_ring *ring)
{
atomic_set(&ring->last_rptr, amdgpu_ring_get_rptr(ring));
atomic64_set(&ring->last_activity, jiffies_64);
}
bool amdgpu_ring_test_lockup(struct amdgpu_ring *ring)
{
uint32_t rptr = amdgpu_ring_get_rptr(ring);
uint64_t last = atomic64_read(&ring->last_activity);
uint64_t elapsed;
if (rptr != atomic_read(&ring->last_rptr)) {
amdgpu_ring_lockup_update(ring);
return false;
}
elapsed = jiffies_to_msecs(jiffies_64 - last);
if (amdgpu_lockup_timeout && elapsed >= amdgpu_lockup_timeout) {
dev_err(ring->adev->dev, "ring %d stalled for more than %llumsec\n",
ring->idx, elapsed);
return true;
}
return false;
}
unsigned amdgpu_ring_backup(struct amdgpu_ring *ring,
uint32_t **data)
{
unsigned size, ptr, i;
mutex_lock(ring->ring_lock);
*data = NULL;
if (ring->ring_obj == NULL) {
mutex_unlock(ring->ring_lock);
return 0;
}
if (!amdgpu_fence_count_emitted(ring)) {
mutex_unlock(ring->ring_lock);
return 0;
}
ptr = le32_to_cpu(*ring->next_rptr_cpu_addr);
size = ring->wptr + (ring->ring_size / 4);
size -= ptr;
size &= ring->ptr_mask;
if (size == 0) {
mutex_unlock(ring->ring_lock);
return 0;
}
*data = kmalloc_array(size, sizeof(uint32_t), GFP_KERNEL);
if (!*data) {
mutex_unlock(ring->ring_lock);
return 0;
}
for (i = 0; i < size; ++i) {
(*data)[i] = ring->ring[ptr++];
ptr &= ring->ptr_mask;
}
mutex_unlock(ring->ring_lock);
return size;
}
int amdgpu_ring_restore(struct amdgpu_ring *ring,
unsigned size, uint32_t *data)
{
int i, r;
if (!size || !data)
return 0;
r = amdgpu_ring_lock(ring, size);
if (r)
return r;
for (i = 0; i < size; ++i) {
amdgpu_ring_write(ring, data[i]);
}
amdgpu_ring_unlock_commit(ring);
kfree(data);
return 0;
}
int amdgpu_ring_init(struct amdgpu_device *adev, struct amdgpu_ring *ring,
unsigned ring_size, u32 nop, u32 align_mask,
struct amdgpu_irq_src *irq_src, unsigned irq_type,
enum amdgpu_ring_type ring_type)
{
u32 rb_bufsz;
int r;
if (ring->adev == NULL) {
if (adev->num_rings >= AMDGPU_MAX_RINGS)
return -EINVAL;
ring->adev = adev;
ring->idx = adev->num_rings++;
adev->rings[ring->idx] = ring;
r = amdgpu_fence_driver_init_ring(ring);
if (r)
return r;
}
r = amdgpu_wb_get(adev, &ring->rptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ring rptr_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get(adev, &ring->wptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ring wptr_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get(adev, &ring->fence_offs);
if (r) {
dev_err(adev->dev, "(%d) ring fence_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get(adev, &ring->next_rptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ring next_rptr wb alloc failed\n", r);
return r;
}
ring->next_rptr_gpu_addr = adev->wb.gpu_addr + (ring->next_rptr_offs * 4);
ring->next_rptr_cpu_addr = &adev->wb.wb[ring->next_rptr_offs];
spin_lock_init(&ring->fence_lock);
r = amdgpu_fence_driver_start_ring(ring, irq_src, irq_type);
if (r) {
dev_err(adev->dev, "failed initializing fences (%d).\n", r);
return r;
}
ring->ring_lock = &adev->ring_lock;
rb_bufsz = order_base_2(ring_size / 8);
ring_size = (1 << (rb_bufsz + 1)) * 4;
ring->ring_size = ring_size;
ring->align_mask = align_mask;
ring->nop = nop;
ring->type = ring_type;
if (ring->ring_obj == NULL) {
r = amdgpu_bo_create(adev, ring->ring_size, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GTT, 0,
NULL, NULL, &ring->ring_obj);
if (r) {
dev_err(adev->dev, "(%d) ring create failed\n", r);
return r;
}
r = amdgpu_bo_reserve(ring->ring_obj, false);
if (unlikely(r != 0))
return r;
r = amdgpu_bo_pin(ring->ring_obj, AMDGPU_GEM_DOMAIN_GTT,
&ring->gpu_addr);
if (r) {
amdgpu_bo_unreserve(ring->ring_obj);
dev_err(adev->dev, "(%d) ring pin failed\n", r);
return r;
}
r = amdgpu_bo_kmap(ring->ring_obj,
(void **)&ring->ring);
amdgpu_bo_unreserve(ring->ring_obj);
if (r) {
dev_err(adev->dev, "(%d) ring map failed\n", r);
return r;
}
}
ring->ptr_mask = (ring->ring_size / 4) - 1;
ring->ring_free_dw = ring->ring_size / 4;
if (amdgpu_debugfs_ring_init(adev, ring)) {
DRM_ERROR("Failed to register debugfs file for rings !\n");
}
amdgpu_ring_lockup_update(ring);
return 0;
}
void amdgpu_ring_fini(struct amdgpu_ring *ring)
{
int r;
struct amdgpu_bo *ring_obj;
if (ring->ring_lock == NULL)
return;
mutex_lock(ring->ring_lock);
ring_obj = ring->ring_obj;
ring->ready = false;
ring->ring = NULL;
ring->ring_obj = NULL;
mutex_unlock(ring->ring_lock);
amdgpu_wb_free(ring->adev, ring->fence_offs);
amdgpu_wb_free(ring->adev, ring->rptr_offs);
amdgpu_wb_free(ring->adev, ring->wptr_offs);
amdgpu_wb_free(ring->adev, ring->next_rptr_offs);
if (ring_obj) {
r = amdgpu_bo_reserve(ring_obj, false);
if (likely(r == 0)) {
amdgpu_bo_kunmap(ring_obj);
amdgpu_bo_unpin(ring_obj);
amdgpu_bo_unreserve(ring_obj);
}
amdgpu_bo_unref(&ring_obj);
}
}
static int amdgpu_debugfs_ring_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct amdgpu_device *adev = dev->dev_private;
int roffset = *(int*)node->info_ent->data;
struct amdgpu_ring *ring = (void *)(((uint8_t*)adev) + roffset);
uint32_t rptr, wptr, rptr_next;
unsigned count, i, j;
amdgpu_ring_free_size(ring);
count = (ring->ring_size / 4) - ring->ring_free_dw;
wptr = amdgpu_ring_get_wptr(ring);
seq_printf(m, "wptr: 0x%08x [%5d]\n",
wptr, wptr);
rptr = amdgpu_ring_get_rptr(ring);
seq_printf(m, "rptr: 0x%08x [%5d]\n",
rptr, rptr);
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
static int amdgpu_debugfs_ring_init(struct amdgpu_device *adev, struct amdgpu_ring *ring)
{
#if defined(CONFIG_DEBUG_FS)
unsigned i;
for (i = 0; i < ARRAY_SIZE(amdgpu_debugfs_ring_info_list); ++i) {
struct drm_info_list *info = &amdgpu_debugfs_ring_info_list[i];
int roffset = *(int*)amdgpu_debugfs_ring_info_list[i].data;
struct amdgpu_ring *other = (void *)(((uint8_t*)adev) + roffset);
unsigned r;
if (other != ring)
continue;
r = amdgpu_debugfs_add_files(adev, info, 1);
if (r)
return r;
}
#endif
return 0;
}
