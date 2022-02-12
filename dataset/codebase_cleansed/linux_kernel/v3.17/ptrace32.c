long compat_arch_ptrace(struct task_struct *child, compat_long_t request,
compat_ulong_t caddr, compat_ulong_t cdata)
{
int addr = caddr;
int data = cdata;
int ret;
switch (request) {
case PTRACE_PEEKTEXT_3264:
case PTRACE_PEEKDATA_3264: {
u32 tmp;
int copied;
u32 __user * addrOthers;
ret = -EIO;
if (get_user(addrOthers, (u32 __user * __user *) (unsigned long) addr) != 0)
break;
copied = access_process_vm(child, (u64)addrOthers, &tmp,
sizeof(tmp), 0);
if (copied != sizeof(tmp))
break;
ret = put_user(tmp, (u32 __user *) (unsigned long) data);
break;
}
case PTRACE_PEEKUSR: {
struct pt_regs *regs;
union fpureg *fregs;
unsigned int tmp;
regs = task_pt_regs(child);
ret = 0;
switch (addr) {
case 0 ... 31:
tmp = regs->regs[addr];
break;
case FPR_BASE ... FPR_BASE + 31:
if (!tsk_used_math(child)) {
tmp = -1;
break;
}
fregs = get_fpu_regs(child);
if (test_thread_flag(TIF_32BIT_FPREGS)) {
tmp = get_fpr32(&fregs[(addr & ~1) - FPR_BASE],
addr & 1);
break;
}
tmp = get_fpr32(&fregs[addr - FPR_BASE], 0);
break;
case PC:
tmp = regs->cp0_epc;
break;
case CAUSE:
tmp = regs->cp0_cause;
break;
case BADVADDR:
tmp = regs->cp0_badvaddr;
break;
case MMHI:
tmp = regs->hi;
break;
case MMLO:
tmp = regs->lo;
break;
case FPC_CSR:
tmp = child->thread.fpu.fcr31;
break;
case FPC_EIR:
tmp = boot_cpu_data.fpu_id;
break;
case DSP_BASE ... DSP_BASE + 5: {
dspreg_t *dregs;
if (!cpu_has_dsp) {
tmp = 0;
ret = -EIO;
goto out;
}
dregs = __get_dsp_regs(child);
tmp = (unsigned long) (dregs[addr - DSP_BASE]);
break;
}
case DSP_CONTROL:
if (!cpu_has_dsp) {
tmp = 0;
ret = -EIO;
goto out;
}
tmp = child->thread.dsp.dspcontrol;
break;
default:
tmp = 0;
ret = -EIO;
goto out;
}
ret = put_user(tmp, (unsigned __user *) (unsigned long) data);
break;
}
case PTRACE_POKETEXT_3264:
case PTRACE_POKEDATA_3264: {
u32 __user * addrOthers;
ret = -EIO;
if (get_user(addrOthers, (u32 __user * __user *) (unsigned long) addr) != 0)
break;
ret = 0;
if (access_process_vm(child, (u64)addrOthers, &data,
sizeof(data), 1) == sizeof(data))
break;
ret = -EIO;
break;
}
case PTRACE_POKEUSR: {
struct pt_regs *regs;
ret = 0;
regs = task_pt_regs(child);
switch (addr) {
case 0 ... 31:
regs->regs[addr] = data;
break;
case FPR_BASE ... FPR_BASE + 31: {
union fpureg *fregs = get_fpu_regs(child);
if (!tsk_used_math(child)) {
memset(&child->thread.fpu, ~0,
sizeof(child->thread.fpu));
child->thread.fpu.fcr31 = 0;
}
if (test_thread_flag(TIF_32BIT_FPREGS)) {
set_fpr32(&fregs[(addr & ~1) - FPR_BASE],
addr & 1, data);
break;
}
set_fpr64(&fregs[addr - FPR_BASE], 0, data);
break;
}
case PC:
regs->cp0_epc = data;
break;
case MMHI:
regs->hi = data;
break;
case MMLO:
regs->lo = data;
break;
case FPC_CSR:
child->thread.fpu.fcr31 = data;
break;
case DSP_BASE ... DSP_BASE + 5: {
dspreg_t *dregs;
if (!cpu_has_dsp) {
ret = -EIO;
break;
}
dregs = __get_dsp_regs(child);
dregs[addr - DSP_BASE] = data;
break;
}
case DSP_CONTROL:
if (!cpu_has_dsp) {
ret = -EIO;
break;
}
child->thread.dsp.dspcontrol = data;
break;
default:
ret = -EIO;
break;
}
break;
}
case PTRACE_GETREGS:
ret = ptrace_getregs(child,
(struct user_pt_regs __user *) (__u64) data);
break;
case PTRACE_SETREGS:
ret = ptrace_setregs(child,
(struct user_pt_regs __user *) (__u64) data);
break;
case PTRACE_GETFPREGS:
ret = ptrace_getfpregs(child, (__u32 __user *) (__u64) data);
break;
case PTRACE_SETFPREGS:
ret = ptrace_setfpregs(child, (__u32 __user *) (__u64) data);
break;
case PTRACE_GET_THREAD_AREA:
ret = put_user(task_thread_info(child)->tp_value,
(unsigned int __user *) (unsigned long) data);
break;
case PTRACE_GET_THREAD_AREA_3264:
ret = put_user(task_thread_info(child)->tp_value,
(unsigned long __user *) (unsigned long) data);
break;
case PTRACE_GET_WATCH_REGS:
ret = ptrace_get_watch_regs(child,
(struct pt_watch_regs __user *) (unsigned long) addr);
break;
case PTRACE_SET_WATCH_REGS:
ret = ptrace_set_watch_regs(child,
(struct pt_watch_regs __user *) (unsigned long) addr);
break;
default:
ret = compat_ptrace_request(child, request, addr, data);
break;
}
out:
return ret;
}
