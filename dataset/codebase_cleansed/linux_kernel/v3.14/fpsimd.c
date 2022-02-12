void do_fpsimd_acc(unsigned int esr, struct pt_regs *regs)
{
WARN_ON(1);
}
void do_fpsimd_exc(unsigned int esr, struct pt_regs *regs)
{
siginfo_t info;
unsigned int si_code = 0;
if (esr & FPEXC_IOF)
si_code = FPE_FLTINV;
else if (esr & FPEXC_DZF)
si_code = FPE_FLTDIV;
else if (esr & FPEXC_OFF)
si_code = FPE_FLTOVF;
else if (esr & FPEXC_UFF)
si_code = FPE_FLTUND;
else if (esr & FPEXC_IXF)
si_code = FPE_FLTRES;
memset(&info, 0, sizeof(info));
info.si_signo = SIGFPE;
info.si_code = si_code;
info.si_addr = (void __user *)instruction_pointer(regs);
send_sig_info(SIGFPE, &info, current);
}
void fpsimd_thread_switch(struct task_struct *next)
{
if (current->mm)
fpsimd_save_state(&current->thread.fpsimd_state);
if (next->mm)
fpsimd_load_state(&next->thread.fpsimd_state);
}
void fpsimd_flush_thread(void)
{
preempt_disable();
memset(&current->thread.fpsimd_state, 0, sizeof(struct fpsimd_state));
fpsimd_load_state(&current->thread.fpsimd_state);
preempt_enable();
}
void kernel_neon_begin(void)
{
BUG_ON(in_interrupt());
preempt_disable();
if (current->mm)
fpsimd_save_state(&current->thread.fpsimd_state);
}
void kernel_neon_end(void)
{
if (current->mm)
fpsimd_load_state(&current->thread.fpsimd_state);
preempt_enable();
}
static int fpsimd_cpu_pm_notifier(struct notifier_block *self,
unsigned long cmd, void *v)
{
switch (cmd) {
case CPU_PM_ENTER:
if (current->mm)
fpsimd_save_state(&current->thread.fpsimd_state);
break;
case CPU_PM_EXIT:
if (current->mm)
fpsimd_load_state(&current->thread.fpsimd_state);
break;
case CPU_PM_ENTER_FAILED:
default:
return NOTIFY_DONE;
}
return NOTIFY_OK;
}
static void fpsimd_pm_init(void)
{
cpu_pm_register_notifier(&fpsimd_cpu_pm_notifier_block);
}
static inline void fpsimd_pm_init(void) { }
static int __init fpsimd_init(void)
{
u64 pfr = read_cpuid(ID_AA64PFR0_EL1);
if (pfr & (0xf << 16)) {
pr_notice("Floating-point is not implemented\n");
return 0;
}
elf_hwcap |= HWCAP_FP;
if (pfr & (0xf << 20))
pr_notice("Advanced SIMD is not implemented\n");
else
elf_hwcap |= HWCAP_ASIMD;
fpsimd_pm_init();
return 0;
}
