void __init_waitqueue_head(struct wait_queue_head *wq_head, const char *name, struct lock_class_key *key)
{
spin_lock_init(&wq_head->lock);
lockdep_set_class_and_name(&wq_head->lock, key, name);
INIT_LIST_HEAD(&wq_head->head);
}
void add_wait_queue(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry)
{
unsigned long flags;
wq_entry->flags &= ~WQ_FLAG_EXCLUSIVE;
spin_lock_irqsave(&wq_head->lock, flags);
__add_wait_queue_entry_tail(wq_head, wq_entry);
spin_unlock_irqrestore(&wq_head->lock, flags);
}
void add_wait_queue_exclusive(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry)
{
unsigned long flags;
wq_entry->flags |= WQ_FLAG_EXCLUSIVE;
spin_lock_irqsave(&wq_head->lock, flags);
__add_wait_queue_entry_tail(wq_head, wq_entry);
spin_unlock_irqrestore(&wq_head->lock, flags);
}
void remove_wait_queue(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry)
{
unsigned long flags;
spin_lock_irqsave(&wq_head->lock, flags);
__remove_wait_queue(wq_head, wq_entry);
spin_unlock_irqrestore(&wq_head->lock, flags);
}
static void __wake_up_common(struct wait_queue_head *wq_head, unsigned int mode,
int nr_exclusive, int wake_flags, void *key)
{
wait_queue_entry_t *curr, *next;
list_for_each_entry_safe(curr, next, &wq_head->head, entry) {
unsigned flags = curr->flags;
int ret = curr->func(curr, mode, wake_flags, key);
if (ret < 0)
break;
if (ret && (flags & WQ_FLAG_EXCLUSIVE) && !--nr_exclusive)
break;
}
}
void __wake_up(struct wait_queue_head *wq_head, unsigned int mode,
int nr_exclusive, void *key)
{
unsigned long flags;
spin_lock_irqsave(&wq_head->lock, flags);
__wake_up_common(wq_head, mode, nr_exclusive, 0, key);
spin_unlock_irqrestore(&wq_head->lock, flags);
}
void __wake_up_locked(struct wait_queue_head *wq_head, unsigned int mode, int nr)
{
__wake_up_common(wq_head, mode, nr, 0, NULL);
}
void __wake_up_locked_key(struct wait_queue_head *wq_head, unsigned int mode, void *key)
{
__wake_up_common(wq_head, mode, 1, 0, key);
}
void __wake_up_sync_key(struct wait_queue_head *wq_head, unsigned int mode,
int nr_exclusive, void *key)
{
unsigned long flags;
int wake_flags = 1;
if (unlikely(!wq_head))
return;
if (unlikely(nr_exclusive != 1))
wake_flags = 0;
spin_lock_irqsave(&wq_head->lock, flags);
__wake_up_common(wq_head, mode, nr_exclusive, wake_flags, key);
spin_unlock_irqrestore(&wq_head->lock, flags);
}
void __wake_up_sync(struct wait_queue_head *wq_head, unsigned int mode, int nr_exclusive)
{
__wake_up_sync_key(wq_head, mode, nr_exclusive, NULL);
}
void
prepare_to_wait(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry, int state)
{
unsigned long flags;
wq_entry->flags &= ~WQ_FLAG_EXCLUSIVE;
spin_lock_irqsave(&wq_head->lock, flags);
if (list_empty(&wq_entry->entry))
__add_wait_queue(wq_head, wq_entry);
set_current_state(state);
spin_unlock_irqrestore(&wq_head->lock, flags);
}
void
prepare_to_wait_exclusive(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry, int state)
{
unsigned long flags;
wq_entry->flags |= WQ_FLAG_EXCLUSIVE;
spin_lock_irqsave(&wq_head->lock, flags);
if (list_empty(&wq_entry->entry))
__add_wait_queue_entry_tail(wq_head, wq_entry);
set_current_state(state);
spin_unlock_irqrestore(&wq_head->lock, flags);
}
void init_wait_entry(struct wait_queue_entry *wq_entry, int flags)
{
wq_entry->flags = flags;
wq_entry->private = current;
wq_entry->func = autoremove_wake_function;
INIT_LIST_HEAD(&wq_entry->entry);
}
long prepare_to_wait_event(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry, int state)
{
unsigned long flags;
long ret = 0;
spin_lock_irqsave(&wq_head->lock, flags);
if (unlikely(signal_pending_state(state, current))) {
list_del_init(&wq_entry->entry);
ret = -ERESTARTSYS;
} else {
if (list_empty(&wq_entry->entry)) {
if (wq_entry->flags & WQ_FLAG_EXCLUSIVE)
__add_wait_queue_entry_tail(wq_head, wq_entry);
else
__add_wait_queue(wq_head, wq_entry);
}
set_current_state(state);
}
spin_unlock_irqrestore(&wq_head->lock, flags);
return ret;
}
int do_wait_intr(wait_queue_head_t *wq, wait_queue_entry_t *wait)
{
if (likely(list_empty(&wait->entry)))
__add_wait_queue_entry_tail(wq, wait);
set_current_state(TASK_INTERRUPTIBLE);
if (signal_pending(current))
return -ERESTARTSYS;
spin_unlock(&wq->lock);
schedule();
spin_lock(&wq->lock);
return 0;
}
int do_wait_intr_irq(wait_queue_head_t *wq, wait_queue_entry_t *wait)
{
if (likely(list_empty(&wait->entry)))
__add_wait_queue_entry_tail(wq, wait);
set_current_state(TASK_INTERRUPTIBLE);
if (signal_pending(current))
return -ERESTARTSYS;
spin_unlock_irq(&wq->lock);
schedule();
spin_lock_irq(&wq->lock);
return 0;
}
void finish_wait(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry)
{
unsigned long flags;
__set_current_state(TASK_RUNNING);
if (!list_empty_careful(&wq_entry->entry)) {
spin_lock_irqsave(&wq_head->lock, flags);
list_del_init(&wq_entry->entry);
spin_unlock_irqrestore(&wq_head->lock, flags);
}
}
int autoremove_wake_function(struct wait_queue_entry *wq_entry, unsigned mode, int sync, void *key)
{
int ret = default_wake_function(wq_entry, mode, sync, key);
if (ret)
list_del_init(&wq_entry->entry);
return ret;
}
static inline bool is_kthread_should_stop(void)
{
return (current->flags & PF_KTHREAD) && kthread_should_stop();
}
long wait_woken(struct wait_queue_entry *wq_entry, unsigned mode, long timeout)
{
set_current_state(mode);
if (!(wq_entry->flags & WQ_FLAG_WOKEN) && !is_kthread_should_stop())
timeout = schedule_timeout(timeout);
__set_current_state(TASK_RUNNING);
smp_store_mb(wq_entry->flags, wq_entry->flags & ~WQ_FLAG_WOKEN);
return timeout;
}
int woken_wake_function(struct wait_queue_entry *wq_entry, unsigned mode, int sync, void *key)
{
smp_wmb();
wq_entry->flags |= WQ_FLAG_WOKEN;
return default_wake_function(wq_entry, mode, sync, key);
}
