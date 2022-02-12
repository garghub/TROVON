void signalfd_cleanup(struct sighand_struct *sighand)
{
wait_queue_head_t *wqh = &sighand->signalfd_wqh;
if (likely(!waitqueue_active(wqh)))
return;
wake_up_poll(wqh, POLLHUP | POLLFREE);
}
static int signalfd_release(struct inode *inode, struct file *file)
{
kfree(file->private_data);
return 0;
}
static unsigned int signalfd_poll(struct file *file, poll_table *wait)
{
struct signalfd_ctx *ctx = file->private_data;
unsigned int events = 0;
poll_wait(file, &current->sighand->signalfd_wqh, wait);
spin_lock_irq(&current->sighand->siglock);
if (next_signal(&current->pending, &ctx->sigmask) ||
next_signal(&current->signal->shared_pending,
&ctx->sigmask))
events |= POLLIN;
spin_unlock_irq(&current->sighand->siglock);
return events;
}
static int signalfd_copyinfo(struct signalfd_siginfo __user *uinfo,
siginfo_t const *kinfo)
{
long err;
BUILD_BUG_ON(sizeof(struct signalfd_siginfo) != 128);
err = __clear_user(uinfo, sizeof(*uinfo));
err |= __put_user(kinfo->si_signo, &uinfo->ssi_signo);
err |= __put_user(kinfo->si_errno, &uinfo->ssi_errno);
err |= __put_user(kinfo->si_code, &uinfo->ssi_code);
switch (siginfo_layout(kinfo->si_signo, kinfo->si_code)) {
case SIL_KILL:
err |= __put_user(kinfo->si_pid, &uinfo->ssi_pid);
err |= __put_user(kinfo->si_uid, &uinfo->ssi_uid);
break;
case SIL_TIMER:
err |= __put_user(kinfo->si_tid, &uinfo->ssi_tid);
err |= __put_user(kinfo->si_overrun, &uinfo->ssi_overrun);
err |= __put_user((long) kinfo->si_ptr, &uinfo->ssi_ptr);
err |= __put_user(kinfo->si_int, &uinfo->ssi_int);
break;
case SIL_POLL:
err |= __put_user(kinfo->si_band, &uinfo->ssi_band);
err |= __put_user(kinfo->si_fd, &uinfo->ssi_fd);
break;
case SIL_FAULT:
err |= __put_user((long) kinfo->si_addr, &uinfo->ssi_addr);
#ifdef __ARCH_SI_TRAPNO
err |= __put_user(kinfo->si_trapno, &uinfo->ssi_trapno);
#endif
#ifdef BUS_MCEERR_AO
if (kinfo->si_signo == SIGBUS &&
(kinfo->si_code == BUS_MCEERR_AR ||
kinfo->si_code == BUS_MCEERR_AO))
err |= __put_user((short) kinfo->si_addr_lsb,
&uinfo->ssi_addr_lsb);
#endif
break;
case SIL_CHLD:
err |= __put_user(kinfo->si_pid, &uinfo->ssi_pid);
err |= __put_user(kinfo->si_uid, &uinfo->ssi_uid);
err |= __put_user(kinfo->si_status, &uinfo->ssi_status);
err |= __put_user(kinfo->si_utime, &uinfo->ssi_utime);
err |= __put_user(kinfo->si_stime, &uinfo->ssi_stime);
break;
case SIL_RT:
default:
err |= __put_user(kinfo->si_pid, &uinfo->ssi_pid);
err |= __put_user(kinfo->si_uid, &uinfo->ssi_uid);
err |= __put_user((long) kinfo->si_ptr, &uinfo->ssi_ptr);
err |= __put_user(kinfo->si_int, &uinfo->ssi_int);
break;
}
return err ? -EFAULT: sizeof(*uinfo);
}
static ssize_t signalfd_dequeue(struct signalfd_ctx *ctx, siginfo_t *info,
int nonblock)
{
ssize_t ret;
DECLARE_WAITQUEUE(wait, current);
spin_lock_irq(&current->sighand->siglock);
ret = dequeue_signal(current, &ctx->sigmask, info);
switch (ret) {
case 0:
if (!nonblock)
break;
ret = -EAGAIN;
default:
spin_unlock_irq(&current->sighand->siglock);
return ret;
}
add_wait_queue(&current->sighand->signalfd_wqh, &wait);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
ret = dequeue_signal(current, &ctx->sigmask, info);
if (ret != 0)
break;
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
spin_unlock_irq(&current->sighand->siglock);
schedule();
spin_lock_irq(&current->sighand->siglock);
}
spin_unlock_irq(&current->sighand->siglock);
remove_wait_queue(&current->sighand->signalfd_wqh, &wait);
__set_current_state(TASK_RUNNING);
return ret;
}
static ssize_t signalfd_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
struct signalfd_ctx *ctx = file->private_data;
struct signalfd_siginfo __user *siginfo;
int nonblock = file->f_flags & O_NONBLOCK;
ssize_t ret, total = 0;
siginfo_t info;
count /= sizeof(struct signalfd_siginfo);
if (!count)
return -EINVAL;
siginfo = (struct signalfd_siginfo __user *) buf;
do {
ret = signalfd_dequeue(ctx, &info, nonblock);
if (unlikely(ret <= 0))
break;
ret = signalfd_copyinfo(siginfo, &info);
if (ret < 0)
break;
siginfo++;
total += ret;
nonblock = 1;
} while (--count);
return total ? total: ret;
}
static void signalfd_show_fdinfo(struct seq_file *m, struct file *f)
{
struct signalfd_ctx *ctx = f->private_data;
sigset_t sigmask;
sigmask = ctx->sigmask;
signotset(&sigmask);
render_sigset_t(m, "sigmask:\t", &sigmask);
}
