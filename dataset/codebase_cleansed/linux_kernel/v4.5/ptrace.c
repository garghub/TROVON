void ptrace_disable(struct task_struct *task)
{
clear_tsk_thread_flag(task, TIF_SINGLESTEP);
clear_tsk_thread_flag(task, TIF_BLOCKSTEP);
pa_psw(task)->r = 0;
pa_psw(task)->t = 0;
pa_psw(task)->h = 0;
pa_psw(task)->l = 0;
}
void user_disable_single_step(struct task_struct *task)
{
ptrace_disable(task);
}
void user_enable_single_step(struct task_struct *task)
{
clear_tsk_thread_flag(task, TIF_BLOCKSTEP);
set_tsk_thread_flag(task, TIF_SINGLESTEP);
if (pa_psw(task)->n) {
struct siginfo si;
task_regs(task)->iaoq[0] = task_regs(task)->iaoq[1];
task_regs(task)->iasq[0] = task_regs(task)->iasq[1];
task_regs(task)->iaoq[1] = task_regs(task)->iaoq[0] + 4;
pa_psw(task)->n = 0;
pa_psw(task)->x = 0;
pa_psw(task)->y = 0;
pa_psw(task)->z = 0;
pa_psw(task)->b = 0;
ptrace_disable(task);
si.si_code = TRAP_TRACE;
si.si_addr = (void __user *) (task_regs(task)->iaoq[0] & ~3);
si.si_signo = SIGTRAP;
si.si_errno = 0;
force_sig_info(SIGTRAP, &si, task);
return;
}
pa_psw(task)->r = 1;
pa_psw(task)->t = 0;
pa_psw(task)->h = 0;
pa_psw(task)->l = 0;
}
void user_enable_block_step(struct task_struct *task)
{
clear_tsk_thread_flag(task, TIF_SINGLESTEP);
set_tsk_thread_flag(task, TIF_BLOCKSTEP);
pa_psw(task)->r = 0;
pa_psw(task)->t = 1;
pa_psw(task)->h = 0;
pa_psw(task)->l = 0;
}
long arch_ptrace(struct task_struct *child, long request,
unsigned long addr, unsigned long data)
{
unsigned long tmp;
long ret = -EIO;
switch (request) {
case PTRACE_PEEKUSR:
if ((addr & (sizeof(unsigned long)-1)) ||
addr >= sizeof(struct pt_regs))
break;
tmp = *(unsigned long *) ((char *) task_regs(child) + addr);
ret = put_user(tmp, (unsigned long __user *) data);
break;
case PTRACE_POKEUSR:
if (addr == PT_PSW) {
data &= USER_PSW_BITS;
task_regs(child)->gr[0] &= ~USER_PSW_BITS;
task_regs(child)->gr[0] |= data;
ret = 0;
break;
}
if ((addr & (sizeof(unsigned long)-1)) ||
addr >= sizeof(struct pt_regs))
break;
if ((addr >= PT_GR1 && addr <= PT_GR31) ||
addr == PT_IAOQ0 || addr == PT_IAOQ1 ||
(addr >= PT_FR0 && addr <= PT_FR31 + 4) ||
addr == PT_SAR) {
*(unsigned long *) ((char *) task_regs(child) + addr) = data;
ret = 0;
}
break;
default:
ret = ptrace_request(child, request, addr, data);
break;
}
return ret;
}
static compat_ulong_t translate_usr_offset(compat_ulong_t offset)
{
if (offset < 0)
return sizeof(struct pt_regs);
else if (offset <= 32*4)
return offset * 2 + 4;
else if (offset <= 32*4+32*8)
return offset + 32*4;
else if (offset < sizeof(struct pt_regs)/2 + 32*4)
return offset * 2 + 4 - 32*8;
else
return sizeof(struct pt_regs);
}
long compat_arch_ptrace(struct task_struct *child, compat_long_t request,
compat_ulong_t addr, compat_ulong_t data)
{
compat_uint_t tmp;
long ret = -EIO;
switch (request) {
case PTRACE_PEEKUSR:
if (addr & (sizeof(compat_uint_t)-1))
break;
addr = translate_usr_offset(addr);
if (addr >= sizeof(struct pt_regs))
break;
tmp = *(compat_uint_t *) ((char *) task_regs(child) + addr);
ret = put_user(tmp, (compat_uint_t *) (unsigned long) data);
break;
case PTRACE_POKEUSR:
if (addr == PT_PSW) {
ret = arch_ptrace(child, request, addr, data);
} else {
if (addr & (sizeof(compat_uint_t)-1))
break;
addr = translate_usr_offset(addr);
if (addr >= sizeof(struct pt_regs))
break;
if (addr >= PT_FR0 && addr <= PT_FR31 + 4) {
*(__u64 *) ((char *) task_regs(child) + addr) = data;
ret = 0;
}
else if ((addr >= PT_GR1+4 && addr <= PT_GR31+4) ||
addr == PT_IAOQ0+4 || addr == PT_IAOQ1+4 ||
addr == PT_SAR+4) {
*(__u32 *) ((char *) task_regs(child) + addr - 4) = 0;
*(__u32 *) ((char *) task_regs(child) + addr) = data;
ret = 0;
}
}
break;
default:
ret = compat_ptrace_request(child, request, addr, data);
break;
}
return ret;
}
long do_syscall_trace_enter(struct pt_regs *regs)
{
secure_computing_strict(regs->gr[20]);
if (test_thread_flag(TIF_SYSCALL_TRACE) &&
tracehook_report_syscall_entry(regs)) {
regs->gr[20] = -1UL;
goto out;
}
#ifdef CONFIG_64BIT
if (!is_compat_task())
audit_syscall_entry(regs->gr[20], regs->gr[26], regs->gr[25],
regs->gr[24], regs->gr[23]);
else
#endif
audit_syscall_entry(regs->gr[20] & 0xffffffff,
regs->gr[26] & 0xffffffff,
regs->gr[25] & 0xffffffff,
regs->gr[24] & 0xffffffff,
regs->gr[23] & 0xffffffff);
out:
return regs->gr[20];
}
void do_syscall_trace_exit(struct pt_regs *regs)
{
int stepping = test_thread_flag(TIF_SINGLESTEP) ||
test_thread_flag(TIF_BLOCKSTEP);
audit_syscall_exit(regs);
if (stepping || test_thread_flag(TIF_SYSCALL_TRACE))
tracehook_report_syscall_exit(regs, stepping);
}
