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
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
dev_priv->guc.action_count += 1;
dev_priv->guc.action_cmd = data[0];
for (i = 0; i < len; i++)
I915_WRITE(SOFT_SCRATCH(i), data[i]);
POSTING_READ(SOFT_SCRATCH(i - 1));
I915_WRITE(HOST2GUC_INTERRUPT, HOST2GUC_TRIGGER);
ret = wait_for_atomic(host2guc_action_response(dev_priv, &status), 10);
if (status != GUC2HOST_STATUS_SUCCESS) {
if (ret != -ETIMEDOUT)
ret = -EIO;
DRM_ERROR("GUC: host2guc action 0x%X failed. ret=%d "
"status=0x%08X response=0x%08X\n",
data[0], ret, status,
I915_READ(SOFT_SCRATCH(15)));
dev_priv->guc.action_fail += 1;
dev_priv->guc.action_err = ret;
}
dev_priv->guc.action_status = status;
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
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
struct drm_device *dev = dev_priv->dev;
u32 data[2];
data[0] = HOST2GUC_ACTION_SAMPLE_FORCEWAKE;
if (!intel_enable_rc6(dev_priv->dev) ||
IS_BXT_REVID(dev, 0, BXT_REVID_A1) ||
(IS_SKL_GT3(dev) && IS_SKL_REVID(dev, 0, SKL_REVID_E0)) ||
(IS_SKL_GT4(dev) && IS_SKL_REVID(dev, 0, SKL_REVID_E0)))
data[1] = 0;
else
data[1] = GUC_FORCEWAKE_RENDER | GUC_FORCEWAKE_MEDIA;
return host2guc_action(guc, data, ARRAY_SIZE(data));
}
static void guc_init_doorbell(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct guc_doorbell_info *doorbell;
void *base;
base = kmap_atomic(i915_gem_object_get_page(client->client_obj, 0));
doorbell = base + client->doorbell_offset;
doorbell->db_status = 1;
doorbell->cookie = 0;
kunmap_atomic(base);
}
static int guc_ring_doorbell(struct i915_guc_client *gc)
{
struct guc_process_desc *desc;
union guc_doorbell_qw db_cmp, db_exc, db_ret;
union guc_doorbell_qw *db;
void *base;
int attempt = 2, ret = -EAGAIN;
base = kmap_atomic(i915_gem_object_get_page(gc->client_obj, 0));
desc = base + gc->proc_desc_offset;
desc->tail = gc->wq_tail;
db_cmp.db_status = GUC_DOORBELL_ENABLED;
db_cmp.cookie = gc->cookie;
db_exc.db_status = GUC_DOORBELL_ENABLED;
db_exc.cookie = gc->cookie + 1;
if (db_exc.cookie == 0)
db_exc.cookie = 1;
db = base + gc->doorbell_offset;
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
DRM_ERROR("Cookie mismatch. Expected %d, returned %d\n",
db_cmp.cookie, db_ret.cookie);
db_cmp.cookie = db_ret.cookie;
db_exc.cookie = db_ret.cookie + 1;
if (db_exc.cookie == 0)
db_exc.cookie = 1;
}
kunmap_atomic(base);
return ret;
}
static void guc_disable_doorbell(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct guc_doorbell_info *doorbell;
void *base;
i915_reg_t drbreg = GEN8_DRBREGL(client->doorbell_id);
int value;
base = kmap_atomic(i915_gem_object_get_page(client->client_obj, 0));
doorbell = base + client->doorbell_offset;
doorbell->db_status = 0;
kunmap_atomic(base);
I915_WRITE(drbreg, I915_READ(drbreg) & ~GEN8_DRB_VALID);
value = I915_READ(drbreg);
WARN_ON((value & GEN8_DRB_VALID) != 0);
I915_WRITE(GEN8_DRBREGU(client->doorbell_id), 0);
I915_WRITE(drbreg, 0);
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
static uint16_t assign_doorbell(struct intel_guc *guc, uint32_t priority)
{
const bool hi_pri = (priority <= GUC_CTX_PRIORITY_HIGH);
const uint16_t half = GUC_MAX_DOORBELLS / 2;
const uint16_t start = hi_pri ? half : 0;
const uint16_t end = start + half;
uint16_t id;
id = find_next_zero_bit(guc->doorbell_bitmap, end, start);
if (id == end)
id = GUC_INVALID_DOORBELL_ID;
else
bitmap_set(guc->doorbell_bitmap, id, 1);
DRM_DEBUG_DRIVER("assigned %s priority doorbell id 0x%x\n",
hi_pri ? "high" : "normal", id);
return id;
}
static void release_doorbell(struct intel_guc *guc, uint16_t id)
{
bitmap_clear(guc->doorbell_bitmap, id, 1);
}
static void guc_init_proc_desc(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct guc_process_desc *desc;
void *base;
base = kmap_atomic(i915_gem_object_get_page(client->client_obj, 0));
desc = base + client->proc_desc_offset;
memset(desc, 0, sizeof(*desc));
desc->wq_base_addr = 0;
desc->db_base_addr = 0;
desc->context_id = client->ctx_index;
desc->wq_size_bytes = client->wq_size;
desc->wq_status = WQ_STATUS_ACTIVE;
desc->priority = client->priority;
kunmap_atomic(base);
}
static void guc_init_ctx_desc(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct intel_context *ctx = client->owner;
struct guc_context_desc desc;
struct sg_table *sg;
int i;
memset(&desc, 0, sizeof(desc));
desc.attribute = GUC_CTX_DESC_ATTR_ACTIVE | GUC_CTX_DESC_ATTR_KERNEL;
desc.context_id = client->ctx_index;
desc.priority = client->priority;
desc.db_id = client->doorbell_id;
for (i = 0; i < I915_NUM_RINGS; i++) {
struct guc_execlist_context *lrc = &desc.lrc[i];
struct intel_ringbuffer *ringbuf = ctx->engine[i].ringbuf;
struct intel_engine_cs *ring;
struct drm_i915_gem_object *obj;
uint64_t ctx_desc;
obj = ctx->engine[i].state;
if (!obj)
break;
ring = ringbuf->ring;
ctx_desc = intel_lr_context_descriptor(ctx, ring);
lrc->context_desc = (u32)ctx_desc;
lrc->ring_lcra = i915_gem_obj_ggtt_offset(obj) +
LRC_STATE_PN * PAGE_SIZE;
lrc->context_id = (client->ctx_index << GUC_ELC_CTXID_OFFSET) |
(ring->id << GUC_ELC_ENGINE_OFFSET);
obj = ringbuf->obj;
lrc->ring_begin = i915_gem_obj_ggtt_offset(obj);
lrc->ring_end = lrc->ring_begin + obj->base.size - 1;
lrc->ring_next_free_location = lrc->ring_begin;
lrc->ring_current_tail_pointer_value = 0;
desc.engines_used |= (1 << ring->id);
}
WARN_ON(desc.engines_used == 0);
desc.db_trigger_cpu = 0;
desc.db_trigger_uk = client->doorbell_offset +
i915_gem_obj_ggtt_offset(client->client_obj);
desc.db_trigger_phy = client->doorbell_offset +
sg_dma_address(client->client_obj->pages->sgl);
desc.process_desc = client->proc_desc_offset +
i915_gem_obj_ggtt_offset(client->client_obj);
desc.wq_addr = client->wq_offset +
i915_gem_obj_ggtt_offset(client->client_obj);
desc.wq_size = client->wq_size;
desc.desc_private = (uintptr_t)client;
sg = guc->ctx_pool_obj->pages;
sg_pcopy_from_buffer(sg->sgl, sg->nents, &desc, sizeof(desc),
sizeof(desc) * client->ctx_index);
}
static void guc_fini_ctx_desc(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct guc_context_desc desc;
struct sg_table *sg;
memset(&desc, 0, sizeof(desc));
sg = guc->ctx_pool_obj->pages;
sg_pcopy_from_buffer(sg->sgl, sg->nents, &desc, sizeof(desc),
sizeof(desc) * client->ctx_index);
}
static int guc_get_workqueue_space(struct i915_guc_client *gc, u32 *offset)
{
struct guc_process_desc *desc;
void *base;
u32 size = sizeof(struct guc_wq_item);
int ret = -ETIMEDOUT, timeout_counter = 200;
base = kmap_atomic(i915_gem_object_get_page(gc->client_obj, 0));
desc = base + gc->proc_desc_offset;
while (timeout_counter-- > 0) {
if (CIRC_SPACE(gc->wq_tail, desc->head, gc->wq_size) >= size) {
*offset = gc->wq_tail;
gc->wq_tail += size;
gc->wq_tail &= gc->wq_size - 1;
timeout_counter = 0;
ret = 0;
}
if (timeout_counter)
usleep_range(1000, 2000);
};
kunmap_atomic(base);
return ret;
}
static int guc_add_workqueue_item(struct i915_guc_client *gc,
struct drm_i915_gem_request *rq)
{
enum intel_ring_id ring_id = rq->ring->id;
struct guc_wq_item *wqi;
void *base;
u32 tail, wq_len, wq_off = 0;
int ret;
ret = guc_get_workqueue_space(gc, &wq_off);
if (ret)
return ret;
WARN_ON(sizeof(struct guc_wq_item) != 16);
WARN_ON(wq_off & 3);
base = kmap_atomic(i915_gem_object_get_page(gc->client_obj,
(wq_off + GUC_DB_SIZE) >> PAGE_SHIFT));
wq_off &= PAGE_SIZE - 1;
wqi = (struct guc_wq_item *)((char *)base + wq_off);
wq_len = sizeof(struct guc_wq_item) / sizeof(u32) - 1;
wqi->header = WQ_TYPE_INORDER |
(wq_len << WQ_LEN_SHIFT) |
(ring_id << WQ_TARGET_SHIFT) |
WQ_NO_WCFLUSH_WAIT;
wqi->context_desc = (u32)intel_lr_context_descriptor(rq->ctx, rq->ring);
tail = rq->ringbuf->tail >> 3;
wqi->ring_tail = tail << WQ_RING_TAIL_SHIFT;
wqi->fence_id = 0;
kunmap_atomic(base);
return 0;
}
static void lr_context_update(struct drm_i915_gem_request *rq)
{
enum intel_ring_id ring_id = rq->ring->id;
struct drm_i915_gem_object *ctx_obj = rq->ctx->engine[ring_id].state;
struct drm_i915_gem_object *rb_obj = rq->ringbuf->obj;
struct page *page;
uint32_t *reg_state;
BUG_ON(!ctx_obj);
WARN_ON(!i915_gem_obj_is_pinned(ctx_obj));
WARN_ON(!i915_gem_obj_is_pinned(rb_obj));
page = i915_gem_object_get_dirty_page(ctx_obj, LRC_STATE_PN);
reg_state = kmap_atomic(page);
reg_state[CTX_RING_BUFFER_START+1] = i915_gem_obj_ggtt_offset(rb_obj);
kunmap_atomic(reg_state);
}
int i915_guc_submit(struct i915_guc_client *client,
struct drm_i915_gem_request *rq)
{
struct intel_guc *guc = client->guc;
enum intel_ring_id ring_id = rq->ring->id;
int q_ret, b_ret;
lr_context_update(rq);
q_ret = guc_add_workqueue_item(client, rq);
if (q_ret == 0)
b_ret = guc_ring_doorbell(client);
client->submissions[ring_id] += 1;
if (q_ret) {
client->q_fail += 1;
client->retcode = q_ret;
} else if (b_ret) {
client->b_fail += 1;
client->retcode = q_ret = b_ret;
} else {
client->retcode = 0;
}
guc->submissions[ring_id] += 1;
guc->last_seqno[ring_id] = rq->seqno;
return q_ret;
}
static struct drm_i915_gem_object *gem_allocate_guc_obj(struct drm_device *dev,
u32 size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
obj = i915_gem_alloc_object(dev, size);
if (!obj)
return NULL;
if (i915_gem_object_get_pages(obj)) {
drm_gem_object_unreference(&obj->base);
return NULL;
}
if (i915_gem_obj_ggtt_pin(obj, PAGE_SIZE,
PIN_OFFSET_BIAS | GUC_WOPCM_TOP)) {
drm_gem_object_unreference(&obj->base);
return NULL;
}
I915_WRITE(GEN8_GTCR, GEN8_GTCR_INVALIDATE);
return obj;
}
static void gem_release_guc_obj(struct drm_i915_gem_object *obj)
{
if (!obj)
return;
if (i915_gem_obj_is_pinned(obj))
i915_gem_object_ggtt_unpin(obj);
drm_gem_object_unreference(&obj->base);
}
static void guc_client_free(struct drm_device *dev,
struct i915_guc_client *client)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_guc *guc = &dev_priv->guc;
if (!client)
return;
if (client->doorbell_id != GUC_INVALID_DOORBELL_ID) {
guc_disable_doorbell(guc, client);
host2guc_release_doorbell(guc, client);
release_doorbell(guc, client->doorbell_id);
}
gem_release_guc_obj(client->client_obj);
if (client->ctx_index != GUC_INVALID_CTX_ID) {
guc_fini_ctx_desc(guc, client);
ida_simple_remove(&guc->ctx_ids, client->ctx_index);
}
kfree(client);
}
static struct i915_guc_client *guc_client_alloc(struct drm_device *dev,
uint32_t priority,
struct intel_context *ctx)
{
struct i915_guc_client *client;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_guc *guc = &dev_priv->guc;
struct drm_i915_gem_object *obj;
client = kzalloc(sizeof(*client), GFP_KERNEL);
if (!client)
return NULL;
client->doorbell_id = GUC_INVALID_DOORBELL_ID;
client->priority = priority;
client->owner = ctx;
client->guc = guc;
client->ctx_index = (uint32_t)ida_simple_get(&guc->ctx_ids, 0,
GUC_MAX_GPU_CONTEXTS, GFP_KERNEL);
if (client->ctx_index >= GUC_MAX_GPU_CONTEXTS) {
client->ctx_index = GUC_INVALID_CTX_ID;
goto err;
}
obj = gem_allocate_guc_obj(dev, GUC_DB_SIZE + GUC_WQ_SIZE);
if (!obj)
goto err;
client->client_obj = obj;
client->wq_offset = GUC_DB_SIZE;
client->wq_size = GUC_WQ_SIZE;
client->doorbell_offset = select_doorbell_cacheline(guc);
if (client->doorbell_offset >= (GUC_DB_SIZE / 2))
client->proc_desc_offset = 0;
else
client->proc_desc_offset = (GUC_DB_SIZE / 2);
client->doorbell_id = assign_doorbell(guc, client->priority);
if (client->doorbell_id == GUC_INVALID_DOORBELL_ID)
goto err;
guc_init_proc_desc(guc, client);
guc_init_ctx_desc(guc, client);
guc_init_doorbell(guc, client);
if (host2guc_allocate_doorbell(guc, client))
goto err;
DRM_DEBUG_DRIVER("new priority %u client %p: ctx_index %u db_id %u\n",
priority, client, client->ctx_index, client->doorbell_id);
return client;
err:
DRM_ERROR("FAILED to create priority %u GuC client!\n", priority);
guc_client_free(dev, client);
return NULL;
}
static void guc_create_log(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct drm_i915_gem_object *obj;
unsigned long offset;
uint32_t size, flags;
if (i915.guc_log_level < GUC_LOG_VERBOSITY_MIN)
return;
if (i915.guc_log_level > GUC_LOG_VERBOSITY_MAX)
i915.guc_log_level = GUC_LOG_VERBOSITY_MAX;
size = (1 + GUC_LOG_DPC_PAGES + 1 +
GUC_LOG_ISR_PAGES + 1 +
GUC_LOG_CRASH_PAGES + 1) << PAGE_SHIFT;
obj = guc->log_obj;
if (!obj) {
obj = gem_allocate_guc_obj(dev_priv->dev, size);
if (!obj) {
i915.guc_log_level = -1;
return;
}
guc->log_obj = obj;
}
flags = GUC_LOG_VALID | GUC_LOG_NOTIFY_ON_HALF_FULL |
(GUC_LOG_DPC_PAGES << GUC_LOG_DPC_SHIFT) |
(GUC_LOG_ISR_PAGES << GUC_LOG_ISR_SHIFT) |
(GUC_LOG_CRASH_PAGES << GUC_LOG_CRASH_SHIFT);
offset = i915_gem_obj_ggtt_offset(obj) >> PAGE_SHIFT;
guc->log_flags = (offset << GUC_LOG_BUF_ADDR_SHIFT) | flags;
}
int i915_guc_submission_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
const size_t ctxsize = sizeof(struct guc_context_desc);
const size_t poolsize = GUC_MAX_GPU_CONTEXTS * ctxsize;
const size_t gemsize = round_up(poolsize, PAGE_SIZE);
struct intel_guc *guc = &dev_priv->guc;
if (!i915.enable_guc_submission)
return 0;
if (guc->ctx_pool_obj)
return 0;
guc->ctx_pool_obj = gem_allocate_guc_obj(dev_priv->dev, gemsize);
if (!guc->ctx_pool_obj)
return -ENOMEM;
ida_init(&guc->ctx_ids);
guc_create_log(guc);
return 0;
}
int i915_guc_submission_enable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_guc *guc = &dev_priv->guc;
struct intel_context *ctx = dev_priv->ring[RCS].default_context;
struct i915_guc_client *client;
client = guc_client_alloc(dev, GUC_CTX_PRIORITY_KMD_NORMAL, ctx);
if (!client) {
DRM_ERROR("Failed to create execbuf guc_client\n");
return -ENOMEM;
}
guc->execbuf_client = client;
host2guc_sample_forcewake(guc, client);
return 0;
}
void i915_guc_submission_disable(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_guc *guc = &dev_priv->guc;
guc_client_free(dev, guc->execbuf_client);
guc->execbuf_client = NULL;
}
void i915_guc_submission_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_guc *guc = &dev_priv->guc;
gem_release_guc_obj(dev_priv->guc.log_obj);
guc->log_obj = NULL;
if (guc->ctx_pool_obj)
ida_destroy(&guc->ctx_ids);
gem_release_guc_obj(guc->ctx_pool_obj);
guc->ctx_pool_obj = NULL;
}
int intel_guc_suspend(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_guc *guc = &dev_priv->guc;
struct intel_context *ctx;
u32 data[3];
if (!i915.enable_guc_submission)
return 0;
ctx = dev_priv->ring[RCS].default_context;
data[0] = HOST2GUC_ACTION_ENTER_S_STATE;
data[1] = GUC_POWER_D1;
data[2] = i915_gem_obj_ggtt_offset(ctx->engine[RCS].state);
return host2guc_action(guc, data, ARRAY_SIZE(data));
}
int intel_guc_resume(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_guc *guc = &dev_priv->guc;
struct intel_context *ctx;
u32 data[3];
if (!i915.enable_guc_submission)
return 0;
ctx = dev_priv->ring[RCS].default_context;
data[0] = HOST2GUC_ACTION_EXIT_S_STATE;
data[1] = GUC_POWER_D0;
data[2] = i915_gem_obj_ggtt_offset(ctx->engine[RCS].state);
return host2guc_action(guc, data, ARRAY_SIZE(data));
}
