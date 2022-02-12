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
static inline int is_dma_buf_file(struct file *file)
{
return file->f_op == &dma_buf_fops;
}
struct dma_buf *dma_buf_export(void *priv, struct dma_buf_ops *ops,
size_t size, int flags)
{
struct dma_buf *dmabuf;
struct file *file;
if (WARN_ON(!priv || !ops
|| !ops->map_dma_buf
|| !ops->unmap_dma_buf
|| !ops->release)) {
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
int dma_buf_fd(struct dma_buf *dmabuf)
{
int error, fd;
if (!dmabuf || !dmabuf->file)
return -EINVAL;
error = get_unused_fd();
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
if (WARN_ON(!dmabuf || !dev || !dmabuf->ops))
return ERR_PTR(-EINVAL);
attach = kzalloc(sizeof(struct dma_buf_attachment), GFP_KERNEL);
if (attach == NULL)
goto err_alloc;
mutex_lock(&dmabuf->lock);
attach->dev = dev;
attach->dmabuf = dmabuf;
if (dmabuf->ops->attach) {
ret = dmabuf->ops->attach(dmabuf, dev, attach);
if (ret)
goto err_attach;
}
list_add(&attach->node, &dmabuf->attachments);
mutex_unlock(&dmabuf->lock);
return attach;
err_alloc:
return ERR_PTR(-ENOMEM);
err_attach:
kfree(attach);
mutex_unlock(&dmabuf->lock);
return ERR_PTR(ret);
}
void dma_buf_detach(struct dma_buf *dmabuf, struct dma_buf_attachment *attach)
{
if (WARN_ON(!dmabuf || !attach || !dmabuf->ops))
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
if (WARN_ON(!attach || !attach->dmabuf || !attach->dmabuf->ops))
return ERR_PTR(-EINVAL);
mutex_lock(&attach->dmabuf->lock);
if (attach->dmabuf->ops->map_dma_buf)
sg_table = attach->dmabuf->ops->map_dma_buf(attach, direction);
mutex_unlock(&attach->dmabuf->lock);
return sg_table;
}
void dma_buf_unmap_attachment(struct dma_buf_attachment *attach,
struct sg_table *sg_table)
{
if (WARN_ON(!attach || !attach->dmabuf || !sg_table
|| !attach->dmabuf->ops))
return;
mutex_lock(&attach->dmabuf->lock);
if (attach->dmabuf->ops->unmap_dma_buf)
attach->dmabuf->ops->unmap_dma_buf(attach, sg_table);
mutex_unlock(&attach->dmabuf->lock);
}
