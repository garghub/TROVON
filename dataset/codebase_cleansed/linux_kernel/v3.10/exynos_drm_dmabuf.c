static int exynos_gem_attach_dma_buf(struct dma_buf *dmabuf,
struct device *dev,
struct dma_buf_attachment *attach)
{
struct exynos_drm_dmabuf_attachment *exynos_attach;
exynos_attach = kzalloc(sizeof(*exynos_attach), GFP_KERNEL);
if (!exynos_attach)
return -ENOMEM;
exynos_attach->dir = DMA_NONE;
attach->priv = exynos_attach;
return 0;
}
static void exynos_gem_detach_dma_buf(struct dma_buf *dmabuf,
struct dma_buf_attachment *attach)
{
struct exynos_drm_dmabuf_attachment *exynos_attach = attach->priv;
struct sg_table *sgt;
if (!exynos_attach)
return;
sgt = &exynos_attach->sgt;
if (exynos_attach->dir != DMA_NONE)
dma_unmap_sg(attach->dev, sgt->sgl, sgt->nents,
exynos_attach->dir);
sg_free_table(sgt);
kfree(exynos_attach);
attach->priv = NULL;
}
static struct sg_table *
exynos_gem_map_dma_buf(struct dma_buf_attachment *attach,
enum dma_data_direction dir)
{
struct exynos_drm_dmabuf_attachment *exynos_attach = attach->priv;
struct exynos_drm_gem_obj *gem_obj = attach->dmabuf->priv;
struct drm_device *dev = gem_obj->base.dev;
struct exynos_drm_gem_buf *buf;
struct scatterlist *rd, *wr;
struct sg_table *sgt = NULL;
unsigned int i;
int nents, ret;
DRM_DEBUG_PRIME("%s\n", __FILE__);
if (exynos_attach->dir == dir && exynos_attach->is_mapped)
return &exynos_attach->sgt;
buf = gem_obj->buffer;
if (!buf) {
DRM_ERROR("buffer is null.\n");
return ERR_PTR(-ENOMEM);
}
sgt = &exynos_attach->sgt;
ret = sg_alloc_table(sgt, buf->sgt->orig_nents, GFP_KERNEL);
if (ret) {
DRM_ERROR("failed to alloc sgt.\n");
return ERR_PTR(-ENOMEM);
}
mutex_lock(&dev->struct_mutex);
rd = buf->sgt->sgl;
wr = sgt->sgl;
for (i = 0; i < sgt->orig_nents; ++i) {
sg_set_page(wr, sg_page(rd), rd->length, rd->offset);
rd = sg_next(rd);
wr = sg_next(wr);
}
if (dir != DMA_NONE) {
nents = dma_map_sg(attach->dev, sgt->sgl, sgt->orig_nents, dir);
if (!nents) {
DRM_ERROR("failed to map sgl with iommu.\n");
sg_free_table(sgt);
sgt = ERR_PTR(-EIO);
goto err_unlock;
}
}
exynos_attach->is_mapped = true;
exynos_attach->dir = dir;
attach->priv = exynos_attach;
DRM_DEBUG_PRIME("buffer size = 0x%lx\n", buf->size);
err_unlock:
mutex_unlock(&dev->struct_mutex);
return sgt;
}
static void exynos_gem_unmap_dma_buf(struct dma_buf_attachment *attach,
struct sg_table *sgt,
enum dma_data_direction dir)
{
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
exynos_gem_obj->base.size, flags);
}
struct drm_gem_object *exynos_dmabuf_prime_import(struct drm_device *drm_dev,
struct dma_buf *dma_buf)
{
struct dma_buf_attachment *attach;
struct sg_table *sgt;
struct scatterlist *sgl;
struct exynos_drm_gem_obj *exynos_gem_obj;
struct exynos_drm_gem_buf *buffer;
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
get_dma_buf(dma_buf);
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
exynos_gem_obj = exynos_drm_gem_init(drm_dev, dma_buf->size);
if (!exynos_gem_obj) {
ret = -ENOMEM;
goto err_free_buffer;
}
sgl = sgt->sgl;
buffer->size = dma_buf->size;
buffer->dma_addr = sg_dma_address(sgl);
if (sgt->nents == 1) {
exynos_gem_obj->flags |= EXYNOS_BO_CONTIG;
} else {
exynos_gem_obj->flags |= EXYNOS_BO_NONCONTIG;
}
exynos_gem_obj->buffer = buffer;
buffer->sgt = sgt;
exynos_gem_obj->base.import_attach = attach;
DRM_DEBUG_PRIME("dma_addr = 0x%x, size = 0x%lx\n", buffer->dma_addr,
buffer->size);
return &exynos_gem_obj->base;
err_free_buffer:
kfree(buffer);
buffer = NULL;
err_unmap_attach:
dma_buf_unmap_attachment(attach, sgt, DMA_BIDIRECTIONAL);
err_buf_detach:
dma_buf_detach(dma_buf, attach);
dma_buf_put(dma_buf);
return ERR_PTR(ret);
}
