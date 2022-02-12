void
nouveau_fence_context_del(struct nouveau_fence_chan *fctx)
{
struct nouveau_fence *fence, *fnext;
spin_lock(&fctx->lock);
list_for_each_entry_safe(fence, fnext, &fctx->pending, head) {
fence->channel = NULL;
list_del(&fence->head);
nouveau_fence_unref(&fence);
}
spin_unlock(&fctx->lock);
}
void
nouveau_fence_context_new(struct nouveau_fence_chan *fctx)
{
INIT_LIST_HEAD(&fctx->flip);
INIT_LIST_HEAD(&fctx->pending);
spin_lock_init(&fctx->lock);
}
static void
nouveau_fence_update(struct nouveau_channel *chan)
{
struct nouveau_fence_chan *fctx = chan->fence;
struct nouveau_fence *fence, *fnext;
spin_lock(&fctx->lock);
list_for_each_entry_safe(fence, fnext, &fctx->pending, head) {
if (fctx->read(chan) < fence->sequence)
break;
fence->channel = NULL;
list_del(&fence->head);
nouveau_fence_unref(&fence);
}
spin_unlock(&fctx->lock);
}
int
nouveau_fence_emit(struct nouveau_fence *fence, struct nouveau_channel *chan)
{
struct nouveau_fence_chan *fctx = chan->fence;
int ret;
fence->channel = chan;
fence->timeout = jiffies + (3 * DRM_HZ);
fence->sequence = ++fctx->sequence;
ret = fctx->emit(fence);
if (!ret) {
kref_get(&fence->kref);
spin_lock(&fctx->lock);
list_add_tail(&fence->head, &fctx->pending);
spin_unlock(&fctx->lock);
}
return ret;
}
bool
nouveau_fence_done(struct nouveau_fence *fence)
{
if (fence->channel)
nouveau_fence_update(fence->channel);
return !fence->channel;
}
static int
nouveau_fence_wait_uevent_handler(struct nouveau_eventh *event, int index)
{
struct nouveau_fence_uevent *uevent =
container_of(event, struct nouveau_fence_uevent, handler);
wake_up_all(&uevent->priv->waiting);
return NVKM_EVENT_KEEP;
}
static int
nouveau_fence_wait_uevent(struct nouveau_fence *fence, bool intr)
{
struct nouveau_channel *chan = fence->channel;
struct nouveau_fifo *pfifo = nouveau_fifo(chan->drm->device);
struct nouveau_fence_priv *priv = chan->drm->fence;
struct nouveau_fence_uevent uevent = {
.handler.func = nouveau_fence_wait_uevent_handler,
.priv = priv,
};
int ret = 0;
nouveau_event_get(pfifo->uevent, 0, &uevent.handler);
if (fence->timeout) {
unsigned long timeout = fence->timeout - jiffies;
if (time_before(jiffies, fence->timeout)) {
if (intr) {
ret = wait_event_interruptible_timeout(
priv->waiting,
nouveau_fence_done(fence),
timeout);
} else {
ret = wait_event_timeout(priv->waiting,
nouveau_fence_done(fence),
timeout);
}
}
if (ret >= 0) {
fence->timeout = jiffies + ret;
if (time_after_eq(jiffies, fence->timeout))
ret = -EBUSY;
}
} else {
if (intr) {
ret = wait_event_interruptible(priv->waiting,
nouveau_fence_done(fence));
} else {
wait_event(priv->waiting, nouveau_fence_done(fence));
}
}
nouveau_event_put(pfifo->uevent, 0, &uevent.handler);
if (unlikely(ret < 0))
return ret;
return 0;
}
int
nouveau_fence_wait(struct nouveau_fence *fence, bool lazy, bool intr)
{
struct nouveau_channel *chan = fence->channel;
struct nouveau_fence_priv *priv = chan ? chan->drm->fence : NULL;
unsigned long sleep_time = NSEC_PER_MSEC / 1000;
ktime_t t;
int ret = 0;
while (priv && priv->uevent && lazy && !nouveau_fence_done(fence)) {
ret = nouveau_fence_wait_uevent(fence, intr);
if (ret < 0)
return ret;
}
while (!nouveau_fence_done(fence)) {
if (fence->timeout && time_after_eq(jiffies, fence->timeout)) {
ret = -EBUSY;
break;
}
__set_current_state(intr ? TASK_INTERRUPTIBLE :
TASK_UNINTERRUPTIBLE);
if (lazy) {
t = ktime_set(0, sleep_time);
schedule_hrtimeout(&t, HRTIMER_MODE_REL);
sleep_time *= 2;
if (sleep_time > NSEC_PER_MSEC)
sleep_time = NSEC_PER_MSEC;
}
if (intr && signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
}
__set_current_state(TASK_RUNNING);
return ret;
}
int
nouveau_fence_sync(struct nouveau_fence *fence, struct nouveau_channel *chan)
{
struct nouveau_fence_chan *fctx = chan->fence;
struct nouveau_channel *prev;
int ret = 0;
prev = fence ? fence->channel : NULL;
if (prev) {
if (unlikely(prev != chan && !nouveau_fence_done(fence))) {
ret = fctx->sync(fence, prev, chan);
if (unlikely(ret))
ret = nouveau_fence_wait(fence, true, false);
}
}
return ret;
}
static void
nouveau_fence_del(struct kref *kref)
{
struct nouveau_fence *fence = container_of(kref, typeof(*fence), kref);
kfree(fence);
}
void
nouveau_fence_unref(struct nouveau_fence **pfence)
{
if (*pfence)
kref_put(&(*pfence)->kref, nouveau_fence_del);
*pfence = NULL;
}
struct nouveau_fence *
nouveau_fence_ref(struct nouveau_fence *fence)
{
kref_get(&fence->kref);
return fence;
}
int
nouveau_fence_new(struct nouveau_channel *chan, bool sysmem,
struct nouveau_fence **pfence)
{
struct nouveau_fence *fence;
int ret = 0;
if (unlikely(!chan->fence))
return -ENODEV;
fence = kzalloc(sizeof(*fence), GFP_KERNEL);
if (!fence)
return -ENOMEM;
fence->sysmem = sysmem;
kref_init(&fence->kref);
ret = nouveau_fence_emit(fence, chan);
if (ret)
nouveau_fence_unref(&fence);
*pfence = fence;
return ret;
}
