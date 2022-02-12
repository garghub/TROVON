static void do_ppgtt_cleanup(struct i915_hw_ppgtt *ppgtt)
{
struct drm_device *dev = ppgtt->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_address_space *vm = &ppgtt->base;
if (ppgtt == dev_priv->mm.aliasing_ppgtt ||
(list_empty(&vm->active_list) && list_empty(&vm->inactive_list))) {
ppgtt->base.cleanup(&ppgtt->base);
return;
}
if (!list_empty(&vm->active_list)) {
struct i915_vma *vma;
list_for_each_entry(vma, &vm->active_list, mm_list)
if (WARN_ON(list_empty(&vma->vma_link) ||
list_is_singular(&vma->vma_link)))
break;
i915_gem_evict_vm(&ppgtt->base, true);
} else {
i915_gem_retire_requests(dev);
i915_gem_evict_vm(&ppgtt->base, false);
}
ppgtt->base.cleanup(&ppgtt->base);
}
static void ppgtt_release(struct kref *kref)
{
struct i915_hw_ppgtt *ppgtt =
container_of(kref, struct i915_hw_ppgtt, ref);
do_ppgtt_cleanup(ppgtt);
kfree(ppgtt);
}
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
void i915_gem_context_free(struct kref *ctx_ref)
{
struct intel_context *ctx = container_of(ctx_ref,
typeof(*ctx), ref);
struct i915_hw_ppgtt *ppgtt = NULL;
if (ctx->obj) {
if (USES_PPGTT(ctx->obj->base.dev))
ppgtt = ctx_to_ppgtt(ctx);
drm_gem_object_unreference(&ctx->obj->base);
}
if (ppgtt)
kref_put(&ppgtt->ref, ppgtt_release);
list_del(&ctx->link);
kfree(ctx);
}
static struct i915_hw_ppgtt *
create_vm_for_ctx(struct drm_device *dev, struct intel_context *ctx)
{
struct i915_hw_ppgtt *ppgtt;
int ret;
ppgtt = kzalloc(sizeof(*ppgtt), GFP_KERNEL);
if (!ppgtt)
return ERR_PTR(-ENOMEM);
ret = i915_gem_init_ppgtt(dev, ppgtt);
if (ret) {
kfree(ppgtt);
return ERR_PTR(ret);
}
ppgtt->ctx = ctx;
return ppgtt;
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
if (dev_priv->hw_context_size) {
ctx->obj = i915_gem_alloc_object(dev, dev_priv->hw_context_size);
if (ctx->obj == NULL) {
ret = -ENOMEM;
goto err_out;
}
if (INTEL_INFO(dev)->gen >= 7 && !IS_VALLEYVIEW(dev)) {
ret = i915_gem_object_set_cache_level(ctx->obj,
I915_CACHE_L3_LLC);
if (WARN_ON(ret))
goto err_out;
}
}
if (file_priv != NULL) {
ret = idr_alloc(&file_priv->context_idr, ctx,
DEFAULT_CONTEXT_ID, 0, GFP_KERNEL);
if (ret < 0)
goto err_out;
} else
ret = DEFAULT_CONTEXT_ID;
ctx->file_priv = file_priv;
ctx->id = ret;
ctx->remap_slice = (1 << NUM_L3_SLICES(dev)) - 1;
return ctx;
err_out:
i915_gem_context_unreference(ctx);
return ERR_PTR(ret);
}
static struct intel_context *
i915_gem_create_context(struct drm_device *dev,
struct drm_i915_file_private *file_priv,
bool create_vm)
{
const bool is_global_default_ctx = file_priv == NULL;
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_context *ctx;
int ret = 0;
BUG_ON(!mutex_is_locked(&dev->struct_mutex));
ctx = __create_hw_context(dev, file_priv);
if (IS_ERR(ctx))
return ctx;
if (is_global_default_ctx && ctx->obj) {
ret = i915_gem_obj_ggtt_pin(ctx->obj,
get_context_alignment(dev), 0);
if (ret) {
DRM_DEBUG_DRIVER("Couldn't pin %d\n", ret);
goto err_destroy;
}
}
if (create_vm) {
struct i915_hw_ppgtt *ppgtt = create_vm_for_ctx(dev, ctx);
if (IS_ERR_OR_NULL(ppgtt)) {
DRM_DEBUG_DRIVER("PPGTT setup failed (%ld)\n",
PTR_ERR(ppgtt));
ret = PTR_ERR(ppgtt);
goto err_unpin;
} else
ctx->vm = &ppgtt->base;
if (is_global_default_ctx) {
if (WARN_ON(dev_priv->mm.aliasing_ppgtt)) {
ret = -EEXIST;
goto err_unpin;
}
dev_priv->mm.aliasing_ppgtt = ppgtt;
}
} else if (USES_PPGTT(dev)) {
ctx->vm = &dev_priv->mm.aliasing_ppgtt->base;
kref_get(&dev_priv->mm.aliasing_ppgtt->ref);
} else
ctx->vm = &dev_priv->gtt.base;
return ctx;
err_unpin:
if (is_global_default_ctx && ctx->obj)
i915_gem_object_ggtt_unpin(ctx->obj);
err_destroy:
i915_gem_context_unreference(ctx);
return ERR_PTR(ret);
}
void i915_gem_context_reset(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
for (i = 0; i < I915_NUM_RINGS; i++) {
struct intel_engine_cs *ring = &dev_priv->ring[i];
struct intel_context *dctx = ring->default_context;
if (ring->last_context == dctx)
continue;
if (!ring->last_context)
continue;
if (dctx->obj && i == RCS) {
WARN_ON(i915_gem_obj_ggtt_pin(dctx->obj,
get_context_alignment(dev), 0));
dctx->obj->base.write_domain = 0;
dctx->obj->active = 0;
}
i915_gem_context_unreference(ring->last_context);
i915_gem_context_reference(dctx);
ring->last_context = dctx;
}
}
int i915_gem_context_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_context *ctx;
int i;
if (WARN_ON(dev_priv->ring[RCS].default_context))
return 0;
if (HAS_HW_CONTEXTS(dev)) {
dev_priv->hw_context_size = round_up(get_context_size(dev), 4096);
if (dev_priv->hw_context_size > (1<<20)) {
DRM_DEBUG_DRIVER("Disabling HW Contexts; invalid size %d\n",
dev_priv->hw_context_size);
dev_priv->hw_context_size = 0;
}
}
ctx = i915_gem_create_context(dev, NULL, USES_PPGTT(dev));
if (IS_ERR(ctx)) {
DRM_ERROR("Failed to create default global context (error %ld)\n",
PTR_ERR(ctx));
return PTR_ERR(ctx);
}
for (i = 0; i < I915_NUM_RINGS; i++)
dev_priv->ring[i].default_context = ctx;
DRM_DEBUG_DRIVER("%s context support initialized\n", dev_priv->hw_context_size ? "HW" : "fake");
return 0;
}
void i915_gem_context_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_context *dctx = dev_priv->ring[RCS].default_context;
int i;
if (dctx->obj) {
intel_gpu_reset(dev);
WARN_ON(!dev_priv->ring[RCS].last_context);
if (dev_priv->ring[RCS].last_context == dctx) {
WARN_ON(dctx->obj->active);
i915_gem_object_ggtt_unpin(dctx->obj);
i915_gem_context_unreference(dctx);
dev_priv->ring[RCS].last_context = NULL;
}
i915_gem_object_ggtt_unpin(dctx->obj);
}
for (i = 0; i < I915_NUM_RINGS; i++) {
struct intel_engine_cs *ring = &dev_priv->ring[i];
if (ring->last_context)
i915_gem_context_unreference(ring->last_context);
ring->default_context = NULL;
ring->last_context = NULL;
}
i915_gem_context_unreference(dctx);
}
int i915_gem_context_enable(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *ring;
int ret, i;
if (dev_priv->mm.aliasing_ppgtt) {
struct i915_hw_ppgtt *ppgtt = dev_priv->mm.aliasing_ppgtt;
ppgtt->enable(ppgtt);
}
if (i915_reset_in_progress(&dev_priv->gpu_error))
return 0;
BUG_ON(!dev_priv->ring[RCS].default_context);
for_each_ring(ring, dev_priv, i) {
ret = i915_switch_context(ring, ring->default_context);
if (ret)
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
ctx = i915_gem_create_context(dev, file_priv, USES_FULL_PPGTT(dev));
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
mi_set_context(struct intel_engine_cs *ring,
struct intel_context *new_context,
u32 hw_flags)
{
int ret;
if (IS_GEN6(ring->dev)) {
ret = ring->flush(ring, I915_GEM_GPU_DOMAINS, 0);
if (ret)
return ret;
}
ret = intel_ring_begin(ring, 6);
if (ret)
return ret;
if (INTEL_INFO(ring->dev)->gen >= 7)
intel_ring_emit(ring, MI_ARB_ON_OFF | MI_ARB_DISABLE);
else
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_NOOP);
intel_ring_emit(ring, MI_SET_CONTEXT);
intel_ring_emit(ring, i915_gem_obj_ggtt_offset(new_context->obj) |
MI_MM_SPACE_GTT |
MI_SAVE_EXT_STATE_EN |
MI_RESTORE_EXT_STATE_EN |
hw_flags);
intel_ring_emit(ring, MI_NOOP);
if (INTEL_INFO(ring->dev)->gen >= 7)
intel_ring_emit(ring, MI_ARB_ON_OFF | MI_ARB_ENABLE);
else
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return ret;
}
static int do_switch(struct intel_engine_cs *ring,
struct intel_context *to)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
struct intel_context *from = ring->last_context;
struct i915_hw_ppgtt *ppgtt = ctx_to_ppgtt(to);
u32 hw_flags = 0;
bool uninitialized = false;
int ret, i;
if (from != NULL && ring == &dev_priv->ring[RCS]) {
BUG_ON(from->obj == NULL);
BUG_ON(!i915_gem_obj_is_pinned(from->obj));
}
if (from == to && from->last_ring == ring && !to->remap_slice)
return 0;
if (ring == &dev_priv->ring[RCS]) {
ret = i915_gem_obj_ggtt_pin(to->obj,
get_context_alignment(ring->dev), 0);
if (ret)
return ret;
}
from = ring->last_context;
if (USES_FULL_PPGTT(ring->dev)) {
ret = ppgtt->switch_mm(ppgtt, ring, false);
if (ret)
goto unpin_out;
}
if (ring != &dev_priv->ring[RCS]) {
if (from)
i915_gem_context_unreference(from);
goto done;
}
ret = i915_gem_object_set_to_gtt_domain(to->obj, false);
if (ret)
goto unpin_out;
if (!to->obj->has_global_gtt_mapping) {
struct i915_vma *vma = i915_gem_obj_to_vma(to->obj,
&dev_priv->gtt.base);
vma->bind_vma(vma, to->obj->cache_level, GLOBAL_BIND);
}
if (!to->is_initialized || i915_gem_context_is_default(to))
hw_flags |= MI_RESTORE_INHIBIT;
ret = mi_set_context(ring, to, hw_flags);
if (ret)
goto unpin_out;
for (i = 0; i < MAX_L3_SLICES; i++) {
if (!(to->remap_slice & (1<<i)))
continue;
ret = i915_gem_l3_remap(ring, i);
if (ret)
DRM_DEBUG_DRIVER("L3 remapping failed\n");
else
to->remap_slice &= ~(1<<i);
}
if (from != NULL) {
from->obj->base.read_domains = I915_GEM_DOMAIN_INSTRUCTION;
i915_vma_move_to_active(i915_gem_obj_to_ggtt(from->obj), ring);
from->obj->dirty = 1;
BUG_ON(from->obj->ring != ring);
i915_gem_object_ggtt_unpin(from->obj);
i915_gem_context_unreference(from);
}
uninitialized = !to->is_initialized && from == NULL;
to->is_initialized = true;
done:
i915_gem_context_reference(to);
ring->last_context = to;
to->last_ring = ring;
if (uninitialized) {
ret = i915_gem_render_state_init(ring);
if (ret)
DRM_ERROR("init render state: %d\n", ret);
}
return 0;
unpin_out:
if (ring->id == RCS)
i915_gem_object_ggtt_unpin(to->obj);
return ret;
}
int i915_switch_context(struct intel_engine_cs *ring,
struct intel_context *to)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
WARN_ON(!mutex_is_locked(&dev_priv->dev->struct_mutex));
if (to->obj == NULL) {
if (to != ring->last_context) {
i915_gem_context_reference(to);
if (ring->last_context)
i915_gem_context_unreference(ring->last_context);
ring->last_context = to;
}
return 0;
}
return do_switch(ring, to);
}
static bool hw_context_enabled(struct drm_device *dev)
{
return to_i915(dev)->hw_context_size;
}
int i915_gem_context_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_context_create *args = data;
struct drm_i915_file_private *file_priv = file->driver_priv;
struct intel_context *ctx;
int ret;
if (!hw_context_enabled(dev))
return -ENODEV;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_create_context(dev, file_priv, USES_FULL_PPGTT(dev));
mutex_unlock(&dev->struct_mutex);
if (IS_ERR(ctx))
return PTR_ERR(ctx);
args->ctx_id = ctx->id;
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
if (args->ctx_id == DEFAULT_CONTEXT_ID)
return -ENOENT;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_get(file_priv, args->ctx_id);
if (IS_ERR(ctx)) {
mutex_unlock(&dev->struct_mutex);
return PTR_ERR(ctx);
}
idr_remove(&ctx->file_priv->context_idr, ctx->id);
i915_gem_context_unreference(ctx);
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG_DRIVER("HW context %d destroyed\n", args->ctx_id);
return 0;
}
