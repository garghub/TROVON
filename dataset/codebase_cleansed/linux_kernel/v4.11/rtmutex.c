static void
rt_mutex_set_owner(struct rt_mutex *lock, struct task_struct *owner)
{
unsigned long val = (unsigned long)owner;
if (rt_mutex_has_waiters(lock))
val |= RT_MUTEX_HAS_WAITERS;
lock->owner = (struct task_struct *)val;
}
static inline void clear_rt_mutex_waiters(struct rt_mutex *lock)
{
lock->owner = (struct task_struct *)
((unsigned long)lock->owner & ~RT_MUTEX_HAS_WAITERS);
}
static void fixup_rt_mutex_waiters(struct rt_mutex *lock)
{
unsigned long owner, *p = (unsigned long *) &lock->owner;
if (rt_mutex_has_waiters(lock))
return;
owner = READ_ONCE(*p);
if (owner & RT_MUTEX_HAS_WAITERS)
WRITE_ONCE(*p, owner & ~RT_MUTEX_HAS_WAITERS);
}
static inline void mark_rt_mutex_waiters(struct rt_mutex *lock)
{
unsigned long owner, *p = (unsigned long *) &lock->owner;
do {
owner = *p;
} while (cmpxchg_relaxed(p, owner,
owner | RT_MUTEX_HAS_WAITERS) != owner);
}
static inline bool unlock_rt_mutex_safe(struct rt_mutex *lock,
unsigned long flags)
__releases(lock->wait_lock)
{
struct task_struct *owner = rt_mutex_owner(lock);
clear_rt_mutex_waiters(lock);
raw_spin_unlock_irqrestore(&lock->wait_lock, flags);
return rt_mutex_cmpxchg_release(lock, owner, NULL);
}
static inline void mark_rt_mutex_waiters(struct rt_mutex *lock)
{
lock->owner = (struct task_struct *)
((unsigned long)lock->owner | RT_MUTEX_HAS_WAITERS);
}
static inline bool unlock_rt_mutex_safe(struct rt_mutex *lock,
unsigned long flags)
__releases(lock->wait_lock)
{
lock->owner = NULL;
raw_spin_unlock_irqrestore(&lock->wait_lock, flags);
return true;
}
static inline int
rt_mutex_waiter_less(struct rt_mutex_waiter *left,
struct rt_mutex_waiter *right)
{
if (left->prio < right->prio)
return 1;
if (dl_prio(left->prio))
return dl_time_before(left->task->dl.deadline,
right->task->dl.deadline);
return 0;
}
static void
rt_mutex_enqueue(struct rt_mutex *lock, struct rt_mutex_waiter *waiter)
{
struct rb_node **link = &lock->waiters.rb_node;
struct rb_node *parent = NULL;
struct rt_mutex_waiter *entry;
int leftmost = 1;
while (*link) {
parent = *link;
entry = rb_entry(parent, struct rt_mutex_waiter, tree_entry);
if (rt_mutex_waiter_less(waiter, entry)) {
link = &parent->rb_left;
} else {
link = &parent->rb_right;
leftmost = 0;
}
}
if (leftmost)
lock->waiters_leftmost = &waiter->tree_entry;
rb_link_node(&waiter->tree_entry, parent, link);
rb_insert_color(&waiter->tree_entry, &lock->waiters);
}
static void
rt_mutex_dequeue(struct rt_mutex *lock, struct rt_mutex_waiter *waiter)
{
if (RB_EMPTY_NODE(&waiter->tree_entry))
return;
if (lock->waiters_leftmost == &waiter->tree_entry)
lock->waiters_leftmost = rb_next(&waiter->tree_entry);
rb_erase(&waiter->tree_entry, &lock->waiters);
RB_CLEAR_NODE(&waiter->tree_entry);
}
static void
rt_mutex_enqueue_pi(struct task_struct *task, struct rt_mutex_waiter *waiter)
{
struct rb_node **link = &task->pi_waiters.rb_node;
struct rb_node *parent = NULL;
struct rt_mutex_waiter *entry;
int leftmost = 1;
while (*link) {
parent = *link;
entry = rb_entry(parent, struct rt_mutex_waiter, pi_tree_entry);
if (rt_mutex_waiter_less(waiter, entry)) {
link = &parent->rb_left;
} else {
link = &parent->rb_right;
leftmost = 0;
}
}
if (leftmost)
task->pi_waiters_leftmost = &waiter->pi_tree_entry;
rb_link_node(&waiter->pi_tree_entry, parent, link);
rb_insert_color(&waiter->pi_tree_entry, &task->pi_waiters);
}
static void
rt_mutex_dequeue_pi(struct task_struct *task, struct rt_mutex_waiter *waiter)
{
if (RB_EMPTY_NODE(&waiter->pi_tree_entry))
return;
if (task->pi_waiters_leftmost == &waiter->pi_tree_entry)
task->pi_waiters_leftmost = rb_next(&waiter->pi_tree_entry);
rb_erase(&waiter->pi_tree_entry, &task->pi_waiters);
RB_CLEAR_NODE(&waiter->pi_tree_entry);
}
int rt_mutex_getprio(struct task_struct *task)
{
if (likely(!task_has_pi_waiters(task)))
return task->normal_prio;
return min(task_top_pi_waiter(task)->prio,
task->normal_prio);
}
struct task_struct *rt_mutex_get_top_task(struct task_struct *task)
{
if (likely(!task_has_pi_waiters(task)))
return NULL;
return task_top_pi_waiter(task)->task;
}
int rt_mutex_get_effective_prio(struct task_struct *task, int newprio)
{
if (!task_has_pi_waiters(task))
return newprio;
if (task_top_pi_waiter(task)->task->prio <= newprio)
return task_top_pi_waiter(task)->task->prio;
return newprio;
}
static void __rt_mutex_adjust_prio(struct task_struct *task)
{
int prio = rt_mutex_getprio(task);
if (task->prio != prio || dl_prio(prio))
rt_mutex_setprio(task, prio);
}
void rt_mutex_adjust_prio(struct task_struct *task)
{
unsigned long flags;
raw_spin_lock_irqsave(&task->pi_lock, flags);
__rt_mutex_adjust_prio(task);
raw_spin_unlock_irqrestore(&task->pi_lock, flags);
}
static bool rt_mutex_cond_detect_deadlock(struct rt_mutex_waiter *waiter,
enum rtmutex_chainwalk chwalk)
{
return debug_rt_mutex_detect_deadlock(waiter, chwalk);
}
static inline struct rt_mutex *task_blocked_on_lock(struct task_struct *p)
{
return p->pi_blocked_on ? p->pi_blocked_on->lock : NULL;
}
static int rt_mutex_adjust_prio_chain(struct task_struct *task,
enum rtmutex_chainwalk chwalk,
struct rt_mutex *orig_lock,
struct rt_mutex *next_lock,
struct rt_mutex_waiter *orig_waiter,
struct task_struct *top_task)
{
struct rt_mutex_waiter *waiter, *top_waiter = orig_waiter;
struct rt_mutex_waiter *prerequeue_top_waiter;
int ret = 0, depth = 0;
struct rt_mutex *lock;
bool detect_deadlock;
bool requeue = true;
detect_deadlock = rt_mutex_cond_detect_deadlock(orig_waiter, chwalk);
again:
if (++depth > max_lock_depth) {
static int prev_max;
if (prev_max != max_lock_depth) {
prev_max = max_lock_depth;
printk(KERN_WARNING "Maximum lock depth %d reached "
"task: %s (%d)\n", max_lock_depth,
top_task->comm, task_pid_nr(top_task));
}
put_task_struct(task);
return -EDEADLK;
}
retry:
raw_spin_lock_irq(&task->pi_lock);
waiter = task->pi_blocked_on;
if (!waiter)
goto out_unlock_pi;
if (orig_waiter && !rt_mutex_owner(orig_lock))
goto out_unlock_pi;
if (next_lock != waiter->lock)
goto out_unlock_pi;
if (top_waiter) {
if (!task_has_pi_waiters(task))
goto out_unlock_pi;
if (top_waiter != task_top_pi_waiter(task)) {
if (!detect_deadlock)
goto out_unlock_pi;
else
requeue = false;
}
}
if (waiter->prio == task->prio) {
if (!detect_deadlock)
goto out_unlock_pi;
else
requeue = false;
}
lock = waiter->lock;
if (!raw_spin_trylock(&lock->wait_lock)) {
raw_spin_unlock_irq(&task->pi_lock);
cpu_relax();
goto retry;
}
if (lock == orig_lock || rt_mutex_owner(lock) == top_task) {
debug_rt_mutex_deadlock(chwalk, orig_waiter, lock);
raw_spin_unlock(&lock->wait_lock);
ret = -EDEADLK;
goto out_unlock_pi;
}
if (!requeue) {
raw_spin_unlock(&task->pi_lock);
put_task_struct(task);
if (!rt_mutex_owner(lock)) {
raw_spin_unlock_irq(&lock->wait_lock);
return 0;
}
task = rt_mutex_owner(lock);
get_task_struct(task);
raw_spin_lock(&task->pi_lock);
next_lock = task_blocked_on_lock(task);
top_waiter = rt_mutex_top_waiter(lock);
raw_spin_unlock(&task->pi_lock);
raw_spin_unlock_irq(&lock->wait_lock);
if (!next_lock)
goto out_put_task;
goto again;
}
prerequeue_top_waiter = rt_mutex_top_waiter(lock);
rt_mutex_dequeue(lock, waiter);
waiter->prio = task->prio;
rt_mutex_enqueue(lock, waiter);
raw_spin_unlock(&task->pi_lock);
put_task_struct(task);
if (!rt_mutex_owner(lock)) {
if (prerequeue_top_waiter != rt_mutex_top_waiter(lock))
wake_up_process(rt_mutex_top_waiter(lock)->task);
raw_spin_unlock_irq(&lock->wait_lock);
return 0;
}
task = rt_mutex_owner(lock);
get_task_struct(task);
raw_spin_lock(&task->pi_lock);
if (waiter == rt_mutex_top_waiter(lock)) {
rt_mutex_dequeue_pi(task, prerequeue_top_waiter);
rt_mutex_enqueue_pi(task, waiter);
__rt_mutex_adjust_prio(task);
} else if (prerequeue_top_waiter == waiter) {
rt_mutex_dequeue_pi(task, waiter);
waiter = rt_mutex_top_waiter(lock);
rt_mutex_enqueue_pi(task, waiter);
__rt_mutex_adjust_prio(task);
} else {
}
next_lock = task_blocked_on_lock(task);
top_waiter = rt_mutex_top_waiter(lock);
raw_spin_unlock(&task->pi_lock);
raw_spin_unlock_irq(&lock->wait_lock);
if (!next_lock)
goto out_put_task;
if (!detect_deadlock && waiter != top_waiter)
goto out_put_task;
goto again;
out_unlock_pi:
raw_spin_unlock_irq(&task->pi_lock);
out_put_task:
put_task_struct(task);
return ret;
}
static int try_to_take_rt_mutex(struct rt_mutex *lock, struct task_struct *task,
struct rt_mutex_waiter *waiter)
{
mark_rt_mutex_waiters(lock);
if (rt_mutex_owner(lock))
return 0;
if (waiter) {
if (waiter != rt_mutex_top_waiter(lock))
return 0;
rt_mutex_dequeue(lock, waiter);
} else {
if (rt_mutex_has_waiters(lock)) {
if (task->prio >= rt_mutex_top_waiter(lock)->prio)
return 0;
} else {
goto takeit;
}
}
raw_spin_lock(&task->pi_lock);
task->pi_blocked_on = NULL;
if (rt_mutex_has_waiters(lock))
rt_mutex_enqueue_pi(task, rt_mutex_top_waiter(lock));
raw_spin_unlock(&task->pi_lock);
takeit:
debug_rt_mutex_lock(lock);
rt_mutex_set_owner(lock, task);
rt_mutex_deadlock_account_lock(lock, task);
return 1;
}
static int task_blocks_on_rt_mutex(struct rt_mutex *lock,
struct rt_mutex_waiter *waiter,
struct task_struct *task,
enum rtmutex_chainwalk chwalk)
{
struct task_struct *owner = rt_mutex_owner(lock);
struct rt_mutex_waiter *top_waiter = waiter;
struct rt_mutex *next_lock;
int chain_walk = 0, res;
if (owner == task)
return -EDEADLK;
raw_spin_lock(&task->pi_lock);
__rt_mutex_adjust_prio(task);
waiter->task = task;
waiter->lock = lock;
waiter->prio = task->prio;
if (rt_mutex_has_waiters(lock))
top_waiter = rt_mutex_top_waiter(lock);
rt_mutex_enqueue(lock, waiter);
task->pi_blocked_on = waiter;
raw_spin_unlock(&task->pi_lock);
if (!owner)
return 0;
raw_spin_lock(&owner->pi_lock);
if (waiter == rt_mutex_top_waiter(lock)) {
rt_mutex_dequeue_pi(owner, top_waiter);
rt_mutex_enqueue_pi(owner, waiter);
__rt_mutex_adjust_prio(owner);
if (owner->pi_blocked_on)
chain_walk = 1;
} else if (rt_mutex_cond_detect_deadlock(waiter, chwalk)) {
chain_walk = 1;
}
next_lock = task_blocked_on_lock(owner);
raw_spin_unlock(&owner->pi_lock);
if (!chain_walk || !next_lock)
return 0;
get_task_struct(owner);
raw_spin_unlock_irq(&lock->wait_lock);
res = rt_mutex_adjust_prio_chain(owner, chwalk, lock,
next_lock, waiter, task);
raw_spin_lock_irq(&lock->wait_lock);
return res;
}
static void mark_wakeup_next_waiter(struct wake_q_head *wake_q,
struct rt_mutex *lock)
{
struct rt_mutex_waiter *waiter;
raw_spin_lock(&current->pi_lock);
waiter = rt_mutex_top_waiter(lock);
rt_mutex_dequeue_pi(current, waiter);
lock->owner = (void *) RT_MUTEX_HAS_WAITERS;
raw_spin_unlock(&current->pi_lock);
wake_q_add(wake_q, waiter->task);
}
static void remove_waiter(struct rt_mutex *lock,
struct rt_mutex_waiter *waiter)
{
bool is_top_waiter = (waiter == rt_mutex_top_waiter(lock));
struct task_struct *owner = rt_mutex_owner(lock);
struct rt_mutex *next_lock;
raw_spin_lock(&current->pi_lock);
rt_mutex_dequeue(lock, waiter);
current->pi_blocked_on = NULL;
raw_spin_unlock(&current->pi_lock);
if (!owner || !is_top_waiter)
return;
raw_spin_lock(&owner->pi_lock);
rt_mutex_dequeue_pi(owner, waiter);
if (rt_mutex_has_waiters(lock))
rt_mutex_enqueue_pi(owner, rt_mutex_top_waiter(lock));
__rt_mutex_adjust_prio(owner);
next_lock = task_blocked_on_lock(owner);
raw_spin_unlock(&owner->pi_lock);
if (!next_lock)
return;
get_task_struct(owner);
raw_spin_unlock_irq(&lock->wait_lock);
rt_mutex_adjust_prio_chain(owner, RT_MUTEX_MIN_CHAINWALK, lock,
next_lock, NULL, current);
raw_spin_lock_irq(&lock->wait_lock);
}
void rt_mutex_adjust_pi(struct task_struct *task)
{
struct rt_mutex_waiter *waiter;
struct rt_mutex *next_lock;
unsigned long flags;
raw_spin_lock_irqsave(&task->pi_lock, flags);
waiter = task->pi_blocked_on;
if (!waiter || (waiter->prio == task->prio &&
!dl_prio(task->prio))) {
raw_spin_unlock_irqrestore(&task->pi_lock, flags);
return;
}
next_lock = waiter->lock;
raw_spin_unlock_irqrestore(&task->pi_lock, flags);
get_task_struct(task);
rt_mutex_adjust_prio_chain(task, RT_MUTEX_MIN_CHAINWALK, NULL,
next_lock, NULL, task);
}
static int __sched
__rt_mutex_slowlock(struct rt_mutex *lock, int state,
struct hrtimer_sleeper *timeout,
struct rt_mutex_waiter *waiter)
{
int ret = 0;
for (;;) {
if (try_to_take_rt_mutex(lock, current, waiter))
break;
if (likely(state == TASK_INTERRUPTIBLE)) {
if (signal_pending(current))
ret = -EINTR;
if (timeout && !timeout->task)
ret = -ETIMEDOUT;
if (ret)
break;
}
raw_spin_unlock_irq(&lock->wait_lock);
debug_rt_mutex_print_deadlock(waiter);
schedule();
raw_spin_lock_irq(&lock->wait_lock);
set_current_state(state);
}
__set_current_state(TASK_RUNNING);
return ret;
}
static void rt_mutex_handle_deadlock(int res, int detect_deadlock,
struct rt_mutex_waiter *w)
{
if (res != -EDEADLOCK || detect_deadlock)
return;
rt_mutex_print_deadlock(w);
while (1) {
set_current_state(TASK_INTERRUPTIBLE);
schedule();
}
}
static int __sched
rt_mutex_slowlock(struct rt_mutex *lock, int state,
struct hrtimer_sleeper *timeout,
enum rtmutex_chainwalk chwalk)
{
struct rt_mutex_waiter waiter;
unsigned long flags;
int ret = 0;
debug_rt_mutex_init_waiter(&waiter);
RB_CLEAR_NODE(&waiter.pi_tree_entry);
RB_CLEAR_NODE(&waiter.tree_entry);
raw_spin_lock_irqsave(&lock->wait_lock, flags);
if (try_to_take_rt_mutex(lock, current, NULL)) {
raw_spin_unlock_irqrestore(&lock->wait_lock, flags);
return 0;
}
set_current_state(state);
if (unlikely(timeout))
hrtimer_start_expires(&timeout->timer, HRTIMER_MODE_ABS);
ret = task_blocks_on_rt_mutex(lock, &waiter, current, chwalk);
if (likely(!ret))
ret = __rt_mutex_slowlock(lock, state, timeout, &waiter);
if (unlikely(ret)) {
__set_current_state(TASK_RUNNING);
if (rt_mutex_has_waiters(lock))
remove_waiter(lock, &waiter);
rt_mutex_handle_deadlock(ret, chwalk, &waiter);
}
fixup_rt_mutex_waiters(lock);
raw_spin_unlock_irqrestore(&lock->wait_lock, flags);
if (unlikely(timeout))
hrtimer_cancel(&timeout->timer);
debug_rt_mutex_free_waiter(&waiter);
return ret;
}
static inline int rt_mutex_slowtrylock(struct rt_mutex *lock)
{
unsigned long flags;
int ret;
if (rt_mutex_owner(lock))
return 0;
raw_spin_lock_irqsave(&lock->wait_lock, flags);
ret = try_to_take_rt_mutex(lock, current, NULL);
fixup_rt_mutex_waiters(lock);
raw_spin_unlock_irqrestore(&lock->wait_lock, flags);
return ret;
}
static bool __sched rt_mutex_slowunlock(struct rt_mutex *lock,
struct wake_q_head *wake_q)
{
unsigned long flags;
raw_spin_lock_irqsave(&lock->wait_lock, flags);
debug_rt_mutex_unlock(lock);
rt_mutex_deadlock_account_unlock(current);
while (!rt_mutex_has_waiters(lock)) {
if (unlock_rt_mutex_safe(lock, flags) == true)
return false;
raw_spin_lock_irqsave(&lock->wait_lock, flags);
}
mark_wakeup_next_waiter(wake_q, lock);
raw_spin_unlock_irqrestore(&lock->wait_lock, flags);
return true;
}
static inline int
rt_mutex_fastlock(struct rt_mutex *lock, int state,
int (*slowfn)(struct rt_mutex *lock, int state,
struct hrtimer_sleeper *timeout,
enum rtmutex_chainwalk chwalk))
{
if (likely(rt_mutex_cmpxchg_acquire(lock, NULL, current))) {
rt_mutex_deadlock_account_lock(lock, current);
return 0;
} else
return slowfn(lock, state, NULL, RT_MUTEX_MIN_CHAINWALK);
}
static inline int
rt_mutex_timed_fastlock(struct rt_mutex *lock, int state,
struct hrtimer_sleeper *timeout,
enum rtmutex_chainwalk chwalk,
int (*slowfn)(struct rt_mutex *lock, int state,
struct hrtimer_sleeper *timeout,
enum rtmutex_chainwalk chwalk))
{
if (chwalk == RT_MUTEX_MIN_CHAINWALK &&
likely(rt_mutex_cmpxchg_acquire(lock, NULL, current))) {
rt_mutex_deadlock_account_lock(lock, current);
return 0;
} else
return slowfn(lock, state, timeout, chwalk);
}
static inline int
rt_mutex_fasttrylock(struct rt_mutex *lock,
int (*slowfn)(struct rt_mutex *lock))
{
if (likely(rt_mutex_cmpxchg_acquire(lock, NULL, current))) {
rt_mutex_deadlock_account_lock(lock, current);
return 1;
}
return slowfn(lock);
}
static inline void
rt_mutex_fastunlock(struct rt_mutex *lock,
bool (*slowfn)(struct rt_mutex *lock,
struct wake_q_head *wqh))
{
DEFINE_WAKE_Q(wake_q);
if (likely(rt_mutex_cmpxchg_release(lock, current, NULL))) {
rt_mutex_deadlock_account_unlock(current);
} else {
bool deboost = slowfn(lock, &wake_q);
wake_up_q(&wake_q);
if (deboost)
rt_mutex_adjust_prio(current);
}
}
void __sched rt_mutex_lock(struct rt_mutex *lock)
{
might_sleep();
rt_mutex_fastlock(lock, TASK_UNINTERRUPTIBLE, rt_mutex_slowlock);
}
int __sched rt_mutex_lock_interruptible(struct rt_mutex *lock)
{
might_sleep();
return rt_mutex_fastlock(lock, TASK_INTERRUPTIBLE, rt_mutex_slowlock);
}
int rt_mutex_timed_futex_lock(struct rt_mutex *lock,
struct hrtimer_sleeper *timeout)
{
might_sleep();
return rt_mutex_timed_fastlock(lock, TASK_INTERRUPTIBLE, timeout,
RT_MUTEX_FULL_CHAINWALK,
rt_mutex_slowlock);
}
int
rt_mutex_timed_lock(struct rt_mutex *lock, struct hrtimer_sleeper *timeout)
{
might_sleep();
return rt_mutex_timed_fastlock(lock, TASK_INTERRUPTIBLE, timeout,
RT_MUTEX_MIN_CHAINWALK,
rt_mutex_slowlock);
}
int __sched rt_mutex_trylock(struct rt_mutex *lock)
{
if (WARN_ON_ONCE(in_irq() || in_nmi() || in_serving_softirq()))
return 0;
return rt_mutex_fasttrylock(lock, rt_mutex_slowtrylock);
}
void __sched rt_mutex_unlock(struct rt_mutex *lock)
{
rt_mutex_fastunlock(lock, rt_mutex_slowunlock);
}
bool __sched rt_mutex_futex_unlock(struct rt_mutex *lock,
struct wake_q_head *wqh)
{
if (likely(rt_mutex_cmpxchg_release(lock, current, NULL))) {
rt_mutex_deadlock_account_unlock(current);
return false;
}
return rt_mutex_slowunlock(lock, wqh);
}
void rt_mutex_destroy(struct rt_mutex *lock)
{
WARN_ON(rt_mutex_is_locked(lock));
#ifdef CONFIG_DEBUG_RT_MUTEXES
lock->magic = NULL;
#endif
}
void __rt_mutex_init(struct rt_mutex *lock, const char *name)
{
lock->owner = NULL;
raw_spin_lock_init(&lock->wait_lock);
lock->waiters = RB_ROOT;
lock->waiters_leftmost = NULL;
debug_rt_mutex_init(lock, name);
}
void rt_mutex_init_proxy_locked(struct rt_mutex *lock,
struct task_struct *proxy_owner)
{
__rt_mutex_init(lock, NULL);
debug_rt_mutex_proxy_lock(lock, proxy_owner);
rt_mutex_set_owner(lock, proxy_owner);
rt_mutex_deadlock_account_lock(lock, proxy_owner);
}
void rt_mutex_proxy_unlock(struct rt_mutex *lock,
struct task_struct *proxy_owner)
{
debug_rt_mutex_proxy_unlock(lock);
rt_mutex_set_owner(lock, NULL);
rt_mutex_deadlock_account_unlock(proxy_owner);
}
int rt_mutex_start_proxy_lock(struct rt_mutex *lock,
struct rt_mutex_waiter *waiter,
struct task_struct *task)
{
int ret;
raw_spin_lock_irq(&lock->wait_lock);
if (try_to_take_rt_mutex(lock, task, NULL)) {
raw_spin_unlock_irq(&lock->wait_lock);
return 1;
}
ret = task_blocks_on_rt_mutex(lock, waiter, task,
RT_MUTEX_FULL_CHAINWALK);
if (ret && !rt_mutex_owner(lock)) {
ret = 0;
}
if (unlikely(ret))
remove_waiter(lock, waiter);
raw_spin_unlock_irq(&lock->wait_lock);
debug_rt_mutex_print_deadlock(waiter);
return ret;
}
struct task_struct *rt_mutex_next_owner(struct rt_mutex *lock)
{
if (!rt_mutex_has_waiters(lock))
return NULL;
return rt_mutex_top_waiter(lock)->task;
}
int rt_mutex_finish_proxy_lock(struct rt_mutex *lock,
struct hrtimer_sleeper *to,
struct rt_mutex_waiter *waiter)
{
int ret;
raw_spin_lock_irq(&lock->wait_lock);
set_current_state(TASK_INTERRUPTIBLE);
ret = __rt_mutex_slowlock(lock, TASK_INTERRUPTIBLE, to, waiter);
if (unlikely(ret))
remove_waiter(lock, waiter);
fixup_rt_mutex_waiters(lock);
raw_spin_unlock_irq(&lock->wait_lock);
return ret;
}
