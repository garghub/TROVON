u64 hw_nmi_get_sample_period(int watchdog_thresh)
{
return (u64)(cpu_khz) * 1000 * watchdog_thresh;
}
static void nmi_raise_cpu_backtrace(cpumask_t *mask)
{
apic->send_IPI_mask(mask, NMI_VECTOR);
}
void arch_trigger_all_cpu_backtrace(bool include_self)
{
nmi_trigger_all_cpu_backtrace(include_self, nmi_raise_cpu_backtrace);
}
static int
arch_trigger_all_cpu_backtrace_handler(unsigned int cmd, struct pt_regs *regs)
{
if (nmi_cpu_backtrace(regs))
return NMI_HANDLED;
return NMI_DONE;
}
static int __init register_trigger_all_cpu_backtrace(void)
{
register_nmi_handler(NMI_LOCAL, arch_trigger_all_cpu_backtrace_handler,
0, "arch_bt");
return 0;
}
