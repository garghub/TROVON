void i915_gem_batch_pool_init(struct drm_device *dev,
struct i915_gem_batch_pool *pool)
{
int n;
pool->dev = dev;
for (n = 0; n < ARRAY_SIZE(pool->cache_list); n++)
INIT_LIST_HEAD(&pool->cache_list[n]);
}
void i915_gem_batch_pool_fini(struct i915_gem_batch_pool *pool)
{
int n;
WARN_ON(!mutex_is_locked(&pool->dev->struct_mutex));
for (n = 0; n < ARRAY_SIZE(pool->cache_list); n++) {
while (!list_empty(&pool->cache_list[n])) {
struct drm_i915_gem_object *obj =
list_first_entry(&pool->cache_list[n],
struct drm_i915_gem_object,
batch_pool_link);
list_del(&obj->batch_pool_link);
drm_gem_object_unreference(&obj->base);
}
}
}
struct drm_i915_gem_object *
i915_gem_batch_pool_get(struct i915_gem_batch_pool *pool,
size_t size)
{
struct drm_i915_gem_object *obj = NULL;
struct drm_i915_gem_object *tmp, *next;
struct list_head *list;
int n;
WARN_ON(!mutex_is_locked(&pool->dev->struct_mutex));
n = fls(size >> PAGE_SHIFT) - 1;
if (n >= ARRAY_SIZE(pool->cache_list))
n = ARRAY_SIZE(pool->cache_list) - 1;
list = &pool->cache_list[n];
list_for_each_entry_safe(tmp, next, list, batch_pool_link) {
if (tmp->active)
break;
if (tmp->madv == __I915_MADV_PURGED) {
list_del(&tmp->batch_pool_link);
drm_gem_object_unreference(&tmp->base);
continue;
}
if (tmp->base.size >= size) {
obj = tmp;
break;
}
}
if (obj == NULL) {
int ret;
obj = i915_gem_object_create(pool->dev, size);
if (IS_ERR(obj))
return obj;
ret = i915_gem_object_get_pages(obj);
if (ret)
return ERR_PTR(ret);
obj->madv = I915_MADV_DONTNEED;
}
list_move_tail(&obj->batch_pool_link, list);
i915_gem_object_pin_pages(obj);
return obj;
}
