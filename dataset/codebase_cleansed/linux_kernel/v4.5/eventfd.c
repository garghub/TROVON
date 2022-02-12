__u64 eventfd_signal(struct eventfd_ctx *ctx, __u64 n)
{
unsigned long flags;
spin_lock_irqsave(&ctx->wqh.lock, flags);
if (ULLONG_MAX - ctx->count < n)
n = ULLONG_MAX - ctx->count;
ctx->count += n;
if (waitqueue_active(&ctx->wqh))
wake_up_locked_poll(&ctx->wqh, POLLIN);
spin_unlock_irqrestore(&ctx->wqh.lock, flags);
return n;
}
static void eventfd_free_ctx(struct eventfd_ctx *ctx)
{
kfree(ctx);
}
static void eventfd_free(struct kref *kref)
{
struct eventfd_ctx *ctx = container_of(kref, struct eventfd_ctx, kref);
eventfd_free_ctx(ctx);
}
struct eventfd_ctx *eventfd_ctx_get(struct eventfd_ctx *ctx)
{
kref_get(&ctx->kref);
return ctx;
}
void eventfd_ctx_put(struct eventfd_ctx *ctx)
{
kref_put(&ctx->kref, eventfd_free);
}
static int eventfd_release(struct inode *inode, struct file *file)
{
struct eventfd_ctx *ctx = file->private_data;
wake_up_poll(&ctx->wqh, POLLHUP);
eventfd_ctx_put(ctx);
return 0;
}
static unsigned int eventfd_poll(struct file *file, poll_table *wait)
{
struct eventfd_ctx *ctx = file->private_data;
unsigned int events = 0;
u64 count;
poll_wait(file, &ctx->wqh, wait);
smp_rmb();
count = ctx->count;
if (count > 0)
events |= POLLIN;
if (count == ULLONG_MAX)
events |= POLLERR;
if (ULLONG_MAX - 1 > count)
events |= POLLOUT;
return events;
}
static void eventfd_ctx_do_read(struct eventfd_ctx *ctx, __u64 *cnt)
{
*cnt = (ctx->flags & EFD_SEMAPHORE) ? 1 : ctx->count;
ctx->count -= *cnt;
}
int eventfd_ctx_remove_wait_queue(struct eventfd_ctx *ctx, wait_queue_t *wait,
__u64 *cnt)
{
unsigned long flags;
spin_lock_irqsave(&ctx->wqh.lock, flags);
eventfd_ctx_do_read(ctx, cnt);
__remove_wait_queue(&ctx->wqh, wait);
if (*cnt != 0 && waitqueue_active(&ctx->wqh))
wake_up_locked_poll(&ctx->wqh, POLLOUT);
spin_unlock_irqrestore(&ctx->wqh.lock, flags);
return *cnt != 0 ? 0 : -EAGAIN;
}
ssize_t eventfd_ctx_read(struct eventfd_ctx *ctx, int no_wait, __u64 *cnt)
{
ssize_t res;
DECLARE_WAITQUEUE(wait, current);
spin_lock_irq(&ctx->wqh.lock);
*cnt = 0;
res = -EAGAIN;
if (ctx->count > 0)
res = 0;
else if (!no_wait) {
__add_wait_queue(&ctx->wqh, &wait);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (ctx->count > 0) {
res = 0;
break;
}
if (signal_pending(current)) {
res = -ERESTARTSYS;
break;
}
spin_unlock_irq(&ctx->wqh.lock);
schedule();
spin_lock_irq(&ctx->wqh.lock);
}
__remove_wait_queue(&ctx->wqh, &wait);
__set_current_state(TASK_RUNNING);
}
if (likely(res == 0)) {
eventfd_ctx_do_read(ctx, cnt);
if (waitqueue_active(&ctx->wqh))
wake_up_locked_poll(&ctx->wqh, POLLOUT);
}
spin_unlock_irq(&ctx->wqh.lock);
return res;
}
static ssize_t eventfd_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
struct eventfd_ctx *ctx = file->private_data;
ssize_t res;
__u64 cnt;
if (count < sizeof(cnt))
return -EINVAL;
res = eventfd_ctx_read(ctx, file->f_flags & O_NONBLOCK, &cnt);
if (res < 0)
return res;
return put_user(cnt, (__u64 __user *) buf) ? -EFAULT : sizeof(cnt);
}
static ssize_t eventfd_write(struct file *file, const char __user *buf, size_t count,
loff_t *ppos)
{
struct eventfd_ctx *ctx = file->private_data;
ssize_t res;
__u64 ucnt;
DECLARE_WAITQUEUE(wait, current);
if (count < sizeof(ucnt))
return -EINVAL;
if (copy_from_user(&ucnt, buf, sizeof(ucnt)))
return -EFAULT;
if (ucnt == ULLONG_MAX)
return -EINVAL;
spin_lock_irq(&ctx->wqh.lock);
res = -EAGAIN;
if (ULLONG_MAX - ctx->count > ucnt)
res = sizeof(ucnt);
else if (!(file->f_flags & O_NONBLOCK)) {
__add_wait_queue(&ctx->wqh, &wait);
for (res = 0;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (ULLONG_MAX - ctx->count > ucnt) {
res = sizeof(ucnt);
break;
}
if (signal_pending(current)) {
res = -ERESTARTSYS;
break;
}
spin_unlock_irq(&ctx->wqh.lock);
schedule();
spin_lock_irq(&ctx->wqh.lock);
}
__remove_wait_queue(&ctx->wqh, &wait);
__set_current_state(TASK_RUNNING);
}
if (likely(res > 0)) {
ctx->count += ucnt;
if (waitqueue_active(&ctx->wqh))
wake_up_locked_poll(&ctx->wqh, POLLIN);
}
spin_unlock_irq(&ctx->wqh.lock);
return res;
}
static void eventfd_show_fdinfo(struct seq_file *m, struct file *f)
{
struct eventfd_ctx *ctx = f->private_data;
spin_lock_irq(&ctx->wqh.lock);
seq_printf(m, "eventfd-count: %16llx\n",
(unsigned long long)ctx->count);
spin_unlock_irq(&ctx->wqh.lock);
}
struct file *eventfd_fget(int fd)
{
struct file *file;
file = fget(fd);
if (!file)
return ERR_PTR(-EBADF);
if (file->f_op != &eventfd_fops) {
fput(file);
return ERR_PTR(-EINVAL);
}
return file;
}
struct eventfd_ctx *eventfd_ctx_fdget(int fd)
{
struct eventfd_ctx *ctx;
struct fd f = fdget(fd);
if (!f.file)
return ERR_PTR(-EBADF);
ctx = eventfd_ctx_fileget(f.file);
fdput(f);
return ctx;
}
struct eventfd_ctx *eventfd_ctx_fileget(struct file *file)
{
if (file->f_op != &eventfd_fops)
return ERR_PTR(-EINVAL);
return eventfd_ctx_get(file->private_data);
}
struct file *eventfd_file_create(unsigned int count, int flags)
{
struct file *file;
struct eventfd_ctx *ctx;
BUILD_BUG_ON(EFD_CLOEXEC != O_CLOEXEC);
BUILD_BUG_ON(EFD_NONBLOCK != O_NONBLOCK);
if (flags & ~EFD_FLAGS_SET)
return ERR_PTR(-EINVAL);
ctx = kmalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return ERR_PTR(-ENOMEM);
kref_init(&ctx->kref);
init_waitqueue_head(&ctx->wqh);
ctx->count = count;
ctx->flags = flags;
file = anon_inode_getfile("[eventfd]", &eventfd_fops, ctx,
O_RDWR | (flags & EFD_SHARED_FCNTL_FLAGS));
if (IS_ERR(file))
eventfd_free_ctx(ctx);
return file;
}
