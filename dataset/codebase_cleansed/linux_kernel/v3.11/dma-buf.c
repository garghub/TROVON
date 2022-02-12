static int dma_buf_release(struct inode *inode, struct file *file)
{
struct dma_buf *dmabuf;
if (!is_dma_buf_file(file))
return -EINVAL;
dmabuf = file->private_data;
BUG_ON(dmabuf->vmapping_counter);
dmabuf->ops->release(dmabuf);
mutex_lock(&db_list.lock);
list_del(&dmabuf->list_node);
mutex_unlock(&db_list.lock);
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
struct dma_buf *dma_buf_export_named(void *priv, const struct dma_buf_ops *ops,
size_t size, int flags, const char *exp_name)
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
dmabuf->exp_name = exp_name;
file = anon_inode_getfile("dmabuf", &dma_buf_fops, dmabuf, flags);
dmabuf->file = file;
mutex_init(&dmabuf->lock);
INIT_LIST_HEAD(&dmabuf->attachments);
mutex_lock(&db_list.lock);
list_add(&dmabuf->list_node, &db_list.head);
mutex_unlock(&db_list.lock);
return dmabuf;
}
int dma_buf_fd(struct dma_buf *dmabuf, int flags)
{
int fd;
if (!dmabuf || !dmabuf->file)
return -EINVAL;
fd = get_unused_fd_flags(flags);
if (fd < 0)
return fd;
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
might_sleep();
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
struct file *oldfile;
int ret;
if (WARN_ON(!dmabuf || !vma))
return -EINVAL;
if (pgoff + ((vma->vm_end - vma->vm_start) >> PAGE_SHIFT) < pgoff)
return -EOVERFLOW;
if (pgoff + ((vma->vm_end - vma->vm_start) >> PAGE_SHIFT) >
dmabuf->size >> PAGE_SHIFT)
return -EINVAL;
get_file(dmabuf->file);
oldfile = vma->vm_file;
vma->vm_file = dmabuf->file;
vma->vm_pgoff = pgoff;
ret = dmabuf->ops->mmap(dmabuf, vma);
if (ret) {
vma->vm_file = oldfile;
fput(dmabuf->file);
} else {
if (oldfile)
fput(oldfile);
}
return ret;
}
void *dma_buf_vmap(struct dma_buf *dmabuf)
{
void *ptr;
if (WARN_ON(!dmabuf))
return NULL;
if (!dmabuf->ops->vmap)
return NULL;
mutex_lock(&dmabuf->lock);
if (dmabuf->vmapping_counter) {
dmabuf->vmapping_counter++;
BUG_ON(!dmabuf->vmap_ptr);
ptr = dmabuf->vmap_ptr;
goto out_unlock;
}
BUG_ON(dmabuf->vmap_ptr);
ptr = dmabuf->ops->vmap(dmabuf);
if (IS_ERR_OR_NULL(ptr))
goto out_unlock;
dmabuf->vmap_ptr = ptr;
dmabuf->vmapping_counter = 1;
out_unlock:
mutex_unlock(&dmabuf->lock);
return ptr;
}
void dma_buf_vunmap(struct dma_buf *dmabuf, void *vaddr)
{
if (WARN_ON(!dmabuf))
return;
BUG_ON(!dmabuf->vmap_ptr);
BUG_ON(dmabuf->vmapping_counter == 0);
BUG_ON(dmabuf->vmap_ptr != vaddr);
mutex_lock(&dmabuf->lock);
if (--dmabuf->vmapping_counter == 0) {
if (dmabuf->ops->vunmap)
dmabuf->ops->vunmap(dmabuf, vaddr);
dmabuf->vmap_ptr = NULL;
}
mutex_unlock(&dmabuf->lock);
}
static int dma_buf_describe(struct seq_file *s)
{
int ret;
struct dma_buf *buf_obj;
struct dma_buf_attachment *attach_obj;
int count = 0, attach_count;
size_t size = 0;
ret = mutex_lock_interruptible(&db_list.lock);
if (ret)
return ret;
seq_printf(s, "\nDma-buf Objects:\n");
seq_printf(s, "\texp_name\tsize\tflags\tmode\tcount\n");
list_for_each_entry(buf_obj, &db_list.head, list_node) {
ret = mutex_lock_interruptible(&buf_obj->lock);
if (ret) {
seq_printf(s,
"\tERROR locking buffer object: skipping\n");
continue;
}
seq_printf(s, "\t");
seq_printf(s, "\t%s\t%08zu\t%08x\t%08x\t%08ld\n",
buf_obj->exp_name, buf_obj->size,
buf_obj->file->f_flags, buf_obj->file->f_mode,
(long)(buf_obj->file->f_count.counter));
seq_printf(s, "\t\tAttached Devices:\n");
attach_count = 0;
list_for_each_entry(attach_obj, &buf_obj->attachments, node) {
seq_printf(s, "\t\t");
seq_printf(s, "%s\n", attach_obj->dev->init_name);
attach_count++;
}
seq_printf(s, "\n\t\tTotal %d devices attached\n",
attach_count);
count++;
size += buf_obj->size;
mutex_unlock(&buf_obj->lock);
}
seq_printf(s, "\nTotal %d objects, %zu bytes\n", count, size);
mutex_unlock(&db_list.lock);
return 0;
}
static int dma_buf_show(struct seq_file *s, void *unused)
{
void (*func)(struct seq_file *) = s->private;
func(s);
return 0;
}
static int dma_buf_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, dma_buf_show, inode->i_private);
}
static int dma_buf_init_debugfs(void)
{
int err = 0;
dma_buf_debugfs_dir = debugfs_create_dir("dma_buf", NULL);
if (IS_ERR(dma_buf_debugfs_dir)) {
err = PTR_ERR(dma_buf_debugfs_dir);
dma_buf_debugfs_dir = NULL;
return err;
}
err = dma_buf_debugfs_create_file("bufinfo", dma_buf_describe);
if (err)
pr_debug("dma_buf: debugfs: failed to create node bufinfo\n");
return err;
}
static void dma_buf_uninit_debugfs(void)
{
if (dma_buf_debugfs_dir)
debugfs_remove_recursive(dma_buf_debugfs_dir);
}
int dma_buf_debugfs_create_file(const char *name,
int (*write)(struct seq_file *))
{
struct dentry *d;
d = debugfs_create_file(name, S_IRUGO, dma_buf_debugfs_dir,
write, &dma_buf_debug_fops);
return PTR_RET(d);
}
static inline int dma_buf_init_debugfs(void)
{
return 0;
}
static inline void dma_buf_uninit_debugfs(void)
{
}
static int __init dma_buf_init(void)
{
mutex_init(&db_list.lock);
INIT_LIST_HEAD(&db_list.head);
dma_buf_init_debugfs();
return 0;
}
static void __exit dma_buf_deinit(void)
{
dma_buf_uninit_debugfs();
}
