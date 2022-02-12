int intel_sanitize_enable_execlists(struct drm_device *dev, int enable_execlists)
{
WARN_ON(i915.enable_ppgtt == -1);
if (HAS_LOGICAL_RING_CONTEXTS(dev) && intel_vgpu_active(dev))
return 1;
if (INTEL_INFO(dev)->gen >= 9)
return 1;
if (enable_execlists == 0)
return 0;
if (HAS_LOGICAL_RING_CONTEXTS(dev) && USES_PPGTT(dev) &&
i915.use_mmio_flip >= 0)
return 1;
return 0;
}
static void
logical_ring_init_platform_invariants(struct intel_engine_cs *ring)
{
struct drm_device *dev = ring->dev;
ring->disable_lite_restore_wa = (IS_SKL_REVID(dev, 0, SKL_REVID_B0) ||
IS_BXT_REVID(dev, 0, BXT_REVID_A1)) &&
(ring->id == VCS || ring->id == VCS2);
ring->ctx_desc_template = GEN8_CTX_VALID;
ring->ctx_desc_template |= GEN8_CTX_ADDRESSING_MODE(dev) <<
GEN8_CTX_ADDRESSING_MODE_SHIFT;
if (IS_GEN8(dev))
ring->ctx_desc_template |= GEN8_CTX_L3LLC_COHERENT;
ring->ctx_desc_template |= GEN8_CTX_PRIVILEGE;
if (ring->disable_lite_restore_wa)
ring->ctx_desc_template |= GEN8_CTX_FORCE_RESTORE;
}
static void
intel_lr_context_descriptor_update(struct intel_context *ctx,
struct intel_engine_cs *ring)
{
uint64_t lrca, desc;
lrca = ctx->engine[ring->id].lrc_vma->node.start +
LRC_PPHWSP_PN * PAGE_SIZE;
desc = ring->ctx_desc_template;
desc |= lrca;
desc |= (lrca >> PAGE_SHIFT) << GEN8_CTX_ID_SHIFT;
ctx->engine[ring->id].lrc_desc = desc;
}
uint64_t intel_lr_context_descriptor(struct intel_context *ctx,
struct intel_engine_cs *ring)
{
return ctx->engine[ring->id].lrc_desc;
}
u32 intel_execlists_ctx_id(struct intel_context *ctx,
struct intel_engine_cs *ring)
{
return intel_lr_context_descriptor(ctx, ring) >> GEN8_CTX_ID_SHIFT;
}
static void execlists_elsp_write(struct drm_i915_gem_request *rq0,
struct drm_i915_gem_request *rq1)
{
struct intel_engine_cs *ring = rq0->ring;
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint64_t desc[2];
if (rq1) {
desc[1] = intel_lr_context_descriptor(rq1->ctx, rq1->ring);
rq1->elsp_submitted++;
} else {
desc[1] = 0;
}
desc[0] = intel_lr_context_descriptor(rq0->ctx, rq0->ring);
rq0->elsp_submitted++;
spin_lock(&dev_priv->uncore.lock);
intel_uncore_forcewake_get__locked(dev_priv, FORCEWAKE_ALL);
I915_WRITE_FW(RING_ELSP(ring), upper_32_bits(desc[1]));
I915_WRITE_FW(RING_ELSP(ring), lower_32_bits(desc[1]));
I915_WRITE_FW(RING_ELSP(ring), upper_32_bits(desc[0]));
I915_WRITE_FW(RING_ELSP(ring), lower_32_bits(desc[0]));
POSTING_READ_FW(RING_EXECLIST_STATUS_LO(ring));
intel_uncore_forcewake_put__locked(dev_priv, FORCEWAKE_ALL);
spin_unlock(&dev_priv->uncore.lock);
}
static int execlists_update_context(struct drm_i915_gem_request *rq)
{
struct intel_engine_cs *ring = rq->ring;
struct i915_hw_ppgtt *ppgtt = rq->ctx->ppgtt;
uint32_t *reg_state = rq->ctx->engine[ring->id].lrc_reg_state;
reg_state[CTX_RING_TAIL+1] = rq->tail;
if (ppgtt && !USES_FULL_48BIT_PPGTT(ppgtt->base.dev)) {
ASSIGN_CTX_PDP(ppgtt, reg_state, 3);
ASSIGN_CTX_PDP(ppgtt, reg_state, 2);
ASSIGN_CTX_PDP(ppgtt, reg_state, 1);
ASSIGN_CTX_PDP(ppgtt, reg_state, 0);
}
return 0;
}
static void execlists_submit_requests(struct drm_i915_gem_request *rq0,
struct drm_i915_gem_request *rq1)
{
execlists_update_context(rq0);
if (rq1)
execlists_update_context(rq1);
execlists_elsp_write(rq0, rq1);
}
static void execlists_context_unqueue(struct intel_engine_cs *ring)
{
struct drm_i915_gem_request *req0 = NULL, *req1 = NULL;
struct drm_i915_gem_request *cursor = NULL, *tmp = NULL;
assert_spin_locked(&ring->execlist_lock);
WARN_ON(!intel_irqs_enabled(ring->dev->dev_private));
if (list_empty(&ring->execlist_queue))
return;
list_for_each_entry_safe(cursor, tmp, &ring->execlist_queue,
execlist_link) {
if (!req0) {
req0 = cursor;
} else if (req0->ctx == cursor->ctx) {
cursor->elsp_submitted = req0->elsp_submitted;
list_move_tail(&req0->execlist_link,
&ring->execlist_retired_req_list);
req0 = cursor;
} else {
req1 = cursor;
break;
}
}
if (IS_GEN8(ring->dev) || IS_GEN9(ring->dev)) {
if (req0->elsp_submitted) {
struct intel_ringbuffer *ringbuf;
ringbuf = req0->ctx->engine[ring->id].ringbuf;
req0->tail += 8;
req0->tail &= ringbuf->size - 1;
}
}
WARN_ON(req1 && req1->elsp_submitted);
execlists_submit_requests(req0, req1);
}
static bool execlists_check_remove_request(struct intel_engine_cs *ring,
u32 request_id)
{
struct drm_i915_gem_request *head_req;
assert_spin_locked(&ring->execlist_lock);
head_req = list_first_entry_or_null(&ring->execlist_queue,
struct drm_i915_gem_request,
execlist_link);
if (head_req != NULL) {
if (intel_execlists_ctx_id(head_req->ctx, ring) == request_id) {
WARN(head_req->elsp_submitted == 0,
"Never submitted head request\n");
if (--head_req->elsp_submitted <= 0) {
list_move_tail(&head_req->execlist_link,
&ring->execlist_retired_req_list);
return true;
}
}
}
return false;
}
static void get_context_status(struct intel_engine_cs *ring,
u8 read_pointer,
u32 *status, u32 *context_id)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
if (WARN_ON(read_pointer >= GEN8_CSB_ENTRIES))
return;
*status = I915_READ(RING_CONTEXT_STATUS_BUF_LO(ring, read_pointer));
*context_id = I915_READ(RING_CONTEXT_STATUS_BUF_HI(ring, read_pointer));
}
void intel_lrc_irq_handler(struct intel_engine_cs *ring)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
u32 status_pointer;
u8 read_pointer;
u8 write_pointer;
u32 status = 0;
u32 status_id;
u32 submit_contexts = 0;
status_pointer = I915_READ(RING_CONTEXT_STATUS_PTR(ring));
read_pointer = ring->next_context_status_buffer;
write_pointer = GEN8_CSB_WRITE_PTR(status_pointer);
if (read_pointer > write_pointer)
write_pointer += GEN8_CSB_ENTRIES;
spin_lock(&ring->execlist_lock);
while (read_pointer < write_pointer) {
get_context_status(ring, ++read_pointer % GEN8_CSB_ENTRIES,
&status, &status_id);
if (status & GEN8_CTX_STATUS_IDLE_ACTIVE)
continue;
if (status & GEN8_CTX_STATUS_PREEMPTED) {
if (status & GEN8_CTX_STATUS_LITE_RESTORE) {
if (execlists_check_remove_request(ring, status_id))
WARN(1, "Lite Restored request removed from queue\n");
} else
WARN(1, "Preemption without Lite Restore\n");
}
if ((status & GEN8_CTX_STATUS_ACTIVE_IDLE) ||
(status & GEN8_CTX_STATUS_ELEMENT_SWITCH)) {
if (execlists_check_remove_request(ring, status_id))
submit_contexts++;
}
}
if (ring->disable_lite_restore_wa) {
if ((status & GEN8_CTX_STATUS_ACTIVE_IDLE) &&
(submit_contexts != 0))
execlists_context_unqueue(ring);
} else if (submit_contexts != 0) {
execlists_context_unqueue(ring);
}
spin_unlock(&ring->execlist_lock);
if (unlikely(submit_contexts > 2))
DRM_ERROR("More than two context complete events?\n");
ring->next_context_status_buffer = write_pointer % GEN8_CSB_ENTRIES;
I915_WRITE(RING_CONTEXT_STATUS_PTR(ring),
_MASKED_FIELD(GEN8_CSB_READ_PTR_MASK,
ring->next_context_status_buffer << 8));
}
static int execlists_context_queue(struct drm_i915_gem_request *request)
{
struct intel_engine_cs *ring = request->ring;
struct drm_i915_gem_request *cursor;
int num_elements = 0;
if (request->ctx != request->i915->kernel_context)
intel_lr_context_pin(request->ctx, ring);
i915_gem_request_reference(request);
spin_lock_irq(&ring->execlist_lock);
list_for_each_entry(cursor, &ring->execlist_queue, execlist_link)
if (++num_elements > 2)
break;
if (num_elements > 2) {
struct drm_i915_gem_request *tail_req;
tail_req = list_last_entry(&ring->execlist_queue,
struct drm_i915_gem_request,
execlist_link);
if (request->ctx == tail_req->ctx) {
WARN(tail_req->elsp_submitted != 0,
"More than 2 already-submitted reqs queued\n");
list_move_tail(&tail_req->execlist_link,
&ring->execlist_retired_req_list);
}
}
list_add_tail(&request->execlist_link, &ring->execlist_queue);
if (num_elements == 0)
execlists_context_unqueue(ring);
spin_unlock_irq(&ring->execlist_lock);
return 0;
}
static int logical_ring_invalidate_all_caches(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *ring = req->ring;
uint32_t flush_domains;
int ret;
flush_domains = 0;
if (ring->gpu_caches_dirty)
flush_domains = I915_GEM_GPU_DOMAINS;
ret = ring->emit_flush(req, I915_GEM_GPU_DOMAINS, flush_domains);
if (ret)
return ret;
ring->gpu_caches_dirty = false;
return 0;
}
static int execlists_move_to_gpu(struct drm_i915_gem_request *req,
struct list_head *vmas)
{
const unsigned other_rings = ~intel_ring_flag(req->ring);
struct i915_vma *vma;
uint32_t flush_domains = 0;
bool flush_chipset = false;
int ret;
list_for_each_entry(vma, vmas, exec_list) {
struct drm_i915_gem_object *obj = vma->obj;
if (obj->active & other_rings) {
ret = i915_gem_object_sync(obj, req->ring, &req);
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
int ret = 0;
request->ringbuf = request->ctx->engine[request->ring->id].ringbuf;
if (i915.enable_guc_submission) {
struct intel_guc *guc = &request->i915->guc;
ret = i915_guc_wq_check_space(guc->execbuf_client);
if (ret)
return ret;
}
if (request->ctx != request->i915->kernel_context)
ret = intel_lr_context_pin(request->ctx, request->ring);
return ret;
}
static int logical_ring_wait_for_space(struct drm_i915_gem_request *req,
int bytes)
{
struct intel_ringbuffer *ringbuf = req->ringbuf;
struct intel_engine_cs *ring = req->ring;
struct drm_i915_gem_request *target;
unsigned space;
int ret;
if (intel_ring_space(ringbuf) >= bytes)
return 0;
WARN_ON(ringbuf->reserved_in_use);
list_for_each_entry(target, &ring->request_list, list) {
if (target->ringbuf != ringbuf)
continue;
space = __intel_ring_space(target->postfix, ringbuf->tail,
ringbuf->size);
if (space >= bytes)
break;
}
if (WARN_ON(&target->list == &ring->request_list))
return -ENOSPC;
ret = i915_wait_request(target);
if (ret)
return ret;
ringbuf->space = space;
return 0;
}
static int
intel_logical_ring_advance_and_submit(struct drm_i915_gem_request *request)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
struct drm_i915_private *dev_priv = request->i915;
struct intel_engine_cs *engine = request->ring;
intel_logical_ring_advance(ringbuf);
request->tail = ringbuf->tail;
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
if (intel_ring_stopped(engine))
return 0;
if (engine->last_context != request->ctx) {
if (engine->last_context)
intel_lr_context_unpin(engine->last_context, engine);
if (request->ctx != request->i915->kernel_context) {
intel_lr_context_pin(request->ctx, engine);
engine->last_context = request->ctx;
} else {
engine->last_context = NULL;
}
}
if (dev_priv->guc.execbuf_client)
i915_guc_submit(dev_priv->guc.execbuf_client, request);
else
execlists_context_queue(request);
return 0;
}
static void __wrap_ring_buffer(struct intel_ringbuffer *ringbuf)
{
uint32_t __iomem *virt;
int rem = ringbuf->size - ringbuf->tail;
virt = ringbuf->virtual_start + ringbuf->tail;
rem /= 4;
while (rem--)
iowrite32(MI_NOOP, virt++);
ringbuf->tail = 0;
intel_ring_update_space(ringbuf);
}
static int logical_ring_prepare(struct drm_i915_gem_request *req, int bytes)
{
struct intel_ringbuffer *ringbuf = req->ringbuf;
int remain_usable = ringbuf->effective_size - ringbuf->tail;
int remain_actual = ringbuf->size - ringbuf->tail;
int ret, total_bytes, wait_bytes = 0;
bool need_wrap = false;
if (ringbuf->reserved_in_use)
total_bytes = bytes;
else
total_bytes = bytes + ringbuf->reserved_size;
if (unlikely(bytes > remain_usable)) {
wait_bytes = remain_actual + total_bytes;
need_wrap = true;
} else {
if (unlikely(total_bytes > remain_usable)) {
wait_bytes = remain_actual + ringbuf->reserved_size;
} else if (total_bytes > ringbuf->space) {
wait_bytes = total_bytes;
}
}
if (wait_bytes) {
ret = logical_ring_wait_for_space(req, wait_bytes);
if (unlikely(ret))
return ret;
if (need_wrap)
__wrap_ring_buffer(ringbuf);
}
return 0;
}
int intel_logical_ring_begin(struct drm_i915_gem_request *req, int num_dwords)
{
struct drm_i915_private *dev_priv;
int ret;
WARN_ON(req == NULL);
dev_priv = req->ring->dev->dev_private;
ret = i915_gem_check_wedge(&dev_priv->gpu_error,
dev_priv->mm.interruptible);
if (ret)
return ret;
ret = logical_ring_prepare(req, num_dwords * sizeof(uint32_t));
if (ret)
return ret;
req->ringbuf->space -= num_dwords * sizeof(uint32_t);
return 0;
}
int intel_logical_ring_reserve_space(struct drm_i915_gem_request *request)
{
intel_ring_reserved_space_reserve(request->ringbuf, MIN_SPACE_FOR_ADD_REQUEST);
return intel_logical_ring_begin(request, 0);
}
int intel_execlists_submission(struct i915_execbuffer_params *params,
struct drm_i915_gem_execbuffer2 *args,
struct list_head *vmas)
{
struct drm_device *dev = params->dev;
struct intel_engine_cs *ring = params->ring;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ringbuffer *ringbuf = params->ctx->engine[ring->id].ringbuf;
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
if (instp_mode != 0 && ring != &dev_priv->ring[RCS]) {
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
if (ring == &dev_priv->ring[RCS] &&
instp_mode != dev_priv->relative_constants_mode) {
ret = intel_logical_ring_begin(params->request, 4);
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
ret = ring->emit_bb_start(params->request, exec_start, params->dispatch_flags);
if (ret)
return ret;
trace_i915_gem_ring_dispatch(params->request, params->dispatch_flags);
i915_gem_execbuffer_move_to_active(vmas, params->request);
i915_gem_execbuffer_retire_commands(params);
return 0;
}
void intel_execlists_retire_requests(struct intel_engine_cs *ring)
{
struct drm_i915_gem_request *req, *tmp;
struct list_head retired_list;
WARN_ON(!mutex_is_locked(&ring->dev->struct_mutex));
if (list_empty(&ring->execlist_retired_req_list))
return;
INIT_LIST_HEAD(&retired_list);
spin_lock_irq(&ring->execlist_lock);
list_replace_init(&ring->execlist_retired_req_list, &retired_list);
spin_unlock_irq(&ring->execlist_lock);
list_for_each_entry_safe(req, tmp, &retired_list, execlist_link) {
struct intel_context *ctx = req->ctx;
struct drm_i915_gem_object *ctx_obj =
ctx->engine[ring->id].state;
if (ctx_obj && (ctx != req->i915->kernel_context))
intel_lr_context_unpin(ctx, ring);
list_del(&req->execlist_link);
i915_gem_request_unreference(req);
}
}
void intel_logical_ring_stop(struct intel_engine_cs *ring)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
int ret;
if (!intel_ring_initialized(ring))
return;
ret = intel_ring_idle(ring);
if (ret && !i915_reset_in_progress(&to_i915(ring->dev)->gpu_error))
DRM_ERROR("failed to quiesce %s whilst cleaning up: %d\n",
ring->name, ret);
I915_WRITE_MODE(ring, _MASKED_BIT_ENABLE(STOP_RING));
if (wait_for_atomic((I915_READ_MODE(ring) & MODE_IDLE) != 0, 1000)) {
DRM_ERROR("%s :timed out trying to stop ring\n", ring->name);
return;
}
I915_WRITE_MODE(ring, _MASKED_BIT_DISABLE(STOP_RING));
}
int logical_ring_flush_all_caches(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *ring = req->ring;
int ret;
if (!ring->gpu_caches_dirty)
return 0;
ret = ring->emit_flush(req, 0, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
ring->gpu_caches_dirty = false;
return 0;
}
static int intel_lr_context_do_pin(struct intel_context *ctx,
struct intel_engine_cs *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *ctx_obj = ctx->engine[ring->id].state;
struct intel_ringbuffer *ringbuf = ctx->engine[ring->id].ringbuf;
struct page *lrc_state_page;
uint32_t *lrc_reg_state;
int ret;
WARN_ON(!mutex_is_locked(&ring->dev->struct_mutex));
ret = i915_gem_obj_ggtt_pin(ctx_obj, GEN8_LR_CONTEXT_ALIGN,
PIN_OFFSET_BIAS | GUC_WOPCM_TOP);
if (ret)
return ret;
lrc_state_page = i915_gem_object_get_dirty_page(ctx_obj, LRC_STATE_PN);
if (WARN_ON(!lrc_state_page)) {
ret = -ENODEV;
goto unpin_ctx_obj;
}
ret = intel_pin_and_map_ringbuffer_obj(ring->dev, ringbuf);
if (ret)
goto unpin_ctx_obj;
ctx->engine[ring->id].lrc_vma = i915_gem_obj_to_ggtt(ctx_obj);
intel_lr_context_descriptor_update(ctx, ring);
lrc_reg_state = kmap(lrc_state_page);
lrc_reg_state[CTX_RING_BUFFER_START+1] = ringbuf->vma->node.start;
ctx->engine[ring->id].lrc_reg_state = lrc_reg_state;
ctx_obj->dirty = true;
if (i915.enable_guc_submission)
I915_WRITE(GEN8_GTCR, GEN8_GTCR_INVALIDATE);
return ret;
unpin_ctx_obj:
i915_gem_object_ggtt_unpin(ctx_obj);
return ret;
}
static int intel_lr_context_pin(struct intel_context *ctx,
struct intel_engine_cs *engine)
{
int ret = 0;
if (ctx->engine[engine->id].pin_count++ == 0) {
ret = intel_lr_context_do_pin(ctx, engine);
if (ret)
goto reset_pin_count;
i915_gem_context_reference(ctx);
}
return ret;
reset_pin_count:
ctx->engine[engine->id].pin_count = 0;
return ret;
}
void intel_lr_context_unpin(struct intel_context *ctx,
struct intel_engine_cs *engine)
{
struct drm_i915_gem_object *ctx_obj = ctx->engine[engine->id].state;
WARN_ON(!mutex_is_locked(&ctx->i915->dev->struct_mutex));
if (--ctx->engine[engine->id].pin_count == 0) {
kunmap(kmap_to_page(ctx->engine[engine->id].lrc_reg_state));
intel_unpin_ringbuffer_obj(ctx->engine[engine->id].ringbuf);
i915_gem_object_ggtt_unpin(ctx_obj);
ctx->engine[engine->id].lrc_vma = NULL;
ctx->engine[engine->id].lrc_desc = 0;
ctx->engine[engine->id].lrc_reg_state = NULL;
i915_gem_context_unreference(ctx);
}
}
static int intel_logical_ring_workarounds_emit(struct drm_i915_gem_request *req)
{
int ret, i;
struct intel_engine_cs *ring = req->ring;
struct intel_ringbuffer *ringbuf = req->ringbuf;
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_workarounds *w = &dev_priv->workarounds;
if (w->count == 0)
return 0;
ring->gpu_caches_dirty = true;
ret = logical_ring_flush_all_caches(req);
if (ret)
return ret;
ret = intel_logical_ring_begin(req, w->count * 2 + 2);
if (ret)
return ret;
intel_logical_ring_emit(ringbuf, MI_LOAD_REGISTER_IMM(w->count));
for (i = 0; i < w->count; i++) {
intel_logical_ring_emit_reg(ringbuf, w->reg[i].addr);
intel_logical_ring_emit(ringbuf, w->reg[i].value);
}
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
ring->gpu_caches_dirty = true;
ret = logical_ring_flush_all_caches(req);
if (ret)
return ret;
return 0;
}
static inline int gen8_emit_flush_coherentl3_wa(struct intel_engine_cs *ring,
uint32_t *const batch,
uint32_t index)
{
uint32_t l3sqc4_flush = (0x40400000 | GEN8_LQSC_FLUSH_COHERENT_LINES);
if (IS_SKL_REVID(ring->dev, 0, SKL_REVID_E0))
l3sqc4_flush |= GEN8_LQSC_RO_PERF_DIS;
wa_ctx_emit(batch, index, (MI_STORE_REGISTER_MEM_GEN8 |
MI_SRM_LRM_GLOBAL_GTT));
wa_ctx_emit_reg(batch, index, GEN8_L3SQCREG4);
wa_ctx_emit(batch, index, ring->scratch.gtt_offset + 256);
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
wa_ctx_emit(batch, index, ring->scratch.gtt_offset + 256);
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
static int gen8_init_indirectctx_bb(struct intel_engine_cs *ring,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *const batch,
uint32_t *offset)
{
uint32_t scratch_addr;
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_DISABLE);
if (IS_BROADWELL(ring->dev)) {
int rc = gen8_emit_flush_coherentl3_wa(ring, batch, index);
if (rc < 0)
return rc;
index = rc;
}
scratch_addr = ring->scratch.gtt_offset + 2*CACHELINE_BYTES;
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
static int gen8_init_perctx_bb(struct intel_engine_cs *ring,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *const batch,
uint32_t *offset)
{
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_ENABLE);
wa_ctx_emit(batch, index, MI_BATCH_BUFFER_END);
return wa_ctx_end(wa_ctx, *offset = index, 1);
}
static int gen9_init_indirectctx_bb(struct intel_engine_cs *ring,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *const batch,
uint32_t *offset)
{
int ret;
struct drm_device *dev = ring->dev;
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
if (IS_SKL_REVID(dev, 0, SKL_REVID_D0) ||
IS_BXT_REVID(dev, 0, BXT_REVID_A1))
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_DISABLE);
ret = gen8_emit_flush_coherentl3_wa(ring, batch, index);
if (ret < 0)
return ret;
index = ret;
while (index % CACHELINE_DWORDS)
wa_ctx_emit(batch, index, MI_NOOP);
return wa_ctx_end(wa_ctx, *offset = index, CACHELINE_DWORDS);
}
static int gen9_init_perctx_bb(struct intel_engine_cs *ring,
struct i915_wa_ctx_bb *wa_ctx,
uint32_t *const batch,
uint32_t *offset)
{
struct drm_device *dev = ring->dev;
uint32_t index = wa_ctx_start(wa_ctx, *offset, CACHELINE_DWORDS);
if (IS_SKL_REVID(dev, 0, SKL_REVID_B0) ||
IS_BXT_REVID(dev, 0, BXT_REVID_A1)) {
wa_ctx_emit(batch, index, MI_LOAD_REGISTER_IMM(1));
wa_ctx_emit_reg(batch, index, GEN9_SLICE_COMMON_ECO_CHICKEN0);
wa_ctx_emit(batch, index,
_MASKED_BIT_ENABLE(DISABLE_PIXEL_MASK_CAMMING));
wa_ctx_emit(batch, index, MI_NOOP);
}
if (IS_SKL_REVID(dev, 0, SKL_REVID_D0) ||
IS_BXT_REVID(dev, 0, BXT_REVID_A1))
wa_ctx_emit(batch, index, MI_ARB_ON_OFF | MI_ARB_ENABLE);
wa_ctx_emit(batch, index, MI_BATCH_BUFFER_END);
return wa_ctx_end(wa_ctx, *offset = index, 1);
}
static int lrc_setup_wa_ctx_obj(struct intel_engine_cs *ring, u32 size)
{
int ret;
ring->wa_ctx.obj = i915_gem_alloc_object(ring->dev, PAGE_ALIGN(size));
if (!ring->wa_ctx.obj) {
DRM_DEBUG_DRIVER("alloc LRC WA ctx backing obj failed.\n");
return -ENOMEM;
}
ret = i915_gem_obj_ggtt_pin(ring->wa_ctx.obj, PAGE_SIZE, 0);
if (ret) {
DRM_DEBUG_DRIVER("pin LRC WA ctx backing obj failed: %d\n",
ret);
drm_gem_object_unreference(&ring->wa_ctx.obj->base);
return ret;
}
return 0;
}
static void lrc_destroy_wa_ctx_obj(struct intel_engine_cs *ring)
{
if (ring->wa_ctx.obj) {
i915_gem_object_ggtt_unpin(ring->wa_ctx.obj);
drm_gem_object_unreference(&ring->wa_ctx.obj->base);
ring->wa_ctx.obj = NULL;
}
}
static int intel_init_workaround_bb(struct intel_engine_cs *ring)
{
int ret;
uint32_t *batch;
uint32_t offset;
struct page *page;
struct i915_ctx_workarounds *wa_ctx = &ring->wa_ctx;
WARN_ON(ring->id != RCS);
if (INTEL_INFO(ring->dev)->gen > 9) {
DRM_ERROR("WA batch buffer is not initialized for Gen%d\n",
INTEL_INFO(ring->dev)->gen);
return 0;
}
if (ring->scratch.obj == NULL) {
DRM_ERROR("scratch page not allocated for %s\n", ring->name);
return -EINVAL;
}
ret = lrc_setup_wa_ctx_obj(ring, PAGE_SIZE);
if (ret) {
DRM_DEBUG_DRIVER("Failed to setup context WA page: %d\n", ret);
return ret;
}
page = i915_gem_object_get_dirty_page(wa_ctx->obj, 0);
batch = kmap_atomic(page);
offset = 0;
if (INTEL_INFO(ring->dev)->gen == 8) {
ret = gen8_init_indirectctx_bb(ring,
&wa_ctx->indirect_ctx,
batch,
&offset);
if (ret)
goto out;
ret = gen8_init_perctx_bb(ring,
&wa_ctx->per_ctx,
batch,
&offset);
if (ret)
goto out;
} else if (INTEL_INFO(ring->dev)->gen == 9) {
ret = gen9_init_indirectctx_bb(ring,
&wa_ctx->indirect_ctx,
batch,
&offset);
if (ret)
goto out;
ret = gen9_init_perctx_bb(ring,
&wa_ctx->per_ctx,
batch,
&offset);
if (ret)
goto out;
}
out:
kunmap_atomic(batch);
if (ret)
lrc_destroy_wa_ctx_obj(ring);
return ret;
}
static int gen8_init_common_ring(struct intel_engine_cs *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
u8 next_context_status_buffer_hw;
lrc_setup_hardware_status_page(ring,
dev_priv->kernel_context->engine[ring->id].state);
I915_WRITE_IMR(ring, ~(ring->irq_enable_mask | ring->irq_keep_mask));
I915_WRITE(RING_HWSTAM(ring->mmio_base), 0xffffffff);
I915_WRITE(RING_MODE_GEN7(ring),
_MASKED_BIT_DISABLE(GFX_REPLAY_MODE) |
_MASKED_BIT_ENABLE(GFX_RUN_LIST_ENABLE));
POSTING_READ(RING_MODE_GEN7(ring));
next_context_status_buffer_hw =
GEN8_CSB_WRITE_PTR(I915_READ(RING_CONTEXT_STATUS_PTR(ring)));
if (next_context_status_buffer_hw == GEN8_CSB_PTR_MASK)
next_context_status_buffer_hw = (GEN8_CSB_ENTRIES - 1);
ring->next_context_status_buffer = next_context_status_buffer_hw;
DRM_DEBUG_DRIVER("Execlists enabled for %s\n", ring->name);
memset(&ring->hangcheck, 0, sizeof(ring->hangcheck));
return 0;
}
static int gen8_init_render_ring(struct intel_engine_cs *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = gen8_init_common_ring(ring);
if (ret)
return ret;
I915_WRITE(MI_MODE, _MASKED_BIT_ENABLE(ASYNC_FLIP_PERF_DISABLE));
I915_WRITE(INSTPM, _MASKED_BIT_ENABLE(INSTPM_FORCE_ORDERING));
return init_workarounds_ring(ring);
}
static int gen9_init_render_ring(struct intel_engine_cs *ring)
{
int ret;
ret = gen8_init_common_ring(ring);
if (ret)
return ret;
return init_workarounds_ring(ring);
}
static int intel_logical_ring_emit_pdps(struct drm_i915_gem_request *req)
{
struct i915_hw_ppgtt *ppgtt = req->ctx->ppgtt;
struct intel_engine_cs *ring = req->ring;
struct intel_ringbuffer *ringbuf = req->ringbuf;
const int num_lri_cmds = GEN8_LEGACY_PDPES * 2;
int i, ret;
ret = intel_logical_ring_begin(req, num_lri_cmds * 2 + 2);
if (ret)
return ret;
intel_logical_ring_emit(ringbuf, MI_LOAD_REGISTER_IMM(num_lri_cmds));
for (i = GEN8_LEGACY_PDPES - 1; i >= 0; i--) {
const dma_addr_t pd_daddr = i915_page_dir_dma_addr(ppgtt, i);
intel_logical_ring_emit_reg(ringbuf, GEN8_RING_PDP_UDW(ring, i));
intel_logical_ring_emit(ringbuf, upper_32_bits(pd_daddr));
intel_logical_ring_emit_reg(ringbuf, GEN8_RING_PDP_LDW(ring, i));
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
(intel_ring_flag(req->ring) & req->ctx->ppgtt->pd_dirty_rings)) {
if (!USES_FULL_48BIT_PPGTT(req->i915) &&
!intel_vgpu_active(req->i915->dev)) {
ret = intel_logical_ring_emit_pdps(req);
if (ret)
return ret;
}
req->ctx->ppgtt->pd_dirty_rings &= ~intel_ring_flag(req->ring);
}
ret = intel_logical_ring_begin(req, 4);
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
static bool gen8_logical_ring_get_irq(struct intel_engine_cs *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (WARN_ON(!intel_irqs_enabled(dev_priv)))
return false;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (ring->irq_refcount++ == 0) {
I915_WRITE_IMR(ring, ~(ring->irq_enable_mask | ring->irq_keep_mask));
POSTING_READ(RING_IMR(ring->mmio_base));
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
return true;
}
static void gen8_logical_ring_put_irq(struct intel_engine_cs *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->irq_lock, flags);
if (--ring->irq_refcount == 0) {
I915_WRITE_IMR(ring, ~ring->irq_keep_mask);
POSTING_READ(RING_IMR(ring->mmio_base));
}
spin_unlock_irqrestore(&dev_priv->irq_lock, flags);
}
static int gen8_emit_flush(struct drm_i915_gem_request *request,
u32 invalidate_domains,
u32 unused)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
struct intel_engine_cs *ring = ringbuf->ring;
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t cmd;
int ret;
ret = intel_logical_ring_begin(request, 4);
if (ret)
return ret;
cmd = MI_FLUSH_DW + 1;
cmd |= MI_FLUSH_DW_STORE_INDEX | MI_FLUSH_DW_OP_STOREDW;
if (invalidate_domains & I915_GEM_GPU_DOMAINS) {
cmd |= MI_INVALIDATE_TLB;
if (ring == &dev_priv->ring[VCS])
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
struct intel_engine_cs *ring = ringbuf->ring;
u32 scratch_addr = ring->scratch.gtt_offset + 2 * CACHELINE_BYTES;
bool vf_flush_wa = false;
u32 flags = 0;
int ret;
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
if (IS_GEN9(ring->dev))
vf_flush_wa = true;
}
ret = intel_logical_ring_begin(request, vf_flush_wa ? 12 : 6);
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
intel_logical_ring_emit(ringbuf, GFX_OP_PIPE_CONTROL(6));
intel_logical_ring_emit(ringbuf, flags);
intel_logical_ring_emit(ringbuf, scratch_addr);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_advance(ringbuf);
return 0;
}
static u32 gen8_get_seqno(struct intel_engine_cs *ring, bool lazy_coherency)
{
return intel_read_status_page(ring, I915_GEM_HWS_INDEX);
}
static void gen8_set_seqno(struct intel_engine_cs *ring, u32 seqno)
{
intel_write_status_page(ring, I915_GEM_HWS_INDEX, seqno);
}
static u32 bxt_a_get_seqno(struct intel_engine_cs *ring, bool lazy_coherency)
{
if (!lazy_coherency)
intel_flush_status_page(ring, I915_GEM_HWS_INDEX);
return intel_read_status_page(ring, I915_GEM_HWS_INDEX);
}
static void bxt_a_set_seqno(struct intel_engine_cs *ring, u32 seqno)
{
intel_write_status_page(ring, I915_GEM_HWS_INDEX, seqno);
intel_flush_status_page(ring, I915_GEM_HWS_INDEX);
}
static inline u32 hws_seqno_address(struct intel_engine_cs *engine)
{
return engine->status_page.gfx_addr + I915_GEM_HWS_INDEX_ADDR;
}
static int gen8_emit_request(struct drm_i915_gem_request *request)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
int ret;
ret = intel_logical_ring_begin(request, 6 + WA_TAIL_DWORDS);
if (ret)
return ret;
BUILD_BUG_ON(I915_GEM_HWS_INDEX_ADDR & (1 << 5));
intel_logical_ring_emit(ringbuf,
(MI_FLUSH_DW + 1) | MI_FLUSH_DW_OP_STOREDW);
intel_logical_ring_emit(ringbuf,
hws_seqno_address(request->ring) |
MI_FLUSH_DW_USE_GTT);
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf, i915_gem_request_get_seqno(request));
intel_logical_ring_emit(ringbuf, MI_USER_INTERRUPT);
intel_logical_ring_emit(ringbuf, MI_NOOP);
return intel_logical_ring_advance_and_submit(request);
}
static int gen8_emit_request_render(struct drm_i915_gem_request *request)
{
struct intel_ringbuffer *ringbuf = request->ringbuf;
int ret;
ret = intel_logical_ring_begin(request, 8 + WA_TAIL_DWORDS);
if (ret)
return ret;
BUILD_BUG_ON(I915_GEM_HWS_INDEX & 1);
intel_logical_ring_emit(ringbuf, GFX_OP_PIPE_CONTROL(6));
intel_logical_ring_emit(ringbuf,
(PIPE_CONTROL_GLOBAL_GTT_IVB |
PIPE_CONTROL_CS_STALL |
PIPE_CONTROL_QW_WRITE));
intel_logical_ring_emit(ringbuf, hws_seqno_address(request->ring));
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
ret = i915_gem_render_state_prepare(req->ring, &so);
if (ret)
return ret;
if (so.rodata == NULL)
return 0;
ret = req->ring->emit_bb_start(req, so.ggtt_offset,
I915_DISPATCH_SECURE);
if (ret)
goto out;
ret = req->ring->emit_bb_start(req,
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
void intel_logical_ring_cleanup(struct intel_engine_cs *ring)
{
struct drm_i915_private *dev_priv;
if (!intel_ring_initialized(ring))
return;
dev_priv = ring->dev->dev_private;
if (ring->buffer) {
intel_logical_ring_stop(ring);
WARN_ON((I915_READ_MODE(ring) & MODE_IDLE) == 0);
}
if (ring->cleanup)
ring->cleanup(ring);
i915_cmd_parser_fini_ring(ring);
i915_gem_batch_pool_fini(&ring->batch_pool);
if (ring->status_page.obj) {
kunmap(sg_page(ring->status_page.obj->pages->sgl));
ring->status_page.obj = NULL;
}
ring->disable_lite_restore_wa = false;
ring->ctx_desc_template = 0;
lrc_destroy_wa_ctx_obj(ring);
ring->dev = NULL;
}
static void
logical_ring_default_vfuncs(struct drm_device *dev,
struct intel_engine_cs *ring)
{
ring->init_hw = gen8_init_common_ring;
ring->emit_request = gen8_emit_request;
ring->emit_flush = gen8_emit_flush;
ring->irq_get = gen8_logical_ring_get_irq;
ring->irq_put = gen8_logical_ring_put_irq;
ring->emit_bb_start = gen8_emit_bb_start;
if (IS_BXT_REVID(dev, 0, BXT_REVID_A1)) {
ring->get_seqno = bxt_a_get_seqno;
ring->set_seqno = bxt_a_set_seqno;
} else {
ring->get_seqno = gen8_get_seqno;
ring->set_seqno = gen8_set_seqno;
}
}
static inline void
logical_ring_default_irqs(struct intel_engine_cs *ring, unsigned shift)
{
ring->irq_enable_mask = GT_RENDER_USER_INTERRUPT << shift;
ring->irq_keep_mask = GT_CONTEXT_SWITCH_INTERRUPT << shift;
}
static int
logical_ring_init(struct drm_device *dev, struct intel_engine_cs *ring)
{
struct intel_context *dctx = to_i915(dev)->kernel_context;
int ret;
ring->buffer = NULL;
ring->dev = dev;
INIT_LIST_HEAD(&ring->active_list);
INIT_LIST_HEAD(&ring->request_list);
i915_gem_batch_pool_init(dev, &ring->batch_pool);
init_waitqueue_head(&ring->irq_queue);
INIT_LIST_HEAD(&ring->buffers);
INIT_LIST_HEAD(&ring->execlist_queue);
INIT_LIST_HEAD(&ring->execlist_retired_req_list);
spin_lock_init(&ring->execlist_lock);
logical_ring_init_platform_invariants(ring);
ret = i915_cmd_parser_init_ring(ring);
if (ret)
goto error;
ret = intel_lr_context_deferred_alloc(dctx, ring);
if (ret)
goto error;
ret = intel_lr_context_do_pin(dctx, ring);
if (ret) {
DRM_ERROR(
"Failed to pin and map ringbuffer %s: %d\n",
ring->name, ret);
goto error;
}
return 0;
error:
intel_logical_ring_cleanup(ring);
return ret;
}
static int logical_render_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[RCS];
int ret;
ring->name = "render ring";
ring->id = RCS;
ring->exec_id = I915_EXEC_RENDER;
ring->guc_id = GUC_RENDER_ENGINE;
ring->mmio_base = RENDER_RING_BASE;
logical_ring_default_irqs(ring, GEN8_RCS_IRQ_SHIFT);
if (HAS_L3_DPF(dev))
ring->irq_keep_mask |= GT_RENDER_L3_PARITY_ERROR_INTERRUPT;
logical_ring_default_vfuncs(dev, ring);
if (INTEL_INFO(dev)->gen >= 9)
ring->init_hw = gen9_init_render_ring;
else
ring->init_hw = gen8_init_render_ring;
ring->init_context = gen8_init_rcs_context;
ring->cleanup = intel_fini_pipe_control;
ring->emit_flush = gen8_emit_flush_render;
ring->emit_request = gen8_emit_request_render;
ring->dev = dev;
ret = intel_init_pipe_control(ring);
if (ret)
return ret;
ret = intel_init_workaround_bb(ring);
if (ret) {
DRM_ERROR("WA batch buffer initialization failed: %d\n",
ret);
}
ret = logical_ring_init(dev, ring);
if (ret) {
lrc_destroy_wa_ctx_obj(ring);
}
return ret;
}
static int logical_bsd_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[VCS];
ring->name = "bsd ring";
ring->id = VCS;
ring->exec_id = I915_EXEC_BSD;
ring->guc_id = GUC_VIDEO_ENGINE;
ring->mmio_base = GEN6_BSD_RING_BASE;
logical_ring_default_irqs(ring, GEN8_VCS1_IRQ_SHIFT);
logical_ring_default_vfuncs(dev, ring);
return logical_ring_init(dev, ring);
}
static int logical_bsd2_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[VCS2];
ring->name = "bsd2 ring";
ring->id = VCS2;
ring->exec_id = I915_EXEC_BSD;
ring->guc_id = GUC_VIDEO_ENGINE2;
ring->mmio_base = GEN8_BSD2_RING_BASE;
logical_ring_default_irqs(ring, GEN8_VCS2_IRQ_SHIFT);
logical_ring_default_vfuncs(dev, ring);
return logical_ring_init(dev, ring);
}
static int logical_blt_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[BCS];
ring->name = "blitter ring";
ring->id = BCS;
ring->exec_id = I915_EXEC_BLT;
ring->guc_id = GUC_BLITTER_ENGINE;
ring->mmio_base = BLT_RING_BASE;
logical_ring_default_irqs(ring, GEN8_BCS_IRQ_SHIFT);
logical_ring_default_vfuncs(dev, ring);
return logical_ring_init(dev, ring);
}
static int logical_vebox_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[VECS];
ring->name = "video enhancement ring";
ring->id = VECS;
ring->exec_id = I915_EXEC_VEBOX;
ring->guc_id = GUC_VIDEOENHANCE_ENGINE;
ring->mmio_base = VEBOX_RING_BASE;
logical_ring_default_irqs(ring, GEN8_VECS_IRQ_SHIFT);
logical_ring_default_vfuncs(dev, ring);
return logical_ring_init(dev, ring);
}
int intel_logical_rings_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = logical_render_ring_init(dev);
if (ret)
return ret;
if (HAS_BSD(dev)) {
ret = logical_bsd_ring_init(dev);
if (ret)
goto cleanup_render_ring;
}
if (HAS_BLT(dev)) {
ret = logical_blt_ring_init(dev);
if (ret)
goto cleanup_bsd_ring;
}
if (HAS_VEBOX(dev)) {
ret = logical_vebox_ring_init(dev);
if (ret)
goto cleanup_blt_ring;
}
if (HAS_BSD2(dev)) {
ret = logical_bsd2_ring_init(dev);
if (ret)
goto cleanup_vebox_ring;
}
return 0;
cleanup_vebox_ring:
intel_logical_ring_cleanup(&dev_priv->ring[VECS]);
cleanup_blt_ring:
intel_logical_ring_cleanup(&dev_priv->ring[BCS]);
cleanup_bsd_ring:
intel_logical_ring_cleanup(&dev_priv->ring[VCS]);
cleanup_render_ring:
intel_logical_ring_cleanup(&dev_priv->ring[RCS]);
return ret;
}
static u32
make_rpcs(struct drm_device *dev)
{
u32 rpcs = 0;
if (INTEL_INFO(dev)->gen < 9)
return 0;
if (INTEL_INFO(dev)->has_slice_pg) {
rpcs |= GEN8_RPCS_S_CNT_ENABLE;
rpcs |= INTEL_INFO(dev)->slice_total <<
GEN8_RPCS_S_CNT_SHIFT;
rpcs |= GEN8_RPCS_ENABLE;
}
if (INTEL_INFO(dev)->has_subslice_pg) {
rpcs |= GEN8_RPCS_SS_CNT_ENABLE;
rpcs |= INTEL_INFO(dev)->subslice_per_slice <<
GEN8_RPCS_SS_CNT_SHIFT;
rpcs |= GEN8_RPCS_ENABLE;
}
if (INTEL_INFO(dev)->has_eu_pg) {
rpcs |= INTEL_INFO(dev)->eu_per_subslice <<
GEN8_RPCS_EU_MIN_SHIFT;
rpcs |= INTEL_INFO(dev)->eu_per_subslice <<
GEN8_RPCS_EU_MAX_SHIFT;
rpcs |= GEN8_RPCS_ENABLE;
}
return rpcs;
}
static u32 intel_lr_indirect_ctx_offset(struct intel_engine_cs *ring)
{
u32 indirect_ctx_offset;
switch (INTEL_INFO(ring->dev)->gen) {
default:
MISSING_CASE(INTEL_INFO(ring->dev)->gen);
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
populate_lr_context(struct intel_context *ctx, struct drm_i915_gem_object *ctx_obj,
struct intel_engine_cs *ring, struct intel_ringbuffer *ringbuf)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_hw_ppgtt *ppgtt = ctx->ppgtt;
struct page *page;
uint32_t *reg_state;
int ret;
if (!ppgtt)
ppgtt = dev_priv->mm.aliasing_ppgtt;
ret = i915_gem_object_set_to_cpu_domain(ctx_obj, true);
if (ret) {
DRM_DEBUG_DRIVER("Could not set to CPU domain\n");
return ret;
}
ret = i915_gem_object_get_pages(ctx_obj);
if (ret) {
DRM_DEBUG_DRIVER("Could not get object pages\n");
return ret;
}
i915_gem_object_pin_pages(ctx_obj);
page = i915_gem_object_get_dirty_page(ctx_obj, LRC_STATE_PN);
reg_state = kmap_atomic(page);
reg_state[CTX_LRI_HEADER_0] =
MI_LOAD_REGISTER_IMM(ring->id == RCS ? 14 : 11) | MI_LRI_FORCE_POSTED;
ASSIGN_CTX_REG(reg_state, CTX_CONTEXT_CONTROL, RING_CONTEXT_CONTROL(ring),
_MASKED_BIT_ENABLE(CTX_CTRL_INHIBIT_SYN_CTX_SWITCH |
CTX_CTRL_ENGINE_CTX_RESTORE_INHIBIT |
(HAS_RESOURCE_STREAMER(dev) ?
CTX_CTRL_RS_CTX_ENABLE : 0)));
ASSIGN_CTX_REG(reg_state, CTX_RING_HEAD, RING_HEAD(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_RING_TAIL, RING_TAIL(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_RING_BUFFER_START, RING_START(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_RING_BUFFER_CONTROL, RING_CTL(ring->mmio_base),
((ringbuf->size - PAGE_SIZE) & RING_NR_PAGES) | RING_VALID);
ASSIGN_CTX_REG(reg_state, CTX_BB_HEAD_U, RING_BBADDR_UDW(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_BB_HEAD_L, RING_BBADDR(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_BB_STATE, RING_BBSTATE(ring->mmio_base),
RING_BB_PPGTT);
ASSIGN_CTX_REG(reg_state, CTX_SECOND_BB_HEAD_U, RING_SBBADDR_UDW(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_SECOND_BB_HEAD_L, RING_SBBADDR(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_SECOND_BB_STATE, RING_SBBSTATE(ring->mmio_base), 0);
if (ring->id == RCS) {
ASSIGN_CTX_REG(reg_state, CTX_BB_PER_CTX_PTR, RING_BB_PER_CTX_PTR(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_RCS_INDIRECT_CTX, RING_INDIRECT_CTX(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_RCS_INDIRECT_CTX_OFFSET, RING_INDIRECT_CTX_OFFSET(ring->mmio_base), 0);
if (ring->wa_ctx.obj) {
struct i915_ctx_workarounds *wa_ctx = &ring->wa_ctx;
uint32_t ggtt_offset = i915_gem_obj_ggtt_offset(wa_ctx->obj);
reg_state[CTX_RCS_INDIRECT_CTX+1] =
(ggtt_offset + wa_ctx->indirect_ctx.offset * sizeof(uint32_t)) |
(wa_ctx->indirect_ctx.size / CACHELINE_DWORDS);
reg_state[CTX_RCS_INDIRECT_CTX_OFFSET+1] =
intel_lr_indirect_ctx_offset(ring) << 6;
reg_state[CTX_BB_PER_CTX_PTR+1] =
(ggtt_offset + wa_ctx->per_ctx.offset * sizeof(uint32_t)) |
0x01;
}
}
reg_state[CTX_LRI_HEADER_1] = MI_LOAD_REGISTER_IMM(9) | MI_LRI_FORCE_POSTED;
ASSIGN_CTX_REG(reg_state, CTX_CTX_TIMESTAMP, RING_CTX_TIMESTAMP(ring->mmio_base), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP3_UDW, GEN8_RING_PDP_UDW(ring, 3), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP3_LDW, GEN8_RING_PDP_LDW(ring, 3), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP2_UDW, GEN8_RING_PDP_UDW(ring, 2), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP2_LDW, GEN8_RING_PDP_LDW(ring, 2), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP1_UDW, GEN8_RING_PDP_UDW(ring, 1), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP1_LDW, GEN8_RING_PDP_LDW(ring, 1), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP0_UDW, GEN8_RING_PDP_UDW(ring, 0), 0);
ASSIGN_CTX_REG(reg_state, CTX_PDP0_LDW, GEN8_RING_PDP_LDW(ring, 0), 0);
if (USES_FULL_48BIT_PPGTT(ppgtt->base.dev)) {
ASSIGN_CTX_PML4(ppgtt, reg_state);
} else {
ASSIGN_CTX_PDP(ppgtt, reg_state, 3);
ASSIGN_CTX_PDP(ppgtt, reg_state, 2);
ASSIGN_CTX_PDP(ppgtt, reg_state, 1);
ASSIGN_CTX_PDP(ppgtt, reg_state, 0);
}
if (ring->id == RCS) {
reg_state[CTX_LRI_HEADER_2] = MI_LOAD_REGISTER_IMM(1);
ASSIGN_CTX_REG(reg_state, CTX_R_PWR_CLK_STATE, GEN8_R_PWR_CLK_STATE,
make_rpcs(dev));
}
kunmap_atomic(reg_state);
i915_gem_object_unpin_pages(ctx_obj);
return 0;
}
void intel_lr_context_free(struct intel_context *ctx)
{
int i;
for (i = I915_NUM_RINGS; --i >= 0; ) {
struct intel_ringbuffer *ringbuf = ctx->engine[i].ringbuf;
struct drm_i915_gem_object *ctx_obj = ctx->engine[i].state;
if (!ctx_obj)
continue;
if (ctx == ctx->i915->kernel_context) {
intel_unpin_ringbuffer_obj(ringbuf);
i915_gem_object_ggtt_unpin(ctx_obj);
}
WARN_ON(ctx->engine[i].pin_count);
intel_ringbuffer_free(ringbuf);
drm_gem_object_unreference(&ctx_obj->base);
}
}
uint32_t intel_lr_context_size(struct intel_engine_cs *ring)
{
int ret = 0;
WARN_ON(INTEL_INFO(ring->dev)->gen < 8);
switch (ring->id) {
case RCS:
if (INTEL_INFO(ring->dev)->gen >= 9)
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
static void lrc_setup_hardware_status_page(struct intel_engine_cs *ring,
struct drm_i915_gem_object *default_ctx_obj)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
struct page *page;
ring->status_page.gfx_addr = i915_gem_obj_ggtt_offset(default_ctx_obj)
+ LRC_PPHWSP_PN * PAGE_SIZE;
page = i915_gem_object_get_page(default_ctx_obj, LRC_PPHWSP_PN);
ring->status_page.page_addr = kmap(page);
ring->status_page.obj = default_ctx_obj;
I915_WRITE(RING_HWS_PGA(ring->mmio_base),
(u32)ring->status_page.gfx_addr);
POSTING_READ(RING_HWS_PGA(ring->mmio_base));
}
int intel_lr_context_deferred_alloc(struct intel_context *ctx,
struct intel_engine_cs *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_gem_object *ctx_obj;
uint32_t context_size;
struct intel_ringbuffer *ringbuf;
int ret;
WARN_ON(ctx->legacy_hw_ctx.rcs_state != NULL);
WARN_ON(ctx->engine[ring->id].state);
context_size = round_up(intel_lr_context_size(ring), 4096);
context_size += PAGE_SIZE * LRC_PPHWSP_PN;
ctx_obj = i915_gem_alloc_object(dev, context_size);
if (!ctx_obj) {
DRM_DEBUG_DRIVER("Alloc LRC backing obj failed.\n");
return -ENOMEM;
}
ringbuf = intel_engine_create_ringbuffer(ring, 4 * PAGE_SIZE);
if (IS_ERR(ringbuf)) {
ret = PTR_ERR(ringbuf);
goto error_deref_obj;
}
ret = populate_lr_context(ctx, ctx_obj, ring, ringbuf);
if (ret) {
DRM_DEBUG_DRIVER("Failed to populate LRC: %d\n", ret);
goto error_ringbuf;
}
ctx->engine[ring->id].ringbuf = ringbuf;
ctx->engine[ring->id].state = ctx_obj;
if (ctx != ctx->i915->kernel_context && ring->init_context) {
struct drm_i915_gem_request *req;
req = i915_gem_request_alloc(ring, ctx);
if (IS_ERR(req)) {
ret = PTR_ERR(req);
DRM_ERROR("ring create req: %d\n", ret);
goto error_ringbuf;
}
ret = ring->init_context(req);
if (ret) {
DRM_ERROR("ring init context: %d\n",
ret);
i915_gem_request_cancel(req);
goto error_ringbuf;
}
i915_add_request_no_flush(req);
}
return 0;
error_ringbuf:
intel_ringbuffer_free(ringbuf);
error_deref_obj:
drm_gem_object_unreference(&ctx_obj->base);
ctx->engine[ring->id].ringbuf = NULL;
ctx->engine[ring->id].state = NULL;
return ret;
}
void intel_lr_context_reset(struct drm_device *dev,
struct intel_context *ctx)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring;
int i;
for_each_ring(ring, dev_priv, i) {
struct drm_i915_gem_object *ctx_obj =
ctx->engine[ring->id].state;
struct intel_ringbuffer *ringbuf =
ctx->engine[ring->id].ringbuf;
uint32_t *reg_state;
struct page *page;
if (!ctx_obj)
continue;
if (i915_gem_object_get_pages(ctx_obj)) {
WARN(1, "Failed get_pages for context obj\n");
continue;
}
page = i915_gem_object_get_dirty_page(ctx_obj, LRC_STATE_PN);
reg_state = kmap_atomic(page);
reg_state[CTX_RING_HEAD+1] = 0;
reg_state[CTX_RING_TAIL+1] = 0;
kunmap_atomic(reg_state);
ringbuf->head = 0;
ringbuf->tail = 0;
}
}
