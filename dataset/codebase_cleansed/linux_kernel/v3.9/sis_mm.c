static int sis_fb_init(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_sis_private_t *dev_priv = dev->dev_private;
drm_sis_fb_t *fb = data;
mutex_lock(&dev->struct_mutex);
drm_mm_init(&dev_priv->vram_mm, 0, fb->size >> SIS_MM_ALIGN_SHIFT);
dev_priv->vram_initialized = 1;
dev_priv->vram_offset = fb->offset;
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG("offset = %lu, size = %lu\n", fb->offset, fb->size);
return 0;
}
static int sis_drm_alloc(struct drm_device *dev, struct drm_file *file,
void *data, int pool)
{
drm_sis_private_t *dev_priv = dev->dev_private;
drm_sis_mem_t *mem = data;
int retval = 0, user_key;
struct sis_memblock *item;
struct sis_file_private *file_priv = file->driver_priv;
unsigned long offset;
mutex_lock(&dev->struct_mutex);
if (0 == ((pool == 0) ? dev_priv->vram_initialized :
dev_priv->agp_initialized)) {
DRM_ERROR
("Attempt to allocate from uninitialized memory manager.\n");
mutex_unlock(&dev->struct_mutex);
return -EINVAL;
}
item = kzalloc(sizeof(*item), GFP_KERNEL);
if (!item) {
retval = -ENOMEM;
goto fail_alloc;
}
mem->size = (mem->size + SIS_MM_ALIGN_MASK) >> SIS_MM_ALIGN_SHIFT;
if (pool == AGP_TYPE) {
retval = drm_mm_insert_node(&dev_priv->agp_mm,
&item->mm_node,
mem->size, 0);
offset = item->mm_node.start;
} else {
#if defined(CONFIG_FB_SIS) || defined(CONFIG_FB_SIS_MODULE)
item->req.size = mem->size;
sis_malloc(&item->req);
if (item->req.size == 0)
retval = -ENOMEM;
offset = item->req.offset;
#else
retval = drm_mm_insert_node(&dev_priv->vram_mm,
&item->mm_node,
mem->size, 0);
offset = item->mm_node.start;
#endif
}
if (retval)
goto fail_alloc;
retval = idr_alloc(&dev_priv->object_idr, item, 1, 0, GFP_KERNEL);
if (retval < 0)
goto fail_idr;
user_key = retval;
list_add(&item->owner_list, &file_priv->obj_list);
mutex_unlock(&dev->struct_mutex);
mem->offset = ((pool == 0) ?
dev_priv->vram_offset : dev_priv->agp_offset) +
(offset << SIS_MM_ALIGN_SHIFT);
mem->free = user_key;
mem->size = mem->size << SIS_MM_ALIGN_SHIFT;
return 0;
fail_idr:
drm_mm_remove_node(&item->mm_node);
fail_alloc:
kfree(item);
mutex_unlock(&dev->struct_mutex);
mem->offset = 0;
mem->size = 0;
mem->free = 0;
DRM_DEBUG("alloc %d, size = %ld, offset = %ld\n", pool, mem->size,
mem->offset);
return retval;
}
static int sis_drm_free(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_sis_private_t *dev_priv = dev->dev_private;
drm_sis_mem_t *mem = data;
struct sis_memblock *obj;
mutex_lock(&dev->struct_mutex);
obj = idr_find(&dev_priv->object_idr, mem->free);
if (obj == NULL) {
mutex_unlock(&dev->struct_mutex);
return -EINVAL;
}
idr_remove(&dev_priv->object_idr, mem->free);
list_del(&obj->owner_list);
if (drm_mm_node_allocated(&obj->mm_node))
drm_mm_remove_node(&obj->mm_node);
#if defined(CONFIG_FB_SIS) || defined(CONFIG_FB_SIS_MODULE)
else
sis_free(obj->req.offset);
#endif
kfree(obj);
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG("free = 0x%lx\n", mem->free);
return 0;
}
static int sis_fb_alloc(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return sis_drm_alloc(dev, file_priv, data, VIDEO_TYPE);
}
static int sis_ioctl_agp_init(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_sis_private_t *dev_priv = dev->dev_private;
drm_sis_agp_t *agp = data;
dev_priv = dev->dev_private;
mutex_lock(&dev->struct_mutex);
drm_mm_init(&dev_priv->agp_mm, 0, agp->size >> SIS_MM_ALIGN_SHIFT);
dev_priv->agp_initialized = 1;
dev_priv->agp_offset = agp->offset;
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG("offset = %lu, size = %lu\n", agp->offset, agp->size);
return 0;
}
static int sis_ioctl_agp_alloc(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return sis_drm_alloc(dev, file_priv, data, AGP_TYPE);
}
static drm_local_map_t *sis_reg_init(struct drm_device *dev)
{
struct drm_map_list *entry;
drm_local_map_t *map;
list_for_each_entry(entry, &dev->maplist, head) {
map = entry->map;
if (!map)
continue;
if (map->type == _DRM_REGISTERS)
return map;
}
return NULL;
}
int sis_idle(struct drm_device *dev)
{
drm_sis_private_t *dev_priv = dev->dev_private;
uint32_t idle_reg;
unsigned long end;
int i;
if (dev_priv->idle_fault)
return 0;
if (dev_priv->mmio == NULL) {
dev_priv->mmio = sis_reg_init(dev);
if (dev_priv->mmio == NULL) {
DRM_ERROR("Could not find register map.\n");
return 0;
}
}
if (dev_priv->chipset != SIS_CHIP_315)
return 0;
end = jiffies + (DRM_HZ * 3);
for (i = 0; i < 4; ++i) {
do {
idle_reg = SIS_READ(0x85cc);
} while (!time_after_eq(jiffies, end) &&
((idle_reg & 0x80000000) != 0x80000000));
}
if (time_after_eq(jiffies, end)) {
DRM_ERROR("Graphics engine idle timeout. "
"Disabling idle check\n");
dev_priv->idle_fault = 1;
}
return 0;
}
void sis_lastclose(struct drm_device *dev)
{
drm_sis_private_t *dev_priv = dev->dev_private;
if (!dev_priv)
return;
mutex_lock(&dev->struct_mutex);
if (dev_priv->vram_initialized) {
drm_mm_takedown(&dev_priv->vram_mm);
dev_priv->vram_initialized = 0;
}
if (dev_priv->agp_initialized) {
drm_mm_takedown(&dev_priv->agp_mm);
dev_priv->agp_initialized = 0;
}
dev_priv->mmio = NULL;
mutex_unlock(&dev->struct_mutex);
}
void sis_reclaim_buffers_locked(struct drm_device *dev,
struct drm_file *file)
{
struct sis_file_private *file_priv = file->driver_priv;
struct sis_memblock *entry, *next;
if (!(file->minor->master && file->master->lock.hw_lock))
return;
drm_idlelock_take(&file->master->lock);
mutex_lock(&dev->struct_mutex);
if (list_empty(&file_priv->obj_list)) {
mutex_unlock(&dev->struct_mutex);
drm_idlelock_release(&file->master->lock);
return;
}
sis_idle(dev);
list_for_each_entry_safe(entry, next, &file_priv->obj_list,
owner_list) {
list_del(&entry->owner_list);
if (drm_mm_node_allocated(&entry->mm_node))
drm_mm_remove_node(&entry->mm_node);
#if defined(CONFIG_FB_SIS) || defined(CONFIG_FB_SIS_MODULE)
else
sis_free(entry->req.offset);
#endif
kfree(entry);
}
mutex_unlock(&dev->struct_mutex);
drm_idlelock_release(&file->master->lock);
return;
}
