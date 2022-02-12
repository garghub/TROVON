static int __init vfio_virqfd_init(void)
{
vfio_irqfd_cleanup_wq =
create_singlethread_workqueue("vfio-irqfd-cleanup");
if (!vfio_irqfd_cleanup_wq)
return -ENOMEM;
return 0;
}
static void __exit vfio_virqfd_exit(void)
{
destroy_workqueue(vfio_irqfd_cleanup_wq);
}
static void virqfd_deactivate(struct virqfd *virqfd)
{
queue_work(vfio_irqfd_cleanup_wq, &virqfd->shutdown);
}
static int virqfd_wakeup(wait_queue_t *wait, unsigned mode, int sync, void *key)
{
struct virqfd *virqfd = container_of(wait, struct virqfd, wait);
unsigned long flags = (unsigned long)key;
if (flags & POLLIN) {
if ((!virqfd->handler ||
virqfd->handler(virqfd->opaque, virqfd->data)) &&
virqfd->thread)
schedule_work(&virqfd->inject);
}
if (flags & POLLHUP) {
unsigned long flags;
spin_lock_irqsave(&virqfd_lock, flags);
if (*(virqfd->pvirqfd) == virqfd) {
*(virqfd->pvirqfd) = NULL;
virqfd_deactivate(virqfd);
}
spin_unlock_irqrestore(&virqfd_lock, flags);
}
return 0;
}
static void virqfd_ptable_queue_proc(struct file *file,
wait_queue_head_t *wqh, poll_table *pt)
{
struct virqfd *virqfd = container_of(pt, struct virqfd, pt);
add_wait_queue(wqh, &virqfd->wait);
}
static void virqfd_shutdown(struct work_struct *work)
{
struct virqfd *virqfd = container_of(work, struct virqfd, shutdown);
u64 cnt;
eventfd_ctx_remove_wait_queue(virqfd->eventfd, &virqfd->wait, &cnt);
flush_work(&virqfd->inject);
eventfd_ctx_put(virqfd->eventfd);
kfree(virqfd);
}
static void virqfd_inject(struct work_struct *work)
{
struct virqfd *virqfd = container_of(work, struct virqfd, inject);
if (virqfd->thread)
virqfd->thread(virqfd->opaque, virqfd->data);
}
int vfio_virqfd_enable(void *opaque,
int (*handler)(void *, void *),
void (*thread)(void *, void *),
void *data, struct virqfd **pvirqfd, int fd)
{
struct fd irqfd;
struct eventfd_ctx *ctx;
struct virqfd *virqfd;
int ret = 0;
unsigned int events;
virqfd = kzalloc(sizeof(*virqfd), GFP_KERNEL);
if (!virqfd)
return -ENOMEM;
virqfd->pvirqfd = pvirqfd;
virqfd->opaque = opaque;
virqfd->handler = handler;
virqfd->thread = thread;
virqfd->data = data;
INIT_WORK(&virqfd->shutdown, virqfd_shutdown);
INIT_WORK(&virqfd->inject, virqfd_inject);
irqfd = fdget(fd);
if (!irqfd.file) {
ret = -EBADF;
goto err_fd;
}
ctx = eventfd_ctx_fileget(irqfd.file);
if (IS_ERR(ctx)) {
ret = PTR_ERR(ctx);
goto err_ctx;
}
virqfd->eventfd = ctx;
spin_lock_irq(&virqfd_lock);
if (*pvirqfd) {
spin_unlock_irq(&virqfd_lock);
ret = -EBUSY;
goto err_busy;
}
*pvirqfd = virqfd;
spin_unlock_irq(&virqfd_lock);
init_waitqueue_func_entry(&virqfd->wait, virqfd_wakeup);
init_poll_funcptr(&virqfd->pt, virqfd_ptable_queue_proc);
events = irqfd.file->f_op->poll(irqfd.file, &virqfd->pt);
if (events & POLLIN) {
if ((!handler || handler(opaque, data)) && thread)
schedule_work(&virqfd->inject);
}
fdput(irqfd);
return 0;
err_busy:
eventfd_ctx_put(ctx);
err_ctx:
fdput(irqfd);
err_fd:
kfree(virqfd);
return ret;
}
void vfio_virqfd_disable(struct virqfd **pvirqfd)
{
unsigned long flags;
spin_lock_irqsave(&virqfd_lock, flags);
if (*pvirqfd) {
virqfd_deactivate(*pvirqfd);
*pvirqfd = NULL;
}
spin_unlock_irqrestore(&virqfd_lock, flags);
flush_workqueue(vfio_irqfd_cleanup_wq);
}
