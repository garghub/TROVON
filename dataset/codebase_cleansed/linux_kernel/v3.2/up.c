int smp_call_function_single(int cpu, void (*func) (void *info), void *info,
int wait)
{
WARN_ON(cpu != 0);
local_irq_disable();
(func)(info);
local_irq_enable();
return 0;
}
