static const char *i915_clflush_get_driver_name(struct dma_fence *fence)
{
return DRIVER_NAME;
}
static const char *i915_clflush_get_timeline_name(struct dma_fence *fence)
{
return "clflush";
}
static bool i915_clflush_enable_signaling(struct dma_fence *fence)
{
return true;
}
static void i915_clflush_release(struct dma_fence *fence)
{
struct clflush *clflush = container_of(fence, typeof(*clflush), dma);
i915_sw_fence_fini(&clflush->wait);
BUILD_BUG_ON(offsetof(typeof(*clflush), dma));
dma_fence_free(&clflush->dma);
}
static void __i915_do_clflush(struct drm_i915_gem_object *obj)
{
drm_clflush_sg(obj->mm.pages);
obj->cache_dirty = false;
intel_fb_obj_flush(obj, ORIGIN_CPU);
}
static void i915_clflush_work(struct work_struct *work)
{
struct clflush *clflush = container_of(work, typeof(*clflush), work);
struct drm_i915_gem_object *obj = clflush->obj;
if (!obj->cache_dirty)
goto out;
if (i915_gem_object_pin_pages(obj)) {
DRM_ERROR("Failed to acquire obj->pages for clflushing\n");
goto out;
}
__i915_do_clflush(obj);
i915_gem_object_unpin_pages(obj);
out:
i915_gem_object_put(obj);
dma_fence_signal(&clflush->dma);
dma_fence_put(&clflush->dma);
}
static int __i915_sw_fence_call
i915_clflush_notify(struct i915_sw_fence *fence,
enum i915_sw_fence_notify state)
{
struct clflush *clflush = container_of(fence, typeof(*clflush), wait);
switch (state) {
case FENCE_COMPLETE:
schedule_work(&clflush->work);
break;
case FENCE_FREE:
dma_fence_put(&clflush->dma);
break;
}
return NOTIFY_DONE;
}
void i915_gem_clflush_object(struct drm_i915_gem_object *obj,
unsigned int flags)
{
struct clflush *clflush;
if (!i915_gem_object_has_struct_page(obj))
return;
obj->cache_dirty = true;
if (!(flags & I915_CLFLUSH_FORCE) && i915_gem_object_is_coherent(obj))
return;
trace_i915_gem_object_clflush(obj);
clflush = NULL;
if (!(flags & I915_CLFLUSH_SYNC))
clflush = kmalloc(sizeof(*clflush), GFP_KERNEL);
if (clflush) {
dma_fence_init(&clflush->dma,
&i915_clflush_ops,
&clflush_lock,
clflush_context,
0);
i915_sw_fence_init(&clflush->wait, i915_clflush_notify);
clflush->obj = i915_gem_object_get(obj);
INIT_WORK(&clflush->work, i915_clflush_work);
dma_fence_get(&clflush->dma);
i915_sw_fence_await_reservation(&clflush->wait,
obj->resv, NULL,
true, I915_FENCE_TIMEOUT,
GFP_KERNEL);
reservation_object_lock(obj->resv, NULL);
reservation_object_add_excl_fence(obj->resv, &clflush->dma);
reservation_object_unlock(obj->resv);
i915_sw_fence_commit(&clflush->wait);
} else if (obj->mm.pages) {
__i915_do_clflush(obj);
} else {
GEM_BUG_ON(obj->base.write_domain != I915_GEM_DOMAIN_CPU);
}
}
void i915_gem_clflush_init(struct drm_i915_private *i915)
{
clflush_context = dma_fence_context_alloc(1);
}
