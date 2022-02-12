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
static void amdgpu_fence_schedule_check(struct amdgpu_ring *ring)
{
queue_delayed_work(system_power_efficient_wq,
&ring->fence_drv.lockup_work,
AMDGPU_FENCE_JIFFIES_TIMEOUT);
}
int amdgpu_fence_emit(struct amdgpu_ring *ring, void *owner,
struct amdgpu_fence **fence)
{
struct amdgpu_device *adev = ring->adev;
*fence = kmalloc(sizeof(struct amdgpu_fence), GFP_KERNEL);
if ((*fence) == NULL) {
return -ENOMEM;
}
(*fence)->seq = ++ring->fence_drv.sync_seq[ring->idx];
(*fence)->ring = ring;
(*fence)->owner = owner;
fence_init(&(*fence)->base, &amdgpu_fence_ops,
&adev->fence_queue.lock, adev->fence_context + ring->idx,
(*fence)->seq);
amdgpu_ring_emit_fence(ring, ring->fence_drv.gpu_addr,
(*fence)->seq,
AMDGPU_FENCE_FLAG_INT);
trace_amdgpu_fence_emit(ring->adev->ddev, ring->idx, (*fence)->seq);
return 0;
}
int amdgpu_fence_recreate(struct amdgpu_ring *ring, void *owner,
uint64_t seq, struct amdgpu_fence **fence)
{
struct amdgpu_device *adev = ring->adev;
if (seq > ring->fence_drv.sync_seq[ring->idx])
return -EINVAL;
*fence = kmalloc(sizeof(struct amdgpu_fence), GFP_KERNEL);
if ((*fence) == NULL)
return -ENOMEM;
(*fence)->seq = seq;
(*fence)->ring = ring;
(*fence)->owner = owner;
fence_init(&(*fence)->base, &amdgpu_fence_ops,
&adev->fence_queue.lock, adev->fence_context + ring->idx,
(*fence)->seq);
return 0;
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
amdgpu_irq_put(adev, fence->ring->fence_drv.irq_src,
fence->ring->fence_drv.irq_type);
__remove_wait_queue(&adev->fence_queue, &fence->fence_wake);
fence_put(&fence->base);
} else
FENCE_TRACE(&fence->base, "pending\n");
return 0;
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
amdgpu_fence_schedule_check(ring);
return wake;
}
static void amdgpu_fence_check_lockup(struct work_struct *work)
{
struct amdgpu_fence_driver *fence_drv;
struct amdgpu_ring *ring;
fence_drv = container_of(work, struct amdgpu_fence_driver,
lockup_work.work);
ring = fence_drv->ring;
if (!down_read_trylock(&ring->adev->exclusive_lock)) {
amdgpu_fence_schedule_check(ring);
return;
}
if (fence_drv->delayed_irq && ring->adev->ddev->irq_enabled) {
fence_drv->delayed_irq = false;
amdgpu_irq_update(ring->adev, fence_drv->irq_src,
fence_drv->irq_type);
}
if (amdgpu_fence_activity(ring))
wake_up_all(&ring->adev->fence_queue);
else if (amdgpu_ring_is_lockup(ring)) {
dev_warn(ring->adev->dev, "GPU lockup (current fence id "
"0x%016llx last fence id 0x%016llx on ring %d)\n",
(uint64_t)atomic64_read(&fence_drv->last_seq),
fence_drv->sync_seq[ring->idx], ring->idx);
ring->adev->needs_reset = true;
wake_up_all(&ring->adev->fence_queue);
}
up_read(&ring->adev->exclusive_lock);
}
void amdgpu_fence_process(struct amdgpu_ring *ring)
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
if (wake)
wake_up_all(&ring->adev->fence_queue);
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
static bool amdgpu_fence_is_signaled(struct fence *f)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
struct amdgpu_ring *ring = fence->ring;
struct amdgpu_device *adev = ring->adev;
if (atomic64_read(&ring->fence_drv.last_seq) >= fence->seq)
return true;
if (down_read_trylock(&adev->exclusive_lock)) {
amdgpu_fence_process(ring);
up_read(&adev->exclusive_lock);
if (atomic64_read(&ring->fence_drv.last_seq) >= fence->seq)
return true;
}
return false;
}
static bool amdgpu_fence_enable_signaling(struct fence *f)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
struct amdgpu_ring *ring = fence->ring;
struct amdgpu_device *adev = ring->adev;
if (atomic64_read(&ring->fence_drv.last_seq) >= fence->seq)
return false;
if (down_read_trylock(&adev->exclusive_lock)) {
amdgpu_irq_get(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type);
if (amdgpu_fence_activity(ring))
wake_up_all_locked(&adev->fence_queue);
if (atomic64_read(&ring->fence_drv.last_seq) >= fence->seq) {
amdgpu_irq_put(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type);
up_read(&adev->exclusive_lock);
return false;
}
up_read(&adev->exclusive_lock);
} else {
if (amdgpu_irq_get_delayed(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type))
ring->fence_drv.delayed_irq = true;
amdgpu_fence_schedule_check(ring);
}
fence->fence_wake.flags = 0;
fence->fence_wake.private = NULL;
fence->fence_wake.func = amdgpu_fence_check_signaled;
__add_wait_queue(&adev->fence_queue, &fence->fence_wake);
fence_get(f);
FENCE_TRACE(&fence->base, "armed on ring %i!\n", ring->idx);
return true;
}
bool amdgpu_fence_signaled(struct amdgpu_fence *fence)
{
if (!fence)
return true;
if (amdgpu_fence_seq_signaled(fence->ring, fence->seq)) {
if (!fence_signal(&fence->base))
FENCE_TRACE(&fence->base, "signaled from amdgpu_fence_signaled\n");
return true;
}
return false;
}
static bool amdgpu_fence_any_seq_signaled(struct amdgpu_device *adev, u64 *seq)
{
unsigned i;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
if (!adev->rings[i] || !seq[i])
continue;
if (amdgpu_fence_seq_signaled(adev->rings[i], seq[i]))
return true;
}
return false;
}
static long amdgpu_fence_wait_seq_timeout(struct amdgpu_device *adev,
u64 *target_seq, bool intr,
long timeout)
{
uint64_t last_seq[AMDGPU_MAX_RINGS];
bool signaled;
int i;
long r;
if (timeout == 0) {
return amdgpu_fence_any_seq_signaled(adev, target_seq);
}
while (!amdgpu_fence_any_seq_signaled(adev, target_seq)) {
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !target_seq[i])
continue;
last_seq[i] = atomic64_read(&ring->fence_drv.last_seq);
trace_amdgpu_fence_wait_begin(adev->ddev, i, target_seq[i]);
amdgpu_irq_get(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type);
}
if (intr) {
r = wait_event_interruptible_timeout(adev->fence_queue, (
(signaled = amdgpu_fence_any_seq_signaled(adev, target_seq))
|| adev->needs_reset), AMDGPU_FENCE_JIFFIES_TIMEOUT);
} else {
r = wait_event_timeout(adev->fence_queue, (
(signaled = amdgpu_fence_any_seq_signaled(adev, target_seq))
|| adev->needs_reset), AMDGPU_FENCE_JIFFIES_TIMEOUT);
}
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !target_seq[i])
continue;
amdgpu_irq_put(adev, ring->fence_drv.irq_src,
ring->fence_drv.irq_type);
trace_amdgpu_fence_wait_end(adev->ddev, i, target_seq[i]);
}
if (unlikely(r < 0))
return r;
if (unlikely(!signaled)) {
if (adev->needs_reset)
return -EDEADLK;
if (r)
continue;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_ring *ring = adev->rings[i];
if (!ring || !target_seq[i])
continue;
if (last_seq[i] != atomic64_read(&ring->fence_drv.last_seq))
break;
}
if (i != AMDGPU_MAX_RINGS)
continue;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
if (!adev->rings[i] || !target_seq[i])
continue;
if (amdgpu_ring_is_lockup(adev->rings[i]))
break;
}
if (i < AMDGPU_MAX_RINGS) {
dev_warn(adev->dev, "GPU lockup (waiting for "
"0x%016llx last fence id 0x%016llx on"
" ring %d)\n",
target_seq[i], last_seq[i], i);
adev->needs_reset = true;
wake_up_all(&adev->fence_queue);
return -EDEADLK;
}
if (timeout < MAX_SCHEDULE_TIMEOUT) {
timeout -= AMDGPU_FENCE_JIFFIES_TIMEOUT;
if (timeout <= 0) {
return 0;
}
}
}
}
return timeout;
}
int amdgpu_fence_wait(struct amdgpu_fence *fence, bool intr)
{
uint64_t seq[AMDGPU_MAX_RINGS] = {};
long r;
seq[fence->ring->idx] = fence->seq;
r = amdgpu_fence_wait_seq_timeout(fence->ring->adev, seq, intr, MAX_SCHEDULE_TIMEOUT);
if (r < 0) {
return r;
}
r = fence_signal(&fence->base);
if (!r)
FENCE_TRACE(&fence->base, "signaled from fence_wait\n");
return 0;
}
int amdgpu_fence_wait_any(struct amdgpu_device *adev,
struct amdgpu_fence **fences,
bool intr)
{
uint64_t seq[AMDGPU_MAX_RINGS];
unsigned i, num_rings = 0;
long r;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
seq[i] = 0;
if (!fences[i]) {
continue;
}
seq[i] = fences[i]->seq;
++num_rings;
}
if (num_rings == 0)
return -ENOENT;
r = amdgpu_fence_wait_seq_timeout(adev, seq, intr, MAX_SCHEDULE_TIMEOUT);
if (r < 0) {
return r;
}
return 0;
}
int amdgpu_fence_wait_next(struct amdgpu_ring *ring)
{
uint64_t seq[AMDGPU_MAX_RINGS] = {};
long r;
seq[ring->idx] = atomic64_read(&ring->fence_drv.last_seq) + 1ULL;
if (seq[ring->idx] >= ring->fence_drv.sync_seq[ring->idx]) {
return -ENOENT;
}
r = amdgpu_fence_wait_seq_timeout(ring->adev, seq, false, MAX_SCHEDULE_TIMEOUT);
if (r < 0)
return r;
return 0;
}
int amdgpu_fence_wait_empty(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
uint64_t seq[AMDGPU_MAX_RINGS] = {};
long r;
seq[ring->idx] = ring->fence_drv.sync_seq[ring->idx];
if (!seq[ring->idx])
return 0;
r = amdgpu_fence_wait_seq_timeout(adev, seq, false, MAX_SCHEDULE_TIMEOUT);
if (r < 0) {
if (r == -EDEADLK)
return -EDEADLK;
dev_err(adev->dev, "error waiting for ring[%d] to become idle (%ld)\n",
ring->idx, r);
}
return 0;
}
struct amdgpu_fence *amdgpu_fence_ref(struct amdgpu_fence *fence)
{
fence_get(&fence->base);
return fence;
}
void amdgpu_fence_unref(struct amdgpu_fence **fence)
{
struct amdgpu_fence *tmp = *fence;
*fence = NULL;
if (tmp)
fence_put(&tmp->base);
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
ring->fence_drv.initialized = true;
ring->fence_drv.irq_src = irq_src;
ring->fence_drv.irq_type = irq_type;
dev_info(adev->dev, "fence driver on ring %d use gpu addr 0x%016llx, "
"cpu addr 0x%p\n", ring->idx,
ring->fence_drv.gpu_addr, ring->fence_drv.cpu_addr);
return 0;
}
void amdgpu_fence_driver_init_ring(struct amdgpu_ring *ring)
{
int i;
ring->fence_drv.cpu_addr = NULL;
ring->fence_drv.gpu_addr = 0;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i)
ring->fence_drv.sync_seq[i] = 0;
atomic64_set(&ring->fence_drv.last_seq, 0);
ring->fence_drv.initialized = false;
INIT_DELAYED_WORK(&ring->fence_drv.lockup_work,
amdgpu_fence_check_lockup);
ring->fence_drv.ring = ring;
}
int amdgpu_fence_driver_init(struct amdgpu_device *adev)
{
init_waitqueue_head(&adev->fence_queue);
if (amdgpu_debugfs_fence_init(adev))
dev_err(adev->dev, "fence debugfs file creation failed\n");
return 0;
}
void amdgpu_fence_driver_fini(struct amdgpu_device *adev)
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
wake_up_all(&adev->fence_queue);
ring->fence_drv.initialized = false;
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
static const char *amdgpu_fence_get_driver_name(struct fence *fence)
{
return "amdgpu";
}
static const char *amdgpu_fence_get_timeline_name(struct fence *f)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
return (const char *)fence->ring->name;
}
static inline bool amdgpu_test_signaled(struct amdgpu_fence *fence)
{
return test_bit(FENCE_FLAG_SIGNALED_BIT, &fence->base.flags);
}
static void amdgpu_fence_wait_cb(struct fence *fence, struct fence_cb *cb)
{
struct amdgpu_wait_cb *wait =
container_of(cb, struct amdgpu_wait_cb, base);
wake_up_process(wait->task);
}
static signed long amdgpu_fence_default_wait(struct fence *f, bool intr,
signed long t)
{
struct amdgpu_fence *fence = to_amdgpu_fence(f);
struct amdgpu_device *adev = fence->ring->adev;
struct amdgpu_wait_cb cb;
cb.task = current;
if (fence_add_callback(f, &cb.base, amdgpu_fence_wait_cb))
return t;
while (t > 0) {
if (intr)
set_current_state(TASK_INTERRUPTIBLE);
else
set_current_state(TASK_UNINTERRUPTIBLE);
if (amdgpu_test_signaled(fence))
break;
if (adev->needs_reset) {
t = -EDEADLK;
break;
}
t = schedule_timeout(t);
if (t > 0 && intr && signal_pending(current))
t = -ERESTARTSYS;
}
__set_current_state(TASK_RUNNING);
fence_remove_callback(f, &cb.base);
return t;
}
