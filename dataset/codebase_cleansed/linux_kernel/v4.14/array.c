static inline void task_name(struct seq_file *m, struct task_struct *p)
{
char *buf;
size_t size;
char tcomm[sizeof(p->comm)];
int ret;
get_task_comm(tcomm, p);
seq_puts(m, "Name:\t");
size = seq_get_buf(m, &buf);
ret = string_escape_str(tcomm, buf, size, ESCAPE_SPACE | ESCAPE_SPECIAL, "\n\\");
seq_commit(m, ret < size ? ret : -1);
seq_putc(m, '\n');
}
static inline const char *get_task_state(struct task_struct *tsk)
{
BUILD_BUG_ON(1 + ilog2(TASK_REPORT_MAX) != ARRAY_SIZE(task_state_array));
return task_state_array[__get_task_state(tsk)];
}
static inline int get_task_umask(struct task_struct *tsk)
{
struct fs_struct *fs;
int umask = -ENOENT;
task_lock(tsk);
fs = tsk->fs;
if (fs)
umask = fs->umask;
task_unlock(tsk);
return umask;
}
static inline void task_state(struct seq_file *m, struct pid_namespace *ns,
struct pid *pid, struct task_struct *p)
{
struct user_namespace *user_ns = seq_user_ns(m);
struct group_info *group_info;
int g, umask;
struct task_struct *tracer;
const struct cred *cred;
pid_t ppid, tpid = 0, tgid, ngid;
unsigned int max_fds = 0;
rcu_read_lock();
ppid = pid_alive(p) ?
task_tgid_nr_ns(rcu_dereference(p->real_parent), ns) : 0;
tracer = ptrace_parent(p);
if (tracer)
tpid = task_pid_nr_ns(tracer, ns);
tgid = task_tgid_nr_ns(p, ns);
ngid = task_numa_group_id(p);
cred = get_task_cred(p);
umask = get_task_umask(p);
if (umask >= 0)
seq_printf(m, "Umask:\t%#04o\n", umask);
task_lock(p);
if (p->files)
max_fds = files_fdtable(p->files)->max_fds;
task_unlock(p);
rcu_read_unlock();
seq_printf(m, "State:\t%s", get_task_state(p));
seq_put_decimal_ull(m, "\nTgid:\t", tgid);
seq_put_decimal_ull(m, "\nNgid:\t", ngid);
seq_put_decimal_ull(m, "\nPid:\t", pid_nr_ns(pid, ns));
seq_put_decimal_ull(m, "\nPPid:\t", ppid);
seq_put_decimal_ull(m, "\nTracerPid:\t", tpid);
seq_put_decimal_ull(m, "\nUid:\t", from_kuid_munged(user_ns, cred->uid));
seq_put_decimal_ull(m, "\t", from_kuid_munged(user_ns, cred->euid));
seq_put_decimal_ull(m, "\t", from_kuid_munged(user_ns, cred->suid));
seq_put_decimal_ull(m, "\t", from_kuid_munged(user_ns, cred->fsuid));
seq_put_decimal_ull(m, "\nGid:\t", from_kgid_munged(user_ns, cred->gid));
seq_put_decimal_ull(m, "\t", from_kgid_munged(user_ns, cred->egid));
seq_put_decimal_ull(m, "\t", from_kgid_munged(user_ns, cred->sgid));
seq_put_decimal_ull(m, "\t", from_kgid_munged(user_ns, cred->fsgid));
seq_put_decimal_ull(m, "\nFDSize:\t", max_fds);
seq_puts(m, "\nGroups:\t");
group_info = cred->group_info;
for (g = 0; g < group_info->ngroups; g++)
seq_put_decimal_ull(m, g ? " " : "",
from_kgid_munged(user_ns, group_info->gid[g]));
put_cred(cred);
seq_putc(m, ' ');
#ifdef CONFIG_PID_NS
seq_puts(m, "\nNStgid:");
for (g = ns->level; g <= pid->level; g++)
seq_put_decimal_ull(m, "\t", task_tgid_nr_ns(p, pid->numbers[g].ns));
seq_puts(m, "\nNSpid:");
for (g = ns->level; g <= pid->level; g++)
seq_put_decimal_ull(m, "\t", task_pid_nr_ns(p, pid->numbers[g].ns));
seq_puts(m, "\nNSpgid:");
for (g = ns->level; g <= pid->level; g++)
seq_put_decimal_ull(m, "\t", task_pgrp_nr_ns(p, pid->numbers[g].ns));
seq_puts(m, "\nNSsid:");
for (g = ns->level; g <= pid->level; g++)
seq_put_decimal_ull(m, "\t", task_session_nr_ns(p, pid->numbers[g].ns));
#endif
seq_putc(m, '\n');
}
void render_sigset_t(struct seq_file *m, const char *header,
sigset_t *set)
{
int i;
seq_puts(m, header);
i = _NSIG;
do {
int x = 0;
i -= 4;
if (sigismember(set, i+1)) x |= 1;
if (sigismember(set, i+2)) x |= 2;
if (sigismember(set, i+3)) x |= 4;
if (sigismember(set, i+4)) x |= 8;
seq_putc(m, hex_asc[x]);
} while (i >= 4);
seq_putc(m, '\n');
}
static void collect_sigign_sigcatch(struct task_struct *p, sigset_t *ign,
sigset_t *catch)
{
struct k_sigaction *k;
int i;
k = p->sighand->action;
for (i = 1; i <= _NSIG; ++i, ++k) {
if (k->sa.sa_handler == SIG_IGN)
sigaddset(ign, i);
else if (k->sa.sa_handler != SIG_DFL)
sigaddset(catch, i);
}
}
static inline void task_sig(struct seq_file *m, struct task_struct *p)
{
unsigned long flags;
sigset_t pending, shpending, blocked, ignored, caught;
int num_threads = 0;
unsigned long qsize = 0;
unsigned long qlim = 0;
sigemptyset(&pending);
sigemptyset(&shpending);
sigemptyset(&blocked);
sigemptyset(&ignored);
sigemptyset(&caught);
if (lock_task_sighand(p, &flags)) {
pending = p->pending.signal;
shpending = p->signal->shared_pending.signal;
blocked = p->blocked;
collect_sigign_sigcatch(p, &ignored, &caught);
num_threads = get_nr_threads(p);
rcu_read_lock();
qsize = atomic_read(&__task_cred(p)->user->sigpending);
rcu_read_unlock();
qlim = task_rlimit(p, RLIMIT_SIGPENDING);
unlock_task_sighand(p, &flags);
}
seq_put_decimal_ull(m, "Threads:\t", num_threads);
seq_put_decimal_ull(m, "\nSigQ:\t", qsize);
seq_put_decimal_ull(m, "/", qlim);
render_sigset_t(m, "\nSigPnd:\t", &pending);
render_sigset_t(m, "ShdPnd:\t", &shpending);
render_sigset_t(m, "SigBlk:\t", &blocked);
render_sigset_t(m, "SigIgn:\t", &ignored);
render_sigset_t(m, "SigCgt:\t", &caught);
}
static void render_cap_t(struct seq_file *m, const char *header,
kernel_cap_t *a)
{
unsigned __capi;
seq_puts(m, header);
CAP_FOR_EACH_U32(__capi) {
seq_printf(m, "%08x",
a->cap[CAP_LAST_U32 - __capi]);
}
seq_putc(m, '\n');
}
static inline void task_cap(struct seq_file *m, struct task_struct *p)
{
const struct cred *cred;
kernel_cap_t cap_inheritable, cap_permitted, cap_effective,
cap_bset, cap_ambient;
rcu_read_lock();
cred = __task_cred(p);
cap_inheritable = cred->cap_inheritable;
cap_permitted = cred->cap_permitted;
cap_effective = cred->cap_effective;
cap_bset = cred->cap_bset;
cap_ambient = cred->cap_ambient;
rcu_read_unlock();
render_cap_t(m, "CapInh:\t", &cap_inheritable);
render_cap_t(m, "CapPrm:\t", &cap_permitted);
render_cap_t(m, "CapEff:\t", &cap_effective);
render_cap_t(m, "CapBnd:\t", &cap_bset);
render_cap_t(m, "CapAmb:\t", &cap_ambient);
}
static inline void task_seccomp(struct seq_file *m, struct task_struct *p)
{
seq_put_decimal_ull(m, "NoNewPrivs:\t", task_no_new_privs(p));
#ifdef CONFIG_SECCOMP
seq_put_decimal_ull(m, "\nSeccomp:\t", p->seccomp.mode);
#endif
seq_putc(m, '\n');
}
static inline void task_context_switch_counts(struct seq_file *m,
struct task_struct *p)
{
seq_put_decimal_ull(m, "voluntary_ctxt_switches:\t", p->nvcsw);
seq_put_decimal_ull(m, "\nnonvoluntary_ctxt_switches:\t", p->nivcsw);
seq_putc(m, '\n');
}
static void task_cpus_allowed(struct seq_file *m, struct task_struct *task)
{
seq_printf(m, "Cpus_allowed:\t%*pb\n",
cpumask_pr_args(&task->cpus_allowed));
seq_printf(m, "Cpus_allowed_list:\t%*pbl\n",
cpumask_pr_args(&task->cpus_allowed));
}
int proc_pid_status(struct seq_file *m, struct pid_namespace *ns,
struct pid *pid, struct task_struct *task)
{
struct mm_struct *mm = get_task_mm(task);
task_name(m, task);
task_state(m, ns, pid, task);
if (mm) {
task_mem(m, mm);
mmput(mm);
}
task_sig(m, task);
task_cap(m, task);
task_seccomp(m, task);
task_cpus_allowed(m, task);
cpuset_task_status_allowed(m, task);
task_context_switch_counts(m, task);
return 0;
}
static int do_task_stat(struct seq_file *m, struct pid_namespace *ns,
struct pid *pid, struct task_struct *task, int whole)
{
unsigned long vsize, eip, esp, wchan = 0;
int priority, nice;
int tty_pgrp = -1, tty_nr = 0;
sigset_t sigign, sigcatch;
char state;
pid_t ppid = 0, pgid = -1, sid = -1;
int num_threads = 0;
int permitted;
struct mm_struct *mm;
unsigned long long start_time;
unsigned long cmin_flt = 0, cmaj_flt = 0;
unsigned long min_flt = 0, maj_flt = 0;
u64 cutime, cstime, utime, stime;
u64 cgtime, gtime;
unsigned long rsslim = 0;
char tcomm[sizeof(task->comm)];
unsigned long flags;
state = *get_task_state(task);
vsize = eip = esp = 0;
permitted = ptrace_may_access(task, PTRACE_MODE_READ_FSCREDS | PTRACE_MODE_NOAUDIT);
mm = get_task_mm(task);
if (mm) {
vsize = task_vsize(mm);
if (permitted && (task->flags & PF_DUMPCORE)) {
eip = KSTK_EIP(task);
esp = KSTK_ESP(task);
}
}
get_task_comm(tcomm, task);
sigemptyset(&sigign);
sigemptyset(&sigcatch);
cutime = cstime = utime = stime = 0;
cgtime = gtime = 0;
if (lock_task_sighand(task, &flags)) {
struct signal_struct *sig = task->signal;
if (sig->tty) {
struct pid *pgrp = tty_get_pgrp(sig->tty);
tty_pgrp = pid_nr_ns(pgrp, ns);
put_pid(pgrp);
tty_nr = new_encode_dev(tty_devnum(sig->tty));
}
num_threads = get_nr_threads(task);
collect_sigign_sigcatch(task, &sigign, &sigcatch);
cmin_flt = sig->cmin_flt;
cmaj_flt = sig->cmaj_flt;
cutime = sig->cutime;
cstime = sig->cstime;
cgtime = sig->cgtime;
rsslim = ACCESS_ONCE(sig->rlim[RLIMIT_RSS].rlim_cur);
if (whole) {
struct task_struct *t = task;
do {
min_flt += t->min_flt;
maj_flt += t->maj_flt;
gtime += task_gtime(t);
} while_each_thread(task, t);
min_flt += sig->min_flt;
maj_flt += sig->maj_flt;
thread_group_cputime_adjusted(task, &utime, &stime);
gtime += sig->gtime;
}
sid = task_session_nr_ns(task, ns);
ppid = task_tgid_nr_ns(task->real_parent, ns);
pgid = task_pgrp_nr_ns(task, ns);
unlock_task_sighand(task, &flags);
}
int proc_tgid_stat(struct seq_file *m, struct pid_namespace *ns,
struct pid *pid, struct task_struct *task)
{
return do_task_stat(m, ns, pid, task, 1);
}
int proc_pid_statm(struct seq_file *m, struct pid_namespace *ns,
struct pid *pid, struct task_struct *task)
{
unsigned long size = 0, resident = 0, shared = 0, text = 0, data = 0;
struct mm_struct *mm = get_task_mm(task);
if (mm) {
size = task_statm(mm, &shared, &text, &data, &resident);
mmput(mm);
}
seq_put_decimal_ull(m, "", size);
seq_put_decimal_ull(m, " ", resident);
seq_put_decimal_ull(m, " ", shared);
seq_put_decimal_ull(m, " ", text);
seq_put_decimal_ull(m, " ", 0);
seq_put_decimal_ull(m, " ", data);
seq_put_decimal_ull(m, " ", 0);
seq_putc(m, '\n');
return 0;
}
static struct pid *
get_children_pid(struct inode *inode, struct pid *pid_prev, loff_t pos)
{
struct task_struct *start, *task;
struct pid *pid = NULL;
read_lock(&tasklist_lock);
start = pid_task(proc_pid(inode), PIDTYPE_PID);
if (!start)
goto out;
if (pid_prev) {
task = pid_task(pid_prev, PIDTYPE_PID);
if (task && task->real_parent == start &&
!(list_empty(&task->sibling))) {
if (list_is_last(&task->sibling, &start->children))
goto out;
task = list_first_entry(&task->sibling,
struct task_struct, sibling);
pid = get_pid(task_pid(task));
goto out;
}
}
list_for_each_entry(task, &start->children, sibling) {
if (pos-- == 0) {
pid = get_pid(task_pid(task));
break;
}
}
out:
read_unlock(&tasklist_lock);
return pid;
}
static int children_seq_show(struct seq_file *seq, void *v)
{
struct inode *inode = seq->private;
pid_t pid;
pid = pid_nr_ns(v, inode->i_sb->s_fs_info);
seq_printf(seq, "%d ", pid);
return 0;
}
static void *children_seq_start(struct seq_file *seq, loff_t *pos)
{
return get_children_pid(seq->private, NULL, *pos);
}
static void *children_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct pid *pid;
pid = get_children_pid(seq->private, v, *pos + 1);
put_pid(v);
++*pos;
return pid;
}
static void children_seq_stop(struct seq_file *seq, void *v)
{
put_pid(v);
}
static int children_seq_open(struct inode *inode, struct file *file)
{
struct seq_file *m;
int ret;
ret = seq_open(file, &children_seq_ops);
if (ret)
return ret;
m = file->private_data;
m->private = inode;
return ret;
}
int children_seq_release(struct inode *inode, struct file *file)
{
seq_release(inode, file);
return 0;
}
