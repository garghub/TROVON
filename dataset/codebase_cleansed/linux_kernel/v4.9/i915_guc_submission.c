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
static int guc_update_doorbell_id(struct intel_guc *guc,
struct i915_guc_client *client,
u16 new_id)
{
struct sg_table *sg = guc->ctx_pool_vma->pages;
void *doorbell_bitmap = guc->doorbell_bitmap;
struct guc_doorbell_info *doorbell;
struct guc_context_desc desc;
size_t len;
doorbell = client->client_base + client->doorbell_offset;
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
desc = client->client_base + client->proc_desc_offset;
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
desc.db_trigger_cpu = (uintptr_t)client->client_base +
client->doorbell_offset;
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
struct guc_process_desc *desc = gc->client_base + gc->proc_desc_offset;
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
void *base;
u32 freespace, tail, wq_off, wq_page;
desc = gc->client_base + gc->proc_desc_offset;
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
wq_page = (wq_off + GUC_DB_SIZE) >> PAGE_SHIFT;
wq_off &= PAGE_SIZE - 1;
base = kmap_atomic(i915_gem_object_get_page(gc->vma->obj, wq_page));
wqi = (struct guc_wq_item *)((char *)base + wq_off);
wqi->header = WQ_TYPE_INORDER |
(wqi_len << WQ_LEN_SHIFT) |
(engine->guc_id << WQ_TARGET_SHIFT) |
WQ_NO_WCFLUSH_WAIT;
wqi->context_desc = (u32)intel_lr_context_descriptor(rq->ctx, engine);
wqi->ring_tail = tail << WQ_RING_TAIL_SHIFT;
wqi->fence_id = rq->fence.seqno;
kunmap_atomic(base);
}
static int guc_ring_doorbell(struct i915_guc_client *gc)
{
struct guc_process_desc *desc;
union guc_doorbell_qw db_cmp, db_exc, db_ret;
union guc_doorbell_qw *db;
int attempt = 2, ret = -EAGAIN;
desc = gc->client_base + gc->proc_desc_offset;
desc->tail = gc->wq_tail;
db_cmp.db_status = GUC_DOORBELL_ENABLED;
db_cmp.cookie = gc->cookie;
db_exc.db_status = GUC_DOORBELL_ENABLED;
db_exc.cookie = gc->cookie + 1;
if (db_exc.cookie == 0)
db_exc.cookie = 1;
db = gc->client_base + gc->doorbell_offset;
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
unsigned int engine_id = rq->engine->id;
struct intel_guc *guc = &rq->i915->guc;
struct i915_guc_client *client = guc->execbuf_client;
int b_ret;
spin_lock(&client->wq_lock);
guc_wq_item_append(client, rq);
b_ret = guc_ring_doorbell(client);
client->submissions[engine_id] += 1;
client->retcode = b_ret;
if (b_ret)
client->b_fail += 1;
guc->submissions[engine_id] += 1;
guc->last_seqno[engine_id] = rq->fence.seqno;
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
if (client->client_base) {
guc_disable_doorbell(guc, client);
kunmap(kmap_to_page(client->client_base));
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
client->client_base = kmap(i915_vma_first_page(vma));
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
static void guc_log_create(struct intel_guc *guc)
{
struct i915_vma *vma;
unsigned long offset;
uint32_t size, flags;
if (i915.guc_log_level < GUC_LOG_VERBOSITY_MIN)
return;
if (i915.guc_log_level > GUC_LOG_VERBOSITY_MAX)
i915.guc_log_level = GUC_LOG_VERBOSITY_MAX;
size = (1 + GUC_LOG_DPC_PAGES + 1 +
GUC_LOG_ISR_PAGES + 1 +
GUC_LOG_CRASH_PAGES + 1) << PAGE_SHIFT;
vma = guc->log_vma;
if (!vma) {
vma = guc_allocate_vma(guc, size);
if (IS_ERR(vma)) {
i915.guc_log_level = -1;
return;
}
guc->log_vma = vma;
}
flags = GUC_LOG_VALID | GUC_LOG_NOTIFY_ON_HALF_FULL |
(GUC_LOG_DPC_PAGES << GUC_LOG_DPC_SHIFT) |
(GUC_LOG_ISR_PAGES << GUC_LOG_ISR_SHIFT) |
(GUC_LOG_CRASH_PAGES << GUC_LOG_CRASH_SHIFT);
offset = i915_ggtt_offset(vma) >> PAGE_SHIFT;
guc->log_flags = (offset << GUC_LOG_BUF_ADDR_SHIFT) | flags;
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
engine = &dev_priv->engine[RCS];
ads->golden_context_lrca = engine->status_page.ggtt_offset;
for_each_engine(engine, dev_priv)
ads->eng_state_size[engine->guc_id] = intel_lr_context_size(engine);
policies = (void *)ads + sizeof(struct guc_ads);
guc_policies_init(policies);
ads->scheduler_policies =
i915_ggtt_offset(vma) + sizeof(struct guc_ads);
reg_state = (void *)policies + sizeof(struct guc_policies);
for_each_engine(engine, dev_priv) {
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
guc_log_create(guc);
guc_addon_create(guc);
return 0;
}
int i915_guc_submission_enable(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
struct i915_guc_client *client;
struct intel_engine_cs *engine;
struct drm_i915_gem_request *request;
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
for_each_engine(engine, dev_priv) {
engine->submit_request = i915_guc_submit;
list_for_each_entry(request, &engine->request_list, link) {
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
i915_vma_unpin_and_release(&guc->log_vma);
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
ctx = dev_priv->kernel_context;
data[0] = HOST2GUC_ACTION_EXIT_S_STATE;
data[1] = GUC_POWER_D0;
data[2] = i915_ggtt_offset(ctx->engine[RCS].state);
return host2guc_action(guc, data, ARRAY_SIZE(data));
}
