int smp_call_function_single(int cpu, void (*func) (void *info), void *info,
int wait)
{
unsigned long flags;
WARN_ON(cpu != 0);
local_irq_save(flags);
func(info);
local_irq_restore(flags);
return 0;
}
void __smp_call_function_single(int cpu, struct call_single_data *csd,
int wait)
{
unsigned long flags;
local_irq_save(flags);
csd->func(csd->info);
local_irq_restore(flags);
}
int on_each_cpu(smp_call_func_t func, void *info, int wait)
{
unsigned long flags;
local_irq_save(flags);
func(info);
local_irq_restore(flags);
return 0;
}
void on_each_cpu_mask(const struct cpumask *mask,
smp_call_func_t func, void *info, bool wait)
{
unsigned long flags;
if (cpumask_test_cpu(0, mask)) {
local_irq_save(flags);
func(info);
local_irq_restore(flags);
}
}
void on_each_cpu_cond(bool (*cond_func)(int cpu, void *info),
smp_call_func_t func, void *info, bool wait,
gfp_t gfp_flags)
{
unsigned long flags;
preempt_disable();
if (cond_func(0, info)) {
local_irq_save(flags);
func(info);
local_irq_restore(flags);
}
preempt_enable();
}
