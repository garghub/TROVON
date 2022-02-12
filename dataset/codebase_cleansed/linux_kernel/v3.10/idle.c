void default_idle(void)
{
set_bl_bit();
local_irq_enable();
cpu_sleep();
clear_bl_bit();
}
void arch_cpu_idle_dead(void)
{
play_dead();
}
void arch_cpu_idle(void)
{
if (cpuidle_idle_call())
sh_idle();
}
void __init select_idle_routine(void)
{
if (!sh_idle)
sh_idle = default_idle;
}
void stop_this_cpu(void *unused)
{
local_irq_disable();
set_cpu_online(smp_processor_id(), false);
for (;;)
cpu_sleep();
}
