void bacct_add_tsk(struct user_namespace *user_ns,
struct pid_namespace *pid_ns,
struct taskstats *stats, struct task_struct *tsk)
{
const struct cred *tcred;
cputime_t utime, stime, utimescaled, stimescaled;
u64 delta;
BUILD_BUG_ON(TS_COMM_LEN < TASK_COMM_LEN);
delta = ktime_get_ns() - tsk->start_time;
do_div(delta, NSEC_PER_USEC);
stats->ac_etime = delta;
do_div(delta, USEC_PER_SEC);
stats->ac_btime = get_seconds() - delta;
if (thread_group_leader(tsk)) {
stats->ac_exitcode = tsk->exit_code;
if (tsk->flags & PF_FORKNOEXEC)
stats->ac_flag |= AFORK;
}
if (tsk->flags & PF_SUPERPRIV)
stats->ac_flag |= ASU;
if (tsk->flags & PF_DUMPCORE)
stats->ac_flag |= ACORE;
if (tsk->flags & PF_SIGNALED)
stats->ac_flag |= AXSIG;
stats->ac_nice = task_nice(tsk);
stats->ac_sched = tsk->policy;
stats->ac_pid = task_pid_nr_ns(tsk, pid_ns);
rcu_read_lock();
tcred = __task_cred(tsk);
stats->ac_uid = from_kuid_munged(user_ns, tcred->uid);
stats->ac_gid = from_kgid_munged(user_ns, tcred->gid);
stats->ac_ppid = pid_alive(tsk) ?
task_tgid_nr_ns(rcu_dereference(tsk->real_parent), pid_ns) : 0;
rcu_read_unlock();
task_cputime(tsk, &utime, &stime);
stats->ac_utime = cputime_to_usecs(utime);
stats->ac_stime = cputime_to_usecs(stime);
task_cputime_scaled(tsk, &utimescaled, &stimescaled);
stats->ac_utimescaled = cputime_to_usecs(utimescaled);
stats->ac_stimescaled = cputime_to_usecs(stimescaled);
stats->ac_minflt = tsk->min_flt;
stats->ac_majflt = tsk->maj_flt;
strncpy(stats->ac_comm, tsk->comm, sizeof(stats->ac_comm));
}
void xacct_add_tsk(struct taskstats *stats, struct task_struct *p)
{
struct mm_struct *mm;
stats->coremem = p->acct_rss_mem1 * PAGE_SIZE;
do_div(stats->coremem, 1000 * KB);
stats->virtmem = p->acct_vm_mem1 * PAGE_SIZE;
do_div(stats->virtmem, 1000 * KB);
mm = get_task_mm(p);
if (mm) {
stats->hiwater_rss = get_mm_hiwater_rss(mm) * PAGE_SIZE / KB;
stats->hiwater_vm = get_mm_hiwater_vm(mm) * PAGE_SIZE / KB;
mmput(mm);
}
stats->read_char = p->ioac.rchar & KB_MASK;
stats->write_char = p->ioac.wchar & KB_MASK;
stats->read_syscalls = p->ioac.syscr & KB_MASK;
stats->write_syscalls = p->ioac.syscw & KB_MASK;
#ifdef CONFIG_TASK_IO_ACCOUNTING
stats->read_bytes = p->ioac.read_bytes & KB_MASK;
stats->write_bytes = p->ioac.write_bytes & KB_MASK;
stats->cancelled_write_bytes = p->ioac.cancelled_write_bytes & KB_MASK;
#else
stats->read_bytes = 0;
stats->write_bytes = 0;
stats->cancelled_write_bytes = 0;
#endif
}
static void __acct_update_integrals(struct task_struct *tsk,
cputime_t utime, cputime_t stime)
{
cputime_t time, dtime;
u64 delta;
if (!likely(tsk->mm))
return;
time = stime + utime;
dtime = time - tsk->acct_timexpd;
delta = cputime_to_nsecs(dtime);
if (delta < TICK_NSEC)
return;
tsk->acct_timexpd = time;
tsk->acct_rss_mem1 += delta * get_mm_rss(tsk->mm) >> 10;
tsk->acct_vm_mem1 += delta * tsk->mm->total_vm >> 10;
}
void acct_update_integrals(struct task_struct *tsk)
{
cputime_t utime, stime;
unsigned long flags;
local_irq_save(flags);
task_cputime(tsk, &utime, &stime);
__acct_update_integrals(tsk, utime, stime);
local_irq_restore(flags);
}
void acct_account_cputime(struct task_struct *tsk)
{
__acct_update_integrals(tsk, tsk->utime, tsk->stime);
}
void acct_clear_integrals(struct task_struct *tsk)
{
tsk->acct_timexpd = 0;
tsk->acct_rss_mem1 = 0;
tsk->acct_vm_mem1 = 0;
}
