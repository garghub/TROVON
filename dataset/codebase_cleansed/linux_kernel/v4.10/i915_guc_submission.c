static inline bool host2guc_action_response(struct drm_i915_private *dev_priv,
u32 *status)
{
u32 val = I915_READ(SOFT_SCRATCH(0));
*status = val;
return GUC2HOST_IS_RESPONSE(val);
}
static int host2guc_action(struct intel_guc *guc, u32 *data, u32 len)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 status;
int i;
int ret;
if (WARN_ON(len < 1 || len > 15))
return -EINVAL;
mutex_lock(&guc->action_lock);
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
dev_priv->guc.action_count += 1;
dev_priv->guc.action_cmd = data[0];
for (i = 0; i < len; i++)
I915_WRITE(SOFT_SCRATCH(i), data[i]);
POSTING_READ(SOFT_SCRATCH(i - 1));
I915_WRITE(HOST2GUC_INTERRUPT, HOST2GUC_TRIGGER);
ret = wait_for_us(host2guc_action_response(dev_priv, &status), 10);
if (ret)
ret = wait_for(host2guc_action_response(dev_priv, &status), 10);
if (status != GUC2HOST_STATUS_SUCCESS) {
if (ret != -ETIMEDOUT)
ret = -EIO;
DRM_WARN("Action 0x%X failed; ret=%d status=0x%08X response=0x%08X\n",
data[0], ret, status, I915_READ(SOFT_SCRATCH(15)));
dev_priv->guc.action_fail += 1;
dev_priv->guc.action_err = ret;
}
dev_priv->guc.action_status = status;
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
mutex_unlock(&guc->action_lock);
return ret;
}
static int host2guc_allocate_doorbell(struct intel_guc *guc,
struct i915_guc_client *client)
{
u32 data[2];
data[0] = HOST2GUC_ACTION_ALLOCATE_DOORBELL;
data[1] = client->ctx_index;
return host2guc_action(guc, data, 2);
}
static int host2guc_release_doorbell(struct intel_guc *guc,
struct i915_guc_client *client)
{
u32 data[2];
data[0] = HOST2GUC_ACTION_DEALLOCATE_DOORBELL;
data[1] = client->ctx_index;
return host2guc_action(guc, data, 2);
}
static int host2guc_sample_forcewake(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 data[2];
data[0] = HOST2GUC_ACTION_SAMPLE_FORCEWAKE;
if (!intel_enable_rc6() || NEEDS_WaRsDisableCoarsePowerGating(dev_priv))
data[1] = 0;
else
data[1] = GUC_FORCEWAKE_RENDER | GUC_FORCEWAKE_MEDIA;
return host2guc_action(guc, data, ARRAY_SIZE(data));
}
static int host2guc_logbuffer_flush_complete(struct intel_guc *guc)
{
u32 data[1];
data[0] = HOST2GUC_ACTION_LOG_BUFFER_FILE_FLUSH_COMPLETE;
return host2guc_action(guc, data, 1);
}
static int host2guc_force_logbuffer_flush(struct intel_guc *guc)
{
u32 data[2];
data[0] = HOST2GUC_ACTION_FORCE_LOG_BUFFER_FLUSH;
data[1] = 0;
return host2guc_action(guc, data, 2);
}
static int host2guc_logging_control(struct intel_guc *guc, u32 control_val)
{
u32 data[2];
data[0] = HOST2GUC_ACTION_UK_LOG_ENABLE_LOGGING;
data[1] = control_val;
return host2guc_action(guc, data, 2);
}
static int guc_update_doorbell_id(struct intel_guc *guc,
struct i915_guc_client *client,
u16 new_id)
{
struct sg_table *sg = guc->ctx_pool_vma->pages;
void *doorbell_bitmap = guc->doorbell_bitmap;
struct guc_doorbell_info *doorbell;
struct guc_context_desc desc;
size_t len;
doorbell = client->vaddr + client->doorbell_offset;
if (client->doorbell_id != GUC_INVALID_DOORBELL_ID &&
test_bit(client->doorbell_id, doorbell_bitmap)) {
doorbell->db_status = GUC_DOORBELL_DISABLED;
(void)host2guc_release_doorbell(guc, client);
__clear_bit(client->doorbell_id, doorbell_bitmap);
}
len = sg_pcopy_to_buffer(sg->sgl, sg->nents, &desc, sizeof(desc),
sizeof(desc) * client->ctx_index);
if (len != sizeof(desc))
return -EFAULT;
desc.db_id = new_id;
len = sg_pcopy_from_buffer(sg->sgl, sg->nents, &desc, sizeof(desc),
sizeof(desc) * client->ctx_index);
if (len != sizeof(desc))
return -EFAULT;
client->doorbell_id = new_id;
if (new_id == GUC_INVALID_DOORBELL_ID)
return 0;
__set_bit(new_id, doorbell_bitmap);
doorbell->cookie = 0;
doorbell->db_status = GUC_DOORBELL_ENABLED;
return host2guc_allocate_doorbell(guc, client);
}
static int guc_init_doorbell(struct intel_guc *guc,
struct i915_guc_client *client,
uint16_t db_id)
{
return guc_update_doorbell_id(guc, client, db_id);
}
static void guc_disable_doorbell(struct intel_guc *guc,
struct i915_guc_client *client)
{
(void)guc_update_doorbell_id(guc, client, GUC_INVALID_DOORBELL_ID);
}
static uint16_t
select_doorbell_register(struct intel_guc *guc, uint32_t priority)
{
const bool hi_pri = (priority <= GUC_CTX_PRIORITY_HIGH);
const uint16_t half = GUC_MAX_DOORBELLS / 2;
const uint16_t start = hi_pri ? half : 0;
const uint16_t end = start + half;
uint16_t id;
id = find_next_zero_bit(guc->doorbell_bitmap, end, start);
if (id == end)
id = GUC_INVALID_DOORBELL_ID;
DRM_DEBUG_DRIVER("assigned %s priority doorbell id 0x%x\n",
hi_pri ? "high" : "normal", id);
return id;
}
static uint32_t select_doorbell_cacheline(struct intel_guc *guc)
{
const uint32_t cacheline_size = cache_line_size();
uint32_t offset;
offset = offset_in_page(guc->db_cacheline);
guc->db_cacheline += cacheline_size;
DRM_DEBUG_DRIVER("selected doorbell cacheline 0x%x, next 0x%x, linesize %u\n",
offset, guc->db_cacheline, cacheline_size);
return offset;
}
static void guc_proc_desc_init(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct guc_process_desc *desc;
desc = client->vaddr + client->proc_desc_offset;
memset(desc, 0, sizeof(*desc));
desc->wq_base_addr = 0;
desc->db_base_addr = 0;
desc->context_id = client->ctx_index;
desc->wq_size_bytes = client->wq_size;
desc->wq_status = WQ_STATUS_ACTIVE;
desc->priority = client->priority;
}
static void guc_ctx_desc_init(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct intel_engine_cs *engine;
struct i915_gem_context *ctx = client->owner;
struct guc_context_desc desc;
struct sg_table *sg;
unsigned int tmp;
u32 gfx_addr;
memset(&desc, 0, sizeof(desc));
desc.attribute = GUC_CTX_DESC_ATTR_ACTIVE | GUC_CTX_DESC_ATTR_KERNEL;
desc.context_id = client->ctx_index;
desc.priority = client->priority;
desc.db_id = client->doorbell_id;
for_each_engine_masked(engine, dev_priv, client->engines, tmp) {
struct intel_context *ce = &ctx->engine[engine->id];
uint32_t guc_engine_id = engine->guc_id;
struct guc_execlist_context *lrc = &desc.lrc[guc_engine_id];
if (!ce->state)
break;
lrc->context_desc = lower_32_bits(ce->lrc_desc);
lrc->ring_lcra =
i915_ggtt_offset(ce->state) + LRC_STATE_PN * PAGE_SIZE;
lrc->context_id = (client->ctx_index << GUC_ELC_CTXID_OFFSET) |
(guc_engine_id << GUC_ELC_ENGINE_OFFSET);
lrc->ring_begin = i915_ggtt_offset(ce->ring->vma);
lrc->ring_end = lrc->ring_begin + ce->ring->size - 1;
lrc->ring_next_free_location = lrc->ring_begin;
lrc->ring_current_tail_pointer_value = 0;
desc.engines_used |= (1 << guc_engine_id);
}
DRM_DEBUG_DRIVER("Host engines 0x%x => GuC engines used 0x%x\n",
client->engines, desc.engines_used);
WARN_ON(desc.engines_used == 0);
gfx_addr = i915_ggtt_offset(client->vma);
desc.db_trigger_phy = sg_dma_address(client->vma->pages->sgl) +
client->doorbell_offset;
desc.db_trigger_cpu =
(uintptr_t)client->vaddr + client->doorbell_offset;
desc.db_trigger_uk = gfx_addr + client->doorbell_offset;
desc.process_desc = gfx_addr + client->proc_desc_offset;
desc.wq_addr = gfx_addr + client->wq_offset;
desc.wq_size = client->wq_size;
desc.desc_private = (uintptr_t)client;
sg = guc->ctx_pool_vma->pages;
sg_pcopy_from_buffer(sg->sgl, sg->nents, &desc, sizeof(desc),
sizeof(desc) * client->ctx_index);
}
static void guc_ctx_desc_fini(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct guc_context_desc desc;
struct sg_table *sg;
memset(&desc, 0, sizeof(desc));
sg = guc->ctx_pool_vma->pages;
sg_pcopy_from_buffer(sg->sgl, sg->nents, &desc, sizeof(desc),
sizeof(desc) * client->ctx_index);
}
int i915_guc_wq_reserve(struct drm_i915_gem_request *request)
{
const size_t wqi_size = sizeof(struct guc_wq_item);
struct i915_guc_client *gc = request->i915->guc.execbuf_client;
struct guc_process_desc *desc = gc->vaddr + gc->proc_desc_offset;
u32 freespace;
int ret;
spin_lock(&gc->wq_lock);
freespace = CIRC_SPACE(gc->wq_tail, desc->head, gc->wq_size);
freespace -= gc->wq_rsvd;
if (likely(freespace >= wqi_size)) {
gc->wq_rsvd += wqi_size;
ret = 0;
} else {
gc->no_wq_space++;
ret = -EAGAIN;
}
spin_unlock(&gc->wq_lock);
return ret;
}
void i915_guc_wq_unreserve(struct drm_i915_gem_request *request)
{
const size_t wqi_size = sizeof(struct guc_wq_item);
struct i915_guc_client *gc = request->i915->guc.execbuf_client;
GEM_BUG_ON(READ_ONCE(gc->wq_rsvd) < wqi_size);
spin_lock(&gc->wq_lock);
gc->wq_rsvd -= wqi_size;
spin_unlock(&gc->wq_lock);
}
static void guc_wq_item_append(struct i915_guc_client *gc,
struct drm_i915_gem_request *rq)
{
const size_t wqi_size = sizeof(struct guc_wq_item);
const u32 wqi_len = wqi_size/sizeof(u32) - 1;
struct intel_engine_cs *engine = rq->engine;
struct guc_process_desc *desc;
struct guc_wq_item *wqi;
u32 freespace, tail, wq_off;
desc = gc->vaddr + gc->proc_desc_offset;
freespace = CIRC_SPACE(gc->wq_tail, desc->head, gc->wq_size);
GEM_BUG_ON(freespace < wqi_size);
tail = rq->tail;
GEM_BUG_ON(tail & 7);
tail >>= 3;
GEM_BUG_ON(tail > WQ_RING_TAIL_MAX);
BUILD_BUG_ON(wqi_size != 16);
GEM_BUG_ON(gc->wq_rsvd < wqi_size);
wq_off = gc->wq_tail;
GEM_BUG_ON(wq_off & (wqi_size - 1));
gc->wq_tail += wqi_size;
gc->wq_tail &= gc->wq_size - 1;
gc->wq_rsvd -= wqi_size;
wqi = gc->vaddr + wq_off + GUC_DB_SIZE;
wqi->header = WQ_TYPE_INORDER |
(wqi_len << WQ_LEN_SHIFT) |
(engine->guc_id << WQ_TARGET_SHIFT) |
WQ_NO_WCFLUSH_WAIT;
wqi->context_desc = (u32)intel_lr_context_descriptor(rq->ctx, engine);
wqi->ring_tail = tail << WQ_RING_TAIL_SHIFT;
wqi->fence_id = rq->global_seqno;
}
static int guc_ring_doorbell(struct i915_guc_client *gc)
{
struct guc_process_desc *desc;
union guc_doorbell_qw db_cmp, db_exc, db_ret;
union guc_doorbell_qw *db;
int attempt = 2, ret = -EAGAIN;
desc = gc->vaddr + gc->proc_desc_offset;
desc->tail = gc->wq_tail;
db_cmp.db_status = GUC_DOORBELL_ENABLED;
db_cmp.cookie = gc->cookie;
db_exc.db_status = GUC_DOORBELL_ENABLED;
db_exc.cookie = gc->cookie + 1;
if (db_exc.cookie == 0)
db_exc.cookie = 1;
db = gc->vaddr + gc->doorbell_offset;
while (attempt--) {
db_ret.value_qw = atomic64_cmpxchg((atomic64_t *)db,
db_cmp.value_qw, db_exc.value_qw);
if (db_ret.value_qw == db_cmp.value_qw) {
gc->cookie = db_exc.cookie;
ret = 0;
break;
}
if (db_ret.db_status == GUC_DOORBELL_DISABLED)
break;
DRM_WARN("Cookie mismatch. Expected %d, found %d\n",
db_cmp.cookie, db_ret.cookie);
db_cmp.cookie = db_ret.cookie;
db_exc.cookie = db_ret.cookie + 1;
if (db_exc.cookie == 0)
db_exc.cookie = 1;
}
return ret;
}
static void i915_guc_submit(struct drm_i915_gem_request *rq)
{
struct drm_i915_private *dev_priv = rq->i915;
struct intel_engine_cs *engine = rq->engine;
unsigned int engine_id = engine->id;
struct intel_guc *guc = &rq->i915->guc;
struct i915_guc_client *client = guc->execbuf_client;
int b_ret;
rq->previous_context = engine->last_context;
engine->last_context = rq->ctx;
i915_gem_request_submit(rq);
spin_lock(&client->wq_lock);
guc_wq_item_append(client, rq);
if (i915_vma_is_map_and_fenceable(rq->ring->vma))
POSTING_READ_FW(GUC_STATUS);
b_ret = guc_ring_doorbell(client);
client->submissions[engine_id] += 1;
client->retcode = b_ret;
if (b_ret)
client->b_fail += 1;
guc->submissions[engine_id] += 1;
guc->last_seqno[engine_id] = rq->global_seqno;
spin_unlock(&client->wq_lock);
}
static struct i915_vma *guc_allocate_vma(struct intel_guc *guc, u32 size)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct drm_i915_gem_object *obj;
struct i915_vma *vma;
int ret;
obj = i915_gem_object_create(&dev_priv->drm, size);
if (IS_ERR(obj))
return ERR_CAST(obj);
vma = i915_vma_create(obj, &dev_priv->ggtt.base, NULL);
if (IS_ERR(vma))
goto err;
ret = i915_vma_pin(vma, 0, PAGE_SIZE,
PIN_GLOBAL | PIN_OFFSET_BIAS | GUC_WOPCM_TOP);
if (ret) {
vma = ERR_PTR(ret);
goto err;
}
I915_WRITE(GEN8_GTCR, GEN8_GTCR_INVALIDATE);
return vma;
err:
i915_gem_object_put(obj);
return vma;
}
static void
guc_client_free(struct drm_i915_private *dev_priv,
struct i915_guc_client *client)
{
struct intel_guc *guc = &dev_priv->guc;
if (!client)
return;
if (client->vaddr) {
guc_disable_doorbell(guc, client);
i915_gem_object_unpin_map(client->vma->obj);
}
i915_vma_unpin_and_release(&client->vma);
if (client->ctx_index != GUC_INVALID_CTX_ID) {
guc_ctx_desc_fini(guc, client);
ida_simple_remove(&guc->ctx_ids, client->ctx_index);
}
kfree(client);
}
static bool guc_doorbell_check(struct intel_guc *guc, uint16_t db_id)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
i915_reg_t drbreg = GEN8_DRBREGL(db_id);
uint32_t value = I915_READ(drbreg);
bool enabled = (value & GUC_DOORBELL_ENABLED) != 0;
bool expected = test_bit(db_id, guc->doorbell_bitmap);
if (enabled == expected)
return true;
DRM_DEBUG_DRIVER("Doorbell %d (reg 0x%x) 0x%x, should be %s\n",
db_id, drbreg.reg, value,
expected ? "active" : "inactive");
return false;
}
static void guc_init_doorbell_hw(struct intel_guc *guc)
{
struct i915_guc_client *client = guc->execbuf_client;
uint16_t db_id;
int i, err;
db_id = client->doorbell_id;
for (i = 0; i < GUC_MAX_DOORBELLS; ++i) {
if (guc_doorbell_check(guc, i))
continue;
err = guc_update_doorbell_id(guc, client, i);
if (err)
DRM_DEBUG_DRIVER("Doorbell %d update failed, err %d\n",
i, err);
}
err = guc_update_doorbell_id(guc, client, db_id);
if (err)
DRM_WARN("Failed to restore doorbell to %d, err %d\n",
db_id, err);
for (i = 0; i < GUC_MAX_DOORBELLS; ++i)
(void)guc_doorbell_check(guc, i);
}
static struct i915_guc_client *
guc_client_alloc(struct drm_i915_private *dev_priv,
uint32_t engines,
uint32_t priority,
struct i915_gem_context *ctx)
{
struct i915_guc_client *client;
struct intel_guc *guc = &dev_priv->guc;
struct i915_vma *vma;
void *vaddr;
uint16_t db_id;
client = kzalloc(sizeof(*client), GFP_KERNEL);
if (!client)
return NULL;
client->owner = ctx;
client->guc = guc;
client->engines = engines;
client->priority = priority;
client->doorbell_id = GUC_INVALID_DOORBELL_ID;
client->ctx_index = (uint32_t)ida_simple_get(&guc->ctx_ids, 0,
GUC_MAX_GPU_CONTEXTS, GFP_KERNEL);
if (client->ctx_index >= GUC_MAX_GPU_CONTEXTS) {
client->ctx_index = GUC_INVALID_CTX_ID;
goto err;
}
vma = guc_allocate_vma(guc, GUC_DB_SIZE + GUC_WQ_SIZE);
if (IS_ERR(vma))
goto err;
client->vma = vma;
vaddr = i915_gem_object_pin_map(vma->obj, I915_MAP_WB);
if (IS_ERR(vaddr))
goto err;
client->vaddr = vaddr;
spin_lock_init(&client->wq_lock);
client->wq_offset = GUC_DB_SIZE;
client->wq_size = GUC_WQ_SIZE;
db_id = select_doorbell_register(guc, client->priority);
if (db_id == GUC_INVALID_DOORBELL_ID)
goto err;
client->doorbell_offset = select_doorbell_cacheline(guc);
if (client->doorbell_offset >= (GUC_DB_SIZE / 2))
client->proc_desc_offset = 0;
else
client->proc_desc_offset = (GUC_DB_SIZE / 2);
guc_proc_desc_init(guc, client);
guc_ctx_desc_init(guc, client);
if (guc_init_doorbell(guc, client, db_id))
goto err;
DRM_DEBUG_DRIVER("new priority %u client %p for engine(s) 0x%x: ctx_index %u\n",
priority, client, client->engines, client->ctx_index);
DRM_DEBUG_DRIVER("doorbell id %u, cacheline offset 0x%x\n",
client->doorbell_id, client->doorbell_offset);
return client;
err:
guc_client_free(dev_priv, client);
return NULL;
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
static bool
guc_check_log_buf_overflow(struct intel_guc *guc,
enum guc_log_buffer_type type, unsigned int full_cnt)
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
static void guc_capture_logs_work(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, struct drm_i915_private, guc.log.flush_work);
i915_guc_capture_logs(dev_priv);
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
INIT_WORK(&guc->log.flush_work, guc_capture_logs_work);
guc->log.flush_wq = alloc_ordered_workqueue("i915-guc_log",
WQ_HIGHPRI | WQ_FREEZABLE);
if (guc->log.flush_wq == NULL) {
DRM_ERROR("Couldn't allocate the wq for GuC logging\n");
return -ENOMEM;
}
}
return 0;
}
static void guc_log_create(struct intel_guc *guc)
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
if (WARN_ON(!i915_memcpy_from_wc(NULL, NULL, 0))) {
i915.guc_log_level = -1;
return;
}
vma = guc_allocate_vma(guc, size);
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
offset = i915_ggtt_offset(vma) >> PAGE_SHIFT;
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
static void guc_policies_init(struct guc_policies *policies)
{
struct guc_policy *policy;
u32 p, i;
policies->dpc_promote_time = 500000;
policies->max_num_work_items = POLICY_MAX_NUM_WI;
for (p = 0; p < GUC_CTX_PRIORITY_NUM; p++) {
for (i = GUC_RENDER_ENGINE; i < GUC_MAX_ENGINES_NUM; i++) {
policy = &policies->policy[p][i];
policy->execution_quantum = 1000000;
policy->preemption_time = 500000;
policy->fault_time = 250000;
policy->policy_flags = 0;
}
}
policies->is_valid = 1;
}
static void guc_addon_create(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct i915_vma *vma;
struct guc_ads *ads;
struct guc_policies *policies;
struct guc_mmio_reg_state *reg_state;
struct intel_engine_cs *engine;
enum intel_engine_id id;
struct page *page;
u32 size;
size = sizeof(struct guc_ads) + sizeof(struct guc_policies) +
sizeof(struct guc_mmio_reg_state) +
GUC_S3_SAVE_SPACE_PAGES * PAGE_SIZE;
vma = guc->ads_vma;
if (!vma) {
vma = guc_allocate_vma(guc, PAGE_ALIGN(size));
if (IS_ERR(vma))
return;
guc->ads_vma = vma;
}
page = i915_vma_first_page(vma);
ads = kmap(page);
engine = dev_priv->engine[RCS];
ads->golden_context_lrca = engine->status_page.ggtt_offset;
for_each_engine(engine, dev_priv, id)
ads->eng_state_size[engine->guc_id] = intel_lr_context_size(engine);
policies = (void *)ads + sizeof(struct guc_ads);
guc_policies_init(policies);
ads->scheduler_policies =
i915_ggtt_offset(vma) + sizeof(struct guc_ads);
reg_state = (void *)policies + sizeof(struct guc_policies);
for_each_engine(engine, dev_priv, id) {
reg_state->mmio_white_list[engine->guc_id].mmio_start =
engine->mmio_base + GUC_MMIO_WHITE_LIST_START;
reg_state->mmio_white_list[engine->guc_id].count = 0;
}
ads->reg_state_addr = ads->scheduler_policies +
sizeof(struct guc_policies);
ads->reg_state_buffer = ads->reg_state_addr +
sizeof(struct guc_mmio_reg_state);
kunmap(page);
}
int i915_guc_submission_init(struct drm_i915_private *dev_priv)
{
const size_t ctxsize = sizeof(struct guc_context_desc);
const size_t poolsize = GUC_MAX_GPU_CONTEXTS * ctxsize;
const size_t gemsize = round_up(poolsize, PAGE_SIZE);
struct intel_guc *guc = &dev_priv->guc;
struct i915_vma *vma;
bitmap_clear(guc->doorbell_bitmap, 0, GUC_MAX_DOORBELLS);
i915_guc_submission_disable(dev_priv);
if (!i915.enable_guc_submission)
return 0;
if (guc->ctx_pool_vma)
return 0;
vma = guc_allocate_vma(guc, gemsize);
if (IS_ERR(vma))
return PTR_ERR(vma);
guc->ctx_pool_vma = vma;
ida_init(&guc->ctx_ids);
mutex_init(&guc->action_lock);
guc_log_create(guc);
guc_addon_create(guc);
return 0;
}
int i915_guc_submission_enable(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
struct drm_i915_gem_request *request;
struct i915_guc_client *client;
struct intel_engine_cs *engine;
enum intel_engine_id id;
client = guc_client_alloc(dev_priv,
INTEL_INFO(dev_priv)->ring_mask,
GUC_CTX_PRIORITY_KMD_NORMAL,
dev_priv->kernel_context);
if (!client) {
DRM_ERROR("Failed to create normal GuC client!\n");
return -ENOMEM;
}
guc->execbuf_client = client;
host2guc_sample_forcewake(guc, client);
guc_init_doorbell_hw(guc);
for_each_engine(engine, dev_priv, id) {
engine->submit_request = i915_guc_submit;
engine->schedule = NULL;
list_for_each_entry(request,
&engine->timeline->requests, link) {
client->wq_rsvd += sizeof(struct guc_wq_item);
if (i915_sw_fence_done(&request->submit))
i915_guc_submit(request);
}
}
return 0;
}
void i915_guc_submission_disable(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
if (!guc->execbuf_client)
return;
intel_execlists_enable_submission(dev_priv);
guc_client_free(dev_priv, guc->execbuf_client);
guc->execbuf_client = NULL;
}
void i915_guc_submission_fini(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
i915_vma_unpin_and_release(&guc->ads_vma);
i915_vma_unpin_and_release(&guc->log.vma);
if (guc->ctx_pool_vma)
ida_destroy(&guc->ctx_ids);
i915_vma_unpin_and_release(&guc->ctx_pool_vma);
}
int intel_guc_suspend(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_guc *guc = &dev_priv->guc;
struct i915_gem_context *ctx;
u32 data[3];
if (guc->guc_fw.guc_fw_load_status != GUC_FIRMWARE_SUCCESS)
return 0;
gen9_disable_guc_interrupts(dev_priv);
ctx = dev_priv->kernel_context;
data[0] = HOST2GUC_ACTION_ENTER_S_STATE;
data[1] = GUC_POWER_D1;
data[2] = i915_ggtt_offset(ctx->engine[RCS].state);
return host2guc_action(guc, data, ARRAY_SIZE(data));
}
int intel_guc_resume(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_guc *guc = &dev_priv->guc;
struct i915_gem_context *ctx;
u32 data[3];
if (guc->guc_fw.guc_fw_load_status != GUC_FIRMWARE_SUCCESS)
return 0;
if (i915.guc_log_level >= 0)
gen9_enable_guc_interrupts(dev_priv);
ctx = dev_priv->kernel_context;
data[0] = HOST2GUC_ACTION_EXIT_S_STATE;
data[1] = GUC_POWER_D0;
data[2] = i915_ggtt_offset(ctx->engine[RCS].state);
return host2guc_action(guc, data, ARRAY_SIZE(data));
}
void i915_guc_capture_logs(struct drm_i915_private *dev_priv)
{
guc_read_update_log_buffer(&dev_priv->guc);
intel_runtime_pm_get(dev_priv);
host2guc_logbuffer_flush_complete(&dev_priv->guc);
intel_runtime_pm_put(dev_priv);
}
void i915_guc_flush_logs(struct drm_i915_private *dev_priv)
{
if (!i915.enable_guc_submission || (i915.guc_log_level < 0))
return;
gen9_disable_guc_interrupts(dev_priv);
flush_work(&dev_priv->guc.log.flush_work);
host2guc_force_logbuffer_flush(&dev_priv->guc);
i915_guc_capture_logs(dev_priv);
}
void i915_guc_unregister(struct drm_i915_private *dev_priv)
{
if (!i915.enable_guc_submission)
return;
mutex_lock(&dev_priv->drm.struct_mutex);
guc_log_cleanup(&dev_priv->guc);
mutex_unlock(&dev_priv->drm.struct_mutex);
}
void i915_guc_register(struct drm_i915_private *dev_priv)
{
if (!i915.enable_guc_submission)
return;
mutex_lock(&dev_priv->drm.struct_mutex);
guc_log_late_setup(&dev_priv->guc);
mutex_unlock(&dev_priv->drm.struct_mutex);
}
int i915_guc_log_control(struct drm_i915_private *dev_priv, u64 control_val)
{
union guc_log_control log_param;
int ret;
log_param.value = control_val;
if (log_param.verbosity < GUC_LOG_VERBOSITY_MIN ||
log_param.verbosity > GUC_LOG_VERBOSITY_MAX)
return -EINVAL;
if (!log_param.logging_enabled && (i915.guc_log_level < 0))
return 0;
ret = host2guc_logging_control(&dev_priv->guc, log_param.value);
if (ret < 0) {
DRM_DEBUG_DRIVER("host2guc action failed %d\n", ret);
return ret;
}
i915.guc_log_level = log_param.verbosity;
if (!dev_priv->guc.log.relay_chan) {
ret = guc_log_late_setup(&dev_priv->guc);
if (!ret)
gen9_enable_guc_interrupts(dev_priv);
} else if (!log_param.logging_enabled) {
i915_guc_flush_logs(dev_priv);
i915.guc_log_level = -1;
} else {
gen9_enable_guc_interrupts(dev_priv);
}
return ret;
}
