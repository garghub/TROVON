static struct sg_table *i915_gem_map_dma_buf(struct dma_buf_attachment *attachment,
enum dma_data_direction dir)
{
struct drm_i915_gem_object *obj = attachment->dmabuf->priv;
struct drm_device *dev = obj->base.dev;
int npages = obj->base.size / PAGE_SIZE;
struct sg_table *sg = NULL;
int ret;
int nents;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ERR_PTR(ret);
if (!obj->pages) {
ret = i915_gem_object_get_pages_gtt(obj, __GFP_NORETRY | __GFP_NOWARN);
if (ret)
goto out;
}
sg = drm_prime_pages_to_sg(obj->pages, npages);
nents = dma_map_sg(attachment->dev, sg->sgl, sg->nents, dir);
out:
mutex_unlock(&dev->struct_mutex);
return sg;
}
static void i915_gem_unmap_dma_buf(struct dma_buf_attachment *attachment,
struct sg_table *sg, enum dma_data_direction dir)
{
dma_unmap_sg(attachment->dev, sg->sgl, sg->nents, dir);
sg_free_table(sg);
kfree(sg);
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
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return ERR_PTR(ret);
if (obj->dma_buf_vmapping) {
obj->vmapping_count++;
goto out_unlock;
}
if (!obj->pages) {
ret = i915_gem_object_get_pages_gtt(obj, __GFP_NORETRY | __GFP_NOWARN);
if (ret) {
mutex_unlock(&dev->struct_mutex);
return ERR_PTR(ret);
}
}
obj->dma_buf_vmapping = vmap(obj->pages, obj->base.size / PAGE_SIZE, 0, PAGE_KERNEL);
if (!obj->dma_buf_vmapping) {
DRM_ERROR("failed to vmap object\n");
goto out_unlock;
}
obj->vmapping_count = 1;
out_unlock:
mutex_unlock(&dev->struct_mutex);
return obj->dma_buf_vmapping;
}
static void i915_gem_dmabuf_vunmap(struct dma_buf *dma_buf, void *vaddr)
{
struct drm_i915_gem_object *obj = dma_buf->priv;
struct drm_device *dev = obj->base.dev;
int ret;
ret = i915_mutex_lock_interruptible(dev);
if (ret)
return;
--obj->vmapping_count;
if (obj->vmapping_count == 0) {
vunmap(obj->dma_buf_vmapping);
obj->dma_buf_vmapping = NULL;
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
struct dma_buf *i915_gem_prime_export(struct drm_device *dev,
struct drm_gem_object *gem_obj, int flags)
{
struct drm_i915_gem_object *obj = to_intel_bo(gem_obj);
return dma_buf_export(obj, &i915_dmabuf_ops,
obj->base.size, 0600);
}
struct drm_gem_object *i915_gem_prime_import(struct drm_device *dev,
struct dma_buf *dma_buf)
{
struct dma_buf_attachment *attach;
struct sg_table *sg;
struct drm_i915_gem_object *obj;
int npages;
int size;
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
sg = dma_buf_map_attachment(attach, DMA_BIDIRECTIONAL);
if (IS_ERR(sg)) {
ret = PTR_ERR(sg);
goto fail_detach;
}
size = dma_buf->size;
npages = size / PAGE_SIZE;
obj = kzalloc(sizeof(*obj), GFP_KERNEL);
if (obj == NULL) {
ret = -ENOMEM;
goto fail_unmap;
}
ret = drm_gem_private_object_init(dev, &obj->base, size);
if (ret) {
kfree(obj);
goto fail_unmap;
}
obj->sg_table = sg;
obj->base.import_attach = attach;
return &obj->base;
fail_unmap:
dma_buf_unmap_attachment(attach, sg, DMA_BIDIRECTIONAL);
fail_detach:
dma_buf_detach(dma_buf, attach);
return ERR_PTR(ret);
}
