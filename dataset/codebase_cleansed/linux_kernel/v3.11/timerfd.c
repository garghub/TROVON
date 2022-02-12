static inline bool isalarm(struct timerfd_ctx *ctx)
{
return ctx->clockid == CLOCK_REALTIME_ALARM ||
ctx->clockid == CLOCK_BOOTTIME_ALARM;
}
static void timerfd_triggered(struct timerfd_ctx *ctx)
{
unsigned long flags;
spin_lock_irqsave(&ctx->wqh.lock, flags);
ctx->expired = 1;
ctx->ticks++;
wake_up_locked(&ctx->wqh);
spin_unlock_irqrestore(&ctx->wqh.lock, flags);
}
static enum hrtimer_restart timerfd_tmrproc(struct hrtimer *htmr)
{
struct timerfd_ctx *ctx = container_of(htmr, struct timerfd_ctx,
t.tmr);
timerfd_triggered(ctx);
return HRTIMER_NORESTART;
}
static enum alarmtimer_restart timerfd_alarmproc(struct alarm *alarm,
ktime_t now)
{
struct timerfd_ctx *ctx = container_of(alarm, struct timerfd_ctx,
t.alarm);
timerfd_triggered(ctx);
return ALARMTIMER_NORESTART;
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
if ((ctx->clockid == CLOCK_REALTIME ||
ctx->clockid == CLOCK_REALTIME_ALARM) &&
(flags & TFD_TIMER_ABSTIME) && (flags & TFD_TIMER_CANCEL_ON_SET)) {
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
if (isalarm(ctx))
remaining = alarm_expires_remaining(&ctx->t.alarm);
else
remaining = hrtimer_expires_remaining(&ctx->t.tmr);
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
if (isalarm(ctx)) {
alarm_init(&ctx->t.alarm,
ctx->clockid == CLOCK_REALTIME_ALARM ?
ALARM_REALTIME : ALARM_BOOTTIME,
timerfd_alarmproc);
} else {
hrtimer_init(&ctx->t.tmr, clockid, htmode);
hrtimer_set_expires(&ctx->t.tmr, texp);
ctx->t.tmr.function = timerfd_tmrproc;
}
if (texp.tv64 != 0) {
if (isalarm(ctx)) {
if (flags & TFD_TIMER_ABSTIME)
alarm_start(&ctx->t.alarm, texp);
else
alarm_start_relative(&ctx->t.alarm, texp);
} else {
hrtimer_start(&ctx->t.tmr, texp, htmode);
}
if (timerfd_canceled(ctx))
return -ECANCELED;
}
return 0;
}
static int timerfd_release(struct inode *inode, struct file *file)
{
struct timerfd_ctx *ctx = file->private_data;
timerfd_remove_cancel(ctx);
if (isalarm(ctx))
alarm_cancel(&ctx->t.alarm);
else
hrtimer_cancel(&ctx->t.tmr);
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
if (isalarm(ctx)) {
ticks += alarm_forward_now(
&ctx->t.alarm, ctx->tintv) - 1;
alarm_restart(&ctx->t.alarm);
} else {
ticks += hrtimer_forward_now(&ctx->t.tmr,
ctx->tintv) - 1;
hrtimer_restart(&ctx->t.tmr);
}
}
ctx->expired = 0;
ctx->ticks = 0;
}
spin_unlock_irq(&ctx->wqh.lock);
if (ticks)
res = put_user(ticks, (u64 __user *) buf) ? -EFAULT: sizeof(ticks);
return res;
}
static int timerfd_fget(int fd, struct fd *p)
{
struct fd f = fdget(fd);
if (!f.file)
return -EBADF;
if (f.file->f_op != &timerfd_fops) {
fdput(f);
return -EINVAL;
}
*p = f;
return 0;
}
static int do_timerfd_settime(int ufd, int flags,
const struct itimerspec *new,
struct itimerspec *old)
{
struct fd f;
struct timerfd_ctx *ctx;
int ret;
if ((flags & ~TFD_SETTIME_FLAGS) ||
!timespec_valid(&new->it_value) ||
!timespec_valid(&new->it_interval))
return -EINVAL;
ret = timerfd_fget(ufd, &f);
if (ret)
return ret;
ctx = f.file->private_data;
timerfd_setup_cancel(ctx, flags);
for (;;) {
spin_lock_irq(&ctx->wqh.lock);
if (isalarm(ctx)) {
if (alarm_try_to_cancel(&ctx->t.alarm) >= 0)
break;
} else {
if (hrtimer_try_to_cancel(&ctx->t.tmr) >= 0)
break;
}
spin_unlock_irq(&ctx->wqh.lock);
cpu_relax();
}
if (ctx->expired && ctx->tintv.tv64) {
if (isalarm(ctx))
alarm_forward_now(&ctx->t.alarm, ctx->tintv);
else
hrtimer_forward_now(&ctx->t.tmr, ctx->tintv);
}
old->it_value = ktime_to_timespec(timerfd_get_remaining(ctx));
old->it_interval = ktime_to_timespec(ctx->tintv);
ret = timerfd_setup(ctx, flags, new);
spin_unlock_irq(&ctx->wqh.lock);
fdput(f);
return ret;
}
static int do_timerfd_gettime(int ufd, struct itimerspec *t)
{
struct fd f;
struct timerfd_ctx *ctx;
int ret = timerfd_fget(ufd, &f);
if (ret)
return ret;
ctx = f.file->private_data;
spin_lock_irq(&ctx->wqh.lock);
if (ctx->expired && ctx->tintv.tv64) {
ctx->expired = 0;
if (isalarm(ctx)) {
ctx->ticks +=
alarm_forward_now(
&ctx->t.alarm, ctx->tintv) - 1;
alarm_restart(&ctx->t.alarm);
} else {
ctx->ticks +=
hrtimer_forward_now(&ctx->t.tmr, ctx->tintv)
- 1;
hrtimer_restart(&ctx->t.tmr);
}
}
t->it_value = ktime_to_timespec(timerfd_get_remaining(ctx));
t->it_interval = ktime_to_timespec(ctx->tintv);
spin_unlock_irq(&ctx->wqh.lock);
fdput(f);
return 0;
}
