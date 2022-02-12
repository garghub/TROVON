static void populate_seccomp_data(struct seccomp_data *sd)
{
struct task_struct *task = current;
struct pt_regs *regs = task_pt_regs(task);
unsigned long args[6];
sd->nr = syscall_get_nr(task, regs);
sd->arch = syscall_get_arch();
syscall_get_arguments(task, regs, 0, 6, args);
sd->args[0] = args[0];
sd->args[1] = args[1];
sd->args[2] = args[2];
sd->args[3] = args[3];
sd->args[4] = args[4];
sd->args[5] = args[5];
sd->instruction_pointer = KSTK_EIP(task);
}
static int seccomp_check_filter(struct sock_filter *filter, unsigned int flen)
{
int pc;
for (pc = 0; pc < flen; pc++) {
struct sock_filter *ftest = &filter[pc];
u16 code = ftest->code;
u32 k = ftest->k;
switch (code) {
case BPF_LD | BPF_W | BPF_ABS:
ftest->code = BPF_LDX | BPF_W | BPF_ABS;
if (k >= sizeof(struct seccomp_data) || k & 3)
return -EINVAL;
continue;
case BPF_LD | BPF_W | BPF_LEN:
ftest->code = BPF_LD | BPF_IMM;
ftest->k = sizeof(struct seccomp_data);
continue;
case BPF_LDX | BPF_W | BPF_LEN:
ftest->code = BPF_LDX | BPF_IMM;
ftest->k = sizeof(struct seccomp_data);
continue;
case BPF_RET | BPF_K:
case BPF_RET | BPF_A:
case BPF_ALU | BPF_ADD | BPF_K:
case BPF_ALU | BPF_ADD | BPF_X:
case BPF_ALU | BPF_SUB | BPF_K:
case BPF_ALU | BPF_SUB | BPF_X:
case BPF_ALU | BPF_MUL | BPF_K:
case BPF_ALU | BPF_MUL | BPF_X:
case BPF_ALU | BPF_DIV | BPF_K:
case BPF_ALU | BPF_DIV | BPF_X:
case BPF_ALU | BPF_AND | BPF_K:
case BPF_ALU | BPF_AND | BPF_X:
case BPF_ALU | BPF_OR | BPF_K:
case BPF_ALU | BPF_OR | BPF_X:
case BPF_ALU | BPF_XOR | BPF_K:
case BPF_ALU | BPF_XOR | BPF_X:
case BPF_ALU | BPF_LSH | BPF_K:
case BPF_ALU | BPF_LSH | BPF_X:
case BPF_ALU | BPF_RSH | BPF_K:
case BPF_ALU | BPF_RSH | BPF_X:
case BPF_ALU | BPF_NEG:
case BPF_LD | BPF_IMM:
case BPF_LDX | BPF_IMM:
case BPF_MISC | BPF_TAX:
case BPF_MISC | BPF_TXA:
case BPF_LD | BPF_MEM:
case BPF_LDX | BPF_MEM:
case BPF_ST:
case BPF_STX:
case BPF_JMP | BPF_JA:
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JGE | BPF_K:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JSET | BPF_K:
case BPF_JMP | BPF_JSET | BPF_X:
continue;
default:
return -EINVAL;
}
}
return 0;
}
static u32 seccomp_run_filters(const struct seccomp_data *sd,
struct seccomp_filter **match)
{
struct seccomp_data sd_local;
u32 ret = SECCOMP_RET_ALLOW;
struct seccomp_filter *f =
lockless_dereference(current->seccomp.filter);
if (unlikely(WARN_ON(f == NULL)))
return SECCOMP_RET_KILL_PROCESS;
if (!sd) {
populate_seccomp_data(&sd_local);
sd = &sd_local;
}
for (; f; f = f->prev) {
u32 cur_ret = BPF_PROG_RUN(f->prog, sd);
if (ACTION_ONLY(cur_ret) < ACTION_ONLY(ret)) {
ret = cur_ret;
*match = f;
}
}
return ret;
}
static inline bool seccomp_may_assign_mode(unsigned long seccomp_mode)
{
assert_spin_locked(&current->sighand->siglock);
if (current->seccomp.mode && current->seccomp.mode != seccomp_mode)
return false;
return true;
}
static inline void seccomp_assign_mode(struct task_struct *task,
unsigned long seccomp_mode)
{
assert_spin_locked(&task->sighand->siglock);
task->seccomp.mode = seccomp_mode;
smp_mb__before_atomic();
set_tsk_thread_flag(task, TIF_SECCOMP);
}
static int is_ancestor(struct seccomp_filter *parent,
struct seccomp_filter *child)
{
if (parent == NULL)
return 1;
for (; child; child = child->prev)
if (child == parent)
return 1;
return 0;
}
static inline pid_t seccomp_can_sync_threads(void)
{
struct task_struct *thread, *caller;
BUG_ON(!mutex_is_locked(&current->signal->cred_guard_mutex));
assert_spin_locked(&current->sighand->siglock);
caller = current;
for_each_thread(caller, thread) {
pid_t failed;
if (thread == caller)
continue;
if (thread->seccomp.mode == SECCOMP_MODE_DISABLED ||
(thread->seccomp.mode == SECCOMP_MODE_FILTER &&
is_ancestor(thread->seccomp.filter,
caller->seccomp.filter)))
continue;
failed = task_pid_vnr(thread);
if (unlikely(WARN_ON(failed == 0)))
failed = -ESRCH;
return failed;
}
return 0;
}
static inline void seccomp_sync_threads(void)
{
struct task_struct *thread, *caller;
BUG_ON(!mutex_is_locked(&current->signal->cred_guard_mutex));
assert_spin_locked(&current->sighand->siglock);
caller = current;
for_each_thread(caller, thread) {
if (thread == caller)
continue;
get_seccomp_filter(caller);
put_seccomp_filter(thread);
smp_store_release(&thread->seccomp.filter,
caller->seccomp.filter);
if (task_no_new_privs(caller))
task_set_no_new_privs(thread);
if (thread->seccomp.mode == SECCOMP_MODE_DISABLED)
seccomp_assign_mode(thread, SECCOMP_MODE_FILTER);
}
}
static struct seccomp_filter *seccomp_prepare_filter(struct sock_fprog *fprog)
{
struct seccomp_filter *sfilter;
int ret;
const bool save_orig = IS_ENABLED(CONFIG_CHECKPOINT_RESTORE);
if (fprog->len == 0 || fprog->len > BPF_MAXINSNS)
return ERR_PTR(-EINVAL);
BUG_ON(INT_MAX / fprog->len < sizeof(struct sock_filter));
if (!task_no_new_privs(current) &&
security_capable_noaudit(current_cred(), current_user_ns(),
CAP_SYS_ADMIN) != 0)
return ERR_PTR(-EACCES);
sfilter = kzalloc(sizeof(*sfilter), GFP_KERNEL | __GFP_NOWARN);
if (!sfilter)
return ERR_PTR(-ENOMEM);
ret = bpf_prog_create_from_user(&sfilter->prog, fprog,
seccomp_check_filter, save_orig);
if (ret < 0) {
kfree(sfilter);
return ERR_PTR(ret);
}
refcount_set(&sfilter->usage, 1);
return sfilter;
}
static struct seccomp_filter *
seccomp_prepare_user_filter(const char __user *user_filter)
{
struct sock_fprog fprog;
struct seccomp_filter *filter = ERR_PTR(-EFAULT);
#ifdef CONFIG_COMPAT
if (in_compat_syscall()) {
struct compat_sock_fprog fprog32;
if (copy_from_user(&fprog32, user_filter, sizeof(fprog32)))
goto out;
fprog.len = fprog32.len;
fprog.filter = compat_ptr(fprog32.filter);
} else
#endif
if (copy_from_user(&fprog, user_filter, sizeof(fprog)))
goto out;
filter = seccomp_prepare_filter(&fprog);
out:
return filter;
}
static long seccomp_attach_filter(unsigned int flags,
struct seccomp_filter *filter)
{
unsigned long total_insns;
struct seccomp_filter *walker;
assert_spin_locked(&current->sighand->siglock);
total_insns = filter->prog->len;
for (walker = current->seccomp.filter; walker; walker = walker->prev)
total_insns += walker->prog->len + 4;
if (total_insns > MAX_INSNS_PER_PATH)
return -ENOMEM;
if (flags & SECCOMP_FILTER_FLAG_TSYNC) {
int ret;
ret = seccomp_can_sync_threads();
if (ret)
return ret;
}
if (flags & SECCOMP_FILTER_FLAG_LOG)
filter->log = true;
filter->prev = current->seccomp.filter;
current->seccomp.filter = filter;
if (flags & SECCOMP_FILTER_FLAG_TSYNC)
seccomp_sync_threads();
return 0;
}
static void __get_seccomp_filter(struct seccomp_filter *filter)
{
refcount_inc(&filter->usage);
}
void get_seccomp_filter(struct task_struct *tsk)
{
struct seccomp_filter *orig = tsk->seccomp.filter;
if (!orig)
return;
__get_seccomp_filter(orig);
}
static inline void seccomp_filter_free(struct seccomp_filter *filter)
{
if (filter) {
bpf_prog_destroy(filter->prog);
kfree(filter);
}
}
static void __put_seccomp_filter(struct seccomp_filter *orig)
{
while (orig && refcount_dec_and_test(&orig->usage)) {
struct seccomp_filter *freeme = orig;
orig = orig->prev;
seccomp_filter_free(freeme);
}
}
void put_seccomp_filter(struct task_struct *tsk)
{
__put_seccomp_filter(tsk->seccomp.filter);
}
static void seccomp_init_siginfo(siginfo_t *info, int syscall, int reason)
{
memset(info, 0, sizeof(*info));
info->si_signo = SIGSYS;
info->si_code = SYS_SECCOMP;
info->si_call_addr = (void __user *)KSTK_EIP(current);
info->si_errno = reason;
info->si_arch = syscall_get_arch();
info->si_syscall = syscall;
}
static void seccomp_send_sigsys(int syscall, int reason)
{
struct siginfo info;
seccomp_init_siginfo(&info, syscall, reason);
force_sig_info(SIGSYS, &info, current);
}
static inline void seccomp_log(unsigned long syscall, long signr, u32 action,
bool requested)
{
bool log = false;
switch (action) {
case SECCOMP_RET_ALLOW:
break;
case SECCOMP_RET_TRAP:
log = requested && seccomp_actions_logged & SECCOMP_LOG_TRAP;
break;
case SECCOMP_RET_ERRNO:
log = requested && seccomp_actions_logged & SECCOMP_LOG_ERRNO;
break;
case SECCOMP_RET_TRACE:
log = requested && seccomp_actions_logged & SECCOMP_LOG_TRACE;
break;
case SECCOMP_RET_LOG:
log = seccomp_actions_logged & SECCOMP_LOG_LOG;
break;
case SECCOMP_RET_KILL_THREAD:
log = seccomp_actions_logged & SECCOMP_LOG_KILL_THREAD;
break;
case SECCOMP_RET_KILL_PROCESS:
default:
log = seccomp_actions_logged & SECCOMP_LOG_KILL_PROCESS;
}
if (log)
return __audit_seccomp(syscall, signr, action);
return audit_seccomp(syscall, signr, action);
}
static void __secure_computing_strict(int this_syscall)
{
const int *syscall_whitelist = mode1_syscalls;
#ifdef CONFIG_COMPAT
if (in_compat_syscall())
syscall_whitelist = get_compat_mode1_syscalls();
#endif
do {
if (*syscall_whitelist == this_syscall)
return;
} while (*++syscall_whitelist);
#ifdef SECCOMP_DEBUG
dump_stack();
#endif
seccomp_log(this_syscall, SIGKILL, SECCOMP_RET_KILL_THREAD, true);
do_exit(SIGKILL);
}
void secure_computing_strict(int this_syscall)
{
int mode = current->seccomp.mode;
if (IS_ENABLED(CONFIG_CHECKPOINT_RESTORE) &&
unlikely(current->ptrace & PT_SUSPEND_SECCOMP))
return;
if (mode == SECCOMP_MODE_DISABLED)
return;
else if (mode == SECCOMP_MODE_STRICT)
__secure_computing_strict(this_syscall);
else
BUG();
}
static int __seccomp_filter(int this_syscall, const struct seccomp_data *sd,
const bool recheck_after_trace)
{
u32 filter_ret, action;
struct seccomp_filter *match = NULL;
int data;
rmb();
filter_ret = seccomp_run_filters(sd, &match);
data = filter_ret & SECCOMP_RET_DATA;
action = filter_ret & SECCOMP_RET_ACTION_FULL;
switch (action) {
case SECCOMP_RET_ERRNO:
if (data > MAX_ERRNO)
data = MAX_ERRNO;
syscall_set_return_value(current, task_pt_regs(current),
-data, 0);
goto skip;
case SECCOMP_RET_TRAP:
syscall_rollback(current, task_pt_regs(current));
seccomp_send_sigsys(this_syscall, data);
goto skip;
case SECCOMP_RET_TRACE:
if (recheck_after_trace)
return 0;
if (!ptrace_event_enabled(current, PTRACE_EVENT_SECCOMP)) {
syscall_set_return_value(current,
task_pt_regs(current),
-ENOSYS, 0);
goto skip;
}
ptrace_event(PTRACE_EVENT_SECCOMP, data);
if (fatal_signal_pending(current))
goto skip;
this_syscall = syscall_get_nr(current, task_pt_regs(current));
if (this_syscall < 0)
goto skip;
if (__seccomp_filter(this_syscall, NULL, true))
return -1;
return 0;
case SECCOMP_RET_LOG:
seccomp_log(this_syscall, 0, action, true);
return 0;
case SECCOMP_RET_ALLOW:
return 0;
case SECCOMP_RET_KILL_THREAD:
case SECCOMP_RET_KILL_PROCESS:
default:
seccomp_log(this_syscall, SIGSYS, action, true);
if (action == SECCOMP_RET_KILL_PROCESS ||
get_nr_threads(current) == 1) {
siginfo_t info;
syscall_rollback(current, task_pt_regs(current));
seccomp_init_siginfo(&info, this_syscall, data);
do_coredump(&info);
}
if (action == SECCOMP_RET_KILL_PROCESS)
do_group_exit(SIGSYS);
else
do_exit(SIGSYS);
}
unreachable();
skip:
seccomp_log(this_syscall, 0, action, match ? match->log : false);
return -1;
}
static int __seccomp_filter(int this_syscall, const struct seccomp_data *sd,
const bool recheck_after_trace)
{
BUG();
}
int __secure_computing(const struct seccomp_data *sd)
{
int mode = current->seccomp.mode;
int this_syscall;
if (IS_ENABLED(CONFIG_CHECKPOINT_RESTORE) &&
unlikely(current->ptrace & PT_SUSPEND_SECCOMP))
return 0;
this_syscall = sd ? sd->nr :
syscall_get_nr(current, task_pt_regs(current));
switch (mode) {
case SECCOMP_MODE_STRICT:
__secure_computing_strict(this_syscall);
return 0;
case SECCOMP_MODE_FILTER:
return __seccomp_filter(this_syscall, sd, false);
default:
BUG();
}
}
long prctl_get_seccomp(void)
{
return current->seccomp.mode;
}
static long seccomp_set_mode_strict(void)
{
const unsigned long seccomp_mode = SECCOMP_MODE_STRICT;
long ret = -EINVAL;
spin_lock_irq(&current->sighand->siglock);
if (!seccomp_may_assign_mode(seccomp_mode))
goto out;
#ifdef TIF_NOTSC
disable_TSC();
#endif
seccomp_assign_mode(current, seccomp_mode);
ret = 0;
out:
spin_unlock_irq(&current->sighand->siglock);
return ret;
}
static long seccomp_set_mode_filter(unsigned int flags,
const char __user *filter)
{
const unsigned long seccomp_mode = SECCOMP_MODE_FILTER;
struct seccomp_filter *prepared = NULL;
long ret = -EINVAL;
if (flags & ~SECCOMP_FILTER_FLAG_MASK)
return -EINVAL;
prepared = seccomp_prepare_user_filter(filter);
if (IS_ERR(prepared))
return PTR_ERR(prepared);
if (flags & SECCOMP_FILTER_FLAG_TSYNC &&
mutex_lock_killable(&current->signal->cred_guard_mutex))
goto out_free;
spin_lock_irq(&current->sighand->siglock);
if (!seccomp_may_assign_mode(seccomp_mode))
goto out;
ret = seccomp_attach_filter(flags, prepared);
if (ret)
goto out;
prepared = NULL;
seccomp_assign_mode(current, seccomp_mode);
out:
spin_unlock_irq(&current->sighand->siglock);
if (flags & SECCOMP_FILTER_FLAG_TSYNC)
mutex_unlock(&current->signal->cred_guard_mutex);
out_free:
seccomp_filter_free(prepared);
return ret;
}
static inline long seccomp_set_mode_filter(unsigned int flags,
const char __user *filter)
{
return -EINVAL;
}
static long seccomp_get_action_avail(const char __user *uaction)
{
u32 action;
if (copy_from_user(&action, uaction, sizeof(action)))
return -EFAULT;
switch (action) {
case SECCOMP_RET_KILL_PROCESS:
case SECCOMP_RET_KILL_THREAD:
case SECCOMP_RET_TRAP:
case SECCOMP_RET_ERRNO:
case SECCOMP_RET_TRACE:
case SECCOMP_RET_LOG:
case SECCOMP_RET_ALLOW:
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static long do_seccomp(unsigned int op, unsigned int flags,
const char __user *uargs)
{
switch (op) {
case SECCOMP_SET_MODE_STRICT:
if (flags != 0 || uargs != NULL)
return -EINVAL;
return seccomp_set_mode_strict();
case SECCOMP_SET_MODE_FILTER:
return seccomp_set_mode_filter(flags, uargs);
case SECCOMP_GET_ACTION_AVAIL:
if (flags != 0)
return -EINVAL;
return seccomp_get_action_avail(uargs);
default:
return -EINVAL;
}
}
long prctl_set_seccomp(unsigned long seccomp_mode, char __user *filter)
{
unsigned int op;
char __user *uargs;
switch (seccomp_mode) {
case SECCOMP_MODE_STRICT:
op = SECCOMP_SET_MODE_STRICT;
uargs = NULL;
break;
case SECCOMP_MODE_FILTER:
op = SECCOMP_SET_MODE_FILTER;
uargs = filter;
break;
default:
return -EINVAL;
}
return do_seccomp(op, 0, uargs);
}
long seccomp_get_filter(struct task_struct *task, unsigned long filter_off,
void __user *data)
{
struct seccomp_filter *filter;
struct sock_fprog_kern *fprog;
long ret;
unsigned long count = 0;
if (!capable(CAP_SYS_ADMIN) ||
current->seccomp.mode != SECCOMP_MODE_DISABLED) {
return -EACCES;
}
spin_lock_irq(&task->sighand->siglock);
if (task->seccomp.mode != SECCOMP_MODE_FILTER) {
ret = -EINVAL;
goto out;
}
filter = task->seccomp.filter;
while (filter) {
filter = filter->prev;
count++;
}
if (filter_off >= count) {
ret = -ENOENT;
goto out;
}
count -= filter_off;
filter = task->seccomp.filter;
while (filter && count > 1) {
filter = filter->prev;
count--;
}
if (WARN_ON(count != 1 || !filter)) {
ret = -ENOENT;
goto out;
}
fprog = filter->prog->orig_prog;
if (!fprog) {
ret = -EMEDIUMTYPE;
goto out;
}
ret = fprog->len;
if (!data)
goto out;
__get_seccomp_filter(filter);
spin_unlock_irq(&task->sighand->siglock);
if (copy_to_user(data, fprog->filter, bpf_classic_proglen(fprog)))
ret = -EFAULT;
__put_seccomp_filter(filter);
return ret;
out:
spin_unlock_irq(&task->sighand->siglock);
return ret;
}
static bool seccomp_names_from_actions_logged(char *names, size_t size,
u32 actions_logged)
{
const struct seccomp_log_name *cur;
bool append_space = false;
for (cur = seccomp_log_names; cur->name && size; cur++) {
ssize_t ret;
if (!(actions_logged & cur->log))
continue;
if (append_space) {
ret = strscpy(names, " ", size);
if (ret < 0)
return false;
names += ret;
size -= ret;
} else
append_space = true;
ret = strscpy(names, cur->name, size);
if (ret < 0)
return false;
names += ret;
size -= ret;
}
return true;
}
static bool seccomp_action_logged_from_name(u32 *action_logged,
const char *name)
{
const struct seccomp_log_name *cur;
for (cur = seccomp_log_names; cur->name; cur++) {
if (!strcmp(cur->name, name)) {
*action_logged = cur->log;
return true;
}
}
return false;
}
static bool seccomp_actions_logged_from_names(u32 *actions_logged, char *names)
{
char *name;
*actions_logged = 0;
while ((name = strsep(&names, " ")) && *name) {
u32 action_logged = 0;
if (!seccomp_action_logged_from_name(&action_logged, name))
return false;
*actions_logged |= action_logged;
}
return true;
}
static int seccomp_actions_logged_handler(struct ctl_table *ro_table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
char names[sizeof(seccomp_actions_avail)];
struct ctl_table table;
int ret;
if (write && !capable(CAP_SYS_ADMIN))
return -EPERM;
memset(names, 0, sizeof(names));
if (!write) {
if (!seccomp_names_from_actions_logged(names, sizeof(names),
seccomp_actions_logged))
return -EINVAL;
}
table = *ro_table;
table.data = names;
table.maxlen = sizeof(names);
ret = proc_dostring(&table, write, buffer, lenp, ppos);
if (ret)
return ret;
if (write) {
u32 actions_logged;
if (!seccomp_actions_logged_from_names(&actions_logged,
table.data))
return -EINVAL;
if (actions_logged & SECCOMP_LOG_ALLOW)
return -EINVAL;
seccomp_actions_logged = actions_logged;
}
return 0;
}
static int __init seccomp_sysctl_init(void)
{
struct ctl_table_header *hdr;
hdr = register_sysctl_paths(seccomp_sysctl_path, seccomp_sysctl_table);
if (!hdr)
pr_warn("seccomp: sysctl registration failed\n");
else
kmemleak_not_leak(hdr);
return 0;
}
