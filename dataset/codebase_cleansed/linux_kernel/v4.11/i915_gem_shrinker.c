static bool i915_gem_shrinker_lock(struct drm_device *dev, bool *unlock)
{
switch (mutex_trylock_recursive(&dev->struct_mutex)) {
case MUTEX_TRYLOCK_FAILED:
return false;
case MUTEX_TRYLOCK_SUCCESS:
*unlock = true;
return true;
case MUTEX_TRYLOCK_RECURSIVE:
*unlock = false;
return true;
}
BUG();
}
static void i915_gem_shrinker_unlock(struct drm_device *dev, bool unlock)
{
if (!unlock)
return;
mutex_unlock(&dev->struct_mutex);
synchronize_rcu_expedited();
}
static bool any_vma_pinned(struct drm_i915_gem_object *obj)
{
struct i915_vma *vma;
list_for_each_entry(vma, &obj->vma_list, obj_link)
if (i915_vma_is_pinned(vma))
return true;
return false;
}
static bool swap_available(void)
{
return get_nr_swap_pages() > 0;
}
static bool can_release_pages(struct drm_i915_gem_object *obj)
{
if (!obj->mm.pages)
return false;
if (!i915_gem_object_is_shrinkable(obj))
return false;
if (atomic_read(&obj->mm.pages_pin_count) > obj->bind_count)
return false;
if (any_vma_pinned(obj))
return false;
return swap_available() || obj->mm.madv == I915_MADV_DONTNEED;
}
static bool unsafe_drop_pages(struct drm_i915_gem_object *obj)
{
if (i915_gem_object_unbind(obj) == 0)
__i915_gem_object_put_pages(obj, I915_MM_SHRINKER);
return !READ_ONCE(obj->mm.pages);
}
unsigned long
i915_gem_shrink(struct drm_i915_private *dev_priv,
unsigned long target, unsigned flags)
{
const struct {
struct list_head *list;
unsigned int bit;
} phases[] = {
{ &dev_priv->mm.unbound_list, I915_SHRINK_UNBOUND },
{ &dev_priv->mm.bound_list, I915_SHRINK_BOUND },
{ NULL, 0 },
}, *phase;
unsigned long count = 0;
bool unlock;
if (!i915_gem_shrinker_lock(&dev_priv->drm, &unlock))
return 0;
trace_i915_gem_shrink(dev_priv, target, flags);
i915_gem_retire_requests(dev_priv);
if ((flags & I915_SHRINK_BOUND) &&
!intel_runtime_pm_get_if_in_use(dev_priv))
flags &= ~I915_SHRINK_BOUND;
for (phase = phases; phase->list; phase++) {
struct list_head still_in_list;
struct drm_i915_gem_object *obj;
if ((flags & phase->bit) == 0)
continue;
INIT_LIST_HEAD(&still_in_list);
while (count < target &&
(obj = list_first_entry_or_null(phase->list,
typeof(*obj),
global_link))) {
list_move_tail(&obj->global_link, &still_in_list);
if (!obj->mm.pages) {
list_del_init(&obj->global_link);
continue;
}
if (flags & I915_SHRINK_PURGEABLE &&
obj->mm.madv != I915_MADV_DONTNEED)
continue;
if (flags & I915_SHRINK_VMAPS &&
!is_vmalloc_addr(obj->mm.mapping))
continue;
if (!(flags & I915_SHRINK_ACTIVE) &&
(i915_gem_object_is_active(obj) ||
obj->framebuffer_references))
continue;
if (!can_release_pages(obj))
continue;
if (unsafe_drop_pages(obj)) {
mutex_lock_nested(&obj->mm.lock,
I915_MM_SHRINKER);
if (!obj->mm.pages) {
__i915_gem_object_invalidate(obj);
list_del_init(&obj->global_link);
count += obj->base.size >> PAGE_SHIFT;
}
mutex_unlock(&obj->mm.lock);
}
}
list_splice_tail(&still_in_list, phase->list);
}
if (flags & I915_SHRINK_BOUND)
intel_runtime_pm_put(dev_priv);
i915_gem_retire_requests(dev_priv);
i915_gem_shrinker_unlock(&dev_priv->drm, unlock);
return count;
}
unsigned long i915_gem_shrink_all(struct drm_i915_private *dev_priv)
{
unsigned long freed;
freed = i915_gem_shrink(dev_priv, -1UL,
I915_SHRINK_BOUND |
I915_SHRINK_UNBOUND |
I915_SHRINK_ACTIVE);
synchronize_rcu();
return freed;
}
static unsigned long
i915_gem_shrinker_count(struct shrinker *shrinker, struct shrink_control *sc)
{
struct drm_i915_private *dev_priv =
container_of(shrinker, struct drm_i915_private, mm.shrinker);
struct drm_device *dev = &dev_priv->drm;
struct drm_i915_gem_object *obj;
unsigned long count;
bool unlock;
if (!i915_gem_shrinker_lock(dev, &unlock))
return 0;
i915_gem_retire_requests(dev_priv);
count = 0;
list_for_each_entry(obj, &dev_priv->mm.unbound_list, global_link)
if (can_release_pages(obj))
count += obj->base.size >> PAGE_SHIFT;
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_link) {
if (!i915_gem_object_is_active(obj) && can_release_pages(obj))
count += obj->base.size >> PAGE_SHIFT;
}
i915_gem_shrinker_unlock(dev, unlock);
return count;
}
static unsigned long
i915_gem_shrinker_scan(struct shrinker *shrinker, struct shrink_control *sc)
{
struct drm_i915_private *dev_priv =
container_of(shrinker, struct drm_i915_private, mm.shrinker);
struct drm_device *dev = &dev_priv->drm;
unsigned long freed;
bool unlock;
if (!i915_gem_shrinker_lock(dev, &unlock))
return SHRINK_STOP;
freed = i915_gem_shrink(dev_priv,
sc->nr_to_scan,
I915_SHRINK_BOUND |
I915_SHRINK_UNBOUND |
I915_SHRINK_PURGEABLE);
if (freed < sc->nr_to_scan)
freed += i915_gem_shrink(dev_priv,
sc->nr_to_scan - freed,
I915_SHRINK_BOUND |
I915_SHRINK_UNBOUND);
i915_gem_shrinker_unlock(dev, unlock);
return freed;
}
static bool
i915_gem_shrinker_lock_uninterruptible(struct drm_i915_private *dev_priv,
struct shrinker_lock_uninterruptible *slu,
int timeout_ms)
{
unsigned long timeout = jiffies + msecs_to_jiffies_timeout(timeout_ms);
do {
if (i915_gem_wait_for_idle(dev_priv, 0) == 0 &&
i915_gem_shrinker_lock(&dev_priv->drm, &slu->unlock))
break;
schedule_timeout_killable(1);
if (fatal_signal_pending(current))
return false;
if (time_after(jiffies, timeout)) {
pr_err("Unable to lock GPU to purge memory.\n");
return false;
}
} while (1);
slu->was_interruptible = dev_priv->mm.interruptible;
dev_priv->mm.interruptible = false;
return true;
}
static void
i915_gem_shrinker_unlock_uninterruptible(struct drm_i915_private *dev_priv,
struct shrinker_lock_uninterruptible *slu)
{
dev_priv->mm.interruptible = slu->was_interruptible;
i915_gem_shrinker_unlock(&dev_priv->drm, slu->unlock);
}
static int
i915_gem_shrinker_oom(struct notifier_block *nb, unsigned long event, void *ptr)
{
struct drm_i915_private *dev_priv =
container_of(nb, struct drm_i915_private, mm.oom_notifier);
struct shrinker_lock_uninterruptible slu;
struct drm_i915_gem_object *obj;
unsigned long unevictable, bound, unbound, freed_pages;
if (!i915_gem_shrinker_lock_uninterruptible(dev_priv, &slu, 5000))
return NOTIFY_DONE;
intel_runtime_pm_get(dev_priv);
freed_pages = i915_gem_shrink_all(dev_priv);
intel_runtime_pm_put(dev_priv);
unbound = bound = unevictable = 0;
list_for_each_entry(obj, &dev_priv->mm.unbound_list, global_link) {
if (!obj->mm.pages)
continue;
if (!can_release_pages(obj))
unevictable += obj->base.size >> PAGE_SHIFT;
else
unbound += obj->base.size >> PAGE_SHIFT;
}
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_link) {
if (!obj->mm.pages)
continue;
if (!can_release_pages(obj))
unevictable += obj->base.size >> PAGE_SHIFT;
else
bound += obj->base.size >> PAGE_SHIFT;
}
i915_gem_shrinker_unlock_uninterruptible(dev_priv, &slu);
if (freed_pages || unbound || bound)
pr_info("Purging GPU memory, %lu pages freed, "
"%lu pages still pinned.\n",
freed_pages, unevictable);
if (unbound || bound)
pr_err("%lu and %lu pages still available in the "
"bound and unbound GPU page lists.\n",
bound, unbound);
*(unsigned long *)ptr += freed_pages;
return NOTIFY_DONE;
}
static int
i915_gem_shrinker_vmap(struct notifier_block *nb, unsigned long event, void *ptr)
{
struct drm_i915_private *dev_priv =
container_of(nb, struct drm_i915_private, mm.vmap_notifier);
struct shrinker_lock_uninterruptible slu;
struct i915_vma *vma, *next;
unsigned long freed_pages = 0;
int ret;
if (!i915_gem_shrinker_lock_uninterruptible(dev_priv, &slu, 5000))
return NOTIFY_DONE;
ret = i915_gem_wait_for_idle(dev_priv, I915_WAIT_LOCKED);
if (ret)
goto out;
intel_runtime_pm_get(dev_priv);
freed_pages += i915_gem_shrink(dev_priv, -1UL,
I915_SHRINK_BOUND |
I915_SHRINK_UNBOUND |
I915_SHRINK_ACTIVE |
I915_SHRINK_VMAPS);
intel_runtime_pm_put(dev_priv);
list_for_each_entry_safe(vma, next,
&dev_priv->ggtt.base.inactive_list, vm_link) {
unsigned long count = vma->node.size >> PAGE_SHIFT;
if (vma->iomap && i915_vma_unbind(vma) == 0)
freed_pages += count;
}
out:
i915_gem_shrinker_unlock_uninterruptible(dev_priv, &slu);
*(unsigned long *)ptr += freed_pages;
return NOTIFY_DONE;
}
void i915_gem_shrinker_init(struct drm_i915_private *dev_priv)
{
dev_priv->mm.shrinker.scan_objects = i915_gem_shrinker_scan;
dev_priv->mm.shrinker.count_objects = i915_gem_shrinker_count;
dev_priv->mm.shrinker.seeks = DEFAULT_SEEKS;
WARN_ON(register_shrinker(&dev_priv->mm.shrinker));
dev_priv->mm.oom_notifier.notifier_call = i915_gem_shrinker_oom;
WARN_ON(register_oom_notifier(&dev_priv->mm.oom_notifier));
dev_priv->mm.vmap_notifier.notifier_call = i915_gem_shrinker_vmap;
WARN_ON(register_vmap_purge_notifier(&dev_priv->mm.vmap_notifier));
}
void i915_gem_shrinker_cleanup(struct drm_i915_private *dev_priv)
{
WARN_ON(unregister_vmap_purge_notifier(&dev_priv->mm.vmap_notifier));
WARN_ON(unregister_oom_notifier(&dev_priv->mm.oom_notifier));
unregister_shrinker(&dev_priv->mm.shrinker);
}
