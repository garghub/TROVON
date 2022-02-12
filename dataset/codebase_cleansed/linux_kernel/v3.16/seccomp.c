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
static u32 seccomp_run_filters(int syscall)
{
struct seccomp_filter *f;
struct seccomp_data sd;
u32 ret = SECCOMP_RET_ALLOW;
if (WARN_ON(current->seccomp.filter == NULL))
return SECCOMP_RET_KILL;
populate_seccomp_data(&sd);
for (f = current->seccomp.filter; f; f = f->prev) {
u32 cur_ret = SK_RUN_FILTER(f->prog, (void *)&sd);
if ((cur_ret & SECCOMP_RET_ACTION) < (ret & SECCOMP_RET_ACTION))
ret = cur_ret;
}
return ret;
}
static long seccomp_attach_filter(struct sock_fprog *fprog)
{
struct seccomp_filter *filter;
unsigned long fp_size = fprog->len * sizeof(struct sock_filter);
unsigned long total_insns = fprog->len;
struct sock_filter *fp;
int new_len;
long ret;
if (fprog->len == 0 || fprog->len > BPF_MAXINSNS)
return -EINVAL;
for (filter = current->seccomp.filter; filter; filter = filter->prev)
total_insns += filter->prog->len + 4;
if (total_insns > MAX_INSNS_PER_PATH)
return -ENOMEM;
if (!current->no_new_privs &&
security_capable_noaudit(current_cred(), current_user_ns(),
CAP_SYS_ADMIN) != 0)
return -EACCES;
fp = kzalloc(fp_size, GFP_KERNEL|__GFP_NOWARN);
if (!fp)
return -ENOMEM;
ret = -EFAULT;
if (copy_from_user(fp, fprog->filter, fp_size))
goto free_prog;
ret = sk_chk_filter(fp, fprog->len);
if (ret)
goto free_prog;
ret = seccomp_check_filter(fp, fprog->len);
if (ret)
goto free_prog;
ret = sk_convert_filter(fp, fprog->len, NULL, &new_len);
if (ret)
goto free_prog;
ret = -ENOMEM;
filter = kzalloc(sizeof(struct seccomp_filter),
GFP_KERNEL|__GFP_NOWARN);
if (!filter)
goto free_prog;
filter->prog = kzalloc(sk_filter_size(new_len),
GFP_KERNEL|__GFP_NOWARN);
if (!filter->prog)
goto free_filter;
ret = sk_convert_filter(fp, fprog->len, filter->prog->insnsi, &new_len);
if (ret)
goto free_filter_prog;
kfree(fp);
atomic_set(&filter->usage, 1);
filter->prog->len = new_len;
sk_filter_select_runtime(filter->prog);
filter->prev = current->seccomp.filter;
current->seccomp.filter = filter;
return 0;
free_filter_prog:
kfree(filter->prog);
free_filter:
kfree(filter);
free_prog:
kfree(fp);
return ret;
}
static long seccomp_attach_user_filter(char __user *user_filter)
{
struct sock_fprog fprog;
long ret = -EFAULT;
#ifdef CONFIG_COMPAT
if (is_compat_task()) {
struct compat_sock_fprog fprog32;
if (copy_from_user(&fprog32, user_filter, sizeof(fprog32)))
goto out;
fprog.len = fprog32.len;
fprog.filter = compat_ptr(fprog32.filter);
} else
#endif
if (copy_from_user(&fprog, user_filter, sizeof(fprog)))
goto out;
ret = seccomp_attach_filter(&fprog);
out:
return ret;
}
void get_seccomp_filter(struct task_struct *tsk)
{
struct seccomp_filter *orig = tsk->seccomp.filter;
if (!orig)
return;
atomic_inc(&orig->usage);
}
void put_seccomp_filter(struct task_struct *tsk)
{
struct seccomp_filter *orig = tsk->seccomp.filter;
while (orig && atomic_dec_and_test(&orig->usage)) {
struct seccomp_filter *freeme = orig;
orig = orig->prev;
sk_filter_free(freeme->prog);
kfree(freeme);
}
}
static void seccomp_send_sigsys(int syscall, int reason)
{
struct siginfo info;
memset(&info, 0, sizeof(info));
info.si_signo = SIGSYS;
info.si_code = SYS_SECCOMP;
info.si_call_addr = (void __user *)KSTK_EIP(current);
info.si_errno = reason;
info.si_arch = syscall_get_arch();
info.si_syscall = syscall;
force_sig_info(SIGSYS, &info, current);
}
int __secure_computing(int this_syscall)
{
int mode = current->seccomp.mode;
int exit_sig = 0;
int *syscall;
u32 ret;
switch (mode) {
case SECCOMP_MODE_STRICT:
syscall = mode1_syscalls;
#ifdef CONFIG_COMPAT
if (is_compat_task())
syscall = mode1_syscalls_32;
#endif
do {
if (*syscall == this_syscall)
return 0;
} while (*++syscall);
exit_sig = SIGKILL;
ret = SECCOMP_RET_KILL;
break;
#ifdef CONFIG_SECCOMP_FILTER
case SECCOMP_MODE_FILTER: {
int data;
struct pt_regs *regs = task_pt_regs(current);
ret = seccomp_run_filters(this_syscall);
data = ret & SECCOMP_RET_DATA;
ret &= SECCOMP_RET_ACTION;
switch (ret) {
case SECCOMP_RET_ERRNO:
syscall_set_return_value(current, regs,
-data, 0);
goto skip;
case SECCOMP_RET_TRAP:
syscall_rollback(current, regs);
seccomp_send_sigsys(this_syscall, data);
goto skip;
case SECCOMP_RET_TRACE:
if (!ptrace_event_enabled(current, PTRACE_EVENT_SECCOMP)) {
syscall_set_return_value(current, regs,
-ENOSYS, 0);
goto skip;
}
ptrace_event(PTRACE_EVENT_SECCOMP, data);
if (fatal_signal_pending(current))
break;
if (syscall_get_nr(current, regs) < 0)
goto skip;
return 0;
case SECCOMP_RET_ALLOW:
return 0;
case SECCOMP_RET_KILL:
default:
break;
}
exit_sig = SIGSYS;
break;
}
#endif
default:
BUG();
}
#ifdef SECCOMP_DEBUG
dump_stack();
#endif
audit_seccomp(this_syscall, exit_sig, ret);
do_exit(exit_sig);
#ifdef CONFIG_SECCOMP_FILTER
skip:
audit_seccomp(this_syscall, exit_sig, ret);
#endif
return -1;
}
long prctl_get_seccomp(void)
{
return current->seccomp.mode;
}
long prctl_set_seccomp(unsigned long seccomp_mode, char __user *filter)
{
long ret = -EINVAL;
if (current->seccomp.mode &&
current->seccomp.mode != seccomp_mode)
goto out;
switch (seccomp_mode) {
case SECCOMP_MODE_STRICT:
ret = 0;
#ifdef TIF_NOTSC
disable_TSC();
#endif
break;
#ifdef CONFIG_SECCOMP_FILTER
case SECCOMP_MODE_FILTER:
ret = seccomp_attach_user_filter(filter);
if (ret)
goto out;
break;
#endif
default:
goto out;
}
current->seccomp.mode = seccomp_mode;
set_thread_flag(TIF_SECCOMP);
out:
return ret;
}
