static int dma_buf_release(struct inode *inode, struct file *file)
{
struct dma_buf *dmabuf;
if (!is_dma_buf_file(file))
return -EINVAL;
dmabuf = file->private_data;
BUG_ON(dmabuf->vmapping_counter);
BUG_ON(dmabuf->cb_shared.active || dmabuf->cb_excl.active);
dmabuf->ops->release(dmabuf);
mutex_lock(&db_list.lock);
list_del(&dmabuf->list_node);
mutex_unlock(&db_list.lock);
if (dmabuf->resv == (struct reservation_object *)&dmabuf[1])
reservation_object_fini(dmabuf->resv);
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
static loff_t dma_buf_llseek(struct file *file, loff_t offset, int whence)
{
struct dma_buf *dmabuf;
loff_t base;
if (!is_dma_buf_file(file))
return -EBADF;
dmabuf = file->private_data;
if (whence == SEEK_END)
base = dmabuf->size;
else if (whence == SEEK_SET)
base = 0;
else
return -EINVAL;
if (offset != 0)
return -EINVAL;
return base + offset;
}
static void dma_buf_poll_cb(struct fence *fence, struct fence_cb *cb)
{
struct dma_buf_poll_cb_t *dcb = (struct dma_buf_poll_cb_t *)cb;
unsigned long flags;
spin_lock_irqsave(&dcb->poll->lock, flags);
wake_up_locked_poll(dcb->poll, dcb->active);
dcb->active = 0;
spin_unlock_irqrestore(&dcb->poll->lock, flags);
}
static unsigned int dma_buf_poll(struct file *file, poll_table *poll)
{
struct dma_buf *dmabuf;
struct reservation_object *resv;
struct reservation_object_list *fobj;
struct fence *fence_excl;
unsigned long events;
unsigned shared_count, seq;
dmabuf = file->private_data;
if (!dmabuf || !dmabuf->resv)
return POLLERR;
resv = dmabuf->resv;
poll_wait(file, &dmabuf->poll, poll);
events = poll_requested_events(poll) & (POLLIN | POLLOUT);
if (!events)
return 0;
retry:
seq = read_seqcount_begin(&resv->seq);
rcu_read_lock();
fobj = rcu_dereference(resv->fence);
if (fobj)
shared_count = fobj->shared_count;
else
shared_count = 0;
fence_excl = rcu_dereference(resv->fence_excl);
if (read_seqcount_retry(&resv->seq, seq)) {
rcu_read_unlock();
goto retry;
}
if (fence_excl && (!(events & POLLOUT) || shared_count == 0)) {
struct dma_buf_poll_cb_t *dcb = &dmabuf->cb_excl;
unsigned long pevents = POLLIN;
if (shared_count == 0)
pevents |= POLLOUT;
spin_lock_irq(&dmabuf->poll.lock);
if (dcb->active) {
dcb->active |= pevents;
events &= ~pevents;
} else
dcb->active = pevents;
spin_unlock_irq(&dmabuf->poll.lock);
if (events & pevents) {
if (!fence_get_rcu(fence_excl)) {
events &= ~pevents;
dma_buf_poll_cb(NULL, &dcb->cb);
} else if (!fence_add_callback(fence_excl, &dcb->cb,
dma_buf_poll_cb)) {
events &= ~pevents;
fence_put(fence_excl);
} else {
fence_put(fence_excl);
dma_buf_poll_cb(NULL, &dcb->cb);
}
}
}
if ((events & POLLOUT) && shared_count > 0) {
struct dma_buf_poll_cb_t *dcb = &dmabuf->cb_shared;
int i;
spin_lock_irq(&dmabuf->poll.lock);
if (dcb->active)
events &= ~POLLOUT;
else
dcb->active = POLLOUT;
spin_unlock_irq(&dmabuf->poll.lock);
if (!(events & POLLOUT))
goto out;
for (i = 0; i < shared_count; ++i) {
struct fence *fence = rcu_dereference(fobj->shared[i]);
if (!fence_get_rcu(fence)) {
events &= ~POLLOUT;
dma_buf_poll_cb(NULL, &dcb->cb);
break;
}
if (!fence_add_callback(fence, &dcb->cb,
dma_buf_poll_cb)) {
fence_put(fence);
events &= ~POLLOUT;
break;
}
fence_put(fence);
}
if (i == shared_count)
dma_buf_poll_cb(NULL, &dcb->cb);
}
out:
rcu_read_unlock();
return events;
}
static inline int is_dma_buf_file(struct file *file)
{
return file->f_op == &dma_buf_fops;
}
struct dma_buf *dma_buf_export(const struct dma_buf_export_info *exp_info)
{
struct dma_buf *dmabuf;
struct reservation_object *resv = exp_info->resv;
struct file *file;
size_t alloc_size = sizeof(struct dma_buf);
if (!exp_info->resv)
alloc_size += sizeof(struct reservation_object);
else
alloc_size += 1;
if (WARN_ON(!exp_info->priv
|| !exp_info->ops
|| !exp_info->ops->map_dma_buf
|| !exp_info->ops->unmap_dma_buf
|| !exp_info->ops->release
|| !exp_info->ops->kmap_atomic
|| !exp_info->ops->kmap
|| !exp_info->ops->mmap)) {
return ERR_PTR(-EINVAL);
}
dmabuf = kzalloc(alloc_size, GFP_KERNEL);
if (dmabuf == NULL)
return ERR_PTR(-ENOMEM);
dmabuf->priv = exp_info->priv;
dmabuf->ops = exp_info->ops;
dmabuf->size = exp_info->size;
dmabuf->exp_name = exp_info->exp_name;
init_waitqueue_head(&dmabuf->poll);
dmabuf->cb_excl.poll = dmabuf->cb_shared.poll = &dmabuf->poll;
dmabuf->cb_excl.active = dmabuf->cb_shared.active = 0;
if (!resv) {
resv = (struct reservation_object *)&dmabuf[1];
reservation_object_init(resv);
}
dmabuf->resv = resv;
file = anon_inode_getfile("dmabuf", &dma_buf_fops, dmabuf,
exp_info->flags);
if (IS_ERR(file)) {
kfree(dmabuf);
return ERR_CAST(file);
}
file->f_mode |= FMODE_LSEEK;
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
if (!sg_table)
sg_table = ERR_PTR(-ENOMEM);
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
if (WARN_ON_ONCE(IS_ERR(ptr)))
ptr = NULL;
if (!ptr)
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
seq_puts(s, "\nDma-buf Objects:\n");
seq_puts(s, "size\tflags\tmode\tcount\texp_name\n");
list_for_each_entry(buf_obj, &db_list.head, list_node) {
ret = mutex_lock_interruptible(&buf_obj->lock);
if (ret) {
seq_puts(s,
"\tERROR locking buffer object: skipping\n");
continue;
}
seq_printf(s, "%08zu\t%08x\t%08x\t%08ld\t%s\n",
buf_obj->size,
buf_obj->file->f_flags, buf_obj->file->f_mode,
file_count(buf_obj->file),
buf_obj->exp_name);
seq_puts(s, "\tAttached Devices:\n");
attach_count = 0;
list_for_each_entry(attach_obj, &buf_obj->attachments, node) {
seq_puts(s, "\t");
seq_printf(s, "%s\n", dev_name(attach_obj->dev));
attach_count++;
}
seq_printf(s, "Total %d devices attached\n\n",
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
return PTR_ERR_OR_ZERO(d);
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
