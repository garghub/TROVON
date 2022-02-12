static int lowlevel_buffer_allocate(struct drm_device *dev,
struct exynos_drm_gem_buf *buffer)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
buffer->kvaddr = dma_alloc_writecombine(dev->dev, buffer->size,
&buffer->dma_addr, GFP_KERNEL);
if (!buffer->kvaddr) {
DRM_ERROR("failed to allocate buffer.\n");
return -ENOMEM;
}
DRM_DEBUG_KMS("vaddr(0x%lx), dma_addr(0x%lx), size(0x%lx)\n",
(unsigned long)buffer->kvaddr,
(unsigned long)buffer->dma_addr,
buffer->size);
return 0;
}
static void lowlevel_buffer_deallocate(struct drm_device *dev,
struct exynos_drm_gem_buf *buffer)
{
DRM_DEBUG_KMS("%s.\n", __FILE__);
if (buffer->dma_addr && buffer->size)
dma_free_writecombine(dev->dev, buffer->size, buffer->kvaddr,
(dma_addr_t)buffer->dma_addr);
else
DRM_DEBUG_KMS("buffer data are invalid.\n");
}
struct exynos_drm_gem_buf *exynos_drm_buf_create(struct drm_device *dev,
unsigned int size)
{
struct exynos_drm_gem_buf *buffer;
DRM_DEBUG_KMS("%s.\n", __FILE__);
DRM_DEBUG_KMS("desired size = 0x%x\n", size);
buffer = kzalloc(sizeof(*buffer), GFP_KERNEL);
if (!buffer) {
DRM_ERROR("failed to allocate exynos_drm_gem_buf.\n");
return ERR_PTR(-ENOMEM);
}
buffer->size = size;
if (lowlevel_buffer_allocate(dev, buffer) < 0) {
kfree(buffer);
buffer = NULL;
return ERR_PTR(-ENOMEM);
}
return buffer;
}
void exynos_drm_buf_destroy(struct drm_device *dev,
struct exynos_drm_gem_buf *buffer)
{
DRM_DEBUG_KMS("%s.\n", __FILE__);
if (!buffer) {
DRM_DEBUG_KMS("buffer is null.\n");
return;
}
lowlevel_buffer_deallocate(dev, buffer);
kfree(buffer);
buffer = NULL;
}
