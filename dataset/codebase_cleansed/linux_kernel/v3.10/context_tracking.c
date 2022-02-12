void user_enter(void)
{
unsigned long flags;
if (in_interrupt())
return;
WARN_ON_ONCE(!current->mm);
local_irq_save(flags);
if (__this_cpu_read(context_tracking.active) &&
__this_cpu_read(context_tracking.state) != IN_USER) {
vtime_user_enter(current);
rcu_user_enter();
__this_cpu_write(context_tracking.state, IN_USER);
}
local_irq_restore(flags);
}
void __sched notrace preempt_schedule_context(void)
{
struct thread_info *ti = current_thread_info();
enum ctx_state prev_ctx;
if (likely(ti->preempt_count || irqs_disabled()))
return;
preempt_disable_notrace();
prev_ctx = exception_enter();
preempt_enable_no_resched_notrace();
preempt_schedule();
preempt_disable_notrace();
exception_exit(prev_ctx);
preempt_enable_notrace();
}
void user_exit(void)
{
unsigned long flags;
if (in_interrupt())
return;
local_irq_save(flags);
if (__this_cpu_read(context_tracking.state) == IN_USER) {
rcu_user_exit();
vtime_user_exit(current);
__this_cpu_write(context_tracking.state, IN_KERNEL);
}
local_irq_restore(flags);
}
void guest_enter(void)
{
if (vtime_accounting_enabled())
vtime_guest_enter(current);
else
__guest_enter();
}
void guest_exit(void)
{
if (vtime_accounting_enabled())
vtime_guest_exit(current);
else
__guest_exit();
}
void context_tracking_task_switch(struct task_struct *prev,
struct task_struct *next)
{
if (__this_cpu_read(context_tracking.active)) {
clear_tsk_thread_flag(prev, TIF_NOHZ);
set_tsk_thread_flag(next, TIF_NOHZ);
}
}
