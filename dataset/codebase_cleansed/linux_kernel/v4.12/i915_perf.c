static bool gen7_oa_buffer_is_empty_fop_unlocked(struct drm_i915_private *dev_priv)
{
int report_size = dev_priv->perf.oa.oa_buffer.format_size;
u32 oastatus2 = I915_READ(GEN7_OASTATUS2);
u32 oastatus1 = I915_READ(GEN7_OASTATUS1);
u32 head = oastatus2 & GEN7_OASTATUS2_HEAD_MASK;
u32 tail = oastatus1 & GEN7_OASTATUS1_TAIL_MASK;
return OA_TAKEN(tail, head) <
dev_priv->perf.oa.tail_margin + report_size;
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
static int gen7_append_oa_reports(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset,
u32 *head_ptr,
u32 tail)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
int report_size = dev_priv->perf.oa.oa_buffer.format_size;
u8 *oa_buf_base = dev_priv->perf.oa.oa_buffer.vaddr;
int tail_margin = dev_priv->perf.oa.tail_margin;
u32 gtt_offset = i915_ggtt_offset(dev_priv->perf.oa.oa_buffer.vma);
u32 mask = (OA_BUFFER_SIZE - 1);
u32 head;
u32 taken;
int ret = 0;
if (WARN_ON(!stream->enabled))
return -EIO;
head = *head_ptr - gtt_offset;
tail -= gtt_offset;
if (tail > OA_BUFFER_SIZE || head > OA_BUFFER_SIZE ||
head % report_size) {
DRM_ERROR("Inconsistent OA buffer pointer (head = %u, tail = %u): force restart\n",
head, tail);
dev_priv->perf.oa.ops.oa_disable(dev_priv);
dev_priv->perf.oa.ops.oa_enable(dev_priv);
*head_ptr = I915_READ(GEN7_OASTATUS2) &
GEN7_OASTATUS2_HEAD_MASK;
return -EIO;
}
tail &= ~(report_size - 1);
if (OA_TAKEN(tail, head) < report_size + tail_margin)
return -EAGAIN;
tail -= tail_margin;
tail &= mask;
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
DRM_NOTE("Skipping spurious, invalid OA report\n");
continue;
}
ret = append_oa_sample(stream, buf, count, offset, report);
if (ret)
break;
report32[0] = 0;
}
*head_ptr = gtt_offset + head;
return ret;
}
static int gen7_oa_read(struct i915_perf_stream *stream,
char __user *buf,
size_t count,
size_t *offset)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
int report_size = dev_priv->perf.oa.oa_buffer.format_size;
u32 oastatus2;
u32 oastatus1;
u32 head;
u32 tail;
int ret;
if (WARN_ON(!dev_priv->perf.oa.oa_buffer.vaddr))
return -EIO;
oastatus2 = I915_READ(GEN7_OASTATUS2);
oastatus1 = I915_READ(GEN7_OASTATUS1);
head = oastatus2 & GEN7_OASTATUS2_HEAD_MASK;
tail = oastatus1 & GEN7_OASTATUS1_TAIL_MASK;
oastatus1 &= ~dev_priv->perf.oa.gen7_latched_oastatus1;
if (unlikely(oastatus1 & GEN7_OASTATUS1_OABUFFER_OVERFLOW)) {
ret = append_oa_status(stream, buf, count, offset,
DRM_I915_PERF_RECORD_OA_BUFFER_LOST);
if (ret)
return ret;
DRM_DEBUG("OA buffer overflow: force restart\n");
dev_priv->perf.oa.ops.oa_disable(dev_priv);
dev_priv->perf.oa.ops.oa_enable(dev_priv);
oastatus2 = I915_READ(GEN7_OASTATUS2);
oastatus1 = I915_READ(GEN7_OASTATUS1);
head = oastatus2 & GEN7_OASTATUS2_HEAD_MASK;
tail = oastatus1 & GEN7_OASTATUS1_TAIL_MASK;
}
if (unlikely(oastatus1 & GEN7_OASTATUS1_REPORT_LOST)) {
ret = append_oa_status(stream, buf, count, offset,
DRM_I915_PERF_RECORD_OA_REPORT_LOST);
if (ret)
return ret;
dev_priv->perf.oa.gen7_latched_oastatus1 |=
GEN7_OASTATUS1_REPORT_LOST;
}
ret = gen7_append_oa_reports(stream, buf, count, offset,
&head, tail);
WARN_ONCE(head & (report_size - 1),
"i915: Writing misaligned OA head pointer");
I915_WRITE(GEN7_OASTATUS2,
((head & GEN7_OASTATUS2_HEAD_MASK) |
OA_MEM_SELECT_GGTT));
return ret;
}
static int i915_oa_wait_unlocked(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
if (!dev_priv->perf.oa.periodic)
return -EIO;
return wait_event_interruptible(dev_priv->perf.oa.poll_wq,
!dev_priv->perf.oa.ops.oa_buffer_is_empty(dev_priv));
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
struct intel_engine_cs *engine = dev_priv->engine[RCS];
int ret;
ret = i915_mutex_lock_interruptible(&dev_priv->drm);
if (ret)
return ret;
ret = engine->context_pin(engine, stream->ctx);
if (ret)
goto unlock;
dev_priv->perf.oa.specific_ctx_id =
i915_ggtt_offset(stream->ctx->engine[engine->id].state);
unlock:
mutex_unlock(&dev_priv->drm.struct_mutex);
return ret;
}
static void oa_put_render_ctx_id(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
struct intel_engine_cs *engine = dev_priv->engine[RCS];
mutex_lock(&dev_priv->drm.struct_mutex);
dev_priv->perf.oa.specific_ctx_id = INVALID_CTX_ID;
engine->context_unpin(engine, stream->ctx);
mutex_unlock(&dev_priv->drm.struct_mutex);
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
dev_priv->perf.oa.ops.disable_metric_set(dev_priv);
free_oa_buffer(dev_priv);
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
intel_runtime_pm_put(dev_priv);
if (stream->ctx)
oa_put_render_ctx_id(stream);
dev_priv->perf.oa.exclusive_stream = NULL;
}
static void gen7_init_oa_buffer(struct drm_i915_private *dev_priv)
{
u32 gtt_offset = i915_ggtt_offset(dev_priv->perf.oa.oa_buffer.vma);
I915_WRITE(GEN7_OASTATUS2, gtt_offset | OA_MEM_SELECT_GGTT);
I915_WRITE(GEN7_OABUFFER, gtt_offset);
I915_WRITE(GEN7_OASTATUS1, gtt_offset | OABUFFER_SIZE_16M);
dev_priv->perf.oa.gen7_latched_oastatus1 = 0;
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
int n_regs)
{
int i;
for (i = 0; i < n_regs; i++) {
const struct i915_oa_reg *reg = regs + i;
I915_WRITE(reg->addr, reg->value);
}
}
static int hsw_enable_metric_set(struct drm_i915_private *dev_priv)
{
int ret = i915_oa_select_metric_set_hsw(dev_priv);
if (ret)
return ret;
I915_WRITE(GDT_CHICKEN_BITS, (I915_READ(GDT_CHICKEN_BITS) |
GT_NOA_ENABLE));
I915_WRITE(GEN7_MISCCPCTL, (I915_READ(GEN7_MISCCPCTL) &
~GEN7_DOP_CLOCK_GATE_ENABLE));
I915_WRITE(GEN6_UCGCTL1, (I915_READ(GEN6_UCGCTL1) |
GEN6_CSUNIT_CLOCK_GATE_DISABLE));
config_oa_regs(dev_priv, dev_priv->perf.oa.mux_regs,
dev_priv->perf.oa.mux_regs_len);
usleep_range(15000, 20000);
config_oa_regs(dev_priv, dev_priv->perf.oa.b_counter_regs,
dev_priv->perf.oa.b_counter_regs_len);
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
static void gen7_update_oacontrol_locked(struct drm_i915_private *dev_priv)
{
lockdep_assert_held(&dev_priv->perf.hook_lock);
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
static void gen7_oa_enable(struct drm_i915_private *dev_priv)
{
unsigned long flags;
gen7_init_oa_buffer(dev_priv);
spin_lock_irqsave(&dev_priv->perf.hook_lock, flags);
gen7_update_oacontrol_locked(dev_priv);
spin_unlock_irqrestore(&dev_priv->perf.hook_lock, flags);
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
static void i915_oa_stream_disable(struct i915_perf_stream *stream)
{
struct drm_i915_private *dev_priv = stream->dev_priv;
dev_priv->perf.oa.ops.oa_disable(dev_priv);
if (dev_priv->perf.oa.periodic)
hrtimer_cancel(&dev_priv->perf.oa.poll_check_timer);
}
static u64 oa_exponent_to_ns(struct drm_i915_private *dev_priv, int exponent)
{
return div_u64(1000000000ULL * (2ULL << exponent),
dev_priv->perf.oa.timestamp_frequency);
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
if (!props->metrics_set) {
DRM_DEBUG("OA metric set not specified\n");
return -EINVAL;
}
if (!props->oa_format) {
DRM_DEBUG("OA report format not specified\n");
return -EINVAL;
}
stream->sample_size = sizeof(struct drm_i915_perf_record_header);
format_size = dev_priv->perf.oa.oa_formats[props->oa_format].size;
stream->sample_flags |= SAMPLE_OA_REPORT;
stream->sample_size += format_size;
dev_priv->perf.oa.oa_buffer.format_size = format_size;
if (WARN_ON(dev_priv->perf.oa.oa_buffer.format_size == 0))
return -EINVAL;
dev_priv->perf.oa.oa_buffer.format =
dev_priv->perf.oa.oa_formats[props->oa_format].format;
dev_priv->perf.oa.metrics_set = props->metrics_set;
dev_priv->perf.oa.periodic = props->oa_periodic;
if (dev_priv->perf.oa.periodic) {
u32 tail;
dev_priv->perf.oa.period_exponent = props->oa_period_exponent;
tail = div64_u64(OA_TAIL_MARGIN_NSEC,
oa_exponent_to_ns(dev_priv,
props->oa_period_exponent));
dev_priv->perf.oa.tail_margin = (tail + 1) * format_size;
}
if (stream->ctx) {
ret = oa_get_render_ctx_id(stream);
if (ret)
return ret;
}
ret = alloc_oa_buffer(dev_priv);
if (ret)
goto err_oa_buf_alloc;
intel_runtime_pm_get(dev_priv);
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
ret = dev_priv->perf.oa.ops.enable_metric_set(dev_priv);
if (ret)
goto err_enable;
stream->ops = &i915_oa_stream_ops;
dev_priv->perf.oa.exclusive_stream = stream;
return 0;
err_enable:
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
intel_runtime_pm_put(dev_priv);
free_oa_buffer(dev_priv);
err_oa_buf_alloc:
if (stream->ctx)
oa_put_render_ctx_id(stream);
return ret;
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
if (ret >= 0) {
dev_priv->perf.oa.pollin = false;
}
return ret;
}
static enum hrtimer_restart oa_poll_check_timer_cb(struct hrtimer *hrtimer)
{
struct drm_i915_private *dev_priv =
container_of(hrtimer, typeof(*dev_priv),
perf.oa.poll_check_timer);
if (!dev_priv->perf.oa.ops.oa_buffer_is_empty(dev_priv)) {
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
i915_gem_context_put_unlocked(stream->ctx);
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
static struct i915_gem_context *
lookup_context(struct drm_i915_private *dev_priv,
struct drm_i915_file_private *file_priv,
u32 ctx_user_handle)
{
struct i915_gem_context *ctx;
int ret;
ret = i915_mutex_lock_interruptible(&dev_priv->drm);
if (ret)
return ERR_PTR(ret);
ctx = i915_gem_context_lookup(file_priv, ctx_user_handle);
if (!IS_ERR(ctx))
i915_gem_context_get(ctx);
mutex_unlock(&dev_priv->drm.struct_mutex);
return ctx;
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
int stream_fd;
int ret;
if (props->single_context) {
u32 ctx_handle = props->ctx_handle;
struct drm_i915_file_private *file_priv = file->driver_priv;
specific_ctx = lookup_context(dev_priv, file_priv, ctx_handle);
if (IS_ERR(specific_ctx)) {
ret = PTR_ERR(specific_ctx);
if (ret != -EINTR)
DRM_DEBUG("Failed to look up context with ID %u for opening perf stream\n",
ctx_handle);
goto err;
}
}
if (!specific_ctx &&
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
i915_gem_context_put_unlocked(specific_ctx);
err:
return ret;
}
static int read_properties_unlocked(struct drm_i915_private *dev_priv,
u64 __user *uprops,
u32 n_props,
struct perf_open_properties *props)
{
u64 __user *uprop = uprops;
int i;
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
if (value == 0 ||
value > dev_priv->perf.oa.n_builtin_sets) {
DRM_DEBUG("Unknown OA metric set ID\n");
return -EINVAL;
}
props->metrics_set = value;
break;
case DRM_I915_PERF_PROP_OA_FORMAT:
if (value == 0 || value >= I915_OA_FORMAT_MAX) {
DRM_DEBUG("Invalid OA report format\n");
return -EINVAL;
}
if (!dev_priv->perf.oa.oa_formats[value].size) {
DRM_DEBUG("Invalid OA report format\n");
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
oa_period = 80ull * (2ull << value);
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
if (!IS_HASWELL(dev_priv))
return;
if (!dev_priv->perf.initialized)
return;
mutex_lock(&dev_priv->perf.lock);
dev_priv->perf.metrics_kobj =
kobject_create_and_add("metrics",
&dev_priv->drm.primary->kdev->kobj);
if (!dev_priv->perf.metrics_kobj)
goto exit;
if (i915_perf_register_sysfs_hsw(dev_priv)) {
kobject_put(dev_priv->perf.metrics_kobj);
dev_priv->perf.metrics_kobj = NULL;
}
exit:
mutex_unlock(&dev_priv->perf.lock);
}
void i915_perf_unregister(struct drm_i915_private *dev_priv)
{
if (!IS_HASWELL(dev_priv))
return;
if (!dev_priv->perf.metrics_kobj)
return;
i915_perf_unregister_sysfs_hsw(dev_priv);
kobject_put(dev_priv->perf.metrics_kobj);
dev_priv->perf.metrics_kobj = NULL;
}
void i915_perf_init(struct drm_i915_private *dev_priv)
{
if (!IS_HASWELL(dev_priv))
return;
hrtimer_init(&dev_priv->perf.oa.poll_check_timer,
CLOCK_MONOTONIC, HRTIMER_MODE_REL);
dev_priv->perf.oa.poll_check_timer.function = oa_poll_check_timer_cb;
init_waitqueue_head(&dev_priv->perf.oa.poll_wq);
INIT_LIST_HEAD(&dev_priv->perf.streams);
mutex_init(&dev_priv->perf.lock);
spin_lock_init(&dev_priv->perf.hook_lock);
dev_priv->perf.oa.ops.init_oa_buffer = gen7_init_oa_buffer;
dev_priv->perf.oa.ops.enable_metric_set = hsw_enable_metric_set;
dev_priv->perf.oa.ops.disable_metric_set = hsw_disable_metric_set;
dev_priv->perf.oa.ops.oa_enable = gen7_oa_enable;
dev_priv->perf.oa.ops.oa_disable = gen7_oa_disable;
dev_priv->perf.oa.ops.read = gen7_oa_read;
dev_priv->perf.oa.ops.oa_buffer_is_empty =
gen7_oa_buffer_is_empty_fop_unlocked;
dev_priv->perf.oa.timestamp_frequency = 12500000;
dev_priv->perf.oa.oa_formats = hsw_oa_formats;
dev_priv->perf.oa.n_builtin_sets =
i915_oa_n_builtin_metric_sets_hsw;
dev_priv->perf.sysctl_header = register_sysctl_table(dev_root);
dev_priv->perf.initialized = true;
}
void i915_perf_fini(struct drm_i915_private *dev_priv)
{
if (!dev_priv->perf.initialized)
return;
unregister_sysctl_table(dev_priv->perf.sysctl_header);
memset(&dev_priv->perf.oa.ops, 0, sizeof(dev_priv->perf.oa.ops));
dev_priv->perf.initialized = false;
}
