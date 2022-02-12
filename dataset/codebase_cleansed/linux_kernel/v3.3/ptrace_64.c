static inline int get_stack_long(struct task_struct *task, int offset)
{
unsigned char *stack;
stack = (unsigned char *)(task->thread.uregs);
stack += offset;
return (*((int *)stack));
}
static inline unsigned long
get_fpu_long(struct task_struct *task, unsigned long addr)
{
unsigned long tmp;
struct pt_regs *regs;
regs = (struct pt_regs*)((unsigned char *)task + THREAD_SIZE) - 1;
if (!tsk_used_math(task)) {
if (addr == offsetof(struct user_fpu_struct, fpscr)) {
tmp = FPSCR_INIT;
} else {
tmp = 0xffffffffUL;
}
return tmp;
}
if (last_task_used_math == task) {
enable_fpu();
save_fpu(task);
disable_fpu();
last_task_used_math = 0;
regs->sr |= SR_FD;
}
tmp = ((long *)task->thread.xstate)[addr / sizeof(unsigned long)];
return tmp;
}
static inline int put_stack_long(struct task_struct *task, int offset,
unsigned long data)
{
unsigned char *stack;
stack = (unsigned char *)(task->thread.uregs);
stack += offset;
*(unsigned long *) stack = data;
return 0;
}
static inline int
put_fpu_long(struct task_struct *task, unsigned long addr, unsigned long data)
{
struct pt_regs *regs;
regs = (struct pt_regs*)((unsigned char *)task + THREAD_SIZE) - 1;
if (!tsk_used_math(task)) {
init_fpu(task);
} else if (last_task_used_math == task) {
enable_fpu();
save_fpu(task);
disable_fpu();
last_task_used_math = 0;
regs->sr |= SR_FD;
}
((long *)task->thread.xstate)[addr / sizeof(unsigned long)] = data;
return 0;
}
void user_enable_single_step(struct task_struct *child)
{
struct pt_regs *regs = child->thread.uregs;
regs->sr |= SR_SSTEP;
set_tsk_thread_flag(child, TIF_SINGLESTEP);
}
void user_disable_single_step(struct task_struct *child)
{
struct pt_regs *regs = child->thread.uregs;
regs->sr &= ~SR_SSTEP;
clear_tsk_thread_flag(child, TIF_SINGLESTEP);
}
static int genregs_get(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
const struct pt_regs *regs = task_pt_regs(target);
int ret;
ret = user_regset_copyout(&pos, &count, &kbuf, &ubuf,
&regs->pc,
0, 3 * sizeof(unsigned long long));
if (!ret)
ret = user_regset_copyout(&pos, &count, &kbuf, &ubuf,
regs->regs,
offsetof(struct pt_regs, regs[0]),
63 * sizeof(unsigned long long));
if (!ret)
ret = user_regset_copyout(&pos, &count, &kbuf, &ubuf,
regs->tregs,
offsetof(struct pt_regs, tregs[0]),
8 * sizeof(unsigned long long));
if (!ret)
ret = user_regset_copyout_zero(&pos, &count, &kbuf, &ubuf,
sizeof(struct pt_regs), -1);
return ret;
}
static int genregs_set(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
struct pt_regs *regs = task_pt_regs(target);
int ret;
ret = user_regset_copyin(&pos, &count, &kbuf, &ubuf,
&regs->pc,
0, 3 * sizeof(unsigned long long));
if (!ret && count > 0)
ret = user_regset_copyin(&pos, &count, &kbuf, &ubuf,
regs->regs,
offsetof(struct pt_regs, regs[0]),
63 * sizeof(unsigned long long));
if (!ret && count > 0)
ret = user_regset_copyin(&pos, &count, &kbuf, &ubuf,
regs->tregs,
offsetof(struct pt_regs, tregs[0]),
8 * sizeof(unsigned long long));
if (!ret)
ret = user_regset_copyin_ignore(&pos, &count, &kbuf, &ubuf,
sizeof(struct pt_regs), -1);
return ret;
}
int fpregs_get(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
int ret;
ret = init_fpu(target);
if (ret)
return ret;
return user_regset_copyout(&pos, &count, &kbuf, &ubuf,
&target->thread.xstate->hardfpu, 0, -1);
}
static int fpregs_set(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
int ret;
ret = init_fpu(target);
if (ret)
return ret;
set_stopped_child_used_math(target);
return user_regset_copyin(&pos, &count, &kbuf, &ubuf,
&target->thread.xstate->hardfpu, 0, -1);
}
static int fpregs_active(struct task_struct *target,
const struct user_regset *regset)
{
return tsk_used_math(target) ? regset->n : 0;
}
const struct user_regset_view *task_user_regset_view(struct task_struct *task)
{
return &user_sh64_native_view;
}
long arch_ptrace(struct task_struct *child, long request,
unsigned long addr, unsigned long data)
{
int ret;
unsigned long __user *datap = (unsigned long __user *) data;
switch (request) {
case PTRACE_PEEKUSR: {
unsigned long tmp;
ret = -EIO;
if ((addr & 3) || addr < 0)
break;
if (addr < sizeof(struct pt_regs))
tmp = get_stack_long(child, addr);
else if ((addr >= offsetof(struct user, fpu)) &&
(addr < offsetof(struct user, u_fpvalid))) {
unsigned long index;
ret = init_fpu(child);
if (ret)
break;
index = addr - offsetof(struct user, fpu);
tmp = get_fpu_long(child, index);
} else if (addr == offsetof(struct user, u_fpvalid)) {
tmp = !!tsk_used_math(child);
} else {
break;
}
ret = put_user(tmp, datap);
break;
}
case PTRACE_POKEUSR:
ret = -EIO;
if ((addr & 3) || addr < 0)
break;
if (addr < sizeof(struct pt_regs)) {
if (addr == offsetof (struct pt_regs, sr)+4)
{
ret = 0;
break;
}
if (addr == offsetof (struct pt_regs, sr))
{
long cursr = get_stack_long(child, addr);
data &= ~(SR_MASK);
data |= (cursr & SR_MASK);
}
ret = put_stack_long(child, addr, data);
}
else if ((addr >= offsetof(struct user, fpu)) &&
(addr < offsetof(struct user, u_fpvalid))) {
unsigned long index;
ret = init_fpu(child);
if (ret)
break;
index = addr - offsetof(struct user, fpu);
ret = put_fpu_long(child, index, data);
}
break;
case PTRACE_GETREGS:
return copy_regset_to_user(child, &user_sh64_native_view,
REGSET_GENERAL,
0, sizeof(struct pt_regs),
datap);
case PTRACE_SETREGS:
return copy_regset_from_user(child, &user_sh64_native_view,
REGSET_GENERAL,
0, sizeof(struct pt_regs),
datap);
#ifdef CONFIG_SH_FPU
case PTRACE_GETFPREGS:
return copy_regset_to_user(child, &user_sh64_native_view,
REGSET_FPU,
0, sizeof(struct user_fpu_struct),
datap);
case PTRACE_SETFPREGS:
return copy_regset_from_user(child, &user_sh64_native_view,
REGSET_FPU,
0, sizeof(struct user_fpu_struct),
datap);
#endif
default:
ret = ptrace_request(child, request, addr, data);
break;
}
return ret;
}
asmlinkage int sh64_ptrace(long request, long pid,
unsigned long addr, unsigned long data)
{
#define WPC_DBRMODE 0x0d104008
static unsigned long first_call;
if (!test_and_set_bit(0, &first_call)) {
printk("DBRMODE set to 0 to permit native debugging\n");
poke_real_address_q(WPC_DBRMODE, 0);
}
return sys_ptrace(request, pid, addr, data);
}
static inline int audit_arch(void)
{
int arch = EM_SH;
#ifdef CONFIG_64BIT
arch |= __AUDIT_ARCH_64BIT;
#endif
#ifdef CONFIG_CPU_LITTLE_ENDIAN
arch |= __AUDIT_ARCH_LE;
#endif
return arch;
}
asmlinkage long long do_syscall_trace_enter(struct pt_regs *regs)
{
long long ret = 0;
secure_computing(regs->regs[9]);
if (test_thread_flag(TIF_SYSCALL_TRACE) &&
tracehook_report_syscall_entry(regs))
ret = -1LL;
if (unlikely(test_thread_flag(TIF_SYSCALL_TRACEPOINT)))
trace_sys_enter(regs, regs->regs[9]);
audit_syscall_entry(audit_arch(), regs->regs[1],
regs->regs[2], regs->regs[3],
regs->regs[4], regs->regs[5]);
return ret ?: regs->regs[9];
}
asmlinkage void do_syscall_trace_leave(struct pt_regs *regs)
{
int step;
audit_syscall_exit(regs);
if (unlikely(test_thread_flag(TIF_SYSCALL_TRACEPOINT)))
trace_sys_exit(regs, regs->regs[9]);
step = test_thread_flag(TIF_SINGLESTEP);
if (step || test_thread_flag(TIF_SYSCALL_TRACE))
tracehook_report_syscall_exit(regs, step);
}
asmlinkage void do_single_step(unsigned long long vec, struct pt_regs *regs)
{
local_irq_enable();
regs->sr &= ~SR_SSTEP;
force_sig(SIGTRAP, current);
}
void ptrace_disable(struct task_struct *child)
{
user_disable_single_step(child);
}
