static bool mutex_is_locked_by(struct mutex *mutex, struct task_struct *task)
{
if (!mutex_is_locked(mutex))
return false;
#if defined(CONFIG_DEBUG_MUTEXES) || defined(CONFIG_MUTEX_SPIN_ON_OWNER)
return mutex->owner == task;
#else
return false;
#endif
}
static int num_vma_bound(struct drm_i915_gem_object *obj)
{
struct i915_vma *vma;
int count = 0;
list_for_each_entry(vma, &obj->vma_list, obj_link) {
if (drm_mm_node_allocated(&vma->node))
count++;
if (vma->pin_count)
count++;
}
return count;
}
static bool swap_available(void)
{
return get_nr_swap_pages() > 0;
}
static bool can_release_pages(struct drm_i915_gem_object *obj)
{
if (!obj->base.filp)
return false;
if (obj->pages_pin_count != num_vma_bound(obj))
return false;
return swap_available() || obj->madv == I915_MADV_DONTNEED;
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
trace_i915_gem_shrink(dev_priv, target, flags);
i915_gem_retire_requests(dev_priv->dev);
for (phase = phases; phase->list; phase++) {
struct list_head still_in_list;
if ((flags & phase->bit) == 0)
continue;
INIT_LIST_HEAD(&still_in_list);
while (count < target && !list_empty(phase->list)) {
struct drm_i915_gem_object *obj;
struct i915_vma *vma, *v;
obj = list_first_entry(phase->list,
typeof(*obj), global_list);
list_move_tail(&obj->global_list, &still_in_list);
if (flags & I915_SHRINK_PURGEABLE &&
obj->madv != I915_MADV_DONTNEED)
continue;
if (flags & I915_SHRINK_VMAPS &&
!is_vmalloc_addr(obj->mapping))
continue;
if ((flags & I915_SHRINK_ACTIVE) == 0 && obj->active)
continue;
if (!can_release_pages(obj))
continue;
drm_gem_object_reference(&obj->base);
list_for_each_entry_safe(vma, v,
&obj->vma_list, obj_link)
if (i915_vma_unbind(vma))
break;
if (i915_gem_object_put_pages(obj) == 0)
count += obj->base.size >> PAGE_SHIFT;
drm_gem_object_unreference(&obj->base);
}
list_splice(&still_in_list, phase->list);
}
i915_gem_retire_requests(dev_priv->dev);
return count;
}
unsigned long i915_gem_shrink_all(struct drm_i915_private *dev_priv)
{
return i915_gem_shrink(dev_priv, -1UL,
I915_SHRINK_BOUND |
I915_SHRINK_UNBOUND |
I915_SHRINK_ACTIVE);
}
static bool i915_gem_shrinker_lock(struct drm_device *dev, bool *unlock)
{
if (!mutex_trylock(&dev->struct_mutex)) {
if (!mutex_is_locked_by(&dev->struct_mutex, current))
return false;
if (to_i915(dev)->mm.shrinker_no_lock_stealing)
return false;
*unlock = false;
} else
*unlock = true;
return true;
}
static unsigned long
i915_gem_shrinker_count(struct shrinker *shrinker, struct shrink_control *sc)
{
struct drm_i915_private *dev_priv =
container_of(shrinker, struct drm_i915_private, mm.shrinker);
struct drm_device *dev = dev_priv->dev;
struct drm_i915_gem_object *obj;
unsigned long count;
bool unlock;
if (!i915_gem_shrinker_lock(dev, &unlock))
return 0;
count = 0;
list_for_each_entry(obj, &dev_priv->mm.unbound_list, global_list)
if (can_release_pages(obj))
count += obj->base.size >> PAGE_SHIFT;
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_list) {
if (!obj->active && can_release_pages(obj))
count += obj->base.size >> PAGE_SHIFT;
}
if (unlock)
mutex_unlock(&dev->struct_mutex);
return count;
}
static unsigned long
i915_gem_shrinker_scan(struct shrinker *shrinker, struct shrink_control *sc)
{
struct drm_i915_private *dev_priv =
container_of(shrinker, struct drm_i915_private, mm.shrinker);
struct drm_device *dev = dev_priv->dev;
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
if (unlock)
mutex_unlock(&dev->struct_mutex);
return freed;
}
static bool
i915_gem_shrinker_lock_uninterruptible(struct drm_i915_private *dev_priv,
struct shrinker_lock_uninterruptible *slu,
int timeout_ms)
{
unsigned long timeout = msecs_to_jiffies(timeout_ms) + 1;
while (!i915_gem_shrinker_lock(dev_priv->dev, &slu->unlock)) {
schedule_timeout_killable(1);
if (fatal_signal_pending(current))
return false;
if (--timeout == 0) {
pr_err("Unable to lock GPU to purge memory.\n");
return false;
}
}
slu->was_interruptible = dev_priv->mm.interruptible;
dev_priv->mm.interruptible = false;
return true;
}
static void
i915_gem_shrinker_unlock_uninterruptible(struct drm_i915_private *dev_priv,
struct shrinker_lock_uninterruptible *slu)
{
dev_priv->mm.interruptible = slu->was_interruptible;
if (slu->unlock)
mutex_unlock(&dev_priv->dev->struct_mutex);
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
freed_pages = i915_gem_shrink_all(dev_priv);
unbound = bound = unevictable = 0;
list_for_each_entry(obj, &dev_priv->mm.unbound_list, global_list) {
if (!can_release_pages(obj))
unevictable += obj->base.size >> PAGE_SHIFT;
else
unbound += obj->base.size >> PAGE_SHIFT;
}
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_list) {
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
unsigned long freed_pages;
if (!i915_gem_shrinker_lock_uninterruptible(dev_priv, &slu, 5000))
return NOTIFY_DONE;
freed_pages = i915_gem_shrink(dev_priv, -1UL,
I915_SHRINK_BOUND |
I915_SHRINK_UNBOUND |
I915_SHRINK_ACTIVE |
I915_SHRINK_VMAPS);
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
