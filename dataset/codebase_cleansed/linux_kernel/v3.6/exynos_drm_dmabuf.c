static struct sg_table *exynos_pages_to_sg(struct page **pages, int nr_pages,
unsigned int page_size)
{
struct sg_table *sgt = NULL;
struct scatterlist *sgl;
int i, ret;
sgt = kzalloc(sizeof(*sgt), GFP_KERNEL);
if (!sgt)
goto out;
ret = sg_alloc_table(sgt, nr_pages, GFP_KERNEL);
if (ret)
goto err_free_sgt;
if (page_size < PAGE_SIZE)
page_size = PAGE_SIZE;
for_each_sg(sgt->sgl, sgl, nr_pages, i)
sg_set_page(sgl, pages[i], page_size, 0);
return sgt;
err_free_sgt:
kfree(sgt);
sgt = NULL;
out:
return NULL;
}
static struct sg_table *
exynos_gem_map_dma_buf(struct dma_buf_attachment *attach,
enum dma_data_direction dir)
{
struct exynos_drm_gem_obj *gem_obj = attach->dmabuf->priv;
struct drm_device *dev = gem_obj->base.dev;
struct exynos_drm_gem_buf *buf;
struct sg_table *sgt = NULL;
unsigned int npages;
int nents;
DRM_DEBUG_PRIME("%s\n", __FILE__);
mutex_lock(&dev->struct_mutex);
buf = gem_obj->buffer;
if (!buf->pages) {
DRM_ERROR("pages is null.\n");
goto err_unlock;
}
npages = buf->size / buf->page_size;
sgt = exynos_pages_to_sg(buf->pages, npages, buf->page_size);
if (!sgt) {
DRM_DEBUG_PRIME("exynos_pages_to_sg returned NULL!\n");
goto err_unlock;
}
nents = dma_map_sg(attach->dev, sgt->sgl, sgt->nents, dir);
DRM_DEBUG_PRIME("npages = %d buffer size = 0x%lx page_size = 0x%lx\n",
npages, buf->size, buf->page_size);
err_unlock:
mutex_unlock(&dev->struct_mutex);
return sgt;
}
static void exynos_gem_unmap_dma_buf(struct dma_buf_attachment *attach,
struct sg_table *sgt,
enum dma_data_direction dir)
{
dma_unmap_sg(attach->dev, sgt->sgl, sgt->nents, dir);
sg_free_table(sgt);
kfree(sgt);
sgt = NULL;
}
static void exynos_dmabuf_release(struct dma_buf *dmabuf)
{
struct exynos_drm_gem_obj *exynos_gem_obj = dmabuf->priv;
DRM_DEBUG_PRIME("%s\n", __FILE__);
if (exynos_gem_obj->base.export_dma_buf == dmabuf) {
exynos_gem_obj->base.export_dma_buf = NULL;
drm_gem_object_unreference_unlocked(&exynos_gem_obj->base);
}
}
static void *exynos_gem_dmabuf_kmap_atomic(struct dma_buf *dma_buf,
unsigned long page_num)
{
return NULL;
}
static void exynos_gem_dmabuf_kunmap_atomic(struct dma_buf *dma_buf,
unsigned long page_num,
void *addr)
{
}
static void *exynos_gem_dmabuf_kmap(struct dma_buf *dma_buf,
unsigned long page_num)
{
return NULL;
}
static void exynos_gem_dmabuf_kunmap(struct dma_buf *dma_buf,
unsigned long page_num, void *addr)
{
}
static int exynos_gem_dmabuf_mmap(struct dma_buf *dma_buf,
struct vm_area_struct *vma)
{
return -ENOTTY;
}
struct dma_buf *exynos_dmabuf_prime_export(struct drm_device *drm_dev,
struct drm_gem_object *obj, int flags)
{
struct exynos_drm_gem_obj *exynos_gem_obj = to_exynos_gem_obj(obj);
return dma_buf_export(exynos_gem_obj, &exynos_dmabuf_ops,
exynos_gem_obj->base.size, 0600);
}
struct drm_gem_object *exynos_dmabuf_prime_import(struct drm_device *drm_dev,
struct dma_buf *dma_buf)
{
struct dma_buf_attachment *attach;
struct sg_table *sgt;
struct scatterlist *sgl;
struct exynos_drm_gem_obj *exynos_gem_obj;
struct exynos_drm_gem_buf *buffer;
struct page *page;
int ret;
DRM_DEBUG_PRIME("%s\n", __FILE__);
if (dma_buf->ops == &exynos_dmabuf_ops) {
struct drm_gem_object *obj;
exynos_gem_obj = dma_buf->priv;
obj = &exynos_gem_obj->base;
if (obj->dev == drm_dev) {
drm_gem_object_reference(obj);
return obj;
}
}
attach = dma_buf_attach(dma_buf, drm_dev->dev);
if (IS_ERR(attach))
return ERR_PTR(-EINVAL);
sgt = dma_buf_map_attachment(attach, DMA_BIDIRECTIONAL);
if (IS_ERR_OR_NULL(sgt)) {
ret = PTR_ERR(sgt);
goto err_buf_detach;
}
buffer = kzalloc(sizeof(*buffer), GFP_KERNEL);
if (!buffer) {
DRM_ERROR("failed to allocate exynos_drm_gem_buf.\n");
ret = -ENOMEM;
goto err_unmap_attach;
}
buffer->pages = kzalloc(sizeof(*page) * sgt->nents, GFP_KERNEL);
if (!buffer->pages) {
DRM_ERROR("failed to allocate pages.\n");
ret = -ENOMEM;
goto err_free_buffer;
}
exynos_gem_obj = exynos_drm_gem_init(drm_dev, dma_buf->size);
if (!exynos_gem_obj) {
ret = -ENOMEM;
goto err_free_pages;
}
sgl = sgt->sgl;
if (sgt->nents == 1) {
buffer->dma_addr = sg_dma_address(sgt->sgl);
buffer->size = sg_dma_len(sgt->sgl);
exynos_gem_obj->flags |= EXYNOS_BO_CONTIG;
} else {
unsigned int i = 0;
buffer->dma_addr = sg_dma_address(sgl);
while (i < sgt->nents) {
buffer->pages[i] = sg_page(sgl);
buffer->size += sg_dma_len(sgl);
sgl = sg_next(sgl);
i++;
}
exynos_gem_obj->flags |= EXYNOS_BO_NONCONTIG;
}
exynos_gem_obj->buffer = buffer;
buffer->sgt = sgt;
exynos_gem_obj->base.import_attach = attach;
DRM_DEBUG_PRIME("dma_addr = 0x%x, size = 0x%lx\n", buffer->dma_addr,
buffer->size);
return &exynos_gem_obj->base;
err_free_pages:
kfree(buffer->pages);
buffer->pages = NULL;
err_free_buffer:
kfree(buffer);
buffer = NULL;
err_unmap_attach:
dma_buf_unmap_attachment(attach, sgt, DMA_BIDIRECTIONAL);
err_buf_detach:
dma_buf_detach(dma_buf, attach);
return ERR_PTR(ret);
}
