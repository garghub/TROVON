int via_agp_init(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_via_agp_t *agp = data;
drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
int ret;
mutex_lock(&dev->struct_mutex);
ret = drm_sman_set_range(&dev_priv->sman, VIA_MEM_AGP, 0,
agp->size >> VIA_MM_ALIGN_SHIFT);
if (ret) {
DRM_ERROR("AGP memory manager initialisation error\n");
mutex_unlock(&dev->struct_mutex);
return ret;
}
dev_priv->agp_initialized = 1;
dev_priv->agp_offset = agp->offset;
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG("offset = %u, size = %u\n", agp->offset, agp->size);
return 0;
}
int via_fb_init(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_via_fb_t *fb = data;
drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
int ret;
mutex_lock(&dev->struct_mutex);
ret = drm_sman_set_range(&dev_priv->sman, VIA_MEM_VIDEO, 0,
fb->size >> VIA_MM_ALIGN_SHIFT);
if (ret) {
DRM_ERROR("VRAM memory manager initialisation error\n");
mutex_unlock(&dev->struct_mutex);
return ret;
}
dev_priv->vram_initialized = 1;
dev_priv->vram_offset = fb->offset;
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG("offset = %u, size = %u\n", fb->offset, fb->size);
return 0;
}
int via_final_context(struct drm_device *dev, int context)
{
drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
via_release_futex(dev_priv, context);
if (dev->ctx_count == 1 && dev->dev_private) {
DRM_DEBUG("Last Context\n");
drm_irq_uninstall(dev);
via_cleanup_futex(dev_priv);
via_do_cleanup_map(dev);
}
return 1;
}
void via_lastclose(struct drm_device *dev)
{
drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
if (!dev_priv)
return;
mutex_lock(&dev->struct_mutex);
drm_sman_cleanup(&dev_priv->sman);
dev_priv->vram_initialized = 0;
dev_priv->agp_initialized = 0;
mutex_unlock(&dev->struct_mutex);
}
int via_mem_alloc(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_via_mem_t *mem = data;
int retval = 0;
struct drm_memblock_item *item;
drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
unsigned long tmpSize;
if (mem->type > VIA_MEM_AGP) {
DRM_ERROR("Unknown memory type allocation\n");
return -EINVAL;
}
mutex_lock(&dev->struct_mutex);
if (0 == ((mem->type == VIA_MEM_VIDEO) ? dev_priv->vram_initialized :
dev_priv->agp_initialized)) {
DRM_ERROR
("Attempt to allocate from uninitialized memory manager.\n");
mutex_unlock(&dev->struct_mutex);
return -EINVAL;
}
tmpSize = (mem->size + VIA_MM_ALIGN_MASK) >> VIA_MM_ALIGN_SHIFT;
item = drm_sman_alloc(&dev_priv->sman, mem->type, tmpSize, 0,
(unsigned long)file_priv);
mutex_unlock(&dev->struct_mutex);
if (item) {
mem->offset = ((mem->type == VIA_MEM_VIDEO) ?
dev_priv->vram_offset : dev_priv->agp_offset) +
(item->mm->
offset(item->mm, item->mm_info) << VIA_MM_ALIGN_SHIFT);
mem->index = item->user_hash.key;
} else {
mem->offset = 0;
mem->size = 0;
mem->index = 0;
DRM_DEBUG("Video memory allocation failed\n");
retval = -ENOMEM;
}
return retval;
}
int via_mem_free(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_via_private_t *dev_priv = dev->dev_private;
drm_via_mem_t *mem = data;
int ret;
mutex_lock(&dev->struct_mutex);
ret = drm_sman_free_key(&dev_priv->sman, mem->index);
mutex_unlock(&dev->struct_mutex);
DRM_DEBUG("free = 0x%lx\n", mem->index);
return ret;
}
void via_reclaim_buffers_locked(struct drm_device *dev,
struct drm_file *file_priv)
{
drm_via_private_t *dev_priv = dev->dev_private;
mutex_lock(&dev->struct_mutex);
if (drm_sman_owner_clean(&dev_priv->sman, (unsigned long)file_priv)) {
mutex_unlock(&dev->struct_mutex);
return;
}
if (dev->driver->dma_quiescent)
dev->driver->dma_quiescent(dev);
drm_sman_owner_cleanup(&dev_priv->sman, (unsigned long)file_priv);
mutex_unlock(&dev->struct_mutex);
return;
}
