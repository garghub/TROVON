static bool context_tracking_recursion_enter(void)
{
int recursion;
recursion = __this_cpu_inc_return(context_tracking.recursion);
if (recursion == 1)
return true;
WARN_ONCE((recursion < 1), "Invalid context tracking recursion value %d\n", recursion);
__this_cpu_dec(context_tracking.recursion);
return false;
}
static void context_tracking_recursion_exit(void)
{
__this_cpu_dec(context_tracking.recursion);
}
void context_tracking_enter(enum ctx_state state)
{
unsigned long flags;
if (!context_tracking_is_enabled())
return;
if (in_interrupt())
return;
WARN_ON_ONCE(!current->mm);
local_irq_save(flags);
if (!context_tracking_recursion_enter())
goto out_irq_restore;
if ( __this_cpu_read(context_tracking.state) != state) {
if (__this_cpu_read(context_tracking.active)) {
if (state == CONTEXT_USER) {
trace_user_enter(0);
vtime_user_enter(current);
}
rcu_user_enter();
}
__this_cpu_write(context_tracking.state, state);
}
context_tracking_recursion_exit();
out_irq_restore:
local_irq_restore(flags);
}
void context_tracking_user_enter(void)
{
context_tracking_enter(CONTEXT_USER);
}
void context_tracking_exit(enum ctx_state state)
{
unsigned long flags;
if (!context_tracking_is_enabled())
return;
if (in_interrupt())
return;
local_irq_save(flags);
if (!context_tracking_recursion_enter())
goto out_irq_restore;
if (__this_cpu_read(context_tracking.state) == state) {
if (__this_cpu_read(context_tracking.active)) {
rcu_user_exit();
if (state == CONTEXT_USER) {
vtime_user_exit(current);
trace_user_exit(0);
}
}
__this_cpu_write(context_tracking.state, CONTEXT_KERNEL);
}
context_tracking_recursion_exit();
out_irq_restore:
local_irq_restore(flags);
}
void context_tracking_user_exit(void)
{
context_tracking_exit(CONTEXT_USER);
}
void __init context_tracking_cpu_set(int cpu)
{
static __initdata bool initialized = false;
if (!per_cpu(context_tracking.active, cpu)) {
per_cpu(context_tracking.active, cpu) = true;
static_key_slow_inc(&context_tracking_enabled);
}
if (initialized)
return;
set_tsk_thread_flag(&init_task, TIF_NOHZ);
WARN_ON_ONCE(!tasklist_empty());
initialized = true;
}
void __init context_tracking_init(void)
{
int cpu;
for_each_possible_cpu(cpu)
context_tracking_cpu_set(cpu);
}
