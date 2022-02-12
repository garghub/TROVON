void ptrace_disable(struct task_struct *child)
{
}
static inline long get_reg(struct task_struct *task, int regno)
{
long *addr = (long *)task_pt_regs(task);
if (regno == PT_TSR || regno == PT_CSR)
return 0;
return addr[regno];
}
static inline int put_reg(struct task_struct *task,
int regno,
unsigned long data)
{
unsigned long *addr = (unsigned long *)task_pt_regs(task);
if (regno != PT_TSR && regno != PT_CSR)
addr[regno] = data;
return 0;
}
static int gpr_get(struct task_struct *target,
const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
struct pt_regs *regs = task_pt_regs(target);
return user_regset_copyout(&pos, &count, &kbuf, &ubuf,
regs,
0, sizeof(*regs));
}
const struct user_regset_view *task_user_regset_view(struct task_struct *task)
{
return &user_c6x_native_view;
}
long arch_ptrace(struct task_struct *child, long request,
unsigned long addr, unsigned long data)
{
int ret = 0;
switch (request) {
case PTRACE_POKETEXT:
ret = generic_ptrace_pokedata(child, addr, data);
if (ret == 0 && request == PTRACE_POKETEXT)
flush_icache_range(addr, addr + 4);
break;
default:
ret = ptrace_request(child, request, addr, data);
break;
}
return ret;
}
asmlinkage unsigned long syscall_trace_entry(struct pt_regs *regs)
{
if (tracehook_report_syscall_entry(regs))
return ULONG_MAX;
return regs->b0;
}
asmlinkage void syscall_trace_exit(struct pt_regs *regs)
{
tracehook_report_syscall_exit(regs, 0);
}
