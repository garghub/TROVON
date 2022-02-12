static bool
mark_free(struct i915_vma *vma, struct list_head *unwind)
{
if (vma->pin_count)
return false;
if (WARN_ON(!list_empty(&vma->exec_list)))
return false;
list_add(&vma->exec_list, unwind);
return drm_mm_scan_add_block(&vma->node);
}
int
i915_gem_evict_something(struct drm_device *dev, struct i915_address_space *vm,
int min_size, unsigned alignment, unsigned cache_level,
unsigned long start, unsigned long end,
unsigned flags)
{
struct list_head eviction_list, unwind_list;
struct i915_vma *vma;
int ret = 0;
int pass = 0;
trace_i915_gem_evict(dev, min_size, alignment, flags);
INIT_LIST_HEAD(&unwind_list);
if (start != 0 || end != vm->total) {
drm_mm_init_scan_with_range(&vm->mm, min_size,
alignment, cache_level,
start, end);
} else
drm_mm_init_scan(&vm->mm, min_size, alignment, cache_level);
search_again:
list_for_each_entry(vma, &vm->inactive_list, vm_link) {
if (mark_free(vma, &unwind_list))
goto found;
}
if (flags & PIN_NONBLOCK)
goto none;
list_for_each_entry(vma, &vm->active_list, vm_link) {
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
if (flags & PIN_NONBLOCK)
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
int
i915_gem_evict_for_vma(struct i915_vma *target)
{
struct drm_mm_node *node, *next;
list_for_each_entry_safe(node, next,
&target->vm->mm.head_node.node_list,
node_list) {
struct i915_vma *vma;
int ret;
if (node->start + node->size <= target->node.start)
continue;
if (node->start >= target->node.start + target->node.size)
break;
vma = container_of(node, typeof(*vma), node);
if (vma->pin_count) {
if (!vma->exec_entry || (vma->pin_count > 1))
return -EBUSY;
if (vma->exec_entry->flags & EXEC_OBJECT_PINNED)
return -EINVAL;
return -ENOSPC;
}
ret = i915_vma_unbind(vma);
if (ret)
return ret;
}
return 0;
}
int i915_gem_evict_vm(struct i915_address_space *vm, bool do_idle)
{
struct i915_vma *vma, *next;
int ret;
WARN_ON(!mutex_is_locked(&vm->dev->struct_mutex));
trace_i915_gem_evict_vm(vm);
if (do_idle) {
ret = i915_gpu_idle(vm->dev);
if (ret)
return ret;
i915_gem_retire_requests(vm->dev);
WARN_ON(!list_empty(&vm->active_list));
}
list_for_each_entry_safe(vma, next, &vm->inactive_list, vm_link)
if (vma->pin_count == 0)
WARN_ON(i915_vma_unbind(vma));
return 0;
}
