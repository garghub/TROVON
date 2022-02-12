u64 dma_fence_context_alloc(unsigned num)
{
BUG_ON(!num);
return atomic64_add_return(num, &dma_fence_context_counter) - num;
}
int dma_fence_signal_locked(struct dma_fence *fence)
{
struct dma_fence_cb *cur, *tmp;
int ret = 0;
lockdep_assert_held(fence->lock);
if (WARN_ON(!fence))
return -EINVAL;
if (!ktime_to_ns(fence->timestamp)) {
fence->timestamp = ktime_get();
smp_mb__before_atomic();
}
if (test_and_set_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags)) {
ret = -EINVAL;
} else
trace_dma_fence_signaled(fence);
list_for_each_entry_safe(cur, tmp, &fence->cb_list, node) {
list_del_init(&cur->node);
cur->func(fence, cur);
}
return ret;
}
int dma_fence_signal(struct dma_fence *fence)
{
unsigned long flags;
if (!fence)
return -EINVAL;
if (!ktime_to_ns(fence->timestamp)) {
fence->timestamp = ktime_get();
smp_mb__before_atomic();
}
if (test_and_set_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags))
return -EINVAL;
trace_dma_fence_signaled(fence);
if (test_bit(DMA_FENCE_FLAG_ENABLE_SIGNAL_BIT, &fence->flags)) {
struct dma_fence_cb *cur, *tmp;
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
dma_fence_wait_timeout(struct dma_fence *fence, bool intr, signed long timeout)
{
signed long ret;
if (WARN_ON(timeout < 0))
return -EINVAL;
trace_dma_fence_wait_start(fence);
ret = fence->ops->wait(fence, intr, timeout);
trace_dma_fence_wait_end(fence);
return ret;
}
void dma_fence_release(struct kref *kref)
{
struct dma_fence *fence =
container_of(kref, struct dma_fence, refcount);
trace_dma_fence_destroy(fence);
BUG_ON(!list_empty(&fence->cb_list));
if (fence->ops->release)
fence->ops->release(fence);
else
dma_fence_free(fence);
}
void dma_fence_free(struct dma_fence *fence)
{
kfree_rcu(fence, rcu);
}
void dma_fence_enable_sw_signaling(struct dma_fence *fence)
{
unsigned long flags;
if (!test_and_set_bit(DMA_FENCE_FLAG_ENABLE_SIGNAL_BIT,
&fence->flags) &&
!test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags)) {
trace_dma_fence_enable_signal(fence);
spin_lock_irqsave(fence->lock, flags);
if (!fence->ops->enable_signaling(fence))
dma_fence_signal_locked(fence);
spin_unlock_irqrestore(fence->lock, flags);
}
}
int dma_fence_add_callback(struct dma_fence *fence, struct dma_fence_cb *cb,
dma_fence_func_t func)
{
unsigned long flags;
int ret = 0;
bool was_set;
if (WARN_ON(!fence || !func))
return -EINVAL;
if (test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags)) {
INIT_LIST_HEAD(&cb->node);
return -ENOENT;
}
spin_lock_irqsave(fence->lock, flags);
was_set = test_and_set_bit(DMA_FENCE_FLAG_ENABLE_SIGNAL_BIT,
&fence->flags);
if (test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags))
ret = -ENOENT;
else if (!was_set) {
trace_dma_fence_enable_signal(fence);
if (!fence->ops->enable_signaling(fence)) {
dma_fence_signal_locked(fence);
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
dma_fence_remove_callback(struct dma_fence *fence, struct dma_fence_cb *cb)
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
dma_fence_default_wait_cb(struct dma_fence *fence, struct dma_fence_cb *cb)
{
struct default_wait_cb *wait =
container_of(cb, struct default_wait_cb, base);
wake_up_state(wait->task, TASK_NORMAL);
}
signed long
dma_fence_default_wait(struct dma_fence *fence, bool intr, signed long timeout)
{
struct default_wait_cb cb;
unsigned long flags;
signed long ret = timeout ? timeout : 1;
bool was_set;
if (test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags))
return ret;
spin_lock_irqsave(fence->lock, flags);
if (intr && signal_pending(current)) {
ret = -ERESTARTSYS;
goto out;
}
was_set = test_and_set_bit(DMA_FENCE_FLAG_ENABLE_SIGNAL_BIT,
&fence->flags);
if (test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags))
goto out;
if (!was_set) {
trace_dma_fence_enable_signal(fence);
if (!fence->ops->enable_signaling(fence)) {
dma_fence_signal_locked(fence);
goto out;
}
}
cb.base.func = dma_fence_default_wait_cb;
cb.task = current;
list_add(&cb.base.node, &fence->cb_list);
while (!test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags) && ret > 0) {
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
static bool
dma_fence_test_signaled_any(struct dma_fence **fences, uint32_t count,
uint32_t *idx)
{
int i;
for (i = 0; i < count; ++i) {
struct dma_fence *fence = fences[i];
if (test_bit(DMA_FENCE_FLAG_SIGNALED_BIT, &fence->flags)) {
if (idx)
*idx = i;
return true;
}
}
return false;
}
signed long
dma_fence_wait_any_timeout(struct dma_fence **fences, uint32_t count,
bool intr, signed long timeout, uint32_t *idx)
{
struct default_wait_cb *cb;
signed long ret = timeout;
unsigned i;
if (WARN_ON(!fences || !count || timeout < 0))
return -EINVAL;
if (timeout == 0) {
for (i = 0; i < count; ++i)
if (dma_fence_is_signaled(fences[i])) {
if (idx)
*idx = i;
return 1;
}
return 0;
}
cb = kcalloc(count, sizeof(struct default_wait_cb), GFP_KERNEL);
if (cb == NULL) {
ret = -ENOMEM;
goto err_free_cb;
}
for (i = 0; i < count; ++i) {
struct dma_fence *fence = fences[i];
if (fence->ops->wait != dma_fence_default_wait) {
ret = -EINVAL;
goto fence_rm_cb;
}
cb[i].task = current;
if (dma_fence_add_callback(fence, &cb[i].base,
dma_fence_default_wait_cb)) {
if (idx)
*idx = i;
goto fence_rm_cb;
}
}
while (ret > 0) {
if (intr)
set_current_state(TASK_INTERRUPTIBLE);
else
set_current_state(TASK_UNINTERRUPTIBLE);
if (dma_fence_test_signaled_any(fences, count, idx))
break;
ret = schedule_timeout(ret);
if (ret > 0 && intr && signal_pending(current))
ret = -ERESTARTSYS;
}
__set_current_state(TASK_RUNNING);
fence_rm_cb:
while (i-- > 0)
dma_fence_remove_callback(fences[i], &cb[i].base);
err_free_cb:
kfree(cb);
return ret;
}
void
dma_fence_init(struct dma_fence *fence, const struct dma_fence_ops *ops,
spinlock_t *lock, u64 context, unsigned seqno)
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
trace_dma_fence_init(fence);
}
