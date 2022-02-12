static struct sg_table *i915_gem_map_dma_buf(struct dma_buf_attachment *attachment,
enum dma_data_direction dir)
{
struct drm_i915_gem_object *obj = attachment->dmabuf->priv;
struct sg_table *st;
struct scatterlist *src, *dst;
int ret, i;
ret = i915_mutex_lock_interruptible(obj->base.dev);
if (ret)
return ERR_PTR(ret);
ret = i915_gem_object_get_pages(obj);
if (ret) {
st = ERR_PTR(ret);
goto out;
}
st = kmalloc(sizeof(struct sg_table), GFP_KERNEL);
if (st == NULL) {
st = ERR_PTR(-ENOMEM);
goto out;
}
ret = sg_alloc_table(st, obj->pages->nents, GFP_KERNEL);
if (ret) {
kfree(st);
st = ERR_PTR(ret);
goto out;
}
src = obj->pages->sgl;
dst = st->sgl;
for (i = 0; i < obj->pages->nents; i++) {
sg_set_page(dst, sg_page(src), src->length, 0);
dst = sg_next(dst);
src = sg_next(src);
}
if (!dma_map_sg(attachment->dev, st->sgl, st->nents, dir)) {
sg_free_table(st);
kfree(st);
st = ERR_PTR(-ENOMEM);
goto out;
}
i915_gem_object_pin_pages(obj);
out:
mutex_unlock(&obj->base.dev->struct_mutex);
return st;
}
static void i915_gem_unmap_dma_buf(struct dma_buf_attachment *attachment,
struct sg_table *sg,
enum dma_data_direction dir)
{
struct drm_i915_gem_object *obj = attachment->dmabuf->priv;
mutex_lock(&obj->base.dev->struct_mutex);
dma_unmap_sg(attachment->dev, sg->sgl, sg->nents, dir);
sg_free_table(sg);
kfree(sg);
i915_gem_object_unpin_pages(obj);
mutex_unlock(&obj->base.dev->struct_mutex);
}
static void i915_gem_dmabuf_release(struct dma_buf *dma_buf)
{
struct drm_i915_gem_object *obj = dma_buf->priv;
if (obj->base.export_dma_buf == dma_buf) {
obj->base.export_dma_buf = NULL;
drm_gem_object_unreference_unlocked(&obj->base);
}
}
static void *i915_gem_dmabuf_vmap(struct dma_buf *dma_buf)
{
struct drm_i915_gem_object *obj = dma_buf->priv;
struct drm_device *dev = obj->base.dev;
struct sg_page_iter sg_iter;
struct page **pages;
int ret, i;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ERR_PTR(ret);
if (obj->dma_buf_vmapping) {
obj->vmapping_count++;
goto out_unlock;
}
ret = i915_gem_object_get_pages(obj);
if (ret)
goto error;
ret = -ENOMEM;
pages = drm_malloc_ab(obj->base.size >> PAGE_SHIFT, sizeof(*pages));
if (pages == NULL)
goto error;
i = 0;
for_each_sg_page(obj->pages->sgl, &sg_iter, obj->pages->nents, 0)
pages[i++] = sg_page_iter_page(&sg_iter);
obj->dma_buf_vmapping = vmap(pages, i, 0, PAGE_KERNEL);
drm_free_large(pages);
if (!obj->dma_buf_vmapping)
goto error;
obj->vmapping_count = 1;
i915_gem_object_pin_pages(obj);
out_unlock:
mutex_unlock(&dev->struct_mutex);
return obj->dma_buf_vmapping;
error:
mutex_unlock(&dev->struct_mutex);
return ERR_PTR(ret);
}
static void i915_gem_dmabuf_vunmap(struct dma_buf *dma_buf, void *vaddr)
{
struct drm_i915_gem_object *obj = dma_buf->priv;
struct drm_device *dev = obj->base.dev;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return;
if (--obj->vmapping_count == 0) {
vunmap(obj->dma_buf_vmapping);
obj->dma_buf_vmapping = NULL;
i915_gem_object_unpin_pages(obj);
}
mutex_unlock(&dev->struct_mutex);
}
static void *i915_gem_dmabuf_kmap_atomic(struct dma_buf *dma_buf, unsigned long page_num)
{
return NULL;
}
static void i915_gem_dmabuf_kunmap_atomic(struct dma_buf *dma_buf, unsigned long page_num, void *addr)
{
}
static void *i915_gem_dmabuf_kmap(struct dma_buf *dma_buf, unsigned long page_num)
{
return NULL;
}
static void i915_gem_dmabuf_kunmap(struct dma_buf *dma_buf, unsigned long page_num, void *addr)
{
}
static int i915_gem_dmabuf_mmap(struct dma_buf *dma_buf, struct vm_area_struct *vma)
{
return -EINVAL;
}
static int i915_gem_begin_cpu_access(struct dma_buf *dma_buf, size_t start, size_t length, enum dma_data_direction direction)
{
struct drm_i915_gem_object *obj = dma_buf->priv;
struct drm_device *dev = obj->base.dev;
int ret;
bool write = (direction == DMA_BIDIRECTIONAL || direction == DMA_TO_DEVICE);
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ret;
ret = i915_gem_object_set_to_cpu_domain(obj, write);
mutex_unlock(&dev->struct_mutex);
return ret;
}
struct dma_buf *i915_gem_prime_export(struct drm_device *dev,
struct drm_gem_object *gem_obj, int flags)
{
struct drm_i915_gem_object *obj = to_intel_bo(gem_obj);
return dma_buf_export(obj, &i915_dmabuf_ops, obj->base.size, flags);
}
static int i915_gem_object_get_pages_dmabuf(struct drm_i915_gem_object *obj)
{
struct sg_table *sg;
sg = dma_buf_map_attachment(obj->base.import_attach, DMA_BIDIRECTIONAL);
if (IS_ERR(sg))
return PTR_ERR(sg);
obj->pages = sg;
obj->has_dma_mapping = true;
return 0;
}
static void i915_gem_object_put_pages_dmabuf(struct drm_i915_gem_object *obj)
{
dma_buf_unmap_attachment(obj->base.import_attach,
obj->pages, DMA_BIDIRECTIONAL);
obj->has_dma_mapping = false;
}
struct drm_gem_object *i915_gem_prime_import(struct drm_device *dev,
struct dma_buf *dma_buf)
{
struct dma_buf_attachment *attach;
struct drm_i915_gem_object *obj;
int ret;
if (dma_buf->ops == &i915_dmabuf_ops) {
obj = dma_buf->priv;
if (obj->base.dev == dev) {
drm_gem_object_reference(&obj->base);
return &obj->base;
}
}
attach = dma_buf_attach(dma_buf, dev->dev);
if (IS_ERR(attach))
return ERR_CAST(attach);
get_dma_buf(dma_buf);
obj = i915_gem_object_alloc(dev);
if (obj == NULL) {
ret = -ENOMEM;
goto fail_detach;
}
ret = drm_gem_private_object_init(dev, &obj->base, dma_buf->size);
if (ret) {
i915_gem_object_free(obj);
goto fail_detach;
}
i915_gem_object_init(obj, &i915_gem_object_dmabuf_ops);
obj->base.import_attach = attach;
return &obj->base;
fail_detach:
dma_buf_detach(dma_buf, attach);
dma_buf_put(dma_buf);
return ERR_PTR(ret);
}
