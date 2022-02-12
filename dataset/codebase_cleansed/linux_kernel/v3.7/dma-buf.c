static int dma_buf_release(struct inode *inode, struct file *file)
{
struct dma_buf *dmabuf;
if (!is_dma_buf_file(file))
return -EINVAL;
dmabuf = file->private_data;
dmabuf->ops->release(dmabuf);
kfree(dmabuf);
return 0;
}
static int dma_buf_mmap_internal(struct file *file, struct vm_area_struct *vma)
{
struct dma_buf *dmabuf;
if (!is_dma_buf_file(file))
return -EINVAL;
dmabuf = file->private_data;
if (vma->vm_pgoff + ((vma->vm_end - vma->vm_start) >> PAGE_SHIFT) >
dmabuf->size >> PAGE_SHIFT)
return -EINVAL;
return dmabuf->ops->mmap(dmabuf, vma);
}
static inline int is_dma_buf_file(struct file *file)
{
return file->f_op == &dma_buf_fops;
}
struct dma_buf *dma_buf_export(void *priv, const struct dma_buf_ops *ops,
size_t size, int flags)
{
struct dma_buf *dmabuf;
struct file *file;
if (WARN_ON(!priv || !ops
|| !ops->map_dma_buf
|| !ops->unmap_dma_buf
|| !ops->release
|| !ops->kmap_atomic
|| !ops->kmap
|| !ops->mmap)) {
return ERR_PTR(-EINVAL);
}
dmabuf = kzalloc(sizeof(struct dma_buf), GFP_KERNEL);
if (dmabuf == NULL)
return ERR_PTR(-ENOMEM);
dmabuf->priv = priv;
dmabuf->ops = ops;
dmabuf->size = size;
file = anon_inode_getfile("dmabuf", &dma_buf_fops, dmabuf, flags);
dmabuf->file = file;
mutex_init(&dmabuf->lock);
INIT_LIST_HEAD(&dmabuf->attachments);
return dmabuf;
}
int dma_buf_fd(struct dma_buf *dmabuf, int flags)
{
int error, fd;
if (!dmabuf || !dmabuf->file)
return -EINVAL;
error = get_unused_fd_flags(flags);
if (error < 0)
return error;
fd = error;
fd_install(fd, dmabuf->file);
return fd;
}
struct dma_buf *dma_buf_get(int fd)
{
struct file *file;
file = fget(fd);
if (!file)
return ERR_PTR(-EBADF);
if (!is_dma_buf_file(file)) {
fput(file);
return ERR_PTR(-EINVAL);
}
return file->private_data;
}
void dma_buf_put(struct dma_buf *dmabuf)
{
if (WARN_ON(!dmabuf || !dmabuf->file))
return;
fput(dmabuf->file);
}
struct dma_buf_attachment *dma_buf_attach(struct dma_buf *dmabuf,
struct device *dev)
{
struct dma_buf_attachment *attach;
int ret;
if (WARN_ON(!dmabuf || !dev))
return ERR_PTR(-EINVAL);
attach = kzalloc(sizeof(struct dma_buf_attachment), GFP_KERNEL);
if (attach == NULL)
return ERR_PTR(-ENOMEM);
attach->dev = dev;
attach->dmabuf = dmabuf;
mutex_lock(&dmabuf->lock);
if (dmabuf->ops->attach) {
ret = dmabuf->ops->attach(dmabuf, dev, attach);
if (ret)
goto err_attach;
}
list_add(&attach->node, &dmabuf->attachments);
mutex_unlock(&dmabuf->lock);
return attach;
err_attach:
kfree(attach);
mutex_unlock(&dmabuf->lock);
return ERR_PTR(ret);
}
void dma_buf_detach(struct dma_buf *dmabuf, struct dma_buf_attachment *attach)
{
if (WARN_ON(!dmabuf || !attach))
return;
mutex_lock(&dmabuf->lock);
list_del(&attach->node);
if (dmabuf->ops->detach)
dmabuf->ops->detach(dmabuf, attach);
mutex_unlock(&dmabuf->lock);
kfree(attach);
}
struct sg_table *dma_buf_map_attachment(struct dma_buf_attachment *attach,
enum dma_data_direction direction)
{
struct sg_table *sg_table = ERR_PTR(-EINVAL);
might_sleep();
if (WARN_ON(!attach || !attach->dmabuf))
return ERR_PTR(-EINVAL);
sg_table = attach->dmabuf->ops->map_dma_buf(attach, direction);
return sg_table;
}
void dma_buf_unmap_attachment(struct dma_buf_attachment *attach,
struct sg_table *sg_table,
enum dma_data_direction direction)
{
if (WARN_ON(!attach || !attach->dmabuf || !sg_table))
return;
attach->dmabuf->ops->unmap_dma_buf(attach, sg_table,
direction);
}
int dma_buf_begin_cpu_access(struct dma_buf *dmabuf, size_t start, size_t len,
enum dma_data_direction direction)
{
int ret = 0;
if (WARN_ON(!dmabuf))
return -EINVAL;
if (dmabuf->ops->begin_cpu_access)
ret = dmabuf->ops->begin_cpu_access(dmabuf, start, len, direction);
return ret;
}
void dma_buf_end_cpu_access(struct dma_buf *dmabuf, size_t start, size_t len,
enum dma_data_direction direction)
{
WARN_ON(!dmabuf);
if (dmabuf->ops->end_cpu_access)
dmabuf->ops->end_cpu_access(dmabuf, start, len, direction);
}
void *dma_buf_kmap_atomic(struct dma_buf *dmabuf, unsigned long page_num)
{
WARN_ON(!dmabuf);
return dmabuf->ops->kmap_atomic(dmabuf, page_num);
}
void dma_buf_kunmap_atomic(struct dma_buf *dmabuf, unsigned long page_num,
void *vaddr)
{
WARN_ON(!dmabuf);
if (dmabuf->ops->kunmap_atomic)
dmabuf->ops->kunmap_atomic(dmabuf, page_num, vaddr);
}
void *dma_buf_kmap(struct dma_buf *dmabuf, unsigned long page_num)
{
WARN_ON(!dmabuf);
return dmabuf->ops->kmap(dmabuf, page_num);
}
void dma_buf_kunmap(struct dma_buf *dmabuf, unsigned long page_num,
void *vaddr)
{
WARN_ON(!dmabuf);
if (dmabuf->ops->kunmap)
dmabuf->ops->kunmap(dmabuf, page_num, vaddr);
}
int dma_buf_mmap(struct dma_buf *dmabuf, struct vm_area_struct *vma,
unsigned long pgoff)
{
if (WARN_ON(!dmabuf || !vma))
return -EINVAL;
if (pgoff + ((vma->vm_end - vma->vm_start) >> PAGE_SHIFT) < pgoff)
return -EOVERFLOW;
if (pgoff + ((vma->vm_end - vma->vm_start) >> PAGE_SHIFT) >
dmabuf->size >> PAGE_SHIFT)
return -EINVAL;
if (vma->vm_file)
fput(vma->vm_file);
vma->vm_file = get_file(dmabuf->file);
vma->vm_pgoff = pgoff;
return dmabuf->ops->mmap(dmabuf, vma);
}
void *dma_buf_vmap(struct dma_buf *dmabuf)
{
if (WARN_ON(!dmabuf))
return NULL;
if (dmabuf->ops->vmap)
return dmabuf->ops->vmap(dmabuf);
return NULL;
}
void dma_buf_vunmap(struct dma_buf *dmabuf, void *vaddr)
{
if (WARN_ON(!dmabuf))
return;
if (dmabuf->ops->vunmap)
dmabuf->ops->vunmap(dmabuf, vaddr);
}
