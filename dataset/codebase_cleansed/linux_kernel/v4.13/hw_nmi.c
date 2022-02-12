u64 hw_nmi_get_sample_period(int watchdog_thresh)
{
return (u64)(cpu_khz) * 1000 * watchdog_thresh;
}
static void nmi_raise_cpu_backtrace(cpumask_t *mask)
{
apic->send_IPI_mask(mask, NMI_VECTOR);
}
void arch_trigger_cpumask_backtrace(const cpumask_t *mask, bool exclude_self)
{
nmi_trigger_cpumask_backtrace(mask, exclude_self,
nmi_raise_cpu_backtrace);
}
static int nmi_cpu_backtrace_handler(unsigned int cmd, struct pt_regs *regs)
{
if (nmi_cpu_backtrace(regs))
return NMI_HANDLED;
return NMI_DONE;
}
static int __init register_nmi_cpu_backtrace_handler(void)
{
register_nmi_handler(NMI_LOCAL, nmi_cpu_backtrace_handler,
0, "arch_bt");
return 0;
}
