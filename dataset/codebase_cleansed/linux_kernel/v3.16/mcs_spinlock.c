static inline int encode_cpu(int cpu_nr)
{
return cpu_nr + 1;
}
static inline struct optimistic_spin_node *decode_cpu(int encoded_cpu_val)
{
int cpu_nr = encoded_cpu_val - 1;
return per_cpu_ptr(&osq_node, cpu_nr);
}
static inline struct optimistic_spin_node *
osq_wait_next(struct optimistic_spin_queue *lock,
struct optimistic_spin_node *node,
struct optimistic_spin_node *prev)
{
struct optimistic_spin_node *next = NULL;
int curr = encode_cpu(smp_processor_id());
int old;
old = prev ? prev->cpu : OSQ_UNLOCKED_VAL;
for (;;) {
if (atomic_read(&lock->tail) == curr &&
atomic_cmpxchg(&lock->tail, curr, old) == curr) {
break;
}
if (node->next) {
next = xchg(&node->next, NULL);
if (next)
break;
}
arch_mutex_cpu_relax();
}
return next;
}
bool osq_lock(struct optimistic_spin_queue *lock)
{
struct optimistic_spin_node *node = this_cpu_ptr(&osq_node);
struct optimistic_spin_node *prev, *next;
int curr = encode_cpu(smp_processor_id());
int old;
node->locked = 0;
node->next = NULL;
node->cpu = curr;
old = atomic_xchg(&lock->tail, curr);
if (old == OSQ_UNLOCKED_VAL)
return true;
prev = decode_cpu(old);
node->prev = prev;
ACCESS_ONCE(prev->next) = node;
while (!smp_load_acquire(&node->locked)) {
if (need_resched())
goto unqueue;
arch_mutex_cpu_relax();
}
return true;
unqueue:
for (;;) {
if (prev->next == node &&
cmpxchg(&prev->next, node, NULL) == node)
break;
if (smp_load_acquire(&node->locked))
return true;
arch_mutex_cpu_relax();
prev = ACCESS_ONCE(node->prev);
}
next = osq_wait_next(lock, node, prev);
if (!next)
return false;
ACCESS_ONCE(next->prev) = prev;
ACCESS_ONCE(prev->next) = next;
return false;
}
void osq_unlock(struct optimistic_spin_queue *lock)
{
struct optimistic_spin_node *node, *next;
int curr = encode_cpu(smp_processor_id());
if (likely(atomic_cmpxchg(&lock->tail, curr, OSQ_UNLOCKED_VAL) == curr))
return;
node = this_cpu_ptr(&osq_node);
next = xchg(&node->next, NULL);
if (next) {
ACCESS_ONCE(next->locked) = 1;
return;
}
next = osq_wait_next(lock, node, NULL);
if (next)
ACCESS_ONCE(next->locked) = 1;
}
