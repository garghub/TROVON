static bool
mark_free(struct i915_vma *vma, struct list_head *unwind)
{
if (vma->obj->pin_count)
return false;
if (WARN_ON(!list_empty(&vma->exec_list)))
return false;
list_add(&vma->exec_list, unwind);
return drm_mm_scan_add_block(&vma->node);
}
int
i915_gem_evict_something(struct drm_device *dev, struct i915_address_space *vm,
int min_size, unsigned alignment, unsigned cache_level,
bool mappable, bool nonblocking)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct list_head eviction_list, unwind_list;
struct i915_vma *vma;
int ret = 0;
int pass = 0;
trace_i915_gem_evict(dev, min_size, alignment, mappable);
INIT_LIST_HEAD(&unwind_list);
if (mappable) {
BUG_ON(!i915_is_ggtt(vm));
drm_mm_init_scan_with_range(&vm->mm, min_size,
alignment, cache_level, 0,
dev_priv->gtt.mappable_end);
} else
drm_mm_init_scan(&vm->mm, min_size, alignment, cache_level);
search_again:
list_for_each_entry(vma, &vm->inactive_list, mm_list) {
if (mark_free(vma, &unwind_list))
goto found;
}
if (nonblocking)
goto none;
list_for_each_entry(vma, &vm->active_list, mm_list) {
if (mark_free(vma, &unwind_list))
goto found;
}
none:
while (!list_empty(&unwind_list)) {
vma = list_first_entry(&unwind_list,
struct i915_vma,
exec_list);
ret = drm_mm_scan_remove_block(&vma->node);
BUG_ON(ret);
list_del_init(&vma->exec_list);
}
if (nonblocking)
return -ENOSPC;
if (pass++ == 0) {
ret = i915_gpu_idle(dev);
if (ret)
return ret;
i915_gem_retire_requests(dev);
goto search_again;
}
return intel_has_pending_fb_unpin(dev) ? -EAGAIN : -ENOSPC;
found:
INIT_LIST_HEAD(&eviction_list);
while (!list_empty(&unwind_list)) {
vma = list_first_entry(&unwind_list,
struct i915_vma,
exec_list);
if (drm_mm_scan_remove_block(&vma->node)) {
list_move(&vma->exec_list, &eviction_list);
drm_gem_object_reference(&vma->obj->base);
continue;
}
list_del_init(&vma->exec_list);
}
while (!list_empty(&eviction_list)) {
struct drm_gem_object *obj;
vma = list_first_entry(&eviction_list,
struct i915_vma,
exec_list);
obj = &vma->obj->base;
list_del_init(&vma->exec_list);
if (ret == 0)
ret = i915_vma_unbind(vma);
drm_gem_object_unreference(obj);
}
return ret;
}
int i915_gem_evict_vm(struct i915_address_space *vm, bool do_idle)
{
struct i915_vma *vma, *next;
int ret;
trace_i915_gem_evict_vm(vm);
if (do_idle) {
ret = i915_gpu_idle(vm->dev);
if (ret)
return ret;
i915_gem_retire_requests(vm->dev);
}
list_for_each_entry_safe(vma, next, &vm->inactive_list, mm_list)
if (vma->obj->pin_count == 0)
WARN_ON(i915_vma_unbind(vma));
return 0;
}
int
i915_gem_evict_everything(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct i915_address_space *vm;
bool lists_empty = true;
int ret;
list_for_each_entry(vm, &dev_priv->vm_list, global_link) {
lists_empty = (list_empty(&vm->inactive_list) &&
list_empty(&vm->active_list));
if (!lists_empty)
lists_empty = false;
}
if (lists_empty)
return -ENOSPC;
trace_i915_gem_evict_everything(dev);
ret = i915_gpu_idle(dev);
if (ret)
return ret;
i915_gem_retire_requests(dev);
list_for_each_entry(vm, &dev_priv->vm_list, global_link)
WARN_ON(i915_gem_evict_vm(vm, false));
return 0;
}
