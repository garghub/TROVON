int rwsem_is_locked(struct rw_semaphore *sem)
{
int ret = 1;
unsigned long flags;
if (raw_spin_trylock_irqsave(&sem->wait_lock, flags)) {
ret = (sem->activity != 0);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
return ret;
}
void __init_rwsem(struct rw_semaphore *sem, const char *name,
struct lock_class_key *key)
{
#ifdef CONFIG_DEBUG_LOCK_ALLOC
debug_check_no_locks_freed((void *)sem, sizeof(*sem));
lockdep_init_map(&sem->dep_map, name, key, 0);
#endif
sem->activity = 0;
raw_spin_lock_init(&sem->wait_lock);
INIT_LIST_HEAD(&sem->wait_list);
}
static inline struct rw_semaphore *
__rwsem_do_wake(struct rw_semaphore *sem, int wakewrite)
{
struct rwsem_waiter *waiter;
struct task_struct *tsk;
int woken;
waiter = list_entry(sem->wait_list.next, struct rwsem_waiter, list);
if (!wakewrite) {
if (waiter->flags & RWSEM_WAITING_FOR_WRITE)
goto out;
goto dont_wake_writers;
}
if (waiter->flags & RWSEM_WAITING_FOR_WRITE) {
wake_up_process(waiter->task);
goto out;
}
dont_wake_writers:
woken = 0;
while (waiter->flags & RWSEM_WAITING_FOR_READ) {
struct list_head *next = waiter->list.next;
list_del(&waiter->list);
tsk = waiter->task;
smp_mb();
waiter->task = NULL;
wake_up_process(tsk);
put_task_struct(tsk);
woken++;
if (list_empty(&sem->wait_list))
break;
waiter = list_entry(next, struct rwsem_waiter, list);
}
sem->activity += woken;
out:
return sem;
}
static inline struct rw_semaphore *
__rwsem_wake_one_writer(struct rw_semaphore *sem)
{
struct rwsem_waiter *waiter;
waiter = list_entry(sem->wait_list.next, struct rwsem_waiter, list);
wake_up_process(waiter->task);
return sem;
}
void __sched __down_read(struct rw_semaphore *sem)
{
struct rwsem_waiter waiter;
struct task_struct *tsk;
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (sem->activity >= 0 && list_empty(&sem->wait_list)) {
sem->activity++;
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
goto out;
}
tsk = current;
set_task_state(tsk, TASK_UNINTERRUPTIBLE);
waiter.task = tsk;
waiter.flags = RWSEM_WAITING_FOR_READ;
get_task_struct(tsk);
list_add_tail(&waiter.list, &sem->wait_list);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
for (;;) {
if (!waiter.task)
break;
schedule();
set_task_state(tsk, TASK_UNINTERRUPTIBLE);
}
tsk->state = TASK_RUNNING;
out:
;
}
int __down_read_trylock(struct rw_semaphore *sem)
{
unsigned long flags;
int ret = 0;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (sem->activity >= 0 && list_empty(&sem->wait_list)) {
sem->activity++;
ret = 1;
}
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
return ret;
}
void __sched __down_write_nested(struct rw_semaphore *sem, int subclass)
{
struct rwsem_waiter waiter;
struct task_struct *tsk;
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
tsk = current;
waiter.task = tsk;
waiter.flags = RWSEM_WAITING_FOR_WRITE;
list_add_tail(&waiter.list, &sem->wait_list);
for (;;) {
if (sem->activity == 0)
break;
set_task_state(tsk, TASK_UNINTERRUPTIBLE);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
schedule();
raw_spin_lock_irqsave(&sem->wait_lock, flags);
}
sem->activity = -1;
list_del(&waiter.list);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
void __sched __down_write(struct rw_semaphore *sem)
{
__down_write_nested(sem, 0);
}
int __down_write_trylock(struct rw_semaphore *sem)
{
unsigned long flags;
int ret = 0;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (sem->activity == 0) {
sem->activity = -1;
ret = 1;
}
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
return ret;
}
void __up_read(struct rw_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (--sem->activity == 0 && !list_empty(&sem->wait_list))
sem = __rwsem_wake_one_writer(sem);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
void __up_write(struct rw_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
sem->activity = 0;
if (!list_empty(&sem->wait_list))
sem = __rwsem_do_wake(sem, 1);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
void __downgrade_write(struct rw_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
sem->activity = 1;
if (!list_empty(&sem->wait_list))
sem = __rwsem_do_wake(sem, 0);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
