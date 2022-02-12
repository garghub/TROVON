void vmw_fence_queue_init(struct vmw_fence_queue *queue)
{
INIT_LIST_HEAD(&queue->head);
queue->lag = ns_to_timespec(0);
getrawmonotonic(&queue->lag_time);
spin_lock_init(&queue->lock);
}
void vmw_fence_queue_takedown(struct vmw_fence_queue *queue)
{
struct vmw_fence *fence, *next;
spin_lock(&queue->lock);
list_for_each_entry_safe(fence, next, &queue->head, head) {
kfree(fence);
}
spin_unlock(&queue->lock);
}
int vmw_fence_push(struct vmw_fence_queue *queue,
uint32_t sequence)
{
struct vmw_fence *fence = kmalloc(sizeof(*fence), GFP_KERNEL);
if (unlikely(!fence))
return -ENOMEM;
fence->sequence = sequence;
getrawmonotonic(&fence->submitted);
spin_lock(&queue->lock);
list_add_tail(&fence->head, &queue->head);
spin_unlock(&queue->lock);
return 0;
}
int vmw_fence_pull(struct vmw_fence_queue *queue,
uint32_t signaled_sequence)
{
struct vmw_fence *fence, *next;
struct timespec now;
bool updated = false;
spin_lock(&queue->lock);
getrawmonotonic(&now);
if (list_empty(&queue->head)) {
queue->lag = ns_to_timespec(0);
queue->lag_time = now;
updated = true;
goto out_unlock;
}
list_for_each_entry_safe(fence, next, &queue->head, head) {
if (signaled_sequence - fence->sequence > (1 << 30))
continue;
queue->lag = timespec_sub(now, fence->submitted);
queue->lag_time = now;
updated = true;
list_del(&fence->head);
kfree(fence);
}
out_unlock:
spin_unlock(&queue->lock);
return (updated) ? 0 : -EBUSY;
}
static struct timespec vmw_timespec_add(struct timespec t1,
struct timespec t2)
{
t1.tv_sec += t2.tv_sec;
t1.tv_nsec += t2.tv_nsec;
if (t1.tv_nsec >= 1000000000L) {
t1.tv_sec += 1;
t1.tv_nsec -= 1000000000L;
}
return t1;
}
static struct timespec vmw_fifo_lag(struct vmw_fence_queue *queue)
{
struct timespec now;
spin_lock(&queue->lock);
getrawmonotonic(&now);
queue->lag = vmw_timespec_add(queue->lag,
timespec_sub(now, queue->lag_time));
queue->lag_time = now;
spin_unlock(&queue->lock);
return queue->lag;
}
static bool vmw_lag_lt(struct vmw_fence_queue *queue,
uint32_t us)
{
struct timespec lag, cond;
cond = ns_to_timespec((s64) us * 1000);
lag = vmw_fifo_lag(queue);
return (timespec_compare(&lag, &cond) < 1);
}
int vmw_wait_lag(struct vmw_private *dev_priv,
struct vmw_fence_queue *queue, uint32_t us)
{
struct vmw_fence *fence;
uint32_t sequence;
int ret;
while (!vmw_lag_lt(queue, us)) {
spin_lock(&queue->lock);
if (list_empty(&queue->head))
sequence = atomic_read(&dev_priv->fence_seq);
else {
fence = list_first_entry(&queue->head,
struct vmw_fence, head);
sequence = fence->sequence;
}
spin_unlock(&queue->lock);
ret = vmw_wait_fence(dev_priv, false, sequence, true,
3*HZ);
if (unlikely(ret != 0))
return ret;
(void) vmw_fence_pull(queue, sequence);
}
return 0;
}
