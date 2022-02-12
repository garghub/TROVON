static inline long get_reg(struct task_struct *task, int regno)
{
unsigned long *addr;
if (regno == PT_USP)
addr = &task->thread.usp;
else if (regno < ARRAY_SIZE(regoff))
addr = (unsigned long *)(task->thread.esp0 + regoff[regno]);
else
return 0;
if (regno == PT_SR || regno == PT_PC) {
long stkadj = *(long *)(task->thread.esp0 + PT_REG(stkadj));
addr = (unsigned long *) ((unsigned long)addr + stkadj);
if (regno == PT_SR)
return *(unsigned short *)addr;
}
return *addr;
}
static inline int put_reg(struct task_struct *task, int regno,
unsigned long data)
{
unsigned long *addr;
if (regno == PT_USP)
addr = &task->thread.usp;
else if (regno < ARRAY_SIZE(regoff))
addr = (unsigned long *)(task->thread.esp0 + regoff[regno]);
else
return -1;
if (regno == PT_SR || regno == PT_PC) {
long stkadj = *(long *)(task->thread.esp0 + PT_REG(stkadj));
addr = (unsigned long *) ((unsigned long)addr + stkadj);
if (regno == PT_SR) {
*(unsigned short *)addr = data;
return 0;
}
}
*addr = data;
return 0;
}
static inline void singlestep_disable(struct task_struct *child)
{
unsigned long tmp = get_reg(child, PT_SR) & ~TRACE_BITS;
put_reg(child, PT_SR, tmp);
clear_tsk_thread_flag(child, TIF_DELAYED_TRACE);
}
void ptrace_disable(struct task_struct *child)
{
singlestep_disable(child);
}
void user_enable_single_step(struct task_struct *child)
{
unsigned long tmp = get_reg(child, PT_SR) & ~TRACE_BITS;
put_reg(child, PT_SR, tmp | T1_BIT);
set_tsk_thread_flag(child, TIF_DELAYED_TRACE);
}
void user_enable_block_step(struct task_struct *child)
{
unsigned long tmp = get_reg(child, PT_SR) & ~TRACE_BITS;
put_reg(child, PT_SR, tmp | T0_BIT);
}
void user_disable_single_step(struct task_struct *child)
{
singlestep_disable(child);
}
long arch_ptrace(struct task_struct *child, long request,
unsigned long addr, unsigned long data)
{
unsigned long tmp;
int i, ret = 0;
int regno = addr >> 2;
unsigned long __user *datap = (unsigned long __user *) data;
switch (request) {
case PTRACE_PEEKUSR:
if (addr & 3)
goto out_eio;
if (regno >= 0 && regno < 19) {
tmp = get_reg(child, regno);
} else if (regno >= 21 && regno < 49) {
tmp = child->thread.fp[regno - 21];
if (FPU_IS_EMU && (regno < 45) && !(regno % 3))
tmp = ((tmp & 0xffff0000) << 15) |
((tmp & 0x0000ffff) << 16);
} else
goto out_eio;
ret = put_user(tmp, datap);
break;
case PTRACE_POKEUSR:
if (addr & 3)
goto out_eio;
if (regno == PT_SR) {
data &= SR_MASK;
data |= get_reg(child, PT_SR) & ~SR_MASK;
}
if (regno >= 0 && regno < 19) {
if (put_reg(child, regno, data))
goto out_eio;
} else if (regno >= 21 && regno < 48) {
if (FPU_IS_EMU && (regno < 45) && !(regno % 3)) {
data <<= 15;
data = (data & 0xffff0000) |
((data & 0x0000ffff) >> 1);
}
child->thread.fp[regno - 21] = data;
} else
goto out_eio;
break;
case PTRACE_GETREGS:
for (i = 0; i < 19; i++) {
tmp = get_reg(child, i);
ret = put_user(tmp, datap);
if (ret)
break;
datap++;
}
break;
case PTRACE_SETREGS:
for (i = 0; i < 19; i++) {
ret = get_user(tmp, datap);
if (ret)
break;
if (i == PT_SR) {
tmp &= SR_MASK;
tmp |= get_reg(child, PT_SR) & ~SR_MASK;
}
put_reg(child, i, tmp);
datap++;
}
break;
case PTRACE_GETFPREGS:
if (copy_to_user(datap, &child->thread.fp,
sizeof(struct user_m68kfp_struct)))
ret = -EFAULT;
break;
case PTRACE_SETFPREGS:
if (copy_from_user(&child->thread.fp, datap,
sizeof(struct user_m68kfp_struct)))
ret = -EFAULT;
break;
case PTRACE_GET_THREAD_AREA:
ret = put_user(task_thread_info(child)->tp_value, datap);
break;
default:
ret = ptrace_request(child, request, addr, data);
break;
}
return ret;
out_eio:
return -EIO;
}
asmlinkage void syscall_trace(void)
{
ptrace_notify(SIGTRAP | ((current->ptrace & PT_TRACESYSGOOD)
? 0x80 : 0));
if (current->exit_code) {
send_sig(current->exit_code, current, 1);
current->exit_code = 0;
}
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
