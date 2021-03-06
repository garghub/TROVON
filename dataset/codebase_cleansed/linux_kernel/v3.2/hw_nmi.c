u64 hw_nmi_get_sample_period(int watchdog_thresh)
{
return (u64)(cpu_khz) * 1000 * watchdog_thresh;
}
void arch_trigger_all_cpu_backtrace(void)
{
int i;
if (test_and_set_bit(0, &backtrace_flag))
return;
cpumask_copy(to_cpumask(backtrace_mask), cpu_online_mask);
printk(KERN_INFO "sending NMI to all CPUs:\n");
apic->send_IPI_all(NMI_VECTOR);
for (i = 0; i < 10 * 1000; i++) {
if (cpumask_empty(to_cpumask(backtrace_mask)))
break;
mdelay(1);
}
clear_bit(0, &backtrace_flag);
smp_mb__after_clear_bit();
}
static int __kprobes
arch_trigger_all_cpu_backtrace_handler(unsigned int cmd, struct pt_regs *regs)
{
int cpu;
cpu = smp_processor_id();
if (cpumask_test_cpu(cpu, to_cpumask(backtrace_mask))) {
static arch_spinlock_t lock = __ARCH_SPIN_LOCK_UNLOCKED;
arch_spin_lock(&lock);
printk(KERN_WARNING "NMI backtrace for cpu %d\n", cpu);
show_regs(regs);
arch_spin_unlock(&lock);
cpumask_clear_cpu(cpu, to_cpumask(backtrace_mask));
return NMI_HANDLED;
}
return NMI_DONE;
}
static int __init register_trigger_all_cpu_backtrace(void)
{
register_nmi_handler(NMI_LOCAL, arch_trigger_all_cpu_backtrace_handler,
0, "arch_bt");
return 0;
}
