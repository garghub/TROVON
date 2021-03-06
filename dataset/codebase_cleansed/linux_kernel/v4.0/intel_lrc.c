int intel_sanitize_enable_execlists(struct drm_device *dev, int enable_execlists)
{
WARN_ON(i915.enable_ppgtt == -1);
if (INTEL_INFO(dev)->gen >= 9)
return 1;
if (enable_execlists == 0)
return 0;
if (HAS_LOGICAL_RING_CONTEXTS(dev) && USES_PPGTT(dev) &&
i915.use_mmio_flip >= 0)
return 1;
return 0;
}
u32 intel_execlists_ctx_id(struct drm_i915_gem_object *ctx_obj)
{
u32 lrca = i915_gem_obj_ggtt_offset(ctx_obj);
return lrca >> 12;
}
static uint64_t execlists_ctx_descriptor(struct drm_i915_gem_object *ctx_obj)
{
uint64_t desc;
uint64_t lrca = i915_gem_obj_ggtt_offset(ctx_obj);
WARN_ON(lrca & 0xFFFFFFFF00000FFFULL);
desc = GEN8_CTX_VALID;
desc |= LEGACY_CONTEXT << GEN8_CTX_MODE_SHIFT;
desc |= GEN8_CTX_L3LLC_COHERENT;
desc |= GEN8_CTX_PRIVILEGE;
desc |= lrca;
desc |= (u64)intel_execlists_ctx_id(ctx_obj) << GEN8_CTX_ID_SHIFT;
return desc;
}
static void execlists_elsp_write(struct intel_engine_cs *ring,
struct drm_i915_gem_object *ctx_obj0,
struct drm_i915_gem_object *ctx_obj1)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint64_t temp = 0;
uint32_t desc[4];
if (ctx_obj1)
temp = execlists_ctx_descriptor(ctx_obj1);
else
temp = 0;
desc[1] = (u32)(temp >> 32);
desc[0] = (u32)temp;
temp = execlists_ctx_descriptor(ctx_obj0);
desc[3] = (u32)(temp >> 32);
desc[2] = (u32)temp;
intel_uncore_forcewake_get(dev_priv, FORCEWAKE_ALL);
I915_WRITE(RING_ELSP(ring), desc[1]);
I915_WRITE(RING_ELSP(ring), desc[0]);
I915_WRITE(RING_ELSP(ring), desc[3]);
I915_WRITE(RING_ELSP(ring), desc[2]);
POSTING_READ(RING_EXECLIST_STATUS(ring));
intel_uncore_forcewake_put(dev_priv, FORCEWAKE_ALL);
}
static int execlists_update_context(struct drm_i915_gem_object *ctx_obj,
struct drm_i915_gem_object *ring_obj,
u32 tail)
{
struct page *page;
uint32_t *reg_state;
page = i915_gem_object_get_page(ctx_obj, 1);
reg_state = kmap_atomic(page);
reg_state[CTX_RING_TAIL+1] = tail;
reg_state[CTX_RING_BUFFER_START+1] = i915_gem_obj_ggtt_offset(ring_obj);
kunmap_atomic(reg_state);
return 0;
}
static void execlists_submit_contexts(struct intel_engine_cs *ring,
struct intel_context *to0, u32 tail0,
struct intel_context *to1, u32 tail1)
{
struct drm_i915_gem_object *ctx_obj0 = to0->engine[ring->id].state;
struct intel_ringbuffer *ringbuf0 = to0->engine[ring->id].ringbuf;
struct drm_i915_gem_object *ctx_obj1 = NULL;
struct intel_ringbuffer *ringbuf1 = NULL;
BUG_ON(!ctx_obj0);
WARN_ON(!i915_gem_obj_is_pinned(ctx_obj0));
WARN_ON(!i915_gem_obj_is_pinned(ringbuf0->obj));
execlists_update_context(ctx_obj0, ringbuf0->obj, tail0);
if (to1) {
ringbuf1 = to1->engine[ring->id].ringbuf;
ctx_obj1 = to1->engine[ring->id].state;
BUG_ON(!ctx_obj1);
WARN_ON(!i915_gem_obj_is_pinned(ctx_obj1));
WARN_ON(!i915_gem_obj_is_pinned(ringbuf1->obj));
execlists_update_context(ctx_obj1, ringbuf1->obj, tail1);
}
execlists_elsp_write(ring, ctx_obj0, ctx_obj1);
}
static void execlists_context_unqueue(struct intel_engine_cs *ring)
{
struct drm_i915_gem_request *req0 = NULL, *req1 = NULL;
struct drm_i915_gem_request *cursor = NULL, *tmp = NULL;
assert_spin_locked(&ring->execlist_lock);
if (list_empty(&ring->execlist_queue))
return;
list_for_each_entry_safe(cursor, tmp, &ring->execlist_queue,
execlist_link) {
if (!req0) {
req0 = cursor;
} else if (req0->ctx == cursor->ctx) {
cursor->elsp_submitted = req0->elsp_submitted;
list_del(&req0->execlist_link);
list_add_tail(&req0->execlist_link,
&ring->execlist_retired_req_list);
req0 = cursor;
} else {
req1 = cursor;
break;
}
}
WARN_ON(req1 && req1->elsp_submitted);
execlists_submit_contexts(ring, req0->ctx, req0->tail,
req1 ? req1->ctx : NULL,
req1 ? req1->tail : 0);
req0->elsp_submitted++;
if (req1)
req1->elsp_submitted++;
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
struct drm_i915_gem_object *ctx_obj =
head_req->ctx->engine[ring->id].state;
if (intel_execlists_ctx_id(ctx_obj) == request_id) {
WARN(head_req->elsp_submitted == 0,
"Never submitted head request\n");
if (--head_req->elsp_submitted <= 0) {
list_del(&head_req->execlist_link);
list_add_tail(&head_req->execlist_link,
&ring->execlist_retired_req_list);
return true;
}
}
}
return false;
}
void intel_lrc_irq_handler(struct intel_engine_cs *ring)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
u32 status_pointer;
u8 read_pointer;
u8 write_pointer;
u32 status;
u32 status_id;
u32 submit_contexts = 0;
status_pointer = I915_READ(RING_CONTEXT_STATUS_PTR(ring));
read_pointer = ring->next_context_status_buffer;
write_pointer = status_pointer & 0x07;
if (read_pointer > write_pointer)
write_pointer += 6;
spin_lock(&ring->execlist_lock);
while (read_pointer < write_pointer) {
read_pointer++;
status = I915_READ(RING_CONTEXT_STATUS_BUF(ring) +
(read_pointer % 6) * 8);
status_id = I915_READ(RING_CONTEXT_STATUS_BUF(ring) +
(read_pointer % 6) * 8 + 4);
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
if (submit_contexts != 0)
execlists_context_unqueue(ring);
spin_unlock(&ring->execlist_lock);
WARN(submit_contexts > 2, "More than two context complete events?\n");
ring->next_context_status_buffer = write_pointer % 6;
I915_WRITE(RING_CONTEXT_STATUS_PTR(ring),
((u32)ring->next_context_status_buffer & 0x07) << 8);
}
static int execlists_context_queue(struct intel_engine_cs *ring,
struct intel_context *to,
u32 tail,
struct drm_i915_gem_request *request)
{
struct drm_i915_gem_request *cursor;
struct drm_i915_private *dev_priv = ring->dev->dev_private;
unsigned long flags;
int num_elements = 0;
if (to != ring->default_context)
intel_lr_context_pin(ring, to);
if (!request) {
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (request == NULL)
return -ENOMEM;
request->ring = ring;
request->ctx = to;
kref_init(&request->ref);
request->uniq = dev_priv->request_uniq++;
i915_gem_context_reference(request->ctx);
} else {
i915_gem_request_reference(request);
WARN_ON(to != request->ctx);
}
request->tail = tail;
intel_runtime_pm_get(dev_priv);
spin_lock_irqsave(&ring->execlist_lock, flags);
list_for_each_entry(cursor, &ring->execlist_queue, execlist_link)
if (++num_elements > 2)
break;
if (num_elements > 2) {
struct drm_i915_gem_request *tail_req;
tail_req = list_last_entry(&ring->execlist_queue,
struct drm_i915_gem_request,
execlist_link);
if (to == tail_req->ctx) {
WARN(tail_req->elsp_submitted != 0,
"More than 2 already-submitted reqs queued\n");
list_del(&tail_req->execlist_link);
list_add_tail(&tail_req->execlist_link,
&ring->execlist_retired_req_list);
}
}
list_add_tail(&request->execlist_link, &ring->execlist_queue);
if (num_elements == 0)
execlists_context_unqueue(ring);
spin_unlock_irqrestore(&ring->execlist_lock, flags);
return 0;
}
static int logical_ring_invalidate_all_caches(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx)
{
struct intel_engine_cs *ring = ringbuf->ring;
uint32_t flush_domains;
int ret;
flush_domains = 0;
if (ring->gpu_caches_dirty)
flush_domains = I915_GEM_GPU_DOMAINS;
ret = ring->emit_flush(ringbuf, ctx,
I915_GEM_GPU_DOMAINS, flush_domains);
if (ret)
return ret;
ring->gpu_caches_dirty = false;
return 0;
}
static int execlists_move_to_gpu(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx,
struct list_head *vmas)
{
struct intel_engine_cs *ring = ringbuf->ring;
struct i915_vma *vma;
uint32_t flush_domains = 0;
bool flush_chipset = false;
int ret;
list_for_each_entry(vma, vmas, exec_list) {
struct drm_i915_gem_object *obj = vma->obj;
ret = i915_gem_object_sync(obj, ring);
if (ret)
return ret;
if (obj->base.write_domain & I915_GEM_DOMAIN_CPU)
flush_chipset |= i915_gem_clflush_object(obj, false);
flush_domains |= obj->base.write_domain;
}
if (flush_domains & I915_GEM_DOMAIN_GTT)
wmb();
return logical_ring_invalidate_all_caches(ringbuf, ctx);
}
int intel_execlists_submission(struct drm_device *dev, struct drm_file *file,
struct intel_engine_cs *ring,
struct intel_context *ctx,
struct drm_i915_gem_execbuffer2 *args,
struct list_head *vmas,
struct drm_i915_gem_object *batch_obj,
u64 exec_start, u32 flags)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_ringbuffer *ringbuf = ctx->engine[ring->id].ringbuf;
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
if (args->num_cliprects != 0) {
DRM_DEBUG("clip rectangles are only valid on pre-gen5\n");
return -EINVAL;
} else {
if (args->DR4 == 0xffffffff) {
DRM_DEBUG("UXA submitting garbage DR4, fixing up\n");
args->DR4 = 0;
}
if (args->DR1 || args->DR4 || args->cliprects_ptr) {
DRM_DEBUG("0 cliprects but dirt in cliprects fields\n");
return -EINVAL;
}
}
if (args->flags & I915_EXEC_GEN7_SOL_RESET) {
DRM_DEBUG("sol reset is gen7 only\n");
return -EINVAL;
}
ret = execlists_move_to_gpu(ringbuf, ctx, vmas);
if (ret)
return ret;
if (ring == &dev_priv->ring[RCS] &&
instp_mode != dev_priv->relative_constants_mode) {
ret = intel_logical_ring_begin(ringbuf, ctx, 4);
if (ret)
return ret;
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_emit(ringbuf, MI_LOAD_REGISTER_IMM(1));
intel_logical_ring_emit(ringbuf, INSTPM);
intel_logical_ring_emit(ringbuf, instp_mask << 16 | instp_mode);
intel_logical_ring_advance(ringbuf);
dev_priv->relative_constants_mode = instp_mode;
}
ret = ring->emit_bb_start(ringbuf, ctx, exec_start, flags);
if (ret)
return ret;
i915_gem_execbuffer_move_to_active(vmas, ring);
i915_gem_execbuffer_retire_commands(dev, file, ring, batch_obj);
return 0;
}
void intel_execlists_retire_requests(struct intel_engine_cs *ring)
{
struct drm_i915_gem_request *req, *tmp;
struct drm_i915_private *dev_priv = ring->dev->dev_private;
unsigned long flags;
struct list_head retired_list;
WARN_ON(!mutex_is_locked(&ring->dev->struct_mutex));
if (list_empty(&ring->execlist_retired_req_list))
return;
INIT_LIST_HEAD(&retired_list);
spin_lock_irqsave(&ring->execlist_lock, flags);
list_replace_init(&ring->execlist_retired_req_list, &retired_list);
spin_unlock_irqrestore(&ring->execlist_lock, flags);
list_for_each_entry_safe(req, tmp, &retired_list, execlist_link) {
struct intel_context *ctx = req->ctx;
struct drm_i915_gem_object *ctx_obj =
ctx->engine[ring->id].state;
if (ctx_obj && (ctx != ring->default_context))
intel_lr_context_unpin(ring, ctx);
intel_runtime_pm_put(dev_priv);
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
int logical_ring_flush_all_caches(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx)
{
struct intel_engine_cs *ring = ringbuf->ring;
int ret;
if (!ring->gpu_caches_dirty)
return 0;
ret = ring->emit_flush(ringbuf, ctx, 0, I915_GEM_GPU_DOMAINS);
if (ret)
return ret;
ring->gpu_caches_dirty = false;
return 0;
}
void intel_logical_ring_advance_and_submit(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx,
struct drm_i915_gem_request *request)
{
struct intel_engine_cs *ring = ringbuf->ring;
intel_logical_ring_advance(ringbuf);
if (intel_ring_stopped(ring))
return;
execlists_context_queue(ring, ctx, ringbuf->tail, request);
}
static int intel_lr_context_pin(struct intel_engine_cs *ring,
struct intel_context *ctx)
{
struct drm_i915_gem_object *ctx_obj = ctx->engine[ring->id].state;
struct intel_ringbuffer *ringbuf = ctx->engine[ring->id].ringbuf;
int ret = 0;
WARN_ON(!mutex_is_locked(&ring->dev->struct_mutex));
if (ctx->engine[ring->id].pin_count++ == 0) {
ret = i915_gem_obj_ggtt_pin(ctx_obj,
GEN8_LR_CONTEXT_ALIGN, 0);
if (ret)
goto reset_pin_count;
ret = intel_pin_and_map_ringbuffer_obj(ring->dev, ringbuf);
if (ret)
goto unpin_ctx_obj;
}
return ret;
unpin_ctx_obj:
i915_gem_object_ggtt_unpin(ctx_obj);
reset_pin_count:
ctx->engine[ring->id].pin_count = 0;
return ret;
}
void intel_lr_context_unpin(struct intel_engine_cs *ring,
struct intel_context *ctx)
{
struct drm_i915_gem_object *ctx_obj = ctx->engine[ring->id].state;
struct intel_ringbuffer *ringbuf = ctx->engine[ring->id].ringbuf;
if (ctx_obj) {
WARN_ON(!mutex_is_locked(&ring->dev->struct_mutex));
if (--ctx->engine[ring->id].pin_count == 0) {
intel_unpin_ringbuffer_obj(ringbuf);
i915_gem_object_ggtt_unpin(ctx_obj);
}
}
}
static int logical_ring_alloc_request(struct intel_engine_cs *ring,
struct intel_context *ctx)
{
struct drm_i915_gem_request *request;
struct drm_i915_private *dev_private = ring->dev->dev_private;
int ret;
if (ring->outstanding_lazy_request)
return 0;
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (request == NULL)
return -ENOMEM;
if (ctx != ring->default_context) {
ret = intel_lr_context_pin(ring, ctx);
if (ret) {
kfree(request);
return ret;
}
}
kref_init(&request->ref);
request->ring = ring;
request->uniq = dev_private->request_uniq++;
ret = i915_gem_get_seqno(ring->dev, &request->seqno);
if (ret) {
intel_lr_context_unpin(ring, ctx);
kfree(request);
return ret;
}
request->ctx = ctx;
i915_gem_context_reference(request->ctx);
ring->outstanding_lazy_request = request;
return 0;
}
static int logical_ring_wait_request(struct intel_ringbuffer *ringbuf,
int bytes)
{
struct intel_engine_cs *ring = ringbuf->ring;
struct drm_i915_gem_request *request;
int ret;
if (intel_ring_space(ringbuf) >= bytes)
return 0;
list_for_each_entry(request, &ring->request_list, list) {
struct intel_context *ctx = request->ctx;
if (ctx->engine[ring->id].ringbuf != ringbuf)
continue;
if (__intel_ring_space(request->tail, ringbuf->tail,
ringbuf->size) >= bytes) {
break;
}
}
if (&request->list == &ring->request_list)
return -ENOSPC;
ret = i915_wait_request(request);
if (ret)
return ret;
i915_gem_retire_requests_ring(ring);
return intel_ring_space(ringbuf) >= bytes ? 0 : -ENOSPC;
}
static int logical_ring_wait_for_space(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx,
int bytes)
{
struct intel_engine_cs *ring = ringbuf->ring;
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long end;
int ret;
ret = logical_ring_wait_request(ringbuf, bytes);
if (ret != -ENOSPC)
return ret;
intel_logical_ring_advance_and_submit(ringbuf, ctx, NULL);
end = jiffies + 60 * HZ;
ret = 0;
do {
if (intel_ring_space(ringbuf) >= bytes)
break;
msleep(1);
if (dev_priv->mm.interruptible && signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
ret = i915_gem_check_wedge(&dev_priv->gpu_error,
dev_priv->mm.interruptible);
if (ret)
break;
if (time_after(jiffies, end)) {
ret = -EBUSY;
break;
}
} while (1);
return ret;
}
static int logical_ring_wrap_buffer(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx)
{
uint32_t __iomem *virt;
int rem = ringbuf->size - ringbuf->tail;
if (ringbuf->space < rem) {
int ret = logical_ring_wait_for_space(ringbuf, ctx, rem);
if (ret)
return ret;
}
virt = ringbuf->virtual_start + ringbuf->tail;
rem /= 4;
while (rem--)
iowrite32(MI_NOOP, virt++);
ringbuf->tail = 0;
intel_ring_update_space(ringbuf);
return 0;
}
static int logical_ring_prepare(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx, int bytes)
{
int ret;
if (unlikely(ringbuf->tail + bytes > ringbuf->effective_size)) {
ret = logical_ring_wrap_buffer(ringbuf, ctx);
if (unlikely(ret))
return ret;
}
if (unlikely(ringbuf->space < bytes)) {
ret = logical_ring_wait_for_space(ringbuf, ctx, bytes);
if (unlikely(ret))
return ret;
}
return 0;
}
int intel_logical_ring_begin(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx, int num_dwords)
{
struct intel_engine_cs *ring = ringbuf->ring;
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = i915_gem_check_wedge(&dev_priv->gpu_error,
dev_priv->mm.interruptible);
if (ret)
return ret;
ret = logical_ring_prepare(ringbuf, ctx, num_dwords * sizeof(uint32_t));
if (ret)
return ret;
ret = logical_ring_alloc_request(ring, ctx);
if (ret)
return ret;
ringbuf->space -= num_dwords * sizeof(uint32_t);
return 0;
}
static int intel_logical_ring_workarounds_emit(struct intel_engine_cs *ring,
struct intel_context *ctx)
{
int ret, i;
struct intel_ringbuffer *ringbuf = ctx->engine[ring->id].ringbuf;
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_workarounds *w = &dev_priv->workarounds;
if (WARN_ON_ONCE(w->count == 0))
return 0;
ring->gpu_caches_dirty = true;
ret = logical_ring_flush_all_caches(ringbuf, ctx);
if (ret)
return ret;
ret = intel_logical_ring_begin(ringbuf, ctx, w->count * 2 + 2);
if (ret)
return ret;
intel_logical_ring_emit(ringbuf, MI_LOAD_REGISTER_IMM(w->count));
for (i = 0; i < w->count; i++) {
intel_logical_ring_emit(ringbuf, w->reg[i].addr);
intel_logical_ring_emit(ringbuf, w->reg[i].value);
}
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance(ringbuf);
ring->gpu_caches_dirty = true;
ret = logical_ring_flush_all_caches(ringbuf, ctx);
if (ret)
return ret;
return 0;
}
static int gen8_init_common_ring(struct intel_engine_cs *ring)
{
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE_IMR(ring, ~(ring->irq_enable_mask | ring->irq_keep_mask));
I915_WRITE(RING_HWSTAM(ring->mmio_base), 0xffffffff);
I915_WRITE(RING_MODE_GEN7(ring),
_MASKED_BIT_DISABLE(GFX_REPLAY_MODE) |
_MASKED_BIT_ENABLE(GFX_RUN_LIST_ENABLE));
POSTING_READ(RING_MODE_GEN7(ring));
ring->next_context_status_buffer = 0;
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
static int gen8_emit_bb_start(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx,
u64 offset, unsigned flags)
{
bool ppgtt = !(flags & I915_DISPATCH_SECURE);
int ret;
ret = intel_logical_ring_begin(ringbuf, ctx, 4);
if (ret)
return ret;
intel_logical_ring_emit(ringbuf, MI_BATCH_BUFFER_START_GEN8 | (ppgtt<<8));
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
static int gen8_emit_flush(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx,
u32 invalidate_domains,
u32 unused)
{
struct intel_engine_cs *ring = ringbuf->ring;
struct drm_device *dev = ring->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
uint32_t cmd;
int ret;
ret = intel_logical_ring_begin(ringbuf, ctx, 4);
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
static int gen8_emit_flush_render(struct intel_ringbuffer *ringbuf,
struct intel_context *ctx,
u32 invalidate_domains,
u32 flush_domains)
{
struct intel_engine_cs *ring = ringbuf->ring;
u32 scratch_addr = ring->scratch.gtt_offset + 2 * CACHELINE_BYTES;
u32 flags = 0;
int ret;
flags |= PIPE_CONTROL_CS_STALL;
if (flush_domains) {
flags |= PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH;
flags |= PIPE_CONTROL_DEPTH_CACHE_FLUSH;
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
}
ret = intel_logical_ring_begin(ringbuf, ctx, 6);
if (ret)
return ret;
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
static int gen8_emit_request(struct intel_ringbuffer *ringbuf,
struct drm_i915_gem_request *request)
{
struct intel_engine_cs *ring = ringbuf->ring;
u32 cmd;
int ret;
ret = intel_logical_ring_begin(ringbuf, request->ctx, 6);
if (ret)
return ret;
cmd = MI_STORE_DWORD_IMM_GEN4;
cmd |= MI_GLOBAL_GTT;
intel_logical_ring_emit(ringbuf, cmd);
intel_logical_ring_emit(ringbuf,
(ring->status_page.gfx_addr +
(I915_GEM_HWS_INDEX << MI_STORE_DWORD_INDEX_SHIFT)));
intel_logical_ring_emit(ringbuf, 0);
intel_logical_ring_emit(ringbuf,
i915_gem_request_get_seqno(ring->outstanding_lazy_request));
intel_logical_ring_emit(ringbuf, MI_USER_INTERRUPT);
intel_logical_ring_emit(ringbuf, MI_NOOP);
intel_logical_ring_advance_and_submit(ringbuf, request->ctx, request);
return 0;
}
static int gen8_init_rcs_context(struct intel_engine_cs *ring,
struct intel_context *ctx)
{
int ret;
ret = intel_logical_ring_workarounds_emit(ring, ctx);
if (ret)
return ret;
return intel_lr_context_render_state_init(ring, ctx);
}
void intel_logical_ring_cleanup(struct intel_engine_cs *ring)
{
struct drm_i915_private *dev_priv;
if (!intel_ring_initialized(ring))
return;
dev_priv = ring->dev->dev_private;
intel_logical_ring_stop(ring);
WARN_ON((I915_READ_MODE(ring) & MODE_IDLE) == 0);
i915_gem_request_assign(&ring->outstanding_lazy_request, NULL);
if (ring->cleanup)
ring->cleanup(ring);
i915_cmd_parser_fini_ring(ring);
if (ring->status_page.obj) {
kunmap(sg_page(ring->status_page.obj->pages->sgl));
ring->status_page.obj = NULL;
}
}
static int logical_ring_init(struct drm_device *dev, struct intel_engine_cs *ring)
{
int ret;
ring->buffer = NULL;
ring->dev = dev;
INIT_LIST_HEAD(&ring->active_list);
INIT_LIST_HEAD(&ring->request_list);
init_waitqueue_head(&ring->irq_queue);
INIT_LIST_HEAD(&ring->execlist_queue);
INIT_LIST_HEAD(&ring->execlist_retired_req_list);
spin_lock_init(&ring->execlist_lock);
ret = i915_cmd_parser_init_ring(ring);
if (ret)
return ret;
ret = intel_lr_context_deferred_create(ring->default_context, ring);
return ret;
}
static int logical_render_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[RCS];
int ret;
ring->name = "render ring";
ring->id = RCS;
ring->mmio_base = RENDER_RING_BASE;
ring->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_RCS_IRQ_SHIFT;
ring->irq_keep_mask =
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_RCS_IRQ_SHIFT;
if (HAS_L3_DPF(dev))
ring->irq_keep_mask |= GT_RENDER_L3_PARITY_ERROR_INTERRUPT;
ring->init_hw = gen8_init_render_ring;
ring->init_context = gen8_init_rcs_context;
ring->cleanup = intel_fini_pipe_control;
ring->get_seqno = gen8_get_seqno;
ring->set_seqno = gen8_set_seqno;
ring->emit_request = gen8_emit_request;
ring->emit_flush = gen8_emit_flush_render;
ring->irq_get = gen8_logical_ring_get_irq;
ring->irq_put = gen8_logical_ring_put_irq;
ring->emit_bb_start = gen8_emit_bb_start;
ring->dev = dev;
ret = logical_ring_init(dev, ring);
if (ret)
return ret;
return intel_init_pipe_control(ring);
}
static int logical_bsd_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[VCS];
ring->name = "bsd ring";
ring->id = VCS;
ring->mmio_base = GEN6_BSD_RING_BASE;
ring->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_VCS1_IRQ_SHIFT;
ring->irq_keep_mask =
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_VCS1_IRQ_SHIFT;
ring->init_hw = gen8_init_common_ring;
ring->get_seqno = gen8_get_seqno;
ring->set_seqno = gen8_set_seqno;
ring->emit_request = gen8_emit_request;
ring->emit_flush = gen8_emit_flush;
ring->irq_get = gen8_logical_ring_get_irq;
ring->irq_put = gen8_logical_ring_put_irq;
ring->emit_bb_start = gen8_emit_bb_start;
return logical_ring_init(dev, ring);
}
static int logical_bsd2_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[VCS2];
ring->name = "bds2 ring";
ring->id = VCS2;
ring->mmio_base = GEN8_BSD2_RING_BASE;
ring->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_VCS2_IRQ_SHIFT;
ring->irq_keep_mask =
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_VCS2_IRQ_SHIFT;
ring->init_hw = gen8_init_common_ring;
ring->get_seqno = gen8_get_seqno;
ring->set_seqno = gen8_set_seqno;
ring->emit_request = gen8_emit_request;
ring->emit_flush = gen8_emit_flush;
ring->irq_get = gen8_logical_ring_get_irq;
ring->irq_put = gen8_logical_ring_put_irq;
ring->emit_bb_start = gen8_emit_bb_start;
return logical_ring_init(dev, ring);
}
static int logical_blt_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[BCS];
ring->name = "blitter ring";
ring->id = BCS;
ring->mmio_base = BLT_RING_BASE;
ring->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_BCS_IRQ_SHIFT;
ring->irq_keep_mask =
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_BCS_IRQ_SHIFT;
ring->init_hw = gen8_init_common_ring;
ring->get_seqno = gen8_get_seqno;
ring->set_seqno = gen8_set_seqno;
ring->emit_request = gen8_emit_request;
ring->emit_flush = gen8_emit_flush;
ring->irq_get = gen8_logical_ring_get_irq;
ring->irq_put = gen8_logical_ring_put_irq;
ring->emit_bb_start = gen8_emit_bb_start;
return logical_ring_init(dev, ring);
}
static int logical_vebox_ring_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_engine_cs *ring = &dev_priv->ring[VECS];
ring->name = "video enhancement ring";
ring->id = VECS;
ring->mmio_base = VEBOX_RING_BASE;
ring->irq_enable_mask =
GT_RENDER_USER_INTERRUPT << GEN8_VECS_IRQ_SHIFT;
ring->irq_keep_mask =
GT_CONTEXT_SWITCH_INTERRUPT << GEN8_VECS_IRQ_SHIFT;
ring->init_hw = gen8_init_common_ring;
ring->get_seqno = gen8_get_seqno;
ring->set_seqno = gen8_set_seqno;
ring->emit_request = gen8_emit_request;
ring->emit_flush = gen8_emit_flush;
ring->irq_get = gen8_logical_ring_get_irq;
ring->irq_put = gen8_logical_ring_put_irq;
ring->emit_bb_start = gen8_emit_bb_start;
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
ret = i915_gem_set_seqno(dev, ((u32)~0 - 0x1000));
if (ret)
goto cleanup_bsd2_ring;
return 0;
cleanup_bsd2_ring:
intel_logical_ring_cleanup(&dev_priv->ring[VCS2]);
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
int intel_lr_context_render_state_init(struct intel_engine_cs *ring,
struct intel_context *ctx)
{
struct intel_ringbuffer *ringbuf = ctx->engine[ring->id].ringbuf;
struct render_state so;
struct drm_i915_file_private *file_priv = ctx->file_priv;
struct drm_file *file = file_priv ? file_priv->file : NULL;
int ret;
ret = i915_gem_render_state_prepare(ring, &so);
if (ret)
return ret;
if (so.rodata == NULL)
return 0;
ret = ring->emit_bb_start(ringbuf,
ctx,
so.ggtt_offset,
I915_DISPATCH_SECURE);
if (ret)
goto out;
i915_vma_move_to_active(i915_gem_obj_to_ggtt(so.obj), ring);
ret = __i915_add_request(ring, file, so.obj);
out:
i915_gem_render_state_fini(&so);
return ret;
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
page = i915_gem_object_get_page(ctx_obj, 1);
reg_state = kmap_atomic(page);
if (ring->id == RCS)
reg_state[CTX_LRI_HEADER_0] = MI_LOAD_REGISTER_IMM(14);
else
reg_state[CTX_LRI_HEADER_0] = MI_LOAD_REGISTER_IMM(11);
reg_state[CTX_LRI_HEADER_0] |= MI_LRI_FORCE_POSTED;
reg_state[CTX_CONTEXT_CONTROL] = RING_CONTEXT_CONTROL(ring);
reg_state[CTX_CONTEXT_CONTROL+1] =
_MASKED_BIT_ENABLE((1<<3) | MI_RESTORE_INHIBIT);
reg_state[CTX_RING_HEAD] = RING_HEAD(ring->mmio_base);
reg_state[CTX_RING_HEAD+1] = 0;
reg_state[CTX_RING_TAIL] = RING_TAIL(ring->mmio_base);
reg_state[CTX_RING_TAIL+1] = 0;
reg_state[CTX_RING_BUFFER_START] = RING_START(ring->mmio_base);
reg_state[CTX_RING_BUFFER_CONTROL] = RING_CTL(ring->mmio_base);
reg_state[CTX_RING_BUFFER_CONTROL+1] =
((ringbuf->size - PAGE_SIZE) & RING_NR_PAGES) | RING_VALID;
reg_state[CTX_BB_HEAD_U] = ring->mmio_base + 0x168;
reg_state[CTX_BB_HEAD_U+1] = 0;
reg_state[CTX_BB_HEAD_L] = ring->mmio_base + 0x140;
reg_state[CTX_BB_HEAD_L+1] = 0;
reg_state[CTX_BB_STATE] = ring->mmio_base + 0x110;
reg_state[CTX_BB_STATE+1] = (1<<5);
reg_state[CTX_SECOND_BB_HEAD_U] = ring->mmio_base + 0x11c;
reg_state[CTX_SECOND_BB_HEAD_U+1] = 0;
reg_state[CTX_SECOND_BB_HEAD_L] = ring->mmio_base + 0x114;
reg_state[CTX_SECOND_BB_HEAD_L+1] = 0;
reg_state[CTX_SECOND_BB_STATE] = ring->mmio_base + 0x118;
reg_state[CTX_SECOND_BB_STATE+1] = 0;
if (ring->id == RCS) {
reg_state[CTX_BB_PER_CTX_PTR] = ring->mmio_base + 0x1c0;
reg_state[CTX_BB_PER_CTX_PTR+1] = 0;
reg_state[CTX_RCS_INDIRECT_CTX] = ring->mmio_base + 0x1c4;
reg_state[CTX_RCS_INDIRECT_CTX+1] = 0;
reg_state[CTX_RCS_INDIRECT_CTX_OFFSET] = ring->mmio_base + 0x1c8;
reg_state[CTX_RCS_INDIRECT_CTX_OFFSET+1] = 0;
}
reg_state[CTX_LRI_HEADER_1] = MI_LOAD_REGISTER_IMM(9);
reg_state[CTX_LRI_HEADER_1] |= MI_LRI_FORCE_POSTED;
reg_state[CTX_CTX_TIMESTAMP] = ring->mmio_base + 0x3a8;
reg_state[CTX_CTX_TIMESTAMP+1] = 0;
reg_state[CTX_PDP3_UDW] = GEN8_RING_PDP_UDW(ring, 3);
reg_state[CTX_PDP3_LDW] = GEN8_RING_PDP_LDW(ring, 3);
reg_state[CTX_PDP2_UDW] = GEN8_RING_PDP_UDW(ring, 2);
reg_state[CTX_PDP2_LDW] = GEN8_RING_PDP_LDW(ring, 2);
reg_state[CTX_PDP1_UDW] = GEN8_RING_PDP_UDW(ring, 1);
reg_state[CTX_PDP1_LDW] = GEN8_RING_PDP_LDW(ring, 1);
reg_state[CTX_PDP0_UDW] = GEN8_RING_PDP_UDW(ring, 0);
reg_state[CTX_PDP0_LDW] = GEN8_RING_PDP_LDW(ring, 0);
reg_state[CTX_PDP3_UDW+1] = upper_32_bits(ppgtt->pd_dma_addr[3]);
reg_state[CTX_PDP3_LDW+1] = lower_32_bits(ppgtt->pd_dma_addr[3]);
reg_state[CTX_PDP2_UDW+1] = upper_32_bits(ppgtt->pd_dma_addr[2]);
reg_state[CTX_PDP2_LDW+1] = lower_32_bits(ppgtt->pd_dma_addr[2]);
reg_state[CTX_PDP1_UDW+1] = upper_32_bits(ppgtt->pd_dma_addr[1]);
reg_state[CTX_PDP1_LDW+1] = lower_32_bits(ppgtt->pd_dma_addr[1]);
reg_state[CTX_PDP0_UDW+1] = upper_32_bits(ppgtt->pd_dma_addr[0]);
reg_state[CTX_PDP0_LDW+1] = lower_32_bits(ppgtt->pd_dma_addr[0]);
if (ring->id == RCS) {
reg_state[CTX_LRI_HEADER_2] = MI_LOAD_REGISTER_IMM(1);
reg_state[CTX_R_PWR_CLK_STATE] = 0x20c8;
reg_state[CTX_R_PWR_CLK_STATE+1] = 0;
}
kunmap_atomic(reg_state);
ctx_obj->dirty = 1;
set_page_dirty(page);
i915_gem_object_unpin_pages(ctx_obj);
return 0;
}
void intel_lr_context_free(struct intel_context *ctx)
{
int i;
for (i = 0; i < I915_NUM_RINGS; i++) {
struct drm_i915_gem_object *ctx_obj = ctx->engine[i].state;
if (ctx_obj) {
struct intel_ringbuffer *ringbuf =
ctx->engine[i].ringbuf;
struct intel_engine_cs *ring = ringbuf->ring;
if (ctx == ring->default_context) {
intel_unpin_ringbuffer_obj(ringbuf);
i915_gem_object_ggtt_unpin(ctx_obj);
}
WARN_ON(ctx->engine[ring->id].pin_count);
intel_destroy_ringbuffer_obj(ringbuf);
kfree(ringbuf);
drm_gem_object_unreference(&ctx_obj->base);
}
}
}
static uint32_t get_lr_context_size(struct intel_engine_cs *ring)
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
ring->status_page.gfx_addr = i915_gem_obj_ggtt_offset(default_ctx_obj);
ring->status_page.page_addr =
kmap(sg_page(default_ctx_obj->pages->sgl));
ring->status_page.obj = default_ctx_obj;
I915_WRITE(RING_HWS_PGA(ring->mmio_base),
(u32)ring->status_page.gfx_addr);
POSTING_READ(RING_HWS_PGA(ring->mmio_base));
}
int intel_lr_context_deferred_create(struct intel_context *ctx,
struct intel_engine_cs *ring)
{
const bool is_global_default_ctx = (ctx == ring->default_context);
struct drm_device *dev = ring->dev;
struct drm_i915_gem_object *ctx_obj;
uint32_t context_size;
struct intel_ringbuffer *ringbuf;
int ret;
WARN_ON(ctx->legacy_hw_ctx.rcs_state != NULL);
WARN_ON(ctx->engine[ring->id].state);
context_size = round_up(get_lr_context_size(ring), 4096);
ctx_obj = i915_gem_alloc_context_obj(dev, context_size);
if (IS_ERR(ctx_obj)) {
ret = PTR_ERR(ctx_obj);
DRM_DEBUG_DRIVER("Alloc LRC backing obj failed: %d\n", ret);
return ret;
}
if (is_global_default_ctx) {
ret = i915_gem_obj_ggtt_pin(ctx_obj, GEN8_LR_CONTEXT_ALIGN, 0);
if (ret) {
DRM_DEBUG_DRIVER("Pin LRC backing obj failed: %d\n",
ret);
drm_gem_object_unreference(&ctx_obj->base);
return ret;
}
}
ringbuf = kzalloc(sizeof(*ringbuf), GFP_KERNEL);
if (!ringbuf) {
DRM_DEBUG_DRIVER("Failed to allocate ringbuffer %s\n",
ring->name);
ret = -ENOMEM;
goto error_unpin_ctx;
}
ringbuf->ring = ring;
ringbuf->size = 32 * PAGE_SIZE;
ringbuf->effective_size = ringbuf->size;
ringbuf->head = 0;
ringbuf->tail = 0;
ringbuf->last_retired_head = -1;
intel_ring_update_space(ringbuf);
if (ringbuf->obj == NULL) {
ret = intel_alloc_ringbuffer_obj(dev, ringbuf);
if (ret) {
DRM_DEBUG_DRIVER(
"Failed to allocate ringbuffer obj %s: %d\n",
ring->name, ret);
goto error_free_rbuf;
}
if (is_global_default_ctx) {
ret = intel_pin_and_map_ringbuffer_obj(dev, ringbuf);
if (ret) {
DRM_ERROR(
"Failed to pin and map ringbuffer %s: %d\n",
ring->name, ret);
goto error_destroy_rbuf;
}
}
}
ret = populate_lr_context(ctx, ctx_obj, ring, ringbuf);
if (ret) {
DRM_DEBUG_DRIVER("Failed to populate LRC: %d\n", ret);
goto error;
}
ctx->engine[ring->id].ringbuf = ringbuf;
ctx->engine[ring->id].state = ctx_obj;
if (ctx == ring->default_context)
lrc_setup_hardware_status_page(ring, ctx_obj);
else if (ring->id == RCS && !ctx->rcs_initialized) {
if (ring->init_context) {
ret = ring->init_context(ring, ctx);
if (ret) {
DRM_ERROR("ring init context: %d\n", ret);
ctx->engine[ring->id].ringbuf = NULL;
ctx->engine[ring->id].state = NULL;
goto error;
}
}
ctx->rcs_initialized = true;
}
return 0;
error:
if (is_global_default_ctx)
intel_unpin_ringbuffer_obj(ringbuf);
error_destroy_rbuf:
intel_destroy_ringbuffer_obj(ringbuf);
error_free_rbuf:
kfree(ringbuf);
error_unpin_ctx:
if (is_global_default_ctx)
i915_gem_object_ggtt_unpin(ctx_obj);
drm_gem_object_unreference(&ctx_obj->base);
return ret;
}
