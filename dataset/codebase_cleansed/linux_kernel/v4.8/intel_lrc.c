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
if (IS_GEN8(dev_priv) || IS_GEN9(dev_priv))
engine->idle_lite_restore_wa = ~0;
engine->disable_lite_restore_wa = (IS_SKL_REVID(dev_priv, 0, SKL_REVID_B0) ||
IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1)) &&
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
desc |= ce->lrc_vma->node.start + LRC_PPHWSP_PN * PAGE_SIZE;
desc |= (u64)ctx->hw_id << GEN8_CTX_ID_SHIFT;
ce->lrc_desc = desc;
}
uint64_t intel_lr_context_descriptor(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
return ctx->engine[engine->id].lrc_desc;
}
static void execlists_elsp_write(struct drm_i915_gem_request *rq0,
struct drm_i915_gem_request *rq1)
{
struct intel_engine_cs *engine = rq0->engine;
struct drm_i915_private *dev_priv = rq0->i915;
uint64_t desc[2];
if (rq1) {
desc[1] = intel_lr_context_descriptor(rq1->ctx, rq1->engine);
rq1->elsp_submitted++;
} else {
desc[1] = 0;
}
desc[0] = intel_lr_context_descriptor(rq0->ctx, rq0->engine);
rq0->elsp_submitted++;
I915_WRITE_FW(RING_ELSP(engine), upper_32_bits(desc[1]));
I915_WRITE_FW(RING_ELSP(engine), lower_32_bits(desc[1]));
I915_WRITE_FW(RING_ELSP(engine), upper_32_bits(desc[0]));
I915_WRITE_FW(RING_ELSP(engine), lower_32_bits(desc[0]));
POSTING_READ_FW(RING_EXECLIST_STATUS_LO(engine));
}
static void
execlists_update_context_pdps(struct i915_hw_ppgtt *ppgtt, u32 *reg_state)
{
ASSIGN_CTX_PDP(ppgtt, reg_state, 3);
ASSIGN_CTX_PDP(ppgtt, reg_state, 2);
ASSIGN_CTX_PDP(ppgtt, reg_state, 1);
ASSIGN_CTX_PDP(ppgtt, reg_state, 0);
}
static void execlists_update_context(struct drm_i915_gem_request *rq)
{
struct intel_engine_cs *engine = rq->engine;
struct i915_hw_ppgtt *ppgtt = rq->ctx->ppgtt;
uint32_t *reg_state = rq->ctx->engine[engine->id].lrc_reg_state;
reg_state[CTX_RING_TAIL+1] = rq->tail;
if (ppgtt && !USES_FULL_48BIT_PPGTT(ppgtt->base.dev))
execlists_update_context_pdps(ppgtt, reg_state);
}
static void execlists_submit_requests(struct drm_i915_gem_request *rq0,
struct drm_i915_gem_request *rq1)
{
struct drm_i915_private *dev_priv = rq0->i915;
unsigned int fw_domains = rq0->engine->fw_domains;
execlists_update_context(rq0);
if (rq1)
execlists_update_context(rq1);
spin_lock_irq(&dev_priv->uncore.lock);
intel_uncore_forcewake_get__locked(dev_priv, fw_domains);
execlists_elsp_write(rq0, rq1);
intel_uncore_forcewake_put__locked(dev_priv, fw_domains);
spin_unlock_irq(&dev_priv->uncore.lock);
}
static inline void execlists_context_status_change(
struct drm_i915_gem_request *rq,
unsigned long status)
{
if (!IS_ENABLED(CONFIG_DRM_I915_GVT))
return;
atomic_notifier_call_chain(&rq->ctx->status_notifier, status, rq);
}
static void execlists_context_unqueue(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *req0 = NULL, *req1 = NULL;
struct drm_i915_gem_request *cursor, *tmp;
assert_spin_locked(&engine->execlist_lock);
WARN_ON(!intel_irqs_enabled(engine->i915));
list_for_each_entry_safe(cursor, tmp, &engine->execlist_queue,
execlist_link) {
if (!req0) {
req0 = cursor;
} else if (req0->ctx == cursor->ctx) {
cursor->elsp_submitted = req0->elsp_submitted;
list_del(&req0->execlist_link);
i915_gem_request_unreference(req0);
req0 = cursor;
} else {
if (IS_ENABLED(CONFIG_DRM_I915_GVT)) {
if (req0->ctx->execlists_force_single_submission)
break;
if (cursor->ctx->execlists_force_single_submission)
break;
}
req1 = cursor;
WARN_ON(req1->elsp_submitted);
break;
}
}
if (unlikely(!req0))
return;
execlists_context_status_change(req0, INTEL_CONTEXT_SCHEDULE_IN);
if (req1)
execlists_context_status_change(req1,
INTEL_CONTEXT_SCHEDULE_IN);
if (req0->elsp_submitted & engine->idle_lite_restore_wa) {
struct intel_ringbuffer *ringbuf;
ringbuf = req0->ctx->engine[engine->id].ringbuf;
req0->tail += 8;
req0->tail &= ringbuf->size - 1;
}
execlists_submit_requests(req0, req1);
}
static unsigned int
execlists_check_remove_request(struct intel_engine_cs *engine, u32 ctx_id)
{
struct drm_i915_gem_request *head_req;
assert_spin_locked(&engine->execlist_lock);
head_req = list_first_entry_or_null(&engine->execlist_queue,
struct drm_i915_gem_request,
execlist_link);
if (WARN_ON(!head_req || (head_req->ctx_hw_id != ctx_id)))
return 0;
WARN(head_req->elsp_submitted == 0, "Never submitted head request\n");
if (--head_req->elsp_submitted > 0)
return 0;
execlists_context_status_change(head_req, INTEL_CONTEXT_SCHEDULE_OUT);
list_del(&head_req->execlist_link);
i915_gem_request_unreference(head_req);
return 1;
}
static u32
get_context_status(struct intel_engine_cs *engine, unsigned int read_pointer,
u32 *context_id)
{
struct drm_i915_private *dev_priv = engine->i915;
u32 status;
read_pointer %= GEN8_CSB_ENTRIES;
status = I915_READ_FW(RING_CONTEXT_STATUS_BUF_LO(engine, read_pointer));
if (status & GEN8_CTX_STATUS_IDLE_ACTIVE)
return 0;
*context_id = I915_READ_FW(RING_CONTEXT_STATUS_BUF_HI(engine,
read_pointer));
return status;
}
static void intel_lrc_irq_handler(unsigned long data)
{
struct intel_engine_cs *engine = (struct intel_engine_cs *)data;
struct drm_i915_private *dev_priv = engine->i915;
u32 status_pointer;
unsigned int read_pointer, write_pointer;
u32 csb[GEN8_CSB_ENTRIES][2];
unsigned int csb_read = 0, i;
unsigned int submit_contexts = 0;
intel_uncore_forcewake_get(dev_priv, engine->fw_domains);
status_pointer = I915_READ_FW(RING_CONTEXT_STATUS_PTR(engine));
read_pointer = engine->next_context_status_buffer;
write_pointer = GEN8_CSB_WRITE_PTR(status_pointer);
if (read_pointer > write_pointer)
write_pointer += GEN8_CSB_ENTRIES;
while (read_pointer < write_pointer) {
if (WARN_ON_ONCE(csb_read == GEN8_CSB_ENTRIES))
break;
csb[csb_read][0] = get_context_status(engine, ++read_pointer,
&csb[csb_read][1]);
csb_read++;
}
engine->next_context_status_buffer = write_pointer % GEN8_CSB_ENTRIES;
I915_WRITE_FW(RING_CONTEXT_STATUS_PTR(engine),
_MASKED_FIELD(GEN8_CSB_READ_PTR_MASK,
engine->next_context_status_buffer << 8));
intel_uncore_forcewake_put(dev_priv, engine->fw_domains);
spin_lock(&engine->execlist_lock);
for (i = 0; i < csb_read; i++) {
if (unlikely(csb[i][0] & GEN8_CTX_STATUS_PREEMPTED)) {
if (csb[i][0] & GEN8_CTX_STATUS_LITE_RESTORE) {
if (execlists_check_remove_request(engine, csb[i][1]))
WARN(1, "Lite Restored request removed from queue\n");
} else
WARN(1, "Preemption without Lite Restore\n");
}
if (csb[i][0] & (GEN8_CTX_STATUS_ACTIVE_IDLE |
GEN8_CTX_STATUS_ELEMENT_SWITCH))
submit_contexts +=
execlists_check_remove_request(engine, csb[i][1]);
}
if (submit_contexts) {
if (!engine->disable_lite_restore_wa ||
(csb[i][0] & GEN8_CTX_STATUS_ACTIVE_IDLE))
execlists_context_unqueue(engine);
}
spin_unlock(&engine->execlist_lock);
if (unlikely(submit_contexts > 2))
DRM_ERROR("More than two context complete events?\n");
}
static void execlists_context_queue(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *engine = request->engine;
struct drm_i915_gem_request *cursor;
int num_elements = 0;
spin_lock_bh(&engine->execlist_lock);
list_for_each_entry(cursor, &engine->execlist_queue, execlist_link)
if (++num_elements > 2)
break;
if (num_elements > 2) {
struct drm_i915_gem_request *tail_req;
tail_req = list_last_entry(&engine->execlist_queue,
struct drm_i915_gem_request,
execlist_link);
if (request->ctx == tail_req->ctx) {
WARN(tail_req->elsp_submitted != 0,
"More than 2 already-submitted reqs queued\n");
list_del(&tail_req->execlist_link);
i915_gem_request_unreference(tail_req);
}
}
i915_gem_request_reference(request);
list_add_tail(&request->execlist_link, &engine->execlist_queue);
request->ctx_hw_id = request->ctx->hw_id;
if (num_elements == 0)
execlists_context_unqueue(engine);
spin_unlock_bh(&engine->execlist_lock);
}
static int logical_ring_invalidate_all_caches(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
uint32_t flush_domains;
int ret;
flush_domains = 0;
if (engine->gpu_caches_dirty)
flush_domains = I915_GEM_GPU_DOMAINS;
ret = engine->emit_flush(req, I915_GEM_GPU_DOMAINS, flush_domains);
if (ret)
return ret;
engine->gpu_caches_dirty = false;
return 0;
}
static int execlists_move_to_gpu(struct drm_i915_gem_request *req,
struct list_head *vmas)
{
const unsigned other_rings = ~intel_engine_flag(req->engine);
struct i915_vma *vma;
uint32_t flush_domains = 0;
bool flush_chipset = false;
int ret;
list_for_each_entry(vma, vmas, exec_list) {
struct drm_i915_gem_object *obj = vma->obj;
if (obj->active & other_rings) {
ret = i915_gem_object_sync(obj, req->engine, &req);
if (ret)
return ret;
}
if (obj->base.write_domain & I915_GEM_DOMAIN_CPU)
flush_chipset |= i915_gem_clflush_object(obj, false);
flush_domains |= obj->base.write_domain;
}
if (flush_domains & I915_GEM_DOMAIN_GTT)
wmb();
return logical_ring_invalidate_all_caches(req);
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
request->ringbuf = ce->ringbuf;
if (i915.enable_guc_submission) {
ret = i915_guc_wq_check_space(request);
if (ret)
return ret;
}
ret = intel_lr_context_pin(request->ctx, engine);
if (ret)
return ret;
ret = intel_ring_begin(request, 0);
if (ret)
goto err_unpin;
if (!ce->initialised) {
ret = engine->init_context(request);
if (ret)
goto err_unpin;
ce->initialised = true;
}
request->reserved_space -= EXECLISTS_REQUEST_SIZE;
return 0;
err_unpin:
intel_lr_context_unpin(request->ctx, engine);
return ret;
}
static int
intel_logical_ring_advance_and_submit(struct drm_i915_gem_request *request)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
struct intel_engine_cs *engine = request->engine;
intel_logical_ring_advance(ringbuf);
request->tail = ringbuf->tail;
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
request->previous_context = engine->last_context;
engine->last_context = request->ctx;
if (i915.enable_guc_submission)
i915_guc_submit(request);
else
execlists_context_queue(request);
return 0;
}
int intel_execlists_submission(struct i915_execbuffer_params *params,
struct drm_i915_gem_execbuffer2 *args,
struct list_head *vmas)
{
struct drm_device *dev = params->dev;
struct intel_engine_cs *engine = params->engine;
struct drm_i915_private *dev_priv = to_i915(dev);
struct intel_ringbuffer *ringbuf = params->ctx->engine[engine->id].ringbuf;
u64 exec_start;
int instp_mode;
u32 instp_mask;
int ret;
instp_mode = args->flags & I915_EXEC_CONSTANTS_MASK;
instp_mask = I915_EXEC_CONSTANTS_MASK;
switch (instp_mode) {
case I915_EXEC_CONSTANTS_REL_GENERAL:
case I915_EXEC_CONSTANTS_ABSOLUTE:
case I915_EXEC_CONSTANTS_REL_SURFACE:
if (instp_mode != 0 && engine != &dev_priv->engine[RCS]) {
DRM_DEBUG("non-0 rel constants mode on non-RCS\n");
return -EINVAL;
}
if (instp_mode != dev_priv->relative_constants_mode) {
if (instp_mode == I915_EXEC_CONSTANTS_REL_SURFACE) {
DRM_DEBUG("rel surface constants mode invalid on gen5+\n");
return -EINVAL;
}
instp_mask &= ~I915_EXEC_CONSTANTS_REL_SURFACE;
}
break;
default:
DRM_DEBUG("execbuf with unknown constants: %d\n", instp_mode);
return -EINVAL;
}
if (args->flags & I915_EXEC_GEN7_SOL_RESET) {
DRM_DEBUG("sol reset is gen7 only\n");
return -EINVAL;
}
ret = execlists_move_to_gpu(params->request, vmas);
if (ret)
return ret;
if (engine == &dev_priv->engine[RCS] &&
instp_mode != dev_priv->relative_constants_mode) {
ret = intel_ring_begin(params->request, 4);
if (ret)
return ret;
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_emit(ringbuf, MI_LOAD_REGISTER_IMM(1));
intel_logical_ring_emit_reg(ringbuf, INSTPM);
intel_logical_ring_emit(ringbuf, instp_mask << 16 | instp_mode);
intel_logical_ring_advance(ringbuf);
dev_priv->relative_constants_mode = instp_mode;
}
exec_start = params->batch_obj_vm_offset +
args->batch_start_offset;
ret = engine->emit_bb_start(params->request, exec_start, params->dispatch_flags);
if (ret)
return ret;
trace_i915_gem_ring_dispatch(params->request, params->dispatch_flags);
i915_gem_execbuffer_move_to_active(vmas, params->request);
return 0;
}
void intel_execlists_cancel_requests(struct intel_engine_cs *engine)
{
struct drm_i915_gem_request *req, *tmp;
LIST_HEAD(cancel_list);
WARN_ON(!mutex_is_locked(&engine->i915->drm.struct_mutex));
spin_lock_bh(&engine->execlist_lock);
list_replace_init(&engine->execlist_queue, &cancel_list);
spin_unlock_bh(&engine->execlist_lock);
list_for_each_entry_safe(req, tmp, &cancel_list, execlist_link) {
list_del(&req->execlist_link);
i915_gem_request_unreference(req);
}
}
void intel_logical_ring_stop(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
if (!intel_engine_initialized(engine))
return;
ret = intel_engine_idle(engine);
if (ret)
DRM_ERROR("failed to quiesce %s whilst cleaning up: %d\n",
engine->name, ret);
I915_WRITE_MODE(engine, _MASKED_BIT_ENABLE(STOP_RING));
if (intel_wait_for_register(dev_priv,
RING_MI_MODE(engine->mmio_base),
MODE_IDLE, MODE_IDLE,
1000)) {
DRM_ERROR("%s :timed out trying to stop ring\n", engine->name);
return;
}
I915_WRITE_MODE(engine, _MASKED_BIT_DISABLE(STOP_RING));
}
int logical_ring_flush_all_caches(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
int ret;
if (!engine->gpu_caches_dirty)
return 0;
ret = engine->emit_flush(req, 0, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
engine->gpu_caches_dirty = false;
return 0;
}
static int intel_lr_context_pin(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = ctx->i915;
struct intel_context *ce = &ctx->engine[engine->id];
void *vaddr;
u32 *lrc_reg_state;
int ret;
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
if (ce->pin_count++)
return 0;
ret = i915_gem_obj_ggtt_pin(ce->state, GEN8_LR_CONTEXT_ALIGN,
PIN_OFFSET_BIAS | GUC_WOPCM_TOP);
if (ret)
goto err;
vaddr = i915_gem_object_pin_map(ce->state);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
goto unpin_ctx_obj;
}
lrc_reg_state = vaddr + LRC_STATE_PN * PAGE_SIZE;
ret = intel_pin_and_map_ringbuffer_obj(dev_priv, ce->ringbuf);
if (ret)
goto unpin_map;
i915_gem_context_reference(ctx);
ce->lrc_vma = i915_gem_obj_to_ggtt(ce->state);
intel_lr_context_descriptor_update(ctx, engine);
lrc_reg_state[CTX_RING_BUFFER_START+1] = ce->ringbuf->vma->node.start;
ce->lrc_reg_state = lrc_reg_state;
ce->state->dirty = true;
if (i915.enable_guc_submission)
I915_WRITE(GEN8_GTCR, GEN8_GTCR_INVALIDATE);
return 0;
unpin_map:
i915_gem_object_unpin_map(ce->state);
unpin_ctx_obj:
i915_gem_object_ggtt_unpin(ce->state);
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
intel_unpin_ringbuffer_obj(ce->ringbuf);
i915_gem_object_unpin_map(ce->state);
i915_gem_object_ggtt_unpin(ce->state);
ce->lrc_vma = NULL;
ce->lrc_desc = 0;
ce->lrc_reg_state = NULL;
i915_gem_context_unreference(ctx);
}
static int intel_logical_ring_workarounds_emit(struct drm_i915_gem_request *req)
{
int ret, i;
struct intel_engine_cs *engine = req->engine;
struct intel_ringbuffer *ringbuf = req->ringbuf;
struct i915_workarounds *w = &req->i915->workarounds;
if (w->count == 0)
return 0;
engine->gpu_caches_dirty = true;
ret = logical_ring_flush_all_caches(req);
if (ret)
return ret;
ret = intel_ring_begin(req, w->count * 2 + 2);
if (ret)
return ret;
intel_logical_ring_emit(ringbuf, MI_LOAD_REGISTER_IMM(w->count));
for (i = 0; i < w->count; i++) {
intel_logical_ring_emit_reg(ringbuf, w->reg[i].addr);
intel_logical_ring_emit(ringbuf, w->reg[i].value);
}
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
engine->gpu_caches_dirty = true;
ret = logical_ring_flush_all_caches(req);
if (ret)
return ret;
return 0;
}
static inline int gen8_emit_flush_coherentl3_wa(struct intel_engine_cs *engine,
uint32_t *const batch,
uint32_t index)
{
struct drm_i915_private *dev_priv = engine->i915;
uint32_t l3sqc4_flush = (0x40400000 | GEN8_LQSC_FLUSH_COHERENT_LINES);
if (IS_SKL_REVID(dev_priv, 0, SKL_REVID_E0) ||
IS_KBL_REVID(dev_priv, 0, KBL_REVID_E0))
l3sqc4_flush |= GEN8_LQSC_RO_PERF_DIS;
wa_ctx_emit(batch, index, (MI_STORE_REGISTER_MEM_GEN8 |
MI_SRM_LRM_GLOBAL_GTT));
wa_ctx_emit_reg(batch, index, GEN8_L3SQCREG4);
wa_ctx_emit(batch, index, engine->scratch.gtt_offset + 256);
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
wa_ctx_emit(batch, index, engine->scratch.gtt_offset + 256);
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
uint32_t *const batch,
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
scratch_addr = engine->scratch.gtt_offset + 2*CACHELINE_BYTES;
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
uint32_t *const batch,
uint32_t *offset)
{
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_ENABLE);
wa_ctx_emit(batch, index, MI_BATCH_BUFFER_END);
return wa_ctx_end(wa_ctx, *offset = index, 1);
}
static int gen9_init_indirectctx_bb(struct intel_engine_cs *engine,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *const batch,
uint32_t *offset)
{
int ret;
struct drm_i915_private *dev_priv = engine->i915;
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
if (IS_SKL_REVID(dev_priv, 0, SKL_REVID_D0) ||
IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_DISABLE);
ret = gen8_emit_flush_coherentl3_wa(engine, batch, index);
if (ret < 0)
return ret;
index = ret;
if (IS_KBL_REVID(dev_priv, 0, KBL_REVID_A0)) {
uint32_t scratch_addr
= engine->scratch.gtt_offset + 2*CACHELINE_BYTES;
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
uint32_t *const batch,
uint32_t *offset)
{
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
if (IS_SKL_REVID(engine->i915, 0, SKL_REVID_B0) ||
IS_BXT_REVID(engine->i915, 0, BXT_REVID_A1)) {
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
if (IS_SKL_REVID(engine->i915, 0, SKL_REVID_D0) ||
IS_BXT_REVID(engine->i915, 0, BXT_REVID_A1))
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_ENABLE);
wa_ctx_emit(batch, index, MI_BATCH_BUFFER_END);
return wa_ctx_end(wa_ctx, *offset = index, 1);
}
static int lrc_setup_wa_ctx_obj(struct intel_engine_cs *engine, u32 size)
{
int ret;
engine->wa_ctx.obj = i915_gem_object_create(&engine->i915->drm,
PAGE_ALIGN(size));
if (IS_ERR(engine->wa_ctx.obj)) {
DRM_DEBUG_DRIVER("alloc LRC WA ctx backing obj failed.\n");
ret = PTR_ERR(engine->wa_ctx.obj);
engine->wa_ctx.obj = NULL;
return ret;
}
ret = i915_gem_obj_ggtt_pin(engine->wa_ctx.obj, PAGE_SIZE, 0);
if (ret) {
DRM_DEBUG_DRIVER("pin LRC WA ctx backing obj failed: %d\n",
ret);
drm_gem_object_unreference(&engine->wa_ctx.obj->base);
return ret;
}
return 0;
}
static void lrc_destroy_wa_ctx_obj(struct intel_engine_cs *engine)
{
if (engine->wa_ctx.obj) {
i915_gem_object_ggtt_unpin(engine->wa_ctx.obj);
drm_gem_object_unreference(&engine->wa_ctx.obj->base);
engine->wa_ctx.obj = NULL;
}
}
static int intel_init_workaround_bb(struct intel_engine_cs *engine)
{
int ret;
uint32_t *batch;
uint32_t offset;
struct page *page;
struct i915_ctx_workarounds *wa_ctx = &engine->wa_ctx;
WARN_ON(engine->id != RCS);
if (INTEL_GEN(engine->i915) > 9) {
DRM_ERROR("WA batch buffer is not initialized for Gen%d\n",
INTEL_GEN(engine->i915));
return 0;
}
if (engine->scratch.obj == NULL) {
DRM_ERROR("scratch page not allocated for %s\n", engine->name);
return -EINVAL;
}
ret = lrc_setup_wa_ctx_obj(engine, PAGE_SIZE);
if (ret) {
DRM_DEBUG_DRIVER("Failed to setup context WA page: %d\n", ret);
return ret;
}
page = i915_gem_object_get_dirty_page(wa_ctx->obj, 0);
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
(u32)engine->status_page.gfx_addr);
POSTING_READ(RING_HWS_PGA(engine->mmio_base));
}
static int gen8_init_common_ring(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
unsigned int next_context_status_buffer_hw;
lrc_init_hws(engine);
I915_WRITE_IMR(engine,
~(engine->irq_enable_mask | engine->irq_keep_mask));
I915_WRITE(RING_HWSTAM(engine->mmio_base), 0xffffffff);
I915_WRITE(RING_MODE_GEN7(engine),
_MASKED_BIT_DISABLE(GFX_REPLAY_MODE) |
_MASKED_BIT_ENABLE(GFX_RUN_LIST_ENABLE));
POSTING_READ(RING_MODE_GEN7(engine));
next_context_status_buffer_hw =
GEN8_CSB_WRITE_PTR(I915_READ(RING_CONTEXT_STATUS_PTR(engine)));
if (next_context_status_buffer_hw == GEN8_CSB_PTR_MASK)
next_context_status_buffer_hw = (GEN8_CSB_ENTRIES - 1);
engine->next_context_status_buffer = next_context_status_buffer_hw;
DRM_DEBUG_DRIVER("Execlists enabled for %s\n", engine->name);
intel_engine_init_hangcheck(engine);
return intel_mocs_init_engine(engine);
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
static int intel_logical_ring_emit_pdps(struct drm_i915_gem_request *req)
{
struct i915_hw_ppgtt *ppgtt = req->ctx->ppgtt;
struct intel_engine_cs *engine = req->engine;
struct intel_ringbuffer *ringbuf = req->ringbuf;
const int num_lri_cmds = GEN8_LEGACY_PDPES * 2;
int i, ret;
ret = intel_ring_begin(req, num_lri_cmds * 2 + 2);
if (ret)
return ret;
intel_logical_ring_emit(ringbuf, MI_LOAD_REGISTER_IMM(num_lri_cmds));
for (i = GEN8_LEGACY_PDPES - 1; i >= 0; i--) {
const dma_addr_t pd_daddr = i915_page_dir_dma_addr(ppgtt, i);
intel_logical_ring_emit_reg(ringbuf,
GEN8_RING_PDP_UDW(engine, i));
intel_logical_ring_emit(ringbuf, upper_32_bits(pd_daddr));
intel_logical_ring_emit_reg(ringbuf,
GEN8_RING_PDP_LDW(engine, i));
intel_logical_ring_emit(ringbuf, lower_32_bits(pd_daddr));
}
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
return 0;
}
static int gen8_emit_bb_start(struct drm_i915_gem_request *req,
u64 offset, unsigned dispatch_flags)
{
struct intel_ringbuffer *ringbuf = req->ringbuf;
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
intel_logical_ring_emit(ringbuf, MI_BATCH_BUFFER_START_GEN8 |
(ppgtt<<8) |
(dispatch_flags & I915_DISPATCH_RS ?
MI_BATCH_RESOURCE_STREAMER : 0));
intel_logical_ring_emit(ringbuf, lower_32_bits(offset));
intel_logical_ring_emit(ringbuf, upper_32_bits(offset));
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
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
static int gen8_emit_flush(struct drm_i915_gem_request *request,
u32 invalidate_domains,
u32 unused)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
struct intel_engine_cs *engine = ringbuf->engine;
struct drm_i915_private *dev_priv = request->i915;
uint32_t cmd;
int ret;
ret = intel_ring_begin(request, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW + 1;
cmd |= MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
if (invalidate_domains & I915_GEM_GPU_DOMAINS) {
cmd |= MI_INVALIDATE_TLB;
if (engine == &dev_priv->engine[VCS])
cmd |= MI_INVALIDATE_BSD;
}
intel_logical_ring_emit(ringbuf, cmd);
intel_logical_ring_emit(ringbuf,
I915_GEM_HWS_SCRATCH_ADDR |
MI_FLUSH_DW_USE_GTT);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_advance(ringbuf);
return 0;
}
static int gen8_emit_flush_render(struct drm_i915_gem_request *request,
u32 invalidate_domains,
u32 flush_domains)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
struct intel_engine_cs *engine = ringbuf->engine;
u32 scratch_addr = engine->scratch.gtt_offset + 2 * CACHELINE_BYTES;
bool vf_flush_wa = false, dc_flush_wa = false;
u32 flags = 0;
int ret;
int len;
flags |= PIPE_CONTROL_CS_STALL;
if (flush_domains) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
flags |= PIPE_CONTROL_DC_FLUSH_ENABLE;
flags |= PIPE_CONTROL_FLUSH_ENABLE;
}
if (invalidate_domains) {
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
intel_logical_ring_emit(ringbuf, GFX_OP_PIPE_CONTROL(6));
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
}
if (dc_flush_wa) {
intel_logical_ring_emit(ringbuf, GFX_OP_PIPE_CONTROL(6));
intel_logical_ring_emit(ringbuf, PIPE_CONTROL_DC_FLUSH_ENABLE);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
}
intel_logical_ring_emit(ringbuf, GFX_OP_PIPE_CONTROL(6));
intel_logical_ring_emit(ringbuf, flags);
intel_logical_ring_emit(ringbuf, scratch_addr);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
if (dc_flush_wa) {
intel_logical_ring_emit(ringbuf, GFX_OP_PIPE_CONTROL(6));
intel_logical_ring_emit(ringbuf, PIPE_CONTROL_CS_STALL);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
}
intel_logical_ring_advance(ringbuf);
return 0;
}
static void bxt_a_seqno_barrier(struct intel_engine_cs *engine)
{
intel_flush_status_page(engine, I915_GEM_HWS_INDEX);
}
static int gen8_emit_request(struct drm_i915_gem_request *request)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
int ret;
ret = intel_ring_begin(request, 6 + WA_TAIL_DWORDS);
if (ret)
return ret;
BUILD_BUG_ON(I915_GEM_HWS_INDEX_ADDR & (1 << 5));
intel_logical_ring_emit(ringbuf,
(MI_FLUSH_DW + 1) | MI_FLUSH_DW_OP_STOREDW);
intel_logical_ring_emit(ringbuf,
intel_hws_seqno_address(request->engine) |
MI_FLUSH_DW_USE_GTT);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, request->seqno);
intel_logical_ring_emit(ringbuf, MI_USER_INTERRUPT);
intel_logical_ring_emit(ringbuf, MI_NOOP);
return intel_logical_ring_advance_and_submit(request);
}
static int gen8_emit_request_render(struct drm_i915_gem_request *request)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
int ret;
ret = intel_ring_begin(request, 8 + WA_TAIL_DWORDS);
if (ret)
return ret;
BUILD_BUG_ON(I915_GEM_HWS_INDEX & 1);
intel_logical_ring_emit(ringbuf, GFX_OP_PIPE_CONTROL(6));
intel_logical_ring_emit(ringbuf,
(PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE));
intel_logical_ring_emit(ringbuf,
intel_hws_seqno_address(request->engine));
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, i915_gem_request_get_seqno(request));
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, MI_USER_INTERRUPT);
intel_logical_ring_emit(ringbuf, MI_NOOP);
return intel_logical_ring_advance_and_submit(request);
}
static int intel_lr_context_render_state_init(struct drm_i915_gem_request *req)
{
struct render_state so;
int ret;
ret = i915_gem_render_state_prepare(req->engine, &so);
if (ret)
return ret;
if (so.rodata == NULL)
return 0;
ret = req->engine->emit_bb_start(req, so.ggtt_offset,
I915_DISPATCH_SECURE);
if (ret)
goto out;
ret = req->engine->emit_bb_start(req,
(so.ggtt_offset + so.aux_batch_offset),
I915_DISPATCH_SECURE);
if (ret)
goto out;
i915_vma_move_to_active(i915_gem_obj_to_ggtt(so.obj), req);
out:
i915_gem_render_state_fini(&so);
return ret;
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
return intel_lr_context_render_state_init(req);
}
void intel_logical_ring_cleanup(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv;
if (!intel_engine_initialized(engine))
return;
if (WARN_ON(test_bit(TASKLET_STATE_SCHED, &engine->irq_tasklet.state)))
tasklet_kill(&engine->irq_tasklet);
dev_priv = engine->i915;
if (engine->buffer) {
intel_logical_ring_stop(engine);
WARN_ON((I915_READ_MODE(engine) & MODE_IDLE) == 0);
}
if (engine->cleanup)
engine->cleanup(engine);
i915_cmd_parser_fini_ring(engine);
i915_gem_batch_pool_fini(&engine->batch_pool);
intel_engine_fini_breadcrumbs(engine);
if (engine->status_page.obj) {
i915_gem_object_unpin_map(engine->status_page.obj);
engine->status_page.obj = NULL;
}
intel_lr_context_unpin(dev_priv->kernel_context, engine);
engine->idle_lite_restore_wa = 0;
engine->disable_lite_restore_wa = false;
engine->ctx_desc_template = 0;
lrc_destroy_wa_ctx_obj(engine);
engine->i915 = NULL;
}
static void
logical_ring_default_vfuncs(struct intel_engine_cs *engine)
{
engine->init_hw = gen8_init_common_ring;
engine->emit_request = gen8_emit_request;
engine->emit_flush = gen8_emit_flush;
engine->irq_enable = gen8_logical_ring_enable_irq;
engine->irq_disable = gen8_logical_ring_disable_irq;
engine->emit_bb_start = gen8_emit_bb_start;
if (IS_BXT_REVID(engine->i915, 0, BXT_REVID_A1))
engine->irq_seqno_barrier = bxt_a_seqno_barrier;
}
static inline void
logical_ring_default_irqs(struct intel_engine_cs *engine, unsigned shift)
{
engine->irq_enable_mask = GT_RENDER_USER_INTERRUPT << shift;
engine->irq_keep_mask = GT_CONTEXT_SWITCH_INTERRUPT << shift;
}
static int
lrc_setup_hws(struct intel_engine_cs *engine,
struct drm_i915_gem_object *dctx_obj)
{
void *hws;
engine->status_page.gfx_addr = i915_gem_obj_ggtt_offset(dctx_obj) +
LRC_PPHWSP_PN * PAGE_SIZE;
hws = i915_gem_object_pin_map(dctx_obj);
if (IS_ERR(hws))
return PTR_ERR(hws);
engine->status_page.page_addr = hws + LRC_PPHWSP_PN * PAGE_SIZE;
engine->status_page.obj = dctx_obj;
return 0;
}
static int
logical_ring_init(struct intel_engine_cs *engine)
{
struct i915_gem_context *dctx = engine->i915->kernel_context;
int ret;
ret = intel_engine_init_breadcrumbs(engine);
if (ret)
goto error;
ret = i915_cmd_parser_init_ring(engine);
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
static int logical_render_ring_init(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
int ret;
if (HAS_L3_DPF(dev_priv))
engine->irq_keep_mask |= GT_RENDER_L3_PARITY_ERROR_INTERRUPT;
if (INTEL_GEN(dev_priv) >= 9)
engine->init_hw = gen9_init_render_ring;
else
engine->init_hw = gen8_init_render_ring;
engine->init_context = gen8_init_rcs_context;
engine->cleanup = intel_fini_pipe_control;
engine->emit_flush = gen8_emit_flush_render;
engine->emit_request = gen8_emit_request_render;
ret = intel_init_pipe_control(engine, 4096);
if (ret)
return ret;
ret = intel_init_workaround_bb(engine);
if (ret) {
DRM_ERROR("WA batch buffer initialization failed: %d\n",
ret);
}
ret = logical_ring_init(engine);
if (ret) {
lrc_destroy_wa_ctx_obj(engine);
}
return ret;
}
static struct intel_engine_cs *
logical_ring_setup(struct drm_i915_private *dev_priv, enum intel_engine_id id)
{
const struct logical_ring_info *info = &logical_rings[id];
struct intel_engine_cs *engine = &dev_priv->engine[id];
enum forcewake_domains fw_domains;
engine->id = id;
engine->name = info->name;
engine->exec_id = info->exec_id;
engine->guc_id = info->guc_id;
engine->mmio_base = info->mmio_base;
engine->i915 = dev_priv;
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
INIT_LIST_HEAD(&engine->active_list);
INIT_LIST_HEAD(&engine->request_list);
INIT_LIST_HEAD(&engine->buffers);
INIT_LIST_HEAD(&engine->execlist_queue);
spin_lock_init(&engine->execlist_lock);
tasklet_init(&engine->irq_tasklet,
intel_lrc_irq_handler, (unsigned long)engine);
logical_ring_init_platform_invariants(engine);
logical_ring_default_vfuncs(engine);
logical_ring_default_irqs(engine, info->irq_shift);
intel_engine_init_hangcheck(engine);
i915_gem_batch_pool_init(&dev_priv->drm, &engine->batch_pool);
return engine;
}
int intel_logical_rings_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
unsigned int mask = 0;
unsigned int i;
int ret;
WARN_ON(INTEL_INFO(dev_priv)->ring_mask &
GENMASK(sizeof(mask) * BITS_PER_BYTE - 1, I915_NUM_ENGINES));
for (i = 0; i < ARRAY_SIZE(logical_rings); i++) {
if (!HAS_ENGINE(dev_priv, i))
continue;
if (!logical_rings[i].init)
continue;
ret = logical_rings[i].init(logical_ring_setup(dev_priv, i));
if (ret)
goto cleanup;
mask |= ENGINE_MASK(i);
}
if (WARN_ON(mask != INTEL_INFO(dev_priv)->ring_mask)) {
struct intel_device_info *info =
(struct intel_device_info *)&dev_priv->info;
info->ring_mask = mask;
}
return 0;
cleanup:
for (i = 0; i < I915_NUM_ENGINES; i++)
intel_logical_ring_cleanup(&dev_priv->engine[i]);
return ret;
}
static u32
make_rpcs(struct drm_i915_private *dev_priv)
{
u32 rpcs = 0;
if (INTEL_GEN(dev_priv) < 9)
return 0;
if (INTEL_INFO(dev_priv)->has_slice_pg) {
rpcs |= GEN8_RPCS_S_CNT_ENABLE;
rpcs |= INTEL_INFO(dev_priv)->slice_total <<
GEN8_RPCS_S_CNT_SHIFT;
rpcs |= GEN8_RPCS_ENABLE;
}
if (INTEL_INFO(dev_priv)->has_subslice_pg) {
rpcs |= GEN8_RPCS_SS_CNT_ENABLE;
rpcs |= INTEL_INFO(dev_priv)->subslice_per_slice <<
GEN8_RPCS_SS_CNT_SHIFT;
rpcs |= GEN8_RPCS_ENABLE;
}
if (INTEL_INFO(dev_priv)->has_eu_pg) {
rpcs |= INTEL_INFO(dev_priv)->eu_per_subslice <<
GEN8_RPCS_EU_MIN_SHIFT;
rpcs |= INTEL_INFO(dev_priv)->eu_per_subslice <<
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
static int
populate_lr_context(struct i915_gem_context *ctx,
struct drm_i915_gem_object *ctx_obj,
struct intel_engine_cs *engine,
struct intel_ringbuffer *ringbuf)
{
struct drm_i915_private *dev_priv = ctx->i915;
struct i915_hw_ppgtt *ppgtt = ctx->ppgtt;
void *vaddr;
u32 *reg_state;
int ret;
if (!ppgtt)
ppgtt = dev_priv->mm.aliasing_ppgtt;
ret = i915_gem_object_set_to_cpu_domain(ctx_obj, true);
if (ret) {
DRM_DEBUG_DRIVER("Could not set to CPU domain\n");
return ret;
}
vaddr = i915_gem_object_pin_map(ctx_obj);
if (IS_ERR(vaddr)) {
ret = PTR_ERR(vaddr);
DRM_DEBUG_DRIVER("Could not map object pages! (%d)\n", ret);
return ret;
}
ctx_obj->dirty = true;
reg_state = vaddr + LRC_STATE_PN * PAGE_SIZE;
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
((ringbuf->size - PAGE_SIZE) & RING_NR_PAGES) | RING_VALID);
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
if (engine->wa_ctx.obj) {
struct i915_ctx_workarounds *wa_ctx = &engine->wa_ctx;
uint32_t ggtt_offset = i915_gem_obj_ggtt_offset(wa_ctx->obj);
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
uint32_t context_size;
struct intel_ringbuffer *ringbuf;
int ret;
WARN_ON(ce->state);
context_size = round_up(intel_lr_context_size(engine), 4096);
context_size += PAGE_SIZE * LRC_PPHWSP_PN;
ctx_obj = i915_gem_object_create(&ctx->i915->drm, context_size);
if (IS_ERR(ctx_obj)) {
DRM_DEBUG_DRIVER("Alloc LRC backing obj failed.\n");
return PTR_ERR(ctx_obj);
}
ringbuf = intel_engine_create_ringbuffer(engine, ctx->ring_size);
if (IS_ERR(ringbuf)) {
ret = PTR_ERR(ringbuf);
goto error_deref_obj;
}
ret = populate_lr_context(ctx, ctx_obj, engine, ringbuf);
if (ret) {
DRM_DEBUG_DRIVER("Failed to populate LRC: %d\n", ret);
goto error_ringbuf;
}
ce->ringbuf = ringbuf;
ce->state = ctx_obj;
ce->initialised = engine->init_context == NULL;
return 0;
error_ringbuf:
intel_ringbuffer_free(ringbuf);
error_deref_obj:
drm_gem_object_unreference(&ctx_obj->base);
ce->ringbuf = NULL;
ce->state = NULL;
return ret;
}
void intel_lr_context_reset(struct drm_i915_private *dev_priv,
struct i915_gem_context *ctx)
{
struct intel_engine_cs *engine;
for_each_engine(engine, dev_priv) {
struct intel_context *ce = &ctx->engine[engine->id];
struct drm_i915_gem_object *ctx_obj = ce->state;
void *vaddr;
uint32_t *reg_state;
if (!ctx_obj)
continue;
vaddr = i915_gem_object_pin_map(ctx_obj);
if (WARN_ON(IS_ERR(vaddr)))
continue;
reg_state = vaddr + LRC_STATE_PN * PAGE_SIZE;
ctx_obj->dirty = true;
reg_state[CTX_RING_HEAD+1] = 0;
reg_state[CTX_RING_TAIL+1] = 0;
i915_gem_object_unpin_map(ctx_obj);
ce->ringbuf->head = 0;
ce->ringbuf->tail = 0;
}
}
