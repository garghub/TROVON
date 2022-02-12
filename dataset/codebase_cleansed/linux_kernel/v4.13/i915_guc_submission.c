static inline bool is_high_priority(struct i915_guc_client* client)
{
return client->priority <= GUC_CLIENT_PRIORITY_HIGH;
}
static int __reserve_doorbell(struct i915_guc_client *client)
{
unsigned long offset;
unsigned long end;
u16 id;
GEM_BUG_ON(client->doorbell_id != GUC_DOORBELL_INVALID);
offset = 0;
end = GUC_NUM_DOORBELLS/2;
if (is_high_priority(client)) {
offset = end;
end += offset;
}
id = find_next_zero_bit(client->guc->doorbell_bitmap, end, offset);
if (id == end)
return -ENOSPC;
__set_bit(id, client->guc->doorbell_bitmap);
client->doorbell_id = id;
DRM_DEBUG_DRIVER("client %u (high prio=%s) reserved doorbell: %d\n",
client->stage_id, yesno(is_high_priority(client)),
id);
return 0;
}
static void __unreserve_doorbell(struct i915_guc_client *client)
{
GEM_BUG_ON(client->doorbell_id == GUC_DOORBELL_INVALID);
__clear_bit(client->doorbell_id, client->guc->doorbell_bitmap);
client->doorbell_id = GUC_DOORBELL_INVALID;
}
static int __guc_allocate_doorbell(struct intel_guc *guc, u32 stage_id)
{
u32 action[] = {
INTEL_GUC_ACTION_ALLOCATE_DOORBELL,
stage_id
};
return intel_guc_send(guc, action, ARRAY_SIZE(action));
}
static int __guc_deallocate_doorbell(struct intel_guc *guc, u32 stage_id)
{
u32 action[] = {
INTEL_GUC_ACTION_DEALLOCATE_DOORBELL,
stage_id
};
return intel_guc_send(guc, action, ARRAY_SIZE(action));
}
static struct guc_stage_desc *__get_stage_desc(struct i915_guc_client *client)
{
struct guc_stage_desc *base = client->guc->stage_desc_pool_vaddr;
return &base[client->stage_id];
}
static void __update_doorbell_desc(struct i915_guc_client *client, u16 new_id)
{
struct guc_stage_desc *desc;
desc = __get_stage_desc(client);
desc->db_id = new_id;
}
static struct guc_doorbell_info *__get_doorbell(struct i915_guc_client *client)
{
return client->vaddr + client->doorbell_offset;
}
static bool has_doorbell(struct i915_guc_client *client)
{
if (client->doorbell_id == GUC_DOORBELL_INVALID)
return false;
return test_bit(client->doorbell_id, client->guc->doorbell_bitmap);
}
static int __create_doorbell(struct i915_guc_client *client)
{
struct guc_doorbell_info *doorbell;
int err;
doorbell = __get_doorbell(client);
doorbell->db_status = GUC_DOORBELL_ENABLED;
doorbell->cookie = client->doorbell_cookie;
err = __guc_allocate_doorbell(client->guc, client->stage_id);
if (err) {
doorbell->db_status = GUC_DOORBELL_DISABLED;
doorbell->cookie = 0;
}
return err;
}
static int __destroy_doorbell(struct i915_guc_client *client)
{
struct drm_i915_private *dev_priv = guc_to_i915(client->guc);
struct guc_doorbell_info *doorbell;
u16 db_id = client->doorbell_id;
GEM_BUG_ON(db_id >= GUC_DOORBELL_INVALID);
doorbell = __get_doorbell(client);
doorbell->db_status = GUC_DOORBELL_DISABLED;
doorbell->cookie = 0;
if (wait_for_us(!(I915_READ(GEN8_DRBREGL(db_id)) & GEN8_DRB_VALID), 10))
WARN_ONCE(true, "Doorbell never became invalid after disable\n");
return __guc_deallocate_doorbell(client->guc, client->stage_id);
}
static int create_doorbell(struct i915_guc_client *client)
{
int ret;
ret = __reserve_doorbell(client);
if (ret)
return ret;
__update_doorbell_desc(client, client->doorbell_id);
ret = __create_doorbell(client);
if (ret)
goto err;
return 0;
err:
__update_doorbell_desc(client, GUC_DOORBELL_INVALID);
__unreserve_doorbell(client);
return ret;
}
static int destroy_doorbell(struct i915_guc_client *client)
{
int err;
GEM_BUG_ON(!has_doorbell(client));
err = __destroy_doorbell(client);
if (err)
return err;
__update_doorbell_desc(client, GUC_DOORBELL_INVALID);
__unreserve_doorbell(client);
return 0;
}
static unsigned long __select_cacheline(struct intel_guc* guc)
{
unsigned long offset;
offset = offset_in_page(guc->db_cacheline);
guc->db_cacheline += cache_line_size();
DRM_DEBUG_DRIVER("reserved cacheline 0x%lx, next 0x%x, linesize %u\n",
offset, guc->db_cacheline, cache_line_size());
return offset;
}
static inline struct guc_process_desc *
__get_process_desc(struct i915_guc_client *client)
{
return client->vaddr + client->proc_desc_offset;
}
static void guc_proc_desc_init(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct guc_process_desc *desc;
desc = memset(__get_process_desc(client), 0, sizeof(*desc));
desc->wq_base_addr = 0;
desc->db_base_addr = 0;
desc->stage_id = client->stage_id;
desc->wq_size_bytes = client->wq_size;
desc->wq_status = WQ_STATUS_ACTIVE;
desc->priority = client->priority;
}
static void guc_stage_desc_init(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct intel_engine_cs *engine;
struct i915_gem_context *ctx = client->owner;
struct guc_stage_desc *desc;
unsigned int tmp;
u32 gfx_addr;
desc = __get_stage_desc(client);
memset(desc, 0, sizeof(*desc));
desc->attribute = GUC_STAGE_DESC_ATTR_ACTIVE | GUC_STAGE_DESC_ATTR_KERNEL;
desc->stage_id = client->stage_id;
desc->priority = client->priority;
desc->db_id = client->doorbell_id;
for_each_engine_masked(engine, dev_priv, client->engines, tmp) {
struct intel_context *ce = &ctx->engine[engine->id];
uint32_t guc_engine_id = engine->guc_id;
struct guc_execlist_context *lrc = &desc->lrc[guc_engine_id];
if (!ce->state)
break;
lrc->context_desc = lower_32_bits(ce->lrc_desc);
lrc->ring_lrca =
guc_ggtt_offset(ce->state) + LRC_STATE_PN * PAGE_SIZE;
lrc->context_id = (client->stage_id << GUC_ELC_CTXID_OFFSET) |
(guc_engine_id << GUC_ELC_ENGINE_OFFSET);
lrc->ring_begin = guc_ggtt_offset(ce->ring->vma);
lrc->ring_end = lrc->ring_begin + ce->ring->size - 1;
lrc->ring_next_free_location = lrc->ring_begin;
lrc->ring_current_tail_pointer_value = 0;
desc->engines_used |= (1 << guc_engine_id);
}
DRM_DEBUG_DRIVER("Host engines 0x%x => GuC engines used 0x%x\n",
client->engines, desc->engines_used);
WARN_ON(desc->engines_used == 0);
gfx_addr = guc_ggtt_offset(client->vma);
desc->db_trigger_phy = sg_dma_address(client->vma->pages->sgl) +
client->doorbell_offset;
desc->db_trigger_cpu = (uintptr_t)__get_doorbell(client);
desc->db_trigger_uk = gfx_addr + client->doorbell_offset;
desc->process_desc = gfx_addr + client->proc_desc_offset;
desc->wq_addr = gfx_addr + client->wq_offset;
desc->wq_size = client->wq_size;
desc->desc_private = (uintptr_t)client;
}
static void guc_stage_desc_fini(struct intel_guc *guc,
struct i915_guc_client *client)
{
struct guc_stage_desc *desc;
desc = __get_stage_desc(client);
memset(desc, 0, sizeof(*desc));
}
int i915_guc_wq_reserve(struct drm_i915_gem_request *request)
{
const size_t wqi_size = sizeof(struct guc_wq_item);
struct i915_guc_client *client = request->i915->guc.execbuf_client;
struct guc_process_desc *desc = __get_process_desc(client);
u32 freespace;
int ret;
spin_lock_irq(&client->wq_lock);
freespace = CIRC_SPACE(client->wq_tail, desc->head, client->wq_size);
freespace -= client->wq_rsvd;
if (likely(freespace >= wqi_size)) {
client->wq_rsvd += wqi_size;
ret = 0;
} else {
client->no_wq_space++;
ret = -EAGAIN;
}
spin_unlock_irq(&client->wq_lock);
return ret;
}
static void guc_client_update_wq_rsvd(struct i915_guc_client *client, int size)
{
unsigned long flags;
spin_lock_irqsave(&client->wq_lock, flags);
client->wq_rsvd += size;
spin_unlock_irqrestore(&client->wq_lock, flags);
}
void i915_guc_wq_unreserve(struct drm_i915_gem_request *request)
{
const int wqi_size = sizeof(struct guc_wq_item);
struct i915_guc_client *client = request->i915->guc.execbuf_client;
GEM_BUG_ON(READ_ONCE(client->wq_rsvd) < wqi_size);
guc_client_update_wq_rsvd(client, -wqi_size);
}
static void guc_wq_item_append(struct i915_guc_client *client,
struct drm_i915_gem_request *rq)
{
const size_t wqi_size = sizeof(struct guc_wq_item);
const u32 wqi_len = wqi_size/sizeof(u32) - 1;
struct intel_engine_cs *engine = rq->engine;
struct guc_process_desc *desc = __get_process_desc(client);
struct guc_wq_item *wqi;
u32 freespace, tail, wq_off;
freespace = CIRC_SPACE(client->wq_tail, desc->head, client->wq_size);
GEM_BUG_ON(freespace < wqi_size);
tail = intel_ring_set_tail(rq->ring, rq->tail) >> 3;
GEM_BUG_ON(tail > WQ_RING_TAIL_MAX);
BUILD_BUG_ON(wqi_size != 16);
GEM_BUG_ON(client->wq_rsvd < wqi_size);
wq_off = client->wq_tail;
GEM_BUG_ON(wq_off & (wqi_size - 1));
client->wq_tail += wqi_size;
client->wq_tail &= client->wq_size - 1;
client->wq_rsvd -= wqi_size;
wqi = client->vaddr + wq_off + GUC_DB_SIZE;
wqi->header = WQ_TYPE_INORDER |
(wqi_len << WQ_LEN_SHIFT) |
(engine->guc_id << WQ_TARGET_SHIFT) |
WQ_NO_WCFLUSH_WAIT;
wqi->context_desc = (u32)intel_lr_context_descriptor(rq->ctx, engine);
wqi->submit_element_info = tail << WQ_RING_TAIL_SHIFT;
wqi->fence_id = rq->global_seqno;
}
static void guc_reset_wq(struct i915_guc_client *client)
{
struct guc_process_desc *desc = __get_process_desc(client);
desc->head = 0;
desc->tail = 0;
client->wq_tail = 0;
}
static int guc_ring_doorbell(struct i915_guc_client *client)
{
struct guc_process_desc *desc = __get_process_desc(client);
union guc_doorbell_qw db_cmp, db_exc, db_ret;
union guc_doorbell_qw *db;
int attempt = 2, ret = -EAGAIN;
desc->tail = client->wq_tail;
db_cmp.db_status = GUC_DOORBELL_ENABLED;
db_cmp.cookie = client->doorbell_cookie;
db_exc.db_status = GUC_DOORBELL_ENABLED;
db_exc.cookie = client->doorbell_cookie + 1;
if (db_exc.cookie == 0)
db_exc.cookie = 1;
db = (union guc_doorbell_qw *)__get_doorbell(client);
while (attempt--) {
db_ret.value_qw = atomic64_cmpxchg((atomic64_t *)db,
db_cmp.value_qw, db_exc.value_qw);
if (db_ret.value_qw == db_cmp.value_qw) {
client->doorbell_cookie = db_exc.cookie;
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
static void __i915_guc_submit(struct drm_i915_gem_request *rq)
{
struct drm_i915_private *dev_priv = rq->i915;
struct intel_engine_cs *engine = rq->engine;
unsigned int engine_id = engine->id;
struct intel_guc *guc = &rq->i915->guc;
struct i915_guc_client *client = guc->execbuf_client;
unsigned long flags;
int b_ret;
if (i915_vma_is_map_and_fenceable(rq->ring->vma))
POSTING_READ_FW(GUC_STATUS);
spin_lock_irqsave(&client->wq_lock, flags);
guc_wq_item_append(client, rq);
b_ret = guc_ring_doorbell(client);
client->submissions[engine_id] += 1;
spin_unlock_irqrestore(&client->wq_lock, flags);
}
static void i915_guc_submit(struct drm_i915_gem_request *rq)
{
__i915_gem_request_submit(rq);
__i915_guc_submit(rq);
}
static void nested_enable_signaling(struct drm_i915_gem_request *rq)
{
if (test_and_set_bit(DMA_FENCE_FLAG_ENABLE_SIGNAL_BIT,
&rq->fence.flags))
return;
GEM_BUG_ON(test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &rq->fence.flags));
trace_dma_fence_enable_signal(&rq->fence);
spin_lock_nested(&rq->lock, SINGLE_DEPTH_NESTING);
intel_engine_enable_signaling(rq, true);
spin_unlock(&rq->lock);
}
static void port_assign(struct execlist_port *port,
struct drm_i915_gem_request *rq)
{
GEM_BUG_ON(rq == port_request(port));
if (port_isset(port))
i915_gem_request_put(port_request(port));
port_set(port, i915_gem_request_get(rq));
nested_enable_signaling(rq);
}
static bool i915_guc_dequeue(struct intel_engine_cs *engine)
{
struct execlist_port *port = engine->execlist_port;
struct drm_i915_gem_request *last = port_request(port);
struct rb_node *rb;
bool submit = false;
spin_lock_irq(&engine->timeline->lock);
rb = engine->execlist_first;
GEM_BUG_ON(rb_first(&engine->execlist_queue) != rb);
while (rb) {
struct i915_priolist *p = rb_entry(rb, typeof(*p), node);
struct drm_i915_gem_request *rq, *rn;
list_for_each_entry_safe(rq, rn, &p->requests, priotree.link) {
if (last && rq->ctx != last->ctx) {
if (port != engine->execlist_port) {
__list_del_many(&p->requests,
&rq->priotree.link);
goto done;
}
if (submit)
port_assign(port, last);
port++;
}
INIT_LIST_HEAD(&rq->priotree.link);
rq->priotree.priority = INT_MAX;
i915_guc_submit(rq);
trace_i915_gem_request_in(rq, port_index(port, engine));
last = rq;
submit = true;
}
rb = rb_next(rb);
rb_erase(&p->node, &engine->execlist_queue);
INIT_LIST_HEAD(&p->requests);
if (p->priority != I915_PRIORITY_NORMAL)
kmem_cache_free(engine->i915->priorities, p);
}
done:
engine->execlist_first = rb;
if (submit)
port_assign(port, last);
spin_unlock_irq(&engine->timeline->lock);
return submit;
}
static void i915_guc_irq_handler(unsigned long data)
{
struct intel_engine_cs *engine = (struct intel_engine_cs *)data;
struct execlist_port *port = engine->execlist_port;
struct drm_i915_gem_request *rq;
bool submit;
do {
rq = port_request(&port[0]);
while (rq && i915_gem_request_completed(rq)) {
trace_i915_gem_request_out(rq);
i915_gem_request_put(rq);
port[0] = port[1];
memset(&port[1], 0, sizeof(port[1]));
rq = port_request(&port[0]);
}
submit = false;
if (!port_count(&port[1]))
submit = i915_guc_dequeue(engine);
} while (submit);
}
struct i915_vma *intel_guc_allocate_vma(struct intel_guc *guc, u32 size)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct drm_i915_gem_object *obj;
struct i915_vma *vma;
int ret;
obj = i915_gem_object_create(dev_priv, size);
if (IS_ERR(obj))
return ERR_CAST(obj);
vma = i915_vma_instance(obj, &dev_priv->ggtt.base, NULL);
if (IS_ERR(vma))
goto err;
ret = i915_vma_pin(vma, 0, PAGE_SIZE,
PIN_GLOBAL | PIN_OFFSET_BIAS | GUC_WOPCM_TOP);
if (ret) {
vma = ERR_PTR(ret);
goto err;
}
return vma;
err:
i915_gem_object_put(obj);
return vma;
}
static bool doorbell_ok(struct intel_guc *guc, u16 db_id)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
u32 drbregl;
bool valid;
GEM_BUG_ON(db_id >= GUC_DOORBELL_INVALID);
drbregl = I915_READ(GEN8_DRBREGL(db_id));
valid = drbregl & GEN8_DRB_VALID;
if (test_bit(db_id, guc->doorbell_bitmap) == valid)
return true;
DRM_DEBUG_DRIVER("Doorbell %d has unexpected state (0x%x): valid=%s\n",
db_id, drbregl, yesno(valid));
return false;
}
static int __reset_doorbell(struct i915_guc_client* client, u16 db_id)
{
int err;
__update_doorbell_desc(client, db_id);
err = __create_doorbell(client);
if (!err)
err = __destroy_doorbell(client);
return err;
}
static int guc_init_doorbell_hw(struct intel_guc *guc)
{
struct i915_guc_client *client = guc->execbuf_client;
bool recreate_first_client = false;
u16 db_id;
int ret;
for_each_clear_bit(db_id, guc->doorbell_bitmap, GUC_NUM_DOORBELLS) {
if (doorbell_ok(guc, db_id))
continue;
if (has_doorbell(client)) {
destroy_doorbell(client);
recreate_first_client = true;
}
ret = __reset_doorbell(client, db_id);
WARN(ret, "Doorbell %u reset failed, err %d\n", db_id, ret);
}
if (recreate_first_client) {
ret = __reserve_doorbell(client);
if (unlikely(ret)) {
DRM_ERROR("Couldn't re-reserve first client db: %d\n", ret);
return ret;
}
__update_doorbell_desc(client, client->doorbell_id);
}
{
ret = __create_doorbell(client);
if (ret) {
DRM_ERROR("Couldn't recreate client %u doorbell: %d\n",
client->stage_id, ret);
return ret;
}
}
for (db_id = 0; db_id < GUC_NUM_DOORBELLS; ++db_id)
WARN_ON(!doorbell_ok(guc, db_id));
return 0;
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
int ret;
client = kzalloc(sizeof(*client), GFP_KERNEL);
if (!client)
return ERR_PTR(-ENOMEM);
client->guc = guc;
client->owner = ctx;
client->engines = engines;
client->priority = priority;
client->doorbell_id = GUC_DOORBELL_INVALID;
client->wq_offset = GUC_DB_SIZE;
client->wq_size = GUC_WQ_SIZE;
spin_lock_init(&client->wq_lock);
ret = ida_simple_get(&guc->stage_ids, 0, GUC_MAX_STAGE_DESCRIPTORS,
GFP_KERNEL);
if (ret < 0)
goto err_client;
client->stage_id = ret;
vma = intel_guc_allocate_vma(guc, GUC_DB_SIZE + GUC_WQ_SIZE);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto err_id;
}
client->vma = vma;
vaddr = i915_gem_object_pin_map(vma->obj, I915_MAP_WB);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
goto err_vma;
}
client->vaddr = vaddr;
client->doorbell_offset = __select_cacheline(guc);
if (client->doorbell_offset >= (GUC_DB_SIZE / 2))
client->proc_desc_offset = 0;
else
client->proc_desc_offset = (GUC_DB_SIZE / 2);
guc_proc_desc_init(guc, client);
guc_stage_desc_init(guc, client);
ret = create_doorbell(client);
if (ret)
goto err_vaddr;
DRM_DEBUG_DRIVER("new priority %u client %p for engine(s) 0x%x: stage_id %u\n",
priority, client, client->engines, client->stage_id);
DRM_DEBUG_DRIVER("doorbell id %u, cacheline offset 0x%lx\n",
client->doorbell_id, client->doorbell_offset);
return client;
err_vaddr:
i915_gem_object_unpin_map(client->vma->obj);
err_vma:
i915_vma_unpin_and_release(&client->vma);
err_id:
ida_simple_remove(&guc->stage_ids, client->stage_id);
err_client:
kfree(client);
return ERR_PTR(ret);
}
static void guc_client_free(struct i915_guc_client *client)
{
destroy_doorbell(client);
guc_stage_desc_fini(client->guc, client);
i915_gem_object_unpin_map(client->vma->obj);
i915_vma_unpin_and_release(&client->vma);
ida_simple_remove(&client->guc->stage_ids, client->stage_id);
kfree(client);
}
static void guc_policies_init(struct guc_policies *policies)
{
struct guc_policy *policy;
u32 p, i;
policies->dpc_promote_time = 500000;
policies->max_num_work_items = POLICY_MAX_NUM_WI;
for (p = 0; p < GUC_CLIENT_PRIORITY_NUM; p++) {
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
static int guc_ads_create(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct i915_vma *vma;
struct page *page;
struct {
struct guc_ads ads;
struct guc_policies policies;
struct guc_mmio_reg_state reg_state;
u8 reg_state_buffer[GUC_S3_SAVE_SPACE_PAGES * PAGE_SIZE];
} __packed *blob;
struct intel_engine_cs *engine;
enum intel_engine_id id;
u32 base;
GEM_BUG_ON(guc->ads_vma);
vma = intel_guc_allocate_vma(guc, PAGE_ALIGN(sizeof(*blob)));
if (IS_ERR(vma))
return PTR_ERR(vma);
guc->ads_vma = vma;
page = i915_vma_first_page(vma);
blob = kmap(page);
guc_policies_init(&blob->policies);
for_each_engine(engine, dev_priv, id) {
blob->reg_state.white_list[engine->guc_id].mmio_start =
engine->mmio_base + GUC_MMIO_WHITE_LIST_START;
blob->reg_state.white_list[engine->guc_id].count = 0;
}
blob->ads.golden_context_lrca =
dev_priv->engine[RCS]->status_page.ggtt_offset;
for_each_engine(engine, dev_priv, id)
blob->ads.eng_state_size[engine->guc_id] = engine->context_size;
base = guc_ggtt_offset(vma);
blob->ads.scheduler_policies = base + ptr_offset(blob, policies);
blob->ads.reg_state_buffer = base + ptr_offset(blob, reg_state_buffer);
blob->ads.reg_state_addr = base + ptr_offset(blob, reg_state);
kunmap(page);
return 0;
}
static void guc_ads_destroy(struct intel_guc *guc)
{
i915_vma_unpin_and_release(&guc->ads_vma);
}
int i915_guc_submission_init(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
struct i915_vma *vma;
void *vaddr;
int ret;
if (guc->stage_desc_pool)
return 0;
vma = intel_guc_allocate_vma(guc,
PAGE_ALIGN(sizeof(struct guc_stage_desc) *
GUC_MAX_STAGE_DESCRIPTORS));
if (IS_ERR(vma))
return PTR_ERR(vma);
guc->stage_desc_pool = vma;
vaddr = i915_gem_object_pin_map(guc->stage_desc_pool->obj, I915_MAP_WB);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
goto err_vma;
}
guc->stage_desc_pool_vaddr = vaddr;
ret = intel_guc_log_create(guc);
if (ret < 0)
goto err_vaddr;
ret = guc_ads_create(guc);
if (ret < 0)
goto err_log;
ida_init(&guc->stage_ids);
return 0;
err_log:
intel_guc_log_destroy(guc);
err_vaddr:
i915_gem_object_unpin_map(guc->stage_desc_pool->obj);
err_vma:
i915_vma_unpin_and_release(&guc->stage_desc_pool);
return ret;
}
void i915_guc_submission_fini(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
ida_destroy(&guc->stage_ids);
guc_ads_destroy(guc);
intel_guc_log_destroy(guc);
i915_gem_object_unpin_map(guc->stage_desc_pool->obj);
i915_vma_unpin_and_release(&guc->stage_desc_pool);
}
static void guc_interrupts_capture(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
int irqs;
irqs = _MASKED_BIT_ENABLE(GFX_INTERRUPT_STEERING);
for_each_engine(engine, dev_priv, id)
I915_WRITE(RING_MODE_GEN7(engine), irqs);
irqs = GT_RENDER_USER_INTERRUPT << GEN8_RCS_IRQ_SHIFT |
GT_RENDER_USER_INTERRUPT << GEN8_BCS_IRQ_SHIFT;
I915_WRITE(GUC_BCS_RCS_IER, ~irqs);
I915_WRITE(GUC_VCS2_VCS1_IER, ~irqs);
I915_WRITE(GUC_WD_VECS_IER, ~irqs);
dev_priv->rps.pm_intrmsk_mbz |= ARAT_EXPIRED_INTRMSK;
dev_priv->rps.pm_intrmsk_mbz &= ~GEN8_PMINTR_DISABLE_REDIRECT_TO_GUC;
}
static void guc_interrupts_release(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
int irqs;
irqs = _MASKED_FIELD(GFX_FORWARD_VBLANK_MASK, GFX_FORWARD_VBLANK_NEVER);
irqs |= _MASKED_BIT_DISABLE(GFX_INTERRUPT_STEERING);
for_each_engine(engine, dev_priv, id)
I915_WRITE(RING_MODE_GEN7(engine), irqs);
I915_WRITE(GUC_BCS_RCS_IER, 0);
I915_WRITE(GUC_VCS2_VCS1_IER, 0);
I915_WRITE(GUC_WD_VECS_IER, 0);
dev_priv->rps.pm_intrmsk_mbz |= GEN8_PMINTR_DISABLE_REDIRECT_TO_GUC;
dev_priv->rps.pm_intrmsk_mbz &= ~ARAT_EXPIRED_INTRMSK;
}
int i915_guc_submission_enable(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
struct i915_guc_client *client = guc->execbuf_client;
struct intel_engine_cs *engine;
enum intel_engine_id id;
int err;
if (!client) {
client = guc_client_alloc(dev_priv,
INTEL_INFO(dev_priv)->ring_mask,
GUC_CLIENT_PRIORITY_KMD_NORMAL,
dev_priv->kernel_context);
if (IS_ERR(client)) {
DRM_ERROR("Failed to create GuC client for execbuf!\n");
return PTR_ERR(client);
}
guc->execbuf_client = client;
}
err = intel_guc_sample_forcewake(guc);
if (err)
goto err_execbuf_client;
guc_reset_wq(client);
err = guc_init_doorbell_hw(guc);
if (err)
goto err_execbuf_client;
guc_interrupts_capture(dev_priv);
for_each_engine(engine, dev_priv, id) {
const int wqi_size = sizeof(struct guc_wq_item);
struct drm_i915_gem_request *rq;
engine->irq_tasklet.func = i915_guc_irq_handler;
clear_bit(ENGINE_IRQ_EXECLIST, &engine->irq_posted);
spin_lock_irq(&engine->timeline->lock);
list_for_each_entry(rq, &engine->timeline->requests, link) {
guc_client_update_wq_rsvd(client, wqi_size);
__i915_guc_submit(rq);
}
spin_unlock_irq(&engine->timeline->lock);
}
return 0;
err_execbuf_client:
guc_client_free(guc->execbuf_client);
guc->execbuf_client = NULL;
return err;
}
void i915_guc_submission_disable(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
guc_interrupts_release(dev_priv);
intel_engines_reset_default_submission(dev_priv);
guc_client_free(guc->execbuf_client);
guc->execbuf_client = NULL;
}
int intel_guc_suspend(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
struct i915_gem_context *ctx;
u32 data[3];
if (guc->fw.load_status != INTEL_UC_FIRMWARE_SUCCESS)
return 0;
gen9_disable_guc_interrupts(dev_priv);
ctx = dev_priv->kernel_context;
data[0] = INTEL_GUC_ACTION_ENTER_S_STATE;
data[1] = GUC_POWER_D1;
data[2] = guc_ggtt_offset(ctx->engine[RCS].state);
return intel_guc_send(guc, data, ARRAY_SIZE(data));
}
int intel_guc_resume(struct drm_i915_private *dev_priv)
{
struct intel_guc *guc = &dev_priv->guc;
struct i915_gem_context *ctx;
u32 data[3];
if (guc->fw.load_status != INTEL_UC_FIRMWARE_SUCCESS)
return 0;
if (i915.guc_log_level >= 0)
gen9_enable_guc_interrupts(dev_priv);
ctx = dev_priv->kernel_context;
data[0] = INTEL_GUC_ACTION_EXIT_S_STATE;
data[1] = GUC_POWER_D0;
data[2] = guc_ggtt_offset(ctx->engine[RCS].state);
return intel_guc_send(guc, data, ARRAY_SIZE(data));
}
