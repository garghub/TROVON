void i915_gem_batch_pool_init(struct drm_device *dev,
struct i915_gem_batch_pool *pool)
{
pool->dev = dev;
INIT_LIST_HEAD(&pool->cache_list);
}
void i915_gem_batch_pool_fini(struct i915_gem_batch_pool *pool)
{
WARN_ON(!mutex_is_locked(&pool->dev->struct_mutex));
while (!list_empty(&pool->cache_list)) {
struct drm_i915_gem_object *obj =
list_first_entry(&pool->cache_list,
struct drm_i915_gem_object,
batch_pool_list);
WARN_ON(obj->active);
list_del_init(&obj->batch_pool_list);
drm_gem_object_unreference(&obj->base);
}
}
struct drm_i915_gem_object *
i915_gem_batch_pool_get(struct i915_gem_batch_pool *pool,
size_t size)
{
struct drm_i915_gem_object *obj = NULL;
struct drm_i915_gem_object *tmp, *next;
WARN_ON(!mutex_is_locked(&pool->dev->struct_mutex));
list_for_each_entry_safe(tmp, next,
&pool->cache_list, batch_pool_list) {
if (tmp->active)
continue;
if (tmp->madv == __I915_MADV_PURGED) {
list_del(&tmp->batch_pool_list);
drm_gem_object_unreference(&tmp->base);
continue;
}
if (tmp->base.size >= size &&
tmp->base.size <= (2 * size)) {
obj = tmp;
break;
}
}
if (!obj) {
obj = i915_gem_alloc_object(pool->dev, size);
if (!obj)
return ERR_PTR(-ENOMEM);
list_add_tail(&obj->batch_pool_list, &pool->cache_list);
}
else
list_move_tail(&obj->batch_pool_list, &pool->cache_list);
obj->madv = I915_MADV_WILLNEED;
return obj;
}
