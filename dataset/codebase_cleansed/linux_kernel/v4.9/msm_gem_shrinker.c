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
static bool msm_gem_shrinker_lock(struct drm_device *dev, bool *unlock)
{
if (!mutex_trylock(&dev->struct_mutex)) {
if (!mutex_is_locked_by(&dev->struct_mutex, current))
return false;
*unlock = false;
} else {
*unlock = true;
}
return true;
}
static unsigned long
msm_gem_shrinker_count(struct shrinker *shrinker, struct shrink_control *sc)
{
struct msm_drm_private *priv =
container_of(shrinker, struct msm_drm_private, shrinker);
struct drm_device *dev = priv->dev;
struct msm_gem_object *msm_obj;
unsigned long count = 0;
bool unlock;
if (!msm_gem_shrinker_lock(dev, &unlock))
return 0;
list_for_each_entry(msm_obj, &priv->inactive_list, mm_list) {
if (is_purgeable(msm_obj))
count += msm_obj->base.size >> PAGE_SHIFT;
}
if (unlock)
mutex_unlock(&dev->struct_mutex);
return count;
}
static unsigned long
msm_gem_shrinker_scan(struct shrinker *shrinker, struct shrink_control *sc)
{
struct msm_drm_private *priv =
container_of(shrinker, struct msm_drm_private, shrinker);
struct drm_device *dev = priv->dev;
struct msm_gem_object *msm_obj;
unsigned long freed = 0;
bool unlock;
if (!msm_gem_shrinker_lock(dev, &unlock))
return SHRINK_STOP;
list_for_each_entry(msm_obj, &priv->inactive_list, mm_list) {
if (freed >= sc->nr_to_scan)
break;
if (is_purgeable(msm_obj)) {
msm_gem_purge(&msm_obj->base);
freed += msm_obj->base.size >> PAGE_SHIFT;
}
}
if (unlock)
mutex_unlock(&dev->struct_mutex);
if (freed > 0)
pr_info_ratelimited("Purging %lu bytes\n", freed << PAGE_SHIFT);
return freed;
}
static int
msm_gem_shrinker_vmap(struct notifier_block *nb, unsigned long event, void *ptr)
{
struct msm_drm_private *priv =
container_of(nb, struct msm_drm_private, vmap_notifier);
struct drm_device *dev = priv->dev;
struct msm_gem_object *msm_obj;
unsigned unmapped = 0;
bool unlock;
if (!msm_gem_shrinker_lock(dev, &unlock))
return NOTIFY_DONE;
list_for_each_entry(msm_obj, &priv->inactive_list, mm_list) {
if (is_vunmapable(msm_obj)) {
msm_gem_vunmap(&msm_obj->base);
if (++unmapped >= 15)
break;
}
}
if (unlock)
mutex_unlock(&dev->struct_mutex);
*(unsigned long *)ptr += unmapped;
if (unmapped > 0)
pr_info_ratelimited("Purging %u vmaps\n", unmapped);
return NOTIFY_DONE;
}
void msm_gem_shrinker_init(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
priv->shrinker.count_objects = msm_gem_shrinker_count;
priv->shrinker.scan_objects = msm_gem_shrinker_scan;
priv->shrinker.seeks = DEFAULT_SEEKS;
WARN_ON(register_shrinker(&priv->shrinker));
priv->vmap_notifier.notifier_call = msm_gem_shrinker_vmap;
WARN_ON(register_vmap_purge_notifier(&priv->vmap_notifier));
}
void msm_gem_shrinker_cleanup(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
if (priv->shrinker.nr_deferred) {
WARN_ON(unregister_vmap_purge_notifier(&priv->vmap_notifier));
unregister_shrinker(&priv->shrinker);
}
}
