void
__mutex_init(struct mutex *lock, const char *name, struct lock_class_key *key)
{
atomic_long_set(&lock->owner, 0);
spin_lock_init(&lock->wait_lock);
INIT_LIST_HEAD(&lock->wait_list);
#ifdef CONFIG_MUTEX_SPIN_ON_OWNER
osq_lock_init(&lock->osq);
#endif
debug_mutex_init(lock, name, key);
}
static inline struct task_struct *__owner_task(unsigned long owner)
{
return (struct task_struct *)(owner & ~MUTEX_FLAGS);
}
static inline unsigned long __owner_flags(unsigned long owner)
{
return owner & MUTEX_FLAGS;
}
static inline bool __mutex_trylock(struct mutex *lock, const bool handoff)
{
unsigned long owner, curr = (unsigned long)current;
owner = atomic_long_read(&lock->owner);
for (;;) {
unsigned long old, flags = __owner_flags(owner);
if (__owner_task(owner)) {
if (handoff && unlikely(__owner_task(owner) == current)) {
smp_mb();
return true;
}
return false;
}
if (handoff)
flags &= ~MUTEX_FLAG_HANDOFF;
old = atomic_long_cmpxchg_acquire(&lock->owner, owner, curr | flags);
if (old == owner)
return true;
owner = old;
}
}
static __always_inline bool __mutex_trylock_fast(struct mutex *lock)
{
unsigned long curr = (unsigned long)current;
if (!atomic_long_cmpxchg_acquire(&lock->owner, 0UL, curr))
return true;
return false;
}
static __always_inline bool __mutex_unlock_fast(struct mutex *lock)
{
unsigned long curr = (unsigned long)current;
if (atomic_long_cmpxchg_release(&lock->owner, curr, 0UL) == curr)
return true;
return false;
}
static inline void __mutex_set_flag(struct mutex *lock, unsigned long flag)
{
atomic_long_or(flag, &lock->owner);
}
static inline void __mutex_clear_flag(struct mutex *lock, unsigned long flag)
{
atomic_long_andnot(flag, &lock->owner);
}
static inline bool __mutex_waiter_is_first(struct mutex *lock, struct mutex_waiter *waiter)
{
return list_first_entry(&lock->wait_list, struct mutex_waiter, list) == waiter;
}
static void __mutex_handoff(struct mutex *lock, struct task_struct *task)
{
unsigned long owner = atomic_long_read(&lock->owner);
for (;;) {
unsigned long old, new;
#ifdef CONFIG_DEBUG_MUTEXES
DEBUG_LOCKS_WARN_ON(__owner_task(owner) != current);
#endif
new = (owner & MUTEX_FLAG_WAITERS);
new |= (unsigned long)task;
old = atomic_long_cmpxchg_release(&lock->owner, owner, new);
if (old == owner)
break;
owner = old;
}
}
void __sched mutex_lock(struct mutex *lock)
{
might_sleep();
if (!__mutex_trylock_fast(lock))
__mutex_lock_slowpath(lock);
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
if (likely(!(atomic_long_read(&lock->base.owner) & MUTEX_FLAG_WAITERS)))
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
static noinline
bool mutex_spin_on_owner(struct mutex *lock, struct task_struct *owner)
{
bool ret = true;
rcu_read_lock();
while (__mutex_owner(lock) == owner) {
barrier();
if (!owner->on_cpu || need_resched() ||
vcpu_is_preempted(task_cpu(owner))) {
ret = false;
break;
}
cpu_relax();
}
rcu_read_unlock();
return ret;
}
static inline int mutex_can_spin_on_owner(struct mutex *lock)
{
struct task_struct *owner;
int retval = 1;
if (need_resched())
return 0;
rcu_read_lock();
owner = __mutex_owner(lock);
if (owner)
retval = owner->on_cpu && !vcpu_is_preempted(task_cpu(owner));
rcu_read_unlock();
return retval;
}
static bool mutex_optimistic_spin(struct mutex *lock,
struct ww_acquire_ctx *ww_ctx,
const bool use_ww_ctx, const bool waiter)
{
struct task_struct *task = current;
if (!waiter) {
if (!mutex_can_spin_on_owner(lock))
goto fail;
if (!osq_lock(&lock->osq))
goto fail;
}
for (;;) {
struct task_struct *owner;
if (use_ww_ctx && ww_ctx->acquired > 0) {
struct ww_mutex *ww;
ww = container_of(lock, struct ww_mutex, base);
if (READ_ONCE(ww->ctx))
goto fail_unlock;
}
owner = __mutex_owner(lock);
if (owner) {
if (waiter && owner == task) {
smp_mb();
break;
}
if (!mutex_spin_on_owner(lock, owner))
goto fail_unlock;
}
if (__mutex_trylock(lock, waiter))
break;
cpu_relax();
}
if (!waiter)
osq_unlock(&lock->osq);
return true;
fail_unlock:
if (!waiter)
osq_unlock(&lock->osq);
fail:
if (need_resched()) {
__set_current_state(TASK_RUNNING);
schedule_preempt_disabled();
}
return false;
}
static bool mutex_optimistic_spin(struct mutex *lock,
struct ww_acquire_ctx *ww_ctx,
const bool use_ww_ctx, const bool waiter)
{
return false;
}
void __sched mutex_unlock(struct mutex *lock)
{
#ifndef CONFIG_DEBUG_LOCK_ALLOC
if (__mutex_unlock_fast(lock))
return;
#endif
__mutex_unlock_slowpath(lock, _RET_IP_);
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
mutex_unlock(&lock->base);
}
static inline int __sched
__ww_mutex_lock_check_stamp(struct mutex *lock, struct ww_acquire_ctx *ctx)
{
struct ww_mutex *ww = container_of(lock, struct ww_mutex, base);
struct ww_acquire_ctx *hold_ctx = READ_ONCE(ww->ctx);
if (!hold_ctx)
return 0;
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
bool first = false;
struct ww_mutex *ww;
int ret;
if (use_ww_ctx) {
ww = container_of(lock, struct ww_mutex, base);
if (unlikely(ww_ctx == READ_ONCE(ww->ctx)))
return -EALREADY;
}
preempt_disable();
mutex_acquire_nest(&lock->dep_map, subclass, 0, nest_lock, ip);
if (__mutex_trylock(lock, false) ||
mutex_optimistic_spin(lock, ww_ctx, use_ww_ctx, false)) {
lock_acquired(&lock->dep_map, ip);
if (use_ww_ctx)
ww_mutex_set_context_fastpath(ww, ww_ctx);
preempt_enable();
return 0;
}
spin_lock_mutex(&lock->wait_lock, flags);
if (__mutex_trylock(lock, false))
goto skip_wait;
debug_mutex_lock_common(lock, &waiter);
debug_mutex_add_waiter(lock, &waiter, task);
list_add_tail(&waiter.list, &lock->wait_list);
waiter.task = task;
if (__mutex_waiter_is_first(lock, &waiter))
__mutex_set_flag(lock, MUTEX_FLAG_WAITERS);
lock_contended(&lock->dep_map, ip);
set_task_state(task, state);
for (;;) {
if (__mutex_trylock(lock, first))
goto acquired;
if (unlikely(signal_pending_state(state, task))) {
ret = -EINTR;
goto err;
}
if (use_ww_ctx && ww_ctx->acquired > 0) {
ret = __ww_mutex_lock_check_stamp(lock, ww_ctx);
if (ret)
goto err;
}
spin_unlock_mutex(&lock->wait_lock, flags);
schedule_preempt_disabled();
if (!first && __mutex_waiter_is_first(lock, &waiter)) {
first = true;
__mutex_set_flag(lock, MUTEX_FLAG_HANDOFF);
}
set_task_state(task, state);
if ((first && mutex_optimistic_spin(lock, ww_ctx, use_ww_ctx, true)) ||
__mutex_trylock(lock, first))
break;
spin_lock_mutex(&lock->wait_lock, flags);
}
spin_lock_mutex(&lock->wait_lock, flags);
acquired:
__set_task_state(task, TASK_RUNNING);
mutex_remove_waiter(lock, &waiter, task);
if (likely(list_empty(&lock->wait_list)))
__mutex_clear_flag(lock, MUTEX_FLAGS);
debug_mutex_free_waiter(&waiter);
skip_wait:
lock_acquired(&lock->dep_map, ip);
if (use_ww_ctx)
ww_mutex_set_context_slowpath(ww, ww_ctx);
spin_unlock_mutex(&lock->wait_lock, flags);
preempt_enable();
return 0;
err:
__set_task_state(task, TASK_RUNNING);
mutex_remove_waiter(lock, &waiter, task);
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
static noinline void __sched __mutex_unlock_slowpath(struct mutex *lock, unsigned long ip)
{
struct task_struct *next = NULL;
unsigned long owner, flags;
DEFINE_WAKE_Q(wake_q);
mutex_release(&lock->dep_map, 1, ip);
owner = atomic_long_read(&lock->owner);
for (;;) {
unsigned long old;
#ifdef CONFIG_DEBUG_MUTEXES
DEBUG_LOCKS_WARN_ON(__owner_task(owner) != current);
#endif
if (owner & MUTEX_FLAG_HANDOFF)
break;
old = atomic_long_cmpxchg_release(&lock->owner, owner,
__owner_flags(owner));
if (old == owner) {
if (owner & MUTEX_FLAG_WAITERS)
break;
return;
}
owner = old;
}
spin_lock_mutex(&lock->wait_lock, flags);
debug_mutex_unlock(lock);
if (!list_empty(&lock->wait_list)) {
struct mutex_waiter *waiter =
list_first_entry(&lock->wait_list,
struct mutex_waiter, list);
next = waiter->task;
debug_mutex_wake_waiter(lock, waiter);
wake_q_add(&wake_q, next);
}
if (owner & MUTEX_FLAG_HANDOFF)
__mutex_handoff(lock, next);
spin_unlock_mutex(&lock->wait_lock, flags);
wake_up_q(&wake_q);
}
int __sched mutex_lock_interruptible(struct mutex *lock)
{
might_sleep();
if (__mutex_trylock_fast(lock))
return 0;
return __mutex_lock_interruptible_slowpath(lock);
}
int __sched mutex_lock_killable(struct mutex *lock)
{
might_sleep();
if (__mutex_trylock_fast(lock))
return 0;
return __mutex_lock_killable_slowpath(lock);
}
static noinline void __sched
__mutex_lock_slowpath(struct mutex *lock)
{
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
int __sched mutex_trylock(struct mutex *lock)
{
bool locked = __mutex_trylock(lock, false);
if (locked)
mutex_acquire(&lock->dep_map, 0, 1, _RET_IP_);
return locked;
}
int __sched
__ww_mutex_lock(struct ww_mutex *lock, struct ww_acquire_ctx *ctx)
{
might_sleep();
if (__mutex_trylock_fast(&lock->base)) {
ww_mutex_set_context_fastpath(lock, ctx);
return 0;
}
return __ww_mutex_lock_slowpath(lock, ctx);
}
int __sched
__ww_mutex_lock_interruptible(struct ww_mutex *lock, struct ww_acquire_ctx *ctx)
{
might_sleep();
if (__mutex_trylock_fast(&lock->base)) {
ww_mutex_set_context_fastpath(lock, ctx);
return 0;
}
return __ww_mutex_lock_interruptible_slowpath(lock, ctx);
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
