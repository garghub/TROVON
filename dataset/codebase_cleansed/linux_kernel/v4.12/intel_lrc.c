int intel_sanitize_enable_execlists(struct drm_i915_private *dev_priv, int enable_execlists)
{
if (HAS_LOGICAL_RING_CONTEXTS(dev_priv) && intel_vgpu_active(dev_priv))
return 1;
if (INTEL_GEN(dev_priv) >= 9)
return 1;
if (enable_execlists == 0)
return 0;
if (HAS_LOGICAL_RING_CONTEXTS(dev_priv) &&
USES_PPGTT(dev_priv) &&
i915.use_mmio_flip >= 0)
return 1;
return 0;
}
static void
intel_lr_context_descriptor_update(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
struct intel_context *ce = &ctx->engine[engine->id];
u64 desc;
BUILD_BUG_ON(MAX_CONTEXT_HW_ID > (1<<GEN8_CTX_ID_WIDTH));
desc = ctx->desc_template;
desc |= i915_ggtt_offset(ce->state) + LRC_PPHWSP_PN * PAGE_SIZE;
desc |= (u64)ctx->hw_id << GEN8_CTX_ID_SHIFT;
ce->lrc_desc = desc;
}
uint64_t intel_lr_context_descriptor(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
return ctx->engine[engine->id].lrc_desc;
}
static inline void
execlists_context_status_change(struct drm_i915_gem_request *rq,
unsigned long status)
{
if (!IS_ENABLED(CONFIG_DRM_I915_GVT))
return;
atomic_notifier_call_chain(&rq->engine->context_status_notifier,
status, rq);
}
static void
execlists_update_context_pdps(struct i915_hw_ppgtt *ppgtt, u32 *reg_state)
{
ASSIGN_CTX_PDP(ppgtt, reg_state, 3);
ASSIGN_CTX_PDP(ppgtt, reg_state, 2);
ASSIGN_CTX_PDP(ppgtt, reg_state, 1);
ASSIGN_CTX_PDP(ppgtt, reg_state, 0);
}
static u64 execlists_update_context(struct drm_i915_gem_request *rq)
{
struct intel_context *ce = &rq->ctx->engine[rq->engine->id];
struct i915_hw_ppgtt *ppgtt =
rq->ctx->ppgtt ?: rq->i915->mm.aliasing_ppgtt;
u32 *reg_state = ce->lrc_reg_state;
reg_state[CTX_RING_TAIL+1] = intel_ring_set_tail(rq->ring, rq->tail);
if (ppgtt && !i915_vm_is_48bit(&ppgtt->base))
execlists_update_context_pdps(ppgtt, reg_state);
return ce->lrc_desc;
}
static void execlists_submit_ports(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
struct execlist_port *port = engine->execlist_port;
u32 __iomem *elsp =
dev_priv->regs + i915_mmio_reg_offset(RING_ELSP(engine));
u64 desc[2];
GEM_BUG_ON(port[0].count > 1);
if (!port[0].count)
execlists_context_status_change(port[0].request,
INTEL_CONTEXT_SCHEDULE_IN);
desc[0] = execlists_update_context(port[0].request);
GEM_DEBUG_EXEC(port[0].context_id = upper_32_bits(desc[0]));
port[0].count++;
if (port[1].request) {
GEM_BUG_ON(port[1].count);
execlists_context_status_change(port[1].request,
INTEL_CONTEXT_SCHEDULE_IN);
desc[1] = execlists_update_context(port[1].request);
GEM_DEBUG_EXEC(port[1].context_id = upper_32_bits(desc[1]));
port[1].count = 1;
} else {
desc[1] = 0;
}
GEM_BUG_ON(desc[0] == desc[1]);
writel(upper_32_bits(desc[1]), elsp);
writel(lower_32_bits(desc[1]), elsp);
writel(upper_32_bits(desc[0]), elsp);
writel(lower_32_bits(desc[0]), elsp);
}
static bool ctx_single_port_submission(const struct i915_gem_context *ctx)
{
return (IS_ENABLED(CONFIG_DRM_I915_GVT) &&
i915_gem_context_force_single_submission(ctx));
}
static bool can_merge_ctx(const struct i915_gem_context *prev,
const struct i915_gem_context *next)
{
if (prev != next)
return false;
if (ctx_single_port_submission(prev))
return false;
return true;
}
static void execlists_dequeue(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *last;
struct execlist_port *port = engine->execlist_port;
struct rb_node *rb;
bool submit = false;
last = port->request;
if (last)
last->tail = last->wa_tail;
GEM_BUG_ON(port[1].request);
spin_lock_irq(&engine->timeline->lock);
rb = engine->execlist_first;
while (rb) {
struct drm_i915_gem_request *cursor =
rb_entry(rb, typeof(*cursor), priotree.node);
if (last && !can_merge_ctx(cursor->ctx, last->ctx)) {
if (port != engine->execlist_port)
break;
if (ctx_single_port_submission(last->ctx) ||
ctx_single_port_submission(cursor->ctx))
break;
GEM_BUG_ON(last->ctx == cursor->ctx);
i915_gem_request_assign(&port->request, last);
port++;
}
rb = rb_next(rb);
rb_erase(&cursor->priotree.node, &engine->execlist_queue);
RB_CLEAR_NODE(&cursor->priotree.node);
cursor->priotree.priority = INT_MAX;
__i915_gem_request_submit(cursor);
trace_i915_gem_request_in(cursor, port - engine->execlist_port);
last = cursor;
submit = true;
}
if (submit) {
i915_gem_request_assign(&port->request, last);
engine->execlist_first = rb;
}
spin_unlock_irq(&engine->timeline->lock);
if (submit)
execlists_submit_ports(engine);
}
static bool execlists_elsp_idle(struct intel_engine_cs *engine)
{
return !engine->execlist_port[0].request;
}
static bool execlists_elsp_ready(const struct intel_engine_cs *engine)
{
const struct execlist_port *port = engine->execlist_port;
return port[0].count + port[1].count < 2;
}
static void intel_lrc_irq_handler(unsigned long data)
{
struct intel_engine_cs *engine = (struct intel_engine_cs *)data;
struct execlist_port *port = engine->execlist_port;
struct drm_i915_private *dev_priv = engine->i915;
intel_uncore_forcewake_get(dev_priv, engine->fw_domains);
while (test_bit(ENGINE_IRQ_EXECLIST, &engine->irq_posted)) {
u32 __iomem *csb_mmio =
dev_priv->regs + i915_mmio_reg_offset(RING_CONTEXT_STATUS_PTR(engine));
u32 __iomem *buf =
dev_priv->regs + i915_mmio_reg_offset(RING_CONTEXT_STATUS_BUF_LO(engine, 0));
unsigned int head, tail;
__clear_bit(ENGINE_IRQ_EXECLIST, &engine->irq_posted);
head = readl(csb_mmio);
tail = GEN8_CSB_WRITE_PTR(head);
head = GEN8_CSB_READ_PTR(head);
while (head != tail) {
unsigned int status;
if (++head == GEN8_CSB_ENTRIES)
head = 0;
status = readl(buf + 2 * head);
if (!(status & GEN8_CTX_STATUS_COMPLETED_MASK))
continue;
GEM_DEBUG_BUG_ON(readl(buf + 2 * head + 1) !=
port[0].context_id);
GEM_BUG_ON(port[0].count == 0);
if (--port[0].count == 0) {
GEM_BUG_ON(status & GEN8_CTX_STATUS_PREEMPTED);
GEM_BUG_ON(!i915_gem_request_completed(port[0].request));
execlists_context_status_change(port[0].request,
INTEL_CONTEXT_SCHEDULE_OUT);
trace_i915_gem_request_out(port[0].request);
i915_gem_request_put(port[0].request);
port[0] = port[1];
memset(&port[1], 0, sizeof(port[1]));
}
GEM_BUG_ON(port[0].count == 0 &&
!(status & GEN8_CTX_STATUS_ACTIVE_IDLE));
}
writel(_MASKED_FIELD(GEN8_CSB_READ_PTR_MASK, head << 8),
csb_mmio);
}
if (execlists_elsp_ready(engine))
execlists_dequeue(engine);
intel_uncore_forcewake_put(dev_priv, engine->fw_domains);
}
static bool insert_request(struct i915_priotree *pt, struct rb_root *root)
{
struct rb_node **p, *rb;
bool first = true;
rb = NULL;
p = &root->rb_node;
while (*p) {
struct i915_priotree *pos;
rb = *p;
pos = rb_entry(rb, typeof(*pos), node);
if (pt->priority > pos->priority) {
p = &rb->rb_left;
} else {
p = &rb->rb_right;
first = false;
}
}
rb_link_node(&pt->node, rb, p);
rb_insert_color(&pt->node, root);
return first;
}
static void execlists_submit_request(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
unsigned long flags;
spin_lock_irqsave(&engine->timeline->lock, flags);
if (insert_request(&request->priotree, &engine->execlist_queue)) {
engine->execlist_first = &request->priotree.node;
if (execlists_elsp_ready(engine))
tasklet_hi_schedule(&engine->irq_tasklet);
}
spin_unlock_irqrestore(&engine->timeline->lock, flags);
}
static struct intel_engine_cs *
pt_lock_engine(struct i915_priotree *pt, struct intel_engine_cs *locked)
{
struct intel_engine_cs *engine =
container_of(pt, struct drm_i915_gem_request, priotree)->engine;
GEM_BUG_ON(!locked);
if (engine != locked) {
spin_unlock(&locked->timeline->lock);
spin_lock(&engine->timeline->lock);
}
return engine;
}
static void execlists_schedule(struct drm_i915_gem_request *request, int prio)
{
struct intel_engine_cs *engine;
struct i915_dependency *dep, *p;
struct i915_dependency stack;
LIST_HEAD(dfs);
if (prio <= READ_ONCE(request->priotree.priority))
return;
lockdep_assert_held(&request->i915->drm.struct_mutex);
stack.signaler = &request->priotree;
list_add(&stack.dfs_link, &dfs);
list_for_each_entry_safe(dep, p, &dfs, dfs_link) {
struct i915_priotree *pt = dep->signaler;
list_for_each_entry(p, &pt->signalers_list, signal_link) {
GEM_BUG_ON(p->signaler->priority < pt->priority);
if (prio > READ_ONCE(p->signaler->priority))
list_move_tail(&p->dfs_link, &dfs);
}
list_safe_reset_next(dep, p, dfs_link);
}
engine = request->engine;
spin_lock_irq(&engine->timeline->lock);
list_for_each_entry_safe_reverse(dep, p, &dfs, dfs_link) {
struct i915_priotree *pt = dep->signaler;
INIT_LIST_HEAD(&dep->dfs_link);
engine = pt_lock_engine(pt, engine);
if (prio <= pt->priority)
continue;
pt->priority = prio;
if (!RB_EMPTY_NODE(&pt->node)) {
rb_erase(&pt->node, &engine->execlist_queue);
if (insert_request(pt, &engine->execlist_queue))
engine->execlist_first = &pt->node;
}
}
spin_unlock_irq(&engine->timeline->lock);
}
static int execlists_context_pin(struct intel_engine_cs *engine,
struct i915_gem_context *ctx)
{
struct intel_context *ce = &ctx->engine[engine->id];
unsigned int flags;
void *vaddr;
int ret;
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
if (ce->pin_count++)
return 0;
GEM_BUG_ON(!ce->pin_count);
if (!ce->state) {
ret = execlists_context_deferred_alloc(ctx, engine);
if (ret)
goto err;
}
GEM_BUG_ON(!ce->state);
flags = PIN_GLOBAL | PIN_HIGH;
if (ctx->ggtt_offset_bias)
flags |= PIN_OFFSET_BIAS | ctx->ggtt_offset_bias;
ret = i915_vma_pin(ce->state, 0, GEN8_LR_CONTEXT_ALIGN, flags);
if (ret)
goto err;
vaddr = i915_gem_object_pin_map(ce->state->obj, I915_MAP_WB);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
goto unpin_vma;
}
ret = intel_ring_pin(ce->ring, ctx->ggtt_offset_bias);
if (ret)
goto unpin_map;
intel_lr_context_descriptor_update(ctx, engine);
ce->lrc_reg_state = vaddr + LRC_STATE_PN * PAGE_SIZE;
ce->lrc_reg_state[CTX_RING_BUFFER_START+1] =
i915_ggtt_offset(ce->ring->vma);
ce->state->obj->mm.dirty = true;
i915_gem_context_get(ctx);
return 0;
unpin_map:
i915_gem_object_unpin_map(ce->state->obj);
unpin_vma:
__i915_vma_unpin(ce->state);
err:
ce->pin_count = 0;
return ret;
}
static void execlists_context_unpin(struct intel_engine_cs *engine,
struct i915_gem_context *ctx)
{
struct intel_context *ce = &ctx->engine[engine->id];
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
GEM_BUG_ON(ce->pin_count == 0);
if (--ce->pin_count)
return;
intel_ring_unpin(ce->ring);
i915_gem_object_unpin_map(ce->state->obj);
i915_vma_unpin(ce->state);
i915_gem_context_put(ctx);
}
static int execlists_request_alloc(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
struct intel_context *ce = &request->ctx->engine[engine->id];
u32 *cs;
int ret;
GEM_BUG_ON(!ce->pin_count);
request->reserved_space += EXECLISTS_REQUEST_SIZE;
GEM_BUG_ON(!ce->ring);
request->ring = ce->ring;
if (i915.enable_guc_submission) {
ret = i915_guc_wq_reserve(request);
if (ret)
goto err;
}
cs = intel_ring_begin(request, 0);
if (IS_ERR(cs)) {
ret = PTR_ERR(cs);
goto err_unreserve;
}
if (!ce->initialised) {
ret = engine->init_context(request);
if (ret)
goto err_unreserve;
ce->initialised = true;
}
request->reserved_space -= EXECLISTS_REQUEST_SIZE;
return 0;
err_unreserve:
if (i915.enable_guc_submission)
i915_guc_wq_unreserve(request);
err:
return ret;
}
static u32 *
gen8_emit_flush_coherentl3_wa(struct intel_engine_cs *engine, u32 *batch)
{
*batch++ = MI_STORE_REGISTER_MEM_GEN8 | MI_SRM_LRM_GLOBAL_GTT;
*batch++ = i915_mmio_reg_offset(GEN8_L3SQCREG4);
*batch++ = i915_ggtt_offset(engine->scratch) + 256;
*batch++ = 0;
*batch++ = MI_LOAD_REGISTER_IMM(1);
*batch++ = i915_mmio_reg_offset(GEN8_L3SQCREG4);
*batch++ = 0x40400000 | GEN8_LQSC_FLUSH_COHERENT_LINES;
batch = gen8_emit_pipe_control(batch,
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_DC_FLUSH_ENABLE,
0);
*batch++ = MI_LOAD_REGISTER_MEM_GEN8 | MI_SRM_LRM_GLOBAL_GTT;
*batch++ = i915_mmio_reg_offset(GEN8_L3SQCREG4);
*batch++ = i915_ggtt_offset(engine->scratch) + 256;
*batch++ = 0;
return batch;
}
static u32 *gen8_init_indirectctx_bb(struct intel_engine_cs *engine, u32 *batch)
{
*batch++ = MI_ARB_ON_OFF | MI_ARB_DISABLE;
if (IS_BROADWELL(engine->i915))
batch = gen8_emit_flush_coherentl3_wa(engine, batch);
batch = gen8_emit_pipe_control(batch,
PIPE_CONTROL_FLUSH_L3 |
PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE,
i915_ggtt_offset(engine->scratch) +
2 * CACHELINE_BYTES);
while ((unsigned long)batch % CACHELINE_BYTES)
*batch++ = MI_NOOP;
return batch;
}
static u32 *gen8_init_perctx_bb(struct intel_engine_cs *engine, u32 *batch)
{
*batch++ = MI_ARB_ON_OFF | MI_ARB_ENABLE;
*batch++ = MI_BATCH_BUFFER_END;
return batch;
}
static u32 *gen9_init_indirectctx_bb(struct intel_engine_cs *engine, u32 *batch)
{
batch = gen8_emit_flush_coherentl3_wa(engine, batch);
*batch++ = MI_LOAD_REGISTER_IMM(1);
*batch++ = i915_mmio_reg_offset(COMMON_SLICE_CHICKEN2);
*batch++ = _MASKED_BIT_DISABLE(
GEN9_DISABLE_GATHER_AT_SET_SHADER_COMMON_SLICE);
*batch++ = MI_NOOP;
if (IS_KBL_REVID(engine->i915, 0, KBL_REVID_A0)) {
batch = gen8_emit_pipe_control(batch,
PIPE_CONTROL_FLUSH_L3 |
PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE,
i915_ggtt_offset(engine->scratch)
+ 2 * CACHELINE_BYTES);
}
if (HAS_POOLED_EU(engine->i915)) {
*batch++ = GEN9_MEDIA_POOL_STATE;
*batch++ = GEN9_MEDIA_POOL_ENABLE;
*batch++ = 0x00777000;
*batch++ = 0;
*batch++ = 0;
*batch++ = 0;
}
while ((unsigned long)batch % CACHELINE_BYTES)
*batch++ = MI_NOOP;
return batch;
}
static u32 *gen9_init_perctx_bb(struct intel_engine_cs *engine, u32 *batch)
{
*batch++ = MI_BATCH_BUFFER_END;
return batch;
}
static int lrc_setup_wa_ctx(struct intel_engine_cs *engine)
{
struct drm_i915_gem_object *obj;
struct i915_vma *vma;
int err;
obj = i915_gem_object_create(engine->i915, CTX_WA_BB_OBJ_SIZE);
if (IS_ERR(obj))
return PTR_ERR(obj);
vma = i915_vma_instance(obj, &engine->i915->ggtt.base, NULL);
if (IS_ERR(vma)) {
err = PTR_ERR(vma);
goto err;
}
err = i915_vma_pin(vma, 0, PAGE_SIZE, PIN_GLOBAL | PIN_HIGH);
if (err)
goto err;
engine->wa_ctx.vma = vma;
return 0;
err:
i915_gem_object_put(obj);
return err;
}
static void lrc_destroy_wa_ctx(struct intel_engine_cs *engine)
{
i915_vma_unpin_and_release(&engine->wa_ctx.vma);
}
static int intel_init_workaround_bb(struct intel_engine_cs *engine)
{
struct i915_ctx_workarounds *wa_ctx = &engine->wa_ctx;
struct i915_wa_ctx_bb *wa_bb[2] = { &wa_ctx->indirect_ctx,
&wa_ctx->per_ctx };
wa_bb_func_t wa_bb_fn[2];
struct page *page;
void *batch, *batch_ptr;
unsigned int i;
int ret;
if (WARN_ON(engine->id != RCS || !engine->scratch))
return -EINVAL;
switch (INTEL_GEN(engine->i915)) {
case 9:
wa_bb_fn[0] = gen9_init_indirectctx_bb;
wa_bb_fn[1] = gen9_init_perctx_bb;
break;
case 8:
wa_bb_fn[0] = gen8_init_indirectctx_bb;
wa_bb_fn[1] = gen8_init_perctx_bb;
break;
default:
MISSING_CASE(INTEL_GEN(engine->i915));
return 0;
}
ret = lrc_setup_wa_ctx(engine);
if (ret) {
DRM_DEBUG_DRIVER("Failed to setup context WA page: %d\n", ret);
return ret;
}
page = i915_gem_object_get_dirty_page(wa_ctx->vma->obj, 0);
batch = batch_ptr = kmap_atomic(page);
for (i = 0; i < ARRAY_SIZE(wa_bb_fn); i++) {
wa_bb[i]->offset = batch_ptr - batch;
if (WARN_ON(!IS_ALIGNED(wa_bb[i]->offset, CACHELINE_BYTES))) {
ret = -EINVAL;
break;
}
batch_ptr = wa_bb_fn[i](engine, batch_ptr);
wa_bb[i]->size = batch_ptr - (batch + wa_bb[i]->offset);
}
BUG_ON(batch_ptr - batch > CTX_WA_BB_OBJ_SIZE);
kunmap_atomic(batch);
if (ret)
lrc_destroy_wa_ctx(engine);
return ret;
}
static u32 port_seqno(struct execlist_port *port)
{
return port->request ? port->request->global_seqno : 0;
}
static int gen8_init_common_ring(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = intel_mocs_init_engine(engine);
if (ret)
return ret;
intel_engine_reset_breadcrumbs(engine);
intel_engine_init_hangcheck(engine);
I915_WRITE(RING_HWSTAM(engine->mmio_base), 0xffffffff);
I915_WRITE(RING_MODE_GEN7(engine),
_MASKED_BIT_ENABLE(GFX_RUN_LIST_ENABLE));
I915_WRITE(RING_HWS_PGA(engine->mmio_base),
engine->status_page.ggtt_offset);
POSTING_READ(RING_HWS_PGA(engine->mmio_base));
DRM_DEBUG_DRIVER("Execlists enabled for %s\n", engine->name);
clear_bit(ENGINE_IRQ_EXECLIST, &engine->irq_posted);
if (!i915.enable_guc_submission && !execlists_elsp_idle(engine)) {
DRM_DEBUG_DRIVER("Restarting %s from requests [0x%x, 0x%x]\n",
engine->name,
port_seqno(&engine->execlist_port[0]),
port_seqno(&engine->execlist_port[1]));
engine->execlist_port[0].count = 0;
engine->execlist_port[1].count = 0;
execlists_submit_ports(engine);
}
return 0;
}
static int gen8_init_render_ring(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = gen8_init_common_ring(engine);
if (ret)
return ret;
I915_WRITE(MI_MODE, _MASKED_BIT_ENABLE(ASYNC_FLIP_PERF_DISABLE));
I915_WRITE(INSTPM, _MASKED_BIT_ENABLE(INSTPM_FORCE_ORDERING));
return init_workarounds_ring(engine);
}
static int gen9_init_render_ring(struct intel_engine_cs *engine)
{
int ret;
ret = gen8_init_common_ring(engine);
if (ret)
return ret;
return init_workarounds_ring(engine);
}
static void reset_common_ring(struct intel_engine_cs *engine,
struct drm_i915_gem_request *request)
{
struct execlist_port *port = engine->execlist_port;
struct intel_context *ce;
if (!request || request->fence.error != -EIO)
return;
ce = &request->ctx->engine[engine->id];
execlists_init_reg_state(ce->lrc_reg_state,
request->ctx, engine, ce->ring);
ce->lrc_reg_state[CTX_RING_BUFFER_START+1] =
i915_ggtt_offset(ce->ring->vma);
ce->lrc_reg_state[CTX_RING_HEAD+1] = request->postfix;
request->ring->head = request->postfix;
intel_ring_update_space(request->ring);
if (request->ctx != port[0].request->ctx) {
i915_gem_request_put(port[0].request);
port[0] = port[1];
memset(&port[1], 0, sizeof(port[1]));
}
GEM_BUG_ON(request->ctx != port[0].request->ctx);
request->tail =
intel_ring_wrap(request->ring,
request->wa_tail - WA_TAIL_DWORDS*sizeof(u32));
assert_ring_tail_valid(request->ring, request->tail);
}
static int intel_logical_ring_emit_pdps(struct drm_i915_gem_request *req)
{
struct i915_hw_ppgtt *ppgtt = req->ctx->ppgtt;
struct intel_engine_cs *engine = req->engine;
const int num_lri_cmds = GEN8_3LVL_PDPES * 2;
u32 *cs;
int i;
cs = intel_ring_begin(req, num_lri_cmds * 2 + 2);
if (IS_ERR(cs))
return PTR_ERR(cs);
*cs++ = MI_LOAD_REGISTER_IMM(num_lri_cmds);
for (i = GEN8_3LVL_PDPES - 1; i >= 0; i--) {
const dma_addr_t pd_daddr = i915_page_dir_dma_addr(ppgtt, i);
*cs++ = i915_mmio_reg_offset(GEN8_RING_PDP_UDW(engine, i));
*cs++ = upper_32_bits(pd_daddr);
*cs++ = i915_mmio_reg_offset(GEN8_RING_PDP_LDW(engine, i));
*cs++ = lower_32_bits(pd_daddr);
}
*cs++ = MI_NOOP;
intel_ring_advance(req, cs);
return 0;
}
static int gen8_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, u32 len,
const unsigned int flags)
{
u32 *cs;
int ret;
if (req->ctx->ppgtt &&
(intel_engine_flag(req->engine) & req->ctx->ppgtt->pd_dirty_rings) &&
!i915_vm_is_48bit(&req->ctx->ppgtt->base) &&
!intel_vgpu_active(req->i915)) {
ret = intel_logical_ring_emit_pdps(req);
if (ret)
return ret;
req->ctx->ppgtt->pd_dirty_rings &= ~intel_engine_flag(req->engine);
}
cs = intel_ring_begin(req, 4);
if (IS_ERR(cs))
return PTR_ERR(cs);
*cs++ = MI_BATCH_BUFFER_START_GEN8 |
(flags & I915_DISPATCH_SECURE ? 0 : BIT(8)) |
(flags & I915_DISPATCH_RS ? MI_BATCH_RESOURCE_STREAMER : 0);
*cs++ = lower_32_bits(offset);
*cs++ = upper_32_bits(offset);
*cs++ = MI_NOOP;
intel_ring_advance(req, cs);
return 0;
}
static void gen8_logical_ring_enable_irq(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine,
~(engine->irq_enable_mask | engine->irq_keep_mask));
POSTING_READ_FW(RING_IMR(engine->mmio_base));
}
static void gen8_logical_ring_disable_irq(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE_IMR(engine, ~engine->irq_keep_mask);
}
static int gen8_emit_flush(struct drm_i915_gem_request *request, u32 mode)
{
u32 cmd, *cs;
cs = intel_ring_begin(request, 4);
if (IS_ERR(cs))
return PTR_ERR(cs);
cmd = MI_FLUSH_DW + 1;
cmd |= MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
if (mode & EMIT_INVALIDATE) {
cmd |= MI_INVALIDATE_TLB;
if (request->engine->id == VCS)
cmd |= MI_INVALIDATE_BSD;
}
*cs++ = cmd;
*cs++ = I915_GEM_HWS_SCRATCH_ADDR | MI_FLUSH_DW_USE_GTT;
*cs++ = 0;
*cs++ = 0;
intel_ring_advance(request, cs);
return 0;
}
static int gen8_emit_flush_render(struct drm_i915_gem_request *request,
u32 mode)
{
struct intel_engine_cs *engine = request->engine;
u32 scratch_addr =
i915_ggtt_offset(engine->scratch) + 2 * CACHELINE_BYTES;
bool vf_flush_wa = false, dc_flush_wa = false;
u32 *cs, flags = 0;
int len;
flags |= PIPE_CONTROL_CS_STALL;
if (mode & EMIT_FLUSH) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
flags |= PIPE_CONTROL_DC_FLUSH_ENABLE;
flags |= PIPE_CONTROL_FLUSH_ENABLE;
}
if (mode & EMIT_INVALIDATE) {
flags |= PIPE_CONTROL_TLB_INVALIDATE;
flags |= PIPE_CONTROL_INSTRUCTION_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_VF_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_CONST_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_STATE_CACHE_INVALIDATE;
flags |= PIPE_CONTROL_QW_WRITE;
flags |= PIPE_CONTROL_GLOBAL_GTT_IVB;
if (IS_GEN9(request->i915))
vf_flush_wa = true;
if (IS_KBL_REVID(request->i915, 0, KBL_REVID_B0))
dc_flush_wa = true;
}
len = 6;
if (vf_flush_wa)
len += 6;
if (dc_flush_wa)
len += 12;
cs = intel_ring_begin(request, len);
if (IS_ERR(cs))
return PTR_ERR(cs);
if (vf_flush_wa)
cs = gen8_emit_pipe_control(cs, 0, 0);
if (dc_flush_wa)
cs = gen8_emit_pipe_control(cs, PIPE_CONTROL_DC_FLUSH_ENABLE,
0);
cs = gen8_emit_pipe_control(cs, flags, scratch_addr);
if (dc_flush_wa)
cs = gen8_emit_pipe_control(cs, PIPE_CONTROL_CS_STALL, 0);
intel_ring_advance(request, cs);
return 0;
}
static void gen8_emit_wa_tail(struct drm_i915_gem_request *request, u32 *cs)
{
*cs++ = MI_NOOP;
*cs++ = MI_NOOP;
request->wa_tail = intel_ring_offset(request, cs);
}
static void gen8_emit_breadcrumb(struct drm_i915_gem_request *request, u32 *cs)
{
BUILD_BUG_ON(I915_GEM_HWS_INDEX_ADDR & (1 << 5));
*cs++ = (MI_FLUSH_DW + 1) | MI_FLUSH_DW_OP_STOREDW;
*cs++ = intel_hws_seqno_address(request->engine) | MI_FLUSH_DW_USE_GTT;
*cs++ = 0;
*cs++ = request->global_seqno;
*cs++ = MI_USER_INTERRUPT;
*cs++ = MI_NOOP;
request->tail = intel_ring_offset(request, cs);
assert_ring_tail_valid(request->ring, request->tail);
gen8_emit_wa_tail(request, cs);
}
static void gen8_emit_breadcrumb_render(struct drm_i915_gem_request *request,
u32 *cs)
{
BUILD_BUG_ON(I915_GEM_HWS_INDEX & 1);
*cs++ = GFX_OP_PIPE_CONTROL(6);
*cs++ = PIPE_CONTROL_GLOBAL_GTT_IVB | PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE;
*cs++ = intel_hws_seqno_address(request->engine);
*cs++ = 0;
*cs++ = request->global_seqno;
*cs++ = 0;
*cs++ = MI_USER_INTERRUPT;
*cs++ = MI_NOOP;
request->tail = intel_ring_offset(request, cs);
assert_ring_tail_valid(request->ring, request->tail);
gen8_emit_wa_tail(request, cs);
}
static int gen8_init_rcs_context(struct drm_i915_gem_request *req)
{
int ret;
ret = intel_ring_workarounds_emit(req);
if (ret)
return ret;
ret = intel_rcs_context_init_mocs(req);
if (ret)
DRM_ERROR("MOCS failed to program: expect performance issues.\n");
return i915_gem_render_state_emit(req);
}
void intel_logical_ring_cleanup(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv;
if (WARN_ON(test_bit(TASKLET_STATE_SCHED, &engine->irq_tasklet.state)))
tasklet_kill(&engine->irq_tasklet);
dev_priv = engine->i915;
if (engine->buffer) {
WARN_ON((I915_READ_MODE(engine) & MODE_IDLE) == 0);
}
if (engine->cleanup)
engine->cleanup(engine);
if (engine->status_page.vma) {
i915_gem_object_unpin_map(engine->status_page.vma->obj);
engine->status_page.vma = NULL;
}
intel_engine_cleanup_common(engine);
lrc_destroy_wa_ctx(engine);
engine->i915 = NULL;
dev_priv->engine[engine->id] = NULL;
kfree(engine);
}
static void execlists_set_default_submission(struct intel_engine_cs *engine)
{
engine->submit_request = execlists_submit_request;
engine->schedule = execlists_schedule;
engine->irq_tasklet.func = intel_lrc_irq_handler;
}
static void
logical_ring_default_vfuncs(struct intel_engine_cs *engine)
{
engine->init_hw = gen8_init_common_ring;
engine->reset_hw = reset_common_ring;
engine->context_pin = execlists_context_pin;
engine->context_unpin = execlists_context_unpin;
engine->request_alloc = execlists_request_alloc;
engine->emit_flush = gen8_emit_flush;
engine->emit_breadcrumb = gen8_emit_breadcrumb;
engine->emit_breadcrumb_sz = gen8_emit_breadcrumb_sz;
engine->set_default_submission = execlists_set_default_submission;
engine->irq_enable = gen8_logical_ring_enable_irq;
engine->irq_disable = gen8_logical_ring_disable_irq;
engine->emit_bb_start = gen8_emit_bb_start;
}
static inline void
logical_ring_default_irqs(struct intel_engine_cs *engine)
{
unsigned shift = engine->irq_shift;
engine->irq_enable_mask = GT_RENDER_USER_INTERRUPT << shift;
engine->irq_keep_mask = GT_CONTEXT_SWITCH_INTERRUPT << shift;
}
static int
lrc_setup_hws(struct intel_engine_cs *engine, struct i915_vma *vma)
{
const int hws_offset = LRC_PPHWSP_PN * PAGE_SIZE;
void *hws;
hws = i915_gem_object_pin_map(vma->obj, I915_MAP_WB);
if (IS_ERR(hws))
return PTR_ERR(hws);
engine->status_page.page_addr = hws + hws_offset;
engine->status_page.ggtt_offset = i915_ggtt_offset(vma) + hws_offset;
engine->status_page.vma = vma;
return 0;
}
static void
logical_ring_setup(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
enum forcewake_domains fw_domains;
intel_engine_setup_common(engine);
engine->buffer = NULL;
fw_domains = intel_uncore_forcewake_for_reg(dev_priv,
RING_ELSP(engine),
FW_REG_WRITE);
fw_domains |= intel_uncore_forcewake_for_reg(dev_priv,
RING_CONTEXT_STATUS_PTR(engine),
FW_REG_READ | FW_REG_WRITE);
fw_domains |= intel_uncore_forcewake_for_reg(dev_priv,
RING_CONTEXT_STATUS_BUF_BASE(engine),
FW_REG_READ);
engine->fw_domains = fw_domains;
tasklet_init(&engine->irq_tasklet,
intel_lrc_irq_handler, (unsigned long)engine);
logical_ring_default_vfuncs(engine);
logical_ring_default_irqs(engine);
}
static int
logical_ring_init(struct intel_engine_cs *engine)
{
struct i915_gem_context *dctx = engine->i915->kernel_context;
int ret;
ret = intel_engine_init_common(engine);
if (ret)
goto error;
ret = lrc_setup_hws(engine, dctx->engine[engine->id].state);
if (ret) {
DRM_ERROR("Failed to set up hws %s: %d\n", engine->name, ret);
goto error;
}
return 0;
error:
intel_logical_ring_cleanup(engine);
return ret;
}
int logical_render_ring_init(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
logical_ring_setup(engine);
if (HAS_L3_DPF(dev_priv))
engine->irq_keep_mask |= GT_RENDER_L3_PARITY_ERROR_INTERRUPT;
if (INTEL_GEN(dev_priv) >= 9)
engine->init_hw = gen9_init_render_ring;
else
engine->init_hw = gen8_init_render_ring;
engine->init_context = gen8_init_rcs_context;
engine->emit_flush = gen8_emit_flush_render;
engine->emit_breadcrumb = gen8_emit_breadcrumb_render;
engine->emit_breadcrumb_sz = gen8_emit_breadcrumb_render_sz;
ret = intel_engine_create_scratch(engine, PAGE_SIZE);
if (ret)
return ret;
ret = intel_init_workaround_bb(engine);
if (ret) {
DRM_ERROR("WA batch buffer initialization failed: %d\n",
ret);
}
return logical_ring_init(engine);
}
int logical_xcs_ring_init(struct intel_engine_cs *engine)
{
logical_ring_setup(engine);
return logical_ring_init(engine);
}
static u32
make_rpcs(struct drm_i915_private *dev_priv)
{
u32 rpcs = 0;
if (INTEL_GEN(dev_priv) < 9)
return 0;
if (INTEL_INFO(dev_priv)->sseu.has_slice_pg) {
rpcs |= GEN8_RPCS_S_CNT_ENABLE;
rpcs |= hweight8(INTEL_INFO(dev_priv)->sseu.slice_mask) <<
GEN8_RPCS_S_CNT_SHIFT;
rpcs |= GEN8_RPCS_ENABLE;
}
if (INTEL_INFO(dev_priv)->sseu.has_subslice_pg) {
rpcs |= GEN8_RPCS_SS_CNT_ENABLE;
rpcs |= hweight8(INTEL_INFO(dev_priv)->sseu.subslice_mask) <<
GEN8_RPCS_SS_CNT_SHIFT;
rpcs |= GEN8_RPCS_ENABLE;
}
if (INTEL_INFO(dev_priv)->sseu.has_eu_pg) {
rpcs |= INTEL_INFO(dev_priv)->sseu.eu_per_subslice <<
GEN8_RPCS_EU_MIN_SHIFT;
rpcs |= INTEL_INFO(dev_priv)->sseu.eu_per_subslice <<
GEN8_RPCS_EU_MAX_SHIFT;
rpcs |= GEN8_RPCS_ENABLE;
}
return rpcs;
}
static u32 intel_lr_indirect_ctx_offset(struct intel_engine_cs *engine)
{
u32 indirect_ctx_offset;
switch (INTEL_GEN(engine->i915)) {
default:
MISSING_CASE(INTEL_GEN(engine->i915));
case 9:
indirect_ctx_offset =
GEN9_CTX_RCS_INDIRECT_CTX_OFFSET_DEFAULT;
break;
case 8:
indirect_ctx_offset =
GEN8_CTX_RCS_INDIRECT_CTX_OFFSET_DEFAULT;
break;
}
return indirect_ctx_offset;
}
static void execlists_init_reg_state(u32 *regs,
struct i915_gem_context *ctx,
struct intel_engine_cs *engine,
struct intel_ring *ring)
{
struct drm_i915_private *dev_priv = engine->i915;
struct i915_hw_ppgtt *ppgtt = ctx->ppgtt ?: dev_priv->mm.aliasing_ppgtt;
u32 base = engine->mmio_base;
bool rcs = engine->id == RCS;
regs[CTX_LRI_HEADER_0] = MI_LOAD_REGISTER_IMM(rcs ? 14 : 11) |
MI_LRI_FORCE_POSTED;
CTX_REG(regs, CTX_CONTEXT_CONTROL, RING_CONTEXT_CONTROL(engine),
_MASKED_BIT_ENABLE(CTX_CTRL_INHIBIT_SYN_CTX_SWITCH |
CTX_CTRL_ENGINE_CTX_RESTORE_INHIBIT |
(HAS_RESOURCE_STREAMER(dev_priv) ?
CTX_CTRL_RS_CTX_ENABLE : 0)));
CTX_REG(regs, CTX_RING_HEAD, RING_HEAD(base), 0);
CTX_REG(regs, CTX_RING_TAIL, RING_TAIL(base), 0);
CTX_REG(regs, CTX_RING_BUFFER_START, RING_START(base), 0);
CTX_REG(regs, CTX_RING_BUFFER_CONTROL, RING_CTL(base),
RING_CTL_SIZE(ring->size) | RING_VALID);
CTX_REG(regs, CTX_BB_HEAD_U, RING_BBADDR_UDW(base), 0);
CTX_REG(regs, CTX_BB_HEAD_L, RING_BBADDR(base), 0);
CTX_REG(regs, CTX_BB_STATE, RING_BBSTATE(base), RING_BB_PPGTT);
CTX_REG(regs, CTX_SECOND_BB_HEAD_U, RING_SBBADDR_UDW(base), 0);
CTX_REG(regs, CTX_SECOND_BB_HEAD_L, RING_SBBADDR(base), 0);
CTX_REG(regs, CTX_SECOND_BB_STATE, RING_SBBSTATE(base), 0);
if (rcs) {
CTX_REG(regs, CTX_BB_PER_CTX_PTR, RING_BB_PER_CTX_PTR(base), 0);
CTX_REG(regs, CTX_RCS_INDIRECT_CTX, RING_INDIRECT_CTX(base), 0);
CTX_REG(regs, CTX_RCS_INDIRECT_CTX_OFFSET,
RING_INDIRECT_CTX_OFFSET(base), 0);
if (engine->wa_ctx.vma) {
struct i915_ctx_workarounds *wa_ctx = &engine->wa_ctx;
u32 ggtt_offset = i915_ggtt_offset(wa_ctx->vma);
regs[CTX_RCS_INDIRECT_CTX + 1] =
(ggtt_offset + wa_ctx->indirect_ctx.offset) |
(wa_ctx->indirect_ctx.size / CACHELINE_BYTES);
regs[CTX_RCS_INDIRECT_CTX_OFFSET + 1] =
intel_lr_indirect_ctx_offset(engine) << 6;
regs[CTX_BB_PER_CTX_PTR + 1] =
(ggtt_offset + wa_ctx->per_ctx.offset) | 0x01;
}
}
regs[CTX_LRI_HEADER_1] = MI_LOAD_REGISTER_IMM(9) | MI_LRI_FORCE_POSTED;
CTX_REG(regs, CTX_CTX_TIMESTAMP, RING_CTX_TIMESTAMP(base), 0);
CTX_REG(regs, CTX_PDP3_UDW, GEN8_RING_PDP_UDW(engine, 3), 0);
CTX_REG(regs, CTX_PDP3_LDW, GEN8_RING_PDP_LDW(engine, 3), 0);
CTX_REG(regs, CTX_PDP2_UDW, GEN8_RING_PDP_UDW(engine, 2), 0);
CTX_REG(regs, CTX_PDP2_LDW, GEN8_RING_PDP_LDW(engine, 2), 0);
CTX_REG(regs, CTX_PDP1_UDW, GEN8_RING_PDP_UDW(engine, 1), 0);
CTX_REG(regs, CTX_PDP1_LDW, GEN8_RING_PDP_LDW(engine, 1), 0);
CTX_REG(regs, CTX_PDP0_UDW, GEN8_RING_PDP_UDW(engine, 0), 0);
CTX_REG(regs, CTX_PDP0_LDW, GEN8_RING_PDP_LDW(engine, 0), 0);
if (ppgtt && i915_vm_is_48bit(&ppgtt->base)) {
ASSIGN_CTX_PML4(ppgtt, regs);
}
if (rcs) {
regs[CTX_LRI_HEADER_2] = MI_LOAD_REGISTER_IMM(1);
CTX_REG(regs, CTX_R_PWR_CLK_STATE, GEN8_R_PWR_CLK_STATE,
make_rpcs(dev_priv));
}
}
static int
populate_lr_context(struct i915_gem_context *ctx,
struct drm_i915_gem_object *ctx_obj,
struct intel_engine_cs *engine,
struct intel_ring *ring)
{
void *vaddr;
int ret;
ret = i915_gem_object_set_to_cpu_domain(ctx_obj, true);
if (ret) {
DRM_DEBUG_DRIVER("Could not set to CPU domain\n");
return ret;
}
vaddr = i915_gem_object_pin_map(ctx_obj, I915_MAP_WB);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
DRM_DEBUG_DRIVER("Could not map object pages! (%d)\n", ret);
return ret;
}
ctx_obj->mm.dirty = true;
execlists_init_reg_state(vaddr + LRC_STATE_PN * PAGE_SIZE,
ctx, engine, ring);
i915_gem_object_unpin_map(ctx_obj);
return 0;
}
uint32_t intel_lr_context_size(struct intel_engine_cs *engine)
{
int ret = 0;
WARN_ON(INTEL_GEN(engine->i915) < 8);
switch (engine->id) {
case RCS:
if (INTEL_GEN(engine->i915) >= 9)
ret = GEN9_LR_CONTEXT_RENDER_SIZE;
else
ret = GEN8_LR_CONTEXT_RENDER_SIZE;
break;
case VCS:
case BCS:
case VECS:
case VCS2:
ret = GEN8_LR_CONTEXT_OTHER_SIZE;
break;
}
return ret;
}
static int execlists_context_deferred_alloc(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
struct drm_i915_gem_object *ctx_obj;
struct intel_context *ce = &ctx->engine[engine->id];
struct i915_vma *vma;
uint32_t context_size;
struct intel_ring *ring;
int ret;
WARN_ON(ce->state);
context_size = round_up(intel_lr_context_size(engine),
I915_GTT_PAGE_SIZE);
context_size += PAGE_SIZE * LRC_PPHWSP_PN;
ctx_obj = i915_gem_object_create(ctx->i915, context_size);
if (IS_ERR(ctx_obj)) {
DRM_DEBUG_DRIVER("Alloc LRC backing obj failed.\n");
return PTR_ERR(ctx_obj);
}
vma = i915_vma_instance(ctx_obj, &ctx->i915->ggtt.base, NULL);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto error_deref_obj;
}
ring = intel_engine_create_ring(engine, ctx->ring_size);
if (IS_ERR(ring)) {
ret = PTR_ERR(ring);
goto error_deref_obj;
}
ret = populate_lr_context(ctx, ctx_obj, engine, ring);
if (ret) {
DRM_DEBUG_DRIVER("Failed to populate LRC: %d\n", ret);
goto error_ring_free;
}
ce->ring = ring;
ce->state = vma;
ce->initialised |= engine->init_context == NULL;
return 0;
error_ring_free:
intel_ring_free(ring);
error_deref_obj:
i915_gem_object_put(ctx_obj);
return ret;
}
void intel_lr_context_resume(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
struct i915_gem_context *ctx;
enum intel_engine_id id;
list_for_each_entry(ctx, &dev_priv->context_list, link) {
for_each_engine(engine, dev_priv, id) {
struct intel_context *ce = &ctx->engine[engine->id];
u32 *reg;
if (!ce->state)
continue;
reg = i915_gem_object_pin_map(ce->state->obj,
I915_MAP_WB);
if (WARN_ON(IS_ERR(reg)))
continue;
reg += LRC_STATE_PN * PAGE_SIZE / sizeof(*reg);
reg[CTX_RING_HEAD+1] = 0;
reg[CTX_RING_TAIL+1] = 0;
ce->state->obj->mm.dirty = true;
i915_gem_object_unpin_map(ce->state->obj);
intel_ring_reset(ce->ring, 0);
}
}
}
