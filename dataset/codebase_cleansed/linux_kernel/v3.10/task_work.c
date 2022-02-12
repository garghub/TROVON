int
task_work_add(struct task_struct *task, struct callback_head *work, bool notify)
{
struct callback_head *head;
do {
head = ACCESS_ONCE(task->task_works);
if (unlikely(head == &work_exited))
return -ESRCH;
work->next = head;
} while (cmpxchg(&task->task_works, head, work) != head);
if (notify)
set_notify_resume(task);
return 0;
}
struct callback_head *
task_work_cancel(struct task_struct *task, task_work_func_t func)
{
struct callback_head **pprev = &task->task_works;
struct callback_head *work = NULL;
unsigned long flags;
raw_spin_lock_irqsave(&task->pi_lock, flags);
while ((work = ACCESS_ONCE(*pprev))) {
read_barrier_depends();
if (work->func != func)
pprev = &work->next;
else if (cmpxchg(pprev, work, work->next) == work)
break;
}
raw_spin_unlock_irqrestore(&task->pi_lock, flags);
return work;
}
void task_work_run(void)
{
struct task_struct *task = current;
struct callback_head *work, *head, *next;
for (;;) {
do {
work = ACCESS_ONCE(task->task_works);
head = !work && (task->flags & PF_EXITING) ?
&work_exited : NULL;
} while (cmpxchg(&task->task_works, work, head) != work);
if (!work)
break;
raw_spin_unlock_wait(&task->pi_lock);
smp_mb();
head = NULL;
do {
next = work->next;
work->next = head;
head = work;
work = next;
} while (work);
work = head;
do {
next = work->next;
work->func(work);
work = next;
cond_resched();
} while (work);
}
}
