static void radeon_fence_write(struct radeon_device *rdev, u32 seq, int ring)
{
struct radeon_fence_driver *drv = &rdev->fence_drv[ring];
if (likely(rdev->wb.enabled || !drv->scratch_reg)) {
if (drv->cpu_addr) {
*drv->cpu_addr = cpu_to_le32(seq);
}
} else {
WREG32(drv->scratch_reg, seq);
}
}
static u32 radeon_fence_read(struct radeon_device *rdev, int ring)
{
struct radeon_fence_driver *drv = &rdev->fence_drv[ring];
u32 seq = 0;
if (likely(rdev->wb.enabled || !drv->scratch_reg)) {
if (drv->cpu_addr) {
seq = le32_to_cpu(*drv->cpu_addr);
} else {
seq = lower_32_bits(atomic64_read(&drv->last_seq));
}
} else {
seq = RREG32(drv->scratch_reg);
}
return seq;
}
static void radeon_fence_schedule_check(struct radeon_device *rdev, int ring)
{
queue_delayed_work(system_power_efficient_wq,
&rdev->fence_drv[ring].lockup_work,
RADEON_FENCE_JIFFIES_TIMEOUT);
}
int radeon_fence_emit(struct radeon_device *rdev,
struct radeon_fence **fence,
int ring)
{
u64 seq = ++rdev->fence_drv[ring].sync_seq[ring];
*fence = kmalloc(sizeof(struct radeon_fence), GFP_KERNEL);
if ((*fence) == NULL) {
return -ENOMEM;
}
(*fence)->rdev = rdev;
(*fence)->seq = seq;
(*fence)->ring = ring;
fence_init(&(*fence)->base, &radeon_fence_ops,
&rdev->fence_queue.lock, rdev->fence_context + ring, seq);
radeon_fence_ring_emit(rdev, ring, *fence);
trace_radeon_fence_emit(rdev->ddev, ring, (*fence)->seq);
radeon_fence_schedule_check(rdev, ring);
return 0;
}
static int radeon_fence_check_signaled(wait_queue_t *wait, unsigned mode, int flags, void *key)
{
struct radeon_fence *fence;
u64 seq;
fence = container_of(wait, struct radeon_fence, fence_wake);
seq = atomic64_read(&fence->rdev->fence_drv[fence->ring].last_seq);
if (seq >= fence->seq) {
int ret = fence_signal_locked(&fence->base);
if (!ret)
FENCE_TRACE(&fence->base, "signaled from irq context\n");
else
FENCE_TRACE(&fence->base, "was already signaled\n");
radeon_irq_kms_sw_irq_put(fence->rdev, fence->ring);
__remove_wait_queue(&fence->rdev->fence_queue, &fence->fence_wake);
fence_put(&fence->base);
} else
FENCE_TRACE(&fence->base, "pending\n");
return 0;
}
static bool radeon_fence_activity(struct radeon_device *rdev, int ring)
{
uint64_t seq, last_seq, last_emitted;
unsigned count_loop = 0;
bool wake = false;
last_seq = atomic64_read(&rdev->fence_drv[ring].last_seq);
do {
last_emitted = rdev->fence_drv[ring].sync_seq[ring];
seq = radeon_fence_read(rdev, ring);
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
} while (atomic64_xchg(&rdev->fence_drv[ring].last_seq, seq) > seq);
if (seq < last_emitted)
radeon_fence_schedule_check(rdev, ring);
return wake;
}
static void radeon_fence_check_lockup(struct work_struct *work)
{
struct radeon_fence_driver *fence_drv;
struct radeon_device *rdev;
int ring;
fence_drv = container_of(work, struct radeon_fence_driver,
lockup_work.work);
rdev = fence_drv->rdev;
ring = fence_drv - &rdev->fence_drv[0];
if (!down_read_trylock(&rdev->exclusive_lock)) {
radeon_fence_schedule_check(rdev, ring);
return;
}
if (fence_drv->delayed_irq && rdev->ddev->irq_enabled) {
unsigned long irqflags;
fence_drv->delayed_irq = false;
spin_lock_irqsave(&rdev->irq.lock, irqflags);
radeon_irq_set(rdev);
spin_unlock_irqrestore(&rdev->irq.lock, irqflags);
}
if (radeon_fence_activity(rdev, ring))
wake_up_all(&rdev->fence_queue);
else if (radeon_ring_is_lockup(rdev, ring, &rdev->ring[ring])) {
dev_warn(rdev->dev, "GPU lockup (current fence id "
"0x%016llx last fence id 0x%016llx on ring %d)\n",
(uint64_t)atomic64_read(&fence_drv->last_seq),
fence_drv->sync_seq[ring], ring);
rdev->needs_reset = true;
wake_up_all(&rdev->fence_queue);
}
up_read(&rdev->exclusive_lock);
}
void radeon_fence_process(struct radeon_device *rdev, int ring)
{
if (radeon_fence_activity(rdev, ring))
wake_up_all(&rdev->fence_queue);
}
static bool radeon_fence_seq_signaled(struct radeon_device *rdev,
u64 seq, unsigned ring)
{
if (atomic64_read(&rdev->fence_drv[ring].last_seq) >= seq) {
return true;
}
radeon_fence_process(rdev, ring);
if (atomic64_read(&rdev->fence_drv[ring].last_seq) >= seq) {
return true;
}
return false;
}
static bool radeon_fence_is_signaled(struct fence *f)
{
struct radeon_fence *fence = to_radeon_fence(f);
struct radeon_device *rdev = fence->rdev;
unsigned ring = fence->ring;
u64 seq = fence->seq;
if (atomic64_read(&rdev->fence_drv[ring].last_seq) >= seq) {
return true;
}
if (down_read_trylock(&rdev->exclusive_lock)) {
radeon_fence_process(rdev, ring);
up_read(&rdev->exclusive_lock);
if (atomic64_read(&rdev->fence_drv[ring].last_seq) >= seq) {
return true;
}
}
return false;
}
static bool radeon_fence_enable_signaling(struct fence *f)
{
struct radeon_fence *fence = to_radeon_fence(f);
struct radeon_device *rdev = fence->rdev;
if (atomic64_read(&rdev->fence_drv[fence->ring].last_seq) >= fence->seq)
return false;
if (down_read_trylock(&rdev->exclusive_lock)) {
radeon_irq_kms_sw_irq_get(rdev, fence->ring);
if (radeon_fence_activity(rdev, fence->ring))
wake_up_all_locked(&rdev->fence_queue);
if (atomic64_read(&rdev->fence_drv[fence->ring].last_seq) >= fence->seq) {
radeon_irq_kms_sw_irq_put(rdev, fence->ring);
up_read(&rdev->exclusive_lock);
return false;
}
up_read(&rdev->exclusive_lock);
} else {
if (radeon_irq_kms_sw_irq_get_delayed(rdev, fence->ring))
rdev->fence_drv[fence->ring].delayed_irq = true;
radeon_fence_schedule_check(rdev, fence->ring);
}
fence->fence_wake.flags = 0;
fence->fence_wake.private = NULL;
fence->fence_wake.func = radeon_fence_check_signaled;
__add_wait_queue(&rdev->fence_queue, &fence->fence_wake);
fence_get(f);
FENCE_TRACE(&fence->base, "armed on ring %i!\n", fence->ring);
return true;
}
bool radeon_fence_signaled(struct radeon_fence *fence)
{
if (!fence)
return true;
if (radeon_fence_seq_signaled(fence->rdev, fence->seq, fence->ring)) {
int ret;
ret = fence_signal(&fence->base);
if (!ret)
FENCE_TRACE(&fence->base, "signaled from radeon_fence_signaled\n");
return true;
}
return false;
}
static bool radeon_fence_any_seq_signaled(struct radeon_device *rdev, u64 *seq)
{
unsigned i;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (seq[i] && radeon_fence_seq_signaled(rdev, seq[i], i))
return true;
}
return false;
}
static long radeon_fence_wait_seq_timeout(struct radeon_device *rdev,
u64 *target_seq, bool intr,
long timeout)
{
long r;
int i;
if (radeon_fence_any_seq_signaled(rdev, target_seq))
return timeout;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (!target_seq[i])
continue;
trace_radeon_fence_wait_begin(rdev->ddev, i, target_seq[i]);
radeon_irq_kms_sw_irq_get(rdev, i);
}
if (intr) {
r = wait_event_interruptible_timeout(rdev->fence_queue, (
radeon_fence_any_seq_signaled(rdev, target_seq)
|| rdev->needs_reset), timeout);
} else {
r = wait_event_timeout(rdev->fence_queue, (
radeon_fence_any_seq_signaled(rdev, target_seq)
|| rdev->needs_reset), timeout);
}
if (rdev->needs_reset)
r = -EDEADLK;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (!target_seq[i])
continue;
radeon_irq_kms_sw_irq_put(rdev, i);
trace_radeon_fence_wait_end(rdev->ddev, i, target_seq[i]);
}
return r;
}
int radeon_fence_wait(struct radeon_fence *fence, bool intr)
{
uint64_t seq[RADEON_NUM_RINGS] = {};
long r;
if (WARN_ON_ONCE(!to_radeon_fence(&fence->base)))
return fence_wait(&fence->base, intr);
seq[fence->ring] = fence->seq;
r = radeon_fence_wait_seq_timeout(fence->rdev, seq, intr, MAX_SCHEDULE_TIMEOUT);
if (r < 0) {
return r;
}
r = fence_signal(&fence->base);
if (!r)
FENCE_TRACE(&fence->base, "signaled from fence_wait\n");
return 0;
}
int radeon_fence_wait_any(struct radeon_device *rdev,
struct radeon_fence **fences,
bool intr)
{
uint64_t seq[RADEON_NUM_RINGS];
unsigned i, num_rings = 0;
long r;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
seq[i] = 0;
if (!fences[i]) {
continue;
}
seq[i] = fences[i]->seq;
++num_rings;
}
if (num_rings == 0)
return -ENOENT;
r = radeon_fence_wait_seq_timeout(rdev, seq, intr, MAX_SCHEDULE_TIMEOUT);
if (r < 0) {
return r;
}
return 0;
}
int radeon_fence_wait_next(struct radeon_device *rdev, int ring)
{
uint64_t seq[RADEON_NUM_RINGS] = {};
long r;
seq[ring] = atomic64_read(&rdev->fence_drv[ring].last_seq) + 1ULL;
if (seq[ring] >= rdev->fence_drv[ring].sync_seq[ring]) {
return -ENOENT;
}
r = radeon_fence_wait_seq_timeout(rdev, seq, false, MAX_SCHEDULE_TIMEOUT);
if (r < 0)
return r;
return 0;
}
int radeon_fence_wait_empty(struct radeon_device *rdev, int ring)
{
uint64_t seq[RADEON_NUM_RINGS] = {};
long r;
seq[ring] = rdev->fence_drv[ring].sync_seq[ring];
if (!seq[ring])
return 0;
r = radeon_fence_wait_seq_timeout(rdev, seq, false, MAX_SCHEDULE_TIMEOUT);
if (r < 0) {
if (r == -EDEADLK)
return -EDEADLK;
dev_err(rdev->dev, "error waiting for ring[%d] to become idle (%ld)\n",
ring, r);
}
return 0;
}
struct radeon_fence *radeon_fence_ref(struct radeon_fence *fence)
{
fence_get(&fence->base);
return fence;
}
void radeon_fence_unref(struct radeon_fence **fence)
{
struct radeon_fence *tmp = *fence;
*fence = NULL;
if (tmp) {
fence_put(&tmp->base);
}
}
unsigned radeon_fence_count_emitted(struct radeon_device *rdev, int ring)
{
uint64_t emitted;
radeon_fence_process(rdev, ring);
emitted = rdev->fence_drv[ring].sync_seq[ring]
- atomic64_read(&rdev->fence_drv[ring].last_seq);
if (emitted > 0x10000000) {
emitted = 0x10000000;
}
return (unsigned)emitted;
}
bool radeon_fence_need_sync(struct radeon_fence *fence, int dst_ring)
{
struct radeon_fence_driver *fdrv;
if (!fence) {
return false;
}
if (fence->ring == dst_ring) {
return false;
}
fdrv = &fence->rdev->fence_drv[dst_ring];
if (fence->seq <= fdrv->sync_seq[fence->ring]) {
return false;
}
return true;
}
void radeon_fence_note_sync(struct radeon_fence *fence, int dst_ring)
{
struct radeon_fence_driver *dst, *src;
unsigned i;
if (!fence) {
return;
}
if (fence->ring == dst_ring) {
return;
}
src = &fence->rdev->fence_drv[fence->ring];
dst = &fence->rdev->fence_drv[dst_ring];
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (i == dst_ring) {
continue;
}
dst->sync_seq[i] = max(dst->sync_seq[i], src->sync_seq[i]);
}
}
int radeon_fence_driver_start_ring(struct radeon_device *rdev, int ring)
{
uint64_t index;
int r;
radeon_scratch_free(rdev, rdev->fence_drv[ring].scratch_reg);
if (rdev->wb.use_event || !radeon_ring_supports_scratch_reg(rdev, &rdev->ring[ring])) {
rdev->fence_drv[ring].scratch_reg = 0;
if (ring != R600_RING_TYPE_UVD_INDEX) {
index = R600_WB_EVENT_OFFSET + ring * 4;
rdev->fence_drv[ring].cpu_addr = &rdev->wb.wb[index/4];
rdev->fence_drv[ring].gpu_addr = rdev->wb.gpu_addr +
index;
} else {
index = ALIGN(rdev->uvd_fw->size, 8);
rdev->fence_drv[ring].cpu_addr = rdev->uvd.cpu_addr + index;
rdev->fence_drv[ring].gpu_addr = rdev->uvd.gpu_addr + index;
}
} else {
r = radeon_scratch_get(rdev, &rdev->fence_drv[ring].scratch_reg);
if (r) {
dev_err(rdev->dev, "fence failed to get scratch register\n");
return r;
}
index = RADEON_WB_SCRATCH_OFFSET +
rdev->fence_drv[ring].scratch_reg -
rdev->scratch.reg_base;
rdev->fence_drv[ring].cpu_addr = &rdev->wb.wb[index/4];
rdev->fence_drv[ring].gpu_addr = rdev->wb.gpu_addr + index;
}
radeon_fence_write(rdev, atomic64_read(&rdev->fence_drv[ring].last_seq), ring);
rdev->fence_drv[ring].initialized = true;
dev_info(rdev->dev, "fence driver on ring %d use gpu addr 0x%016llx and cpu addr 0x%p\n",
ring, rdev->fence_drv[ring].gpu_addr, rdev->fence_drv[ring].cpu_addr);
return 0;
}
static void radeon_fence_driver_init_ring(struct radeon_device *rdev, int ring)
{
int i;
rdev->fence_drv[ring].scratch_reg = -1;
rdev->fence_drv[ring].cpu_addr = NULL;
rdev->fence_drv[ring].gpu_addr = 0;
for (i = 0; i < RADEON_NUM_RINGS; ++i)
rdev->fence_drv[ring].sync_seq[i] = 0;
atomic64_set(&rdev->fence_drv[ring].last_seq, 0);
rdev->fence_drv[ring].initialized = false;
INIT_DELAYED_WORK(&rdev->fence_drv[ring].lockup_work,
radeon_fence_check_lockup);
rdev->fence_drv[ring].rdev = rdev;
}
int radeon_fence_driver_init(struct radeon_device *rdev)
{
int ring;
init_waitqueue_head(&rdev->fence_queue);
for (ring = 0; ring < RADEON_NUM_RINGS; ring++) {
radeon_fence_driver_init_ring(rdev, ring);
}
if (radeon_debugfs_fence_init(rdev)) {
dev_err(rdev->dev, "fence debugfs file creation failed\n");
}
return 0;
}
void radeon_fence_driver_fini(struct radeon_device *rdev)
{
int ring, r;
mutex_lock(&rdev->ring_lock);
for (ring = 0; ring < RADEON_NUM_RINGS; ring++) {
if (!rdev->fence_drv[ring].initialized)
continue;
r = radeon_fence_wait_empty(rdev, ring);
if (r) {
radeon_fence_driver_force_completion(rdev, ring);
}
cancel_delayed_work_sync(&rdev->fence_drv[ring].lockup_work);
wake_up_all(&rdev->fence_queue);
radeon_scratch_free(rdev, rdev->fence_drv[ring].scratch_reg);
rdev->fence_drv[ring].initialized = false;
}
mutex_unlock(&rdev->ring_lock);
}
void radeon_fence_driver_force_completion(struct radeon_device *rdev, int ring)
{
if (rdev->fence_drv[ring].initialized) {
radeon_fence_write(rdev, rdev->fence_drv[ring].sync_seq[ring], ring);
cancel_delayed_work_sync(&rdev->fence_drv[ring].lockup_work);
}
}
static int radeon_debugfs_fence_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct radeon_device *rdev = dev->dev_private;
int i, j;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (!rdev->fence_drv[i].initialized)
continue;
radeon_fence_process(rdev, i);
seq_printf(m, "--- ring %d ---\n", i);
seq_printf(m, "Last signaled fence 0x%016llx\n",
(unsigned long long)atomic64_read(&rdev->fence_drv[i].last_seq));
seq_printf(m, "Last emitted 0x%016llx\n",
rdev->fence_drv[i].sync_seq[i]);
for (j = 0; j < RADEON_NUM_RINGS; ++j) {
if (i != j && rdev->fence_drv[j].initialized)
seq_printf(m, "Last sync to ring %d 0x%016llx\n",
j, rdev->fence_drv[i].sync_seq[j]);
}
}
return 0;
}
static int radeon_debugfs_gpu_reset(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct radeon_device *rdev = dev->dev_private;
down_read(&rdev->exclusive_lock);
seq_printf(m, "%d\n", rdev->needs_reset);
rdev->needs_reset = true;
wake_up_all(&rdev->fence_queue);
up_read(&rdev->exclusive_lock);
return 0;
}
int radeon_debugfs_fence_init(struct radeon_device *rdev)
{
#if defined(CONFIG_DEBUG_FS)
return radeon_debugfs_add_files(rdev, radeon_debugfs_fence_list, 2);
#else
return 0;
#endif
}
static const char *radeon_fence_get_driver_name(struct fence *fence)
{
return "radeon";
}
static const char *radeon_fence_get_timeline_name(struct fence *f)
{
struct radeon_fence *fence = to_radeon_fence(f);
switch (fence->ring) {
case RADEON_RING_TYPE_GFX_INDEX: return "radeon.gfx";
case CAYMAN_RING_TYPE_CP1_INDEX: return "radeon.cp1";
case CAYMAN_RING_TYPE_CP2_INDEX: return "radeon.cp2";
case R600_RING_TYPE_DMA_INDEX: return "radeon.dma";
case CAYMAN_RING_TYPE_DMA1_INDEX: return "radeon.dma1";
case R600_RING_TYPE_UVD_INDEX: return "radeon.uvd";
case TN_RING_TYPE_VCE1_INDEX: return "radeon.vce1";
case TN_RING_TYPE_VCE2_INDEX: return "radeon.vce2";
default: WARN_ON_ONCE(1); return "radeon.unk";
}
}
static inline bool radeon_test_signaled(struct radeon_fence *fence)
{
return test_bit(FENCE_FLAG_SIGNALED_BIT, &fence->base.flags);
}
static signed long radeon_fence_default_wait(struct fence *f, bool intr,
signed long t)
{
struct radeon_fence *fence = to_radeon_fence(f);
struct radeon_device *rdev = fence->rdev;
bool signaled;
fence_enable_sw_signaling(&fence->base);
if (intr)
t = wait_event_interruptible_timeout(rdev->fence_queue,
((signaled = radeon_test_signaled(fence)) ||
rdev->needs_reset), t);
else
t = wait_event_timeout(rdev->fence_queue,
((signaled = radeon_test_signaled(fence)) ||
rdev->needs_reset), t);
if (t > 0 && !signaled)
return -EDEADLK;
return t;
}
