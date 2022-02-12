void context_tracking_cpu_set(int cpu)
{
if (!per_cpu(context_tracking.active, cpu)) {
per_cpu(context_tracking.active, cpu) = true;
static_key_slow_inc(&context_tracking_enabled);
}
}
void context_tracking_user_enter(void)
{
unsigned long flags;
if (!context_tracking_is_enabled())
return;
if (in_interrupt())
return;
WARN_ON_ONCE(!current->mm);
local_irq_save(flags);
if ( __this_cpu_read(context_tracking.state) != IN_USER) {
if (__this_cpu_read(context_tracking.active)) {
trace_user_enter(0);
vtime_user_enter(current);
rcu_user_enter();
}
__this_cpu_write(context_tracking.state, IN_USER);
}
local_irq_restore(flags);
}
void context_tracking_user_exit(void)
{
unsigned long flags;
if (!context_tracking_is_enabled())
return;
if (in_interrupt())
return;
local_irq_save(flags);
if (__this_cpu_read(context_tracking.state) == IN_USER) {
if (__this_cpu_read(context_tracking.active)) {
rcu_user_exit();
vtime_user_exit(current);
trace_user_exit(0);
}
__this_cpu_write(context_tracking.state, IN_KERNEL);
}
local_irq_restore(flags);
}
void __context_tracking_task_switch(struct task_struct *prev,
struct task_struct *next)
{
clear_tsk_thread_flag(prev, TIF_NOHZ);
set_tsk_thread_flag(next, TIF_NOHZ);
}
void __init context_tracking_init(void)
{
int cpu;
for_each_possible_cpu(cpu)
context_tracking_cpu_set(cpu);
}
