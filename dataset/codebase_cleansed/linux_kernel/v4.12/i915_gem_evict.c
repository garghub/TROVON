static bool ggtt_is_idle(struct drm_i915_private *dev_priv)
{
struct i915_ggtt *ggtt = &dev_priv->ggtt;
struct intel_engine_cs *engine;
enum intel_engine_id id;
for_each_engine(engine, dev_priv, id) {
struct intel_timeline *tl;
tl = &ggtt->base.timeline.engine[engine->id];
if (i915_gem_active_isset(&tl->last_request))
return false;
}
return true;
}
static bool
mark_free(struct drm_mm_scan *scan,
struct i915_vma *vma,
unsigned int flags,
struct list_head *unwind)
{
if (i915_vma_is_pinned(vma))
return false;
if (WARN_ON(!list_empty(&vma->exec_list)))
return false;
if (flags & PIN_NONFAULT && !list_empty(&vma->obj->userfault_link))
return false;
list_add(&vma->exec_list, unwind);
return drm_mm_scan_add_block(scan, &vma->node);
}
int
i915_gem_evict_something(struct i915_address_space *vm,
u64 min_size, u64 alignment,
unsigned cache_level,
u64 start, u64 end,
unsigned flags)
{
struct drm_i915_private *dev_priv = vm->i915;
struct drm_mm_scan scan;
struct list_head eviction_list;
struct list_head *phases[] = {
&vm->inactive_list,
&vm->active_list,
NULL,
}, **phase;
struct i915_vma *vma, *next;
struct drm_mm_node *node;
enum drm_mm_insert_mode mode;
int ret;
lockdep_assert_held(&vm->i915->drm.struct_mutex);
trace_i915_gem_evict(vm, min_size, alignment, flags);
mode = DRM_MM_INSERT_BEST;
if (flags & PIN_HIGH)
mode = DRM_MM_INSERT_HIGH;
if (flags & PIN_MAPPABLE)
mode = DRM_MM_INSERT_LOW;
drm_mm_scan_init_with_range(&scan, &vm->mm,
min_size, alignment, cache_level,
start, end, mode);
if (!(flags & PIN_NONBLOCK))
i915_gem_retire_requests(dev_priv);
else
phases[1] = NULL;
search_again:
INIT_LIST_HEAD(&eviction_list);
phase = phases;
do {
list_for_each_entry(vma, *phase, vm_link)
if (mark_free(&scan, vma, flags, &eviction_list))
goto found;
} while (*++phase);
list_for_each_entry_safe(vma, next, &eviction_list, exec_list) {
ret = drm_mm_scan_remove_block(&scan, &vma->node);
BUG_ON(ret);
INIT_LIST_HEAD(&vma->exec_list);
}
if (!i915_is_ggtt(vm) || flags & PIN_NONBLOCK)
return -ENOSPC;
if (ggtt_is_idle(dev_priv)) {
return intel_has_pending_fb_unpin(dev_priv) ? -EAGAIN : -ENOSPC;
}
ret = i915_gem_switch_to_kernel_context(dev_priv);
if (ret)
return ret;
ret = i915_gem_wait_for_idle(dev_priv,
I915_WAIT_INTERRUPTIBLE |
I915_WAIT_LOCKED);
if (ret)
return ret;
goto search_again;
found:
list_for_each_entry_safe(vma, next, &eviction_list, exec_list) {
if (drm_mm_scan_remove_block(&scan, &vma->node))
__i915_vma_pin(vma);
else
list_del_init(&vma->exec_list);
}
ret = 0;
while (!list_empty(&eviction_list)) {
vma = list_first_entry(&eviction_list,
struct i915_vma,
exec_list);
list_del_init(&vma->exec_list);
__i915_vma_unpin(vma);
if (ret == 0)
ret = i915_vma_unbind(vma);
}
while (ret == 0 && (node = drm_mm_scan_color_evict(&scan))) {
vma = container_of(node, struct i915_vma, node);
ret = i915_vma_unbind(vma);
}
return ret;
}
int i915_gem_evict_for_node(struct i915_address_space *vm,
struct drm_mm_node *target,
unsigned int flags)
{
LIST_HEAD(eviction_list);
struct drm_mm_node *node;
u64 start = target->start;
u64 end = start + target->size;
struct i915_vma *vma, *next;
bool check_color;
int ret = 0;
lockdep_assert_held(&vm->i915->drm.struct_mutex);
GEM_BUG_ON(!IS_ALIGNED(start, I915_GTT_PAGE_SIZE));
GEM_BUG_ON(!IS_ALIGNED(end, I915_GTT_PAGE_SIZE));
trace_i915_gem_evict_node(vm, target, flags);
if (!(flags & PIN_NONBLOCK))
i915_gem_retire_requests(vm->i915);
check_color = vm->mm.color_adjust;
if (check_color) {
if (start)
start -= I915_GTT_PAGE_SIZE;
end += I915_GTT_PAGE_SIZE;
}
GEM_BUG_ON(start >= end);
drm_mm_for_each_node_in_range(node, &vm->mm, start, end) {
if (node->color == I915_COLOR_UNEVICTABLE) {
ret = -ENOSPC;
break;
}
GEM_BUG_ON(!node->allocated);
vma = container_of(node, typeof(*vma), node);
if (check_color) {
if (node->start + node->size == target->start) {
if (node->color == target->color)
continue;
}
if (node->start == target->start + target->size) {
if (node->color == target->color)
continue;
}
}
if (flags & PIN_NONBLOCK &&
(i915_vma_is_pinned(vma) || i915_vma_is_active(vma))) {
ret = -ENOSPC;
break;
}
if (i915_vma_is_pinned(vma) || !list_empty(&vma->exec_list)) {
ret = -ENOSPC;
if (vma->exec_entry &&
vma->exec_entry->flags & EXEC_OBJECT_PINNED)
ret = -EINVAL;
break;
}
__i915_vma_pin(vma);
list_add(&vma->exec_list, &eviction_list);
}
list_for_each_entry_safe(vma, next, &eviction_list, exec_list) {
list_del_init(&vma->exec_list);
__i915_vma_unpin(vma);
if (ret == 0)
ret = i915_vma_unbind(vma);
}
return ret;
}
int i915_gem_evict_vm(struct i915_address_space *vm, bool do_idle)
{
struct i915_vma *vma, *next;
int ret;
lockdep_assert_held(&vm->i915->drm.struct_mutex);
trace_i915_gem_evict_vm(vm);
if (do_idle) {
struct drm_i915_private *dev_priv = vm->i915;
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
WARN_ON(!list_empty(&vm->active_list));
}
list_for_each_entry_safe(vma, next, &vm->inactive_list, vm_link)
if (!i915_vma_is_pinned(vma))
WARN_ON(i915_vma_unbind(vma));
return 0;
}
