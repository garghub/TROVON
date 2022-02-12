void nmi_trigger_cpumask_backtrace(const cpumask_t *mask,
bool exclude_self,
void (*raise)(cpumask_t *mask))
{
int i, this_cpu = get_cpu();
if (test_and_set_bit(0, &backtrace_flag)) {
put_cpu();
return;
}
cpumask_copy(to_cpumask(backtrace_mask), mask);
if (exclude_self)
cpumask_clear_cpu(this_cpu, to_cpumask(backtrace_mask));
if (cpumask_test_cpu(this_cpu, to_cpumask(backtrace_mask)))
nmi_cpu_backtrace(NULL);
if (!cpumask_empty(to_cpumask(backtrace_mask))) {
pr_info("Sending NMI from CPU %d to CPUs %*pbl:\n",
this_cpu, nr_cpumask_bits, to_cpumask(backtrace_mask));
raise(to_cpumask(backtrace_mask));
}
for (i = 0; i < 10 * 1000; i++) {
if (cpumask_empty(to_cpumask(backtrace_mask)))
break;
mdelay(1);
touch_softlockup_watchdog();
}
printk_safe_flush();
clear_bit_unlock(0, &backtrace_flag);
put_cpu();
}
bool nmi_cpu_backtrace(struct pt_regs *regs)
{
int cpu = smp_processor_id();
if (cpumask_test_cpu(cpu, to_cpumask(backtrace_mask))) {
if (regs && cpu_in_idle(instruction_pointer(regs))) {
pr_warn("NMI backtrace for cpu %d skipped: idling at pc %#lx\n",
cpu, instruction_pointer(regs));
} else {
pr_warn("NMI backtrace for cpu %d\n", cpu);
if (regs)
show_regs(regs);
else
dump_stack();
}
cpumask_clear_cpu(cpu, to_cpumask(backtrace_mask));
return true;
}
return false;
}
