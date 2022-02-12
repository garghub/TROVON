static int lowlevel_buffer_allocate(struct drm_device *dev,
unsigned int flags, struct exynos_drm_gem_buf *buf)
{
int ret = 0;
enum dma_attr attr;
unsigned int nr_pages;
if (buf->dma_addr) {
DRM_DEBUG_KMS("already allocated.\n");
return 0;
}
init_dma_attrs(&buf->dma_attrs);
if (!(flags & EXYNOS_BO_NONCONTIG))
dma_set_attr(DMA_ATTR_FORCE_CONTIGUOUS, &buf->dma_attrs);
if (flags & EXYNOS_BO_WC || !(flags & EXYNOS_BO_CACHABLE))
attr = DMA_ATTR_WRITE_COMBINE;
else
attr = DMA_ATTR_NON_CONSISTENT;
dma_set_attr(attr, &buf->dma_attrs);
dma_set_attr(DMA_ATTR_NO_KERNEL_MAPPING, &buf->dma_attrs);
nr_pages = buf->size >> PAGE_SHIFT;
if (!is_drm_iommu_supported(dev)) {
dma_addr_t start_addr;
unsigned int i = 0;
buf->pages = drm_calloc_large(nr_pages, sizeof(struct page *));
if (!buf->pages) {
DRM_ERROR("failed to allocate pages.\n");
return -ENOMEM;
}
buf->kvaddr = dma_alloc_attrs(dev->dev, buf->size,
&buf->dma_addr, GFP_KERNEL,
&buf->dma_attrs);
if (!buf->kvaddr) {
DRM_ERROR("failed to allocate buffer.\n");
ret = -ENOMEM;
goto err_free;
}
start_addr = buf->dma_addr;
while (i < nr_pages) {
buf->pages[i] = phys_to_page(start_addr);
start_addr += PAGE_SIZE;
i++;
}
} else {
buf->pages = dma_alloc_attrs(dev->dev, buf->size,
&buf->dma_addr, GFP_KERNEL,
&buf->dma_attrs);
if (!buf->pages) {
DRM_ERROR("failed to allocate buffer.\n");
return -ENOMEM;
}
}
buf->sgt = drm_prime_pages_to_sg(buf->pages, nr_pages);
if (!buf->sgt) {
DRM_ERROR("failed to get sg table.\n");
ret = -ENOMEM;
goto err_free_attrs;
}
DRM_DEBUG_KMS("dma_addr(0x%lx), size(0x%lx)\n",
(unsigned long)buf->dma_addr,
buf->size);
return ret;
err_free_attrs:
dma_free_attrs(dev->dev, buf->size, buf->pages,
(dma_addr_t)buf->dma_addr, &buf->dma_attrs);
buf->dma_addr = (dma_addr_t)NULL;
err_free:
if (!is_drm_iommu_supported(dev))
drm_free_large(buf->pages);
return ret;
}
static void lowlevel_buffer_deallocate(struct drm_device *dev,
unsigned int flags, struct exynos_drm_gem_buf *buf)
{
if (!buf->dma_addr) {
DRM_DEBUG_KMS("dma_addr is invalid.\n");
return;
}
DRM_DEBUG_KMS("dma_addr(0x%lx), size(0x%lx)\n",
(unsigned long)buf->dma_addr,
buf->size);
sg_free_table(buf->sgt);
kfree(buf->sgt);
buf->sgt = NULL;
if (!is_drm_iommu_supported(dev)) {
dma_free_attrs(dev->dev, buf->size, buf->kvaddr,
(dma_addr_t)buf->dma_addr, &buf->dma_attrs);
drm_free_large(buf->pages);
} else
dma_free_attrs(dev->dev, buf->size, buf->pages,
(dma_addr_t)buf->dma_addr, &buf->dma_attrs);
buf->dma_addr = (dma_addr_t)NULL;
}
struct exynos_drm_gem_buf *exynos_drm_init_buf(struct drm_device *dev,
unsigned int size)
{
struct exynos_drm_gem_buf *buffer;
DRM_DEBUG_KMS("desired size = 0x%x\n", size);
buffer = kzalloc(sizeof(*buffer), GFP_KERNEL);
if (!buffer) {
DRM_ERROR("failed to allocate exynos_drm_gem_buf.\n");
return NULL;
}
buffer->size = size;
return buffer;
}
void exynos_drm_fini_buf(struct drm_device *dev,
struct exynos_drm_gem_buf *buffer)
{
if (!buffer) {
DRM_DEBUG_KMS("buffer is null.\n");
return;
}
kfree(buffer);
buffer = NULL;
}
int exynos_drm_alloc_buf(struct drm_device *dev,
struct exynos_drm_gem_buf *buf, unsigned int flags)
{
if (lowlevel_buffer_allocate(dev, flags, buf) < 0)
return -ENOMEM;
return 0;
}
void exynos_drm_free_buf(struct drm_device *dev,
unsigned int flags, struct exynos_drm_gem_buf *buffer)
{
lowlevel_buffer_deallocate(dev, flags, buffer);
}
