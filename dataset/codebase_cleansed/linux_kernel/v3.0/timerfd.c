static enum hrtimer_restart timerfd_tmrproc(struct hrtimer *htmr)
{
struct timerfd_ctx *ctx = container_of(htmr, struct timerfd_ctx, tmr);
unsigned long flags;
spin_lock_irqsave(&ctx->wqh.lock, flags);
ctx->expired = 1;
ctx->ticks++;
wake_up_locked(&ctx->wqh);
spin_unlock_irqrestore(&ctx->wqh.lock, flags);
return HRTIMER_NORESTART;
}
void timerfd_clock_was_set(void)
{
ktime_t moffs = ktime_get_monotonic_offset();
struct timerfd_ctx *ctx;
unsigned long flags;
rcu_read_lock();
list_for_each_entry_rcu(ctx, &cancel_list, clist) {
if (!ctx->might_cancel)
continue;
spin_lock_irqsave(&ctx->wqh.lock, flags);
if (ctx->moffs.tv64 != moffs.tv64) {
ctx->moffs.tv64 = KTIME_MAX;
ctx->ticks++;
wake_up_locked(&ctx->wqh);
}
spin_unlock_irqrestore(&ctx->wqh.lock, flags);
}
rcu_read_unlock();
}
static void timerfd_remove_cancel(struct timerfd_ctx *ctx)
{
if (ctx->might_cancel) {
ctx->might_cancel = false;
spin_lock(&cancel_lock);
list_del_rcu(&ctx->clist);
spin_unlock(&cancel_lock);
}
}
static bool timerfd_canceled(struct timerfd_ctx *ctx)
{
if (!ctx->might_cancel || ctx->moffs.tv64 != KTIME_MAX)
return false;
ctx->moffs = ktime_get_monotonic_offset();
return true;
}
static void timerfd_setup_cancel(struct timerfd_ctx *ctx, int flags)
{
if (ctx->clockid == CLOCK_REALTIME && (flags & TFD_TIMER_ABSTIME) &&
(flags & TFD_TIMER_CANCEL_ON_SET)) {
if (!ctx->might_cancel) {
ctx->might_cancel = true;
spin_lock(&cancel_lock);
list_add_rcu(&ctx->clist, &cancel_list);
spin_unlock(&cancel_lock);
}
} else if (ctx->might_cancel) {
timerfd_remove_cancel(ctx);
}
}
static ktime_t timerfd_get_remaining(struct timerfd_ctx *ctx)
{
ktime_t remaining;
remaining = hrtimer_expires_remaining(&ctx->tmr);
return remaining.tv64 < 0 ? ktime_set(0, 0): remaining;
}
static int timerfd_setup(struct timerfd_ctx *ctx, int flags,
const struct itimerspec *ktmr)
{
enum hrtimer_mode htmode;
ktime_t texp;
int clockid = ctx->clockid;
htmode = (flags & TFD_TIMER_ABSTIME) ?
HRTIMER_MODE_ABS: HRTIMER_MODE_REL;
texp = timespec_to_ktime(ktmr->it_value);
ctx->expired = 0;
ctx->ticks = 0;
ctx->tintv = timespec_to_ktime(ktmr->it_interval);
hrtimer_init(&ctx->tmr, clockid, htmode);
hrtimer_set_expires(&ctx->tmr, texp);
ctx->tmr.function = timerfd_tmrproc;
if (texp.tv64 != 0) {
hrtimer_start(&ctx->tmr, texp, htmode);
if (timerfd_canceled(ctx))
return -ECANCELED;
}
return 0;
}
static int timerfd_release(struct inode *inode, struct file *file)
{
struct timerfd_ctx *ctx = file->private_data;
timerfd_remove_cancel(ctx);
hrtimer_cancel(&ctx->tmr);
kfree_rcu(ctx, rcu);
return 0;
}
static unsigned int timerfd_poll(struct file *file, poll_table *wait)
{
struct timerfd_ctx *ctx = file->private_data;
unsigned int events = 0;
unsigned long flags;
poll_wait(file, &ctx->wqh, wait);
spin_lock_irqsave(&ctx->wqh.lock, flags);
if (ctx->ticks)
events |= POLLIN;
spin_unlock_irqrestore(&ctx->wqh.lock, flags);
return events;
}
static ssize_t timerfd_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
struct timerfd_ctx *ctx = file->private_data;
ssize_t res;
u64 ticks = 0;
if (count < sizeof(ticks))
return -EINVAL;
spin_lock_irq(&ctx->wqh.lock);
if (file->f_flags & O_NONBLOCK)
res = -EAGAIN;
else
res = wait_event_interruptible_locked_irq(ctx->wqh, ctx->ticks);
if (timerfd_canceled(ctx)) {
ctx->ticks = 0;
ctx->expired = 0;
res = -ECANCELED;
}
if (ctx->ticks) {
ticks = ctx->ticks;
if (ctx->expired && ctx->tintv.tv64) {
ticks += hrtimer_forward_now(&ctx->tmr,
ctx->tintv) - 1;
hrtimer_restart(&ctx->tmr);
}
ctx->expired = 0;
ctx->ticks = 0;
}
spin_unlock_irq(&ctx->wqh.lock);
if (ticks)
res = put_user(ticks, (u64 __user *) buf) ? -EFAULT: sizeof(ticks);
return res;
}
static struct file *timerfd_fget(int fd)
{
struct file *file;
file = fget(fd);
if (!file)
return ERR_PTR(-EBADF);
if (file->f_op != &timerfd_fops) {
fput(file);
return ERR_PTR(-EINVAL);
}
return file;
}
