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
int radeon_fence_emit(struct radeon_device *rdev,
struct radeon_fence **fence,
int ring)
{
*fence = kmalloc(sizeof(struct radeon_fence), GFP_KERNEL);
if ((*fence) == NULL) {
return -ENOMEM;
}
kref_init(&((*fence)->kref));
(*fence)->rdev = rdev;
(*fence)->seq = ++rdev->fence_drv[ring].sync_seq[ring];
(*fence)->ring = ring;
radeon_fence_ring_emit(rdev, ring, *fence);
trace_radeon_fence_emit(rdev->ddev, (*fence)->seq);
return 0;
}
void radeon_fence_process(struct radeon_device *rdev, int ring)
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
if (wake)
wake_up_all(&rdev->fence_queue);
}
static void radeon_fence_destroy(struct kref *kref)
{
struct radeon_fence *fence;
fence = container_of(kref, struct radeon_fence, kref);
kfree(fence);
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
bool radeon_fence_signaled(struct radeon_fence *fence)
{
if (!fence) {
return true;
}
if (fence->seq == RADEON_FENCE_SIGNALED_SEQ) {
return true;
}
if (radeon_fence_seq_signaled(fence->rdev, fence->seq, fence->ring)) {
fence->seq = RADEON_FENCE_SIGNALED_SEQ;
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
static int radeon_fence_wait_seq(struct radeon_device *rdev, u64 *target_seq,
bool intr, bool lock_ring)
{
uint64_t last_seq[RADEON_NUM_RINGS];
bool signaled;
int i, r;
while (!radeon_fence_any_seq_signaled(rdev, target_seq)) {
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (!target_seq[i])
continue;
last_seq[i] = atomic64_read(&rdev->fence_drv[i].last_seq);
trace_radeon_fence_wait_begin(rdev->ddev, target_seq[i]);
radeon_irq_kms_sw_irq_get(rdev, i);
}
if (intr) {
r = wait_event_interruptible_timeout(rdev->fence_queue, (
(signaled = radeon_fence_any_seq_signaled(rdev, target_seq))
|| rdev->needs_reset), RADEON_FENCE_JIFFIES_TIMEOUT);
} else {
r = wait_event_timeout(rdev->fence_queue, (
(signaled = radeon_fence_any_seq_signaled(rdev, target_seq))
|| rdev->needs_reset), RADEON_FENCE_JIFFIES_TIMEOUT);
}
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (!target_seq[i])
continue;
radeon_irq_kms_sw_irq_put(rdev, i);
trace_radeon_fence_wait_end(rdev->ddev, target_seq[i]);
}
if (unlikely(r < 0))
return r;
if (unlikely(!signaled)) {
if (rdev->needs_reset)
return -EDEADLK;
if (r)
continue;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (!target_seq[i])
continue;
if (last_seq[i] != atomic64_read(&rdev->fence_drv[i].last_seq))
break;
}
if (i != RADEON_NUM_RINGS)
continue;
if (lock_ring)
mutex_lock(&rdev->ring_lock);
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
if (!target_seq[i])
continue;
if (radeon_ring_is_lockup(rdev, i, &rdev->ring[i]))
break;
}
if (i < RADEON_NUM_RINGS) {
dev_warn(rdev->dev, "GPU lockup (waiting for "
"0x%016llx last fence id 0x%016llx on"
" ring %d)\n",
target_seq[i], last_seq[i], i);
rdev->needs_reset = true;
if (lock_ring)
mutex_unlock(&rdev->ring_lock);
wake_up_all(&rdev->fence_queue);
return -EDEADLK;
}
if (lock_ring)
mutex_unlock(&rdev->ring_lock);
}
}
return 0;
}
int radeon_fence_wait(struct radeon_fence *fence, bool intr)
{
uint64_t seq[RADEON_NUM_RINGS] = {};
int r;
if (fence == NULL) {
WARN(1, "Querying an invalid fence : %p !\n", fence);
return -EINVAL;
}
seq[fence->ring] = fence->seq;
if (seq[fence->ring] == RADEON_FENCE_SIGNALED_SEQ)
return 0;
r = radeon_fence_wait_seq(fence->rdev, seq, intr, true);
if (r)
return r;
fence->seq = RADEON_FENCE_SIGNALED_SEQ;
return 0;
}
int radeon_fence_wait_any(struct radeon_device *rdev,
struct radeon_fence **fences,
bool intr)
{
uint64_t seq[RADEON_NUM_RINGS];
unsigned i, num_rings = 0;
int r;
for (i = 0; i < RADEON_NUM_RINGS; ++i) {
seq[i] = 0;
if (!fences[i]) {
continue;
}
seq[i] = fences[i]->seq;
++num_rings;
if (seq[i] == RADEON_FENCE_SIGNALED_SEQ)
return 0;
}
if (num_rings == 0)
return -ENOENT;
r = radeon_fence_wait_seq(rdev, seq, intr, true);
if (r) {
return r;
}
return 0;
}
int radeon_fence_wait_locked(struct radeon_fence *fence)
{
uint64_t seq[RADEON_NUM_RINGS] = {};
int r;
if (fence == NULL) {
WARN(1, "Querying an invalid fence : %p !\n", fence);
return -EINVAL;
}
seq[fence->ring] = fence->seq;
if (seq[fence->ring] == RADEON_FENCE_SIGNALED_SEQ)
return 0;
r = radeon_fence_wait_seq(fence->rdev, seq, false, false);
if (r)
return r;
fence->seq = RADEON_FENCE_SIGNALED_SEQ;
return 0;
}
int radeon_fence_wait_next_locked(struct radeon_device *rdev, int ring)
{
uint64_t seq[RADEON_NUM_RINGS] = {};
seq[ring] = atomic64_read(&rdev->fence_drv[ring].last_seq) + 1ULL;
if (seq[ring] >= rdev->fence_drv[ring].sync_seq[ring]) {
return -ENOENT;
}
return radeon_fence_wait_seq(rdev, seq, false, false);
}
int radeon_fence_wait_empty_locked(struct radeon_device *rdev, int ring)
{
uint64_t seq[RADEON_NUM_RINGS] = {};
int r;
seq[ring] = rdev->fence_drv[ring].sync_seq[ring];
if (!seq[ring])
return 0;
r = radeon_fence_wait_seq(rdev, seq, false, false);
if (r) {
if (r == -EDEADLK)
return -EDEADLK;
dev_err(rdev->dev, "error waiting for ring[%d] to become idle (%d)\n",
ring, r);
}
return 0;
}
struct radeon_fence *radeon_fence_ref(struct radeon_fence *fence)
{
kref_get(&fence->kref);
return fence;
}
void radeon_fence_unref(struct radeon_fence **fence)
{
struct radeon_fence *tmp = *fence;
*fence = NULL;
if (tmp) {
kref_put(&tmp->kref, radeon_fence_destroy);
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
r = radeon_fence_wait_empty_locked(rdev, ring);
if (r) {
radeon_fence_driver_force_completion(rdev);
}
wake_up_all(&rdev->fence_queue);
radeon_scratch_free(rdev, rdev->fence_drv[ring].scratch_reg);
rdev->fence_drv[ring].initialized = false;
}
mutex_unlock(&rdev->ring_lock);
}
void radeon_fence_driver_force_completion(struct radeon_device *rdev)
{
int ring;
for (ring = 0; ring < RADEON_NUM_RINGS; ring++) {
if (!rdev->fence_drv[ring].initialized)
continue;
radeon_fence_write(rdev, rdev->fence_drv[ring].sync_seq[ring], ring);
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
int radeon_debugfs_fence_init(struct radeon_device *rdev)
{
#if defined(CONFIG_DEBUG_FS)
return radeon_debugfs_add_files(rdev, radeon_debugfs_fence_list, 1);
#else
return 0;
#endif
}
