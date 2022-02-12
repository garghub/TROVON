notrace static unsigned int check_preemption_disabled(const char *what1,
const char *what2)
{
int this_cpu = raw_smp_processor_id();
if (likely(preempt_count()))
goto out;
if (irqs_disabled())
goto out;
if (cpumask_equal(&current->cpus_allowed, cpumask_of(this_cpu)))
goto out;
if (system_state < SYSTEM_SCHEDULING)
goto out;
preempt_disable_notrace();
if (!printk_ratelimit())
goto out_enable;
printk(KERN_ERR "BUG: using %s%s() in preemptible [%08x] code: %s/%d\n",
what1, what2, preempt_count() - 1, current->comm, current->pid);
print_symbol("caller is %s\n", (long)__builtin_return_address(0));
dump_stack();
out_enable:
preempt_enable_no_resched_notrace();
out:
return this_cpu;
}
notrace unsigned int debug_smp_processor_id(void)
{
return check_preemption_disabled("smp_processor_id", "");
}
notrace void __this_cpu_preempt_check(const char *op)
{
check_preemption_disabled("__this_cpu_", op);
}
