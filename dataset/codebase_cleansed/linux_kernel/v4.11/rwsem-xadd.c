void __init_rwsem(struct rw_semaphore *sem, const char *name,
struct lock_class_key *key)
{
#ifdef CONFIG_DEBUG_LOCK_ALLOC
debug_check_no_locks_freed((void *)sem, sizeof(*sem));
lockdep_init_map(&sem->dep_map, name, key, 0);
#endif
atomic_long_set(&sem->count, RWSEM_UNLOCKED_VALUE);
raw_spin_lock_init(&sem->wait_lock);
INIT_LIST_HEAD(&sem->wait_list);
#ifdef CONFIG_RWSEM_SPIN_ON_OWNER
sem->owner = NULL;
osq_lock_init(&sem->osq);
#endif
}
static void __rwsem_mark_wake(struct rw_semaphore *sem,
enum rwsem_wake_type wake_type,
struct wake_q_head *wake_q)
{
struct rwsem_waiter *waiter, *tmp;
long oldcount, woken = 0, adjustment = 0;
waiter = list_first_entry(&sem->wait_list, struct rwsem_waiter, list);
if (waiter->type == RWSEM_WAITING_FOR_WRITE) {
if (wake_type == RWSEM_WAKE_ANY) {
wake_q_add(wake_q, waiter->task);
}
return;
}
if (wake_type != RWSEM_WAKE_READ_OWNED) {
adjustment = RWSEM_ACTIVE_READ_BIAS;
try_reader_grant:
oldcount = atomic_long_fetch_add(adjustment, &sem->count);
if (unlikely(oldcount < RWSEM_WAITING_BIAS)) {
if (atomic_long_add_return(-adjustment, &sem->count) <
RWSEM_WAITING_BIAS)
return;
goto try_reader_grant;
}
rwsem_set_reader_owned(sem);
}
list_for_each_entry_safe(waiter, tmp, &sem->wait_list, list) {
struct task_struct *tsk;
if (waiter->type == RWSEM_WAITING_FOR_WRITE)
break;
woken++;
tsk = waiter->task;
wake_q_add(wake_q, tsk);
list_del(&waiter->list);
smp_store_release(&waiter->task, NULL);
}
adjustment = woken * RWSEM_ACTIVE_READ_BIAS - adjustment;
if (list_empty(&sem->wait_list)) {
adjustment -= RWSEM_WAITING_BIAS;
}
if (adjustment)
atomic_long_add(adjustment, &sem->count);
}
__visible
struct rw_semaphore __sched *rwsem_down_read_failed(struct rw_semaphore *sem)
{
long count, adjustment = -RWSEM_ACTIVE_READ_BIAS;
struct rwsem_waiter waiter;
DEFINE_WAKE_Q(wake_q);
waiter.task = current;
waiter.type = RWSEM_WAITING_FOR_READ;
raw_spin_lock_irq(&sem->wait_lock);
if (list_empty(&sem->wait_list))
adjustment += RWSEM_WAITING_BIAS;
list_add_tail(&waiter.list, &sem->wait_list);
count = atomic_long_add_return(adjustment, &sem->count);
if (count == RWSEM_WAITING_BIAS ||
(count > RWSEM_WAITING_BIAS &&
adjustment != -RWSEM_ACTIVE_READ_BIAS))
__rwsem_mark_wake(sem, RWSEM_WAKE_ANY, &wake_q);
raw_spin_unlock_irq(&sem->wait_lock);
wake_up_q(&wake_q);
while (true) {
set_current_state(TASK_UNINTERRUPTIBLE);
if (!waiter.task)
break;
schedule();
}
__set_current_state(TASK_RUNNING);
return sem;
}
static inline bool rwsem_try_write_lock(long count, struct rw_semaphore *sem)
{
if (count != RWSEM_WAITING_BIAS)
return false;
count = list_is_singular(&sem->wait_list) ?
RWSEM_ACTIVE_WRITE_BIAS :
RWSEM_ACTIVE_WRITE_BIAS + RWSEM_WAITING_BIAS;
if (atomic_long_cmpxchg_acquire(&sem->count, RWSEM_WAITING_BIAS, count)
== RWSEM_WAITING_BIAS) {
rwsem_set_owner(sem);
return true;
}
return false;
}
static inline bool rwsem_try_write_lock_unqueued(struct rw_semaphore *sem)
{
long old, count = atomic_long_read(&sem->count);
while (true) {
if (!(count == 0 || count == RWSEM_WAITING_BIAS))
return false;
old = atomic_long_cmpxchg_acquire(&sem->count, count,
count + RWSEM_ACTIVE_WRITE_BIAS);
if (old == count) {
rwsem_set_owner(sem);
return true;
}
count = old;
}
}
static inline bool rwsem_can_spin_on_owner(struct rw_semaphore *sem)
{
struct task_struct *owner;
bool ret = true;
if (need_resched())
return false;
rcu_read_lock();
owner = READ_ONCE(sem->owner);
if (!rwsem_owner_is_writer(owner)) {
ret = !rwsem_owner_is_reader(owner);
goto done;
}
ret = owner->on_cpu && !vcpu_is_preempted(task_cpu(owner));
done:
rcu_read_unlock();
return ret;
}
static noinline bool rwsem_spin_on_owner(struct rw_semaphore *sem)
{
struct task_struct *owner = READ_ONCE(sem->owner);
if (!rwsem_owner_is_writer(owner))
goto out;
rcu_read_lock();
while (sem->owner == owner) {
barrier();
if (!owner->on_cpu || need_resched() ||
vcpu_is_preempted(task_cpu(owner))) {
rcu_read_unlock();
return false;
}
cpu_relax();
}
rcu_read_unlock();
out:
return !rwsem_owner_is_reader(READ_ONCE(sem->owner));
}
static bool rwsem_optimistic_spin(struct rw_semaphore *sem)
{
bool taken = false;
preempt_disable();
if (!rwsem_can_spin_on_owner(sem))
goto done;
if (!osq_lock(&sem->osq))
goto done;
while (rwsem_spin_on_owner(sem)) {
if (rwsem_try_write_lock_unqueued(sem)) {
taken = true;
break;
}
if (!sem->owner && (need_resched() || rt_task(current)))
break;
cpu_relax();
}
osq_unlock(&sem->osq);
done:
preempt_enable();
return taken;
}
static inline bool rwsem_has_spinner(struct rw_semaphore *sem)
{
return osq_is_locked(&sem->osq);
}
static bool rwsem_optimistic_spin(struct rw_semaphore *sem)
{
return false;
}
static inline bool rwsem_has_spinner(struct rw_semaphore *sem)
{
return false;
}
static inline struct rw_semaphore *
__rwsem_down_write_failed_common(struct rw_semaphore *sem, int state)
{
long count;
bool waiting = true;
struct rwsem_waiter waiter;
struct rw_semaphore *ret = sem;
DEFINE_WAKE_Q(wake_q);
count = atomic_long_sub_return(RWSEM_ACTIVE_WRITE_BIAS, &sem->count);
if (rwsem_optimistic_spin(sem))
return sem;
waiter.task = current;
waiter.type = RWSEM_WAITING_FOR_WRITE;
raw_spin_lock_irq(&sem->wait_lock);
if (list_empty(&sem->wait_list))
waiting = false;
list_add_tail(&waiter.list, &sem->wait_list);
if (waiting) {
count = atomic_long_read(&sem->count);
if (count > RWSEM_WAITING_BIAS) {
__rwsem_mark_wake(sem, RWSEM_WAKE_READERS, &wake_q);
wake_up_q(&wake_q);
wake_q_init(&wake_q);
}
} else
count = atomic_long_add_return(RWSEM_WAITING_BIAS, &sem->count);
set_current_state(state);
while (true) {
if (rwsem_try_write_lock(count, sem))
break;
raw_spin_unlock_irq(&sem->wait_lock);
do {
if (signal_pending_state(state, current))
goto out_nolock;
schedule();
set_current_state(state);
} while ((count = atomic_long_read(&sem->count)) & RWSEM_ACTIVE_MASK);
raw_spin_lock_irq(&sem->wait_lock);
}
__set_current_state(TASK_RUNNING);
list_del(&waiter.list);
raw_spin_unlock_irq(&sem->wait_lock);
return ret;
out_nolock:
__set_current_state(TASK_RUNNING);
raw_spin_lock_irq(&sem->wait_lock);
list_del(&waiter.list);
if (list_empty(&sem->wait_list))
atomic_long_add(-RWSEM_WAITING_BIAS, &sem->count);
else
__rwsem_mark_wake(sem, RWSEM_WAKE_ANY, &wake_q);
raw_spin_unlock_irq(&sem->wait_lock);
wake_up_q(&wake_q);
return ERR_PTR(-EINTR);
}
__visible struct rw_semaphore * __sched
rwsem_down_write_failed(struct rw_semaphore *sem)
{
return __rwsem_down_write_failed_common(sem, TASK_UNINTERRUPTIBLE);
}
__visible struct rw_semaphore * __sched
rwsem_down_write_failed_killable(struct rw_semaphore *sem)
{
return __rwsem_down_write_failed_common(sem, TASK_KILLABLE);
}
__visible
struct rw_semaphore *rwsem_wake(struct rw_semaphore *sem)
{
unsigned long flags;
DEFINE_WAKE_Q(wake_q);
if (rwsem_has_spinner(sem)) {
smp_rmb();
if (!raw_spin_trylock_irqsave(&sem->wait_lock, flags))
return sem;
goto locked;
}
raw_spin_lock_irqsave(&sem->wait_lock, flags);
locked:
if (!list_empty(&sem->wait_list))
__rwsem_mark_wake(sem, RWSEM_WAKE_ANY, &wake_q);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
wake_up_q(&wake_q);
return sem;
}
__visible
struct rw_semaphore *rwsem_downgrade_wake(struct rw_semaphore *sem)
{
unsigned long flags;
DEFINE_WAKE_Q(wake_q);
raw_spin_lock_irqsave(&sem->wait_lock, flags);
if (!list_empty(&sem->wait_list))
__rwsem_mark_wake(sem, RWSEM_WAKE_READ_OWNED, &wake_q);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
wake_up_q(&wake_q);
return sem;
}
