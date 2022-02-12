static void lut_close(struct i915_gem_context *ctx)
{
struct i915_lut_handle *lut, *ln;
struct radix_tree_iter iter;
void __rcu **slot;
list_for_each_entry_safe(lut, ln, &ctx->handles_list, ctx_link) {
list_del(&lut->obj_link);
kmem_cache_free(ctx->i915->luts, lut);
}
rcu_read_lock();
radix_tree_for_each_slot(slot, &ctx->handles_vma, &iter, 0) {
struct i915_vma *vma = rcu_dereference_raw(*slot);
struct drm_i915_gem_object *obj = vma->obj;
radix_tree_iter_delete(&ctx->handles_vma, &iter, slot);
if (!i915_vma_is_ggtt(vma))
i915_vma_close(vma);
__i915_gem_object_release_unless_active(obj);
}
rcu_read_unlock();
}
static void i915_gem_context_free(struct i915_gem_context *ctx)
{
int i;
lockdep_assert_held(&ctx->i915->drm.struct_mutex);
GEM_BUG_ON(!i915_gem_context_is_closed(ctx));
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
ida_simple_remove(&ctx->i915->contexts.hw_ida, ctx->hw_id);
kfree_rcu(ctx, rcu);
}
static void contexts_free(struct drm_i915_private *i915)
{
struct llist_node *freed = llist_del_all(&i915->contexts.free_list);
struct i915_gem_context *ctx, *cn;
lockdep_assert_held(&i915->drm.struct_mutex);
llist_for_each_entry_safe(ctx, cn, freed, free_link)
i915_gem_context_free(ctx);
}
static void contexts_free_first(struct drm_i915_private *i915)
{
struct i915_gem_context *ctx;
struct llist_node *freed;
lockdep_assert_held(&i915->drm.struct_mutex);
freed = llist_del_first(&i915->contexts.free_list);
if (!freed)
return;
ctx = container_of(freed, typeof(*ctx), free_link);
i915_gem_context_free(ctx);
}
static void contexts_free_worker(struct work_struct *work)
{
struct drm_i915_private *i915 =
container_of(work, typeof(*i915), contexts.free_work);
mutex_lock(&i915->drm.struct_mutex);
contexts_free(i915);
mutex_unlock(&i915->drm.struct_mutex);
}
void i915_gem_context_release(struct kref *ref)
{
struct i915_gem_context *ctx = container_of(ref, typeof(*ctx), ref);
struct drm_i915_private *i915 = ctx->i915;
trace_i915_context_free(ctx);
if (llist_add(&ctx->free_link, &i915->contexts.free_list))
queue_work(i915->wq, &i915->contexts.free_work);
}
static void context_close(struct i915_gem_context *ctx)
{
i915_gem_context_set_closed(ctx);
lut_close(ctx);
if (ctx->ppgtt)
i915_ppgtt_close(&ctx->ppgtt->base);
ctx->file_priv = ERR_PTR(-EBADF);
i915_gem_context_put(ctx);
}
static int assign_hw_id(struct drm_i915_private *dev_priv, unsigned *out)
{
int ret;
ret = ida_simple_get(&dev_priv->contexts.hw_ida,
0, MAX_CONTEXT_HW_ID, GFP_KERNEL);
if (ret < 0) {
i915_gem_retire_requests(dev_priv);
ret = ida_simple_get(&dev_priv->contexts.hw_ida,
0, MAX_CONTEXT_HW_ID, GFP_KERNEL);
if (ret < 0)
return ret;
}
*out = ret;
return 0;
}
static u32 default_desc_template(const struct drm_i915_private *i915,
const struct i915_hw_ppgtt *ppgtt)
{
u32 address_mode;
u32 desc;
desc = GEN8_CTX_VALID | GEN8_CTX_PRIVILEGE;
address_mode = INTEL_LEGACY_32B_CONTEXT;
if (ppgtt && i915_vm_is_48bit(&ppgtt->base))
address_mode = INTEL_LEGACY_64B_CONTEXT;
desc |= address_mode << GEN8_CTX_ADDRESSING_MODE_SHIFT;
if (IS_GEN8(i915))
desc |= GEN8_CTX_L3LLC_COHERENT;
return desc;
}
static struct i915_gem_context *
__create_hw_context(struct drm_i915_private *dev_priv,
struct drm_i915_file_private *file_priv)
{
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
list_add_tail(&ctx->link, &dev_priv->contexts.list);
ctx->i915 = dev_priv;
ctx->priority = I915_PRIORITY_NORMAL;
INIT_RADIX_TREE(&ctx->handles_vma, GFP_KERNEL);
INIT_LIST_HEAD(&ctx->handles_list);
ret = DEFAULT_CONTEXT_HANDLE;
if (file_priv) {
ret = idr_alloc(&file_priv->context_idr, ctx,
DEFAULT_CONTEXT_HANDLE, 0, GFP_KERNEL);
if (ret < 0)
goto err_lut;
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
i915_gem_context_set_bannable(ctx);
ctx->ring_size = 4 * PAGE_SIZE;
ctx->desc_template =
default_desc_template(dev_priv, dev_priv->mm.aliasing_ppgtt);
if (HAS_GUC(dev_priv) && i915.enable_guc_loading)
ctx->ggtt_offset_bias = GUC_WOPCM_TOP;
else
ctx->ggtt_offset_bias = I915_GTT_PAGE_SIZE;
return ctx;
err_pid:
put_pid(ctx->pid);
idr_remove(&file_priv->context_idr, ctx->user_handle);
err_lut:
context_close(ctx);
return ERR_PTR(ret);
}
static void __destroy_hw_context(struct i915_gem_context *ctx,
struct drm_i915_file_private *file_priv)
{
idr_remove(&file_priv->context_idr, ctx->user_handle);
context_close(ctx);
}
static struct i915_gem_context *
i915_gem_create_context(struct drm_i915_private *dev_priv,
struct drm_i915_file_private *file_priv)
{
struct i915_gem_context *ctx;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
contexts_free_first(dev_priv);
ctx = __create_hw_context(dev_priv, file_priv);
if (IS_ERR(ctx))
return ctx;
if (USES_FULL_PPGTT(dev_priv)) {
struct i915_hw_ppgtt *ppgtt;
ppgtt = i915_ppgtt_create(dev_priv, file_priv, ctx->name);
if (IS_ERR(ppgtt)) {
DRM_DEBUG_DRIVER("PPGTT setup failed (%ld)\n",
PTR_ERR(ppgtt));
__destroy_hw_context(ctx, file_priv);
return ERR_CAST(ppgtt);
}
ctx->ppgtt = ppgtt;
ctx->desc_template = default_desc_template(dev_priv, ppgtt);
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
ctx = __create_hw_context(to_i915(dev), NULL);
if (IS_ERR(ctx))
goto out;
ctx->file_priv = ERR_PTR(-EBADF);
i915_gem_context_set_closed(ctx);
i915_gem_context_clear_bannable(ctx);
i915_gem_context_set_force_single_submission(ctx);
if (!i915.enable_guc_submission)
ctx->ring_size = 512 * PAGE_SIZE;
GEM_BUG_ON(i915_gem_context_is_kernel(ctx));
out:
mutex_unlock(&dev->struct_mutex);
return ctx;
}
int i915_gem_contexts_init(struct drm_i915_private *dev_priv)
{
struct i915_gem_context *ctx;
if (WARN_ON(dev_priv->kernel_context))
return 0;
INIT_LIST_HEAD(&dev_priv->contexts.list);
INIT_WORK(&dev_priv->contexts.free_work, contexts_free_worker);
init_llist_head(&dev_priv->contexts.free_list);
if (intel_vgpu_active(dev_priv) &&
HAS_LOGICAL_RING_CONTEXTS(dev_priv)) {
if (!i915.enable_execlists) {
DRM_INFO("Only EXECLIST mode is supported in vgpu.\n");
return -EINVAL;
}
}
BUILD_BUG_ON(MAX_CONTEXT_HW_ID > INT_MAX);
ida_init(&dev_priv->contexts.hw_ida);
ctx = i915_gem_create_context(dev_priv, NULL);
if (IS_ERR(ctx)) {
DRM_ERROR("Failed to create default global context (error %ld)\n",
PTR_ERR(ctx));
return PTR_ERR(ctx);
}
GEM_BUG_ON(ctx->hw_id);
i915_gem_context_clear_bannable(ctx);
ctx->priority = I915_PRIORITY_MIN;
dev_priv->kernel_context = ctx;
GEM_BUG_ON(!i915_gem_context_is_kernel(ctx));
DRM_DEBUG_DRIVER("%s context support initialized\n",
dev_priv->engine[RCS]->context_size ? "logical" :
"fake");
return 0;
}
void i915_gem_contexts_lost(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
for_each_engine(engine, dev_priv, id) {
engine->legacy_active_context = NULL;
if (!engine->last_retired_context)
continue;
engine->context_unpin(engine, engine->last_retired_context);
engine->last_retired_context = NULL;
}
if (!i915.enable_execlists) {
struct i915_gem_context *ctx;
list_for_each_entry(ctx, &dev_priv->contexts.list, link) {
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
void i915_gem_contexts_fini(struct drm_i915_private *i915)
{
struct i915_gem_context *ctx;
lockdep_assert_held(&i915->drm.struct_mutex);
ctx = i915_gem_context_get(fetch_and_zero(&i915->kernel_context));
GEM_BUG_ON(!i915_gem_context_is_kernel(ctx));
context_close(ctx);
i915_gem_context_free(ctx);
ida_destroy(&i915->contexts.hw_ida);
}
static int context_idr_cleanup(int id, void *p, void *data)
{
struct i915_gem_context *ctx = p;
context_close(ctx);
return 0;
}
int i915_gem_context_open(struct drm_i915_private *i915,
struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct i915_gem_context *ctx;
idr_init(&file_priv->context_idr);
mutex_lock(&i915->drm.struct_mutex);
ctx = i915_gem_create_context(i915, file_priv);
mutex_unlock(&i915->drm.struct_mutex);
if (IS_ERR(ctx)) {
idr_destroy(&file_priv->context_idr);
return PTR_ERR(ctx);
}
GEM_BUG_ON(i915_gem_context_is_kernel(ctx));
return 0;
}
void i915_gem_context_close(struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
lockdep_assert_held(&file_priv->dev_priv->drm.struct_mutex);
idr_for_each(&file_priv->context_idr, context_idr_cleanup, NULL);
idr_destroy(&file_priv->context_idr);
}
static inline int
mi_set_context(struct drm_i915_gem_request *req, u32 flags)
{
struct drm_i915_private *dev_priv = req->i915;
struct intel_engine_cs *engine = req->engine;
enum intel_engine_id id;
const int num_rings =
(i915.semaphores && INTEL_GEN(dev_priv) == 7) ?
INTEL_INFO(dev_priv)->num_rings - 1 :
0;
int len;
u32 *cs;
flags |= MI_MM_SPACE_GTT;
if (IS_HASWELL(dev_priv) || INTEL_GEN(dev_priv) >= 8)
flags |= HSW_MI_RS_SAVE_STATE_EN | HSW_MI_RS_RESTORE_STATE_EN;
else
flags |= MI_SAVE_EXT_STATE_EN | MI_RESTORE_EXT_STATE_EN;
len = 4;
if (INTEL_GEN(dev_priv) >= 7)
len += 2 + (num_rings ? 4*num_rings + 6 : 0);
cs = intel_ring_begin(req, len);
if (IS_ERR(cs))
return PTR_ERR(cs);
if (INTEL_GEN(dev_priv) >= 7) {
*cs++ = MI_ARB_ON_OFF | MI_ARB_DISABLE;
if (num_rings) {
struct intel_engine_cs *signaller;
*cs++ = MI_LOAD_REGISTER_IMM(num_rings);
for_each_engine(signaller, dev_priv, id) {
if (signaller == engine)
continue;
*cs++ = i915_mmio_reg_offset(
RING_PSMI_CTL(signaller->mmio_base));
*cs++ = _MASKED_BIT_ENABLE(
GEN6_PSMI_SLEEP_MSG_DISABLE);
}
}
}
*cs++ = MI_NOOP;
*cs++ = MI_SET_CONTEXT;
*cs++ = i915_ggtt_offset(req->ctx->engine[RCS].state) | flags;
*cs++ = MI_NOOP;
if (INTEL_GEN(dev_priv) >= 7) {
if (num_rings) {
struct intel_engine_cs *signaller;
i915_reg_t last_reg = {};
*cs++ = MI_LOAD_REGISTER_IMM(num_rings);
for_each_engine(signaller, dev_priv, id) {
if (signaller == engine)
continue;
last_reg = RING_PSMI_CTL(signaller->mmio_base);
*cs++ = i915_mmio_reg_offset(last_reg);
*cs++ = _MASKED_BIT_DISABLE(
GEN6_PSMI_SLEEP_MSG_DISABLE);
}
*cs++ = MI_STORE_REGISTER_MEM | MI_SRM_LRM_GLOBAL_GTT;
*cs++ = i915_mmio_reg_offset(last_reg);
*cs++ = i915_ggtt_offset(engine->scratch);
*cs++ = MI_NOOP;
}
*cs++ = MI_ARB_ON_OFF | MI_ARB_ENABLE;
}
intel_ring_advance(req, cs);
return 0;
}
static int remap_l3(struct drm_i915_gem_request *req, int slice)
{
u32 *cs, *remap_info = req->i915->l3_parity.remap_info[slice];
int i;
if (!remap_info)
return 0;
cs = intel_ring_begin(req, GEN7_L3LOG_SIZE/4 * 2 + 2);
if (IS_ERR(cs))
return PTR_ERR(cs);
*cs++ = MI_LOAD_REGISTER_IMM(GEN7_L3LOG_SIZE/4);
for (i = 0; i < GEN7_L3LOG_SIZE/4; i++) {
*cs++ = i915_mmio_reg_offset(GEN7_L3LOG(slice, i));
*cs++ = remap_info[i];
}
*cs++ = MI_NOOP;
intel_ring_advance(req, cs);
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
return to == engine->legacy_active_context;
}
static bool
needs_pd_load_pre(struct i915_hw_ppgtt *ppgtt, struct intel_engine_cs *engine)
{
struct i915_gem_context *from = engine->legacy_active_context;
if (!ppgtt)
return false;
if (!from)
return true;
if ((!from->ppgtt || from->ppgtt == ppgtt) &&
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
static int do_rcs_switch(struct drm_i915_gem_request *req)
{
struct i915_gem_context *to = req->ctx;
struct intel_engine_cs *engine = req->engine;
struct i915_hw_ppgtt *ppgtt = to->ppgtt ?: req->i915->mm.aliasing_ppgtt;
struct i915_gem_context *from = engine->legacy_active_context;
u32 hw_flags;
int ret, i;
GEM_BUG_ON(engine->id != RCS);
if (skip_rcs_switch(ppgtt, engine, to))
return 0;
if (needs_pd_load_pre(ppgtt, engine)) {
trace_switch_mm(engine, to);
ret = ppgtt->switch_mm(ppgtt, req);
if (ret)
return ret;
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
return ret;
engine->legacy_active_context = to;
}
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
if (needs_pd_load_pre(ppgtt, engine)) {
int ret;
trace_switch_mm(engine, to);
ret = ppgtt->switch_mm(ppgtt, req);
if (ret)
return ret;
ppgtt->pd_dirty_rings &= ~intel_engine_flag(engine);
}
engine->legacy_active_context = to;
return 0;
}
return do_rcs_switch(req);
}
static bool engine_has_kernel_context(struct intel_engine_cs *engine)
{
struct i915_gem_timeline *timeline;
list_for_each_entry(timeline, &engine->i915->gt.timelines, link) {
struct intel_timeline *tl;
if (timeline == &engine->i915->gt.global_timeline)
continue;
tl = &timeline->engine[engine->id];
if (i915_gem_active_peek(&tl->last_request,
&engine->i915->drm.struct_mutex))
return false;
}
return (!engine->last_retired_context ||
i915_gem_context_is_kernel(engine->last_retired_context));
}
int i915_gem_switch_to_kernel_context(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
struct i915_gem_timeline *timeline;
enum intel_engine_id id;
lockdep_assert_held(&dev_priv->drm.struct_mutex);
i915_gem_retire_requests(dev_priv);
for_each_engine(engine, dev_priv, id) {
struct drm_i915_gem_request *req;
int ret;
if (engine_has_kernel_context(engine))
continue;
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
i915_add_request(req);
if (ret)
return ret;
}
return 0;
}
static bool client_is_banned(struct drm_i915_file_private *file_priv)
{
return atomic_read(&file_priv->context_bans) > I915_MAX_CLIENT_CONTEXT_BANS;
}
int i915_gem_context_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_gem_context_create *args = data;
struct drm_i915_file_private *file_priv = file->driver_priv;
struct i915_gem_context *ctx;
int ret;
if (!dev_priv->engine[RCS]->context_size)
return -ENODEV;
if (args->pad != 0)
return -EINVAL;
if (client_is_banned(file_priv)) {
DRM_DEBUG("client %s[%d] banned from creating ctx\n",
current->comm,
pid_nr(get_task_pid(current, PIDTYPE_PID)));
return -EIO;
}
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_create_context(dev_priv, file_priv);
mutex_unlock(&dev->struct_mutex);
if (IS_ERR(ctx))
return PTR_ERR(ctx);
GEM_BUG_ON(i915_gem_context_is_kernel(ctx));
args->ctx_id = ctx->user_handle;
DRM_DEBUG("HW context %d created\n", args->ctx_id);
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
ctx = i915_gem_context_lookup(file_priv, args->ctx_id);
if (!ctx)
return -ENOENT;
ret = mutex_lock_interruptible(&dev->struct_mutex);
if (ret)
goto out;
__destroy_hw_context(ctx, file_priv);
mutex_unlock(&dev->struct_mutex);
out:
i915_gem_context_put(ctx);
return 0;
}
int i915_gem_context_getparam_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct drm_i915_gem_context_param *args = data;
struct i915_gem_context *ctx;
int ret = 0;
ctx = i915_gem_context_lookup(file_priv, args->ctx_id);
if (!ctx)
return -ENOENT;
args->size = 0;
switch (args->param) {
case I915_CONTEXT_PARAM_BAN_PERIOD:
ret = -EINVAL;
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
args->value = i915_gem_context_no_error_capture(ctx);
break;
case I915_CONTEXT_PARAM_BANNABLE:
args->value = i915_gem_context_is_bannable(ctx);
break;
default:
ret = -EINVAL;
break;
}
i915_gem_context_put(ctx);
return ret;
}
int i915_gem_context_setparam_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct drm_i915_gem_context_param *args = data;
struct i915_gem_context *ctx;
int ret;
ctx = i915_gem_context_lookup(file_priv, args->ctx_id);
if (!ctx)
return -ENOENT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
goto out;
switch (args->param) {
case I915_CONTEXT_PARAM_BAN_PERIOD:
ret = -EINVAL;
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
if (args->size)
ret = -EINVAL;
else if (args->value)
i915_gem_context_set_no_error_capture(ctx);
else
i915_gem_context_clear_no_error_capture(ctx);
break;
case I915_CONTEXT_PARAM_BANNABLE:
if (args->size)
ret = -EINVAL;
else if (!capable(CAP_SYS_ADMIN) && !args->value)
ret = -EPERM;
else if (args->value)
i915_gem_context_set_bannable(ctx);
else
i915_gem_context_clear_bannable(ctx);
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&dev->struct_mutex);
out:
i915_gem_context_put(ctx);
return ret;
}
int i915_gem_context_reset_stats_ioctl(struct drm_device *dev,
void *data, struct drm_file *file)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct drm_i915_reset_stats *args = data;
struct i915_gem_context *ctx;
int ret;
if (args->flags || args->pad)
return -EINVAL;
ret = -ENOENT;
rcu_read_lock();
ctx = __i915_gem_context_lookup_rcu(file->driver_priv, args->ctx_id);
if (!ctx)
goto out;
if (capable(CAP_SYS_ADMIN))
args->reset_count = i915_reset_count(&dev_priv->gpu_error);
else
args->reset_count = 0;
args->batch_active = atomic_read(&ctx->guilty_count);
args->batch_pending = atomic_read(&ctx->active_count);
ret = 0;
out:
rcu_read_unlock();
return ret;
}
