static size_t get_context_alignment(struct drm_i915_private *dev_priv)
{
if (IS_GEN6(dev_priv))
return GEN6_CONTEXT_ALIGN;
return GEN7_CONTEXT_ALIGN;
}
static int get_context_size(struct drm_i915_private *dev_priv)
{
int ret;
u32 reg;
switch (INTEL_GEN(dev_priv)) {
case 6:
reg = I915_READ(CXT_SIZE);
ret = GEN6_CXT_TOTAL_SIZE(reg) * 64;
break;
case 7:
reg = I915_READ(GEN7_CXT_SIZE);
if (IS_HASWELL(dev_priv))
ret = HSW_CXT_TOTAL_SIZE;
else
ret = GEN7_CXT_TOTAL_SIZE(reg) * 64;
break;
case 8:
ret = GEN8_CXT_TOTAL_SIZE;
break;
default:
BUG();
}
return ret;
}
void i915_gem_context_free(struct kref *ctx_ref)
{
struct i915_gem_context *ctx = container_of(ctx_ref, typeof(*ctx), ref);
int i;
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
trace_i915_context_free(ctx);
GEM_BUG_ON(!ctx->closed);
i915_ppgtt_put(ctx->ppgtt);
for (i = 0; i < I915_NUM_ENGINES; i++) {
struct intel_context *ce = &ctx->engine[i];
if (!ce->state)
continue;
WARN_ON(ce->pin_count);
if (ce->ring)
intel_ring_free(ce->ring);
__i915_gem_object_release_unless_active(ce->state->obj);
}
kfree(ctx->name);
put_pid(ctx->pid);
list_del(&ctx->link);
ida_simple_remove(&ctx->i915->context_hw_ida, ctx->hw_id);
kfree(ctx);
}
struct drm_i915_gem_object *
i915_gem_alloc_context_obj(struct drm_device *dev, size_t size)
{
struct drm_i915_gem_object *obj;
int ret;
lockdep_assert_held(&dev->struct_mutex);
obj = i915_gem_object_create(dev, size);
if (IS_ERR(obj))
return obj;
if (IS_IVYBRIDGE(to_i915(dev))) {
ret = i915_gem_object_set_cache_level(obj, I915_CACHE_L3_LLC);
if (WARN_ON(ret)) {
i915_gem_object_put(obj);
return ERR_PTR(ret);
}
}
return obj;
}
static void i915_ppgtt_close(struct i915_address_space *vm)
{
struct list_head *phases[] = {
&vm->active_list,
&vm->inactive_list,
&vm->unbound_list,
NULL,
}, **phase;
GEM_BUG_ON(vm->closed);
vm->closed = true;
for (phase = phases; *phase; phase++) {
struct i915_vma *vma, *vn;
list_for_each_entry_safe(vma, vn, *phase, vm_link)
if (!i915_vma_is_closed(vma))
i915_vma_close(vma);
}
}
static void context_close(struct i915_gem_context *ctx)
{
GEM_BUG_ON(ctx->closed);
ctx->closed = true;
if (ctx->ppgtt)
i915_ppgtt_close(&ctx->ppgtt->base);
ctx->file_priv = ERR_PTR(-EBADF);
i915_gem_context_put(ctx);
}
static int assign_hw_id(struct drm_i915_private *dev_priv, unsigned *out)
{
int ret;
ret = ida_simple_get(&dev_priv->context_hw_ida,
0, MAX_CONTEXT_HW_ID, GFP_KERNEL);
if (ret < 0) {
i915_gem_retire_requests(dev_priv);
ret = ida_simple_get(&dev_priv->context_hw_ida,
0, MAX_CONTEXT_HW_ID, GFP_KERNEL);
if (ret < 0)
return ret;
}
*out = ret;
return 0;
}
static struct i915_gem_context *
__create_hw_context(struct drm_device *dev,
struct drm_i915_file_private *file_priv)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_gem_context *ctx;
int ret;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (ctx == NULL)
return ERR_PTR(-ENOMEM);
ret = assign_hw_id(dev_priv, &ctx->hw_id);
if (ret) {
kfree(ctx);
return ERR_PTR(ret);
}
kref_init(&ctx->ref);
list_add_tail(&ctx->link, &dev_priv->context_list);
ctx->i915 = dev_priv;
ctx->ggtt_alignment = get_context_alignment(dev_priv);
if (dev_priv->hw_context_size) {
struct drm_i915_gem_object *obj;
struct i915_vma *vma;
obj = i915_gem_alloc_context_obj(dev,
dev_priv->hw_context_size);
if (IS_ERR(obj)) {
ret = PTR_ERR(obj);
goto err_out;
}
vma = i915_vma_create(obj, &dev_priv->ggtt.base, NULL);
if (IS_ERR(vma)) {
i915_gem_object_put(obj);
ret = PTR_ERR(vma);
goto err_out;
}
ctx->engine[RCS].state = vma;
}
ret = DEFAULT_CONTEXT_HANDLE;
if (file_priv) {
ret = idr_alloc(&file_priv->context_idr, ctx,
DEFAULT_CONTEXT_HANDLE, 0, GFP_KERNEL);
if (ret < 0)
goto err_out;
}
ctx->user_handle = ret;
ctx->file_priv = file_priv;
if (file_priv) {
ctx->pid = get_task_pid(current, PIDTYPE_PID);
ctx->name = kasprintf(GFP_KERNEL, "%s[%d]/%x",
current->comm,
pid_nr(ctx->pid),
ctx->user_handle);
if (!ctx->name) {
ret = -ENOMEM;
goto err_pid;
}
}
ctx->remap_slice = ALL_L3_SLICES(dev_priv);
ctx->hang_stats.ban_period_seconds = DRM_I915_CTX_BAN_PERIOD;
ctx->ring_size = 4 * PAGE_SIZE;
ctx->desc_template = GEN8_CTX_ADDRESSING_MODE(dev_priv) <<
GEN8_CTX_ADDRESSING_MODE_SHIFT;
ATOMIC_INIT_NOTIFIER_HEAD(&ctx->status_notifier);
return ctx;
err_pid:
put_pid(ctx->pid);
idr_remove(&file_priv->context_idr, ctx->user_handle);
err_out:
context_close(ctx);
return ERR_PTR(ret);
}
static struct i915_gem_context *
i915_gem_create_context(struct drm_device *dev,
struct drm_i915_file_private *file_priv)
{
struct i915_gem_context *ctx;
lockdep_assert_held(&dev->struct_mutex);
ctx = __create_hw_context(dev, file_priv);
if (IS_ERR(ctx))
return ctx;
if (USES_FULL_PPGTT(dev)) {
struct i915_hw_ppgtt *ppgtt;
ppgtt = i915_ppgtt_create(to_i915(dev), file_priv, ctx->name);
if (IS_ERR(ppgtt)) {
DRM_DEBUG_DRIVER("PPGTT setup failed (%ld)\n",
PTR_ERR(ppgtt));
idr_remove(&file_priv->context_idr, ctx->user_handle);
context_close(ctx);
return ERR_CAST(ppgtt);
}
ctx->ppgtt = ppgtt;
}
trace_i915_context_create(ctx);
return ctx;
}
struct i915_gem_context *
i915_gem_context_create_gvt(struct drm_device *dev)
{
struct i915_gem_context *ctx;
int ret;
if (!IS_ENABLED(CONFIG_DRM_I915_GVT))
return ERR_PTR(-ENODEV);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ERR_PTR(ret);
ctx = i915_gem_create_context(dev, NULL);
if (IS_ERR(ctx))
goto out;
ctx->execlists_force_single_submission = true;
ctx->ring_size = 512 * PAGE_SIZE;
out:
mutex_unlock(&dev->struct_mutex);
return ctx;
}
static void i915_gem_context_unpin(struct i915_gem_context *ctx,
struct intel_engine_cs *engine)
{
if (i915.enable_execlists) {
intel_lr_context_unpin(ctx, engine);
} else {
struct intel_context *ce = &ctx->engine[engine->id];
if (ce->state)
i915_vma_unpin(ce->state);
i915_gem_context_put(ctx);
}
}
int i915_gem_context_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_gem_context *ctx;
if (WARN_ON(dev_priv->kernel_context))
return 0;
if (intel_vgpu_active(dev_priv) &&
HAS_LOGICAL_RING_CONTEXTS(dev_priv)) {
if (!i915.enable_execlists) {
DRM_INFO("Only EXECLIST mode is supported in vgpu.\n");
return -EINVAL;
}
}
BUILD_BUG_ON(MAX_CONTEXT_HW_ID > INT_MAX);
ida_init(&dev_priv->context_hw_ida);
if (i915.enable_execlists) {
dev_priv->hw_context_size = 0;
} else if (HAS_HW_CONTEXTS(dev_priv)) {
dev_priv->hw_context_size =
round_up(get_context_size(dev_priv), 4096);
if (dev_priv->hw_context_size > (1<<20)) {
DRM_DEBUG_DRIVER("Disabling HW Contexts; invalid size %d\n",
dev_priv->hw_context_size);
dev_priv->hw_context_size = 0;
}
}
ctx = i915_gem_create_context(dev, NULL);
if (IS_ERR(ctx)) {
DRM_ERROR("Failed to create default global context (error %ld)\n",
PTR_ERR(ctx));
return PTR_ERR(ctx);
}
ctx->priority = I915_PRIORITY_MIN;
dev_priv->kernel_context = ctx;
DRM_DEBUG_DRIVER("%s context support initialized\n",
i915.enable_execlists ? "LR" :
dev_priv->hw_context_size ? "HW" : "fake");
return 0;
}
void i915_gem_context_lost(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
for_each_engine(engine, dev_priv, id) {
if (engine->last_context) {
i915_gem_context_unpin(engine->last_context, engine);
engine->last_context = NULL;
}
}
if (!i915.enable_execlists) {
struct i915_gem_context *ctx;
list_for_each_entry(ctx, &dev_priv->context_list, link) {
if (!i915_gem_context_is_default(ctx))
continue;
for_each_engine(engine, dev_priv, id)
ctx->engine[engine->id].initialised = false;
ctx->remap_slice = ALL_L3_SLICES(dev_priv);
}
for_each_engine(engine, dev_priv, id) {
struct intel_context *kce =
&dev_priv->kernel_context->engine[engine->id];
kce->initialised = true;
}
}
}
void i915_gem_context_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_gem_context *dctx = dev_priv->kernel_context;
lockdep_assert_held(&dev->struct_mutex);
context_close(dctx);
dev_priv->kernel_context = NULL;
ida_destroy(&dev_priv->context_hw_ida);
}
static int context_idr_cleanup(int id, void *p, void *data)
{
struct i915_gem_context *ctx = p;
context_close(ctx);
return 0;
}
int i915_gem_context_open(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct i915_gem_context *ctx;
idr_init(&file_priv->context_idr);
mutex_lock(&dev->struct_mutex);
ctx = i915_gem_create_context(dev, file_priv);
mutex_unlock(&dev->struct_mutex);
if (IS_ERR(ctx)) {
idr_destroy(&file_priv->context_idr);
return PTR_ERR(ctx);
}
return 0;
}
void i915_gem_context_close(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
lockdep_assert_held(&dev->struct_mutex);
idr_for_each(&file_priv->context_idr, context_idr_cleanup, NULL);
idr_destroy(&file_priv->context_idr);
}
static inline int
mi_set_context(struct drm_i915_gem_request *req, u32 hw_flags)
{
struct drm_i915_private *dev_priv = req->i915;
struct intel_ring *ring = req->ring;
struct intel_engine_cs *engine = req->engine;
enum intel_engine_id id;
u32 flags = hw_flags | MI_MM_SPACE_GTT;
const int num_rings =
i915.semaphores ?
INTEL_INFO(dev_priv)->num_rings - 1 :
0;
int len, ret;
if (IS_GEN6(dev_priv)) {
ret = engine->emit_flush(req, EMIT_INVALIDATE);
if (ret)
return ret;
}
if (IS_HASWELL(dev_priv) || INTEL_GEN(dev_priv) >= 8)
flags |= (HSW_MI_RS_SAVE_STATE_EN | HSW_MI_RS_RESTORE_STATE_EN);
else if (INTEL_GEN(dev_priv) < 8)
flags |= (MI_SAVE_EXT_STATE_EN | MI_RESTORE_EXT_STATE_EN);
len = 4;
if (INTEL_GEN(dev_priv) >= 7)
len += 2 + (num_rings ? 4*num_rings + 6 : 0);
ret = intel_ring_begin(req, len);
if (ret)
return ret;
if (INTEL_GEN(dev_priv) >= 7) {
intel_ring_emit(ring, MI_ARB_ON_OFF | MI_ARB_DISABLE);
if (num_rings) {
struct intel_engine_cs *signaller;
intel_ring_emit(ring,
MI_LOAD_REGISTER_IMM(num_rings));
for_each_engine(signaller, dev_priv, id) {
if (signaller == engine)
continue;
intel_ring_emit_reg(ring,
RING_PSMI_CTL(signaller->mmio_base));
intel_ring_emit(ring,
_MASKED_BIT_ENABLE(GEN6_PSMI_SLEEP_MSG_DISABLE));
}
}
}
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_SET_CONTEXT);
intel_ring_emit(ring,
i915_ggtt_offset(req->ctx->engine[RCS].state) | flags);
intel_ring_emit(ring, MI_NOOP);
if (INTEL_GEN(dev_priv) >= 7) {
if (num_rings) {
struct intel_engine_cs *signaller;
i915_reg_t last_reg = {};
intel_ring_emit(ring,
MI_LOAD_REGISTER_IMM(num_rings));
for_each_engine(signaller, dev_priv, id) {
if (signaller == engine)
continue;
last_reg = RING_PSMI_CTL(signaller->mmio_base);
intel_ring_emit_reg(ring, last_reg);
intel_ring_emit(ring,
_MASKED_BIT_DISABLE(GEN6_PSMI_SLEEP_MSG_DISABLE));
}
intel_ring_emit(ring,
MI_STORE_REGISTER_MEM |
MI_SRM_LRM_GLOBAL_GTT);
intel_ring_emit_reg(ring, last_reg);
intel_ring_emit(ring,
i915_ggtt_offset(engine->scratch));
intel_ring_emit(ring, MI_NOOP);
}
intel_ring_emit(ring, MI_ARB_ON_OFF | MI_ARB_ENABLE);
}
intel_ring_advance(ring);
return ret;
}
static int remap_l3(struct drm_i915_gem_request *req, int slice)
{
u32 *remap_info = req->i915->l3_parity.remap_info[slice];
struct intel_ring *ring = req->ring;
int i, ret;
if (!remap_info)
return 0;
ret = intel_ring_begin(req, GEN7_L3LOG_SIZE/4 * 2 + 2);
if (ret)
return ret;
intel_ring_emit(ring, MI_LOAD_REGISTER_IMM(GEN7_L3LOG_SIZE/4));
for (i = 0; i < GEN7_L3LOG_SIZE/4; i++) {
intel_ring_emit_reg(ring, GEN7_L3LOG(slice, i));
intel_ring_emit(ring, remap_info[i]);
}
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return 0;
}
static inline bool skip_rcs_switch(struct i915_hw_ppgtt *ppgtt,
struct intel_engine_cs *engine,
struct i915_gem_context *to)
{
if (to->remap_slice)
return false;
if (!to->engine[RCS].initialised)
return false;
if (ppgtt && (intel_engine_flag(engine) & ppgtt->pd_dirty_rings))
return false;
return to == engine->last_context;
}
static bool
needs_pd_load_pre(struct i915_hw_ppgtt *ppgtt,
struct intel_engine_cs *engine,
struct i915_gem_context *to)
{
if (!ppgtt)
return false;
if (!engine->last_context)
return true;
if (engine->last_context == to &&
!(intel_engine_flag(engine) & ppgtt->pd_dirty_rings))
return false;
if (engine->id != RCS)
return true;
if (INTEL_GEN(engine->i915) < 8)
return true;
return false;
}
static bool
needs_pd_load_post(struct i915_hw_ppgtt *ppgtt,
struct i915_gem_context *to,
u32 hw_flags)
{
if (!ppgtt)
return false;
if (!IS_GEN8(to->i915))
return false;
if (hw_flags & MI_RESTORE_INHIBIT)
return true;
return false;
}
struct i915_vma *
i915_gem_context_pin_legacy(struct i915_gem_context *ctx,
unsigned int flags)
{
struct i915_vma *vma = ctx->engine[RCS].state;
int ret;
if (!(vma->flags & I915_VMA_GLOBAL_BIND)) {
ret = i915_gem_object_set_to_gtt_domain(vma->obj, false);
if (ret)
return ERR_PTR(ret);
}
ret = i915_vma_pin(vma, 0, ctx->ggtt_alignment, PIN_GLOBAL | flags);
if (ret)
return ERR_PTR(ret);
return vma;
}
static int do_rcs_switch(struct drm_i915_gem_request *req)
{
struct i915_gem_context *to = req->ctx;
struct intel_engine_cs *engine = req->engine;
struct i915_hw_ppgtt *ppgtt = to->ppgtt ?: req->i915->mm.aliasing_ppgtt;
struct i915_vma *vma;
struct i915_gem_context *from;
u32 hw_flags;
int ret, i;
if (skip_rcs_switch(ppgtt, engine, to))
return 0;
vma = i915_gem_context_pin_legacy(to, 0);
if (IS_ERR(vma))
return PTR_ERR(vma);
from = engine->last_context;
if (needs_pd_load_pre(ppgtt, engine, to)) {
trace_switch_mm(engine, to);
ret = ppgtt->switch_mm(ppgtt, req);
if (ret)
goto err;
}
if (!to->engine[RCS].initialised || i915_gem_context_is_default(to))
hw_flags = MI_RESTORE_INHIBIT;
else if (ppgtt && intel_engine_flag(engine) & ppgtt->pd_dirty_rings)
hw_flags = MI_FORCE_RESTORE;
else
hw_flags = 0;
if (to != from || (hw_flags & MI_FORCE_RESTORE)) {
ret = mi_set_context(req, hw_flags);
if (ret)
goto err;
}
if (from != NULL) {
i915_vma_move_to_active(from->engine[RCS].state, req, 0);
i915_vma_unpin(from->engine[RCS].state);
i915_gem_context_put(from);
}
engine->last_context = i915_gem_context_get(to);
if (needs_pd_load_post(ppgtt, to, hw_flags)) {
trace_switch_mm(engine, to);
ret = ppgtt->switch_mm(ppgtt, req);
if (ret)
return ret;
}
if (ppgtt)
ppgtt->pd_dirty_rings &= ~intel_engine_flag(engine);
for (i = 0; i < MAX_L3_SLICES; i++) {
if (!(to->remap_slice & (1<<i)))
continue;
ret = remap_l3(req, i);
if (ret)
return ret;
to->remap_slice &= ~(1<<i);
}
if (!to->engine[RCS].initialised) {
if (engine->init_context) {
ret = engine->init_context(req);
if (ret)
return ret;
}
to->engine[RCS].initialised = true;
}
return 0;
err:
i915_vma_unpin(vma);
return ret;
}
int i915_switch_context(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
lockdep_assert_held(&req->i915->drm.struct_mutex);
if (i915.enable_execlists)
return 0;
if (!req->ctx->engine[engine->id].state) {
struct i915_gem_context *to = req->ctx;
struct i915_hw_ppgtt *ppgtt =
to->ppgtt ?: req->i915->mm.aliasing_ppgtt;
if (needs_pd_load_pre(ppgtt, engine, to)) {
int ret;
trace_switch_mm(engine, to);
ret = ppgtt->switch_mm(ppgtt, req);
if (ret)
return ret;
ppgtt->pd_dirty_rings &= ~intel_engine_flag(engine);
}
if (to != engine->last_context) {
if (engine->last_context)
i915_gem_context_put(engine->last_context);
engine->last_context = i915_gem_context_get(to);
}
return 0;
}
return do_rcs_switch(req);
}
int i915_gem_switch_to_kernel_context(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
struct i915_gem_timeline *timeline;
enum intel_engine_id id;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
for_each_engine(engine, dev_priv, id) {
struct drm_i915_gem_request *req;
int ret;
req = i915_gem_request_alloc(engine, dev_priv->kernel_context);
if (IS_ERR(req))
return PTR_ERR(req);
list_for_each_entry(timeline, &dev_priv->gt.timelines, link) {
struct drm_i915_gem_request *prev;
struct intel_timeline *tl;
tl = &timeline->engine[engine->id];
prev = i915_gem_active_raw(&tl->last_request,
&dev_priv->drm.struct_mutex);
if (prev)
i915_sw_fence_await_sw_fence_gfp(&req->submit,
&prev->submit,
GFP_KERNEL);
}
ret = i915_switch_context(req);
i915_add_request_no_flush(req);
if (ret)
return ret;
}
return 0;
}
static bool contexts_enabled(struct drm_device *dev)
{
return i915.enable_execlists || to_i915(dev)->hw_context_size;
}
int i915_gem_context_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_context_create *args = data;
struct drm_i915_file_private *file_priv = file->driver_priv;
struct i915_gem_context *ctx;
int ret;
if (!contexts_enabled(dev))
return -ENODEV;
if (args->pad != 0)
return -EINVAL;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_create_context(dev, file_priv);
mutex_unlock(&dev->struct_mutex);
if (IS_ERR(ctx))
return PTR_ERR(ctx);
args->ctx_id = ctx->user_handle;
DRM_DEBUG_DRIVER("HW context %d created\n", args->ctx_id);
return 0;
}
int i915_gem_context_destroy_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_context_destroy *args = data;
struct drm_i915_file_private *file_priv = file->driver_priv;
struct i915_gem_context *ctx;
int ret;
if (args->pad != 0)
return -EINVAL;
if (args->ctx_id == DEFAULT_CONTEXT_HANDLE)
return -ENOENT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_lookup(file_priv, args->ctx_id);
if (IS_ERR(ctx)) {
mutex_unlock(&dev->struct_mutex);
return PTR_ERR(ctx);
}
idr_remove(&file_priv->context_idr, ctx->user_handle);
context_close(ctx);
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG_DRIVER("HW context %d destroyed\n", args->ctx_id);
return 0;
}
int i915_gem_context_getparam_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct drm_i915_gem_context_param *args = data;
struct i915_gem_context *ctx;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_lookup(file_priv, args->ctx_id);
if (IS_ERR(ctx)) {
mutex_unlock(&dev->struct_mutex);
return PTR_ERR(ctx);
}
args->size = 0;
switch (args->param) {
case I915_CONTEXT_PARAM_BAN_PERIOD:
args->value = ctx->hang_stats.ban_period_seconds;
break;
case I915_CONTEXT_PARAM_NO_ZEROMAP:
args->value = ctx->flags & CONTEXT_NO_ZEROMAP;
break;
case I915_CONTEXT_PARAM_GTT_SIZE:
if (ctx->ppgtt)
args->value = ctx->ppgtt->base.total;
else if (to_i915(dev)->mm.aliasing_ppgtt)
args->value = to_i915(dev)->mm.aliasing_ppgtt->base.total;
else
args->value = to_i915(dev)->ggtt.base.total;
break;
case I915_CONTEXT_PARAM_NO_ERROR_CAPTURE:
args->value = !!(ctx->flags & CONTEXT_NO_ERROR_CAPTURE);
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&dev->struct_mutex);
return ret;
}
int i915_gem_context_setparam_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct drm_i915_gem_context_param *args = data;
struct i915_gem_context *ctx;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_lookup(file_priv, args->ctx_id);
if (IS_ERR(ctx)) {
mutex_unlock(&dev->struct_mutex);
return PTR_ERR(ctx);
}
switch (args->param) {
case I915_CONTEXT_PARAM_BAN_PERIOD:
if (args->size)
ret = -EINVAL;
else if (args->value < ctx->hang_stats.ban_period_seconds &&
!capable(CAP_SYS_ADMIN))
ret = -EPERM;
else
ctx->hang_stats.ban_period_seconds = args->value;
break;
case I915_CONTEXT_PARAM_NO_ZEROMAP:
if (args->size) {
ret = -EINVAL;
} else {
ctx->flags &= ~CONTEXT_NO_ZEROMAP;
ctx->flags |= args->value ? CONTEXT_NO_ZEROMAP : 0;
}
break;
case I915_CONTEXT_PARAM_NO_ERROR_CAPTURE:
if (args->size) {
ret = -EINVAL;
} else {
if (args->value)
ctx->flags |= CONTEXT_NO_ERROR_CAPTURE;
else
ctx->flags &= ~CONTEXT_NO_ERROR_CAPTURE;
}
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&dev->struct_mutex);
return ret;
}
int i915_gem_context_reset_stats_ioctl(struct drm_device *dev,
void *data, struct drm_file *file)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_reset_stats *args = data;
struct i915_ctx_hang_stats *hs;
struct i915_gem_context *ctx;
int ret;
if (args->flags || args->pad)
return -EINVAL;
if (args->ctx_id == DEFAULT_CONTEXT_HANDLE && !capable(CAP_SYS_ADMIN))
return -EPERM;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_lookup(file->driver_priv, args->ctx_id);
if (IS_ERR(ctx)) {
mutex_unlock(&dev->struct_mutex);
return PTR_ERR(ctx);
}
hs = &ctx->hang_stats;
if (capable(CAP_SYS_ADMIN))
args->reset_count = i915_reset_count(&dev_priv->gpu_error);
else
args->reset_count = 0;
args->batch_active = hs->batch_active;
args->batch_pending = hs->batch_pending;
mutex_unlock(&dev->struct_mutex);
return 0;
}
