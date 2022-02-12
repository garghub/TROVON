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
fpureg_t *fregs;
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
if (addr & 1)
tmp = fregs[(addr & ~1) - 32] >> 32;
else
tmp = fregs[addr - 32];
break;
}
tmp = fregs[addr - FPR_BASE];
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
case FPC_EIR: {
unsigned int flags;
#ifdef CONFIG_MIPS_MT_SMTC
unsigned int irqflags;
unsigned int mtflags;
#endif
preempt_disable();
if (!cpu_has_fpu) {
preempt_enable();
tmp = 0;
break;
}
#ifdef CONFIG_MIPS_MT_SMTC
local_irq_save(irqflags);
mtflags = dmt();
#endif
if (cpu_has_mipsmt) {
unsigned int vpflags = dvpe();
flags = read_c0_status();
__enable_fpu(FPU_AS_IS);
__asm__ __volatile__("cfc1\t%0,$0": "=r" (tmp));
write_c0_status(flags);
evpe(vpflags);
} else {
flags = read_c0_status();
__enable_fpu(FPU_AS_IS);
__asm__ __volatile__("cfc1\t%0,$0": "=r" (tmp));
write_c0_status(flags);
}
#ifdef CONFIG_MIPS_MT_SMTC
emt(mtflags);
local_irq_restore(irqflags);
#endif
preempt_enable();
break;
}
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
fpureg_t *fregs = get_fpu_regs(child);
if (!tsk_used_math(child)) {
memset(&child->thread.fpu, ~0,
sizeof(child->thread.fpu));
child->thread.fpu.fcr31 = 0;
}
if (test_thread_flag(TIF_32BIT_FPREGS)) {
if (addr & 1) {
fregs[(addr & ~1) - FPR_BASE] &=
0xffffffff;
fregs[(addr & ~1) - FPR_BASE] |=
((u64)data) << 32;
} else {
fregs[addr - FPR_BASE] &= ~0xffffffffLL;
fregs[addr - FPR_BASE] |= data;
}
break;
}
fregs[addr - FPR_BASE] = data;
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
ret = ptrace_getregs(child, (__s64 __user *) (__u64) data);
break;
case PTRACE_SETREGS:
ret = ptrace_setregs(child, (__s64 __user *) (__u64) data);
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
