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
logical_ring_init_platform_invariants(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
engine->disable_lite_restore_wa =
IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1) &&
(engine->id == VCS || engine->id == VCS2);
engine->ctx_desc_template = GEN8_CTX_VALID;
if (IS_GEN8(dev_priv))
engine->ctx_desc_template |= GEN8_CTX_L3LLC_COHERENT;
engine->ctx_desc_template |= GEN8_CTX_PRIVILEGE;
if (engine->disable_lite_restore_wa)
engine->ctx_desc_template |= GEN8_CTX_FORCE_RESTORE;
}
static void
intel_lr_context_descriptor_update(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
struct intel_context *ce = &ctx->engine[engine->id];
u64 desc;
BUILD_BUG_ON(MAX_CONTEXT_HW_ID > (1<<GEN8_CTX_ID_WIDTH));
desc = ctx->desc_template;
desc |= engine->ctx_desc_template;
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
atomic_notifier_call_chain(&rq->ctx->status_notifier, status, rq);
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
struct i915_hw_ppgtt *ppgtt = rq->ctx->ppgtt;
u32 *reg_state = ce->lrc_reg_state;
reg_state[CTX_RING_TAIL+1] = rq->tail;
if (ppgtt && !USES_FULL_48BIT_PPGTT(ppgtt->base.dev))
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
if (!port[0].count)
execlists_context_status_change(port[0].request,
INTEL_CONTEXT_SCHEDULE_IN);
desc[0] = execlists_update_context(port[0].request);
engine->preempt_wa = port[0].count++;
if (port[1].request) {
GEM_BUG_ON(port[1].count);
execlists_context_status_change(port[1].request,
INTEL_CONTEXT_SCHEDULE_IN);
desc[1] = execlists_update_context(port[1].request);
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
ctx->execlists_force_single_submission);
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
unsigned long flags;
struct rb_node *rb;
bool submit = false;
last = port->request;
if (last)
last->tail = last->wa_tail;
GEM_BUG_ON(port[1].request);
spin_lock_irqsave(&engine->timeline->lock, flags);
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
cursor->previous_context = engine->last_context;
engine->last_context = cursor->ctx;
__i915_gem_request_submit(cursor);
last = cursor;
submit = true;
}
if (submit) {
i915_gem_request_assign(&port->request, last);
engine->execlist_first = rb;
}
spin_unlock_irqrestore(&engine->timeline->lock, flags);
if (submit)
execlists_submit_ports(engine);
}
static bool execlists_elsp_idle(struct intel_engine_cs *engine)
{
return !engine->execlist_port[0].request;
}
bool intel_execlists_idle(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
if (!i915.enable_execlists)
return true;
for_each_engine(engine, dev_priv, id)
if (!execlists_elsp_idle(engine))
return false;
return true;
}
static bool execlists_elsp_ready(struct intel_engine_cs *engine)
{
int port;
port = 1;
if (engine->disable_lite_restore_wa || engine->preempt_wa)
port = 0;
return !engine->execlist_port[port].request;
}
static void intel_lrc_irq_handler(unsigned long data)
{
struct intel_engine_cs *engine = (struct intel_engine_cs *)data;
struct execlist_port *port = engine->execlist_port;
struct drm_i915_private *dev_priv = engine->i915;
intel_uncore_forcewake_get(dev_priv, engine->fw_domains);
if (!execlists_elsp_idle(engine)) {
u32 __iomem *csb_mmio =
dev_priv->regs + i915_mmio_reg_offset(RING_CONTEXT_STATUS_PTR(engine));
u32 __iomem *buf =
dev_priv->regs + i915_mmio_reg_offset(RING_CONTEXT_STATUS_BUF_LO(engine, 0));
unsigned int csb, head, tail;
csb = readl(csb_mmio);
head = GEN8_CSB_READ_PTR(csb);
tail = GEN8_CSB_WRITE_PTR(csb);
if (tail < head)
tail += GEN8_CSB_ENTRIES;
while (head < tail) {
unsigned int idx = ++head % GEN8_CSB_ENTRIES;
unsigned int status = readl(buf + 2 * idx);
if (!(status & GEN8_CTX_STATUS_COMPLETED_MASK))
continue;
GEM_BUG_ON(port[0].count == 0);
if (--port[0].count == 0) {
GEM_BUG_ON(status & GEN8_CTX_STATUS_PREEMPTED);
execlists_context_status_change(port[0].request,
INTEL_CONTEXT_SCHEDULE_OUT);
i915_gem_request_put(port[0].request);
port[0] = port[1];
memset(&port[1], 0, sizeof(port[1]));
engine->preempt_wa = false;
}
GEM_BUG_ON(port[0].count == 0 &&
!(status & GEN8_CTX_STATUS_ACTIVE_IDLE));
}
writel(_MASKED_FIELD(GEN8_CSB_READ_PTR_MASK,
GEN8_CSB_WRITE_PTR(csb) << 8),
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
if (insert_request(&request->priotree, &engine->execlist_queue))
engine->execlist_first = &request->priotree.node;
if (execlists_elsp_idle(engine))
tasklet_hi_schedule(&engine->irq_tasklet);
spin_unlock_irqrestore(&engine->timeline->lock, flags);
}
static struct intel_engine_cs *
pt_lock_engine(struct i915_priotree *pt, struct intel_engine_cs *locked)
{
struct intel_engine_cs *engine;
engine = container_of(pt,
struct drm_i915_gem_request,
priotree)->engine;
if (engine != locked) {
if (locked)
spin_unlock_irq(&locked->timeline->lock);
spin_lock_irq(&engine->timeline->lock);
}
return engine;
}
static void execlists_schedule(struct drm_i915_gem_request *request, int prio)
{
static DEFINE_MUTEX(lock);
struct intel_engine_cs *engine = NULL;
struct i915_dependency *dep, *p;
struct i915_dependency stack;
LIST_HEAD(dfs);
if (prio <= READ_ONCE(request->priotree.priority))
return;
mutex_lock(&lock);
stack.signaler = &request->priotree;
list_add(&stack.dfs_link, &dfs);
list_for_each_entry_safe(dep, p, &dfs, dfs_link) {
struct i915_priotree *pt = dep->signaler;
list_for_each_entry(p, &pt->signalers_list, signal_link)
if (prio > READ_ONCE(p->signaler->priority))
list_move_tail(&p->dfs_link, &dfs);
p = list_next_entry(dep, dfs_link);
if (!RB_EMPTY_NODE(&pt->node))
continue;
engine = pt_lock_engine(pt, engine);
if (prio > pt->priority && RB_EMPTY_NODE(&pt->node)) {
pt->priority = prio;
list_del_init(&dep->dfs_link);
}
}
list_for_each_entry_safe_reverse(dep, p, &dfs, dfs_link) {
struct i915_priotree *pt = dep->signaler;
INIT_LIST_HEAD(&dep->dfs_link);
engine = pt_lock_engine(pt, engine);
if (prio <= pt->priority)
continue;
GEM_BUG_ON(RB_EMPTY_NODE(&pt->node));
pt->priority = prio;
rb_erase(&pt->node, &engine->execlist_queue);
if (insert_request(pt, &engine->execlist_queue))
engine->execlist_first = &pt->node;
}
if (engine)
spin_unlock_irq(&engine->timeline->lock);
mutex_unlock(&lock);
}
int intel_logical_ring_alloc_request_extras(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
struct intel_context *ce = &request->ctx->engine[engine->id];
int ret;
request->reserved_space += EXECLISTS_REQUEST_SIZE;
if (!ce->state) {
ret = execlists_context_deferred_alloc(request->ctx, engine);
if (ret)
return ret;
}
request->ring = ce->ring;
ret = intel_lr_context_pin(request->ctx, engine);
if (ret)
return ret;
if (i915.enable_guc_submission) {
ret = i915_guc_wq_reserve(request);
if (ret)
goto err_unpin;
}
ret = intel_ring_begin(request, 0);
if (ret)
goto err_unreserve;
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
err_unpin:
intel_lr_context_unpin(request->ctx, engine);
return ret;
}
static int intel_lr_context_pin(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
struct intel_context *ce = &ctx->engine[engine->id];
void *vaddr;
int ret;
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
if (ce->pin_count++)
return 0;
ret = i915_vma_pin(ce->state, 0, GEN8_LR_CONTEXT_ALIGN,
PIN_OFFSET_BIAS | GUC_WOPCM_TOP | PIN_GLOBAL);
if (ret)
goto err;
vaddr = i915_gem_object_pin_map(ce->state->obj, I915_MAP_WB);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
goto unpin_vma;
}
ret = intel_ring_pin(ce->ring);
if (ret)
goto unpin_map;
intel_lr_context_descriptor_update(ctx, engine);
ce->lrc_reg_state = vaddr + LRC_STATE_PN * PAGE_SIZE;
ce->lrc_reg_state[CTX_RING_BUFFER_START+1] =
i915_ggtt_offset(ce->ring->vma);
ce->state->obj->mm.dirty = true;
if (i915.enable_guc_submission) {
struct drm_i915_private *dev_priv = ctx->i915;
I915_WRITE(GEN8_GTCR, GEN8_GTCR_INVALIDATE);
}
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
void intel_lr_context_unpin(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
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
static int intel_logical_ring_workarounds_emit(struct drm_i915_gem_request *req)
{
int ret, i;
struct intel_ring *ring = req->ring;
struct i915_workarounds *w = &req->i915->workarounds;
if (w->count == 0)
return 0;
ret = req->engine->emit_flush(req, EMIT_BARRIER);
if (ret)
return ret;
ret = intel_ring_begin(req, w->count * 2 + 2);
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(w->count));
for (i = 0; i < w->count; i++) {
intel_ring_emit_reg(ring, w->reg[i].addr);
intel_ring_emit(ring, w->reg[i].value);
}
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
ret = req->engine->emit_flush(req, EMIT_BARRIER);
if (ret)
return ret;
return 0;
}
static inline int gen8_emit_flush_coherentl3_wa(struct intel_engine_cs *engine,
uint32_t *batch,
uint32_t index)
{
uint32_t l3sqc4_flush = (0x40400000 | GEN8_LQSC_FLUSH_COHERENT_LINES);
wa_ctx_emit(batch, index, (MI_STORE_REGISTER_MEM_GEN8 |
MI_SRM_LRM_GLOBAL_GTT));
wa_ctx_emit_reg(batch, index, GEN8_L3SQCREG4);
wa_ctx_emit(batch, index, i915_ggtt_offset(engine->scratch) + 256);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, MI_LOAD_REGISTER_IMM(1));
wa_ctx_emit_reg(batch, index, GEN8_L3SQCREG4);
wa_ctx_emit(batch, index, l3sqc4_flush);
wa_ctx_emit(batch, index, GFX_OP_PIPE_CONTROL(6));
wa_ctx_emit(batch, index, (PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_DC_FLUSH_ENABLE));
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, (MI_LOAD_REGISTER_MEM_GEN8 |
MI_SRM_LRM_GLOBAL_GTT));
wa_ctx_emit_reg(batch, index, GEN8_L3SQCREG4);
wa_ctx_emit(batch, index, i915_ggtt_offset(engine->scratch) + 256);
wa_ctx_emit(batch, index, 0);
return index;
}
static inline uint32_t wa_ctx_start(struct i915_wa_ctx_bb *wa_ctx,
uint32_t offset,
uint32_t start_alignment)
{
return wa_ctx->offset = ALIGN(offset, start_alignment);
}
static inline int wa_ctx_end(struct i915_wa_ctx_bb *wa_ctx,
uint32_t offset,
uint32_t size_alignment)
{
wa_ctx->size = offset - wa_ctx->offset;
WARN(wa_ctx->size % size_alignment,
"wa_ctx_bb failed sanity checks: size %d is not aligned to %d\n",
wa_ctx->size, size_alignment);
return 0;
}
static int gen8_init_indirectctx_bb(struct intel_engine_cs *engine,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *batch,
uint32_t *offset)
{
uint32_t scratch_addr;
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_DISABLE);
if (IS_BROADWELL(engine->i915)) {
int rc = gen8_emit_flush_coherentl3_wa(engine, batch, index);
if (rc < 0)
return rc;
index = rc;
}
scratch_addr = i915_ggtt_offset(engine->scratch) + 2 * CACHELINE_BYTES;
wa_ctx_emit(batch, index, GFX_OP_PIPE_CONTROL(6));
wa_ctx_emit(batch, index, (PIPE_CONTROL_FLUSH_L3 |
PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE));
wa_ctx_emit(batch, index, scratch_addr);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
while (index % CACHELINE_DWORDS)
wa_ctx_emit(batch, index, MI_NOOP);
return wa_ctx_end(wa_ctx, *offset = index, CACHELINE_DWORDS);
}
static int gen8_init_perctx_bb(struct intel_engine_cs *engine,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *batch,
uint32_t *offset)
{
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_ENABLE);
wa_ctx_emit(batch, index, MI_BATCH_BUFFER_END);
return wa_ctx_end(wa_ctx, *offset = index, 1);
}
static int gen9_init_indirectctx_bb(struct intel_engine_cs *engine,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *batch,
uint32_t *offset)
{
int ret;
struct drm_i915_private *dev_priv = engine->i915;
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_DISABLE);
ret = gen8_emit_flush_coherentl3_wa(engine, batch, index);
if (ret < 0)
return ret;
index = ret;
wa_ctx_emit(batch, index, MI_LOAD_REGISTER_IMM(1));
wa_ctx_emit_reg(batch, index, COMMON_SLICE_CHICKEN2);
wa_ctx_emit(batch, index, _MASKED_BIT_DISABLE(
GEN9_DISABLE_GATHER_AT_SET_SHADER_COMMON_SLICE));
wa_ctx_emit(batch, index, MI_NOOP);
if (IS_KBL_REVID(dev_priv, 0, KBL_REVID_A0)) {
u32 scratch_addr =
i915_ggtt_offset(engine->scratch) + 2 * CACHELINE_BYTES;
wa_ctx_emit(batch, index, GFX_OP_PIPE_CONTROL(6));
wa_ctx_emit(batch, index, (PIPE_CONTROL_FLUSH_L3 |
PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE));
wa_ctx_emit(batch, index, scratch_addr);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
}
if (HAS_POOLED_EU(engine->i915)) {
u32 eu_pool_config = 0x00777000;
wa_ctx_emit(batch, index, GEN9_MEDIA_POOL_STATE);
wa_ctx_emit(batch, index, GEN9_MEDIA_POOL_ENABLE);
wa_ctx_emit(batch, index, eu_pool_config);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
wa_ctx_emit(batch, index, 0);
}
while (index % CACHELINE_DWORDS)
wa_ctx_emit(batch, index, MI_NOOP);
return wa_ctx_end(wa_ctx, *offset = index, CACHELINE_DWORDS);
}
static int gen9_init_perctx_bb(struct intel_engine_cs *engine,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *batch,
uint32_t *offset)
{
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
if (IS_BXT_REVID(engine->i915, 0, BXT_REVID_A1)) {
wa_ctx_emit(batch, index, MI_LOAD_REGISTER_IMM(1));
wa_ctx_emit_reg(batch, index, GEN9_SLICE_COMMON_ECO_CHICKEN0);
wa_ctx_emit(batch, index,
_MASKED_BIT_ENABLE(DISABLE_PIXEL_MASK_CAMMING));
wa_ctx_emit(batch, index, MI_NOOP);
}
if (IS_BXT_REVID(engine->i915, 0, BXT_REVID_B0)) {
wa_ctx_emit(batch, index, MI_LOAD_REGISTER_IMM(4));
wa_ctx_emit_reg(batch, index, GEN8_STATE_ACK);
wa_ctx_emit(batch, index, _MASKED_BIT_DISABLE(GEN9_SUBSLICE_TDL_ACK_BITS));
wa_ctx_emit_reg(batch, index, GEN9_STATE_ACK_SLICE1);
wa_ctx_emit(batch, index, _MASKED_BIT_DISABLE(GEN9_SUBSLICE_TDL_ACK_BITS));
wa_ctx_emit_reg(batch, index, GEN9_STATE_ACK_SLICE2);
wa_ctx_emit(batch, index, _MASKED_BIT_DISABLE(GEN9_SUBSLICE_TDL_ACK_BITS));
wa_ctx_emit_reg(batch, index, GEN7_ROW_CHICKEN2);
wa_ctx_emit(batch, index, 0x0);
wa_ctx_emit(batch, index, MI_NOOP);
}
if (IS_BXT_REVID(engine->i915, 0, BXT_REVID_A1))
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_ENABLE);
wa_ctx_emit(batch, index, MI_BATCH_BUFFER_END);
return wa_ctx_end(wa_ctx, *offset = index, 1);
}
static int lrc_setup_wa_ctx_obj(struct intel_engine_cs *engine, u32 size)
{
struct drm_i915_gem_object *obj;
struct i915_vma *vma;
int err;
obj = i915_gem_object_create(&engine->i915->drm, PAGE_ALIGN(size));
if (IS_ERR(obj))
return PTR_ERR(obj);
vma = i915_vma_create(obj, &engine->i915->ggtt.base, NULL);
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
static void lrc_destroy_wa_ctx_obj(struct intel_engine_cs *engine)
{
i915_vma_unpin_and_release(&engine->wa_ctx.vma);
}
static int intel_init_workaround_bb(struct intel_engine_cs *engine)
{
struct i915_ctx_workarounds *wa_ctx = &engine->wa_ctx;
uint32_t *batch;
uint32_t offset;
struct page *page;
int ret;
WARN_ON(engine->id != RCS);
if (INTEL_GEN(engine->i915) > 9) {
DRM_ERROR("WA batch buffer is not initialized for Gen%d\n",
INTEL_GEN(engine->i915));
return 0;
}
if (!engine->scratch) {
DRM_ERROR("scratch page not allocated for %s\n", engine->name);
return -EINVAL;
}
ret = lrc_setup_wa_ctx_obj(engine, PAGE_SIZE);
if (ret) {
DRM_DEBUG_DRIVER("Failed to setup context WA page: %d\n", ret);
return ret;
}
page = i915_gem_object_get_dirty_page(wa_ctx->vma->obj, 0);
batch = kmap_atomic(page);
offset = 0;
if (IS_GEN8(engine->i915)) {
ret = gen8_init_indirectctx_bb(engine,
&wa_ctx->indirect_ctx,
batch,
&offset);
if (ret)
goto out;
ret = gen8_init_perctx_bb(engine,
&wa_ctx->per_ctx,
batch,
&offset);
if (ret)
goto out;
} else if (IS_GEN9(engine->i915)) {
ret = gen9_init_indirectctx_bb(engine,
&wa_ctx->indirect_ctx,
batch,
&offset);
if (ret)
goto out;
ret = gen9_init_perctx_bb(engine,
&wa_ctx->per_ctx,
batch,
&offset);
if (ret)
goto out;
}
out:
kunmap_atomic(batch);
if (ret)
lrc_destroy_wa_ctx_obj(engine);
return ret;
}
static void lrc_init_hws(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
I915_WRITE(RING_HWS_PGA(engine->mmio_base),
engine->status_page.ggtt_offset);
POSTING_READ(RING_HWS_PGA(engine->mmio_base));
}
static int gen8_init_common_ring(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
ret = intel_mocs_init_engine(engine);
if (ret)
return ret;
lrc_init_hws(engine);
intel_engine_reset_breadcrumbs(engine);
I915_WRITE(RING_HWSTAM(engine->mmio_base), 0xffffffff);
I915_WRITE(RING_MODE_GEN7(engine),
_MASKED_BIT_DISABLE(GFX_REPLAY_MODE) |
_MASKED_BIT_ENABLE(GFX_RUN_LIST_ENABLE));
DRM_DEBUG_DRIVER("Execlists enabled for %s\n", engine->name);
intel_engine_init_hangcheck(engine);
if (!execlists_elsp_idle(engine)) {
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
struct drm_i915_private *dev_priv = engine->i915;
struct execlist_port *port = engine->execlist_port;
struct intel_context *ce = &request->ctx->engine[engine->id];
execlists_init_reg_state(ce->lrc_reg_state,
request->ctx, engine, ce->ring);
ce->lrc_reg_state[CTX_RING_BUFFER_START+1] =
i915_ggtt_offset(ce->ring->vma);
ce->lrc_reg_state[CTX_RING_HEAD+1] = request->postfix;
request->ring->head = request->postfix;
request->ring->last_retired_head = -1;
intel_ring_update_space(request->ring);
if (i915.enable_guc_submission)
return;
I915_WRITE(RING_CONTEXT_STATUS_PTR(engine), _MASKED_FIELD(0xffff, 0));
if (request->ctx != port[0].request->ctx) {
i915_gem_request_put(port[0].request);
port[0] = port[1];
memset(&port[1], 0, sizeof(port[1]));
}
GEM_BUG_ON(request->ctx != port[0].request->ctx);
request->tail = request->wa_tail - WA_TAIL_DWORDS * sizeof(u32);
}
static int intel_logical_ring_emit_pdps(struct drm_i915_gem_request *req)
{
struct i915_hw_ppgtt *ppgtt = req->ctx->ppgtt;
struct intel_ring *ring = req->ring;
struct intel_engine_cs *engine = req->engine;
const int num_lri_cmds = GEN8_LEGACY_PDPES * 2;
int i, ret;
ret = intel_ring_begin(req, num_lri_cmds * 2 + 2);
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(num_lri_cmds));
for (i = GEN8_LEGACY_PDPES - 1; i >= 0; i--) {
const dma_addr_t pd_daddr = i915_page_dir_dma_addr(ppgtt, i);
intel_ring_emit_reg(ring, GEN8_RING_PDP_UDW(engine, i));
intel_ring_emit(ring, upper_32_bits(pd_daddr));
intel_ring_emit_reg(ring, GEN8_RING_PDP_LDW(engine, i));
intel_ring_emit(ring, lower_32_bits(pd_daddr));
}
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static int gen8_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, u32 len,
unsigned int dispatch_flags)
{
struct intel_ring *ring = req->ring;
bool ppgtt = !(dispatch_flags & I915_DISPATCH_SECURE);
int ret;
if (req->ctx->ppgtt &&
(intel_engine_flag(req->engine) & req->ctx->ppgtt->pd_dirty_rings)) {
if (!USES_FULL_48BIT_PPGTT(req->i915) &&
!intel_vgpu_active(req->i915)) {
ret = intel_logical_ring_emit_pdps(req);
if (ret)
return ret;
}
req->ctx->ppgtt->pd_dirty_rings &= ~intel_engine_flag(req->engine);
}
ret = intel_ring_begin(req, 4);
if (ret)
return ret;
intel_ring_emit(ring, MI_BATCH_BUFFER_START_GEN8 |
(ppgtt<<8) |
(dispatch_flags & I915_DISPATCH_RS ?
MI_BATCH_RESOURCE_STREAMER : 0));
intel_ring_emit(ring, lower_32_bits(offset));
intel_ring_emit(ring, upper_32_bits(offset));
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
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
struct intel_ring *ring = request->ring;
u32 cmd;
int ret;
ret = intel_ring_begin(request, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW + 1;
cmd |= MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
if (mode & EMIT_INVALIDATE) {
cmd |= MI_INVALIDATE_TLB;
if (request->engine->id == VCS)
cmd |= MI_INVALIDATE_BSD;
}
intel_ring_emit(ring, cmd);
intel_ring_emit(ring,
I915_GEM_HWS_SCRATCH_ADDR |
MI_FLUSH_DW_USE_GTT);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_advance(ring);
return 0;
}
static int gen8_emit_flush_render(struct drm_i915_gem_request *request,
u32 mode)
{
struct intel_ring *ring = request->ring;
struct intel_engine_cs *engine = request->engine;
u32 scratch_addr =
i915_ggtt_offset(engine->scratch) + 2 * CACHELINE_BYTES;
bool vf_flush_wa = false, dc_flush_wa = false;
u32 flags = 0;
int ret;
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
ret = intel_ring_begin(request, len);
if (ret)
return ret;
if (vf_flush_wa) {
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(6));
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
}
if (dc_flush_wa) {
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(6));
intel_ring_emit(ring, PIPE_CONTROL_DC_FLUSH_ENABLE);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
}
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(6));
intel_ring_emit(ring, flags);
intel_ring_emit(ring, scratch_addr);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
if (dc_flush_wa) {
intel_ring_emit(ring, GFX_OP_PIPE_CONTROL(6));
intel_ring_emit(ring, PIPE_CONTROL_CS_STALL);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
intel_ring_emit(ring, 0);
}
intel_ring_advance(ring);
return 0;
}
static void bxt_a_seqno_barrier(struct intel_engine_cs *engine)
{
intel_flush_status_page(engine, I915_GEM_HWS_INDEX);
}
static void gen8_emit_wa_tail(struct drm_i915_gem_request *request, u32 *out)
{
*out++ = MI_NOOP;
*out++ = MI_NOOP;
request->wa_tail = intel_ring_offset(request->ring, out);
}
static void gen8_emit_breadcrumb(struct drm_i915_gem_request *request,
u32 *out)
{
BUILD_BUG_ON(I915_GEM_HWS_INDEX_ADDR & (1 << 5));
*out++ = (MI_FLUSH_DW + 1) | MI_FLUSH_DW_OP_STOREDW;
*out++ = intel_hws_seqno_address(request->engine) | MI_FLUSH_DW_USE_GTT;
*out++ = 0;
*out++ = request->global_seqno;
*out++ = MI_USER_INTERRUPT;
*out++ = MI_NOOP;
request->tail = intel_ring_offset(request->ring, out);
gen8_emit_wa_tail(request, out);
}
static void gen8_emit_breadcrumb_render(struct drm_i915_gem_request *request,
u32 *out)
{
BUILD_BUG_ON(I915_GEM_HWS_INDEX & 1);
*out++ = GFX_OP_PIPE_CONTROL(6);
*out++ = (PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE);
*out++ = intel_hws_seqno_address(request->engine);
*out++ = 0;
*out++ = request->global_seqno;
*out++ = 0;
*out++ = MI_USER_INTERRUPT;
*out++ = MI_NOOP;
request->tail = intel_ring_offset(request->ring, out);
gen8_emit_wa_tail(request, out);
}
static int gen8_init_rcs_context(struct drm_i915_gem_request *req)
{
int ret;
ret = intel_logical_ring_workarounds_emit(req);
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
intel_engine_cleanup_common(engine);
if (engine->status_page.vma) {
i915_gem_object_unpin_map(engine->status_page.vma->obj);
engine->status_page.vma = NULL;
}
intel_lr_context_unpin(dev_priv->kernel_context, engine);
lrc_destroy_wa_ctx_obj(engine);
engine->i915 = NULL;
dev_priv->engine[engine->id] = NULL;
kfree(engine);
}
void intel_execlists_enable_submission(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
for_each_engine(engine, dev_priv, id) {
engine->submit_request = execlists_submit_request;
engine->schedule = execlists_schedule;
}
}
static void
logical_ring_default_vfuncs(struct intel_engine_cs *engine)
{
engine->init_hw = gen8_init_common_ring;
engine->reset_hw = reset_common_ring;
engine->emit_flush = gen8_emit_flush;
engine->emit_breadcrumb = gen8_emit_breadcrumb;
engine->emit_breadcrumb_sz = gen8_emit_breadcrumb_sz;
engine->submit_request = execlists_submit_request;
engine->schedule = execlists_schedule;
engine->irq_enable = gen8_logical_ring_enable_irq;
engine->irq_disable = gen8_logical_ring_disable_irq;
engine->emit_bb_start = gen8_emit_bb_start;
if (IS_BXT_REVID(engine->i915, 0, BXT_REVID_A1))
engine->irq_seqno_barrier = bxt_a_seqno_barrier;
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
logical_ring_init_platform_invariants(engine);
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
ret = execlists_context_deferred_alloc(dctx, engine);
if (ret)
goto error;
ret = intel_lr_context_pin(dctx, engine);
if (ret) {
DRM_ERROR("Failed to pin context for %s: %d\n",
engine->name, ret);
goto error;
}
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
ret = intel_engine_create_scratch(engine, 4096);
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
static void execlists_init_reg_state(u32 *reg_state,
struct i915_gem_context *ctx,
struct intel_engine_cs *engine,
struct intel_ring *ring)
{
struct drm_i915_private *dev_priv = engine->i915;
struct i915_hw_ppgtt *ppgtt = ctx->ppgtt ?: dev_priv->mm.aliasing_ppgtt;
reg_state[CTX_LRI_HEADER_0] =
MI_LOAD_REGISTER_IMM(engine->id == RCS ? 14 : 11) | MI_LRI_FORCE_POSTED;
ASSIGN_CTX_REG(reg_state, CTX_CONTEXT_CONTROL,
RING_CONTEXT_CONTROL(engine),
_MASKED_BIT_ENABLE(CTX_CTRL_INHIBIT_SYN_CTX_SWITCH |
CTX_CTRL_ENGINE_CTX_RESTORE_INHIBIT |
(HAS_RESOURCE_STREAMER(dev_priv) ?
CTX_CTRL_RS_CTX_ENABLE : 0)));
ASSIGN_CTX_REG(reg_state, CTX_RING_HEAD, RING_HEAD(engine->mmio_base),
0);
ASSIGN_CTX_REG(reg_state, CTX_RING_TAIL, RING_TAIL(engine->mmio_base),
0);
ASSIGN_CTX_REG(reg_state, CTX_RING_BUFFER_START,
RING_START(engine->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_RING_BUFFER_CONTROL,
RING_CTL(engine->mmio_base),
RING_CTL_SIZE(ring->size) | RING_VALID);
ASSIGN_CTX_REG(reg_state, CTX_BB_HEAD_U,
RING_BBADDR_UDW(engine->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_BB_HEAD_L,
RING_BBADDR(engine->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_BB_STATE,
RING_BBSTATE(engine->mmio_base),
RING_BB_PPGTT);
ASSIGN_CTX_REG(reg_state, CTX_SECOND_BB_HEAD_U,
RING_SBBADDR_UDW(engine->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_SECOND_BB_HEAD_L,
RING_SBBADDR(engine->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_SECOND_BB_STATE,
RING_SBBSTATE(engine->mmio_base), 0);
if (engine->id == RCS) {
ASSIGN_CTX_REG(reg_state, CTX_BB_PER_CTX_PTR,
RING_BB_PER_CTX_PTR(engine->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_RCS_INDIRECT_CTX,
RING_INDIRECT_CTX(engine->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_RCS_INDIRECT_CTX_OFFSET,
RING_INDIRECT_CTX_OFFSET(engine->mmio_base), 0);
if (engine->wa_ctx.vma) {
struct i915_ctx_workarounds *wa_ctx = &engine->wa_ctx;
u32 ggtt_offset = i915_ggtt_offset(wa_ctx->vma);
reg_state[CTX_RCS_INDIRECT_CTX+1] =
(ggtt_offset + wa_ctx->indirect_ctx.offset * sizeof(uint32_t)) |
(wa_ctx->indirect_ctx.size / CACHELINE_DWORDS);
reg_state[CTX_RCS_INDIRECT_CTX_OFFSET+1] =
intel_lr_indirect_ctx_offset(engine) << 6;
reg_state[CTX_BB_PER_CTX_PTR+1] =
(ggtt_offset + wa_ctx->per_ctx.offset * sizeof(uint32_t)) |
0x01;
}
}
reg_state[CTX_LRI_HEADER_1] = MI_LOAD_REGISTER_IMM(9) | MI_LRI_FORCE_POSTED;
ASSIGN_CTX_REG(reg_state, CTX_CTX_TIMESTAMP,
RING_CTX_TIMESTAMP(engine->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP3_UDW, GEN8_RING_PDP_UDW(engine, 3),
0);
ASSIGN_CTX_REG(reg_state, CTX_PDP3_LDW, GEN8_RING_PDP_LDW(engine, 3),
0);
ASSIGN_CTX_REG(reg_state, CTX_PDP2_UDW, GEN8_RING_PDP_UDW(engine, 2),
0);
ASSIGN_CTX_REG(reg_state, CTX_PDP2_LDW, GEN8_RING_PDP_LDW(engine, 2),
0);
ASSIGN_CTX_REG(reg_state, CTX_PDP1_UDW, GEN8_RING_PDP_UDW(engine, 1),
0);
ASSIGN_CTX_REG(reg_state, CTX_PDP1_LDW, GEN8_RING_PDP_LDW(engine, 1),
0);
ASSIGN_CTX_REG(reg_state, CTX_PDP0_UDW, GEN8_RING_PDP_UDW(engine, 0),
0);
ASSIGN_CTX_REG(reg_state, CTX_PDP0_LDW, GEN8_RING_PDP_LDW(engine, 0),
0);
if (USES_FULL_48BIT_PPGTT(ppgtt->base.dev)) {
ASSIGN_CTX_PML4(ppgtt, reg_state);
} else {
execlists_update_context_pdps(ppgtt, reg_state);
}
if (engine->id == RCS) {
reg_state[CTX_LRI_HEADER_2] = MI_LOAD_REGISTER_IMM(1);
ASSIGN_CTX_REG(reg_state, CTX_R_PWR_CLK_STATE, GEN8_R_PWR_CLK_STATE,
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
context_size = round_up(intel_lr_context_size(engine), 4096);
context_size += PAGE_SIZE * LRC_PPHWSP_PN;
ctx_obj = i915_gem_object_create(&ctx->i915->drm, context_size);
if (IS_ERR(ctx_obj)) {
DRM_DEBUG_DRIVER("Alloc LRC backing obj failed.\n");
return PTR_ERR(ctx_obj);
}
vma = i915_vma_create(ctx_obj, &ctx->i915->ggtt.base, NULL);
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
ce->initialised = engine->init_context == NULL;
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
ce->ring->head = ce->ring->tail = 0;
ce->ring->last_retired_head = -1;
intel_ring_update_space(ce->ring);
}
}
}
