void nmi_trigger_all_cpu_backtrace(bool include_self,
void (*raise)(cpumask_t *mask))
{
int i, this_cpu = get_cpu();
if (test_and_set_bit(0, &backtrace_flag)) {
put_cpu();
return;
}
cpumask_copy(to_cpumask(backtrace_mask), cpu_online_mask);
if (!include_self)
cpumask_clear_cpu(this_cpu, to_cpumask(backtrace_mask));
if (!cpumask_empty(to_cpumask(backtrace_mask))) {
pr_info("Sending NMI to %s CPUs:\n",
(include_self ? "all" : "other"));
raise(to_cpumask(backtrace_mask));
}
for (i = 0; i < 10 * 1000; i++) {
if (cpumask_empty(to_cpumask(backtrace_mask)))
break;
mdelay(1);
touch_softlockup_watchdog();
}
printk_nmi_flush();
clear_bit_unlock(0, &backtrace_flag);
put_cpu();
}
bool nmi_cpu_backtrace(struct pt_regs *regs)
{
int cpu = smp_processor_id();
if (cpumask_test_cpu(cpu, to_cpumask(backtrace_mask))) {
pr_warn("NMI backtrace for cpu %d\n", cpu);
if (regs)
show_regs(regs);
else
dump_stack();
cpumask_clear_cpu(cpu, to_cpumask(backtrace_mask));
return true;
}
return false;
}
