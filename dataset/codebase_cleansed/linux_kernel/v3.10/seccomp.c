static inline u32 get_u32(u64 data, int index)
{
return ((u32 *)&data)[index];
}
u32 seccomp_bpf_load(int off)
{
struct pt_regs *regs = task_pt_regs(current);
if (off == BPF_DATA(nr))
return syscall_get_nr(current, regs);
if (off == BPF_DATA(arch))
return syscall_get_arch(current, regs);
if (off >= BPF_DATA(args[0]) && off < BPF_DATA(args[6])) {
unsigned long value;
int arg = (off - BPF_DATA(args[0])) / sizeof(u64);
int index = !!(off % sizeof(u64));
syscall_get_arguments(current, regs, arg, 1, &value);
return get_u32(value, index);
}
if (off == BPF_DATA(instruction_pointer))
return get_u32(KSTK_EIP(current), 0);
if (off == BPF_DATA(instruction_pointer) + sizeof(u32))
return get_u32(KSTK_EIP(current), 1);
BUG();
}
static int seccomp_check_filter(struct sock_filter *filter, unsigned int flen)
{
int pc;
for (pc = 0; pc < flen; pc++) {
struct sock_filter *ftest = &filter[pc];
u16 code = ftest->code;
u32 k = ftest->k;
switch (code) {
case BPF_S_LD_W_ABS:
ftest->code = BPF_S_ANC_SECCOMP_LD_W;
if (k >= sizeof(struct seccomp_data) || k & 3)
return -EINVAL;
continue;
case BPF_S_LD_W_LEN:
ftest->code = BPF_S_LD_IMM;
ftest->k = sizeof(struct seccomp_data);
continue;
case BPF_S_LDX_W_LEN:
ftest->code = BPF_S_LDX_IMM;
ftest->k = sizeof(struct seccomp_data);
continue;
case BPF_S_RET_K:
case BPF_S_RET_A:
case BPF_S_ALU_ADD_K:
case BPF_S_ALU_ADD_X:
case BPF_S_ALU_SUB_K:
case BPF_S_ALU_SUB_X:
case BPF_S_ALU_MUL_K:
case BPF_S_ALU_MUL_X:
case BPF_S_ALU_DIV_X:
case BPF_S_ALU_AND_K:
case BPF_S_ALU_AND_X:
case BPF_S_ALU_OR_K:
case BPF_S_ALU_OR_X:
case BPF_S_ALU_XOR_K:
case BPF_S_ALU_XOR_X:
case BPF_S_ALU_LSH_K:
case BPF_S_ALU_LSH_X:
case BPF_S_ALU_RSH_K:
case BPF_S_ALU_RSH_X:
case BPF_S_ALU_NEG:
case BPF_S_LD_IMM:
case BPF_S_LDX_IMM:
case BPF_S_MISC_TAX:
case BPF_S_MISC_TXA:
case BPF_S_ALU_DIV_K:
case BPF_S_LD_MEM:
case BPF_S_LDX_MEM:
case BPF_S_ST:
case BPF_S_STX:
case BPF_S_JMP_JA:
case BPF_S_JMP_JEQ_K:
case BPF_S_JMP_JEQ_X:
case BPF_S_JMP_JGE_K:
case BPF_S_JMP_JGE_X:
case BPF_S_JMP_JGT_K:
case BPF_S_JMP_JGT_X:
case BPF_S_JMP_JSET_K:
case BPF_S_JMP_JSET_X:
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
u32 ret = SECCOMP_RET_ALLOW;
if (WARN_ON(current->seccomp.filter == NULL))
return SECCOMP_RET_KILL;
for (f = current->seccomp.filter; f; f = f->prev) {
u32 cur_ret = sk_run_filter(NULL, f->insns);
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
long ret;
if (fprog->len == 0 || fprog->len > BPF_MAXINSNS)
return -EINVAL;
for (filter = current->seccomp.filter; filter; filter = filter->prev)
total_insns += filter->len + 4;
if (total_insns > MAX_INSNS_PER_PATH)
return -ENOMEM;
if (!current->no_new_privs &&
security_capable_noaudit(current_cred(), current_user_ns(),
CAP_SYS_ADMIN) != 0)
return -EACCES;
filter = kzalloc(sizeof(struct seccomp_filter) + fp_size,
GFP_KERNEL|__GFP_NOWARN);
if (!filter)
return -ENOMEM;
atomic_set(&filter->usage, 1);
filter->len = fprog->len;
ret = -EFAULT;
if (copy_from_user(filter->insns, fprog->filter, fp_size))
goto fail;
ret = sk_chk_filter(filter->insns, filter->len);
if (ret)
goto fail;
ret = seccomp_check_filter(filter->insns, filter->len);
if (ret)
goto fail;
filter->prev = current->seccomp.filter;
current->seccomp.filter = filter;
return 0;
fail:
kfree(filter);
return ret;
}
long seccomp_attach_user_filter(char __user *user_filter)
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
info.si_arch = syscall_get_arch(current, task_pt_regs(current));
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
