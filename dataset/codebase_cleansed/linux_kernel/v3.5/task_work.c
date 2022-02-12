int
task_work_add(struct task_struct *task, struct task_work *twork, bool notify)
{
unsigned long flags;
int err = -ESRCH;
#ifndef TIF_NOTIFY_RESUME
if (notify)
return -ENOTSUPP;
#endif
raw_spin_lock_irqsave(&task->pi_lock, flags);
if (likely(!(task->flags & PF_EXITING))) {
hlist_add_head(&twork->hlist, &task->task_works);
err = 0;
}
raw_spin_unlock_irqrestore(&task->pi_lock, flags);
if (likely(!err) && notify)
set_notify_resume(task);
return err;
}
struct task_work *
task_work_cancel(struct task_struct *task, task_work_func_t func)
{
unsigned long flags;
struct task_work *twork;
struct hlist_node *pos;
raw_spin_lock_irqsave(&task->pi_lock, flags);
hlist_for_each_entry(twork, pos, &task->task_works, hlist) {
if (twork->func == func) {
hlist_del(&twork->hlist);
goto found;
}
}
twork = NULL;
found:
raw_spin_unlock_irqrestore(&task->pi_lock, flags);
return twork;
}
void task_work_run(void)
{
struct task_struct *task = current;
struct hlist_head task_works;
struct hlist_node *pos;
raw_spin_lock_irq(&task->pi_lock);
hlist_move_list(&task->task_works, &task_works);
raw_spin_unlock_irq(&task->pi_lock);
if (unlikely(hlist_empty(&task_works)))
return;
for (pos = task_works.first; pos->next; pos = pos->next)
;
for (;;) {
struct hlist_node **pprev = pos->pprev;
struct task_work *twork = container_of(pos, struct task_work,
hlist);
twork->func(twork);
if (pprev == &task_works.first)
break;
pos = container_of(pprev, struct hlist_node, next);
}
}
