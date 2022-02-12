static void tee_shm_release(struct tee_shm *shm)
{
struct tee_device *teedev = shm->teedev;
struct tee_shm_pool_mgr *poolm;
mutex_lock(&teedev->mutex);
idr_remove(&teedev->idr, shm->id);
if (shm->ctx)
list_del(&shm->link);
mutex_unlock(&teedev->mutex);
if (shm->flags & TEE_SHM_DMA_BUF)
poolm = &teedev->pool->dma_buf_mgr;
else
poolm = &teedev->pool->private_mgr;
poolm->ops->free(poolm, shm);
kfree(shm);
tee_device_put(teedev);
}
static struct sg_table *tee_shm_op_map_dma_buf(struct dma_buf_attachment
*attach, enum dma_data_direction dir)
{
return NULL;
}
static void tee_shm_op_unmap_dma_buf(struct dma_buf_attachment *attach,
struct sg_table *table,
enum dma_data_direction dir)
{
}
static void tee_shm_op_release(struct dma_buf *dmabuf)
{
struct tee_shm *shm = dmabuf->priv;
tee_shm_release(shm);
}
static void *tee_shm_op_map_atomic(struct dma_buf *dmabuf, unsigned long pgnum)
{
return NULL;
}
static void *tee_shm_op_map(struct dma_buf *dmabuf, unsigned long pgnum)
{
return NULL;
}
static int tee_shm_op_mmap(struct dma_buf *dmabuf, struct vm_area_struct *vma)
{
struct tee_shm *shm = dmabuf->priv;
size_t size = vma->vm_end - vma->vm_start;
return remap_pfn_range(vma, vma->vm_start, shm->paddr >> PAGE_SHIFT,
size, vma->vm_page_prot);
}
struct tee_shm *tee_shm_alloc(struct tee_context *ctx, size_t size, u32 flags)
{
struct tee_device *teedev = ctx->teedev;
struct tee_shm_pool_mgr *poolm = NULL;
struct tee_shm *shm;
void *ret;
int rc;
if (!(flags & TEE_SHM_MAPPED)) {
dev_err(teedev->dev.parent,
"only mapped allocations supported\n");
return ERR_PTR(-EINVAL);
}
if ((flags & ~(TEE_SHM_MAPPED | TEE_SHM_DMA_BUF))) {
dev_err(teedev->dev.parent, "invalid shm flags 0x%x", flags);
return ERR_PTR(-EINVAL);
}
if (!tee_device_get(teedev))
return ERR_PTR(-EINVAL);
if (!teedev->pool) {
ret = ERR_PTR(-EINVAL);
goto err_dev_put;
}
shm = kzalloc(sizeof(*shm), GFP_KERNEL);
if (!shm) {
ret = ERR_PTR(-ENOMEM);
goto err_dev_put;
}
shm->flags = flags;
shm->teedev = teedev;
shm->ctx = ctx;
if (flags & TEE_SHM_DMA_BUF)
poolm = &teedev->pool->dma_buf_mgr;
else
poolm = &teedev->pool->private_mgr;
rc = poolm->ops->alloc(poolm, shm, size);
if (rc) {
ret = ERR_PTR(rc);
goto err_kfree;
}
mutex_lock(&teedev->mutex);
shm->id = idr_alloc(&teedev->idr, shm, 1, 0, GFP_KERNEL);
mutex_unlock(&teedev->mutex);
if (shm->id < 0) {
ret = ERR_PTR(shm->id);
goto err_pool_free;
}
if (flags & TEE_SHM_DMA_BUF) {
DEFINE_DMA_BUF_EXPORT_INFO(exp_info);
exp_info.ops = &tee_shm_dma_buf_ops;
exp_info.size = shm->size;
exp_info.flags = O_RDWR;
exp_info.priv = shm;
shm->dmabuf = dma_buf_export(&exp_info);
if (IS_ERR(shm->dmabuf)) {
ret = ERR_CAST(shm->dmabuf);
goto err_rem;
}
}
mutex_lock(&teedev->mutex);
list_add_tail(&shm->link, &ctx->list_shm);
mutex_unlock(&teedev->mutex);
return shm;
err_rem:
mutex_lock(&teedev->mutex);
idr_remove(&teedev->idr, shm->id);
mutex_unlock(&teedev->mutex);
err_pool_free:
poolm->ops->free(poolm, shm);
err_kfree:
kfree(shm);
err_dev_put:
tee_device_put(teedev);
return ret;
}
int tee_shm_get_fd(struct tee_shm *shm)
{
u32 req_flags = TEE_SHM_MAPPED | TEE_SHM_DMA_BUF;
int fd;
if ((shm->flags & req_flags) != req_flags)
return -EINVAL;
fd = dma_buf_fd(shm->dmabuf, O_CLOEXEC);
if (fd >= 0)
get_dma_buf(shm->dmabuf);
return fd;
}
void tee_shm_free(struct tee_shm *shm)
{
if (shm->flags & TEE_SHM_DMA_BUF)
dma_buf_put(shm->dmabuf);
else
tee_shm_release(shm);
}
int tee_shm_va2pa(struct tee_shm *shm, void *va, phys_addr_t *pa)
{
if ((char *)va < (char *)shm->kaddr)
return -EINVAL;
if ((char *)va >= ((char *)shm->kaddr + shm->size))
return -EINVAL;
return tee_shm_get_pa(
shm, (unsigned long)va - (unsigned long)shm->kaddr, pa);
}
int tee_shm_pa2va(struct tee_shm *shm, phys_addr_t pa, void **va)
{
if (pa < shm->paddr)
return -EINVAL;
if (pa >= (shm->paddr + shm->size))
return -EINVAL;
if (va) {
void *v = tee_shm_get_va(shm, pa - shm->paddr);
if (IS_ERR(v))
return PTR_ERR(v);
*va = v;
}
return 0;
}
void *tee_shm_get_va(struct tee_shm *shm, size_t offs)
{
if (offs >= shm->size)
return ERR_PTR(-EINVAL);
return (char *)shm->kaddr + offs;
}
int tee_shm_get_pa(struct tee_shm *shm, size_t offs, phys_addr_t *pa)
{
if (offs >= shm->size)
return -EINVAL;
if (pa)
*pa = shm->paddr + offs;
return 0;
}
struct tee_shm *tee_shm_get_from_id(struct tee_context *ctx, int id)
{
struct tee_device *teedev;
struct tee_shm *shm;
if (!ctx)
return ERR_PTR(-EINVAL);
teedev = ctx->teedev;
mutex_lock(&teedev->mutex);
shm = idr_find(&teedev->idr, id);
if (!shm || shm->ctx != ctx)
shm = ERR_PTR(-EINVAL);
else if (shm->flags & TEE_SHM_DMA_BUF)
get_dma_buf(shm->dmabuf);
mutex_unlock(&teedev->mutex);
return shm;
}
int tee_shm_get_id(struct tee_shm *shm)
{
return shm->id;
}
void tee_shm_put(struct tee_shm *shm)
{
if (shm->flags & TEE_SHM_DMA_BUF)
dma_buf_put(shm->dmabuf);
}
