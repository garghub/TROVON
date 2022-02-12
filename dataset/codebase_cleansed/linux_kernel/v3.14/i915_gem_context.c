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
struct i915_hw_context *ctx = container_of(ctx_ref,
typeof(*ctx), ref);
list_del(&ctx->link);
drm_gem_object_unreference(&ctx->obj->base);
kfree(ctx);
}
static struct i915_hw_context *
create_hw_context(struct drm_device *dev,
struct drm_i915_file_private *file_priv)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_hw_context *ctx;
int ret;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (ctx == NULL)
return ERR_PTR(-ENOMEM);
kref_init(&ctx->ref);
ctx->obj = i915_gem_alloc_object(dev, dev_priv->hw_context_size);
INIT_LIST_HEAD(&ctx->link);
if (ctx->obj == NULL) {
kfree(ctx);
DRM_DEBUG_DRIVER("Context object allocated failed\n");
return ERR_PTR(-ENOMEM);
}
if (INTEL_INFO(dev)->gen >= 7) {
ret = i915_gem_object_set_cache_level(ctx->obj,
I915_CACHE_L3_LLC);
if (WARN_ON(ret))
goto err_out;
}
ctx->ring = &dev_priv->ring[RCS];
list_add_tail(&ctx->link, &dev_priv->context_list);
if (file_priv == NULL)
return ctx;
ret = idr_alloc(&file_priv->context_idr, ctx, DEFAULT_CONTEXT_ID + 1, 0,
GFP_KERNEL);
if (ret < 0)
goto err_out;
ctx->file_priv = file_priv;
ctx->id = ret;
ctx->remap_slice = (1 << NUM_L3_SLICES(dev)) - 1;
return ctx;
err_out:
i915_gem_context_unreference(ctx);
return ERR_PTR(ret);
}
static inline bool is_default_context(struct i915_hw_context *ctx)
{
return (ctx == ctx->ring->default_context);
}
static int create_default_context(struct drm_i915_private *dev_priv)
{
struct i915_hw_context *ctx;
int ret;
BUG_ON(!mutex_is_locked(&dev_priv->dev->struct_mutex));
ctx = create_hw_context(dev_priv->dev, NULL);
if (IS_ERR(ctx))
return PTR_ERR(ctx);
ret = i915_gem_obj_ggtt_pin(ctx->obj, CONTEXT_ALIGN, false, false);
if (ret) {
DRM_DEBUG_DRIVER("Couldn't pin %d\n", ret);
goto err_destroy;
}
ret = do_switch(ctx);
if (ret) {
DRM_DEBUG_DRIVER("Switch failed %d\n", ret);
goto err_unpin;
}
dev_priv->ring[RCS].default_context = ctx;
DRM_DEBUG_DRIVER("Default HW context loaded\n");
return 0;
err_unpin:
i915_gem_object_unpin(ctx->obj);
err_destroy:
i915_gem_context_unreference(ctx);
return ret;
}
int i915_gem_context_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
if (!HAS_HW_CONTEXTS(dev))
return 0;
if (dev_priv->ring[RCS].default_context)
return 0;
dev_priv->hw_context_size = round_up(get_context_size(dev), 4096);
if (dev_priv->hw_context_size > (1<<20)) {
DRM_DEBUG_DRIVER("Disabling HW Contexts; invalid size\n");
return -E2BIG;
}
ret = create_default_context(dev_priv);
if (ret) {
DRM_DEBUG_DRIVER("Disabling HW Contexts; create failed %d\n",
ret);
return ret;
}
DRM_DEBUG_DRIVER("HW context support initialized\n");
return 0;
}
void i915_gem_context_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct i915_hw_context *dctx = dev_priv->ring[RCS].default_context;
if (!HAS_HW_CONTEXTS(dev))
return;
intel_gpu_reset(dev);
WARN_ON(!dev_priv->ring[RCS].last_context);
if (dev_priv->ring[RCS].last_context == dctx) {
WARN_ON(dctx->obj->active);
i915_gem_object_unpin(dctx->obj);
i915_gem_context_unreference(dctx);
}
i915_gem_object_unpin(dctx->obj);
i915_gem_context_unreference(dctx);
dev_priv->ring[RCS].default_context = NULL;
dev_priv->ring[RCS].last_context = NULL;
}
static int context_idr_cleanup(int id, void *p, void *data)
{
struct i915_hw_context *ctx = p;
BUG_ON(id == DEFAULT_CONTEXT_ID);
i915_gem_context_unreference(ctx);
return 0;
}
struct i915_ctx_hang_stats *
i915_gem_context_get_hang_stats(struct drm_device *dev,
struct drm_file *file,
u32 id)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
struct i915_hw_context *ctx;
if (id == DEFAULT_CONTEXT_ID)
return &file_priv->hang_stats;
if (!HAS_HW_CONTEXTS(dev))
return ERR_PTR(-ENOENT);
ctx = i915_gem_context_get(file->driver_priv, id);
if (ctx == NULL)
return ERR_PTR(-ENOENT);
return &ctx->hang_stats;
}
void i915_gem_context_close(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
idr_for_each(&file_priv->context_idr, context_idr_cleanup, NULL);
idr_destroy(&file_priv->context_idr);
}
static struct i915_hw_context *
i915_gem_context_get(struct drm_i915_file_private *file_priv, u32 id)
{
return (struct i915_hw_context *)idr_find(&file_priv->context_idr, id);
}
static inline int
mi_set_context(struct intel_ring_buffer *ring,
struct i915_hw_context *new_context,
u32 hw_flags)
{
int ret;
if (IS_GEN6(ring->dev) && ring->itlb_before_ctx_switch) {
ret = ring->flush(ring, I915_GEM_GPU_DOMAINS, 0);
if (ret)
return ret;
}
ret = intel_ring_begin(ring, 6);
if (ret)
return ret;
if (IS_GEN7(ring->dev))
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
if (IS_GEN7(ring->dev))
intel_ring_emit(ring, MI_ARB_ON_OFF | MI_ARB_ENABLE);
else
intel_ring_emit(ring, MI_NOOP);
intel_ring_advance(ring);
return ret;
}
static int do_switch(struct i915_hw_context *to)
{
struct intel_ring_buffer *ring = to->ring;
struct i915_hw_context *from = ring->last_context;
u32 hw_flags = 0;
int ret, i;
BUG_ON(from != NULL && from->obj != NULL && from->obj->pin_count == 0);
if (from == to && !to->remap_slice)
return 0;
ret = i915_gem_obj_ggtt_pin(to->obj, CONTEXT_ALIGN, false, false);
if (ret)
return ret;
from = ring->last_context;
ret = i915_gem_object_set_to_gtt_domain(to->obj, false);
if (ret) {
i915_gem_object_unpin(to->obj);
return ret;
}
if (!to->obj->has_global_gtt_mapping)
i915_gem_gtt_bind_object(to->obj, to->obj->cache_level);
if (!to->is_initialized || is_default_context(to))
hw_flags |= MI_RESTORE_INHIBIT;
ret = mi_set_context(ring, to, hw_flags);
if (ret) {
i915_gem_object_unpin(to->obj);
return ret;
}
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
i915_gem_object_unpin(from->obj);
i915_gem_context_unreference(from);
}
i915_gem_context_reference(to);
ring->last_context = to;
to->is_initialized = true;
return 0;
}
int i915_switch_context(struct intel_ring_buffer *ring,
struct drm_file *file,
int to_id)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
struct i915_hw_context *to;
if (!HAS_HW_CONTEXTS(ring->dev))
return 0;
WARN_ON(!mutex_is_locked(&dev_priv->dev->struct_mutex));
if (ring != &dev_priv->ring[RCS])
return 0;
if (to_id == DEFAULT_CONTEXT_ID) {
to = ring->default_context;
} else {
if (file == NULL)
return -EINVAL;
to = i915_gem_context_get(file->driver_priv, to_id);
if (to == NULL)
return -ENOENT;
}
return do_switch(to);
}
int i915_gem_context_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file)
{
struct drm_i915_gem_context_create *args = data;
struct drm_i915_file_private *file_priv = file->driver_priv;
struct i915_hw_context *ctx;
int ret;
if (!(dev->driver->driver_features & DRIVER_GEM))
return -ENODEV;
if (!HAS_HW_CONTEXTS(dev))
return -ENODEV;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = create_hw_context(dev, file_priv);
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
struct i915_hw_context *ctx;
int ret;
if (!(dev->driver->driver_features & DRIVER_GEM))
return -ENODEV;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ctx = i915_gem_context_get(file_priv, args->ctx_id);
if (!ctx) {
mutex_unlock(&dev->struct_mutex);
return -ENOENT;
}
idr_remove(&ctx->file_priv->context_idr, ctx->id);
i915_gem_context_unreference(ctx);
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG_DRIVER("HW context %d destroyed\n", args->ctx_id);
return 0;
}
