void down(struct semaphore *sem)
{
unsigned long flags;
spin_lock_irqsave(&sem->lock, flags);
if (likely(sem->count > 0))
sem->count--;
else
__down(sem);
spin_unlock_irqrestore(&sem->lock, flags);
}
int down_interruptible(struct semaphore *sem)
{
unsigned long flags;
int result = 0;
spin_lock_irqsave(&sem->lock, flags);
if (likely(sem->count > 0))
sem->count--;
else
result = __down_interruptible(sem);
spin_unlock_irqrestore(&sem->lock, flags);
return result;
}
int down_killable(struct semaphore *sem)
{
unsigned long flags;
int result = 0;
spin_lock_irqsave(&sem->lock, flags);
if (likely(sem->count > 0))
sem->count--;
else
result = __down_killable(sem);
spin_unlock_irqrestore(&sem->lock, flags);
return result;
}
int down_trylock(struct semaphore *sem)
{
unsigned long flags;
int count;
spin_lock_irqsave(&sem->lock, flags);
count = sem->count - 1;
if (likely(count >= 0))
sem->count = count;
spin_unlock_irqrestore(&sem->lock, flags);
return (count < 0);
}
int down_timeout(struct semaphore *sem, long jiffies)
{
unsigned long flags;
int result = 0;
spin_lock_irqsave(&sem->lock, flags);
if (likely(sem->count > 0))
sem->count--;
else
result = __down_timeout(sem, jiffies);
spin_unlock_irqrestore(&sem->lock, flags);
return result;
}
void up(struct semaphore *sem)
{
unsigned long flags;
spin_lock_irqsave(&sem->lock, flags);
if (likely(list_empty(&sem->wait_list)))
sem->count++;
else
__up(sem);
spin_unlock_irqrestore(&sem->lock, flags);
}
static inline int __sched __down_common(struct semaphore *sem, long state,
long timeout)
{
struct task_struct *task = current;
struct semaphore_waiter waiter;
list_add_tail(&waiter.list, &sem->wait_list);
waiter.task = task;
waiter.up = 0;
for (;;) {
if (signal_pending_state(state, task))
goto interrupted;
if (timeout <= 0)
goto timed_out;
__set_task_state(task, state);
spin_unlock_irq(&sem->lock);
timeout = schedule_timeout(timeout);
spin_lock_irq(&sem->lock);
if (waiter.up)
return 0;
}
timed_out:
list_del(&waiter.list);
return -ETIME;
interrupted:
list_del(&waiter.list);
return -EINTR;
}
static noinline void __sched __down(struct semaphore *sem)
{
__down_common(sem, TASK_UNINTERRUPTIBLE, MAX_SCHEDULE_TIMEOUT);
}
static noinline int __sched __down_interruptible(struct semaphore *sem)
{
return __down_common(sem, TASK_INTERRUPTIBLE, MAX_SCHEDULE_TIMEOUT);
}
static noinline int __sched __down_killable(struct semaphore *sem)
{
return __down_common(sem, TASK_KILLABLE, MAX_SCHEDULE_TIMEOUT);
}
static noinline int __sched __down_timeout(struct semaphore *sem, long jiffies)
{
return __down_common(sem, TASK_UNINTERRUPTIBLE, jiffies);
}
static noinline void __sched __up(struct semaphore *sem)
{
struct semaphore_waiter *waiter = list_first_entry(&sem->wait_list,
struct semaphore_waiter, list);
list_del(&waiter->list);
waiter->up = 1;
wake_up_process(waiter->task);
}
