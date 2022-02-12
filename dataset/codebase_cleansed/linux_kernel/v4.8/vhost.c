static void vhost_disable_cross_endian(struct vhost_virtqueue *vq)
{
vq->user_be = !virtio_legacy_is_little_endian();
}
static void vhost_enable_cross_endian_big(struct vhost_virtqueue *vq)
{
vq->user_be = true;
}
static void vhost_enable_cross_endian_little(struct vhost_virtqueue *vq)
{
vq->user_be = false;
}
static long vhost_set_vring_endian(struct vhost_virtqueue *vq, int __user *argp)
{
struct vhost_vring_state s;
if (vq->private_data)
return -EBUSY;
if (copy_from_user(&s, argp, sizeof(s)))
return -EFAULT;
if (s.num != VHOST_VRING_LITTLE_ENDIAN &&
s.num != VHOST_VRING_BIG_ENDIAN)
return -EINVAL;
if (s.num == VHOST_VRING_BIG_ENDIAN)
vhost_enable_cross_endian_big(vq);
else
vhost_enable_cross_endian_little(vq);
return 0;
}
static long vhost_get_vring_endian(struct vhost_virtqueue *vq, u32 idx,
int __user *argp)
{
struct vhost_vring_state s = {
.index = idx,
.num = vq->user_be
};
if (copy_to_user(argp, &s, sizeof(s)))
return -EFAULT;
return 0;
}
static void vhost_init_is_le(struct vhost_virtqueue *vq)
{
vq->is_le = vhost_has_feature(vq, VIRTIO_F_VERSION_1) || !vq->user_be;
}
static void vhost_disable_cross_endian(struct vhost_virtqueue *vq)
{
}
static long vhost_set_vring_endian(struct vhost_virtqueue *vq, int __user *argp)
{
return -ENOIOCTLCMD;
}
static long vhost_get_vring_endian(struct vhost_virtqueue *vq, u32 idx,
int __user *argp)
{
return -ENOIOCTLCMD;
}
static void vhost_init_is_le(struct vhost_virtqueue *vq)
{
if (vhost_has_feature(vq, VIRTIO_F_VERSION_1))
vq->is_le = true;
}
static void vhost_reset_is_le(struct vhost_virtqueue *vq)
{
vq->is_le = virtio_legacy_is_little_endian();
}
static void vhost_flush_work(struct vhost_work *work)
{
struct vhost_flush_struct *s;
s = container_of(work, struct vhost_flush_struct, work);
complete(&s->wait_event);
}
static void vhost_poll_func(struct file *file, wait_queue_head_t *wqh,
poll_table *pt)
{
struct vhost_poll *poll;
poll = container_of(pt, struct vhost_poll, table);
poll->wqh = wqh;
add_wait_queue(wqh, &poll->wait);
}
static int vhost_poll_wakeup(wait_queue_t *wait, unsigned mode, int sync,
void *key)
{
struct vhost_poll *poll = container_of(wait, struct vhost_poll, wait);
if (!((unsigned long)key & poll->mask))
return 0;
vhost_poll_queue(poll);
return 0;
}
void vhost_work_init(struct vhost_work *work, vhost_work_fn_t fn)
{
clear_bit(VHOST_WORK_QUEUED, &work->flags);
work->fn = fn;
init_waitqueue_head(&work->done);
}
void vhost_poll_init(struct vhost_poll *poll, vhost_work_fn_t fn,
unsigned long mask, struct vhost_dev *dev)
{
init_waitqueue_func_entry(&poll->wait, vhost_poll_wakeup);
init_poll_funcptr(&poll->table, vhost_poll_func);
poll->mask = mask;
poll->dev = dev;
poll->wqh = NULL;
vhost_work_init(&poll->work, fn);
}
int vhost_poll_start(struct vhost_poll *poll, struct file *file)
{
unsigned long mask;
int ret = 0;
if (poll->wqh)
return 0;
mask = file->f_op->poll(file, &poll->table);
if (mask)
vhost_poll_wakeup(&poll->wait, 0, 0, (void *)mask);
if (mask & POLLERR) {
if (poll->wqh)
remove_wait_queue(poll->wqh, &poll->wait);
ret = -EINVAL;
}
return ret;
}
void vhost_poll_stop(struct vhost_poll *poll)
{
if (poll->wqh) {
remove_wait_queue(poll->wqh, &poll->wait);
poll->wqh = NULL;
}
}
void vhost_work_flush(struct vhost_dev *dev, struct vhost_work *work)
{
struct vhost_flush_struct flush;
if (dev->worker) {
init_completion(&flush.wait_event);
vhost_work_init(&flush.work, vhost_flush_work);
vhost_work_queue(dev, &flush.work);
wait_for_completion(&flush.wait_event);
}
}
void vhost_poll_flush(struct vhost_poll *poll)
{
vhost_work_flush(poll->dev, &poll->work);
}
void vhost_work_queue(struct vhost_dev *dev, struct vhost_work *work)
{
if (!dev->worker)
return;
if (!test_and_set_bit(VHOST_WORK_QUEUED, &work->flags)) {
smp_mb();
llist_add(&work->node, &dev->work_list);
wake_up_process(dev->worker);
}
}
bool vhost_has_work(struct vhost_dev *dev)
{
return !llist_empty(&dev->work_list);
}
void vhost_poll_queue(struct vhost_poll *poll)
{
vhost_work_queue(poll->dev, &poll->work);
}
static void vhost_vq_reset(struct vhost_dev *dev,
struct vhost_virtqueue *vq)
{
vq->num = 1;
vq->desc = NULL;
vq->avail = NULL;
vq->used = NULL;
vq->last_avail_idx = 0;
vq->avail_idx = 0;
vq->last_used_idx = 0;
vq->signalled_used = 0;
vq->signalled_used_valid = false;
vq->used_flags = 0;
vq->log_used = false;
vq->log_addr = -1ull;
vq->private_data = NULL;
vq->acked_features = 0;
vq->log_base = NULL;
vq->error_ctx = NULL;
vq->error = NULL;
vq->kick = NULL;
vq->call_ctx = NULL;
vq->call = NULL;
vq->log_ctx = NULL;
vhost_reset_is_le(vq);
vhost_disable_cross_endian(vq);
vq->busyloop_timeout = 0;
vq->umem = NULL;
vq->iotlb = NULL;
}
static int vhost_worker(void *data)
{
struct vhost_dev *dev = data;
struct vhost_work *work, *work_next;
struct llist_node *node;
mm_segment_t oldfs = get_fs();
set_fs(USER_DS);
use_mm(dev->mm);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop()) {
__set_current_state(TASK_RUNNING);
break;
}
node = llist_del_all(&dev->work_list);
if (!node)
schedule();
node = llist_reverse_order(node);
smp_wmb();
llist_for_each_entry_safe(work, work_next, node, node) {
clear_bit(VHOST_WORK_QUEUED, &work->flags);
__set_current_state(TASK_RUNNING);
work->fn(work);
if (need_resched())
schedule();
}
}
unuse_mm(dev->mm);
set_fs(oldfs);
return 0;
}
static void vhost_vq_free_iovecs(struct vhost_virtqueue *vq)
{
kfree(vq->indirect);
vq->indirect = NULL;
kfree(vq->log);
vq->log = NULL;
kfree(vq->heads);
vq->heads = NULL;
}
static long vhost_dev_alloc_iovecs(struct vhost_dev *dev)
{
struct vhost_virtqueue *vq;
int i;
for (i = 0; i < dev->nvqs; ++i) {
vq = dev->vqs[i];
vq->indirect = kmalloc(sizeof *vq->indirect * UIO_MAXIOV,
GFP_KERNEL);
vq->log = kmalloc(sizeof *vq->log * UIO_MAXIOV, GFP_KERNEL);
vq->heads = kmalloc(sizeof *vq->heads * UIO_MAXIOV, GFP_KERNEL);
if (!vq->indirect || !vq->log || !vq->heads)
goto err_nomem;
}
return 0;
err_nomem:
for (; i >= 0; --i)
vhost_vq_free_iovecs(dev->vqs[i]);
return -ENOMEM;
}
static void vhost_dev_free_iovecs(struct vhost_dev *dev)
{
int i;
for (i = 0; i < dev->nvqs; ++i)
vhost_vq_free_iovecs(dev->vqs[i]);
}
void vhost_dev_init(struct vhost_dev *dev,
struct vhost_virtqueue **vqs, int nvqs)
{
struct vhost_virtqueue *vq;
int i;
dev->vqs = vqs;
dev->nvqs = nvqs;
mutex_init(&dev->mutex);
dev->log_ctx = NULL;
dev->log_file = NULL;
dev->umem = NULL;
dev->iotlb = NULL;
dev->mm = NULL;
dev->worker = NULL;
init_llist_head(&dev->work_list);
init_waitqueue_head(&dev->wait);
INIT_LIST_HEAD(&dev->read_list);
INIT_LIST_HEAD(&dev->pending_list);
spin_lock_init(&dev->iotlb_lock);
for (i = 0; i < dev->nvqs; ++i) {
vq = dev->vqs[i];
vq->log = NULL;
vq->indirect = NULL;
vq->heads = NULL;
vq->dev = dev;
mutex_init(&vq->mutex);
vhost_vq_reset(dev, vq);
if (vq->handle_kick)
vhost_poll_init(&vq->poll, vq->handle_kick,
POLLIN, dev);
}
}
long vhost_dev_check_owner(struct vhost_dev *dev)
{
return dev->mm == current->mm ? 0 : -EPERM;
}
static void vhost_attach_cgroups_work(struct vhost_work *work)
{
struct vhost_attach_cgroups_struct *s;
s = container_of(work, struct vhost_attach_cgroups_struct, work);
s->ret = cgroup_attach_task_all(s->owner, current);
}
static int vhost_attach_cgroups(struct vhost_dev *dev)
{
struct vhost_attach_cgroups_struct attach;
attach.owner = current;
vhost_work_init(&attach.work, vhost_attach_cgroups_work);
vhost_work_queue(dev, &attach.work);
vhost_work_flush(dev, &attach.work);
return attach.ret;
}
bool vhost_dev_has_owner(struct vhost_dev *dev)
{
return dev->mm;
}
long vhost_dev_set_owner(struct vhost_dev *dev)
{
struct task_struct *worker;
int err;
if (vhost_dev_has_owner(dev)) {
err = -EBUSY;
goto err_mm;
}
dev->mm = get_task_mm(current);
worker = kthread_create(vhost_worker, dev, "vhost-%d", current->pid);
if (IS_ERR(worker)) {
err = PTR_ERR(worker);
goto err_worker;
}
dev->worker = worker;
wake_up_process(worker);
err = vhost_attach_cgroups(dev);
if (err)
goto err_cgroup;
err = vhost_dev_alloc_iovecs(dev);
if (err)
goto err_cgroup;
return 0;
err_cgroup:
kthread_stop(worker);
dev->worker = NULL;
err_worker:
if (dev->mm)
mmput(dev->mm);
dev->mm = NULL;
err_mm:
return err;
}
static void *vhost_kvzalloc(unsigned long size)
{
void *n = kzalloc(size, GFP_KERNEL | __GFP_NOWARN | __GFP_REPEAT);
if (!n)
n = vzalloc(size);
return n;
}
struct vhost_umem *vhost_dev_reset_owner_prepare(void)
{
return vhost_kvzalloc(sizeof(struct vhost_umem));
}
void vhost_dev_reset_owner(struct vhost_dev *dev, struct vhost_umem *umem)
{
int i;
vhost_dev_cleanup(dev, true);
INIT_LIST_HEAD(&umem->umem_list);
dev->umem = umem;
for (i = 0; i < dev->nvqs; ++i)
dev->vqs[i]->umem = umem;
}
void vhost_dev_stop(struct vhost_dev *dev)
{
int i;
for (i = 0; i < dev->nvqs; ++i) {
if (dev->vqs[i]->kick && dev->vqs[i]->handle_kick) {
vhost_poll_stop(&dev->vqs[i]->poll);
vhost_poll_flush(&dev->vqs[i]->poll);
}
}
}
static void vhost_umem_free(struct vhost_umem *umem,
struct vhost_umem_node *node)
{
vhost_umem_interval_tree_remove(node, &umem->umem_tree);
list_del(&node->link);
kfree(node);
umem->numem--;
}
static void vhost_umem_clean(struct vhost_umem *umem)
{
struct vhost_umem_node *node, *tmp;
if (!umem)
return;
list_for_each_entry_safe(node, tmp, &umem->umem_list, link)
vhost_umem_free(umem, node);
kvfree(umem);
}
static void vhost_clear_msg(struct vhost_dev *dev)
{
struct vhost_msg_node *node, *n;
spin_lock(&dev->iotlb_lock);
list_for_each_entry_safe(node, n, &dev->read_list, node) {
list_del(&node->node);
kfree(node);
}
list_for_each_entry_safe(node, n, &dev->pending_list, node) {
list_del(&node->node);
kfree(node);
}
spin_unlock(&dev->iotlb_lock);
}
void vhost_dev_cleanup(struct vhost_dev *dev, bool locked)
{
int i;
for (i = 0; i < dev->nvqs; ++i) {
if (dev->vqs[i]->error_ctx)
eventfd_ctx_put(dev->vqs[i]->error_ctx);
if (dev->vqs[i]->error)
fput(dev->vqs[i]->error);
if (dev->vqs[i]->kick)
fput(dev->vqs[i]->kick);
if (dev->vqs[i]->call_ctx)
eventfd_ctx_put(dev->vqs[i]->call_ctx);
if (dev->vqs[i]->call)
fput(dev->vqs[i]->call);
vhost_vq_reset(dev, dev->vqs[i]);
}
vhost_dev_free_iovecs(dev);
if (dev->log_ctx)
eventfd_ctx_put(dev->log_ctx);
dev->log_ctx = NULL;
if (dev->log_file)
fput(dev->log_file);
dev->log_file = NULL;
vhost_umem_clean(dev->umem);
dev->umem = NULL;
vhost_umem_clean(dev->iotlb);
dev->iotlb = NULL;
vhost_clear_msg(dev);
wake_up_interruptible_poll(&dev->wait, POLLIN | POLLRDNORM);
WARN_ON(!llist_empty(&dev->work_list));
if (dev->worker) {
kthread_stop(dev->worker);
dev->worker = NULL;
}
if (dev->mm)
mmput(dev->mm);
dev->mm = NULL;
}
static int log_access_ok(void __user *log_base, u64 addr, unsigned long sz)
{
u64 a = addr / VHOST_PAGE_SIZE / 8;
if (a > ULONG_MAX - (unsigned long)log_base ||
a + (unsigned long)log_base > ULONG_MAX)
return 0;
return access_ok(VERIFY_WRITE, log_base + a,
(sz + VHOST_PAGE_SIZE * 8 - 1) / VHOST_PAGE_SIZE / 8);
}
static bool vhost_overflow(u64 uaddr, u64 size)
{
return uaddr > ULONG_MAX || size > ULONG_MAX || uaddr > ULONG_MAX - size;
}
static int vq_memory_access_ok(void __user *log_base, struct vhost_umem *umem,
int log_all)
{
struct vhost_umem_node *node;
if (!umem)
return 0;
list_for_each_entry(node, &umem->umem_list, link) {
unsigned long a = node->userspace_addr;
if (vhost_overflow(node->userspace_addr, node->size))
return 0;
if (!access_ok(VERIFY_WRITE, (void __user *)a,
node->size))
return 0;
else if (log_all && !log_access_ok(log_base,
node->start,
node->size))
return 0;
}
return 1;
}
static int memory_access_ok(struct vhost_dev *d, struct vhost_umem *umem,
int log_all)
{
int i;
for (i = 0; i < d->nvqs; ++i) {
int ok;
bool log;
mutex_lock(&d->vqs[i]->mutex);
log = log_all || vhost_has_feature(d->vqs[i], VHOST_F_LOG_ALL);
if (d->vqs[i]->private_data)
ok = vq_memory_access_ok(d->vqs[i]->log_base,
umem, log);
else
ok = 1;
mutex_unlock(&d->vqs[i]->mutex);
if (!ok)
return 0;
}
return 1;
}
static int vhost_copy_to_user(struct vhost_virtqueue *vq, void *to,
const void *from, unsigned size)
{
int ret;
if (!vq->iotlb)
return __copy_to_user(to, from, size);
else {
struct iov_iter t;
ret = translate_desc(vq, (u64)(uintptr_t)to, size, vq->iotlb_iov,
ARRAY_SIZE(vq->iotlb_iov),
VHOST_ACCESS_WO);
if (ret < 0)
goto out;
iov_iter_init(&t, WRITE, vq->iotlb_iov, ret, size);
ret = copy_to_iter(from, size, &t);
if (ret == size)
ret = 0;
}
out:
return ret;
}
static int vhost_copy_from_user(struct vhost_virtqueue *vq, void *to,
void *from, unsigned size)
{
int ret;
if (!vq->iotlb)
return __copy_from_user(to, from, size);
else {
struct iov_iter f;
ret = translate_desc(vq, (u64)(uintptr_t)from, size, vq->iotlb_iov,
ARRAY_SIZE(vq->iotlb_iov),
VHOST_ACCESS_RO);
if (ret < 0) {
vq_err(vq, "IOTLB translation failure: uaddr "
"%p size 0x%llx\n", from,
(unsigned long long) size);
goto out;
}
iov_iter_init(&f, READ, vq->iotlb_iov, ret, size);
ret = copy_from_iter(to, size, &f);
if (ret == size)
ret = 0;
}
out:
return ret;
}
static void __user *__vhost_get_user(struct vhost_virtqueue *vq,
void *addr, unsigned size)
{
int ret;
ret = translate_desc(vq, (u64)(uintptr_t)addr, size, vq->iotlb_iov,
ARRAY_SIZE(vq->iotlb_iov),
VHOST_ACCESS_RO);
if (ret < 0) {
vq_err(vq, "IOTLB translation failure: uaddr "
"%p size 0x%llx\n", addr,
(unsigned long long) size);
return NULL;
}
if (ret != 1 || vq->iotlb_iov[0].iov_len != size) {
vq_err(vq, "Non atomic userspace memory access: uaddr "
"%p size 0x%llx\n", addr,
(unsigned long long) size);
return NULL;
}
return vq->iotlb_iov[0].iov_base;
}
static void vhost_dev_lock_vqs(struct vhost_dev *d)
{
int i = 0;
for (i = 0; i < d->nvqs; ++i)
mutex_lock(&d->vqs[i]->mutex);
}
static void vhost_dev_unlock_vqs(struct vhost_dev *d)
{
int i = 0;
for (i = 0; i < d->nvqs; ++i)
mutex_unlock(&d->vqs[i]->mutex);
}
static int vhost_new_umem_range(struct vhost_umem *umem,
u64 start, u64 size, u64 end,
u64 userspace_addr, int perm)
{
struct vhost_umem_node *tmp, *node = kmalloc(sizeof(*node), GFP_ATOMIC);
if (!node)
return -ENOMEM;
if (umem->numem == max_iotlb_entries) {
tmp = list_first_entry(&umem->umem_list, typeof(*tmp), link);
vhost_umem_free(umem, tmp);
}
node->start = start;
node->size = size;
node->last = end;
node->userspace_addr = userspace_addr;
node->perm = perm;
INIT_LIST_HEAD(&node->link);
list_add_tail(&node->link, &umem->umem_list);
vhost_umem_interval_tree_insert(node, &umem->umem_tree);
umem->numem++;
return 0;
}
static void vhost_del_umem_range(struct vhost_umem *umem,
u64 start, u64 end)
{
struct vhost_umem_node *node;
while ((node = vhost_umem_interval_tree_iter_first(&umem->umem_tree,
start, end)))
vhost_umem_free(umem, node);
}
static void vhost_iotlb_notify_vq(struct vhost_dev *d,
struct vhost_iotlb_msg *msg)
{
struct vhost_msg_node *node, *n;
spin_lock(&d->iotlb_lock);
list_for_each_entry_safe(node, n, &d->pending_list, node) {
struct vhost_iotlb_msg *vq_msg = &node->msg.iotlb;
if (msg->iova <= vq_msg->iova &&
msg->iova + msg->size - 1 > vq_msg->iova &&
vq_msg->type == VHOST_IOTLB_MISS) {
vhost_poll_queue(&node->vq->poll);
list_del(&node->node);
kfree(node);
}
}
spin_unlock(&d->iotlb_lock);
}
static int umem_access_ok(u64 uaddr, u64 size, int access)
{
unsigned long a = uaddr;
if (vhost_overflow(uaddr, size))
return -EFAULT;
if ((access & VHOST_ACCESS_RO) &&
!access_ok(VERIFY_READ, (void __user *)a, size))
return -EFAULT;
if ((access & VHOST_ACCESS_WO) &&
!access_ok(VERIFY_WRITE, (void __user *)a, size))
return -EFAULT;
return 0;
}
int vhost_process_iotlb_msg(struct vhost_dev *dev,
struct vhost_iotlb_msg *msg)
{
int ret = 0;
vhost_dev_lock_vqs(dev);
switch (msg->type) {
case VHOST_IOTLB_UPDATE:
if (!dev->iotlb) {
ret = -EFAULT;
break;
}
if (umem_access_ok(msg->uaddr, msg->size, msg->perm)) {
ret = -EFAULT;
break;
}
if (vhost_new_umem_range(dev->iotlb, msg->iova, msg->size,
msg->iova + msg->size - 1,
msg->uaddr, msg->perm)) {
ret = -ENOMEM;
break;
}
vhost_iotlb_notify_vq(dev, msg);
break;
case VHOST_IOTLB_INVALIDATE:
vhost_del_umem_range(dev->iotlb, msg->iova,
msg->iova + msg->size - 1);
break;
default:
ret = -EINVAL;
break;
}
vhost_dev_unlock_vqs(dev);
return ret;
}
ssize_t vhost_chr_write_iter(struct vhost_dev *dev,
struct iov_iter *from)
{
struct vhost_msg_node node;
unsigned size = sizeof(struct vhost_msg);
size_t ret;
int err;
if (iov_iter_count(from) < size)
return 0;
ret = copy_from_iter(&node.msg, size, from);
if (ret != size)
goto done;
switch (node.msg.type) {
case VHOST_IOTLB_MSG:
err = vhost_process_iotlb_msg(dev, &node.msg.iotlb);
if (err)
ret = err;
break;
default:
ret = -EINVAL;
break;
}
done:
return ret;
}
unsigned int vhost_chr_poll(struct file *file, struct vhost_dev *dev,
poll_table *wait)
{
unsigned int mask = 0;
poll_wait(file, &dev->wait, wait);
if (!list_empty(&dev->read_list))
mask |= POLLIN | POLLRDNORM;
return mask;
}
ssize_t vhost_chr_read_iter(struct vhost_dev *dev, struct iov_iter *to,
int noblock)
{
DEFINE_WAIT(wait);
struct vhost_msg_node *node;
ssize_t ret = 0;
unsigned size = sizeof(struct vhost_msg);
if (iov_iter_count(to) < size)
return 0;
while (1) {
if (!noblock)
prepare_to_wait(&dev->wait, &wait,
TASK_INTERRUPTIBLE);
node = vhost_dequeue_msg(dev, &dev->read_list);
if (node)
break;
if (noblock) {
ret = -EAGAIN;
break;
}
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
if (!dev->iotlb) {
ret = -EBADFD;
break;
}
schedule();
}
if (!noblock)
finish_wait(&dev->wait, &wait);
if (node) {
ret = copy_to_iter(&node->msg, size, to);
if (ret != size || node->msg.type != VHOST_IOTLB_MISS) {
kfree(node);
return ret;
}
vhost_enqueue_msg(dev, &dev->pending_list, node);
}
return ret;
}
static int vhost_iotlb_miss(struct vhost_virtqueue *vq, u64 iova, int access)
{
struct vhost_dev *dev = vq->dev;
struct vhost_msg_node *node;
struct vhost_iotlb_msg *msg;
node = vhost_new_msg(vq, VHOST_IOTLB_MISS);
if (!node)
return -ENOMEM;
msg = &node->msg.iotlb;
msg->type = VHOST_IOTLB_MISS;
msg->iova = iova;
msg->perm = access;
vhost_enqueue_msg(dev, &dev->read_list, node);
return 0;
}
static int vq_access_ok(struct vhost_virtqueue *vq, unsigned int num,
struct vring_desc __user *desc,
struct vring_avail __user *avail,
struct vring_used __user *used)
{
size_t s = vhost_has_feature(vq, VIRTIO_RING_F_EVENT_IDX) ? 2 : 0;
return access_ok(VERIFY_READ, desc, num * sizeof *desc) &&
access_ok(VERIFY_READ, avail,
sizeof *avail + num * sizeof *avail->ring + s) &&
access_ok(VERIFY_WRITE, used,
sizeof *used + num * sizeof *used->ring + s);
}
static int iotlb_access_ok(struct vhost_virtqueue *vq,
int access, u64 addr, u64 len)
{
const struct vhost_umem_node *node;
struct vhost_umem *umem = vq->iotlb;
u64 s = 0, size;
while (len > s) {
node = vhost_umem_interval_tree_iter_first(&umem->umem_tree,
addr,
addr + len - 1);
if (node == NULL || node->start > addr) {
vhost_iotlb_miss(vq, addr, access);
return false;
} else if (!(node->perm & access)) {
return false;
}
size = node->size - addr + node->start;
s += size;
addr += size;
}
return true;
}
int vq_iotlb_prefetch(struct vhost_virtqueue *vq)
{
size_t s = vhost_has_feature(vq, VIRTIO_RING_F_EVENT_IDX) ? 2 : 0;
unsigned int num = vq->num;
if (!vq->iotlb)
return 1;
return iotlb_access_ok(vq, VHOST_ACCESS_RO, (u64)(uintptr_t)vq->desc,
num * sizeof *vq->desc) &&
iotlb_access_ok(vq, VHOST_ACCESS_RO, (u64)(uintptr_t)vq->avail,
sizeof *vq->avail +
num * sizeof *vq->avail->ring + s) &&
iotlb_access_ok(vq, VHOST_ACCESS_WO, (u64)(uintptr_t)vq->used,
sizeof *vq->used +
num * sizeof *vq->used->ring + s);
}
int vhost_log_access_ok(struct vhost_dev *dev)
{
return memory_access_ok(dev, dev->umem, 1);
}
static int vq_log_access_ok(struct vhost_virtqueue *vq,
void __user *log_base)
{
size_t s = vhost_has_feature(vq, VIRTIO_RING_F_EVENT_IDX) ? 2 : 0;
return vq_memory_access_ok(log_base, vq->umem,
vhost_has_feature(vq, VHOST_F_LOG_ALL)) &&
(!vq->log_used || log_access_ok(log_base, vq->log_addr,
sizeof *vq->used +
vq->num * sizeof *vq->used->ring + s));
}
int vhost_vq_access_ok(struct vhost_virtqueue *vq)
{
if (vq->iotlb) {
return 1;
}
return vq_access_ok(vq, vq->num, vq->desc, vq->avail, vq->used) &&
vq_log_access_ok(vq, vq->log_base);
}
static struct vhost_umem *vhost_umem_alloc(void)
{
struct vhost_umem *umem = vhost_kvzalloc(sizeof(*umem));
if (!umem)
return NULL;
umem->umem_tree = RB_ROOT;
umem->numem = 0;
INIT_LIST_HEAD(&umem->umem_list);
return umem;
}
static long vhost_set_memory(struct vhost_dev *d, struct vhost_memory __user *m)
{
struct vhost_memory mem, *newmem;
struct vhost_memory_region *region;
struct vhost_umem *newumem, *oldumem;
unsigned long size = offsetof(struct vhost_memory, regions);
int i;
if (copy_from_user(&mem, m, size))
return -EFAULT;
if (mem.padding)
return -EOPNOTSUPP;
if (mem.nregions > max_mem_regions)
return -E2BIG;
newmem = vhost_kvzalloc(size + mem.nregions * sizeof(*m->regions));
if (!newmem)
return -ENOMEM;
memcpy(newmem, &mem, size);
if (copy_from_user(newmem->regions, m->regions,
mem.nregions * sizeof *m->regions)) {
kvfree(newmem);
return -EFAULT;
}
newumem = vhost_umem_alloc();
if (!newumem) {
kvfree(newmem);
return -ENOMEM;
}
for (region = newmem->regions;
region < newmem->regions + mem.nregions;
region++) {
if (vhost_new_umem_range(newumem,
region->guest_phys_addr,
region->memory_size,
region->guest_phys_addr +
region->memory_size - 1,
region->userspace_addr,
VHOST_ACCESS_RW))
goto err;
}
if (!memory_access_ok(d, newumem, 0))
goto err;
oldumem = d->umem;
d->umem = newumem;
for (i = 0; i < d->nvqs; ++i) {
mutex_lock(&d->vqs[i]->mutex);
d->vqs[i]->umem = newumem;
mutex_unlock(&d->vqs[i]->mutex);
}
kvfree(newmem);
vhost_umem_clean(oldumem);
return 0;
err:
vhost_umem_clean(newumem);
kvfree(newmem);
return -EFAULT;
}
long vhost_vring_ioctl(struct vhost_dev *d, int ioctl, void __user *argp)
{
struct file *eventfp, *filep = NULL;
bool pollstart = false, pollstop = false;
struct eventfd_ctx *ctx = NULL;
u32 __user *idxp = argp;
struct vhost_virtqueue *vq;
struct vhost_vring_state s;
struct vhost_vring_file f;
struct vhost_vring_addr a;
u32 idx;
long r;
r = get_user(idx, idxp);
if (r < 0)
return r;
if (idx >= d->nvqs)
return -ENOBUFS;
vq = d->vqs[idx];
mutex_lock(&vq->mutex);
switch (ioctl) {
case VHOST_SET_VRING_NUM:
if (vq->private_data) {
r = -EBUSY;
break;
}
if (copy_from_user(&s, argp, sizeof s)) {
r = -EFAULT;
break;
}
if (!s.num || s.num > 0xffff || (s.num & (s.num - 1))) {
r = -EINVAL;
break;
}
vq->num = s.num;
break;
case VHOST_SET_VRING_BASE:
if (vq->private_data) {
r = -EBUSY;
break;
}
if (copy_from_user(&s, argp, sizeof s)) {
r = -EFAULT;
break;
}
if (s.num > 0xffff) {
r = -EINVAL;
break;
}
vq->last_avail_idx = s.num;
vq->avail_idx = vq->last_avail_idx;
break;
case VHOST_GET_VRING_BASE:
s.index = idx;
s.num = vq->last_avail_idx;
if (copy_to_user(argp, &s, sizeof s))
r = -EFAULT;
break;
case VHOST_SET_VRING_ADDR:
if (copy_from_user(&a, argp, sizeof a)) {
r = -EFAULT;
break;
}
if (a.flags & ~(0x1 << VHOST_VRING_F_LOG)) {
r = -EOPNOTSUPP;
break;
}
if ((u64)(unsigned long)a.desc_user_addr != a.desc_user_addr ||
(u64)(unsigned long)a.used_user_addr != a.used_user_addr ||
(u64)(unsigned long)a.avail_user_addr != a.avail_user_addr) {
r = -EFAULT;
break;
}
BUILD_BUG_ON(__alignof__ *vq->avail > VRING_AVAIL_ALIGN_SIZE);
BUILD_BUG_ON(__alignof__ *vq->used > VRING_USED_ALIGN_SIZE);
if ((a.avail_user_addr & (VRING_AVAIL_ALIGN_SIZE - 1)) ||
(a.used_user_addr & (VRING_USED_ALIGN_SIZE - 1)) ||
(a.log_guest_addr & (VRING_USED_ALIGN_SIZE - 1))) {
r = -EINVAL;
break;
}
if (vq->private_data) {
if (!vq_access_ok(vq, vq->num,
(void __user *)(unsigned long)a.desc_user_addr,
(void __user *)(unsigned long)a.avail_user_addr,
(void __user *)(unsigned long)a.used_user_addr)) {
r = -EINVAL;
break;
}
if ((a.flags & (0x1 << VHOST_VRING_F_LOG)) &&
!log_access_ok(vq->log_base, a.log_guest_addr,
sizeof *vq->used +
vq->num * sizeof *vq->used->ring)) {
r = -EINVAL;
break;
}
}
vq->log_used = !!(a.flags & (0x1 << VHOST_VRING_F_LOG));
vq->desc = (void __user *)(unsigned long)a.desc_user_addr;
vq->avail = (void __user *)(unsigned long)a.avail_user_addr;
vq->log_addr = a.log_guest_addr;
vq->used = (void __user *)(unsigned long)a.used_user_addr;
break;
case VHOST_SET_VRING_KICK:
if (copy_from_user(&f, argp, sizeof f)) {
r = -EFAULT;
break;
}
eventfp = f.fd == -1 ? NULL : eventfd_fget(f.fd);
if (IS_ERR(eventfp)) {
r = PTR_ERR(eventfp);
break;
}
if (eventfp != vq->kick) {
pollstop = (filep = vq->kick) != NULL;
pollstart = (vq->kick = eventfp) != NULL;
} else
filep = eventfp;
break;
case VHOST_SET_VRING_CALL:
if (copy_from_user(&f, argp, sizeof f)) {
r = -EFAULT;
break;
}
eventfp = f.fd == -1 ? NULL : eventfd_fget(f.fd);
if (IS_ERR(eventfp)) {
r = PTR_ERR(eventfp);
break;
}
if (eventfp != vq->call) {
filep = vq->call;
ctx = vq->call_ctx;
vq->call = eventfp;
vq->call_ctx = eventfp ?
eventfd_ctx_fileget(eventfp) : NULL;
} else
filep = eventfp;
break;
case VHOST_SET_VRING_ERR:
if (copy_from_user(&f, argp, sizeof f)) {
r = -EFAULT;
break;
}
eventfp = f.fd == -1 ? NULL : eventfd_fget(f.fd);
if (IS_ERR(eventfp)) {
r = PTR_ERR(eventfp);
break;
}
if (eventfp != vq->error) {
filep = vq->error;
vq->error = eventfp;
ctx = vq->error_ctx;
vq->error_ctx = eventfp ?
eventfd_ctx_fileget(eventfp) : NULL;
} else
filep = eventfp;
break;
case VHOST_SET_VRING_ENDIAN:
r = vhost_set_vring_endian(vq, argp);
break;
case VHOST_GET_VRING_ENDIAN:
r = vhost_get_vring_endian(vq, idx, argp);
break;
case VHOST_SET_VRING_BUSYLOOP_TIMEOUT:
if (copy_from_user(&s, argp, sizeof(s))) {
r = -EFAULT;
break;
}
vq->busyloop_timeout = s.num;
break;
case VHOST_GET_VRING_BUSYLOOP_TIMEOUT:
s.index = idx;
s.num = vq->busyloop_timeout;
if (copy_to_user(argp, &s, sizeof(s)))
r = -EFAULT;
break;
default:
r = -ENOIOCTLCMD;
}
if (pollstop && vq->handle_kick)
vhost_poll_stop(&vq->poll);
if (ctx)
eventfd_ctx_put(ctx);
if (filep)
fput(filep);
if (pollstart && vq->handle_kick)
r = vhost_poll_start(&vq->poll, vq->kick);
mutex_unlock(&vq->mutex);
if (pollstop && vq->handle_kick)
vhost_poll_flush(&vq->poll);
return r;
}
int vhost_init_device_iotlb(struct vhost_dev *d, bool enabled)
{
struct vhost_umem *niotlb, *oiotlb;
int i;
niotlb = vhost_umem_alloc();
if (!niotlb)
return -ENOMEM;
oiotlb = d->iotlb;
d->iotlb = niotlb;
for (i = 0; i < d->nvqs; ++i) {
mutex_lock(&d->vqs[i]->mutex);
d->vqs[i]->iotlb = niotlb;
mutex_unlock(&d->vqs[i]->mutex);
}
vhost_umem_clean(oiotlb);
return 0;
}
long vhost_dev_ioctl(struct vhost_dev *d, unsigned int ioctl, void __user *argp)
{
struct file *eventfp, *filep = NULL;
struct eventfd_ctx *ctx = NULL;
u64 p;
long r;
int i, fd;
if (ioctl == VHOST_SET_OWNER) {
r = vhost_dev_set_owner(d);
goto done;
}
r = vhost_dev_check_owner(d);
if (r)
goto done;
switch (ioctl) {
case VHOST_SET_MEM_TABLE:
r = vhost_set_memory(d, argp);
break;
case VHOST_SET_LOG_BASE:
if (copy_from_user(&p, argp, sizeof p)) {
r = -EFAULT;
break;
}
if ((u64)(unsigned long)p != p) {
r = -EFAULT;
break;
}
for (i = 0; i < d->nvqs; ++i) {
struct vhost_virtqueue *vq;
void __user *base = (void __user *)(unsigned long)p;
vq = d->vqs[i];
mutex_lock(&vq->mutex);
if (vq->private_data && !vq_log_access_ok(vq, base))
r = -EFAULT;
else
vq->log_base = base;
mutex_unlock(&vq->mutex);
}
break;
case VHOST_SET_LOG_FD:
r = get_user(fd, (int __user *)argp);
if (r < 0)
break;
eventfp = fd == -1 ? NULL : eventfd_fget(fd);
if (IS_ERR(eventfp)) {
r = PTR_ERR(eventfp);
break;
}
if (eventfp != d->log_file) {
filep = d->log_file;
d->log_file = eventfp;
ctx = d->log_ctx;
d->log_ctx = eventfp ?
eventfd_ctx_fileget(eventfp) : NULL;
} else
filep = eventfp;
for (i = 0; i < d->nvqs; ++i) {
mutex_lock(&d->vqs[i]->mutex);
d->vqs[i]->log_ctx = d->log_ctx;
mutex_unlock(&d->vqs[i]->mutex);
}
if (ctx)
eventfd_ctx_put(ctx);
if (filep)
fput(filep);
break;
default:
r = -ENOIOCTLCMD;
break;
}
done:
return r;
}
static int set_bit_to_user(int nr, void __user *addr)
{
unsigned long log = (unsigned long)addr;
struct page *page;
void *base;
int bit = nr + (log % PAGE_SIZE) * 8;
int r;
r = get_user_pages_fast(log, 1, 1, &page);
if (r < 0)
return r;
BUG_ON(r != 1);
base = kmap_atomic(page);
set_bit(bit, base);
kunmap_atomic(base);
set_page_dirty_lock(page);
put_page(page);
return 0;
}
static int log_write(void __user *log_base,
u64 write_address, u64 write_length)
{
u64 write_page = write_address / VHOST_PAGE_SIZE;
int r;
if (!write_length)
return 0;
write_length += write_address % VHOST_PAGE_SIZE;
for (;;) {
u64 base = (u64)(unsigned long)log_base;
u64 log = base + write_page / 8;
int bit = write_page % 8;
if ((u64)(unsigned long)log != log)
return -EFAULT;
r = set_bit_to_user(bit, (void __user *)(unsigned long)log);
if (r < 0)
return r;
if (write_length <= VHOST_PAGE_SIZE)
break;
write_length -= VHOST_PAGE_SIZE;
write_page += 1;
}
return r;
}
int vhost_log_write(struct vhost_virtqueue *vq, struct vhost_log *log,
unsigned int log_num, u64 len)
{
int i, r;
smp_wmb();
for (i = 0; i < log_num; ++i) {
u64 l = min(log[i].len, len);
r = log_write(vq->log_base, log[i].addr, l);
if (r < 0)
return r;
len -= l;
if (!len) {
if (vq->log_ctx)
eventfd_signal(vq->log_ctx, 1);
return 0;
}
}
BUG();
return 0;
}
static int vhost_update_used_flags(struct vhost_virtqueue *vq)
{
void __user *used;
if (vhost_put_user(vq, cpu_to_vhost16(vq, vq->used_flags),
&vq->used->flags) < 0)
return -EFAULT;
if (unlikely(vq->log_used)) {
smp_wmb();
used = &vq->used->flags;
log_write(vq->log_base, vq->log_addr +
(used - (void __user *)vq->used),
sizeof vq->used->flags);
if (vq->log_ctx)
eventfd_signal(vq->log_ctx, 1);
}
return 0;
}
static int vhost_update_avail_event(struct vhost_virtqueue *vq, u16 avail_event)
{
if (vhost_put_user(vq, cpu_to_vhost16(vq, vq->avail_idx),
vhost_avail_event(vq)))
return -EFAULT;
if (unlikely(vq->log_used)) {
void __user *used;
smp_wmb();
used = vhost_avail_event(vq);
log_write(vq->log_base, vq->log_addr +
(used - (void __user *)vq->used),
sizeof *vhost_avail_event(vq));
if (vq->log_ctx)
eventfd_signal(vq->log_ctx, 1);
}
return 0;
}
int vhost_vq_init_access(struct vhost_virtqueue *vq)
{
__virtio16 last_used_idx;
int r;
bool is_le = vq->is_le;
if (!vq->private_data) {
vhost_reset_is_le(vq);
return 0;
}
vhost_init_is_le(vq);
r = vhost_update_used_flags(vq);
if (r)
goto err;
vq->signalled_used_valid = false;
if (!vq->iotlb &&
!access_ok(VERIFY_READ, &vq->used->idx, sizeof vq->used->idx)) {
r = -EFAULT;
goto err;
}
r = vhost_get_user(vq, last_used_idx, &vq->used->idx);
if (r) {
vq_err(vq, "Can't access used idx at %p\n",
&vq->used->idx);
goto err;
}
vq->last_used_idx = vhost16_to_cpu(vq, last_used_idx);
return 0;
err:
vq->is_le = is_le;
return r;
}
static int translate_desc(struct vhost_virtqueue *vq, u64 addr, u32 len,
struct iovec iov[], int iov_size, int access)
{
const struct vhost_umem_node *node;
struct vhost_dev *dev = vq->dev;
struct vhost_umem *umem = dev->iotlb ? dev->iotlb : dev->umem;
struct iovec *_iov;
u64 s = 0;
int ret = 0;
while ((u64)len > s) {
u64 size;
if (unlikely(ret >= iov_size)) {
ret = -ENOBUFS;
break;
}
node = vhost_umem_interval_tree_iter_first(&umem->umem_tree,
addr, addr + len - 1);
if (node == NULL || node->start > addr) {
if (umem != dev->iotlb) {
ret = -EFAULT;
break;
}
ret = -EAGAIN;
break;
} else if (!(node->perm & access)) {
ret = -EPERM;
break;
}
_iov = iov + ret;
size = node->size - addr + node->start;
_iov->iov_len = min((u64)len - s, size);
_iov->iov_base = (void __user *)(unsigned long)
(node->userspace_addr + addr - node->start);
s += size;
addr += size;
++ret;
}
if (ret == -EAGAIN)
vhost_iotlb_miss(vq, addr, access);
return ret;
}
static unsigned next_desc(struct vhost_virtqueue *vq, struct vring_desc *desc)
{
unsigned int next;
if (!(desc->flags & cpu_to_vhost16(vq, VRING_DESC_F_NEXT)))
return -1U;
next = vhost16_to_cpu(vq, desc->next);
read_barrier_depends();
return next;
}
static int get_indirect(struct vhost_virtqueue *vq,
struct iovec iov[], unsigned int iov_size,
unsigned int *out_num, unsigned int *in_num,
struct vhost_log *log, unsigned int *log_num,
struct vring_desc *indirect)
{
struct vring_desc desc;
unsigned int i = 0, count, found = 0;
u32 len = vhost32_to_cpu(vq, indirect->len);
struct iov_iter from;
int ret, access;
if (unlikely(len % sizeof desc)) {
vq_err(vq, "Invalid length in indirect descriptor: "
"len 0x%llx not multiple of 0x%zx\n",
(unsigned long long)len,
sizeof desc);
return -EINVAL;
}
ret = translate_desc(vq, vhost64_to_cpu(vq, indirect->addr), len, vq->indirect,
UIO_MAXIOV, VHOST_ACCESS_RO);
if (unlikely(ret < 0)) {
if (ret != -EAGAIN)
vq_err(vq, "Translation failure %d in indirect.\n", ret);
return ret;
}
iov_iter_init(&from, READ, vq->indirect, ret, len);
read_barrier_depends();
count = len / sizeof desc;
if (unlikely(count > USHRT_MAX + 1)) {
vq_err(vq, "Indirect buffer length too big: %d\n",
indirect->len);
return -E2BIG;
}
do {
unsigned iov_count = *in_num + *out_num;
if (unlikely(++found > count)) {
vq_err(vq, "Loop detected: last one at %u "
"indirect size %u\n",
i, count);
return -EINVAL;
}
if (unlikely(copy_from_iter(&desc, sizeof(desc), &from) !=
sizeof(desc))) {
vq_err(vq, "Failed indirect descriptor: idx %d, %zx\n",
i, (size_t)vhost64_to_cpu(vq, indirect->addr) + i * sizeof desc);
return -EINVAL;
}
if (unlikely(desc.flags & cpu_to_vhost16(vq, VRING_DESC_F_INDIRECT))) {
vq_err(vq, "Nested indirect descriptor: idx %d, %zx\n",
i, (size_t)vhost64_to_cpu(vq, indirect->addr) + i * sizeof desc);
return -EINVAL;
}
if (desc.flags & cpu_to_vhost16(vq, VRING_DESC_F_WRITE))
access = VHOST_ACCESS_WO;
else
access = VHOST_ACCESS_RO;
ret = translate_desc(vq, vhost64_to_cpu(vq, desc.addr),
vhost32_to_cpu(vq, desc.len), iov + iov_count,
iov_size - iov_count, access);
if (unlikely(ret < 0)) {
if (ret != -EAGAIN)
vq_err(vq, "Translation failure %d indirect idx %d\n",
ret, i);
return ret;
}
if (access == VHOST_ACCESS_WO) {
*in_num += ret;
if (unlikely(log)) {
log[*log_num].addr = vhost64_to_cpu(vq, desc.addr);
log[*log_num].len = vhost32_to_cpu(vq, desc.len);
++*log_num;
}
} else {
if (unlikely(*in_num)) {
vq_err(vq, "Indirect descriptor "
"has out after in: idx %d\n", i);
return -EINVAL;
}
*out_num += ret;
}
} while ((i = next_desc(vq, &desc)) != -1);
return 0;
}
int vhost_get_vq_desc(struct vhost_virtqueue *vq,
struct iovec iov[], unsigned int iov_size,
unsigned int *out_num, unsigned int *in_num,
struct vhost_log *log, unsigned int *log_num)
{
struct vring_desc desc;
unsigned int i, head, found = 0;
u16 last_avail_idx;
__virtio16 avail_idx;
__virtio16 ring_head;
int ret, access;
last_avail_idx = vq->last_avail_idx;
if (unlikely(vhost_get_user(vq, avail_idx, &vq->avail->idx))) {
vq_err(vq, "Failed to access avail idx at %p\n",
&vq->avail->idx);
return -EFAULT;
}
vq->avail_idx = vhost16_to_cpu(vq, avail_idx);
if (unlikely((u16)(vq->avail_idx - last_avail_idx) > vq->num)) {
vq_err(vq, "Guest moved used index from %u to %u",
last_avail_idx, vq->avail_idx);
return -EFAULT;
}
if (vq->avail_idx == last_avail_idx)
return vq->num;
smp_rmb();
if (unlikely(vhost_get_user(vq, ring_head,
&vq->avail->ring[last_avail_idx & (vq->num - 1)]))) {
vq_err(vq, "Failed to read head: idx %d address %p\n",
last_avail_idx,
&vq->avail->ring[last_avail_idx % vq->num]);
return -EFAULT;
}
head = vhost16_to_cpu(vq, ring_head);
if (unlikely(head >= vq->num)) {
vq_err(vq, "Guest says index %u > %u is available",
head, vq->num);
return -EINVAL;
}
*out_num = *in_num = 0;
if (unlikely(log))
*log_num = 0;
i = head;
do {
unsigned iov_count = *in_num + *out_num;
if (unlikely(i >= vq->num)) {
vq_err(vq, "Desc index is %u > %u, head = %u",
i, vq->num, head);
return -EINVAL;
}
if (unlikely(++found > vq->num)) {
vq_err(vq, "Loop detected: last one at %u "
"vq size %u head %u\n",
i, vq->num, head);
return -EINVAL;
}
ret = vhost_copy_from_user(vq, &desc, vq->desc + i,
sizeof desc);
if (unlikely(ret)) {
vq_err(vq, "Failed to get descriptor: idx %d addr %p\n",
i, vq->desc + i);
return -EFAULT;
}
if (desc.flags & cpu_to_vhost16(vq, VRING_DESC_F_INDIRECT)) {
ret = get_indirect(vq, iov, iov_size,
out_num, in_num,
log, log_num, &desc);
if (unlikely(ret < 0)) {
if (ret != -EAGAIN)
vq_err(vq, "Failure detected "
"in indirect descriptor at idx %d\n", i);
return ret;
}
continue;
}
if (desc.flags & cpu_to_vhost16(vq, VRING_DESC_F_WRITE))
access = VHOST_ACCESS_WO;
else
access = VHOST_ACCESS_RO;
ret = translate_desc(vq, vhost64_to_cpu(vq, desc.addr),
vhost32_to_cpu(vq, desc.len), iov + iov_count,
iov_size - iov_count, access);
if (unlikely(ret < 0)) {
if (ret != -EAGAIN)
vq_err(vq, "Translation failure %d descriptor idx %d\n",
ret, i);
return ret;
}
if (access == VHOST_ACCESS_WO) {
*in_num += ret;
if (unlikely(log)) {
log[*log_num].addr = vhost64_to_cpu(vq, desc.addr);
log[*log_num].len = vhost32_to_cpu(vq, desc.len);
++*log_num;
}
} else {
if (unlikely(*in_num)) {
vq_err(vq, "Descriptor has out after in: "
"idx %d\n", i);
return -EINVAL;
}
*out_num += ret;
}
} while ((i = next_desc(vq, &desc)) != -1);
vq->last_avail_idx++;
BUG_ON(!(vq->used_flags & VRING_USED_F_NO_NOTIFY));
return head;
}
void vhost_discard_vq_desc(struct vhost_virtqueue *vq, int n)
{
vq->last_avail_idx -= n;
}
int vhost_add_used(struct vhost_virtqueue *vq, unsigned int head, int len)
{
struct vring_used_elem heads = {
cpu_to_vhost32(vq, head),
cpu_to_vhost32(vq, len)
};
return vhost_add_used_n(vq, &heads, 1);
}
static int __vhost_add_used_n(struct vhost_virtqueue *vq,
struct vring_used_elem *heads,
unsigned count)
{
struct vring_used_elem __user *used;
u16 old, new;
int start;
start = vq->last_used_idx & (vq->num - 1);
used = vq->used->ring + start;
if (count == 1) {
if (vhost_put_user(vq, heads[0].id, &used->id)) {
vq_err(vq, "Failed to write used id");
return -EFAULT;
}
if (vhost_put_user(vq, heads[0].len, &used->len)) {
vq_err(vq, "Failed to write used len");
return -EFAULT;
}
} else if (vhost_copy_to_user(vq, used, heads, count * sizeof *used)) {
vq_err(vq, "Failed to write used");
return -EFAULT;
}
if (unlikely(vq->log_used)) {
smp_wmb();
log_write(vq->log_base,
vq->log_addr +
((void __user *)used - (void __user *)vq->used),
count * sizeof *used);
}
old = vq->last_used_idx;
new = (vq->last_used_idx += count);
if (unlikely((u16)(new - vq->signalled_used) < (u16)(new - old)))
vq->signalled_used_valid = false;
return 0;
}
int vhost_add_used_n(struct vhost_virtqueue *vq, struct vring_used_elem *heads,
unsigned count)
{
int start, n, r;
start = vq->last_used_idx & (vq->num - 1);
n = vq->num - start;
if (n < count) {
r = __vhost_add_used_n(vq, heads, n);
if (r < 0)
return r;
heads += n;
count -= n;
}
r = __vhost_add_used_n(vq, heads, count);
smp_wmb();
if (vhost_put_user(vq, cpu_to_vhost16(vq, vq->last_used_idx),
&vq->used->idx)) {
vq_err(vq, "Failed to increment used idx");
return -EFAULT;
}
if (unlikely(vq->log_used)) {
log_write(vq->log_base,
vq->log_addr + offsetof(struct vring_used, idx),
sizeof vq->used->idx);
if (vq->log_ctx)
eventfd_signal(vq->log_ctx, 1);
}
return r;
}
static bool vhost_notify(struct vhost_dev *dev, struct vhost_virtqueue *vq)
{
__u16 old, new;
__virtio16 event;
bool v;
smp_mb();
if (vhost_has_feature(vq, VIRTIO_F_NOTIFY_ON_EMPTY) &&
unlikely(vq->avail_idx == vq->last_avail_idx))
return true;
if (!vhost_has_feature(vq, VIRTIO_RING_F_EVENT_IDX)) {
__virtio16 flags;
if (vhost_get_user(vq, flags, &vq->avail->flags)) {
vq_err(vq, "Failed to get flags");
return true;
}
return !(flags & cpu_to_vhost16(vq, VRING_AVAIL_F_NO_INTERRUPT));
}
old = vq->signalled_used;
v = vq->signalled_used_valid;
new = vq->signalled_used = vq->last_used_idx;
vq->signalled_used_valid = true;
if (unlikely(!v))
return true;
if (vhost_get_user(vq, event, vhost_used_event(vq))) {
vq_err(vq, "Failed to get used event idx");
return true;
}
return vring_need_event(vhost16_to_cpu(vq, event), new, old);
}
void vhost_signal(struct vhost_dev *dev, struct vhost_virtqueue *vq)
{
if (vq->call_ctx && vhost_notify(dev, vq))
eventfd_signal(vq->call_ctx, 1);
}
void vhost_add_used_and_signal(struct vhost_dev *dev,
struct vhost_virtqueue *vq,
unsigned int head, int len)
{
vhost_add_used(vq, head, len);
vhost_signal(dev, vq);
}
void vhost_add_used_and_signal_n(struct vhost_dev *dev,
struct vhost_virtqueue *vq,
struct vring_used_elem *heads, unsigned count)
{
vhost_add_used_n(vq, heads, count);
vhost_signal(dev, vq);
}
bool vhost_vq_avail_empty(struct vhost_dev *dev, struct vhost_virtqueue *vq)
{
__virtio16 avail_idx;
int r;
r = vhost_get_user(vq, avail_idx, &vq->avail->idx);
if (r)
return false;
return vhost16_to_cpu(vq, avail_idx) == vq->avail_idx;
}
bool vhost_enable_notify(struct vhost_dev *dev, struct vhost_virtqueue *vq)
{
__virtio16 avail_idx;
int r;
if (!(vq->used_flags & VRING_USED_F_NO_NOTIFY))
return false;
vq->used_flags &= ~VRING_USED_F_NO_NOTIFY;
if (!vhost_has_feature(vq, VIRTIO_RING_F_EVENT_IDX)) {
r = vhost_update_used_flags(vq);
if (r) {
vq_err(vq, "Failed to enable notification at %p: %d\n",
&vq->used->flags, r);
return false;
}
} else {
r = vhost_update_avail_event(vq, vq->avail_idx);
if (r) {
vq_err(vq, "Failed to update avail event index at %p: %d\n",
vhost_avail_event(vq), r);
return false;
}
}
smp_mb();
r = vhost_get_user(vq, avail_idx, &vq->avail->idx);
if (r) {
vq_err(vq, "Failed to check avail idx at %p: %d\n",
&vq->avail->idx, r);
return false;
}
return vhost16_to_cpu(vq, avail_idx) != vq->avail_idx;
}
void vhost_disable_notify(struct vhost_dev *dev, struct vhost_virtqueue *vq)
{
int r;
if (vq->used_flags & VRING_USED_F_NO_NOTIFY)
return;
vq->used_flags |= VRING_USED_F_NO_NOTIFY;
if (!vhost_has_feature(vq, VIRTIO_RING_F_EVENT_IDX)) {
r = vhost_update_used_flags(vq);
if (r)
vq_err(vq, "Failed to enable notification at %p: %d\n",
&vq->used->flags, r);
}
}
struct vhost_msg_node *vhost_new_msg(struct vhost_virtqueue *vq, int type)
{
struct vhost_msg_node *node = kmalloc(sizeof *node, GFP_KERNEL);
if (!node)
return NULL;
node->vq = vq;
node->msg.type = type;
return node;
}
void vhost_enqueue_msg(struct vhost_dev *dev, struct list_head *head,
struct vhost_msg_node *node)
{
spin_lock(&dev->iotlb_lock);
list_add_tail(&node->node, head);
spin_unlock(&dev->iotlb_lock);
wake_up_interruptible_poll(&dev->wait, POLLIN | POLLRDNORM);
}
struct vhost_msg_node *vhost_dequeue_msg(struct vhost_dev *dev,
struct list_head *head)
{
struct vhost_msg_node *node = NULL;
spin_lock(&dev->iotlb_lock);
if (!list_empty(head)) {
node = list_first_entry(head, struct vhost_msg_node,
node);
list_del(&node->node);
}
spin_unlock(&dev->iotlb_lock);
return node;
}
static int __init vhost_init(void)
{
return 0;
}
static void __exit vhost_exit(void)
{
}
