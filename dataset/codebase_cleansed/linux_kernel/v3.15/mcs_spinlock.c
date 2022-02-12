static inline struct optimistic_spin_queue *
osq_wait_next(struct optimistic_spin_queue **lock,
struct optimistic_spin_queue *node,
struct optimistic_spin_queue *prev)
{
struct optimistic_spin_queue *next = NULL;
for (;;) {
if (*lock == node && cmpxchg(lock, node, prev) == node) {
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
bool osq_lock(struct optimistic_spin_queue **lock)
{
struct optimistic_spin_queue *node = this_cpu_ptr(&osq_node);
struct optimistic_spin_queue *prev, *next;
node->locked = 0;
node->next = NULL;
node->prev = prev = xchg(lock, node);
if (likely(prev == NULL))
return true;
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
void osq_unlock(struct optimistic_spin_queue **lock)
{
struct optimistic_spin_queue *node = this_cpu_ptr(&osq_node);
struct optimistic_spin_queue *next;
if (likely(cmpxchg(lock, node, NULL) == node))
return;
next = xchg(&node->next, NULL);
if (next) {
ACCESS_ONCE(next->locked) = 1;
return;
}
next = osq_wait_next(lock, node, NULL);
if (next)
ACCESS_ONCE(next->locked) = 1;
}
