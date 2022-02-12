static inline void frozen_process(void)
{
if (!unlikely(current->flags & PF_NOFREEZE)) {
current->flags |= PF_FROZEN;
smp_wmb();
}
clear_freeze_flag(current);
}
void refrigerator(void)
{
long save;
task_lock(current);
if (freezing(current)) {
frozen_process();
task_unlock(current);
} else {
task_unlock(current);
return;
}
save = current->state;
pr_debug("%s entered refrigerator\n", current->comm);
spin_lock_irq(&current->sighand->siglock);
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
current->flags |= PF_FREEZING;
for (;;) {
set_current_state(TASK_UNINTERRUPTIBLE);
if (!frozen(current))
break;
schedule();
}
current->flags &= ~PF_FREEZING;
pr_debug("%s left refrigerator\n", current->comm);
__set_current_state(save);
}
static void fake_signal_wake_up(struct task_struct *p)
{
unsigned long flags;
spin_lock_irqsave(&p->sighand->siglock, flags);
signal_wake_up(p, 0);
spin_unlock_irqrestore(&p->sighand->siglock, flags);
}
bool freeze_task(struct task_struct *p, bool sig_only)
{
if (!freezing(p)) {
smp_rmb();
if (frozen(p))
return false;
if (!sig_only || should_send_signal(p))
set_freeze_flag(p);
else
return false;
}
if (should_send_signal(p)) {
fake_signal_wake_up(p);
} else if (sig_only) {
return false;
} else {
wake_up_state(p, TASK_INTERRUPTIBLE);
}
return true;
}
void cancel_freezing(struct task_struct *p)
{
unsigned long flags;
if (freezing(p)) {
pr_debug(" clean up: %s\n", p->comm);
clear_freeze_flag(p);
spin_lock_irqsave(&p->sighand->siglock, flags);
recalc_sigpending_and_wake(p);
spin_unlock_irqrestore(&p->sighand->siglock, flags);
}
}
static int __thaw_process(struct task_struct *p)
{
if (frozen(p)) {
p->flags &= ~PF_FROZEN;
return 1;
}
clear_freeze_flag(p);
return 0;
}
int thaw_process(struct task_struct *p)
{
task_lock(p);
if (__thaw_process(p) == 1) {
task_unlock(p);
wake_up_process(p);
return 1;
}
task_unlock(p);
return 0;
}
