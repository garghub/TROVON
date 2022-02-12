static const char *seqno_fence_get_driver_name(struct fence *fence)
{
struct seqno_fence *seqno_fence = to_seqno_fence(fence);
return seqno_fence->ops->get_driver_name(fence);
}
static const char *seqno_fence_get_timeline_name(struct fence *fence)
{
struct seqno_fence *seqno_fence = to_seqno_fence(fence);
return seqno_fence->ops->get_timeline_name(fence);
}
static bool seqno_enable_signaling(struct fence *fence)
{
struct seqno_fence *seqno_fence = to_seqno_fence(fence);
return seqno_fence->ops->enable_signaling(fence);
}
static bool seqno_signaled(struct fence *fence)
{
struct seqno_fence *seqno_fence = to_seqno_fence(fence);
return seqno_fence->ops->signaled && seqno_fence->ops->signaled(fence);
}
static void seqno_release(struct fence *fence)
{
struct seqno_fence *f = to_seqno_fence(fence);
dma_buf_put(f->sync_buf);
if (f->ops->release)
f->ops->release(fence);
else
fence_free(&f->base);
}
static signed long seqno_wait(struct fence *fence, bool intr, signed long timeout)
{
struct seqno_fence *f = to_seqno_fence(fence);
return f->ops->wait(fence, intr, timeout);
}
