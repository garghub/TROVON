static void free_oa_config(struct drm_i915_private *dev_priv,
struct i915_oa_config *oa_config)
{
if (!PTR_ERR(oa_config->flex_regs))
kfree(oa_config->flex_regs);
if (!PTR_ERR(oa_config->b_counter_regs))
kfree(oa_config->b_counter_regs);
if (!PTR_ERR(oa_config->mux_regs))
kfree(oa_config->mux_regs);
kfree(oa_config);
}
static void put_oa_config(struct drm_i915_private *dev_priv,
struct i915_oa_config *oa_config)
{
if (!atomic_dec_and_test(&oa_config->ref_count))
return;
free_oa_config(dev_priv, oa_config);
}
static int get_oa_config(struct drm_i915_private *dev_priv,
int metrics_set,
struct i915_oa_config **out_config)
{
int ret;
if (metrics_set == 1) {
*out_config = &dev_priv->perf.oa.test_config;
atomic_inc(&dev_priv->perf.oa.test_config.ref_count);
return 0;
}
ret = mutex_lock_interruptible(&dev_priv->perf.metrics_lock);
if (ret)
return ret;
*out_config = idr_find(&dev_priv->perf.metrics_idr, metrics_set);
if (!*out_config)
ret = -EINVAL;
else
atomic_inc(&(*out_config)->ref_count);
mutex_unlock(&dev_priv->perf.metrics_lock);
return ret;
}
static u32 gen8_oa_hw_tail_read(struct drm_i915_private *dev_priv)
{
return I915_READ(GEN8_OATAILPTR) & GEN8_OATAILPTR_MASK;
}
static u32 gen7_oa_hw_tail_read(struct drm_i915_private *dev_priv)
{
u32 oastatus1 = I915_READ(GEN7_OASTATUS1);
return oastatus1 & GEN7_OASTATUS1_TAIL_MASK;
}
static bool oa_buffer_check_unlocked(struct drm_i915_private *dev_priv)
{
int report_size = dev_priv->perf.oa.oa_buffer.format_size;
unsigned long flags;
unsigned int aged_idx;
u32 head, hw_tail, aged_tail, aging_tail;
u64 now;
spin_lock_irqsave(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
head = dev_priv->perf.oa.oa_buffer.head;
aged_idx = dev_priv->perf.oa.oa_buffer.aged_tail_idx;
aged_tail = dev_priv->perf.oa.oa_buffer.tails[aged_idx].offset;
aging_tail = dev_priv->perf.oa.oa_buffer.tails[!aged_idx].offset;
hw_tail = dev_priv->perf.oa.ops.oa_hw_tail_read(dev_priv);
hw_tail &= ~(report_size - 1);
now = ktime_get_mono_fast_ns();
if (aging_tail != INVALID_TAIL_PTR &&
((now - dev_priv->perf.oa.oa_buffer.aging_timestamp) >
OA_TAIL_MARGIN_NSEC)) {
aged_idx ^= 1;
dev_priv->perf.oa.oa_buffer.aged_tail_idx = aged_idx;
aged_tail = aging_tail;
dev_priv->perf.oa.oa_buffer.tails[!aged_idx].offset = INVALID_TAIL_PTR;
aging_tail = INVALID_TAIL_PTR;
}
if (aging_tail == INVALID_TAIL_PTR &&
(aged_tail == INVALID_TAIL_PTR ||
OA_TAKEN(hw_tail, aged_tail) >= report_size)) {
struct i915_vma *vma = dev_priv->perf.oa.oa_buffer.vma;
u32 gtt_offset = i915_ggtt_offset(vma);
if (hw_tail >= gtt_offset &&
hw_tail < (gtt_offset + OA_BUFFER_SIZE)) {
dev_priv->perf.oa.oa_buffer.tails[!aged_idx].offset =
aging_tail = hw_tail;
dev_priv->perf.oa.oa_buffer.aging_timestamp = now;
} else {
DRM_ERROR("Ignoring spurious out of range OA buffer tail pointer = %u\n",
hw_tail);
}
}
spin_unlock_irqrestore(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
return aged_tail == INVALID_TAIL_PTR ?
false : OA_TAKEN(aged_tail, head) >= report_size;
}
static int append_oa_status(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset,
enum drm_i915_perf_record_type type)
{
struct drm_i915_perf_record_header header = { type, 0, sizeof(header) };
if ((count - *offset) < header.size)
return -ENOSPC;
if (copy_to_user(buf + *offset, &header, sizeof(header)))
return -EFAULT;
(*offset) += header.size;
return 0;
}
static int append_oa_sample(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset,
const u8 *report)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
int report_size = dev_priv->perf.oa.oa_buffer.format_size;
struct drm_i915_perf_record_header header;
u32 sample_flags = stream->sample_flags;
header.type = DRM_I915_PERF_RECORD_SAMPLE;
header.pad = 0;
header.size = stream->sample_size;
if ((count - *offset) < header.size)
return -ENOSPC;
buf += *offset;
if (copy_to_user(buf, &header, sizeof(header)))
return -EFAULT;
buf += sizeof(header);
if (sample_flags & SAMPLE_OA_REPORT) {
if (copy_to_user(buf, report, report_size))
return -EFAULT;
}
(*offset) += header.size;
return 0;
}
static int gen8_append_oa_reports(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
int report_size = dev_priv->perf.oa.oa_buffer.format_size;
u8 *oa_buf_base = dev_priv->perf.oa.oa_buffer.vaddr;
u32 gtt_offset = i915_ggtt_offset(dev_priv->perf.oa.oa_buffer.vma);
u32 mask = (OA_BUFFER_SIZE - 1);
size_t start_offset = *offset;
unsigned long flags;
unsigned int aged_tail_idx;
u32 head, tail;
u32 taken;
int ret = 0;
if (WARN_ON(!stream->enabled))
return -EIO;
spin_lock_irqsave(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
head = dev_priv->perf.oa.oa_buffer.head;
aged_tail_idx = dev_priv->perf.oa.oa_buffer.aged_tail_idx;
tail = dev_priv->perf.oa.oa_buffer.tails[aged_tail_idx].offset;
spin_unlock_irqrestore(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
if (tail == INVALID_TAIL_PTR)
return -EAGAIN;
head -= gtt_offset;
tail -= gtt_offset;
if (WARN_ONCE(head > OA_BUFFER_SIZE || head % report_size ||
tail > OA_BUFFER_SIZE || tail % report_size,
"Inconsistent OA buffer pointers: head = %u, tail = %u\n",
head, tail))
return -EIO;
for (;
(taken = OA_TAKEN(tail, head));
head = (head + report_size) & mask) {
u8 *report = oa_buf_base + head;
u32 *report32 = (void *)report;
u32 ctx_id;
u32 reason;
if (WARN_ON((OA_BUFFER_SIZE - head) < report_size)) {
DRM_ERROR("Spurious OA head ptr: non-integral report offset\n");
break;
}
reason = ((report32[0] >> OAREPORT_REASON_SHIFT) &
OAREPORT_REASON_MASK);
if (reason == 0) {
if (__ratelimit(&dev_priv->perf.oa.spurious_report_rs))
DRM_NOTE("Skipping spurious, invalid OA report\n");
continue;
}
ctx_id = report32[2] & 0x1fffff;
if (!(report32[0] & dev_priv->perf.oa.gen8_valid_ctx_bit))
ctx_id = report32[2] = INVALID_CTX_ID;
if (!dev_priv->perf.oa.exclusive_stream->ctx ||
dev_priv->perf.oa.specific_ctx_id == ctx_id ||
(dev_priv->perf.oa.oa_buffer.last_ctx_id ==
dev_priv->perf.oa.specific_ctx_id) ||
reason & OAREPORT_REASON_CTX_SWITCH) {
if (dev_priv->perf.oa.exclusive_stream->ctx &&
dev_priv->perf.oa.specific_ctx_id != ctx_id) {
report32[2] = INVALID_CTX_ID;
}
ret = append_oa_sample(stream, buf, count, offset,
report);
if (ret)
break;
dev_priv->perf.oa.oa_buffer.last_ctx_id = ctx_id;
}
report32[0] = 0;
}
if (start_offset != *offset) {
spin_lock_irqsave(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
head += gtt_offset;
I915_WRITE(GEN8_OAHEADPTR, head & GEN8_OAHEADPTR_MASK);
dev_priv->perf.oa.oa_buffer.head = head;
spin_unlock_irqrestore(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
}
return ret;
}
static int gen8_oa_read(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
u32 oastatus;
int ret;
if (WARN_ON(!dev_priv->perf.oa.oa_buffer.vaddr))
return -EIO;
oastatus = I915_READ(GEN8_OASTATUS);
if (oastatus & GEN8_OASTATUS_OABUFFER_OVERFLOW) {
ret = append_oa_status(stream, buf, count, offset,
DRM_I915_PERF_RECORD_OA_BUFFER_LOST);
if (ret)
return ret;
DRM_DEBUG("OA buffer overflow (exponent = %d): force restart\n",
dev_priv->perf.oa.period_exponent);
dev_priv->perf.oa.ops.oa_disable(dev_priv);
dev_priv->perf.oa.ops.oa_enable(dev_priv);
oastatus = I915_READ(GEN8_OASTATUS);
}
if (oastatus & GEN8_OASTATUS_REPORT_LOST) {
ret = append_oa_status(stream, buf, count, offset,
DRM_I915_PERF_RECORD_OA_REPORT_LOST);
if (ret)
return ret;
I915_WRITE(GEN8_OASTATUS,
oastatus & ~GEN8_OASTATUS_REPORT_LOST);
}
return gen8_append_oa_reports(stream, buf, count, offset);
}
static int gen7_append_oa_reports(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
int report_size = dev_priv->perf.oa.oa_buffer.format_size;
u8 *oa_buf_base = dev_priv->perf.oa.oa_buffer.vaddr;
u32 gtt_offset = i915_ggtt_offset(dev_priv->perf.oa.oa_buffer.vma);
u32 mask = (OA_BUFFER_SIZE - 1);
size_t start_offset = *offset;
unsigned long flags;
unsigned int aged_tail_idx;
u32 head, tail;
u32 taken;
int ret = 0;
if (WARN_ON(!stream->enabled))
return -EIO;
spin_lock_irqsave(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
head = dev_priv->perf.oa.oa_buffer.head;
aged_tail_idx = dev_priv->perf.oa.oa_buffer.aged_tail_idx;
tail = dev_priv->perf.oa.oa_buffer.tails[aged_tail_idx].offset;
spin_unlock_irqrestore(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
if (tail == INVALID_TAIL_PTR)
return -EAGAIN;
head -= gtt_offset;
tail -= gtt_offset;
if (WARN_ONCE(head > OA_BUFFER_SIZE || head % report_size ||
tail > OA_BUFFER_SIZE || tail % report_size,
"Inconsistent OA buffer pointers: head = %u, tail = %u\n",
head, tail))
return -EIO;
for (;
(taken = OA_TAKEN(tail, head));
head = (head + report_size) & mask) {
u8 *report = oa_buf_base + head;
u32 *report32 = (void *)report;
if (WARN_ON((OA_BUFFER_SIZE - head) < report_size)) {
DRM_ERROR("Spurious OA head ptr: non-integral report offset\n");
break;
}
if (report32[0] == 0) {
if (__ratelimit(&dev_priv->perf.oa.spurious_report_rs))
DRM_NOTE("Skipping spurious, invalid OA report\n");
continue;
}
ret = append_oa_sample(stream, buf, count, offset, report);
if (ret)
break;
report32[0] = 0;
}
if (start_offset != *offset) {
spin_lock_irqsave(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
head += gtt_offset;
I915_WRITE(GEN7_OASTATUS2,
((head & GEN7_OASTATUS2_HEAD_MASK) |
OA_MEM_SELECT_GGTT));
dev_priv->perf.oa.oa_buffer.head = head;
spin_unlock_irqrestore(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
}
return ret;
}
static int gen7_oa_read(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
u32 oastatus1;
int ret;
if (WARN_ON(!dev_priv->perf.oa.oa_buffer.vaddr))
return -EIO;
oastatus1 = I915_READ(GEN7_OASTATUS1);
oastatus1 &= ~dev_priv->perf.oa.gen7_latched_oastatus1;
if (unlikely(oastatus1 & GEN7_OASTATUS1_OABUFFER_OVERFLOW)) {
ret = append_oa_status(stream, buf, count, offset,
DRM_I915_PERF_RECORD_OA_BUFFER_LOST);
if (ret)
return ret;
DRM_DEBUG("OA buffer overflow (exponent = %d): force restart\n",
dev_priv->perf.oa.period_exponent);
dev_priv->perf.oa.ops.oa_disable(dev_priv);
dev_priv->perf.oa.ops.oa_enable(dev_priv);
oastatus1 = I915_READ(GEN7_OASTATUS1);
}
if (unlikely(oastatus1 & GEN7_OASTATUS1_REPORT_LOST)) {
ret = append_oa_status(stream, buf, count, offset,
DRM_I915_PERF_RECORD_OA_REPORT_LOST);
if (ret)
return ret;
dev_priv->perf.oa.gen7_latched_oastatus1 |=
GEN7_OASTATUS1_REPORT_LOST;
}
return gen7_append_oa_reports(stream, buf, count, offset);
}
static int i915_oa_wait_unlocked(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
if (!dev_priv->perf.oa.periodic)
return -EIO;
return wait_event_interruptible(dev_priv->perf.oa.poll_wq,
oa_buffer_check_unlocked(dev_priv));
}
static void i915_oa_poll_wait(struct i915_perf_stream *stream,
struct file *file,
poll_table *wait)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
poll_wait(file, &dev_priv->perf.oa.poll_wq, wait);
}
static int i915_oa_read(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
return dev_priv->perf.oa.ops.read(stream, buf, count, offset);
}
static int oa_get_render_ctx_id(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
if (i915.enable_execlists)
dev_priv->perf.oa.specific_ctx_id = stream->ctx->hw_id;
else {
struct intel_engine_cs *engine = dev_priv->engine[RCS];
struct intel_ring *ring;
int ret;
ret = i915_mutex_lock_interruptible(&dev_priv->drm);
if (ret)
return ret;
ring = engine->context_pin(engine, stream->ctx);
mutex_unlock(&dev_priv->drm.struct_mutex);
if (IS_ERR(ring))
return PTR_ERR(ring);
dev_priv->perf.oa.specific_ctx_id =
i915_ggtt_offset(stream->ctx->engine[engine->id].state);
}
return 0;
}
static void oa_put_render_ctx_id(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
if (i915.enable_execlists) {
dev_priv->perf.oa.specific_ctx_id = INVALID_CTX_ID;
} else {
struct intel_engine_cs *engine = dev_priv->engine[RCS];
mutex_lock(&dev_priv->drm.struct_mutex);
dev_priv->perf.oa.specific_ctx_id = INVALID_CTX_ID;
engine->context_unpin(engine, stream->ctx);
mutex_unlock(&dev_priv->drm.struct_mutex);
}
}
static void
free_oa_buffer(struct drm_i915_private *i915)
{
mutex_lock(&i915->drm.struct_mutex);
i915_gem_object_unpin_map(i915->perf.oa.oa_buffer.vma->obj);
i915_vma_unpin(i915->perf.oa.oa_buffer.vma);
i915_gem_object_put(i915->perf.oa.oa_buffer.vma->obj);
i915->perf.oa.oa_buffer.vma = NULL;
i915->perf.oa.oa_buffer.vaddr = NULL;
mutex_unlock(&i915->drm.struct_mutex);
}
static void i915_oa_stream_destroy(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
BUG_ON(stream != dev_priv->perf.oa.exclusive_stream);
mutex_lock(&dev_priv->drm.struct_mutex);
dev_priv->perf.oa.exclusive_stream = NULL;
mutex_unlock(&dev_priv->drm.struct_mutex);
dev_priv->perf.oa.ops.disable_metric_set(dev_priv);
free_oa_buffer(dev_priv);
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
intel_runtime_pm_put(dev_priv);
if (stream->ctx)
oa_put_render_ctx_id(stream);
put_oa_config(dev_priv, stream->oa_config);
if (dev_priv->perf.oa.spurious_report_rs.missed) {
DRM_NOTE("%d spurious OA report notices suppressed due to ratelimiting\n",
dev_priv->perf.oa.spurious_report_rs.missed);
}
}
static void gen7_init_oa_buffer(struct drm_i915_private *dev_priv)
{
u32 gtt_offset = i915_ggtt_offset(dev_priv->perf.oa.oa_buffer.vma);
unsigned long flags;
spin_lock_irqsave(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
I915_WRITE(GEN7_OASTATUS2, gtt_offset | OA_MEM_SELECT_GGTT);
dev_priv->perf.oa.oa_buffer.head = gtt_offset;
I915_WRITE(GEN7_OABUFFER, gtt_offset);
I915_WRITE(GEN7_OASTATUS1, gtt_offset | OABUFFER_SIZE_16M);
dev_priv->perf.oa.oa_buffer.tails[0].offset = INVALID_TAIL_PTR;
dev_priv->perf.oa.oa_buffer.tails[1].offset = INVALID_TAIL_PTR;
spin_unlock_irqrestore(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
dev_priv->perf.oa.gen7_latched_oastatus1 = 0;
memset(dev_priv->perf.oa.oa_buffer.vaddr, 0, OA_BUFFER_SIZE);
dev_priv->perf.oa.pollin = false;
}
static void gen8_init_oa_buffer(struct drm_i915_private *dev_priv)
{
u32 gtt_offset = i915_ggtt_offset(dev_priv->perf.oa.oa_buffer.vma);
unsigned long flags;
spin_lock_irqsave(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
I915_WRITE(GEN8_OASTATUS, 0);
I915_WRITE(GEN8_OAHEADPTR, gtt_offset);
dev_priv->perf.oa.oa_buffer.head = gtt_offset;
I915_WRITE(GEN8_OABUFFER_UDW, 0);
I915_WRITE(GEN8_OABUFFER, gtt_offset |
OABUFFER_SIZE_16M | OA_MEM_SELECT_GGTT);
I915_WRITE(GEN8_OATAILPTR, gtt_offset & GEN8_OATAILPTR_MASK);
dev_priv->perf.oa.oa_buffer.tails[0].offset = INVALID_TAIL_PTR;
dev_priv->perf.oa.oa_buffer.tails[1].offset = INVALID_TAIL_PTR;
dev_priv->perf.oa.oa_buffer.last_ctx_id = INVALID_CTX_ID;
spin_unlock_irqrestore(&dev_priv->perf.oa.oa_buffer.ptr_lock, flags);
memset(dev_priv->perf.oa.oa_buffer.vaddr, 0, OA_BUFFER_SIZE);
dev_priv->perf.oa.pollin = false;
}
static int alloc_oa_buffer(struct drm_i915_private *dev_priv)
{
struct drm_i915_gem_object *bo;
struct i915_vma *vma;
int ret;
if (WARN_ON(dev_priv->perf.oa.oa_buffer.vma))
return -ENODEV;
ret = i915_mutex_lock_interruptible(&dev_priv->drm);
if (ret)
return ret;
BUILD_BUG_ON_NOT_POWER_OF_2(OA_BUFFER_SIZE);
BUILD_BUG_ON(OA_BUFFER_SIZE < SZ_128K || OA_BUFFER_SIZE > SZ_16M);
bo = i915_gem_object_create(dev_priv, OA_BUFFER_SIZE);
if (IS_ERR(bo)) {
DRM_ERROR("Failed to allocate OA buffer\n");
ret = PTR_ERR(bo);
goto unlock;
}
ret = i915_gem_object_set_cache_level(bo, I915_CACHE_LLC);
if (ret)
goto err_unref;
vma = i915_gem_object_ggtt_pin(bo, NULL, 0, SZ_16M, 0);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto err_unref;
}
dev_priv->perf.oa.oa_buffer.vma = vma;
dev_priv->perf.oa.oa_buffer.vaddr =
i915_gem_object_pin_map(bo, I915_MAP_WB);
if (IS_ERR(dev_priv->perf.oa.oa_buffer.vaddr)) {
ret = PTR_ERR(dev_priv->perf.oa.oa_buffer.vaddr);
goto err_unpin;
}
dev_priv->perf.oa.ops.init_oa_buffer(dev_priv);
DRM_DEBUG_DRIVER("OA Buffer initialized, gtt offset = 0x%x, vaddr = %p\n",
i915_ggtt_offset(dev_priv->perf.oa.oa_buffer.vma),
dev_priv->perf.oa.oa_buffer.vaddr);
goto unlock;
err_unpin:
__i915_vma_unpin(vma);
err_unref:
i915_gem_object_put(bo);
dev_priv->perf.oa.oa_buffer.vaddr = NULL;
dev_priv->perf.oa.oa_buffer.vma = NULL;
unlock:
mutex_unlock(&dev_priv->drm.struct_mutex);
return ret;
}
static void config_oa_regs(struct drm_i915_private *dev_priv,
const struct i915_oa_reg *regs,
u32 n_regs)
{
u32 i;
for (i = 0; i < n_regs; i++) {
const struct i915_oa_reg *reg = regs + i;
I915_WRITE(reg->addr, reg->value);
}
}
static int hsw_enable_metric_set(struct drm_i915_private *dev_priv,
const struct i915_oa_config *oa_config)
{
I915_WRITE(GEN7_MISCCPCTL, (I915_READ(GEN7_MISCCPCTL) &
~GEN7_DOP_CLOCK_GATE_ENABLE));
I915_WRITE(GEN6_UCGCTL1, (I915_READ(GEN6_UCGCTL1) |
GEN6_CSUNIT_CLOCK_GATE_DISABLE));
config_oa_regs(dev_priv, oa_config->mux_regs, oa_config->mux_regs_len);
usleep_range(15000, 20000);
config_oa_regs(dev_priv, oa_config->b_counter_regs,
oa_config->b_counter_regs_len);
return 0;
}
static void hsw_disable_metric_set(struct drm_i915_private *dev_priv)
{
I915_WRITE(GEN6_UCGCTL1, (I915_READ(GEN6_UCGCTL1) &
~GEN6_CSUNIT_CLOCK_GATE_DISABLE));
I915_WRITE(GEN7_MISCCPCTL, (I915_READ(GEN7_MISCCPCTL) |
GEN7_DOP_CLOCK_GATE_ENABLE));
I915_WRITE(GDT_CHICKEN_BITS, (I915_READ(GDT_CHICKEN_BITS) &
~GT_NOA_ENABLE));
}
static void gen8_update_reg_state_unlocked(struct i915_gem_context *ctx,
u32 *reg_state,
const struct i915_oa_config *oa_config)
{
struct drm_i915_private *dev_priv = ctx->i915;
u32 ctx_oactxctrl = dev_priv->perf.oa.ctx_oactxctrl_offset;
u32 ctx_flexeu0 = dev_priv->perf.oa.ctx_flexeu0_offset;
u32 flex_mmio[] = {
i915_mmio_reg_offset(EU_PERF_CNTL0),
i915_mmio_reg_offset(EU_PERF_CNTL1),
i915_mmio_reg_offset(EU_PERF_CNTL2),
i915_mmio_reg_offset(EU_PERF_CNTL3),
i915_mmio_reg_offset(EU_PERF_CNTL4),
i915_mmio_reg_offset(EU_PERF_CNTL5),
i915_mmio_reg_offset(EU_PERF_CNTL6),
};
int i;
reg_state[ctx_oactxctrl] = i915_mmio_reg_offset(GEN8_OACTXCONTROL);
reg_state[ctx_oactxctrl+1] = (dev_priv->perf.oa.period_exponent <<
GEN8_OA_TIMER_PERIOD_SHIFT) |
(dev_priv->perf.oa.periodic ?
GEN8_OA_TIMER_ENABLE : 0) |
GEN8_OA_COUNTER_RESUME;
for (i = 0; i < ARRAY_SIZE(flex_mmio); i++) {
u32 state_offset = ctx_flexeu0 + i * 2;
u32 mmio = flex_mmio[i];
u32 value = 0;
if (oa_config) {
u32 j;
for (j = 0; j < oa_config->flex_regs_len; j++) {
if (i915_mmio_reg_offset(oa_config->flex_regs[j].addr) == mmio) {
value = oa_config->flex_regs[j].value;
break;
}
}
}
reg_state[state_offset] = mmio;
reg_state[state_offset+1] = value;
}
}
static int gen8_emit_oa_config(struct drm_i915_gem_request *req,
const struct i915_oa_config *oa_config)
{
struct drm_i915_private *dev_priv = req->i915;
u32 flex_mmio[] = {
i915_mmio_reg_offset(EU_PERF_CNTL0),
i915_mmio_reg_offset(EU_PERF_CNTL1),
i915_mmio_reg_offset(EU_PERF_CNTL2),
i915_mmio_reg_offset(EU_PERF_CNTL3),
i915_mmio_reg_offset(EU_PERF_CNTL4),
i915_mmio_reg_offset(EU_PERF_CNTL5),
i915_mmio_reg_offset(EU_PERF_CNTL6),
};
u32 *cs;
int i;
cs = intel_ring_begin(req, ARRAY_SIZE(flex_mmio) * 2 + 4);
if (IS_ERR(cs))
return PTR_ERR(cs);
*cs++ = MI_LOAD_REGISTER_IMM(ARRAY_SIZE(flex_mmio) + 1);
*cs++ = i915_mmio_reg_offset(GEN8_OACTXCONTROL);
*cs++ = (dev_priv->perf.oa.period_exponent << GEN8_OA_TIMER_PERIOD_SHIFT) |
(dev_priv->perf.oa.periodic ? GEN8_OA_TIMER_ENABLE : 0) |
GEN8_OA_COUNTER_RESUME;
for (i = 0; i < ARRAY_SIZE(flex_mmio); i++) {
u32 mmio = flex_mmio[i];
u32 value = 0;
if (oa_config) {
u32 j;
for (j = 0; j < oa_config->flex_regs_len; j++) {
if (i915_mmio_reg_offset(oa_config->flex_regs[j].addr) == mmio) {
value = oa_config->flex_regs[j].value;
break;
}
}
}
*cs++ = mmio;
*cs++ = value;
}
*cs++ = MI_NOOP;
intel_ring_advance(req, cs);
return 0;
}
static int gen8_switch_to_updated_kernel_context(struct drm_i915_private *dev_priv,
const struct i915_oa_config *oa_config)
{
struct intel_engine_cs *engine = dev_priv->engine[RCS];
struct i915_gem_timeline *timeline;
struct drm_i915_gem_request *req;
int ret;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
i915_gem_retire_requests(dev_priv);
req = i915_gem_request_alloc(engine, dev_priv->kernel_context);
if (IS_ERR(req))
return PTR_ERR(req);
ret = gen8_emit_oa_config(req, oa_config);
if (ret) {
i915_add_request(req);
return ret;
}
list_for_each_entry(timeline, &dev_priv->gt.timelines, link) {
struct drm_i915_gem_request *prev;
struct intel_timeline *tl;
tl = &timeline->engine[engine->id];
prev = i915_gem_active_raw(&tl->last_request,
&dev_priv->drm.struct_mutex);
if (prev)
i915_sw_fence_await_sw_fence_gfp(&req->submit,
&prev->submit,
GFP_KERNEL);
}
ret = i915_switch_context(req);
i915_add_request(req);
return ret;
}
static int gen8_configure_all_contexts(struct drm_i915_private *dev_priv,
const struct i915_oa_config *oa_config,
bool interruptible)
{
struct i915_gem_context *ctx;
int ret;
unsigned int wait_flags = I915_WAIT_LOCKED;
if (interruptible) {
ret = i915_mutex_lock_interruptible(&dev_priv->drm);
if (ret)
return ret;
wait_flags |= I915_WAIT_INTERRUPTIBLE;
} else {
mutex_lock(&dev_priv->drm.struct_mutex);
}
ret = gen8_switch_to_updated_kernel_context(dev_priv, oa_config);
if (ret)
goto out;
ret = i915_gem_wait_for_idle(dev_priv, wait_flags);
if (ret)
goto out;
list_for_each_entry(ctx, &dev_priv->contexts.list, link) {
struct intel_context *ce = &ctx->engine[RCS];
u32 *regs;
if (!ce->state)
continue;
regs = i915_gem_object_pin_map(ce->state->obj, I915_MAP_WB);
if (IS_ERR(regs)) {
ret = PTR_ERR(regs);
goto out;
}
ce->state->obj->mm.dirty = true;
regs += LRC_STATE_PN * PAGE_SIZE / sizeof(*regs);
gen8_update_reg_state_unlocked(ctx, regs, oa_config);
i915_gem_object_unpin_map(ce->state->obj);
}
out:
mutex_unlock(&dev_priv->drm.struct_mutex);
return ret;
}
static int gen8_enable_metric_set(struct drm_i915_private *dev_priv,
const struct i915_oa_config *oa_config)
{
int ret;
if (IS_SKYLAKE(dev_priv) || IS_BROXTON(dev_priv) ||
IS_KABYLAKE(dev_priv) || IS_GEMINILAKE(dev_priv)) {
I915_WRITE(GEN8_OA_DEBUG,
_MASKED_BIT_ENABLE(GEN9_OA_DEBUG_DISABLE_CLK_RATIO_REPORTS |
GEN9_OA_DEBUG_INCLUDE_CLK_RATIO));
}
ret = gen8_configure_all_contexts(dev_priv, oa_config, true);
if (ret)
return ret;
config_oa_regs(dev_priv, oa_config->mux_regs, oa_config->mux_regs_len);
config_oa_regs(dev_priv, oa_config->b_counter_regs,
oa_config->b_counter_regs_len);
return 0;
}
static void gen8_disable_metric_set(struct drm_i915_private *dev_priv)
{
gen8_configure_all_contexts(dev_priv, NULL, false);
I915_WRITE(GDT_CHICKEN_BITS, (I915_READ(GDT_CHICKEN_BITS) &
~GT_NOA_ENABLE));
}
static void gen7_oa_enable(struct drm_i915_private *dev_priv)
{
gen7_init_oa_buffer(dev_priv);
if (dev_priv->perf.oa.exclusive_stream->enabled) {
struct i915_gem_context *ctx =
dev_priv->perf.oa.exclusive_stream->ctx;
u32 ctx_id = dev_priv->perf.oa.specific_ctx_id;
bool periodic = dev_priv->perf.oa.periodic;
u32 period_exponent = dev_priv->perf.oa.period_exponent;
u32 report_format = dev_priv->perf.oa.oa_buffer.format;
I915_WRITE(GEN7_OACONTROL,
(ctx_id & GEN7_OACONTROL_CTX_MASK) |
(period_exponent <<
GEN7_OACONTROL_TIMER_PERIOD_SHIFT) |
(periodic ? GEN7_OACONTROL_TIMER_ENABLE : 0) |
(report_format << GEN7_OACONTROL_FORMAT_SHIFT) |
(ctx ? GEN7_OACONTROL_PER_CTX_ENABLE : 0) |
GEN7_OACONTROL_ENABLE);
} else
I915_WRITE(GEN7_OACONTROL, 0);
}
static void gen8_oa_enable(struct drm_i915_private *dev_priv)
{
u32 report_format = dev_priv->perf.oa.oa_buffer.format;
gen8_init_oa_buffer(dev_priv);
I915_WRITE(GEN8_OACONTROL, (report_format <<
GEN8_OA_REPORT_FORMAT_SHIFT) |
GEN8_OA_COUNTER_ENABLE);
}
static void i915_oa_stream_enable(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
dev_priv->perf.oa.ops.oa_enable(dev_priv);
if (dev_priv->perf.oa.periodic)
hrtimer_start(&dev_priv->perf.oa.poll_check_timer,
ns_to_ktime(POLL_PERIOD),
HRTIMER_MODE_REL_PINNED);
}
static void gen7_oa_disable(struct drm_i915_private *dev_priv)
{
I915_WRITE(GEN7_OACONTROL, 0);
}
static void gen8_oa_disable(struct drm_i915_private *dev_priv)
{
I915_WRITE(GEN8_OACONTROL, 0);
}
static void i915_oa_stream_disable(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
dev_priv->perf.oa.ops.oa_disable(dev_priv);
if (dev_priv->perf.oa.periodic)
hrtimer_cancel(&dev_priv->perf.oa.poll_check_timer);
}
static int i915_oa_stream_init(struct i915_perf_stream *stream,
struct drm_i915_perf_open_param *param,
struct perf_open_properties *props)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
int format_size;
int ret;
if (!dev_priv->perf.metrics_kobj) {
DRM_DEBUG("OA metrics weren't advertised via sysfs\n");
return -EINVAL;
}
if (!(props->sample_flags & SAMPLE_OA_REPORT)) {
DRM_DEBUG("Only OA report sampling supported\n");
return -EINVAL;
}
if (!dev_priv->perf.oa.ops.init_oa_buffer) {
DRM_DEBUG("OA unit not supported\n");
return -ENODEV;
}
if (dev_priv->perf.oa.exclusive_stream) {
DRM_DEBUG("OA unit already in use\n");
return -EBUSY;
}
if (!props->oa_format) {
DRM_DEBUG("OA report format not specified\n");
return -EINVAL;
}
ratelimit_state_init(&dev_priv->perf.oa.spurious_report_rs,
5 * HZ, 10);
ratelimit_set_flags(&dev_priv->perf.oa.spurious_report_rs,
RATELIMIT_MSG_ON_RELEASE);
stream->sample_size = sizeof(struct drm_i915_perf_record_header);
format_size = dev_priv->perf.oa.oa_formats[props->oa_format].size;
stream->sample_flags |= SAMPLE_OA_REPORT;
stream->sample_size += format_size;
dev_priv->perf.oa.oa_buffer.format_size = format_size;
if (WARN_ON(dev_priv->perf.oa.oa_buffer.format_size == 0))
return -EINVAL;
dev_priv->perf.oa.oa_buffer.format =
dev_priv->perf.oa.oa_formats[props->oa_format].format;
dev_priv->perf.oa.periodic = props->oa_periodic;
if (dev_priv->perf.oa.periodic)
dev_priv->perf.oa.period_exponent = props->oa_period_exponent;
if (stream->ctx) {
ret = oa_get_render_ctx_id(stream);
if (ret)
return ret;
}
ret = get_oa_config(dev_priv, props->metrics_set, &stream->oa_config);
if (ret)
goto err_config;
intel_runtime_pm_get(dev_priv);
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
ret = alloc_oa_buffer(dev_priv);
if (ret)
goto err_oa_buf_alloc;
ret = dev_priv->perf.oa.ops.enable_metric_set(dev_priv,
stream->oa_config);
if (ret)
goto err_enable;
stream->ops = &i915_oa_stream_ops;
ret = i915_mutex_lock_interruptible(&dev_priv->drm);
if (ret)
goto err_lock;
dev_priv->perf.oa.exclusive_stream = stream;
mutex_unlock(&dev_priv->drm.struct_mutex);
return 0;
err_lock:
dev_priv->perf.oa.ops.disable_metric_set(dev_priv);
err_enable:
free_oa_buffer(dev_priv);
err_oa_buf_alloc:
put_oa_config(dev_priv, stream->oa_config);
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
intel_runtime_pm_put(dev_priv);
err_config:
if (stream->ctx)
oa_put_render_ctx_id(stream);
return ret;
}
void i915_oa_init_reg_state(struct intel_engine_cs *engine,
struct i915_gem_context *ctx,
u32 *reg_state)
{
struct i915_perf_stream *stream;
if (engine->id != RCS)
return;
stream = engine->i915->perf.oa.exclusive_stream;
if (stream)
gen8_update_reg_state_unlocked(ctx, reg_state, stream->oa_config);
}
static ssize_t i915_perf_read_locked(struct i915_perf_stream *stream,
struct file *file,
char __user *buf,
size_t count,
loff_t *ppos)
{
size_t offset = 0;
int ret = stream->ops->read(stream, buf, count, &offset);
return offset ?: (ret ?: -EAGAIN);
}
static ssize_t i915_perf_read(struct file *file,
char __user *buf,
size_t count,
loff_t *ppos)
{
struct i915_perf_stream *stream = file->private_data;
struct drm_i915_private *dev_priv = stream->dev_priv;
ssize_t ret;
if (!stream->enabled)
return -EIO;
if (!(file->f_flags & O_NONBLOCK)) {
do {
ret = stream->ops->wait_unlocked(stream);
if (ret)
return ret;
mutex_lock(&dev_priv->perf.lock);
ret = i915_perf_read_locked(stream, file,
buf, count, ppos);
mutex_unlock(&dev_priv->perf.lock);
} while (ret == -EAGAIN);
} else {
mutex_lock(&dev_priv->perf.lock);
ret = i915_perf_read_locked(stream, file, buf, count, ppos);
mutex_unlock(&dev_priv->perf.lock);
}
if (ret >= 0 || ret == -EAGAIN) {
dev_priv->perf.oa.pollin = false;
}
return ret;
}
static enum hrtimer_restart oa_poll_check_timer_cb(struct hrtimer *hrtimer)
{
struct drm_i915_private *dev_priv =
container_of(hrtimer, typeof(*dev_priv),
perf.oa.poll_check_timer);
if (oa_buffer_check_unlocked(dev_priv)) {
dev_priv->perf.oa.pollin = true;
wake_up(&dev_priv->perf.oa.poll_wq);
}
hrtimer_forward_now(hrtimer, ns_to_ktime(POLL_PERIOD));
return HRTIMER_RESTART;
}
static unsigned int i915_perf_poll_locked(struct drm_i915_private *dev_priv,
struct i915_perf_stream *stream,
struct file *file,
poll_table *wait)
{
unsigned int events = 0;
stream->ops->poll_wait(stream, file, wait);
if (dev_priv->perf.oa.pollin)
events |= POLLIN;
return events;
}
static unsigned int i915_perf_poll(struct file *file, poll_table *wait)
{
struct i915_perf_stream *stream = file->private_data;
struct drm_i915_private *dev_priv = stream->dev_priv;
int ret;
mutex_lock(&dev_priv->perf.lock);
ret = i915_perf_poll_locked(dev_priv, stream, file, wait);
mutex_unlock(&dev_priv->perf.lock);
return ret;
}
static void i915_perf_enable_locked(struct i915_perf_stream *stream)
{
if (stream->enabled)
return;
stream->enabled = true;
if (stream->ops->enable)
stream->ops->enable(stream);
}
static void i915_perf_disable_locked(struct i915_perf_stream *stream)
{
if (!stream->enabled)
return;
stream->enabled = false;
if (stream->ops->disable)
stream->ops->disable(stream);
}
static long i915_perf_ioctl_locked(struct i915_perf_stream *stream,
unsigned int cmd,
unsigned long arg)
{
switch (cmd) {
case I915_PERF_IOCTL_ENABLE:
i915_perf_enable_locked(stream);
return 0;
case I915_PERF_IOCTL_DISABLE:
i915_perf_disable_locked(stream);
return 0;
}
return -EINVAL;
}
static long i915_perf_ioctl(struct file *file,
unsigned int cmd,
unsigned long arg)
{
struct i915_perf_stream *stream = file->private_data;
struct drm_i915_private *dev_priv = stream->dev_priv;
long ret;
mutex_lock(&dev_priv->perf.lock);
ret = i915_perf_ioctl_locked(stream, cmd, arg);
mutex_unlock(&dev_priv->perf.lock);
return ret;
}
static void i915_perf_destroy_locked(struct i915_perf_stream *stream)
{
if (stream->enabled)
i915_perf_disable_locked(stream);
if (stream->ops->destroy)
stream->ops->destroy(stream);
list_del(&stream->link);
if (stream->ctx)
i915_gem_context_put(stream->ctx);
kfree(stream);
}
static int i915_perf_release(struct inode *inode, struct file *file)
{
struct i915_perf_stream *stream = file->private_data;
struct drm_i915_private *dev_priv = stream->dev_priv;
mutex_lock(&dev_priv->perf.lock);
i915_perf_destroy_locked(stream);
mutex_unlock(&dev_priv->perf.lock);
return 0;
}
static int
i915_perf_open_ioctl_locked(struct drm_i915_private *dev_priv,
struct drm_i915_perf_open_param *param,
struct perf_open_properties *props,
struct drm_file *file)
{
struct i915_gem_context *specific_ctx = NULL;
struct i915_perf_stream *stream = NULL;
unsigned long f_flags = 0;
bool privileged_op = true;
int stream_fd;
int ret;
if (props->single_context) {
u32 ctx_handle = props->ctx_handle;
struct drm_i915_file_private *file_priv = file->driver_priv;
specific_ctx = i915_gem_context_lookup(file_priv, ctx_handle);
if (!specific_ctx) {
DRM_DEBUG("Failed to look up context with ID %u for opening perf stream\n",
ctx_handle);
ret = -ENOENT;
goto err;
}
}
if (IS_HASWELL(dev_priv) && specific_ctx)
privileged_op = false;
if (privileged_op &&
i915_perf_stream_paranoid && !capable(CAP_SYS_ADMIN)) {
DRM_DEBUG("Insufficient privileges to open system-wide i915 perf stream\n");
ret = -EACCES;
goto err_ctx;
}
stream = kzalloc(sizeof(*stream), GFP_KERNEL);
if (!stream) {
ret = -ENOMEM;
goto err_ctx;
}
stream->dev_priv = dev_priv;
stream->ctx = specific_ctx;
ret = i915_oa_stream_init(stream, param, props);
if (ret)
goto err_alloc;
if (WARN_ON(stream->sample_flags != props->sample_flags)) {
ret = -ENODEV;
goto err_flags;
}
list_add(&stream->link, &dev_priv->perf.streams);
if (param->flags & I915_PERF_FLAG_FD_CLOEXEC)
f_flags |= O_CLOEXEC;
if (param->flags & I915_PERF_FLAG_FD_NONBLOCK)
f_flags |= O_NONBLOCK;
stream_fd = anon_inode_getfd("[i915_perf]", &fops, stream, f_flags);
if (stream_fd < 0) {
ret = stream_fd;
goto err_open;
}
if (!(param->flags & I915_PERF_FLAG_DISABLED))
i915_perf_enable_locked(stream);
return stream_fd;
err_open:
list_del(&stream->link);
err_flags:
if (stream->ops->destroy)
stream->ops->destroy(stream);
err_alloc:
kfree(stream);
err_ctx:
if (specific_ctx)
i915_gem_context_put(specific_ctx);
err:
return ret;
}
static u64 oa_exponent_to_ns(struct drm_i915_private *dev_priv, int exponent)
{
return div_u64(1000000000ULL * (2ULL << exponent),
dev_priv->perf.oa.timestamp_frequency);
}
static int read_properties_unlocked(struct drm_i915_private *dev_priv,
u64 __user *uprops,
u32 n_props,
struct perf_open_properties *props)
{
u64 __user *uprop = uprops;
u32 i;
memset(props, 0, sizeof(struct perf_open_properties));
if (!n_props) {
DRM_DEBUG("No i915 perf properties given\n");
return -EINVAL;
}
if (n_props >= DRM_I915_PERF_PROP_MAX) {
DRM_DEBUG("More i915 perf properties specified than exist\n");
return -EINVAL;
}
for (i = 0; i < n_props; i++) {
u64 oa_period, oa_freq_hz;
u64 id, value;
int ret;
ret = get_user(id, uprop);
if (ret)
return ret;
ret = get_user(value, uprop + 1);
if (ret)
return ret;
if (id == 0 || id >= DRM_I915_PERF_PROP_MAX) {
DRM_DEBUG("Unknown i915 perf property ID\n");
return -EINVAL;
}
switch ((enum drm_i915_perf_property_id)id) {
case DRM_I915_PERF_PROP_CTX_HANDLE:
props->single_context = 1;
props->ctx_handle = value;
break;
case DRM_I915_PERF_PROP_SAMPLE_OA:
props->sample_flags |= SAMPLE_OA_REPORT;
break;
case DRM_I915_PERF_PROP_OA_METRICS_SET:
if (value == 0) {
DRM_DEBUG("Unknown OA metric set ID\n");
return -EINVAL;
}
props->metrics_set = value;
break;
case DRM_I915_PERF_PROP_OA_FORMAT:
if (value == 0 || value >= I915_OA_FORMAT_MAX) {
DRM_DEBUG("Out-of-range OA report format %llu\n",
value);
return -EINVAL;
}
if (!dev_priv->perf.oa.oa_formats[value].size) {
DRM_DEBUG("Unsupported OA report format %llu\n",
value);
return -EINVAL;
}
props->oa_format = value;
break;
case DRM_I915_PERF_PROP_OA_EXPONENT:
if (value > OA_EXPONENT_MAX) {
DRM_DEBUG("OA timer exponent too high (> %u)\n",
OA_EXPONENT_MAX);
return -EINVAL;
}
BUILD_BUG_ON(sizeof(oa_period) != 8);
oa_period = oa_exponent_to_ns(dev_priv, value);
if (oa_period <= NSEC_PER_SEC) {
u64 tmp = NSEC_PER_SEC;
do_div(tmp, oa_period);
oa_freq_hz = tmp;
} else
oa_freq_hz = 0;
if (oa_freq_hz > i915_oa_max_sample_rate &&
!capable(CAP_SYS_ADMIN)) {
DRM_DEBUG("OA exponent would exceed the max sampling frequency (sysctl dev.i915.oa_max_sample_rate) %uHz without root privileges\n",
i915_oa_max_sample_rate);
return -EACCES;
}
props->oa_periodic = true;
props->oa_period_exponent = value;
break;
case DRM_I915_PERF_PROP_MAX:
MISSING_CASE(id);
return -EINVAL;
}
uprop += 2;
}
return 0;
}
int i915_perf_open_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_perf_open_param *param = data;
struct perf_open_properties props;
u32 known_open_flags;
int ret;
if (!dev_priv->perf.initialized) {
DRM_DEBUG("i915 perf interface not available for this system\n");
return -ENOTSUPP;
}
known_open_flags = I915_PERF_FLAG_FD_CLOEXEC |
I915_PERF_FLAG_FD_NONBLOCK |
I915_PERF_FLAG_DISABLED;
if (param->flags & ~known_open_flags) {
DRM_DEBUG("Unknown drm_i915_perf_open_param flag\n");
return -EINVAL;
}
ret = read_properties_unlocked(dev_priv,
u64_to_user_ptr(param->properties_ptr),
param->num_properties,
&props);
if (ret)
return ret;
mutex_lock(&dev_priv->perf.lock);
ret = i915_perf_open_ioctl_locked(dev_priv, param, &props, file);
mutex_unlock(&dev_priv->perf.lock);
return ret;
}
void i915_perf_register(struct drm_i915_private *dev_priv)
{
int ret;
if (!dev_priv->perf.initialized)
return;
mutex_lock(&dev_priv->perf.lock);
dev_priv->perf.metrics_kobj =
kobject_create_and_add("metrics",
&dev_priv->drm.primary->kdev->kobj);
if (!dev_priv->perf.metrics_kobj)
goto exit;
sysfs_attr_init(&dev_priv->perf.oa.test_config.sysfs_metric_id.attr);
if (IS_HASWELL(dev_priv)) {
i915_perf_load_test_config_hsw(dev_priv);
} else if (IS_BROADWELL(dev_priv)) {
i915_perf_load_test_config_bdw(dev_priv);
} else if (IS_CHERRYVIEW(dev_priv)) {
i915_perf_load_test_config_chv(dev_priv);
} else if (IS_SKYLAKE(dev_priv)) {
if (IS_SKL_GT2(dev_priv))
i915_perf_load_test_config_sklgt2(dev_priv);
else if (IS_SKL_GT3(dev_priv))
i915_perf_load_test_config_sklgt3(dev_priv);
else if (IS_SKL_GT4(dev_priv))
i915_perf_load_test_config_sklgt4(dev_priv);
} else if (IS_BROXTON(dev_priv)) {
i915_perf_load_test_config_bxt(dev_priv);
} else if (IS_KABYLAKE(dev_priv)) {
if (IS_KBL_GT2(dev_priv))
i915_perf_load_test_config_kblgt2(dev_priv);
else if (IS_KBL_GT3(dev_priv))
i915_perf_load_test_config_kblgt3(dev_priv);
} else if (IS_GEMINILAKE(dev_priv)) {
i915_perf_load_test_config_glk(dev_priv);
}
if (dev_priv->perf.oa.test_config.id == 0)
goto sysfs_error;
ret = sysfs_create_group(dev_priv->perf.metrics_kobj,
&dev_priv->perf.oa.test_config.sysfs_metric);
if (ret)
goto sysfs_error;
atomic_set(&dev_priv->perf.oa.test_config.ref_count, 1);
goto exit;
sysfs_error:
kobject_put(dev_priv->perf.metrics_kobj);
dev_priv->perf.metrics_kobj = NULL;
exit:
mutex_unlock(&dev_priv->perf.lock);
}
void i915_perf_unregister(struct drm_i915_private *dev_priv)
{
if (!dev_priv->perf.metrics_kobj)
return;
sysfs_remove_group(dev_priv->perf.metrics_kobj,
&dev_priv->perf.oa.test_config.sysfs_metric);
kobject_put(dev_priv->perf.metrics_kobj);
dev_priv->perf.metrics_kobj = NULL;
}
static bool gen8_is_valid_flex_addr(struct drm_i915_private *dev_priv, u32 addr)
{
static const i915_reg_t flex_eu_regs[] = {
EU_PERF_CNTL0,
EU_PERF_CNTL1,
EU_PERF_CNTL2,
EU_PERF_CNTL3,
EU_PERF_CNTL4,
EU_PERF_CNTL5,
EU_PERF_CNTL6,
};
int i;
for (i = 0; i < ARRAY_SIZE(flex_eu_regs); i++) {
if (flex_eu_regs[i].reg == addr)
return true;
}
return false;
}
static bool gen7_is_valid_b_counter_addr(struct drm_i915_private *dev_priv, u32 addr)
{
return (addr >= OASTARTTRIG1.reg && addr <= OASTARTTRIG8.reg) ||
(addr >= OAREPORTTRIG1.reg && addr <= OAREPORTTRIG8.reg) ||
(addr >= OACEC0_0.reg && addr <= OACEC7_1.reg);
}
static bool gen7_is_valid_mux_addr(struct drm_i915_private *dev_priv, u32 addr)
{
return addr == HALF_SLICE_CHICKEN2.reg ||
(addr >= MICRO_BP0_0.reg && addr <= NOA_WRITE.reg) ||
(addr >= OA_PERFCNT1_LO.reg && addr <= OA_PERFCNT2_HI.reg) ||
(addr >= OA_PERFMATRIX_LO.reg && addr <= OA_PERFMATRIX_HI.reg);
}
static bool gen8_is_valid_mux_addr(struct drm_i915_private *dev_priv, u32 addr)
{
return gen7_is_valid_mux_addr(dev_priv, addr) ||
addr == WAIT_FOR_RC6_EXIT.reg ||
(addr >= RPM_CONFIG0.reg && addr <= NOA_CONFIG(8).reg);
}
static bool hsw_is_valid_mux_addr(struct drm_i915_private *dev_priv, u32 addr)
{
return gen7_is_valid_mux_addr(dev_priv, addr) ||
(addr >= 0x25100 && addr <= 0x2FF90) ||
addr == 0x9ec0;
}
static bool chv_is_valid_mux_addr(struct drm_i915_private *dev_priv, u32 addr)
{
return gen7_is_valid_mux_addr(dev_priv, addr) ||
(addr >= 0x182300 && addr <= 0x1823A4);
}
static uint32_t mask_reg_value(u32 reg, u32 val)
{
if (HALF_SLICE_CHICKEN2.reg == reg)
val = val & ~_MASKED_BIT_ENABLE(GEN8_ST_PO_DISABLE);
if (WAIT_FOR_RC6_EXIT.reg == reg)
val = val & ~_MASKED_BIT_ENABLE(HSW_WAIT_FOR_RC6_EXIT_ENABLE);
return val;
}
static struct i915_oa_reg *alloc_oa_regs(struct drm_i915_private *dev_priv,
bool (*is_valid)(struct drm_i915_private *dev_priv, u32 addr),
u32 __user *regs,
u32 n_regs)
{
struct i915_oa_reg *oa_regs;
int err;
u32 i;
if (!n_regs)
return NULL;
if (!access_ok(VERIFY_READ, regs, n_regs * sizeof(u32) * 2))
return ERR_PTR(-EFAULT);
GEM_BUG_ON(!is_valid);
if (!is_valid)
return ERR_PTR(-EINVAL);
oa_regs = kmalloc_array(n_regs, sizeof(*oa_regs), GFP_KERNEL);
if (!oa_regs)
return ERR_PTR(-ENOMEM);
for (i = 0; i < n_regs; i++) {
u32 addr, value;
err = get_user(addr, regs);
if (err)
goto addr_err;
if (!is_valid(dev_priv, addr)) {
DRM_DEBUG("Invalid oa_reg address: %X\n", addr);
err = -EINVAL;
goto addr_err;
}
err = get_user(value, regs + 1);
if (err)
goto addr_err;
oa_regs[i].addr = _MMIO(addr);
oa_regs[i].value = mask_reg_value(addr, value);
regs += 2;
}
return oa_regs;
addr_err:
kfree(oa_regs);
return ERR_PTR(err);
}
static ssize_t show_dynamic_id(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i915_oa_config *oa_config =
container_of(attr, typeof(*oa_config), sysfs_metric_id);
return sprintf(buf, "%d\n", oa_config->id);
}
static int create_dynamic_oa_sysfs_entry(struct drm_i915_private *dev_priv,
struct i915_oa_config *oa_config)
{
sysfs_attr_init(&oa_config->sysfs_metric_id.attr);
oa_config->sysfs_metric_id.attr.name = "id";
oa_config->sysfs_metric_id.attr.mode = S_IRUGO;
oa_config->sysfs_metric_id.show = show_dynamic_id;
oa_config->sysfs_metric_id.store = NULL;
oa_config->attrs[0] = &oa_config->sysfs_metric_id.attr;
oa_config->attrs[1] = NULL;
oa_config->sysfs_metric.name = oa_config->uuid;
oa_config->sysfs_metric.attrs = oa_config->attrs;
return sysfs_create_group(dev_priv->perf.metrics_kobj,
&oa_config->sysfs_metric);
}
int i915_perf_add_config_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_perf_oa_config *args = data;
struct i915_oa_config *oa_config, *tmp;
int err, id;
if (!dev_priv->perf.initialized) {
DRM_DEBUG("i915 perf interface not available for this system\n");
return -ENOTSUPP;
}
if (!dev_priv->perf.metrics_kobj) {
DRM_DEBUG("OA metrics weren't advertised via sysfs\n");
return -EINVAL;
}
if (i915_perf_stream_paranoid && !capable(CAP_SYS_ADMIN)) {
DRM_DEBUG("Insufficient privileges to add i915 OA config\n");
return -EACCES;
}
if ((!args->mux_regs_ptr || !args->n_mux_regs) &&
(!args->boolean_regs_ptr || !args->n_boolean_regs) &&
(!args->flex_regs_ptr || !args->n_flex_regs)) {
DRM_DEBUG("No OA registers given\n");
return -EINVAL;
}
oa_config = kzalloc(sizeof(*oa_config), GFP_KERNEL);
if (!oa_config) {
DRM_DEBUG("Failed to allocate memory for the OA config\n");
return -ENOMEM;
}
atomic_set(&oa_config->ref_count, 1);
if (!uuid_is_valid(args->uuid)) {
DRM_DEBUG("Invalid uuid format for OA config\n");
err = -EINVAL;
goto reg_err;
}
memcpy(oa_config->uuid, args->uuid, sizeof(args->uuid));
oa_config->mux_regs_len = args->n_mux_regs;
oa_config->mux_regs =
alloc_oa_regs(dev_priv,
dev_priv->perf.oa.ops.is_valid_mux_reg,
u64_to_user_ptr(args->mux_regs_ptr),
args->n_mux_regs);
if (IS_ERR(oa_config->mux_regs)) {
DRM_DEBUG("Failed to create OA config for mux_regs\n");
err = PTR_ERR(oa_config->mux_regs);
goto reg_err;
}
oa_config->b_counter_regs_len = args->n_boolean_regs;
oa_config->b_counter_regs =
alloc_oa_regs(dev_priv,
dev_priv->perf.oa.ops.is_valid_b_counter_reg,
u64_to_user_ptr(args->boolean_regs_ptr),
args->n_boolean_regs);
if (IS_ERR(oa_config->b_counter_regs)) {
DRM_DEBUG("Failed to create OA config for b_counter_regs\n");
err = PTR_ERR(oa_config->b_counter_regs);
goto reg_err;
}
if (INTEL_GEN(dev_priv) < 8) {
if (args->n_flex_regs != 0) {
err = -EINVAL;
goto reg_err;
}
} else {
oa_config->flex_regs_len = args->n_flex_regs;
oa_config->flex_regs =
alloc_oa_regs(dev_priv,
dev_priv->perf.oa.ops.is_valid_flex_reg,
u64_to_user_ptr(args->flex_regs_ptr),
args->n_flex_regs);
if (IS_ERR(oa_config->flex_regs)) {
DRM_DEBUG("Failed to create OA config for flex_regs\n");
err = PTR_ERR(oa_config->flex_regs);
goto reg_err;
}
}
err = mutex_lock_interruptible(&dev_priv->perf.metrics_lock);
if (err)
goto reg_err;
idr_for_each_entry(&dev_priv->perf.metrics_idr, tmp, id) {
if (!strcmp(tmp->uuid, oa_config->uuid)) {
DRM_DEBUG("OA config already exists with this uuid\n");
err = -EADDRINUSE;
goto sysfs_err;
}
}
err = create_dynamic_oa_sysfs_entry(dev_priv, oa_config);
if (err) {
DRM_DEBUG("Failed to create sysfs entry for OA config\n");
goto sysfs_err;
}
oa_config->id = idr_alloc(&dev_priv->perf.metrics_idr,
oa_config, 2,
0, GFP_KERNEL);
if (oa_config->id < 0) {
DRM_DEBUG("Failed to create sysfs entry for OA config\n");
err = oa_config->id;
goto sysfs_err;
}
mutex_unlock(&dev_priv->perf.metrics_lock);
return oa_config->id;
sysfs_err:
mutex_unlock(&dev_priv->perf.metrics_lock);
reg_err:
put_oa_config(dev_priv, oa_config);
DRM_DEBUG("Failed to add new OA config\n");
return err;
}
int i915_perf_remove_config_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u64 *arg = data;
struct i915_oa_config *oa_config;
int ret;
if (!dev_priv->perf.initialized) {
DRM_DEBUG("i915 perf interface not available for this system\n");
return -ENOTSUPP;
}
if (i915_perf_stream_paranoid && !capable(CAP_SYS_ADMIN)) {
DRM_DEBUG("Insufficient privileges to remove i915 OA config\n");
return -EACCES;
}
ret = mutex_lock_interruptible(&dev_priv->perf.metrics_lock);
if (ret)
goto lock_err;
oa_config = idr_find(&dev_priv->perf.metrics_idr, *arg);
if (!oa_config) {
DRM_DEBUG("Failed to remove unknown OA config\n");
ret = -ENOENT;
goto config_err;
}
GEM_BUG_ON(*arg != oa_config->id);
sysfs_remove_group(dev_priv->perf.metrics_kobj,
&oa_config->sysfs_metric);
idr_remove(&dev_priv->perf.metrics_idr, *arg);
put_oa_config(dev_priv, oa_config);
config_err:
mutex_unlock(&dev_priv->perf.metrics_lock);
lock_err:
return ret;
}
void i915_perf_init(struct drm_i915_private *dev_priv)
{
dev_priv->perf.oa.timestamp_frequency = 0;
if (IS_HASWELL(dev_priv)) {
dev_priv->perf.oa.ops.is_valid_b_counter_reg =
gen7_is_valid_b_counter_addr;
dev_priv->perf.oa.ops.is_valid_mux_reg =
hsw_is_valid_mux_addr;
dev_priv->perf.oa.ops.is_valid_flex_reg = NULL;
dev_priv->perf.oa.ops.init_oa_buffer = gen7_init_oa_buffer;
dev_priv->perf.oa.ops.enable_metric_set = hsw_enable_metric_set;
dev_priv->perf.oa.ops.disable_metric_set = hsw_disable_metric_set;
dev_priv->perf.oa.ops.oa_enable = gen7_oa_enable;
dev_priv->perf.oa.ops.oa_disable = gen7_oa_disable;
dev_priv->perf.oa.ops.read = gen7_oa_read;
dev_priv->perf.oa.ops.oa_hw_tail_read =
gen7_oa_hw_tail_read;
dev_priv->perf.oa.timestamp_frequency = 12500000;
dev_priv->perf.oa.oa_formats = hsw_oa_formats;
} else if (i915.enable_execlists) {
dev_priv->perf.oa.ops.is_valid_b_counter_reg =
gen7_is_valid_b_counter_addr;
dev_priv->perf.oa.ops.is_valid_mux_reg =
gen8_is_valid_mux_addr;
dev_priv->perf.oa.ops.is_valid_flex_reg =
gen8_is_valid_flex_addr;
dev_priv->perf.oa.ops.init_oa_buffer = gen8_init_oa_buffer;
dev_priv->perf.oa.ops.enable_metric_set = gen8_enable_metric_set;
dev_priv->perf.oa.ops.disable_metric_set = gen8_disable_metric_set;
dev_priv->perf.oa.ops.oa_enable = gen8_oa_enable;
dev_priv->perf.oa.ops.oa_disable = gen8_oa_disable;
dev_priv->perf.oa.ops.read = gen8_oa_read;
dev_priv->perf.oa.ops.oa_hw_tail_read = gen8_oa_hw_tail_read;
dev_priv->perf.oa.oa_formats = gen8_plus_oa_formats;
if (IS_GEN8(dev_priv)) {
dev_priv->perf.oa.ctx_oactxctrl_offset = 0x120;
dev_priv->perf.oa.ctx_flexeu0_offset = 0x2ce;
dev_priv->perf.oa.timestamp_frequency = 12500000;
dev_priv->perf.oa.gen8_valid_ctx_bit = (1<<25);
if (IS_CHERRYVIEW(dev_priv)) {
dev_priv->perf.oa.ops.is_valid_mux_reg =
chv_is_valid_mux_addr;
}
} else if (IS_GEN9(dev_priv)) {
dev_priv->perf.oa.ctx_oactxctrl_offset = 0x128;
dev_priv->perf.oa.ctx_flexeu0_offset = 0x3de;
dev_priv->perf.oa.gen8_valid_ctx_bit = (1<<16);
switch (dev_priv->info.platform) {
case INTEL_BROXTON:
case INTEL_GEMINILAKE:
dev_priv->perf.oa.timestamp_frequency = 19200000;
break;
case INTEL_SKYLAKE:
case INTEL_KABYLAKE:
dev_priv->perf.oa.timestamp_frequency = 12000000;
break;
default:
break;
}
}
}
if (dev_priv->perf.oa.timestamp_frequency) {
hrtimer_init(&dev_priv->perf.oa.poll_check_timer,
CLOCK_MONOTONIC, HRTIMER_MODE_REL);
dev_priv->perf.oa.poll_check_timer.function = oa_poll_check_timer_cb;
init_waitqueue_head(&dev_priv->perf.oa.poll_wq);
INIT_LIST_HEAD(&dev_priv->perf.streams);
mutex_init(&dev_priv->perf.lock);
spin_lock_init(&dev_priv->perf.oa.oa_buffer.ptr_lock);
oa_sample_rate_hard_limit =
dev_priv->perf.oa.timestamp_frequency / 2;
dev_priv->perf.sysctl_header = register_sysctl_table(dev_root);
mutex_init(&dev_priv->perf.metrics_lock);
idr_init(&dev_priv->perf.metrics_idr);
dev_priv->perf.initialized = true;
}
}
static int destroy_config(int id, void *p, void *data)
{
struct drm_i915_private *dev_priv = data;
struct i915_oa_config *oa_config = p;
put_oa_config(dev_priv, oa_config);
return 0;
}
void i915_perf_fini(struct drm_i915_private *dev_priv)
{
if (!dev_priv->perf.initialized)
return;
idr_for_each(&dev_priv->perf.metrics_idr, destroy_config, dev_priv);
idr_destroy(&dev_priv->perf.metrics_idr);
unregister_sysctl_table(dev_priv->perf.sysctl_header);
memset(&dev_priv->perf.oa.ops, 0, sizeof(dev_priv->perf.oa.ops));
dev_priv->perf.initialized = false;
}
