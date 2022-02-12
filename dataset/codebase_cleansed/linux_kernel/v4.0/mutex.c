void
__mutex_init(struct mutex *lock, const char *name, struct lock_class_key *key)
{
atomic_set(&lock->count, 1);
spin_lock_init(&lock->wait_lock);
INIT_LIST_HEAD(&lock->wait_list);
mutex_clear_owner(lock);
#ifdef CONFIG_MUTEX_SPIN_ON_OWNER
osq_lock_init(&lock->osq);
#endif
debug_mutex_init(lock, name, key);
}
void __sched mutex_lock(struct mutex *lock)
{
might_sleep();
__mutex_fastpath_lock(&lock->count, __mutex_lock_slowpath);
mutex_set_owner(lock);
}
static __always_inline void ww_mutex_lock_acquired(struct ww_mutex *ww,
struct ww_acquire_ctx *ww_ctx)
{
#ifdef CONFIG_DEBUG_MUTEXES
DEBUG_LOCKS_WARN_ON(ww->ctx);
DEBUG_LOCKS_WARN_ON(ww_ctx->done_acquire);
if (ww_ctx->contending_lock) {
DEBUG_LOCKS_WARN_ON(ww_ctx->contending_lock != ww);
DEBUG_LOCKS_WARN_ON(ww_ctx->acquired > 0);
ww_ctx->contending_lock = NULL;
}
DEBUG_LOCKS_WARN_ON(ww_ctx->ww_class != ww->ww_class);
#endif
ww_ctx->acquired++;
}
static __always_inline void
ww_mutex_set_context_fastpath(struct ww_mutex *lock,
struct ww_acquire_ctx *ctx)
{
unsigned long flags;
struct mutex_waiter *cur;
ww_mutex_lock_acquired(lock, ctx);
lock->ctx = ctx;
smp_mb();
if (likely(atomic_read(&lock->base.count) == 0))
return;
spin_lock_mutex(&lock->base.wait_lock, flags);
list_for_each_entry(cur, &lock->base.wait_list, list) {
debug_mutex_wake_waiter(&lock->base, cur);
wake_up_process(cur->task);
}
spin_unlock_mutex(&lock->base.wait_lock, flags);
}
static __always_inline void
ww_mutex_set_context_slowpath(struct ww_mutex *lock,
struct ww_acquire_ctx *ctx)
{
struct mutex_waiter *cur;
ww_mutex_lock_acquired(lock, ctx);
lock->ctx = ctx;
list_for_each_entry(cur, &lock->base.wait_list, list) {
debug_mutex_wake_waiter(&lock->base, cur);
wake_up_process(cur->task);
}
}
static inline bool owner_running(struct mutex *lock, struct task_struct *owner)
{
if (lock->owner != owner)
return false;
barrier();
return owner->on_cpu;
}
static noinline
int mutex_spin_on_owner(struct mutex *lock, struct task_struct *owner)
{
rcu_read_lock();
while (owner_running(lock, owner)) {
if (need_resched())
break;
cpu_relax_lowlatency();
}
rcu_read_unlock();
return lock->owner == NULL;
}
static inline int mutex_can_spin_on_owner(struct mutex *lock)
{
struct task_struct *owner;
int retval = 1;
if (need_resched())
return 0;
rcu_read_lock();
owner = ACCESS_ONCE(lock->owner);
if (owner)
retval = owner->on_cpu;
rcu_read_unlock();
return retval;
}
static inline bool mutex_try_to_acquire(struct mutex *lock)
{
return !mutex_is_locked(lock) &&
(atomic_cmpxchg(&lock->count, 1, 0) == 1);
}
static bool mutex_optimistic_spin(struct mutex *lock,
struct ww_acquire_ctx *ww_ctx, const bool use_ww_ctx)
{
struct task_struct *task = current;
if (!mutex_can_spin_on_owner(lock))
goto done;
if (!osq_lock(&lock->osq))
goto done;
while (true) {
struct task_struct *owner;
if (use_ww_ctx && ww_ctx->acquired > 0) {
struct ww_mutex *ww;
ww = container_of(lock, struct ww_mutex, base);
if (ACCESS_ONCE(ww->ctx))
break;
}
owner = ACCESS_ONCE(lock->owner);
if (owner && !mutex_spin_on_owner(lock, owner))
break;
if (mutex_try_to_acquire(lock)) {
lock_acquired(&lock->dep_map, ip);
if (use_ww_ctx) {
struct ww_mutex *ww;
ww = container_of(lock, struct ww_mutex, base);
ww_mutex_set_context_fastpath(ww, ww_ctx);
}
mutex_set_owner(lock);
osq_unlock(&lock->osq);
return true;
}
if (!owner && (need_resched() || rt_task(task)))
break;
cpu_relax_lowlatency();
}
osq_unlock(&lock->osq);
done:
if (need_resched()) {
__set_current_state(TASK_RUNNING);
schedule_preempt_disabled();
}
return false;
}
static bool mutex_optimistic_spin(struct mutex *lock,
struct ww_acquire_ctx *ww_ctx, const bool use_ww_ctx)
{
return false;
}
void __sched mutex_unlock(struct mutex *lock)
{
#ifndef CONFIG_DEBUG_MUTEXES
mutex_clear_owner(lock);
#endif
__mutex_fastpath_unlock(&lock->count, __mutex_unlock_slowpath);
}
void __sched ww_mutex_unlock(struct ww_mutex *lock)
{
if (lock->ctx) {
#ifdef CONFIG_DEBUG_MUTEXES
DEBUG_LOCKS_WARN_ON(!lock->ctx->acquired);
#endif
if (lock->ctx->acquired > 0)
lock->ctx->acquired--;
lock->ctx = NULL;
}
#ifndef CONFIG_DEBUG_MUTEXES
mutex_clear_owner(&lock->base);
#endif
__mutex_fastpath_unlock(&lock->base.count, __mutex_unlock_slowpath);
}
static inline int __sched
__ww_mutex_lock_check_stamp(struct mutex *lock, struct ww_acquire_ctx *ctx)
{
struct ww_mutex *ww = container_of(lock, struct ww_mutex, base);
struct ww_acquire_ctx *hold_ctx = ACCESS_ONCE(ww->ctx);
if (!hold_ctx)
return 0;
if (unlikely(ctx == hold_ctx))
return -EALREADY;
if (ctx->stamp - hold_ctx->stamp <= LONG_MAX &&
(ctx->stamp != hold_ctx->stamp || ctx > hold_ctx)) {
#ifdef CONFIG_DEBUG_MUTEXES
DEBUG_LOCKS_WARN_ON(ctx->contending_lock);
ctx->contending_lock = ww;
#endif
return -EDEADLK;
}
return 0;
}
static __always_inline int __sched
__mutex_lock_common(struct mutex *lock, long state, unsigned int subclass,
struct lockdep_map *nest_lock, unsigned long ip,
struct ww_acquire_ctx *ww_ctx, const bool use_ww_ctx)
{
struct task_struct *task = current;
struct mutex_waiter waiter;
unsigned long flags;
int ret;
preempt_disable();
mutex_acquire_nest(&lock->dep_map, subclass, 0, nest_lock, ip);
if (mutex_optimistic_spin(lock, ww_ctx, use_ww_ctx)) {
preempt_enable();
return 0;
}
spin_lock_mutex(&lock->wait_lock, flags);
if (!mutex_is_locked(lock) && (atomic_xchg(&lock->count, 0) == 1))
goto skip_wait;
debug_mutex_lock_common(lock, &waiter);
debug_mutex_add_waiter(lock, &waiter, task_thread_info(task));
list_add_tail(&waiter.list, &lock->wait_list);
waiter.task = task;
lock_contended(&lock->dep_map, ip);
for (;;) {
if (atomic_read(&lock->count) >= 0 &&
(atomic_xchg(&lock->count, -1) == 1))
break;
if (unlikely(signal_pending_state(state, task))) {
ret = -EINTR;
goto err;
}
if (use_ww_ctx && ww_ctx->acquired > 0) {
ret = __ww_mutex_lock_check_stamp(lock, ww_ctx);
if (ret)
goto err;
}
__set_task_state(task, state);
spin_unlock_mutex(&lock->wait_lock, flags);
schedule_preempt_disabled();
spin_lock_mutex(&lock->wait_lock, flags);
}
__set_task_state(task, TASK_RUNNING);
mutex_remove_waiter(lock, &waiter, current_thread_info());
if (likely(list_empty(&lock->wait_list)))
atomic_set(&lock->count, 0);
debug_mutex_free_waiter(&waiter);
skip_wait:
lock_acquired(&lock->dep_map, ip);
mutex_set_owner(lock);
if (use_ww_ctx) {
struct ww_mutex *ww = container_of(lock, struct ww_mutex, base);
ww_mutex_set_context_slowpath(ww, ww_ctx);
}
spin_unlock_mutex(&lock->wait_lock, flags);
preempt_enable();
return 0;
err:
mutex_remove_waiter(lock, &waiter, task_thread_info(task));
spin_unlock_mutex(&lock->wait_lock, flags);
debug_mutex_free_waiter(&waiter);
mutex_release(&lock->dep_map, 1, ip);
preempt_enable();
return ret;
}
void __sched
mutex_lock_nested(struct mutex *lock, unsigned int subclass)
{
might_sleep();
__mutex_lock_common(lock, TASK_UNINTERRUPTIBLE,
subclass, NULL, _RET_IP_, NULL, 0);
}
void __sched
_mutex_lock_nest_lock(struct mutex *lock, struct lockdep_map *nest)
{
might_sleep();
__mutex_lock_common(lock, TASK_UNINTERRUPTIBLE,
0, nest, _RET_IP_, NULL, 0);
}
int __sched
mutex_lock_killable_nested(struct mutex *lock, unsigned int subclass)
{
might_sleep();
return __mutex_lock_common(lock, TASK_KILLABLE,
subclass, NULL, _RET_IP_, NULL, 0);
}
int __sched
mutex_lock_interruptible_nested(struct mutex *lock, unsigned int subclass)
{
might_sleep();
return __mutex_lock_common(lock, TASK_INTERRUPTIBLE,
subclass, NULL, _RET_IP_, NULL, 0);
}
static inline int
ww_mutex_deadlock_injection(struct ww_mutex *lock, struct ww_acquire_ctx *ctx)
{
#ifdef CONFIG_DEBUG_WW_MUTEX_SLOWPATH
unsigned tmp;
if (ctx->deadlock_inject_countdown-- == 0) {
tmp = ctx->deadlock_inject_interval;
if (tmp > UINT_MAX/4)
tmp = UINT_MAX;
else
tmp = tmp*2 + tmp + tmp/2;
ctx->deadlock_inject_interval = tmp;
ctx->deadlock_inject_countdown = tmp;
ctx->contending_lock = lock;
ww_mutex_unlock(lock);
return -EDEADLK;
}
#endif
return 0;
}
int __sched
__ww_mutex_lock(struct ww_mutex *lock, struct ww_acquire_ctx *ctx)
{
int ret;
might_sleep();
ret = __mutex_lock_common(&lock->base, TASK_UNINTERRUPTIBLE,
0, &ctx->dep_map, _RET_IP_, ctx, 1);
if (!ret && ctx->acquired > 1)
return ww_mutex_deadlock_injection(lock, ctx);
return ret;
}
int __sched
__ww_mutex_lock_interruptible(struct ww_mutex *lock, struct ww_acquire_ctx *ctx)
{
int ret;
might_sleep();
ret = __mutex_lock_common(&lock->base, TASK_INTERRUPTIBLE,
0, &ctx->dep_map, _RET_IP_, ctx, 1);
if (!ret && ctx->acquired > 1)
return ww_mutex_deadlock_injection(lock, ctx);
return ret;
}
static inline void
__mutex_unlock_common_slowpath(struct mutex *lock, int nested)
{
unsigned long flags;
if (__mutex_slowpath_needs_to_unlock())
atomic_set(&lock->count, 1);
spin_lock_mutex(&lock->wait_lock, flags);
mutex_release(&lock->dep_map, nested, _RET_IP_);
debug_mutex_unlock(lock);
if (!list_empty(&lock->wait_list)) {
struct mutex_waiter *waiter =
list_entry(lock->wait_list.next,
struct mutex_waiter, list);
debug_mutex_wake_waiter(lock, waiter);
wake_up_process(waiter->task);
}
spin_unlock_mutex(&lock->wait_lock, flags);
}
__visible void
__mutex_unlock_slowpath(atomic_t *lock_count)
{
struct mutex *lock = container_of(lock_count, struct mutex, count);
__mutex_unlock_common_slowpath(lock, 1);
}
int __sched mutex_lock_interruptible(struct mutex *lock)
{
int ret;
might_sleep();
ret = __mutex_fastpath_lock_retval(&lock->count);
if (likely(!ret)) {
mutex_set_owner(lock);
return 0;
} else
return __mutex_lock_interruptible_slowpath(lock);
}
int __sched mutex_lock_killable(struct mutex *lock)
{
int ret;
might_sleep();
ret = __mutex_fastpath_lock_retval(&lock->count);
if (likely(!ret)) {
mutex_set_owner(lock);
return 0;
} else
return __mutex_lock_killable_slowpath(lock);
}
__visible void __sched
__mutex_lock_slowpath(atomic_t *lock_count)
{
struct mutex *lock = container_of(lock_count, struct mutex, count);
__mutex_lock_common(lock, TASK_UNINTERRUPTIBLE, 0,
NULL, _RET_IP_, NULL, 0);
}
static noinline int __sched
__mutex_lock_killable_slowpath(struct mutex *lock)
{
return __mutex_lock_common(lock, TASK_KILLABLE, 0,
NULL, _RET_IP_, NULL, 0);
}
static noinline int __sched
__mutex_lock_interruptible_slowpath(struct mutex *lock)
{
return __mutex_lock_common(lock, TASK_INTERRUPTIBLE, 0,
NULL, _RET_IP_, NULL, 0);
}
static noinline int __sched
__ww_mutex_lock_slowpath(struct ww_mutex *lock, struct ww_acquire_ctx *ctx)
{
return __mutex_lock_common(&lock->base, TASK_UNINTERRUPTIBLE, 0,
NULL, _RET_IP_, ctx, 1);
}
static noinline int __sched
__ww_mutex_lock_interruptible_slowpath(struct ww_mutex *lock,
struct ww_acquire_ctx *ctx)
{
return __mutex_lock_common(&lock->base, TASK_INTERRUPTIBLE, 0,
NULL, _RET_IP_, ctx, 1);
}
static inline int __mutex_trylock_slowpath(atomic_t *lock_count)
{
struct mutex *lock = container_of(lock_count, struct mutex, count);
unsigned long flags;
int prev;
if (mutex_is_locked(lock))
return 0;
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
int __sched
__ww_mutex_lock(struct ww_mutex *lock, struct ww_acquire_ctx *ctx)
{
int ret;
might_sleep();
ret = __mutex_fastpath_lock_retval(&lock->base.count);
if (likely(!ret)) {
ww_mutex_set_context_fastpath(lock, ctx);
mutex_set_owner(&lock->base);
} else
ret = __ww_mutex_lock_slowpath(lock, ctx);
return ret;
}
int __sched
__ww_mutex_lock_interruptible(struct ww_mutex *lock, struct ww_acquire_ctx *ctx)
{
int ret;
might_sleep();
ret = __mutex_fastpath_lock_retval(&lock->base.count);
if (likely(!ret)) {
ww_mutex_set_context_fastpath(lock, ctx);
mutex_set_owner(&lock->base);
} else
ret = __ww_mutex_lock_interruptible_slowpath(lock, ctx);
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
