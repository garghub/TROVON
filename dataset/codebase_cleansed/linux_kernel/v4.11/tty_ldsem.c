static inline long ldsem_atomic_update(long delta, struct ld_semaphore *sem)
{
return atomic_long_add_return(delta, (atomic_long_t *)&sem->count);
}
static inline int ldsem_cmpxchg(long *old, long new, struct ld_semaphore *sem)
{
long tmp = atomic_long_cmpxchg(&sem->count, *old, new);
if (tmp == *old) {
*old = new;
return 1;
} else {
*old = tmp;
return 0;
}
}
void __init_ldsem(struct ld_semaphore *sem, const char *name,
struct lock_class_key *key)
{
#ifdef CONFIG_DEBUG_LOCK_ALLOC
debug_check_no_locks_freed((void *)sem, sizeof(*sem));
lockdep_init_map(&sem->dep_map, name, key, 0);
#endif
sem->count = LDSEM_UNLOCKED;
sem->wait_readers = 0;
raw_spin_lock_init(&sem->wait_lock);
INIT_LIST_HEAD(&sem->read_wait);
INIT_LIST_HEAD(&sem->write_wait);
}
static void __ldsem_wake_readers(struct ld_semaphore *sem)
{
struct ldsem_waiter *waiter, *next;
struct task_struct *tsk;
long adjust, count;
adjust = sem->wait_readers * (LDSEM_ACTIVE_BIAS - LDSEM_WAIT_BIAS);
count = ldsem_atomic_update(adjust, sem);
do {
if (count > 0)
break;
if (ldsem_cmpxchg(&count, count - adjust, sem))
return;
} while (1);
list_for_each_entry_safe(waiter, next, &sem->read_wait, list) {
tsk = waiter->task;
smp_mb();
waiter->task = NULL;
wake_up_process(tsk);
put_task_struct(tsk);
}
INIT_LIST_HEAD(&sem->read_wait);
sem->wait_readers = 0;
}
static inline int writer_trylock(struct ld_semaphore *sem)
{
long count = ldsem_atomic_update(LDSEM_ACTIVE_BIAS, sem);
do {
if ((count & LDSEM_ACTIVE_MASK) == LDSEM_ACTIVE_BIAS)
return 1;
if (ldsem_cmpxchg(&count, count - LDSEM_ACTIVE_BIAS, sem))
return 0;
} while (1);
}
static void __ldsem_wake_writer(struct ld_semaphore *sem)
{
struct ldsem_waiter *waiter;
waiter = list_entry(sem->write_wait.next, struct ldsem_waiter, list);
wake_up_process(waiter->task);
}
static void __ldsem_wake(struct ld_semaphore *sem)
{
if (!list_empty(&sem->write_wait))
__ldsem_wake_writer(sem);
else if (!list_empty(&sem->read_wait))
__ldsem_wake_readers(sem);
}
static void ldsem_wake(struct ld_semaphore *sem)
{
unsigned long flags;
raw_spin_lock_irqsave(&sem->wait_lock, flags);
__ldsem_wake(sem);
raw_spin_unlock_irqrestore(&sem->wait_lock, flags);
}
static struct ld_semaphore __sched *
down_read_failed(struct ld_semaphore *sem, long count, long timeout)
{
struct ldsem_waiter waiter;
long adjust = -LDSEM_ACTIVE_BIAS + LDSEM_WAIT_BIAS;
raw_spin_lock_irq(&sem->wait_lock);
do {
if (ldsem_cmpxchg(&count, count + adjust, sem))
break;
if (count > 0) {
raw_spin_unlock_irq(&sem->wait_lock);
return sem;
}
} while (1);
list_add_tail(&waiter.list, &sem->read_wait);
sem->wait_readers++;
waiter.task = current;
get_task_struct(current);
if ((count & LDSEM_ACTIVE_MASK) == 0)
__ldsem_wake(sem);
raw_spin_unlock_irq(&sem->wait_lock);
for (;;) {
set_current_state(TASK_UNINTERRUPTIBLE);
if (!waiter.task)
break;
if (!timeout)
break;
timeout = schedule_timeout(timeout);
}
__set_current_state(TASK_RUNNING);
if (!timeout) {
raw_spin_lock_irq(&sem->wait_lock);
if (waiter.task) {
ldsem_atomic_update(-LDSEM_WAIT_BIAS, sem);
list_del(&waiter.list);
raw_spin_unlock_irq(&sem->wait_lock);
put_task_struct(waiter.task);
return NULL;
}
raw_spin_unlock_irq(&sem->wait_lock);
}
return sem;
}
static struct ld_semaphore __sched *
down_write_failed(struct ld_semaphore *sem, long count, long timeout)
{
struct ldsem_waiter waiter;
long adjust = -LDSEM_ACTIVE_BIAS;
int locked = 0;
raw_spin_lock_irq(&sem->wait_lock);
do {
if (ldsem_cmpxchg(&count, count + adjust, sem))
break;
if ((count & LDSEM_ACTIVE_MASK) == LDSEM_ACTIVE_BIAS) {
raw_spin_unlock_irq(&sem->wait_lock);
return sem;
}
} while (1);
list_add_tail(&waiter.list, &sem->write_wait);
waiter.task = current;
set_current_state(TASK_UNINTERRUPTIBLE);
for (;;) {
if (!timeout)
break;
raw_spin_unlock_irq(&sem->wait_lock);
timeout = schedule_timeout(timeout);
raw_spin_lock_irq(&sem->wait_lock);
set_current_state(TASK_UNINTERRUPTIBLE);
locked = writer_trylock(sem);
if (locked)
break;
}
if (!locked)
ldsem_atomic_update(-LDSEM_WAIT_BIAS, sem);
list_del(&waiter.list);
raw_spin_unlock_irq(&sem->wait_lock);
__set_current_state(TASK_RUNNING);
if (!locked)
return NULL;
return sem;
}
static int __ldsem_down_read_nested(struct ld_semaphore *sem,
int subclass, long timeout)
{
long count;
lockdep_acquire_read(sem, subclass, 0, _RET_IP_);
count = ldsem_atomic_update(LDSEM_READ_BIAS, sem);
if (count <= 0) {
lock_stat(sem, contended);
if (!down_read_failed(sem, count, timeout)) {
lockdep_release(sem, 1, _RET_IP_);
return 0;
}
}
lock_stat(sem, acquired);
return 1;
}
static int __ldsem_down_write_nested(struct ld_semaphore *sem,
int subclass, long timeout)
{
long count;
lockdep_acquire(sem, subclass, 0, _RET_IP_);
count = ldsem_atomic_update(LDSEM_WRITE_BIAS, sem);
if ((count & LDSEM_ACTIVE_MASK) != LDSEM_ACTIVE_BIAS) {
lock_stat(sem, contended);
if (!down_write_failed(sem, count, timeout)) {
lockdep_release(sem, 1, _RET_IP_);
return 0;
}
}
lock_stat(sem, acquired);
return 1;
}
int __sched ldsem_down_read(struct ld_semaphore *sem, long timeout)
{
might_sleep();
return __ldsem_down_read_nested(sem, 0, timeout);
}
int ldsem_down_read_trylock(struct ld_semaphore *sem)
{
long count = sem->count;
while (count >= 0) {
if (ldsem_cmpxchg(&count, count + LDSEM_READ_BIAS, sem)) {
lockdep_acquire_read(sem, 0, 1, _RET_IP_);
lock_stat(sem, acquired);
return 1;
}
}
return 0;
}
int __sched ldsem_down_write(struct ld_semaphore *sem, long timeout)
{
might_sleep();
return __ldsem_down_write_nested(sem, 0, timeout);
}
int ldsem_down_write_trylock(struct ld_semaphore *sem)
{
long count = sem->count;
while ((count & LDSEM_ACTIVE_MASK) == 0) {
if (ldsem_cmpxchg(&count, count + LDSEM_WRITE_BIAS, sem)) {
lockdep_acquire(sem, 0, 1, _RET_IP_);
lock_stat(sem, acquired);
return 1;
}
}
return 0;
}
void ldsem_up_read(struct ld_semaphore *sem)
{
long count;
lockdep_release(sem, 1, _RET_IP_);
count = ldsem_atomic_update(-LDSEM_READ_BIAS, sem);
if (count < 0 && (count & LDSEM_ACTIVE_MASK) == 0)
ldsem_wake(sem);
}
void ldsem_up_write(struct ld_semaphore *sem)
{
long count;
lockdep_release(sem, 1, _RET_IP_);
count = ldsem_atomic_update(-LDSEM_WRITE_BIAS, sem);
if (count < 0)
ldsem_wake(sem);
}
int ldsem_down_read_nested(struct ld_semaphore *sem, int subclass, long timeout)
{
might_sleep();
return __ldsem_down_read_nested(sem, subclass, timeout);
}
int ldsem_down_write_nested(struct ld_semaphore *sem, int subclass,
long timeout)
{
might_sleep();
return __ldsem_down_write_nested(sem, subclass, timeout);
}
