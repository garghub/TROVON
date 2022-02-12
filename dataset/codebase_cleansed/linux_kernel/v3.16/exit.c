static void __unhash_process(struct task_struct *p, bool group_dead)
{
nr_threads--;
detach_pid(p, PIDTYPE_PID);
if (group_dead) {
detach_pid(p, PIDTYPE_PGID);
detach_pid(p, PIDTYPE_SID);
list_del_rcu(&p->tasks);
list_del_init(&p->sibling);
__this_cpu_dec(process_counts);
}
list_del_rcu(&p->thread_group);
list_del_rcu(&p->thread_node);
}
static void __exit_signal(struct task_struct *tsk)
{
struct signal_struct *sig = tsk->signal;
bool group_dead = thread_group_leader(tsk);
struct sighand_struct *sighand;
struct tty_struct *uninitialized_var(tty);
cputime_t utime, stime;
sighand = rcu_dereference_check(tsk->sighand,
lockdep_tasklist_lock_is_held());
spin_lock(&sighand->siglock);
posix_cpu_timers_exit(tsk);
if (group_dead) {
posix_cpu_timers_exit_group(tsk);
tty = sig->tty;
sig->tty = NULL;
} else {
if (unlikely(has_group_leader_pid(tsk)))
posix_cpu_timers_exit_group(tsk);
if (sig->notify_count > 0 && !--sig->notify_count)
wake_up_process(sig->group_exit_task);
if (tsk == sig->curr_target)
sig->curr_target = next_thread(tsk);
task_cputime(tsk, &utime, &stime);
sig->utime += utime;
sig->stime += stime;
sig->gtime += task_gtime(tsk);
sig->min_flt += tsk->min_flt;
sig->maj_flt += tsk->maj_flt;
sig->nvcsw += tsk->nvcsw;
sig->nivcsw += tsk->nivcsw;
sig->inblock += task_io_get_inblock(tsk);
sig->oublock += task_io_get_oublock(tsk);
task_io_accounting_add(&sig->ioac, &tsk->ioac);
sig->sum_sched_runtime += tsk->se.sum_exec_runtime;
}
sig->nr_threads--;
__unhash_process(tsk, group_dead);
flush_sigqueue(&tsk->pending);
tsk->sighand = NULL;
spin_unlock(&sighand->siglock);
__cleanup_sighand(sighand);
clear_tsk_thread_flag(tsk,TIF_SIGPENDING);
if (group_dead) {
flush_sigqueue(&sig->shared_pending);
tty_kref_put(tty);
}
}
static void delayed_put_task_struct(struct rcu_head *rhp)
{
struct task_struct *tsk = container_of(rhp, struct task_struct, rcu);
perf_event_delayed_put(tsk);
trace_sched_process_free(tsk);
put_task_struct(tsk);
}
void release_task(struct task_struct * p)
{
struct task_struct *leader;
int zap_leader;
repeat:
rcu_read_lock();
atomic_dec(&__task_cred(p)->user->processes);
rcu_read_unlock();
proc_flush_task(p);
write_lock_irq(&tasklist_lock);
ptrace_release_task(p);
__exit_signal(p);
zap_leader = 0;
leader = p->group_leader;
if (leader != p && thread_group_empty(leader) && leader->exit_state == EXIT_ZOMBIE) {
zap_leader = do_notify_parent(leader, leader->exit_signal);
if (zap_leader)
leader->exit_state = EXIT_DEAD;
}
write_unlock_irq(&tasklist_lock);
release_thread(p);
call_rcu(&p->rcu, delayed_put_task_struct);
p = leader;
if (unlikely(zap_leader))
goto repeat;
}
struct pid *session_of_pgrp(struct pid *pgrp)
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
static int will_become_orphaned_pgrp(struct pid *pgrp, struct task_struct *ignored_task)
{
struct task_struct *p;
do_each_pid_task(pgrp, PIDTYPE_PGID, p) {
if ((p == ignored_task) ||
(p->exit_state && thread_group_empty(p)) ||
is_global_init(p->real_parent))
continue;
if (task_pgrp(p->real_parent) != pgrp &&
task_session(p->real_parent) == task_session(p))
return 0;
} while_each_pid_task(pgrp, PIDTYPE_PGID, p);
return 1;
}
int is_current_pgrp_orphaned(void)
{
int retval;
read_lock(&tasklist_lock);
retval = will_become_orphaned_pgrp(task_pgrp(current), NULL);
read_unlock(&tasklist_lock);
return retval;
}
static bool has_stopped_jobs(struct pid *pgrp)
{
struct task_struct *p;
do_each_pid_task(pgrp, PIDTYPE_PGID, p) {
if (p->signal->flags & SIGNAL_STOP_STOPPED)
return true;
} while_each_pid_task(pgrp, PIDTYPE_PGID, p);
return false;
}
static void
kill_orphaned_pgrp(struct task_struct *tsk, struct task_struct *parent)
{
struct pid *pgrp = task_pgrp(tsk);
struct task_struct *ignored_task = tsk;
if (!parent)
parent = tsk->real_parent;
else
ignored_task = NULL;
if (task_pgrp(parent) != pgrp &&
task_session(parent) == task_session(tsk) &&
will_become_orphaned_pgrp(pgrp, ignored_task) &&
has_stopped_jobs(pgrp)) {
__kill_pgrp_info(SIGHUP, SEND_SIG_PRIV, pgrp);
__kill_pgrp_info(SIGCONT, SEND_SIG_PRIV, pgrp);
}
}
void mm_update_next_owner(struct mm_struct *mm)
{
struct task_struct *c, *g, *p = current;
retry:
if (mm->owner != p)
return;
if (atomic_read(&mm->mm_users) <= 1) {
mm->owner = NULL;
return;
}
read_lock(&tasklist_lock);
list_for_each_entry(c, &p->children, sibling) {
if (c->mm == mm)
goto assign_new_owner;
}
list_for_each_entry(c, &p->real_parent->children, sibling) {
if (c->mm == mm)
goto assign_new_owner;
}
for_each_process(g) {
if (g->flags & PF_KTHREAD)
continue;
for_each_thread(g, c) {
if (c->mm == mm)
goto assign_new_owner;
if (c->mm)
break;
}
}
read_unlock(&tasklist_lock);
mm->owner = NULL;
return;
assign_new_owner:
BUG_ON(c == p);
get_task_struct(c);
task_lock(c);
read_unlock(&tasklist_lock);
if (c->mm != mm) {
task_unlock(c);
put_task_struct(c);
goto retry;
}
mm->owner = c;
task_unlock(c);
put_task_struct(c);
}
static void exit_mm(struct task_struct * tsk)
{
struct mm_struct *mm = tsk->mm;
struct core_state *core_state;
mm_release(tsk, mm);
if (!mm)
return;
sync_mm_rss(mm);
down_read(&mm->mmap_sem);
core_state = mm->core_state;
if (core_state) {
struct core_thread self;
up_read(&mm->mmap_sem);
self.task = tsk;
self.next = xchg(&core_state->dumper.next, &self);
if (atomic_dec_and_test(&core_state->nr_threads))
complete(&core_state->startup);
for (;;) {
set_task_state(tsk, TASK_UNINTERRUPTIBLE);
if (!self.task)
break;
freezable_schedule();
}
__set_task_state(tsk, TASK_RUNNING);
down_read(&mm->mmap_sem);
}
atomic_inc(&mm->mm_count);
BUG_ON(mm != tsk->active_mm);
task_lock(tsk);
tsk->mm = NULL;
up_read(&mm->mmap_sem);
enter_lazy_tlb(mm, current);
task_unlock(tsk);
mm_update_next_owner(mm);
mmput(mm);
}
static struct task_struct *find_new_reaper(struct task_struct *father)
__releases(&tasklist_lock
void reparent_leader(struct task_struct *father, struct task_struct *p,
struct list_head *dead)
{
list_move_tail(&p->sibling, &p->real_parent->children);
if (p->exit_state == EXIT_DEAD)
return;
if (same_thread_group(p->real_parent, father))
return;
p->exit_signal = SIGCHLD;
if (!p->ptrace &&
p->exit_state == EXIT_ZOMBIE && thread_group_empty(p)) {
if (do_notify_parent(p, p->exit_signal)) {
p->exit_state = EXIT_DEAD;
list_move_tail(&p->sibling, dead);
}
}
kill_orphaned_pgrp(p, father);
}
static void forget_original_parent(struct task_struct *father)
{
struct task_struct *p, *n, *reaper;
LIST_HEAD(dead_children);
write_lock_irq(&tasklist_lock);
exit_ptrace(father);
reaper = find_new_reaper(father);
list_for_each_entry_safe(p, n, &father->children, sibling) {
struct task_struct *t = p;
do {
t->real_parent = reaper;
if (t->parent == father) {
BUG_ON(t->ptrace);
t->parent = t->real_parent;
}
if (t->pdeath_signal)
group_send_sig_info(t->pdeath_signal,
SEND_SIG_NOINFO, t);
} while_each_thread(p, t);
reparent_leader(father, p, &dead_children);
}
void exit_notify(struct task_struct *tsk, int group_dead)
{
bool autoreap;
forget_original_parent(tsk);
write_lock_irq(&tasklist_lock);
if (group_dead)
kill_orphaned_pgrp(tsk->group_leader, NULL);
if (unlikely(tsk->ptrace)) {
int sig = thread_group_leader(tsk) &&
thread_group_empty(tsk) &&
!ptrace_reparented(tsk) ?
tsk->exit_signal : SIGCHLD;
autoreap = do_notify_parent(tsk, sig);
} else if (thread_group_leader(tsk)) {
autoreap = thread_group_empty(tsk) &&
do_notify_parent(tsk, tsk->exit_signal);
} else {
autoreap = true;
}
tsk->exit_state = autoreap ? EXIT_DEAD : EXIT_ZOMBIE;
if (unlikely(tsk->signal->notify_count < 0))
wake_up_process(tsk->signal->group_exit_task);
write_unlock_irq(&tasklist_lock);
if (autoreap)
release_task(tsk);
}
static void check_stack_usage(void)
{
static DEFINE_SPINLOCK(low_water_lock);
static int lowest_to_date = THREAD_SIZE;
unsigned long free;
free = stack_not_used(current);
if (free >= lowest_to_date)
return;
spin_lock(&low_water_lock);
if (free < lowest_to_date) {
printk(KERN_WARNING "%s (%d) used greatest stack depth: "
"%lu bytes left\n",
current->comm, task_pid_nr(current), free);
lowest_to_date = free;
}
spin_unlock(&low_water_lock);
}
static inline void check_stack_usage(void) {}
void do_exit(long code)
{
struct task_struct *tsk = current;
int group_dead;
profile_task_exit(tsk);
WARN_ON(blk_needs_flush_plug(tsk));
if (unlikely(in_interrupt()))
panic("Aiee, killing interrupt handler!");
if (unlikely(!tsk->pid))
panic("Attempted to kill the idle task!");
set_fs(USER_DS);
ptrace_event(PTRACE_EVENT_EXIT, code);
validate_creds_for_do_exit(tsk);
if (unlikely(tsk->flags & PF_EXITING)) {
printk(KERN_ALERT
"Fixing recursive fault but reboot is needed!\n");
tsk->flags |= PF_EXITPIDONE;
set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
}
exit_signals(tsk);
smp_mb();
raw_spin_unlock_wait(&tsk->pi_lock);
if (unlikely(in_atomic()))
printk(KERN_INFO "note: %s[%d] exited with preempt_count %d\n",
current->comm, task_pid_nr(current),
preempt_count());
acct_update_integrals(tsk);
if (tsk->mm)
sync_mm_rss(tsk->mm);
group_dead = atomic_dec_and_test(&tsk->signal->live);
if (group_dead) {
hrtimer_cancel(&tsk->signal->real_timer);
exit_itimers(tsk->signal);
if (tsk->mm)
setmax_mm_hiwater_rss(&tsk->signal->maxrss, tsk->mm);
}
acct_collect(code, group_dead);
if (group_dead)
tty_audit_exit();
audit_free(tsk);
tsk->exit_code = code;
taskstats_exit(tsk, group_dead);
exit_mm(tsk);
if (group_dead)
acct_process();
trace_sched_process_exit(tsk);
exit_sem(tsk);
exit_shm(tsk);
exit_files(tsk);
exit_fs(tsk);
if (group_dead)
disassociate_ctty(1);
exit_task_namespaces(tsk);
exit_task_work(tsk);
exit_thread();
perf_event_exit_task(tsk);
cgroup_exit(tsk);
module_put(task_thread_info(tsk)->exec_domain->module);
flush_ptrace_hw_breakpoint(tsk);
exit_notify(tsk, group_dead);
proc_exit_connector(tsk);
#ifdef CONFIG_NUMA
task_lock(tsk);
mpol_put(tsk->mempolicy);
tsk->mempolicy = NULL;
task_unlock(tsk);
#endif
#ifdef CONFIG_FUTEX
if (unlikely(current->pi_state_cache))
kfree(current->pi_state_cache);
#endif
debug_check_no_locks_held();
tsk->flags |= PF_EXITPIDONE;
if (tsk->io_context)
exit_io_context(tsk);
if (tsk->splice_pipe)
free_pipe_info(tsk->splice_pipe);
if (tsk->task_frag.page)
put_page(tsk->task_frag.page);
validate_creds_for_do_exit(tsk);
check_stack_usage();
preempt_disable();
if (tsk->nr_dirtied)
__this_cpu_add(dirty_throttle_leaks, tsk->nr_dirtied);
exit_rcu();
smp_mb();
raw_spin_unlock_wait(&tsk->pi_lock);
tsk->state = TASK_DEAD;
tsk->flags |= PF_NOFREEZE;
schedule();
BUG();
for (;;)
cpu_relax();
}
void complete_and_exit(struct completion *comp, long code)
{
if (comp)
complete(comp);
do_exit(code);
}
void
do_group_exit(int exit_code)
{
struct signal_struct *sig = current->signal;
BUG_ON(exit_code & 0x80);
if (signal_group_exit(sig))
exit_code = sig->group_exit_code;
else if (!thread_group_empty(current)) {
struct sighand_struct *const sighand = current->sighand;
spin_lock_irq(&sighand->siglock);
if (signal_group_exit(sig))
exit_code = sig->group_exit_code;
else {
sig->group_exit_code = exit_code;
sig->flags = SIGNAL_GROUP_EXIT;
zap_other_threads(current);
}
spin_unlock_irq(&sighand->siglock);
}
do_exit(exit_code);
}
static inline
struct pid *task_pid_type(struct task_struct *task, enum pid_type type)
{
if (type != PIDTYPE_PID)
task = task->group_leader;
return task->pids[type].pid;
}
static int eligible_pid(struct wait_opts *wo, struct task_struct *p)
{
return wo->wo_type == PIDTYPE_MAX ||
task_pid_type(p, wo->wo_type) == wo->wo_pid;
}
static int eligible_child(struct wait_opts *wo, struct task_struct *p)
{
if (!eligible_pid(wo, p))
return 0;
if (((p->exit_signal != SIGCHLD) ^ !!(wo->wo_flags & __WCLONE))
&& !(wo->wo_flags & __WALL))
return 0;
return 1;
}
static int wait_noreap_copyout(struct wait_opts *wo, struct task_struct *p,
pid_t pid, uid_t uid, int why, int status)
{
struct siginfo __user *infop;
int retval = wo->wo_rusage
? getrusage(p, RUSAGE_BOTH, wo->wo_rusage) : 0;
put_task_struct(p);
infop = wo->wo_info;
if (infop) {
if (!retval)
retval = put_user(SIGCHLD, &infop->si_signo);
if (!retval)
retval = put_user(0, &infop->si_errno);
if (!retval)
retval = put_user((short)why, &infop->si_code);
if (!retval)
retval = put_user(pid, &infop->si_pid);
if (!retval)
retval = put_user(uid, &infop->si_uid);
if (!retval)
retval = put_user(status, &infop->si_status);
}
if (!retval)
retval = pid;
return retval;
}
static int wait_task_zombie(struct wait_opts *wo, struct task_struct *p)
{
unsigned long state;
int retval, status, traced;
pid_t pid = task_pid_vnr(p);
uid_t uid = from_kuid_munged(current_user_ns(), task_uid(p));
struct siginfo __user *infop;
if (!likely(wo->wo_flags & WEXITED))
return 0;
if (unlikely(wo->wo_flags & WNOWAIT)) {
int exit_code = p->exit_code;
int why;
get_task_struct(p);
read_unlock(&tasklist_lock);
if ((exit_code & 0x7f) == 0) {
why = CLD_EXITED;
status = exit_code >> 8;
} else {
why = (exit_code & 0x80) ? CLD_DUMPED : CLD_KILLED;
status = exit_code & 0x7f;
}
return wait_noreap_copyout(wo, p, pid, uid, why, status);
}
traced = ptrace_reparented(p);
state = traced && thread_group_leader(p) ? EXIT_TRACE : EXIT_DEAD;
if (cmpxchg(&p->exit_state, EXIT_ZOMBIE, state) != EXIT_ZOMBIE)
return 0;
if (likely(!traced) && thread_group_leader(p)) {
struct signal_struct *psig;
struct signal_struct *sig;
unsigned long maxrss;
cputime_t tgutime, tgstime;
thread_group_cputime_adjusted(p, &tgutime, &tgstime);
spin_lock_irq(&p->real_parent->sighand->siglock);
psig = p->real_parent->signal;
sig = p->signal;
psig->cutime += tgutime + sig->cutime;
psig->cstime += tgstime + sig->cstime;
psig->cgtime += task_gtime(p) + sig->gtime + sig->cgtime;
psig->cmin_flt +=
p->min_flt + sig->min_flt + sig->cmin_flt;
psig->cmaj_flt +=
p->maj_flt + sig->maj_flt + sig->cmaj_flt;
psig->cnvcsw +=
p->nvcsw + sig->nvcsw + sig->cnvcsw;
psig->cnivcsw +=
p->nivcsw + sig->nivcsw + sig->cnivcsw;
psig->cinblock +=
task_io_get_inblock(p) +
sig->inblock + sig->cinblock;
psig->coublock +=
task_io_get_oublock(p) +
sig->oublock + sig->coublock;
maxrss = max(sig->maxrss, sig->cmaxrss);
if (psig->cmaxrss < maxrss)
psig->cmaxrss = maxrss;
task_io_accounting_add(&psig->ioac, &p->ioac);
task_io_accounting_add(&psig->ioac, &sig->ioac);
spin_unlock_irq(&p->real_parent->sighand->siglock);
}
read_unlock(&tasklist_lock);
retval = wo->wo_rusage
? getrusage(p, RUSAGE_BOTH, wo->wo_rusage) : 0;
status = (p->signal->flags & SIGNAL_GROUP_EXIT)
? p->signal->group_exit_code : p->exit_code;
if (!retval && wo->wo_stat)
retval = put_user(status, wo->wo_stat);
infop = wo->wo_info;
if (!retval && infop)
retval = put_user(SIGCHLD, &infop->si_signo);
if (!retval && infop)
retval = put_user(0, &infop->si_errno);
if (!retval && infop) {
int why;
if ((status & 0x7f) == 0) {
why = CLD_EXITED;
status >>= 8;
} else {
why = (status & 0x80) ? CLD_DUMPED : CLD_KILLED;
status &= 0x7f;
}
retval = put_user((short)why, &infop->si_code);
if (!retval)
retval = put_user(status, &infop->si_status);
}
if (!retval && infop)
retval = put_user(pid, &infop->si_pid);
if (!retval && infop)
retval = put_user(uid, &infop->si_uid);
if (!retval)
retval = pid;
if (state == EXIT_TRACE) {
write_lock_irq(&tasklist_lock);
ptrace_unlink(p);
state = EXIT_ZOMBIE;
if (do_notify_parent(p, p->exit_signal))
state = EXIT_DEAD;
p->exit_state = state;
write_unlock_irq(&tasklist_lock);
}
if (state == EXIT_DEAD)
release_task(p);
return retval;
}
static int *task_stopped_code(struct task_struct *p, bool ptrace)
{
if (ptrace) {
if (task_is_stopped_or_traced(p) &&
!(p->jobctl & JOBCTL_LISTENING))
return &p->exit_code;
} else {
if (p->signal->flags & SIGNAL_STOP_STOPPED)
return &p->signal->group_exit_code;
}
return NULL;
}
static int wait_task_stopped(struct wait_opts *wo,
int ptrace, struct task_struct *p)
{
struct siginfo __user *infop;
int retval, exit_code, *p_code, why;
uid_t uid = 0;
pid_t pid;
if (!ptrace && !(wo->wo_flags & WUNTRACED))
return 0;
if (!task_stopped_code(p, ptrace))
return 0;
exit_code = 0;
spin_lock_irq(&p->sighand->siglock);
p_code = task_stopped_code(p, ptrace);
if (unlikely(!p_code))
goto unlock_sig;
exit_code = *p_code;
if (!exit_code)
goto unlock_sig;
if (!unlikely(wo->wo_flags & WNOWAIT))
*p_code = 0;
uid = from_kuid_munged(current_user_ns(), task_uid(p));
unlock_sig:
spin_unlock_irq(&p->sighand->siglock);
if (!exit_code)
return 0;
get_task_struct(p);
pid = task_pid_vnr(p);
why = ptrace ? CLD_TRAPPED : CLD_STOPPED;
read_unlock(&tasklist_lock);
if (unlikely(wo->wo_flags & WNOWAIT))
return wait_noreap_copyout(wo, p, pid, uid, why, exit_code);
retval = wo->wo_rusage
? getrusage(p, RUSAGE_BOTH, wo->wo_rusage) : 0;
if (!retval && wo->wo_stat)
retval = put_user((exit_code << 8) | 0x7f, wo->wo_stat);
infop = wo->wo_info;
if (!retval && infop)
retval = put_user(SIGCHLD, &infop->si_signo);
if (!retval && infop)
retval = put_user(0, &infop->si_errno);
if (!retval && infop)
retval = put_user((short)why, &infop->si_code);
if (!retval && infop)
retval = put_user(exit_code, &infop->si_status);
if (!retval && infop)
retval = put_user(pid, &infop->si_pid);
if (!retval && infop)
retval = put_user(uid, &infop->si_uid);
if (!retval)
retval = pid;
put_task_struct(p);
BUG_ON(!retval);
return retval;
}
static int wait_task_continued(struct wait_opts *wo, struct task_struct *p)
{
int retval;
pid_t pid;
uid_t uid;
if (!unlikely(wo->wo_flags & WCONTINUED))
return 0;
if (!(p->signal->flags & SIGNAL_STOP_CONTINUED))
return 0;
spin_lock_irq(&p->sighand->siglock);
if (!(p->signal->flags & SIGNAL_STOP_CONTINUED)) {
spin_unlock_irq(&p->sighand->siglock);
return 0;
}
if (!unlikely(wo->wo_flags & WNOWAIT))
p->signal->flags &= ~SIGNAL_STOP_CONTINUED;
uid = from_kuid_munged(current_user_ns(), task_uid(p));
spin_unlock_irq(&p->sighand->siglock);
pid = task_pid_vnr(p);
get_task_struct(p);
read_unlock(&tasklist_lock);
if (!wo->wo_info) {
retval = wo->wo_rusage
? getrusage(p, RUSAGE_BOTH, wo->wo_rusage) : 0;
put_task_struct(p);
if (!retval && wo->wo_stat)
retval = put_user(0xffff, wo->wo_stat);
if (!retval)
retval = pid;
} else {
retval = wait_noreap_copyout(wo, p, pid, uid,
CLD_CONTINUED, SIGCONT);
BUG_ON(retval == 0);
}
return retval;
}
static int wait_consider_task(struct wait_opts *wo, int ptrace,
struct task_struct *p)
{
int ret;
if (unlikely(p->exit_state == EXIT_DEAD))
return 0;
ret = eligible_child(wo, p);
if (!ret)
return ret;
ret = security_task_wait(p);
if (unlikely(ret < 0)) {
if (wo->notask_error)
wo->notask_error = ret;
return 0;
}
if (unlikely(p->exit_state == EXIT_TRACE)) {
if (likely(!ptrace))
wo->notask_error = 0;
return 0;
}
if (likely(!ptrace) && unlikely(p->ptrace)) {
if (!ptrace_reparented(p))
ptrace = 1;
}
if (p->exit_state == EXIT_ZOMBIE) {
if (!delay_group_leader(p)) {
if (unlikely(ptrace) || likely(!p->ptrace))
return wait_task_zombie(wo, p);
}
if (likely(!ptrace) || (wo->wo_flags & (WCONTINUED | WEXITED)))
wo->notask_error = 0;
} else {
wo->notask_error = 0;
}
ret = wait_task_stopped(wo, ptrace, p);
if (ret)
return ret;
return wait_task_continued(wo, p);
}
static int do_wait_thread(struct wait_opts *wo, struct task_struct *tsk)
{
struct task_struct *p;
list_for_each_entry(p, &tsk->children, sibling) {
int ret = wait_consider_task(wo, 0, p);
if (ret)
return ret;
}
return 0;
}
static int ptrace_do_wait(struct wait_opts *wo, struct task_struct *tsk)
{
struct task_struct *p;
list_for_each_entry(p, &tsk->ptraced, ptrace_entry) {
int ret = wait_consider_task(wo, 1, p);
if (ret)
return ret;
}
return 0;
}
static int child_wait_callback(wait_queue_t *wait, unsigned mode,
int sync, void *key)
{
struct wait_opts *wo = container_of(wait, struct wait_opts,
child_wait);
struct task_struct *p = key;
if (!eligible_pid(wo, p))
return 0;
if ((wo->wo_flags & __WNOTHREAD) && wait->private != p->parent)
return 0;
return default_wake_function(wait, mode, sync, key);
}
void __wake_up_parent(struct task_struct *p, struct task_struct *parent)
{
__wake_up_sync_key(&parent->signal->wait_chldexit,
TASK_INTERRUPTIBLE, 1, p);
}
static long do_wait(struct wait_opts *wo)
{
struct task_struct *tsk;
int retval;
trace_sched_process_wait(wo->wo_pid);
init_waitqueue_func_entry(&wo->child_wait, child_wait_callback);
wo->child_wait.private = current;
add_wait_queue(&current->signal->wait_chldexit, &wo->child_wait);
repeat:
wo->notask_error = -ECHILD;
if ((wo->wo_type < PIDTYPE_MAX) &&
(!wo->wo_pid || hlist_empty(&wo->wo_pid->tasks[wo->wo_type])))
goto notask;
set_current_state(TASK_INTERRUPTIBLE);
read_lock(&tasklist_lock);
tsk = current;
do {
retval = do_wait_thread(wo, tsk);
if (retval)
goto end;
retval = ptrace_do_wait(wo, tsk);
if (retval)
goto end;
if (wo->wo_flags & __WNOTHREAD)
break;
} while_each_thread(current, tsk);
