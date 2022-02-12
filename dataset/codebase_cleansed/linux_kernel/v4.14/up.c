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
int smp_call_function_single_async(int cpu, call_single_data_t *csd)
{
unsigned long flags;
local_irq_save(flags);
csd->func(csd->info);
local_irq_restore(flags);
return 0;
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
int smp_call_on_cpu(unsigned int cpu, int (*func)(void *), void *par, bool phys)
{
int ret;
if (cpu != 0)
return -ENXIO;
if (phys)
hypervisor_pin_vcpu(0);
ret = func(par);
if (phys)
hypervisor_pin_vcpu(-1);
return ret;
}
