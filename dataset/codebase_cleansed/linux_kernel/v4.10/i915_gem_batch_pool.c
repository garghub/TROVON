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
__i915_gem_object_release_unless_active(obj);
INIT_LIST_HEAD(&pool->cache_list[n]);
}
}
struct drm_i915_gem_object *
i915_gem_batch_pool_get(struct i915_gem_batch_pool *pool,
size_t size)
{
struct drm_i915_gem_object *obj = NULL;
struct drm_i915_gem_object *tmp;
struct list_head *list;
int n, ret;
lockdep_assert_held(&pool->engine->i915->drm.struct_mutex);
n = fls(size >> PAGE_SHIFT) - 1;
if (n >= ARRAY_SIZE(pool->cache_list))
n = ARRAY_SIZE(pool->cache_list) - 1;
list = &pool->cache_list[n];
list_for_each_entry(tmp, list, batch_pool_link) {
if (i915_gem_object_is_active(tmp))
break;
GEM_BUG_ON(!reservation_object_test_signaled_rcu(tmp->resv,
true));
if (tmp->base.size >= size) {
ww_mutex_lock(&tmp->resv->lock, NULL);
reservation_object_add_excl_fence(tmp->resv, NULL);
ww_mutex_unlock(&tmp->resv->lock);
obj = tmp;
break;
}
}
if (obj == NULL) {
obj = i915_gem_object_create_internal(pool->engine->i915, size);
if (IS_ERR(obj))
return obj;
}
ret = i915_gem_object_pin_pages(obj);
if (ret)
return ERR_PTR(ret);
list_move_tail(&obj->batch_pool_link, list);
return obj;
}
