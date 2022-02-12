void __init_waitqueue_head(wait_queue_head_t *q, const char *name, struct lock_class_key *key)
{
spin_lock_init(&q->lock);
lockdep_set_class_and_name(&q->lock, key, name);
INIT_LIST_HEAD(&q->task_list);
}
void add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
{
unsigned long flags;
wait->flags &= ~WQ_FLAG_EXCLUSIVE;
spin_lock_irqsave(&q->lock, flags);
__add_wait_queue(q, wait);
spin_unlock_irqrestore(&q->lock, flags);
}
void add_wait_queue_exclusive(wait_queue_head_t *q, wait_queue_t *wait)
{
unsigned long flags;
wait->flags |= WQ_FLAG_EXCLUSIVE;
spin_lock_irqsave(&q->lock, flags);
__add_wait_queue_tail(q, wait);
spin_unlock_irqrestore(&q->lock, flags);
}
void remove_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
{
unsigned long flags;
spin_lock_irqsave(&q->lock, flags);
__remove_wait_queue(q, wait);
spin_unlock_irqrestore(&q->lock, flags);
}
static void __wake_up_common(wait_queue_head_t *q, unsigned int mode,
int nr_exclusive, int wake_flags, void *key)
{
wait_queue_t *curr, *next;
list_for_each_entry_safe(curr, next, &q->task_list, task_list) {
unsigned flags = curr->flags;
if (curr->func(curr, mode, wake_flags, key) &&
(flags & WQ_FLAG_EXCLUSIVE) && !--nr_exclusive)
break;
}
}
void __wake_up(wait_queue_head_t *q, unsigned int mode,
int nr_exclusive, void *key)
{
unsigned long flags;
spin_lock_irqsave(&q->lock, flags);
__wake_up_common(q, mode, nr_exclusive, 0, key);
spin_unlock_irqrestore(&q->lock, flags);
}
void __wake_up_locked(wait_queue_head_t *q, unsigned int mode, int nr)
{
__wake_up_common(q, mode, nr, 0, NULL);
}
void __wake_up_locked_key(wait_queue_head_t *q, unsigned int mode, void *key)
{
__wake_up_common(q, mode, 1, 0, key);
}
void __wake_up_sync_key(wait_queue_head_t *q, unsigned int mode,
int nr_exclusive, void *key)
{
unsigned long flags;
int wake_flags = 1;
if (unlikely(!q))
return;
if (unlikely(nr_exclusive != 1))
wake_flags = 0;
spin_lock_irqsave(&q->lock, flags);
__wake_up_common(q, mode, nr_exclusive, wake_flags, key);
spin_unlock_irqrestore(&q->lock, flags);
}
void __wake_up_sync(wait_queue_head_t *q, unsigned int mode, int nr_exclusive)
{
__wake_up_sync_key(q, mode, nr_exclusive, NULL);
}
void
prepare_to_wait(wait_queue_head_t *q, wait_queue_t *wait, int state)
{
unsigned long flags;
wait->flags &= ~WQ_FLAG_EXCLUSIVE;
spin_lock_irqsave(&q->lock, flags);
if (list_empty(&wait->task_list))
__add_wait_queue(q, wait);
set_current_state(state);
spin_unlock_irqrestore(&q->lock, flags);
}
void
prepare_to_wait_exclusive(wait_queue_head_t *q, wait_queue_t *wait, int state)
{
unsigned long flags;
wait->flags |= WQ_FLAG_EXCLUSIVE;
spin_lock_irqsave(&q->lock, flags);
if (list_empty(&wait->task_list))
__add_wait_queue_tail(q, wait);
set_current_state(state);
spin_unlock_irqrestore(&q->lock, flags);
}
long prepare_to_wait_event(wait_queue_head_t *q, wait_queue_t *wait, int state)
{
unsigned long flags;
if (signal_pending_state(state, current))
return -ERESTARTSYS;
wait->private = current;
wait->func = autoremove_wake_function;
spin_lock_irqsave(&q->lock, flags);
if (list_empty(&wait->task_list)) {
if (wait->flags & WQ_FLAG_EXCLUSIVE)
__add_wait_queue_tail(q, wait);
else
__add_wait_queue(q, wait);
}
set_current_state(state);
spin_unlock_irqrestore(&q->lock, flags);
return 0;
}
void finish_wait(wait_queue_head_t *q, wait_queue_t *wait)
{
unsigned long flags;
__set_current_state(TASK_RUNNING);
if (!list_empty_careful(&wait->task_list)) {
spin_lock_irqsave(&q->lock, flags);
list_del_init(&wait->task_list);
spin_unlock_irqrestore(&q->lock, flags);
}
}
void abort_exclusive_wait(wait_queue_head_t *q, wait_queue_t *wait,
unsigned int mode, void *key)
{
unsigned long flags;
__set_current_state(TASK_RUNNING);
spin_lock_irqsave(&q->lock, flags);
if (!list_empty(&wait->task_list))
list_del_init(&wait->task_list);
else if (waitqueue_active(q))
__wake_up_locked_key(q, mode, key);
spin_unlock_irqrestore(&q->lock, flags);
}
int autoremove_wake_function(wait_queue_t *wait, unsigned mode, int sync, void *key)
{
int ret = default_wake_function(wait, mode, sync, key);
if (ret)
list_del_init(&wait->task_list);
return ret;
}
int wake_bit_function(wait_queue_t *wait, unsigned mode, int sync, void *arg)
{
struct wait_bit_key *key = arg;
struct wait_bit_queue *wait_bit
= container_of(wait, struct wait_bit_queue, wait);
if (wait_bit->key.flags != key->flags ||
wait_bit->key.bit_nr != key->bit_nr ||
test_bit(key->bit_nr, key->flags))
return 0;
else
return autoremove_wake_function(wait, mode, sync, key);
}
int __sched
__wait_on_bit(wait_queue_head_t *wq, struct wait_bit_queue *q,
wait_bit_action_f *action, unsigned mode)
{
int ret = 0;
do {
prepare_to_wait(wq, &q->wait, mode);
if (test_bit(q->key.bit_nr, q->key.flags))
ret = (*action)(&q->key);
} while (test_bit(q->key.bit_nr, q->key.flags) && !ret);
finish_wait(wq, &q->wait);
return ret;
}
int __sched out_of_line_wait_on_bit(void *word, int bit,
wait_bit_action_f *action, unsigned mode)
{
wait_queue_head_t *wq = bit_waitqueue(word, bit);
DEFINE_WAIT_BIT(wait, word, bit);
return __wait_on_bit(wq, &wait, action, mode);
}
int __sched out_of_line_wait_on_bit_timeout(
void *word, int bit, wait_bit_action_f *action,
unsigned mode, unsigned long timeout)
{
wait_queue_head_t *wq = bit_waitqueue(word, bit);
DEFINE_WAIT_BIT(wait, word, bit);
wait.key.timeout = jiffies + timeout;
return __wait_on_bit(wq, &wait, action, mode);
}
int __sched
__wait_on_bit_lock(wait_queue_head_t *wq, struct wait_bit_queue *q,
wait_bit_action_f *action, unsigned mode)
{
do {
int ret;
prepare_to_wait_exclusive(wq, &q->wait, mode);
if (!test_bit(q->key.bit_nr, q->key.flags))
continue;
ret = action(&q->key);
if (!ret)
continue;
abort_exclusive_wait(wq, &q->wait, mode, &q->key);
return ret;
} while (test_and_set_bit(q->key.bit_nr, q->key.flags));
finish_wait(wq, &q->wait);
return 0;
}
int __sched out_of_line_wait_on_bit_lock(void *word, int bit,
wait_bit_action_f *action, unsigned mode)
{
wait_queue_head_t *wq = bit_waitqueue(word, bit);
DEFINE_WAIT_BIT(wait, word, bit);
return __wait_on_bit_lock(wq, &wait, action, mode);
}
void __wake_up_bit(wait_queue_head_t *wq, void *word, int bit)
{
struct wait_bit_key key = __WAIT_BIT_KEY_INITIALIZER(word, bit);
if (waitqueue_active(wq))
__wake_up(wq, TASK_NORMAL, 1, &key);
}
void wake_up_bit(void *word, int bit)
{
__wake_up_bit(bit_waitqueue(word, bit), word, bit);
}
wait_queue_head_t *bit_waitqueue(void *word, int bit)
{
const int shift = BITS_PER_LONG == 32 ? 5 : 6;
const struct zone *zone = page_zone(virt_to_page(word));
unsigned long val = (unsigned long)word << shift | bit;
return &zone->wait_table[hash_long(val, zone->wait_table_bits)];
}
static inline wait_queue_head_t *atomic_t_waitqueue(atomic_t *p)
{
if (BITS_PER_LONG == 64) {
unsigned long q = (unsigned long)p;
return bit_waitqueue((void *)(q & ~1), q & 1);
}
return bit_waitqueue(p, 0);
}
static int wake_atomic_t_function(wait_queue_t *wait, unsigned mode, int sync,
void *arg)
{
struct wait_bit_key *key = arg;
struct wait_bit_queue *wait_bit
= container_of(wait, struct wait_bit_queue, wait);
atomic_t *val = key->flags;
if (wait_bit->key.flags != key->flags ||
wait_bit->key.bit_nr != key->bit_nr ||
atomic_read(val) != 0)
return 0;
return autoremove_wake_function(wait, mode, sync, key);
}
static __sched
int __wait_on_atomic_t(wait_queue_head_t *wq, struct wait_bit_queue *q,
int (*action)(atomic_t *), unsigned mode)
{
atomic_t *val;
int ret = 0;
do {
prepare_to_wait(wq, &q->wait, mode);
val = q->key.flags;
if (atomic_read(val) == 0)
break;
ret = (*action)(val);
} while (!ret && atomic_read(val) != 0);
finish_wait(wq, &q->wait);
return ret;
}
__sched int out_of_line_wait_on_atomic_t(atomic_t *p, int (*action)(atomic_t *),
unsigned mode)
{
wait_queue_head_t *wq = atomic_t_waitqueue(p);
DEFINE_WAIT_ATOMIC_T(wait, p);
return __wait_on_atomic_t(wq, &wait, action, mode);
}
void wake_up_atomic_t(atomic_t *p)
{
__wake_up_bit(atomic_t_waitqueue(p), p, WAIT_ATOMIC_T_BIT_NR);
}
__sched int bit_wait(struct wait_bit_key *word)
{
if (signal_pending_state(current->state, current))
return 1;
schedule();
return 0;
}
__sched int bit_wait_io(struct wait_bit_key *word)
{
if (signal_pending_state(current->state, current))
return 1;
io_schedule();
return 0;
}
__sched int bit_wait_timeout(struct wait_bit_key *word)
{
unsigned long now = ACCESS_ONCE(jiffies);
if (signal_pending_state(current->state, current))
return 1;
if (time_after_eq(now, word->timeout))
return -EAGAIN;
schedule_timeout(word->timeout - now);
return 0;
}
__sched int bit_wait_io_timeout(struct wait_bit_key *word)
{
unsigned long now = ACCESS_ONCE(jiffies);
if (signal_pending_state(current->state, current))
return 1;
if (time_after_eq(now, word->timeout))
return -EAGAIN;
io_schedule_timeout(word->timeout - now);
return 0;
}
