static bool mutex_is_locked_by(struct mutex *mutex, struct task_struct *task)
{
if (!mutex_is_locked(mutex))
return false;
#if defined(CONFIG_SMP) || defined(CONFIG_DEBUG_MUTEXES)
return mutex->owner == task;
#else
return false;
#endif
}
unsigned long
i915_gem_shrink(struct drm_i915_private *dev_priv,
long target, unsigned flags)
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
drm_gem_object_reference(&obj->base);
list_for_each_entry_safe(vma, v,
&obj->vma_list, vma_link)
if (i915_vma_unbind(vma))
break;
if (i915_gem_object_put_pages(obj) == 0)
count += obj->base.size >> PAGE_SHIFT;
drm_gem_object_unreference(&obj->base);
}
list_splice(&still_in_list, phase->list);
}
return count;
}
unsigned long i915_gem_shrink_all(struct drm_i915_private *dev_priv)
{
i915_gem_evict_everything(dev_priv->dev);
return i915_gem_shrink(dev_priv, LONG_MAX,
I915_SHRINK_BOUND | I915_SHRINK_UNBOUND);
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
static int num_vma_bound(struct drm_i915_gem_object *obj)
{
struct i915_vma *vma;
int count = 0;
list_for_each_entry(vma, &obj->vma_list, vma_link) {
if (drm_mm_node_allocated(&vma->node))
count++;
if (vma->pin_count)
count++;
}
return count;
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
if (obj->pages_pin_count == 0)
count += obj->base.size >> PAGE_SHIFT;
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_list) {
if (obj->pages_pin_count == num_vma_bound(obj))
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
static int
i915_gem_shrinker_oom(struct notifier_block *nb, unsigned long event, void *ptr)
{
struct drm_i915_private *dev_priv =
container_of(nb, struct drm_i915_private, mm.oom_notifier);
struct drm_device *dev = dev_priv->dev;
struct drm_i915_gem_object *obj;
unsigned long timeout = msecs_to_jiffies(5000) + 1;
unsigned long pinned, bound, unbound, freed_pages;
bool was_interruptible;
bool unlock;
while (!i915_gem_shrinker_lock(dev, &unlock) && --timeout) {
schedule_timeout_killable(1);
if (fatal_signal_pending(current))
return NOTIFY_DONE;
}
if (timeout == 0) {
pr_err("Unable to purge GPU memory due lock contention.\n");
return NOTIFY_DONE;
}
was_interruptible = dev_priv->mm.interruptible;
dev_priv->mm.interruptible = false;
freed_pages = i915_gem_shrink_all(dev_priv);
dev_priv->mm.interruptible = was_interruptible;
unbound = bound = pinned = 0;
list_for_each_entry(obj, &dev_priv->mm.unbound_list, global_list) {
if (!obj->base.filp)
continue;
if (obj->pages_pin_count)
pinned += obj->base.size;
else
unbound += obj->base.size;
}
list_for_each_entry(obj, &dev_priv->mm.bound_list, global_list) {
if (!obj->base.filp)
continue;
if (obj->pages_pin_count)
pinned += obj->base.size;
else
bound += obj->base.size;
}
if (unlock)
mutex_unlock(&dev->struct_mutex);
if (freed_pages || unbound || bound)
pr_info("Purging GPU memory, %lu bytes freed, %lu bytes still pinned.\n",
freed_pages << PAGE_SHIFT, pinned);
if (unbound || bound)
pr_err("%lu and %lu bytes still available in the "
"bound and unbound GPU page lists.\n",
bound, unbound);
*(unsigned long *)ptr += freed_pages;
return NOTIFY_DONE;
}
void i915_gem_shrinker_init(struct drm_i915_private *dev_priv)
{
dev_priv->mm.shrinker.scan_objects = i915_gem_shrinker_scan;
dev_priv->mm.shrinker.count_objects = i915_gem_shrinker_count;
dev_priv->mm.shrinker.seeks = DEFAULT_SEEKS;
register_shrinker(&dev_priv->mm.shrinker);
dev_priv->mm.oom_notifier.notifier_call = i915_gem_shrinker_oom;
register_oom_notifier(&dev_priv->mm.oom_notifier);
}
