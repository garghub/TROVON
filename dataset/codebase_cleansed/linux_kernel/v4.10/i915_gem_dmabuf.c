static struct drm_i915_gem_object *dma_buf_to_obj(struct dma_buf *buf)
{
return to_intel_bo(buf->priv);
}
static struct sg_table *i915_gem_map_dma_buf(struct dma_buf_attachment *attachment,
enum dma_data_direction dir)
{
struct drm_i915_gem_object *obj = dma_buf_to_obj(attachment->dmabuf);
struct sg_table *st;
struct scatterlist *src, *dst;
int ret, i;
ret = i915_gem_object_pin_pages(obj);
if (ret)
goto err;
st = kmalloc(sizeof(struct sg_table), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto err_unpin_pages;
}
ret = sg_alloc_table(st, obj->mm.pages->nents, GFP_KERNEL);
if (ret)
goto err_free;
src = obj->mm.pages->sgl;
dst = st->sgl;
for (i = 0; i < obj->mm.pages->nents; i++) {
sg_set_page(dst, sg_page(src), src->length, 0);
dst = sg_next(dst);
src = sg_next(src);
}
if (!dma_map_sg(attachment->dev, st->sgl, st->nents, dir)) {
ret = -ENOMEM;
goto err_free_sg;
}
return st;
err_free_sg:
sg_free_table(st);
err_free:
kfree(st);
err_unpin_pages:
i915_gem_object_unpin_pages(obj);
err:
return ERR_PTR(ret);
}
static void i915_gem_unmap_dma_buf(struct dma_buf_attachment *attachment,
struct sg_table *sg,
enum dma_data_direction dir)
{
struct drm_i915_gem_object *obj = dma_buf_to_obj(attachment->dmabuf);
dma_unmap_sg(attachment->dev, sg->sgl, sg->nents, dir);
sg_free_table(sg);
kfree(sg);
i915_gem_object_unpin_pages(obj);
}
static void *i915_gem_dmabuf_vmap(struct dma_buf *dma_buf)
{
struct drm_i915_gem_object *obj = dma_buf_to_obj(dma_buf);
return i915_gem_object_pin_map(obj, I915_MAP_WB);
}
static void i915_gem_dmabuf_vunmap(struct dma_buf *dma_buf, void *vaddr)
{
struct drm_i915_gem_object *obj = dma_buf_to_obj(dma_buf);
i915_gem_object_unpin_map(obj);
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
struct drm_i915_gem_object *obj = dma_buf_to_obj(dma_buf);
int ret;
if (obj->base.size < vma->vm_end - vma->vm_start)
return -EINVAL;
if (!obj->base.filp)
return -ENODEV;
ret = obj->base.filp->f_op->mmap(obj->base.filp, vma);
if (ret)
return ret;
fput(vma->vm_file);
vma->vm_file = get_file(obj->base.filp);
return 0;
}
static int i915_gem_begin_cpu_access(struct dma_buf *dma_buf, enum dma_data_direction direction)
{
struct drm_i915_gem_object *obj = dma_buf_to_obj(dma_buf);
struct drm_device *dev = obj->base.dev;
bool write = (direction == DMA_BIDIRECTIONAL || direction == DMA_TO_DEVICE);
int err;
err = i915_gem_object_pin_pages(obj);
if (err)
return err;
err = i915_mutex_lock_interruptible(dev);
if (err)
goto out;
err = i915_gem_object_set_to_cpu_domain(obj, write);
mutex_unlock(&dev->struct_mutex);
out:
i915_gem_object_unpin_pages(obj);
return err;
}
static int i915_gem_end_cpu_access(struct dma_buf *dma_buf, enum dma_data_direction direction)
{
struct drm_i915_gem_object *obj = dma_buf_to_obj(dma_buf);
struct drm_device *dev = obj->base.dev;
int err;
err = i915_gem_object_pin_pages(obj);
if (err)
return err;
err = i915_mutex_lock_interruptible(dev);
if (err)
goto out;
err = i915_gem_object_set_to_gtt_domain(obj, false);
mutex_unlock(&dev->struct_mutex);
out:
i915_gem_object_unpin_pages(obj);
return err;
}
struct dma_buf *i915_gem_prime_export(struct drm_device *dev,
struct drm_gem_object *gem_obj, int flags)
{
struct drm_i915_gem_object *obj = to_intel_bo(gem_obj);
DEFINE_DMA_BUF_EXPORT_INFO(exp_info);
exp_info.ops = &i915_dmabuf_ops;
exp_info.size = gem_obj->size;
exp_info.flags = flags;
exp_info.priv = gem_obj;
exp_info.resv = obj->resv;
if (obj->ops->dmabuf_export) {
int ret = obj->ops->dmabuf_export(obj);
if (ret)
return ERR_PTR(ret);
}
return drm_gem_dmabuf_export(dev, &exp_info);
}
static struct sg_table *
i915_gem_object_get_pages_dmabuf(struct drm_i915_gem_object *obj)
{
return dma_buf_map_attachment(obj->base.import_attach,
DMA_BIDIRECTIONAL);
}
static void i915_gem_object_put_pages_dmabuf(struct drm_i915_gem_object *obj,
struct sg_table *pages)
{
dma_buf_unmap_attachment(obj->base.import_attach, pages,
DMA_BIDIRECTIONAL);
}
struct drm_gem_object *i915_gem_prime_import(struct drm_device *dev,
struct dma_buf *dma_buf)
{
struct dma_buf_attachment *attach;
struct drm_i915_gem_object *obj;
int ret;
if (dma_buf->ops == &i915_dmabuf_ops) {
obj = dma_buf_to_obj(dma_buf);
if (obj->base.dev == dev) {
return &i915_gem_object_get(obj)->base;
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
drm_gem_private_object_init(dev, &obj->base, dma_buf->size);
i915_gem_object_init(obj, &i915_gem_object_dmabuf_ops);
obj->base.import_attach = attach;
obj->resv = dma_buf->resv;
obj->base.read_domains = I915_GEM_DOMAIN_GTT;
obj->base.write_domain = 0;
return &obj->base;
fail_detach:
dma_buf_detach(dma_buf, attach);
dma_buf_put(dma_buf);
return ERR_PTR(ret);
}
