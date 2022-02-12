static unsigned int cache_level_to_agp_type(struct drm_device *dev,
enum i915_cache_level cache_level)
{
switch (cache_level) {
case I915_CACHE_LLC_MLC:
if (INTEL_INFO(dev)->gen >= 6)
return AGP_USER_CACHED_MEMORY_LLC_MLC;
case I915_CACHE_LLC:
return AGP_USER_CACHED_MEMORY;
default:
case I915_CACHE_NONE:
return AGP_USER_MEMORY;
}
}
void i915_gem_restore_gtt_mappings(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_object *obj;
intel_gtt_clear_range(dev_priv->mm.gtt_start / PAGE_SIZE,
(dev_priv->mm.gtt_end - dev_priv->mm.gtt_start) / PAGE_SIZE);
list_for_each_entry(obj, &dev_priv->mm.gtt_list, gtt_list) {
unsigned int agp_type =
cache_level_to_agp_type(dev, obj->cache_level);
i915_gem_clflush_object(obj);
if (dev_priv->mm.gtt->needs_dmar) {
BUG_ON(!obj->sg_list);
intel_gtt_insert_sg_entries(obj->sg_list,
obj->num_sg,
obj->gtt_space->start >> PAGE_SHIFT,
agp_type);
} else
intel_gtt_insert_pages(obj->gtt_space->start
>> PAGE_SHIFT,
obj->base.size >> PAGE_SHIFT,
obj->pages,
agp_type);
}
intel_gtt_chipset_flush();
}
int i915_gem_gtt_bind_object(struct drm_i915_gem_object *obj)
{
struct drm_device *dev = obj->base.dev;
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned int agp_type = cache_level_to_agp_type(dev, obj->cache_level);
int ret;
if (dev_priv->mm.gtt->needs_dmar) {
ret = intel_gtt_map_memory(obj->pages,
obj->base.size >> PAGE_SHIFT,
&obj->sg_list,
&obj->num_sg);
if (ret != 0)
return ret;
intel_gtt_insert_sg_entries(obj->sg_list,
obj->num_sg,
obj->gtt_space->start >> PAGE_SHIFT,
agp_type);
} else
intel_gtt_insert_pages(obj->gtt_space->start >> PAGE_SHIFT,
obj->base.size >> PAGE_SHIFT,
obj->pages,
agp_type);
return 0;
}
void i915_gem_gtt_unbind_object(struct drm_i915_gem_object *obj)
{
intel_gtt_clear_range(obj->gtt_space->start >> PAGE_SHIFT,
obj->base.size >> PAGE_SHIFT);
if (obj->sg_list) {
intel_gtt_unmap_memory(obj->sg_list, obj->num_sg);
obj->sg_list = NULL;
}
}
