static void winchip_machine_check(struct pt_regs *regs, long error_code)
{
ist_enter(regs);
pr_emerg("CPU0: Machine Check Exception.\n");
add_taint(TAINT_MACHINE_CHECK, LOCKDEP_NOW_UNRELIABLE);
ist_exit(regs);
}
void winchip_mcheck_init(struct cpuinfo_x86 *c)
{
u32 lo, hi;
machine_check_vector = winchip_machine_check;
wmb();
rdmsr(MSR_IDT_FCR1, lo, hi);
lo |= (1<<2);
lo &= ~(1<<4);
wrmsr(MSR_IDT_FCR1, lo, hi);
cr4_set_bits(X86_CR4_MCE);
pr_info("Winchip machine check reporting enabled on CPU#0.\n");
}
