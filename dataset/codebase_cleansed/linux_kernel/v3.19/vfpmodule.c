static bool vfp_state_in_hw(unsigned int cpu, struct thread_info *thread)
{
#ifdef CONFIG_SMP
if (thread->vfpstate.hard.cpu != cpu)
return false;
#endif
return vfp_current_hw_state[cpu] == &thread->vfpstate;
}
static void vfp_force_reload(unsigned int cpu, struct thread_info *thread)
{
if (vfp_state_in_hw(cpu, thread)) {
fmxr(FPEXC, fmrx(FPEXC) & ~FPEXC_EN);
vfp_current_hw_state[cpu] = NULL;
}
#ifdef CONFIG_SMP
thread->vfpstate.hard.cpu = NR_CPUS;
#endif
}
static void vfp_thread_flush(struct thread_info *thread)
{
union vfp_state *vfp = &thread->vfpstate;
unsigned int cpu;
cpu = get_cpu();
if (vfp_current_hw_state[cpu] == vfp)
vfp_current_hw_state[cpu] = NULL;
fmxr(FPEXC, fmrx(FPEXC) & ~FPEXC_EN);
put_cpu();
memset(vfp, 0, sizeof(union vfp_state));
vfp->hard.fpexc = FPEXC_EN;
vfp->hard.fpscr = FPSCR_ROUND_NEAREST;
#ifdef CONFIG_SMP
vfp->hard.cpu = NR_CPUS;
#endif
}
static void vfp_thread_exit(struct thread_info *thread)
{
union vfp_state *vfp = &thread->vfpstate;
unsigned int cpu = get_cpu();
if (vfp_current_hw_state[cpu] == vfp)
vfp_current_hw_state[cpu] = NULL;
put_cpu();
}
static void vfp_thread_copy(struct thread_info *thread)
{
struct thread_info *parent = current_thread_info();
vfp_sync_hwstate(parent);
thread->vfpstate = parent->vfpstate;
#ifdef CONFIG_SMP
thread->vfpstate.hard.cpu = NR_CPUS;
#endif
}
static int vfp_notifier(struct notifier_block *self, unsigned long cmd, void *v)
{
struct thread_info *thread = v;
u32 fpexc;
#ifdef CONFIG_SMP
unsigned int cpu;
#endif
switch (cmd) {
case THREAD_NOTIFY_SWITCH:
fpexc = fmrx(FPEXC);
#ifdef CONFIG_SMP
cpu = thread->cpu;
if ((fpexc & FPEXC_EN) && vfp_current_hw_state[cpu])
vfp_save_state(vfp_current_hw_state[cpu], fpexc);
#endif
fmxr(FPEXC, fpexc & ~FPEXC_EN);
break;
case THREAD_NOTIFY_FLUSH:
vfp_thread_flush(thread);
break;
case THREAD_NOTIFY_EXIT:
vfp_thread_exit(thread);
break;
case THREAD_NOTIFY_COPY:
vfp_thread_copy(thread);
break;
}
return NOTIFY_DONE;
}
static void vfp_raise_sigfpe(unsigned int sicode, struct pt_regs *regs)
{
siginfo_t info;
memset(&info, 0, sizeof(info));
info.si_signo = SIGFPE;
info.si_code = sicode;
info.si_addr = (void __user *)(instruction_pointer(regs) - 4);
current->thread.error_code = 0;
current->thread.trap_no = 6;
send_sig_info(SIGFPE, &info, current);
}
static void vfp_panic(char *reason, u32 inst)
{
int i;
pr_err("VFP: Error: %s\n", reason);
pr_err("VFP: EXC 0x%08x SCR 0x%08x INST 0x%08x\n",
fmrx(FPEXC), fmrx(FPSCR), inst);
for (i = 0; i < 32; i += 2)
pr_err("VFP: s%2u: 0x%08x s%2u: 0x%08x\n",
i, vfp_get_float(i), i+1, vfp_get_float(i+1));
}
static void vfp_raise_exceptions(u32 exceptions, u32 inst, u32 fpscr, struct pt_regs *regs)
{
int si_code = 0;
pr_debug("VFP: raising exceptions %08x\n", exceptions);
if (exceptions == VFP_EXCEPTION_ERROR) {
vfp_panic("unhandled bounce", inst);
vfp_raise_sigfpe(0, regs);
return;
}
if (exceptions & (FPSCR_N|FPSCR_Z|FPSCR_C|FPSCR_V))
fpscr &= ~(FPSCR_N|FPSCR_Z|FPSCR_C|FPSCR_V);
fpscr |= exceptions;
fmxr(FPSCR, fpscr);
#define RAISE(stat,en,sig) \
if (exceptions & stat && fpscr & en) \
si_code = sig;
RAISE(FPSCR_DZC, FPSCR_DZE, FPE_FLTDIV);
RAISE(FPSCR_IXC, FPSCR_IXE, FPE_FLTRES);
RAISE(FPSCR_UFC, FPSCR_UFE, FPE_FLTUND);
RAISE(FPSCR_OFC, FPSCR_OFE, FPE_FLTOVF);
RAISE(FPSCR_IOC, FPSCR_IOE, FPE_FLTINV);
if (si_code)
vfp_raise_sigfpe(si_code, regs);
}
static u32 vfp_emulate_instruction(u32 inst, u32 fpscr, struct pt_regs *regs)
{
u32 exceptions = VFP_EXCEPTION_ERROR;
pr_debug("VFP: emulate: INST=0x%08x SCR=0x%08x\n", inst, fpscr);
if (INST_CPRTDO(inst)) {
if (!INST_CPRT(inst)) {
if (vfp_single(inst)) {
exceptions = vfp_single_cpdo(inst, fpscr);
} else {
exceptions = vfp_double_cpdo(inst, fpscr);
}
} else {
}
} else {
}
return exceptions & ~VFP_NAN_FLAG;
}
void VFP_bounce(u32 trigger, u32 fpexc, struct pt_regs *regs)
{
u32 fpscr, orig_fpscr, fpsid, exceptions;
pr_debug("VFP: bounce: trigger %08x fpexc %08x\n", trigger, fpexc);
fmxr(FPEXC, fpexc & ~(FPEXC_EX|FPEXC_DEX|FPEXC_FP2V|FPEXC_VV|FPEXC_TRAP_MASK));
fpsid = fmrx(FPSID);
orig_fpscr = fpscr = fmrx(FPSCR);
if ((fpsid & FPSID_ARCH_MASK) == (1 << FPSID_ARCH_BIT)
&& (fpscr & FPSCR_IXE)) {
goto emulate;
}
if (fpexc & FPEXC_EX) {
#ifndef CONFIG_CPU_FEROCEON
trigger = fmrx(FPINST);
regs->ARM_pc -= 4;
#endif
} else if (!(fpexc & FPEXC_DEX)) {
vfp_raise_exceptions(VFP_EXCEPTION_ERROR, trigger, fpscr, regs);
goto exit;
}
if (fpexc & (FPEXC_EX | FPEXC_VV)) {
u32 len;
len = fpexc + (1 << FPEXC_LENGTH_BIT);
fpscr &= ~FPSCR_LENGTH_MASK;
fpscr |= (len & FPEXC_LENGTH_MASK) << (FPSCR_LENGTH_BIT - FPEXC_LENGTH_BIT);
}
exceptions = vfp_emulate_instruction(trigger, fpscr, regs);
if (exceptions)
vfp_raise_exceptions(exceptions, trigger, orig_fpscr, regs);
if ((fpexc & (FPEXC_EX | FPEXC_FP2V)) != (FPEXC_EX | FPEXC_FP2V))
goto exit;
barrier();
trigger = fmrx(FPINST2);
emulate:
exceptions = vfp_emulate_instruction(trigger, orig_fpscr, regs);
if (exceptions)
vfp_raise_exceptions(exceptions, trigger, orig_fpscr, regs);
exit:
preempt_enable();
}
static void vfp_enable(void *unused)
{
u32 access;
BUG_ON(preemptible());
access = get_copro_access();
set_copro_access(access | CPACC_FULL(10) | CPACC_FULL(11));
}
static int vfp_pm_suspend(void)
{
struct thread_info *ti = current_thread_info();
u32 fpexc = fmrx(FPEXC);
if (fpexc & FPEXC_EN) {
pr_debug("%s: saving vfp state\n", __func__);
vfp_save_state(&ti->vfpstate, fpexc);
fmxr(FPEXC, fmrx(FPEXC) & ~FPEXC_EN);
} else if (vfp_current_hw_state[ti->cpu]) {
#ifndef CONFIG_SMP
fmxr(FPEXC, fpexc | FPEXC_EN);
vfp_save_state(vfp_current_hw_state[ti->cpu], fpexc);
fmxr(FPEXC, fpexc);
#endif
}
vfp_current_hw_state[ti->cpu] = NULL;
return 0;
}
static void vfp_pm_resume(void)
{
vfp_enable(NULL);
fmxr(FPEXC, fmrx(FPEXC) & ~FPEXC_EN);
}
static int vfp_cpu_pm_notifier(struct notifier_block *self, unsigned long cmd,
void *v)
{
switch (cmd) {
case CPU_PM_ENTER:
vfp_pm_suspend();
break;
case CPU_PM_ENTER_FAILED:
case CPU_PM_EXIT:
vfp_pm_resume();
break;
}
return NOTIFY_OK;
}
static void vfp_pm_init(void)
{
cpu_pm_register_notifier(&vfp_cpu_pm_notifier_block);
}
static inline void vfp_pm_init(void) { }
void vfp_sync_hwstate(struct thread_info *thread)
{
unsigned int cpu = get_cpu();
if (vfp_state_in_hw(cpu, thread)) {
u32 fpexc = fmrx(FPEXC);
fmxr(FPEXC, fpexc | FPEXC_EN);
vfp_save_state(&thread->vfpstate, fpexc | FPEXC_EN);
fmxr(FPEXC, fpexc);
}
put_cpu();
}
void vfp_flush_hwstate(struct thread_info *thread)
{
unsigned int cpu = get_cpu();
vfp_force_reload(cpu, thread);
put_cpu();
}
int vfp_preserve_user_clear_hwstate(struct user_vfp __user *ufp,
struct user_vfp_exc __user *ufp_exc)
{
struct thread_info *thread = current_thread_info();
struct vfp_hard_struct *hwstate = &thread->vfpstate.hard;
int err = 0;
vfp_sync_hwstate(thread);
err |= __copy_to_user(&ufp->fpregs, &hwstate->fpregs,
sizeof(hwstate->fpregs));
__put_user_error(hwstate->fpscr, &ufp->fpscr, err);
__put_user_error(hwstate->fpexc, &ufp_exc->fpexc, err);
__put_user_error(hwstate->fpinst, &ufp_exc->fpinst, err);
__put_user_error(hwstate->fpinst2, &ufp_exc->fpinst2, err);
if (err)
return -EFAULT;
vfp_flush_hwstate(thread);
hwstate->fpscr &= ~(FPSCR_LENGTH_MASK | FPSCR_STRIDE_MASK);
return 0;
}
int vfp_restore_user_hwstate(struct user_vfp __user *ufp,
struct user_vfp_exc __user *ufp_exc)
{
struct thread_info *thread = current_thread_info();
struct vfp_hard_struct *hwstate = &thread->vfpstate.hard;
unsigned long fpexc;
int err = 0;
vfp_flush_hwstate(thread);
err |= __copy_from_user(&hwstate->fpregs, &ufp->fpregs,
sizeof(hwstate->fpregs));
__get_user_error(hwstate->fpscr, &ufp->fpscr, err);
__get_user_error(fpexc, &ufp_exc->fpexc, err);
fpexc |= FPEXC_EN;
fpexc &= ~(FPEXC_EX | FPEXC_FP2V);
hwstate->fpexc = fpexc;
__get_user_error(hwstate->fpinst, &ufp_exc->fpinst, err);
__get_user_error(hwstate->fpinst2, &ufp_exc->fpinst2, err);
return err ? -EFAULT : 0;
}
static int vfp_hotplug(struct notifier_block *b, unsigned long action,
void *hcpu)
{
if (action == CPU_DYING || action == CPU_DYING_FROZEN)
vfp_current_hw_state[(long)hcpu] = NULL;
else if (action == CPU_STARTING || action == CPU_STARTING_FROZEN)
vfp_enable(NULL);
return NOTIFY_OK;
}
void vfp_kmode_exception(void)
{
if (fmrx(FPEXC) & FPEXC_EN)
pr_crit("BUG: unsupported FP instruction in kernel mode\n");
else
pr_crit("BUG: FP instruction issued in kernel mode with FP unit disabled\n");
}
void kernel_neon_begin(void)
{
struct thread_info *thread = current_thread_info();
unsigned int cpu;
u32 fpexc;
BUG_ON(in_interrupt());
cpu = get_cpu();
fpexc = fmrx(FPEXC) | FPEXC_EN;
fmxr(FPEXC, fpexc);
if (vfp_state_in_hw(cpu, thread))
vfp_save_state(&thread->vfpstate, fpexc);
#ifndef CONFIG_SMP
else if (vfp_current_hw_state[cpu] != NULL)
vfp_save_state(vfp_current_hw_state[cpu], fpexc);
#endif
vfp_current_hw_state[cpu] = NULL;
}
void kernel_neon_end(void)
{
fmxr(FPEXC, fmrx(FPEXC) & ~FPEXC_EN);
put_cpu();
}
static int __init vfp_init(void)
{
unsigned int vfpsid;
unsigned int cpu_arch = cpu_architecture();
if (cpu_arch >= CPU_ARCH_ARMv6)
on_each_cpu(vfp_enable, NULL, 1);
vfp_vector = vfp_testing_entry;
barrier();
vfpsid = fmrx(FPSID);
barrier();
vfp_vector = vfp_null_entry;
pr_info("VFP support v0.3: ");
if (VFP_arch) {
pr_cont("not present\n");
return 0;
} else if ((read_cpuid_id() & 0x000f0000) == 0x000f0000) {
VFP_arch = vfpsid & FPSID_CPUID_ARCH_MASK;
VFP_arch >>= FPSID_ARCH_BIT;
if (IS_ENABLED(CONFIG_NEON) &&
(fmrx(MVFR1) & 0x000fff00) == 0x00011100)
elf_hwcap |= HWCAP_NEON;
if (IS_ENABLED(CONFIG_VFPv3)) {
u32 mvfr0 = fmrx(MVFR0);
if (((mvfr0 & MVFR0_DP_MASK) >> MVFR0_DP_BIT) == 0x2 ||
((mvfr0 & MVFR0_SP_MASK) >> MVFR0_SP_BIT) == 0x2) {
elf_hwcap |= HWCAP_VFPv3;
if ((mvfr0 & MVFR0_A_SIMD_MASK) == 1)
elf_hwcap |= HWCAP_VFPv3D16;
else
elf_hwcap |= HWCAP_VFPD32;
}
if ((fmrx(MVFR1) & 0xf0000000) == 0x10000000)
elf_hwcap |= HWCAP_VFPv4;
}
} else {
if (vfpsid & FPSID_NODOUBLE) {
pr_cont("no double precision support\n");
return 0;
}
VFP_arch = (vfpsid & FPSID_ARCH_MASK) >> FPSID_ARCH_BIT;
}
hotcpu_notifier(vfp_hotplug, 0);
vfp_vector = vfp_support_entry;
thread_register_notifier(&vfp_notifier_block);
vfp_pm_init();
elf_hwcap |= HWCAP_VFP;
pr_cont("implementor %02x architecture %d part %02x variant %x rev %x\n",
(vfpsid & FPSID_IMPLEMENTER_MASK) >> FPSID_IMPLEMENTER_BIT,
VFP_arch,
(vfpsid & FPSID_PART_MASK) >> FPSID_PART_BIT,
(vfpsid & FPSID_VARIANT_MASK) >> FPSID_VARIANT_BIT,
(vfpsid & FPSID_REV_MASK) >> FPSID_REV_BIT);
return 0;
}
