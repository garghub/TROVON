void
__mutex_init(struct mutex *lock, const char *name, struct lock_class_key *key)
{
atomic_set(&lock->count, 1);
spin_lock_init(&lock->wait_lock);
INIT_LIST_HEAD(&lock->wait_list);
mutex_clear_owner(lock);
debug_mutex_init(lock, name, key);
}
void __sched mutex_lock(struct mutex *lock)
{
might_sleep();
__mutex_fastpath_lock(&lock->count, __mutex_lock_slowpath);
mutex_set_owner(lock);
}
void __sched mutex_unlock(struct mutex *lock)
{
#ifndef CONFIG_DEBUG_MUTEXES
mutex_clear_owner(lock);
#endif
__mutex_fastpath_unlock(&lock->count, __mutex_unlock_slowpath);
}
static inline int __sched
__mutex_lock_common(struct mutex *lock, long state, unsigned int subclass,
struct lockdep_map *nest_lock, unsigned long ip)
{
struct task_struct *task = current;
struct mutex_waiter waiter;
unsigned long flags;
preempt_disable();
mutex_acquire_nest(&lock->dep_map, subclass, 0, nest_lock, ip);
#ifdef CONFIG_MUTEX_SPIN_ON_OWNER
for (;;) {
struct task_struct *owner;
owner = ACCESS_ONCE(lock->owner);
if (owner && !mutex_spin_on_owner(lock, owner))
break;
if (atomic_cmpxchg(&lock->count, 1, 0) == 1) {
lock_acquired(&lock->dep_map, ip);
mutex_set_owner(lock);
preempt_enable();
return 0;
}
if (!owner && (need_resched() || rt_task(task)))
break;
arch_mutex_cpu_relax();
}
#endif
spin_lock_mutex(&lock->wait_lock, flags);
debug_mutex_lock_common(lock, &waiter);
debug_mutex_add_waiter(lock, &waiter, task_thread_info(task));
list_add_tail(&waiter.list, &lock->wait_list);
waiter.task = task;
if (atomic_xchg(&lock->count, -1) == 1)
goto done;
lock_contended(&lock->dep_map, ip);
for (;;) {
if (atomic_xchg(&lock->count, -1) == 1)
break;
if (unlikely(signal_pending_state(state, task))) {
mutex_remove_waiter(lock, &waiter,
task_thread_info(task));
mutex_release(&lock->dep_map, 1, ip);
spin_unlock_mutex(&lock->wait_lock, flags);
debug_mutex_free_waiter(&waiter);
preempt_enable();
return -EINTR;
}
__set_task_state(task, state);
spin_unlock_mutex(&lock->wait_lock, flags);
schedule_preempt_disabled();
spin_lock_mutex(&lock->wait_lock, flags);
}
done:
lock_acquired(&lock->dep_map, ip);
mutex_remove_waiter(lock, &waiter, current_thread_info());
mutex_set_owner(lock);
if (likely(list_empty(&lock->wait_list)))
atomic_set(&lock->count, 0);
spin_unlock_mutex(&lock->wait_lock, flags);
debug_mutex_free_waiter(&waiter);
preempt_enable();
return 0;
}
void __sched
mutex_lock_nested(struct mutex *lock, unsigned int subclass)
{
might_sleep();
__mutex_lock_common(lock, TASK_UNINTERRUPTIBLE, subclass, NULL, _RET_IP_);
}
void __sched
_mutex_lock_nest_lock(struct mutex *lock, struct lockdep_map *nest)
{
might_sleep();
__mutex_lock_common(lock, TASK_UNINTERRUPTIBLE, 0, nest, _RET_IP_);
}
int __sched
mutex_lock_killable_nested(struct mutex *lock, unsigned int subclass)
{
might_sleep();
return __mutex_lock_common(lock, TASK_KILLABLE, subclass, NULL, _RET_IP_);
}
int __sched
mutex_lock_interruptible_nested(struct mutex *lock, unsigned int subclass)
{
might_sleep();
return __mutex_lock_common(lock, TASK_INTERRUPTIBLE,
subclass, NULL, _RET_IP_);
}
static inline void
__mutex_unlock_common_slowpath(atomic_t *lock_count, int nested)
{
struct mutex *lock = container_of(lock_count, struct mutex, count);
unsigned long flags;
spin_lock_mutex(&lock->wait_lock, flags);
mutex_release(&lock->dep_map, nested, _RET_IP_);
debug_mutex_unlock(lock);
if (__mutex_slowpath_needs_to_unlock())
atomic_set(&lock->count, 1);
if (!list_empty(&lock->wait_list)) {
struct mutex_waiter *waiter =
list_entry(lock->wait_list.next,
struct mutex_waiter, list);
debug_mutex_wake_waiter(lock, waiter);
wake_up_process(waiter->task);
}
spin_unlock_mutex(&lock->wait_lock, flags);
}
static __used noinline void
__mutex_unlock_slowpath(atomic_t *lock_count)
{
__mutex_unlock_common_slowpath(lock_count, 1);
}
int __sched mutex_lock_interruptible(struct mutex *lock)
{
int ret;
might_sleep();
ret = __mutex_fastpath_lock_retval
(&lock->count, __mutex_lock_interruptible_slowpath);
if (!ret)
mutex_set_owner(lock);
return ret;
}
int __sched mutex_lock_killable(struct mutex *lock)
{
int ret;
might_sleep();
ret = __mutex_fastpath_lock_retval
(&lock->count, __mutex_lock_killable_slowpath);
if (!ret)
mutex_set_owner(lock);
return ret;
}
static __used noinline void __sched
__mutex_lock_slowpath(atomic_t *lock_count)
{
struct mutex *lock = container_of(lock_count, struct mutex, count);
__mutex_lock_common(lock, TASK_UNINTERRUPTIBLE, 0, NULL, _RET_IP_);
}
static noinline int __sched
__mutex_lock_killable_slowpath(atomic_t *lock_count)
{
struct mutex *lock = container_of(lock_count, struct mutex, count);
return __mutex_lock_common(lock, TASK_KILLABLE, 0, NULL, _RET_IP_);
}
static noinline int __sched
__mutex_lock_interruptible_slowpath(atomic_t *lock_count)
{
struct mutex *lock = container_of(lock_count, struct mutex, count);
return __mutex_lock_common(lock, TASK_INTERRUPTIBLE, 0, NULL, _RET_IP_);
}
static inline int __mutex_trylock_slowpath(atomic_t *lock_count)
{
struct mutex *lock = container_of(lock_count, struct mutex, count);
unsigned long flags;
int prev;
spin_lock_mutex(&lock->wait_lock, flags);
prev = atomic_xchg(&lock->count, -1);
if (likely(prev == 1)) {
mutex_set_owner(lock);
mutex_acquire(&lock->dep_map, 0, 1, _RET_IP_);
}
if (likely(list_empty(&lock->wait_list)))
atomic_set(&lock->count, 0);
spin_unlock_mutex(&lock->wait_lock, flags);
return prev == 1;
}
int __sched mutex_trylock(struct mutex *lock)
{
int ret;
ret = __mutex_fastpath_trylock(&lock->count, __mutex_trylock_slowpath);
if (ret)
mutex_set_owner(lock);
return ret;
}
int atomic_dec_and_mutex_lock(atomic_t *cnt, struct mutex *lock)
{
if (atomic_add_unless(cnt, -1, 1))
return 0;
mutex_lock(lock);
if (!atomic_dec_and_test(cnt)) {
mutex_unlock(lock);
return 0;
}
return 1;
}
