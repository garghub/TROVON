int rwsem_is_locked(struct rw_semaphore *sem)
{
int ret = 1;
unsigned long flags;
if (raw_spin_trylock_irqsave(&sem->wait_lock, flags)) {
ret = (sem->count != 0);
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
sem->count = 0;
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
if (waiter->type == RWSEM_WAITING_FOR_WRITE) {
if (wakewrite)
wake_up_process(waiter->task);
goto out;
}
woken = 0;
do {
struct list_head *next = waiter->list.next;
list_del(&waiter->list);
tsk = waiter->task;
smp_mb();
waiter->task = NULL;
wake_up_process(tsk);
put_task_struct(tsk);
woken++;
if (next == &sem->wait_list)
break;
waiter = list_entry(next, struct rwsem_waiter, list);
} while (waiter->type != RWSEM_WAITING_FOR_WRITE);
sem->count += woken;
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
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (sem->count >= 0 && list_empty(&sem->wait_list)) {
sem->count++;
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
goto out;
}
set_current_state(TASK_UNINTERRUPTIBLE);
waiter.task = current;
waiter.type = RWSEM_WAITING_FOR_READ;
get_task_struct(current);
list_add_tail(&waiter.list, &sem->wait_list);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
for (;;) {
if (!waiter.task)
break;
schedule();
set_current_state(TASK_UNINTERRUPTIBLE);
}
__set_current_state(TASK_RUNNING);
out:
;
}
int __down_read_trylock(struct rw_semaphore *sem)
{
unsigned long flags;
int ret = 0;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (sem->count >= 0 && list_empty(&sem->wait_list)) {
sem->count++;
ret = 1;
}
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
return ret;
}
int __sched __down_write_common(struct rw_semaphore *sem, int state)
{
struct rwsem_waiter waiter;
unsigned long flags;
int ret = 0;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
waiter.task = current;
waiter.type = RWSEM_WAITING_FOR_WRITE;
list_add_tail(&waiter.list, &sem->wait_list);
for (;;) {
if (sem->count == 0)
break;
if (signal_pending_state(state, current))
goto out_nolock;
set_current_state(state);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
schedule();
raw_spin_lock_irqsave(&sem->wait_lock, flags);
}
sem->count = -1;
list_del(&waiter.list);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
return ret;
out_nolock:
list_del(&waiter.list);
if (!list_empty(&sem->wait_list) && sem->count >= 0)
__rwsem_do_wake(sem, 0);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
return -EINTR;
}
void __sched __down_write(struct rw_semaphore *sem)
{
__down_write_common(sem, TASK_UNINTERRUPTIBLE);
}
int __sched __down_write_killable(struct rw_semaphore *sem)
{
return __down_write_common(sem, TASK_KILLABLE);
}
int __down_write_trylock(struct rw_semaphore *sem)
{
unsigned long flags;
int ret = 0;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (sem->count == 0) {
sem->count = -1;
ret = 1;
}
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
return ret;
}
void __up_read(struct rw_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (--sem->count == 0 && !list_empty(&sem->wait_list))
sem = __rwsem_wake_one_writer(sem);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
void __up_write(struct rw_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
sem->count = 0;
if (!list_empty(&sem->wait_list))
sem = __rwsem_do_wake(sem, 1);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
void __downgrade_write(struct rw_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
sem->count = 1;
if (!list_empty(&sem->wait_list))
sem = __rwsem_do_wake(sem, 0);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
