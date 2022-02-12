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
ret = HSW_CXT_TOTAL_SIZE(reg) * 64;
else
ret = GEN7_CXT_TOTAL_SIZE(reg) * 64;
break;
default:
BUG();
}
return ret;
}
static void do_destroy(struct i915_hw_context *ctx)
{
if (ctx->file_priv)
idr_remove(&ctx->file_priv->context_idr, ctx->id);
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
ctx->obj = i915_gem_alloc_object(dev, dev_priv->hw_context_size);
if (ctx->obj == NULL) {
kfree(ctx);
DRM_DEBUG_DRIVER("Context object allocated failed\n");
return ERR_PTR(-ENOMEM);
}
if (INTEL_INFO(dev)->gen >= 7) {
ret = i915_gem_object_set_cache_level(ctx->obj,
I915_CACHE_LLC_MLC);
if (ret)
goto err_out;
}
ctx->ring = &dev_priv->ring[RCS];
if (file_priv == NULL)
return ctx;
ctx->file_priv = file_priv;
ret = idr_alloc(&file_priv->context_idr, ctx, DEFAULT_CONTEXT_ID + 1, 0,
GFP_KERNEL);
if (ret < 0)
goto err_out;
ctx->id = ret;
return ctx;
err_out:
do_destroy(ctx);
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
dev_priv->ring[RCS].default_context = ctx;
ret = i915_gem_object_pin(ctx->obj, CONTEXT_ALIGN, false, false);
if (ret)
goto err_destroy;
ret = do_switch(ctx);
if (ret)
goto err_unpin;
DRM_DEBUG_DRIVER("Default HW context loaded\n");
return 0;
err_unpin:
i915_gem_object_unpin(ctx->obj);
err_destroy:
do_destroy(ctx);
return ret;
}
void i915_gem_context_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!HAS_HW_CONTEXTS(dev)) {
dev_priv->hw_contexts_disabled = true;
return;
}
if (dev_priv->hw_contexts_disabled ||
dev_priv->ring[RCS].default_context)
return;
dev_priv->hw_context_size = round_up(get_context_size(dev), 4096);
if (dev_priv->hw_context_size > (1<<20)) {
dev_priv->hw_contexts_disabled = true;
return;
}
if (create_default_context(dev_priv)) {
dev_priv->hw_contexts_disabled = true;
return;
}
DRM_DEBUG_DRIVER("HW context support initialized\n");
}
void i915_gem_context_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->hw_contexts_disabled)
return;
intel_gpu_reset(dev);
i915_gem_object_unpin(dev_priv->ring[RCS].default_context->obj);
do_destroy(dev_priv->ring[RCS].default_context);
}
static int context_idr_cleanup(int id, void *p, void *data)
{
struct i915_hw_context *ctx = p;
BUG_ON(id == DEFAULT_CONTEXT_ID);
do_destroy(ctx);
return 0;
}
void i915_gem_context_close(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
mutex_lock(&dev->struct_mutex);
idr_for_each(&file_priv->context_idr, context_idr_cleanup, NULL);
idr_destroy(&file_priv->context_idr);
mutex_unlock(&dev->struct_mutex);
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
intel_ring_emit(ring, new_context->obj->gtt_offset |
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
struct drm_i915_gem_object *from_obj = ring->last_context_obj;
u32 hw_flags = 0;
int ret;
BUG_ON(from_obj != NULL && from_obj->pin_count == 0);
if (from_obj == to->obj)
return 0;
ret = i915_gem_object_pin(to->obj, CONTEXT_ALIGN, false, false);
if (ret)
return ret;
ret = i915_gem_object_set_to_gtt_domain(to->obj, false);
if (ret) {
i915_gem_object_unpin(to->obj);
return ret;
}
if (!to->obj->has_global_gtt_mapping)
i915_gem_gtt_bind_object(to->obj, to->obj->cache_level);
if (!to->is_initialized || is_default_context(to))
hw_flags |= MI_RESTORE_INHIBIT;
else if (WARN_ON_ONCE(from_obj == to->obj))
hw_flags |= MI_FORCE_RESTORE;
ret = mi_set_context(ring, to, hw_flags);
if (ret) {
i915_gem_object_unpin(to->obj);
return ret;
}
if (from_obj != NULL) {
from_obj->base.read_domains = I915_GEM_DOMAIN_INSTRUCTION;
i915_gem_object_move_to_active(from_obj, ring);
from_obj->dirty = 1;
BUG_ON(from_obj->ring != ring);
i915_gem_object_unpin(from_obj);
drm_gem_object_unreference(&from_obj->base);
}
drm_gem_object_reference(&to->obj->base);
ring->last_context_obj = to->obj;
to->is_initialized = true;
return 0;
}
int i915_switch_context(struct intel_ring_buffer *ring,
struct drm_file *file,
int to_id)
{
struct drm_i915_private *dev_priv = ring->dev->dev_private;
struct i915_hw_context *to;
if (dev_priv->hw_contexts_disabled)
return 0;
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
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_context_create *args = data;
struct drm_i915_file_private *file_priv = file->driver_priv;
struct i915_hw_context *ctx;
int ret;
if (!(dev->driver->driver_features & DRIVER_GEM))
return -ENODEV;
if (dev_priv->hw_contexts_disabled)
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
do_destroy(ctx);
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG_DRIVER("HW context %d destroyed\n", args->ctx_id);
return 0;
}
