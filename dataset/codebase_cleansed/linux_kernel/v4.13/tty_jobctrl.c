static int is_ignored(int sig)
{
return (sigismember(&current->blocked, sig) ||
current->sighand->action[sig-1].sa.sa_handler == SIG_IGN);
}
int __tty_check_change(struct tty_struct *tty, int sig)
{
unsigned long flags;
struct pid *pgrp, *tty_pgrp;
int ret = 0;
if (current->signal->tty != tty)
return 0;
rcu_read_lock();
pgrp = task_pgrp(current);
spin_lock_irqsave(&tty->ctrl_lock, flags);
tty_pgrp = tty->pgrp;
spin_unlock_irqrestore(&tty->ctrl_lock, flags);
if (tty_pgrp && pgrp != tty->pgrp) {
if (is_ignored(sig)) {
if (sig == SIGTTIN)
ret = -EIO;
} else if (is_current_pgrp_orphaned())
ret = -EIO;
else {
kill_pgrp(pgrp, sig, 1);
set_thread_flag(TIF_SIGPENDING);
ret = -ERESTARTSYS;
}
}
rcu_read_unlock();
if (!tty_pgrp)
tty_warn(tty, "sig=%d, tty->pgrp == NULL!\n", sig);
return ret;
}
int tty_check_change(struct tty_struct *tty)
{
return __tty_check_change(tty, SIGTTOU);
}
void proc_clear_tty(struct task_struct *p)
{
unsigned long flags;
struct tty_struct *tty;
spin_lock_irqsave(&p->sighand->siglock, flags);
tty = p->signal->tty;
p->signal->tty = NULL;
spin_unlock_irqrestore(&p->sighand->siglock, flags);
tty_kref_put(tty);
}
static void __proc_set_tty(struct tty_struct *tty)
{
unsigned long flags;
spin_lock_irqsave(&tty->ctrl_lock, flags);
put_pid(tty->session);
put_pid(tty->pgrp);
tty->pgrp = get_pid(task_pgrp(current));
spin_unlock_irqrestore(&tty->ctrl_lock, flags);
tty->session = get_pid(task_session(current));
if (current->signal->tty) {
tty_debug(tty, "current tty %s not NULL!!\n",
current->signal->tty->name);
tty_kref_put(current->signal->tty);
}
put_pid(current->signal->tty_old_pgrp);
current->signal->tty = tty_kref_get(tty);
current->signal->tty_old_pgrp = NULL;
}
static void proc_set_tty(struct tty_struct *tty)
{
spin_lock_irq(&current->sighand->siglock);
__proc_set_tty(tty);
spin_unlock_irq(&current->sighand->siglock);
}
void tty_open_proc_set_tty(struct file *filp, struct tty_struct *tty)
{
read_lock(&tasklist_lock);
spin_lock_irq(&current->sighand->siglock);
if (current->signal->leader &&
!current->signal->tty &&
tty->session == NULL) {
if (filp->f_mode & FMODE_READ)
__proc_set_tty(tty);
}
spin_unlock_irq(&current->sighand->siglock);
read_unlock(&tasklist_lock);
}
struct tty_struct *get_current_tty(void)
{
struct tty_struct *tty;
unsigned long flags;
spin_lock_irqsave(&current->sighand->siglock, flags);
tty = tty_kref_get(current->signal->tty);
spin_unlock_irqrestore(&current->sighand->siglock, flags);
return tty;
}
void session_clear_tty(struct pid *session)
{
struct task_struct *p;
do_each_pid_task(session, PIDTYPE_SID, p) {
proc_clear_tty(p);
} while_each_pid_task(session, PIDTYPE_SID, p);
}
int tty_signal_session_leader(struct tty_struct *tty, int exit_session)
{
struct task_struct *p;
int refs = 0;
struct pid *tty_pgrp = NULL;
read_lock(&tasklist_lock);
if (tty->session) {
do_each_pid_task(tty->session, PIDTYPE_SID, p) {
spin_lock_irq(&p->sighand->siglock);
if (p->signal->tty == tty) {
p->signal->tty = NULL;
refs++;
}
if (!p->signal->leader) {
spin_unlock_irq(&p->sighand->siglock);
continue;
}
__group_send_sig_info(SIGHUP, SEND_SIG_PRIV, p);
__group_send_sig_info(SIGCONT, SEND_SIG_PRIV, p);
put_pid(p->signal->tty_old_pgrp);
spin_lock(&tty->ctrl_lock);
tty_pgrp = get_pid(tty->pgrp);
if (tty->pgrp)
p->signal->tty_old_pgrp = get_pid(tty->pgrp);
spin_unlock(&tty->ctrl_lock);
spin_unlock_irq(&p->sighand->siglock);
} while_each_pid_task(tty->session, PIDTYPE_SID, p);
}
read_unlock(&tasklist_lock);
if (tty_pgrp) {
if (exit_session)
kill_pgrp(tty_pgrp, SIGHUP, exit_session);
put_pid(tty_pgrp);
}
return refs;
}
void disassociate_ctty(int on_exit)
{
struct tty_struct *tty;
if (!current->signal->leader)
return;
tty = get_current_tty();
if (tty) {
if (on_exit && tty->driver->type != TTY_DRIVER_TYPE_PTY) {
tty_vhangup_session(tty);
} else {
struct pid *tty_pgrp = tty_get_pgrp(tty);
if (tty_pgrp) {
kill_pgrp(tty_pgrp, SIGHUP, on_exit);
if (!on_exit)
kill_pgrp(tty_pgrp, SIGCONT, on_exit);
put_pid(tty_pgrp);
}
}
tty_kref_put(tty);
} else if (on_exit) {
struct pid *old_pgrp;
spin_lock_irq(&current->sighand->siglock);
old_pgrp = current->signal->tty_old_pgrp;
current->signal->tty_old_pgrp = NULL;
spin_unlock_irq(&current->sighand->siglock);
if (old_pgrp) {
kill_pgrp(old_pgrp, SIGHUP, on_exit);
kill_pgrp(old_pgrp, SIGCONT, on_exit);
put_pid(old_pgrp);
}
return;
}
spin_lock_irq(&current->sighand->siglock);
put_pid(current->signal->tty_old_pgrp);
current->signal->tty_old_pgrp = NULL;
tty = tty_kref_get(current->signal->tty);
if (tty) {
unsigned long flags;
spin_lock_irqsave(&tty->ctrl_lock, flags);
put_pid(tty->session);
put_pid(tty->pgrp);
tty->session = NULL;
tty->pgrp = NULL;
spin_unlock_irqrestore(&tty->ctrl_lock, flags);
tty_kref_put(tty);
}
spin_unlock_irq(&current->sighand->siglock);
read_lock(&tasklist_lock);
session_clear_tty(task_session(current));
read_unlock(&tasklist_lock);
}
void no_tty(void)
{
struct task_struct *tsk = current;
disassociate_ctty(0);
proc_clear_tty(tsk);
}
static int tiocsctty(struct tty_struct *tty, struct file *file, int arg)
{
int ret = 0;
tty_lock(tty);
read_lock(&tasklist_lock);
if (current->signal->leader && (task_session(current) == tty->session))
goto unlock;
if (!current->signal->leader || current->signal->tty) {
ret = -EPERM;
goto unlock;
}
if (tty->session) {
if (arg == 1 && capable(CAP_SYS_ADMIN)) {
session_clear_tty(tty->session);
} else {
ret = -EPERM;
goto unlock;
}
}
if ((file->f_mode & FMODE_READ) == 0 && !capable(CAP_SYS_ADMIN)) {
ret = -EPERM;
goto unlock;
}
proc_set_tty(tty);
unlock:
read_unlock(&tasklist_lock);
tty_unlock(tty);
return ret;
}
struct pid *tty_get_pgrp(struct tty_struct *tty)
{
unsigned long flags;
struct pid *pgrp;
spin_lock_irqsave(&tty->ctrl_lock, flags);
pgrp = get_pid(tty->pgrp);
spin_unlock_irqrestore(&tty->ctrl_lock, flags);
return pgrp;
}
static struct pid *session_of_pgrp(struct pid *pgrp)
{
struct task_struct *p;
struct pid *sid = NULL;
p = pid_task(pgrp, PIDTYPE_PGID);
if (p == NULL)
p = pid_task(pgrp, PIDTYPE_PID);
if (p != NULL)
sid = task_session(p);
return sid;
}
static int tiocgpgrp(struct tty_struct *tty, struct tty_struct *real_tty, pid_t __user *p)
{
struct pid *pid;
int ret;
if (tty == real_tty && current->signal->tty != real_tty)
return -ENOTTY;
pid = tty_get_pgrp(real_tty);
ret = put_user(pid_vnr(pid), p);
put_pid(pid);
return ret;
}
static int tiocspgrp(struct tty_struct *tty, struct tty_struct *real_tty, pid_t __user *p)
{
struct pid *pgrp;
pid_t pgrp_nr;
int retval = tty_check_change(real_tty);
if (retval == -EIO)
return -ENOTTY;
if (retval)
return retval;
if (!current->signal->tty ||
(current->signal->tty != real_tty) ||
(real_tty->session != task_session(current)))
return -ENOTTY;
if (get_user(pgrp_nr, p))
return -EFAULT;
if (pgrp_nr < 0)
return -EINVAL;
rcu_read_lock();
pgrp = find_vpid(pgrp_nr);
retval = -ESRCH;
if (!pgrp)
goto out_unlock;
retval = -EPERM;
if (session_of_pgrp(pgrp) != task_session(current))
goto out_unlock;
retval = 0;
spin_lock_irq(&tty->ctrl_lock);
put_pid(real_tty->pgrp);
real_tty->pgrp = get_pid(pgrp);
spin_unlock_irq(&tty->ctrl_lock);
out_unlock:
rcu_read_unlock();
return retval;
}
static int tiocgsid(struct tty_struct *tty, struct tty_struct *real_tty, pid_t __user *p)
{
if (tty == real_tty && current->signal->tty != real_tty)
return -ENOTTY;
if (!real_tty->session)
return -ENOTTY;
return put_user(pid_vnr(real_tty->session), p);
}
long tty_jobctrl_ioctl(struct tty_struct *tty, struct tty_struct *real_tty,
struct file *file, unsigned int cmd, unsigned long arg)
{
void __user *p = (void __user *)arg;
switch (cmd) {
case TIOCNOTTY:
if (current->signal->tty != tty)
return -ENOTTY;
no_tty();
return 0;
case TIOCSCTTY:
return tiocsctty(real_tty, file, arg);
case TIOCGPGRP:
return tiocgpgrp(tty, real_tty, p);
case TIOCSPGRP:
return tiocspgrp(tty, real_tty, p);
case TIOCGSID:
return tiocgsid(tty, real_tty, p);
}
return -ENOIOCTLCMD;
}
