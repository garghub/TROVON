static inline long get_reg(struct task_struct *task, int regno)
{
unsigned long *addr;
if (regno == PT_USP)
addr = &task->thread.usp;
else if (regno < ARRAY_SIZE(regoff))
addr = (unsigned long *)(task->thread.esp0 + regoff[regno]);
else
return 0;
return *addr;
}
static inline int put_reg(struct task_struct *task, int regno,
unsigned long data)
{
unsigned long *addr;
if (regno == PT_USP)
addr = &task->thread.usp;
else if (regno < ARRAY_SIZE(regoff))
addr = (unsigned long *) (task->thread.esp0 + regoff[regno]);
else
return -1;
*addr = data;
return 0;
}
void user_enable_single_step(struct task_struct *task)
{
unsigned long srflags;
srflags = get_reg(task, PT_SR) | (TRACE_BITS << 16);
put_reg(task, PT_SR, srflags);
}
void user_disable_single_step(struct task_struct *task)
{
unsigned long srflags;
srflags = get_reg(task, PT_SR) & ~(TRACE_BITS << 16);
put_reg(task, PT_SR, srflags);
}
void ptrace_disable(struct task_struct *child)
{
user_disable_single_step(child);
}
long arch_ptrace(struct task_struct *child, long request,
unsigned long addr, unsigned long data)
{
int ret;
int regno = addr >> 2;
unsigned long __user *datap = (unsigned long __user *) data;
switch (request) {
case PTRACE_PEEKUSR: {
unsigned long tmp;
ret = -EIO;
if ((addr & 3) || addr > sizeof(struct user) - 3)
break;
tmp = 0;
ret = -EIO;
if (regno < 19) {
tmp = get_reg(child, regno);
if (regno == PT_SR)
tmp >>= 16;
} else if (regno >= 21 && regno < 49) {
tmp = child->thread.fp[regno - 21];
} else if (regno == 49) {
tmp = child->mm->start_code;
} else if (regno == 50) {
tmp = child->mm->start_data;
} else if (regno == 51) {
tmp = child->mm->end_code;
} else
break;
ret = put_user(tmp, datap);
break;
}
case PTRACE_POKEUSR:
ret = -EIO;
if ((addr & 3) || addr > sizeof(struct user) - 3)
break;
if (regno == PT_SR) {
data &= SR_MASK;
data <<= 16;
data |= get_reg(child, PT_SR) & ~(SR_MASK << 16);
}
if (regno < 19) {
if (put_reg(child, regno, data))
break;
ret = 0;
break;
}
if (regno >= 21 && regno < 48)
{
child->thread.fp[regno - 21] = data;
ret = 0;
}
break;
case PTRACE_GETREGS: {
int i;
unsigned long tmp;
for (i = 0; i < 19; i++) {
tmp = get_reg(child, i);
if (i == PT_SR)
tmp >>= 16;
if (put_user(tmp, datap)) {
ret = -EFAULT;
break;
}
datap++;
}
ret = 0;
break;
}
case PTRACE_SETREGS: {
int i;
unsigned long tmp;
for (i = 0; i < 19; i++) {
if (get_user(tmp, datap)) {
ret = -EFAULT;
break;
}
if (i == PT_SR) {
tmp &= SR_MASK;
tmp <<= 16;
tmp |= get_reg(child, PT_SR) & ~(SR_MASK << 16);
}
put_reg(child, i, tmp);
datap++;
}
ret = 0;
break;
}
#ifdef PTRACE_GETFPREGS
case PTRACE_GETFPREGS: {
ret = 0;
if (copy_to_user(datap, &child->thread.fp,
sizeof(struct user_m68kfp_struct)))
ret = -EFAULT;
break;
}
#endif
#ifdef PTRACE_SETFPREGS
case PTRACE_SETFPREGS: {
ret = 0;
if (copy_from_user(&child->thread.fp, datap,
sizeof(struct user_m68kfp_struct)))
ret = -EFAULT;
break;
}
#endif
case PTRACE_GET_THREAD_AREA:
ret = put_user(task_thread_info(child)->tp_value, datap);
break;
default:
ret = ptrace_request(child, request, addr, data);
break;
}
return ret;
}
asmlinkage int syscall_trace_enter(void)
{
int ret = 0;
if (test_thread_flag(TIF_SYSCALL_TRACE))
ret = tracehook_report_syscall_entry(task_pt_regs(current));
return ret;
}
asmlinkage void syscall_trace_leave(void)
{
if (test_thread_flag(TIF_SYSCALL_TRACE))
tracehook_report_syscall_exit(task_pt_regs(current), 0);
}
