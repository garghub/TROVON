void i915_gem_object_set_cache_coherency(struct drm_i915_gem_object *obj,
unsigned int cache_level)
{
obj->cache_level = cache_level;
if (cache_level != I915_CACHE_NONE)
obj->cache_coherent = (I915_BO_CACHE_COHERENT_FOR_READ |
I915_BO_CACHE_COHERENT_FOR_WRITE);
else if (HAS_LLC(to_i915(obj->base.dev)))
obj->cache_coherent = I915_BO_CACHE_COHERENT_FOR_READ;
else
obj->cache_coherent = 0;
obj->cache_dirty =
!(obj->cache_coherent & I915_BO_CACHE_COHERENT_FOR_WRITE);
}
