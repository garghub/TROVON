static size_t get_context_alignment(struct drm_device *dev)
{
if (IS_GEN6(dev))
return GEN6_CONTEXT_ALIGN;
return GEN7_CONTEXT_ALIGN;
}
static int get_context_size(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
u32 reg;
switch (INTEL_INFO(dev)->gen) {
case 6:
reg = I915_READ(CXT_SIZE);
ret = GEN6_CXT_TOTAL_SIZE(reg) * 64;
break;
case 7:
reg = I915_READ(GEN7_CXT_SIZE);
if (IS_HASWELL(dev))
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
static void i915_gem_context_clean(struct intel_context *ctx)
{
struct i915_hw_ppgtt *ppgtt = ctx->ppgtt;
struct i915_vma *vma, *next;
if (!ppgtt)
return;
list_for_each_entry_safe(vma, next, &ppgtt->base.inactive_list,
vm_link) {
if (WARN_ON(__i915_vma_unbind_no_wait(vma)))
break;
}
}
void i915_gem_context_free(struct kref *ctx_ref)
{
struct intel_context *ctx = container_of(ctx_ref, typeof(*ctx), ref);
trace_i915_context_free(ctx);
if (i915.enable_execlists)
intel_lr_context_free(ctx);
i915_gem_context_clean(ctx);
i915_ppgtt_put(ctx->ppgtt);
if (ctx->legacy_hw_ctx.rcs_state)
drm_gem_object_unreference(&ctx->legacy_hw_ctx.rcs_state->base);
list_del(&ctx->link);
kfree(ctx);
}
struct drm_i915_gem_object *
i915_gem_alloc_context_obj(struct drm_device *dev, size_t size)
{
struct drm_i915_gem_object *obj;
int ret;
obj = i915_gem_alloc_object(dev, size);
if (obj == NULL)
return ERR_PTR(-ENOMEM);
if (IS_IVYBRIDGE(dev)) {
ret = i915_gem_object_set_cache_level(obj, I915_CACHE_L3_LLC);
if (WARN_ON(ret)) {
drm_gem_object_unreference(&obj->base);
return ERR_PTR(ret);
}
}
return obj;
}
static struct intel_context *
__create_hw_context(struct drm_device *dev,
struct drm_i915_file_private *file_priv)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_context *ctx;
int ret;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (ctx == NULL)
return ERR_PTR(-ENOMEM);
kref_init(&ctx->ref);
list_add_tail(&ctx->link, &dev_priv->context_list);
ctx->i915 = dev_priv;
if (dev_priv->hw_context_size) {
struct drm_i915_gem_object *obj =
i915_gem_alloc_context_obj(dev, dev_priv->hw_context_size);
if (IS_ERR(obj)) {
ret = PTR_ERR(obj);
goto err_out;
}
ctx->legacy_hw_ctx.rcs_state = obj;
}
if (file_priv != NULL) {
ret = idr_alloc(&file_priv->context_idr, ctx,
DEFAULT_CONTEXT_HANDLE, 0, GFP_KERNEL);
if (ret < 0)
goto err_out;
} else
ret = DEFAULT_CONTEXT_HANDLE;
ctx->file_priv = file_priv;
ctx->user_handle = ret;
ctx->remap_slice = (1 << NUM_L3_SLICES(dev)) - 1;
ctx->hang_stats.ban_period_seconds = DRM_I915_CTX_BAN_PERIOD;
return ctx;
err_out:
i915_gem_context_unreference(ctx);
return ERR_PTR(ret);
}
static struct intel_context *
i915_gem_create_context(struct drm_device *dev,
struct drm_i915_file_private *file_priv)
{
const bool is_global_default_ctx = file_priv == NULL;
struct intel_context *ctx;
int ret = 0;
BUG_ON(!mutex_is_locked(&dev->struct_mutex));
ctx = __create_hw_context(dev, file_priv);
if (IS_ERR(ctx))
return ctx;
if (is_global_default_ctx && ctx->legacy_hw_ctx.rcs_state) {
ret = i915_gem_obj_ggtt_pin(ctx->legacy_hw_ctx.rcs_state,
get_context_alignment(dev), 0);
if (ret) {
DRM_DEBUG_DRIVER("Couldn't pin %d\n", ret);
goto err_destroy;
}
}
if (USES_FULL_PPGTT(dev)) {
struct i915_hw_ppgtt *ppgtt = i915_ppgtt_create(dev, file_priv);
if (IS_ERR_OR_NULL(ppgtt)) {
DRM_DEBUG_DRIVER("PPGTT setup failed (%ld)\n",
PTR_ERR(ppgtt));
ret = PTR_ERR(ppgtt);
goto err_unpin;
}
ctx->ppgtt = ppgtt;
}
trace_i915_context_create(ctx);
return ctx;
err_unpin:
if (is_global_default_ctx && ctx->legacy_hw_ctx.rcs_state)
i915_gem_object_ggtt_unpin(ctx->legacy_hw_ctx.rcs_state);
err_destroy:
idr_remove(&file_priv->context_idr, ctx->user_handle);
i915_gem_context_unreference(ctx);
return ERR_PTR(ret);
}
static void i915_gem_context_unpin(struct intel_context *ctx,
struct intel_engine_cs *engine)
{
if (i915.enable_execlists) {
intel_lr_context_unpin(ctx, engine);
} else {
if (engine->id == RCS && ctx->legacy_hw_ctx.rcs_state)
i915_gem_object_ggtt_unpin(ctx->legacy_hw_ctx.rcs_state);
i915_gem_context_unreference(ctx);
}
}
void i915_gem_context_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
if (i915.enable_execlists) {
struct intel_context *ctx;
list_for_each_entry(ctx, &dev_priv->context_list, link)
intel_lr_context_reset(dev_priv, ctx);
}
for (i = 0; i < I915_NUM_ENGINES; i++) {
struct intel_engine_cs *engine = &dev_priv->engine[i];
if (engine->last_context) {
i915_gem_context_unpin(engine->last_context, engine);
engine->last_context = NULL;
}
}
dev_priv->kernel_context->legacy_hw_ctx.initialized = false;
}
int i915_gem_context_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_context *ctx;
if (WARN_ON(dev_priv->kernel_context))
return 0;
if (intel_vgpu_active(dev) && HAS_LOGICAL_RING_CONTEXTS(dev)) {
if (!i915.enable_execlists) {
DRM_INFO("Only EXECLIST mode is supported in vgpu.\n");
return -EINVAL;
}
}
if (i915.enable_execlists) {
dev_priv->hw_context_size = 0;
} else if (HAS_HW_CONTEXTS(dev)) {
dev_priv->hw_context_size = round_up(get_context_size(dev), 4096);
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
dev_priv->kernel_context = ctx;
DRM_DEBUG_DRIVER("%s context support initialized\n",
i915.enable_execlists ? "LR" :
dev_priv->hw_context_size ? "HW" : "fake");
return 0;
}
void i915_gem_context_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_context *dctx = dev_priv->kernel_context;
int i;
if (dctx->legacy_hw_ctx.rcs_state) {
intel_gpu_reset(dev, ALL_ENGINES);
WARN_ON(!dev_priv->engine[RCS].last_context);
i915_gem_object_ggtt_unpin(dctx->legacy_hw_ctx.rcs_state);
}
for (i = I915_NUM_ENGINES; --i >= 0;) {
struct intel_engine_cs *engine = &dev_priv->engine[i];
if (engine->last_context) {
i915_gem_context_unpin(engine->last_context, engine);
engine->last_context = NULL;
}
}
i915_gem_context_unreference(dctx);
dev_priv->kernel_context = NULL;
}
int i915_gem_context_enable(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
int ret;
if (i915.enable_execlists) {
if (engine->init_context == NULL)
return 0;
ret = engine->init_context(req);
} else
ret = i915_switch_context(req);
if (ret) {
DRM_ERROR("ring init context: %d\n", ret);
return ret;
}
return 0;
}
static int context_idr_cleanup(int id, void *p, void *data)
{
struct intel_context *ctx = p;
i915_gem_context_unreference(ctx);
return 0;
}
int i915_gem_context_open(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct intel_context *ctx;
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
idr_for_each(&file_priv->context_idr, context_idr_cleanup, NULL);
idr_destroy(&file_priv->context_idr);
}
struct intel_context *
i915_gem_context_get(struct drm_i915_file_private *file_priv, u32 id)
{
struct intel_context *ctx;
ctx = (struct intel_context *)idr_find(&file_priv->context_idr, id);
if (!ctx)
return ERR_PTR(-ENOENT);
return ctx;
}
static inline int
mi_set_context(struct drm_i915_gem_request *req, u32 hw_flags)
{
struct intel_engine_cs *engine = req->engine;
u32 flags = hw_flags | MI_MM_SPACE_GTT;
const int num_rings =
i915_semaphore_is_enabled(engine->dev) ?
hweight32(INTEL_INFO(engine->dev)->ring_mask) - 1 :
0;
int len, ret;
if (IS_GEN6(engine->dev)) {
ret = engine->flush(req, I915_GEM_GPU_DOMAINS, 0);
if (ret)
return ret;
}
if (IS_HASWELL(engine->dev) || INTEL_INFO(engine->dev)->gen >= 8)
flags |= (HSW_MI_RS_SAVE_STATE_EN | HSW_MI_RS_RESTORE_STATE_EN);
else if (INTEL_INFO(engine->dev)->gen < 8)
flags |= (MI_SAVE_EXT_STATE_EN | MI_RESTORE_EXT_STATE_EN);
len = 4;
if (INTEL_INFO(engine->dev)->gen >= 7)
len += 2 + (num_rings ? 4*num_rings + 6 : 0);
ret = intel_ring_begin(req, len);
if (ret)
return ret;
if (INTEL_INFO(engine->dev)->gen >= 7) {
intel_ring_emit(engine, MI_ARB_ON_OFF | MI_ARB_DISABLE);
if (num_rings) {
struct intel_engine_cs *signaller;
intel_ring_emit(engine,
MI_LOAD_REGISTER_IMM(num_rings));
for_each_engine(signaller, to_i915(engine->dev)) {
if (signaller == engine)
continue;
intel_ring_emit_reg(engine,
RING_PSMI_CTL(signaller->mmio_base));
intel_ring_emit(engine,
_MASKED_BIT_ENABLE(GEN6_PSMI_SLEEP_MSG_DISABLE));
}
}
}
intel_ring_emit(engine, MI_NOOP);
intel_ring_emit(engine, MI_SET_CONTEXT);
intel_ring_emit(engine,
i915_gem_obj_ggtt_offset(req->ctx->legacy_hw_ctx.rcs_state) |
flags);
intel_ring_emit(engine, MI_NOOP);
if (INTEL_INFO(engine->dev)->gen >= 7) {
if (num_rings) {
struct intel_engine_cs *signaller;
i915_reg_t last_reg = {};
intel_ring_emit(engine,
MI_LOAD_REGISTER_IMM(num_rings));
for_each_engine(signaller, to_i915(engine->dev)) {
if (signaller == engine)
continue;
last_reg = RING_PSMI_CTL(signaller->mmio_base);
intel_ring_emit_reg(engine, last_reg);
intel_ring_emit(engine,
_MASKED_BIT_DISABLE(GEN6_PSMI_SLEEP_MSG_DISABLE));
}
intel_ring_emit(engine,
MI_STORE_REGISTER_MEM |
MI_SRM_LRM_GLOBAL_GTT);
intel_ring_emit_reg(engine, last_reg);
intel_ring_emit(engine, engine->scratch.gtt_offset);
intel_ring_emit(engine, MI_NOOP);
}
intel_ring_emit(engine, MI_ARB_ON_OFF | MI_ARB_ENABLE);
}
intel_ring_advance(engine);
return ret;
}
static inline bool skip_rcs_switch(struct intel_engine_cs *engine,
struct intel_context *to)
{
if (to->remap_slice)
return false;
if (!to->legacy_hw_ctx.initialized)
return false;
if (to->ppgtt &&
!(intel_engine_flag(engine) & to->ppgtt->pd_dirty_rings))
return false;
return to == engine->last_context;
}
static bool
needs_pd_load_pre(struct intel_engine_cs *engine, struct intel_context *to)
{
if (!to->ppgtt)
return false;
if (engine->last_context == to &&
!(intel_engine_flag(engine) & to->ppgtt->pd_dirty_rings))
return false;
if (engine->id != RCS)
return true;
if (INTEL_INFO(engine->dev)->gen < 8)
return true;
return false;
}
static bool
needs_pd_load_post(struct intel_context *to, u32 hw_flags)
{
if (!to->ppgtt)
return false;
if (!IS_GEN8(to->i915))
return false;
if (hw_flags & MI_RESTORE_INHIBIT)
return true;
return false;
}
static int do_rcs_switch(struct drm_i915_gem_request *req)
{
struct intel_context *to = req->ctx;
struct intel_engine_cs *engine = req->engine;
struct intel_context *from;
u32 hw_flags;
int ret, i;
if (skip_rcs_switch(engine, to))
return 0;
ret = i915_gem_obj_ggtt_pin(to->legacy_hw_ctx.rcs_state,
get_context_alignment(engine->dev),
0);
if (ret)
return ret;
from = engine->last_context;
ret = i915_gem_object_set_to_gtt_domain(to->legacy_hw_ctx.rcs_state, false);
if (ret)
goto unpin_out;
if (needs_pd_load_pre(engine, to)) {
trace_switch_mm(engine, to);
ret = to->ppgtt->switch_mm(to->ppgtt, req);
if (ret)
goto unpin_out;
}
if (!to->legacy_hw_ctx.initialized || i915_gem_context_is_default(to))
hw_flags = MI_RESTORE_INHIBIT;
else if (to->ppgtt &&
intel_engine_flag(engine) & to->ppgtt->pd_dirty_rings)
hw_flags = MI_FORCE_RESTORE;
else
hw_flags = 0;
WARN_ON(needs_pd_load_pre(engine, to) &&
needs_pd_load_post(to, hw_flags));
if (to != from || (hw_flags & MI_FORCE_RESTORE)) {
ret = mi_set_context(req, hw_flags);
if (ret)
goto unpin_out;
}
if (from != NULL) {
from->legacy_hw_ctx.rcs_state->base.read_domains = I915_GEM_DOMAIN_INSTRUCTION;
i915_vma_move_to_active(i915_gem_obj_to_ggtt(from->legacy_hw_ctx.rcs_state), req);
from->legacy_hw_ctx.rcs_state->dirty = 1;
i915_gem_object_ggtt_unpin(from->legacy_hw_ctx.rcs_state);
i915_gem_context_unreference(from);
}
i915_gem_context_reference(to);
engine->last_context = to;
if (needs_pd_load_post(to, hw_flags)) {
trace_switch_mm(engine, to);
ret = to->ppgtt->switch_mm(to->ppgtt, req);
if (ret)
return ret;
}
if (to->ppgtt)
to->ppgtt->pd_dirty_rings &= ~intel_engine_flag(engine);
for (i = 0; i < MAX_L3_SLICES; i++) {
if (!(to->remap_slice & (1<<i)))
continue;
ret = i915_gem_l3_remap(req, i);
if (ret)
return ret;
to->remap_slice &= ~(1<<i);
}
if (!to->legacy_hw_ctx.initialized) {
if (engine->init_context) {
ret = engine->init_context(req);
if (ret)
return ret;
}
to->legacy_hw_ctx.initialized = true;
}
return 0;
unpin_out:
i915_gem_object_ggtt_unpin(to->legacy_hw_ctx.rcs_state);
return ret;
}
int i915_switch_context(struct drm_i915_gem_request *req)
{
struct intel_engine_cs *engine = req->engine;
struct drm_i915_private *dev_priv = req->i915;
WARN_ON(i915.enable_execlists);
WARN_ON(!mutex_is_locked(&dev_priv->dev->struct_mutex));
if (engine->id != RCS ||
req->ctx->legacy_hw_ctx.rcs_state == NULL) {
struct intel_context *to = req->ctx;
if (needs_pd_load_pre(engine, to)) {
int ret;
trace_switch_mm(engine, to);
ret = to->ppgtt->switch_mm(to->ppgtt, req);
if (ret)
return ret;
to->ppgtt->pd_dirty_rings &= ~intel_engine_flag(engine);
}
if (to != engine->last_context) {
i915_gem_context_reference(to);
if (engine->last_context)
i915_gem_context_unreference(engine->last_context);
engine->last_context = to;
}
return 0;
}
return do_rcs_switch(req);
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
struct intel_context *ctx;
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
struct intel_context *ctx;
int ret;
if (args->pad != 0)
return -EINVAL;
if (args->ctx_id == DEFAULT_CONTEXT_HANDLE)
return -ENOENT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_get(file_priv, args->ctx_id);
if (IS_ERR(ctx)) {
mutex_unlock(&dev->struct_mutex);
return PTR_ERR(ctx);
}
idr_remove(&ctx->file_priv->context_idr, ctx->user_handle);
i915_gem_context_unreference(ctx);
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG_DRIVER("HW context %d destroyed\n", args->ctx_id);
return 0;
}
int i915_gem_context_getparam_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct drm_i915_gem_context_param *args = data;
struct intel_context *ctx;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_get(file_priv, args->ctx_id);
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
struct intel_context *ctx;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_get(file_priv, args->ctx_id);
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
default:
ret = -EINVAL;
break;
}
mutex_unlock(&dev->struct_mutex);
return ret;
}
