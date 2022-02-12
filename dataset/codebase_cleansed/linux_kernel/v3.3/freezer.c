bool freezing_slow_path(struct task_struct *p)
{
if (p->flags & PF_NOFREEZE)
return false;
if (pm_nosig_freezing || cgroup_freezing(p))
return true;
if (pm_freezing && !(p->flags & PF_KTHREAD))
return true;
return false;
}
bool __refrigerator(bool check_kthr_stop)
{
bool was_frozen = false;
long save = current->state;
pr_debug("%s entered refrigerator\n", current->comm);
for (;;) {
set_current_state(TASK_UNINTERRUPTIBLE);
spin_lock_irq(&freezer_lock);
current->flags |= PF_FROZEN;
if (!freezing(current) ||
(check_kthr_stop && kthread_should_stop()))
current->flags &= ~PF_FROZEN;
spin_unlock_irq(&freezer_lock);
if (!(current->flags & PF_FROZEN))
break;
was_frozen = true;
schedule();
}
pr_debug("%s left refrigerator\n", current->comm);
set_current_state(save);
return was_frozen;
}
static void fake_signal_wake_up(struct task_struct *p)
{
unsigned long flags;
if (lock_task_sighand(p, &flags)) {
signal_wake_up(p, 0);
unlock_task_sighand(p, &flags);
}
}
bool freeze_task(struct task_struct *p)
{
unsigned long flags;
spin_lock_irqsave(&freezer_lock, flags);
if (!freezing(p) || frozen(p)) {
spin_unlock_irqrestore(&freezer_lock, flags);
return false;
}
if (!(p->flags & PF_KTHREAD)) {
fake_signal_wake_up(p);
} else {
wake_up_state(p, TASK_INTERRUPTIBLE);
}
spin_unlock_irqrestore(&freezer_lock, flags);
return true;
}
void __thaw_task(struct task_struct *p)
{
unsigned long flags;
spin_lock_irqsave(&freezer_lock, flags);
if (frozen(p))
wake_up_process(p);
spin_unlock_irqrestore(&freezer_lock, flags);
}
bool set_freezable(void)
{
might_sleep();
spin_lock_irq(&freezer_lock);
current->flags &= ~PF_NOFREEZE;
spin_unlock_irq(&freezer_lock);
return try_to_freeze();
}
