static bool
gpu_is_idle(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
for_each_engine(engine, dev_priv) {
if (intel_engine_is_active(engine))
return false;
}
return true;
}
static bool
mark_free(struct i915_vma *vma, unsigned int flags, struct list_head *unwind)
{
if (i915_vma_is_pinned(vma))
return false;
if (WARN_ON(!list_empty(&vma->exec_list)))
return false;
if (flags & PIN_NONFAULT && vma->obj->fault_mappable)
return false;
list_add(&vma->exec_list, unwind);
return drm_mm_scan_add_block(&vma->node);
}
int
i915_gem_evict_something(struct i915_address_space *vm,
u64 min_size, u64 alignment,
unsigned cache_level,
u64 start, u64 end,
unsigned flags)
{
struct drm_i915_private *dev_priv = to_i915(vm->dev);
struct list_head eviction_list;
struct list_head *phases[] = {
&vm->inactive_list,
&vm->active_list,
NULL,
}, **phase;
struct i915_vma *vma, *next;
int ret;
trace_i915_gem_evict(vm, min_size, alignment, flags);
if (start != 0 || end != vm->total) {
drm_mm_init_scan_with_range(&vm->mm, min_size,
alignment, cache_level,
start, end);
} else
drm_mm_init_scan(&vm->mm, min_size, alignment, cache_level);
if (flags & PIN_NONBLOCK)
phases[1] = NULL;
search_again:
INIT_LIST_HEAD(&eviction_list);
phase = phases;
do {
list_for_each_entry(vma, *phase, vm_link)
if (mark_free(vma, flags, &eviction_list))
goto found;
} while (*++phase);
list_for_each_entry_safe(vma, next, &eviction_list, exec_list) {
ret = drm_mm_scan_remove_block(&vma->node);
BUG_ON(ret);
INIT_LIST_HEAD(&vma->exec_list);
}
if (!i915_is_ggtt(vm) || flags & PIN_NONBLOCK)
return -ENOSPC;
if (gpu_is_idle(dev_priv)) {
return intel_has_pending_fb_unpin(vm->dev) ? -EAGAIN : -ENOSPC;
}
ret = i915_gem_switch_to_kernel_context(dev_priv);
if (ret)
return ret;
ret = i915_gem_wait_for_idle(dev_priv,
I915_WAIT_INTERRUPTIBLE |
I915_WAIT_LOCKED);
if (ret)
return ret;
i915_gem_retire_requests(dev_priv);
goto search_again;
found:
list_for_each_entry_safe(vma, next, &eviction_list, exec_list) {
if (drm_mm_scan_remove_block(&vma->node))
__i915_vma_pin(vma);
else
list_del_init(&vma->exec_list);
}
while (!list_empty(&eviction_list)) {
vma = list_first_entry(&eviction_list,
struct i915_vma,
exec_list);
list_del_init(&vma->exec_list);
__i915_vma_unpin(vma);
if (ret == 0)
ret = i915_vma_unbind(vma);
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
if (i915_vma_is_pinned(vma)) {
if (!vma->exec_entry || i915_vma_pin_count(vma) > 1)
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
struct drm_i915_private *dev_priv = to_i915(vm->dev);
if (i915_is_ggtt(vm)) {
ret = i915_gem_switch_to_kernel_context(dev_priv);
if (ret)
return ret;
}
ret = i915_gem_wait_for_idle(dev_priv,
I915_WAIT_INTERRUPTIBLE |
I915_WAIT_LOCKED);
if (ret)
return ret;
i915_gem_retire_requests(dev_priv);
WARN_ON(!list_empty(&vm->active_list));
}
list_for_each_entry_safe(vma, next, &vm->inactive_list, vm_link)
if (!i915_vma_is_pinned(vma))
WARN_ON(i915_vma_unbind(vma));
return 0;
}
