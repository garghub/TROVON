static struct sg_table *omap_gem_map_dma_buf(
struct dma_buf_attachment *attachment,
enum dma_data_direction dir)
{
struct drm_gem_object *obj = attachment->dmabuf->priv;
struct sg_table *sg;
dma_addr_t paddr;
int ret;
sg = kzalloc(sizeof(*sg), GFP_KERNEL);
if (!sg)
return ERR_PTR(-ENOMEM);
ret = omap_gem_get_paddr(obj, &paddr, true);
if (ret)
goto out;
ret = sg_alloc_table(sg, 1, GFP_KERNEL);
if (ret)
goto out;
sg_init_table(sg->sgl, 1);
sg_dma_len(sg->sgl) = obj->size;
sg_set_page(sg->sgl, pfn_to_page(PFN_DOWN(paddr)), obj->size, 0);
sg_dma_address(sg->sgl) = paddr;
omap_gem_dma_sync(obj, dir);
return sg;
out:
kfree(sg);
return ERR_PTR(ret);
}
static void omap_gem_unmap_dma_buf(struct dma_buf_attachment *attachment,
struct sg_table *sg, enum dma_data_direction dir)
{
struct drm_gem_object *obj = attachment->dmabuf->priv;
omap_gem_put_paddr(obj);
sg_free_table(sg);
kfree(sg);
}
static void omap_gem_dmabuf_release(struct dma_buf *buffer)
{
struct drm_gem_object *obj = buffer->priv;
drm_gem_object_unreference_unlocked(obj);
}
static int omap_gem_dmabuf_begin_cpu_access(struct dma_buf *buffer,
size_t start, size_t len, enum dma_data_direction dir)
{
struct drm_gem_object *obj = buffer->priv;
struct page **pages;
if (omap_gem_flags(obj) & OMAP_BO_TILED) {
return -ENOMEM;
}
return omap_gem_get_pages(obj, &pages, true);
}
static void omap_gem_dmabuf_end_cpu_access(struct dma_buf *buffer,
size_t start, size_t len, enum dma_data_direction dir)
{
struct drm_gem_object *obj = buffer->priv;
omap_gem_put_pages(obj);
}
static void *omap_gem_dmabuf_kmap_atomic(struct dma_buf *buffer,
unsigned long page_num)
{
struct drm_gem_object *obj = buffer->priv;
struct page **pages;
omap_gem_get_pages(obj, &pages, false);
omap_gem_cpu_sync(obj, page_num);
return kmap_atomic(pages[page_num]);
}
static void omap_gem_dmabuf_kunmap_atomic(struct dma_buf *buffer,
unsigned long page_num, void *addr)
{
kunmap_atomic(addr);
}
static void *omap_gem_dmabuf_kmap(struct dma_buf *buffer,
unsigned long page_num)
{
struct drm_gem_object *obj = buffer->priv;
struct page **pages;
omap_gem_get_pages(obj, &pages, false);
omap_gem_cpu_sync(obj, page_num);
return kmap(pages[page_num]);
}
static void omap_gem_dmabuf_kunmap(struct dma_buf *buffer,
unsigned long page_num, void *addr)
{
struct drm_gem_object *obj = buffer->priv;
struct page **pages;
omap_gem_get_pages(obj, &pages, false);
kunmap(pages[page_num]);
}
static int omap_gem_dmabuf_mmap(struct dma_buf *buffer,
struct vm_area_struct *vma)
{
struct drm_gem_object *obj = buffer->priv;
struct drm_device *dev = obj->dev;
int ret = 0;
if (WARN_ON(!obj->filp))
return -EINVAL;
mutex_lock(&dev->struct_mutex);
ret = drm_gem_mmap_obj(obj, omap_gem_mmap_size(obj), vma);
mutex_unlock(&dev->struct_mutex);
if (ret < 0)
return ret;
return omap_gem_mmap_obj(obj, vma);
}
struct dma_buf *omap_gem_prime_export(struct drm_device *dev,
struct drm_gem_object *obj, int flags)
{
return dma_buf_export(obj, &omap_dmabuf_ops, obj->size, flags, NULL);
}
struct drm_gem_object *omap_gem_prime_import(struct drm_device *dev,
struct dma_buf *buffer)
{
struct drm_gem_object *obj;
if (buffer->ops == &omap_dmabuf_ops) {
obj = buffer->priv;
if (obj->dev == dev) {
drm_gem_object_reference(obj);
return obj;
}
}
return ERR_PTR(-EINVAL);
}
