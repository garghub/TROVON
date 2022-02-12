int
task_work_add(struct task_struct *task, struct callback_head *twork, bool notify)
{
struct callback_head *last, *first;
unsigned long flags;
raw_spin_lock_irqsave(&task->pi_lock, flags);
last = task->task_works;
first = last ? last->next : twork;
twork->next = first;
if (last)
last->next = twork;
task->task_works = twork;
raw_spin_unlock_irqrestore(&task->pi_lock, flags);
if (notify)
set_notify_resume(task);
return 0;
}
struct callback_head *
task_work_cancel(struct task_struct *task, task_work_func_t func)
{
unsigned long flags;
struct callback_head *last, *res = NULL;
raw_spin_lock_irqsave(&task->pi_lock, flags);
last = task->task_works;
if (last) {
struct callback_head *q = last, *p = q->next;
while (1) {
if (p->func == func) {
q->next = p->next;
if (p == last)
task->task_works = q == p ? NULL : q;
res = p;
break;
}
if (p == last)
break;
q = p;
p = q->next;
}
}
raw_spin_unlock_irqrestore(&task->pi_lock, flags);
return res;
}
void task_work_run(void)
{
struct task_struct *task = current;
struct callback_head *p, *q;
while (1) {
raw_spin_lock_irq(&task->pi_lock);
p = task->task_works;
task->task_works = NULL;
raw_spin_unlock_irq(&task->pi_lock);
if (unlikely(!p))
return;
q = p->next;
p->next = NULL;
while (q) {
p = q->next;
q->func(q);
q = p;
cond_resched();
}
}
}
