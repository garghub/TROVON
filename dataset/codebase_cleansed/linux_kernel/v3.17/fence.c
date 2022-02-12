unsigned fence_context_alloc(unsigned num)
{
BUG_ON(!num);
return atomic_add_return(num, &fence_context_counter) - num;
}
int fence_signal_locked(struct fence *fence)
{
struct fence_cb *cur, *tmp;
int ret = 0;
if (WARN_ON(!fence))
return -EINVAL;
if (!ktime_to_ns(fence->timestamp)) {
fence->timestamp = ktime_get();
smp_mb__before_atomic();
}
if (test_and_set_bit(FENCE_FLAG_SIGNALED_BIT, &fence->flags)) {
ret = -EINVAL;
} else
trace_fence_signaled(fence);
list_for_each_entry_safe(cur, tmp, &fence->cb_list, node) {
list_del_init(&cur->node);
cur->func(fence, cur);
}
return ret;
}
int fence_signal(struct fence *fence)
{
unsigned long flags;
if (!fence)
return -EINVAL;
if (!ktime_to_ns(fence->timestamp)) {
fence->timestamp = ktime_get();
smp_mb__before_atomic();
}
if (test_and_set_bit(FENCE_FLAG_SIGNALED_BIT, &fence->flags))
return -EINVAL;
trace_fence_signaled(fence);
if (test_bit(FENCE_FLAG_ENABLE_SIGNAL_BIT, &fence->flags)) {
struct fence_cb *cur, *tmp;
spin_lock_irqsave(fence->lock, flags);
list_for_each_entry_safe(cur, tmp, &fence->cb_list, node) {
list_del_init(&cur->node);
cur->func(fence, cur);
}
spin_unlock_irqrestore(fence->lock, flags);
}
return 0;
}
signed long
fence_wait_timeout(struct fence *fence, bool intr, signed long timeout)
{
signed long ret;
if (WARN_ON(timeout < 0))
return -EINVAL;
trace_fence_wait_start(fence);
ret = fence->ops->wait(fence, intr, timeout);
trace_fence_wait_end(fence);
return ret;
}
void fence_release(struct kref *kref)
{
struct fence *fence =
container_of(kref, struct fence, refcount);
trace_fence_destroy(fence);
BUG_ON(!list_empty(&fence->cb_list));
if (fence->ops->release)
fence->ops->release(fence);
else
fence_free(fence);
}
void fence_free(struct fence *fence)
{
kfree_rcu(fence, rcu);
}
void fence_enable_sw_signaling(struct fence *fence)
{
unsigned long flags;
if (!test_and_set_bit(FENCE_FLAG_ENABLE_SIGNAL_BIT, &fence->flags) &&
!test_bit(FENCE_FLAG_SIGNALED_BIT, &fence->flags)) {
trace_fence_enable_signal(fence);
spin_lock_irqsave(fence->lock, flags);
if (!fence->ops->enable_signaling(fence))
fence_signal_locked(fence);
spin_unlock_irqrestore(fence->lock, flags);
}
}
int fence_add_callback(struct fence *fence, struct fence_cb *cb,
fence_func_t func)
{
unsigned long flags;
int ret = 0;
bool was_set;
if (WARN_ON(!fence || !func))
return -EINVAL;
if (test_bit(FENCE_FLAG_SIGNALED_BIT, &fence->flags)) {
INIT_LIST_HEAD(&cb->node);
return -ENOENT;
}
spin_lock_irqsave(fence->lock, flags);
was_set = test_and_set_bit(FENCE_FLAG_ENABLE_SIGNAL_BIT, &fence->flags);
if (test_bit(FENCE_FLAG_SIGNALED_BIT, &fence->flags))
ret = -ENOENT;
else if (!was_set) {
trace_fence_enable_signal(fence);
if (!fence->ops->enable_signaling(fence)) {
fence_signal_locked(fence);
ret = -ENOENT;
}
}
if (!ret) {
cb->func = func;
list_add_tail(&cb->node, &fence->cb_list);
} else
INIT_LIST_HEAD(&cb->node);
spin_unlock_irqrestore(fence->lock, flags);
return ret;
}
bool
fence_remove_callback(struct fence *fence, struct fence_cb *cb)
{
unsigned long flags;
bool ret;
spin_lock_irqsave(fence->lock, flags);
ret = !list_empty(&cb->node);
if (ret)
list_del_init(&cb->node);
spin_unlock_irqrestore(fence->lock, flags);
return ret;
}
static void
fence_default_wait_cb(struct fence *fence, struct fence_cb *cb)
{
struct default_wait_cb *wait =
container_of(cb, struct default_wait_cb, base);
wake_up_state(wait->task, TASK_NORMAL);
}
signed long
fence_default_wait(struct fence *fence, bool intr, signed long timeout)
{
struct default_wait_cb cb;
unsigned long flags;
signed long ret = timeout;
bool was_set;
if (test_bit(FENCE_FLAG_SIGNALED_BIT, &fence->flags))
return timeout;
spin_lock_irqsave(fence->lock, flags);
if (intr && signal_pending(current)) {
ret = -ERESTARTSYS;
goto out;
}
was_set = test_and_set_bit(FENCE_FLAG_ENABLE_SIGNAL_BIT, &fence->flags);
if (test_bit(FENCE_FLAG_SIGNALED_BIT, &fence->flags))
goto out;
if (!was_set) {
trace_fence_enable_signal(fence);
if (!fence->ops->enable_signaling(fence)) {
fence_signal_locked(fence);
goto out;
}
}
cb.base.func = fence_default_wait_cb;
cb.task = current;
list_add(&cb.base.node, &fence->cb_list);
while (!test_bit(FENCE_FLAG_SIGNALED_BIT, &fence->flags) && ret > 0) {
if (intr)
__set_current_state(TASK_INTERRUPTIBLE);
else
__set_current_state(TASK_UNINTERRUPTIBLE);
spin_unlock_irqrestore(fence->lock, flags);
ret = schedule_timeout(ret);
spin_lock_irqsave(fence->lock, flags);
if (ret > 0 && intr && signal_pending(current))
ret = -ERESTARTSYS;
}
if (!list_empty(&cb.base.node))
list_del(&cb.base.node);
__set_current_state(TASK_RUNNING);
out:
spin_unlock_irqrestore(fence->lock, flags);
return ret;
}
void
fence_init(struct fence *fence, const struct fence_ops *ops,
spinlock_t *lock, unsigned context, unsigned seqno)
{
BUG_ON(!lock);
BUG_ON(!ops || !ops->wait || !ops->enable_signaling ||
!ops->get_driver_name || !ops->get_timeline_name);
kref_init(&fence->refcount);
fence->ops = ops;
INIT_LIST_HEAD(&fence->cb_list);
fence->lock = lock;
fence->context = context;
fence->seqno = seqno;
fence->flags = 0UL;
trace_fence_init(fence);
}
