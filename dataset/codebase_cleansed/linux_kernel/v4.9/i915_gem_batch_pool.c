void i915_gem_batch_pool_init(struct intel_engine_cs *engine,
struct i915_gem_batch_pool *pool)
{
int n;
pool->engine = engine;
for (n = 0; n < ARRAY_SIZE(pool->cache_list); n++)
INIT_LIST_HEAD(&pool->cache_list[n]);
}
void i915_gem_batch_pool_fini(struct i915_gem_batch_pool *pool)
{
int n;
lockdep_assert_held(&pool->engine->i915->drm.struct_mutex);
for (n = 0; n < ARRAY_SIZE(pool->cache_list); n++) {
struct drm_i915_gem_object *obj, *next;
list_for_each_entry_safe(obj, next,
&pool->cache_list[n],
batch_pool_link)
i915_gem_object_put(obj);
INIT_LIST_HEAD(&pool->cache_list[n]);
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
lockdep_assert_held(&pool->engine->i915->drm.struct_mutex);
n = fls(size >> PAGE_SHIFT) - 1;
if (n >= ARRAY_SIZE(pool->cache_list))
n = ARRAY_SIZE(pool->cache_list) - 1;
list = &pool->cache_list[n];
list_for_each_entry_safe(tmp, next, list, batch_pool_link) {
if (!i915_gem_active_is_idle(&tmp->last_read[pool->engine->id],
&tmp->base.dev->struct_mutex))
break;
if (tmp->madv == __I915_MADV_PURGED) {
list_del(&tmp->batch_pool_link);
i915_gem_object_put(tmp);
continue;
}
if (tmp->base.size >= size) {
obj = tmp;
break;
}
}
if (obj == NULL) {
int ret;
obj = i915_gem_object_create(&pool->engine->i915->drm, size);
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
