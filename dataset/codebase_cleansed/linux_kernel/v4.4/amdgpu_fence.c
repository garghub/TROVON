static void amdgpu_fence_write(struct amdgpu_ring *ring, u32 seq)
{
struct amdgpu_fence_driver *drv = &ring->fence_drv;
if (drv->cpu_addr)
*drv->cpu_addr = cpu_to_le32(seq);
}
static u32 amdgpu_fence_read(struct amdgpu_ring *ring)
{
struct amdgpu_fence_driver *drv = &ring->fence_drv;
u32 seq = 0;
if (drv->cpu_addr)
seq = le32_to_cpu(*drv->cpu_addr);
else
seq = lower_32_bits(atomic64_read(&drv->last_seq));
return seq;
}
int amdgpu_fence_emit(struct amdgpu_ring *ring, void *owner,
struct amdgpu_fence **fence)
{
struct amdgpu_device *adev = ring->adev;
*fence = kmem_cache_alloc(amdgpu_fence_slab, GFP_KERNEL);
if ((*fence) == NULL) {
return -ENOMEM;
}
(*fence)->seq = ++ring->fence_drv.sync_seq[ring->idx];
(*fence)->ring = ring;
(*fence)->owner = owner;
fence_init(&(*fence)->base, &amdgpu_fence_ops,
&ring->fence_drv.fence_queue.lock,
adev->fence_context + ring->idx,
(*fence)->seq);
amdgpu_ring_emit_fence(ring, ring->fence_drv.gpu_addr,
(*fence)->seq,
AMDGPU_FENCE_FLAG_INT);
return 0;
}
static void amdgpu_fence_schedule_fallback(struct amdgpu_ring *ring)
{
mod_timer(&ring->fence_drv.fallback_timer,
jiffies + AMDGPU_FENCE_JIFFIES_TIMEOUT);
}
static bool amdgpu_fence_activity(struct amdgpu_ring *ring)
{
uint64_t seq, last_seq, last_emitted;
unsigned count_loop = 0;
bool wake = false;
last_seq = atomic64_read(&ring->fence_drv.last_seq);
do {
last_emitted = ring->fence_drv.sync_seq[ring->idx];
seq = amdgpu_fence_read(ring);
seq |= last_seq & 0xffffffff00000000LL;
if (seq < last_seq) {
seq &= 0xffffffff;
seq |= last_emitted & 0xffffffff00000000LL;
}
if (seq <= last_seq || seq > last_emitted) {
break;
}
wake = true;
last_seq = seq;
if ((count_loop++) > 10) {
break;
}
} while (atomic64_xchg(&ring->fence_drv.last_seq, seq) > seq);
if (seq < last_emitted)
amdgpu_fence_schedule_fallback(ring);
return wake;
}
void amdgpu_fence_process(struct amdgpu_ring *ring)
{
if (amdgpu_fence_activity(ring))
wake_up_all(&ring->fence_drv.fence_queue);
}
static void amdgpu_fence_fallback(unsigned long arg)
{
struct amdgpu_ring *ring = (void *)arg;
amdgpu_fence_process(ring);
}
static bool amdgpu_fence_seq_signaled(struct amdgpu_ring *ring, u64 seq)
{
if (atomic64_read(&ring->fence_drv.last_seq) >= seq)
return true;
amdgpu_fence_process(ring);
if (atomic64_read(&ring->fence_drv.last_seq) >= seq)
return true;
return false;
}
static int amdgpu_fence_ring_wait_seq(struct amdgpu_ring *ring, uint64_t seq)
{
bool signaled = false;
BUG_ON(!ring);
if (seq > ring->fence_drv.sync_seq[ring->idx])
return -EINVAL;
if (atomic64_read(&ring->fence_drv.last_seq) >= seq)
return 0;
amdgpu_fence_schedule_fallback(ring);
wait_event(ring->fence_drv.fence_queue, (
(signaled = amdgpu_fence_seq_signaled(ring, seq))));
if (signaled)
return 0;
else
return -EDEADLK;
}
int amdgpu_fence_wait_next(struct amdgpu_ring *ring)
{
uint64_t seq = atomic64_read(&ring->fence_drv.last_seq) + 1ULL;
if (seq >= ring->fence_drv.sync_seq[ring->idx])
return -ENOENT;
return amdgpu_fence_ring_wait_seq(ring, seq);
}
int amdgpu_fence_wait_empty(struct amdgpu_ring *ring)
{
uint64_t seq = ring->fence_drv.sync_seq[ring->idx];
if (!seq)
return 0;
return amdgpu_fence_ring_wait_seq(ring, seq);
}
unsigned amdgpu_fence_count_emitted(struct amdgpu_ring *ring)
{
uint64_t emitted;
amdgpu_fence_process(ring);
emitted = ring->fence_drv.sync_seq[ring->idx]
- atomic64_read(&ring->fence_drv.last_seq);
if (emitted > 0x10000000)
emitted = 0x10000000;
return (unsigned)emitted;
}
bool amdgpu_fence_need_sync(struct amdgpu_fence *fence,
struct amdgpu_ring *dst_ring)
{
struct amdgpu_fence_driver *fdrv;
if (!fence)
return false;
if (fence->ring == dst_ring)
return false;
fdrv = &dst_ring->fence_drv;
if (fence->seq <= fdrv->sync_seq[fence->ring->idx])
return false;
return true;
}
void amdgpu_fence_note_sync(struct amdgpu_fence *fence,
struct amdgpu_ring *dst_ring)
{
struct amdgpu_fence_driver *dst, *src;
unsigned i;
if (!fence)
return;
if (fence->ring == dst_ring)
return;
src = &fence->ring->fence_drv;
dst = &dst_ring->fence_drv;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
if (i == dst_ring->idx)
continue;
dst->sync_seq[i] = max(dst->sync_seq[i], src->sync_seq[i]);
}
}
int amdgpu_fence_driver_start_ring(struct amdgpu_ring *ring,
struct amdgpu_irq_src *irq_src,
unsigned irq_type)
{
struct amdgpu_device *adev = ring->adev;
uint64_t index;
if (ring != &adev->uvd.ring) {
ring->fence_drv.cpu_addr = &adev->wb.wb[ring->fence_offs];
ring->fence_drv.gpu_addr = adev->wb.gpu_addr + (ring->fence_offs * 4);
} else {
index = ALIGN(adev->uvd.fw->size, 8);
ring->fence_drv.cpu_addr = adev->uvd.cpu_addr + index;
ring->fence_drv.gpu_addr = adev->uvd.gpu_addr + index;
}
amdgpu_fence_write(ring, atomic64_read(&ring->fence_drv.last_seq));
amdgpu_irq_get(adev, irq_src, irq_type);
ring->fence_drv.irq_src = irq_src;
ring->fence_drv.irq_type = irq_type;
ring->fence_drv.initialized = true;
dev_info(adev->dev, "fence driver on ring %d use gpu addr 0x%016llx, "
"cpu addr 0x%p\n", ring->idx,
ring->fence_drv.gpu_addr, ring->fence_drv.cpu_addr);
return 0;
}
int amdgpu_fence_driver_init_ring(struct amdgpu_ring *ring)
{
int i, r;
ring->fence_drv.cpu_addr = NULL;
ring->fence_drv.gpu_addr = 0;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i)
ring->fence_drv.sync_seq[i] = 0;
atomic64_set(&ring->fence_drv.last_seq, 0);
ring->fence_drv.initialized = false;
setup_timer(&ring->fence_drv.fallback_timer, amdgpu_fence_fallback,
(unsigned long)ring);
init_waitqueue_head(&ring->fence_drv.fence_queue);
if (amdgpu_enable_scheduler) {
long timeout = msecs_to_jiffies(amdgpu_lockup_timeout);
if (timeout == 0) {
timeout = MAX_SCHEDULE_TIMEOUT;
}
r = amd_sched_init(&ring->sched, &amdgpu_sched_ops,
amdgpu_sched_hw_submission,
timeout, ring->name);
if (r) {
DRM_ERROR("Failed to create scheduler on ring %s.\n",
ring->name);
return r;
}
}
return 0;
}
int amdgpu_fence_driver_init(struct amdgpu_device *adev)
{
if (atomic_inc_return(&amdgpu_fence_slab_ref) == 1) {
amdgpu_fence_slab = kmem_cache_create(
"amdgpu_fence", sizeof(struct amdgpu_fence), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!amdgpu_fence_slab)
return -ENOMEM;
}
if (amdgpu_debugfs_fence_init(adev))
dev_err(adev->dev, "fence debugfs file creation failed\n");
return 0;
}
void amdgpu_fence_driver_fini(struct amdgpu_device *adev)
{
int i, r;
if (atomic_dec_and_test(&amdgpu_fence_slab_ref))
kmem_cache_destroy(amdgpu_fence_slab);
mutex_lock(&adev->ring_lock);
for (i = 0; i < AMDGPU_MAX_RINGS; i++) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->fence_drv.initialized)
continue;
r = amdgpu_fence_wait_empty(ring);
if (r) {
amdgpu_fence_driver_force_completion(adev);
}
wake_up_all(&ring->fence_drv.fence_queue);
amdgpu_irq_put(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type);
amd_sched_fini(&ring->sched);
del_timer_sync(&ring->fence_drv.fallback_timer);
ring->fence_drv.initialized = false;
}
mutex_unlock(&adev->ring_lock);
}
void amdgpu_fence_driver_suspend(struct amdgpu_device *adev)
{
int i, r;
mutex_lock(&adev->ring_lock);
for (i = 0; i < AMDGPU_MAX_RINGS; i++) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->fence_drv.initialized)
continue;
r = amdgpu_fence_wait_empty(ring);
if (r) {
amdgpu_fence_driver_force_completion(adev);
}
amdgpu_irq_put(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type);
}
mutex_unlock(&adev->ring_lock);
}
void amdgpu_fence_driver_resume(struct amdgpu_device *adev)
{
int i;
mutex_lock(&adev->ring_lock);
for (i = 0; i < AMDGPU_MAX_RINGS; i++) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->fence_drv.initialized)
continue;
amdgpu_irq_get(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type);
}
mutex_unlock(&adev->ring_lock);
}
void amdgpu_fence_driver_force_completion(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < AMDGPU_MAX_RINGS; i++) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->fence_drv.initialized)
continue;
amdgpu_fence_write(ring, ring->fence_drv.sync_seq[i]);
}
}
static const char *amdgpu_fence_get_driver_name(struct fence *fence)
{
return "amdgpu";
}
static const char *amdgpu_fence_get_timeline_name(struct fence *f)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
return (const char *)fence->ring->name;
}
static bool amdgpu_fence_is_signaled(struct fence *f)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
struct amdgpu_ring *ring = fence->ring;
if (atomic64_read(&ring->fence_drv.last_seq) >= fence->seq)
return true;
amdgpu_fence_process(ring);
if (atomic64_read(&ring->fence_drv.last_seq) >= fence->seq)
return true;
return false;
}
static int amdgpu_fence_check_signaled(wait_queue_t *wait, unsigned mode, int flags, void *key)
{
struct amdgpu_fence *fence;
struct amdgpu_device *adev;
u64 seq;
int ret;
fence = container_of(wait, struct amdgpu_fence, fence_wake);
adev = fence->ring->adev;
seq = atomic64_read(&fence->ring->fence_drv.last_seq);
if (seq >= fence->seq) {
ret = fence_signal_locked(&fence->base);
if (!ret)
FENCE_TRACE(&fence->base, "signaled from irq context\n");
else
FENCE_TRACE(&fence->base, "was already signaled\n");
__remove_wait_queue(&fence->ring->fence_drv.fence_queue, &fence->fence_wake);
fence_put(&fence->base);
} else
FENCE_TRACE(&fence->base, "pending\n");
return 0;
}
static bool amdgpu_fence_enable_signaling(struct fence *f)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
struct amdgpu_ring *ring = fence->ring;
if (atomic64_read(&ring->fence_drv.last_seq) >= fence->seq)
return false;
fence->fence_wake.flags = 0;
fence->fence_wake.private = NULL;
fence->fence_wake.func = amdgpu_fence_check_signaled;
__add_wait_queue(&ring->fence_drv.fence_queue, &fence->fence_wake);
fence_get(f);
if (!timer_pending(&ring->fence_drv.fallback_timer))
amdgpu_fence_schedule_fallback(ring);
FENCE_TRACE(&fence->base, "armed on ring %i!\n", ring->idx);
return true;
}
static void amdgpu_fence_release(struct fence *f)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
kmem_cache_free(amdgpu_fence_slab, fence);
}
static int amdgpu_debugfs_fence_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct amdgpu_device *adev = dev->dev_private;
int i, j;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->fence_drv.initialized)
continue;
amdgpu_fence_process(ring);
seq_printf(m, "--- ring %d (%s) ---\n", i, ring->name);
seq_printf(m, "Last signaled fence 0x%016llx\n",
(unsigned long long)atomic64_read(&ring->fence_drv.last_seq));
seq_printf(m, "Last emitted 0x%016llx\n",
ring->fence_drv.sync_seq[i]);
for (j = 0; j < AMDGPU_MAX_RINGS; ++j) {
struct amdgpu_ring *other = adev->rings[j];
if (i != j && other && other->fence_drv.initialized &&
ring->fence_drv.sync_seq[j])
seq_printf(m, "Last sync to ring %d 0x%016llx\n",
j, ring->fence_drv.sync_seq[j]);
}
}
return 0;
}
int amdgpu_debugfs_fence_init(struct amdgpu_device *adev)
{
#if defined(CONFIG_DEBUG_FS)
return amdgpu_debugfs_add_files(adev, amdgpu_debugfs_fence_list, 1);
#else
return 0;
#endif
}
