static inline u32 encode_tail(int cpu, int idx)
{
u32 tail;
#ifdef CONFIG_DEBUG_SPINLOCK
BUG_ON(idx > 3);
#endif
tail = (cpu + 1) << _Q_TAIL_CPU_OFFSET;
tail |= idx << _Q_TAIL_IDX_OFFSET;
return tail;
}
static inline struct mcs_spinlock *decode_tail(u32 tail)
{
int cpu = (tail >> _Q_TAIL_CPU_OFFSET) - 1;
int idx = (tail & _Q_TAIL_IDX_MASK) >> _Q_TAIL_IDX_OFFSET;
return per_cpu_ptr(&mcs_nodes[idx], cpu);
}
static __always_inline void clear_pending_set_locked(struct qspinlock *lock)
{
struct __qspinlock *l = (void *)lock;
WRITE_ONCE(l->locked_pending, _Q_LOCKED_VAL);
}
static __always_inline u32 xchg_tail(struct qspinlock *lock, u32 tail)
{
struct __qspinlock *l = (void *)lock;
return (u32)xchg_release(&l->tail,
tail >> _Q_TAIL_OFFSET) << _Q_TAIL_OFFSET;
}
static __always_inline void clear_pending_set_locked(struct qspinlock *lock)
{
atomic_add(-_Q_PENDING_VAL + _Q_LOCKED_VAL, &lock->val);
}
static __always_inline u32 xchg_tail(struct qspinlock *lock, u32 tail)
{
u32 old, new, val = atomic_read(&lock->val);
for (;;) {
new = (val & _Q_LOCKED_PENDING_MASK) | tail;
old = atomic_cmpxchg_release(&lock->val, val, new);
if (old == val)
break;
val = old;
}
return old;
}
static __always_inline void set_locked(struct qspinlock *lock)
{
struct __qspinlock *l = (void *)lock;
WRITE_ONCE(l->locked, _Q_LOCKED_VAL);
}
static __always_inline void __pv_init_node(struct mcs_spinlock *node) { }
static __always_inline void __pv_wait_node(struct mcs_spinlock *node,
struct mcs_spinlock *prev) { }
static __always_inline void __pv_kick_node(struct qspinlock *lock,
struct mcs_spinlock *node) { }
static __always_inline u32 __pv_wait_head_or_lock(struct qspinlock *lock,
struct mcs_spinlock *node)
{ return 0; }
void queued_spin_lock_slowpath(struct qspinlock *lock, u32 val)
{
struct mcs_spinlock *prev, *next, *node;
u32 new, old, tail;
int idx;
BUILD_BUG_ON(CONFIG_NR_CPUS >= (1U << _Q_TAIL_CPU_BITS));
if (pv_enabled())
goto queue;
if (virt_spin_lock(lock))
return;
if (val == _Q_PENDING_VAL) {
while ((val = atomic_read(&lock->val)) == _Q_PENDING_VAL)
cpu_relax();
}
for (;;) {
if (val & ~_Q_LOCKED_MASK)
goto queue;
new = _Q_LOCKED_VAL;
if (val == new)
new |= _Q_PENDING_VAL;
old = atomic_cmpxchg_acquire(&lock->val, val, new);
if (old == val)
break;
val = old;
}
if (new == _Q_LOCKED_VAL)
return;
while ((val = smp_load_acquire(&lock->val.counter)) & _Q_LOCKED_MASK)
cpu_relax();
clear_pending_set_locked(lock);
return;
queue:
node = this_cpu_ptr(&mcs_nodes[0]);
idx = node->count++;
tail = encode_tail(smp_processor_id(), idx);
node += idx;
node->locked = 0;
node->next = NULL;
pv_init_node(node);
if (queued_spin_trylock(lock))
goto release;
old = xchg_tail(lock, tail);
next = NULL;
if (old & _Q_TAIL_MASK) {
prev = decode_tail(old);
WRITE_ONCE(prev->next, node);
pv_wait_node(node, prev);
arch_mcs_spin_lock_contended(&node->locked);
next = READ_ONCE(node->next);
if (next)
prefetchw(next);
}
if ((val = pv_wait_head_or_lock(lock, node)))
goto locked;
smp_cond_acquire(!((val = atomic_read(&lock->val)) & _Q_LOCKED_PENDING_MASK));
locked:
for (;;) {
if ((val & _Q_TAIL_MASK) != tail) {
set_locked(lock);
break;
}
old = atomic_cmpxchg_relaxed(&lock->val, val, _Q_LOCKED_VAL);
if (old == val)
goto release;
val = old;
}
if (!next) {
while (!(next = READ_ONCE(node->next)))
cpu_relax();
}
arch_mcs_spin_unlock_contended(&next->locked);
pv_kick_node(lock, next);
release:
this_cpu_dec(mcs_nodes[0].count);
}
