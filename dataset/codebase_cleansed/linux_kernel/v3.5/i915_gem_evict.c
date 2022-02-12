static bool
mark_free(struct drm_i915_gem_object *obj, struct list_head *unwind)
{
if (obj->pin_count)
return false;
list_add(&obj->exec_list, unwind);
return drm_mm_scan_add_block(obj->gtt_space);
}
int
i915_gem_evict_something(struct drm_device *dev, int min_size,
unsigned alignment, bool mappable)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct list_head eviction_list, unwind_list;
struct drm_i915_gem_object *obj;
int ret = 0;
trace_i915_gem_evict(dev, min_size, alignment, mappable);
INIT_LIST_HEAD(&unwind_list);
if (mappable)
drm_mm_init_scan_with_range(&dev_priv->mm.gtt_space, min_size,
alignment, 0,
dev_priv->mm.gtt_mappable_end);
else
drm_mm_init_scan(&dev_priv->mm.gtt_space, min_size, alignment);
list_for_each_entry(obj, &dev_priv->mm.inactive_list, mm_list) {
if (mark_free(obj, &unwind_list))
goto found;
}
list_for_each_entry(obj, &dev_priv->mm.active_list, mm_list) {
if (obj->base.write_domain)
continue;
if (mark_free(obj, &unwind_list))
goto found;
}
list_for_each_entry(obj, &dev_priv->mm.flushing_list, mm_list) {
if (mark_free(obj, &unwind_list))
goto found;
}
list_for_each_entry(obj, &dev_priv->mm.active_list, mm_list) {
if (!obj->base.write_domain)
continue;
if (mark_free(obj, &unwind_list))
goto found;
}
while (!list_empty(&unwind_list)) {
obj = list_first_entry(&unwind_list,
struct drm_i915_gem_object,
exec_list);
ret = drm_mm_scan_remove_block(obj->gtt_space);
BUG_ON(ret);
list_del_init(&obj->exec_list);
}
return -ENOSPC;
found:
INIT_LIST_HEAD(&eviction_list);
while (!list_empty(&unwind_list)) {
obj = list_first_entry(&unwind_list,
struct drm_i915_gem_object,
exec_list);
if (drm_mm_scan_remove_block(obj->gtt_space)) {
list_move(&obj->exec_list, &eviction_list);
drm_gem_object_reference(&obj->base);
continue;
}
list_del_init(&obj->exec_list);
}
while (!list_empty(&eviction_list)) {
obj = list_first_entry(&eviction_list,
struct drm_i915_gem_object,
exec_list);
if (ret == 0)
ret = i915_gem_object_unbind(obj);
list_del_init(&obj->exec_list);
drm_gem_object_unreference(&obj->base);
}
return ret;
}
int
i915_gem_evict_everything(struct drm_device *dev, bool purgeable_only)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj, *next;
bool lists_empty;
int ret;
lists_empty = (list_empty(&dev_priv->mm.inactive_list) &&
list_empty(&dev_priv->mm.flushing_list) &&
list_empty(&dev_priv->mm.active_list));
if (lists_empty)
return -ENOSPC;
trace_i915_gem_evict_everything(dev, purgeable_only);
ret = i915_gpu_idle(dev);
if (ret)
return ret;
i915_gem_retire_requests(dev);
BUG_ON(!list_empty(&dev_priv->mm.flushing_list));
list_for_each_entry_safe(obj, next,
&dev_priv->mm.inactive_list, mm_list) {
if (!purgeable_only || obj->madv != I915_MADV_WILLNEED) {
if (obj->pin_count == 0)
WARN_ON(i915_gem_object_unbind(obj));
}
}
return 0;
}
