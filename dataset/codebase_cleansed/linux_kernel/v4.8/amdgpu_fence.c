int amdgpu_fence_slab_init(void)
{
amdgpu_fence_slab = kmem_cache_create(
"amdgpu_fence", sizeof(struct amdgpu_fence), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!amdgpu_fence_slab)
return -ENOMEM;
return 0;
}
void amdgpu_fence_slab_fini(void)
{
kmem_cache_destroy(amdgpu_fence_slab);
}
static inline struct amdgpu_fence *to_amdgpu_fence(struct fence *f)
{
struct amdgpu_fence *__f = container_of(f, struct amdgpu_fence, base);
if (__f->base.ops == &amdgpu_fence_ops)
return __f;
return NULL;
}
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
seq = atomic_read(&drv->last_seq);
return seq;
}
int amdgpu_fence_emit(struct amdgpu_ring *ring, struct fence **f)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_fence *fence;
struct fence *old, **ptr;
uint32_t seq;
fence = kmem_cache_alloc(amdgpu_fence_slab, GFP_KERNEL);
if (fence == NULL)
return -ENOMEM;
seq = ++ring->fence_drv.sync_seq;
fence->ring = ring;
fence_init(&fence->base, &amdgpu_fence_ops,
&ring->fence_drv.lock,
adev->fence_context + ring->idx,
seq);
amdgpu_ring_emit_fence(ring, ring->fence_drv.gpu_addr,
seq, AMDGPU_FENCE_FLAG_INT);
ptr = &ring->fence_drv.fences[seq & ring->fence_drv.num_fences_mask];
old = rcu_dereference_protected(*ptr, 1);
if (old && !fence_is_signaled(old)) {
DRM_INFO("rcu slot is busy\n");
fence_wait(old, false);
}
rcu_assign_pointer(*ptr, fence_get(&fence->base));
*f = &fence->base;
return 0;
}
static void amdgpu_fence_schedule_fallback(struct amdgpu_ring *ring)
{
mod_timer(&ring->fence_drv.fallback_timer,
jiffies + AMDGPU_FENCE_JIFFIES_TIMEOUT);
}
void amdgpu_fence_process(struct amdgpu_ring *ring)
{
struct amdgpu_fence_driver *drv = &ring->fence_drv;
uint32_t seq, last_seq;
int r;
do {
last_seq = atomic_read(&ring->fence_drv.last_seq);
seq = amdgpu_fence_read(ring);
} while (atomic_cmpxchg(&drv->last_seq, last_seq, seq) != last_seq);
if (seq != ring->fence_drv.sync_seq)
amdgpu_fence_schedule_fallback(ring);
if (unlikely(seq == last_seq))
return;
last_seq &= drv->num_fences_mask;
seq &= drv->num_fences_mask;
do {
struct fence *fence, **ptr;
++last_seq;
last_seq &= drv->num_fences_mask;
ptr = &drv->fences[last_seq];
fence = rcu_dereference_protected(*ptr, 1);
RCU_INIT_POINTER(*ptr, NULL);
if (!fence)
continue;
r = fence_signal(fence);
if (!r)
FENCE_TRACE(fence, "signaled from irq context\n");
else
BUG();
fence_put(fence);
} while (last_seq != seq);
}
static void amdgpu_fence_fallback(unsigned long arg)
{
struct amdgpu_ring *ring = (void *)arg;
amdgpu_fence_process(ring);
}
int amdgpu_fence_wait_empty(struct amdgpu_ring *ring)
{
uint64_t seq = ACCESS_ONCE(ring->fence_drv.sync_seq);
struct fence *fence, **ptr;
int r;
if (!seq)
return 0;
ptr = &ring->fence_drv.fences[seq & ring->fence_drv.num_fences_mask];
rcu_read_lock();
fence = rcu_dereference(*ptr);
if (!fence || !fence_get_rcu(fence)) {
rcu_read_unlock();
return 0;
}
rcu_read_unlock();
r = fence_wait(fence, false);
fence_put(fence);
return r;
}
unsigned amdgpu_fence_count_emitted(struct amdgpu_ring *ring)
{
uint64_t emitted;
amdgpu_fence_process(ring);
emitted = 0x100000000ull;
emitted -= atomic_read(&ring->fence_drv.last_seq);
emitted += ACCESS_ONCE(ring->fence_drv.sync_seq);
return lower_32_bits(emitted);
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
amdgpu_fence_write(ring, atomic_read(&ring->fence_drv.last_seq));
amdgpu_irq_get(adev, irq_src, irq_type);
ring->fence_drv.irq_src = irq_src;
ring->fence_drv.irq_type = irq_type;
ring->fence_drv.initialized = true;
dev_info(adev->dev, "fence driver on ring %d use gpu addr 0x%016llx, "
"cpu addr 0x%p\n", ring->idx,
ring->fence_drv.gpu_addr, ring->fence_drv.cpu_addr);
return 0;
}
int amdgpu_fence_driver_init_ring(struct amdgpu_ring *ring,
unsigned num_hw_submission)
{
long timeout;
int r;
if ((num_hw_submission & (num_hw_submission - 1)) != 0)
return -EINVAL;
ring->fence_drv.cpu_addr = NULL;
ring->fence_drv.gpu_addr = 0;
ring->fence_drv.sync_seq = 0;
atomic_set(&ring->fence_drv.last_seq, 0);
ring->fence_drv.initialized = false;
setup_timer(&ring->fence_drv.fallback_timer, amdgpu_fence_fallback,
(unsigned long)ring);
ring->fence_drv.num_fences_mask = num_hw_submission * 2 - 1;
spin_lock_init(&ring->fence_drv.lock);
ring->fence_drv.fences = kcalloc(num_hw_submission * 2, sizeof(void *),
GFP_KERNEL);
if (!ring->fence_drv.fences)
return -ENOMEM;
timeout = msecs_to_jiffies(amdgpu_lockup_timeout);
if (timeout == 0) {
timeout = MAX_SCHEDULE_TIMEOUT;
}
r = amd_sched_init(&ring->sched, &amdgpu_sched_ops,
num_hw_submission,
timeout, ring->name);
if (r) {
DRM_ERROR("Failed to create scheduler on ring %s.\n",
ring->name);
return r;
}
return 0;
}
int amdgpu_fence_driver_init(struct amdgpu_device *adev)
{
if (amdgpu_debugfs_fence_init(adev))
dev_err(adev->dev, "fence debugfs file creation failed\n");
return 0;
}
void amdgpu_fence_driver_fini(struct amdgpu_device *adev)
{
unsigned i, j;
int r;
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
amd_sched_fini(&ring->sched);
del_timer_sync(&ring->fence_drv.fallback_timer);
for (j = 0; j <= ring->fence_drv.num_fences_mask; ++j)
fence_put(ring->fence_drv.fences[j]);
kfree(ring->fence_drv.fences);
ring->fence_drv.initialized = false;
}
}
void amdgpu_fence_driver_suspend(struct amdgpu_device *adev)
{
int i, r;
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
}
void amdgpu_fence_driver_resume(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < AMDGPU_MAX_RINGS; i++) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->fence_drv.initialized)
continue;
amdgpu_irq_get(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type);
}
}
void amdgpu_fence_driver_force_completion(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < AMDGPU_MAX_RINGS; i++) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->fence_drv.initialized)
continue;
amdgpu_fence_write(ring, ring->fence_drv.sync_seq);
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
static bool amdgpu_fence_enable_signaling(struct fence *f)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
struct amdgpu_ring *ring = fence->ring;
if (!timer_pending(&ring->fence_drv.fallback_timer))
amdgpu_fence_schedule_fallback(ring);
FENCE_TRACE(&fence->base, "armed on ring %i!\n", ring->idx);
return true;
}
static void amdgpu_fence_free(struct rcu_head *rcu)
{
struct fence *f = container_of(rcu, struct fence, rcu);
struct amdgpu_fence *fence = to_amdgpu_fence(f);
kmem_cache_free(amdgpu_fence_slab, fence);
}
static void amdgpu_fence_release(struct fence *f)
{
call_rcu(&f->rcu, amdgpu_fence_free);
}
static int amdgpu_debugfs_fence_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct amdgpu_device *adev = dev->dev_private;
int i;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !ring->fence_drv.initialized)
continue;
amdgpu_fence_process(ring);
seq_printf(m, "--- ring %d (%s) ---\n", i, ring->name);
seq_printf(m, "Last signaled fence 0x%08x\n",
atomic_read(&ring->fence_drv.last_seq));
seq_printf(m, "Last emitted 0x%08x\n",
ring->fence_drv.sync_seq);
}
return 0;
}
static int amdgpu_debugfs_gpu_reset(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct amdgpu_device *adev = dev->dev_private;
seq_printf(m, "gpu reset\n");
amdgpu_gpu_reset(adev);
return 0;
}
int amdgpu_debugfs_fence_init(struct amdgpu_device *adev)
{
#if defined(CONFIG_DEBUG_FS)
return amdgpu_debugfs_add_files(adev, amdgpu_debugfs_fence_list, 2);
#else
return 0;
#endif
}
