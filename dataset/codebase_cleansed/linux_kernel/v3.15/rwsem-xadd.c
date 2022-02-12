void __init_rwsem(struct rw_semaphore *sem, const char *name,
struct lock_class_key *key)
{
#ifdef CONFIG_DEBUG_LOCK_ALLOC
debug_check_no_locks_freed((void *)sem, sizeof(*sem));
lockdep_init_map(&sem->dep_map, name, key, 0);
#endif
sem->count = RWSEM_UNLOCKED_VALUE;
raw_spin_lock_init(&sem->wait_lock);
INIT_LIST_HEAD(&sem->wait_list);
}
static struct rw_semaphore *
__rwsem_do_wake(struct rw_semaphore *sem, enum rwsem_wake_type wake_type)
{
struct rwsem_waiter *waiter;
struct task_struct *tsk;
struct list_head *next;
long oldcount, woken, loop, adjustment;
waiter = list_entry(sem->wait_list.next, struct rwsem_waiter, list);
if (waiter->type == RWSEM_WAITING_FOR_WRITE) {
if (wake_type == RWSEM_WAKE_ANY)
wake_up_process(waiter->task);
goto out;
}
adjustment = 0;
if (wake_type != RWSEM_WAKE_READ_OWNED) {
adjustment = RWSEM_ACTIVE_READ_BIAS;
try_reader_grant:
oldcount = rwsem_atomic_update(adjustment, sem) - adjustment;
if (unlikely(oldcount < RWSEM_WAITING_BIAS)) {
if (rwsem_atomic_update(-adjustment, sem) &
RWSEM_ACTIVE_MASK)
goto out;
goto try_reader_grant;
}
}
woken = 0;
do {
woken++;
if (waiter->list.next == &sem->wait_list)
break;
waiter = list_entry(waiter->list.next,
struct rwsem_waiter, list);
} while (waiter->type != RWSEM_WAITING_FOR_WRITE);
adjustment = woken * RWSEM_ACTIVE_READ_BIAS - adjustment;
if (waiter->type != RWSEM_WAITING_FOR_WRITE)
adjustment -= RWSEM_WAITING_BIAS;
if (adjustment)
rwsem_atomic_add(adjustment, sem);
next = sem->wait_list.next;
loop = woken;
do {
waiter = list_entry(next, struct rwsem_waiter, list);
next = waiter->list.next;
tsk = waiter->task;
smp_mb();
waiter->task = NULL;
wake_up_process(tsk);
put_task_struct(tsk);
} while (--loop);
sem->wait_list.next = next;
next->prev = &sem->wait_list;
out:
return sem;
}
__visible
struct rw_semaphore __sched *rwsem_down_read_failed(struct rw_semaphore *sem)
{
long count, adjustment = -RWSEM_ACTIVE_READ_BIAS;
struct rwsem_waiter waiter;
struct task_struct *tsk = current;
waiter.task = tsk;
waiter.type = RWSEM_WAITING_FOR_READ;
get_task_struct(tsk);
raw_spin_lock_irq(&sem->wait_lock);
if (list_empty(&sem->wait_list))
adjustment += RWSEM_WAITING_BIAS;
list_add_tail(&waiter.list, &sem->wait_list);
count = rwsem_atomic_update(adjustment, sem);
if (count == RWSEM_WAITING_BIAS ||
(count > RWSEM_WAITING_BIAS &&
adjustment != -RWSEM_ACTIVE_READ_BIAS))
sem = __rwsem_do_wake(sem, RWSEM_WAKE_ANY);
raw_spin_unlock_irq(&sem->wait_lock);
while (true) {
set_task_state(tsk, TASK_UNINTERRUPTIBLE);
if (!waiter.task)
break;
schedule();
}
tsk->state = TASK_RUNNING;
return sem;
}
__visible
struct rw_semaphore __sched *rwsem_down_write_failed(struct rw_semaphore *sem)
{
long count, adjustment = -RWSEM_ACTIVE_WRITE_BIAS;
struct rwsem_waiter waiter;
struct task_struct *tsk = current;
waiter.task = tsk;
waiter.type = RWSEM_WAITING_FOR_WRITE;
raw_spin_lock_irq(&sem->wait_lock);
if (list_empty(&sem->wait_list))
adjustment += RWSEM_WAITING_BIAS;
list_add_tail(&waiter.list, &sem->wait_list);
count = rwsem_atomic_update(adjustment, sem);
if (count > RWSEM_WAITING_BIAS &&
adjustment == -RWSEM_ACTIVE_WRITE_BIAS)
sem = __rwsem_do_wake(sem, RWSEM_WAKE_READERS);
set_task_state(tsk, TASK_UNINTERRUPTIBLE);
while (true) {
if (!(count & RWSEM_ACTIVE_MASK)) {
count = RWSEM_ACTIVE_WRITE_BIAS;
if (!list_is_singular(&sem->wait_list))
count += RWSEM_WAITING_BIAS;
if (sem->count == RWSEM_WAITING_BIAS &&
cmpxchg(&sem->count, RWSEM_WAITING_BIAS, count) ==
RWSEM_WAITING_BIAS)
break;
}
raw_spin_unlock_irq(&sem->wait_lock);
do {
schedule();
set_task_state(tsk, TASK_UNINTERRUPTIBLE);
} while ((count = sem->count) & RWSEM_ACTIVE_MASK);
raw_spin_lock_irq(&sem->wait_lock);
}
list_del(&waiter.list);
raw_spin_unlock_irq(&sem->wait_lock);
tsk->state = TASK_RUNNING;
return sem;
}
__visible
struct rw_semaphore *rwsem_wake(struct rw_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (!list_empty(&sem->wait_list))
sem = __rwsem_do_wake(sem, RWSEM_WAKE_ANY);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
return sem;
}
__visible
struct rw_semaphore *rwsem_downgrade_wake(struct rw_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (!list_empty(&sem->wait_list))
sem = __rwsem_do_wake(sem, RWSEM_WAKE_READ_OWNED);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
return sem;
}
