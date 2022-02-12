static int guc_log_flush_complete(struct intel_guc *guc)
{
u32 action[] = {
INTEL_GUC_ACTION_LOG_BUFFER_FILE_FLUSH_COMPLETE
};
return intel_guc_send(guc, action, ARRAY_SIZE(action));
}
static int guc_log_flush(struct intel_guc *guc)
{
u32 action[] = {
INTEL_GUC_ACTION_FORCE_LOG_BUFFER_FLUSH,
0
};
return intel_guc_send(guc, action, ARRAY_SIZE(action));
}
static int guc_log_control(struct intel_guc *guc, u32 control_val)
{
u32 action[] = {
INTEL_GUC_ACTION_UK_LOG_ENABLE_LOGGING,
control_val
};
return intel_guc_send(guc, action, ARRAY_SIZE(action));
}
static int subbuf_start_callback(struct rchan_buf *buf,
void *subbuf,
void *prev_subbuf,
size_t prev_padding)
{
if (relay_buf_full(buf))
return 0;
return 1;
}
static struct dentry *create_buf_file_callback(const char *filename,
struct dentry *parent,
umode_t mode,
struct rchan_buf *buf,
int *is_global)
{
struct dentry *buf_file;
*is_global = 1;
if (!parent)
return NULL;
buf_file = debugfs_create_file("guc_log", mode,
parent, buf, &relay_file_operations);
return buf_file;
}
static int remove_buf_file_callback(struct dentry *dentry)
{
debugfs_remove(dentry);
return 0;
}
static void guc_log_remove_relay_file(struct intel_guc *guc)
{
relay_close(guc->log.relay_chan);
}
static int guc_log_create_relay_channel(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct rchan *guc_log_relay_chan;
size_t n_subbufs, subbuf_size;
subbuf_size = guc->log.vma->obj->base.size;
n_subbufs = 8;
guc_log_relay_chan = relay_open(NULL, NULL, subbuf_size,
n_subbufs, &relay_callbacks, dev_priv);
if (!guc_log_relay_chan) {
DRM_ERROR("Couldn't create relay chan for GuC logging\n");
return -ENOMEM;
}
GEM_BUG_ON(guc_log_relay_chan->subbuf_size < subbuf_size);
guc->log.relay_chan = guc_log_relay_chan;
return 0;
}
static int guc_log_create_relay_file(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct dentry *log_dir;
int ret;
log_dir = dev_priv->drm.primary->debugfs_root;
if (!log_dir) {
DRM_ERROR("Debugfs dir not available yet for GuC log file\n");
return -ENODEV;
}
ret = relay_late_setup_files(guc->log.relay_chan, "guc_log", log_dir);
if (ret) {
DRM_ERROR("Couldn't associate relay chan with file %d\n", ret);
return ret;
}
return 0;
}
static void guc_move_to_next_buf(struct intel_guc *guc)
{
smp_wmb();
relay_reserve(guc->log.relay_chan, guc->log.vma->obj->base.size);
relay_flush(guc->log.relay_chan);
}
static void *guc_get_write_buffer(struct intel_guc *guc)
{
if (!guc->log.relay_chan)
return NULL;
return relay_reserve(guc->log.relay_chan, 0);
}
static bool guc_check_log_buf_overflow(struct intel_guc *guc,
enum guc_log_buffer_type type,
unsigned int full_cnt)
{
unsigned int prev_full_cnt = guc->log.prev_overflow_count[type];
bool overflow = false;
if (full_cnt != prev_full_cnt) {
overflow = true;
guc->log.prev_overflow_count[type] = full_cnt;
guc->log.total_overflow_count[type] += full_cnt - prev_full_cnt;
if (full_cnt < prev_full_cnt) {
guc->log.total_overflow_count[type] += 16;
}
DRM_ERROR_RATELIMITED("GuC log buffer overflow\n");
}
return overflow;
}
static unsigned int guc_get_log_buffer_size(enum guc_log_buffer_type type)
{
switch (type) {
case GUC_ISR_LOG_BUFFER:
return (GUC_LOG_ISR_PAGES + 1) * PAGE_SIZE;
case GUC_DPC_LOG_BUFFER:
return (GUC_LOG_DPC_PAGES + 1) * PAGE_SIZE;
case GUC_CRASH_DUMP_LOG_BUFFER:
return (GUC_LOG_CRASH_PAGES + 1) * PAGE_SIZE;
default:
MISSING_CASE(type);
}
return 0;
}
static void guc_read_update_log_buffer(struct intel_guc *guc)
{
unsigned int buffer_size, read_offset, write_offset, bytes_to_copy, full_cnt;
struct guc_log_buffer_state *log_buf_state, *log_buf_snapshot_state;
struct guc_log_buffer_state log_buf_state_local;
enum guc_log_buffer_type type;
void *src_data, *dst_data;
bool new_overflow;
if (WARN_ON(!guc->log.buf_addr))
return;
log_buf_state = src_data = guc->log.buf_addr;
log_buf_snapshot_state = dst_data = guc_get_write_buffer(guc);
src_data += PAGE_SIZE;
dst_data += PAGE_SIZE;
for (type = GUC_ISR_LOG_BUFFER; type < GUC_MAX_LOG_BUFFER; type++) {
memcpy(&log_buf_state_local, log_buf_state,
sizeof(struct guc_log_buffer_state));
buffer_size = guc_get_log_buffer_size(type);
read_offset = log_buf_state_local.read_ptr;
write_offset = log_buf_state_local.sampled_write_ptr;
full_cnt = log_buf_state_local.buffer_full_cnt;
guc->log.flush_count[type] += log_buf_state_local.flush_to_file;
new_overflow = guc_check_log_buf_overflow(guc, type, full_cnt);
log_buf_state->read_ptr = write_offset;
log_buf_state->flush_to_file = 0;
log_buf_state++;
if (unlikely(!log_buf_snapshot_state))
continue;
memcpy(log_buf_snapshot_state, &log_buf_state_local,
sizeof(struct guc_log_buffer_state));
log_buf_snapshot_state->write_ptr = write_offset;
log_buf_snapshot_state++;
if (unlikely(new_overflow)) {
read_offset = 0;
write_offset = buffer_size;
} else if (unlikely((read_offset > buffer_size) ||
(write_offset > buffer_size))) {
DRM_ERROR("invalid log buffer state\n");
read_offset = 0;
write_offset = buffer_size;
}
if (read_offset > write_offset) {
i915_memcpy_from_wc(dst_data, src_data, write_offset);
bytes_to_copy = buffer_size - read_offset;
} else {
bytes_to_copy = write_offset - read_offset;
}
i915_memcpy_from_wc(dst_data + read_offset,
src_data + read_offset, bytes_to_copy);
src_data += buffer_size;
dst_data += buffer_size;
}
if (log_buf_snapshot_state)
guc_move_to_next_buf(guc);
else {
DRM_ERROR_RATELIMITED("no sub-buffer to capture logs\n");
guc->log.capture_miss_count++;
}
}
static void guc_log_cleanup(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
lockdep_assert_held(&dev_priv->drm.struct_mutex);
gen9_disable_guc_interrupts(dev_priv);
if (guc->log.flush_wq)
destroy_workqueue(guc->log.flush_wq);
guc->log.flush_wq = NULL;
if (guc->log.relay_chan)
guc_log_remove_relay_file(guc);
guc->log.relay_chan = NULL;
if (guc->log.buf_addr)
i915_gem_object_unpin_map(guc->log.vma->obj);
guc->log.buf_addr = NULL;
}
static void capture_logs_work(struct work_struct *work)
{
struct intel_guc *guc =
container_of(work, struct intel_guc, log.flush_work);
guc_log_capture_logs(guc);
}
static int guc_log_create_extras(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
void *vaddr;
int ret;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
if (i915.guc_log_level < 0)
return 0;
if (!guc->log.buf_addr) {
vaddr = i915_gem_object_pin_map(guc->log.vma->obj, I915_MAP_WC);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
DRM_ERROR("Couldn't map log buffer pages %d\n", ret);
return ret;
}
guc->log.buf_addr = vaddr;
}
if (!guc->log.relay_chan) {
ret = guc_log_create_relay_channel(guc);
if (ret)
return ret;
}
if (!guc->log.flush_wq) {
INIT_WORK(&guc->log.flush_work, capture_logs_work);
guc->log.flush_wq = alloc_ordered_workqueue("i915-guc_log",
WQ_HIGHPRI | WQ_FREEZABLE);
if (guc->log.flush_wq == NULL) {
DRM_ERROR("Couldn't allocate the wq for GuC logging\n");
return -ENOMEM;
}
}
return 0;
}
void intel_guc_log_create(struct intel_guc *guc)
{
struct i915_vma *vma;
unsigned long offset;
uint32_t size, flags;
if (i915.guc_log_level > GUC_LOG_VERBOSITY_MAX)
i915.guc_log_level = GUC_LOG_VERBOSITY_MAX;
size = (1 + GUC_LOG_DPC_PAGES + 1 +
GUC_LOG_ISR_PAGES + 1 +
GUC_LOG_CRASH_PAGES + 1) << PAGE_SHIFT;
vma = guc->log.vma;
if (!vma) {
if (WARN_ON(!i915_has_memcpy_from_wc())) {
i915.guc_log_level = -1;
return;
}
vma = intel_guc_allocate_vma(guc, size);
if (IS_ERR(vma)) {
i915.guc_log_level = -1;
return;
}
guc->log.vma = vma;
if (guc_log_create_extras(guc)) {
guc_log_cleanup(guc);
i915_vma_unpin_and_release(&guc->log.vma);
i915.guc_log_level = -1;
return;
}
}
flags = GUC_LOG_VALID | GUC_LOG_NOTIFY_ON_HALF_FULL |
(GUC_LOG_DPC_PAGES << GUC_LOG_DPC_SHIFT) |
(GUC_LOG_ISR_PAGES << GUC_LOG_ISR_SHIFT) |
(GUC_LOG_CRASH_PAGES << GUC_LOG_CRASH_SHIFT);
offset = guc_ggtt_offset(vma) >> PAGE_SHIFT;
guc->log.flags = (offset << GUC_LOG_BUF_ADDR_SHIFT) | flags;
}
static int guc_log_late_setup(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
int ret;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
if (i915.guc_log_level < 0)
return -EINVAL;
ret = guc_log_create_extras(guc);
if (ret)
goto err;
ret = guc_log_create_relay_file(guc);
if (ret)
goto err;
return 0;
err:
guc_log_cleanup(guc);
i915.guc_log_level = -1;
return ret;
}
static void guc_log_capture_logs(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
guc_read_update_log_buffer(guc);
intel_runtime_pm_get(dev_priv);
guc_log_flush_complete(guc);
intel_runtime_pm_put(dev_priv);
}
static void guc_flush_logs(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
if (!i915.enable_guc_submission || (i915.guc_log_level < 0))
return;
gen9_disable_guc_interrupts(dev_priv);
flush_work(&guc->log.flush_work);
guc_log_flush(guc);
guc_log_capture_logs(guc);
}
int i915_guc_log_control(struct drm_i915_private *dev_priv, u64 control_val)
{
struct intel_guc *guc = &dev_priv->guc;
union guc_log_control log_param;
int ret;
log_param.value = control_val;
if (log_param.verbosity < GUC_LOG_VERBOSITY_MIN ||
log_param.verbosity > GUC_LOG_VERBOSITY_MAX)
return -EINVAL;
if (!log_param.logging_enabled && (i915.guc_log_level < 0))
return 0;
ret = guc_log_control(guc, log_param.value);
if (ret < 0) {
DRM_DEBUG_DRIVER("guc_logging_control action failed %d\n", ret);
return ret;
}
i915.guc_log_level = log_param.verbosity;
if (!dev_priv->guc.log.relay_chan) {
ret = guc_log_late_setup(guc);
if (!ret)
gen9_enable_guc_interrupts(dev_priv);
} else if (!log_param.logging_enabled) {
guc_flush_logs(guc);
i915.guc_log_level = -1;
} else {
gen9_enable_guc_interrupts(dev_priv);
}
return ret;
}
void i915_guc_log_register(struct drm_i915_private *dev_priv)
{
if (!i915.enable_guc_submission)
return;
mutex_lock(&dev_priv->drm.struct_mutex);
guc_log_late_setup(&dev_priv->guc);
mutex_unlock(&dev_priv->drm.struct_mutex);
}
void i915_guc_log_unregister(struct drm_i915_private *dev_priv)
{
if (!i915.enable_guc_submission)
return;
mutex_lock(&dev_priv->drm.struct_mutex);
guc_log_cleanup(&dev_priv->guc);
mutex_unlock(&dev_priv->drm.struct_mutex);
}
