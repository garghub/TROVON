wait_queue_head_t *bit_waitqueue(void *word, int bit)
{
const int shift = BITS_PER_LONG == 32 ? 5 : 6;
unsigned long val = (unsigned long)word << shift | bit;
return bit_wait_table + hash_long(val, WAIT_TABLE_BITS);
}
int wake_bit_function(struct wait_queue_entry *wq_entry, unsigned mode, int sync, void *arg)
{
struct wait_bit_key *key = arg;
struct wait_bit_queue_entry *wait_bit = container_of(wq_entry, struct wait_bit_queue_entry, wq_entry);
if (wait_bit->key.flags != key->flags ||
wait_bit->key.bit_nr != key->bit_nr ||
test_bit(key->bit_nr, key->flags))
return 0;
else
return autoremove_wake_function(wq_entry, mode, sync, key);
}
int __sched
__wait_on_bit(struct wait_queue_head *wq_head, struct wait_bit_queue_entry *wbq_entry,
wait_bit_action_f *action, unsigned mode)
{
int ret = 0;
do {
prepare_to_wait(wq_head, &wbq_entry->wq_entry, mode);
if (test_bit(wbq_entry->key.bit_nr, wbq_entry->key.flags))
ret = (*action)(&wbq_entry->key, mode);
} while (test_bit(wbq_entry->key.bit_nr, wbq_entry->key.flags) && !ret);
finish_wait(wq_head, &wbq_entry->wq_entry);
return ret;
}
int __sched out_of_line_wait_on_bit(void *word, int bit,
wait_bit_action_f *action, unsigned mode)
{
struct wait_queue_head *wq_head = bit_waitqueue(word, bit);
DEFINE_WAIT_BIT(wq_entry, word, bit);
return __wait_on_bit(wq_head, &wq_entry, action, mode);
}
int __sched out_of_line_wait_on_bit_timeout(
void *word, int bit, wait_bit_action_f *action,
unsigned mode, unsigned long timeout)
{
struct wait_queue_head *wq_head = bit_waitqueue(word, bit);
DEFINE_WAIT_BIT(wq_entry, word, bit);
wq_entry.key.timeout = jiffies + timeout;
return __wait_on_bit(wq_head, &wq_entry, action, mode);
}
int __sched
__wait_on_bit_lock(struct wait_queue_head *wq_head, struct wait_bit_queue_entry *wbq_entry,
wait_bit_action_f *action, unsigned mode)
{
int ret = 0;
for (;;) {
prepare_to_wait_exclusive(wq_head, &wbq_entry->wq_entry, mode);
if (test_bit(wbq_entry->key.bit_nr, wbq_entry->key.flags)) {
ret = action(&wbq_entry->key, mode);
if (ret)
finish_wait(wq_head, &wbq_entry->wq_entry);
}
if (!test_and_set_bit(wbq_entry->key.bit_nr, wbq_entry->key.flags)) {
if (!ret)
finish_wait(wq_head, &wbq_entry->wq_entry);
return 0;
} else if (ret) {
return ret;
}
}
}
int __sched out_of_line_wait_on_bit_lock(void *word, int bit,
wait_bit_action_f *action, unsigned mode)
{
struct wait_queue_head *wq_head = bit_waitqueue(word, bit);
DEFINE_WAIT_BIT(wq_entry, word, bit);
return __wait_on_bit_lock(wq_head, &wq_entry, action, mode);
}
void __wake_up_bit(struct wait_queue_head *wq_head, void *word, int bit)
{
struct wait_bit_key key = __WAIT_BIT_KEY_INITIALIZER(word, bit);
if (waitqueue_active(wq_head))
__wake_up(wq_head, TASK_NORMAL, 1, &key);
}
void wake_up_bit(void *word, int bit)
{
__wake_up_bit(bit_waitqueue(word, bit), word, bit);
}
static inline wait_queue_head_t *atomic_t_waitqueue(atomic_t *p)
{
if (BITS_PER_LONG == 64) {
unsigned long q = (unsigned long)p;
return bit_waitqueue((void *)(q & ~1), q & 1);
}
return bit_waitqueue(p, 0);
}
static int wake_atomic_t_function(struct wait_queue_entry *wq_entry, unsigned mode, int sync,
void *arg)
{
struct wait_bit_key *key = arg;
struct wait_bit_queue_entry *wait_bit = container_of(wq_entry, struct wait_bit_queue_entry, wq_entry);
atomic_t *val = key->flags;
if (wait_bit->key.flags != key->flags ||
wait_bit->key.bit_nr != key->bit_nr ||
atomic_read(val) != 0)
return 0;
return autoremove_wake_function(wq_entry, mode, sync, key);
}
static __sched
int __wait_on_atomic_t(struct wait_queue_head *wq_head, struct wait_bit_queue_entry *wbq_entry,
int (*action)(atomic_t *), unsigned mode)
{
atomic_t *val;
int ret = 0;
do {
prepare_to_wait(wq_head, &wbq_entry->wq_entry, mode);
val = wbq_entry->key.flags;
if (atomic_read(val) == 0)
break;
ret = (*action)(val);
} while (!ret && atomic_read(val) != 0);
finish_wait(wq_head, &wbq_entry->wq_entry);
return ret;
}
__sched int out_of_line_wait_on_atomic_t(atomic_t *p, int (*action)(atomic_t *),
unsigned mode)
{
struct wait_queue_head *wq_head = atomic_t_waitqueue(p);
DEFINE_WAIT_ATOMIC_T(wq_entry, p);
return __wait_on_atomic_t(wq_head, &wq_entry, action, mode);
}
void wake_up_atomic_t(atomic_t *p)
{
__wake_up_bit(atomic_t_waitqueue(p), p, WAIT_ATOMIC_T_BIT_NR);
}
__sched int bit_wait(struct wait_bit_key *word, int mode)
{
schedule();
if (signal_pending_state(mode, current))
return -EINTR;
return 0;
}
__sched int bit_wait_io(struct wait_bit_key *word, int mode)
{
io_schedule();
if (signal_pending_state(mode, current))
return -EINTR;
return 0;
}
__sched int bit_wait_timeout(struct wait_bit_key *word, int mode)
{
unsigned long now = READ_ONCE(jiffies);
if (time_after_eq(now, word->timeout))
return -EAGAIN;
schedule_timeout(word->timeout - now);
if (signal_pending_state(mode, current))
return -EINTR;
return 0;
}
__sched int bit_wait_io_timeout(struct wait_bit_key *word, int mode)
{
unsigned long now = READ_ONCE(jiffies);
if (time_after_eq(now, word->timeout))
return -EAGAIN;
io_schedule_timeout(word->timeout - now);
if (signal_pending_state(mode, current))
return -EINTR;
return 0;
}
void __init wait_bit_init(void)
{
int i;
for (i = 0; i < WAIT_TABLE_SIZE; i++)
init_waitqueue_head(bit_wait_table + i);
}
